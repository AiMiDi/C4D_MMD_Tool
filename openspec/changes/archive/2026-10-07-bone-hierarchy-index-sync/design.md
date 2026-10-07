## Context

当前骨骼层级相关状态分布在两个位置：

- `MMDBoneManagerObject` 维护 `bone_list_` 与 `bone_items_`，提供 `FindBone()` 和骨骼下拉列表
- `MMDBoneTag` 通过 `HandleBoneIndexUpdate()` 和 edit mode `Execute()`，根据 `GetUp()` / `GetPred()` 关系自行推导 `PMX_BONE_INDEX` 与 `PMX_BONE_PARENT_BONE_INDEX`

这套结构存在三个问题：

1. 计算来源不唯一。manager 与 tag 都在推导索引，但顺序和触发时机不完全一致。
2. 触发方式不稳定。tag 依赖 `Execute()` 每帧更新，拖拽层级、同级重排、新增/删除骨骼等操作无法保证在正确的时点完成整树刷新。
3. 依赖方读到的结果可能分叉。rigid/joint/display frame 等依赖 `GetBoneItems()` 的对象读取 manager 缓存，而属性管理器显示和导出路径又可能读取 tag 参数，导致 UI 与数据不同步。

这次变更需要在不修改 PMX 数据结构、不立即重建 libmmd runtime 的前提下，把“骨骼层级变化后的索引同步”收敛到单一实现。

## Goals / Non-Goals

**Goals:**

- 让 `MMDBoneManagerObject` 成为骨骼索引、亲骨骼索引和骨骼列表缓存的单一真源
- 在骨骼层级变化时，自动同步所有受影响骨骼 tag 的显示字段
- 让依赖 `GetBoneItems()` 的 UI 始终读取到与 bone tag 一致的骨骼顺序
- 移除 edit mode 下基于 `Execute()` 的每帧索引推导，改为事件驱动
- 让 PMX 导入和运行时恢复继续复用同一套同步入口初始化缓存

**Non-Goals:**

- 不在层级变化后立即重建 `libmmd::MMDNodeManager`、`MMDIKManager` 或 solver 父子关系
- 不新增外部资源 ID，不修改 `TMMDBone` / `OMMDBoneManager` 的静态资源结构
- 不改变 PMX 导出格式，只保证导出前读取到的骨骼索引和亲骨骼索引是最新同步结果
- 不引入 SceneHook 级别的全局监听；同步仍以内聚在 bone tag / bone manager 的消息链中为主

## Decisions

### 决策 1：索引顺序以 bone manager 子树 DFS 先序为唯一规则

**选择**: 在 `MMDBoneManagerObject` 中新增统一同步入口，对 manager 子树执行一次 DFS，按访问顺序为所有带 `g_mmd_bone_tag_id` 的 `Ojoint` 分配骨骼索引。

**理由**:

- DFS 先序与现有导入后骨骼在对象树中的组织方式一致，用户拖拽层级后也能得到直观、稳定的顺序
- 同一趟遍历就能拿到 index、parent index、对象名和 tag/link，避免 manager/tag 双方重复扫描
- `bone_list_` 和 `bone_items_` 可以直接由 DFS 结果重建，不需要再从旧缓存回推

**替代方案**: 保留 `MMDBoneTag::HandleBoneIndexUpdate()` 按局部相邻关系推导索引——会在整树重排时产生级联依赖，且无法保证 manager 缓存同步更新。

### 决策 2：bone tag 只负责检测拓扑变化并发出“层级脏”消息

**选择**: `MMDBoneTag` 新增运行期缓存，记录上次的 `GetUp()`、`GetPred()` 和当前 manager 归属，仅在这些拓扑指针发生变化时向 manager 发送 `MMDBoneTagMsgType::BONE_HIERARCHY_DIRTY`。

**理由**:

- tag 最接近实际被拖拽或重排的对象，最容易低成本检测“是否真的有层级变化”
- 把 tag 的职责收敛为脏通知，避免它继续承担整树索引计算
- 可以兼容新增、复制、删除、换父级、兄弟重排等由对象树变化引起的刷新需求

**替代方案**: 在 manager 侧每帧轮询整棵树——实现简单但会回到高频重复计算，不符合本次“事件驱动”的目标。

