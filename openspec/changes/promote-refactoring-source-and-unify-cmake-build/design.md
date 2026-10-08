## Context

当前项目存在三类同时演进但尚未统一的基础设施问题：

1. 源码主目录与真实维护状态不一致。`refactoring/` 承载当前有效代码，但 `source/` 仍保留旧实现，导致 SDK 工程、文档与开发认知长期分裂。
2. 第三方依赖构建仍以 `init.bat` 为主入口。虽然其中已经在内部调用 CMake，但入口、参数约定、产物位置和失败处理都绑定在批处理流程上，不利于跨平台和多预设复用。
3. 多 SDK 版本的工程组织不一致。`sdk_2026` 已具备可复用的 CMake 体系，`sdk_2025` 也已有接近的结构，但更早版本缺少统一的插件 CMake 工程与预设复用方案。

这次变更需要在不改变插件运行时行为的前提下，统一源码目录语义与构建入口，并为 R20、R21、S22、R23、S24、R25、S26、2023、2024、2025、2026 提供一致的构建组织模型。

## Goals / Non-Goals

**Goals:**

- 将重构版代码正式提升为主源码目录 `source/`，并将旧版 `source/` 归档为 `old/`
- 统一所有 SDK 工程对源码目录和资源目录的引用方式
- 复用 `sdk_2026` 的 CMake 组织方式、目录链接策略和预设命名
- 用 CMake 提供依赖库构建与安装主入口，覆盖 bullet3、libMMD
- 为不原生支持 CMake 的旧 SDK 提供“最小可用”的插件工程配置文件，使其可以引用统一源码目录完成插件编译
- 保持 `dependency/install` 作为统一依赖安装根目录，避免插件工程与依赖产物解耦失败

**Non-Goals:**

- 不在本次设计中重写插件运行时逻辑、导入导出流程或对象层级实现
- 不要求一次性清理所有历史 SDK 自带工程文件，只要求建立可维护的 CMake 主路径
- 不要求在本次变更中引入新的外部依赖管理器（如 vcpkg、Conan）
- 不把不同 SDK 的 API 差异直接散落在各模块中，新增兼容逻辑仍应沉淀到 `module/core/cmt_marco.h` 或集中适配层

## Decisions

### 1. 以目录语义迁移取代“继续保留 refactoring 作为事实源码”

**Decision**

将 `refactoring/` 迁移为新的 `source/`，将当前旧版 `source/` 改名为 `old/`。之后所有 SDK 工程、文档、构建配置、源码扫描与资源映射均以新的 `source/` 为准。

**Rationale**

- `source/` 是项目默认语义上的主源码目录，继续把真实源码留在 `refactoring/` 会长期放大认知成本。
- 多 SDK CMake 配置最终都需要约定统一源码根，越早完成目录语义收敛，后续兼容成本越低。
- `old/` 明确表达历史归档语义，避免后续误接入旧代码。

**Alternatives considered**

- 保持 `refactoring/` 为主源码，仅修改文档：不能解决路径分裂问题。
- 把旧源码删除而非归档：迁移风险较高，且不利于回溯与对照。

### 2. 以“公共 CMake 构建层 + 每 SDK 薄封装”组织多版本工程

**Decision**

提炼一个项目级公共 CMake 层，负责：

- 统一源码根、资源根、依赖安装根
- 统一第三方库发现与 Debug/Release 产物命名规则
- 统一插件公共编译定义、包含目录、链接目录与跨平台库搜集逻辑

每个 `sdk_`* 只保留一个薄封装的 `plugins/mmdtool/project/CMakeLists.txt`，负责接入该 SDK 自带 tooling，并把公共参数传入项目级公共层。`sdk_2026` 的结构作为模板，其他 SDK 按“最小差异”适配。

**Rationale**

- `sdk_2026` 已验证可行，继续复制粘贴会造成多份 CMakeLists 长期漂移。
- 公共层能让旧 SDK 只处理“如何挂接 SDK tooling”，而不是重复维护项目逻辑。
- 后续支持新 SDK 时，只需增加薄封装和少量差异变量。

**Alternatives considered**

- 为每个 SDK 维护完整独立 CMakeLists：重复过高，后期难以同步修复。
- 只保留 2026/2025 CMake，旧 SDK 继续用原生工程文件：无法达到统一构建入口目标。

### 3. 依赖构建改为 CMake 主入口，批处理仅保留为兼容包装或淘汰对象

**Decision**

新增项目级依赖构建 CMake 入口，例如独立的 `dependency/CMakeLists.txt` 或顶层 superbuild 配置，用于统一配置、构建并安装 bullet3、libMMD 到 `dependency/install`。`init.bat` 不再作为主路径；若短期保留，则仅作为对 CMake 命令的兼容包装。

**Rationale**

- 当前 `init.bat` 已经把核心逻辑写成串行 CMake 命令，迁移成本主要在入口重组而非依赖工程重写。
- CMake 入口天然更适合与 `CMakePresets.json`、CI、跨平台脚本和 IDE 集成。
- 统一依赖产物目录后，插件工程无需区分“批处理产物”和“CMake 产物”。

**Alternatives considered**

- 保留 `init.bat` 为唯一入口：继续锁定 Windows 和命令脚本，不利于 preset 统一。
- 为每个依赖单独写平台脚本：可维护性更差。

