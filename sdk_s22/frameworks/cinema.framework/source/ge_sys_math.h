/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef GE_SYS_MATH_H__
#define GE_SYS_MATH_H__

#include <math.h>
#include "maxon/apibase.h"

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(disable:4805)	// boolean
	#pragma warning(error: 4265)	// non-virtual destructor of virtual classes

	#define __TYPES_READY
#endif

#if defined(MAXON_TARGET_LINUX) || defined (MAXON_TARGET_MACOS)
	#define GCC34T this->
#endif

#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#ifndef NULL
	#define NULL 0
#endif

typedef void* Hndl;
typedef int INT;
typedef unsigned int UINT;

typedef maxon::Bool				Bool;
typedef maxon::Char				Char;
typedef maxon::UChar			UChar;
typedef maxon::Int16			Int16;
typedef maxon::UInt16			UInt16;
typedef maxon::Int32			Int32;
typedef maxon::UInt32			UInt32;
typedef maxon::Int64			Int64;
typedef maxon::UInt64			UInt64;
typedef maxon::Int				Int;
typedef maxon::UInt				UInt;
typedef maxon::Float			Float;
typedef maxon::Float64		Float64;
typedef maxon::Float32		Float32;

//----------------------------------------------------------------------------------------
/// 32 bit unicode (UTF-32) character.
/// @note This is the datatype for a single 32 bit unicode character.
/// @since R17.032
//----------------------------------------------------------------------------------------
typedef maxon::Utf32Char	Utf32Char;

//----------------------------------------------------------------------------------------
/// 16 bit unicode character.
/// @note Complex unicodes can be composed of two individual 16 bit characters.
/// @since R17.032
//----------------------------------------------------------------------------------------
typedef maxon::Utf16Char	Utf16Char;

/// @addtogroup EPSILON
/// @ingroup group_enumeration
/// @{
static const Float EPSILON		= 0.0001_f;		///< @em 0.0001
static const Float EPSILON2		= 0.01_f;			///< @em 1e-2 (@em 0.01)
static const Float EPSILON3		= 0.001_f;		///< @em 1e-3 (@em 0.001)
static const Float EPSILON5		= 1e-5_f;			///< @em 1e-5 (@em 0.00001)
static const Float EPSILON6		= 1e-6_f;			///< @em 1e-6
static const Float EPSILON7		= 1e-7_f;			///< @em 1e-7
static const Float EPSILON8		= 1e-8_f;			///< @em 1e-8
static const Float EPSILON10	= 1e-10_f;		///< @em 1e-10
/// @}

//----------------------------------------------------------------------------------------
/// Gets the minimum of two float values.\n
/// Single-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Float32 FMin(Float32 a, Float32 b)
{
	if (a < b)
		return a;
	return b;
}

//----------------------------------------------------------------------------------------
/// Gets the minimum of two float values.\n
/// Double-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Float64 FMin(Float64 a, Float64 b)
{
	if (a < b)
		return a;
	return b;
}

//----------------------------------------------------------------------------------------
/// Gets the minimum of two integer values.\n
/// Single-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Int32 LMin(Int32 a, Int32 b)
{
	if (a < b)
		return a;
	return b;
}

//----------------------------------------------------------------------------------------
/// Gets the minimum of two integer values.\n
/// Double-precision version on 64-bit systems.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Int VMin(Int a, Int b)
{
	if (a < b)
		return a;
	return b;
}

//----------------------------------------------------------------------------------------
/// Gets the maximum of two float values.\n
/// Single-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Float32 FMax(Float32 a, Float32 b)
{
	if (a < b)
		return b;
	return a;
}

//----------------------------------------------------------------------------------------
/// Gets the maximum of two float values.\n
/// Double-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Float64 FMax(Float64 a, Float64 b)
{
	if (a < b)
		return b;
	return a;
}

//----------------------------------------------------------------------------------------
/// Gets the maximum of two integer values.\n
/// Single-precision version.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Int32 LMax(Int32 a, Int32 b)
{
	if (a < b)
		return b;
	return a;
}

//----------------------------------------------------------------------------------------
/// Gets the maximum of two integer values.\n
/// Double-precision version on 64-bit systems.
/// @param[in] a									The first value.
/// @param[in] b									The second value.
/// @return												The minimum value.
//----------------------------------------------------------------------------------------
inline Int VMax(Int a, Int b)
{
	if (a < b)
		return b;
	return a;
}

//----------------------------------------------------------------------------------------
/// Limits the value of @formatParam{a} between @formatParam{b} and @formatParam{c}.\n
/// Single-precision version.
/// @param[in] a									The value.
/// @param[in] b									The lower bound.
/// @param[in] c									The upper bound.
/// @return												@formatParam{b} if @formatParam{a} < @formatParam{b}, @formatParam{c} if @formatParam{a} > @formatParam{c}, otherwise @formatParam{a}.
//----------------------------------------------------------------------------------------
inline Int32 LCut(Int32 a, Int32 b, Int32 c)
{
	if (a < b)
		return b;
	if (a > c)
		return c;
	return a;
}

//----------------------------------------------------------------------------------------
/// Limits the value of @formatParam{a} between @formatParam{b} and @formatParam{c}.\n
/// Double-precision version on 64-bit systems.
/// @param[in] a									The value.
/// @param[in] b									The lower bound.
/// @param[in] c									The upper bound.
/// @return												@formatParam{b} if @formatParam{a} < @formatParam{b}, @formatParam{c} if @formatParam{a} > @formatParam{c}, otherwise @formatParam{a}.
//----------------------------------------------------------------------------------------
inline Int VCut(Int a, Int b, Int c)
{
	if (a < b)
		return b;
	if (a > c)
		return c;
	return a;
}

//----------------------------------------------------------------------------------------
/// Calculates the sign of a value.
/// @param[in] f									The value.
/// @return												@em 1 if the passed value is @em 0 or positive, otherwise @em -1.
//----------------------------------------------------------------------------------------
template <typename X> inline Int Sign(X f)
{
	if (f < (X)0)
		return -1;
	return 1;
}

//----------------------------------------------------------------------------------------
/// Calculates @formatParam{a} modulo @formatParam{b}.
/// @param[in] a									The dividend.
/// @param[in] b									The divisor.
/// @return												The remainder.
//----------------------------------------------------------------------------------------
template <typename T, typename U> inline T Mod(T a, U b)
{
	return a < 0 ? a - (((a - b + 1) / b) * b) : a % b;
}

#ifndef NOTOK
	#define NOTOK -1
#endif

// Type value ranges, math constants and trigonometric functions into global namespace
#include "c4d_misc/utilities/apibasemath.h"

#endif // GE_SYS_MATH_H__
