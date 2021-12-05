// no header guards... do NOT include directly!

/// @addtogroup group_maxonmath maxon Math
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

static const Float MINVALUE_FLOAT = MINVALUE_FLOAT64;										///< the minimum value a Float can represent
static const Float MAXVALUE_FLOAT = MAXVALUE_FLOAT64;										///< the maximum value a Float can represent

static const Float MINRANGE_FLOAT = MINRANGE_FLOAT64;										///< 'safe' minimum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow
static const Float MAXRANGE_FLOAT = MAXRANGE_FLOAT64;										///< 'safe' maximum range for Float64. Guarantees that multiplication of two numbers doesn't produce an overflow

/// Class to determine the limits of a datatype. Use LIMIT<type>::Min() or LIMIT<type>::Max() to return the minimum or maximum values that can be represented by the datatype.
/// You can also use the LIMIT<type>::MIN or LIMIT<type>::MAX for integer datatypes (this doesn't work for floating point types though).
template <typename T> class LIMIT
{
};

template<> class LIMIT<Int64>
{
public:
	static const Int64 MIN = -9223372036854775807LL - 1;
	static const Int64 MAX = 9223372036854775807LL;

	static Int64 Min() { return -9223372036854775807LL - 1; }
	static Int64 Max() { return 9223372036854775807LL; }
};

template<> class LIMIT<UInt64>
{
public:
	static const UInt64 MIN = 0;
	static const UInt64 MAX = 0xffffffffffffffffULL;

	static UInt64 Min() { return 0; }
	static UInt64 Max() { return 0xffffffffffffffffULL; }
};

template<> class LIMIT<Int32>
{
public:
	static const Int32 MIN = -2147483647L - 1;
	static const Int32 MAX = 2147483647L;

	static Int32 Min() { return -2147483647L - 1; }
	static Int32 Max() { return 2147483647L; }
};

template<> class LIMIT<UInt32>
{
public:
	static const UInt32 MIN = 0;
	static const UInt32 MAX = 0xffffffffULL;

	static UInt32 Min() { return 0; }
	static UInt32 Max() { return 0xffffffffULL; }
};

template<> class LIMIT<Int16>
{
public:
	static const Int16 MIN = -32767 - 1;
	static const Int16 MAX = 32767;

	static Int16 Min() { return -32767 - 1; }
	static Int16 Max() { return 32767; }
};

template<> class LIMIT<UInt16>
{
public:
	static const UInt16 MIN = 0;
	static const UInt16 MAX = 0xffff;

	static UInt16 Min() { return 0; }
	static UInt16 Max() { return 0xffff; }
};

template<> class LIMIT<Char>
{
public:
	static const Char MIN = -127 - 1;
	static const Char MAX = 127;

	static Char Min() { return -127 - 1; }
	static Char Max() { return  127; }
};

template<> class LIMIT<UChar>
{
public:
	static const UChar MIN = 0;
	static const UChar MAX = 0xff;

	static UChar Min() { return 0; }
	static UChar Max() { return 0xff; }
};

template<> class LIMIT<Float32>
{
public:
	static Float32 Min() { return -3.402823466e+38f; }
	static Float32 Max() { return  3.402823466e+38f; }
};

template<> class LIMIT<Float64>
{
public:
	static Float64 Min() { return -1.7976931348623158e+308; }
	static Float64 Max() { return  1.7976931348623158e+308; }
};

#ifndef NOTOK
	static const Int NOTOK = -1; ///< constant used for special cases
#endif

/// floating point constant: PI
static const Float64 PI			= 3.1415926535897932384626433832795;

/// floating point constant: 1.0 / PI
static const Float64 PI_INV	= 0.31830988618379067153776752674508;

/// floating point constant: 2.0 * PI
static const Float64 PI2			= 6.283185307179586476925286766559;

/// floating point constant: 1.0 / (2.0 * PI)
static const Float64 PI2_INV	= 0.15915494309189533576888376337251;

/// floating point constant: 0.5 * PI
static const Float64 PI05		= 1.5707963267948966192313216916398;

