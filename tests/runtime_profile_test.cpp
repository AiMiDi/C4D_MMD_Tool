#include "utils/cmt_runtime_profile.hpp"
#include "utils/cmt_runtime_profile_report.hpp"
#include "utils/cmt_runtime_profile_bullet.hpp"

#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

namespace
{
	struct ManualClock
	{
		using time_point = std::chrono::time_point<ManualClock, std::chrono::milliseconds>;
		inline static std::int64_t ticks = 0;
		inline static int reads = 0;
		static time_point now() { ++reads; return time_point(std::chrono::milliseconds(ticks)); }
	};
	using Stage = cmt_runtime::BasicScopedRuntimeStage<ManualClock>;
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
		Stage stage(RuntimeStage::IK);
	}
	Require(disabled.calls[static_cast<std::size_t>(RuntimeStage::IK)] == 0, "disabled diagnostics must not measure stages");
	Require(disabled.Milliseconds(RuntimeStage::IK) == 0.0, "disabled diagnostics must stay zero");
	Require(ManualClock::reads == 0, "runtime disabled scopes must not read the clock");
	BulletProfileBridge<ManualClock> bridge;
	bridge.Enter("solveConstraints");
	bridge.Leave();
	Require(ManualClock::reads == 0, "Bullet outside a profiled evaluation must not read the clock");
	FrameMetrics bullet(true);
	{
		ScopedFrameMetrics frame(bullet);
		ManualClock::ticks = 0;
		bridge.Enter("solveConstraints");
		ManualClock::ticks = 1;
		bridge.Enter("unmapped Bullet zone");
		bridge.Enter("solveGroupCacheFriendlySetup");
		ManualClock::ticks = 4;
		bridge.Leave();
		bridge.Leave();
		ManualClock::ticks = 7;
		bridge.Leave();
	}
	Require(bullet.Milliseconds(RuntimeStage::BulletSolverSetup) == 3, "Bullet child duration recorded");
	Require(bullet.Milliseconds(RuntimeStage::BulletSolve) == 7, "unknown Bullet zones preserve nesting");
	Require(bullet.self_milliseconds[static_cast<std::size_t>(RuntimeStage::BulletSolve)] == 4, "Bullet parent excludes measured child");
	{
		ScopedFrameMetrics frame(bullet);
		for (int i = 0; i < 132; ++i) bridge.Enter("unmapped Bullet zone");
		bridge.Enter("solveConstraints");
		for (int i = 0; i < 133; ++i) bridge.Leave();
		bridge.Enter("solveConstraints");
		bridge.Leave();
	}
	Require(bullet.calls[static_cast<std::size_t>(RuntimeStage::BulletSolve)] == 2, "overflow restores balanced Bullet stack");
	Require(detail::active_scope == nullptr, "Bullet leaves no active scope");

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
	FrameMetrics recursive(true);
	{
		ScopedFrameMetrics frame(recursive);
		ManualClock::ticks = 0;
		Stage parent(RuntimeStage::Morph);
		ManualClock::ticks = 2;
		{
			Stage child(RuntimeStage::Morph);
			ManualClock::ticks = 5;
		}
		ManualClock::ticks = 9;
	}
	const auto morph = static_cast<std::size_t>(RuntimeStage::Morph);
	Require(recursive.milliseconds[morph] == 12, "recursive inclusive times include child");
	Require(recursive.self_milliseconds[morph] == 9, "recursive self times count wall time once");
	Require(recursive.maximum_milliseconds[morph] == 9 && recursive.calls[morph] == 2, "peak and count aggregate recursive calls");
	Require(recursive.root_milliseconds == 9 && recursive.root_calls == 1, "root wall time is not the sum of inclusive scopes");

	FrameMetrics first_doc(true), second_doc(true);
	{
		ScopedFrameMetrics frame(first_doc);
		ManualClock::ticks = 0;
		Stage parent(RuntimeStage::ModelExecute);
		ManualClock::ticks = 3;
		{
			ScopedFrameMetrics inner(second_doc);
			Stage child(RuntimeStage::IK);
			ManualClock::ticks = 7;
		}
		ManualClock::ticks = 10;
	}
	Require(first_doc.self_milliseconds[static_cast<std::size_t>(RuntimeStage::ModelExecute)] == 6, "nested document time excluded from caller self time");
	Require(second_doc.Milliseconds(RuntimeStage::IK) == 4, "nested document measured independently");
	std::thread worker([] {
		Require(detail::active_frame_metrics == nullptr && detail::active_scope == nullptr, "TLS starts empty on worker");
		FrameMetrics local(true);
		ScopedFrameMetrics frame(local);
		ScopedRuntimeStage scope(RuntimeStage::IK);
	});
	worker.join();
	Require(detail::active_frame_metrics == nullptr && detail::active_scope == nullptr, "worker cannot change caller TLS");

	std::vector<FrameMetrics> batches;
	auto sink = [&batches](const ProfileContext&, const FrameMetrics& value) { batches.push_back(value); };
	ProfileBatchCollector<decltype(sink)> collector(sink);
	ProfileContext context{1, 2, 1.0, 30, 30};
	collector.Add(context, recursive);
	collector.Add(context, recursive);
	Require(batches.empty(), "same-frame roots remain in memory");
	++context.frame;
	collector.Add(context, recursive);
	Require(batches.size() == 1 && batches[0].calls[morph] == 4, "frame change emits combined roots");
	Require(batches[0].self_milliseconds[morph] == 18 && batches[0].maximum_milliseconds[morph] == 9, "batch sums durations but takes peak maximum");
	collector.Flush(); collector.Flush();
	Require(batches.size() == 2, "flush emits last batch once");
	const auto json = FormatProfileBatch(context, recursive, 10, 20, 1);
	Require(json.find("\"frame\":31") != std::string::npos && json.find("\"self_ms\":9") != std::string::npos, "JSON includes context and self timing");
	Require(json.find("morph.total") != std::string::npos, "stable stage name emitted");
	std::cout << "runtime profiling regression passed\n";
}
