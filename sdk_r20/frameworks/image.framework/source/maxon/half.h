#ifndef HALF_H__
#define HALF_H__

#include "maxon/apibase.h"
#include "maxon/string.h"

namespace maxon
{

// TODO: (Anybody) starting with AVX a new instruction is available to convert from float32 to Float16 and vice versa
// search for "vcvtps2ph" under https://software.intel.com/sites/landingpage/IntrinsicsGuide/

extern const UInt32 Mantissa[2048];
extern const UInt16 Offset[64];
extern const UInt32 Exponent[64];
extern const UInt16 Base[512];
extern const UChar	Shift[512];

template <typename FLOAT32TYPE> class HalfFloat
{
	static_assert(sizeof(FLOAT32TYPE) == 4, "FLOAT32TYPE must by sizeof 4.");

	UInt16 _half;

public:
	HalfFloat() : _half(0)
	{
	}

	HalfFloat(const HalfFloat& other) : _half(other._half)
	{
	}

	HalfFloat(HalfFloat&& other) : _half(std::move(other._half))
	{
	}

	MAXON_IMPLICIT HalfFloat(FLOAT32TYPE floatVal)
	{
		union
		{
			FLOAT32TYPE	floatVal;
			UInt32			intVal;
		} in;

		UInt32 n, j;

		in.floatVal = floatVal;
		n = in.intVal;
		j = (n >> 23) & 0x1ff;

		_half = (UInt16)((UInt32)Base[j] + ((n & 0x007fffff) >> Shift[j]));
	}

	MAXON_IMPLICIT HalfFloat(Int intVal) : HalfFloat((FLOAT32TYPE)intVal)
	{
	}

	const HalfFloat& operator = (const HalfFloat& other)
	{
		_half = other._half;
		return *this;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE operator FLOAT32TYPE () const
	{
		union
		{
			FLOAT32TYPE	floatVal;
			UInt32			intVal;
		} out;

		Int n = _half >> 10;
		out.intVal = Mantissa[(_half & 0x3ff) + Offset[n]] + Exponent[n];
		return out.floatVal;
	}

	String ToString(const FormatStatement* formatStatement) const
	{
		Float32 f = *this;
		return FormatString("@", f);
	}
};

}

#endif // HALF_H__
