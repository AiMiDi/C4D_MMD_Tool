## 1. Presentation and model controls

- [x] 1.1 Implement model-proportional shapes, palette and visual-only refresh; verify pose and track preservation.
- [x] 1.2 Add model-level generation, selection, display, size and occlusion settings in both resource layouts; verify defaults and persistence.
- [x] 1.3 Add restrained occluded outlines; inspect before/after native views and selection behavior.

## 2. Acceptance

- [x] 2.1 Build SDK 2026 and R20 Release and run native controller checks with the supplied model.
- [x] 2.2 Recheck PSR driving, save reviewable scenes/screenshots/receipts and document the workflow.

Evidence: `output/controller-design-20261008/receipt.json`, 27 native controller checks and 90 native PMX PSR checks pass in C4D 2026.4. R20 has compile evidence only. Same-camera wrist screenshots record through-mesh on/off; native picking retains C4D's selection behavior (not every occluded control becomes the first hit).

## 3. Lower-body controls and delivery

- [x] 3.1 Add anatomical leg/foot, IK target and IK parent eligibility and distinct shapes; test aliases and duplicate exclusion.
- [x] 3.2 Validate native FK ownership, IK/toe/parent motion, neutral recovery, tracks, refresh and reload on Afu, including VMD.
- [x] 3.3 Rebuild all packaged Windows SDKs, verify the installer artifact, sync/archive both session changes and commit the completed source.

Final delivery: see `docs/dev/controllers-acceptance-20261008.md` and its committed JSON receipt. All eight Windows SDK Release builds pass; 252 lower-body, 27 presentation and 180 native PSR checks pass. Private installer lifecycle verifies 869 actual Release files. Local 0.9.2.3 Windows package; no public release.
