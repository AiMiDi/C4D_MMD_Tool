## ADDED Requirements

### Requirement: VMD 动画数据序列化到场景文件

系统 SHALL 在 `MMDModelManagerObject::Write()` 中将 `animations_` 数组中的所有 VMD 动画数据序列化到 HyperFile 中，使其在场景保存时被持久化。

#### Scenario: 保存包含 VMD 动画的场景

- **WHEN** 用户保存一个已加载了 VMD 动画的场景
- **THEN** `Write()` 方法将 `animations_` 数组的大小写入 HyperFile
- **THEN** 对于每个动画条目，写入动画名称（String）和 VMD 二进制数据（通过 `VMDAnimation::Save(VMDFile&)` + `WriteVMDFile()` 转换为字节数组）
- **THEN** HyperFile 的 level 递增以标识新数据格式

#### Scenario: 保存无动画的场景

- **WHEN** 用户保存一个未加载 VMD 动画的场景（`animations_` 为空）
- **THEN** `Write()` 方法写入动画数量为 0
- **THEN** 不写入额外的动画数据

### Requirement: VMD 动画数据从场景文件反序列化

系统 SHALL 在 `MMDModelManagerObject::Read()` 中从 HyperFile 读取 VMD 动画数据，并将其暂存以供运行时重建阶段恢复。

#### Scenario: 加载包含 VMD 动画数据的场景

- **WHEN** 用户打开一个包含已序列化 VMD 动画数据的场景文件
- **THEN** `Read()` 方法从 HyperFile 读取动画数量和每个动画的名称与 VMD 二进制数据
- **THEN** VMD 二进制数据被暂存到临时缓冲区，等待运行时重建阶段恢复

#### Scenario: 向后兼容旧版本场景文件

- **WHEN** 用户打开一个由旧版本插件保存的场景文件（不包含 VMD 动画数据的 level）
- **THEN** `Read()` 方法跳过 VMD 动画数据的读取
- **THEN** `animations_` 保持为空，插件正常运行但无 VMD 动画

### Requirement: VMD 动画在运行时重建阶段恢复

系统 SHALL 在 `PMXModel` 运行时重建完成后，使用暂存的 VMD 二进制数据恢复 `VMDAnimation` 对象。

#### Scenario: 动画恢复成功

- **WHEN** `PMXModel` 重建完成且存在暂存的 VMD 二进制数据
- **THEN** 系统为每个暂存的 VMD 数据调用 `VMDAnimation::Create(mmd_model_)` 和 `VMDAnimation::Add(vmd_file)` 恢复动画
- **THEN** 恢复后的 `animations_` 数组大小和动画名称与保存时一致
- **THEN** `animation_index_` 和 `animation_items_` 被正确恢复
- **THEN** 动画可以正常播放

#### Scenario: 动画恢复时的 animation_index_ 持久化

- **WHEN** 用户在保存场景时选中了某个动画（`animation_index_` >= 0）
- **THEN** 场景重载后 `animation_index_` 恢复到保存时的值
- **THEN** 属性管理器中的动画列表下拉菜单显示正确的选中项

### Requirement: VMD 动画数据的 CopyTo 支持

系统 SHALL 在 `MMDModelManagerObject::CopyTo()` 中正确复制 `animations_` 数组，使撤销/重做和对象复制操作正常工作。

#### Scenario: 对象复制保留动画数据

- **WHEN** 用户复制一个包含 VMD 动画的 `MMDModelManagerObject`
- **THEN** 复制后的对象包含相同的 `animations_` 数据
- **THEN** 复制后的对象可以独立播放动画
