# 仓库可靠性与运行时整改

## Why

当前 VMD 导入导出界面存在未接入执行路径的设置，资源输出与文档约定不一致，日常提交缺少自动回归。运行时排序和 ModelManager 职责集中也增加了持续维护成本，需要在同一轮整改中建立可复现的验证链路。

## What Changes

- P0：修复相机导出失败提示、临时对象生命周期，以及动作导入导出开关、模型可见性、动画槽隔离、实际烘焙与缩放。
- P1：输出可独立搬运的资源副本；明确 Debug/Release 预设；PR/main 运行最新 SDK 编译与依赖功能测试，发布使用完整兼容矩阵。
- P1：增加 C4D 场景回归脚本和带构建身份的结果回执，覆盖存档重开、模式、层级、动画槽、物理及材质表情。
- P2：将纯数据计算和转换移出 ModelManager，缓存骨骼分层执行计划，提供阶段耗时诊断；保留场景兼容迁移。
- 校准构建、调试和 OpenSpec 文档。仅凭代码完成不标记原生运行验收通过。

## Capabilities

### New Capabilities

- `runtime-regression-evidence`：可重复执行的 C4D 回归与构建/输入身份结果回执。

### Modified Capabilities

- `motion-vmd-motion`：导入替换/新增/合并语义，模型信息槽持久化，开关生效，最终姿态烘焙与导出单位转换。
- `motion-vmd-camera`：导出结果和提示一致，临时转换与文档时间恢复。
- `build-multi-sdk-cmake`：依赖采用 CMake 子目录目标，运行资源复制、Release 配置和持续验证。

## Impact

影响插件导入导出、ModelManager/BoneManager、公共 CMake、GitHub Actions、资源同步脚本与开发文档。ModelManager 持久化版本追加为 5，保留版本 4 及更早数据的读取。构建工具安装由用户另一个智能体负责；本变更不升级依赖提交。
