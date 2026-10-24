// Drop-in draft for MMDMotionSizingAdvanced.test.cpp's anonymous namespace.
// Call with the standard leg model built by CheckLegPlaybackAndAvoidance.
// No licensed assets or random generation are needed.
void CheckLegReleaseObjectiveFallback(const libmmd::PMXFile& standardLegModel)
{
    auto model = standardLegModel;
    for (auto& bone : model.m_bones)
    {
        if ((static_cast<uint16_t>(bone.m_boneFlag) & 0x20u) != 0)
            bone.m_ikIterationCount = 64;
    }
    // Hip spheres provide a fixed largest depth. The knee pair may increase
    // within tolerance while the largest depth and IK errors remain safe.
    for (const std::string side : {"左", "右"})
    {
        libmmd::PMXRigidbody body{};
        body.m_name = side + "足";
        body.m_boneIndex = Find(model, body.m_name);
        body.m_shape = libmmd::PMXRigidbody::Shape::Sphere;
        body.m_shapeSize = Eigen::Vector3f(1.4f, 0, 0);
        body.m_translate = model.m_bones[body.m_boneIndex].m_position;
        body.m_rotate.setZero();
        body.m_op = libmmd::PMXRigidbody::Operation::Static;
        model.m_rigidbodies.push_back(body);
    }
    for (auto& bone : model.m_bones) bone.m_position *= .1f;
    for (auto& body : model.m_rigidbodies)
    {
        body.m_shapeSize *= .1f;
        body.m_translate *= .1f;
    }
    const Rig rig(model);
    const auto pairs = LegCollisionPairs(rig);
    const int controls[] = {rig.Find("左足ＩＫ"), rig.Find("右足ＩＫ")};
    double length = 0.;
    for (const std::string side : {"左", "右"})
    {
        const auto& hip = model.m_bones[rig.Find(side + "足")].m_position;
        const auto& knee = model.m_bones[rig.Find(side + "ひざ")].m_position;
        const auto& ankle = model.m_bones[rig.Find(side + "足首")].m_position;
        length += (hip - knee).norm() + (knee - ankle).norm();
    }
    const double budget = .04 * length, step = .25 * budget;
    Options options;
    options.tolerance = .1;
    for (bool switchIK : {false, true})
    {
        libmmd::VMDFile motion;
        motion.m_motions.push_back(Key("センター", 0));
        const Vector start[] = {{-.65, 1, 0}, {.65, 1, 0}};
        const Vector end[] = {{-1.4054584358375, 4.4902893386136, .18369513659895},
                              {1.310143212459, 4.9359652953181, 1.7918076183566}};
        for (uint32_t frame = 0; frame < 18; ++frame)
            for (int side = 0; side < 2; ++side)
            {
                const double blend = std::clamp((static_cast<double>(frame) - 5.) / 6., 0., 1.);
                auto key = Key(side ? "右足ＩＫ" : "左足ＩＫ", frame);
                key.m_translate = (.1 * ((1. - blend) * start[side] + blend * end[side])).cast<float>();
                motion.m_motions.push_back(key);
            }
        if (switchIK)
            for (uint32_t frame : {11u, 13u})
            {
                libmmd::VMDIk key(frame, 1);
                libmmd::VMDIkInfo info;
                std::u16string name;
                libmmd::ConvU8ToU16("左足ＩＫ", name);
                info.m_name.Set(libmmd::ConvertU16ToSjisString(name).c_str());
                info.m_enable = frame == 13;
                key.m_ikInfos.push_back(info);
                motion.m_iks.push_back(key);
            }
        auto adjusted = motion;
        Analysis analysis;
        ApplyLegAvoidance(rig, adjusted, options, analysis, nullptr, {});
        const Motion incoming(motion), output(adjusted);
        Vector previous[] = {Vector::Zero(), Vector::Zero()};
        double peakCorrection = 0.;
        for (uint32_t frame = 0; frame < 18; ++frame)
        {
            const Pose before(rig, incoming, frame), after(rig, output, frame);
            const auto inputDepths = LegPenetrations(before, pairs, options.collisionMargin);
            const auto outputDepths = LegPenetrations(after, pairs, options.collisionMargin);
            for (size_t i = 0; i < pairs.size(); ++i)
                Check(outputDepths[i] <= std::max(inputDepths[i], options.tolerance) + 1.e-6,
                      "Release fallback bypassed a leg-pair guard");
            Check(*std::max_element(outputDepths.begin(), outputDepths.end()) <=
                  *std::max_element(inputDepths.begin(), inputDepths.end()) + 2.e-6,
                  "Release fallback increased maximum penetration");
            for (int side = 0; side < 2; ++side)
            {
                const int control = controls[side];
                const int ankle = model.m_bones[control].m_ikTargetBoneIndex;
                const Vector correction = after.positions[control] - before.positions[control];
                peakCorrection = std::max(peakCorrection, correction.norm());
                Check(correction.norm() <= budget + 1.e-6 && std::abs(correction.y()) < 1.e-6,
                      "Release fallback exceeded the planar correction budget");
                if (before.ikEnabled[control])
                {
                    Check((after.positions[ankle] - after.positions[control]).norm() <=
                          (before.positions[ankle] - before.positions[control]).norm() + options.tolerance + 1.e-6,
                          "Release fallback bypassed the foot IK guard");
                    if (frame > 0)
                        Check((correction - previous[side]).norm() <= step + 1.e-6,
                              "Lower zero objective discarded a safe bounded leg release");
                }
                else Check(correction.norm() < 1.e-6, "Disabled IK retained a leg correction");
                previous[side] = correction;
            }
        }
        Check(peakCorrection > step * 1.5, "Release regression was hidden by suppressing all corrections");
    }
}
