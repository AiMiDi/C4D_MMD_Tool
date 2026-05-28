# bone-c4d-track-animation Specification

## Purpose
TBD - created by archiving change vmd-bone-c4d-tracks. Update Purpose after archive.
## Requirements
### Requirement: Bone animation UI on bone tag

The `MMDBoneTag` description SHALL include an animation group (`PMX_BONE_ANIM_GRP`) containing: a keyframe frame number parameter (Int), four navigation buttons (previous/next/add/delete keyframe), an interpolation curve type selector (Int with CYCLE+QUICKTABRADIO for X/Y/Z/R channels), and a SplineData interpolation curve editor (0-127 range, two locked knots at (0,0) and (127,127) with bezier handles). The tag SHALL NOT expose separate animatable parameters for bone position XYZ or quaternion WXYZ for authoring keyframe values.

#### Scenario: Animation group visible in animation mode

- **WHEN** the model is in `MODEL_MODE_ANIM` and a bone tag is selected

- **THEN** the `PMX_BONE_ANIM_GRP` group SHALL be visible in the Attribute Manager

- **THEN** the keyframe navigator, curve type selector, and SplineData editor SHALL be displayed

#### Scenario: Curve type selector switches displayed channel

- **WHEN** the user selects "X" in the curve type selector

- **THEN** the SplineData editor SHALL display the X-translation interpolation curve for the current keyframe

- **WHEN** the user selects "R" in the curve type selector

- **THEN** the SplineData editor SHALL display the rotation interpolation curve for the current keyframe

#### Scenario: SplineData constrained to VMD range

- **WHEN** a user drags a control point tangent in the SplineData editor

- **THEN** the tangent handle positions SHALL be clamped to the (0,0)-(127,127) range

- **THEN** the two endpoint knots SHALL remain locked at (0,0) and (127,127)

#### Scenario: Keyframe navigation buttons

- **WHEN** the user clicks the "next" button

- **THEN** the keyframe frame number SHALL advance to the next keyframe in the list and the SplineData SHALL update to show that keyframe's interpolation curves

- **WHEN** the user clicks the "previous" button

- **THEN** the keyframe frame number SHALL move to the previous keyframe

### Requirement: VMD bone keyframe import to bone tag storage and marker CTracks

Bone name matching SHALL use tags reachable from `MMDBoneManagerObject::bone_list_` (indices assigned by `HandleBoneIndexChangeMessage`; see root spec `import-object-hierarchy` — Bone index cache and hierarchy refresh). During VMD import, the system SHALL iterate `VMDFile::m_motions`, group keyframes by bone name, and for each matched bone SHALL write keyframe records into the `MMDBoneTag` internal ordered structure: VMD frame index, translation (scaled per `position_multiple`), quaternion rotation (MMD space), and decoded interpolation data for X/Y/Z/R channels from `VMDMotion::m_interpolation`. The system SHALL NOT create CTrack/CKey on the bone object's position or rotation channels for VMD bone motion.

The system SHALL create CTrack/CKey on the bone tag's **SplineData** parameter (`PMX_BONE_ANIM_SPLINE`) and on the **next keyframe frame** Int parameter (`PMX_BONE_ANIM_FRAME_ON`) at each imported keyframe time, so that keyframe markers appear on the timeline and in the F-Curve manager. The authoritative playback values SHALL come from the tag's internal structure and VMD bezier evaluation, not from C4D's evaluation of object PRS tracks.

#### Scenario: Import VMD with bone keyframes

- **WHEN** a VMD file containing bone animation is imported onto a model

- **THEN** for each bone name that matches a bone in `bone_list_`, keyframe data SHALL be stored in the corresponding `MMDBoneTag` internal structure

- **THEN** CTrack/CKey SHALL be created on the bone tag for `PMX_BONE_ANIM_SPLINE` and `PMX_BONE_ANIM_FRAME_ON` at keyframe times (marker tracks)

- **THEN** no CTrack/CKey SHALL be created on the bone object for position X/Y/Z or rotation X/Y/Z for this VMD import path

#### Scenario: VMD interpolation data and frame list

- **WHEN** bone keyframes are imported

- **THEN** the four interpolation curves (X/Y/Z translation + rotation) from `VMDMotion::m_interpolation` SHALL be decoded and stored with each keyframe record on the bone tag

- **THEN** keyframe VMD frame numbers SHALL be consistent with `PMX_BONE_ANIM_FRAME_ON` navigation and internal storage

#### Scenario: Unmatched bone names logged

- **WHEN** a VMD file contains bone names that do not match any bone in the model

- **THEN** the unmatched bone names SHALL be recorded in `LoadVmdMotionLog::not_find_bone_name_list`

### Requirement: Bone tag VMD animation evaluation

In `BONE_MODE_ANIM`, `MMDBoneTag::Execute` SHALL evaluate bone animation using VMD bezier interpolation from the tag's stored keyframe data, instead of reading from `mmd_node_->GetLocalTransform()`.

#### Scenario: Bone animation evaluated from tag data

- **WHEN** `MMDBoneTag::Execute` runs in `BONE_MODE_ANIM`

- **THEN** the tag SHALL determine the current VMD frame from document time (at 30fps)

- **THEN** the tag SHALL find the surrounding keyframes from its stored keyframe list

- **THEN** the tag SHALL use `VMDBezier::FindBezierX` + `EvalY` for each channel to compute interpolation factors

- **THEN** position SHALL be interpolated per-axis using the computed factors

- **THEN** rotation SHALL be interpolated using quaternion slerp with the rotation bezier factor

- **THEN** the result SHALL be applied to the bone object's local animation transform (relative to the imported bind pose), without overwriting the serialized frozen bind pose each frame

#### Scenario: Before first keyframe or after last keyframe

