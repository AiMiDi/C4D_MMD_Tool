# Changelog

[中文](CHANGELOG_zh.md) · [README](README.md)

Entries for 0.9.1.x were reconstructed from tagged source changes and release dates. Intermediate build tags are grouped below; original entries through 0.4.6.1 are retained.

### 0.9.3.5 · Motion adaptation fixes and controller workflow (2026-10-10)

Published as [v0.9.3.5](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.3.5) after joint native validation, release CI and package verification. [Validation record](docs/validation/vmd-sizing/joint-release-20261010/README.md).

1. Fix destructive wrist/finger contact adjustments while preserving finger curls, palm orientation and source contact relationships.
2. Reuse playback IK for offline poses, including PMX link limits, iteration counts and VMD IK switches; skip driven channels that cannot accept direct animation.
3. Add optional leg self-collision avoidance with foot IK target protection, temporal filtering and rollback for conflicting floor constraints.
4. Add C4D status-bar progress and cancellation feedback for long calculations, with shared MCP and panel options.
5. Document motion adaptation, wrist/leg effect comparisons and the reference project.
6. Fix false PMX binding expiry, uninitialized vertex data, QDEF weight IO and side effects in playback IK global-cache updates.
7. Add body groups, part isolation, arm IK, knee direction controls, matched FK/IK switching, controller keyframes and Undo.
8. Reduce widget sizes and fix model scale being applied twice to hand targets; preserve animation inputs when refreshing their display.
9. Stabilize small IK angles near parallel links to reduce knee-pose jumps caused by tiny input differences.

Inspect complex contacts in the stage preview. [Validation and known limits](docs/validation/vmd-sizing/leg-ik-fix-20261010/README.md)

### 0.9.3.3 · VMD motion adaptation (2026-10-10)

1. Add staged VMD motion adaptation with body-scale and movement offsets, stance and twist adjustment, rigid-shape avoidance, contact constraints, multi-character processing and camera fitting.
2. Add a localized C4D panel with scene-model selection, existing animation-slot input, before/after stage previews, queued characters and apply/export controls.
3. Add typed production MCP motion-sizing tools with asynchronous jobs, cancellation, preview, apply/export and shared panel state.
4. Move reusable calculation into libMMD under `libmmd::sizing`, independent of the C4D SDK, with public APIs, regression fixtures and documented solver limits.
5. Fix R20 source processing, R21 STL compatibility and pre-2026 LinkBox API support. Preserve SSE2 compilation for sizing to keep the validated numerical baseline.

Validation: 21 SDK/platform builds, 41 MCP tests, 15 libMMD tests and 24 plugin tests passed. Native acceptance of the latest menu placement, MCP/dialog synchronization and queue interactions remains pending. Avoidance uses rigid-shape sample constraints rather than whole-mesh collision guarantees; macOS and older-host runtime behavior remain unverified. Published macOS ZIPs are Intel builds.

[Changes since 0.9.3.2](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.3.2...v0.9.3.3) · [Validation record](docs/validation/vmd-sizing/submission-ci-20261010/README.md) · [Numerical compatibility](docs/dev/motion-sizing-numerics.md)

### 0.9.3.2 · Controller placement and hover names (2026-10-09)

1. Fix eye controller placement on fresh PMX import; align the shared eye outline with the actual eye pair while retaining its authored rotation pivot and model scale.
2. Show the bone name when hovering a generated controller outline, using the selected local or English naming mode. Hidden controls and disabled spline display do not produce hints.
3. Remove direction triangles from rotation rings and ovals; retain shoulder leaders, hand wire boxes and toe IK triangles.
4. Hide generated controllers in Edit mode and restore Primary/All/Hidden settings in Animation mode. Preserve existing controller transforms and animation tracks when refreshing.
5. Avoid transient GitLab Eigen checkout failures in CI by using a mirror of the same pinned commit and bounded checkout retries.

[Changes since 0.9.3.0](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.3.0...v0.9.3.2) · [Validation scope](docs/dev/controllers-eye-hover-20261009.md)

### 0.9.3.0 · MMD controller hierarchy and silhouettes (2026-10-09)

