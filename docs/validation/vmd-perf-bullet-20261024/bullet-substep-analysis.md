# VMD 播放：Bullet 子步热点定位与结果保持型优化候选

> 只读代码分析（t16）。**未改任何源码、未启动宿主、未联网、未跑构建**。
> 输入口径：t14 的 `docs/validation/vmd-perf-stable-20261024/README.md`（插桩构建 stage 分解）
> 与 `docs/validation/vmd-perf-stable-20261024/code-hotspot-analysis.md`（C1–C9），本文不重测、不改写。

## 0. 结论先行

| 排名 | 候选 | 类型 | 预期收益（ms/帧） | 是否改变结果 | 改动面 |
| --- | --- | --- | --- | --- | --- |
| 1 | **B4 运动学×运动学碰撞对跳过窄相** | 结构裁剪 | **1.0–1.4**（上限 `bullet.dispatch` 3.611 × k-k 对占比） | **否**（求解端有硬证据不消费） | 插件侧 15–25 行 |
| 2 | **B3 运动学刚体第 2/3 子步的 AABB 重复提交** | 冗余重算消除 | **0.7–1.15**（上限 2/3 × 运动学占比 × `bullet.aabb` 3.459） | **否**（输入未变的重算） | Bullet 侧 30–60 行 |
| 3 | **B1 子步 3→2** | 参数降档 | **4.6**（13.876/3） | **是** | 0–5 行（参数/默认值） |
| 4 | B6 双运动学端 MMD 关节转换复用 | 冗余重算消除 | 0.4–0.9（上限 2/3 × 占比 × `bullet.solver.joints` 2.155） | 否 | Bullet 侧 60–120 行 |
| 5 | B5 求解迭代 10→6 | 参数降档 | ~1.2（linear 估计） | 是 | 3–10 行 |
| 6 | B7 物理输入/写回侧索引裁剪 | 结构裁剪 | 0.2–0.5 | 否 | 插件侧 30–60 行 |
| — | B2 子步 3→1 | 参数降档 | ~9.3 | 是（明显） | 0–5 行 |
| — | B8 关预测接触 / B9 关 forceUpdateAllAabbs | 已排除 | ~0.17 / 0 | 是 / 无效 | 不建议 |

**一句话**：13.876 ms 的 `bullet.substep` 里，约 **47% 是「每子步都要重算、但只有第 1 个子步的输入变过」的运动学侧工作**（AABB 3.459 + 窄相中 k-k 部分），
这部分**可以做到结果逐位不变**；剩下的是动态刚体真正需要的求解，只能靠降档（子步/迭代）换性能，必然改变轨迹。

## 1. 每帧物理时间线（已核实，非推测）

```
MMDModelManagerObject::Execute                       source/module/tools/object/mmd_model_manager.cpp:2317
├─ RunLayeredBonePass(doc,false,…)                   :2436          ← 物理前骨骼/IK
├─ if (physics_enabled)                              :2438
│  └─ if (time_changed) StepStandalonePhysics(1/fps) :2441, :2446
│     └─ mmd_model_runtime.cpp:878-900
│        ├─ for 479 rigid_bodies → SyncBonePositionToPhysics(elapsed)   :892
│        ├─ physics->Update(elapsed)                                    :897
│        └─ ApplyStandalonePhysicsResults()                             :899
├─ RunLayeredBonePass(doc,true,…)                    :2463          ← 物理后骨骼/IK
└─ SyncControlsToCurrentPose / checksum              :2465, :2466
```

`libmmd::MMDPhysics::Update` 只是转调：

```cpp
// dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-166
void MMDPhysics::Update(const float time) const
{ m_world->stepSimulation(time, m_maxSubStepCount, static_cast<btScalar>(1.0 / m_fps)); }
```

### 1.1 「每帧 3 个子步」是怎么来的（t14 的 `calls` 未落表，这里是代码实证）

```cpp
// source/module/tools/object/mmd_model_runtime.cpp:1039-1040
const Float32 document_fps = doc ? static_cast<Float32>(doc->GetFps()) : fps_;
physics->SetFPS(document_fps * static_cast<Float32>(GetPhysicsSubsteps(op)));
```

