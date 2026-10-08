## ADDED Requirements

### Requirement: Morph Types
The plugin SHALL support the following morph types corresponding to the PMX specification, alongside its existing Material and Impulse morph support:
- **Group** (`GroupMorph`): Combines multiple other morphs by weight.
- **Flip** (`FlipMorph`): Toggles between two morph states.
- **Mesh** (`MeshMorph`): Per-vertex position offsets for polygon objects.
- **UV** (`UVMorph`): Per-face UV coordinate offsets.
- **Bone** (`BoneMorph`): Bone transformation offsets.

#### Scenario: Distinguishing position and UV types
- **WHEN** a model contains both position and UV-based morphs
- **THEN** inspection reports the position morph as Mesh and all UV-based morphs as UV.

### Requirement: Class Hierarchy
All morph types SHALL implement the `IMorph` interface defined in `mmd_morph.h`.

#### Scenario: UV leaf implementation
- **WHEN** a UV morph is created through the common morph interface
- **THEN** `UVMorph` provides the common name, strength, update and UI operations through `IMorph`.

### Requirement: Morph UI Ordering
The Attribute Manager SHALL display morph groups in the following order: Group, Flip, Mesh, UV, Bone.

#### Scenario: UV group placement
- **WHEN** the model Attribute Manager description is built
- **THEN** the UV group is placed after Mesh and before Bone, while existing Material and Impulse groups are retained.

### Requirement: Morph Storage
- Morphs SHALL be owned by `MMDModelManagerObject`.
- Group and Flip morphs are loaded during `MMDModelManagerObject::LoadPMX()`.
- Mesh and UV morphs are processed by `MMDMeshManagerObject`.
- Bone morphs are handled via the bone system.
- Morph strengths in the UI are synced from the actual `CAPoseMorphTag` values during updates to ensure consistency after operations like Undo.

#### Scenario: Coexistence of UV and Mesh Morphs
- **WHEN** UV morphs are imported from a PMX
- **THEN** They are stored alongside Mesh morphs in the mesh manager's morph data structures, distinguished by the UV morph names set.