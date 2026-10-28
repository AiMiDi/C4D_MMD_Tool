# 影子世界是「冷启动」而主世界早「热运行」吗？——逐帧时间线计数器（t74）

> 只加计数器、不改产品逻辑。诊断工件来自隔离副本 `S:\tmp\cmt_vmd_profile_20261019\p5-src`（产品树零写入，候选 patch `fbd41b9a…3389` 前后同值）。
> 原始日志：`S:\tmp\cmt_vmd_profile_20261019\p5\ab\warm-sync2\a1-diag.log`（251 行）、`…\warm-async\b-diag.log`（589 行）。

## §0 结论：`warmup_asymmetry` **不成立**

**两个世界在第 539 帧时都「零步进」**，不存在「主世界已热、影子才冷」的历史差：

| | 到帧 539 为止的累计步进 | 首次真正步进帧 | 采样窗口内步进数 |
|---|---|---|---|
| A1-sync（主世界） | **0** | **540**（第 1 步） | 81（540–620，每帧 1 步） |
| B-async（影子世界） | **0** | **541**（首个结果在 541 生效） | 79（`worker_steps`） |

- 两段日志在帧 539 之前都只有 **2 条 `timeline`**：帧 0（`branch=reset`）与帧 539（`branch=reset`）。帧 1–538 从未被求值 ⇒ 两个世界都没有可累积的历史。
- 因此 541 帧 async 相对 sync 的 97.168 mm 均值偏差**不能**用「历史步数不等」解释；步数在 540/541 是 1:0、2:1，量级相同。

## §1 插桩与控制项

- 新增日志（`CMT_ASYNC_STATS_LOG` 门控，生产未设该 env 时零输出）：
  - `timeline frame=<f> t=<s> branch=<reset|off|seam_sync|async> async=<0|1> substeps=<n> epoch=<e> sub=<n> cons=<n> app=<n> wsteps=<n> skipped=<n> covered=<n>`——`MMDModelManagerObject::Execute` 的物理分发点，**每帧一次**，`branch` 即该帧真正走的分支。
  - `ev_rebuild` / `ev_start inst=<k>` / `ev_shutdown inst=<k>` / `ev_reset`——影子世界生命周期（`RebuildStandaloneAsyncShadow` / `StartStandaloneAsyncPhysics` / `ShutdownStandaloneAsyncPhysics` / `ResetStandalonePhysics`）。
  - 计数器取自 `PhysicsAsyncPipeline::GetCounters()` 与 `async_applied_frame_`。
