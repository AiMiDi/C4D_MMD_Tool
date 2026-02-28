## 1. Octane 材质适配

- [x] 1.1 新建 `mmd_octane_material.h`，声明 `CreateOctaneMaterialFromPMX`、`CreateOctaneMaterialFromData`、`SyncToOctaneMaterial`
- [x] 1.2 新建 `mmd_octane_material.cpp`，在匿名命名空间定义必要的 OC 常量（`ID_OCTANE_DIFFUSE_MATERIAL`、`ID_OCTANE_IMAGE_TEXTURE`、`ID_OCTANE_RGBSPECTRUM`、`ID_OCTANE_FLOAT_TEXTURE`、`OCT_MAT_USE_COLOR`、`OCT_MAT_USE_OPACITY`、`OCT_MATERIAL_DIFFUSE_LINK`、`OCT_MATERIAL_OPACITY_LINK`、`RGBSPECTRUMSHADER_COLOR`、`FLOATTEXTURE_VALUE`、`IMAGETEXTURE_FILE`），实现三个函数——有贴图时用 ImageTexture 着色器设路径并 BaseLink 连接到 diffuse/opacity link，无贴图时用 RGBSpectrum 设纯色 + FloatTexture 设 alpha；渲染器未安装时 `BaseMaterial::Alloc` 返回 nullptr 弹窗警告
- [x] 1.3 在 `mmd_material.cpp` 的 `LoadPMXMaterial` 中填充 `Octane` case，调用 `CreateOctaneMaterialFromPMX`

## 2. RedShift 材质适配

- [x] 2.1 新建 `mmd_redshift_material.h`，声明 `CreateRedShiftMaterialFromPMX`、`CreateRedShiftMaterialFromData`、`SyncToRedShiftMaterial`
- [x] 2.2 新建 `mmd_redshift_material.cpp`，在匿名命名空间定义必要的 RS 常量（`ID_REDSHIFT_MATERIAL`、`g_redshiftId`、StandardMaterial 节点的 base_color / opacity_color InternedId），实现三个函数——通过 NodeMaterial Graph API 设置端口默认值（纯色模式）和贴图路径（有贴图时创建 TextureSampler 节点连接）；渲染器未安装时弹窗警告
- [x] 2.3 在 `mmd_material.cpp` 的 `LoadPMXMaterial` 中填充 `RedShift` case，调用 `CreateRedShiftMaterialFromPMX`

## 3. Corona 材质适配

- [x] 3.1 新建 `mmd_corona_material.h`，声明 `CreateCoronaMaterialFromPMX`、`CreateCoronaMaterialFromData`、`SyncToCoronaMaterial`
- [x] 3.2 新建 `mmd_corona_material.cpp`，在匿名命名空间定义必要的 Corona 常量（`ID_CORONA_MATERIAL`、`ID_CORONA_BITMAP`、`CORONA_BITMAP_FILENAME`、`CORONA_DIFFUSE_COLOR`、`CORONA_DIFFUSE_TEXTURE`、`CORONA_MATERIAL_DIFFUSE`、`CORONA_MATERIAL_ALPHA`、`CORONA_ALPHA_COLOR`、`CORONA_ALPHA_COLOR_LEVEL`、`CORONA_ALPHA_TEXTURE`），实现三个函数——有贴图时用 CoronaBitmap 着色器设路径并 BaseLink 连接到 diffuse/alpha texture，无贴图时设纯色 + alpha；渲染器未安装时弹窗警告
- [x] 3.3 在 `mmd_material.cpp` 的 `LoadPMXMaterial` 中填充 `Corona` case，调用 `CreateCoronaMaterialFromPMX`

## 4. 创建/同步按钮集成

- [x] 4.1 在 `mmd_model_manager.cpp` 的 `MODEL_MATERIAL_CREATE_BUTTON` 处理中添加 RS/OC/Corona 的 case 分支，调用对应 `Create*MaterialFromData`
- [x] 4.2 在 `mmd_model_manager.cpp` 的同步逻辑中（`MODEL_MATERIAL_SYNC_BUTTON` 和 `SetDParameter`），根据 `BaseMaterial::GetType()` 分发到对应的 `SyncTo*Material`

## 5. UI 资源更新

- [x] 5.1 `c4d_symbols.h` 新增 `IDS_CMT_MATERIAL_TYPE_CORONA`、`DLG_CMT_MATERIAL_TYPE_CORONA`、`IDS_MES_RENDERER_NOT_INSTALLED`
- [x] 5.2 `OMMDModelManager.h` 新增 `MODEL_MATERIAL_CREATE_TYPE_CORONA`（S24_up + R20-S24）
- [x] 5.3 `OMMDModelManager.res` CYCLE 新增 Corona（S24_up + R20-S24）
- [x] 5.4 `DLG_CMT_TOOL.res` COMBOBOX 新增 Corona（S24_up + R20-S24）
- [x] 5.5 所有 `.str` 文件新增 Corona 字符串 + 渲染器未安装消息
- [x] 5.6 `cmt_tools_setting.h` 枚举新增 `Corona`

## 6. 构建配置

- [x] 6.1 在 `CMakeLists.txt` 中添加新源文件
