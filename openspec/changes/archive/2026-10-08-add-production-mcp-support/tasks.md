# Tasks

2026-10-08 当前范围验收完成：19/19。普通 Release 模块 `806a5091…`，
源码/资源指纹 `f75f9c77…`，回归桥 OFF。真实 HTTP/stdio 八阶段、原生 UV 4 例、
Impulse 7 例、延迟响应/重连/宿主重启，以及独立测试构建的现有业务 9 例通过。
[完整记录](../../../../docs/dev/mcp-acceptance-20261008.md)及 [MCP 支持说明](../../../../docs/dev/mcp-support.md)。
macOS 与旧宿主 UI 已按用户要求延期并保持未验证；当前完成不表示公开发行已验收。
以下保留历史收据，并在各节注明本次补齐的项目。

## 1. 接口契约与版本基线

- [x] 1.1 核对 C4D 2026.4+ 宿主 MCP、现有 SDK ABI 和公开调用方式，形成版本/权限矩阵及可执行连接检查；只有必要 API 缺失才另立 SDK 升级。
- [x] 1.2 定义首版工具 input/output Schema、能力版本、操作状态和错误码；以 Schema fixture 验证有效/无效请求及未知选项拒绝。
- [x] 1.3 定义文档、模型、相机、表情和动画槽的句柄契约；通过同名、复制、删除、Undo、重开和宿主重启的身份测试。2026-10-08 八阶段与重启后五类旧句柄拒绝通过。

1.1–1.2 的证据为客户端运行条件表、协议维护说明、Schema fixture 及真实 host 握手。
Schema fixture 还覆盖显式 null 请求 ID 拒绝、completed-success 各工具必要 data 字段和标准 `if`/`then`/`anyOf`。
1.3 的句柄实现已存在；2026-10-08 完整矩阵已通过；重启后文档、模型、表情、槽和相机旧句柄均返回 stale_handle。

## 2. 生产业务入口与事务

- [x] 2.1 实现普通发行构建默认包含的版本化生产桥和主线程串行 dispatcher；验证回归桥 OFF 时握手、查询及执行前目标复查可用。
- [x] 2.2 提取非模态业务服务及结构化报告，保持 UI 行为；用无对话框导入/失败路径及匹配/未匹配名称结果验证。2026-10-08 三种导入各 missing/truncated/wrong-format 共 9 例及准确未匹配报告通过。
- [x] 2.3 实现显式文档/对象定位和单步 Undo、失败回滚后的缓存重绑；通过多文档隔离、失败后再次导入及 Undo 实机测试。
- [x] 2.4 记录生产 API 协议和线程/事务边界，补充默认入口与测试桥区别；核对说明中的可执行调用与测试结果。

2.1 当前为同步主线程串行执行，无异步队列；普通 Release 已实际握手、查询，Undo 后旧模型句柄被拒绝。
2.2 的服务和报告已接入，但2026-10-08 名称报告和导入失败矩阵已通过实机验证。
2.3 包含材质的单步 Undo/Redo、多文档隔离及失败路径实机验证通过；历史首次 Redo 仅恢复材质的收据保留。
2.4 记录临时 packet、只读响应 fallback 与同步执行边界，Windows 验收和完整发行状态分别记录。

## 3. MCP 适配器与连接

- [x] 3.1 实现薄 stdio MCP 入口及 tools/list，固定封装宿主授权入口；MCP 客户端验证工具发现、Schema 和 plugin/API 握手。
- [x] 3.2 实现本地 endpoint/token-file 配置、权限及连接错误映射；连接 fixture 覆盖缺失宿主、401、权限拒绝和版本不兼容，断言结果/日志不含 token。
- [x] 3.3 实现 operation ID、状态查询、去重和超时后的 outcome_unknown；用延迟/断线/重连 fixture 验证不重复修改。
- [x] 3.4 发布适配器启动与客户端配置模板、依赖锁定及故障说明；在干净配置中按文档完成真实连接。2026-10-08 打包 mcp 入口在无 pip、无第三方依赖的独立 Python 环境中完成真实 tools/list、握手、修改及状态恢复。

3.1 有真实 stdio tools/list 和 plugin/API 握手证据。此前 3.2 的认证/权限错误矩阵与 3.3 的初始超时结论来自 Python fixture；
原生初段另验证了同 ID 的 HTTP/stdio 去重和状态查询。2026-10-08 延迟实际原生执行后的 HTTP 响应，超时返回 outcome_unknown、同 ID 不重放，重连查询恢复 completed；实际修改仅送入宿主一次。
最终 fixture 还验证提交后导出身份校验异常为 outcome_unknown，且状态恢复按缓存原工具 Schema 复查完成数据。
3.4 的启动配置、标准库依赖清单和故障说明已写入文档；2026-10-08 普通 Release 运行包及干净客户端配置验收已完成；公开安装包发布不在此结论内。

## 4. MMD 域工具

- [x] 4.1 接入能力、模型检查、槽查询/选择、模式、物理、表情强度和帧求值工具；真实 host 验证作用对象、时间单位和状态结果。
- [x] 4.2 接入 PMX 模型及 VMD 动作/相机导入导出工具，完整映射已有选项；原生验证 append/replace/merge、频道、倍率、model-info 和 bake。
- [x] 4.3 实现导出的完整写入、显式 overwrite、文件身份和源状态恢复；验证写入失败、既有目标拒绝、烘焙源材质/时间/轨道不变，并同步工具文档。

