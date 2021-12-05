#ifndef GENERAL_MATH_H__
#define GENERAL_MATH_H__

/// @file
/// Mathematical functions

#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"
#include "maxon/matrix.h"
#include "maxon/matrix2d.h"
#include "maxon/matrix4d.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

//----------------------------------------------------------------------------------------
/// Compare two floating point values.
/// @return												The result is true if the values are identical or nearly identical (the last 3 bits may be different)
//----------------------------------------------------------------------------------------
Bool CompareFloatTolerant(Float32 a, Float32 b);

//----------------------------------------------------------------------------------------
/// Compare two floating point values.
/// @return												The result is true if the values are identical or nearly identical (the last 3 bits may be different)
//----------------------------------------------------------------------------------------
Bool CompareFloatTolerant(Float64 a, Float64 b);

//----------------------------------------------------------------------------------------
/// Tests if a floating point number is valid.
/// @return												True for FP_NORMAL, FP_SUBNORMAL, FP_ZERO and false for FP_NAN, FP_INFINITE.
//----------------------------------------------------------------------------------------
inline Bool CheckFloat(Float32 r)
{
	union { Float32 f; UInt32 u; } val = { r };

	return ((val.u >> 23) & 0xff) != 0xff;
}

//----------------------------------------------------------------------------------------
/// Tests if a floating point number is valid.
/// @return												True for FP_NORMAL, FP_SUBNORMAL, FP_ZERO and false for FP_NAN, FP_INFINITE.
//----------------------------------------------------------------------------------------
inline Bool CheckFloat(Float64 r)
{
	union { Float64 f; UInt64 u; } val = { r };

	return ((~val.u >> 52) & 0x7ff) != 0;
}

/// Repair floating point number.
/// Only NANs and Infinity are corrected - denormalized numbers stay unchanged
inline Float32 RepairFloat(Float32 r)
{
	if (!CheckFloat(r))
		return 0.0f;

	return r;
}

/// Repair floating point number.
/// Only NANs and Infinity are corrected - denormalized numbers stay unchanged
inline Float64 RepairFloat(Float64 r)
{
	if (!CheckFloat(r))
		return 0.0;

	return r;
}

/// calculates the relative position of x in the range [lowerLimit..upperLimit].
/// if x <= lowerLimit the return value is 0.0, if x >= upperLimit it is 1.0, otherwise the relative position: (x - lowerLimit) / (upperLimit - lowerLimit)
inline Float32 BoxStep(Float32 lowerLimit, Float32 upperLimit, Float32 x)
{
	Float32 diff = upperLimit - lowerLimit;
	if (diff == 0.0f)
	{
		if (x < lowerLimit)
			return 0.0f;
		else
			return 1.0f;
	}

	x = (x - lowerLimit) / diff;
	return x < 0.0f ? 0.0f : (x > 1.0f ? 1.0f : x);
}

/// calculates the relative position of x in the range [lowerLimit..upperLimit].
/// if x <= lowerLimit the return value is 0.0, if x >= upperLimit it is 1.0, otherwise the relative position: (x - lowerLimit) / (upperLimit - lowerLimit)
inline Float64 BoxStep(Float64 lowerLimit, Float64 upperLimit, Float64 x)
{
	Float64 diff = upperLimit - lowerLimit;
	if (diff == 0.0)
	{
		if (x < lowerLimit)
			return 0.0;
		else
			return 1.0;
	}
	x = (x - lowerLimit) / diff;
	return x < 0.0 ? 0.0 : (x > 1.0 ? 1.0 : x);
}

/// identical to Boxstep, but with a soft curve instead of linear behaviour in the range of [lowerLimit..upperLimit].
inline Float32 SmoothStep(Float32 lowerLimit, Float32 upperLimit, Float32 x)
{
	if (x <= lowerLimit)
		return 0.0f;

	Float32 diff = upperLimit - lowerLimit;
	if (diff == 0.0f || x >= upperLimit)
		return 1.0f;

	x = (x - lowerLimit) / (upperLimit - lowerLimit);	// normalize to [0,1]

	return x * x * (3.0f - 2.0f * x);
}

