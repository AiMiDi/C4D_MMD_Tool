# Morph System

## Overview

MMD models support morph targets (expressions/deformations) that modify vertices, bones, UVs, materials, or other morphs. The plugin implements seven morph types matching the PMX specification.

## Morph Types

| Type | Class | Description |
|------|-------|-------------|
| Group | `GroupMorph` | Combines multiple other morphs with individual weights |
| Flip | `FlipMorph` | Toggles between two morph states |
| Mesh (Vertex) | `MeshMorph` | Vertex position offsets applied to polygon objects |
| Bone | `BoneMorph` | Bone transform offsets (position + rotation) |
| UV | `UVMorph` | UV coordinate offsets |
| Material | `MaterialMorph` | Material property changes |
| Impulse | `ImpulseMorph` | Rigid-body impulse / physics-related morphs |

## Class Hierarchy

```
IMorph (interface, m_panel for panel classification)
├── GroupMorph   — references other morphs by index + weight
├── FlipMorph   — binary flip between morph states
├── MeshMorph   — per-vertex position delta
├── BoneMorph   — per-bone transform delta
├── UVMorph     — UV coordinate delta (from mesh manager)
├── MaterialMorph — material property delta
└── ImpulseMorph  — rigid-body impulse delta
```

All morph types implement `IMorph` interface defined in `mmd_morph.h`.

`MMDMorphType` enum uses bitmask values: `DEFAULT=0`, `GROUP=1`, `FLIP=2`, `MESH=4`, `BONE=8`, `UV=16`, `MATERIAL=32`, `IMPULSE=64`.

## Panel Classification

Each morph carries a panel value (`IMorph::m_panel`) corresponding to PMX `m_controlPanel`:

| Value | Panel |
|-------|-------|
| 1 | 眉 (Eyebrow) |
| 2 | 目 (Eye) |
| 3 | 口 (Mouth) |
| 4 | 其他 (Other) |

Panel is displayed as a CYCLE parameter per morph in the attribute manager.

## Morph Storage

- Morphs are owned by `MMDModelManagerObject`
- Group, Flip, Material, and Impulse morphs are loaded during `MMDModelManagerObject::LoadPMX()`
- Mesh morphs are handled by `MMDMeshManagerObject`
- UV morphs are created in `SyncMorphsFromMesh()` using `MMDMeshManagerObject::GetUVMorphNames()` to distinguish UV morphs from position morphs
- Bone morphs are handled through the bone system

## Morph UI

- `EditorSubMorphDialog` — embedded in `mmd_model_manager.cpp`
- `AddMorphHelper` — helper for adding morphs via UI
- `MorphUIData` (in `utils/morph_ui_data_util.hpp`) — serialization of morph tag/DescID data for the attribute manager
- Morph groups in attribute manager: `MODEL_MORPH_MESH_GRP`, `MODEL_MORPH_UV_GRP`, `MODEL_MORPH_BONE_GRP`, `MODEL_MORPH_MATERIAL_GRP`, `MODEL_MORPH_IMPULSE_GRP`
- Morph UI ordering in the Attribute Manager: Group, Flip, Mesh, UV, Bone.
- Material and Impulse groups have dedicated add-name input and add button

## VMD Morph Animation

VMD files contain morph keyframes that animate morph weights over time. These are applied through the VMD motion import pipeline (see vmd-motion spec).

## Source Files

| File | Role |
|------|------|
| `module/tools/object/mmd_morph.h/cpp` | IMorph interface + all morph type implementations |
| `module/tools/object/mmd_model_manager.cpp` | Morph storage, Group/Flip/Material/Impulse loading, EditorSubMorphDialog |
| `module/tools/object/mmd_mesh_manager.cpp` | Mesh morph application, UV morph name tracking |
| `utils/morph_ui_data_util.hpp` | Morph UI data serialization |
