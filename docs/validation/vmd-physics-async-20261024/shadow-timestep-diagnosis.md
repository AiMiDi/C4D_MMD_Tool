# 影子世界 vs 主世界：每帧物理时间推进对照（t67，只读诊断）

> 口径：本文所有结论以 `candidate-async-p4/`（t65 PASS 的那一版，patch `c4a35f62…`）与
> `_build_msvc` 外的源码为准；只读，未改任何代码、未启宿主。
> **t63 事实（不重测）**：`lag=1` 0/81 命中、`lag_constant=false`、最早不等帧 **540**、最大偏差 **254.91 mm**、
> async 段位移 **286.78 mm** vs sync **103.32 mm（2.8×）**、写回 479/479 全动。

## 0. 结论先行

1. **两个世界的「每次步进推进多少物理时间」完全相同**：都是 `dt = 1/30 s`、固定子步 `1/90 s`、
   单次 `Update` 恰好 **3 子步 × 1/90 = 1/30 s**（§1/§2/§3 有逐项 file:line）。
   ⇒ **captain 的「影子是 3× 主世界」假设被证伪**：如果影子真的每步走 3 倍时间，位移应放大 9 倍量级
   （自由落体 ∝ t²），而实测只有 2.8×，且位移比接近「速度差 3 倍」而不是「时间差 3 倍」。
2. 因此 2.8× 只可能来自**每帧步进次数**或**输入姿态/速度被额外注入**（§4/§5）。
3. 顺带查出 **2 个确定缺陷**（与 2.8× 未必同源，但都会让真机行为偏离契约）：
   - **D1（P4 回归）**：`FlushStandalonePhysicsPipeline` 的 `AsyncPhysicsEnabled()` 分支在 P4 被删掉了
     （`work/.../mmd_model_runtime.cpp:1410-1437` 只剩同步 P1 逻辑）⇒ async 档下 7 处显式 `ExecutePasses`
     的 flush 会走同步状态机并**返回 false**，拿不到当前帧结果（T37-001 的契约在 P4 丢了）。
   - **D2（顺序缺陷）**：`StepStandaloneAsyncPhysics` 先抓骨骼载荷（`.inc:223-230`）再 `TryConsume` 应用上一帧结果
     （`.inc:244-246`）⇒ 载荷里含「上一帧被物理写回的骨骼」，与同步档「动画求值 → 步进 → 回写」的因果顺序不同。

## 1. 主世界（sync / seam_sync）

| 项 | 值 | 依据 |
| --- | --- | --- |
| 每帧 `Update` 次数 | **1** | `work/source/module/tools/object/mmd_model_manager.cpp:2458-2463`（`StepStandaloneAsyncPhysics` / `ProduceStandalonePhysicsFrame` 各一分支，同一帧只进一个） → `mmd_model_runtime.cpp:1462-1470` `StepStandalonePhysicsRaw` → `:1468 RunStandalonePhysicsStep(elapsed)` |
| 传给 `Update` 的 dt | **`1.f / fps_` = 1/30 s** | `mmd_model_manager.cpp:2452/2458/2462` 实参 `1.f / fps_`；`fps_ = document_fps`（`:2413`），默认 30（`mmd_model_manager.h:301`） |
| `SetFPS` 值 | **90**（30 × 3） | `mmd_model_runtime.cpp:1613` `physics->SetFPS(document_fps * GetPhysicsSubsteps(op))`；`GetPhysicsSubsteps` 默认 3（`:1003`） |
| 固定子步 `h` | **1/90 s** | `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:164` `stepSimulation(time, m_maxSubStepCount, 1.0 / m_fps)` + `:128-131 SetFPS` |
| `maxSubStepCount` | **10**（构造默认；产品代码从未调用 `SetMaxSubStepCount`） | `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.h:365` `int m_maxSubStepCount = 10;`；`SetMaxSubStepCount` 只在 `MMDPhysics.cpp:138` 定义，产品 `source/` 与候选 `new-files/` 均无调用（只有离线夹具 `eqtest/p4-equivalence.cpp:106` 显式设为 3） |
| 实际子步数 | **3**（`min(⌊(1/30)/(1/90)⌋, 10)`） | 同上；t14 插桩实测「恰好 3 子步/帧」与此一致 |
| **每帧累计物理时间** | **1/30 s = 0.03333 s** | 3 × 1/90 |

## 2. 影子世界（async / worker）

