# P3 异步物理真机复测（t56 身份修复后）

> 任务：t58（verification）。本文件是新结果文件，不覆盖 `host-ab-p3-result.md`（t49 旧结论）。
> 结论先行：**写回已生效，但等价不成立**（无恒定 lag，第一帧后出现整帧跳变并沿另一条轨迹发散）。
> 按契约「语义不过则性能数字一律记不可用」，第 3 节的计时数字**不作性能结论**，只用于回答 worker 是否吃掉主线程收益。

## 0. 结论

| 问题 | 结论 |
| --- | --- |
| 写回是否生效（479 全动，不再 27/452） | **是**。async 段 479/479 刚体有非零位移（frozen=0，max 285.979 mm；sync 段同为 479/479）。t49 的 452 冻结指纹消失。 |
| 是否存在常数 lag 使 `async(N) == sync(N−lag)` 逐位相等 | **否**。lag 0..40 全部 0 命中（唯一匹配是起点帧 539，1/82）；`lag_constant=False`，lag 桶 `{0:1, none:81}`。 |
| 发散形态 | 第 1 帧（540）**确实晚一帧**（452/479 逐位相同、差 0.000 mm）；**第 2 帧（541）整帧跳变 93.6 mm（median）/160.6 mm（max），444/479 跳 50–160 mm**；此后每帧步长恢复正常（2–4 mm），但整条轨迹偏移 100–230 mm 且差值不是常数。 |
| 开关反证 | A1 与 B 是两台独立宿主，A1 与 A2（sync）82/82 帧逐位一致；B 与 A1 显著不同 ⇒ 比较链路有效、async 路径确实在跑。 |
| 变形锚点旁证 | sync 段帧 540/560/619 局部 sha 前缀 `07757cb6`/`068d56c8`/`c15545a9` 全部命中。 |
| 能否默认开 | **不能**。语义未过，性能数字不可用。 |

## 1. 工件与构建

- 隔离 worktree：`S:\tmp\cmt_vmd_profile_20261019\p3b-src`（detached HEAD `3910564d99757f31f98e4cf7c89f5c8cc0df644a`）。
- patch：`.dsh-switchman\vmd-perf-20261024\candidate-async-p3\candidate-async-p3.patch`，74,537 B，sha256 `6eb55a373cd299fe4cb43008307f171910b19b96f10b36c2412992e213e4e473`（t56 修复版，t57 复审 pass）。
- 构建：`cmake -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF` → `cmake --build --config Release --target mmdtool`（`-Parallel 8`）。
  - sync：`S:\tmp\cmt_vmd_profile_20261019\p3b\sync\plugins\mmdtool\mmdtool.xdl64` 3,779,584 B `096ca542832120a8c95ed6f0e8f687c0a11195420fd80913988b608da22d9008`
  - async：`S:\tmp\cmt_vmd_profile_20261019\p3b\async\plugins\mmdtool\mmdtool.xdl64` 3,811,840 B `bf8afb06c6142b1e1750a63e2c694b061a7ae17290297727b8086e526e234b02`
  - 两者 sha 不同；`CMT_RUNTIME_PROFILING=1` 标记扫描均为 False；`CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`。
- 构建期一次性 `C1001`（MSVC 内部编译器错误，命中 maxon `quaternion.h`/`map.h`/`basearray.h`，与补丁无关），`-Parallel 8` 重试通过；`build-p3-ab.ps1` 因此新增 `-Parallel`/`-BuildRetries`，并按「同名步骤最后一次状态」判失败。
- 产品树 tracked 改动 0（`git status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency` 仅既存未跟踪文件）。

## 2. 语义（82 帧 × 479 刚体，逐位比对）

跑法：`run-p3-ab.ps1 -OutRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\sem -Execute -SkipTiming`，三段 A1-sync(ASYNC=0) / B-async(ASYNC=1) / A2-sync(ASYNC=0)，每段独立宿主，逐帧 `SetTime + ExecutePasses` 后采样 479 个刚体的世界矩阵（`matrix_hex`）与网格。

### 2.1 写回生效（t49 缺口已关闭）

| 段 | 有位移刚体 | 冻结刚体 | 最大位移 |
| --- | --- | --- | --- |
| A1-sync | 479 / 479 | 0 | 103.319 mm |
| B-async | **479 / 479** | **0** | 285.979 mm |
| A2-sync | 479 / 479 | 0 | 103.319 mm |

### 2.2 lag 直方图

- `max_lag` 扩到 40 后仍无匹配：`{"0": 1}`（仅起点 539），`none: 81`；`dominant_lag=0`、`lag_constant=False`、`full_match=1/82`。
- 每 lag 的位置偏差（median）几乎不随 lag 变化（lag0 221.9 mm → lag12 223.3 mm），说明不是「整体平移若干帧」，而是换了轨迹。
- 逐帧最像帧的偏移乱跳：async(559)→sync(548)（off 11）、async(580)→sync(580)（off 0）、async(619)→sync(602)（off 17）；即便最像仍差 208–223 mm。

