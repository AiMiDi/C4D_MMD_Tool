## 1. 数据模型定义

- [x] 1.1 在 `mmd_model_manager.h` 中定义 `DisplayFrameTargetData` 结构体（类型枚举 Bone/Morph + 目标索引 Int32）和 `DisplayFrameData` 结构体（name, name_universal, frame_type, `maxon::BaseArray<DisplayFrameTargetData>` targets）
- [x] 1.2 实现 `DisplayFrameData` 的 `FromPMX(const libmmd::PMXDisplayFrame&)` 方法
- [x] 1.3 实现 `DisplayFrameData` 的 `ToPMX(libmmd::PMXDisplayFrame&)` 方法
- [x] 1.4 实现 `DisplayFrameData` 的 Read/Write 序列化方法（从/到 HyperFile）
- [x] 1.5 实现 `DisplayFrameData` 的 CopyTo 深拷贝方法
- [x] 1.6 在 `MMDModelManagerObject` 中新增 `maxon::BaseArray<DisplayFrameData> display_frame_list_`、`Int32 display_frame_selection_index_`、`BaseContainer display_frame_items_` 成员变量

## 2. 资源文件

- [x] 2.1 在 `OMMDModelManager.h` 中新增表示框编辑相关描述 ID：`MODEL_DISPLAY_FRAME_LIST`（帧组下拉列表）、`MODEL_DISPLAY_FRAME_NAME_LOCAL`（本地名称）、`MODEL_DISPLAY_FRAME_NAME_UNIVERSAL`（通用名称）、`MODEL_DISPLAY_FRAME_ADD_TYPE`（添加条目类型）、`MODEL_DISPLAY_FRAME_ADD_TARGET`（添加条目目标）、`MODEL_DISPLAY_FRAME_ADD_BUTTON`（添加条目按钮）、`MODEL_DISPLAY_FRAME_DELETE_BUTTON`（删除帧组按钮）、`MODEL_DISPLAY_FRAME_NEW_NAME`（新帧组名称输入）、`MODEL_DISPLAY_FRAME_NEW_BUTTON`（新增帧组按钮）、`MODEL_DISPLAY_FRAME_NONE`（空占位）、各 CYCLE 枚举值
- [x] 2.2 在 `OMMDModelManager.res` 中更新 `MODEL_DISPLAY_FRAME_GRP` 分组，添加帧组下拉列表、名称编辑、添加条目控件、帧组管理按钮等 UI 定义
- [x] 2.3 在 `strings_zh-CN/description/OMMDModelManager.str` 中新增所有表示框编辑相关中文字符串
- [x] 2.4 在 `strings_en-US/description/OMMDModelManager.str` 中新增所有表示框编辑相关英文字符串
- [x] 2.5 同步更新 `res/R20-S24/` 下对应的 `.h`、`.res`、`.str` 文件

## 3. 导入集成

- [x] 3.1 重构 `ImportDisplayFrames`：移除现有 DynamicDescription 静态文本创建逻辑，改为将 PMX 表示框数据通过 `FromPMX` 填充到 `display_frame_list_`
- [x] 3.2 新增 `RebuildDisplayFrameUI` 方法：根据当前选中帧组，使用 DynamicDescription 动态创建条目列表 UI（每行包含类型标签、目标名称、删除/上移/下移按钮）

## 4. GetDDescription / GetDParameter / SetDParameter

- [x] 4.1 在 `GetDDescription` 中动态填充 `MODEL_DISPLAY_FRAME_LIST` 的 CYCLE 选项（帧组名称列表）和 `MODEL_DISPLAY_FRAME_ADD_TARGET` 的 CYCLE 选项（骨骼/形变名称列表）
- [x] 4.2 在 `GetDParameter` 中处理帧组名称（`MODEL_DISPLAY_FRAME_NAME_LOCAL`/`_UNIVERSAL`）的动态值读取
- [x] 4.3 在 `SetDParameter` 中处理 `MODEL_DISPLAY_FRAME_LIST`（切换帧组时重建条目 UI）、帧组名称编辑（更新数据和 CYCLE 显示）

## 5. 条目编辑功能

- [x] 5.1 在 `Message` 的 `MSG_DESCRIPTION_COMMAND` 中处理添加条目按钮：读取类型和目标选择，追加到当前帧组，调用 `RebuildDisplayFrameUI` 刷新
- [x] 5.2 在 `Message` 中处理条目删除按钮：从帧组中移除对应条目，重建 UI
- [x] 5.3 在 `Message` 中处理条目上移/下移按钮：交换条目位置，重建 UI
- [x] 5.4 在 `Message` 中处理新增帧组按钮：创建空帧组追加到列表，更新 CYCLE，切换到新帧组
- [x] 5.5 在 `Message` 中处理删除帧组按钮：移除当前帧组，更新 CYCLE 和选中索引

## 6. 序列化

- [x] 6.1 在 `MMDModelManagerObject::Read` 中添加表示框数据的反序列化（检测 level，缺失时跳过以兼容旧版）
- [x] 6.2 在 `MMDModelManagerObject::Write` 中添加表示框数据的序列化
- [x] 6.3 在 `MMDModelManagerObject::CopyTo` 中添加表示框列表的深拷贝

## 7. PMX 导出

- [x] 7.1 在 `SavePMX` 中遍历 `display_frame_list_`，调用 `ToPMX` 将数据写入 `PMXFile::m_displayFrames`

## 8. GetDEnabling

- [x] 8.1 在 `GetDEnabling` 中添加逻辑：当 `display_frame_list_` 为空时，所有表示框编辑控件为禁用状态；当未选中帧组时，条目编辑控件为禁用
