# P2 异步物理 —— 真实宿主 A/B/A 与语义验证结果（t34）

日期：2026-10-25　宿主：Cinema 4D 2027（2027.0.0）　场景：阿芙2.0.pmx + Stay Tonight VMD（625 骨 / 479 刚体 / 748 约束 / 70,222 点）

## 0. 结论（先看这三行）

1. **默认配置下 async 档根本不可达**：`CMT_PHYSICS_ASYNC=1` 确实被读到、异步档也确实启动成功（诊断构建实证），但帧内主路径走的是 P1 的 `Produce/Consume` 缝分支，而 async 钩子只挂在 `StepStandalonePhysics()` 里 → **默认设置下 async 是死代码**，主线程收益 **+0.219 ms（= 0）**，判定 **archive_invisible**。
2. 只有把 P1 缝强制关掉（`CMT_PHYSICS_PIPELINE=0`）才会走 `StepStandalonePhysics()`，此时收益真实且巨大：主线程物理开 **33.3714 → 17.94 ms（−15.5 ms / −46%）**，物理关基本不变（17.37 → 17.40）。
3. 但强制可达时语义不等价：**网格（变形）11 帧逐字节相同**，然而**刚体世界矩阵从第 2 帧起就与 sync 不同**，且 **lag 0–4 帧全部 0/11 命中**（不是「晚一帧」，不是固定滞后）。按「达标门槛 + 语义等价」双条件，**不建议默认开**；需要 P2 负责人先修「接线（seam 分支）+ 影子世界初始化一致性」。

## 1. 两版工件（隔离工作树，产品树零改动）

- 隔离源：`git worktree add --detach S:\tmp\cmt_vmd_profile_20261019\async-src HEAD`（HEAD = `4daff9e2`）；`dependency/bullet3`、`dependency/libMMD` 为子模块空目录，已从产品树 robocopy（355 MB）补齐。
- 候选补丁：`.dsh-switchman\vmd-perf-20261024\candidate-async-p2\candidate-async-p2.patch`，61,835 B，sha256 `9fb40d801c773717d7bc48dbf22719edeaa87b4d9dcca7ac81b1729fd91a5155`；`git apply --check` / `git apply` 均 exit 0。
- configure（两版同一条命令，仅补丁前后不同）：
  `cmake -S S:\tmp\cmt_vmd_profile_20261019\async-src\sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\async-build-baseline -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`
  `CMakeCache.txt` 实测 `CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF`；两版二进制均无 `CMT_RUNTIME_PROFILING=1` 标记（`cmake/check_profiling_disabled.cmake` 的判据）。
- 构建：`cmake --build <build> --config Release --target mmdtool`。baseline 全量 **139.1 s**；应用补丁后必须**重新 configure** 再 build（新 `cmt_physics_async.cpp` / `cmt_physics_pipeline.cpp` 是 GLOB 收录，patch 在 configure 之后应用会报 16 个 `LNK2019`）。

| 变体 | 工件路径 | 字节数 | sha256 |
|---|---|---|---|
| baseline(sync) | `S:\tmp\cmt_vmd_profile_20261019\physics-async\sync\plugins\mmdtool\mmdtool.xdl64` | 3,779,584 | `942e24bfce714f7c89945e26e1ee4219f998bf04f1e7d81430f405308d6fd07d` |
| async | `S:\tmp\cmt_vmd_profile_20261019\physics-async\async\plugins\mmdtool\mmdtool.xdl64` | 3,808,768 | `7c261ea091f50f5bd3255dfe83afb47048c1156ec59c70405dfd8f547958318c` |

ResolvedModuleSha：每次宿主启动都由 `launch-host.ps1` 写入 `host-identity.json` 并与本地工件逐轮比对，**3/3 段 `module_match=True`**（即宿主里确实加载了对应版本，不是「以为加载了」）。

产品树收尾：`git -C C:/code/C4D_MMD_Tool status --short --ignore-submodules -- source` 只有既存未跟踪文件 `?? source/utils/pmx_entity_apply_regression.hpp`（0 B，任务开工前就在），**tracked 改动 0**。

## 2. 默认配置的 A/B/A 计时（A1-sync / B-async / A2-sync，各 5 rep）

