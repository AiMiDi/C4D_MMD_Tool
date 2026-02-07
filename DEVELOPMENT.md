# C4D_MMDTool 项目结构与构建流程

## 项目概述

C4D_MMDTool 是一个 Cinema 4D 插件，用于在 Cinema 4D 中导入和管理 MikuMikuDance (MMD) 模型、动画、相机、刚体、关节等数据。插件支持 PMX/PMD 模型格式和 VMD/VPD 动画格式。

项目支持多个 Cinema 4D SDK 版本（R20 ~ 2026），当前活跃开发在 `refactoring` 分支上，目标 SDK 为 2026。

---

## 目录结构

```
C4D_MMDTool/
├── refactoring/              # 插件源代码（重构版本）
├── source/                   # 旧版插件源代码（已弃用）
├── dependency/               # 第三方依赖库源码
│   ├── bullet3/              #   Bullet 物理引擎
│   ├── libMMD/               #   MMD 文件解析库
│   ├── yaml-cpp/             #   YAML 配置解析库
│   └── install/              #   依赖库编译安装输出 (由 init.bat 生成)
│       ├── include/           #     头文件
│       │   ├── bullet/        #       Bullet 头文件
│       │   ├── glm/           #       GLM 数学库头文件 (libMMD 依赖)
│       │   ├── libMMD/        #       libMMD 头文件
│       │   └── yaml-cpp/      #       yaml-cpp 头文件
│       └── lib/               #     静态库文件 (.lib)
├── res/                      # 插件资源文件
│   ├── R20-S24/              #   R20~S24 版本资源
│   └── S24_up/               #   S24 及以上版本资源（当前使用）
│       ├── c4d_symbols.h     #     C4D 符号定义
│       ├── description/      #     对象/标签描述文件 (.h, .res)
│       ├── dialogs/          #     对话框资源 (.res)
│       ├── mikumikudance_data/ #   MMD 内置数据 (toon 贴图等)
│       ├── name_conversion/  #     名称转换配置 (.yaml)
│       ├── strings_en-US/    #     英文字符串
│       └── strings_zh-CN/    #     中文字符串
├── sdk_2026/                 # Cinema 4D 2026 SDK 工程
│   ├── CMakeLists.txt        #   根 CMake 配置
│   ├── CMakePresets.json     #   CMake 预设 (VS2022 v143/ClangCL)
│   ├── cmake/                #   CMake 工具链脚本
│   ├── frameworks/           #   C4D SDK 框架 (cinema, core, image, math 等)
│   ├── plugins/
│   │   └── mmdtool/
│   │       └── project/
│   │           ├── CMakeLists.txt          # 自定义 CMake 构建配置 (实际使用)
│   │           └── projectdefinition.txt   # 插件身份声明 (仅供参考，不被解析)
│   └── sdk_modules.txt       #   模块路径说明文件
├── sdk_2025/                 # Cinema 4D 2025 SDK 工程
├── sdk_2024/                 # Cinema 4D 2024 SDK 工程
├── sdk_2023/                 # Cinema 4D 2023 SDK 工程
├── sdk_r20/ ~ sdk_s26/       # 更早版本 SDK 工程
├── setup/                    # 安装包脚本 (Inno Setup)
├── init.bat                  # 依赖库编译脚本
└── .github/workflows/        # CI/CD 配置
```

---

## 源代码结构 (`refactoring/`)

