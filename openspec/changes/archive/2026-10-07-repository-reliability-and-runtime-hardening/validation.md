# 验证记录

日期：2026-10-06。工作区：`C:\code\C4D_MMD_Tool`。

本记录区分源码与工作流检查、独立测试、插件编译、打包和原生 Cinema 4D 验收。
临时日志与回执已另存到仓库忽略的 `_build_msvc/validation/repository-reliability-and-runtime-hardening/`，
其中包含 `native/` 场景、导出文件、输入、原始 manifest/receipt，以及 `logs/` 和 `native-crash/`。
原始回执中的路径保留实际执行位置 `S:\tmp`；归档副本不改写历史证据。重新运行应重新 prepare manifest。

## 构建环境与已完成编译

- CMake：`C:\Program Files\CMake\bin\cmake.exe`。
- 已验证的插件构建图使用 `Visual Studio 18 2026` / `v143`，MSVC `19.38.33145.0`。
- CI Windows 构建使用 `windows-2022` / Visual Studio 2022 / v143。两者工具链环境有区别，本机结果不替代远端 CI 执行结果。

以下是原生回归补丁之前已经完成的编译。后续原生发现导致的源文件修改，需要在本记录末尾追加同源构建与运行身份；不能把先前编译成功当作新补丁已经加载。

| 构建 | 回归桥接 | 产物 | 证据 |
|---|---|---|---|
| SDK 2026 Debug | ON | `_build_msvc/sdk_2026/bin/Debug/plugins/mmdtool/mmdtool_Debug.xdl64` | [configure 日志](/S:/tmp/cmt-reliability-sdk2026-configure.log)、[build 日志](/S:/tmp/cmt-reliability-sdk2026-debug.log)、[实际缓存](/C:/code/C4D_MMD_Tool/_build_msvc/sdk_2026/CMakeCache.txt) |
| SDK 2026 Release | OFF | `_build_msvc/sdk_2026_release/bin/Release/plugins/mmdtool/mmdtool.xdl64` | [configure 日志](/S:/tmp/cmt-reliability-sdk2026-release-configure.log)、[build 日志](/S:/tmp/cmt-reliability-sdk2026-release.log)、[实际缓存](/C:/code/C4D_MMD_Tool/_build_msvc/sdk_2026_release/CMakeCache.txt) |
| SDK R20 Debug | OFF | `_build_msvc/sdk_r20/bin/Debug/plugins/mmdtool/mmdtool_Debug.xdl64` | [configure 日志](/S:/tmp/cmt-reliability-sdk-r20-configure.log)、[build 日志](/S:/tmp/cmt-reliability-sdk-r20-debug.log)、[实际缓存](/C:/code/C4D_MMD_Tool/_build_msvc/sdk_r20/CMakeCache.txt) |

R20 构建中有 SDK math header 的既有 C4756 警告，插件链接与资源同步成功。
本次未执行其余六个兼容 SDK 的完整编译，也未执行 macOS 构建。

## 独立测试与资源验证

| 验证 | 结果 | 证据 |
|---|---|---|
| libMMD 功能 CTest | 13/13 通过，排除 benchmark/performance | [执行日志](/S:/tmp/cmt-reliability-deps-build.log) |
| 插件算法、协议和文件 fixture CTest | 8/8 通过 | [执行日志](/S:/tmp/cmt-reliability-plugin-tests.log)、[最新 LastTest.log](/S:/tmp/cmt-reliability-root-tests/tests/Testing/Temporary/LastTest.log) |
| 真实资源复制 fixture | 9/9 通过 | [执行日志](/S:/tmp/cmt-final-resource-check.log)、[receipt](/S:/tmp/cmt-final-resource-check/d1354dafa1c34c54baa9ec8dd2befe1c/receipt.json) |
| 实际 pinned setup 脚本适配 | 6/6 通过 | [pinned 输入副本](/S:/tmp/cmt-installer-pinned-source.iss)、[receipt](/S:/tmp/cmt-installer-resource-checks/cf4016be97a740f5837a9aa30376780a/receipt.json) |
| CI 独立安装脚本 fixture | 6/6 通过 | [receipt](/S:/tmp/cmt-installer-resource-checks/1f965e9e1f4942e8ac1059401e4c215f/receipt.json) |

8 个 CTest 包括骨骼执行计划、材质表情代数、阶段计时、模型信息动画、动作输入校验、相机 FOV、原生 receipt 契约，以及 libMMD 解析确定性 PMX/VMD fixture。
它们验证算法、文件和验收协议；不验证 C4D 对象加载、材质渲染、Undo 或场景保存重开。

