# VMD 播放：物理求解 worker 化设计方案（方向 A：结果晚 1 帧）

- 日期：2026-10-25
- 状态：设计稿（只读调研，不含代码改动）
- 目标：把 `physics.total = 14.72 ms/帧` 从主线程求值路径中移出，用「帧 N 消费帧 N-1 的物理结果」换取与主线程其余工作重叠，把带物理播放从 34.8 ms/帧 压到 ~20 ms/帧。
- 依据数据：`docs/validation/vmd-perf-stable-20261024/code-hotspot-analysis.md`、`docs/validation/vmd-perf-bullet-20261024/bullet-substep-analysis.md`、`.dsh-switchman/vmd-perf-20261024/candidate-bullet-b4/ds-bullet-b4.md`。

## 0. 三句话结论

1. **最可行的切片**：让 Bullet 世界只面对「影子骨骼节点（纯 Eigen 数据的 `libmmd::IMMDNode` 实现）」运行，主线程在帧 N 的动画层求值后把 625 份骨骼世界矩阵拷进影子节点，worker 完成 `SyncBonePositionToPhysics → Update → ReflectGlobalTransform` 写入结果缓冲，主线程在帧 N+1 的 after-physics 层求值前消费结果（回写适配器 → `SetPhysicsOverride` → `SetRelMl` → `MarkMeshHierarchyDirty`）。物理结果比动画晚 1 帧，正是已拍板的语义。
2. **P1 改动面**：新增 1 个约 180–220 行的 `cmt_physics_pipeline.{h,cpp}`（双缓冲 + epoch + 一次性开关），改 `mmd_model_runtime.cpp` 约 +70/−30 行（把 `StepStandalonePhysics` 拆成「生产」与「消费」两半），改 `mmd_model_manager.cpp:2438-2456` 约 +25 行（在两次 `RunLayeredBonePass` 之间插入生产/消费），**P1 仍同步执行**，因此可先用「结果位移 1 帧后与基线逐位一致」验正确性，再谈提速。
3. **最大风险**：C4D 的 `BaseObject/BaseTag/BaseDocument` 只能在主线程触碰，而 libMMD 的物理反射路径会顺着 `IMMDNode::SetGlobalTransform → UpdateChildTransform` 直接写骨骼节点树（`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:284`、`:337`、`:489`、`:544`）；只要有一处仍指向插件适配器 `C4DIKChainNodeAdapter`（`source/module/tools/tag/mmd_bone.h:129-171`），worker 就会与主线程的 IK/after-physics 层求值、`MMDRigidObject::Execute` 的显示变换读取（`source/module/tools/object/mmd_rigid.cpp:692`）并发写同一块内存。**影子节点不是优化，是并发的正确性前提。**

---

## 1. 现状：物理今天的线程归属与入口

### 1.1 调用链（全部在主线程求值期）

```
C4D ExecutePasses（主线程；文档求值）
└─ MMDModelManagerObject::Execute            source/module/tools/object/mmd_model_manager.cpp:2317
   ├─ 门控（C1）：time/control checksum/morph checksum/physics_timing 变化   :2394-2411
   ├─ RunLayeredBonePass(doc,false,&ctx)      :2436   ← pre-physics 层：ApplyActiveAnimation + 控制 workflow + IK
   │   └─ MMDBoneManagerObject::PrepareSceneForPhysicsPlaybackLayer(doc,layer,false)
   │                                          source/module/tools/object/mmd_bone_manager.cpp:2341
   │   └─ SyncStandaloneBoneAdaptersFromScene(true)   source/module/tools/object/mmd_model_runtime.cpp:232
   ├─ ResetStandalonePhysics() 或 StepStandalonePhysics(1/fps)                :2443-2446
   │   ├─ Sync 阶段：rigid_body->SyncBonePositionToPhysics(elapsed)           mmd_model_runtime.cpp:892-893
   │   ├─ Step 阶段：physics->Update(elapsed)                                 mmd_model_runtime.cpp:897
   │   └─ ApplyStandalonePhysicsResults()                                     mmd_model_runtime.cpp:902
   │       ├─ ReflectGlobalTransform() ×479                                   :913-914
   │       ├─ SyncStandaloneBoneAdaptersLocalFromGlobal(dynamic)              :916
   │       ├─ MMDBoneManagerObject::SetPhysicsOverride(...)                   :920-929
   │       └─ ApplyPhysicsResultsToBoneObjects() → ApplyLocalToBoneObject + MarkMeshHierarchyDirty
   │                                                                          :932-938
   ├─ RunLayeredBonePass(doc,true,&ctx)       :2463   ← after-physics 层：消费物理结果
   └─ SyncControlsToCurrentPose + 重算 control checksum + 落 prev_time_        :2464-2472
```