| 项 | 值 | 依据 |
| --- | --- | --- |
| 每帧 `Update` 次数 | **1**（每次 job 一次） | `new-files/cmt_physics_async.cpp:276` `step_(fixed_dt_, job);`；job 由 `.inc:249 Submit(...)` 每帧一次产生 |
| 传给 `Update` 的 dt | **`fixed_dt_` = `1.f/fps_` = 1/30 s** | `new-files/cmt_physics_async.cpp:94` `fixed_dt_ = fixed_dt > 0.F ? fixed_dt : 1/30`；`.inc:189` `async_physics_pipeline_.Start(1.F / fps_)`；`fps_ = 30` |
| 影子 `SetFPS` 值 | **90**（与主世界同一表达式） | `.inc:81` `ApplyPhysicsConfigToAsyncWorld(async_physics_manager_own_.get(), Get())` → `mmd_model_runtime.cpp:1259-1271` `shadow_physics->SetFPS(shadow_fps * GetPhysicsSubsteps(op))`；`shadow_fps = doc->GetFps()`（=30） |
| 固定子步 `h` | **1/90 s** | 同 §1，`MMDPhysics.cpp:164` |
| `maxSubStepCount` | **10**（同默认，未改） | `MMDPhysics.h:365`；候选代码无 `SetMaxSubStepCount` |
| 实际子步数 | **3** | 同上 |
| **每帧累计物理时间** | **1/30 s = 0.03333 s** | 3 × 1/90 |

### 2.1 关键：影子 worker 走的是同一套 `MMDPhysics::Update`

`.inc:953-971` 的 StepFn：`rigid_body->SyncBonePositionToPhysics(dt)` → `physics->Update(dt)` → `ReflectGlobalTransform()`，
`dt` 就是 `fixed_dt_`。**没有第二处 SetFPS、没有额外 Update、没有 dt 变体**（全仓 `SetFPS(` 只有两处：
`mmd_model_runtime.cpp:1613` 主世界、`:1271` 影子；`Update(` 只有 `mmd_model_runtime.cpp:1371` 主世界与
`.inc:170` 影子）。

## 3. 差异排查：重复步进（假设 4）

| 可能路径 | 结论 | 依据 |
| --- | --- | --- |
| async step + Flush 兜底 step | **不会**：P4 的 async Flush 只 `TryConsume`，不步进 | `.inc:333-353`（`FlushStandaloneAsyncPhysics`） |
| async step + seam（P1）路径 | **不会**：`Execute` 只进一个分支 | `mmd_model_manager.cpp:2448-2464`（`!SeamEnabled` / `AsyncEnabled` / `else` 三选一） |
| `StepStandalonePhysics` 内部再转一次 | **不会**：`AsyncEnabled` 时直接 return | `mmd_model_runtime.cpp:1442-1448`（`SelectPhysicsDispatch`） |
| `StepStandalonePhysicsRaw` 被并发调用 | **仅当** `async_physics_active_ == false` | `.inc:215-219` |
| 每帧 `Execute` 被 C4D 调用多次 | **会被时间闸门挡住**：同一文档时刻只有第一次 `time_changed` 为真 | `mmd_model_manager.cpp:2441`（`time_changed \|\| !is_animation_initialized_ \|\| physics_timing_changed`） |

⇒ 静态上看，两边都是「每帧 1 次 Update、每次 1/30 s」。**2.8× 无法由时间推进解释。**

## 4. 那么 2.8× 从哪来：两个方向，用现有计数器就能判死

### 方向 A：每帧步进次数其实 >1（worker 收到多次 Submit）

- 反证/取证一把抓：P4 的 `AsyncEventLog` 每 120 accepted 帧打一次
  `[CMT][physics-async] stats … submitted=… consumed=… worker_steps=… main_thread_steps=…`
  （`.inc` 的 stats 调用 + `cmt_physics_async.h` 的 `AsyncEventLog::Stats`）。
  在 t63 的 async 段日志里取 `worker_steps` 增量 ÷ 帧数：
  - ≈1.0 ⇒ 步数正确，**方向 A 死**，去看方向 B；
  - ≈3.0 ⇒ 每帧 3 步，问题在 `Submit` 被多调（`StepStandaloneAsyncPhysics` 的重入/多次分发），
    改法见 §6-F1。