### 2.3 分岔形态（为什么不是「晚一帧」）

| 比较 | median | max | 逐位相同刚体 |
| --- | --- | --- | --- |
| async(540) vs sync(540) | 0.890 mm | 45.599 mm | 27/479 |
| **async(540) vs sync(539)** | **0.000 mm** | 4.080 mm | **452/479** |
| async(541) vs sync(540) | 93.611 mm | 161.034 mm | 0/479 |
| async(560) vs sync(560) | 68.109 mm | 230.411 mm | 27/479 |
| async(619) vs sync(619) | 115.497 mm | 229.352 mm | 27/479 |

- 第 1 帧成立：async(540) 与 sync(539) 的 452 个动态/合并刚体**逐位相同**，仅 27 个 kinematic 因骨骼输入取的是第 540 帧而动了 4.08 mm。
- 第 2 帧崩掉：async 段 540→541 一步跳 93.59 mm（median），跳变分布 `<1mm:3 / 1–10mm:32 / 50–100mm:273 / >100mm:171`；此后每帧 2–4 mm 恢复正常 → 是一次**整体重定位**，不是持续爆炸。
- 差值不是常数偏置：逐刚体 `async(f) − sync(f−1)` 在 541/560/600/619 四帧间的变化量 median 119.6 mm（<1 mm 的只有 1/479）⇒ 影子世界在 541 之后独立演化，不是同一轨迹的平移。

### 2.4 机理判读（与 t36 离线结论对齐）

- P3 的 `ReplayStandalonePhysicsToFrame()`（patch 内 `hooks.reset_to_origin = [](){}`、`step_once = RunStandalonePhysicsStep(1/fps)`）重放时**不重放逐帧动画输入**，等于用同一组骨骼输入反复步进 → 只能得到 anchor，拿不到「同一路径的历史」。
- t36 离线夹具证明「严格一帧等价」的成立条件是：**相同初始状态 + 逐帧延迟一帧的真实动画输入**；当前实现缺后半，所以第一帧对、第二帧就因初始状态/输入差异被放大成整帧跳变。
- 与「物理不可约」无关：t36 的 `delay` 模式 200 帧 × 479 刚体已做到逐位相等（0.0000 mm）。因此结论是**接线/重放输入缺失**，不是物理本质限制。

## 3. 计时（语义未过 → **数字不可用**，仅记录主线程延迟变化）

同会话 A/B/A，每段 5 launch × 5 rep（on/off 交替，取每 launch 的 median 再取段中位数），预热 15 帧、计时 30 帧（560–589），`-MaxLoadPct 30` 安静门，10/10 轮 `module_match=True`。

| 段 | 插件 | on median | off median | 每 launch on（ms） | 负载 |
| --- | --- | --- | --- | --- | --- |
| A1-sync | `096ca542…` | **33.666** | 17.467 | 33.75 / 33.67 / 33.44 / 34.01 / 33.64 | 2.7–10.4% |
| B-async | `bf8afb06…` | **17.910** | 17.454 | 17.84 / 17.99 / 17.95 / 17.87 / 17.91 | 3.0–5.7% |
| A2-sync | `096ca542…` | **33.779** | 17.441 | 33.72 / 33.59 / 33.78 / 33.92 / 33.92 | 3.0–4.8% |

- A1/A2 漂移 **0.33%**（限 5%）；async on 的跨 launch 散布 <1%（17.84–17.99）。
- 主线程变化：物理开 **−15.756 ms/帧（−46.8%）**；物理关 −0.013 ms（噪声）。
- async 段 on(17.910) 与 off(17.454) 只差 0.46 ms ⇒ 物理在主线程上几乎不再花时间（工作搬走了）。
- **按契约：语义未过 ⇒ 以上不作性能结论，也不作为默认开启依据**；它只说明「主线程延迟确实降到 17.9 ms」这一事实。

## 4. worker 逐线程 CPU（回答「省下的时间是否被 worker 吃掉」）

`run-p3-ab.ps1` 的 `thread-cpu.json` 逐线程归属**判定不可靠**（C4D 线程数远超预期，渲染/线程池被算进 `worker_ms`），故改用**变体级进程 CPU 差分**（`worker-cpu-diff.py` + `run-cpu-diff.ps1`）：同一场景、同一帧段（预热 10 + 计时 60 帧，物理开），首尾各采一次 `GetProcessTimes`（kernel+user），除以帧数。

| 变体 | 墙钟 ms/帧 | 进程 CPU ms/帧 | 并行度（CPU/墙钟） |
| --- | --- | --- | --- |
| sync | **35.108** | **68.750** | 1.96 核 |
| async | **19.557** | **60.268** | 3.08 核 |