- `physics->Update` 内部：`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164` → `m_world->stepSimulation(time, m_maxSubStepCount, 1/fps)`，默认 3 子步（`mmd_model_manager.cpp:2400` 取 `GetPhysicsSubsteps(op)`）。
- 帧外还有一条**同步求值**入口：插件自己在多处调用 `doc->ExecutePasses(...)`（`source/module/tools/sizing/sizing_session.cpp:628`、`source/module/ui/motion_sizing_dialog.cpp:545`、`source/utils/mmd_control_workflow.cpp:885/908/935`、`source/module/tools/object/mmd_model_manager.cpp:4440`、`source/module/automation/mmd_automation.cpp:1501`）。这些路径要求「调用返回时场景已含物理结果」，与异步天然冲突，必须逐条 white-list 为同步模式。

### 1.2 每个子步读写的共享数据

| 数据 | 读 | 写 | 归属 |
| --- | --- | --- | --- |
| 骨骼世界/局部矩阵 | 适配器 `global_transform_`/`local_transform_`（`mmd_bone.h:166-167`，纯 Eigen） | 物理反射、IK、after-physics 层 | 适配器（`physics_bone_pool_`） |
| C4D 骨骼对象 `Matrix` | `SyncCurrentTransformsFromBoneObject` | `ApplyLocalToBoneObject` → `SetRelMl` | 场景对象（**主线程独占**） |
| Bullet 刚体 transform/速度 | 显示（`mmd_rigid.cpp:692`） | `SyncBonePositionToPhysics`/`Update`/`ReflectGlobalTransform` | Bullet world |
| 关节约束（748） | solver | solver | Bullet world |
| mesh 变形 | weight tag（`Tweights`） | `SetDirty(DIRTYFLAGS::MATRIX|DATA|CACHE)`+`MSG_UPDATE`（`mmd_model_runtime.cpp:63-64`、`:73-89`） | 场景对象（**主线程独占**） |
| `MMDBoneTag` 的 runtime override/时间戳 | 动画层 | `SetPhysicsOverride`、`SetPhysicsOverride` 触发 `skip_prephysics_scene_write_` | 骨骼 tag（**主线程独占**） |
| C1 checksum 状态 | `GetControlStateChecksum`/`HasActiveControlDelta`（`source/utils/mmd_bone_control_util.cpp:1386`、`:1420`） | `control_state_checksum_` 等字段 | model manager（主线程） |
| mesh 形变缓存 | mesh manager | `MarkMeshHierarchyDirty` | 主线程 |

## 2. 可行切片：帧 N 用帧 N-1 的物理结果

### 2.1 数据流（目标形态）

```
主线程（帧 N）                                        worker（帧 N 的物理）
1. RunLayeredBonePass(false)  产生帧 N 的动画姿态
2. PublishInput(N): 适配器矩阵 → 影子节点（625×2 矩阵）
3. 把 request(N) 交给 worker ───────────────────▶ 4. SyncBonePositionToPhysics（读影子节点）
   继续主线程：mesh 变形/材质/绘制 …                 5. physics->Update(1/fps, substeps)
                                                   6. ReflectGlobalTransform（写影子节点）
                                                   7. 结果写入 result slot（epoch=N）
主线程（帧 N+1）
8. ConsumeResult(N)：epoch 匹配才取；把动态骨局部变换写回适配器
9. SetPhysicsOverride(dynamic) + ApplyLocalToBoneObject + MarkMeshHierarchyDirty
10. RunLayeredBonePass(true)  ← 用帧 N 的物理结果驱动 after-physics 骨
```

