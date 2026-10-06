# Proposal

## Why

用户需要让智能体通过 MCP 稳定调用 MMD 插件的模型、动作、相机和运行时操作。当前 C4D 宿主已有 MCP，
MMD 插件仅在专门测试构建中提供回归桥，正常发行包缺少可发现、有类型、无需 UI 对话框的 MMD 接口。

## What Changes

- 在常规 Debug/Release 发行构建中默认提供版本化 MMD 自动化 API，独立于 `CMT_ENABLE_RUNTIME_REGRESSION`。
- 提供可通过 MCP `tools/list` 发现的 MMD 工具及 JSON Schema，覆盖检查、PMX/VMD 导入导出、动画槽、模式、物理、表情强度和帧求值。
- 优先复用 C4D 宿主 MCP；验证其公开扩展机制，必要时提供受维护的薄适配器，通过宿主的已授权执行入口调用固定 MMD API。
- 所有场景操作在主线程串行执行，显式绑定文档和实例句柄，提供非模态结果、单步 Undo、失败回滚和导出状态恢复。
- 随发行包提供接入说明和配置模板，说明宿主版本、鉴权、工具集权限与连接故障；默认 API 可用不表示自动开启宿主网络服务。
- 以普通 Release 构建执行真实 MCP 验收，补齐多文档、同名对象、过期句柄、超时和业务回归证据。

## Capabilities

### New Capabilities

- `mcp-mmd-operations`: 生产 MMD MCP 工具发现、操作契约、主线程调度、对象身份、事务、接入配置及发行验收。

### Modified Capabilities

无。既有模型、动作、相机和运行时业务语义保持，由新增 MCP 入口复用。

## Impact

- `source/CMTSceneManager.*`、工具服务和模型/骨骼/相机管理器：复用业务 API，提取非模态调用入口和结构化结果。
- 新的生产自动化协议与宿主适配层：固定操作集合、版本、句柄、请求/结果 Schema；不公开测试专用删除或任意代码执行工具。
- 公共 CMake、资源配置、Windows/macOS 打包和文档：正常构建默认包含生产 API，测试桥继续默认关闭。
- 新增协议/适配器测试和 Release 原生 MCP 集成测试；不会把本轮测试桥的 9/9 当成生产 MCP 已实现。

本 change 当前为需求与设计提案，尚未实施代码。
