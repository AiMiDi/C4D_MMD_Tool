# P8 异步物理语义证据（A/B/A 真机）

场景：`C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx` + `C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd`，
625 骨骼 / 479 刚体（452 参与求解 + 27 骨骼跟随）/ 748 关节，30 fps。

- 同步工件：`S:\tmp\cmt_vmd_profile_20261019\p7\sync\plugins\mmdtool\mmdtool.xdl64`
  sha256 `21AF780B…C6ED`（3,779,584 B）
- 异步工件：`S:\tmp\cmt_vmd_profile_20261019\p8\async\plugins\mmdtool\mmdtool.xdl64`
  sha256 `51CE067E…B5D2`（3,811,328 B，含 P8 建世界姿态修正）
- 原始 probe：`S:\tmp\cmt_vmd_profile_20261019\p8b\ab\sem\segments\{A1-sync,B-async}\semantics\probe.host.json`

## 判据：按刚体类型分档 lag

异步物理把**参与求解**的刚体推迟一帧写回，而**骨骼跟随**刚体（PMX 类型 0）不参与求解、
由当帧骨骼直接驱动，没有滞后：

| 类别 | 数量 | 正确配对 |
| --- | --- | --- |
| 参与求解（类型 1/2） | 452 | `async(N) == sync(N-1)` |
| 骨骼跟随（类型 0） | 27 | `async(N) == sync(N)` |

旧判据把 479 个刚体一律按 `lag = 1` 比较，等于拿两帧不同的骨骼姿态相减，天生差几毫米到
几十毫米（实测 max 102.76 mm），把「语义正确」误判成发散。按数据反推分类得到 27 / 452，
与 PMX 类型分布一致。

## 结果（帧 540–620，容差 1e-4 mm / 1e-5 rad）

- 帧 540–560（稳态播放）：**479/479 全部落在容差内**，其中 452 个动力学刚体
  `async(N) == sync(N-1)` 为**逐位相等**（`matrix_hex` 原始 float32 字节），
  27 个骨骼跟随刚体 `async(N) == sync(N)` 只差旋转分量 3.8e-06 rad（float 噪声）。
- 帧 561（seek 后重建那一帧）：452 个动力学刚体超容差，max 102.7632 mm。
  这是影子世界被重建的**唯一一帧**瞬时差，符合预期：Bullet 状态路径相关，
  冷重建无法复现热连续轨的中间状态。
- 帧 562–620：**重新全部落回容差内**（562 起单调收敛，580/600/620 已回到逐位相等）。

结论：稳态语义 `async(N) == sync(N-1)`（动力学）/ `== sync(N)`（骨骼跟随）成立；
唯一例外是 seek 重建帧，属设计内的一次性重建瞬态。

## 主线程开销（同一次启动内 on − off，抵消整机负载共模）

| 段 | on 中位数 | off 中位数 | 主线程物理开销 |
| --- | --- | --- | --- |
| A1-sync | 34.36 / 34.30 / 35.19 | 18.24 / 17.69 / 18.71 | 16.12 / 16.61 / 16.48 ms |
| A2-sync | 36.05 / 35.36 / 34.40 | 19.01 / 18.53 / 17.41 | 17.04 / 16.83 / 16.99 ms |
| B-async | 24.93 / 22.15 / 19.10 | 20.38 / 18.49 / 18.21 | 4.55 / 3.65 / **0.89** ms |

- 同步段主线程物理开销稳定在 **16.1–17.0 ms**（跨 6 次启动散布 5.7%）。
- 异步段最接近无争用的一次为 **0.89 ms**，即主线程省下 **≈15.2 ms/帧**；
  负载高时残差升到 4.55 ms（提交/取回/写回撞上 CPU 争用），仍远低于同步段。
- 绝对帧时受整机负载影响大（同一异步段三次启动 on 中位数 24.93→19.10），
  因此跨段比较必须用上面的**同启动内差值**，不能用绝对 on 中位数。

## 复现

```powershell
# 语义（约 6 分钟，无需安静负载）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p7\sync\plugins `
  -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p8\async\plugins `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p8e\ab\sem -SkipTiming -Execute

# 主线程开销（读各段 launch-*/probe.json）
python docs\validation\vmd-physics-async-20261024\analyze-main-thread-cost.py `
  --root S:\tmp\cmt_vmd_profile_20261019\p8b\ab\timing2 --out <out>\main-thread-cost.json
