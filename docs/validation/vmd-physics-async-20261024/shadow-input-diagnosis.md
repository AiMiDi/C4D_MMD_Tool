# P3 影子物理世界分岔诊断（收窄版：为什么 452/479 刚体彻底冻结）

> 状态：定稿（第二轮，按 t49 新指纹收窄）。**只读诊断**——未改 `source/`、未改任何 `candidate-*`、未启宿主、未跑完整构建。
> 新指纹（t49 原始矩阵离线重算）：async 段 **452/479 刚体位移恒 0.0000 mm**（冻在初始变换），**27 个**在动；static+kinematic 恰 27、dynamic 450 + dynamicAndBoneMerge 2 = 452。
> 结论口径：每条给「成立 / 不成立 / 需宿主实测」，并把「该看哪个计数器」写到能直接交给 t52 埋点采样。

## 0. 一句话结论

冻结指纹 **不是**「刚体顺序对不上导致每帧整帧拒绝」——静态读码可以**排除**这个假设（下面第 2 条给出四条反证）。真正需要 t52 用埋点区分的是两类：**(A) 写回根本没被调用**（`ApplyStandaloneAsyncResult` 早退或未消费），**(B) 写回调用了但写的是另一批刚体对象**（主世界 `GetRigidBodys()` 与场景 `MMDRigidObject` 绑定的不是同一批）。链路上共有 **6 个静默早退点**，其中 3 个不产生任何日志或计数，这正是「看起来在跑、实际没写回」的成因。

## 1. 优先级 1：分发 → produce → 消费 → 写回 的完整链路与静默早退

| 序 | 环节 | file:line | 静默早退 / 隐患 |
| --- | --- | --- | --- |
| 1 | 帧内分发 | `candidate-async-p3/work/source/module/tools/object/mmd_model_manager.cpp:2444-2457`：`if (physics_enabled)` → `if (time_changed \|\| !is_animation_initialized_ \| \| physics_timing_changed)` → `else if (AsyncPhysicsEnabled()) StepStandaloneAsyncPhysics(1.f/fps_)` | `time_changed == false` 的帧（播放器暂停/同帧重算）整段跳过，不产生计数；这是**正常**语义，但宿主采样若落在暂停帧会误判「没动」 |
| 2 | 异步步入口 | `new-files/runtime_p2_block.inc:193-200`：`if (!async_physics_active_ \|\| !async_physics_manager_own_) { StepStandalonePhysicsRaw(elapsed); return; }` | **静默降级到同步路径**，无日志无计数；一旦 `async_physics_active_` 被 `ShutdownStandaloneAsyncPhysics()`（`.inc:183-191`）清掉，后续全部帧都在主线程同步算，采样看起来「async 世界不动」 |
| 3 | 消费 | `.inc:225-227`：`if (pipeline.TryConsume(async_physics_epoch_, 0, result)) ApplyStandaloneAsyncResult(result);` | `TryConsume` 因 epoch 不符 / 结果未就绪而返回 false 时**静默跳过**（`cmt_physics_async.cpp:141-168`，epoch 不符会 `has_result_=false; ++stale_dropped_`）；`stale_dropped` 有计数但不入日志 |
| 4 | 应用 | `.inc:291-315` `ApplyStandaloneAsyncResult`：`if (!async_physics_active_ \|\| result.epoch != async_physics_epoch_) return false;` | **静默 return false**，无计数。`async_physics_epoch_` 在 `ShutdownStandaloneAsyncPhysics`（`.inc:187`）里自增，若某次 reset 后 worker 仍用旧 epoch 交作业，此后**每一帧都在这里被丢弃**——与「452 全冻」完全吻合的外观 |
| 5 | 刚体写回 | `.inc:250-289` `ApplyStandaloneAsyncRigidWorld`：`rigid_world.size() != main_rigid_identity_.size() \|\| != rigid_bodies->size()` → `++async_rigid_identity_mismatch_; return false;`；`MapRigidSnapshotToMain` 失败同样 `++…; return false` | 有计数**但不入日志**；整帧拒绝后骨骼侧仍会写（骨骼先于刚体写，`.inc:296-311`），因此宿主会看到「骨骼在动、刚体全冻」——**正是 t49 指纹** |
| 6 | flush | `.inc:314-340` `FlushStandaloneAsyncPhysics`：`if (async_submitted_frame_ == 0 \|\| async_applied_frame_ == async_submitted_frame_) return true;`；`mmd_model_manager.cpp` 的 `FlushStandalonePhysicsPipeline` 先 `if (AsyncPhysicsEnabled()) return FlushStandaloneAsyncPhysics();` | flush 只在显式 `ExecutePasses`（7 处接线）与 seek/导出触发；常规播放**不 flush**，所以「flush 没报错」不能证明写回发生过 |

