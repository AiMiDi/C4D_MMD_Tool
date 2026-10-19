#ifndef MATRIX_PRS_H__
#define MATRIX_PRS_H__

#include "maxon/lib_math.h"

namespace maxon
{

/// Helper type for decomposed Matrix. Also includes shear calculation.
template <typename VECTORTYPE>
struct PRSMatrixData
{
	//----------------------------------------------------------------------------------------
	/// Return a Matrix formed with the PRSMatrix decomposed members.
	/// @return												The resulting Matrix.
	//----------------------------------------------------------------------------------------
	Mat3<VECTORTYPE> GetMatrix() const;

	//----------------------------------------------------------------------------------------
	/// Sets the PRSMatrix internal members using the supplied #matrix and #order.
	//----------------------------------------------------------------------------------------
	void SetMatrix(const Mat3<VECTORTYPE>& matrix, ROTATIONORDER order = DEFAULT_ORDER);

	//----------------------------------------------------------------------------------------
	/// @see SetMatrix. Resulting PRSMatrix will be returned.
	//----------------------------------------------------------------------------------------
	static PRSMatrixData<VECTORTYPE> FromMatrix(const Mat3<VECTORTYPE>& matrix, ROTATIONORDER order = DEFAULT_ORDER)
	{
		PRSMatrixData<VECTORTYPE> m;
		m.SetMatrix(matrix, order);
		return m;
	}

	static constexpr ROTATIONORDER DEFAULT_ORDER = ROTATIONORDER::YXZLOCAL;

	VECTORTYPE			position;														///< The position.
	VECTORTYPE			rotation;														///< The rotation.
	VECTORTYPE			scale = VECTORTYPE{1.0};						///< The scale.
	VECTORTYPE			shear;															///< The shear.
	ROTATIONORDER		order = DEFAULT_ORDER;							///< The order.

	MAXON_OPERATOR_STRUCT(PRSMatrixData<VECTORTYPE>, position, rotation, scale, shear, order);
};

//----------------------------------------------------------------------------------------
/// Translate and Id rotation order value into the corresponding enum value.
/// @param[in] type								The ordering Id value.
/// @return												The matching ROTATIONORDER.
//----------------------------------------------------------------------------------------
ROTATIONORDER TranslateRotationOrder(const Id& type);

using PRSMatrix64 = PRSMatrixData<Vector64>;
// TODO: (Core) Need to devise a way for soft transitions on id changes. For now, we keep the old neutron id.
// MAXON_DATATYPE(PRSMatrix64, "net.maxon.math.datatype.prsmatrix64");
MAXON_DATATYPE(PRSMatrix64, "net.maxon.neutron.datatype.psrmatrix");
using PRSMatrix32 = PRSMatrixData<Vector32>;
MAXON_DATATYPE(PRSMatrix32, "net.maxon.math.datatype.prsmatrix32");
using PRSMatrix = PRSMatrixData<Vector>;

#include "matrix_prs1.hxx"
#include "matrix_prs2.hxx"

} // namespace maxon

#endif // MATRIX_PRS_H__
