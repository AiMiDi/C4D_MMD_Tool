# C1/C3 热点候选：真实宿主 A/B 实测（t19）

> 状态：**测量完成**。主证据：`S:\tmp\cmt_vmd_profile_20261019\hotpath\ab\t19g\ab-summary.json`
> （`AB_OK`，exit 0）；网格证据：`S:\tmp\cmt_vmd_profile_20261019\hotpath\mesh-rerun\mesh-summary.json`。
> 结论摘要：效果**逐字节一致**；收益 **on −1.05 ~ −1.25 ms/帧（−2.95% ~ −3.51%）**、
> off **−0.69 ~ −0.93 ms/帧（−3.69% ~ −4.89%）**，**低于 t14 合计预期（1.5–6.0 ms）的下界**。

## 1. 目的

回答一个问题：`candidate-hotpath-v1`（C1「控制状态扫描合并」+ C3「键帧查找二分」）在**真实宿主**里
到底省了多少 ms/帧，是否达到 t14 的预期（C1 1.0–3.5 ms/帧、C3 0.5–2.5 ms/帧），以及**效果是否逐字节一致**。

- 候选来源：`.dsh-switchman/vmd-perf-20261024/candidate-hotpath-v1/candidate-hotpath-v1.patch`
  （sha256 `CCF7EB014CB67E61B0F8371A240CCDB985DF745141F89EB3D247506FAC78FE74`，15,860 B，6 文件 +139/−46）
- 补丁的离线等价性证据（不重复，只引用）：
  `HOTPATH_VERIFY assertions=74 cases=9 failures=0`；
  `KEYFRAME_SEARCH_TEST` 137,815 断言 / 18 案例；`CONTROL_SCAN_TEST` 28,162 断言 / 8 案例。

## 2. 两版工件

| 变体 | 插件目录 | `mmdtool.xdl64` 大小 | sha256 |
|---|---|---|---|
| baseline | `S:\tmp\cmt_vmd_profile_20261019\ab\baseline\plugins` | 3,777,024 B | `1C949823F2CC992EE7026A131253EB76E0054B954F7B7075BB8340948BEF8CE7` |
| candidate | `S:\tmp\cmt_vmd_profile_20261019\hotpath\candidate\plugins` | 3,776,000 B | `C4D494EE62ED6F547DF282A9F8E5D904D98FDC4DDDE3C6EDA40B0ADA3904E216` |

两版均无 `CMT_RUNTIME_PROFILING=1` 标记（出包口径），宿主侧 `host-identity.json` 的
`modules.mmdtool_loaded.sha256` 与本地工件逐一核对相等（每轮记录 `module_match=True`）。

## 3. 构建（隔离目录，产品树零残留）

命令（`build-candidate.ps1 -Execute`）：

```powershell
git apply .dsh-switchman/vmd-perf-20261024/candidate-hotpath-v1/candidate-hotpath-v1.patch
cmake -S sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\hotpath-build `
      -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF
