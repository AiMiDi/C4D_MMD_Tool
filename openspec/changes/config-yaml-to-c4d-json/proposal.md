## Why

当前插件使用 yaml-cpp 持久化配置（工具对话框配置 `cmt_config.yaml`、名称映射配置 `name_conversion/*.yaml`），带来额外依赖与构建复杂度。C4D SDK 的 JSON API 在 R20–S24（`NetworkProtocolJSONInterface`）与 R25–2026（`ParserInterface`）之间签名完全不同，难以统一使用。因此选择在项目内实现轻量 JSON 读写器，去掉 yaml-cpp 依赖，同时保证 R20–2026 全版本兼容，无需依赖 SDK JSON API。

## What Changes

- 移除对 yaml-cpp 的依赖（CMake/依赖脚本、include、链接）。
- 工具配置：将 `CMTToolConfigManager` 的存储从 YAML 改为 JSON；配置文件从 `cmt_config.yaml` 改为 `cmt_config.json`；读写逻辑改用项目内轻量 JSON 读写器。
- 名称映射配置：将 `UpdateNameConversionDialog` / `NameConversion` 的名称映射从 `name_conversion/*.yaml` 改为 `name_conversion/*.json`，保持「键→值」映射语义与 UTF-8 字符串支持。
- 资源与默认配置：将 `res/S24_up/` 下现有 YAML（如 `cmt_config.yaml`、`name_conversion/default.yaml`、`name_conversion/UE5.yaml` 等）翻译为等价 JSON 并作为新默认资源；删除旧 `.yaml` 文件。
- **BREAKING**：磁盘上的配置格式由 YAML 变为 JSON，旧版生成的 `cmt_config.yaml` 与 `name_conversion/*.yaml` 将不再被读取，不提供自动迁移。

## Capabilities

### New Capabilities

- `config-json-storage`: 使用 JSON 作为唯一持久化格式的工具配置与名称映射配置的读写，包括：项目内轻量 JSON 读写器（header-only，不依赖 SDK JSON API，R20–2026 全版本兼容）、配置文件路径与扩展名（.json）、bool/int/double 及 UTF-8 字符串键值对的序列化/反序列化。

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **修改文件**：`refactoring/cmt_tools_config_manager.h`、`refactoring/cmt_tools_config_manager.cpp`（去掉 yaml-cpp，改为 JSON 读写）；`refactoring/module/ui/cmt_name_conversion_dialog.cpp`（名称映射改为 .json、去掉 YAML 解析与 `YAML::convert<String>`）；`refactoring/cmt_name_conversion_dialog.h`（若存在与 YAML 相关的成员/接口）。
- **资源文件**：`res/S24_up/cmt_config.yaml` → `cmt_config.json`（可为空或默认键值）；`res/S24_up/name_conversion/*.yaml` → `*.json`，内容翻译为等价 JSON。
- **构建与依赖**：从 CMake/依赖列表中移除 yaml-cpp；不再链接 yaml-cpp 库。
- **兼容性**：用户已有 `cmt_config.yaml` 或 `name_conversion/*.yaml` 将被忽略，不做自动迁移；轻量 JSON 读写器不依赖 SDK，R20–2026 全版本兼容。
