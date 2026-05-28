## Context

当前材质数据由 `MMDModelManagerObject::material_list_` 持久化，材质创建和同步通过 `MMDMaterialAdapter` 分发到 Standard、Redshift、Octane、Corona 等实现。Morph 系统已经支持 group/flip 的运行时展开，Mesh/UV/Bone morph 会把展开后的强度推给对应 manager，但 `MaterialMorph::UpdateMorph()` 为空，`ApplyMorphRuntimeStrength()` 也没有 material 分支。

libMMD 已经能读写 PMX material morph offsets：目标材质索引、加算/乘算模式、diffuse、specular、specularPower、ambient、edgeColor、edgeSize、textureFactor、sphereTextureFactor、toonTextureFactor。当前导入路径只创建一个 material morph 名称/strength UI，未保存 offset 明细，因此无法场景恢复、PMX 导出或运行时应用。

Cinema 4D `ShaderData` 适合放在材质通道里被采样，不能承担 morph 图求值或在采样函数里修改场景对象。材质表情需要把“PMX 数据持久化和强度合成”放在 manager 层，把“通道显示”放在少量通用 shader 和 material adapter 层。

## Goals / Non-Goals

**Goals:**

- 完整保存 PMX material morph 的 offset 数据，并在 MeshManager 属性管理器提供可查看/可编辑的材质表情栏。
- PMX 导入、场景保存恢复、PMX 导出保持 material morph 字段和目标材质索引关系。
- 运行时 material morph 复用现有 group/flip 强度展开结果，并从基础材质状态重新计算有效材质状态，避免强度累积漂移。
- Standard 材质优先用少量通用 `ShaderData` shader 包装贴图通道；简单颜色、透明度和浮点字段在播放求值阶段预计算后更新到 shader/material 参数；不能 shader 化的字段走 adapter 同步。
- 保持现有 `MMDMaterialAdapter` 边界，Redshift/Octane/Corona 首版仅支持简单颜色和浮点字段的预计算参数更新。

**Non-Goals:**

- 不在本变更中为每个 renderer 实现完整 node material morph 图。
- 不在本变更中为 Redshift/Octane/Corona 实现贴图 factor、classic ShaderData wrapper 或 renderer-specific node graph。
- 不用一个 `ShaderData` 类型对应一个 PMX 字段或一个 morph；避免插件类型爆炸。
- 不在 `ShaderData::Output()` 中读取/修改可变 C4D 场景状态，也不在 shader 采样时重新计算 group/flip/morph 图。
- 不改变 VMD morph keyframe 导入语义；VMD 仍只负责驱动 morph strength。

## Decisions

### D1: 材质表情数据模型独立于材质当前值

新增可持久化的数据结构保存 material morph 定义，例如 `MMDMaterialMorphData` 与 `MMDMaterialMorphOffsetData`。每个 morph 记录名称、英文名、panel、strength DescID 关联和 offset 列表；每个 offset 记录目标材质索引、操作模式和 PMX material morph 的全部字段。

这样可以区分三类数据：

- `MMDMaterialData`：PMX 基础材质和 C4D 材质链接。
- `MMDMaterialMorphData`：PMX material morph 定义。
- `MMDMaterialRuntimeData`：当前帧按 strength 合成后的有效材质状态。

备选方案是直接把 morph offset 写进 `MaterialMorph` 类内部，但这会让 UI 持久化、PMX 导出和 MeshManager 页面编辑都依赖动态 morph 对象生命周期。独立数据模型更适合 HyperFile、CopyTo、导出和 UI 列表同步。

### D2: MeshManager 完整编辑和持久化材质表情，ModelManager 仍负责 morph strength 调度

按需求在 MeshManager 属性管理器新增“材质表情”栏，负责展示和完整编辑 material morph offset 明细。每个 offset 字段都需要在页面上可见、可编辑、可保存，包括 target material index、运算模式和所有 PMX material morph 字段。ModelManager 继续拥有通用 morph 列表、strength UI、group/flip 展开和 VMD strength 动画，因为这些行为已经服务所有 morph 类型。

