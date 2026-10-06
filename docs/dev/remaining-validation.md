# 剩余验收与分阶段执行

本文覆盖真实模型连续物理、重建后重放、运行成本、其余 Windows SDK 编译和实际安装包。
`scripts/c4d_extended_validation.py` 只准备可调用的原生阶段；导入模块不会启动测试、修改场景或运行构建。
主任务统一持有 C4D / MCP / 构建窗口，避免在插件被加载时覆盖二进制。

2026-10-06 当前边界：普通 Release 的生产 MCP 八阶段已通过；Standard/Redshift 各十张隔离 Alpha 图、
Standard 四张默认材质 Alpha 图已有实际渲染证据。真实阿芙的严格 seek 重放仍未通过。
后续材质预览/升级正由并行任务实施；下列验收针对明确冻结的模块，不代表持续变化的工作树。

## 本轮最新切片

| 范围 | 当前结果 | 证据 |
| --- | --- | --- |
| Windows 普通 Release 生产 MCP | setup/discovery/model/motion/camera/invalid/lifecycle/cleanup 全部通过，回归桥 OFF、原文档恢复、所属文档清理完成 | [最新 receipt](../../_build_msvc/validation/remaining/production-no-contact-default/native-run/receipt.json)，模块 `38c9aa87…`，源码/资源 `20033573…`；manifest 含维护依赖源码与实际选定静态库身份 |
| Standard/RS Alpha | 两端各 10 个隔离通道图像通过；Standard 另 4 个默认材质 Alpha 图像通过 | [24 图汇总](../../_build_msvc/validation/remaining/material-alpha-9d132/render-summary.json)，旧模块 `9d132…` / 源码 `fd274…`；不证明默认 RGB 外观等效，也不证明后续新绑定已验 |
| 新 Shader/User Data 最小闭环 | 由并行材质任务独立验证 Standard 与 RS 的最小原生采样/动画/渲染范围 | [独立 minimum receipt](../../_build_msvc/validation/shader-driven-material-morph/minimum-26f84838/minimum-receipt.json)，Debug `26f84838…`；面板、升级和后续编辑不自动取得同等验收 |
| 原配置物理 0–60 seek | 625 根骨骼和 70,222 个网格点有限；完整 reference/seek 严格比较失败 | [本轮物理 receipt](../../_build_msvc/validation/remaining/production-no-contact-default/real-physics/receipt.json)：骨矩阵最大差 `0.6453483637052126`、末帧点坐标最大差 `0.2928073833725402`；容差仍为 `1e-4` |
| 接触排序候选 | libMMD 配置与接触缓存保留测试通过，但原模型短重放失败；插件默认启用已撤销 | [候选原生证据](../../_build_msvc/validation/remaining/production-408695/short-physics/variant-A-receipt.json)，不把关闭碰撞或放宽容差当修复 |

固定测试工程为 `_build_msvc/validation/material-morph-debug-test.c4d`。
设置真实文件名/目录后保存并检查 changed 状态；运行时求值可能再次使文档变脏。
关闭前保存最新任务结果，只清理 exact-owned 测试文档，避免丢失工程或累积未命名文档。
SDK Debug、普通 Release 构建目录及 native 5556 访问按任务协调交接。

离线最终复核见 [独立收集收据](../../_build_msvc/validation/remaining/offline-final-20261006/receipt.json)：
运行时 Python 48/48、材质 20/20、适配器 35/35，统一 `cmt-plugin-tests` 的 13/13 测试组通过。
该目录保留最初两项旧 fixture 失败及修正后的日志、候选物理测试和构建日志；
候选配置/接触缓存测试通过不改变真实物理重放失败的结论。

## 已有证据基线

2026-10-06 可查的验证产物位于 `_build_msvc/validation/real-assets-and-materials/`。
其中 `native/manifest.json` 对应的 SDK 2026 Debug 模块为
`62f2b1361ba3ac84571bed19ab37dd83a0e2546d8ca3aee371b64dbe9e7fed9a`，源码与当前资源树指纹为
`587f461fe080c9cce3bca8ebe0c7f0a4f818211dca1fe489ffa728e78c182bc9`。
该二进制已有九项合成原生回归、真实阿芙/枪/箱子，以及真实动作和相机回归。
真实动作之前关闭物理并选择少量帧求值，因此不构成阿芙连续物理或性能验收。