/// Clip a floating point number against the lower limit 0 and the upper limit 1. The result will be returned.
inline Float32 Clamp01(Float32 a) { const Float32 t = a < 0.0f ? 0.0f : a; return t > 1.0f ? 1.0f : t; }

/// Clip a floating point number against the lower limit 0 and the upper limit 1. The result will be returned.
inline Float64 Clamp01(Float64 a) { const Float64 t = a < 0.0 ? 0.0 : a; return t > 1.0 ? 1.0 : t; }

inline Float32 Sin(Float32 val) { return sinf(val); }
inline Float64 Sin(Float64 val) { return sin(val); }

inline Float32 Cos(Float32 val) { return cosf(val); }
inline Float64 Cos(Float64 val) { return cos(val); }

inline Float32 Tan(Float32 val) { return tanf(val); }
inline Float64 Tan(Float64 val) { return tan(val); }

inline Float32 ATan(Float32 val) { return atanf(val); }
inline Float64 ATan(Float64 val) { return atan(val); }

inline Float32 ATan2(Float32 valY, Float32 valX) { return atan2f(valY, valX); }
inline Float64 ATan2(Float64 valY, Float64 valX) { return atan2(valY, valX); }

inline Float32 Exp(Float32 val) { return expf(val); }
inline Float64 Exp(Float64 val) { return exp(val); }

inline Float32 Ln(Float32 val) { return logf(val); }
inline Float64 Ln(Float64 val) { return log(val); }

inline Float32 Log10(Float32 val) { return log10f(val); }
inline Float64 Log10(Float64 val) { return log10(val); }

inline Float32 Log2(Float32 val) { return log2f(val); }
inline Float64 Log2(Float64 val) { return log2(val); }

inline Float32 Sqrt(Float32 val) { return sqrtf(val); }
inline Float64 Sqrt(Float64 val) { return sqrt(val); }

inline Float32 Floor(Float32 val) { return floorf(val); }
inline Float64 Floor(Float64 val) { return floor(val); }

inline Float32 Ceil(Float32 val) { return ceilf(val); }
inline Float64 Ceil(Float64 val) { return ceil(val); }

inline Float32 Modf(Float32 val, Float32* intpart) { return modff(val, intpart); }
inline Float64 Modf(Float64 val, Float64* intpart) { return modf(val, intpart); }

inline Float32 Pow(Float32 v1, Float32 v2) { return powf(v1, v2); }
inline Float64 Pow(Float64 v1, Float64 v2) { return pow(v1, v2); }

inline Float32 Sinh(Float32 val) { return sinhf(val); }
inline Float64 Sinh(Float64 val) { return sinh(val); }

inline Float32 Cosh(Float32 val) { return coshf(val); }
inline Float64 Cosh(Float64 val) { return cosh(val); }

inline Float32 Tanh(Float32 val) { return tanhf(val); }
inline Float64 Tanh(Float64 val) { return tanh(val); }

inline Float32 FMod(Float32 v1, Float32 v2) { return fmodf(v1, v2); }
inline Float64 FMod(Float64 v1, Float64 v2) { return fmod(v1, v2); }

inline Float32 Abs(Float32 val) { return fabsf(val); }
inline Float64 Abs(Float64 val) { return fabs(val); }

/// Calculates the reciprocal value (multiplicative inverse). If the input value is zero, zero will be returned for safety to avoid exceptions.
inline Float32 Inverse(Float32 f) { return (f == 0.0f) ? 0.0f : 1.0f / f; }

/// Calculates the reciprocal value (multiplicative inverse). If the input value is zero, zero will be returned for safety to avoid exceptions.
inline Float64 Inverse(Float64 f) { return (f == 0.0) ? 0.0 : 1.0 / f; }

/// Rounds a floating point value
/// @since R18
inline Float32 Round(Float32 f) { return Floor(f + 0.5f); }

/// Rounds a floating point value
/// @since R18
inline Float64 Round(Float64 f) { return Floor(f + 0.5); }

