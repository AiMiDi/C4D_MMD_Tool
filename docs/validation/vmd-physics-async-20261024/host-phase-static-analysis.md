# P6 异步物理管线：帧号/相位语义静态核对（t80，只读）

- 核对对象：`candidate-async-p6/candidate-async-p6.patch`（sha256 `862a4d863901692be474dbdcaf8ffd95649dec268d2ed3b9703b4119eef236d9`）应用后的 `candidate-async-p6/work/` 副本。
- 方法：只读代码路径核对 + 归纳推导。**未启动宿主、未编译、未改动 `source/` 或候选目录**。
- 行号均指该 work 副本（`work/source/module/tools/object/...` 与 `new-files/...`）。

---

## 1. 一次 Execute 内的完整时序（file:line）

调用入口：`work/source/module/tools/object/mmd_model_manager.cpp:2438-2465`

```
2438  const Bool physics_enabled = IsPhysicsEnabled(op);
2441  if (time_changed || !is_animation_initialized_ || physics_timing_changed)
2443      if (needs_physics_reset)            { physics_frame_id_ = 0; ResetStandalonePhysics(); }       // 2445-2446
2448      else if (!physics_pipeline_.SeamEnabled()) { physics_frame_id_ = 0; StepStandalonePhysics(1/fps_); }  // 2451-2452
2454      else if (AsyncPhysicsEnabled())      { physics_frame_id_ = 0; StepStandaloneAsyncPhysics(1/fps_); }   // 2457-2458
2460      else                                 { physics_frame_id_ = ProduceStandalonePhysicsFrame(1/fps_); ConsumeStandalonePhysicsFrame(physics_frame_id_); } // 2462-2463
```

关键点：**三个物理分支互斥**。异步档下 `ProduceStandalonePhysicsFrame` / `ConsumeStandalonePhysicsFrame`（同步缝）**完全不执行**，`physics_frame_id_` 只是被清零（`:2457`），异步路径不使用它。

异步路径本体：`work/.../mmd_model_runtime.cpp:1043-1098`

| 步骤 | 行号 | 帧号来源 / 语义 |
| --- | --- | --- |
| 入口守卫 | 1046-1050 | `!async_physics_active_` 时退化为 `StepStandalonePhysicsRaw(elapsed)`（同步直算），**不计异步帧** |
| ① 抓载荷 | 1054-1061 | 逐骨 `GetBoneAdapter(i)->GetGlobalTransform()` → `bone_world`。这是**本帧 bone pass 之后、物理之前**的姿态 `P(N)`；此时 `bone_world` 内不含任何帧号 |
| ② 消费上一帧结果 | 1075-1077 | `TryConsume(epoch, 0, result)`：`expected_frame = 0` 表示**接受结果槽里任一帧号**；成功即 `ApplyStandaloneAsyncResult(result)` |
| ③ 提交本帧 | 1079-1083 | `frame = async_submitted_frame_ + 1`；`Submit(frame, epoch, bone_world, rigid_identity)` **只在被接受时** `async_submitted_frame_ = frame` |
| ④ 被拒 | 1084-1096 | 不推进 `async_submitted_frame_`（注释 `:1097`）：显示值保持上一份结果，**滞后增大而不跳帧** |

帧号变量的唯一定义点：

- `async_submitted_frame_`：**提交被接受时**推进到 `旧值 + 1`（`mmd_model_runtime.cpp:1082`）；语义是「已接受的最后一个载荷帧号」。Reset/Start 时清零（`:856` `async_frames_since_reset_ = 0;`，manager 成员默认 0）。
- `async_applied_frame_`：**只有真正应用结果时**写入 `result.frame`（`:1160`）。语义是「显示值对应的同步帧号」。
- `AsyncJobPayload::frame`：由主线程在提交时写入（`new-files/cmt_physics_async.cpp:150`），`WorkerLoop` 只把它原样带进结果（`:280 produced.frame = job.frame;`），**worker 不改帧号**。
- `physics_frame_id_`：异步档下恒为 0（`:2457`），与异步语义无关。

应用侧：`mmd_model_runtime.cpp:1141-1162`

