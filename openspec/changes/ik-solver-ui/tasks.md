## 1. 头文件声明

- [ ] 1.1 在 `mmd_model_manager.h` 的 `MMDModelRootDynamicDescriptionType` 枚举末尾（`DISPLAY_FRAME_MOVE_DOWN_BUTTON` 之后）追加 `IK_SOLVER_ENABLE`（值 9）
- [ ] 1.2 在 `MMDModelManagerObject` 私有成员区添加 `maxon::HashMap<String, Bool> ik_solver_enable_states_`（位于 `display_frame_items_` 附近）
- [ ] 1.3 在 `MMDModelManagerObject` 的 `private:` 区声明 `void BuildIKSolverUI()`

## 2. BuildIKSolverUI 实现

- [ ] 2.1 在 `mmd_model_manager.cpp` 中实现 `BuildIKSolverUI()`：遍历 `mmd_model_->GetIKManager()`，对每个解算器创建 `DTYPE_BOOL` 动态描述，父级为 `MODEL_IK_GRP`，标签使用 `solver->GetName()`。使用 `ik_solver_enable_states_` 中的持久化状态（默认 true）调用 `solver->Enable()`，然后通过 `AddDynamicDescription(bc, IK_SOLVER_ENABLE, solver_index)` 注册

## 3. LoadPMX 集成

- [ ] 3.1 在 `LoadPMX` 中 `bone_manager_data_->LoadPMX(...)` 成功之后、morph 导入之前调用 `BuildIKSolverUI()`

## 4. GetDParameter 处理

- [ ] 4.1 在 `GetDParameter` 的 switch 默认分支之前，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的 DescID。若 `mmd_model_` 存在则从 `solver->Enabled()` 读取；否则从 `ik_solver_enable_states_` 按名称回退读取

## 5. SetDParameter 处理

- [ ] 5.1 在 `SetDParameter` 的 default 分支中，查找 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的 DescID。调用 `solver->Enable(t_data.GetBool())`，并更新 `ik_solver_enable_states_`（通过 `solver->GetName()` 作为 key）

## 6. GetDEnabling 处理

- [ ] 6.1 在 `GetDEnabling` 中，为 `desc_id_map_` 中 `IK_SOLVER_ENABLE` 类型的 DescID 返回 `true`，确保在所有模式下可操作

## 7. 持久化（Read/Write/CopyTo）

- [ ] 7.1 在 `Write` 方法中 `display_frame_list_` 序列化之后，追加 `io_util::WriteHashMap(hf, ik_solver_enable_states_)`
- [ ] 7.2 在 `Read` 方法中 `level >= 2` 分支中 `display_frame_list_` 反序列化之后，追加 `io_util::ReadHashMap(hf, ik_solver_enable_states_)`
- [ ] 7.3 在 `CopyTo` 方法中 `display_frame_list_` 复制之后，追加 `destObject->ik_solver_enable_states_.CopyFrom(ik_solver_enable_states_)`
