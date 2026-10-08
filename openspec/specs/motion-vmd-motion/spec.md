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

The system SHALL provide a bone-manager-owned MMD control layer for authoring and previewing bone animation deltas. Controls SHALL be created only for bones whose `MMDBoneTag` has `PMX_BONE_LOCAL_IS_COORDINATE` or `PMX_BONE_IS_FIXED_AXIS` enabled. The system SHALL NOT create controls from a common MMD skeleton whitelist or alias table. Each control SHALL be linked from the driven bone tag through `PMX_BONE_CONTROL_LINK`, and the link SHALL be persisted by Cinema 4D's parameter storage.

#### Scenario: Refresh creates only eligible controls

- **WHEN** the user clicks `Create/Refresh Controls`

- **THEN** the system SHALL create or reconnect controls for bones with PMX local coordinates or fixed axes

- **THEN** the system SHALL NOT create controls for ordinary bones that only match common MMD bone names

- **THEN** ineligible bones SHALL have stale `PMX_BONE_CONTROL_LINK` values cleared

#### Scenario: Control placement follows bone hierarchy

- **WHEN** a control is created for a bone with a parent object

- **THEN** the control SHALL be inserted as a sibling under the driven bone's parent, not as a child of the driven bone

- **THEN** refreshing controls SHALL NOT delete existing user animation tracks on managed control objects

### Requirement: MMD bone controls orientation, constraints, and visual display

Control splines SHALL be oriented so their plane is perpendicular to the PMX fixed axis, PMX local X axis, or a stable fallback bone/tail direction. Local-coordinate bones SHALL use PMX local Z as the control plane reference direction. Control scale SHALL be ignored at runtime. Fixed-axis control rotation SHALL be projected to the bone's fixed axis.

#### Scenario: Control axis and shape are derived from bone data

- **WHEN** a bone has `PMX_BONE_IS_FIXED_AXIS`

- **THEN** its control SHALL use the fixed axis as the effective rotation axis

- **THEN** its visual control shape SHOULD distinguish it from a regular local-coordinate control

- **WHEN** a bone has `PMX_BONE_LOCAL_IS_COORDINATE`

- **THEN** its control SHALL use PMX local X as the plane normal and PMX local Z as the reference direction

#### Scenario: Bone manager control-only display mode

- **WHEN** the user selects the bone manager `Controls` display type

- **THEN** bone/joint visual display SHALL be hidden

- **THEN** linked control objects SHALL remain visible

### Requirement: MMD bone controls runtime delta and keyframe writeback

In animation mode, a control object's relative PRS SHALL be interpreted as an additive delta on top of the active bone animation value. The delta SHALL be applied before append/inherit, IK, and physics processing. Translation SHALL only affect bones with `PMX_BONE_TRANSLATABLE`; rotation SHALL only affect bones with `PMX_BONE_ROTATABLE`; scale SHALL always be ignored.

#### Scenario: Control delta drives animation in the same frame

- **WHEN** the model is in `MODEL_MODE_ANIM` and a user moves or rotates an eligible bone control

- **THEN** `MMDModelManagerObject::Execute` SHALL re-evaluate the bone pipeline even if the document time has not changed

- **THEN** the driven bone animation value SHALL include the control delta before append/inherit, IK, and physics are evaluated

#### Scenario: Add keyframe writes adjusted animation value

- **WHEN** the user adjusts a bone control and clicks the bone animation add-key button

- **THEN** the target bone's keyframe SHALL store the current animation value plus the control delta

- **THEN** an existing keyframe at the same VMD frame SHALL be overwritten

- **THEN** the control relative PRS SHALL be reset to identity after the keyframe is written

- **THEN** the current pose SHALL remain stable after the reset

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
