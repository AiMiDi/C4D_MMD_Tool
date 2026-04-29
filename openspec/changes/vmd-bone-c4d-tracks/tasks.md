## 1. libMMD — VMD 插值算法独立模块



- [x] 1.1 创建 `VMDInterpolation.h`：声明 `VMDBezier` 结构体（从 `VMDAnimation.h` 移出）、`SetVMDBezier`/`GetVMDBezier` 函数、`VMDBoneKeyframe` 数据结构、`InterpolateBoneKeys` 纯函数、`FindBoundKey` 模板函数

- [x] 1.2 创建 `VMDInterpolation.cpp`：实现 `VMDBezier::EvalX/EvalY/EvalDX/FindBezierX`（从 `VMDAnimation.cpp` 迁移）、`SetVMDBezier`/`GetVMDBezier`（从匿名命名空间提升为公开函数）、`InterpolateBoneKeys` 纯函数

- [x] 1.3 修改 `VMDAnimation.h`：`#include "VMDInterpolation.h"` 保持 `VMDBezier` 的向后兼容，移除 `VMDBezier` 的本地声明

- [x] 1.4 修改 `VMDAnimation.cpp`：内部 `VMDNodeController::Evaluate` 改为调用 `InterpolateBoneKeys`（或直接使用提取出的函数），移除已迁移的本地实现

- [x] 1.5 更新 libMMD CMakeLists.txt 添加新源文件

- [x] 1.6 编写 `VMDInterpolation` 单元测试：线性插值、非线性贝塞尔插值、字节编解码往返、边界帧处理



## 2. libMMD — MMD 节点抽象接口 `IMMDNode`



- [x] 2.1 创建 `IMMDNode.h`：定义 `IMMDNode` 纯虚接口（`GetGlobalTransform`/`SetGlobalTransform`/`GetLocalTransform`/`SetIKRotate`/`GetIKRotate`/`AnimateRotate`/`UpdateLocalTransform`/`UpdateGlobalTransform`/`GetParent` 等）

- [x] 2.2 修改 `MMDNode.h`：`MMDNode` 继承 `IMMDNode`，现有方法标记为 `override`

- [x] 2.3 修改 `MMDIkSolver.h`：`m_ikNode`/`m_ikTarget` 类型从 `MMDNode*` 改为 `IMMDNode*`；`IKChain::m_node` 同改；`m_chainPath` 改为 `std::vector<IMMDNode*>`

- [x] 2.4 修改 `MMDIkSolver.cpp`：`Solve`/`SolveCore`/`SolvePlane`/`BuildChainPath`/`UpdateChainPathGlobalTransform` 中所有 `MMDNode*` 改为 `IMMDNode*`

- [x] 2.5 确保 `PMXModel.cpp` 中 `SetIKNode`/`SetTargetNode`/`AddIKChain` 的 `PMXNode*` 参数仍可隐式传入（`PMXNode` → `MMDNode` → `IMMDNode`）

- [x] 2.6 编写 IK 接口单元测试：创建 Mock `IMMDNode` 实现的简单 3 骨骼链，验证 `Solve()` 收敛



## 3. libMMD — 物理模块外部绑定



- [x] 3.1 在 `IMMDNode` 上增加 `GetInitialGlobalTransform()`；物理外部绑定仅使用 `IMMDNode*`（与 IK 对齐）

- [x] 3.2 在 `MMDPhysics.cpp` 中新增 `ExternalKinematicMotionState`（`getWorldTransform` 使用 `IMMDNode::GetGlobalTransform()`）

- [x] 3.3 新增 `ExternalDynamicMotionState`（`ReflectGlobalTransform` 调用 `IMMDNode::SetGlobalTransform()`）

- [x] 3.4 新增 `ExternalDynamicAndBoneMergeMotionState`（`SyncBonePosition` / `ComputeBoneVelocity` 经 `IMMDNode`）

- [x] 3.5 `MMDRigidBody::Create` 新增 `(const PMXRigidbody&, IMMDNode*)` 重载，offset 使用 `GetInitialGlobalTransform()`，根据 Operation 类型选择 External MotionState

- [x] 3.6 `CalcLocalTransform` 中判断是否为外部绑定模式，若是则跳过

- [x] 3.7 `MMDPhysicsManager` 析构函数添加 `m_mmdPhysics` 空指针检查

