# C4D_MMDTool — Project Structure and Build Guide

**Language / 语言：** [中文](DEVELOPMENT_zh.md) | English

---

## Build workflow

### CI (GitHub Actions)

- **`.github/workflows/build.yml`** — PRs and pushes to `main` compile `sdk_2027` Release on Windows 2022. CI does not execute automated tests or benchmarks; the local test presets below remain available. Manual dispatch and tag release calls run the complete **24-job Release matrix** (nine Windows, nine Intel macOS, six Apple Silicon SDKs). The matrix uses `release-windows` / `release-macos` configure presets with test targets disabled. Windows and Intel macOS upload complete plugin artifacts; Apple Silicon jobs compile only. Dependency caches include toolchain versions, architectures, build options, and nested submodule revisions.
- **`.github/workflows/package.yml`** — On tag `v*`: first selects a successful full Build run with matching runtime/build inputs, or calls `build.yml` when none is reusable. It lays out complete Windows artifacts under `_build_msvc/` for Inno Setup, zips each complete macOS artifact once (including its existing `res/`), and creates a **GitHub Release**. Packaging consumes built resources and does not add a second nested resource directory.

Reuse verifies all 24 matrix jobs and all 18 unexpired SDK artifacts, including source commits and digests. It accepts a successful standalone Build or a completed Package whose own build matrix and input checks all succeeded, even if packaging subsequently failed. A Package that reused artifacts cannot serve as their source. Files under `docs/`, explicitly listed documentation/packaging files and the two `res/*/cmt_version.txt` files may differ; packaging stamps the final version again. Source, other resources, compiler configuration, SDKs and dependency gitlinks must match. CI saves `package-build-provenance.json`. Manual package dispatch accepts an optional `build_run_id` from either workflow; an incompatible explicit run fails rather than silently rebuilding. With the input empty, selection is automatic and a fresh matrix is the fallback. Manual dispatch produces package artifacts; formal releases remain tag-triggered. Local provenance regressions: `python tests/test_package_build_reuse.py`.

For an installer-only repair, manual dispatch can set `windows_only=true` together with the original `build_run_id` and release `version`; this skips macOS packaging and produces a Windows artifact for review. The installer adapter and its focused fixtures are packaging-only inputs. The adapter keeps the supported version tables and year-based registry detection in sync, including C4D 2027. Run `pwsh -NoProfile -File scripts/check_installer_resources.ps1`; add `-PinnedInstallerPath setup/Common/installer_script.iss` to check the pinned setup template too.

Local packaging with Inno still uses `package-windows` + `inno-installer` / `CMakeUserPresets.json` as described below.

### Prerequisites

- Visual Studio 2022 (v143 toolset)
- CMake >= 3.30
- Python 3 (for the Cinema 4D Source Processor)
- PowerShell 7 (`pwsh`) on Windows (for safe resource synchronization)
- Cinema 4D 2026 SDK frameworks under `sdk_2026/frameworks/`

### Step 1: Third-party dependencies (optional root workflow)

**Normal plugin development** does **not** require a separate dependency step: configuring any `sdk_*` with CMake runs `mmdtool_plugin_dependencies_add()` and builds Bullet3 + libMMD as part of the plugin target.

To **smoke-test** the `dependency/` subproject from the **repository root** (same idea as the optional `cmt-deps-build` path used in CI):

```bash
git submodule update --init --recursive
cmake --preset dev-windows
cmake --build --preset cmt-deps-build
```

**libMMD unit tests** (CTest) are **off** by default. Turn them on via cache or preset:

```bash
cmake --preset dev-windows-deps-test
cmake --build --preset cmt-deps-test
cmake --build --preset cmt-plugin-tests
```

Or: `cmake -S . -B _build_msvc -D CMT_DEPS_ENABLE_LIBMMD_TESTS=ON` then `cmake --build _build_msvc --target cmt-deps-test`.

Functional tests exclude `benchmark` / `performance` labels. Run the independent benchmark target with `cmake --build --preset cmt-deps-benchmark`. `CMT_DEPS_TEST_CONFIG` defaults to Debug and must match the built configuration. SDK-independent plugin algorithm tests are enabled by `CMT_ENABLE_PLUGIN_TESTS=ON` (the dependency-test preset enables it); they can also be configured directly from `tests/`.

