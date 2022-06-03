#ifndef SSE_MATRIX_4F64_SSE_H__
#define SSE_MATRIX_4F64_SSE_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

#include "maxon/matrix.h"
#include "maxon/matrix4d.h"

namespace maxon
{

class Matrix4f64SSE
{
public:
	using ValueType = Float64;

	/// Constructs the object. It does not set a default value.
	Matrix4f64SSE()
	{
	}

	/*MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64SSE(const Float32* p, Bool aligned) :
		v0(p, aligned),
		v1(p + 4, aligned),
		v2(p + 8, aligned),
		v3(p + 12, aligned)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64SSE(const SquareMatrix4d& m, Bool aligned)
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
	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f64SSE(const Matrix& m)
	{
#ifdef MAXON_TARGET_SINGLEPRECISION
		v0 = Vector4f32(m.sqmat.v1.x, m.sqmat.v1.y, m.sqmat.v1.z, 0.0f);
		v1 = Vector4f32(m.sqmat.v2.x, m.sqmat.v2.y, m.sqmat.v2.z, 0.0f);
		v2 = Vector4f32(m.sqmat.v3.x, m.sqmat.v3.y, m.sqmat.v3.z, 0.0f);
		v3 = Vector4f32(m.off.x, m.off.y, m.off.z, 0.0f);
#else
		v0A.LoadUnaligned(&m.sqmat.v1.x);
		v0B.LoadSingle(&m.sqmat.v1.z);

		v1A.LoadUnaligned(&m.sqmat.v2.x);
		v1B.LoadSingle(&m.sqmat.v2.z);

		v2A.LoadUnaligned(&m.sqmat.v3.x);
		v2B.LoadSingle(&m.sqmat.v3.z);

		v3A.LoadUnaligned(&m.off.x);
		v3B = Vector2f64(m.off.z, 1.0);
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

	MAXON_ATTRIBUTE_FORCE_INLINE Matrix4f64SSE GetTransposed() const
	{
		Matrix4f64SSE ret(*this);

		Transpose(ret.v0, ret.v1, ret.v2, ret.v3);

		return ret;
	}

	*/
	MAXON_ATTRIBUTE_FORCE_INLINE void Multiply(Vector2f64& xy, Vector2f64& zw)
	{
		Vector2f64 x = Vector2f64::Shuffle<0, 0>(xy);
		Vector2f64 y = Vector2f64::Shuffle<1, 1>(xy);
		Vector2f64 z = Vector2f64::Shuffle<0, 0>(zw);
		Vector2f64 w = Vector2f64::Shuffle<1, 1>(zw);

		xy = v0A * x + v1A * y + v2A * z + v3A * w;
		zw = v0B * x + v1B * y + v2B * z + v3B * w;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void Multiply(Vector2f64& xy, Vector2f64& zw, const Vector2f64& x, const Vector2f64& y, const Vector2f64& z, const Vector2f64& w)
	{
		xy = v0A * x + v1A * y + v2A * z + v3A * w;
		zw = v0B * x + v1B * y + v2B * z + v3B * w;
	}

	/*
	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator * (const Matrix4f64SSE& m, const Vector4f32& v)
	{
		Vector4f32 ret;

		Vector4f32 x = Vector4f32::Shuffle<0, 0, 0, 0>(v);
		Vector4f32 y = Vector4f32::Shuffle<1, 1, 1, 1>(v);
		Vector4f32 z = Vector4f32::Shuffle<2, 2, 2, 2>(v);
		Vector4f32 w = Vector4f32::Shuffle<3, 3, 3, 3>(v);

		ret = m.v0 * x + m.v1 * y + m.v2 * z + m.v3 * w;

		return ret;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Matrix4f64SSE operator * (const Matrix4f64SSE& a, const Matrix4f64SSE& b)
	{
		Matrix4f64SSE ret;
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

private:
	Vector2f64 v0A, v0B, v1A, v1B, v2A, v2B, v3A, v3B;
};

} // namespace maxon

#endif // SSE_MATRIX_4F64_SSE_H__
