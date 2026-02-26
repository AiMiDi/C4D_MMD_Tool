# GLM → Eigen Migration & Coordinate System Refactoring

## Summary

Replaced GLM (OpenGL Mathematics) with Eigen as the math library in libMMD. Removed the internal Z-axis negation from libMMD, unifying its internal coordinate system to original PMX space. Added explicit coordinate conversion at the C4D plugin boundary.

## Motivation

- GLM is an OpenGL-oriented library; Eigen is more general-purpose and widely used in C++ scientific/engineering code.
- libMMD previously applied Z-negation (`z *= -1`) on all bone positions, animation data, and physics transforms to convert from MMD's left-handed coordinate system to an OpenGL-style right-handed system. This added complexity and was a source of bugs during the Eigen migration.
- Removing Z-negation from libMMD makes its output match the original PMX/VMD file data directly, simplifying the internal data flow.

## Changes

### libMMD Internal (dependency/libMMD)

| Area | Before (GLM) | After (Eigen) |
|------|-------------|----------------|
| Math library | `glm::vec3`, `glm::mat4`, `glm::quat` | `Eigen::Vector3f`, `Eigen::Matrix4f`, `Eigen::Quaternionf` |
| Bone positions | Z-negated on load (`z *= -1`) | Original PMX coordinates |
| VMD animation translate | Z-negated (`cwiseProduct(1,1,-1)`) | Original VMD data |
| VMD animation rotation | InvZ'd (`S*R*S`, `S=diag(1,1,-1)`) | Original VMD quaternion |
| Physics transforms | InvZ conversions on input/output | Direct pass-through |
| VPD pose loading | Z-negated translation and rotation | Original data |
| Internal coordinate system | Right-handed (Z+ out of screen) | Left-handed (Z+ into screen, original MMD) |

### C4D Plugin Boundary (refactoring/)

MMD and C4D are both left-handed coordinate systems but with **opposite Z directions**:

| System | X | Y | Z |
|--------|---|---|---|
| MMD (PMX/VMD) | Right | Up | Into screen |
| Cinema 4D | Right | Up | Toward viewer |

This means X/Y rotation directions are reversed between the two systems. The conversion is handled at the plugin output boundary:

#### Bone transforms (`mmd_bone.cpp` — `MMDBoneTag::Execute`)

- **Position delta**: No conversion needed (mesh vertices, bone frozen positions, and animation deltas all use original PMX space consistently).
- **Rotation matrix**: Converted via `S*R*S` (`S=diag(1,1,-1)`) to flip X/Y rotation directions for C4D.

```
SetRelMl(Matrix{
    Vector(translate.x(), translate.y(), translate.z()) * pm,        // position: original
    Vector( local(0,0),  local(1,0), -local(2,0)),                   // rotation: S*R*S
    Vector( local(0,1),  local(1,1), -local(2,1)),
    Vector(-local(0,2), -local(1,2),  local(2,2)) });
```

#### Rigid body display (`mmd_rigid.cpp` — `MMDRigidObject::Execute`)

- **Position**: Z component negated.
- **Rotation columns**: Z row negated (S*M left-multiplication).

```
SetMl(Matrix{
    Vector(transform(0,3), transform(1,3), -transform(2,3)) * pm,   // position: Z negated
    Vector(transform(0,0), transform(1,0), -transform(2,0)),        // rotation: Z row negated
    Vector(transform(0,1), transform(1,1), -transform(2,1)),
    Vector(transform(0,2), transform(1,2), -transform(2,2)) });
```

### Mesh & Bone Rest Pose (unchanged)

- Mesh vertex positions: loaded from `pmx_vertex.m_position` directly (original PMX space).
- Bone frozen positions: loaded from `mmd_bone.m_position` directly (original PMX space).
- No coordinate conversion applied to static geometry or rest poses.

## Affected Specs

- **vmd-motion**: Bone transform application in `MMDBoneTag::Execute` now includes S*R*S rotation conversion.
- **physics**: Rigid body display transform includes Z-row negation for C4D rendering.
- **model-import**: No change to import pipeline; bone/mesh positions remain in original PMX space.

## Affected Source Files

| File | Change |
|------|--------|
| `dependency/libMMD` (submodule) | GLM → Eigen, removed all `InvZ` / Z-negation |
| `refactoring/module/tools/tag/mmd_bone.cpp` | S*R*S rotation conversion in Execute |
| `refactoring/module/tools/object/mmd_rigid.cpp` | Z-row negation in Execute |
| `init.bat` | Added libMMD test execution (ctest) |
| `dependency/libMMD/tests/MMDModel.test.cpp` | Coordinate system consistency tests |