- [x] 3.8 编写外部绑定单元测试：使用 Mock `IMMDNode` 创建 kinematic / dynamic 刚体，验证 Bullet step 后读写矩阵路径正确



## 4. C4D 插件 — 骨骼 Tag 动画 UI



- [x] 4.1 在 `TMMDBone.h` 中新增动画组枚举值：`PMX_BONE_ANIM_GRP`、`PMX_BONE_ANIM_FRAME_ON`（当前帧号）、`PMX_BONE_ANIM_PREV_BTN`/`NEXT_BTN`/`ADD_BTN`/`DEL_BTN`（导航按钮）、`PMX_BONE_ANIM_CURVE_TYPE`（通道选择）、`PMX_BONE_ANIM_SPLINE`（SplineData）

- [x] 4.2 在 `TMMDBone.res` 中新增 `PMX_BONE_ANIM_GRP` 组的完整描述：帧号 Int、4 个按钮、CYCLE+QUICKTABRADIO 通道选择器（X/Y/Z/R/A）、CUSTOMDATATYPE_SPLINE

- [x] 4.3 在 `MMDBoneTag` 中实现 `SplineDataCallBack` 静态回调（限制切线在 0-127 范围内），参考旧代码 `TMMDBone::SplineDataCallBack`

- [x] 4.4 实现 `InitInterpolator` 方法：初始化 SplineData（范围 0-127，两个锁定端点，贝塞尔插值模式）

- [x] 4.5 在 `SetDParameter` 中为 `PMX_BONE_ANIM_SPLINE` 重新附加 `SplineDataCallBack`

- [x] 4.6 在 `Message`/`SetDParameter` 中处理导航按钮命令（上一个/下一个/添加/删除关键帧），切换 `PMX_BONE_ANIM_FRAME_ON` 并刷新 SplineData 显示

- [x] 4.7 在 `GetDEnabling` 中控制动画组 UI 的可见性与可编辑性：拆开当前“非 EDIT 直接全部禁用”的逻辑，使 **`PMX_BONE_ANIM_GRP`** 及其子参数在 **`BONE_MODE_ANIM`** 下仍可交互，而骨骼结构/PMX 静态参数继续保持编辑模式专属

- [x] 4.8 实现「+」：从骨骼捕获 **相对绑定姿态的当前局部动画结果**（而非直接读取 frozen bind pose）→ 四元数 → 写入内部关键帧表，并创建/更新 `PMX_BONE_ANIM_SPLINE` 与 `PMX_BONE_ANIM_FRAME_ON` 上的 CKey（SDK 2026：`GetMl()` 使用 `ml.sqmat.v1/v2/v3`）

- [x] 4.9 实现「−」：删除当前 VMD 帧关键帧数据并维护 CTrack 一致性（按实现策略）



## 5. C4D 插件 — 骨骼 Tag 数据结构与序列化



- [x] 5.1 在 `MMDBoneTag` 中新增成员：关键帧列表（`maxon::BaseArray<VMDBoneKeyframe>` 或等效）、每帧 4 组 VMDBezier 参数、当前通道选择；**不**新增独立位移/四元数 Tag 参数作为动画真值来源

- [x] 5.2 更新 `MMDBoneTag::Write`：序列化关键帧列表和贝塞尔参数，递增 HyperFile level

- [x] 5.3 更新 `MMDBoneTag::Read`：反序列化关键帧列表和贝塞尔参数，处理旧版本兼容

- [x] 5.4 更新 `MMDBoneTag::CopyTo`（如有）：复制关键帧数据（`SDK2024_CopyTo`：`bone_anim_keys_` / `append_recursion_depth_` 等）



## 6. C4D 插件 — 骨骼 Tag VMD 动画评估



- [x] 6.1 在 `MMDBoneTag::Execute` 的 `BONE_MODE_ANIM` 分支中移除 `mmd_node_->GetLocalTransform()` 读取

- [x] 6.2 实现 VMD 动画评估：获取文档时间 → 转 VMD 帧号（30fps）→ 在关键帧列表中查找前后帧 → 调用 `InterpolateBoneKeys` → 应用坐标转换 → 写入骨骼 **局部动画变换**（`SetRelMl()` 或等价局部矩阵/PRS 路径），保持导入时 frozen bind pose 不被每帧覆盖

- [x] 6.3 实现 SplineData 显示联动：当关键帧或通道类型变化时，从存储的贝塞尔参数更新 SplineData 的切线显示

