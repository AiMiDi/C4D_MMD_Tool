# PMX 缺失参数补全 — 实施任务

命名规范：所有参数 UI 显示名称与 PMXEditor 对齐，日语/繁体汉字统一为简体中文。

## 0. 现有参数重命名（对齐 PMXEditor）

- [x] 0.1 修改 `res/S24_up/strings_zh-CN/description/TMMDBone.str`，按以下对照表重命名：

| 参数 ID | 现有名称 | 新名称 |
|---------|---------|--------|
| PMX_BONE_NAME_LOCAL | 骨骼本地名称(和) | 骨骼名(日) |
| PMX_BONE_NAME_UNIVERSAL | 骨骼通用名称(英) | 骨骼名(英) |
| PMX_BONE_NAME_IS_LOCAL | 骨骼本地名称(和) | 日 |
| PMX_BONE_NAME_IS_UNIVERSAL | 骨骼通用名称(英) | 英 |
| PMX_BONE_PARENT_BONE_TEXT | 亲骨骼索引 | 亲骨骼 |
| PMX_BONE_FLAG_GRP | 骨骼特性 | 性能 |
| PMX_BONE_ROTATABLE | 可旋转 | 旋转 |
| PMX_BONE_TRANSLATABLE | 可移动 | 移动 |
| PMX_BONE_VISIBLE | 可见 | 显示 |
| PMX_BONE_ENABLED | 启用 | 操作 |
| PMX_BONE_DEFORM_LAYER_GRP | 蒙皮变形 | 变形阶层 |
| PMX_BONE_PHYSICS_AFTER_DEFORM | 物理后变形 | 物理后 |
| PMX_BONE_END_OF_BONE_GRP | 骨骼末端指向 | 表示先 |
| PMX_BONE_TAIL_IS_POSITION | 相对位置 | 相对 |
| PMX_BONE_TAIL_INDEX | 尾部骨骼索引 | 骨骼索引 |
| PMX_BONE_TAIL_POSITION | 尾部相对位置 | 相对位置 |
| PMX_BONE_IK_TARGET_BONE_INDEX | IK目标骨骼 | Target |
| PMX_BONE_IK_ITERATION | 迭代次数 | Loop |
| PMX_BONE_IK_LINKS_GRP | IK链 | Link |
| PMX_BONE_IK_LINK_ADD_BUTTON | 添加IK链 | 添加Link |

- [x] 0.2 同步修改 `res/S24_up/strings_en-US/description/TMMDBone.str` 中对应英文名称（保持一致性）
- [x] 0.3 同步修改 `res/R20-S24/strings_zh-CN/description/TMMDBone.str` 和 `res/R20-S24/strings_en-US/description/TMMDBone.str`（R20-S24 版本）

## 1. 骨骼 Tag 参数 — 付与亲 L / 外部亲 / 亲Key

- [x] 1.1 在 `res/S24_up/description/TMMDBone.h` 中新增参数 ID：`PMX_BONE_INHERIT_LOCAL`（10046）、`PMX_BONE_OUTER_PARENT`（10047）、`PMX_BONE_OUTER_PARENT_KEY`（10048）、`PMX_BONE_OUTER_PARENT_GRP`（10049）
- [x] 1.2 在 `res/S24_up/description/TMMDBone.res` 中新增对应参数定义：
  - `PMX_BONE_INHERIT_LOCAL`（BOOL）放在现有「付与」group（`PMX_BONE_INHERIT_GRP`）内，紧接付与亲之后
  - `PMX_BONE_OUTER_PARENT`（BOOL）和 `PMX_BONE_OUTER_PARENT_KEY`（LONG）放在新建 group `PMX_BONE_OUTER_PARENT_GRP` 内
- [x] 1.3 在 `refactoring/module/tools/tag/mmd_bone.cpp` 的 Init 中设置默认值（false / false / 0）
- [x] 1.4 在 `refactoring/module/tools/object/mmd_bone_manager.cpp` 的 `LoadPMX` 骨骼循环中，读取 PMX 骨骼标志的 AppendLocal（0x0080）和 DeformOuterParent（0x2000）位，以及 m_keyValue，写入 MMDBoneTag 的 BaseContainer
- [x] 1.5 字符串资源 — 中文：「付与亲 L」/「外部亲」/「亲Key」，英文：「Append Local」/「Outer Parent」/「Outer Parent Key」
- [x] 1.6 同步修改 `res/R20-S24/` 下对应的 `.h` / `.res` / `.str` 文件

