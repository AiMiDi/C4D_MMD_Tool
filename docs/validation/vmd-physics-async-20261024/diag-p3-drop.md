# P3 异步物理：452 个刚体冻结的成因定位（t52）

> 结论一句话：**四选一命中「身份映射失败」，不是「结果槽对不上」、不是「没走到 flush」、也不是「写回不生效」。**
> 根因是 `CollectStandaloneRigidIdentities()` 用 `GetInt32(RIGID_INDEX)` 读取一个**字符串**参数，恒得 0 →
> 479 条身份全部重复 → `MapRigidSnapshotToMain()` fail-closed → `ApplyStandaloneAsyncRigidWorld()` 每帧整帧拒绝 →
> 450 dynamic + 2 dynamicAndBoneMerge 共 452 个刚体从不写回主世界，剩下的 27 个 kinematic 仍随骨骼层级动。
> 这与 t49 的现场指纹（452 个位移恒 0、27 个有位移、任何 lag 都不重合）逐条吻合。

## 0. 判据与取值口径

- 诊断只做**单次 launch 短窗口**：建场景 → `set-mode anim` → `physics on` → 逐帧 `SetTime + ExecutePasses` 21 帧 → `physics off`（触发 Reset）→ 停宿主。
- 观测手段：在**隔离副本** `S:\tmp\cmt_vmd_profile_20261019\p3diag` 的 `source/module/tools/object/mmd_model_runtime.cpp` 里加 18 处 `CmtAsyncDiag(tag, a, b, c, d)`，写 `CMT_ASYNC_DIAG_LOG` 指定文件，格式 `DIAG <tag> <a> <b> <c> <d>`。**产品树零写入**。
- 事件语义（与源码一一对应）：
  - `apply_rigid_enter a=manager存在 b=主世界刚体数 c=main_rigid_identity_.size() d=快照刚体数`
  - `apply_rigid_map_fail a=快照数 b=映射结果数 c=刚体数 d=async_rigid_identity_mismatch_`
  - `apply_rigid_done a=快照数 b=写入数 c=mismatch d=0`
  - `step a=async_submitted_frame_ b=async_applied_frame_ c=consumed d=result.frame`
  - `stats_final` = submitted/consumed/submit_skipped/worker_steps；`stats_final2` = produced/result_covered/applied_frame/submitted_frame；`stats_final3` = identity_mismatch/blocked_result_pending/cancelled/stale_dropped。

## 1. 构建现场（隔离，不改产品树）

| 项 | 值 |
|---|---|
| worktree | `S:\tmp\cmt_vmd_profile_20261019\p3diag`（P3 patch 后第二次独立副本，baseline HEAD 同产品树） |
| 构建目录 | `S:\tmp\cmt_vmd_profile_20261019\p3diag-build` |
| configure | `cmake -S ...\p3diag\sdk_2027 -B ...\p3diag-build -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF` |
| build | `cmake --build ... --config Release --target mmdtool`（rc=0） |
| 工件（含埋点，未修复） | 3,819,008 B `395ECB0603C999C2D1E9C12FB1B8B111291F2C9CE48049EDA03DE3F0E5398DDA` |
| 工件（+身份值打印） | 3,819,008 B `21DC34B03B1E4AA821675DCF360C89AD3E798961B3702C5C5068431031A7B8C7` |
| 工件（+身份读取修复） | 3,819,008 B `C41A096148C09F746DBD3C2FEE17A37BDADCEA05BE28B0A587DF8095D97C149F` |
| profiling 标记 | 三个工件均无 `CMT_RUNTIME_PROFILING=1` |
| 产品树 | `git status --short --ignore-submodules -- source` 仅既存未跟踪 `?? source/utils/pmx_entity_apply_regression.hpp`，tracked 改动 0 |

构建坑（记录，避免复现踩）：worktree 里 `sdk_2027\plugins\mmdtool\source` 是 junction，`robocopy /MIR` 解引用成真副本，
所以改 `p3diag\source\...` 不会被编译；必须同步到 `p3diag\sdk_2027\plugins\mmdtool\source\...` 并 **touch mtime**，
否则 `Copy-Item` 保留旧时间戳会让 MSBuild 判定 up-to-date（实测第一次产物完全不含 DIAG 字符串）。

## 2. 采样运行（每轮单 launch、宿主 pid/ticks 不同）

| run | 宿主 pid / ticks | 加载工件 | 关键事件计数 |
|---|---|---|---|
| run4 | 15352 / 639285356340593790 | 395ECB06…（未修） | step 21、apply_result_enter 20、apply_result_done 20、apply_rigid_enter 20、**apply_rigid_map_fail 20**、apply_rigid_done 0 |
| run5 | 75512 / 639285358204197015 | 21DC34B0…（+身份打印） | 同上，并新增 `identities` 7 行 |
| run6 | 19204 / 639285359655397170 | C41A0961…（+修复） | step 21、apply_result_enter 20、apply_result_done 20、apply_rigid_enter 20、**apply_rigid_done 20**、apply_rigid_map_fail 0 |