cmake --build S:\tmp\cmt_vmd_profile_20261019\hotpath-build --config Release --target mmdtool
# finally: 还原产品树（按开工前 sha256 校验 + git cat-file blob 回写 + 清理补丁新增文件）
```

- 构建耗时：configure 5.6 s + build 174.2 s（Release，x64，v143）
- 构建后 6 条还原断言全 PASS：`git status --short -- source` 为空、5 个被改文件字节 sha256 与开工前一致、
  补丁新增的 `source/module/tools/tag/mmd_keyframe_search.h` 已清除。
- 产品树 5 文件基线 sha256（核对用）：`mmd_model_manager.cpp` `B79B9AE2…43DA`、
  `mmd_bone_manager.h` `39BF14AB…F661`、`mmd_bone.cpp` `2F6C0BBB…CB77`、
  `mmd_bone_control_util.cpp` `D3F50818…D73C`、`mmd_bone_control_util.hpp` `F3B75D9F…2F8B`。

> 注意：同一份源码两次构建的 `mmdtool.xdl64` sha256 不同（PE 时间戳），本轮以最后一次
> `C4D494EE…` 为准，并通过宿主侧模块 sha 核对绑定。

## 4. 测量协议

`run-ab.ps1`（参数 `-Pairs 5 -Rounds 5 -Frames 30 -Warmup 15 -MaxLoadPct 30 -QuietMaxLoadPct 20`）：

1. **交替**：每对依次跑 baseline、candidate（p1..p5，每轮都重新启动宿主，不跨轮复用）。
2. **安静门**：每次启动前等 CPU 总占用连续 3 次采样 <20%（最长等 900 s），等不到也照跑并记录 `quiet_ok=false`。
3. **负载门**：单次启动后采样 `system-running` 的 CPU 总占用，>30% 即丢弃该次启动并重试（`launch_discards` 记账，**不算失败**）。
4. **清理**：`Clear-OurHost` 用 CIM 枚举 + `taskkill /F /T`，只杀命令行含本任务私有 profile 的宿主实例。
5. **测量内核**：`stable-measure.ps1 -Variant <v> -PluginsPath <dir> -PhysicsBoth -Rounds 5 -Launches 1`；
   预热 15 帧（540–555）、计时 30 帧（560–589），物理开/关各 5 次交替，逐帧墙钟
   `doc.SetTime(...) + doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)`。
6. **每轮记录**：`artifact_sha`、`hosted_module_sha`、`module_match`、`pid`、`start_ticks_utc`、
   物理开/关各自 5 次 rep 的 median、`load_pct`、`stop_method`、`remaining_cinema4d`。

判定口径：以「每变体 5 轮 median 的中位数」为主指标，同时给出每对的相对变化 `delta_pct` 与
每变体 5 轮 median 的 CV；对 `load_pct` 明显不对称的配对单独标注（不混入主结论）。

## 5. 宿主稳定性事故（必须与结果一起读）

本机在 12:52–13:45 之间出现多次宿主崩溃，**与候选无关**（baseline 同样崩），证据如下：

| 时间 | 现象 | 证据 |
|---|---|---|
| 12:52:52 | `Cinema 4D.exe` 崩溃，出错模块 `python311.dll`，异常码 `0xc0000409` | Windows 事件日志 Application Error（Provider `Application Error`，Id 1000） |
| 13:08:46 | `exec_python`（仅 `GetActiveDocument` + `SetFps/SetMin-MaxTime`）后 2 s 触发 `REENTRANT_DRAIN ... nested CoreMessage` | `host_profile\prefs\mcp\audit.log` |
| 13:08 / 13:15 / 13:42 | `_bugreports\_BugReport.txt`（1.20–1.21 MB）+ `minidump.dmp`（3.70 MB）；463 个线程段的调用栈**全部在 `python311.dll`**，`mmdtool` 仅出现在 `Loaded_Modules` | `host_profile\_bugreports\`（已归档） |
| 13:17–13:28 | 连续 `host_exited_before_ready: exit_code=-1` | `launch-*.log` |

其中 13:17–13:28 的连败**根因已定位并修复**：被强杀的宿主留下子进程继续持有 Cinema 4D 2027 的
「同一安装单实例」锁，且 `Get-Process 'Cinema 4D'` 看不到这些实例，于是后续每次 `Start-Process`
都只打印 `Detected another instance of the same installation running. Forwarding command line parameters...`
并以 `exit_code=-1` 退出。改用 CIM 枚举 + `taskkill /F /T` 后恢复正常（见 §4.4）。

崩溃报告已归档为 `host_profile\_bugreports-archive-<stamp>`，未删除，供后续排查。

## 6. 未覆盖

- 本轮全部为**墙钟**口径，没有 ETW/采样器交叉验证；单帧 30 ms 量级下墙钟噪声约 ±1 ms。
- C1/C3 的收益未做**归因拆分**（c1-only / c3-only 两个裁剪构建脚本已具备 `-Only c1|c3` 能力，本轮未跑）。
- 宿主崩溃导致的轮次作废见 §7；作废轮不参与任何统计。

## 7. 结果

### 7.1 运行与可用性

| 项 | 值 |
|---|---|
| 驱动命令 | `run-ab.ps1 -Pairs 5 -Rounds 5 -Frames 30 -Warmup 15 -MaxLoadPct 30 -QuietMaxLoadPct 20 -OutRoot S:\tmp\cmt_vmd_profile_20261019\hotpath\ab\t19g` |
| 退出码 | **0**（`AB_OK`） |
| 启动轮数 | 10（5 对 × baseline/candidate），每轮独立启动宿主，`module_match=True` × 10 |
| 每轮 rep | 物理开 5 次 / 物理关 5 次交替（预热 15 帧、计时 30 帧） |
| 丢弃轮 | 1 次：`p2-baseline` 首次启动 load 33.0% > 30% → 门禁丢弃后重测（`launch_discards=1`，不算失败） |
| 崩溃/作废轮 | 本轮 t19g **无**崩溃、无作废（12:52–13:45 的崩溃轮见 §5，已全部作废且不参与统计） |

### 7.2 每轮原始 median（每轮 5 次 rep 的 median，ms/帧）

| pair | baseline on | baseline off | baseline load | candidate on | candidate off | candidate load | Δon | Δoff |
|---|---|---|---|---|---|---|---|---|
| 1 | 35.2191 | 18.9282 | 13.3% | 34.4612 | 18.1447 | 24.6% | −0.758 (−2.15%) | −0.784 (−4.14%) |
| 2 | 35.6609 | 18.6033 | 7.9% | 34.0729 | 18.0032 | 26.0% | −1.588 (−4.45%) | −0.600 (−3.23%) |
| 3 | 35.3038 | 18.3660 | 10.2% | 34.4078 | 17.9243 | 10.8% | −0.896 (−2.54%) | −0.442 (−2.40%) |
| 4 | 42.0989 | 22.8879 | **29.9%** | 34.3009 | 17.7893 | 15.6% | −7.798 (−18.52%) | −5.099 (−22.28%) |
| 5 | 36.5108 | 19.7303 | 17.9% | 37.0261 | 19.9036 | 19.6% | +0.515 (+1.41%) | +0.173 (+0.88%) |

`pair 5` 是唯一「候选略慢」的配对（+1.41% / +0.88%），量级与墙钟噪声（±1 ms ≈ ±3%）同阶。

### 7.3 聚合与散布

| 变体 | on median（5 轮 median 的中位数） | on mean | on min–max | on CV | off median | off mean | off min–max | off CV |
|---|---|---|---|---|---|---|---|---|
| baseline | 35.661 | 36.959 | 35.219–42.099 | 7.90% | 18.928 | 19.703 | 18.366–22.888 | 9.41% |
| candidate | **34.408** | 34.854 | 34.073–37.026 | **3.51%** | **18.003** | 18.353 | 17.789–19.904 | **4.77%** |

- 全 5 对：on **−1.253 ms（−3.51%）**、off **−0.925 ms（−4.89%）**；逐对 delta 中位数 on −2.54%、off −3.23%。
- **剔除 pair 4**（baseline 在 29.9% 负载下测，该轮自身 on CV 20.02% / off CV 22.81%，属明显污染轮）：
  余下 4 对 on 35.482→34.434 = **−1.048 ms（−2.95%）**、off 18.766→18.074 = **−0.692 ms（−3.69%）**；
  逐对 delta 中位数 on −2.34%、off −2.81%。
- 结论口径：以剔除污染轮后的 **on −1.05 ms（−2.95%）** 与 **off −0.69 ms（−3.69%）** 为主，
  全量数字（−1.25 / −0.93 ms）作为上界参考。两种口径方向一致、幅度同一量级。

### 7.4 与 t14 预期对比（未达预期，如实记录）

t14 的分解预期：C1「控制状态扫描合并」1.0–3.5 ms/帧 + C3「键帧二分」0.5–2.5 ms/帧，**合计 1.5–6.0 ms/帧**。

| 指标 | 预期 | 实测（剔除污染轮 / 全量） | 判定 |
|---|---|---|---|
| 物理开 | 1.5–6.0 ms | **1.05 / 1.25 ms** | **低于合计下界**（约为下界的 0.70–0.84） |
| 物理关 | 1.5–6.0 ms | **0.69 / 0.93 ms** | **低于合计下界** |

如实说明：

- 收益**存在但很小**：物理开约 −3%、物理关约 −3.7%，单帧 30 ms 量级下属于「可测但不显著」。
- 量级与「**C3 单独收益落在 0.5–2.5 ms 区间内、C1 接近 0**」相容：
  C1 的合并扫描在 625 骨规模下省下的时间被 5 次 rep 的墙钟噪声掩盖；C3 的二分替换（每骨每帧 2 次
  O(K) 扫描 → O(log K)）是可感知的小头。
- 本轮**未做归因拆分**（`build-candidate.ps1 -Only c1|c3` 已具备能力但未跑），因此「C1≈0、C3≈全部」
  只是与数据相容的推断，**不是实测归因**。
- 判据「是否仍低于 30 FPS 预算 33.3 ms」：物理开仍在 **34.4 ms**（略超预算），因此**这两处改动不足以把
  物理开拉回 33.3 ms 以内**；物理关 18.0 ms 远低于预算。

### 7.5 网格一致性（效果证据）

`run-mesh.ps1 -OutRoot S:\tmp\cmt_vmd_profile_20261019\hotpath\mesh-rerun`（两版各一次 `-DumpMesh`，
`MESH_OK`）；对象 `阿芙2.0.pmx/MMD网格管理器/Mesh`，**70,222 点**，三帧逐字节相同且与历史锚点相同：

| 帧 | 口径 | baseline | candidate | 历史锚点（t13 round1-baseline） |
|---|---|---|---|---|
| 540 | local | `07757cb63370023f…eece0fae10` | `07757cb63370023f…eece0fae10` | 同左 |
| 540 | world | `5361f419809f8b3c…d6b0023fc6` | `5361f419809f8b3c…d6b0023fc6` | 同左 |
| 560 | local | `068d56c87b41b1f1…cbde7aae3b2` | `068d56c87b41b1f1…cbde7aae3b2` | 同左 |
| 560 | world | `e07de0caefc2b54a…5e6a7e2ec5d9` | `e07de0caefc2b54a…5e6a7e2ec5d9` | 同左 |
| 619 | local | `c15545a9a0b151e4…6c78424a8c` | `c15545a9a0b151e4…6c78424a8c` | 同左 |
| 619 | world | `fba9fd247e3cce72…9c116d5641a919` | `fba9fd247e3cce72…9c116d5641a919` | 同左 |

`local_eq / world_eq / anchor_eq` 三帧全部 `true` → **候选与基线的变形结果逐字节一致，无肉眼或数值差异**。

### 7.6 收尾与已知小问题

- 10/10 轮宿主均按用户授权以 `Stop-Process` 收尾（`stop_forced=true`；`CloseMainWindow` 在 MCP 长连接下
  常等不到 10–15 s 内退出），每轮 `remaining_cinema4d=0`，`5557` 已释放；无残留 C4D 进程。
- **`ab-summary.json` 的 `cleanup.remaining_any=true` 是我聚合表达式的 bug**（逐轮记录均为 0，
  见 §7.6 的逐轮字段）；真实结论以逐轮 `remaining_cinema4d` 为准。该字段下轮修。
- `run-mesh.ps1` 首次运行在聚合处崩溃（`$summary.artifact_sha` 属性不存在，StrictMode 抛错）；
  已改为从 `plugins.module_sha256` / `host.loaded_module_sha256` 取值后重跑通过。

