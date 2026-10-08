# RS 2026.9 高光与基础参数同步验证

日期：2026-10-07。证据根目录：
`_build_msvc/validation/rs-toon-material/rs269-20261007-9deb5a4e/`。

## 环境与模块

- Cinema 4D 2026.4.0 / Redshift 2026.9.0。
- SDK 2026 Release 候选 SHA256：`9deb5a4e94a206bb114f0938877bff75e70cc768389bfb68660f9a115c914e2c`。
- SDK 2026、2024、R20 Release 编译通过；三个现有材质/Morph/fixture CTest 通过。
- 使用隔离 c4dpy 进程，经生产导入接口创建测试材质。启动授权选择使用 `g_licenseModel=LICENSEMODEL::MAXONAPP`；不在脚本或日志中传入账户密码。
- 用户确认保存并允许重启后，GUI 已重启并通过进程模块路径核对加载了上述候选和 RS 2026.9。重启前的三个打开文档另存恢复副本。

## 实际修复

1. **测试渲染等待**：新文档已带一个 RS VideoPost，原型又无条件插入一个。两个 RS 节点进入 `Busy:Render Waiting until idle`；同一六球场景去重后在独立进程成功渲染。共享测试帮助函数改为复用已有节点，发现重复节点立即报错，不删除不明渲染设置。此因果对照解释本轮测试渲染等待，不解释全部历史启动退出。
2. **遮罩硬切换**：颜色渐变节点的插值 ID 应为 `linearknot`。早期候选设置的 `linear` 属于另一类样条，虽然节点接受该值，实际画面会变成硬高光。源码和原生断言均已修正。

## 高光图像

维护入口：`tests/material/native_toon_specular_test.py::run(c4d, output)`，仅在任务自有的无界面进程运行。

六球场景使用正式导入生成的 revision 3 配方，30 个角色、13 个属性通过原生断言。上排仅将遮罩插值回退为错误 ID，下排保持生产图。三列分别为零 Specular、Power 8、Power 64；非零 Specular 为 `(0.5, 0.5, 0.5)`。球体有 Phong 法线，一盏方向光，GI 关闭。

GPU 和 CPU 均渲染保存重开的同一场景，两者均返回成功。低 Power 高光蓝通道有 167 个不同值，修复后出现连续过渡。固定 ROI/阈值下高光区域由 Power 8 的 1745 像素收窄为 Power 64 的 744 像素；零 Specular 的高光像素为 0。两设备最大通道差为 1/255。这是该固定样例的结果，不能推广为全部场景的设备等价。

本测试使用原生 User Data reader 的默认值隔离着色配方，不把它算作网格属性驱动的 Morph 图片矩阵。完整任务 5.2 仍未完成。

## 基础参数同步

`candidate/native-result.json`：Standard、RS Standard、RS Toon 三种类型全部通过 `base_parameter_binding`，此次 `authoring_metadata_verified=true`。

直接修改 MMD 属性后检查基础值、材质名称、RS reader 默认值；叠加预览后关闭会恢复基础值，图节点集合保持不变。与上一轮只验证旧加载模块的结果分开。本轮未扩大为 GUI Undo/Redo 全矩阵的通过结论。

## 真实 PMX 与剩余范围

重新从 `C:\白银之城—阿芙2.0\阿芙2.0.pmx` 走生产接口导入，35 个材质通过 revision 3 结构及线性遮罩断言。

另在任务自有场景测试了 `Texture → Matcap → Add → Toon Base Color`。此为球面贴图实验图，未并入生产适配器，也未声称完成 MMD Sphere 的混合顺序、色彩空间、相机映射及 Morph 语义。实验材质手工改变受管理连线，因此不将它用于自动同步验收。该实验不会消除生产材质的 Sphere 未映射诊断。SubTexture / Additional UV 仍不进入默认路径。

真实模型采用新导入静止姿态、单方向光、固定正面相机。与用户 PmxView 截图的曝光、色彩管理及精确光向尚未对齐，阴影分层仍较硬，不能称为 MMD 外观验收完成。基础、球面贴图实验以及六球场景均已在用户 GUI 文档列表中打开。