即 `fixedTimeStep = 1 / (fps × substeps)`；`Update(1/fps)` 传入 `1/fps` 的 dt，于是
`substeps_per_frame = (1/fps) / (1/(fps×substeps)) = substeps`（本场景 fps=30、默认 substeps=3 → **90 Hz 固定步长、每帧 3 次 `internalSingleStepSimulation`**）。

Bullet 侧的子步循环与每子步动作：

```cpp
// dependency/bullet3/src/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp:423-436
int clampedSimulationSteps = min(numSimulationSubSteps, maxSubSteps);
saveKinematicState(fixedTimeStep * clampedSimulationSteps);   // :428  1 次/帧（运动学刚体唯一一次取骨骼变换）
applyGravity();                                              // :430
for (i = 0; i < clampedSimulationSteps; i++) {
    internalSingleStepSimulation(fixedTimeStep);             // :434
    synchronizeMotionStates();                               // :435  只写动态刚体（:339 过滤 kinematic）
}
```

```cpp
// btDiscreteDynamicsWorld.cpp:462-491（internalSingleStepSimulation 顺序）
predictUnconstraintMotion → createPredictiveContacts → performDiscreteCollisionDetection
→ calculateSimulationIslands → solveConstraints → integrateTransforms → updateActions → updateActivationState
```

**关键结构事实**：运动学刚体（PMX type 0）的世界变换在 `btRigidBody::saveKinematicState` 里
`getMotionState()->getWorldTransform(m_worldTransform)`（`dependency/bullet3/src/BulletDynamics/Dynamics/btRigidBody.cpp:105-121`，调用点 `btDiscreteDynamicsWorld.cpp:428`）
**每帧只更新 1 次**；但 `updateAabbs` 与窄相在每个子步都重跑（见 §2）。这就是「子步放大系数」的来源。

## 2. 热点定位：13.876 ms 的构成（用 t14 的 stage 数，按子步归一）

| stage | ms/帧（t14） | per-substep | 归因 |
| --- | ---: | ---: | --- |
| `bullet.substep` | 13.876 | 4.625 | 3 个子步合计 |
| `bullet.collision` | 7.257 | 2.419 | = aabb + broadphase + dispatch |
| ├ `bullet.aabb` | 3.459 | 1.153 | 479 体 × 3 子步 = 1,437 次 `updateSingleAabb` |
| ├ `bullet.dispatch` | 3.611 | 1.204 | 窄相（命中对的 `processCollision` + `refreshContactPoints`） |
| └ `bullet.broadphase` | （4 子步口径 0.192） | ~0.06 | 对枚举，便宜 |
| `bullet.solve` | 6.047 | 2.016 | = setup + iterations + finish |
| ├ `bullet.solver.setup` | 2.888 | 0.963 | 含 `bodies`（479→solverBody）+ `joints` |
| │ └ `bullet.solver.joints` | 2.155 | 0.718 | 748 关节 × 3 子步 = 2,244 次 `convertJoint` |
| └ iterations + finish | ≈3.16（推） | ~1.05 | 10 次 `solveSingleIteration` + 写回 |

`bullet.collision` 与 `bullet.solve` 已覆盖 13.30 / 13.88 ms；积分、预测、岛构建、预测接触合计 <1 ms
（4 子步口径：integrate 0.496 / predict 0.275 / islands 0.261 / predictive_contacts 0.225，
见 `docs/validation/vmd-bullet-controller-performance-20261019/README.md:40-43`）。

### 2.1 为什么「运动学侧的重复劳动」是最大的一块

1. 全场景刚体都是 `DISABLE_DEACTIVATION`：
   ```cpp
   // dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:701 / :824 / :933
   m_rigidBody->setActivationState(DISABLE_DEACTIVATION);
   ```
   于是 `btCollisionWorld::updateAabbs`（`btCollisionWorld.cpp:197-212`）的 `isActive()` 恒为真，
   **每个子步都要为全部 479 个刚体重算 AABB 并提交 broadphase**（`:153-195`，`bp->setAabb` 在 `:177`）。
2. 运动学刚体的变换每帧只变 1 次（§1.1），所以第 2、3 子步算出的 AABB 与第 1 子步**逐位相同**；
   这一步是纯重算，占 `bullet.aabb` 的 2/3 × 运动学占比。
