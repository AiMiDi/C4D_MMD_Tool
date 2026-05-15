# 动画 / IK / 物理流水线诊断（CMT_ANIM_FLOW_DEBUG）

本文配套 `source/utils/cmt_anim_flow_debug.hpp` 一组受环境变量控制的 `[CMT][AnimFlow]`
诊断日志，专门用来定位 **IK 控制下的骨骼播放/scrub 时不流畅、出现"阶梯感"** 这类问题。

诊断打开后，C4D Console 的 Diagnostic 输出里会逐帧出现一组 `[CMT][AnimFlow]` 行，配合
`[CMT][Frame N]` 既有的 `ModelExecute` / `BoneManagerExecute` / `PrepareSceneForPhysicsPlayback`
/ `PrePhysicsIK` / `StepStandalonePhysics` 行，可以拼出完整的逐帧执行流水线。

> 默认完全关闭，开关基于 `std::getenv` + 静态变量缓存，关闭时只剩一次 atomic load，
> 不影响 release 性能。

---

## 1. 启动方式

### 1.1 环境变量

| 变量 | 取值 | 作用 |
|---|---|---|
| `CMT_ANIM_FLOW_DEBUG` | `1` / `true` 等任意非 `0`/`false`/`FALSE` 的非空值 | 打开整套 `[CMT][AnimFlow]` 日志 |
| `CMT_ANIM_FLOW_BONE` | 整数 bone_index，例如 `87` | 仅记录指定骨骼（一般写问题最严重的 IK 末端骨骼 index）；不设或 `-1` 表示全部记录 |
| `CMT_INITIAL_STATE_DEBUG` | `1` | 已有开关；打开后 `BoneManagerExecute` 等日志会列出每帧涉及的骨骼名，便于交叉对照 |

PowerShell 启动 Cinema 4D 2026 + 我们的插件并打开诊断的最小命令：

```powershell
$env:CMT_ANIM_FLOW_DEBUG = "1"
$env:CMT_ANIM_FLOW_BONE  = "<问题最严重的 IK 末端 bone_index>"   # 可选
$env:CMT_INITIAL_STATE_DEBUG = "1"                              # 可选，但强烈推荐

& "C:\Program Files\Maxon Cinema 4D 2026\Cinema 4D.exe" `
  g_console=true `
  g_additionalModulePath="D:\code\C4D_MMD_Tool\_build_msvc\sdk_2026\bin\Debug\plugins"
```

`g_console=true` 在 Windows 上会打开独立的 Console 窗口，所有 `DebugOutput(maxon::OUTPUT::DIAGNOSTIC, ...)`
会直接输出到那里。如果想抓到文件里，再用 `2>&1 | Tee-Object cmt_anim_flow.log` 之类组合即可。

### 1.2 复现工作流

1. 拖入 PMX 模型并完成正常导入流程（直到生成 ModelManager / BoneManager / 等）。
2. 拖入对应 VMD 动画。
3. **保持时间轴在第 0 帧**，确认所有 `[CMT][AnimFlow]` 行都已经出现。
4. 把时间轴拉到一段已知"阶梯感"明显的区间（例如手部 IK、脚部 IK 集中变化的区段）。
5. 点击 Play 让其连续播放 1~3 秒；或者用方向键逐帧前进 30~60 帧。
6. 关闭 Play 或停止播放，从 Console 复制日志。

---

## 2. 输出结构

### 2.1 `MMDBoneTag::Execute`（每帧、每根骨骼）

```
[CMT][AnimFlow][Frame N][Bone i] BoneTag::Execute isIK=0/1 deformAfterPhys=0/1 modelManager=0/1 standaloneSolve=0/1 applyToScene=0/1 skipPre=0/1 playbackOverride=0/1
```

| 字段 | 含义 |
|---|---|
| `isIK` | 该骨骼是否为 IK 骨骼 |
| `deformAfterPhys` | 该骨骼是否被标为 *物理后变形* |
| `modelManager` | 该骨骼是否关联到 ModelManager（完整模型导入时为 1） |
| `standaloneSolve` | 本次 Execute 是否会**自己解 IK**（`!deformAfterPhys && isIK && !modelManager`） |
| `applyToScene` | 本次 Execute 是否会把局部矩阵写回场景 |
| `skipPre` | `ShouldSkipPrephysicsSceneWrite` 真值（pre-physics IK 已先行写过场景） |
| `playbackOverride` | 物理 / IK 临时 override 是否在本帧已下发 |

### 2.2 `MMDBoneTag::ApplyActiveAnimation`（仅在该骨骼存在 keyframes 时）

```
[CMT][AnimFlow][Bone i] ApplyActiveAnimation contFrame=F slotKeys=K upperIdx=U keyLo=L keyHi=H applyToScene=0/1
```