target material index 为 `-1` 时，UI 显示为“全部材质”，并禁用具体 material link / material index 选择控件，避免用户同时表达“全部材质”和“某个材质”。切回非 `-1` 目标时再启用具体材质选择。

实现上 MeshManager 可以通过 model manager link 读取/更新 material morph 数据，或把 material morph 数据放在 MeshManager 后由 ModelManager 查询。推荐由 ModelManager 保留运行时权威索引，由 MeshManager 提供属性页编辑视图，避免打散现有 `ApplyMorphRuntimeStrengths()` 的调度入口。

### D3: 运行时从基础材质重新合成，不原地累积

每次 `ApplyMorphRuntimeStrengths()` 完成 group/flip 展开后，Material 分支把所有 material morph 的有效强度传给材质运行时 evaluator。Evaluator 从未变形的 `material_list_` 基础值开始，按 PMX 规则对目标材质应用 offsets：

- target material index 为有效索引时只作用于该材质。
- target material index 为 `-1` 时作用于所有材质。
- Multiply 模式按基础值乘以插值后的 offset 值。
- Add 模式按基础值加上 `offset * strength`。

合成结果写入 `material_runtime_list_` 或等价缓存，再由 material adapter 同步到 C4D 材质和 shader 参数。这样与之前 compound morph 纯求值修复保持一致，不会因为播放、拖时间线或重复执行而污染基础数据。

### D4: 贴图通道用嵌套 ShaderData wrapper，简单颜色和浮点用预计算参数更新

Cinema 4D `BaseShader` 可以形成嵌套结构。材质或对象使用 `InsertShader()` 拥有 shader branch；许多拥有子 shader 的 shader 类型通过 `InsertUnder()` 挂载子级。基于这个机制，贴图类材质表情采用 wrapper shader 更合理：保留原 Bitmap/Layer/Fusion shader 作为子 shader，外层 `MMDMaterialTextureMorphShader` 采样子 shader 后再应用 PMX textureFactor / sphereTextureFactor / toonTextureFactor 的乘算或加算效果。

简单颜色和浮点字段不必每次采样时再计算：

- diffuse RGB、alpha、specular、specularPower、ambient 等当前材质系统已承载的字段在 `ApplyMorphRuntimeStrengths()` 后由 evaluator 预计算成有效值。
- Standard adapter 将这些有效值写入现有材质参数或少量简单 shader 参数。
- 贴图 wrapper shader 只处理必须按采样点读取原贴图结果再做 factor 叠加的通道。

首版 Standard 材质新增少量通用 shader：

- `MMDMaterialTextureMorphShader`：包装一个原始 child shader，采样 child 输出后应用 texture/sphere/toon factor。
- `MMDMaterialColorShader` 或现有 `Xcolor` 参数路径：承载预计算后的纯色 diffuse。
- `MMDMaterialAlphaShader` 或现有 `Xcolor` 参数路径：承载预计算后的 alpha。

表情更新时由运行时 evaluator 或 adapter 更新 shader 参数或只读快照。`Output()` 只读取已准备好的参数和 child shader 采样结果，不触碰 `MMDModelManagerObject`、不改 `BaseMaterial`、不访问会被主线程修改的容器。

备选方案是每帧直接修改 `Xcolor`/Bitmap shader 参数。这个方案对纯色和浮点是合适的，但对贴图 factor 不够准确，因为 PMX 的 texture factor 应该作用在贴图采样结果上；wrapper shader 能把贴图采样后的乘算/加算集中表达。

### D5: 非 Standard renderer 只同步简单颜色和浮点

specular、specularPower、ambient 或 renderer-specific 参数不一定能被 C4D Standard shader channel 表达。运行时 evaluator 产出有效材质后，adapter 根据材质类型同步当前材质系统已承载的字段：

