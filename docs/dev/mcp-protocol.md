# 生产 MCP 协议维护说明

本文说明当前协议版本 1 的实现和验证方法。用户接入见 [mcp-client.md](mcp-client.md)，
实际验收状态见 [mcp-support.md](mcp-support.md)。协议、编译、fixture 和同模块实机验证是独立证据层。

## 调用链和默认入口

| 层次 | 维护入口 | 职责 |
| --- | --- | --- |
| 客户端协议 | `mcp/run_mmdtool_mcp.py`、`mcp/mmdtool_mcp/server.py` | UTF-8 单行 stdio JSON-RPC、16 工具发现、输入校验、会话去重 |
| 工具契约 | `mcp/mmdtool_mcp/schema.py` | 工具名称、input/output Schema、默认值和 option 编号 |
| 宿主连接 | `mcp/mmdtool_mcp/host.py` | 本地 HTTP(S)、token-file、宿主握手、固定 Python 调用及最终导出 SHA-256 |
| C4D 消息入口 | `source/CMTSceneManager.cpp` | 消费 caller-owned production packet，提供只读响应 fallback |
| 生产协议 | `source/utils/cmt_automation_protocol.hpp` | 版本、容器/字段编号和原生限制 |
| 原生执行 | `source/module/automation/mmd_automation.cpp` | 二次输入校验、实例句柄、串行执行、操作记录和业务事务 |

公共 CMake 层默认编译生产模块，并由 `mmdtool-mcp-adapter` 依赖调用
`cmake/sync_mcp_adapter.cmake`，复制启动脚本及四个 `mmdtool_mcp/*.py` 运行文件。
安装包规则从已构建插件目录收集 `mcp/`。运行不需要第三方 Python 包，测试、缓存和凭据不属于该复制清单。
这些构建/安装规则存在不等于各平台安装包已经通过验收。

生产入口不依赖 `CMT_ENABLE_RUNTIME_REGRESSION`。回归桥仍只在该选项为 ON 的专用构建中启用。
不要把回归桥成功、固定测试 Python 代码成功或普通 UI 导入成功当作 typed MCP 验收。

## 临时消息包

生产调用通过 SceneHook `1057017` 的 `Message(MSG_BASECONTAINER, packet)` 进入。
`1057017` 同时是 `packet.GetId()` 的限定值，**不是自定义 Message 类型**。
packet 由调用者临时创建；`2000000` 是请求子容器，`2000001` 是响应 JSON 字符串字段。

| 请求字段编号 | 名称 | 内容 |
| --- | --- | --- |
| 0 | `Protocol` | 整数 `1` |
| 1 | `OperationName` | 公开的完整 `mmdtool_*` 工具名称 |
| 2 | `OperationId` | UUID 字符串 |
| 3 | `DocumentHandle` | capabilities 返回的文档句柄；无目标工具为空 |
| 4 | `TargetHandle` | 模型或相机实例句柄；无对象目标工具为空 |
| 5 | `Options` | 该工具允许的选项子容器 |

Python 固定 wrapper 优先读取 packet 的 `2000001`。某些 Python 绑定会复制传入容器，
此时 wrapper 通过 `GetParameter(DescID(DescLevel(2000001, DTYPE_STRING, 0)))` 读取 SceneHook
的 `production_response_` 成员。该成员不在持久 BaseContainer 内，不序列化，且 `SetDParameter` 拒绝写入。
每个 qualified packet 处理前清空缓存，处理后立即读取响应。
不得把请求或响应写入 `SceneHook.GetDataInstance()`，也不得用场景脏状态或 Undo 项传递通信数据。

客户端只提交 JSON 数据。固定 host wrapper 进行数据编码并生成调用，接口不接受任意 Python 源码，
不接受 SDK 参数编号。不要把测试 runner 的文档操作 helper 加入生产工具集合。

## 选项编号和结果

下列编号必须与 C++ `Option`、Python `OPTION_IDS`、固定 wrapper 及 fixture 一致。

