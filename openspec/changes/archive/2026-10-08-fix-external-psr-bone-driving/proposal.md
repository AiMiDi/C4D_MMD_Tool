# Proposal

## Why

真实阿芙 PMX/VMD 场景中，C4D 空对象通过原生 PSR 约束驱动骨骼时，约束先执行会被 MMD 动画覆盖，后执行则只移动 IK 目标而不驱动腿部。需要让原生约束结果进入 MMD 求值，避免要求用户另建控制器体系。

## What Changes

- 对存在有效原生 PSR 位置或旋转约束的 ANIM 模型，分阶段准备动画、接收约束结果和执行 MMD IK/物理。
- 外部驱动通道覆盖对应的 MMD 动画结果，其他通道继续使用 VMD、表情和继承；保留冻结绑定数据。
- 禁用或删除约束后恢复普通 MMD 求值；无外部约束模型保留原有路径。
- 增加真实 C4D 回归，覆盖同帧、关键帧、优先级、物理、保存重开和克隆。

## Capabilities

### New Capabilities

无。

### Modified Capabilities

- `motion-model-runtime-reconstruction`: 增加外部 PSR 姿态的运行时接入及非持久缓存边界。

## Impact

影响 ModelManager、BoneManager、MMDBoneTag 的执行协调和运行时测试，不改变 PMX/VMD 格式、蒙皮权重、约束标签配置或依赖库。
