## Why

当前骨骼索引、亲骨骼索引和骨骼列表缓存分散在 `MMDBoneTag` 与 `MMDBoneManagerObject` 两侧维护。`MMDBoneTag` 在 edit mode 的 `Execute()` 中按当前层级反复推导索引，但这个推导既会重复计算，也无法稳定覆盖拖拽重排、新增/删除骨骼等层级变化场景，导致属性管理器显示、下拉列表内容和导出使用的数据出现不同步。

需要把骨骼层级相关索引收敛到 bone manager 的单一真源，并通过 C4D 消息系统在层级变化时自动同步，这样骨骼 tag 的显示字段、依赖骨骼列表的 UI 和后续导出都能共享同一份稳定结果。

## What Changes

- 在 `MMDBoneManagerObject` 中新增统一的骨骼层级同步入口，对 bone manager 子树执行一次 DFS，集中计算骨骼索引、亲骨骼索引、`bone_list_` 和 `bone_items_`
- `MMDBoneTag` 新增运行期拓扑缓存与层级脏消息，仅在父子层级、同级顺序或 manager 归属变化时通知 bone manager 重算
- bone manager 在同步后回写每个骨骼 tag 的 `PMX_BONE_INDEX`、`PMX_BONE_PARENT_BONE_INDEX`、`PMX_BONE_PARENT_BONE_NAME`，并刷新属性管理器显示
- 移除 bone tag 在 edit mode 下每帧重复执行的索引推导逻辑，避免 `Execute()` 驱动的重复计算和状态分叉
- 让 PMX 导入和运行时恢复继续复用同一套 manager 同步入口，保证初始化后的缓存结构与手动编辑后的结果一致

## Capabilities

### New Capabilities

- `object-bone-hierarchy-sync`: 在骨骼层级发生变化时，自动同步 bone manager 缓存、bone tag 索引显示和依赖骨骼列表的对象 UI

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **影响代码**: `module/tools/object/mmd_bone_manager.*`、`module/tools/tag/mmd_bone.*`，以及使用 bone manager 缓存初始化路径的 `mmd_model_manager.cpp`
- **影响系统**: 骨骼属性管理器显示、骨骼下拉列表（如 rigid/joint/display frame 等依赖 `GetBoneItems()` 的界面）、PMX 导出前读取到的父骨骼索引
- **接口变化**: 新增内部消息 `MMDBoneTagMsgType::BONE_HIERARCHY_DIRTY` 和若干运行期缓存字段，不新增外部资源 ID，不修改 PMX 数据结构
- **兼容性**: 旧场景文件继续使用现有参数与序列化数据；新增逻辑仅改变层级编辑后的自动同步行为
