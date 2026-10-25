# P2 异步物理：真实宿主 A/B/A 验证方案（t31）

> 状态：**方案 + 脚本就绪，尚未上宿主**。本任务（t31）只做离线准备：不启动 Cinema 4D、不联网、不改产品树。
> 真正开跑由复审通过后的执行任务调用 `run-ab-async.ps1 -Execute`。

## 1. 目的与判定门槛

### 1.1 要回答的问题

P2（异步物理）把物理步进搬到工作线程，主线程只消费「上一帧」的结果。它带来两个**必须同时成立**的前提：

1. **语义**：异步路径的画面必须等于同步路径**晚一帧**，且只晚一帧（不是两帧、不是没消费、不是乱序）。
2. **收益**：主线程每帧省下的时间要够大，值得为「晚一帧」这个可见副作用买单。

只要语义不成立，性能数字再漂亮也不能默认开；只要收益不达门槛，语义再正确也不该默认开。本方案把这两件事分开测、分开判。

### 1.2 判定门槛（硬数字）

| 条件 | 结论 | 后续动作 |
| --- | --- | --- |
| 语义全部通过 且 `async − sync` 的物理开 median **≥ 3.0 ms/帧** | `promote_candidate` | 可提出「默认开」的候选（仍需用户拍板） |
| 语义全部通过 且收益 **< 1.5 ms/帧** | `archive_invisible` | 收益不可见：结论归档，**保持默认关闭**，不再投入 |
| 收益落在 **1.5–3.0 ms** 灰区 | `gray_keep_off` | 保持默认关闭；换时段/延长轮次复测，或先做别的优化 |
| 语义任一失败 | 判定失败（exit 1） | 先修 P2（t29/t30），不进入性能结论 |
| A1 与 A2 两段 sync 的 on median 漂移 > 10% | 判定失败 | 本轮作废重跑（机器被占） |

30 FPS 预算 33.3 ms/帧：当前同步版物理开约 35 ms，本就压线；异步要「值得默认开」，至少要把它拉回预算内，这也是 3 ms 门槛的由来之一。

### 1.3 为什么必须 A/B/A 而不是 A/B

同一台机器上，**绝对毫秒跨会话不可比**：t13 实测同工件同配方 20 分钟后从 34.0 变成 45.1 ms（+34%），被占满时甚至 110 ms。因此：

* 只在**同一会话内**交替测 sync/async，用**相对差值**下结论；
* 用 A1（sync）与 A2（sync）两段夹住 B（async），漂移 > 10% 直接判本轮不可用；
* 每段各自 ≥ 5 轮 rep，取 median；CV 一并记录。

## 2. 两版工件与构建

### 2.1 两版差异只有一个环境变量

P2 候选（`.dsh-switchman/vmd-perf-20261024/candidate-async-p2/candidate-async-p2.patch`，54,536 B）把异步路径做成**运行时开关**：

* `AsyncPhysicsSwitchEnabled()` 读环境变量 `CMT_PHYSICS_ASYNC`；
* **未设置 / 非 1** → 走 P1 同步路径，逐位不变；
* **= 1** → 走异步管线（主线程消费 N-1、工作线程推进 N）。

因此 A/B 可以**用同一份 xdl64、只切环境变量**，从而排除「两版二进制差异」这个干扰项。但为了同时交付可复现的隔离产物，构建仍要求落两份 xdl64 并记 size + sha256：

* `sync`：产品口径 Release（`CMT_ENABLE_RUNTIME_PROFILING=OFF`），不设 `CMT_PHYSICS_ASYNC`；
* `async`：同一源码 + P2 补丁，同一口径 Release（profiling 仍必须 OFF，否则插桩本身会污染毫秒）。

> 若两版 sha 相同，说明 async 版没构建成功或补丁没生效——`run-ab-async.ps1` 预检会直接抛错。

### 2.2 隔离构建（不许污染 `_build_msvc`）

沿用 t14/t19 已验证的做法：

