## 1. 目录结构与数据定义

- [x] 1.1 新建 `refactoring/module/tools/material/` 目录，将现有 `mmd_material.h/cpp` 迁移到该目录下，并重构为纯数据结构文件：在 `material/mmd_material.h/cpp` 中定义 `MMDMaterialData` 结构体，包含完整 PMX 材质字段（diffuse/specular/ambient/draw flags/edge/texture indices/sphere mode/toon/memo/face count）和 `AutoAlloc<BaseLink>` 材质链接；保留 `MMDMaterialManager` 中与纹理路径管理相关的逻辑
- [x] 1.2 实现 `MMDMaterialData::FromPMX(const libmmd::PMXMaterial&)` 方法，从 PMXMaterial 映射所有字段，包括从 `PMXDrawModeFlags` 位标志提取各 draw_* 布尔值
- [x] 1.3 实现 `MMDMaterialData::ToPMX(libmmd::PMXMaterial&)` 方法，将所有字段写回 PMXMaterial，包括将 draw_* 布尔值合并为 `PMXDrawModeFlags` 位标志
- [x] 1.4 实现 `MMDMaterialData` 的 Read/Write 序列化方法（从/到 HyperFile），按固定顺序读写所有字段和 BaseLink
- [x] 1.5 实现 `MMDMaterialData` 的 CopyTo 深拷贝方法

## 2. 资源文件（描述/字符串）

- [x] 2.1 在 `OMMDModelManager.h` 中新增材质管理相关的所有描述 ID 枚举值（MODEL_MATERIAL_GRP, MODEL_MATERIAL_LIST, MODEL_MATERIAL_LINK, MODEL_MATERIAL_NAME_LOCAL, MODEL_MATERIAL_NAME_UNIVERSAL, 所有颜色/标志/轮廓线/纹理/备注/面数 ID，以及 CYCLE 枚举值）
- [x] 2.2 在 `OMMDModelManager.res` 中新增 `MODEL_MATERIAL_GRP` 分组及所有子属性的 UI 定义（包括材质列表 CYCLE、LINK、STRING、COLOR、REAL、BOOL、LONG 等控件）
- [x] 2.3 在 `strings_zh-CN/description/OMMDModelManager.str` 中新增所有材质相关属性的中文字符串
- [x] 2.4 在 `strings_en-US/description/OMMDModelManager.str` 中新增所有材质相关属性的英文字符串

## 3. MMDModelManagerObject 集成

- [x] 3.1 在 `MMDModelManagerObject` 类中新增材质管理相关的成员变量：`maxon::BaseArray<MMDMaterialData>` 材质列表、`Int32` 当前选中索引、`BaseContainer` 材质列表 CYCLE items
- [x] 3.2 在 `GetDDescription` 中动态填充材质列表 CYCLE 的选项（遍历材质列表，设置 "索引: 名称" 格式）
- [x] 3.3 在 `GetDParameter` 中实现材质属性的动态值读取——根据当前选中索引从 `MMDMaterialData` 读取对应字段值返回
- [x] 3.4 在 `SetDParameter` 中实现材质属性的动态值写入——将用户修改的值写入当前选中的 `MMDMaterialData`，并触发同步逻辑
- [x] 3.5 在 `Read` 方法中添加材质数据的反序列化（检测 level 兼容旧版文件），在 `Write` 方法中添加序列化
- [x] 3.6 在 `CopyTo` 方法中添加材质列表的深拷贝

## 4. PMX 导入集成

- [x] 4.1 重构 `MMDMeshManagerObject::LoadPMX` 中的材质导入流程，在创建 C4D 材质后，调用 `MMDModelManagerObject` 的接口将 `MMDMaterialData` 和 `BaseMaterial` 引用添加到材质列表
- [x] 4.2 在 `MMDModelManagerObject` 中添加 `AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material)` 接口方法

## 5. PMX 导出集成

- [x] 5.1 在 `MMDModelManagerObject::SavePMX` 中添加从材质列表读取 `MMDMaterialData` 并通过 `ToPMX` 写入 `PMXFile::m_materials` 的逻辑

## 6. 标准材质同步

