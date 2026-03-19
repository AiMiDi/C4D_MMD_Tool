## ADDED Requirements

### Requirement: Sync Diffuse Color to C4D Material
When the user modifies the diffuse color of an MMD material, the system SHALL automatically sync the changes to the linked C4D `BaseMaterial`.

#### Scenario: Modify Diffuse RGB
- **WHEN** The user modifies the RGB values of `MODEL_MATERIAL_DIFFUSE_COLOR`
- **THEN** The color channel of the linked C4D material SHALL be updated.

#### Scenario: Modify Diffuse Alpha
- **WHEN** The user modifies `MODEL_MATERIAL_DIFFUSE_ALPHA`
- **THEN** The alpha/opacity channel of the linked C4D material SHALL be updated.

#### Scenario: No Linked Material
- **WHEN** `material_link` is null or points to a non-existent material
- **THEN** The modification is saved to `MMDMaterialData` without triggering sync operations or errors.

### Requirement: Sync Specular Color to C4D Material
When the user modifies the specular color and power, the system SHALL automatically sync them to the linked C4D material.

### Requirement: Populate Material Data on PMX Import
The PMX import process SHALL populate the `MMDModelManagerObject` material list while creating C4D materials.

#### Scenario: Import PMX with Materials
- **WHEN** Importing a PMX file with N materials
- **THEN** The material list contains N `MMDMaterialData` entries, each linked to the created C4D `BaseMaterial`, with all PMX properties mapped.

#### Scenario: Import without Materials
- **WHEN** `import_material` is false in the import settings
- **THEN** The material list is still populated with MMD material data, but `material_link` is empty.

### Requirement: Read Material Data on PMX Export
The PMX export process SHALL read complete MMD material parameters from the `MMDModelManagerObject` material list.

### Requirement: Sync Material Name
Modifications to the local MMD material name SHALL sync to the linked C4D material.

### Requirement: Full Sync via Sync Button
Clicking the Sync button SHALL trigger a full synchronization of all properties to the linked C4D material using the appropriate Material Adapter.

### Requirement: Reverse Sync via Reverse Sync Button
Clicking the Reverse Sync button SHALL read supported properties (e.g. diffuse color, alpha) from the linked C4D material back into the `MMDMaterialData` using the appropriate Material Adapter.

### Requirement: Dynamic Dispatch via Adapter Pattern
All sync operations (both ways) SHALL utilize the `MMDMaterialAdapter` pattern to detect the material type dynamically and delegate reading/writing to the specific renderer's adapter implementation.