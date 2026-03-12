## Context

当前插件的数据架构分为两层：

1. **C4D 持久层**：通过 `Read`/`Write` 保存到场景文件的数据（骨骼标签参数、刚体对象参数、关节对象参数、morph 数据、材质数据、显示帧数据）
2. **libmmd 运行时层**：仅在内存中存在的 libmmd 对象（`PMXModel`、`MMDNode`、`MMDRigidBody`、`MMDJoint`、`MMDIkSolver`、`VMDAnimation`）

场景保存时只有第 1 层被持久化。场景重新打开后，第 2 层完全丢失，导致：
- `mmd_model_` 为 nullptr → VMD 动画和物理模拟无法执行
- 各子对象的 libmmd 指针（`mmd_node_`、`mmd_rigidbody_`、`mmd_joint_`）为 nullptr
- `animations_` 数组为空 → 已加载的 VMD 动画丢失

`mmd_model_` 仅在两种情况下被设置：`MSG_MENUPREPARE`（首次创建，不在场景加载时触发）和 `LoadPMX`（导入时）。

## Goals / Non-Goals

**Goals:**

- 场景重新打开后，自动从已序列化的 C4D 数据重建 `PMXModel` 及其子管理器，使动画和物理计算能够正常工作
- VMD 动画数据能够通过 Read/Write 持久化，场景重载后保持可用
- 用户在编辑模式下修改的骨骼/刚体/关节属性能反映到重建的运行时对象中
- 保持向后兼容：旧版本保存的场景文件能够正常打开（仅缺少运行时恢复功能）

**Non-Goals:**

- 不实现 PMX 文件路径的保存和从磁盘重新读取（方案 C）
- 不在场景中保存原始 PMX 二进制数据（方案 B）
- 不修改 libmmd 的 PMXModel::Load/LoadPMX 接口（保持文件解析路径不变）
- 不处理 mesh morph 数据的运行时重建（mesh morph 不依赖 libmmd 运行时对象）

## Decisions

### 决策 1：运行时重建的入口点

**选择**：在 `MMDModelManagerObject::Execute()` 中检测 `mmd_model_` 为 nullptr 时触发重建，而非在 `Read()` 中。

**理由**：`Read()` 在反序列化过程中被调用，此时子对象可能尚未完全恢复，场景文档也可能未完全就绪。`Execute()` 在场景完全加载后的每帧调用，且已有类似的延迟初始化模式（`is_manager_read_`、`is_morph_initialized_`）。

**备选方案**：在 `Read()` 末尾或 `MSG_DOCUMENTINFO`/`MSG_MULTI_DOCUMENTIMPORTED` 消息中触发。但这些时机子对象层级可能不完整。

### 决策 2：模型运行时对象的重建策略

**选择**：为 libmmd 添加 builder 风格的接口，允许从参数逐步构建 `PMXModel`，而非通过文件解析。

**步骤**：
1. 创建空 `PMXModel`
2. 遍历 `MMDBoneManagerObject` 的 `bone_list_`，为每个骨骼标签读取参数并调用 `MMDNodeManager::AddNode()` 设置节点属性（名称、位置、父子关系、层级、append、IK 等）
3. 遍历 `MMDRigidManagerObject` 的子对象，为每个 `MMDRigidObject` 读取参数并调用 `MMDPhysicsManager::AddRigidBody()` 设置刚体属性
4. 遍历 `MMDJointManagerObject` 的子对象，为每个 `MMDJointObject` 读取参数并调用 `MMDPhysicsManager::AddJoint()` 设置关节属性
5. 调用 `SetMMDModel()` 将指针分发到各子管理器
6. 重连各子对象的运行时指针

**理由**：libmmd 的各 Manager 已提供 `AddNode()`/`AddRigidBody()`/`AddJoint()` 接口，只需在其基础上增加属性设置方法。这比将整个 PMXFile 结构体序列化到场景中更轻量，且能自然反映用户的编辑修改。