```
1143  if (!async_physics_active_ || result.epoch != async_physics_epoch_) return false;     // 跨 epoch 丢弃
1148-1155  逐骨 node->SetGlobalTransform(result.bone_world[index]); Append(touched)
1156-1157  ApplyStandaloneBoneAdaptersToScene(touched)                                    // 写回 C4D 场景
1159       ApplyStandaloneAsyncRigidWorld(result.rigid_world)                              // 刚体快照按身份映射回主世界（1100-1138，fail-closed）
1160       async_applied_frame_ = result.frame;
```

worker 侧：`new-files/cmt_physics_async.cpp:246-300`

```
270-273  job = std::move(job_); has_job_ = false;            // 取出载荷（帧号随载荷走）
276      step_(fixed_dt_, job);                              // 一次 step：应用载荷 → 推进物理
277      ++worker_steps_;
279-285  produced.frame = job.frame; snapshot_(bone_world, rigid_world);   // 快照在 StepFn 内部推进之后
296-300  if (has_result_) ++result_covered_;                 // 覆盖计数（正常应为 0）
```

`step_` 的实现（`mmd_model_runtime.cpp:984-1002`）：先把 `job.bone_world` 写进影子节点（`:990-991`）→ `SyncBonePositionToPhysics(dt)`（`:997-998`）→ `physics->Update(dt)`（`:999`）→ `ReflectGlobalTransform()`（`:1000-1001`）；快照回调（`:1003-1007`）取**推进后**的骨骼+刚体世界矩阵。

**关键顺序事实（必须保持）**：抓载荷（`:1057-1061`）严格早于消费（`:1076`）。若顺序颠倒，本帧提交的载荷会被上一帧消费结果污染（骨骼刚被写成 `S(N−1)`），`verify.ps1` stage 15c/15d 正是锁这条（capture < consume < submit，且受控交换必须判负）。

---

## 2. 影子世界第 k 次 step 用哪一帧的载荷

设 LoadPMX/Reset 后第一次被接受的提交帧为 `f0`（`async_submitted_frame_` 从 0 变为 `f0` 的那次），之后每一次提交被接受都恰好 +1（`:1082`；被拒不推进，`:1084-1096`）。`WorkerLoop` 对每个被接受的 job 恰好执行一次 `step_`（`:270-277`），且 `produced.frame = job.frame`（`:280`）。

因此：

```
step_k  ⟷  frame = f0 + (k − 1)          (k = 1, 2, 3, …)
result(N) = 以 P(N) 为输入、从 result(N−1) 的末态继续推进一次 dt 得到的状态
```

即 **`step_k` 用的是 `frame_{f0+k−1}` 的载荷**，不存在 `frame_{k+1}` 这种错位：载荷帧号与 step 一一对应（前提是无丢步——`block_on_in_flight_` 默认真，提交阻塞等待，`cmt_physics_async.cpp:121-127`；丢步路径 `:134-147` 会把 `steps_skipped_` 计入并**不推进** `async_submitted_frame_`，因此不会造成帧号错位，只会减少总步数）。

---

## 3. 本该满足的等价关系（推导）

记：

- `P(N)` = 帧 N 的**物理前**骨骼世界矩阵集合（bone pass 之后）。
- `S_sync(N)` = 同步世界在帧 N 步进后的状态（骨骼世界矩阵 + 479 刚体世界矩阵）。
- `S_async(N)` = 影子世界处理完 `job(N)` 后的状态。

同步档（`mmd_model_manager.cpp:2462-2463`）：`S_sync(N) = Step(S_sync(N−1), P(N), dt)`，显示值即 `S_sync(N)`。
影子档：`S_async(N) = Step(S_async(N−1), P(N), dt)`，而帧 N 的 Execute **显示的是** `result(N−1)`（因为 `job(N)` 刚提交、结果尚未回来）。

归纳步：若在某次交棒处 `S_async(f0−1) == S_sync(f0−1)`，且两侧 `dt`、FPS、刚体数量与顺序、`P(N)` 全部相同，则对所有 `N ≥ f0` 有 `S_async(N) == S_sync(N)`。

于是**显示值**满足：

```
display_async(N) == result(N−1) == S_async(N−1) == S_sync(N−1)        （lag = 1 时）
一般化：display_async(N) == S_sync(N − lag),  lag = submitted − applied ≥ 1 且段内恒定
```

**三帧对齐**（把 Reset 帧、首步帧、应用帧放在同一条时间轴上）：

