## Context

当前 `res/S24_up` 和兼容资源树里已经有“导入姿势(VPD)”分组和按钮，README 也描述了 VPD 姿势导入能力，但 `CMTToolDialog::Command` 对 `DLG_CMT_TOOL_POSE_IMPORT_BUTTON` 只执行空 `break`。`old/VPD.cpp` 里保留了旧实现：直接从选中对象向下遍历 `Ojoint`，按本地骨骼名写 `SetRelPos` / `SetRelRot`，但它不接入当前 `MMDModelManagerObject`、动画槽、morph UI、runtime 重建和导入报告。

`dependency/libMMD/src/libMMD/Model/MMD/VPDFile.*` 已提供 VPD 读写结构和 parser，且 2026-02-26 的 GLM 到 Eigen 迁移已把 VPD 数据约定为原始 MMD 坐标数据。当前 C4D 插件边界已经在 PMX/VMD 导入和 runtime 写回处承担坐标与姿势解释，因此这次不应把旧版 parser 复制回插件层。

## Goals / Non-Goals

**Goals:**

- 接通工具窗口的 VPD 导入按钮，要求用户选中 `MMDModelManagerObject` 根对象后导入 `.vpd` 文件。
- 通过 libMMD 读取 VPD 文件，并在插件层把 bone pose 和 morph weight 应用到当前模型。
- 按 PMX 本地骨骼名匹配 VPD bone，按模型 morph 名匹配 VPD morph，并在导入日志里报告未匹配项。
- 导入后刷新 C4D 对象、morph 显示和 standalone runtime，使后续 IK/physics/runtime 基于导入后的姿势运行。
- 给 libMMD 的 VPD 解析/写出补充测试，避免 parser 回归。

**Non-Goals:**

- 不实现 VPD 导出。
- 不新增拖入 `.vpd` 的 C4D scene loader。
- 不把 VPD 作为新的 VMD 动画槽，也不在骨骼或 morph 上创建 CTrack/CKey。
- 不恢复 `old/` 目录中的旧类结构；旧实现只作为行为参考。
- 不在本 change 里重做 VMD motion 的比例、插值或动画槽语义。

## Decisions

### D1: VPD 由 ModelManager 入口拥有

选择：新增 `CMTToolsSetting::PoseImport`、`CMTToolsManager::ImportVPDPose`、`CMTSceneManager::LoadVPDPose`，最终由 `MMDModelManagerObject::LoadVPDPose` 应用到模型。

理由：当前模型的骨骼索引、morph 名称表、子 manager 链接、runtime 失效和模式切换都由 `MMDModelManagerObject` 管理。继续沿用旧版“遍历任意选中对象子树”的做法会绕过这些边界，容易出现 morph 不刷新、runtime 覆盖导入姿势、选中子对象导致半成功等问题。

替代方案：直接在 `CMTToolDialog` 中遍历选中对象并设置 joint。放弃，因为它只覆盖旧骨骼写入，无法正确处理当前插件的 morph、runtime 和错误报告。

### D2: VPD 导入应用为当前模型状态，而不是动画槽

选择：VPD bone/morph 数据导入为当前模型姿势。若模型处于动画模式，实现不切换到编辑模式，也不删除、替换或重建已有动画槽；骨骼姿势作为当前文档时间点的静态 pose override 应用到 scene state，morph weight 作为当前帧临时 strength 显示。该状态只在导入的当前时间点保留；如果用户不点击“注册当前状态”，播放推进、跳到其他时间或切换模式时应清理临时 VPD 状态，让当前动画槽/轨道重新驱动模型。后续用户可用“注册当前状态”把发生变化的部分写入当前动画槽关键帧。

理由：VPD 是单帧姿势格式，不包含 VMD 的时间轴、插值、IK enable track 和模型信息时间序列。把 VPD 转成单帧动画槽会让用户误以为它是 motion 导入，并可能污染现有动画槽；强制切到编辑模式也会打断动画面板中的当前槽操作。当前状态和关键帧写入必须拆开，由用户显式选择是否注册。

替代方案：生成一个只有第 0 帧 key 的 VMD animation slot。放弃，因为它改变了 VPD 语义，也会把 pose import 和 motion import 的删除/合并策略耦合起来。

### D3: 骨骼姿势复用当前动画姿势解释和 dirty 路径

选择：在 `MMDBoneTag` 或 BoneManager 暴露一个明确的“应用静态 pose” helper，输入 VPD translation + quaternion，按当前 VMD bone pose 的比例和旋转约定构造骨骼相对矩阵，并复用现有 dirty/update 逻辑。实现前需要确认 `MODEL_POSITION_MULTIPLE` 在 PMX/VMD 当前管线里的实际口径，VPD 平移必须与当前模型骨骼姿势空间一致。

