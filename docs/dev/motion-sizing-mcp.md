# 动作适配 MCP 调试接口

2026-10-09 新增 11 个生产工具，适配器共公开 27 个 typed tools。接口复用 `HostSession` 和独立 C++ 适配库，不依赖 `CMT_ENABLE_RUNTIME_REGRESSION`。宿主连接方法见 [MCP 客户端](mcp-client.md)。

## 工具

所有适配调用都要求来源 `document` 句柄。除启动外，还要求启动结果中的 `job` 句柄。句柄绑定当前宿主会话和来源文档，不能使用对象名称或旧会话的句柄。

| 工具 | 输入 / 行为 |
| --- | --- |
| `mmdtool_sizing_start` | `characters`：1–16 个目标模型，每项含 `model`、`source_pmx`，以及二选一的动作 `path` 或 `slot`；返回任务句柄 |
| `mmdtool_sizing_status` | 非阻塞轮询 `job_state`、角色数、相机是否可用、预览文档句柄与失败原因 |
| `mmdtool_sizing_result` | `member` 选择角色；`section` 为 `summary` / `stages` / `warnings` / `constraints`；`offset` / `limit` 分页 |
| `mmdtool_sizing_cancel` | 请求协作取消；继续轮询到终态，不发布或应用部分结果 |
| `mmdtool_sizing_preview` | `stage`、`member`、`overlay`；在临时文档显示整个角色批次的前后对比，角色选择决定焦点 |
| `mmdtool_sizing_close_preview` | 关闭该任务拥有的临时文档，保留计算结果 |
| `mmdtool_sizing_apply` | 将 `member` 的 `stage` 应用为新动画槽，返回模型与槽句柄；检查整个批次的目标绑定快照 |
| `mmdtool_sizing_export` | 导出 `member` 的 `stage`，要求绝对 VMD `path`；`overwrite` 默认为 false |
| `mmdtool_sizing_apply_camera` | 将调整后的相机加入来源文档，返回新相机句柄 |
| `mmdtool_sizing_export_camera` | 导出调整后的相机，沿用覆盖保护和文件身份校验 |
| `mmdtool_sizing_release` | 释放终态任务及其预览；运行中的任务须先取消并轮询 |

`member` 为从零开始的批次序号，默认 0。阶段名称为 `original`、`scale`、`offset`、`stance`、`twist`、`avoidance`、`contact`、`multi_character`，默认最终阶段 `multi_character`。禁用的算法阶段沿用前一个阶段的结果。

启动还接受共享 `sizing_options`、可选 `camera_path` 和 `max_camera_distance_ratio`（默认 5，范围 1–100）。每个角色的 `sizing_options` 覆盖共享参数。所有角色要求同一来源文档、不同模型和相同模型导入倍率；算法空间及距离统一为 PMX/VMD 单位。

## 调用示例

先调用 `mmdtool_capabilities`、`mmdtool_list_models`，需要使用已导入动作时再调用 `mmdtool_list_animation_slots`。将下列占位符替换为本次发现的句柄。

```json
{
  "name": "mmdtool_sizing_start",
  "arguments": {
    "document": "<来源文档句柄>",
    "characters": [
      {
        "model": "<目标模型句柄>",
        "source_pmx": "C:/pmx/source.pmx",
        "slot": "<该模型的动作槽句柄>"
      }
    ],
    "sizing_options": {
      "stance": true,
      "twist": true,
      "movement_multiplier": 1.0
    }
  }
}
```

也可以用 `"path": "C:/vmd/motion.vmd"` 替换 `slot`。每项必须且只能提供其中一个，槽按稳定运行期 identity 在隔离文档副本中读取。

启动请求的外层 `state=completed` 表示启动操作已经完成，**计算状态看 `data.job_state`**。任务状态为 `running`、`cancelling`、`completed`、`cancelled` 或 `failed`；工具返回的外层 `success=true` 并不表示任务已求解成功。只有任务 `completed` 才能查询结果、预览或应用。

每次轮询使用新的 `operation_id`，或省略该字段让适配器生成；同一 ID 返回缓存响应。启动、应用、导出超时后先用原 `operation_id` 调用 `mmdtool_operation_status`，确认实际结果，避免重复启动或创建动画槽。

```json
{"name":"mmdtool_sizing_status","arguments":{"document":"<来源文档句柄>","job":"<任务句柄>"}}
{"name":"mmdtool_sizing_result","arguments":{"document":"<来源文档句柄>","job":"<任务句柄>","section":"constraints","limit":64}}
{"name":"mmdtool_sizing_preview","arguments":{"document":"<来源文档句柄>","job":"<任务句柄>","stage":"stance"}}
```

诊断摘要包含比例、局部偏移、匹配轨道数、修改关键帧数、约束数、未解决数、最大残差、警告数、保留的约束样本数及耗时。约束页含阶段、帧、骨名、目标位置、实际位置和误差。`total` 是该列表保留的条目数；`max_diagnostics` 截断明细时，摘要仍保留总约束统计。阶段页显示每个阶段的骨骼/表情关键帧数量及最大帧。

## 参数和资源边界

| 参数 | 核心默认值 | 接口范围 |
| --- | --- | --- |
| `movement_multiplier` / `leg_offset` | 1 / 0 | (0,1000] / [-10000,10000] |
| `center_offsets` / `leg_offsets` | true / true | 布尔值 |
| `stance` / `twist` / `avoidance` | false | 布尔值 |
| `wrist_contact` / `finger_contact` / `floor_contact` / `multi_contact` | false | 布尔值 |
| `contact_distance` / `floor_height` | 0.3 / 0 | (0,10000] / [-10000,10000] |
| `collision_margin` / `tolerance` | 0.05 / 0.01 | [0,10000] / (0,1000] |
| `iterations` | 40 | 1–1000 |
| `max_bake_frames` / `max_baked_keys` / `max_diagnostics` | 18000 / 2000000 / 20000 | 1–18000 / 1–2000000 / 0–20000 |
| `avoidance_bodies` | 空列表，采用核心默认选择 | 最多 256 个刚体名称 |

