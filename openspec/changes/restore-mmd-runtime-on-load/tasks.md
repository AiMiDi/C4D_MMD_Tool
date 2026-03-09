## 1. libmmd 接口扩展 — 参数式构建支持

- [ ] 1.1 为 `MMDRigidBody` 添加参数式 `Create` 重载：接收形状、尺寸、位置、旋转、质量、摩擦力、弹性系数、阻尼、物理模式、碰撞组/掩码等独立参数（而非 `PMXRigidbody` 结构体），创建 bullet3 刚体。添加单元测试验证参数式创建与 `PMXRigidbody` 结构体创建的等价性。
- [ ] 1.2 为 `MMDJoint` 添加参数式 `Create` 重载：接收位置、旋转、位置限制、旋转限制、弹簧常数和两个 `MMDRigidBody*` 引用等独立参数，创建 bullet3 关节约束。添加单元测试验证等价性。
- [ ] 1.3 验证 `PMXNode` 现有的属性设置接口完备性：确认 `SetName`、`SetTranslate`、`SetDeformDepth`、`EnableDeformAfterPhysics`、`SetAppendNode`、`EnableAppendRotate`/`Translate`/`Local`、`SetAppendWeight`、`SetIKSolver` 和 `MMDNode::AddChild` 等已有接口足以从参数重建节点。如有缺失则补充。
- [ ] 1.4 验证 `MMDIkSolver` 的构建接口完备性：确认可以从参数设置 IK 目标骨骼、链长度、迭代次数和角度限制。如有缺失则补充（如 `SetTarget`、`SetIterateCount`、`SetLimitAngle`、`AddChain` 等）。

## 2. 插件端反向构建接口

- [ ] 2.1 在 `MMDBoneManagerObject` 中添加 `RebuildNodes(PMXModel*)` 方法：遍历 `bone_list_` 中所有骨骼标签，读取各标签参数，调用 `PMXNode::AddNode()` 及属性设置接口构建节点树。建立父子关系（`AddChild`）、设置 deform depth 和 append 属性。
- [ ] 2.2 在 `MMDBoneManagerObject::RebuildNodes` 中重建 IK 解算器：遍历包含 IK 配置的骨骼标签，调用 `MMDIKManagerT::AddIKSolver()` 创建 `MMDIkSolver` 并设置参数，通过 `PMXNode::SetIKSolver()` 关联到对应节点。
- [ ] 2.3 在 `MMDRigidManagerObject` 中添加 `RebuildRigidBodies(MMDPhysicsManager*, MMDNodeManager*)` 方法：遍历所有 `MMDRigidObject` 子对象，读取 C4D 参数，调用 `MMDPhysicsManager::AddRigidBody()` 并通过 1.1 的参数式接口创建 `MMDRigidBody`。
- [ ] 2.4 在 `MMDJointManagerObject` 中添加 `RebuildJoints(MMDPhysicsManager*)` 方法：遍历所有 `MMDJointObject` 子对象，读取 C4D 参数，调用 `MMDPhysicsManager::AddJoint()` 并通过 1.2 的参数式接口创建 `MMDJoint`。
- [ ] 2.5 在 `MMDRigidObject` 中添加 `PopulateRigidBodyParams()` 辅助方法：从 BaseContainer 提取形状、尺寸、质量等物理属性，返回结构化参数供 `RebuildRigidBodies` 使用。
- [ ] 2.6 在 `MMDJointObject` 中添加 `PopulateJointParams()` 辅助方法：从 BaseContainer 提取关节限制、弹簧等参数，返回结构化参数供 `RebuildJoints` 使用。

## 3. VMD 动画序列化

- [ ] 3.1 在 `MMDModelManagerObject::Write()` 中添加 VMD 动画序列化逻辑：遍历 `animations_` 数组，对每个条目写入动画名称和通过 `VMDAnimation::Save(VMDFile&)` + `WriteVMDFile()` 转换的 VMD 二进制数据到 HyperFile。递增 Write level。
- [ ] 3.2 在 `MMDModelManagerObject::Read()` 中添加 VMD 动画反序列化逻辑：在新 level 条件下，读取动画数量和每个条目的名称与 VMD 二进制数据，暂存到 `pending_vmd_data_` 成员变量（类型：`maxon::BaseArray<std::pair<String, std::vector<uint8_t>>>`）。
- [ ] 3.3 在 `MMDModelManagerObject` 中添加 `pending_vmd_data_` 成员变量声明，以及 `animation_index_` 的序列化/反序列化（在 Write/Read 中添加）。
- [ ] 3.4 在 `MMDModelManagerObject::CopyTo()` 中添加 `animations_` 的复制逻辑：对每个 `VMDAnimation` 通过 Save → ReadVMDFile → Create + Add 进行深拷贝。

## 4. 运行时重建核心

- [ ] 4.1 在 `MMDModelManagerObject` 中添加 `is_runtime_initialized_` 成员变量（默认 false），以及 `RebuildRuntime()` 方法声明。
- [ ] 4.2 实现 `RebuildRuntime()` 方法：创建空 `PMXModel` → 调用 `bone_manager_data_->RebuildNodes()` → 调用 `rigid_manager_data_->RebuildRigidBodies()` → 调用 `joint_manager_data_->RebuildJoints()` → 调用 `SetMMDModel()` → 恢复 VMD 动画 → 释放 `pending_vmd_data_`。
- [ ] 4.3 修改 `Execute()` 方法：在 `UpdateManagers()` 之后添加 `if (!is_runtime_initialized_ && !mmd_model_)` 条件判断，调用 `RebuildRuntime()` 并设置 `is_runtime_initialized_ = true`。

## 5. 子对象指针重连

- [ ] 5.1 在 `MMDBoneManagerObject` 中添加 `ReconnectNodePointers(MMDNodeManager*, MMDIKManager*)` 方法：遍历所有骨骼标签，通过索引或名称匹配将 `MMDBoneTag::mmd_node_` 和 `MMDBoneTag::ik_solver_` 重新指向重建后的 libmmd 对象。
- [ ] 5.2 在 `MMDRigidManagerObject` 中添加 `ReconnectRigidBodyPointers(MMDPhysicsManager*)` 方法：遍历所有 `MMDRigidObject`，将 `mmd_rigidbody_` 重新指向重建后的 `MMDRigidBody`。
- [ ] 5.3 在 `MMDJointManagerObject` 中添加 `ReconnectJointPointers(MMDPhysicsManager*)` 方法：遍历所有 `MMDJointObject`，将 `mmd_joint_` 重新指向重建后的 `MMDJoint`。
- [ ] 5.4 在 `RebuildRuntime()` 的末尾调用三个 Reconnect 方法，确保所有子对象指针在重建完成后被正确设置。

## 6. 测试与验证

- [ ] 6.1 为 libmmd 的 `MMDRigidBody` 参数式 `Create` 添加单元测试：验证从参数创建的刚体与从 `PMXRigidbody` 创建的刚体具有相同的物理属性。
- [ ] 6.2 为 libmmd 的 `MMDJoint` 参数式 `Create` 添加单元测试：验证从参数创建的关节与从 `PMXJoint` 创建的关节具有相同的约束属性。
- [ ] 6.3 编写 PMX 导入 → C4D 参数 → 运行时重建的往返测试描述：验证导入后保存/重载场景后，重建的 `PMXModel` 节点数量、物理对象数量和动画数据与原始导入一致。
- [ ] 6.4 编写 VMD 序列化往返测试描述：验证 VMD 动画保存到 HyperFile 后重新读取，恢复的动画关键帧数量和最大帧时间与原始一致。
