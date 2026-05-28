## 1. 数据模型与持久化

- [ ] 1.1 阅读 `source/module/core/cmt_marco.h` 和现有 HyperFile helper，确认本变更需要的 SDK 兼容写法
- [ ] 1.2 新增 material morph 持久化数据结构，覆盖目标材质索引、操作模式、diffuse、specular、specularPower、ambient、edgeColor、edgeSize、textureFactor、sphereTextureFactor、toonTextureFactor
- [ ] 1.3 为 material morph 数据实现 `Read`、`Write`、`CopyTo`、清空和索引校验逻辑，旧场景缺失数据时读取为空列表
- [ ] 1.4 将 material morph 数据与现有 `MaterialMorph` strength 条目建立稳定名称/索引关联

## 2. MeshManager 属性页与 PMX 导入导出

- [ ] 2.1 在 MeshManager 资源描述和字符串中新增“材质表情”栏、morph 列表、offset 列表和全部 PMX offset 字段控件
- [ ] 2.2 实现 MeshManager 材质表情栏的完整字段编辑、选中项读写、添加/删除 offset 和 dirty 刷新
- [ ] 2.3 实现 target material index 为 `-1` 时显示“全部材质”并禁用具体 material link / material index 选择
- [ ] 2.4 PMX 导入时从 `PMXFileMorph::m_materialMorph` 填充完整 material morph 数据，同时保留通用 morph strength UI
- [ ] 2.5 PMX 导出时从持久化 material morph 数据重建 `PMXMorphType::Material` 数据，并处理 `-1` 全材质目标
- [ ] 2.6 在材质删除、重排、同步列表时更新或诊断 material morph target index，避免悬空索引导致崩溃

## 3. 运行时求值与材质同步

- [ ] 3.1 在 `ApplyMorphRuntimeStrength()` 中接入 Material morph 分支，复用 group/flip 展开后的有效强度
- [ ] 3.2 实现 material morph evaluator，从基础 `MMDMaterialData` 每次重新合成有效 runtime material state
- [ ] 3.3 按 PMX Add/Mul 规则实现 diffuse、alpha、specular、specularPower、ambient、texture/sphere/toon factor 的强度应用，并区分预计算字段和贴图采样字段；edgeColor、edgeSize 等暂未承载字段仅保留数据
- [ ] 3.4 为 runtime material state 增加 dirty/revision 判断，只在有效状态变化时同步 C4D 材质
- [ ] 3.5 更新 EDIT/ANIM/VMD 模式切换路径，确保动画模式应用材质表情、编辑模式恢复基础材质且不把 runtime 效果写回基础字段
- [ ] 3.6 更新导出清空恢复路径，确保 strength 归零或导出结束时材质回到基础状态

## 4. ShaderData 与 MaterialAdapter

- [ ] 4.1 注册少量通用 MMD material ShaderData plugin，并添加对应描述资源和插件注册入口
- [ ] 4.2 在 Standard material adapter 中为贴图通道安装/复用通用 texture morph wrapper shader，并把原贴图 shader 作为 child shader 保留
- [ ] 4.3 对纯色 diffuse、alpha 和浮点字段优先使用运行时预计算值更新 `Xcolor` 或材质参数，不强制走 per-sample shader
- [ ] 4.4 确保 ShaderData `Output()` 只读取 shader 参数、render-time 快照和 child shader 采样结果，不读取或修改可变场景状态
- [ ] 4.5 将 specular、ambient 和其他当前材质系统已承载但无法 shader 化的字段通过 `MMDMaterialAdapter::SyncTo()` 或新增 runtime sync helper 更新
- [ ] 4.6 为 Redshift/Octane/Corona adapter 增加最小同步：仅更新预计算后的简单颜色和浮点字段，不处理贴图 factor、classic ShaderData wrapper 或 renderer-specific node graph

## 5. 验证与文档

- [ ] 5.1 增加 PMX material morph round-trip 测试，验证导入后导出保留所有 offset 字段
- [ ] 5.2 增加运行时 material morph focused 验证，覆盖 direct strength、group/flip contribution、重复求值不漂移、strength 归零恢复和 EDIT/ANIM 模式分离
- [ ] 5.3 增加 Standard 材质贴图 wrapper 验证，确认原贴图 shader 被保留为 child shader 且 texture factor 作用于采样结果
- [ ] 5.4 使用 `cmake --preset dev-windows-deps-test` 与 `cmake --build --preset cmt-deps-test` 验证依赖测试
- [ ] 5.5 使用 `cmake --preset dev-windows` 与 `cmake --build --preset workflow-dev` 验证插件构建
- [ ] 5.6 更新 `docs/dev/import-flow.md` 或相关 runtime/material 文档，记录 material morph 数据流、BaseShader 嵌套方式和 ShaderData 边界
