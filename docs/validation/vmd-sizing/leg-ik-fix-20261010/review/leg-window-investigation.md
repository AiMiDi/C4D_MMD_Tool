# Remaining leg collision investigation — 2026-10-10

This is an isolated numerical investigation. No shared repository source files were changed, no commits were made, and no C4D process or document was operated. The code under `MotionSizing/` is a copied snapshot for instrumentation, not a proposed production replacement.

## Confirmed cause at frame 589

The production input is `leg-verified-results/all/stage-4.vmd`, with the same target PMX listed in `S:/tmp/cmt-sizing-migration-assets.txt`. This is the pre-constraint motion; the experiment isolates the leg pass and excludes subsequent hand/floor contact effects. Default margin is 0.05 PMX units. The 8% per-foot correction budget is 0.752697449 PMX units.

The first solve pass finds an admissible improvement at frame 589: maximum capsule penetration decreases from 1.196555429 to 0.57548. Its left/right Z corrections are approximately +0.751106/-0.752440. At frame 590 the solver selects the opposite correction direction, -0.741378/+0.505514.

The nine-frame triangular filter averages these opposite directions. At frame 589 the filtered correction has left/right Z of only +0.041396/-0.071119, and increases penetration to 1.25899. Every tested halving also increases penetration; the final acceptance guard correctly rejects the result and restores the original frame. This directly explains the final unchanged depth of 1.19656.

Thus this frame is **not proven geometrically unsolvable inside the current budget**. A useful bounded solution exists, but independent correction-direction choices and subsequent filtering cancel it. This is a branch in the correction search; no anatomical knee-bend branch reversal has been established by this experiment.

See `probe.txt` lines beginning `RAW` and `SMOOTH`; `probe2.txt` repeats these observations.

## Feasible-domain sampling

20,000 deterministic random planar correction candidates per frame were evaluated with each foot constrained to the same 8% radius. These values are sample minima, not proven global minima:

| Frame | Input max penetration | Minimum sampled penetration |
| --- | ---: | ---: |
| 258 | 1.035726 | 0.183393 |
| 588 | 1.126097 | 0.327541 |
| 589 | 1.196555 | 0.554764 |
| 590 | 1.097347 | 0.275366 |
| 591 | 1.071042 | 0.085656 |
| 592 | 1.137161 | 0.058118 |
| 593 | 1.187460 | 0.009824 |

Independent minima do not imply a usable continuous animation. Some improve collisions while worsening ankle-to-foot-IK-goal residual. The random-search section also logs penetration along the line from zero to the selected candidate.

## Bounded temporal path prototype

The second experiment evaluates 321 symmetric planar correction candidates per frame over frames 580–603: zero plus 64 directions at five radial levels. Dynamic programming selects a path using penetration-squared, displacement and transition costs. Constraints are:

- Existing per-foot displacement budget 0.752697449.
- Correction change per foot per frame no greater than 0.25 PMX units.
- Per-frame maximum penetration no greater than the unmodified input.
- Both ankle-to-foot-IK residuals no greater than their same-frame input value plus 0.005 PMX units.
- Zero correction at the final frame; the path starts from zero.

For this sampled candidate set, the selected path gives:

| Metric | Result |
| --- | ---: |
| Window maximum penetration before | 1.196555429 |
| Window maximum penetration after | 0.837456430 |
| Frame 589 after | 0.574912016 |
| Frame 593 after | 0.495162472 |
| Maximum correction step | 0.248384984 |
| Maximum per-foot displacement | 0.752697449 |

This shows a concrete improvement without increasing either the original displacement budget or a conservative correction-step cap. It also exposes a tradeoff: frame 593 is worse than the current filtered solver's 0.356294, in return for retaining a consistent direction across the difficult interval. It does not eliminate the remaining collision, prove visual quality, or guarantee acceleration continuity. The goal-residual constraint also is not a full foot-plant or orientation constraint.

`path-search.json` contains all selected samples for three goal-residual guard variants (`None`, `0.02`, `0.005`). `candidates.tsv` contains the complete evaluated candidate set. `path_search.py` reproduces path selection. The path is currently data only; **it is not baked into a VMD or verified in C4D**. The `prototype.vmd` file is the unchanged production leg algorithm rerun with instrumentation, not this dynamic-programming path.

## Additional issue: goal tracking is not part of current acceptance

The existing solver accepts candidates based on collision depth and correction size, but not ankle-to-IK-goal error. On frame 590 the left ankle's residual grows from 0.169392379 to 0.209793486 PMX units after the current filtered leg pass. At frame 593 it grows from 0.218182783 to 0.241938194. These are isolated pre-floor-pass measurements.

There is already a substantial residual before avoidance (for example 0.203069 at frame 589), so this is not all caused by the new feature. In the inspected frames the straight-line hip-to-goal distance does not exceed total leg length; simple outer reach is therefore not the explanation. Joint limits, authored rotations, solver stopping behavior and inner reach remain possible contributors and have not been individually isolated. Agreement with the C4D player proves parity with its solver, not exact target satisfaction.

A minimal synthetic reproduction is available in `fixture-probe.cpp`, using the same two-leg model as `CheckLegPlaybackAndAvoidance`. Set both IK controllers to 4 iterations (angle limit 0.3), foot translations to `(opposite 0.65, 0.1, 0)`, and sizing tolerance to 0.002. Both feet's residuals rise from 0.0718279 to 0.0845943. With foot Z translation 1, they rise from 0.0105114 to 0.0230424. These fail a per-foot `after <= before + options.tolerance` assertion. See `fixture.txt` for the small parameter sweep. This fixture requires no external model assets and is appropriate for the newly requested acceptance guard regression.

## Recommendation

Do not remove the no-worse-collision guard or disable temporal filtering merely to improve a collision counter. Do not merge this prototype into the current release without complete-motion, floor-contact and native playback verification.

For a follow-up change:

1. Add per-foot goal residual to candidate evaluation and diagnostics. Preserve or improve baseline tracking within a specified tolerance, rather than assuming IK always reaches its goal.
2. Group crossing intervals with a small entry/exit context window. Generate several bounded correction-direction candidates and choose a temporally consistent path before continuous local refinement. This addresses the demonstrated direction cancellation directly.
3. Retain displacement and collision guards, and add speed/acceleration terms or limits. Evaluate ground contact in the same acceptance logic so a later floor snap cannot invalidate the chosen path.
4. Validate all 1719 frames, both foot orientation and position, unmodified finger channels, existing hand collision metrics, repeat/reverse sampling, and C4D playback. Include failure examples; a numerical reduction alone is insufficient acceptance.

## Reproduction

```powershell
cmake -S S:/tmp/cmt-leg-followup-20261010 -B S:/tmp/cmt-leg-followup-20261010/build -G 'Visual Studio 18 2026' -A x64
cmake --build S:/tmp/cmt-leg-followup-20261010/build --config Release
S:/tmp/cmt-leg-followup-20261010/build/Release/leg_probe.exe
python -X utf8 S:/tmp/cmt-leg-followup-20261010/path_search.py
```

For the synthetic sweep, configure a separate build directory with `-DPROBE_SOURCE=S:/tmp/cmt-leg-followup-20261010/fixture-probe.cpp`.

The probe links the current built libMMD IK implementation and copied motion-sizing sources. Model assets remain outside the repository. The result is scoped to this local source/build snapshot and the supplied asset manifest.
