#include "matrix_prs.h"
#include <limits>

namespace maxon
{

ROTATIONORDER TranslateRotationOrder(const Id& type)
{
	if (type == Id("xyzlocal"))
		return ROTATIONORDER::XYZLOCAL;
	else if (type == Id("xzylocal"))
		return ROTATIONORDER::XZYLOCAL;
	else if (type == Id("yxzlocal"))
		return ROTATIONORDER::YXZLOCAL;
	else if (type == Id("yzxlocal"))
		return ROTATIONORDER::YZXLOCAL;
	else if (type == Id("zxylocal"))
		return ROTATIONORDER::ZXYLOCAL;
	else if (type == Id("zyxlocal"))
		return ROTATIONORDER::ZYXLOCAL;
	else if (type == Id("xyzglobal"))
		return ROTATIONORDER::XYZGLOBAL;
	else if (type == Id("xzyglobal"))
		return ROTATIONORDER::XZYGLOBAL;
	else if (type == Id("yxzglobal"))
		return ROTATIONORDER::YXZGLOBAL;
	else if (type == Id("yzxglobal"))
		return ROTATIONORDER::YZXGLOBAL;
	else if (type == Id("zxyglobal"))
		return ROTATIONORDER::ZXYGLOBAL;
	else if (type == Id("zyxglobal"))
		return ROTATIONORDER::ZYXGLOBAL;

	return ROTATIONORDER::YXZLOCAL;
}

// Computes the QR decomposition of in using two householder transformations.
// q will be orthogonal (with det(q)==1), r an upper triangular matrix where the first two diagonal elements r.v1.x and r.v2.y are non-negative.
template <typename VECTORTYPE>
static void DecomposeQR(const SqrMat3<VECTORTYPE>& in, SqrMat3<VECTORTYPE>& q, SqrMat3<VECTORTYPE>& r, Bool needOnlyR)
{
	using FloatType = typename VECTORTYPE::ValueType;
	const FloatType eps = FloatType{1000000.0} * Sqrt(std::numeric_limits<FloatType>::min());

	// first Householder transformation
	FloatType h0 = in.v1.x;
	FloatType h1 = in.v1.y;
	FloatType h2 = in.v1.z;
	FloatType s = Sqrt(h0 * h0 + h1 * h1 + h2 * h2);

	Bool mirror = false;

	if (s < eps)
	{
		q = SqrMat3<VECTORTYPE>();
		r = in;
		r.v1.x = eps;
	}
	else
	{
		FloatType sign{1.0};
		if (h0 < FloatType{0.0})
		{
			// use Householder transformation (det == -1)
			sign = FloatType{1.0};
		}
		else
		{
			// use Householder transformation multiplied by -1 (det == 1)
			// this ensures m00 > 0
			mirror = true;
			sign = FloatType{-1.0};
			s = -s;
		}

		h0 -= s;

		FloatType w = sign / (s * h0);

		q.v1.x = sign + h0 * h0 * w;
		q.v2.x = q.v1.y = h0 * h1 * w;
		q.v3.x = q.v1.z = h0 * h2 * w;
		q.v2.y = sign + h1 * h1 * w;
		q.v3.y = q.v2.z = h1 * h2 * w;
		q.v3.z = sign + h2 * h2 * w;

		r = q * in;
	}

	r.v1.y = r.v1.z = FloatType{0.0};

	// second Householder transformation
	h1 = r.v2.y;
	h2 = r.v2.z;
	s = Sqrt(h1 * h1 + h2 * h2);
	if (s < eps)
	{
		r.v2.y = eps;
		r.v2.z = FloatType{0.0};
	}
	else
	{
		FloatType sign{1.0};
		if (h1 < FloatType{0.0})
		{
			// use Householder transformation
			sign = FloatType{1.0};
		}
		else
		{
			// use Householder transformation multiplied by -1
			// this ensures m11 > 0
			sign = FloatType{-1.0};
			s = -s;
		}
		// det(Householder) == -1, whether multiplied by -1 or not
		// so det(q) is negative iff mirror is true

		h1 -= s;
		FloatType w = sign / (s * h1);
		FloatType h11 = sign + h1 * h1 * w;
		FloatType h12 = h1 * h2 * w;
		FloatType h22 = sign + h2 * h2 * w;

		// multiply r from left by H
		FloatType r12 = r.v3.y;
		r.v2.y = s * sign;
		r.v2.z = FloatType{0.0};
		r.v3.y = h11 * r12 + h12 * r.v3.z;
		r.v3.z = h12 * r12 + h22 * r.v3.z;

		if (!needOnlyR)
		{
			// multiply q from right by H
			FloatType q01 = q.v2.x, q11 = q.v2.y, q21 = q.v2.z;
			q.v2.x = q01 * h11 + q.v3.x * h12;
			q.v3.x = q01 * h12 + q.v3.x * h22;
			q.v2.y = q11 * h11 + q.v3.y * h12;
			q.v3.y = q11 * h12 + q.v3.y * h22;
			q.v2.z = q21 * h11 + q.v3.z * h12;
			q.v3.z = q21 * h12 + q.v3.z * h22;
		}
	}

	if (Abs(r.v3.z) < eps)
	{
		r.v3.z = eps;
	}

	if (mirror)
	{
		// ensure det(q) == 1. As a consequence, sign(det(in)) == sign(r.v3.z)

		// multiply r from left by diag(1,1,-1)
		r.v3.z = -r.v3.z;

		if (needOnlyR)
		{
			return;
		}

		// multiply q from right by diag(1,1,-1)
		q.v3 = -q.v3;
	}
}


template <typename VECTORTYPE>
Mat3<VECTORTYPE> PRSMatrixData<VECTORTYPE>::GetMatrix() const
{
	SqrMat3<VECTORTYPE> m = GetRotationMatrix(rotation, order);
	m.v3 = m.v1 * shear.y + m.v2 * shear.z + m.v3 * scale.z;
	m.v2 = m.v1 * shear.x + m.v2 * scale.y;
	m.v1 *= scale.x;
	return Mat3<VECTORTYPE>(position, m);
}

template <typename VECTORTYPE>
void PRSMatrixData<VECTORTYPE>::SetMatrix(const Mat3<VECTORTYPE>& matrix, ROTATIONORDER o)
{
	SqrMat3<VECTORTYPE> q;
	SqrMat3<VECTORTYPE> r;
	DecomposeQR(matrix.sqmat, q, r, false);
	position = matrix.off;
	rotation = GetRotationAngles(q, o);
	scale.x = r.v1.x;
	scale.y = r.v2.y;
	scale.z = r.v3.z;
	shear.x = r.v2.x;
	shear.y = r.v3.x;
	shear.z = r.v3.y;
	order = o;
}

template struct PRSMatrixData<Vector32>;
template struct PRSMatrixData<Vector64>;

} // namespace maxon
