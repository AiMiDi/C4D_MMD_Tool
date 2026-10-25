# VMD 播放性能：先测稳再优化（t14）

本目录是「测量稳定性 + 阶段分解 + 优化排序」的可复现档案。所有数字来自隔离宿主（私有 profile、
`S:\tmp\cmt_vmd_profile_20261019\host_profile`，MCP 5557）上的真实 Cinema 4D 2027，脚本可原样复跑。

- 判据口径：**同一宿主会话内交替**测物理开/关，只信同段相对差；绝对毫秒跨会话不可比（见 §4.5）。
- 工件口径：每次都核对宿主实际加载的 `mmdtool.xdl64` sha256 与本地工件一致（`module_match`）。
- 出包口径：`CMT_ENABLE_RUNTIME_PROFILING` 默认 OFF；插桩构建只存在于 `S:\tmp` 的隔离目录。

## 0. 结论摘要

| 项 | 结论 |
| --- | --- |
| 插桩构建 | `S:\tmp\cmt_vmd_profile_20261019\profiling-build`，`mmdtool.xdl64` 3,819,008 B / sha256 `BBFB6C4B46EC717C3BBECF28EFF49C8441D46E4EF32A6DC3E96265B2D96BBE78`，`CMT_RUNTIME_PROFILING=1` 标记存在；`_build_msvc\sdk_2027_v143` 的 baseline 工件未被打上标记（仍是 OFF，符合出包要求） |
| 单会话稳定性 | 5 轮交替：物理开 median 35.22 ms（内散布 3.5%）、物理关 18.61 ms（5.7%） |
| 跨启动漂移 | 5 次启动：on 34.88–42.10 ms（散布 20.7%）、off 18.15–22.82 ms（25.7%）；**归因 = 外部 CPU 争用**（on median 与机器负载 r=+0.893；时钟恒定 3200 MHz，与散布无关） |
| 受控复现 | 人为 8 个忙循环进程（系统总 CPU 36.4 / 45.2 %）→ on median 34.95 → **58.37 ms（+67 %）**、off 18.19 → **36.02 ms（+98 %）**；撤掉后回落 34.81 / 18.64 → 归因可复现 |
| 修正后跨启动散布 | 加机器负载门禁（≤30 %）后 5 次启动、0 丢弃：on **34.811 ms（散布 3.39 %）**、off **18.642 ms（散布 4.23 %）** → **≤10 %** |
| 分解自洽 | 逐帧 Σ`self_ms` 与 `root_ms` 比值 = 1.000（插桩口径内部精确闭合）；与墙钟的差是**未插桩的宿主固定开销** ≈9.0–10.0 ms/帧，两档几乎相同 |
| 下一刀 | ①Bullet 物理内核（`bullet.substep` 13.9 ms，占 on 的 39%）②MMD 非物理求值（animation/bone/morph/control ≈8.9 ms 的自耗）③未插桩宿主残差 ~10 ms（对象数/依赖图，风险高） |

**离线/静态检查 ≠ 宿主验证**：本目录的数字全部来自真实宿主，但只在 `S:\tmp` 的私有 profile 上跑过；
包安装后的用户环境、其他机器 CPU 未验证。

## 1. 工件与构建

两版并行存在，互不污染：

| 变体 | 路径 | 大小 | sha256 | 标记 |
| --- | --- | --- | --- | --- |
| baseline（出包口径） | `S:\tmp\cmt_vmd_profile_20261019\ab\baseline\plugins\mmdtool\mmdtool.xdl64`（t13 冻结）；`_build_msvc\sdk_2027_v143\bin\Release\plugins\mmdtool\mmdtool.xdl64`（实时构建目录） | 3,777,024 B | `1C949823F2CC992EE7026A131253EB76E0054B954F7B7075BB8340948BEF8CE7`（冻结）/ `1B8FC3A8688430AFD25C82A1FB725359AB9C5B50914103D5C0AFF14E61E1A11B`（实时） | 无 `CMT_RUNTIME_PROFILING=1` |
| profiling（插桩） | `S:\tmp\cmt_vmd_profile_20261019\profiling-build\bin\Release\plugins\mmdtool\mmdtool.xdl64` | 3,819,008 B | `BBFB6C4B46EC717C3BBECF28EFF49C8441D46E4EF32A6DC3E96265B2D96BBE78` | 有 `CMT_RUNTIME_PROFILING=1` |

构建命令（插桩，只写 `S:\tmp` 的副本，源构建目录只读）：

