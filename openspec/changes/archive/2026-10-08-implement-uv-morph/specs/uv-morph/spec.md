## ADDED Requirements

### Requirement: UVMorph Type Enum
The `MMDMorphType` enum SHALL include a `UV` value (`1 << 4`) to identify UV-based morphs.

#### Scenario: UV type identity
- **WHEN** an imported UV-based morph is inspected through the model type system
- **THEN** its type is `MMDMorphType::UV` with value 16, distinct from Mesh type 4.

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

#### Scenario: Separate UV sliders
- **WHEN** a PMX contains UV-based and position morphs
- **THEN** UV sliders belong to `MODEL_MORPH_UV_GRP` and position sliders remain under `MODEL_MORPH_MESH_GRP`.

### Requirement: UV Morph Creation in AddMorph
`MMDModelManagerObject::AddMorph()` SHALL instantiate a `UVMorph` when called with `MMDMorphType::UV`.

#### Scenario: Creating a UV morph
- **WHEN** `AddMorph()` receives `MMDMorphType::UV` and a morph name
- **THEN** it creates a `UVMorph` with a slider in the UV group.

### Requirement: Tracking UV Morph Names in Mesh Manager
`MMDMeshManagerObject` SHALL maintain a set of morph names belonging to UV morphs (`uv_morph_names_`). During PMX import, names from `PMXMorphType::UV`, `AddUV1`, `AddUV2`, `AddUV3`, or `AddUV4` SHALL be added to this set.

#### Scenario: Both mesh import strategies
- **WHEN** a PMX containing UV and AddUV1 through AddUV4 morphs is imported as a single mesh or multiple parts
- **THEN** every imported UV-based name is tracked and refresh classifies it as UV instead of Mesh.

### Requirement: UV Morph Names Serialization
The UV morph name set SHALL be serialized in `MMDMeshManagerObject::Write()` and deserialized in `Read()`. Older scenes without this data SHALL load correctly, treating all morphs as Mesh morphs.
#### Scenario: Scene save and reload
- **WHEN** a scene containing imported UV-based and position morphs is saved and loaded from disk without PMX re-import
- **THEN** the UV names and classification persist, position morphs remain Mesh, and the corresponding sliders retain their strengths.

#### Scenario: Older scene without UV name data
- **WHEN** an older scene has no serialized UV morph name set
- **THEN** loading succeeds with an empty UV name set and existing entries are treated as Mesh morphs.