1. Support native PSR position/rotation constraints on imported MMD bones, including IK target motion and direct FK ownership. Stabilize repeated evaluation and retain registered FK poses.
2. Add leg, knee, ankle, toe, foot IK and IK-parent controllers, plus root, center, groove, waist, torso, neck and head controls.
3. Give shoulders, wrists, eyes, central bones and IK goals distinct silhouettes and consistent left/right colors. Reduce auxiliary/twist controls and exclude them from Primary display.
4. Add model-level controller generation, visible-control selection, Primary/All/Hidden display, proportional sizing and continuous outlines through meshes.
5. Preserve controller identities, transforms, animation tracks, links and bind poses when refreshing, changing size or saving and reopening.

[Changes since 0.9.2.2](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.2.2...v0.9.3.0) · [Controller acceptance](docs/dev/controllers-acceptance-20261008.md)

### 0.9.2.3 · MMD controllers (2026-10-08)

1. Support native PSR position/rotation constraints on imported MMD bones, including IK target motion and direct FK ownership.
2. Add leg, knee, ankle, toe, foot IK, toe IK and IK-parent controllers. Stabilize repeated evaluation and preserve registered FK poses.
3. Redesign control silhouettes and left/right colors, with continuous outlines through meshes. Add model-level generation, selection, Primary/All/Hidden display and size settings.
4. Preserve existing control transforms, links, animation tracks and bind pose when refreshing the presentation.

Validation scope and Windows package receipts: [controller acceptance](docs/dev/controllers-acceptance-20261008.md).

### 0.9.2.2 · Architecture, Morph and materials (2026-10-08)

Changes since `v0.9.1.20`, grouped by module:

1. **Model runtime and bones:** Split IK/physics rebuilding, frame evaluation, Morph evaluation and material conversion into dedicated modules. Clarify EDIT / ANIM bind-pose transitions and rebuild after reopening, cloning and animation-slot changes. Synchronize hierarchy/index changes, cache layered execution plans and restore stored bone display settings.
2. **Motion and camera:** Complete VMD append, replace, merge and channel options, with per-slot Morph animation, IK switches and visibility. Improve baked export, scale conversion and source-state restoration. Correct camera vertical field of view and unit conversion, migrate legacy tracks and fix export success reporting and temporary-object cleanup.
3. **Morph and persistence:** Classify UV/Additional UV Morphs separately and preserve their PMX offsets. Persist impulse offsets and expression panels. Consolidate Group/Flip expansion and mixed preview. Repair stale mesh-tag references and derived-cache serialization so Undo/Redo followed by immediate save/reopen can rebuild safely.
4. **Material Morph:** Add versioned Standard shader and fixed Redshift node bindings. Keep texture Multiply/Add RGBA factors separate, evaluate them after sampling and separate factor Alpha from image opacity. Add mixed preview, reset, support diagnostics, explicit upgrade/repair and independent material copies, with transactional Undo/Redo and ownership checks.
5. **Standard and Redshift materials:** Add MMD-style RS Toon conversion using native Toon/Contour nodes, including main-texture transparency, Toon fallback, stylized specular, outlines and Sphere Multiply/Add. Improve Standard Sphere rendering and ordinary RS specular color/Power conversion and reverse synchronization. Preserve user connections and sampler color-space choices.
6. **PMX export:** Apply length scaling consistently, enforce PMX 2.0/2.1 softbody serialization boundaries and improve write-failure cleanup while preserving source-scene state.
7. **Production MCP:** Add 16 typed tools and a stdio adapter for inspection, PMX/VMD import/export, animation slots, modes, physics, Morphs and frame evaluation, including `redshift_toon` import. Host integration requires Cinema 4D 2026.4 or later. Windows acceptance includes real operations, timeout recovery and host restart; see the [acceptance record](docs/dev/mcp-acceptance-20261008.md).
8. **Build, packaging and documentation:** Share source, resources and CMake setup across SDKs, with explicit Debug/Release/test presets and real runtime resource copies. Package Windows x64 for R20–2026 and separate macOS Intel ZIPs by compatible C4D version. Include platform/architecture/version in artifact names, expand regression tooling and refresh development guides and feature screenshots.

