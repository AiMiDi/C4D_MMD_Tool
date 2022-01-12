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

## 使用方法

1. 选择相应的插件版本，并将其放置在Cinema 4D安装目录下的plugins文件夹中。
2. 运行Cinema 4D，在菜单->扩展（插件）栏中找到 `MMDTool`，然后单击运行。

### 界面介绍

- MMD Tool

  - 摄像机

    - 导入摄像机

      ![](https://ftp.bmp.ovh/imgs/2022/01/2b2638f049827f85.png) 

      从VMD相机数据导入摄像机动画

      - 大小缩放
        导入的摄像机动画放大倍率

      - 起始偏移
        导入摄像机动画的起始帧位置

      - 导入
        根据上述设置导入带有摄像机动画的VMD文件

    - 导出摄像机

      ![](https://ftp.bmp.ovh/imgs/2022/01/d166192f827cebc1.png) 

      导出摄像机动画到VMD

      - 大小缩放
        导出的摄像机动画放大倍率

      - 起始偏移
        导出摄像机动画的起始帧位置

      - 使用旋转曲线
        指定转化为整个MMD旋转曲线动画的轴，选择烘焙则不用担心此问题

      - 烘焙后导出
        导出烘焙后的动画，能保证曲线的完整性

      - 导出
        根据上述设置导出带有摄像机动画的VMD文件

    - 转化摄像机

      ![](https://ftp.bmp.ovh/imgs/2022/01/e0c97fad1fc5ffcb.png) 

      将默认摄像机转化为MMD专用摄像机

      - 距离
        转化后的MMD专用摄像机距离

      - 使用旋转曲线
        指定转化为整个MMD旋转曲线动画的轴

      - 转化
        根据上述设置将默认摄像机转化为MMD专用摄像机

  - 动作

    - 导入动作

      ![](https://ftp.bmp.ovh/imgs/2022/01/b1868a4f65482d5a.png) 

      导入VMD动作数据到模型的骨骼上。
      若无PMX骨骼标签则根据骨骼名称导入动作；
      若有PMX骨骼标签则根据标签上的本地骨骼名称导入动作；

      - 大小缩放
        导入的骨骼动画动画放大倍率
        
      - 起始偏移
        导入骨骼动画的起始帧位置

      - 导入骨骼动作
        是否导入骨骼动作

      - 导入表情动作
        是否导入表情动作

      - 导入模型信息
        是否导入模型IK开关，模型隐藏信息

      - 删除先前动画
        是否在导入前删除之前的动画

      - 详细报告
        是否显示缺少骨骼或表情具体信息

      - 导入
        根据上述参数导入VMD动作数据

    - 导出动作

      ![](https://ftp.bmp.ovh/imgs/2022/01/9ef8573c38282e31.png) 

      将模型上的动作数据导出到VMD。

      - 大小缩放
        导出的骨骼动画动画放大倍率

      - 起始偏移
        导出骨骼动画动画的起始帧位置

      - 使用旋转曲线
        指定转化为整个MMD旋转曲线动画的轴，选择烘焙则不用担心此问题

      - 起始偏移
        导出骨骼动画的起始帧位置

      - 大小缩放
        导出的骨骼动画放大倍率

      - 烘焙后导出
        导出烘焙后的动画，能保证曲线的完整性

      - 导出
        根据上述设置导出带有骨骼动画的VMD文件

    - 导入姿势

      

      ![](https://ftp.bmp.ovh/imgs/2022/01/92d73f698d9fbae0.png) 

      将VPD数据导入到模型上

      - 导入
        导入VPD姿势数据

  - 模型

    - 导入模型

      ![](https://ftp.bmp.ovh/imgs/2022/01/60c1719d991e4661.png) 

      将PMX模型导入到插件中

      - 大小
        导入的模型缩放倍率

      - 多边形
        是否导入多边形

      - 法线
        是否导入法线

      - UV
        是否导入UV

      - 材质
        是否导入材质

      - 骨骼
        是否导入骨骼

      - 权重
        是否导入权重

      - IK
        是否导入IK骨骼

      - 付予
        是否导入付予骨骼

      - 表情
        是否导入表情变形

      - 多部分
        是否将模型导入为分开的网格

      - 名称英文
        是否添加骨骼英文名称并显示为英文

      - 手动确认英文
        是否手动确认没找到的骨骼英文名称对应

      - 导入
        根据上述参数导入PMX模型

飞书文档: https://fsrjo99ngu.feishu.cn/docs/doccnjnPb8YuNmiVEheSzBj7bSd

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

1. 优化导入模型赋予亲的处理方式，确保与MMD中效果相同。

2. 优化导入模型的腿部骨骼问题，确保与MMD中效果相同。

3. 优化了图片alpha通道的检测，修复了材质错误导入透明通道的问题。

4. 增加了代码稳定性，减少了意外的崩溃。


**version 0.3.3** 引入YAML配置文件；重写更名英文模块。

![](https://ftp.bmp.ovh/imgs/2021/05/5c6d8897c477f188.jpg)

**version 0.3.4** 添加设置记录功能，保存上一次使用配置；更新R20版本。

**version 0.3.5** 修复配置文件造成的卡死和错误，增加多线程安全性，减少崩溃。

**version 0.3.6** 修复多部分导入面错误问题，添加多部分导入顶点表情的功能。 

**version 0.3.7** 修复可能无法加载插件的问题，添加骨骼表情导入。

**version 0.3.7.5**  修复不可旋转骨骼，物理骨骼导入动画的问题。添加UV表情导入（仅多部分导入模式）。

**version 0.3.8**

1. 重写了骨骼表情部分。

2. 添加UV表情导入（多部分导入模式）。

3. 修复导入模型的一些错误。

4. 添加对导入模型的无连接顶点的清理功能。

5. 添加摄像机动作的拖拽导入。

6. 预载物理引擎模块支持。


**version 0.3.8.1** 添加工具模块。

~~如果导入动作后模型出现类似下图问题，可以尝试使用工具修复。~~

1. ~~选择模型。~~
2. ~~点击修复动作工具按钮。~~

（v0.4问题修复，已移除）

**version 0.3.9**

1. 添加刚体和Joint的支持。（目前物理未实装）

2. 修复GUI滚动条问题。

3. 修复动画曲线不能保存的问题。

4. 增加新的模型管理对象。

5. 增加模型显示过滤系统。

6. 增加IK启用，模型显示动画导入。

7. 修复部分动作导入问题。


**version 0.3.9.1**

1. 修复导入动画后卡死问题。

2. 修复一些可能的内存泄漏问题。


**version 0.4**

1. 增加动作导出功能.

2. 修复导入动作捕捉制作动画后动作错乱问题。

3. 将动画导入改为，多线程优化速度。

4. 修复部分曲线问题。

5. 修复一些已知BUG

6. 修复一些可能的内存泄漏问题。


**version 0.4.1**

1. 增加摄像机烘焙导出。

2. 增加动作烘焙导出。

3. 优化Ik.


**version 0.4.2**

1. 添加姿势（vpd）导入。

2. 改进PMX控件。

3. 支持 R25 版本。


**version 0.4.3**

1. 修复多部分导入时未初始化骨骼导致的崩溃。

2. 改进权重导入。

3. 修复ik列表为空导致的导入失败。


**version 0.4.4**

1. 修复多部分导入部分顶点的顶点表情丢失问题。
2. 修复模型有骨骼打开外部亲的情况下，模型无法导入的问题。
3. 兼容旧版本保存的工程。（可能会丢失部分信息，但是不影响工程打开）

## 作者

AiMiDi

[![](https://img.shields.io/badge/-@AiMiDi-%23181717?style=flat-square&logo=github)](https://github.com/AiMiDi)   

[![](https://img.shields.io/badge/-%40艾米蒂aimidi-blue?style=flat-square&logo=bilibili)](https://space.bilibili.com/30898053)

讨论群：790973593