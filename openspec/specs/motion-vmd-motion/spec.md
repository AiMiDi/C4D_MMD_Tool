# VMD Motion

## Purpose

Import and export VMD motion animations for MMD models. Motion data includes bone keyframes and morph keyframes, applied to an existing `MMDModelManagerObject` in the scene.

## Requirements

### Requirement: VMD morph animation playback mechanism

In animation mode (`MODEL_MODE_ANIM`), morph animation playback SHALL be driven by C4D's CTrack system instead of per-frame reads from libMMD's morph weight output. The `MMDMeshManagerObject` SHALL NOT read morph weights from `libmmd::MorphManager` during `MODEL_MODE_ANIM` execution. Instead, morph strength values come from C4D parameters (set by CTrack evaluation), and `UpdateMorph()` dispatches them to mesh/bone managers through existing paths (`SetMorphStrength`, bone morph hubs).

#### Scenario: Mesh morph strength comes from CTrack in animation mode

- **WHEN** the model is in `MODEL_MODE_ANIM` and a mesh morph has CTrack keyframes

- **THEN** `MMDMeshManagerObject::Execute()` does NOT read morph weights from `mmd_morph_manager_`

- **THEN** mesh morph strength is applied through `MeshMorph::UpdateMorph()` → `SetMorphStrength()` using the CTrack-driven parameter value

#### Scenario: Bone morph works via bone tag

- **WHEN** the model is in `MODEL_MODE_ANIM` and bone morphs exist

- **THEN** bone morph strength values SHALL come from CTrack on the model manager

- **THEN** `MMDBoneTag::Execute` SHALL apply bone morph position/rotation deltas using the CTrack-driven strength values

- **THEN** libMMD's `VMDAnimation::Evaluate()` SHALL NOT be used for bone morph evaluation

### Requirement: Remove VMD morph weight reading from MeshManager

The `MMDMeshManagerObject` SHALL NOT maintain `morph_manager_index_` or `mmd_morph_manager_` members. The `MESH_MODE_VMD` morph weight reading loop in `Execute()` SHALL be removed.

#### Scenario: MeshManager Execute in VMD mode
- **WHEN** `MMDMeshManagerObject::Execute()` runs in `MESH_MODE_VMD`
- **THEN** no morph weight reading from libMMD's `MorphManager` occurs
- **THEN** morph strength is applied solely through the `SetMorphStrength()` path called by `UpdateMorph()`

### Requirement: Report unmatched VMD morph names

The VMD import pipeline SHALL record morph names from the VMD file that do not match any morph in the target model's `morph_name_` map, and include them in the import log report.

#### Scenario: Import report includes unmatched morph names
- **WHEN** a VMD file is imported and some morph names cannot be matched
- **THEN** `LoadVmdMotionLog::not_find_morph_name_list` contains the unmatched morph names
- **THEN** the import report dialog displays these names when `detail_report` is enabled

### Requirement: VMD bone animation playback via bone tag storage and evaluation

In animation mode (`MODEL_MODE_ANIM`), bone animation playback SHALL be driven by keyframe data stored on each `MMDBoneTag` (internal structure) plus VMD bezier interpolation evaluated in `MMDBoneTag::Execute`, instead of per-frame reads from libMMD's `VMDAnimation::Evaluate()` and `MMDNode` transforms. Timeline markers MAY be provided by CTrack/CKey on the bone tag's SplineData and frame-on Int parameters.

#### Scenario: Bone animation from tag data in animation mode

- **WHEN** the model is in `MODEL_MODE_ANIM` and bones have imported or authored keyframe data on the bone tag

- **THEN** `MMDBoneTag::Execute` SHALL evaluate animation from its stored keyframe data using VMD bezier interpolation

- **THEN** `VMDAnimation::Evaluate()` SHALL NOT be called for bone animation

- **THEN** `mmd_node_->GetLocalTransform()` SHALL NOT be read by `MMDBoneTag::Execute`

#### Scenario: Bone animation with physics

- **WHEN** the model has physics rigid bodies bound to bones

- **THEN** the model manager SHALL run physics simulation after before-physics bone tag evaluations and before after-physics bone tag evaluations (ordering via numeric priority within `EXECUTIONPRIORITY_EXPRESSION`)

- **THEN** physics results SHALL be written back to C4D bone objects via callbacks

### Requirement: VMD bone import populates bone tag and marker CTracks

During VMD import, `MMDModelManagerObject::LoadVMDMotion` SHALL iterate `VMDFile::m_motions`, match bone names to the model's bone list, and for each matched bone write keyframe data into the bone tag's internal structure. It SHALL create CTrack/CKey on the bone tag's SplineData and frame-on parameters for timeline markers. It SHALL NOT create position/rotation CTrack/CKey on matched bone objects for VMD bone motion.

#### Scenario: Import VMD bone motion

