#include "module/tools/object/cmt_physics_pipeline.h"

#include <cstdlib>
#include <cstring>

namespace cmt_physics_pipeline
{
namespace
{
	//! 严格匹配 "0"/"1"/"2"；其余一律视为非法（不做首字符宽容）。
	bool ParseModeStrict(const char* const raw, CmtPhysicsPipeline::Mode& out)
	{
		if (raw == nullptr)
			return false;
		if (std::strcmp(raw, "0") == 0) { out = CmtPhysicsPipeline::Mode::off; return true; }
		if (std::strcmp(raw, "1") == 0) { out = CmtPhysicsPipeline::Mode::seam_sync; return true; }
		if (std::strcmp(raw, "2") == 0) { out = CmtPhysicsPipeline::Mode::async_reserved; return true; }
		return false;
	}
}

void CmtPhysicsPipeline::Configure(const Mode mode)
{
	// P1 没有刚体快照，async_reserved 无法安全产出 N-1 结果：明确拒绝启用。
	if (mode == Mode::async_reserved)
	{
		++counters_.async_switch_refused;
		return;
	}
	if (mode == mode_)
		return;

	// 开关切换属于「结果语义边界」：旧槽属于旧模式，必须作废并推进 epoch。
	mode_ = mode;
	InvalidateEpoch();
}

bool CmtPhysicsPipeline::ConfigureFromString(const char* const raw)
{
	Mode parsed = mode_;
	if (!ParseModeStrict(raw, parsed))
	{
		// 非法/多字符值：忽略，模式保持当前值（与头文件注释一致）。
		++counters_.invalid_switch_ignored;
		return false;
	}
	if (parsed == Mode::async_reserved)
	{
		Configure(parsed); // 内部计数拒绝
		return false;
	}
	Configure(parsed);
	return true;
}

void CmtPhysicsPipeline::ConfigureFromEnvironment()
{
	// 开关走运行时环境变量：P1 只提供「开/关」两档可用行为，不改描述资源，
	// 避免在产品树里新增可见参数位；P2 接入描述参数时只需在此覆盖 mode_。
	ConfigureFromString(std::getenv("CMT_PHYSICS_PIPELINE"));
}

std::uint64_t CmtPhysicsPipeline::BeginFrame()
{
	++counters_.begin_frames;
	const std::uint64_t frame = next_frame_++;
	pending_frame_ = frame;
	// 强制「先生产再消费」：上一帧残留的结果不能在本帧被消费。
	slot_.ready = false;
	slot_.consumed = false;
	slot_.frame = 0;
	slot_.produce_ms = 0.0;
	return frame;
}

void CmtPhysicsPipeline::MarkProduced(const std::uint64_t frame, const double produce_ms)
{
	// frame 必须是最近 BeginFrame 的返回值：否则是过期生产（seek/reset 之后又收到旧调用），
	// 直接丢弃并推进 epoch，保证消费端永远看不到跨 epoch 的结果。
	if (frame == 0 || frame != pending_frame_ || frame + 1 != next_frame_)
	{
		++counters_.produced_stale;
		InvalidateEpoch();
		return;
	}

	slot_.frame = frame;
	slot_.epoch = epoch_;
	slot_.ready = true;
	slot_.consumed = false;
	slot_.produce_ms = produce_ms;
	++counters_.produced;
}

bool CmtPhysicsPipeline::Consume(const std::uint64_t expected_frame)
{
	if (!SeamEnabled() || !slot_.ready || slot_.epoch != epoch_ || slot_.frame != expected_frame)
	{
		++counters_.stale_consumes;
		return false;
	}

	if (slot_.consumed)
	{
		// 同一结果再次消费必须显式走 Reapply：这里拒绝，避免真实回写被重复执行。
		++counters_.stale_consumes;
		return false;
	}

	slot_.consumed = true;
	++counters_.consumed;
	return true;
}

bool CmtPhysicsPipeline::Reapply(const std::uint64_t expected_frame)
{
	if (!SeamEnabled() || !slot_.ready || slot_.epoch != epoch_ || slot_.frame != expected_frame || !slot_.consumed)
	{
		++counters_.stale_reapplies;
		return false;
	}

	++counters_.reapplied;
	return true;
}

bool CmtPhysicsPipeline::Flush(const std::uint64_t expected_frame)
{
	if (!SeamEnabled())
		return false;

	if (!slot_.ready || slot_.epoch != epoch_ || slot_.frame != expected_frame)
	{
		++counters_.stale_consumes;
		return false;
	}

	if (!slot_.consumed)
	{
		slot_.consumed = true;
		++counters_.consumed;
	}
	++counters_.flushed;
	return true;
}

void CmtPhysicsPipeline::InvalidateEpoch()
{
	// seek / 冷重建 / 开关切换：世界或语义边界变了，旧结果不再对应任何刚体，必须整槽作废。
	++epoch_;
	pending_frame_ = 0;
	slot_ = Slot {};
	++counters_.epoch_invalidations;
}

void CmtPhysicsPipeline::Reset()
{
	mode_ = Mode::seam_sync;
	next_frame_ = 1;
	pending_frame_ = 0;
	epoch_ = 1;
	slot_ = Slot {};
	counters_ = Counters {};
}

} // namespace cmt_physics_pipeline
