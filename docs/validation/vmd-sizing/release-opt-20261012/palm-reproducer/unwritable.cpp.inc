// Include after cross-arm.cpp's Arms()/Check() helpers in the isolated test TU.
libmmd::VMDMotion PalmKey(const std::string& name, uint32_t frame)
{
    libmmd::VMDMotion key;
    std::u16string utf16;
    libmmd::ConvU8ToU16(name, utf16);
    key.m_boneName.Set(libmmd::ConvertU16ToSjisString(utf16).c_str());
    key.m_frame = frame;
    key.m_quaternion = Rotation(Eigen::AngleAxisd(.12, Vector::UnitX())).cast<float>();
    for (size_t i = 0; i < 64; ++i) key.m_interpolation[i] = i % 16 < 8 ? 20 : 107;
    return key;
}

void CheckUnwritablePalmTracks()
{
    for (uint16_t flags : {uint16_t(0x102), uint16_t(0x202), uint16_t(0x402), uint16_t(4)})
        for (bool authoredWrist : {false, true})
        {
            auto model = Arms();
            const int wrist = Rig(model).Find("左手首");
            auto& bone = model.m_bones[wrist];
            bone.m_boneFlag = static_cast<libmmd::PMXBoneFlags>(flags);
            bone.m_appendBoneIndex = 0;
            bone.m_appendWeight = .5f;
            bone.m_fixedAxis = Eigen::Vector3f::UnitX();

            libmmd::VMDFile motion;
            auto center = PalmKey("センター", 10);
            center.m_quaternion = Eigen::Quaternionf::Identity();
            motion.m_motions.push_back(center);
            if (authoredWrist)
            {
                motion.m_motions.push_back(PalmKey("左手首", 0));
                motion.m_motions.push_back(PalmKey("左手首", 10));
            }
            libmmd::PMXRigidbody obstacle{};
            obstacle.m_name = "arm displacement obstacle";
            obstacle.m_boneIndex = -1;
            obstacle.m_shape = libmmd::PMXRigidbody::Shape::Sphere;
            obstacle.m_shapeSize = Eigen::Vector3f(.5f, 0, 0);
            obstacle.m_translate = Eigen::Vector3f(2, .2f, 0);
            obstacle.m_rotate.setZero();
            obstacle.m_op = libmmd::PMXRigidbody::Operation::Static;
            model.m_rigidbodies.push_back(obstacle);

            const Rig rig(model);
            const Pose before(rig, Motion(motion), 0);
            Options options;
            options.avoidance = true;
            options.tolerance = .002;
            options.iterations = 100;
            Analysis analysis;
            const auto effectors = Effectors(rig, rig, options, analysis);
            Check(!effectors.empty(), "Unwritable-wrist fixture skipped all arm effectors");
            auto adjusted = motion;
            Avoid(rig, adjusted, effectors, options, analysis, nullptr, {});
            const Pose after(rig, Motion(adjusted), 0);
            Check((before.positions[wrist] - after.positions[wrist]).norm() > .01,
                "Unwritable-wrist test did not actually displace the arm");

            std::vector<libmmd::VMDMotion> originalKeys, adjustedKeys;
            for (const auto& key : motion.m_motions)
                if (key.m_boneName.ToUtf8String() == "左手首") originalKeys.push_back(key);
            for (const auto& key : adjusted.m_motions)
                if (key.m_boneName.ToUtf8String() == "左手首") adjustedKeys.push_back(key);
            Check(originalKeys.size() == adjustedKeys.size(),
                "Avoidance added or replaced keys on an unwritable wrist");
            for (size_t i = 0; i < originalKeys.size(); ++i)
            {
                const auto& a = originalKeys[i];
                const auto& b = adjustedKeys[i];
                Check(a.m_frame == b.m_frame && a.m_translate == b.m_translate &&
                    a.m_quaternion.coeffs() == b.m_quaternion.coeffs() &&
                    std::equal(std::begin(a.m_interpolation), std::end(a.m_interpolation), std::begin(b.m_interpolation)),
                    "Avoidance modified authored unwritable-wrist keys");
            }
            std::cout << "unwritable_flags=" << flags << " authored=" << authoredWrist
                      << " keys=" << adjustedKeys.size() << " displacement="
                      << (before.positions[wrist] - after.positions[wrist]).norm() << '\n';
        }
}
