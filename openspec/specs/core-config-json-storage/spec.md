# Config JSON Storage

## Purpose
Persist tool and name-conversion configuration as repository-managed JSON resources with SDK-compatible parsing and writing.

## Requirements

### Requirement: 轻量 JSON 读写器
系统 SHALL 在 `refactoring/utils/json_util.hpp` 中提供一个 header-only 的轻量 JSON 读写器，支持解析与序列化 JSON 对象。读写器 SHALL 不依赖 C4D SDK JSON API，以保证 R20–2026 全版本兼容。

#### Scenario: 解析 JSON 对象
- **WHEN** 传入一个包含 JSON 对象字符串（如 `{"key": "value", "num": 42}`)
- **THEN** 系统 SHALL 返回一个键值映射，键为 `std::string`，值为 `std::variant<bool, int, double, std::string>`

#### Scenario: 序列化 JSON 对象
- **WHEN** 传入一个键值映射
- **THEN** 系统 SHALL 输出格式化的 JSON 字符串，使用 UTF-8 编码

#### Scenario: 从文件读取 JSON
- **WHEN** 传入一个有效的文件路径
- **THEN** 系统 SHALL 读取文件内容并解析为键值映射

#### Scenario: 将 JSON 写入文件
- **WHEN** 传入键值映射与目标文件路径
- **THEN** 系统 SHALL 将 JSON 写入文件，覆盖已有内容

### Requirement: JSON 工具配置读取
系统 SHALL 通过 JSON 格式文件读取工具配置（`cmt_config.json`），取代之前的 YAML 格式。

#### Scenario: 读取工具配置
- **WHEN** `CMTToolConfigManager::InitConfigManager()` 被调用
- **THEN** 系统 SHALL 从 `GeGetPluginResourcePath() + "cmt_config.json"` 读取 JSON 文件，将其解析为键值对并填充内部配置表

#### Scenario: 配置文件不存在时初始化默认值
- **WHEN** `cmt_config.json` 文件不存在或读取失败
- **THEN** 系统 SHALL 使用 `k_default_config_table` 中的默认值初始化所有配置项，并将默认配置写入 `cmt_config.json`

### Requirement: JSON 工具配置写入
系统 SHALL 将工具配置以 JSON 格式写入磁盘，确保配置持久化。

#### Scenario: 保存工具配置
- **WHEN** `CMTToolConfigManager::SaveConfig()` 被调用
- **THEN** 系统 SHALL 将当前配置以格式化 JSON 写入 `cmt_config.json`，包含所有键值对（bool/int/double）

### Requirement: JSON 名称映射配置读取
系统 SHALL 通过 JSON 格式文件读取名称映射配置（`name_conversion/*.json`），取代之前的 YAML 格式。

#### Scenario: 读取名称映射配置
- **WHEN** `NameConversion::LoadConfig()` 被调用并传入一个 `.json` 文件路径
- **THEN** 系统 SHALL 解析该 JSON 文件（根对象为字符串键值对），将每对键值插入 `local_to_universal_name_lookup_table` 与 `universal_to_local_name_lookup_table`

### Requirement: JSON 名称映射配置写入
系统 SHALL 将名称映射以 JSON 格式写入磁盘。

#### Scenario: 名称映射配置保存
- **WHEN** 用户在名称映射对话框中创建或修改映射后确认保存
- **THEN** 系统 SHALL 将映射表以 JSON 对象格式（字符串键值对）写入对应的 `name_conversion/*.json` 文件

### Requirement: 配置值类型支持
系统 SHALL 支持 bool、int、double 三种值类型的 JSON 序列化与反序列化，与现有 `k_default_config_table` 中的类型保持一致。

#### Scenario: bool 类型往返
- **WHEN** 配置项类型为 bool 且值为 `true`
- **THEN** 写入 JSON 时 SHALL 序列化为 JSON `true`，读回时 SHALL 解析为 C++ `bool` 值 `true`

#### Scenario: int 类型往返
- **WHEN** 配置项类型为 int 且值为 `42`
- **THEN** 写入 JSON 时 SHALL 序列化为 JSON 数字 `42`，读回时 SHALL 解析为 C++ `int` 值 `42`

#### Scenario: double 类型往返
- **WHEN** 配置项类型为 double 且值为 `8.5`
- **THEN** 写入 JSON 时 SHALL 序列化为 JSON 数字 `8.5`，读回时 SHALL 解析为 C++ `double` 值 `8.5`

### Requirement: UTF-8 字符串支持
名称映射配置中的键与值 SHALL 支持完整的 UTF-8 编码（包括日文假名、汉字、拉丁字符），在 JSON 读写过程中不丢失或破坏字符。

#### Scenario: 日文名称映射往返
- **WHEN** 名称映射包含键 `"センター"` 值 `"center"`
- **THEN** 写入 JSON 后重新读取，SHALL 得到完全相同的键值对，无字符损坏

### Requirement: 名称映射文件浏览改用 .json 扩展名
名称映射对话框（`UpdateNameConversionDialog`）在浏览 `name_conversion/` 目录时 SHALL 查找 `.json` 文件而非 `.yaml` 文件。

#### Scenario: 枚举名称映射文件
- **WHEN** 对话框初始化并浏览 `name_conversion/` 目录
- **THEN** 系统 SHALL 仅列出以 `.json` 为扩展名的文件

#### Scenario: 新建名称映射文件
- **WHEN** 用户在对话框中新建名称映射
- **THEN** 系统 SHALL 以 `.json` 扩展名保存新文件

### Requirement: yaml-cpp 依赖移除
变更完成后，项目 SHALL 不再依赖 yaml-cpp 库；所有 `#include "yaml-cpp/yaml.h"` 与 `YAML::` 命名空间引用 SHALL 被移除。

#### Scenario: 编译无 yaml-cpp
- **WHEN** 项目在移除 yaml-cpp 的 include 与链接配置后编译
- **THEN** 编译与链接 SHALL 成功，无未解析符号错误

### Requirement: 默认资源文件为 JSON 格式
`res/S24_up/` 目录下的默认配置资源 SHALL 以 JSON 格式提供，内容与原 YAML 等价。

#### Scenario: 默认工具配置资源
- **WHEN** 插件首次安装且无用户配置
- **THEN** `res/S24_up/cmt_config.json` SHALL 存在且包含所有默认配置键值对

#### Scenario: 默认名称映射资源
- **WHEN** 插件首次安装
- **THEN** `res/S24_up/name_conversion/default.json` 与 `UE5.json` SHALL 存在，内容与原 `default.yaml`、`UE5.yaml` 等价