资源 fixture 覆盖新输出、重复同步删除旧文件、reset/preserve 策略、无效 JSON 保留旧输出、旧 Junction 的安全替换、输出祖先链接和越界路径拒绝、旧资源补配置，以及源资源链接拒绝。
已另外执行 SDK 2026 实际生成的 runtime command wrapper：即使 `maxon_Target` 仍是 SDK 输入 Junction，也从固定的根资源树生成真实副本；源配置 SHA 不变。独立输出位于 `_build_msvc/sdk_2026/runtime-resource-hook-check/res`。
隔离 CMake 原生复制路径也通过，脚本为 [cmt-runtime-hook-test.cmake](/S:/tmp/cmt-runtime-hook-test.cmake)；这是本机脚本验证，不等于实际 macOS 主机构建。

可重复执行的本地验证入口：

```powershell
& 'C:\Program Files\CMake\bin\cmake.exe' --build S:/tmp/cmt-reliability-deps --config Debug --target cmt-deps-test
& 'C:\Program Files\CMake\bin\cmake.exe' --build S:/tmp/cmt-reliability-root-tests --config Debug --target cmt-plugin-tests
pwsh -NoProfile -File scripts/check_runtime_resources.ps1
pwsh -NoProfile -File scripts/check_installer_resources.ps1
```

Benchmark 提供独立目标 `cmt-deps-benchmark` 和独立 workflow job，本次未执行性能测试，因此没有同质量性能提升结论。

## CI、预设和打包命令检查

- `build.yml` 的 PR/main 路径包含资源复制 fixture、安装脚本适配 fixture、libMMD 功能 CTest、插件 CTest 和 SDK 2026 Release 编译。
- tag 发布调用和手动运行包含完整 21-job SDK/platform 矩阵；benchmark 为显式选择的独立 job。
- checks 和 matrix checkout 都使用 `inputs.ref || github.ref`，避免 reusable workflow 的 caller event 使请求的 ref 被忽略。
- 依赖缓存身份包含 runner/platform、目标架构、Release 配置、compiler/CMake 版本、递归子模块版本以及依赖和工作流选项文件。
- `release-windows`、`release-macos`、`package-windows` 明确将 runtime regression bridge、插件测试和依赖测试设为 OFF，避免已有测试缓存影响生产构建。
- 已解析 workflow YAML、configure/build preset JSON；已断言 Release preset 配置和 production 测试开关。已运行 scoped `git diff --check`。

以上检查与本机命令足以支持 task 2.3 的工作流实现及本地检查完成。远端 GitHub Actions 尚未触发，完整发布矩阵不记为已运行。

Windows 默认打包在 ISCC 前执行 `cmake/prepare_installer_resources.ps1`，仅适配 `setup/Common/installer_script.iss` 中唯一的已知旧资源 Source。
已适配的 Source 保持不变；旧/新重复、未知 Source 和自定义路径均拒绝写入。
因此 fresh checkout 可以使用当前固定的 setup 子模块版本消费构建资源，无需先提交本地 setup 修改或推进子模块指针。
自定义 `CMT_ISS_MAIN` 的本地打包图不调用该适配，自定义安装脚本自行负责完整资源来源。

默认与自定义两套根工程图已经在隔离目录 configure，并检查生成的 `cmt-package.vcxproj` 命令：

- [默认图](/S:/tmp/cmt-installer-default-graph/cmt-package.vcxproj)：包含资源适配命令。
- [自定义图](/S:/tmp/cmt-installer-custom-graph/cmt-package.vcxproj)：豁免资源适配。
- [图检查 receipt](/S:/tmp/cmt-installer-graph-check-receipt.json)、[综合验证 receipt](/S:/tmp/cmt-installer-final-validation.json)。

这两套图仅用于配置及命令检查，ISCC 路径使用存在的占位 executable，未执行任何 build target 或安装编译。
本机 PATH、常规 Program Files 安装位置、卸载注册表、用户 LocalPrograms 和 Chocolatey bin 未发现 ISCC；本次没有 Inno 实际安装包或安装验收。
macOS 打包配置直接消费完整产物已有的 `res/`，不会再次复制生成嵌套资源目录；本次未在 macOS 执行 zip job。

## 原生 Cinema 4D 与原生发现后的补编译

