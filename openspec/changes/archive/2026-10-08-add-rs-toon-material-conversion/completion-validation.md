# RS Toon revision 5 最终验收（2026-10-08）

本轮完成 `add-rs-toon-material-conversion` 剩余任务。结论针对下面的
Release 模块和固定条件；MMD 原生像素等价、MME、逐顶点 edgeMag、独立
Ambient、完整 PMX 阴影标志和 SubTexture 着色仍不属于这个 profile 的完成声明。

## 模块与证据

- C4D 2026.4.0（2026400），Redshift 2026.9.0。
- SDK 2026 Release，`CMT_ENABLE_RUNTIME_REGRESSION=OFF`。
- 最终模块 SHA256：`74ee51a548e2ddc4cb7d86159b87975fe79074989eba484f70b72438d7675e6c`。
- Profile v1，binding version 2，graph revision 5：40 个固定角色、16 个网格属性。
- 证据目录：`_build_msvc/validation/rs-toon-material/completion-20261008-74ee51a5/`。
- `contracts/receipt.json`：正式接口、原生 UI 描述/按钮、图保护。
- `native/receipt.json`：三种材质的基础参数自动联动与 Sphere 兼容回归。
- `faults/receipt.json`：四个真实失败注入点、歧义分配、不可用宿主和 Undo/Redo。
- `visual/receipt.json`、`visual/pixel-analysis.json`：8 个成功独立宿主批次，
  56 次实际渲染，51 张去除重复 preview/full 命名的图像，38 组比较。
- `specular/receipt.json`、`specular/pixel-analysis.json`：另两次保存重开后的
  六球 GPU/CPU 渲染与高光分析。
- `cold-page/receipt.json`：新进程未预热能力缓存时读取实际模型材质页。

失败注入使用单独的显式 regression Release 构建，SHA256
`fe3013e81ffe7cb603169d06c4a02473954abb64e64bdbb463c7c8e4c9d17092`。
以 `faults/receipt.json` 的实际加载路径和 hash 为准；这不是生产图像模块。
最终生产模块原生验证了相同私有 flag 不会禁用 Toon，测试控制已编译移除。

## 类型、图与使用入口

旧类型数值 0～3 保持不变，RS Toon 追加为 4。原生保存重开覆盖 0～4 与
未知持久化值 99；未知值不创建其他材质。默认 Standard 的映射保持不变。
未知值通过直接写入序列化容器模拟，不能要求原生 Cycle 控件输入菜单外值。

从条目创建和正式 PMX 导入得到相同 Toon 路径及图角色。能力查询前后的
材质、链接、分配、网格属性与渲染设置一致。两个 surface、两个 output、
删除必需 `toonmaterial.base_color` 输入端口、缺失 Matcap 角色和错误
Contour 资产均停止自动驱动并保留艺术家图。普通 Standard、RS Standard
与 Toon 的基础参数/Sphere 回归分别通过。

原生描述与按钮检查覆盖 EDIT/ANIM、预览门控、旧选择持久化、中英文资源、
类型创建和支持原因。冷缓存读取保持 `will be checked`，未触发图探测；
读取 first/stockings/last/no-selection 保留材质数。这里记录的是原生
描述/参数回调和按钮行为，未将其称为新的 GUI 手工切页复现。

正式接口支持 `redshift_toon`。不可用宿主不广告该能力；启用材质导入
返回 `unsupported_renderer` 且场景保持原样。禁用材质时，合并及拆网格
均可导入模型并保存重开，不需要 Toon 能力。不可用宿主由 regression
构建模拟，不能据此声称已运行所有旧版本 RS。

## 回滚修复

在属性分配完成、绑定完成、第一次 Tag 切换和模型链接切换四处注入失败。
每次都读回注入标记，并比较材质、Tag、User Data 和模型链接的完整测试
签名；全部恢复。重复的匹配选区被拒绝。成功转换三轮 Undo/Redo，每一步
在求值前立即保存并重开，实际分配、profile、材质数与源材质保留状态一致。

测试还发现 Undo 会替换模型节点实例。向启动事务的旧实例写诊断会丢失
错误原因；转换现在通过稳定 BaseLink 找到恢复后的实例再发布诊断。
四个失败点均保留对应 `Injected ...` 原因。

## 图片矩阵与校准

所有图使用一个方向光、GI 关闭、16/64 samples、denoise 关闭。
材质与输入采样使用 Auto；导入不修改用户文档色彩设置。记录的实际文档
参数为 `DOCUMENT_COLOR_MANAGEMENT=1`、`DOCUMENT_LINEARWORKFLOW=1`、
`DOCUMENT_COLORPROFILE=0`；Bake OCIO render 参数未显式设置，原生读回为
`None`。图片是 RenderDocument 的 8-bit Bitmap 导出，不宣称已经验证与
RenderView 显示变换或 MMD 显示管线等价。