- [x] 6.4 移除 `mmd_node_` 成员变量及相关的 `ReconnectNodePointers` 接收逻辑（代码已移除；骨骼结果由 Tag 内评估 + `C4DIKChainNodeAdapter` / 物理适配器写回）




## 7. C4D 插件 — 骨骼 Tag 付与逻辑



- [x] 7.1 在 `BONE_MODE_ANIM` 的 Execute 中实现付与旋转：读取 `PMX_BONE_INHERIT_ROTATION` → `FindBone(inherit_index)` → 读源骨骼 tag 的动画旋转 → slerp(identity, source_rot, weight) → 组合到自身旋转

- [x] 7.2 实现付与位移：读取 `PMX_BONE_INHERIT_TRANSLATION` → 读源骨骼 tag 的动画位移偏移 → 乘权重 → 叠加到自身位移

- [x] 7.3 实现 `PMX_BONE_INHERIT_LOCAL` 标志：本地模式使用源骨骼的 `AnimateRotate()`，非本地模式使用源骨骼的 append rotation（若有）

- [x] 7.4 处理付与链递归：确保通过 IK rotate + animate rotate 的组合正确传递（按 PMXNode `UpdateAppendTransform`：付与亲 L / 非 L、`GetAppendRotate`/VMD、`GetIKRotate` 前缀；依赖 `append_recursion_depth` 执行顺序）

- [x] 7.5 PMX 导入或初始化时计算每根骨骼的 `append_recursion_depth`（全局付与深度，同深度可共享优先级数值）



## 8. C4D 插件 — 骨骼 Tag IK 集成



- [x] 8.1 实现 `C4DIKChainNodeAdapter` 类（`IMMDNode` 适配器）：包装 `cinema::BaseObject*` + `MMDBoneTag*`，`SetupFromBone` / 子节点列表 / Eigen 局部/全局缓存

- [x] 8.2 `C4DIKChainNodeAdapter::GetGlobalTransform`/`SetGlobalTransform`：读写 Eigen 缓存（与 MMD 空间一致）

- [x] 8.3 `C4DIKChainNodeAdapter::UpdateGlobalTransform`：栈式 DFS 更新子节点全局变换

- [x] 8.4 `C4DIKChainNodeAdapter::SetIKRotate`/`GetIKRotate`/`AnimateRotate`：通过骨骼 tag / 适配器状态与 libMMD 求解器对接

- [x] 8.5 在 `BONE_MODE_ANIM` 下恢复预物理 IK 到 `MMDBoneTag::Execute`：动画/付与应用后立即执行 `RunIKSolveAnimMode()`，并通过 frame-local skip 标记避免后续 tag 覆盖 IK 链结果；后物理 IK 由 `MMDBoneManagerObject` final phase 触发

- [x] 8.6 IK 开关：tag/BoneManager 触发的 IK 调度受 `is_IK`、solver enable 状态与 target/node 完整性约束（与既有 IK 描述一致）



## 9. C4D 插件 — 骨骼 Tag 执行优先级



- [x] 9.1 骨骼 Tag 与模型管理器 physics Execute 均使用 **`EXECUTIONPRIORITY_EXPRESSION`**（不再使用 ANIMATION/DYNAMICS 类别区分骨骼 Tag）

- [x] 9.2 骨骼 Tag 数值优先级只保留预物理 `deform_layer * 100 + append_depth`；模型管理器 physics step 固定 `5000`；刚体/关节回读分别固定在 `5200/5300`；骨骼管理器 final phase 固定 `6000`

- [ ] 9.3 验证同一 `EXECUTIONPRIORITY_EXPRESSION` 下不同数值是否按递增顺序执行（概念验证样例：付与链 + 物理前/后各一骨）
  - **验证结论**: C4D 的 `EXPRESSION_PRIORITY` 按 `PRIORITYVALUE_PRIORITY` 数值递增全局排序执行，与对象层级无关。`RefreshExecutionPriority` 已正确设置：物理前骨骼 `layer*100+append_depth`（递增顺序保证 append 源先执行）→ ModelManager 物理步 5000 → 物理后骨骼 `6000+layer*100+append_depth`



## 10. C4D 插件 — VMD 骨骼导入



- [x] 10.1 在 `MMDModelManagerObject::LoadVMDMotion` 中新增骨骼导入逻辑：遍历 `vmd_file.m_motions`，按骨骼名分组

