#ifndef VECTOR_H__
#define VECTOR_H__

#include "maxon/apibase.h"
#include "maxon/string.h"
#include "maxon/datatype.h"

namespace maxon
{

template <typename T, Int STRIDE> struct Vec2;
template <typename T, Int STRIDE> struct Vec4;
template <typename T, Int STRIDE> struct Col3;
template <typename T, Int STRIDE> struct Col4;
template <typename T> struct Mat3;
template <typename T> struct SqMat4;

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Vec, "net.maxon.parametrictype.vec");
	MAXON_DECLARATION(ParametricType, Col, "net.maxon.parametrictype.col");
	MAXON_DECLARATION(ParametricType, Mat, "net.maxon.parametrictype.mat");
	MAXON_DECLARATION(ParametricType, SqMat, "net.maxon.parametrictype.sqmat");
}

}

#define MAXON_VECTORMODE

// Include generic versions with arbitrary stride
#include "math/vec.h"
#include "math/col.h"

// Include specialized version with no stride
#define STRIDE 1
#include "math/vec.h"
#include "math/col.h"
#undef STRIDE

#undef MAXON_VECTORMODE

namespace maxon
{

/// @addtogroup MATH
/// @{

/// Single-Precision Vector.
/// A vector contains three components X, Y and Z
using Vector32 = Vec3<Float32, 1>;

/// Double-Precision Vector.
/// A vector contains three components X, Y and Z
using Vector64 = Vec3<Float64, 1>;

/// Vector with the precision of Float.
/// A vector contains three components X, Y and Z
using Vector = Vec3<Float, 1>;

/// 32-bit Int Vector.
/// A vector contains three components X, Y and Z
using IntVector32 = Vec3<Int32, 1>;

/// 64-bit Int Vector.
/// A vector contains three components X, Y and Z
using IntVector64 = Vec3<Int64, 1>;

/// Vector of Int.
/// A vector contains three components X, Y and Z
using IntVector = Vec3<Int, 1>;

/// Single-Precision Color.
/// A color contains three components R, G and B
using Color32 = Col3<Float32, 1>;

/// Double-Precision Color.
/// A color contains three components R, G and B
using Color64 = Col3<Float64, 1>;

/// Color with the precision of Float.
/// A color contains three components R, G and B
using Color = Col3<Float, 1>;

/// Generic arithmetic vector type.
using GenericVector = Vec3<GenericArithmetic, 1>;

/// @}

#ifndef MAXON_COMPILER_GCC
static_assert(std::is_trivially_copyable<Vector>::value, "Vector not trivially copyable.");
#endif

} // namespace maxon

#endif // VECTOR_H__
