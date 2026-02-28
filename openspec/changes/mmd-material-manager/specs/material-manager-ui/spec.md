## ADDED Requirements

### Requirement: 材质管理分组

`MMDModelManagerObject` 的属性管理器 SHALL 新增 `MODEL_MATERIAL_GRP` 分组，用于展示材质管理 UI。该分组 SHALL 在编辑模式下可见。

#### Scenario: 编辑模式下显示材质分组
- **WHEN** 模型处于编辑模式（`MODEL_MODE_EDIT`）时
- **THEN** 属性管理器 SHALL 显示"材质"分组

#### Scenario: 动画模式下材质分组行为
- **WHEN** 模型处于动画模式（`MODEL_MODE_ANIM`）或 VMD 模式时
- **THEN** 材质分组 SHALL 保持可见但属性为只读状态

### Requirement: 材质列表选择器

材质分组 SHALL 包含一个 `LONG` + `CYCLE` 类型的下拉列表 `MODEL_MATERIAL_LIST`，显示所有已加载的材质名称，支持选中当前要编辑的材质。

#### Scenario: 有材质时显示列表
- **WHEN** 模型包含 N 个材质时
- **THEN** 下拉列表 SHALL 包含 N 个选项，每个选项显示 "索引: 材质名称" 格式

#### Scenario: 切换选中材质
- **WHEN** 用户从下拉列表选择另一个材质时
- **THEN** 下方的属性编辑区 SHALL 立即更新为所选材质的属性值

#### Scenario: 无材质时
- **WHEN** 模型不包含任何材质时
- **THEN** 下拉列表 SHALL 显示"-- 无材质 --"，下方属性区域为空或隐藏

### Requirement: 材质链接属性

材质编辑区 SHALL 包含一个 `LINK` 类型属性 `MODEL_MATERIAL_LINK`，显示当前选中材质关联的 C4D `BaseMaterial`。

#### Scenario: 查看关联材质
- **WHEN** 选中一个已关联 C4D 材质的 MMD 材质时
- **THEN** LINK 属性 SHALL 显示对应的 `BaseMaterial` 名称，可点击跳转

#### Scenario: 手动修改材质链接
- **WHEN** 用户将另一个 `BaseMaterial` 拖放到 LINK 属性时
- **THEN** 该 MMD 材质的 `material_link` SHALL 更新为新材质，后续同步操作 SHALL 作用于新材质

### Requirement: 材质名称编辑

材质编辑区 SHALL 包含两个字符串属性：`MODEL_MATERIAL_NAME_LOCAL`（本地名称）和 `MODEL_MATERIAL_NAME_UNIVERSAL`（通用名称）。

#### Scenario: 修改本地名称
- **WHEN** 用户修改本地材质名称时
- **THEN** 对应 `MMDMaterialData` 的 `name_local` SHALL 更新，材质列表中的显示名称 SHALL 同步更新

### Requirement: 材质色编辑

材质编辑区 SHALL 包含以下颜色和数值属性：

| 属性 ID | 类型 | 说明 |
|---------|------|------|
| `MODEL_MATERIAL_DIFFUSE_COLOR` | `COLOR` | 扩散色 RGB |
| `MODEL_MATERIAL_DIFFUSE_ALPHA` | `REAL` | 扩散色 Alpha (非透视率) |
| `MODEL_MATERIAL_SPECULAR_COLOR` | `COLOR` | 反射色 RGB |
| `MODEL_MATERIAL_SPECULAR_POWER` | `REAL` | 反射强度 |
| `MODEL_MATERIAL_AMBIENT_COLOR` | `COLOR` | 环境色 RGB |

#### Scenario: 编辑扩散色
- **WHEN** 用户修改扩散色 RGB 或 Alpha 时
- **THEN** 对应 `MMDMaterialData` 的 `diffuse` 字段 SHALL 更新

#### Scenario: 同步扩散-环境色
- **WHEN** 用户勾选"同步扩散到环境"选项并修改扩散色时
- **THEN** 环境色 SHALL 自动设置为扩散色 RGB × 0.5

### Requirement: 描绘标志编辑

材质编辑区 SHALL 包含以下 `BOOL` 类型属性：

| 属性 ID | 说明 |
|---------|------|
| `MODEL_MATERIAL_DRAW_BOTH_FACE` | 双面描绘 |
| `MODEL_MATERIAL_DRAW_GROUND_SHADOW` | 地面影 |
| `MODEL_MATERIAL_DRAW_CAST_SELF_SHADOW` | 本影标示 |
| `MODEL_MATERIAL_DRAW_RECEIVE_SELF_SHADOW` | 本影 |
| `MODEL_MATERIAL_DRAW_VERTEX_COLOR` | 顶点色 |

#### Scenario: 切换双面描绘
- **WHEN** 用户勾选/取消"双面描绘"复选框时
- **THEN** 对应 `MMDMaterialData` 的 `draw_both_face` SHALL 更新

### Requirement: 轮廓线编辑

材质编辑区 SHALL 包含轮廓线相关属性：