```
refactoring/
├── main.cpp                          # 插件入口 (PluginStart/Stop/Message)
├── register_entity.cpp/.h            # 实体注册 (对象、标签等)
├── plugin_resource.h                 # 插件资源 ID
├── CMTSceneManager.cpp/.h            # 场景管理器 (PMX/VMD 导入核心逻辑)
├── cmt_tools_manager.cpp/.h          # 工具管理器
├── cmt_tools_config_manager.cpp/.h   # 配置管理器 (yaml 配置读写)
├── cmt_tools_setting.h               # 工具设置
├── module/
│   ├── core/
│   │   └── cmt_marco.h              # 公共宏定义和类型别名
│   ├── tools/
│   │   ├── loader/
│   │   │   └── vmd_loader.cpp/.h    # VMD 动画加载器
│   │   ├── mmd_material.cpp/.h      # MMD 材质处理
│   │   ├── object/                  # C4D 对象插件
│   │   │   ├── mmd_manager.hpp      # 管理器基类模板
│   │   │   ├── mmd_model_manager.*  # MMD 模型管理器
│   │   │   ├── mmd_bone_manager.*   # 骨骼管理器
│   │   │   ├── mmd_mesh_manager.*   # 网格管理器
│   │   │   ├── mmd_joint_manager.*  # 关节管理器
│   │   │   ├── mmd_rigid_manager.*  # 刚体管理器
│   │   │   ├── mmd_joint.*          # MMD 关节对象
│   │   │   ├── mmd_rigid.*          # MMD 刚体对象
│   │   │   ├── mmd_morph.*          # MMD 变形对象
│   │   │   └── mmd_camera.*         # MMD 相机对象
│   │   └── tag/
│   │       └── mmd_bone.*           # MMD 骨骼标签
│   └── ui/
│       ├── cmt_tools_dialog.*            # 主工具对话框
│       ├── cmt_name_conversion_dialog.*  # 名称转换对话框
│       └── vmd_loader_camera_dialog.*    # VMD 相机导入对话框
└── utils/                            # 工具函数 (header-only)
    ├── filename_util.hpp
    ├── images_user_area_util.hpp
    ├── io_util.hpp
    ├── math_util.hpp
    ├── morph_ui_data_util.hpp
    ├── pmx_util.hpp
    ├── string_util.hpp
    ├── time_util.hpp
    └── unique_id_util.hpp
```

### 源代码依赖关系

源代码的外部依赖 `#include` 模式：

| 依赖库     | Include 模式                                    | 示例                                                |
| ---------- | ----------------------------------------------- | --------------------------------------------------- |
| libMMD     | `#include "libMMD/Model/MMD/xxx.h"`             | `#include "libMMD/Model/MMD/PMXFile.h"`             |
| yaml-cpp   | `#include "yaml-cpp/yaml.h"`                    | `#include "yaml-cpp/yaml.h"`                        |
| glm        | `#include <glm/...>` (通过 libMMD 头文件间接引用) | `#include <glm/gtc/quaternion.hpp>` (在 PMXFile.h 中) |
| C4D 资源   | `#include "description/xxx.h"`                  | `#include "description/OMMDBoneManager.h"`          |
| C4D 符号   | `#include <c4d_symbols.h>`                      | `#include <c4d_symbols.h>`                          |

> 注：Bullet 物理引擎仅在 libMMD 的 `.cpp` 文件中使用，插件源代码不直接包含 Bullet 头文件。但由于 libMMD 是静态库且私有链接 Bullet，插件链接时需要同时链接所有 Bullet 组件。

---

## 第三方依赖 (`dependency/`)

### 依赖关系图

```
C4D_MMDTool (插件)
├── libMMD (静态库) - MMD 文件格式解析
│   ├── Bullet Physics (静态库, PRIVATE) - 物理模拟
│   │   ├── BulletDynamics
│   │   ├── BulletCollision
│   │   ├── BulletSoftBody
│   │   ├── BulletInverseDynamics
│   │   ├── Bullet3Common
│   │   └── LinearMath
│   └── GLM (header-only, PUBLIC) - 数学库
├── yaml-cpp (静态库) - YAML 配置解析
└── Cinema 4D SDK (框架)
    ├── cinema.framework
    ├── core.framework
    ├── image.framework
    └── math.framework
```

### 依赖库版本

