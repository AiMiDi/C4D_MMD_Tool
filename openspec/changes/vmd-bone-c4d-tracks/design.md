## Context



当前 VMD 骨骼动画的数据流是：



```

VMDFile → VMDAnimation::Create(mmd_model_) + Add(vmd_file)

    每帧 → VMDAnimation::Evaluate(frame)

         → MMDNode::SetAnimationTranslate/Rotate

    → PMXModel::UpdateNodeAnimation(false)  // 物理前: local变换 + 付与 + IK

    → PMXModel::UpdatePhysicsAnimation(dt)  // Bullet step

    → PMXModel::UpdateNodeAnimation(true)   // 物理后: local变换 + 付与 + IK

    → MMDBoneTag::Execute 从 mmd_node_->GetLocalTransform() 复制到 C4D 骨骼

```



`vmd-morph-c4d-tracks` 已将 morph 动画和 IK 开关迁移到 C4D CTrack。骨骼动画是最后一个仍由 libMMD 内部驱动的主要通道。



libMMD 中 `VMDBezier`（贝塞尔插值）、`MMDIkSolver`（IK 求解）、`MMDRigidBody`/`MotionState`（物理）均通过 `MMDNode*` 直接耦合到 libMMD 的节点系统，无法被外部独立使用。



代码中已有旧版骨骼 Tag 实现（`old/TMMDBone.cpp`）的完整参考：SplineData 插值曲线 UI、`VMDInterpolator` HashMap、`UpdateAllInterpolator` 将 VMD 贝塞尔参数转为 C4D CKey 切线等。



## Goals / Non-Goals



**Goals:**

- VMD 导入后，骨骼关键帧在 C4D 时间线中可见（通过骨骼 Tag 上 SplineData /「下一个关键帧」参数的 CTrack 标记），用户可编辑插值曲线与关键帧

- 骨骼 Tag 使用 VMD 原生贝塞尔插值算法自行评估动画，保证与 MMD 精确一致；位移与四元数旋转数据存于 Tag 内部结构，不在骨骼对象 PRS 上打关键帧

- 付与规则和骨骼动画评估仍由骨骼 Tag 持有，但播放时的 `动画 -> 付与 -> IK -> 物理 -> 回写` 统一由模型管理器调度，不依赖 libMMD 的 PMXModel 流水线

- 物理模拟通过回调函数读写 C4D 骨骼变换，不再依赖 MMDNode

- libMMD 中的贝塞尔插值、IK 求解器、物理模块可被外部独立使用

- `MMDModelManagerObject` 不再持有 `mmd_model_`；模型管理器直接拥有 standalone `MMDIKManager` 与 `MMDPhysicsManager`

- 利用 C4D `EXECUTIONPRIORITY_EXPRESSION` 内的优先级数值保证变形阶层与付与链的执行顺序



**Non-Goals:**

- 本次变更不要求立刻实现新的 bone VMD 导出器；但原始 VMD 来源数据会被**彻底删除**，因此后续 `SaveVMDMotion()` 若恢复 bone 通道导出，必须从骨骼 Tag 内部关键帧和模型管理器槽元数据 **重建 `VMDFile`**

- 相机动画迁移到 C4D CTrack（独立范围）

- 移除 libMMD 中 `VMDAnimation` 现有的骨骼评估代码（保持 API 兼容，仅提取算法为独立模块）

- 支持实时物理编辑（当前仅在 VMD 模式和动画模式下运行物理）



## Decisions



### D1: 骨骼动画数据与评估 — 内部 map + SplineData /「下一个关键帧」CTrack



**选择**：

- **权威数据**：骨骼 Tag 内维护有序结构（sorted array / map），每项包含 VMD 帧号、`translate`、`quaternion`、以及 X/Y/Z/R 四通道的插值曲线数据（与 `VMDMotion::m_interpolation` 解码一致）。通过 `MMDBoneTag::Write` / `Read`（HyperFile）序列化。

- **时间线与 F-Curve 标记**：在 Tag 的 **SplineData** 参数与 **「下一个关键帧」Int** 参数上创建 CTrack/CKey，用于在时间线显示关键帧、在 F-Curve 中显示标记；用户在该 SplineData 控件中编辑 0–127 范围的 VMD 贝塞尔控制点。**不在骨骼对象的 position/rotation CTrack 上写入关键帧**；**不在 Tag 上增加独立的位移 XYZ / 四元数 WXYZ 可动画参数**。

