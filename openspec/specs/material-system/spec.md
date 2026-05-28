# Materials

## Purpose

Creates and manages Cinema 4D materials from PMX material definitions. Supports Standard, RedShift, Octane, and Corona renderers. Material data is stored on `MMDModelManagerObject` as `MMDMaterialData` structs with bidirectional sync to C4D materials.

## Requirements

### Requirement: PMX material data storage
The system SHALL store PMX material fields and related Cinema 4D links in `MMDMaterialData` entries owned by `MMDModelManagerObject`.

#### Scenario: PMX material is imported
- **WHEN** a PMX material is read during model import
- **THEN** its names, colors, draw flags, edge settings, texture paths, memo, face count, and C4D links SHALL be represented in `MMDMaterialData`

### Requirement: Renderer-specific material adapters
The material system SHALL use renderer-specific adapters to create, sync, and read Standard, RedShift, Octane, and Corona materials.

#### Scenario: Create material for selected renderer
- **WHEN** a material is created from PMX data for a selected material type
- **THEN** the matching material adapter SHALL create a Cinema 4D material and preserve sync paths for that renderer

### Requirement: Material management UI
The model manager attribute UI SHALL expose material list management and editable PMX material fields.

#### Scenario: User edits a material entry
- **WHEN** the user selects a material in the model manager material list
- **THEN** the UI SHALL expose controls for linking, creating, syncing, reverse-syncing, reordering, deleting, and editing PMX material properties

### Requirement: Texture path resolution
The material importer SHALL resolve texture references relative to the PMX model directory and reuse shared texture resources when possible.

#### Scenario: Multiple materials reference one texture
- **WHEN** imported PMX materials reference the same texture path
- **THEN** the material system SHALL avoid redundant texture loading for that shared resource

## MMDMaterialData

Defined in `module/tools/material/mmd_material.h`. Stores all PMX material fields plus C4D links.

### Fields

| Category | Fields |
|----------|--------|
| Names | `name_local`, `name_universal` |
| Colors | `diffuse_rgb`, `diffuse_alpha`, `specular`, `specular_power`, `ambient` |
| Draw flags | `draw_both_face`, `draw_ground_shadow`, `draw_self_shadow_map`, `draw_self_shadow`, `draw_edge` |
| Edge | `edge_enabled`, `edge_color_rgb`, `edge_color_alpha`, `edge_size` |
| Textures | `texture_path`, `sphere_texture_path`, `sphere_mode`, `toon_mode`, `toon_texture_index`, `toon_texture_path` |
| Other | `memo`, `num_face_vertices` |
| C4D links | `material_link` (BaseMaterial), `mesh_link` (mesh object), `selection_name` |

### Methods

| Method | Description |
|--------|-------------|
| `FromPMX()` | Maps PMX material fields to struct |
| `ToPMX()` | Writes struct fields back to PMX material |
| `Read()` / `Write()` | HyperFile serialization |
| `CopyTo()` | Deep copy |

## Material Storage

Materials are stored on `MMDModelManagerObject`:
- `maxon::BaseArray<MMDMaterialData> material_list_` — all material data
- `Int32 material_selection_index_` — currently selected index
- `BaseContainer material_list_items_` — CYCLE items for UI

## Material Manager (`MMDMaterialManager`)

Defined in `module/tools/material/mmd_material.h/cpp`. Used during PMX import.

| Method | Description |
|--------|-------------|
| `LoadPMXTextures()` | Loads texture bitmaps from the model directory |
| `LoadPMXMaterial()` | Creates C4D materials from PMX material data during import |

## Material Types

| Type | Status | Source File |
|------|--------|-------------|
| Standard | Implemented | `module/tools/material/mmd_standard_material.h/cpp` |
| RedShift | Implemented | `module/tools/material/mmd_redshift_material.h/cpp` |
| Octane | Implemented | `module/tools/material/mmd_octane_material.h/cpp` |
| Corona | Implemented | `module/tools/material/mmd_corona_material.h/cpp` |

Selected via `ModelImport::import_material_type` enum (Standard/RedShift/Octane/Corona).

### Material Adapter System

Material operations use the `MMDMaterialAdapter` pattern to detect the material type dynamically and delegate reading/writing to the specific renderer's adapter implementation.

| Adapter Method | Description |
|----------------|-------------|
| `CreateFromPMX()` | Creates C4D material from PMX data + textures (import time) |
| `CreateFromData()` | Creates C4D material from `MMDMaterialData` (UI create button) |
| `SyncTo()` | Pushes MMD data → C4D material |
| `ReadFrom()` | Pulls C4D material → MMD data |

## PMX Material Properties

| PMX Field | C4D Mapping (Standard) |
|-----------|-------------|
| Diffuse color | Material color channel |
| Specular color | Specular channel |
| Specular power | Specular width |
| Ambient color | Luminance or environment |
| Texture index | Color channel bitmap shader |
| Sphere texture | Additional layer |
| Toon texture | Toon mode (shared index → built-in toon bitmap path) |
| Edge color/size | Stored in `MMDMaterialData` |
| Alpha | Transparency channel |
| Double-sided | Material backface culling off |

## Material Management UI

The attribute manager exposes material editing in `MODEL_MATERIAL_GRP`:

| Control | Description |
|---------|-------------|
| Material list CYCLE | Select material by "index: name" |
| ↑ / ↓ buttons | Reorder materials |
| × button | Delete material entry (and related mesh/selection) |
| + button | Add material to mesh (reverse syncs if mesh has material, creates new C4D material otherwise) |
| Material link | Link to C4D BaseMaterial |
| Mesh link | Link to associated mesh object |
| Selection name | Polygon selection tag name |
| Create button | Create C4D material from current MMDMaterialData (type selectable and remembers last import choice) |
| Sync button | Push MMD data → C4D material |
| Reverse sync button | Pull C4D material → MMD data |
| All PMX fields | Editable in attribute manager (colors, flags, edge, textures, etc.) |

### Toon Mode Control

- Shared toon (`toon_mode == 1`): CYCLE dropdown selects toon01–toon10; path auto-generated from plugin resources
- Individual toon (`toon_mode == 0`): Free path input enabled; CYCLE disabled

## Texture Loading

- Textures are loaded from the PMX model directory
- Paths are resolved relative to the model file location
- Shared textures (referenced by multiple materials) are loaded once

## Source Files

| File | Role |
|------|------|
| `module/tools/material/mmd_material.h/cpp` | `MMDMaterialData`, `MMDMaterialManager`, texture loading |
| `module/tools/material/mmd_standard_material.h/cpp` | Standard material create/sync/read |
| `module/tools/material/mmd_redshift_material.h/cpp` | RedShift material create/sync/read |
| `module/tools/material/mmd_octane_material.h/cpp` | Octane material create/sync/read |
| `module/tools/material/mmd_corona_material.h/cpp` | Corona material create/sync/read |
| `module/tools/object/mmd_model_manager.cpp` | Material list storage, UI, sync logic |
| `module/tools/object/mmd_mesh_manager.cpp` | Calls material manager during import |
