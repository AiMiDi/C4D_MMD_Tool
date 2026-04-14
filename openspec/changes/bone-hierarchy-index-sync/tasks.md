## 1. Bone manager 同步核心

- [x] 1.1 在 `mmd_bone_manager.h` 中新增层级同步所需的运行期状态与辅助声明（如同步 guard、DFS 中间数据结构或私有同步方法）
- [x] 1.2 在 `mmd_bone_manager.cpp` 中实现统一的骨骼层级同步入口，对 bone manager 子树执行 DFS，重建 `bone_list_`、`bone_items_` 和对象到骨骼索引的反查关系
- [x] 1.3 在同步入口中回写每个 bone tag 的 `PMX_BONE_INDEX`、`PMX_BONE_PARENT_BONE_INDEX`、`PMX_BONE_PARENT_BONE_NAME`，并让 `FindBone()`、`FindBoneIndex()`、`GetBoneItems()` 全部基于同步后的 manager 缓存工作

## 2. Bone tag 层级脏通知

- [x] 2.1 在 `mmd_bone.h` 中新增 `MMDBoneTagMsgType::BONE_HIERARCHY_DIRTY`，以及 tag 运行期使用的拓扑缓存字段（parent / pred / manager 归属）
- [x] 2.2 在 `mmd_bone.cpp` 中实现拓扑变化检测，仅当层级或 manager 归属真实变化时向 bone manager 发送层级脏消息
- [x] 2.3 移除 edit mode 下 `Execute()` 中基于 `HandleBoneIndexUpdate()` 的每帧索引推导逻辑，保留现有非层级相关行为

## 3. 集成与刷新路径

- [x] 3.1 在 `MMDBoneManagerObject::Message()` / `HandleMMDBoneTagMessage()` 中接入新的层级脏消息，完成同步后广播 `BONE_HIERARCHY_UPDATE`
- [x] 3.2 在同步完成后使用 `SetDirty(DIRTYFLAGS::DATA)`、`COREMSG_CINEMA_FORCE_AM_UPDATE` 和 `EventAdd()` 刷新属性管理器，避免使用伪造 `MSG_CHANGE`
- [x] 3.3 让 PMX 导入、manager read 恢复和 runtime reconstruction 后的骨骼缓存初始化复用同一个 bone manager 同步入口

## 4. 验证与回归检查

- [ ] 4.1 验证骨骼重设父级、同层重排、新增、删除、复制后，bone tag 显示索引与 `bone_items_` 顺序保持一致
- [ ] 4.2 验证依赖 `GetBoneItems()` 的对象（如 rigid、joint、display frame 相关选择器）在同步后读取到最新下拉列表
- [ ] 4.3 验证 PMX 导出前读取到的 parent index 与 manager 同步结果一致，并确认 ANIM/VMD 模式未因移除 edit-mode 每帧重算而回归
