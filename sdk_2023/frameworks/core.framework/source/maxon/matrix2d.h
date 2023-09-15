#ifndef MATRIX2D_H__
#define MATRIX2D_H__

#include "maxon/vector2d.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

/// General 2&times;2 matrix template consisting of two column vectors v1, v2.
template <typename V> struct SqrMat2
{
	using VectorStrideType = typename V::VectorStrideType;
	using ValueType = typename V::ValueType;
	using ValueTypeParam = typename ByValueParam<ValueType>::type;

	/// The type returned by comparisons. If the template argument for V is a vector of SIMD components,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = typename V::BoolType;

	/// The X axis
	V v1;

	/// The Y axis
	V v2;

	/// Default constructor, creates an identity matrix
	constexpr SqrMat2() : v1(ValueType(1), ValueType(0)), v2(ValueType(0), ValueType(1))
	{
	}

	/// Initializes matrix from individual components
	constexpr SqrMat2(const V& v1_in, const V& v2_in) : v1(v1_in), v2(v2_in) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit constexpr SqrMat2(const SqrMat2<V2>& m) : v1(m.v1), v2(m.v2) { }

	/// Skips initialization of matrix (for better speed)
	explicit constexpr SqrMat2(ENUM_DONT_INITIALIZE v) : v1(v), v2(v) { }

	/// Sets this matrix to an identity matrix.
	constexpr void SetIdentity()
	{
		v1 = V(ValueType(1), ValueType(0));
		v2 = V(ValueType(0), ValueType(1));
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	V& operator [](Int idx)
	{
		DebugAssert((UInt) idx < 2);
		return (&v1)[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	const V& operator [](Int idx) const
	{
		DebugAssert((UInt) idx < 2);
		return (&v1)[idx];
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr SqrMat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat2<V2>& m2) const
	{
		return SqrMat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type>(v1 * m2.v1.x + v2 * m2.v1.y, v1 * m2.v2.x + v2 * m2.v2.y);
	}

	/// Transforms a point by a matrix
	template <typename T, Int S> constexpr Vec2<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec2<T, S>& v) const
	{
		return Vec2<typename MultiplicativePromotion<ValueType, T>::type, 1>(v1.x * v.x + v2.x * v.y, v1.y * v.x + v2.y * v.y);
	}

	/// Scales all matrix components by a scalar value
	friend constexpr SqrMat2 operator *(ValueTypeParam s, const SqrMat2& m)
	{
		return SqrMat2(s * m.v1, s * m.v2);
	}

	/// Scales all matrix components by a scalar value
	constexpr SqrMat2 operator *(ValueTypeParam s) const
	{
		return SqrMat2(v1 * s, v2 * s);
	}

	/// Divides all matrix components by a scalar value. If s is 0.0 an identity matrix will be returned
	constexpr SqrMat2 operator /(ValueTypeParam s) const
	{
		if (s == ValueType(0))
			return SqrMat2();
		ValueType is = ValueType(1) / s;
		return SqrMat2(v1 * is, v2 * is);
	}

	/// Adds two matrices component-wise
	constexpr SqrMat2 operator +(const SqrMat2& m2) const
	{
		return SqrMat2(v1 + m2.v1, v2 + m2.v2);
	}

	/// Subtracts two matrices component-wise
	constexpr SqrMat2 operator -(const SqrMat2& m2) const
	{
		return SqrMat2(v1 - m2.v1, v2 - m2.v2);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												True if this and other are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const SqrMat2& other) const
	{
		return (v1 == other.v1) && (v2 == other.v2);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												False if this and other are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const SqrMat2& other) const
	{
		return (v1 != other.v1) || (v2 != other.v2);
	}

	/// Computes the determinant of this matrix.
	constexpr ValueType Det() const
	{
		return v1.x * v2.y - v2.x * v1.y;
	}

	/// Calculates the inverse matrix
	/// If no inverse can be calculated the result is the Identity matrix
	constexpr SqrMat2 operator ~() const
	{
		ValueType det = v1.x * v2.y - v2.x * v1.y;
		if (det == ValueType(0))
			return SqrMat2();

		det = ValueType(1) / det;
		return SqrMat2(V(v2.y * det, -v1.y * det), V(-v2.x * det, v1.x * det));
	}

	/// Normalizes the length of all three axes
	constexpr void Normalize()
	{
		v1.Normalize();
		v2.Normalize();
	}

	/// Returns this matrix with all axis vectors normalized.
	constexpr SqrMat2 GetNormalized() const
	{
		return SqrMat2(v1.GetNormalized(), v2.GetNormalized());
	}

	/// Scales each axis by the respective components of the passed vector
	constexpr SqrMat2& operator *=(const V& v)
	{
		v1 *= v.x;
		v2 *= v.y;
		return *this;
	}

	/// Scales each axis by the scalar
	constexpr SqrMat2& operator *=(ValueTypeParam r)
	{
		v1 *= r;
		v2 *= r;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + v1.ToString(formatStatement) + ","_s + v2.ToString(formatStatement) + ")"_s;
	}

	constexpr MAXON_OPERATOR_HASH(SqrMat2, v1, v2);

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the matrix (see nullvalue.h for more details).
	/// @return												A null value of the matrix.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE constexpr const SqrMat2& NullValue()
	{
		return GetZeroRef<SqrMat2>();
	}
};

/// General 2d Matrix template.
/// The matrix has a dimension of 3&times;3 and consists of three rows and three columns. The first row is always "1, 0, 0" and not stored in the class, which means
/// that there are 6 actual numbers used. These numbers are grouped into three vectors, one for the remaining numbers in each column. The three vectors
/// are called off, v1 and v2, together these three vectors can be used to represent the coordinate system. A coordinate system consists of two axes,
/// one for each coordinate (X and Y). The system also has a base position, from which the two axes originate. This base position is stored in off,
/// and the two axis vectors are stored in v1 and v2 respectively
template <typename V> struct Mat2
{
	using ValueType = typename V::ValueType;
	using ValueTypeParam = typename ByValueParam<ValueType>::type;

	/// The type returned by comparisons. If the template argument for V is a vector of SIMD components,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = typename V::BoolType;

	/// The translation vector
	V off;

	/// The 2&times;2 matrix for rotation, scale and shear.
	SqrMat2<V> sqmat;

	/// Default constructor, creates an identity matrix
	constexpr Mat2() : off(), sqmat()
	{
	}

	/// Initializes matrix from individual components
	constexpr Mat2(const V& off_in, const V& v1_in, const V& v2_in) : off(off_in), sqmat(v1_in, v2_in) { }

	/// Initializes matrix from individual components
	constexpr Mat2(const V& off_in, const SqrMat2<V>& mat_in) : off(off_in), sqmat(mat_in) { }

	/// Initializes matrix from square matrix. The translation part is initialized to zero.
	MAXON_IMPLICIT constexpr Mat2(const SqrMat2<V>& mat_in) : off(), sqmat(mat_in) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit constexpr Mat2(const Mat2<V2>& m) : off(m.off), sqmat(m.sqmat) { }

	/// Skips initialization of matrix (for better speed)
	explicit constexpr Mat2(ENUM_DONT_INITIALIZE v) : off(v), sqmat(v) { }

	/// Sets this matrix to an identity matrix.
	constexpr void SetIdentity()
	{
		off.SetZero();
		sqmat.SetIdentity();
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr Mat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const Mat2<V2>& m2) const
	{
		using RV = typename MultiplicativePromotion<V, typename V2::ValueType>::type;
		return Mat2<RV>(RV(off) + sqmat.v1 * m2.off.x + sqmat.v2 * m2.off.y,
										sqmat.v1 * m2.sqmat.v1.x + sqmat.v2 * m2.sqmat.v1.y,
										sqmat.v1 * m2.sqmat.v2.x + sqmat.v2 * m2.sqmat.v2.y);
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr Mat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat2<V2>& m2) const
	{
		using RV = typename MultiplicativePromotion<V, typename V2::ValueType>::type;
		return Mat2<RV>(RV(off),
										sqmat.v1 * m2.v1.x + sqmat.v2 * m2.v1.y,
										sqmat.v1 * m2.v2.x + sqmat.v2 * m2.v2.y);
	}

	/// Transforms a point by a matrix
	template <typename T, Int S> constexpr Vec2<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec2<T, S>& v) const
	{
		return Vec2<typename MultiplicativePromotion<ValueType, T>::type, 1>(off.x + sqmat.v1.x*v.x + sqmat.v2.x*v.y,
																																				 off.y + sqmat.v1.y*v.x + sqmat.v2.y*v.y);
	}

	/// Scales all matrix components by a scalar value
	friend constexpr Mat2 operator *(ValueTypeParam s, const Mat2& m)
	{
		return Mat2(s * m.off, s * m.sqmat.v1, s * m.sqmat.v2);
	}

	/// Scales all matrix components by a scalar value
	constexpr Mat2 operator *(ValueTypeParam s) const
	{
		return Mat2(off * s, sqmat.v1 * s, sqmat.v2 * s);
	}

	/// Divides all matrix components by a scalar value. If s is 0.0 an identity matrix will be returned
	constexpr Mat2 operator /(ValueTypeParam s) const
	{
		if (s == ValueType(0))
			return Mat2();
		ValueType is = ValueType(1) / s;
		return Mat2(off * is, sqmat.v1 * is, sqmat.v2 * is);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												True if this and other are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const Mat2& other) const
	{
		return (sqmat.v1 == other.sqmat.v1) && (sqmat.v2 == other.sqmat.v2) && (off == other.off);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												False if this and other are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const Mat2& other) const
	{
		return (sqmat.v1 != other.sqmat.v1) || (sqmat.v2 != other.sqmat.v2) || (off != other.off);
	}

	/// Calculates the inverse matrix
	/// If no inverse can be calculated the result is the Identity matrix
	constexpr Mat2 operator ~() const
	{
		ValueType det = sqmat.v1.x * sqmat.v2.y - sqmat.v2.x * sqmat.v1.y;
		if (det == ValueType(0))
			return Mat2();

		det = ValueType(1) / det;
		return Mat2(V((off.y * sqmat.v2.x - off.x * sqmat.v2.y) * det, (off.x * sqmat.v1.y - off.y * sqmat.v1.x) * det),
								V(sqmat.v2.y * det, -sqmat.v1.y * det),
								V(-sqmat.v2.x * det, sqmat.v1.x * det));
	}

	/// Returns this matrix with all axis vectors normalized.
	constexpr Mat2 GetNormalized() const
	{
		return Mat2(off, sqmat.v1.GetNormalized(), sqmat.v2.GetNormalized());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + sqmat.v1.ToString(formatStatement) + ","_s + sqmat.v2.ToString(formatStatement) + ","_s + off.ToString(formatStatement) + ")"_s;
	}

	constexpr MAXON_OPERATOR_HASH(Mat2, sqmat, off);

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the matrix (see nullvalue.h for more details).
	/// @return												A null value of the matrix.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE constexpr const Mat2& NullValue()
	{
		return GetZeroRef<Mat2>();
	}
};

/// Multiplies two matrices.
/// The rule is m1 AFTER m2
/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
template <typename V, typename V2> inline Mat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat2<V>& m, const Mat2<V2>& m2)
{
	return Mat2<typename MultiplicativePromotion<V, typename V2::ValueType>::type>(m.v1 * m2.off.x + m.v2 * m2.off.y,
																																								 m.v1 * m2.sqmat.v1.x + m.v2 * m2.sqmat.v1.y,
																																								 m.v1 * m2.sqmat.v2.x + m.v2 * m2.sqmat.v2.y);
}

