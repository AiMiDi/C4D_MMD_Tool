# Model Import (PMX)

## Purpose

Imports PMX (Polygon Model eXtended) model files into Cinema 4D, creating a complete MMD model hierarchy with bones, mesh, materials, rigid bodies, joints, and morphs.

## Requirements

### Requirement: PMX model import entry point
The system SHALL import PMX model files through the tool manager, parse the PMX data with libMMD, and delegate scene creation to `CMTSceneManager`.

#### Scenario: Import a PMX file
- **WHEN** the user selects a PMX model file through the import model command
- **THEN** the system SHALL read the file, parse it as a PMX model, and create a corresponding `MMDModelManagerObject` hierarchy in the active Cinema 4D document

### Requirement: Import option handling
The PMX import flow SHALL honor `ModelImport` settings for scale, model components, name conversion, and material renderer type.

#### Scenario: Import options are applied
- **WHEN** a PMX import runs with specific `ModelImport` flags
- **THEN** the importer SHALL enable or skip polygon, normal, UV, material, bone, weight, IK, inherit, expression, multipart, and English-name handling according to those flags

### Requirement: PMX data mapping
The import flow SHALL map PMX model data into the plugin's C4D objects, tags, materials, morphs, physics objects, and display frame data.

#### Scenario: PMX contains extended model data
- **WHEN** a PMX file contains bones, materials, morphs, physics, vertex attributes, and display frames
- **THEN** the imported scene SHALL preserve those fields in the corresponding MMD manager objects, tags, material data, morph containers, rigid bodies, joints, and display frame structures

## Import Pipeline

```
User clicks "Import Model" in CMTToolDialog
    │
    ▼
CMTToolsManager::ImportPMXModel(ModelImport setting)
    │
    ├── filename_util::ReadFileData(filename) → raw bytes
    ├── libmmd::ReadPMXFile(data) → PMXFile (raw structures)
    │
    ├── PMXModel::LoadPMX(pmx_file, model_dir, mmd_data_path)
    │       → Parsed model with bones, meshes, materials, physics
    │
    └── CMTSceneManager::LoadPMXModel(pmx_model, setting)
            │
            ├── Create MMDModelManagerObject (root node)
            ├── MMDModelManagerObject::CreateManagers()
            │       → Bone/Mesh/Rigid/Joint manager children
            │
            └── MMDModelManagerObject::LoadPMX(pmx_model)
                    ├── MMDBoneManagerObject::LoadPMX()
                    │       → Bone joints + MMDBoneTag per bone
                    │       → IK chains, inheritance
                    ├── MMDMeshManagerObject::LoadPMX()
                    │       → Polygon objects, UVs, normals, weights
                    │       → Materials via MMDMaterialManager
                    ├── MMDRigidManagerObject::LoadPMX()
                    │       → MMDRigidObject per rigid body
                    ├── MMDJointManagerObject::LoadPMX()
                    │       → MMDJointObject per joint
                    └── Load Group/Flip morphs
```

## Import Options (`ModelImport`)

| Option | Type | Default | Description |
|--------|------|---------|-------------|
| `position_multiple` | Float | — | Scale factor for positions |
| `import_polygon` | Bool | — | Import polygon mesh |
| `import_normal` | Bool | — | Import vertex normals |
| `import_uv` | Bool | — | Import UV coordinates |
| `import_material` | Bool | — | Import materials |
| `import_bone` | Bool | — | Import bone skeleton |
| `import_weights` | Bool | — | Import skin weights |
| `import_ik` | Bool | — | Import IK chains |
| `import_inherit` | Bool | — | Import bone inheritance |
| `import_expression` | Bool | — | Import morph expressions |
| `import_multipart` | Bool | — | Split mesh by material |
| `import_english` | Bool | — | Use English bone names |
| `import_english_check` | Bool | — | Verify English name availability |
| `import_material_type` | enum | Standard | Standard / RedShift / Octane / Corona |

## Data Mapping: PMX → C4D

| PMX Data | C4D Representation |
|----------|-------------------|
| Model | MMDModelManagerObject |
| Bone | Joint object + MMDBoneTag |
| Bone flags (AppendLocal, OuterParent) | MMDBoneTag parameters |
| Vertex/Face | PolygonObject |
| Vertex edgeMag | VertexMapTag ("轮廓倍率") |
| Vertex SDEF C/R0/R1 | 3× VertexColorTag ("SDEF_C/R0/R1") |
| Material | BaseMaterial (Standard) |
| Texture | BaseShader (bitmap) |
| Rigid body | MMDRigidObject |
| Joint | MMDJointObject |
| Morph (group) | GroupMorph in model |
| Morph (flip) | FlipMorph in model |
| Morph (vertex) | MeshMorph on mesh |
| Morph (bone) | BoneMorph on bones |
| Morph (material) | MaterialMorph in model |
| Morph (impulse) | ImpulseMorph in model |
| Morph panel (m_controlPanel) | CYCLE parameter per morph |
| Display frame | DisplayFrameData in model |

## Extended Import Fields

### Bone Extended Parameters

`MMDBoneManagerObject::LoadPMX` reads additional bone flags:
- AppendLocal (0x0080) → `PMX_BONE_INHERIT_LOCAL`
- DeformOuterParent (0x2000) → `PMX_BONE_OUTER_PARENT`
- m_keyValue → `PMX_BONE_OUTER_PARENT_KEY`

### Morph Extended Parameters

Each morph stores its `m_controlPanel` value (1=眉, 2=目, 3=口, 4=其他) as a CYCLE "panel" parameter. Material (`PMXMorphType::Material`) and impulse (`PMXMorphType::Impluse`) morph types are imported into dedicated groups.

### Vertex Extended Data

- **Edge magnitude**: Per-vertex `m_edgeMag` stored in VertexMapTag named "轮廓倍率"
- **SDEF data**: For SDEF weight-type vertices, C/R0/R1 vectors stored in 3 VertexColorTags ("SDEF_C", "SDEF_R0", "SDEF_R1"), XYZ → RGB channels

### Display Frames

`MMDModelManagerObject::LoadPMX` iterates `pmx_file.m_displayFrames`, creating `DisplayFrameData` entries with frame name, type, and bone/morph member references.

## Export Status

`ExportPMXModel` exists in `cmt_tools_manager` but `CMTSceneManager::SavePMXModel()` returns `nullptr`. **PMX export is not implemented.**

## Source Files

| File | Role |
|------|------|
| `cmt_tools_manager.cpp` | `ImportPMXModel()` — file reading + parse entry |
| `CMTSceneManager.cpp` | `LoadPMXModel()` — scene object creation |
| `module/tools/object/mmd_model_manager.cpp` | `LoadPMX()` — delegate to managers |
| `module/tools/object/mmd_bone_manager.cpp` | Bone import |
| `module/tools/object/mmd_mesh_manager.cpp` | Mesh import |
| `module/tools/object/mmd_rigid_manager.cpp` | Rigid body import |
| `module/tools/object/mmd_joint_manager.cpp` | Joint import |
| `module/tools/material/mmd_material.cpp` | Material creation and texture loading |
