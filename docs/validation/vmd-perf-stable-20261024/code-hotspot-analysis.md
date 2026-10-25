# VMD 播放每帧热点：只读代码分析与候选排序（t15）

- 日期：2026-10-24
- 任务：t15（只读代码热点分析），与另一路「宿主 stage 探针实测」（ds-impl2）互为交叉验证
- 场景基准（既有实测，本文件不改写、不复测）：阿芙2.0.pmx（625 骨骼 / 479 刚体 / 748 约束 / 70,222 顶点）+ `Stay Tonight Heaven Lee Ver. 动作.vmd`，30 FPS；物理开中位 34.0 ms/帧，物理关 18.2 ms/帧 → 物理相关约 15.9 ms（47%）；物理关已超 60 FPS 预算（16.7 ms）约 9%
- 方法：只读源码 + 结构推理。**没有**启动宿主、没有构建、没有插桩取数。
- 证据分级：文中凡「待实测」标记处，均为静态代码无法判定真实占比的推断；`假设 ≠ 实证`。

---

## 0. 一句话结论

18.2 ms（物理关）里，插件自身最像「每帧重复劳动」的不是蒙皮写回，而是**控制/变形状态的全场景重复扫描族**（每帧 4 次以上 625 骨遍历，含 `GetParameter` + 矩阵归一化 + 哈希，其中一次还带 `std::sort`）与**每骨每帧 3 次 `ApplyActiveAnimation` + 3 次 `MSG_UPDATE`**；物理 15.9 ms 的主体是 Bullet 求解行数，最大单一杠杆是「748 个关节一律用 `btGeneric6DofSpringConstraint`」与 3 子步。

---

## 1. 每帧执行链（真实调用顺序）

C4D 侧的执行点注册在 `source/module/tools/object/mmd_model_manager.cpp:5136-5144`：

```
list->Add(op, kExternalPosePreparePriority, EXECUTIONFLAGS::EXPRESSION);   // EXPRESSION-500
list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);   // 主通道
list->Add(op, kExternalPoseSolvePriority, EXECUTIONFLAGS::EXPRESSION);     // EXPRESSION+500
```

即**每帧 `MMDModelManagerObject::Execute` 被调用 3 次**（`source/module/tools/object/mmd_model_manager.cpp:2317`）：

| 序 | 通道 | 实际工作 |
|---|---|---|
| 1 | `kExternalPosePreparePriority` | `:2385-2388` → `PrepareExternalBonePoses`（`source/module/tools/object/mmd_model_runtime.cpp:95`）：`EnsurePlaybackExecutionPlan()` + 全骨循环，逐骨扫 tag 找 `kNativeConstraintTagId`（`:104-140`）——**无外部姿态时也不早退** |
| 2 | `EXECUTIONPRIORITY_EXPRESSION` | 主通道，见下 |
| 3 | `kExternalPoseSolvePriority` | `:2334-2335`：`!HasExternalBonePoses()` 时直接 return（正常情况下零成本） |

主通道（`mmd_model_manager.cpp:2392-2473`，`model_mode_ == MODEL_MODE_ANIM`）：

1. `:2405` `mmd_bone_control_util::GetControlStateChecksum(...)`
2. `:2407` `mmd_bone_control_util::HasActiveControlDelta(...)`
3. `:2408` `GetBoneMorphStateChecksum()`
4. `:2411` 门控：`time_changed || control_state_changed || control_delta_active || bone_morph_state_changed || external_pose_refresh_ || physics_timing_changed`
5. `:2435` `bone_manager_data_->EnsurePlaybackExecutionPlan()`
6. `:2436` `RunLayeredBonePass(doc, false, &control_context)` → `source/module/tools/object/mmd_model_runtime.cpp:385`：
   - `:397` 对 `GetPlaybackLayers()` 每个 layer：
     - `:408` `PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics)`（`source/module/tools/object/mmd_bone_manager.cpp:2341`）→ 逐骨 `ApplyActiveAnimation(bone_object, doc, true)`（`:2386`）
     - `:409` `SyncStandaloneBoneAdaptersFromScene(true)`（`mmd_model_runtime.cpp:232`，两遍 625 adapter）
     - `:411` `mmd_control_workflow::SolveLayer(...)`（`source/utils/mmd_control_workflow.cpp:696`）
     - `:413` 若控制求解数 >0 再来一次 `SyncStandaloneBoneAdaptersFromScene(true)`
     - `:414` `SolveStandaloneIKForLayer(layer, after_physics, false)`（`mmd_model_runtime.cpp:281`）
7. `:2444/:2446` `ResetStandalonePhysics()` / `StepStandalonePhysics(1.f / fps_)`（`mmd_model_runtime.cpp:878`）：
   - `:892-893` 遍历 479 刚体 `SyncBonePositionToPhysics(elapsed)`
   - `:897` `physics->Update(elapsed)` → `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164` `m_world->stepSimulation(time, m_maxSubStepCount, 1.0/m_fps)`
   - `:899` `ApplyStandalonePhysicsResults()`（`mmd_model_runtime.cpp:902`）：`:913-914` 479 刚体 `ReflectGlobalTransform`；`:916` 动态骨 adapter 同步；`:920-929` `SetPhysicsOverride`；`:932-938` `ApplyStandaloneBoneAdaptersToScene` + `MarkMeshHierarchyDirty(..., false)`
8. `:2463` `RunLayeredBonePass(doc, true, &control_context)`（after-physics 通道，同上但只跑 `PMX_BONE_PHYSICS_AFTER_DEFORM == true` 的骨）
9. `:2465` `mmd_bone_control_util::SyncControlsToCurrentPose(...)`
10. `:2466` **第二次** `GetControlStateChecksum(...)`

与上面并行的还有两个每帧执行点：

