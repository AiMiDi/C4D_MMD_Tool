import io

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

broken = 'std::printf("NOTE dynamics=%zu kinematics=%zu bullet_kinematic=%zu\n", motion_probe.Dynamics(),'
fixed = 'std::printf("NOTE dynamics=%zu kinematics=%zu bullet_kinematic=%zu\\n", motion_probe.Dynamics(),'

if broken not in src:
    print("BROKEN_NOT_FOUND")
else:
    src = src.replace(broken, fixed, 1)
    io.open(p, "w", encoding="utf-8", newline="").write(src)
    print("FIXED")