4.1 在真实普通 Release 通过模型/槽/模式/物理开关/表情及精确半帧、负帧、秒数检查。
4.2 的 VMD 动作/相机 append/replace/merge、倍率、offset、频道、model-info 和 bake 已通过；
PMX 导出位置倍率的统一长度换算已实现并通过独立测试及 SDK 2026/2024/R20 编译；
普通 Release `b21d630a…` 的倍率 1/2/.5 实际原生导出、文件读回和源状态验证通过。
旧模块的 UV/Impulse 丢失收据保留。2026-10-08 修复 UV 展开读取、所有角点及分网格面索引；merged/split × direct/reopened 4 例通过。Impulse 保存刚体链接、local、速度与力矩，直接/倍率 2/.5/重开/复制/刚体重排/目标缺失 7 例通过。
4.3 已有写入身份、overwrite 拒绝和烘焙源状态原生证据；同一普通 Release 通过 PMX/动作/相机 ×
missing-parent、staging-collision、directory-destination、Windows readonly-destination 共 12 个真实失败。
每例验证 `write_failed`、同 ID 的失败状态、旧文件保持、临时文件清理及源状态恢复；未模拟磁盘耗尽。
此次结果覆盖所列写入失败矩阵；本次同模块重跑确认源材质/时间/轨道不变，数据及源状态任务通过。材质外观与真实 MMD 渲染一致性仍由材质提案独立验收。

## 5. 发行与兼容

- [x] 5.1 公共 CMake/资源/安装包默认包含生产 API 和适配器，保持测试桥默认 OFF；配置及打包 fixture 验证完整文件与生产默认值。
- [x] 5.2 使用公共 SDK 兼容设施验证 SDK 2026 和 R20 编译，保留构建日志及版本矩阵。旧 host transport 不支持时原 UI 实测按用户 2026-10-08 的明确调整延期，登记 deferred / unverified，不记为通过。
- [x] 5.3 用普通 Release 包在 Windows/C4D 2026.4+ 执行 typed MCP 验收；记录实际加载模块、请求/结果和文件/场景证据。macOS 按用户 2026-10-08 的范围调整跳过，保留 deferred / unverified 状态，不记为通过。

5.1 已通过真实 pinned installer 输入的 resource fixture 6/6（含 MCP 规则配对和 runtime-only 文件清单）、runtime resource fixture 9/9，
以及正常 Release、回归桥 OFF 的真实 `res/`、`mcp/` 副本检查。该任务的 fixture 不要求执行 ISCC；
其完成不代替实际安装包、兼容 SDK/旧宿主 UI 矩阵或 Windows/macOS 全量实机验收。
5.2 的 Windows 八个 SDK Debug 及 SDK 2026 独立普通 Release 候选已编译通过，统一源码/资源冻结指纹 `460e…`；
旧宿主 UI 运行尚未验证，2026-10-08 用户明确允许延期；任务完成范围已调整为兼容编译与明确的未验证登记。
随后冻结源码/资源 `4a542f52…` 的八套 canonical Windows Release 也全部编译通过，测试桥全部 OFF，
输入 audit、真实 ISCC 候选包编译以及私有 AppId/目录的真实文件安装/重复安装/卸载（869 项身份）通过。
最终 SDK 2026 打包模块 `c7ad243e…` 独立重跑生产 MCP 八阶段通过；旧 host 与 macOS 未由这些结果覆盖。

## 6. 集成验收

- [x] 6.1 重跑现有业务回归，执行多文档/同名/过期句柄/Undo/超时集成用例；证明生产 MCP 验收未依赖回归桥。
- [x] 6.2 核对 capability 清单与真实发行行为，完成 OpenSpec strict validation、diff 检查和最终验证记录；更新 README 的已实现状态。

2026-10-08 现有业务 9/9 在独立测试桥 ON 的 Debug 构建重跑；普通 Release/桥 OFF 的八阶段和真实超时/重启验收单独通过。19 项 CTest（其中适配器 35 项）通过。能力清单与实际 16 工具一致，README 和最终记录已更新；OpenSpec strict validation 与文本 diff 检查通过。

## 验收范围与后续

2026-10-08 用户明确允许延期 macOS 和旧宿主 UI 实测；两者均为 deferred / unverified，
不计为通过。本 change 的当前完成范围是 Windows / C4D 2026.4+ 与 SDK 2026/R20 编译。
公开安装包发布、真实模型物理重放、Additional UV 渲染与 Impulse 物理施加不由本次 MCP 数据验收代替。
UV 修复已独立提交为 4de2b04f；Impulse 和 dispatcher 的其余生产 C++ 仍与共享材质增量处于工作树。归档或验证脚本提交不表示已发布或已完整固化所有实现源码。

## English summary

Completed the Windows / Cinema 4D 2026.4+ production MCP acceptance scope (19/19). The normal Release module passed real HTTP/stdio, UV and impulse data roundtrips, delayed-response recovery, deduplication, and host-restart identity checks. macOS and older-host UI execution were explicitly deferred by the user and remain unverified. Shared C++ changes and public release are not fully committed or accepted by this documentation archive.
