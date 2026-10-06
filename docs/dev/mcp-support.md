# 生产 MCP 支持：实现与验收状态

状态：**生产 API、16 个 typed tools 和 stdio 适配器已实现；Windows 普通 Release 的八阶段原生验收通过，跨平台发行验收尚未完成**。
本页状态核对日期为 2026-10-06，不表示 GitHub 已发布的安装包已经包含这些改动。
本轮按模块提交时，Python 客户端、测试及构建资源已分别固化；C++ dispatcher 与共享 ModelManager
仍与进行中的材质验收一起保留在工作树。下列原生结果属于明确标识的已构建模块，
不能据此认定仅检出这些部分提交就已经具备完整生产 API。
对应 OpenSpec：[proposal](../../openspec/changes/add-production-mcp-support/proposal.md)、
[design](../../openspec/changes/add-production-mcp-support/design.md)、
[spec](../../openspec/changes/add-production-mcp-support/specs/mcp-mmd-operations/spec.md)、
[tasks](../../openspec/changes/add-production-mcp-support/tasks.md)。

普通 Debug/Release 的公共构建层默认包含生产 API，并同步 `mcp/` 运行文件。
薄 stdio 适配器公开 `mmdtool_*` 工具，通过已授权的 C4D 宿主 MCP 发送固定调用。
宿主 MCP 服务、凭据和 Python 执行权限仍由用户配置，插件不会自动开启服务。
运行期回归桥继续受默认关闭的 `CMT_ENABLE_RUNTIME_REGRESSION` 控制。

已接入的工具覆盖模型发现/检查、PMX 模型与 VMD 动作/相机导入导出、动画槽、EDIT/ANIM、物理、
表情强度、帧求值和操作状态。请求使用明确的文档和实例句柄，返回结构化结果。
当前 dispatcher 在 C4D 主线程同步串行执行；没有异步工作队列，运输超时通过 operation ID 查询和去重处理。
单步 Undo、失败回滚、导出源状态恢复和多文档隔离属于必须完成的验收项，不能仅凭对应源码存在判定通过。
VPD 和专用定义编辑工具留作后续扩展。

接入方法见 [客户端配置](mcp-client.md)，生产包、字段编号和事务边界见 [协议维护说明](mcp-protocol.md)。

## 已取得的验证证据

| 层次 | 当前结果 | 证据边界 |
| --- | --- | --- |
| Python 适配器 fixture | 35/35 通过 | 覆盖工具 Schema、stdio、连接错误、凭据保护、去重、超时/会话恢复、提交后导出校验、null 请求 ID 拒绝及 completed-success 必要字段；不运行真实 C4D |
| Windows 正常 Release 接入 | 已执行，回归桥 OFF | C4D 2026.4.0 的已加载模块身份、宿主握手、真实 HTTP 调用和真实 stdio `tools/list` 已记录；发现 16 个工具 |
| Windows PMX 初段集成 | 通过 | 普通 Release、回归桥 OFF；跨 HTTP/stdio 去重、状态查询、包含材质的单步 Undo/Redo、同名多文档及显式实例隔离通过 |
| Windows 后续集成 | 八阶段通过 | setup/discovery/model/motion/camera/invalid/lifecycle/cleanup 全部通过；动作槽、模式、表情、物理开关、精确时间、导出与源状态保持、复制/删除/重开句柄验证完成；不包含真实模型的物理重放或默认材质外观验收 |
| 运行文件/安装规则 fixture | 已通过 | 真实 pinned installer 输入的 resource fixture 6/6、runtime resource fixture 9/9，以及正常 Release、回归桥 OFF 的真实 `res/` 和 `mcp/` 副本已核对；不表示 ISCC 安装包或全 SDK 发行矩阵验收完成 |
| macOS 生产 MCP | 尚未验收 | 没有对应宿主、模块身份和 typed tools 实机证据 |

较早 `49d331…` 模块的失败 receipt 保持 `acceptance_eligible=false`、`status=incomplete`。
补充原生探测发现：包含材质的 PMX 导入，第一次 Redo 只恢复材质，第二次才恢复模型；
关闭材质导入时一次 Redo 可恢复模型。这缩小了单步 Undo/Redo 事务问题的范围，并未使集成用例通过。
此事务问题修复后已用新模块重跑通过；原失败记录保留用于追溯。

