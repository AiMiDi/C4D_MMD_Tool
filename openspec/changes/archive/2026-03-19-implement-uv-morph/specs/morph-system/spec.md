## MODIFIED Requirements

### Requirement: Morph Types
The plugin implements five morph types corresponding to the PMX specification:
- **Group** (`GroupMorph`): Combines multiple other morphs by weight.
- **Flip** (`FlipMorph`): Toggles between two morph states.
- **Mesh** (`MeshMorph`): Per-vertex position offsets for polygon objects.
- **UV** (`UVMorph`): Per-face UV coordinate offsets.
- **Bone** (`BoneMorph`): Bone transformation offsets.

### Requirement: Class Hierarchy
All morph types implement the `IMorph` interface defined in `mmd_morph.h`.

### Requirement: Morph UI Ordering
The Attribute Manager SHALL display morph groups in the following order: Group, Flip, Mesh, UV, Bone.

### Requirement: Morph Storage
- Morphs are owned by `MMDModelManagerObject`.
- Group and Flip morphs are loaded during `MMDModelManagerObject::LoadPMX()`.
- Mesh and UV morphs are processed by `MMDMeshManagerObject`.
- Bone morphs are handled via the bone system.
- Morph strengths in the UI are synced from the actual `CAPoseMorphTag` values during updates to ensure consistency after operations like Undo.

#### Scenario: Coexistence of UV and Mesh Morphs
- **WHEN** UV morphs are imported from a PMX
- **THEN** They are stored alongside Mesh morphs in the mesh manager's morph data structures, distinguished by the UV morph names set.