- 每个骨标签 `EXECUTIONRESULT MMDBoneTag::Execute(...)`（`source/module/tools/tag/mmd_bone.cpp:3634`）：`UpdateHierarchyTopologyCache` → `BeginPrephysicsFrame` → `SyncSplineFromCurrentParametersIfNeeded` → `GetModelManager()` → `ApplyActiveAnimation(op, doc, false)`（`:3654`）
- 骨骼管理器 `EXECUTIONRESULT MMDBoneManagerObject::Execute(...)`（`source/module/tools/object/mmd_bone_manager.cpp:2206`）：`EnsurePlaybackExecutionPlan()`（`:2232`）→ 全骨循环（只有带 runtime override 的骨会落到 `ApplyActiveAnimation`，`:2282`）→ 若有应用过动画的骨，再 `MarkMeshHierarchyDirty(...)`（`:2299-2303`，`weights_changed` 默认 `true`）

蒙皮本身由 C4D 原生 `Oskin` + 权重 tag 完成（插件在导入期插入，`source/module/tools/object/mmd_mesh_manager.cpp:651`、`:1189`），插件每帧只负责「让 mesh 层级失效」：`MarkMeshHierarchyDirty`（`source/module/tools/object/mmd_model_runtime.cpp:67-91`）= 每个部件 `SetDirty(MATRIX|DATA|CACHE)` + `MSG_UPDATE`，并在 `weights_changed` 时对权重 tag 追加 `MSG_UPDATE`。

---

## 2. 候选清单（按 收益/风险 排序）

### C1（最高杠杆 · 非物理路径）每帧 4 次「控制状态全场景扫描」

**位置**
- `source/module/tools/object/mmd_model_manager.cpp:2405`、`:2407`、`:2466`（每帧无条件执行，且在 `time_changed` 判定之前）
- `source/utils/mmd_bone_control_util.cpp:1420-1449` `GetControlStateChecksum`
- `source/utils/mmd_bone_control_util.cpp:1386-1404` `HasActiveControlDelta`
- `source/utils/mmd_bone_control_util.cpp:1451+` `SyncControlsToCurrentPose`
- 逐骨辅助：`source/utils/mmd_bone_control_util.cpp` 内 `ResolveLinkedObjectParameter`（`owner->GetParameter(CreateDescID(DescLevel(parameter_id)), ...)`）与 `IsBoneControlEligible`

**关键代码行原文**
```cpp
// mmd_bone_control_util.cpp:1424-1428
std::vector<Int32> sorted_indices;
sorted_indices.reserve(bone_manager.bone_list_.GetCount());
for (const auto& entry : bone_manager.bone_list_)
    sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
std::sort(sorted_indices.begin(), sorted_indices.end());
// :1436-1441
BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
if (!control) continue;
hash = MixHash(hash, static_cast<UInt32>(bone_index));
hash = HashMatrix(hash, NormalizeMatrixBasis(control->GetRelMl()));
```

**为什么怀疑它贵（结构论证）**
- 每次调用：`std::vector` 堆分配 + 625 次 `FindBone`（HashMap）+ `std::sort`（≈625·log₂625 ≈ 5.7k 次比较）+ 逐骨 `GetParameter`（走描述系统，且每次 `CreateDescID(DescLevel(...))` 现造 `DescID`）+ `GetRelMl()` + `NormalizeMatrixBasis` + 16 个 float 的哈希更新。
- 帧内次数：`GetControlStateChecksum` ×2、`HasActiveControlDelta` ×1、`SyncControlsToCurrentPose` ×1 = **≥4 次全骨扫描**，与物理开关无关（物理关的 18.2 ms 全额承受）。
- 其中 `HasActiveControlDelta` 与 `SyncControlsToCurrentPose` 还各自再做一次「收集 + 排序 / 建立 625 条 `SyncControlEntry`」，属于同一份可缓存数据的重复构造。
- 注意 `:2405/:2407/:2408` 位于门控 `:2411` **之外**：即使本帧 `time_changed == false`（暂停、或同一帧被重复求值），这三份全量扫描照付。

**预期收益**：1.0–3.5 ms/帧（推理：若「合格骨」约 300–500 个，单次 `GetParameter` 0.3–1 µs 计，单次扫描 0.25–0.7 ms；4 次 → 1.0–2.8 ms，另加两次 `std::sort` 与 vector 分配）。**待实测**：需 stage `control.checksum` / `control.delta` / `control.sync` 的 self 时间确认。

**风险**：中。注释 `mmd_bone_control_util.cpp` 与 `mmd_model_manager.cpp:2401-2402` 明确说明「脚本可绕过消息直接写 `BaseContainer`，所以必须每帧哈希」。因此不能简单删掉校验和，只能：①把 `time_changed` 判定提前，未变时间时走轻量路径（如 `doc` 脏计数/采样）；②对控制链接与 `GetRelMl` 结果做「每帧一次」缓存（同一帧内 4 次调用共用一份快照）；③保留低频（每 N 帧或 doc 变化时）全量校验作兜底。

**验证方式**
- 正确性：改前后逐帧对比骨 `GetRelMl` 与 `GetMg`（位模式相等）；跑「同帧脚本直改 `BaseContainer`」「拖动控制对象」「切 IK/FK」三个用例，断言帧首帧行为不变。
- 提速：stage `control.checksum/delta/sync` self 时间 + 整帧墙钟；同时看 `calls` 计数是否从 4×625 降到 1×625。

**是否碰产品源码**：是（`mmd_bone_control_util.cpp`、`mmd_model_manager.cpp`）。**规模**：约 80–150 行。

---

### C2（非物理路径）每骨每帧 3 次 `ApplyActiveAnimation` + 3 次 `MSG_UPDATE`

**位置**
- `source/module/tools/tag/mmd_bone.cpp:3634-3665`（tag 自身 Execute → `:3654 ApplyActiveAnimation(op, doc, false)`）
- `source/module/tools/object/mmd_bone_manager.cpp:2341-2390`（每 layer 逐骨 `:2386 ApplyActiveAnimation(bone_object, doc, true)`）
- 收尾写入：`source/module/tools/tag/mmd_bone.cpp:3360-3363` → `MarkBoneTransformDirty`（`mmd_bone.cpp:139-145`）

