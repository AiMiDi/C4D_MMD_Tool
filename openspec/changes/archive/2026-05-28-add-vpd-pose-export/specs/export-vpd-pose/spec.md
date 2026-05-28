## ADDED Requirements

### Requirement: VPD pose export command
The system SHALL provide a user-facing command that exports the currently selected MMD model pose to a `.vpd` file.

#### Scenario: Export command is available
- **WHEN** the user opens the CMT tools dialog
- **THEN** the dialog SHALL expose a VPD pose export entry point distinct from PMX model export and VMD motion export

#### Scenario: Model manager animation section exports VPD
- **WHEN** the user activates the selected model manager animation section's VPD export button
- **THEN** the system SHALL export a `.vpd` pose from that model manager without relying on active object lookup

#### Scenario: User selects VPD output path
- **WHEN** the user activates the VPD pose export command
- **THEN** the system SHALL prompt for a `.vpd` output filename before writing the file

### Requirement: Selected MMD model validation
The system SHALL export VPD pose data only from the active `MMDModelManagerObject`.

#### Scenario: No object is selected
- **WHEN** the user activates VPD pose export without an active object
- **THEN** the system SHALL fail the export and show a selection error

#### Scenario: Active object is not an MMD model manager
- **WHEN** the user activates VPD pose export while the active object is not an `MMDModelManagerObject`
- **THEN** the system SHALL fail the export and show a target type error

#### Scenario: Active object is an MMD model manager
- **WHEN** the user activates VPD pose export while an `MMDModelManagerObject` is active
- **THEN** the system SHALL collect pose data from that selected model manager

### Requirement: Current pose snapshot export
The system SHALL export a single-frame snapshot of the selected model's current pose and MUST NOT create, select, delete, or modify VMD animation slots.

#### Scenario: Export from edit mode
- **WHEN** the selected model is in edit mode
- **THEN** the exported VPD file SHALL contain the current editable static bone pose and morph controller strengths

#### Scenario: Export from animation mode
- **WHEN** the selected model is in animation mode
- **THEN** the exported VPD file SHALL contain the evaluated pose at the document's current time

#### Scenario: Existing animation data remains unchanged
- **WHEN** VPD pose export completes
- **THEN** existing VMD animation slots, animation tracks, and keyframes SHALL remain unchanged

### Requirement: VPD bone entries
The system SHALL write one `VPDBone` entry for every model bone using the model's PMX local bone name and the current VPD-space translation and rotation.

#### Scenario: Model contains bones
- **WHEN** VPD pose export collects bone data
- **THEN** each model bone SHALL produce one VPD bone entry with its local name, translation vector, and rotation quaternion

#### Scenario: Bone has zero pose delta
- **WHEN** a model bone currently has zero translation and identity rotation
- **THEN** the exported VPD file SHALL still include that bone entry

#### Scenario: Bone names require Japanese encoding
- **WHEN** a bone name contains non-ASCII characters
- **THEN** the exported file SHALL preserve the name through libMMD VPD writing and reading

### Requirement: VPD morph entries
The system SHALL write one `VPDMorph` entry for every model morph controller using the model morph name and current controller strength.

#### Scenario: Model contains morphs
- **WHEN** VPD pose export collects morph data
- **THEN** each model morph controller SHALL produce one VPD morph entry with its name and current weight

#### Scenario: Morph strength is zero
- **WHEN** a model morph controller currently has weight `0`
- **THEN** the exported VPD file SHALL still include that morph entry

#### Scenario: Group or flip morph is active
- **WHEN** a group or flip morph controller has a non-zero strength
- **THEN** the exported VPD file SHALL write that controller strength without expanding its downstream runtime contribution into child morph entries

### Requirement: VPD file writing and reporting
The system SHALL write VPD files through libMMD `WriteVPDFile` and report export success or failure to the user.

#### Scenario: VPD writer succeeds
- **WHEN** libMMD successfully writes the populated `VPDFile`
- **THEN** the system SHALL show an export success report including exported bone and morph counts

#### Scenario: VPD writer fails
- **WHEN** libMMD fails to create or write the requested VPD file
- **THEN** the system SHALL fail the export and show a write-file error

### Requirement: VPD writer round-trip validation
The implementation SHALL include focused validation that a VPD file written by libMMD can be read back with preserved bone and morph data.

#### Scenario: Writer round-trip test
- **WHEN** the focused VPD writer test writes a VPD file containing bones, morphs, non-ASCII names, translations, rotations, and weights
- **THEN** reading that file back through libMMD SHALL preserve the written entries and numeric values within test tolerance

### Requirement: Model manager current-state animation controls
The system SHALL provide model manager animation-section controls for importing VPD, exporting VPD, registering the current state, and deleting the current frame keyframe using the existing two-column animation group layout.

#### Scenario: Register current state
- **WHEN** the user activates the model manager animation section's register-current-state button
- **THEN** the system SHALL write only bone poses that differ from the active animation slot's current evaluation to the active animation slot at the current document frame
- **THEN** the system SHALL write only morph strengths that differ from the morph animation track's current evaluation to morph animation tracks at the current document frame
- **THEN** if no animation slot exists and at least one changed bone or morph exists, the system SHALL create one before writing keys
- **THEN** unmodified bones and morphs SHALL NOT receive new zero-value or identity-pose keys
- **THEN** in animation mode, the current frame's visible pose SHALL remain stable after registration until the document time changes

#### Scenario: Delete current frame keyframe
- **WHEN** the user activates the model manager animation section's delete-current-frame button
- **THEN** the system SHALL remove current-frame bone keyframes from the active animation slot
- **THEN** the system SHALL remove current-frame morph keys from morph animation tracks
- **THEN** other frames and other animation slots SHALL remain unchanged
