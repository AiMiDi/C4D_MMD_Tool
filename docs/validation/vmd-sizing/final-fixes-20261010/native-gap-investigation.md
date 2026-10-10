# Native knee gap investigation — 2026-10-10

## Scope and frozen inputs

Read-only investigation; no C4D actions or production edits. Inputs: target A-Fu PMX from the UTF-8 asset manifest, `S:/tmp/cmt-sizing-audit-20261010/leg-reviewed-results/legs/stage-6.vmd`, and `reviewed-native-positions.response.json`. Native replay history was checked separately by the parent: repeated frame 258 was stable within 2.56e-14 scene units.

## Concrete interface defect / smallest repair candidate

`MMDIkSolver::UpdatePathGlobalTransform` (`dependency/libMMD/src/libMMD/Model/MMD/MMDIkSolver.cpp:169-178`) calculates `parentGlobal * local` and sends that cache result through `IMMDNode::SetGlobalTransform`.

- libMMD `MMDNode.h:218`: assigns global only.
- C4D `source/module/tools/tag/mmd_bone.cpp:797-803`: also reconstructs local by `parentGlobal.inverse() * global`.

The latter round-trip perturbs local matrices on every CCD path update. This is not an intended pose correction, and makes the shared solver depend on host node implementation, ISA and model scale.

Smallest proposed fix: C4D adapter `SetGlobalTransform` should assign global only, matching MMDNode. Keep local reconstruction in its explicit `SyncLocalTransformFromGlobal` method.

Call-site audit supports this separation: actual SetGlobal consumers are the IK tracked-path cache and libMMD physics. C4D `ApplyStandalonePhysicsResults`, `mmd_model_runtime.cpp:885-888`, already calls `SyncStandaloneBoneAdaptersLocalFromGlobal(physics_dynamic_bone_indices_)` immediately after all rigid-body `ReflectGlobalTransform` calls. Physics therefore has an explicit synchronization boundary; it need not depend on the implicit setter side effect.

This is an evidence-backed mechanism and minimal repair candidate, not a claim that a modified DLL has passed native validation. C4D IK and physics writeback must be retested after implementation.

## Controlled offline experiments

All numbers below are scene-unit error against the same native result. Variant code is reviewer-owned. `reference-adapter.cpp` mimics the C4D setter side effect and normalized local rotation; `reference.cpp` is the normalization-only variant. Neither is proposed as production code (the temporary `final`-removal macro is solely a comparison harness).

| Library / node path | Scale used during IK | Frame 258 right knee error |
| --- | ---: | ---: |
| Standalone SSE2 / regular PMXNode | 1 | 0.594163 |
| Standalone SSE2 / regular PMXNode | 8.5 | 0.632540 |
| SDK AVX2 / regular PMXNode | 1 | 0.632009 |
| SDK AVX2 / regular PMXNode | 8.5 | 0.587056 |
| SDK AVX2 / normalization only | 8.5 | 0.579154 |
| SDK AVX2 / normalization + local reconstruction in SetGlobal | 1 | 0.290256 |
| SDK AVX2 / normalization + local reconstruction in SetGlobal | 8.5 | 0.039031 |

Last case maximum over the sampled 80 points was 0.056713 (frame 313 left knee). Reproducing the C4D local-reconstruction side effect strongly narrows the gap; normalization alone does not. Matching the host defect in offline code is not the recommended fix.

## Exclusions / remaining limits

- Model root X=55 is not an IK input: adapters are built only for bones, linked only to bone parents (`mmd_model_runtime.cpp:500-567`), and root transforms start at bone GetMl/GetFrozenMln (`mmd_bone.cpp:697-769`). They operate in model-relative coordinates. Adding 55 to an offline rig would test an unrelated numerical perturbation.
- Actual A-Fu foot IK iteration counts are 40. Toe IK counts are 3, and their sole link is the ankle. The previous 1–3 iteration contract bug is fixed, but does not directly explain a knee/hip pose change.
- Solver does have absolute thresholds: distance 1e-5, squared-vector norm 1e-12; angular cutoff 1.75e-5. Scaling alone did not eliminate the gap. No production iteration count or tolerance was changed to improve the comparison.
- Standalone audit library is SSE2; SDK playback and IK library are AVX2. MotionSizing-only SSE2 source properties do not make its privately called playback solver SSE2. Future acceptance should include the actual SDK-linked library and actual host scale, not only the standalone library.
- Remaining differences after the controlled node comparison are not fully attributed. Keep the actual latest native receipt and do not carry forward the earlier 0.0557 maximum as if it covered the newer output.

## Files

- `parity-experiments.json`: compact summary for every experiment.
- `scaled-*.tsv`: all sampled coordinates.
- `main.cpp`: loads the PMX and final VMD; evaluates 1 and 8.5 scales.
- `reference.cpp`: normalization-only alternative node.
- `reference-adapter.cpp`: normalization + C4D setter behavior.
- `CMakeLists.txt`: current SDK AVX2-linked experiment (MotionSizing source TUs remain SSE2).
- `CMakeLists-sse2.txt`: original standalone-library CMake configuration.

Build with `cmake --build S:/tmp/cmt-ik-review-20261010/build --config Release`. Run the resulting `Release/sizing_audit.exe` with the full path to `stage-6.vmd` and redirect stdout to a fresh TSV. The pre-existing iteration-count review and output remain in `review.md` and `iteration-delta.txt`; its original main fixture was replaced by this later probe, so that earlier fixture source is not separately retained.
