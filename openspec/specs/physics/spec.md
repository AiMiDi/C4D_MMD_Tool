# Physics System

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