如果其他实现同时修改 `source/`，本页的历史指纹不会自动代表新代码。
扩展回执分别记录实际加载模块、准备 manifest 的源码指纹和运行时工作区源码指纹。
`acceptance_eligible` 对应回执中标识的模块；`current_source_accepted` 还要求运行结束时工作区源码与
manifest 一致。新二进制应完成构建、重新准备 manifest、正常启动 C4D 后再运行。

### 较早切片收据的持久副本

以下目录位于 `_build_msvc/validation/remaining/final-evidence/`。
`collection-material-fidelity.json` 保存来源、目标、字节数和逐文件 SHA-256；归档时所有文件与原件一致。
原始 JSON 中的 `S:\tmp` 路径、manifest 身份和 pass/fail 都保留，不能为了归档改写验收结果。

| 目录/收据 | 实际证据 | 仍未证明的范围 |
| --- | --- | --- |
| [bone-4b670/bone-display-receipt.json](../../_build_msvc/validation/remaining/final-evidence/bone-4b670/bone-display-receipt.json) | 普通 Release 模块 `4b670c890d950842f39c1fe818c23d806edfe27b51fcdfcbb36368dbdf3279ed` 的 focused 骨骼显示断言完成，包括默认 OFF、控制器生成、各显示模式保存/重开、复制隔离、新骨骼、EDIT/ANIM 及姿态/网格保持 | 不表示该目录的九项通用回归已经重跑；`receipt.json` 是 prepare 时生成的 pending 收据，应与 focused 收据分开读取 |
| [production-49d331/receipt.json](../../_build_msvc/validation/remaining/final-evidence/production-49d331/receipt.json) | 普通 Release、回归桥 OFF 的真实 HTTP/stdio 初段；导入和 Undo 已执行 | 一次 Redo 未恢复模型，`acceptance_eligible=false`；后续生产阶段未通过 |
| [production-49d331/cmt-undo-observe.json](../../_build_msvc/validation/remaining/final-evidence/production-49d331/cmt-undo-observe.json) | 补充 Undo/Redo 探测：含材质时首次 Redo 只恢复材质，第二次才恢复模型；不导入材质时一次 Redo 可恢复 | 探测缩小事务问题范围，不能代替完整 runner 通过 |
| [physics-4b670/receipt.json](../../_build_msvc/validation/remaining/final-evidence/physics-4b670/receipt.json) | 真实阿芙 reference 与 seek 都完成 0–60 帧并保存轨迹 | seek 最大骨矩阵差 `0.6453483637052126`、末帧点坐标差 `0.2928073833725402`，严格重放仍失败；后续重开、物理开关配对和控制器 smoke 未执行 |
| [rider-no-paused-values/summary.json](../../_build_msvc/validation/remaining/final-evidence/rider-no-paused-values/summary.json) | Rider attach/pause、状态和 stack/threads 请求的原始结果 | 未取得暂停位置、调用栈或运行时变量值，不能认定物理漂移或 Message 路径的运行时根因 |
| [adapter-review/review.md](../../_build_msvc/validation/remaining/final-evidence/adapter-review/review.md)、[最终 fixture 日志](../../_build_msvc/validation/remaining/final-evidence/adapter-review/adapter-unittest-final-p2.log) | 独立源码/适配器 review；最终 Python fixture 35/35，通过提交后导出校验、null 请求 ID 拒绝及 completed-success 结果字段/状态恢复校验 | 不调用真实 C4D，不证明 Undo/Redo 或其他原生业务修复 |
| [resource-fixtures](../../_build_msvc/validation/remaining/final-evidence/resource-fixtures) | 真实 pinned installer 输入 6/6、runtime resource 9/9，通过日志已保存 | 不表示实际 ISCC 安装包、全 SDK 发布矩阵或安装/卸载完成 |
| [primary-build-audit.json](../../_build_msvc/validation/remaining/final-evidence/primary-build-audit.json)、[primary-builds](../../_build_msvc/validation/remaining/final-evidence/primary-builds) | 最终冻结源码的 SDK 2026 Debug/Release 候选和 R20 Debug 编译、真实资源副本与当前五个 MCP 运行文件身份 | 三个候选均未做本轮原生加载验收 |
| [candidate-prepare/receipt.json](../../_build_msvc/validation/remaining/final-evidence/candidate-prepare/receipt.json) | 最终候选 fixture manifest 和 prepare 结果 | `pending_native_runtime`、`native_executed=false`、`acceptance_eligible=false`；不能把准备成功写成原生通过 |
| [sdk-2024-compat/sdk_2024-Debug-receipt.json](../../_build_msvc/validation/remaining/final-evidence/sdk-2024-compat/sdk_2024-Debug-receipt.json) | SDK 2024 的 durable 兼容片段配置及最终源码 target 编译通过，原始失败和 compiler probe 同目录保留 | 只验证本机 MSVC 19.38.33145；不证明其他编译器/平台或对应旧 C4D 的原生运行 |
| [sdk-builds/final-matrix.json](../../_build_msvc/validation/remaining/final-evidence/sdk-builds/final-matrix.json) | 其余六个 SDK 的最终 Debug configure/build 均为 0，统一 `460e…` 冻结源码前后稳定，真实模块身份及资源副本已记录 | 对应版本 C4D 未运行；不表示全 SDK Release 发行矩阵通过 |