命令：`run-ab-async.ps1 -SyncPluginsPath <sync> -AsyncPluginsPath <async> -OutRoot S:\tmp\...\runs\default-aba -Pairs 1 -Rounds 5 -Frames 30 -Warmup 15 -MaxLoadPct 30 -SkipSemantics -Execute`（exit 0）
测量口径：`stable-measure.ps1`，预热 15 帧（540–555），计时 30 帧（560–589），物理开/关各 5 rep 交替，`-MaxLoadPct 30` 负载门禁（本轮无丢弃）。

| 段 | pid | ticks(UTC) | module sha | on median (ms) | off median (ms) | load |
|---|---|---|---|---|---|---|
| A1-sync | 7088 | 639285116560868983 | 942e24bf | **33.5476** | 17.4017 | 8.0% |
| B-async (`CMT_PHYSICS_ASYNC=1`) | 71580 | 639285117188579120 | 7c261ea0 | **33.7534** | 17.5063 | 9.8% |
| A2-sync | 60364 | 639285117828366539 | 942e24bf | **33.5220** | 17.4217 | 9.3% |

- A1/A2 一致性：**漂移 0.08%**（<10% 门禁），本轮可用。
- async 相对 sync：**on +0.219 ms / off +0.095 ms** → 落在 **<1.5 ms → archive_invisible**。
- 每段 5 rep 原始 median 见 `S:\tmp\...\runs\default-aba\segments\*\timing\run-summary.json`。

## 3. 根因：默认设置下 async 走不到

- `cmt_physics_pipeline.h`（候选补丁）：`Mode mode_ = Mode::seam_sync;` → `SeamEnabled()` 默认 **true**。
- 帧内分支（补丁内 `mmd_model_manager.cpp` 物理段）：
  - `if (needs_physics_reset) { ResetStandalonePhysics(); }`
  - `else if (!physics_pipeline_.SeamEnabled()) { StepStandalonePhysics(1.f / fps_); }` ← **只有 seam 关时才走这里**
  - `else { physics_frame_id_ = ProduceStandalonePhysicsFrame(...); ConsumeStandalonePhysicsFrame(...); }` ← 默认走这里
- 而 `StepStandalonePhysics()` 是唯一的 async 分发点：`if (async_physics_active_) { StepStandaloneAsyncPhysics(elapsed); return; }`。
- 因此默认配置下 `Produce/Consume` 直接调用 `RunStandalonePhysicsStep`/`ApplyStandalonePhysicsResults`，**`StepStandalonePhysics` 从未被调用**。

实证（诊断构建，只改 `S:\tmp` 的 worktree，产品树未动）：在 `StartStandaloneAsyncPhysics()` 各失败出口与成功处、以及 `StepStandalonePhysics()` 入口写盘。默认配置跑一轮，日志只有：

```
enter a=625 b=1 c=0        # 625 骨、开关读到 1、active=0
identity a=479 b=479 c=479 # 身份/影子/主世界刚体数量对齐
started                    # 异步档启动成功
```

**没有任何 `step` 行** → 证明 async 档活着但主路径不经过它。对照：加 `CMT_PHYSICS_PIPELINE=0` 后主线程物理开时间立刻从 33.8 ms 掉到 18 ms（见 §4）。诊断脚本 `S:\tmp\...\physics-async\diag-async-start.py`、`diag-run.ps1`；诊断二进制只在 `S:\tmp\...\async-build-baseline`，未进任何交付目录。

## 4. 强制可达（`CMT_PHYSICS_PIPELINE=0`）的 A/B/A

同一 async 工件，只切 `CMT_PHYSICS_ASYNC`；三段各 5 rep，`-MaxLoadPct 30`：

| 段 | pid | ticks(UTC) | on median (ms) | off median (ms) | threads |
|---|---|---|---|---|---|
| A1 async=1 | 75208 | 639285118520941163 | **18.1136** | 17.5450 | 468 |
| B async=0 | 79652 | 639285119123163561 | **33.3714** | 17.3667 | 463 |
| A2 async=1 | 71244 | 639285119748796799 | **17.7739** | 17.2507 | 463 |

