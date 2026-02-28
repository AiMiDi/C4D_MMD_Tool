## Context

当前 PMX 导入流程中，`MMDMaterialManager` 是一个纯粹的辅助类（非 C4D 节点），仅在 `MMDMeshManagerObject::LoadPMX` 导入时临时创建，将 PMX 材质转换为 C4D `BaseMaterial` 后即销毁。导入后，MMD 材质的特有属性（描绘标志、轮廓线、Toon/高光贴图模式等）全部丢失，用户无法在 C4D 中查看或编辑这些参数。

现有的管理器模式（`MMDBoneManagerObject`、`MMDMeshManagerObject`）已经建立了良好的架构范例：
- 继承 `ObjectData`，作为 `MMDModelManagerObject` 的子对象
- 使用 `BaseContainer` / `HashMap` 存储索引化数据
- 通过 `BaseLink` 关联 C4D 对象
- 实现 `Read/Write/CopyTo` 进行序列化
- 在 `LoadPMX/SavePMX` 中处理数据转换

材质管理器**不采用**独立子对象模式。与骨骼/网格不同，材质数据直接展示在 `MMDModelManagerObject` 的属性管理器上（类似现有的 Morph 管理和动画列表），通过动态描述系统实现 UI。

## Goals / Non-Goals

**Goals:**
- 在 `MMDModelManagerObject` 属性管理器中提供完整的 MMD 材质编辑 UI
- 持久化存储所有 PMX 材质属性（`PMXMaterial` 完整字段）
- 通过 `BaseLink` 将每个 MMD 材质关联到对应的 C4D `BaseMaterial`
- 材质属性修改时自动同步到 C4D 材质的对应通道
- PMX 导入时自动填充材质数据，导出时读取完整数据
- 支持 `Read/Write/CopyTo` 序列化以确保项目保存/加载正确

**Non-Goals:**
- 不创建独立的材质管理器子对象（`ObjectData`），所有 UI 和数据集成在 `MMDModelManagerObject` 中
- 不支持实时预览 Toon/高光贴图效果（仅存储路径和模式参数）
- 不支持材质变形（Material Morph）的编辑（已有独立的 Morph 系统处理）
- 不实现 RedShift/Octane 材质的完整双向同步（仅同步标准材质通道）
- 不实现 MMD 材质编辑器独立对话框

## Decisions

### 决策 1：在 MMDModelManagerObject 上使用动态描述而非独立子对象

**选择**: 将材质 UI 直接嵌入 `MMDModelManagerObject` 的属性管理器中，使用动态描述系统

**理由**:
- 与现有的 Morph 管理 UI 模式一致（都是在 ModelManager 上通过动态描述实现）
- 材质与模型是 1:1 关系，不需要像骨骼那样作为独立的场景对象层级
- 避免引入新的插件 ID 和对象类型，降低复杂度
- 用户在同一属性面板中即可访问所有模型级别的管理功能

**替代方案**: 创建 `MMDMaterialManagerObject` 子对象——增加了对象层级复杂度，且材质不需要在场景中独立存在

### 决策 2：材质数据存储方案

**选择**: 在 `MMDModelManagerObject` 中使用 `maxon::BaseArray<MMDMaterialData>` 存储材质列表，每个 `MMDMaterialData` 包含完整的 PMX 材质字段和一个 `AutoAlloc<BaseLink>` 指向 C4D 材质

**理由**:
- 结构化存储，便于索引访问和序列化
- `BaseLink` 是 C4D SDK 中关联节点对象的标准方式，支持项目保存/加载后的引用恢复
- 与 `MMDBoneManagerObject` 的 `bone_list_` 模式一致

**替代方案**: 使用 `BaseContainer` 存储所有材质属性——数据类型过多，BaseContainer 的类型系统不够灵活

### 决策 6：文件组织——material 子目录按职责分层

**选择**: 新建 `refactoring/module/tools/material/` 目录，按职责组织文件：

```
refactoring/module/tools/material/
  mmd_material.h/cpp                 - MMDMaterialData 纯数据结构 + FromPMX/ToPMX/序列化
  mmd_standard_material.h/cpp        - 标准材质：导入创建 + 属性同步到 C4D 标准材质
  // 未来扩展:
  mmd_redshift_material.h/cpp        - Redshift 材质：导入创建 + 同步
  mmd_octane_material.h/cpp          - Octane 材质：导入创建 + 同步
```

现有 `refactoring/module/tools/mmd_material.h/cpp`（`MMDMaterialManager` 导入辅助类）迁移到此目录并拆分：纯数据部分进入 `mmd_material.h/cpp`，标准材质的创建和同步逻辑进入 `mmd_standard_material.h/cpp`。

