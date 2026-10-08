## 1. Type System & Class

- [x] 1.1 Add `UV = 1 << 4` to `MMDMorphType` enum in `mmd_morph.h`
- [x] 1.2 Create `UVMorph` class in `mmd_morph.h` inheriting `IMorph` (constructor, move, `GetType`, `UpdateMorph`, `AddMorphUI`, `DeleteMorphUI`)
- [x] 1.3 Implement `UVMorph` methods in `mmd_morph.cpp` — `UpdateMorph` calls `SetMorphStrength`, `AddMorphUI` places slider under `MODEL_MORPH_UV_GRP`

## 2. Resource Descriptions (UI)

- [x] 2.1 Add `MODEL_MORPH_UV_GRP` enum value in `res/S24_up/description/OMMDModelManager.h`
- [x] 2.2 Add `GROUP MODEL_MORPH_UV_GRP {}` between `MODEL_MORPH_MESH_GRP` and `MODEL_MORPH_BONE_GRP` in `OMMDModelManager.res`
- [x] 2.3 Add localized string for `MODEL_MORPH_UV_GRP` in string resource files (`res/S24_up/strings_*/description/OMMDModelManager.str`)

## 3. Mesh Manager — UV Morph Name Tracking

- [x] 3.1 Add `maxon::HashSet<String> uv_morph_names_` member to `MMDMeshManagerObject` in `mmd_mesh_manager.h`
- [x] 3.2 Add `GetUVMorphNames()` accessor method returning `const maxon::HashSet<String>&`
- [x] 3.3 In `MMDMeshManagerObject::LoadPMX()`, insert morph names into `uv_morph_names_` when `PMXMorphType` is UV/AddUV1–4 (both single-mesh and multi-part paths)
- [x] 3.4 Serialize `uv_morph_names_` in `Write()` after existing fields
- [x] 3.5 Deserialize `uv_morph_names_` in `Read()` with backward-compatible fallback (if data not present, leave set empty)
- [x] 3.6 Copy `uv_morph_names_` in `CopyTo()`

## 4. Model Manager — Morph Creation & Refresh

- [x] 4.1 Add `MMDMorphType::UV` case in `MMDModelManagerObject::AddMorph()` to create `UVMorph` instances
- [x] 4.2 Update `MMDModelManagerObject::RefreshMorph()` to query `GetUVMorphNames()` and create UV morphs with `MMDMorphType::UV` instead of `MMDMorphType::MESH` for matching names

## 5. Verification

- [x] 5.1 Build project and verify no compile errors
- [ ] 5.2 Import a PMX model with UV morphs and verify they appear under the UV morph group in the attribute manager
- [ ] 5.3 Verify position morphs still appear under the Mesh group
- [ ] 5.4 Test save/reload scene and confirm UV morph classification persists

