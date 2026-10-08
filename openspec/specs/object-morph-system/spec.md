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

### Requirement: Material morph definitions are persisted as editable morph data
The system SHALL persist material morph definitions with their morph name, English name, panel, target material offsets, operation type, and all PMX material morph fields. The ModelManager Attribute Manager SHALL expose a Material Morph group that can display and fully edit the persisted material morph data without relying on transient runtime material state.

#### Scenario: Imported material morph appears in ModelManager
- **WHEN** a PMX file contains a material morph with two material offsets
- **THEN** the ModelManager Attribute Manager SHALL show the material morph in the Material Morph group
- **AND** the selected material morph SHALL show both offsets with target material index, operation type, diffuse, specular, specular power, ambient, edge color, edge size, texture factor, sphere texture factor, and toon texture factor fields

#### Scenario: Edit all material morph offset fields
- **WHEN** a user selects a material morph offset in the ModelManager Material Morph group
- **THEN** the user SHALL be able to edit target material index, operation type, diffuse, specular, specular power, ambient, edge color, edge size, texture factor, sphere texture factor, and toon texture factor fields
- **AND** each edited field SHALL be persisted in the material morph data model

#### Scenario: Material morph survives scene save and reopen
- **WHEN** a C4D scene containing imported material morph data is saved and reopened
- **THEN** the material morph list and every offset field SHALL be restored from HyperFile data
- **AND** the restored material morph SHALL keep the same morph strength identity used by animation tracks

### Requirement: Material morph runtime evaluation uses effective morph strengths
The system SHALL apply material morphs from the effective strengths produced by the model morph runtime evaluation pass. Group and Flip morph contributions SHALL be resolved before material morphs update material runtime state.

#### Scenario: Group morph drives material morph
- **WHEN** a Group morph references a Material morph with weight 0.5 and the Group morph strength is 0.8
- **THEN** the Material morph SHALL be evaluated with an effective strength contribution of 0.4
- **AND** the target material runtime state SHALL reflect that contribution

#### Scenario: Direct and group material strengths add together
- **WHEN** a Material morph has direct strength 0.3
- **AND** a Group morph contributes 0.4 to the same Material morph
- **THEN** the Material morph SHALL be evaluated with effective strength 0.7

### Requirement: Material morph evaluation is non-accumulating
The system SHALL compute material morph results from base material data for each runtime evaluation and SHALL NOT mutate the stored base material data while applying morph strengths.

#### Scenario: Repeated evaluation does not drift
- **WHEN** a Material morph with strength 1.0 is evaluated for the same frame multiple times
- **THEN** the target material runtime state SHALL be identical after each evaluation
- **AND** the stored base `MMDMaterialData` SHALL remain unchanged

#### Scenario: Strength returns to zero restores base material
- **WHEN** a Material morph changes a material alpha at strength 1.0
- **AND** the Material morph strength later becomes 0.0
- **THEN** the target material runtime state SHALL match the base material alpha

#### Scenario: Removing the final material morph definition restores base material
- **WHEN** a Material morph currently affects one or more linked C4D materials
- **AND** the user removes its final offset or deletes the final Material morph
- **THEN** the linked C4D materials SHALL be synchronized once more from base `MMDMaterialData`
- **AND** no value from the previously active Material morph SHALL remain visible

### Requirement: Material morph target index supports all-material offsets
The system SHALL support PMX material morph target index `-1` as an all-material target and SHALL apply that offset to every material in the current model material list.

#### Scenario: All-material morph applies to every material
- **WHEN** a Material morph offset has target material index `-1`
- **AND** the model contains three materials
- **THEN** the offset SHALL contribute to all three material runtime states

#### Scenario: All-material target is shown in UI
- **WHEN** a Material morph offset target material index is `-1`
- **THEN** the ModelManager Material Morph group SHALL display the target as "全部材质"
- **AND** specific material selection controls for that offset SHALL be disabled

#### Scenario: Invalid material index is safe
- **WHEN** a Material morph offset targets a material index that is outside the current material list
- **THEN** runtime evaluation SHALL skip that offset without crashing
- **AND** PMX export SHALL report or preserve the unresolved offset according to the export policy

### Requirement: Material morph runtime effects are separated by model mode
The system SHALL keep editable base material data and material morph offset definitions separate from runtime material morph effects. Animation and VMD modes SHALL apply material morph effects to runtime material state, while Edit mode SHALL restore or display base material values unless an explicit preview path is used.

#### Scenario: Enter animation mode applies material morph runtime state
- **WHEN** the model switches from Edit mode to Animation or VMD mode
- **AND** one or more Material morph strengths are non-zero
- **THEN** the material runtime state SHALL be computed from base material data and effective Material morph strengths
- **AND** linked C4D materials SHALL show the runtime material morph effect

#### Scenario: Return to edit mode restores base material state
- **WHEN** the model switches from Animation or VMD mode back to Edit mode
- **THEN** linked C4D materials SHALL be restored to base `MMDMaterialData` values
- **AND** material morph offset definitions SHALL remain unchanged

#### Scenario: Edit material morph offsets without applying runtime effect
- **WHEN** the model is in Edit mode and the user changes a Material morph offset field
- **THEN** the stored material morph definition SHALL change
- **AND** the linked C4D material SHALL NOT permanently bake the current runtime Material morph effect into base material data

### Requirement: Morph Types
The plugin SHALL support the following morph types corresponding to the PMX specification, alongside its existing Material and Impulse morph support:
- **Group** (`GroupMorph`): Combines multiple other morphs by weight.
- **Flip** (`FlipMorph`): Toggles between two morph states.
- **Mesh** (`MeshMorph`): Per-vertex position offsets for polygon objects.
- **UV** (`UVMorph`): Per-face UV coordinate offsets.
- **Bone** (`BoneMorph`): Bone transformation offsets.

#### Scenario: Distinguishing position and UV types
- **WHEN** a model contains both position and UV-based morphs
- **THEN** inspection reports the position morph as Mesh and all UV-based morphs as UV.

### Requirement: Class Hierarchy
All morph types SHALL implement the `IMorph` interface defined in `mmd_morph.h`.

#### Scenario: UV leaf implementation
- **WHEN** a UV morph is created through the common morph interface
- **THEN** `UVMorph` provides the common name, strength, update and UI operations through `IMorph`.

### Requirement: Morph UI Ordering
The Attribute Manager SHALL display morph groups in the following order: Group, Flip, Mesh, UV, Bone.

#### Scenario: UV group placement
- **WHEN** the model Attribute Manager description is built
- **THEN** the UV group is placed after Mesh and before Bone, while existing Material and Impulse groups are retained.

### Requirement: Morph Storage
- Morphs SHALL be owned by `MMDModelManagerObject`.
- Group and Flip morphs are loaded during `MMDModelManagerObject::LoadPMX()`.
- Mesh and UV morphs are processed by `MMDMeshManagerObject`.
- Bone morphs are handled via the bone system.
- Morph strengths in the UI are synced from the actual `CAPoseMorphTag` values during updates to ensure consistency after operations like Undo.

#### Scenario: Coexistence of UV and Mesh Morphs
- **WHEN** UV morphs are imported from a PMX
- **THEN** They are stored alongside Mesh morphs in the mesh manager's morph data structures, distinguished by the UV morph names set.

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
