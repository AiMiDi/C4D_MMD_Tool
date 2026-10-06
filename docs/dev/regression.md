# 原生运行时回归与验收证据

独立测试验证算法、输入文件和回执规则；Cinema 4D 原生测试进一步验证对象链接、动态属性、场景持久化、
动画求值、物理重建和材质恢复。编译成功或输入测试通过，都不代表 C4D 运行时验收通过。

仓库的 `cmt-plugin-tests` 入口同时执行 C++ 算法测试与 Python fixture。
纯 Python 检查不依赖 `libMMD` 编译目标，因此使用预构建依赖或独立测试工程时也会注册；
需要实际 `libMMD` 的 C++ PMX/VMD 输入回读测试仍只在对应目标可用时注册。
Python 检查覆盖输入/回执契约、测试文档归属和失败清理、依赖源码/选定链接库身份、
材质图像断言及 MCP 适配器。2026-10-06 的离线复核为运行时脚本 48、材质 20、适配器 35 项通过，
预构建依赖测试图的 CTest 为 13/13 测试组通过；这些均不代替下文的原生执行证据。

`scripts/c4d_runtime_regression.py` 在 Cinema 4D 内执行九项回归。每项测试都使用新的测试文档，读取由仓库内
Python 代码生成的 PMX/VMD 输入，并将断言结果和实测值写入 JSON 回执。测试结束后恢复用户原先的活动文档。
某项测试失败时，会记录异常堆栈，随后使用新的测试文档继续执行下一项。

## 构建与准备

常规构建默认关闭原生测试桥。测试构建需要显式开启：

```powershell
cmake --preset dev-windows -DCMT_ENABLE_RUNTIME_REGRESSION=ON
cmake --build --preset workflow-dev
python scripts/c4d_runtime_regression.py --prepare `
  --output S:\tmp\cmt-runtime-regression `
  --sdk sdk_2026 `
  --binary _build_msvc\sdk_2026\bin\Debug\plugins\mmdtool\mmdtool_Debug.xdl64
```

完成构建后再准备 manifest；修改源码或二进制后，需要重新准备。manifest 记录 Git revision、工作区修改、
源码和资源 SHA-256、SDK 标识、插件二进制 SHA-256、解析后的资源 ID，以及输入文件路径和 SHA-256。
生成的模型包含三个顶点、四根骨骼及一条 IK 链、一份材质及材质颜色表情、两个刚体和一个关节。两份动作具有
不同的骨骼姿势、表情强度、模型可见性和 IK 启用状态。另生成一份引用白色 toon ramp 的 PMX，
以及由 Python 写出的 2 × 4 BMP，用于发现误把阴影 ramp 转成发光的回归。测试不依赖外部模型资产。

等待构建或 C4D 安装时，可以省略 `--binary`，先生成输入。此时 `receipt.json` 将全部原生测试标为 `pending`，
并设置 `native_executed=false`、`acceptance_eligible=false`。准备输入不会产生运行时通过结果。
要生成符合验收条件的原生回执，必须提供插件二进制。

## 在 Cinema 4D 内运行

正常启动 Cinema 4D，并加载新构建的插件目录。需要调试时，按仓库说明正常启动后再 attach；本测试流程不使用
LLDB/DAP 直接启动 C4D。

在 Script Manager 中运行以下入口，按实际工作区位置调整路径：

```python
import os
import runpy

os.environ["CMT_REGRESSION_MANIFEST"] = r"S:\tmp\cmt-runtime-regression\manifest.json"
runpy.run_path(r"C:\code\C4D_MMD_Tool\scripts\c4d_runtime_regression.py",
              run_name="__main__")
