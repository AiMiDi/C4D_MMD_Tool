#include "utils/cmt_bone_execution_plan.hpp"

#include <cstdlib>
#include <iostream>
#include <limits>

namespace
{
	void Require(const bool value, const char* message)
	{
		if (!value)
		{
			std::cerr << message << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	using cmt_runtime::BoneExecutionEntry;
	cmt_runtime::BoneExecutionPlan plan;
	std::vector<BoneExecutionEntry> snapshot{
		{4, 9, 0, true, true},
		{2, 0, 2, false, true},
		{1, 0, 0, false, true},
		{3, 0, 1, false, false},
		{5, 9, 0, false, false}
	};
	Require(plan.Update(snapshot), "initial snapshot must build");
	Require(plan.Layers() == std::vector<std::int32_t>({0, 9}), "only populated layers execute");
	Require(plan.BoneIndices() == std::vector<std::int32_t>({1, 3, 2, 4, 5}), "animation order is layer, append depth, index");
	Require(plan.BonesForLayer(0, false) == std::vector<std::int32_t>({1, 3, 2}), "prephysics layer membership");
	Require(plan.IKBonesForLayer(0, false) == std::vector<std::int32_t>({1, 2}), "IK order remains numeric");
	Require(plan.IKBonesForLayer(9, true) == std::vector<std::int32_t>({4}), "afterphysics IK membership");
	for (int frame = 0; frame < 1000; ++frame)
		Require(!plan.Update(snapshot), "unchanged playback must reuse plan");
	Require(plan.RebuildCount() == 1, "unchanged playback must not rebuild");

	snapshot[1].layer = 9;
	snapshot[1].after_physics = true;
	Require(plan.Update(snapshot), "direct layer/phase edit must rebuild");
	Require(plan.IKBonesForLayer(9, true) == std::vector<std::int32_t>({2, 4}), "updated IK grouping");
	snapshot[0].is_ik = false;
	Require(plan.Update(snapshot), "direct IK flag edit must rebuild");
	Require(plan.IKBonesForLayer(9, true) == std::vector<std::int32_t>({2}), "disabled IK removed from group");
	snapshot[2].append_depth = 3;
	Require(plan.Update(snapshot), "append depth edit must rebuild");
	Require(plan.BonesForLayer(0, false) == std::vector<std::int32_t>({3, 1}), "append edit updates ordering");

	snapshot.push_back({6, std::numeric_limits<std::int32_t>::max(), 0, false, false});
	Require(plan.Update(snapshot), "adding a sparse extreme layer must rebuild");
	Require(plan.Layers().size() == 3, "extreme layers must not allocate empty layer ranges");
	plan.Invalidate();
	Require(plan.Update(snapshot), "explicit topology invalidation must rebuild");
	snapshot.clear();
	Require(plan.Update(snapshot), "deleting all bones must rebuild");
	Require(plan.Layers().empty() && plan.BoneIndices().empty(), "empty scene leaves no stale entries");
	Require(plan.BonesForLayer(0, false).empty(), "deleted layer lookup is empty");
	std::cout << "bone execution plan regression passed\n";
	return EXIT_SUCCESS;
}
