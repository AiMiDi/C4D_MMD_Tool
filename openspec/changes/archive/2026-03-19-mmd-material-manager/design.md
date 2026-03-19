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

### 决策 9：Toon 模式控制索引和路径的启用/禁用

**选择**: 
- `toon_mode == 1`（共用）时：启用 `MODEL_MATERIAL_TOON_TEXTURE_INDEX` 下拉框（CYCLE 选项 toon01-toon10.bmp），禁用 `MODEL_MATERIAL_TOON_TEXTURE_PATH`（路径从索引自动派生）
- `toon_mode == 0`（独立）时：禁用 `MODEL_MATERIAL_TOON_TEXTURE_INDEX`，启用 `MODEL_MATERIAL_TOON_TEXTURE_PATH`（路径来自 PMX 纹理数组或用户手动设置）
- 修改 toon_texture_index 或 toon_mode 时自动重新生成 toon_texture_path

**理由**:
- 共用模式下 toon 索引对应 mikumikudance_data 中的固定 10 个 toon 贴图，适合用 CYCLE 下拉选择
- 独立模式下 toon 纹理来自 PMX 纹理数组，索引在导入时已转为路径，用户可直接编辑路径
- 两种模式互斥，分别控制启用状态避免用户困惑

### 决策 10：材质 Mesh 关联与列表管理按钮

**选择**: 
- 在 `MMDMaterialData` 中新增 `mesh_link` 和 `selection_name` 字段，关联材质所属的 mesh 对象及选集标签名
- 在材质列表旁使用 `GROUP { COLUMNS 2; }` 布局：左侧材质列表 CYCLE，右侧嵌套 `GROUP { COLUMNS 4; }` 放置 ↑ ↓ × + 四个按钮
- × 删除按钮（-）行为：弹出提示框告知用户会删除对应的 mesh。用户确认后，若 `selection_name` 非空，则删除选集对应多边形部分；如果没有选集，则移除整个 mesh 对象。此操作需加入 Undo 系统。
- + 添加按钮（+）行为：手动触发材质列表更新。对比当前 `material_list_` 和实际的 mesh 对象/选集。若发现新的对象或选集：
  - 若该 mesh/选集已有 `Ttexture` 标签且关联了 C4D 材质：引用该已有材质并调用 `ReadFromStandardMaterial` 将颜色、纹理等属性反向更新到 MMD 材质数据
  - 若该 mesh/选集无材质：根据新建的 MMD 材质数据调用 `CreateStandardMaterialFromData` 生成 C4D 材质，插入文档，并在 mesh 上创建 `TextureTag`（如为选集则设置 `TEXTURETAG_RESTRICTION` 指定选集名）
  - 若无新增，则添加按钮无效。

**理由**:
- mesh_link 和 selection_name 建立了材质与场景中几何体的关联，便于定位和管理
- 四按钮布局提供完整的列表 CRUD 操作
- 删除操作涉及实际几何体的修改，提供确认框和 Undo 支持可防止误操作并提供安全保障
- 将添加操作从单纯的“新建空条目”改为“手动从场景同步新增材质”，更符合实际工作流，并优化性能

### 决策 11：Mesh-材质同步机制

**选择**: 放弃全自动的增量同步，改为“手动添加同步 + 自动删除检测”相结合的机制：
1. **添加同步（手动）**：如决策10所述，用户点击 `+` 按钮时对比列表和 mesh，如有对象或选集新增情况：若 mesh 已有 `Ttexture` 标签指向现有 C4D 材质，则引用该材质并反向读取属性到 MMD 数据；否则创建新 C4D 材质和 TextureTag。
2. **删除检测（自动）**：在 `MMDModelManagerObject::Execute` 等合适的时机，检测子 mesh 对象或者选集是否被删除。如果发现已被删除，则自动移除对应的 list 条目和 MMD 材质 data。

**理由**:
- 手动触发新增同步可以避免频繁遍历场景节点造成的性能开销，同时让用户明确知道何时添加了新材质管理条目
- 自动检测删除则能保证数据有效性，避免持有悬空指针（无效的 mesh 或 material link）

**风险**: 自动删除检测需轻量化，只需校验现有链接的有效性，避免性能开销。

### 决策 12：Adapter 设计模式重构

**选择**: 将各渲染器的 4 个 free function 重构为 `MMDMaterialAdapter` 抽象基类 + 4 个渲染器子类（`MMDStandardMaterialAdapter` / `MMDRedShiftMaterialAdapter` / `MMDOctaneMaterialAdapter` / `MMDCoronaMaterialAdapter`）。

基类提供：
- 4 个纯虚方法：`CreateFromPMX` / `CreateFromData` / `SyncTo` / `ReadFrom`
- 静态工厂 `Create(type)` / `CreateFor(material)` + 检测 `DetectType(material)`
- 共享工具 `DetectTextureFromPMX` / `DetectTextureFromData`（提取原 4 个 `CreateFromPMX` 中重复的纹理/Alpha 检测逻辑）
- 保留 `SyncToMaterial` / `ReadFromMaterial` / `CreateMaterialFromData` 便捷 free function（内部创建 adapter），保持调用方兼容性

**检测逻辑**（参考 D5 `d5_plugin_manager.cpp:399-436` 的 switch 结构）：
```
switch (material->GetType())
  case Mmaterial:
    if (IsNodeBased() && HasSpace(redshiftId)) → RedShift (3.5+)
    else → Standard
  case ID_REDSHIFT_MATERIAL → RedShift (3.0)
  case ID_OCTANE_DIFFUSE_MATERIAL → Octane
  case ID_CORONA_MATERIAL → Corona
  default → Unknown
```

**理由**:
- 消除 RedShift 材质（`Mmaterial` 类型 + RS node space）与 Standard 检查的重叠问题
- Adapter 模式提供接口约束，新增渲染器只需继承基类、实现 4 个方法、在工厂注册
- 共享纹理检测消除 80%+ 重复代码
- 便捷 free function 保持调用方兼容性

**替代方案**: 保持 free function + switch 分发——功能等价但缺乏接口约束，新增渲染器需修改多个 switch

## Risks / Trade-offs

- **[Risk] 属性数量多导致 UI 拥挤** → 使用折叠分组（`DEFAULT 0` 默认折叠）组织材质色、描绘、轮廓线、纹理等子分组
- **[Risk] 序列化版本兼容** → 在 `Read` 方法中使用 level 参数检测是否存在材质数据段，缺失时跳过（向后兼容）
- **[Risk] BaseLink 在材质被手动删除后失效** → 在 `Execute` 或 `GetDParameter` 中检查 link 有效性，无效时显示为空
- **[Risk] 大量材质时性能问题** → CYCLE 列表和数据数组均为 O(1) 索引访问，不存在性能瓶颈；典型 PMX 模型材质数量在 10-50 个范围内
- **[Risk] Mesh-材质同步的性能开销** → 采用手动添加同步（点击+按钮）避免了频繁的场景遍历开销，自动删除检测仅需校验现有链接的有效性，开销极小
- **[Risk] 材质排序后序列化兼容** → 排序只改变数组内元素顺序，不影响序列化格式
