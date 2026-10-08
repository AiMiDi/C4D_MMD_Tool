# RS Toon 材质转换设计

## Context

目标见 [proposal.md](proposal.md)。本设计基于 2026-10-07 当前工作区，包含未提交的 shader-driven material morph 实现；不把历史 Release 收据当作新 Toon 功能的验证结果。

现有扩展点：

- `ModelImport::material_type` 和两个 UI 列表按 Standard、RedShift、Octane、Corona 保存选择。
- `MMDMaterialAdapter` 统一创建、同步、识别与绑定；当前 RS 实现固定查找首个 Standard Material，不能直接用于 Toon。
- 提案时 `mmd_material_binding::Field` 只有四个字段；实施期间共享纹理语义修复扩展为七个字段（含 TextureScale/Bias/Add）和 `CurrentVersion=2`。Toon 使用独立 profile 和 User Data 范围扩展到十三个角色，既有 Standard/RS Standard 仍使用七个角色。
- `MODEL_MATERIAL_CREATE_BUTTON` 创建新材质并修改 `material_link`，但没有切换真实 TextureTag 分配，且绑定准备失败尚未纳入转换回滚。
- PMX 共用 Toon 路径在 `MMDModelManagerObject::AddMaterial()` 中解析，时间晚于旧 adapter 的 `CreateFromPMX()`。新图不能在这之前假定 Toon 路径已完整。
- `shader-driven-material-morph` 已提供不可变求值、EDIT 预览、显式绑定升级、完整材质 Undo 快照与图 UndoMode NONE 的组合。新的图类型应复用这些边界。

## Goals / Non-Goals

**Goals:**

- 提供可直接选择的 `RS Toon（MMD 风格）`，首版画面闭环覆盖分层着色、透明、高光、基础描边和已声明的 Morph 字段。
- 转换后实际网格立即使用新材质，并保持源材质、模型基础数据和动画轨道可恢复。
- 将 RS 公共基础设施与 Standard/Toon 两种图的端口契约分开；扩展 Toon 不改变旧绑定的字段解释。
- 从原生小场景先确认节点能力与图像，再扩展 UI、迁移和兼容验收。

**Non-Goals:**

- 不进行 MMD 原生渲染器复刻，也不重写所有材质的纹理 Morph 公式。
- 不实现 Sphere SubTexture、Additional UV、逐顶点描边倍率、完整 PMX 阴影标志和 MME。用户后续要求对齐实际丝袜外观，普通 Sphere Multiply/Add 纳入 revision 5。
- 不做任意第三方材质图到 Toon 的通用反推转换；输入权威是模型的持久化 MMD 材质条目。
- 不自动修改用户场景的渲染器、灯光、曝光或色彩管理，不批量转换其他模型。

用户已明确 Additional UV 默认不用。首版只要求普通 UV；不创建额外 UV 通道、不把相关网格改造排进前置任务，也不为普通模型展示额外 UV 告警。只有明确使用 Sphere SubTexture 或额外 UV Morph 的输入才提示该项不在支持范围；单纯存在但未被引用的额外通道不告警。

## Decisions

### 1. 用户选择独立类型，内部共享 RS 基础设施

新增 `RedShiftToon` 适配类型与 UI/API 值；所有既有枚举与资源常量的序列化数值固定，新值追加。导入枚举、adapter 枚举和 UI 常量通过显式映射转换，不假设数值相等，也不继续散落 `type_idx < 4`。

Toon adapter 负责图配方和支持矩阵；RS 公共层负责图事务、端口读写、稳定角色路径、原生 User Data 和能力探测。`DetectType/CreateFor` 先识别经过验证的 profile 元数据与输出表面，保留旧 RS 的兼容识别。多 surface 图或混合图不得仅凭第一个 Standard/Toon 节点认领所有权。

仅给现有 RS Standard 设置一个布尔开关会混淆资产识别、端口和已有场景；完全复制现有 RS 文件则会重复维护事务与绑定。采用独立 adapter 加窄公共工具层。

### 2. 先解析完整基础材质，再创建图

抽取 PMX 材质及纹理解析的共用入口，先得到包含主贴图、共用/独立 Toon 和 Sphere 元数据的 `MMDMaterialData`，再构建目标材质。显式转换直接使用现有条目。无需为此改变 PMX 数据格式。

首版图配方：

```text
主贴图 × Diffuse/Texture RGB ───────────→ Toon Base Color
主贴图 A × Diffuse/Texture Alpha ───────→ Toon Opacity
Toon 纹理或默认分层 Ramp × Toon RGB ────→ Toon Base Tonemap
Specular / Power 映射 ─────────────────→ Toon 高光
Edge enable / color / alpha / size ───→ Contour → Output Contour
Toon Surface ─────────────────────────→ Output Surface
```

