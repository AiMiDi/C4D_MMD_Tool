## MODIFIED Requirements

### Requirement: Model-level controller presentation settings
The model Attribute Manager SHALL expose controls to create or refresh generated bone controls, select visible controls, choose Primary/All/Hidden display, adjust overall shape size, and show or hide occluded outlines. These settings SHALL persist with the model. Primary display SHALL exclude bones marked hidden or disabled by PMX flags and recognized auxiliary, twist or glasses-accessory controls without deleting them.

#### Scenario: Adjust controller presentation
- **WHEN** the user changes display or size at model level
- **THEN** existing managed control splines SHALL update without changing their transforms, links, tracks, bone bind state, or current pose
- **AND** external artist-linked objects SHALL NOT have their geometry restyled

#### Scenario: Save and reopen
- **WHEN** the model is copied or saved and reopened
- **THEN** its presentation settings SHALL apply to its own generated controls

#### Scenario: Auxiliary controls overlap an elbow
- **WHEN** a visible and enabled auxiliary control such as `+左ひじ補助_ctrl` is near `左ひじ_ctrl`
- **THEN** Primary display and visible-control selection SHALL exclude the auxiliary and retain the elbow
- **AND** All display SHALL expose the same auxiliary object with its original tracks and links

### Requirement: Readable generated controller geometry
Generated controls SHALL use distinct rotation, fixed-axis and translation silhouettes, model-proportional sizes, and consistent left/right/central colors. Occluded outlines SHALL be optional and visually quieter than selected controls. Existing fixed/local-axis semantics SHALL remain unchanged. Ordinary foot IK goals SHALL use horizontal foot outlines, toe IK goals triangles, and IK parents larger rounded frames.

#### Scenario: Refresh an animated controller
- **WHEN** a controller with authored tracks or a nonzero relative pose is refreshed
- **THEN** its object identity, transform and animation tracks SHALL be preserved
- **AND** its generated shape and color SHALL use the current presentation settings

#### Scenario: Shape size reflects purpose
- **WHEN** main joints, auxiliary bones and twist bones have generated controls
- **THEN** recognized shoulder, arm, elbow and wrist controls SHALL have progressively smaller nominal radii
- **AND** auxiliary and twist controls SHALL use substantially smaller outlines than main joint controls
- **AND** the global size setting SHALL scale every purpose consistently

#### Scenario: Native and foreground geometry agree
- **WHEN** a generated control is drawn normally or through the mesh
- **THEN** its main outline and any triangular orientation fin SHALL each be explicitly closed
- **AND** limb rotation rings SHALL have a fin outside the rim with a small gap, its broad base tangent to the rim and its tip extending along the positive plane normal; the fin plane SHALL be perpendicular to the ring plane
- **AND** fixed-axis diamonds, feet and IK frames SHALL remain planar without an added fin
- **AND** foot IK and IK-parent frames SHALL be narrower across the foot than along its length
- **AND** no implicit additional closing edge SHALL appear on the marker

#### Scenario: Character-style controls for hands and central bones
- **WHEN** standard root, center, groove, waist, torso, neck and head bones are present
- **THEN** generated controls SHALL include them without fins: a large root ring, a larger rounded center frame, a groove oval, a waist triangle, and upper-torso/neck/head rings and a downward pelvis silhouette, horizontal when no explicit PMX axis is specified
- **AND** recognized wrist controls SHALL use shallow wire boxes unless an explicit fixed axis takes precedence
- **AND** existing control transforms and animation SHALL remain intact while newly generated central controls SHALL drive their bones
- **AND** accessory and helper names SHALL NOT qualify through a partial central-name match

#### Scenario: Secondary silhouettes identify purpose
- **WHEN** shoulders, eyes and upper/lower torso have generated controls
- **THEN** shoulder outlines SHALL use an offset frame and short leader, eye outlines SHALL be small ovals in front of their pivots, and lower-torso outlines SHALL differ from upper-torso rings
- **AND** changing the silhouette SHALL NOT introduce a new IK pole-vector or eye Aim solver

### Requirement: MMD bone controls creation and persistence
The system SHALL create persistent animation-delta controls for PMX local-coordinate/fixed-axis bones, PMX IS_IK targets, and exactly matched standard limb and central-body names in Japanese or English. Names alone SHALL NOT create an IK solver or qualify an IK goal. D-suffix deformation duplicates SHALL NOT qualify by name alone. Controls SHALL persist through PMX_BONE_CONTROL_LINK.

#### Scenario: Refresh creates only eligible controls
- **WHEN** Create/Refresh Controls is invoked on an ordinary MMD skeleton
- **THEN** its eligible leg, knee, ankle, toe, IK target, IK parent, root, center, groove, waist, upper/lower torso, neck and head bones SHALL receive controls even without local/fixed-axis flags
- **AND** unrelated clothing/deformation bones SHALL NOT qualify merely by containing part of a standard bone name
- **AND** stale links on ineligible bones SHALL be cleared

#### Scenario: Control placement follows bone hierarchy
- **WHEN** a control is created for a bone with a parent
- **THEN** it SHALL be inserted as a sibling under that parent
- **AND** refresh SHALL preserve existing relative inputs, frozen transforms and animation tracks

### Requirement: MMD bone controls orientation, constraints, and visual display
Control transform frames SHALL use the PMX fixed axis or local X as normal, with local Z as reference for local-coordinate bones. Fallback orientation SHALL follow the bone/tail, except IK and central body controls without explicit PMX axes SHALL use the posed model horizontal plane. Fixed-axis rotation SHALL be projected to that axis and scale SHALL be ignored. Visual markers MAY extend outside the plane without changing the transform basis.

#### Scenario: Control axis and shape are derived from bone data
- **WHEN** a bone has a fixed axis
- **THEN** its control SHALL use that axis and a distinct fixed-axis silhouette
- **WHEN** a bone has local coordinates
- **THEN** its control SHALL use local X as normal and local Z as reference

#### Scenario: Bone manager control-only display mode
- **WHEN** the user selects Controls display
- **THEN** bone/joint visuals SHALL be hidden
- **AND** generated controls SHALL follow the model's Primary/All display scope
