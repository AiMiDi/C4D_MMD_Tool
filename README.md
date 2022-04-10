# C4D MMD Tool

[![](https://img.shields.io/github/downloads/AiMiDi/C4D_MMD_Tool/total)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) [![](https://img.shields.io/github/forks/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/network/members) [![](https://img.shields.io/github/stars/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/stargazers) [![](https://img.shields.io/github/license/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/blob/main/LICENSE.md) ![](https://img.shields.io/github/languages/top/AiMiDi/C4D_MMD_Tool) ![](https://img.shields.io/github/last-commit/AiMiDi/C4D_MMD_Tool) [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases)

[![](https://img.shields.io/badge/ReadMe-%E4%B8%AD%E6%96%87-red)](README_zh.md)

## About

mmdtool for Cinema 4D.

A plugin for Cinema 4D written in C++ is used to import MikuMikuDance data into Cinema 4D.

![](https://ftp.bmp.ovh/imgs/2021/05/bac9aa6402d8894d.jpg)

## Release

Click the latest version of the plugin under [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) to download it

At present, the main maintenance version are R20 and higher, R19 and lower are unsupported.

If there is a problem with selecting multiple-parts when the model is imported, please do not check it.

**If the plugin is installed, please check whether the latest version of C4D is installed (such as R21 is R21.207, R21.115 does not show the upgrade can be used)**

## usage

1. Select the corresponding version of the plugin and place it in the plugins folder under the Cinema 4D installation directory.

2. Run Cinema 4D, find `MMDTool` in the menu -> Extension(Plugin) bar and click Run.

### Functions 

- MMD Tool

  - Camera

    - Camera Import

      [![7KytMj.png](https://s4.ax1x.com/2022/01/12/7KytMj.png)](https://imgtu.com/i/7KytMj) 

      Import camera animation from VMD camera data.

      - Size
        The magnification of the imported camera animation

      - Offset
        Import the start frame position of the camera animation.

      - Import
        Import a VMD file with camera animation according to the above settings.

    - Export

      [![7KyHQH.png](https://s4.ax1x.com/2022/01/12/7KyHQH.png)](https://imgtu.com/i/7KyHQH) 

      Export camera animation to VMD.

      - Size
        Exported camera animation magnification.

      - Offset
        Export the starting frame position of the camera animation.

      - Use rotate curve
        Specifies the axis to convert to the entire MMD rotation curve animation, which you don't have to worry about if you choose baking.

      - Export after baking
        Exporting the baked animation can ensure the integrity of the curve.

      - Export
        Export a VMD file with camera animation according to the above settings.

    - Conversion camera

      [![7KyXwt.png](https://s4.ax1x.com/2022/01/12/7KyXwt.png)](https://imgtu.com/i/7KyXwt) 

      Convert the default camera to a dedicated MMD camera.

      - Distance
        MMD dedicated camera distance after conversion.

      - Use rotate curve
        Specifies the axis to convert to the entire MMD rotation curve animation.

      - Conversion
        Convert the default camera to an MMD dedicated camera according to the above settings.

  - Motion

    - Motion Import

      [![7K6Pyj.png](https://s4.ax1x.com/2022/01/12/7K6Pyj.png)](https://imgtu.com/i/7K6Pyj) 

      Import VMD action data to the bones of the model.
      If there is no PMX bone tag, import the action according to the bone name;
      If there is a PMX bone tag, import the action according to the local bone name on the tag;
  
      - Size
        The magnification of the imported bone animation.
    - Offset
        The start frame position of the imported bone animation.
      -  Import motion
      Whether to import bone actions.
      -  Import morph
        Whether to import emoticons.
    - Import model info
        Whether to import the model IK switch, and hide the information of the model.
      - Delete previous animation
      Whether to delete the previous animation before import.
      - Detail report Whether to display specific information about missing bones or expressions.
      - Import
      Import VMD action data according to the above parameters
  
    - Export Motion

      [![7K6mfU.png](https://s4.ax1x.com/2022/01/12/7K6mfU.png)](https://imgtu.com/i/7K6mfU) 
  
    Export the action data on the model to VMD.
  
      - Size
        The magnification of the exported bone animation.
    - Offset
      Export the start frame position of the bone animation.
      - Use rotate curve
      Specifies the axis to convert to the entire MMD rotation curve animation, which you don't have to worry about if you choose baking.
      -  Export motion
      Whether to export bone actions.
    -  Export morph
        Whether to export expression actions.
    - Export after baking
      Exporting the baked animation can ensure the integrity of the curve.
      - Export
      Export a VMD file with bone animation according to the above settings.
  
    - Pose Import

      
  
    [![7K6UpD.png](https://s4.ax1x.com/2022/01/12/7K6UpD.png)](https://imgtu.com/i/7K6UpD)
  
      Import VPD data into the model.

      - Import
        Import VPD pose data.

  - Model
  
  - Import Model
  
    [![7K629S.png](https://s4.ax1x.com/2022/01/12/7K629S.png)](https://imgtu.com/i/7K629S) 
  
    Import the PMX model into the plugin.
  
    - Size
        The scale factor of the imported model.

      - Polygon
        Whether to import polygons.

      - Normal
      Whether import normals.
  
    - UV
        Whether to import UVs.

      - Material
      Whether to import materials.
  
      - Bone
      Whether to import bones.
  
      - Weighs
      Whether to import weights.
  
      - IK
      Whether to import IK bones.
  
      - Inherit
      Whether to import inherit bone.
  
      - Expression
      Whether to import facial expression deformation.
  
      - Multipath
      Whether to import the model as a separate mesh.
  
      - English
      Whether to add the English name of the bone and display it in English.
  
      - Check English
      Whether to manually confirm the English name of the missing bone.
  
      - Import
      Import PMX model according to the above parameters.

## version 

**version 0.2.0** Initial commit

**version 0.2.1** Fix the weight import problem and bone import problem

**version 0.2.2** Fix the weight import problem

**version 0.2.3** Support s22 version

**version 0.2.8**  Optimized for multi-threaded import.

**version 0.2.8.1** Fix import issues

**version 0.2.8.3** Fix the action import bug.

**version 0.2.8.5** Add the import expression function for non-multipart model import.

**version 0.2.9.0** Fixed the problem that the imported model may be stuck.

**version 0.2.9.1**  Added the function of deleting key frames of camera objects.

**version 0.3.0**  Improve camera action export function, support S24.

**version 0.3.1** Improve the action import and PMX bone objects; fix the situation that the imported model may be stuck.

**version 0.3.2**

1. Optimize the processing method of the imported model to ensure the same effect as in MMD.

2. Optimize the leg bone problem of the imported model to ensure the same effect as in MMD.

3. Optimized the detection of the alpha channel of the picture, and fixed the problem that the material was incorrectly imported into the transparent channel

4. Increased code stability and reduced accidental crashes.


**version 0.3.3** Introduce the YAML configuration file; rewrite and rename the English module.

![](https://ftp.bmp.ovh/imgs/2021/05/84376d077a7e0721.jpg)

**version 0.3.4** Add support for saving settings, save the last used configuration; update the R20 version.

**version 0.3.5** Fix stuck and errors caused by configuration files, increase multi-thread safety, and reduce crashes.

**version 0.3.6** Fix the problem of multi-part import face error, and add the function of importing multi-part vertex expressions.

**version 0.3.7** Fixed the problem that the plug-in might not be loaded, and added bone expression import.

**version 0.3.7.5** Fix the problem of non-rotatable bones and import animation of physical bones. Add UV expression import (only multi-part import mode).

**version 0.3.8**

1. Rewrite the bone expression part.

2. Add UV expression import (multi-part import mode).

3. Fix some errors of imported models.

4. Add the function of cleaning up the unconnected vertices of the imported model.

5. Add drag and drop import of camera animation.

6. Pre-loaded physics engine module support.


**version 0.3.8.1** Add tool modules.

​	~~If the model has a problem similar to the following figure after importing the action, you can try to use the tool to repair it.~~

1. ~~Select the model.~~

2. ~~Click on the fix action tool button.~~

(V0.4 has been temporarily removed)

**version 0.3.9**

1. Added support for rigidbodies and joints. (Currently not implemented in physics)

2. Fix the GUI scroll bar problem.

3. Fixed an issue where animation curves could not be saved.

4. Add new model management objects.

5. Add model display filter system.

6. Add IK enabled, model display animation import.

7. Fixed some actions importing problems.


**version 0.3.9.1**

1. Fixed the problem of stuck animation after import.

2. Fix some possible memory leaks.


**version 0.4**

1. Add the action export function

2. Fix the action confusion problem after importing motion capture to make animation.

3. Change the animation import to multithreaded optimization speed.

4.  Fix some curve problems.

5. Fix known bugs

6. Fix some possible memory leaks.


**version 0.4.1**

1. Add camera bake export.

2. Add motion bake export. 

3. Improve Ik.


**version 0.4.2**

1. Add import pose.

2. Improve the function of PMX Control.

3. Support R25.


**version 0.4.3**

1. Fixed multi-part import import weights not initializing bones.

2. Improved weight import.

3. Fix import failure caused by empty IK list.

**version 0.4.4**

1. Fix the problem of vertex expression loss of partial vertices imported by multiple parts.
2. Fix the problem that the model cannot be imported when the external parent is opened.
3. Compatible with projects saved by older versions. (some information may be lost, but it does not affect the opening of the project)

**version 0.4.4.1** Fix import normal inversion issue.

**version 0.4.5**

1. Fixed an issue where saved documents could not be opened.
2. Optimize the IK of the imported model.
3. Add import model report.
4. Optimize import speed and stability.
5. Fixed import normal inversion problem for versions below R23.

**version 0.4.5.1** Fixed import model surface error.

**version 0.4.6**

1. A new expression hub panel is added to manage all expressions.
2. Added support and editing for group and flip expressions.
3. Motion import adds the option to ignore physical bones.
4. New icon.（The logo icon is temporary and the logo icon may be changed again）

## Author

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)