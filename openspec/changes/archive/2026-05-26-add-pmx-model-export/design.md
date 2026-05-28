## Context

当前 PMX 导入链路已经把外部 `libmmd::PMXFile` 拆分到 C4D 对象、tag 参数、材质数据、morph UI、display frame 数据以及刚体/关节对象中。导出方向已有若干未完成入口：`CMTToolsManager::ExportPMXModel()` 目前直接返回成功，`CMTSceneManager::SavePMXModel()` 只做了选中对象检查和 `MMDModelManagerObject::SavePMX()` 调用，`MMDMeshManagerObject::SavePMX()` 是 stub，骨骼导出也只写了基础字段。

本设计补齐“插件管理的 MMD 模型回导 PMX”能力。导出目标是当前选中的 `MMDModelManagerObject`，不是通用 C4D 模型转换器。导出数据来源以插件已经持久化的 PMX 参数和当前 C4D 编辑态为准，输出为新构造的 `libmmd::PMXFile`。

## Goals / Non-Goals

**Goals:**

- 接通模型页 PMX 导出入口，并让导出失败时返回明确错误而不是静默成功。
- 从当前 `MMDModelManagerObject` 重建 `libmmd::PMXFile` 并写入 `.pmx`。
- 导出 metadata、骨骼、mesh、权重、材质/贴图、display frame、支持的 morph、刚体和关节。
- 导出前同步 EDIT 态编辑结果，使骨骼、刚体和关节使用用户当前编辑后的参数。
- 添加 round-trip 验证，导出后能被 `libmmd::ReadPMXFile()` 重新读取并满足核心 section/索引不变量。

**Non-Goals:**

- 不支持任意普通 C4D polygon/skin/joint 场景转 PMX。
- 不在 v1 保存或 patch 原始 PMX blob，也不保证未知 PMX section 无损透传。
- 不把运行时逐帧 IK/物理结果 bake 成 PMX 静态模型。
- 不实现 softbody 导出，除非后续已有独立导入和持久化语义。

## Decisions

### 决策 1：采用重建式导出，而不是原始 PMX 快照 patch

**选择**：导出时创建新的 `libmmd::PMXFile`，由 model/bone/mesh/rigid/joint/material/display-frame/morph 数据填充后写出。

**理由**：

- 当前代码没有原始 PMX blob 的稳定持久化结构，直接引入快照会增加存档体积、兼容迁移和未支持段合并复杂度。
- 重建式导出能反映用户在 C4D 中做过的骨骼、mesh、材质、刚体和关节编辑。
- v1 可以清楚声明不保证 SDEF/QDEF、softbody 和未知扩展无损，降低第一版风险。

**替代方案**：保存原始 PMX 并 patch 已编辑字段。保真更强，但需要新增存档格式、版本迁移和冲突规则，不适合作为第一版。

### 决策 2：导出入口复用现有工具对话框和设置结构

**选择**：在模型页新增导出分组和按钮，读取 `CMTToolsSetting::ModelExport`，通过 `filename_util::SelectSuffixExportFile(setting.fn, "pmx"_s)` 选择路径。

**理由**：

- 与 camera/motion 导出入口一致，用户无需学习新的命令入口。
- 现有 `ModelExport` 已包含 polygon、normal、uv、material、bone、weights、ik、inherit、expression 等开关，可以作为导出选项基础。
- 配置默认值可接入 `CMTToolConfigManager`，保持工具面板状态持久化。

**替代方案**：新增独立命令或 scene saver。独立命令仍需要一套 UI 设置；scene saver 会让“选中 MMD model 才可导出”的约束变得不直观。

### 决策 3：导出前先提交编辑态参数

**选择**：`SavePMX` 收集数据前，复用或抽出当前 EDIT -> ANIM 边界中的提交逻辑，把骨骼 frozen/bind、`PMX_BONE_POSITION`、mesh bind pose、刚体参数和关节参数同步为当前编辑结果。

**理由**：

- 用户期望导出的是当前可见、可编辑模型，而不是最初导入时的旧 PMX 参数。
- 仅提交骨骼会让物理重建仍读取 stale rigid/joint 数据；导出必须把骨骼、刚体、关节作为一个模型编辑边界处理。
- 这与当前运行时恢复和模式切换语义一致，避免给导出引入单独的状态规则。

**替代方案**：导出时只读 BaseContainer 中已有参数。实现简单，但会漏掉用户通过对象 transform 编辑后的状态。

### 决策 4：按 PMX section 顺序分层写入

**选择**：`MMDModelManagerObject::SavePMX()` 负责 header/info、section 编排、材质/贴图和 display frame/morph 汇总；bone/mesh/rigid/joint manager 各自负责自身 section。

