import io, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

old = ("\tif (compared)\n"
       "\t\t*compared = count;\n"
       "\treturn mismatched;\n")
new = ("\tif (compared)\n"
       "\t\t*compared = count;\n"
       "\treturn mismatched;\n")
if old not in src:
    sys.exit("ANCHOR compared")

old2 = ("\tfor (int frame = lag; frame < kFrames; ++frame)\n"
        "\t{\n"
        "\t\tmismatched += CompareBitExact(sync_frames[static_cast<size_t>(frame - lag)], async_frames[static_cast<size_t>(frame)]);\n"
        "\t\t++count;\n"
        "\t}\n")
new2 = ("\tfor (int frame = lag; frame < kFrames; ++frame)\n"
        "\t{\n"
        "\t\tconst size_t diff = CompareBitExact(sync_frames[static_cast<size_t>(frame - lag)], async_frames[static_cast<size_t>(frame)]);\n"
        "\t\tif (diff != 0 && g_first_diff_frame < 0)\n"
        "\t\t\tg_first_diff_frame = frame;\n"
        "\t\tmismatched += diff;\n"
        "\t\t++count;\n"
        "\t}\n")
if old2 not in src:
    sys.exit("ANCHOR loop")
src = src.replace(old2, new2, 1)

src = src.replace("\nint g_cases = 0;", "\nint g_cases = 0;\nint g_first_diff_frame = -1;", 1)

old3 = '\t\tstd::printf("NOTE delayed-by-one-frame compared=%zu mismatched=%zu\\n", compared, mismatched);'
new3 = ('\t\tstd::printf("NOTE delayed-by-one-frame compared=%zu mismatched=%zu first_diff_frame=%d\\n",\n'
        '\t\t\tcompared, mismatched, g_first_diff_frame);\n'
        '\t\tg_first_diff_frame = -1;')
if old3 not in src:
    sys.exit("ANCHOR note3")
src = src.replace(old3, new3, 1)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED6")
