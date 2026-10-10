## ADDED Requirements

### Requirement: Controller body-part workflow
The model SHALL expose body-part visibility, a solo body part, and MMD-adjustment, IK-animation and FK-posing presets. Drawing, picking, hover and visible-control selection SHALL use the same filters. Presentation changes SHALL preserve existing animation input.

#### Scenario: Focus a limb
- **WHEN** the artist solos one arm
- **THEN** only that arm's enabled controls SHALL be visible and selectable
- **AND** leaving solo SHALL restore the saved body-part switches

#### Scenario: Save display preferences
- **WHEN** a model is cloned or saved and reopened
- **THEN** its groups, solo setting and workflow preferences SHALL apply to its own controls

### Requirement: Explicit limb control and pose matching
Each supported limb SHALL expose Auto, FK and IK ownership. Auto SHALL retain legacy behavior. FK SHALL retain ownership at neutral input; IK SHALL ignore inactive FK controls. A mode switch SHALL match the currently evaluated pose without changing model bind state. Existing control tracks SHALL receive a matching key at the current time while retaining keys at other times.

#### Scenario: Animate a standard arm
- **WHEN** a standard shoulder-arm-elbow-wrist chain is available and arm IK is selected
- **THEN** a hand target and bend-direction control SHALL drive a two-segment arm without stretching beyond its lengths
- **AND** incomplete chains SHALL retain existing controls without a misleading IK target

#### Scenario: Switch and reopen
- **WHEN** the artist repeatedly switches a posed limb between FK and IK, then saves and reopens
- **THEN** its current pose and selected ownership SHALL remain stable
- **AND** its original tracks and bind state SHALL be preserved

### Requirement: Animation control selection commands
The model SHALL offer reset-input and key-selected commands for its selected visible managed controls. Both SHALL support Undo. Reset SHALL retain tracks; key-selected SHALL write native relative position and rotation control tracks without requiring an MMD animation slot.

#### Scenario: Reset one selected controller
- **WHEN** the artist resets one visible selected controller
- **THEN** only that controller's relative input SHALL reset
- **AND** another model's selection, tracks and frozen transforms SHALL be unchanged

#### Scenario: Hand and helper controls
- **WHEN** standard finger bones and auxiliary bones are present
- **THEN** finger controls SHALL be available in their own group
- **AND** auxiliary controls SHALL remain outside normal primary selection
