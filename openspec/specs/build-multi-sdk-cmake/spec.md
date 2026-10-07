# Multi-SDK CMake Build

## Purpose

Unified CMake-based build system for compiling the mmdtool plugin across all supported Cinema 4D SDK versions (R20 through 2026). A project-level common CMake layer (`cmake/mmdtool_plugin_common.cmake`, `cmake/mmdtool_plugin_dependencies.cmake`) is shared by all SDK plugin projects, with each `sdk_*/plugins/mmdtool/project/CMakeLists.txt` acting as a thin SDK-specific wrapper.

## Requirements

### Requirement: Unified CMake entry for supported SDKs
The project SHALL provide a CMake-based build entry for Cinema 4D SDK versions R20, R21, S22, R23, S24, R25, S26, 2023, 2024, 2025, and 2026, and each supported SDK build entry MUST compile the plugin from the canonical project source tree instead of requiring version-specific source copies.

#### Scenario: Configure a supported SDK build
- **WHEN** a developer configures any supported `sdk_*` project through its documented CMake entry
- **THEN** the configuration resolves the canonical source directory, resource directory, and dependency install directory without requiring manual path edits

### Requirement: 2026 presets are the baseline preset contract
The project SHALL treat the preset naming and generator conventions from `sdk_2026/CMakePresets.json` as the baseline contract for supported SDK builds, and other SDK integrations MUST reuse that contract unless a version-specific limitation requires an explicit extension.

#### Scenario: Reuse preset naming across SDKs
- **WHEN** a developer follows the documented Windows Visual Studio workflow for two different supported SDK versions
- **THEN** the preset names and their expected build directories remain consistent with the 2026 baseline unless the documentation declares a version-specific exception

### Requirement: Dependencies build through CMake-managed workflow
The project SHALL provide a CMake-managed workflow to configure, build, and test Bullet3 and libMMD as shared build targets. Plugin builds SHALL consume those targets or explicitly configured compatible prebuilt libraries without requiring an install prefix.

#### Scenario: Build dependencies before plugin build
- **WHEN** a developer runs the documented dependency build workflow
- **THEN** dependency targets and their transitive include/link requirements are available to the plugin
- **AND** functional tests can be run through the documented test target

### Requirement: Legacy SDKs have minimal bridge configurations
For SDK versions that do not natively provide the modern CMake workflow used by 2025/2026, the project MUST provide a minimal bridge configuration that is sufficient to compile the plugin from the canonical source tree.

#### Scenario: Configure a legacy SDK bridge
- **WHEN** a developer configures one of the legacy supported SDK versions
- **THEN** the build system provides the minimal CMake bridge files needed for that SDK version
- **AND** the bridge still points to the same canonical source and dependency roots used by newer SDK versions

### Requirement: Legacy VS project files are removed only after CMake verification
During migration of legacy SDK versions, the team MAY use existing Visual Studio project files as migration references, but the repository MUST remove those VS project artifacts for a specific SDK only after that SDK's CMake configure/build workflow is verified to pass.

#### Scenario: Reference VS settings during migration
- **WHEN** a maintainer creates a legacy SDK CMake bridge
- **THEN** they can reference existing `.vcxproj`, `.vcxproj.filters`, or `.props` files to port compile and link settings

#### Scenario: Remove VS artifacts after successful CMake run
- **WHEN** the legacy SDK CMake workflow has completed the documented configure/build validation
- **THEN** the matching VS project artifacts for that SDK are removed from the default repository workflow
- **AND** removal does not happen before the CMake validation step is complete

### Requirement: Portable runtime resources
Every built plugin SHALL contain a physical copy of its matching runtime resource tree. The output SHALL be usable after moving it outside the repository. Synchronization SHALL never recursively delete the resource source through a stale output link and SHALL validate required resources and JSON configuration.

#### Scenario: Existing output link
- **WHEN** resource synchronization encounters a junction or symlink at output res
- **THEN** only the link is removed and the canonical source remains intact
- **AND** output res is replaced by a complete physical resource directory

### Requirement: Explicit release workflow
The documented Release preset SHALL configure and compile the selected SDK in Release configuration independently of earlier Debug configuration.

#### Scenario: Developer runs release preset
- **WHEN** a developer follows the documented release configure/build presets
- **THEN** the resulting plugin is generated under the Release output directory

### Requirement: Continuous functional validation
Pull requests and main branch pushes SHALL run functional dependency tests and compile the latest supported SDK. Release validation SHALL compile the full supported SDK/platform matrix. Performance benchmarks SHALL have a separate entrypoint.

#### Scenario: Ordinary pull request
- **WHEN** a pull request changes maintained plugin or build files
- **THEN** functional CTest results and latest SDK compile results are produced
- **AND** the functional job does not include benchmarks
