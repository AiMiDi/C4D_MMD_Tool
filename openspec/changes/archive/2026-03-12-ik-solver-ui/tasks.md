## 1. 头文件声明

- [x] 1.1 在 `mmd_model_manager.h` 的 `MMDModelRootDynamicDescriptionType` 枚举末尾（`DISPLAY_FRAME_MOVE_DOWN_BUTTON` 之后）追加 `IK_SOLVER_ENABLE`（值 9）
- [x] 1.2 在 `MMDModelManagerObject` 私有成员区添加 `maxon::HashMap<String, Bool> ik_solver_enable_states_`（位于 `display_frame_items_` 附近）
- [x] 1.3 在 `MMDModelManagerObject` 的 `private:` 区声明 `void BuildIKSolverUI()` 和 `void ApplyIKSolverStates()`

## 2. ApplyIKSolverStates 实现

- [x] 2.1 在 `mmd_model_manager.cpp` 中实现 `ApplyIKSolverStates()`：检查 `mmd_model_` 是否存在，遍历 `ik_solver_enable_states_`，对每个条目通过 `mmd_model_->GetIKManager()->GetMMDIKSolver(name)` 查找解算器，找到则调用 `solver->Enable(state)`，未找到则忽略

## 3. BuildIKSolverUI 实现

- [x] 3.1 在 `mmd_model_manager.cpp` 中实现 `BuildIKSolverUI()`：遍历 `mmd_model_->GetIKManager()`，对每个解算器创建 `DTYPE_BOOL` 动态描述，父级为 `MODEL_IK_GRP`，标签使用 `solver->GetName()`。在 `ik_solver_enable_states_` 中查找持久化状态（默认 true），通过 `AddDynamicDescription(bc, IK_SOLVER_ENABLE, solver_index)` 注册。全部注册完成后调用 `ApplyIKSolverStates()` 恢复状态

## 4. LoadPMX 集成

- [x] 4.1 在 `LoadPMX` 中 `bone_manager_data_->LoadPMX(...)` 成功之后、morph 导入之前调用 `BuildIKSolverUI()`

## 5. RebuildRuntime 集成

- [x] 5.1 在 `RebuildRuntime` 中 `SetMMDModel(pmx_model)` 之后、`ReconnectNodePointers` 之前调用 `ApplyIKSolverStates()`

## 6. GetDParameter 处理

- [x] 6.1 在 `GetDParameter` 的第一个 switch 的 `default` 分支后（material 处理之前），检查 `id[0].id == ID_USERDATA`，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的条目。若 `mmd_model_` 存在，通过 index 获取解算器并从 `solver->Enabled()` 读取，设置 `t_data.SetBool()` 并返回 true；否则回退到 SUPER 返回 C4D 存储的用户数据值

## 7. SetDParameter 处理

- [x] 7.1 在 `SetDParameter` 的 `default` 分支中（material 处理之前），检查 `id[0].id == ID_USERDATA`，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的条目。若 `mmd_model_` 存在，通过 index 获取解算器并调用 `solver->Enable(t_data.GetBool())`，同时以 `solver->GetName()` 为 key 更新 `ik_solver_enable_states_`。标记 `DESCFLAGS_SET::PARAM_SET` 并返回 true

## 8. GetDEnabling 处理

- [x] 8.1 在 `GetDEnabling` 的 switch 之前，检查 `id[0].id == ID_USERDATA`，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的条目，若匹配则返回 `true`（确保在所有模式下可操作）

## 9. 持久化（Read/Write/CopyTo）

- [x] 9.1 在 `Write` 方法中 `display_frame_list_` 序列化之后、animations 序列化之前，追加 `io_util::WriteHashMap(hf, ik_solver_enable_states_)`
- [x] 9.2 在 `Read` 方法中 `display_frame_list_` 反序列化之后、animations 反序列化之前，追加 `io_util::ReadHashMap(hf, ik_solver_enable_states_)`
- [x] 9.3 在 `CopyTo` 方法中 `display_frame_list_` 复制之后，追加 `destObject->ik_solver_enable_states_.CopyFrom(ik_solver_enable_states_)`

## 10. libMMD VMDAnimation IK 控制开关

- [x] 10.1 在 `VMDAnimation` 类中添加 `bool m_applyIKEnable = true` 私有成员
- [x] 10.2 添加 `void SetApplyIKEnable(bool apply)` 和 `bool GetApplyIKEnable() const` 公有方法
- [x] 10.3 修改 `VMDAnimation::Evaluate`，当 `m_applyIKEnable` 为 false 时跳过 `m_ikControllers` 循环

## 11. VMD IK 关键帧导入

- [x] 11.1 在 `mmd_model_manager.h` 中声明 `void ImportVMDIKKeyframes(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting)`
- [x] 11.2 在 `mmd_model_manager.cpp` 中实现 `ImportVMDIKKeyframes`：遍历 `vmd_file.m_iks`，对每个 `VMDIkInfo` 按名称在 `desc_id_map_` 中查找 `IK_SOLVER_ENABLE` 条目对应的 DescID，创建或查找 CTrack，添加 CKey（step 插值），值为 `ikInfo.m_enable`
- [x] 11.3 在 `LoadVMDMotion` 中 `vmd_animation->Add(vmd_file)` 之后，调用 `ImportVMDIKKeyframes(vmd_file, setting)`，并调用 `vmd_animation->SetApplyIKEnable(false)`

## 12. Execute VMD 模式 IK 状态同步

- [x] 12.1 在 `Execute` 的 VMD 模式中，`SyncPhysics` 和 `UpdateAllAnimation` 之前，遍历 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 条目，通过 `op->GetParameter` 读取当前帧的关键帧值，调用 `mmd_model_->GetIKManager()->GetMMDIKSolver(index)->Enable(value)` 同步到 solver
