# Standard 与 Redshift 材质支持

新增的独立 `RS Toon（MMD 风格）` 类型使用原生 Toon/Contour 配方，revision 5 支持普通 UV 主贴图、Toon 明暗映射、普通 Sphere Multiply/Add 及十六个材质 Morph 输出角色。导入、当前条目转换、支持范围和实际验收状态见 [rs-toon-materials.md](rs-toon-materials.md) 及 [RS Toon 验证记录](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/validation.md)。Additional UV 默认不需要；明确使用 SubTexture 或额外 UV Morph 时提示未映射的视觉贡献。以下历史章节仍以各自注明的模块为证据边界。

插件默认导入为 Standard 材质。Redshift 使用独立的节点适配器；两者当前对齐的目标是
diffuse RGB、真实贴图 Alpha，以及材质表情的有效 RGB/Alpha 系数。
完整 MMD toon、sphere、边线和光照模型仍有差异，不能仅凭贴图加载成功判断外观已经等效。

## 当前 Matcap Sphere 增量（2026-10-07）

新建/转换的 Standard 与 RS Standard 均支持普通 Sphere/SPA 的 Multiply/Add。
RS Standard 使用原生 Matcap（World）；默认材质用相机空间法线生成 UV，
在 Color 输出内加/乘，不再把新材质的 SPA 接成 Environment 反射。
Sphere RGBA Morph 独立求值，图片 Alpha 不进入 opacity；主贴图和 Diffuse Alpha
维持原绑定契约。新 RS binding 为 profile 2/revision 1，十个字段保存于独立范围。
旧 Standard Environment 场景及七字段 RS binding 不自动改图；需新建独立材质，
RS 旧七字段 v2 binding 可通过“修复当前绑定”显式升级。路径/模式编辑保留采样设置、保护艺术家输入，并支持 Undo。

两种材质继续用各自的 Standard/PBR 表面打光，SPA 的手绘高光不是 PBR 反射；
Toon ramp、独立 Ambient、边线和 SubTexture/Additional UV 不因此获得映射。
实际原生与图片范围见 [Matcap Sphere 验证](../../openspec/changes/archive/2026-10-08-add-rs-toon-material-conversion/standard-sphere-validation.md)。

## 当前增量与历史证据的边界（2026-10-07）

- 普通 RS Standard 的创建、同步与反向读取已覆盖高光颜色和 Specular Power；
  无贴图/带贴图、外接 Shader 保护和保存重开均已原生验证。直接 PMX 创建已传递 Sphere 路径，
  该历史模块尚未增加 Sphere 着色节点。对应 Release 模块为 `d6ca05c6…`，详见
  [普通 RS 高光验证](rs-standard-specular.md)。下方旧矩阵中的“未映射高光”仅描述旧模块。
- 新版 Morph binding v2 分别保存纹理 Mul/Add，纹理 factor Alpha 参与 RGB 运算，
  opacity 为图片 Alpha × diffuse Alpha。详见 [当前 Morph 绑定说明](material-morph-shaders.md)；
  下方 `9d132…` 的合并 factor 契约保留作历史证据，不是新版实现的期望值。
- 普通 RS 高光已在独立宿主完成六张实际图片响应验收，覆盖颜色、零高光、Power 收窄、
  重复与保存重开；详见 [高光验证记录](rs-standard-specular.md)。材质验收允许任一设备。
  完整 Morph 绑定光照矩阵和 MMD 原生外观等效仍未完成。

本文区分源码已实现、原生着色器或节点已验证、实际图像已验证三个状态。
构建成功和节点连接成功都不能代替图像验收。导入与材质表情的数据链路见
[import-flow.md](import-flow.md)，剩余整体验收见 [remaining-validation.md](remaining-validation.md)。
以下支持矩阵和完整 Alpha 图像证据对应旧 `9d132…` Release 模块、`fd274…` 源码/资源切片。
后来新增的 shader binding 有独立 `26f84838…` Debug 最小闭环，范围见本文后段；
旧图像通过不能用于验收新的工作区源码或 binding。

## 旧模块 9d132 的 RGB 与 Alpha 契约

