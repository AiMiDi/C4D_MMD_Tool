# PMX Parameter Mapping

Naming Convention: All parameter UI display names align with PMXEditor, and Japanese/Traditional Chinese characters are unified to Simplified Chinese.

## ADDED Requirements

### Requirement: Align Existing Parameter Names with PMXEditor

The system SHALL align the Chinese display names in the TMMDBone Attribute Manager with the PMXEditor bone panel. Only modify the display names in the string resource file; parameter IDs and data remain unchanged.

#### Scenario: Parameters Display Correctly After Renaming

- **WHEN** viewing the Attribute Manager of MMDBoneTag in C4D (Chinese locale)
- **THEN** parameter names SHALL match the PMXEditor bone panel: "Rotation/Translation/IK/Display/Operation" within the performance group, bone name labels are "Bone Name (JP)"/"Bone Name (EN)", endpoint pointing group is "Display Destination", and IK uses "Target/Loop/Link/Unit Angle"

#### Scenario: Saved Scene Compatibility

- **WHEN** opening a C4D scene saved with older naming
- **THEN** all parameter data SHALL be read normally, with only display names updated

### Requirement: Bone "Append Parent L" Flag Parameter

The system SHALL expose the "Append Parent L" boolean parameter in the "Append" group of the MMDBoneTag Attribute Manager. This parameter corresponds to the PMX bone flag AppendLocal (0x0080), which controls the append source: 0=User Morph/IK/Multiple Append, 1=Parent Bone Local Transform.

#### Scenario: PMX Bone Has AppendLocal Set

- **WHEN** a bone in the imported PMX file has the 0x0080 (AppendLocal) flag
- **THEN** the "Append Parent L" parameter of the corresponding MMDBoneTag SHALL be true

#### Scenario: PMX Bone Does Not Have AppendLocal Set

- **WHEN** a bone in the imported PMX file does not have the 0x0080 flag
- **THEN** the "Append Parent L" parameter of the corresponding MMDBoneTag SHALL be false

### Requirement: Bone "Outer Parent" / "Parent Key" Parameters

The system SHALL create a new "Outer Parent" group in the MMDBoneTag Attribute Manager, exposing the "Outer Parent" boolean parameter and "Parent Key" integer parameter. During PMX import, it SHALL read and write from the bone flag DeformOuterParent (0x2000) and m_keyValue.

#### Scenario: PMX Bone Enables Outer Parent

- **WHEN** a bone in the imported PMX file has the 0x2000 (DeformOuterParent) flag
- **THEN** the "Outer Parent" parameter of the corresponding MMDBoneTag SHALL be true, and the "Parent Key" parameter SHALL be the m_keyValue from the PMX

#### Scenario: PMX Bone Does Not Enable Outer Parent

- **WHEN** a bone in the imported PMX file does not have the 0x2000 flag
- **THEN** the "Outer Parent" parameter SHALL be false, and "Parent Key" parameter SHALL be 0

### Requirement: Morph "Panel" Category Parameter

The system SHALL save the panel category value for each imported morph. The display name is "panel" (aligned with PMXEditor), and the value is a CYCLE: 1=Eyebrow, 2=Eye, 3=Mouth, 4=Other.

#### Scenario: Import Morph with Panel Category

- **WHEN** a morph in the imported PMX file has an m_controlPanel value of 2 (Eye)
- **THEN** "panel" in the corresponding morph parameters SHALL display as "Eye"

### Requirement: "Material Morph" Parameter

The system SHALL expose the "Material Morph" group and child item list in the Attribute Manager of MMDModelManagerObject. During PMX import, it SHALL import and store all morph data of type PMXMorphType::Material.

#### Scenario: Import PMX with Material Morphs

- **WHEN** the imported PMX file contains PMXMorphType::Material type morphs
- **THEN** the "Material Morph" group SHALL appear in the Attribute Manager, listing the name of each material morph

#### Scenario: Import PMX without Material Morphs

- **WHEN** the imported PMX file does not contain material morphs
- **THEN** the "Material Morph" group in the Attribute Manager SHALL be empty

### Requirement: "Impulse Morph" Parameter

The system SHALL expose the "Impulse Morph" group and child item list in the Attribute Manager of MMDModelManagerObject. During PMX import, it SHALL import and store all morph data of type PMXMorphType::Impluse.

#### Scenario: Import PMX with Impulse Morphs

- **WHEN** the imported PMX file contains PMXMorphType::Impluse type morphs
- **THEN** the "Impulse Morph" group SHALL appear in the Attribute Manager, listing the name of each impulse morph

### Requirement: "Display Frame" Parameter

The system SHALL expose "Display Frame" data in the Attribute Manager of MMDModelManagerObject. During PMX import, it SHALL iterate through pmx_file.m_displayFrames, create a group named after each display frame, and list its included bone/morph items.

#### Scenario: Import PMX with Display Frames

- **WHEN** the imported PMX file contains 2 display frames ("Root" with 1 bone, "Expression" with 3 morphs)
- **THEN** the "Display Frame" group SHALL appear in the Attribute Manager, containing "Root" and "Expression" child groups, listing their respective members

### Requirement: Vertex "Edge Scale" Parameter

The system SHALL store the per-vertex edgeMag (Edge Scale) to the mesh object during PMX import. It uses a VertexMapTag for storage, and the Tag name SHALL be "Edge Scale".

#### Scenario: Import PMX with Non-default edgeMag

- **WHEN** the imported PMX file has vertices where edgeMag is not 1.0
- **THEN** a VertexMapTag named "Edge Scale" SHALL exist on the mesh object, and the value of each vertex SHALL equal the corresponding vertex's m_edgeMag in the PMX

### Requirement: SDEF Vertex Data Parameter

The system SHALL store the vertex parameters (C, R0, R1) for SDEF weight types to the mesh object during PMX import. They are stored using 3 VertexColorTags (named "SDEF_C", "SDEF_R0", "SDEF_R1" respectively), where the RGB channels of each Tag store the X/Y/Z components of the Vector3.

#### Scenario: Import PMX with SDEF Vertices

- **WHEN** the imported PMX file has vertices with the SDEF weight type
- **THEN** three VertexColorTags "SDEF_C", "SDEF_R0", "SDEF_R1" SHALL exist on the mesh object; corresponding SDEF vertex positions SHALL be filled with C/R0/R1 values from PMX, and non-SDEF vertices SHALL be (0,0,0)