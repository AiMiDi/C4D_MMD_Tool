# 未指定 Toon 的眼部修复验证

2026-10-07。此记录只覆盖眼部 fallback 修复的 revision 4 候选，不覆盖共享工作树后续 revision 5 Sphere 实施。

## 当前界面与测试候选

只读检查当前 GUI 文档 `阿芙-材质页检查.c4d`：35 个 Toon 材质全部为 revision 3，均无 Sphere 角色。加载插件 SHA256 为 `6964159ad4c06b62553184b937687765472caf3f73dadb79dcb7ea629a86b29f`。收据：`S:\tmp\cmt-rs-toon-eye-fix-20261007\current-gui-material-version.json`。没有修改该文档或关闭用户的 Cinema 4D。

独立 c4dpy 候选插件 SHA256 为 `8c70d1d535786989d8474c01c0ba97e2096f70780e5eb41d37944a824b61b77a`。SDK 2026 Release 编译通过；19 个独立逻辑测试通过。源码后续出现 revision 5 后，将对应 revision 4 的结构断言冻结到任务目录，避免把后续测试配方错误用于旧候选。

## 行为与实际渲染

- 独立 Toon 模式、索引负值且无路径时使用全白 fallback，并绕过 Toon 纹理 Morph 运算。
- 已指定但缺失的 Toon 保留原默认阴影 fallback；不把缺失资源当成未使用资源。
- 原始 `阿芙2.0.pmx` 通过生产导入创建 35 个 revision 4 材质；结构读回验证所有眼部条目的 neutral 标志及表面连接。
- 单白色方向光，方向 `(-0.5, -1, 0.5)`，无补光、关闭 GI，480 × 720。此设置是固定测试条件，不声称等于用户实际 MMD 灯光参数。
- 原生渲染 face、face-reopen、front、legs 全部成功，虹膜颜色与贴图亮点恢复。保存重开后眼部 ROI `(130, 235, 385, 315)` 的 RGBA 像素完全一致。
- 整张 face 与 face-reopen 的 345600 个像素中有 1 个像素红通道相差 1/255，位于 `(94, 640)`，眼部之外。文件哈希不一致，不声明整张图逐像素复现。
- 测试文档清理成功、原文档恢复、RS 偏好恢复。

最终收据与图片：`S:\tmp\cmt-rs-toon-eye-fix-20261007\native-3\`，包含 `receipt.json`、`pixel-comparison.json` 和 `afu-toon-eye-fixed.c4d`。`native-1` 因测试读取后续配方的 16 属性失败；`native-2` 因严格文件哈希断言失败；保留两份失败记录，不混入最终运行结论。

## 剩余范围

此候选没有 Sphere Add 着色分支。实际模型全部 35 个材质 Specular RGB 为零，23 个材质指定 Sphere Add；缺少的材质亮带不能由提高 Specular Power 恢复。Sphere 分支、实际高光对照、旧材质显式升级和后续候选保存重开的验收另行记录。完整 MMD 外观等价性尚未通过同条件 MMD 原生参考验证。