Standard/Redshift 材质旧模块 `97b6…` 的持久结果位于
`_build_msvc/validation/remaining/material-97b6/standard-material-receipt.json` 和
`redshift-material-receipt.json`，其 manifest 身份保持不变。
这些是原生 shader/节点及参数验证，不能代替完整 MMD toon/sphere fidelity、最终图像或新候选模块验收。

该历史切片的 C++ 源码/资源冻结指纹为
`460e009c6eb08b3e363668b3c83ed6d3b03432786fd21f15927d92b3eab78a2a`。
该候选包含延后登记 PMX Undo 及动画槽选择前记录文档时间/范围的修订。SDK 2026 Debug、独立目录普通 Release
和 R20 Debug 的最终增量构建已成功，尚无候选模块的原生 Undo/Redo 通过记录。
当时 C4D 原生窗口受锁定桌面和模态窗口影响，未能加载该候选重跑；编译结果不能代替加载和测试。

三个主构建的模块 SHA-256 与源码指纹分别标识，不能互相替代：

| 构建 | 实际模块 SHA-256 | 原生候选验收 |
| --- | --- | --- |
| SDK 2026 Debug | `44a5c52b0672b67c6b02428cc0b45e44cc143e62337c6ad345d728806cc3e13a` | 未执行 |
| SDK 2026 普通 Release 独立候选 | `f9c88eeb47a6c6319ee4d640a17d72d41849838d8e896d55178bfb1ed0f0bcc7` | 未执行 |
| R20 Debug | `38130a83c66c2abb8ca33458418359e2efec6fc124ad1885b205f038d6adeaa6` | 未执行 |

审计分别确认 73 个真实资源副本文件、有效配置以及五个 MCP 运行文件与当前 35 fixture 版本逐字一致。
最终适配器修订没有改变 C++ 冻结指纹；候选仍需通过真实 host 验收。

## 真实阿芙的连续物理与重放

输入来自 `motion-inventory.json`，不修改用户提供的 PMX/VMD 或贴图。
默认使用阿芙和 Stay Tonight 动作，文档为 30fps，窗口为第 0–60 帧。
脚本根据非静态刚体的 `RIGID_RELATED_BONE_INDEX` 找到实际参与模拟的骨骼，读取这些骨骼的原生世界矩阵。
刚体管理器中的作者对象矩阵只检查有限值，不用来证明 Bullet 已参与模拟。

初始化一个任务专用验证对象：

```python
import runpy
ns = runpy.run_path(r"C:\code\C4D_MMD_Tool\scripts\c4d_extended_validation.py")
validation = ns["ExtendedNativeValidation"](
    manifest_path=r"C:\code\C4D_MMD_Tool\_build_msvc\validation\real-assets-and-materials\native\manifest.json",
    inventory_path=r"C:\code\C4D_MMD_Tool\_build_msvc\validation\real-assets-and-materials\motion-inventory.json",
    output=r"S:\tmp\cmt-extended-validation",
    end_frame=60,
)
```

