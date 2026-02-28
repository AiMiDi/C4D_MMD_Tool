## Why

PMX 导入时大量数据被丢弃且未暴露到属性管理器（Attribute Manager），包括顶点的 SDEF/轮廓倍率、骨骼的付与亲 L/外部亲/亲Key、表情变换材质/冲量变形、表情 panel 分类以及表示框。这些数据对于模型的完整保存与后续导出回 PMX 至关重要，缺失会导致导出时信息丢失、无法还原原始 PMX 模型。同时，现有属性管理器参数的命名需与 PMXEditor 对齐，日语/繁体汉字统一为简体中文。

## What Changes

- **骨骼 Tag（TMMDBone）**：新增「付与亲 L」（0x0080）、「外部亲」（0x2000）、「亲Key」的描述参数与导入逻辑。
- **模型管理器（OMMDModelManager）**：新增表示框（Display Frame）的存储与 UI 展示；新增表情变换材质（Material Morph）和冲量变形（Impulse Morph）的 Group 参数与导入逻辑；新增表情 panel 分类（眉/目/口/其他）的存储。
- **网格管理器 / 顶点数据**：在 Tag 或自定义数据中新增逐顶点轮廓倍率（edgeMag）的存储。SDEF 参数（C/R0/R1）作为逐顶点数据，需评估存储方式（BaseTag 或变量 Tag）。
- **现有参数重命名**：将 TMMDBone 的中文显示名称与 PMXEditor 对齐（如「骨骼特性」→「性能」、「骨骼末端指向」→「表示先」等）。
- **资源文件（res/S24_up/）**：修改 `TMMDBone.h/.res`、`OMMDModelManager.h/.res`，可能新增描述文件。
- **导入代码**：修改 `mmd_bone_manager.cpp`、`mmd_model_manager.cpp`、`mmd_mesh_manager.cpp` 等，在 LoadPMX 时填充新增参数。

## Capabilities

### New Capabilities

- `pmx-missing-params`：将 PMX 导入时当前丢弃的数据（SDEF/轮廓倍率、付与亲 L/外部亲/亲Key、表情变换材质/冲量变形、表情 panel 分类、表示框）保存到 C4D 属性管理器的参数中，使其可在 UI 上查看，并为后续导出回 PMX 保留数据。同时将现有参数命名与 PMXEditor 对齐。

### Modified Capabilities

- `model-import`：PMX 导入管线需写入新增的参数字段。

## Impact

- **资源文件**：`res/S24_up/description/TMMDBone.h`、`TMMDBone.res`、`OMMDModelManager.h`、`OMMDModelManager.res`，可能新增 `.h/.res` 文件。
- **代码**：`refactoring/module/tools/tag/mmd_bone.cpp`（骨骼标志导入）、`refactoring/module/tools/object/mmd_model_manager.cpp`（显示枠/材质变形/冲击变形/表情分类）、`refactoring/module/tools/object/mmd_mesh_manager.cpp`（edgeMag/SDEF 顶点数据）。
- **依赖**：仅使用 libMMD 已有的 PMXFile 结构，无新增外部依赖。

