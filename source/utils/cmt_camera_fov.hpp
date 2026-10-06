#pragma once

#include <cmath>
#include <cstdint>

namespace cmt_camera_fov
{
	constexpr double kPi = 3.141592653589793238462643383279502884;
	constexpr double kDegreesToRadians = kPi / 180.0;

	constexpr double DegreesToRadians(double degrees)
	{
		return degrees * kDegreesToRadians;
	}

	inline bool IsValidRadians(double radians)
	{
		return std::isfinite(radians) && radians > 0.0 && radians < kPi;
	}

	inline bool ToVmdDegrees(double radians, uint32_t& degrees)
	{
		if (!IsValidRadians(radians))
			return false;
		// VMD stores whole degrees. Round instead of truncating a float32 import
		// such as 45 degrees to 44 when it is converted back from radians.
		const auto rounded = std::llround(radians / kDegreesToRadians);
		if (rounded <= 0 || rounded >= 180)
			return false;
		degrees = static_cast<uint32_t>(rounded);
		return true;
	}
}
