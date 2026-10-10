# VMD 动作适配：P0–P4

正式 MCP 接口已接入任务启动、查询、取消、诊断、阶段预览、导出和应用，见 [动作适配 MCP 调试接口](motion-sizing-mcp.md)。新接口不依赖测试桥；当前普通 Release 已编译，原生业务验证仍需加载新模块后执行。

计算核心现已下沉到 `dependency/libMMD`，直接由 `libMMD` target 提供，命名空间为 `libmmd::sizing`；核心不依赖 C4D SDK，运行时不需要 Python。Python/Cython 仅用于离线生成上游对照。

## 使用

1. 从扩展菜单中的 **MMD Tools - VMD 动作适配** 打开面板，原面板入口为 **MMD Tools - 工具面板**。当前原生检查仍看到外层 Mmdtool 分组，直接平级展示尚未验收。两个面板使用同一张 MMD Tools Logo。
2. 选择动作原本使用的**来源 PMX**，将场景中导入的**目标 MMD 模型管理器**拖入链接框，也可以点击“使用当前选中模型”。来源 PMX 用于计算比例，目标模型链接用于取得目标绑定结构。
3. 动作可以来自上方 VMD 文件，或在“模型 VMD 动画槽”中选择该目标模型已导入的动作。槽读取在隔离副本中完成，不切换原模型的当前槽。无效或已删除的槽不会按另一个索引误读。
4. “参数变化后自动更新模型前后对比”默认开启：修改参数后等待约 350 ms，后台计算，然后在临时预览文档更新两份目标模型。计算期间可继续调整求解参数；旧任务被取消，最后一次输入生效。可关闭自动更新后手动“计算调整阶段”与“预览”。
5. 选择原始、比例、偏移、姿态、扭转、避让、接触、多人/相机共八个阶段；用 C4D 时间轴播放或拖动。切换阶段和自动重算保留预览时间。蓝色模型播放原动作，橙色模型播放所选阶段。默认并排，可以切换叠加；预览关闭物理。
6. 批量处理时为每个目标设置来源和动作，再“加入/更新角色”。每个角色保留独立参数；选择队列条目恢复该角色的输入与参数，并决定导出/应用哪个角色。选择未入队模型进入“新角色”草稿，必须“加入/更新角色”后才参与计算；删除角色后立即显示剩余选中角色的配置。最多 16 个同文档角色，要求相同导入倍率、共用 MMD 坐标系和时间轴。
7. 可另外指定相机 VMD 和最大距离倍率。相机调整随最终阶段显示，支持单独导出 VMD 或作为新相机加入原文档。
8. 满意后“应用为新动画槽”，或导出所选阶段 VMD。原动作槽保留，应用支持 Undo/Redo 和场景保存重开。关闭预览/工具会清理临时文档；原文档的时间、绑定和动作不受预览影响。

**自动预览的含义**：计算完成后更新模型阶段结果；不显示 CCD 每一次迭代，也不覆盖原场景模型的已有动画槽。输入读取、绑定复制和预览模型生成仍在主线程，大模型可能短暂停顿；没有承诺逐帧无延迟。更改源/目标模型后重新选取或计算。应用前校验所有参与目标的绑定快照，过期结果拒绝提交。

## 当前算法与边界

| 阶段 | 已实现 | 验证 / 限制 |
| --- | --- | --- |
| P1 比例/偏移 | 根、中心、沟槽、左右脚/脚尖 IK 比例与中心/脚 IK 补偿 | 两套原实现位移基准；保留上游中心 Y 历史公式和到达关键帧曲线规则 |
| P2 姿态 | 肩臂、肘、腕绑定轴校正，上半身/上半身 2 方向校正 | 普通手臂旋转与原 StanceService 对照；未迁移全部下半身、脚尖和特殊模型启发式 |
| P2 扭转 | 串联父骨—扭转骨—子骨的 swing/twist 分配，包括非共线结构 | 父骨方向与子骨旋转补偿保持末端姿态；不可消除的半径误差限制在容差内，不引入不可播放的位移通道 |
| P3 避让 | 跟随绑定骨的球/盒/胶囊刚体，腕/肘目标投影及有限步 CCD | 默认静态刚体；不是动态物理或网格碰撞，不保证全身无穿模 |
| P3 接触 | 来源动作驱动的双手腕/五指尖接近配对、手腕地面与脚 IK 落地修正；连接组和共享关节同时求解 | Eigen 阻尼最小二乘、角步限制与回溯；明确报告不可达与残差，外部父级不支持 |
| P4 多人 | 统一 XZ 移动比例、共享时间轴、跨角色手部接触组 | 需要统一 MMD 空间，不自动推断任意 C4D 世界摆放或拼接动作 |
| P4 相机 | 相机平面上的角色范围拟合，调整兴趣点和距离，限制倍率 | 保留旋转/FOV/透视/插值；是几何取景算法，不是原 Python 近景/可见点启发式的逐项复刻 |

