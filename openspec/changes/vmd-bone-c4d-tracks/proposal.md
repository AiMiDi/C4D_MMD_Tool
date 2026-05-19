## Why



当前 VMD 模式下，骨骼动画完全由 libMMD 内部驱动：`VMDAnimation::Evaluate()` 每帧向 `MMDNode` 写入位移/旋转 → `PMXModel::UpdateNodeAnimation` 处理付与和 IK → `UpdatePhysicsAnimation` 运行 Bullet 物理 → `MMDBoneTag::Execute` 从 `mmd_node_->GetLocalTransform()` 复制到 C4D 骨骼。用户无法在 C4D 时间线中查看、编辑或微调骨骼关键帧，调试极其困难。延续 `vmd-morph-c4d-tracks` 的思想，将骨骼动画数据迁移到以骨骼 Tag 为中心的时间线与曲线编辑，同时重构 libMMD 中物理、IK、插值算法模块使其可被外部独立使用。



## What Changes



- **骨骼 Tag 动画 UI**：在 `MMDBoneTag` 的描述中新增动画组，包含关键帧导航（帧号 Int + 跳转/添加/删除按钮）、动画插值曲线类型选择器（X/Y/Z/R 通道，CYCLE+QUICKTABRADIO）和 SplineData 插值曲线编辑器（0-127 范围，参考旧代码 `TMMDBone::SplineDataCallBack` 模式）。

- **VMD 导入写入骨骼 Tag 数据**：在 `LoadVMDMotion` 中遍历 `VMDFile::m_motions`，按骨骼名匹配后，将关键帧的位移、四元数旋转与 `m_interpolation` 解码结果写入 **骨骼 Tag 内部有序结构**；同时在 Tag 的 **SplineData** 与 **「下一个关键帧」** 参数上创建 CTrack/CKey，用于时间线与 F-Curve 标记。**不在骨骼对象 position/rotation CTrack 上写入关键帧**。

- **分层播放执行**：`MMDBoneTag` 负责预物理动画/付与评估，并在动画应用后立刻执行预物理 IK；`MMDModelManagerObject` 保留 physics runtime、physics UI 与 physics step；`MMDRigidObject` / `MMDJointObject` 负责从物理世界回读结果；`MMDBoneManagerObject` 负责后物理 final phase 并统一提交骨骼最终姿态。

- **付与逻辑保留在骨骼 Tag**：PMX append transform 仍以 `MMDBoneTag` 为数据与规则承载；预物理时由 tag 自己评估，后物理阶段由 `MMDBoneManagerObject` 基于 physics override 重新评估依赖链。

- **IK 求解回到骨骼 Tag / BoneManager 分层执行**：预物理 IK 在对应 `MMDBoneTag::Execute` 中、紧跟动画与付与之后执行；若 `PMX_BONE_PHYSICS_AFTER_DEFORM` 需要后物理 IK，则由 `MMDBoneManagerObject` 在 final phase 触发。`MMDIkSolver` 继续通过 **`IMMDNode`** 抽象接口操作节点。

- **物理模块独立化**：`MMDRigidBody::Create` 新增不依赖 `MMDModel*`/`MMDNode*` 的重载 `Create(const PMXRigidbody&, IMMDNode*)`，MotionState 通过 `IMMDNode`（与 IK 一致、`GetInitialGlobalTransform` 用于 offset）获取和写入骨骼全局变换，使物理模拟可以直接读写 C4D 骨骼矩阵。

- **VMD 插值算法独立模块**：将 `VMDBezier`、`SetVMDBezier`/`GetVMDBezier`、骨骼关键帧插值逻辑从 `VMDAnimation` 中提取为独立的纯函数算法模块，供 C4D 侧直接调用。

- **执行顺序保证**：骨骼 Tag 与模型管理器在 **`EXECUTIONPRIORITY_EXPRESSION`** 下，用数值区间区分物理前骨骼、物理模拟（固定 5000）、物理后骨骼（见 design D6）；其中骨骼 Tag 在动画模式下不再作为最终写回者，最终骨骼提交由模型管理器统一完成。

