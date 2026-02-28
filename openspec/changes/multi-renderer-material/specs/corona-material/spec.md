## ADDED Requirements

### Requirement: Corona 材质从 PMX 数据创建（diffuse 贴图 + alpha + 纯色）

系统 SHALL 提供 `CreateCoronaMaterialFromPMX` 函数，行为与 `CreateStandardMaterialFromPMX` 等价：
- 使用 `BaseMaterial::Alloc(ID_CORONA_MATERIAL)` 分配 Corona 默认材质
- 有贴图时：分配 `ID_CORONA_BITMAP` 着色器设 `CORONA_BITMAP_FILENAME` 为贴图路径，通过 `BaseLink` 连接到 `CORONA_DIFFUSE_TEXTURE`；检测 png/tga alpha 通道，启用 `CORONA_MATERIAL_ALPHA` 并连接到 `CORONA_ALPHA_TEXTURE`
- 无贴图时：设 `CORONA_DIFFUSE_COLOR` 为 PMX diffuse 颜色；设 `CORONA_ALPHA_COLOR` + `CORONA_ALPHA_COLOR_LEVEL` 为 alpha 灰度
- 启用 `CORONA_MATERIAL_DIFFUSE`
- 设置材质名称
- **渲染器未安装时** `BaseMaterial::Alloc` 返回 nullptr，调用 `MessageDialog` 弹窗警告并返回 nullptr

#### Scenario: 有贴图且有 alpha 通道
- **WHEN** PMX 材质指向一个带 alpha 通道的 png 贴图
- **THEN** 创建的 Corona 材质 diffuse 通道使用 CoronaBitmap 着色器指向该贴图，alpha 通道也使用该贴图

#### Scenario: 无贴图
- **WHEN** PMX 材质无贴图
- **THEN** 创建的 Corona 材质 diffuse 通道使用纯色，alpha 使用灰度值

#### Scenario: Corona 渲染器未安装
- **WHEN** Corona 渲染器未安装
- **THEN** `BaseMaterial::Alloc` 返回 nullptr，弹出 MessageDialog 提示 "Corona 渲染器未安装，无法创建材质"，返回 nullptr 取消导入

### Requirement: Corona 材质从 MMDMaterialData 创建

系统 SHALL 提供 `CreateCoronaMaterialFromData` 函数，从 `MMDMaterialData` 创建 Corona 材质（纯色模式，不含贴图）。

#### Scenario: 通过创建材质按钮创建
- **WHEN** 用户点击"创建材质"按钮并选择 Corona 类型
- **THEN** 创建 Corona 默认材质，diffuse 为纯色，alpha 为 diffuse_alpha

### Requirement: Corona 材质 diffuse 颜色同步

系统 SHALL 提供 `SyncToCoronaMaterial` 函数，仅同步 `diffuse_rgb`、`diffuse_alpha` 和 `name_local` 到关联的 Corona 材质。

#### Scenario: 修改 diffuse 颜色后同步
- **WHEN** 用户修改 MMD 材质的扩散色，且关联材质为 Corona 类型
- **THEN** Corona 材质 `CORONA_DIFFUSE_COLOR` 更新为新值

### Requirement: 导入时 Corona case 分支调用

系统 SHALL 在 `LoadPMXMaterial` 的 `Corona` case 中调用 `CreateCoronaMaterialFromPMX`。

#### Scenario: PMX 导入选择 Corona
- **WHEN** 导入工具选择 Corona 材质类型
- **THEN** 创建的材质为 Corona 默认材质
