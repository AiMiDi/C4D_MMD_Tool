# RS Toon 材质转换提案

## Why

当前 Standard 和 Redshift Standard 已有主贴图、透明度及材质 Morph 通路，但面向 MMD 风格场景仍需手工搭建明暗分层和描边。新增独立的 `RS Toon（MMD 风格）` 转换类型，让用户直接得到可编辑、可随 Morph 动画变化的风格化材质，并保留现有材质类型的用途。

## What Changes

用户后续范围：普通 Sphere/SPA 的 Matcap 投影与独立 RGBA Morph 同时接入
RS Standard 与默认 Standard 转换。两者在基础颜色的加/乘阶段复用 Sphere
语义，继续由各自表面处理光照与高光；不把 Toon ramp 移植成 PBR 光照。

- 在 PMX 导入的“材质转换类型”与模型材质管理中增加 RS Toon，使用原生 Redshift Toon Material、Tonemap 和 Contour。既有类型的数值与默认选择保持兼容。
- 提供从当前模型材质条目转换到 RS Toon 的操作：以持久化 MMD 基础数据为输入，创建新材质并切换该条目的材质分配，原材质保留；整次操作支持 Undo/Redo，失败恢复原状态。
- 首版支持主贴图、Diffuse/Alpha、共用及独立 Toon 贴图或默认分层 Ramp、风格化高光、逐材质基础描边，以及这些已承载字段的 Material/Group/Flip Morph 联动。
- 复用现有不可变 Morph 求值、原生 User Data、预览及绑定所有权机制，为 Toon profile 增加明确的节点角色、字段支持矩阵和持久化身份。
- 按实际节点与端口能力判断当前 Redshift 是否支持 Toon；UI、生产自动化导入参数 `redshift_toon` 和能力查询采用相同判断，失败不静默转换成其他类型。
- 验收目标是“适合接近 MMD 效果的使用场景”。首版不承诺 MMD 像素等价，不以完整原生语义重建为前置任务；独立 MMD 对照用于记录差异与确定近似规则。
- 后续已接入普通 Sphere Multiply/Add；Sphere SubTexture、逐顶点描边倍率、完整逐材质阴影标志、Ambient 独立模型及任意 MME 效果进入后续范围。Additional UV 按默认不用处理，不作为本轮前置任务；仅当源模型明确使用 SubTexture 或额外 UV Morph 时提示对应边界，普通模型不产生额外 UV 告警。

## Capabilities

### New Capabilities

- `rs-toon-material`: 定义面向 MMD 风格的 RS Toon 图、参数近似、Morph 绑定、宿主能力判断、图像验收和支持边界。

### Modified Capabilities

- `material-system`: 增加独立 RS Toon 适配与识别，定义从 MMD 条目转换材质时的分配、事务和用户编辑保护。
- `import-model-import`: 导入选项增加 RS Toon，并在 UI 与生产自动化接口中提供一致的类型与能力语义。

## Impact

- 类型与创建：`source/cmt_tools_setting.h`、`source/module/tools/material/mmd_material.*`，以及 Redshift 适配器与待新增 Toon profile 实现。
- 场景与运行时：`mmd_model_manager.*`、`mmd_model_morph_runtime.cpp`、`mmd_mesh_manager.cpp`、`mmd_material_morph_binding.*`。新转换必须更新真实 TextureTag 分配，不能只更换模型中的材质链接。
- UI 与资源：导入对话框、`OMMDModelManager` 描述、英文/中文字符串和所有维护中的资源布局。新增标识符不得改变既有序列化数值。
- 生产自动化：现有 PMX 导入类型校验、能力报告、维护中的 MCP 参数定义及回归助手同步增加 `redshift_toon`；不在本轮扩展通用场景材质转换 API。
- 构建：SDK 差异收敛到 `source/module/core/cmt_marco.h`；现有旧 SDK 继续编译，Toon 是否可用另做运行时探测。本轮不引入外部渲染依赖或修改 libMMD 算法。
- 依赖当前工作区的 `shader-driven-material-morph` 绑定实现，其未完成验收不能因本提案自动视为完成。实施前固定依赖代码身份并单独记录 Toon 验收。
- 文档：同步更新材质支持、Morph 使用和导入说明，保留不同模块版本的历史证据边界。