姿态以外的高级求解主要采用独立几何不变量、可达/不可达及误差下降验证，**不等于完整上游算法一致性**。各阶段残差反映该阶段约束，不保证后续阶段仍满足所有前序约束；启用多个互相冲突的约束时应检查结果。

要求标准日文骨名。P1 必要骨骼包括 `センター`、`左足`、`左ひざ`、`左足首`。缺失可选参考或无足部权重顶点会给出警告。P1 偏移仍保留上游兼容路径和保守预检；高级 FK 支持旋转/平移、局部/多重付与和负权重，分别排序父子与付与依赖，循环辅助分支隔离并报告。固定轴只限制求解新增旋转，输入姿态按现有 C4D/libMMD 播放插值求值。离线姿态已接入 libMMD 播放 IK 求解器，包含 PMX 链限制、变形层及 VMD IK 开关；骨骼 morph、动态物理、场景控制器覆写和外部父级仍不在离线评估范围。扭转/约束控制的轨道会逐整数 VMD 帧烘焙并使用线性插值，其余轨道保持原样。默认烘焙上限 18000 帧 / 200 万关键帧，诊断明细上限 20000 条，统计仍计全部约束。

## 模块结构

`dependency/libMMD/src/libMMD/Model/MMD/MMDMotionSizing.h` 是公共入口；内部实现在 `dependency/libMMD/src/MotionSizing`，保留五个职责模块：

- `Analysis`：模型/动作预检、比例和 P1 位移补偿。
- `Pose`：层级/付与 FK、libMMD 动作采样、固定轴约束、同时接触求解和轨道烘焙。
- `Solvers`：姿态、扭转、碰撞/接触、多角色与相机计算。
- `Pipeline`：阶段编排、批量执行、取消和结果发布。
- `Diagnostics`：输入错误、跳过原因、约束目标/实际位置及残差记录。

`source/module/tools/sizing/sizing_session.*` 负责 C4D 主线程快照、后台纯数据任务、预览和事务提交；`source/module/ui/motion_sizing_dialog.*` 负责交互。插件和测试直接链接同一个 `libMMD` target；旧 `cmt_motion_sizing` target 和兼容 include 已移除。公共头和上游 MIT 许可随 libMMD 安装，私有求解头不安装。核心测试与合成 fixtures 归 libMMD 所有，参见 [独立库使用说明](../../dependency/libMMD/docs/MotionSizing.md)。

中英文 UI 复用两套资源树 `c4d_symbols.h` / `c4d_strings.str`。`.str` 内非 ASCII 文本统一写成 `\uXXXX`，防止 C4D 以错误编码解释 UTF-8。SDK C++ 源码使用 `/utf-8`；这是与 `.str` 资源读取不同的两层问题。核心诊断明细目前为英文，按钮、标签、阶段和宿主错误为中英文。

## P0 原实现复现

固定上游 `miu200521358/vmd_sizing` 提交 `e5c30358696f688c96544e3af33ea9871961487d`。来源工程保持不变，兼容修补仅发生在临时副本中；MIT 声明在 `docs/licenses/vmd_sizing-MIT.txt`。

在仓库根目录执行，以下工作目录必须尚不存在：