**备选方案**：序列化 `PMXFile` 二进制数据并通过 `PMXModel::LoadPMX()` 重建。但这会增加场景文件大小，且无法反映用户在编辑模式下的修改。

### 决策 3：VMD 动画数据的持久化

**选择**：将 VMD 动画数据序列化为 VMD 二进制格式保存到 HyperFile 中。

**步骤**：
1. Write 时：对 `animations_` 数组中的每个 `VMDAnimation`，调用 `VMDAnimation::Save(VMDFile&)` 转换为 `VMDFile` 结构体，然后使用 `WriteVMDFile()` 序列化为字节数组写入 HyperFile
2. Read 时：从 HyperFile 读取字节数组，使用 `ReadVMDFile()` 解析为 `VMDFile`，然后在运行时重建阶段通过 `VMDAnimation::Create(mmd_model_)` + `VMDAnimation::Add(vmd_file)` 恢复

**理由**：VMD 动画数据是关键帧数据，无法从 C4D 对象推导。libmmd 已提供 `VMDAnimation::Save()` 和 `ReadVMDFile()`/`WriteVMDFile()` 接口，可以直接复用。VMD 文件格式紧凑，不会显著增加场景文件大小。

**备选方案**：保存 VMD 文件路径并从磁盘重读。但用户可能移动/删除文件，且无法保存通过 merge 操作合并的动画。

### 决策 4：重建状态管理

**选择**：添加 `is_runtime_initialized_` 标志位，在 `Execute()` 中检查并触发一次性重建。

**流程**：
```
Execute()
  ├── UpdateManagers()
  ├── if (!is_runtime_initialized_ && !mmd_model_)
  │     ├── RebuildRuntime()  // 新增方法
  │     │     ├── 创建 PMXModel
  │     │     ├── 从骨骼标签重建节点树
  │     │     ├── 从刚体对象重建物理
  │     │     ├── 从关节对象重建约束
  │     │     ├── SetMMDModel()
  │     │     └── 从序列化数据恢复 VMDAnimation
  │     └── is_runtime_initialized_ = true
  ├── (existing morph/animation logic)
```

### 决策 5：libmmd 接口扩展

需要为 libmmd 的以下类添加从参数设置属性的公共接口：

- `MMDNode`/`PMXNode`：`SetName()`、`SetPosition()`、`SetParent()` 等（部分已存在）
- `MMDRigidBody`：`SetShape()`、`SetMass()`、`SetDamping()` 等属性设置器
- `MMDJoint`：`SetLimits()`、`SetSpring()` 等属性设置器
- `MMDIkSolver`：从骨骼标签的 IK 参数重建链

这些接口应作为公共方法添加到现有类中，而非修改 `LoadPMX` 的内部实现。

## Risks / Trade-offs

- **[重建精度]** 从 C4D 参数反向构建的 libmmd 对象可能与原始 PMX 导入时的对象存在微小差异（浮点精度、参数映射遗漏）→ 缓解：添加单元测试验证 PMX 导入 → C4D 参数 → 重建 → 对比的往返一致性
- **[性能]** 大型模型（数百个骨骼、刚体）的运行时重建可能导致首帧延迟 → 缓解：重建在单独的初始化帧完成，后续帧不受影响；可在状态栏显示进度
- **[libmmd 改动范围]** 需要为 libmmd 添加 builder 接口，这是对第三方依赖的修改 → 缓解：libmmd 是项目内部维护的库，不影响外部依赖；新接口是纯增量添加，不修改现有接口
- **[VMD 数据大小]** 复杂动画的 VMD 数据可能较大，增加场景文件体积 → 缓解：VMD 格式本身紧凑；典型 VMD 文件为数百 KB 到几 MB，相对于 C4D 场景文件可接受
- **[向后兼容]** Read 的 level 递增后，新版本保存的场景无法被旧版本打开 → 缓解：这是 Cinema 4D 插件的标准做法；旧版本打开新场景时跳过未知 level 的数据

---

## Phase 2: C4D 插件端实现改进

### Context

