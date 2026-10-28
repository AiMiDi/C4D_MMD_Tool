# stale-epoch-result-rejected 偶发失败：静态判定与复现方案（t66 第一阶段）

> 状态：**第一阶段（只读静态分析）**。本文件不含任何编译/运行证据——真机 A/B/A 计时期间不允许跑 verify 或夹具，
> 第二阶段（复现）必须等队长放行后按 §6 执行。全程未改 `source/`、未改 `candidate-async-p4/` 任何文件。

## 1. 现象

t65 复审第一次跑 `verify.ps1` 得到：

```
FAIL stale-epoch-result-rejected :: 拒绝旧结果之后管线必须仍能接受并生产新一代世界的帧
RESULT cases=15 assertions=36 failures=1
```

原样重跑 exit 0。失败点在夹具断言 `eqtest/p4-equivalence.cpp:741`：

```cpp
Check(accepted_again && produced_again, "stale-epoch-result-rejected",
    "拒绝旧结果之后管线必须仍能接受并生产新一代世界的帧");
```

同一案例里另外 6 条断言（`started`、旧帧真实产出并消费、新帧真实产出未消费、旧 epoch 被拒、
`stale_dropped` 恰好 +1、新 epoch 下一帧可消费、epoch 递增）在失败那次都通过了（`failures=1`），
所以「拒绝」本身是对的，出问题的是**拒绝之后怎么判定「新一代确实又产出了一帧」**。

## 2. 三类成因的判定

### 2.1 判定结论

| 类别 | 判定 | 置信度 |
| --- | --- | --- |
| (a) 夹具假设问题 | **最可能（主因）** | 高（代码路径可完全解释） |
| (b) 夹具依赖调度顺序 | **次要（放大器）** | 中（只能解释「偶发」的触发条件，不能单独解释失败机制） |
| (c) 产品侧真实竞态 | **不是本次失败的原因**，但存在一处**潜在**无界等待缺陷（见 §5） | 中高 |

一句话：失败机制是 **(a)**——夹具用「`Submit` 之后才抓的 `produced` 基线」去判断「新帧是否产出」，
而 worker 完全可能在 `Submit` 返回与抓基线之间就把这一帧生产完；于是基线里已经含了本帧，
`produced > baseline` 永远不成立，400 ms 后判失败。机器越快，这个窗口越容易命中。

### 2.2 (a) 的依据：基线与提交的顺序

夹具 `eqtest/p4-equivalence.cpp:713-728`：

```cpp
bool accepted_again = false;
PhysicsAsyncPipeline::Counters before_again = pipeline.GetCounters();   // :714 基线（此时还未提交）
bool produced_again = false;
for (int attempt = 0; attempt < 200 && !produced_again; ++attempt)
{
    if (!accepted_again)
    {
        accepted_again = pipeline.Submit(8, epoch_new, {}, { -1 });     // :720 提交
        if (accepted_again)
            before_again = pipeline.GetCounters();                      // :722 ← 重新抓基线（问题所在）
    }
    if (accepted_again && pipeline.GetCounters().produced > before_again.produced)  // :724
        produced_again = true;
    else
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
}
```

worker 侧的生产是异步的，且计数与提交在同一把锁内推进（`new-files/cmt_physics_async.cpp:296-305`）：

```cpp
result_ = std::move(produced);
has_result_ = true;      // :302
++produced_;             // :303
in_flight_ = false;      // :304
```

`Submit`（`cmt_physics_async.cpp:101-159`）在持锁期间完成 `has_job_/in_flight_` 置位与 `wake_.notify_one()`，
返回后主线程继续执行到 `:722` 需要几条指令。若 worker 在这几微秒内被唤醒并跑完 `step_`（本案例的
`step_` 是空 lambda，`eqtest/p4-equivalence.cpp:663`），`++produced_` 就发生在 `:722` **之前**——
基线被"污染"，此后 `produced > baseline` 需要再有一帧才会成立，而夹具不会再提交第二帧，只能耗尽
200 次 × 2 ms = 400 ms 的预算后失败。

同一形状的隐患也存在于前面那次等待（`:696` 在 `:693` 的 `Submit(7, …)` 之后抓基线），只是那次
后面还有 `stale` 消费动作，命中窗口更小；一旦命中，会先在 `:736`（`accepted_new && produced_new`）失败。

### 2.3 (b) 的依据：400 ms 预算与机器争用