Headers/libs for the plugin come from the source tree (`dependency/bullet3/src`, `dependency/libMMD/src`, `dependency/libMMD/external/eigen`) and CMake targets (`libMMD`, Bullet static libs). Legacy **install-prefix** mode remains available as `DEPENDENCY_MODE INSTALL` + `DEPENDENCY_INSTALL_DIR` in `mmdtool_plugin_common.cmake`.

### Root `CMakeLists.txt`: presets and “config files”

The repository-root CMake wires dependencies, `sdk_*` plugin builds, and optional Inno targets. Common ways to set cache variables (can be combined; later values override earlier ones):

| Method | Description |
|--------|-------------|
| **`CMakePresets.json`** (recommended) | Root provides **configurePresets** such as `dev-windows`, `dev-windows-deps-test` (sets `CMT_DEPS_ENABLE_LIBMMD_TESTS`), `package-windows`, `dev-linux`, and `dev-macos`; **buildPresets** include `cmt-deps-build`, `cmt-deps-test`, `workflow-dev`, `workflow-configure-all-sdks`, `workflow-release`, `workflow-release-macos`, and `inno-installer`. The root workflow requires CMake ≥ 3.23; the primary 2026 SDK requires CMake ≥ 3.30. |
| **`CMakeUserPresets.json`** (local, not committed) | Listed in `.gitignore`. Copy `CMakeUserPresets.SAMPLE.json` to `CMakeUserPresets.json`, `inherits` `package-windows`, then override the local **ISCC** path and Inno macros such as `/DPluginVersion=...`, `/DSdkBuildDir=...`. |
| **Initial cache `-C`** | Edit copies of `cmake/initial_cache/dev.example.cmake` or `package.example.cmake`, then: `cmake -S . -B _build_msvc -C cmake/initial_cache/your_file.cmake`. Handy for scripts and CI. |

Examples (Windows, development):

```bash
cmake --preset dev-windows
cmake --build --preset workflow-dev
```

Examples (Windows, packaging + Inno):

```bash
cmake --preset package-windows
cmake --build --preset inno-installer
```

To build a Release plugin without Inno, run `cmake --preset release-windows` then `cmake --build --preset workflow-release`; macOS uses `release-macos` / `workflow-release-macos`. Configure first: selecting a Release build preset does not update `CMT_SDK_BUILD_CONFIG` in an existing Debug cache.

Target **`cmt-package`** (built by **`inno-installer`**) builds shared prebuilt dependencies, then configures and Release-builds **all eight** SDK trees before it invokes Inno (ISCC). `workflow-package` only configures and builds the selected `CMT_SDK_DIR` with the package preset; use it when you need that Release plugin but not an installer.

For a full multi-version installer, let `inno-installer` build all SDK trees; it passes the resulting Release paths to `installer_script.iss`.

`CMT_ISS_EXTRA_ARGS` is split and passed to ISCC so you can pass `/DPluginVersion=...` without editing `installer_script.iss`.

Before ISCC, the default local target and Windows CI run `cmake/prepare_installer_resources.ps1`. It adapts the pinned setup submodule's old resource Source to the matching built SDK resources, accepts an already adapted Source without writing, and rejects ambiguous layouts. This makes packaging portable with the existing submodule pointer. A custom `CMT_ISS_MAIN` is exempt and must manage its own complete resource sources. The preparation script preserves the default installer's other content and line endings; `scripts/check_installer_resources.ps1` exercises the pinned-source, idempotence, and rejection contract.

### Step 2: Configure and build the SDK project

The `sdk_*` `CMakePresets.json` files place `binaryDir` under the **repository root**, for example `_build_msvc/sdk_2026`, not `sdk_2026/_build_msvc`.

```bat
cd sdk_2026

cmake --preset windows_vs2022_v143

cmake --build ..\_build_msvc\sdk_2026 --config Debug
cmake --build ..\_build_msvc\sdk_2026 --config Release
```

From the repository root, the equivalent is:

```bat
cmake --preset windows_vs2022_v143 -S sdk_2026 -B _build_msvc/sdk_2026
cmake --build _build_msvc/sdk_2026 --config Debug
```

