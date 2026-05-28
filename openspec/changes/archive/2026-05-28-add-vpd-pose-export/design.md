## Context

C4D_MMD_Tool 现在有较完整的 PMX/VMD 导入导出路径：UI 收集 `CMTToolsSetting`，`CMTToolsManager` 负责文件读写，`CMTSceneManager` 负责场景对象校验和编排，`MMDModelManagerObject` 负责模型级数据采集或应用。VMD Motion 导出已经按这个方向实现，`ExportVMDMotion` 先让模型对象填充 `libmmd::VMDFile`，再由工具层调用 `WriteVMDFile`。

VPD 的边界不同：它是单帧静态姿势文件，不应该进入 VMD 动画槽，也不应该触发多帧烘焙。libMMD 已经提供 `libmmd::VPDFile`、`VPDBone`、`VPDMorph` 和 `WriteVPDFile`，插件侧需要补的是当前姿势采样、UI 入口、错误提示和验证。

当前干净分支还没有 VPD 导出入口。现有资源中有 `Pose Import(VPD)` 组和按钮，但对应 command 分支仍是空操作；本变更只定义导出，后续实现时如果 VPD 导入变更已经合入，可以复用其坐标转换和报告能力。

## Goals / Non-Goals

**Goals:**

- 增加 VPD 姿势导出 UI 入口，保存扩展名为 `.vpd` 的文件。
- 在模型管理器动画分组中提供 VPD 导入/导出和当前帧关键帧辅助按钮，按现有两列布局呈现。
- 只对当前选中的 `MMDModelManagerObject` 导出姿势，沿用现有导出链路的对象校验和错误提示风格。
- 导出当前姿势快照：所有模型骨骼写入 `VPDBone`，所有模型 morph 控制器写入 `VPDMorph`。
- EDIT 模式导出当前可编辑静态姿势；ANIM 模式导出当前文档时间点已经求值后的单帧姿势。
- 使用 libMMD `WriteVPDFile` 写文件，并补充 VPD 写入/读回的聚焦测试。
- 更新导出开发文档，说明 VPD 是姿势快照而不是 VMD 动画导出。

**Non-Goals:**

- 不实现 VPD 导入；导入属于独立变更，即使实现时可以共享 helper。
- 不把 VPD 文件导入或导出为 VMD animation slot。
- 不做多帧动画烘焙、时间范围导出或批量帧导出。
- 不修改 `old/` 旧代码。

## Decisions

### 1. 沿用现有导出分层

实现路径采用 `CMTToolDialog` -> `CMTToolsManager::ExportVPDPose` -> `CMTSceneManager::SaveVPDPose` -> `MMDModelManagerObject::SaveVPDPose`：

- UI 只负责响应按钮、选择 `.vpd` 目标路径、构造 `CMTToolsSetting::PoseExport`。
- `CMTToolsManager` 持有 `libmmd::VPDFile`，调用 `CMTSceneManager` 填充数据，再调用 `WriteVPDFile`。
- `CMTSceneManager` 负责 active object 为空、类型不匹配等场景级错误。
- `MMDModelManagerObject` 负责从模型当前状态采样骨骼和 morph。

替代方案是在 UI 或 `CMTSceneManager` 直接遍历骨骼。这个方案会绕过模型对象已经持有的命名、动画槽、morph 和运行时状态边界，后续也更难和 VPD 导入共享转换逻辑，因此不采用。

### 1.1 模型管理器动画分组提供同类操作

模型管理器自身已经拥有活动动画槽、骨骼 tag 列表和 morph CTrack/slot 缓存，因此动画分组新增四个模型级按钮：

- 导入 VPD：对当前模型管理器对象导入 `.vpd`，不依赖 Object Manager 的 active selection。
- 导出 VPD：从当前模型管理器对象导出 `.vpd`，不依赖 active selection。
- 注册当前状态：只把当前时间点相对当前动画求值发生变化的骨骼姿势和 morph 强度写入当前动画槽当前帧；若没有动画槽且存在变化，则新建一个动画槽。
- 删除当前帧关键帧：从当前动画槽删除当前帧的骨骼关键帧和 morph CTrack key。

这些按钮沿用 `MODEL_ANIM_GRP` 现有两列布局，不放到 PMX 模型导入/导出区域。