/// Single-precision 2&times;2 matrix.
using SquareMatrix2d32 = SqrMat2<Vector2d32>;

/// Double-precision 2&times;2 matrix.
using SquareMatrix2d64 = SqrMat2<Vector2d64>;

/// 2&times;2 matrix with the precision of Float.
using SquareMatrix2d = SqrMat2<Vector2d>;

/// Single-Precision Matrix.
/// The matrix has a dimension of 3&times;3 and consists of three rows and three columns. The first row is always "1, 0, 0" and not stored in the class, which means
/// that there are 6 actual numbers used. These numbers are grouped into three vectors, one for the remaining numbers in each column. The three vectors
/// are called off, v1 and v2, together these three vectors can be used to represent the coordinate system. A coordinate system consists of two axes,
/// one for each coordinate (X and Y). The system also has a base position, from which the two axes originate. This base position is stored in off,
/// and the two axis vectors are stored in v1 and v2 respectively
using Matrix2d32 = Mat2<Vector2d32>;

/// Double-Precision Matrix.
/// The matrix has a dimension of 3&times;3 and consists of three rows and three columns. The first row is always "1, 0, 0" and not stored in the class, which means
/// that there are 6 actual numbers used. These numbers are grouped into three vectors, one for the remaining numbers in each column. The three vectors
/// are called off, v1 and v2, together these three vectors can be used to represent the coordinate system. A coordinate system consists of two axes,
/// one for each coordinate (X and Y). The system also has a base position, from which the two axes originate. This base position is stored in off,
/// and the two axis vectors are stored in v1 and v2 respectively
using Matrix2d64 = Mat2<Vector2d64>;

/// Matrix with the precision of Float.
/// The matrix has a dimension of 3&times;3 and consists of three rows and three columns. The first row is always "1, 0, 0" and not stored in the class, which means
/// that there are 6 actual numbers used. These numbers are grouped into three vectors, one for the remaining numbers in each column. The three vectors
/// are called off, v1 and v2, together these three vectors can be used to represent the coordinate system. A coordinate system consists of two axes,
/// one for each coordinate (X and Y). The system also has a base position, from which the two axes originate. This base position is stored in off,
/// and the two axis vectors are stored in v1 and v2 respectively
using Matrix2d = Mat2<Vector2d>;

/// @}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(SqrMat2<T>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	return ParametricTypes::SqrMat().Instantiate(t, ToSingletonBlock(Int64(2)));
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Mat2<T>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	Member tt[] = {t, t};
	return ParametricTypes::Mat().Instantiate(tt, ToSingletonBlock(Int64(2)));
}

template <typename T> struct IsZeroInitialized<SqrMat2<T>> : public IsZeroInitialized<T> { };

template <typename T> struct IsZeroInitialized<Mat2<T>> : public IsZeroInitialized<T> { };


} // namespace maxon

#endif // MATRIX2D_H__