**理由**：

- 导入路径已经按 manager 拆分，反向导出保持同样边界最容易维护。
- mesh 权重需要 bone index，材质 face count 需要 mesh face 划分，因此 model manager 应协调 section 顺序和跨 section 不变量。
- rigid/joint 依赖骨骼和刚体索引，放在对应 manager 中写出但由 model manager 控制调用顺序。

**替代方案**：由单个导出器扫描全场景并写完整 PMX。集中实现初期快，但会绕开现有 manager 的持久化数据和同步规则。

### 决策 5：贴图表先于材质索引生成

**选择**：导出时先从 `MMDMaterialData` 收集 texture、sphere texture、toon texture 路径，构建去重后的 `pmx_file.m_textures`，再把材质中的路径转换为 PMX texture indices。

**理由**：

- 当前 `MMDMaterialData::ToPMX()` 对 texture/sphere index 仍写 `-1`，直接复用会丢贴图引用。
- PMX 材质引用的是 texture table index，不是路径字符串。
- 统一建表可以处理多个材质共享同一贴图。

**替代方案**：让每个材质局部追加 texture。实现分散，容易出现重复路径和 index 偏移错误。

### 决策 6：测试以可重读和不变量为第一验收

**选择**：新增 focused round-trip 测试，导出后用 libMMD 重新读取，并检查 section count、材质 face vertex 总数、bone parent/IK links、rigid/joint 索引关系。

**理由**：

- PMX 二进制格式问题最容易通过写出后重读暴露。
- v1 不追求逐字节一致，应该验证语义不变量而不是与原文件完全相同。
- 这类测试能覆盖用户实际最关心的“导出的文件能被 PMX 读回”。

**替代方案**：只做插件 build 或手动导出。无法稳定覆盖 PMX section 写入错误。

### 决策 7：网格基准形态优先来自 PoseMorph base，而不是当前对象点

**选择**：mesh 导出时优先读取 `CAPoseMorphTag` 第 0 个 base morph point node 作为 PMX base mesh position；当前对象点只作为 fallback。导出前仍临时清零并恢复插件记录的 morph 强度。

**理由**：

- 在 ANIM 模式或当前帧有表情动画时，`PolygonObject::GetPointR()` 可能已经反映了当前表情状态，直接写出会把闭眼等表情烘焙到 PMX base mesh。
- 导入时已经把原始静态点位存入 PoseMorph base，使用它更符合“重建静态 PMX 模型”的导出语义。
- 清零强度只能减少运行时状态影响，不能替代使用稳定的基准点位来源。

**替代方案**：导出前切换文档时间或强制重评估为无动画帧。这样会干扰用户当前时间状态，也可能触发动画/IK/物理重评估副作用。

### 决策 8：IK 动态描述读取必须先判定 `GeData` 类型

**选择**：只有 `GeData::GetType() == DA_ALIASLINK` 时才调用 `GeData::GetBaseLink()`；旧场景的 numeric/string index 走独立 fallback。结构化 dynamic-description 解析失败时，复用运行时 IK 的字段名/浏览顺序 fallback。

**理由**：

- Cinema 4D Debug SDK 会在非 link `GeData` 上调用 `GetBaseLink()` 时触发 `0x80000003` 断点异常。
- IK link 数据经历过资源布局和动态描述迁移，旧场景可能同时存在 link、long、string 或空名字段。
- 导出侧需要和运行时 IK 链解析保持兼容，否则导出的 PMX 重新导入后 IK 链会缺失。

**替代方案**：只依赖导入时保存的 numeric index。实现简单，但骨骼层级同步后 index 可能过期，导出会重新产生失效 IK。

## Risks / Trade-offs

- **[Risk] C4D 权重无法完整恢复 PMX SDEF/QDEF 辅助数据** → v1 明确不保证无损；如果导入已保存 SDEF tags，则优先使用已保存数据，否则退化为可表达的 BDEF 权重。
- **[Risk] 材质 face count 与 mesh face 顺序不一致会生成非法 PMX** → mesh 导出必须按材质 selection 顺序生成面列表，并在测试中检查材质 face vertex 总和等于 faces * 3。
- **[Risk] 刚体/关节编辑态未提交导致导出后物理偏移** → 导出前调用统一编辑态提交入口，覆盖骨骼、刚体和关节。
- **[Risk] 导出选项组合可能产生不完整 PMX** → v1 对核心依赖做保护：导出 mesh 权重需要骨骼；导出刚体/关节需要骨骼/rigid section，缺失时返回错误或跳过依赖 section 并提示。
- **[Risk] OpenSpec 范围过大导致实现拖长** → 任务分阶段执行，先接通入口和可重读基础模型，再补齐高风险 section。
