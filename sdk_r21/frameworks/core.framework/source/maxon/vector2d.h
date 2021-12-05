#ifndef VECTOR2D_H__
#define VECTOR2D_H__

#include "maxon/vector.h"

namespace maxon
{
template <typename T> struct Mat2;
}

#define MAXON_VECTORMODE

// Include generic versions with arbitrary stride
#include "math/vec2.h"

// Include specialized version with no stride
#define STRIDE 1
#include "math/vec2.h"
#undef STRIDE

#undef MAXON_VECTORMODE

namespace maxon
{
/// @addtogroup MATH
/// @{

/// Single-Precision Vector.
/// A vector contains two components X and Y
using Vector2d32 = Vec2<Float32, 1>;

/// Double-Precision Vector.
/// A vector contains two components X and Y
using Vector2d64 = Vec2<Float64, 1>;

/// Vector with the precision of Float.
/// A vector contains two components X and Y
using Vector2d = Vec2<Float, 1>;

/// 32-bit Int Vector.
/// A vector contains three components X, Y and Z
using IntVector2d32 = Vec2<Int32, 1>;

/// 32-bit UInt Vector.
/// A vector contains three components X, Y and Z
using UIntVector2d32 = Vec2<UInt32, 1>;

/// 64-bit Int Vector.
/// A vector contains three components X, Y and Z
using IntVector2d64 = Vec2<Int64, 1>;

/// 64-bit UInt Vector.
/// A vector contains three components X, Y and Z
using UIntVector2d64 = Vec2<UInt64, 1>;

/// Vector of Int.
/// A vector contains three components X, Y and Z
using IntVector2d = Vec2<Int, 1>;

/// Generic arithmetic vector type.
using GenericVector2d = Vec2<GenericArithmetic, 1>;

/// @}

#ifndef MAXON_COMPILER_GCC
static_assert(std::is_trivially_copyable<Vector2d>::value, "Vector not trivially copyable.");
#endif

} // namespace maxon

#endif // VECTOR2D_H__