此前通过的普通 Release 模块为
`38c9aa87d3de24810568fe3bd1d4dbed71782b195880b00c33a525f1d2d8afeb`，
源码/资源指纹为 `200335730bcb1effd70a74d2b0da3536c2b4c0cbc4e95a6a74469f45ca88edd1`。
run ID `34ed5e42-8b56-435a-be92-55d3404e81b4` 的
[原生收据](../../_build_msvc/validation/remaining/production-no-contact-default/native-run/receipt.json)
为 `passed`、`acceptance_eligible=true`，原始文档已恢复，所属测试文档清理完成。
[manifest](../../_build_msvc/validation/remaining/production-no-contact-default/native-run/manifest.json)
另记录 libMMD/Bullet 维护源码及该 CMake cache 实际选择的静态库路径与 SHA-256；
这属于该冻结切片的验证，不表示后续并行编辑的工作树或安装包已经验收。

原生时间检查覆盖半帧、负帧、微秒级秒数和非整数文档帧。
采用约分后的整数分数构造 C4D 时间，无法表示的非零微小时间明确拒绝，避免 SDK 复制时间时静默舍入。
相机倍率按公开 C4D/MMD 单位比例在导出边界取倒数；原始及烘焙导出、偏移和源状态保持已验证。

较早失败运行的 `manifest.json`、`receipt.json`、`state.json` 和 `transcript.jsonl` 已保存在仓库根目录下的
`_build_msvc/validation/remaining/final-evidence/production-49d331/`，
见 [失败 receipt](../../_build_msvc/validation/remaining/final-evidence/production-49d331/receipt.json)，
run ID 为 `6b8bb50d-e750-4117-91ef-438b129a693b`。
该失败记录的原始输出是 `S:\tmp\cmt-prod-pmx-simple/receipt.json`，记录 C4D 版本 `2026400`、普通 Release 模块和 SHA-256
`49d33120a7f41444a8829e04e99810add4d47c67e232cb3e244aaaa52a876605`。
原始临时目录可能被清理，应以持久收集目录保留的同 run ID 记录为准，不能混用较早模块的快照。

以下为历史构建切片，保留当时的编译和准备状态，不作为最新验收结论。历史源码加入延后登记 PMX Undo 的修复，冻结源码/资源指纹为
`460e009c6eb08b3e363668b3c83ed6d3b03432786fd21f15927d92b3eab78a2a`。
动画槽选择还补充记录文档时间及范围的 Undo，尚未做原生 Undo/Redo 验证。
最终冻结后的 SDK 2026 Debug、独立目录普通 Release 候选及 R20 Debug 增量构建已成功；
当时受桌面锁定及模态窗口影响，尚未加载该候选到 C4D 验证。候选源码/构建与上述已加载失败模块属于不同证据，
不得据此把 Windows 事务验收改为通过。
三个候选的编译、模块及真实运行文件身份见
[primary-build-audit.json](../../_build_msvc/validation/remaining/final-evidence/primary-build-audit.json)。
Windows 八个 SDK 的最终 Debug 编译也已通过，SDK 2024 使用本机实测的专属兼容片段；
其他六个构建见 [final-matrix.json](../../_build_msvc/validation/remaining/final-evidence/sdk-builds/final-matrix.json)。
这些编译结果未覆盖对应旧宿主 UI、所有 SDK Release 安装包或 macOS 原生验收。
独立普通 Release 候选模块为
`f9c88eeb47a6c6319ee4d640a17d72d41849838d8e896d55178bfb1ed0f0bcc7`；
其 [prepare receipt](../../_build_msvc/validation/remaining/final-evidence/candidate-prepare/receipt.json)
仍为 `pending_native_runtime`，并非候选已通过原生验收。

适配器最终 fixture 日志为
[adapter-unittest-final-p2.log](../../_build_msvc/validation/remaining/final-evidence/adapter-review/adapter-unittest-final-p2.log)。
提交后的导出身份校验异常返回 `outcome_unknown`，重复 operation ID 不会重复修改。
显式 JSON-RPC `id:null` 被拒绝，完成且成功的结果通过标准 Schema `if`/`then`/`anyOf` 校验各工具必要 data 字段；
失败、running 和 outcome_unknown 结果仍允许空 data。状态恢复按缓存原工具的 Schema 验证，
无效完成结果不能覆盖已缓存的未知结果。这些是 Python fixture 与 review 结论，不能替代原生候选验收。

## SDK 与宿主基线