- 墙钟 **−15.55 ms/帧（−44.3%）**，与 A/B/A 的 −15.76 ms 一致。
- 进程总 CPU 只降 **8.48 ms/帧（−12.3%）** ⇒ **省下的主线程时间大部分没有被消灭，而是搬到了 worker 线程**：主线程延迟收益真实，但整机计算量只小幅下降（并行度 1.96 → 3.08 核）。
- 结论：async 是「延迟优化 / 并行化」，不是「计算量优化」。在有空闲核心的机器上收益成立；在 CPU 已被占满的场景（本仓库 t14 已证明负载会让绝对毫秒翻倍）收益会被吃掉。

## 4b. `-B` 精度档位（substeps）单独收益

同步插件、同一宿主会话内改 `MMD模型管理器` 的 `MODEL_PHYSICS_SUBSTEPS`(3200)，物理开、计时 30 帧（560–589）、预热 15：

| substeps | on median | p95 | 相对 3 档 |
| --- | --- | --- | --- |
| 3（默认） | 33.735 ms | 36.38 | — |
| 2 | 28.523 ms | 31.85 | −15.4% |
| 1 | **24.698 ms** | 26.63 | −26.8% |

- 结论：**单靠档位降不到 60 FPS 预算（16.7 ms）**；最省的 1 档仍有 24.7 ms（≈40 FPS）。
- 档位收益是「同一路径、确定性不变」的，可作 async 之外的独立选项；两者是否叠加需另测。


## 5. 门槛与判定

- 语义：**未过**（无常数 lag、无逐位相等；第一帧后整帧跳变并沿另一条轨迹发散）。
- 性能：按契约记**不可用**——主线程 33.666 → 17.910 ms（−46.8%）只说明「延迟降了」，不能作为默认开启依据。
- 资源：进程总 CPU 68.750 → 60.268 ms/帧（−12.3%），并行度 1.96 → 3.08 核 ⇒ 收益是并行化而非计算量下降。
- 档位：substeps 3/2/1 = 33.735 / 28.523 / 24.698 ms ⇒ 单独用档位到不了 16.7 ms。
- 默认开关：**不能默认开**（保持关闭）。要进入默认开，至少还缺：①影子世界按「逐帧真实输入」重放/预热，使 `async(N) == sync(N−lag)` 可证；②在 CPU 已占满的机器上复核延迟收益；③与档位叠加的组合测量。

## 6. 收尾与事故

- 每轮 `stop_method=Stop-Process forced=true`（用户授权），结束 C4D 进程 0、5557 无监听。
- 崩溃目录已归档并标 invalid（详见运行日志 `S:\tmp\cmt_vmd_profile_20261019\p3b-*.log`）。

## 7. 复现

```powershell
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1 `
  -Src S:\tmp\cmt_vmd_profile_20261019\p3b-src -WorkRoot S:\tmp\cmt_vmd_profile_20261019\p3b `
  -PatchShaPrefix 6eb55a37 -Parallel 8 -BuildRetries 1

pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p3-ab.ps1 `
  -SyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p3b\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p3b\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\sem -Execute -SkipTiming

pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p3-ab.ps1 `
  -TimingRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\main `
  -SemanticsRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\sem `
  -ReportPath docs\validation\vmd-physics-async-20261024\host-ab-p3b-result.md -RequireWorkerCpu
```

## 8. 自检

```
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p3-ab.ps1 `
  -TimingRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\main `
  -SemanticsRoot S:\tmp\cmt_vmd_profile_20261019\p3b\ab\sem `
  -BuildSummary S:\tmp\cmt_vmd_profile_20261019\p3b\build-summary.json `
  -ReportPath docs\validation\vmd-physics-async-20261024\host-ab-p3b-result.md `
  -ThreadCpuInformational -RequireWorkerCpu
→ CHECK_P3 OK assertions=73 failures=0 warnings=3 (exit 0)
```

- warnings：A1/B/A2 计时段各含 1 次崩溃重试（`-LaunchRetries` 生效，最终仍 5/5 有效轮），以及逐线程口径降级说明。
- `-ThreadCpuInformational`：`thread-cpu.json` 把 C4D 渲染/线程池计入 worker（sync 段也有大量「晚起」线程），故该指标只作参考；worker 结论改用第 4 节的进程 CPU 差分。

## 9. 未覆盖

- 未验证「补齐逐帧输入重放」后的等价性（需要改 P3 的 replay 接线，属下一轮实现）。
- 计时只覆盖 30 FPS、单场景（阿芙 2.0，479 刚体 / 748 关节）。
- 崩溃轮次按 invalid 处理，未纳入统计。
- `host-ab-p3-result.md`（t49）中的 −47% 数字属于旧语义状态，本轮不引用。