- [x] 6.1 新建 `refactoring/module/tools/material/mmd_standard_material.h/cpp`，将现有 `MMDMaterialManager::LoadPMXMaterial` 中标准材质创建逻辑（`case Standard` 分支）迁移到此文件
- [x] 6.2 在 `mmd_standard_material.cpp` 中实现 `SyncToStandardMaterial(const MMDMaterialData& data, BaseMaterial* material)` 函数，将 MMD 材质属性同步到 C4D 标准材质（扩散色→颜色通道, Alpha→透明通道, 反射色→反射通道, 材质名称→SetName）
- [x] 6.3 在 `SetDParameter` 的材质属性写入逻辑中，修改完 `MMDMaterialData` 后根据材质类型调用对应同步函数将变更推送到关联的 C4D 材质

## 7. 导入工具对话框——材质类型选择

- [x] 7.1 在 `c4d_symbols.h` 中新增 `DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL_TYPE` 符号 ID
- [x] 7.2 在 `DLG_CMT_TOOL.res` 的模型导入设置区域新增 `COMBOBOX DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL_TYPE` 控件，选项为标准材质(0)/RedShift(1)/Octane(2)
- [x] 7.3 在 `DLG_CMT_TOOL.str`（中文/英文）中新增材质类型下拉框及各选项的字符串
- [x] 7.4 在 `cmt_tools_dialog.cpp` 的 `InitDialog` 中初始化 COMBOBOX 默认选中标准材质
- [x] 7.5 在 `cmt_tools_dialog.cpp` 的导入按钮处理逻辑中通过 `GetItem` 读取选中值并写入 `setting.import_material_type`

## 8. 材质管理 UI——创建材质按钮

- [x] 8.1 在 `OMMDModelManager.h` 中新增 `MODEL_MATERIAL_CREATE_TYPE`、`MODEL_MATERIAL_CREATE_BUTTON`、`MODEL_MATERIAL_SYNC_BUTTON` 及创建类型 CYCLE 枚举值的描述 ID
- [x] 8.2 在 `OMMDModelManager.res` 的 `MODEL_MATERIAL_GRP` 中新增创建材质类型下拉框（CYCLE: 标准/RS/OC）、创建材质按钮、同步材质按钮
- [x] 8.3 在 `OMMDModelManager.str`（中文/英文）中新增创建材质类型/创建按钮/同步按钮的字符串
- [x] 8.4 在 `MMDModelManagerObject::Message` 中处理 `MODEL_MATERIAL_CREATE_BUTTON` 的 `MSG_DESCRIPTION_COMMAND`：读取 `MODEL_MATERIAL_CREATE_TYPE`，根据类型调用对应的 `CreateStandardMaterialFromPMX`（或未来 RS/OC 函数）创建新材质，将其插入文档材质列表，更新当前 `MMDMaterialData` 的 `material_link`
- [x] 8.5 在 `MMDModelManagerObject::Message` 中处理 `MODEL_MATERIAL_SYNC_BUTTON` 的 `MSG_DESCRIPTION_COMMAND`：读取关联材质，调用 `SyncToStandardMaterial` 将当前 MMD 材质属性完整同步到 C4D 材质
- [x] 8.6 在 `GetDEnabling` 中添加逻辑：当未选中材质时，创建材质按钮和同步材质按钮为灰色不可点击；同步按钮在 `material_link` 为空时也为灰色

## 9. Toon 模式控制索引/路径启用状态与自动路径更新

- [x] 9.1 在 `OMMDModelManager.h` 中新增 `MODEL_MATERIAL_TOON_01` ~ `MODEL_MATERIAL_TOON_10` CYCLE 枚举值（值 0-9）
- [x] 9.2 在 `OMMDModelManager.res` 中将 `MODEL_MATERIAL_TOON_TEXTURE_INDEX` 改为 LONG CYCLE 下拉框，选项为 toon01.bmp ~ toon10.bmp
- [x] 9.3 在 `OMMDModelManager.str`（中英文共 4 个文件）中新增 `MODEL_MATERIAL_TOON_01` ~ `MODEL_MATERIAL_TOON_10` 字符串
- [x] 9.4 在 `GetDEnabling` 中：`MODEL_MATERIAL_TOON_TEXTURE_INDEX` 在 `toon_mode == 1`（共用）时启用，`toon_mode == 0`（独立）时禁用；`MODEL_MATERIAL_TOON_TEXTURE_PATH` 在 `toon_mode == 0` 时启用，`toon_mode == 1` 时禁用
- [x] 9.5 在 `SetDParameter` 的 `MODEL_MATERIAL_TOON_TEXTURE_INDEX` case 中，写入 `toon_texture_index` 后当 `toon_mode == 1` 时根据新索引值拼接 `GeGetPluginResourcePath() + "mikumikudance_data/toonXX.bmp"` 更新 `toon_texture_path`
- [x] 9.6 在 `SetDParameter` 的 `MODEL_MATERIAL_TOON_MODE` case 中，当 toon_mode 变更为共用且 `toon_texture_index >= 0` 时，同样重新生成 `toon_texture_path`

