## Context

当前标准材质的 `CreateStandardMaterialFromPMX` 做了三件事：
1. 有贴图时：将贴图路径设到 Color Channel，检测 png/tga 的 alpha 通道设到 Alpha Channel
2. 无贴图时：用 `Xcolor` 着色器设纯色 diffuse，用 Xcolor brightness 设 alpha
3. 设置材质名称

RS/OC/Corona 需要做完全对等的事情，只是 API 不同。范围不包含 specular/roughness/ambient 等映射。

参考 D5 Render 插件（`D:\code\D5\cinema-4d`）中的 `octane_render.h`、`redshift_render.h`、`corona_renderer.h` 提供了渲染器参数 ID 定义。

## Goals / Non-Goals

**Goals:**
- 为 RS、OC、Corona 实现与标准材质 `CreateFromPMX` 等价的简单创建（diffuse 贴图 + alpha + 纯色）
- 为 RS、OC、Corona 实现与 `SyncToStandardMaterial` 等价的 diffuse 颜色同步
- 使用各渲染器的**默认**材质类型
- 渲染器未安装时弹窗警告用户并取消导入

**Non-Goals:**
- 不做 specular/roughness/ambient/emission 等属性映射
- 不支持 RS 3.0 GvNode API
- 不做各渲染器的特殊材质类型

## Decisions

### 决策 1：Octane 使用 BaseMaterial + BaseLink 设置 diffuse

**选择**: `BaseMaterial::Alloc(ID_OCTANE_DIFFUSE_MATERIAL)` 分配默认 OC 材质。
- 有贴图时：分配 `ID_OCTANE_IMAGE_TEXTURE` 着色器设 `IMAGETEXTURE_FILE` 为贴图路径，通过 `BaseLink` 连接到 `OCT_MATERIAL_DIFFUSE_LINK`；alpha 同理连接到 `OCT_MATERIAL_OPACITY_LINK`
- 无贴图时：分配 `ID_OCTANE_RGBSPECTRUM` 着色器设 `RGBSPECTRUMSHADER_COLOR` 为 diffuse 颜色连接到 diffuse link；分配 `ID_OCTANE_FLOAT_TEXTURE` 设 `FLOATTEXTURE_VALUE` 为 alpha 连接到 opacity link
- 启用 `OCT_MAT_USE_COLOR = true`、`OCT_MAT_USE_OPACITY = true`

### 决策 2：RedShift 使用 NodeMaterial Graph API

**选择**: `BaseMaterial::Alloc(ID_REDSHIFT_MATERIAL)` 分配 RS 材质，转换为 `NodeMaterial*`，通过 `GetGraph(g_redshiftId)` 获取节点图，找到 StandardMaterial 节点设置 base_color / opacity_color 端口。

### 决策 3：Corona 使用 BaseMaterial + BaseLink 设置 diffuse

**选择**: `BaseMaterial::Alloc(ID_CORONA_MATERIAL)` 分配默认 Corona 材质。
- 有贴图时：分配 `ID_CORONA_BITMAP` 着色器设 `CORONA_BITMAP_FILENAME` 为贴图路径，通过 `BaseLink` 连接到 `CORONA_DIFFUSE_TEXTURE`；alpha 通道同理连接到 `CORONA_ALPHA_TEXTURE`
- 无贴图时：设 `CORONA_DIFFUSE_COLOR` 为 diffuse 颜色；alpha 通过 `CORONA_ALPHA_COLOR` 设灰度
- 启用 `CORONA_MATERIAL_DIFFUSE = true`、`CORONA_MATERIAL_ALPHA = true`

**理由**: Corona 的参数结构与 Octane 类似，都是 BaseMaterial + SetParameter/BaseLink 方式，D5 参考代码中已有完整的 ID 定义。

### 决策 4：渲染器参数 ID 局部定义

**选择**: 只在各自 `.cpp` 的匿名命名空间中定义实际用到的少量 ID，不引入完整的渲染器头文件。

### 决策 5：渲染器未安装时弹窗警告并取消导入

**选择**: 在各 `Create*MaterialFromPMX` 函数中，`BaseMaterial::Alloc` 返回 nullptr 时调用 `MessageDialog` 弹窗提示"XXX 渲染器未安装，无法创建材质"，然后返回 nullptr。`LoadPMXMaterial` 返回 nullptr 后，上层导入流程将因材质创建失败而中止。

在字符串资源中新增 `IDS_MES_RENDERER_NOT_INSTALLED` 消息 ID，通过 `GeLoadString` + `FormatString` 附加渲染器名称。

**理由**: 与现有 `MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + ...)` 错误弹窗模式一致。

### 决策 6：同步仅处理 diffuse 颜色

**选择**: `SyncTo*Material` 仅同步 `diffuse_rgb`、`diffuse_alpha` 和 `name_local`。同步逻辑中根据 `BaseMaterial::GetType()` 检测材质类型自动分发。

### 决策 7：material_type 枚举新增 Corona

**选择**: 在 `CMTToolsSetting::ModelImport::material_type` 枚举中新增 `Corona`，在 UI 的 COMBOBOX/CYCLE 选项中新增 Corona(3)，所有相关 `.str` / `.res` / `.h` 同步更新。

### 决策 8：反向同步（从 C4D 材质读取到 MMD 材质数据）

**选择**: 在材质管理器 UI 添加 `MODEL_MATERIAL_REVERSE_SYNC_BUTTON`（"从材质更新"），点击后根据关联材质的 `GetType()` 自动分发到对应的 `ReadFrom*Material` 函数，仅读回 `diffuse_rgb`、`diffuse_alpha` 和 `name_local`。

**理由**: 与正向同步对称，参考 D5 插件读取各渲染器材质的模式。每个 ReadFrom 函数内部通过 `GetType()` 检测材质类型，不匹配时直接 return，因此可以依次调用四个函数而无需外部 switch。

### 决策 9：C4D 2024+ 默认选择 RedShift

**选择**: 在 `cmt_tools_config_manager.h` 的默认配置表中，使用 `kSDK2024 ? 1 : 0` 作为 `DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL_TYPE` 的默认值。`kSDK2024` 为编译期常量（`API_VERSION >= 2024000`），1 对应 `DLG_CMT_MATERIAL_TYPE_REDSHIFT`。

**理由**: C4D 2024 开始内置 RedShift 渲染器，是最常用的默认渲染器选择。

## Risks / Trade-offs

- **[风险] 渲染器未安装** → 弹窗警告 + 返回 nullptr 取消导入
- **[取舍] 不处理纹理到 RS 节点图** → RS 的纹理节点连接较复杂，首次实现 FromPMX 中有贴图时的 RS 纹理连接视复杂度决定是否简化