失败判定依赖「200 次 × 2 ms」的时间预算（`:716`）。t65 的第一次 verify 在同一进程里刚跑完
7 个 Release TU 编译（`verify.ps1` stage 14），cl.exe 与 Windows Defender 都会抢占 CPU；
worker 线程被调度延迟数百毫秒并非不可能。但 (b) 只能解释「为什么偶发」，不能解释
「为什么基线已含本帧」这一类确定性错误——两者叠加时最先触发的是 (a)。

### 2.4 为什么判断不是 (c)：产品侧状态清理路径是自洽的

逐条核对跨 epoch 路径的清理责任：

- **拒绝旧结果**：`TryConsume` 在 epoch 不匹配时只做 `has_result_ = false; ++stale_dropped_;`
  （`cmt_physics_async.cpp:171-175`），**不碰** `has_job_`、`in_flight_`、`cancel_`、`running_`。
  因此「拒绝」不会让新一代的提交或生产卡住。
- **重建**：`CancelAndJoin`（`:201-232`）在锁内清 `has_job_/in_flight_/has_result_` 并置
  `cancel_=true / running_=false`（`:213`），`join()` 之后**再次加锁**把三态清干净（`:226-231`）；
  `Start`（`:81-99`）先 `if (running_) return true;`，再 `join` 残留线程，然后
  `cancel_=false / running_=true`（`:94-96`）并起新线程。⇒ 重启后 `cancel_` 为 false，
  worker 不会「一启动就退出」，也不会继承上一代的 in-flight 状态。
- **生产**：worker 发布路径在没有取消的情况下一定会写 `has_result_=true; ++produced_; in_flight_=false;`
  并 `idle_.notify_all()`（`:296-307`），不存在「产出了但不计数」的分支；`result_covered_`（`:299`）
  只在确实发生覆盖时增长，与本失败无关。

也就是说：本次失败时 `stale_dropped` 恰好 +1（`:739` 通过）证明拒绝分支执行了；若真是 (c)，
最可能表现为 `stale_dropped` 不增长，或 `submit_blocked_result_pending` 暴涨（槽被错误保留）——
这两种都会让**别的**断言先失败，而实测只有 `:741` 失败。

**若将来要怀疑 (c)，最可疑的三个状态位/清理路径**（当前均未命中，但要写进宿主验证清单）：

1. `has_result_` 与 `in_flight_` 的分离：worker 在 `:302-304` 先置 `has_result_` 再清 `in_flight_`，
   若将来有人在两者之间插入早退（例如「结果槽满则丢弃」），会出现「有结果、仍在飞」的半状态。
2. `CancelAndJoin` 的两段加锁（`:203-224` 与 `:226-231`）：第一段之后 `join()` 期间若有第三方线程调用
   `Submit`，会看到 `running_=false` 直接返回 false——目前单线程主流程不会发生。
3. `Start` 的「已运行则直接返回 true」（`:83`）：若在 `running_=true` 但 worker 尚未进入 `wake_.wait`
   的瞬间再做一次「重建」，会得到「没重建」的假象；当前 `RebuildStandaloneAsyncShadow` 走
   `Shutdown`（`CancelAndJoin`）→ `Start`，等价于先置 `running_=false`，暂时安全。

## 3. 对真机 seek 的影响（为什么值得现在写清）

真机 seek 走 `RebuildStandaloneAsyncShadow` → `CancelAndJoin` + `Start`（epoch 由
`PhysicsEpochCounter::Next()` 推进）。上述 (a) 是**夹具的判定方式**问题，不是产品行为：
产品侧「重建后首帧产不出来」需要 `running_` 或 `cancel_` 残留才会发生，而这两处在
`CancelAndJoin`/`Start` 里是对称清理的。因此**本次偶发不构成「seek 后首帧丢失」的证据**；
真机上若观察到 lag 跳变，应优先看 `async_log_` 的 `submitted/produced/consumed/skipped/blocked`
区间计数，而不是先怀疑等价性。

## 4. 修复建议（仅建议，本轮不改候选）

- 夹具层（首选，零产品改动）：把基线移到 `Submit` **之前**（`:714` 已经是这个位置，`:722` 的覆盖是多余的），
  即删除 `:722`，或改为「提交前抓基线 + 提交后只比较 `produced` 增长」。
- 更稳的形态：给管线加只读的 `bool HasPendingResult() const` / `WaitForProduced(target, timeout)`，
  用「结果槽是否就绪」而不是「计数增量」判定；这类 API 已有先例（t48 的 `WaitForJobTaken` 走的是同一思路，
  但 P4 候选头基于 t61，未包含它）。
