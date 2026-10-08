## Why

当前项目的实际活跃代码位于 `refactoring/`，而 `source/` 仍然承载旧版实现，目录语义与真实维护状态已经脱节。同时，依赖构建仍依赖 `init.bat` 等批处理脚本，只有部分 SDK 版本接入了 CMake，导致多版本 SDK 的工程组织、预设、依赖产物和构建入口长期不一致。

现在需要把重构后的代码正式转正为主源码目录，并以 `sdk_2026` 的 CMake 体系和预设为统一基线，为 R20、R21、S22、R23、S24、R25、S26、2023、2024、2025、2026 提供一致的 CMake 组织方式，使项目能够在不依赖批处理的前提下完整构建插件。

## What Changes

- 将 `refactoring/` 转正为新的 `source/`，使主源码目录与当前维护分支保持一致。
- 将现有旧版 `source/` 迁移为 `old/`，明确其为历史归档代码，避免与新源码混用。
- 以 `sdk_2026` 当前的 CMake 结构、目录链接策略和 `CMakePresets.json` 为统一模板，整理整个项目的 CMake 入口。
- 用 CMake 驱动第三方依赖构建与安装流程，逐步取代 `init.bat` 等批处理脚本作为主构建方式。
- 为原生不支持 CMake 的旧 SDK 版本补充“最小可用”的插件工程配置文件，使其能够复用统一源码目录与依赖安装目录完成插件编译。
- 旧版本 SDK 的 CMake 迁移允许参考现有 VS 工程（如 `.vcxproj/.filters/.props`）提取编译定义、包含路径和链接规则；在对应 SDK 的 CMake 构建完整跑通并通过验证后，再移除 VS 工程相关文件。
- 统一多 SDK 版本对资源目录、依赖目录、预设命名和输出行为的约定，降低后续兼容维护成本。
- **BREAKING**：项目源码主目录将从 `refactoring/` 迁移为 `source/`，旧 `source/` 将重命名为 `old/`，所有直接引用旧路径的构建脚本、工程文件和文档都需要同步调整。

## Capabilities

### New Capabilities
- `build-multi-sdk-cmake`: 为全部目标 Cinema 4D SDK 提供统一的 CMake 配置入口、依赖构建流程与预设复用规则。

### Modified Capabilities
- `core-plugin-infrastructure`: 调整主源码目录、旧代码归档目录、资源映射方式以及插件工程对源码路径的解析约定。

## Impact

- 受影响代码与目录：`refactoring/`、`source/`、新增 `old/`、`sdk_*`、`dependency/`、`res/`、`openspec/`、`DEVELOPMENT.md`
- 受影响构建入口：`init.bat`、各 SDK `plugins/mmdtool/project/CMakeLists.txt`、根级或 SDK 级 `CMakePresets.json`
- 受影响工程文件：旧 SDK 下的 VS 工程文件（如 `.vcxproj`、`.vcxproj.filters`、`.props`）将进入“迁移参考 -> 验证后移除”流程
- 受影响依赖系统：bullet3、libMMD 的配置、构建、安装与 Debug/Release 产物发现逻辑
- 受影响开发方式：后续新增 SDK 版本或维护旧 SDK 版本时，需要遵循统一 CMake 预设与目录约定
