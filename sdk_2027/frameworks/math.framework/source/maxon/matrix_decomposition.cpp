#include "matrix_decomposition.h"
#include <limits>

namespace maxon
{

template <typename VECTORTYPE>
void DecomposeQR(const SqrMat3<VECTORTYPE>& m, SqrMat3<VECTORTYPE>& q, SqrMat3<VECTORTYPE>& r)
{
	using FloatType = typename VECTORTYPE::ValueType;
	// See below for Sqrt. Division by epsilon() gives some extra safety.
	const FloatType eps = Sqrt(std::numeric_limits<FloatType>::min() / std::numeric_limits<FloatType>::epsilon());

	// first Householder transformation
	FloatType h0 = m.v1.x;
	FloatType h1 = m.v1.y;
	FloatType h2 = m.v1.z;
	FloatType s = Sqrt(h0 * h0 + h1 * h1 + h2 * h2);

	Bool mirror = false;

	if (s < eps)
	{
		q = SqrMat3<VECTORTYPE>();
		r = m;
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

		// h0 and s have opposite signs, so after -= we have |h0| > |s|
		h0 -= s;

		// We divide by something > s*s, therefore the epsilon for s was based on Sqrt(min).
		FloatType w = sign / (s * h0);

		q.v1.x = sign + h0 * h0 * w;
		q.v2.x = q.v1.y = h0 * h1 * w;
		q.v3.x = q.v1.z = h0 * h2 * w;
		q.v2.y = sign + h1 * h1 * w;
		q.v3.y = q.v2.z = h1 * h2 * w;
		q.v3.z = sign + h2 * h2 * w;

		r = q * m;
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

		// multiply q from right by H
		FloatType q01 = q.v2.x, q11 = q.v2.y, q21 = q.v2.z;
		q.v2.x = q01 * h11 + q.v3.x * h12;
		q.v3.x = q01 * h12 + q.v3.x * h22;
		q.v2.y = q11 * h11 + q.v3.y * h12;
		q.v3.y = q11 * h12 + q.v3.y * h22;
		q.v2.z = q21 * h11 + q.v3.z * h12;
		q.v3.z = q21 * h12 + q.v3.z * h22;
	}

	if (Abs(r.v3.z) < eps)
	{
		r.v3.z = eps;
	}

	if (mirror)
	{
		// ensure det(q) == 1. As a consequence, sign(det(m)) == sign(r.v3.z)

		// multiply r from left by diag(1,1,-1)
		r.v3.z = -r.v3.z;

		// multiply q from right by diag(1,1,-1)
		q.v3 = -q.v3;
	}
}

template void DecomposeQR<Vector32>(const SqrMat3<Vector32>& m, SqrMat3<Vector32>& q, SqrMat3<Vector32>& r);
template void DecomposeQR<Vector64>(const SqrMat3<Vector64>& m, SqrMat3<Vector64>& q, SqrMat3<Vector64>& r);

}
