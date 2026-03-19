## ADDED Requirements

### Requirement: Octane Material Adapter
The system SHALL provide an `MMDOctaneMaterialAdapter` class inheriting from `MMDMaterialAdapter` to handle Octane material operations.

### Requirement: Create OC Material from PMX
The `MMDOctaneMaterialAdapter::CreateFromPMX` method SHALL create an OC material from PMX data:
- Allocate OC default material using `BaseMaterial::Alloc(ID_OCTANE_DIFFUSE_MATERIAL)`.
- If texture exists: Allocate `ID_OCTANE_IMAGE_TEXTURE`, set path, and connect to `OCT_MATERIAL_DIFFUSE_LINK`; detect alpha and connect to `OCT_MATERIAL_OPACITY_LINK`.
- If no texture: Allocate `ID_OCTANE_RGBSPECTRUM` for diffuse color; allocate `ID_OCTANE_FLOAT_TEXTURE` for opacity.
- Enable `OCT_MAT_USE_COLOR` and `OCT_MAT_USE_OPACITY`.
- If Octane is not installed: Return `nullptr` and show a MessageDialog warning.

#### Scenario: Texture with Alpha Channel
- **WHEN** PMX material references a PNG texture with an alpha channel
- **THEN** The created OC material uses an ImageTexture shader for the diffuse channel and opacity channel.

### Requirement: Create OC Material from MMDMaterialData
The `MMDOctaneMaterialAdapter::CreateFromData` method SHALL create an OC material from `MMDMaterialData` (solid color mode).

### Requirement: OC Material Sync To
The `MMDOctaneMaterialAdapter::SyncTo` method SHALL sync `diffuse_rgb`, `diffuse_alpha`, and `name_local` to the linked OC material.

### Requirement: OC Material Read From
The `MMDOctaneMaterialAdapter::ReadFrom` method SHALL read `diffuse_rgb` and `diffuse_alpha` from the OC material back into the `MMDMaterialData`.