令 `D_rgb/D_a` 为合成材质表情后的 diffuse，`F_rgb/F_a` 为合成后的 base texture factor，
`T_rgb/T_a` 为同一贴图的颜色和内嵌 Alpha。带贴图材质的预期输出为：

```text
diffuse color = T_rgb × D_rgb × F_rgb
opacity      = T_a   × D_a   × F_a
```

RGB 图片没有内嵌 Alpha 时，`T_a = 1`；纹理的灰度或颜色不能作为透明遮罩。
RGBA 图片即使全部 Alpha 为 1，也属于有内嵌 Alpha 的图片。
完全没有 base texture 时，材质使用 `D_rgb/D_a`，不应用无贴图的 texture factor。
每次求值都替换完整有效系数，不继续乘上一帧的系数，也不把 runtime 结果回写基础材质数据。

`9d132…` 基线的 Standard 在颜色通道使用 Bitmap 或本插件 wrapper，Alpha 通道使用独立 Bitmap/wrapper 或纯色 shader。
颜色 wrapper 的 Alpha factor 保持 1；`T_a × D_a × F_a` 只进入透明度路径。
带 RGB 贴图的常量 Alpha shader 也必须接收 `D_a × F_a`，这一分支此前漏掉了 texture factor。

Redshift 使用 `TextureSampler.outcolor → Standard Material.base_color`，同时把同一 `outcolor`
接到 Color Splitter，再由 `outa → opacity_color`。Sampler 的 `alpha_is_luminance=false`；
RGB multiplier 与 Alpha multiplier 分别保存上述完整系数。
实际节点空间只有 RGBA `outcolor`，不能假定存在独立 `outalpha` 端口。

图片 Alpha 的原始数值与宿主当前色彩管理下的 shader 返回值需要分别记录。
例如原始 `96/255` 的 Alpha 若在采样上下文中变为其他数值，测试应查明配置和转换路径，
不能扩大容差或把 RGB 值作为预期 Alpha。`9d132…` 的中间及非均匀 Alpha 已有后述像素结果；
新 binding 和额外格式须依据各自的同模块证据判定。

本轮 Standard opacity 采样使用 `TEX_ALPHA + CHANNEL_ALPHA`（`texflag=452`），
raw/document 两档均直接断言原始图片 A 乘有效 Alpha 系数。
颜色 shader 的 `TEX_ALPHA + CHANNEL_COLOR` 探测只检查 wrapper 与其已初始化 child 的转发结果一致，
不把该上下文可能经过宿主颜色转换的值当成原始图片 A。

## 9d132 基线支持矩阵

下表描述已加载的 `9d132…` 旧 wrapper 实现，不作为后来 binding 改动的逐字段源码或原生验收结论。

