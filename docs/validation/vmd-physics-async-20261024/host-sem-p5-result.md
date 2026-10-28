# p5（D1 修复后）真机语义复测：lag 直方图 + 三个计数器（t69）

- 日期：2026-10-26
- 结论一句话：**`different_trajectory`，且与 p4 逐位相同 —— D1 修复没有改变轨迹，因为它在这条采样路径上一次都没被调用。**
- 工件：p5 patch `fbd41b9a…`；隔离 worktree `S:\tmp\cmt_vmd_profile_20261019\p5-src`（HEAD `3910564d…`）；产品树 tracked 0。

## 0. 结论摘要

| 问题 | 本轮答案 | 与上一轮（p4）对比 |
|---|---|---|
| 写回是否生效 | async **479/479** 刚体有位移，`frozen=0` | 一致（P3 的 27/452 分裂已不复现） |
| 是否有常数 lag 使逐位相等 | **否**；lag 直方图 `{"0":1,"none":81}`，`lag_constant=false` | 一致 |
| 最早不等帧 | **540** | 一致 |
| 最大偏差 | **254.9132 mm**（帧 553） | 一致（同一数值） |
| async / sync 总位移比 | **2.751×**（644.5370 / 234.3314 mm·刚体/帧） | p4 为 2.8×，同量级 |
| `worker_steps ÷ submitted` | **1.0**（每个被接受的帧恰好步进一次） | 新增指标 |
| `submit_skipped` / `result_covered` / `stale_dropped` | **全 0** | 新增指标 |
| 540 帧之前 async 是否在步进 | **否**：前 3 个管线实例 `submitted=0`；首个真实管线在帧 539 才产生 `submitted=1` | 新增结论 |
| D1 修复是否改变轨迹 | **没有**：p4 与 p5 的 82 帧 × 479 刚体矩阵 **sha256 完全相同** | 直接判据 |

## 1. 工件与构建

| 项 | 值 |
|---|---|
| patch | `.dsh-switchman\vmd-perf-20261024\candidate-async-p5\candidate-async-p5.patch`，74,661 B，sha256 `fbd41b9a75c9f31165b796c2f28700792b4d43daaa0e6a4a56c9634a6b663389` |
| 产品树 HEAD | `3910564d99757f31f98e4cf7c89f5c8cc0df644a`，`git status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency` 无 tracked 改动 |
| 构建方式 | `git worktree add --detach …\p5-src HEAD`（deps 从产品树 robocopy：bullet3 7603 / libMMD 2239 文件）+ `build-p3-ab.ps1 -PatchShaPrefix fbd41b9a -Parallel 8 -BuildRetries 1` |
| sync 工件 | `S:\tmp\cmt_vmd_profile_20261019\p5\sync\plugins\mmdtool\mmdtool.xdl64`，3,779,584 B，`c8ce92e643a83078fe0c7eac4d54877aeaaf4f21d43c4701490857590d393ec3` |
| async 工件（干净） | `S:\tmp\cmt_vmd_profile_20261019\p5\async\plugins\mmdtool\mmdtool.xdl64`，3,809,792 B，`9b67fcd339c70d9f0f49d9df4689bce04a1d6aaa014d5c9b5255d6f7fdf651aa` |
| async 工件（仅加计数器日志，本轮语义段实际使用） | `S:\tmp\cmt_vmd_profile_20261019\p5\async-diag\plugins\mmdtool\mmdtool.xdl64`，3,812,352 B，`d5f215d127494582c84d3a451dcdcc17d949343814bc5d0d878a772aebffe893` |
| profiling | 两棵树 `CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；三份 xdl64 均无 `CMT_RUNTIME_PROFILING=1` 标记 |
| configure / build 耗时 | 5.0 s + 85.4 s（sync）、4.6 s + 86.3 s（async）；diag 增量重建 2 次，各约 40–90 s |

> 计数器在 p5 里没有任何周期性输出（只有一条背压警告），因此在**隔离副本** `S:\tmp\…\p5-src` 里加了三类日志（`step` / `flush_*` / `stats final=1`，写 `CMT_ASYNC_STATS_LOG` 指定文件），并只重建 async 件。日志代码全部包在「环境变量未设置就空转」的早退里，**不改任何分支条件、不改任何提交/消费顺序**；产品树零写入。干净 async 件保留在 `p5\async\plugins` 未动。

## 2. 语义结果（A1-sync / B-async（含 seek 560→600）/ A2-sync，82 帧 × 479 刚体）

```
LAG1_ANALYSIS {"frames_compared": 81, "equal_frames": 0, "all_equal": false,
               "verdict": "different_trajectory", "earliest_mismatch_frame": 540,
               "worst": {"frame": 553, "max_deviation_mm": 254.9132}}