**Compatibility and limits:** RS Toon needs the required native Redshift nodes; unsupported hosts report the reason. Material Morph binding v1 requires an explicit upgrade to v2; older Toon graph revisions require explicit conversion. Toon lighting/specular and some outlines remain approximations; native MMD image equivalence is unverified. macOS/older-host runtime execution and full real-model physics replay remain unverified. Published macOS assets are Intel builds; Apple Silicon builds are CI validation only.

### 0.9.1.20 (2026-07-15)

1. Add PMX Material Morph import, authoring, persistence and export, including material fields, texture factors and Standard material preview.
2. Add VPD pose import/export controls, including current-pose export.
3. Fix repeated VMD Morph evaluation accumulating deformation and stabilize PMX bone EDIT / ANIM transitions.
4. Improve macOS builds, pin Windows CI to VS 2022, package macOS Intel binaries and add separate Apple Silicon build validation.
5. Synchronize SDK resource layouts for release builds, including the missing SDK 2025 Material Morph resources.

[Release](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.1.20) · [Changes since 0.9.1.15](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.1.15...v0.9.1.20)

### 0.9.1.15 · Pre-release (2026-05-23)

1. Add PMX model export for plugin-managed models, with selectable mesh, normals, UV, material, bone, weight, IK, inheritance and Morph data.
2. Add MMD bone control objects for editing poses on imported models.
3. Restore PMX export compilation on older SDKs and fix Clang compatibility for bone indices and SDK interfaces.
4. Repair dependency/submodule checkout and pin reachable Bullet/libMMD dependencies.
5. Package macOS builds as Intel x86_64 and constrain the Xcode build architecture accordingly.

[Release](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.1.15) · [Changes since 0.9.1.3](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.1.3...v0.9.1.15)

### 0.9.1.3 · Pre-release (2026-05-15)

1. Refine model EDIT / ANIM transitions: commit edited bone bind transforms when entering animation and restore bind state when returning to editing.
2. Coordinate bone, mesh, rigid-body and joint modes, clear transient Morph/physics state and rebuild runtime managers at mode boundaries.
3. Persist Morph animation by slot so switching animation slots preserves their authored tracks.
4. Adjust physics reset behavior and fix VMD camera import.

[Release](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.1.3) · [Changes since 0.9.1.2](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.1.2...v0.9.1.3)

### 0.9.1.2 · Pre-release (2026-04-29)

This entry consolidates the source refactor and features added after 0.4.6.1, including the 0.9.1.0 / 0.9.1.1 build tags.

1. Reorganize PMX/VMD import around Model, Bone, Mesh, Rigid and Joint managers, with libMMD animation, IK and Bullet physics integration.
2. Add SDK support through Cinema 4D 2026 and a shared CMake build/dependency layer, with Windows and macOS build/package workflows.
3. Expand PMX parameter import, editable display frames, bone Morph data and UV Morph classification; repair multipart mesh/weight import and Morph persistence.
4. Add a persistent MMD material manager with texture-path editing and renderer conversion options for Standard, Redshift, Octane and Corona.
5. Add IK solver controls and rebuild runtime state after loading scenes; improve rigid-body/joint transforms, physics reset and mode synchronization.
6. Introduce C4D-track-based VMD bone and Morph animation, improve interpolation and animation persistence, and refine motion import/export reporting.
7. Rework VMD camera import, conversion and export using libMMD camera animation.
8. Replace YAML settings with lightweight JSON and repair Windows Inno Setup invocation and packaging triggers.

[Release](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.1.2) · [Changes since 0.4.6.1](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.4.6.1...v0.9.1.2)

### 0.4.6.1

1. Fixed the crash that caused 0.4.6.

   2. Support S26.

### 0.4.6

1. A new expression hub panel is added to manage all expressions.

2. Added support and editing for group and flip expressions.

3. Motion import adds the option to ignore physical bones.

4. New icon.（The logo icon is temporary and the logo icon may be changed again）

### 0.4.5.1

Fixed import model surface error.

### 0.4.5

1. Fixed an issue where saved documents could not be opened.
2. Optimize the IK of the imported model.
3. Add import model report.
4. Optimize import speed and stability.
5. Fixed import normal inversion problem for versions below R23.

### 0.4.4.1

Fix import normal inversion issue.

### 0.4.4

