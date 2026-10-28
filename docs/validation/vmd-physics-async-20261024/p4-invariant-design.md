# P4 不变量设计（t59 起草，t60 定论）

> **结论先行**：
> - **问题一（逐帧真实输入下是否逐位等价）：成立** —— 真实 PMX 世界上「影子晚一帧」在 199 帧 × 15,748 words 上严格 0 差异，且 dt、substeps、跳输入三条负向控制**全部变红**（证伪力已建立）。前提是夹具必须复刻产品的 `SetActivation(true)`，否则世界根本不积分。
> - **问题二（seek）：无历史重建** —— 同步路径 `ResetStandalonePhysics()` 整世界重建 + warm-start 清零（`mmd_model_runtime.cpp:828-876`），影子镜像重建即可保持等价，不必向「seek 后回退同步」妥协。
> - 边界：只覆盖 libMMD + Bullet 层；C4D 适配层、VMD 输入相位、接触主导场景未覆盖（见 §2.4）。

## 1. 实验设置（真实度边界）

夹具：`docs/validation/vmd-physics-async-20261024/offline/p4-equivalence-v2.cpp`，构建脚本 `build-p4-equivalence.ps1`。

真实性（已做到）：
- 世界由 `libmmd::PMXModel::Load()` 建立（`dependency/libMMD/src/libMMD/Model/MMD/PMXModel.h:251`），刚体/关节由 `PMXModel::LoadPMX` 内部调用 `MMDRigidBody::Create` / `MMDJoint::CreateJoint` 建成（`dependency/libMMD/src/libMMD/Model/MMD/PMXModel.cpp:648-688`）。
- 数据来自真实 PMX：`C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx`（625 骨骼 / 479 刚体 / 748 关节），`ReadPMXFile` 解析成功。
- 步进：`MMDPhysics::Update(dt)`，`SetFPS(90)`、`SetMaxSubStepCount(3)`，与插件 `source/module/tools/object/mmd_model_runtime.cpp:1040` 的口径一致。
- 同步/反射：`MMDRigidBody::SyncBonePositionToPhysics` / `ReflectGlobalTransform`，与插件物理桥同一路径。
- 快照：479 刚体世界矩阵（basis 3×3 + origin）+ 625 骨骼世界矩阵，共 **15,748 words**，比较为**逐 word memcmp，零容差**。

未覆盖（必须标注）：骨骼输入是确定性合成摆动而非 VMD；C4D 适配层（`MMDRigidManagerObject::BuildStandaloneRigidBodies`、`mmd_model_runtime.cpp` 物理桥）不覆盖；无蒙皮/渲染。

## 2. 问题一：等价性在真实世界成立吗？

**结论：成立（在真实 PMX 世界上、在本夹具的输入与步进口径下）。** 但这个「成立」是 t60 修好两处夹具缺陷之后才成立的——t59 那一版的正向 0 差异没有证伪力。

### 2.1 为什么 t59 的负向控制不可能变红（根因）

`libMMD` 建刚体时把动态刚体设为 kinematic：`MMDPhysics.cpp:814-828` 用 mass 建 `btRigidBody`，但只有 `Operation::Static` 才加 `CF_KINEMATIC_OBJECT`；**动态刚体随后在 `MMDPhysics.cpp:1026` 被 `SetActivation(false)` 打上 kinematic 标记**（产品在第一步之前会统一 `SetActivation(true)`）。t59 的夹具直接 `PMXModel::Load()` 后就开始步进，**没有复刻产品的 `SetActivation(true)`**（`source/module/tools/object/mmd_model_runtime.cpp:868-875` 的 `ResetTransform`/`Reset`/`SetActivation(true)` 三连），于是 479 个刚体全部是 kinematic，Bullet 只做运动学搬运、不做积分：改 dt、改 substeps 自然一个 word 都不变。t59 里「219 个刚体动了、最大 54 mm」原来只是骨骼驱动的搬运，不是物理响应。