每个代码行作为独立 MCP 请求执行。连续阶段每次最多十帧，默认五帧和三十秒软预算；重复调用
`advance()` 直到返回 `complete=true`，不要把全部循环装进单次 MCP Python 请求。
时间预算在完整帧之间检查，无法中断单次 `ExecutePasses()`；如果单帧已接近工具时限，改为一次一帧。

```python
validation.prepare_run("reference", origin="fresh", physics=True)
validation.advance(max_frames=5, max_seconds=30.)  # 重复独立请求直到完成
validation.save_completed_scene()

validation.prepare_run("seek_replay", origin="seek", physics=True)
validation.advance(max_frames=5, max_seconds=30.)  # 同样完成 0..60
validation.compare_runs(candidate="seek_replay")

validation.prepare_run("initial_reopen", origin="initial", physics=True)
validation.advance(max_frames=5, max_seconds=30.)
validation.compare_runs(candidate="initial_reopen")

validation.prepare_run("end_reopen", origin="saved", physics=True)
validation.advance(max_frames=5, max_seconds=30.)
validation.compare_runs(candidate="end_reopen")

validation.prepare_run("physics_disabled", origin="initial", physics=False)
validation.advance(max_frames=5, max_seconds=30.)
validation.verify_physics_participation()
validation.check_control_delta()  # 已有 linked controller 的固定帧 smoke

validation.finalize()
validation.close()  # 仅关闭此对象创建的测试文档
```

三种重放有不同的意义：

- `seek_replay` 在同一个已完成连续播放的物理世界跳回零帧，依赖 seek reset 后重新顺序播放。
- `initial_reopen` 读取零帧持久化输入，在新 runtime 中重新从零帧开始。
- `end_reopen` 读取六十帧保存的场景，使用同一 frozen bind、VMD、刚体/关节配置重新从零帧开始。

脚本不会声称六十帧的 Bullet 实时 world 已被存档保存，也不会将重开后的第一帧直接与原 live world 比较。
对比对象是从相同初态重新连续播放得到的所有动态骨骼矩阵和末帧完整蒙皮顶点，默认容差为 `1e-4`。
读取非活动文档的旧 deform cache 不能代替求值；每次取几何前都先激活并完整求值对应测试文档。

连续阶段检查全部骨骼矩阵和完整蒙皮顶点有限、网格顺序/名称/数量/连接关系一致，并记录每个相邻帧的
最大动态骨骼位移。硬性连续性保护界限为一个完整模型空间尺度，旨在发现明显发散；细小抖动、碰撞穿透、
衣物形态和艺术效果仍需视觉评估。相同输入和模块的重放对比能发现 seek 或恢复路径的状态漂移。
启用/关闭物理的配对结果还必须在实际动态骨骼上出现差异，否则不能判定物理参与了运行。

`check_control_delta()` 只使用已存在且可移动的 linked controller，优先选择非 fixed-axis 控制器；
它暂时关闭物理，在零帧验证 identity、阈值内微量、实际非零 transform、归零的骨骼世界矩阵，
并检查完整求值几何有限。它会恢复选中控制器的 relative/frozen PRS、原时间、物理开关和活动文档。
本阶段不创建控制器，也不依赖骨架的 viewport 显示；没有 eligible link 时明确报未通过。
应放在全部连续重放之后执行，避免控制器 smoke 的临时 seek 改变尚未采集的物理世界。

### 62f2 模块的首次扩展结果

真实阿芙的 reference、seek 和重开运行均完成第 0–60 帧，625 根骨骼及完整蒙皮顶点有限，
实际识别出 444 根非静态刚体关联骨骼。两次完整重新导入相同 PMX/VMD 的 fresh 运行，
所有动态骨骼矩阵和末帧完整顶点差均为 `0`，因此当前严格重放要求具有有效参考。
但 seek 重放最大骨矩阵分量差为 `0.5530971585`、末帧点坐标差为 `0.2819550499`；
initial scene 重开重放分别为 `0.5795603229` 和 `0.2439363209`。
这些路径尚未通过；有限值和连续播放本身不能替代重放验收，容差没有放宽。

