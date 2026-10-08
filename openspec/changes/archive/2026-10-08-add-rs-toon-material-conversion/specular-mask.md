# Specular 遮罩候选修复（2026-10-07）

历史状态：早期候选仅完成源码及编译，未完成实际画面验收。后续已发现并修复插值 ID 错误，GPU/CPU 高光图像及新模块基础参数同步结果见 [RS 2026.9 收据](rs269-validation.md)。以下保留早期候选的证据，不把新结果追溯到旧模块。旧证据目录：
`_build_msvc/validation/rs-toon-material/specular-mask-20261007-13b768440f7e/`。

## 修改依据与实现

[Maxon Toon Material 文档](https://help.maxon.net/c4d/2025/en-us/Subsystems/Default/Content/html/Material%2BToon.html)
说明关闭 Fresnel 时，反射层可能覆盖底色，需要 Tonemap Layer Mask 控制高光的可见范围。
原转换图关闭 Fresnel，但没有连接该遮罩。这个缺口是源码和文档支持的修复方向，尚无前后渲染图证明它解释了用户模型的全部差异。

- 新增 `cmt_specular_mask` 原生 Ramp，使用连续黑到白线性插值，连接 `toonmaterial.refl_mask_tone_map`。
- 漫反射的 Toon Ramp 与此遮罩分开。保持现有 Specular RGB / Power 绑定及 Power→roughness 近似。
- 显式配置反射权重 1、反射光照模式 1、Fresnel 关闭和间接反射 0。
- Graph revision 升为 3，固定角色数为 30，13 个属性不变。新角色与连接纳入配方、绑定验证和可用性探测；旧 revision 不自动改图，需要重新转换。
- `binding_snapshot` 增加新配方默认遮罩的原生读回断言。该函数只用于默认配方检查，不将用户手工调过的 Ramp 视为默认值。

## 已取得的验证

- SDK 2026、2024、R20 Release 编译通过。候选 SDK 2026 模块完整 SHA256：
  `13b768440f7ede6d73db9edda65c4fcd74c3f3e0fe53db0529a21f6e43c4d2de`。
- 材质 Morph、Morph 求值、材质 fixture 三项 Release CTest 通过。这些是数值/逻辑回归，不证明新遮罩的画面正确。
- Python 语法检查、diff 检查和 OpenSpec 严格验证通过。
- 在旧加载模块宿主中，用原生 API 创建了六球原型并保存 `specular-masks.c4d`。原型上排无遮罩、下排有遮罩，各列分别为零 Specular、Power 8、Power 64；原型反射模式为 0，不能冒充生产候选模式 1 的图像验收。

## 未完成及阻塞

原型渲染没有产出有效图片。RS 日志停在 `Context: Busy:Render Waiting until idle`，已请求取消任务渲染并恢复临时设备偏好。用户确认暂停 RenderView/IPR。

随后候选模块 GUI 宿主停在 SplashScreen；已知旧模块控制启动也未进入可用主界面，其中一次进程随后退出。用户确认没有操作窗口，也未见提示。没有本轮新崩溃报告，不能归因为新模块崩溃。
带控制台的启动日志到达 DirectX/NVIDIA Drawport 初始化；c4dpy 也未进入测试脚本。
CLI-Anything 不在当前 PATH；Rider 附加尝试没有建立调试会话，故没有调用栈证据，也未声称启动根因已定位。
测试进程已清理，最终 Rider 会话列表为空。

候选模块完整原生导入、前后画面、零 Specular、Power 增大时高光宽度、保存重开及上一轮新增预览默认值/Undo 仍需验证。任务 1.4 已重新取消勾选，保留 revision 2 的历史校准证据。

Sphere Add 尚未实现。这件真实 PMX 的丝袜 Specular 为零，其 `mc3.png` 亮带不由本次高光遮罩替代。
