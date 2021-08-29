# C4D MMD Tool

[![](https://img.shields.io/github/downloads/AiMiDi/C4D_MMD_Tool/total)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) [![](https://img.shields.io/github/forks/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/network/members) [![](https://img.shields.io/github/stars/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/stargazers) [![](https://img.shields.io/github/license/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/blob/main/LICENSE.md)  ![](https://img.shields.io/github/languages/top/AiMiDi/C4D_MMD_Tool) [![](https://img.shields.io/github/last-commit/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/commits/main) [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases)

[![](https://img.shields.io/badge/ReadMe-English-green)](README.md)

## 关于

Cinema 4D的mmdtool。

用C ++编写的Cinema 4D插件，用于将MikuMikuDance数据导入Cinema 4D。

![](https://ftp.bmp.ovh/imgs/2021/05/a35d8cc0c9312f6b.jpg)

## 发行版

插件点击 [![](https://img.shields.io/github/v/release/AiMiDi/C4D_MMD_Tool)](https://github.com/AiMiDi/C4D_MMD_Tool/releases) 下的最新版本下载

目前，主要维护版本为R20及更高版本，R19及以下版本未提供支持。

若模型导入时勾选多部分出现问题请不要勾选。

**如果安装了插件没有显示，请检查是否C4D安装的为最新小版本（如R21的是R21.207才行，R21.115不显示的升级就可以用）**

## 版本更新

**version 0.2.0** 初次提交

**version 0.2.1** 解决权重导入问题和骨骼导入问题

**version 0.2.2** 解决权重导入问题

**version 0.2.3** 支持s22版本

**version 0.2.8**  针对多线程导入进行了优化。

**version 0.2.8.1** 解决导入问题

**version 0.2.8.3** 修复导入动作错误。

**version 0.2.8.5** 添加用于非多部分模型导入的导入表情功能。

**version 0.2.9.0** 修复了导入模型可能卡住的问题。

**version 0.2.9.1**  增加了删除摄像机对象关键帧的功能。

**version 0.3.0**  完善摄像头动作导出功能，支持S24。

**version 0.3.1** 完善动作导入和PMX骨骼对象；修复导入模型可能卡死的情况。

**version 0.3.2**

​	1.优化导入模型赋予亲的处理方式，确保与MMD中效果相同。

​	2.优化导入模型的腿部骨骼问题，确保与MMD中效果相同。

​	3.优化了图片alpha通道的检测，修复了材质错误导入透明通道的问题。

​	4.增加了代码稳定性，减少了意外的崩溃。

**version 0.3.3** 引入YAML配置文件；重写更名英文模块。

![](https://ftp.bmp.ovh/imgs/2021/05/5c6d8897c477f188.jpg)

**version 0.3.4** 添加设置记录功能，保存上一次使用配置；更新R20版本。

**version 0.3.5** 修复配置文件造成的卡死和错误，增加多线程安全性，减少崩溃。

**version 0.3.6** 修复多部分导入面错误问题，添加多部分导入顶点表情的功能。 

**version 0.3.7** 修复可能无法加载插件的问题，添加骨骼表情导入。

**version 0.3.7.5**  修复不可旋转骨骼，物理骨骼导入动画的问题。添加UV表情导入（仅多部分导入模式）。

**version 0.3.8**

​	1.重写了骨骼表情部分。

​	2.添加UV表情导入（多部分导入模式）。

​	3.修复导入模型的一些错误。

​	4.添加对导入模型的无连接顶点的清理功能。

​	5.添加摄像机动作的拖拽导入。

​	6.预载物理引擎模块支持。

**version 0.3.8.1** 添加工具模块。

​	如果导入动作后模型出现类似下图问题，可以尝试使用工具修复。

​		1.选择模型。

​		2.点击修复动作工具按钮。

（v0.4已暂时移除）

**version 0.3.9**

​	1.添加刚体和Joint的支持。（目前物理未实装）

​	2.修复GUI滚动条问题。

​	3.修复动画曲线不能保存的问题。

​	4.增加新的模型管理对象。

​	5.增加模型显示过滤系统。

​	6.增加IK启用，模型显示动画导入。

​	7.修复部分动作导入问题。

**version 0.3.9.1**

​	1.修复导入动画后卡死问题。

​	2.修复一些可能的内存泄漏问题。

**version 0.4**

​	1.修复导入动作捕捉制作动画后动作错乱问题。

​	2.将动画导入改为，多线程优化速度。

​	3.修复部分曲线问题。

​	4.修复一些已知BUG

​	5.修复一些可能的内存泄漏问题。

## 使用方法

1.选择相应的插件版本，并将其放置在Cinema 4D安装目录下的plugins文件夹中。

2.运行Cinema 4D，在菜单->扩展（插件）栏中找到 `MMDTool`，然后单击运行。

## 作者

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)

讨论群：790973593