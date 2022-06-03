#ifndef SSE_MATRIX_4F64_H__
#define SSE_MATRIX_4F64_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

#include "maxon/matrix.h"
#include "maxon/matrix4d.h"

namespace maxon
{

class Matrix4f64
{
public:
	using ValueType = Float64;

	/// Constructs the object. It does not set a default value.
	Matrix4f64()
	{
	}

#ifdef C4D_HAS_AVX_CAPABILITY
	/*MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64(const Float32* p, Bool aligned) :
		v0(p, aligned),
		v1(p + 4, aligned),
		v2(p + 8, aligned),
		v3(p + 12, aligned)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64(const SquareMatrix4d& m, Bool aligned)
	{
		if (aligned)
		{
			v0.LoadAligned(&m.v1.x);
			v1.LoadAligned(&m.v2.x);
			v2.LoadAligned(&m.v3.x);
			v3.LoadAligned(&m.v4.x);
		}
		else
		{
			v0.LoadUnaligned(&m.v1.x);
			v1.LoadUnaligned(&m.v2.x);
			v2.LoadUnaligned(&m.v3.x);
			v3.LoadUnaligned(&m.v4.x);
		}
	}
	*/
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64(const Matrix& m)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		v0 = Vector4f32(m.sqmat.v1.x, m.sqmat.v1.y, m.sqmat.v1.z, 0.0f);
		v1 = Vector4f32(m.sqmat.v2.x, m.sqmat.v2.y, m.sqmat.v2.z, 0.0f);
		v2 = Vector4f32(m.sqmat.v3.x, m.sqmat.v3.y, m.sqmat.v3.z, 0.0f);
		v3 = Vector4f32(m.off.x, m.off.y, m.off.z, 0.0f);
#else
		Vector2f64 vA(&m.sqmat.v1.x, false);
		Vector2f64 vB(m.sqmat.v1.z, false);
		v0 = Vector4f64(_mm256_castps_pd(_mm256_set_m128(_mm_castpd_ps(vB.Get()), _mm_castpd_ps(vA.Get()))));

		vA = Vector2f64(&m.sqmat.v2.x, false);
		vB = Vector2f64(m.sqmat.v2.z, false);
		v1 = Vector4f64(_mm256_castps_pd(_mm256_set_m128(_mm_castpd_ps(vB.Get()), _mm_castpd_ps(vA.Get()))));

		vA = Vector2f64(&m.sqmat.v3.x, false);
		vB = Vector2f64(m.sqmat.v3.z, false);
		v2 = Vector4f64(_mm256_castps_pd(_mm256_set_m128(_mm_castpd_ps(vB.Get()), _mm_castpd_ps(vA.Get()))));

		vA = Vector2f64(&m.off.x, false);
		vB = Vector2f64(m.off.z, 1.0);
		v3 = Vector4f64(_mm256_castps_pd(_mm256_set_m128(_mm_castpd_ps(vB.Get()), _mm_castpd_ps(vA.Get()))));
#endif
	}
	/*
	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float32* p)
	{
		v0.LoadAligned(p);
		v1.LoadAligned(p + 4);
		v2.LoadAligned(p + 8);
		v3.LoadAligned(p + 12);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void LoadAligned(const Float64* p)
	{
		v0.LoadAligned(p);
		v1.LoadAligned(p + 4);
		v2.LoadAligned(p + 8);
		v3.LoadAligned(p + 12);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void StoreUnaligned(Float32* p) const
	{
		v0.StoreUnaligned(p);
		v1.StoreUnaligned(p + 4);
		v2.StoreUnaligned(p + 8);
		v3.StoreUnaligned(p + 12);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Matrix4f64 GetTransposed() const
	{
		Matrix4f64 ret(*this);

		Transpose(ret.v0, ret.v1, ret.v2, ret.v3);

		return ret;
	}

	*/

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f64 operator * (const Matrix4f64& m, const Vector4f64& v)
	{
		Vector4f64 ret;

		Vector4f64 xyxy = Vector4f64::Shuffle2<0, 0>(v);
		Vector4f64 zwzw = Vector4f64::Shuffle2<1, 1>(v);

		Vector4f64 x = Vector4f64::Shuffle<0, 0, 0, 0>(xyxy, xyxy);
		Vector4f64 y = Vector4f64::Shuffle<1, 1, 1, 1>(xyxy, xyxy);
		Vector4f64 z = Vector4f64::Shuffle<0, 0, 0, 0>(zwzw, zwzw);
		Vector4f64 w = Vector4f64::Shuffle<1, 1, 1, 1>(zwzw, zwzw);

		ret = m.v0 * x + m.v1 * y + m.v2 * z + m.v3 * w;

		return ret;
	}

	/*MAXON_ATTRIBUTE_FORCE_INLINE friend Matrix4f64 operator * (const Matrix4f64& a, const Matrix4f64& b)
	{
		Matrix4f64 ret;
		Vector4f32 u, v, r;

		for (UChar i = 0; i < 4; ++i) 
		{
			u = a.v0;
			v = Vector4f32::Shuffle<0, 0, 0, 0>((&b.v0)[i], (&b.v0)[i]);
			r = u * v;

			u = a.v1;
			v = Vector4f32::Shuffle<1, 1, 1, 1>((&b.v0)[i], (&b.v0)[i]);
			r += u * v;

			u = a.v2;
			v = Vector4f32::Shuffle<2, 2, 2, 2>((&b.v0)[i], (&b.v0)[i]);
			r += u * v;

			u = a.v3;
			v = Vector4f32::Shuffle<3, 3, 3, 3>((&b.v0)[i], (&b.v0)[i]);

			(&ret.v0)[i] = r + u * v;
		}

		return ret;
	}*/

#endif // C4D_HAS_AVX_CAPABILITY
private:
	Vector4f64 v0, v1, v2, v3;
};

} // namespace maxon

#endif // SSE_MATRIX_4F64_H__
