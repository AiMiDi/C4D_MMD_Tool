# P5 轨迹分岔三通道归因（t73，只诊断不修）

**结论：`world_state`（影子世界初始状态/相位）是主因；`input_content` 与 `apply_fail_closed` 均已排除。**

一句话机理：worker 收到的动画输入与 sync 逐位相同（80/80），结果槽回写也每帧成功（78/78），但影子世界在
`StartStandaloneAsyncPhysics()` 里用 `MMDRigidBody::ResetTransform()`/`Reset()` 把 479 个刚体复位到 **PMX 初始
（bind）变换**，而不是复制主世界此刻已累计 539 帧的物理状态（变换、线速度/角速度、激活态、warm-start 缓存）。
于是第一份结果就把「从静止初态塌落」的一步（均值 97 mm、最大 160.6 mm）写进主世界，两条轨迹从此不可逆地分开
（chaos 放大），后续每帧位移量级与 sync 同阶（0.7–2.4×）、但逐位相等 0/81。

---

## 0. 工件与日志

| 项 | 值 |
|---|---|
| 候选 patch | `.dsh-switchman/vmd-perf-20261024/candidate-async-p5/candidate-async-p5.patch`，74,661 B，sha256 `fbd41b9a75c9f31165b796c2f28700792b4d43daaa0e6a4a56c9634a6b663389`（开工前后同一值，未改动） |
| p5 sync 工件 | `S:\tmp\cmt_vmd_profile_20261019\p5\sync\plugins\mmdtool\mmdtool.xdl64`，3,779,584 B，`c8ce92e6…3ec3` |
| p5 async 工件 | `…\p5\async\plugins\mmdtool\mmdtool.xdl64`，3,809,792 B，`9b67fcd3…51aa` |
| 诊断（t73）工件（首版，含 prestep/payload/apply_rigid） | `…\p5\diag\plugins\mmdtool\mmdtool.xdl64`，3,814,912 B，`7483e09d91a1eb12c42c06ff05336d7cd1dcf9ba628955e83239f708ad793d7d` |
| 诊断（t73）工件（终版，+ worker 侧 `wstep`） | 3,815,424 B，`04685e09904cf25ecbf2879c620c39b0be1f8a1ff5144a65c0ecb8f2cc216cf4`；四条日志串齐全，无 `CMT_RUNTIME_PROFILING=1` |
| 埋点位置 | 隔离 worktree `S:\tmp\cmt_vmd_profile_20261019\p5-src`，仅 `mmd_model_manager.cpp`（执行前骨骼哈希 + 帧/子步/模式）与 `mmd_model_runtime.cpp`（载荷哈希、回写返回值、worker 步） |
| 日志开关 | `CMT_ASYNC_STATS_LOG`；未设置时零输出（生产默认不写盘） |
| sync 段日志 | `S:\tmp\cmt_vmd_profile_20261019\p5\ab\diag2-archive-20261026T105042\a1-diag.log`（83 条 `prestep`） |
| async 段日志 | `…\p5\ab\diag3\b-diag.log`（84 `prestep` / 80 `async_payload` / 78 `apply_result` / 78 `apply_rigid ok` / 0 reject） |
| 探针载荷 | `…\p5\ab\diag2*/segments/A1-sync/semantics/probe.host.json`、`…\p5\ab\diag3/segments/B-async/semantics/probe.host.json` |
| 分析脚本 | `S:\tmp\cmt_vmd_profile_20261019\p5-prep\{patch-stats3.py, t73-analyze.py, t73-disp.py, sig.py}`；结果 `…\p5\ab\{t73-analysis.json, t73-disp.json}` |

**日志不改变行为（自证）**：诊断版与 p5 正式版在**同一协议、同一帧表**下产出的 82×479 刚体矩阵串 sha256 完全相同——

| 段 | p5 正式版 | t73 诊断版 |
|---|---|---|
| A1-sync | `370d907cc8b860042e693d55dbd52cef…` | `370d907cc8b860042e693d55dbd52cef…`（同值） |
| B-async | `14f8dc63860750193833a09f1329c965…` | `14f8dc63860750193833a09f1329c965…`（首版与终版诊断工件均同值） |

