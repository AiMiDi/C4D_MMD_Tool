# VMD Motion

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