| doc 帧 | 主世界 | 影子世界 | 显示值 |
| --- | --- | --- | --- |
| 539（`needs_physics_reset`） | `physics_frame_id_=0` + `ResetStandalonePhysics()`（`:2445-2446`） | 尚未启动（异步 lazily 启动于首个异步帧）；Reset 尾部 `:1285-1286` 处 `Seed…FromMain()` 把**主世界当前刚体状态**种进影子 | `S_sync(539)` 的复位值 |
| 540（首个异步帧） | 不步进 | Start（`:862`）→ 种子化（`:921-932`）→ 提交 `job(540)`；worker 随后 step 一次 | 尚未应用新结果 → 仍显示种子态 = `S_sync(539)` 的物理后状态 |
| 541 | 不步进 | 消费 `result(540)` → 应用；再提交 `job(541)` | `S_sync(540)` |

由此得到两条**互相独立**的结论：

1. **语义上应有的等价式是 `async(N) == sync(N−1)`（lag=1）**；不应是 `sync(N−2)`。只有 worker 比主线程慢一帧（`has_result_` 未及时产出）时 lag 才增大，但**不得跳帧**，且任一时刻 `lag = async_submitted_frame_ − async_applied_frame_`。
2. t74 的「首次真正步进 sync=540 / async=541」与上式**不矛盾**：影子世界的**第一次 step 发生在 `job(540)`**（worker 计数在 540 就 +1），而**第一份结果被应用**发生在 541。若 t74 的探针统计的是「`async_applied_frame_` 首次推进」，读数必然是 541；这类「步进口径 vs 应用口径」差异足以单独解释 1 帧的表观差，**不需要代码里真的多等一帧**。

---

## 4. 与 t76 实测不符时的候选定位（各带可观测特征）

t76 实测：540 帧 async 的 452 动态刚体逐位等于 `sync(539)`、27 kinematic 跟随当前骨骼；541 起发散（4.34×）。第 540 帧现象**正是 lag=1 的正确表现**；因此需要解释的只有「541 起发散」。按可能性排序列出三个候选，每个都给出「若成立，539–546 逐帧数据应看到什么」，供真机判据直接判掉。

### C1（最可能）：交接起点不一致——种子化发生在主世界 Reset 之前/使用了旧主世界状态

- 位置：`mmd_model_runtime.cpp:862`（Start）、`:921-932`（Start 内三连后 `SeedStandaloneAsyncWorldFromMain()`）、`:1285-1286`（Ensure 尾部）、`:1395`（Reset 之后）；`mmd_model_manager.cpp:2445-2446`（Reset 分支）。
- 机制：若 Start 早于主世界 `ResetStandalonePhysics()`，影子拿到的主世界状态是 **Reset 之前**的状态；随后的 Reset 又改了主世界（`ResetTransform()`/`Reset(physics)`/`SetActivation(true)`），两侧 `S(f0−1)` 不再相等 → 从第一步起就沿不同轨迹积分，第一帧差异可能极小（位移同量级），随后放大。
- 可观测特征：帧 540 影子刚体快照 ≠ `sync(539)`（哪怕只有 27 个 kinematic 之外的小差异）；`async_seed_stats_.copied == bodies` 但 `worker_steps` 在 540 就 ≥1；把种子化移到 Reset **之后**（`:1391` 已有一次）后 541 的差异显著缩小。
- 判据数据：539–546 每帧 dump `async result(rigid_world)` 与 `sync` 同帧/前一帧的 `memcmp` 差异 word 数 + 首个不等帧号。

### C2：同帧重算路径绕过异步——`ReapplyStandalonePhysicsFrame(0)` 把冻结的主世界写回显示

- 位置：`mmd_model_manager.cpp:2467-2476`（`bone_morph_state_changed || control_state_changed || external_pose_refresh_` → `else ReapplyStandalonePhysicsFrame(physics_frame_id_)`，异步档 `physics_frame_id_ == 0`）；实现 `mmd_model_runtime.cpp:1451-1458`，其尾部调用 `ApplyStandalonePhysicsResults()`（`:1529` 的同步反射）。
- 机制：异步档主世界**从不步进**，其刚体状态是冻结的（仅被结果写回覆盖）。一旦走这条分支，会把「冻结主世界反射出来的骨骼」写回场景，覆盖掉异步结果，表现为该帧姿态跳变；而计数器（`submitted`/`consumed`/`applied`）**完全不变**，所以纯看计数会误判为正常。
- 可观测特征：发散帧恰好与「控制/形变/外部姿态变更」帧重合；该帧 `async_applied_frame_` 不变、无新 submit，但骨骼矩阵等于主世界刚体反射值；日志里没有 `[CMT][physics-async] flush` 记录（因为没走 flush）。判据：在 539–546 dump 每帧的 `applied/bone_hash/control_state_changed` 三元组，若 bone_hash 变化而 applied 不变 → C2 成立。

