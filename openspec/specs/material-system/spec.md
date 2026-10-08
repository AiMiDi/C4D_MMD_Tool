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
The material system SHALL use renderer-specific adapters to create, sync, and read Standard, RedShift, Octane, and Corona materials, and SHALL additionally create and synchronize a distinct RS Toon profile. Managed Toon outputs SHALL preserve source base data instead of being reverse-read as independent base values.

#### Scenario: Create material for selected renderer
- **WHEN** a material is created from PMX data for a selected material type
- **THEN** the matching material adapter SHALL create a Cinema 4D material and preserve supported sync paths for that renderer and profile

#### Scenario: A managed Toon material is reverse-synchronized
- **WHEN** the user requests reverse synchronization from managed Toon outputs
- **THEN** the source base values SHALL remain unchanged and the UI SHALL explain that the managed outputs are driven from those values

### Requirement: Material management UI
The model manager attribute UI SHALL expose material list management and editable PMX material fields, including RS Toon creation and explicit conversion of the current material entry.

#### Scenario: User edits a material entry
- **WHEN** the user selects a material in the model manager material list
- **THEN** the UI SHALL expose controls for linking, creating, syncing, reverse-syncing, reordering, deleting, and editing PMX material properties

#### Scenario: User selects RS Toon
- **WHEN** the installed renderer supports the profile
- **THEN** the material-type selector SHALL offer RS Toon and the UI SHALL expose its conversion action and support diagnostics

### Requirement: Texture path resolution
The material importer SHALL resolve texture references relative to the PMX model directory and reuse shared texture resources when possible.

#### Scenario: Multiple materials reference one texture
- **WHEN** imported PMX materials reference the same texture path
- **THEN** the material system SHALL avoid redundant texture loading for that shared resource

### Requirement: Material runtime state reflects material morph composition
The material system SHALL maintain an effective runtime material state derived from base `MMDMaterialData` plus active material morph contributions. Material adapters SHALL synchronize C4D materials from the effective runtime state when it changes.

#### Scenario: Material morph changes diffuse and alpha
- **WHEN** a Material morph adds diffuse color and alpha offsets to material index 0
- **AND** the morph effective strength is 1.0
- **THEN** material index 0 runtime state SHALL contain the adjusted diffuse RGB and alpha values
- **AND** the linked C4D material SHALL be synchronized from that adjusted runtime state

#### Scenario: Material runtime state uses base data when no material morph is active
- **WHEN** no Material morph has a non-zero effective strength
- **THEN** every material runtime state SHALL match its stored base `MMDMaterialData`

### Requirement: Standard materials use generic ShaderData for morphable texture channels
Standard C4D materials SHALL use generic MMD ShaderData wrappers for morphable texture sampling. Wrappers SHALL retain the original child shader where the C4D hierarchy supports it and apply supported PMX texture, sphere or toon factors to its sampled output. Material morph evaluation SHALL update generic parameters or render-time snapshots instead of creating shader types per field or morph.

#### Scenario: Texture morph shader wraps original texture shader
- **WHEN** a Standard material is linked to material index 0
- **AND** the material color channel already uses a bitmap or compatible texture shader
- **THEN** the material color channel SHALL use a generic MMD material texture morph shader as the channel shader
- **AND** the original texture shader SHALL be preserved as a child shader of the generic wrapper when the shader type supports that hierarchy

#### Scenario: Texture factor applies to sampled child shader output
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 texture factor
- **THEN** the generic texture morph shader SHALL sample the wrapped child shader
- **AND** the shader SHALL apply the effective texture factor to the sampled child color

### Requirement: Simple material morph fields are precomputed before parameter synchronization
Standard material fields that can be represented as simple colors, floats, or direct material parameters SHALL be computed during material morph runtime evaluation and then synchronized to shader or material parameters. These fields SHALL NOT require per-sample ShaderData evaluation unless they are part of a texture sampling operation.

