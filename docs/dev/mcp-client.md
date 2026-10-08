# MMD Tool MCP 客户端

MMD Tool 的生产 API 与运行期回归桥是独立入口。`mcp/` 内的 `mmdtool-mcp` 是一个薄 stdio 适配器：
它向客户端提供 16 个有类型的 MMD 工具，向已经启用并授权的 Cinema 4D MCP 服务发送固定的生产 API 调用。
客户端提交路径、选项和对象句柄，不提交 Python 源码或 SDK 参数编号。

## 运行条件

| 项目 | 要求 |
| --- | --- |
| Cinema 4D 宿主 | 2026.4 或更高版本，启用宿主 MCP 服务及 Python 执行权限 |
| 插件 | 包含生产 API 的普通 Debug 或 Release 构建；无需启用 `CMT_ENABLE_RUNTIME_REGRESSION` |
| Python | 3.11 或更高版本；运行不依赖第三方 Python 包 |
| 连接 | 本机 HTTP(S) MCP endpoint，默认 `http://127.0.0.1:5556/mcp` |
| 凭据 | Cinema 4D MCP 创建的本地 token 文件；适配器每次连接读取文件，不在配置中保存 token 内容 |

旧版 C4D 的普通插件功能可继续使用；没有宿主 MCP 服务时，生产适配器无法连接。启用插件 API 不会启用宿主服务，
适配器也不会修改 C4D 偏好设置、客户端配置或 Maxon 安装目录。

当前实施及实机验收状态以 [MCP 支持说明](mcp-support.md) 和该 change 的验证记录为准；
协议 fixture 通过不能代替同一个 Release 模块的 C4D 实机验收。

截至 2026-10-08，Python fixture 为 35/35 通过；普通 Release、回归桥 OFF 的 Windows 八阶段、
PMX 单步 Undo/Redo、真实响应超时与去重恢复、宿主重启及干净客户端接入均已通过。
macOS 和旧宿主 UI 依用户明确要求延期并保留未验证；见 [完整记录](mcp-acceptance-20261008.md)。
当前工作树的实现状态不表示已发布安装包包含这些改动。

## 启动与客户端配置

从插件发行包的 `mcp` 目录直接启动，无需安装包：

```powershell
python C:\path\to\mmdtool\mcp\run_mmdtool_mcp.py `
  --endpoint http://127.0.0.1:5556/mcp `
  --token-file C:\path\to\Cinema4D\prefs\mcp\token
