## 背景

UV 变形是 PMX 变形类型之一（类型 3–7：UV、AddUV1–4）。它们修改的是逐面的 UV 坐标，而非顶点位置。插件已在 `MMDMeshManagerObject::LoadPMX()` 中通过带 `ID_CA_POSE_UV` 标志的 `CAPoseMorphTag` 和 `CAMorphNode::SetUV()` 从 PMX 文件导入 UV 变形数据。但在类型系统和 UI 层面，UV 变形与位置（网格）变形无法区分——两者都使用 `MeshMorph` 类，并显示在 `MODEL_MORPH_MESH_GRP` 下。

当前流程：
1. `MMDMeshManagerObject::LoadPMX()` 将 UV 变形导入到 `CAPoseMorphTag`（正确）
2. `RefreshMeshMorphData()` 从 pose morph 标签按名称发现所有变形 → 存入 `mesh_morph_name_`
3. `MMDModelManagerObject::RefreshMorph()` 调用 `GetMeshMorphData()` → 为每个条目创建 `MeshMorph`
4. UV 变形最终成为 Mesh 变形 UI 组下的 `MeshMorph` 实例

## 目标 / 非目标

**目标：**
- 添加 `MMDMorphType::UV` 和 `UVMorph` 类，使类型系统能区分 UV 变形与位置变形
- 在属性管理器中添加 `MODEL_MORPH_UV_GRP` UI 组用于 UV 变形
- 确保在 PMX 导入和场景刷新时都能正确识别 UV 变形
- 保持与现有已保存场景的向后兼容（沿用原有 `MeshMorph` 序列化）

**非目标：**
- 不改变 UV 变形数据如何应用到 `CAPoseMorphTag`（`mmd_mesh_manager.cpp` 中的导入逻辑已正确）
- 不添加 UV 变形导出支持（当前导出路径可保持不变）
- 不支持材质变形或冲量变形（单独实现）

## 设计决策

### 1. 通过 MMDMeshManagerObject 中的独立名称集合识别 UV 变形

**决策**：在 `MMDMeshManagerObject` 中，与 `mesh_morph_name_` 并存，新增 `maxon::HashSet<String> uv_morph_names_`。在 `LoadPMX()` 期间，将 UV 变形名称插入该集合。通过 `GetUVMorphNames()` 对外暴露。

**为何不检查 CAPoseMorphTag 标志？** Pose morph 标签的 `ID_CA_POSE_UV` 是标签级标志，不是按变形设置的。一旦启用，该标签上的所有变形理论上都可能包含 UV 数据。没有可靠的按变形 API 来查询某个变形是修改 UV 还是点，除非遍历 morph 节点。在导入时显式存储名称更简单且确定。

**为何不用带类型标志的联合映射？** 那会把 `mesh_morph_name_` 的值类型从 `Int32` 改为结构体，破坏序列化兼容性并需要更多重构。单独的集合是增量改动。

### 2. UVMorph 类与 MeshMorph 结构一致

**决策**：`UVMorph` 是继承 `IMorph` 的叶子类，结构与 `MeshMorph` 相同（仅名称 + 强度）。实际变形数据在 `CAPoseMorphTag` 中；该类仅提供 UI 和类型识别。

**考虑过的替代方案**：添加 UV 专用字段（例如 UV 通道：UV/AddUV1–4）。当前不采用——通道已在导入时烘焙进 pose morph 标签。若后续需要，可无破坏性添加。

### 3. RefreshMorph 区分 UV 与网格变形

**决策**：`MMDModelManagerObject::RefreshMorph()` 将同时调用 `GetMeshMorphData()` 和 `GetUVMorphNames()`。对 `GetMeshMorphData()` 中的每个名称，检查是否也在 UV 名称集合中 → 若在则创建 `UVMorph` 而非 `MeshMorph`。

### 4. 序列化向后兼容

**决策**：`uv_morph_names_` 在 `MMDMeshManagerObject::Write()` 中于现有字段之后序列化。在 `Read()` 中尝试读取 UV 名称集合；若文件结束（旧格式），则全部视为网格变形。这样可保留旧场景加载能力。

对于 `UVMorph` 类的序列化：复用 `IMorph::Read/Write`（与 `MeshMorph` 相同）。变形类型由父级 morph 映射决定，而非 `IMorph` 序列化。

### 5. UI 布局

**决策**：在 `OMMDModelManager.res` 中，在 `MODEL_MORPH_MESH_GRP` 与 `MODEL_MORPH_BONE_GRP` 之间添加 `MODEL_MORPH_UV_GRP` 组。UV 变形为仅展示的滑块（与 mesh/bone 变形相同）——无添加/删除/重命名按钮，因其来自 pose morph 标签。

## 风险 / 权衡

- **[风险] RefreshMeshMorphData 在未重新导入 PMX 的场景重载时无法保留 UV 名称** → 缓解：`uv_morph_names_` 在 HyperFile 中序列化，可跨保存/加载周期保留。
- **[风险] 旧场景没有 UV 名称集合——所有变形显示为网格变形** → 可接受的降级：用户可重新导入 PMX 以获得正确分类。无数据丢失。
- **[权衡] UV 变形仍共享同一 `mesh_morph_data_` 存储** → UV 变形与网格变形都通过同一 `SetMorphStrength` 路径工作，这是正确的，因为两者都经由 `CAPoseMorphTag`。拆分存储会增加不必要的复杂度。
