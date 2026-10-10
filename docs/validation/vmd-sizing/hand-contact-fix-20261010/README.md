# Hand contact gesture preservation — 2026-10-10

The previous contact stage collapsed connected wrist/finger landmarks to one
point and allowed finger joints to rotate to satisfy that target. On the supplied
Sour → Afu / Stay Tonight motion, this changed a finger by 102.8247 degrees and
a palm's world orientation by 100.5575 degrees relative to the preceding stage.
Small positional residuals therefore did not imply a usable gesture.

## Changes

- Each connected contact landmark retains its source offset from the group
  centroid. Offsets scale by mean target/source palm size, with a forearm fallback.
- Finger constraints move the whole hand through its arm chain. Authored finger
  rotation tracks are not rewritten; writable wrists counter-rotate to retain
  their incoming world orientation. Fixed-axis/append-driven wrists remain unchanged.
- Local arm/wrist corrections have a 30-degree total budget per contact stage.
  The DLS line search enforces the arm budget; the acceptance search also checks
  wrist compensation and does not accept an increased positional objective.
- When avoidance is enabled, corrections cannot increase penetration beyond the
  incoming depth or tolerance at wrists, elbows, and three points per arm segment.
  Conflicting contacts retain explicit unresolved diagnostics.
- Single-character and cross-character contacts use the same goal construction
  and bounded rigid-hand solver. The SDK-independent implementation remains in libMMD.

## Data verification

Inputs are the same four files recorded in the preceding algorithm audit. The
source PMX was suggested by the user; its status as the motion author's original
model is not independently established. Frames 0–1718 were scanned. Scene scale
is 8.5; core distances below are PMX units.

| All options enabled: avoidance, wrist, fingers, floor | Previous | Corrected |
| --- | ---: | ---: |
| Maximum additional finger local rotation | 102.824738° | 0° |
| Maximum additional palm world rotation | 100.557519° | 0.000008708° |
| Wrist/elbow point–body violations | 131 | 5 |
| Maximum wrist/elbow depth | 0.348098 | 0.049384 |
| Interior arm sample–body violations | 1317 | 1107 |

These are sampled point–rigidbody pairs beyond tolerance, not mesh intersection
counts. Rotation changes are measured against the incoming Avoidance stage,
not the original source character. The corrected all-options result adjusts
hands on 86 frames; this is not a disabled/no-op contact stage.

Wrist-only contacts without avoidance resolve all 26 recorded goals on the
13 detected wrist-contact frames. With avoidance, 24/26 wrist goals remain
unresolved rather than reintroducing collisions. The all-options Contact stage
has 505 unresolved diagnostics out of 3465 (maximum residual 0.693689 PMX units).
The earlier Avoidance stage has five unresolved diagnostics. This tradeoff is
intentional: preserve the pose and expose conflicts instead of hiding them by
deforming fingers. Counts from the old and new contact objectives are not
direct measures of equivalent contact quality.

`metrics.json` contains all seven variants and selected frame measurements.
The final source gate change reproduced all 21 pre-final candidate VMDs exactly.

## Native and build evidence

- Two focused CTest targets passed, including new checks for nonzero wrist
  spacing, proportionally scaled spacing, multi-finger identity, authored curl,
  palm orientation, bounded unreachable poses, avoidance conflicts and batch
  gesture preservation. See `ctest.log`.
- SDK 2026 Release libMMD build and plugin compile/link passed. To preserve the
  running C4D, the plugin was linked with an alternate MSBuild `OutDir`, after
  building the SDK's libMMD dependency normally. The candidate has copied `res`
  and `mcp` directories. It is not a published Release or a full SDK CI matrix run.
- Existing task-owned C4D PID 54832 imported baseline/corrected exported VMDs
  through production MCP. No C4D process was restarted or closed.
- Native playback of 48 arm/wrist positions across frames 258, 313, 776 and 854
  matches the offline result at 8.5 scale within 0.000005524 scene units.
- Native viewport captures checked frames 258, 373 and 776. Left is previous
  all-options Contact; right is corrected all-options Contact. No screenshot
  pixels were synthesized or edited.
- The saved comparison scene opens on frame 258. Previous comparison files were
  not overwritten. The currently loaded plugin remains the prior binary; only
  the imported animation was changed. New in-panel solves require loading the
  separately built candidate in a subsequent C4D session.

Artifacts under `output/hand-contact-fix-20261010/`:

- `hand-contact-comparison.c4d`
- `frame-0258.png`, `frame-0373.png`, `frame-0776.png`
- `corrected-all.vmd`, `previous-all.vmd`
- `plugins/mmdtool/` (candidate plugin, resources, MCP adapter)

Hashes and runtime boundaries are recorded in `receipt.json`. The source and
native operation receipts are retained alongside this report. The scanner can
be rebuilt from this directory using `CMakeLists.txt`, after building the normal
standalone libMMD IO library; run `sizing_audit <UTF8-asset-manifest> <output-dir>`.

## Remaining limits

This fixes the destructive hand articulation, not every advanced retargeting
problem. Contacts still use bone-distance detection rather than palm/finger
surface geometry; hand shapes can differ enough that all positional constraints
cannot be satisfied while preserving articulation. There is no temporal contact
window stabilization. Existing arm-segment penetrations, mesh thickness,
cross-character collision solving, offline PMX IK, bone morphs and dynamic
physics are not solved by this change. The earlier preview/apply binding guard
failure is outside this change and has not been attributed or fixed here.