- **产出者**：worker = `SyncBonePositionToPhysics + Update + ReflectGlobalTransform`（纯 libMMD/Bullet + 影子节点）。
- **消费者**：主线程 = 适配器回写 + `SetPhysicsOverride` + `SetRelMl` + dirty 标记（现状 `ApplyStandalonePhysicsResults` 的后半段，`mmd_model_runtime.cpp:916-938`）。
- **同步点**：`result slot` 的 epoch 匹配（`std::atomic<uint64_t> published_epoch`）；主线程**不等待**，拿不到 N 就用 N-1（并计数 `stale_frames`）；seek/暂停/重建世界时 bump `epoch` 并 `join()`。

### 2.2 影子节点（关键机制）

- 新增 `CmtPhysicsShadowNode : libmmd::IMMDNode`，只存 `initial/global/local` 三个 `Eigen::Matrix4f`、父子指针、`ik_rotation/animate_*`，**不持有任何 C4D 指针**（对照 `C4DIKChainNodeAdapter` 的字段 `mmd_bone.h:158-171`，其中 `bone_object_`/`bone_tag_` 是必须剥离的部分）。
- 物理管理器在 `BuildStandalonePhysics()`（`mmd_model_runtime.cpp:691-767`）里本来就用 lambda 取节点（`:705-708` `GetBoneAdapter(bone_index)`），改为 `GetPhysicsShadowNode(bone_index)`：**只改一个 lambda**，Bullet 世界从此与 C4D 解耦。
- 主线程 `PublishInput` 只需 625 次 `shadow->SetMatrix(adapter->GetGlobalTransform(), adapter->GetInitialGlobalTransform())`（≈0.05–0.1 ms）。
- 主线程 `ConsumeResult` 只把**动态骨**（`physics_dynamic_bone_indices_`；场景里有 450 个 dynamic 刚体，对应骨骼数 ≤450）的局部变换写回适配器；子树传播仍在主线程由 `UpdateGlobalTransform` 完成（沿用现状 `SyncStandaloneBoneAdaptersLocalFromGlobal`，`mmd_model_runtime.cpp:248-262`）。
- 好处：`UpdateChildTransform` 的写传播（`MMDPhysics.cpp:284/337/489/544`）只落在影子树上，主线程的 IK/after-physics 层读不到半更新的适配器状态。

### 2.3 与「帧 N 消费 N-1」的语义一致

- 现状：帧 N 的 after-physics 层用帧 N 的物理结果。
- 方案：帧 N 的 after-physics 层用帧 N-1 的物理结果（用户的语义选择：物理晚 1 帧）。
- 不受影响的部分：pre-physics 层（动画/控制/IK）完全不变；mesh 变形仍然是「消费当前骨骼姿态」，只是物理骨比动画骨晚 1 帧——与 MMD 本家「物理滞后于动画」的观感同向。

## 3. 线程安全风险清单

