# Contact activation review and bounded correction (2026-10-12)

Base: CMT main 64c8cada, libMMD 577c46d. Production changes are on the parent-owned codex/sizing-followup-20261012 branch. This subagent edited only the approved Constraints.cpp, advanced regression test, and MotionSizing.md. No commit, C4D operation, or full real-motion solve was performed by this subagent.

## Reproduced quality gap

This is a quantified consequence of the previously documented per-frame distance heuristic, not an undisclosed new feature claim. Source motion changes its left upper-arm angle by only 0.002 radians/frame. When wrist distance crosses the default 0.3 PMX contact threshold, the old solve drops a 23.455-degree arm correction in one frame.

- Smooth exit (frame 53 to 54): source/input wrist step 0.0056567 PMX; old adjusted step 0.781893 PMX (6.646 scene units at 8.5), final adjusted step 0.0056567 PMX.
- Boundary oscillation: source gap alternates 0.2999942267 / 0.3000056638. Input step is 0.0000114533 PMX; old adjusted step is 0.785515 PMX; final adjusted step equals input.
- Across the full smooth exit, maximum output step falls from 0.781893 to 0.122199 PMX. The fade introduces gradual movement; it does not promise constant velocity.

The fixture derives from the existing advanced wrist-contact fixture and uses the checked-in source.pmx. contact_threshold.cpp and the before/final CSV files reproduce these measurements. No external model is required.

## Changes

1. Smoothstep distance confidence over the final 20% of the configured contact distance. Below 80% influence remains full. At a zero threshold only exactly coincident landmarks qualify.
2. Anchored weighted contact graph for single and batch use. Pair-local palm-scaled offsets replace abrupt connected-component centroid merges. A vanishing weak edge neither relocates an existing strong group nor disables its strong edges. Three-plus points with different hand scales are reconciled by weighted least squares, as now documented.
3. Smooth hand and foot floor activation, including blended hand-floor/contact goals. A newly appearing weak constraint no longer immediately receives half the weight of an existing strong constraint.
4. Foot floor displacement performs up to eight successively halved candidate steps before reverting. Every step retains the original per-pair collision and foot IK error guards; neither tolerance nor acceptance condition is relaxed. Diagnostics still measure actual ankle position against the desired goal.

The 30-degree local correction budget, finger-curl preservation, world palm orientation, arm collision rollback, foot/leg protection and authored-rotation preservation remain intact.

## Verification

Official standalone Release CTest: mmd_motion_sizing_test, mmd_motion_sizing_advanced_test, mmd_ik_solver_test all pass. The advanced runner now covers single/batch entry and exit, threshold oscillation, a third-character weak bridge to a strong pair, zero contact distance, hand-floor (alone and combined with wrist contact), foot-floor entry/exit, and an IK-rejected full floor step retaining a smaller safe correction. Existing gesture/collision/IK tests remain in the same run. Full receipts are in focused-tests.log.

A negative-control executable compiles a frozen Constraints.cpp from 577c46d against the current regression cases, counting assertions instead of stopping after the first failure. Only the new categories fail:

- Contact threshold wrist jump: 306 assertions.
- Foot floor activation jump: 2 assertions.
- Hand floor activation jump: 4 assertions.
- Retaining a smaller safe floor correction: 1 assertion.

This negative control intentionally reports counts, so its process exit status is not the pass criterion. See negative-control.txt and prepare_negative.py. Existing assertions pass.

Build and run:

