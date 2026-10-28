import io, re, sys

p = r"C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\p4-equivalence-v2.cpp"
src = io.open(p, encoding="utf-8", newline="").read()

helper = '''
// 帧间位移统计：用于证明物理真的在演算（否则「0 差异」没有意义）。
struct MotionStats
{
	size_t moved_over_1mm = 0;
	double max_mm = 0.0;
	size_t compared_bodies = 0;
};

MotionStats MeasureMotion(const std::vector<std::uint32_t>& a, const std::vector<std::uint32_t>& b)
{
	MotionStats stats;
	const size_t body_words = 12;
	if (a.size() < body_words || b.size() < body_words)
		return stats;
	const size_t bodies = a.size() / body_words < b.size() / body_words ? a.size() / body_words : b.size() / body_words;
	stats.compared_bodies = bodies;
	for (size_t i = 0; i < bodies; ++i)
	{
		float pa[3];
		float pb[3];
		for (int k = 0; k < 3; ++k)
		{
			std::memcpy(&pa[k], &a[i * body_words + 9 + static_cast<size_t>(k)], sizeof(float));
			std::memcpy(&pb[k], &b[i * body_words + 9 + static_cast<size_t>(k)], sizeof(float));
		}
		const double dx = static_cast<double>(pb[0]) - static_cast<double>(pa[0]);
		const double dy = static_cast<double>(pb[1]) - static_cast<double>(pa[1]);
		const double dz = static_cast<double>(pb[2]) - static_cast<double>(pa[2]);
		const double mm = std::sqrt(dx * dx + dy * dy + dz * dz) * 1000.0;
		if (mm > 1.0)
			++stats.moved_over_1mm;
		if (mm > stats.max_mm)
			stats.max_mm = mm;
	}
	return stats;
}
'''

anchor = "struct WorldOptions\n{"
if anchor not in src:
    sys.exit("ANCHOR_MISS worldoptions")
src = src.replace(anchor, helper + "\n" + anchor, 1)

case = '''	{
		BeginCase("physics-actually-simulates");
		const MotionStats motion = MeasureMotion(sync_frames[0], sync_frames[kFrames - 1]);
		std::printf("NOTE motion compared_bodies=%zu moved_over_1mm=%zu max_mm=%.4f\\n",
			motion.compared_bodies, motion.moved_over_1mm, motion.max_mm);
		CheckInt(static_cast<long long>(motion.compared_bodies), 479, "physics-actually-simulates", "必须比较全部 479 个刚体");
		Check(motion.moved_over_1mm >= 30, "physics-actually-simulates",
			"至少 30 个刚体在 199 帧内位移超过 1 mm，否则物理几乎没演算，等价性断言无意义");
		Check(motion.max_mm > 5.0, "physics-actually-simulates", "最大位移必须超过 5 mm");
	}

'''
anchor2 = '\t{\n\t\tBeginCase("same-cadence-identical-replay");'
if anchor2 not in src:
    sys.exit("ANCHOR_MISS replay")
src = src.replace(anchor2, case + anchor2, 1)

io.open(p, "w", encoding="utf-8", newline="").write(src)
print("PATCHED")
