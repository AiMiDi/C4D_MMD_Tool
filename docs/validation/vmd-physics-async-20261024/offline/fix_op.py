import io

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

bad = "const int op = static_cast<int>(body.m_op);`n`t`t`tif (op >= 0 && op < 3)`n`t`t`t`t++op_counts[op];"
good = ("const int op = static_cast<int>(body.m_op);\n"
        "\t\t\tif (op >= 0 && op < 3)\n"
        "\t\t\t\t++op_counts[op];")
if bad not in src:
    print("BAD_NOT_FOUND")
else:
    src = src.replace(bad, good, 1)
    io.open(p, "w", encoding="utf-8", newline="").write(src)
    print("FIXED")
