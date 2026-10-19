#ifndef MATRIX_DECOMPOSITION_H__
#define MATRIX_DECOMPOSITION_H__

#include "maxon/matrix.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Computes the QR decomposition of m (i.e., m = q * r) using two householder transformations.
/// q will be orthogonal (with det(q)==1), r an upper triangular matrix where the first two diagonal elements r.v1.x and r.v2.y are non-negative.
/// This decomposition is unique if m is invertible.
///
/// @param[in] m									The matrix to be decomposed.
/// @param[out] q									The resulting orthogonal matrix.
/// @param[out] r									The resulting upper triangular matrix.
//----------------------------------------------------------------------------------------
template <typename VECTORTYPE>
void DecomposeQR(const SqrMat3<VECTORTYPE>& m, SqrMat3<VECTORTYPE>& q, SqrMat3<VECTORTYPE>& r);

} // namespace maxon

#endif // MATRIX_DECOMPOSITION_H__
