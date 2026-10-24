# VMD 播放性能：宿主恢复、基线计时与紧凑关节表 A/B 结论

日期：2026-10-24。本文只保留结论与可复现入口；逐轮日志、原始响应、profile 快照等验证产物已移出版本库，
归档在 `S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\` 下同名目录。

## 1. 宿主恢复结论

- 旧宿主基础设施（`host_call.py`、`profiler-build`、预览场景）在本机上已全部消失，已按 C4D 2027 自带 MCP 重建。
- 启动配方（私有 profile，不动用户默认 profile）：

  ```powershell
  pwsh -NoProfile -File docs\validation\vmd-host-restore-20261024\launch-host.ps1 -Execute
  # 等价核心参数：
  # "C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe"
  #   g_prefsPath="S:\tmp\cmt_vmd_profile_20261019\host_profile"
  #   g_additionalModulePath="C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143\bin\Release\plugins"
  ```

- 就绪 13–19 s；MCP 端点 `http://127.0.0.1:5557/mcp`，token 在
  `S:\tmp\cmt_vmd_profile_20261019\host_profile\prefs\mcp\token`；`initialize` 返回 `serverInfo` cinema4d 1.0.0.26、
  协议 `2025-06-18`，`tools/list` 68 个工具（含 `exec_python`）。
- 客户端要点：`sys.path.insert(0, r"C:\code\C4D_MMD_Tool\mcp")` 后 `from mmdtool_mcp.host import HostConnection`
  （`from mcp.…` 会命中 PyPI 的 `mcp` 包）；响应是 SSE（`event: message` + `data:`），HTTP 需 `ProxyHandler({})` 绕代理。
- 端口 5557 不是出厂默认（适配器默认 5556）：它来自 profile 内的世界插件偏好，改端口须
  `GetWorldPluginData(1070225)` → 改 1004 → `SetWorldPluginData` → `SaveWorldPreferences()` 并重启 C4D。
- 收尾由 `stop-host.ps1` 按身份（pid + UTC ticks + 命令行 hash）校验后关闭，拒绝误杀身份不符的进程；
  用户默认 profile 的 `prefs\` 子树零变化，`teamrender\` / `Redshift\Cache` 的 mtime 变化是 C4D 按固定 APPDATA 路径写盘的固有行为。

## 2. 测试场景与基线

场景：`阿芙2.0.pmx`（6,597,335 B）+ `Stay Tonight Heaven Lee Ver. 动作.vmd`，30 FPS。
构成与旧规格一致：625 骨骼 / 479 刚体 / 748 约束 / 70,222 顶点（网格对象因合并由 35 变为 1）。
`c4d.documents.LoadDocument` 在 C4D 2027 不回放对象树，故计时用「资产 + 固定导入配方」重建而非打开 `.c4d`。

基线 median ms/帧（`baseline-run.ps1`，预热 40 帧后取 560–619 帧）：物理开 65.6 / 68.1 / 64.7，物理关 36.1 / 36.8 / 33.5。

变形锚点（对象 `阿芙2.0.pmx/MMD网格管理器/Mesh`，帧 540/560/619，sha256 前 16 位）：
局部 `07757cb6` / `068d56c8` / `c15545a9`，世界 `5361f419` / `e07de0ca` / `fba9fd24`；三帧互不相同，证明是真变形而非静止网格。

## 3. 紧凑关节表 A/B/A 结论

| 维度 | 结果 |
| --- | --- |
| 变形一致性 | 6 轮 × 3 帧局部与世界坐标 sha256 与基线逐字节相同，逐点偏差 0 |
| 播放耗时 | 物理开 34.031→34.178 ms（+0.43%），物理关 18.168→17.783 ms（−2.12%） |
| 导入耗时 | 3404.5→3386.0 ms（−0.54%） |
| 判定 | 差异小于重测散布（3.5%–7.0%），相邻对符号翻转 → **无可测收益，仅就性能不合并**（中性、无正确性风险） |

性能大头是物理子步：开/关差 15.9 ms（占开态 47%）；物理关 18.17 ms 仍超 60 FPS 预算 16.7 ms 约 9%。
候选补丁与复审记录见 `../vmd-compact-joints-20261024/`。

## 4. 可比性约束（重要）

同一 baseline 工件跨启动复跑的 median 出现 34.0 / 45.1 / 65.6 ms（近 2×），但同一轮内物理开/关比值稳定 ≈1.9。
**绝对毫秒不可跨会话比较，A/B 必须在同一时段交替测量并取多轮 median。**

## 5. 目录内脚本

| 文件 | 用途 |
| --- | --- |
| `launch-host.ps1` | 私有 profile 启动 C4D 2027，写宿主身份（pid/ticks/命令行 hash/模块 sha），等 MCP 就绪 |
| `stop-host.ps1` | 按身份校验后关闭宿主，复核端口释放与残存进程 |
| `configure-mcp-prefs.ps1` / `.py` | 把世界插件偏好里的 MCP 端口写成 5557（需重启 C4D） |
| `host-driver.py` | MCP 生产 API 驱动：capabilities/new-scene/import/import-motion/inspect/save/set-mode/physics/scene-report/export 等子命令 |
| `baseline-run.ps1` | 一条命令跑完导入、缓存、逐帧计时与网格快照；支持 `-PluginsPath` / `-DumpMesh` / `-OutDir` |

未覆盖：未插桩确认候选路径在本场景真被走到；未测内存峰值、实时视口播放、其他模型与动作组合。