* `contFrame` 是浮点连续帧（来自 `GetAnimationFrameFromDocumentContinuous`）；
* `keyLo` / `keyHi` 是当前所处的两侧 keyframe 帧号；
* 如果你看到 `contFrame` 在播放过程中跳跃 ≫1.0，那就是上游时间→帧的转换出了问题。

### 2.3 `MMDBoneTag::RunIKSolveAnimMode`

```
[CMT][AnimFlow][Frame N][Bone i] RunIKSolveAnimMode SOLVED markChain=0/1 allowSameFrame=0/1
```

不同分支会输出不同的 `rejected` / `short-circuit` / `bailed` 行，帮助定位**为什么 IK 没解**：

| 行尾 | 原因 |
|---|---|
| `rejected op=0/1 mode=N isIK=0/1` | 入参不对或骨骼不是 IK |
| `short-circuit (sameFrame)` | 同 BaseTime 已经解过，跳过 |
| `bailed mgr=0/1` | ModelManager 缺失或 standalone runtime 没准备好 |
| `bailed solver=... enabled=... ikNode=... target=...` | IK 配置不完整（PMX 数据问题或链路构建失败） |

### 2.4 `MMDModelManagerObject::Execute`

补充行：

```
[CMT][AnimFlow][Frame N] ModelExecute timeDiff=Δ frameTime=Tf resetSeek=0/1 resetMinTime=0/1 resetUninit=0/1
```

* `resetSeek=1` 表示 **触发了"播放跳跃 reset 物理"** 那条阈值（`time_diff < 0.5*frame_time` 或 `> 1.5*frame_time`）；如果在正常播放下频繁出现，就要怀疑文档 fps≠30 或者 C4D 时间步长不稳定。
* 同帧重新进入会输出：

```
[CMT][AnimFlow][Frame N] ModelExecute sameTimeReentry prev=t0 now=t0
```

这是用来观察**是否有同一帧二次评估**导致的诡异写场景顺序。

* 物理关闭时还会输出：

```
[CMT][AnimFlow][Frame N] ModelExecute physicsDisabled noPhysicsStep noPrePhysicsIK
```

这一行**直接对应"候选 1"诊断假设**：完整模型场景下 BoneTag::Execute 不会自己解 IK
（`standaloneSolve=0`），ModelManager::Execute 又因为物理关闭跳过 PrePhysicsIK ——
那 IK 链上的骨骼**就完全没有被解算**，只剩各自 keyframe 给的局部姿态。

### 2.5 `MMDModelManagerObject::SolveStandaloneIKBeforePhysics`

```
[CMT][AnimFlow][Frame N][Bone i] PrePhysicsIK preTgt=(x,y,z) postTgt=(x,y,z)
```

`preTgt` 是 `ik_solver->Solve()` 之前 IK target adapter 的全局位置，`postTgt` 是解算之后的。
逐帧采集 `postTgt` 的 (x,y,z)，画成曲线就能看出末端骨骼是否在解算阶段做了平滑过渡。

---

## 3. 诊断假设与对应判断标准

### 候选 1（最高嫌疑）：物理关闭时 IK 完全没解算

* 假设：完整 PMX 模型 + 物理关闭 → `BoneTag::Execute` 走 `standaloneSolve=0`，`ModelManager::Execute` 走 `physicsDisabled`，全程没有任何路径调 `RunIKSolveAnimMode` / `SolveStandaloneIKBeforePhysics`。
* 判断方法：日志里
  * 出现 `BoneTag::Execute ... isIK=1 standaloneSolve=0`；
  * 出现 `ModelExecute physicsDisabled noPhysicsStep noPrePhysicsIK`；
  * **完全没有任何** `[CMT][AnimFlow][Frame N][Bone i] PrePhysicsIK ...` 或 `RunIKSolveAnimMode SOLVED` 行。

  → 三者同时成立即可确认候选 1。修复方向：在 `BoneTag::Execute` 物理关闭分支或 `ModelManager::Execute` 的 `else` 分支补一条 `BoneManager`/`ModelManager` 主导的 IK 解算入口。

### 候选 2（中等嫌疑）：同帧重入或 prev_time 短路

* 判断方法：
  * 高频出现 `ModelExecute sameTimeReentry`；
  * 同一帧内既有 `RunIKSolveAnimMode SOLVED` 又有更晚时间戳的 `BoneTag::Execute applyToScene=1` 写入（看 `[CMT][Frame N] BoneManagerExecute` 与 `PrePhysicsIK` 的相对顺序）。
* 修复方向：检查 `ModelManager::Execute` 是否需要在同帧 reentry 时仍然刷新 `last_prephysics_time_` 状态、或者 BoneTag::Execute 是否需要先检查 `last_postphysics_ik_solve_time_`。

### 候选 3（低嫌疑）：fps 不一致 / 时间步长漂移

