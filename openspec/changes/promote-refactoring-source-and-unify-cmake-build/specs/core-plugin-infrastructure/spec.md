## ADDED Requirements

### Requirement: Canonical source directory naming
The project SHALL promote the maintained plugin implementation tree to `source/`, and all active plugin build configurations, source discovery rules, and developer documentation MUST treat that directory as the canonical plugin source root.

#### Scenario: Active build references the canonical source tree
- **WHEN** a supported SDK plugin project resolves its source inputs
- **THEN** it reads active plugin code from `source/`
- **AND** it does not require `refactoring/` to remain the canonical source root

### Requirement: Legacy source tree is archived separately
The previous legacy implementation SHALL be preserved under `old/`, and the default build workflow MUST exclude that archived tree from active plugin compilation unless a maintainer explicitly opts into legacy investigation.

#### Scenario: Default build excludes archived legacy code
- **WHEN** a developer runs the documented default plugin build workflow
- **THEN** the build includes the canonical `source/` tree
- **AND** the archived `old/` tree is not compiled as part of the active plugin target

### Requirement: Shared resource mapping remains stable during source migration
Source directory promotion MUST NOT require duplicating plugin resources, and supported SDK builds SHALL continue to resolve the shared active resource tree through a single documented mapping strategy.

#### Scenario: Source migration preserves resource resolution
- **WHEN** the source promotion is completed and a supported SDK build is configured
- **THEN** the build still resolves the shared plugin resource directory through the documented mapping
- **AND** the resource mapping does not depend on the archived legacy source tree
