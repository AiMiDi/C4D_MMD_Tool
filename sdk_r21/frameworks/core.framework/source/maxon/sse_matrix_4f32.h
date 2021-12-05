#ifndef SSE_MATRIX_4F32_H__
#define SSE_MATRIX_4F32_H__

#ifndef SSE_VECTOR_H__
#error Do not include this file directly. Include sse_vector.h instead.
#endif

#include "maxon/matrix.h"
#include "maxon/matrix4d.h"

namespace maxon
{

class Matrix4f32
{
public:
	using ValueType = Float32;

	/// Constructs the object. It does not set a default value.
	Matrix4f32()
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f32(const Float32* p, Bool aligned) :
		v0(p, aligned),
		v1(p + 4, aligned),
		v2(p + 8, aligned),
		v3(p + 12, aligned)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit Matrix4f32(const SquareMatrix4d& m, Bool aligned)
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

	MAXON_ATTRIBUTE_FORCE_INLINE friend Vector4f32 operator * (const Matrix4f32& m, const Vector4f32& v)
	{
		Vector4f32 ret;

		Vector4f32 x = Vector4f32::Shuffle<0, 0, 0, 0>(v);
		Vector4f32 y = Vector4f32::Shuffle<1, 1, 1, 1>(v);
		Vector4f32 z = Vector4f32::Shuffle<2, 2, 2, 2>(v);
		Vector4f32 w = Vector4f32::Shuffle<3, 3, 3, 3>(v);

		ret = m.v0 * x + m.v1 * y + m.v2 * z + m.v3 * w;

		return ret;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE friend Matrix4f32 operator * (const Matrix4f32& a, const Matrix4f32& b)
	{
		Matrix4f32 ret;
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
	}

private:
	Vector4f32 v0, v1, v2, v3;
};

} // namespace maxon

#endif // SSE_MATRIX_4F32_H__
