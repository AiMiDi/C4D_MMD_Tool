#include "MMD_utility.h"
#include "iconv.h"

namespace mmd {
	inline maxon::Vector4d32 EulerToQuaternion(maxon::Vector& euler) {

		// pitch(H), roll(-P), yaw(Z)
		const Float sx = sin(-euler.y * 0.5);
		const Float sy = sin(euler.x * 0.5);
		const Float sz = sin(euler.z * 0.5);
		const Float cx = cos(-euler.y * 0.5);
		const Float cy = cos(euler.x * 0.5);
		const Float cz = cos(euler.z * 0.5);

		const Float w = (cz * cy * cx) + (sz * sy * sx);
		const Float x = (cz * cy * sx) + (sz * sy * cx);
		const Float y = (sz * cy * sx) - (cz * sy * cx);
		const Float z = (cz * sy * sx) - (sz * cy * cx);

		return maxon::Vector4d32(x, y, z, w);
	}
	inline maxon::Vector QuaternionToEuler(maxon::Vector4d32& quaternion)
	{
		// pitch(y - axis rotation)
		const Float sinr_cosp = 2.0 * (quaternion.w * quaternion.y + quaternion.x * quaternion.z);
		const Float cosr_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.y * quaternion.y));
		const Float pitch = -atan2(sinr_cosp, cosr_cosp);

		// yaw(z - axis rotation)
		const Float siny_cosp = 2.0 * (-quaternion.w * quaternion.z - quaternion.x * quaternion.y);
		const Float cosy_cosp = 1.0 - (2.0 * (quaternion.x * quaternion.x + quaternion.z * quaternion.z));
		const Float yaw = atan2(siny_cosp, cosy_cosp);

		// roll(x - axis rotation)
		Float roll = 0.0;
		const Float sinp = 2.0 * (quaternion.z * quaternion.y - quaternion.w * quaternion.x);
		if (sinp >= 1.0)
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
		if (quaternion.x * quaternion.x > 0.5f || quaternion.w < 0.0f)
		{
			if (quaternion.x < 0.0f)
			{
				roll = -PI - roll;
			}
			else
			{
				roll = PI * copysign(1.0, quaternion.w) - roll;
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
		return maxon::Vector(pitch, -roll, yaw);
	}
	inline Bool UTF8toSJIS(String& strin, char* strout)
	{
		libiconv_t cd = libiconv_open("SHIFT_JIS", "UTF-8");
		iferr_scope_handler{
			libiconv_close(cd);
			return false;
		};
		size_t length_i = strin.GetCStringLen(STRINGENCODING::UTF8) + size_t(1);
		maxon::AutoMem<maxon::Char> inmen = NewMemClear(maxon::Char, length_i) iferr_return;
		strin.GetCString(inmen, length_i, STRINGENCODING::UTF8);
		size_t length_o = length_i * 2;
		char* outbuf = strout;
		char* inbuf = inmen;
		if (libiconv(cd, &inbuf, &length_i, &outbuf, &length_o) == size_t(-1))
		{
			strout = "Null";
			libiconv_close(cd);
			return false;
		}
		libiconv_close(cd);
		return true;
	}
	inline Bool SJIStoUTF8(char* strin, String& strout, Int64 char_length)
	{
		libiconv_t cd = libiconv_open("UTF-8", "SHIFT_JIS");
		iferr_scope_handler{
			strout = String();
			libiconv_close(cd);
			return false;
		};
		if (strin == nullptr)
		{
			strout = String();
			return false;
		}
		size_t length_i = 0;
		if (char_length == -1)
		{
			length_i = strlen(strin) + 1;
		}
		else {
			length_i = char_length;
		}
		size_t length_o = length_i * 2;
		maxon::AutoMem<maxon::Char> outmen = NewMemClear(maxon::Char, length_o) iferr_return;
		char* outbuf = outmen;
		if (libiconv(cd, &strin, &length_i, &outbuf, &length_o) == size_t(-1))
		{
			strout = String();
			libiconv_close(cd);
			return false;
		}
		libiconv_close(cd);
		strout.SetCString(outmen, -1, STRINGENCODING::UTF8);
		return (true);
	}
}