- **播放**：`MMDBoneTag` 提供“当前活动槽 -> 当前帧局部动画结果”的评估 helper，播放主循环改由 `MMDModelManagerObject::Execute` 统一调度。在 **动画模式** `BONE_MODE_ANIM` 下，模型管理器按稳定顺序调用骨骼 Tag helper，使用独立模块 `InterpolateBoneKeys`（VMD Bezier + 四元数 slerp）计算局部动画结果，写入 `C4DIKChainNodeAdapter`/standalone runtime，并在整帧末尾统一回写骨骼对象。导入 PMX 时建立的 frozen bind pose 继续表示静态骨架初始姿态，不作为每帧动画输出的目标。



**理由**：

- VMD 贝塞尔语义与 C4D 标量 F-Curve 不同；数值真值以内部结构与 libmmd 插值为准。

- SplineData CTrack 提供编辑入口与时间线可见性，无需在对象 PRS 上 duplicate 关键帧值。



### D2: 付与（Append Transform）由模型管理器调用骨骼 Tag helper 实现



**选择**：付与逻辑保留在 `MMDBoneTag` 的评估 helper 中，但不再由各 tag 自己的 `Execute` 直接驱动。模型管理器在统一播放管线中按骨骼顺序调用这些 helper；每根有付与属性的骨骼读取其付与源骨骼的 Tag runtime state，获取已评估的动画/IK/物理后有效旋转与位移，并按权重叠加到自身。



**理由**：付与需在骨骼动画评估之后、与 IK / 物理阶段协调；如果仍由各 tag 分散在 `Execute` 中写回骨骼，后续 tag 很容易覆盖同帧前面求出的 IK / physics 结果。通过模型管理器统一调度，可以在保持 bone tag 数据权威的同时，确保同帧只提交一次最终骨骼状态。



**执行顺序（与 D6 一致）**：付与链按 **付与递归深度** 在同一变形层内排序；同深度、无依赖的骨骼可共享同一优先级数值。变形层与深度共同决定 Tag 的优先级数值（见 D6）。



### D3: `IMMDNode` 抽象接口（IK 求解器及其他子系统）



**选择**：定义 **`IMMDNode`** 纯虚接口（`IMMDNode.h`），供 IK 求解器及后续物理绑定、外部适配器等复用；求解器依赖的节点操作（`GetGlobalTransform`/`SetGlobalTransform`/`GetLocalTransform`/`SetIKRotate`/`GetIKRotate`/`AnimateRotate`/`UpdateLocalTransform`/`UpdateGlobalTransform`/`GetParent` 等）均通过该接口访问。**`MMDNode`** 继承并实现该接口以保持 libMMD 内部路径兼容。**C4D 插件** 提供 **`C4DIKChainNodeAdapter`**（`c4d_ik_chain_node_adapter.h`），包装 `BaseObject*` + `MMDBoneTag*`，在 IK 迭代期间维护**临时全局变换缓存**（因 C4D 中 `SetMg()` 不会立即传播到子对象，与此前设计一致）。



**理由**：虚接口边界清晰、类型安全，便于单元测试 Mock；与物理模块的 `IMMDNode` 绑定（D4）共用同一抽象，IK 链与节点生命周期仍适合面向对象的适配器模型。



### D4: 物理模块通过 IMMDNode 绑定外部骨骼



**选择**：在 `MMDPhysics.cpp` 中新增一组 `External*MotionState` 类，通过 `IMMDNode*`（与 IK 同一抽象）读写全局矩阵，替代内建 `MMDNode*`。`MMDRigidBody::Create` 新增 `Create(const PMXRigidbody&, IMMDNode*)`；刚体 offset 使用 `IMMDNode::GetInitialGlobalTransform()`。



**接口设计**：

```

// 外部绑定：直接传入 IMMDNode*；offset 用 GetInitialGlobalTransform()

```



**理由**：

- MotionState 已经是 `MMDNode*` 与 Bullet 之间的适配层，替换为 `IMMDNode*` 与 IK 共用同一宿主抽象。

- `CalcLocalTransform()` 在外部绑定模式下不需要——C4D 的场景图自动处理父子变换。

- `UpdateChildTransform()` 在外部绑定模式下不需要——C4D 在下一次评估时自动传播。

- 保留原有 `MMDNode*` 版本的 MotionState，新增外部版本共存。



**`MMDModel*` 依赖的移除**：`Create` 中 `model` 仅用于获取根节点（当 `node==nullptr` 时），外部绑定版本通过 `initialGlobalTransform` 与 `IMMDNode*` 替代。