实际资产 ID、输入类型与端口名必须从安装的 Redshift 节点资产获取并通过原生图读回验证，不能把 Standard 的端口前缀替换为猜测的 Toon 名称。正式转换只使用通过能力检查的配方。

### 3. 第一版近似契约可解释、可版本化

| 数据 | 首版映射 |
| --- | --- |
| 主贴图/Diffuse/Alpha | 沿用现有版本的 RGB/Alpha 契约；图片 A 单独拆出，不使用亮度替代 |
| 共用或独立 Toon | 使用原图驱动 Tonemap；显式处理图像取样轴向、反转、边界和过滤 |
| 没有指定 Toon | revision 4/5 使用中性白色 Ramp，不额外压暗；供用户继续编辑 |
| 指定 Toon 但文件不可读 | 用默认 Ramp 保持可渲染，同时返回可见的路径诊断，不能报告贴图映射成功 |
| Toon factor RGBA | 使用共享 v2 的独立乘/加状态，采样后调节 RGB；factor Alpha 不挪作物体 opacity |
| Specular/Power | 使用 Toon 高光分支；由现有 roughness 近似开始校准，固定灯光下验证 power 增大时高光不变宽、specular 为零时消失 |
| Edge | 开关决定描边；有效颜色、Alpha 和 size 驱动 Contour；宽度为非负 size 乘 profile 缩放值 |
| Sphere Multiply/Add | revision 5 使用 Matcap 投影与独立 RGBA Morph，在 Toon 前乘/加 |
| Ambient、Sphere SubTexture、阴影标志等 | 保留已有数据，明确标为尚未映射；不静默接到 Emission 或其他含义不同的输入 |

revision 5 当前配方的主贴图、Toon、边界与 Sphere sampler 统一采用 Auto，遵循文档与 Redshift 输入颜色规则。早期 Raw 候选的证据按原模块保留，不作为当前 Auto 配方的外观结论。Alpha 与控制量保持数值语义，不硬编码只在一套 OCIO 配置中存在的颜色空间名。转换不更换文档工作空间或显示变换。原生图像校准发现无 wrapping 的 Toon 采样域在强光下可能越界返回黑色；配方 revision 2 增加固定采样最亮端像素的同图分支，作为该 sampler 的 Invalid Color，使边界颜色与同图保持一致解释。

主贴图使用普通 mesh UV，Toon 使用光照驱动的取样域，Contour 使用其原生轮廓计算；这三条路径都不以 Additional UV 为输入。明确使用额外 UV 的源特性只做一次有范围的兼容提示，不因此阻断已支持的材质转换，也不在本轮顺便改造既有 UV Morph 导入/导出。

RS Toon 对灯类型、强度、阴影和 GI 有自身响应。采用原生 Toon 着色并用固定灯光样例建立基线，接受其与 MMD 的差异；完整 MMD 光照及纹理 Morph 语义研究不阻断首版。所有近似规则与默认 Ramp/线宽参数记录为 profile revision，不能通过修改全局 Morph 求值偷偷改变旧材质。

revision 5 追加 Sphere sampler、无透视失真的相机相关 Matcap、独立 Sphere Mul/Add RGBA 和乘/加组合节点。Sphere 在基础纹理/Diffuse 合成后、Toon 乘法前参与，Sphere 图片 Alpha 不参与物体透明度。追加字段保留前十三个编号；revision 4 及更早的清理继续使用十三字段范围。路径与模式编辑先验证受管理连接和独占所有权，再以图事务切换，坏路径与艺术家连接保留原值。

该 MMD 风格配方使用 Auto 解释主/Toon/Sphere 图片，不强制改变艺术家选择的颜色空间；它不改变文档 OCIO 或显示变换。主颜色贴图在 Auto 与 Raw 下的中间调可能不同，球面亮带也需在相同输入解释下比较。Toon 垂直取样偏移 0.5，阴影使用 Light and Shadow 模式；这仍是 native RS 光照域上的近似，不能保证背向法线及灯颜色与 MMD 一致。未指定 Toon 的中性规则保留。旧图不自动升级，需显式重新转换。

revision 3 候选高光修复增加独立的黑到白线性 Ramp，接入 `refl_mask_tone_map`。Fresnel 关闭时，此原生遮罩用于限制反射层在弱高光区域覆盖底色；与漫反射的分段 Ramp 分离。保持既有 Power→roughness 近似，显式设置反射权重、光照/阴影模式及零间接反射。新增节点与连线纳入受管理角色和能力检查；旧 revision 必须重新转换，不自动侵入用户图。新配方必须在单方向光下重新检查零 Specular、Power 单调性和底色保留，编译与节点创建不能替代该画面验收。

