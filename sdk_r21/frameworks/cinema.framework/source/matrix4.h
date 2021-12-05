/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef MATRIX4_H__
#define MATRIX4_H__

#include "vector4.h"
#include "maxon/matrix4d.h"

using Matrix4d32 = maxon::SqMat4<Vector4d32>;			///< Single-precision Matrix4
using Matrix4d64 = maxon::SqMat4<Vector4d64>;			///< Double-precision Matrix4
using Matrix4d = maxon::SqMat4<Vector4d64>;				///< Matrix4 for double-precision @C4D versions.

template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE TYPE GlDet(TYPE a1, TYPE a2, TYPE a3, TYPE b1, TYPE b2, TYPE b3, TYPE c1, TYPE c2, TYPE c3)
{
	return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
}

template <typename VEC> MAXON_ATTRIBUTE_FORCE_INLINE maxon::SqMat4<VEC> GetGlInverseMatrix(const maxon::SqMat4<VEC>& m)
{
	maxon::SqMat4<VEC> r(DONT_INITIALIZE);

	r.v1.x =  GlDet(m.v2.y, m.v2.z, m.v2.w, m.v3.y, m.v3.z, m.v3.w, m.v4.y, m.v4.z, m.v4.w);
	r.v1.y = -GlDet(m.v1.y, m.v1.z, m.v1.w, m.v3.y, m.v3.z, m.v3.w, m.v4.y, m.v4.z, m.v4.w);
	r.v1.z =  GlDet(m.v1.y, m.v1.z, m.v1.w, m.v2.y, m.v2.z, m.v2.w, m.v4.y, m.v4.z, m.v4.w);
	r.v1.w = -GlDet(m.v1.y, m.v1.z, m.v1.w, m.v2.y, m.v2.z, m.v2.w, m.v3.y, m.v3.z, m.v3.w);
	r.v2.x = -GlDet(m.v2.x, m.v2.z, m.v2.w, m.v3.x, m.v3.z, m.v3.w, m.v4.x, m.v4.z, m.v4.w);
	r.v2.y =  GlDet(m.v1.x, m.v1.z, m.v1.w, m.v3.x, m.v3.z, m.v3.w, m.v4.x, m.v4.z, m.v4.w);
	r.v2.z = -GlDet(m.v1.x, m.v1.z, m.v1.w, m.v2.x, m.v2.z, m.v2.w, m.v4.x, m.v4.z, m.v4.w);
	r.v2.w =  GlDet(m.v1.x, m.v1.z, m.v1.w, m.v2.x, m.v2.z, m.v2.w, m.v3.x, m.v3.z, m.v3.w);
	r.v3.x =  GlDet(m.v2.x, m.v2.y, m.v2.w, m.v3.x, m.v3.y, m.v3.w, m.v4.x, m.v4.y, m.v4.w);
	r.v3.y = -GlDet(m.v1.x, m.v1.y, m.v1.w, m.v3.x, m.v3.y, m.v3.w, m.v4.x, m.v4.y, m.v4.w);
	r.v3.z =  GlDet(m.v1.x, m.v1.y, m.v1.w, m.v2.x, m.v2.y, m.v2.w, m.v4.x, m.v4.y, m.v4.w);
	r.v3.w = -GlDet(m.v1.x, m.v1.y, m.v1.w, m.v2.x, m.v2.y, m.v2.w, m.v3.x, m.v3.y, m.v3.w);
	r.v4.x = -GlDet(m.v2.x, m.v2.y, m.v2.z, m.v3.x, m.v3.y, m.v3.z, m.v4.x, m.v4.y, m.v4.z);
	r.v4.y =  GlDet(m.v1.x, m.v1.y, m.v1.z, m.v3.x, m.v3.y, m.v3.z, m.v4.x, m.v4.y, m.v4.z);
	r.v4.z = -GlDet(m.v1.x, m.v1.y, m.v1.z, m.v2.x, m.v2.y, m.v2.z, m.v4.x, m.v4.y, m.v4.z);
	r.v4.w =  GlDet(m.v1.x, m.v1.y, m.v1.z, m.v2.x, m.v2.y, m.v2.z, m.v3.x, m.v3.y, m.v3.z);
	typename maxon::SqMat4<VEC>::ValueType det = m.v1.x * r.v1.x + m.v2.x * r.v1.y + m.v3.x * r.v1.z + m.v4.x * r.v1.w;
	if (det == 0.0)
		return maxon::SqMat4<VEC>();

	det = (typename maxon::SqMat4<VEC>::ValueType)(1.0) / det;
	r = det * r;
	return r;
}

//----------------------------------------------------------------------------------------
/// Creates a transposed 4d matrix from the ::Matrix32.
/// @param[in] m									The standard ::Matrix32 to copy.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Matrix4d32 GetGLMatrix(const Matrix32& m)
{
	return Matrix4d32(
		Vector4d32(m.sqmat.v1.x, m.sqmat.v2.x, m.sqmat.v3.x, m.off.x),
		Vector4d32(m.sqmat.v1.y, m.sqmat.v2.y, m.sqmat.v3.y, m.off.y),
		Vector4d32(m.sqmat.v1.z, m.sqmat.v2.z, m.sqmat.v3.z, m.off.z),
		Vector4d32(0.0f, 0.0f, 0.0f, 1.0f));
}

//----------------------------------------------------------------------------------------
/// Creates a transposed 4d matrix from the ::Matrix64.
/// @param[in] m									The standard ::Matrix32 to copy.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Matrix4d64 GetGLMatrix(const Matrix64& m)
{
	return Matrix4d64(
		Vector4d64(m.sqmat.v1.x, m.sqmat.v2.x, m.sqmat.v3.x, m.off.x),
		Vector4d64(m.sqmat.v1.y, m.sqmat.v2.y, m.sqmat.v3.y, m.off.y),
		Vector4d64(m.sqmat.v1.z, m.sqmat.v2.z, m.sqmat.v3.z, m.off.z),
		Vector4d64(0.0, 0.0, 0.0, 1.0));
}

	//----------------------------------------------------------------------------------------
	/// Multiplies the 2 matrices.
	/// @param[in] m1									The first matrix.
	/// @param[in] m2									The second matrix.
	/// @return												The result of the matrix multiplication.
	//----------------------------------------------------------------------------------------
template <typename VEC> MAXON_ATTRIBUTE_FORCE_INLINE maxon::SqMat4<VEC> GlMatrixMultiply(const maxon::SqMat4<VEC>& m1, const maxon::SqMat4<VEC>& m2)
{
	return m2 * m1;
}

//----------------------------------------------------------------------------------------
/// Transforms the vector @formatParam{v} by the matrix, GL-style.
/// @param[in] m									The matrix.
/// @param[in] v									The vector.
/// @return												The vector @formatParam{v} transformed by the matrix.
//----------------------------------------------------------------------------------------
template <typename VEC> MAXON_ATTRIBUTE_FORCE_INLINE VEC GlMultiply(const maxon::SqMat4<VEC>& m, const VEC& v)
{
	return VEC(Dot(m.v1, v), Dot(m.v2, v), Dot(m.v3, v), Dot(m.v4, v));
}

#endif // MATRIX4_H__
