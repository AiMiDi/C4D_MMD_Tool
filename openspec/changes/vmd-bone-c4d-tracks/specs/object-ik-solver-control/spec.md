## MODIFIED Requirements

### Requirement: IK Solver Enable/Disable Control

The user SHALL be able to enable or disable the corresponding IK solver via the BOOL checkbox in MODEL_IK_GRP. In animation mode (`MODEL_MODE_ANIM`, after the `*_MODE_VMD` merge), the IK solver enable state SHALL be read by the IK bone's `MMDBoneTag::Execute` to determine whether to run `MMDIkSolver::Solve()`. The operation SHALL target the standalone `MMDIKManager` owned by `MMDModelManagerObject`, not a `PMXModel`-owned IK manager.

#### Scenario: Disabling an IK Solver
- **WHEN** a user unchecks the "Right Leg IK" checkbox
- **THEN** the corresponding IK bone's `MMDBoneTag::Execute` SHALL skip calling `MMDIkSolver::Solve()`
- **THEN** the `PMX_BONE_IS_IK` property of the bone tag SHALL remain unchanged

#### Scenario: Re-enabling an IK Solver
- **WHEN** a user re-checks the previously disabled "Right Leg IK" checkbox
- **THEN** the corresponding IK bone's `MMDBoneTag::Execute` SHALL resume calling `MMDIkSolver::Solve()`

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