（`sig.py` 按帧序把每帧 479 条 `matrix_hex` 串起来做 sha256；A2-sync 与 A1-sync 亦相同 → 跨段可复现。）

---

## 1. 通道①「输入内容」：**排除**

对比口径：日志里 `prestep`（sync 段每帧、`mmd_model_manager.cpp:2501`）与 `async_payload`（async 段每帧、
`mmd_model_runtime.cpp:1113`）都是对 **625 个骨骼世界矩阵**做同一 FNV-1a 64 位哈希，取 **fixture 位精确** 比较。

| 比较 | 命中 |
|---|---|
| `payload(N)` vs `sync(N)` | **80 / 80 逐位相同**（首个不等帧：无） |
| `payload(N)` vs `sync(N−1)` | 0 / 80 |
| `prestep(N)`（sync 段） vs `prestep(N)`（async 段） | **83 / 83 相同**（帧 0 与 539–620 全覆盖） |

示例（`b-diag.log` 顺序对齐，同一帧内 `prestep` 紧接 `async_payload`）：

```
prestep   frame=18.000000 fps=30.000000 substeps=3 mode=seam_sync async=1 … hash=4a4dbceb388e3f5f
async_payload frame=540 n=625 hash=4a4dbceb388e3f5f
```

⇒ worker 用的就是**当帧**（N）的骨骼世界矩阵，不是 N−1；输入通道与 sync 完全一致，**不能解释分岔**。

> 附带纠正：t58 的「第一帧像晚一帧（452/479 与 sync(539) 相同）」来自**显示尚未应用任何结果**，不是载荷滞后。

## 2. 通道③「回写 fail-closed」：**排除**

`ApplyStandaloneAsyncRigidWorld()` 的返回值此前被丢弃（`mmd_model_runtime.cpp:1182`），诊断版改为接收并逐帧记录
（`apply_result`，`mmd_model_runtime.cpp:1255`；`apply_rigid ok`，`:1213`；拒绝分支 `:1166/:1178/:1192`）：

| 指标 | 实测（78 个被消费帧） |
|---|---|
| `epoch_match` | 78 / 78 = 1 |
| `rigid_ok` | **78 / 78 = 1**（每帧 `applied = 479`，`nullbody = 0`） |
| `rigid_n` | 恒 479 |
| `apply_rigid reject=empty/no_manager/size/map` | 0 行（一次都没有） |
| `async_rigid_identity_mismatch_` | 全程 **0**（progression `[0,0,0,0,0,0]`） |
| `applied frame` 序列 | `1,2,3,…,58` 连续（`head=[1..8]`、`tail=[53..58]`），无跳号/回退 |

⇒ 回写从未 fail-closed；`562 帧只有 27 个 kinematic 动` 不是回写被拒造成（见 §3 的「无结果可应用」解释）。

## 3. 通道②「世界状态 / 分层」：**主因**

### 3.1 逐帧位移分层（479 体，kinematic=27 由「async 在 540 帧有位移者」标定）

| 帧 | sync 均值 | async 均值 | 比值 | sync 动态 452 | async 动态 452 | async kinematic 27 | sync max | async max |
|---|---|---|---|---|---|---|---|---|
| 540 | 1.817 | **0.082** | 0.05 | 1.838 | **0.000** | 1.457 | 45.6 | 4.1 |
| 541 | 1.659 | **97.168** | **58.56** | 1.676 | **102.889** | 1.383 | 22.9 | **160.6** |
| 542 | 2.284 | 1.603 | 0.70 | 2.299 | 1.577 | 2.036 | 11.9 | 7.1 |
| 543 | 2.474 | 3.666 | 1.48 | 2.506 | 3.769 | 1.943 | 7.4 | 55.0 |
| 544 | 2.828 | 4.303 | 1.52 | 2.874 | 4.438 | 2.048 | 7.8 | 136.0 |
| 545 | 3.369 | 4.110 | 1.22 | 3.416 | 4.200 | 2.594 | 7.0 | 70.9 |
| 546 | 4.035 | 4.363 | 1.08 | 4.069 | 4.416 | 3.475 | 7.4 | 46.6 |
| 547 | 4.381 | 4.624 | 1.06 | 4.410 | 4.669 | 3.882 | 9.1 | 36.3 |
| … | | | 0.7–2.4 | | | | | |
| 618 | 1.308 | 2.169 | 1.66 | 1.322 | 2.234 | 1.087 | 6.0 | 58.5 |
| 619 | 1.209 | 2.133 | 1.77 | 1.215 | 2.195 | 1.103 | 6.2 | 29.7 |
| 620 | 1.088 | 2.625 | 2.41 | 1.075 | 2.704 | 1.313 | 5.1 | 90.4 |

