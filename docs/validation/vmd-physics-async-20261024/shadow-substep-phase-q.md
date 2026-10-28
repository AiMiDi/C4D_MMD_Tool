# 假设 Q 排查：两个 Bullet 世界的「子步数 / 累加器相位」是否不一致

- 任务：t71 之后由队长指派（只读排查，不建 patch、不编译、不跑 verify）
- 结论时间：2026-10-26
- 输入事实（队长提供，本报告不复测）：541 尖峰 97.1678 mm（53.5×）、561 尖峰 77.2287 mm、562 只有 27 个 kinematic 动（整帧无物理结果被应用）、563 再尖峰 97.1493 mm；除三处尖峰外每帧与 sync 同量级（1.4–1.7×）；管线计数干净（`worker_steps÷submitted = 21/21`、`submit_skipped=0`、`result_covered=0`、`stale=0`、`in_flight=0`、`mismatch=0`、`applied = submitted−1`）。

**一句话结论：Q 在「30 fps 文档」下不能解释这些尖峰（算术上是位精确的 3 子步、残余恒为 0）；但在「非整数比的文档帧率」下 Q 成立，且当前代码确实**没有**做相位对齐。所以这不是「Q 对/错」，而是「Q 的触发条件是否被满足」——需要一条数据（文档 FPS 与每帧实际子步数）就能定死。**

---

## 1. `MMDPhysics::Update(dt)` 内部到底怎么调 `stepSimulation`

- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160` `void MMDPhysics::Update(const float time) const`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:164`
  `m_world->stepSimulation(time, m_maxSubStepCount, static_cast<btScalar>(1.0 / m_fps));`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:128` `void MMDPhysics::SetFPS(const float fps)` → 只写 `m_fps`（`:131` 附近），不改世界。
- `m_maxSubStepCount` 默认 10（`MMDPhysics.cpp:140` 的 setter 上界，产品未调用 setter）。

Bullet 侧的累加器（`dependency/bullet3/src/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp:382`）：

```
m_fixedTimeStep = fixedTimeStep;
m_localTime += timeStep;
if (m_localTime >= fixedTimeStep) {
    numSimulationSubSteps = int(m_localTime / fixedTimeStep);
    m_localTime -= numSimulationSubSteps * fixedTimeStep;
}
...
int clampedSimulationSteps = (numSimulationSubSteps > maxSubSteps) ? maxSubSteps : numSimulationSubSteps;
saveKinematicState(fixedTimeStep * clampedSimulationSteps);
```

**主世界与影子世界走的是同一个 `MMDPhysics::Update`、同一个 `stepSimulation` 重载、同样 `maxSubSteps=10`、同样 `fixedTimeStep = 1/90`**：

| 侧 | 入口 | dt | fixedTimeStep | 证据 |
| --- | --- | --- | --- | --- |
| 主 | `RunStandalonePhysicsStep(elapsed)` → `physics->Update(elapsed)` | `1.f/fps_`（=1/30） | `1/m_fps`，`m_fps=90` | `candidate-async-p5/work/source/module/tools/object/mmd_model_runtime.cpp:1371`（Update 调用点）；`ApplyPhysicsConfigToRuntime` 里 `SetFPS(document_fps * substeps)` |
| 影 | worker `StepFn(fixed_dt_, job)` → `SyncBonePositionToPhysics(dt)` → `Update(dt)` | `fixed_dt_`（`1.F/fps_`） | 同上，`ApplyPhysicsConfigToAsyncWorld` 复刻同一表达式 | `mmd_model_runtime.cpp:968`（StepFn 内 `physics->Update(dt)`）；`StartStandaloneAsyncPhysics()` 末尾 `Start(1.F / fps_)` |

> 也就是说：**参数同源，不存在「一边 3 子步、一边 4 子步」的静态差异**。差异只可能来自「累加器相位」这个运行态。

## 2. 3 子步 / 4 子步的浮点判定条件（位精确计算）

按 Bullet 的算法（`m_localTime += dt`，`n = int(m_localTime / fixed)`），用 `btScalar = float` 复算：

```
dt    = 1.0f/30.0f = 0.033333335071802139
fixed = 1.0f/90.0f = 0.011111111380159855
3*fixed（float 舍入后） = 0.033333335071802139   ← 与 dt 位相等
dt / fixed = 3.000000083819  → int() = 3
dt - 3*fixed = 0（float 下精确为 0）
```

连续 600 帧模拟（同一算法、float 逐位）：**n != 3 的帧数 = 0，残余 `m_localTime` 恒为 0**。

| 文档 FPS | dt=1/fps | 600 帧中 n≠3 的帧数 | 出现的子步数 |
| --- | --- | --- | --- |
| 30 | 0.0333333351 | 0 | {3} |
| 29.97 | 0.0333647016 | 1 | {3,4} |
| 25 | 0.04 | 359 | {3,4} |
| 24 | 0.04166667 | 450 | {3,4} |
| 60 | 0.01666667 | 600 | {1,2} |

结论：

- **30 fps（t14 场景口径）下，Q 的「偶尔算出 4 子步」在数学上不可能**：`1/30f` 与 `3×(1/90f)` 在 float 下位相等，残余恒 0，主/影两侧都恒 3 子步，**相位差异也不产生任何效果**（因为每帧残余都被减到 0，没有可累积的量）。
- **非整数比（25/24 fps 等）下 Q 成立且后果严重**：359/600、450/600 的帧会多算一个子步；此时主世界有非零残余 `r∈[0,fixed)`、影子重建后残余为 0，同样的 dt 序列会得到**不同的 n 序列** → 「某帧多推进 1/90 s、下一帧少推进」→ 尖峰 + 回补，形状与队长给的指纹一致。

## 3. 影子世界重建后有没有重置累加器、有没有与主世界对齐

- `RebuildStandaloneAsyncShadow()`（`mmd_model_runtime.cpp:829`）：`ShutdownStandaloneAsyncPhysics()` → `async_frames_since_reset_ = 0` → `StartStandaloneAsyncPhysics()`。
- `StartStandaloneAsyncPhysics()`（`mmd_model_runtime.cpp:840`）：`std::make_unique<libmmd::MMDPhysicsManager>()` + `Create()` → **新 `btDiscreteDynamicsWorld`，其 `m_localTime` 从 0 开始**（Bullet 的成员初值 0，构造函数不读外部状态）。
- 代码里**没有任何**相位对齐动作（也不可能直接写 `m_localTime`：它是 `btDiscreteDynamicsWorld` 的 protected/private 成员，libMMD 也没有暴露 setter）。搜索 `m_localTime` / `setLocalTime` / `fixedTimeStep` 在 `source/` 与 `dependency/libMMD/src/` 均无产品侧写入点，唯一的写入就是 Bullet 自己的累加。

⇒ **点 3 的事实成立：重建把影子相位归零，且没有对齐机制。** 在 30 fps 下这无害（残余恒 0，归零等于没变化）；在非整数比下这就是 Q 的具体机制。

## 4. 562「整帧没有物理结果被应用」在代码上对应哪条路径

`StepStandaloneAsyncPhysics`（`mmd_model_runtime.cpp:1012`）里，能造成「骨骼/刚体都没被写回、但 kinematic 仍随骨骼层级动」的路径只有三条，且**三条都不打日志**：

1. `TryConsume(async_physics_epoch_, 0, result)` 返回 false（结果未就绪/epoch 不符）→ 整帧不 Apply。**但队长给的 `stale=0`、`covered=0`、`applied = submitted−1` 与这条矛盾**（若发生未消费，`applied` 会落后更多）。
2. `ApplyStandaloneAsyncResult` 入口 `if (!async_physics_active_ || result.epoch != async_physics_epoch_) return false;`（`mmd_model_runtime.cpp:1112`）——epoch 若在当帧推进（seek/重建）就会整帧丢弃，而 `stale_dropped_` 只在 `TryConsume` 内部计数，**这条路径不计数**。
3. `ApplyStandaloneAsyncRigidWorld(result.rigid_world)`（`mmd_model_runtime.cpp:1128` 调用，定义 `:1069`，返回值 `:1107 return applied > 0;`）**返回值被忽略**：`!rigid_bodies || rigid_world.empty()` → false；数量不符 → `++async_rigid_identity_mismatch_` 并 false；`applied == 0`（全部 `GetRigidBody()` 为空）→ false。**这一路骨骼照写、刚体一个都不动，而 `async_applied_frame_` 仍然推进**，所以计数看起来完全健康。

⇒ 562 最像第 3 条（或第 2 条 + 骨骼恰好也被覆盖成旧值）。**判据很便宜**：把 `async_rigid_identity_mismatch_` 与 `result.rigid_world.size()` 打出来即可分辨 3 与 1/2；若是第 3 条且来自 `rigid_world.empty()`，说明快照函数在那一帧没填上刚体（`rigid_bodies` 为空）。

> 与 Q 的关系：562 是「整帧没有结果被应用」，Q 解释的是「子步数不同导致的位移差」；**两者可以同时成立，但 562 本身不是 Q 的直接后果**。562 之后的 563 尖峰更有可能是「一帧没应用 + 下一帧用了更新的结果」的追赶，而不是子步数。

## 5. 如果 Q 成立，最小修法

三种，按代价从低到高：

1. **（最小，推荐先做）启动时校验帧率比**：在 `StartStandaloneAsyncPhysics()` 里读 `document_fps` 与 `GetPhysicsSubsteps(op)`，若 `90 % document_fps != 0`（即 `1/fps ÷ 1/90` 不是整数），要么拒绝进异步档（fail-closed，日志一条），要么把 `fps_` 对齐到整数比。改动 ~8 行，不改物理算法。
2. **影子侧改手动子步**：把 `physics->Update(dt)` 换成
   `for (int i = 0; i < substeps; ++i) physics->GetDynamicsWorld()->stepSimulation(fixed, 1, fixed);`
   （`fixed = 1/90`）。每帧固定 `substeps` 次、每次 `n=1`，**相位彻底无关**。改动 ~6 行，但要注意 `saveKinematicState`/`synchronizeMotionStates` 的调用次数从 1 次变成 3 次（对 kinematic 语义有影响，需要在夹具里对照）。
3. **重建后相位对齐**：不可行——`m_localTime` 不可访问；只能靠「每次重建后补一次 `stepSimulation(0,0)`」之类的技巧，语义含混，不建议。

如果最终结论是「30 fps 下 Q 不成立」，那第 1 条仍然值得做（它把一类隐性风险变成显式拒绝），第 2 条不必做。

## 6. 三分类（明确结论）

| 分类 | 内容 |
| --- | --- |
| **Q 能解释** | 文档帧率与 `90Hz` 成非整数比时（25/24/29.97 fps）：主世界有非零累加残余、影子重建后归零、且无对齐机制 ⇒ 部分帧多算 1 子步，随后回补，尖峰形状吻合。 |
| **Q 不能解释** | 30 fps 文档下：`dt=1/30f` 与 `3×(1/90f)` float 位相等、残余恒 0、两侧恒 3 子步，相位无意义 ⇒ **不能**解释 541/561/563 的尖峰，也不能解释 562。 |
| **需要什么数据才能定** | ①`document_fps` 与 `GetPhysicsSubsteps(op)` 的实际取值（`mmd_model_runtime.cpp` 的 `ApplyPhysicsConfigToRuntime` 调用点打一行日志即可）；②每帧实际子步数 `n`（在 `MMDPhysics::Update` 前读 `m_localTime`、或临时在 `Update` 里循环里加计数）；③每帧 `result.rigid_world.size()`、`async_rigid_identity_mismatch_`、`ApplyStandaloneAsyncResult` 的 `result.epoch vs async_physics_epoch_` 三项（分辨 562 属于第 2 还是第 3 条）。 |

## 7. 边界与未做

- 本报告**只读**：未改任何源码、未建 patch、未编译、未跑 verify、未启宿主。
- 第 2 节是**按 Bullet 算法在 float 下重算**的结果，不是宿主实测；若宿主用 double 构建 `btScalar`（`BT_USE_DOUBLE_PRECISION`），结论需重算（`1/30` 与 `3×(1/90)` 在 double 下也不相等，但残余会以极慢速度累积：~3.7e-10/帧，约 3×10^7 帧才够一个子步，实际播放长度内仍不产生 4 子步）。
- 第 4 节的三条路径是从代码读出，**没有**宿主日志证据；`562` 的确切成因仍需第 6 节的数据项②③。
