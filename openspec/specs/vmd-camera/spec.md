# VMD Camera

## Overview

Import, export, and convert VMD (Vocaloid Motion Data) camera animations. VMD camera data includes position, rotation, distance, FOV keyframes with bezier interpolation.

## Import

### Entry Points

1. **Main dialog** — User clicks import in CMTToolDialog → `CMTToolsManager::ImportVMDCamera(CameraImport)`
2. **Scene loader** — C4D opens a `.vmd` file → `VMDLoaderData::Load()` → if camera VMD, opens `VMDLoaderCameraDialog`

### Pipeline

```
VMD file → libmmd::ReadVMDFile() → VMDFile
    → VMDCameraAnimation::Create(vmd_file)
    → CMTSceneManager::LoadVMDCamera()
        → Creates MMDCamera object
        → Writes keyframes to C4D animation tracks
```

### Settings (`CameraImport`)

| Option | Default | Description |
|--------|---------|-------------|
| `position_multiple` | 8.5 | Position scale factor (MMD units → C4D units) |
| `time_offset` | 0 | Frame offset for animation |

## Export

`CMTToolsManager::ExportVMDCamera(CameraExport)` → `CMTSceneManager::SaveVMDCamera()`

### Settings (`CameraExport`)

| Option | Default | Description |
|--------|---------|-------------|
| `position_multiple` | 8.5 | Position scale factor |
| `time_offset` | 0 | Frame offset |
| `use_rotation` | 0 | Rotation conversion mode |
| `use_bake` | true | Bake animation before export |

## Camera Conversion

Converts between MMD-style camera (distance-based orbit) and standard C4D camera.

`CMTToolsManager::ConversionCamera(CameraConversion)` → `CMTSceneManager::ConversionCamera()`

### Settings (`CameraConversion`)

| Option | Default | Description |
|--------|---------|-------------|
| `distance` | 0 | Camera distance |
| `use_rotation` | 0 | Rotation mode |
| `src_cam` | nullptr | Source camera object |

## VMD Loader (`vmd_loader`)

- Type: `SceneLoaderData` (ID: 1057489)
- `Identify()` — detects VMD file format; distinguishes camera VMD from motion VMD by model name field
- `Load()` — only supports camera VMD; non-camera VMD files produce an error message
- Camera VMD opens `VMDLoaderCameraDialog` for import settings

## Source Files

| File | Role |
|------|------|
| `cmt_tools_manager.cpp` | Import/Export/Conversion entry points |
| `CMTSceneManager.cpp` | Load/Save/Convert camera logic |
| `module/tools/object/mmd_camera.h/cpp` | MMDCamera ObjectData |
| `module/tools/loader/vmd_loader.h/cpp` | SceneLoaderData for .vmd |
| `module/ui/vmd_loader_camera_dialog.h/cpp` | Import dialog |
