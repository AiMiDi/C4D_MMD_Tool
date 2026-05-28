# Physics System

## Purpose

Define rigid body and joint physics behavior, runtime rebuild, and external C4D bone binding for animation playback.

## Overview

MMD models use rigid body physics for secondary motion (hair, clothing, accessories). The plugin maps PMX rigid body and joint definitions to C4D objects, with simulation driven by bullet3 through libMMD.

## Rigid Bodies (`MMDRigidObject`)

Each PMX rigid body becomes a `MMDRigidObject` child of `MMDRigidManagerObject`.

### Properties (from PMX)

| Property | Description |
|----------|-------------|
| Shape | Sphere, Box, or Capsule |
| Size | Dimensions per shape type |
| Position/Rotation | World-space transform |
| Mass | Object mass (0 = kinematic) |
| Linear damping | Movement resistance |
| Angular damping | Rotation resistance |
| Restitution | Bounciness |
| Friction | Surface friction |

### Physics Modes

| Mode | Behavior |
|------|----------|
| Follow bone | Kinematic — rigid body follows bone transform |
| Physics | Dynamic — bullet3 simulates, result ignored by bones |
| Physics + bone | Dynamic — simulation result drives bone transform |

### Bone Binding

Each rigid body references a bone index. The binding determines how physics interacts with the skeletal animation.

## Joints (`MMDJointObject`)

Each PMX joint becomes a `MMDJointObject` child of `MMDJointManagerObject`.

### Properties (from PMX)

| Property | Description |
|----------|-------------|
| Type | 6DOF Spring (standard MMD joint type) |
| Rigid body A/B | Connected rigid bodies |
| Position/Rotation | Joint anchor transform |
| Position limits | Min/max translation per axis |
| Rotation limits | Min/max rotation per axis |
| Spring position | Spring constants for translation |
| Spring rotation | Spring constants for rotation |

## Parametric Creation (Runtime Rebuild)

### MMDRigidBody Parametric Create

`MMDRigidBody` supports creation from individual C4D parameters (shape, size, position, rotation, mass, friction, restitution, damping, physics mode, collision group/mask) instead of a `PMXRigidbody` struct. Used for scene-reload runtime rebuild. Result is equivalent to creation from `PMXRigidbody`.

### MMDJoint Parametric Create

`MMDJoint` supports creation from individual C4D parameters (position, rotation, position limits, rotation limits, spring constants, two `MMDRigidBody*` references) instead of a `PMXJoint` struct. Used for scene-reload runtime rebuild. Result is equivalent to creation from `PMXJoint`.

### MMDRigidObject Reverse Build

`MMDRigidObject` extracts physics parameters from its C4D BaseContainer (shape, size, mass, friction, restitution, damping, collision group, etc.) to create a corresponding `MMDRigidBody` during runtime rebuild. The rigid body is correctly associated with its bound bone node.

### MMDJointObject Reverse Build

`MMDJointObject` extracts joint parameters from its C4D BaseContainer (position/rotation limits, spring constants, connected rigid body references) to create a corresponding `MMDJoint` during runtime rebuild. The joint is correctly associated with its two connected rigid bodies.

## Simulation Flow

```
MMDModelManagerObject::Execute() (per frame)
    │
    ├── libmmd::VMDAnimation::Evaluate(frame)
    │       → Bone transforms from keyframes
    │
    ├── libmmd IK solver
    │       → IK-adjusted bone transforms
    │
    └── libmmd::MMDPhysicsManager::SyncPhysics()
            │
            ├── Update kinematic rigid bodies from bone transforms
            ├── bullet3 step simulation
            └── Read back dynamic rigid body transforms → bone transforms
```

## Coordinate Conversion (MMD → C4D)

Rigid body transforms from libMMD are in original PMX space. `MMDRigidObject::Execute` converts to C4D by negating the Z row of the transform matrix (position Z negated, rotation Z components negated).

## Source Files

| File | Role |
|------|------|
| `module/tools/object/mmd_rigid_manager.h/cpp` | Rigid body manager (creates children) |
| `module/tools/object/mmd_joint_manager.h/cpp` | Joint manager (creates children) |
| `module/tools/object/mmd_rigid.h/cpp` | Single rigid body ObjectData |
| `module/tools/object/mmd_joint.h/cpp` | Single joint ObjectData |
| libMMD `MMDPhysicsManager` | Physics simulation via bullet3 |

## Requirements

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