## 2. 表情变换材质与冲量变形

- [x] 2.1 在 `res/S24_up/description/OMMDModelManager.h` 中新增参数 ID：`MODEL_MORPH_MATERIAL_GRP`（1023）、`MODEL_MORPH_MATERIAL_ADD_NAME`（1024）、`MODEL_MORPH_MATERIAL_ADD_BUTTON`（1025）、`MODEL_MORPH_IMPULSE_GRP`（1026）、`MODEL_MORPH_IMPULSE_ADD_NAME`（1027）、`MODEL_MORPH_IMPULSE_ADD_BUTTON`（1028）
- [x] 2.2 在 `res/S24_up/description/OMMDModelManager.res` 中新增对应 group 与参数定义
- [x] 2.3 在 `refactoring/module/tools/object/mmd_model_manager.h` 中新增材质变形和冲量变形的存储结构（参考现有 group/flip morph）
- [x] 2.4 在 `refactoring/module/tools/object/mmd_model_manager.cpp` 中实现 `ImportMaterialMorph` 和 `ImportImpulseMorph` 方法
- [x] 2.5 在 `LoadPMX` 的 morph 遍历循环中增加对 `PMXMorphType::Material` 和 `PMXMorphType::Impluse` 的处理分支
- [x] 2.6 字符串资源 — 中文：「表情变换材质」/「冲量变形」，英文：「Material Morph」/「Impulse Morph」

## 3. 表情 panel 分类

- [x] 3.1 在 morph 动态描述参数中新增 CYCLE 字段，显示名为"panel"（与 PMXEditor 一致），值为 1=眉 2=目 3=口 4=其他
- [x] 3.2 修改现有 morph 导入方法（mesh/uv/bone/group/flip），在创建动态参数时额外写入 panel 值
- [x] 3.3 修改新增的材质/冲量变形导入方法，同样写入 panel 值

## 4. 表示框（Display Frame）

- [x] 4.1 在 `res/S24_up/description/OMMDModelManager.h` 中新增 `MODEL_DISPLAY_FRAME_GRP`（1029）
- [x] 4.2 在 `res/S24_up/description/OMMDModelManager.res` 中新增对应 group 定义
- [x] 4.3 在 `refactoring/module/tools/object/mmd_model_manager.cpp` 中实现 `ImportDisplayFrames` 方法，遍历 `pmx_file.m_displayFrames`，为每个表示框创建动态 group（框名）并填充骨骼/表情条目
- [x] 4.4 在 `LoadPMX` 中调用 `ImportDisplayFrames`
- [x] 4.5 字符串资源 — 中文：「表示框」/「框名」，英文：「Display Frame」/「Frame Name」

## 5. 顶点轮廓倍率（VertexMapTag）

- [x] 5.1 在 `refactoring/module/tools/object/mmd_mesh_manager.cpp` 的 `LoadPMX` 中，在 mesh 创建后添加名为「轮廓倍率」的 VertexMapTag
- [x] 5.2 遍历 PMX 顶点，将每个顶点的 m_edgeMag 写入 VertexMapTag 对应位置

## 6. SDEF 顶点数据（VertexColorTag）

- [x] 6.1 在 `refactoring/module/tools/object/mmd_mesh_manager.cpp` 的 `LoadPMX` 中，检测是否存在 SDEF 权重类型顶点
- [x] 6.2 若存在，创建 3 个 VertexColorTag（"SDEF_C"、"SDEF_R0"、"SDEF_R1"），遍历顶点将 sdefC/R0/R1 的 X/Y/Z 写入 RGB 通道

## 7. 收尾

- [x] 7.1 验证编译通过且新参数在属性管理器中正确显示
- [ ] 7.2 导入测试 PMX 文件，确认各参数值与 PMX 原始数据一致
- [ ] 7.3 确认重命名后现有参数显示正确，已保存场景数据不受影响