### 2. VPD 导出语义定义为当前快照

VPD 导出只保存当前一帧状态：

- EDIT 模式读取当前可编辑骨骼姿势和 morph 滑块值。
- ANIM 模式读取当前文档时间点已经求值后的可见姿势和 morph 控制器值。
- 导出过程中不切换 animation slot，不创建 key，不修改已有轨道。

替代方案是只允许 EDIT 模式导出。这样实现更简单，但用户在动画某一帧定格导出姿势是常见需求，且 VPD 本身可以表达这种快照，因此不限制模式。实现时需要明确先保证文档当前时间点求值完成，再采样。

### 3. 骨骼导出使用模型本地名称和 VPD 坐标约定

每个 `VPDBone` 使用 PMX 本地骨骼名，平移和旋转转换成 libMMD/VPD 约定的 `Eigen::Vector3f` 与 `Eigen::Quaternionf`。实现应优先复用 VPD 导入变更中的转换 helper；如果导入尚未合入，则在当前架构内新增可复用的转换 helper，避免导入和导出各自维护一份坐标翻转/缩放逻辑。

导出应覆盖模型中的所有骨骼，即使某个骨骼当前是零位移或单位旋转。这样导出的 VPD 可以完整表达“将姿势复位到当前快照”的意图，后续导入时不会因为缺少条目而保留旧姿势。

### 4. Morph 导出保存控制器强度而非展开后的运行时结果

每个 `VPDMorph` 使用模型 morph 名称和当前 morph 强度。导出范围是模型拥有的 morph 控制器，包括值为 0 的条目。Group/flip morph 保存自身控制器强度，不把它们的下游贡献展开成普通 morph；展开后的 mesh/material/runtime hub 状态属于运行时应用结果，不是 VPD 控制器语义。

这个选择让 VPD round-trip 更可预测：导出后再导入会恢复用户看到和可编辑的 morph 控制器值，而不是把 group/flip 贡献重复应用到子 morph。

### 5. 文件写入和编码留在 libMMD

插件侧不手写 VPD 文本。`CMTToolsManager::ExportVPDPose` 只把 UTF-8 名称和浮点数据填入 `libmmd::VPDFile`，实际 SJIS 转换、文本格式和文件创建由 `WriteVPDFile` 完成。

libMMD 侧需要用测试覆盖 `WriteVPDFile` -> `ReadVPDFile` 的 round-trip，至少包含：

- 多骨骼条目。
- morph 条目。
- 非 ASCII 名称。
- 平移、四元数和权重的数值保持。

## Risks / Trade-offs

- [Risk] 骨骼坐标转换和 VPD 导入不一致，导致导出后导入姿势有偏差。 -> Mitigation: 把导入/导出转换集中到共享 helper，并用手工 round-trip 验证 EDIT 姿势。
- [Risk] ANIM 模式采样到的骨骼状态不是当前帧最终可见姿势。 -> Mitigation: 在采样前使用当前文档时间点的已求值状态，必要时通过现有运行时 pose/cache 或对象矩阵读取最终写回结果。
- [Risk] group/flip morph 导出语义和最终 mesh/material 变形效果不完全等价。 -> Mitigation: 明确导出 morph 控制器值，不导出展开后的运行时状态；这符合 VPD 作为控制器姿势文件的用途。
- [Risk] libMMD 子模块在新 worktree 未初始化时无法直接跑测试。 -> Mitigation: 实现阶段先初始化/同步 submodule，再运行 VPD writer 测试和插件构建。
- [Risk] C4D 资源 ID 和多语言字符串新增遗漏。 -> Mitigation: 同步更新 `res/S24_up` dialog、strings 和 `c4d_symbols.h`，并通过插件构建验证资源编译。

## Migration Plan

这是新增能力，不需要数据迁移。实现完成后用户会在工具面板看到新的 VPD 导出入口；已有 PMX/VMD 导入导出行为保持不变。

回滚时删除新增 UI 入口、`PoseExport` setting、VPD export 调用链和文档/测试即可，不需要修改用户工程文件。

## Open Questions

无阻塞问题。实现时需要在代码中确认 ANIM 模式骨骼采样的最佳来源：优先使用模型运行时最终姿势缓存；如果当前架构没有公开缓存，则从已经写回到场景的骨骼对象矩阵转换。
