# Hand contact guard continuity review — 2026-10-12

## Reproduction and root cause

The fixture is the checked-in sizing source PMX with horizontal source wrists at Y=15, a target whose arm/elbow/wrist rest positions are 1 PMX unit higher and +/-0.8 wider, and authored center Y moving from .2 to .32 and back in .004 increments over 61 frames. Only hand floor contact at Y=15 is required.

Before this patch, SolveHandContacts first accepts one of 16 powers-of-two correction weights. At frame 14 the full candidate violates the palm compensation 30 degree local budget, so it accepts weight .5 (wrist correction .26658855 rad). At frame 15 the full candidate becomes legal (.47840646 rad), creating a .40349917 PMX position step.

A private relative-input warm-start experiment did not remove the jump (maximum step .403461 PMX). That approach was discarded. Production Pose.cpp/Pose.h have no changes, and no contact history is retained.

## Production fix

After finding the first safe power-of-two weight, refine the interval up to the previously rejected weight with 12 bisections. Each trial rebuilds from the incoming pose and runs the same palm compensation, 30 degree, weighted contact error and body penetration guards. A trial must also not increase the weighted error of the current accepted candidate. Only validated local poses are retained. Full-step successes bypass refinement. Cancellation remains checked per trial.

This targets the discrete half/full step boundary. It does not promise temporal continuity across arbitrary solver branch changes, hard collision rejection or unsupported rig transitions, and does not loosen safety tolerances or filter authored animation.

## Numeric receipt

The `receipt` directory isolates baseline/refined Constraints overrides while using the unchanged production Pose interface and same static library. Its CMake project and high_floor.cpp are the reproducer. Values use PMX units and radians.

| Metric | Frozen baseline | Refined |
| --- | ---: | ---: |
| Frame 14 to 15 wrist step | 0.403499171314 | 0.0893200356164 |
| Maximum wrist step over 61 frames | 0.403499171314 | 0.128435137071 |
| Maximum local rotation correction | 0.478406458006 | 0.523590567126 |
| Maximum palm world rotation error | 1.11392357727e-7 | 1.05976347642e-7 |
| Sum of left-wrist weighted squared error | 10.1197618801 | 1.05517990519 |
| Frame 14 weighted squared error | 0.213292135252 | 0.000259820801171 |

The maximum per-frame refined error minus baseline error is zero; likewise the maximum refined error minus incoming error is zero. Improvement is not obtained by accepting more residual. The maximum local rotation remains below pi/6 = .5235987755983.

Machine data: receipt/baseline.csv, receipt/refine.csv, receipt/metrics.json.

## Regression status and boundary

The expanded MMDMotionSizingAdvanced test covers the original and raised target, floor-only and wrist+floor, and batch paths. Every frame checks wrist step bounds, current incoming palm orientation, all-bone 30 degree local budget, and authored finger local rotation preservation. It fails against frozen baseline Constraints with `Hand floor activation or saturated correction introduced a wrist jump`; it passes with production Constraints. See advanced-baseline.log and advanced-production.log.

The first override test harness retained a temporary default-null Pose signature adapter from the warm experiment; final numeric receipt uses a clean directory and the original production signature. Parent is responsible for the official combined core build/CTest and C4D native run after integrating the parallel leg fix. No C4D was operated and no Git commit was created by this agent.

Production locations: MMDMotionConstraints.cpp around 326-377; MMDMotionSizingAdvanced.test.cpp around 741-773; docs/MotionSizing.md around 87-93. Existing earlier confidence/floor/shared-wrist patches were preserved.
