libmmd::VMDMotion Key(const std::string& name,uint32_t frame){libmmd::VMDMotion key;std::u16string utf16;libmmd::ConvU8ToU16(name,utf16);key.m_boneName.Set(libmmd::ConvertU16ToSjisString(utf16).c_str());key.m_frame=frame;key.m_quaternion=Eigen::Quaternionf::Identity();for(size_t i=0;i<64;++i)key.m_interpolation[i]=i%16<8?20:107;return key;}
libmmd::PMXFile Model(){
    libmmd::PMXFile model;
    const auto bone = [&](const std::string& name, int parent, const Eigen::Vector3f& position, uint16_t flags) {
        libmmd::PMXBone value{};
        value.m_name = name; value.m_parentBoneIndex = parent; value.m_position = position;
        value.m_boneFlag = static_cast<libmmd::PMXBoneFlags>(flags);
        model.m_bones.push_back(value);
        return static_cast<int>(model.m_bones.size() - 1);
    };
    bone("センター", -1, Eigen::Vector3f::Zero(), 6);
    for (const std::string side : {"左", "右"})
    {
        const float x = side == "左" ? .8f : -.8f;
        const int hip = bone(side + "足", 0, Eigen::Vector3f(x, 8, 0), 2);
        const int knee = bone(side + "ひざ", hip, Eigen::Vector3f(x, 4, -.3f), 2);
        const int ankle = bone(side + "足首", knee, Eigen::Vector3f(x, 0, 0), 2);
        const int goal = bone(side + "足ＩＫ", 0, Eigen::Vector3f(x, 0, 0), 0x26);
        model.m_bones[goal].m_ikTargetBoneIndex = ankle;
        model.m_bones[goal].m_ikIterationCount = 128;
        model.m_bones[goal].m_ikLimit = .3f;
        for (int index : {knee, hip})
        {
            libmmd::PMXIKLink link{}; link.m_ikBoneIndex = index;
            model.m_bones[goal].m_ikLinks.push_back(link);
        }
        libmmd::PMXRigidbody body{};
        body.m_name = side + "ひざ"; body.m_boneIndex = knee;
        body.m_shape = libmmd::PMXRigidbody::Shape::Capsule;
        body.m_shapeSize = Eigen::Vector3f(.35f, 3.2f, 0);
        body.m_translate = Eigen::Vector3f(x, 2, 0); body.m_rotate.setZero();
        body.m_op = libmmd::PMXRigidbody::Operation::Static;
        model.m_rigidbodies.push_back(body);
    }
return model;}