1. Fix the problem of vertex expression loss of partial vertices imported by multiple parts.
2. Fix the problem that the model cannot be imported when the external parent is opened.
3. Compatible with projects saved by older versions. (some information may be lost, but it does not affect the opening of the project)

### 0.4.3

1. Fixed multi-part import import weights not initializing bones.

2. Improved weight import.

3. Fix import failure caused by empty IK list.

### 0.4.2

1. Add import pose.

2. Improve the function of PMX Control.

3. Support R25.

### 0.4.1

1. Add camera bake export.

2. Add motion bake export.

3. Improve Ik.

### 0.4

1. Add the action export function

2. Fix the action confusion problem after importing motion capture to make animation.

3. Change the animation import to multithreaded optimization speed.

4.  Fix some curve problems.

5. Fix known bugs

6. Fix some possible memory leaks.

### 0.3.9.1

1. Fixed the problem of stuck animation after import.

2. Fix some possible memory leaks.

### 0.3.9

1. Added support for rigidbodies and joints. (Currently not implemented in physics)

2. Fix the GUI scroll bar problem.

3. Fixed an issue where animation curves could not be saved.

4. Add new model management objects.

5. Add model display filter system.

6. Add IK enabled, model display animation import.

7. Fixed some actions importing problems.

### 0.3.8.1

Add tool modules.

​	~~If the model has a problem similar to the following figure after importing the action, you can try to use the tool to repair it.~~

1. ~~Select the model.~~

2. ~~Click on the fix action tool button.~~

(V0.4 has been temporarily removed)

### 0.3.8

1. Rewrite the bone expression part.

2. Add UV expression import (multi-part import mode).

3. Fix some errors of imported models.

4. Add the function of cleaning up the unconnected vertices of the imported model.

5. Add drag and drop import of camera animation.

6. Pre-loaded physics engine module support.

### 0.3.7.5

Fix the problem of non-rotatable bones and import animation of physical bones. Add UV expression import (only multi-part import mode).

### 0.3.7

Fixed the problem that the plug-in might not be loaded, and added bone expression import.

### 0.3.6

Fix the problem of multi-part import face error, and add the function of importing multi-part vertex expressions.

### 0.3.5

Fix stuck and errors caused by configuration files, increase multi-thread safety, and reduce crashes.

### 0.3.4

Add support for saving settings, save the last used configuration; update the R20 version.

### 0.3.3

Introduce the YAML configuration file; rewrite and rename the English module.

![](https://ftp.bmp.ovh/imgs/2021/05/84376d077a7e0721.jpg)

### 0.3.2

1. Optimize the processing method of the imported model to ensure the same effect as in MMD.

2. Optimize the leg bone problem of the imported model to ensure the same effect as in MMD.

3. Optimized the detection of the alpha channel of the picture, and fixed the problem that the material was incorrectly imported into the transparent channel

4. Increased code stability and reduced accidental crashes.

### 0.3.1

Improve the action import and PMX bone objects; fix the situation that the imported model may be stuck.

### 0.3.0

Improve camera action export function, support S24.

### 0.2.9.1

Added the function of deleting key frames of camera objects.

### 0.2.9.0

Fixed the problem that the imported model may be stuck.

### 0.2.8.5

Add the import expression function for non-multipart model import.

### 0.2.8.3

Fix the action import bug.

### 0.2.8.1

Fix import issues

### 0.2.8

Optimized for multi-threaded import.

### 0.2.3

Support s22 version

### 0.2.2

Fix the weight import problem

### 0.2.1

Fix the weight import problem and bone import problem

### 0.2.0

Initial commit

## Intermediate build tags

Tags without a separate published Release are consolidated into the next published version above:

| Tags | Recorded under | Main changes |
| --- | --- | --- |
| 0.9.1.0, 0.9.1.1 | 0.9.1.2 | Refactor baseline and Windows packaging fixes |
| 0.9.1.4, 0.9.1.5, 0.9.1.7–0.9.1.14 | 0.9.1.15 | Bone controls, PMX export, dependency/old-SDK/Intel build repairs |
| 0.9.1.16–0.9.1.19 | 0.9.1.20 | VPD and Material Morph work, macOS/ARM validation and resource synchronization |