```powershell
$env:UV_PYTHON_INSTALL_DIR = 'S:/tmp/cmt-sizing-python'
python -m uv venv --python 3.10 S:/tmp/cmt-sizing-reference/venv
python -m uv pip install --python S:/tmp/cmt-sizing-reference/venv/Scripts/python.exe Cython==0.29.37 numpy==1.26.4 numpy-quaternion==2023.0.4 bezier==2023.7.28 setuptools==68.2.2 scipy==1.10.1
S:/tmp/cmt-sizing-reference/venv/Scripts/python.exe scripts/vmd_sizing_reference_setup.py C:/code/vmd_sizing S:/tmp/cmt-sizing-reference
python scripts/vmd_sizing_fixtures.py dependency/libMMD/tests/fixtures/vmd-sizing
S:/tmp/cmt-sizing-reference/venv/Scripts/python.exe scripts/vmd_sizing_reference.py S:/tmp/cmt-sizing-reference/reference-src dependency/libMMD/tests/fixtures/vmd-sizing S:/tmp/cmt-sizing-reference/baseline
S:/tmp/cmt-sizing-reference/venv/Scripts/python.exe scripts/vmd_sizing_reference.py S:/tmp/cmt-sizing-reference/reference-src dependency/libMMD/tests/fixtures/vmd-sizing S:/tmp/cmt-sizing-reference/baseline-staggered --motion-name motion-staggered.vmd
```

需要可用的 MSVC 构建工具。构建脚本移除未使用且不能构建的 Cython cimport；运行器恢复 numpy 旧别名及上游文件名大小写别名。执行的比例分析和 MoveService 均来自原实现，未用新 C++ 实现生成参考答案。

仓库中的 fixture 包含两份可再生合成人形 PMX，以及每份 30 个输入骨骼关键帧的两份 VMD。它们覆盖不同体型、非零脚 IK 偏移、旋转和稀疏插值；`motion-staggered.vmd` 另覆盖父子骨关键帧错开的情形，以及每个关键帧不同的 Bezier 曲线。上游每份动作额外产生一个虚拟根节点关键帧；对照覆盖输入的共 60 帧，不要求复制该内部节点。两个 baseline 目录的 `reference.json` 保存输入 SHA256、参数、原实现计时和偏移；`docs/validation/vmd-sizing/reference-build.json` 保存来源源码哈希、依赖版本与兼容编辑记录。

## 构建与验证

正常开发使用仓库 `dev-windows-deps-test` / `cmt-plugin-tests` 预设。本机使用 VS 2026 v145 独立输出目录，避免改变标准预设。核心也可单独构建：

```powershell
cmake -S dependency/libMMD -B _build_msvc/libmmd-sizing-standalone -G "Visual Studio 18 2026" -A x64 -DLIBMMD_BULLET_ROOT=S:/tmp/cmt-vmd-sizing-p0/deps -DBULLET_INCLUDE_DIR=C:/code/C4D_MMD_Tool/dependency/bullet3/src -DLIBMMD_ENABLE_TEST=ON
cmake --build _build_msvc/libmmd-sizing-standalone --config Release --target mmd_motion_sizing_test mmd_motion_sizing_advanced_test
ctest --test-dir _build_msvc/libmmd-sizing-standalone -C Release -R mmd_motion_sizing --output-on-failure
cmake --build _build_msvc/vmd-sizing --config Release --target cmt-plugin-tests
cmake --build _build_msvc/vmd-sizing/sdk_2026 --config Release --target mmdtool
```

高级原实现基准：setup 加 `--advanced`，reference 加 `--phase stance`，输入在 `dependency/libMMD/tests/fixtures/vmd-sizing-advanced`，输出在 `baseline-stance`。上游避让/对齐模块虽能在参考环境编译，但没有据此声称数值对照通过。

- P1 两组 60 个输入关键帧：最大位置差 `8.49983e-8`。
- P2 18 个普通手臂旋转关键帧：相对上游最大角差 `2.56272e-8` rad。
- 24 项插件回归通过，包含高级求解测试；可达腕部接触间距约 `0.00321026`，跨角色接触约 `0.00197264` PMX 单位。
- 独立库与 SDK 2026 Release 分别编译验证。旧 SDK 和 macOS 未实测。
- 原生回归使用测试桥接构建；正式构建关闭 `CMT_ENABLE_RUNTIME_REGRESSION`。测试用例在 `tests/runtime/native_motion_sizing_test.py` 和 `native_motion_sizing_advanced_test.py`。

历史 P0/P1 回执保存在 `docs/validation/vmd-sizing/`；本轮 P2–P4 与 UI 验证保存到其 `advanced/` 子目录。原生样例为可再生合成人形，不是生产角色的美术质量验收。时间仅记录样例观测，不宣称整个 Python 工程的固定加速倍数。

