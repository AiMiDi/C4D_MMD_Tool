> 本目录只保留结论与脚本。原始日志 / JSON / 截图 / TSV 已移出版本库，归档在 `S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\docs-validation\vmd-sizing/temporal-floor-20261012/ik`。

# Near-straight floor IK safe-region investigation

Production source was only read. No shared Constraints/Pose/IK/tests/SDK edits, shared build, C4D operation or runtime attach was performed. The probe uses a frozen current Constraints copy, the exact asset-free two-leg model from the existing floor regression, and a temporary MMDIkSolver.cpp copy with logging only. Solver settings remain exactly128iterations, original .3rad limit, original angle thresholds, and original sizing .002 tolerance. No iteration/tolerance increase was used even in the experiment.

## Result

The47→48frame jump is caused by a disconnected safe target-height set under the fixed playback IK behavior. It is not a knee-side flip, frame-history cache defect or scale/AVX configuration issue in this fixture.

| Case | GoalY | Actual ankleY | Actual ankleZ | IK error | Result |
| --- | ---: | ---: | ---: | ---: | --- |
| frame47 incoming | .244000003 | .243500710 | .000131845 | .000516408 | reference |
| frame47 full floor | .003108745 | .001304150 | .000139296 | .001809963 | accepted |
| frame48 incoming | .246000007 | .245492458 | .000134587 | .000525090 | reference |
| frame48 full floor | .006888015 | .003745556 | .000254750 | .003152768 | rejected |
| frame48 half floor | .126444011 | .120046616 | .001223207 | .006513287 | rejected |
| frame48 quarter floor | .186222009 | .184324980 | .000439465 | .001947267 | accepted |
| frame48 refined floor | .174546614 | .172083139 | .000552952 | .002524770 | accepted at original guard |

Frame48's permitted error is .000525089677+.002=.002525089677. Sweeping goal heights0..0.25 in .00025 increments finds two safe intervals: [0,.00525] and [.17475,.25]. The maximum residual is .0131468893 at goalY=.0575. More bisections cannot connect those intervals. The floor stage also correctly limits candidates between incoming goalY=.246 and requested soft-floor goalY=.006888, so the lower safe island is outside its requested displacement at frame48.

## Solver evidence

This fixture's PMX links have no axis limits; it takes SolveCore's free-link path, not SolvePlane. Hip/knee/ankle always remain in the sameYZ plane, and the knee retains negativeZ at all relevant targets. Frame47's full-floor kneeZ=-.308503866; frame48 full-floor kneeZ=-.323878348. No knee flip or pole branch change occurs.

At frame47 full-floor goal, iteration95 and later remain at .001809963 error. Iteration127 hip rotation request is1.74149009e-5rad, just below the existing1.75e-5 skip threshold; the knee request is7.40756789e-9rad. Both skip.

At frame48 full-floor goal, iteration95 error=.00387648,126=.00317357,127=.00315277. The final hip/knee angle requests3.2060e-5 and6.3727e-5 exceed the skip threshold; iteration128 is exhausted while the residual is still decreasing. At the intermediate half-step goal convergence is even slower: iteration95=.0196494 to127=.00651329. Thus the dominant rejection region is finite-iteration near-extension convergence, not an unstable sign choice or lost tiny-angle calculation.

MMDIkSolver.cpp relevant production mechanisms: Solve() iteration bound and distance stop; SolveCore() reversed chain traversal and1.75e-5 free-angle skip. The test does not establish that changing either is globally safe or desirable.

## Excluded alternatives and limits

Reused Rig and newly constructed Rig at interleaved target heights (.006888,.244,.003108745,.246,.006888) produce identical recorded goal/ankle/knee positions and residuals: maximum difference0.

Scaling every PMX bind position and target displacement by8.5, then normalizing the output back to PMX units, changes these samples by at most4.78e-7. This is far below the ~.000628 excess causing frame48 rejection. This experiment is a scale-path check, not a new C4D native acceptance or an AVX-vs-SSE build comparison.

## Maintainable floor-stage candidates

1. Keep the runtime solver unchanged, and only admit floor corrections with a bounded future release path validated against the same actual future input poses and IK/pair guards. This can conservatively prevent entry into a low-height safe island that has no bounded exit. It must operate on relative corrections, not overwrite/freeze absolute authored foot poses. A candidate from the previous frame can be used only if it passes all current-frame guards. No continuity guarantee should be made when feasible sets are genuinely disconnected.
2. Alternatively, restrict candidate selection to the safe component connected to the incoming target by sampled intermediate displacements. This sacrifices some otherwise safe full-floor landings and needs quality measurement; it is not a proven production patch.
3. A shared runtime solver change (e.g. a carefully scoped two-link seed) would have to affect both C4D and offline adapters identically and receive full solver/native regression. Merely increasing offline iterations or weakening the sizing guard would violate the current playback contract and is not recommended by this evidence.

Machine receipts: poses.csv, iterations.csv, summary.json. Reproducer: CMakeLists.txt, probe.cpp, fixture.h, IK-trace.cpp, Constraints-frozen.cpp. `iter` rows contain goalY,iteration,error,ankleXYZ and each link position/quaternion; `angle` rows record the final iterations' free-angle requests and threshold decisions.
