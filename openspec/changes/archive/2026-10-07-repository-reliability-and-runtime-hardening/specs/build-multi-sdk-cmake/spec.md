## MODIFIED Requirements

### Requirement: Dependencies build through CMake-managed workflow
The project SHALL provide a CMake-managed workflow to configure, build, and test Bullet3 and libMMD as shared build targets. Plugin builds SHALL consume those targets or explicitly configured compatible prebuilt libraries without requiring an install prefix.

#### Scenario: Build dependencies before plugin build
- **WHEN** a developer runs the documented dependency build workflow
- **THEN** dependency targets and their transitive include/link requirements are available to the plugin
- **AND** functional tests can be run through the documented test target

## ADDED Requirements

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