seek 窗口（560 → 600 之后，`probe` 在 560 后执行 seek）：

| 帧 | sync 均值 | async 均值 | 比值 | async 动态 | async max |
|---|---|---|---|---|---|
| 560 | 4.034 | 6.263 | 1.55 | 6.399 | 77.5 |
| **561** | 3.487 | **77.229** | **22.15** | 81.647 | **231.1** |
| 562 | 2.876 | **0.144** | 0.05 | **0.000** | 5.0 |
| **563** | 2.265 | **97.149** | **42.89** | 102.838 | **160.8** |
| 564 | 1.770 | 1.952 | 1.10 | 1.953 | 11.7 |
| 565 | 1.263 | 2.711 | 2.15 | 2.789 | 33.4 |

**分层结论**：
- **kinematic 27 个全程与 sync 逐位一致**（如 540: 1.457279 vs 1.457279；541: 1.382602 vs 1.382602；542: 2.036197 vs 2.036197）——它们跟随骨骼动画，不参与物理积分，说明**输入与显示通路都是对的**。
- 差异 **100% 集中在 dynamic / dynamicAndBoneMerge 452 个**：540 帧位移 0.000（此时尚无结果可应用）、541 帧一次性
  102.889 mm 的「塌落补步」，之后每帧量级回到 sync 同阶但轨迹已偏。
- 总位移比 **2.751×**（async 308,733 mm / sync 112,245 mm）；逐体（sync>5 mm 的 479 个）p10 1.47 / p50 2.29 / p90 5.64 / max 11.97×。
- `lag=1` 逐位相等帧数 **0 / 81**。

### 3.2 机理（代码定位）

影子世界建立处（`S:\tmp\cmt_vmd_profile_20261019\p5-src\source\module\tools\object\mmd_model_runtime.cpp`，`StartStandaloneAsyncPhysics()`：`mmd_model_runtime.cpp:843`）：

```
:898   physics->AddRigidBody(rigid_body.get());
:903   rigid_body->ResetTransform();
:906   rigid_body->Reset(physics);
:90x    … SetActivation(true)
```

- `MMDRigidBody::ResetTransform()`（`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1036-1061`）取的是
  **motion state 的初始/绑定世界变换**，然后写回 `setWorldTransform`/`setCenterOfMassTransform`/`setInterpolationWorldTransform`；
- `Reset(physics)`（`MMDPhysics.cpp:1063+`）再把它按刚体重力/关节重新初始化（速度清零、激活态重置）；
- 代码**没有**从主世界刚体复制当前 `btTransform`、线速度/角速度、`setActivationState` 或 warm-start 缓存。

于是「影子世界第 1 步」= 从 bind 姿态塌落一步，而 sync 第 539 步 = 已经 18 秒演化后的真实状态；两者相差一个
**初始条件**，量级正是 541 帧观测到的 97–160 mm。此后两套 Bullet 世界各自积分，误差按混沌系统放大（每帧 0.7–2.4×，逐体最高 11.97×），
任何常数 lag 都无法对齐——这与 t36 离线夹具的结论一致：**逐位相等的前提是「相同初始状态 + 逐帧真实输入」，两者缺一不可**。
本轮的输入已确认正确（§1），因此缺的是初始状态。

### 3.3 540/561/563 三个尖峰与 562 的「只有 kinematic 动」