t60 在夹具 `RealWorld::Load()` 末尾加 `ActivateDynamics()`（逐刚体 `SetActivation(true)`），并把「激活后 kinematic 数」打成 NOTE：`bullet_kinematic=479 → 27`（27 = PMX 里 op=Static 的数量），世界才开始真正积分。

第二处缺陷是影子时钟的起点：给 `Run()` 加 `lag` 后，若 lag 帧之前仍然步进（只是不喂输入），`async(1)` 与 `sync(0)` 会差一次「无输入的步进」，正向必然不等（实测 `first_diff_frame=1`、2,218,703 个 word 差异）。修法是**影子时钟从被启用那一帧开始**：`input_frame < 0` 时不步进。修后 `first_diff_frame=-1`、0 差异。

### 2.2 现在的实测（`offline/build/run-t60-final.log`，`RESULT cases=8 assertions=17 failures=0`，exit 0）

| 案例 | 结果 |
|---|---|
| `real-world-build-from-pmx` | 479 刚体 / 748 关节，与 PMX 一致；快照 15,748 words |
| `rigid-op` 直方图 | static=27、dynamic=450、dynamic_with_bone=2（`file.m_rigidbodies[i].m_op`） |
| `world-has-dynamics` | mass>0=452；激活后 `bullet_kinematic=27`（未激活时是 479 —— 这正是 t59 的病根） |
| **`physics-actually-simulates`** | 帧 0 vs 帧 199：**476/479 个刚体位移 > 1 mm，最大 8,032.30 mm**（本 PMX 没有 ground 刚体，自由落体；产品世界同样没有额外地面，重力 `-9.8×10` 见 `MMDPhysics.cpp:87`） |
| `same-cadence-identical-replay` | 两个独立真实世界、同输入同节奏：0 差异（比较器自证） |
| **`delayed-by-one-frame-bitexact`** | 影子晚一帧、199 帧 × 15,748 words：**0 个 word 差异**（严格 memcmp，零容差） |
| **`negative-skipped-input-detected`** | 跳到第 57 帧不喂输入：**检出**（>0 差异） |
| **`negative-dt-changed-detected`** | dt ×1.5：**1,736,170 个 word 不同**（16 个刚体漂移 >1 mm，最大 2.80 mm） |
| **`negative-substeps-changed-detected`** | substeps 3→2：**2,276,027 个 word 不同**（232 个刚体漂移 >1 mm，最大 40.04 mm） |

### 2.3 判定与门槛

- 正向等价性**只在三条负向控制全红之后**才被写成「成立」；三者分别打红在「输入序列」「积分步长」「子步上限」三个维度上。
- 夹具现在把「物理真的在演算」写成硬断言：`moved_over_1mm >= 300`、`max_mm > 50`（不满足即 fail），避免退回 t59 那种「冻结世界里的 0 差异」。
- 等价性口径：影子世界从被启用那一帧起，喂与同步世界**同一段输入序列**；`async(N)` 与 `sync(N−1)` 在 `lag=1` 时逐位相等（199 帧）。

### 2.4 仍未覆盖（不得越界宣称）

- 骨骼输入是确定性合成摆动，不是 VMD 采样；只验了「同一段输入序列」，没验「输入本身来自 VMD 时的相位/帧号映射」。
- 只覆盖 libMMD 层（`PMXModel::Load` → `MMDPhysicsManager` → `MMDPhysics` → Bullet），**不覆盖** C4D 适配层（`MMDRigidManagerObject::BuildStandaloneRigidBodies`、`mmd_model_runtime.cpp` 物理桥的 `SyncBonePositionToPhysics`/`ReflectGlobalTransform` 调用时机）。
- 位级一致只在「同进程、同二进制、同构建选项」下验证；跨编译器/跨进程（例如 worker 线程所在 TU 由不同 flags 编译）未验证。
- 本 PMX 无地面，自由落体 8 m；有接触/摩擦主导的场景（落地、衣摆挤压）未覆盖——接触求解是 warm-start 敏感区，单独需要一组实验。

## 3. 问题二：seek 之后还能不能保持等价？

