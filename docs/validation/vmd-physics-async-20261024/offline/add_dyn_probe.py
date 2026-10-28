import io, re, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

pat = re.compile(r'([ \t]*size_t Kinematics\(\) const[^\n]*\n)')
m = pat.search(src)
if not m:
    sys.exit("NO KINEMATICS")
print("FOUND:", repr(m.group(1)))

new_method = (
    "\n"
    "\t// 由 Bullet 的碰撞标志判断「跟随骨骼」的刚体（mode 0），用于解释 dt 不敏感。\n"
    "\tsize_t BulletKinematics() const\n"
    "\t{\n"
    "\t\tif (!bodies_) return 0;\n"
    "\t\tsize_t n = 0;\n"
    "\t\tfor (auto& body : *bodies_)\n"
    "\t\t\tif (body->GetRigidBody() && body->GetRigidBody()->isKinematicObject()) ++n;\n"
    "\t\treturn n;\n"
    "\t}\n")
src = src[:m.end(1)] + new_method + src[m.end(1):]

src, n = re.subn(r'std::printf\("NOTE dynamics=%zu kinematics=%zu\\n", motion_probe\.Dynamics\(\), motion_probe\.Kinematics\(\)\);',
                 'std::printf("NOTE dynamics=%zu kinematics=%zu bullet_kinematic=%zu\\n", motion_probe.Dynamics(),\n'
                 '\t\t\t\tmotion_probe.Kinematics(), motion_probe.BulletKinematics());', src)
print("NOTE_REPL", n)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED3")