### 4. Contour 先实现逐材质控制

Contour 直接连接 Output Contour；首版默认启用外轮廓、关闭容易放大网格结构差异的内部线。保存 profile 线宽缩放参数，其默认值在固定分辨率和相机的样例中校准。关闭 edge 或有效宽度为零必须使轮廓消失，包括场景启用全局 contour 的测试条件。

颜色、Alpha 和宽度可以动画，逐顶点倍率首版明确不读取。测试分别使用合并网格和分材质网格，记录两者轮廓差异。RS 的轮廓内侧绘线和屏幕尺度与 PMX 描边存在区别，因此首版不通过自动复制/外扩几何来弥补。

### 5. 复用求值，按 profile 声明绑定字段

保留原四字段编号，以及共享 v2 增加的三个主贴图字段。增加 profile 身份、图 schema revision 和角色描述表；旧场景没有 profile 字段时按原 Standard/RS Standard 规则处理。Toon 的 thirteen-role User Data 从 metadata key 300 起记录，避免与既有 child shader 范围碰撞。

Toon 角色表追加 ToonScale/Bias/Add、Edge RGB、Edge Alpha、Edge Width；角色的原生属性类型、目标端口和 neutral/default 值集中定义。创建、校验、发布、清理和复制都按 profile 选择同一角色集合，避免扩展创建却仍只发布旧字段。新元数据 key 与既有 UserData/child/output 区间不得碰撞。

图与属性只在导入或显式编辑时创建；运行时通过当前文档的统一快照发布有效值。绑定保存模型/材质/图角色身份，验证目标 surface 和 Output 连接，不依赖名称或当前选中材质。复制模型后的所有权冲突、独立化、预览与普通重开规则沿用现有机制。

基础 Toon 路径、edge 开关和 profile 缩放值属于显式 authoring；已有主贴图切换扩展为按纹理角色更新的受控入口。路径修改保留采样配置，手工占用连接停止自动同步。基础编辑后的 runtime publication 不能重建整个图。

### 6. 转换是一次有范围的场景事务

新操作“转换当前材质”只在 EDIT 且材质预览关闭时执行，使用当前条目的基础数据。“创建材质”选择新增 RS Toon 类型时调用同一转换事务并切换实际分配；既有四种类型继续沿用原创建行为。

1. 根据模型、条目、mesh、selection 和旧材质链接解析需要更换的 TextureTag。整网格使用选区限制，multipart 使用对应 mesh；共享旧材质不会扩大到其他模型或条目。目标不明确则停止并给出诊断。
2. 检查 Toon 能力与输入，构建候选材质，完成绑定和角色验证。候选准备过程对 mesh 新增的 User Data 也属于事务范围。
3. 一次文档 Undo 中插入新材质，替换已解析的 TextureTag 和该条目的链接，提交对应属性与元数据。原材质留在文档中。
4. 任一步失败都恢复旧链接、Tag 和属性，释放本次候选，不触碰无关节点。采用当前已验证的完整快照与图 UndoMode NONE 策略，避免文档 Undo 与图自动 Undo 形成两步。

导入也必须把绑定准备成功纳入完成条件。现有“创建材质后忽略 PrepareMorphBinding 返回值”的方式不能直接用作转换成功判断。

### 7. 编译能力与运行时能力分开

节点 API 的 SDK 差异通过 `cmt_marco.h` 的兼容能力与封装处理。旧 SDK 可以编译并解释既有选择；不支持的 Toon 选择保留身份但明确不可用。

运行时探测所需 Toon、Contour、Tonemap、User Data 资产及端口，采用不插入文档的临时图并释放。UI 和生产接口共用结果。仅有 `API_VERSION >= 2024000` 或“检测到 Redshift”不足以宣告可用。

`redshift_toon` 同步加入原生参数校验、能力列表、PMX 导入分派，以及维护中的 MCP schema。材质导入关闭时不为未使用的 Toon 类型构造图；显式启用 Toon 材质但能力不足时在导入前失败。

## 用户后续范围：RS Standard / 默认材质的 Sphere Matcap

- RS Standard 新绑定使用 `Profile=2 / GraphRevision=1`。字段仍为既有
  `0..6` 与 Sphere `13..15`，按字段映射分配十个 mesh attribute，保存于
  独立的 `400+field` 元数据范围；旧七字段绑定继续按原 schema 发布。
- 原生 Texture Sampler → Matcap（World，`space=Int32(0)`）→ Bias → Saturate
  → Add → Base Color 加/乘。Specular/Roughness 和 opacity 路径独立；颜色
  采样尊重 Auto 规则。端口枚举的实际数据类型参与校验。