**关键代码行原文**
```cpp
// mmd_bone.cpp:3360-3363
ApplyPlaybackRelativeMatrix(op, BuildAnimationMatrix(final_translation, final_rotation));
MarkBoneTransformDirty(op);
if (self_tag) self_tag->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);

// mmd_bone.cpp:139-145
void MarkBoneTransformDirty(BaseObject* object)
{
    if (!object) return;
    object->Touch();
    object->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA);
    object->Message(MSG_UPDATE);
}
```

**为什么怀疑它贵**
- 同一帧同一骨，`ApplyActiveAnimation` 至少被调用 3 次：tag Execute 一次（`apply_to_scene=false`）+ before-physics layer 一次 + after-physics layer 一次（`mmd_bone_manager.cpp:2386`，两个 layer 各自遍历其骨集合）。625 骨 → ≈1.9k 次/帧。
- 每次都以 `MarkBoneTransformDirty` 结尾：`Touch()` + `SetDirty` + `Message(MSG_UPDATE)`；`apply_to_scene` 参数并未屏蔽最后的 `ApplyPlaybackRelativeMatrix`/`MSG_UPDATE`，所以**每帧 625×3 次 `MSG_UPDATE` 打到骨对象上**。`MSG_UPDATE` 会进入 C4D 的缓存/依赖失效路径（`mmd_model_runtime.cpp:79-85` 的注释已经承认「每个权重 tag 的 `MSG_UPDATE` 会在关节只移动时也重建数据」是浪费，并据此加了 `weights_changed` 开关——骨对象这一侧还没有同等收敛）。
- 每次调用还完整重算：关键帧插值、`GetParameter` 读旋转/位移开关、`GetControlDeltaInBoneSpace`（Eigen 矩阵）、`bone_morph_data_arr_` 逐 morph `GetParameter`（`mmd_bone.cpp:3441-3460`）。

**预期收益**：1.5–5.0 ms/帧（推理：1875 次 `MSG_UPDATE` 与 1875 次完整姿态重算；若单次 0.5–2 µs 级，落在 1–4 ms）。**待实测**：`bone.animation` / `bone.tag.execute` stage 时间与 `calls` 计数。

**风险**：中高。`mmd_bone_manager.cpp:2378-2383` 的注释明确写了「只准备 after-physics 子集会让多数 adapter 落后一帧、产生抖动」，所以不能退回旧行为。可行方向：①同帧同 (doc time, 控制状态, morph 状态) 的结果缓存，重复调用直接返回；②把 `MarkBoneTransformDirty` 收敛为「每骨每帧一次」，并在 model manager 收尾统一发一次层级更新；③`apply_to_scene=false` 时只更新 `evaluated_*` 缓存字段，不写场景、不发 `MSG_UPDATE`。

**验证方式**：改前后对 30 帧×抽样骨骼比较 `GetRelMl`/`GetMg` 位模式；对物理开启的帧比较物理回放一致性；计时看 `bone.animation` self 与整帧墙钟。

**是否碰产品源码**：是（`mmd_bone.cpp`、`mmd_bone_manager.cpp`、可能需要 `mmd_model_manager.cpp` 统一收尾）。**规模**：100–200 行。

---

### C3（非物理路径）关键帧定位每帧每骨两次线性扫描

**位置**
- `source/module/tools/tag/mmd_bone.cpp:3382` → `HasStaticPoseAnimationSegmentAtTime`（`mmd_bone.cpp:1270-1297`）
- `source/module/tools/tag/mmd_bone.cpp:3401-3403`（插值区间定位）

**关键代码行原文**
```cpp
// mmd_bone.cpp:1290-1292
Int upper_index = 1;
while (upper_index < slot->keyframes.GetCount() && slot->keyframes[upper_index].frame <= current_frame)
    ++upper_index;

// mmd_bone.cpp:3401-3403
Int upper_index = 1;
while (upper_index < slot->keyframes.GetCount() && slot->keyframes[upper_index].frame <= current_frame)
    ++upper_index;
```

**为什么怀疑它贵**
- 两次扫描都从 `index = 1` 重新开始，复杂度 O(K)，K = 该骨关键帧数量；VMD 30 FPS 下 K 常为数百，长动作可上千。
- 乘以 C2 的调用次数：625 骨 × 3 次 × 2 次扫描 × (K/2 平均比较)。K=500 时约 1.9M 次比较/帧，且每次比较伴随 `maxon::BaseArray` 元素访问与 `frame` 字段读取（步长较大，缓存不友好）。
- 代码里没有「上一帧索引」游标，播放时时间单调递增这一强先验完全没被利用。

**预期收益**：0.5–2.5 ms/帧（推理：1.9M 次简单比较在 ~1 ns/次量级 → 1.9 ms 上界；实际因内存步长可能更高）。**待实测**：把 `HasStaticPoseAnimationSegmentAtTime` 与插值定位分别计时。

**风险**：低。语义可完全保持：①每个骨保存 `last_keyframe_cursor`，命中「新帧 ≥ 旧帧」时从游标继续；②未命中则二分（`std::upper_bound`，`keyframes[i].frame` 已升序）；③`static_pose` 段判定可以按 slot 预计算成「静态段区间表」，避免每帧扫描。

**验证方式**：对同一 VMD，改前后逐帧逐骨比较插值结果位模式（必须完全一致）；随机 seek（前后跳帧）也必须一致，专门覆盖游标失效路径。

**是否碰产品源码**：是（`mmd_bone.cpp`）。**规模**：40–80 行。

---

### C4（非物理路径）playback 执行计划每帧重建 1–2 次（每次两遍全骨扫描）

**位置**
- `source/module/tools/object/mmd_bone_manager.cpp:1326-1372` `EnsurePlaybackExecutionPlan`
- 调用点：`mmd_model_manager.cpp:2435`、`mmd_bone_manager.cpp:2351`（`PrepareSceneForPhysicsPlaybackLayer` 内，dirty 时）、`:2336`（`PrepareSceneForPhysicsPlayback`）、`:2232`（骨骼管理器 Execute）、`mmd_model_runtime.cpp:104`（`PrepareExternalBonePoses`）