| 编号 | 选项 | 编号 | 选项 |
| --- | --- | --- | --- |
| 100 | `path` | 101 | `position_multiple` |
| 102 | `strategy` | 103 | `motion` |
| 104 | `morph` | 105 | `model_info` |
| 106 | `time_offset` | 107 | `ignore_physics` |
| 108 | `local_names` | 109 | `bake` |
| 110 | `rotation` | 111 | `overwrite` |
| 112 | `slot` | 113 | `mode` |
| 114 | `enabled` | 115 | `morph_handle` |
| 116 | `strength` | 117 | `frame` |
| 118 | `unit` | 119 | `set_playhead` |
| 120 | `offset` | 121 | `limit` |
| 122 | `section` | 123 | `polygon` |
| 124 | `normals` | 125 | `uv` |
| 126 | `materials` | 127 | `bones` |
| 128 | `weights` | 129 | `ik` |
| 130 | `inherit` | 131 | `expressions` |
| 132 | `multipart` | 133 | `english` |
| 134 | `english_check` | 135 | `material_type` |
| 136 | `query_operation_id` | | |

Python 与原生端分别校验工具允许的字段、类型、有限数、枚举及 PMX 选项依赖，拒绝未知选项。
`time_offset` 是整数 30 fps VMD 帧；`evaluate_frame` 的 `unit` 必须明确提供。
新增工具/选项时同时更新两端契约、默认值、错误结果、capabilities 和测试；不复用现有编号表示不同含义。
不兼容的改动必须升级协议并在修改前拒绝不兼容客户端。

结果 envelope 包含 `success`、`code`、`message`、`operation_id`、`state`、`host_session`、`data`、`warnings`。
stdio 端把相同结构放入 `structuredContent`，失败结果同时设置 MCP `isError`。
Python 的标准库 validator 执行 Schema `if`/`then`/`anyOf`：完成且成功的 envelope 必须包含对应工具的必要
data 字段；accepted/running、失败和 outcome_unknown 保留空 data 的合法路径。
状态恢复按已缓存原工具的 Schema 复查完成结果，无效结果不能替换原来的未知状态，也不触发重放。
显式 JSON-RPC `id:null` 在 stdio 协议层拒绝，不能作为普通请求进入宿主。
原生导出完成暂存文件写入及目标提交后返回路径和字节数；固定 wrapper 读取最终文件并补充 `size`、`sha256`。
同一导出 operation ID 的状态查询也需要校验对应最终文件，不能只凭历史成功 envelope 证明文件仍相同。
提交后的文件身份校验异常返回 `export_verification_failed` 和 `outcome_unknown`，而不是把已提交文件误报为已回滚。
适配器不会自动重试；对应 fixture 检查提交文件仍保留，重复 operation ID 仅执行一次修改。

### 位置倍率契约

编号 101 的 `position_multiple` 是业务倍率 `s = C4D 长度单位 / MMD 长度单位`，默认 8.5。
这与某个 C++ setting 字段恰好参与乘法还是除法是不同层次的契约。
令 `M` 为目标模型保存的 `MODEL_POSITION_MULTIPLE`、`V` 为文件平移、`K` 为模型内部骨骼动画平移：

| 操作 | 公开倍率换算 | setting 边界 |
| --- | --- | --- |
| Camera import | C4D 位置/距离 = VMD 位置/距离 × `s` | 传入 `s` |
| Camera export，raw 或 bake | VMD 位置/距离 = C4D 位置/距离 ÷ `s` | 当前 `SaveVMDCamera` 内部相乘，入口需传 `1/s` |
| Motion import | `K = V × s/M` | 传入 `s`，转换器处理模型倍率 |
| Motion export，raw 或 bake | `V = K × M/s` | 传入 `s`；共用 `ConvertBoneKeyframeToMotion` 已执行除法，不再次取倒数 |
| PMX import | 保留内部 PMX 坐标，模型根倍率设为 `s` | 传入 `s` |
| PMX export | 输出长度 = 内部 PMX 长度 × `M/s` | `SavePMX` 统一换算已组装的数据；独立测试及 SDK 编译通过，普通 Release `b21d630a…` 实际导出验证通过 |

