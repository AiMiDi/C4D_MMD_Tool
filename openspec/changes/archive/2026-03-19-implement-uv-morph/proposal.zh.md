## 背景与动机

UV 变形（PMX 类型 UV/AddUV1–4）已由 `MMDMeshManagerObject` 从 PMX 文件导入，但被静默合并到通用的 `MeshMorph` 类别中。用户在属性管理器中无法区分基于 UV 的变形与顶点位置变形，且变形类型系统没有对 UV 变形的原生表示。添加显式的 UV 变形支持可提升美术人员的使用清晰度，并使插件的类型系统与 PMX 规范保持一致。

## 变更内容

- 在 `MMDMorphType` 枚举中新增 `UV` 值，并新增继承自 `IMorph` 的 `UVMorph` 类。
- 在 `OMMDModelManager.res` 中新增 UI 组 `MODEL_MORPH_UV_GRP`，使 UV 变形在属性管理器中拥有独立分组。
- 更新 `MMDModelManagerObject::AddMorph()` 和 `RefreshMorph()`，识别并创建 `UVMorph` 实例，而非将其当作 `MeshMorph` 处理。
- 更新 `MMDMeshManagerObject`，在导入时标记 UV 变形，以便在 `RefreshMorph` 中与位置变形区分。
- 更新变形的读写序列化逻辑以支持新类型。

## 能力范围

### 新增能力

- `uv-morph`：独立的 UV 变形类型，拥有独立 UI 组、正确的类型识别及持久化支持。

### 修改能力

- `morph-system`：在变形类型层次结构中加入 UVMorph，并更新变形存储与 UI 契约。

## 影响范围

- **源文件**：`mmd_morph.h/cpp`、`mmd_model_manager.h/cpp`、`mmd_mesh_manager.h/cpp`
- **资源**：`OMMDModelManager.res`、`OMMDModelManager.h`、字符串表
- **序列化**：HyperFile 读写路径需保持向后兼容（不含 UV 变形类型的旧场景仍应能加载）
- **无外部依赖变更** — libMMD 已提供 `PMXMorphType::UV` 和 `UVMorph` 结构体
