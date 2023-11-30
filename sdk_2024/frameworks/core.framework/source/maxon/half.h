#ifndef HALF_H__
#define HALF_H__

#include "maxon/datatype.h"

namespace maxon
{

// TODO: (Anybody) starting with AVX a new instruction is available to convert from float32 to Float16 and vice versa
// search for "vcvtps2ph" under https://software.intel.com/sites/landingpage/IntrinsicsGuide/

extern const UInt32 Mantissa[2048];
extern const UInt16 Offset[64];
extern const UInt32 Exponent[64];
extern const UInt16 Base[512];
extern const UChar	Shift[512];

class HalfFloat
{
public:
	HalfFloat() : _half(0)
	{
	}

	MAXON_IMPLICIT HalfFloat(Float32 val)
	{
		union
		{
			Float32	floatVal;
			UInt32 intVal;
		} in;

		UInt32 n, j;

		in.floatVal = val;
		n = in.intVal;
		j = (n >> 23) & 0x1ff;

		_half = (UInt16)((UInt32)Base[j] + ((n & 0x007fffff) >> Shift[j]));
	}

	MAXON_IMPLICIT HalfFloat(Int val)
		: HalfFloat(Float32(val))
	{
	}

	MAXON_IMPLICIT HalfFloat(Int32 val)
		: HalfFloat(Float32(val))
	{
	}
	MAXON_IMPLICIT HalfFloat(Float val)
		: HalfFloat(Float32(val))
	{
	}

	// causes ambiguity default constructor of Vec4
	//	MAXON_IMPLICIT HalfFloat(Int intVal) : HalfFloat((Float32)intVal)
	//	{
	//	}

	MAXON_ATTRIBUTE_FORCE_INLINE operator Float32() const
	{
		union
		{
			Float32	floatVal;
			UInt32 intVal;
		} out;

		Int n = _half >> 10;
		out.intVal = Mantissa[(_half & 0x3ff) + Offset[n]] + Exponent[n];
		return out.floatVal;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE HalfFloat operator-() const
	{
		HalfFloat out = *this;
		out._half ^= 1 << 15; // flip the sign bit
		return out;
	}

	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		Float32 f = *this;
		return FormatString("@", f);
	}

	UInt16 GetBits() const
	{
		return _half;
	}

	MAXON_OPERATOR_EQUALITY(HalfFloat, _half);

	Bool operator <(const HalfFloat& other) const
	{
		return CmpValue() < other.CmpValue();
	}

	MAXON_OPERATOR_INEQUALITY(HalfFloat);

	HashInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_half);
	}

	static constexpr Bool TriviallyHashable() { return true; }

private:
	UInt16 CmpValue() const
	{
		// For negative numbers the mask is 0xffff, otherwise 0x8000.
		const UInt16 mask = UInt16(-Int16(_half >> 15)) | UInt16(0x8000);
		// By xoring _half with mask we get a correct ordering of the float16
		// values using ordinary UInt16 comparison (except NaN values).
		return _half ^ mask;
	}

	UInt16 _half;
};

// stylecheck.naming=false
template <> class LIMIT<HalfFloat>
{
public:
	static constexpr Float32 MIN = -6.55e+4f;
	static constexpr Float32 MAX = 6.55e+4f;
};

template <> struct IsZeroInitialized<HalfFloat> : public std::true_type
{
};

MAXON_DATATYPE(HalfFloat, "float16");

#include "half1.hxx"
#include "half2.hxx"

}

#endif // HALF_H__