代码事实（`source/module/tools/object/mmd_model_runtime.cpp:828-876` `ResetStandalonePhysics()`）：
- `:843-847` root adapter `ResetCurrentTransformToInitial()`；
- `:848` `const Bool rebuilt = BuildStandalonePhysics();` —— 整世界重建（销毁 + `MMDPhysicsManager::Create()` + 重新 `AddRigidBody`/`AddJoint`）；
- `:849` 重新同步骨骼适配器；
- `:860` `ApplyPhysicsConfigToRuntime(...)`（FPS/重力）；
- `:868-875` 所有刚体 `ResetTransform()`、`Reset(physics)`、`SetActivation(true)` —— **warm-start 与接触流形全部丢弃**。

结论：**无历史重建**（不是「携带历史」）。因此影子可以镜像重建保持等价，条件是重建序列与同步侧完全一致：重建 → 应用当帧配置 → 逐刚体 `ResetTransform`/`Reset`/`SetActivation(true)` → 再按同一帧号继续。

t58 的 68–115 mm 偏移与本结论不冲突：那是 `ReplayStandalonePhysicsToFrame()` 只反复步进、不重放逐帧输入造成的，不是 seek 重建语义的问题。

作废 epoch 的事件（实现时）：seek、时间轴跳变、开关切换、导出/7 处显式 `ExecutePasses`；恢复 async 的唯一时机是「重建完成且 epoch 递增之后」。

## 4. 下一轮改动点（带行号）

1. 影子世界必须复刻 `source/module/tools/object/mmd_model_runtime.cpp:868-875` 的 `ResetTransform`/`Reset`/`SetActivation(true)` 三连；否则动态刚体停在 kinematic 状态，影子世界不会积分（t60 实测：未激活时 479/479 kinematic，激活后 27）。
2. 影子时钟从启用帧开始（`lag` 帧之前不步进）；丢弃「先空转再补输入」，那会引入一次没有输入的步进。
3. seek 走 `ResetStandalonePhysics()`（`:848`）后按同样的激活顺序重建，等价性自动恢复（问题二结论）。

## 5. 本轮产物

- `offline/p4-equivalence-v2.cpp`：真实 PMX 世界夹具（8 案例 / 17 断言），含刚体 op 直方图、激活后 kinematic 计数、帧间位移统计与三条负向控制。
- `offline/build-p4-equivalence.ps1`：构建 + 运行（`-Pmx` 指定 ASCII 路径副本）。
- `offline/build/run-t60-final.log`：本轮定稿运行日志（`RESULT cases=8 assertions=17 failures=0`，exit 0）。
- `offline/build/model.pmx`：真实 PMX 的 ASCII 副本（libMMD 的 `fopen` 不支持中文路径）。
- 一次性补丁脚本（`add_motion_case.py`、`add_neg_notes.py`、`add_static_semantics.py`、`add_activation.py`、`fix_lag_clock.py`、`add_firstdiff.py`、`tighten_motion.py`、`update_report_t60.py` 等）留作取证。

## 6. P4 产品侧改动（t61，候选补丁 `candidate-async-p4.patch`）

这一节记录把 t60 的三条结论落进产品代码的形状。补丁只在候选目录生成，产品树零写入，
用 `git -C C:/code/C4D_MMD_Tool apply --check` 验证可合入。

### 6.1 影子世界的构建序列与主线程同源同序

`StartStandaloneAsyncPhysics()` 里，影子刚体建好后追加三连（`work/.../mmd_model_runtime.cpp`）：

```cpp
for (const auto& rigid_body : *rigid_bodies)
    if (rigid_body)
        rigid_body->ResetTransform();
for (const auto& rigid_body : *rigid_bodies)
    if (rigid_body)
        rigid_body->Reset(physics);
for (const auto& rigid_body : *rigid_bodies)
    if (rigid_body)
        rigid_body->SetActivation(true);
```

依据是 `ResetStandalonePhysics()` 的同类三连与 `MMDPhysics.cpp:1026` 的 `SetActivation(false)`：
缺这三步时动态刚体停在 kinematic，Bullet 只做运动学搬运、不积分（t60 实测 479/479 全部
kinematic）。夹具的 `negative-missing-activation-detected` 用例把这条变成可复现的失败：
去掉三连后 199 帧 × 15,748 words 里出现 **2,277,944** 个 word 不一致。