- [x] 10.2 对每个匹配的骨骼：将关键帧的位移、四元数（MMD 空间）、`m_interpolation` 解码数据写入骨骼 Tag 内部关键帧列表（不做骨骼对象 PRS CTrack）

- [x] 10.3 将每个关键帧的 `m_interpolation` 字节通过 `SetVMDBezier` 解码为 4 组 VMDBezier，存入骨骼 tag 的关键帧列表

- [x] 10.4 在骨骼 Tag 的 `PMX_BONE_ANIM_SPLINE` 与 `PMX_BONE_ANIM_FRAME_ON` 上创建 CTrack/CKey，作为时间线/F-Curve 标记

- [x] 10.5 收集未匹配的骨骼名到 `LoadVmdMotionLog::not_find_bone_name_list`，在导入报告中展示

- [x] 10.6 移除 `VMDAnimation::Create` + `Add` 的骨骼相关调用（morph 和 IK 的 VMDAnimation 使用已在之前迁移中禁用）（**`Add(vmd, importBoneMotions=false)` 跳过骨骼 NodeController 注册**）；新导入后**不再保留任何原始 VMD 来源数据**



## 11. C4D 插件 — 模型管理器重构



- [x] 11.1 `MMDModelManagerObject::Execute` 的 `MODEL_MODE_ANIM` 分支：移除 `VMDAnimation::Evaluate`/`UpdateAllAnimation` 调用

- [x] 11.2 替换为：在 `MODEL_MODE_ANIM` 下由模型管理器仅执行 physics runtime 初始化、physics UI 参数应用与 physics step，使用 `EXECUTIONPRIORITY_EXPRESSION` 且优先级数值为 `5000`

- [x] 11.3 移除 `mmd_model_` 成员和 `SetMMDModel()`；`MMDModelManagerObject` 改为直接持有 standalone `MMDIKManagerT<MMDIkSolver>`（或等价封装）与 `MMDPhysicsManager`

- [x] 11.4 移除旧 `RebuildRuntime` 系列函数与调用点，替换为独立的运行时初始化辅助逻辑（如 `EnsureStandaloneRuntimeManagers` / `BuildStandaloneIKManager` / `BuildStandalonePhysics`，命名可调整）

- [x] 11.5 standalone IK manager 构建：根据骨骼 Tag 的 IK 描述和 `bone_list_` 创建 `MMDIkSolver`，设置 `IKNode` / `TargetNode` / `IKChain`，并将求解器名称与模型管理器 UI、持久化状态对齐

- [x] 11.6 standalone Physics 构建：刚体/关节构建使用独立 `MMDPhysicsManager` + `C4DIKChainNodeAdapter` 适配器池，通过 `get_node` 回调提供 `IMMDNode*`
  - `MMDRigidManagerObject::RebuildRigidBodies` 签名改为 `(MMDPhysicsManager*, std::function<IMMDNode*(Int32)>)`
  - 从 C4D 对象数据构造 `PMXRigidbody` 并调用 `Create(pmx_rb, node)`

- [x] 11.7 `Execute` 物理步进改用独立 `MMDPhysicsManager`，physics 结果不再直接写回骨骼，而是等待 `MMDRigidObject` / `MMDJointObject` 回读并由 `MMDBoneManagerObject` 在后物理 final phase 统一提交
  - 新增 `physics_manager_own_` / `physics_bone_pool_` / `physics_bone_adapters_` / `physics_dynamic_bone_indices_` 成员
  - 新增 `BuildPhysicsBoneAdapters` / `SyncPhysicsAdaptersFromTags` / `ResetStandalonePhysics` / `StepStandalonePhysics` / `ApplyPhysicsResultsToBoneObjects` 方法
  - `Execute` 中不再调用 `mmd_model_->InitializeAnimation()` / `UpdatePhysicsAnimation()`，改为统一 phase 调度后执行 `ResetStandalonePhysics()` / `StepStandalonePhysics()`，并在帧末统一提交骨骼结果
  - 物理结果：动态刚体骨先通过适配器更新 runtime state，再由模型管理器在统一提交点写回 C4D 骨骼与 Tag 姿态

- [x] 11.8 `BuildIKSolverUI` / `ApplyIKSolverStates` / `ImportVMDIKKeyframes` / `SetDParameter(ID_USERDATA)` 全部改为访问 standalone IK manager，而不是 `mmd_model_->GetIKManager()`

