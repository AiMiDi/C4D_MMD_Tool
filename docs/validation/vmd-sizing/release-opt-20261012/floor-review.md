# Foot floor backtracking refinement — 2026-10-12

Only the foot-floor block of MMDMotionConstraints.cpp was changed. Frozen input SHA256: D91E3F1305F21E24F55A2B04E83A41DE974F2AF8BDC8A45C05760A2CAB8728BA. Final SHA256: E3FB63136828050E0284EA196DEA9558981216305006371F75FD892CB2843566. Production tests/docs were not edited by this agent; no SDK build, C4D operation or commit was performed.

## Real maximum step attribution

The previously observed .222694186 PMX extra floor-correction step is right foot 770 to 771. Source height rises .242452040 to .363677919, passing the entire .24 to .30 distance-confidence fade in one sample. At 770 confidence=.99512609 and strength=1 was accepted, with IK residual .000500392 to .001832041. At 771 confidence=0. Thus floor correction goes -.222694186 to zero, while stage5 authored foot motion rises .111892313. This is rapid crossing of a distance-only activation window, not horizontal leg avoidance, backtracking or guard rejection. This patch intentionally does not change that boundary.

## Confirmed discrete backtracking issue and minimal fix

The two-leg advanced fixture raises both foot controls from Y=.15 to .35 in .002 increments (101 frames). Inside the stable IK branch, frames55..63 show power-of-two floor weights switching between quarter and half. Maximum adjacent target step was .0402708203 despite .002 authored steps. After finding the first safe weight, the patch bisects the prior rejected/safe bracket up to12 times, retaining all existing per-pair collision and IK-target error guards. It also requires actual ankle-to-floor-goal squared residual not to exceed the previously accepted candidate. The final stored weight has already been validated.

Stable-window maximum target step becomes .00328847766. The entire101frame sweep is checked for original IK tolerance, pair safety and no horizontal correction. Maximum IK-error increase is .00199991568 <= .002 tolerance.

The independent near-straight IK branch switch at47→48 remains: .183113257 before versus .171437869 after. That event is not disguised by selecting a continuity metric: the regression explicitly checks55..63 for the discrete staircase and all101frames for safety. A guard transition is not a general temporal-continuity guarantee.

## Validation

- `advanced_baseline.exe` with the new test and frozenD91E Constraints exits1: Discrete floor backtracking introduced a stair step.
- `advanced_refine.exe` with identical tests and the new Constraints passes the full advanced suite.
- Integration-ready test body: `floor-regression-snippet.cpp`. The parent can insert this in CheckLegPlaybackAndAvoidance before the existing leg_ik_depth report.
- Replayed Contact on the same frozen real all-leg stage5 for1719frames, bothfeet3438samples. Final refinement changes51samples. The earlier experimental unconstrained ankle-error refinement changed70; final evidence and production use51.
- All real per-pair excess above max(inputDepth,tolerance):0. Horizontal foot correction:0. Maximum IK error increase .00999994304 <= .01 original tolerance.
- All non-foot VMD bone records are byte-identical between baseline/refined outputs. Finger local delta0 and palm world delta2.13456e-7rad remain the same as baseline. This compares Contact against stage5, not Avoidance against stage4; the separate Avoid palm issue belongs to the parent task.
- The real maximum floor-correction step stays .222694186 as explained above.
- git diff --check passed.

Reproduction tools and raw data are in this directory: CMakeLists.txt, synthetic*.cpp, real*.cpp, Constraints-baseline.cpp, Constraints-refine.cpp, synthetic-{baseline,refine}.csv, real-{baseline,refine}.csv/.vmd, advanced-{baseline,refine}.log, real-*-guards.txt and metrics.json. Real input paths come from S:/tmp/cmt-sizing-migration-assets.txt, with frozen stage5 at S:/tmp/cmt-sizing-continuity-20261012/real-after/all-leg/stage-5.vmd. Temporary executables link the existing SSE2 standalone core with the explicit Constraints override; parent owns final combined core/SDK/native verification.