| 属性 ID | 类型 | 说明 |
|---------|------|------|
| `MODEL_MATERIAL_EDGE_ENABLED` | `BOOL` | 轮廓线有效 |
| `MODEL_MATERIAL_EDGE_SIZE` | `REAL` | 轮廓线尺寸 |
| `MODEL_MATERIAL_EDGE_COLOR` | `COLOR` | 轮廓线颜色 RGB |
| `MODEL_MATERIAL_EDGE_ALPHA` | `REAL` | 轮廓线颜色 Alpha |

#### Scenario: 启用轮廓线
- **WHEN** 用户勾选"轮廓线有效"时
- **THEN** 轮廓线尺寸和颜色属性 SHALL 变为可编辑状态

#### Scenario: 禁用轮廓线
- **WHEN** 用户取消"轮廓线有效"时
- **THEN** 轮廓线尺寸和颜色属性 SHALL 变为灰色不可编辑

### Requirement: 纹理信息显示

材质编辑区 SHALL 包含纹理相关属性：

| 属性 ID | 类型 | 说明 |
|---------|------|------|
| `MODEL_MATERIAL_TEXTURE_INDEX` | `LONG` | 纹理索引 |
| `MODEL_MATERIAL_SPHERE_TEXTURE_INDEX` | `LONG` | 高光贴图索引 |
| `MODEL_MATERIAL_SPHERE_MODE` | `LONG` + `CYCLE` | 高光贴图模式（无效/乘算/加算/子纹理） |
| `MODEL_MATERIAL_TOON_MODE` | `LONG` + `CYCLE` | Toon 模式（独立/共用） |
| `MODEL_MATERIAL_TOON_TEXTURE_INDEX` | `LONG` | Toon 纹理索引 |

#### Scenario: 查看纹理索引
- **WHEN** 选中一个材质时
- **THEN** 纹理索引属性 SHALL 显示当前材质的纹理索引值

#### Scenario: 修改高光贴图模式
- **WHEN** 用户从下拉列表选择高光贴图模式时
- **THEN** 对应 `MMDMaterialData` 的 `sphere_mode` SHALL 更新

### Requirement: 备注和面数显示

材质编辑区 SHALL 包含：
- `MODEL_MATERIAL_MEMO`（`STRING` + `MULTISTRING`）：备注文本，可编辑
- `MODEL_MATERIAL_FACE_COUNT`（`LONG`，只读）：面数

#### Scenario: 查看面数
- **WHEN** 选中一个材质时
- **THEN** 面数属性 SHALL 显示该材质对应的三角面数（`num_face_vertices / 3`），且该属性不可编辑

### Requirement: 创建材质按钮和类型选择

材质编辑区 SHALL 包含：
- `MODEL_MATERIAL_CREATE_TYPE`（`LONG` + `CYCLE`）：选择创建的材质类型（标准材质/RedShift/Octane）
- `MODEL_MATERIAL_CREATE_BUTTON`（`BUTTON`）：从当前 MMD 材质属性创建新的 C4D 材质

#### Scenario: 创建标准材质
- **WHEN** 用户选择"标准材质"并点击"创建材质"按钮时
- **THEN** 系统 SHALL 根据当前 `MMDMaterialData` 的属性创建一个新的 C4D 标准材质，将其插入到文档的材质列表中，并将 `material_link` 更新为该新材质

#### Scenario: 已存在关联材质时创建
- **WHEN** 当前材质已有关联的 C4D 材质且用户点击"创建材质"时
- **THEN** 系统 SHALL 创建新材质并替换 `material_link`，原有材质不被删除（用户可手动删除）

#### Scenario: 未选中材质时按钮不可用
- **WHEN** 未选中任何材质时
- **THEN** 创建材质按钮 SHALL 为灰色不可点击

### Requirement: 同步材质按钮

材质编辑区 SHALL 包含 `MODEL_MATERIAL_SYNC_BUTTON`（`BUTTON`），用于将当前 MMD 材质属性手动同步到关联的 C4D 材质。

#### Scenario: 手动同步材质
- **WHEN** 用户点击"同步材质"按钮时
- **THEN** 系统 SHALL 将当前选中 `MMDMaterialData` 的所有属性同步到 `material_link` 关联的 C4D 材质

#### Scenario: 无关联材质时同步
- **WHEN** `material_link` 为空时用户点击"同步材质"
- **THEN** 不执行任何操作，不产生错误

### Requirement: 导入工具材质类型选择

导入工具对话框（`DLG_CMT_TOOL`）的模型导入设置区域 SHALL 新增一个 `COMBOBOX` 控件 `DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL_TYPE`，允许用户选择导入时创建的 C4D 材质类型。

#### Scenario: 选择标准材质导入
- **WHEN** 用户在导入对话框选择"标准材质"并导入 PMX 文件时
- **THEN** 导入流程 SHALL 使用 `CMTToolsSetting::ModelImport::material_type::Standard` 创建材质

#### Scenario: 默认选择标准材质
- **WHEN** 导入对话框初始化时
- **THEN** 材质类型下拉框 SHALL 默认选中"标准材质"
