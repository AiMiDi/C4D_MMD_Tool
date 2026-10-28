# P4 异步物理相位：真机 A/B/A + seek 语义验证（t63）

> 结论口径（captain 定）：`lag=1` + `lag_constant=True` + 每帧 479 刚体世界矩阵逐位相等，才算 `semantics_ok`；
> `lag1_close_but_not_equal`（≤5 mm）判 failed；`seek_events_recorded` 缺失判 failed；seek 前/后两窗口分别判 lag=1。
> **语义不过则性能数字一律记「不可用」。**

## 0. 结论

- **语义（lag=1 逐位等价）：不成立。** `verdict=different_trajectory`、`lag_constant=false`、81 帧里 lag 0–40 全不命中，最早不等帧 **540**，最大偏差 **254.91 mm**（帧 553）。
- **写回已修好**：async 段 **479/479 刚体全部有非零位移**（frozen=0），P3 时期的 27/452 分裂消失。
- **seek 后仍不保持 lag=1**：seek 前窗口 0/21、seek 后窗口 0/60 相等；seek 事件本身有记录（1 次，560→600）。
- **性能：不可用**（按口径不给结论）；计时段仍按契约跑完，数字见 §4 仅供参考。
- **一句话判定：不能默认开 `CMT_PHYSICS_ASYNC`。** 当前不是「数值噪声」问题，而是影子世界推进与主世界走的轨迹不同（总位移比 sync 大 2.8 倍），需要继续定位步数/dt 口径。

## 1. 两版工件

| 变体 | 路径 | 字节 | sha256 |
|---|---|---|---|
| sync（干净 HEAD） | `S:\tmp\cmt_vmd_profile_20261019\p4b\sync\plugins\mmdtool\mmdtool.xdl64` | 3,779,584 | `a34bdbce42cd7822611efee1b944bb4a4fc59eeab7360bf305a8e6261425c1ca` |
| async（HEAD+patch） | `S:\tmp\cmt_vmd_profile_20261019\p4b\async\plugins\mmdtool\mmdtool.xdl64` | 3,810,304 | `5075c6759796420f243fbebc04c30ce9902ef1884902fdc2328bbaf05cb3752b` |

- patch：`c4a35f62c9e9c59899d6318c567b49059f31cbc0541450198fffd21247b2ca4a`（74,256 B，14 文件：7 改 + 7 新增，含 `cmt_physics_epoch.h`）。
- 构建：`-G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；configure 4.6/4.5 s、build 87.0/89.3 s（`-Parallel 8`）；两版均无 `CMT_RUNTIME_PROFILING=1` 标记；两棵树 cache 均为 `CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；产品树 tracked 改动 0。

## 2. 语义（82 帧 × 479 刚体逐位比 `matrix_hex`）