```

把示例中的两条文件路径替换为本机的真实路径。token 文件的位置由对应的 C4D 用户配置目录决定；
可以在 C4D MCP 设置中确认。不要把 token 内容作为命令行参数、配置文本或问题报告提交。

支持 stdio 的 MCP 客户端通常使用以下配置结构；Python 可执行文件和发行目录都应填写绝对路径：

```json
{
  "mcpServers": {
    "mmdtool": {
      "command": "C:\\path\\to\\python.exe",
      "args": [
        "C:\\path\\to\\mmdtool\\mcp\\run_mmdtool_mcp.py",
        "--endpoint", "http://127.0.0.1:5556/mcp",
        "--token-file", "C:\\path\\to\\Cinema4D\\prefs\\mcp\\token"
      ]
    }
  }
}
```

也可以用环境变量 `CMT_MCP_ENDPOINT` 和 `CMT_MCP_TOKEN_FILE` 指定 endpoint 与凭据文件路径。
`--timeout` 控制单次宿主等待，范围为 1–600 秒，默认 180 秒。环境变量中同样只填文件路径，不填 token。

入口将标准输出用于单行 UTF-8 JSON-RPC，不在标准输出打印日志。工具发现本身不连接 C4D；
第一次工具调用先完成宿主连接及插件协议握手，握手成功后才允许修改。
显式 JSON-RPC `id:null` 会被拒绝；请求 ID 使用字符串或整数，notification 则不带请求 ID。

固定宿主调用使用 SDK 支持的 `MSG_BASECONTAINER` 和调用者拥有的临时容器。请求及响应不会写入场景中
SceneHook 的持久数据；当 Python 绑定复制消息容器时，响应从插件的只读、非序列化成员缓存取得。
普通读取工具因此不应改变文档脏状态或 Undo/Redo 历史。首次使用该传输必须使用包含对应入口的新插件模块。
这是传输设计边界；PMX Undo/Redo 的早期失败已修复并重跑通过，临时容器机制本身不代替事务实测。
具体 packet 和响应读取约定见 [协议维护说明](mcp-protocol.md)。

## 工具与选项

所有输入都拒绝未知选项。每次调用可提供 `operation_id` UUID；省略时由适配器生成并在结果中返回。
`document`、`model`、`camera`、`slot` 和 `morph_handle` 必须使用当前宿主会话返回的 opaque handle，
不能填写对象名字、类型 ID 或 PMX 索引。关闭/重开文档、删除对象和重启宿主后要重新发现句柄。

| 工具 | 必填输入 | 其他输入 |
| --- | --- | --- |
| `mmdtool_capabilities` | 无 | `operation_id` |
| `mmdtool_list_models` | `document` | `offset`, `limit` |
| `mmdtool_inspect_model` | `document`, `model` | `section`: `summary`/`bones`/`morphs`/`slots`, `offset`, `limit` |
| `mmdtool_import_pmx` | `document`, `path` | `position_multiple`, PMX 开关、材质类型和名称选项 |
| `mmdtool_export_pmx` | `document`, `model`, `path` | `position_multiple`, PMX 开关、`overwrite` |
| `mmdtool_import_motion` | `document`, `model`, `path` | `strategy`: `append`/`replace`/`merge`, `motion`, `morph`, `model_info`, `position_multiple`, `time_offset`, `ignore_physics`, `local_names` |
| `mmdtool_export_motion` | `document`, `model`, `path` | `motion`, `morph`, `model_info`, `position_multiple`, `time_offset`, `bake`, `rotation`, `overwrite` |
| `mmdtool_import_camera` | `document`, `path` | `position_multiple`, `time_offset` |
| `mmdtool_export_camera` | `document`, `camera`, `path` | `position_multiple`, `time_offset`, `bake`, `rotation`, `overwrite` |
| `mmdtool_list_animation_slots` | `document`, `model` | `offset`, `limit` |
| `mmdtool_select_animation_slot` | `document`, `model`, `slot` | 无 |
| `mmdtool_set_mode` | `document`, `model`, `mode`: `edit`/`anim` | 无 |
| `mmdtool_set_physics_enabled` | `document`, `model`, `enabled` | 无 |
| `mmdtool_set_morph_strength` | `document`, `model`, `morph_handle`, `strength` | 无 |
| `mmdtool_evaluate_frame` | `document`, `model`, `frame`, `unit` | `set_playhead` |
| `mmdtool_operation_status` | `query_operation_id` | 无 |

PMX 开关为 `polygon`, `normals`, `uv`, `materials`, `bones`, `weights`, `ik`, `inherit`, `expressions`，默认均为 `true`。
导入还支持 `multipart`, `english`, `english_check`，默认均为 `false`，以及 `material_type`：
`standard`（默认）、`redshift`、`octane`、`corona`。选择额外渲染器需要对应的宿主能力；
插件会拒绝不受支持的选项，不会静默替换为其他渲染器。
capabilities 的 `data.material_types` 列出当前实际可创建的材质类型；没有安装对应材质/贴图节点时返回
`unsupported_renderer`，不会弹出安装提示或转换成 Standard。

PMX 选项有明确依赖：`weights=true` 要求 `polygon=true` 且 `bones=true`；`ik`、`inherit` 要求 `bones=true`；
`normals`、`uv`、`materials` 要求 `polygon=true`，`multipart=true` 同样要求导入 polygon。
关闭上游选项时应同时关闭这些依赖选项；不一致的组合在连接/修改前被拒绝。

位置倍率 `position_multiple` 默认为 `8.5`，必须为正的有限数。其公开含义为
`s = C4D 长度单位 / MMD 长度单位`，客户端传入业务倍率，不自行取倒数。
相机位置及距离导入时乘 `s`，导出时除 `s`；例如倍率 2 导入得到两倍 C4D 长度，
按同倍率导出应恢复原始 VMD 长度，raw 与 bake 的倍率契约相同。

动作使用模型保存的位置倍率 `M`（`MODEL_POSITION_MULTIPLE`）：VMD 平移 `V` 导入为模型内部平移
`K = V × s/M`，导出为 `V = K × M/s`。MCP 动作入口直接传 `s`，不再次反转；
这一公式用于模型内部骨骼动画平移，不把任意父对象变换当成模型倍率。

当前 `9d132…` 原生模块的相机导出边界尚未执行 `1/s`，而 UI 动作导出仍有多余倒数；
修订已确定，需新模块实机复验上述方程，现有倍率 1 用例不能证明倍率 2 或默认 8.5 正确。
PMX 导入把 `s` 设为模型根倍率；**PMX 导出目前接收 `position_multiple`，但保存链路没有应用它**，
仍写出内部 PMX 坐标。这是未完成的选项，不能据 Schema 接受或拓扑回写成功声称导出缩放通过。
倍率维护规则见 [mcp-protocol.md](mcp-protocol.md#位置倍率契约)。

`time_offset` 始终是 **30 fps 的整数 VMD 帧**，
不是 C4D 秒；小数偏移会在修改前被拒绝。`rotation` 为 `quaternion`（默认）或 `euler`。
`bake` 默认 `true`，导出使用隔离副本求值并保持源场景状态。

帧求值的 `unit` 必须显式指定：`vmd_frames`、`document_frames` 或 `seconds`。
默认 `set_playhead=false` 表示临时采样；只有 `true` 才设置目标文档的播放头。
分页默认 `offset=0`、`limit=64`，单页上限为 256；实际限制以 capabilities 为准。

## 一次完整调用

1. 调用 `mmdtool_capabilities`，检查成功状态、`data.protocol_version`、`data.host_session` 和 `data.supported_operations`，
   从 `data.documents` 取得目标文档句柄。
   现有普通相机和 MMD 相机的句柄位于 `data.cameras`，每项同时标明所属文档。
2. 用该文档句柄调用 `mmdtool_list_models`。导入新模型时，直接调用 `mmdtool_import_pmx`，指定绝对 `path` 和倍率。
3. 用返回的模型句柄调用 `mmdtool_inspect_model`；`section=morphs` 或 `slots` 获取派生对象句柄。
4. 调用所需的动画、表情、模式或导出工具。不要从对象列表位置推导句柄。

例：向已发现的模型追加动作。这里的句柄占位符必须替换为实际返回值：

```json
{
  "name": "mmdtool_import_motion",
  "arguments": {
    "document": "<document-handle>",
    "model": "<model-handle>",
    "path": "C:\\assets\\dance.vmd",
    "strategy": "append",
    "position_multiple": 1,
    "time_offset": 0,
    "motion": true,
    "morph": true,
    "model_info": true,
    "operation_id": "fb563486-b0ed-4f6a-9d8e-e7e10f301db8"
  }
}
```

每个结果都包含 `success`, `code`, `message`, `operation_id`, `state`, `data`, `warnings`，
并通过 MCP `structuredContent` 返回相同结构。`state` 为 `queued`, `running`, `completed`, `failed` 或 `outcome_unknown`。
当 `success=true` 且 `state=completed` 时，结果还必须包含对应工具的必要 data 字段；
running、失败和 outcome_unknown 可以没有完成数据。状态恢复会按原工具 Schema 校验，
格式无效的完成结果不会被当作成功恢复或触发自动重复修改。
当前 capabilities 的 `data.execution` 为 `synchronous-main-thread`：宿主调用同步完成，没有可供客户端提交的
异步队列。`queued` 是结果契约中的预留状态，不能据此假设已经实现后台作业或取消功能。
成功导出还包含 `data.path`, `data.bytes`, `data.size`, `data.sha256`：原生端完成暂存写入及目标替换，
固定宿主调用再读取并校验最终文件身份。既有目标默认拒绝，只有显式 `overwrite=true` 才允许替换。
最终文件已提交后，身份校验异常返回 `export_verification_failed`、`state=outcome_unknown`；
文件可能已经写入，适配器保留安全错误信息且不会自动重试。

## 超时、重连与错误

等待超时或连接中断不表示撤销已经完成。适配器不会自动重试修改；重复相同 operation ID 和参数会返回已有结果，
相同 ID 配不同参数会返回 `operation_id_conflict`。发生不确定结果后，调用 `mmdtool_operation_status`，
以 `query_operation_id` 查询原始 ID。只有确认失败且没有发生修改后，才使用一个新的 operation ID 发起新的操作。

生产端去重记录的窗口及容量由 capabilities 返回。适配器也保留有界的本机会话记录；
重启宿主或记录已经过期后，旧操作可能返回 `outcome_unknown`，需要检查实际场景/文件。重新连接不会把未知结果解释为回滚。

| 错误 | 处理方式 |
| --- | --- |
| `authentication_required` | 确认 token 文件路径、宿主服务及凭据有效；错误输出不包含 token |
| `permission_denied` | 确认 C4D MCP 已授权 Python 执行；适配器不会修改设置 |
| `host_unavailable` | 确认 C4D 正在运行且 endpoint 与实际监听地址一致 |
| `unsupported_host` / `incompatible_protocol` | 使用受支持的宿主/插件版本，重新执行 capabilities |
| `plugin_unavailable` | 确认正确的插件模块已加载并包含生产 API |
| `stale_handle` | 重新发现文档和实例句柄；不要按名字寻找替代对象 |
| `transport_timeout` / `host_session_expired` | 查询原 operation ID，检查场景/文件，不自动重复修改 |
| `export_verification_failed` | 结果为 `outcome_unknown`；目标文件可能已写入，检查路径与文件身份，使用原 operation ID 查询状态 |

## 开发验证

```powershell
python -m unittest discover -s mcp/tests -v
```

当前 35 个 fixture 覆盖 stdio 生命周期、16 个 Schema、未知选项/数值拒绝、HTTP/SSE、凭据错误、
固定数据编码、去重、超时恢复、会话变化、导出 SHA-256、提交后校验异常、null 请求 ID 和完成结果必要字段。
测试临时文件在 Windows 默认放到 `S:\tmp`，
可通过 `CMT_TEST_TEMP_DIR` 指定专用目录。它们不启动或修改真实 C4D。

真实接入使用 [`c4d_production_mcp_validation.py`](../../scripts/c4d_production_mcp_validation.py) 的独立阶段 runner。
该 runner 的文档创建、Undo、复制和保存/重开代码仅用于测试，不属于适配器公开的 16 个工具；
运行方法、证据文件和失败后续跑规则见 [协议维护说明](mcp-protocol.md#分层验证和原生-runner)。

运行时依赖仅为 Python 标准库；`mcp/pyproject.toml` 的 `dependencies=[]` 是完整运行时依赖清单。
直接运行发行入口不需要 setuptools。可选的安装式入口 `mmdtool-mcp` 由该文件声明，
构建 Python 包时才需要 setuptools。

协议依据：[MCP stdio/Streamable HTTP](https://modelcontextprotocol.io/specification/2025-06-18/basic/transports)、
[生命周期](https://modelcontextprotocol.io/specification/2025-06-18/basic/lifecycle)、
[工具及结构化结果](https://modelcontextprotocol.io/specification/2025-06-18/server/tools)。
宿主要求依据：[Maxon Cinema 4D MCP Server](https://www.maxon.net/en/cinema-4d/features/mcp-server)。