最终原生运行完成于 `2026-10-06T06:23:38Z`，宿主为 Cinema 4D **2026.4.0**。
通过正常启动参数 `g_additionalModulePath=C:\code\C4D_MMD_Tool\_build_msvc\sdk_2026\bin\Debug\plugins`
加载插件，再通过 C4D 自带 MCP 的 `exec_python` 在主线程执行维护脚本。未使用 LLDB 直接启动。
本会话未热加载新配置的 MCP 工具，因此使用同一本地 HTTP 服务及其本机 token 完成调用。
MCP 调用成功，测试后原活动文档已恢复。

实际进程模块 SHA-256：`781b176cfe1cbc638b787e4f1b13078e420ab74a13cdc041db3606277c83c401`。
源码和资源 SHA-256：`454620e919f2d87ff933fbaeb55ca260ff4d2194c0b4941c7e58602e9d4a6aec`。
Debug 回归桥为 ON；Release 和 R20 构建为 OFF。原始清单与实际模块哈希相符。

九项原生回归全部通过，回执为 `status=passed`、`binary_identity_confirmed=true`、
`acceptance_eligible=true`。证据在
[native receipt](/C:/code/C4D_MMD_Tool/_build_msvc/validation/repository-reliability-and-runtime-hardening/native/receipt.json)
和同目录的 manifest、输入、`.c4d`、PMX/VMD 导出文件及 MCP 调用结果中。

原生发现后的修复已由这轮运行覆盖：

- 材质表情在刷新时保留；归零、删除和重开恢复基础颜色。动画 A/B 的表情插值、切槽及两个槽保存重开均保持。
- 初始 PMX 索引转换、重排/复制时对象身份映射，以及末端骨骼删除的 hierarchy checksum 检测；display frame、rigid、joint 选择和 indexed tail 引用解除正确。
- 混合表情由输入 `[bone_pose, group, tint]` 转为导出 `[group, tint, bone_pose]`，Group 前向引用和 display frame 的 Morph 引用均仍指向 tint。
- 相机克隆用持久角色标记识别实际子相机并重建 UniqueID；不再生成额外子相机。实际 FOV、旧轨道迁移及相机保存重开均通过。
- 表情克隆保留动态 DescID 及原轨道插值；烘焙实际权重为 `0/.5/1`，源材质、姿势和时间不变。
- 拒绝导入后的 Undo 曾使下一次导入使用旧 manager 缓存而崩溃。CopyTo 现清空管理器缓存及层级索引缓存，只重置自身运行时对象；后续导入重新绑定管理器。失败回滚保持原状态，并且再次有效导入通过。

访问冲突报告和 minidump 保留在 `native-crash/`。报告调用栈位于
`HashMap::GetNonEmptyBucket → MMDBoneManagerObject::EnsureAllAnimationSlotCount → LoadVMDMotion`。
Rider 当时未打开本仓库，未取得该项目的附加调试值；诊断使用 C4D 自身崩溃报告、已释放内存特征、
导出文件和失败前后的操作顺序，修复结论由最终同源原生回归验证。

上述源文件修复后，SDK 2026 Debug、SDK 2026 Release、R20 Debug 均重新编译并链接通过。
最新日志在验证目录 `logs/cmt-final-verified-{debug,release,r20}-build.log`。
插件 CTest 最新仍为 **8/8**，Python 回执/输入契约包含 **13** 个子测试；真实 libMMD fixture 还解析混合 PMX 输入。

本次未执行真实生产资产、最终渲染/视口视觉对比、同质量性能比较、其余 SDK、macOS、远端发布矩阵或 Inno 实际打包。
阶段计时和执行计划缓存已有实现及独立测试；本轮不据此宣称实际性能提升。

MMD 插件默认不提供独立 MCP 服务。C4D 宿主 MCP 可使用通用对象/参数及 Python 工具；本次使用的
`CMT_ENABLE_RUNTIME_REGRESSION` 测试桥常规构建默认关闭，不是生产 MCP 工具集。

## 最终集成校验

本 change 及旧 `bone-hierarchy-index-sync` 的 OpenSpec strict validation 通过；完整 `git diff --check` 通过。
19 项实施任务全部完成，旧骨骼层级 change 的三项原生验收已勾选。
Bullet/libMMD 子模块保持原固定提交且工作区干净；setup 仅有两行资源 Source 的本地调整，未推进子模块指针。
所有修改保留在当前工作区，未创建提交或推送。

## 真实资产与材质修复复验

