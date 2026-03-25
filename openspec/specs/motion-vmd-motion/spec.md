# VMD Motion

## Purpose

Import and export VMD motion animations for MMD models. Motion data includes bone keyframes and morph keyframes, applied to an existing `MMDModelManagerObject` in the scene.
## Requirements
### Requirement: VMD morph animation playback mechanism

In VMD mode, morph animation playback SHALL be driven by C4D's CTrack system instead of per-frame reads from libMMD's morph weight output. The `MMDMeshManagerObject` SHALL NOT read morph weights from `libmmd::MorphManager` during VMD mode execution. Instead, morph strength values come from C4D parameters (set by CTrack evaluation), and `UpdateMorph()` dispatches them to mesh/bone managers through existing paths (`SetMorphStrength`, bone morph hubs).

#### Scenario: Mesh morph strength comes from CTrack in VMD mode
- **WHEN** the model is in `MODEL_MODE_VMD` and a mesh morph has CTrack keyframes
- **THEN** `MMDMeshManagerObject::Execute()` does NOT read morph weights from `mmd_morph_manager_`
- **THEN** mesh morph strength is applied through `MeshMorph::UpdateMorph()` → `SetMorphStrength()` using the CTrack-driven parameter value

#### Scenario: Bone morph still works via libMMD node transforms
- **WHEN** the model is in `MODEL_MODE_VMD` and bone morphs exist
- **THEN** libMMD's `VMDAnimation::Evaluate()` still sets bone morph weights internally
- **THEN** `UpdateMorphAnimation()` applies bone morph effects to `mmd_node_` transforms
- **THEN** `MMDBoneTag` reads correct transforms from `mmd_node_` including bone morph effects

### Requirement: Remove VMD morph weight reading from MeshManager

The `MMDMeshManagerObject` SHALL NOT maintain `morph_manager_index_` or `mmd_morph_manager_` members. The `MESH_MODE_VMD` morph weight reading loop in `Execute()` SHALL be removed.

#### Scenario: MeshManager Execute in VMD mode
- **WHEN** `MMDMeshManagerObject::Execute()` runs in `MESH_MODE_VMD`
- **THEN** no morph weight reading from libMMD's `MorphManager` occurs
- **THEN** morph strength is applied solely through the `SetMorphStrength()` path called by `UpdateMorph()`

### Requirement: Report unmatched VMD morph names

The VMD import pipeline SHALL record morph names from the VMD file that do not match any morph in the target model's `morph_name_` map, and include them in the import log report.

#### Scenario: Import report includes unmatched morph names
- **WHEN** a VMD file is imported and some morph names cannot be matched
- **THEN** `LoadVmdMotionLog::not_find_morph_name_list` contains the unmatched morph names
- **THEN** the import report dialog displays these names when `detail_report` is enabled

## Overview

Import and export VMD motion animations for MMD models. Motion data includes bone keyframes and morph keyframes, applied to an existing MMDModelManagerObject in the scene.

## Import

### Prerequisite

A `MMDModelManagerObject` must be selected in the scene. Motion is applied to the model's bone and morph systems.

### Pipeline

```
VMD file → libmmd::ReadVMDFile() → VMDFile
    → CMTToolsManager::ImportVMDMotion(MotionImport)
        → CMTSceneManager::LoadVMDMotion()
            → MMDModelManagerObject::LoadVMDMotion()
                → Creates libmmd::VMDAnimation
                → Stores in animations_ array
                → Execute() drives playback + physics
```

### Settings (`MotionImport`)

| Option | Default | Description |
|--------|---------|-------------|
| `position_multiple` | 8.5 | Position scale factor |
| `time_offset` | 0 | Frame offset |
| `import_motion` | true | Import bone keyframes |
| `import_morph` | true | Import morph keyframes |
| `import_model_info` | true | Import model info (visibility, IK states) |
| `import_by_local_name` | true | Match bones by local (Japanese) name |
| `ignore_physical` | true | Skip physical bone animations |
| `delete_previous_animation` | true | Remove existing animation before import |
| `detail_report` | false | Show detailed import report |

## Export

`CMTToolsManager::ExportVMDMotion(MotionExport)` → `CMTSceneManager::SaveVMDMotion()`

### Settings (`MotionExport`)

| Option | Default | Description |
|--------|---------|-------------|
| `position_multiple` | 8.5 | Position scale factor |
| `time_offset` | 0 | Frame offset |
| `use_rotation` | 0 | Rotation conversion mode |
| `export_motion` | true | Export bone keyframes |
| `export_morph` | true | Export morph keyframes |
| `export_model_info` | true | Export model info |
| `use_bake` | true | Bake animation before export |

## Animation Storage & Persistence

`MMDModelManagerObject` stores `animations_` array of VMD animations. Animation data is persisted across scene save/reload cycles, restoring to the same state after reload.

### Save-Reload-Playback Cycle

- On save: `Write()` serializes animation count, names, and VMD binary data (via `VMDAnimation::Save(VMDFile&)` + `WriteVMDFile()`) to HyperFile
- On reload: `Read()` deserializes VMD binary data into temporary buffer (`pending_vmd_data_`)
- On first `Execute()`: `RebuildRuntime()` restores `VMDAnimation` objects from pending data, then releases buffer
- After restore: `animation_index_` and `animation_items_` are correctly restored; animations play as before save

### VMD Binary Data Staging

During `Read()`, VMD binary data is staged in `pending_vmd_data_` until runtime rebuild completes. The buffer is released after successful or failed rebuild.

## Animation Playback

`MMDModelManagerObject::Execute()` evaluates VMD animations each frame:
1. Calls `libmmd::VMDAnimation::Evaluate()` for current frame
2. libMMD resolves IK, inheritance, physics via bullet3
3. Bone transforms are pushed to C4D joints via `MMDBoneTag`

### Coordinate Conversion (MMD → C4D)

libMMD outputs transforms in original PMX space (left-handed, Z+ into screen). C4D is also left-handed but with Z+ toward viewer. `MMDBoneTag::Execute` applies:

- **Position delta**: Used directly (mesh, frozen positions, and deltas all share original PMX space).
- **Rotation matrix**: Converted via `S*R*S` (`S=diag(1,1,-1)`) to flip X/Y rotation directions.

## Source Files

| File | Role |
|------|------|
| `cmt_tools_manager.cpp` | Import/Export entry points |
| `CMTSceneManager.cpp` | Load/Save motion logic |
| `module/tools/object/mmd_model_manager.cpp` | Animation storage + Execute() |
| `module/tools/tag/mmd_bone.cpp` | Bone transform application |
