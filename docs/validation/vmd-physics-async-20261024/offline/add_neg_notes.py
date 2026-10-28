import io, re, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

pattern = re.compile(
    r'(\t\tBeginCase\("negative-(?P<kind>dt|substeps)-changed-detected"\);\n)'
    r'.*?'
    r'(\t\tCheck\(mismatched > 0, "negative-(?P=kind)-changed-detected", [^\n]*\);\n)',
    re.S)

def repl(m):
    kind = m.group('kind')
    opt = 'options.dt_scale = 1.5f;' if kind == 'dt' else 'options.sub_steps = 2;'
    label = '改变 dt 必须导致逐位不等' if kind == 'dt' else '改变 substeps 必须导致逐位不等'
    return (
        '\t\tBeginCase("negative-%s-changed-detected");\n'
        '\t\tWorldOptions options;\n'
        '\t\toptions.lag = 1;\n'
        '\t\t%s\n'
        '\t\tconst FrameSnapshots changed = Run(pmx_path, options);\n'
        '\t\tsize_t compared = 0;\n'
        '\t\tconst size_t mismatched = changed.size() == static_cast<size_t>(kFrames)\n'
        '\t\t\t? CompareDelayed(sync_frames, changed, options.lag, &compared)\n'
        '\t\t\t: static_cast<size_t>(-1);\n'
        '\t\tif (changed.size() == static_cast<size_t>(kFrames))\n'
        '\t\t{\n'
        '\t\t\tconst MotionStats drift = MeasureMotion(sync_frames[static_cast<size_t>(kFrames - 1 - options.lag)], changed[static_cast<size_t>(kFrames - 1)]);\n'
        '\t\t\tstd::printf("NOTE %s-changed drift_bodies_over_1mm=%%zu max_mm=%%.4f compared=%%zu mismatched=%%zu\\n",\n'
        '\t\t\t\tdrift.moved_over_1mm, drift.max_mm, compared, mismatched);\n'
        '\t\t}\n'
        '\t\tCheck(mismatched > 0, "negative-%s-changed-detected", "%s");\n'
    ) % (kind, opt, kind, kind, label)

src, n = pattern.subn(repl, src)
if n != 2:
    sys.exit("NEG_PATCH count=%d" % n)

if 'bodies > 479' not in src:
    src = src.replace('bodies > kBodyCount', 'bodies > 479')

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED2 count=%d" % n)
