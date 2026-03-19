## ADDED Requirements

### Requirement: UVMorph Type Enum
The `MMDMorphType` enum SHALL include a `UV` value (`1 << 4`) to identify UV-based morphs.

### Requirement: UVMorph Class
The plugin SHALL provide a `UVMorph` class inheriting from `IMorph`. It SHALL implement `AddMorphUI`, `DeleteMorphUI`, `UpdateMorph`, and `GetType`.

#### Scenario: UVMorph Constructor
- **WHEN** A `UVMorph` is constructed with a name and strength DescID
- **THEN** It stores them and `GetType()` returns `MMDMorphType::UV`.

#### Scenario: UVMorph Updating Mesh Manager Strength
- **WHEN** `UpdateMorph` is called on a `UVMorph`
- **THEN** It calls `MMDMeshManagerObject::SetMorphStrength` with its name and current strength.

### Requirement: UV Morph UI Group
The Attribute Manager SHALL display UV morphs in a separate `MODEL_MORPH_UV_GRP` group, distinct from position (Mesh) morphs.

### Requirement: UV Morph Creation in AddMorph
`MMDModelManagerObject::AddMorph()` SHALL instantiate a `UVMorph` when called with `MMDMorphType::UV`.

### Requirement: Tracking UV Morph Names in Mesh Manager
`MMDMeshManagerObject` SHALL maintain a set of morph names belonging to UV morphs (`uv_morph_names_`). During PMX import, names from `PMXMorphType::UV`, `AddUV1`, `AddUV2`, `AddUV3`, or `AddUV4` SHALL be added to this set.

### Requirement: UV Morph Names Serialization
The UV morph name set SHALL be serialized in `MMDMeshManagerObject::Write()` and deserialized in `Read()`. Older scenes without this data SHALL load correctly, treating all morphs as Mesh morphs.