**关键代码行原文**
```cpp
// mmd_bone_manager.cpp:1333-1346
append_dependency_scratch_.clear();
append_dependency_scratch_.reserve(bone_list_.GetCount());
for (const auto& entry : bone_list_)
{
    const Int32 index = static_cast<Int32>(entry.GetKey());
    BaseTag* const tag = FindBone(index);
    ...
    append_dependency_scratch_.emplace_back(index, source ? FindBoneIndex(source) : -1,
        bc->GetBool(PMX_BONE_INHERIT_TRANSLATION), bc->GetBool(PMX_BONE_INHERIT_ROTATION));
}
if (append_dependency_scratch_ != append_dependency_snapshot_)
```

**为什么怀疑它贵**
- 单次调用 = 两遍 625 骨循环（继承依赖 + playback 快照），每骨 `FindBone` + `ResolveInheritSourceBoneTag()`（解析链接）+ 2×`GetBool` + 1×`GetInt32` + 2×`GetBool`，再叠加两个 `std::vector` 的 clear/reserve/emplace（4 元组与 5 元组）+ 一次逐元素 `operator!=` 比较 + `playback_execution_plan_.Update(...)`。
- 帧内调用点至少 2 个（`mmd_model_manager.cpp:2435` 与 `mmd_bone_manager.cpp:2232`），`PrepareSceneForPhysicsPlaybackLayer:2351` 在 dirty 时再触发；`PrepareExternalBonePoses:104` 每帧无条件触发一次（第 1 个 Execute 通道）。
- 这是典型的「每帧全量重算可缓存量」：项目已经有 `MarkAppendExecutionOrderDirty()`（`mmd_bone_manager.cpp:1350`）与 `append_execution_order_dirty_` 机制，说明脏标记基础设施是现成的。

**预期收益**：0.3–1.2 ms/帧（2–4 次 × 625 × ~0.3–0.7 µs）。**待实测**：stage `bone.plan` self 时间。

**风险**：低。已有脏标记是天然入口；需要补齐「脚本直改 `BaseContainer` 不走消息」的兜底（可保留低频全量校验，与 C1 合并成一次）。

**验证方式**：改前后比较 `playback_execution_plan_` 的 `BoneIndices()`/`Layers()`（逐元素相等）、逐帧插值顺序不变；构造「脚本改 layer/继承标志」用例断言仍能感知。

**是否碰产品源码**：是（`mmd_bone_manager.cpp`）。**规模**：60–120 行。

---

### C5（非物理路径 · IK 相关）IK 受影响骨集合每 IK 骨每帧重算 3–5 次，且去重是 O(n²)

**位置**
- `source/module/tools/tag/mmd_bone.cpp:2548-2620` `CollectIKAffectedBoneIndices`（去重 `:2558-2569`、`GetParameter(PMX_BONE_IK_TARGET_BONE_LINK)` `:2584`、`CollectStandaloneIKChainEntries` `:2600`）
- 调用点：`mmd_model_runtime.cpp:304`（`ik_chain_has_authored_pose` lambda 内，规划循环 + 求解循环各一次）、`mmd_bone.cpp:2532`（`MarkPrephysicsIKChainUpdated`）、`mmd_bone.cpp:2633`（`CacheIKSolveRuntimeOverrides`）、`mmd_model_runtime.cpp:369`

**关键代码行原文**
```cpp
// mmd_bone.cpp:2558-2569
const auto append_unique_index = [&affected_indices](const Int32 bone_index)
{
    if (bone_index < 0)
        return;
    for (const Int32 existing_index : affected_indices)
    {
        if (existing_index == bone_index)
            return;
    }
    affected_indices.Append(bone_index)iferr_ignore("append ik affected bone");
};
```

**为什么怀疑它贵**
- 单次调用包含：当前骨 + 从 `PMX_BONE_IK_TARGET_BONE_LINK` 解析链接（`GetParameter` + `BaseLink::GetLink`）+ `CollectStandaloneIKChainEntries`（读 IK 链描述数据）+ 逐链项 `FindBoneIndex`，并伴随 `maxon::BaseArray` 构造（无 reserve）。
- 去重是线性查表 → O(n²)；IK 链长度通常 3–5，n 小，但对每个 IK 骨重复 3–5 次乘以 IK 骨数量（典型 MMD 模型几十个）→ 每帧数百次「链接解析 + 描述读取」。
- 集合本身在同一帧内不会变化（同一 doc time、同一控制状态），完全可以按「帧 + 控制状态」缓存，或在 `SolveStandaloneIKForLayer` 内算一次传给三处调用点。

**预期收益**：0.3–1.5 ms/帧。**待实测**：stage `ik.solve` 中 `CollectIKAffectedBoneIndices` 的占比。

**风险**：低（纯缓存/传递参数，不改判定逻辑）。注意 `mmd_bone.cpp:2548` 是 `const` 函数、`CacheIKSolveRuntimeOverrides` 在求解后才调用，需要保证缓存 key 覆盖「同帧控制改动」。

**验证方式**：改前后对同一动作逐帧比较 IK 骨 `GetRelMl`；构造「同帧改 IK 目标链接」「切换 forced FK/IK」用例。

**是否碰产品源码**：是（`mmd_bone.cpp`、`mmd_model_runtime.cpp`）。**规模**：60–100 行。

---

### C6（非物理路径）adapter 全量同步每帧 2–4 次（每次两遍 625 adapter）

**位置**
- `source/module/tools/object/mmd_model_runtime.cpp:232-246` `SyncStandaloneBoneAdaptersFromScene`（第一遍逐 adapter `SyncCurrentTransformsFromBoneObject`，第二遍只对根 adapter `UpdateGlobalTransform`）
- 调用点：`mmd_model_runtime.cpp:409`、`:413`（每个 layer），外加 `:248-260` `SyncStandaloneBoneAdaptersLocalFromGlobal`（物理路径）

