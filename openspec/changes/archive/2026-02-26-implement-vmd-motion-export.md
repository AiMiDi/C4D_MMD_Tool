# Implement VMD Motion Export

## Summary

Implemented the full `ExportVMDMotion` pipeline, enabling users to export the active VMDAnimation from a selected MMD model to a `.vmd` file. Previously, the export button and all backend functions were stubbed out. Now the complete data flow from UI button click through to file writing is functional.

## Motivation

- The VMD motion import pipeline was fully implemented, but the export path was empty stubs returning `true`/`false` with no logic.
- Users had no way to save modified or merged VMD animations back to disk from the plugin.
- The underlying `VMDAnimation::Save(VMDFile&)` in libMMD was already implemented, so the plugin-side wiring was the remaining gap.

## Changes

### Data Flow

```
DLG_CMT_TOOL_MOTION_EXPORT_BUTTON (UI)
    → CMTToolsManager::ExportVMDMotion(MotionExport)
        → CMTSceneManager::SaveVMDMotion()
            → MMDModelManagerObject::SaveVMDMotion()
                → VMDAnimation::Save(VMDFile&)
        → WriteVMDFile() to disk
        → Log statistics (bone count, morph count, frame count, timing)
```

### Plugin Logic (refactoring/)

| File | Change |
|------|--------|
| `cmt_tools_manager.cpp` | Implemented `ExportVMDMotion`: calls `SaveVMDMotion`, writes file via `WriteVMDFile`, collects statistics from the resulting `VMDFile` (unique bone/morph names, total keyframe count) |
| `CMTSceneManager.h` | Added `SaveVmdMotionLog` fields (`exported_bone_count`, `exported_morph_count`, `exported_frame_count`) and methods (`LogOK`, `LogSelectError`, `LogNotMMDModelError`, `LogNoAnimationError`) |
| `CMTSceneManager.cpp` | Implemented `SaveVMDMotion`: gets active object, validates it is `MMDModelManagerObject`, delegates to its `SaveVMDMotion`. Implemented all `SaveVmdMotionLog` methods |
| `module/tools/object/mmd_model_manager.cpp` | Implemented `MMDModelManagerObject::SaveVMDMotion`: reads `animations_[animation_index_]` and calls `VMDAnimation::Save(VMDFile&)` |
| `module/ui/cmt_tools_dialog.cpp` | Completed `DLG_CMT_TOOL_MOTION_EXPORT_BUTTON` handler: added `use_bake` read, `position_multiple` inversion, file save dialog, and `ExportVMDMotion` call |

### UI Resources (res/S24_up/)

| File | Change |
|------|--------|
| `c4d_symbols.h` | Added `IDS_MES_EXPORT_MOT_TYPE_ERR`, `IDS_MES_EXPORT_MOT_NO_ANIM`, `IDS_MES_EXPORT_MOT_OK` |
| `strings_en-US/c4d_strings.str` | Added English strings for the three new message IDs |
| `strings_zh-CN/c4d_strings.str` | Added Chinese strings for the three new message IDs |

No changes to `DLG_CMT_TOOL.res` — the motion export dialog layout was already fully defined.

### Error Handling

Follows the same pattern as `ImportVMDMotion` / `ExportVMDCamera`:

| Condition | Handler |
|-----------|---------|
| No object selected | `SaveVmdMotionLog::LogSelectError()` — shows "Export failed: Please select an object" |
| Selected object is not MMD model | `SaveVmdMotionLog::LogNotMMDModelError()` — shows "Export failed: Please select an MMD model object" |
| No active animation (invalid index) | `SaveVmdMotionLog::LogNoAnimationError()` — shows "Export failed: No active animation to export" |
| File write failure | `IOLog::LogWriteFileErr()` — shows "Export failed: Cannot write file" |
| Success | `SaveVmdMotionLog::LogOK()` — shows exported bone count, morph count, frame count, and elapsed time |

## Affected Specs

- **vmd-motion**: Export pipeline is now fully implemented matching the spec's documented flow.
