## Context

当前 `MMDModelManagerObject` 的 `MODEL_IK_GRP` 分组已在资源文件中定义但内容为空。IK 解算器（`MMDIkSolver`）由 `libmmd::MMDModel::GetIKManager()` 管理，每个 IK 骨骼对应一个解算器实例。解算器提供 `Enable(bool)` / `Enabled()` 接口控制运行时开关。

现有代码中，`PMX_BONE_IS_IK`（骨骼标签属性）同时承担结构定义和运行时控制两个职责。骨骼标签的 `GetDEnabling` 在非编辑模式下禁用所有参数，导致用户无法在动画模式下切换 IK。

`desc_id_map_`（`HashMap<DescID, Pair<MMDModelRootDynamicDescriptionType, Int>>`）已用于 Morph 和 Display Frame 的动态描述管理，并通过 `io_util::ReadHashMap/WriteHashMap` 自动持久化。

## Goals / Non-Goals

**Goals:**
- 在 Model Manager 属性面板中集中展示所有 IK 解算器，提供启用/禁用复选框
- 直接操作 `MMDIkSolver::Enable()`，不修改骨骼的 `PMX_BONE_IS_IK` 结构属性
- IK 控制在所有模式（Edit/Anim/VMD）下均可操作
- 解算器启用状态跨会话持久化（按名称匹配）

**Non-Goals:**
- 不改造骨骼标签的 IK 属性编辑逻辑
- 不实现 VMD IK 控制器关键帧的导入/导出（已注释代码，后续独立处理）
- 不修改 libMMD 的 `MMDIkSolver` API

## Decisions

### 1. 通过 IKManager 访问解算器，而非通过骨骼标签

**选择**：使用 `mmd_model_->GetIKManager()` 遍历所有 IK 解算器。

**理由**：
- Model Manager 已持有 `mmd_model_`，可直接访问 `MMDIKManager`
- 避免依赖骨骼标签的私有成员 `ik_solver_`（需要 friend 或公开接口）
- `MMDIKManager` 提供按索引和按名称的查找接口，API 完备

**替代方案**：通过 `bone_manager_data_->FindBone()` 获取骨骼标签再访问 `ik_solver_`。但这需要扩展 `MMDBoneTag` 的公开接口或增加 friend 关系，耦合度更高。

### 2. 按解算器名称持久化启用状态

**选择**：使用 `HashMap<String, Bool> ik_solver_enable_states_` 存储，key 为解算器名称。

**理由**：
- 解算器名称与骨骼名称一致，具有语义唯一性
- 重新导入模型时骨骼索引可能变化，按名称匹配更稳健
- HashMap 可直接复用 `io_util::ReadHashMap/WriteHashMap` 进行序列化

**替代方案**：按索引持久化。但模型修改后索引不稳定，状态恢复可能错误。

### 3. 使用动态描述（DynamicDescription）构建 UI

**选择**：在 `LoadPMX` 后通过 `AddDynamicDescription` 为每个解算器添加 `DTYPE_BOOL` 参数。

**理由**：
- 与现有 Morph 和 Display Frame 的动态 UI 模式一致
- `desc_id_map_` 已有完善的持久化和类型分发机制
- 新增 `IK_SOLVER_ENABLE` 枚举值（追加在末尾，值 9）不影响已有序列化

### 4. GetDParameter 优先从解算器读取，回退到持久化状态

**选择**：`mmd_model_` 存在时从解算器实时读取 `Enabled()` 状态；不存在时从 `ik_solver_enable_states_` 读取。

**理由**：
- `mmd_model_` 仅在 PMX 导入后存在，场景重新打开后为 null
- 持久化的 HashMap 保证场景重新打开后 UI 仍显示上次状态
- 重新导入 PMX 时，`BuildIKSolverUI` 从 HashMap 恢复状态到新解算器

## Risks / Trade-offs

- **解算器生命周期受限** → `mmd_model_` 在场景重新打开后为 null，解算器不存在。此时 UI 仅反映持久化状态，实际 IK 解算不运行。用户重新导入 PMX 后状态自动恢复。这是现有架构的限制（VMD 模式同样依赖 `mmd_model_`），后续可通过场景级模型重建解决。
- **名称冲突** → 理论上不同骨骼可能同名。PMX 规范中骨骼名称通常唯一，实际冲突概率极低。如遇冲突，后者覆盖前者状态。
- **枚举值序列化** → `IK_SOLVER_ENABLE` 必须追加在枚举末尾以保持向后兼容。若插入中间会导致已有 `desc_id_map_` 数据类型错位。
