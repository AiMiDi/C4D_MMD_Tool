# RS Toon 材质

当前功能由 `add-rs-toon-material-conversion` 实施，完成状态与原生证据见该变更的任务和验证记录。本轮已完成 25/25 任务，描述的是已验证的工作区候选；不作为安装包已发布或 MMD 像素等价声明。

## 使用场景

`RS Toon（MMD 风格）` 用于在 Redshift 中得到分层明暗、风格化高光、透明贴图与基础轮廓线。它采用当前灯光和 Redshift 的 Toon 着色规则，适合 MMD 风格场景；外观会受灯型、阴影、曝光及色彩管理影响。

Additional UV 默认不用。主贴图使用普通 UV，Toon 使用光照驱动的采样域，轮廓线使用原生 Contour。未使用额外 UV 的模型不应收到这方面的告警。

## 导入与转换

- PMX 导入时在“材质转换类型”选择 `RS Toon（MMD 风格）`。
- 对已有模型，在 EDIT 模式关闭材质混合预览后，选中材质条目并执行“转换为 RS Toon”。转换输入是条目保存的 MMD 基础值和 Morph 定义。
- 转换创建独立材质并切换该条目对应网格/选区的实际材质分配。源材质保留；一次 Undo/Redo 恢复整次转换。
- “创建材质”选择 RS Toon 时执行同一转换事务，切换当前条目的实际分配；其他既有类型沿用原创建行为。
- 文档需要使用 Redshift 渲染才能看到预期效果。导入与转换不修改场景的渲染器、灯光、曝光或色彩管理。

## 参数与 Morph

| 参数 | RS Toon v1 处理 |
| --- | --- |
| Diffuse RGB/Alpha | 驱动基础颜色与不透明度；无主贴图时直接使用 |
| 主贴图 | RGB 与内嵌 Alpha 分路，RGB 不充当透明遮罩 |
| 主贴图 Morph | 使用当前材质求值的独立 Mul/Add RGBA；factor Alpha 调节 RGB，不充当图片 Alpha |
| Toon | 共用 toon01～toon10 或独立纹理；未指定时采用中性白色 Ramp；指定但不可读时使用分段回退并提示路径错误 |
| Toon Morph | 采样后使用独立 Mul/Add RGBA，调节 Toon 颜色 |
| Specular/Power | 调节风格化高光颜色和粗糙度近似 |
| Edge | 逐材质开关、颜色、Alpha 和宽度；支持对应材质 Morph |
| Sphere Multiply / Add | 相机相关 Matcap，在 Toon 乘法前参与；支持独立球面贴图 Morph 和路径/模式编辑 |
| Ambient | 数据保留，独立着色尚未对齐 |
| Additional UV / SubTexture | 默认不需要；明确使用对应特性时提示其未支持的视觉贡献 |
| 逐顶点 edgeMag / 完整 PMX 阴影标志 | 首版未对齐 |

当前独立纹理乘/加公式来自已记录的 Saba 参考修复，其与 MMD 原生输出的等价性尚需外部对照。采用此公式不意味着完整 MMD 渲染还原。

未指定 Toon 时，两端为中性白色，绕过 Toon factor 运算；指定但不可读时，回退 Ramp 阴影段为 0.3、亮部为 1、切换位置为 0.5。Contour 以 1080p 为参考，目标线宽约为 `max(edgeSize, 0) × 3` 像素；实现通过原生 Thickness Modifier 调节，最大宽度为 1024 像素。不同分辨率按 RS 规则缩放，线位于原生轮廓范围内。首版关闭内部线及背向内部线。

Profile v1 的图配方 revision 2 使用普通 UV 主贴图和光照域的垂直 Toon 取样。强光超出 Toon 图片域时，使用同图最亮端像素的原生取样作为边界颜色，避免亮部变黑；这一路仍经过对应 Toon Morph 运算及当前色彩管理。早期 revision 1 原型需要重新转换或创建独立材质，不能作为最终配方的结构验收。

