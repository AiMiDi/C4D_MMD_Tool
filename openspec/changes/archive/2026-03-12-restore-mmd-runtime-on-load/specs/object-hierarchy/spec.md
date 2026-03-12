## MODIFIED Requirements

### Requirement: MMDModelManagerObject Execute 流程

`MMDModelManagerObject::Execute()` 在每帧调用时 SHALL 先检查运行时对象是否已初始化，若未初始化则触发重建流程，然后再执行现有的动画和物理逻辑。

#### Scenario: 首次 Execute 时触发运行时重建

- **WHEN** `Execute()` 被调用且 `is_runtime_initialized_` 为 false 且 `mmd_model_` 为 nullptr
- **THEN** 系统调用 `RebuildRuntime()` 方法重建 PMXModel 及其子管理器
- **THEN** 设置 `is_runtime_initialized_` 为 true
- **THEN** 后续帧不再重复触发重建

#### Scenario: 运行时已存在时跳过重建

- **WHEN** `Execute()` 被调用且 `mmd_model_` 不为 nullptr（如首次导入 PMX 后）
- **THEN** 系统跳过重建逻辑，直接执行现有的动画和物理更新

#### Scenario: Execute 中处理运行时对象的过渡状态

- **WHEN** `Execute()` 被调用且运行时重建尚未完成（`is_runtime_initialized_` 为 false）
- **THEN** 系统 SHALL 安全地跳过依赖 `mmd_model_` 的动画和物理逻辑
- **THEN** 不产生崩溃或异常

## ADDED Requirements

### Requirement: RebuildRuntime 方法

`MMDModelManagerObject` SHALL 提供 `RebuildRuntime()` 方法，负责协调从 C4D 数据重建整个 libmmd 运行时层。

#### Scenario: 完整的运行时重建流程

- **WHEN** `RebuildRuntime()` 被调用
- **THEN** 系统按以下顺序执行：
  1. 创建空的 `PMXModel`
  2. 从骨骼标签重建节点树和 IK 解算器
  3. 从刚体对象重建物理刚体
  4. 从关节对象重建物理关节
  5. 调用 `SetMMDModel()` 分发指针到各子管理器
  6. 重连各子对象的运行时指针
  7. 从暂存的 VMD 二进制数据恢复 `VMDAnimation`

### Requirement: is_runtime_initialized_ 状态标志

`MMDModelManagerObject` SHALL 维护 `is_runtime_initialized_` 标志位，确保运行时重建仅执行一次。

#### Scenario: 标志位在重建后被设置

- **WHEN** `RebuildRuntime()` 完成（无论成功或失败）
- **THEN** `is_runtime_initialized_` 被设置为 true

#### Scenario: 标志位在 Read 后被重置

- **WHEN** `Read()` 方法完成反序列化
- **THEN** `is_runtime_initialized_` 保持默认值 false，以便下次 `Execute()` 触发重建
