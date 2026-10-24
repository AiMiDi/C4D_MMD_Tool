> 本目录只保留结论与脚本。原始日志 / JSON / 截图 / TSV 已移出版本库，归档在 `S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\docs-validation\c4d-2027-native-20261019`。

# Cinema 4D 2027 原生兼容验证

后续：[物理回放修复验证](../physics-replay-determinism-20261019/README.md) 记录 2026 / 2027 修复后的严格回放及 IK / PSR 结果。下文为修复前原始验收，失败记录保留。

日期：2026-10-19。用户在初次仅构建验证后授权启动 2027，并提供 `C:\pmx` 和 `C:\vmd` 的真实资源。已完成宿主加载、标准生产接口及真实模型验证；Sour 模型的严格物理回放一致性检查失败，因此不作完整兼容验收。

宿主为 Cinema 4D 2027.0.0（`2027000`），PID `64328`。正常启动后通过用户启用的原生 MCP 执行，使用普通 Release 插件，测试回归桥关闭。加载模块与构建阶段一致：

```text
_build_msvc/sdk_2027_v143/bin/Release/plugins/mmdtool/mmdtool.xdl64
SHA-256: 40506105a9d082675d30f92c4b566472929247d49424829e47bfa192a1fd0d7f
```

| 检查 | 结果与边界 |
| --- | --- |
| 标准生产套件 | 8 个阶段全部通过：setup、discovery、model、motion、camera、invalid、lifecycle、cleanup；包含实际 HTTP 和 stdio 传输 |
| Sour Black + Stay Tonight 动作 | 319 根骨骼、33,608 个顶点；30 fps、0–60 帧；连续播放、跳转重放、初始场景重开、末帧场景重开、关闭物理五条流程均完成 |
| Sour 物理参与 | 开关物理影响 145 根运行时骨骼；最大矩阵分量差 `6.777973195012921`，证明物理实际参与求值 |
| Sour 原生 IK/PSR | 90 项通过；包括原生约束对照、优先级、权重/轴屏蔽、同帧响应、模式切换、关键帧、保存重开和 Undo；分别检查关闭及开启物理 |
| Sour 控制器增量 | 禁用时姿态及几何误差为 0；启用后姿态及几何发生变化；复位误差分别为 `3.55e-15`、`1.24e-14` |
| Sour 严格跳转重放 | **失败**：阈值 `1e-4`；骨骼矩阵最大分量差 `0.045868372625538195`，最终网格点最大坐标差 `0.008281679299009248` |
| 阿芙 2.0 + 同一动作 | 625 根骨骼、70,222 个顶点；0–30 帧动画改变姿态，骨骼和求值网格均为有限值；保存重开后拓扑及有限值检查通过。未验证严格回放相等 |
| Stay Tonight 真实镜头 | 导入 93 个输入镜头帧，求值 0/30/60 帧；导出 103,225 字节 VMD；保存重开后第 60 帧相机矩阵误差为 0 |
| 文档生命周期 | 各测试所有自建文档均已关闭，无剩余测试文档、无清理错误，原先文档已恢复；宿主保留运行 |

后续 [2026.4.0 实机对照](../c4d-2026-2027-compare-20261019/README.md) 已复现完全相同的严格回放误差；五条对应流程的物理骨骼矩阵、每帧网格哈希和末帧全部顶点坐标在两版间一致。该用例未显示 2027 特有回归；严格回放仍为失败，根因尚未定位。原始失败回执及场景继续保留，没有放宽阈值。

视口截图因窗口最小化/激活状态检查未能取得，本次没有材质外观或渲染验收；宿主重启/退出、macOS、远端 CI 和公开发布也未验证。构建使用现有工作区，包括此前已有的无关本地修改，本次未提交或推送。

## 证据与复现入口

- [汇总及文件摘要](receipt.json)、[标准生产回执](production-receipt.json)
- [Sour 完整回执及失败原因](sour-receipt.json)、[90 项原生 IK/PSR 结果](sour-native-psr-results.json)
- [阿芙回执](afu-receipt.json)、[真实镜头回执](camera-receipt.json)、[Sour/动作身份](asset-inventory.json)
- [此前仅构建与私有安装器验证](../c4d-2027-compat-20261019/README.md)

标准套件入口为 `scripts/c4d_production_mcp_validation.py`，执行 `prepare` 后在新的证据目录中运行 `all`。扩展流程使用 `scripts/c4d_extended_validation.py`，通过 `scripts/c4d_native_production_suite.py` 连接普通 Release 接口；原生约束对照使用 `tests/runtime/native_external_psr_test.py`。本次为生成的现代 SDK 工程及 `add_subdirectory` 依赖增加了链接输入身份记录，相关 13 项单元测试通过；没有修改依赖来源与二进制之间的证明标准。

完整模型副本、轨迹、场景、临时驱动和 MCP 日志在 `S:\tmp\cmt-sdk2027-native-20261019\`、`S:\tmp\cmt-sdk2027-20261019\`，可能被清理。本目录只保留结果和摘要，不纳入用户模型、贴图或大型场景。
