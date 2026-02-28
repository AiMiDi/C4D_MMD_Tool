## ADDED Requirements

### Requirement: RS 材质从 PMX 数据创建（diffuse 贴图 + alpha + 纯色）

系统 SHALL 提供 `CreateRedShiftMaterialFromPMX` 函数，行为与 `CreateStandardMaterialFromPMX` 等价：
- 使用 `BaseMaterial::Alloc(ID_REDSHIFT_MATERIAL)` 分配 RS 默认材质
- 有贴图时：通过 NodeMaterial Graph API 设置 base_color 端口的贴图路径；检测 png/tga alpha 通道并设置 opacity_color
- 无贴图时：设置 base_color 端口默认值为 PMX diffuse RGB；设置 opacity_color 为 diffuse alpha 灰度
- 设置材质名称
- **渲染器未安装时** `BaseMaterial::Alloc` 返回 nullptr，调用 `MessageDialog` 弹窗警告并返回 nullptr

#### Scenario: 有贴图且有 alpha 通道
- **WHEN** PMX 材质指向一个带 alpha 通道的 png 贴图
- **THEN** 创建的 RS 材质 base_color 使用该贴图，opacity_color 也使用该贴图的 alpha

#### Scenario: 无贴图
- **WHEN** PMX 材质无贴图
- **THEN** 创建的 RS 材质 base_color 为 diffuse 纯色，opacity 为 diffuse alpha 值

#### Scenario: RedShift 渲染器未安装
- **WHEN** RedShift 渲染器未安装
- **THEN** `BaseMaterial::Alloc` 返回 nullptr，弹出 MessageDialog 提示 "RedShift 渲染器未安装，无法创建材质"，返回 nullptr 取消导入

### Requirement: RS 材质从 MMDMaterialData 创建

系统 SHALL 提供 `CreateRedShiftMaterialFromData` 函数，从 `MMDMaterialData` 创建 RS 材质（纯色模式，不含贴图）。

#### Scenario: 通过创建材质按钮创建
- **WHEN** 用户点击"创建材质"按钮并选择 RedShift 类型
- **THEN** 创建 RS 默认材质，base_color 为 diffuse 颜色，opacity 为 alpha

### Requirement: RS 材质 diffuse 颜色同步

系统 SHALL 提供 `SyncToRedShiftMaterial` 函数，仅同步 `diffuse_rgb`、`diffuse_alpha` 和 `name_local` 到关联的 RS 材质。

#### Scenario: 修改 diffuse 颜色后自动同步
- **WHEN** 用户修改 MMD 材质的扩散色，且关联材质为 RS 类型
- **THEN** RS 材质的 base_color 默认值更新为新颜色

### Requirement: 导入时 RS case 分支调用

系统 SHALL 在 `LoadPMXMaterial` 的 `RedShift` case 中调用 `CreateRedShiftMaterialFromPMX`。

#### Scenario: PMX 导入选择 RS
- **WHEN** 导入工具选择 RedShift 材质类型
- **THEN** 创建的材质为 RS 默认材质
