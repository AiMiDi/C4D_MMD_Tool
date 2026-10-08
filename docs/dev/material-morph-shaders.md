# 材质 Morph 着色器实现

## 使用方式

- **ANIM**：编辑 Morph 的正式 `strength`，或给它设置关键帧。Material、Group、Flip 的有效权重共同驱动材质。
- **EDIT**：在“材质表情 → 仅材质混合预览”启用预览，选择表情并调整“预览权重”。切换到另一项后，之前的权重仍保留，可混合多项。预览不驱动骨骼或顶点。
- 关闭预览恢复基础材质；“清空预览权重”将所有预览项归零。进入 ANIM 会关闭并清空预览。普通保存重开后预览关闭；渲染文档克隆保留本次预览。
- 新导入的 Standard / Redshift / RS Toon 材质自动安装绑定。旧场景在 EDIT 下使用“升级材质 Morph”。升级、修复和创建独立材质均有 Undo 记录。
- 连接丢失时使用“修复选中材质绑定”。如果通道已被手工 Shader 占用，或多个模型共享同一绑定，使用“创建独立材质”；原材质和手工结构保留。
- 新乘算偏移以 1 初始化，新加算偏移以 0 初始化。切换操作不改输入值；“重置偏移为中性值”才明确重置当前项。
- 在基础材质字段中修改主贴图路径，会同步更新插件拥有的贴图分支；清空路径恢复纯色与基础 Alpha，再添加贴图会复用已有节点。原贴图和采样设置保留；不存在的文件、手工更改的贴图或占用目标输入的手工连接会被拒绝并显示诊断。

基础值仍在模型的材质字段中编辑。反向读取仅在 EDIT 且预览关闭时允许；受 Morph 驱动的输出没有可独立反读的基础值，界面会报告这一情况。

### 基础参数自动同步

在模型的材质列表选择条目后，修改名称、Diffuse RGB/Alpha、Specular RGB/Power 会自动更新所属 Standard、RS Standard 或 RS Toon 材质，无需点击同步按钮。当前 Morph 权重继续叠加在新基础值上；关闭预览后恢复新基础值。主贴图路径也通过所属分支更新，RS Toon 另支持 Toon 路径和 Edge 字段。

Standard 的实际颜色/透明度/反射由绑定 Shader 提供，通道外层乘数保持中性，避免重复染色。RS 的实际值来自模型网格上的 User Data；编辑基础值同时更新 Reader 的默认值，使没有模型网格上下文的材质预览也使用新基础值。默认值不写入 Morph 结果。名称与默认值变更加入参数编辑的 Undo 记录。

此绑定是 MMD 基础数据到渲染材质的单向驱动。手工改线和不属于当前模型的绑定仍受保护；Sphere、独立 Ambient、完整 PMX 阴影标志等未映射的字段不会因此获得对应的着色效果。

## 数据通路

`cmt_morph_evaluation.hpp` 展开 Group/Flip，并报告循环和无效引用。
`cmt_material_morph_accumulator.hpp` 从基础值组合乘算与加算。每次求值从基础值开始，不把效果回写基础数据。

Standard 使用内部 ShaderData 的颜色、标量、贴图 RGB、贴图 Alpha 输出模式。
绑定通过模型和材质链接定位，与材质列表索引分离。`InitRender` 使用当前渲染文档及其时间求值，并持有本次采样所需的颜色/标量；`Output` 不遍历 Morph、不写场景。当前实现每次初始化生成独立结果，没有复用活动视口的全局缓存。

Redshift 使用固定的原生 User Data 节点。导入/显式修复创建节点及对象属性，运行时只发布数值。主贴图 RGBA 通过颜色分离器取 A；RGB 不作为不透明度。对节点连接的验证包括原生 Alpha 路径。

RS Toon 使用独立 profile：保留前七个角色的语义，新增 Toon 的 Scale/Bias/Add 和 Edge 的颜色/Alpha/宽度，共十三个角色。属性键从 300 开始，与既有 Standard 的 child shader 登记范围隔离。Toon 路径编辑在共用纹理、独立纹理与默认 Ramp 间切换；受管理的目标输入被艺术家连接占用时拒绝更新。详细使用与证据见 [rs-toon-materials.md](rs-toon-materials.md)。

两条通路现在保留独立的纹理乘算 M 和加算 A，并使用以下 Saba 参考规则。原生 MMD 图像对照尚未完成，因此这不是最终还原精度声明：