- 我这边**没有** t63 的宿主日志（语义段落在 ds-impl2 的 `S:\tmp\...\p4b\ab\sem3\`，属于宿主侧证据），
  所以这条**待实测**，不写成已确认。

### 方向 B：输入姿态里被注入额外速度（当前更可疑）

链条（全在候选里，可静态核对）：

1. 帧 N 结束前，`ApplyStandaloneAsyncResult` 把影子结果写回主场景骨骼
   （`.inc:310-331`：`node->SetGlobalTransform(result.bone_world[i])` + `ApplyStandaloneBoneAdaptersToScene(touched)`）。
2. 帧 N+1 的 `StepStandaloneAsyncPhysics` **先**抓骨骼世界矩阵做载荷（`.inc:223-230`），**后**才 `TryConsume`
   并应用上一帧结果（`.inc:244-246`）。⇒ 载荷 = 「动画求值 + 上一帧物理回写」的混合姿态。
3. 影子 worker 用这份载荷 `SyncBonePositionToPhysics(dt)`：对 27 个 `Aligned`（kinematic）刚体，
   速度 = `(当前骨骼位置 − 上次骨骼位置) / dt`（`MMDPhysics.cpp:1092-1107` + `:349-357` / `:560-568`），
   而「上次位置」正是上一帧**影子自己**的物理输出。
4. 于是 kinematic 刚体每帧都额外带上「上一帧物理位移 / dt」的速度；Bullet 再按 3 子步积分，
   位移被叠加进轨迹 → 表现为「走得更远」，且从第一帧（540）就开始分岔。

同步档为什么没有这个问题：主世界每帧的输入是同一帧的动画求值结果，物理写回发生在**该帧步进之后**，
下一帧动画求值会重新覆盖骨骼位置；因果顺序是「动画 → 步进 → 回写」，不存在「物理输出回流成输入速度」。

**判定方法（1 行插桩即可）**：在 `.inc:967` 前对某个 kinematic 刚体记
`boneVelocity.length()`，同时在主世界 `mmd_model_runtime.cpp:1367` 前记同样量；async 段若显著大于 sync 段
（预期 ~3×），方向 B 成立。

## 5. 离线夹具为什么能对、真机为什么不能（五项逐项对照）

| 项 | 离线 `offline/p4-equivalence-v2.cpp` | 真机候选（P4） | 是否一致 |
| --- | --- | --- | --- |
| `SetFPS` | `physics_->SetFPS(kPhysicsFps)`（90，`:105`） | 主 90（`:1613`）/ 影 90（`:1271`） | ✅ |
| 每帧 `Update` 次数 | **1**（`world.Step(kFrameDt * dt_scale)`，`:335`/`:337` 各属不同分支） | 1（`.inc:170` / `:1371`） | ✅ |
| 传入 dt | `kFrameDt` = 1/30 | 1/30 | ✅ |
| 子步 | `physics_->SetMaxSubStepCount(kSubSteps)`（`eqtest/p4-equivalence.cpp:106`，`kSubSteps`=3）+ `Update(dt)`（`:175-180`）⇒ 3 子步 | `m_maxSubStepCount=10`（产品默认）+ `h=1/90` ⇒ 同样 3 子步 | ✅（dt=1/30 下等价；若 dt<3h 会分岔） |
| **输入时点** | `PushNodesToBodies()` 每帧用**动画/脚本输入**覆盖节点，再步进，再 `PullBodiesToNodes()`（夹具 `Step()`） | 先抓场景骨骼（含上一帧物理回写），worker 再 `SyncBonePositionToPhysics` | **❌ 不一致（方向 B）** |

⇒ 「离线能逐位相等、真机不能」的差异**不在前四项**（三项完全相同、一项等价），**只在第五项：输入时点**。

## 6. 修复方案（改动点 + 是否影响 patch）

### F1（对应方向 A，先测后用）：保证每帧恰好一次 step

- 改动点：`.inc:212-267` `StepStandaloneAsyncPhysics` 入口加帧号幂等（`if (async_submitted_frame_ == physics_frame_id_) return;`）
  + 在 `AsyncEventLog` 里加 `steps_per_frame` 统计。
- 影响：改 `new-files/runtime_p2_block.inc`（**在 patch 内**）⇒ patch sha 会变，需要重跑 verify 与真机工件。

### F2（对应方向 B，推荐）：把「输入姿态」与「物理输出」解耦

两种改法，二选一：

1. **载荷取动画求值后的姿态，不带物理回写**（最小改动）：在 `StepStandaloneAsyncPhysics` 里，抓载荷前对每个骨骼
   用「本帧动画求值结果」而非当前场景值。落地方式：在 `mmd_model_manager.cpp:2436`（`RunLayeredBonePass` 之后、
   物理之前）记录一份 `pre_physics_bone_world_` 快照，`:2458` 调用时传入。
   - 改动点：`work/.../mmd_model_manager.cpp:2436-2458` + `.inc:212`（签名加一个可选快照参数）。
   - 影响：属于 patch 内文件 ⇒ patch sha 变化。
2. **影子侧不把影子输出回灌成输入速度**（不动主线程数据流）：在 worker 里对 `Aligned` 刚体使用
   「上一帧载荷中的骨骼位置」而不是「上一帧物理输出」计算速度；实现上在 `AsyncJobPayload` 里带一份
   `prev_bone_world`（由主线程在提交时把上一帧载荷存下来）。
   - 改动点：`new-files/cmt_physics_async.h`（payload 字段）、`.inc:223-249`（缓存上一帧载荷）、`.inc:953-971`（用缓存算速度）。
   - 影响：patch 内（`new-files` + `runtime_p2_block.inc`）⇒ sha 变化。

### F3（与 2.8× 无关，但必须修）：恢复 flush 的 async 分支

- 改动点：`work/.../mmd_model_runtime.cpp:1410` 函数体首行加
  `if (AsyncPhysicsEnabled()) return FlushStandaloneAsyncPhysics();`（恢复 T37-001 语义）。
- 影响：patch 内（`mmd_model_runtime.cpp`）⇒ sha 变化；恢复后 7 处显式 `ExecutePasses` 才能拿到当前帧结果。

> 三者都落在 patch 内 ⇒ **一旦动手，t63 的 p4b 工件（`5075c675…`）即失效**，必须重建并重跑真机。
> 因此建议顺序：先用 §4 的日志判死 A/B → 只改一条 → 重建 → 真机语义段先跑通 lag=1，再谈性能。

## 7. 即使修好时间推进，仍可能与主世界不等（残余因素）

1. **IK 时序**：主世界 IK 在物理前/后各跑一次（`RunLayeredBonePass(doc,false)` / `(doc,true)`），影子只有物理；
   骨骼驱动到刚体的采样点可能差一次 IK。
2. **kinematic 更新顺序**：`SyncBonePositionToPhysics` 只处理 `Aligned` 刚体（`MMDPhysics.cpp:1094`），
   非 Aligned 的动态刚体由上一帧状态积分；两世界的 `m_prevBoneOrigin` 初值不同（影子从启用帧开始）。
3. **接触与 warm-start**：镜像重建正合 `Reset(physics)`/`SetActivation(true)` 三连，但主世界在 seek 后
   重建时机与影子不同（`.inc:202-210` vs `mmd_model_runtime.cpp:1283-1351`），接触历史起点不同。
4. **插值**：Bullet 的 `setInterpolationWorldTransform` 被 `ApplyStandaloneAsyncRigidWorld`（`.inc:304`）显式设置，
   主世界不设；渲染帧读取的是哪一份取决于采样时刻。
5. **C4D 求值节拍**：文档时间与渲染帧不一一对应（t14 已记录），异步消费发生在 `Execute` 内，采样点与宿主拍摄点可能差一帧。

⇒ 判据建议：**先要求 lag=1 稳定**（帧号单调、`worker_steps/frame≈1`），再要求逐位相等；
若逐位仍不成立，按上面 5 项逐个排除，而不是继续调 `SetFPS`。

## 8. 本次未能取证的项（待实测清单）

| 项 | 需要的证据 | 采集方式 |
| --- | --- | --- |
| 每帧实际步进次数 | `worker_steps / submitted`（async 段） | t63 日志里的 `stats` 行，或重跑加 §4 插桩 |
| kinematic 速度是否被放大 | async vs sync 段 `boneVelocity.length()` 对比 | §4 的 1 行插桩 |
| 输入姿态是否含上一帧物理输出 | 帧 N 载荷 vs 帧 N 动画求值（逐位） | 在 `.inc:230` 落一份载荷哈希，与 `RunLayeredBonePass` 后快照比 |
| flush 是否真的在 async 下失效 | `stale_consumes`/`flushed` 计数 | `AsyncEventLog` stats 行 |