```

测试桥使用 CMTSceneManager 的插件 ID 作为无数据自定义节点消息。Python 把带协议版本的标量请求写入
scene hook 的 BaseContainer，再调用 `hook.Message(1057017)`。C++ 回调只存在于开启
`CMT_ENABLE_RUNTIME_REGRESSION` 的构建中，并且只分发固定的导入、导出及表情操作。
桥接不可用或协议版本不同时，握手明确失败。测试桥略过文件选择和成功提示对话框，调用交互工具使用的
场景和模型序列化逻辑。

## 原生断言

| 测试 | 必须取得的原生证据 |
|---|---|
| `import_save_reopen` | PMX 和 VMD 导入、骨骼动画姿势、C4D 保存重开后的相同求值姿势 |
| `mode_bind_restore` | EDIT → ANIM 提交编辑后的 bind position，ANIM → EDIT 恢复，保存重开后保持 EDIT 状态；ANIM 固定帧骨表情强度及偏移立即更新骨骼和蒙皮，归零恢复且 frozen bind 不变；重开后滑块仍能驱动 tag；源文档与副本独立调节；启用物理后固定帧调节不额外推进动态骨骼 |
| `hierarchy_edit_and_selectors` | 重设父级、同层重排、新增、复制、删除后的 DFS 索引及 parent index；每次修改后的 rigid、joint、display frame 骨骼下拉列表 |
| `hierarchy_export_and_anim` | PMX 骨骼顺序和 parent index 与原生同步结果一致；层级编辑和重开后 VMD 姿势仍正确求值 |
| `animation_slots_and_options` | 追加导入创建不同动画槽，替换保留槽标识；切槽及保存重开后姿势、材质表情插值和可见性不同；关闭 model-info 导入和导出后行为正确 |
| `physics_toggle_and_reopen` | 连续物理求值有限且与关闭物理时不同，保存重开后能重现连续求值结果，关闭物理后恢复动画结果 |
| `material_morph_zero_and_delete` | 表情改变实际标准材质 shader；强度归零和删除活动表情都恢复基础颜色，重开后不再残留颜色；混合表情顺序改变后，Group 前向引用和 display frame 的 Morph 引用仍指向 tint；toon 导入不启用发光，表情同步不重新启用；导出及重开保留 toon 元数据；旧误建发光只迁移一次，用户自定义发光保持 |
| `motion_roundtrip_and_bake` | 稀疏 VMD 帧和值保持不变，重新导入后姿势相同，逐帧骨骼及表情烘焙值与原生连续播放一致；源文档姿势、材质、时间和模式不变；拒绝导入回滚后保持原状态且仍能再次导入 |
| `camera_export_and_failures` | 相机 VMD 文件头、插值、烘焙帧数及实际垂直 FOV；相机复制后的真实子对象和导出结果；旧 APERTURE 曲线的单次迁移、值切线缩放和保存重开；普通相机 APERTURE 轨道保留；导出无多余对象且时间不变，文件写入失败和负帧导出返回失败 |

两项层级测试覆盖 `openspec/changes/bone-hierarchy-index-sync/tasks.md` 中的三项验收场景，
并检查删除被引用骨骼后的 display frame、刚体、关节选择和 indexed tail 引用解除。
只有测试在指定的实际加载插件二进制上通过后，才能把对应任务标为已验证。

相机 AOV 现在使用 `CAMERAOBJECT_FOV_VERTICAL` 的弧度值。`CAMERAOBJECT_APERTURE` 表示传感器宽度，
旧实现把 VMD 视场角的度数写入该参数，无法得到对应的实际视场角。VMD 相机求值器本身提供弧度，导入时直接
写入垂直 FOV；导出时换算并四舍五入为 VMD 整数度数，避免浮点误差使 45° 往返后截断为 44°。

MMD 相机根对象的隐藏 `MMD_CAMERA_ANIMATION_SCHEMA_VERSION` 字段记录动画轨道版本，版本 1 表示垂直
FOV 弧度轨道。仅当旧根对象缺少版本标记、子相机具有 MMD 生成对象 UniqueID、存在带关键帧的 APERTURE 轨道，
并且没有垂直 FOV 轨道时，才会自动迁移：先克隆轨道，转换关键帧值和左右值切线的度数单位，保留时间、时间
切线、插值方式、关键帧标志及循环设置，准备成功后替换旧轨道，并持久化版本标记。重复加载不会再次缩放。
普通相机的艺术家 APERTURE 轨道不参与迁移；已经具有垂直 FOV 轨道的生成子相机优先保留其现有轨道。

C4D `GetClone()` 会丢弃 `AddUniqueID()` 数据。生成子相机还会在自身持久化 BaseContainer 中，以 MMD 相机
插件 ID 存储角色标记；复制后根据该标记识别真实的生成子对象，并重新注册 UniqueID。普通相机没有该标记，
不会因为是根对象的第一个子相机就被选为生成对象。原生复制测试检查只有一个真实子相机、角色标记与
UniqueID 重建，以及原动画和 FOV 保持一致。

原生测试会检查实际垂直 FOV 参数、45° 导入、60° 普通相机导出、旧轨道及值切线迁移、重复运行、复制、保存
重开和普通相机轨道保留。源码和纯数学测试通过仍不足以证明这些 C4D API 路径已经执行；必须取得实际加载
插件的原生回执。当前测试也不包含视口截图、最终渲染画面或摄影机世界变换的视觉对比验收。

## 回执含义

测试在准备目录下逐步写入 `receipt.json`、保存的 `.c4d` 场景和导出的 PMX/VMD 文件。单项测试结果为
`passed` 或 `failed`，并记录 `native_executed`、时间和断言证据。只有全部必需测试通过，而且实际加载的插件
二进制身份已确认时，总体结果才是 `passed`。`identity_unverified` 表示断言通过，但指定二进制身份不可确认
或哈希不匹配。运行环境尚未安装时保留 `pending_native_runtime`，不计为跳过后通过。

Windows 上，测试脚本枚举自身 C4D 进程的模块，并计算实际加载的 `mmdtool*.xdl64` 哈希。manifest 中的路径
或构建成功都无法证明 C4D 已加载该二进制。实际进程模块哈希必须与 manifest 匹配，才能得到
`acceptance_eligible=true`。当前脚本尚未提供 macOS 的实际加载模块身份验证；该平台可以收集单项结果，
但总体身份保持未验证，直到补齐对应的模块验证路径。

每次导入前都会检查输入文件身份。需要长期保留的回执应复制到 `S:\tmp` 之外，因为该目录可能独立于仓库被清理。

## 独立验证

```powershell
python tests/runtime/test_regression_contract.py
```

这些测试验证输入生成的一致性、PMX 拓扑、不同动画及元数据状态、相机文件头、错误或截断输入拒绝、资源 ID
解析、原生测试待执行回执、输入改动拒绝、测试桥缺失时明确失败，以及原始空白文档被关闭后的清理。
它们无需安装 C4D。

在包含 `libMMD` 的依赖测试 CMake 配置中，`cmt_runtime_fixture_test` 进一步使用实际 libMMD 读取器解析全部
生成文件，并通过 `VMDCameraAnimation::Evaluate(1.f)` 求值相机中间帧。回执规则测试也参与 CTest。
`camera_fov_test` 还验证 1°–179° 经过 float32 弧度的往返、值切线单位转换，以及无效视场角拒绝。
这些独立检查验证测试输入、数学规则及证据流程；上述原生断言仍需在 Cinema 4D 内实际执行。