/// identical to Boxstep, but with a soft curve instead of linear behaviour in the range of [lowerLimit..upperLimit].
inline Float64 SmoothStep(Float64 lowerLimit, Float64 upperLimit, Float64 x)
{
	if (x <= lowerLimit)
		return 0.0;

	Float64 diff = upperLimit - lowerLimit;
	if (diff == 0.0 || x >= upperLimit)
		return 1.0;

	x = (x - lowerLimit) / (upperLimit - lowerLimit);	// normalize to [0,1]

	return x * x * (3.0 - 2.0 * x);
}

//----------------------------------------------------------------------------------------
/// Calculates the modulo of two floating point values.
/// If the first value is positive, it behaves like a regular C++ modulo.
/// Below zero the results are different though as the modulo continues to operate like in the positive domain:
/// e.g. -1 % 7 = 6 or -8 % 7 = 6.
/// @param[in] a									Positive or negative value.
/// @param[in] b									This value must be positive, otherwise the return value will be zero.
//----------------------------------------------------------------------------------------
inline Float32 Modulo(Float32 a, Float32 b)
{
	if (b <= 0.0f)
		return 0.0f;
	Int32 n = (Int32) (a / b);

	a -= n * b;
	if (a < 0.0f)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Calculates the modulo of two floating point values.
/// If the first value is positive, it behaves like a regular C++ modulo.
/// Below zero the results are different though as the modulo continues to operate like in the positive domain:
/// e.g. -1 % 7 = 6 or -8 % 7 = 6.
/// @param[in] a									Positive or negative value.
/// @param[in] b									This value must be positive, otherwise the return value will be zero.
//----------------------------------------------------------------------------------------
inline Float64 Modulo(Float64 a, Float64 b)
{
	if (b <= 0.0)
		return 0.0;
	Int64 n = (Int64) (a / b);

	a -= n * b;
	if (a < 0.0)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Calculates the modulo of two integer values.
/// If the first value is positive, it behaves like a regular C++ modulo.
/// Below zero the results are different though as the modulo continues to operate like in the positive domain:
/// e.g. -1 % 7 = 6 or -8 % 7 = 6.
/// @param[in] a									Positive or negative value.
/// @param[in] b									This value must be positive, otherwise the return value will be zero.
//----------------------------------------------------------------------------------------
inline Int32 Modulo(Int32 a, Int32 b)
{
	if (b <= 0)
		return 0;
	if (a >= 0)
		return a % b;
	return a - ((a - b + 1) / b) * b;
}

//----------------------------------------------------------------------------------------
/// Calculates the modulo of two integer values.
/// If the first value is positive, it behaves like a regular C++ modulo.
/// Below zero the results are different though as the modulo continues to operate like in the positive domain:
/// e.g. -1 % 7 = 6 or -8 % 7 = 6.
/// @param[in] a									Positive or negative value.
/// @param[in] b									This value must be positive, otherwise the return value will be zero.
//----------------------------------------------------------------------------------------
inline Int64 Modulo(Int64 a, Int64 b)
{
	if (b <= 0)
		return 0;
	if (a >= 0)
		return a % b;
	return a - ((a - b + 1) / b) * b;
}

/// calculates x ^ log2(b).
/// b must be > 0.0
inline Float32 Bias(Float32 b, Float32 x)
{
	return Pow(x, -Log2(b));
}

/// calculates x ^ log2(b)
/// b must be > 0.0
inline Float64 Bias(Float64 b, Float64 x)
{
	return Pow(x, -Log2(b));
}

/// returns Floor for positive values and zero or Ceil for negative values
inline Float32 Truncate(Float32 x)
{
	if (x >= 0.0f)
		return Floor(x);
	else
		return Ceil(x);
}

/// returns Floor for positive values and zero or Ceil for negative values
inline Float64 Truncate(Float64 x)
{
	if (x >= 0.0)
		return Floor(x);
	else
		return Ceil(x);
}

/// @}

} // namespace maxon

#endif // GENERAL_MATH_H__
