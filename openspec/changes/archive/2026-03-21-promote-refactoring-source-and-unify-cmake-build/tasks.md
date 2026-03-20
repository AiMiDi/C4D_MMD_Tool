## 1. 目录转正与路径清点

- [x] 1.1 盘点所有直接引用 `refactoring/`、`source/`、`res/S24_up`、`dependency/install` 的构建脚本、文档与 SDK 工程文件
- [x] 1.2 将当前旧版 `source/` 迁移为 `old/`，并将 `refactoring/` 转正为新的 `source/`
- [x] 1.3 更新项目文档与目录说明，明确 `source/` 为主源码目录、`old/` 为历史归档目录

## 2. 抽取公共 CMake 构建层

- [x] 2.1 从 `sdk_2026/plugins/mmdtool/project/CMakeLists.txt` 提炼公共源码根、资源根与依赖根变量
- [x] 2.2 抽取第三方库发现、Debug/Release 产物收集和公共编译定义逻辑到项目级公共 CMake 模块
- [x] 2.3 让 `sdk_2026` 改为通过公共 CMake 层构建，并验证其仍能完整生成插件

## 3. 替换依赖批处理为 CMake 工作流

- [x] 3.1 为 bullet3、libMMD 新增统一的依赖构建 CMake 入口，并保持产物安装到 `dependency/install`
- [x] 3.2 将 libMMD 测试接入新的依赖构建工作流，保留可选测试开关与失败中断行为
- [x] 3.3 将 `init.bat` 降级为对新 CMake 工作流的兼容包装，或在文档中正式废弃其主入口角色

## 4. 对齐现代 SDK 工程

- [x] 4.1 让 `sdk_2025` 复用与 `sdk_2026` 一致的 preset 命名和公共 CMake 层
- [x] 4.2 补齐 `sdk_2024` 的插件 CMake 工程，使其使用新的 `source/` 与统一依赖目录完成构建
- [x] 4.3 校验 2024、2025、2026 三个版本在默认文档工作流下都能完成配置与插件编译

## 5. 补齐旧 SDK 最小桥接层

- [x] 5.1 为 R20、R21、S22、R23、S24、R25、S26、2023 设计最小可用 CMake 桥接模板
- [x] 5.2 迁移各旧 SDK 时参考现有 VS 工程（`.vcxproj/.filters/.props`）提取必要编译与链接配置（已落实到各 `sdk_*/cmake/sdk_compat_*.cmake` 与编译选项）
- [x] 5.3 按 SDK 版本补充各自的插件 `CMakeLists.txt` 或桥接配置，并统一指向 `source/`、共享资源目录和 `dependency/install`
- [x] 5.4 为旧 SDK 的特殊 API 或工具链差异补充集中式兼容处理，避免在业务代码中散落版本特判（`source/module/core/cmt_marco.h`、条件注册文件、`sdk_*/frameworks/...` 必要补丁等）
- [x] 5.5 对每个旧 SDK 执行 CMake configure/build 验证，并记录通过结果（本地已验证：2023/2024/2025/2026、S26、R20–R25、S24 等 Debug 配置可生成 `mmdtool`；记录见本变更设计/实施笔记）
- [ ] 5.6 在对应 SDK 的 CMake 验证通过后，移除该 SDK 的 VS 工程相关文件（**待仓库维护者确认无回归后再执行，避免先删后验**）

## 6. 预设、验证与交付

- [x] 6.1 统一并补全文档中的 CMake 预设使用方式，明确以 `sdk_2026` 当前预设约定为基线（已写入 `README_zh.md`「开发者：CMake 构建」）
- [ ] 6.2 复核 VS 工程移除顺序与验证记录一致，确保无“先删后验”情况（与 5.6 联动，待执行移除时勾选）
- [x] 6.3 更新 OpenSpec 文档与实施记录，确保后续 `/opsx:apply` 可以按任务顺序推进实现
