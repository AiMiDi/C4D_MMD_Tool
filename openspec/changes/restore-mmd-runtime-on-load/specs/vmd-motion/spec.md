## MODIFIED Requirements

### Requirement: VMD 动画存储与回放

`MMDModelManagerObject` 存储 `animations_` 数组中的 VMD 动画，并在 `Execute()` 中驱动回放。动画数据 SHALL 在场景保存/重载周期中持久化，重载后可恢复到与保存时相同的状态。

#### Scenario: VMD 动画的保存-重载-回放循环

- **WHEN** 用户导入 VMD 动画并保存场景
- **WHEN** 用户重新打开该场景
- **THEN** `animations_` 数组被恢复，包含与保存时相同数量和名称的动画条目
- **THEN** `animation_index_` 和 `animation_items_` 被正确恢复
- **THEN** 用户切换到 VMD 模式后，动画可以正常播放
- **THEN** 播放结果与保存前一致

#### Scenario: 场景重载后切换动画

- **WHEN** 场景重载后存在多个 VMD 动画
- **THEN** 用户可以通过属性管理器的动画列表下拉菜单切换不同的动画
- **THEN** 切换后动画正常播放

## ADDED Requirements

### Requirement: VMD 二进制数据暂存

系统 SHALL 在 `Read()` 过程中将 VMD 二进制数据暂存到临时缓冲区（如 `pending_vmd_data_`），直到运行时重建阶段使用 `VMDAnimation::Create()` + `VMDAnimation::Add()` 恢复后释放。

#### Scenario: 暂存数据在重建后被释放

- **WHEN** 运行时重建完成且 VMD 动画恢复成功
- **THEN** 系统释放暂存的 VMD 二进制数据缓冲区以回收内存

#### Scenario: 暂存数据在重建失败时被释放

- **WHEN** 运行时重建失败
- **THEN** 系统仍释放暂存的 VMD 二进制数据缓冲区
- **THEN** `animations_` 保持为空