- 物理开：**33.3714 → 17.94（两段均值）/ −15.5 ms / −46%**；物理关：17.37 → 17.40（无变化）。
- 两个 async 段自洽（18.11 / 17.77，差 1.9%）。

## 5. 语义证据（seam 关，async=1 vs async=0 两台独立宿主）

### 5.1 C0 网格锚点（全部通过）

| 帧 | 局部 sha256（前 16） | 期望前缀 | 结果 |
|---|---|---|---|
| 540 | `07757cb63370023f` | 07757cb6 | PASSED |
| 560 | `068d56c87b41b1f1` | 068d56c8 | PASSED |
| 619 | `c15545a9a0b151e4` | c15545a9 | PASSED |

### 5.2 网格（变形）逐字节一致 —— 通过

- 帧 539/540/541/560/561/619/620：async 与 sync 的 `local_sha256` **全部相同**（`7c015f7d` / `07757cb6` / `772232cc` / `068d56c8` / `068d56c8` / `c15545a9` / `0aaabd45`）。
- 连续帧 556–566（11 帧）：全部 `same=True`。

**但这条证据比看起来弱**（必须写清）：同一场景把物理**关掉**跑，帧 556–561 的网格 sha 与物理开时**完全相同**（`068d56c8…`）。即在本场景/本窗口，网格 hash 对物理驱动骨骼不敏感（VMD 动画每帧把骨骼写满，物理结果影响不到可见变形）→ 「网格一致」只能证明「可见变形没有被 async 改坏」，**不能**证明「物理世界一致」。

### 5.3 刚体世界矩阵 —— 不等价（C1 / C2 不成立）

- 默认配置（semantics7，`S:\tmp\...\runs\semantics7`）：`C2 async(N) != sync(N)` **全部失败** → async(N) 与 sync(N) **逐字节相同**，即开关没生效（与 §3 根因一致）。
- seam 关（`runs\seamoff-contig`，连续 556–566）：
  - 帧 556（异步启动后第一帧）：`6d7860be4ce6` 相同。
  - 帧 557 起：`async != sync`，且 **lag 0/1/2/3/4 的命中数分别为 1/0/0/0/0（= 仅第一帧）**。
  - 结论：**异步刚体状态既不是「晚一帧」，也不是固定 k 帧滞后**；影子 Bullet 世界与主世界在起点之后很快分岔（数值不可比）。P2-004 只保证「身份/数量对齐」，不保证「数值轨迹一致」。

### 5.4 P2-004 名册独立核对 —— 通过

- 刚体数 **479**（sync / async 两段一致），`RIGID_INDEX` 覆盖 **0..478 连续无缺**。
- `roster_sha256 = f16bc0b77a188007`（键 = `RIGID_INDEX|name_local|bone_index|bone_name`），两段逐项相同；A1/A2 名册也逐项相同。
- 未解析骨骼数 **0**（RIGID_INDEX → 骨骼名映射完整）。
- 采样依赖：刚体管理器 `RIGID_DISPLAY_TYPE(1001)` 出厂是 `None`(=OFF)，而 `MMDRigidObject::Execute` 只在非 OFF 时写 `SetRelMl`；**不开显示就永远读到绑定位**。本轮全部语义采样都显式把 `1001` 置 1（`probe-rigid.py --enable-rigid-display` 默认开），这是能读到物理位姿的前提。

### 5.5 C6 A1/A2 一致性 —— 通过

两段 sync 的网格 + 刚体 sha 逐项相同（同场景、同序列、同配方）。

## 6. 门槛判定

| 配置 | 主线程 on 收益 | 语义等价 | 判定 |
|---|---|---|---|
| 默认（seam_sync） | +0.219 ms（≈0） | 由构造决定：async 不参与，等价但无收益 | **archive_invisible**（当前交付形态拿不到收益） |
| 强制 `CMT_PHYSICS_PIPELINE=0` | **−15.5 ms（−46%）** | 网格一致、**刚体世界不等价**（非固定滞后） | 不满足 promote 的语义前提 → **保持默认关闭** |
| 灰区（1.5–3.0 ms） | 不适用 | — | — |

