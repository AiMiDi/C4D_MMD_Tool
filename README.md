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

The latest three releases are listed here. See the [complete changelog](CHANGELOG.md) for older versions and intermediate build tags.

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

## Author

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)
