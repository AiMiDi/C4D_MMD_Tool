# Model Runtime Reconstruction

## Purpose

Reconstruct standalone model runtime managers from scene objects after scene load, PMX import, and edit/animation mode transitions.
## Requirements
### Requirement: Automatically Rebuild Standalone Runtime Managers After Scene Load

When a scene file is opened and standalone runtime managers are not initialized, the system SHALL automatically rebuild the model-manager-owned `MMDIKManager` and `MMDPhysicsManager` from the serialized C4D sub-object data. The system SHALL NOT rebuild a full `PMXModel`, `MMDModel`, or `MMDNodeManager`. Rigid bodies SHALL be created using `MMDRigidBody::Create(..., IMMDNode*)` with adapters that read/write C4D bone object transforms.

#### Scenario: Runtime Reconstruction After Normal Scene Reload
- **WHEN** a user opens a saved scene file containing `MMDModelManagerObject`
- **THEN** the system SHALL detect uninitialized standalone runtime managers during the first `Execute()` call, automatically triggering runtime reconstruction
- **THEN** after reconstruction, the standalone `MMDIKManager` SHALL contain solvers rebuilt from bone-tag IK data
- **THEN** the standalone `MMDPhysicsManager` SHALL be valid with rigid bodies and joints registered in the Bullet world
- **THEN** no `PMXModel`, `MMDModel`, or `MMDNodeManager` SHALL be created

#### Scenario: Fallback Handling When Reconstruction Fails
- **WHEN** an error occurs during standalone runtime reconstruction (e.g. incomplete sub-object data)
- **THEN** the system SHALL set `is_runtime_initialized_` to true to prevent repeated retries
- **THEN** the plugin SHALL still work in edit mode; only standalone IK / physics simulation is unavailable

### Requirement: Rebuild IK Solvers from Bone Tag Data

The system SHALL iterate through IK-enabled `MMDBoneTag`s and rebuild a standalone `MMDIKManager` owned by `MMDModelManagerObject`. Each solver SHALL be configured from bone-tag IK target, iterate count, limit angle, and dynamic IK chain entries, and SHALL use `IMMDNode` adapters bound to C4D bones.

#### Scenario: IK solvers rebuilt correctly
- **WHEN** there are IK bones in the scene
- **THEN** the system SHALL create one standalone `MMDIkSolver` per IK bone in the model-manager-owned `MMDIKManager`
- **THEN** each solver SHALL use bone-tag data for target bone, iteration count, unit angle, and IK chain limits
- **THEN** the solver SHALL operate on `IMMDNode` adapters rather than `MMDNode*`

### Requirement: Rebuild Physics Rigid Bodies from Rigid Body Objects

The system SHALL iterate through all `MMDRigidObject`s among the child objects of `MMDRigidManagerObject`, creating a corresponding `MMDRigidBody` in the `MMDPhysicsManager` for each rigid body object. Each rigid body SHALL be created using `Create(..., IMMDNode*)` with the adapter for the bound C4D bone object.

#### Scenario: Rigid Body Properties Rebuilt Correctly
- **WHEN** there are `MMDRigidObject` child objects in the scene
- **THEN** the system SHALL call `MMDPhysicsManager::AddRigidBody()` to create an `MMDRigidBody` for each `MMDRigidObject`
- **THEN** rigid body creation SHALL use `Create(..., IMMDNode*)` for the corresponding C4D bone object
- **THEN** the rigid body's shape, dimensions, mass, and other properties SHALL be correctly set from the C4D object parameters

### Requirement: Rebuild Physics Joints from Joint Objects

The system SHALL iterate through all `MMDJointObject`s among the child objects of `MMDJointManagerObject`, creating a corresponding `MMDJoint` in the `MMDPhysicsManager` for each joint object.

#### Scenario: Joint Properties Rebuilt Correctly
- **WHEN** there are `MMDJointObject` child objects in the scene
- **THEN** the system SHALL call `MMDPhysicsManager::AddJoint()` to create an `MMDJoint` for each `MMDJointObject`
- **THEN** the joint's position/rotation limits, spring constants, and references to the two connected rigid bodies SHALL be correctly set from the C4D object parameters

### Requirement: Edit Mode Modifications Reflected in Runtime Objects

Modifications made by the user to the bone/rigid body/joint properties in edit mode SHALL automatically reflect in the libmmd runtime objects when switching to animation or VMD mode.

#### Scenario: Editing Bone Position Affects Animation
- **WHEN** a user modifies the position parameters of a bone in edit mode
- **WHEN** the user switches to VMD mode
- **THEN** the initial position of the corresponding `PMXNode` matches the modified C4D bone parameters
- **THEN** the VMD animation calculates using the updated initial position

#### Scenario: Editing Rigid Body Parameters Affects Physics
- **WHEN** a user modifies the mass or damping parameters of a rigid body in edit mode
- **WHEN** the user switches to animation or VMD mode
- **THEN** the corresponding `MMDRigidBody` uses the updated parameters for physics simulation