seek 与 reference 的零帧骨矩阵差约 `1e-9`，首个模拟帧已有显著差异；
initial-reopen 的首帧差约 `4.9e-6`，第二帧开始放大。
插件正在补充冷物理 world 的 reset：仅清刚体速度/力不足以清除 world 的接触、约束和子步历史。
重新创建刚体/关节时先用 bind-space adapter 缓存构建 anchor，再恢复当前动画姿态，避免改变持久 bind。
随后较早的正常 Release 模块的冷 world 重建已运行，但 seek 重放仍未通过：最大骨矩阵分量差
`0.5112690581`、末帧点坐标差 `0.0733487352`，与此前 end-reopen 路径一致。
reference 与 seek 的全部 bone bind、rigid/joint 物理数值输入完全相同。
identity control 的 float basis 投影可能引入依赖前次同步姿态的微小旋转；
后续 `4b670…` 模块已经包含以既有 inactive-control 判断直接跳过零 delta 的候选，
其完整 reference/seek 原生重跑仍失败：最大骨矩阵分量差为 `0.6453483637052126`，末帧点坐标差为
`0.2928073833725402`，容差仍是 `1e-4`。因此不能声称 inactive-control guard 已修复物理重放。
该轮在 compare_seek_replay 失败点停止，没有执行 linked-controller smoke、物理开关配对或后续重开重放。

脚本提供 `capture_persistent_inputs(suite)` 只读辅助：全骨 frozen matrix/PRS 和原始骨 tag 参数、
rigid/joint 原始 BaseContainer 参数、模型物理配置及 Float32 数值指纹。
每条新运行会在零帧求值前保存 `<run>-persistent-inputs.json`；必要时由主任务在首次求值后再调用辅助，
区分保存精度、读取配置变化和 runtime 初始化造成的漂移。
只读辅助 `capture_control_inputs(suite)` 另记录控制器的 relative/frozen/global matrix 和
与原生一致的 inactive 判断；每条新运行在零帧前保存 `<run>-control-inputs.json`。
这些 synchronized frozen control pose 属于运行时输入证据，不应与持久骨 bind 混为同一指纹。

准备新运行时暂存前一测试文档，在显式 `close()` 时统一关闭，避免 MCP 宿主仍引用已销毁文档。
最终清理前激活需要保留的用户文档；此验证对象只销毁自己创建或读取的文档。

输出包含 `receipt.json`、每条运行的 `*-trajectory.json`、`initial.c4d` 和 `continuous_end.c4d`。
`S:\tmp` 可能被清理；本次需要保留的最新回执、轨迹和场景已复制到上述持久目录，原件未修改。

### 原生调试证据边界

Rider 已尝试对 C4D attach 会话 pause，但请求在 15 秒后超时，后续 stack、threads 和 resume 报告
目标未暂停。所设源码断点未命中，且绑定返回没有关联可执行代码。
记录没有暂停位置、调用栈或变量值，源码推测不能升级为已证实的物理或 Message 运行时根因。
stop attach 会话后未再观察到目标进程，日志没有证明退出原因，也未证明该次 stop 保留进程；
只保留这些观察结果，不据此解释物理漂移。

## 性能证据

每帧计时只包围两次 `ExecutePasses()` 和时间设置，完整顶点读取、JSON 写盘和 Python 对比均在计时之外。
回执保留每帧原始耗时、median/p95/max，并另列第十帧后的稳定区间。
零帧耗时单独列为 `zero_frame_initialization_or_seek_evaluate_ms`，包含该次原生求值中的
runtime 初始化或 cold-world reset，排除 PMX/VMD 导入、C4D 文件读取和 Python 快照。
它可量化本次 seek 重建的可见成本；不是单独 Bullet reset 的精确计时。
它可以回答当前模块在当前场景和本机上的成本，不能单凭一次运行宣称优化幅度或满足生产性能目标。