3. 窄相同理：k-k（运动学×运动学）对每个子步都要跑 `processCollision`（`needsCollision` 只在两侧都 inactive
   时才跳过，`dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp:177-178`），
   但它们产生的 manifold 在求解阶段被直接丢弃：
   ```cpp
   // dependency/bullet3/src/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp:1015-1017
   ///avoid collision response between two static objects
   if (!solverBodyA || (solverBodyA->m_invMass.fuzzyZero() && (!solverBodyB || solverBodyB->m_invMass.fuzzyZero())))
       return;
   ```
   即 k-k 流形**对动力学零贡献**，其窄相成本 100% 是浪费（`dispatch` 里按 k-k 对占比计）。

## 3. 候选清单

> 约定：每条都标「是否改变结果」。**改变结果**的候选必须走质量门禁（位级/视觉/漂移对比）才能合入；
> **不改变结果**的候选仍要位级对比，但预期差异应恒为 0。

### B1 子步数 3→2（参数降档）

- **位置**：`source/module/tools/object/mmd_model_runtime.cpp:1040`（`SetFPS(fps × substeps)`）；
  默认值与范围在 `GetPhysicsSubsteps(op)`（88bc01c1 已把默认设为 3，范围 1–10）。
- **机理**：成本 ≈ 子步数 × 单子步成本；3→2 直接省 1/3。
- **预期收益**：**4.6 ms/帧**（13.876 / 3），即整帧 34.0 → ~29.4 ms。
- **是否改变结果**：**是**。固定步长 1/90 → 1/60，轨迹、接触时刻、弹簧收敛度都会变。
- **风险**：中高（穿模/抖动，尤其在高速摆动的裙摆/头发）。**注意**：88bc01c1 已把默认从更高值降到 3，
  说明降档是已知的质量-性能折衷；继续降到 2 属于**同一杠杆的进一步取值**，需队长裁定是否越界。
- **验证**：①同会话交替 A/B 的 stage 探针（`bullet.substep` 应 ≈ 2/3）；②持久化 112 组输出的位级对比
  （方法参考 `docs/validation/vmd-bullet-controller-performance-20261019/README.md` §多线程世界试验）；
  ③视觉抽查穿模。**不接受**仅凭 ms 数字合入。
- **改动规模**：0–5 行（改默认值或加一个上限参数）。

### B2 子步数 3→1（30 Hz 物理）

- **位置/机理**：同 B1。
- **预期收益**：**~9.3 ms/帧**（13.876 × 2/3）。
- **是否改变结果**：是，且幅度明显（物理与动画同频，弹簧约束在 30 Hz 下显著软化）。
- **风险**：高。**不建议**作为默认；只在「用户显式选择低质量物理」时可用。列入本表是为了让后续讨论有基线。

### B3 运动学刚体在第 2…N 子步跳过 AABB 重算（结果保持）

- **位置**：
  - `dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionWorld.cpp:197-212`（`updateAabbs`）
    与 `:153-195`（`updateSingleAabb`，`bp->setAabb(...)` 在 `:177`）；
  - `dependency/bullet3/src/BulletDynamics/Dynamics/btRigidBody.cpp:105-121`（`saveKinematicState`，运动学刚体唯一的变换更新点，调用点 `btDiscreteDynamicsWorld.cpp:428`）。
- **机理**：为每个刚体维护「世界变换版本号」，在 `saveKinematicState`/`setCenterOfMassTransform`/`setWorldTransform`
  处递增；`updateSingleAabb` 若发现 `isStaticOrKinematicObject()` 且版本未变，则跳过（AABB 与 broadphase 节点内容必然相同）。
- **预期收益**：上限 `(substeps-1)/substeps × 运动学占比 × 3.459`
  → 运动学占 50% 时 **1.15 ms**，占 30% 时 **0.69 ms**。（运动学占比**待实测**，见 §6）
- **是否改变结果**：**否**（跳过的是输入未变的重算；AABB 值、树结构、对集合都不变）。
- **风险**：中（改 vendored Bullet，影响所有物理路径）。必须保证动态刚体永不跳过（其变换每子步都变）。
- **验证**：①位级输出应当**完全一致**（112 组）；②`bullet.aabb` 应降至 (1/3 + 2/3×(1−运动学占比)) 附近；
  ③压力场景（高速旋转骨骼）下不出现「碰撞延迟一帧」。
- **改动规模**：Bullet 侧 30–60 行（字段 + 三处递增 + 跳过判断）。