**关键代码行原文**
```cpp
// mmd_model_runtime.cpp:409-414（RunLayeredBonePass 内）
anim_count = bone_manager_data_->PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics);
SyncStandaloneBoneAdaptersFromScene(true);
}
const Int32 control_ik_count = mmd_control_workflow::SolveLayer(*bone_manager_data_, doc, layer, after_physics, controls);
if (control_ik_count > 0)
    SyncStandaloneBoneAdaptersFromScene(true);
const Int32 ik_count = SolveStandaloneIKForLayer(layer, after_physics, false);
```

**为什么怀疑它贵**
- 每个 layer 至少一次全量同步，控制求解有结果时再一次；两个 layer（before/after physics）→ 每帧 2–4 次 × 625 adapter 两遍扫描 = 2.5k–5k 次 adapter 调用。
- `PrepareSceneForPhysicsPlaybackLayer` 已经知道本 layer 实际刷新了哪些骨（返回值 `prepared_bones`/`anim_count`），把全量同步改成「只同步动过的骨 + 一次根级 `UpdateGlobalTransform`」是纯收益；现在的写法等于丢弃了这份信息。
- 第二遍 `UpdateGlobalTransform` 只对根 adapter，成本低；主要成本在第一遍 625 次（每次读场景矩阵 + 写 adapter 局部/全局矩阵）。

**预期收益**：0.3–1.2 ms/帧。**待实测**：stage `bone.scene_sync` self 时间与 `calls` 计数（`calls` 可直接验证 2–4 次/帧）。

**风险**：中。全局矩阵更新有顺序依赖（父子顺序）；缩小集合时必须保证「动过的骨的祖先链」也更新，否则会出现一帧的位姿错位。建议先做「按 layer 的骨集合」而不是「按返回值」，减少正确性风险。

**验证方式**：改前后逐帧比较所有骨的 `GetMg`（或 adapter 全局矩阵）；物理开/关各跑一遍，检查抖动（连续帧差分）。

**是否碰产品源码**：是（`mmd_model_runtime.cpp`）。**规模**：40–80 行。

---

### C7（非物理路径）控制链名称分类每帧全量重建

**位置**
- `source/utils/mmd_control_workflow.cpp:142-182` `FindLimbChains`（`:146 BuildOrderedBoneObjectList`，`:155-158` 两次 `GetString` + 名称分类）
- 上下文对象：`mmd_model_manager.cpp:2404` `mmd_control_workflow::EvaluationContext control_context;`（每帧新建 → 每帧重建链）

**关键代码行原文**
```cpp
// mmd_control_workflow.cpp:150-158
for (BaseObject *bone : bones)
{
    BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
    if (!tag) continue;
    const auto *data = tag->GetDataInstance();
    const auto local = string_util::GetStdString(data->GetString(PMX_BONE_NAME_LOCAL));
    const auto universal = string_util::GetStdString(data->GetString(PMX_BONE_NAME_UNIVERSAL));
    const Bool is_ik = data->GetBool(PMX_BONE_IS_IK);
    const auto kind = ClassifyBoneNames(local, universal, is_ik);
```

**为什么怀疑它贵**
- 625 骨 ×（2 次 `GetString` → `maxon::String`，再 `GetStdString` 转 `std::string`，至少一次堆分配 + UTF 转换）+ 每条名字跑多次名称前缀/角色匹配。
- 每帧一次（`EvaluationContext` 每帧新建，`GetChains` 只在同一 context 内缓存），与物理开关无关。
- 该结果是「模型级静态拓扑」：只在骨名/位置顺序/IK 标志变化时才会变。

**预期收益**：0.3–1.0 ms/帧（625 × ~0.5–1.5 µs 的字符串与匹配 + 625 次 `GetTag`）。**待实测**：stage `control.chains` self 时间。

**风险**：低-中。`mmd_control_workflow.cpp:148-149` 的注释明确「不要在多次求值间复用快照，脚本可改名/改序」——所以缓存必须有失效条件：绑定到 `MMDBoneManagerObject` 的骨名/顺序版本号（导入/改名/重排时递增），或绑定到 doc time + 低频校验。

**验证方式**：改前后对同一场景比较四条肢体链指针（`arms/legs/leg_goals`）；构造「脚本改名后立即求值」用例断言链路更新。

**是否碰产品源码**：是（`mmd_control_workflow.cpp`，可选 `mmd_model_manager.cpp` 复用 context）。**规模**：40–70 行。

---

### C8（物理路径 · 最大单点）748 个关节一律 `btGeneric6DofSpringConstraint` + 3 子步

**位置**
- `source/module/tools/object/mmd_model_runtime.cpp:746-759`：**无过滤**地把所有 `joints` 逐个 `physics->AddJoint(...)`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1172-1177`：每个关节都构造成 `btGeneric6DofSpringConstraint`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1200-1229`：只有 `m_spring*` 非零的轴才 `enableSpring(...)`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164`：`stepSimulation(time, m_maxSubStepCount, 1.0/m_fps)`
- 求解器：`dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:75`（`btSequentialImpulseConstraintSolver`，未显式调 `m_numIterations`，Bullet 默认 10）
- 子步默认值：产品侧 `mmd_model_manager.cpp:1003-1008` `GetPhysicsSubsteps`，默认 3（1–10）

**关键代码行原文**
```cpp
// MMDPhysics.cpp:1172-1177
auto constraint = std::make_unique<btGeneric6DofSpringConstraint>(
    *rigidBodyA->GetRigidBody(),
    *rigidBodyB->GetRigidBody(),
    invA, invB, true);

