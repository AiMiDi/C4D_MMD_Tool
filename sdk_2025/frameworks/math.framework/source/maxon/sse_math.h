#ifndef SSE_MATH_H__
#define SSE_MATH_H__

#include "maxon/sse_vector.h"

namespace maxon
{

inline void MatrixConvert(SquareMatrix4d& dest, const Matrix& src)
{
	Vector2f64 tmp;

	tmp.LoadUnaligned(&src.sqmat.v1.x);
	tmp.StoreUnaligned(&dest.v1.x);
	tmp.LoadSingle(&src.sqmat.v1.z);
	tmp.StoreUnaligned(&dest.v1.z);

	tmp.LoadUnaligned(&src.sqmat.v2.x);
	tmp.StoreUnaligned(&dest.v2.x);
	tmp.LoadSingle(&src.sqmat.v2.z);
	tmp.StoreUnaligned(&dest.v2.z);

	tmp.LoadUnaligned(&src.sqmat.v3.x);
	tmp.StoreUnaligned(&dest.v3.x);
	tmp.LoadSingle(&src.sqmat.v3.z);
	tmp.StoreUnaligned(&dest.v3.z);

	tmp = Vector2f64(src.off.x, src.off.y);
	tmp.StoreUnaligned(&dest.v4.x);
	tmp = Vector2f64(src.off.z, 1.0);
	tmp.StoreUnaligned(&dest.v4.z);
}

} // namespace maxon

#endif // SSE_MATH_H__