| 字段或场景 | 默认 Standard | Redshift | 支持边界 |
| --- | --- | --- | --- |
| diffuse RGB，无材质表情 | Bitmap/wrapper 乘 diffuse RGB；无贴图时为纯色 | Sampler color multiplier；无贴图时为 base color | 两条导入路径均应用基础 diffuse，不要求先创建材质表情 |
| diffuse Alpha | 独立 Alpha shader 乘 diffuse Alpha | Sampler Alpha multiplier 或纯色 opacity | Alpha 不应染暗颜色通道 |
| RGBA 贴图 | 根据成功解码后的 `GetInternalChannel()` 判断内嵌 Alpha | Sampler RGBA 输出拆出 A | PNG/TGA 扩展名不再是 Standard Alpha 的允许名单 |
| RGB PNG、JPEG、24 位 TGA | 常量 Alpha 为 `D_a × F_a` | 无图片 Alpha 按 1，再乘 Alpha multiplier | 已补齐 Standard 的 opaque texture Alpha morph 分支；这些样例的两端隔离渲染 Alpha 已通过，不表示所有强度/格式组合或默认 RGB 外观通过 |
| 其他带 Alpha 的图片格式 | 宿主解码后确有内嵌 Alpha 即进入 Alpha 分支 | 依赖 Redshift sampler 对该格式的支持 | TIFF RGBA 的两端隔离渲染 Alpha 已通过；未列入矩阵的其他格式不能据此推定通过 |
| 没有 base texture | 纯色 RGB 与 diffuse Alpha | 纯色 base color 与 opacity | texture factor 不改变无贴图材质 |
| diffuse/texture RGB 与 Alpha morph | 替换 wrapper 系数；opaque texture 直接更新常量 Alpha | 替换 sampler 两组系数 | 原生采样/图矩阵验证 0、1、0.5、0、0.5 序列、重置及保存重开；隔离图与部分 Standard 默认图另有 Alpha 结果，完整 RGB 着色仍未验收 |
| PMX 与 `MMDMaterialData` 创建 | PMX 入口委托 Data 入口 | PMX 入口委托 Data 入口 | 支持字段的初始化一致；不代表两种渲染器的光照等效 |
| specular / specular power | 现有传统 Standard 近似；宽度为 `clamp(power/100)` | 当前未映射 PMX specular/power，使用默认 PBR 节点参数 | 尚无传统高光与 PBR 的等效映射 |
| ambient | sphere approximation 启用时进入 Environment 颜色 | 保留在 PMX 数据；未接入着色节点 | 不能把环境色直接替换为发光来宣称等效 |
| toon 纹理与 factor | 保留 PMX 元数据；未实现光照驱动的 toon ramp | 保留 PMX 元数据；未接入 toon 着色 | 新材质不把 toon 接到 Luminance |
| sphere None / SubTexture | Environment 关闭 | 保留 PMX 元数据 | SubTexture 的 additional UV1 未实现 |
| sphere Multiply / Add | 使用既有 Environment 近似 | 保留 PMX 元数据；未构建 sphere 节点 | 未实现两端准确一致的 MMD multiply/add 运算 |
| edge、double face、shadow、vertex color | 字段持久化，部分使用宿主默认行为 | 字段持久化，部分使用宿主默认行为 | 尚未逐项对齐实际渲染效果 |
| 用户发光设置 | 旧 toon-as-Luminance 仅做保守、一次性迁移；自定义或重新启用后保留 | 不做 toon-to-emission 迁移 | 后续修复须保留既有用户保护 |
| 修改贴图路径或 RGB↔RGBA 切换 | 现有 wrapper 不更新 child 文件名，Alpha 分支也不会随路径重建 | 现有 sampler 只更新系数，不更新 URL | 已确认后续缺口，本轮尚未修复 |
| shader / node 所有权 | 可识别本插件 wrapper；尚无独立 diffuse 链登记 | sampler/splitter 有稳定 ID；surface 当前仍按首个资产匹配 | 自定义、多节点和旧场景迁移不能据此声称安全完成 |
| SDK / 宿主可用性 | 传统材质实现用于兼容 SDK | 当前节点实现受 `API_VERSION >= 2024000` 条件约束 | 旧 SDK 编译通过不代表其 Redshift 节点功能可用；对应宿主与 Redshift 运行环境需单独验收 |

`9d132…` 检测在文件存在但解码失败时仍保留 `has_texture=true`，没有统一的坏图片诊断或替代材质策略。
这类情况不能归入“没有贴图”的通过样例。

## 9d132 原生与实际图像证据

