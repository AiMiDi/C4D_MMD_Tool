## Context

当前 PMX 导入后，表示框（Display Frame）数据通过 `ImportDisplayFrames` 函数以 `DTYPE_STATICTEXT` + `DTYPE_GROUP` 的形式写入 DynamicDescription，仅用于只读展示。数据未持久化存储在 `MMDModelManagerObject` 中，导致：

- 用户无法编辑表示框的结构（增删条目、重命名帧组）
- 项目保存/加载后表示框信息丢失（DynamicDescription 的静态文本不自动序列化有意义的数据）
- PMX 导出时无法写回表示框数据

现有的管理器模式（材质列表、Morph 管理）已建立良好的架构范例：使用结构化数据模型 + `GetDParameter/SetDParameter` 动态绑定 + `Read/Write/CopyTo` 序列化。

## Goals / Non-Goals

**Goals:**

- 在 `MMDModelManagerObject` 中以结构化数据持久化存储表示框数据
- 提供可编辑的表示框 UI：重命名帧组、增删条目、条目排序、新增/删除帧组
- 实现 Read/Write/CopyTo 序列化
- PMX 导入时填充结构化数据，PMX 导出时写回 `PMXFile::m_displayFrames`

**Non-Goals:**

- 不实现拖拽排序（使用按钮上移/下移）
- 不实现跨帧组的条目移动
- 不实现表示框的独立编辑器对话框
- 不修改 libMMD 的 `PMXDisplayFrame` 结构

## Decisions

### 决策 1：数据存储——结构化数据模型而非 DynamicDescription

**选择**: 在 `MMDModelManagerObject` 中定义 `DisplayFrameData` 结构体和 `maxon::BaseArray<DisplayFrameData>` 存储表示框列表，完全脱离 DynamicDescription

**理由**:

- DynamicDescription（用户数据）适用于用户自定义的参数，不适合结构化的、需要序列化和导出的数据
- 结构化模型便于 Read/Write/CopyTo 和 ToPMX/FromPMX 转换
- 与材质管理（`maxon::BaseArray<MMDMaterialData>`）和 Morph 管理的架构一致

**替代方案**: 继续使用 DynamicDescription 存储——数据难以序列化，无法可靠导出，且编辑支持受限

### 决策 2：UI 布局——下拉列表选择帧组 + 条目列表

**选择**: 

- 使用 `LONG` + `CYCLE` 下拉列表选择当前编辑的帧组（类似材质列表 `MODEL_MATERIAL_LIST`）
- 选中帧组后，下方以动态描述显示该帧的所有条目
- 每个条目行包含：类型标签（[Bone]/[Morph]）、目标名称、删除按钮
- 帧组级别提供：重命名输入框、添加条目按钮（选择类型+输入索引）、上移/下移按钮、删除帧组按钮、新增帧组按钮

**理由**:

- 与材质管理 UI 模式一致（CYCLE 选择 + 动态绑定属性区）
- 每次只显示一个帧组的条目，避免大量条目导致 UI 拥挤
- 动态描述用于条目列表，支持灵活的增删

**替代方案**: 全部展开为树形结构——条目过多时 UI 难以管理（一个模型可能有数百个表示框条目）

### 决策 3：条目编辑使用 CYCLE 选择目标

**选择**: 添加条目时，使用两个控件：

- 类型选择（`LONG` + `CYCLE`）：骨骼/形变
- 目标选择（`LONG` + `CYCLE`）：动态填充当前模型的所有骨骼或形变名称列表

**理由**:

- 避免用户手动输入索引的出错风险
- 骨骼和形变的名称列表可从 `MMDBoneManagerObject` 和 Morph 数据中获取
- 用户友好，直接选择而非记忆索引

**替代方案**: 使用索引输入框——容易输错，用户体验差

### 决策 4：帧组内条目排序使用上移/下移按钮

**选择**: 每个条目行提供上移（↑）和下移（↓）按钮

**理由**:

- C4D 属性管理器不原生支持拖拽排序
- 按钮方式实现简单可靠
- 与 PMX Editor 的操作方式类似

### 决策 5：条目列表使用动态描述（DynamicDescription）

**选择**: 每个帧组的条目通过 DynamicDescription 动态创建，切换帧组时清除旧描述并重建新描述

**理由**:

- 条目数量可变，静态描述无法满足
- 切换帧组时完全重建描述，避免残留和不一致
- 条目的按钮事件通过 `MSG_DESCRIPTION_COMMAND` + `desc_id_map_` 映射处理

**替代方案**: 使用 `GetDDescription` 动态注入描述——与现有 DynamicDescription 体系不一致，且需要在每帧刷新时完全重建

### 决策 6：帧组名称编辑

**选择**: 在帧组级 UI 区域提供一个 `STRING` 参数显示当前帧组名称，用户可直接编辑。在 `SetDParameter` 中捕获修改并更新 `DisplayFrameData::name`

**理由**:

- 直观且简单
- 与材质名称编辑（`MODEL_MATERIAL_NAME_LOCAL`）模式一致

## Risks / Trade-offs

- **[Risk] 切换帧组时重建动态描述的性能** → 典型帧组内条目数量较少（10-50个），重建代价可接受。使用 `EventAdd()` 确保 UI 刷新
- **[Risk] 序列化版本兼容** → 在 `Read` 方法中使用 level 参数检测表示框数据是否存在，缺失时跳过（向后兼容）
- **[Risk] 条目的骨骼/形变索引在编辑后可能失效** → 存储索引和名称双份数据，优先使用索引，失效时显示名称提示用户
- **[Risk] 帧组数量较多时 CYCLE 下拉列表可能拥挤** → 典型 PMX 模型帧组数量在 2-5 个，极端情况不超过 20 个，CYCLE 可以胜任