`9d132…` 模块的 typed Camera export 仍直接传 `s`，与公开业务契约和相机 UI 不一致；
UI Motion export 则仍传倒数，与当前动作转换器不一致。相机入口 `1/s` 与动作 UI 取消倒数随后已在
`38c9aa87…` 普通 Release 的原生阶段验证通过，旧失败记录保持其原始身份。
PMX 倍率实现覆盖顶点/SDEF、骨骼/尾偏移、位置与骨 Morph、刚体尺寸/平移、关节平移及线性限制；
helper 对已有 PMX 结构中的 Impulse 平移速度按长度/时间单位换算，角字段、UV、法线、权重、颜色和物理系数保持。
既有插件 ImpulseMorph 目前仅输出空 stub，不保留 offset 或应用物理冲量；此结构检查不代表完整冲量支持。
所有长度先检查 Float32 可表示性，再统一写入，失败不部分缩放输出。只读取实际序列化的 SDEF/尾偏移等可选字段。
普通 Release `b21d630a…` 已实际导出倍率 1、2、.5，独立读回检查文件数据和源文档快照通过；冲量效果另属未实现范围。
三种导出格式另通过 12 个真实写盘失败场景：父目录缺失、目标为目录、临时文件冲突和 Windows 只读目标。
失败状态查询保持同一 operation ID、`state=failed` 和 `write_failed`；旧文件及源文档保持，临时文件无泄漏。

回归需使用非 1 倍率：Camera import/export 同倍率 2 与默认 8.5，检查位置与距离并分别覆盖 raw/bake；
Motion 使用不同的模型倍率 `M` 与动作倍率 `s`，检查 `s/M`、`M/s` 及同倍率往返。
场景时间、源曲线、rotation 和 FOV 保持另做断言，长度换算不应改变这些字段。

## 线程、身份和事务

capabilities 当前声明 `execution=synchronous-main-thread`。dispatcher 检查 `GeIsMainThread()`，
非主线程返回 `main_thread_required`；执行中的重入请求返回 `dispatcher_busy`。
当前没有异步工作队列、后台作业或取消入口。结果契约保留 `queued`/`running` 状态，
不能据此承诺已实现排队执行；未来新增队列时必须在出队后重新核对目标。

文档和对象句柄绑定宿主会话及实例，原生端通过 BaseLink、当前打开文档列表和对象文档归属复查目标。
模型派生的动画槽和表情句柄还包含运行期 identity，并在修改前验证仍存在。
名字、活动选区、PMX 索引和对象列表位置都不能代替这些句柄。
关闭/重开、删除/替换、复制和 Undo/Redo 后应重新发现对象，不能假定旧句柄仍可复用。

修改操作在目标与输入验证后使用 Undo 事务，失败路径尝试回滚并重绑运行期数据；
Undo 记录/回滚失败返回 `undo_failed` 和 `outcome_unknown`，要求核对实际场景。
导出通过隔离副本求值并暂存写入，`overwrite=false` 默认拒绝既有目标。
临时帧求值恢复源状态；`set_playhead=true` 才有意修改目标文档时间。
这些是源码中的事务行为，完整状态恢复必须逐操作做实机验证。
动画槽选择会改变文档时间及范围，dispatcher 已在同一事务内先记录 `DocumentSettings`，再记录模型改变；
该修订尚未取得原生单步 Undo/Redo 通过证据。

2026-10-06 较早 Windows 模块曾发生一次 Redo 只恢复材质、第二次才恢复模型的问题。
延后登记 PMX Undo 后，普通 Release `38c9aa87…` 的包含材质导入、单步 Undo/Redo 和全部八阶段已通过；
历史失败收据保持原样，最新证据见 [支持状态](mcp-support.md)。

## 执行记录和连接错误

原生记录当前保留 900 秒，容量 256；最大分页 256，输入文件限制 256 MiB。
以 capabilities 返回值为准，Python JSON 请求另有 64 KiB 限制。
operation ID 的 fingerprint 绑定工具、文档/对象和选项；同 ID 相同参数返回已有记录，不同参数返回
`operation_id_conflict`。状态查询通过 `query_operation_id` 查询原 ID。

stdio 适配器也保留有界的本机会话记录。运输超时、连接中断、宿主会话变化或记录过期时不自动重放修改，
无法确定结果返回 `outcome_unknown`。重连后先查询原 ID，再核对场景/文件。
维护错误映射时不要回显宿主任意错误文本、Authorization 或 token 文件内容。