| 验证层 | 已有事实 | 仍未证明的范围 |
| --- | --- | --- |
| 旧模块原生 shader/graph | 普通 Release `97b6…` 的 [Standard 收据](../../_build_msvc/validation/remaining/material-97b6/standard-material-receipt.json)、[Redshift 收据](../../_build_msvc/validation/remaining/material-97b6/redshift-material-receipt.json) 与 [manifest](../../_build_msvc/validation/remaining/material-97b6/manifest.json) 保留原始身份和结果 | 不是本轮新增内嵌 Alpha 检测、opaque texture Alpha morph 或最终图像的通过证据 |
| 本轮构建 | 主任务已报告 `fd274…` 源码切片的 SDK 2026 Debug 与 R20 Debug 构建成功 | 编译不能证明 Alpha 采样和画面正确；完整身份以本轮构建收据为准 |
| 宿主图片解码探测 | C4D 2026.4 实际 RGB PNG 无 internal Alpha、channel count 0；RGBA PNG 有 internal Alpha、channel count 1 | 证明新检测使用的接口能区分这两个样例，不证明其他格式和材质渲染 |
| 本轮 Standard 原生采样 | [Standard 矩阵收据](../../_build_msvc/validation/remaining/material-alpha-9d132/standard/standard_matrix_receipt.json) 为 `passed`，10/10 样例；raw/document 两档采样、PNG/JPEG/TGA/TIFF/无贴图、中文相对路径、重复系数、保存重开及重置均执行 | `native_shader_sampling=true`、`full_image_render=false`；不证明默认材质的最终图像或完整光照等效 |
| 本轮 Redshift 原生图 | [RS 矩阵收据](../../_build_msvc/validation/remaining/material-alpha-9d132/redshift/redshift_matrix_receipt.json) 为 `passed`，10/10 样例；节点、RGB/Alpha 系数、连接、路径、保存重开及重置均执行 | `native_graph_inspection=true`、`native_shader_sampling=false`、`full_image_render=false`；不能据图连接推定实际采样或遮罩像素通过 |
| Standard 隔离通道图 | [render-summary](../../_build_msvc/validation/remaining/material-alpha-9d132/render-summary.json) 及 [Standard 原图/收据](../../_build_msvc/validation/remaining/material-alpha-9d132/render-standard) 中 10/10 为 `passed`，覆盖 Alpha 0/1、非均匀 Alpha、变化 RGB/固定 Alpha、RGB 无 Alpha、PNG/JPEG/TGA/TIFF 和无贴图；指定样例保存重开 | `isolated_channels` 的 Alpha 像素结果，不是默认 RGB/BRDF 外观验收 |
| Redshift 隔离通道图 | 同一汇总及 [RS 原图/收据](../../_build_msvc/validation/remaining/material-alpha-9d132/render-redshift) 中 10/10 为 `passed`，覆盖同组样例和指定重开 | 已超过节点连线检查，实际 Alpha 图通过；RS 默认材质图在这个模块尚未验收 |
| Standard 默认材质 Alpha | 4/4 为 `passed`：`alpha_full` strength 0、`gray_varied_alpha` strength 0.5 并重开、`varied_rgb_fixed_alpha` strength 0.5、`rgb_without_alpha` strength 1 并重开 | 判定 Alpha，未接受完整默认 RGB 外观；`default_rgb_visual_acceptance=false` |
| 默认 RGB 与完整外观 | 汇总保留 `default_rgb_visual_acceptance=false` | 两端默认 RGB/光照效果、完整 toon/sphere/边线仍需独立验收；这些 24 张旧图不验证新 binding |

两个采样/图矩阵及输入、保存场景和最初校准图的逐文件来源/字节数/SHA-256 见
[归档清单](../../_build_msvc/validation/remaining/material-alpha-9d132/collection-material-fidelity.json)。
完整渲染汇总另列 94 个归档文件，并记录上述 24 份图像/原始收据的 SHA-256。
[render-summary 单独清单](../../_build_msvc/validation/remaining/material-alpha-9d132/collection-render-summary.json)
补充登记主任务本地生成的汇总文件；原始 native receipt 的 `full_image_render=false` 保留原值，
后续 render 成功由独立 render receipt 证明，不回填或改写旧 receipt。
离线核对 94 个引用文件和 24 组 receipt/image 的 hash 一致，所有记录为 `passed`；
已记录像素的最大 Alpha 绝对误差为 `0.0005882352941178892`，原 oracle 容差为 `0.025`。
这次核对只读取本地证据，没有新宿主调用或重新渲染。
两个 run 的 finally cleanup 均为零错误、零剩余所属文档，并恢复原文档。
原始矩阵收据自身未记录 loaded module 或源码/资源指纹；主任务将本轮运行关联到 `fd274…` 源码与
`9d132…` Release 模块。独立 [原生上下文](../../_build_msvc/validation/remaining/material-alpha-9d132/native-context.json)
记录同一持续运行的 C4D 2026.4 进程、实际 loaded module 以及两份矩阵收据的 SHA-256；
[manifest](../../_build_msvc/validation/remaining/material-alpha-9d132/manifest.json) 保留普通 Release、
runtime regression OFF 的准备身份。两者及原始收据的引用 hash 已在归档时互相核对，未修改原收据。
渲染汇总关联同一旧模块/源码和独立 native context，并记录各 receipt/image 的原始 SHA-256。
原始单图 JSON 不含 loaded-module 字段，不把汇总关联写成单图收据自带的身份证明。