- [x] 11.9 移除 `animations_` / `pending_vmd_data_` 的 bone 来源职责：新导入后不再保存原始 VMD 数据；删除/列表/时间范围改为依赖 bone tag 数据和模型管理器槽元数据；旧格式 `Read` 仅做兼容读取并忽略 bone 播放



## 12. C4D 插件 — 骨骼管理器重构



- [x] 12.1 移除 `MMDBoneManagerObject::mmd_node_manager_` 和 `mmd_morph_manager_` 成员

- [x] 12.2 移除 `ReconnectNodePointers` 方法

- [x] 12.3 移除 `RebuildNodes` 方法（不再需要从 C4D 骨骼反建 PMXNode 树）

- [x] 12.4 确保 `FindBone`/`bone_list_` 仍正常工作，用于付与和 IK 的骨骼查找

- [x] 12.5 调整 `LoadPMX` 初始导入路径：骨骼 Tag 初始化不再写入 `mmd_node_` / `ik_solver_` 运行时指针，骨骼索引与父子关系完全来自 PMX 参数和 C4D 层级

- [x] 12.6 更新 `MMDBoneTag::GetBoneIndex()`（及其调用方）改用 `PMX_BONE_INDEX` / 显式索引缓存，而不是 `mmd_node_->GetIndex()`，避免去掉 `mmd_node_` 后 `FindBoneIndex()`、层级刷新等逻辑失效



## 13. 集成测试与验证



- [ ] 13.1 使用简单模型（3-5 根骨骼，无物理）验证 VMD 导入 → Tag 内部数据 + 标记 CTrack → 骨骼 Tag 评估 → 动画播放

- [ ] 13.2 使用带付与的模型验证付与链评估顺序与结果（优先级 `deform_layer*100+append_depth`）

- [ ] 13.3 使用带 IK 的模型验证 IK 求解通过 `C4DIKChainNodeAdapter`（`IMMDNode`）正确工作

- [ ] 13.4 使用带物理的模型验证执行顺序（EXPRESSION 内 物理前 < 5000 < 物理后）与物理回调

- [ ] 13.5 验证旧场景文件加载不崩溃，提示用户重新导入 VMD

- [ ] 13.6 验证 SplineData UI 正确显示和编辑插值曲线；验证「+」写入关键帧与 CKey



## 14. C4D 插件 — 模式枚举合并与 `MODEL_ANIM_LIST` 多槽



- [x] 14.1 从 `OMMDModelManager` / `OMMDBoneManager` / `OMMDMeshManager` / `OMMDJointManager` / `OMMDRigidManager` 的 `.res`、`.h`、中英 `.str` 中 **移除 `*_MODE_VMD`**，仅保留 `*_MODE_EDIT` 与 `*_MODE_ANIM`；同步 `R20-S24` 与 `S24_up` 镜像资源

- [x] 14.2 `Read`/兼容：`HyperFile` 或参数反序列化若读到旧枚举值 `*_MODE_VMD`，**映射为 `*_MODE_ANIM`**

- [x] 14.3 代码中所有 `*_MODE_VMD` 分支改为 `*_MODE_ANIM`（或与「非 EDIT」等价）；`SetAllBoneMode`、子管理器消息等统一为 `BONE_MODE_ANIM`

- [x] 14.4 **`MODEL_ANIM_LIST`**：将 `animation_index_` 定义为 **活动动画槽**；模型管理器仅保留槽级元数据（名称、最大帧），导入/合并 VMD 时写入对应槽的骨骼 Tag 数据（或模型管理器槽表 + 切换时同步到 Tag）

- [x] 14.5 切换 `MODEL_ANIM_LIST` 时广播活动槽（扩展 `MMDModelManagerObjectMsg` 或下行 `MultiMessage`），`MMDBoneTag` 仅对活动槽关键帧做插值

- [x] 14.6 用当前槽内关键帧时间范围（或槽元数据）设置 `doc->SetMaxTime`/`SetLoopMaxTime`，**移除**对 `VMDAnimation::GetMaxKeyTime()` 的依赖

- [x] 14.7 重构 `SaveVMDMotion()` / `DeleteVMDAnimation()` / `MODEL_ANIM_LIST`：删除与原始 VMD 来源数据的耦合；后续 bone VMD 保存/导出改为从 bone tag 数据和模型管理器槽元数据重建

- [ ] 14.8 验证多槽切换：两段 VMD 导入 → 列表切换 → 骨骼姿态与时间与预期一致


