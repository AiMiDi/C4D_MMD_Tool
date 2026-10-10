# C4D MMD Tool

[![](https://img.shields.io/github/downloads/AiMiDi/C4D_MMD_Tool/total)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) [![](https://img.shields.io/github/forks/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/network/members) [![](https://img.shields.io/github/stars/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/stargazers)  ![](https://img.shields.io/github/languages/top/AiMiDi/C4D_MMD_Tool) ![](https://img.shields.io/github/last-commit/AiMiDi/C4D_MMD_Tool) [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases)

[![Build](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml/badge.svg)](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/facde953bcc94a0799d045ba0633222d)](https://www.codacy.com/gh/AiMiDi/C4D_MMD_Tool/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=AiMiDi/C4D_MMD_Tool&amp;utm_campaign=Badge_Grade) [![](https://img.shields.io/github/license/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/blob/main/LICENSE.md)

[![](https://img.shields.io/badge/ReadMe-%E4%B8%AD%E6%96%87-red)](README_zh.md)

## About

mmdtool for Cinema 4D.

A plugin for Cinema 4D written in C++ is used to import MikuMikuDance data into Cinema 4D.

![MMD Tool](res/S24_up/mmd_tool_title.png)

## Release

Click the latest version of the plugin under [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) to download it

Release filenames identify the plugin version, Cinema 4D compatibility and platform:

- **Windows x64**: `MMD-Tool-v<version>-Windows-x64-Setup.exe` — one installer for Cinema 4D R20 through 2026.
- **macOS Intel**: `MMD-Tool-v<version>-Cinema4D-2026-macOS-x86_64.zip` — choose the ZIP for your Cinema 4D version. Older pairs are labeled `R21-S22`, `R23-S24` and `R25-S26`; R20 has its own ZIP. Published macOS ZIPs contain Intel builds; Apple Silicon builds currently validate in CI only.

At present, the main maintenance version are R20 and higher, R19 and lower are unsupported.

If there is a problem with selecting multiple-parts when the model is imported, please do not check it.

**If the plugin is installed, please check whether the latest version of C4D is installed (such as R21 is R21.207, R21.115 does not show the upgrade can be used)**

## usage

1. Select the corresponding version of the plugin and place it in the plugins folder under the Cinema 4D installation directory.

2. Run Cinema 4D, find `MMDTool` in the menu -> Extension(Plugin) bar and click Run.

### Interface and features

Captured in Cinema 4D 2026.4.0 on 2026-10-06, these screenshots show the current working-tree plugin with its Chinese UI. Screenshots are cropped to the relevant controls. Scroll within each tab to reach the lower sections. Published releases may have a different interface.

#### Camera · VMD import, export and conversion

| Import and export | Camera conversion |
| --- | --- |
| ![VMD camera import and export panel](docs/images/camera-vmd.png) | ![MMD camera conversion controls](docs/images/camera-conversion.png) |

- **Import camera**: Load camera animation from a VMD file, with scale and start-frame offset settings.
- **Export camera**: Save camera animation as VMD, with scale, start-frame offset, rotation-curve and bake options.
- **Convert camera**: Convert a regular camera to an MMD camera, with distance and rotation-curve settings.

#### Motion and pose · VMD / VPD

| Motion import | Motion export and pose |
| --- | --- |
| ![VMD motion import panel with bone, morph and model-information options](docs/images/motion-import.png) | ![VMD motion export and VPD pose import and export panel](docs/images/motion-export-pose.png) |

- **Import motion**: Load VMD bone animation, morph animation and model information onto a model, with scale and start-frame offset settings.
- **Import options**: Match local names, ignore physics bones, overwrite previous animation and show a detailed report. Model information includes IK switches and model visibility.
- **Export motion**: Save bone animation, morph animation and model information as VMD, with rotation-curve and bake options.
- **Pose**: Import a VPD pose, or export the selected MMD model's pose at the current frame as VPD.

#### VMD motion adaptation · Body proportions and stage previews

Adapt a VMD made for one character to another. Source and target PMX proportions drive movement correction, with optional stance, twist, arm avoidance, wrist/finger contact, floor contact and leg self-collision correction. Character queues and camera fitting are supported. The reusable C++ core lives in [libMMD](https://github.com/AiMiDi/libMMD) under `libmmd::sizing`, without a C4D SDK or Python runtime dependency.

1. Find **MMD Tools - VMD Motion Sizing** in the Extensions menu.
2. Select the **source PMX used to author the motion**, then drag an imported **target MMD model manager** from the scene into the model field.
3. Select a VMD file or an existing VMD animation slot on the target model. Use the same import scale for the model and motion; this example uses **8.5**.
4. Check scale and offset results first, then enable constraints as needed. Wrist/finger contact preserves the relative arrangement of nearby source hand landmarks; it does not generate grips or finger curls. Leg self-collision avoidance makes bounded adjustments to foot IK goals.
5. Calculate and watch progress in the C4D status bar; long operations can be cancelled. Select stages and scrub the timeline to compare original, scale, offset, stance, twist, avoidance and contact results. Side-by-side/overlay previews and automatic refresh after parameter changes are available.
6. Inspect residuals and important poses, then **apply as a new animation slot** or export VMD. The original slot is retained.

Afu 2.0 with Stay Tonight Heaven Lee Ver., captured in the native C4D viewport with physics disabled.

**Legs and overall pose: the original, unadapted VMD on the left and the complete adaptation result on the right.** Both use the same import scale, animation frame and camera view.

![Leg pose comparison: original VMD on the left, complete adaptation on the right](docs/images/motion-sizing-comparison.png)

**Wrist contact: the previous contact solver on the left and the correction that preserves the hand pose on the right.** This image shows the change in handling overlapping hands.

![Wrist contact comparison: previous contact result on the left, corrected result on the right](docs/images/motion-sizing-wrist-comparison.png)

**Current limits:** Avoidance uses standard bone chains and rigid shapes. It does not guarantee mesh-level separation, full physics simulation or foot locking. Deep crossings and conflicting goals may still need manual adjustment; inspect important poses in the stage preview.

**Reference project:** Body-proportion and movement compensation adapts formulae from [miu200521358/vmd_sizing](https://github.com/miu200521358/vmd_sizing), revision `e5c30358696f688c96544e3af33ea9871961487d`. Its [MIT license and copyright notice](res/S24_up/licenses/vmd_sizing-MIT.txt) are retained. Advanced constraints are this project's C++ implementation; full feature or numerical equivalence with the Python tool is not claimed.

[Usage and solver limits](docs/dev/vmd-sizing.md) · [MCP interface](docs/dev/motion-sizing-mcp.md) · [Real-asset validation](docs/validation/vmd-sizing/leg-ik-fix-20261010/README.md)

#### Model · PMX import and export

| Model import | Model export |
| --- | --- |
| ![PMX model import panel with material-conversion options](docs/images/model-import.png) | ![PMX model export panel](docs/images/model-export.png) |

- **Import model**: Set the scale and choose which data to import: polygons, normals, UVs, materials, bones, weights, IK, inherit bones and morphs.
- **Material conversion**: Choose Standard, RedShift, Octane or Corona materials. The corresponding renderer must be available when required.
- **Import options**: Use separate meshes, English names and manual confirmation of English names.
- **Export model**: Save the selected MMD model as PMX, with scale and data-selection options. The source must be an MMD model managed by the plugin.

## Developers

**Developer documentation:** [DEVELOPMENT.md](DEVELOPMENT.md) · [中文 DEVELOPMENT_zh.md](DEVELOPMENT_zh.md)

Windows development: `cmake --preset dev-windows` then `cmake --build --preset workflow-dev`. Release: configure `release-windows` then build `workflow-release`. Test preset `dev-windows-deps-test` supports `cmt-deps-test` and `cmt-plugin-tests`; benchmarks use the separate `cmt-deps-benchmark` target. PR/main CI runs functional tests and a latest-SDK compile; releases build the complete SDK matrix. Built plugin folders include copied, verified resources. See the developer guide for packaging and normal-start/attach debugging.

## Changelog

The three most recent version entries are shown below. See the [complete changelog](CHANGELOG.md) for earlier changes.

### 0.9.3.4 · Motion pose preservation and IK correction (2026-10-10)

1. Fix destructive wrist/finger contact adjustments while preserving finger curls, palm orientation and source contact relationships.
2. Reuse playback IK for offline poses, including PMX link limits, iteration counts and VMD IK switches; skip driven channels that cannot accept direct animation.
3. Add optional leg self-collision avoidance with foot IK target protection, temporal filtering and rollback for conflicting floor constraints.
4. Add C4D status-bar progress and cancellation feedback for long calculations, with shared MCP and panel options.
5. Document motion adaptation, wrist/leg effect comparisons and the reference project.

Inspect complex contacts in the stage preview. [Validation and known limits](docs/validation/vmd-sizing/leg-ik-fix-20261010/README.md)

### 0.9.3.3 · VMD motion adaptation (2026-10-10)

1. Add staged VMD motion adaptation with body-scale and movement offsets, stance and twist adjustment, rigid-shape avoidance, contact constraints, multi-character processing and camera fitting.
2. Add a localized C4D panel with scene-model selection, existing animation-slot input, before/after stage previews, queued characters and apply/export controls.
3. Add typed production MCP motion-sizing tools with asynchronous jobs, cancellation, preview, apply/export and shared panel state.
4. Move reusable calculation into libMMD under `libmmd::sizing`, independent of the C4D SDK, with public APIs, regression fixtures and documented solver limits.
5. Fix R20 source processing, R21 STL compatibility and pre-2026 LinkBox API support. Preserve SSE2 compilation for sizing to keep the validated numerical baseline.

### 0.9.3.2 · Controller placement and hover names (2026-10-09)

1. Fix eye controller placement on fresh PMX import; align the shared eye outline with the actual eye pair while retaining its authored rotation pivot and model scale.
2. Show the bone name when hovering a generated controller outline, using the selected local or English naming mode. Hidden controls and disabled spline display do not produce hints.
3. Remove direction triangles from rotation rings and ovals; retain shoulder leaders, hand wire boxes and toe IK triangles.
4. Hide generated controllers in Edit mode and restore Primary/All/Hidden settings in Animation mode. Preserve existing controller transforms and animation tracks when refreshing.
5. Avoid transient GitLab Eigen checkout failures in CI by using a mirror of the same pinned commit and bounded checkout retries.

[Changes since 0.9.3.0](https://github.com/AiMiDi/C4D_MMD_Tool/compare/v0.9.3.0...v0.9.3.2) · [Validation scope](docs/dev/controllers-eye-hover-20261009.md)

## Author

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)
