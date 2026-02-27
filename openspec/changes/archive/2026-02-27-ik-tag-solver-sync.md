# IK Tag → Solver Sync in Edit Mode

## Summary

When the user edits IK properties on an `MMDBoneTag` in edit mode (iteration count, unit angle, target bone, IK enable/disable, IK chain links), propagate those changes back to the corresponding `MMDIkSolver` in libMMD. Currently the UI fields are display-only after import — edits are silently lost.

## Motivation

- PMX import populates both the C4D bone tag UI fields (`PMX_BONE_IK_*`) and the libMMD `MMDIkSolver` from the PMX data. After import, these are two independent copies.
- In edit mode (`BONE_MODE_EDIT`), the bone tag description fields are editable, but changing them has no effect on the actual IK solver used during animation playback.
- `HandleBoneModeChange` contains `// TODO: Save to mmd_node_` — this was planned but never implemented.
- Without this sync, any IK tuning done through the UI (adjusting iteration count, limit angle, changing target bone, toggling IK on/off) is ignored when switching back to VMD mode or playing animation.

## Design

### Access Path

```
MMDBoneTag::mmd_node_ (MMDNode*)
    → static_cast<PMXNode*>(mmd_node_)
        → PMXNode::GetIKSolver()
            → MMDIkSolver*
```

`mmd_node_` is always a `PMXNode*` at runtime (set in `MMDBoneManagerObject::LoadPMX` via `mmd_node_manager_->GetMMDNode()`), so the cast is safe. However, to avoid relying on an unchecked downcast, the preferred approach is to lift `GetIKSolver()` / `SetIKSolver()` to the `MMDNode` base class as virtual methods, or store the `MMDIkSolver*` pointer directly on the bone tag.

### Recommended Approach: Store IK solver pointer on MMDBoneTag

Add an `MMDIkSolver*` member to `MMDBoneTag`, set during `MMDBoneManagerObject::LoadPMX` alongside `mmd_node_`. This avoids downcasting and keeps the dependency explicit.

### Properties to Sync

| UI Field (TMMDBone.h) | MMDIkSolver Method | When |
|---|---|---|
| `PMX_BONE_IK_ITERATION` | `SetIterateCount(uint32_t)` | `SetDParameter` / `HandleDescriptionUpdate` |
| `PMX_BONE_IK_UNIT_ANGLE` | `SetLimitAngle(float)` | `SetDParameter` / `HandleDescriptionUpdate` |
| `PMX_BONE_IK_TARGET_BONE_INDEX` | `SetTargetNode(MMDNode*)` | `SetDParameter` — requires node lookup via bone manager |
| `PMX_BONE_IS_IK` | `Enable(bool)` | `SetDParameter` (already partially handled for UI visibility) |

### IK Chain Edits

IK chain links are dynamic descriptions created at import time. Changes to chain link properties (enable limit, limit min/max) require rebuilding or mutating the solver's internal `m_chains` vector. Since `MMDIkSolver` currently only exposes `AddIKChain()` (append-only), two options:

1. **Add mutation API to MMDIkSolver**: `SetChainLimit(size_t idx, bool enable, Vector3f min, Vector3f max)`, `RemoveIKChain(size_t idx)`, `ClearIKChains()` + re-add.
2. **Rebuild solver chains on edit**: Clear all chains and re-add from the current UI state. Simpler but requires reading all dynamic description fields.

Option 2 (rebuild) is recommended — it's simpler and IK chain edits are infrequent.

### Sync Trigger Points

Two approaches, both valid:

**A. Immediate sync (in `SetDParameter`)**: Each IK property change immediately calls the corresponding solver setter. Most responsive, but requires the solver pointer at edit time.

**B. Deferred sync (on mode switch)**: When switching from `BONE_MODE_EDIT` to `BONE_MODE_VMD`/`BONE_MODE_ANIM`, read all IK fields from the tag's `BaseContainer` and push them to the solver. Simpler, single sync point.

**Recommendation**: Use approach **A** for scalar properties (iteration, angle, enable) since they're trivial one-liners, and approach **B** for IK chain rebuilds (complex, multi-field).

## Changes

### libMMD: MMDIkSolver chain mutation API

| Area | Before | After |
|------|--------|-------|
| Chain management | `AddIKChain()` only (append) | Add `ClearIKChains()` to allow rebuild |

### Plugin: MMDBoneTag IK solver pointer

| Area | Before | After |
|------|--------|-------|
| `MMDBoneTag` members | `mmd_node_` only | Add `ik_solver_` (`MMDIkSolver*`) |
| `MMDBoneManagerObject::LoadPMX` | Sets `mmd_node_` | Also sets `ik_solver_` via `PMXNode::GetIKSolver()` |

### Plugin: MMDBoneTag edit-mode sync

| Area | Before | After |
|------|--------|-------|
| `SetDParameter` `PMX_BONE_IK_ITERATION` | No sync | `ik_solver_->SetIterateCount()` |
| `SetDParameter` `PMX_BONE_IK_UNIT_ANGLE` | No sync | `ik_solver_->SetLimitAngle()` |
| `SetDParameter` `PMX_BONE_IS_IK` | UI visibility only | Also `ik_solver_->Enable()` |
| `SetDParameter` `PMX_BONE_IK_TARGET_BONE_INDEX` | No sync | Lookup node via bone manager, `ik_solver_->SetTargetNode()` |
| `HandleBoneModeChange` (edit→other) | `// TODO` | Rebuild IK chains from dynamic description fields |

### Plugin: HandleBoneModeChange TODO resolution

| Area | Before | After |
|------|--------|-------|
| `HandleBoneModeChange` edit→VMD/anim | Empty `// TODO: Save to mmd_node_` | Rebuild IK chains from current UI state to solver |

## Affected Specs

- **vmd-motion**: IK solver state now reflects edit-mode changes before animation playback.
- **model-import**: `MMDBoneManagerObject::LoadPMX` sets additional `ik_solver_` pointer on bone tags.

## Affected Source Files

| File | Change |
|------|--------|
| `dependency/libMMD/src/libMMD/Model/MMD/MMDIkSolver.h` | Add `ClearIKChains()` method |
| `refactoring/module/tools/tag/mmd_bone.h` | Add `ik_solver_` member |
| `refactoring/module/tools/tag/mmd_bone.cpp` | Sync IK properties in `SetDParameter`, rebuild chains in `HandleBoneModeChange` |
| `refactoring/module/tools/object/mmd_bone_manager.cpp` | Set `ik_solver_` during `LoadPMX` |

## Tasks

- [x] Add `ClearIKChains()` to `MMDIkSolver` (clears `m_chains` vector)
- [x] Add `MMDIkSolver* ik_solver_` member to `MMDBoneTag`
- [x] Set `ik_solver_` in `MMDBoneManagerObject::LoadPMX` alongside `mmd_node_`
- [x] Sync `PMX_BONE_IK_ITERATION` → `SetIterateCount()` in `SetDParameter`
- [x] Sync `PMX_BONE_IK_UNIT_ANGLE` → `SetLimitAngle()` in `SetDParameter`
- [x] Sync `PMX_BONE_IS_IK` → `Enable()` in `SetDParameter`
- [x] Sync `PMX_BONE_IK_TARGET_BONE_INDEX` → `SetTargetNode()` in `SetDParameter` (node lookup via bone manager)
- [x] Implement IK chain rebuild in `HandleBoneModeChange` (edit → other mode)
- [x] Remove `// TODO: Save to mmd_node_` comment