```powershell
cmake --build C:/code/C4D_MMD_Tool/_build_msvc/libmmd-sizing-standalone --config Release --target mmd_motion_sizing_advanced_test mmd_motion_sizing_test mmd_ik_solver_test
ctest --test-dir C:/code/C4D_MMD_Tool/_build_msvc/libmmd-sizing-standalone -C Release -R 'mmd_motion_sizing|mmd_ik_solver' --output-on-failure
cmake --build S:/tmp/cmt-sizing-review-20261012/build --config Release --target contact_threshold advanced_negative
S:/tmp/cmt-sizing-review-20261012/build/Release/contact_threshold.exe
S:/tmp/cmt-sizing-review-20261012/build/Release/contact_threshold.exe jitter
S:/tmp/cmt-sizing-review-20261012/build/Release/advanced_negative.exe C:/code/C4D_MMD_Tool/dependency/libMMD/tests/fixtures/vmd-sizing C:/code/C4D_MMD_Tool/dependency/libMMD/tests/fixtures/vmd-sizing-advanced
```

contact-review-summary.json contains metrics and hashes of the three production files at handoff. Earlier confidence-experiment files are private prototypes, not the implemented weighted graph.

## Remaining boundary

This change smooths constraint activation in distance space; it is not a temporal contact-window tracker. Large unreachable floor targets at a nearly saturated 30-degree hand correction budget can still switch solver branches, and collision/IK rejection can still change the accepted amount. During test development, the existing one-unit-raised hand fixture additionally raised by 0.2 to 0.32 PMX showed a roughly 0.40 PMX step inside the fade band when the bounded nonlinear solve changed branch. The hand-floor activation regression therefore isolates a reachable target, while existing unreachable/budget tests retain the safety boundary. Do not claim all per-frame jumps or physical/mesh collisions have been solved.

The parent agent owns full Sour-to-Afu scans, SDK builds, native acceptance and the release decision.

## Final-review follow-up: confidence through shared wrist aggregation

An independent review found a remaining discontinuity in the first weighted-graph revision: ContactGoals carried only positions, so a weak newly active fingertip received an equal vote in SolveHandContacts. Its negligible desired displacement could halve another strong landmark's wrist correction. Equal-weight acceptance also let the weak point veto the strong correction.

The final source uses a private ContactTarget containing position and confidence. The maximum incident edge confidence reaches the shared-wrist weighted mean and the weighted acceptance error. Floor blends update the same point confidence. Public API and existing rotation, palm, finger, collision and IK protections are unchanged.

New tests isolate strong wrist plus weak finger, and strong finger plus weak finger, each in single and batch mode, with no obstacle and reachable arm targets. The weak source landmark moves only 0.00002 PMX across the contact boundary while source wrists remain stationary. Additional tests introduce a weak finger-floor target on a hand that already has a strong contact. In the batch strong-finger case, wrists remain outside contact detection, so wrist edges cannot mask the finger-only condition.

Frozen previous weighted-graph revision versus final revision:

| Case | Previous wrist jump (PMX) | Final wrist jump (PMX) |
|---|---:|---:|
| Strong wrist / weak finger, single | 0.400386 | 0.000000197215 |
| Strong wrist / weak floor, single | 0.199616 | 0 |
| Strong wrist / weak finger, batch actors | 0.200383 / 0.199616 | 0 / 0 |
| Strong finger / weak finger, single | 0.400386 | 0.000000197215 |
| Strong finger / weak floor, single | 0.0666465 | 0 |
| Strong finger / weak finger, batch actors | 0.200383 / 0.199616 | 0 / 0 |

The previous revision fails eight jump assertions, two strong single-contact assertions and two strong batch-contact assertions. The final revision fails none. Official Release focused CTest again passes all three runners. Receipts are shared-wrist-before.txt, shared-wrist-after.txt, shared-wrist-focused-tests.log; current production hashes and ordered measurements are in shared-wrist-summary.json. This summary supersedes the earlier contact-review-summary.json source hashes. Constraints-before-point-confidence.cpp is the exact frozen pre-fix control.

Reproduction targets: shared_wrist_before and shared_wrist_after in the independent temporary CMake project. Both run with the checked-in base and advanced fixture directories. The instrumented temporary test copy counts failures; use printed failure counts rather than its process exit status as the negative-control criterion.