### 决策 3：manager 同步同时重建缓存并回写 tag 参数

**选择**: manager 同步入口在一次执行中完成以下动作：

- 清空并重建 `bone_list_`
- 清空并重建 `bone_items_`
- 建立 `BaseObject* -> bone_index` 的反查表
- 回写每个 tag 的 `PMX_BONE_INDEX`
- 回写每个 tag 的 `PMX_BONE_PARENT_BONE_INDEX` 和 `PMX_BONE_PARENT_BONE_NAME`
- 广播现有 `MMDBoneManagerObjectMsgType::BONE_HIERARCHY_UPDATE`

**理由**:

- 这样 manager 缓存与 tag UI 字段始终来自同一份中间结果
- 反查表可以复用给亲骨骼计算，复杂度保持在线性范围
- 依赖层级信息的后续逻辑只需要依赖同步完成后的 manager 状态

**替代方案**: 只更新缓存，不回写 tag 字段——会让属性管理器继续显示旧值，无法解决用户反馈的核心问题。

### 决策 4：使用轻量 reentry guard 防止同步递归

**选择**: 在 `MMDBoneManagerObject` 中增加一个轻量 guard/dirty 状态，用于防止同步过程中的 `SetParameter()`、广播消息或属性管理器刷新再次触发整树重算。

**理由**:

- manager 同步会回写多个 tag 参数，这些参数更新可能触发额外消息
- 没有 guard 时，容易出现重入和重复刷新，放大层级调整的代价
- 该 guard 仅用于本轮同步周期，不改变正常消息语义

**替代方案**: 依赖调用方自行避免递归——约束太脆弱，后续维护容易再次引入重入问题。

### 决策 5：属性管理器刷新使用 SetDirty + FORCE_AM_UPDATE，而不是伪造 MSG_CHANGE

**选择**: manager 在回写 tag 参数后，对相关对象/标签设置 `DIRTYFLAGS::DATA`，并发送 `COREMSG_CINEMA_FORCE_AM_UPDATE`，主线程下配合 `EventAdd()` 刷新 UI。

**理由**:

- C4D SDK 对 tag 参数变化推荐使用 `SetDirty(DIRTYFLAGS::DATA)`，而不是人工发送 `MSG_CHANGE`
- 这与仓库现有 DynamicDescription/Morph UI 的刷新方式一致
- 可以尽量减少对对象缓存系统的副作用

**替代方案**: 手动发送 `MSG_CHANGE`——容易把参数刷新和缓存重建混在一起，且不符合 SDK 注释建议。

### 决策 6：导入和运行时恢复复用 manager 同步入口

**选择**: 保留现有导入和运行时恢复的大流程，但在关键初始化完成后统一调用 bone manager 同步入口，作为缓存和 tag 显示字段的最终收敛步骤。

**理由**:

- 避免再维护一套“导入专用”的骨骼列表初始化逻辑
- 保证新建场景、重新打开场景、手动编辑层级三条路径看到同一套索引规则
- 便于后续若要扩展到 runtime 重建时，只需要在同一同步入口之后追加额外阶段

**替代方案**: 保留 `HandleBoneIndexChangeMessage()`、`GetBoneItems()`、导入路径各自独立初始化——实现分散，后续很难保证行为一致。

## Risks / Trade-offs

- **[Risk] 同步入口覆盖过多调用路径，可能引入消息重入** → 使用 manager guard，且把 tag 的新消息类型与旧的 `BONE_INDEX_CHANGE` 语义分离
- **[Risk] 删除/复制骨骼时缓存中的 BaseLink 可能暂时失效** → 每次同步都完全重建 `bone_list_` 与 `bone_items_`，不尝试增量修补旧缓存
- **[Risk] 依赖 `GetBoneItems()` 的下拉列表刷新时机不一致** → 同步后统一触发 AM 更新，并继续让各对象在 `GetDDescription()` 中从 manager 读取最新 `DESC_CYCLE`
- **[Risk] 运行时 libmmd 父子关系仍可能滞后于编辑后的层级** → 明确保持本次范围为 UI/导出优先，在 proposal/spec/tasks 中记录这一非目标，避免误解