```

## p9e：产品树默认开启 + Release 构建的端到端语义（2026-10-27）

- 工件：`_build_msvc\sdk_2027_v143_rel\bin\Release\plugins\mmdtool\mmdtool.xdl64`，sha256 `68d724ca28aa2fe2a3f409dafdb10ea61bae9b7caeca6a9a8d68397ff8b6f4bc`。
- 分段：A1-sync / B-async / A2-sync 用**同一份二进制**，差异只在 `CMT_PHYSICS_ASYNC`（A 段 `0`，B 段不设 = 产品默认开启）⇒ harness 记为 `artifact_variant_mode=runtime_switch`。
- 产物目录：`S:\tmp\cmt_vmd_profile_20261019\p9e\ab\sem`（`run-summary.json` / `lag-p4.json` / `lag-tolerance.json`）。
- 判定：`semantics_ok=true`、`failures=[]`、`warnings=[]`。

| 判据 | 结果 |
| --- | --- |
| roster（479 刚体） | 三段同 `f16bc0b7…`，contiguous、dup=0、unresolved_bones=0 |
| A1 vs A2 | 82/82 |
| 写回（两段） | 479 moved / 0 frozen / 82 帧 |
| 动力学 lag=1 逐位 | 36160 对比 0 超容差，maxT **0.0 mm**、maxR 2.1e-08 rad |
| 骨骼跟随（lag=0） | 2187 对比 0 超容差，maxT 3.49e-05 mm、maxR 4.69e-07 rad |
| 稳态窗口 | `lag1_within 81/81`，bodies_over=0 |
| seek 前窗口 | 22/22 |
| seek 后窗口 | 59/59（重建瞬态帧 561 单列报告，maxT 102.763 mm，不计入判定） |

复现：

```powershell
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\run-p4-ab.ps1 `
  -SyncPluginsPath <Release plugins> -AsyncPluginsPath <同一目录> `
  -OutRoot S:\tmp\cmt_vmd_profile_20261019\p9e\ab\sem -SkipTiming -QuietMaxLoadPct 100 -Execute
