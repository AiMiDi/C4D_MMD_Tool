# Multi-SDK CMake Build

## Overview

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
The project SHALL provide a CMake-managed workflow to configure, build, test where applicable, and install bullet3 and libMMD into `dependency/install`, and plugin builds MUST consume that installed output.

#### Scenario: Build dependencies before plugin build
- **WHEN** a developer runs the documented dependency build workflow
- **THEN** the system produces installable headers and libraries under `dependency/install`
- **AND** a subsequent plugin configure step uses that install directory as its include and link root

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
