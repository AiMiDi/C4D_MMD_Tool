#include "utils/cmt_control_workflow.hpp"
#include <iostream>
#include <cmath>
using namespace cmt::controls;
static bool Near(double a, double b) { return std::abs(a - b) < 1e-7; }
int main()
{
    for (const char *name : {"左親指０", "右人指２", "left_index_2", "middle3_R"})
        if (!IsFingerAlias(name) || ClassifyControl(name).part != Part::Fingers)
            return 1;
    for (const char *name : {"左人指２D", "left_index_2_accessory", "left_ring_cuff", "hair"})
        if (IsFingerAlias(name))
            return 2;
    if (ClassifyControl("Right Shoulder").part != Part::RightArm || ClassifyControl("足ＩＫ").part == Part::LeftLeg ||
        ClassifyControl("左足ＩＫ", true).limb_fk || !ClassifyControl("+左ひじ補助").secondary)
        return 3;
    if (ModeShowsControl(LimbMode::IK, true, false) || ModeShowsControl(LimbMode::FK, false, true) ||
        !ModeShowsControl(LimbMode::Auto, true, true))
        return 4;
    TwoBoneSolution solved;
    if (!SolveTwoBone({0, 0, 0}, {6, 0, 0}, {0, 0, 10}, 5, 5, solved) || !solved.reachable ||
        !Near(solved.joint.x, 3) || !Near(solved.joint.z, 4) || !Near(solved.end.x, 6))
        return 5;
    if (!Near(solved.joint.Length(), 5) || !Near((solved.end - solved.joint).Length(), 5))
        return 6;
    if (!SolveTwoBone({0, 0, 0}, {6, 0, 0}, {0, 0, -10}, 5, 5, solved) || !Near(solved.joint.z, -4))
        return 7;
    if (!SolveTwoBone({0, 0, 0}, {50, 0, 0}, {10, 0, 0}, 5, 5, solved) || solved.reachable || !Near(solved.end.x, 10))
        return 8;
    if (!SolveTwoBone({0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 5, 3, solved) || solved.reachable ||
        !Near(solved.joint.Length(), 5) || !Near((solved.end - solved.joint).Length(), 3))
        return 9;
    if (SolveTwoBone({0, 0, 0}, {1, 1, 1}, {0, 0, 0}, 0, 5, solved))
        return 10;
    // The pole chooses a plane without changing reachable segment lengths.
    for (int i = 0; i < 30; ++i)
    {
        Point3 target{double(i % 7) - 3, double(i % 5) - 2, double(i % 3) + 1};
        if (!SolveTwoBone({1, 2, 3}, target, {8, 9, -10}, 4, 3, solved) ||
            !Near((solved.joint - Point3{1, 2, 3}).Length(), 4) || !Near((solved.end - solved.joint).Length(), 3))
            return 11;
    }
    std::cout << "Classification, control ownership and independent limb-length checks passed\n";
}
