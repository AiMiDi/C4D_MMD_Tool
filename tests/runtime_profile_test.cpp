#include "utils/cmt_runtime_profile.hpp"

#include <cstdlib>
#include <iostream>

namespace
{
	void Require(bool condition, const char* message)
	{
		if (!condition)
		{
			std::cerr << message << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	using namespace cmt_runtime;
	FrameMetrics disabled(false);
	{
		ScopedFrameMetrics frame(disabled);
		ScopedRuntimeStage stage(RuntimeStage::IK);
	}
	Require(disabled.calls[static_cast<std::size_t>(RuntimeStage::IK)] == 0, "disabled diagnostics must not measure stages");
	Require(disabled.Milliseconds(RuntimeStage::IK) == 0.0, "disabled diagnostics must stay zero");

	FrameMetrics outer(true), nested(true);
	{
		ScopedFrameMetrics frame(outer);
		{ ScopedRuntimeStage stage(RuntimeStage::Animation); }
		{
			ScopedFrameMetrics nested_frame(nested);
			ScopedRuntimeStage stage(RuntimeStage::IK);
		}
		{ ScopedRuntimeStage stage(RuntimeStage::Physics); }
	}
	Require(outer.calls[static_cast<std::size_t>(RuntimeStage::Animation)] == 1, "outer animation measured");
	Require(outer.calls[static_cast<std::size_t>(RuntimeStage::Physics)] == 1, "outer metrics restored after nested evaluation");
	Require(outer.calls[static_cast<std::size_t>(RuntimeStage::IK)] == 0, "nested document must not pollute outer metrics");
	Require(nested.calls[static_cast<std::size_t>(RuntimeStage::IK)] == 1, "nested IK measured independently");
	Require(detail::active_frame_metrics == nullptr, "frame guard restores previous thread state");
	std::cout << "runtime profiling regression passed\n";
}
