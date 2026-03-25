## Context

当前 VMD 模式下表情动画的数据流是：

```
VMDFile::m_morphs → VMDAnimation::Add() → VMDMorphController (线性插值)
    每帧 → VMDAnimation::Evaluate() → MMDMorph::SetWeight()
         → PMXModel::UpdateMorphAnimation() → libMMD 内部处理
         → MMDMeshManagerObject 从 libMMD 读 GetWeight() → 覆盖 Pose Morph Tag
```

- `MODEL_MORPH_GRP` 在 VMD 模式下被完全隐藏
- `UpdateMorph()` 虽在所有模式下运行，但 mesh manager 的 VMD 路径会覆盖其效果
- 用户无法在 C4D 时间线中查看或编辑表情关键帧

代码中已有被注释掉的 `SetMeshMorphAnimation`（mmd_model_manager.cpp:1611-1649），使用 `CTrack`/`CKey` 在 `IMorph::m_strength_id` 上创建关键帧，是本次改造的直接参考。

## Goals / Non-Goals

**Goals:**
- VMD 导入后，表情关键帧出现在 C4D 时间线中，用户可查看和编辑
- 表情滑块在 VMD 模式下可见且实时反映动画值
- Group/Flip morph 的传播语义与 MMD 原始行为一致（叠加而非覆写）
- 清理 MeshManager 中不再使用的 VMD morph 数据结构
- 未匹配的 morph 名称在导入报告中给出反馈

**Non-Goals:**
- 骨骼动画迁移到 C4D CTrack（留作第二步，涉及贝塞尔曲线转换）
- Material/Impulse morph 的 UpdateMorph 实现（这两个当前为空实现，不在本次范围内）
- 改动 libMMD 内部代码
- 支持 VMD 导出时从 CTrack 读取表情数据（保持现有的 `VMDAnimation::Save` 路径）

## Decisions

### D1: CTrack 创建时机 — 在 LoadVMDMotion 中完成

**选择**：在 `MMDModelManagerObject::LoadVMDMotion` 中，`VMDAnimation::Add` 完成后，遍历 `vmd_file.m_morphs` 直接创建 CTrack/CKey。

**理由**：
- `LoadVMDMotion` 已经持有 `vmd_file` 和完整的 `morph_name_` 映射
- 一次性操作，不影响每帧性能
- 注释代码 `SetMeshMorphAnimation` 正是这个模式

**备选**：在 `RebuildRuntime` 中从 VMDAnimation 的 morph controller 提取数据。但这需要暴露 VMDAnimation 内部结构，增加 libMMD API 耦合。

### D2: 保留 libMMD 的 VMDAnimation morph 评估

**选择**：`VMDAnimation::Evaluate()` 仍然会设置所有 morph 权重（包括表情），不修改 libMMD。

**理由**：
- 骨骼 morph 的效果通过 `UpdateMorphAnimation()` 写入 `mmd_node_` 变换，`BoneTag` 在 VMD 模式下读取这些变换。如果移除 morph 评估，骨骼 morph 会失效。
- libMMD 不需要改动，降低改造风险。
- C4D 端的表情值和 libMMD 端的表情值会平行存在但互不干扰：mesh/UV morph 只看 C4D 路径（通过 `UpdateMorph → SetMorphStrength`），骨骼 morph 只看 libMMD 路径。

### D3: Group/Flip Morph 叠加语义

**选择**：将 `GroupMorph::UpdateMorph` 改为叠加（`SetStrength(node, GetStrength(node) + self * ratio)`），`FlipMorph::UpdateMorph` 类似。

**理由**：
- MMD 中 group morph 对子 morph 是叠加效果。如果 VMD 同时在 group morph 和其子 mesh morph 上都有关键帧，覆写会丢失子 morph 自身的关键帧值。
- C4D 的 CTrack 会同时在 group morph 和子 morph 的 strength 参数上设置值，`UpdateMorph` 在 track 求值之后运行，必须是叠加才能正确合并。

**注意**：`UpdateMorph` 的遍历顺序需要保证 group/flip morph 在其子 morph 的 `UpdateMorph` 之前执行。当前的 `morph_data_` 顺序（由 PMX 导入顺序决定）通常满足这个条件，因为 PMX 中 group/flip morph 通常排在引用的子 morph 之后。但在遍历时需要先处理 group/flip，再处理其余。实际上 PMX 中 group/flip morph 引用的是其他 morph 的 index，而 group/flip 本身可以在列表中任意位置。

**具体实现**：分两轮遍历 — 第一轮只处理 group/flip morph（将叠加值写入子 morph），第二轮处理其余 morph（mesh/bone/UV 推送到 manager）。

### D4: MeshManager VMD morph 数据结构清理

**选择**：移除 `morph_manager_index_`、`mmd_morph_manager_` 成员、以及 `Execute` 中 `MESH_MODE_VMD` 的 morph 权重读取块。

**理由**：
- 这些结构仅用于从 libMMD 读取 morph 权重，改用 C4D 参数驱动后不再需要。
- `SetMorphStrength(name, strength)` 通过名称查找 `mesh_morph_name_` 映射，功能完全覆盖。

**保留**：`mesh_morph_name_`、`mesh_morph_data_`、`mesh_morph_mode_` 等结构仍然需要，它们是 Pose Morph Tag 的映射，与 VMD 无关。

### D5: CKey 插值模式设为线性

**选择**：创建 CKey 后显式设置为线性插值（`CINTERPOLATION_LINEAR`）。

**理由**：C4D 默认使用样条插值，会在关键帧之间产生过冲。VMD 表情使用线性插值，必须匹配。

### D6: VMD 模式下表情 UI 可见性策略

**选择**：VMD 模式与 ANIM 模式使用相同的 UI 可见性逻辑 — 表情滑块可见，但隐藏"添加/删除/重命名"等编辑按钮。

**理由**：
- 用户需要能看到滑块来确认动画效果
- 用户可以在时间线中修改关键帧，滑块应实时反映当前值
- 不应允许在 VMD 模式下添加/删除 morph，避免与 VMD 动画数据不一致

## Risks / Trade-offs

- **[风险] CTrack 数量大**：复杂 VMD 可能有几十个 morph 关键帧通道。→ 缓解：C4D 时间线原生支持大量 CTrack，UI 上通过面板分类过滤。
- **[风险] Group morph 遍历顺序**：如果 PMX 数据中 group morph 引用了排在其后的 morph，两轮遍历策略可以正确处理。→ 缓解：第一轮仅处理 group/flip，第二轮处理余下所有类型。
- **[风险] 旧场景兼容性**：已保存的场景在 VMD 模式下没有 CTrack。→ 缓解：用户需要重新导入 VMD 文件；旧场景不会崩溃，只是表情不再自动播放。
- **[权衡] libMMD 中 morph 评估冗余**：libMMD 仍然每帧评估所有 morph 权重，但 mesh/UV morph 结果不再使用。→ 这个开销很小（纯数值插值），且保障了骨骼 morph 的正确性。
