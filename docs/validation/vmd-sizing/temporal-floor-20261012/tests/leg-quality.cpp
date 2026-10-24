#include "MMDMotionPose.h"
#include "MMDMotionLegs.h"
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;
std::vector<uint8_t> Read(const std::string& path)
{
    std::ifstream file(std::filesystem::u8path(path), std::ios::binary);
    Require(file.good(), "Missing audit input");
    return {std::istreambuf_iterator<char>(file), {}};
}
int main(int argc, char** argv)
{
    Require(argc == 3, "Expected audit folder and TSV output");
    std::ifstream manifest("S:/tmp/cmt-sizing-migration-assets.txt");
    std::string source, path; std::getline(manifest, source); std::getline(manifest, path);
    if (!path.empty() && path.back() == '\r') path.pop_back();
    libmmd::PMXFile model; auto bytes = Read(path);
    Require(libmmd::ReadPMXFile(&model, bytes.data(), bytes.size()), "PMX parse");
    libmmd::VMDFile files[3];
    for (int stage = 0; stage < 3; ++stage)
    {
        bytes = Read(std::string(argv[1]) + "/stage-" + std::to_string(stage + 4) + ".vmd");
        Require(libmmd::ReadVMDFile(&files[stage], bytes.data(), bytes.size()), "VMD parse");
    }
    const Rig rig(model); const Motion input(files[0]); Options options;
    const auto pairs = LegCollisionPairs(rig);
    const int controls[] = {rig.Find("左足ＩＫ"), rig.Find("右足ＩＫ")};
    double length = 0.;
    for (const std::string side : {"左", "右"})
    {
        const int hip = rig.Find(side + "足"), knee = rig.Find(side + "ひざ"), ankle = rig.Find(side + "足首");
        length += (model.m_bones[hip].m_position - model.m_bones[knee].m_position).norm() +
                  (model.m_bones[knee].m_position - model.m_bones[ankle].m_position).norm();
    }
    const double budget = .04 * length;
    std::ofstream out(argv[2]);
    out << std::setprecision(12) << "stage\tframe\tdepth\tpair_increase\tik_delta\toffset\theight\tstep\tsafe\n";
    int failures = 0;
    for (int stage = 1; stage < 3; ++stage)
    {
        const Motion stageInput(files[stage - 1]);
        const Motion output(files[stage]);
        Vector previous[] = {Vector::Zero(), Vector::Zero()};
        for (uint32_t frame = 0; frame <= input.LastFrame(); ++frame)
        {
            const Pose before(rig, stageInput, frame), after(rig, output, frame);
            const auto original = LegPenetrations(before, pairs, options.collisionMargin);
            const auto corrected = LegPenetrations(after, pairs, options.collisionMargin);
            double increase = -1.e30, ikDelta = -1.e30, distance = 0., height = 0., step = 0.;
            for (size_t pair = 0; pair < pairs.size(); ++pair)
                increase = std::max(increase, corrected[pair] - std::max(original[pair], options.tolerance));
            bool disabledSafe = true, floorPlanarSafe = true;
            for (int side = 0; side < 2; ++side)
            {
                const int control = controls[side], ankle = model.m_bones[control].m_ikTargetBoneIndex;
                const Vector correction = after.positions[control] - before.positions[control];
                distance = std::max(distance, correction.norm()); height = std::max(height, std::abs(correction.y()));
                if (frame) step = std::max(step, (correction - previous[side]).norm());
                previous[side] = correction;
                floorPlanarSafe &= std::hypot(correction.x(), correction.z()) < 1.e-5;
                if (before.ikEnabled[control])
                    ikDelta = std::max(ikDelta, (after.positions[control] - after.positions[ankle]).norm() -
                        (before.positions[control] - before.positions[ankle]).norm());
                else disabledSafe &= correction.norm() < 1.e-5;
            }
            const bool safe = increase <= 1.e-5 && ikDelta <= options.tolerance + 1.e-5 &&
                disabledSafe && (stage == 1 ? distance <= budget + 1.e-5 && height < 1.e-5 : floorPlanarSafe);
            failures += !safe;
            out << stage + 4 << '\t' << frame << '\t' << *std::max_element(corrected.begin(), corrected.end())
                << '\t' << increase << '\t' << ikDelta << '\t' << distance << '\t' << height << '\t' << step << '\t' << safe << '\n';
        }
    }
    std::cout << "leg_quality_failures=" << failures << '\n';
    return failures ? 1 : 0;
}
