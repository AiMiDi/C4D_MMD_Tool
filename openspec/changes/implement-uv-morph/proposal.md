## Why

UV morphs (PMX types UV/AddUV1–4) are already imported from PMX files by `MMDMeshManagerObject`, but they are silently merged into the generic `MeshMorph` category. Users cannot distinguish UV-based deformations from vertex-position morphs in the attribute manager, and the morph type system has no first-class representation for UV morphs. Adding explicit UV morph support improves clarity for artists and aligns the plugin's type system with the PMX specification.

## What Changes

- Add `MMDMorphType::UV` enum value and a dedicated `UVMorph` class inheriting from `IMorph`.
- Add a new UI group `MODEL_MORPH_UV_GRP` in `OMMDModelManager.res` so UV morphs appear in their own section in the attribute manager.
- Update `MMDModelManagerObject::AddMorph()` and `RefreshMorph()` to recognize and create `UVMorph` instances instead of treating them as `MeshMorph`.
- Update `MMDMeshManagerObject` to tag imported UV morphs so they can be distinguished from position morphs during `RefreshMorph`.
- Update morph read/write serialization to handle the new type.

## Capabilities

### New Capabilities

- `uv-morph`: Dedicated UV morph type with separate UI group, proper type identification, and persistence support.

### Modified Capabilities

- `morph-system`: Add UVMorph to the morph type hierarchy and update morph storage/UI contracts.

## Impact

- **Source files**: `mmd_morph.h/cpp`, `mmd_model_manager.h/cpp`, `mmd_mesh_manager.h/cpp`
- **Resources**: `OMMDModelManager.res`, `OMMDModelManager.h`, string tables
- **Serialization**: HyperFile read/write paths must be backward-compatible (old scenes without UV morph type should still load)
- **No external dependency changes** — libMMD already exposes `PMXMorphType::UV` and `UVMorph` structs
