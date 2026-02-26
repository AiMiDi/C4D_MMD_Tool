# Model Import (PMX)

## Overview

Imports PMX (Polygon Model eXtended) model files into Cinema 4D, creating a complete MMD model hierarchy with bones, mesh, materials, rigid bodies, joints, and morphs.

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
| `import_material_type` | enum | Standard | Standard / RedShift / Octane |

## Data Mapping: PMX → C4D

| PMX Data | C4D Representation |
|----------|-------------------|
| Model | MMDModelManagerObject |
| Bone | Joint object + MMDBoneTag |
| Vertex/Face | PolygonObject |
| Material | BaseMaterial (Standard) |
| Texture | BaseShader (bitmap) |
| Rigid body | MMDRigidObject |
| Joint | MMDJointObject |
| Morph (group) | GroupMorph in model |
| Morph (flip) | FlipMorph in model |
| Morph (vertex) | MeshMorph on mesh |
| Morph (bone) | BoneMorph on bones |

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
| `module/tools/mmd_material.cpp` | Material creation |
