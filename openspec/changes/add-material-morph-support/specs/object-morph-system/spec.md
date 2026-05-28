## ADDED Requirements

### Requirement: Material morph definitions are persisted as editable morph data
The system SHALL persist material morph definitions with their morph name, English name, panel, target material offsets, operation type, and all PMX material morph fields. The MeshManager Attribute Manager SHALL expose a Material Morph group that can display and fully edit the persisted material morph data without relying on transient runtime material state.

#### Scenario: Imported material morph appears in MeshManager
- **WHEN** a PMX file contains a material morph with two material offsets
- **THEN** the MeshManager Attribute Manager SHALL show the material morph in the Material Morph group
- **AND** the selected material morph SHALL show both offsets with target material index, operation type, diffuse, specular, specular power, ambient, edge color, edge size, texture factor, sphere texture factor, and toon texture factor fields

#### Scenario: Edit all material morph offset fields
- **WHEN** a user selects a material morph offset in the MeshManager Material Morph group
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

### Requirement: Material morph target index supports all-material offsets
The system SHALL support PMX material morph target index `-1` as an all-material target and SHALL apply that offset to every material in the current model material list.

#### Scenario: All-material morph applies to every material
- **WHEN** a Material morph offset has target material index `-1`
- **AND** the model contains three materials
- **THEN** the offset SHALL contribute to all three material runtime states

#### Scenario: All-material target is shown in UI
- **WHEN** a Material morph offset target material index is `-1`
- **THEN** the MeshManager Material Morph group SHALL display the target as "全部材质"
- **AND** specific material link or material selection controls for that offset SHALL be disabled

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
