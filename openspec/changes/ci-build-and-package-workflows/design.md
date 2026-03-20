## Context

变更前：仓库曾使用 `msbuild.yml`、`RefactoringMSBuild.yml`（MSBuild / 覆盖面窄）。**现已**由 **`build.yml` + `package.yml`** 替代，并与根目录 **CMake 预设**、**artifact**、**GitHub Release** 对齐。

项目使用 CMake preset 体系（根 `CMakePresets.json`：`dev-windows`、`dev-macos`、`package-windows`、`workflow-release` 等），支持 Windows VS2022 v143 与 macOS Xcode Universal。需在多个 `sdk_*` 上编译以覆盖 Cinema 4D R20～2026。

打包方面，Windows 使用 Inno Setup 6（`setup/Common/installer_script.iss`）打成安装程序，macOS 产物为 `.xdl64` 等文件需打包为 zip。当前打包全部在本地完成。

## Goals / Non-Goals

**Goals:**

- 在合并到主分支时自动编译全平台、多 SDK 版本，确保代码质量
- 将编译产出的二进制产物上传为 artifact，供 package 工作流复用，避免重复编译
- 在推送 tag 时自动打包并上传到 GitHub Release
- tag 发布时在同一 workflow run 内先 **`workflow_call` build** 再打包（不依赖「跨 run 复用 main 上 artifact」）
- 充分复用已有的 CMake preset 体系，避免在 workflow 中硬编码构建命令

**Non-Goals:**

- 不覆盖 Linux 平台（Cinema 4D 不支持 Linux）
- 不涉及插件源码或功能变更
- 不实现自动版本号管理（版本号由 tag 名称或 ISS 定义决定）
- 不实现代码签名（可后续扩展）

## Decisions

### D1: 使用 reusable workflow 实现 build → package 调用链

**选择**：将 build 定义为 `workflow_call` 可调用工作流，package 在需要时通过 `workflow_call` 调用 build。

**备选方案**：

- A) `repository_dispatch`：过于松耦合，无法直接等待完成
- B) 将 build 和 package 合并为一个工作流：tag 事件和 push 事件逻辑混杂，维护困难

**理由**：`workflow_call` 是 GitHub Actions 原生的工作流复用机制，调用方可以直接等待被调用方完成，且 `workflow_call` 触发的工作流可以通过 `outputs` 传递信息。

### D2: 不缓存 `_build` 构建树，仅通过 artifact 传递最终二进制产物

**选择**：**不** 使用 `actions/cache` 缓存 `_build/<sdk_name>` 目录。build 工作流每次全量编译，完成后仅将最终二进制产物（`_build/<sdk>/bin/Release/plugins/mmdtool/` 目录）通过 `actions/upload-artifact` 上传；package 工作流通过 `actions/download-artifact` 下载。

**备选方案**：

- A) 缓存完整 `_build` 目录加速增量编译：每个 SDK 构建树包含大量中间产物（`.obj`、`.pdb`、CMake cache 等），单个 SDK 可达数百 MB 至 GB 级别。多个 SDK × 多平台会迅速耗尽 GitHub Actions 10 GB 的缓存上限，且缓存命中率难以保证。
- B) 使用 cache 传递产物：cache 有分支 scope 限制（仅同分支或默认分支可访问），package 在 tag ref 上运行时存在 scope 问题。

**理由**：
- 最终二进制产物体积小（每个 SDK 仅 `.xdl64` + 资源，几 MB 级别），适合 artifact 传递
- artifact 无分支限制，跨工作流传递可靠
- 全量编译虽然耗时但确保构建一致性，CI 本就运行在推送事件后、无需交互等待

### D4: 根目录 CMake 预设 + 缓存覆盖（与本地一致）

**选择**：CI **不**手写 `cmake -S . -B _build -G ...`，而是与 `DEVELOPMENT.md` 一致使用根 **`CMakePresets.json`**：