### B4 运动学×运动学碰撞对跳过窄相（结果保持，插件侧）

- **位置**：世界构建 `source/module/tools/object/mmd_model_runtime.cpp:691-767`（`BuildStandalonePhysics`，可挂
  `btOverlapFilterCallback`）；Bullet 侧两条证据：
  ①`dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp:177-178`
  （`needsCollision` 只在**两侧都 inactive** 时跳过 → k-k 对今天确实进入窄相，成本真实存在）；
  ②`dependency/bullet3/src/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp:1015-1017`
  （`avoid collision response between two static objects`：两侧 `invMass` 都为零时 `return`，k-k 流形不产生任何求解行）。
- **机理**：`btOverlapFilterCallback::needBroadphaseCollision` 里，若两体都 `isStaticOrKinematicObject()`
  则返回 false。实现只需 `btRigidBody::upcast` + 两次虚调用。
- **预期收益**：上限 `bullet.dispatch 3.611 × k-k 对占比`。若 k-k 占命中对 1/3 → **1.2 ms**；
  占 1/5 → 0.72 ms。（占比**待实测**）
- **是否改变结果**：**否**。这类流形不产生任何求解行（`btSequentialImpulseConstraintSolver.cpp:1015-1017`），
  也不参与积分；唯一的语义差异是「接触点回调/调试绘制看不到 k-k 接触」，本插件未使用。
- **风险**：低–中（插件侧；filter 对所有对生效，需要确认没有依赖 k-k 接触的副作用；`filter` 中不能抛异常/分配）。
- **验证**：①112 组位级一致（必须全等）；②`bullet.dispatch` 下降、`bullet.solve` 不变；
  ③确认 `physics.writeback` 不变。
- **改动规模**：插件侧 15–25 行（一个 filter 类 + 安装/移除）。

### B5 求解迭代数 10→6（参数降档）

- **位置**：`source/module/tools/object/mmd_model_runtime.cpp:1025-1049`（`ApplyPhysicsConfigToRuntime`，
  可写 `world->getSolverInfo().m_numIterations`）。
- **机理**：t14 `solve 6.047` 中 `setup 2.888` 是固定开销，剩余 ≈3.16 ms 随迭代数近似线性。
- **预期收益**：10→6 约 **1.2 ms**；10→8 约 0.6 ms。
- **是否改变结果**：**是**（接触/弹簧收敛度下降，可能抖动）。
- **风险**：中。MMD 关节是软弹簧，迭代不足会表现为「布料更软/更抖」。
- **验证**：位级对比 + 视觉抽查；`bullet.solver.iterations` 比例核对。
- **改动规模**：3–10 行。

### B6 双运动学端 MMD 关节的转换复用（结果保持，难）

- **位置**：`dependency/bullet3/src/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp:1486-1491`
  （`convertBodies`/`convertJoints`/`convertContacts` 的顺序调用）与 `:1403-1485`（`solveGroupCacheFriendlySetup`）。
- **机理**：`bullet.solver.joints` 2.155 ms = 748 关节 × 3 子步。若关节两端都是运动学刚体，
  其求解行只取决于两端世界变换与关节参数——两者在帧内 3 个子步都不变（§1.1）→ 转换结果逐位相同，可缓存复用。
- **预期收益**：上限 `2/3 × 双运动学端占比 × 2.155`。若占比 40% → **0.57 ms**。
- **是否改变结果**：否，前提是缓存键覆盖「两体变换版本 + 关节参数版本」。
- **风险**：高（求解器热点；solverBodyId 映射、临时池复用、`m_tmpSolverNonContactConstraintPool` 生命周期都要对）。
- **验证**：位级一致；`bullet.solver.joints` 下降；随机化关节参数变更后仍一致。
- **改动规模**：Bullet 侧 60–120 行。

### B7 物理输入/写回侧的索引裁剪（结果保持，补充项）

- **位置**：`source/module/tools/object/mmd_model_runtime.cpp:878-900`（`StepStandalonePhysics`：`:892` 对全部 479 体
  调 `SyncBonePositionToPhysics`，但 `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1092-1097` 只对
  `RigidBodyType::Aligned` 真做事）、`:902-940`（`ApplyStandalonePhysicsResults`：`:913` 全量 `ReflectGlobalTransform`、
  `:916` 动态骨局部同步、`:920` 覆盖写）、`:232-258` 适配器两遍同步。