最多保留 4 个任务，包括运行中任务；及时 `release`。任务在 900 秒无访问后，在后续适配调用时清理；运行中任务先取消，完成后再销毁。来源文档关闭也会在后续调用清理关联任务。宿主重启、释放或过期后的任务句柄拒绝复用。

只有纯数据求解在后台；快照、文件读取、预览模型生成和应用仍在 C4D 主线程，大模型可能短暂停顿。当前没有每次 CCD 迭代的进度或百分比，诊断对应完成的阶段结果。计算完成不等于所有可选骨链都支持，也不等于真实角色美术质量验收；算法边界见 [动作适配说明](vmd-sizing.md)。

## 验证与复验

首次接口交付时 Python 协议/固定调用测试 41/41 通过，SDK 2026 普通 Release（测试桥 OFF）编译通过。已通过真实 stdio 发现 11 个新增工具，但当时原会话的 C4D 仍加载旧模块，尚未执行新模块的原生业务回归。同一安装程序的第二个进程未保持运行，未重启或关闭原会话实例。

持久证据见 [本轮回执](validation/motion-sizing-mcp-20261009/receipt.json)。同一模块及运行资源已另存到 `_build_msvc/validation/motion-sizing-mcp-20261009/plugins/mmdtool/`，避免后续并行构建覆盖本轮产物；使用这份副本复验时，再传 `--build-cache _build_msvc/vmd-sizing-production/sdk_2026/CMakeCache.txt`。

新 Release 插件位于 `_build_msvc/vmd-sizing-production/sdk_2026/bin/Release/plugins/mmdtool/`。加载它之后，使用现有已授权的宿主 endpoint/token-file，运行下列脚本。脚本不启用服务、不启动或重启 C4D，也不使用测试桥；当前模块缺少接口时，在创建文档之前写出 `blocked` 回执。

```powershell
python scripts/c4d_sizing_mcp_validation.py `
  --endpoint http://127.0.0.1:5566/mcp `
  --token-file S:/tmp/cmt-vmd-sizing-native/prefs/prefs/mcp/token `
  --expected-binary C:/code/C4D_MMD_Tool/_build_msvc/vmd-sizing-production/sdk_2026/bin/Release/plugins/mmdtool/mmdtool.xdl64 `
  --output S:/tmp/cmt-sizing-mcp-native-<新的运行编号>
```

脚本覆盖加载模块身份、启动去重、嵌套参数冲突、双角色槽输入、分页诊断、八阶段预览及原场景保护、导出覆盖保护、相机、新槽 Undo/Redo、保存重开、绑定过期、取消和释放。取消允许任务已完成的竞态，并记录终态；所有文档属于测试且在成功清理后恢复原文档。合成用例不代表 Sour → 阿芙的完整视觉验证。Windows 以外平台及旧 SDK 未实测。


### 后续原生复验：2026-10-09

高级补全版已加载至 C4D 2026.4.0 / PID 72544，普通 Release、测试桥 OFF。`c4d_sizing_mcp_validation.py` 通过真实 stdio 完成 **27/27** 检查，`original_document_restored=true`、`remaining_owned_documents=[]`、`cleanup_errors=[]`。已在独立请求先切换活动文档，再关闭测试文档，避免宿主 exec 包装器在返回时访问已销毁的活动文档。

加载模块为 `_build_msvc/vmd-sizing-p4-sdk/bin/Release/plugins/mmdtool/mmdtool.xdl64`，SHA256 `de6759b521d4a47a697222945fdebda1b87e30f63bffa32fa1fa6ca2c025b5b2`。复验命令的 `--expected-binary` 对应该路径，`--build-cache` 使用 `_build_msvc/vmd-sizing-p4-sdk/CMakeCache.txt`。持久 [原生回执](../validation/vmd-sizing/advanced-completion/production-native/receipt.json) 和同目录 transcript 记录完整操作；保留首次旧模块 blocked 回执作为历史。

随后使用同一正式接口创建 Sour → 阿芙的 Stay Tonight 真实演示，PMX/VMD 场景尺寸均 8.5。真实角色的残差、演示工程与当前质量边界见 [动作适配说明](vmd-sizing.md)，合成接口通过不等于所有真实约束收敛。

### MCP 与动作适配面板同步

启动成功后，MCP 会发布完整有效输入；成功预览/应用后发布所选角色、阶段和叠加状态。已打开的面板通过主线程定时器回显，稍后打开也能恢复。状态查询不覆盖 UI 草稿；同步关闭自动计算，避免重复任务。面板使用同一任务的结果/预览，关闭面板不取消 MCP 任务。显式取消和关闭预览按钮仍作用于当前任务。

修改 UI 输入后会脱离 MCP 任务，后续计算使用面板独立会话。角色的独立选项与 UI 尚无控件的容差、迭代预算、避让刚体选择等参数均保留；不会把角色 1 的选项覆盖到整个批次。MCP 释放/过期后，面板不能通过持有强引用延长任务生命周期。

本次同步修复已通过普通 SDK 2026 Release 编译、现有 MCP 测试 41/41 与 OpenSpec 严格校验。当前 C4D 仍为修复前模块，**这些结果不等于 UI 原生同步通过**；重载后的原生验证待完成。见 [同步修复回执](../validation/vmd-sizing/ui-sync-20261009/receipt.json)。
