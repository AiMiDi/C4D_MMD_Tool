# C4D MMD Tool

[![](https://img.shields.io/github/downloads/AiMiDi/C4D_MMD_Tool/total)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) [![](https://img.shields.io/github/forks/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/network/members) [![](https://img.shields.io/github/stars/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/stargazers) ![](https://img.shields.io/github/languages/top/AiMiDi/C4D_MMD_Tool) [![](https://img.shields.io/github/last-commit/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/commits/main) [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases)

[![Build](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml/badge.svg)](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/facde953bcc94a0799d045ba0633222d)](https://www.codacy.com/gh/AiMiDi/C4D_MMD_Tool/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=AiMiDi/C4D_MMD_Tool&amp;utm_campaign=Badge_Grade) [![](https://img.shields.io/github/license/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/blob/main/LICENSE.md)

[![](https://img.shields.io/badge/ReadMe-English-green)](README.md)

**开发文档：** [DEVELOPMENT_zh.md](DEVELOPMENT_zh.md) · [English DEVELOPMENT.md](DEVELOPMENT.md)

## 关于

Cinema 4D的mmdtool。

用C ++编写的Cinema 4D插件，用于将MikuMikuDance数据导入Cinema 4D。

![MMD Tool](res/S24_up/mmd_tool_title.png)

## 发行版

插件点击 [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) 下的最新版本下载

目前，主要维护版本为R20及更高版本，R19及以下版本未提供支持。

### 开发者：CMake 构建（多 SDK）

- **基线**：以 `sdk_2026` 根目录的 `CMakePresets.json` 为约定（如 `windows_vs2022_v143`、`linux_ninja`、`macos_universal_xcode`）。公共 Maxon 工具链位于 `sdk_2026/cmake`；各旧版 `sdk_*` 桥接通过 `MAXON_TOOLING_DIR` 指向该目录复用同一套 tooling。
- **依赖**：Bullet3 与 libMMD 通过 `cmake/mmdtool_plugin_dependencies.cmake`（`mmdtool_plugin_dependencies_add`）以 **CMake 子目录 + 目标链接** 并入各 `sdk_*` 工程，**无需**安装到 `dependency/install`。可选根工程：`cmake --preset dev-windows` 后 `cmake --build --preset cmt-deps-build`。libMMD 测试：预设 `dev-windows-deps-test` + `cmake --build --preset cmt-deps-test`，或 `-D CMT_DEPS_ENABLE_LIBMMD_TESTS=ON`。清理：`cmake --build _build_msvc --target cmt-clean-deps`（需已配置根工程；会删除各 `sdk_*` 在 `_build_msvc/<sdk名>/cmt_deps` 下的 Bullet/libMMD 构建树，以及根工程 `dependency/` 子项目产生的 `_build_msvc/cmt_deps`）。若要连插件目标一并清空，可用根目标的 `cmt-clean`。
- **仅生成某 SDK 的工程文件（Windows）**：`configure_sdk.bat sdk_2026 windows_vs2022_v143`（preset 可省略，默认 `windows_vs2022_v143`）。
- **根目录预设 `dev-windows`**：只生成仓库**根**工程 `_build_msvc`（含 `dependency/`、`cmt-workflow` 等），**不包含** `mmdtool` 目标。查看/调试插件请在仓库根下的 **`_build_msvc/<sdk名>/`**（在 `sdk_*` 里执行 preset 时同样输出到此路径）打开解决方案，或先执行 `cmake --build --preset workflow-dev` 生成该目录。
- **根目录一键工作流**（需先配置根工程一次）：
  1. `cmake -S . -B _build_msvc -G "Visual Studio 17 2022" -A x64`
  2. `cmake --build _build_msvc --target cmt-workflow`（依赖 + 配置 + 编译插件；可通过 `-D CMT_SDK_DIR=...` 等变量指向目标 `sdk_*`）
- **典型命令**（仅插件、在某一 `sdk_*` 内；构建树在**仓库根** `_build_msvc/<sdk名>/`）：
  1. `cd sdk_2026`（或目标 `sdk_r25`、`sdk_2024` 等）
  2. `cmake --preset windows_vs2022_v143`
  3. `cmake --build ..\_build_msvc\sdk_2026 --config Debug`（将 `sdk_2026` 换成当前目录名）
- **产物**：Debug 下插件一般在 `_build_msvc/sdk_2026/bin/Debug/plugins/mmdtool/`（相对仓库根；SDK 目录名随版本变化）。
- **Windows 安装包（Inno）**：`setup/Common/installer_script.iss` 直接从各 **`sdk_*\_build_msvc_*\bin\Release\plugins\mmdtool\mmdtool.xdl64`** 与 **`res\R20-S24` / `res\S24_up`** 取文件，**不再使用**根构建目录下的 `release` 收集区。打全量安装包前，请在需要的 **`sdk_r20`～`sdk_r25`、`sdk_2023`～`sdk_2026`** 中分别配置并 **Release** 编译；**不必再编 `sdk_s*`**——旧版 C4D 中 R/S 为同一大版本，S 系与配对 R 系 ABI 兼容，安装程序里 S22/S24/S26 组件复用 **sdk_r21 / sdk_r23 / sdk_r25** 的产物（与 iss 中 `XdlSdkRel` 一致）。若输出目录或配置名不同，可对 ISCC 传 `/DSdkBuildDir=...`、`/DSdkBinConfig=...`（亦可通过 `CMT_ISS_EXTRA_ARGS`）。

若模型导入时勾选多部分出现问题请不要勾选。

**如果安装了插件没有显示，请检查是否C4D安装的为最新小版本（如R21的是R21.207才行，R21.115不显示的升级就可以用）**

## 使用方法

1. 选择相应的插件版本，并将其放置在Cinema 4D安装目录下的plugins文件夹中。
2. 运行Cinema 4D，在菜单->扩展（插件）栏中找到 `MMDTool`，然后单击运行。

### 界面与功能展示

以下截图于 2026-10-06 在 Cinema 4D 2026.4.0 中实机截取，展示当前工作树插件的中文界面。截图仅保留对应的功能区域。各页可上下滚动；已发布版本的界面可能有所不同。

#### 摄像机 · VMD 导入、导出与转换

| 导入与导出 | 摄像机转换 |
| --- | --- |
| ![VMD 摄像机导入与导出面板](docs/images/camera-vmd.png) | ![MMD 摄像机转换选项](docs/images/camera-conversion.png) |

- **导入摄像机**：从 VMD 文件导入摄像机动画，可设置大小缩放和起始偏移。
- **导出摄像机**：将摄像机动画保存为 VMD，可设置大小缩放、起始偏移、旋转曲线与烘焙后导出。
- **转换摄像机**：将普通摄像机转换为 MMD 摄像机，可设置距离和旋转曲线。

#### 动作与姿势 · VMD / VPD

| 动作导入 | 动作导出与姿势 |
| --- | --- |
| ![VMD 动作导入面板及骨骼、表情、模型信息选项](docs/images/motion-import.png) | ![VMD 动作导出和 VPD 姿势导入导出面板](docs/images/motion-export-pose.png) |

- **导入动作**：向模型导入 VMD 骨骼动作、表情动作和模型信息，可设置大小缩放与起始偏移。
- **导入选项**：按本地名称导入、忽视物理骨骼、覆盖先前动画，以及显示详细报告。模型信息包含 IK 开关和模型显示状态。
- **导出动作**：将模型的骨骼动作、表情动作和模型信息保存为 VMD，支持旋转曲线设置与烘焙后导出。
- **姿势**：导入 VPD 姿势，或将选中 MMD 模型当前时间点的姿势导出为 VPD。

#### 模型 · PMX 导入与导出

| 模型导入 | 模型导出 |
| --- | --- |
| ![PMX 模型导入面板及材质转换类型选项](docs/images/model-import.png) | ![PMX 模型导出面板](docs/images/model-export.png) |

- **导入模型**：设置大小缩放，选择多边形、法线、UV、材质、骨骼、权重、IK、付予骨和表情等数据。
- **材质转换类型**：可选择标准材质、RedShift、Octane 或 Corona；使用相应渲染器时需具备对应环境。
- **导入选项**：支持多部分网格、使用英文名称和手动确认英文名称。
- **导出模型**：将选中的 MMD 模型保存为 PMX，可设置大小缩放并选择导出的数据。导出对象需为插件管理的 MMD 模型。

飞书文档: https://fsrjo99ngu.feishu.cn/docs/doccnjnPb8YuNmiVEheSzBj7bSd

## 版本更新

### 未发布 · 架构大重构（2026-10-06）

本轮在 `v0.9.1.20` 之后继续重构插件架构、导入导出和开发流程。以下记录当前工作树的改动，正式发行版本号尚未确定。

1. 拆分模型管理器职责，将 IK/物理运行时重建、每帧求值和表情计算移入独立模块，统一复用 libMMD 的解算与物理接口。
2. 整理 EDIT / ANIM 模式切换：进入动画模式时提交绑定姿态，返回编辑模式时恢复绑定状态；统一处理保存重开、复制和动画槽切换后的运行时重建。
3. 统一骨骼层级与索引同步，父级调整、同层重排、新增和删除骨骼后同步更新引用与选择列表；缓存分层骨骼和 IK 执行计划，减少重复计算。
4. 完善 VMD 动作追加、替换、合并和频道开关，按动画槽独立保存表情、IK 开关及模型显示状态；补齐最终姿态烘焙、缩放转换和导出后的源场景状态恢复。
5. 修正 VMD 摄像机的垂直视场角与单位转换，增加旧相机轨道迁移，完善相机复制、烘焙导出、失败提示和临时对象清理。
6. 整理材质表情的加算/乘算、组合与翻转表情强度计算，完善强度归零、删除表情和编辑模式下的基础材质恢复，并调整标准材质与 Redshift 的材质适配路径。
7. 新增生产 MCP API、16 个有类型工具及 stdio 适配器，覆盖模型检查、PMX/VMD 导入导出、动画槽、模式、物理、表情和帧求值；宿主接入要求 Cinema 4D 2026.4 或更高版本。
8. 统一多 SDK 的源码、资源和公共 CMake 构建层，明确 Debug / Release / 测试预设；插件产物使用真实资源副本，并同步调整 Windows 安装包、macOS 打包和 CI 构建流程。
9. 增加算法测试、确定性输入、C4D 场景回归和带构建身份的验证记录；补充导入、导出、运行时与调试文档，更新中英文 README 的功能截图。

**验收进度：** 部分算法、构建及原生场景回归已有验证记录；生产 MCP 完整流程、真实模型物理重放和跨平台发行验收仍需收尾，后续将随发行验收更新此记录。

以下保留已有历史条目并按版本号倒序排列；未收录的发行版本可查看 [GitHub Releases](https://github.com/AiMiDi/C4D_MMD_Tool/releases)。

### 0.4.6.1

1. 修复导致0.4.6的崩溃问题。
2. 支持S26版本。

### 0.4.6

1. 新增表情hub面板，统一管理所有表情。
2. 新增对组合表情和翻转表情的支持和编辑。
3. 动作导入添加忽略物理骨骼选项。
4. 图标更新（logo图标为临时的，logo图标可能还会再更改）

### 0.4.5.1

修复导入模型面错误的问题。

### 0.4.5

1. 修复保存的文档无法打开的问题。
2. 优化导入模型的IK。
3. 增加导入模型报告。
4. 优化导入速度，稳定性。
5. 修复R23以下版本导入法线反转问题。

### 0.4.4.1

修复导入法线反转的问题。

### 0.4.4

1. 修复多部分导入部分顶点的顶点表情丢失问题。
2. 修复模型有骨骼打开外部亲的情况下，模型无法导入的问题。
3. 兼容旧版本保存的工程。（可能会丢失部分信息，但是不影响工程打开）

### 0.4.3

1. 修复多部分导入时未初始化骨骼导致的崩溃。

2. 改进权重导入。

3. 修复ik列表为空导致的导入失败。

### 0.4.2

1. 添加姿势（vpd）导入。

2. 改进PMX控件。

3. 支持 R25 版本。

### 0.4.1

1. 增加摄像机烘焙导出。

2. 增加动作烘焙导出。

3. 优化Ik.

### 0.4

1. 增加动作导出功能.

2. 修复导入动作捕捉制作动画后动作错乱问题。

3. 将动画导入改为，多线程优化速度。

4. 修复部分曲线问题。

5. 修复一些已知BUG

6. 修复一些可能的内存泄漏问题。

### 0.3.9.1

1. 修复导入动画后卡死问题。

2. 修复一些可能的内存泄漏问题。

### 0.3.9

1. 添加刚体和Joint的支持。（目前物理未实装）

2. 修复GUI滚动条问题。

3. 修复动画曲线不能保存的问题。

4. 增加新的模型管理对象。

5. 增加模型显示过滤系统。

6. 增加IK启用，模型显示动画导入。

7. 修复部分动作导入问题。

### 0.3.8.1

添加工具模块。

~~如果导入动作后模型出现类似下图问题，可以尝试使用工具修复。~~

1. ~~选择模型。~~
2. ~~点击修复动作工具按钮。~~

（v0.4问题修复，已移除）

### 0.3.8

1. 重写了骨骼表情部分。

2. 添加UV表情导入（多部分导入模式）。

3. 修复导入模型的一些错误。

4. 添加对导入模型的无连接顶点的清理功能。

5. 添加摄像机动作的拖拽导入。

6. 预载物理引擎模块支持。

### 0.3.7.5

修复不可旋转骨骼，物理骨骼导入动画的问题。添加UV表情导入（仅多部分导入模式）。

### 0.3.7

修复可能无法加载插件的问题，添加骨骼表情导入。

### 0.3.6

修复多部分导入面错误问题，添加多部分导入顶点表情的功能。

### 0.3.5

修复配置文件造成的卡死和错误，增加多线程安全性，减少崩溃。

### 0.3.4

添加设置记录功能，保存上一次使用配置；更新R20版本。

### 0.3.3

引入YAML配置文件；重写更名英文模块。

![](https://ftp.bmp.ovh/imgs/2021/05/5c6d8897c477f188.jpg)

### 0.3.2

1. 优化导入模型赋予亲的处理方式，确保与MMD中效果相同。

2. 优化导入模型的腿部骨骼问题，确保与MMD中效果相同。

3. 优化了图片alpha通道的检测，修复了材质错误导入透明通道的问题。

4. 增加了代码稳定性，减少了意外的崩溃。

### 0.3.1

完善动作导入和PMX骨骼对象；修复导入模型可能卡死的情况。

### 0.3.0

完善摄像头动作导出功能，支持S24。

### 0.2.9.1

增加了删除摄像机对象关键帧的功能。

### 0.2.9.0

修复了导入模型可能卡住的问题。

### 0.2.8.5

添加用于非多部分模型导入的导入表情功能。

### 0.2.8.3

修复导入动作错误。

### 0.2.8.1

解决导入问题

### 0.2.8

针对多线程导入进行了优化。

### 0.2.3

支持s22版本

### 0.2.2

解决权重导入问题

### 0.2.1

解决权重导入问题和骨骼导入问题

### 0.2.0

初次提交

## 作者

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)

讨论群：790973593
