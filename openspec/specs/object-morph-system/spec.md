# Morph System

## Purpose

Specify how MMD morph targets (PMX morph types) are represented, stored, evaluated in the plugin, and surfaced in the Cinema 4D UI.
## Requirements
### Requirement: Group morph propagation to sub-morphs

GroupMorph SHALL propagate its strength to sub-morphs using additive semantics. When `UpdateMorph` is called, each sub-morph's strength SHALL be incremented by `group_strength * sub_morph_weight`, rather than being overwritten.

#### Scenario: Group morph adds to sub-morph strength
- **WHEN** a GroupMorph has strength 0.8 and references sub-morph A with weight 0.5
- **AND** sub-morph A already has strength 0.3 (from its own CTrack or manual setting)
- **THEN** after `GroupMorph::UpdateMorph`, sub-morph A's strength becomes 0.3 + (0.8 * 0.5) = 0.7

#### Scenario: Group morph with zero strength does not affect sub-morphs
- **WHEN** a GroupMorph has strength 0.0
- **THEN** sub-morph strengths remain unchanged after `GroupMorph::UpdateMorph`

### Requirement: Flip morph propagation to sub-morphs

FlipMorph SHALL propagate its activation to sub-morphs using additive semantics. When `UpdateMorph` is called and the flip morph's strength is >= 0.5, each sub-morph's strength SHALL be incremented by the sub-morph's defined weight. When strength < 0.5, sub-morphs SHALL not be modified.

#### Scenario: Flip morph activated adds to sub-morph strength
- **WHEN** a FlipMorph has strength 0.7 (>= 0.5) and references sub-morph B with weight 1.0
- **AND** sub-morph B already has strength 0.2
- **THEN** after `FlipMorph::UpdateMorph`, sub-morph B's strength becomes 0.2 + 1.0 = 1.2

#### Scenario: Flip morph not activated leaves sub-morphs unchanged
- **WHEN** a FlipMorph has strength 0.3 (< 0.5)
- **THEN** sub-morph strengths remain unchanged after `FlipMorph::UpdateMorph`

### Requirement: UpdateMorph execution order for compound morphs

The system SHALL process Group and Flip morphs before Mesh, UV, Bone, Material, and Impulse morphs during the `UpdateMorph` loop, ensuring compound morph propagation is complete before leaf morphs push values to their respective managers.

#### Scenario: Group morph propagates before mesh morph applies
- **WHEN** `Execute()` runs the UpdateMorph loop
- **THEN** all Group and Flip morphs have their `UpdateMorph` called first (propagating strength to sub-morphs)
- **THEN** all other morph types have their `UpdateMorph` called second (pushing final strength values to mesh/bone managers)

### Requirement: Morph UI visible in VMD mode

The `MODEL_MORPH_GRP` group SHALL be visible in VMD mode, allowing users to see morph strength sliders. Add/delete/rename/editor buttons for morphs SHALL be hidden in VMD mode (same as non-edit mode behavior).

#### Scenario: Morph sliders visible during VMD playback
- **WHEN** the model is in `MODEL_MODE_VMD`
- **THEN** the `MODEL_MORPH_GRP` group is visible in the attribute manager
- **THEN** morph strength sliders display current animated values
- **THEN** morph add-name inputs and add/delete/rename buttons are hidden

#### Scenario: Morph sliders reflect CTrack animation values
- **WHEN** the model is in `MODEL_MODE_VMD` and the timeline is playing
- **THEN** morph strength sliders update in real-time to reflect CTrack keyframe interpolation

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