- **机理**：把「全量循环 + 逐体早退」换成「预先算好的 Aligned/动态索引表」，减少 479×N 次虚调用与分支。
- **预期收益**：**0.2–0.5 ms**（`physics.inputs` 0.9 + `physics.writeback` 0.66 的一部分）。
- **是否改变结果**：否（纯索引裁剪）。
- **风险**：低；规模 30–60 行插件侧。
- **不属于 Bullet 子步**，列在这里是因为它落在同一条每帧物理时间线上。

### B8 关闭预测接触（已评估，不建议）

- **位置**：`dependency/bullet3/src/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp:470`（每子步）。
- **成本**：4 子步口径 0.225 ms → 当前 ≈0.17 ms。**收益太低**，且它是防穿透机制（高速运动体扫掠）。
- 结论：收益/风险不划算，除非做 B1 后仍需再挤 0.2 ms。

### B9 `setForceUpdateAllAabbs(false)`（已排除，避免重复尝试）

- **位置**：`dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionWorld.cpp:71`（默认 `true`）、`:207`。
- **为什么无效**：本工程所有刚体都 `DISABLE_DEACTIVATION`（`MMDPhysics.cpp:701/824/933`），`isActive()` 恒真，
  该开关只在「有体处于 sleep」时才有意义。
- 结论：**不要**把它当作优化项；真正的浪费是 §2.1 的「输入未变仍重算」，对应 B3。

## 4. 与 t14 stage 的交叉验证矩阵

| 若探针显示…… | 说明什么 | 应优先采用 | 排序变化 |
| --- | --- | --- | --- |
| `bullet.aabb` ≥ 3.0 ms（占 substep ≥22%） | 运动学 AABB 重复提交成立 | **B3** 升为第一 | B3 > B4 > B1 |
| `bullet.dispatch` ≥ 3.0 ms | k-k 窄相浪费占比大 | **B4** 升为第一 | B4 > B3 > B1 |
| `bullet.solver.joints` ≥ 2.0 ms | 关节转换是可观项 | **B6** 进前三 | B4 > B3 > B6 |
| `bullet.solver.iterations` ≥ 3.0 ms | 迭代是主要项 | **B5** 进前三（但改结果） | B1 > B4 > B5 |
| `physics.inputs + physics.writeback` ≥ 2.0 ms | 桥接层循环成本高 | **B7** 进前三 | B4 > B7 > B3 |
| `physics.total` 占整帧 < 35% | 物理不是当前瓶颈 | 暂停本线，回到 t15 的 C1/C2（模型求值） | — |

**与 ds-impl2 探针的对齐点**：他测的是「每帧 wall 时间 + stage 占比」。我的候选全部以
`bullet.aabb` / `bullet.dispatch` / `bullet.solver.joints` 三个 stage 的变化作为**第一判据**，
只要他给出这三项的 ms 与 calls，就能直接判定 B3/B4/B6 的实际收益上限。

## 5. 不建议的方向（避免重复劳动）

1. **紧凑关节表**：已实测无收益（逐点一致、耗时在噪声内），不要作为物理线方向。
2. **88bc01c1 已做**：控制器数据复用、材质所有权复用、空物理后层跳过、重复权重通知消除、
   可复用运行时/Bullet 插桩、物理子步默认 3、依赖目标 `/O2 /fp:strict /Ob0 /Oi-`。本报告不重复提案。
3. **多线程 Bullet 世界**：`docs/validation/vmd-bullet-controller-performance-20261019/README.md:62-84`
   已做过 MT 1/4 线程试验，未得到稳定收益；不要在没有新证据前重试。
4. **`/fp:strict` → `/fp:fast`（依赖侧）**：会改变物理数值，且属于已做过的选项集调整，越界。

## 6. 待实测（本报告无法从代码判定的量）

