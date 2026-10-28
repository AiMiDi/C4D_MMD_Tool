#ifndef CMT_PHYSICS_ASYNC_H
#define CMT_PHYSICS_ASYNC_H

//! P2：常驻 worker 线程 + 结果槽。
//!
//! 线程模型（单模型、单 worker；t29 修复 P2-001 后的形态）：
//!   主线程 pre-physics：把「纯数据载荷」打包（骨骼世界矩阵 + frame/epoch），Submit；
//!   worker：先把载荷应用进影子节点，再 step(dt)、再快照刚体/骨骼世界矩阵，发布结果；
//!   主线程之后：TryConsume(epoch, expected_frame) → 写回 C4D（骨骼 + 刚体显示）。
//!
//! 不变量（与 t29 验收对应）：
//!   1. 影子节点树只被 worker 线程读写；主线程与 worker 之间只传 POD 载荷与快照，
//!      不存在「主线程写节点、worker 读节点」的共享可写状态；
//!   2. Submit 有背压：上一帧 job 还在跑时不会静默覆盖，而是有界等待后拒绝本帧并计数
//!      （submit_skipped），主线程继续用上一份结果；
//!   3. 结果槽的 frame/epoch 必须与消费方期望一致，跨 epoch 一律丢弃；
//!   4. 结果永远按 frame 单调；被新结果覆盖的旧结果计入 result_covered，不静默丢失；
//!   5. CancelAndJoin 之后不会再有生产（在途任务被丢弃并计数）。

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

#include <Eigen/Geometry>

namespace cmt
{
	namespace physics
	{
		//! 主线程提交给 worker 的纯数据载荷：不含任何可写节点/世界句柄。
		struct AsyncJobPayload
		{
			std::uint64_t frame = 0;
			std::uint64_t epoch = 0;
			//! 提交时刻的骨骼世界矩阵（worker 会把它应用进影子节点）。
			std::vector<Eigen::Matrix4f> bone_world;
			//! P2-004：影子刚体的稳定身份（PMX 刚体下标，按影子世界顺序）；
			//! 消费侧必须按身份映射回主世界，不允许裸下标错写。
			std::vector<std::int32_t> rigid_identity;
		};

		struct AsyncFrameResult
		{
			std::uint64_t frame = 0;
			std::uint64_t epoch = 0;
			//! 物理推进之后的骨骼世界矩阵（结果槽 payload 之一）。
			std::vector<Eigen::Matrix4f> bone_world;
			//! 物理推进之后的刚体世界矩阵（结果槽 payload 之二，消费协议见 runtime）。
			std::vector<Eigen::Matrix4f> rigid_world;
			//! 与 rigid_world 同序的稳定身份（来自提交载荷，逐帧随结果一起返回）。
			std::vector<std::int32_t> rigid_identity;
		};

		// P2-004：按稳定身份（PMX 刚体下标）把结果快照映射到主世界索引。
// - result_identity / main_identity 必须等长且都等于主世界刚体数，否则返回 false（fail-closed）；
// - 任何一侧出现重复身份或找不到身份也返回 false；
// - 成功时 out_main_index[i] 给出快照第 i 条应当写入的主世界刚体下标。
bool MapRigidSnapshotToMain(const std::vector<std::int32_t>& result_identity,
	const std::vector<std::int32_t>& main_identity, std::size_t main_body_count,
	std::vector<std::size_t>& out_main_index);

//! t35：物理步的分发判定。默认管道模式（seam 开）+ async 开 ⇒ seam_async，
//! 保证 CMT_PHYSICS_ASYNC=1 在默认配置下真正接管物理步（此前 async 只挂在
//! StepStandalonePhysics()，而它仅在 seam 关闭时调用，默认配置下是死代码）。
enum class PhysicsDispatch
{
	raw, //!< 缝关闭：旧路径（同步直算 + 立即回写）
	seam_sync, //!< 缝开启、async 关闭：Produce/Consume 同步推进
	seam_async //!< 缝开启、async 开启：提交 worker，消费上一帧结果
};

PhysicsDispatch SelectPhysicsDispatch(bool seam_enabled, bool async_enabled);

class PhysicsAsyncPipeline
		{
		public:
			//! worker 线程上的一步物理（含 substeps）。必须先应用 payload，再推进，再回读。
			//! 只允许操作影子世界，不得触碰任何 C4D 对象。
			using StepFn = std::function<void(float, const AsyncJobPayload&)>;
			//! worker 线程上、物理推进之后把「骨骼世界矩阵 + 刚体世界矩阵」一起拷进结果槽。
			using SnapshotFn = std::function<void(std::vector<Eigen::Matrix4f>& bone_world, std::vector<Eigen::Matrix4f>& rigid_world)>;

			struct Counters
			{
				std::uint64_t submitted = 0;
				std::uint64_t produced = 0;
				std::uint64_t consumed = 0;
				std::uint64_t cancelled = 0;
				std::uint64_t stale_dropped = 0;
				std::uint64_t in_flight_dropped = 0;
				std::uint64_t worker_steps = 0;
				std::uint64_t main_thread_steps = 0;
				//! t29：背压与结果槽覆盖的显式计数。
				std::uint64_t submit_skipped = 0;
				std::uint64_t submit_waited = 0;
				std::uint64_t result_covered = 0;
				//! P2-003：结果已就绪但未被消费时拒绝新提交的次数（严格一帧延迟的代价）。
				std::uint64_t submit_blocked_result_pending = 0;
				//! P3：被跳过的物理步数。默认阻塞提交下必须恒为 0（丢步会破坏 async(N)=sync(N-1)）。
				std::uint64_t steps_skipped = 0;
			};

