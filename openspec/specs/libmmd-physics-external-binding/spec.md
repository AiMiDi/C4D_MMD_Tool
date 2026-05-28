# libmmd-physics-external-binding Specification

## Purpose
TBD - created by archiving change vmd-bone-c4d-tracks. Update Purpose after archive.
## Requirements
### Requirement: IMMDNode::GetInitialGlobalTransform for rigid-body offset

The libMMD library SHALL extend `IMMDNode` with `GetInitialGlobalTransform() const` returning the world matrix used to compute rigid-body offset (`m_offsetMat = GetInitialGlobalTransform().inverse() * rbMat`). In-model `MMDNode` SHALL implement it by delegating to `GetGlobalTransform()`. External hosts (e.g. C4D adapters) MAY snapshot bind-time pose via a dedicated field and `SetBindingGlobalTransform()` (or equivalent) before `MMDRigidBody::Create`.

#### Scenario: Offset uses initial global at Create time

- **WHEN** `MMDRigidBody::Create(const PMXRigidbody&, IMMDNode*)` runs

- **THEN** the offset matrix SHALL use `node->GetInitialGlobalTransform()`

### Requirement: MMDRigidBody::Create overload with IMMDNode

`MMDRigidBody` SHALL provide a `Create` overload that accepts `const PMXRigidbody&` and `IMMDNode*` instead of `MMDModel*` and `MMDNode*`. The overload SHALL use `GetInitialGlobalTransform()` for offset matrix computation and create MotionStates that delegate to that node.

#### Scenario: Create rigid body with external node

- **WHEN** `Create` is called with a non-null `IMMDNode*`

- **THEN** the rigid body SHALL be created with external MotionStates wired to that node

- **THEN** the offset matrix SHALL be computed from `GetInitialGlobalTransform()`

- **THEN** no `MMDModel*` or in-model `MMDNode*` SHALL be required

#### Scenario: Create rigid body without a node

- **WHEN** `Create` is called with `node == nullptr`

- **THEN** creation SHALL fail (`Create` returns false)

### Requirement: External MotionState classes using IMMDNode

The library SHALL provide MotionState implementations (`ExternalKinematicMotionState`, `ExternalDynamicMotionState`, `ExternalDynamicAndBoneMergeMotionState`) that read/write transforms through `IMMDNode*` instead of in-model `MMDNode*` pointers.

#### Scenario: Kinematic motion state reads from IMMDNode

- **WHEN** Bullet calls `getWorldTransform` on an `ExternalKinematicMotionState`

- **THEN** the MotionState SHALL use `node->GetGlobalTransform()` to obtain the bone transform

- **THEN** the result SHALL be multiplied by the offset matrix and returned

#### Scenario: Dynamic motion state writes physics result via IMMDNode

- **WHEN** `ReflectGlobalTransform` is called on an `ExternalDynamicMotionState`

- **THEN** the MotionState SHALL compute the bone global transform from the physics result

- **THEN** the MotionState SHALL call `node->SetGlobalTransform(result)` to write back

#### Scenario: DynamicAndBoneMerge sync and velocity

- **WHEN** `SyncBonePosition` is called on an `ExternalDynamicAndBoneMergeMotionState`

- **THEN** the MotionState SHALL read the bone position via `node->GetGlobalTransform()`

- **THEN** `ComputeBoneVelocity` SHALL compute velocity from position deltas as before

### Requirement: CalcLocalTransform skip in external binding mode

`MMDRigidBody::CalcLocalTransform` SHALL be a no-op when the rigid body was created with the external `IMMDNode` overload (no in-model `MMDNode*`), since the external system (C4D) manages local transforms from its scene graph.

#### Scenario: CalcLocalTransform with external binding

- **WHEN** `CalcLocalTransform` is called on a rigid body created with `Create(..., IMMDNode*)`

- **THEN** no transform computation or assignment SHALL occur

### Requirement: MMDPhysicsManager destructor null safety

`MMDPhysicsManager` destructor SHALL check for null `m_mmdPhysics` before attempting to remove joints and rigid bodies, preventing crashes when `Create()` was never called.

#### Scenario: Destroy without Create

- **WHEN** an `MMDPhysicsManager` is destroyed without having called `Create()`

- **THEN** the destructor SHALL complete without error

### Requirement: Unit tests for external binding

The libMMD test suite SHALL include tests verifying that rigid bodies created with `Create(..., IMMDNode*)` correctly read/write transforms during physics simulation.

#### Scenario: Physics simulation with external binding

- **WHEN** a kinematic rigid body is created with an `IMMDNode` implementation

- **THEN** the Bullet simulation SHALL use that transform

- **WHEN** a dynamic rigid body's `ReflectGlobalTransform` is called

- **THEN** the `IMMDNode::SetGlobalTransform` path SHALL receive the physics result

