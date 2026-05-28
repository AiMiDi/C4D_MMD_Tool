## 1. 现状确认与 libMMD 测试

- [x] 1.1 阅读 `source/module/core/cmt_marco.h`、现有 VMD/PMX 导入入口和 `dependency/libMMD/src/libMMD/Model/MMD/VPDFile.*`，确认 SDK 兼容写法、文件选择方式、VPD parser 行为和 `MODEL_POSITION_MULTIPLE` 口径
- [x] 1.2 在 `dependency/libMMD/tests` 增加 VPD parser fixture/test，覆盖 SJIS 日文 bone/morph 名称、translation、quaternion、morph weight
- [x] 1.3 增加 VPD write/read round-trip 测试，并把测试接入 libMMD tests CMake
- [x] 1.4 运行 focused libMMD VPD tests，记录通过命令和结果

## 2. 插件导入入口与报告

- [x] 2.1 在 `source/cmt_tools_setting.h` 增加 `PoseImport` 设置，至少包含 document、filename，并按设计确认是否需要 `position_multiple` / detail report
- [x] 2.2 在 `source/cmt_tools_manager.*` 增加 `ImportVPDPose`，调用 `libmmd::ReadVPDFile` 读取 `.vpd`，处理文件读取/解析失败日志
- [x] 2.3 在 `source/CMTSceneManager.*` 增加 `LoadVPDPose`，校验 active selection 必须是 `MMDModelManagerObject`，失败路径沿用现有导入错误风格
- [x] 2.4 增加 `LoadVpdPoseLog` 或等价报告结构，记录 VPD bone/morph 总数、匹配数、未匹配 bone 名、未匹配 morph 名
- [x] 2.5 接通 `source/module/ui/cmt_tools_dialog.cpp` 的 `DLG_CMT_TOOL_POSE_IMPORT_BUTTON`，使用 `SelectSuffixImportFile(..., "vpd")` 并调用 `CMTToolsManager::ImportVPDPose`

## 3. 模型骨骼与 Morph 应用

- [x] 3.1 在 `MMDModelManagerObject` 增加 `LoadVPDPose`，从 BoneManager 的 bone list 构建 PMX 本地骨骼名到 `MMDBoneTag` / bone object 的映射
- [x] 3.2 为 `MMDBoneTag` 或 BoneManager 增加静态 pose 应用 helper，输入 VPD translation + quaternion，复用当前 bone pose 矩阵构造/dirty 逻辑，并尊重 `PMX_BONE_TRANSLATABLE`、`PMX_BONE_ROTATABLE`
- [x] 3.3 在应用 VPD bone pose 前处理模型模式边界，确保动画模式不会在导入完成后立即覆盖静态姿势，同时保留已有 VMD animation slots
- [x] 3.4 应用 VPD morph weight 时走 `MMDModelManagerObject` 的 morph 名称映射和现有 morph strength/update 路径，支持 mesh、bone、group、flip、material、impulse morph 的既有分发
- [x] 3.5 收集并上报未匹配 bone/morph；匹配项继续导入，不因部分未匹配整体失败
- [x] 3.6 导入完成后标记受影响 bone/morph/model 节点 dirty，刷新 UI，调用 `InvalidateStandaloneRuntime()` 并 `EventAdd()`
- [x] 3.7 调整动画模式 VPD 导入语义：不切到 EDIT，不覆盖动画槽，只把 VPD 应用为当前模型状态，并由模型管理器动画面板提供 VPD 导入入口。

## 4. 文档与验证

- [x] 4.1 更新 `docs/dev/import-flow.md`，补充 VPD 姿势导入链路、静态姿势语义、匹配规则和问题定位
- [x] 4.2 运行 `openspec validate add-vpd-pose-import --strict`
- [x] 4.3 运行根 CMake workflow 构建，优先使用 `cmake --build --preset workflow-dev`
- [x] 4.4 在 Cinema 4D 中手动验证：导入 PMX，选中 ModelManager，导入包含骨骼和 morph 的 VPD，确认姿势/morph 可见、未匹配报告可见、已有 VMD animation slots 未被删除
- [x] 4.5 检查 `git status --short` 和 staged diff，确保未提交 `old/` 变更或无关本地状态