- **WHEN** a VMD file containing bone keyframes is imported

- **THEN** keyframe records SHALL be stored on each matched `MMDBoneTag`

- **THEN** CTrack/CKey SHALL be created on bone tag parameters used for SplineData and frame-on markers

- **THEN** interpolation curve data from VMD SHALL be stored with each keyframe record on the bone tag

### Requirement: Report unmatched VMD bone names

The VMD import pipeline SHALL record bone names from the VMD file that do not match any bone in the model, and include them in the import log report.

#### Scenario: Import report includes unmatched bone names

- **WHEN** a VMD file is imported and some bone names cannot be matched

- **THEN** `LoadVmdMotionLog::not_find_bone_name_list` SHALL contain the unmatched bone names

- **THEN** the import report dialog SHALL display these names when `detail_report` is enabled

### Requirement: Model manager no longer uses VMDAnimation for bone evaluation

`MMDModelManagerObject::Execute` in `MODEL_MODE_ANIM` SHALL NOT call `VMDAnimation::Evaluate()` or `PMXModel::UpdateAllAnimation()` for bone animation, and SHALL NOT depend on `mmd_model_` / `PMXModel` ownership for runtime execution. The model manager's animation-mode Execute SHALL use its standalone `MMDIKManager` and `MMDPhysicsManager`, running physics simulation at the agreed numeric priority.

#### Scenario: Model manager animation-mode execute

- **WHEN** `MMDModelManagerObject::Execute` runs in `MODEL_MODE_ANIM`

- **THEN** it SHALL NOT call `VMDAnimation::Evaluate()`

- **THEN** it SHALL NOT call `mmd_model_->UpdateAllAnimation()`

- **THEN** it SHALL use standalone runtime managers owned by the model manager rather than `mmd_model_`

- **THEN** it SHALL run physics simulation by reading bone transforms via callbacks and stepping Bullet

### Requirement: Unified `*_MODE` enums and `MODEL_ANIM_LIST` animation slots

`MODEL_MODE`, `BONE_MODE`, `MESH_MODE`, `JOINT_MODE` and `RIGID_MODE` SHALL expose only Edit and Animation, without separate VMD values. Legacy VMD values SHALL load as Animation mode. Animation slots SHALL isolate per-bone keyframes and derive document MaxTime/LoopMaxTime from active-slot keys or metadata, rather than VMDAnimation::GetMaxKeyTime().

#### Scenario: Animation slots retain metadata and bone keyframe truth
- **WHEN** a VMD is imported into an animation slot
- **THEN** the model manager SHALL retain the slot display name and maximum-frame metadata
- **AND** each MMDBoneTag SHALL retain that slot's bone keyframes
- **AND** the bone channel SHALL NOT retain a replayable raw VMD source payload

#### Scenario: Legacy `*_MODE_VMD` in saved file

- **WHEN** an older scene file contains a saved `MODEL_MODE_VMD` (or other `*_MODE_VMD`) parameter value

- **THEN** the plugin SHALL interpret it as the corresponding `*_MODE_ANIM` value

#### Scenario: User switches `MODEL_ANIM_LIST`

- **WHEN** the user selects a different animation slot in `MODEL_ANIM_LIST`

- **THEN** bone tags SHALL evaluate the active slot's stored keyframes

- **AND** the active slot index SHALL be propagated to every managed MMDBoneTag

- **THEN** the timeline maximum SHALL match the active slot's range (or documented metadata rule)

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

### Requirement: Bone manager display mode auto-switching

After VMD motion import or when switching from edit mode back to animation mode, the bone manager display type SHALL automatically switch to `BONE_DISPLAY_TYPE_OFF`. When switching to edit mode, it SHALL automatically switch to `BONE_DISPLAY_TYPE_ON`.

#### Scenario: VMD import hides bone manager display

- **WHEN** VMD motion import completes

- **THEN** the model SHALL be in animation mode

- **THEN** the linked bone manager display type SHALL be `BONE_DISPLAY_TYPE_OFF`

#### Scenario: Mode switch updates bone manager display

- **WHEN** the user switches the model to edit mode

- **THEN** the linked bone manager display type SHALL be `BONE_DISPLAY_TYPE_ON`

- **WHEN** the user switches the model back to animation mode

- **THEN** the linked bone manager display type SHALL be `BONE_DISPLAY_TYPE_OFF`

### Requirement: Motion import options control channel replacement
Motion import SHALL honor the bone, morph, and model-info channel switches. Replacement SHALL replace the active slot while preserving other slots; non-replacement SHALL add an isolated slot; explicit merge SHALL combine keys in the active slot with incoming keys winning at matching times.

#### Scenario: Model info disabled
- **WHEN** a VMD with visibility and IK keys is imported with model info disabled
- **THEN** those keys are not imported