* 判断方法：日志里 `frameTime` ≠ `1/30`，或者 `timeDiff` 在播放期间反复偏离 `frameTime` 一倍以上。
* 修复方向：要么把 `kBoneAnimationFps` / `kModelAnimationFps` 与 `doc->GetFps()` 解耦，要么在 ModelManager 里限定 fps_=30 而不是跟随文档。

---

## 4. 配套：cli-anything-lldb 实时抓数据

LLDB 配 C4D 时切记走 AGENTS.md 里要求的可靠启动顺序：**先正常起 C4D 加载完插件，再 attach**，
不要让 lldb-dap 直接 launch C4D 2026。

下面是 cli-anything-lldb（已通过 `pip install -e .` 安装到 `cli-anything-lldb` 命令）的最小工作流。
所有命令都加 `--json`，便于把结果直接喂给后续分析脚本。

### 4.1 准备

```powershell
$env:CMT_ANIM_FLOW_DEBUG = "1"
$env:CMT_ANIM_FLOW_BONE  = "<bone_index>"          # 可选
$env:CLI_ANYTHING_LLDB_SESSION_FILE = "$PWD\.lldb-cmt.session"

# 1. 正常启动 C4D 2026 + 插件
& "C:\Program Files\Maxon Cinema 4D 2026\Cinema 4D.exe" `
  g_console=true `
  g_additionalModulePath="D:\code\C4D_MMD_Tool\_build_msvc\sdk_2026\bin\Debug\plugins"

# 2. 等 C4D 加载完毕、mmdtool_Debug.xdl64 已经出现在加载列表里之后，再 attach
$pid = (Get-Process "Cinema 4D").Id
cli-anything-lldb --json target create --exe "C:\Program Files\Maxon Cinema 4D 2026\Cinema 4D.exe"
cli-anything-lldb --json process attach --pid $pid
```

### 4.2 断点

为避免每帧都被打断造成的 UI 卡死，**只下函数断点 + 立刻 continue**，把数据通过 expression
打印到 console（或者直接读现有的 `[CMT][AnimFlow]` 日志，效率更高）。

```powershell
# 仅在某根问题骨骼解 IK 时停一下抓现场
cli-anything-lldb --json breakpoint set --function "MMDBoneTag::RunIKSolveAnimMode" --allow-pending
cli-anything-lldb --json breakpoint list

# 命中后抓一帧关键变量，再 continue
cli-anything-lldb --json frame info
cli-anything-lldb --json frame locals
cli-anything-lldb --json expr "(int)this->is_IK"
cli-anything-lldb --json expr "(double)last_ik_solve_time_.Get()"
cli-anything-lldb --json expr "(double)doc->GetTime().Get()"
cli-anything-lldb --json expr "this->ik_overridden_this_frame_"
cli-anything-lldb --json process continue
```

### 4.3 noisy stops 处理

参考 AGENTS.md 里关于 lldb-dap 的注意事项：
* 推荐 attach 时直接走 DAP 入口（`cli-anything-lldb-dap`）并附带：

```json
{
  "autoContinueInternalBreakpoints": true,
  "autoContinueStopPatterns": [
    "nvgpucomp64.dll`destroyFinalizer",
    "__jit_debug_register_code"
  ]
}
```

* 显式 `pause` 之后看到的若是 nvgpucomp64 线程，要用 `GetWindowThreadProcessId` 找到 C4D 主线程再请求 stackTrace。

### 4.4 收尾

```powershell
cli-anything-lldb --json process detach
cli-anything-lldb --json session close
```

---

## 5. 后续操作建议

1. 如果日志验证了 **候选 1**：先讨论是要在 `BoneTag::Execute` 加一条"ModelManager 存在但物理关闭时也调用 RunIKSolveAnimMode"的补丁，还是把 IK 主驱动统一搬到 `BoneManagerObject::Execute` / `ModelManager::Execute` 内部。
2. 如果验证了 **候选 2**：把 `ModelManager::Execute` 的同帧 reentry 路径补上一次 IK 解算保护，或者在 BoneTag::Execute 入口加 `last_postphysics_ik_solve_time_` 检查，避免覆盖已写场景。
3. 如果验证了 **候选 3**：在 `MMDModelManagerObject::EnsureStandaloneRuntimeManagers` 时锁定 `fps_=30`，并在 UI 给一条警告（"document fps 不是 30，物理与 VMD 帧步长会不一致"）。

修完后再次按本文档第 1 节复现，日志里 `[CMT][AnimFlow][Frame N][Bone i] PrePhysicsIK postTgt=(...)` 的逐帧曲线应当变成连续平滑的。

---

## 6. 关闭诊断

最简单的做法：直接关掉对应环境变量。

```powershell
Remove-Item Env:CMT_ANIM_FLOW_DEBUG -ErrorAction SilentlyContinue
Remove-Item Env:CMT_ANIM_FLOW_BONE  -ErrorAction SilentlyContinue
```

代码本身保留诊断 hook，下次需要时再设环境变量启用即可。
