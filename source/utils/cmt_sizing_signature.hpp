#pragma once

#include "libMMD/Model/MMD/PMXFile.h"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

namespace cmt { namespace sizing
{
// Compare solver inputs, not transient object dirty counters or unused PMX
// storage slots. Ordinary playback must not invalidate the binding snapshot.
inline std::string BuildBindSignature(const libmmd::PMXFile& model, double scale)
{
    std::ostringstream out;
    out.imbue(std::locale::classic());
    out << std::setprecision(17) << scale << ' ' << model.m_bones.size() << ' ' << model.m_vertices.size() << '\n';
    for (const auto& bone : model.m_bones)
    {
        const auto flags = static_cast<uint16_t>(bone.m_boneFlag);
        out << bone.m_name.size() << ':' << bone.m_name << ' ' << bone.m_position.transpose() << ' '
            << bone.m_parentBoneIndex << ' ' << flags << ' ' << bone.m_deformDepth;
        if ((flags & 0x400u) != 0) out << ' ' << bone.m_fixedAxis.transpose();
        if ((flags & 0x300u) != 0) out << ' ' << bone.m_appendBoneIndex << ' ' << bone.m_appendWeight;
        if ((flags & 0x20u) != 0)
        {
            out << ' ' << bone.m_ikTargetBoneIndex << ' ' << bone.m_ikIterationCount << ' '
                << bone.m_ikLimit << ' ' << bone.m_ikLinks.size();
            for (const auto& link : bone.m_ikLinks)
            {
                out << ' ' << link.m_ikBoneIndex << ':' << static_cast<int>(link.m_enableLimit);
                if (link.m_enableLimit) out << ' ' << link.m_limitMin.transpose() << ' ' << link.m_limitMax.transpose();
            }
        }
        out << '\n';
    }
    for (const auto& vertex : model.m_vertices)
    {
        out << vertex.m_position.transpose() << ' ' << static_cast<int>(vertex.m_weightType);
        for (int i = 0; i < libmmd::GetPMXVertexInfluenceCount(vertex.m_weightType); ++i)
            out << ' ' << vertex.m_boneIndices[i] << ':' << libmmd::GetPMXVertexInfluenceWeight(vertex, i);
        out << '\n';
    }
    for (const auto& body : model.m_rigidbodies)
        out << body.m_name.size() << ':' << body.m_name << ' ' << body.m_boneIndex << ' '
            << static_cast<int>(body.m_shape) << ' ' << static_cast<int>(body.m_op) << ' '
            << body.m_shapeSize.transpose() << ' ' << body.m_translate.transpose() << ' ' << body.m_rotate.transpose() << '\n';
    return out.str();
}
}}
