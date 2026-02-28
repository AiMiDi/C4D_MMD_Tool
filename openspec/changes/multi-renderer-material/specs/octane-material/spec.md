## ADDED Requirements

### Requirement: OC 材质从 PMX 数据创建（diffuse 贴图 + alpha + 纯色）

系统 SHALL 提供 `CreateOctaneMaterialFromPMX` 函数，行为与 `CreateStandardMaterialFromPMX` 等价：
- 使用 `BaseMaterial::Alloc(ID_OCTANE_DIFFUSE_MATERIAL)` 分配 OC 默认材质
- 有贴图时：分配 `ID_OCTANE_IMAGE_TEXTURE` 着色器设贴图路径，连接到 `OCT_MATERIAL_DIFFUSE_LINK`；检测 png/tga alpha 通道并连接到 `OCT_MATERIAL_OPACITY_LINK`
- 无贴图时：分配 `ID_OCTANE_RGBSPECTRUM` 设 diffuse 颜色连接到 diffuse link；分配 `ID_OCTANE_FLOAT_TEXTURE` 设 alpha 值连接到 opacity link
- 启用 `OCT_MAT_USE_COLOR` 和 `OCT_MAT_USE_OPACITY`
- 设置材质名称
- **渲染器未安装时** `BaseMaterial::Alloc` 返回 nullptr，调用 `MessageDialog` 弹窗警告并返回 nullptr

#### Scenario: 有贴图且有 alpha 通道
- **WHEN** PMX 材质指向一个带 alpha 通道的 png 贴图
- **THEN** 创建的 OC 材质 diffuse 通道使用 ImageTexture 着色器指向该贴图，opacity 也使用该贴图

#### Scenario: 无贴图
- **WHEN** PMX 材质无贴图
- **THEN** 创建的 OC 材质 diffuse 通道使用 RGBSpectrum 设纯色，opacity 使用 FloatTexture 设 alpha 值

#### Scenario: Octane 渲染器未安装
- **WHEN** Octane 渲染器未安装
- **THEN** `BaseMaterial::Alloc` 返回 nullptr，弹出 MessageDialog 提示 "Octane 渲染器未安装，无法创建材质"，返回 nullptr 取消导入

### Requirement: OC 材质从 MMDMaterialData 创建

系统 SHALL 提供 `CreateOctaneMaterialFromData` 函数，从 `MMDMaterialData` 创建 OC 材质（纯色模式，不含贴图）。

#### Scenario: 通过创建材质按钮创建
- **WHEN** 用户点击"创建材质"按钮并选择 Octane 类型
- **THEN** 创建 OC 默认材质，diffuse 为纯色，opacity 为 alpha

### Requirement: OC 材质 diffuse 颜色同步

系统 SHALL 提供 `SyncToOctaneMaterial` 函数，仅同步 `diffuse_rgb`、`diffuse_alpha` 和 `name_local` 到关联的 OC 材质。

#### Scenario: 修改 diffuse 颜色后自动同步
- **WHEN** 用户修改 MMD 材质的扩散色，且关联材质为 OC 类型
- **THEN** OC 材质 diffuse link 的 RGBSpectrum 颜色更新为新值

### Requirement: 导入时 OC case 分支调用

系统 SHALL 在 `LoadPMXMaterial` 的 `Octane` case 中调用 `CreateOctaneMaterialFromPMX`。

#### Scenario: PMX 导入选择 OC
- **WHEN** 导入工具选择 Octane 材质类型
- **THEN** 创建的材质为 OC 默认材质
