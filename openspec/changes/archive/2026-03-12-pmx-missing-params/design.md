## Context

PMX 导入时多类数据被丢弃（详见 proposal.md）。现需将这些数据存入 C4D 属性管理器参数，使其在 UI 中可见，并为后续导出回 PMX 保留数据。涉及骨骼 Tag、模型管理器对象、网格管理器三个层面的描述文件与导入代码。

同时，现有属性管理器中的参数命名需与 PMXEditor 对齐，日语/繁体汉字统一替换为简体中文。

## Goals / Non-Goals

**Goals：**

- 在 C4D 属性管理器中暴露当前丢弃的 PMX 字段：骨骼的付与亲 L / 外部亲 / 亲Key；表情的 panel 分类与表情变换材质/冲量变形；表示框；顶点轮廓倍率与 SDEF。
- 修改 LoadPMX 导入逻辑，在解析 PMX 时将这些数据写入对应参数。
- 保持与现有参数 ID 不冲突，保持资源文件 / 描述文件的一致性。
- 将现有参数的中文显示名称与 PMXEditor 对齐（日语/繁体→简体）。

**Non-Goals：**

- 不在本次实现这些数据的运行时行为（如 SDEF 变形实际驱动网格、材质变形实际修改材质、表示框驱动 UI 分组）。
- 不在本次实现 PMX 导出时回写这些字段（仅保留数据以备后续导出）。
- 不处理追加 UV（addUV 1–4）的存储——作为逐顶点 Vector4 数据量较大，单独评估。

## Decisions

### 0. 现有参数命名对齐 PMXEditor

以下为 `TMMDBone.str`（中文）中需重命名的现有参数，与 PMXEditor 骨骼面板对齐：


| 参数 ID                         | 现有名称      | PMXEditor 名称 | 新名称（简体） |
| ----------------------------- | --------- | ------------ | ------- |
| PMX_BONE_NAME_LOCAL           | 骨骼本地名称(和) | 骨骼名 日        | 骨骼名(日)  |
| PMX_BONE_NAME_UNIVERSAL       | 骨骼通用名称(英) | 骨骼名 英        | 骨骼名(英)  |
| PMX_BONE_NAME_IS_LOCAL        | 骨骼本地名称(和) | 日            | 日       |
| PMX_BONE_NAME_IS_UNIVERSAL    | 骨骼通用名称(英) | 英            | 英       |
| PMX_BONE_PARENT_BONE_TEXT     | 亲骨骼索引     | 亲骨骼          | 亲骨骼     |
| PMX_BONE_FLAG_GRP             | 骨骼特性      | 性能           | 性能      |
| PMX_BONE_ROTATABLE            | 可旋转       | 旋转           | 旋转      |
| PMX_BONE_TRANSLATABLE         | 可移动       | 移动           | 移动      |
| PMX_BONE_VISIBLE              | 可见        | 显示           | 显示      |
| PMX_BONE_ENABLED              | 启用        | 操作           | 操作      |
| PMX_BONE_DEFORM_LAYER_GRP     | 蒙皮变形      | （变形阶层区域）     | 变形阶层    |
| PMX_BONE_PHYSICS_AFTER_DEFORM | 物理后变形     | 物理后          | 物理后     |
| PMX_BONE_END_OF_BONE_GRP      | 骨骼末端指向    | 表示先          | 表示先     |
| PMX_BONE_TAIL_IS_POSITION     | 相对位置      | 相对           | 相对      |
| PMX_BONE_TAIL_INDEX           | 尾部骨骼索引    | （索引）         | 骨骼索引    |
| PMX_BONE_TAIL_POSITION        | 尾部相对位置    | （位置）         | 相对位置    |
| PMX_BONE_IK_TARGET_BONE_INDEX | IK目标骨骼    | Target       | Target  |
| PMX_BONE_IK_ITERATION         | 迭代次数      | Loop         | Loop    |
| PMX_BONE_IK_LINKS_GRP         | IK链       | Link         | Link    |
| PMX_BONE_IK_LINK_ADD_BUTTON   | 添加IK链     | —            | 添加Link  |


以下为 `OMMDModelManager.str`（中文）中需重命名的现有参数：


| 参数 ID                 | 现有名称 | 新名称（简体） |
| --------------------- | ---- | ------- |
| MODEL_MORPH_GROUP_GRP | 组合表情 | 组合表情    |
| MODEL_MORPH_FLIP_GRP  | 反转表情 | 反转表情    |
| MODEL_MORPH_MESH_GRP  | 顶点表情 | 顶点表情    |
| MODEL_MORPH_UV_GRP    | UV表情 | UV表情    |
| MODEL_MORPH_BONE_GRP  | 骨骼表情 | 骨骼表情    |


（以上 morph group 名称已为简体，无需修改，仅确认对齐。）

### 1. 骨骼标志 — 付与亲 L / 外部亲 / 亲Key

参照 PMXEditor 骨骼面板命名（日语汉字→简体）：

- **付与亲 L**（AppendLocal, 0x0080）：付与来源切换，0=取用户变形/IK/多重付与，1=取父骨骼局部变形量。在 PMXEditor 中显示为"付与亲"旁的 `L` 复选框。
- **外部亲**（DeformOuterParent, 0x2000）：外部父变换标志。
- **亲Key**（keyValue）：外部父变换键值，仅当外部亲启用时有效。

