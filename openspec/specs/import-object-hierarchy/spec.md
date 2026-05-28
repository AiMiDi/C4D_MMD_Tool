# Object Hierarchy

## Purpose

MMD data is represented in Cinema 4D as a tree of custom ObjectData plugins. Each Manager object owns a category of MMD data and creates child objects during import.

## Requirements

### Requirement: MMD model manager hierarchy
The system SHALL represent imported MMD model data as an `MMDModelManagerObject` root with bone, mesh, rigid body, and joint manager children.

#### Scenario: Import creates manager hierarchy
- **WHEN** a PMX model is imported
- **THEN** the created model root SHALL own bone, mesh, rigid, and joint manager objects that contain their respective imported data

### Requirement: Manager-owned object data
Each MMD manager SHALL own the Cinema 4D objects and runtime links for its category of PMX data.

#### Scenario: Managers load PMX categories
- **WHEN** `MMDModelManagerObject::LoadPMX()` delegates to child managers
- **THEN** bone data SHALL create joint objects with bone tags, mesh data SHALL create polygon objects and material links, rigid data SHALL create rigid objects, and joint data SHALL create joint objects

### Requirement: Runtime rebuild after scene load
The model manager SHALL rebuild libMMD runtime objects from serialized Cinema 4D object data when a scene is reopened.

#### Scenario: Scene opens without runtime pointers
- **WHEN** an MMD scene is loaded and runtime pointers are not initialized
- **THEN** the model manager SHALL rebuild the PMX model runtime, reconnect child manager pointers, and restore staged animation data

### Requirement: Inter-manager messaging
Managers SHALL communicate through explicit message structs rather than relying on implicit scene traversal for cross-manager state updates.

#### Scenario: Manager state is requested
- **WHEN** one manager needs state owned by another manager
- **THEN** the request SHALL use the documented model, bone, or mesh manager message structure

## Hierarchy Structure

```
MMDModelManagerObject (root, ID: 1056724)
├── MMDBoneManagerObject (ID: 1057944)
│   └── [bone joints as child objects with MMDBoneTag]
├── MMDMeshManagerObject (ID: 1057943)
│   └── [polygon objects per submesh]
├── MMDRigidManagerObject (ID: 1057945)
│   └── MMDRigidObject × N (ID: 1056722)
└── MMDJointManagerObject (ID: 1057946)
    └── MMDJointObject × N (ID: 1056723)
```

## Base Manager (`mmd_manager.hpp`)

`MMDManagerObject` — base class for manager objects.

- Inherits: `ObjectData`
- Provides display tag and protection tag management
- Pattern: each manager holds a pointer to its parent `MMDModelManagerObject`

## MMDModelManagerObject (`mmd_model_manager.h/cpp`)

Root object representing a complete PMX model.

- Owns cross-references to all child managers: `bone_manager_data_`, `mesh_manager_data_`, `rigid_manager_data_`, `joint_manager_data_`
- `CreateManagers()` — creates bone/mesh/rigid/joint manager children
- `LoadPMX(PMXModel*)` — delegates to each manager's `LoadPMX()`
- `LoadVMDMotion()` / `SaveVMDMotion()` — manages VMD animation data
- Stores `animations_` array of `libmmd::VMDAnimation`
- `Execute()` drives animation playback and physics simulation via libMMD
- Contains `EditorSubMorphDialog` for morph editing UI (embedded in this file)

## MMDBoneManagerObject (`mmd_bone_manager.h/cpp`)

- Creates bone joints from PMX bone data
- Each bone joint gets a `MMDBoneTag` (TagData)
- Manages IK chains and bone inheritance relationships

## MMDMeshManagerObject (`mmd_mesh_manager.h/cpp`)

- Creates polygon objects from PMX mesh data
- Handles vertex positions, normals, UVs, weight maps
- Delegates material creation to `MMDMaterialManager`
- Supports mesh morphs (vertex offset morphs applied to mesh)

## MMDRigidManagerObject (`mmd_rigid_manager.h/cpp`)