### 6.2 去掉 replay：seek / 导出 / 中途开启一律镜像重建

`ReplayStandalonePhysicsToFrame()`（P3 用「从共同起点重复步进」冒充历史）整段删除，
换成 `RebuildStandaloneAsyncShadow()`：停 worker、清零世界边界计数、按当前时点重建影子世界
（epoch 随世界边界推进）。`FlushStandaloneAsyncPhysics()` 不再靠 replay 保证「返回即当前帧」，
改为等待目标帧结果；中途开启也不再 replay——影子世界建在当前时点，本身就是同步世界的镜像。

这条对应 t58 的真机现象：`f=541` 整帧跳 93.6 mm，因为 replay 的轨迹与该帧之前真实喂进去的
VMD 输入轨迹不相交；重复步进再多次也对不上。

`cmt_physics_replay.h` 与 `async_frames_since_reset_` 的 replay 语义一并退出补丁（前者删除，
后者只保留为「世界边界清零」的计数）。verify 的门禁禁止 `ReplayStandalonePhysicsToFrame`、
`ReplayToFrame` 出现在 work 树。

### 6.3 载荷时点：当帧 pre-physics 骨骼世界矩阵

`StepStandaloneAsyncPhysics()` 先在主线程按 `physics_bone_pool_` 抓 `GetGlobalTransform()`
打包成纯数据载荷，**再**消费上一帧结果（`ApplyStandaloneAsyncRigidWorld`）。因此载荷里的骨骼
矩阵是动画/IK 之后、物理回写之前的当帧状态。夹具的 `negative-polluted-input-detected`
把「物理回写后的层级」当输入，立即产生 **2,655,980** 个 word 不一致——如果时点选错，
这条用例会绿，反之必红。

### 6.4 夹具（`candidate-async-p4/eqtest/p4-equivalence.cpp`，13 案例 23 断言）

| 类别 | 案例 | 观测 |
| --- | --- | --- |
| 真实世界 | `real-world-build-from-pmx` / `world-has-dynamics` | 479 刚体 / 748 关节；mass>0 = 452，激活后 Bullet kinematic = 27 |
| 物理真在积分 | `physics-actually-simulates` | 帧 0→199：476 个刚体位移 >1 mm，max 8032.3025 mm |
| 正向等价 | `same-cadence-identical-replay` / `delayed-by-one-frame-bitexact` | 199 帧 × 15,748 words，**0** 个 word 不一致 |
| 负向（原有） | `negative-skipped-input-detected` / `negative-dt-changed-detected` / `negative-substeps-changed-detected` | 跳第 57 帧、dt×1.5（1,736,170 word）、substeps 3→2（2,276,027 word） |
| 负向（P4 新增） | `negative-missing-activation-detected`（2,277,944）/ `negative-idle-clock-detected`（2,220,802）/ `negative-repeat-step-detected`（2,276,086）/ `negative-polluted-input-detected`（2,655,980） | 缺三连、时钟空转、多步一次、污染输入全部被检出 |
| 镜像重建 | `seek-mirror-rebuild-bitexact` | 两侧在同一语义时点重建后，后续 138 帧逐位相等 |

判定顺序：只有在四条负向全红之后，正向的 0 差异才算等价性证据。

## 7. 未覆盖项（P4 之后仍未证明）

1. **C4D 适配层调用时机**：`BuildStandaloneRigidBodies()` 从 BaseContainer 读参、`ExecutePasses`
   的插入点、7 处显式 flush 都在宿主里才跑到；离线夹具直接用 PMX 数据建世界。
2. **VMD 输入相位**：夹具用合成骨骼矩阵（`BoneMatrix`），不是真实 VMD 采样；相位/插值差异
   未覆盖。
3. **跨二进制 / 跨线程位级一致**：仿真在本进程内串行跑，worker 线程上的浮点环境与
   `-fp:strict` 之外的因素未验证。
