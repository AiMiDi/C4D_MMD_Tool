## Purpose

Control IK solver visibility, enablement, persistence, and runtime ownership for model-manager animation playback.

## Requirements

### Requirement: IK Solver List Display
The system SHALL display a BOOL checkbox for each IK solver from the imported PMX model in the `MODEL_IK_GRP` group of `MMDModelManagerObject`. The label of the checkbox SHALL use the solver name (i.e., IK bone name).

#### Scenario: PMX Model Contains IK Solvers
- **WHEN** a user imports a PMX model containing 4 IK solvers (Right Leg IK, Left Leg IK, Right Toe IK, Left Toe IK)
- **THEN** MODEL_IK_GRP SHALL display 4 BOOL checkboxes labeled with their corresponding solver names, all enabled (checked) by default

#### Scenario: PMX Model Contains No IK Solvers
- **WHEN** a user imports a PMX model containing no IK bones
- **THEN** MODEL_IK_GRP SHALL be empty and display no checkboxes

### Requirement: IK Solver Enable/Disable Control
The user SHALL be able to enable or disable the corresponding IK solver via the BOOL checkbox in MODEL_IK_GRP. In animation mode (`MODEL_MODE_ANIM`, after the `*_MODE_VMD` merge), the IK solver enable state SHALL be read by the IK bone's `MMDBoneTag::Execute` to determine whether to run `MMDIkSolver::Solve()`. The operation SHALL target the standalone `MMDIKManager` owned by `MMDModelManagerObject`, not a `PMXModel`-owned IK manager.

#### Scenario: Disabling an IK Solver
- **WHEN** a user unchecks the "Right Leg IK" checkbox
- **THEN** the corresponding IK bone's `MMDBoneTag::Execute` SHALL skip calling `MMDIkSolver::Solve()`
- **THEN** the `PMX_BONE_IS_IK` property of the bone tag SHALL remain unchanged

#### Scenario: Re-enabling an IK Solver
- **WHEN** a user re-checks the previously disabled "Right Leg IK" checkbox
- **THEN** the corresponding IK bone's `MMDBoneTag::Execute` SHALL resume calling `MMDIkSolver::Solve()`

### Requirement: Operable Across All Modes
The IK solver checkboxes SHALL be operable in all modes (Edit/Anim/VMD), unrestricted by `model_mode_`.

#### Scenario: Operating IK Control in Animation Mode
- **WHEN** the current mode is Anim mode, and the user toggles an IK solver checkbox
- **THEN** the operation SHALL successfully execute, and the checkbox state updates instantly

#### Scenario: Operating IK Control in VMD Mode
- **WHEN** the current mode is VMD mode, and the user toggles an IK solver checkbox
- **THEN** the operation SHALL successfully execute, and the solver state takes effect instantly

### Requirement: IK Solver State Persistence
The system SHALL persist the enablement state of IK solvers by solver name into the C4D scene file, using a `HashMap<String, Bool>` format. The IK solver state SHALL be applied to the standalone `MMDIKManager` owned by the model manager and communicated to bone tags during execution.

#### Scenario: Saving and Loading a Scene
- **WHEN** a user disables "Right Leg IK", saves the scene, and reopens the scene
- **THEN** the "Right Leg IK" checkbox SHALL appear unchecked

#### Scenario: IK state communicated to bone tag
- **WHEN** a scene is loaded and IK states are restored
- **THEN** the model manager SHALL provide IK enable states to bone tags during execution
- **THEN** IK bone tags SHALL query the model manager's IK state to determine whether to solve

### Requirement: Model manager owns standalone IK manager

`MMDModelManagerObject` SHALL construct and own the standalone `MMDIKManager` used by animation-mode execution. Bone tags SHALL not look up IK solvers through `mmd_model_` or `PMXModel`.

#### Scenario: IK manager available without PMXModel
- **WHEN** the model enters animation mode after PMX import or scene reload
- **THEN** `MMDModelManagerObject` SHALL provide a standalone `MMDIKManager` populated from bone-tag IK data
- **THEN** bone tags and model-manager UI SHALL query this standalone manager rather than `mmd_model_->GetIKManager()`

### Requirement: Automatic State Restoration After RebuildRuntime
The system SHALL apply the persisted states from `ik_solver_enable_states_` to the newly created IK solvers by name matching after `RebuildRuntime` is completed (after `SetMMDModel`).

#### Scenario: Runtime Reconstruction After Reopening Scene
- **WHEN** a scene is reopened, and `RebuildRuntime` creates a new `PMXModel` (IK solvers are all enabled by default)
- **THEN** the system SHALL set the solvers recorded as disabled in `ik_solver_enable_states_` to disabled, while unrecorded solvers remain enabled by default

#### Scenario: Mismatched Solver Name
- **WHEN** the persisted state contains solver "Right Leg IK", but the solver does not exist in the reconstructed model
- **THEN** the system SHALL ignore this entry without throwing an error

### Requirement: VMD IK Keyframes Imported as C4D Parameter Keyframes
During VMD animation import, the system SHALL convert the IK enable keyframes from `VMDFile::m_iks` into C4D parameter keyframes (CTrack/CKey), set them on the corresponding IK checkboxes, and disable libMMD's VMD IK enablement control. A CTrack is only created if there is at least one disabled state keyframe for a particular IK (no redundant animation tracks are created if all are enabled by default).

#### Scenario: Import VMD Containing IK Keyframes
- **WHEN** a user imports a VMD file containing keyframes where "Right Leg IK" is enabled at frame 0, disabled at frame 100, and enabled at frame 200
- **THEN** the "Right Leg IK" checkbox SHALL possess a corresponding CTrack containing 3 CKeys (step interpolation), and the IK state changes are visible on the C4D timeline

#### Scenario: IK State Driven by C4D Keyframes During VMD Playback
- **WHEN** VMD animation plays to frame 150 (where "Right Leg IK" should be disabled)
- **THEN** the IK checkbox SHALL appear unchecked, and the corresponding `MMDIkSolver` SHALL be disabled

#### Scenario: No CTrack Created When VMD IK Is Entirely Enabled
- **WHEN** a user imports a VMD file where all keyframes for a certain IK are set to enabled
- **THEN** no CTrack SHALL be created for that IK checkbox, keeping its default enabled state

#### Scenario: VMD Contains No IK Keyframes
- **WHEN** a user imports a VMD file containing no IK keyframes
- **THEN** the IK checkbox SHALL maintain its current state and create no CTrack

### Requirement: libMMD VMD IK Enablement Control Toggle
`VMDAnimation` SHALL provide a `SetApplyIKEnable(bool)` interface. When set to false, `Evaluate` SHALL skip the evaluation of the IK controller and not modify the solver's enable state.

#### Scenario: Playback After Disabling VMD IK Control
- **WHEN** `Evaluate` is executed after calling `SetApplyIKEnable(false)`
- **THEN** `VMDIKController::Evaluate` SHALL not be called, and the solver's enable state is controlled externally (by C4D keyframes)

### Requirement: Dynamic Description Type Registration
The system SHALL append the `IK_SOLVER_ENABLE` value (value 9) to the end of the `MMDModelRootDynamicDescriptionType` enum, without altering the numerical values of existing enum entries.

#### Scenario: Preserve Existing Dynamic Description Values
- **WHEN** dynamic description types are registered
- **THEN** `IK_SOLVER_ENABLE` SHALL be appended as value 9
- **THEN** existing enum numerical values SHALL remain unchanged