| # | 风险 | 具体冲突点 | 处置 |
| --- | --- | --- | --- |
| R1 | **C4D 主线程 API** | `SetRelMl`/`SetDirty`/`Message(MSG_UPDATE)`/`GetDataInstance`/`GetDocument` 全在 `ApplyPhysicsResultsToBoneObjects` 路径（`mmd_model_runtime.cpp:937-938`、`:63-64`）；worker 一旦触碰即 UB | worker 只做「影子节点 + Bullet」，所有 C4D 调用留在消费侧（主线程） |
| R2 | **动画层求值 vs 物理反射** | `RunLayeredBonePass` 与 worker 同时读写适配器矩阵 | 影子节点隔离；适配器只在 `PublishInput`（拷贝出）与 `ConsumeResult`（拷贝入）两处被 worker 的等价物访问，且这两处 worker 不运行（用 `busy` 标志/epoch 保证） |
| R3 | **C1 门控（checksum）** | `GetControlStateChecksum`/`HasActiveControlDelta` 走 C4D 对象，只在主线程；checksum 记录的是控制骨的 `control->GetRelMl()`（`mmd_bone_control_util.cpp:1441`），物理 override 不进入 checksum | 无需改 C1；但需验证「物理骨 ∩ 控制骨」为空（否则延迟应用会让 checksum 在同帧两次计算间跳变，触发多余重算） |
| R4 | **C2 / MSG_UPDATE 时序** | 现状 `ApplyStandalonePhysicsResults` 在 after-physics 层之前发 `MSG_UPDATE`；延后 1 帧后，同帧内「先 message 后读」的假设被打破 | 消费侧仍在 after-physics 层之前执行（只是改用 N-1 数据），message 的**相对顺序**不变 |
| R5 | **材质同步** | 材质 manager 逐帧读 mesh 状态；物理只改骨骼 → 间接改顶点 | 无新增共享写；`MarkMeshHierarchyDirty` 仍在主线程，顺序不变 |
| R6 | **seek / 暂停 / 循环** | `ResetStandalonePhysics`（`mmd_model_runtime.cpp:828-876`）会重建世界并 `Reset`/`SetActivation`；worker 正在 `Update` 时重建 = 释放正在使用的 Bullet 对象 | epoch bump + `join()` + `world_generation` 双保险；`needs_physics_reset` 判定保持 `mmd_model_manager.cpp:2418-2420` 不变 |
| R7 | **首帧 / 无上一帧结果** | 帧 0 没有 N-1 结果 | 第一帧同步跑一次（`produce + consume` 同帧），第 2 帧起进入流水线；`stale_frames` 计数应为 1 |
| R8 | **渲染帧 ≠ 求值帧** | 渲染可能以别的时刻再次 `ExecutePasses`（`mmd_automation.cpp:1501` 等显式调用） | 显式 `ExecutePasses` 路径强制「同步模式」（`flush_before_return=true`），异步仅用于主场景的常规求值 |
| R9 | **多模型** | 每个 model manager 各持一个世界；N 个 worker 抢核 | P2 先用「全局 1 worker、按模型串行」；P3 再评估小线程池（上限 `min(models, cores-1)`） |
| R10 | **显示对象读取** | `MMDRigidObject::Execute` 每帧 `mmd_rigidbody_->GetTransform()`（`mmd_rigid.cpp:692`）→ 与 worker 写 Bullet 竞态 | 显示改读「已发布结果快照」或仅在 `!busy` 时更新；479 个刚体对象的逐帧读取本身可延迟到消费之后 |
| R11 | **子步/时间步变化** | 子步从 3 改成 B 档（自适应）时世界语义变化 | 变更时 bump epoch + 重建（沿用 `physics_timing_changed`，`mmd_model_manager.cpp:2403`） |
| R12 | **profiler** | 现有 stage 计时是 `thread_local`（`source/utils/cmt_runtime_profile.hpp:88`；`cmt_runtime_profile_c4d.cpp:31/44`），worker 的 Stage 不会进主线程 FrameMetrics | worker 侧单独发 `PhysicsWorker` stage（emit 已被 `std::mutex output_mutex` 保护，`cmt_runtime_profile_c4d.cpp:68-69`），或由主线程把耗时手动并入 `metrics.milliseconds[Physics]` |

## 4. 可复用的并发设施

| 设施 | 位置 | 复用方式 |
| --- | --- | --- |
| sizing 后台任务（`std::async(std::launch::async, …)` + `std::atomic_bool queued_/finished_/cancelling_` + `mutex_`） | `source/module/tools/sizing/sizing_session.cpp:399`、`:153-158` | 直接照搬「提交-轮询-取消」形态；sizing 的 job 是纯数据拷贝，物理 job 需要影子节点，其余骨架同构 |
| 更新检查 worker（`std::thread worker_` + `cancel_` + `resultMutex_`） | `source/cmt_update_manager.cpp:138`、`source/cmt_update_manager.h:46-48` | 长驻线程 + 结果锁的形态可复用；物理需要 `jthread`（C4D 2026 用 C++20，`mmdtool.vcxproj` `LanguageStandard=stdcpp20`）+ `condition_variable` |
| `maxon::ParallelFor` 封装 | `source/module/tools/object/mmd_mesh_manager.cpp:63-68` | **不复用**：这是主线程内的数据并行，物理是跨帧流水线；在 worker 里嵌套 C4D 的 ParallelFor 风险高 |
| profiler 输出锁 / thread_local 上下文 | `source/utils/cmt_runtime_profile_c4d.cpp:31/44/65-69/101` | 输出侧线程安全已具备；只需决定 worker 计时的归并口径 |
| 一次性开关的现有形态 | 容器参数（`GetPhysicsSubsteps`/`IsPhysicsEnabled`，`mmd_model_manager.cpp:2400/2442`） | 新增 `CMT_PHYSICS_ASYNC_MODE`（0=关，1=缝同步，2=worker）容器参数 + `cmt_config.json` 默认值，沿用现有读写路径 |