#ifndef SIZEOF
	/// Calculates the size of a datatype or element.
	#define SIZEOF(x) ((maxon::Int)sizeof(x))
#endif

/// Calculates the absolute value of any data type
template <typename X> inline X Abs(X f) { if (f < 0) return -f; return f; }

/// Calculates the minimum of two values and return it.
template <typename X> inline X Min(X a, X b) { if (a < b) return a; return b; }

/// Calculates the maximum of two values and return it.
template <typename X> inline X Max(X a, X b) { if (a < b) return b; return a; }

/// Swaps two values. If available, move semantics will be used.
template <typename X> inline void Swap(X &a, X &b) { X c(std::move(a)); a = std::move(b); b = std::move(c); }

/// Clips a value against a lower and upper limit. The new value is returned.
template <typename X> inline X ClampValue(X value, X lowerLimit, X upperLimit) { const X t = value < lowerLimit ? lowerLimit : value; return t > upperLimit ? upperLimit : t; }

/// Clips a value against a lower and upper limit. The new value is returned.
inline Float32 Blend(Float32 value1, Float32 value2, Float32 blendValue) { return value1 + (value2 - value1) * blendValue; }
inline Float64 Blend(Float64 value1, Float64 value2, Float64 blendValue) { return value1 + (value2 - value1) * blendValue; }

/// Calculates square difference of two values
template <typename X> inline X Sqr(X a, X b) { X tmp = a-b; return tmp*tmp; }

/// Calculates square of a value
template <typename X> inline X Sqr(X a) { return a*a; }

/// Calculates arcsine. The input value is clipped for safety to avoid exceptions.
inline Float32 ASin(Float32 val) { if (val >= 1.0f) return Float32(PI05); else if (val <= -1.0f) return Float32(-PI05); return asinf(val); }

/// Calculates arcsine. The input value is clipped for safety to avoid exceptions.
inline Float64 ASin(Float64 val) { if (val >= 1.0) return PI05; else if (val <= -1.0) return -PI05; return asin(val); }

/// Calculates arccosine. The input value is clipped for safety to avoid exceptions.
inline Float32 ACos(Float32 val) { if (val >= 1.0f) return 0.0f; else if (val <= -1.0f) return Float32(PI); return acosf(val); }

/// Calculates arccosine. The input value is clipped for safety to avoid exceptions.
inline Float64 ACos(Float64 val) { if (val >= 1.0) return 0.0; else if (val <= -1.0) return PI; return acos(val); }

/// Converts float value from degrees to radians.
/// @since R18
inline Float32 DegToRad(Float32 r)   { return r * Float32(PI / 180.0); }

/// Converts float value from degrees to radians.
/// @since R18
inline Float64 DegToRad(Float64 r)   { return r * (PI / 180.0); }

/// Converts float value from radians to degrees.
/// @since R18
inline Float32 RadToDeg(Float32 r)   { return r * Float32(180.0 / PI); }

/// Converts float value from radians to degrees.
/// @since R18
inline Float64 RadToDeg(Float64 r)   { return r * (180.0 / PI); }

inline void SinCos(Float32 r, Float32& sn, Float32& cs) { sn = Sin(r); cs = Cos(r); }
inline void SinCos(Float64 r, Float64& sn, Float64& cs) { sn = Sin(r); cs = Cos(r); }

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
inline Int SAFEINT(Float64 x) { return SAFEINT64(x); }

/// Safely converts a 32 bit float value into Int.
/// The resulting value will be clipped against the Int boundaries, without raising an exception
inline Int SAFEINT(Float32 x) { return SAFEINT64(x); }

//----------------------------------------------------------------------------------------
/// Assigns the maximum of two values to the first value.
/// @param[in,out] a							First value.
/// @param[in] b									Second value.
//----------------------------------------------------------------------------------------
template <typename T> inline void SetMax(T& a, const T& b)
{
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
template <typename T> inline void SetMin(T& a, const T& b)
{
	if (b < a)
	{
		a = b;
	}
}

/// @}
