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

​	1.Optimize the processing method of the imported model to ensure the same effect as in MMD.

​	2.Optimize the leg bone problem of the imported model to ensure the same effect as in MMD.

​	3.Optimized the detection of the alpha channel of the picture, and fixed the problem that the material was incorrectly imported into the transparent channel

​	4.Increased code stability and reduced accidental crashes.

**version 0.3.3** Introduce the YAML configuration file; rewrite and rename the English module.

![](https://ftp.bmp.ovh/imgs/2021/05/84376d077a7e0721.jpg)

**version 0.3.4** Add support for saving settings, save the last used configuration; update the R20 version.

**version 0.3.5** Fix stuck and errors caused by configuration files, increase multi-thread safety, and reduce crashes.

**version 0.3.6** Fix the problem of multi-part import face error, and add the function of importing multi-part vertex expressions.

**version 0.3.7** Fixed the problem that the plug-in might not be loaded, and added bone expression import.

**version 0.3.7.5** Fix the problem of non-rotatable bones and import animation of physical bones. Add UV expression import (only multi-part import mode).

**version 0.3.8**

​	1.Rewrite the bone expression part.

​	2.Add UV expression import (multi-part import mode).

​	3.Fix some errors of imported models.

​	4.Add the function of cleaning up the unconnected vertices of the imported model.

​	5.Add drag and drop import of camera animation.

​	6.Pre-loaded physics engine module support.

**version 0.3.8.1** Add tool modules.

​	If the model has a problem similar to the following figure after importing the action, you can try to use the tool to repair it.

​		1.Select the model.

​		2.Click on the fix action tool button.

![](https://ftp.bmp.ovh/imgs/2021/06/56cdad59253281fe.png)

**version 0.3.9**

​		1. Added support for rigidbodies and joints. (Currently not implemented in physics)

​		2. Fix the GUI scroll bar problem.

​		3. Fixed an issue where animation curves could not be saved.

​		4. Add new model management objects.

​		5. Add model display filter system.

​		6. Add IK enabled, model display animation import.

​		7. Fixed some actions importing problems.

## usage

1.Select the corresponding version of the plugin and place it in the plugins folder under the Cinema 4D installation directory.

2.Run Cinema 4D, find `MMDTool` in the menu -> Extension(Plugin) bar and click Run.

## Author

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)