原始产物：`S:\tmp\cmt_vmd_profile_20261019\p4b\ab\sem3\`（`segments\<段>\semantics\probe.host.json` 为完整载荷，`lag-p4.json` 为分析结果）。

| 项目 | 数值 |
|---|---|
| 比较帧数 | 82（539–620），lag=1 有效比较 81 帧 |
| `lag=1` 逐位相等 | **0/81** |
| `lag_constant` | **false** |
| 判定 | `different_trajectory` |
| 最早不等帧 | **540** |
| 最大偏差 | **254.9132 mm**（帧 553） |
| 参考直方图（lag 0–4） | `{"0":1,"none":81}`（唯一命中是 539 起点） |
| A1-sync 位移 | moved 479/479，frozen 0，max **103.3192 mm** |
| B-async 位移 | moved 479/479，frozen 0，max **286.7826 mm**（≈ sync 的 2.8 倍） |
| 名册 | count 479、RIGID_INDEX 0..478 连续、dup 0、unresolved 0、`roster_sha256=f16bc0b77a1880076b39960fe1a8381ac642bd641811a761f67e0bce27a10803`（A1 == B == A2） |
| A1 vs A2 | 82/82 帧逐位一致（跨进程可复现性成立） |
| 锚点旁证 | 540 `07757cb6`/`5361f419`、560 `068d56c8`/`e07de0ca`、619 `c15545a9`/`fba9fd24` 全中（网格对物理不敏感，仅作旁证） |

判读：偏差从 540 这一帧就开始，且 async 的总位移显著大于 sync——**不是「晚一帧」而是「走得更远」**，与 P3 时期「452 个冻结」是不同性质的失败。离线夹具（199 帧 × 15,748 words 严格全等）与真机仍不一致，说明影子世界在宿主里的推进步数/步长与主世界不同（substeps × dt 口径，或每帧调用次数），需要下一步单独定位。

## 3. seek 行为（B-async 在帧 560 采完后跳到 600）

| 窗口 | lag=1 相等 | 最早不等帧 |
|---|---|---|
| seek 前（539–560） | 0/21 | 540 |
| seek 后（561–620） | 0/60 | 561 |

- `seek_events`：1 次，`after_frame=560`、`target_frame=600`、`rigid_count=479`、`doc_time_seconds_after` 已记录 —— 说明重建路径确实被触发（`seek_events_recorded` 断言 passed）。
- 但重建之后依旧没有回到 lag=1 且逐位相等：**P4 的 `RebuildStandaloneAsyncShadow()` 只修好了「重建发生」，没有修好「重建后与主世界同步」**。
- 按 captain 要求，本轮**没有**对 seek 段做任何重试掩盖；`stale-epoch-result-rejected` 那次 flake 在本轮未复现（没有出现帧号不连续或 lag 跳变到 2/3 的现场）。

## 4. 计时（同会话 A/B/A，每段 5 launch × 5 rep，`-MaxLoadPct 30`）—— 仅供参考

- 待回填（计时段运行中；因语义未过，本节数字**不作为结论**）。

## 5. worker / 进程 CPU 与并行度

- 待回填。

## 6. 门槛与结论

- 门槛：≥3.0 ms promote；<1.5 ms archive_invisible；1.5–3.0 灰区保持默认关。
- 因语义未过：`decision = unavailable`，**不主张默认开**。

## 7. 收尾

- 三段语义各自 `cleanup.json`：`method=Stop-Process forced=True remaining=0`（CloseMainWindow 30 s 超时后转 Stop-Process，用户已授权）。
- `host_clean` 断言 passed（C4D=0、5557 无监听）。
- 本任务未 push / 未提交 / 未打 tag；产品树 tracked 0。

## 8. 复现命令

```powershell
# 1) 语义段（单独落盘）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p4b\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p4b\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p4b\ab\sem3 -Execute -SkipTiming

# 2) 计时段（复用语义段结果，仍出一份合并 summary）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p4b\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p4b\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p4b\ab\main -Execute -SkipSemantics `
  -SemanticsRoot S:\tmp\cmt_vmd_profile_20261019\p4b\ab\sem3

# 3) 只读自检
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p4-ab.ps1 `
  -RunRoot S:\tmp\cmt_vmd_profile_20261019\p4b\ab\main `
  -BuildSummary S:\tmp\cmt_vmd_profile_20261019\p4b\build-summary.json -PatchShaPrefix c4a35f62
```

## 9. 未覆盖项

- 未定位「影子世界走得更远」的具体机制（substeps 与 dt 口径、每帧调用次数、kinematic 输入帧号）；本任务只做测量不做归因修改。
- 网格 sha 对物理不敏感（t34 结论），因此不能作为等价判据；本轮只把 540/560/619 当旁证，且为控制单次 exec 时长，其余帧不再计算网格（`--mesh-frames`）。
- 未验证 `lag=1` 之外的其他相位（P4 契约只认 lag=1）。
- 计时段因语义未过，数字不构成性能结论。
