# 阿芙丝袜对照实验

日期：2026-10-07。使用上一轮 SDK 2026 候选 `9deb5a4e...` 保存的实际阿芙场景，独立 c4dpy 进程，固定一盏方向光与腿部相机。未并入生产图。

证据：`_build_msvc/validation/rs-toon-material/stockings-calibration-20261007/`。

丝袜 Specular 为零，Sphere Mode 为 Add，球面贴图为 `mc3.png`。亮带应优先来自这张球面图。参考 Saba 的 [MMD fragment shader](https://github.com/benikabocha/saba/blob/master/viewer/Saba/Viewer/resource/shader/mmd.frag)：视图法线确定球面坐标，Sphere Add 在 Toon 乘法前加到基础颜色，高光另行相加。该实现是参考，尚未作为 MMD/PmxView 原生等价证据。

使用 RS [Matcap](https://help.maxon.net/r3d/cinema/en-us/Content/html/Texture%2BMatcap.html) 的无透视失真相机相关映射，接入基础颜色的加法分支。默认颜色解码下 `mc3.png` 的暗灰亮带非常弱；Sphere sampler 使用 Raw 后，固定灯光下出现更清楚的软亮带。修改 Toon sampler 的 V 偏移 0.5 会缩窄腿正面的大块深色区域，但原始 Toon 图片仍为阶梯状，不能宣称消除分段。

## 图片对应

- `baseline.png`：原配方。
- `matcap.png`：仅加入 Sphere Add，自动解码。
- `bias-v.png` / `bias-u.png`：分别测试 Toon V/U 偏移，Sphere 自动解码。
- `raw.png`：仅 Sphere 改 Raw，保留原 Toon 采样。
- `combined.png`：Sphere Raw + Toon V 偏移 + Light and Shadow 模式。
- `combined-raw-all.png`：在上述基础上，丝袜的基础/Toon/边界 sampler 也改为 Raw。颜色更接近用户截图的浅粉色，但这是明确改变颜色解释的实验，尚未决定生产默认。

文档仍使用 ACEScg / sRGB 显示 / ACES 1.0 SDR-video 变换。简单设置 `DOCUMENT_OCIO_PRESET` 的另一分支未确认改变实际活动配置，不用该分支证明 sRGB 显示校准成功。

材质页崩溃报告打断了生产接入。Sphere Morph、路径/模式编辑事务、普通重开、视角映射、CPU/GPU 一致性及外观参考匹配均尚需继续验证；没有修改 Sphere 未支持诊断或提升 graph revision。
