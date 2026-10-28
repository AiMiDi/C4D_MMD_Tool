# P3（replay 异步物理）真机 A/B/A 验证结果（t49）

> 原始产物在 `S:\tmp\cmt_vmd_profile_20261019\p3\`（不进仓库）。本文件只写结论与表格。

## 0. 结论

**P3 的前提不成立**：默认路径（`CMT_PHYSICS_ASYNC=1`，`CMT_PHYSICS_PIPELINE` 不设）下，async 世界与 sync 世界从采样第 2 帧（540）起就分岔，且**不存在任何恒定滞后**——`async(N) := sync(N−lag)` 的假设被数据否掉。

一句话结论：**不能默认开 `CMT_PHYSICS_ASYNC`**。原因不是性能不够，而是语义不等价——async 档 479 个刚体里 **452 个在 82 帧内零位移（完全冻结）**，只有 27 个在动，说明物理驱动的刚体写回没有生效（不是「慢一帧」，是「没进来」）。

门槛判定（第 6 条）：语义失败优先于性能门槛 → `archive_invisible` 不适用，判 **reject_default_off**（保持默认关闭，需先定位输入/写回差异）。

## 1. 两版工件（隔离构建）

| 变体 | 路径 | 字节 | sha256 |
| --- | --- | --- | --- |
| sync | `S:\tmp\cmt_vmd_profile_20261019\p3\sync\plugins\mmdtool\mmdtool.xdl64` | 3,779,584 | `327f4fa6b4094838f64e460311a25d8f9b5f9228af8107f45aff2dbca8a8e6ef` |
| async | `S:\tmp\cmt_vmd_profile_20261019\p3\async\plugins\mmdtool\mmdtool.xdl64` | 3,810,304 | `d78407d3383753e281e076825456a54fb1903671fbfe6a6e778184ab5a3f7776` |

- 隔离 worktree `S:\tmp\cmt_vmd_profile_20261019\p3-src`：detached HEAD = 产品树 HEAD `3910564d99757f31f98e4cf7c89f5c8cc0df644a`；patch `candidate-async-p3.patch` 69,732 B sha256 `74788a624fba8770b7b47827b1fe45e88b52884043b4b91e17401131b54a6288`（只读应用，未改 `candidate-async-p3/`）。
- configure：`cmake -S <worktree>\sdk_2027 -B <build> -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；Cache 实测 `CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；两工件 ASCII 扫描均无 `CMT_RUNTIME_PROFILING=1` 标记。
- 构建后产品树 `git status --short -- source` tracked 改动 0。

## 2. 计时 A/B/A（同会话交替，安静门 CPU<20%，-MaxLoadPct 30）

命令：`run-p3-ab.ps1 -OutRoot S:\tmp\cmt_vmd_profile_20261019\p3\ab\main -Execute -SkipSemantics`
（每段 5 launch × 5 rep（on/off 交替取 median），预热 15 帧、计时 30 帧 560–589；语义段单独跑，见 §3）

| 段 | 变体 | on 每轮 median（ms） | on 段 median | off 段 median | 负载 |
| --- | --- | --- | --- | --- | --- |
| A1-sync | 同步 | 34.562 / 33.873 / 33.748 / 34.489 / 33.971 | **33.971** | 17.676 | 4.0–10.0% |
| B-async | 异步 | 18.102 / 17.953 / 18.353 / 17.906 / 17.915 | **17.953** | 17.664 | 2.9–7.5% |
| A2-sync | 同步 | 33.968 / 34.059 / 33.957 / 33.690 / 34.224 | **33.968** | 17.814 | 2.5–6.3% |

- **A1/A2 漂移 = 0.01%**（limit 5%）→ 同步两段可互换。
- 主线程收益（物理开）：sync 33.970 → async 17.953 = **−16.016 ms/帧（−47.15%）**。
- 物理关：17.745 → 17.664 = −0.082 ms（噪声级，符合预期：异步只影响物理步进）。
- 10/10（本段 15/15）轮 `module_match=True`：宿主加载的模块 sha 与本地工件逐一相等，A/B 不是同一份二进制。
- 按门槛（≥3.0 ms promote）：**性能单看远超门槛**；但语义失败（§3）优先，故结论仍是「不能默认开」——这 16 ms 现在买到的是「物理没生效」的画面，只能记作**潜力上限**。
- 有效轮次说明：A1 段 launch-2、A2 段 launch-1/launch-2 各因宿主崩溃重试后补上（`-LaunchRetries 2`），三段最终都是 5/5 有效 launch；`stable-measure` 因崩溃返回非 0，已按「有效率达标 + 确有重试」记为 warning（见 `check-p3-ab.ps1` 的 `crashed_attempts_*`）。

## 3. 语义段：**failed**（宿主实测，不是离线夹具推断）

测量口径：`launch-host.ps1` → `host-driver.py new-scene / import --pmx --vmd / import-motion / set-mode anim / physics on` → `probe-rigid.py --frames 539..620 --enable-rigid-display`；A1-sync（`CMT_PHYSICS_ASYNC=0`）与 B-async（`CMT_PHYSICS_ASYNC=1`，`CMT_PHYSICS_PIPELINE` 不设）各起一台独立宿主，同一配方、同一帧序列（升序 539→620，逐帧 `SetTime + ExecutePasses`）。

### 3.1 lag 直方图（82 帧，479 刚体逐位比对）

- 逐位相等只出现 **1/82** 帧（帧 539 = 采样起点）；`dominant_lag=0`、`lag_constant=False`、直方图 `{"0": 1}`。
- **lag 既不是 1 也不是 2，而是没有恒定滞后**。
- 「最像的 sync 帧」偏移乱跳：`async(545)~sync(539)`（偏移 6）、`async(550)~sync(540)`（10）、`async(560)~sync(540)`（20）、`async(580)~sync(589)`（−9）、`async(600)~sync(593)`（7）、`async(619)~sync(596)`（23）；即便「最像」仍有 24.8–71.6 mm 最大位置差。

### 3.2 逐位对齐与幅值

- 最早不等帧 = **540**（同帧 lag 0：452/479 刚体不等，最大位置差 **45.6 mm**）。
- 同帧最大位置差：帧 540 **45.6 mm**、帧 560 **102.8 mm**、帧 619 **94.4 mm**。
- `async(N)` vs `sync(N−1..N−4)` 也不逐位相等（除帧 539）。
- async 世界自身演化明显偏慢：539→540 只动 **4.08 mm**（sync 同段 45.6 mm）；539→619 累计 89.0 mm（sync 94.4 mm）。

### 3.3 位移方向分布（回答「4.08 mm 是均匀动还是少数动」）

对帧 540/541/560 逐刚体统计「539→f 的位移」：

| 帧 | sync 有位移刚体 | async 有位移刚体 | async 冻结刚体 | async max 位移 | sync max 位移 |
| --- | --- | --- | --- | --- | --- |
| 540 | 479/479 | **27/479** | **452** | 4.080 mm | 45.599 mm |
| 541 | 479/479 | **27/479** | 452 | 8.323 mm | 68.515 mm |
| 560 | 479/479 | **27/479** | 452 | 58.260 mm | 102.763 mm |

- 全 82 帧统计：**452 个刚体位移恒为 0.0000 mm**（完全冻结，连 0.001 mm 都没有），只有 27 个刚体有位移。
- 任一帧、任一 lag 0–4，async 与 sync **逐位相同的刚体数 = 0**。
- 结论：这不是「输入滞后一帧」，而是**物理驱动的 452 个刚体根本没收到写回**；动的 27 个是随骨骼层级一起动的（它们的位移幅度与骨骼驱动一致），恰好也是 async 下唯一能动的子集。

### 3.4 开关反证

- A1-sync 与 B-async 是两台独立宿主进程、同一配方；A1 的结果与 t34 完全可复现（锚点全中，见 3.5），说明配方稳定。
- 两段结果显著不同（0 个刚体逐帧相同）⇒ async 路径确实在跑，不是「两边都在同步算」的假象。

### 3.5 名册与变形锚点

- 刚体名册：479 个、`RIGID_INDEX` 连续 0..478、无重复、无未知骨骼，`roster_sha256 = f16bc0b77a1880076b39960fe1a8381ac642bd641811a761f67e0bce27a10803`（A1 与 B 相同）。
- 网格锚点（A1-sync）：540 局部 `07757cb6`/世界 `5361f419`、560 `068d56c8`/`e07de0ca`、619 `c15545a9`/`fba9fd24` —— 与历史锚点逐字节一致。
- B-async 的网格 sha 与 A1 同帧相同（82/82 帧），但这**不能作为等价证据**（t34 已证该场景网格对物理不敏感），只作「变形未被异步改变」的旁证。

## 4. 事故（作废轮）

- **A2-sync（语义段）**：probe 的首次 `exec_python` 调用时宿主崩溃（2026-10-25 21:41:03）。窗口标题 `Cinema 4D: Application Error`、进程不响应；`_BugReport.txt` 1,177,934 B + `minidump.dmp` 3,519,098 B，崩溃栈内含 `redshift-core-vc140.dll` 帧（`Load_Mmdtool` 段列出 mmdtool.xdl64）。处置：`_bugreports` 归档到 `...\_bugreports-archive-20261025T2150`（未删除）；该轮 **标 invalid**、**未静默重试**；pid 32680 强制结束，随后 C4D=0、5557 释放。
- **计时段（3 次崩溃尝试）**：A1-sync launch-2、A2-sync launch-1/launch-2，均在同一位置（probe 建场景的 `SCENE_PREPARE` exec_python）崩溃，`HostError: transport_timeout`；三次都被 `-LaunchRetries 2` 重试补上，最终三段仍各 5/5 有效 launch。崩溃包（9 个文件）归档到 `...\_bugreports-archive-20261025T215336`（未删除），崩溃尝试未计入 median。
- 崩溃在 **sync 段和 async 段都出现**（A2 是纯同步），且栈内无 mmdtool 帧（历史同签名：python311/Redshift），说明是宿主/驱动侧不稳定，不是 P3 候选引入；但**它同时说明本环境跑长时程 A/B 有成本**——每 5 launch 约 1–2 次崩溃。
- 影响：A2 语义缺失；语义判定用 A1 vs B 两段（A1/A2 一致性由计时段 0.01% 漂移与历史 A1≡A2 证据补足）。

## 5. 门槛与「能否默认开」

- 语义段 failed（第 3 条验收）⇒ **不能默认开**。
- 性能即使达标也只应视为「潜力上限」，与语义失败分开陈述。

## 6. 复现

```powershell
# 构建（隔离 worktree，不动产品树）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1

