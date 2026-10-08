# 基础材质自动同步与丝袜对照（2026-10-07）

后续更新：新模块三种材质的基础参数、名称及 reader 默认值已完成原生验证，见 [RS 2026.9 收据](rs269-validation.md)。以下保留早期模块及启动阻塞的历史边界。

证据目录：`_build_msvc/validation/rs-toon-material/authoring-sync-20261007-4a73c33ccc65/`。

## 自动同步

当前加载模块 `3a27a16d171e5498c7556e3da8441feca9b06552285d6d4ffffa7541a67b548c`
已在三个独立、未插入活动文档列表的保存场景副本中验证 Standard、RS Standard、RS Toon。
测试通过模型的虚拟参数修改 Diffuse RGB/Alpha 和 Specular RGB/Power；没有调用同步按钮或显式 ExecutePasses。
Standard 检查原生 Shader Sample，RS 检查实际绑定的对象属性。

- 基础 RGB `(0.31, 0.42, 0.53)`、Alpha `0.64`、Specular `(0.15, 0.25, 0.35)`、Power `30`，粗糙度 `0.5`。
- Tint 预览权重 `0.5` 后，RGB 红色分量 `0.36`、Alpha `0.69`、Specular 红色分量 `0.25`、粗糙度约 `0.467138`。
- 关闭预览回到修改后的基础值；图节点身份集合不变。
- 测试同时识别实际 renderer 类型，不能用第二个 Toon 场景冒充 RS Standard 验证。

本次源码补充：绑定材质名称随 MMD 本地名称更新；RS Standard/Toon Reader 默认值随基础参数更新，用于缺少网格属性上下文的预览；Morph 的有效结果仍只由网格属性提供。
参数编辑将材质修改加入现有 Undo 记录，且不写入其他模型或重复共享的绑定。
Standard 保持通道外层乘数中性，以免与驱动 Shader 重复相乘。

SDK 2026、2024、R20 Release 编译通过。SDK 2026 候选模块 SHA256
`4a73c33ccc65`（完整值见 receipt.json）输出到独立目录，未替换当前进程加载的模块。
两次独立宿主启动均停在 SplashScreen，测试 Python 插件尚未加载；只终止任务自有测试进程，用户 PID 40832 保留。
因此新增名称、Reader 默认值及其 Undo/Redo **尚未在候选模块上完成原生复验**。
维护中的 `base_parameter_binding` 默认检查这些新行为；本轮旧模块核心链路验证显式关闭这部分检查，JSON 中记录为 false。

## 实际模型与单方向光

用户提供 PmxView 截图作为外观参考。真实 PMX 的“丝袜”条目 Specular RGB 为零，Sphere 模式为 Add，使用 `mc3.png`；Toon 使用 `toon2.png`。
`mc3.png` 含平滑的亮带，而 `toon2.png` 本身有明显的明暗分区。因此不能仅调高光粗糙度或无纹理默认 Ramp 来恢复这件材质的亮带。

单方向光、固定相机的 CPU 基线已保存。方向使用估计值 `(-0.5, -1, 0.5)`，并非从 PmxEditor 读取；曝光、颜色管理及光照方向尚未严格对齐，不能声称与参考等价。
测试了 Camera-space Normal → 数学映射 → Texture Sampler Offset 的 Sphere Add 原型；其结果与基线 RGBA 像素完全相同。
这条接法未产生可接受的实际贡献，未并入生产配方，也未将 Sphere 支持标为完成。
临时 RS 设备偏好已恢复，测试使用非活动文档副本。

下一步外观缺口仍是有效的 Sphere Add/Mul 采样、MMD Toon 光照域映射及同光照/色彩管理条件下的参考对齐。