## 5. 落地拆分

### P1：最小可验证骨架（同步缝 + 双缓冲）

| 项 | 内容 |
| --- | --- |
| 新增 | `source/module/tools/object/cmt_physics_pipeline.h`（~80 行）、`.cpp`（~120 行）：`CmtPhysicsFrameInput/Output`、双缓冲、`epoch`、`stale_frames`、`mode {Off, SeamSync, Worker}` |
| 修改 | `mmd_model_runtime.cpp`：`StepStandalonePhysics`（`:878-900`）拆为 `ProducePhysicsFrame()`（sync+update+reflect，写 result slot）与 `ConsumePhysicsFrame()`（适配器回写 + override + dirty）；约 +70/−30 |
| 修改 | `mmd_model_manager.cpp:2438-2456`：`produce(N)` 后 `consume(N-1)`，首帧特判；约 +25 |
| 新增参数 | `res/S24_up/description/*.res` + `mmd_model_manager.cpp` 参数注册（~15 行） |
| 验证 | ①插桩：每帧 `produce/consume` 各 1 次、`stale_frames` 统计、线程 id（主线程恒定）；②等价性：逐帧导出 625 骨局部矩阵（4×4 float + override 四元数），与基线做「位移 1 帧」逐位比较（Bullet 定步长 ⇒ 应 bit-exact；不一致即切片错误）；③帧时间：P1 预期**不改善**（仍同步），仅验证缝的正确性与可开关 |
| 回退 | 参数 `CMT_PHYSICS_ASYNC_MODE=0` → 完全走原路径（`StepStandalonePhysics` 原实现保留为 `legacy` 分支，一个 if 切换） |

### P2：worker + 默认打开 + 自适应子步接入

| 项 | 内容 |
| --- | --- |
| 新增 | `cmt_physics_shadow_node.h/.cpp`（~130 行：`IMMDNode` 实现，纯 Eigen）；`cmt_physics_worker.h/.cpp`（~220 行：`std::jthread` + `condition_variable` + request/result slot + `CancelAndJoin()` + 线程名/优先级） |
| 修改 | `mmd_model_runtime.cpp`：`BuildStandalonePhysics` 的节点 lambda（`:705-708`）改影子节点（~10 行）；`ProducePhysicsFrame/ConsumePhysicsFrame` 接 worker（~40 行）；`ResetStandalonePhysics` 前 `CancelAndJoin()`（~8 行） |
| 修改 | `mmd_rigid.cpp:683-701`：显示变换改读已发布快照（~15 行） |
| 接入自适应子步 | 子步档位 B 的入口在 `mmd_model_manager.cpp:2400`（`GetPhysicsSubsteps(op)`）；worker 化后主线程只传「本帧目标子步」，由 worker 执行；档位切换沿 `physics_timing_changed` 重建 |
| 验证 | ①线程 id：`produce` 在 worker（记录 `std::this_thread::get_id()`，断言 ≠ 主线程）；②一致性：与 P1 的同步缝结果逐位一致（同一帧号对齐后）；③stale/丢帧计数：正常播放应 <1%；④帧时间：median/p95 双指标（目标 34.8→20±2） |
| 回退 | 参数回 0/1；`CancelAndJoin` 在销毁、seek、参数切换、文档关闭四处调用 |

### P3：扩展

- 多模型线程池（上限 cores−1）、按 `physics.total` 历史做「本帧是否值得异步」的预算判断。
- 插值/运动模糊（在 N-1 与 N 之间按显示时间插值，改善观感）。
- worker 侧 profiler 归并、与 t16 的 B3（运动学刚体 AABB 重复提交）/B6（双运动学端关节转换复用）叠加。
- 与 `candidate-hotpath-v1` 的主线程削减（C1–C9）叠加时的相互影响复测。

## 6. 收益估算（按 t14 数据）

基线（阿芙2.0 + Stay Tonight，30 FPS）：**34.8 ms/帧（物理开）**、18.2 ms（物理关）；`physics.total 14.72`（`bullet.update 14.13`，其中 dispatch 3.611 / solver 6.047 / 其余 setup+jacobian+integrate；`writeback 0.66`；输入同步约 0.9）。

