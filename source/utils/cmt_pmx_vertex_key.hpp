#pragma once

#include "libMMD/Model/MMD/PMXFile.h"
#include <cmath>
#include <cstdint>

namespace cmt_export
{
inline uint64_t HashVertexKeyValue(uint64_t seed, uint64_t value)
{
    return seed ^ (value + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2));
}

inline uint64_t HashVertexKeyFloat(uint64_t seed, double value)
{
    return HashVertexKeyValue(seed, static_cast<uint64_t>(static_cast<int64_t>(std::llround(value * 1000000.0))));
}

inline uint64_t MakePMXVertexKey(const libmmd::PMXVertex& vertex)
{
    uint64_t seed = 1469598103934665603ULL;
    for (int i = 0; i < 3; ++i)
    {
        seed = HashVertexKeyFloat(seed, vertex.m_position[i]);
        seed = HashVertexKeyFloat(seed, vertex.m_normal[i]);
    }
    for (int i = 0; i < 2; ++i) seed = HashVertexKeyFloat(seed, vertex.m_uv[i]);
    seed = HashVertexKeyFloat(seed, vertex.m_edgeMag);
    seed = HashVertexKeyValue(seed, static_cast<uint64_t>(vertex.m_weightType));
    for (int i = 0; i < libmmd::GetPMXVertexInfluenceCount(vertex.m_weightType); ++i)
    {
        seed = HashVertexKeyValue(seed, static_cast<uint64_t>(vertex.m_boneIndices[i]));
        seed = HashVertexKeyFloat(seed, libmmd::GetPMXVertexInfluenceWeight(vertex, i));
    }
    if (vertex.m_weightType == libmmd::PMXVertexWeight::SDEF)
        for (int i = 0; i < 3; ++i)
        {
            seed = HashVertexKeyFloat(seed, vertex.m_sdefC[i]);
            seed = HashVertexKeyFloat(seed, vertex.m_sdefR0[i]);
            seed = HashVertexKeyFloat(seed, vertex.m_sdefR1[i]);
        }
    return seed;
}
}
