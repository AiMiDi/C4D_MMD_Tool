/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef GE_MATH_H__
#define GE_MATH_H__

#include "ge_sys_math.h"

#ifndef GCC34T
	#define GCC34T
#endif

typedef UChar PIX;					///< 8-bit integer pixel type.
typedef UChar PIX_C;				///< 8-bit integer pixel type.
typedef UInt16 PIX_W;				///< 16-bit integer pixel type.
typedef Float32 PIX_F;			///< 32-bit float pixel type.

/// @addtogroup group_comparecheckrepair_float Compare/Check/Repair Float
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Checks if two floats are close to each other on a bit basis (rather than a fixed epsilon).\n
/// Single precision version.
/// @param[in] a									A float value.
/// @param[in] b									A float value.
/// @return												@trueIfOtherwiseFalse{a and b are sufficiently close to each other}
//----------------------------------------------------------------------------------------
Bool CompareFloatTolerant(Float32 a, Float32 b);

//----------------------------------------------------------------------------------------
/// Checks if two floats are close to each other on a bit basis (rather than a fixed epsilon).\n
/// Double precision version.
/// @param[in] a									A float value.
/// @param[in] b									A float value.
/// @return												@trueIfOtherwiseFalse{a and b are sufficiently close to each other}
//----------------------------------------------------------------------------------------
Bool CompareFloatTolerant(Float64 a, Float64 b);

//----------------------------------------------------------------------------------------
/// Checks if @formatParam{r} is a valid floating point number.\n
/// Single precision version.
/// @param[in] r									The value to check.
/// @return												@trueIfOtherwiseFalse{@formatParam{r} is a valid floating point number}\n
///																@formatConstant{true} for @em FP_NORMAL, @em FP_SUBNORMAL and @em FP_ZERO.\n
///																@formatConstant{false} for @em FP_NAN, @em FP_INFINITE.
//----------------------------------------------------------------------------------------
inline Bool CheckFloat(Float32 r)
{
	union { Float32 f; UInt32 u; } u = { r };

	return ((u.u >> 23) & 0xff) != 0xff;
}

//----------------------------------------------------------------------------------------
/// Checks if @formatParam{r} is a valid floating point number.\n
/// Double precision version.
/// @param[in] r									The value to check.
/// @return												@trueIfOtherwiseFalse{@formatParam{r} is a valid floating point number}\n
///																@formatConstant{true} for @em FP_NORMAL, @em FP_SUBNORMAL and @em FP_ZERO.\n
///																@formatConstant{false} for @em FP_NAN, @em FP_INFINITE.
//----------------------------------------------------------------------------------------
inline Bool CheckFloat(Float64 r)
{
	union { Float64 f; UInt64 u; } u = { r };

	return ((~u.u >> 52) & 0x7ff) != 0;
}

//----------------------------------------------------------------------------------------
/// Repairs floating point values.\n
/// Single precision version.
/// @warning Only NaN and Infinity are corrected. Denormalized numbers are not.
/// @note Useful when importing other formats where the floating point data is not always valid.
/// @param[in] r									The float value to repair.
/// @return												The repaired value.
//----------------------------------------------------------------------------------------
inline Float32 RepairFloat(Float32 r)
{
	if (!CheckFloat(r))
		return 0.0;

	return r;
}

//----------------------------------------------------------------------------------------
/// Repairs floating point values.\n
/// Double precision version.
/// @warning Only NaNs and Infinity are corrected. Denormalized numbers are not.
/// @note Useful when importing other formats where the floating point data is not always valid.
/// @param[in] r									The float value to repair.
/// @return												The repaired value.
//----------------------------------------------------------------------------------------
inline Float64 RepairFloat(Float64 r)
{
	if (!CheckFloat(r))
		return 0.0;

	return r;
}

/// @}

#define C4D_FOUR_BYTE(x1, x2, x3, x4)			((x1 << 24) | (x2 << 16) | (x3 << 8) | x4)
#define C4D_RESERVE_PRIVATE_TYPE(type, x)	type x

enum _DONTCONSTRUCT
{
	DC			///< Pass this to invoke the no-op constructor.
};

enum _EMPTYCONSTRUCT
{
	EC			///< Pass this to invoke the no-op empty constructor.
};

#include "maxon/vector.h"
#include "maxon/vector2d.h"

static const maxon::ENUM_DONT_INITIALIZE DONT_INITIALIZE = maxon::ENUM_DONT_INITIALIZE::VALUE;

/// Single-Precision Vector.
/// A vector contains three components X, Y and Z
typedef maxon::Vec3<maxon::Float32, 1> Vector32;

/// Double-Precision Vector.
/// A vector contains three components X, Y and Z
typedef maxon::Vec3<maxon::Float64, 1> Vector64;

typedef maxon::Vec3<maxon::Float64, 1> Vector;

typedef maxon::Vec2<maxon::Float64, 1> Vector2d;

typedef maxon::Vec2<maxon::Float64, 1> Vector2d64;

#include "maxon/matrix.h"

// Necessary to import in exactly this order

typedef maxon::Mat3<maxon::Vector64> Matrix64;

typedef maxon::Mat3<maxon::Vector32> Matrix32;

typedef maxon::Mat3<maxon::Vector64> Matrix;

namespace maxon
{
class String;
class Url;
class FormatStatement;
}

maxon::String ToString(const Matrix32& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);
maxon::String ToString(const Vector32& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);
maxon::String ToString(const Matrix64& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);
maxon::String ToString(const Vector64& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);

#endif // GE_MATH_H__
