## Why

目前 MMD 模型导入后，没有集中管理 IK 解算器的属性管理器界面。用户无法在运行时启用或禁用 IK 解算（如关闭脚部 IK 以手动调整姿势），只能通过逐个选择骨骼标签来修改 `PMX_BONE_IS_IK` 属性，且该属性在非编辑模式下被禁用。需要在 Model Manager 层级提供统一的 IK 解算器控制界面，将"IK 解算器的运行时激活/禁用"与"骨骼是否为 IK 骨骼的结构属性"分离。

## What Changes

- 在 `MMDModelManagerObject` 的 `MODEL_IK_GRP`（已存在的空分组）中动态添加 IK 解算器列表，每个解算器显示为一个 BOOL 复选框
- 复选框直接控制 `MMDIkSolver::Enable()` / `MMDIkSolver::Enabled()`，不修改骨骼的 `PMX_BONE_IS_IK` 结构属性
- 通过 `mmd_model_->GetIKManager()` 访问所有 IK 解算器，按名称持久化启用状态
- IK 控制在所有模式（Edit/Anim/VMD）下均可操作

## Capabilities

### New Capabilities
- `ik-solver-control`: IK 解算器的集中管理界面——在 Model Manager 的 MODEL_IK_GRP 中为每个 IK 解算器提供启用/禁用复选框，状态通过 `ik_solver_enable_states_` HashMap 按名称持久化

### Modified Capabilities

（无已有 capability 的需求变更）

## Impact

- `refactoring/module/tools/object/mmd_model_manager.h` — 新增枚举值、数据成员、方法声明
- `refactoring/module/tools/object/mmd_model_manager.cpp` — 新增 BuildIKSolverUI、修改 GetDParameter/SetDParameter/GetDEnabling/Read/Write/CopyTo/LoadPMX
- `dependency/libMMD` — 仅使用已有 API（`MMDIKManager`、`MMDIkSolver`），无需修改
- 资源文件 — `MODEL_IK_GRP` 已在 `OMMDModelManager.res/.h/.str` 中定义，无需修改
