## 1. 准备与边界确认

- [x] 1.1 初始化/同步 `dependency/libMMD` 子模块，确认 `VPDFile`、`ReadVPDFile`、`WriteVPDFile` 和现有 VPD 测试位置可用。
- [x] 1.2 阅读 `source/module/core/cmt_marco.h` 和现有 VMD/PMX 导出调用链，确认新增代码优先使用已有 SDK 兼容封装。
- [x] 1.3 确认 VPD 导入变更是否已经合入；若已合入，复用其姿势坐标转换 helper；若未合入，新增导入/导出都可复用的转换 helper。

## 2. libMMD 写入验证

- [x] 2.1 新增或扩展 `dependency/libMMD/tests/VPDFile.test.cpp`，覆盖 `WriteVPDFile` -> `ReadVPDFile` round-trip。
- [x] 2.2 测试数据包含多骨骼、morph、非 ASCII 名称、平移、四元数和权重，并用容差验证数值。
- [x] 2.3 确认 VPD writer 测试已被 libMMD/CMake 测试目标纳入，并能单独运行。

## 3. UI 与工具入口

- [x] 3.1 增加 `CMTToolsSetting::PoseExport`，保存输出文件名和当前导出所需设置。
- [x] 3.2 更新 `res/S24_up` dialog、strings 和 `c4d_symbols.h`，新增 VPD 姿势导出按钮/分组及中英文显示文本。
- [x] 3.3 在 `CMTToolDialog::Command` 中处理 VPD 导出按钮，弹出 `.vpd` 保存路径选择，并调用 `CMTToolsManager::ExportVPDPose`。
- [x] 3.4 在 `CMTToolsManager` 中新增 `ExportVPDPose`，负责创建 `libmmd::VPDFile`、调用 scene manager 填充数据、执行 `WriteVPDFile`、处理写入失败。
- [x] 3.5 在 `OMMDModelManager` 动画分组增加导入 VPD、导出 VPD、注册当前状态、删除当前帧关键帧四个按钮，沿用两列布局。
- [x] 3.6 接通模型管理器按钮命令：VPD 导入/导出作用于当前模型管理器对象，注册/删除操作作用于当前动画槽当前帧。

## 4. 场景校验与姿势采样

- [x] 4.1 增加 `SaveVpdPoseLog`，覆盖选择为空、目标类型错误、写入失败和成功计数提示。
- [x] 4.2 在 `CMTSceneManager` 中新增 `SaveVPDPose`，复用现有导出风格校验 active object 并调用模型管理对象。
- [x] 4.3 在 `MMDModelManagerObject` 中新增 `SaveVPDPose`，填充所有骨骼和 morph 到 `libmmd::VPDFile`。
- [x] 4.4 实现骨骼快照采样：使用 PMX 本地骨骼名，按 VPD 坐标/缩放约定写入当前平移和旋转四元数，包含零姿势骨骼。
- [x] 4.5 实现 morph 快照采样：写入所有 morph 控制器当前强度，包含 0 权重，group/flip 只保存控制器强度而不展开运行时贡献。
- [x] 4.6 确保 EDIT 模式导出当前可编辑姿势，ANIM 模式导出当前文档时间点已求值姿势，导出过程不修改 animation slot、轨道或关键帧。

## 5. 文档与验证

- [x] 5.1 更新 `docs/dev/export-flow.md`，记录 VPD 姿势导出入口、调用链、快照语义和与 VMD 导出的区别。
- [x] 5.2 运行聚焦 libMMD VPD writer 测试，确认 round-trip 通过。
- [x] 5.3 运行插件构建，优先使用 `cmake --build --preset workflow-dev` 或当前 SDK Debug 目标。
- [x] 5.4 在 Cinema 4D 中手工验证 EDIT 和 ANIM 模式 VPD 导出，检查成功报告的骨骼/morph 计数和生成文件可读。
- [x] 5.5 运行 `openspec validate add-vpd-pose-export --strict`，并在实现完成后按实际结果更新任务勾选状态。
