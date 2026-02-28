## Context

插件当前通过 yaml-cpp 持久化两类配置：1）工具对话框配置（`cmt_tools_config_manager`，单文件 `cmt_config.yaml`，键为 DLG_CMT_TOOL_* 符号名，值为 bool/int/double）；2）名称映射配置（`cmt_name_conversion_dialog` / `NameConversion`，`name_conversion/*.yaml`，键值均为 UTF-8 字符串的键值对）。

C4D SDK 在不同版本间的 JSON API 差异显著：
- **R20–S24**：`NetworkProtocolJSONInterface`（`parser_json.h`），方法为 `ConvertToJSON()` / `ConvertFromJSON()`，枚举为 `NETWORKPROTOCOLJSONFLAGS`
- **R25–2026**：`ParserInterface`（`parser.h`），方法为 `Read()` / `Write()` / `WriteFile()` / `ReadString()`，通过 `ParserClasses::JsonParser` 创建，枚举为 `PARSERFLAGS`

由于需要支持 C4D R20 到 2026 全版本，使用 SDK JSON API 需要维护两套完全不同的调用代码。更合理的方案是在项目内实现一个轻量 JSON 读写器，完全不依赖 SDK JSON API，从而保证全版本行为一致。

## Goals / Non-Goals

**Goals:**

- 在 `refactoring/utils/` 中实现轻量 JSON 读写器（header-only），替代 yaml-cpp，完成工具配置与名称映射配置的读写。
- 仅支持本项目所需的 JSON 子集：对象（`{}`）、字符串、数字（整数与浮点）、布尔值、null。不需要支持数组。
- 将 `cmt_config.yaml` 与 `name_conversion/*.yaml` 替换为 `.json` 等价物，并翻译资源目录中的默认 YAML 为 JSON。
- 不实现从已有 `.yaml` 的自动迁移；旧 `.yaml` 文件直接忽略。
- 支持 C4D R20 到 2026 全版本，无 SDK JSON API 依赖。

**Non-Goals:**

- 不改变配置的语义（仍为键值表、相同键名与类型）。
- 不实现从 `.yaml` 到 `.json` 的自动迁移。
- 不使用 C4D SDK 的 JSON API（避免多版本适配成本）。
- 不实现通用 JSON 库（不支持数组、嵌套对象等本项目不需要的特性）。

## Decisions

1. **自实现轻量 JSON 读写器**
   - 在 `refactoring/utils/json_util.hpp` 中实现 header-only 的轻量 JSON 读写器。
   - 读取：从 `std::ifstream` 或 `std::string` 解析 JSON 对象为 `std::unordered_map<std::string, JsonValue>`，其中 `JsonValue` 为 `std::variant<bool, int, double, std::string>`。
   - 写出：将上述 map 序列化为格式化 JSON 字符串并写入 `std::ofstream`。
   - **理由**：SDK JSON API 在 R20 和 R25+ 之间签名完全不同（`NetworkProtocolJSONInterface` vs `ParserInterface`），维护两套调用代码的复杂度远超自实现简单 JSON 解析。本项目的配置数据结构极简（单层对象、几种原始类型），自实现代码量小（约 200–300 行），易于维护。
   - **不选 SDK JSON 的理由**：跨版本接口不兼容需要 `#if API_VERSION` 分支，增加构建与测试矩阵复杂度；且 SDK JSON 使用 DataDictionary，需额外处理 Data 类型转换，带来更多版本间差异。

2. **数据模型**
   - 工具配置（`CMTToolConfigManager`）：将 `YAML::Node m_config` 替换为 `std::unordered_map<std::string, JsonValue>`。`GetConfig<T>()` 从 map 按键取值并用 `std::get<T>()` 取出；`SetConfig<T>()` 直接插入/更新 map。
   - 名称映射（`NameConversion`）：读取 JSON 对象后遍历 map，每个 entry 的 key 和 value 均为 `std::string`，转换为 C4D `String`（`SetCString` / UTF-8）后插入查找表。写出时遍历查找表生成 JSON 对象。

3. **配置文件路径与扩展名**
   - 工具配置：`cmt_config.yaml` → `cmt_config.json`（路径仍基于 `GeGetPluginResourcePath()`）。
   - 名称映射：目录仍为 `name_conversion/`，文件扩展名由 `.yaml` 改为 `.json`（如 `default.json`、`UE5.json`）。

4. **yaml-cpp 完整移除**
   - 从 CMake 中移除 yaml-cpp 的 include 路径与链接库配置。
   - 删除所有 `#include "yaml-cpp/yaml.h"` 及 `YAML::` 命名空间引用。
   - 删除 `YAML::convert<String>` 模板特化。
   - 不实现从旧 YAML 的自动迁移，因此无需保留任何 YAML 解析代码。

5. **资源文件翻译**
   - 将 `res/S24_up/` 下的 `cmt_config.yaml`、`name_conversion/default.yaml`、`name_conversion/UE5.yaml` 手工翻译为等价 JSON。
   - 删除旧 `.yaml` 资源文件。

## Risks / Trade-offs

- **[Risk] 轻量 JSON 解析器对 edge case 处理不够（如 Unicode 转义、数字精度）**
  **Mitigation**：本项目配置内容简单且已知（键名为 ASCII，值为简单类型或 UTF-8 原始字符串），不涉及 `\uXXXX` 转义或极端数字；在写出时直接使用 UTF-8 编码，读入时按字节流处理；对已知配置做往返测试覆盖。

- **[Risk] 用户升级后已有 `.yaml` 配置丢失**
  **Mitigation**：在 release notes 中明确说明格式变更；配置文件不存在时自动生成默认值（与现有行为一致），用户功能不受阻。

- **[Trade-off] 自实现 vs SDK JSON**
  自实现多约 200–300 行代码需维护，但换来全版本一致性与零 SDK 依赖。考虑到配置格式极简且稳定，此 trade-off 合理。