4. **接触主导场景**：该 PMX 没有 ground 刚体，落地、挤压、约束抖动都没有覆盖；镜像重建在
   接触堆叠下的稳定性也未测。
5. **性能**：本轮没有任何计时；P4 的收益完全取决于下一轮真机 A/B/A。
6. **默认开启**：本补丁仍默认关（`CMT_PHYSICS_ASYNC` 未设置时走 `seam_sync`），默认开的前提是
   宿主侧先证明 P4 的镜像重建在 seek/导出路径上真的被调用。

## 8. t64（P4-001）：async epoch 随世界边界单调递增

**问题**：`StartStandaloneAsyncPhysics()` 每次都写 `async_physics_epoch_ = 1;`，而
`ShutdownStandaloneAsyncPhysics()` 里的 `++async_physics_epoch_;` 会被这一行覆盖。于是镜像重建
（seek / 导出 / 中途开启都走这条路径）之后，旧世界与「新一代世界」拿到同一个 epoch——
跨世界污染的排除只能依赖 `CancelAndJoin`「恰好清空了结果槽」这个实现细节，不是契约。

**改法（首次初始化与重建分离）**：新增 `new-files/cmt_physics_epoch.h` 的
`cmt::physics::PhysicsEpochCounter`，`Next()` 首次给 1、之后严格 +1，并在回绕时跳过 0（0 是「未初始化」哨兵）。
runtime 侧：`async_physics_epoch_ = async_epoch_counter_.Next();` 是**唯一**推进点；
`ShutdownStandaloneAsyncPhysics()` 不再自增（暂停/销毁不产生世界边界）；manager 成员初值改为 0。

**测试与证伪力**：夹具 `eqtest/p4-equivalence.cpp` 新增两案例——
`epoch-monotonic-across-world-rebuilds`（连续 6 次重建得到 1..6、严格递增、永不 0，并验证回绕跳过 0）、
`stale-epoch-result-rejected`（旧世界真实产出一帧 → 重建使 epoch 推进 → 新世界再产出一帧未消费 →
用旧 epoch 去取必须被拒绝、`stale_dropped` 恰好 +1、随后用新 epoch 取同一帧必须成功）。
证伪力验证：把 runtime 的 `async_epoch_counter_.Next()` 临时改回 `async_physics_epoch_ = 1;` 后
`verify.ps1` 的 stage 15b 立刻失败（`runtime never resets epoch to the constant 1`），恢复后全绿。

**边界**：夹具证明的是「计数器 + 结果槽 epoch 校验」这一层；`StartStandaloneAsyncPhysics()` 的调用时机
（哪些路径算世界边界）仍由 runtime 决定，属宿主验证项（t63）。

**本轮实测（t64）**

| 项 | 结果 |
| --- | --- |
| 夹具 | `RESULT cases=15 assertions=36 failures=0`（新增 2 案例、13 断言；既有 13 案例未变） |
| verify | `VERIFY OK patch=c4a35f62c9e9c59899d6318c567b49059f31cbc0541450198fffd21247b2ca4a cases=15 assertions=36 failures=0 gates=79`，exit 0 |
| 补丁 | `candidate-async-p4.patch` 74,256 B，+1662/−11，14 文件（13 + `cmt_physics_epoch.h`），`git apply --check` exit 0 |
| Release TU | 7 个 TU 全 `exit=0 errors=0`（p1-runtime / p1-manager 也带上新头文件编译） |
| 负向（证伪力） | 把 runtime 的 `async_epoch_counter_.Next()` 改回 `async_physics_epoch_ = 1;` → verify 在 stage 15b 立刻 `[fail] runtime takes epoch from the counter`，exit 30；还原后 exit 0 |
| 产品树 | `git diff --stat -- source` 为空（tracked 改动 0）；未启宿主、未联网 |

口径说明：`epoch-monotonic-across-world-rebuilds` 直接驱动产品头文件里的 `PhysicsEpochCounter`
（不是夹具自写的副本），`stale-epoch-result-rejected` 用产品管线实例真实跑两代世界。