### 4. 旧 SDK 采用“最小可用 CMake 桥接”，不强求完全复制新 SDK 结构

**Decision**

对 R20、R21、S22、R23、S24、R25、S26、2023、2024 采用“最小可用桥接”策略：

- 如果该 SDK 缺少完整现代 CMake 体系，则仅补齐插件项目所需的最小 `CMakeLists.txt`、公共变量桥接和源码/资源路径映射
- 允许不同 SDK 的桥接层在调用 SDK 原生工具链时存在少量差异
- 但必须保证使用同一套 `source/`、`res/`、`dependency/install` 和统一 preset 命名约定

**Rationale**

- 旧 SDK 的原生构建能力差异较大，强行完全统一会推高实现成本。
- 用户目标是“能通过 CMake 完整编译插件”，不是把所有 SDK 改造成同一内部实现。

**Alternatives considered**

- 强制所有 SDK 具备与 2026 完全一致的目录和工具链：成本过高，且部分版本可能不现实。
- 旧 SDK 不纳入统一路径：不满足本次目标。

### 5. 预设命名与默认工作流以 `sdk_2026` 当前约定为基线

**Decision**

保留并推广 `sdk_2026/CMakePresets.json` 中已有的预设命名和生成器风格，例如 `windows_vs2022_v143`、`windows_vs2022_clangcl` 等。其他 SDK 优先复用同名 preset；确有差异时，采用最小增量扩展，而不是重新发明一套命名。

**Rationale**

- 2026 方案已经是项目当前事实标准。
- 统一 preset 名称后，文档、CI、本地开发和自动化脚本都可共享调用约定。

**Alternatives considered**

- 每个 SDK 各自命名 preset：会让用户和脚本必须记忆多套入口。

### 6. 旧 SDK 迁移阶段允许参考 VS 工程，删除动作后置到 CMake 验证完成

**Decision**

旧 SDK 的 CMake 化过程中，允许将现有 VS 工程文件作为迁移参考来源（编译定义、头文件路径、链接库、输出设置）。但 VS 工程相关文件的移除必须在该 SDK 的 CMake 配置与编译流程完整跑通并通过验收后执行，不允许提前删除。

**Rationale**

- 旧 SDK 的工程参数分散在 `.vcxproj/.filters/.props` 中，直接跳过参考会提高漏配风险。
- “先跑通再删除”可以保证迁移期间可回溯，降低一次性切换失败概率。
- 明确删除前置条件后，可以避免不同 SDK 迁移节奏不一致导致的仓库噪音。

**Alternatives considered**

- 迁移开始即批量删除 VS 工程文件：风险过高，排障成本大。
- 永久保留 VS 工程文件：会造成双轨维护，长期增加维护成本。

## Risks / Trade-offs

- [目录重命名会影响现有脚本、IDE 索引和人工习惯] → 通过一次性更新文档、CMake 路径、OpenSpec 和兼容包装脚本来降低切换成本
- [旧 SDK 的 CMake 桥接能力不确定] → 优先定义“最小可用”验收标准，以能产出插件为第一目标，必要时为个别版本保留少量特化逻辑
- [依赖 superbuild 可能引入更长的首次配置时间] → 保持依赖安装目录稳定，并允许分步构建依赖与插件
- [2024/2026 已接入重构代码，迁移中容易出现路径双写或漏改] → 先抽公共路径变量，再逐个 SDK 替换，避免直接散改
- [旧源码归档后仍可能被误引用] → 在 `old/` 文档或目录说明中明确禁止新开发继续引用，并移除其默认构建接入
- [旧 SDK 提前删除 VS 工程文件导致迁移失败难以定位] → 要求每个 SDK 先通过 CMake configure/build 验证，再执行对应 VS 工程文件移除

## Migration Plan

1. 完成目录迁移方案设计并冻结命名：`refactoring/ -> source/`，旧 `source/ -> old/`
2. 抽取项目级公共 CMake 层，统一源码根、资源根、依赖根、链接库收集逻辑
3. 让 `sdk_2026` 先切换到公共层并保持构建通过，作为基线验证
4. 让 `sdk_2025` 对齐同一套公共层与 preset 约定
5. 为 2024 及更早 SDK 逐步补齐最小桥接 `CMakeLists.txt`
6. 提供依赖构建的 CMake 主入口，并将 `init.bat` 降级为兼容包装或移除
7. 针对每个旧 SDK：先以 CMake 流程完成可构建验证，再移除对应 VS 工程相关文件
8. 更新 `DEVELOPMENT.md`、相关构建文档和 OpenSpec 说明，统一开发工作流

**Rollback strategy**

- 如果多 SDK 全量切换出现阻塞，可短期保留 `refactoring/` 到 `source/` 的兼容映射，但不回退“新源码目录是 `source/`”这一命名决策
- 如果依赖 superbuild 在个别平台不可用，可临时保留批处理包装层调用同一组 CMake 命令，避免恢复旧脚本逻辑分叉

## Open Questions

- 旧 SDK 中哪些版本具备可直接复用的 Maxon CMake tooling，哪些版本需要完全自定义桥接层？
- 是否需要在仓库根目录新增统一 `CMakePresets.json`，还是继续以各 `sdk_`* 目录内 preset 为主要入口？
- `old/` 是否需要保留最小只读说明文档，标记其仅供历史参考且不参与默认构建？

