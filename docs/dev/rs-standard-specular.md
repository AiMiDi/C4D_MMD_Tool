# 普通 RS 材质的 Sphere 路径与高光字段

此补齐针对 `MMDRedShiftMaterialAdapter` 的普通 RS Standard 材质创建、显式同步和反向读取。

- `CreateFromPMX` 按 `m_sphereTextureIndex` 读取已解析路径；负索引和越界索引保持空路径。
  不按 Sphere 模式过滤，不通过文件存在性判断丢弃引用。此处只向 `CreateFromData` 传递数据；
  下述高光检查记录的是 Sphere 着色补齐之前的模块。当前普通 RS 已支持
  Matcap Sphere Multiply/Add，最新范围见 [材质支持说明](material-support.md)。
- `CreateFromData` 和普通材质 `SyncTo` 同时设置 `refl_color` 与 `refl_roughness`。
  有主贴图和无主贴图使用同一条高光设置路径。
- `ReadFrom` 在贴图分支提前返回前读取高光字段。颜色或粗糙度输入有连接时，
  保留对应 MMD 基础值，避免把 Shader 端口的默认值当作求值结果。
- Morph 管理的材质继续由绑定系统提供输出，禁止通过反向同步覆盖其基础数据。

普通材质与 Morph 共用 `source/utils/cmt_specular_conversion.hpp`：

```text
roughness = (2 / (max(power, 0) + 2)) ^ 0.25
power = 2 / roughness^4 - 2
```

反向转换仅接受有限的 `[0, 1]` 粗糙度；无效值保持已有 Power。零粗糙度或过小粗糙度
饱和到 PMX Float32 的最大有限值，避免无限大或溢出。正向转换的无效 Power 使用粗糙度 1，
保持此前 Morph 的边界行为。该 GGX 近似不代表与 MMD 高光图像完全一致。

## 验证

`specular_conversion_test` 检查普通值及 Float32 极值往返、`.5 ↔ 30`、`.25 ↔ 510`、
零粗糙度饱和、越界/NaN/Infinity 拒绝并保持输出。现有 `morph_evaluation_test` 验证 Morph
仍使用同一换算。2026-10-07 两项测试通过，SDK 2026、2024、R20 Release 编译通过。

`tests/material/native_rs_specular_test.py` 提供正常 Release、生产入口下的原生用例：
无贴图/带贴图创建、高光同步、反向同步、自定义连接保护和保存重开。示例在 C4D Python 中执行：

```python
import sys
sys.path.insert(0, r"C:\code\C4D_MMD_Tool\scripts")
sys.path.insert(0, r"C:\code\C4D_MMD_Tool\tests\material")
import native_rs_specular_test
result = native_rs_specular_test.run(c4d, r"S:\tmp\cmt-rs-specular-native-fresh")
```

输出目录必须为新目录。测试会关闭自己创建的文档并恢复原活动文档，输出逐项 receipt。
节点/数值结果与实际高光渲染分开记录；不能用编译或纯换算测试替代原生验收。

2026-10-07 原生节点/数据验收通过：C4D 2026.4.0 加载 RS 2026.9.0，
无贴图和带贴图两个用例均通过创建、高光同步、反向同步、外接 Shader 输入保护；
保存重开后高光颜色与 Power 保持正确。测试文档清理完成，原活动文档恢复成功。
此前测试脚本的节点查询 API 错误及主机退出中断记录仍保留，不计为通过证据。
当前汇总记录保存在
`_build_msvc/validation/remaining/rs-standard-specular-20261007/receipt.json`。
原生通过记录为同目录的 `run/native-post-install-2/receipt.json`。
SDK 2026 测试模块 SHA-256 为
`d6ca05c62ccd883754464bc846a47a945b16466031b1d2bd96276b0542e2f84d`，
`CMT_ENABLE_RUNTIME_REGRESSION=OFF`。上述是数据验收；后续实际渲染结果单独登记如下。

## 后续图像验证工具

`tests/material/analyze_rs_highlights.py` 可离线检查高光渲染矩阵，单一设备包含四个
响应用例、一次窄高光重复和一次保存重开结果即可验收材质响应。检查包括图片哈希、
RGBA 覆盖、宽度响应、颜色响应、零高光、重复/重开差异及文档/设备恢复。
`--compare-devices` 可额外要求并比较 CPU/GPU 两组结果，默认不作为材质响应的门槛。
完整调用方式与暂定阈值见 [材质测试说明](../../tests/material/README.md)。

这套检查器已有合成反例测试和真实 PNG 编解码冒烟验证。
`response_checks_passed` 只表示图像通过所列响应阈值；阈值还需原生场景校准，
不能替代 MMD 原生参考、人工外观判断或实际 GPU 执行日志。

## 普通 RS 高光实际渲染验收（2026-10-07）

在独立 c4dpy 宿主中使用同一普通 Release `d6ca05c6…`，C4D 2026.4.0 / RS 2026.9.0，
固定白色无限光、黑色 diffuse、球体和 256×256 RGBA 输出。六张实际渲染图全部成功：

- 白色高光 Power 2 / 510：中心区域半峰面积从 7385 降为 88，符合 Power 增大后高光收窄。
- 红色高光 Power 30：绿色与蓝色通道均为零；零高光：区域 RGB 峰值为零。
- Power 510 重复渲染和保存重开：与初次图片 SHA-256 完全一致，RGB/Alpha 像素差为零。
- 测试文档全部清理，原活动文档和设备设置恢复；宿主退出码为 0。

响应检查及原图、保存场景、模块/PDB归档于
`_build_msvc/validation/remaining/rs-standard-highlight-native-20261007/`，汇总为 `receipt.json`。
本轮采用 CPU；按用户要求，材质验收允许任一设备，CPU/GPU 对照不是必需门槛。
这证明此固定场景的普通 RS 高光响应和持久化，没有 MMD 原生参考，尚不证明 BRDF 外观等效，
也不覆盖带纹理高光或完整 Morph 绑定光照矩阵。
