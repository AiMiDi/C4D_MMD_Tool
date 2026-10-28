import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\p4-invariant-design.md"
src = io.open(p, encoding="utf-8", newline="").read()

start = src.index("## 2. 问题一：")
end = src.index("## 3. 问题二：")
old_sec2 = src[start:end]

new_sec2 = """## 2. 问题一：等价性在真实世界成立吗？

**结论：成立（在真实 PMX 世界上、在本夹具的输入与步进口径下）。** 但这个「成立」是 t60 修好两处夹具缺陷之后才成立的——t59 那一版的正向 0 差异没有证伪力。

### 2.1 为什么 t59 的负向控制不可能变红（根因）

`libMMD` 建刚体时把动态刚体设为 kinematic：`MMDPhysics.cpp:814-828` 用 mass 建 `btRigidBody`，但只有 `Operation::Static` 才加 `CF_KINEMATIC_OBJECT`；**动态刚体随后在 `MMDPhysics.cpp:1026` 被 `SetActivation(false)` 打上 kinematic 标记**（产品在第一步之前会统一 `SetActivation(true)`）。t59 的夹具直接 `PMXModel::Load()` 后就开始步进，**没有复刻产品的 `SetActivation(true)`**（`source/module/tools/object/mmd_model_runtime.cpp:868-875` 的 `ResetTransform`/`Reset`/`SetActivation(true)` 三连），于是 479 个刚体全部是 kinematic，Bullet 只做运动学搬运、不做积分：改 dt、改 substeps 自然一个 word 都不变。t59 里「219 个刚体动了、最大 54 mm」原来只是骨骼驱动的搬运，不是物理响应。

t60 在夹具 `RealWorld::Load()` 末尾加 `ActivateDynamics()`（逐刚体 `SetActivation(true)`），并把「激活后 kinematic 数」打成 NOTE：`bullet_kinematic=479 → 27`（27 = PMX 里 op=Static 的数量），世界才开始真正积分。

第二处缺陷是影子时钟的起点：给 `Run()` 加 `lag` 后，若 lag 帧之前仍然步进（只是不喂输入），`async(1)` 与 `sync(0)` 会差一次「无输入的步进」，正向必然不等（实测 `first_diff_frame=1`、2,218,703 个 word 差异）。修法是**影子时钟从被启用那一帧开始**：`input_frame < 0` 时不步进。修后 `first_diff_frame=-1`、0 差异。

### 2.2 现在的实测（`offline/build/run-t60-final.log`，`RESULT cases=8 assertions=17 failures=0`，exit 0）

| 案例 | 结果 |
|---|---|
| `real-world-build-from-pmx` | 479 刚体 / 748 关节，与 PMX 一致；快照 15,748 words |
| `rigid-op` 直方图 | static=27、dynamic=450、dynamic_with_bone=2（`file.m_rigidbodies[i].m_op`） |
| `world-has-dynamics` | mass>0=452；激活后 `bullet_kinematic=27`（未激活时是 479 —— 这正是 t59 的病根） |
| **`physics-actually-simulates`** | 帧 0 vs 帧 199：**476/479 个刚体位移 > 1 mm，最大 8,032.30 mm**（本 PMX 没有 ground 刚体，自由落体；产品世界同样没有额外地面，重力 `-9.8×10` 见 `MMDPhysics.cpp:87`） |
| `same-cadence-identical-replay` | 两个独立真实世界、同输入同节奏：0 差异（比较器自证） |
| **`delayed-by-one-frame-bitexact`** | 影子晚一帧、199 帧 × 15,748 words：**0 个 word 差异**（严格 memcmp，零容差） |
| **`negative-skipped-input-detected`** | 跳到第 57 帧不喂输入：**检出**（>0 差异） |
| **`negative-dt-changed-detected`** | dt ×1.5：**1,736,170 个 word 不同**（16 个刚体漂移 >1 mm，最大 2.80 mm） |
| **`negative-substeps-changed-detected`** | substeps 3→2：**2,276,027 个 word 不同**（232 个刚体漂移 >1 mm，最大 40.04 mm） |

### 2.3 判定与门槛

- 正向等价性**只在三条负向控制全红之后**才被写成「成立」；三者分别打红在「输入序列」「积分步长」「子步上限」三个维度上。
- 夹具现在把「物理真的在演算」写成硬断言：`moved_over_1mm >= 300`、`max_mm > 50`（不满足即 fail），避免退回 t59 那种「冻结世界里的 0 差异」。
- 等价性口径：影子世界从被启用那一帧起，喂与同步世界**同一段输入序列**；`async(N)` 与 `sync(N−1)` 在 `lag=1` 时逐位相等（199 帧）。

### 2.4 仍未覆盖（不得越界宣称）

- 骨骼输入是确定性合成摆动，不是 VMD 采样；只验了「同一段输入序列」，没验「输入本身来自 VMD 时的相位/帧号映射」。
- 只覆盖 libMMD 层（`PMXModel::Load` → `MMDPhysicsManager` → `MMDPhysics` → Bullet），**不覆盖** C4D 适配层（`MMDRigidManagerObject::BuildStandaloneRigidBodies`、`mmd_model_runtime.cpp` 物理桥的 `SyncBonePositionToPhysics`/`ReflectGlobalTransform` 调用时机）。
- 位级一致只在「同进程、同二进制、同构建选项」下验证；跨编译器/跨进程（例如 worker 线程所在 TU 由不同 flags 编译）未验证。
- 本 PMX 无地面，自由落体 8 m；有接触/摩擦主导的场景（落地、衣摆挤压）未覆盖——接触求解是 warm-start 敏感区，单独需要一组实验。

"""

src = src[:start] + new_sec2 + src[end:]

old_head_end = src.index("## 1. 实验设置（真实度边界）")
new_head = """# P4 不变量设计（t59 起草，t60 定论）

> **结论先行**：
> - **问题一（逐帧真实输入下是否逐位等价）：成立** —— 真实 PMX 世界上「影子晚一帧」在 199 帧 × 15,748 words 上严格 0 差异，且 dt、substeps、跳输入三条负向控制**全部变红**（证伪力已建立）。前提是夹具必须复刻产品的 `SetActivation(true)`，否则世界根本不积分。
> - **问题二（seek）：无历史重建** —— 同步路径 `ResetStandalonePhysics()` 整世界重建 + warm-start 清零（`mmd_model_runtime.cpp:828-876`），影子镜像重建即可保持等价，不必向「seek 后回退同步」妥协。
> - 边界：只覆盖 libMMD + Bullet 层；C4D 适配层、VMD 输入相位、接触主导场景未覆盖（见 §2.4）。

"""
src = new_head + src[old_head_end:]

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("REPORT_UPDATED")