| 库名       | 类型     | 版本   | 说明                           |
| ---------- | -------- | ------ | ------------------------------ |
| bullet3    | 静态库   | 3.27   | 物理引擎，libMMD 私有依赖       |
| libMMD     | 静态库   | -      | MMD 格式解析，git submodule     |
| yaml-cpp   | 静态库   | -      | YAML 解析，git submodule        |
| GLM        | 纯头文件 | -      | 数学库，libMMD 的 external 子模块 |

### 编译输出命名规则

所有依赖库使用 `CMAKE_DEBUG_POSTFIX="_Debug"`：

| 库                    | Release           | Debug                    |
| --------------------- | ----------------- | ------------------------ |
| libMMD                | `libMMD.lib`      | `libMMD_Debug.lib`       |
| BulletDynamics        | `BulletDynamics.lib` | `BulletDynamics_Debug.lib` |
| BulletCollision       | `BulletCollision.lib` | `BulletCollision_Debug.lib` |
| BulletSoftBody        | `BulletSoftBody.lib` | `BulletSoftBody_Debug.lib` |
| BulletInverseDynamics | `BulletInverseDynamics.lib` | `BulletInverseDynamics_Debug.lib` |
| Bullet3Common         | `Bullet3Common.lib` | `Bullet3Common_Debug.lib` |
| LinearMath            | `LinearMath.lib`  | `LinearMath_Debug.lib`   |
| yaml-cpp              | `yaml-cpp.lib`    | `yaml-cpp_Debug.lib`     |

---

## 构建流程

### 前置条件

- Visual Studio 2022（v143 工具集）
- CMake >= 3.30
- Python 3（用于 Cinema 4D Source Processor）
- Cinema 4D 2026 SDK 框架文件（放在 `sdk_2026/frameworks/` 下）

### 第一步：编译依赖库

运行 `init.bat` 编译所有第三方依赖：

```bat
# 编译 Debug 和 Release（默认）
init.bat

# 仅编译 Debug
init.bat Debug

# 仅编译 Release
init.bat Release
```

`init.bat` 执行流程：
1. 初始化 git submodule
2. 设置 MSVC 环境变量 (vcvars64.bat)
3. 清空 `dependency/install/` 目录
4. 编译并安装 bullet3 → `dependency/install/`
5. 编译并安装 yaml-cpp → `dependency/install/`
6. 编译并安装 libMMD → `dependency/install/`

编译完成后：
- 头文件安装到 `dependency/install/include/`
- 库文件安装到 `dependency/install/lib/`

### 第二步：CMake 配置与构建

```bat
cd sdk_2026

# 使用 VS2022 v143 预设配置
cmake --preset windows_vs2022_v143

# 构建 Debug
cmake --build _build_v143 --config Debug

# 构建 Release
cmake --build _build_v143 --config Release
```

或直接用 Visual Studio 打开 `sdk_2026/_build_v143/c4d-sdk.sln`。

> 不需要手动创建符号链接。自定义 `CMakeLists.txt` 通过 `maxon_targetSourceDirectories` 直接引用
> `refactoring/` 和 `res/S24_up/` 的相对路径，构建系统自动处理文件扫描和 include 路径收集。

---

## Cinema 4D 2026 SDK 构建系统

### 概述

2026 SDK 使用 CMake 构建系统（不再使用旧版 Project Tool 生成 .vcxproj）。构建系统根据每个模块的配置生成对应的 CMake 目标。

### 模块发现流程

1. CMake 根配置读取 `MAXON_SDK_MODULES_DIR`（默认为 `plugins/`）
2. 如果存在 `custom_paths.txt`，从中读取模块路径（需 `MODULE` 关键字）
3. 否则自动扫描 `plugins/` 下的目录
4. 在每个模块目录中搜索 `projectdefinition.txt`（最多 3 层深度）
5. 对于找到的每个 `projectdefinition.txt`，检查同目录下是否有 `CMakeLists.txt`

### 构建配置方式：自定义 CMakeLists.txt vs projectdefinition.txt

构建系统支持两种配置方式（见 `sdk_update_projects.cmake` 第 960 行）：

**方式 A（本项目使用）：自定义 `CMakeLists.txt`**

