import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\p4-invariant-design.md"
src = io.open(p, encoding="utf-8", newline="").read()

start = src.index("## 4. 下一轮改动点（带行号）")
new_tail = """## 4. 下一轮改动点（带行号）

1. 影子世界必须复刻 `source/module/tools/object/mmd_model_runtime.cpp:868-875` 的 `ResetTransform`/`Reset`/`SetActivation(true)` 三连；否则动态刚体停在 kinematic 状态，影子世界不会积分（t60 实测：未激活时 479/479 kinematic，激活后 27）。
2. 影子时钟从启用帧开始（`lag` 帧之前不步进）；丢弃「先空转再补输入」，那会引入一次没有输入的步进。
3. seek 走 `ResetStandalonePhysics()`（`:848`）后按同样的激活顺序重建，等价性自动恢复（问题二结论）。

## 5. 本轮产物

- `offline/p4-equivalence-v2.cpp`：真实 PMX 世界夹具（8 案例 / 17 断言），含刚体 op 直方图、激活后 kinematic 计数、帧间位移统计与三条负向控制。
- `offline/build-p4-equivalence.ps1`：构建 + 运行（`-Pmx` 指定 ASCII 路径副本）。
- `offline/build/run-t60-final.log`：本轮定稿运行日志（`RESULT cases=8 assertions=17 failures=0`，exit 0）。
- `offline/build/model.pmx`：真实 PMX 的 ASCII 副本（libMMD 的 `fopen` 不支持中文路径）。
- 一次性补丁脚本（`add_motion_case.py`、`add_neg_notes.py`、`add_static_semantics.py`、`add_activation.py`、`fix_lag_clock.py`、`add_firstdiff.py`、`tighten_motion.py`、`update_report_t60.py` 等）留作取证。

"""

src = src[:start] + new_tail
io.open(p, "w", encoding="utf-8", newline="").write(src)
print("TAIL_UPDATED")
