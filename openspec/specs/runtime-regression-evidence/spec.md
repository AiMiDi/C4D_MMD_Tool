# runtime-regression-evidence Specification

## Purpose
Provide reproducible native Cinema 4D regression runs that associate observed scene behavior with an exact plugin build and deterministic input fixtures.

## Requirements

### Requirement: Reproducible scene regression receipts
The regression runner SHALL record plugin/build identity, host version, input identity, scenario steps, and per-case outcomes. It SHALL cover import/save/reload, edit/animation transitions, bone hierarchy mutation, animation slots, physics toggles, and material morph restoration.

#### Scenario: Native regression run
- **WHEN** the runner executes in Cinema 4D with a regression-enabled plugin
- **THEN** it writes a machine-readable receipt containing the observed outcomes and identities

### Requirement: Missing prerequisites do not count as passing
Unavailable host, missing plugin, or missing input SHALL produce an explicit unavailable or skipped outcome. Static checks, dependency tests, and plugin compilation SHALL not be recorded as native scene acceptance.

#### Scenario: Host not installed
- **WHEN** Cinema 4D is unavailable
- **THEN** native scenarios remain unverified and the runner does not claim acceptance