Or open `_build_msvc/sdk_2026/c4d-sdk.sln` in Visual Studio (path relative to the repository root).

> No manual symlinks are required. During configure, the shared CMake layer links module-local `source/` and the selected `res/` directory to the maintained root trees; the build system then scans them and collects include paths.

### Quick start (minimal commands)

```bat
git clone --recursive <repo-url>
cd C4D_MMDTool

cd sdk_2026
cmake --preset windows_vs2022_v143
cmake --build ..\_build_msvc\sdk_2026 --config Debug

start ..\_build_msvc\sdk_2026\c4d-sdk.sln
```

> Junctions/symlinks for sources are created during CMake configure—no manual link step.

### Runtime resources and debugging

Module-local source/resource links are build inputs. Output `plugins/mmdtool/res/` is a real, verified copy, synchronized both before every plugin build (including resource-only edits) and through the SDK post-build hook. The shared layer forwards SDK commands through generated wrappers and replaces only the runtime resource-link command; Maxon vendor files remain unchanged. Windows runs `cmake/sync_runtime_resources.ps1`; macOS runs `cmake/sync_runtime_resources.cmake`.

`CMT_RUNTIME_RESOURCE_CONFIG_POLICY=reset` copies repository defaults for reproducible artifacts. Set it to `preserve` to retain valid output `cmt_config.json` preferences during local development. R20–R23 resources receive the default config from `res/S24_up` when absent. Existing output links are unlinked without traversing their targets. Test this with `pwsh -NoProfile -File scripts/check_runtime_resources.ps1`; receipts are saved below `S:\tmp`.

Start Cinema 4D normally with `g_additionalModulePath` pointing to the built `plugins` directory, wait for the plugin to load, then attach LLDB/DAP. Direct debugger launch can trigger a false startup library-validation error in C4D 2026. For diagnostic console output add `g_console=true` and the variables documented in [`docs/dev/anim-flow-debug.md`](docs/dev/anim-flow-debug.md), then save the console output. Preserve user-owned C4D processes; a loaded plugin can lock the binary during rebuilds. See [`AGENTS.md`](AGENTS.md) for attach and stop-filter details.

`CMT_ENABLE_RUNTIME_REGRESSION=ON` enables the test-only scene bridge for deterministic C4D scenarios. It defaults to OFF in normal and release builds; follow [`docs/dev/regression.md`](docs/dev/regression.md) for the native harness and acceptance evidence.

---

## Overview

C4D_MMDTool is a Cinema 4D plugin for importing and managing MikuMikuDance (MMD) models, animation, cameras, rigid bodies, joints, and related data. It supports PMX/PMD and VMD/VPD.

The project targets multiple Cinema 4D SDK versions (R20 through 2027). Active development uses the `source/` tree; the primary SDK is 2026.

---

## Repository layout

```
C4D_MMDTool/
├── source/                   # Main plugin sources (maintained)
├── old/                      # Legacy archive (not built by default)
├── dependency/
│   ├── bullet3/
│   ├── libMMD/
│   ├── yaml-cpp/
│   └── install/              # Legacy; optional if using old install-prefix workflow
├── res/                      # Canonical resources; selected by SDK wrapper
│   ├── R20-S24/
│   └── S24_up/               # Current resource set
├── cmake/                    # Shared plugin/dependency CMake implementation
├── sdk_2026/                 # Cinema 4D 2026 SDK tree
│   ├── CMakeLists.txt
│   ├── CMakePresets.json
│   ├── cmake/
│   ├── frameworks/
│   ├── plugins/mmdtool/project/
│   │   ├── CMakeLists.txt          # Actual build config
│   │   └── projectdefinition.txt   # Reference only when CMakeLists.txt exists
│   └── sdk_modules.txt
├── sdk_r20/, sdk_r21/, sdk_r23/, sdk_r25/, sdk_2023/ … sdk_2027/
├── docs/dev/                 # Import, export, runtime, and animation-debug maps
├── setup/                    # Inno Setup scripts
└── .github/workflows/
```

---

## `source/` layout