			PhysicsAsyncPipeline();
			~PhysicsAsyncPipeline();

			PhysicsAsyncPipeline(const PhysicsAsyncPipeline&) = delete;
			PhysicsAsyncPipeline& operator=(const PhysicsAsyncPipeline&) = delete;

			void Configure(StepFn step, SnapshotFn snapshot);

			//! 起常驻线程。重复调用是幂等的。
			bool Start(float fixed_dt);
			bool Running() const { return running_.load(std::memory_order_acquire); }

			//! 主线程提交一帧任务（纯数据载荷）。
			//! 两道门（P2-003 严格一帧延迟）：
			//!   1. 上一帧 job 仍在 worker 手上 → 有界等待后拒绝（submit_skipped）；
			//!   2. 结果槽仍有未消费结果 → 立即拒绝（submit_blocked_result_pending）。
			//! 因此「已接受帧的结果必被按序消费」，result_covered 在契约下恒为 0。
			bool Submit(std::uint64_t frame, std::uint64_t epoch, std::vector<Eigen::Matrix4f> bone_world,
				std::vector<std::int32_t> rigid_identity);

			//! 主线程消费：epoch 必须匹配；expected_frame 非 0 时还必须与结果帧号相等
			//! （Flush 用具体帧号，防止「更大帧号」被误当成当前帧）。
			bool TryConsume(std::uint64_t epoch, std::uint64_t expected_frame, AsyncFrameResult& out);

			//! seek / 停止 / 关闭开关 / 模型销毁：取消在途任务并 join 线程。
			void CancelAndJoin();

			void Shutdown() { CancelAndJoin(); }

			Counters GetCounters() const;

			//! 有界等待当前在途 job 结束（夹具与 Flush 用）。
			bool WaitIdle(std::uint64_t timeout_ms);

			//! 仅在夹具里用来断言「主线程从未执行过 step」。
			void NoteMainThreadStep() { ++main_thread_steps_; }

			void SetMaxSubmitWaitMs(std::uint64_t value) { max_submit_wait_ms_ = value; }

			//! P9-001：阻塞提交的等待上限。worker 卡死时主线程必须能返回（不能永久挂死），
			//! 超预算按「本帧跳过」计数，由 runtime 的滞后安全网决定是否回退同步。
			void SetBlockWaitBudgetMs(std::uint64_t value) { block_wait_budget_ms_ = value; }

			//! P9-001：worker 侧曾抛异常（step/snapshot 失败）。置位后不再生产，主线程据此回退同步。
			bool Fatal();

			//! P3：默认阻塞提交——上一帧还没跑完就等，绝不跳帧（t36 结论：丢步是分岔源之一）。
			void SetBlockingSubmit(bool value) { block_on_in_flight_ = value; }

			//! P3：worker 侧的固定步长（必须与同步路径的 1/fps 一致）。
			float FixedDt() const { return fixed_dt_; }

		private:
			void WorkerLoop();

			StepFn step_;
			SnapshotFn snapshot_;
			float fixed_dt_ = 1.F / 30.F;
			std::uint64_t max_submit_wait_ms_ = 0;
			//! P9-001：提交侧等待在途 job 的总预算（毫秒）。默认 500ms ≈ 25 帧 @30fps。
			std::uint64_t block_wait_budget_ms_ = 500;
			bool block_on_in_flight_ = true;

			mutable std::mutex mutex_;
			std::condition_variable wake_;
			std::condition_variable idle_;

			bool has_job_ = false;
			//! 已提交但尚未产出结果的 job（背压判定用；与 has_job_ 的区别是 worker 已在执行）。
			bool in_flight_ = false;
			AsyncJobPayload job_;

			bool has_result_ = false;
			AsyncFrameResult result_;
			//! P9-001：worker 抛过异常（只在 mutex_ 下读写）。置位后 Submit/Start 拒绝，
			//! runtime 检测到后关闭本代异步世界并回退同步步进。
			bool fatal_ = false;

			std::atomic<bool> running_{ false };
			std::atomic<bool> cancel_{ false };
			std::thread worker_;

			mutable std::atomic<std::uint64_t> submitted_{ 0 };
			mutable std::atomic<std::uint64_t> produced_{ 0 };
			mutable std::atomic<std::uint64_t> consumed_{ 0 };
			mutable std::atomic<std::uint64_t> cancelled_{ 0 };
			mutable std::atomic<std::uint64_t> stale_dropped_{ 0 };
			mutable std::atomic<std::uint64_t> in_flight_dropped_{ 0 };
			mutable std::atomic<std::uint64_t> worker_steps_{ 0 };
			mutable std::atomic<std::uint64_t> main_thread_steps_{ 0 };
			mutable std::atomic<std::uint64_t> submit_skipped_{ 0 };
			mutable std::atomic<std::uint64_t> submit_waited_{ 0 };
			mutable std::atomic<std::uint64_t> result_covered_{ 0 };
			mutable std::atomic<std::uint64_t> submit_blocked_result_pending_{ 0 };
			mutable std::atomic<std::uint64_t> steps_skipped_{ 0 };
		};
	}
}

#endif // CMT_PHYSICS_ASYNC_H
