import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

pairs = [
    ('Check(motion.moved_over_1mm >= 30, "physics-actually-simulates",\n\t\t\t"至少 30 个刚体在 199 帧内位移超过 1 mm，否则物理几乎没演算，等价性断言无意义");',
     'Check(motion.moved_over_1mm >= 300, "physics-actually-simulates",\n\t\t\t"至少 300/479 个刚体在 199 帧内位移超过 1 mm，否则物理几乎没演算，等价性断言无意义");'),
    ('Check(motion.max_mm > 5.0, "physics-actually-simulates", "最大位移必须超过 5 mm");',
     'Check(motion.max_mm > 50.0, "physics-actually-simulates", "最大位移必须超过 50 mm（真实重力下应有明显自由落体）");'),
]
for old, new in pairs:
    if old not in src:
        sys.exit("ANCHOR " + old[:40])
    src = src.replace(old, new, 1)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("THRESHOLD_TIGHTENED")
