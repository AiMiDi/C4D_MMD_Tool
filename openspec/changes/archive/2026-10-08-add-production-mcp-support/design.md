# Design

## Context

需求动机见 proposal.md。本机 C4D 2026.4.0 的宿主 MCP 已实际提供 `exec_python`、对象/参数和文档工具。
当前安装的 catalog 说明可覆写层仅支持工具描述等展示信息，未发现可依赖的第三方工具注册契约。
提案时业务回归入口属于默认关闭的测试桥。当时生产接口与 Release MCP 尚未实现；2026-10-08 已完成本提案 Windows 范围的生产接口、句柄与普通 Release 验收，证据见 tasks.md。

## Goals / Non-Goals

**Goals:**

- 让普通发行包具备稳定的 MMD 生产 API，并使 MCP 客户端能发现有类型的 MMD 操作。
- 复用当前已验证的业务求值和事务路径；协议与传输适配不复制模型/动画实现。
- 明确默认可用的插件 API、用户授权的宿主传输、测试专用入口三个独立状态。

**Non-Goals:**

- 首版不新增公共网络监听服务、远程资产下载或渲染器集成，不修改 Maxon 安装目录和私有 adapter 实现。
- 不提供任意 Python、任意 SDK 参数写入或测试专用删除命令作为 MMD 域工具。
- VPD、表情定义编辑和专用骨骼编辑工具留作后续增量；普通场景编辑可继续使用宿主已有工具。

## Decisions

### 1. 首版采用薄 stdio MCP 适配器

随插件发行受维护的 `mmdtool-mcp` 入口，向客户端提供 typed tools，再调用用户已配置且已授权的 C4D MCP。
适配器生成固定生产 API 调用并编码请求数据；客户端不提交源码，所有数据必须经 Schema 和插件端二次校验。
宿主的 Python 执行权限关闭时返回前置条件错误，不自行改偏好设置。

宿主内直接注册自定义工具是可替换的后续传输方案；当前无已验证的公开注册契约，首版不依赖它。
独立 HTTP/socket 服务增加端口、鉴权和生命周期负担，本版不采用。

### 2. 固定操作集合与版本化生产桥

生产桥默认编译到常规发行构建，独立协议版本和请求/结果模型；实验测试桥继续保持默认关闭。
主线程 dispatcher 调用非模态业务服务，不绕过输入检查、场景 Undo 或已有 EDIT/ANIM 边界。
业务层向 UI 和自动化返回结果，由 UI 层决定交互提示，MCP 路径不触发弹窗。

首版工具集合：

| 工具 | 主要行为 |
|---|---|
| `mmdtool_capabilities` | host/plugin/API 版本、连接状态、支持的操作与选项 |
| `mmdtool_list_models` / `mmdtool_inspect_model` | 文档内模型发现、状态、骨骼/表情/槽摘要；大列表分页 |
| `mmdtool_import_pmx` / `mmdtool_export_pmx` | 明确路径及选项的模型导入导出 |
| `mmdtool_import_motion` / `mmdtool_export_motion` | VMD append/replace/merge、频道、倍率、物理处理和 bake |
| `mmdtool_import_camera` / `mmdtool_export_camera` | VMD 相机及普通相机转换导出 |
| `mmdtool_list_animation_slots` / `mmdtool_select_animation_slot` | 槽身份、名称、长度和显式选择 |
| `mmdtool_set_mode` / `mmdtool_set_physics_enabled` | 保持 bind-state 与物理重建语义的状态操作 |
| `mmdtool_set_morph_strength` | 已存在表情的有限强度值，使用返回的表情身份 |
| `mmdtool_evaluate_frame` | 指定文档/模型、时间单位和求值选项，返回有限姿态摘要 |
| `mmdtool_operation_status` | 已接受请求的执行状态及完成结果 |

工具统一声明 `inputSchema`、结果 Schema、只读/修改性质及显式目标字段。新功能通过 capabilities 协商，不静默忽略选项。