Maxon 的[官方 MCP 说明](https://www.maxon.net/en/cinema-4d/features/mcp-server)要求完整 Cinema 4D **2026.4 或更高**，
MCP 调用使用宿主 Python API。该要求是宿主能力要求，不自动意味着需要更换本仓库的 C++ SDK。

当前 `sdk_2026` 的 `apibase_version.h` 标识 `MAXON_API_ABI_VERSION=2026000`、
`MAXON_CORE_FRAMEWORK_VERSION=2026100`；这些是 ABI/框架标识，不作为完整 SDK 发行包版本证明。
现有 SDK 的产物已经在 C4D 2026.4.0 执行九项原生业务回归，新增生产入口也已通过普通 Release 的连接、
发现和初段 PMX 调用。因此当前方案以现有 SDK 为基础，没有已确认的 MCP 相关 C++ API 缺口要求先升级。
早先的九项业务回归不能替代生产协议及普通 Release 的完整 MCP 验收。

截至本次核对，可读取的[官方 2026.3 SDK change notes](https://developers.maxon.net/docs/cpp/2026_3_0/page_change_notes.html)
包含 Windows ARM64、Xcode 26 及重编译时的 platform 配置变化，并说明该配置变化不影响已编译插件。
未来确需新 API、平台或修复时，另立 SDK 更新并核对 wrapper、工具链、全部受影响构建和同产物原生回归；
不仅凭 C4D 宿主小版本号决定 SDK 更新。

## 待完成的发行验收

必须从 MCP `tools/list` 和 typed tools 进入，以正常 Release 产物、回归桥 OFF 为前提取得实机证据。
已有的 [9 项业务回归](regression.md)提供复用业务路径的基线；生产协议、句柄、调度和发行接入需要额外验收。

生产 runner 为 [`scripts/c4d_production_mcp_validation.py`](../../scripts/c4d_production_mcp_validation.py)。
它使用 [`c4d_regression_fixtures.py`](../../scripts/c4d_regression_fixtures.py) 的输入 manifest，
逐阶段记录请求、结果、已加载模块身份和场景/文件证据，并保留用户原始文档。
运行方法及各阶段的完成条件见 [协议维护说明](mcp-protocol.md#分层验证和原生-runner)。

随后普通 Release 模块 `b21d630a6e78a4cb89a34345e56d2b2fc2aed8d387aa3f3b5905f2107728776a`，
源码/资源指纹 `4a542f52dc29f97577be75213e1e3eee961ee4530188bdb6a7d5964e0bdf5db2`，
run ID `b17dcd3c-e551-4e21-88d7-16215654125c` 的
[八阶段原生收据](../../_build_msvc/validation/remaining/production-pmx-final-b21d630a/native-run/receipt.json)
为 passed、acceptance_eligible=true，原文档已恢复、测试文档清理完成。PMX 倍率 1/2/.5 和
三种格式 × 四种写盘失败共 12 例均通过。模块、库、源码与两次新失败运行的原始记录已经归档，
PMX 2.0 尾部格式失败和测试端状态字段错误的旧收据保持失败状态。

最终 canonical SDK 2026 Release 模块为
`c7ad243ee135a7135f2e58ff6c99585b4d9ae95b2562b3a1501faac281700478`，源码/资源冻结指纹仍为 `4a542f52…`。
因构建目录变化后模块哈希不同，另用新 run `743bb4c9-b778-4899-8284-6933d4441f60`
重跑八阶段，全部通过；回归桥 OFF、PMX 三倍率、12 个实际写盘失败及原文档恢复均通过。
[最终原生收据](../../_build_msvc/validation/remaining/windows-release-candidate-20261006/native-run/receipt.json)
与八 SDK Release 构建、实际安装文件身份核对、ISCC 候选包及隔离安装/重复安装/卸载记录一并归档。
安装测试使用私有 AppId 和目录、真实 Release 文件，869 项文件哈希通过；没有把公开 AppId 的候选包安装到用户 host。

尚需完成：真实宿主超时/重连集成、宿主重启后的完整身份矩阵、UV Morph 导出保真、
旧宿主 UI 运行、macOS 对应接入与实际发行包验证。当前 Windows 八阶段通过不能代替这些范围。
真实阿芙 0–60 帧的严格 seek 重放仍失败，另见 [剩余验证](remaining-validation.md)；
物理开关工具的事务验证不意味着物理模拟重放已经通过。
