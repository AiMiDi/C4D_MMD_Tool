import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

anchor = "\tvoid SetSubSteps(int count)\n"
add = ("\t// libMMD 创建刚体时把动态刚体置为 kinematic（MMDPhysics.cpp:824/1026），\n"
       "\t// 产品在 ResetStandalonePhysics() 里对所有刚体 SetActivation(true)（mmd_model_runtime.cpp:868-875）；\n"
       "\t// 夹具必须复刻这一步，否则 Bullet 根本不积分，dt/substeps 负向控制不可能变红。\n"
       "\tvoid ActivateDynamics()\n"
       "\t{\n"
       "\t\tif (!bodies_) return;\n"
       "\t\tfor (auto& body : *bodies_)\n"
       "\t\t\tbody->SetActivation(true);\n"
       "\t}\n"
       "\n")
if "void ActivateDynamics()" not in src:
    if anchor not in src:
        sys.exit("ANCHOR substeps")
    src = src.replace(anchor, add + anchor, 1)

marker = "\t\treturn bodies_ != nullptr && joints_ != nullptr;"
if marker not in src:
    sys.exit("ANCHOR return")
if "ActivateDynamics();\n\t\treturn bodies_" not in src:
    src = src.replace(marker, "\t\tActivateDynamics();\n" + marker, 1)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED5")
