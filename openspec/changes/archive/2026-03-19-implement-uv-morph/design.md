## Context

UV morphs are one of the PMX morph types (types 3–7: UV, AddUV1–4). They modify per-face UV coordinates rather than vertex positions. The plugin already imports UV morph data from PMX files in `MMDMeshManagerObject::LoadPMX()` using `CAPoseMorphTag` with `ID_CA_POSE_UV` flag and `CAMorphNode::SetUV()`. However, at the type system and UI level, UV morphs are indistinguishable from position (mesh) morphs — both use `MeshMorph` class and appear under `MODEL_MORPH_MESH_GRP`.

Current flow:
1. `MMDMeshManagerObject::LoadPMX()` imports UV morphs into `CAPoseMorphTag` (correct)
2. `RefreshMeshMorphData()` discovers all morphs by name from pose morph tags → stores in `mesh_morph_name_`
3. `MMDModelManagerObject::RefreshMorph()` calls `GetMeshMorphData()` → creates `MeshMorph` for every entry
4. UV morphs end up as `MeshMorph` instances under the Mesh morph UI group

## Goals / Non-Goals

**Goals:**
- Add `MMDMorphType::UV` and a `UVMorph` class so the type system distinguishes UV from position morphs
- Add `MODEL_MORPH_UV_GRP` UI group in the attribute manager for UV morphs
- Ensure UV morphs are correctly identified during both PMX import and scene refresh
- Maintain backward compatibility with existing saved scenes (old `MeshMorph` serialization)

**Non-Goals:**
- Changing how UV morph data is actually applied to `CAPoseMorphTag` (import logic in `mmd_mesh_manager.cpp` is already correct)
- Adding UV morph export support (current export path can remain as-is)
- Supporting material morphs or impulse morphs (separate effort)

## Decisions

### 1. UV morph identification via separate name set in MMDMeshManagerObject

**Decision**: Store a `maxon::HashSet<String> uv_morph_names_` alongside `mesh_morph_name_` in `MMDMeshManagerObject`. During `LoadPMX()`, insert UV morph names into this set. Expose via `GetUVMorphNames()`.

**Why not inspect CAPoseMorphTag flags?** The pose morph tag's `ID_CA_POSE_UV` is a tag-level flag, not per-morph. Once enabled, all morphs on that tag could theoretically have UV data. There's no reliable per-morph API to query whether a morph modifies UVs vs points without iterating morph nodes. Storing the names explicitly at import time is simple and deterministic.

**Why not a combined map with type flag?** That would change the `mesh_morph_name_` value type from `Int32` to a struct, breaking serialization compatibility and requiring more refactoring. A separate set is additive.

### 2. UVMorph class mirrors MeshMorph

**Decision**: `UVMorph` is a leaf class inheriting `IMorph`, structurally identical to `MeshMorph` (name + strength only). The actual morph data lives in the `CAPoseMorphTag`; the class just provides UI and type identification.

**Alternative considered**: Adding UV-specific fields (e.g., which UV channel: UV/AddUV1–4). Rejected for now — the channel is already baked into the pose morph tag during import. If needed later, it can be added without breaking changes.

### 3. RefreshMorph distinguishes UV vs mesh morphs

**Decision**: `MMDModelManagerObject::RefreshMorph()` will call both `GetMeshMorphData()` and `GetUVMorphNames()`. For each name in `GetMeshMorphData()`, check if it's also in the UV name set → create `UVMorph` instead of `MeshMorph`.

### 4. Serialization backward compatibility

**Decision**: `uv_morph_names_` is serialized after existing fields in `MMDMeshManagerObject::Write()`. In `Read()`, attempt to read the UV name set; if the file ends (old format), treat all as mesh morphs. This preserves old scene loading.

For `UVMorph` class serialization: reuse `IMorph::Read/Write` (same as `MeshMorph`). The morph type is determined by the parent morph map, not by the `IMorph` serialization.

### 5. UI layout

**Decision**: Add `MODEL_MORPH_UV_GRP` group between `MODEL_MORPH_MESH_GRP` and `MODEL_MORPH_BONE_GRP` in `OMMDModelManager.res`. UV morphs are display-only sliders (like mesh/bone morphs) — no add/delete/rename buttons since they come from the pose morph tag.

## Risks / Trade-offs

- **[Risk] RefreshMeshMorphData doesn't persist UV names across scene reloads without PMX re-import** → Mitigation: `uv_morph_names_` is serialized in HyperFile, so it survives save/load cycles.
- **[Risk] Old scenes have no UV name set — all morphs appear as mesh morphs** → Acceptable degradation: users can re-import PMX to get proper classification. No data loss.
- **[Trade-off] UV morphs still share the same `mesh_morph_data_` storage** → UV morphs and mesh morphs both work through the same `SetMorphStrength` path, which is correct since they both go through `CAPoseMorphTag`. Splitting storage would be unnecessary complexity.
