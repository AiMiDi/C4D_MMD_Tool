# Model Runtime Reconstruction

## ADDED Requirements

### Requirement: Automatically Rebuild PMXModel Runtime Object After Scene Load

When a scene file is opened and `mmd_model_` is nullptr, the system SHALL automatically rebuild the complete `libmmd::PMXModel` runtime object from the serialized C4D sub-object data, including the node tree (`MMDNodeManager`), physics manager (`MMDPhysicsManager`), and IK solver (`MMDIKManager`).

#### Scenario: Runtime Reconstruction After Normal Scene Reload
- **WHEN** a user opens a saved scene file containing `MMDModelManagerObject`
- **THEN** the system detects `mmd_model_` is nullptr during the first `Execute()` call, automatically triggering the runtime reconstruction
- **THEN** after reconstruction, `mmd_model_` is not nullptr, and `GetNodeManager()`, `GetPhysicsManager()`, `GetIKManager()` all return valid pointers

#### Scenario: Fallback Handling When Reconstruction Fails
- **WHEN** an error occurs during runtime reconstruction (e.g. incomplete sub-object data)
- **THEN** the system SHALL set `is_runtime_initialized_` to true to prevent repeated retries
- **THEN** the plugin can still work normally in edit mode, only animation and physics features are unavailable

### Requirement: Rebuild Node Tree from Bone Tags

The system SHALL iterate through all bone tags in the `bone_list_` of `MMDBoneManagerObject`, create a corresponding `PMXNode` for each bone, and correctly set the node's name, initial position, parent-child relationship, deform depth, append properties, and IK solver.

#### Scenario: Bone Node Properties Rebuilt Correctly
- **WHEN** there are bone joint objects with `MMDBoneTag` in the scene
- **THEN** the system creates a `PMXNode` for each bone tag
- **THEN** the name and initial position (`SetTranslate`) of each `PMXNode` match the corresponding C4D bone tag parameters
- **THEN** the parent-child relationship is correctly established via `AddChild()`
- **THEN** deform depth, append rotate/translate/local/weight, and other properties are correctly set from the bone tag parameters

#### Scenario: IK Solver Reconstruction
- **WHEN** a bone tag contains IK configuration parameters (target bone, chain length, iterations, angle limits)
- **THEN** the system creates an `MMDIkSolver` for the bone and correctly sets the IK chain, iterations, and angle limits
- **THEN** `PMXNode::SetIKSolver()` associates the IK solver to the corresponding node

### Requirement: Rebuild Physics Rigid Bodies from Rigid Body Objects

The system SHALL iterate through all `MMDRigidObject`s among the child objects of `MMDRigidManagerObject`, creating a corresponding `MMDRigidBody` in the `MMDPhysicsManager` for each rigid body object.

#### Scenario: Rigid Body Properties Rebuilt Correctly
- **WHEN** there are `MMDRigidObject` child objects in the scene
- **THEN** the system calls `MMDPhysicsManager::AddRigidBody()` to create an `MMDRigidBody` for each `MMDRigidObject`
- **THEN** the rigid body's shape, dimensions, mass, friction, restitution, damping, collision group, and other properties are correctly set from the C4D object parameters
- **THEN** the rigid body is correctly bound to the corresponding `PMXNode`

### Requirement: Rebuild Physics Joints from Joint Objects

The system SHALL iterate through all `MMDJointObject`s among the child objects of `MMDJointManagerObject`, creating a corresponding `MMDJoint` in the `MMDPhysicsManager` for each joint object.

#### Scenario: Joint Properties Rebuilt Correctly
- **WHEN** there are `MMDJointObject` child objects in the scene
- **THEN** the system calls `MMDPhysicsManager::AddJoint()` to create an `MMDJoint` for each `MMDJointObject`
- **THEN** the joint's position/rotation limits, spring constants, and references to the two connected rigid bodies are correctly set from the C4D object parameters

### Requirement: Reconnect Sub-object Runtime Pointers After Reconstruction

The system SHALL reconnect the libmmd runtime pointers (`mmd_node_`, `mmd_rigidbody_`, `mmd_joint_`) of each sub-object (`MMDBoneTag`, `MMDRigidObject`, `MMDJointObject`) to the newly created objects after the `PMXModel` reconstruction is complete.

#### Scenario: Bone Tag Pointer Reconnection
- **WHEN** `PMXModel` reconstruction is complete
- **THEN** the `mmd_node_` of each `MMDBoneTag` points to the reconstructed `PMXNode`
- **THEN** the `ik_solver_` of a bone tag containing an IK configuration points to the reconstructed `MMDIkSolver`

#### Scenario: Rigid Body Object Pointer Reconnection
- **WHEN** `PMXModel` reconstruction is complete
- **THEN** the `mmd_rigidbody_` of each `MMDRigidObject` points to the reconstructed `MMDRigidBody`

#### Scenario: Joint Object Pointer Reconnection
- **WHEN** `PMXModel` reconstruction is complete
- **THEN** the `mmd_joint_` of each `MMDJointObject` points to the reconstructed `MMDJoint`

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