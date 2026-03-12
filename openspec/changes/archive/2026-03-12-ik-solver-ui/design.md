## Context

当前 `MMDModelManagerObject` 的 `MODEL_IK_GRP` 分组已在资源文件中定义但内容为空。IK 解算器（`MMDIkSolver`）由 `libmmd::MMDModel::GetIKManager()` 管理，每个 IK 骨骼对应一个解算器实例。解算器提供 `Enable(bool)` / `Enabled()` 接口控制运行时开关。

现有代码中，`PMX_BONE_IS_IK`（骨骼标签属性）同时承担结构定义和运行时控制两个职责。骨骼标签的 `GetDEnabling` 在非编辑模式下禁用所有参数，导致用户无法在动画模式下切换 IK。

`desc_id_map_`（`HashMap<DescID, Pair<MMDModelRootDynamicDescriptionType, Int>>`）已用于 Morph 和 Display Frame 的动态描述管理，并通过 `io_util::ReadHashMap/WriteHashMap` 自动持久化。

`mmd_model_` 的生命周期：首次导入时由 `LoadPMX` 设置；场景重新打开后为 null，直到 `RebuildRuntime` 在 `Execute` 中被调用，重新创建 `PMXModel` 并通过 `SetMMDModel` 赋值。IK 解算器在 `RebuildNodes`（Pass 4）中根据骨骼标签的 `PMX_BONE_IS_IK` 属性重建。

当前 `Read`/`Write` 序列化顺序为：links → morph_named_number → desc_id_map → morph_name → morph_data → materials → display_frames → animations。插件尚未发布，无需考虑旧版文件兼容。

## Goals / Non-Goals

**Goals:**
- 在 Model Manager 属性面板中集中展示所有 IK 解算器，提供启用/禁用复选框
- 直接操作 `MMDIkSolver::Enable()`，不修改骨骼的 `PMX_BONE_IS_IK` 结构属性
- IK 控制在所有模式（Edit/Anim/VMD）下均可操作
- 解算器启用状态跨会话持久化（按名称匹配）
- 场景重新打开后 `RebuildRuntime` 自动从持久化状态恢复解算器启用设置

**Non-Goals:**
- 不改造骨骼标签的 IK 属性编辑逻辑
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

### 4. GetDParameter/SetDParameter 通过 ID_USERDATA 拦截动态描述

**选择**：在 `GetDParameter`/`SetDParameter` 的 `default` 分支中（material 处理之前），检查 `id[0].id == ID_USERDATA`，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的条目进行拦截。`mmd_model_` 存在时从解算器实时读取/写入；不存在时从 `ik_solver_enable_states_` 回退读取/写入。

**理由**：
- 动态描述的 DescID 第一级始终是 `ID_USERDATA`，当前 switch 按 `id[0].id` 分发，会落入 `default` 分支
- Morph 滑块不需要自定义 GetDParameter（值存储在 C4D 用户数据中），但 IK 解算器的真实状态在 solver 对象上，需要显式拦截
- `mmd_model_` 仅在 PMX 导入后或 `RebuildRuntime` 后存在，null 时回退到持久化 HashMap 保证 UI 正确显示

### 5. 分离 UI 构建与状态恢复

**选择**：将 IK 解算器管理拆分为 `BuildIKSolverUI()`（创建动态描述 + 恢复状态）和 `ApplyIKSolverStates()`（仅将持久化状态应用到解算器）。

**理由**：
- `LoadPMX`（首次导入）：需要创建动态描述 UI 并应用持久化状态 → 调用 `BuildIKSolverUI()`
- `RebuildRuntime`（场景重新打开）：动态描述已由 C4D 从文件恢复，不需要重新创建，只需将 `ik_solver_enable_states_` 应用到新创建的解算器 → 调用 `ApplyIKSolverStates()`
- `BuildIKSolverUI` 内部调用 `ApplyIKSolverStates` 来复用逻辑

**替代方案**：统一调用 `BuildIKSolverUI`，在其中检查动态描述是否已存在来决定是否跳过创建。但这增加了复杂度，且 C4D 不提供高效的"检查动态描述是否已存在"接口。

### 6. 序列化放在 display_frames 之后

**选择**：将 `ik_solver_enable_states_` 的序列化放在 `display_frame_list_` 之后、animations 之前。

**理由**：
- 插件尚未发布，无需考虑旧版文件兼容，可以自由调整序列化顺序
- `ik_solver_enable_states_` 与 display_frames 同属模型结构数据，放在一起逻辑上更合理
- animations 是可变长的大块数据，放在最后便于维护

### 7. VMD IK 关键帧导入为 C4D 参数关键帧，libMMD 让出控制权

**选择**：在 `VMDAnimation` 中新增 `SetApplyIKEnable(bool)` 开关。关闭后 `Evaluate` 跳过 IK 控制器循环。VMD 导入时读取 `VMDFile::m_iks`，按名称匹配找到 IK 复选框的 DescID，创建 CTrack + CKey（step 插值），并设置 `SetApplyIKEnable(false)`。

**理由**：
- VMD 的 IK 启用关键帧是步进式的（某帧启用/禁用），映射到 C4D 的 BOOL 参数关键帧（step interpolation）语义完全匹配
- 将 IK 启用控制交给 C4D 动画系统后，用户可在时间线上直接查看和编辑 IK 启用状态，符合 C4D 工作流
- libMMD 的 `VMDIKController::Evaluate` 会在每帧强制设置 solver 状态，与 C4D 关键帧冲突，必须关闭
- `Execute` 中 VMD 模式下需要额外步骤：从 C4D 参数读取当前关键帧值并应用到 solver

**替代方案**：不修改 libMMD，在 Execute 中覆盖 solver 状态。但 `Evaluate` 设置的值会在同一帧被覆盖，逻辑冗余且存在时序隐患。

### 8. VMD 模式 Execute 中同步 C4D 参数到 solver

**选择**：在 `Execute` 的 VMD 模式中，`UpdateAllAnimation` 之后遍历 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 条目，通过 `op->GetParameter` 读取当前关键帧值，应用到对应 solver。

**理由**：
- C4D 的关键帧评估在 `GetParameter` 时自动完成，返回当前帧的插值结果
- 此时 `VMDAnimation::Evaluate` 已跳过 IK 控制器（因为 `SetApplyIKEnable(false)`），solver 状态未被 VMD 修改
- 从 C4D 参数读取后立即应用，确保后续的 `UpdateNodeAnimation` 使用正确的 IK 状态

## Risks / Trade-offs

- **解算器生命周期受限** → `mmd_model_` 在场景重新打开后为 null，解算器不存在。此时 UI 仅反映持久化状态，实际 IK 解算不运行。`RebuildRuntime` 完成后状态自动恢复。这是现有架构的限制（VMD 模式同样依赖 `mmd_model_`），后续可通过场景级模型重建解决。
- **名称冲突** → 理论上不同骨骼可能同名。PMX 规范中骨骼名称通常唯一，实际冲突概率极低。如遇冲突，后者覆盖前者状态。
- **枚举值序列化** → `IK_SOLVER_ENABLE` 追加在枚举末尾。发布前不存在兼容性问题，但发布后修改枚举值顺序会导致已有 `desc_id_map_` 数据类型错位。
- **VMD IK 关键帧与手动编辑冲突** → VMD 导入后 IK 复选框有关键帧，用户手动修改会与关键帧冲突。这是 C4D 标准行为，用户可删除关键帧后自行控制。
