#ifndef MATRIX4D_H__
#define MATRIX4D_H__

#include "maxon/vector4d.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

template <typename V> struct SqMat4
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

	/// The W axis
	V v4;

	/// Default constructor, creates an identity matrix
	SqMat4() : v1(ValueType(1), ValueType(0), ValueType(0), ValueType(0)), v2(ValueType(0), ValueType(1), ValueType(0), ValueType(0)),
					 v3(ValueType(0), ValueType(0), ValueType(1), ValueType(0)), v4(ValueType(0), ValueType(0), ValueType(0), ValueType(1))
	{
	}

	/// Initializes matrix from individual components
	SqMat4(const V& v1_in, const V& v2_in, const V& v3_in, const V& v4_in) : v1(v1_in), v2(v2_in), v3(v3_in), v4(v4_in) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit SqMat4(const SqMat4<V2>& m) : v1(m.v1), v2(m.v2), v3(m.v3), v4(m.v4) { }

	/// Initializes matrix from another matrix
	template <typename V2> explicit SqMat4(const Mat3<V2>& m) : v1(m.sqmat.v1, typename V2::ValueType(0)), v2(m.sqmat.v2, typename V2::ValueType(0)), v3(m.sqmat.v3, typename V2::ValueType(0)), v4(m.off, typename V2::ValueType(1)) { }

	/// Skips initialization of matrix (for better speed)
	explicit SqMat4(ENUM_DONT_INITIALIZE v) : v1(v), v2(v), v3(v), v4(v) { }

	/// Sets this matrix to an identity matrix.
	void SetIdentity()
	{
		v1 = V(ValueType(1), ValueType(0), ValueType(0), ValueType(0));
		v2 = V(ValueType(0), ValueType(1), ValueType(0), ValueType(0));
		v3 = V(ValueType(0), ValueType(0), ValueType(1), ValueType(0));
		v4 = V(ValueType(0), ValueType(0), ValueType(0), ValueType(1));
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	V& operator [](Int idx)
	{
		DebugAssert((UInt) idx < 4);
		return (&v1)[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const index access to the matrix components.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Matrix component.
	//----------------------------------------------------------------------------------------
	const V& operator [](Int idx) const
	{
		DebugAssert((UInt) idx < 4);
		return (&v1)[idx];
	}

	Mat3<Vec3<ValueType, 1>> GetMatrix3d()
	{
		return Mat3<Vec3<ValueType, 1>>(v4.GetVector3(), v1.GetVector3(), v2.GetVector3(), v3.GetVector3());
	}

	/// Multiplies two matrices.
	/// The rule is m1 AFTER m2
	/// If you transform a vector with the result matrix this is identical to first transforming with m2 and then with m1
	template <typename V2> SqMat4<typename MultiplicativePromotion<V, typename V2::ValueType>::type> operator *(const SqMat4<V2>& m2) const
	{
		return SqMat4<typename MultiplicativePromotion<V, typename V2::ValueType>::type>(v1 * m2.v1.x + v2 * m2.v1.y + v3 * m2.v1.z + v4 * m2.v1.w,
																																										v1 * m2.v2.x + v2 * m2.v2.y + v3 * m2.v2.z + v4 * m2.v2.w,
																																										v1 * m2.v3.x + v2 * m2.v3.y + v3 * m2.v3.z + v4 * m2.v3.w,
																																										v1 * m2.v4.x + v2 * m2.v4.y + v3 * m2.v4.z + v4 * m2.v4.w);
	}

	/// Multiplies a 4d vector by a matrix
	template <typename T, Int S> Vec4<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec4<T, S>& v) const
	{
		return Vec4<typename MultiplicativePromotion<ValueType, T>::type, 1>(v1.x*v.x + v2.x*v.y + v3.x*v.z + v4.x*v.w,
																																				 v1.y*v.x + v2.y*v.y + v3.y*v.z + v4.y*v.w,
																																				 v1.z*v.x + v2.z*v.y + v3.z*v.z + v4.z*v.w,
																																				 v1.w*v.x + v2.w*v.y + v3.w*v.z + v4.w*v.w);
	}

	/// Transforms a 3d vector by a matrix
	template <typename T, Int S> Vec3<typename MultiplicativePromotion<ValueType, T>::type, 1> operator *(const Vec3<T, S>& v) const
	{
		using P = typename MultiplicativePromotion<ValueType, T>::type;
		Vec4<P, 1> t = Vec4<P, 1>(v1.x*v.x + v2.x*v.y + v3.x*v.z + v4.x,
															v1.y*v.x + v2.y*v.y + v3.y*v.z + v4.y,
															v1.z*v.x + v2.z*v.y + v3.z*v.z + v4.z,
															v1.w*v.x + v2.w*v.y + v3.w*v.z + v4.w);
		t.NormalizeW();
		return t.GetVector3();
	}

	/// Scales all matrix components by a scalar value
	friend SqMat4 operator *(ValueTypeParam s, const SqMat4& m)
	{
		return SqMat4(s * m.v1, s * m.v2, s * m.v3, s * m.v4);
	}

	/// Scales all matrix components by a scalar value
	SqMat4 operator *(ValueTypeParam s) const
	{
		return SqMat4(v1 * s, v2 * s, v3 * s, v4 * s);
	}

	/// Divides all matrix components by a scalar value. If s is 0.0 an identity matrix will be returned
	SqMat4 operator /(ValueTypeParam s) const
	{
		if (s == ValueType(0))
			return SqMat4();
		ValueType is = ValueType(1) / s;
		return SqMat4(v1 * is, v2 * is, v3 * is, v4 * is);
	}

	/// Adds two matrices component-wise
	SqMat4 operator +(const SqMat4& m2) const
	{
		return SqMat4(v1 + m2.v1, v2 + m2.v2, v3 + m2.v3, v4 + m2.v4);
	}

	/// Subtracts two matrices component-wise
	SqMat4 operator -(const SqMat4& m2) const
	{
		return SqMat4(v1 - m2.v1, v2 - m2.v2, v3 - m2.v3, v4 - m2.v4);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												True if this and other are equal, otherwise false.
	//----------------------------------------------------------------------------------------
	BoolType operator ==(const SqMat4& other) const
	{
		return (v1 == other.v1) && (v2 == other.v2) && (v3 == other.v3) && (v4 == other.v4);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] other							Comparison matrix.
	/// @return												False if this and other are equal, otherwise true.
	//----------------------------------------------------------------------------------------
	BoolType operator !=(const SqMat4& other) const
	{
		return (v1 != other.v1) || (v2 != other.v2) || (v3 != other.v3) || (v4 != other.v4);
	}

	/// Computes the determinant of this matrix.
	ValueType Det() const
	{
		return v1.x * Det3(v2.y, v3.y, v4.y, v2.z, v3.z, v4.z, v2.w, v3.w, v4.w)
			- v1.y * Det3(v2.x, v3.x, v4.x, v2.z, v3.z, v4.z, v2.w, v3.w, v4.w)
			+ v1.z * Det3(v2.x, v3.x, v4.x, v2.y, v3.y, v4.y, v2.w, v3.w, v4.w)
			- v1.w * Det3(v2.x, v3.x, v4.x, v2.y, v3.y, v4.y, v2.z, v3.z, v4.z);
	}

	/// Calculates the inverse matrix
	/// If no inverse can be calculated the result is the Identity matrix
	SqMat4 operator ~() const
	{
		V i1(Det3(v2.y, v3.y, v4.y, v2.z, v3.z, v4.z, v2.w, v3.w, v4.w),
				 -Det3(v1.y, v3.y, v4.y, v1.z, v3.z, v4.z, v1.w, v3.w, v4.w),
					Det3(v1.y, v2.y, v4.y, v1.z, v2.z, v4.z, v1.w, v2.w, v4.w),
				 -Det3(v1.y, v2.y, v3.y, v1.z, v2.z, v3.z, v1.w, v2.w, v3.w));
		V i2(-Det3(v2.x, v3.x, v4.x, v2.z, v3.z, v4.z, v2.w, v3.w, v4.w),
					Det3(v1.x, v3.x, v4.x, v1.z, v3.z, v4.z, v1.w, v3.w, v4.w),
				 -Det3(v1.x, v2.x, v4.x, v1.z, v2.z, v4.z, v1.w, v2.w, v4.w),
					Det3(v1.x, v2.x, v3.x, v1.z, v2.z, v3.z, v1.w, v2.w, v3.w));
		V i3(Det3(v2.x, v3.x, v4.x, v2.y, v3.y, v4.y, v2.w, v3.w, v4.w),
				 -Det3(v1.x, v3.x, v4.x, v1.y, v3.y, v4.y, v1.w, v3.w, v4.w),
					Det3(v1.x, v2.x, v4.x, v1.y, v2.y, v4.y, v1.w, v2.w, v4.w),
				 -Det3(v1.x, v2.x, v3.x, v1.y, v2.y, v3.y, v1.w, v2.w, v3.w));
		V i4(-Det3(v2.x, v3.x, v4.x, v2.y, v3.y, v4.y, v2.z, v3.z, v4.z),
					Det3(v1.x, v3.x, v4.x, v1.y, v3.y, v4.y, v1.z, v3.z, v4.z),
				 -Det3(v1.x, v2.x, v4.x, v1.y, v2.y, v4.y, v1.z, v2.z, v4.z),
					Det3(v1.x, v2.x, v3.x, v1.y, v2.y, v3.y, v1.z, v2.z, v3.z));
		ValueType det = v1.x * i1.x + v1.y * i2.x + v1.z * i3.x + v1.w * i4.x;
		if (det == ValueType(0))
		{
			return SqMat4();
		}
		det = ValueType(1) / det;
		return SqMat4(i1 * det, i2 * det, i3 * det, i4 * det);
	}

	/// Normalizes the length of all four axes
	void Normalize()
	{
		v1.Normalize();
		v2.Normalize();
		v3.Normalize();
		v4.Normalize();
	}

	/// Returns this matrix with all vectors normalized.
	SqMat4 GetNormalized() const
	{
		return SqMat4(v1.GetNormalized(), v2.GetNormalized(), v3.GetNormalized(), v4.GetNormalized());
	}

	/// Returns the transposed matrix.
	SqMat4 GetTransposed() const
	{
		return SqMat4(V(v1.x, v2.x, v3.x, v4.x), V(v1.y, v2.y, v3.y, v4.y), V(v1.z, v2.z, v3.z, v4.z), V(v1.w, v2.w, v3.w, v4.w));
	}

	/// Scales each axis by the respective components of the passed vector
	SqMat4& operator *=(const V& v)
	{
		v1 *= v.x;
		v2 *= v.y;
		v3 *= v.z;
		v4 *= v.w;
		return *this;
	}

	/// Scales each axis by the scalar
	SqMat4& operator *=(ValueTypeParam r)
	{
		v1 *= r;
		v2 *= r;
		v3 *= r;
		v4 *= r;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "("_s + v1.ToString(formatStatement) + ","_s + v2.ToString(formatStatement) + ","_s + v3.ToString(formatStatement) + ","_s + v4.ToString(formatStatement) + ")"_s;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the matrix (used for hash maps and comparisons).
	/// @return												The matrix' hash code.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return MAXON_HASHCODE(v1, v2, v3, v4);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the matrix (see nullvalue.h for more details).
	/// @return												A null value of the matrix.
	//----------------------------------------------------------------------------------------
	static const SqMat4& NullValue()
	{
		return GetZeroRef<SqMat4>();
	}

private:
	static ValueType Det3(ValueType a1, ValueType a2, ValueType a3, ValueType b1, ValueType b2, ValueType b3, ValueType c1, ValueType c2, ValueType c3)
	{
		return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
	}
};

/// Single-Precision Matrix.
using SquareMatrix4d32 = SqMat4<Vector4d32>;

/// Double-Precision Matrix.
using SquareMatrix4d64 = SqMat4<Vector4d64>;

/// Matrix with the precision of Float.
using SquareMatrix4d = SqMat4<Vector4d>;

/// @}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(SqMat4<T>**, OverloadRank0)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>() iferr_return;
	return ParametricTypes::SqMat().Instantiate(t, ToSingletonBlock(Int64(4)));
}

template <typename T> struct IsZeroInitialized<SqMat4<T>> : public IsZeroInitialized<T> { };


} // namespace maxon

#endif // MATRIX4D_H__
