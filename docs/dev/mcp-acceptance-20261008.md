# 生产 MCP：2026-10-08 Windows 验收

本次完成 `add-production-mcp-support` 的 Windows / C4D 2026.4+ 范围。
用户明确允许延期 macOS 与旧宿主 UI 实测，两项均保持 **deferred / unverified**。
SDK 2026 Release 与 R20 Debug 编译通过，不能据此认定旧宿主 UI 已通过。

当前生产 C++ 仍与共享材质修改处于工作树；本记录描述实际构建、加载和验证的模块。
验证脚本或文档的提交不表示检出该提交即可获得全部生产实现，也不表示公开安装包已发布。

## 模块与收据

- 宿主：Cinema 4D `2026400`，Windows。
- 普通 Release：`806a50913b36db18a894c11ce868e74cb3908d741d9c65d476658e6d090e0422`。
- 维护源码/资源指纹：`f75f9c77494be0214803a60b516670fcb4e7e6fbbd899e201d931f60a8f04899`。
- 生产验收回归桥：**OFF**；16 个工具从真实 HTTP 与 stdio 入口调用。
- [汇总](../../_build_msvc/validation/production-mcp-20261008/summary.json)包含各证据入口。
  该目录还保存模块、完整维护源码/资源快照、构建日志和失败后修复重跑的最终记录。

| 验证 | 结果 | 收据 |
| --- | --- | --- |
| 普通 Release 八阶段 | 8/8，原文档恢复、所属文档清理完成 | [typed receipt](../../_build_msvc/validation/production-mcp-20261008/typed/receipt.json) |
| 无效导入 | PMX/动作/相机 × 缺失/截断/错误格式，共 9 例；场景不变 | 同一 typed receipt 的 invalid 阶段 |
| VMD 名称报告 | 匹配输入无误报；未匹配骨骼/表情名称精确返回 | 同一 typed receipt 的 motion 阶段 |
| 写入失败 | 三种格式 × 四种真实写入失败，共 12 例；旧文件、源状态与临时文件清理符合要求 | 同一 typed receipt 的 invalid 阶段 |
| UV offset | merged/split × direct/reopened，共 4 例；每例 8 个 offset，源 UV、强度与编辑模式不变 | [UV receipt](../../_build_msvc/validation/production-mcp-20261008/uv/receipt.json) |
| Impulse 数据 | 直接导出、倍率 2/.5、重开、复制、刚体重排、目标缺失，共 7 例 | [Impulse receipt](../../_build_msvc/validation/production-mcp-20261008/impulse/receipt.json) |
| 干净客户端与超时恢复 | 打包目录入口，无 pip/第三方包；超时、去重和重连恢复通过 | [before-restart](../../_build_msvc/validation/production-mcp-20261008/recovery-before/before-restart.json) |
| 宿主重启 | PID 58448 → 35888，同一生产模块；五类旧句柄拒绝，旧操作状态未知，新句柄可用 | [after-restart](../../_build_msvc/validation/production-mcp-20261008/recovery-after/after-restart.json) |
| 现有业务回归 | 9/9，通过独立测试构建重跑 | [business receipt](../../_build_msvc/validation/production-mcp-20261008/business/receipt.json) |
| CTest | 19/19，其中适配器测试集为 35/35 | [CTest log](../../_build_msvc/validation/production-mcp-20261008/logic-tests.log) |

九项旧业务回归使用独立的 Debug/测试桥 ON 模块 `c9271068…`，包括模式绑定、层级、动画槽、
物理开关、材质表情、动作烘焙和相机导出。该证据与普通 Release 生产 MCP 的桥 OFF 验收分开记录。

## 修复的导出缺口

Cinema 4D 的 `CAMorphNode` 访问器要求先展开 Morph 数据。原 UV 导出直接读取压缩数据，
原生探测中 `GetUVCount` 为 0；展开后才得到实际面数。导出现在使用作用域恢复，
同时修复同一面只写一个角点及分材质网格误用全局面索引的问题。

Impulse Morph 现在保留刚体链接、local 标志、平移速度和旋转力矩，支持场景保存和复制。
刚体链接随场景复制翻译，删除其他刚体导致索引重排时仍指向原目标；目标刚体缺失则拒绝导出，
不会覆写已有文件。平移速度随长度倍率换算，旋转力矩不缩放。PMX 输出保持 2.1 版本边界。
Model 场景级别升到 6，补齐表情 panel 与对应 UI ID 的保存；旧级别不读取新增字段。

## 超时与重启的证据边界

超时用例在本机代理中**延迟真实 C4D 已完成操作的 HTTP 响应 2.5 秒**。
普通打包适配器的 1 秒超时返回 `transport_timeout` / `outcome_unknown`；
重复 UUID 不再次送入宿主。查询原 UUID 后恢复 `completed`，场景强度为 0.37，实际修改请求计数为 1。
这是明确的网络响应故障注入，未宣称真实宿主崩溃或断电恢复。

测试宿主在所属测试场景保存并清理后重启，再加载保存场景验证旧文档、模型、表情、槽和相机句柄。
本机宿主没有发放 HTTP Session ID，过期 HTTP 会话用例记录为不适用；宿主 nonce 和实例句柄失效已实测。
没有将“不适用”登记为一个通过的有状态 HTTP 会话用例。

复现入口为 [八阶段 runner](../../scripts/c4d_production_mcp_validation.py)与
[两阶段恢复 runner](../../scripts/c4d_mcp_recovery_validation.py)。后者接受普通 Release 模块、cache、
endpoint、token 文件路径、干净 Python 和打包适配器入口；重启操作由调用者仅对已清理的测试宿主执行。
凭据内容不进入日志或收据。

Additional UV 的独立渲染语义、Impulse 对物理求解器的实际施加、RS Toon 的 MMD 外观对齐、
真实模型 seek 重放、macOS、旧宿主 UI 与公开发布仍属于各自的后续验收范围。
