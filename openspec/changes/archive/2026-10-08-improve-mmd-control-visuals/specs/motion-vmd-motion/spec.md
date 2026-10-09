## ADDED Requirements

### Requirement: Model-level controller presentation settings
The model Attribute Manager SHALL expose controls to create or refresh generated bone controls, select visible controls, choose Primary/All/Hidden display, adjust overall shape size, and show or hide occluded outlines. These settings SHALL persist with the model. Primary display SHALL exclude bones marked hidden or disabled by PMX flags without deleting their controls.

#### Scenario: Adjust controller presentation
- **WHEN** the user changes display or size at model level
- **THEN** existing managed control splines SHALL update without changing their transforms, links, tracks, bone bind state, or current pose
- **AND** external artist-linked objects SHALL NOT have their geometry restyled

#### Scenario: Save and reopen
- **WHEN** the model is copied or saved and reopened
- **THEN** its presentation settings SHALL apply to its own generated controls

### Requirement: Readable generated controller geometry
Generated controls SHALL use distinct rotation, fixed-axis and translation silhouettes, model-proportional sizes, and consistent left/right/central colors. Occluded outlines SHALL be optional and visually quieter than selected controls. Existing fixed/local-axis semantics SHALL remain unchanged. Ordinary foot IK goals SHALL use horizontal foot outlines, toe IK goals triangles, and IK parents larger rounded frames.

#### Scenario: Refresh an animated controller
- **WHEN** a controller with authored tracks or a nonzero relative pose is refreshed
- **THEN** its object identity, transform and animation tracks SHALL be preserved
- **AND** its generated shape and color SHALL use the current presentation settings

## MODIFIED Requirements

### Requirement: MMD bone controls creation and persistence
The system SHALL provide a bone-manager-owned MMD control layer for animation deltas. It SHALL create controls for PMX local-coordinate/fixed-axis bones, PMX IS_IK targets, and exactly matched standard leg, knee, ankle, toe, toe-extension and IK-parent names in Japanese or English. Names alone SHALL NOT create an IK solver or qualify an IK goal. Deformation duplicates with a D suffix SHALL NOT qualify by name alone. Controls SHALL persist through PMX_BONE_CONTROL_LINK.

#### Scenario: Refresh creates only eligible controls
- **WHEN** Create/Refresh Controls is invoked on an ordinary MMD skeleton
- **THEN** its eligible leg, knee, ankle, toe, IK target and IK parent bones SHALL receive controls even without local/fixed-axis flags
- **AND** unrelated clothing/deformation bones SHALL NOT qualify merely by containing part of a standard bone name
- **AND** stale links on ineligible bones SHALL be cleared

#### Scenario: Control placement follows bone hierarchy
- **WHEN** a control is created for a bone with a parent
- **THEN** it SHALL be inserted as a sibling under that parent
- **AND** refresh SHALL preserve existing relative inputs, frozen transforms and animation tracks

### Requirement: MMD bone controls runtime delta and keyframe writeback
In animation mode, control relative PRS SHALL contribute additive animation deltas before append/inherit, IK and physics. Translation and rotation SHALL respect their PMX channel flags; scale SHALL be ignored. An active valid FK rotation on an affected non-goal bone SHALL take rotation ownership of that IK chain until neutral, consistent with direct external rotation constraints. IK goal controls SHALL remain solver inputs.

#### Scenario: Control delta drives animation in the same frame
- **WHEN** a control changes without advancing the timeline
- **THEN** the pipeline SHALL re-evaluate its input
- **AND** active limb FK rotation SHALL survive IK, with normal IK restored after the FK control is neutral
- **AND** moving an IK target or its parent SHALL move the existing chain

#### Scenario: Add keyframe writes adjusted animation value
- **WHEN** adjusted animation is registered through the bone add-key command
- **THEN** the current animation plus control delta SHALL replace the key at that VMD frame
- **AND** relative control PRS SHALL reset to identity while preserving the registered pose
- **AND** registered FK rotation SHALL retain authored-pose ownership across reload and remain editable by subsequent control deltas

### Requirement: MMD bone controls orientation, constraints, and visual display
Control planes SHALL use the PMX fixed axis or local X as normal, with local Z as reference for local-coordinate bones. Fallback orientation SHALL follow the bone/tail, except IK controls SHALL use the posed model horizontal plane. Fixed-axis rotation SHALL be projected to that axis and scale SHALL be ignored. Visual markers MAY extend outside the plane without changing the transform basis.

#### Scenario: Control axis and shape are derived from bone data
- **WHEN** a bone has a fixed axis
- **THEN** its control SHALL use that axis and a distinct fixed-axis silhouette
- **WHEN** a bone has local coordinates
- **THEN** its control SHALL use local X as normal and local Z as reference

#### Scenario: Bone manager control-only display mode
- **WHEN** the user selects Controls display
- **THEN** bone/joint visuals SHALL be hidden
- **AND** generated controls SHALL follow the model's Primary/All display scope
