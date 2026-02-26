# Animation & Physics Pipeline Optimization

## Summary

Optimized the per-frame animation and physics update pipeline in libMMD and the C4D plugin layer. Key changes: eliminated redundant node traversals via pre-partitioning, skipped zero-weight morphs, parameterized physics timestep, merged rigid body loops, and replaced the Bezier bisection solver with Newton-Raphson.

## Motivation

- `PMXModel::UpdateNodeAnimation` traversed the full `m_sortedNodes` array 4 times per call (8 times per frame), with each iteration branching on `IsDeformAfterPhysics()` to skip ~50% of nodes.
- `UpdateMorphAnimation` processed all morphs unconditionally, including those with zero weight, wasting cycles on identity matrix operations.
- `VMDAnimation::SyncPhysics` hardcoded the physics timestep to `1/30s` regardless of actual scene FPS, causing inconsistent physics warmup behavior.
- `UpdatePhysicsAnimation` called `SetActivation(true)` on every rigid body every frame (redundant after initialization) and used separate loops for `ReflectGlobalTransform` and `CalcLocalTransform`.
- `VMDBezier::FindBezierX` used binary search (~17 iterations); cubic Bezier has an analytic derivative enabling Newton-Raphson convergence in 3-5 iterations.
- `Execute` computed `now_time.Get() * fps_` twice.

## Changes

### libMMD: PMXModel Node Partition

| Area | Before | After |
|------|--------|-------|
| Node storage | Single `m_sortedNodes` array | Added `m_beforePhysicsNodes` + `m_afterPhysicsNodes` |
| `UpdateNodeAnimation(bool)` | 4 loops × full array, branch-filter each node | 4 loops × pre-filtered sub-array, no branches |
| Partition timing | N/A | Built in `LoadPMX` after `m_sortedNodes` sort |

### libMMD: Zero-Weight Morph Skip

| Area | Before | After |
|------|--------|-------|
| `UpdateMorphAnimation` | Calls `Morph()` for every morph | Skips when `GetWeight() == 0.0f` |

### libMMD: SyncPhysics Parameterization

| Area | Before | After |
|------|--------|-------|
| `SyncPhysics` signature | `SyncPhysics(float t, int frameCount = 30)` | `SyncPhysics(float t, int frameCount = 30, float physicsElapsed = 1.0f/30.0f)` |
| Physics timestep in warmup loop | Hardcoded `1.0f / 30.0f` | Uses `physicsElapsed` parameter |

### libMMD: Rigid Body Loop Merge

| Area | Before | After |
|------|--------|-------|
| `UpdatePhysicsAnimation` loops | 3 separate loops: SetActivation, ReflectGlobalTransform, CalcLocalTransform | 1 loop: ReflectGlobalTransform + CalcLocalTransform |
| `SetActivation(true)` | Called every frame in `UpdatePhysicsAnimation` | Called once in `InitializeAnimation` |
| Applies to | PMXModel and PMDModel | Both updated consistently |

### libMMD: Newton-Raphson Bezier Solver

| Area | Before | After |
|------|--------|-------|
| `FindBezierX` algorithm | Binary search (~17 iterations) | Newton-Raphson (≤8 iterations) with bisection fallback |
| `VMDBezier` API | `EvalX`, `EvalY`, `Eval` | Added `EvalDX` (analytic derivative) |

### C4D Plugin: Execute Cleanup

| Area | Before | After |
|------|--------|-------|
| `vmd_frame` calculation | Computed twice (`SyncPhysics` call + `UpdateAllAnimation` call) | Computed once, reused |
| `SyncPhysics` call | `animation->SyncPhysics(vmd_frame)` | `animation->SyncPhysics(vmd_frame, 30, 1.f / fps_)` |

## Affected Specs

- **vmd-motion**: `Execute()` flow updated — `vmd_frame` reuse and `SyncPhysics` now receives actual FPS-based timestep.
- **physics**: `UpdatePhysicsAnimation` loop structure changed; `SetActivation` moved to initialization phase.
- **morph-system**: `UpdateMorphAnimation` now skips zero-weight morphs.

## Affected Source Files

| File | Change |
|------|--------|
| `dependency/libMMD/src/libMMD/Model/MMD/PMXModel.h` | Added `m_beforePhysicsNodes`, `m_afterPhysicsNodes` members |
| `dependency/libMMD/src/libMMD/Model/MMD/PMXModel.cpp` | `LoadPMX` partition; `UpdateNodeAnimation` rewrite; `UpdatePhysicsAnimation` loop merge; `InitializeAnimation` adds `SetActivation`; `UpdateMorphAnimation` zero-weight skip |
| `dependency/libMMD/src/libMMD/Model/MMD/PMDModel.cpp` | `UpdatePhysicsAnimation` loop merge; `InitializeAnimation` adds `SetActivation` |
| `dependency/libMMD/src/libMMD/Model/MMD/VMDAnimation.h` | `SyncPhysics` signature with `physicsElapsed` param; `VMDBezier::EvalDX` declaration |
| `dependency/libMMD/src/libMMD/Model/MMD/VMDAnimation.cpp` | `SyncPhysics` uses param; `EvalDX` implementation; `FindBezierX` Newton-Raphson rewrite |
| `refactoring/module/tools/object/mmd_model_manager.cpp` | `vmd_frame` reuse; `SyncPhysics` call with `1.f / fps_` |
| `dependency/libMMD/tests/MMDModel.test.cpp` | 20 new tests covering all optimization items |