## 分层验证和原生 runner

适配器 fixture：

```powershell
python -m unittest discover -s mcp/tests -v
```

本次最终 35/35 通过只证明 Python 协议和模拟 host 行为。
另有 [历史 envelope Schema 检查](../../_build_msvc/validation/remaining/final-evidence/captured-envelope-schema-audit.json)：
最终 output Schema 对旧 `49d331…` transcript 的 11 个真实 HTTP 原生 envelope 只读校验通过，没有新 host 调用或原生重跑，不改变 Redo 失败结论。
OpenSpec strict validation 与 `git diff --check` 只证明 change 格式和文本完整性，也不能替代业务验收。

生产实机 runner 在 C4D 外运行：

```powershell
python scripts/c4d_production_mcp_validation.py --stage prepare `
  --output S:\tmp\cmt-prod-run `
  --expected-binary C:\path\to\Release\plugins\mmdtool\mmdtool.xdl64 `
  --build-cache C:\path\to\sdk_2026_release\CMakeCache.txt

python scripts/c4d_production_mcp_validation.py --stage setup `
  --output S:\tmp\cmt-prod-run --token-file C:\path\to\Cinema4D\prefs\mcp\token

python scripts/c4d_production_mcp_validation.py --stage discovery `
  --output S:\tmp\cmt-prod-run --token-file C:\path\to\Cinema4D\prefs\mcp\token
```

`prepare` 生成 fixture manifest 和预期模块身份，并核对 Release 路径及回归桥 OFF 的 CMake cache。
后续顺序是 `setup`、`discovery`、`model`、`motion`、`camera`、`invalid`、`lifecycle`、`cleanup`。
可用 `--stage all` 按顺序运行，首个失败即停止；已通过阶段不会自动重放修改。
业务断言失败时先保存失败证据，再自动恢复原文档并清理 exact-owned 测试文档；
超时或执行结果未知时保持 `cleanup_pending`，确认操作完成和主线程检查点后再清理，禁止重放修改。
`cleanup` 可重试未完成的安全清理。换模块或重新开始验收时使用新的输出目录，
重新 prepare，避免混用旧模块/旧会话的证据。

runner 使用真实 stdio subprocess 和真实 HTTP typed 调用；创建、复制、Undo、保存、重开和清理文档
另用固定测试 helper，通过当前已授权的 host 执行。它保留原始文档及活动状态，不使用生产客户端的任意代码入口。
同名文档用不同目录保存并重开同名 `.c4d` 文件，目标始终由实例句柄定位。

保存 `manifest.json`、`state.json`、`receipt.json` 和 `transcript.jsonl`。
记录必须同时包含宿主版本、实际加载模块路径/SHA-256、回归桥禁用证据、请求/结果及场景或文件断言。
只有所有必需原生阶段通过且原始文档仍存活并恢复后，receipt 才可标为验收通过。
当前 Windows 普通 Release、回归桥 OFF 的八阶段已通过，原文档已恢复，所属文档全部关闭。
manifest 同时记录 libMMD/Bullet 维护源码、submodule HEAD/源码脏状态与该 cache 的实际静态链接输入；
完整依赖快照未确认的 run 不能成为新的完整验收通过记录。源码/库变动后使用新 run，旧 manifest 不改写。
这些是切片身份及原生结果，不构成依赖历史构建来源证明。2026-10-08 的响应超时、去重重连和宿主重启
已通过，见 [最新验收记录](mcp-acceptance-20261008.md)。macOS 与旧宿主 UI 依用户要求延期，保留未验证。

两阶段恢复 runner `scripts/c4d_mcp_recovery_validation.py` 的 `--phase before-restart` 使用真实普通打包适配器，
在本机故障代理中延迟已执行的响应；`--phase after-restart` 检查新宿主 nonce、旧句柄拒绝与新句柄可用。
每阶段使用新的准备记录并验证普通 Release 模块和回归桥 OFF。两阶段之间只重启已清理的测试宿主，
保留 `before-restart.json`、保存场景和 `after-restart.json`，不自动终止或重启用户宿主。
