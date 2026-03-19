## ADDED Requirements

### Requirement: MMD Material Data Structure
The system SHALL define the `MMDMaterialData` struct containing complete PMX material properties (diffuse, specular, ambient, draw flags, edge settings, texture indices, memo, etc.).

### Requirement: MMDMaterialData Mesh Tracking
The `MMDMaterialData` struct SHALL include tracking for its associated mesh and polygon selection:
- `mesh_link`: BaseLink pointing to the associated `PolygonObject`.
- `selection_name`: String containing the name of the associated polygon selection tag (if any).

### Requirement: Material List Storage
`MMDModelManagerObject` SHALL maintain a `maxon::BaseArray<MMDMaterialData>` containing all materials.

### Requirement: Material Data Serialization
The material data SHALL support serialization (`Read`/`Write`/`CopyTo`) for C4D project files, including proper serialization of the `BaseLink` for the `material_link` and `mesh_link`.

#### Scenario: Save and Reload Project
- **WHEN** A project with MMD material data is saved and reloaded
- **THEN** All material properties and links (material and mesh) are fully restored.

### Requirement: Material to C4D Material Link
Each `MMDMaterialData` SHALL associate with a `BaseMaterial` via `material_link`. If the C4D material is deleted, the link becomes null.