## MODIFIED Requirements

### Requirement: Morph Types
MMD models support morph targets (expressions/deformations) that modify vertices, bones, UVs, or other morphs. The plugin implements five morph types matching the PMX specification.

| Type | Class | Description |
|------|-------|-------------|
| Group | `GroupMorph` | Combines multiple other morphs with individual weights |
| Flip | `FlipMorph` | Toggles between two morph states |
| Mesh (Vertex) | `MeshMorph` | Vertex position offsets applied to polygon objects |
| UV | `UVMorph` | UV coordinate offsets (UV/AddUV1–4) applied to polygon objects |
| Bone | `BoneMorph` | Bone transform offsets (position + rotation) |

#### Scenario: All five morph types available
- **WHEN** a PMX model with group, flip, mesh, UV, and bone morphs is imported
- **THEN** each morph type SHALL be represented by its corresponding class (`GroupMorph`, `FlipMorph`, `MeshMorph`, `UVMorph`, `BoneMorph`)

### Requirement: Class Hierarchy
All morph types implement the `IMorph` interface defined in `mmd_morph.h`.

```
IMorph (interface)
├── GroupMorph — references other morphs by index + weight
├── FlipMorph — binary flip between morph states
├── MeshMorph — per-vertex position delta
├── UVMorph — per-face UV coordinate delta
└── BoneMorph — per-bone transform delta
```

#### Scenario: UVMorph inherits IMorph
- **WHEN** a `UVMorph` instance exists
- **THEN** it SHALL be usable through the `IMorph` interface

### Requirement: Morph UI
The morph UI in the attribute manager SHALL display morph groups in this order: Group, Flip, Mesh, UV, Bone.

#### Scenario: UV morph group placement
- **WHEN** the attribute manager displays morph groups
- **THEN** the UV morph group SHALL appear after the Mesh group and before the Bone group

### Requirement: Morph Storage
- Morphs are owned by `MMDModelManagerObject`
- Group and Flip morphs are loaded during `MMDModelManagerObject::LoadPMX()`
- Mesh and UV morphs are handled by `MMDMeshManagerObject`
- Bone morphs are handled through the bone system

#### Scenario: UV morphs stored alongside mesh morphs
- **WHEN** UV morphs are imported from PMX
- **THEN** they SHALL be stored in the mesh manager's morph data structures and distinguished by the UV morph name set