Phase 1 的基础实现（`RebuildRuntime`、VMD 序列化、子对象重连）已完成。代码审查发现了以下需要修复的问题：

1. **`Write()` 在 RebuildRuntime 前保存会丢失 VMD 数据**：`Write()` 从 `animations_` 序列化，但 `Read()` 后 `RebuildRuntime()` 执行前 `animations_` 为空，VMD 数据仅存在于 `pending_vmd_data_`。如果在首次 `Execute()` 前保存场景（例如加载后立即保存），所有 VMD 动画数据丢失。
2. **`Execute()` 忽略 `RebuildRuntime()` 返回值**：当前代码调用 `RebuildRuntime()` 但不检查返回值，失败时静默继续，`mmd_model_` 保持 nullptr。
3. **刚体/关节重建顺序不确定**：`RebuildRigidBodies` 和 `RebuildJoints` 通过 `GetDown()`/`GetNext()` 遍历子对象，该顺序是场景层级顺序，可能与 `RIGID_INDEX` 不同。关节通过 `JOINT_LINK_RIGID_A_INDEX`/`JOINT_LINK_RIGID_B_INDEX` 引用刚体数组索引，如果创建顺序不匹配则会连接到错误的刚体。
4. **`is_runtime_initialized_` 线程安全**：其他类似标志（`is_manager_read_`、`is_morph_initialized_`、`update_morph_`）使用 `maxon::Synchronized<Bool>`，但 `is_runtime_initialized_` 使用裸 `bool`。
5. **文档时间未恢复**：`LoadVMDMotion()` 在加载 VMD 后更新 `doc->SetMaxTime()` 和 `SetLoopMaxTime()`，但 `RebuildRuntime()` 的 VMD 恢复逻辑没有执行此操作。

### 决策 6：Write() 的 VMD 数据回退

**选择**：在 `Write()` 中，当 `animations_` 为空且 `pending_vmd_data_` 不为空时，直接从 `pending_vmd_data_` 序列化。

**理由**：场景加载后如果用户在首次 Execute() 前保存（例如批量处理场景），`animations_` 尚未从 `pending_vmd_data_` 恢复。直接从 `pending_vmd_data_` 写入可以保证数据不丢失。

**实现**：

```
Write():
  if (animations_.GetCount() > 0)
    // 现有逻辑：从 animations_ 序列化
  else if (pending_vmd_data_.GetCount() > 0)
    // 回退：直接写入 pending_vmd_data_ 中的名称和二进制数据
  else
    // 写入 anim_count = 0
```

### 决策 7：刚体/关节按索引排序重建

**选择**：在 `RebuildRigidBodies` 和 `ReconnectRigidBodyPointers` 中，按 `RIGID_INDEX` 排序后创建刚体，而非按子对象层级顺序。

**理由**：关节的 `JOINT_LINK_RIGID_A_INDEX` / `JOINT_LINK_RIGID_B_INDEX` 是刚体在 `MMDPhysicsManager` 数组中的索引。如果刚体创建顺序与原始导入顺序不同，关节会引用到错误的刚体。

**实现**：先收集所有子对象及其 `RIGID_INDEX`，按 `RIGID_INDEX` 排序后再依次创建。关节侧同理。

### 决策 8：RebuildRuntime 错误处理

**选择**：在 `Execute()` 中检查 `RebuildRuntime()` 的返回值，失败时通过 `StatusSetBar` 显示错误信息，并将 `is_runtime_initialized_` 设为 true 防止每帧重试。

**理由**：重复的失败重试没有意义（每帧都会失败），且会严重影响性能。用户需要知道重建失败以采取行动（如重新导入）。

### Risks / Trade-offs (Phase 2)

- **[Write 回退复杂度]** `Write()` 需要处理两个数据源，增加了代码路径 → 缓解：两个路径的数据格式完全相同（名称 + 二进制），只是来源不同
- **[排序开销]** 刚体/关节按索引排序需要额外的排序步骤 → 缓解：排序发生在重建阶段，仅执行一次，且数据量小（通常 < 100 个刚体）
