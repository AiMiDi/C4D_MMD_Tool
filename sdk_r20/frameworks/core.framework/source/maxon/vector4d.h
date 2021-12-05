#ifndef VECTOR4D_H__
#define VECTOR4D_H__

#include "maxon/matrix.h"

namespace maxon
{

#define MAXON_VECTORMODE

// Include generic versions with arbitrary stride
#include "math/vec4.h"
#include "math/col4.h"

// Include specialized version with no stride
#define STRIDE 1
#include "math/vec4.h"
#include "math/col4.h"
#undef STRIDE

#undef MAXON_VECTORMODE

/// @addtogroup MATH
/// @{

/// Single-Precision Vector.
/// A vector contains three components X, Y, Z and W
using Vector4d32 = Vec4<Float32, 1>;

/// Double-Precision Vector.
/// A vector contains three components X, Y, Z and W
using Vector4d64 = Vec4<Float64, 1>;

/// Vector with the precision of Float.
/// A vector contains four components X, Y, Z and W
using Vector4d = Vec4<Float, 1>;

/// 32-bit Int Vector.
/// A vector contains four components X, Y, Z and W
using IntVector4d32 = Vec4<Int32, 1>;

/// 64-bit Int Vector.
/// A vector contains four components X, Y, Z and W
using IntVector4d64 = Vec4<Int64, 1>;

/// Vector of Int.
/// A vector contains four components X, Y, Z and W
using IntVector4d = Vec4<Int, 1>;

/// Single-Precision Color with Alpha.
/// A color contains three components R, G, B and A
using ColorA32 = Col4<Float32, 1>;

/// Double-Precision Color with Alpha.
/// A color contains three components R, G, B and A
using ColorA64 = Col4<Float64, 1>;

/// Color with Alpha with the precision of Float.
/// A color contains four components R, G, B and A
using ColorA = Col4<Float, 1>;

/// Generic arithmetic vector type.
using GenericVector4d = Vec4<GenericArithmetic, 1>;

/// @}

#ifndef MAXON_COMPILER_GCC
static_assert(std::is_trivially_copyable<Vector4d>::value, "Vector not trivially copyable.");
#endif

} // namespace maxon

#endif // VECTOR4D_H__
