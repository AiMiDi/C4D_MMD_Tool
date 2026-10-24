#include "libMMD/Model/MMD/MMDMotionSizing.h"
#include "MMDMotionPose.h"
#include "MMDMotionLegs.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "../ik/fixture.h"

using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;

void Switch(libmmd::VMDFile& clip, uint32_t frame, bool enabled)
{
    libmmd::VMDIk key(frame, 1);
    libmmd::VMDIkInfo info;
    std::u16string name;
    libmmd::ConvU8ToU16("左足ＩＫ", name);
    info.m_name.Set(libmmd::ConvertU16ToSjisString(name).c_str());
    info.m_enable = enabled;
    key.m_ikInfos.push_back(info);
    clip.m_iks.push_back(key);
}

int main()
{
    try
    {
        int failures = 0;
        std::cout << std::setprecision(13);
        for (double ratio : {.82, .86, .90, .92, .97, 1.03, 1.07, 1.11})
        for (int scenario = 0; scenario < 10; ++scenario)
        {
            auto sourceModel = Model();
            auto model = sourceModel;
            for (auto& bone : model.m_bones) bone.m_position *= float(ratio);
            for (auto& body : model.m_rigidbodies)
            {
                body.m_shapeSize *= float(ratio);
                body.m_translate *= float(ratio);
            }
            const Rig sourceRig(sourceModel);
            Rig rig(model);
            const auto pairs = LegCollisionPairs(rig);
            if (pairs.empty()) throw std::runtime_error("Fixture needs real leg collision pairs");
            const bool rotated = scenario >= 4;
            const int shape = scenario % 4;
            const Rotation rotation = rotated ? Rotation(Eigen::AngleAxisd(.14, Vector::UnitZ())) : Rotation::Identity();
            libmmd::VMDFile input;
            const uint32_t last = scenario >= 8 ? 2 : 21;
            for (uint32_t frame = 0; frame <= last; ++frame)
            {
                auto center = Key("センター", frame);
                center.m_quaternion = rotation.cast<float>();
                // Author translates the entire model. Temporal correction must
                // neither freeze nor filter this independent original motion.
                center.m_translate = Eigen::Vector3f(float(.025 * frame), 0, float(-.013 * frame));
                input.m_motions.push_back(center);
                for (int side = 0; side < 2; ++side)
                {
                    const std::string name = side ? "右足ＩＫ" : "左足ＩＫ";
                    const int control = rig.Find(name);
                    double height = .7;
                    if (shape == 0) height = frame < 9 ? .70 : frame == 9 ? .742452 : .863678;
                    if (shape == 1) height = frame < 9 ? .863678 : .739916;
                    if (shape == 2) height = frame == 10 ? .737139 : .5;
                    if (shape == 3) height = .72;
                    if (scenario == 8) height = frame == 0 ? .742452 : .863678;
                    if (scenario == 9) height = frame == 0 ? .863678 : .739916;
                    // Stagger the other foot's release/entry to exercise the
                    // mixed prefix, not just equal corrections on both feet.
                    if (side == 1) height = (frame >= 12 && frame <= 15) ? .85 : .69;
                    const Vector bind = sourceModel.m_bones[sourceRig.Find(name)].m_position.cast<double>();
                    const Vector desired(bind.x(), height, 0.);
                    auto key = Key(name, frame);
                    key.m_translate = (rotation.conjugate() * desired - bind).cast<float>();
                    input.m_motions.push_back(key);
                }
            }
            if (shape == 3) { Switch(input, 10, false); Switch(input, 14, true); }
            Options options;
            options.centerOffsets = options.legOffsets = false;
            options.floorContact = options.legAvoidance = true;
            options.floorHeight = .5;
            options.contactDistance = .3;
            options.tolerance = .002;
            options.iterations = 100;
            const Result result = Run(sourceModel, model, input, options);
            if (!result.success) throw std::runtime_error(result.error);
            const Motion before(result.stages[5]), after(result.stages[6]);
            double previous[2] = {0., 0.}, maxStep = 0., peak = 0., leftPeak = 0., leftTotal = 0.;
            const int startFailures = failures;
            for (uint32_t frame = 0; frame <= last; ++frame)
            {
                const Pose a(rig, before, frame), b(rig, after, frame), sourcePose(sourceRig, Motion(input), frame);
                const auto beforeDepth = LegPenetrations(a, pairs, options.collisionMargin);
                const auto afterDepth = LegPenetrations(b, pairs, options.collisionMargin);
                for (size_t pair = 0; pair < pairs.size(); ++pair)
                    if (afterDepth[pair] > std::max(beforeDepth[pair], options.tolerance) + 2.e-7)
                    { ++failures; std::cout << "PAIR_FAIL " << scenario << ' ' << frame << ' ' << pair << '\n'; }
                for (int side = 0; side < 2; ++side)
                {
                    const int control = rig.Find(side ? "右足ＩＫ" : "左足ＩＫ");
                    const int ankle = model.m_bones[control].m_ikTargetBoneIndex;
                    const Vector delta = b.positions[control] - a.positions[control];
                    const double errorBefore = (a.positions[ankle] - a.positions[control]).norm();
                    const double errorAfter = (b.positions[ankle] - b.positions[control]).norm();
                    if (std::hypot(delta.x(), delta.z()) > 2.e-6 ||
                        (a.ikEnabled[control] && errorAfter > errorBefore + options.tolerance + 2.e-7))
                    { ++failures; std::cout << "GUARD_FAIL " << scenario << ' ' << frame << ' ' << side << '\n'; }
                    if (!a.ikEnabled[control] && delta.norm() > 2.e-6)
                    { ++failures; std::cout << "IK_OFF_FAIL " << scenario << ' ' << frame << '\n'; }
                    const double step = std::abs(delta.y() - previous[side]);
                    if (frame > 0 && a.ikEnabled[control])
                    {
                        maxStep = std::max(maxStep, step);
                        if (step > .075 * ratio + 2.e-6)
                        { ++failures; std::cout << "STEP_FAIL ratio=" << ratio << " case=" << scenario << ' ' << frame << ' ' << side << " step=" << step << '\n'; }
                    }
                    if (std::abs(sourcePose.positions[sourceRig.Find(side ? "右足ＩＫ" : "左足ＩＫ")].y() - .5) >= .3 && delta.norm() > 2.e-6)
                    { ++failures; std::cout << "INACTIVE_FAIL " << scenario << ' ' << frame << ' ' << side << '\n'; }
                    peak = std::max(peak, std::abs(delta.y()));
                    if (side == 0) { leftPeak = std::max(leftPeak, std::abs(delta.y())); leftTotal += std::abs(delta.y()); }
                    previous[side] = delta.y();
                    std::cout << "sample," << ratio << ',' << scenario << ',' << frame << ',' << side << ',' << a.positions[control].y()
                              << ',' << delta.y() << ',' << step << ',' << errorBefore << ',' << errorAfter << '\n';
                }
                const int center = rig.Find("センター");
                if ((a.local[center].translation - b.local[center].translation).norm() > 1.e-10 ||
                    a.local[center].rotation.angularDistance(b.local[center].rotation) > 1.e-10)
                { ++failures; std::cout << "AUTHOR_FAIL " << scenario << ' ' << frame << '\n'; }
            }
            if (peak < .05 * ratio) { ++failures; std::cout << "NO_IMPROVEMENT " << scenario << '\n'; }
            if (leftTotal < .05 * ratio) { ++failures; std::cout << "LEFT_NO_IMPROVEMENT " << scenario << '\n'; }
            std::cout << "ratio=" << ratio << " case=" << scenario << " failures=" << failures-startFailures << " max_step=" << maxStep << " peak=" << peak << '\n';
            for (const auto& warning : result.analysis.warnings) std::cout << "warning " << scenario << ' ' << warning << '\n';
        }
        std::cout << "failures=" << failures << '\n';
        return failures ? 1 : 0;
    }
    catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 2; }
}


