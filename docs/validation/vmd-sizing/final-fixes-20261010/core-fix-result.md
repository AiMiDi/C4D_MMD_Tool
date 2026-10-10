# PMX 权重与 ToeZ 修复结果

已修改共享 libMMD 工作区，未提交/推送，未重建 SDK，未操作 C4D。

## 改动文件

- `src/libMMD/Model/MMD/PMXFile.h`：PMXVertex 所有向量、数组、权重、索引和标量默认初始化；新增 inline `GetPMXVertexInfluenceCount(PMXVertexWeight)` 和 `GetPMXVertexInfluenceWeight(const PMXVertex&, int)`，按 PMX 的隐式权重语义读取有效影响。
- `src/libMMD/Model/MMD/PMXFile.cpp`：QDEF 读/写原本索引 0、1、3、4（漏掉 2，访问 4 越界），均改为循环 0..3。
- `src/MotionSizing/Analysis/MMDMotionAnalysis.cpp`：ToeZ 按有效权重筛选顶点，不再读取 BDEF2/SDEF 未存储的第二权重槽。
- `tests/PMXVertexWeights.test.cpp`（新增）：默认构造初始化、无效/NaN 未使用槽、隐式第二权重、QDEF 磁盘字节顺序、全部权重读回和相邻存储不被覆盖。
- `tests/MMDMotionSizing.test.cpp`：第二骨为足骨的 BDEF2/SDEF 顶点得到与单影响足顶点一致的 ToeZ/中心偏移。
- `tests/CMakeLists.txt`：注册 `pmx_vertex_weights_test`。

helper 不会归一化或 clamp 权重，保留原始值供上层验证；未知类型影响数为 0，越界影响索引的权重返回 0。

## 验证

Release 核心构建通过。以下 5 个 CTest 通过：

- `pmx_vertex_weights_test`
- `mmd_motion_sizing_test`
- `mmd_motion_sizing_advanced_test`
- `file_roundtrip_test`
- `pmx_export_invariants_test`

`git diff --check` 通过。构建/测试日志在本目录 `core-build.log`、`core-tests.log`、`io-build.log`、`io-tests.log`。

将两个新增回归分别链接本轮修复前冻结的 libMMD 静态库进行反证，均按预期退出 1：

```text
Toe reference ignored the second bone's implicit weight
QDEF disk weight index is wrong
```

证据：`red-sizing.log`、`red-weights.log`、`red-build.log`。这证明回归能捕获原来的错误，而非只验证 helper 自身。

这些测试不代表 C4D Apply 误拒绝的原生验收；CMT 的签名、去重键和 Snapshot 修复由主代理处理。
