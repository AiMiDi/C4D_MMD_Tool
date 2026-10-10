# 动作适配与控制器联合验收，2026-10-10

“评估PMX模型一键绑定兼容性”已完成实现、验证和归档；提交 `b4000dcb`、`e78b443b`、`6df5c6dd` 已汇总到动作适配分支。本次使用联合源码重新构建并加载 C4D 2026 Release 模块，未用旧 DLL 代替原生验收。发布进度和实际引用见 [receipt.json](receipt.json)。

## 联合复核发现并修复的问题

1. 控制器辅助函数创建临时 `BaseLink` 后，`GeData` 复制链接却没有释放原分配。两处辅助函数现在在复制后释放临时链接；控制器的持久链接和动画输入通过原生回归。
2. 新 IK 缓存契约修复后，原生与离线姿态仍有超过测试容差的膝部差异。共享 CCD 的两条路径使用 `acos(float dot)`，近共线时损失了小角度。改为原向量 double 点积、叉积的 `atan2`，保持原迭代次数、方向选择、关节限制和停止阈值。没有硬编码场景倍率。

第二项的[隔离调查](ccd-stability/README.md)包含旧实现负向回归、分别只修改一条路径的对照和完整修复；不能将该调查追溯为旧 AVX2 接触差异的唯一原因。

## 最终模块验证

- C4D 2026.4，场景倍率 8.5；模块 SHA256 `734d012adb15e4418db5907b0d4491372b9079499ac5b707c89a515217578a09`，runtime regression bridge 为 OFF。
- 生产 stdio MCP sizing：27 项通过，含角色批量、动作槽输入、全部阶段预览、导出覆盖保护、应用与撤销／重做、存档重开、过期绑定拒绝、句柄释放和文档恢复。
- 用户素材 Sour → 阿芙 / Stay Tonight：16 项通过，含全部高级选项和腿部避让、8 阶段预览、整数及非整数帧播放、导出动作／相机、播放后应用、保存重开，以及真实 IK 迭代参数编辑会拒绝旧结果、恢复后允许应用。
- 实际调整后 VMD 与原生播放器比较 8 个帧、16 个骨骼，共 128 个唯一位置和 224 次采样；最大差异 **0.002595 场景单位**，小于预设 0.085。重复／跳帧最大位置差异约 `8.84e-14`。原来的失败结果保留在调查记录中。
- 当前调整后动作上的控制器工作流 72 项通过；原生 PSR、IK 与物理开启／关闭组合 90 项通过，覆盖同帧稳定、约束释放、撤销、存档重开和普通 Joint 对照。
- 已生成且有非零手部输入的 85 个控制器：计算快照和应用均保留输入；没有错误的绑定过期拒绝。
- 核心 16 项功能 CTest、插件 23 项无 SDK 测试、MCP 42 项测试通过。独立 AVX2 IK 测试 828 个断言通过；冻结旧实现下 12 个新增近共线残差断言全部失败。

机器可读结果在本目录；素材本体和大型测试工程未加入仓库。测试使用独立持久偏好目录，MCP 端口 5570。只结束本次拥有的测试进程，保留其他 C4D 会话及原工作区无关脏文件。

## 边界

原生验证范围是 Windows / C4D 2026.4 和所列素材及采样帧。其他 SDK／平台由发布 CI 编译验证，不能作为旧主机原生运行验收。深度腿部穿插、复杂衣物碰撞和所有角色的完全接触仍不保证全部解决；跨帧候选原型尚未集成。现有 README 的效果图属于已注明的前后对比，不是本轮全部素材的验收证明。

取消测试中的短小 fixture 可能先完成计算；验收要求取消请求不会自动应用结果。该终态保存在生产 MCP 回执中。

## 发布流水线补漏

首次标签 `v0.9.3.4` 的功能检查发现，新 `pmx_vertex_weights_test` 已注册到 CTest，但根 `cmt-deps-test` 没有构建该可执行文件。该尝试未生成 Release。现已补入构建依赖；用全新 Debug / AVX2 根构建实际执行聚合目标，核心 16 项和插件 26 项全部通过。插件聚合包含两项核心 sizing 和 runtime fixture，不能与核心数量相加当作独立覆盖。使用新版本 `v0.9.3.5` 重跑，不覆盖失败标签。

`v0.9.3.5` 的 Main Build 已成功；Package 首次运行中，Mac Intel R25 的编译成功，但 GitHub 托管 runner 上传 artifact 时发生 `ENOTFOUND` DNS 错误。原始步骤见 [ci-artifact-upload-failure.txt](ci-artifact-upload-failure.txt)。当时活动流水线拒绝单项重跑；待全部结束后，在同一标签和源码上重跑失败任务成功，没有更换标签或修改算法来处理基础设施错误。

## 正式发布核验

正式发布 [v0.9.3.5](https://github.com/AiMiDi/C4D_MMD_Tool/releases/tag/v0.9.3.5)，来源提交 `a15230c7156221e45cded3afbcf1ccf12228f51b`，libMMD `577c46d122c1276d198e1fd9f3cedb04dab93348` 已核验远端可达。

Main Build 与 Package attempt 2 均成功，21 个 SDK/platform 矩阵全部通过。首次 R25 artifact 上传 DNS 失败在同源码重跑后恢复，没有修改或覆盖标签。完整作业记录见 [release-ci.json](release-ci.json)。

下载并核验正式 Release 的 9 个资产，文件大小和 SHA256 全部与 GitHub digest 一致。Windows 安装包 ProductVersion 为 `0.9.3.5`；8 个 Mac Intel ZIP 的 CRC、Mach-O x86_64 架构、真实资源、许可证通过；8 个 Windows SDK 输入的 PE x64 架构、真实资源、许可证及全部 MCP 入口源码与发布提交一致。见 [artifact-audit.json](artifact-audit.json)。本轮未执行正式安装包，也未安装至用户 C4D；发布核验不扩大上文原生测试范围。

源码文本核验只统一 Windows Git 检出的 CRLF 为 LF，其余字节必须一致；资产 SHA256 按原始字节核验。Inno 版本资源带有尾部填充空格，回执同时保留原值和去除填充后的 ProductVersion。

本地包位于 `output/release-audit-0.9.3.5-20261010/`；实际测试工程为 `output/joint-release-20261010/Afu-motion-sizing.c4d`。双语 Release 说明及 README／CHANGELOG 发布状态已补齐。
