## ADDED Requirements

### Requirement: RedShift Material Adapter
The system SHALL provide an `MMDRedShiftMaterialAdapter` class inheriting from `MMDMaterialAdapter` to handle RedShift material operations.

### Requirement: Create RS Material from PMX
The `MMDRedShiftMaterialAdapter::CreateFromPMX` method SHALL create an RS material from PMX data:
- Allocate RS default material using `BaseMaterial::Alloc(ID_REDSHIFT_MATERIAL)`.
- If texture exists: Configure base_color port using NodeMaterial Graph API; detect PNG/TGA alpha channel and set opacity_color.
- If no texture: Set base_color to PMX diffuse RGB; set opacity_color to diffuse alpha grayscale.
- If RedShift is not installed: Return `nullptr` and show a MessageDialog warning.

#### Scenario: Texture with Alpha Channel
- **WHEN** PMX material references a PNG texture with an alpha channel
- **THEN** The created RS material uses the texture for base_color and its alpha for opacity_color.

### Requirement: Create RS Material from MMDMaterialData
The `MMDRedShiftMaterialAdapter::CreateFromData` method SHALL create an RS material from `MMDMaterialData` (solid color mode without texture).

#### Scenario: Created via UI Button
- **WHEN** User clicks the "Create Material" button and RedShift is selected
- **THEN** A new RS material is created with base_color set to diffuse color and opacity set to alpha.

### Requirement: RS Material Sync To
The `MMDRedShiftMaterialAdapter::SyncTo` method SHALL sync `diffuse_rgb`, `diffuse_alpha`, and `name_local` to the linked RS material.

### Requirement: RS Material Read From
The `MMDRedShiftMaterialAdapter::ReadFrom` method SHALL read `diffuse_rgb` and `diffuse_alpha` from the RS material back into the `MMDMaterialData`.

### Requirement: Dispatch for RS Materials
The unified `DetectType` and factory methods SHALL correctly dispatch calls to the RedShift adapter.

#### Scenario: PMX Import Selection
- **WHEN** RedShift is selected during PMX import
- **THEN** The system creates RS materials using the adapter factory.