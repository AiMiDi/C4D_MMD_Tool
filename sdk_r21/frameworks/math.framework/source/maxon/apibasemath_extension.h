#ifndef APIBASEMATH_EXTENSION_H__
#define APIBASEMATH_EXTENSION_H__

#include "maxon/scalar_extension.h"

//----------------------------------------------------------------------------------------------------
/// Useful apibasemath extensions.
//----------------------------------------------------------------------------------------------------
namespace maxon
{
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_float<T> Fract(T value) { return value - Floor(value); }
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_float<T> Invert(T value) { return T(1.0f) - value; }

// Custom ClampValue function since we got problems with the original function calls during compile. Enable only for scalar values.
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_scalar<T> ClampValueCustom(T value, T lowerLimit, T upperLimit)
{
	const T t = value < lowerLimit ? lowerLimit : value;
	return t > upperLimit ? upperLimit : t;
}

// Custom Min and Max functions since we got problems with the original function calls during compile. Enable only for scalar values.
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_scalar<T> MinCustom(T a, T b) { return (a < b) ? a : b; }
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_scalar<T> MaxCustom(T a, T b) { return (a < b) ? b : a; }

// Custom Sign function since we got ambiguous calls during compile. Enable only for scalar values.
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_scalar<T> SignNoTemplate(T value) 
{ 
	if (value < T())
		return T(-1);
	else if (value > T())
		return T(1);
	return T();
}

// Mod that is enabled for Integral types. We call it FMod, since for some reason Mod and FMod are different functions :(.
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_integral<T> FMod(T a, T b) { return MAXON_LIKELY(b != T()) ? a % b : a; }

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_scalar<T> MapRange(T input, T inputMin, T inputMax, T outputMin, T outputMax)
{
	T blend = T();
	if (MAXON_LIKELY(inputMin != inputMax))
		blend = (input - inputMin) / (inputMax - inputMin);
	else
		blend = T() < inputMin ? T() : T(1.0f);
	return Blend(outputMin, outputMax, blend);
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_float<T> Step(T value, T threshold) { return value < threshold ? T() : T(1.0f); }

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_float<T> Quantize(T value, T steps) { return steps > T() ? Floor(value * steps) / steps : value; }
	
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE enable_if_float<T> Cbrt(T input) { input >= T() ? Pow(input, T(1.0f / 3.0f)) : T();  }

MAXON_ATTRIBUTE_FORCE_INLINE Float32 SquaredLength(const Vector2d32& input) {	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 SquaredLength(const Vector2d64& input) {	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 SquaredLength(const Vector32& input)		{	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 SquaredLength(const Vector64& input)		{	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 SquaredLength(const Vector4d32& input) {	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 SquaredLength(const Vector4d64& input) {	return input.GetSquaredLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 SquaredLength(const Color32& input)		{	return input.r * input.r + input.g * input.g + input.b * input.b; }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 SquaredLength(const Color64& input)		{	return input.r * input.r + input.g * input.g + input.b * input.b; }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 SquaredLength(const ColorA32& input)		{	return Dot(input, input); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 SquaredLength(const ColorA64& input)		{ return Dot(input, input); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Length(const Vector2d32& input)				{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Length(const Vector2d64& input)				{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Length(const Vector32& input)					{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Length(const Vector64& input)					{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Length(const Vector4d32& input)				{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Length(const Vector4d64& input)				{	return input.GetLength(); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Length(const Color32& input)						{	return Sqrt(SquaredLength(input)); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Length(const Color64& input)						{	return Sqrt(SquaredLength(input)); }
MAXON_ATTRIBUTE_FORCE_INLINE Float32 Length(const ColorA32& input)					{	return Sqrt(SquaredLength(input)); }
MAXON_ATTRIBUTE_FORCE_INLINE Float64 Length(const ColorA64& input)					{ return Sqrt(SquaredLength(input)); }

// stylecheck.naming=false

// Limits specialized for Vectors and Colors
template <> class LIMIT<Vector2d32>
{
public:
	static Vector2d32 Min() { return Vector2d32(-3.402823466e+38f); }
	static Vector2d32 Max() { return Vector2d32(3.402823466e+38f); }
};

template <> class LIMIT<Vector2d64>
{
public:
	static Vector2d64 Min() { return Vector2d64(-1.7976931348623158e+308); }
	static Vector2d64 Max() { return Vector2d64(1.7976931348623158e+308); }
};

template <> class LIMIT<Vector4d32>
{
public:
	static Vector4d32 Min() { return Vector4d32(-3.402823466e+38f); }
	static Vector4d32 Max() { return Vector4d32(3.402823466e+38f); }
};

template <> class LIMIT<Vector4d64>
{
public:
	static Vector4d64 Min() { return Vector4d64(-1.7976931348623158e+308); }
	static Vector4d64 Max() { return Vector4d64(1.7976931348623158e+308); }
};

template <> class LIMIT<Vector32>
{
public:
	static Vector32 Min() { return Vector32(-3.402823466e+38f); }
	static Vector32 Max() { return Vector32(3.402823466e+38f); }
};

template <> class LIMIT<Vector64>
{
public:
	static Vector64 Min() { return Vector64(-1.7976931348623158e+308); }
	static Vector64 Max() { return Vector64(1.7976931348623158e+308); }
};

template <> class LIMIT<Matrix32>
{
public:
	static Matrix32 Min() { return Matrix32(LIMIT<Vector32>::Min(), LIMIT<Vector32>::Min(), LIMIT<Vector32>::Min(), LIMIT<Vector32>::Min()); }
	static Matrix32 Max() { return Matrix32(LIMIT<Vector32>::Max(), LIMIT<Vector32>::Max(), LIMIT<Vector32>::Max(), LIMIT<Vector32>::Max()); }
};

template <> class LIMIT<Matrix64>
{
public:
	static Matrix64 Min() { return Matrix64(LIMIT<Vector64>::Min(), LIMIT<Vector64>::Min(), LIMIT<Vector64>::Min(), LIMIT<Vector64>::Min()); }
	static Matrix64 Max() { return Matrix64(LIMIT<Vector64>::Max(), LIMIT<Vector64>::Max(), LIMIT<Vector64>::Max(), LIMIT<Vector64>::Max()); }
};

template <> class LIMIT<Color32>
{
public:
	static Color32 Min() { return Color32(-3.402823466e+38f); }
	static Color32 Max() { return Color32(3.402823466e+38f); }
};

template <> class LIMIT<Color64>
{
public:
	static Color64 Min() { return Color64(-1.7976931348623158e+308); }
	static Color64 Max() { return Color64(1.7976931348623158e+308); }
};

template <> class LIMIT<ColorA32>
{
public:
	static ColorA32 Min() { return ColorA32(-3.402823466e+38f); }
	static ColorA32 Max() { return ColorA32(3.402823466e+38f); }
};

template <> class LIMIT<ColorA64>
{
public:
	static ColorA64 Min() { return ColorA64(-1.7976931348623158e+308); }
	static ColorA64 Max() { return ColorA64(1.7976931348623158e+308); }
};

// stylecheck.naming=true


MAXON_ATTRIBUTE_FORCE_INLINE Float64 SafePow(Float64 v1, Float64 v2) 
{ 
	if (v1 == 0.0)
		return 0.0;
	else if (v1 > 0.0 || Float64((Int)v2) == v2) // if v1 is negative Pow only works if v2 is an integer
		return Pow(v1, v2);
	return 0.0;
}

MAXON_ATTRIBUTE_FORCE_INLINE Float32 SafePow(Float32 v1, Float32 v2) 
{ 
	if (v1 == 0.0f)
		return 0.0f;
	else if (v1 > 0.0f || Float32((Int)v2) == v2) // if v1 is negative Pow only works if v2 is an integer
		return Pow(v1, v2);
	return 0.0f;
}

MAXON_ATTRIBUTE_FORCE_INLINE Float64 SafeSqrt(Float64 v) 
{ 
	return v > 0.0 ? Sqrt(v): 0.0;
}

MAXON_ATTRIBUTE_FORCE_INLINE Float32 SafeSqrt(Float32 v) 
{ 
	return v > 0.0f ? Sqrt(v): 0.0f;
}

MATH_HELPER_INSTANTIATE(Clamp01);
MATH_HELPER_INSTANTIATE(ATan2);
MATH_HELPER_INSTANTIATE(Exp);
MATH_HELPER_INSTANTIATE(Exp2);
MATH_HELPER_INSTANTIATE(Ln);
MATH_HELPER_INSTANTIATE(Log10);
MATH_HELPER_INSTANTIATE(Log2);
MATH_HELPER_INSTANTIATE(Gamma);
MATH_HELPER_INSTANTIATE(Si);
MATH_HELPER_INSTANTIATE(Sinc);
MATH_HELPER_INSTANTIATE(Abs);
MATH_HELPER_INSTANTIATE(Ceil);
MATH_HELPER_INSTANTIATE(Floor);
MATH_HELPER_INSTANTIATE(Round);
MATH_HELPER_INSTANTIATE(ClampValueCustom);
MATH_HELPER_INSTANTIATE(MinCustom);
MATH_HELPER_INSTANTIATE(MaxCustom);
MATH_HELPER_INSTANTIATE(Fract);
MATH_HELPER_INSTANTIATE(Invert);
MATH_HELPER_INSTANTIATE(FMod);
MATH_HELPER_INSTANTIATE(MapRange);
MATH_HELPER_INSTANTIATE(Inverse);
MATH_HELPER_INSTANTIATE(SignNoTemplate);
MATH_HELPER_INSTANTIATE(SmoothStep);
MATH_HELPER_INSTANTIATE(BoxStep);
MATH_HELPER_INSTANTIATE(Step);
MATH_HELPER_INSTANTIATE(Quantize);
MATH_HELPER_INSTANTIATE(Pow);
MATH_HELPER_INSTANTIATE(Sqrt);
MATH_HELPER_INSTANTIATE(Cbrt);
MATH_HELPER_INSTANTIATE(Sin);
MATH_HELPER_INSTANTIATE(Cos);
MATH_HELPER_INSTANTIATE(Tan);
MATH_HELPER_INSTANTIATE(Sinh);
MATH_HELPER_INSTANTIATE(Cosh);
MATH_HELPER_INSTANTIATE(Tanh);
MATH_HELPER_INSTANTIATE(ASin);
MATH_HELPER_INSTANTIATE(ACos);
MATH_HELPER_INSTANTIATE(ATan);
MATH_HELPER_INSTANTIATE(SafePow);
MATH_HELPER_INSTANTIATE(SafeSqrt);

} // namespace maxon

#endif // APIBASEMATH_EXTENSION_H__
