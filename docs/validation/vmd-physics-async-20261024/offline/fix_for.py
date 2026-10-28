import io

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

bad = ("\t\tfor (const auto& body : file.m_rigidbodies)\n"
       "\t\t\tconst int op = static_cast<int>(body.m_op);\n"
       "\t\t\tif (op >= 0 && op < 3)\n"
       "\t\t\t\t++op_counts[op];\n")
good = ("\t\tfor (const auto& body : file.m_rigidbodies)\n"
        "\t\t{\n"
        "\t\t\tconst int op = static_cast<int>(body.m_op);\n"
        "\t\t\tif (op >= 0 && op < 3)\n"
        "\t\t\t\t++op_counts[op];\n"
        "\t\t}\n")
if bad not in src:
    print("BAD_NOT_FOUND")
else:
    io.open(p, "w", encoding="utf-8", newline="").write(src.replace(bad, good, 1))
    print("FIXED")
