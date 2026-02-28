## 1. 轻量 JSON 读写器

- [x] 1.1 在 `refactoring/utils/json_util.hpp` 中实现 header-only 轻量 JSON 解析器：支持从 `std::string` 或 `std::ifstream` 解析 JSON 对象为 `std::unordered_map<std::string, JsonValue>`（`JsonValue = std::variant<bool, int, double, std::string>`），处理 UTF-8 字符串、数字、布尔、null
- [x] 1.2 在同文件中实现 JSON 序列化器：将 map 写出为格式化 JSON 字符串，支持写入 `std::ofstream`
- [x] 1.3 提供文件级便捷函数：`ReadJsonFile(path) -> map` 与 `WriteJsonFile(path, map)`

## 2. 工具配置迁移（CMTToolConfigManager）

- [x] 2.1 修改 `cmt_tools_config_manager.h`：移除 `#include "yaml-cpp/yaml.h"` 与 `YAML::Node m_config`；替换为 `std::unordered_map<std::string, JsonValue>` 类型的 `m_config`；更新 `m_config_path` 扩展名为 `cmt_config.json`；添加 `#include "utils/json_util.hpp"`
- [x] 2.2 修改 `GetConfig<T>()` 模板：从 map 按键查找，用 `std::get<T>()` 取值，替换 `YAML::convert<T>::decode`
- [x] 2.3 修改 `SetConfig<T>()` 与 `InitConfig()`：将值直接写入 map 而非 YAML::Node
- [x] 2.4 修改 `cmt_tools_config_manager.cpp`：`InitConfigManager()` 改用 `ReadJsonFile()` 加载配置；`SaveConfig()` 改用 `WriteJsonFile()` 写出配置

## 3. 名称映射配置迁移（NameConversion）

- [x] 3.1 修改 `cmt_name_conversion_dialog.cpp`：移除 `#include "yaml-cpp/yaml.h"` 与 `YAML::convert<String>` 特化；添加 `#include "utils/json_util.hpp"`
- [x] 3.2 修改 `NameConversion::LoadConfig()`：改用 `ReadJsonFile()` 解析文件，遍历 map 键值对插入查找表
- [x] 3.3 修改 `UpdateNameConversionDialog` 构造函数与相关方法：将文件扩展名过滤从 `.yaml` 改为 `.json`（`CheckSuffix`、`FindIndex`、新建/删除/增量保存路径等所有涉及扩展名的位置）
- [x] 3.4 修改名称映射保存逻辑（新建映射、增量添加）：将输出格式从 YAML 改为 JSON，使用 `WriteJsonFile()`

## 4. 资源文件翻译

- [x] 4.1 将 `res/S24_up/name_conversion/default.yaml` 翻译为 `res/S24_up/name_conversion/default.json`（键值对保持一致）
- [x] 4.2 将 `res/S24_up/name_conversion/UE5.yaml` 翻译为 `res/S24_up/name_conversion/UE5.json`
- [x] 4.3 创建 `res/S24_up/cmt_config.json`（空对象 `{}` 或包含默认键值）
- [x] 4.4 删除旧的 `.yaml` 资源文件（`cmt_config.yaml`、`name_conversion/default.yaml`、`name_conversion/UE5.yaml`）

## 5. 依赖与构建清理

- [x] 5.1 从 `sdk_2026/plugins/mmdtool/project/CMakeLists.txt` 中移除 yaml-cpp 的 include 路径与链接库
- [x] 5.2 确认 `dependency/` 相关构建脚本中 yaml-cpp 不再被编译（如 `init.bat` 或顶层 CMake）
- [x] 5.3 完整编译项目（Debug/Release），确保无 yaml-cpp 相关未解析符号或编译错误
