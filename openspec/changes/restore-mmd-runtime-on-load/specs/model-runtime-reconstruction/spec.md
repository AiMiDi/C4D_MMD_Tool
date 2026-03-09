## ADDED Requirements

### Requirement: 场景加载后自动重建 PMXModel 运行时对象

当场景文件被打开且 `mmd_model_` 为 nullptr 时，系统 SHALL 从 C4D 已序列化的子对象数据自动重建完整的 `libmmd::PMXModel` 运行时对象，包括节点树（`MMDNodeManager`）、物理管理器（`MMDPhysicsManager`）和 IK 解算器（`MMDIKManager`）。

#### Scenario: 正常场景重载后运行时重建

- **WHEN** 用户打开一个包含 `MMDModelManagerObject` 的已保存场景文件
- **THEN** 系统在首次 `Execute()` 调用时检测到 `mmd_model_` 为 nullptr，自动触发运行时重建
- **THEN** 重建后 `mmd_model_` 不为 nullptr，`GetNodeManager()`、`GetPhysicsManager()`、`GetIKManager()` 均返回有效指针

#### Scenario: 重建失败时的降级处理

- **WHEN** 运行时重建过程中发生错误（如子对象数据不完整）
- **THEN** 系统 SHALL 将 `is_runtime_initialized_` 设置为 true 以防止反复重试
- **THEN** 插件仍可在编辑模式下正常工作，仅动画和物理功能不可用

### Requirement: 从骨骼标签重建节点树

系统 SHALL 遍历 `MMDBoneManagerObject` 的 `bone_list_` 中的所有骨骼标签，为每个骨骼创建对应的 `PMXNode`，并正确设置节点的名称、初始位置、父子关系、deform depth、append 属性和 IK 解算器。

#### Scenario: 骨骼节点属性正确重建

- **WHEN** 场景中存在带有 `MMDBoneTag` 的骨骼关节对象
- **THEN** 系统为每个骨骼标签创建一个 `PMXNode`
- **THEN** 每个 `PMXNode` 的名称、初始位置（`SetTranslate`）与对应的 C4D 骨骼标签参数一致
- **THEN** 父子关系通过 `AddChild()` 正确建立
- **THEN** deform depth、append rotate/translate/local/weight 等属性从骨骼标签参数正确设置

#### Scenario: IK 解算器重建

- **WHEN** 骨骼标签包含 IK 配置参数（目标骨骼、链长度、迭代次数、角度限制）
- **THEN** 系统为该骨骼创建 `MMDIkSolver` 并正确设置 IK 链、迭代次数和角度限制
- **THEN** `PMXNode::SetIKSolver()` 将 IK 解算器关联到对应的节点

### Requirement: 从刚体对象重建物理刚体

系统 SHALL 遍历 `MMDRigidManagerObject` 的子对象中的所有 `MMDRigidObject`，为每个刚体对象在 `MMDPhysicsManager` 中创建对应的 `MMDRigidBody`。

#### Scenario: 刚体属性正确重建

- **WHEN** 场景中存在 `MMDRigidObject` 子对象
- **THEN** 系统为每个 `MMDRigidObject` 调用 `MMDPhysicsManager::AddRigidBody()` 创建 `MMDRigidBody`
- **THEN** 刚体的形状、尺寸、质量、摩擦力、弹性系数、阻尼、碰撞组等属性从 C4D 对象参数正确设置
- **THEN** 刚体与对应的 `PMXNode` 正确绑定

### Requirement: 从关节对象重建物理关节

系统 SHALL 遍历 `MMDJointManagerObject` 的子对象中的所有 `MMDJointObject`，为每个关节对象在 `MMDPhysicsManager` 中创建对应的 `MMDJoint`。

#### Scenario: 关节属性正确重建

- **WHEN** 场景中存在 `MMDJointObject` 子对象
- **THEN** 系统为每个 `MMDJointObject` 调用 `MMDPhysicsManager::AddJoint()` 创建 `MMDJoint`
- **THEN** 关节的位置/旋转限制、弹簧常数、连接的两个刚体引用等属性从 C4D 对象参数正确设置

### Requirement: 重建后重连子对象运行时指针

系统 SHALL 在 `PMXModel` 重建完成后，将各子对象（`MMDBoneTag`、`MMDRigidObject`、`MMDJointObject`）的 libmmd 运行时指针（`mmd_node_`、`mmd_rigidbody_`、`mmd_joint_`）重新连接到新创建的对象。

#### Scenario: 骨骼标签指针重连

- **WHEN** `PMXModel` 重建完成
- **THEN** 每个 `MMDBoneTag` 的 `mmd_node_` 指向重建后的 `PMXNode`
- **THEN** 包含 IK 配置的骨骼标签的 `ik_solver_` 指向重建后的 `MMDIkSolver`

#### Scenario: 刚体对象指针重连

- **WHEN** `PMXModel` 重建完成
- **THEN** 每个 `MMDRigidObject` 的 `mmd_rigidbody_` 指向重建后的 `MMDRigidBody`

#### Scenario: 关节对象指针重连

- **WHEN** `PMXModel` 重建完成
- **THEN** 每个 `MMDJointObject` 的 `mmd_joint_` 指向重建后的 `MMDJoint`

### Requirement: 编辑模式修改反映到运行时对象

用户在编辑模式下对骨骼/刚体/关节属性的修改 SHALL 在切换到动画或 VMD 模式时自动反映到 libmmd 运行时对象中。

#### Scenario: 编辑骨骼位置后影响动画

- **WHEN** 用户在编辑模式下修改骨骼的位置参数
- **WHEN** 用户切换到 VMD 模式
- **THEN** 对应的 `PMXNode` 的初始位置与修改后的 C4D 骨骼参数一致
- **THEN** VMD 动画使用更新后的初始位置进行计算

#### Scenario: 编辑刚体参数后影响物理

- **WHEN** 用户在编辑模式下修改刚体的质量或阻尼参数
- **WHEN** 用户切换到动画或 VMD 模式
- **THEN** 对应的 `MMDRigidBody` 使用更新后的参数进行物理模拟