### D5: VMD 插值算法提取为独立模块



**选择**：将 `VMDBezier`、`SetVMDBezier`/`GetVMDBezier`、`FindBoundKey`、骨骼/morph 插值纯函数提取到 `VMDInterpolation.h/cpp`。`VMDAnimation` 内部改为调用提取出的函数。



**模块内容**：

- `VMDBezier` 结构体（`EvalX/EvalY/EvalDX/FindBezierX`）

- `SetVMDBezier(VMDBezier&, const uint8_t* cp)` / `GetVMDBezier(const VMDBezier&, uint8_t* cp)` — 字节编解码

- `VMDBoneKeyframe` 数据结构（frame, translate, rotate, 4x VMDBezier）

- `InterpolateBoneKeys(key0, key1, currentFrame)` → `{translate, rotate}` 纯函数

- `FindBoundKey<T>` 模板（二分查找关键帧段）



**文件位置**：`dependency/libMMD/src/libMMD/Model/MMD/VMDInterpolation.h/cpp`，与 `VMDAnimation` 同目录，方便引用。



### D6: 执行顺序 — 统一 `EXECUTIONPRIORITY_EXPRESSION` + 数值区间



**背景**：[Cinema 4D SDK — Scene Execution Pipeline / Priority](https://developers.maxon.net/docs/cpp/2026_1_0/page_manual_cinemathreads.html#page_manual_cinemathreads_execute_priority) 指出，在 `Execute` 中修改对象位姿等参数，**应优先在 expression 阶段进行**；跨阶段滥用可能导致缓存反复重建或属性管理器数据不一致。因此不再采用「物理前 = ANIMATION、物理后 = DYNAMICS」的三类分组来区分骨骼 Tag。



**选择**：骨骼 Tag 与模型管理器上驱动骨骼变换/物理的 Execute **均使用 `EXECUTIONPRIORITY_EXPRESSION`**，仅用 **优先级数值** 区分：物理前骨骼 → 物理步进（模型管理器）→ 物理后骨骼。骨骼 Tag 在动画模式下仍参与表达式调度与 UI 同步，但**不再在 Execute 中直接写最终骨骼矩阵**；最终提交由模型管理器统一完成。



**数值方案**（`append_depth` = 全局付与递归深度，同深度无依赖骨骼可共享编号）：

- **物理前骨骼**：`priority = deform_layer × 100 + append_depth`（建议占用约 0～2999）

- **模型管理器（Bullet 步进）**：`priority = 5000`（固定）

- **物理后骨骼**：`priority = 6000 + deform_layer × 100 + append_depth`（建议占用约 6000～8999）



示例：变形层 0、无付与 → 0；变形层 0、付与深度 1 → 1；变形层 1、无付与 → 100；物理后变形层 1 → 6100。



### D7: 模型管理器独立运行时管理器



**选择**：`MMDModelManagerObject` 不再持有 `mmd_model_` / `PMXModel`，也不再保留旧的 `RebuildRuntime` / `SetMMDModel` 家族。模型管理器改为直接拥有 standalone `libmmd::MMDIKManagerT<libmmd::MMDIkSolver>`（或等价 `MMDIKManager` 封装）与 `libmmd::MMDPhysicsManager`。



**新流程**：

1. PMX 导入完成后，模型管理器根据骨骼 Tag 的 IK 描述直接创建 standalone IK manager，并为每条 IK 链创建 `MMDIkSolver`

2. 创建 standalone `MMDPhysicsManager` 并调用 `Create()`

3. 遍历 `MMDRigidObject` 子对象，使用 `MMDRigidBody::Create(..., IMMDNode*)`（C4D 骨骼适配器实现 `IMMDNode`，必要时先 `SetBindingGlobalTransform()`）创建 `MMDRigidBody`

4. 遍历 `MMDJointObject` 子对象，创建 `MMDJoint`

5. 将 rigid body 和 joint 注册到 Bullet world

6. `BuildIKSolverUI` / `ApplyIKSolverStates` / `ImportVMDIKKeyframes` / Execute 中的 IK 状态读取全部改为访问 standalone IK manager，而不是 `mmd_model_->GetIKManager()`

7. 不再调用 `ReconnectNodePointers`（骨骼 Tag 不再持有 `mmd_node_`）

8. 不再重建 `VMDAnimation`；骨骼动画数据在 **骨骼 Tag 内部结构** + **SplineData /「下一个关键帧」CTrack** 中持久化

9. 每帧播放时采用统一调度：
   - 按 `deform_layer + append_recursion_depth + bone_index` 的稳定顺序遍历 **物理前** 骨骼，调用 bone tag helper 评估动画/付与并写入 adapter；遇到 IK 骨骼时由模型管理器统一触发 solver，并同步 IK runtime state
   - 执行 standalone physics step，但不立即把结果写回 C4D 场景对象
   - 将 physics 驱动骨骼的 local state 作为 runtime override 回填到 source bone tag，供 **物理后** 骨骼继续读取
   - 再按同样顺序遍历 **物理后** 骨骼，跳过 physics 驱动骨骼自身的动画覆盖，只评估非 physics-driven 骨骼及其 IK
   - 整帧最后统一 `ApplyStandaloneBoneAdaptersToScene()`，避免同帧中间结果被后续 tag 覆盖

**补充说明（与当前代码结构对齐）**：

- 这不只是“场景重开后的恢复路径”变化。当前代码在 **初次 PMX 导入** 时也会通过 `MMDBoneManagerObject::LoadPMX` / `SetMMDModel` 把 `mmd_node_`、`ik_solver_` 等 libMMD 运行时对象塞回骨骼 Tag。该提案落地时，这条初始绑定路径也必须同步拆掉，否则会出现“新播放路径已去 `mmd_node_`，但导入期仍偷偷建立依赖”的半迁移状态。
- 场景重开后的恢复也不再是“重建 PMXModel 再拆出子系统”，而是直接从 C4D 对象数据重建 standalone IK/Physics 管理器。
- `MMDMorphManager` 不再是模型管理器运行时的一部分；morph 通道继续由 C4D CTrack / 数据对象驱动。



### D8: 用户关键帧编辑（「+」/「−」）



**选择**：用户在视口调整骨骼姿态后，点击动画组 **「+」**：从当前骨骼读取 **相对绑定姿态的局部动画结果**（与 `Execute` 写回目标一致，而不是直接读取 frozen bind pose），旋转转为四元数，写入内部关键帧表（同帧则覆盖）；同步更新/创建该帧上的 SplineData 与「下一个关键帧」相关 CKey。**「−」**：删除当前 VMD 帧对应关键帧数据及相应 CKey（实现细节以任务为准）。



**理由**：保证编辑结果与 VMD 插值管线一致，且不依赖对象 PRS 上的关键帧。



### D9: 模式枚举合并 — 取消独立的 `*_MODE_VMD`

**现状**：`MODEL_MODE` / `BONE_MODE` / `MESH_MODE` / `JOINT_MODE` / `RIGID_MODE` 等均为 **编辑 / 动画 / VMD** 三态；其中「动画」与「VMD」在迁移后都表示「按时间播放场景内动画数据」，语义重复。

**选择**：删除各描述中的 **`*_MODE_VMD` 枚举值**，仅保留 **`*_MODE_EDIT`** 与 **`*_MODE_ANIM`**。原 VMD 管线（骨骼 Tag 内部关键帧、物理、Morph CTrack 等）全部在 **`*_MODE_ANIM`** 下运行，不再用模式位区分「是否 VMD」。

**资源与兼容**：更新 `OMMDModelManager.res`、`OMMDBoneManager.res`、`OMMDMeshManager.res`、`OMMDJointManager.res`、`OMMDRigidManager.res` 及对应 `*.h`、中英 `*.str`；旧场景反序列化时若读到已废弃的 `*_MODE_VMD` 数值，**映射为 `*_MODE_ANIM`**。

**代码**：所有 `== *_MODE_VMD` 分支改为 `== *_MODE_ANIM`（或与「非 EDIT」等价判断），子管理器 `SetAllBoneMode` 等同步改为仅发 `BONE_MODE_ANIM`。



### D10: `MODEL_ANIM_LIST` 与多段动画（内部数据）切换

**现状**：`MMDModelManagerObject::animation_index_` 选择 `animations_` 中的 `libmmd::VMDAnimation`，`SetDParameter(MODEL_ANIM_LIST)` 时用 `GetMaxKeyTime()` 设置文档时间范围。

**选择**：动画列表仍用 **`MODEL_ANIM_LIST`**（UI 与参数 ID 可保留），但语义改为 **活动动画槽索引**（0…N−1 或含「无」）。每段导入的 VMD 对应一个槽；骨骼关键帧与曲线数据不再依赖 `VMDAnimation` 驱动播放。

**数据放置（推荐）**：在 **`MMDBoneTag` 内为每根骨骼按槽存储** 多套关键帧块（每槽：`sorted keyframes` + 该槽对应的 SplineData /「下一个关键帧」标记策略）；模型管理器侧仅保留一份 **槽级元数据**（至少包含显示名、最大帧），用于列表 UI、删除和文档时间范围。切换 **`MODEL_ANIM_LIST`** 时：

1. 更新 `animation_index_`，向骨骼管理器/骨骼 Tag **广播当前活动槽**（`MultiMessage` 或已有消息扩展）；
2. 各 **`MMDBoneTag`** 的活动槽数据由模型管理器在统一播放管线中调用 helper 做 `InterpolateBoneKeys`，而不是由各 tag 自己的 `Execute` 分散驱动；
3. **`doc->SetMaxTime` / `SetLoopMaxTime`** 根据当前槽内关键帧时间并集（或槽元数据中记录的最大帧）计算，**不再**调用 `VMDAnimation::GetMaxKeyTime()`。

**与当前代码强相关的澄清**：

- 当前 `DeleteVMDAnimation()`、`SaveVMDMotion()`、`MODEL_ANIM_LIST` 文案和列表项都直接依赖 `animations_`。本提案的决策是：**原始 VMD 来源数据彻底删除**，这些行为都要改为依赖 bone tag 数据和模型管理器槽元数据。
- **播放权威** 迁移为“bone tag 数据 + model manager 播放调度”组合：bone tag 仍是骨骼动画真值持有者，模型管理器不再保留任何可回放的原始 VMD 来源对象，但承担统一调度与最终提交职责。
- 当前 morph / IK 关键帧仍位于模型管理器 CTrack 上。本提案定义的是 **骨骼通道** 的槽切换语义；若希望 morph / IK 也做严格的按槽隔离，需要后续单独定义模型管理器侧多槽轨道策略。

**备选**：槽数据仅存在模型管理器 HyperFile、切换时整块写入骨骼 Tag（内存换简单序列化）；文档中可记为实现选项。



## Risks / Trade-offs



- **[风险] EXPRESSION 内优先级顺序**：同一 `EXECUTIONPRIORITY` 类别下，不同数值是否严格按递增顺序执行，需用简单场景验证。→ 缓解：最小样例（付与链 + 物理前/后各一根骨）做概念验证。

- **[风险] IK 适配器性能**：`C4DIKChainNodeAdapter` 的临时全局变换缓存在 IK 求解时若每帧分配，可能影响性能。→ 缓存在骨骼 Tag 或适配器成员上持久化，避免每帧堆分配。

- **[风险] 付与递归深度**：极端模型付与链很长；需保证 `append_depth` 与层号在 PMX 导入时计算正确。→ 缓解：与 PMX 付与字段一致建图后做拓扑深度。

- **[风险] 旧场景兼容性**：已保存的 VMD 场景没有新格式骨骼数据，需重新导入。→ 缓解：旧场景加载不崩溃；`pending_vmd_data_` 仍可读取；提示用户重新导入 VMD；废弃 `*_MODE_VMD` 读值映射到 `*_MODE_ANIM`。

- **[风险] 多槽数据体量**：每骨骼多段 VMD 会使 Tag 序列化体积增大。→ 缓解：按需懒加载槽、或槽仅存引用与外部资源路径（若采用备选方案）。

- **[风险] 导出/删除/动画列表仍耦合 `animations_`**：当前代码的删除、导出和动画名列表都把 `animations_` 当事实来源，而本提案要求彻底删除原始 VMD 来源数据。→ 缓解：将这些行为统一改到 bone tag 数据和模型管理器槽元数据上；future export 只能从数据对象重建 `VMDFile`。

- **[权衡] 内部 map 与 HyperFile**：位移/旋转与曲线主要存在 Tag 自定义序列化路径，维护成本高于纯 CTrack。→ 缓解：结构体版本号、单元测试往返。

- **[权衡] libMMD 接口变更**：`IMMDNode` 增加 `GetInitialGlobalTransform` 与物理 `Create` 重载。→ 缓解：保留 `MMDNode*` 旧重载/原有 `MMDIkSolver` 用法；外部绑定通过 `IMMDNode*` 与 IK 共用适配器。

- **[风险] 物理回调线程安全**：C4D 执行管线可能多线程。→ 缓解：物理在模型管理器单一 Execute 中串行；回调仅在文档执行线程访问场景（遵循 SDK 约束）。


