#pragma once
#include "cmt_runtime_profile.hpp"
#if CMT_ENABLE_RUNTIME_PROFILING
#include <cstring>
#include <optional>

namespace cmt_runtime
{
// Bullet's existing BT_PROFILE zones use static string literals. Keep the
// bridge SDK-independent; registration against Bullet lives in the C4D adapter.
inline RuntimeStage BulletStage(const char* name)
{
    struct Mapping { const char* name; RuntimeStage stage; };
    static constexpr Mapping mapping[] = {
        {"internalSingleStepSimulation", RuntimeStage::BulletSubstep},
        {"predictUnconstraintMotion", RuntimeStage::BulletPredict},
        {"createPredictiveContacts", RuntimeStage::BulletPredictiveContacts},
        {"performDiscreteCollisionDetection", RuntimeStage::BulletCollision},
        {"updateAabbs", RuntimeStage::BulletAabb},
        {"calculateOverlappingPairs", RuntimeStage::BulletBroadphase},
        {"dispatchAllCollisionPairs", RuntimeStage::BulletDispatch},
        {"calculateSimulationIslands", RuntimeStage::BulletIslands},
        {"solveConstraints", RuntimeStage::BulletSolve},
        {"solveGroupCacheFriendlySetup", RuntimeStage::BulletSolverSetup},
        {"convertBodies", RuntimeStage::BulletSolverBodies},
        {"convertJoints", RuntimeStage::BulletSolverJoints},
        {"solveGroupCacheFriendlyIterations", RuntimeStage::BulletSolverIterations},
        {"solveGroupCacheFriendlySplitImpulseIterations", RuntimeStage::BulletSolverSplitImpulse},
        {"solveGroupCacheFriendlyFinish", RuntimeStage::BulletSolverFinish},
        {"integrateTransforms", RuntimeStage::BulletIntegrate},
        {"updateActivationState", RuntimeStage::BulletActivation},
        {"updateActions", RuntimeStage::BulletActions}
    };
    for (const auto& item : mapping)
        if (!std::strcmp(name, item.name)) return item.stage;
    return RuntimeStage::Count;
}

template<class Clock = std::chrono::steady_clock>
class BulletProfileBridge
{
public:
    void Enter(const char* name)
    {
        const auto index = depth_++;
        if (index >= scopes_.size() || !detail::active_frame_metrics) return;
        auto& slot = cache_[(reinterpret_cast<std::uintptr_t>(name) >> 3) % cache_.size()];
        if (slot.name != name) slot = {name, BulletStage(name)};
        if (slot.stage != RuntimeStage::Count) scopes_[index].emplace(slot.stage);
    }
    void Leave()
    {
        if (!depth_) return;
        const auto index = --depth_;
        if (index < scopes_.size()) scopes_[index].reset();
    }
private:
    struct Slot { const char* name = nullptr; RuntimeStage stage = RuntimeStage::Count; };
    // No allocations, shared locks or I/O on Bullet's hot path. Unknown and
    // overflowing zones still balance their depth without disturbing parents.
    std::array<Slot, 128> cache_{};
    std::array<std::optional<BasicScopedRuntimeStage<Clock>>, 128> scopes_{};
    std::size_t depth_ = 0;
};
}
#endif