- 工件：`S:\tmp\cmt_vmd_profile_20261019\p5\diag2\plugins\mmdtool\mmdtool.xdl64` 3,816,960 B sha256 `B1305BBF685A20E075E3E2C26A292B1FFFD82067C2912C53AB8369B5DD30AB1E`；`CMT_RUNTIME_PROFILING=1` 标记 = False；含 `timeline frame=`/`ev_start inst=` 字符串。
- 跑法（两段各一次 launch，均为 82 帧 539–620，B 段含 seek 560→600）：
  ```powershell
  $env:CMT_ASYNC_STATS_LOG='…\warm-sync2\a1-diag.log'; $env:CMT_PHYSICS_ASYNC='0'
  pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
    -OutRoot S:\tmp\cmt_vmd_profile_20261019\p5\ab\warm-sync2 -OnlySegments A1-sync -SkipTiming `
    -SyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p5\diag2\plugins -Execute
  ```
  （async 段同形，`CMT_PHYSICS_ASYNC='1'`、`-OnlySegments B-async`、`-AsyncPluginsPath`。）

## §2 A1-sync 时间线（主世界）

- 事件：`ev_reset` × 4（三条在 `t=0.000` 建场景期间，一条在 `t=17.966667`＝帧 539）。
- `timeline` 83 条：帧 0 `branch=reset`；帧 539 `branch=reset`；**帧 540–620 全部 `branch=seam_sync`**（81 条）。
- `epoch` 恒为 0（sync 模式不建异步管线），`sub/app/wsteps` 恒 0（无异步计数器）。
- `wstep` 81 条（同步路径每帧一次 `RunStandalonePhysicsStep(1/30)`）。

结论：**主世界在帧 539 才被 Reset，帧 540 是它的第一步**。到 539 帧累计 0 步。

## §3 B-async 时间线（影子世界）

`timeline` 84 条：帧 0 `reset`、539 `reset`、**540–560 `async`**（21 条）、600 `reset`（seek）、561 `reset`、562–620 `async`（59 条）。

影子实例生命周期（`ev_*`）：

| inst | 创建 | 结束 | epoch | 结束时 submitted/applied | 是否有过 step |
|---|---|---|---|---|---|
| 1 | t=0（建场景） | t=0 | 0→1 | 0 / 0 | 否 |
| 2 | t=0 | t=0 | 1→2 | 0 / 0 | 否 |
| 3 | t=0 | t=0 | 2→3 | 0 / 0 | 否 |
| **4** | t=0 | t=17.9667（帧 539 Reset） | 3→4 | 0 / 0 | 否 |
| 5 | t=17.9667（帧 539） | t=20.0（seek 到 600） | 4→5 | 21 / 20 | 是（540 提交，541 起消费） |
| 6 | t=20.0（seek） | t=18.7（回到 561） | 5→6 | 0 / 0 | 否 |
| 7 | t=18.7（帧 561） | 关闭（收尾） | 6→7 | 59 行 `async` | 是 |

- 首个 `wsteps>0` 出现在**帧 541 的 `timeline` 行**（`wsteps=1`）；帧 540 行 `sub=0/app=0/wsteps=0`（刚提交、还没消费）。
- 到帧 539 为止 `wsteps` 上限 = **0**。

## §4 问题 1：首次步进帧与累计步进

| 段 | 世界首次真正步进 | 到帧 539 累计步进 | 帧 540 | 帧 541 |
|---|---|---|---|---|
| A1-sync 主世界 | **540** | **0** | 1（`seam_sync` 分支执行） | 2 |
| B-async 影子世界 | **541**（首个结果生效；worker 在 540 提交） | **0** | 0 | 1 |

两边都从「帧 539 Reset 后的冷状态」起步，**没有 warmup 不对称**。

## §5 问题 2：B 段 539 帧前 4 个 `submitted=0` 实例由什么创建

`ev_start` 在 `t=0.000` 连续出现 3 次（inst 1/2/3），各自紧随一条 `ev_reset` 与 `ev_shutdown`；inst 4 也在 `t=0.000` 创建、一直存活到帧 539 的 Reset（`t=17.966667`）。它们对应**建场景序列**：`host-driver new-scene` → `import_pmx` → `import_motion` → `set_mode anim` → `physics on`，每一次模型/模式/物理开关变更都触发 `ResetStandalonePhysics()`（`mmd_model_manager.cpp` 的 `needs_physics_reset`），Reset 里 `ShutdownStandaloneAsyncPhysics()` + 重建，而**这些时刻没有任何 `Execute` 走到物理分发**，所以一次 step 都没有。

- 与 t69 的「3 个」差异：t69 只统计了 `stats final=1` 里 `submitted=0` 的管线；本次生命周期插桩看到 **4 个**（inst 4 存活到 539 才关，同样 `submitted=0`）。
- sync 模式同一位置也重建了世界：`ev_reset` × 4（t=0 三条 + 帧 539 一条），只是 sync 没有 pipeline 实例（`epoch` 恒 0）——**重建次数相同**，差异只在是否创建异步管线。

## §6 问题 3：541 尖峰从哪来（在「无 warmup 不对称」前提下的重解释）

- 帧 539 前的累计步进：sync **0**、影子 **0**（相等）。
- 帧 540：sync 已步进 **1** 次（结果立即写回），影子**尚未步进**（先提交）。
- 帧 541：sync 累计 **2** 次，影子累计 **1** 次（首个结果此时才写回）。
- 所以「影子冷、主世界热」**被推翻**。剩下的差异只能来自「同样一次步进，两个世界算出的位姿不同」，即**世界状态/构造路径**：
  - sync 的 `ResetStandalonePhysics()` 走主 `physics_manager_own_`；
  - 影子的 `StartStandaloneAsyncPhysics()` 用 `ResetTransform()` + `Reset(physics)` 把刚体放到 PMX 初始/绑定变换（t73 已定位，`mmd_model_runtime.cpp:903/906`），并且**不复用主世界刚体的当前变换与速度**；
  - 于是即便步数相同（各 1 步），两边刚体在第一步的起点/约束接触状态不同，影子首步产生 ~97 mm 的均值位移，而主世界首步只有 ~1.8 mm。
- 这与 t73 的 `world_state` 结论一致，但**明确排除**了「历史步数差」这一解释；换句话说：**修法是「让影子的起始状态对齐主世界」而不是「补步进历史」**。

## §7 未覆盖 / 边界

- 只采了 2 次 launch（sync 1 次、async 1 次），每段 82 帧；未做重复性验证。
- `submitted`/`applied` 的帧号语义来自 `async_submitted_frame_`/`async_applied_frame_`（逻辑帧），与文档帧的映射靠 `timeline` 行的 `frame=`；本报告按同一行读数，未额外交叉核对结果槽的 `frame` 字段。
- 未定位「同样一步为何差 97 mm」的具体物理量（质量/接触/初始速度），仅确认它不是步数差；若要修，需在影子 `Start` 里补主世界 `btTransform`/线速度/角速度的复制并重测。
- 运行期 env 门控日志：未设 `CMT_ASYNC_STATS_LOG` 时零输出，生产默认不受影响；产品树 `git status --short -- source` tracked 改动 0。