```powershell
# 1) 复制构建树（首次；之后可 -SrcBuild 增量）
robocopy C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143 S:\tmp\cmt_vmd_profile_20261019\profiling-build /MIR /NFL /NDL /NJH /NJS
# 2) 副本里的 CMakeCache 记录的是源构建目录，必须删掉再 configure
Remove-Item S:\tmp\cmt_vmd_profile_20261019\profiling-build\CMakeCache.txt -Force
# 3) 用本机实际安装的 generator（VS18；CMakePresets.json 的 windows_vs2022_v143 硬编码 VS17，本机不可用）
cmake -S C:\code\C4D_MMD_Tool\sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\profiling-build `
      -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=ON
cmake --build S:\tmp\cmt_vmd_profile_20261019\profiling-build --config Release --target mmdtool
```

耗时：configure 4.4 s + build 141.3 s（首轮 robocopy 约 2.5 GB / 4,233 文件）。实测教训：
在副本上直接 `cmake --build` 而不删 `CMakeCache.txt` 会**把源树重建一遍**（cache 里的源目录写死了），
虽然产物 sha 未变，但会让并行构建的另一方拿到意外改动，务必先删 cache 再 configure。

标记核对方法（与 `cmake/check_profiling_disabled.cmake` 同判据）：

```powershell
$bytes = [IO.File]::ReadAllBytes($xdl64); $text = [Text.Encoding]::ASCII.GetString($bytes)
$text.Contains('CMT_RUNTIME_PROFILING=1')
```

## 2. 测量协议

`stable-measure.ps1` 一次调用 = N 次宿主启动（`-Launches`）× 每次启动内 M 轮交替（`-Rounds`）：

1. `launch-host.ps1 -Execute` 启动宿主（私有 profile + `-ModulePath` 指向被测工件），写 `host-identity.json`；
2. 核对 `identity.modules.mmdtool_loaded.sha256` 与本地工件 sha 一致（不一致直接判失败，绝不测错版本）；
3. 记录机器状态 `system-before.json` / `system-running.json` / `system-after-probe.json`
   （电源计划、`Win32_Processor` 时钟/最大时钟/负载、2 次 `\Processor(_Total)\% Processor Time`、Top5 CPU 进程、C4D pid/线程数/CPU）；
4. `stable-probe.py` 在**同一会话**内交替：物理开 → 物理关 → 物理开 → …，每个条件测 `-Frames` 帧（默认 560–599，预热 540–559），
   每帧墙钟 = `doc.SetTime(BaseTime(frame, fps))` + `doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)`；
5. `stop-host.ps1 -Execute` 收尾（CloseMainWindow 优先，超时才 Stop-Process 并记 `stop_forced`）；
6. 汇总 `run-summary.json` + `summary.md`，打印 `STABLE_RESULT:{...}`。

关键参数：

| 参数 | 作用 |
| --- | --- |
| `-Variant baseline\|candidate\|live\|profiling\|<路径>` | 选工件；baseline/candidate 默认用 `S:\tmp\...\ab\` 的冻结副本 |
| `-PhysicsBoth` / `-Physics on\|off` | 是否两档都测 |
| `-Rounds` / `-Launches` | 每会话轮数 / 启动次数 |
| `-LoadWorkers N` | 先起 N 个忙循环进程再测（复现外部争用） |
| `-MaxLoadPct P` | 机器负载门禁：单次启动测到 CPU 总占用 > P% 就丢弃该次启动并重试（`-LaunchRetries`） |
| `-RequireSpread` / `-SpreadThresholdPct` | 跨启动散布不达标时把退出码置非零 |

## 3. 宿主崩溃事故（2026-10-24 19:07:37）与规避

**现象**：`stable-measure.ps1 -Launches 5` 跑到第 5 次启动时，MCP 在 `exec_python` 建场景的瞬间失去响应，
对 5557 的连接变为 refused，探测进程挂到超时，随后 `stop-host.ps1` 也读不到 `cleanup.json`，脚本因
StrictMode 属性访问报 `在此对象上找不到属性"stop_method"`。

**证据链**（全部只读采集）：

- `S:\tmp\cmt_vmd_profile_20261019\host_profile\prefs\mcp\audit.log` 末尾：

  ```
  2026-10-24T11:07:36+00:00 COMMAND exec_python [req db8cb00c-f6bf-46c0-89c6-57cf39bceca5]
  2026-10-24T11:07:36+00:00 EXEC_PYTHON \nimport json, c4d\ndoc = c4d.documents.BaseDocument()\ndoc.SetFps(30)\n...
  2026-10-24T11:07:37+00:00 REENTRANT_DRAIN dispatcher drain re-entered while a handler was running (nested CoreMessage); nested call skipped
  ```

- `S:\tmp\cmt_vmd_profile_20261019\host_profile\_bugreports\_BugReport.txt`（1,216,633 B，时间戳 19:07:37）：
  `Call_Stack_Thread_65832` 里 **0 帧 mmdtool**，全部是 `python311.dll`（`PyEval_EvalFrameDefault` /
  `PyImport_ImportModuleLevelObject` 反复嵌套）；`mmdtool.xdl64` 只出现在 `Loaded_Modules` 段（`S:\tmp\...\ab\baseline\plugins\mmdtool\mmdtool.xdl64`）。

**判断**：不是插件崩溃，是**在 MCP dispatcher 的 drain 内新建文档触发了 CoreMessage 重入**，把宿主搞崩。
该轮 `baseline-drift5` 的 5 次启动里只有前 4 次有效，**第 5 次及整轮作废（invalid，不参与统计）**。

**规避（已固化到代码）**：`stable-probe.py` 不再调用 `driver.NEW_SCENE_CODE`（`BaseDocument()` +
`InsertBaseDocument` + `SetActiveDocument`），改为 `SCENE_PREPARE_CODE` —— 复用宿主启动时已加载的文档，
只改 `SetFps` / `SetMinTime` / `SetMaxTime` / `SetTime`，再走 `mmdtool_import_pmx` / `mmdtool_import_motion`。
落地后 `baseline-drift5c` 的 5 次启动全部正常（`object_total=1944` 与崩溃前一致）。

**规则**：**禁止在 `exec_python` 内新建/切换文档**；需要独立文档时先停宿主、改启动参数或走 C4D 自己的
命令（不要走 MCP 的 python 通道）。

## 4. 跨启动漂移：数据与归因

### 4.1 现象（历史）

同一 baseline 工件、同一配方、同一台机器，跨启动 median 曾出现 34.0 / 45.1 / 65.6 ms（约 2×），
而同一会话内交替测得的相对差稳定（物理开/关比值 ≈1.9）。

### 4.2 不加门禁的 5 次启动（`baseline-drift5c`，静默机器，5 轮/次）

| 启动 | pid | 启动耗时 s | 时钟 MHz | 负载 % | 线程 | 物理开 median ms | 物理关 median ms | on 内散布 % | off 内散布 % |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| L1 | 49424 | 18.4 | 3200 | 21.9 | 463 | 34.879 | 18.230 | 3.84 | 7.12 |
| L2 | 11444 | 17.5 | 3200 | 12.2 | 464 | 35.014 | 18.146 | 6.52 | 8.31 |
| L3 | 61172 | 17.1 | 3200 | 15.0 | 463 | 37.790 | 21.255 | 9.03 | 24.26 |
| L4 | 51680 | 26.1 | 3200 | **82.2** | 458 | **42.104** | **22.816** | 43.98 | 41.20 |
| L5 | 29888 | 17.7 | 3200 | 21.5 | 466 | 37.023 | 19.115 | 8.27 | 11.64 |

- on：min 34.879 / max 42.104 / median 37.023 → 散布 **20.72%**；off：18.146 / 22.816 / 19.115 → **25.73%**。
- 时钟 5 次全部 **3200 MHz**（无降频），说明**不是**频率/电源计划造成的。
- L4 的机器负载 82.2%（其余 12–22%），其 on median 与内散布同时最大。
- on median 与负载的皮尔逊相关 **r = +0.893**（n=5，方向性证据；因样本少不作因果结论）。

### 4.3 受控复现（外部负载 → 变慢）

先排除"降频"这个直觉：`baseline-drift5c` 5 次启动里 CPU 时钟**全程 3200 MHz（=MaxClockSpeed）**，`pearson(on, clock) = 0.0`；而 `pearson(on, load) = +0.893`。
于是直接做受控实验——`-LoadWorkers 8` 在宿主启动前拉起 8 个 pwsh 忙循环（`try/finally` 保证测量结束必杀），同工件、同配方、2 次启动 × 3 轮交替：

| 启动 | pid | 系统 CPU 占用 | 物理开 median ms | 物理关 median ms |
| --- | --- | --- | --- | --- |
| L1 | 85548 | 36.4 % | 63.753 | 36.926 |
| L2 | 84596 | 45.2 % | 52.977 | 35.111 |
| 静默对照（drift5c L1/L2，同工件同期） | 49424 / 11444 | 12.2–21.9 % | 34.879 / 35.014 | 18.230 / 18.146 |

on 中位 **58.365 ms（+67.0 %）**、off 中位 **36.019 ms（+98.0 %）**（对照取 34.947 / 18.188）；撤掉 workers 后立刻回到 `baseline-gated2` 的 34.81 / 18.64。

关键观察：本机 24 核 / 32 逻辑，8 个忙循环只占总量 36–45 %，却让物理开掉到 58 ms —— 瓶颈在**主线程拿到的 CPU 时间片**（物理/动画/依赖图都在主线程同步跑），不是总算力。这也解释了为什么别人在跑构建时测出的数会整体抬高：环境负载直接决定主线程的时间片，而不是"这台机器更慢"。

### 4.4 修正后（负载门禁）跨启动散布

`stable-measure.ps1 -MaxLoadPct 30 -LaunchRetries 3`：每次启动在 `system-running` 采样系统总 CPU，> 30 % 直接丢弃该次启动并重试（丢弃记 `launch_discards`，**不算失败**）。

`baseline-gated2`（2026-10-24 19:30 起，同 baseline 工件 sha `1C94…8CE7`，5/5 启动成功、0 丢弃、`all_launches_ok=true`、exit 0）：

| 启动 | pid | ticks | 负载 % | 线程 | on median ms | off median ms |
| --- | --- | --- | --- | --- | --- | --- |
| L1 | 20412 | 639284382115742213 | 12.7 | 466 | 34.705 | 19.175 |
| L2 | 28992 | 639284382805623634 | 16.2 | 465 | 34.179 | 18.400 |
| L3 | 19728 | 639284383479299934 | 11.9 | 467 | 35.023 | 18.398 |
| L4 | 77816 | 639284384168547745 | 13.9 | 465 | 34.814 | 18.641 |
| L5 | 85568 | 639284384864766996 | 8.0 | 465 | 35.337 | 18.596 |

- on：34.179–35.337，median **34.811**，跨启动散布 **3.39 %**
- off：18.398–19.175，median **18.642**，跨启动散布 **4.23 %**
- `pearson(on, load) = −0.943`（此区间内负载越低越慢，已是噪声量级）、`module_identity_all_match = true`

→ **≤10 % 达成**。对照不加门禁的 `baseline-drift5c`：on 20.72 %、off 25.73 %（其中 L4 启动时正好撞上 82.2 % 的系统负载，on 42.104）。
结论：**测量前必须过负载门禁**，否则同一工件的跨启动散布就足以吞掉任何 A/B 差异。

### 4.5 一个必须记住的坑：绝对毫秒跨会话不可比

t13 收尾时同一 baseline 工件、同一配方复跑，on 从 34.03 → 45.13 ms（+32.6%）、off 18.17 → 21.20 ms（+16.7%）。
所以**任何 A/B 结论都必须在同一会话内交替得出**，跨会话只能比"比值/百分比"。

同样是这个 baseline 工件：`baseline-gated2`（19:41 收尾）是 34.811 / 18.642，20 分钟后 19:47 再跑一次契约 Verify
（同一命令、同一配方）拿到 **110.489 / 87.005 ms**（3.2× / 4.7×）—— 当时机器正在跑其它重任务，且这次是单次启动、
没过负载门禁。这不是"另一个版本"，就是同一条数据在不同机器负载下的样子；它也再次说明**测量必须过门禁 + 同会话交替**。

## 5. stage 分解（插桩构建，单会话 5 轮交替）

`profiling-stage2`（工件 sha `BBFB…BE78`，marker=True，pid 46176，warmup 20 / frames 40 / start 560）：

| stage | 物理开 median ms | 物理关 median ms |
| --- | --- | --- |
| `model.execute`（MMD 模型管理器整体，含子项） | 23.344 | 7.959 |
| `physics.total` | 14.719 | 0.000 |
| ├ `physics.bullet` | 14.026 | 0 |
| │ ├ `bullet.substep` | 13.876 | 0 |
| │ │ ├ `bullet.collision` | 7.257 | 0 |
| │ │ ├ `bullet.solve` | 6.047 | 0 |
| │ │ ├ `bullet.dispatch` | 3.611 | 0 |
| │ │ ├ `bullet.aabb` | 3.459 | 0 |
| │ │ ├ `bullet.solver.setup` | 2.888 | 0 |
| │ │ └ `bullet.solver.joints` | 2.155 | 0 |
| ├ `physics.inputs` / `physics.writeback` | 0.9 / 0.66 | 0 |
| `animation.layer` | 2.653 | 2.615 |
| `bone.animation` | 1.841 | 1.787 |
| `control.checksum` | 1.659 | 1.540 |
| `material.sync` | 1.415 | 1.370 |
| `bone.plan` | 1.408 | 1.306 |
| `morph.total` | 1.359 | 1.364 |
| `bone.manager.execute` | 1.323 | 1.30 |
| `bone.tag.execute` | 0.955 | 0.925 |
| `control.sync` / `control.delta` / `control.chains` | 0.87 / 0.49 / 0.48 | 同量级 |
| `ik.solve` | 0.356 | — |
| 墙钟（每帧整帧） | 35.856 | 19.276 |

解读：物理开多出来的 ~16.5 ms 里，**Bullet 内核（collision+solve+substep 机械开销）占 14.0 ms**，
MMD 侧非物理部分两档几乎相同（animation/bone/morph/control/material ≈ 9 ms，两档都在）。

## 6. 自洽性与口径

- **插桩口径内部精确闭合**：逐帧 Σ`self_ms` 与 `root_ms` 的比值 = **1.000**（root ≈ 25.89 ms 物理开 / 9.87 ms 物理关）。
  `root_ms` 是所有顶层 scope 的 inclusive 之和，嵌套会重复计数，因此解释时必须用 `self_ms` 或按父子关系归并。
- **插桩口径 vs 墙钟**：物理开 25.89 vs 35.86（差 **10.0 ms**，−27.9%）；物理关 9.87 vs 19.28（差 **9.0 ms**，−47.7%）。
  这段是对 MMD 逻辑**未插桩**的宿主固定开销（C4D 按帧遍历/依赖图/缓存刷新 + 计时外壳），
  **两档几乎相同**，即不随 MMD 工作量变化。所以"stage 之和 = 整帧"在插桩口径内成立，
  与墙钟的缺口是口径差而不是漏算逻辑。
- **墙钟口径**：`ExecutePasses(PASS_ALL)` 含动画/表达式/生成器全部 pass；t8/t13 的历史数字也是这个口径，可直接对比。
- **哪些是插桩、哪些是墙钟兜底**：本报告所有 stage 数字是插桩；每帧总耗时与内散布/跨启动散布是墙钟。

### 6.1 缺口不是 `PASS_ALL` 的 pass 开销（`-ExecFlags default` 对照）

为排除"多跑的 pass 让墙钟变长"这个解释，用 `stable-measure.ps1 -Variant profiling -ExecFlags default`
（`c4d.EXECUTIONFLAGS_0`）再跑一轮同配方 5 轮交替，脚本 `check-selfconsistency.py` 逐 rep 对照：

| 口径 | 物理开 wall / Σself / 比值 | 物理关 wall / Σself / 比值 |
| --- | --- | --- |
| `PASS_ALL`（`profiling-stage2`） | 35.856 / 25.681 / **0.716** | 18.896 / 9.678 / **0.512** |
| `EXECUTIONFLAGS_0`（`profiling-stage-default`） | 39.980 / 28.366 / **0.710** | 27.271 / 14.049 / **0.515** |

两档的 Σself/wall 比值几乎相同（0.716 vs 0.710），绝对缺口都落在 **10–13 ms**；也就是说：
缺的不是 C4D 多跑的 pass，而是**插件插桩范围之外、每帧固定的宿主内核开销**（该轮 `EXECUTIONFLAGS_0`
反而更慢，是因为那台机器当时外部负载更高，见 §4）。
因此 §6 的口径结论可以写成一句话：**插桩内自洽到 1.000，插桩外有一个约 9–10 ms/帧的宿主固定残差，
它是墙钟兜底、不随 MMD 工作量变化。**

## 7. 下一刀砍哪里（按 可优化空间 × 实现风险 排序）

1. **Bullet 物理内核热路径**（`bullet.substep` 13.88 ms，其中 `bullet.collision` 7.26 + `bullet.solve` 6.05）。
   证据：物理开/关差值 16.55 ms，物理内核占其 84%。可选手段：减少子步数（`bullet.substep` 的调用数由
   substeps 决定，当前 1 次/帧，若为多子步可调）、接触缓存复用、宽相 AABB 剪枝（`bullet.dispatch` 3.61 / `bullet.aabb` 3.46 说明
   宽相与分发也有可观开销）、约束迭代上限。预期收益：物理档 −3 ~ −5 ms/帧（on −8% ~ −14%），风险中（改物理观感，须做网格/位姿一致性校验）。
2. **MMD 非物理求值**（`animation.layer` 2.65 + `bone.animation` 1.84 + `control.checksum` 1.66 + `bone.plan` 1.41 + `morph.total` 1.36 ≈ 8.9 ms 的自耗，两档都在）。
   证据：物理关时 `model.execute` 仍有 7.96 ms。可选手段：`control.checksum` 增量比较改为脏标记、未变化通道跳过权重回写、`bone.plan` 复用到 tags。
   预期收益：−1.5 ~ −3 ms/帧（on −4% ~ −8%，off −8% ~ −16%），风险低。
3. **未插桩的宿主固定残差 ≈10 ms/帧**（占 on 的 27.9%、off 的 47.7%，两档几乎相同）。
   证据：见 §6。它来自 C4D 侧对 1944 个对象（748 `MMDJoint` + 479 `MMD刚体` + 85 样条等）的按帧遍历与依赖图执行。
   可选手段：把 joint/rigid 降为 tag/内部数据结构、减少文档对象数、少开 pass（PASS_ALL → 仅动画）。预期收益 −2 ~ −5 ms/帧，风险高（触及产品数据模型，可能破坏 C4D 侧交互与兼容）。

## 8. 复现

```powershell
# 单会话 5 轮交替（判据用）：物理开/关
pwsh -NoProfile -File docs\validation\vmd-perf-stable-20261024\stable-measure.ps1 `
    -Variant baseline -PhysicsBoth -Rounds 5 -OutDir S:\tmp\cmt_vmd_profile_20261019\stable\baseline-verify

# 跨启动散布（5 次启动 × 5 轮），带负载门禁与重试
pwsh -NoProfile -File docs\validation\vmd-perf-stable-20261024\stable-measure.ps1 `
    -Variant baseline -PhysicsBoth -Rounds 5 -Launches 5 -LaunchRetries 3 -MaxLoadPct 30 `
    -OutDir S:\tmp\cmt_vmd_profile_20261019\stable\baseline-gated

# 阶段分解（插桩工件 + 每帧 JSON 日志）
pwsh -NoProfile -File docs\validation\vmd-perf-stable-20261024\stable-measure.ps1 `
    -Variant profiling -PhysicsBoth -Rounds 5 -OutDir S:\tmp\cmt_vmd_profile_20261019\stable\profiling-stage

