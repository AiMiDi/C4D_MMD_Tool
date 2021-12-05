#ifndef SSE_VECTOR_H__
#define SSE_VECTOR_H__

#if _MSC_VER > 1000
	#pragma warning(push)
	#pragma warning(disable:4752)
#endif

#include "maxon/sse_general.h"
#include "maxon/bitmanipulation.h"
#include "maxon/sse_vector_4i32.h"
#include "maxon/sse_vector_4f32.h"
#include "maxon/sse_vector_2f64.h"

#include "maxon/sse_vector_8f32.h"
#include "maxon/sse_vector_8i32.h"
#include "maxon/sse_vector_4f64.h"

#include "maxon/sse_matrix_4f32.h"

namespace maxon
{

#ifdef C4D_HAS_SSE2_CAPABILITY

//----------------------------------------------------------------------------------------
/// Casts a Vector4i32 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 CastToVector4f32(const Vector4i32& a)
{
	return Vector4f32(_mm_castsi128_ps(a._val));
}

//----------------------------------------------------------------------------------------
/// Converts a Vector4i32 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector4i32& a)
{
	return Vector4f32(_mm_cvtepi32_ps(a._val));
}

//----------------------------------------------------------------------------------------
/// Casts a Vector4f32 to a Vector4i32 vector.
/// @return												A Vector4i32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 CastToVector4i32(const Vector4f32& a)
{
	return Vector4i32(_mm_castps_si128(a._val));
}

//----------------------------------------------------------------------------------------
/// Converts a Vector4f32 to a Vector4i32 vector.
/// @return												A Vector4i32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 ConvertToVector4i32(const Vector4f32& a)
{
	return Vector4i32(_mm_cvtps_epi32(a._val));
}

//----------------------------------------------------------------------------------------
/// Converts two Vector2f64 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector2f64& a, const Vector2f64& b)
{
	return Vector4f32(_mm_shuffle_ps(_mm_cvtpd_ps(a._val), _mm_cvtpd_ps(b._val), _MM_SHUFFLE(1, 0, 1, 0)));
}

//----------------------------------------------------------------------------------------
/// Converts one Vector2f64 to a Vector4f32 vector.
/// @return												A Vector4f32 vector. The two lower values are the converted members from the source vector, the two upper values are zero.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector2f64& a)
{
	return Vector4f32(_mm_cvtpd_ps(a._val));
}

//----------------------------------------------------------------------------------------
/// Calculates the cross product of two vector arrays. The parameter arrays must have at least 3 elements.
/// @param[out] r									The cross product of a and b.
/// @param[in] a									An array of input vectors. a[0] contains all x coordinates, a[1] the y coordinates and a[2] the z coordinates.
/// @param[in] b									An array of input vectors. b[0] contains all x coordinates, b[1] the y coordinates and b[2] the z coordinates.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SSECross(Vector4f32* r, const Vector4f32* a, const Vector4f32* b)
{
	r[0] = a[1] * b[2] - a[2] * b[1];
	r[1] = a[2] * b[0] - a[0] * b[2];
	r[2] = a[0] * b[1] - a[1] * b[0];
}

//----------------------------------------------------------------------------------------
/// Normalizes a vector array.
/// @param[in,out] n							An array of input vectors. n[0] contains all x coordinates, n[1] the y coordinates and n[2] the z coordinates.
//----------------------------------------------------------------------------------------
template<Bool useRsqrt = false> MAXON_ATTRIBUTE_FORCE_INLINE void SSENormalize(Vector4f32 *n)
{
	Vector4f32 len;
	Vector4i32 mask;
	len = n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
	if (useRsqrt)
	{
		len = Rsqrt(len);
		mask = CastToVector4i32(len > Vector4f32(0.0f));

		n[0] *= len;
		n[1] *= len;
		n[2] *= len;
	}
	else
	{
		len = Sqrt(len);
		mask = CastToVector4i32(len > Vector4f32(0.0f));

		n[0] /= len;
		n[1] /= len;
		n[2] /= len;
	}
	n[0] = CastToVector4f32(CastToVector4i32(n[0]) & mask);
	n[1] = CastToVector4f32(CastToVector4i32(n[1]) & mask);
	n[2] = CastToVector4f32(CastToVector4i32(n[2]) & mask);
}

//----------------------------------------------------------------------------------------
/// Converts one Vector4f32 to two Vector2f64.
/// @param[in] a									Input vector.
/// @param[out] result1						The two upper values of the input vector.
/// @param[out] result2						The two lower values of the input vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertToVectors2f64(const Vector4f32& a, Vector2f64& result1, Vector2f64& result2)
{
	__m128 tmp = a._val;
	result1._val = _mm_cvtps_pd(tmp);
	tmp = _mm_shuffle_ps(tmp, tmp, _MM_SHUFFLE(3, 2, 3, 2));
	result2._val = _mm_cvtps_pd(tmp);
}

#ifdef C4D_HAS_AVX_CAPABILITY

//----------------------------------------------------------------------------------------
/// Calculates the cross product of two vector arrays. The parameter arrays must have at least 3 elements.
/// @param[out] r									The cross product of a and b.
/// @param[in] a									An array of input vectors. a[0] contains all x coordinates, a[1] the y coordinates and a[2] the z coordinates.
/// @param[in] b									An array of input vectors. b[0] contains all x coordinates, b[1] the y coordinates and b[2] the z coordinates.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SSECross(Vector8f32* r, const Vector8f32* a, const Vector8f32* b)
{
	r[0] = a[1] * b[2] - a[2] * b[1];
	r[1] = a[2] * b[0] - a[0] * b[2];
	r[2] = a[0] * b[1] - a[1] * b[0];
}

//----------------------------------------------------------------------------------------
/// Normalizes a vector array.
/// @param[in,out] n							An array of input vectors. n[0] contains all x coordinates, n[1] the y coordinates and n[2] the z coordinates.
//----------------------------------------------------------------------------------------
template<Bool useRsqrt = false> MAXON_ATTRIBUTE_FORCE_INLINE void SSENormalize(Vector8f32 *n)
{
	Vector8f32 len;
	Vector8i32 mask;
	len = n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
	if (useRsqrt)
	{
		len = Rsqrt(len);
		mask = CastToVector8i32(len > Vector8f32(0.0f));

		n[0] *= len;
		n[1] *= len;
		n[2] *= len;
	}
	else
	{
		len = Sqrt(len);
		mask = CastToVector8i32(len > Vector8f32(0.0f));

		n[0] /= len;
		n[1] /= len;
		n[2] /= len;
	}
	n[0] = CastToVector8f32(CastToVector8i32(n[0]) & mask);
	n[1] = CastToVector8f32(CastToVector8i32(n[1]) & mask);
	n[2] = CastToVector8f32(CastToVector8i32(n[2]) & mask);
}

//----------------------------------------------------------------------------------------
/// Converts two Vector4f32 to a Vector8f32 vector.
/// @return												A Vector8f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32 ConvertToVector8f32(const Vector4f32& a, const Vector4f32& b)
{
	return Vector8f32(_mm256_setr_m128(a._val, b._val));
}

//----------------------------------------------------------------------------------------
/// Converts one Vector4f32 to two Vector2f64.
/// @param[in] a									Input vector.
/// @param[out] result1						The two upper values of the input vector.
/// @param[out] result2						The two lower values of the input vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertToVectors4f32(const Vector8f32& a, Vector4f32& result1, Vector4f32& result2)
{
	result1._val = _mm256_castps256_ps128(a._val);
	result2._val = _mm256_extractf128_ps(a._val, 0x1);
}

//----------------------------------------------------------------------------------------
/// Casts a Vector8f32 to a Vector8i32 vector.
/// @return												A Vector8i32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector8i32 CastToVector8i32(const Vector8f32& a)
{
	return Vector8i32(_mm256_castps_si256(a._val));
}

//----------------------------------------------------------------------------------------
/// Casts a Vector8i32 to a Vector8f32 vector.
/// @return												A Vector8f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector8f32 CastToVector8f32(const Vector8i32& a)
{
	return Vector8f32(_mm256_castsi256_ps(a._val));
}

#endif // C4D_HAS_AVX_CAPABILITY

#else // C4D_HAS_SSE2_CAPABILITY

//----------------------------------------------------------------------------------------
/// Casts a Vector4i32 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 CastToVector4f32(const Vector4i32& a)
{
	const Float32* f = reinterpret_cast<const Float32*>(a.v);
	return Vector4f32(f[0], f[1], f[2], f[3]);
}

//----------------------------------------------------------------------------------------
/// Converts a Vector4i32 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector4i32& a)
{
	const Int32* i = a.v;
	return Vector4f32((Float32)i[0], (Float32)i[1], (Float32)i[2], (Float32)i[3]);
}

//----------------------------------------------------------------------------------------
/// Casts a Vector4f32 to a Vector4i32 vector.
/// @return												A Vector4i32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 CastToVector4i32(const Vector4f32& a)
{
	const Int32* i = reinterpret_cast<const Int32*>(a.v);
	return Vector4i32(i[0], i[1], i[2], i[3]);
}

//----------------------------------------------------------------------------------------
/// Converts a Vector4f32 to a Vector4i32 vector.
/// @return												A Vector4i32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4i32 ConvertToVector4i32(const Vector4f32& a)
{
	const Float32* f = a.v;
	return Vector4i32((Int32)f[0], (Int32)f[1], (Int32)f[2], (Int32)f[3]);
}

//----------------------------------------------------------------------------------------
/// Converts two Vector2f64 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector2f64& a, const Vector2f64& b)
{
	const Float64* f1 = a.v;
	const Float64* f2 = b.v;
	return Vector4f32((Float32)f1[0], (Float32)f1[1], (Float32)f2[0], (Float32)f2[1]);
}

//----------------------------------------------------------------------------------------
/// Converts one Vector2f64 to a Vector4f32 vector.
/// @return												A Vector4f32 vector. The two lower values are the converted members from the source vector, the two upper values are zero.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector2f64& a)
{
	const Float64* f = a.v;
	return Vector4f32((Float32)f[0], (Float32)f[1], 0.0f, 0.0f);
}

#endif // C4D_HAS_SSE2_CAPABILITY

#if defined C4D_HAS_SSE2_CAPABILITY && defined C4D_HAS_AVX_CAPABILITY

//----------------------------------------------------------------------------------------
/// Converts one Vector4f64 to a Vector4f32 vector.
/// @return												A Vector4f32 vector.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Vector4f32 ConvertToVector4f32(const Vector4f64& a)
{
	return Vector4f32(_mm256_cvtpd_ps(a.Get()));
}

#endif // C4D_HAS_SSE2_CAPABILITY && C4D_HAS_AVX_CAPABILITY

} // namespace maxon

#if _MSC_VER > 1000
	#pragma warning(pop)
#endif

#endif // SSE_VECTOR_H__
