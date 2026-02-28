## Why

当前 PMX 模型导入后，材质仅作为 C4D 原生材质插入到文档中，缺少与 MMD 材质属性的持久化关联。用户无法在 C4D 属性管理器中直接查看和编辑 MMD 特有的材质参数（如描绘标志、轮廓线/边缘设置、Toon 纹理、高光贴图模式等），也无法将这些修改同步回 C4D 材质或在 PMX 导出时保留完整的 MMD 材质信息。需要一个类似骨骼管理器/网格管理器模式的材质管理系统，在 MMDModelManagerObject 的属性管理器中提供完整的 MMD 材质管理 UI。

## What Changes

- 在 `MMDModelManagerObject` 的属性管理器中新增**材质管理** UI 分组，包含：
  - 材质列表（可选中当前编辑的材质）
  - 选中材质的 Link 属性（指向 C4D 文档中对应的 `BaseMaterial`）
  - 完整的 MMD 材质属性编辑区（参照 PMX Editor 界面）：
    - 材质名称（本地/通用）
    - 材质色（扩散色 RGBA、反射色 RGB、环境色 RGB、反射强度/非透视率）
    - 描绘标志（双面描绘、地面影、本影标示、本影、顶点色）
    - 轮廓线（有效、尺寸、颜色 RGBA）
    - 材质纹理（Tex 路径、Toon 纹理、高光贴图及模式选择）
    - 备注（Memo）
    - 面数（只读）
- 将现有 `MMDMaterialManager` 从纯导入辅助类重构为持久化数据管理器，在模型对象上存储每个材质的 MMD 属性数据
- 材质属性修改时自动同步到关联的 C4D 材质（扩散色、Alpha、高光等）
- PMX 导入时自动填充材质管理器数据
- PMX 导出时从材质管理器读取完整的 MMD 材质参数
- 导入工具对话框（`DLG_CMT_TOOL`）新增**转换材质类型**下拉框，允许用户选择导入时创建的材质类型（标准/RedShift/Octane），当前默认且仅支持标准材质
- MMD 材质管理界面新增**创建材质**按钮和转换材质类型下拉框，支持从当前 MMD 材质属性创建新的 C4D 材质并自动更新 `material_link`
- MMD 材质管理界面新增**同步材质**按钮，将当前 UI 上的 MMD 材质属性手动同步到 `material_link` 关联的 C4D 材质

## Capabilities

### New Capabilities

- `material-data-model`: MMD 材质数据的持久化存储模型，包括 Read/Write/CopyTo 序列化、材质列表管理、与 C4D 材质的 BaseLink 关联
- `material-manager-ui`: 在 MMDModelManagerObject 属性管理器中的材质管理 UI，包括材质列表选择、属性编辑区、动态描述系统
- `material-sync`: 材质属性修改到 C4D 材质的同步逻辑，以及 PMX 导入/导出时的数据转换

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **修改文件**: `MMDModelManagerObject` 类（新增材质管理成员和方法）、`MMDMaterialManager` 类（重构为持久化管理器）、`MMDMeshManagerObject`（导入时需与材质管理器协作）
- **新增资源文件**: `OMMDModelManager.res/.h/.str` 需要新增材质相关的描述 ID 和 UI 定义
- **依赖**: 仅使用现有的 libMMD（`PMXMaterial` 结构体）和 C4D SDK，无新增外部依赖
- **兼容性**: 需要处理旧版本项目文件的向后兼容（Read 中检测材质数据是否存在）