## 10. 材质 Mesh 关联与列表管理按钮

- [x] 10.1 在 `MMDMaterialData` 中新增 `mesh_link`（`maxon::StrongRef<AutoAlloc<BaseLink>>`）和 `selection_name`（`String`）字段，并更新 Read/Write/CopyTo 序列化
- [x] 10.2 在 `OMMDModelManager.h` 中新增 `MODEL_MATERIAL_MESH_LINK`、`MODEL_MATERIAL_SELECTION`、`MODEL_MATERIAL_DELETE_BUTTON`、`MODEL_MATERIAL_MOVE_UP_BUTTON`、`MODEL_MATERIAL_MOVE_DOWN_BUTTON`、`MODEL_MATERIAL_ADD_BUTTON` 描述 ID
- [x] 10.3 在 `OMMDModelManager.res` 中将 `MODEL_MATERIAL_LIST` 改为 `GROUP { COLUMNS 2; }` 布局：左侧材质列表 CYCLE，右侧嵌套 `GROUP { COLUMNS 4; }` 放置 ↑↓×+ 四个按钮；在材质名称之后添加 `LINK MODEL_MATERIAL_MESH_LINK` 和 `STRING MODEL_MATERIAL_SELECTION`
- [x] 10.4 在 `OMMDModelManager.str`（中英文共 4 个文件）中新增 mesh link / 选集 / 四个按钮的字符串
- [x] 10.5 在 `GetDParameter` / `SetDParameter` 中添加 `MODEL_MATERIAL_MESH_LINK` 和 `MODEL_MATERIAL_SELECTION` 的读写处理
- [x] 10.6 在 `Message` 中处理 `MODEL_MATERIAL_MOVE_UP_BUTTON` / `MODEL_MATERIAL_MOVE_DOWN_BUTTON`：交换 `material_list_` 中相邻元素并更新选中索引
- [x] 10.7 在 `Message` 中处理 `MODEL_MATERIAL_DELETE_BUTTON`：删除当前材质条目，有 selection_name 时仅删除选集和纹理标签，否则删除整个 mesh 对象
- [x] 10.8 在 `Message` 中处理 `MODEL_MATERIAL_ADD_BUTTON`：添加新的空 `MMDMaterialData` 条目并选中
- [x] 10.9 在 `GetDEnabling` 中添加：↑按钮在 `index <= 0` 时禁用；↓按钮在 `index >= count - 1` 时禁用；×按钮在无选中材质时禁用

## 11. Mesh-材质同步

- [ ] 11.1 在 `MMDModelManagerObject` 中设计 mesh-材质同步的触发时机，在 `Message` 中监听 `MSG_CHANGE` 或 `CheckDirty` 检测子对象结构变化
- [ ] 11.2 实现同步逻辑：遍历 `MMDMeshManagerObject` 下 mesh 子对象的 `TextureTag`，收集所有引用的 `BaseMaterial`，与 `material_list_` 的 `material_link` 对比
- [ ] 11.3 对于新出现的材质（在 mesh 上但不在 `material_list_` 中）：创建新的 `MMDMaterialData` 条目，设置 `material_link`，初始化默认 MMD 属性
- [ ] 11.4 对于消失的材质（在 `material_list_` 中但 mesh 上不再引用）：从 `material_list_` 中移除对应条目
- [ ] 11.5 同步后刷新 `material_list_items_` CYCLE 列表和 `material_selection_index_`
