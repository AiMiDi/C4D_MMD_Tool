## Why

当前插件在保存场景后重新打开时，libmmd 运行时层（`PMXModel`、`MMDNode`、`MMDRigidBody`、`MMDJoint`、`MMDIkSolver`、`VMDAnimation`）完全丢失。这些对象仅在首次导入 PMX/VMD 时创建，未参与 Cinema 4D 的 Read/Write 序列化。场景重载后 `mmd_model_` 为 nullptr，导致 VMD 动画回放和物理模拟完全无法工作——用户必须重新导入 PMX 和 VMD 文件才能恢复功能，这是不可接受的。

## What Changes

- 新增场景加载后从已序列化的 C4D 数据（骨骼参数、刚体参数、关节参数）反向重建 `PMXModel` 及其子管理器（`MMDNodeManager`、`MMDPhysicsManager`、`MMDIKManager`）的能力
- 新增 VMD 动画数据的序列化与反序列化支持，使 `animations_` 数组能在 Read/Write 中持久化
- 场景加载后自动重连各子对象的 libmmd 运行时指针（`mmd_node_`、`mmd_rigidbody_`、`mmd_joint_`、`ik_solver_`）
- 用户在编辑模式下对骨骼/刚体/关节属性的修改将反映到重建的 libmmd 对象中

## Capabilities

### New Capabilities

- `model-runtime-reconstruction`: 场景加载后从 C4D 序列化数据重建 PMXModel 运行时对象（节点树、物理管理器、IK 解算器），使动画和物理计算能在场景重载后正常工作
- `vmd-animation-persistence`: VMD 动画数据的序列化与反序列化，使已加载的 VMD 动画在场景保存/重载后保持可用

### Modified Capabilities

- `object-hierarchy`: 各 Manager 对象和子对象需要在 Read 之后执行运行时重建流程，`Execute()` 需要处理运行时对象尚未就绪的过渡状态
- `physics`: 刚体和关节对象需要支持从 C4D 属性反向创建 libmmd 物理对象，并重连指针
- `vmd-motion`: 动画存储和回放流程需要适配序列化后的 VMDAnimation 恢复

## Impact

- **核心文件**: `mmd_model_manager.h/cpp` — 新增重建入口和 VMD 序列化
- **骨骼系统**: `mmd_bone_manager.h/cpp`, `mmd_bone.h/cpp` — 反向创建 MMDNode 和 IK 解算器
- **物理系统**: `mmd_rigid_manager.h/cpp`, `mmd_rigid.h/cpp`, `mmd_joint_manager.h/cpp`, `mmd_joint.h/cpp` — 反向创建刚体和关节
- **libMMD 依赖**: 可能需要为 `PMXModel`/`MMDPhysicsManager` 添加从参数构建（而非从文件解析）的接口
- **序列化兼容性**: Read/Write 的 level 需要递增，确保旧场景文件的向后兼容

---

## Phase 2: C4D 插件端实现改进

基础的运行时重建和 VMD 序列化已实现，以下是对 C4D 插件端实现的补强，覆盖在代码审查中发现的数据丢失风险、边界情况和健壮性问题。

### What Changes (Phase 2)

- 修复 `Write()` 在 `RebuildRuntime()` 执行前（`animations_` 为空）保存场景时 VMD 数据丢失的问题
- 修复 `Execute()` 忽略 `RebuildRuntime()` 返回值导致失败后静默继续的问题
- 修复刚体/关节重建使用子对象遍历顺序（可能与 `RIGID_INDEX` 不一致）的问题
- 将 `is_runtime_initialized_` 改为 `maxon::Synchronized<Bool>` 以保持与其他标志位的一致性
- 在 `RebuildRuntime()` 完成后更新文档的最大时间和循环时间
- 增加 `RebuildRuntime()` 失败时的用户反馈

### Modified Capabilities (Phase 2)

- `vmd-animation-persistence`: Write() 需要在 `animations_` 为空时回退到 `pending_vmd_data_` 序列化，防止 RebuildRuntime 前保存导致数据丢失
- `physics`: 刚体和关节的创建与重连需要按 `RIGID_INDEX` / 创建顺序排序，而非依赖子对象层级遍历顺序
- `object-hierarchy`: `RebuildRuntime()` 失败需要被正确传播和处理

### Impact (Phase 2)

- **核心文件**: `mmd_model_manager.h/cpp` — Write() 回退逻辑、Execute() 错误处理、RebuildRuntime() 后文档时间更新
- **物理系统**: `mmd_rigid_manager.cpp` — 按索引排序重建刚体；`mmd_joint_manager.cpp` — 按顺序重建关节
