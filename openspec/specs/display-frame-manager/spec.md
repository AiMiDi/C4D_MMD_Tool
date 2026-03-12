## ADDED Requirements

### Requirement: 表示框数据模型

系统 SHALL 定义 `DisplayFrameData` 结构体，包含以下字段：
- `name`（String）：帧组名称
- `name_universal`（String）：帧组英文名称
- `frame_type`（枚举）：DefaultFrame / SpecialFrame
- `targets`（BaseArray）：条目列表，每个条目包含类型（Bone/Morph）和目标索引（Int32）

系统 SHALL 在 `MMDModelManagerObject` 中以 `maxon::BaseArray<DisplayFrameData>` 存储所有表示框数据。

#### Scenario: PMX 导入后数据模型填充
- **WHEN** 用户导入 PMX 文件，且文件包含表示框数据
- **THEN** 系统 SHALL 将每个 `PMXDisplayFrame` 转换为 `DisplayFrameData` 并存储到列表中，保留帧组名称、类型标志和所有条目的类型及索引

#### Scenario: 空表示框列表
- **WHEN** 用户导入的 PMX 文件不包含表示框
- **THEN** 表示框列表 SHALL 为空，UI 不显示任何帧组

### Requirement: 表示框序列化

系统 SHALL 实现表示框数据的 Read/Write/CopyTo 方法，确保项目保存、加载和复制时完整保留表示框数据。

#### Scenario: 项目保存后重新打开
- **WHEN** 用户保存包含已编辑表示框的项目文件并重新打开
- **THEN** 所有表示框数据（帧组名称、条目列表）SHALL 与保存前完全一致

#### Scenario: 向后兼容旧版本文件
- **WHEN** 用户打开不包含表示框数据的旧版本项目文件
- **THEN** 系统 SHALL 正常加载，表示框列表为空，不产生错误

### Requirement: 表示框 UI——帧组选择

系统 SHALL 在 `MMDModelManagerObject` 的"表示框"Tab 中提供 `LONG` + `CYCLE` 下拉列表，列出所有帧组名称供用户选择当前编辑的帧组。

#### Scenario: 选择帧组
- **WHEN** 用户在下拉列表中选择一个帧组
- **THEN** 下方属性区 SHALL 显示该帧组的名称编辑框和所有条目列表

#### Scenario: 帧组列表为空
- **WHEN** 表示框数据为空
- **THEN** 下拉列表 SHALL 显示占位提示，所有编辑控件 SHALL 为禁用状态

### Requirement: 帧组名称编辑

系统 SHALL 提供 STRING 类型的属性控件，显示当前选中帧组的本地名称和通用名称，用户可直接编辑。

#### Scenario: 修改帧组名称
- **WHEN** 用户修改帧组名称字段
- **THEN** 系统 SHALL 更新对应 `DisplayFrameData` 的 `name` 字段，并同步更新 CYCLE 下拉列表中的显示文本

### Requirement: 条目列表展示

选中帧组后，系统 SHALL 以动态描述展示该帧组的所有条目。每个条目 SHALL 显示为一行，包含：
- 类型标签（`[Bone]` 或 `[Morph]`）
- 目标名称（从骨骼或形变列表中查找索引对应的名称）

#### Scenario: 显示骨骼条目
- **WHEN** 帧组包含类型为 BoneIndex、索引为 N 的条目
- **THEN** 该条目行 SHALL 显示 `[Bone]` 和第 N 个骨骼的名称

#### Scenario: 显示形变条目
- **WHEN** 帧组包含类型为 MorphIndex、索引为 N 的条目
- **THEN** 该条目行 SHALL 显示 `[Morph]` 和第 N 个形变的名称

#### Scenario: 索引无效
- **WHEN** 条目的目标索引超出当前骨骼或形变列表范围
- **THEN** 该条目 SHALL 显示索引数字作为名称

### Requirement: 添加条目

系统 SHALL 在帧组编辑区域提供添加条目功能：
- 类型选择控件（CYCLE：骨骼/形变）
- 目标选择控件（CYCLE：动态填充当前模型的骨骼或形变名称列表）
- 添加按钮

#### Scenario: 添加骨骼条目
- **WHEN** 用户选择类型为"骨骼"，选择一个骨骼，点击添加
- **THEN** 系统 SHALL 在当前帧组末尾追加一个 BoneIndex 类型的条目，条目列表 UI SHALL 立即刷新

#### Scenario: 添加形变条目
- **WHEN** 用户选择类型为"形变"，选择一个形变，点击添加
- **THEN** 系统 SHALL 在当前帧组末尾追加一个 MorphIndex 类型的条目，条目列表 UI SHALL 立即刷新

### Requirement: 删除条目

每个条目行 SHALL 提供删除按钮。

#### Scenario: 删除条目
- **WHEN** 用户点击某条目的删除按钮
- **THEN** 系统 SHALL 从当前帧组中移除该条目，条目列表 UI SHALL 立即刷新

### Requirement: 条目排序

每个条目行 SHALL 提供上移（↑）和下移（↓）按钮。

#### Scenario: 上移条目
- **WHEN** 用户点击非首项条目的上移按钮
- **THEN** 该条目 SHALL 与上一个条目交换位置，UI SHALL 刷新

#### Scenario: 下移条目
- **WHEN** 用户点击非末项条目的下移按钮
- **THEN** 该条目 SHALL 与下一个条目交换位置，UI SHALL 刷新

#### Scenario: 首项上移或末项下移
- **WHEN** 用户点击首项的上移或末项的下移按钮
- **THEN** 系统 SHALL 不执行任何操作

### Requirement: 新增帧组

系统 SHALL 提供新增帧组功能，包含名称输入框和新增按钮。

#### Scenario: 新增帧组
- **WHEN** 用户输入帧组名称并点击新增按钮
- **THEN** 系统 SHALL 在表示框列表末尾追加一个空帧组，CYCLE 下拉列表 SHALL 更新，自动切换到新帧组

### Requirement: 删除帧组

系统 SHALL 提供删除当前帧组的按钮。

#### Scenario: 删除帧组
- **WHEN** 用户点击删除帧组按钮
- **THEN** 系统 SHALL 移除当前选中的帧组及其所有条目，CYCLE 下拉列表 SHALL 更新，选中索引调整为有效值

### Requirement: PMX 导出表示框

系统 SHALL 在 `SavePMX` 中将 `DisplayFrameData` 列表转换为 `PMXFile::m_displayFrames` 写入导出文件。

#### Scenario: 导出包含表示框
- **WHEN** 用户导出 PMX 文件，且存在表示框数据
- **THEN** 导出的 PMX 文件 SHALL 包含与编辑后完全一致的表示框结构（帧组名称、类型、条目列表）

#### Scenario: 导出空表示框
- **WHEN** 用户导出 PMX 文件，且表示框列表为空
- **THEN** 导出的 PMX 文件的 `m_displayFrames` SHALL 为空
