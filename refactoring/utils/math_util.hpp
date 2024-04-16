/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			math_util.hpp
Description:	math util

**************************************************************************/

#ifndef MATH_UTIL_H__
#define MATH_UTIL_H__

#include "pch.h"

namespace math_util
{
	/**
	 * \brief Converts Euler rotation to quaternion rotation.
	 * \param euler Enter Euler rotation
	 * \return Results Quaternion rotation
	 */
	inline maxon::Vector4d32 EulerToQuaternion(const maxon::Vector& euler) {

		// pitch(H), roll(-P), yaw(Z)
		const Float sx = sin(-euler.y * 0.5);
		const Float sy = sin(euler.x * 0.5);
		const Float sz = sin(euler.z * 0.5);
		const Float cx = cos(-euler.y * 0.5);
		const Float cy = cos(euler.x * 0.5);
		const Float cz = cos(euler.z * 0.5);
		return maxon::Vector4d32(
			maxon::SafeConvert<Float32>((cz * cy * sx) + (sz * sy * cx)), // x
			maxon::SafeConvert<Float32>((sz * cy * sx) - (cz * sy * cx)), // y
			maxon::SafeConvert<Float32>((cz * sy * sx) - (sz * cy * cx)), // z
			maxon::SafeConvert<Float32>((cz * cy * cx) + (sz * sy * sx)));// w
	}
	/**
	 * \brief Converts Quaternion rotation to euler rotation.
	 * \param quaternion Enter quaternion rotation
	 * \return Results euler rotation
	 */

	inline maxon::Vec3<float> QuaternionToEuler(const std::array<float, 4>& quaternion)
	{
		// pitch(y - axis rotation)
		const Float sinr_cosp = 2.0 * (static_cast<double>(quaternion[3] * quaternion[1]) +
			static_cast<double>(quaternion[0] * quaternion[2]));
		const Float cosr_cosp = 1.0 - (2.0 * (static_cast<double>(quaternion[0] * quaternion[0]) + 
			static_cast<double>(quaternion[1] * quaternion[1])));
		const Float pitch = -atan2(sinr_cosp, cosr_cosp);

		// yaw(z - axis rotation)
		const Float siny_cosp = 2.0 * (static_cast<double>(-quaternion[3] * quaternion[2]) - 
			static_cast<double>(quaternion[0] * quaternion[1]));
		const Float cosy_cosp = 1.0 - (2.0 * (static_cast<double>(quaternion[0] * quaternion[0]) + 
			static_cast<double>(quaternion[2] * quaternion[2])));
		const Float yaw = atan2(siny_cosp, cosy_cosp);

		// roll(x - axis rotation)
		Float roll;
		if (const Float sinp = 2.0 * (static_cast<double>(quaternion[2] * quaternion[1]) - 
			static_cast<double>(quaternion[3] *quaternion[0])); sinp >= 1.0)
		{
			// use 90 degrees if out of range
			roll = -PI05;
		}
		else if (sinp <= -1.0)
		{
			roll = PI05;
		}
		else {
			roll = -asin(sinp);
		}

		// fixing the x rotation, part 1
		if (quaternion[0] * quaternion[0] > 0.5f || quaternion[3] < 0.0f)
		{
			if (quaternion[0] < 0.0f)
			{
				roll = -PI - roll;
			}
			else
			{
				roll = PI * copysign(1.0, quaternion[3]) - roll;
			}
		}
		// fixing the x rotation, part 2
		if (roll > PI05)
		{
			roll = PI - roll;
		}
		else if (roll < -PI05)
		{
			roll = -PI - roll;
		}
		// HPB
		return maxon::Vec3<float>{ maxon::SafeConvert<float>(pitch), maxon::SafeConvert<float>(-roll), maxon::SafeConvert<float>(yaw) };
	}
}

#endif // !MATH_UTIL_H__