| 口径 | 计算 | 结果 |
| --- | --- | --- |
| 主线程非物理工作 | 34.8 − 14.72 | **≈20.1 ms** |
| 异步后主线程新增 | PublishInput 拷贝 ~0.08 + ConsumeResult（含 adapter 回写/override/dirty）≈0.6 | +0.7 ms |
| 乐观（完全隐藏、无争核） | 20.1 + 0.7 | **≈20.8 ms（≈48 FPS）** |
| 保守（渲染线程争核、偶发 stale 等待、worker 调度抖动 +15%） | 20.1 + 0.7 + 1.0~2.5 | **22–24 ms（≈42–45 FPS）** |
| 上限（若 writeback 也能藏） | 20.1 + 0.3 | ≈20.4 ms |

**「可能不赚」的情形**：

1. 轻场景（主线程 <10 ms 且物理 14 ms）：worker 来不及在 1 帧内完成 → 每帧 stale，最终退化成「每 2 帧更新一次物理」。
2. 多模型同场景：N 个 Bullet 世界同时跑，核数不足，主线程被挤压。
3. 渲染/回放（RenderDocument、`ExecutePasses` 显式调用）：同步 flush 语义会抵消异步收益。
4. 4 核以下机器：C4D 自身（mesh 变形的 `ParallelFor`、视口绘制）已占满核。
5. 物理子步被调到 10（`physics_timing_changed` 重建 + 更重的 `Update`），1 帧窗口不够。

## 7. 未覆盖 / 待实测

- **未实测**：C4D 是否保证场景 `Execute` 恒在主线程（本机未启宿主，无法用线程 id 采样验证）；文中按「C4D 对象层主线程独占」的既有约束设计，R1–R12 的处置均不依赖该假设成立的反面。
- **未实测**：`ConsumeResult` 的真实成本（现 0.66 ms 是「reflect+override+dirty」合计，拆分后各占多少需插桩）。
- **未实测**：影子节点拷贝 625×2×64 B 的 cache 影响（估算 0.05–0.1 ms，未测）。
- **未验证**：物理骨与控制骨是否真无交集（影响 R3）；需一次只读统计（遍历 `PMX_BONE_CONTROL_LINK` 与物理骨下标求交）。
- **未验证**：`MMDRigidObject::Execute` 的显示变换读取（479 次/帧）在异步下是否成为新的竞态热点（R10 的处置需实测确认开销）。
- 本文不含任何代码改动与宿主测量；所有 ms 数字均来自既有 t14/t16 报告，新增估算已标注推导过程。

## 8. 参考

> 行号口径：以当前工作树为准（2026-10-25）。注意 `source/module/tools/object/mmd_model_manager.cpp` 等文件正被另一路任务（`candidate-hotpath-v1`，主线程削减 C1–C9）并行修改，本方案落地前需按合并后的文件重新核对行号；本文引用的 `Execute` 门控块（`:2392-2475`）当前与基线一致。

- `source/module/tools/object/mmd_model_manager.cpp:2317-2477`（Execute 门控与两次 bone pass）
- `source/module/tools/object/mmd_model_runtime.cpp:232-262`（适配器同步）、`:385-418`（分层求值）、`:691-767`（物理世界构建）、`:828-938`（重置/步进/回写）
- `source/module/tools/object/mmd_bone_manager.cpp:2341-2390`（pre-physics 层写入）、`:2423-2441`（seek 失效）
- `source/module/tools/tag/mmd_bone.h:129-171`（适配器字段：哪些必须剥离到影子节点）
- `source/module/tools/object/mmd_rigid.cpp:671-705`（显示对象逐帧读 Bullet）
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164`（stepSimulation）、`:1080-1107`（反射与运动学同步）、`:237-340`（motion state 写节点）
- `source/utils/cmt_runtime_profile.hpp:88`、`source/utils/cmt_runtime_profile_c4d.cpp:31/44/65-69`（线程本地计时与输出锁）
- `source/module/tools/sizing/sizing_session.cpp:153-158`、`:399`（现成 worker 形态）
- `docs/validation/vmd-perf-stable-20261024/code-hotspot-analysis.md`、`docs/validation/vmd-perf-bullet-20261024/bullet-substep-analysis.md`
