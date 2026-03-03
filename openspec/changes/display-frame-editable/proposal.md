## Why

当前 PMX 导入后，表示框（Display Frame）数据仅以静态文本形式展示在 `MMDModelManagerObject` 的属性管理器中，用户无法编辑表示框的结构（增删/排序条目、重命名帧）。表示框数据也未持久化存储，不支持序列化（Read/Write），PMX 导出时也未将表示框写回。需要将表示框从"只读展示"升级为"完整可编辑"的管理功能，支持增删条目、排序、重命名帧、持久化、以及 PMX 导出。

## What Changes

- 将表示框数据从 DynamicDescription 静态文本改为**结构化数据模型**（`DisplayFrameData` 结构体），在 `MMDModelManagerObject` 中以 `maxon::BaseArray<DisplayFrameData>` 持久化存储
- 表示框 UI 改为**可编辑的动态描述**：
  - 每个帧组（如 ROOT、表情）支持重命名
  - 每个条目支持删除
  - 帧组内支持添加新的骨骼或形变条目（通过下拉选择或输入索引）
  - 帧组支持排序（上移/下移）
  - 支持新增/删除帧组
- 实现 `DisplayFrameData` 的 Read/Write/CopyTo 序列化方法
- 在 `SavePMX` 中实现表示框数据导出到 `PMXFile::m_displayFrames`
- PMX 导入时从现有 `ImportDisplayFrames` 填充结构化数据

## Capabilities

### New Capabilities

- `display-frame-manager`: 表示框的完整管理功能，包括数据模型、可编辑 UI、增删条目、帧组管理、排序、序列化、PMX 导入/导出

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **修改文件**: `MMDModelManagerObject`（新增表示框数据成员和管理方法）、`ImportDisplayFrames`（重构为填充结构化数据）、`SavePMX`（新增表示框导出）
- **新增资源文件**: `OMMDModelManager.res/.h/.str` 需要新增表示框编辑相关的按钮和控件描述 ID
- **依赖**: 使用现有 libMMD 的 `PMXDisplayFrame` 结构体，无新增外部依赖
- **兼容性**: 需要处理旧版本项目文件的向后兼容（Read 中检测表示框数据是否存在）