- Material/Group/Flip 轨道按 0/15/30/0/30/15/0 重复求值。Tint 有效值
  0/.7/.9，Multiply 为 0/.75/.25；Diffuse、Alpha 和 roughness 都与独立
  预期相符，重复图像及属性复现，40 角色稳定。
- 混合 preview 通过真实渲染克隆；关闭和重开重置画面。求值及渲染期间
  有一个无 MMD 模型、时间为 99 帧的其他文档处于激活状态，目标文档
  保持自己的状态。预览克隆不冒充磁盘 preview 持久化。
- 纯色/嵌入 Alpha 两个面片的 opacity 为基底 128/48，15 帧 145/55，
  30 帧 150/57（8-bit，允许量化差）；图片 Alpha 与 factor Alpha 分离。
- 默认无 Toon 是白色中性 Ramp，并绕过 Toon factor；明确引用但不可读
  的 Toon 使用 .3→1、位置 .5 的回退并给诊断。垂直光照域取样和 .5 偏移
  保持 revision 5 规则，不以普通 UV 替代 Toon 光照域。
- Contour 厚度 1024、modifier `max(edgeSize,0)*3/1024`，1080p 为参考。
  关闭、零宽度、增宽、零 Specular、全局默认 Contour 与两个网格布局均
  渲染验证。默认全局材质给未管理球体绘出 225 个品红像素，证明全局
  Contour 真正生效；受管理条目关闭仍保持关闭。
- 宽度由 1 增至 3，合并布局线条影响像素由 885 增至 1155，拆网格由
  978 增至 1409。线位于几何轮廓内部，与反向外扩 MMD shell 不同。
- 合并/拆网格在 edge-off、zero-width 和 global-off 时完全一致；开启
  描边时有 149～351 个超过 2 的 RGB 差异像素，集中在描边区域，区域外
  最大差不超过 2，Alpha 相同。原生 Contour 按对象轮廓计算，不承诺不同
  网格划分的线条像素完全一致。
- 生成样例 CPU/GPU 比较最大 RGBA 差不超过 2；实际丝袜最大 RGB 差 3、
  Alpha 差 1，平均 RGBA 差约 .0109 个 code value。实际 PMX 的允许边界
  明确为 3/255，并未写成像素相同。

高光使用连续 `linearknot` 黑白 mask，Fresnel 关闭、weight=1、indirect=0，
`roughness=(2/(max(power,0)+2))^0.25`。零 Specular 无对应亮斑。Power 8/64
下，导出蓝通道超过基底并按自身峰值归一化后的 10%/25%/50% 面积分别为
1483/811/421 与 655/469/363；软外沿变窄，GPU/CPU 最大 RGBA 差为 1。
Power 64 峰值更亮且有 8-bit 饱和，高阈值面积不保证同样单调；这是导出
亮斑校准，不是未裁剪 HDR lobe 测量，更不是 MMD Phong 的强度等价证明。

## 实际阿芙对照

使用 `C:\白银之城—阿芙2.0\阿芙2.0.pmx`，相同单方向光
(.25,-.65,1)、相机和输入 Auto 规则，分别导入 RS Standard 和 RS Toon。
`visual/comparison-full.png`、`visual/comparison-stockings.png` 并排展示
实际全身及丝袜。两种材质均有 GPU/CPU、保存重开后的结果。

观察：Toon 脸部较明亮且分层明确，Standard 的丝袜亮带连续、脸部更暗。
Toon 丝袜仍有较明显的原图分段，球面贡献在 Toon 前运算后会被明暗段
压缩；不能把 Specular 为零时的 Sphere 亮带当作 Specular 高光。细发丝
和衣裙透明区域仍可见，轮廓相对 MMD 外扩式描边细且受内侧限制。

用户提供过 PmxView 截图，但没有匹配此相机、方向光、曝光和显示变换的
MMD 原生参考。这里仅完成 RS 两种材质的同条件对照，MMD 同条件参考仍缺失。

## 构建、自动检查与失败尝试

SDK 2026/2024/R20 Release 全部构建通过，三者 regression 开关均为 OFF；
2024/R20 是编译和资源证据，不声称在对应宿主执行了 Toon。独立 Debug
逻辑/fixture/MCP CTest 19/19 通过。严格 OpenSpec 与额外验证按用户 2026-10-08 的明确要求跳过，不报告通过。

之前的资源错误、长批次停止产出、空 guard 文档被 C4D 自动关闭，以及
全局 Contour 对照未恢复 Specular 的脚本错误都保存在 `attempts/`；它们
不进入通过的 8 个矩阵宿主收据。脚本已为 guard 添加非模型对象，逐帧
显式释放重开的文档，并按设备/组串行运行。部分资源错误与并发 C4D
测试重叠；没有仅凭通用错误码认定某个驱动或显存为唯一根因。

Rider 附加了任务自有宿主，但 Release 首处断点没有可执行行信息，随后
显式暂停超时；未取得栈/变量，不作为根因证据。调试会话及自建断点已
清理，原生失败标记和修复后的读回构成回滚诊断修复的证据。