## 2026-10-09 真实素材初次验证（高级补全前）

用户提供 `C:/pmx/Sour式初音ミクVer.1.02_by_Sour暄/Black.pmx`（内部名 `Sour_Miku_Black`）、`C:/pmx/白银之城—阿芙2.0/阿芙2.0.pmx` 与 `C:/vmd/Stay Tonight Heaven Lee Ver. 动作.vmd` / `cam.vmd`。来源内部名称与 VMD 标记一致，但文件版本不能仅凭名称唯一确认。

实际动作含 7251 个骨骼关键帧、557 个表情关键帧，至 1718 帧；相机 93 帧。原生 53 项检查通过：导入、两轮八阶段/五个时间点求值、源绑定/时间/槽不变、导出、有限矩阵、新槽应用、Undo/Redo、保存重开。额外输出检查确认表情和 IK 保留、相机帧数/旋转/FOV/投影保留、无重复骨骼关键帧和非有限数值。原素材未改写，也未复制到仓库。

XZ/Y 比例约为 0.922933 / 0.923007；开启高级选项的一次纯求解约 3248 ms。2957 条已支持约束报告零残差，但双方 `肩C` 存在付与旋转（flags 0x112），手臂姿态和手部约束被保守跳过，扭转链也因非共线结构跳过。**这不是该角色手臂修正、扭转/手部接触或整体动作质量通过。** 来源模型的扩展轨道并非全部能映射到阿芙。

回执见 [advanced/validation.json](../validation/vmd-sizing/advanced/validation.json) 和 [真实模型回执](../validation/vmd-sizing/advanced/real-assets/native.json)。测试场景保存于 `S:/tmp/cmt-vmd-sizing-real/real-roundtrip.c4d`；因用户正在面板中操作，真实素材的测试文档保留，不声称已清理。合成验证文档已清理。

## 2026-10-09 高级求解补全与 P4 复验

正式 MCP 接口已由独立任务接入，本轮保留其实现并合入最新编译产物。核心仍为 SDK 无关库，没有修改 libMMD 子模块。

此次补全 `肩C` 付与链、非共线扭转，以及共享手臂的同时接触求解。真实 C4D 对照还发现高级 FK 采样与播放曲线约定不一致，已直接复用 `InterpolateBoneKeys`；P1 的上游位移基准路径保持原有兼容行为。付与来源/权重已纳入目标过期签名。

最新完整 Stay Tonight 单角色求解覆盖 0–1718 帧，4 条扭转链均参与。一次核心观测约 707 ms（不包括导入、克隆和预览，不能据此推断整体交互耗时）：

| 检查 | 最新结果 |
| --- | --- |
| 扭转 | 6876 条约束，0 条超差；全帧肘/腕位置最大变化约 4.64e-7，腕方向误差小于 1e-5 rad |
| 避让 | 165024 条采样点约束，5 条超出 0.01 容差，最大残差约 0.0494 |
| 接触 | 3794 条约束，97 条超差，最大残差约 0.2338；包含脚 IK 和手部，不再全部跳过手臂 |
| 相机 | 93 个关键帧，帧号/旋转/FOV/投影/插值保持，兴趣点与距离为有限值 |
| C4D 播放对照 | 当前实例导入新生成 VMD，姿态/扭转/接触三个阶段、五个时间点、六个手臂骨，共 90 个位置样本最大差约 1.01e-6 |
| 回归 | 24/24 插件测试及 libMMD 插值专项通过；含负权重付与、非共线扭转、异形曲线、可达/不可达约束 |

双角色压力用例重复同一个源动作，一个目标为阿芙、另一个为 Sour，用于验证公共时间轴、跨角色求解、相机及有限输出。它不是两人舞蹈素材：重合人物产生大量互相冲突的接触，两个角色分别有 21284 / 28526 条超差，明确不算多人动作质量通过。可达双角色合成用例另外验证误差收敛。

来源模型的 `キューブ` 循环辅助骨被隔离并报告，不影响所测手臂。未匹配扩展轨道仍保留警告。全身网格无穿插、所有约束收敛、完整 Python 算法等价和真实双人舞美术质量均未作承诺。

