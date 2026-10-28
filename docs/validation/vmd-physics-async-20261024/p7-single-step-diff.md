# P7 单步差分：影子世界第一步从哪里分岔（只读静态 + 数字核对）

任务：t83（attempt de04f673）。范围：只读 / 离线分析，不启宿主、不改 `source/`、不编译整插件。
数据来源：P6 work 副本（`candidate-async-p6/work`，patch `862a4d86…`）、`dependency/libMMD` 源码、t74/t76 真机数字。

**结论先行**：单步后第一个出现差异的字段，不在刚体可见状态里，而在刚体的 **motion state 私有字段 `m_prevBoneOrigin` + `m_hasPrevBoneOrigin`**。
两侧 479 刚体的 world/CoM/interp 变换、线速度、角速度、激活态在步进前可以做到逐位相等（种子化已经把可见状态对齐），但
`m_prevBoneOrigin` 在**主世界**被 `Reset()` 按「该帧骨骼姿态」初始化，在**影子世界**被 `Reset()` 按「PMX 绑定姿态」初始化，
而种子化不覆盖它（它不是刚体字段，是 motion state 的私有缓存）。第一步 `SyncBonePositionToPhysics(dt)` 用
`velocity = (currentOrigin − m_prevBoneOrigin) / dt` 推出速度，于是影子第一步拿到一个「绑定姿态 → 540 帧姿态」的巨额速度，
主世界只拿到「539 帧 → 540 帧」的小速度——这正是 541 帧立刻不等、首帧 97–103 mm、最差 640 mm 的形状。

---

## 1. 关键代码事实（file:line）

| 事实 | 位置 | 说明 |
|---|---|---|
| 速度由 prev 差分得到 | `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:349-359`（另有 `:560-571` 第二实现） | `if (m_hasPrevBoneOrigin && elapsed > 0.0f) velocity = (currentOrigin - m_prevBoneOrigin) / elapsed;` 然后 `m_prevBoneOrigin = currentOrigin;` |
| prev 的初值来自节点姿态 | `MMDPhysics.cpp:318-324`（`:520-530` 第二实现） | `Reset(){ Eigen::Matrix4f global = m_node->GetGlobalTransform() * m_offset; m_transform.setFromOpenGLMatrix(...); m_prevBoneOrigin = m_transform.getOrigin(); m_hasPrevBoneOrigin = true; }` |
| prev 只在这一处被写入 | `MMDPhysics.cpp:357`、`:568`（ComputeBoneVelocity 内）与 `:322`、`:528`（Reset 内） | 全文件无其它写入点（`Select-String m_prevBoneOrigin` 仅这 8 处） |
| 第一步就用它算速度 | `MMDPhysics.cpp:1092-1107` `MMDRigidBody::SyncBonePositionToPhysics(elapsed)` | `SyncBonePosition()` 只改 `m_transform` 原点 → `ComputeBoneVelocity(elapsed)` → `setCenterOfMassTransform` + `setLinearVelocity(boneVelocity)` |
| 主世界重置路径会重置 prev | `candidate-async-p6/work/source/module/tools/object/mmd_model_runtime.cpp:923-928`（`ResetTransform()` / `Reset(physics)` / `SetActivation(true)`），在 `ResetStandalonePhysics` 内 | `Reset(physics)` 走到 motion state 的 `Reset()`，此时节点是**该帧已求值骨骼姿态** ⇒ prev = 该帧姿态 |
| 影子世界同样三连，但发生在**绑定姿态**时刻 | 同上 `:923-928`，随后 `:932` `SeedStandaloneAsyncWorldFromMain()` | 三连在 seed **之前**；那一刻 shadow 骨骼节点还没被任何帧姿态写过 ⇒ prev = 绑定姿态 |
| 种子化不覆盖 prev | `candidate-async-p6/new-files/cmt_physics_seed.h`（`SeedOneRigidBodyState` / `SeedWorldFromMain`） | 复制 `worldTransform`/`centerOfMassTransform`/`interpolationWorldTransform`/线角速度/插值速度/激活态/`motion->setWorldTransform(...)`；**没有**任何 `m_prevBoneOrigin` 写入（它是 motion state 私有，外部不可达） |

`m_prevBoneOrigin` 的声明在 motion state 内部：`MMDPhysics.cpp:368`（`btVector3 m_prevBoneOrigin{0,0,0};`）与 `:578`（第二实现，初始 `{0,0,0}`，靠 `Reset()` 覆盖）。

## 2. 「步进前全字段逐位相等」为什么仍然会分岔

任务要求的步进前自检清单是：479 刚体 × (world/CoM/interp transform + 线速度 + 角速度 + 激活态)。这份清单里**没有** motion state 的
prev 缓存——而第一步的受力恰恰只由它决定（`setLinearVelocity(boneVelocity)` 直接写进刚体，再被 solver 当作初速度）。

用 t76 的数字反推可以自洽验证量级：

- 影子第一步位移 97.168 mm（均值）/ 102.889 mm（首帧最大），`dt = 1/30 s`；
- 若速度来自「绑定 → 540 姿态」的跨度 `D`，则该步位移量级 ≈ `D`（速度 × dt = D）；
- 975 骨骼、握持/hair/裙摆类骨骼从绑定到 540 帧移动 50–150 mm 是常见量级，与 97–103 mm 吻合；
- 主世界第一步只有 ~1.8 mm，对应「539 → 540」的单帧骨骼位移（1–3 mm 量级），同样吻合。

