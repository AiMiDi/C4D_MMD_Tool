## Why

当前 MMD 材质管理系统仅支持标准材质（Standard）的创建与同步，而 `CMTToolsSetting::ModelImport::material_type` 枚举中已预留了 RedShift 和 Octane 材质类型。用户导入 PMX 模型后如需使用第三方渲染器，必须手动重建材质，效率低下。需要为 RS/OC 补齐与标准材质同等程度的简单创建逻辑：设置 diffuse 贴图（含 alpha 通道处理）和 diffuse 纯色。

## What Changes

- 新建 `mmd_redshift_material.h/cpp`，使用 RS 默认材质类型，实现与标准材质等价的简单创建：diffuse 贴图路径 + alpha 通道 + diffuse 纯色，以及 diffuse 颜色同步
- 新建 `mmd_octane_material.h/cpp`，同上，使用 OC 默认材质类型
- 新建 `mmd_corona_material.h/cpp`，同上，使用 Corona 默认材质类型
- 在 `material_type` 枚举中新增 `Corona`，UI 中新增 Corona 选项
- 填充 `LoadPMXMaterial` 中 RS/OC/Corona case 分支
- 集成到创建/同步按钮和 `SetDParameter` 同步分发
- **渲染器未安装时**：`BaseMaterial::Alloc` 返回 nullptr 时弹出 `MessageDialog` 警告用户渲染器未安装，并取消导入流程（`LoadPMXMaterial` 返回 nullptr，上层中止导入）

## Capabilities

### New Capabilities
- `redshift-material`: RS 默认材质的 diffuse 贴图/颜色/alpha 创建与同步
- `octane-material`: OC 默认材质的 diffuse 贴图/颜色/alpha 创建与同步
- `corona-material`: Corona 默认材质的 diffuse 贴图/颜色/alpha 创建与同步
- `renderer-not-installed-warning`: 渲染器未安装时弹窗警告并取消导入
- `reverse-sync`: 从关联的 C4D 材质读取 diffuse 颜色/alpha 回写到 MMD 材质数据
- `default-rs-2024`: C4D 2024+ 版本默认选择 RedShift 渲染器

### Modified Capabilities

## Impact

- 新增文件：`mmd_redshift_material.h/cpp`、`mmd_octane_material.h/cpp`、`mmd_corona_material.h/cpp`
- 修改文件：`mmd_material.cpp`、`mmd_model_manager.cpp`、`cmt_tools_setting.h`、`c4d_symbols.h`、`OMMDModelManager.h/res`、`DLG_CMT_TOOL.res`、各 `.str` 文件、`CMakeLists.txt`
- 不影响现有标准材质功能
