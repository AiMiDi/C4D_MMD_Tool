# Standard / RS Standard 的 Matcap Sphere 验证

2026-10-07。用户后续任务：把普通 SPA/Sphere 通过 Matcap 接回 RS Standard 与默认材质转换。

## 完成范围

- RS Standard 新图使用原生 Texture Sampler → Matcap（World）→ 独立 Sphere
  Mul/Add RGBA → Base Color 加/乘。保持 PBR Specular/Roughness 与 opacity 独立。
- 默认 Standard 新图在 Color Shader 内用相机空间 Phong normal 生成
  `(0.5 + Nx/2, 0.5 - Ny/2)` 的 Sphere UV，保留原始 UV bitmap 与独立 Sphere child。
  InitRender 缓存 render-document 状态；Output 不读取编辑器可变状态。
- 两者支持 None/Multiply/Add、受控路径编辑、坏文件拒绝、采样参数保留、
  手工输入保护与 Undo/Redo。SubTexture/Additional UV 保留数据并旁路，未映射。
- RS 旧七字段 v2 binding 不在运行时改图；当前条目显式“修复绑定”可迁移到十字段
  profile 2/revision 1。默认材质的旧 Environment 配方需创建独立材质使用新配方。
- 材质类型序列化值和当前 Toon profile/revision 保持不变。Sphere 是基础颜色运算，
  不自动覆盖 PBR 高光，也不把 Toon ramp 接成 PBR 的完整光照模型。

## 精确候选与原生结果

最终 SDK 2026 Release 模块 SHA-256：
`469f60fcff65b15d51e2427663ccc6a61932e276b57dd1497cb4dd386accb463`。

证据目录：[standard-sphere-20261007-469f60fc](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc)。

- [原生收据](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/native/receipt.json)：
  Standard/RS Sphere RGBA Morph 与重置、路径/模式、采样和艺术家输入保护、立即保存重开通过；
  Standard 的颜色运算以独立手算公式校验。RS 十字段的数值与独立手算一致。
- 同一收据覆盖三种材质的基础属性自动同步、原有 Toon Sphere 回归、RS 旧无 binding
  结构的批量升级与三轮 Undo/Redo 保存重开，以及普通 RS 高光/反向读取和连接保护。
- [旧七字段 v2 收据](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/native/legacy-seven/receipt.json)：
  runtime 保持旧配方；显式修复迁移后仅保留十个属性，没有遗留旧字段；Undo/Redo 立即重开通过。
- SDK 2026、2024、R20 Release 构建通过；现有三个 focused CTest 通过。
  旧 SDK 的编译证据不代表该宿主上的原生渲染验收。

## 图片结果

[渲染收据](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/visual/receipt.json)
记录 11 个保存重开后执行的成功样例，包含两种材质的正面/换向无光照渐变球，
实际阿芙丝袜的 Sphere None/Add，以及完整模型。默认材质使用 CPU；RS 使用 GPU，
丝袜 Add 另有 CPU 对照。方向测试还验证中心 Alpha=255，与 Sphere 图片的 Alpha=96 无关。

实际模型：`C:\白银之城—阿芙2.0\阿芙2.0.pmx`。丝袜仍使用原始 `mc3.png`、Add 模式、
原始主贴图和零 Specular；一个方向光 `(0.25,-0.65,1)`，没有替换用户源贴图。

[像素分析](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/visual/pixel-analysis.json)：

| 比较 | 最大 RGB 差异（8 位） | 最大 Alpha 差异 | 解释 |
| --- | ---: | ---: | --- |
| Standard 渐变球换向 | 0 | 0 | 相机法线投影稳定，方向断言通过 |
| RS 渐变球换向 | 1 | 0 | 相机法线投影稳定，方向断言通过 |
| Standard 丝袜 None/Add | 15 | 0 | 2169 个可见像素改变，Sphere 未进入 opacity |
| RS 丝袜 None/Add | 6 | 1 | 2100 个可见像素改变，Alpha 差异在采样容差内 |
| RS 丝袜 Add CPU/GPU | 2 | 1 | 当前固定场景的设备对照通过 |

两种渲染器的亮度及边缘覆盖仍不同，不以跨渲染器的绝对 RGB/Alpha 差分验收等效。
本轮验收投影方向、相机响应、Sphere 运算与生命周期；未宣称完整 MMD/PmxView 等效。
默认 Shader 的投影采样不使用 mesh UV 的 MIP 半径，精细高频 SPA 的过滤效果仍需单独评估。

## 失败记录与加载状态

- 前期发现 Matcap `space` 是 Int32，错误的 Int64 校验导致导入拒绝；已修正并原生复验。
- 方向渐变发现默认 Shader V 轴与 RS 相反；已翻转并在最终模块重跑全部原生和图片样例。
  `b1ea7249` 的前期图片仅作定位记录，不能替代最终候选。
- 最终候选第一次 GPU 帧返回 `RENDERRESULT::OUTOFMEMORY`（1）；无法仅凭该返回值区分
  内存/显存原因。失败保存在 `visual/resource-failure-*`，不算通过。同一模块在新独立
  进程重跑 11 帧全部通过。
- 测试在任务自有 c4dpy 进程执行。最终模块已同步至
  `_build_msvc/sdk_2026/bin/Release/plugins/mmdtool/mmdtool.xdl64`。
  当前 GUI 仍加载 `auto-color-space-20261007` 的旧模块，保留其未保存场景；本轮未关闭或重启。
  保存并关闭 GUI 后，可正常启动 C4D 并传入新的 `_build_msvc/sdk_2026/bin/Release/plugins`。

## 交付场景

- [阿芙-Matcap-standard.c4d](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/visual/阿芙-Matcap-standard.c4d)
- [阿芙-Matcap-redshift.c4d](../../../../_build_msvc/validation/rs-toon-material/standard-sphere-20261007-469f60fc/visual/阿芙-Matcap-redshift.c4d)

两者均已实际保存、重开并渲染，继续保留原始模型文件中的 MMD 材质数据。
