# Morph System

## Overview

MMD models support morph targets (expressions/deformations) that modify vertices, bones, or other morphs. The plugin implements four morph types matching the PMX specification.

## Morph Types

| Type | Class | Description |
|------|-------|-------------|
| Group | `GroupMorph` | Combines multiple other morphs with individual weights |
| Flip | `FlipMorph` | Toggles between two morph states |
| Mesh (Vertex) | `MeshMorph` | Vertex position offsets applied to polygon objects |
| Bone | `BoneMorph` | Bone transform offsets (position + rotation) |

## Class Hierarchy

```
IMorph (interface)
├── GroupMorph — references other morphs by index + weight
├── FlipMorph — binary flip between morph states
├── MeshMorph — per-vertex position delta
└── BoneMorph — per-bone transform delta
```

All morph types implement `IMorph` interface defined in `mmd_morph.h`.

## Morph Storage

- Morphs are owned by `MMDModelManagerObject`
- Group and Flip morphs are loaded during `MMDModelManagerObject::LoadPMX()`
- Mesh morphs are handled by `MMDMeshManagerObject`
- Bone morphs are handled through the bone system

## Morph UI

- `EditorSubMorphDialog` — embedded in `mmd_model_manager.cpp`
- `AddMorphHelper` — helper for adding morphs via UI
- `MorphUIData` (in `utils/morph_ui_data_util.hpp`) — serialization of morph tag/DescID data for the attribute manager

## VMD Morph Animation

VMD files contain morph keyframes that animate morph weights over time. These are applied through the VMD motion import pipeline (see vmd-motion spec).

## Source Files

| File | Role |
|------|------|
| `module/tools/object/mmd_morph.h/cpp` | IMorph interface + morph type implementations |
| `module/tools/object/mmd_model_manager.cpp` | Morph storage, Group/Flip loading, EditorSubMorphDialog |
| `module/tools/object/mmd_mesh_manager.cpp` | Mesh morph application |
| `utils/morph_ui_data_util.hpp` | Morph UI data serialization |
