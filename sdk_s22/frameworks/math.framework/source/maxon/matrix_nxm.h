#ifndef MATRIX_NXM_H__
#define MATRIX_NXM_H__

#include "maxon/vector.h"
#include "maxon/complex.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

/// General n x m matrix
template <typename TYPE> class MatrixNxM
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(MatrixNxM);

public:
	using ValueType = TYPE;

	/// Creates a matrix with no rows or columns.
	MatrixNxM()
	{
	}

	MatrixNxM(MatrixNxM&& src) : MAXON_MOVE_MEMBERS(_arr, _xcnt, _ycnt)
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(MatrixNxM);

	//----------------------------------------------------------------------------------------
	/// Resizes the matrix to contain new_xcnt*new_ycnt elements.
	/// If new_xcnt or new_ycnt differ from the existing values the internal array is expanded.
	/// @param[in] new_xcnt						new number of columns
	/// @param[in] new_ycnt						new number of rows
	//----------------------------------------------------------------------------------------
	Result<void> Resize(Int new_xcnt, Int new_ycnt)
	{
		iferr_scope;

		if (new_xcnt < 1 && new_ycnt < 1)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Invalid number of rows and columns"_s);

		if (new_xcnt == _xcnt && new_ycnt == _ycnt)
			return OK;

		_arr.Resize(new_xcnt * new_ycnt) iferr_return;

		_xcnt = new_xcnt;
		_ycnt = new_ycnt;

		return OK;
	}


	//----------------------------------------------------------------------------------------
	/// Copy matrix elements from src matrix.
	/// The number of rows and columns are resized if necessary.
	/// @param[in] src								source matrix
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const MatrixNxM& src)
	{
		iferr_scope;

		_arr.CopyFrom(src._arr) iferr_return;
		_xcnt = src._xcnt;
		_ycnt = src._ycnt;

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Operator to access a matrix element.
	/// @param[in] x									column
	/// @param[in] y									row
	/// @return												matrix element value
	//----------------------------------------------------------------------------------------
	TYPE& operator()(Int x, Int y)
	{
		DebugAssert(x >= 0 && x < _xcnt && y >= 0 && y < _ycnt);

		return _arr[x + y * _xcnt];
	}

	//----------------------------------------------------------------------------------------
	/// Operator to access a matrix element.
	/// @param[in] x									column
	/// @param[in] y									row
	/// @return												matrix element value
	//----------------------------------------------------------------------------------------
	const TYPE& operator()(const Int x, const Int y) const
	{
		DebugAssert(x >= 0 && x < _xcnt && y >= 0 && y < _ycnt);

		return _arr[x + y * _xcnt];
	}

	//----------------------------------------------------------------------------------------
	/// Get number of columns.
	/// @return												number of columns
	//----------------------------------------------------------------------------------------
	Int GetXCount() const
	{
		return _xcnt;
	}

	//----------------------------------------------------------------------------------------
	/// Get number of rows.
	/// @return												number of rows
	//----------------------------------------------------------------------------------------
	Int GetYCount() const
	{
		return _ycnt;
	}

	//----------------------------------------------------------------------------------------
	/// Reorganises the matrix so that the four quadrants
	/// ---------
	/// | A | B |
	/// ---------
	/// | C | D |
	/// ---------
	/// are then
	/// ---------
	/// | D | C |
	/// ---------
	/// | B | A |
	/// ---------
	/// This function is especially useful for dealing with FFT transformed data
	/// Note: If either number of rows or columns are not a multiple of 2 you get an error.
	//----------------------------------------------------------------------------------------
	Result<void> ShiftMatrix()
	{
		Int xcnt2 = _xcnt / 2;
		Int ycnt2 = _ycnt / 2;

		if (2 * xcnt2 != _xcnt || 2 * ycnt2 != _ycnt)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Rows and columns must be a multiple of 2"_s);

		for (Int j = 0; j < ycnt2; j++)
		{
			for (Int i = 0; i < xcnt2; i++)
			{
				Swap(_arr[i         + j * _xcnt], _arr[i + xcnt2 + (j + ycnt2) * _xcnt]);
				Swap(_arr[i + xcnt2 + j * _xcnt], _arr[i         + (j + ycnt2) * _xcnt]);
			}
		}

		return OK;
	}



	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		String str;

		str += "["_s;

		Int i = 0;
		for (Int y = 0; y < _ycnt; y++)
		{
			str += "("_s;

			for (Int x = 0; x < _xcnt; x++)
			{
				str += FormatString("@", _arr[i++]);

				if (x < _xcnt-1)
					str += ", "_s;
			}

			str += ")"_s;

			if (y < _ycnt-1)
				str += " | "_s;
		}

		str += "]"_s;

		return str;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(MatrixNxM, _xcnt, _ycnt, _arr);

private:
	BaseArray<TYPE> _arr;
	Int							_xcnt = 0;
	Int							_ycnt = 0;
};



// ----------------------------------------------------------------------------------------------------------------------
class MatrixNxMInterface
{
public:
	MatrixNxM<Generic>& _matrix;
	DataType _type;

	template <typename TYPE> MAXON_IMPLICIT MatrixNxMInterface(MatrixNxM<TYPE>& matrix) : _matrix((MatrixNxM<Generic>&) matrix), _type(GetDataType<TYPE>())
	{
	}

	const DataType& GetValueDataType() const
	{
		return _type;
	}

	MatrixNxM<Generic>& GetMatrix() const
	{
		return _matrix;
	}

};
class ConstMatrixNxMInterface
{
public:
	const MatrixNxM<Generic>& _matrix;
	DataType _type;

	template <typename TYPE> MAXON_IMPLICIT ConstMatrixNxMInterface(const MatrixNxM<TYPE>& matrix) : _matrix((const MatrixNxM<Generic>&) matrix), _type(GetDataType<TYPE>())
	{
	}

	const DataType& GetValueDataType() const
	{
		return _type;
	}

	const MatrixNxM<Generic>& GetMatrix() const
	{
		return _matrix;
	}
};


/// @}

/// Single-precision n x m matrix.
using MatrixNxM32 = MatrixNxM<Float32>;

/// Double-precision n x m matrix.
using MatrixNxM64 = MatrixNxM<Float64>;

/// single-precision complex n x m matrix.
using MatrixNxMComplex32 = MatrixNxM<Complex32>;

/// Double-precision complex n x m matrix.
using MatrixNxMComplex64 = MatrixNxM<Complex64>;


MAXON_DATATYPE(MatrixNxM32, "net.maxon.datatype.matrixnxm32");
MAXON_DATATYPE(MatrixNxM64, "net.maxon.datatype.matrixnxm64");
MAXON_DATATYPE(MatrixNxMComplex32, "net.maxon.datatype.matrixnxmcomplex32");
MAXON_DATATYPE(MatrixNxMComplex64, "net.maxon.datatype.matrixnxmcomplex64");


} // namespace maxon

#endif // MATRIX_NXM_H__