```
source/
├── main.cpp
├── register_entity.cpp/.h
├── plugin_resource.h
├── CMTSceneManager.cpp/.h
├── cmt_tools_manager.cpp/.h
├── cmt_tools_config_manager.cpp/.h
├── cmt_tools_setting.h
├── module/core/cmt_marco.h
├── module/tools/loader/vmd_loader.cpp/.h
├── module/tools/object/   # Object plugins, managers, etc.
├── module/tools/tag/mmd_bone.*
├── module/ui/
└── utils/                  # Header-only helpers (*.hpp)
```

## Architecture and developer navigation

The [documentation index](docs/README.md) links maintained guides, dated validation records, outstanding acceptance, and workspace cleanup conventions.

The plugin starts in `source/main.cpp`, which initializes shared configuration and calls the central registration routine in `source/register_entity.cpp`. UI commands and file loaders delegate PMX/VMD/VPD/camera work to the per-document `CMTSceneManager`; the model, bone, mesh, material, IK, and physics managers under `source/module/tools/` then own the concrete scene objects and runtime evaluation.

Use the detailed maps before changing a subsystem:

| Change area | Start here | Follow-up code |
|-------------|------------|----------------|
| PMX, VMD, VPD, or camera import | [`docs/dev/import-flow.md`](docs/dev/import-flow.md) | `CMTSceneManager.*`, `module/tools/loader/vmd_loader.*`, object and material managers |
| PMX model or VPD pose export | [`docs/dev/export-flow.md`](docs/dev/export-flow.md) | `CMTSceneManager.*`, `mmd_model_manager.*`, `mmd_bone_manager.*` |
| Animation evaluation, EDIT/ANIM transitions, IK, or physics | [`docs/dev/runtime-flow.md`](docs/dev/runtime-flow.md) | `mmd_model_manager.*`, `mmd_bone_manager.*`, `module/tools/tag/mmd_bone.*` |
| Animation/IK/physics diagnosis | [`docs/dev/anim-flow-debug.md`](docs/dev/anim-flow-debug.md) | `cmt_anim_flow_debug.hpp` and the runtime code above |

`old/` is a legacy archive. Do not add normal feature work there, and do not edit SDK-generated or SDK-mirrored source/resource trees: the maintained inputs are root `source/`, `res/`, and the shared `cmake/` layer.

### Include conventions

| Library | Pattern | Example |
|---------|---------|---------|
| libMMD | `#include "libMMD/Model/MMD/..."` | `#include "libMMD/Model/MMD/PMXFile.h"` |
| yaml-cpp | `#include "yaml-cpp/yaml.h"` | |
| glm | via libMMD | `#include <glm/gtc/quaternion.hpp>` |
| C4D descriptions | `#include "description/..."` | `#include "description/OMMDBoneManager.h"` |
| C4D symbols | `#include <c4d_symbols.h>` | |

> Bullet is used inside libMMD sources only; the plugin links Bullet transitively through the static libMMD archive.

---

## Third-party dependencies (`dependency/`)

### Dependency graph (conceptual)

```
Plugin
├── libMMD (static)
│   ├── Bullet (static, private)
│   └── GLM (header-only)
├── yaml-cpp (static)
└── Cinema 4D SDK frameworks (cinema, core, image, math, …)
```

### Library naming (`CMAKE_DEBUG_POSTFIX="_Debug"`)

Release vs Debug `.lib` names follow the `_Debug` suffix pattern for Debug (see Chinese doc table for full list).

---

## Cinema 4D 2026 SDK build system

### Overview

The 2026 SDK uses CMake (not the legacy Project Tool `.vcxproj` flow). Targets are generated per module.

### Module discovery

1. Root CMake reads `MAXON_SDK_MODULES_DIR` (default `plugins/`)
2. Optional `custom_paths.txt` with `MODULE` entries
3. Otherwise scan subfolders of `plugins/`
4. Search up to 3 levels for `projectdefinition.txt`
5. If found, check for a sibling `CMakeLists.txt`

### Custom `CMakeLists.txt` vs generated (Mode A vs B)