#### Scenario: Diffuse color updates as precomputed parameter
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 diffuse RGB
- **THEN** the material runtime evaluator SHALL compute the effective diffuse RGB before shader sampling
- **AND** the Standard material adapter SHALL update the material color parameter or a simple color shader parameter from the precomputed value

#### Scenario: Alpha updates as precomputed parameter
- **WHEN** a Standard material is linked to material index 0
- **AND** a Material morph changes material index 0 alpha
- **THEN** the material runtime evaluator SHALL compute the effective alpha before shader sampling
- **AND** the Standard material adapter SHALL update the material alpha parameter or a simple alpha shader parameter from the precomputed value

### Requirement: ShaderData output is read-only with respect to scene state
MMD material ShaderData implementations SHALL NOT mutate C4D scene objects, morph data, model manager data, or BaseMaterial parameters from shader output sampling. ShaderData output SHALL read only shader parameters, render-time snapshots, or other data prepared by the material runtime update path.

#### Scenario: Render sampling does not change morph state
- **WHEN** Cinema 4D samples an MMD material shader during viewport or render evaluation
- **THEN** the shader output SHALL NOT change morph strength values
- **AND** the shader output SHALL NOT write to `MMDMaterialData`, material morph definitions, or linked `BaseMaterial` parameters

### Requirement: Supported non-shader material fields are synchronized through adapters
Material morph fields that cannot be represented by Standard ShaderData channels but are currently represented by the material system SHALL be synchronized through the material adapter layer when the effective material runtime state changes. Material morph fields that are not yet used by the material system, including edge color and edge size, SHALL be preserved for UI editing, scene persistence, and PMX export but SHALL NOT be required to affect runtime material appearance in this change.

#### Scenario: Supported scalar fields update through adapter path
- **WHEN** a Material morph changes a supported scalar material field such as specular power
- **THEN** the effective runtime material state SHALL contain the adjusted supported field
- **AND** the material adapter SHALL apply the supported field through C4D material parameters without requiring a dedicated ShaderData plugin

#### Scenario: Unused edge fields are preserved but not applied
- **WHEN** a Material morph changes edge color or edge size for a material
- **THEN** the imported material morph data SHALL preserve the edge color and edge size values
- **AND** runtime material synchronization SHALL be allowed to ignore those fields until the material system has an edge rendering path

#### Scenario: Renderer-specific materials keep data integrity
- **WHEN** a linked material is Redshift, Octane, or Corona
- **THEN** the material adapter SHALL apply only supported precomputed simple color and float fields through renderer-specific parameters
- **AND** texture factor, sphere texture factor, toon texture factor, edge color, edge size, and other unsupported renderer-specific visual fields SHALL remain preserved in MMD material runtime and PMX export data
- **AND** the adapter SHALL NOT be required to create classic ShaderData wrappers or edit renderer-specific node graphs for this change

### Requirement: Standard textured materials apply complete material morph factors
The Standard material adapter SHALL apply effective diffuse and alpha values together with PMX texture factors to texture-backed channels. It SHALL preserve the original channel shader as a child of the material morph wrapper and SHALL keep pure-color `Xcolor` channels on the direct parameter update path.

#### Scenario: Textured diffuse and alpha respond to a material morph
- **WHEN** a Standard material has texture-backed color and alpha channels
- **AND** an active Material morph changes diffuse, alpha, or texture factor values
- **THEN** the color wrapper SHALL apply effective diffuse RGB multiplied by effective texture factor RGB
- **AND** the alpha wrapper SHALL apply effective diffuse alpha multiplied by effective texture factor alpha

#### Scenario: Pure-color material does not receive a texture wrapper
- **WHEN** a Standard material color or alpha channel is backed only by `Xcolor`
- **AND** a Material morph changes diffuse or alpha
- **THEN** the adapter SHALL update the `Xcolor` parameters directly
- **AND** it SHALL NOT wrap that channel merely to apply a texture factor

### Requirement: Standard sphere and toon factors are applied to their texture channels
The Standard material adapter SHALL map sphere textures to the Environment channel and toon textures to the Luminance channel. Effective sphere and toon RGB and alpha factors SHALL be applied by the material morph wrapper for their respective channels.

