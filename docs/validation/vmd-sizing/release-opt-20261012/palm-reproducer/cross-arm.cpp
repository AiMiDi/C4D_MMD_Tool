#ifndef PALM_IMPLEMENTATION
#define PALM_IMPLEMENTATION "Constraints-guard.cpp"
#endif
#include PALM_IMPLEMENTATION
#include <iostream>
#include <iomanip>

using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;

void Check(bool condition, const char* message)
{
    if (!condition) throw std::runtime_error(message);
}

libmmd::PMXFile Arms()
{
    libmmd::PMXFile model;
    const auto addBone = [&](const std::string& name, int parent, const Eigen::Vector3f& position) {
        libmmd::PMXBone bone{};
        bone.m_name = name;
        bone.m_parentBoneIndex = parent;
        bone.m_position = position;
        bone.m_boneFlag = static_cast<libmmd::PMXBoneFlags>(6);
        model.m_bones.push_back(bone);
        return static_cast<int>(model.m_bones.size()) - 1;
    };
    const int root = addBone("センター", -1, Eigen::Vector3f::Zero());
    for (const std::string side : {"左", "右"})
    {
        const float height = side == "左" ? 0.f : 3.f;
        const int arm = addBone(side + "腕", root, {0, height, 0});
        const int elbow = addBone(side + "ひじ", arm, {1, height, 0});
        const int wrist = addBone(side + "手首", elbow, {2, height, 0});
        addBone(side + "中指１", wrist, {2.3f, height, 0});
    }
    return model;
}

void CheckCrossArmPalmGuard(libmmd::PMXRigidbody::Shape shape)
{
    auto model = Arms();
    const Rig initialRig(model);
    const Motion empty{libmmd::VMDFile()};
    const Pose initial(initialRig, empty, 0);
    auto shifted = initial;
    const int arm = initialRig.Find("左腕");
    const int wrist = initialRig.Find("左手首");
    const int opposite = initialRig.Find("右手首");

    // Isolate the palm helper at its contract boundary: arm avoidance has
    // completed and rotated the left upper arm 20 degrees downwards.
    shifted.local[arm].rotation = Rotation(Eigen::AngleAxisd(-.3490658503988659, Vector::UnitZ()));
    shifted.Update();

    // Full wrist counterrotation brings this offset body to the right wrist.
    // Without compensation it is clear of all right-arm sampled points.
    libmmd::PMXRigidbody body{};
    body.m_name = "offset left wrist collider";
    body.m_boneIndex = wrist;
    body.m_shape = shape;
    body.m_shapeSize = shape == libmmd::PMXRigidbody::Shape::Box ?
        Eigen::Vector3f(.2f, .4f, .2f) : Eigen::Vector3f(.2f, .8f, 0);
    body.m_translate = model.m_bones[wrist].m_position +
        (shifted.positions[opposite] - shifted.positions[wrist]).cast<float>();
    body.m_rotate.setZero();
    body.m_op = libmmd::PMXRigidbody::Operation::Static;
    model.m_rigidbodies.push_back(body);

    const Rig rig(model);
    const Pose incoming(rig, empty, 0);
    Pose avoided(rig, empty, 0);
    avoided.local[arm].rotation = shifted.local[arm].rotation;
    avoided.Update();
    Options options;
    options.tolerance = .002;
    options.collisionMargin = 0.;
    Analysis analysis;
    const auto effectors = Effectors(rig, rig, options, analysis);
    const std::vector<size_t> bodies{0};
    const auto before = HandPenetrations(avoided, effectors, bodies, options);
    Check(!before.empty(), "Guard has no collision samples");
    Check(*std::max_element(before.begin(), before.end()) < 1.e-7,
        "Fixture starts inside the other arm");

    auto full = avoided;
    full.local[wrist].rotation = full.rotations[model.m_bones[wrist].m_parentBoneIndex].conjugate() *
        incoming.rotations[wrist];
    full.Update();
    const auto fullDepths = HandPenetrations(full, effectors, bodies, options);
    Check(*std::max_element(fullDepths.begin(), fullDepths.end()) > .15,
        "Full compensation did not trigger cross-arm penetration");

    auto result = avoided;
    PreserveAvoidancePalms(result, effectors, bodies, options, incoming.rotations, nullptr);
    const auto after = HandPenetrations(result, effectors, bodies, options);
    const double originalAngle = avoided.rotations[wrist].angularDistance(incoming.rotations[wrist]);
    const double remainingAngle = result.rotations[wrist].angularDistance(incoming.rotations[wrist]);
    std::cout << std::setprecision(12) << "shape=" << int(shape)
              << " full_depth=" << *std::max_element(fullDepths.begin(), fullDepths.end())
              << " guarded_depth=" << *std::max_element(after.begin(), after.end())
              << " initial_angle=" << originalAngle << " remaining_angle=" << remainingAngle << '\n';
    for (size_t i = 0; i < after.size(); ++i)
        Check(after[i] <= std::max(before[i], options.tolerance) + 1.e-8,
            "Palm counterrotation reintroduced opposite-arm penetration");
    Check(remainingAngle > .01 && remainingAngle < originalAngle - .01,
        "Compensation was not partially accepted and limited");
    Check(avoided.local[wrist].rotation.angularDistance(result.local[wrist].rotation) <= .5235987756,
        "Palm correction exceeded 30 degrees");
    for (int bone : {rig.Find("左中指１"), rig.Find("右中指１")})
        Check(avoided.local[bone].rotation.angularDistance(result.local[bone].rotation) < 1.e-10,
            "Compensation changed authored finger rotation");
}

#include "unwritable.cpp.inc"

int main()
{
    try
    {
        CheckUnwritablePalmTracks();
        CheckCrossArmPalmGuard(libmmd::PMXRigidbody::Shape::Box);
        CheckCrossArmPalmGuard(libmmd::PMXRigidbody::Shape::Capsule);
        return 0;
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