**方案**：在 `TMMDBone.h` / `TMMDBone.res` 中新增：


| PMXEditor 名称 | C4D 参数                      | 类型   | 描述 ID |
| ------------ | --------------------------- | ---- | ----- |
| 付与亲 L        | `PMX_BONE_INHERIT_LOCAL`    | BOOL | 10046 |
| 外部亲          | `PMX_BONE_OUTER_PARENT`     | BOOL | 10047 |
| 亲Key         | `PMX_BONE_OUTER_PARENT_KEY` | LONG | 10048 |


- 「付与亲 L」放在现有 `PMX_BONE_INHERIT_GRP`（付与 group）内，紧接付与亲 link 参数之后。
- 「外部亲 / 亲Key」新建 group `PMX_BONE_OUTER_PARENT_GRP`（10049），对应 PMXEditor 右下角的"外部亲"区域。

起始 ID 10046 紧接当前最大值 10045。

### 2. 表情 panel 分类

参照 PMXEditor 表情面板：右上角的 `panel` 下拉框，值为 眉(1) / 目(2) / 口(3) / 其他(4)。

**方案**：morph 使用 DynamicDescription 动态添加参数，在创建每个 morph 动态项时额外添加一个 `panel` 的 CYCLE 参数，存值 1–4（与 PMX 一致）。显示名使用 "panel"（与 PMXEditor 一致）。

### 3. 表情变换材质与冲量变形

参照 PMXEditor 表情面板（日语汉字→简体）：

- 「表情变换材质 编辑」按钮对应材质变形（Material Morph）
- 偏移里区域中「冲量速度 / 冲量扭矩」对应冲量变形（Impulse Morph）

**方案**：在 `OMMDModelManager.h/.res` 中新增：


| PMXEditor 名称（简体） | C4D Group                         | 描述 ID |
| ---------------- | --------------------------------- | ----- |
| 表情变换材质           | `MODEL_MORPH_MATERIAL_GRP`        | 1023  |
| —                | `MODEL_MORPH_MATERIAL_ADD_NAME`   | 1024  |
| —                | `MODEL_MORPH_MATERIAL_ADD_BUTTON` | 1025  |
| 冲量变形             | `MODEL_MORPH_IMPULSE_GRP`         | 1026  |
| —                | `MODEL_MORPH_IMPULSE_ADD_NAME`    | 1027  |
| —                | `MODEL_MORPH_IMPULSE_ADD_BUTTON`  | 1028  |


子项数据通过 DynamicDescription 动态添加，结构参考现有 Group/Flip morph 的实现模式。导入时在 `LoadPMX` 的 morph 遍历循环中增加对 `PMXMorphType::Material` 和 `PMXMorphType::Impluse` 的处理分支。

### 4. 表示框（Display Frame）

参照 PMXEditor 表示框面板（枠→框）：

- 左侧「共同表示框」列表
- 右侧「范围内要素」含框名（日/英）与成员列表
- 可添加表情变换与骨骼成员

**方案**：在 `OMMDModelManager.h/.res` 中新增：


| PMXEditor 名称（简体） | C4D 参数                    | 描述 ID |
| ---------------- | ------------------------- | ----- |
| 表示框              | `MODEL_DISPLAY_FRAME_GRP` | 1029  |


每个表示框用 DynamicDescription 动态添加一个 group（框名 = 表示框名称），group 内列出该框包含的骨骼/表情引用（类型 + 名称）。导入时遍历 `pmx_file.m_displayFrames`。

### 5. 顶点 — 轮廓倍率（edgeMag）与 SDEF

参照 PMXEditor 顶点面板（輪郭→轮廓）：

- 右上角「轮廓线 倍率」= edgeMag
- 右下角「-SDEF- C / R0 / R1」= sdefC / sdefR0 / sdefR1

**方案**：

- **轮廓倍率**：使用 C4D 的 `VertexMapTag`，一个 float 对应一个顶点。导入时在 mesh 上创建名为「轮廓倍率」的 VertexMapTag 并填充。
- **SDEF（C / R0 / R1）**：每个顶点 3 个 Vector3，使用 3 个 VertexColorTag（分别命名为 "SDEF_C"、"SDEF_R0"、"SDEF_R1"），RGB 通道分别存 X/Y/Z 分量。

**本次可先仅实现轮廓倍率（VertexMapTag）**，SDEF 存储方案更复杂且运行时暂不使用，可后续单独处理。

## Risks / Trade-offs


| 风险                              | 缓解                                          |
| ------------------------------- | ------------------------------------------- |
| 参数 ID 冲突                        | 紧接现有最大 ID 分配，开发前再次确认无冲突                     |
| DynamicDescription 条目过多影响 UI 性能 | 材质变形/冲量变形/表示框条目数通常不大（<100），可接受              |
| 逐顶点数据（edgeMag/SDEF）存储方式影响文件大小   | VertexMapTag 是 C4D 原生方式，已有压缩；SDEF 推迟到需要时再实现 |
| 现有 morph 动态参数系统未设计 panel_type   | 新增字段为只读 LONG，不影响现有行为                        |
| 表示框为只读展示，暂不支持编辑                 | 符合本次目标（仅保留数据）                               |
| 现有参数重命名不影响已保存场景                 | 仅修改显示字符串，参数 ID 不变，已保存数据正常读取                 |


