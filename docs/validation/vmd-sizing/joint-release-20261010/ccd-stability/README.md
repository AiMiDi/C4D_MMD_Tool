# CCD small-angle stability investigation (2026-10-10)

## Finding and production change

Both `MMDIkSolver::SolveCore` and `SolvePlane` calculated the turn angle using `acos` of a normalized float dot product. Near parallel links lose meaningful angle information when that dot rounds toward one. The discontinuity changes subsequent iterations and can move a knee substantially even when the foot target changed negligibly.

The production change is restricted to `src/libMMD/Model/MMD/MMDIkSolver.cpp` and `tests/MMDIkSolver.test.cpp`. A shared `StableAngleBetween` helper evaluates `atan2(norm(cross(a,b)), dot(a,b))` with the original vectors promoted to double for the products. Both paths call it. Existing rotation direction, plane direction selection, axis limits, iteration counts, small-vector guard and stopping thresholds remain unchanged. There is no hardcoded model scale or C4D dependency.

## Reproducible synthetic regression

The new single-joint test uses an effector at `(0, radius, 0)` and an external target rotated by + or - 0.0003 radians around X. It checks both a free joint and an X-only plane joint at radii 1, 8.5 and 100, after the same four iterations. The required final distance is less than 0.00001 times the radius.

- Frozen pre-change solver: all 12 new residual assertions fail; 816/828 assertions pass. Residuals range from 0.000045267 to 0.0003 times radius.
- Production solver: 828/828 assertions pass. Maximum new residual is 2.73918e-11 times radius.
- Both standalone comparison targets use AVX2, link the same SDK library, and override only the solver translation unit. `MMDIkSolver-old.cpp` freezes the negative control; it is not a replacement production file.
- Official standalone Release/SSE2 core build and CTest also pass `mmd_ik_solver_test`, `mmd_motion_sizing_test`, and `mmd_motion_sizing_advanced_test` (3/3).

Commands:

```powershell
cmake --build S:/tmp/cmt-joint-ik-review-20261010/build --config Release --target ik_regression_old ik_regression_fixed
S:/tmp/cmt-joint-ik-review-20261010/build/Release/ik_regression_old.exe
S:/tmp/cmt-joint-ik-review-20261010/build/Release/ik_regression_fixed.exe
cmake --build C:/code/C4D_MMD_Tool/_build_msvc/libmmd-sizing-standalone --config Release --target mmd_ik_solver_test mmd_motion_sizing_test mmd_motion_sizing_advanced_test
ctest --test-dir C:/code/C4D_MMD_Tool/_build_msvc/libmmd-sizing-standalone -C Release -R 'mmd_ik_solver_test|mmd_motion_sizing_test|mmd_motion_sizing_advanced_test' --output-on-failure
```

## Real asset experiment

Inputs are `S:/tmp/cmt-joint-validation-20261010/target-normalized.pmx` and `adjusted.vmd` from the parent task's real Sour-to-Afu run. Frame 258 has a nearly extended right leg. At this frame, perturb the right foot IK local target by +/- 1e-8, 1e-7, 1e-6, or 1e-5 PMX units in each of three axes, and measure the resulting knee displacement in scene units (8.5 times PMX units).

| Solver variant | Maximum knee change (scene units) |
|---|---:|
| Both original acos paths | 0.5890956161 |
| Only free path stabilized | 0.0111697023 |
| Only plane path stabilized | 0.2125279790 |
| Both paths stabilized | 0.0001107213 |
| Actual production helper | 0.0001107213 |

Replacing only one path is insufficient. For the +/- 1e-7 PMX X perturbation, the old knee changes were 0.220509 and 0.142839 scene units; the fixed values were 0.0000137821 and 0.00000151992.

A second experiment samples 80 leg points (10 bones x 8 frames), comparing unscaled PMX/VMD against uniformly scaled geometry and translations, with output converted back to a common scene unit. An alternate private node implementation normalizes local rotation and roundtrips quaternion/matrix conversion to probe node-path sensitivity.

- Production geometry/motion scale 1 vs 8.5: max 0.0025763519 scene units (frame 776, right knee).
- Production normal PMX node vs alternate normalized node, scale 1: max 0.0044678856 (frame 776, right ankle).
- Same node-path comparison at scale 8.5: max 0.0011488384 (frame 373, left ankle).
- Actual production-helper outputs are numerically identical to the private two-path experiment.

The alternate node is an experiment only. No node normalization change is proposed. The C4D adapter works in model-local PMX-sized coordinates; its model-root 8.5 transform and scene X offset do not mean its CCD chain is solved in absolute world space. Scaling the offline bridge to 8.5 merely to match one native frame would violate that contract.

Commands:

```powershell
cmake --build S:/tmp/cmt-joint-ik-review-20261010/build --config Release --target perturb_production pose_production
S:/tmp/cmt-joint-ik-review-20261010/build/Release/perturb_production.exe S:/tmp/cmt-joint-validation-20261010/target-normalized.pmx S:/tmp/cmt-joint-validation-20261010/adjusted.vmd
S:/tmp/cmt-joint-ik-review-20261010/build/Release/pose_production.exe S:/tmp/cmt-joint-validation-20261010/adjusted.vmd S:/tmp/cmt-joint-validation-20261010/target-normalized.pmx
python S:/tmp/cmt-joint-ik-review-20261010/summarize.py
```

## Evidence and boundary

`stable-angle-summary.json` holds recomputed metrics and SHA-256 hashes of production sources and real inputs. `regression-old.txt`, `regression-fixed.txt`, `core-focused-ctest.txt`, `perturbation-production.txt`, and `production-poses.tsv` retain the measurements; other variant files isolate the cause.

This confirms a reproducible shared CCD numerical defect and verifies the minimal fix in synthetic and real-asset offline runs. It does not yet certify native parity in the newly loaded C4D DLL. The parent task owns that final native recheck and release decision. No C4D process was touched by this subagent, and no commits were made.
