#pragma once

#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>

namespace cmt_runtime
{

enum class RuntimeStage : std::size_t
{
	Rebuild,
	Animation,
	IK,
	Physics,
	Morph,
	MaterialSync,
	Count
};

struct FrameMetrics
{
	explicit FrameMetrics(const bool enabled_) : enabled(enabled_) {}
	bool enabled;
	std::array<double, static_cast<std::size_t>(RuntimeStage::Count)> milliseconds{};
	std::array<std::uint64_t, static_cast<std::size_t>(RuntimeStage::Count)> calls{};

	double Milliseconds(const RuntimeStage stage) const { return milliseconds[static_cast<std::size_t>(stage)]; }
};

namespace detail
{
	inline thread_local FrameMetrics* active_frame_metrics = nullptr;
}

// Nested document evaluation (for example export on a clone) gets its own
// metrics and restores the caller's frame when it finishes.
class ScopedFrameMetrics
{
public:
	explicit ScopedFrameMetrics(FrameMetrics& metrics)
		: previous_(detail::active_frame_metrics)
	{
		detail::active_frame_metrics = metrics.enabled ? &metrics : nullptr;
	}
	~ScopedFrameMetrics() { detail::active_frame_metrics = previous_; }
	ScopedFrameMetrics(const ScopedFrameMetrics&) = delete;
	ScopedFrameMetrics& operator=(const ScopedFrameMetrics&) = delete;

private:
	FrameMetrics* previous_;
};

class ScopedRuntimeStage
{
public:
	explicit ScopedRuntimeStage(const RuntimeStage stage)
		: metrics_(detail::active_frame_metrics), stage_(static_cast<std::size_t>(stage))
	{
		if (metrics_)
			start_ = Clock::now();
	}
	~ScopedRuntimeStage()
	{
		if (!metrics_)
			return;
		metrics_->milliseconds[stage_] += std::chrono::duration<double, std::milli>(Clock::now() - start_).count();
		++metrics_->calls[stage_];
	}
	ScopedRuntimeStage(const ScopedRuntimeStage&) = delete;
	ScopedRuntimeStage& operator=(const ScopedRuntimeStage&) = delete;

private:
	using Clock = std::chrono::steady_clock;
	FrameMetrics* metrics_;
	std::size_t stage_;
	Clock::time_point start_{};
};

} // namespace cmt_runtime
