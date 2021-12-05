#ifndef APIBASEMATH_H__
#define APIBASEMATH_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// Basic math definitions.

namespace maxon
{

/// @addtogroup MATH
/// @{

static const Float32 MINVALUE_FLOAT32 = -3.402823466e+38f;							///< the minimum value a Float32 can represent
static const Float32 MAXVALUE_FLOAT32 =  3.402823466e+38f;							///< the maximum value a Float32 can represent

static const Float64 MINVALUE_FLOAT64 = -1.7976931348623158e+308;				///< the minimum value a Float64 can represent
static const Float64 MAXVALUE_FLOAT64 =  1.7976931348623158e+308;				///< the maximum value a Float64 can represent

static const Float32 MINVALUE_INT32_FLOAT32 = -2147483520.0f;						///< minimum Float32 value that can be represented by Int32 (-0x7FFFFF80). Lower values will results in an overflow
static const Float32 MAXVALUE_INT32_FLOAT32	=  2147483520.0f;						///< maximum Float32 value that can be represented by Int32 ( 0x7FFFFF80). Higher values will results in an overflow

static const Float64 MINVALUE_INT64_FLOAT64 = -9223372036854775295.0;		///< minimum Float64 value that can be represented by Int64 (-0x7ffffffffffffdff). Lower values will results in an overflow
static const Float64 MAXVALUE_INT64_FLOAT64 =  9223372036854775295.0;		///< maximum Float64 value that can be represented by Int64 ( 0x7ffffffffffffdff). Higher values will results in an overflow

static const Float32 MINRANGE_FLOAT32	= -1.0e10f;												///< 'safe' minimum range for Float32. Guarantees that multiplication of two numbers doesn't produce an overflow
static const Float32 MAXRANGE_FLOAT32	=  1.0e10f;												///< 'safe' maximum range for Float32. Guarantees that multiplication of two numbers doesn't produce an overflow

static const Float64 MINRANGE_FLOAT64  = -1.0e100;											///< 'safe' minimum range for Float. Guarantees that multiplication of two numbers doesn't produce an overflow
static const Float64 MAXRANGE_FLOAT64	=   1.0e100;											///< 'safe' maximum range for Float. Guarantees that multiplication of two numbers doesn't produce an overflow

#ifdef MAXON_TARGET_SINGLEPRECISION
static const Float MINVALUE_FLOAT = MINVALUE_FLOAT32;										///< the minimum value a Float can represent
static const Float MAXVALUE_FLOAT = MAXVALUE_FLOAT32;										///< the maximum value a Float can represent

static const Float MINRANGE_FLOAT = MINRANGE_FLOAT32;										///< 'safe' minimum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
static const Float MAXRANGE_FLOAT = MAXRANGE_FLOAT32;										///< 'safe' maximum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
#else
static const Float MINVALUE_FLOAT = MINVALUE_FLOAT64;										///< the minimum value a Float can represent
static const Float MAXVALUE_FLOAT = MAXVALUE_FLOAT64;										///< the maximum value a Float can represent

static const Float MINRANGE_FLOAT = MINRANGE_FLOAT64;										///< 'safe' minimum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
static const Float MAXRANGE_FLOAT = MAXRANGE_FLOAT64;										///< 'safe' maximum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
#endif

// stylecheck.naming=false

/// Class to determine the limits of a datatype. Use LIMIT<type>::Min() or LIMIT<type>::Max() to return the minimum or maximum values that can be represented by the datatype.
/// You can also use the LIMIT<type>::MIN or LIMIT<type>::MAX for integer datatypes (this doesn't work for floating point types though).
template <typename T> class LIMIT
{
};

template <> class LIMIT<Int64>
{
public:
	static const Int64 MIN = -9223372036854775807LL - 1;
	static const Int64 MAX = 9223372036854775807LL;

	static Int64 Min() { return -9223372036854775807LL - 1; }
	static Int64 Max() { return 9223372036854775807LL; }
};

template <> class LIMIT<UInt64>
{
public:
	static const UInt64 MIN = 0;
	static const UInt64 MAX = 0xffffffffffffffffULL;

	static UInt64 Min() { return 0; }
	static UInt64 Max() { return 0xffffffffffffffffULL; }
};

template <> class LIMIT<Int32>
{
public:
	static const Int32 MIN = -2147483647L - 1;
	static const Int32 MAX = 2147483647L;

	static Int32 Min() { return -2147483647L - 1; }
	static Int32 Max() { return 2147483647L; }
};

template <> class LIMIT<UInt32>
{
public:
	static const UInt32 MIN = 0;
	static const UInt32 MAX = 0xffffffffULL;

	static UInt32 Min() { return 0; }
	static UInt32 Max() { return 0xffffffffULL; }
};

template <> class LIMIT<Int16>
{
public:
	static const Int16 MIN = -32767 - 1;
	static const Int16 MAX = 32767;

	static Int16 Min() { return -32767 - 1; }
	static Int16 Max() { return 32767; }
};

template <> class LIMIT<UInt16>
{
public:
	static const UInt16 MIN = 0;
	static const UInt16 MAX = 0xffff;

	static UInt16 Min() { return 0; }
	static UInt16 Max() { return 0xffff; }
};

template <> class LIMIT<Char>
{
public:
	static const Char MIN = -127 - 1;
	static const Char MAX = 127;

	static Char Min() { return -127 - 1; }
	static Char Max() { return  127; }
};

template <> class LIMIT<UChar>
{
public:
	static const UChar MIN = 0;
	static const UChar MAX = 0xff;

	static UChar Min() { return 0; }
	static UChar Max() { return 0xff; }
};

template <> class LIMIT<Float32>
{
public:
	static Float32 Min() { return -3.402823466e+38f; }
	static Float32 Max() { return  3.402823466e+38f; }
};

template <> class LIMIT<Float64>
{
public:
	static Float64 Min() { return -1.7976931348623158e+308; }
	static Float64 Max() { return  1.7976931348623158e+308; }
};

#ifndef NOTOK
	static const Int NOTOK = -1; ///< constant used for special cases
#endif

/// floating point constant: PI
static const Float64 PI			   = 3.1415926535897932384626433832795;

/// floating point constant: 1.0 / PI
static const Float64 PI_INV	   = 0.31830988618379067153776752674508;

/// floating point constant: 2.0 * PI
static const Float64 PI2			 = 6.283185307179586476925286766559;

/// floating point constant: 1.0 / (2.0 * PI)
static const Float64 PI2_INV	 = 0.15915494309189533576888376337251;

/// floating point constant: 0.5 * PI
static const Float64 PI05		   = 1.5707963267948966192313216916398;

/// floating point constant: Sqrt(2.0)
static const Float64 SQRT2		 = 1.4142135623730950488016887242097;

/// floating point constant: Sqrt(2.0 * PI)
static const Float64 SQRT_PI2	 = 2.506628274631000502415765284811;

/// floating point constant: 1.0 / Sqrt(2.0)
static const Float64 SQRT2_INV = 0.7071067811865475244008443621049;

/// floating point constant: Sqrt(3.0)
static const Float64 SQRT3		 = 1.7320508075688772935274463415059;

/// floating point constant: Log(2.0)
static const Float64 LOG2			 = 0.69314718055994530941723212145818;

#ifdef MAXON_TARGET_ANDROID
MAXON_ATTRIBUTE_FORCE_INLINE Float32 log2f(Float32 a)
{
	return logf(a) / (Float32)LOG2;
}

MAXON_ATTRIBUTE_FORCE_INLINE Float64 log2(Float64 a)
{
	return log(a) / LOG2;
}
#endif

/// Clip a floating point number against the lower limit 0 and the upper limit 1. The result will be returned.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Clamp01(Float32 a)
{
	const Float32 t = a < 0.0f ? 0.0f : a;
	return t > 1.0f ? 1.0f : t;
}

/// Clip a floating point number against the lower limit 0 and the upper limit 1. The result will be returned.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Clamp01(Float64 a)
{
	const Float64 t = a < 0.0 ? 0.0 : a;
	return t > 1.0 ? 1.0 : t;
}

/// Calculates the sine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Sin(Float32 val) { return sinf(val); }

/// Calculates the sine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Sin(Float64 val) { return sin(val); }

/// Calculates the cosine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Cos(Float32 val) { return cosf(val); }

/// Calculates the cosine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Cos(Float64 val) { return cos(val); }

/// Calculates the tangent of a value. Note that the input needs to be checked for proper range, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Tan(Float32 val) { return tanf(val); }

/// Calculates the tangent of a value. Note that the input needs to be checked for proper range, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Tan(Float64 val) { return tan(val); }

/// Calculates the arcustangens of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 ATan(Float32 val) { return atanf(val); }

/// Calculates the arcustangens of a value.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 ATan(Float64 val) { return atan(val); }

/// Calculates the arcustangens2 of a value.
/// Returns the principal value of the arc tangent of y/x, expressed in radians.
/// To compute the value, the function takes into account the sign of both arguments in order to determine the quadrant.
/// If x is zero, depending on the sign of y +/- PI05 is returned.
/// If x and y are both zero the function returns zero.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 ATan2(Float32 valY, Float32 valX) { return atan2f(valY, valX); }

/// Calculates the arcustangens2 of a value.
/// Returns the principal value of the arc tangent of y/x, expressed in radians.
/// To compute the value, the function takes into account the sign of both arguments in order to determine the quadrant.
/// If x is zero, depending on the sign of y +/- PI05 is returned.
/// If x and y are both zero the function returns zero.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 ATan2(Float64 valY, Float64 valX) { return atan2(valY, valX); }

/// Calculates e^value.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Exp(Float32 val) { return expf(val); }

/// Calculates e^value.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Exp(Float64 val) { return exp(val); }

/// Returns the base-2 exponential function of x, which is 2 raised to the power x: 2x.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Exp2(Float32 val) { return exp2f(val); }

/// Returns the base-2 exponential function of x, which is 2 raised to the power x: 2x.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Exp2(Float64 val) { return exp2(val); }

/// Calculates logarithm of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Ln(Float32 val) { return logf(val); }

/// Calculates logarithm of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Ln(Float64 val) { return log(val); }

/// Calculates logarithm with base 10 of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Log10(Float32 val) { return log10f(val); }

/// Calculates logarithm with base 10 of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Log10(Float64 val) { return log10(val); }

/// Calculates logarithm with base 2 of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Log2(Float32 val) { return log2f(val); }

/// Calculates logarithm with base 2 of a value. Note that the input needs to be positive, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Log2(Float64 val) { return log2(val); }

/// Calculates square root of a value. Note that the input must not be be negative, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Sqrt(Float32 val) { return sqrtf(val); }

/// Calculates square root of a value. Note that the input must not be be negative, so that no exceptions will be generated.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Sqrt(Float64 val) { return sqrt(val); }

/// Rounds to the largest previous integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Floor(Float32 val) { return floorf(val); }

/// Rounds to the largest previous integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Floor(Float64 val) { return floor(val); }

/// Rounds to the smallest following integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Ceil(Float32 val) { return ceilf(val); }

/// Rounds to the smallest following integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Ceil(Float64 val) { return ceil(val); }

/// Rounds to the nearest integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Round(Float32 val) { return roundf(val); }

/// Rounds to the nearest integer number.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Round(Float64 val) { return round(val); }

/// Calculates v1^v2
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Pow(Float32 v1, Float32 v2) { return powf(v1, v2); }

/// Calculates v1^v2
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Pow(Float64 v1, Float64 v2) { return pow(v1, v2); }

/// Calculates hyperbolic sine
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Sinh(Float32 val) { return sinhf(val); }

/// Calculates hyperbolic sine
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Sinh(Float64 val) { return sinh(val); }

/// Calculates hyperbolic cosine
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Cosh(Float32 val) { return coshf(val); }

/// Calculates hyperbolic cosine
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Cosh(Float64 val) { return cosh(val); }

/// Calculates hyperbolic tangent
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Tanh(Float32 val) { return tanhf(val); }

/// Calculates hyperbolic tangent
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Tanh(Float64 val) { return tanh(val); }

/// Calculates floating point modulo
MAXON_ATTRIBUTE_FORCE_INLINE Float32 FMod(Float32 v1, Float32 v2) { return fmodf(v1, v2); }

/// Calculates floating point modulo
MAXON_ATTRIBUTE_FORCE_INLINE Float64 FMod(Float64 v1, Float64 v2) { return fmod(v1, v2); }

/// Calculates the absolute value of a floating point number.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Abs(Float32 val) { return fabsf(val); }

/// Calculates the absolute value of a floating point number.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Abs(Float64 val) { return fabs(val); }

/// Calculates the reciprocal value (multiplicative inverse). If the input value is zero, zero will be returned for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Inverse(Float32 f) { return MAXON_UNLIKELY(f == 0.0f) ? 0.0f : 1.0f / f; }

/// Calculates the reciprocal value (multiplicative inverse). If the input value is zero, zero will be returned for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Inverse(Float64 f) { return MAXON_UNLIKELY(f == 0.0) ? 0.0 : 1.0 / f; }

#ifndef SIZEOF
	/// Calculates the size of a datatype or element.
	#define SIZEOF(x) ((maxon::Int)sizeof(x))
#endif

/// Calculates the absolute value of any data type
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE constexpr X Abs(X f)
{
	return (f < 0) ? -f : f;
}

/// Calculates the minimum of two values and return it.
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE constexpr X Min(X a, X b)
{
	return (a < b) ? a : b;
}

/// Calculates the maximum of two values and return it.
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE constexpr X Max(X a, X b)
{
	return (a < b) ? b : a;
}

/// Swaps two values. If available, move semantics will be used.
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE void Swap(X &a, X &b) { X c(std::move(a)); a = std::move(b); b = std::move(c); }

/// Clips a value against a lower and upper limit. The new value is returned.
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE X ClampValue(X value, X lowerLimit, X upperLimit)
{
	const X t = value < lowerLimit ? lowerLimit : value;
	return t > upperLimit ? upperLimit : t;
}

/// Blends two values. If blendValue is 0.0 value1 is returned, if blendValue is 1.0 value2 is returned. No clipping below 0.0 or 1.0 takes place (in that case use BoxStep).
template <typename X, typename Y> MAXON_ATTRIBUTE_FORCE_INLINE X Blend(const X& value1, const X& value2, Y blendValue) { return X(value1 + (value2 - value1) * blendValue); }

/// Calculates square difference of two values
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE X Sqr(X a, X b) { X tmp = a - b; return tmp * tmp; }

/// Calculates square of a value
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE X Sqr(X a) { return a * a; }

/// Calculates the gamma correction. The input value is clipped to [0.0, 1.0] for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Gamma(Float32 value, Float32 gamma)
{
	return Pow(ClampValue(value, Float32(0.0), Float32(1.0)), Max(gamma, Float32(0.0)));
}

/// Calculates the gamma correction. The input value is clipped to [0.0, 1.0] for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Gamma(Float64 value, Float64 gamma)
{
	return Pow(ClampValue(value, Float64(0.0), Float64(1.0)), Max(gamma, Float64(0.0)));
}

/// Calculates si (the unnormalized sinc function). The input value is checked for 0 to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Si(Float32 val)
{
	if (MAXON_UNLIKELY(val == 0.0f))
		return 1.0f;

	return Sin(val) / val;
}

/// Calculates si (the unnormalized sinc function). The input value is checked for 0 to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Si(Float64 val)
{
	if (MAXON_UNLIKELY(val == 0.0))
		return 1.0;

	return Sin(val) / val;
}


/// Calculates sinc. The input value is checked for 0 to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Sinc(Float32 val)
{
	val *= Float32(PI);

	if (MAXON_UNLIKELY(val == 0.0f))
		return 1.0f;

	return Sin(val) / val;
}

/// Calculates sinc. The input value is checked for 0 to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Sinc(Float64 val)
{
	val *= PI;

	if (MAXON_UNLIKELY(val == 0.0))
		return 1.0;

	return Sin(val) / val;
}


/// Calculates arcsine. The input value is clipped for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 ASin(Float32 val)
{
	if (val >= 1.0f)
		return Float32(PI05);
	else if (val <= -1.0f)
		return Float32(-PI05);
	return asinf(val);
}

/// Calculates arcsine. The input value is clipped for safety to avoid exceptions.
/// @MAXON_ANNOTATION{reflection="net.maxon.ASin"}
MAXON_ATTRIBUTE_FORCE_INLINE Float64 ASin(Float64 val)
{
	if (val >= 1.0)
		return PI05;
	else if (val <= -1.0)
		return -PI05;
	return asin(val);
}

/// Calculates arccosine. The input value is clipped for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float32 ACos(Float32 val)
{
	if (val >= 1.0f)
		return 0.0f;
	else if (val <= -1.0f)
		return Float32(PI);
	return acosf(val);
}

/// Calculates arccosine. The input value is clipped for safety to avoid exceptions.
MAXON_ATTRIBUTE_FORCE_INLINE Float64 ACos(Float64 val)
{
	if (val >= 1.0)
		return 0.0;
	else if (val <= -1.0)
		return PI;
	return acos(val);
}

/// Converts float value from degrees to radians
MAXON_ATTRIBUTE_FORCE_INLINE Float32 DegToRad(Float32 r)   { return r * Float32(PI / 180.0); }

/// Converts float value from degrees to radians
MAXON_ATTRIBUTE_FORCE_INLINE Float64 DegToRad(Float64 r)   { return r * (PI / 180.0); }

/// Converts float value from radians to degrees
MAXON_ATTRIBUTE_FORCE_INLINE Float32 RadToDeg(Float32 r)   { return r * Float32(180.0 / PI); }

/// Converts float value from radians to degrees
MAXON_ATTRIBUTE_FORCE_INLINE Float64 RadToDeg(Float64 r)   { return r * (180.0 / PI); }

/// Calculates both sine and cosine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE void SinCos(Float32 val, Float32& sn, Float32& cs) { sn = Sin(val); cs = Cos(val); }

/// Calculates both sine and cosine of a value.
MAXON_ATTRIBUTE_FORCE_INLINE void SinCos(Float64 val, Float64& sn, Float64& cs) { sn = Sin(val); cs = Cos(val); }

/// Safely converts a 64 bit float value into another scalar value.
/// The resulting value will be clipped against its boundaries, without raising an exception.
template <typename DEST> MAXON_ATTRIBUTE_FORCE_INLINE DEST SafeConvert(Float64 src)
{
	if (src >= (Float64) LIMIT<DEST>::Max())
		return LIMIT<DEST>::Max();
	else if (src <= (Float64) LIMIT<DEST>::Min())
		return LIMIT<DEST>::Min();
	return (DEST) src;
}

/// Safely converts a 32 bit float value into another scalar value.
/// The resulting value will be clipped against its boundaries, without raising an exception.
template <typename DEST> MAXON_ATTRIBUTE_FORCE_INLINE DEST SafeConvert(Float32 src)
{
	if (src >= (Float32) LIMIT<DEST>::Max())
		return LIMIT<DEST>::Max();
	else if (src <= (Float32) LIMIT<DEST>::Min())
		return LIMIT<DEST>::Min();
	return (DEST) src;
}

//----------------------------------------------------------------------------------------
/// Assigns the maximum of two values to the first value.
/// @param[in,out] a							First value.
/// @param[in] b									Second value.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void SetMax(T& a, const typename SFINAEHelper<T>::type& b)
{
	// With the SFINAEHelper the type T is deduced only from the first argument. This helps with code like SetMax(x, 10) for some Int x:
	// Otherwise we would have to write SetMax<Int>(x, 10) or SetMax(x, Int(10)) (when int != Int).
	if (b > a)
	{
		a = b;
	}
}

//----------------------------------------------------------------------------------------
/// Assigns the minimum of two values to the first value.
/// @param[in,out] a							First value.
/// @param[in] b									Second value.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void SetMin(T& a, const typename SFINAEHelper<T>::type& b)
{
	if (b < a)
	{
		a = b;
	}
}

//----------------------------------------------------------------------------------------
/// Calculates the sign of a value.
/// @param[in] f									Value to test.
/// @return												1 if the value is 0 or positive, -1 otherwise.
//----------------------------------------------------------------------------------------
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE Int Sign(X f)
{
	if (f < (X)0)
		return -1;
	return 1;
}

//----------------------------------------------------------------------------------------
/// Calculates the modulo (non-negative remainder of division) value for integer values.
/// It works continuously for negative dividends, e.g. Mod(-1, 9) == 8 and Mod(1, 9) == 1.
/// @param[in] a									Dividend.
/// @param[in] b									Divisor, must be > 0 (positive).
/// @return												Modulo result.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T Mod(T a, T b)
{
	T rem = a % b;
	return MAXON_LIKELY(rem >= 0) ? rem : rem + b;
}

//----------------------------------------------------------------------------------------
/// Returns true if @p x is a power of two, i.e., if it has exactly one bit set.
/// @param[in] x									Value to check.
/// @return												True if @p x is a power of two.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Bool IsPowerOfTwo(UInt32 x)
{
	return (x != 0) && !(x & (x - 1));
}

//----------------------------------------------------------------------------------------
/// Returns true if @p x is a power of two, i.e., if it has exactly one bit set.
/// @param[in] x									Value to check.
/// @return												True if @p x is a power of two.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Bool IsPowerOfTwo(UInt64 x)
{
	return (x != 0) && !(x & (x - 1));
}


//----------------------------------------------------------------------------------------
/// Computes the sum of the given VALUES. The result is stored in the static member @c value.
/// @tparam VALUES								The values to sum.
//----------------------------------------------------------------------------------------
template <Int... VALUES> struct Sum;

template <Int X, Int... Y> struct Sum<X, Y...>
{
	static const Int value = X + Sum<Y...>::value;
};

template <> struct Sum<>
{
	static const Int value = 0;
};


//----------------------------------------------------------------------------------------
/// Computes the bitwise or of the given VALUES. The result is stored in the static member @c value.
/// @tparam T											The type of the values, may be Bool, an integral type or an enum type.
/// @tparam VALUES								The values to combine.
//----------------------------------------------------------------------------------------
template <typename T, T... VALUES> struct Or;

template <typename T, T X, T... Y> struct Or<T, X, Y...>
{
	using IntType = UnderlyingType<T>;
	static const T value = T(IntType(X) | IntType(Or<T, Y...>::value));
};

template <typename T> struct Or<T>
{
	static const T value = T(0);
};

#if 1
/// Major control to define the used coordinate system. So far C4D runs only with left-handed coordinates.
#define COORDINATESYSTEM_LEFT_HANDED
#else
#define COORDINATESYSTEM_RIGHT_HANDED
#endif

/// @}

} // namespace maxon

#endif // APIBASEMATH_H__
