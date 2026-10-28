#include "cmt_physics_async.h"

#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace cmt
{
	namespace physics
	{
		PhysicsAsyncPipeline::PhysicsAsyncPipeline() = default;

		PhysicsAsyncPipeline::~PhysicsAsyncPipeline()
		{
			CancelAndJoin();
		}

		PhysicsDispatch SelectPhysicsDispatch(const bool seam_enabled, const bool async_enabled)
{
	// 缝关闭时 async 没有结果槽可挂，只能走旧路径；这也是「强制关缝」时的既有语义。
	if (!seam_enabled)
		return PhysicsDispatch::raw;
	return async_enabled ? PhysicsDispatch::seam_async : PhysicsDispatch::seam_sync;
}

bool MapRigidSnapshotToMain(const std::vector<std::int32_t>& result_identity,
	const std::vector<std::int32_t>& main_identity, const std::size_t main_body_count,
	std::vector<std::size_t>& out_main_index)
{
	out_main_index.clear();
	if (result_identity.size() != main_identity.size() || result_identity.size() != main_body_count)
		return false;

	// t56：身份是 PMX 刚体下标；负数/非法值一律 fail-closed，避免只靠「恰好唯一」蒙混过关。
	for (const std::int32_t identity : result_identity)
	{
		if (identity < 0)
			return false;
	}
	for (const std::int32_t identity : main_identity)
	{
		if (identity < 0)
			return false;
	}
	std::unordered_map<std::int32_t, std::size_t> main_index_by_identity;
	main_index_by_identity.reserve(main_identity.size());
	for (std::size_t index = 0; index < main_identity.size(); ++index)
	{
		// 重复身份意味着「按下标」与「按身份」不再等价，直接拒绝。
		if (!main_index_by_identity.emplace(main_identity[index], index).second)
			return false;
	}
	std::unordered_set<std::int32_t> seen_result;
	seen_result.reserve(result_identity.size());
	out_main_index.reserve(result_identity.size());
	for (const std::int32_t identity : result_identity)
	{
		if (!seen_result.insert(identity).second)
		{
			out_main_index.clear();
			return false;
		}
		const auto found = main_index_by_identity.find(identity);
		if (found == main_index_by_identity.end())
		{
			out_main_index.clear();
			return false;
		}
		out_main_index.push_back(found->second);
	}
	return true;
}

void PhysicsAsyncPipeline::Configure(StepFn step, SnapshotFn snapshot)
		{
			step_ = std::move(step);
			snapshot_ = std::move(snapshot);
		}

		bool PhysicsAsyncPipeline::Start(const float fixed_dt)
		{
			if (running_.load(std::memory_order_acquire))
				return true;
			if (!step_)
				return false;

			if (worker_.joinable())
			{
				// 上一轮已取消但还没回收：先 join，避免 std::terminate。
				worker_.join();
			}

			fixed_dt_ = fixed_dt > 0.F ? fixed_dt : (1.F / 30.F);
			{
				// P9-001：新一代线程从干净的槽状态起步（上一代可能是在 fatal/超预算下收的尾）。
				std::lock_guard<std::mutex> lock(mutex_);
				fatal_ = false;
				has_job_ = false;
				in_flight_ = false;
				has_result_ = false;
				job_ = AsyncJobPayload{};
			}
			cancel_.store(false, std::memory_order_release);
			running_.store(true, std::memory_order_release);
			worker_ = std::thread(&PhysicsAsyncPipeline::WorkerLoop, this);
			return true;
		}

		bool PhysicsAsyncPipeline::Fatal()
		{
			std::lock_guard<std::mutex> lock(mutex_);
			return fatal_;
		}

		bool PhysicsAsyncPipeline::Submit(
			const std::uint64_t frame,
			const std::uint64_t epoch,
			std::vector<Eigen::Matrix4f> bone_world,
			std::vector<std::int32_t> rigid_identity)
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if (!running_.load(std::memory_order_acquire) || fatal_)
				return false;

			// P2-003：槽里还有未消费结果时直接拒绝本帧——只有主线程能消费，等待无意义；
			// 这样「已接受帧」与「已消费帧」一一对应，结果槽永不覆盖，帧号连续。
			if (has_result_)
			{
				++submit_blocked_result_pending_;
				return false;
			}

			// 背压：在途 job 未完成时不覆盖（P2-001）。
			// P3：默认一直等到空位——丢步会让 async 链与 sync 链错位，t36 实测每 7 帧丢一步即单调分岔。
			// P9-001：但等待必须有上限。worker 里 Bullet/分配器一旦卡住，主线程（在 C4D 的 Execute 里）
			// 不能跟着永久挂死；超预算按跳过计数，交由 runtime 的滞后安全网回退同步。
			if (has_job_ || in_flight_)
			{
				const std::uint64_t wait_ms = block_on_in_flight_
					? (block_wait_budget_ms_ > 0 ? block_wait_budget_ms_ : 1)
					: max_submit_wait_ms_;
				const bool finished = idle_.wait_for(
					lock,
					std::chrono::milliseconds(wait_ms),
					[this]() {
						return (!has_job_ && !in_flight_) || fatal_ ||
						       cancel_.load(std::memory_order_acquire) ||
						       !running_.load(std::memory_order_acquire);
					});
				if (!finished || has_job_ || in_flight_)
				{
					++submit_skipped_;
					++steps_skipped_;
					return false;
				}
				// P9-001：等待期间 worker 可能已把结果投进槽；此时再提交会让结果被下一轮覆盖。
				// 严格一帧延迟的契约要求「先消费再提交」，这里直接拒绝本帧。
				if (has_result_)
				{
					++submit_blocked_result_pending_;
					return false;
				}
				++submit_waited_;
			}

			job_.frame = frame;
			job_.epoch = epoch;
			job_.bone_world = std::move(bone_world);
			job_.rigid_identity = std::move(rigid_identity);
			has_job_ = true;
			in_flight_ = true;
			++submitted_;
			wake_.notify_one();
			return true;
		}

		bool PhysicsAsyncPipeline::TryConsume(
			const std::uint64_t epoch,
			const std::uint64_t expected_frame,
			AsyncFrameResult& out)
		{
			std::lock_guard<std::mutex> lock(mutex_);
			if (!has_result_)
				return false;
			if (result_.epoch != epoch)
			{
				// 跨 epoch 的结果一律作废：seek 之后的旧帧不能落回场景。
				has_result_ = false;
				++stale_dropped_;
				return false;
			}
			if (expected_frame != 0 && result_.frame != expected_frame)
			{
				// 帧号对不上（例如 Flush 要 frame=7，槽里是 9）：拒绝落回，保留「未就绪」。
				has_result_ = false;
				++stale_dropped_;
				return false;
			}

			out = std::move(result_);
			has_result_ = false;
			++consumed_;
			return true;
		}

		bool PhysicsAsyncPipeline::WaitIdle(const std::uint64_t timeout_ms)
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if (!has_job_ && !in_flight_)
				return true;
			return idle_.wait_for(
				lock,
				std::chrono::milliseconds(timeout_ms),
				[this]() { return !has_job_ && !in_flight_; });
		}

		void PhysicsAsyncPipeline::CancelAndJoin()
		{
			{
				std::lock_guard<std::mutex> lock(mutex_);
				if (has_job_ || in_flight_)
				{
					has_job_ = false;
					++in_flight_dropped_;
				}
				has_result_ = false;
				++cancelled_;
				cancel_.store(true, std::memory_order_release);
				running_.store(false, std::memory_order_release);
			}
			wake_.notify_all();
			idle_.notify_all();

			if (worker_.joinable())
				worker_.join();

			std::lock_guard<std::mutex> lock(mutex_);
			has_job_ = false;
			in_flight_ = false;
			has_result_ = false;
		}

		PhysicsAsyncPipeline::Counters PhysicsAsyncPipeline::GetCounters() const
		{
			Counters counters;
			counters.submitted = submitted_.load(std::memory_order_acquire);
			counters.produced = produced_.load(std::memory_order_acquire);
			counters.consumed = consumed_.load(std::memory_order_acquire);
			counters.cancelled = cancelled_.load(std::memory_order_acquire);
			counters.stale_dropped = stale_dropped_.load(std::memory_order_acquire);
			counters.in_flight_dropped = in_flight_dropped_.load(std::memory_order_acquire);
			counters.worker_steps = worker_steps_.load(std::memory_order_acquire);
			counters.main_thread_steps = main_thread_steps_.load(std::memory_order_acquire);
			counters.submit_skipped = submit_skipped_.load(std::memory_order_acquire);
			counters.submit_waited = submit_waited_.load(std::memory_order_acquire);
			counters.result_covered = result_covered_.load(std::memory_order_acquire);
			counters.submit_blocked_result_pending = submit_blocked_result_pending_.load(std::memory_order_acquire);
			counters.steps_skipped = steps_skipped_.load(std::memory_order_acquire);
			return counters;
		}

		void PhysicsAsyncPipeline::WorkerLoop()
		{
			for (;;)
			{
				AsyncJobPayload job;

				{
					std::unique_lock<std::mutex> lock(mutex_);
					wake_.wait(lock, [this]() {
						return has_job_ || cancel_.load(std::memory_order_acquire) ||
						       !running_.load(std::memory_order_acquire);
					});

					if (cancel_.load(std::memory_order_acquire) ||
					    !running_.load(std::memory_order_acquire))
					{
						if (has_job_ || in_flight_)
						{
							has_job_ = false;
							++in_flight_dropped_;
						}
						return;
					}

					job = std::move(job_);
					job_ = AsyncJobPayload{};
					has_job_ = false;
				}

				// 影子世界推进：载荷由主线程以纯数据形式提交，节点树只在本线程被写。
				// P9-001：worker 里的异常不能逃出线程（那会 std::terminate 直接杀掉宿主）。
				// 捕获后置 fatal_，主线程在下一帧看到 Fatal() 就关掉本代异步世界、回退同步。
				AsyncFrameResult produced;
				try
				{
					step_(fixed_dt_, job);
					++worker_steps_;

					produced.frame = job.frame;
					produced.epoch = job.epoch;
					produced.rigid_identity = job.rigid_identity;
					// payload 只来自推进后的快照；提交时带进来的矩阵不进入结果槽。
					if (snapshot_)
						snapshot_(produced.bone_world, produced.rigid_world);
				}
				catch (...)
				{
					std::lock_guard<std::mutex> lock(mutex_);
					fatal_ = true;
					has_job_ = false;
					in_flight_ = false;
					idle_.notify_all();
					return;
				}

				{
					std::lock_guard<std::mutex> lock(mutex_);
					if (cancel_.load(std::memory_order_acquire))
					{
						++in_flight_dropped_;
						in_flight_ = false;
						idle_.notify_all();
						return;
					}
					if (has_result_)
					{
						// 主线程还没取走上一帧：新结果覆盖旧结果，但必须计数（不静默丢失）。
						++result_covered_;
					}
					result_ = std::move(produced);
					has_result_ = true;
					++produced_;
					in_flight_ = false;
				}
				idle_.notify_all();
			}
		}
	}
}
