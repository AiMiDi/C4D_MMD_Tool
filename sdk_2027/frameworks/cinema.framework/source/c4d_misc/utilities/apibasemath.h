// no header guards... do NOT include directly!

/// @addtogroup group_maxonmath maxon Math
/// @{

using maxon::MINVALUE_FLOAT32;	///< the minimum value a Float32 can represent
using maxon::MAXVALUE_FLOAT32;	///< the maximum value a Float32 can represent

using maxon::MINVALUE_FLOAT64;	///< the minimum value a Float64 can represent
using maxon::MAXVALUE_FLOAT64;	///< the maximum value a Float64 can represent

using maxon::MINVALUE_INT32_FLOAT32;	///< minimum Float32 value that can be represented by Int32 (-0x7FFFFF80). Lower values will results in an overflow
using maxon::MAXVALUE_INT32_FLOAT32;	///< maximum Float32 value that can be represented by Int32 ( 0x7FFFFF80). Higher values will results in an overflow

using maxon::MINVALUE_INT64_FLOAT64;	///< minimum Float64 value that can be represented by Int64 (-0x7ffffffffffffdff). Lower values will results in an overflow
using maxon::MAXVALUE_INT64_FLOAT64;	///< maximum Float64 value that can be represented by Int64 ( 0x7ffffffffffffdff). Higher values will results in an overflow

using maxon::MINRANGE_FLOAT32;	///< 'safe' minimum range for Float32. Guarantees that multiplication of two numbers doesn't produce an overflow
using maxon::MAXRANGE_FLOAT32;	///< 'safe' maximum range for Float32. Guarantees that multiplication of two numbers doesn't produce an overflow

using maxon::MINRANGE_FLOAT64;	///< 'safe' minimum range for Float. Guarantees that multiplication of two numbers doesn't produce an overflow
using maxon::MAXRANGE_FLOAT64;	///< 'safe' maximum range for Float. Guarantees that multiplication of two numbers doesn't produce an overflow

using maxon::MINVALUE_FLOAT;	///< the minimum value a Float can represent
using maxon::MAXVALUE_FLOAT;	///< the maximum value a Float can represent

using maxon::MINRANGE_FLOAT;	///< 'safe' minimum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
using maxon::MAXRANGE_FLOAT;	///< 'safe' maximum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow

/// Class to determine the limits of a datatype. Use LIMIT<type>::MIN or LIMIT<type>::MAX to return the minimum or maximum values that can be represented by the datatype.
/// You can also use the LIMIT<type>::MIN or LIMIT<type>::MAX for integer datatypes (this doesn't work for floating point types though).
using maxon::LIMIT;

#ifndef NOTOK
	using maxon::NOTOK;
#endif

/// floating point constant: PI
using maxon::PI;

/// floating point constant: 1.0 / PI
using maxon::PI_INV;

/// floating point constant: 2.0 * PI
using maxon::PI2;

/// floating point constant: 1.0 / (2.0 * PI)
using maxon::PI2_INV;

/// floating point constant: 0.5 * PI
using maxon::PI05;

/// floating point constant: 1.0 / (0.5 * PI)
using maxon::PI05_INV;

/// floating point constant: 1.5 * PI
static constexpr Float64 PI15			= 4.7123889803846898576939650749193;

/// floating point constant: 1.0 / (1.5 * PI)
static constexpr Float64 PI15_INV	= 0.2122065907891937810251783511634;

/// Clip a floating point number against the lower limit 0 and the upper limit 1. The result will be returned.
using maxon::Clamp01;
using maxon::Sin;
using maxon::Cos;
using maxon::Tan;
using maxon::ATan;
using maxon::ATan2;
using maxon::Exp;
using maxon::Ln;
using maxon::Log10;
using maxon::Log2;
using maxon::Sqrt;
using maxon::Floor;
using maxon::Ceil;

inline Float32 Modf(Float32 val, Float32* intpart) { return modff(val, intpart); }
inline Float64 Modf(Float64 val, Float64* intpart) { return modf(val, intpart); }

using maxon::Pow;
using maxon::Sinh;
using maxon::Cosh;
using maxon::Tanh;
using maxon::FMod;
using maxon::Abs;

/// Calculates the reciprocal value (multiplicative inverse). If the input value is zero, zero will be returned for safety to avoid exceptions.
using maxon::Inverse;

/// Rounds a floating point value
using maxon::Round;

/// Calculates the minimum of two values and return it.
using maxon::Min;

/// Calculates the maximum of two values and return it.
using maxon::Max;

/// Swaps two values. If available, move semantics will be used.
using maxon::Swap;

/// Clips a value against a lower and upper limit. The new value is returned.
using maxon::ClampValue;

/// Clips a value against a lower and upper limit. The new value is returned.
using maxon::Blend;

/// Calculates square of a value/difference of two values
using maxon::Sqr;

/// Calculates arcsine. The input value is clipped for safety to avoid exceptions.
using maxon::ASin;

/// Calculates arccosine. The input value is clipped for safety to avoid exceptions.
using maxon::ACos;

/// Converts float value from degrees to radians.
using maxon::DegToRad;

/// Converts float value from radians to degrees.
using maxon::RadToDeg;


using maxon::SinCos;

/// Safely converts a 32 bit float value into Int32.
/// The resulting value will be clipped against the Int32 boundaries, without raising an exception.
inline Int32 SAFEINT32(Float32 x)
{
	if (x <= MINVALUE_INT32_FLOAT32)
		return LIMIT<Int32>::MIN;
	else if (x >= MAXVALUE_INT32_FLOAT32)
		return LIMIT<Int32>::MAX;
	return Int32(x);
}

/// Safely converts a 64 bit float value into Int32.
/// The resulting value will be clipped against the Int32 boundaries, without raising an exception.
inline Int32 SAFEINT32(Float64 x)
{
	if (x <= (Float64)LIMIT<Int32>::MIN)
		return LIMIT<Int32>::MIN;
	else if (x >= (Float64)LIMIT<Int32>::MAX)
		return LIMIT<Int32>::MAX;
	return Int32(x);
}

/// Safely converts a 32 bit float value into Int64.
/// The resulting value will be clipped against the Int64 boundaries, without raising an exception.
inline Int64 SAFEINT64(Float32 x)
{
	if (x <= MINVALUE_INT32_FLOAT32)
		return (Int64)LIMIT<Int32>::MIN;
	else if (x >= MAXVALUE_INT32_FLOAT32)
		return (Int64)LIMIT<Int32>::MAX;
	return Int64(x);
}

/// Safely converts a 64 bit float value into Int64.
/// The resulting value will be clipped against the Int64 boundaries, without raising an exception
inline Int64 SAFEINT64(Float64 x)
{
	if (x <= MINVALUE_INT64_FLOAT64)
		return LIMIT<Int64>::MIN;
	else if (x >= MAXVALUE_INT64_FLOAT64)
		return LIMIT<Int64>::MAX;
	return Int64(x);
}

/// Safely converts a 64 bit float value into Int.
/// The resulting value will be clipped against the Int boundaries, without raising an exception
inline Int SAFEINT(Float64 x) { return cinema::SAFEINT64(x); }

/// Safely converts a 32 bit float value into Int.
/// The resulting value will be clipped against the Int boundaries, without raising an exception
inline Int SAFEINT(Float32 x) { return cinema::SAFEINT64(x); }

/// Assigns the maximum of two values to the first value.
using maxon::SetMax;

/// Assigns the minimum of two values to the first value.
using maxon::SetMin;

/// @}
