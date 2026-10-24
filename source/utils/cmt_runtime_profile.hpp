#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

// Keep the core SDK-independent. Disabled builds do not evaluate macro arguments.
#ifndef CMT_ENABLE_RUNTIME_PROFILING
#define CMT_ENABLE_RUNTIME_PROFILING 0
#endif
#if CMT_ENABLE_RUNTIME_PROFILING
#include <algorithm>
#include <chrono>
#endif

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
	ModelExecute, ManagerUpdate, PlaybackPlan, BoneTagExecute, BoneManagerExecute,
	BoneAnimation, BoneStateSync, HierarchySync, AppendOrder, ControlPresentation,
	ControlSolve, BoneMorphChecksum, MorphWeights, MorphApply, MorphPreview,
	ModelSetParameter, BoneSetParameter, PhysicsSync, PhysicsStep, PhysicsWriteback,
	MeshManagerExecute, MeshInvalidation, WeightUpdate,
	ControlChains, ControlChecksum, ControlDelta, ControlSync, MaterialOwnership,
	BulletSubstep, BulletPredict, BulletPredictiveContacts, BulletCollision,
	BulletAabb, BulletBroadphase, BulletDispatch, BulletIslands, BulletSolve,
	BulletSolverSetup, BulletSolverBodies, BulletSolverJoints, BulletSolverIterations,
	BulletSolverSplitImpulse, BulletSolverFinish, BulletIntegrate, BulletActivation, BulletActions,
	Count
};

inline const char* RuntimeStageName(const RuntimeStage stage)
{
	static constexpr const char* names[] = {
		"runtime.rebuild", "animation.layer", "ik.solve", "physics.total", "morph.total", "material.sync",
		"model.execute", "model.managers", "bone.plan", "bone.tag.execute", "bone.manager.execute",
		"bone.animation", "bone.scene_sync", "bone.hierarchy", "bone.append_order", "control.presentation",
		"control.solve", "morph.bone_checksum", "morph.weights", "morph.apply", "morph.preview",
		"model.set_parameter", "bone.set_parameter", "physics.inputs", "physics.bullet", "physics.writeback",
		"mesh.manager.execute", "mesh.invalidate", "mesh.weight_update",
		"control.chains", "control.checksum", "control.delta", "control.sync", "material.ownership",
		"bullet.substep", "bullet.predict", "bullet.predictive_contacts", "bullet.collision",
		"bullet.aabb", "bullet.broadphase", "bullet.dispatch", "bullet.islands", "bullet.solve",
		"bullet.solver.setup", "bullet.solver.bodies", "bullet.solver.joints", "bullet.solver.iterations",
		"bullet.solver.split_impulse", "bullet.solver.finish", "bullet.integrate", "bullet.activation", "bullet.actions"
	};
	static_assert(sizeof(names) / sizeof(names[0]) == static_cast<std::size_t>(RuntimeStage::Count));
	return names[static_cast<std::size_t>(stage)];
}

struct FrameMetrics
{
	explicit FrameMetrics(const bool enabled_) : enabled(CMT_ENABLE_RUNTIME_PROFILING && enabled_) {}
	bool enabled;
	std::array<double, static_cast<std::size_t>(RuntimeStage::Count)> milliseconds{};
	std::array<std::uint64_t, static_cast<std::size_t>(RuntimeStage::Count)> calls{};
	std::array<double, static_cast<std::size_t>(RuntimeStage::Count)> self_milliseconds{};
	std::array<double, static_cast<std::size_t>(RuntimeStage::Count)> maximum_milliseconds{};
	double root_milliseconds = 0.0;
	std::uint64_t root_calls = 0;

	double Milliseconds(const RuntimeStage stage) const { return milliseconds[static_cast<std::size_t>(stage)]; }
	void Merge(const FrameMetrics& other)
	{
		for (std::size_t i = 0; i < calls.size(); ++i)
		{
			milliseconds[i] += other.milliseconds[i];
			self_milliseconds[i] += other.self_milliseconds[i];
			if (other.maximum_milliseconds[i] > maximum_milliseconds[i])
				maximum_milliseconds[i] = other.maximum_milliseconds[i];
			calls[i] += other.calls[i];
		}
		root_milliseconds += other.root_milliseconds;
		root_calls += other.root_calls;
	}
};

namespace detail
{
	inline thread_local FrameMetrics* active_frame_metrics = nullptr;
#if CMT_ENABLE_RUNTIME_PROFILING
	struct ScopeState
	{
		FrameMetrics* metrics = nullptr;
		ScopeState* parent = nullptr;
		double child_milliseconds = 0.0;
	};
	inline thread_local ScopeState* active_scope = nullptr;
#endif
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

#if CMT_ENABLE_RUNTIME_PROFILING
// Clock injection makes tests deterministic, without sleeps or time tolerances.
template <class Clock>
class BasicScopedRuntimeStage
{
public:
	explicit BasicScopedRuntimeStage(const RuntimeStage stage)
		: stage_(static_cast<std::size_t>(stage))
	{
		state_.metrics = detail::active_frame_metrics;
		if (!state_.metrics) return;
		state_.parent = detail::active_scope;
		detail::active_scope = &state_;
		start_ = Clock::now();
	}
	~BasicScopedRuntimeStage()
	{
		if (!state_.metrics) return;
		const double elapsed = std::chrono::duration<double, std::milli>(Clock::now() - start_).count();
		auto& metrics = *state_.metrics;
		metrics.milliseconds[stage_] += elapsed;
		metrics.self_milliseconds[stage_] += std::max(0.0, elapsed - state_.child_milliseconds);
		metrics.maximum_milliseconds[stage_] = std::max(metrics.maximum_milliseconds[stage_], elapsed);
		++metrics.calls[stage_];
		if (!state_.parent || state_.parent->metrics != state_.metrics)
		{
			metrics.root_milliseconds += elapsed;
			++metrics.root_calls;
		}
		if (state_.parent) state_.parent->child_milliseconds += elapsed;
		detail::active_scope = state_.parent;
	}
	BasicScopedRuntimeStage(const BasicScopedRuntimeStage&) = delete;
	BasicScopedRuntimeStage& operator=(const BasicScopedRuntimeStage&) = delete;

private:
	detail::ScopeState state_;
	std::size_t stage_;
	typename Clock::time_point start_{};
};
using ScopedRuntimeStage = BasicScopedRuntimeStage<std::chrono::steady_clock>;
#else
class ScopedRuntimeStage
{
public:
	explicit ScopedRuntimeStage(RuntimeStage) {}
};
#endif

} // namespace cmt_runtime

#define CMT_PROFILE_JOIN_IMPL(a, b) a##b
#define CMT_PROFILE_JOIN(a, b) CMT_PROFILE_JOIN_IMPL(a, b)
#if CMT_ENABLE_RUNTIME_PROFILING
#define CMT_PROFILE_SCOPE(stage) \
	::cmt_runtime::ScopedRuntimeStage CMT_PROFILE_JOIN(cmt_profile_scope_, __COUNTER__)(stage)
#else
#define CMT_PROFILE_SCOPE(stage) ((void)0)
#endif
