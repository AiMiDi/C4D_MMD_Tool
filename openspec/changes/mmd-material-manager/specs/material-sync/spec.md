## ADDED Requirements

### Requirement: 扩散色同步到 C4D 材质

当用户修改 MMD 材质的扩散色时，系统 SHALL 自动将变更同步到关联的 C4D `BaseMaterial`。

#### Scenario: 修改扩散色 RGB
- **WHEN** 用户修改 `MODEL_MATERIAL_DIFFUSE_COLOR` 的 RGB 值时
- **THEN** 关联 C4D 标准材质的颜色通道（`MATERIAL_COLOR_COLOR`）SHALL 更新为对应的 RGB 值

#### Scenario: 修改扩散色 Alpha
- **WHEN** 用户修改 `MODEL_MATERIAL_DIFFUSE_ALPHA` 时
- **THEN** 关联 C4D 标准材质的 Alpha 通道的亮度 SHALL 更新为对应值

#### Scenario: 无关联材质时修改不同步
- **WHEN** `material_link` 指向的材质不存在或为 `nullptr` 时
- **THEN** 修改 SHALL 仅保存到 `MMDMaterialData`，不触发同步操作，不产生错误

### Requirement: 反射色同步到 C4D 材质

当用户修改 MMD 材质的反射色和反射强度时，系统 SHALL 自动同步到关联的 C4D 材质。

#### Scenario: 修改反射色
- **WHEN** 用户修改 `MODEL_MATERIAL_SPECULAR_COLOR` 和 `MODEL_MATERIAL_SPECULAR_POWER` 时
- **THEN** 关联 C4D 标准材质的反射通道颜色和反射通道的宽度 SHALL 更新

### Requirement: PMX 导入时填充材质数据

PMX 导入流程 SHALL 在创建 C4D 材质的同时填充 `MMDModelManagerObject` 的材质列表。

#### Scenario: 导入包含材质的 PMX 文件
- **WHEN** 导入一个包含 N 个材质的 PMX 文件时
- **THEN** `MMDModelManagerObject` 的材质列表 SHALL 包含 N 个 `MMDMaterialData` 条目，每个条目的 `material_link` SHALL 指向对应的已创建 C4D `BaseMaterial`，所有 PMX 材质属性 SHALL 完整映射

#### Scenario: 导入设置中禁用材质导入
- **WHEN** 导入设置中 `import_material` 为 false 时
- **THEN** 材质列表 SHALL 仍然填充 MMD 材质数据（属性值），但 `material_link` SHALL 为空

### Requirement: PMX 导出时读取材质数据

PMX 导出流程 SHALL 从 `MMDModelManagerObject` 的材质列表中读取完整的 MMD 材质参数。

#### Scenario: 导出材质属性
- **WHEN** 导出 PMX 文件时
- **THEN** 每个材质的所有 PMX 属性（扩散色、反射色、环境色、描绘标志、轮廓线、纹理索引、高光模式、Toon 设置、备注等）SHALL 从 `MMDMaterialData` 完整写入到 `PMXMaterial`

### Requirement: 材质名称同步

当用户修改 MMD 材质名称时，系统 SHALL 将名称变更同步到关联的 C4D 材质。

#### Scenario: 修改本地名称
- **WHEN** 用户修改 `MODEL_MATERIAL_NAME_LOCAL` 时
- **THEN** 关联 C4D 材质的 `SetName()` SHALL 被调用，C4D 材质管理器中显示的名称 SHALL 更新

### Requirement: 手动同步按钮触发完整同步

当用户点击同步按钮时，系统 SHALL 将当前 `MMDMaterialData` 的所有属性完整同步到关联的 C4D 材质，效果等同于逐个修改所有属性后的自动同步总和。

#### Scenario: 点击同步按钮
- **WHEN** 用户点击 `MODEL_MATERIAL_SYNC_BUTTON` 时
- **THEN** 系统 SHALL 调用 `SyncToStandardMaterial`（或对应渲染器的同步函数），将扩散色、Alpha、反射色、反射强度、材质名称等全部推送到关联材质

### Requirement: 创建材质并更新 Link

当用户点击创建材质按钮时，系统 SHALL 根据选择的材质类型和当前 `MMDMaterialData` 创建新的 C4D 材质。

#### Scenario: 创建标准材质并更新 link
- **WHEN** 用户选择标准材质类型并点击创建按钮时
- **THEN** 系统 SHALL 创建 C4D 标准材质，设置扩散色/纹理/Alpha 等属性，将其插入到文档材质列表，并将 `material_link` 设置为该新材质
