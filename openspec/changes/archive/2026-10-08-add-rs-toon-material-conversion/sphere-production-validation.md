# 普通 Sphere 与丝袜 revision 5 验证

日期：2026-10-07。用户要求继续对齐实际丝袜外观，并确认上一轮材质页防护后暂未复现崩溃。本轮保留该防护和 revision 4 的未指定 Toon 中性规则。

证据根目录：`_build_msvc/validation/rs-toon-material/sphere-20261007-08f90203/`。

## 模块和配方

- Cinema 4D 2026.4.0 / RS 2026.9.0。
- SDK 2026 Release SHA256：`08f9020326d37501ba0358cb4bcd51538a817252397b975d4caa2ca9b9ef67cf`。
- SDK 2026、2024、R20 Release 编译通过，三个现有材质/Morph/fixture CTest 通过。
- Graph revision 5：40 个角色、16 个对象属性；旧十三字段编号不变，旧图清理按旧字段数量进行，不自动重建艺术家图。
- 普通 Sphere Multiply/Add 使用相机相关的无透视失真 Matcap，Sphere Mul/Add RGBA 采样后独立运算，在 Toon 乘法前参与。Sphere 图片 Alpha 不接物体透明度。
- 主/Toon/Sphere sampler 默认 Raw，Toon V 偏移 0.5，Base Tonemap 使用 Light and Shadow；未指定 Toon 的中性规则保留。文档 OCIO 和显示变换不由转换修改。

Raw 是为保留旧式 bitmap 数值运算选定的风格配方，不能解释为所有颜色图片的物理正确解码。RS 的普通颜色材质通常使用颜色解码，参见 [Texture Sampler](https://help.maxon.net/r3d/cinema/en-us/Content/html/Texture%2BSampler.html)。Sphere 顺序与坐标参考 [Saba MMD shader](https://github.com/benikabocha/saba/blob/master/viewer/Saba/Viewer/resource/shader/mmd.frag) 和 [RS Matcap](https://help.maxon.net/r3d/cinema/en-us/Content/html/Texture%2BMatcap.html)，仍不构成 MMD 原生等价证明。

## 原生编辑与 Morph

`tests/material/native_sphere_test.py` 通过生产 PMX 导入创建双材质样例。

- 中性 Sphere 字段、加算/乘算混合预览的手算系数、关闭预览复位、节点数量稳定通过。
- 模式 1/0/3/2、空路径、有效路径恢复通过；坏文件保留权威数据，原有采样设置保留。
- 目标为未启用的 Multiply 节点时，手工连接仍阻止自动接管，旧模式保持不变。
- 模式编辑一次 Undo/Redo，分别立即保存重开，元数据与模式恢复通过。
- SubTexture 仍只保留数据并输出未支持诊断。

规范收据是 `native/result.json`。该目录的旧 `error.txt` 来自测试脚本先前的事务/布尔包装判断错误，不是最终候选失败；通过收据和 `native3.stdout.log` 分开记录。未扩大为完整 GUI Undo/Redo 或全部 Morph 图片矩阵的验收。

## 真实阿芙图像

重新从 `C:\白银之城—阿芙2.0\阿芙2.0.pmx` 生产导入。35 个材质通过 revision 5 / 40 角色 / 16 属性断言。丝袜 PMX Specular 为零，软亮带使用 Sphere Add `mc3.png`。

`tests/material/native_sphere_visual_test.py` 的每张图都先保存，再加载并渲染。关闭 GI 与降噪，采样 16/64。

- `before-gpu` / `after-gpu`：同一几何、相机和单方向光 `(-0.5,-1,0.5)`；只将丝袜退回旧采样/无 Sphere，再恢复 revision 5。其他材质保持新配方，不将这组称为整模型旧模块对照。
- `after-cpu` / `after-repeat-gpu`：同一保存场景的 CPU 与重复 GPU；重复 GPU RGBA 完全相同。CPU/GPU 最大通道差 7/255，可见区域 RGB 平均差约 0.00569/255。
- 改动前后 Alpha 最大差 1/255，未观察到 Sphere 造成透明轮廓改变。
- `frontal-light-gpu/cpu`：保持单方向光，将方向改为 `(0.25,-0.65,1)`，单独检查光向影响。两设备最大通道差 3/255。
- 两个整模型保存场景分别为 `阿芙-RS-Toon-球面贴图对齐.c4d` 和 `阿芙-RS-Toon-丝袜对齐.c4d`；后者采用偏正面的方向光。

目测：软亮带恢复，腿正面的大块深色段缩小，底色更接近用户截图中的浅粉色。原 Toon 图片本身仍为阶梯状，腿侧仍有分段；精确 PmxView 光向、曝光、颜色解释、独立 Ambient 与完整阴影标志尚未对齐。本轮不标为完整 MMD 外观验收。

交付时重新核对当前 GUI（PID 18180），其从 `project-update-20261007-08f90203/plugins/mmdtool/mmdtool.xdl64` 加载的 SHA256 与上述测试候选完全相同。通过正常文件打开命令展示新场景，保留用户原文档。GUI 模块身份已核对；原生图片、编辑事务的通过范围仍以独立进程收据为准。