1. **Configure**：`cmake --preset dev-windows` 或 `cmake --preset dev-macos`（generator、toolset、Universal、`CMT_SDK_SKIP_VS_A_AND_T` 等均在预设中）。
2. **覆盖矩阵当前 SDK 与 Release**：`-D CMT_SDK_DIR=<repo>/<sdk>`、`-D CMT_SDK_BUILD_CONFIG=Release`（CMake 允许在 `--preset` 后追加 `-D` 覆盖缓存）。
3. **Build**：`cmake --build --preset workflow-release` 或 `workflow-release-macos`（仓库中新增，与 `workflow-dev`/`workflow-dev-macos` 对称，配置为 **Release** 的 `cmt-workflow`）。

矩阵 `include` 仅注入 **`configure_preset`** / **`build_preset`** 名称；YAML 内无 per-OS 的 `-G`/`-A`/`-T` 重复。

**理由**：避免 CI 与本地分叉；`dev-windows`/`dev-macos` 已包含根工程所需变量；Release 用独立 build 预设，避免误用 Debug 的 `workflow-dev`。

**实现补充**：根 `CMakeLists.txt` 中 `cmt-workflow` 调用的 **SDK 子工程** `cmake` 在 **`APPLE` 且 `CMT_SDK_GENERATOR` 为 `Xcode`** 时追加 `-D CMAKE_OSX_ARCHITECTURES=arm64;x86_64`（与 `sdk_*/CMakePresets` 的 `macos_universal_xcode` 一致）。

### D5: SDK 版本矩阵设计 — 全量 SDK 编译

**选择**：

全部 8 个 SDK 都纳入 build 矩阵：`sdk_r20`、`sdk_r21`、`sdk_r23`、`sdk_r25`、`sdk_2023`、`sdk_2024`、`sdk_2025`、`sdk_2026`。所有 SDK 均有统一的 `CMakePresets.json`，支持 `windows_vs2022_v143` 和 `macos_universal_xcode` preset，可在两个平台上通过相同的 CMake 工作流编译。

矩阵中 **`sdk` 列表** 两个平台共用；**`include`** 只选 `dev-windows`+`workflow-release` 或 `dev-macos`+`workflow-release-macos`。

**理由**：
- 各 `sdk_*` 自带 `CMakePresets.json`（`windows_vs2022_v143`、`macos_universal_xcode` 等），与根流程一致
- 全部 SDK 在 build 阶段编完，package 只下载 artifact 并布局 `_build/` 后 Inno / zip
- **并行度**：8 SDK × 2 OS = **16 个 job**；GitHub 组织并发上限会导致排队，但逻辑上仍为全矩阵并行

### D6: Inno Setup 安装

**选择**：在 Windows runner 上使用 Chocolatey（`choco install innosetup`）安装 Inno Setup 6。

**备选方案**：

- A) 手动下载 + 安装：脚本复杂，版本管理困难
- B) 预装在 runner 上：GitHub hosted runner 不预装 Inno Setup

**理由**：Chocolatey 是 Windows runner 上已预装的包管理器，安装快速且版本可控。

### D7: package 与 build 的衔接

**选择**：`package.yml` 在 tag 推送时 **`workflow_call` 可复用的 `build.yml`**，`ref: ${{ github.ref }}`，在同一 workflow run 内先完成全部矩阵 build，再 `download-artifact` 取产物。**未**实现「若 main 上已有同 commit 的 artifact 则跳过 build」的跨 run 优化（可降低重复编译，但需 `gh`/API 查询 run id；可后续迭代）。

**理由**：同 run 内 artifact 与 `download-artifact` 行为明确；先编后发保证 tag 与二进制一致。

## Risks / Trade-offs

- **[全量编译耗时]** build 工作流每次全量编译无增量缓存，单次可能需 20～40 分钟 → CI 在后台异步运行，无需交互等待；且避免了缓存失效导致的不一致问题
- **[矩阵规模]** 8 SDK × 2 平台 = 16 个并行 job，GitHub Actions 免费版并发数有限 → 矩阵 job 会排队等待，但总耗时仍远优于串行编译
- **[Inno Setup 安装耗时]** 每次运行需 ~30s 安装 → 相比完整编译时间可接受
- **[artifact 保留期]** 默认 90 天过期，超期后 package 需重新触发 build → 发版通常在 build 之后短时间内进行，可接受；必要时可调整 retention
- **[macOS 无 Inno Setup]** macOS 产物只能打 zip → 符合 macOS 用户习惯（拖放安装），无需安装程序

