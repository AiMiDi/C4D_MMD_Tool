#include "utils/cmt_pmx_vertex_key.hpp"
#include "utils/cmt_sizing_signature.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

namespace
{
void Check(bool condition, const char* message)
{
    if (!condition) throw std::runtime_error(message);
}

libmmd::PMXFile Fixture(libmmd::PMXVertexWeight weightType)
{
    libmmd::PMXFile model;
    libmmd::PMXVertex vertex{};
    vertex.m_position = Eigen::Vector3f(1, 2, 3);
    vertex.m_normal = Eigen::Vector3f::UnitY();
    vertex.m_uv = Eigen::Vector2f(.2f, .4f);
    vertex.m_weightType = weightType;
    vertex.m_boneIndices[0] = 0; vertex.m_boneIndices[1] = 1;
    vertex.m_boneWeights[0] = .25f;
    model.m_vertices.push_back(vertex);
    libmmd::PMXBone bone{};
    bone.m_name = "foot IK"; bone.m_position.setZero(); bone.m_parentBoneIndex = -1;
    bone.m_boneFlag = static_cast<libmmd::PMXBoneFlags>(0x26);
    bone.m_ikTargetBoneIndex = 1; bone.m_ikIterationCount = 40; bone.m_ikLimit = .3f;
    libmmd::PMXIKLink link{};
    link.m_ikBoneIndex = 0; link.m_enableLimit = true;
    link.m_limitMin = Eigen::Vector3f(-1, 0, 0); link.m_limitMax = Eigen::Vector3f::Zero();
    bone.m_ikLinks.push_back(link); model.m_bones.push_back(bone);
    return model;
}
}

int main()
{
    try
    {
        for (auto type : {libmmd::PMXVertexWeight::BDEF1, libmmd::PMXVertexWeight::BDEF2, libmmd::PMXVertexWeight::SDEF})
        {
            auto model = Fixture(type), changed = model;
            const int count = libmmd::GetPMXVertexInfluenceCount(type);
            for (int i = count; i < 4; ++i) changed.m_vertices[0].m_boneIndices[i] = 1234 + i;
            for (int i = type == libmmd::PMXVertexWeight::BDEF1 ? 0 : 1; i < 4; ++i)
                changed.m_vertices[0].m_boneWeights[i] = std::numeric_limits<float>::quiet_NaN();
            Check(cmt::sizing::BuildBindSignature(model, 8.5) == cmt::sizing::BuildBindSignature(changed, 8.5),
                  "Unused PMX weight storage invalidated a binding snapshot");
            Check(cmt_export::MakePMXVertexKey(model.m_vertices[0]) == cmt_export::MakePMXVertexKey(changed.m_vertices[0]),
                  "Unused PMX weight storage changed vertex deduplication");
            changed.m_vertices[0].m_boneIndices[0] = 5;
            Check(cmt::sizing::BuildBindSignature(model, 8.5) != cmt::sizing::BuildBindSignature(changed, 8.5),
                  "An effective bone assignment did not invalidate binding");
        }
        const auto model = Fixture(libmmd::PMXVertexWeight::BDEF2);
        const auto baseline = cmt::sizing::BuildBindSignature(model, 8.5);
        const auto editInvalidates = [&](auto edit) {
            auto changed = model; edit(changed.m_bones[0]);
            Check(cmt::sizing::BuildBindSignature(changed, 8.5) != baseline, "An IK input edit did not invalidate binding");
        };
        editInvalidates([](auto& bone) { ++bone.m_deformDepth; });
        editInvalidates([](auto& bone) { ++bone.m_ikTargetBoneIndex; });
        editInvalidates([](auto& bone) { ++bone.m_ikIterationCount; });
        editInvalidates([](auto& bone) { bone.m_ikLimit += .1f; });
        editInvalidates([](auto& bone) { ++bone.m_ikLinks[0].m_ikBoneIndex; });
        editInvalidates([](auto& bone) { bone.m_ikLinks[0].m_enableLimit = false; });
        editInvalidates([](auto& bone) { bone.m_ikLinks[0].m_limitMin.x() -= .2f; });
        editInvalidates([](auto& bone) { bone.m_ikLinks[0].m_limitMax.x() += .2f; });
        auto changed = model; changed.m_vertices[0].m_boneWeights[0] = .5f;
        Check(cmt_export::MakePMXVertexKey(model.m_vertices[0]) != cmt_export::MakePMXVertexKey(changed.m_vertices[0]),
              "A semantic weight change was lost by deduplication");
        std::cout << "PMX semantic vertex identity and sizing bind signature passed\n";
        return 0;
    }
    catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
