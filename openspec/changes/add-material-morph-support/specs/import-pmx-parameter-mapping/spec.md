## MODIFIED Requirements

### Requirement: "Material Morph" Parameter
The system SHALL expose a "Material Morph" group and child item list in the Attribute Manager of MMDMeshManagerObject, linked to the model morph list used by MMDModelManagerObject. During PMX import, it SHALL import and store all morph data of type PMXMorphType::Material, including every material offset field required for PMX export and runtime material morph evaluation.

#### Scenario: Import PMX with Material Morphs
- **WHEN** the imported PMX file contains PMXMorphType::Material type morphs
- **THEN** the "Material Morph" group in the MeshManager Attribute Manager SHALL list each material morph
- **AND** each material morph SHALL preserve its name, English name, panel, and material offset list

#### Scenario: Import PMX without Material Morphs
- **WHEN** the imported PMX file does not contain material morphs
- **THEN** the "Material Morph" group in the MeshManager Attribute Manager SHALL be empty

#### Scenario: Import PMX material morph offset fields
- **WHEN** a PMX material morph offset contains target material index, operation type, diffuse, specular, specular power, ambient, edge color, edge size, texture factor, sphere texture factor, and toon texture factor values
- **THEN** the imported material morph data SHALL store all of those fields without dropping unsupported visual fields

#### Scenario: Export PMX with material morphs
- **WHEN** a plugin-managed model containing material morph data is exported to PMX
- **THEN** the exported PMX morph section SHALL contain PMXMorphType::Material entries reconstructed from the persisted material morph data
- **AND** each exported material morph offset SHALL preserve target material index, operation type, diffuse, specular, specular power, ambient, edge color, edge size, texture factor, sphere texture factor, and toon texture factor values