```

注意：`-QuietMaxLoadPct 100` 仅用于**语义**段（语义与负载无关，避免 `Wait-MachineQuiet` 空转 15 分钟）；计时段仍用默认 20%。宿主侧 MCP 端口若丢失，按 `docs/validation/vmd-host-restore-20261024/mcp-port-recovery.md` 恢复。

## p9e：主线程物理开销 A/B/A 计时（2026-10-27，Release 构建）

- 产物目录：`S:\tmp\cmt_vmd_profile_20261019\p9e\ab\timing`（`main-thread-cost.json`、`run-summary.json`）。
- 参数：`-Launches 3 -Reps 5 -Warmup 15 -Frames 30 -MaxLoadPct 60 -QuietMaxLoadPct 100 -SkipSemantics -SemanticsRoot p9e\ab\sem`。
  （`QuietMaxLoadPct 100` + `MaxLoadPct 60` 是因为机器常驻负载 40–60%，静默门 20% 永远等不到；判据改用**同一次启动内 on − off 的差值**，整机负载是共模项，会被差值抵消。）
- 三段：`a1_a2_drift 0.84%`（阈值 5%），`benefit_ms 16.73`（整帧中位数差）。

| 段 | on 中位（ms） | off 中位（ms） | 同启动内 on−off（主线程物理） |
| --- | --- | --- | --- |
| A1-sync | 37.7541（37.03/38.43/37.81） | 20.6965（20.44/21.03/20.62） | 16.47 ~ 17.73 |
| B-async | 20.5349（19.43/20.92/21.26） | 19.2016（18.56/19.23/19.81） | **0.78 ~ 1.83** |
| A2-sync | 37.9350（39.20/37.12/37.49） | 20.3191（21.53/19.75/19.67） | 17.39 ~ 17.91 |

- `MAIN_THREAD_COST`：sync 16.4705 ms → async 0.782 ms，**省 15.69 ms/帧**（异步侧固定残差 0.78 ms = 提交/取回/写回）。
- 结论：异步物理把每帧约 16.5–17.6 ms 的 Bullet 主线程开销压到 0.8–1.8 ms；整帧从 37.75 ms 降到 20.53 ms（30 FPS 预算 33.3 ms 下从「掉帧」回到「余量 12.8 ms」）。
- 计时判据备注：这一轮 harness 因「`-SkipSemantics` 复用路径没有一并复用 `lag-tolerance.json`」把 `lag1_within_tolerance` 判成 failed（数值为空），已修（新增 `tolerance_reused`），并用 `-SkipTiming -SkipSemantics -SemanticsRoot` 复跑验证全绿（`S:\tmp\cmt_vmd_profile_20261019\p9e\ab\reuse-check`）。

## 附录：插件测试套件结果（2026-10-28，Debug）

- 配置：`dev-windows-deps-test` 预设写死 `Visual Studio 17 2022`，本机只有 VS 2026（18.11.12306.390），按 `DEVELOPMENT.md:313` 等价改写为 `-G "Visual Studio 18 2026" -A x64 -T v143`（工具集仍 v143），配置与 95 个工程构建均成功。
- 全量 31 例（`ctest -C Debug -LE "benchmark;performance"`）：**97% passed，1 failed**，Total 1616.63 s。
- 唯一失败是 `cmt_motion_sizing_parallel`：`***Timeout 60.04 sec` —— 撞上 `tests/CMakeLists.txt:86` 写死的 `TIMEOUT 60`；绕过该属性直接运行 `mmd_motion_sizing_parallel_test.exe` 两次均 **exit 0**（62.1 s / 63.4 s），属 Debug 下计时阈值不足，不是功能缺陷。
- `cmt_motion_sizing_advanced` 通过但耗时 1543 s（Debug + Eigen 未优化，无 TIMEOUT 属性）。
- 结论：异步物理改动**没有引入测试回归**；上述超时属测试工程自身的 Debug 计时阈值问题，本次未修改该文件。

## 附录：R20（/std:c++17）兼容性与最终工件复核（2026-10-28）

- R20 兼容 SDK 树（`_build_msvc\sdk_r20`，`CMAKE_CXX_STANDARD=17`）重新配置并构建成功：`cmake -S sdk_r20 -B _build_msvc\sdk_r20` + `cmake --build _build_msvc\sdk_r20 --config Debug --target mmdtool`，产物 `_build_msvc\sdk_r20\bin\Debug\plugins\mmdtool\mmdtool_Debug.xdl64`（9,588,736 B，sha256 `64a3ff7142bfb4668cc1505eea872e36cbabd30b0f8313a7181433b78c20a669`）。
- 过程中修掉一个真实兼容性问题：R20 的 **Maxon Source Processor 不接受 C++17 嵌套命名空间简写**，报 `cmt_physics_epoch.h(50,1): error : Expected ;, found  instead.`（同理 `cmt_physics_seed.h(125,1)`、`cmt_rigid_identity.h(43,1)`）。三个头文件改为经典嵌套 `namespace cmt { namespace physics { ... } }` 后通过——这是源码处理器的限制，不是编译器（`/std:c++17` 本身支持该写法）。
- 最终 Release 工件（命名空间修复后重编）：`_build_msvc\sdk_2027_v143_rel\bin\Release\plugins\mmdtool\mmdtool.xdl64`，3,811,840 B，sha256 `4fa4f01370d08aec9263c0d990a839286112339fece9600d47e7fde69bb71952`。
- 用该工件复跑 A/B/A（`S:\tmp\cmt_vmd_profile_20261019\p11\ab\sem`，同一二进制分别以 `CMT_PHYSICS_ASYNC=0` / 默认开启 运行）：`semantics_ok=true`、`failures=[]`、`warnings=[]`；`lag1_within 81/81`、dynamic `0 bad / 36160`（maxT 0.0 mm）、kinematic `0 bad / 2187`（maxT 3.4925e-05 mm）、`seek_pre 22/22`、`seek_post 59/59`、重建瞬态仅帧 561 单列。
- 结论：R20 与 2027 两套工具链都编得过，最终发布工件语义零回归。
