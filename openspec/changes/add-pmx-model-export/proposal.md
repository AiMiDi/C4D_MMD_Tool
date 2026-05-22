## Why

当前插件已有 PMX 导入、场景内编辑、存档恢复和运行时重建链路，但 PMX 导出入口仍未真正实现，用户无法把由插件管理的 MMD 模型从 Cinema 4D 回写成 PMX 文件。补齐 PMX 导出可以形成基础 round-trip 工作流，并为后续模型编辑、修正和跨工具交付提供明确出口。

## What Changes

- 新增 PMX 模型导出能力，仅支持从当前选中的 `MMDModelManagerObject` 导出，不做任意 C4D 场景到 PMX 的通用转换。
- 导出采用重建式策略：从当前 C4D 对象和插件持久化的 PMX 参数重新构造 `libmmd::PMXFile`，再通过 `libmmd::WritePMXFile()` 写出。
- 在模型工具页增加 PMX 导出入口和导出选项，复用现有 `ModelExport` 设置结构与 `SelectSuffixExportFile(..., "pmx")` 文件选择方式。
- 接通 `CMTToolsManager::ExportPMXModel`、`CMTSceneManager::SavePMXModel`、`MMDModelManagerObject::SavePMX` 和各子 manager 的 PMX section 写入流程。
- 导出前同步当前编辑态，确保骨骼、刚体和关节的编辑结果写回持久化 PMX 参数后再收集数据。
- v1 覆盖 metadata、骨骼、mesh 顶点/面/法线/UV、权重、材质/贴图、display frames、支持的 morph、刚体和关节。
- v1 明确不保证 softbody、任意未知扩展、原始 PMX 未支持段、SDEF/QDEF 等数据的无损透传，除非这些数据已由插件持久化并能重建。

## Capabilities

### New Capabilities

- `pmx-model-export`: 从插件管理的 MMD 模型重建并导出 PMX 文件，包括模型元数据、几何、骨骼、材质、morph、刚体和关节等核心 PMX section。

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **影响代码**：`cmt_tools_manager.*`、`CMTSceneManager.*`、`module/ui/cmt_tools_dialog.*`、`mmd_model_manager.*`、`mmd_bone_manager.*`、`mmd_mesh_manager.*`、`mmd_rigid_manager.*`、`mmd_joint_manager.*`、`mmd_material.*`。
- **影响资源**：`res/S24_up/dialogs/DLG_CMT_TOOL.res`、`res/S24_up/c4d_symbols.h`、对应中英文字符串和配置默认值。
- **影响依赖**：使用 libMMD 已有 `PMXFile` / `WritePMXFile`，不引入新第三方依赖。
- **兼容性**：旧场景文件无需迁移；导出行为只在用户主动选择 MMD ModelManager 并执行 PMX 导出时生效。
- **测试**：需要新增 round-trip 校验，导出后用 `ReadPMXFile` 重新读取并检查 section 计数和核心索引关系。
