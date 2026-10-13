# Hand contact accuracy follow-up — 2026-10-13

## Change

libMMD commit: `6f2d24c6a7ee6d250ef2f09494d0f4de3e31a9f1` (base `ba770f2f154d702605123148a59fe8655661b6cf`).
The plugin used for native validation was built from the clean CMT `0ddf5ddfc80d8e7c78fae0df23f88683e16e31b4` source archive and the new library. Unrelated changes in the shared checkout were excluded.

The previous common backtracking weight could suppress one arm's otherwise legal correction when the other arm reached its palm compensation or collision limit. After the existing joint solve, an additional bounded search can improve independent arms. It retains the previous accepted pose as fallback and preserves:

- Each hand's original confidence-weighted positional error.
- Every original active contact pair's source-scaled relative offset error.
- Original palm orientation, authored finger articulation and the original 30-degree local correction budget.
- Both the incoming and latest accepted collision bounds for wrist, elbow and sampled arm segments.

Parent/append-coupled arms are excluded from this independent search. Batch contact retains the old path; this change is limited to single-character contact. It does not add time smoothing, reduce contact confidence, change the collision margin, or introduce physics simulation.

## Verification

- Release/AVX2 root dependency aggregate: 17 functional tests passed. Sizing remains compiled with its existing SSE2/Eigen configuration.
- Focused advanced and serial/parallel tests passed again after the final fixtures and mutation restoration.
- 40 mirrored asymmetric-arm cases verify that a constrained hand no longer discards a legal correction on the other arm. A representative old free-hand error of `0.491650` dropped below `0.002` while preserving the other hand, palms and finger rotations.
- Two wrist-following collider cases start without penetration, exhibit an unsafe complete correction with depth `0.2`, and keep the actual result within the fixture tolerance `0.002`.
- Two active wrist-pair cases verify relative contact protection. Removing just the new pair guard changes the gap from approximately `0.159078` to `0.482432` and fails the intended assertion. Removing just the new collision guard also fails its intended penetration assertion. Both source restorations were hash-checked and the tests passed afterward.
- Sour Black → Afu, Stay Tonight, 1719 frames: raw-PMX CLI exports for all eight stages and camera remain byte-identical to the released baseline. One/four-worker exports and Analysis also match exactly.
- New DLL SHA256: `7EA929A168D3214BE914FE9FC0CAFCCF751379D2872D3F764973C814E8886F46`. Its path was verified in the task-owned Windows Cinema 4D 2026.4 process. The user's separate C4D session was preserved.
- Native production MCP calculation, export and application passed at scene scale 8.5. One/four-worker motion and camera exports are identical; 13 sampled frames × 625 bones have zero matrix difference. Samples include frame 500 and the contact investigation frames.

Native C4D exports the model's bind snapshot rather than using the raw PMX directly. On this snapshot the new search makes a very small, deterministic change to 22 rotation keys at frames 374, 375, 774 and 775 (maximum quaternion component difference `1.33886933327e-5`). An independent C++ probe reproduces all 22 old keys exactly with the old path, and all 22 new keys exactly with the new path, using the same snapshot and incoming stage. Original target errors improve slightly; this is not a claim of visible improvement in the sample motion.

## Real-motion residual diagnosis

All quantities below are PMX units before multiplying by scene scale 8.5.

The original active contact pairs were audited without lowering their confidence or changing source offsets. A fixed-palm/finger-shape translation analysis separates incompatible hand geometry from failure to reach a goal. It is a lower bound without arm reach or collision constraints, not proof of a reachable pose.

- At frame 1072, the weighted pair RMS lower bound is `0.144335`, versus actual `0.146092`; most remaining error there is incompatible hand geometry under the current palm/finger preservation rules.
- Frames 1057–1065 account for approximately 76.41% of this clip's confidence-weighted squared pair error. At frames 1058, 1062 and 1064, the complete position solver reaches its wrist goals within `0.000332`, with chain corrections below 10 degrees. The candidate is rejected because wrist samples enter the opposite forearm capsule or hand box. The accepted common weights are approximately 1.48%, 0.74% and 2.41%.
- Source and target proxies differ: source forearm capsule radius `0.30` versus target `0.45`; the source wrist has a thin capsule, whereas the target uses a larger hand box. The source motion itself overlaps the source forearm proxies at these poses, even with zero added margin. Proxy overlap does not by itself prove visible mesh penetration.
- Per frame, 208 common-translation candidates and another 390 partial-correction/common-translation candidates did not produce a strict improvement satisfying all existing collision, rotation, per-hand and per-pair conditions for those three frames. This finite search does not prove that no feasible pose exists. Candidates improving relative contact while worsening original absolute goals were rejected.

The major visible residual in this sample therefore remains unresolved under the current proxy constraints. No collision guard was relaxed to make the numerical result look better. Mesh/clothing collision, subframe motion quality, other C4D hosts and macOS native runtime were not validated by this change. Shared-ancestor/append exclusions have source review but no dedicated mutation fixture yet.

## Rejected approach and evidence

A temporal confidence-envelope experiment reduced correction jumps but weakened actual contact (for example frame 128's selected gap rose from about `0.0062` to `0.0600`). It was removed before this commit. The archive retains the rejected patch and measurements to prevent treating a lower correction-jump metric as proof of better motion.

Local evidence: `output/contact-quality-20261013/`. It contains core/focused logs, pair/collision mutation receipts, raw-PMX stage exports, native receipts and sampled poses, plus `real-quality-limits/`, `real-solver-debug/` and the separate unimplemented `wrist-budget/` investigation. Licensed PMX/VMD inputs and native scene files remain local and are not included in this documentation commit.
