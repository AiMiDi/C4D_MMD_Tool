## ADDED Requirements

### Requirement: MMD 材质数据结构定义

系统 SHALL 定义 `MMDMaterialData` 结构体，包含完整的 PMX 材质属性字段：

| 字段 | 类型 | 说明 |
|------|------|------|
| `name_local` | `String` | 本地材质名称 |
| `name_universal` | `String` | 通用材质名称 |
| `diffuse` | `Vector4d32` | 扩散色 RGBA |
| `specular` | `Vector32` | 反射色 RGB |
| `specular_power` | `Float32` | 反射强度 |
| `ambient` | `Vector32` | 环境色 RGB |
| `draw_both_face` | `Bool` | 双面描绘 |
| `draw_ground_shadow` | `Bool` | 地面影 |
| `draw_cast_self_shadow` | `Bool` | 本影标示（投射阴影到阴影贴图） |
| `draw_receive_self_shadow` | `Bool` | 本影（接收自身阴影） |
| `draw_vertex_color` | `Bool` | 顶点色 |
| `edge_enabled` | `Bool` | 轮廓线有效 |
| `edge_color` | `Vector4d32` | 轮廓线颜色 RGBA |
| `edge_size` | `Float32` | 轮廓线尺寸 |
| `texture_index` | `Int32` | 纹理索引（-1 为无） |
| `sphere_texture_index` | `Int32` | 高光贴图索引（-1 为无） |
| `sphere_mode` | `Int32` | 高光贴图模式（0=无效, 1=乘算, 2=加算, 3=子纹理） |
| `toon_mode` | `Int32` | Toon 模式（0=独立, 1=共用） |
| `toon_texture_index` | `Int32` | Toon 纹理索引 |
| `memo` | `String` | 备注 |
| `num_face_vertices` | `Int32` | 面数（三角面数 × 3） |
| `material_link` | `AutoAlloc<BaseLink>` | 指向 C4D `BaseMaterial` 的链接 |

#### Scenario: 从 PMXMaterial 构造 MMDMaterialData
- **WHEN** 调用 `MMDMaterialData::FromPMX(const libmmd::PMXMaterial& pmx_material)` 时
- **THEN** 所有字段 SHALL 从 `PMXMaterial` 的对应字段正确映射，`draw_*` 标志从 `PMXDrawModeFlags` 位标志中提取，`material_link` 初始化为空

#### Scenario: 从 MMDMaterialData 导出到 PMXMaterial
- **WHEN** 调用 `MMDMaterialData::ToPMX(libmmd::PMXMaterial& pmx_material)` 时
- **THEN** 所有字段 SHALL 正确写回到 `PMXMaterial` 的对应字段，`draw_*` 标志 SHALL 合并为 `PMXDrawModeFlags` 位标志

### Requirement: 材质列表存储

`MMDModelManagerObject` SHALL 维护一个 `maxon::BaseArray<MMDMaterialData>` 类型的材质列表，按材质索引顺序存储所有 MMD 材质数据。

#### Scenario: 空模型无材质
- **WHEN** 模型未加载或无材质时
- **THEN** 材质列表 SHALL 为空，材质计数为 0

#### Scenario: 导入后材质列表填充
- **WHEN** PMX 模型导入完成后
- **THEN** 材质列表长度 SHALL 等于 PMX 文件的材质数量，每个元素包含完整的 MMD 材质数据

### Requirement: 材质数据序列化

材质数据 SHALL 支持 C4D 项目文件的 `Read/Write/CopyTo` 序列化。

#### Scenario: 保存并重新加载项目
- **WHEN** 包含 MMD 材质数据的项目被保存后重新打开时
- **THEN** 所有材质属性 SHALL 完整恢复，`BaseLink` 指向的 C4D 材质引用 SHALL 正确解析

#### Scenario: 加载不含材质数据的旧项目
- **WHEN** 打开不含材质管理器数据的旧版项目文件时
- **THEN** 系统 SHALL 正常加载，材质列表为空，不产生错误

#### Scenario: 复制模型对象
- **WHEN** 用户复制包含材质数据的 `MMDModelManagerObject` 时
- **THEN** 目标对象的材质列表 SHALL 是源对象的深拷贝，`BaseLink` SHALL 独立

### Requirement: 材质与 C4D 材质的关联

每个 `MMDMaterialData` SHALL 通过 `BaseLink` 关联到文档中的一个 `BaseMaterial` 对象。

#### Scenario: 导入时建立关联
- **WHEN** PMX 导入创建 C4D 材质后
- **THEN** 对应的 `MMDMaterialData::material_link` SHALL 指向新创建的 `BaseMaterial`

#### Scenario: 关联材质被删除
- **WHEN** 用户手动删除了 C4D 文档中的关联材质时
- **THEN** `material_link->GetLink(doc)` SHALL 返回 `nullptr`，UI 中对应的材质链接 SHALL 显示为空