// MMDPhysics.cpp:1200-1204
if (pmdJoint.m_springPos.x() != 0)
{
    constraint->enableSpring(0, true);
    constraint->setStiffness(0, pmdJoint.m_springPos.x());
}
```

**为什么怀疑它贵**
- 物理 15.9 ms 的主体是 Bullet 求解：748 个 6-DOF 约束 ≈ 748×6 = 4488 行/子步，×3 子步 ≈ 13.5k 行/tick 组，×10 次求解迭代 ≈ 134k 行解算/帧。`btGeneric6DofSpringConstraint` 比 `btGeneric6DofConstraint` 每个子步多一遍弹簧力累积与 6 次 `calculateTransforms` 相关开销（`enableSpring` 只影响被使能的轴，但类型仍是 Spring）。
- 三个可独立落地的切口：
  1. **无弹簧关节降级**：`m_springPos/m_springRot` 六轴全 0 时用 `btGeneric6DofConstraint`（语义完全等价，因为弹簧刚度为 0 时不产生力）；MMD 模型里「刚体框架/固定件」类关节通常全 0。
  2. **双静态关节不入世界**：两边刚体都是 `Static` 的关节不可能产生约束作用（`mmd_model_runtime.cpp:733` 已经会用 `Operation::Static` 过滤动态骨，说明类型信息就在手边）。MMD 常见于固定装饰件对。
  3. **子步 3→2**：1/30 s 帧用 1/60 固定步长本就需要 2 步，第 3 步常为空转（`stepSimulation` 内部按累加器决定实际子步数，配置 3 只是上限）。**注意**：这条会改变动力学行为，属于「参数调整」而非纯优化，需要视觉/数值回归。
- 微项（已排查、不建议投入）：`MMDFilterCallback::needBroadphaseCollision`（`MMDPhysics.cpp:43-57`）对每个 broadphase pair 做 `std::find_if`，但 `m_nonFilterProxy` 只有地面 1 项，成本可忽略。

**预期收益**：切口 1+2 合计 2–6 ms/帧（推理：若 748 个关节中 60–80% 无弹簧、5–15% 为双静态，则求解行数与弹簧开销同比下降）；切口 3 约 4–5 ms（15.9 × 1/3，上游界）。**待实测**：`physics.bullet` 与 `bullet.solver.joints` / `bullet.solver.iterations` stage；这三个 stage 名在 `source/utils/cmt_runtime_profile.hpp:30-37` 已存在。

**风险**
- 切口 1：低（刚度全 0 时无副作用；必须逐关节校验六轴刚度确实为 0，避免把「靠 0 弹簧 + 极限」实现的软约束改坏）。归属 **libMMD 依赖**（`dependency/libMMD`），需要依赖补丁 + 物理回归。
- 切口 2：中（必须确认双静态关节确实不影响碰撞过滤/接触；MMD 中存在靠关节连接静态刚体做「碰撞体锚定」的用法）。
- 切口 3：中高（行为变化，且数值上可能破坏既有「物理回放确定性」基线，`docs/validation/physics-replay-determinism-20261019/` 有现成基线）。

**验证方式**：①同场景同动作，改前后逐帧比较所有动态骨的 `GetMg`（确定性回放，允许的差异必须给出阈值与理由）；②`docs/validation/physics-replay-determinism-20261019/` 的基线复跑；③`bullet.solver.*` stage 的行数/迭代计数下降；④视觉抽查接触穿插。

**是否碰产品源码**：部分。切口 1/2 在 `dependency/libMMD`（依赖补丁，非 `source/`）；切口 3 在产品侧配置默认值（`mmd_model_manager.cpp:1003-1008` 附近）。**规模**：依赖侧 60–120 行；产品侧 10–30 行。

---

### C9（非物理路径）每帧两次 mesh 层级失效 + 每帧 morph tag 全量解析

**位置**
- `source/module/tools/object/mmd_model_runtime.cpp:67-91` `MarkMeshHierarchyDirty`（`weights_changed` 默认 `true`）
- 调用：`mmd_model_runtime.cpp:938`（物理写回，`false`）、`mmd_bone_manager.cpp:2299-2303`（骨骼管理器，**默认 true**）
- `source/module/tools/object/mmd_mesh_manager.cpp:342-353`：每帧遍历 `mesh_morph_data_` 调 `morph.ResolveTag()`

**关键代码行原文**
```cpp
// mmd_model_runtime.cpp:73-85
for (BaseObject* mesh_object = mesh_manager_object->GetDown(); mesh_object; mesh_object = mesh_object->GetNext())
{
    MarkSceneNodeDirty(mesh_object);
    for (BaseTag* tag = mesh_object->GetFirstTag(); tag; tag = tag->GetNext())
    {
        if (weights_changed && tag->GetType() == Tweights)
            MarkSceneNodeDirty(tag);
    }
}

// mmd_mesh_manager.cpp:343-345
for (const auto& group : mesh_morph_data_)
    for (const auto& morph : group)
        if (!morph.ResolveTag()) invalid_morph_link = true;