```text
loaded module: 9d132206fc577f55f3f487f3d1fe84ac5dc2a5562d9ef9f226a626f400771a34
source/resource fingerprint: fd274ec97729be2512e38c7a5290b02ad27f36078acf90bbcde6a3009f8482c1
```

已完成的旧图矩阵覆盖 Alpha 为 0/1/中间值和空间非均匀 Alpha、RGB 与 Alpha 不相关，
以及无 Alpha 的彩色/灰度图片。贴图 RGB 变化而 Alpha 不变时，opacity 必须保持；
Alpha 变化而 RGB 不变时，只应改变遮罩覆盖率。
实际图像需记录宿主版本、插件模块、源码/资源指纹、渲染器、色彩管理、采样位置和允许误差。
隔离着色路径的诊断图用于定位 RGBA，不作为完整默认材质外观对齐的结论。
本轮矩阵的有效系数控制在 0–1；图像预期最后限制到 0–1，未据此验收任意超范围 morph 值。

## 新 shader binding 的独立最小闭环

后来 shader-driven 实现的 [minimum-receipt.json](../../_build_msvc/validation/shader-driven-material-morph/minimum-26f84838/minimum-receipt.json)
对应 SDK 2026 Debug 模块 `26f84838f7171521381330fea72fe801b25a48cf6883ab466f27dc935d40b0c2`。
这是与 `9d132…` 分开的双材质最小样例：一个模型包含 plain/RGBA 两种材质、两个 Material Morph、Group 与 Flip。
具体实现与验收边界见已归档变更的 [validation.md](../../openspec/changes/archive/2026-10-08-shader-driven-material-morph/validation.md)。

独立 [Standard sampling](../../_build_msvc/validation/shader-driven-material-morph/minimum-26f84838/standard-sampling.json)
记录 base、add、add/mul、Group、Flip、reset 六组状态；实现方还记录线性强度轨道第 15 帧的原生检查。
最小图像收据列五张实际 RGBA 图及像素/hash：Standard 第 0/30 帧内部 Alpha 分别为 `[128,48]` 与 `[153,72]`；
Redshift 默认材质第 30 帧为 `[153,72]`，隔离图第 0/30 帧分别为 `[128,48]` 与 `[153,72]`。
本任务只读核对了这五张图片的 hash，未运行该宿主或修改其收据。

这一闭环证明指定新 binding 样例的 shader/原生 reader 能随动画读到有效值，不是新功能全面验收。
完整默认 RGB/BRDF 外观、完整图像矩阵、preview authoring、旧场景迁移、Undo/Redo、保存重开、复制隔离与兼容构建仍待该实现独立完成。
该目录的通用 [receipt.json](../../_build_msvc/validation/shader-driven-material-morph/minimum-26f84838/receipt.json)
仍为 prepare 时的 `pending_native_runtime`；它不能覆盖、替代或扩展最小图像收据的已验范围。

## 路径同步与旧场景迁移的后续验收

下列是 `9d132…` 未完成的范围；新 binding 的最小闭环尚未验收这些迁移场景。
拟验证的新 Standard 材质单独登记 diffuse 链及 Bitmap/Alpha shader 的链接，
新 RS 材质登记创建时选定的 surface、sampler 与 splitter。更新前验证节点类型、原始连接和文件路径，
不再通过任意首个 Standard 节点定位所有权。

旧场景只能在完整符合既有导入链结构、唯一 surface 和匹配文件路径时登记所有权。
自定义、多节点、模糊或部分损坏的图保持原样，不凭名称或单一节点类型接管。
明确换贴图时保留颜色配置与过滤参数，只更新所属 Bitmap/URL，并按实际内嵌 Alpha 重建所属的透明度分支。
路径同步、旧场景迁移与完整 toon/sphere 是分别需要验证的工作，不能与旧 Alpha 图或新最小闭环合并算作完成。