- Creates `MMDRigidObject` children from PMX rigid body data
- Rigid bodies reference bones for kinematic/dynamic binding

## MMDJointManagerObject (`mmd_joint_manager.h/cpp`)

- Creates `MMDJointObject` children from PMX joint data
- Joints connect two rigid bodies with constraint parameters

## Individual Object Plugins

### MMDRigidObject (`mmd_rigid.h/cpp`)
- Represents a single PMX rigid body
- Properties: shape (sphere/box/capsule), mass, friction, restitution, damping
- Modes: follow bone, physics, physics + bone

### MMDJointObject (`mmd_joint.h/cpp`)
- Represents a single PMX joint (6DOF spring constraint)
- Properties: position/rotation limits, spring constants
- Links two `MMDRigidObject` instances

### MMDCamera (`mmd_camera.h/cpp`)
- Custom camera object for VMD camera animation
- Stores VMD camera keyframes as C4D animation tracks
- Separate from the model hierarchy (scene-level object)

## Runtime Rebuild on Scene Load

When a scene file is opened and `mmd_model_` is nullptr, the system automatically rebuilds the complete `libmmd::PMXModel` runtime object from serialized C4D sub-object data.

### RebuildRuntime() Flow

`MMDModelManagerObject::RebuildRuntime()` orchestrates the full rebuild:
1. Creates empty `PMXModel`
2. Rebuilds node tree from bone tags (`MMDBoneManagerObject::RebuildNodes()`)
3. Rebuilds rigid bodies from rigid objects (`MMDRigidManagerObject::RebuildRigidBodies()`) — sorted by `RIGID_INDEX`
4. Rebuilds joints from joint objects (`MMDJointManagerObject::RebuildJoints()`) — sorted by joint index
5. Calls `SetMMDModel()` to distribute pointers to child managers
6. Reconnects sub-object runtime pointers (`ReconnectNodePointers`, `ReconnectRigidBodyPointers`, `ReconnectJointPointers`)
7. Restores VMD animations from staged binary data
8. Updates document time range (`SetMaxTime`, `SetLoopMaxTime`)

### Execute() Integration

`Execute()` checks `is_runtime_initialized_` (thread-safe `maxon::Synchronized<Bool>`). On first call after `Read()`, triggers `RebuildRuntime()` and sets flag to true. Failure displays error via `StatusSetBar()` and sets flag to prevent per-frame retries.

### Pointer Reconnection

After rebuild, each sub-object's libmmd pointer is reconnected:
- `MMDBoneTag::mmd_node_` → rebuilt `PMXNode`
- `MMDBoneTag::ik_solver_` → rebuilt `MMDIkSolver`
- `MMDRigidObject::mmd_rigidbody_` → rebuilt `MMDRigidBody`
- `MMDJointObject::mmd_joint_` → rebuilt `MMDJoint`

## Inter-Manager Communication

Managers communicate via message structs:

| Message | Direction |
|---------|-----------|
| `MMDModelManagerObjectMsg` | Model → managers |
| `MMDBoneManagerObjectMsg` | Bone manager → model |
| `MMDMeshManagerObjectMsg` | Mesh manager → model |

## Source Files

| File | Role |
|------|------|
| `module/tools/object/mmd_manager.hpp` | Base manager class |
| `module/tools/object/mmd_model_manager.h/cpp` | Root model object + morph UI |
| `module/tools/object/mmd_bone_manager.h/cpp` | Bone manager |
| `module/tools/object/mmd_mesh_manager.h/cpp` | Mesh manager |
| `module/tools/object/mmd_rigid_manager.h/cpp` | Rigid body manager |
| `module/tools/object/mmd_joint_manager.h/cpp` | Joint manager |
| `module/tools/object/mmd_rigid.h/cpp` | Single rigid body |
| `module/tools/object/mmd_joint.h/cpp` | Single joint |
| `module/tools/object/mmd_camera.h/cpp` | VMD camera object |