若需区分 animation / IK / physics / morph / material，可在正常启动 C4D 前设置
`CMT_RUNTIME_PROFILE=1`，并按 `anim-flow-debug.md` 捕获 console。
开关在 C++ 内缓存；脚本中临时改环境变量不能证明已启用阶段统计。
`morphMs` 包含 material 子阶段，阶段数值不能直接相加；日志开销与 Python MCP 开销也要单独说明。

同质量性能对比需要两个可追溯模块：历史源码 revision 或快照、依赖 SHA、SDK/C4D 版本、编译器、
Debug/Release、优化选项、资源树、实际加载模块 SHA，以及相同 PMX/VMD、renderer、模拟参数和帧窗口。
两边还应通过同一质量验收。缺少相同正确性表现的旧模块只适合解释行为差异，不能作为同质量加速基线。
文件名带 old、文件仍存在、某个旧 SHA 出现在回执中，都不能证明可重现的历史模块当前可用。

当前只读盘点未确认可用的历史性能基线；已有的三个输出是当前工作区构建产物。
主任务若建立历史基线，应使用独立 checkout 和独立输出目录，保留当前脏工作区，序列化构建和 C4D 加载窗口。
本页没有创建 checkout、编译历史源码或切换正在加载的模块。

## 其余 SDK 与安装包

本机盘点入口：

```powershell
python scripts/c4d_extended_validation.py --inventory S:\tmp\cmt-remaining-local-inventory.json
```

它只读取目录、CMake cache、模块哈希和 Inno 安装记录，不运行构建或安装器。
早先盘点只有 SDK 2026 Debug、SDK 2026 Release、R20 Debug 三个配置图，生成器为
Visual Studio 18 2026、toolset v143。这是历史状态，不能继续写成其余六个 SDK 尚无配置。
当前八个 Windows SDK 的 Debug 编译已全部通过：`sdk_r20`、`sdk_r21`、`sdk_r23`、`sdk_r25`、
`sdk_2023`、`sdk_2024`、`sdk_2025`、`sdk_2026`，另有 SDK 2026 普通 Release 的独立候选编译成功。
主构建见 `primary-build-audit.json`，其余六项见 `sdk-builds/final-matrix.json`。
最终构建的源码/资源指纹统一为 `460e009c6eb08b3e363668b3c83ed6d3b03432786fd21f15927d92b3eab78a2a`，
其余六项最终 configure/build 退出码均为 0，主构建也已成功；记录了实际模块哈希、大小、73 个真实资源副本和有效配置。
首轮 SDK 2025/2023 的旧 `f6aa…` 结果属于历史记录，最终矩阵已完成统一冻结源码的增量构建。

SDK 2024 首次在官方 framework 的 `datatype.cpp` 比较表达式触发 C2666；普通 cache CXX flags
会被 Maxon helper 清空，未能解决该次构建。随后通过仅属于该构建图的目录级兼容选项完成完整 target
及 durable 增量构建。原始失败与最终成功同时保留，不把一次失败等同于 SDK 源码整体不兼容。
已配置、首轮编译通过和最终冻结源码的编译通过是三个不同状态；原生加载/UI 运行还需要对应宿主验证。

| 其余 SDK Debug | 最终 configure/build | 实际模块 SHA-256 前缀 |
| --- | --- | --- |
| SDK 2025 | 0 / 0，通过 | `280ec7ea104cdc66` |
| SDK 2024 | 0 / 0，通过；使用专属兼容片段 | `bfbde85f570bc611` |
| SDK 2023 | 0 / 0，通过 | `43ced1207b179e95` |
| R25 | 0 / 0，通过 | `b0db777255d7002d` |
| R23 | 0 / 0，通过 | `088aadc2bf15682c` |
| R21 | 0 / 0，通过 | `fad1dbcef813ec31` |

主任务可按每次一个 SDK 的方式补齐 Windows 编译，并保留退出码、CMake/compiler 身份和最终模块 SHA：

```powershell
$taskCmake = 'C:\Program Files\CMake\bin\cmake.exe'
& $taskCmake -S sdk_r21 -B _build_msvc/sdk_r21 -G 'Visual Studio 18 2026' -A x64 -T v143 `
    -DCMT_ENABLE_RUNTIME_REGRESSION=OFF