**关键结构性风险（第 4+5 条的组合）**：骨骼写回（`.inc:296-311`，写 adapter 全局矩阵 + `ApplyStandaloneBoneAdaptersToScene`）与刚体写回（`.inc:309` → `ApplyStandaloneAsyncRigidWorld`）在**同一个函数里顺序执行**，但前者无校验、后者有 fail-closed 校验。任何一次刚体侧拒绝都会产生「骨骼动、刚体冻」的精确指纹，而日志里**什么都不会出现**。

## 2. 优先级 2：写回路径是否可能每帧整帧拒绝？——**静态排除顺序错位**

| 判断点 | 证据 | 结论 |
| --- | --- | --- |
| 影子刚体顺序 | `source/module/tools/object/mmd_rigid_manager.cpp:594-602`：按 `RIGID_INDEX` 收集子对象并 `std::stable_sort`，然后逐个 `physics_manager->AddRigidBody()`（`:651`） | 影子顺序 = **RIGID_INDEX 升序**，与主世界同一函数、同一输入树 |
| 主世界刚体顺序 | 同一 `BuildStandaloneRigidBodies`（`source/module/tools/object/mmd_model_runtime.cpp:705-712`）在主世界管理器上跑一次 | 与影子**同序**（deterministic） |
| 身份表 | `CollectStandaloneRigidIdentities`（`runtime_p2_block.inc:96`）= PMX `RIGID_INDEX` 升序下标；`main_rigid_identity_` 直接复制同一份（`.inc:97`） | 映射为**恒等置换**，`MapRigidSnapshotToMain`（`cmt_physics_async.cpp:27-60`）不会失败 |
| 启动期 fail-closed | `.inc:98-114`：`identity_count != shadow_count \|\| != main_count` 时拒绝启动并打日志 | 若顺序天然不同，**异步档根本起不来**（会在启动日志里看到 `async physics refused: rigid identity mismatch`），而 t35 已验证默认路径可达 |
| 数量 | `AddRigidBody()` 在 `node == nullptr`（unbound）时**仍会创建**（`mmd_rigid_manager.cpp:651-668`：先 Add 再判 node） | 影子与主世界刚体数一致 |

⇒ **「顺序天然不同 → 每帧整帧拒绝」不成立**（四条独立反证）。`async_rigid_identity_mismatch_` 若不为 0，只可能来自运行期**尺寸/内容变化**（例如重建世界后身份表未同步、或 `rigid_world` 快照条数与身份表不一致），这仍可用计数器一句话判死。

**判别式（给 t52）**：同时打印 `async_rigid_identity_mismatch_` 与 `ApplyStandaloneAsyncRigidWorld` 的返回值：

- 若 `applied_calls > 0 && applied_ok == 0` → **假设 (B1)**：写回被整帧拒绝（看 mismatch 计数是否增长）。
- 若 `applied_calls == 0` → **假设 (A)**：写回根本没被调用（看第 1 条链路 2–4 的静默早退：`async_physics_active_`、`result.epoch`）。
- 若 `applied_ok > 0` 但宿主仍观测 452 冻结 → **假设 (B2)**：写回写的是另一批刚体对象（场景 `MMDRigidObject::mmd_rigidbody_` 绑定的不是 `physics_manager_own_->GetRigidBodys()` 里的那批），需比对指针。

B2 的静态线索：场景刚性体对象显示读 `source/module/tools/object/mmd_rigid.cpp:692` `mmd_rigidbody_->GetTransform()`；而 `libmmd::MMDRigidBody::GetTransform()`（`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1131-1141`）读的是 `m_rigidBody->getCenterOfMassTransform()`（**活体**，不是缓存）。所以只要 `applied_ok>0` 且指针是同一批，显示必须动——这让 B2 成为「可一行指针日志判死」的假设，而不是玄学。

## 3. 其余四条（按原任务描述）

| # | 问题 | 结论 | 证据 | 备注 |
| --- | --- | --- | --- | --- |
| 2 | 步进口径是否一致 | **成立（但已不是冻结的解释）** | 主世界 `work/.../mmd_model_runtime.cpp:1580` `SetFPS(document_fps*GetPhysicsSubsteps(op))`（默认 3 → 90）+ `:897 physics->Update(elapsed)`；影子 `runtime_p2_block.inc:57-58` 只 `Create()`、**全文件无 `SetFPS`** → 默认 `m_fps=120., m_maxSubStepCount=10`（`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.h:364-365`），`runtime_p2_block.inc:151 physics->Update(dt)` | 主 3×1/90 vs 影 4×1/120：解释「lag 非恒定/乱跳」，**不解释整帧冻结**（冻结的刚体是位移恒 0，不是走得慢） |
| 3 | 丢步计数是否 0 | **需宿主实测** | 计数在 `cmt_physics_async.cpp:103/118/125`，日志由 t44 `AsyncEventLog` 输出；本机 t49 产物 `S:\tmp\cmt_vmd_profile_20261019\p3\ab\**\*.log` 里 `[CMT][physics-async]` **0 命中**（该轮工件早于 t44 日志） | 采样时可一并取 `submit_skipped / submit_blocked_result_pending / in_flight_dropped` |
| 4 | 初始状态是锚定还是冷启动 | **冷启动** | `.inc:50-55` 只拷骨骼全局矩阵；刚体由 `BuildStandaloneRigidBodies` 按 PMX 定义重建（`.inc:69-91`）→ 位姿=PMX 初始、速度=0 | t38 实测：冷启动首帧 1.5754 mm、40 帧 8.9137 mm；只锚定仍 53.32 mm。「452 冻结」不能全归此项（冻结是恒 0，不是缓慢漂移） |
| 5 | 写回是否反馈 | **成立** | `.inc:291-315` 写回骨骼 adapter + `ApplyStandaloneBoneAdaptersToScene`；刚体侧 `.inc:250-289` 只写 `setCenterOfMassTransform/setInterpolationWorldTransform`，**不写速度与激活态** | 下一帧 `mmd_model_runtime.cpp:414-418` 从场景重建输入 → 闭环；差值按物理敏感性放大 |
| 6 | replay 是否被触发 | **待实测（倾向未触发）** | `ReplayStandalonePhysicsToFrame` 只在「中途开启 / seek / 显示 flush」路径；`async_frames_since_reset_` 无日志打点 | 加一条 `[CMT][physics-async] replay from=… to=… steps=…` 即可；若采样窗口内有 replay，该段不能参与对齐 |