| 事件 | 数据 | 解释 |
|---|---|---|
| 540（起播第二帧） | async 动态 452 = 0.000 mm，kinematic = 1.457（=sync） | 首份结果还没被消费（`applied` 首值在 541 才出现），显示仍停在起始姿态；kinematic 由骨骼带动照常动 |
| 541 | 97.168 mm（58.6×），动态 102.889，max 160.6 | 第一份结果 = **从 bind 姿态塌落的第一步**（§3.2），一次性写回造成尖峰 |
| 561（seek 后首帧） | 77.229 mm（22.2×），max 231.1 | `RebuildStandaloneAsyncShadow()`（`mmd_model_runtime.cpp:832`）→ 再次 `StartStandaloneAsyncPhysics()` → 影子世界再次被 `ResetTransform()` 复位（同一根因） |
| 562 | async 动态 **0.000**，仅 27 kinematic 动 | 重建后首份结果尚未到达（与 540 同型：**无结果可应用**，不是回写被拒——§2 已证 0 次拒绝） |
| 563 | 97.149 mm（42.9×），max 160.8 | 重建后的第一份「塌落步」写回（与 541 同型、同量级） |

### 3.4 子步 / 帧率实际值

- `prestep` 记录（两种模式一致）：`fps=30.000000 substeps=3`，`mode=seam_sync`（sync 段）/`async=1`（async 段），`bones=625`。
- 影子世界 `SetFPS(document_fps × GetPhysicsSubsteps(op))` = `30 × 3 = 90 Hz`（`mmd_model_runtime.cpp:1362`），与主世界口径相同（t56 已对齐）。
- worker 每帧子步数（诊断版计数，非推断）：终版诊断工件在 worker 回调（`mmd_model_runtime.cpp:971` 之后）逐次打点，
  async 段共 **80 条 `wstep`**，逐条为 `dt=0.033333335 phys_fps=90.000000 need_substeps=3.000 thread=worker`
  → 每帧 **恰好一次**物理推进、**每次 3 个子步**（80 帧 = 80 条，与 80 条 `async_payload` 一一对应）；
  与 t69 的 `submitted≡worker_steps` 计数一致，无漏步/重复步。

## 4. 三选一判定

| 候选 | 判定 | 关键证据 |
|---|---|---|
| `input_content` | **排除** | `payload(N)` 与 `sync(N)` 80/80 逐位相同（§1）；`prestep` 跨段 83/83 相同 |
| `apply_fail_closed` | **排除** | 78/78 `rigid_ok=1`、`rigid_n=479`、`mismatch=0`、`applied` 连续（§2） |
| `world_state` | **主因（唯一存活候选）** | kinematic 27 全程逐位一致；452 动态刚体在 541 一次性塌落 102.889 mm（58.6×）；`ResetTransform()`/`Reset()` 复位到 bind 初态且不复制速度/激活态（§3.2）；seek 重建后同型复现（561/563） |

**给下一步的改动点（仅定位，未实施）**：在 `StartStandaloneAsyncPhysics()`（`mmd_model_runtime.cpp:843`）建立影子刚体后，
用主世界 `MMDRigidBody` 的当前 `btTransform`、`setLinearVelocity`/`setAngularVelocity`、`setActivationState`、
`setDeactivationTime` 覆盖 `ResetTransform()`/`Reset()` 的结果；或在首次 `Submit` 之前对影子世界做「热启动」——
但热启动只能减小误差、不能逐位相等，**逐位相等必须复制状态**。

## 5. 收尾

- C4D 进程 0；5557 无监听；两段均 `stop_method=Stop-Process forced=true remaining=0`（关闭窗口超 30 s，按用户授权强杀）。
- 产品树：`git status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency` **tracked 改动 0**（仅既有未跟踪 `source/utils/pmx_entity_apply_regression.hpp` 与 `res/*/MMDPESync.png`）。
- 候选 patch 未改动：`fbd41b9a…3389`，74,661 B（开工前后同值）。
- 未 push / 未提交 / 未改候选目录；所有埋点只在 `S:\tmp\cmt_vmd_profile_20261019\p5-src` 隔离副本内。

## 6. 未覆盖项

1. 只做了 82 帧（539–620）窗口，未跑更长时程；分岔是否随时间饱和未测。
2. 未实施修复，也未验证「复制主世界状态」后是否真能逐位相等；按 t36 离线夹具结论预期可行，但需真机复测。
3. 未单独量化 shadow world 的质量/摩擦/关节参数差异（本轮只测了初始状态与相位；参数一致性属 t56 已验证范围）。
