## ADDED Requirements

### Requirement: Package workflow triggers on version tag push
The package workflow SHALL be triggered when a version tag (matching pattern `v*`) is pushed to the repository.

#### Scenario: Tag push triggers packaging
- **WHEN** a tag matching `v*` (e.g., `v0.5.0`) is pushed
- **THEN** the package workflow SHALL start and produce release artifacts

#### Scenario: Non-version tags ignored
- **WHEN** a tag not matching `v*` is pushed
- **THEN** the package workflow SHALL NOT trigger

### Requirement: Build before package in the same workflow run
The package workflow SHALL invoke the reusable build workflow via `workflow_call` so that all matrix build jobs complete in the **same** workflow run as packaging, then download artifacts with `actions/download-artifact`.

#### Scenario: Tag release runs build then package
- **WHEN** a version tag is pushed and the package workflow starts
- **THEN** it SHALL call `build.yml` with `workflow_call` (including an appropriate `ref` for checkout), wait for all build matrix jobs to finish, and SHALL download the resulting artifacts before Inno Setup and macOS zip steps

#### Scenario: Cross-run artifact reuse (optional future optimization)
- **WHEN** a future implementation chooses to skip `workflow_call` if artifacts already exist for the commit on another run
- **THEN** that behavior SHALL be documented separately; the baseline implementation SHALL NOT require cross-run artifact lookup

### Requirement: Windows Inno Setup packaging
The package workflow SHALL produce a Windows installer using Inno Setup on a Windows runner.

#### Scenario: Inno Setup installer creation
- **WHEN** all Windows SDK build artifacts are available (all 8 SDKs from the build matrix)
- **THEN** the workflow SHALL install Inno Setup 6, place artifacts in the expected `_build/<sdk>/bin/Release/plugins/mmdtool/` paths, and run ISCC on `setup/Common/installer_script.iss` to produce the installer executable

### Requirement: macOS zip packaging
The package workflow SHALL produce macOS release archives on a macOS runner.

#### Scenario: macOS zip creation
- **WHEN** macOS build artifacts are available for each SDK version
- **THEN** the workflow SHALL create a zip archive for each SDK version containing the plugin bundle (`mmdtool.xdl64`) and resources (`res/`)

### Requirement: Upload to GitHub Release
The package workflow SHALL upload all packaging artifacts to the GitHub Release associated with the triggering tag.

#### Scenario: Release creation and upload
- **WHEN** all packaging jobs (Windows installer + macOS zips) complete successfully
- **THEN** the workflow SHALL create a GitHub Release for the tag (or use existing draft) and upload the Windows installer (`.exe`) and macOS zip files (`.zip`) as release assets

#### Scenario: Release naming
- **WHEN** the release is created
- **THEN** the release title SHALL use the tag name (e.g., `v0.5.0`) and the body SHALL include a placeholder for changelog

### Requirement: Version propagation from tag
The package workflow SHALL extract the version number from the tag name and pass it to Inno Setup for embedding in the installer.

#### Scenario: Version from tag
- **WHEN** the tag `v0.5.0` triggers the workflow
- **THEN** the version `0.5.0` (without the `v` prefix) SHALL be passed to ISCC via `/DPluginVersion=0.5.0`
