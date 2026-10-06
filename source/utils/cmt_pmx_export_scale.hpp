#pragma once

#include "libMMD/Model/MMD/PMXFile.h"

#include <cmath>
#include <cstdint>
#include <limits>

namespace cmt_export
{
// Managers reconstruct PMX in the model's stored MMD units. The requested
// export scale is C4D units per output MMD unit, so all lengths use this ratio.
inline bool TryPMXLengthScale(const double model_scale, const double export_scale, double& factor)
{
	if (!std::isfinite(model_scale) || model_scale <= 0.0 ||
		!std::isfinite(export_scale) || export_scale <= 0.0)
		return false;
	const double ratio = model_scale / export_scale;
	if (!std::isfinite(ratio) || ratio <= 0.0)
		return false;
	factor = ratio;
	return true;
}

namespace detail
{
template <class File, class Visitor>
bool VisitPMXLengths(File& file, Visitor&& visit)
{
	for (auto& vertex : file.m_vertices)
	{
		if (!visit(vertex.m_position)) return false;
		// Other weight modes do not serialize these optional vectors, which may
		// be uninitialized. Never inspect or modify inactive PMX fields.
		if (vertex.m_weightType == libmmd::PMXVertexWeight::SDEF &&
			(!visit(vertex.m_sdefC) || !visit(vertex.m_sdefR0) || !visit(vertex.m_sdefR1)))
			return false;
	}
	for (auto& bone : file.m_bones)
	{
		if (!visit(bone.m_position)) return false;
		const bool indexed_tail = (static_cast<std::uint16_t>(bone.m_boneFlag) &
			static_cast<std::uint16_t>(libmmd::PMXBoneFlags::TargetShowMode)) != 0;
		if (!indexed_tail && !visit(bone.m_positionOffset)) return false;
	}
	for (auto& morph : file.m_morphs)
	{
		switch (morph.m_morphType)
		{
		case libmmd::PMXMorphType::Position:
			for (auto& offset : morph.m_positionMorph)
				if (!visit(offset.m_position)) return false;
			break;
		case libmmd::PMXMorphType::Bone:
			for (auto& offset : morph.m_boneMorph)
				if (!visit(offset.m_position)) return false;
			break;
		case libmmd::PMXMorphType::Impluse:
			// PMX's translational velocity has length/time units. Angular torque
			// and dimensionless coefficients are not coordinate-length fields.
			for (auto& offset : morph.m_impulseMorph)
				if (!visit(offset.m_translateVelocity)) return false;
			break;
		default:
			break;
		}
	}
	for (auto& rigid : file.m_rigidbodies)
		if (!visit(rigid.m_shapeSize) || !visit(rigid.m_translate)) return false;
	for (auto& joint : file.m_joints)
		if (!visit(joint.m_translate) || !visit(joint.m_translateLowerLimit) ||
			!visit(joint.m_translateUpperLimit)) return false;
	return true;
}
}

inline bool ScalePMXLengths(libmmd::PMXFile& file, const double factor)
{
	if (!std::isfinite(factor) || factor <= 0.0) return false;
	// Validate every serialized length before changing any output section.
	// Double arithmetic also avoids narrowing a valid ratio to float first.
	const bool representable = detail::VisitPMXLengths(file, [factor](const auto& vector)
	{
		for (int axis = 0; axis < 3; ++axis)
		{
			const double value = vector[axis];
			const double scaled = value * factor;
			if (!std::isfinite(scaled) || std::abs(scaled) > std::numeric_limits<float>::max()) return false;
			if (value != 0.0 && static_cast<float>(scaled) == 0.0f) return false;
		}
		return true;
	});
	if (!representable) return false;
	return detail::VisitPMXLengths(file, [factor](auto& vector)
	{
		for (int axis = 0; axis < 3; ++axis)
			vector[axis] = static_cast<float>(static_cast<double>(vector[axis]) * factor);
		return true;
	});
}
}