理由：`MMDBoneTag::ApplyActiveAnimation` 已经包含可移动/可旋转标志、append/inherit 基础求值和矩阵构建语义。VPD 导入不应复制一套数学转换，也不应重走旧版 `QuaternionToEuler` 后写 HPB 的路径。

替代方案：直接 `SetRelPos` / `SetRelRot`。放弃，因为它绕过当前 quaternion 规范化、rotation order、append/inherit 和 runtime pose cache 约定。

### D4: Morph 使用现有 morph strength 路径

选择：VPD morph weight 通过 `MMDModelManagerObject` 的 morph 名称映射和现有 `UpdateMorph` / `SetMorphStrength` 路径应用，并刷新 UI/dirty 状态。

理由：mesh morph、bone morph、group/flip/material/impulse morph 的实际分发已经集中在当前 morph 系统里。VPD 不应直接访问 mesh manager 的私有 map，也不应只支持 mesh morph。

替代方案：只实现骨骼 pose，与旧实现保持一致。放弃，因为 libMMD 的 VPDFile 已支持 morph，README 期望是“VPD data”而不是“仅骨骼 VPD”。

### D5: 报告和失败路径沿用 VMD/PMX 导入风格

选择：新增 `LoadVpdPoseLog` 或扩展同类导入日志，覆盖读文件失败、选中对象为空、选中对象不是 MMD 模型、未匹配骨骼、未匹配 morph、导入统计。详细报告可先总是输出到 `GePrint` / `MessageDialog` 的现有风格；若新增 detail 开关，应放在 `PoseImport`。

理由：当前用户排查导入问题依赖明确的错误对话框和导入报告。VPD 名称不匹配很常见，必须可见，而不能静默跳过。

替代方案：只返回 false。放弃，因为这会让“按钮没反应”和“VPD 名称不匹配”无法区分。

## Risks / Trade-offs

- [Risk] 动画模式下导入后被同帧 runtime 立即覆盖，或未注册的 VPD 姿势跨帧残留 -> [Mitigation] 使用当前时间点静态 pose override 保持同帧导入结果，并在时间/模式变化时清理临时状态；关键帧写入只由“注册当前状态”触发。
- [Risk] VPD translation 比例与当前 PMX/VMD 管线不一致 -> [Mitigation] 实现前用现有 PMX bone position、VMD bone keyframe 和 `MODEL_POSITION_MULTIPLE` 读写路径确认口径，并把决策写入任务验证记录。
- [Risk] append/inherit 或物理驱动骨骼直接写入后与 runtime 求值冲突 -> [Mitigation] 复用当前 bone pose helper 和 runtime invalidation；测试覆盖普通骨骼、append/inherit 骨骼以及物理骨骼至少一种手动场景。
- [Risk] libMMD VPD parser 只按 filename 读取，工具层其他导入多用 `ReadFileData` -> [Mitigation] 初版可使用 `ReadVPDFile(filename)`，但 tests 要覆盖 SJIS 名称、bone/morph、round-trip；如需内存解析再在 libMMD 增加接口。
- [Risk] 当前工作区已有无关本地改动 -> [Mitigation] 实施时只提交 VPD 相关代码、tests、docs 和 OpenSpec 文件，保持 `res/S24_up/cmt_config.json`、`.ignore`、`_lldb_c4d_run.txt` 等无关状态不进入提交。

## Migration Plan

1. 先实现 libMMD VPD parser 测试，确认现有 parser 能稳定读取 bone/morph 和 SJIS 名称。
2. 接通插件 UI -> ToolsManager -> SceneManager -> ModelManager 的 VPD 导入链路。
3. 实现骨骼 pose 和 morph weight 应用，并补充导入日志。
4. 更新 `docs/dev/import-flow.md` 的 VPD 姿势链路和问题定位。
5. 使用 libMMD focused tests、`openspec validate add-vpd-pose-import --strict`、根 CMake workflow 构建验证；最后在 C4D 中手动导入 PMX + VPD 验收。

Rollback 策略：VPD 是新增入口，若运行时行为不稳定，可先禁用 `DLG_CMT_TOOL_POSE_IMPORT_BUTTON` 的调用并保留 parser tests；不会影响 PMX/VMD 既有导入路径。

## Open Questions

- 是否需要在 VPD 导入对话中暴露 `position_multiple` 或“详细报告”选项，还是直接读取选中模型的 `MODEL_POSITION_MULTIPLE` 并使用默认报告？
- 已决定：对处于动画模式的模型，VPD 导入只应用当前状态，不切换 `MODEL_MODE_EDIT`；需要写入动画时由模型管理器动画面板的“注册当前状态”按钮完成。