每轮都由 `launch-host.ps1` 写入 `host-identity.json`，宿主侧 `modules.mmdtool_loaded.sha256` 与本地工件 sha 一致（脚本打印 `IDENTITY … module=<sha>`），因此「跑的是哪一版」是可核对的。

## 3. 决定性证据①：身份值全是 0

```
DIAG identities 479 0 0 0     # run5（未修）：a=身份条目数, b/c/d=前三条身份
DIAG identities 479 0 1 2     # run6（修复后）：第一条 0，第二/三条 1、2
```

`CollectStandaloneRigidIdentities()` 读的是 `bc->GetInt32(RIGID_INDEX)`。而 `RIGID_INDEX` 在创建刚体对象时是这样写的：

```cpp
// source/module/tools/object/mmd_rigid_manager.cpp:449
rigid_object->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)),
    String::IntToString(static_cast<Int32>(rigid_index)), DESCFLAGS_SET::NONE);
```

即**字符串**参数。`GetInt32` 对字符串参数返回 0 → 479 条身份全为 0。

## 4. 决定性证据②：映射失败 → 整帧拒绝

```cpp
// mmd_model_runtime.cpp:1099-1120（P3 原样）
if (rigid_world.size() != main_rigid_identity_.size() || rigid_world.size() != rigid_bodies->size()) { … return false; }
if (!cmt::physics::MapRigidSnapshotToMain(async_rigid_identity_, main_rigid_identity_, rigid_bodies->size(), main_indices)
    || main_indices.size() != rigid_world.size()) { ++async_rigid_identity_mismatch_; … return false; }
```

`MapRigidSnapshotToMain()`（`cmt_physics_async.cpp:27-61`）先建 `identity → index` 表，**遇到重复身份立即 return false**。
身份全 0 ⇒ 第一次 `emplace` 成功、第二次就重复 ⇒ 每帧 false。日志与之严格对齐：

```
DIAG apply_rigid_enter   1 479 479 479
DIAG apply_rigid_map_fail 479 0 479 1     # b=0：没有任何映射结果；d=mismatch 计数每帧 +1
DIAG apply_result_done    1 1 0 479
```

数量检查（479/479/479）全部通过，所以不是「结果槽数量不对」，而是**身份表内容退化成同一个值**。

## 5. 决定性证据③：管线本身是健康的（排除「结果槽对不上」）

`step` 轨迹（run6，21 帧）：

```
DIAG step 0 0 0 0
DIAG step 1 1 1 1
DIAG step 2 2 1 2
…
DIAG step 19 19 1 19
DIAG step 20 20 1 20
```

`a=submitted`、`b=applied` 每帧同步 +1，`c=consumed=1`，`d=result.frame` 与本帧号一致 ⇒ 提交/产出/消费全通，
**没有积压、没有丢步、没有「结果槽对不上」**。因此 452 冻结只能发生在「消费之后、写回主世界」这一步。

## 6. flush 证据：本窗口 0 行，且结构上不可能解释逐帧丢失

- run4/5/6 的 `flush_reason` 分布均为 **0 行**（`{"flush_enter":0, "reason_*":0}`）。
- 原因不是「flush 缺失」，而是 flush 只在**交互边界**被调用：`mmd_control_workflow.cpp:885/908/935`、
  `motion_sizing_dialog.cpp:545`、`sizing_session.cpp:628`、`mmd_automation.cpp:1507`、`mmd_model_manager.cpp:4430`；
  纯播放窗口（只有 SetTime+ExecutePasses）不会经过它们。
- 而刚体写回不依赖 flush：`ApplyStandaloneAsyncRigidWorld` 在**每帧**的 `StepStandaloneAsyncPhysics` 消费路径里
  被调用（日志 `apply_rigid_enter` 20 次 = 20 个消费帧），所以「没走到 flush」不能解释逐帧冻结。
- 触发方式（供后续补测）：模式来回切换（edit↔anim）、seek、导出、sizing 会话、自动化读路径。

## 7. stats 计数（shutdown 时快照）

`stats_final`/`2`/`3` 每轮各 6 组，对应 5 次 Reset（新建场景/import/import-motion/set-mode/physics on）+ 1 次
`physics off`。代表性的末组（run4，未修）：

```
DIAG stats_final  0 0 0 0
DIAG stats_final2 0 0 0 0
DIAG stats_final3 0 0 5 0        # a=mismatch 0（该实例未到消费帧）、c=cancelled 5
```

