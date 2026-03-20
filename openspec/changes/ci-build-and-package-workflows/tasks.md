## 1. Build 工作流 — 基础结构

- [x] 1.1 创建 `.github/workflows/build.yml`，定义 `on: push (main) / workflow_dispatch / workflow_call` 触发条件
- [x] 1.2 定义矩阵策略：`os: [windows-latest, macos-latest]` × `sdk: [sdk_r20, …, sdk_2026]`；`include` 注入 `configure_preset`（`dev-windows` / `dev-macos`）与 `build_preset`（`workflow-release` / `workflow-release-macos`）
- [x] 1.3 添加 `actions/checkout@v4`（含 `submodules: recursive`）

## 2. Build 工作流 — 编译步骤

- [x] 2.1 使用根预设：`cmake --preset <configure_preset>` + `-D CMT_SDK_DIR=...` + `-D CMT_SDK_BUILD_CONFIG=Release`；`cmake --build --preset <build_preset>`（`workflow-release` / `workflow-release-macos`）
- [x] 2.2 根 `CMakePresets.json` 新增 `workflow-release`、`workflow-release-macos` build 预设（Release / `cmt-workflow`）
- [x] 2.3 根 `CMakeLists.txt`：Xcode SDK 配置追加 `CMAKE_OSX_ARCHITECTURES`（与 Universal 预设一致）
- [x] 2.4 使用 `actions/upload-artifact@v4` 上传 `_build/<sdk>/bin/Release/plugins/mmdtool/`，artifact 名 `build-${{ runner.os }}-${{ matrix.sdk }}`，保留 7 天

## 3. Package 工作流 — 触发与产物获取

- [x] 3.1 创建 `.github/workflows/package.yml`，定义 `on: push (tags: v*)` 触发条件
- [x] 3.2 同一 run 内 `workflow_call` `build.yml`，`ref: ${{ github.ref }}`，再 `download-artifact`（未实现跨 run 复用 main 上 artifact，见下说明）

> 实现说明：打 tag 时先在同 run 内完成 build，再打包；跨 run 复用 artifact 为可选后续优化。

## 4. Package 工作流 — Windows Inno Setup 打包

- [x] 4.1 Windows job：下载 `build-Windows-*` artifact，布局到 `_build/<sdk>/bin/Release/plugins/mmdtool/`
- [x] 4.2 `choco install innosetup`
- [x] 4.3 从 tag 解析版本，`/DPluginVersion=...` 传给 ISCC（与 `CMakeUserPresets` / `CMT_ISS_EXTRA_ARGS` 思路一致）
- [x] 4.4 ISCC 编译 `setup/Common/installer_script.iss`
- [x] 4.5 上传 `setup/Common/Output/*.exe` 为 artifact

## 5. Package 工作流 — macOS zip 打包

- [x] 5.1 macOS job：下载 `build-macOS-*` artifact
- [x] 5.2 每 SDK 打 zip（插件目录 + `res/S24_up`）
- [x] 5.3 上传 `dist/*.zip` 为 artifact

## 6. Package 工作流 — 发布上传

- [x] 6.1 `release` job 依赖 Windows / macOS 打包 job
- [x] 6.2 下载 installer 与 macOS zips 到统一目录
- [x] 6.3 `softprops/action-gh-release` 创建 Release 并上传产物
- [x] 6.4 Release 标题为 tag 名，body 含 changelog 占位符

## 7. 文档与仓库清理

- [x] 7.1 删除 `.github/workflows/msbuild.yml`、`.github/workflows/RefactoringMSBuild.yml`
- [x] 7.2 更新 `DEVELOPMENT.md` / `DEVELOPMENT_zh.md`（CI、`CMakePresets` 表）、`README.md` / `README_zh.md`（徽章 → `build.yml`）
