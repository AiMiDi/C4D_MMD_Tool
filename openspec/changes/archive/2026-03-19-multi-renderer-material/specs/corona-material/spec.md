## ADDED Requirements

### Requirement: Corona Material Adapter
The system SHALL provide an `MMDCoronaMaterialAdapter` class inheriting from `MMDMaterialAdapter` to handle Corona material operations.

### Requirement: Create Corona Material from PMX
The `MMDCoronaMaterialAdapter::CreateFromPMX` method SHALL create a Corona material from PMX data:
- Allocate Corona default material using `BaseMaterial::Alloc(ID_CORONA_MATERIAL)`.
- If texture exists: Allocate `ID_CORONA_BITMAP`, set path, connect to `CORONA_DIFFUSE_TEXTURE`; detect alpha, enable `CORONA_MATERIAL_ALPHA`, connect to `CORONA_ALPHA_TEXTURE`.
- If no texture: Set `CORONA_DIFFUSE_COLOR` to diffuse color; set `CORONA_ALPHA_COLOR` and `CORONA_ALPHA_COLOR_LEVEL` for alpha.
- Enable `CORONA_MATERIAL_DIFFUSE`.
- If Corona is not installed: Return `nullptr` and show a MessageDialog warning.

### Requirement: Create Corona Material from MMDMaterialData
The `MMDCoronaMaterialAdapter::CreateFromData` method SHALL create a Corona material from `MMDMaterialData` (solid color mode).

### Requirement: Corona Material Sync To
The `MMDCoronaMaterialAdapter::SyncTo` method SHALL sync `diffuse_rgb`, `diffuse_alpha`, and `name_local` to the linked Corona material.

### Requirement: Corona Material Read From
The `MMDCoronaMaterialAdapter::ReadFrom` method SHALL read `diffuse_rgb` and `diffuse_alpha` from the Corona material back into the `MMDMaterialData`.