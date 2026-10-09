# Proposal

## Why

阿芙模型的 `+左ひじ補助` 与主要肘部控制器几乎重合且尺寸相同，默认显示时抢占选择区域。轮廓方向标记还因全局闭合设置而出现多余斜边。

## What Changes

- 按用途区分主要关节、扭转、辅助控制器，主要视图收起辅助、扭转和眼镜附件，全部视图保留访问。
- 为肩、手臂、肘、腕、辅助和扭转使用有层次的尺寸；保留既有控制器的绑定轴和动画，并覆盖标准中央骨骼。
- 主轮廓和方向三角形用重复端点闭合，三角形位于圆环边缘外并垂直于圆环平面，统一原生样条与穿透绘制结果，脚和 IK 框去掉附加标记，手部改为浅立体框。
- 在真实模型副本上验证显示、选择、保存重开、关键帧与姿势，并更新交付记录。

## Capabilities

### New Capabilities

无。

### Modified Capabilities

- `motion-vmd-motion`: 控制器显示分层、用途尺寸和样条闭合行为。

## Impact

涉及控制器命名识别、几何生成与默认显示，增加独立逻辑和原生 C4D 回归。无需变更场景数据格式，不删除已有控制器，不更改 IK/PSR 求值。

Archive summary: Refine controller silhouettes and purpose hierarchy, and add central-body controls while preserving existing animation inputs.