**Mode A (this project):** If `project/CMakeLists.txt` exists, it is loaded directly; `projectdefinition.txt` is **not** parsed. Each SDK wrapper is intentionally thin: it selects the resource generation, adds dependencies, and delegates shared target setup to `cmake/mmdtool_plugin_common.cmake`. That layer creates module-local links to the root `source/` and selected `res/` tree so `source_group(TREE …)` and includes stay valid.

**Mode B (SDK default):** Only `projectdefinition.txt` → generated `CMakeLists.txt` in the build dir; expects `source` and `res` beside the module (often requires manual symlinks).

### `projectdefinition.txt` → CMake mapping

Relevant only for **Mode B**. In Mode A, set the corresponding CMake variables directly in `CMakeLists.txt` (see Maxon `sdk_update_projects.cmake`).

### Output

- Windows: `_build_msvc/sdk_2026/bin/{Debug|Release}/plugins/mmdtool/*.xdl64`（相对仓库根；其他 SDK 将 `sdk_2026` 换成对应目录名）
- macOS: `.xlib` under the equivalent path
- The post-build `res/` beside the plugin is a complete real copy of the resource tree selected by the SDK wrapper. `sdk_r20`, `sdk_r21`, and `sdk_r23` use `res/R20-S24`; `sdk_r25` and 2023–2027 use `res/S24_up`.

---

## Configuration files

### `sdk_2026/plugins/mmdtool/project/CMakeLists.txt`

Loaded when present. It only resolves the repository/module roots, adds dependencies, and calls `cmt_setup_mmdtool_plugin()`. The shared `cmake/mmdtool_plugin_common.cmake` owns the source/resource links, Maxon target variables, platform settings, dependency modes, and final third-party linking. `mmdtool_plugin_dependencies_add()` builds Bullet and libMMD in `SUBDIR` mode unless `CMT_DEPS_PREBUILT_DIR` selects prebuilt libraries.

### `projectdefinition.txt`

Human-readable metadata only when custom `CMakeLists.txt` exists—the build system does not parse it for this module.

### SDK `CMakePresets.json` (inside `sdk_*`)

| Preset | Generator | Notes |
|--------|-------------|-------|
| `windows_vs2022_v143` | VS 2022 | MSVC v143 |
| `windows_vs2026_v145` | VS 2026 | MSVC v145 (when installed) |
| `windows_vs2022_clangcl` | VS 2022 | ClangCL |
| `macos_universal_xcode` | Xcode | Universal binary |
| `linux_ninja` | Ninja Multi-Config | Linux |


## Cinema 4D 2027 compatibility

`sdk_2027/` contains the official 2027 SDK frameworks and build tools. Its thin plugin wrapper uses the common build layer; that layer translates plugin settings to the native descriptor API introduced in 2027. The default root development preset remains on 2026. CI and packaging include a separate 2027 binary and copied resources/MCP runtime.

Build 2027 without launching Cinema 4D:

```powershell
cmake --preset windows_vs2022_v143 -S sdk_2027 -B _build_msvc/sdk_2027
cmake --build _build_msvc/sdk_2027 --config Debug --target mmdtool
cmake --build _build_msvc/sdk_2027 --config Release --target mmdtool
```

For Visual Studio 2026 with the v143 toolset installed, configure with `cmake -S sdk_2027 -B _build_msvc/sdk_2027_v143 -G "Visual Studio 18 2026" -A x64 -T v143`. The `windows_vs2026_v145` preset also remains available; use a separate build directory for each toolchain. The 2027 SDK requires CMake 3.30 and C++20. Build and installer fixture validation do not establish plugin loading, import, animation, or save/reopen behavior in the 2027 host.

The [Windows 2027 native validation](docs/validation/c4d-2027-native-20261019/README.md) records production API and real-asset results, including the original strict physics seek-replay failure. It does not establish full runtime compatibility.

The [2026.4.0 / 2027.0.0 native comparison](docs/validation/c4d-2026-2027-compare-20261019/README.md) reproduced the same strict replay failure in both hosts, with identical captured results for all five corresponding flows. The subsequent [physics replay repair](docs/validation/physics-replay-determinism-20261019/README.md) removes history-dependent Euler decomposition from playback writes: both hosts pass all three strict replay comparisons with zero captured difference for this model, motion, and 0–60 frame window. The reports retain the original failures, validated binary identities, and acceptance limits.