LAG_REFERENCE {"histogram": {"0": 1, "none": 81}, "frames": 82}
DISPLACEMENT {"a1": {"rigids_moved": 479, "rigids_frozen": 0, "max_displacement_mm": 103.3192},
              "b":  {"rigids_moved": 479, "rigids_frozen": 0, "max_displacement_mm": 286.7826}}
ROSTER 三段同 sha256 f16bc0b77a188007…，count 479，RIGID_INDEX 0..478 连续，dup 0，未解析骨 0
SEEK {"after_frame": 560, "to_frame": 600, "events": 1, "pre_equal": "0/21", "post_equal": "0/60",
      "post_earliest_mismatch": 561}
```

- 网格锚点旁证：540 局部 `07757cb6…`、560 `068d56c8…`、619 `c15545a9…`（A1/B/A2 全中；网格对物理不敏感，只作旁证）。
- A1 与 A2 两段 sync **82/82 帧逐位一致** ⇒ 宿主与比较链路自洽。

## 3. 每帧位移：两个「双步尖峰」

| 帧 | sync 平均位移 (mm) | async 平均位移 (mm) | 倍数 | async 有位移刚体数 |
|---|---|---|---|---|
| 541 | 1.8165 | **97.1678** | 53.5× | 479 |
| 542 | 1.6593 | 1.6027 | 0.97× | 479 |
| 560 | 4.3801 | 6.2634 | 1.43× | 479 |
| 561 | 4.0343 | **77.2287** | 19.1× | 479 |
| 562 | 3.4867 | 0.1441 | 0.04× | **27** |
| 563 | 2.8762 | **97.1493** | 33.8× | 479 |

- 除 541 / 561 / 563 三次尖峰外，async 每帧位移与 sync **同量级**（1.4–1.7×）。
- 562 只有 27 个刚体动（等于 kinematic 数）⇒ 该帧整帧**没有物理结果被应用**，紧接的 563 又一次补步尖峰。
- 逐刚体总位移比（sync>5 mm 的 479 个）：p10 1.47 / p50 2.29 / p90 5.64 / max 11.97。
- 与该轮之前的 p4 数据**逐位相同**（541 97.1678、561 77.2287、563 97.1493）。

## 4. 计数器（`stats final=1` 与逐帧 `step`）

5 个管线实例（`epoch=1..5` 各有 `stats final=1`；第 6 个实例在进程被 Stop-Process 时仍在跑，故只有逐帧数据、没有 final 行）：

| 实例 | submitted | produced | consumed | worker_steps | submit_skipped | result_covered | stale_dropped | in_flight_dropped | cancelled | applied_frame |
|---|---|---|---|---|---|---|---|---|---|---|
| epoch1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |
| epoch2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 |
| epoch3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 3 | 0 |
| epoch4 | 21 | 21 | 20 | 21 | 0 | 0 | 0 | 0 | 4 | 20 |
| epoch5 | 21 | 21 | 20 | 21 | 0 | 0 | 0 | 0 | 5 | 0 |

- `worker_steps ÷ submitted` = **21/21 = 1.000**（epoch4）⇒ **每个被接受的帧恰好步进一次**，没有「一帧步进多次」。
- `submit_skipped=0`、`result_covered=0`、`stale_dropped=0`、`in_flight_dropped=0`、`mismatch=0` ⇒ 背压、结果覆盖、陈旧拒绝、身份映射失败四条路径**本轮全部没有发生**。
- `applied_frame` 恒为 `submitted−1`（20/21）⇒ 管线自身确实只慢一帧。
- **计数器卫生问题（如实记录）**：epoch 提升（`RebuildStandaloneAsyncShadow`）时 `submitted/produced/consumed/applied` 被清零，但 `worker_steps` **没有清零**，于是 epoch6 的逐帧行出现 `worker_steps=79` vs `submitted=59`（差 20 = epoch4 遗留）。按「减掉遗留下来的 20」修正后仍是 **59/59 = 1.000**。这不是行为问题，是计数口径问题，但如果以后要用该计数器做门禁，需要一并修。

## 5. 540 帧之前 async 到底有没有在步进

- 场景建立阶段产生的 3 个管线实例（epoch1/2/3）**`submitted=0`、`worker_steps=0`** —— 一次都没有提交。
- 首个真实管线（epoch4）的第一条逐帧行：`step submitted=1 applied=0 worker_steps=0`，对应宿主开始逐帧求值的**第一帧 539**。
- 逐帧行共 80 条（epoch4 21 条 + epoch6 59 条），覆盖 82 个采样帧中的 80 个（seek 跳变与被重建吞掉的帧不计）。
- ⇒ **540 帧之前 async 没有步进过**；它从 539 起才建立世界并开始「每帧一步、显示慢一帧」。因此 t63 观察到的「541 一次性跳 97 mm」不是「之前偷偷补步」，而是**第 2 步就与 sync 走散**。

## 6. seek 前后

- `seek_events=1`（after 560 → to 600），前窗口 0/21、后窗口 0/60 逐位相等，后窗口最早不等帧 **561**。
- 561 尖峰 77.2287 mm、562 冻结（27 个 kinematic）、563 再尖峰 97.1493 mm —— 与 541 的同型「双步」指纹一致，说明 seek 触发的镜像重建沿用了同一条会多走一步的路径。

## 7. D1 修复是否改变轨迹：没有（直接证据）

- 把本轮与 t63（p4 工件）的 82 帧 × 479 刚体矩阵按 `frame|rigid_count|matrix_hex` 串起来做 sha256：
  - `A1-sync`：p4 `aedcf8b8bedc80e2ceb06484c51ce585` = p5 `aedcf8b8bedc80e2ceb06484c51ce585`
  - `B-async`：p4 `552ce718236f0e60c94964fcc79b8154` = p5 `552ce718236f0e60c94964fcc79b8154`
- 原因（代码事实）：`FlushStandalonePhysicsPipeline()` 在 p5 里**没有任何调用点**（全仓仅一次定义 + 一次声明）；真正被 7 处显式 `ExecutePasses` 走到的是 `FlushAsyncPhysicsForDocument()` → `FlushStandaloneAsyncPhysics()`，而本轮语义段**没有一行 `flush_*` 日志**（0 次调用）。
- ⇒ 纯播放 + 探针逐帧求值这条路径**根本不经过 flush**。D1 是契约回归（`FlushStandalonePhysicsPipeline` 返回值语义），但它不是本轮轨迹分岔的原因；恢复它对语义段是 no-op。

## 8. 收尾与现场

- 三段各 1 次 launch，收尾全部 `stop_method=Stop-Process forced=true remaining=0`；结束 `C4D=0`、`5557` 无监听。
- 无崩溃、无端口占用、无超时；未重试掩盖。
- 产品树 `git status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency` 无 tracked 改动；未 push / 未提交 / 未打 tag。
- 原始产物：`S:\tmp\cmt_vmd_profile_20261019\p5\ab\sem\`（`run-summary.json`、`segments\{A1-sync,B-async,A2-sync}\semantics\{probe.json,probe.host.json}`、`async-stats.log`、`host\`）。

## 9. 未覆盖 / 口径提醒

- 本轮只跑语义段（按调令省时间），**没有计时数字**，因此对「async 能否默认开」不构成任何性能结论。
- 语义段用的是「干净 p5 async + 只加日志」的 diag 件；日志严格旁路（未设环境变量即空转，运行中只写文件）。没有再把干净 async 单独跑一遍语义 —— 依据是它与 diag 只差日志代码，且 `p4↔p5` 逐位一致已说明日志没有改变轨迹；若后续要发布这个数字，建议用干净件复跑一次确认。
- 计数器只在 5 个实例上拿到 `stats final=1`；第 6 个实例被 Stop-Process 杀掉，没有 final 行（这是「收尾强制杀」的必然结果，不是丢失证据）。
- `worker_steps` 跨 epoch 不清零的问题见 §4，属计数口径缺陷。
- 离线夹具（t36）曾证明「相同初始状态 + 逐帧延迟输入」可以做到逐位相等；本轮真机仍不同，说明差异不在「lag 一帧」本身，而在**世界状态/输入内容**（下一步应对比 async 每次提交的骨骼载荷哈希与 sync 同帧骨骼姿态哈希）。

## 10. 复现命令

```powershell
# 1) 构建（隔离 worktree，产品树只读）
git worktree add --detach S:\tmp\cmt_vmd_profile_20261019\p5-src HEAD
robocopy C:\code\C4D_MMD_Tool\dependency\bullet3 S:\tmp\cmt_vmd_profile_20261019\p5-src\dependency\bullet3 /MIR
robocopy C:\code\C4D_MMD_Tool\dependency\libMMD  S:\tmp\cmt_vmd_profile_20261019\p5-src\dependency\libMMD  /MIR
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1 `
  -Src S:\tmp\cmt_vmd_profile_20261019\p5-src -WorkRoot S:\tmp\cmt_vmd_profile_20261019\p5 `
  -Patch C:\code\C4D_MMD_Tool\.dsh-switchman\vmd-perf-20261024\candidate-async-p5\candidate-async-p5.patch `
  -PatchShaPrefix fbd41b9a -Parallel 8 -BuildRetries 1

# 2) 语义段（只跑语义，不跑计时）
$env:CMT_ASYNC_STATS_LOG = 'S:\tmp\cmt_vmd_profile_20261019\p5\ab\sem\async-stats.log'
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p5\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p5\async-diag\plugins `
  -VmdPath 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd' `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p5\ab\sem -Execute -SkipTiming
```