**理由**:
- 职责分离：数据模型与材质类型相关的创建/同步逻辑分开
- 可扩展性：未来添加 RS/OC 材质支持时只需新增文件，不修改已有代码
- 现有 `MMDMaterialManager::LoadPMXMaterial` 中的 `switch (import_material_type)` 各分支可自然拆分到对应文件

**替代方案**: 全部放在单个 `mmd_material.h` 中——随着 RS/OC 逻辑增加，文件会膨胀且职责混杂

### 决策 3：材质列表 UI 使用 CYCLE 下拉列表

**选择**: 使用 `LONG` + `CYCLE` 类型的下拉列表选择当前编辑的材质（类似现有的动画列表 `MODEL_ANIM_LIST`）

**理由**:
- 与现有动画列表 UI 模式一致
- 实现简单，通过 `GetDDescription` 动态填充 CYCLE 选项
- 切换选中项时通过 `SetDParameter` 更新下方的属性编辑区

**替代方案**: 使用 `SimpleListView` 或 `TreeView` 自定义 GUI——复杂度高，与现有 UI 风格不一致

### 决策 4：属性编辑区使用静态描述 + 动态值绑定

**选择**: 在 `OMMDModelManager.res` 中静态定义材质属性的所有 UI 元素（颜色、标志、数值等），在 `GetDParameter/SetDParameter` 中动态绑定到当前选中材质的数据

**理由**:
- 材质属性结构固定（所有材质共享相同的属性集），适合静态描述
- 避免为每个材质动态创建/销毁大量描述项
- `GetDParameter/SetDParameter` 的动态绑定模式在 C4D 插件中是标准做法

**替代方案**: 完全使用动态描述——不必要的复杂，且材质属性数量固定

### 决策 5：同步策略——单向推送

**选择**: 当用户在 MMD 材质 UI 中修改属性时，通过 `SetDParameter` 检测变更，主动将对应值推送到 C4D 材质

**理由**:
- 明确的数据流方向：MMD 材质 UI → C4D 材质
- 避免双向同步的复杂性和循环更新问题
- C4D 材质的直接修改不影响 MMD 数据（这是预期行为，MMD 数据作为"源"）

### 决策 7：导入工具对话框添加材质类型选择

**选择**: 在 `DLG_CMT_TOOL.res` 的模型导入设置区域新增一个 `COMBOBOX` 控件（`DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL_TYPE`），选项为标准材质/RedShift/Octane。在导入按钮处理逻辑中通过 `GetItem` 读取用户选择并写入 `setting.import_material_type`。

**理由**:
- `CMTToolsSetting::ModelImport::material_type` 枚举已存在但从未在 UI 中暴露，当前硬编码为 `Standard`
- 遵循现有对话框的 checkbox/combobox 模式，在材质 checkbox 旁添加类型选择

**替代方案**: 在 `OMMDModelManager.res` 材质管理 UI 中设置全局材质类型——但导入时的材质类型选择应在导入前决定，放在导入对话框更合理

### 决策 8：材质管理 UI 添加创建材质和同步按钮

**选择**: 在 `OMMDModelManager.res` 的材质管理分组中新增：
- `MODEL_MATERIAL_CREATE_TYPE`（`LONG` + `CYCLE`）：选择要创建的材质类型（标准/RedShift/Octane）
- `MODEL_MATERIAL_CREATE_BUTTON`（`BUTTON`）：根据当前 `MMDMaterialData` 属性创建新的 C4D 材质，插入到文档中，并更新 `material_link`
- `MODEL_MATERIAL_SYNC_BUTTON`（`BUTTON`）：将当前选中材质的所有 MMD 属性手动同步到 `material_link` 关联的 C4D 材质

**理由**:
- 创建按钮支持在不重新导入的情况下为 MMD 材质生成 C4D 材质（例如更换渲染器后重新创建材质）
- 同步按钮提供显式的手动同步入口，与自动同步（`SetDParameter` 触发）互补
- 材质类型下拉框放在创建按钮旁边，仅在点击创建时使用

## Risks / Trade-offs

- **[Risk] 属性数量多导致 UI 拥挤** → 使用折叠分组（`DEFAULT 0` 默认折叠）组织材质色、描绘、轮廓线、纹理等子分组
- **[Risk] 序列化版本兼容** → 在 `Read` 方法中使用 level 参数检测是否存在材质数据段，缺失时跳过（向后兼容）
- **[Risk] BaseLink 在材质被手动删除后失效** → 在 `Execute` 或 `GetDParameter` 中检查 link 有效性，无效时显示为空
- **[Risk] 大量材质时性能问题** → CYCLE 列表和数据数组均为 O(1) 索引访问，不存在性能瓶颈；典型 PMX 模型材质数量在 10-50 个范围内