& $taskCmake --build _build_msvc/sdk_r21 --config Debug --target mmdtool --parallel 8
```

其他五个目录使用对应名称替换；本次使用的预编译依赖、cache 参数和配置命令以各最终 receipt 为准。
构建后同时检查 copied `res/cmt_config.json` 和资源数量。
当前已补齐 Windows Debug 编译覆盖，未安装各版本宿主时不代表对应 C4D 的加载和场景运行验收；
macOS SDK/Xcode、macOS 安装包和远端 CI 仍需要对应执行环境的真实回执。

### SDK 2024 的本机 MSVC 兼容参数

该次失败位于官方 `core.framework` 的 `datatype.cpp` 比较表达式，诊断为 C2666。
最初失败、普通 cache flags 无效失败和临时 hook 成功的原始收据分别保存在上述持久目录的
`sdk-2024-compat/sdk_2024-first-failure/`、`sdk_2024-ineffective-cache-attempt/` 和 `sdk_2024-temp-hook-pass/`。
不能将前两次失败改写为通过，也不能只保留临时路径成功而省略最终维护配置。

维护片段为 [cmake/sdk_2024_msvc_compat.cmake](../../cmake/sdk_2024_msvc_compat.cmake)，SHA-256 为
`2af672095ebb55b566e08baeca8aa00bd1b1e11bdb706b2c22fa685662c0bfe3`。
仅 SDK 2024 的 `CMAKE_PROJECT_TOP_LEVEL_INCLUDES` 引用该文件，MSVC/CXX genex 添加
`/Zc:rewrittenExpressions-`；其他 SDK graph 不引用该片段。SDK 强制的 C++20 标准保留，
`CMAKE_CXX_FLAGS` 恢复默认 `/DWIN32 /D_WINDOWS /EHsc`，不依赖 SDK 会清空的 cache 字符串。

本机 C++20 微型 compiler probe 默认失败，加入该开关后通过，C++17 对照也通过；
完整 SDK 2024 的 configure/build 退出码均为 0，最终模块为
`bfbde85f570bc6113bc778ec286689fb32a41a902b33d7a4a3e1bdf2aeff7d1f`，资源副本 73 文件。
这是 MSVC `19.38.33145`、v143 工具链下的实际兼容证据；该开关没有被本次查到的公开 Microsoft 选项说明
确认为跨版本契约，换编译器版本需要重新验证。
Microsoft 的 [C++20 rewritten expressions 说明](https://learn.microsoft.com/en-us/cpp/overview/cpp-conformance-improvements-2019?view=msvc-170#rewritten-expressions-in-c20)
解释比较重写可能新增歧义候选；它不为本机这个兼容开关提供所有版本支持承诺。

以下命令复现本次已验证配置，使用已存在且已记录哈希的七类 Debug 预编译依赖：

```powershell
& 'C:\Program Files\CMake\bin\cmake.exe' -S sdk_2024 -B _build_msvc/sdk_2024 `
    -G 'Visual Studio 18 2026' -A x64 -T v143 `
    '-DCMT_DEPS_PREBUILT_DIR:PATH=C:/code/C4D_MMD_Tool/_build_msvc/cmt_deps_prebuilt' `
    '-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES:FILEPATH=C:/code/C4D_MMD_Tool/cmake/sdk_2024_msvc_compat.cmake' `
    -DCMT_ENABLE_RUNTIME_REGRESSION=OFF
& 'C:\Program Files\CMake\bin\cmake.exe' --build _build_msvc/sdk_2024 `
    --config Debug --target mmdtool --parallel 4
```

预编译依赖身份、完整 cache 参数、退出码及模块身份见同目录的最终 receipt；
该命令不证明全 SDK Release 发布矩阵、实际安装包或旧宿主 UI 运行完成。

