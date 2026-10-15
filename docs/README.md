# 文档导航

使用与安装从 [中文 README](../README_zh.md) 或 [English README](../README.md) 进入；构建与目录约定见 [中文开发指南](../DEVELOPMENT_zh.md) / [English development guide](../DEVELOPMENT.md)。

`dev/` 保存持续维护的接口、代码地图和复验方法；`validation/` 只保留动作适配与 PE 同步相关的验收记录；`releases/` 保存版本交付记录。按日期记录的结果只适用于报告中的模块、宿主和输入。

## 开发参考

| 主题 | 文档 |
| --- | --- |
| PMX、VMD、VPD 与相机导入 | [导入流程](dev/import-flow.md) |
| PMX 与姿势导出 | [导出流程](dev/export-flow.md) |
| 动画、模式切换、IK 与物理 | [运行时流程](dev/runtime-flow.md) · [动画诊断](dev/anim-flow-debug.md) |
| 原生回归方法 | [构建、执行与回执说明](dev/regression.md) |
| 材质 | [支持范围](dev/material-support.md) · [Morph Shader](dev/material-morph-shaders.md) · [RS Toon](dev/rs-toon-materials.md) · [RS Standard 高光](dev/rs-standard-specular.md) |
| 生产 MCP | [客户端配置](dev/mcp-client.md) · [协议](dev/mcp-protocol.md) · [实现说明](dev/mcp-support.md) |
| 动作适配 | [功能与质量边界](dev/vmd-sizing.md) · [MCP 接口](dev/motion-sizing-mcp.md) · [数值约定](dev/motion-sizing-numerics.md) |
| 插件更新提醒 | [实现与复验](dev/plugin-update-reminder.md) |

## 验收与发布记录

| 范围 | 入口 |
| --- | --- |
| 动作适配 MCP 首次交付，2026-10-09 | [历史回执](validation/motion-sizing-mcp-20261009/receipt.json) · [后续原生回执](validation/vmd-sizing/advanced-completion/production-native/receipt.json) |
| 动作适配算法、真实角色与交付 | [基础回执](validation/vmd-sizing/validation.json) · [联合发布](validation/vmd-sizing/joint-release-20261010/README.md) · [接触质量](validation/vmd-sizing/contact-quality-20261013/README.md) |
| PE 模型同步 | 本地规范位于 `openspec/changes/add-pe-model-sync/`，回执位于 `docs/dev/validation/pe-sync-*` 与 `pe_sync/validation/` |
| 版本交付 | [发布记录目录](releases/) · [完整更新日志](../CHANGELOG_zh.md) |

## 待完成事项

- 动作适配面板和打包模块的原生验收：[检查清单](dev/vmd-sizing-pending-validation.md)。
- 尚未归档的 OpenSpec 变更：[插件更新提醒](../openspec/changes/add-plugin-update-reminder/) · [源码与构建统一](../openspec/changes/promote-refactoring-source-and-unify-cmake-build/)；PE 模型同步的本地规范见上表。归档前按各自任务与证据核对完成范围。

## 过程文件与空间维护

- 新的临时构建、调试 transcript 和试验输出放在 `S:\tmp\cmt-<任务名>-<日期>/`；体积大或速度不敏感的内容放在 `D:\tmp`。这些目录可能被定期清理；需要持续维护的动作适配、PE 同步回执应保存在相应验证目录中。
- `output/` 用于本地交付与生成产物，由 Git 忽略。私有模型、动作和场景的唯一副本应另行保存。
- 清理 `_build_msvc/` 时，先检查 C4D、调试器和构建进程，并核对 CMake 引用；按明确清单删除可重建缓存和过期构建。保留当前 SDK、共用依赖、打包工具，以及动作适配和 PE 同步仍需复验的模块与证据。
- 已移除的其他验收目录从 Git 历史追溯；历史报告中的本地构建产物路径只记录当时位置。
- SDK 的 `source/`、`res/` 可能是 Junction。盘点和清理时跳过链接，避免遍历到维护源码。
- 移动验收记录时同步更新 Markdown 引用；原始 JSON、日志和 transcript 保留原内容及当时的路径字段。
