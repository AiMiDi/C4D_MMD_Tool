# 实际 PMX 描边检查 — 2026-10-07

输入为用户指定目录 `C:\白银之城—阿芙2.0` 下的 `阿芙2.0.pmx`。
仅在任务自有文档中导入，未改写源 PMX。没有 MMD 原生对照图。

使用 SDK 2026 Release 模块
`3a27a16d171e5498c7556e3da8441feca9b06552285d6d4ffffa7541a67b548c`，
profile v1 / graph recipe revision 2。实际导入为 35 个材质，其中 22 个开启
edge；edge size 均为约 0.6，脸和皮肤的 edge Alpha 为 0.5。
普通 UV、Toon 图及 13 个绑定字段正常生成。

固定相机、灯光、720×960 分辨率和 CPU Production 渲染进行对照：

| 场景 | 参数 | 相对关闭描边的变化 |
| --- | --- | --- |
| 原始导入 | edge 0.6；约 1080p 下 1.8px | 16,683 像素超过 1/255；4,343 个双方不透明像素的 RGB 至少一通道变暗超过 6/255 |
| 直接等效宽度 | Thickness 1.8、Modifier 1 | 与原图最大解码通道差 1/255，支持当前 1024×Modifier 的线宽实现确实生效 |
| 加粗预览 | 只把 22 个开启 edge 的条目改成 2.0，Alpha 保留 | 21,740 像素超过 1/255；10,072 个双方不透明像素满足上述变暗阈值 |

结论：实际 PMX 的描边已生成并影响渲染。默认宽度很细，黑背景和全身缩放
进一步降低可见度。RS Contour 画在对象轮廓内部，和 MMD 的几何扩张描边
存在视觉差异。加粗预览用于比较，没有修改默认导入映射或源模型数据。

证据保存在本机
`_build_msvc/validation/rs-toon-material/actual-pmx-20261007-3a27a16d171e/`：
原始及加粗 C4D 场景、原始 RGBA 渲染、白背景对照图、绑定和 Contour 参数、
相机身份、渲染配置和像素统计。两份场景仍引用本机原始纹理目录。

首轮异步渲染对照发生相机回落，已排除这些图片。修正维护中的
`native_toon_test.start_render`：每个 clone 显式绑定对应场景相机，并在源文档
非 active 的情况下复验。此处只修改测试辅助代码，不更改材质生产实现。
复验的相机和取景保持一致；重渲染与加粗对照最大解码通道差为 6/255，
未宣称完整逐像素一致。临时渲染设备偏好已恢复；默认和加粗两份审阅场景
已在任务自有 Cinema 4D 进程中打开，加粗场景为当前 active 文档。

官方范围说明：[Maxon Redshift Contour](https://help.maxon.net/c4d/en-us/Content/_REDSHIFT_/html/Utility%2BContour.html)。
