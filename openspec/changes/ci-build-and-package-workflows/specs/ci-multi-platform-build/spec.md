## ADDED Requirements

### Requirement: Build workflow triggers on main branch merge
The build workflow SHALL be triggered when a pull request is merged (push) to the main branch. It SHALL also support `workflow_dispatch` for manual triggering and `workflow_call` for invocation by other workflows.

#### Scenario: PR merged to main
- **WHEN** a pull request is merged to the main branch (push event)
- **THEN** the build workflow SHALL start and compile all matrix combinations

#### Scenario: Manual trigger
- **WHEN** a user manually triggers the workflow via `workflow_dispatch`
- **THEN** the build workflow SHALL start and compile all matrix combinations

#### Scenario: Called by package workflow
- **WHEN** the package workflow invokes build via `workflow_call`
- **THEN** the build workflow SHALL execute and produce artifacts consumable by the caller

### Requirement: Matrix compilation across platforms and SDK versions
The build workflow SHALL use a matrix strategy to compile the plugin on multiple platforms (Windows, macOS) and eight SDK directories (`sdk_r20`, `sdk_r21`, `sdk_r23`, `sdk_r25`, `sdk_2023`, `sdk_2024`, `sdk_2025`, `sdk_2026`). Each matrix cell SHALL run as a separate job (up to 16 concurrent jobs, subject to GitHub concurrency limits).

#### Scenario: Windows matrix build
- **WHEN** the build workflow runs on Windows
- **THEN** it SHALL run one job per SDK in the matrix and build `mmdtool` in Release for that SDK

#### Scenario: macOS matrix build
- **WHEN** the build workflow runs on macOS
- **THEN** it SHALL run one job per SDK in the matrix and build `mmdtool` in Release for that SDK (Universal Binary arm64;x86_64 per root and SDK CMake conventions)

### Requirement: Root CMake presets for configure and build
The build workflow SHALL use the repository-root **`CMakePresets.json`** for both configure and build steps, matching local developer workflow documented in `DEVELOPMENT.md`.

#### Scenario: Configure with dev-windows or dev-macos
- **WHEN** the configure step runs for a matrix cell
- **THEN** it SHALL invoke `cmake --preset dev-windows` on Windows or `cmake --preset dev-macos` on macOS, with additional cache overrides `-D CMT_SDK_DIR=<repository>/<sdk>` and `-D CMT_SDK_BUILD_CONFIG=Release`

#### Scenario: Build with workflow-release presets
- **WHEN** the build step runs for a matrix cell
- **THEN** it SHALL invoke `cmake --build --preset workflow-release` on Windows or `cmake --build --preset workflow-release-macos` on macOS, which SHALL build the `cmt-workflow` target in Release configuration

### Requirement: Unified CMake workflow target
The build workflow SHALL rely on the root `CMakeLists.txt` **`cmt-workflow`** custom target (dependencies + configure SDK tree + build plugin). The workflow SHALL NOT duplicate generator flags in YAML beyond what presets and cache overrides provide.

#### Scenario: Same target as local root workflow
- **WHEN** a matrix job completes its build step
- **THEN** the plugin SHALL be produced under `_build/<sdk_name>/bin/Release/plugins/mmdtool/` (or equivalent path for the active generator) as defined by the Cinema 4D SDK CMake layout

### Requirement: Upload build artifacts
The build workflow SHALL upload the compiled plugin binaries as GitHub Actions artifacts for each platform/SDK combination.

#### Scenario: Artifact upload after successful build
- **WHEN** a build matrix job completes successfully
- **THEN** the plugin output directory (`_build/<sdk_name>/bin/Release/plugins/mmdtool/`) SHALL be uploaded as an artifact named with the pattern `build-<runner_os>-<sdk_name>` (e.g. `build-Windows-sdk_2026`, `build-macOS-sdk_2026`)

#### Scenario: Artifact retention
- **WHEN** artifacts are uploaded
- **THEN** they SHALL have a retention period of at least 7 days to allow the package workflow to consume them
