# Plugin Infrastructure

## Overview

Plugin entry point, registration, configuration persistence, and scene hook management.

## Entry Point (`main.cpp`)

- `PluginStart()` — Registers all plugins via `cmt_register::RegisterPlugin()`, initializes name conversion and config manager
- `PluginEnd()` — Saves config via `CMTToolConfigManager::SaveConfig()`
- `PluginMessage(C4DPL_INIT_SYS)` — Loads plugin resources

## Plugin Registration (`register_entity.cpp`)

Registers 12 C4D plugins:

| Type | ID | Name | Source |
|------|----|------|--------|
| CommandData | 1056563 | MMDTool | `CMTToolCommand` |
| SceneHookData | 1057017 | CMTSceneManager | `CMTSceneManager` |
| SceneLoaderData | 1057489 | VMD(.vmd) | `VMDLoaderData` |
| ObjectData | 1056724 | MMD Model Manager | `MMDModelManagerObject` |
| ObjectData | 1057944 | MMD Bone Manager | `MMDBoneManagerObject` |
| ObjectData | 1057943 | MMD Mesh Manager | `MMDMeshManagerObject` |
| ObjectData | 1057945 | MMD Rigid Manager | `MMDRigidManagerObject` |
| ObjectData | 1057946 | MMD Joint Manager | `MMDJointManagerObject` |
| ObjectData | 1056722 | MMD Rigid | `MMDRigidObject` |
| ObjectData | 1056723 | MMD Joint | `MMDJointObject` |
| ObjectData | 1056978 | MMD Camera | `MMDCamera` |
| TagData | 1056720 | TMMDBone | `MMDBoneTag` |

Plugin IDs are defined in `plugin_resource.h`. Additionally `g_mmd_vmd_export_id = 1057490` is reserved.

## Scene Hook (`CMTSceneManager`)

- Type: `SceneHookData`
- Central coordinator for all import/export operations
- Maintains `BaseLinkArray SceneCameraArray` for scene-level camera tracking
- Key methods: `LoadPMXModel`, `LoadVMDCamera`, `LoadVMDMotion`, `SaveVMDCamera`, `SaveVMDMotion`, `ConversionCamera`
- Uses log structs (`LoadVmdCameraLog`, `LoadVmdMotionLog`, `LoadModelLog`, etc.) to report results

## Tools Manager (`cmt_tools_manager`)

- High-level import/export API called from UI layer
- Reads files from disk, invokes libMMD parsers, delegates to `CMTSceneManager`
- Functions: `ImportPMXModel`, `ExportPMXModel`, `ImportVMDCamera`, `ExportVMDCamera`, `ConversionCamera`, `ImportVMDMotion`, `ExportVMDMotion`

## Config Manager (`cmt_tools_config_manager`)

- Singleton pattern
- Persists GUI settings to `cmt_config.json` via `utils/json_util.hpp`
- Internal storage: `cmt_json::JsonObject m_config` (`std::unordered_map<std::string, JsonValue>`)
- Config ID range: `DLG_CMT_TOOL_ID_BEGIN` (10000) to `DLG_CMT_TOOL_ID_END`
- API: `GetConfig<T>(id)`, `SetConfig<T>(id, value)`, `InitDialog()`, `SaveConfig()`

## Settings (`cmt_tools_setting.h`)

Typed setting structs under `CMTToolsSetting` namespace:

| Struct | Purpose |
|--------|---------|
| `BaseSetting` | Base: document + filename |
| `CameraImport` | position_multiple, time_offset |
| `CameraExport` | position_multiple, time_offset, use_rotation, use_bake |
| `CameraConversion` | distance, use_rotation, src_cam |
| `MotionImport` | position_multiple, time_offset, import flags (motion/morph/model_info/local_name/physical), delete_previous, detail_report |
| `MotionExport` | position_multiple, time_offset, use_rotation, export flags, use_bake |
| `ModelImport` | position_multiple, import flags (polygon/normal/uv/material/bone/weights/ik/inherit/expression/multipart/english), import_material_type (Standard/RedShift/Octane/Corona) |
| `ModelExport` | position_multiple, export flags |

## SDK Compatibility (`module/core/cmt_marco.h`)

- Version constants: `kSDKVersion`, `kSDK2024`, `kSDK2026`, `kSDKHasIconColorize`, `kSDKHasCinemaNamespace`
- Method signature macros: `CMT_Init`, `CMT_Write`, `CMT_CopyTo`, `CMT_GetDDescription`, `CMT_GetDEnabling` for SDK version differences
- Const-correctness macros: `SDK2024_Const`, `SDK2024_ConstExpr`
- API remapping macros: `ConstDescID`, `CreateDescID`, `GetDynamicDescriptionWritable`, `GetWritableBaseSelect`, `SDK2024_ToPointer`, `SDK2024_Append`, `SDK2024_Move`
- Compatibility helpers: `MakeObjectColorProperties`, `MakeDescIDGeData`, `GetContainerCustomDataType`, `GetCustomDataTypeWritable`
- Namespace compatibility: `CINEMA_NAMESPACE`, `using namespace cinema`
- Type aliases: `MMDModel`, `PMXModel`, `PMDModel`, `MMDModelPtr`, `PMXModelPtr`, `PMDModelPtr`

## Source Directory Convention

### Requirement: Canonical source directory naming
The project SHALL promote the maintained plugin implementation tree to `source/`, and all active plugin build configurations, source discovery rules, and developer documentation MUST treat that directory as the canonical plugin source root.

#### Scenario: Active build references the canonical source tree
- **WHEN** a supported SDK plugin project resolves its source inputs
- **THEN** it reads active plugin code from `source/`
- **AND** it does not require `refactoring/` to remain the canonical source root

### Requirement: Legacy source tree is archived separately
The previous legacy implementation SHALL be preserved under `old/`, and the default build workflow MUST exclude that archived tree from active plugin compilation unless a maintainer explicitly opts into legacy investigation.

#### Scenario: Default build excludes archived legacy code
- **WHEN** a developer runs the documented default plugin build workflow
- **THEN** the build includes the canonical `source/` tree
- **AND** the archived `old/` tree is not compiled as part of the active plugin target

### Requirement: Shared resource mapping remains stable during source migration
Source directory promotion MUST NOT require duplicating plugin resources, and supported SDK builds SHALL continue to resolve the shared active resource tree through a single documented mapping strategy.

#### Scenario: Source migration preserves resource resolution
- **WHEN** the source promotion is completed and a supported SDK build is configured
- **THEN** the build still resolves the shared plugin resource directory through the documented mapping
- **AND** the resource mapping does not depend on the archived legacy source tree

## Source Files

| File | Role |
|------|------|
| `main.cpp` | Plugin entry point |
| `register_entity.h/cpp` | Plugin registration |
| `plugin_resource.h` | Plugin ID constants |
| `CMTSceneManager.h/cpp` | Scene hook (import/export coordinator) |
| `cmt_tools_manager.h/cpp` | High-level import/export API |
| `cmt_tools_config_manager.h/cpp` | JSON config persistence |
| `cmt_tools_setting.h` | Setting structs |
| `module/core/cmt_marco.h` | SDK macros, type aliases |