# 语义段（3 段各起一台宿主 + 逐帧刚体矩阵）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p3-ab.ps1 `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p3\ab\sem -Execute -SkipTiming

# lag 分析（A1 vs B）
python docs\validation\vmd-physics-async-20261024\analyze-p3-lag.py `
  --sync-a1 <sem>\segments\A1-sync\semantics\probe.host.json `
  --async-b <sem>\segments\B-async\semantics\probe.host.json `
  --frames 539-620
```

## 7. 未覆盖项

- A2 语义段因宿主崩溃缺失（作废轮，已归档）；A1≡A2 的跨进程逐位一致性沿用 t34 结论与本轮 A1 锚点复现，未在本轮重测。
- 冻结刚体的**直接机制**（是 `ApplyStandaloneAsyncRigidWorld` 被身份校验拒绝、还是结果槽未被消费）需要宿主侧计数器（t44 的 stats `final=1`）才能定论；本轮按只读约束未改代码、未加埋点，只给出行为证据。
- 计时段（第 2/3 条）在 CPU 竞争环境下受 ±5% 影响；A1/A2 漂移见 §2。

---

## 8. 自检脚本

```
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p3-ab.ps1 
  -TimingRoot S:\tmp\cmt_vmd_profile_20261019\p3\ab\main 
  -SemanticsRoot S:\tmp\cmt_vmd_profile_20261019\p3\ab\sem
```

实测：CHECK_P3 OK assertions=51 failures=0 warnings=3（warnings = A2 语义缺失 + A1/A2 各有崩溃重试）。
断言覆盖：三段有效轮次/样本数/安静门/reps、module_match 逐轮、A1-A2 漂移、收益与门槛带、lag 证据完整性（帧数/直方图/逐 lag 偏差表/最像帧表）、roster（数量/连续/无重复/无未知/同步异步同 sha）、三帧变形锚点、收尾（C4D=0、5557 无监听）、构建口径（profiling OFF + 无 marker + patch sha 前缀）、以及「收益达标但语义不等价时报告必须给出不默认开」的一致性。