- 产品层（与本失败无关，但建议记账）：`Submit` 的背压等待谓词只含 `!has_job_ && !in_flight_`
  （`cmt_physics_async.cpp:125`），**不含** `cancel_ || !running_`。今天主线程串行调用不可能触发，
  但一旦将来出现「另一线程触发重建」，这里会无界挂死。若要提前上护栏，谓词改成
  `!has_job_ && !in_flight_ || cancel_ || !running_` 并返回 false。

## 5. 结论（第一阶段）

- 定论方向：**(a) 夹具假设问题（主因）+ (b) 调度/CPU 争用（放大器）**；**不是**产品侧竞态。
- 依据：失败点前后 6 条断言全过、`stale_dropped` 恰好 +1；跨 epoch 清理路径（TryConsume/CancelAndJoin/Start）
  逐条核对自洽；基线在 `Submit` 之后重新抓取（`eqtest/p4-equivalence.cpp:722`）与 worker 的
  `++produced_`（`cmt_physics_async.cpp:303`）之间存在确定的丢失窗口。
- 需要修产品代码吗：**不需要**（就本失败而言）。建议只改夹具判定方式；`Submit` 的无界等待谓词作为
  潜在缺陷单独记账，等引入真正的并发重建时再修。

## 6. 可复现方案（第二阶段，**等队长放行、真机 A/B/A 计时结束后**才执行）

约束：执行前确认 ds-impl2 的计时已结束；执行期间不要同时跑编译/宿主；不改
`candidate-async-p4/`（用现成二进制；如需更细的观测，把探针放在本目录 `docs/validation/...` 下）。

| 项 | 方案 |
| --- | --- |
| 轮数 | 先 50 轮 `verify.ps1`（每轮全新进程），再 200 轮只跑夹具 exe（`eqtest/build/p4-equivalence-v2.exe`）——后者更快，能放大 (a) 的命中率 |
| 记录项 | 每轮失败时 dump：`submitted / produced / consumed / stale_dropped / submit_blocked_result_pending / submit_skipped / in_flight_dropped / worker_steps`、`accepted_again`、`produced_again`、`elapsed_ms`；连同 `PID`、`StartTime`、机器负载（`\Processor(_Total)\% Processor Time` 采样） |
| 判定 | 若失败现场满足「`accepted_again=1`、`produced` 在提交后 0 增长、`blocked/skipped` 均为 0」→ 命中 (a)；若 `produced` 有增长但超过预算才发生 → (b)；若 `stale_dropped` 未 +1 或 `blocked` 暴涨 → 转 (c) 并立刻停下报我 |
| 加压复现（可选） | 后台跑 4 个忙线程（不启宿主）制造调度抖动，观察失败率是否升高——用于把 (b) 的贡献量化 |
| 输出 | 追加到本文件「第二阶段实测」小节：轮数、失败次数、失败现场表、最终定论 |

> 说明：本文件所有 file:line 均按 2026-10-26 的候选快照（t65 PASS 的那一版）核对；
> 若候选后续变动，行号需重核。

## 7. known-risk 台账（本轮只记录，不改代码）

### KR-001：`Submit` 的背压等待谓词缺少取消/停机条件

| 项 | 内容 |
| --- | --- |
| 位置 | `candidate-async-p4/new-files/cmt_physics_async.cpp:123-130`（`Submit` 中 `idle_.wait(lock, [this]{ return !has_job_ && !in_flight_; })`，谓词见 `:125`） |
| 现状 | 谓词只含 `!has_job_ && !in_flight_`；不含 `cancel_ || !running_`。`CancelAndJoin` 只 `notify_all` 了 `wake_`/`idle_`/`released_`/`hold_entered_`，**不改变**这两个谓词变量的组合结果 |
| 触发条件 | 必须有第二个线程与主线程并发：①主线程阻塞在 `Submit` 的 `idle_.wait` 上（in-flight 未清），②另一线程（未来多模型/线程池调度、或「别的线程触发重建」）调用 `CancelAndJoin`/`Shutdown` → worker 退出、`in_flight_` 永不归零 → 主线程永久阻塞，`Join` 也等不到 |
| 为什么现在不触发 | P4 候选只有主线程调用 `Submit`；重建走 `RebuildStandaloneAsyncShadow()`（`Shutdown` → `Start`）且全在主线程；`in_flight_` 清空与 worker 退出在同一线程模型下必然发生 |
| 修法 | 谓词改为 `return (!has_job_ && !in_flight_) || cancel_ || !running_;`，且 `wait` 返回后若 `cancel_ || !running_` 则直接 `return false`（让调用方走「本帧未提交」分支，不写回）；同时确认 `CancelAndJoin` 已 `notify_all()` 到 `idle_`（当前 `:203-224` 已包含） |
| 为何现在不改 | t65 复审已 PASS、t63 真机工件必须与候选逐字节一致；此改动会改 `new-files/cmt_physics_async.cpp` → patch sha 变化 → 真机工件不可比。属于 **P5（多模型/线程池扩展）的前置条件**，应在 P4 真机结论落地后单独做，并补一条「held submit + 并发 CancelAndJoin」回归（做法参照 t54 的 `held-inflight-cancel-joins-within-timeout`：5 s 限时 + 失败即 detach 泄漏，避免夹具自挂） |