- **worker CPU 开销：未测量**（现有脚本只有系统级 `\\Processor(_Total)` 采样，无逐线程采样）。可用代理：同样 5 rep 下系统级 CPU 采样 sync 11.3% vs async 12.0%/12.6%（+0.7–1.3 个百分点 ≈ 0.2–0.4 核），只能说明「worker 确实吃 CPU」，不足以给出精确开销 → 列为未覆盖。
- **lag 上限：无法给出**。`ceil(worker 单帧耗时/主线程帧间隔)` 这种「固定滞后」模型的前提是滞后为常数；实测 lag 0–4 全部 0 命中，说明不是固定滞后，故该公式不适用（这本身是要 P2 修的问题）。

## 7. 宿主收尾

- 本轮所有宿主：`stop_method = Stop-Process`、`forced = true`（用户授权）、`remaining_cinema4d = 0`、5557 端口释放。
- 本轮**没有**新的 C4D 崩溃；此前两轮 `python311.dll` 崩溃包已归档在 `S:\tmp\cmt_vmd_profile_20261019\host_profile\_bugreports-archive-20261025T132544` / `...T134417`（未删除、未覆盖）。
- 任务结束时复查：`Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'"` = 0；`Get-NetTCPConnection -LocalPort 5557` 无监听。

## 8. 复现命令

```powershell
# 1) 隔离工作树 + 补丁
git worktree add --detach S:\tmp\cmt_vmd_profile_20261019\async-src HEAD
#   补依赖：robocopy 产品树 dependency\bullet3、dependency\libMMD 到 worktree
git -C S:\tmp\cmt_vmd_profile_20261019\async-src apply <patch>

# 2) 构建（baseline 与 async 各一次，同一 -B）
cmake -S S:\tmp\cmt_vmd_profile_20261019\async-src\sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\async-build-baseline `
      -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF
cmake --build S:\tmp\cmt_vmd_profile_20261019\async-build-baseline --config Release --target mmdtool

# 3) 默认配置 A/B/A（契约口径）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-ab-async.ps1 `
  -SyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\physics-async\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\physics-async\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\physics-async\runs\default-aba `
  -Pairs 1 -Rounds 5 -MaxLoadPct 30 -Execute

# 4) 语义（含强制 seam 关的对照）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-ab-async.ps1 ... -SkipTiming -Execute
#    强制可达：$env:CMT_PHYSICS_PIPELINE='0'，再只切 CMT_PHYSICS_ASYNC
```

## 9. 未覆盖 / 已知限制

1. **worker CPU 开销未逐线程测量**（见 §6），只有系统级代理。
2. **lag 上限未给出**：实测不是固定滞后，公式不适用；影子世界与主世界为何分岔未定位到具体一行（怀疑影子 Bullet 冷启动的 warm-start / 每帧 dt 累积与主世界不同），需要在 P2 侧加计数器才能定位。
3. 网格 hash 在本场景对物理**不敏感**（物理开/关同 sha），所以「网格一致」不能当作物理等价证据；要证明物理效果一致必须比刚体世界矩阵（§5.3 显示不等价）。
4. 只测了一个场景（阿芙2.0 + Stay Tonight，625 骨/479 刚体/748 约束）、一种帧率（30 FPS）、一种计时窗口（560–589）。
5. 语义采样只在 seam 关时可达；默认配置下 `C1/C2` 天然不成立（且这正是要修的接线问题）。
6. 本轮全部为墙钟口径，无 ETW/采样器交叉验证。

## 10. 本轮脚本改动（都在 `docs/validation/vmd-physics-async-20261024/`）

- `probe-rigid.py`：修 `is_rigid()` 的中文类型名判定（`MMD刚体管理器` 曾被当成刚体）；`GetTags()` 在 2027 返回 list；刚体显示默认打开（`--enable-rigid-display`）；大 payload 改为宿主内写文件 + stdout 只回 ack（避免截断）；新增 P2-004 名册采样（`vmd-async-probe/2`）。
- `run-ab-async.ps1`：修 `-FrameList` 与 `[int]$Frames` 撞名、`$null.Count` StrictMode 崩溃、`stable-measure` 汇总字段路径（`aggregate.on|off.per_launch_median_ms`）；语义段补 `import-motion`（否则动画槽不存在、全帧静止）；语义帧序列与计时帧序列分离；`-OutRoot` 可省（dry-run 无需目录）。
