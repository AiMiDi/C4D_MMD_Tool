## ADDED Requirements

### Requirement: Build workflow triggers on main branch merge
The build workflow SHALL run functional dependency/plugin tests and compile the latest SDK on pull requests and main branch pushes. Manual `workflow_dispatch` and reusable `workflow_call` release invocations SHALL run the full supported SDK/platform matrix after functional checks.

#### Scenario: PR merged to main
- **WHEN** a pull request is merged to the main branch (push event)
- **THEN** the build workflow SHALL run functional checks and compile the latest supported SDK

#### Scenario: Manual trigger
- **WHEN** a user manually triggers the workflow via `workflow_dispatch`
- **THEN** the build workflow SHALL start and compile all matrix combinations

#### Scenario: Called by package workflow
- **WHEN** the package workflow invokes build via `workflow_call`
- **THEN** the build workflow SHALL execute and produce artifacts consumable by the caller

### Requirement: Matrix compilation across platforms and SDK versions
The full matrix SHALL compile eight supported SDKs on Windows x64 and Intel macOS, plus ARM64 macOS for R25 and 2023 through 2026. Each of the 21 supported combinations SHALL run separately with bounded parallelism. R20, R21 and R23 SHALL NOT be requested on ARM64 macOS.

#### Scenario: Windows matrix build
- **WHEN** the build workflow runs on Windows
- **THEN** it SHALL run one job per SDK in the matrix and build `mmdtool` in Release for that SDK

#### Scenario: macOS matrix build
- **WHEN** the build workflow runs on macOS
- **THEN** it SHALL build Release for each supported SDK/architecture combination, using x86_64 on Intel runners and arm64 on Apple Silicon runners

### Requirement: Root CMake presets for configure and build
The build workflow SHALL use the repository-root **`CMakePresets.json`** for both configure and build steps, matching local developer workflow documented in `DEVELOPMENT.md`.

#### Scenario: Configure with the matching Release preset
- **WHEN** the configure step runs for a matrix cell
- **THEN** it SHALL invoke `cmake --preset release-windows` on Windows or `cmake --preset release-macos` on macOS, with additional cache overrides `-D CMT_SDK_DIR=<repository>/<sdk>` and `-D CMT_SDK_BUILD_CONFIG=Release`

#### Scenario: Build with workflow-release presets
- **WHEN** the build step runs for a matrix cell
- **THEN** it SHALL invoke `cmake --build --preset workflow-release` on Windows or `cmake --build --preset workflow-release-macos` on macOS, which SHALL build the `cmt-workflow` target in Release configuration

### Requirement: Unified CMake workflow target
The plugin build SHALL use the root `cmt-workflow` target for SDK configuration and compilation instead of duplicating SDK generator flags in YAML. Separate dependency build steps MAY select a toolchain and native architecture for cached libraries.

#### Scenario: Same target as local root workflow
- **WHEN** a matrix job completes its build step
- **THEN** the plugin SHALL be produced under `_build_msvc/<sdk_name>/bin/Release/plugins/mmdtool/` (or equivalent path for the active generator) as defined by the Cinema 4D SDK CMake layout

### Requirement: Upload build artifacts
The build workflow SHALL upload physical plugin/resource outputs for Windows and Intel macOS packaging. ARM64 validation jobs SHALL remain separate and SHALL NOT overwrite the packaged Intel artifacts.

#### Scenario: Artifact upload after successful build
- **WHEN** a Windows or Intel macOS packaging matrix job completes successfully
- **THEN** the plugin output directory (`_build_msvc/<sdk_name>/bin/Release/plugins/mmdtool/`) SHALL be uploaded as an artifact named with the pattern `build-<runner_os>-<sdk_name>` (e.g. `build-Windows-sdk_2026`, `build-macOS-sdk_2026`)

#### Scenario: Artifact retention
- **WHEN** artifacts are uploaded
- **THEN** they SHALL have a retention period of at least 7 days to allow the package workflow to consume them