#### Scenario: Sphere and toon texture factors update wrapper parameters
- **WHEN** a Standard material has sphere and toon texture channels
- **AND** an active Material morph changes sphere texture factor or toon texture factor
- **THEN** the Environment wrapper SHALL receive the effective sphere RGB and alpha factors
- **AND** the Luminance wrapper SHALL receive the effective toon RGB and alpha factors

#### Scenario: Shared PMX toon texture is resolved during import
- **WHEN** a PMX material uses common toon slot 0 through 9
- **THEN** the Standard material SHALL resolve the corresponding bundled `toon01.bmp` through `toon10.bmp`
- **AND** the resolved texture SHALL be assigned to the Luminance channel

### Requirement: Standard Matcap Sphere conversion
New Standard and Redshift Standard conversions SHALL project ordinary PMX Sphere
textures using the camera-space surface normal, independently of mesh UVs and
reflected view rays. Multiply/Add SHALL compose with base color before native
surface shading. Sphere RGBA Morph factors SHALL remain independent and image
Alpha SHALL NOT change object opacity. SubTexture SHALL retain its source data
with an unsupported diagnostic instead of using ordinary UV or reflection.

#### Scenario: Sphere parameters are edited
- **WHEN** a unique owned Standard or Redshift Standard binding receives a valid Sphere path or mode edit
- **THEN** it SHALL update the managed Sphere contribution, preserve sampling and artist inputs, and survive Undo/Redo with immediate save/reopen

#### Scenario: An older material is opened
- **WHEN** a scene retains the legacy Environment approximation or seven-field RS binding
- **THEN** opening and runtime evaluation SHALL NOT silently rewrite its material recipe, and an explicit independent conversion or supported upgrade SHALL be required to obtain the new Matcap binding

#### Scenario: A Sphere edit conflicts with artist input
- **WHEN** an artist replaces the owned bitmap or connects an unowned source to an active or dormant managed input
- **THEN** the edit SHALL fail while preserving the current graph and authoritative source parameters

### Requirement: Conversion uses authoritative MMD data
Conversion to RS Toon SHALL use the selected model entry's stored base material and Morph definitions. It SHALL NOT infer equivalent PMX parameters from arbitrary renderer graphs. Conversion SHALL require EDIT mode with material preview disabled.

#### Scenario: The linked source material has artist edits
- **WHEN** the user explicitly converts its MMD material entry
- **THEN** the new material SHALL use stored MMD values, the UI SHALL identify that input source, and the original material graph SHALL remain available unchanged

### Requirement: Scoped material assignment
Successful conversion SHALL create a new material, update the selected entry's material link and its unambiguous mesh material assignments, and preserve unrelated assignments. The source material SHALL remain in the document. Missing or ambiguous target assignments SHALL reject conversion with a diagnostic.

#### Scenario: A source material is shared by two entries
- **WHEN** one entry is converted to RS Toon
- **THEN** only that entry and its resolved mesh or polygon-selection assignments SHALL use the new material while the other entry retains the source

#### Scenario: Target assignments cannot be resolved
- **WHEN** the selected entry's mesh, selection or source-material relationships are ambiguous
- **THEN** conversion SHALL report the ambiguity without creating an assigned or orphan conversion result

### Requirement: Atomic conversion and recovery
Conversion, including assignment and animation-binding preparation, SHALL form one Undo action. Failure SHALL restore previous links, assignments and binding attributes and remove only objects created by that failed operation. Undo and Redo SHALL restore usable states that can be immediately saved and reopened.

#### Scenario: Binding preparation fails
- **WHEN** material construction succeeds but required binding preparation fails
- **THEN** the original scene state SHALL be restored and conversion SHALL report failure

#### Scenario: Conversion is undone and redone
- **WHEN** the user performs Undo or Redo after a successful conversion
- **THEN** material assignment and binding ownership SHALL agree, source data and animation tracks SHALL be preserved, and immediate save/reopen SHALL succeed

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