| 编号 | 待测量 | 怎么测（只读或宿主侧） | 影响哪条候选 |
| --- | --- | --- | --- |
| M1 | PMX 刚体类型分布（type0/1/2 计数）与关节两端类型分布 | 宿主跑一次只读统计：遍历 `MMDPhysics` 刚体读 `MMDRigidBody::GetRigidBodyType()`（需确认公开访问器）；或离线解析 PMX 二进制 | B3/B6 收益上限 |
| M2 | broadphase 命中对里 k-k / k-d / d-d 的比例 | 临时 stage 计数器（`processCollision` 入口按两侧 `isStaticOrKinematicObject()` 分类） | B4 收益上限 |
| M3 | `btDbvtBroadphase::setAabb` 对「相同 AABB」的实际早退程度 | `btDbvt` 内部计数，或对 B3 打桩前后对比 `bullet.aabb` | B3 是否还有「提交侧」成本 |
| M4 | `world->getSolverInfo().m_numIterations` 是否为默认 10 | 宿主只读打印 | B5 的基线 |
| M5 | 748 关节里双运动学端的数量 | 同 M1 | B6 收益上限 |
| M6 | `synchronizeMotionStates`（每子步 1 次，只对动态体）的实际成本 | t14 未单独插桩 | 若大，可能有「只写最后一次」的裁剪（会改变视觉插值语义，需谨慎） |

## 7. 引用清单（file:line）

- `source/module/tools/object/mmd_model_manager.cpp:2317`（`Execute`）、`:2436`、`:2438-2456`（物理门控）、`:2463-2466`
- `source/module/tools/object/mmd_model_runtime.cpp:691-767`（`BuildStandalonePhysics`）、`:878-900`（`StepStandalonePhysics`）、
  `:902-940`（`ApplyStandalonePhysicsResults`）、`:1025-1049`（`ApplyPhysicsConfigToRuntime`，`SetFPS` 在 `:1040`）、`:232-258`、`:248-…`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-166`（`Update` → `stepSimulation`）、`:701/:824/:933`（`DISABLE_DEACTIVATION`）、
  `:1080-1090`（`ReflectGlobalTransform`）、`:1092-1107`（`SyncBonePositionToPhysics`，只对 `Aligned`）、`:1010-1034`（`SetActivation`）、`:1036-1061`（`ResetTransform`）
- `dependency/bullet3/src/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp:249-267`（`saveKinematicState`）、
  `:335-379`（`synchronizeMotionStates`，`:339` 过滤 kinematic）、`:423-441`（子步循环）、`:462-491`（单子步顺序）
- `dependency/bullet3/src/BulletDynamics/Dynamics/btRigidBody.cpp:105-121`（`saveKinematicState` 取骨骼变换）
- `dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionWorld.cpp:71`（`m_forceUpdateAllAabbs(true)`）、
  `:153-195`（`updateSingleAabb`）、`:197-212`（`updateAabbs`）
- `dependency/bullet3/src/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp:311`（`setAabb`）
- `dependency/bullet3/src/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp:147-156`（`needsResponse`：k-k 无接触响应）、
  `:158-183`（`needsCollision`：只在两侧都 inactive 时跳过）、`:236`（`defaultNearCallback` 调用点）
- `dependency/bullet3/src/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp:999-1017`（`convertContact`，k-k 直接 `return`）、
  `:1149-1160`（`convertContacts`）、`:1403-1491`（`solveGroupCacheFriendlySetup`，`convertJoints` 在 `:1489`）、`:1526`（`solveSingleIteration`）
- `docs/validation/vmd-perf-stable-20261024/README.md:184-207`（t14 stage 表）、`:209-210`（解读）
- `docs/validation/vmd-perf-stable-20261024/code-hotspot-analysis.md`（C1–C9，本报告不复述）
- `docs/validation/vmd-bullet-controller-performance-20261019/README.md:22-43`（4 子步口径的 Bullet 分解）、`:62-84`（MT 试验）、`:88-94`（后续并行点）

## 8. 口径说明（必须与结论一起读）

- 本文所有 ms 数字都来自 t14 的插桩构建（`CMT_ENABLE_RUNTIME_PROFILING=1` 的专用构建，
  sha `BBFB…BE78`），**不是 Release 产品构建**；`source/utils/cmt_runtime_profile.hpp:171-175`
  在 `CMT_ENABLE_RUNTIME_PROFILING=0` 时把 `CMT_PROFILE_SCOPE` 编译成 `((void)0)`。
- 候选的「预期收益」是**结构性上限**（按 t14 实测成本 × 可裁剪比例），不是实测结果；
  合入前必须按各条「验证」小节做 A/B。
- B1/B2/B5 改变数值结果；B3/B4/B6/B7 在正确实现下应为**逐位不变**——如果不是，说明实现错了，不要接受「差异很小」。
