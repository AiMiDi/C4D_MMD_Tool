# VMD Camera

## Purpose

Import, export, and convert VMD (Vocaloid Motion Data) camera animations. VMD camera data includes position, rotation, distance, FOV keyframes with bezier interpolation.

## Requirements

### Requirement: VMD camera import
The system SHALL import VMD camera animation data from the main dialog or VMD scene loader and create an `MMDCamera` object with C4D animation tracks.

#### Scenario: Import camera VMD
- **WHEN** a user imports a camera VMD file
- **THEN** the system SHALL parse the VMD camera animation, create an MMD camera object, and write position, rotation, distance, and FOV keyframes to C4D tracks

### Requirement: VMD camera export
The system SHALL export camera animation through `CMTToolsManager::ExportVMDCamera()` and `CMTSceneManager::SaveVMDCamera()` using the configured scale, offset, rotation mode, and bake settings.

#### Scenario: Export camera VMD
- **WHEN** a user exports camera animation
- **THEN** the system SHALL write a VMD camera file using the configured export settings

### Requirement: Camera conversion
The system SHALL convert between MMD-style distance-based cameras and standard Cinema 4D cameras using `CameraConversion` settings.

#### Scenario: Convert camera
- **WHEN** camera conversion is requested with a source camera
- **THEN** the system SHALL create or update the converted camera representation using the configured distance and rotation mode

### Requirement: VMD loader camera detection
The VMD scene loader SHALL identify VMD files and route camera VMD data to the camera import dialog while rejecting unsupported motion VMD loading through that loader.

#### Scenario: Loader receives VMD file
- **WHEN** Cinema 4D opens a `.vmd` file through the scene loader
- **THEN** the loader SHALL distinguish camera VMD from motion VMD and only continue with the camera import path for camera files

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