```
有主贴图：U = (1 - M.a) + 图片 RGB × M.rgb × M.a
          RGB = (clamp(U + (U - 1) × A.a, 0, 1) + A.rgb) × Diffuse RGB
          Alpha = 图片 Alpha × Diffuse Alpha
无主贴图：RGB = Diffuse RGB；Alpha = Diffuse Alpha
高光：Specular RGB；roughness = (2 / (max(power, 0) + 2)) ^ 0.25
```

factor Alpha 参与 RGB 运算，不再乘入图片不透明度；截断发生在加上 A.rgb 之前。无贴图时不应用纹理系数。Toon、Sphere 的乘算与加算也分别保留；本修复不扩展其显示范围。PMX 原始 offset 的保存和导出格式保持不变。

Standard 的 InitRender 捕获独立 M/A，贴图包装器在采样后应用上述运算。Redshift 使用固定的偏置、饱和、加法、Diffuse 乘法节点；采样前的等价缩放为 `M.rgb × M.a × (1 + A.a)`，偏置为 `1 - M.a × (1 + A.a)`。运行时只发布七个 User Data 字段，不重建图。状态校验和覆盖独立 M/A，避免旧合成系数相同而实际采样不同的状态碰撞。

绑定版本升至 2。已有版本 1 绑定会停止驱动并提示显式“升级材质 Morph”，升级使用原来的可撤销操作；手工占用的输入和被修改的运算节点不会被覆盖。未绑定的旧 Shader 参数模式继续使用旧解释，直至显式升级。历史渲染图像对应旧公式，不能用作本修复的像素验收。

## 验证与限制

验收记录及准确二进制身份见
`openspec/changes/archive/2026-10-08-shader-driven-material-morph/validation.md`。
SDK-independent 测试可通过根构建的 `cmt-plugin-tests` 或独立 `tests/` CMake 工程运行。
原生测试助手为 `tests/material/shader_binding_test.py`；它必须在 Cinema 4D 中配合
`scripts/c4d_runtime_regression.py` 的私有测试文档使用。

**纹理修复版本 5d699ce5（2026-10-07）**：15 组逻辑测试、SDK 2026/2024/R20 Release 构建通过；Standard 六组原生采样通过。Redshift 在 GPU-only 设置下通过七次跳帧渲染和 0～30 全部 31 帧，RGB/Alpha 符合参考运算，重复帧及连续/跳帧对应帧的 PNG 哈希一致，本次没有崩溃或显存不足。版本 1 的两种材质均通过显式升级、Undo/Redo 和立即保存重开。测试后恢复设备偏好、清理私有文档并关闭任务自有 C4D。此证据覆盖纹理运算及其运行通路；完整高光/照明矩阵、原生 MMD 图像对照仍未完成。以下段落保留此前版本的历史记录。

当前已有 Standard 原生采样、背景渲染、混合预览、保存重开、材质 PMX round-trip、旧场景升级及 Undo/Redo 证据。2026-10-07 的 Release `5a8929a8` 通过 Redshift GPU 预览；随后的 GPU 时间轴首帧返回 `RENDERRESULT_OUTOFMEMORY`，当时显卡仅剩约 587 MiB 显存。同一版本的 CPU-only 时间轴 0 → 30 → 15 → 0 通过颜色/Alpha 验证，返回第 0 帧的结果与初始帧完全一致。设备配置已恢复。单帧 GPU 结果不代表连续 GPU 渲染验收；完整高光/照明图像矩阵尚未完成，因此当前实现不标记为完整发布验收通过。

双材质升级在 Standard 和 Redshift 中均通过三轮 Undo/Redo，每一步立即保存并重开验证。Redshift 的节点修改不再单独生成自动图撤销：文档用完整材质快照统一记录节点与绑定元数据，避免批量升级只能撤销/重做其中一个材质。复制共享材质的冲突诊断、显式创建独立材质及其 Undo/Redo 通过；副本预览 Alpha 为 0.575 时原模型保持 0.5，普通保存重开后预览关闭，两者均恢复为 0.5。两种渲染器各重复求值 100 次，结构数量保持不变。

同日 GPU 重试已通过 `0 → 15 → 30 → 0 → 30 → 15 → 0`，重复帧的采样颜色和 Alpha 完全一致。额外的 0～30 逐帧测试通过第 0～3 帧后，在第 4 帧返回显存不足（当时可用约 582 MiB）。因此短跳帧序列已有 GPU 证据，完整逐帧验收仍保留为待完成。

撤销后立即保存的崩溃已修正。网格管理器不再序列化运行时标签地址缓存，保存的 Pose Morph 标签仍是权威数据；重开与复制时重建缓存。运行时 Morph 标签引用使用可检测失效的 BaseLink。原生回归覆盖深层网格撤销和 Redshift 节点修复撤销，各重复三轮 Undo/Redo，并在每一步立即保存、重开检查。
