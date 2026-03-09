## ADDED Requirements

### Requirement: IK 解算器列表展示
系统 SHALL 在 `MMDModelManagerObject` 的 `MODEL_IK_GRP` 分组中，为导入的 PMX 模型中每个 IK 解算器展示一个 BOOL 复选框。复选框的标签 SHALL 使用解算器名称（即 IK 骨骼名称）。

#### Scenario: PMX 模型包含 IK 解算器
- **WHEN** 用户导入一个包含 4 个 IK 解算器（右足IK、左足IK、右つま先IK、左つま先IK）的 PMX 模型
- **THEN** MODEL_IK_GRP 中 SHALL 显示 4 个 BOOL 复选框，分别标记为对应的解算器名称，默认全部启用（勾选）

#### Scenario: PMX 模型不包含 IK 解算器
- **WHEN** 用户导入一个不包含任何 IK 骨骼的 PMX 模型
- **THEN** MODEL_IK_GRP SHALL 为空，不显示任何复选框

### Requirement: IK 解算器启用/禁用控制
用户 SHALL 能够通过 MODEL_IK_GRP 中的 BOOL 复选框启用或禁用对应的 IK 解算器。操作 SHALL 直接调用 `MMDIkSolver::Enable()`，不 SHALL 修改骨骼标签的 `PMX_BONE_IS_IK` 属性。

#### Scenario: 禁用一个 IK 解算器
- **WHEN** 用户取消勾选 "右足IK" 复选框
- **THEN** 对应的 `MMDIkSolver` SHALL 被禁用（`Enabled()` 返回 false），骨骼标签的 `PMX_BONE_IS_IK` 属性 SHALL 保持不变

#### Scenario: 重新启用一个 IK 解算器
- **WHEN** 用户重新勾选之前禁用的 "右足IK" 复选框
- **THEN** 对应的 `MMDIkSolver` SHALL 被启用（`Enabled()` 返回 true）

### Requirement: 全模式可操作
IK 解算器复选框 SHALL 在所有模式（Edit/Anim/VMD）下均可操作，不受 `model_mode_` 的限制。

#### Scenario: 在动画模式下操作 IK 控制
- **WHEN** 当前模式为 Anim 模式，用户切换 IK 解算器复选框
- **THEN** 操作 SHALL 成功执行，复选框状态即时更新

#### Scenario: 在 VMD 模式下操作 IK 控制
- **WHEN** 当前模式为 VMD 模式，用户切换 IK 解算器复选框
- **THEN** 操作 SHALL 成功执行，解算器状态即时生效

### Requirement: IK 解算器状态持久化
系统 SHALL 将 IK 解算器的启用状态按解算器名称持久化到 C4D 场景文件中，使用 `HashMap<String, Bool>` 格式。

#### Scenario: 保存和加载场景
- **WHEN** 用户禁用 "右足IK" 后保存场景，然后重新打开场景
- **THEN** "右足IK" 的复选框 SHALL 显示为未勾选状态

#### Scenario: 重新导入 PMX 后恢复状态
- **WHEN** 场景中已有持久化的 IK 禁用状态，用户重新导入同一 PMX 模型
- **THEN** 系统 SHALL 按名称匹配恢复之前的启用/禁用状态到对应的解算器

#### Scenario: 解算器不可用时的回退
- **WHEN** 场景重新打开但 `mmd_model_` 尚未创建（解算器不存在）
- **THEN** GetDParameter SHALL 从持久化的 `ik_solver_enable_states_` 中返回上次保存的状态

### Requirement: 动态描述类型注册
系统 SHALL 在 `MMDModelRootDynamicDescriptionType` 枚举末尾追加 `IK_SOLVER_ENABLE` 值，确保不改变已有枚举值的序列化数值。

#### Scenario: 枚举值向后兼容
- **WHEN** 打开一个不包含 `IK_SOLVER_ENABLE` 的旧版本场景文件
- **THEN** 已有的动态描述类型（Morph、Display Frame 等）SHALL 正常解析，无数据损坏
