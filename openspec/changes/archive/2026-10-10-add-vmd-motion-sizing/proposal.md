## Why

把来源模型的 VMD 直接套到不同体型的目标模型，会产生移动幅度和中心、脚 IK 位置偏差。需要将 vmd_sizing 的首阶段迁移为可测试的 C++ 核心，并在 C4D 中预览各阶段后提交新动作槽。

## What Changes

- P0：固定上游版本，提供隔离运行原 Cython/Python 实现的基准工具、可再生 PMX/VMD 样例及位移数值回执。
- P1：新增 SDK 无关的 Eigen C++ 核心，支持单角色比例、中心 Y/Z 与脚 IK 横向偏移修正。
- 新增 C4D 工具窗口，后台计算、取消、原始/比例/偏移阶段选择、同目标模型的前后预览、新动作槽提交和 VMD 导出。
- 增加输入校验、未支持项报告、原文档保护、保存重开与 Undo 回归。
- P2：肩臂/躯干绑定姿态补偿、扭转分配及阶段快照。
- P3：刚体运动学避让、手腕/指尖与地面接触及残差报告。
- P4：多角色输入队列、跨角色接触与相机取景调整、独立相机导出。
- P1 维持原实现基准；后续阶段采用明确记录差异的 C++ 约束算法，不能把合成测试称为所有上游模型特例的逐帧等价证明。

## Capabilities

### New Capabilities
- `motion-vmd-sizing`: 可重现的动作适配计算、阶段预览与安全提交。

### Modified Capabilities
无；复用 motion-vmd-motion 已有的导入、动画槽和撤销契约。

## Impact

计算核心迁入 dependency/libMMD，公共接口使用 libmmd::sizing 和 MMDMotionSizing.h；source/module/tools/sizing 保留 C4D 场景适配，UI 独立维护。扩展 libMMD 构建、测试、合成 fixtures 和安装许可，父仓库直接链接 libMMD/Eigen，不在生产插件中嵌入 Python。