# 外部负载对照（复现慢 20%+）
pwsh -NoProfile -File docs\validation\vmd-perf-stable-20261024\stable-measure.ps1 `
    -Variant baseline -PhysicsBoth -Rounds 3 -Launches 2 -LoadWorkers 8 `
    -OutDir S:\tmp\cmt_vmd_profile_20261019\stable\load-8workers
```

分析：`python analyze-drift.py <run-summary.json>`（跨启动表 + 相关）、`python analyze-stable.py --run <dir>`（stage 表 + 自洽指标）。

## 9. 未覆盖 / 限制

- 只在一台机器（i9 级、`logical_cpus` 见 `system-*.json`、时钟 3200 MHz 恒定）与一个场景（625 骨骼 / 479 刚体 / 748 约束 / 70,222 顶点）上验证。
- 跨启动散布的归因是**方向性**证据（n=5 的相关 + 一次受控负载复现），不是逐因隔离实验；CPU 频率/温度未纳入采集。
- `dynamics_substeps=null`（C4D 侧无该参数），Bullet 子步数只能从 `bullet.substep` 的 `calls` 推断，未做逐子步拆分。
- 插桩构建**只用于测量**，不得出包；出包判据见 `cmake/check_profiling_disabled.cmake`。
- 排序里的"预期收益"是从 stage 占比推算的区间，未做实现验证。
- `baseline-gated2` 的 5 次收尾全部走 `Stop-Process forced=true`（本机 `CloseMainWindow` 在该无人值守场景下 15 s 内不退，用户已授权），
  即它证明的是"只杀自己 pid、无残留"，不是"优雅退出"路径；优雅退出见 `baseline-drift5c`/`profiling-stage2` 的 `close_mainwindow` 记录。
- 本轮所有测量都是**墙钟**，没有用 C4D 内置 profiler 或 ETW 交叉验证；插桩只覆盖插件自身 stage（宿主内核未插桩）。
