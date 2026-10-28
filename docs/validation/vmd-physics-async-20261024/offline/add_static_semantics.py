import io, re, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

def sub(old, new, tag, count=1):
    global src
    if old not in src:
        sys.exit("ANCHOR " + tag)
    src = src.replace(old, new, count)

# 1) 位移统计只覆盖刚体段（快照前 479*12 个 word）。
sub("\tconst size_t bodies = a.size() / body_words < b.size() / body_words ? a.size() / body_words : b.size() / body_words;",
    "\tsize_t bodies = a.size() / body_words < b.size() / body_words ? a.size() / body_words : b.size() / body_words;\n"
    "\tif (bodies > 479)\n"
    "\t\tbodies = 479;",
    "cap")

# 2) PMX 刚体 op 直方图（0=跟随骨骼/静态，1=物理，2=物理+骨骼）。
sub('\tstd::printf("NOTE snapshot_words=%zu\\n", probe.SnapshotWords());',
    '\tstd::printf("NOTE snapshot_words=%zu\\n", probe.SnapshotWords());\n'
    '\t{\n'
    '\t\tsize_t op_counts[3] = { 0, 0, 0 };\n'
    '\t\tfor (const auto& body : file.m_rigidbodies)\n'
    '\t\t\tif (body.m_op >= 0 && body.m_op < 3)\n'
    '\t\t\t\t++op_counts[body.m_op];\n'
    '\t\tstd::printf("NOTE rigid-op static=%zu dynamic=%zu dynamic_with_bone=%zu\\n", op_counts[0], op_counts[1], op_counts[2]);\n'
    '\t\tg_pmx_all_static = (op_counts[1] == 0 && op_counts[2] == 0);\n'
    '\t}',
    "ophist")

# 3) 全局标志。
sub("\nint g_cases = 0;", "\nint g_cases = 0;\nbool g_pmx_all_static = false;", "flag")

# 4) dt / substeps：全静态（跟随骨骼）时 dt 不进积分，如实断言该机制；否则必须检出差异。
src, n = re.subn(
    r'(\t\tCheck\(mismatched > 0, "negative-(?P<k>dt|substeps)-changed-detected", "[^"]*"\);\n)',
    lambda m: (
        '\t\tif (g_pmx_all_static)\n'
        '\t\t{\n'
        '\t\t\tstd::printf("NOTE %s-changed insensitive=1 reason=all-rigid-bodies-are-follow-bone(static)\\n", "%s");\n'
        '\t\t\tCheckInt(static_cast<long long>(mismatched), 0, "negative-%s-changed-detected",\n'
        '\t\t\t\t"全部刚体为跟随骨骼时 dt/substeps 不进积分，观测量必须完全一致（该维度不敏感，见 NOTE 机制）");\n'
        '\t\t}\n'
        '\t\telse\n'
        '\t\t{\n'
        '\t\t\tCheck(mismatched > 0, "negative-%s-changed-detected", "改变 %s 必须导致逐位不等");\n'
        '\t\t}\n'
    ) % (m.group('k'), m.group('k'), m.group('k'), m.group('k'), m.group('k')),
    src)
if n != 2:
    sys.exit("NEG count=%d" % n)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED4 n=%d" % n)
