#ifndef MATRIX_H__
#define MATRIX_H__

#include "maxon/vector.h"
#include "maxon/matrix2d.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

/// General 3&times;3 matrix template consisting of three column vectors v1, v2, v3.
template <typename V> struct SqrMat3
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

	/// The Z axis
	V v3;

	/// Default constructor, creates an identity matrix
	constexpr SqrMat3() : v1(ValueType(1), ValueType(0), ValueType(0)), v2(ValueType(0), ValueType(1), ValueType(0)), v3(ValueType(0), ValueType(0), ValueType(1))
	{
	}

	/// Initializes matrix from individual components
	constexpr SqrMat3(const V& v1_in, const V& v2_in, const V& v3_in) : v1(v1_in), v2(v2_in), v3(v3_in) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit constexpr SqrMat3(const SqrMat3<V2>& m) : v1(m.v1), v2(m.v2), v3(m.v3) { }

	/// Skips initialization of matrix (for better speed)
	explicit constexpr SqrMat3(ENUM_DONT_INITIALIZE v) : v1(maxon::DONT_INITIALIZE), v2(maxon::DONT_INITIALIZE), v3(maxon::DONT_INITIALIZE) { }

	/// Initializes matrix from 2d matrix. v3 is assigned Cross(v1, v2).GetNormalized()
	template <typename V2> explicit constexpr SqrMat3(const SqrMat2<V2>& m) :
		v1(m.v1), v2(m.v2), v3(ValueType(0), ValueType(0), (m.v1.x * m.v2.y > m.v1.y * m.v2.x) ? ValueType(1) : ValueType(-1)) { }

	/// Sets this matrix to an identity matrix.
	void SetIdentity()
	{
		v1 = V(ValueType(1), ValueType(0), ValueType(0));
		v2 = V(ValueType(0), ValueType(1), ValueType(0));
		v3 = V(ValueType(0), ValueType(0), ValueType(1));
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	V& operator [](Int idx)
	{
		DebugAssert((UInt) idx < 3);
		return (&v1)[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	const V& operator [](Int idx) const
	{
		DebugAssert((UInt) idx < 3);
		return (&v1)[idx];
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr SqrMat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat3<V2>& m2) const
	{
		return SqrMat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type>(v1 * m2.v1.x + v2 * m2.v1.y + v3 * m2.v1.z,
																																										v1 * m2.v2.x + v2 * m2.v2.y + v3 * m2.v2.z,
																																										v1 * m2.v3.x + v2 * m2.v3.y + v3 * m2.v3.z);
	}

	/// Transforms a vector by a matrix
	template <typename T, Int S> constexpr Vec3<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec3<T, S>& v) const
	{
		return Vec3<typename MultiplicativePromotion<ValueType, T>::type, 1>(v1.x*v.x + v2.x*v.y + v3.x*v.z,
																																				 v1.y*v.x + v2.y*v.y + v3.y*v.z,
																																				 v1.z*v.x + v2.z*v.y + v3.z*v.z);
	}

	/// Scales all matrix components by a scalar value
	friend constexpr SqrMat3 operator *(ValueTypeParam s, const SqrMat3& m)
	{
		return SqrMat3(s * m.v1, s * m.v2, s * m.v3);
	}

	/// Scales all matrix components by a scalar value
	constexpr SqrMat3 operator *(ValueTypeParam s) const
	{
		return SqrMat3(v1 * s, v2 * s, v3 * s);
	}

	/// Divides all matrix components by a scalar value. If s is 0.0 an identity matrix will be returned
	constexpr SqrMat3 operator /(ValueTypeParam s) const
	{
		if (s == ValueType(0))
			return SqrMat3();
		ValueType is = ValueType(1) / s;
		return SqrMat3(v1 * is, v2 * is, v3 * is);
	}

	/// Adds two matrices component-wise
	constexpr SqrMat3 operator +(const SqrMat3& m2) const
	{
		return SqrMat3(v1 + m2.v1, v2 + m2.v2, v3 + m2.v3);
	}

	/// Subtracts two matrices component-wise
	constexpr SqrMat3 operator -(const SqrMat3& m2) const
	{
		return SqrMat3(v1 - m2.v1, v2 - m2.v2, v3 - m2.v3);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												True if this and other are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const SqrMat3& other) const
	{
		return (v1 == other.v1) && (v2 == other.v2) && (v3 == other.v3);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												False if this and other are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const SqrMat3& other) const
	{
		return (v1 != other.v1) || (v2 != other.v2) || (v3 != other.v3);
	}

	/// Computes the determinant of this matrix.
	constexpr ValueType Det() const
	{
		return v1.x * (v2.y * v3.z - v3.y * v2.z) + v2.x * (v3.y * v1.z - v1.y * v3.z) + v3.x * (v1.y * v2.z - v2.y * v1.z);
	}

	/// Calculates the inverse matrix
	/// If no inverse can be calculated the result is the Identity matrix
	constexpr SqrMat3 operator ~() const
	{
		ValueType det = v1.x * (v2.y * v3.z - v3.y * v2.z) + v2.x * (v3.y * v1.z - v1.y * v3.z) + v3.x * (v1.y * v2.z - v2.y * v1.z);
		if (det == ValueType(0))
			return SqrMat3();

		det = ValueType(1) / det;
		return SqrMat3(V((v2.y * v3.z - v3.y * v2.z) * det,
										(v3.y * v1.z - v1.y * v3.z) * det,
										(v1.y * v2.z - v2.y * v1.z) * det),
									V((v2.z * v3.x - v3.z * v2.x) * det,
										(v3.z * v1.x - v1.z * v3.x) * det,
										(v1.z * v2.x - v2.z * v1.x) * det),
									V((v2.x * v3.y - v3.x * v2.y) * det,
										(v3.x * v1.y - v1.x * v3.y) * det,
										(v1.x * v2.y - v2.x * v1.y) * det));
	}

	/// Normalizes the length of all three axes
	constexpr void Normalize()
	{
		v1.Normalize();
		v2.Normalize();
		v3.Normalize();
	}

	/// Returns this matrix with all axis vectors normalized.
	constexpr SqrMat3 GetNormalized() const
	{
		return SqrMat3(v1.GetNormalized(), v2.GetNormalized(), v3.GetNormalized());
	}

	/// Returns the transposed matrix.
	constexpr SqrMat3 GetTransposed() const
	{
		return SqrMat3(V(v1.x, v2.x, v3.x), V(v1.y, v2.y, v3.y), V(v1.z, v2.z, v3.z));
	}

	constexpr V GetScale() const
	{
		return V(v1.GetLength(), v2.GetLength(), v3.GetLength());
	}

	/// Calculates the tensor matrix which allows to transform normal vectors for non-orthogonal matrices.
	/// The tensor matrix T of a matrix M is given by T = inverse(transpose(M)) * det(M), and its computation is faster than that of the inverse transpose.
	/// To transform a normal with a normalized result, use the formula transformedNormal = !(matrix.GetTensorMatrix() * normal).
	constexpr SqrMat3 GetTensorMatrix() const
	{
		return SqrMat3(V(v3.z * v2.y - v3.y * v2.z, v3.x * v2.z - v3.z * v2.x, v3.y * v2.x - v3.x * v2.y),
									V(v3.y * v1.z - v1.y * v3.z, v3.z * v1.x - v3.x * v1.z, v1.y * v3.x - v3.y * v1.x),
									V(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x));
	}

	/// Scales each axis by the respective components of the passed vector
	constexpr SqrMat3& operator *=(const V& v)
	{
		v1 *= v.x;
		v2 *= v.y;
		v3 *= v.z;
		return *this;
	}

	/// Scales each axis by the scalar
	constexpr SqrMat3& operator *=(ValueTypeParam r)
	{
		v1 *= r;
		v2 *= r;
		v3 *= r;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + v1.ToString(formatStatement) + ","_s + v2.ToString(formatStatement) + ","_s + v3.ToString(formatStatement) + ")"_s;
	}

	constexpr MAXON_OPERATOR_HASH(SqrMat3, v1, v2, v3);

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the matrix (see nullvalue.h for more details).
	/// @return												A null value of the matrix.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE constexpr const SqrMat3& NullValue()
	{
		return GetZeroRef<SqrMat3>();
	}
};

/// Matrix.
/// @image html matrix.png
/// The matrix has a dimension of 4&times;4 and consists of four rows and four columns. The first row is always "1, 0, 0, 0" and not stored in the class, which means
/// that there are 12 actual numbers used. These numbers are grouped into four vectors, one for the remaining numbers in each column. The four vectors
/// are called off, v1, v2 and v3, together these four vectors can be used to represent the coordinate system. A coordinate system consists of three axes,
/// one for each coordinate (X, Y and Z). The system also has a base position, from which the three axes originate. This base position is stored in off,
/// and the three axis vectors are stored in v1, v2 and v3 respectively.
/// For a rectangular, normalized matrix v3 equals the cross product of v1 and v2 (v1%v2).
/// C4D by default uses a left-handed coordinate system (see define COORDINATESYSTEM_LEFT_HANDED).
template <typename V> struct Mat3
{
	using ValueType = typename V::ValueType;
	using ValueTypeParam = typename ByValueParam<ValueType>::type;

	/// The type returned by comparisons. If the template argument for V is a vector of SIMD components,
	/// this will be a SIMD type, too, which contains the per-element results.
	using BoolType = typename V::BoolType;

	/// The translation vector
	V off;

	/// The 3&times;3 matrix for rotation, scale and shear.
	SqrMat3<V> sqmat;

	/// Default constructor, creates an identity matrix
	constexpr Mat3() : off(), sqmat() { }

	/// Initializes matrix from individual components
	constexpr Mat3(const V& off_in, const V& v1_in, const V& v2_in, const V& v3_in) : off(off_in), sqmat(v1_in, v2_in, v3_in) { }

	/// Initializes matrix from individual components
	constexpr Mat3(const V& off_in, const SqrMat3<V>& mat_in) : off(off_in), sqmat(mat_in) { }

	/// Initializes matrix from square matrix. The translation part is initialized to zero.
	MAXON_IMPLICIT constexpr Mat3(const SqrMat3<V>& mat_in) : off(), sqmat(mat_in) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit constexpr Mat3(const Mat3<V2>& m) : off(m.off), sqmat(m.sqmat) { }

	/// Skips initialization of matrix (for better speed)
	explicit constexpr Mat3(ENUM_DONT_INITIALIZE v) : off(maxon::DONT_INITIALIZE), sqmat(maxon::DONT_INITIALIZE)  { }

	/// Initializes matrix from 2d matrix. v3 is assigned Cross(v1, v2).GetNormalized()
	template <typename V2> explicit constexpr Mat3(const Mat2<V2>& m) : off(m.off), sqmat(m.sqmat) { }

	/// Sets this matrix to an identity matrix.
	constexpr void SetIdentity()
	{
		off.SetZero();
		sqmat.SetIdentity();
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr Mat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const Mat3<V2>& m2) const
	{
		using RV = typename MultiplicativePromotion<V, typename V2::ValueType>::type;
		return Mat3<RV>(RV(off) + sqmat.v1 * m2.off.x + sqmat.v2 * m2.off.y + sqmat.v3 * m2.off.z,
										sqmat.v1 * m2.sqmat.v1.x + sqmat.v2 * m2.sqmat.v1.y + sqmat.v3 * m2.sqmat.v1.z,
										sqmat.v1 * m2.sqmat.v2.x + sqmat.v2 * m2.sqmat.v2.y + sqmat.v3 * m2.sqmat.v2.z,
										sqmat.v1 * m2.sqmat.v3.x + sqmat.v2 * m2.sqmat.v3.y + sqmat.v3 * m2.sqmat.v3.z);
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> constexpr Mat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat3<V2>& m2) const
	{
		using RV = typename MultiplicativePromotion<V, typename V2::ValueType>::type;
		return Mat3<RV>(RV(off),
										sqmat.v1 * m2.v1.x + sqmat.v2 * m2.v1.y + sqmat.v3 * m2.v1.z,
										sqmat.v1 * m2.v2.x + sqmat.v2 * m2.v2.y + sqmat.v3 * m2.v2.z,
										sqmat.v1 * m2.v3.x + sqmat.v2 * m2.v3.y + sqmat.v3 * m2.v3.z);
	}

	/// Transforms a point by a matrix
	template <typename T, Int S> constexpr Vec3<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec3<T, S>& v) const
	{
		return Vec3<typename MultiplicativePromotion<ValueType, T>::type, 1>(off.x + sqmat.v1.x*v.x + sqmat.v2.x*v.y + sqmat.v3.x*v.z,
																																				 off.y + sqmat.v1.y*v.x + sqmat.v2.y*v.y + sqmat.v3.y*v.z,
																																				 off.z + sqmat.v1.z*v.x + sqmat.v2.z*v.y + sqmat.v3.z*v.z);
	}

	/// Scales all matrix components by a scalar value
	friend constexpr Mat3 operator *(ValueTypeParam s, const Mat3& m)
	{
		return Mat3(s * m.off, s * m.sqmat.v1, s * m.sqmat.v2, s * m.sqmat.v3);
	}

	/// Scales all matrix components by a scalar value
	constexpr Mat3 operator *(ValueTypeParam s) const
	{
		return Mat3(off * s, sqmat.v1 * s, sqmat.v2 * s, sqmat.v3 * s);
	}

	/// Divides all matrix components by a scalar value. If s is 0.0 an identity matrix will be returned
	constexpr Mat3 operator /(ValueTypeParam s) const
	{
		if (s == ValueType(0))
			return Mat3();
		ValueType is = ValueType(1) / s;
		return Mat3(off * is, sqmat.v1 * is, sqmat.v2 * is, sqmat.v3 * is);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												True if this and other are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator ==(const Mat3& other) const
	{
		return (sqmat.v1 == other.sqmat.v1) && (sqmat.v2 == other.sqmat.v2) && (sqmat.v3 == other.sqmat.v3) && (off == other.off);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												False if this and other are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	constexpr BoolType operator !=(const Mat3& other) const
	{
		return (sqmat.v1 != other.sqmat.v1) || (sqmat.v2 != other.sqmat.v2) || (sqmat.v3 != other.sqmat.v3) || (off != other.off);
	}

	/// Calculates the inverse matrix
	/// If no inverse can be calculated the result is the Identity matrix
	constexpr Mat3 operator ~() const
	{
		ValueType det = sqmat.v1.x * (sqmat.v2.y * sqmat.v3.z - sqmat.v3.y * sqmat.v2.z) + sqmat.v2.x * (sqmat.v3.y * sqmat.v1.z - sqmat.v1.y * sqmat.v3.z)
			+ sqmat.v3.x * (sqmat.v1.y * sqmat.v2.z - sqmat.v2.y * sqmat.v1.z);
		if (det == ValueType(0))
			return Mat3();

		det = ValueType(1) / det;
		return Mat3(V((sqmat.v2.x * (off.y * sqmat.v3.z - sqmat.v3.y * off.z) +
										 sqmat.v3.x * (off.z * sqmat.v2.y - off.y * sqmat.v2.z) +
										 off.x * (sqmat.v3.y * sqmat.v2.z - sqmat.v2.y * sqmat.v3.z)) * det,
										(sqmat.v3.x * (off.y * sqmat.v1.z - sqmat.v1.y * off.z) +
										 off.x * (sqmat.v1.y * sqmat.v3.z - sqmat.v3.y * sqmat.v1.z) +
										 sqmat.v1.x * (sqmat.v3.y * off.z - off.y * sqmat.v3.z)) * det,
										(off.x * (sqmat.v2.y * sqmat.v1.z - sqmat.v1.y * sqmat.v2.z) +
										 sqmat.v1.x * (sqmat.v2.z * off.y - sqmat.v2.y * off.z) +
										 sqmat.v2.x * (off.z * sqmat.v1.y - off.y * sqmat.v1.z)) * det),
									V((sqmat.v2.y * sqmat.v3.z - sqmat.v3.y * sqmat.v2.z) * det,
										(sqmat.v3.y * sqmat.v1.z - sqmat.v1.y * sqmat.v3.z) * det,
										(sqmat.v1.y * sqmat.v2.z - sqmat.v2.y * sqmat.v1.z) * det),
									V((sqmat.v2.z * sqmat.v3.x - sqmat.v3.z * sqmat.v2.x) * det,
										(sqmat.v3.z * sqmat.v1.x - sqmat.v1.z * sqmat.v3.x) * det,
										(sqmat.v1.z * sqmat.v2.x - sqmat.v2.z * sqmat.v1.x) * det),
									V((sqmat.v2.x * sqmat.v3.y - sqmat.v3.x * sqmat.v2.y) * det,
										(sqmat.v3.x * sqmat.v1.y - sqmat.v1.x * sqmat.v3.y) * det,
										(sqmat.v1.x * sqmat.v2.y - sqmat.v2.x * sqmat.v1.y) * det));
	}

	/// Returns this matrix with all axis vectors normalized.
	constexpr Mat3 GetNormalized() const
	{
		return Mat3(off, sqmat.v1.GetNormalized(), sqmat.v2.GetNormalized(), sqmat.v3.GetNormalized());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return "("_s + sqmat.v1.ToString(formatStatement) + ","_s + sqmat.v2.ToString(formatStatement) + ","_s + sqmat.v3.ToString(formatStatement) + ","_s + off.ToString(formatStatement) + ")"_s;
	}

	constexpr MAXON_OPERATOR_HASH(Mat3, sqmat, off);

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the matrix (see nullvalue.h for more details).
	/// @return												A null value of the matrix.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE constexpr const Mat3& NullValue()
	{
		return GetZeroRef<Mat3>();
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the minimum of each component.
	//----------------------------------------------------------------------------------------
	friend constexpr Mat3 Min(const Mat3& a, const Mat3& other)
	{
		return Mat3(Min(a.off, other.off), Min(a.sqmat.v1, other.sqmat.v1), Min(a.sqmat.v2, other.sqmat.v2), Min(a.sqmat.v3, other.sqmat.v3));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the maximum of each component.
	//----------------------------------------------------------------------------------------
	friend constexpr Mat3 Max(const Mat3& a, const Mat3& other)
	{
		return Mat3(Max(a.off, other.off), Max(a.sqmat.v1, other.sqmat.v1), Max(a.sqmat.v2, other.sqmat.v2), Max(a.sqmat.v3, other.sqmat.v3));
	}
};

/// Multiplies two matrices.
/// The rule is m1 AFTER m2
/// If you transform a point with the result matrix this is identical to first transforming with m2 and then with m1
template <typename V, typename V2> inline Mat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqrMat3<V>& m, const Mat3<V2>& m2)
{
	return Mat3<typename MultiplicativePromotion<V, typename V2::ValueType>::type>(m.v1 * m2.off.x + m.v2 * m2.off.y + m.v3 * m2.off.z,
																																								 m.v1 * m2.sqmat.v1.x + m.v2 * m2.sqmat.v1.y + m.v3 * m2.sqmat.v1.z,
																																								 m.v1 * m2.sqmat.v2.x + m.v2 * m2.sqmat.v2.y + m.v3 * m2.sqmat.v2.z,
																																								 m.v1 * m2.sqmat.v3.x + m.v2 * m2.sqmat.v3.y + m.v3 * m2.sqmat.v3.z);
}

/// Single-precision 3&times;3 matrix.
using SquareMatrix32 = SqrMat3<Vector32>;

/// Double-precision 3&times;3 matrix.
using SquareMatrix64 = SqrMat3<Vector64>;

/// 3&times;3 matrix with the precision of Float.
using SquareMatrix = SqrMat3<Vector>;

/// Single-Precision Matrix.
/// @image html matrix.png
/// The matrix has a dimension of 4&times;4 and consists of four rows and four columns. The first row is always "1, 0, 0, 0" and not stored in the class, which means
/// that there are 12 actual numbers used. These numbers are grouped into four vectors, one for the remaining numbers in each column. The four vectors
/// are called off, v1, v2 and v3, together these four vectors can be used to represent the coordinate system. A coordinate system consists of three axes,
/// one for each coordinate (X, Y and Z). The system also has a base position, from which the three axes originate. This base position is stored in off,
/// and the three axis vectors are stored in v1, v2 and v3 respectively.
/// For a rectangular, normalized matrix v3 equals the cross product of v1 and v2 (v1%v2).
/// C4D by default uses a left-handed coordinate system (see define COORDINATESYSTEM_LEFT_HANDED).
using Matrix32 = Mat3<Vector32>;

/// Double-Precision Matrix.
/// @image html matrix.png
/// The matrix has a dimension of 4&times;4 and consists of four rows and four columns. The first row is always "1, 0, 0, 0" and not stored in the class, which means
/// that there are 12 actual numbers used. These numbers are grouped into four vectors, one for the remaining numbers in each column. The four vectors
/// are called off, v1, v2 and v3, together these four vectors can be used to represent the coordinate system. A coordinate system consists of three axes,
/// one for each coordinate (X, Y and Z). The system also has a base position, from which the three axes originate. This base position is stored in off,
/// and the three axis vectors are stored in v1, v2 and v3 respectively.
/// For a rectangular, normalized matrix v3 equals the cross product of v1 and v2 (v1%v2).
/// C4D by default uses a left-handed coordinate system (see define COORDINATESYSTEM_LEFT_HANDED).
using Matrix64 = Mat3<Vector64>;

/// Matrix with the precision of Float.
/// @image html matrix.png
/// The matrix has a dimension of 4&times;4 and consists of four rows and four columns. The first row is always "1, 0, 0, 0" and not stored in the class, which means
/// that there are 12 actual numbers used. These numbers are grouped into four vectors, one for the remaining numbers in each column. The four vectors
/// are called off, v1, v2 and v3, together these four vectors can be used to represent the coordinate system. A coordinate system consists of three axes,
/// one for each coordinate (X, Y and Z). The system also has a base position, from which the three axes originate. This base position is stored in off,
/// and the three axis vectors are stored in v1, v2 and v3 respectively.
/// For a rectangular, normalized matrix v3 equals the cross product of v1 and v2 (v1%v2).
/// C4D by default uses a left-handed coordinate system (see define COORDINATESYSTEM_LEFT_HANDED).
using Matrix = Mat3<Vector>;

/// @}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(SqrMat3<T>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	return ParametricTypes::SqrMat().Instantiate(t, ToSingletonBlock(Int64(3)));
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Mat3<T>**, OverloadRank1)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	Member tt[] = {t, t};
	return ParametricTypes::Mat().Instantiate(tt, ToSingletonBlock(Int64(3)));
}

template <typename T> struct IsZeroInitialized<SqrMat3<T>> : public IsZeroInitialized<T> { };

template <typename T> struct IsZeroInitialized<Mat3<T>> : public IsZeroInitialized<T> { };

} // namespace maxon

#endif // MATRIX_H__
