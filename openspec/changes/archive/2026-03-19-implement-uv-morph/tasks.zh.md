## 1. 类型系统与类

- [x] 1.1 在 `mmd_morph.h` 的 `MMDMorphType` 枚举中添加 `UV = 1 << 4`
- [x] 1.2 在 `mmd_morph.h` 中创建继承 `IMorph` 的 `UVMorph` 类（构造函数、移动、`GetType`、`UpdateMorph`、`AddMorphUI`、`DeleteMorphUI`）
- [x] 1.3 在 `mmd_morph.cpp` 中实现 `UVMorph` 方法——`UpdateMorph` 调用 `SetMorphStrength`，`AddMorphUI` 将滑块置于 `MODEL_MORPH_UV_GRP` 下

## 2. 资源描述（UI）

- [x] 2.1 在 `res/S24_up/description/OMMDModelManager.h` 中添加 `MODEL_MORPH_UV_GRP` 枚举值
- [x] 2.2 在 `OMMDModelManager.res` 中，在 `MODEL_MORPH_MESH_GRP` 与 `MODEL_MORPH_BONE_GRP` 之间添加 `GROUP MODEL_MORPH_UV_GRP {}`
- [x] 2.3 在字符串资源文件中添加 `MODEL_MORPH_UV_GRP` 的本地化字符串（`res/S24_up/strings_*/description/OMMDModelManager.str`）

## 3. 网格管理器 — UV 变形名称追踪

- [x] 3.1 在 `mmd_mesh_manager.h` 的 `MMDMeshManagerObject` 中添加成员 `maxon::HashSet<String> uv_morph_names_`
- [x] 3.2 添加返回 `const maxon::HashSet<String>&` 的访问器方法 `GetUVMorphNames()`
- [x] 3.3 在 `MMDMeshManagerObject::LoadPMX()` 中，当 `PMXMorphType` 为 UV/AddUV1–4 时，将变形名称插入 `uv_morph_names_`（单网格与多部件路径均需处理）
- [x] 3.4 在 `Write()` 中于现有字段之后序列化 `uv_morph_names_`
- [x] 3.5 在 `Read()` 中反序列化 `uv_morph_names_`，并做向后兼容回退（若数据不存在，则保持集合为空）
- [x] 3.6 在 `CopyTo()` 中复制 `uv_morph_names_`

## 4. 模型管理器 — 变形创建与刷新

- [x] 4.1 在 `MMDModelManagerObject::AddMorph()` 中添加 `MMDMorphType::UV` 分支，创建 `UVMorph` 实例
- [x] 4.2 更新 `MMDModelManagerObject::RefreshMorph()`，查询 `GetUVMorphNames()`，对匹配名称创建 `MMDMorphType::UV` 的 UV 变形，而非 `MMDMorphType::MESH`

## 5. 验证

- [x] 5.1 构建项目并确认无编译错误
- [ ] 5.2 导入带 UV 变形的 PMX 模型，验证其在属性管理器中出现在 UV 变形组下
- [ ] 5.3 验证位置变形仍出现在 Mesh 组下
- [ ] 5.4 测试保存/重载场景，确认 UV 变形分类被正确保留
