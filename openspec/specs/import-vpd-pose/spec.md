# import-vpd-pose Specification

## Purpose
TBD - created by archiving change add-vpd-pose-import. Update Purpose after archive.
## Requirements
### Requirement: VPD pose import entry point
The system SHALL provide a working VPD pose import command from the existing Pose Import (VPD) tool button and from the selected model manager's animation section. The command SHALL open a `.vpd` file selector, SHALL reject non-VPD files, SHALL require an `MMDModelManagerObject`, and SHALL route the parsed `libmmd::VPDFile` through the scene/model import path instead of applying changes directly from the UI layer.

#### Scenario: Import command routes a VPD file to the selected model
- **WHEN** the user selects an `MMDModelManagerObject` and clicks the Pose Import (VPD) import button
- **THEN** the system opens an import file selector for `.vpd`
- **THEN** the selected VPD file is parsed with libMMD
- **THEN** the parsed pose is applied through `CMTToolsManager`, `CMTSceneManager`, and the selected `MMDModelManagerObject`

#### Scenario: Model manager animation section imports VPD
- **WHEN** the user activates the model manager animation section's VPD import button
- **THEN** the system SHALL import the selected `.vpd` file into that model manager without relying on the active object selection

#### Scenario: Import command rejects invalid targets
- **WHEN** the user runs VPD pose import with no selected object or with a selected object that is not an `MMDModelManagerObject`
- **THEN** the system does not apply any VPD bone or morph data
- **THEN** the user receives an import error consistent with the existing PMX/VMD import error style

### Requirement: VPD bone pose application
The system SHALL match VPD bone entries to imported MMD bones by PMX local bone name. For each matched bone, the system SHALL apply the VPD translation and quaternion rotation as a static pose in the same bone-pose coordinate and scale convention used by the selected model's existing MMD bone pose pipeline. The system SHALL respect PMX bone control flags so non-translatable bones do not receive translation and non-rotatable bones do not receive rotation.

#### Scenario: Matching VPD bones update the current static pose
- **WHEN** a VPD file contains bone pose entries whose names match PMX local bone names in the selected model
- **THEN** each matched bone object is updated to the imported static pose
- **THEN** the imported pose remains visible after the import command completes without creating a VMD animation slot

#### Scenario: Bone pose honors control flags
- **WHEN** a matched bone is marked non-translatable or non-rotatable by its PMX bone parameters
- **THEN** the system does not apply the disallowed translation or rotation component from the VPD entry
- **THEN** the allowed component, if any, is still applied

### Requirement: VPD morph weight application
The system SHALL apply VPD morph entries through the model's existing morph strength path. The system SHALL match VPD morph names to the model morph name map and SHALL update the corresponding current morph strength without creating animation keyframes.

#### Scenario: Matching VPD morphs update current morph strength
- **WHEN** a VPD file contains morph entries whose names match morphs in the selected model
- **THEN** each matched morph strength is updated to the VPD weight
- **THEN** mesh, bone, group, flip, material, and impulse morph dispatch continues to use the existing model morph update path

#### Scenario: VPD morph import does not create animation tracks
- **WHEN** VPD morph weights are imported
- **THEN** the system does not create CTrack or CKey data for those morph weights
- **THEN** existing VMD animation slots remain unchanged

### Requirement: Import reporting for unmatched VPD data
The system SHALL report VPD import statistics and unmatched names. Unmatched VPD bone names and morph names SHALL be collected during import and SHALL be visible in the import report or diagnostic output consistent with existing import reports.

#### Scenario: Import report includes unmatched bones and morphs
- **WHEN** a VPD file contains bone or morph names that cannot be matched to the selected model
- **THEN** the system completes the import for matched entries
- **THEN** the system reports the unmatched bone names and unmatched morph names

#### Scenario: Import report includes successful counts
- **WHEN** VPD pose import succeeds
- **THEN** the system reports the number of VPD bone entries, matched bone entries, VPD morph entries, and matched morph entries

### Requirement: Runtime state after VPD import
The system SHALL invalidate or refresh runtime state after VPD pose import so IK, append/inherit, morph, and physics evaluation do not continue from stale state. VPD import SHALL apply as a static pose operation and SHALL NOT delete existing VMD animation slots.

#### Scenario: Runtime is refreshed after pose import
- **WHEN** VPD pose import changes at least one bone or morph on the selected model
- **THEN** the system marks affected scene nodes dirty
- **THEN** the system invalidates standalone runtime state for the selected model
- **THEN** subsequent IK, append/inherit, morph, and physics evaluation uses the imported pose as the current static pose input

#### Scenario: Existing animations are preserved
- **WHEN** the selected model already has VMD animation slots before VPD pose import
- **THEN** the system does not delete or replace those animation slots
- **THEN** the user can still select and play the existing animations after the VPD import

#### Scenario: Animation mode stays in animation mode
- **WHEN** VPD pose import runs while the selected model is in animation mode
- **THEN** the system SHALL apply the imported pose to the current model state
- **THEN** the system SHALL NOT switch the model to edit mode
- **THEN** the system SHALL NOT create, overwrite, or delete keyframes unless the user separately registers the current state

#### Scenario: Unregistered animation-mode pose is transient
- **WHEN** VPD pose import runs while the selected model is in animation mode
- **AND** the user does not register the current state
- **WHEN** playback advances, the current document time changes, or the model mode changes
- **THEN** the system SHALL clear the VPD pose override and imported morph strengths from the current state
- **THEN** the existing animation slot and morph tracks SHALL drive the model again

### Requirement: VPD parser validation
The system SHALL include focused libMMD tests for VPD parsing and writing. The tests SHALL cover bone translation, bone quaternion rotation, morph weights, Japanese/SJIS names, and VPD round-trip output accepted by `ReadVPDFile`.

#### Scenario: libMMD reads VPD bone and morph data
- **WHEN** the focused VPD parser test reads a fixture containing Japanese bone and morph names
- **THEN** the parsed `VPDFile` contains the expected UTF-8 names
- **THEN** the parsed translation, quaternion, and morph weight values match the fixture data

#### Scenario: libMMD writes a readable VPD file
- **WHEN** the focused VPD round-trip test writes a `VPDFile` and reads it back
- **THEN** the re-read file contains the same bone names, morph names, translations, quaternions, and weights within floating-point tolerance
