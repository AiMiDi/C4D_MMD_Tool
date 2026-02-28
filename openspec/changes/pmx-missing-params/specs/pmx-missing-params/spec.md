# PMX 缺失参数补全

命名规范：所有参数 UI 显示名称与 PMXEditor 对齐，日语/繁体汉字统一为简体中文。

## ADDED Requirements

### Requirement: 现有参数命名对齐 PMXEditor

系统 SHALL 将 TMMDBone 属性管理器中的中文显示名称与 PMXEditor 骨骼面板对齐。仅修改字符串资源文件中的显示名称，参数 ID 和数据不变。

#### Scenario: 重命名后参数显示正确

- **WHEN** 在 C4D 中查看 MMDBoneTag 的属性管理器（中文语言环境）
- **THEN** 各参数名称 SHALL 与 PMXEditor 骨骼面板一致：性能 group 内为「旋转/移动/IK/显示/操作」，骨骼名标签为「骨骼名(日)」/「骨骼名(英)」，末端指向 group 为「表示先」，IK 内使用「Target/Loop/Link/单位角」

#### Scenario: 已保存场景兼容性

- **WHEN** 打开一个使用旧版命名时保存的 C4D 场景
- **THEN** 所有参数数据 SHALL 正常读取，仅显示名称更新

### Requirement: 骨骼「付与亲 L」标志参数

系统 SHALL 在 MMDBoneTag 的属性管理器「付与」group 中暴露「付与亲 L」布尔参数。该参数对应 PMX 骨骼标志位 AppendLocal（0x0080），控制付与来源：0=取用户变形/IK/多重付与，1=取父骨骼局部变形量。

#### Scenario: PMX 骨骼设置了 AppendLocal

- **WHEN** 导入的 PMX 文件中某骨骼的 flag 包含 0x0080（AppendLocal）
- **THEN** 该骨骼的 MMDBoneTag 的「付与亲 L」参数 SHALL 为 true

#### Scenario: PMX 骨骼未设置 AppendLocal

- **WHEN** 导入的 PMX 文件中某骨骼的 flag 不包含 0x0080
- **THEN** 该骨骼的 MMDBoneTag 的「付与亲 L」参数 SHALL 为 false

### Requirement: 骨骼「外部亲」/「亲Key」参数

系统 SHALL 在 MMDBoneTag 的属性管理器中新建「外部亲」group，暴露「外部亲」布尔参数和「亲Key」整数参数。PMX 导入时 SHALL 从骨骼标志位 DeformOuterParent（0x2000）和 m_keyValue 读取并写入。

#### Scenario: PMX 骨骼启用外部亲

- **WHEN** 导入的 PMX 文件中某骨骼的 flag 包含 0x2000（DeformOuterParent）
- **THEN** 该骨骼的 MMDBoneTag 的「外部亲」参数 SHALL 为 true，「亲Key」参数 SHALL 为 PMX 中的 m_keyValue 值

#### Scenario: PMX 骨骼未启用外部亲

- **WHEN** 导入的 PMX 文件中某骨骼的 flag 不包含 0x2000
- **THEN**「外部亲」参数 SHALL 为 false，「亲Key」参数 SHALL 为 0

### Requirement: 表情「panel」分类参数

系统 SHALL 为每个导入的 morph 保存其面板分类值。显示名为「panel」（与 PMXEditor 一致），值为 CYCLE：1=眉、2=目、3=口、4=其他。

#### Scenario: 导入含面板分类的表情

- **WHEN** 导入的 PMX 文件中某 morph 的 m_controlPanel 值为 2（目）
- **THEN** 对应的 morph 参数中「panel」SHALL 显示为"目"

### Requirement: 「表情变换材质」参数

系统 SHALL 在 MMDModelManagerObject 的属性管理器中暴露「表情变换材质」group 与子项列表。PMX 导入时 SHALL 将所有 PMXMorphType::Material 类型的 morph 数据导入并存储。

#### Scenario: 导入含材质变形的 PMX

- **WHEN** 导入的 PMX 文件包含 PMXMorphType::Material 类型的 morph
- **THEN** 属性管理器中 SHALL 出现「表情变换材质」group，列出每个材质变形的名称

#### Scenario: 导入不含材质变形的 PMX

- **WHEN** 导入的 PMX 文件不包含材质变形
- **THEN** 属性管理器中「表情变换材质」group SHALL 为空

### Requirement: 「冲量变形」参数

系统 SHALL 在 MMDModelManagerObject 的属性管理器中暴露「冲量变形」group 与子项列表。PMX 导入时 SHALL 将所有 PMXMorphType::Impluse 类型的 morph 数据导入并存储。

#### Scenario: 导入含冲量变形的 PMX

- **WHEN** 导入的 PMX 文件包含 PMXMorphType::Impluse 类型的 morph
- **THEN** 属性管理器中 SHALL 出现「冲量变形」group，列出每个冲量变形的名称

### Requirement: 「表示框」参数

系统 SHALL 在 MMDModelManagerObject 的属性管理器中暴露「表示框」数据。PMX 导入时 SHALL 遍历 pmx_file.m_displayFrames，为每个表示框创建以框名命名的 group 并列出其包含的骨骼/表情条目。

#### Scenario: 导入含表示框的 PMX

- **WHEN** 导入的 PMX 文件包含 2 个表示框（"Root" 含 1 个骨骼，"表情" 含 3 个表情）
- **THEN** 属性管理器中 SHALL 出现「表示框」group，包含 "Root" 和 "表情" 两个子 group，各列出其成员

### Requirement: 顶点「轮廓倍率」参数

系统 SHALL 在导入 PMX 时将逐顶点的 edgeMag（轮廓倍率）存储到 mesh 对象上。使用 VertexMapTag 存储，Tag 名称 SHALL 为「轮廓倍率」。

#### Scenario: 导入含非默认 edgeMag 的 PMX

- **WHEN** 导入的 PMX 文件中存在 edgeMag 不全为 1.0 的顶点
- **THEN** mesh 对象上 SHALL 存在名为「轮廓倍率」的 VertexMapTag，其中每个顶点的值 SHALL 等于 PMX 中对应顶点的 m_edgeMag

### Requirement: SDEF 顶点数据参数

系统 SHALL 在导入 PMX 时将 SDEF 权重类型的顶点参数（C、R0、R1）存储到 mesh 对象上。存储方式使用 3 个 VertexColorTag（分别命名为 "SDEF_C"、"SDEF_R0"、"SDEF_R1"），每个 Tag 的 RGB 通道分别存 Vector3 的 X/Y/Z 分量。

#### Scenario: 导入含 SDEF 顶点的 PMX

- **WHEN** 导入的 PMX 文件中存在权重类型为 SDEF 的顶点
- **THEN** mesh 对象上 SHALL 存在 "SDEF_C"、"SDEF_R0"、"SDEF_R1" 三个 VertexColorTag，SDEF 顶点对应位置 SHALL 填充 PMX 中的 C/R0/R1 值，非 SDEF 顶点 SHALL 为 (0,0,0)