- **模式枚举合并**：各管理器上的 **`*_MODE_ANIM` 与 `*_MODE_VMD` 合并为单一 `*_MODE_ANIM`**（保留 `*_MODE_EDIT`）。原「VMD 播放」与「动画播放」统一为同一套骨骼 Tag 内部数据管线；更新 `OMMD*.res` / `*.h` / 字符串表，旧文件中的 `*_MODE_VMD` 读入时映射到 `*_MODE_ANIM`（见 design D9）。

- **`MODEL_ANIM_LIST` 与多段动画**：`MODEL_ANIM_LIST` 表示 **活动动画槽**；每槽对应一次（或合并后的）VMD 导入。骨骼关键帧真值按槽存于各骨骼 Tag，上层仅保留 **槽级元数据**（至少包含显示名、最大帧范围）供列表 UI、删除和文档时间范围使用。切换列表时广播活动槽索引，骨骼 Tag 仅对当前槽做插值；文档时间范围由当前槽关键帧范围或槽元数据计算，不再依赖 `VMDAnimation::GetMaxKeyTime()`（见 design D10）。

- **MMD 骨骼控制层**：在骨骼管理器上提供 `Create/Refresh Controls`，为带 PMX local coordinate 或 fixed axis 的骨骼创建可视化 spline 控制器。控制器与被驱动骨骼同级放置，通过骨骼 Tag 的 `PMX_BONE_CONTROL_LINK` 与骨骼绑定；不使用 C4D Character Builder，不保留旧实验性的平铺 `MMD Controls` 控制器树，也不再按通用骨架白名单创建控制器。控制器只作为编辑/预览/写关键帧工具，VMD 导出仍读取骨骼动画槽数据。

- **模型管理器重构**：`MMDModelManagerObject` 不再持有 `mmd_model_` / `PMXModel`，也不再保留旧的 `RebuildRuntime` 系列路径；改为直接拥有独立的 `MMDIKManager` 与 `MMDPhysicsManager`。`VMDAnimation` 的骨骼求值使用、`MMDNodeManager`、`PMXNode`、`SetMMDModel` 及其相关绑定路径全部移除；`LoadPMX` 和场景恢复都只重建 standalone IK/Physics 运行时。

- **骨骼管理器重构**：`MMDBoneManagerObject` 移除 `mmd_node_manager_` 依赖和 `ReconnectNodePointers`，骨骼查找纯用 `bone_list_`。与此配套，骨骼索引的权威来源也需要从 `mmd_node_->GetIndex()` 切换到 Tag 持久化的 `PMX_BONE_INDEX` / 索引缓存，避免去掉 `mmd_node_` 后 `GetBoneIndex()` 退化为 `-1`。

- **`pending_vmd_data_` 兼容处理**：保留旧场景文件中序列化的 VMD blob 读取能力，但 blob 不再作为骨骼播放真值，且新导入的 VMD **彻底不再保留原始来源数据**。骨骼动画的权威数据只存在于骨骼 Tag 与模型管理器槽元数据中；旧场景加载后如只有 legacy blob，需重新导入 VMD 以恢复骨骼动画数据。



## Capabilities



### New Capabilities

- `bone-c4d-track-animation`：VMD 导入将骨骼关键帧与插值数据写入骨骼 Tag 内部结构，并在 SplineData /「下一个关键帧」上建 CTrack；骨骼 Tag 用 VMD 贝塞尔插值自行评估动画，支持时间线与曲线编辑

- `mmd-bone-controls`：骨骼管理器创建/刷新 PMX local/fixed-axis 骨骼的 spline 控制器，控制器 delta 在骨骼动画评估后、付与/IK/物理前叠加；用户按原骨骼关键帧按钮写入调整后的骨骼动画值并自动归零控制器

- `libmmd-vmd-interpolation-module`：从 VMDAnimation 中独立出的 VMD 贝塞尔插值算法模块，包含 VMDBezier、字节编解码、骨骼/morph 插值纯函数

- `libmmd-immdnode-abstraction`：`MMDIkSolver` 通过 **`IMMDNode`** 抽象接口操作节点；`MMDNode` 实现该接口；C4D 侧提供 `C4DIKChainNodeAdapter`