在用户提供的阿芙、枪、箱子 PMX 和 Stay Tonight 动作/相机 VMD 上继续验证，发现并修复了三处问题：

- Standard adapter 把白色 toon 阴影 ramp 接入 Luminance，造成材质整体发白。同模型、同视角的单变量对照
  只关闭该通道，就恢复了头发、衣服和装饰颜色。新导入和 CreateFromData 不再建立这条发光连接；旧默认
  toon Bitmap/wrapper 在显式材质同步时执行一次保守迁移，保留 shader。用户自定义发光和 PMX toon 元数据保留。
- 固定帧骨表情强度/偏移变化没有进入完整骨骼求值门控。现在校验实际 tag 的强度、平移/旋转定义和数量，
  同帧重新求值前后骨阶段，清旧 IK/append override；已有物理状态只重新反映，不额外推进 Bullet 或提交 bind。
- 骨表情 tag 数据能够持久化，但 BoneManager 的运行时 hub 映射在 Read/CopyTo 后没有恢复。现在从本地骨
  层级的 tag 定义重建，避免复制源文档裸指针；重建失败清旧映射并保留重试标记。

本轮最终源码/资源 SHA-256 为 `587f461fe080c9cce3bca8ebe0c7f0a4f818211dca1fe489ffa728e78c182bc9`。
Cinema 4D 2026.4.0 实际加载的 Debug 插件 SHA-256 为
`62f2b1361ba3ac84571bed19ab37dd83a0e2546d8ca3aee371b64dbe9e7fed9a`。
SDK 2026 Debug、SDK 2026 Release 和 R20 Debug 均已对本轮最终代码重新编译通过。

| 验证 | 结果 |
|---|---|
| 九项公开 fixture 原生回归 | 9/9，通过；实际二进制身份确认，原活动文档恢复 |
| 真实 PMX 导入、模式、表情、保存重开 | 14/14，通过；包含箱子骨表情在导入和重开后的同帧 0/1/0 |
| 真实动作与相机 | 6/6，通过；动作 8 个采样帧，相机 84 个切镜/插值采样 |
| 插件算法/文件/协议 CTest | 8/8，通过 |
| Python 回执/fixture 契约 | 15/15，通过 |

公开原生用例已加强到固定帧骨表情、Read 后重新调节、直接 offset 编辑、源文档/副本独立调节、冻结 bind
保持，以及物理连续推进后同帧调节不额外推进动态骨骼。蒙皮几何在所属文档重新求值后比较；作者侧刚体
对象的变换与实际模拟骨骼的变换分别记录。旧版本复现和数值探针保留在 diagnostics 中。

阿芙导入包含 70,222 顶点、95,290 面、625 骨骼、35 材质、479 刚体和 748 关节；修复后实际材质中的
toon 发光通道为关闭状态。保存重开的最大顶点差为 `1.7686932781387731e-7`，低于全点 `1e-5` 验证容差。
动作导入接收 7,251 骨骼关键帧，匹配 46 个表情的 480 个关键帧；同帧保存重开最大骨矩阵/顶点差分别为
`2.3863878678698214e-8` / `2.4381012377422875e-8`。
相机源 93 个关键帧展开为 1,691 个逐帧关键帧，导出重导入的采样矩阵与 FOV 最大差均为 0。

本轮证据在仓库忽略的
[summary](/C:/code/C4D_MMD_Tool/_build_msvc/validation/real-assets-and-materials/summary.json)、
[native receipt](/C:/code/C4D_MMD_Tool/_build_msvc/validation/real-assets-and-materials/native/receipt.json)、
[model receipt](/C:/code/C4D_MMD_Tool/_build_msvc/validation/real-assets-and-materials/real-model/receipt.json) 和
[motion receipt](/C:/code/C4D_MMD_Tool/_build_msvc/validation/real-assets-and-materials/real-motion/receipt.json) 中。
同目录保留对照图、派生测试场景、公开生成输入、实际使用的 harness 快照和构建日志。
三个原 PMX 和两份原 VMD 的 SHA 均保持不变，没有提交或发布私有资产。

当前前台阿芙材质工程使用与 Standard 材质匹配的 Standard 渲染器。视口颜色及 Standard 预览已检查，
完整 MMD toon 着色和 Redshift 最终渲染未验收。真实动作有四个非零辅助骨通道未匹配阿芙 rig，精确复现
需要显式重定向；真实模型的完整连续物理、同质量性能和其余平台仍不在本轮抽样验收范围内。
