#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>

namespace cmt_motion_validation
{

// Offsets are integral VMD frames. Reject fractions so bones, morphs, model
// visibility, IK keys, and clip metadata cannot quantize the same offset apart.
inline bool IsFrameOffsetValid(const double offset)
{
	return std::isfinite(offset)
		&& std::trunc(offset) == offset
		&& offset >= static_cast<double>(std::numeric_limits<std::int32_t>::min())
		&& offset <= static_cast<double>(std::numeric_limits<std::int32_t>::max());
}

inline bool TryAnimationFrame(const std::uint32_t source_frame, const double offset, std::int32_t& result)
{
	if (!IsFrameOffsetValid(offset))
		return false;
	const double shifted = static_cast<double>(source_frame) + offset;
	if (shifted < static_cast<double>(std::numeric_limits<std::int32_t>::min())
		|| shifted > static_cast<double>(std::numeric_limits<std::int32_t>::max()))
		return false;
	result = static_cast<std::int32_t>(std::max(0.0, shifted));
	return true;
}

inline bool TryExportFrame(const std::int32_t source_frame, const double offset, std::uint32_t& result)
{
	if (!IsFrameOffsetValid(offset))
		return false;
	const double shifted = static_cast<double>(source_frame) + offset;
	if (shifted < static_cast<double>(std::numeric_limits<std::int32_t>::min())
		|| shifted > static_cast<double>(std::numeric_limits<std::int32_t>::max()))
		return false;
	result = static_cast<std::uint32_t>(std::max(0.0, shifted));
	return true;
}

// Match C4D BaseTime::GetFrame while validating before its Int32 narrowing.
inline bool TryDocumentFrame(const double numerator, const double denominator, const double fps, std::int32_t& result)
{
	if (!std::isfinite(numerator) || !std::isfinite(denominator) || !std::isfinite(fps)
		|| std::floor(denominator) < 1.0 || fps <= 0.0)
		return false;
	const double frame = std::floor(numerator * fps) / std::floor(denominator);
	if (!std::isfinite(frame) || frame < static_cast<double>(std::numeric_limits<std::int32_t>::min())
		|| frame > static_cast<double>(std::numeric_limits<std::int32_t>::max()))
		return false;
	result = static_cast<std::int32_t>(frame);
	return true;
}

inline bool IsPositionValid(const std::array<double, 3>& position, const double scale_ratio)
{
	if (!std::isfinite(scale_ratio) || scale_ratio <= 0.0)
		return false;
	for (const double value : position)
	{
		const double scaled = value * scale_ratio;
		if (!std::isfinite(value) || !std::isfinite(scaled)
			|| std::abs(scaled) > static_cast<double>(std::numeric_limits<float>::max()))
			return false;
	}
	return true;
}

inline bool IsQuaternionValid(const std::array<double, 4>& quaternion)
{
	bool nonzero = false;
	for (const double value : quaternion)
	{
		if (!std::isfinite(value))
			return false;
		nonzero = nonzero || value != 0.0;
	}
	return nonzero;
}

}
