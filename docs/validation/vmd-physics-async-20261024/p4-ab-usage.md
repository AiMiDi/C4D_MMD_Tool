# P4 真机 A/B/A 脚本就绪说明（t63 预备）

本文件只描述「脚本与判据」，不含实测数据；等 t62 复审通过后按此执行，结果写到 `host-ab-p4-result.md`（新文件）。

## 1. 相对 P3 的两处变化（P4 契约）

| 维度 | P3（`run-p3-ab.ps1`） | P4（`run-p4-ab.ps1`） |
|---|---|---|
| 等价判据 | 找任意常数 lag（0..N 全扫） | **必须 lag=1 且 `lag_constant=True`**，其余 lag 只作诊断参考 |
| seek | 无 | B-async 段采完 `-SeekAfterFrame` 后**跳变到 `-SeekToFrame`**，之后继续采样；分析器按 seek 前/后两窗口各自判定 lag=1 |
| 语义不过时的性能 | 标「不可用」 | 同（`decision=unavailable`，`benefit_ms` 仅作参考） |

## 2. 脚本清单（都在 `docs/validation/vmd-physics-async-20261024/`）

- `run-p4-ab.ps1`：三段 A1-sync / B-async(+seek) / A2-sync；计时走 `stable-measure.ps1`（`-MaxLoadPct`、`-LaunchRetries 2`、每段 `-Launches × -Reps`），语义走 `launch-host.ps1 → host-driver(new-scene/import/import-motion/set-mode/physics) → probe-rigid.py → stop-host.ps1`；无 `-Execute` 只打印 `P4_AB_PLAN`。
- `analyze-p4-lag.py`：输入 `probe.host.json`，输出 lag=1 逐帧结果、最早不等帧、偏差量级、`verdict`（`lag1_bitwise_equal` / `lag1_close_but_not_equal` / `different_trajectory` / `lag1_partial`）、名册摘要、锚点、seek 两窗口。
- `probe-rigid.py`：新增 `--seek-after-frame` / `--seek-to-frame`，宿主内采完该帧后做一次时间跳变求值，并把跳变前后刚体指纹记入 `seek_events`。
- `check-p4-ab.ps1`：对 `run-summary.json` + `lag-p4.json` 做只读断言（46 项：工件 sha/大小/无 profiling 标记、产品树 tracked=0、三段 median/launches/load/module_match、A1/A2 漂移、479 全动、lag=1、名册 479 连续无重复、锚点、A1==A2、seek 前后窗口、结论一致性、C4D=0 与 5557 无监听）。

## 3. 执行命令（t62 通过后）

```powershell
# 1) 构建（沿用 build-p3-ab.ps1，patch 换成 P4 版；-Parallel 8 规避 MSVC C1001 内存问题）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1 `
  -Src S:\tmp\cmt_vmd_profile_20261019\p4-src -WorkRoot S:\tmp\cmt_vmd_profile_20261019\p4 `
  -PatchShaPrefix <P4 patch sha 前缀> -Parallel 8 -BuildRetries 1

# 2) A/B/A + seek 语义
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p4\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p4\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p4\ab\main -Execute

# 3) 自检（exit 0 才算过）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\check-p4-ab.ps1 `
  -RunRoot S:\tmp\cmt_vmd_profile_20261019\p4\ab\main `
  -BuildSummary S:\tmp\cmt_vmd_profile_20261019\p4\build-summary.json -PatchShaPrefix <前缀>

# 4) 进程 CPU / 并行度（沿用 t58 口径）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-cpu-diff.ps1 ...
```

## 4. 判据与门槛

- **写回**：A1/B 段 `displacement.*.all_rigids_moved=True`（t58 已达成 479/479）。
- **等价**：`lag1.all_equal=True` 且 `lag_constant=True`，窗口 ≥80 帧；不等时报告给出最早不等帧与 `max_deviation_mm`，并区分「差一点（median ≤5 mm）」与「另一条轨迹（median ≥50 mm）」。
- **seek**：`seek.pre_window.lag1.all_equal` 与 `seek.post_window.lag1.all_equal` 同时为真；`seek_events ≥1` 作为「重建确实发生」的行为证据（若 P4 补丁另有 epoch 日志，应一并附在报告里）。
- **性能**：`benefit_ms ≥3.0` → promote；`<1.5` → archive_invisible；1.5–3.0 → gray_keep_off；**语义不过一律 `unavailable`**。
- **收尾**：C4D=0、5557 无监听、崩溃 `_bugreports` 归档并标 invalid。

## 5. 已做的离线自检（未启宿主、未构建）

- `analyze-p4-lag.py` 用 t58 的 82 帧数据回放：`verdict=different_trajectory`、最早不等帧 540、worst 258.59 mm、479/479 全动、名册三段同 sha、seek 两窗口分别 0/21 与 0/60 —— 与 t58 结论一致，说明判据方向正确。
- `run-p4-ab.ps1` 无 `-Execute`：打印 `P4_AB_PLAN`（三段、sed frames 展开、seek 560→600、阈值 3.0/1.5/5.0）exit 0。
- `check-p4-ab.ps1` 对合成 fixture 跑出 46 断言、无崩溃；对 P3 数据按预期在 lag1/seek 上 failed（证明断言不是恒真）。

## 6. 未覆盖

- 真实宿主上的 seek 行为（`seek_events` 是否产生、重建后是否立刻 lag=1）未验证——属于 t63 本体。
- `probe-rigid.py` 的 seek 分支只在静态层面检查过（模板占位符/guard/落盘字段），尚未在宿主内执行。
- 崩溃环境（python311.dll 类）不受控，`-LaunchRetries` 只能缓解，不能消除；崩溃轮仍按 invalid 记。