### 3. 句柄绑定会话、文档和实例

优先使用宿主返回并能验证归属的 opaque handle；生产桥维护必要的身份和 generation 校验。
不向客户端暴露原始指针，不靠 `SearchObject(name)` 或 PMX 索引定位。文档关闭/重开、对象删除/替换和宿主重启使对应句柄失效。
动作槽和表情身份由模型检查工具提供；派生目标发生变化后旧句柄必须明确失效，不能落到占用旧索引的新对象。

### 4. 事务与时间状态由业务服务拥有

导入/状态操作验证目标和输入后进入单个 Undo 操作；失败回滚后重新绑定 manager 和运行期缓存。
导出以隔离副本求值，保留用户时间、活动文档、选区、轨道和材质；最终文件通过临时写入和替换完成，成功结果包含文件身份。
请求默认不改变用户活动文档或选区；帧求值明确区分临时采样与设置目标文档 playhead。

### 5. 执行记录避免超时后重复修改

适配器为请求分配 operation ID，并将状态与 host session 绑定。主线程队列开始执行前复查句柄。
同步小请求直接返回结果；长请求可返回 operation ID 并查询状态。运输超时只表示未取得完成结果，不自动重试修改。
状态保留窗口、队列容量和输入限制必须由 capabilities 明示；重连无法恢复记录时返回 outcome_unknown。

### 6. 发行与 SDK 兼容

公共 CMake 层管理生产桥及适配器打包，SDK wrapper 保持薄封装。SDK 差异使用 `module/core/cmt_marco.h` 的兼容设施。
首个实机验收基线为 Windows/C4D 2026.4.0。2026-10-08 用户明确允许因缺少设备跳过本轮 macOS 实机验证；其状态为 deferred / unverified，不作为 Windows 交付的通过证据或阻塞条件。无宿主 MCP 的旧 C4D 明确报告 transport 不支持，原插件功能照常可用；兼容编译和旧宿主实际运行分别登记。用户同日也允许将旧宿主 UI 实测延期并保留 unverified。
文档提供本地 token 文件/配置入口和 stdio 客户端示例，不写入实际 secret；插件 API 默认包含不等于自动启用宿主服务。

本需求不预设 C++ SDK 升级。现有 `sdk_2026` 产物已在 C4D 2026.4.0 执行九项原生业务回归；
新增桥所需的消息、容器和线程接口已有兼容设施。
[官方 MCP 要求](https://www.maxon.net/en/cinema-4d/features/mcp-server)是宿主 2026.4+，
[2026.3 SDK 说明](https://developers.maxon.net/docs/cpp/2026_3_0/page_change_notes.html)的主要平台变化另行评估。
只在实际缺少必要 API、平台支持或修复时建立独立 SDK 更新任务。

## Risks / Trade-offs

- [宿主执行权限或接口变化] → 启动时 capabilities 握手，固定兼容契约和结构化前置条件错误；适配层与业务层隔离。
- [Undo、复制、重开导致对象更换] → 执行前重验身份，事务后重绑缓存；沿用本轮回滚后再次导入的实机回归。
- [大资产/烘焙超过传输等待] → operation 状态及去重、分页和有界请求；不把 timeout 当作撤销完成。
- [常规构建仅通过编译却未实际可用] → 必须用桥接关闭的 Release 产物通过 typed MCP 工具验收并记录模块身份。

## Migration Plan

1. 锁定工具 Schema、宿主连接契约和正常发行默认行为。
2. 提取生产服务/dispatcher，保持现有 UI 和测试桥兼容。
3. 实现并随包分发 stdio 适配器、身份/事务/执行记录。
4. 执行协议测试、SDK 编译及同二进制 Release MCP 验收；达标后更新用户功能说明。
5. 回退可移除适配器配置并禁用生产入口；现有场景格式和原生工作流无需迁移。