此前未找到 ISCC 的阻塞已解除。2026-10-06 从 [Inno 官方下载页](https://jrsoftware.org/isdl.php)
取得 6.7.3，Authenticode 验证为 Valid、发布者 Pyrsys B.V.，编译器保存在
`_build_msvc/tools/inno-6.7.3/ISCC.exe`。临时用户安装已卸载，保留经过校验的独立工具文件。

新增 `scripts/check_inno_package.py` 使用真实 ISCC 编译维护安装器副本。为保证隔离，副本设置私有 AppId、
私有控制目录及 S:/tmp 下的 11 个 host，并以八个不同的非生产 DLL 标记检查 R/S 对应关系。
实际编译、安装的 869 项文件身份、重复安装的旧插件内容清理、卸载与无关 host 文件保持均通过。
原模板、runtime resource adapter、MCP runtime 文件均有 hash 记录。

```powershell
python scripts/check_inno_package.py `
  --compiler C:/code/C4D_MMD_Tool/_build_msvc/tools/inno-6.7.3/ISCC.exe `
  --output S:/tmp/cmt-inno-package-fresh `
  --exercise-install
```

该结果是安装器基础流程验证，`test_payloads=true`、`release_installer_accepted=false`，不证明真实 SDK DLL
的装载或最终发布包。正式包仍需在源码冻结后使用根 `package-windows` / `inno-installer`，
显式传本机 generator 和 ISCC 路径，生成最终八套 Release 模块。build preset 不会修改既有 SDK config。
`scripts/check_release_artifacts.py --build-root <目录> --output <收据>` 可提前检查八套输入的
实际 x64 DLL、回归桥 OFF、真实资源树、配置及五个 MCP 文件身份。此检查不证明源码/二进制历史关联或原生通过。
2026-10-06 较早 canonical 目录 audit 尚未通过：当时八套 Release 主模块缺失，2026 图为测试桥 ON。
安装包应记录哈希、大小、包含的各 SDK 模块及真实资源；安装/卸载效果需要独立目录的真实运行，
不能只看 installer 文件生成或启动窗口。

2026-10-06 最终冻结源码/资源 `4a542f52…` 后，R20、R21、R23、R25、2023、2024、2025、2026
八套 canonical Release 已编译通过，测试桥全部 OFF。构建使用同一份已核对 hash 的预编译依赖，
没有重复构建或替换静态库；2024 图使用前述兼容片段。最终输入 audit 全部通过。
2026 模块 `c7ad243e…` 在 C4D 2026.4.0 重跑普通生产 MCP 八阶段全部通过；
PMX 倍率 1、2、.5、三格式的 12 个写盘失败、源文档恢复和测试文档清理均通过。
测试工作树的 SDK-independent CTest 为 15/15，libMMD 格式/往返/material morph 三项 focused tests 为 3/3。

真实 ISCC 已生成候选包
[CMT_Windows_Candidate_20261006.exe](../../_build_msvc/validation/remaining/windows-release-candidate-20261006/CMT_Windows_Candidate_20261006.exe)。
候选版本沿用模板 `0.0.0.0`，未作为正式版本发布。另用私有 AppId/安装路径和上述真实 Release 文件
完成隔离安装、重复安装和卸载，11 个组件共 869 项文件哈希通过，无关 host 文件保持。
原始候选包未安装到用户 host；ISCC 提示仓库旧中文语言文件缺少部分新消息，相关消息回退为英文。

维护命令也支持真实 Release 文件的隔离安装验证：

```powershell
python scripts/check_inno_package.py `
  --compiler C:/code/C4D_MMD_Tool/_build_msvc/tools/inno-6.7.3/ISCC.exe `
  --output S:/tmp/cmt-inno-real-release-fresh `
  --release-build-root C:/code/C4D_MMD_Tool/_build_msvc `
  --exercise-install
```

[最终归档收据](../../_build_msvc/validation/remaining/windows-release-candidate-20261006/archive-receipt.json)
保留八套模块/PDB/资源、构建日志、cache、源码快照、原生 run、安装记录和每份文件 hash。
此前 PMX 2.0 尾部多写 4 字节以及测试端误读状态字段的两个失败 run 另归档，保持原始失败结论。
严格真实模型物理 seek 重放、UV Morph offset 导出、Impulse offset/运行效果、GPU 渲染、
真实运输超时/重连/重启身份、旧宿主 UI 和 macOS 仍未全部通过，因此 `release_accepted=false`。