- **WHEN** the current frame is before the first keyframe

- **THEN** the bone SHALL use the first keyframe's values

- **WHEN** the current frame is after the last keyframe

- **THEN** the bone SHALL use the last keyframe's values

### Requirement: User keyframe capture from viewport

The bone tag SHALL provide an "add keyframe" action that captures the bone's current local animation result from the C4D object (the same local pose delta targeted by `MMDBoneTag::Execute`, not the frozen bind pose), converts rotation to a quaternion, and writes or overwrites a keyframe record in the tag's internal structure at the current VMD frame. It SHALL create or update CKey entries on `PMX_BONE_ANIM_SPLINE` and `PMX_BONE_ANIM_FRAME_ON` as needed for timeline visibility. A "delete keyframe" action SHALL remove the keyframe at the current frame from internal storage and associated CKeys when applicable.

#### Scenario: Add keyframe after manual pose

- **WHEN** the user adjusts the bone in the viewport and invokes add keyframe

- **THEN** the tag SHALL store position and quaternion rotation in the internal keyframe structure at the current VMD frame

- **THEN** marker CTracks on SplineData and frame-on parameters SHALL be updated

#### Scenario: Delete keyframe

- **WHEN** the user invokes delete keyframe at a frame that has a stored keyframe

- **THEN** that keyframe SHALL be removed from internal storage and timeline markers updated per implementation rules

### Requirement: Append transform (fu-yo) in bone tag

In `BONE_MODE_ANIM`, `MMDBoneTag::Execute` SHALL implement PMX append transform (付与) logic. If the bone has `PMX_BONE_INHERIT_ROTATION` or `PMX_BONE_INHERIT_TRANSLATION` enabled, the tag SHALL read the animation values from the append source bone's tag and apply them with the configured weight.

#### Scenario: Rotation append from source bone

- **WHEN** a bone has `PMX_BONE_INHERIT_ROTATION` enabled with source bone index N and weight 0.5

- **THEN** the tag SHALL find bone N via `bone_manager_data_->FindBone(N)`

- **THEN** the tag SHALL read the source bone tag's current animation rotation

- **THEN** the tag SHALL slerp from identity to the source rotation by weight 0.5

- **THEN** the result SHALL be composed with the bone's own rotation

#### Scenario: Append with local flag

- **WHEN** a bone has append with `PMX_BONE_INHERIT_LOCAL` enabled

- **THEN** the tag SHALL use the source bone's local animate rotation instead of the global/append rotation

#### Scenario: Chained append

- **WHEN** bone A appends from bone B, and bone B appends from bone C

- **THEN** bone C SHALL execute before bone B, and bone B before bone A, as enforced by execution priority values (see execution priority requirement)

- **THEN** bone A's append SHALL read bone B's already-computed append rotation

### Requirement: IK solving in bone tag

In `BONE_MODE_ANIM`, `MMDBoneTag::Execute` for IK bones SHALL run `MMDIkSolver::Solve()` using C4D bone objects through the **`IMMDNode`** interface. The C4D plugin SHALL provide **`C4DIKChainNodeAdapter`** wrapping `BaseObject*` and `MMDBoneTag*`, maintaining a temporary global transform cache during the solve as required by C4D's scene graph behavior. `MMDNode` SHALL implement `IMMDNode` for libMMD-internal paths.

#### Scenario: IK bone solves during Execute

- **WHEN** `MMDBoneTag::Execute` runs for an IK bone in `BONE_MODE_ANIM`

- **WHEN** the IK solver is enabled

- **THEN** the tag SHALL construct `C4DIKChainNodeAdapter` instances for the IK chain

- **THEN** the tag SHALL call `MMDIkSolver::Solve()`

- **THEN** the IK rotation results SHALL be applied to the chain bones' transforms

#### Scenario: IK disabled via model manager parameter

- **WHEN** the IK solver is disabled via the model manager's IK checkbox (or CTrack keyframe)

- **THEN** `MMDBoneTag::Execute` SHALL skip the `Solve()` call

### Requirement: Bone tag execution priority within EXPRESSION

All bone tags that set bone transforms in `Execute` SHALL use **`EXECUTIONPRIORITY_EXPRESSION`** as the priority category (per Cinema 4D execution pipeline guidance for parameter changes on scene objects). Ordering SHALL be expressed **only** by the numeric priority value, not by switching to `EXECUTIONPRIORITY_ANIMATION` or `EXECUTIONPRIORITY_DYNAMICS` for bone tags.

Let `deform_layer` be the bone's PMX deform layer index and `append_depth` the global append recursion depth for that bone (bones at the same depth with no dependency MAY share the same numeric priority).

- **Before-physics bones** (`PMX_BONE_PHYSICS_AFTER_DEFORM == false`): `priority = deform_layer * 100 + append_depth`

- **Model manager physics step** (single owner): `priority = 5000` (fixed)

- **After-physics bones** (`PMX_BONE_PHYSICS_AFTER_DEFORM == true`): `priority = 6000 + deform_layer * 100 + append_depth`

#### Scenario: Before-physics bones run before physics

- **WHEN** a before-physics bone and the model manager both use `EXECUTIONPRIORITY_EXPRESSION`

- **THEN** the bone's numeric priority SHALL be less than `5000`

- **THEN** the bone tag SHALL run before the model manager's physics step

#### Scenario: After-physics bones run after physics

- **WHEN** an after-physics bone uses `EXECUTIONPRIORITY_EXPRESSION`

- **THEN** its numeric priority SHALL be at least `6000`

- **THEN** it SHALL run after the model manager's physics step

#### Scenario: Append depth ordering

- **WHEN** two bones share the same `deform_layer` and differ in `append_depth`

- **THEN** the bone with smaller `append_depth` SHALL have a smaller or equal numeric priority so it executes first