```

**为什么怀疑它贵**
- `MarkSceneNodeDirty` = `SetDirty(MATRIX|DATA|CACHE)` + `MSG_UPDATE`（`mmd_model_runtime.cpp:60-65`）。骨骼管理器与物理写回**同一帧各触发一次**；两者同时发生且 `weights_changed=true` 时，权重 tag 被 `MSG_UPDATE` 两次 → 权重缓存（70,222 顶点）可能被重建两次。
- `mmd_mesh_manager.cpp:343` 每帧对全部 morph（MMD 模型常 100–300 个）做一次 `ResolveTag()`（链接解析），仅为了检测「失效链接」；这是典型的可消息驱动化的工作（`needs_morph_data_refresh_` 已经存在，`:346`）。

**预期收益**：0.5–2.0 ms/帧（取决于是否真的发生两次全量权重重建——**待实测**：`mesh.invalidate`、`mesh.weight_update` stage 的 `calls` 与 self 时间；`calls==2/帧` 即坐实重复）。

**风险**：低-中。合并不是简单删调用：物理写回后必须确保 mesh 至少失效一次、且 after-physics 骨骼改动之后还要再失效（顺序敏感）。建议改成「每帧一次合并失效」：物理写回只标记 `pending`，由 model manager 收尾统一 `MarkMeshHierarchyDirty(..., weights_changed = 本帧是否改过权重)`。

**验证方式**：改前后逐帧比较顶点位置（`GetPointR`）与权重缓存一致性；检查 `mesh.weight_update` 的 `calls` 从 2 降到 1（或 0）；视觉检查 morph 滑杆仍即时生效。

**是否碰产品源码**：是（`mmd_model_runtime.cpp`、`mmd_mesh_manager.cpp`）。**规模**：30–60 行。

---

## 3. 候选汇总表

| 编号 | 环节 | 帧内次数（结构推断） | 预估收益 | 风险 | 碰 `source/` | 规模 |
|---|---|---|---|---|---|---|
| C1 | 控制状态校验和/增量/同步 | ≥4 × 625 骨 | 1.0–3.5 ms | 中 | 是 | 80–150 行 |
| C2 | `ApplyActiveAnimation` + `MSG_UPDATE` | 3 × 625 骨 | 1.5–5.0 ms | 中高 | 是 | 100–200 行 |
| C3 | 关键帧线性扫描 | 6 × 625 骨 × K | 0.5–2.5 ms | 低 | 是 | 40–80 行 |
| C4 | playback 执行计划重建 | 2–4 次 × 两遍 625 | 0.3–1.2 ms | 低 | 是 | 60–120 行 |
| C5 | IK 受影响集合重算 | 3–5 × IK 骨 | 0.3–1.5 ms | 低 | 是 | 60–100 行 |
| C6 | adapter 全量同步 | 2–4 × 625 × 2 遍 | 0.3–1.2 ms | 中 | 是 | 40–80 行 |
| C7 | 控制链名称分类 | 1 × 625 骨（2 次字符串） | 0.3–1.0 ms | 低-中 | 是 | 40–70 行 |
| C8 | Bullet 约束类型/子步 | 748 约束 × 3 子步 × 10 迭代 | 2–6 ms（+子步 4–5 ms） | 低→中高（分切口） | 部分（libMMD） | 60–120 行 |
| C9 | mesh 双重失效 + morph 解析 | 2 次失效 / 1 × morph 数 | 0.5–2.0 ms | 低-中 | 是 | 30–60 行 |

> 收益区间是**推理值**，不是实测值；同一帧里 C1–C7、C9 互有重叠（例如 C2 的收益部分来自 C3），不能简单相加。

---

## 4. 交叉验证矩阵（stage 探针 → 我的排序应如何重排）

探针阶段名取自 `source/utils/cmt_runtime_profile.hpp:19-57`（`RuntimeStageName` 的真实字符串）。注意：`CMT_ENABLE_RUNTIME_PROFILING` 在 Release 下为 0（`source/utils/cmt_runtime_profile.hpp:8-11`、`:171-175` → `CMT_PROFILE_SCOPE` 展开为 `((void)0)`），所以 stage 数来自 profiling 构建；该构建自身有开销量（每 scope 两次 `steady_clock` 读 + 记账，`bone.tag.execute`/`bone.animation` 这类 scope 每帧上千次），**请以 `calls` 计数与相对比例为准，绝对值会被抬高**。

| 探针结果 | 结论 | 我的排序调整 |
|---|---|---|
| `physics.bullet` / `bullet.solver.joints` / `bullet.solver.iterations` 占大头，且 `calls` 显示 3 子步 | Bullet 求解行数是主因 | **C8 提到第 1**（先做「无弹簧降级 + 双静态过滤」，再谈子步） |
| `bone.animation` self 高、`calls` ≈ 625×3/帧 | C2 的「每骨 3 次重算 + 3 次 MSG_UPDATE」被实测坐实 | C2 提到第 1；C3 紧跟（C2 的优化会同时放大/缩小 C3 的收益） |
| `bone.tag.execute` self 高但 `bone.animation` 接近整帧 | 主要成本在 `MSG_UPDATE`/`SetDirty` 传播而不是插值 | 只做 C2 的第 ②③ 项（收敛 `MSG_UPDATE`），暂不动插值路径 |
| `control.checksum` + `control.delta` + `control.sync` 合计 ≥1 ms，`calls` ≈ 4/帧 | C1 成立 | C1 保持第 1–2 |
| `control.chains` 明显（≥0.5 ms） | C7 成立 | C7 提前到 C4 之前 |
| `bone.plan` 明显（≥0.3 ms）且 `calls` ≥2 | C4 成立 | C4 提到 C5/C6 之前 |
| `ik.solve` 高且 `calls` 显示每 IK 骨多次 `CollectIKAffectedBoneIndices` | C5 成立 | C5 提前 |
| `bone.scene_sync` 高、`calls` ≈ 4/帧 | C6 成立 | C6 提前到 C4 之前 |
| `mesh.invalidate` / `mesh.weight_update` 的 `calls` ≥2/帧 | C9 的「双重失效」坐实 | C9 提到 C1 之后（收益可能是最大的一项） |
| 物理关 18.2 ms 中，上述 stage 合计 <2 ms，且 `model.execute` self 很大 | 说明瓶颈在我未插桩的路径（C4D 原生 `Oskin` 蒙皮 / 依赖图调度），本轮候选全部收益有限 | 应改攻「减少每帧触发蒙皮的成本」或接受 18.2 ms 现状 |
| 物理开 34.0 − 物理关 18.2 ≈ 15.9 ms，但 `physics.total` 只报到 8–10 ms | 有物理相关时间落在 `physics.total` 之外（如 `mesh.invalidate` 之后的重建、`PhysicsWriteback` 里的 adapter/override） | 先查 `physics.writeback`、`bone.scene_sync`，再看 C8 |

---

## 5. 明确不建议的方向

- **紧凑关节表（compact skin joints）**：已有实测结论「变形逐点一致、耗时在噪声内」，本文件不再提案。
- **顶点写回并行化**：基线已经是 `ParallelForDynamic`（`source/module/tools/object/mmd_mesh_manager.cpp:681-688`），且属于导入期一次性代码，不是每帧路径。
- **`Clamp01`/权重组装微优化**：同上，属导入期；已被实测证明无收益。
- **`88bc01c1` 已做的项**（控制器数据复用、材质所有权复用、空物理后层跳过、重复权重通知消除、可复用运行时/Bullet 插桩、物理子步默认 3、依赖目标 `/O2 /fp:strict /Ob0 /Oi-`）：不重复提案。
- **C4D 原生蒙皮内部**：`Oskin` 求值不在插件源码内（导入期插入，`mmd_mesh_manager.cpp:651`、`:1189`），只能通过「少失效、少重复触发」间接影响，属 C9 范畴。

---

## 6. 引用清单（file:line）

**执行点与通道**
- `source/module/tools/object/mmd_model_manager.cpp:2317` `EXECUTIONRESULT MMDModelManagerObject::Execute(...)`
- `source/module/tools/object/mmd_model_manager.cpp:2334-2337` 外部姿态通道早退
- `source/module/tools/object/mmd_model_manager.cpp:2392-2473` 主通道（校验和 → 门控 → 两个 layer pass → 物理 → 控制同步 → 二次校验和）
- `source/module/tools/object/mmd_model_manager.cpp:5136-5144` `AddToExecution` 注册 3 个执行点
- `source/module/tools/object/mmd_model_manager.h:293-294` `kExternalPosePreparePriority` / `kExternalPoseSolvePriority`

**骨骼 / IK / 控制**
- `source/module/tools/tag/mmd_bone.cpp:3634-3673` `MMDBoneTag::Execute`
- `source/module/tools/tag/mmd_bone.cpp:3367-3365`（`ApplyActiveAnimation` 主体，含 `:3360-3363` 收尾写入）
- `source/module/tools/tag/mmd_bone.cpp:139-145` `MarkBoneTransformDirty`
- `source/module/tools/tag/mmd_bone.cpp:1270-1297` `HasStaticPoseAnimationSegmentAtTime`（`:1290-1292` 线性扫描）
- `source/module/tools/tag/mmd_bone.cpp:3401-3403` 插值区间线性扫描
- `source/module/tools/tag/mmd_bone.cpp:2548-2620` `CollectIKAffectedBoneIndices`
- `source/module/tools/tag/mmd_bone.cpp:2532`、`:2633`、`source/module/tools/object/mmd_model_runtime.cpp:304`、`:369` 该集合的重复调用点
- `source/utils/mmd_bone_control_util.cpp:1386-1404` `HasActiveControlDelta`
- `source/utils/mmd_bone_control_util.cpp:1420-1449` `GetControlStateChecksum`
- `source/utils/mmd_bone_control_util.cpp:1451+` `SyncControlsToCurrentPose`
- `source/utils/mmd_control_workflow.cpp:142-182` `FindLimbChains`
- `source/utils/mmd_control_workflow.cpp:468-488` `CollectExtraControls`
- `source/utils/mmd_control_workflow.cpp:696-731` `SolveLayer`

**骨骼管理器 / 执行计划**
- `source/module/tools/object/mmd_bone_manager.cpp:1326-1372` `EnsurePlaybackExecutionPlan`
- `source/module/tools/object/mmd_bone_manager.cpp:2206-2306` `MMDBoneManagerObject::Execute`
- `source/module/tools/object/mmd_bone_manager.cpp:2341-2391` `PrepareSceneForPhysicsPlaybackLayer`

**模型运行时 / adapter / mesh 失效**
- `source/module/tools/object/mmd_model_runtime.cpp:95-140` `PrepareExternalBonePoses`
- `source/module/tools/object/mmd_model_runtime.cpp:232-260` adapter 同步函数
- `source/module/tools/object/mmd_model_runtime.cpp:281-418` `SolveStandaloneIKForLayer` / `RunLayeredBonePass`
- `source/module/tools/object/mmd_model_runtime.cpp:60-91` `MarkSceneNodeDirty` / `MarkMeshHierarchyDirty`
- `source/module/tools/object/mmd_model_runtime.cpp:691-767` `BuildStandalonePhysics`（`:746-759` 关节无过滤入世界）
- `source/module/tools/object/mmd_model_runtime.cpp:878-900` `StepStandalonePhysics`
- `source/module/tools/object/mmd_model_runtime.cpp:902-939` `ApplyStandalonePhysicsResults`
- `source/module/tools/object/mmd_mesh_manager.cpp:330-356` `MMDMeshManagerObject::Execute`（`:343-345` 每帧 morph `ResolveTag`）
- `source/module/tools/object/mmd_mesh_manager.cpp:651`、`:1189` 导入期插入 `Oskin`

**依赖（libMMD / Bullet）**
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:69-107` `Create`（`:75` 默认求解器，未设迭代数）
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:160-164` `Update` → `stepSimulation`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1172-1229` `btGeneric6DofSpringConstraint` 构造与弹簧使能
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1092-1107` `SyncBonePositionToPhysics`
- `dependency/libMMD/src/libMMD/Model/MMD/MMDPhysics.cpp:1080-1090` `ReflectGlobalTransform`

**插桩基础设施**
- `source/utils/cmt_runtime_profile.hpp:8-11`、`:19-57`、`:171-175`（宏在 Release 下为空）

---

## 7. 待实测清单（本文件未做、需要探针或实验确认）

1. `MSG_UPDATE` 在骨对象上的真实代价（C2）——C4D 内部是否因此触发父级缓存重建，静态代码无法判定。
2. `mesh.weight_update` 的 `calls` 是否真的 ≥2/帧（C9）；若只有 1 次，C9 收益大幅缩水。
3. `GetParameter`（描述系统）单次成本（C1）——决定了 C1 是 1 ms 还是 3.5 ms。
4. `ApplyActiveAnimation` 的单次耗时随 K（关键帧数）的斜率（C2/C3）。
5. Bullet 侧：748 个关节中「六轴弹簧全 0」与「双静态」的实际比例（C8 的收益直接由比例决定）；需从 PMX 数据统计。
6. 物理子步从 3 降到 2 的数值差异幅度（C8 切口 3）——必须先有确定性基线再评估。
7. 「每帧 `MMDModelManagerObject::Execute` 是否被调用超过 3 次」（例如依赖图重复调度）：`model.execute` 的 `calls` 计数可直接回答；若是 6 次，本文件所有「每帧次数」都要翻倍。
