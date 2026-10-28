# P6 真机验证结果（t76）

> 结论先行：**未通过**。取 armended 判据（动态 452 lag=1、运动学 27 同帧）——动态刚体 `async(N) == sync(N−1)` 逐位相等 **1/81**，最早不等帧 **541**，最差 **640.4123 mm @557**；运动学 27 同帧仅在 3/82 帧逐位相等（位置差 0.0000 mm，差异在旋转分量）。因此按契约**不跑计时段**，性能数字记「不可用」。

## 1. 工件与构建（patch `862a4d86…`，t79 r2 已批准版本）

- 隔离 worktree：`S:\tmp\cmt_vmd_profile_20261019\p6b-src`，HEAD = 产品树 HEAD `b4aa10a23603a864f8d79658e7907c8d094e16c2`。
- patch：`.dsh-switchman\vmd-perf-20261024\candidate-async-p6\candidate-async-p6.patch`，**82,956 B**，sha256 `862a4d863901692be474dbdcaf8ffd95649dec268d2ed3b9703b4119eef236d9`。
- 构建命令（`build-p3-ab.ps1 -Parallel 8 -BuildRetries 1`）：configure sync 4.6 s / async 7.6 s，build sync 103.1 s / async 104.8 s。
- 工件：

| 变体 | 路径 | 字节 | sha256 |
|---|---|---|---|
| sync | `S:\tmp\cmt_vmd_profile_20261019\p6b\sync\plugins\mmdtool\mmdtool.xdl64` | 3,779,584 | `3240237fe55cef04112b826e1fccc41b4578806563ca2543068c935efc995d59` |
| async | `S:\tmp\cmt_vmd_profile_20261019\p6b\async\plugins\mmdtool\mmdtool.xdl64` | 3,811,328 | `37358c1a9555dd30…`（完整值见 run-summary.json） |
| diag-async（埋点，仅取证） | `S:\tmp\cmt_vmd_profile_20261019\p6b\diag\plugins\mmdtool\mmdtool.xdl64` | 3,812,864 | `18f97ce78e3ae540badc2519f892ed9981c52b22c5f30f74c26ba590b714f161` |

- 两版 cache 均为 `CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`，两工件均无 `CMT_RUNTIME_PROFILING=1` 标记；构建结束 `product-tree-untouched tracked_changes=0`。

## 2. 语义（82 帧 539–620，479 刚体世界矩阵逐位比）

- 分类方式：不额外调用宿主——async 段帧 539→540 发生位移的 27 个即运动学（骨骼驱动），其余 **452** 为动态/动态骨骼合并。
- 判定（`analyze-p6-lag.py`，`S:\tmp\...\p6b\ab\lag-p6.json`）：

| 指标 | 值 |
|---|---|
| 动态 452：`async(N)` vs `sync(N−1)` 逐位相等 | **1/81**（仅 539 起点） |
| 最早不等帧 | **541** |
| 最大偏差 | **640.4123 mm @557** |
| 运动学 27：`async(N)` vs `sync(N)` 逐位相等 | **3/82**（位置差 0.0000 mm，差在旋转分量） |
| 参考 lag 表（动态） | lag0 1/82、lag1 1/81、lag2 0/80、lag3 0/79、lag4 0/78 |
| A1/A2 同步一致性 | 82/82 逐位相同 |
| roster | 479、RIGID_INDEX 0..478 连续、无重复、未解析骨骼 0 |
| 网格锚点 | 540 `07757cb6`/`5361f419`、560 `068d56c8`/`e07de0ca`、619 `c15545a9`/`fba9fd24` 全中 |

- 与旧 patch（`3c18878…`）对比：旧版同样 `different_trajectory`（0/81、最早 540、动态 540 时 452 已与 sync(539) 逐位相同），新版起点行为一致、发散帧从 540 推到 541。

## 3. 539–546 逐帧取证（instrumented diag，env `CMT_ASYNC_STATS_LOG`）

日志：`S:\tmp\cmt_vmd_profile_20261019\p6b\ab\diag-b-async4.log`（80 行）；解析：`analyze-diag-p6.py` → `diag-summary.json`。

### 3.1 管线计数（epoch 5，帧 540 起）

| submitted | applied | produced | consumed | worker_steps | submit_skipped | result_covered | stale_dropped |
|---|---|---|---|---|---|---|---|
| 1..7 逐帧 +1 | 0..6（**恒为 submitted−1**） | = submitted | = produced | = submitted | 0 | 0 | 0 |

- 关机时 `stats final=1 epoch=9 submitted=9 applied=0 produced=9 consumed=7 worker_steps=9 submit_skipped=0 submit_waited=0 result_covered=0 stale_dropped=0 in_flight_dropped=0 cancelled=8 mismatch=0`（`cancelled=8` 是 epoch 重建时的正常取消）。
- worker 行：`wstep k=1..9 job_frame=1..7,1,2`（seek 后重建，epoch 8 的 k 继续累加、job_frame 重置为 1）→ **每个主线程提交恰好一次 worker 步进，`step_index == job_frame`，无跳步/重复**。

### 3.2 载荷哈希（C3 相关）

- 帧 540 `payload bones=625 hash=4a4dbceb388e3f5f`、541 `41e91a1ffdc10b95`、542 `f713cb650ce4027d`…（逐帧不同、非零）。
- 局限：本轮只在 async 侧采样，缺「同帧同步物理前的骨骼哈希」同口径对照，因此**无法直接排除 C3**；t73 曾在旧 patch 上证过 `payload(N) == sync(N)` 80/80。

