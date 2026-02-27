## ADDED Requirements

### Requirement: UVMorph type enum value
The `MMDMorphType` enum SHALL include a `UV` value (`1 << 4`) to identify UV-based morphs.

#### Scenario: UV morph type identification
- **WHEN** a morph is created with `MMDMorphType::UV`
- **THEN** `GetType()` SHALL return `MMDMorphType::UV`

### Requirement: UVMorph class
The plugin SHALL provide a `UVMorph` class inheriting from `IMorph` that represents UV morphs. It SHALL implement `AddMorphUI`, `DeleteMorphUI`, `UpdateMorph`, and `GetType`.

#### Scenario: UVMorph construction
- **WHEN** a `UVMorph` is constructed with a name and strength DescID
- **THEN** it SHALL store the name and strength descriptor, and `GetType()` SHALL return `MMDMorphType::UV`

#### Scenario: UVMorph updates mesh manager strength
- **WHEN** `UpdateMorph` is called on a `UVMorph`
- **THEN** it SHALL call `MMDMeshManagerObject::SetMorphStrength` with the morph name and current strength value

### Requirement: UV morph UI group
The attribute manager SHALL display UV morphs in a dedicated `MODEL_MORPH_UV_GRP` group, separate from position (mesh) morphs.

#### Scenario: UV morph slider placement
- **WHEN** `AddMorphUI` is called on a `UVMorph`
- **THEN** the strength slider SHALL be added under `MODEL_MORPH_UV_GRP` (not `MODEL_MORPH_MESH_GRP`)

#### Scenario: UV morph group visible in attribute manager
- **WHEN** a model with UV morphs is selected
- **THEN** the attribute manager SHALL show a "UV" morph group between "Mesh" and "Bone" groups

### Requirement: UV morph creation in AddMorph
`MMDModelManagerObject::AddMorph()` SHALL create a `UVMorph` instance when called with `MMDMorphType::UV`.

#### Scenario: AddMorph with UV type
- **WHEN** `AddMorph(MMDMorphType::UV, "test_uv")` is called
- **THEN** a `UVMorph` with name "test_uv" SHALL be stored in the morph map

### Requirement: UV morph names tracked in mesh manager
`MMDMeshManagerObject` SHALL maintain a set of morph names that are UV morphs. During PMX import, morph names originating from `PMXMorphType::UV`, `AddUV1`, `AddUV2`, `AddUV3`, or `AddUV4` SHALL be added to this set.

#### Scenario: PMX import marks UV morph names
- **WHEN** a PMX file with UV morphs is imported
- **THEN** the UV morph names SHALL be stored in the mesh manager's UV name set

#### Scenario: UV morph names exposed to model manager
- **WHEN** `RefreshMorph` queries the mesh manager for morph data
- **THEN** it SHALL be able to distinguish UV morph names from position morph names

### Requirement: UV morph name set serialization
The UV morph name set SHALL be serialized in `MMDMeshManagerObject::Write()` and deserialized in `Read()`. Old scene files without this data SHALL load successfully with all morphs treated as mesh morphs.

#### Scenario: Save and reload scene with UV morphs
- **WHEN** a scene with UV morphs is saved and reloaded
- **THEN** UV morphs SHALL retain their UV type classification

#### Scenario: Load old scene without UV morph data
- **WHEN** a scene saved before UV morph support is loaded
- **THEN** all morphs SHALL be treated as mesh morphs (backward compatibility)
