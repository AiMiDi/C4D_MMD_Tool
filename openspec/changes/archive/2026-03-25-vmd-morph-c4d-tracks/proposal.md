## Why

当前 VMD 模式下，表情（morph）动画完全由 libMMD 内部驱动：`VMDAnimation::Evaluate()` 每帧计算权重 → `MMDMeshManagerObject` 从 libMMD 读取权重覆盖 Pose Morph → 整个 `MODEL_MORPH_GRP` UI 被隐藏。用户无法在 C4D 时间线中看到、编辑或微调表情关键帧，可调性极差。VMD 表情关键帧使用纯线性插值，与 C4D 的 CTrack/CKey 系统完全兼容，可以直接移植。

## What Changes

- **VMD 导入时创建 C4D 关键帧**：在 `LoadVMDMotion` 中遍历 `VMDFile::m_morphs`，通过 `morph_name_` 匹配到 `morph_data_[]`，在对应的 `m_strength_id` 上创建 CTrack/CKey（线性插值），将 VMD 表情数据直接映射到模型属性管理器 UI 的强度属性。
- **取消 VMD 模式下表情组隐藏**：移除 `GetDDescription` 中对 `MODEL_MORPH_GRP` 的 `DESC_HIDE` 设置，使用户在 VMD 模式下也能看到和编辑表情滑块。非编辑模式下仅隐藏"添加"相关按钮。
- **移除 MeshManager 的 VMD 表情覆盖路径**：移除 `MMDMeshManagerObject::Execute` 中 `MESH_MODE_VMD` 下从 libMMD 读取 morph 权重的逻辑，改为完全依赖 `UpdateMorph()` → `SetMorphStrength()` 已有路径。
- **Group/Flip Morph 改为叠加语义**：将 `GroupMorph::UpdateMorph` 从覆写改为叠加（`+=`），`FlipMorph::UpdateMorph` 同理，与 libMMD/MMD 原始行为保持一致。
- **清理 MeshManager 中 VMD morph 相关数据结构**：移除不再需要的 `morph_manager_index_`、`mmd_morph_manager_` 等 VMD 表情相关的数据结构和初始化逻辑。
- **记录未匹配 morph 名称到导入日志**：导入 VMD 时，将无法匹配到模型 morph 的名称记录到 `not_find_morph_name_list`，在导入报告中给用户反馈。

## Capabilities

### New Capabilities
- `morph-c4d-track-animation`：VMD 导入时将表情关键帧数据写入 C4D CTrack，支持时间线查看和编辑

### Modified Capabilities
- `object-morph-system`：Group/Flip morph 的 UpdateMorph 语义从覆写改为叠加；VMD 模式下不再隐藏表情 UI
- `motion-vmd-motion`：VMD 导入流程增加 CTrack 关键帧创建；不再使用 libMMD 每帧输出表情权重驱动 mesh；增加未匹配 morph 的日志反馈

## Impact

- **源文件**：`mmd_model_manager.cpp/h`（导入逻辑、UI 隐藏）、`mmd_morph.cpp`（Group/Flip UpdateMorph 语义）、`mmd_mesh_manager.cpp/h`（VMD morph 路径移除、数据结构清理）
- **依赖**：libMMD 内部 VMD morph 评估仍保留（骨骼 morph 效果依赖其 node 变换计算），不改动 libMMD
- **兼容性**：已存在的 VMD 模式场景文件加载后需要重新导入 VMD 动画以获得 CTrack 关键帧；旧场景的 morph 滑块数据不会丢失
- **API 变化**：`MMDMeshManagerObject` 移除 `morph_manager_index_`、`mmd_morph_manager_` 成员和相关方法
