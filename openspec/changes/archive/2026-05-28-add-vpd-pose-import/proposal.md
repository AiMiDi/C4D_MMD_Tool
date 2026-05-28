## Why

当前工具界面和 README 仍暴露“导入姿势(VPD)”能力，但 `DLG_CMT_TOOL_POSE_IMPORT_BUTTON` 的命令入口已经断开，用户无法把 VPD 静态姿势导入到已导入的 MMD 模型。需要把这个旧功能接回当前 `MMDModelManagerObject`、骨骼 tag、morph UI 和 runtime 重建边界，避免继续依赖 `old/` 里的遗留实现。

## What Changes

- 新增 VPD 姿势导入能力，通过工具窗口“导入姿势(VPD)”按钮选择 `.vpd` 文件并作用于当前选中的 `MMDModelManagerObject`。
- 使用 `libmmd::ReadVPDFile` 解析 VPD 文件，保留 libMMD 内部“原始 PMX/VPD 坐标空间”的约定，不在 libMMD 里做 C4D 坐标修正。
- 按 PMX 本地骨骼名匹配 VPD bone pose，将 VPD 的平移和旋转写入对应骨骼的当前姿势数据；未匹配骨骼进入导入报告。
- 支持 VPD morph weight 导入到当前模型的 morph 控件/strength 路径；未匹配 morph 进入导入报告。
- 导入后刷新 C4D 对象状态并使 standalone runtime 失效，确保 IK/physics/runtime 在下一次执行时基于新姿势重建。
- 补充 libMMD VPD 解析/写出测试覆盖，并补充导入流程文档中的 VPD 姿势链路。

## Capabilities

### New Capabilities

- `import-vpd-pose`: 覆盖 VPD 静态姿势导入入口、目标模型校验、骨骼/morph 名称匹配、导入报告、runtime 刷新和验证要求。

### Modified Capabilities

- None.

## Impact

- 代码入口：`source/module/ui/cmt_tools_dialog.cpp`、`source/cmt_tools_setting.h`、`source/cmt_tools_manager.*`、`source/CMTSceneManager.*`。
- 模型应用：`source/module/tools/object/mmd_model_manager.*`、`source/module/tools/object/mmd_bone_manager.*`、`source/module/tools/tag/mmd_bone.*`、morph strength 路径。
- 解析依赖：`dependency/libMMD/src/libMMD/Model/MMD/VPDFile.*` 以及对应 tests。
- 资源和文档：`res/S24_up/` 与兼容资源树中的现有 VPD UI 文案、`docs/dev/import-flow.md`。
