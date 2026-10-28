import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

old = ("\t\tconst int input_frame = frame - options.lag;\n"
       "\t\tif (input_frame >= 0 && input_frame != options.skip_input_frame)\n"
       "\t\t\tworld.ApplyInputs(input_frame);\n"
       "\t\tworld.Step(kFrameDt * options.dt_scale);\n"
       "\t\tworld.Snapshot(frames[static_cast<size_t>(frame)]);\n")
new = ("\t\tconst int input_frame = frame - options.lag;\n"
       "\t\t// 影子世界的时钟从它被启用的那一帧开始：lag 帧之前不做任何步进（没有输入就没有结果），\n"
       "\t\t// 这样 async(f) 与 sync(f - lag) 才在「同一段输入的同一段步进」上比较。\n"
       "\t\tif (input_frame < 0)\n"
       "\t\t\tcontinue;\n"
       "\t\tif (input_frame != options.skip_input_frame)\n"
       "\t\t\tworld.ApplyInputs(input_frame);\n"
       "\t\tworld.Step(kFrameDt * options.dt_scale);\n"
       "\t\tworld.Snapshot(frames[static_cast<size_t>(frame)]);\n")
if old not in src:
    sys.exit("ANCHOR run")
src = src.replace(old, new, 1)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED7")