### C3：载荷捕获读到被写回的旧物理姿态（`P(N)` 被污染）

- 位置：`mmd_model_runtime.cpp:1054-1061`（抓取）与 `:1148-1157`（写回 `SetGlobalTransform` + `ApplyStandaloneBoneAdaptersToScene`）。
- 机制：若某些骨骼在本帧 bone pass 中**没有**被重新求值（例如 IK 链被跳过、`HasStaticPoseAnimationSegmentAtTime` 支路），其世界矩阵仍是上一帧「异步结果写回」的物理姿态；此时 `P(N)` 与同步档同帧的物理前姿态**不再相同**。t73 已证 `payload(N) == sync(N)` 只覆盖了写回尚未开始的帧（539 及之前），541 之后未证。
- 可观测特征：在 541–546 逐帧比较「异步档的 payload 哈希」与「同步档同帧的物理前骨骼哈希」——若出现首个不等帧且差异局限在未被动画求值的骨骼上 → C3 成立（这也是「payload 相等只到 540」的直接含义）。
- 最小修法（若成立）：载荷只在 bone pass 明确求值过的骨骼上取，其余骨骼用动画层的局部变换重算全局，或把「本帧求值掩码」随载荷提交、worker 侧只覆盖掩码内骨骼。

> 注：C1 与 C3 都会表现为「第一帧就分岔」，但 C1 的分岔出现在**刚体状态**（首帧 memcmp 就有差异），C3 的分岔先在**输入哈希**上暴露（payload 不等），再传导到刚体。C2 的分岔是**跳变型**（单帧姿态突变、计数不变）。三者用「刚体 memcmp / payload 哈希 / 计数不变但 bone_hash 变」三条正交观测量即可判开。

---

## 5. 应写入 verify 与真机判据的统一等价断言

```
设 lag(N) = async_submitted_frame_(N) − async_applied_frame_(N)
前置：lag(N) ∈ {1,2} 且在段内恒定；无 seek/无重建；
      submit_skipped == 0 且 result_covered == 0 且 stale_dropped == 0
      （即 submitted == consumed + 1 或 submitted == consumed，取决于在途结果是否已产出）

断言（对每个 N ∈ [f0+2, N_end]，lag 固定为 L）：
  A. 骨骼：display_async(N).bone_world == S_sync(N−L).bone_world       // 625×16 float 逐位
  B. 刚体：display_async(N).rigid_world == S_sync(N−L).rigid_world     // 479×12 float 逐位
     其中 452 个 dynamic 必须逐位；27 个 static/kinematic 也必须按 N−L 比（它们随骨骼，不随物理）
  C. 计数：async_applied_frame_(N) == N − L；且 applied 单调 +1（不跳帧）
  D. 反例（必须红）：把 L 改成 1 而实际为 2、或把参考帧改成 N、或禁用种子化，
     上述 A/B 必须出现非零差异——否则说明判据没有证伪力
```

与现有 `verify.ps1` 的口径关系：stage 15c/15d 锁「capture < consume < submit」的顺序；本节的 A/B 锁数值等价；C 锁帧号连续。真机判据建议直接采用 A/B/C 三条，并在 539–546 逐帧保存 `payload_hash`、`rigid memcmp`、`applied`、`submitted`、`consumed`、`stale_dropped`、`result_covered`，以便一次判开 C1/C2/C3。

---

## 6. 未覆盖与边界

- 本文是**静态核对**：不证明真机行为，只把「应当成立什么」写成可判定的形式；结论以 t76/t74 的实测为准。
- 未核对 C4D 侧 `GetBoneAdapter()->GetGlobalTransform()` 的求值时机（是否在 bone pass 后立即更新全局矩阵）——C3 成立与否取决于这一点，需要宿主侧在 bone pass 之后、物理之前打一次哈希。
- 未核对 `MMDPhysics::Update` 内部子步相位（t67 已单独分析；30 fps 下 3×1/90 与 1/30 位相等）。
- 未评估性能影响（本轮只读、不编译、不跑宿主）。
