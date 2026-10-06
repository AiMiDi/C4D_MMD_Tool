# C4D MMD Tool

[![](https://img.shields.io/github/downloads/AiMiDi/C4D_MMD_Tool/total)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) [![](https://img.shields.io/github/forks/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/network/members) [![](https://img.shields.io/github/stars/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/stargazers)  ![](https://img.shields.io/github/languages/top/AiMiDi/C4D_MMD_Tool) ![](https://img.shields.io/github/last-commit/AiMiDi/C4D_MMD_Tool) [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases)

[![Build](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml/badge.svg)](https://github.com/AiMiDi/C4D_MMD_Tool/actions/workflows/build.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/facde953bcc94a0799d045ba0633222d)](https://www.codacy.com/gh/AiMiDi/C4D_MMD_Tool/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=AiMiDi/C4D_MMD_Tool&amp;utm_campaign=Badge_Grade) [![](https://img.shields.io/github/license/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/blob/main/LICENSE.md)

[![](https://img.shields.io/badge/ReadMe-%E4%B8%AD%E6%96%87-red)](README_zh.md)

**Developer documentation:** [DEVELOPMENT.md](DEVELOPMENT.md) · [中文 DEVELOPMENT_zh.md](DEVELOPMENT_zh.md)

Windows development: `cmake --preset dev-windows` then `cmake --build --preset workflow-dev`. Release: configure `release-windows` then build `workflow-release`. Test preset `dev-windows-deps-test` supports `cmt-deps-test` and `cmt-plugin-tests`; benchmarks use the separate `cmt-deps-benchmark` target. PR/main CI runs functional tests and a latest-SDK compile; releases build the complete SDK matrix. Built plugin folders include copied, verified resources. See the developer guide for packaging and normal-start/attach debugging.

## About

mmdtool for Cinema 4D.

A plugin for Cinema 4D written in C++ is used to import MikuMikuDance data into Cinema 4D.

![MMD Tool](res/S24_up/mmd_tool_title.png)

## Release

Click the latest version of the plugin under [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) to download it

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

## Changelog

### Unreleased · Major architectural refactor (2026-10-06)

This work continues the architecture, import/export and development-workflow refactor after `v0.9.1.20`. The entries below describe the current working tree; a new release version has not been assigned.

1. Split the model manager's responsibilities into dedicated modules for IK/physics runtime rebuilding, frame evaluation and morph calculation, sharing libMMD's solver and physics interfaces.
2. Clarify EDIT / ANIM transitions: commit the bind pose when entering animation mode and restore it when returning to editing. Consolidate runtime rebuilding after scene reopening, cloning and animation-slot changes.
3. Centralize bone hierarchy and index synchronization so reparenting, reordering, insertion and deletion update references and selection lists together. Cache layered bone and IK execution plans to reduce repeated work.
4. Complete VMD append, replace, merge and channel-option handling. Store morph animation, IK switches and model visibility per animation slot; improve final-pose baking, scale conversion and source-scene state restoration after export.
5. Correct VMD camera vertical field of view and unit conversion, migrate legacy camera tracks, and improve camera cloning, baked export, failure reporting and temporary-object cleanup.
6. Consolidate additive/multiplicative material morph calculations and Group/Flip strength evaluation. Improve base-material restoration when strengths return to zero, morphs are deleted or editing resumes, and update Standard and Redshift material adapters.
7. Add the production MCP API, 16 typed tools and a stdio adapter for model inspection, PMX/VMD import/export, animation slots, modes, physics, morphs and frame evaluation. Host integration requires Cinema 4D 2026.4 or later.
8. Unify shared source, resources and the common CMake layer across SDKs, with explicit Debug, Release and test presets. Ship real resource copies with plugin outputs and update Windows installer, macOS packaging and CI workflows.
9. Add algorithm tests, deterministic fixtures, native C4D scene regressions and build-identified validation records. Expand import, export, runtime and debugging documentation, and refresh the feature screenshots in both READMEs.

**Validation status:** Selected algorithm, build and native scene checks have recorded results. Complete production MCP, real-model physics replay and cross-platform release acceptance still require follow-up. This record will be updated as release validation progresses.

Existing historical entries are retained below in descending version order. See [GitHub Releases](https://github.com/AiMiDi/C4D_MMD_Tool/releases) for releases not recorded here.

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

## Author

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)