- 默认 Standard 的 Color 输出 Shader 保留原始颜色/UV child，另存受管理的
  Sphere bitmap child。InitRender 缓存 render-document 的材质 Morph 快照与
  相机逆矩阵；Output 只读相机空间 Phong normal，生成 UV 并应用独立 Sphere
  RGBA 运算。图片 Alpha 不进入 opacity，旧 Environment 场景保持兼容。
- 路径/模式编辑经统一 adapter 方法分派，只有唯一、归属明确的绑定允许
  更新；坏文件、被替换的 child、活动或休眠 combine 的艺术家连接均拒绝。
  保留 bitmap/sampler 的过滤参数，用整材质 Undo 快照覆盖图和容器。
- Sphere 是基础颜色运算；Standard 与 PBR 继续用自身 BRDF 打光。这一增量
  不提供 Toon ramp、Ambient 或 Additional UV 的 PBR 等效替代。

## Risks / Trade-offs

- [原生 Toon 与 MMD 的明暗规则不同] → 对照图记录差异，以用户需要的风格化场景为验收目标，保留独立 profile。
- [纹理 Morph 的既有约定未证明与原生 MMD 等价] → 版本化沿用现有规则，记录最小对照，不扩大承诺或同时改动旧材质。
- [绑定依赖仍在未提交工作区] → 实施前记录依赖文件/模块身份，新功能验证使用自己的精确构建。
- [透明轮廓、全局 contour、合并/拆分网格影响画面] → 最小图像矩阵覆盖这些组合；必要的限制进入支持说明。
- [场景多 surface 或用户修改图] → 通过 profile、角色和实际 Output 连接验证，不凭首个节点接管。
- [节点资源或插件版本不同] → 能力探测、清晰不可用状态、按宿主/渲染器组合记录原生结果。
- [GPU 显存不足中断测试] → 单独记录资源失败和已完成帧，不推断为着色正确或错误，也不使用 CPU 结果替代 GPU 验收。

## Migration Plan

1. 先在任务自有场景完成 Toon/Contour 原生图和实际图像原型，固定资产端口、近似参数及 profile revision。
2. 实现独立类型、适配和描述驱动的绑定，新增规范中要求的转换事务。
3. 打通 UI/资源/生产导入接口，新增值不改变旧值；没有自动场景升级。
4. 通过转换/Undo/Redo/保存重开/复制和图像矩阵，再更新支持文档。旧场景只有用户显式转换后才使用 Toon。
5. 用户回退通过 Undo 或重新关联保留的原材质完成；旧程序对新 profile 的支持另列版本边界，不承诺降级编辑新图。

## Validation

- 原生原型：实际安装节点、端口读回、共用/独立 Toon 方向、无 Toon fallback、不同 power、高光颜色、Contour 输出及透明切口。
- 外观：同模型固定相机/灯光/色彩管理并排比较 RS Standard、RS Toon 与可取得的 MMD 原生参考；重点比较明暗分界、脸部阴影、发丝透明和轮廓。没有 MMD 参考时记录该对照缺失，不伪造等效结论。
- 运行时：Material/Group/Flip、0/15/30/0 跳帧、重置、混合预览、渲染克隆；重复求值节点数量不增长。独立执行 GPU 与 CPU 样例。
- 转换：单条目、共享旧材质、多个选区和 multipart；准备失败回滚；一次 Undo/Redo 后立即保存重开，重复三轮。
- 兼容：至少主 SDK 2026、SDK 2024 与 R20 编译，旧类型/配置与新类型不可用分支验证。编译证据和实际宿主证据分别记录。
- 文档：更新 `material-support.md`、`material-morph-shaders.md`、`import-flow.md` 和测试说明；首版未承载的字段始终可见。

## References

以下资料核对于 2026-10-07。官方节点能力是实现依据，不能代替本插件的原生图像验证。

- [Redshift Toon Material](https://help.maxon.net/r3d/cinema/en-us/Content/html/Material%2BToon.html)：Base Tonemap、光照影响和高光分支。
- [Redshift Contour](https://help.maxon.net/c4d/2024/en-us/Subsystems/Default/Content/html/Utility%2BContour.html)：Output Contour、内侧轮廓、线宽与分辨率。
- [Texture Sampler](https://help.maxon.net/r3d/cinema/en-us/Content/html/Texture%2BSampler.html)：外部纹理的 tone-mapping UV 覆盖和颜色空间。
- [既有 Morph 设计](../../shader-driven-material-morph/design.md)及[验收记录](../../shader-driven-material-morph/validation.md)：本地依赖与历史证据边界。