### KR-002：`Start` 的「已运行即返回 true」可能掩盖未重建

| 项 | 内容 |
| --- | --- |
| 位置 | `new-files/cmt_physics_async.cpp:81-99`（`:83` `if (running_) return true;`） |
| 风险 | 若未来存在 `running_==true` 但 world 已换代的调用序列（当前 `RebuildStandaloneAsyncShadow` 先 `Shutdown` 再 `Start`，不会命中），会得到「没重建却返回成功」的假象 |
| 修法 | 让 `Start` 接受调用方传入的 `expected_epoch` 或 world 代号，不匹配则强制先 `CancelAndJoin` |
| 为何现在不改 | 同 KR-001（真机工件冻结）；当前唯一调用路径已保证先停机 |

## 8. 结论：修夹具**不会**改变插件二进制，也不会改变 patch sha

（本节回答「eqtest 是否进插件 TU 列表」以及「修夹具会不会破坏与 t63 工件的可比性」。）

| 检查项 | 结论 | 依据 |
| --- | --- | --- |
| `eqtest/*.cpp` 是否进插件 TU 列表 | **否**。`compile-tu.ps1` 只编译 7 个产物源文件：`work/source/module/tools/object/{mmd_model_runtime,mmd_model_manager,cmt_physics_pipeline,cmt_physics_async}.cpp`、`work/source/utils/mmd_control_workflow.cpp`、`work/source/module/ui/motion_sizing_dialog.cpp`、`work/source/module/tools/sizing/sizing_session.cpp`（`compile-tu.ps1:99-106`），无 `eqtest` 路径 | `compile-tu.ps1:99-106` |
| 夹具如何构建 | 独立进程：`verify.ps1:62-64` 调 `eqtest/build-p4-equivalence.ps1 -Run -Pmx …`，产物是 `eqtest/build/p4-equivalence-v2.exe`（链接 `_build_msvc/cmt_deps_prebuilt/lib` 的 libMMD/Bullet），与插件 DLL/XDl64 无关 | `verify.ps1:62-64`、`eqtest/build-p4-equivalence.ps1` |
| 夹具是否进补丁 | **否**。补丁目标只有 7 个产品源文件（`p2.all_targets()`）＋ 6 个 `new-files`（`cmt_physics_pipeline.{h,cpp}`、`cmt_physics_shadow.h`、`cmt_physics_async.{h,cpp}`、`cmt_physics_epoch.h`），`eqtest/` 不在其中 | `make_patch_p4.py` → `p2.all_targets()` / `p2.NEW_FILES` |
| identity.json 是否记录夹具哈希 | **否**（键只有 `round/base_source/files/new_files/wiring/patch_sha256/patch_bytes/patch_lines_*/patch`），无 fixture 字段 | `identity.json` |
| 故：只改 `eqtest/p4-equivalence.cpp` 的影响 | patch sha **不变**（当前 `c4a35f62c9e9c59899d6318c567b49059f31cbc0541450198fffd21247b2ca4a`）、identity 不变、`mmdtool.xdl64` 不变；只会改 verify 的夹具阶段与报告数字（cases/assertions 可能 +1） | 上述三项 |

> 需要澄清的一点：队长担心的「修夹具会让 patch sha 变化」在本候选里**不成立**——补丁只覆盖产品源与 `new-files`。
> 反过来，若为了「结果槽就绪」判定而给 `cmt_physics_async.h` 加 API（`HasPendingResult()/WaitForProduced()`），
> **那会**改 `new-files` → patch sha 变化 → 真机工件不可比。所以 §9 的首选方案刻意只动夹具。

## 9. 待放行后的夹具修法（定稿，可直接执行；尚未执行）

放行条件：t63 真机 A/B/A 结束且队长明确说「可以动 `candidate-async-p4`」。

### 9.0 执行前自检（不通过就停下问）

```powershell
cd C:\code\C4D_MMD_Tool\.dsh-switchman\vmd-perf-20261024\candidate-async-p4
(Get-FileHash -Algorithm SHA256 candidate-async-p4.patch).Hash.ToLower()
# 必须 = c4a35f62c9e9c59899d6318c567b49059f31cbc0541450198fffd21247b2ca4a
git -C C:\code\C4D_MMD_Tool status --porcelain -- source res sdk_2026 sdk_2027   # 必须为空
```