#### Scenario: Replacement and additional slot
- **WHEN** import is performed with replacement enabled
- **THEN** the active slot is replaced by the imported animation and other slots are retained
- **WHEN** import is performed with replacement disabled
- **THEN** previous slots remain and the new slot does not inherit their morph or IK tracks

### Requirement: Model info follows animation slots and scene persistence
Model visibility and IK states SHALL follow the selected animation slot and survive scene save/reload. Scenes from earlier persistence versions SHALL remain readable. Leaving animated visibility playback SHALL restore the artist's base viewport/render visibility.

#### Scenario: Save reload and slot switch
- **WHEN** two slots have different visibility and IK keys and the scene is saved and reopened
- **THEN** selecting either slot evaluates only its corresponding keys

### Requirement: Motion export options reflect actual output
Motion export SHALL honor channel switches, position scale, frame offset, and rotation curve selection. Model-info-disabled output SHALL contain no visibility or IK keys. Sparse export SHALL preserve stored key interpolation; baked export SHALL sample evaluated final poses at 30 VMD frames per second.

#### Scenario: Bake without disturbing source scene
- **WHEN** the user exports baked motion containing IK, controls, or physics
- **THEN** the output contains evaluated bone poses for every sampled frame
- **AND** the original document time, mode, tracks, and simulation state are preserved

#### Scenario: Model info round trip
- **WHEN** a motion containing visibility toggles is imported and exported with model info enabled
- **THEN** exported show/hide transitions retain their values and frame positions

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
- **THEN** its main outline SHALL be explicitly closed
- **AND** rotation rings SHALL have no added orientation triangles
- **AND** fixed-axis diamonds, feet and IK frames SHALL remain planar without an added fin
- **AND** foot IK and IK-parent frames SHALL be narrower across the foot than along its length
- **AND** no implicit closing edge SHALL connect unrelated spline segments

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

#### Scenario: Fresh import places eye controls correctly
- **WHEN** a PMX is imported before C4D has evaluated its new hierarchy
- **THEN** controller pivots SHALL be initialized from the composed frozen bone transforms, retaining model scale
- **AND** the shared eye outline SHALL align with the actual eye pair while preserving the authored shared eye rotation pivot

#### Scenario: Editing and animating a model
- **WHEN** the model enters Edit mode
- **THEN** generated controllers and their hover hints SHALL be hidden
- **WHEN** the model returns to Animation mode
- **THEN** controllers SHALL follow the retained Primary, All or Hidden setting
- **AND** mode switches SHALL preserve controller objects and animation

#### Scenario: Hover a visible controller
- **WHEN** the pointer is within six screen pixels of a visible generated controller edge
- **THEN** the native viewport bubble help SHALL show its bone name in the selected local or universal naming mode
- **AND** the nearest edge SHALL win when outlines overlap
- **AND** hidden controllers, hidden ancestors and disabled spline display SHALL not produce controller hints

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

## Implementation overview

VMD bone keys are stored in each bone tag's animation slots. Morph and model-info data have model-manager slot snapshots; the active slot rebuilds CTracks for morph strengths and named IK channels. The model manager owns standalone IK and physics through adapters bound to C4D scene bones.

Import preflights enabled channels before mutation and prepares merged arrays before writing them. Replacement updates the active slot, append creates a separate slot, and explicit merge replaces matching name/frame keys with incoming values. Bone, morph and model-info switches are independent. Frame offsets are integral VMD frames at 30 fps.

Scene persistence stores slot metadata and bone-tag keys, rather than a replayable VMDAnimation payload. ModelManager level 5 appends named IK and visibility slots to the older layout. Earlier active tracks migrate before runtime UI/track reconstruction. Native save/reload acceptance is recorded by the regression suite.

Sparse export preserves VMD interpolation and samples authored C4D controls when needed. Baked export evaluates a translated document clone at 30 fps and captures final poses. Export does not modify the original document's time or simulation state. Final baked poses require target physics/append configuration that avoids repeated deformation because VMD cannot encode those rig switches.

Detailed maintained flows and acceptance boundaries are documented in `docs/dev/import-flow.md`, `docs/dev/runtime-flow.md` and `docs/dev/regression.md`.

## Source files

| File | Responsibility |
|------|----------------|
| `source/cmt_tools_manager.cpp` | File import/export and result reporting |
| `source/CMTSceneManager.cpp` | Scene entrypoints and scoped import undo |
| `source/module/tools/object/mmd_model_manager.cpp` | Slots, persistence, import/export and ObjectData entrypoints |
| `source/module/tools/object/mmd_model_runtime.cpp` | Standalone IK/physics, adapters and layered execution |
| `source/module/tools/object/mmd_model_morph_runtime.cpp` | Morph strength composition and scene synchronization |
| `source/module/tools/tag/mmd_bone.cpp` | Bone slot storage and interpolation |