```powershell
# 1) 复制构建树到 S:\tmp（robocopy /MIR），删掉副本顶层 CMakeCache.txt
#    否则 cmake 会认为「源目录不一致」并把 build 打到原树里
# 2) 本机只装了 VS18，CMakePresets 的 windows_vs2022_v143 硬编码 VS17，必须显式指定 generator
cmake -S sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\async-build `
      -G "Visual Studio 18 2026" -A x64 -T v143 `
      -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF
cmake --build S:\tmp\cmt_vmd_profile_20261019\async-build --config Release --target mmdtool
# 3) 断言二进制里没有 CMT_RUNTIME_PROFILING=1 标记（cmake/check_profiling_disabled.cmake 的判据）
# 4) 复制 bin\Release\plugins 到 S:\tmp\...\async\plugins，记录 size + sha256
```

**产品树零改动**：补丁用 `git apply` 临时应用，构建完必须还原（按开工前 sha256 逐字节校验，autocrlf 会把 LF 回写成 CRLF，字节 sha 会变——这一点在 t19 踩过）。

产物目录约定：

```
S:\tmp\cmt_vmd_profile_20261019\physics-async\
  build\          隔离构建树
  sync\plugins\   mmdtool\mmdtool.xdl64  (+ res/ mcp/)
  async\plugins\  同上
  ab\<stamp>\     run-ab-async.ps1 的 -OutRoot
```

## 3. 三段 A/B/A 测量协议

### 3.1 命令

```powershell
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-ab-async.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\physics-async\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\physics-async\async\plugins `
  -OutRoot          S:\tmp\cmt_vmd_profile_20261019\physics-async\ab\run1 `
  -Pairs 5 -Rounds 5 -Warmup 15 -Frames 30 -StartFrame 560 `
  -MaxLoadPct 30 -Execute