### 9.1 唯一改动文件：`eqtest/p4-equivalence.cpp`（三处精确编辑）

| # | 位置（当前行号） | 现状 | 改成 |
| --- | --- | --- | --- |
| E1 | `:693-706`（`stale-epoch-result-rejected` 第一段） | `:693` 先 `Submit(7, epoch_new, {}, {-1})`，`:696` 才抓 `before_produced` | 把 `const cmt::physics::PhysicsAsyncPipeline::Counters before_produced = pipeline.GetCounters();` **上移到 `:691` 的 `bool accepted_new = false;` 之前**（即 Submit 之前），删除 `:696` 原行；循环条件 `spin < 400` → `spin < 100`（2 ms/轮 ⇒ 200 ms 预算） |
| E2 | `:713-728`（同案例第二段） | `:714` 抓 `before_again`，`:721-722` 在 Submit 成功后**再次重抓** | 删除 `:721-722` 两行（`if (accepted_again) { before_again = …; }` 整个 if），只保留 `:714` 提交前基线；`:720` 的 `Submit(8, epoch_new, {}, {-1})` 与 `:724` 的判据不变 |
| E3 | `:733-741` 断言区 | 失败时只有固定文案 | 在 `++g_cases;` 前拼一行现场：`snprintf` 到 `static char detail[256]`，内容 `"accepted_new=%d produced_new=%d accepted_again=%d produced_again=%d new_accepted=%d submitted=%llu produced=%llu consumed=%llu stale=%llu"`，数据取 `after_new`（`submitted/produced/consumed/stale_dropped`）与四个 bool；把该字符串作为 `:736` 与后续「拒绝旧结果后仍能出帧」两条 `Check(...)` 的 message 参数（`Check` 的第三参本身就是 `std::string`，无需改签名） |

> 为什么这样修能消除 flake：`:722` 的基线是在 `Submit` **返回之后**才抓的，而 worker 可能在
> `Submit` 解锁到主线程抓基线之间就把本帧算完（`cmt_physics_async.cpp:302-304`：`has_result_ = true; ++produced_; ++consumed_…`），
> 基线于是已经包含本帧 → `produced > baseline` 永不成立 → 耗尽预算。E1/E2 把两边基线都固定到
> `Submit` 之前，就只剩「提交后是否新增一帧」这一件事，与调度速度无关。

### 9.2 执行后自检（三条，全过才算完）

```powershell
# ① 只允许 fixture 一处改动
git -C C:\code\C4D_MMD_Tool status --porcelain -- .dsh-switchman/vmd-perf-20261024/candidate-async-p4
#   期望仅： M .../candidate-async-p4/eqtest/p4-equivalence.cpp   （可能另有 build/ 下的日志，那是生成物）

# ② 重新生成补丁，sha 必须不变（变了=动了产品源或 new-files → 停下报队长）
python -X utf8 make_patch_p4.py
(Get-FileHash -Algorithm SHA256 candidate-async-p4.patch).Hash.ToLower()
#   期望仍为 c4a35f62…；identity.json 的 patch_sha256/patch_bytes 也应不变

# ③ 复核门禁：跑 verify（会编译，必须等 t63 结束）
pwsh -NoProfile -File verify.ps1
#   期望 VERIFY OK … cases ≥13 assertions ≥23 gates ≥63 failures=0，exit 0
```

若 ② 里 sha 变了：立即 `git checkout --` 恢复、保留现场（`git diff` 存到 `build/sha-changed.diff`）并报队长，
不要继续跑 ③。

### 9.3 本次修法**不会**改变的东西（t63 工件可比性的依据）

- `candidate-async-p4.patch` 内容（只覆盖 7 产品源 + 6 `new-files`）→ sha 不变；
- `identity.json`（无 fixture 字段）→ 不变；
- `mmdtool.xdl64` / 真机 `p4b` 工件 → 不变：`verify.ps1` 只做 `cl /c` 到 `candidate-async-p4/build/<name>.obj`
  （`compile-tu.ps1:69-70`）＋把夹具编成独立 exe（`verify.ps1:62-64`），**没有 link、没有 msbuild/cmake、没有触碰
  `_build_msvc\…\plugins\mmdtool\`**；`compile-tu.ps1` 读取 vcxproj 只用于取编译选项（`:28`）。
  ⇒ 修夹具后 **不需要**重跑真机；ds-impl2 已产出的两版工件继续有效。