### 3.3 同帧物理分发次数（C2）

- 全部 doc 帧 `dispatch` 均为 **1 次**；唯一 2 次出现在 `doc_seconds=20.0`（seek 目标帧 600），属设计内重建。
- 540 帧 `worker_steps=0`（首步尚在 worker 中）、`reset=0`；17.9667s（539）`reset=1` 且其前有两行 `seed bodies=479 copied=479 skipped=0 ok=1`（P6 双次种子化）→ 种子化在 Reset 前后各一次且都成功。

## 4. 三选一结论

| 候选 | 结论 | 证据 |
|---|---|---|
| C1 种子化早于主世界 Reset | **排除** | 539 帧 Reset 前有一次 seed、Reset 后（epoch 5）再 seed 成功；540 帧动态 452 与 sync(539) 逐位相同；540 帧 worker_steps=0 |
| C2 同帧重算绕过异步（额外一次主世界步进） | **排除** | 逐帧 dispatch 恰 1 次；applied 严格 = submitted−1 单调 +1；submit_skipped/result_covered/stale 全 0 |
| C3 载荷被写回污染 | **未排除、也无正面证据** | payload 哈希逐帧非零且变化；但缺 sync 侧同口径对照，本轮不能直接判 |

**实测指向的新候选（C4）**：分岔恰发生在「第一份影子结果被写回的那一帧（541）」——此时输入（payload 与 sync 同帧骨骼一致，t73 已证）与世界起点（540 动态逐位相同）都已对齐，唯一变化是「影子世界自己的第 1 步结果」。因此差异更可能来自**影子 Bullet 世界与主世界的单步配置口径**（固定步长/最大子步/求解器迭代/插值），而不是输入相位或写回链路。t73 记录影子侧 `wstep dt=0.033333335 phys_fps=90.000000 need_substeps=3.000`，主世界同轮口径尚未采样，建议 P7 前先补这一条对照。

## 5. 计数与收尾

- 三段语义（A1-sync / B-async+seek 560→600 / A2-sync）均完成；`seek_events` 记录 1 次（after 560 → to 600，前后 rigid_sha256 不同）。
- 崩溃：无。宿主收尾全部 `stop_method=Stop-Process forced=true`、`remaining=0`、最终 `C4D=0`、`5557` 无监听。
- 产品树：`git status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency` 仅 3 条既存 untracked（`res/R20-S24/MMDPESync.png`、`res/S24_up/MMDPESync.png`、`source/utils/pmx_entity_apply_regression.hpp`），tracked 改动 0；未 push/commit/tag。

## 6. 未覆盖

- 计时段未跑（按契约：语义不过即记不可用）。
- C3 未做实（缺 sync 侧同口径 payload 哈希）。
- 影子/主世界单步配置（固定步长、子步数、求解器参数）未逐项对照——这是当前最强线索。
- 运动学 27 的差异在旋转分量（位置一致），需在 P7 里按「骨骼→刚体变换的旋转分量」单独核对。

## 7. 自检脚本（`check-p6-ab.ps1`）

- 对本次产物（`-ResultDir S:\tmp\cmt_vmd_profile_20261019\p6\ab`）：`CHECK_P6 OK assertions=38 failures=0`，**exit 0**（断言覆盖：lag 证据完整 + 判定与证据一致、三段 probe 479 刚体/82 帧、seek 事件、埋点计数器干净且 applied 逐 epoch = submitted−1、同帧二次分发仅 seek 帧、两版工件 sha 不同且 profiling OFF、产品树 tracked 0、C4D=0 与 5557 无监听）。
- 负向验证（证明断言不恒真）：把 `lag-p6.json` 改成 p5 口径（schema `vmd-p5-lag/1`、删掉 dynamic/kinematic 拆分）后重跑 → `FAILURES: result_dir_present, lag_schema_v2, lag_has_dynamic_split, dynamic_count`，**exit 1**。

## 8. 命令与复现

```powershell
# 构建（隔离 worktree，patch 862a4d86…）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1 `
  -Src S:\tmp\cmt_vmd_profile_20261019\p6b-src -WorkRoot S:\tmp\cmt_vmd_profile_20261019\p6b `
  -Patch C:\code\C4D_MMD_Tool\.dsw-switchman\vmd-perf-20261024\candidate-async-p6\candidate-async-p6.patch `
  -PatchShaPrefix 862a4d86 -Parallel 8 -BuildRetries 1

# 语义三段（A1/B(+seek)/A2）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p6b\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p6b\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p6b\ab\sem -Execute -SkipTiming

# 分析（动态 452 / 运动学 27 分离）
python docs\validation\vmd-physics-async-20261024\analyze-p6-lag.py `
  --root S:\tmp\cmt_vmd_profile_20261019\p6b\ab\sem2-archive-20261026T125659 `
  --out S:\tmp\cmt_vmd_profile_20261019\p6b\ab\lag-p6.json

# 取证埋点（payload/step/wstep/dispatch/stats）
$env:CMT_ASYNC_STATS_LOG='S:\tmp\cmt_vmd_profile_20261019\p6b\ab\diag-b-async4.log'
python docs\validation\vmd-physics-async-20261024\patch-p6b-stats.py
python docs\validation\vmd-physics-async-20261024\analyze-diag-p6.py

# 自检
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p6-ab.ps1 `
  -ResultDir S:\tmp\cmt_vmd_profile_20261019\p6\ab
```