说明：`Counters` 是每个 pipeline 实例自己的；每次 Reset 都会 `Start…`/`Shutdown…` 一对，因此计数在实例间不累积。
`async_rigid_identity_mismatch_` 是对象成员（跨实例累积），其真机值即 `apply_rigid_map_fail` 的 `d` 字段：**每消费帧 +1**（run4/5 最终 20）。

## 8. 四个候选（captain 的四选一）逐条判定

| 候选 | 判定 | 证据 |
|---|---|---|
| ① 结果槽对不上（stale/未产出） | **排除** | `step` 里 submitted==applied 每帧、consumed=1；`apply_result_enter/done` 各 20 |
| ② 身份映射失败 | **命中** | `identities 479 0 0 0`；`apply_rigid_map_fail` 20/20；`apply_rigid_done` 0 |
| ③ 没走到 flush | **排除（对本症状）** | flush 仅交互边界调用（7 处），播放窗口 0 行属预期；写回不经过 flush |
| ④ 写回不生效（映射成功但没写） | **排除** | 修复身份读取后 `apply_rigid_done 20`（每帧写 479 个），mismatch 0 |

## 9. 修复候选（已在不入库的隔离副本验证，未提交）

```cpp
// source/module/tools/object/mmd_model_runtime.cpp — CollectStandaloneRigidIdentities()
// 旧：entries.emplace_back(bc->GetInt32(RIGID_INDEX), bc->GetInt32(RIGID_INDEX));
const GeData* const data = bc->GetDataPointer(RIGID_INDEX);
Int32 rigid_index = -1;
if (data && data->GetType() == DA_STRING) {
    const String value = data->GetString();
    rigid_index = value.IsEmpty() ? -1 : value.ToInt32(nullptr);
} else if (data && data->GetType() == DA_LONG) {
    rigid_index = data->GetInt32();
}
if (rigid_index < 0) continue;
entries.emplace_back(rigid_index, rigid_index);
```

- 这也正是仓库既有写法：`mmd_rigid_manager.cpp:96-111` 的 `ReadObjectStoredIndex()`（先 `DA_LONG` 再 `DA_STRING` + `ToInt32`）。
  改动量：**1 个函数内 ~10 行**，无接口变化；工作量约半小时（含单测/构建）。
- 验证结果（run6）：`identities 479 0 1 2`、`apply_rigid_done 479 479 0 0`×20、`apply_rigid_map_fail` 0 行。
- 影响面复核：`async_rigid_identity_` 与 `main_rigid_identity_` 由同一函数产生（`mmd_model_runtime.cpp:914-915` 复制），
  修复后两者仍是同源一致表，`MapRigidSnapshotToMain` 的「重复身份即拒绝」语义保持不变（真正的 fail-closed 能力没有被削弱）。

## 10. 未覆盖项（如实声明）

1. 本报告只做**单 launch 21 帧短窗口**诊断，未重跑 t49 的 5 轮 A/B/A 计时；「修复后帧收益是否仍为 −16 ms」未测。
2. **flush reason 分布未取到实机样本**（本窗口 0 行）；它不影响本结论（写回不经过 flush），但「长交互序列下的 flush 行为」仍未验证。
3. 修复只在 `S:\tmp` 的隔离副本验证，**未进产品树、未提 patch、未做候选构建**（按 t52 契约只读产品树）。
4. `stats_*` 计数分散在 6 个 pipeline 实例上，未做跨实例汇总；本次判据用的是每帧 `step`/`apply_*` 事件而非计数器。
5. 修复后未做「async(N) vs sync(N−lag) 逐位比较」；那属于 t49/t53 的语义回归范围。
6. 期间一次采样（run7）在建场景阶段卡住 13 分钟后宿主被强杀，该轮判作废；本报告全部结论只用 run4/5/6。

## 11. 复现

```powershell
# 构建（隔离副本，产品树只读）
cmake -S S:\tmp\cmt_vmd_profile_20261019\p3diag\sdk_2027 -B S:\tmp\cmt_vmd_profile_20261019\p3diag-build `
      -G "Visual Studio 18 2026" -A x64 -T v143 -DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF
cmake --build S:\tmp\cmt_vmd_profile_20261019\p3diag-build --config Release --target mmdtool

# 单 launch 采样（约 25 s + 宿主退出等待）
pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\diag-sample-p3.ps1 -Execute `
     -OutRoot S:\tmp\cmt_vmd_profile_20261019\p3diag-run6

# 读证据
Get-Content S:\tmp\cmt_vmd_profile_20261019\p3diag-run6\async-diag.log |
    Group-Object { ($_ -split ' ')[1] } | Sort-Object Count -Descending
```

原始日志（不入库）：`S:\tmp\cmt_vmd_profile_20261019\p3diag-run{4,5,6}\async-diag.log`、`summary.json`、
`p3diag-sample{4,5,6}.log`、`p3diag-build{,2,3}.log`。
