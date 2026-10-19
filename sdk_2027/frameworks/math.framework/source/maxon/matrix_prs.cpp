#include "matrix_prs.h"
#include "matrix_decomposition.h"

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
	DecomposeQR(matrix.sqmat, q, r);
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