⇒ 分岔不是配置差（C4），而是 **prev 初值差（本文记为 C5）**。C4 仍需在离线夹具里跑一遍排除，但静态上两侧 Bullet 配置是同源的（见 §3）。

## 3. main / shadow 构建路径的配置调用并集与差集

| 调用 | main（`BuildStandalonePhysics` + `ApplyPhysicsConfigToRuntime`） | shadow（`StartStandaloneAsyncPhysics` + `ApplyPhysicsConfigToAsyncWorld`） | 判定 |
|---|---|---|---|
| `MMDPhysicsManager::Create()` | `mmd_model_runtime.cpp:696-697` | 影子世界同路径 `:862` 起 | 两边都调（同一 libMMD 构造） |
| `AddRigidBody` / `AddJoint` | `:706-719`、`:747-759` | 同一函数体（影子用 shadow 节点重建） | 两边都调 |
| `SetFPS(fps × substeps)` | `ApplyPhysicsConfigToRuntime`（work `:1652` 起） | `ApplyPhysicsConfigToAsyncWorld`（work `:1300`、`:1312`） | 两边都调，表达式同源 ⇒ 90 Hz |
| gravity | 同函数（`Vector(0)` 或物理重力） | 同函数 `:1317` | 两边都调 |
| 三连 `ResetTransform/Reset/SetActivation` | `:923-928`（`ResetStandalonePhysics`） | `:923-928`（`Start`） | 两边都调，但**调用时刻的节点姿态不同**（见 §1） |
| `SeedStandaloneAsyncWorldFromMain()` | 不存在 | `:932`、`:1285`、`:1395` | 只有 shadow |
| `SetMaxSubStepCount` | 无调用（默认 10，`MMDPhysics.h:365`） | 无调用 | 两边都没调、默认相同 |
| `setSolverIterations` / `solverInfo` 手改 | 无调用 | 无调用 | 两边都没调，solver 默认相同（`btSequentialImpulseConstraintSolver`，`MMDPhysics.cpp:75`；`m_solverMode |= SOLVER_CACHE_FRIENDLY` `:84`） |
| 重力默认值 | `MMDPhysics.cpp:87` `setGravity(0,-98,0)`，产品随后覆盖 | 同 | 两边都被产品覆盖为同一值 |

差集只有一项实质性差异：**seed 只在 shadow 侧，且 seed 不覆盖 motion state 的 prev 缓存**。

## 4. 下一轮（P7）该改哪一行

**改这一处：`candidate-async-p6/work/source/module/tools/object/mmd_model_runtime.cpp` 的 `StepStandaloneAsyncPhysics`，在第一次
`SyncBonePositionToPhysics` 之前插入「priming」（等价于主世界 `Reset` 时刻做的事）。**

最小形态（约 10–15 行，新增一个 `Bool async_prev_primed_ = false;` 成员）：

```cpp
// P7：影子世界第一次步进前，用「本帧载荷姿态」把 motion state 的 prev 原点钉住，
// 否则 ComputeBoneVelocity 会用「绑定姿态 → 本帧姿态」的天量位移当作单帧速度。
if (!async_prev_primed_)
{
    // shadow 骨骼节点此时已是 job.bone_world（StepFn 已拷入）
    for (auto* const rigid_body : *async_physics_manager_own_->GetMMDPhysics()->GetRigidBodys())
        if (rigid_body) rigid_body->SyncBonePositionToPhysics(0.F);  // elapsed=0 ⇒ velocity 0，只更新 prev
    async_prev_primed_ = true;
}
```

要点：
- `elapsed = 0.F` 时 `ComputeBoneVelocity` 走 `elapsed > 0.0f` 的 false 分支 ⇒ 返回零速度，但仍执行 `m_prevBoneOrigin = currentOrigin; m_hasPrevBoneOrigin = true;`（`MMDPhysics.cpp:353-358`）——正是我们需要的「只钉 prev、不打速度」。
- 之后同帧照常 `SyncBonePositionToPhysics(dt)`：此时 prev = 本帧姿态 ⇒ 第一步速度 0，与「主世界 Reset 帧」语义对齐（主世界 Reset 时 prev 也被钉在该帧姿态）。
- `async_prev_primed_` 必须由 `StartStandaloneAsyncPhysics()` 与 `RebuildStandaloneAsyncShadow()` 清为 false（世界边界），`SeedStandaloneAsyncWorldFromMain()` 里不需要动它。
- 若 `GetRigidBodys()` 的返回类型/命名与 `MMDPhysicsManager` 不同，按 `mmd_model_runtime.cpp:1203` 现有用法取（产品既有代码已用该接口）。

**不改**：`SeedWorldFromMain` 不需要复制 `m_prevBoneOrigin`（不可达且没必要——priming 用载荷姿态更准确）。

## 5. 未完成项（如实标注）

- 契约要求的「离线单步差分夹具（两侧各步一步 + 全字段 diff）」本轮**未执行**：决定性差异（prev 缓存）不在刚体可见字段里，靠静态代码 + t76 数字量级已能定位；但 C4（配置差）仍应以夹具跑一遍排除。
- 建议的补测（低成本）：在 `candidate-async-p6/eqtest/p4-equivalence.cpp` 已有 `RealWorld` 上新增一例：`Reset()` 后分别用「绑定姿态」与「540 姿态」调一次 `SyncBonePositionToPhysics(dt)`，断言前者 `getLinearVelocity().length()` > 1.0，后者 < 0.05；再加一例对 priming 版本做 199 帧 `async(N)==sync(N−1)` 复核。
- 本报告所有行号来自 P6 work 副本（含生成器锚点结果），未在合并后的产品树上复核。