- `libmmd-physics-external-binding`：MMDRigidBody 的外部绑定机制，通过 `IMMDNode*`（与 IK 共用同一适配器）替代内建 `MMDNode*` 实现 MotionState，使物理模块可独立于 MMDModel 使用



### Modified Capabilities

- `motion-vmd-motion`：骨骼动画播放从 libMMD 内部驱动改为骨骼 Tag 内部数据 + 自行评估；VMD 导入写入 Tag 内部结构与 SplineData/帧号 CTrack；移除 VMDAnimation 的骨骼求值使用

- `motion-vmd-animation-persistence`：**BREAKING** — VMD 骨骼动画数据不再以 VMD blob 形式序列化；关键帧真值经 `MMDBoneTag` HyperFile 与 Tag 上 CTrack 持久化；保留旧格式读取兼容但需重新导入

- `motion-model-runtime-reconstruction`：**BREAKING** — 不再重建完整 PMXModel / `mmd_model_` 运行时；模型管理器改为恢复 standalone `MMDIKManager` 与 `MMDPhysicsManager`；移除 `RebuildRuntime` / `SetMMDModel` / `ReconnectNodePointers`

- `object-physics`：物理模拟流程改为通过 `IMMDNode` 读写 C4D 骨骼变换，不再依赖内建 `MMDNode`；执行顺序在 EXPRESSION 内用数值区分

- `object-ik-solver-control`：IK 求解从 PMXModel 内部移到 C4D 侧统一播放管线中执行；骨骼 Tag 提供链配置与动画评估 helper，模型管理器持有 standalone `MMDIKManager`、统一触发求解并持久化 IK 开关状态



## Impact



- **libMMD 源文件**：`MMDPhysics.h/cpp`（外部 MotionState、`Create(..., IMMDNode*)`、`IMMDNode::GetInitialGlobalTransform`）、`MMDIkSolver.h/cpp`（`IMMDNode`）、`MMDNode.h`（实现接口）、`IMMDNode.h`、`VMDAnimation.h/cpp`（插值算法提取）、新增 `VMDInterpolation.h/cpp`

- **插件源文件**：`mmd_bone.h/cpp`（动画 UI、内部关键帧数据、VMD 评估、付与、IK、控制器 delta 写关键帧）、`mmd_bone_manager.h/cpp`（移除节点管理器依赖，控制器创建/显示模式同步）、`mmd_model_manager.h/cpp`（移除 `mmd_model_`、改为 standalone IK/Physics 管理器、VMD 导入/Execute/运行时初始化重构、控制器同帧刷新）、`utils/mmd_bone_control_util.*`（控制器生成、同步、delta 计算）、`CMTSceneManager.cpp`（日志适配）

- **资源文件**：`TMMDBone.res`/`TMMDBone.h`（新增动画组 UI 描述与 `PMX_BONE_CONTROL_LINK`）；`OMMDBoneManager.res`/`.h`/`.str`（新增 `Create/Refresh Controls` 与 `Controls` 显示模式）；`OMMDModelManager` / `OMMDBoneManager` / `OMMDMeshManager` / `OMMDJointManager` / `OMMDRigidManager` 的 `.res`/`.h`/`.str`（模式枚举合并，去掉 `*_MODE_VMD`）

- **依赖**：libMMD 接口变更，bullet3 无变更

- **兼容性**：已保存的 VMD 模式场景需重新导入 VMD 文件以恢复骨骼动画；旧场景不会崩溃但骨骼动画不自动播放

- **导出说明**：当前 `SaveVMDMotion()` 直接依赖 `animations_` / `VMDAnimation::Save`，这条来源链路应随本提案一起废弃。后续若恢复骨骼 VMD 保存/导出，必须从骨骼 Tag 的关键帧数据和模型管理器槽元数据 **重建 `VMDFile`**，而不是保留或回用原始导入 VMD 数据。

- **测试**：libMMD 的 VMDInterpolation 模块、`IMMDNode` 与 `MMDIkSolver`、物理外部绑定需新增单元测试