- Standard 材质更新可直接设置的材质参数和通用 shader 参数。
- Redshift/Octane/Corona 首版只同步预计算后的简单颜色和浮点字段，例如 diffuse RGB、alpha、specular、specularPower、ambient 中已有 adapter 能映射的部分。
- Redshift/Octane/Corona 首版不实现 textureFactor、sphereTextureFactor、toonTextureFactor 的可视化应用，也不创建或改写 renderer-specific node graph。
- 后续 renderer-specific node 支持可以在各 adapter 内扩展，不改变 material morph evaluator。

`edgeColor`、`edgeSize` 以及其他当前材质系统还没有使用到的 material morph 字段，首版只做 PMX 导入、UI 编辑、场景持久化和 PMX 导出保留，不参与运行时材质参数同步，也不要求 Standard adapter 立即呈现这些效果。

### D6: PMX 导入导出以持久化数据为准

PMX 导入时遍历 `PMXFileMorph::m_materialMorph`，构造 material morph 数据并同步到 MeshManager 页面。PMX 导出时从持久化数据重建 `PMXFileMorph::m_materialMorph`，不从 C4D 材质当前视觉状态反推 offset。

导出前需要校验目标材质索引是否仍有效。无效索引不应崩溃；可以保留原索引用于 round-trip，或在用户修改/删除材质时给出诊断并跳过非法导出项。优先保持导入未修改模型的无损 round-trip。

### D7: 编辑模式和动画模式分离材质表情效果

编辑模式下的材质参数页面默认表达基础 PMX 材质和 material morph offset 定义，不应被当前动画帧的材质表情结果污染。动画/VMD 播放模式下才把有效 material morph strength 应用到 runtime material state，并同步到 shader/material 参数。

模式切换规则：

- EDIT -> ANIM/VMD：从基础 `MMDMaterialData` 和当前 morph strength 计算 runtime material state，然后同步到 C4D 材质。
- ANIM/VMD -> EDIT：清空或归零 runtime material morph 参数，把 C4D 材质恢复到基础 `MMDMaterialData`，但保留 material morph offset 定义。
- 如需要在 EDIT 模式预览材质表情，应作为显式预览开关或临时 strength，不应写回基础材质字段。

## Risks / Trade-offs

- **ShaderData 线程安全风险** → `Output()` 只读 shader 自身参数或 render 初始化快照；所有 morph 求值和参数写入在 manager/adapter 层完成。
- **MeshManager 页面与 ModelManager morph 列表双写风险** → 设计单一权威数据结构，另一侧只做视图/索引同步；新增同步 helper 和保存恢复测试。
- **renderer-specific 或未承载字段表现不一致** → 首版声明 Standard 为完整贴图 factor 显示目标；Redshift/Octane/Corona 只同步简单颜色和浮点；edgeColor、edgeSize 等暂不应用字段保留数据完整性和 PMX round-trip。
- **材质删除/重排导致 morph target 失效** → material morph offset 保存 PMX 索引，并在材质列表重排/删除时同步更新或产生导入/导出诊断。
- **运行时每帧同步材质过重** → 通过 dirty flag / strength checksum / runtime revision 只在有效材质状态变化时更新 shader 和 adapter 参数。
- **编辑态被动画材质表情污染** → 模式切换时明确恢复基础材质，材质表情结果只进入 runtime cache 和 shader/material runtime 参数。

## Migration Plan

1. 新增 material morph 数据结构、HyperFile `Read/Write`、`CopyTo`，旧场景没有该段时读取为空列表。
2. PMX 导入开始填充完整 material morph offsets，同时继续创建普通 morph strength 条目，保证 VMD strength 路径可复用。
3. MeshManager 属性页新增材质表情栏和动态字段，读取旧文件时没有数据则显示空列表；`-1` target 显示“全部材质”并禁用具体材质选择。
4. 接入 runtime evaluator 和 Standard 通用 shader；已有贴图材质在首次同步时安装 wrapper shader 并把原 shader 迁移为 child shader。
5. PMX 导出从持久化 material morph 数据写回 `PMXFileMorph::m_materialMorph`。
6. 如需回滚，删除 runtime 应用和 shader 注册后，持久化 material morph 数据仍可作为无害未使用数据读取。

## Open Questions

None.
