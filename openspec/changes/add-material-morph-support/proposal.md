## Why

当前 PMX 材质表情只在规范中被列为需要导入的 morph 类型，运行时没有把材质表情应用到 C4D 材质，也没有完整的属性页持久化与 PMX round-trip 能力。补齐这条链路后，VMD/手动表情可以驱动材质颜色、透明度、边线和纹理相关参数，PMX 导入编辑后也能再导出材质表情数据。

## What Changes

- 在 MeshManager 属性管理器中新增材质表情栏，用可持久化的 UI 数据记录并完整编辑材质表情项、目标材质索引、运算模式和各 PMX 材质偏移字段；目标索引为 `-1` 时显示“全部材质”并禁用具体材质选择。
- PMX 导入时完整读取 `PMXMorphType::Material` 数据，保留每个 material morph 的 display/panel 信息、offset 列表、目标材质引用、加算/乘算模式和所有受支持字段。
- PMX 导出时从插件持久化数据重建 material morph section，确保导入后未修改、修改后保存、重新打开后导出都能保持材质表情语义。
- 运行时将 material morph 接入现有 morph strength 评估链路，复用 group/flip 展开后的有效强度，不再在 morph 对象中直接累积或漂移。
- 为 Standard 材质引入少量通用 ShaderData shader，贴图类通道用 wrapper shader 嵌套原贴图 shader 后应用 texture/sphere/toon factor；简单颜色、透明度和浮点字段在表情更新时预计算并更新材质或 shader 参数。
- 在动画/VMD 模式应用材质表情 runtime 效果，在编辑模式恢复基础材质并保持 offset 定义可编辑，避免把播放结果写回基础材质。
- 对无法用 ShaderData 表达但当前材质系统已承载的简单颜色/浮点字段，继续通过材质 adapter 的受控同步路径写入 `BaseMaterial` 或 renderer-specific 参数。
- 保留现有材质 adapter 结构，优先支持 Standard 材质；Redshift/Octane/Corona 首版仅支持简单颜色和浮点字段的预计算参数更新，不做 classic ShaderData、贴图 factor 或 node graph 扩展。

## Capabilities

### New Capabilities

- None.

### Modified Capabilities

- `object-morph-system`: 补全 material morph 的可持久化 UI、PMX 导入导出、运行时强度应用和 group/flip 组合语义。
- `material-system`: 新增材质表情运行时状态、通用 ShaderData 更新路径，以及不能 shader 化字段的 adapter 同步规则。
- `import-pmx-parameter-mapping`: 将现有“Material Morph 参数”要求从仅展示列表扩展为完整字段导入、持久化和 PMX 导出 round-trip。

## Impact

- **代码**：`source/module/tools/object/mmd_mesh_manager.*`、`source/module/tools/object/mmd_model_manager.*`、`source/module/tools/object/mmd_morph.*`、`source/module/tools/material/*`、`source/CMTSceneManager.*`、PMX 导入导出相关路径。
- **资源**：MeshManager/ModelManager 相关 `.res`、`.h`、`.str` 描述文件，新增材质表情栏、字段控件、列表/按钮文案和持久化 DescID。
- **SDK/插件注册**：新增少量 `ShaderData` plugin 注册和描述资源；所有 SDK 差异通过既有兼容层处理。
- **PMX round-trip**：Material morph section 从导入、场景保存恢复到导出需要保持字段完整性和索引关系。
- **测试**：需要增加 PMX material morph 解析/导出 round-trip 校验，以及运行时 material morph 应用的 focused 验证。