```

不加 `-Execute`（或加 `-DryRun`）时只打印 `AB_ASYNC_PLAN:{...}` 计划 JSON 并退出 0，**不启动宿主**——这是 `check-scripts.ps1` 的自检路径。

### 3.2 每段做什么

| 段 | 环境 | 计时 | 语义采样帧 |
| --- | --- | --- | --- |
| A1-sync | `CMT_PHYSICS_ASYNC=0` | `stable-measure.ps1 -Launches 5 -Rounds 5 -PhysicsBoth` | 539,540,541,559,560,561,618,619,620 |
| B-async | `CMT_PHYSICS_ASYNC=1` | 同上 | 540,560,619（另需 sync 的 N-1、N-2） |
| A2-sync | `CMT_PHYSICS_ASYNC=0` | 同上 | 同 A1（至少 540/560/619） |

* 计时沿用 `stable-measure.ps1` 的既有能力：`-MaxLoadPct 30` 安静门（>30% 的启动直接丢弃重测，丢弃不算失败）、`-LaunchRetries`、forced 清理、`run-summary.json` 里逐轮 `load_pct`。
* 语义段单独起宿主（`launch-host.ps1 -Execute`，同一私有 profile `S:\tmp\cmt_vmd_profile_20261019\host_profile`、端口 5557），导入同一 PMX+VMD，`set-mode anim`、物理开，然后 `probe-rigid.py` 采样。
* 每段结束 `stop-host.ps1 -Execute` 收尾；`Stop-Process forced=true` 是用户已授权的兜底，会如实写进 `cleanup.json`。

### 3.3 计时阶段必须关刚体显示

`MMDRigidObject::Execute`（`source/module/tools/object/mmd_rigid.cpp:671-705`）只有在 `m_display_type != RIGID_DISPLAY_TYPE_OFF` 时才 `SetRelMl + MarkSceneTransformDirty`。也就是说：

* **显示关闭** = 刚体的 `GetMg()` 不随物理更新 → 采样不到位移，但也正是计时想要的最轻路径；
* **显示打开** = 每帧多 479 次 `SetRelMl`，计时会被污染。

所以：计时段保持默认（显示关闭）；语义段由 `probe-rigid.py --enable-rigid-display` 显式打开（把刚体管理器 `RIGID_DISPLAY_TYPE=1001` 置 1 再 `c4d.EventAdd()`），采完即随宿主退出。这个开关差异必须写进报告，否则「语义段的 ms」不可与「计时段的 ms」混用。

## 4. 语义断言

全部断言由 `run-ab-async.ps1` 的 `Add-Check` 产出，写进 `run-summary.json` 的 `checks[]`。任一 `failed` → 整个脚本 exit 1。

| ID | 断言 | 说明 |
| --- | --- | --- |
| C0 | sync 帧 540/560/619 的网格局部 sha 前缀 = `07757cb6` / `068d56c8` / `c15545a9` | 锚点：证明「这一轮确实导入了同一场景、网格没被换掉」 |
| C1 | `async(N).rigid_sha256 == sync(N-1).rigid_sha256`，逐字节 | **位移一帧**的正面证据 |
| C2 | `async(N).rigid_sha256 != sync(N).rigid_sha256` | 反证：若相等说明 `CMT_PHYSICS_ASYNC=1` 没生效，跑的还是同步路径 |
| C3 | 网格：若 `sync(N).mesh == sync(N-1).mesh`（动画静止窗口）则要求 `async(N).mesh == sync(N-1).mesh`；否则只记录关系（`shift_exact` / `shift_plus_animation_delta` / `no_shift_suspicious`） | 动画在动的帧，网格差异无法归因于物理，故只在静止窗口下硬断言 |
| C5 | `async(N).rigid_sha256 != sync(N-2).rigid_sha256` | 排除「晚两帧」（消费滞后两帧） |
| C6 | A1 与 A2 两段 sync 的 540/560/619 网格与刚体 sha 完全相同 | 关闭开关时零差异、可复现 |
| timing | A1/A2 的 on median 漂移 ≤ 10%；`delta_on = B.on − mean(A1.on, A2.on)` | 漂移超限判本轮作废 |

### 4.1 「稳定态对齐关系必须可解释」

C1 只对**同一次物理推进的结果**成立。物理在收敛过程中，工作线程推进 N 时用的是 N-1 的骨骼输入，主线程渲染 N 时用 N-1 的刚体结果——所以「异步 N 的刚体 = 同步 N-1 的刚体」是工程定义上的精确关系，**不是近似**。

但网格不是：网格由骨骼驱动，`async(N)` 的骨骼是 N 的动画 + N-1 的物理，`sync(N-1)` 的骨骼是 N-1 的动画 + N-1 的物理。只有当**动画本身在这两帧之间没变**（静止窗口）时两者才逐字节相等。这就是 C3 分条件断言的原因，也是报告里「网格差异来源」必须写清楚的地方。

### 4.2 P2-002：刚体可见性

历史问题（P2-002）：异步结果写回时，关掉显示的刚体不更新 `GetMg()`，于是「物理在跑但看不见动」。本方案用 `probe-rigid.py` 直接采样 `MMDRigidObject` 的世界矩阵（479 个刚体，按 path 排序后拼接 12×float32 取 sha256），因此：

* 若显示没打开 → 各帧 `rigid_sha256` 全同 → `probe-rigid.py` 以退出码 2 报 `rigid_display_not_enabled`（fail-closed，不给出假阳性「位移一致」）；
* 刚体数 ≠ 479 或网格点数 ≠ 70,222 → 退出码 3，说明场景不对，整轮不可用。

## 5. 宿主事故与清理

| 现象 | 处置 | 记录 |
| --- | --- | --- |
| 启动后 `host_exited_before_ready: exit_code=-1` | 多为「强杀留下的子进程仍持有单实例锁」：用 `Get-CimInstance Win32_Process` 枚举 + `taskkill /F /T`，**只杀命令行含本任务私有 profile 的实例**，再重试 | `logs/segment-*-launch.log` |
| 弹窗卡住 / 保存确认 | 用户已授权 `Stop-Process` | `cleanup.json` 的 `stop_method=Stop-Process`、`stop_forced=true` |
| `exec_python` 触发崩溃（`REENTRANT_DRAIN ... nested CoreMessage`） | 崩溃栈历史实测全在 `python311.dll`、无 `mmdtool` 帧；把 `host_profile\_bugreports` 整包拷到 `<OutRoot>\crash\` 后归档目录，再重启宿主 | `crash/*`、`audit.log` 尾行 |
| 端口 5557 仍被占 | 说明宿主没退干净，`Clear-OurHost` 后等端口释放再继续 | `run-summary.json` 的 preflight 段 |

**绝不碰别人的宿主**：清理条件不是「名叫 Cinema 4D 就杀」，而是「命令行里带本任务预私有 profile 路径」。

## 6. 判定与动作

`run-ab-async.ps1` 结束时写 `<OutRoot>\run-summary.json` 并打印一行 `AB_ASYNC_RESULT:{...}`，字段包括：

```
artifacts.sync / artifacts.async   : { module, size, sha256 }
timing.A1 / timing.B / timing.A2   : { on_median, off_median, on_values[], off_values[], loads[], launches }
timing.delta_on_ms / delta_off_ms  : 相对差值（唯一可用于结论的数字）
checks[]                           : C0/C1/C2/C3/C5/C6/timing_* 的 status 与 detail
verdict                            : promote_candidate | gray_keep_off | archive_invisible
```

* `verdict=promote_candidate` → 报告提交「建议默认开」，由用户拍板；默认值改动本身是单行（`AsyncPhysicsSwitchEnabled()` 的 fallback）。
* `verdict=archive_invisible` → 归档结论，**保持默认关闭**，把精力转回主线程热点（见 `docs/validation/vmd-perf-stable-20261024/README.md` §7 的前三刀）。
* `verdict=gray_keep_off` → 保持关闭，补测：换时段（避开别的构建/CI）、加轮次（`-Pairs 7`）、或先用 `-ExecFlags default` 复核口径。

## 7. 复现清单

```powershell
# 0) 离线自检（不启宿主）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-scripts.ps1

# 1) 构建两版（隔离树，profiling OFF），落 S:\tmp\...\physics-async\{sync,async}\plugins
#    见 §2.2；构建完逐字节校验产品树

# 2) 只测计时（跳过语义，快速看收益）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-ab-async.ps1 `
  -SyncPluginsPath <sync>\plugins -AsyncPluginsPath <async>\plugins `
  -OutRoot S:\tmp\...\ab\quick -SkipSemantics -Execute

# 3) 只测语义（跳过计时，快速看待办）
pwsh ... -SkipTiming -Execute

# 4) 完整 A/B/A
pwsh ... -Pairs 5 -Rounds 5 -Execute
```

单次完整 A/B/A 的机器时间估算：每段 5 次启动 × (启动 ~15 s + 5 rep × (15 预热 + 30 计时 + 30 关物理) 帧 ≈ 20 s + 收尾 ~10 s) ≈ 4–6 分钟；三段 ≈ 12–18 分钟，另加三次语义段（每次 1 次启动 + 导入 ≈ 40 s）。实际以 `stable-measure` 的 `elapsed` 为准。

## 8. 未覆盖与风险

1. **未上宿主**：`probe-rigid.py` 与 `run-ab-async.ps1` 只做过语法/参数/dry-run 自检，`HOST_CODE` 里的 C4D API 用法（`OMMDRigidManager` 容器写 1001、`ExecutePasses` 顺序、`GetMg()` 口径）尚未在 2027 上实跑过一次。
2. **网格只在静止窗口硬断言**：移动帧的网格差异只能定性记录，不能证明「差的就是那一帧的物理」。
3. **物理参数未扫**：只测当前场景（479 刚体 / 748 约束）；异步收益与刚体数、约束迭代次数强相关，其他场景不保证同样的毫秒数。
4. **单机单场景**：本机 i9-14900KF 24 核/32 线程，工作线程有充足空核；核数更少的机器上收益可能变小、甚至因争用变负。
5. **默认值不在本任务范围**：即使 `promote_candidate`，改默认值、改设计文档、改 CHANGELOG 都属于后续任务，且需用户确认。
6. **崩溃归因不完全**：`REENTRANT_DRAIN` 崩溃栈历史实测无 `mmdtool` 帧，但也不能据此断言「与插件无关」；只能说明「不是 MMD 计算路径里的空指针」。
