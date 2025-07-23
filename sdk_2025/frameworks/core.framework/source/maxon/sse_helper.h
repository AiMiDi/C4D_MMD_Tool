#ifndef SSE_HELPER_H__
#define SSE_HELPER_H__

#include "vector.h"
#include "vector4d.h"
#include "sse_vector.h"

namespace maxon
{

inline Vector4f32 LoadVector4f32(const Vector64& v, Float64 w, Bool aligned)
{
	Vector2f64 a(&v.x, aligned);
	Vector2f64 b(v.z, w);

	return ConvertToVector4f32(a, b);
}

inline Vector4f32 LoadVector4f32(const Vector32& v, Float32 w, Bool aligned)
{
	return Vector4f32(v.x, v.y, v.z, w);
}

inline Vector4f32 LoadVector4f32(const Vector4d64& v, Bool aligned)
{
	Vector2f64 a(&v.x, aligned);
	Vector2f64 b(&v.z, aligned);

	return ConvertToVector4f32(a, b);
}

inline Vector4f32 LoadVector4f32(const Vector4d32& v, Bool aligned)
{
	return Vector4f32(&v.x, aligned);
}

inline Vector4f32 LoadVector4f32(const Color64& v, Float64 w, Bool aligned)
{
	Vector2f64 a(&v.r, aligned);
	Vector2f64 b(v.b, w);

	return ConvertToVector4f32(a, b);
}

inline Vector4f32 LoadVector4f32(const Color32& v, Float32 w, Bool aligned)
{
	return Vector4f32(v.r, v.g, v.b, w);
}

inline Vector4f32 LoadVector4f32(const ColorA64& v, Bool aligned)
{
	Vector2f64 a(&v.r, aligned);
	Vector2f64 b(&v.b, aligned);

	return ConvertToVector4f32(a, b);
}

inline Vector4f32 LoadVector4f32(const ColorA32& v, Bool aligned)
{
	return Vector4f32(&v.r, aligned);
}

}; // namespace maxon

#endif // SSE_HELPER_H__
