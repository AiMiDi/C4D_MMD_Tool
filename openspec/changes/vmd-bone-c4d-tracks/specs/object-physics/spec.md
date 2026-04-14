## MODIFIED Requirements

### Requirement: Physics simulation flow with external bone binding

The physics simulation flow SHALL read bone transforms via `IMMDNode` (same adapters as IK) instead of from in-model `MMDNode` transforms. The model manager SHALL own the standalone `MMDPhysicsManager` used for simulation, and SHALL run physics in its `Execute` at `EXECUTIONPRIORITY_EXPRESSION` with numeric priority `5000`, after before-physics bone tags (priority less than `5000`) and before after-physics bone tags (priority `6000` and above), all within the same priority category.

#### Scenario: Physics step in model manager Execute
- **WHEN** `MMDModelManagerObject::Execute` runs in `MODEL_MODE_ANIM` at `EXECUTIONPRIORITY_EXPRESSION`
- **THEN** it SHALL call `SyncBonePositionToPhysics` on DynamicAndBoneMerge rigid bodies (which reads C4D bone positions via `IMMDNode`)
- **THEN** it SHALL call `MMDPhysics::Update(elapsed)` to step the Bullet simulation
- **THEN** it SHALL call `ReflectGlobalTransform` on dynamic rigid bodies (which writes physics results to C4D bones via `IMMDNode`)

#### Scenario: Kinematic rigid body follows C4D bone
- **WHEN** a kinematic rigid body's `getWorldTransform` is called by Bullet
- **THEN** the `ExternalKinematicMotionState` SHALL read the bound C4D bone's global matrix via `binding.node->GetGlobalTransform()` and apply the offset matrix

#### Scenario: Dynamic rigid body drives C4D bone
- **WHEN** `ReflectGlobalTransform` is called on a dynamic rigid body with external binding
- **THEN** the physics-computed global transform (minus offset) SHALL be written to the C4D bone via `binding.node->SetGlobalTransform()`

### Requirement: Rigid body creation with external binding during import and rebuild

When creating rigid bodies during PMX import or runtime rebuild, the system SHALL use `MMDRigidBody::Create(const PMXRigidbody&, IMMDNode*)`, passing an `IMMDNode` adapter for the C4D bone object identified by the rigid body's bone index; offset uses `GetInitialGlobalTransform()` (e.g. after `SetBindingGlobalTransform()` on the adapter).

#### Scenario: PMX import creates rigid body with external binding
- **WHEN** a PMX model is imported and rigid bodies are created
- **THEN** each rigid body SHALL be created with `Create(..., IMMDNode*)` pointing to the corresponding C4D bone joint adapter
- **THEN** the `initialGlobalTransform` SHALL be set from the bone object's global matrix at import time

#### Scenario: Unbound rigid body (no bone reference)
- **WHEN** a rigid body has no bone binding (bone index = -1)
- **THEN** the rigid body SHALL be created with the root bone object's transform as `initialGlobalTransform`
- **THEN** plugin policy SHALL avoid write-back where no bone host exists (e.g. omit external binding or use a no-op `IMMDNode` adapter as appropriate)
