#ifndef CMT_PHYSICS_PIPELINE_H
#define CMT_PHYSICS_PIPELINE_H

#include <cstdint>

//! 物理生产/消费缝（P1）：把「Bullet 推进」与「结果回写到骨骼」拆成显式的两步。
//!
//! 生产（Produce）= SyncBonePositionToPhysics → Update(substeps) → 结果进入结果槽；
//! 消费（Consume）= 适配器回写 + SetPhysicsOverride + SetRelMl + MarkMeshHierarchyDirty。
//!
//! P1 阶段恒为「同步、立即消费」：结果槽只记录帧号/有效性/生产耗时/消费标记，
//! 物理量本身仍留在 Bullet 刚体与 IK 适配器上，因此数值与旧的直接调用路径逐位一致。
//! P2 才会把刚体姿态快照进槽、让消费读取 N-1 帧的槽内容（槽的 payload 来源替换）。
//!
//! 三档契约（P1）：
//!   - off(0)：调用方走旧路径；本流水线**不参与**，不产生槽状态、不取计时。
//!   - seam_sync(1)：P1 默认。BeginFrame → MarkProduced → Consume(frame) 同步消费。
//!   - async_reserved(2)：P1 **明确禁止启用**（槽还没有刚体快照，无法安全地产出 N-1 结果）。
//!     配置请求会被拒绝并计入 async_switch_refused，模式保持不变；P2 解除。
//! 非法值策略：环境变量必须是精确的 "0"/"1"/"2"，其余（含 "10"、"2junk"、空串之外的杂项）
//! 一律忽略并计入 invalid_switch_ignored，模式保持当前值。
namespace cmt_physics_pipeline
{

class CmtPhysicsPipeline
{
public:
	enum class Mode : int
	{
		off = 0,            //!< 旧路径：调用方自行 Step，缝不参与
		seam_sync = 1,      //!< P1 默认：显式生产 + 立即消费
		async_reserved = 2  //!< P2 预留：P1 下拒绝启用（见类注释）
	};

	//! 结果槽：P1 只保存状态；P2 会在此追加刚体姿态快照。
	struct Slot
	{
		std::uint64_t frame = 0;      //!< 产生该结果的帧号（单调递增）
		std::uint64_t epoch = 0;      //!< 产生时的 epoch（seek/冷重建/开关切换会推进）
		bool ready = false;           //!< 槽内结果可用
		bool consumed = false;        //!< 该结果已被首次消费
		double produce_ms = 0.0;      //!< 生产耗时（毫秒），人工计时，不做统计推断
	};

	struct Counters
	{
		std::uint64_t begin_frames = 0;         //!< BeginFrame 调用次数（off 档应保持 0）
		std::uint64_t produced = 0;             //!< 生产次数
		std::uint64_t produced_stale = 0;       //!< 过期/错帧生产被丢弃次数
		std::uint64_t consumed = 0;             //!< 首次消费次数
		std::uint64_t reapplied = 0;            //!< 同帧重算：对已消费结果再次回写
		std::uint64_t flushed = 0;              //!< Flush 成功次数
		std::uint64_t stale_consumes = 0;       //!< 无可用/错帧/旧 epoch 的消费请求
		std::uint64_t stale_reapplies = 0;      //!< 未消费结果上的 Reapply 请求
		std::uint64_t epoch_invalidations = 0;  //!< seek/冷重建/开关切换导致的结果作废次数
		std::uint64_t invalid_switch_ignored = 0; //!< 非法开关值被忽略次数
		std::uint64_t async_switch_refused = 0; //!< P1 下 2 档启用被拒绝次数
	};

	CmtPhysicsPipeline() = default;

	//! 切换模式；模式真正变化时作废当前槽并推进 epoch（开关切换不得沿用旧结果）。
	//! P1 下 async_reserved 会被拒绝（计数后保持原模式）。
	void Configure(Mode mode);
	//! 严格解析环境变量 CMT_PHYSICS_PIPELINE（只接受 "0"/"1"/"2"）。
	void ConfigureFromEnvironment();
	//! 直接按字符串解析（供测试与 P2 的描述参数复用），返回是否被接受。
	bool ConfigureFromString(const char* raw);

	Mode GetMode() const { return mode_; }
	bool SeamEnabled() const { return mode_ != Mode::off; }
	bool ShouldConsumeImmediately() const { return mode_ == Mode::seam_sync; }
	bool AsyncEnabled() const { return false; } //!< P1 恒 false

	std::uint64_t Frame() const { return slot_.frame; }
	std::uint64_t PendingFrame() const { return pending_frame_; }
	std::uint64_t Epoch() const { return epoch_; }
	bool Ready() const { return slot_.ready; }
	bool Consumed() const { return slot_.consumed; }
	double ProduceMs() const { return slot_.produce_ms; }
	const Slot& GetSlot() const { return slot_; }
	const Counters& GetCounters() const { return counters_; }

	//! 新帧开始：返回本帧编号，清 ready/consumed（强制「先生产再消费」）。
	std::uint64_t BeginFrame();
	//! 生产完成：frame 必须是最近 BeginFrame 的返回值且 epoch 未变，否则整槽作废。
	void MarkProduced(std::uint64_t frame, double produce_ms);
	//! 首次消费：必须匹配 expected_frame 且属于当前 epoch；已消费过返回 false。
	bool Consume(std::uint64_t expected_frame);
	//! 同帧重算：对已消费的同一帧结果再次回写（数值不变），未消费过则返回 false。
	bool Reapply(std::uint64_t expected_frame);
	//! 供插件内部直接调用 ExecutePasses 的路径使用：消费当前帧的挂起结果。
	//! 返回「该帧结果是否已就绪可用」。
	bool Flush(std::uint64_t expected_frame);
	//! seek / 冷重建 / 在途任务取消：清槽并推进 epoch。
	void InvalidateEpoch();
	void Reset();

private:
	Mode mode_ = Mode::seam_sync;
	std::uint64_t next_frame_ = 1;
	std::uint64_t pending_frame_ = 0;
	std::uint64_t epoch_ = 1;
	Slot slot_ {};
	Counters counters_ {};
};

} // namespace cmt_physics_pipeline

#endif // CMT_PHYSICS_PIPELINE_H
