## ADDED Requirements

### Requirement: 导入骨骼「付与亲 L」/「外部亲」/「亲Key」字段

PMX 导入管线 SHALL 在 `MMDBoneManagerObject::LoadPMX` 的骨骼遍历中，读取骨骼标志的 AppendLocal（0x0080）和 DeformOuterParent（0x2000）位，以及 m_keyValue 字段，并写入对应 MMDBoneTag 的描述参数。

#### Scenario: 骨骼导入包含新增标志

- **WHEN** 执行 PMX 导入且 `import_bone` 为 true
- **THEN** 每根骨骼的 MMDBoneTag SHALL 包含「付与亲 L」「外部亲」「亲Key」参数且值与 PMX 文件一致

### Requirement: 导入「表情变换材质」和「冲量变形」

PMX 导入管线 SHALL 在 `MMDModelManagerObject::LoadPMX` 的 morph 遍历中，处理 PMXMorphType::Material 和 PMXMorphType::Impluse 类型的 morph，将其名称和数据存储到模型管理器的动态描述参数中。

#### Scenario: morph 遍历覆盖材质和冲量类型

- **WHEN** 执行 PMX 导入且 `import_expression` 为 true
- **THEN** PMXMorphType::Material 和 PMXMorphType::Impluse 类型的 morph SHALL 被导入并可在属性管理器中查看

### Requirement: 导入表情「panel」分类

PMX 导入管线 SHALL 为每个导入的 morph 存储 m_controlPanel 值（1–4），显示名为「panel」。

#### Scenario: morph panel 分类写入

- **WHEN** 执行 PMX 导入且 `import_expression` 为 true
- **THEN** 每个 morph 的「panel」参数 SHALL 与 PMX 中的 m_controlPanel 值一致

### Requirement: 导入「表示框」

PMX 导入管线 SHALL 遍历 pmx_file.m_displayFrames 并将每个表示框的框名、类型及其包含的骨骼/表情引用存储到模型管理器的描述参数中。

#### Scenario: 表示框数据完整导入

- **WHEN** 执行 PMX 导入
- **THEN** 所有表示框 SHALL 被导入，包括框名、类型（DefaultFrame/SpecialFrame）和成员列表

### Requirement: 导入顶点「轮廓倍率」

PMX 导入管线 SHALL 在 `MMDMeshManagerObject::LoadPMX` 中将每个顶点的 m_edgeMag 写入名为「轮廓倍率」的 VertexMapTag。

#### Scenario: 轮廓倍率数据写入 VertexMapTag

- **WHEN** 执行 PMX 导入且 `import_polygon` 为 true
- **THEN** mesh 对象上 SHALL 存在「轮廓倍率」VertexMapTag，值与 PMX 一致

### Requirement: 导入 SDEF 顶点数据

PMX 导入管线 SHALL 在 `MMDMeshManagerObject::LoadPMX` 中将 SDEF 类型顶点的 C/R0/R1 数据写入 3 个 VertexColorTag。

#### Scenario: SDEF 数据写入 VertexColorTag

- **WHEN** 执行 PMX 导入且 `import_polygon` 为 true 且存在 SDEF 类型顶点
- **THEN** mesh 对象上 SHALL 存在 "SDEF_C"、"SDEF_R0"、"SDEF_R1" 三个 VertexColorTag
