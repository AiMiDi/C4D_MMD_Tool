## Why

当前工具已经有 PMX/VMD 导出链路，也有 VPD 读写能力可复用，但用户无法把当前模型姿势保存为 `.vpd`。VPD 是 MMD 生态里常用的静态姿势交换格式，适合在模型调姿、动画帧定格、以及和其他 MMD 工具互通时保存当前骨骼和表情状态。

现有 UI 只暴露了 `Pose Import(VPD)` 入口，缺少对称的导出命令；现有 VMD Motion 导出面向动画数据，不适合表达单帧姿势快照。需要增加一个当前架构内的 VPD 姿势导出能力，复用 libMMD 的 `WriteVPDFile`，避免重新实现文件格式或回到 `old/` 旧代码路径。

## What Changes

- 在工具 UI 和模型管理器动画面板中增加 VPD 姿势导出入口，用于选择保存 `.vpd` 文件。
- 增加 `CMTToolsManager` / `CMTSceneManager` / `MMDModelManagerObject` 方向的 VPD 导出调用链，保持与现有 PMX/VMD 导出结构一致。
- 从选中的 `MMDModelManagerObject` 采集当前姿势快照：
  - 骨骼以 PMX 本地名称写入，保存当前位置偏移和旋转四元数。
  - 表情以模型 morph 名称写入，保存当前强度。
- 在 EDIT 模式导出当前可编辑静态姿势；在 ANIM 模式导出当前文档时间点已经求值后的单帧姿势快照，不创建或修改 VMD 动画槽。
- 在模型管理器动画面板增加当前姿势辅助操作：导入 VPD、导出 VPD、注册当前状态到当前帧关键帧、删除当前帧关键帧。
- 复用 libMMD `VPDFile` / `WriteVPDFile` 作为文件写入边界，并补充聚焦测试和导出文档。
- 增加错误提示和结果汇总，覆盖未选中模型、目标类型错误、写入失败等路径。

## Capabilities

- New: `export-vpd-pose` - selected MMD model VPD static pose export, including current bone pose, morph strengths, UI entry, file writing, and failure reporting.

## Impact

- 影响范围主要在工具 UI、导出编排层、模型管理对象的姿态采集、libMMD VPD 写入验证，以及开发文档。
- 不改变 PMX/VMD 导入导出语义。
- 不把 VPD 当作新的 VMD 动画槽，也不实现多帧动画烘焙。
- 不修改 `old/` 旧代码；旧实现仅可作为行为参考。