本轮证据在 [高级补全回执](../validation/vmd-sizing/advanced-completion/validation.json)。C4D 当前旧模块的导入姿态对照与新版模块原生计算是两项不同证据，后者只有加载最新插件并完成实际调用后才能通过。

离线实物探针 `mmd_motion_sizing_assets_probe` 接受 UTF-8 四行清单（来源 PMX、目标 PMX、动作 VMD、相机 VMD）与 ASCII 输出目录；加 `--batch` 运行上述双角色压力用例。输出八阶段 VMD、相机、逐阶段统计和选帧 FK 坐标，不把用户模型复制进仓库。


## 2026-10-09 正式 MCP 原生闭环与 8.5 演示

后续已在 C4D 2026.4.0（PID 72544）加载高级补全版普通 Release，测试桥为 OFF。真实 stdio MCP 的 27/27 检查通过：八阶段预览及源场景保护、双角色输入、分页诊断、导出覆盖保护、相机、应用新槽、Undo/Redo、保存重开、过期拒绝与释放；取消测试记录完成竞态，不宣称本次进入 cancelled。测试文档全部清理、原文档恢复。详见 [原生回执](../validation/vmd-sizing/advanced-completion/production-native/receipt.json)。

真实素材另建立交互演示，PMX 和 VMD 的 `position_multiple` 均为 **8.5**。通过正式 MCP 在当前插件内重新求解 0–1718 帧，摘要为 175694 条约束、95 条未达容差、最大残差约 0.22495 PMX 单位；一次观测约 14.25 秒，不包括导入/预览，也不与离线探针计时混作性能承诺。8.5 仅为宿主场景尺寸，核心仍使用 PMX 单位。

工程保存在 `output/vmd-sizing-p4-20261009/live-demo-8.5/`：`阿芙-高级动作适配.c4d` 保留原动作及扭转/避让/接触的新槽；`刚体避让-前后对比-8.5.c4d` 将扭转阶段与避让阶段并排展示，第 854 帧可观察右肘/腕变化。演示场景关闭物理，以隔离动作求解效果；避让是基于刚体形状的运动学采样点约束，不代表网格级无穿插或物理模拟。演示工程按用户要求保留，与回归测试文档的清理结果分开记录。

## 2026-10-10 队列修复与 libMMD 下沉

独立复核反馈的“新目标覆盖旧队列项”和“删除后编辑器仍显示被删角色”已修复。草稿不自动覆盖旧条目或启动计算，移除最后一个角色清空目标与动作输入。MCP 同步的角色独立配置及没有 UI 控件的高级参数继续保留。

计算 API、七个实现文件、核心测试、合成 fixtures 和上游许可已迁入 libMMD；文件采用 `MMDMotion*.cpp/.h`，计算命名空间为 `libmmd::sizing`。C4D 会话/面板仍使用插件侧 `cmt::sizing`，显式调用库类型。独立复核发现的自定义 libMMD 源码路径问题也已修复：插件测试从实际 target 推导源码目录。

迁移中发现继承 AVX2 会改变迭代接触解，已为七个计算源文件保留原 SSE2 配置；真实素材八阶段及相机共九份 VMD 与迁移前 SHA256 全部一致。迁移验证与逐文件映射见 [本轮回执](../validation/vmd-sizing/libmmd-migration-20261010/receipt.json)。当前 C4D 属于 PE 同步验证会话，未重启或替换其模块；本轮队列及 MCP/UI 同步的原生交互验收仍待进行，不能用旧版原生回执代替。


## 2026-10-10 手部保护、腿部与 IK 复核

手部接触保留来源标志点关系、手指弯曲与手掌朝向；离线姿态复用播放 IK 并保持正数迭代次数和 VMD IK 开关。新增独立腿部自碰撞避让开关（MCP：`leg_avoidance`），限制足 IK 目标位移并保护目标跟随，地面阶段使用实际脚踝诊断。最新扫描超差胶囊对×帧数由 330 降到 245，仍有 116 帧超差；80 个原生采样点最大姿态差为 0.594163 个场景单位（8.5 倍率），未达到完全一致性。候选 Release 已编译，最新 UI/MCP 求解的模块加载验收仍待进行。详细数据、子代理复核与后续跨帧原型见 [本轮回执](../validation/vmd-sizing/leg-ik-fix-20261010/README.md)。