当 `project/` 目录下存在 `CMakeLists.txt` 时，构建系统**直接加载**该文件，`projectdefinition.txt` **不被解析**。
这允许完全控制 CMake 变量，尤其是 `maxon_targetSourceDirectories`——可以指向项目内的任意目录。

```cmake
# 在 configure 阶段自动创建 Junction，将 source/ 和 res/ 指向实际位置
MaxonTargets_CreateDirectoryLink(PATH ${MODULE_ROOT_DIR}/source TARGET ${PROJECT_ROOT_DIR}/refactoring)
MaxonTargets_CreateDirectoryLink(PATH ${MODULE_ROOT_DIR}/res    TARGET ${PROJECT_ROOT_DIR}/res/S24_up)

# 使用标准源目录名（通过 Junction 解析到实际路径）
set(maxon_targetSourceDirectories source res)
```

Junction 的创建是幂等的——如果已存在且指向正确目标则跳过，指向错误则自动重建。`MaxonTargets_CreateDirectoryLink` 是 SDK 自带函数（`sdk_targets.cmake`），在 Windows 上使用 `mklink /J`（无需管理员权限），在 macOS/Linux 上使用符号链接。

这样做的原因是 `sdk_targets.cmake` 中的 `source_group(TREE ...)` 要求所有源文件路径必须在模块根目录之下，直接用 `../../../refactoring` 这样的外部路径会导致 CMake configure 报错。

**方式 B（SDK 默认）：自动生成**

当只有 `projectdefinition.txt` 而没有 `CMakeLists.txt` 时，构建系统解析 `projectdefinition.txt` 并基于 `sdk_library_template.cmake` 模板自动生成 `CMakeLists.txt` 到构建目录。此模式下源目录同样硬编码为 `source` 和 `res`，需要手动创建符号链接。

### projectdefinition.txt → CMake 变量映射参考

以下映射关系仅在**方式 B（自动生成）** 时有效。方式 A 的 CMakeLists.txt 中直接设置这些 CMake 变量。

| projectdefinition.txt 键             | CMake 变量                                    | 说明                     |
| ------------------------------------ | --------------------------------------------- | ------------------------ |
| `Type`                               | `maxon_targetType`                             | `Lib`=静态库, `DLL`=动态模块 |
| `APIS`                               | `maxon_targetFrameworkDependencies`             | SDK 框架依赖              |
| `C4D=true`                           | 添加 `USE_API_MAXON` 定义                       | 启用经典 API 支持         |
| `AdditionalIncludeDirectories`       | `maxon_additionalIncludeDirectories.WINDOWS`    | Windows 头文件搜索路径    |
| `USER_HEADER_SEARCH_PATHS`           | `maxon_additionalIncludeDirectories.MACOS`      | macOS 头文件搜索路径      |
| `AdditionalLibraryDirectories`       | `maxon_additionalLinkDirectories.WINDOWS`       | Windows 库文件搜索路径    |
| `AdditionalDependencies.Win64.Debug` | `maxon_linkLibraries.WINDOWS.DEBUG`             | Windows Debug 链接库      |
| `AdditionalDependencies.Win64.Release`| `maxon_linkLibraries.WINDOWS.RELEASE`          | Windows Release 链接库    |
| `ExceptionHandling`                  | `maxon_enableExceptionHandling`                 | 异常处理开关              |

### 路径变量

`projectdefinition.txt` 中可使用以下变量（自动生成模式下由 `MaxonUpdateProjects_ReplacePathPlaceholders` 转换）：

| 变量                              | 解析值                        | 说明             |
| --------------------------------- | ----------------------------- | ---------------- |
| `$(MAXON_SDK_ROOT_DIR)`           | `sdk_2026/`                   | SDK 根目录       |
| `$(MAXON_SDK_CURRENT_MODULE_DIR)` | `sdk_2026/plugins/mmdtool/`   | 当前模块目录     |
| `$(MAXON_SDK_BUILD_DIR)`          | CMake 构建输出目录             | 构建目录         |

