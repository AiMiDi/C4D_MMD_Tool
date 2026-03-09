## ADDED Requirements

### Requirement: MMDRigidBody 支持从 C4D 参数创建

`MMDRigidBody` SHALL 支持从 C4D 对象参数（而非 `PMXRigidbody` 结构体）创建，用于场景重载后的运行时重建。

#### Scenario: 通过参数式接口创建刚体

- **WHEN** 运行时重建过程中需要创建 `MMDRigidBody`
- **THEN** 系统可以通过设置形状类型、尺寸、位置、旋转、质量、摩擦力、弹性系数、线性阻尼、角阻尼、物理模式、碰撞组和碰撞掩码等参数来创建有效的 bullet3 刚体
- **THEN** 创建结果等价于从 `PMXRigidbody` 结构体创建

### Requirement: MMDJoint 支持从 C4D 参数创建

`MMDJoint` SHALL 支持从 C4D 对象参数（而非 `PMXJoint` 结构体）创建，用于场景重载后的运行时重建。

#### Scenario: 通过参数式接口创建关节

- **WHEN** 运行时重建过程中需要创建 `MMDJoint`
- **THEN** 系统可以通过设置位置、旋转、位置限制（min/max）、旋转限制（min/max）、弹簧位置常数、弹簧旋转常数和连接的两个刚体引用来创建有效的 bullet3 关节约束
- **THEN** 创建结果等价于从 `PMXJoint` 结构体创建

### Requirement: MMDRigidObject 反向构建接口

`MMDRigidObject` SHALL 提供从其 C4D 参数提取物理属性并填充到 `MMDRigidBody` 的接口，用于运行时重建。

#### Scenario: 从 MMDRigidObject 提取参数并创建 MMDRigidBody

- **WHEN** 系统在运行时重建过程中访问 `MMDRigidObject`
- **THEN** `MMDRigidObject` 从其 C4D BaseContainer 中读取所有物理参数（形状、尺寸、质量、摩擦力、弹性、阻尼、碰撞组等）
- **THEN** 这些参数被用于创建对应的 `MMDRigidBody`
- **THEN** 刚体与绑定的骨骼节点正确关联

### Requirement: MMDJointObject 反向构建接口

`MMDJointObject` SHALL 提供从其 C4D 参数提取关节属性并填充到 `MMDJoint` 的接口，用于运行时重建。

#### Scenario: 从 MMDJointObject 提取参数并创建 MMDJoint

- **WHEN** 系统在运行时重建过程中访问 `MMDJointObject`
- **THEN** `MMDJointObject` 从其 C4D BaseContainer 中读取所有关节参数（位置/旋转限制、弹簧常数、连接的刚体引用等）
- **THEN** 这些参数被用于创建对应的 `MMDJoint`
- **THEN** 关节与连接的两个刚体正确关联