## 4. 原第 1 条（`bone_world` 是 IK 前还是后）——简短回答

**是 pre-physics 层 IK 之后的全局矩阵**：分发点在 `mmd_model_manager.cpp:2436`（`RunLayeredBonePass(doc,false,…)`，其内 `mmd_model_runtime.cpp:414-418` 已完成 `SolveLayer` 与 `SolveStandaloneIKForLayer`，IK 结果在 `:371` 写回场景）之后、`:2463`（after-physics 层）之前；取数 `runtime_p2_block.inc:204-211` 的 `GetBoneAdapter(index)->GetGlobalTransform()`。

- **不是冻结点**（同步路径在同一时刻用同一批 adapter 矩阵）。
- 仍有两个将来必须修的点：(i) after-physics 层 IK 结果从不进入影子世界；(ii) 影子节点只被 `SetGlobalTransform` 覆盖 `global_`（`new-files/cmt_physics_shadow.h:42`），`local_`/`ik_rotate_` 从不更新。

## 5. 给 t52 的埋点清单（最小集，全部是现有计数器或缺一行日志）

| 采样点 | 位置 | 取什么 | 用来判定 |
| --- | --- | --- | --- |
| L1 | `.inc:193-200` 的降级分支 | `reason=not_active` / `manager_null` | 假设 A 的第一道 |
| L2 | `.inc:225-227` | `TryConsume` 布尔 + `stale_dropped` + 当前 `result.epoch` vs `async_physics_epoch_` | 假设 A：epoch 是否每帧不符 |
| L3 | `.inc:291-295` | `ApplyStandaloneAsyncResult` 入口/出口布尔 + `result.frame/epoch` | 假设 A |
| L4 | `.inc:250-289` | `applied` 计数 + `async_rigid_identity_mismatch_` + `rigid_world.size()` / `main_rigid_identity_.size()` / `rigid_bodies->size()` | 假设 B1 的判决式 |
| L5 | 一次性（首帧） | 主世界首刚体指针 + 场景首个 `MMDRigidObject::mmd_rigidbody_` 指针是否相同 | 假设 B2 |
| L6 | 每 120 帧 | t44 既有 `stats … final=1` 六项 | Q3 丢步 |

## 6. 未覆盖 / 需宿主实测

- 「写回被调用但写错对象」（B2）需要指针级日志，静态无法定论。
- 冻结是「位移恒 0」而非「缓慢漂移」，因此本轮**不**把冷启动/步进口径当作冻结主因（它们解释 lag 乱跳与漂移幅度）。
- `async_physics_active_` 在真机是否曾被 `ShutdownStandaloneAsyncPhysics()`（例如插件 reset/undo 路径）清掉：需日志确认，属假设 A 的一部分。

## 7. 引用清单

- 分发/时序：`candidate-async-p3/work/source/module/tools/object/mmd_model_manager.cpp:2436,2444-2457,2463`
- 异步步与静默降级：`candidate-async-p3/new-files/runtime_p2_block.inc:183-200`
- 消费与应用：`.inc:225-227,291-315`
- 刚体写回与映射：`.inc:250-289`；`candidate-async-p3/new-files/cmt_physics_async.cpp:27-60,141-168`
- 顺序/身份：`source/module/tools/object/mmd_rigid_manager.cpp:594-602,651-668`；`source/module/tools/object/mmd_model_runtime.cpp:705-712`
- 步进口径：`work/.../mmd_model_runtime.cpp:1580,897`；`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164`；`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.h:364-365`
- 显示读取：`source/module/tools/object/mmd_rigid.cpp:692`；`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1131-1141`
- 真机数据：`docs/validation/vmd-physics-async-20261024/host-ab-p3-result.md`