在自定义 CMakeLists.txt 中，直接使用 CMake 变量 `${MAXON_SDK_ROOT_DIR}` 即可。

### 源文件扫描机制

`maxon_targetSourceDirectories` 中指定的目录会被 `MaxonTargets_CreateFileList` 递归扫描（`file(GLOB_RECURSE ... FOLLOW_SYMLINKS)`），扫描基于模块根目录（`targetSourceRoot`，即 `sdk_2026/plugins/mmdtool/`）。

扫描后，`MaxonTargets_CollectIncludeDirectories` 自动将包含源文件的目录添加为 include 路径，因此：
- `refactoring/` 内部的相对 include（如 `#include "module/tools/tag/mmd_bone.h"`）自动解析
- `res/S24_up/` 中的资源 include（如 `#include "description/OMMDBoneManager.h"`、`#include "c4d_symbols.h"`）自动解析

### 构建输出

- 插件动态库输出到 `sdk_2026/_build_v143/bin/{Debug|Release}/plugins/mmdtool/`
- 输出文件扩展名：Windows 为 `.xdl64`，macOS 为 `.xlib`
- `res/` 目录会通过符号链接映射到输出目录的 `res/` 下

---

## 配置文件说明

### `CMakeLists.txt`（实际构建配置）

位于 `sdk_2026/plugins/mmdtool/project/CMakeLists.txt`，构建系统检测到此文件后直接加载。

关键配置项：

```cmake
# 自动创建 Junction（configure 阶段，幂等操作）
MaxonTargets_CreateDirectoryLink(PATH .../source TARGET .../refactoring)
MaxonTargets_CreateDirectoryLink(PATH .../res    TARGET .../res/S24_up)

# 标准源目录（通过 Junction 解析）
set(maxon_targetSourceDirectories source res)

# 头文件搜索路径（覆盖 libMMD、yaml-cpp、glm 的 include）
set(maxon_additionalIncludeDirectories.WINDOWS ${DEPENDENCY_INSTALL_DIR}/include)

# 库文件搜索路径
set(maxon_additionalLinkDirectories.WINDOWS ${DEPENDENCY_INSTALL_DIR}/lib)

# 链接库列表（自动从 install/lib/ 收集，按 _Debug 后缀分拣 Debug/Release）
file(GLOB _ALL_LIBS "${DEPENDENCY_INSTALL_DIR}/lib/*.lib")
# → Debug: *_Debug.lib   Release: 其余 *.lib
```

### `projectdefinition.txt`（仅供参考）

位于同一目录，由于 `CMakeLists.txt` 存在而**不被构建系统解析**。仅保留插件基本身份信息（类型、框架依赖、ModuleId）作为人类可读的参考。

### CMake 预设 (`CMakePresets.json`)

| 预设名                       | 生成器                    | 工具集    | 说明             |
| ---------------------------- | ------------------------- | --------- | ---------------- |
| `windows_vs2022_v143`        | Visual Studio 17 2022     | v143      | MSVC 编译（推荐） |
| `windows_vs2022_clangcl`     | Visual Studio 17 2022     | ClangCL   | Clang-CL 编译    |
| `macos_universal_xcode`      | Xcode                     | -         | macOS 通用二进制  |
| `linux_ninja`                | Ninja Multi-Config        | -         | Linux 构建        |

---

## 快速上手

```bat
# 1. 克隆仓库并初始化子模块
git clone --recursive <repo-url>
cd C4D_MMDTool

# 2. 编译第三方依赖
init.bat

# 3. CMake 配置
cd sdk_2026
cmake --preset windows_vs2022_v143

# 4. 构建
cmake --build _build_v143 --config Debug

# 5. 用 VS 打开 (可选)
start _build_v143\c4d-sdk.sln
```

> 无需手动创建符号链接——`CMakeLists.txt` 在 CMake configure 阶段自动创建 Junction。
