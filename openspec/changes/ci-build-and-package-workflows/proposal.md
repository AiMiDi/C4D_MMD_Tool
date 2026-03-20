## Why

当前项目缺乏统一的 CI/CD 流水线。现有的 `RefactoringMSBuild.yml` 仅针对单个 SDK 版本（2024）在 Windows 上编译，`msbuild.yml` 只覆盖旧版 R 系 SDK；两者均不支持 macOS、不包含缓存机制、无法自动打包发布。每次发布版本都需要开发者在本地手动执行多平台多 SDK 的编译和打包，效率低且容易出错。需要一套完整的自动化 CI 工作流来覆盖全平台构建与发布。

## What Changes

- **新增 `build.yml` 工作流**：在合并到主分支时触发，使用 **矩阵**（`os` × `sdk_*`）在 Windows 与 macOS 上**并行**编译全部 8 个 SDK（共 16 个 job，受组织并发限制可能排队）。构建命令与本地一致：根目录 **`CMakePresets.json`** 的 `cmake --preset dev-windows` / `dev-macos`，用 **`-D CMT_SDK_DIR=<repo>/<sdk>`**、**`-D CMT_SDK_BUILD_CONFIG=Release`** 覆盖当前矩阵单元；再 **`cmake --build --preset workflow-release`** / **`workflow-release-macos`**（Release 下的 `cmt-workflow`）。最终二进制目录上传为 artifact（不缓存 `_build` 整树）。
- **根 `CMakePresets.json`**：新增 **`workflow-release`**、**`workflow-release-macos`** build 预设，与 `workflow-dev`/`workflow-dev-macos` 对称，供 CI 与本地 Release 单 SDK 构建使用。
- **根 `CMakeLists.txt`**：在 `APPLE` 且 `CMT_SDK_GENERATOR` 为 `Xcode` 时，为 SDK 子工程 `cmake` 配置追加 `-D CMAKE_OSX_ARCHITECTURES=arm64;x86_64`，与 `sdk_*/CMakePresets` 的 Universal 行为一致。
- **新增 `package.yml` 工作流**：在推送 `v*` tag 时触发。通过 **`workflow_call`** 复用 `build.yml`（同一 run 内先编再打包），下载 artifact、布局 `_build/` 后跑 Inno Setup、打 macOS zip，并用 **`softprops/action-gh-release`** 发布。
- **废弃旧工作流**：已删除 `msbuild.yml`、`RefactoringMSBuild.yml`。

## Capabilities

### New Capabilities
- `ci-multi-platform-build`: 跨平台（Windows + macOS）多 SDK 版本矩阵编译，产物上传为 artifact
- `ci-release-packaging`: 基于 tag 的自动发布打包（Windows Inno Setup 安装程序 + macOS zip），上传至 GitHub Release

### Modified Capabilities
（无现有 spec 需修改）

## Impact

- `.github/workflows/`：`build.yml`、`package.yml`；`README.md` / `README_zh.md`：CI 徽章指向 `build.yml`
- **`DEVELOPMENT.md` / `DEVELOPMENT_zh.md`**：CI 小节说明与 `CMakePresets.json` 对齐
- **根 `CMakePresets.json`**：新增 `workflow-release`、`workflow-release-macos`
- **根 `CMakeLists.txt`**：Xcode SDK 配置追加 `CMAKE_OSX_ARCHITECTURES`（见上）
- 依赖 GitHub Actions **artifact**（`upload-artifact` / `download-artifact`）与 **`softprops/action-gh-release`**；Windows runner 需 **Inno Setup**（`choco install innosetup`）
- 不涉及 C4D 插件业务逻辑或插件 ID 变更
