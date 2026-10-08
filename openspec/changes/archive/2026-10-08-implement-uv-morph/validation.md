# UV Morph 原生验收记录

日期：2026-10-08。提案 `implement-uv-morph` 从 15/18 完成至 18/18。

## 宿主与产物

- 使用用户指定的当前 Cinema 4D MCP，在独立测试工程中执行；宿主版本 `2026400`（2026.4.0），PID `20696`。
- 实际加载模块：`S:\tmp\cmt-morph-completion-20261008\plugins\mmdtool\mmdtool.xdl64`。
- 模块 SHA-256：`e5c0501cebb1af35ecb2320fede99eebb80261152461694bb58add078eeb2b34`。验证入口拒绝不匹配的模块。
- 本轮补完原生验证，没有修改插件 C++，也没有重新声明或重跑此前已完成的 5.1 编译任务。

## 覆盖范围与结果

`tests/uv_morph_native_test.py` 生成一个合法 PMX 2.0 模型，包含两个材质分区、八个顶点、一个骨骼、Vertex 与 UV/AddUV1/AddUV2/AddUV3/AddUV4 共六个 Morph，以及四个 Additional UV 通道。用生产导入协议分别执行 `multipart=false/true`，确认确实生成一/两个 polygon 对象。材质导入关闭，将验收集中于 Morph 分类。

| 任务 | 原生证据 | 结果 |
|---|---|---|
| 5.2 UV 属性分组 | 五个 UV 名称的原生类型均为 16，真实属性描述中的滑块父组均为 `MODEL_MORPH_UV_GRP=1016` | 两条导入路径通过 |
| 5.3 位置 Morph 分组 | Vertex 原生类型为 4，滑块父组为 `MODEL_MORPH_MESH_GRP=1015`；每个 Morph 恰有一个滑块 | 两条导入路径通过 |
| 5.4 保存重载 | 六个权重设为 0.1/0.2/0.3/0.4/0.5/0.6，保存 `.c4d`、释放旧工程并加载磁盘工程；再次单独执行只读盘重载阶段，不重新导入 PMX | 类型、完整 DescID、父组、权重和网格数量一致 |

所有四个验收 case（两次导入和两次磁盘重载）的清理记录均为 `errors=[]`、`remaining_owned_documents=[]`、`original_document_restored=true`。当前用户工程和宿主保留。

## 复现与证据

完整接受收据随提案保存在 `validation-native.json`。生成的 PMX、`.c4d` 和原生阶段收据保存于 `_build_msvc/validation/uv-morph/20261008-e5c0501c/`；临时调用脚本和 MCP 返回保存于 `S:\tmp\cmt-uv-morph-20261008-103036/`。

在 Cinema 4D MCP 的 `exec_python` 中运行，传入已核验的当前加载模块 hash：

```python
import c4d, sys
sys.path.insert(0, r"C:\code\C4D_MMD_Tool\tests")
import uv_morph_native_test
receipt = uv_morph_native_test.run(c4d, r"S:\tmp\cmt-uv-morph-repeat", expected_module_sha256, phase="import")
assert receipt["status"] == "passed", receipt
# 后续调用可以执行 phase="reload"，复用同一输出目录，只读取已保存场景。
```

这次验收使用真实 Cinema 4D 的生产导入、类型检查、属性描述、场景序列化和加载，没有依赖 fixture 模拟宿主。输入模型是人工构造的确定性 fixture。它证明分类、属性 UI 描述和保存重载保持；不证明实际 GUI 截图布局、完整真实模型视觉效果、Additional UV 通道映射、UV 导出保真、旧版本宿主或旧格式场景兼容性。保存重载在同一宿主的不同工程间完成，没有声称宿主重启验证。

先前独立 c4dpy 尝试的失败输出留在临时目录 `evidence/`，不作为本次接受收据。最终验收只使用 `evidence-mcp/` 和上述归档。

## 规格整理

严格校验发现这份历史提案的 delta 缺少 Scenario，且指向不存在的 `morph-system` 能力。已补齐原有需求的 Scenario，改为当前 `object-morph-system` 能力；该主规格中的类型、层次和 UI/存储说明原先是普通说明段落，所以本提案将它们作为新增规范需求，不用 MODIFIED 匹配不存在的 Requirement 标题。已有 Material/Impulse 支持保持在契约内。2026-10-08 归档时同步这些契约至主规格。