revision 3 在高光分支增加独立、连续的黑到白 Tonemap Layer Mask。关闭 Fresnel 时，遮罩按原生高光光照域限制反射层对底色的覆盖；它不使用漫反射的分段 Ramp，也不使用主贴图 UV。Specular 仍控制高光颜色，Power 仍采用既有粗糙度近似，间接反射明确关闭。颜色渐变的插值 ID 必须为 `linearknot`；早期候选误用了样条的 `linear`，节点接受该值但画面成为硬切换。修正后已在 RS 2026.9 的 GPU、CPU 单方向光六球场景验证平滑高光、零 Specular 和 Power 收窄，并覆盖保存重开。此结果是 RS 原生配方校准，不能作为 MMD 高光等价性结论。详见 [本轮收据](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/rs269-validation.md)。

revision 3 的固定图为 30 个角色、13 个对象属性；revision 4 保留此结构并明确未指定 Toon 时保持中性颜色。revision 5 追加普通 Sphere Multiply/Add，固定图为 40 个角色、16 个对象属性。Sphere 的软亮带在 Specular 为零时仍可出现，它与高光分支分别运算。旧 revision 不自动改图，需要显式重新转换当前材质，原材质保留。

revision 5 的主贴图、Toon、边界与 Sphere sampler 默认统一使用 `Auto`，遵循当前文档和 Redshift 的输入颜色规则。早期 Sphere 候选将所有 sampler 设为 Raw，会在当前色彩管理下抬高主颜色贴图的中间调；按用户后续要求已取消这一强制设置。旧候选的 Raw 亮带对照不能直接作为 Auto 配方的外观结论。设置仍可在节点中编辑，纹理路径更新不会覆盖这些采样设置；既有材质需要显式调整，加载新插件不会自动覆盖艺术家的颜色空间选择。转换不会修改文档工作空间、曝光或显示变换。Toon 垂直采样加入 0.5 偏移，使用 Light and Shadow 模式；这是 RS 光照域上的近似，背向法线和多灯场景仍可能与 MMD 不同。

球面路径或模式编辑会同步图连线，不重新创建角色。坏文件、共享绑定或手工占用目标输入时保留原参数并显示诊断。Sphere 图片 Alpha 不作为物体透明度；Sphere Morph 的 factor Alpha 只参与 RGB 乘/加运算。SubTexture 继续保留数据并报告未支持，不进入额外 UV 默认路径。

实际阿芙的单方向光对照、CPU/GPU、重复渲染和保存重开结果见 [revision 5 验证](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/sphere-production-validation.md)。丝袜软亮带恢复，整体色调更接近参考；原 Toon 图片的分段及精确 MMD 光照差异仍保留。

## 编辑与兼容

基础值仍从模型材质字段编辑。Toon 模式、共用索引和路径变更需要同步所属的 Toon 采样分支；更换主贴图保留采样参数并同步颜色/透明度路线。

受管理的连接被手工替换时，自动同步应停止并显示原因。显式修复用于所属绑定，独立材质用于保留自定义结构或隔离共享所有权。任意第三方材质图不会被反向推测为 PMX 基础参数。

旧场景和旧材质类型继续使用原选择。宿主缺少必要的 Toon、Contour 或相关端口时，RS Toon 应显示不可用原因；它不会静默生成其他材质。

## 验证

外观验收使用真实渲染图，分别记录 GPU/CPU、宿主/渲染器版本、插件模块和 profile revision、灯光、相机及色彩管理。节点创建、源码检查和编译结果各有范围，不能替代画面验收。

重点覆盖透明切口、不同 Toon 输入、不同高光 power、edge 开关/颜色/宽度、合并与拆网格、混合预览、跳帧重置、转换与三轮 Undo/Redo 后立即保存重开。

官方参考：[Toon Material](https://help.maxon.net/r3d/cinema/en-us/Content/html/Material%2BToon.html)、[Contour](https://help.maxon.net/c4d/2024/en-us/Subsystems/Default/Content/html/Utility%2BContour.html)。

当前实施及验收边界见 [RS Toon 验证记录](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/validation.md)。最终模块的事务失败注入、正式接口、51 张独立 GPU/CPU 图像及实际 Standard/Toon 同条件对照已完成，见 [最终验收](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/completion-validation.md)。严格 OpenSpec 校验按用户要求跳过。合并/拆网格的线条覆盖及实际丝袜分段仍有近似差异，MMD 同条件参考缺失。
