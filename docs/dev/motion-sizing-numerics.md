# Motion sizing: SSE2 and AVX2 numerical compatibility

The current MSVC sizing sources retain SSE2. This preserves the migration baseline; it does not establish that AVX2 arithmetic is intrinsically less accurate or that SSE2 is the physically correct answer.

## Observed comparison

The rejected AVX2 candidate used the same real-asset inputs as the pre-migration executable. See [the comparison receipt](../validation/vmd-sizing/libmmd-migration-20261010/avx2-candidate-rejected.json).

- Camera and stages 0–5 were byte-identical.
- Contact (stage 6) changed 151 of 58,330 bone keys, about 0.26%; the largest rotation difference was 0.0246359502 radians, about 1.41 degrees. Key translations and the other VMD channels were unchanged. Stage 7 retained this difference.
- The reported maximum contact residual was 0.233831232469 before and 0.233831218779 after. Both runs reported 97 unresolved constraints out of 3,794. Similar global residuals do not prove identical poses or per-constraint quality.
- Restoring SSE2 on the seven sizing translation units and matching private test consumers restored byte identity for all eight stages and the camera. See [the accepted comparison](../validation/vmd-sizing/libmmd-migration-20261010/real-assets.json).

## Supported mechanism and remaining uncertainty

`SolveGoals` in `dependency/libMMD/src/MotionSizing/Pose/MMDMotionPose.cpp` builds a Jacobian and computes a damped least-squares update:

```
step = J.transpose() * (J * J.transpose() + damping² * I).ldlt().solve(error)
```

It caps joint updates at 0.35 radians, tests up to eight line-search steps and accepts a step only if the squared residual improves by more than `1e-14`. Rejection multiplies damping by ten; acceptance halves it down to 0.001. Stopping also depends on tolerance and the iteration budget. Several joint configurations can produce similar effector positions; the objective has no explicit term preserving a particular joint pose.

Vectorization can change reduction grouping and the selected Eigen arithmetic paths. Fused multiply-add also rounds differently from a separately rounded multiply followed by an add; it can be more accurate locally. Small arithmetic differences can change a line-search decision, damping and the subsequent nonlinear solve path. Forming the normal matrix and working near an ill-conditioned configuration can increase sensitivity. These are mechanisms supported by the implementation, not a traced diagnosis of the first differing instruction in this asset.

The experiment changed the compilation context; it did not separately isolate FMA, reduction ordering, Eigen alignment/ABI or the conditioning of the first divergent solve. An alignment/ABI bug has not been demonstrated or conclusively excluded by the stage-level comparison. Do not describe the 1.41-degree difference as direct floating-point rounding error, universal AVX2 behavior, or proof of a particular hardware/compiler defect.

Before enabling AVX2 for sizing, compare uniformly compiled candidates with controlled FMA/vectorization settings, verify Eigen type sizes and alignment across translation-unit boundaries, and trace the first differing frame, goal, iteration, residual, accepted step and damping. Validate both pose deviation and per-goal residuals, together with performance. Adding pose regularization or changing acceptance thresholds would change solver behavior and needs a separate regression baseline.

References: [MSVC floating-point behavior](https://learn.microsoft.com/en-us/cpp/build/reference/fp-specify-floating-point-behavior), [Eigen vectorization and ABI macros](https://libeigen.gitlab.io/eigen/docs-3.4/TopicPreprocessorDirectives.html). The sizing source flag is independent of the existing libMMD playback AVX2 option.

## Joint validation: near-parallel playback IK

The 2026-10-10 joint validation isolated another numerical failure in the shared CCD solver. Both the free-joint and single-axis paths used `acos` of a normalized float dot product. Near parallel links can round that dot to one, losing a meaningful small rotation. Real-asset target perturbations then produced discontinuous knee positions.

The shared solver now calculates the angle from the original vectors with double products: `atan2(norm(cross(a,b)), dot(a,b))`. Rotation directions, joint limits, iteration counts and stopping thresholds retain their existing behavior. The regression checks both signs and both solver paths at three uniform scales; all twelve new residual assertions fail with the frozen old solver and pass with the fix.

The new C4D 2026 Release module and the offline library passed a selected-frame pose comparison at the user's 8.5 scale. The full report, negative control, binary identity and remaining contact limitations are in [joint validation](../validation/vmd-sizing/joint-release-20261010/README.md). This isolates the CCD failure; the earlier contact-stage AVX2 comparison remains a separate historical experiment.
