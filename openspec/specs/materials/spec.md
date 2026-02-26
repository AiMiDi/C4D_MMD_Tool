# Materials

## Overview

Creates Cinema 4D materials from PMX material definitions during model import. Currently only Standard materials are fully implemented.

## Material Manager (`MMDMaterialManager`)

Defined in `module/tools/mmd_material.h/cpp`.

### Key Methods

| Method | Description |
|--------|-------------|
| `LoadPMXTextures()` | Loads texture bitmaps from the model directory |
| `LoadPMXMaterial()` | Creates C4D materials from PMX material data |

## PMX Material Properties

| PMX Field | C4D Mapping |
|-----------|-------------|
| Diffuse color | Material color channel |
| Specular color | Specular channel |
| Specular power | Specular width |
| Ambient color | Luminance or environment |
| Texture index | Color channel bitmap shader |
| Sphere texture | Additional layer |
| Toon texture | — |
| Edge color/size | — |
| Alpha | Transparency channel |
| Double-sided | Material backface culling off |

## Material Types

| Type | Status | Notes |
|------|--------|-------|
| Standard | Implemented | Native C4D material |
| RedShift | Placeholder | Stub only, not functional |
| Octane | Placeholder | Stub only, not functional |

Selected via `ModelImport::material_type` enum.

## Texture Loading

- Textures are loaded from the PMX model directory
- Paths are resolved relative to the model file location
- Shared textures (referenced by multiple materials) are loaded once

## Source Files

| File | Role |
|------|------|
| `module/tools/mmd_material.h/cpp` | Material creation and texture loading |
| `module/tools/object/mmd_mesh_manager.cpp` | Calls material manager during import |
