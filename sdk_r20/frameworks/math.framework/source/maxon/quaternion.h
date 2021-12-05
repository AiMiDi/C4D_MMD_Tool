#ifndef QUATERNION_H__
#define QUATERNION_H__

#include "maxon/lib_math.h"
#include "maxon/dataserialize.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

//----------------------------------------------------------------------------------------
/// Quaternions extend the concept of rotation in three dimensions to	rotation in four dimensions. This avoids the problem of "gimbal-lock"
/// and allows for the implementation of smooth and continuous rotation.
/// In effect, they may be considered to add an additional rotation angle to spherical coordinates ie. Longitude, Latitude and Rotation angles.
/// A Quaternion is defined using four floating point values |v.x v.y v.z w|.
/// These are calculated from the combination of the three coordinates of the rotation axis and the rotation angle.
/// Because the rotation axis is specified as a unit direction vector, it may be calculated through vector mathematics or from spherical
/// coordinates ie. (longitude/latitude).
/// Quaternions offer another advantage in that they be interpolated - this allows for smooth and predictable rotation effects.
//----------------------------------------------------------------------------------------
template <typename ValueType> class Quaternion
{
	using VectorType = Vec3<ValueType>;
	using MatrixType = SqMat3<Vec3<ValueType>>;
	using QuaternionType = Quaternion<ValueType>;

	ValueType MyCopysign(const ValueType& x, const ValueType& y) const;


public:
	//-------------------------------------------------------------------------------------------------------------
	//                               constructors
	//-------------------------------------------------------------------------------------------------------------

	/// Creates a quaternion initialized with default values (all components 0.0).
	Quaternion();

	/// Creates a quaternion and initialize it with given quaternion values
	MAXON_IMPLICIT Quaternion(const VectorType& v, const ValueType w);

	/// Creates a quaternion and initialize it with given quaternion values
	MAXON_IMPLICIT Quaternion(const ValueType x, const ValueType y, const ValueType z, const ValueType w);


	//-------------------------------------------------------------------------------------------------------------
	//                               operators
	//-------------------------------------------------------------------------------------------------------------

	/// Adds the components of two quaternions.
	const QuaternionType& operator +=(const QuaternionType& v);

	/// Subtract the components of two quaternions.
	const QuaternionType& operator -=(const QuaternionType& v);

	/// Concatenate two quaternion operations.
	const QuaternionType& operator *=(const QuaternionType& v);

	/// Adds the components of two quaternions.
	QuaternionType operator +(const QuaternionType& v) const;

	/// Subtracts the components of two quaternions.
	QuaternionType operator -(const QuaternionType& v) const;

	/// Concatenates two quaternion operations.
	QuaternionType operator *(const QuaternionType& v) const;

	/// Scales the components of a quaternion.
	QuaternionType operator *(const ValueType s) const;

	/// Scales the components of a quaternion with a scalar.
	friend QuaternionType operator *(const ValueType s, const QuaternionType& q)
	{
		return QuaternionType(q.v * s, q.w * s);
	}


	//-------------------------------------------------------------------------------------------------------------
	//                               set values
	//-------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	/// Converts a rotation matrix into a quaternion.
	/// @param[in] m									Rotation matrix (does not need to be normalized).
	//----------------------------------------------------------------------------------------
	void SetMatrix(const MatrixType& m);

	//----------------------------------------------------------------------------------------
	/// Converts a rotation of order X -> Y -> Z into a quaternion.
	/// @param[in] rotation						Rotation angle vector in radians.
	//----------------------------------------------------------------------------------------
	void SetRotation(const VectorType& rotation);

	//----------------------------------------------------------------------------------------
	/// Converts an axis and angle to a quaternion.
	/// @param[in] axis								Axis (does not need to be normalized).
	/// @param[in] rotation						Rotation angle in radians.
	//----------------------------------------------------------------------------------------
	void SetAxisRotation(const VectorType& axis, const ValueType rotation);


	//-------------------------------------------------------------------------------------------------------------
	//                               get values
	//-------------------------------------------------------------------------------------------------------------

	/// Derives a rotation matrix from the quaternion.
	MatrixType GetMatrix() const;

	//----------------------------------------------------------------------------------------
	/// Calculate axis and rotation angle from quaternion
	/// @param[out] axis							axis vector
	/// @param[out] angle							angle value in radians
	/// @return												OK on success. Returns an error if quaternion is not normalized or the direction of the axis is undefined (singularity at 0 / 180 degree)
	//----------------------------------------------------------------------------------------
	Result<void> GetAxisRotation(VectorType& axis, ValueType& angle) const;

	/// Calculates the squared magntitude/length/norm of a quaternion.
	ValueType GetSquaredLength() const;

	/// Calculates the magntitude/length/norm of a quaternion.
	ValueType GetLength() const;

	//----------------------------------------------------------------------------------------
	/// Calculates the normalized quaternion.
	/// @return												OK on sucess. Returns an error if the length of the quaternion is zero
	//----------------------------------------------------------------------------------------
	Result<QuaternionType> GetNormalized() const;

	//----------------------------------------------------------------------------------------
	/// Calculates the inverse of a quaternion.
	/// @return												OK on sucess. Returns an error if the length of the quaternion is zero
	//----------------------------------------------------------------------------------------
	Result<QuaternionType> GetInverse() const;

	//----------------------------------------------------------------------------------------
	/// Calculates the conjugate of a quaternion.
	/// @return												conjugated quaternion
	//----------------------------------------------------------------------------------------
	QuaternionType GetConjugate() const;
	//----------------------------------------------------------------------------------------
	/// Calculates the logarithm of a quaternion.
	/// @return												OK on sucess. Returns an error if the length of the quaternion axis is zero
	//----------------------------------------------------------------------------------------
	Result<QuaternionType> GetLog() const;

	//----------------------------------------------------------------------------------------
	/// Calculates the exponential of a quaternion.
	/// @return												OK on sucess. Returns an error if the length of the quaternion is zero
	//----------------------------------------------------------------------------------------
	Result<QuaternionType> GetExp() const;

	//----------------------------------------------------------------------------------------
	/// Calculates the quaternion power q^t.
	/// @param[in] t									exponent
	/// @return												OK on sucess. Returns an error if the length of the quaternion is zero
	//----------------------------------------------------------------------------------------
	Result<QuaternionType> GetPow(const ValueType& t) const;

	/// Calculates the dot product of two quaternions.
	static ValueType GetDot(const QuaternionType& q1, const QuaternionType& q2);

	//----------------------------------------------------------------------------------------
	/// Interpolates two quaternions linearly with blend parameter t.
	/// @param[in] q1									first quaternion
	/// @param[in] q2									second quaternion
	/// @param[in] t									blend parameter [0.0, 1.0.]
	/// @return												The interpolated quaternion.
	//----------------------------------------------------------------------------------------
	static Result<QuaternionType> GetLerp(const QuaternionType& q1, const QuaternionType& q2, const ValueType t);

	//----------------------------------------------------------------------------------------
	/// Interpolates two quaternions spherical linearly with blend parameter t.
	/// @param[in] q1									first quaternion
	/// @param[in] q2									second quaternion
	/// @param[in] t									blend parameter [0.0, 1.0.]
	/// @return												The interpolated quaternion.
	//----------------------------------------------------------------------------------------
	static Result<QuaternionType> GetSlerp(const QuaternionType& q1, const QuaternionType& q2, const ValueType t);

	//----------------------------------------------------------------------------------------
	/// Spherical quadrangle interpolation of a sequence of quaternions qi and qi+1 with blend parameter t
	/// Additionally you have to specify the innner quaternions si and si+1.
	/// @param[in] qi									main quaternion at index i
	/// @param[in] qi_p1							main quaternion at index i+1
	/// @param[in] si									inner quaterniona at index i
	/// @param[in] si_p1							inner quaternion at index i+1
	/// @param[in] t									blend parameter [0.0, 1.0.]
	/// @return												The interpolated quaternion.
	//----------------------------------------------------------------------------------------
	static Result<QuaternionType> GetSquad(const QuaternionType& qi, const QuaternionType& qi_p1, const QuaternionType& si, const QuaternionType& si_p1, const ValueType t);

	//----------------------------------------------------------------------------------------
	/// Computer the inner quaternion from the series of quaternions qi-1, qi and qi+1
	/// @param[in] qi_m1							quaternion at index i-1
	/// @param[in] qi									quaternion at index i
	/// @param[in] qi_p1							quaternion at index i+1
	/// @return												The interpolated quaternion.
	//----------------------------------------------------------------------------------------
	static Result<QuaternionType> GetInnerQuaternion(const QuaternionType& qi_m1, const QuaternionType& qi, const QuaternionType& qi_p1);

	//----------------------------------------------------------------------------------------
	/// Interpolates two quaternions qi and qi+1 smoothly using spherical spline interpolation with parameter t.
	/// qi-1 and qi+2 are used to provide C1 continuity at the borders.
	/// @param[in] qi_m1							quaternion at index i-1
	/// @param[in] qi									quaternion at index i
	/// @param[in] qi_p1							quaternion at index i+1
	/// @param[in] qi_p2							quaternion at index i+2
	/// @param[in] t									blend parameter [0.0, 1.0.]
	/// @return												The interpolated quaternion.
	//----------------------------------------------------------------------------------------
	static Result<QuaternionType> GetSpline(const QuaternionType& qi_m1, const QuaternionType& qi, const QuaternionType& qi_p1, const QuaternionType& qi_p2, const ValueType t);

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;


	//-------------------------------------------------------------------------------------------------------------
	//                               functions
	//-------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	MAXON_OPERATOR_EQUALITY_HASHCODE(Quaternion, v, w);

public:
	VectorType v; 	///< direction vector component
	ValueType	 w; 	///< angle component
};

/// @}

//-------------------------------------------------------------------------------------------------------------
//                               implementation
//-------------------------------------------------------------------------------------------------------------
template <typename ValueType> Quaternion<ValueType>::Quaternion()
{
	v.x = ValueType(0.0);
	v.y = ValueType(0.0);
	v.z = ValueType(0.0);
	w   = ValueType(0.0);
}

template <typename ValueType> Quaternion<ValueType>::Quaternion(const VectorType& _v, const ValueType _w)
{
	v = _v;
	w = _w;
}

template <typename ValueType> Quaternion<ValueType>::Quaternion(const ValueType _x, const ValueType _y, const ValueType _z, const ValueType _w)
{
	v.x = _x;
	v.y = _y;
	v.z = _z;
	w   = _w;
}

template <typename ValueType> const Quaternion<ValueType>& Quaternion<ValueType>::operator +=(const QuaternionType& q1)
{
	w += q1.w;
	v += q1.v;

	return *this;
}

template <typename ValueType> const Quaternion<ValueType>& Quaternion<ValueType>::operator -=(const QuaternionType& q1)
{
	w -= q1.w;
	v -= q1.v;
	return *this;
}

template <typename ValueType> const Quaternion<ValueType>& Quaternion<ValueType>::operator *=(const QuaternionType& q2)
{
	w = w * q2.w - Dot(v, q2.v);
	v = w * q2.v + v * q2.w + Cross(v, q2.v);

	return *this;
}

template <typename ValueType> Quaternion<ValueType> Quaternion<ValueType>::operator +(const QuaternionType& q2) const
{
	return QuaternionType(v + q2.v, w + q2.w);
}

template <typename ValueType> Quaternion<ValueType> Quaternion<ValueType>::operator -(const QuaternionType& q2) const
{
	return QuaternionType(v - q2.v, w - q2.w);
}

template <typename ValueType> Quaternion<ValueType> Quaternion<ValueType>::operator *(const QuaternionType& q2) const
{
	QuaternionType ret;

	ret.w = w * q2.w - Dot(v, q2.v);
	ret.v = w * q2.v + q2.w * v + Cross(v, q2.v);

	return ret;
}

template <typename ValueType> Quaternion<ValueType> Quaternion<ValueType>::operator *(const ValueType s) const
{
	return QuaternionType(v * s, w * s);
}

template <typename ValueType> ValueType Quaternion<ValueType>::MyCopysign(const ValueType& x, const ValueType& y) const
{
	return Abs(x) * Sign(y);
}

template <typename ValueType> void Quaternion<ValueType>::SetMatrix(const MatrixType& _m)
{
	MatrixType m = _m.GetNormalized();

	// Because quaternions cannot represent a reflection component, the matrix must be special orthogonal.
	// For a special orthogonal matrix, 1 + trace is always positive.
	// The if cases are not needed, just do Sqrt() on the 4 trace variants and you are done
	// The extra Max call is just a safeguard against rounding errors.

	w   = Sqrt(Max(ValueType(0.0), ValueType(1.0) + m.v1.x + m.v2.y +  m.v3.z)) * ValueType(0.5);
	v.x = Sqrt(Max(ValueType(0.0), ValueType(1.0) + m.v1.x - m.v2.y -  m.v3.z)) * ValueType(0.5);
	v.y = Sqrt(Max(ValueType(0.0), ValueType(1.0) - m.v1.x + m.v2.y -  m.v3.z)) * ValueType(0.5);
	v.z = Sqrt(Max(ValueType(0.0), ValueType(1.0) - m.v1.x - m.v2.y +  m.v3.z)) * ValueType(0.5);

	// recover signs
	v.x = MyCopysign(v.x, m.v3.y - m.v2.z);
	v.y = MyCopysign(v.y, m.v1.z - m.v3.x);
	v.z = MyCopysign(v.z, m.v2.x - m.v1.y);
}

template <typename ValueType> void Quaternion<ValueType>::SetRotation(const VectorType& rotation)
{
	QuaternionType qx, qy, qz;

	qx.SetAxisRotation(VectorType(1.0, 0.0, 0.0), rotation.x);
	qy.SetAxisRotation(VectorType(0.0, 1.0, 0.0), rotation.y);
	qz.SetAxisRotation(VectorType(0.0, 0.0, 1.0), rotation.z);

	*this = (qx * qy) * qz;
}

template <typename ValueType> void Quaternion<ValueType>::SetAxisRotation(const VectorType& axis, const ValueType angle)
{
	v = Sin(ValueType(0.5) * angle) * axis.GetNormalized();
	w = Cos(ValueType(0.5) * angle);
}

template <typename ValueType> auto Quaternion<ValueType>::GetMatrix() const -> MatrixType
{
	return MatrixType(VectorType(ValueType(1.0) - ValueType(2.0) * (v.y * v.y + v.z * v.z),                  ValueType(2.0) * (v.x * v.y - w   * v.z),                  ValueType(2.0) * (v.x * v.z + w   * v.y)),
										VectorType(                 ValueType(2.0) * (v.x * v.y + w   * v.z), ValueType(1.0) - ValueType(2.0) * (v.x * v.x + v.z * v.z),                  ValueType(2.0) * (v.y * v.z - w   * v.x)),
										VectorType(                 ValueType(2.0) * (v.x * v.z - w   * v.y),                  ValueType(2.0) * (v.y * v.z + w   * v.x), ValueType(1.0) - ValueType(2.0) * (v.x * v.x + v.y * v.y)));
}

template <typename ValueType> Result<void> Quaternion<ValueType>::GetAxisRotation(VectorType& axis, ValueType& angle) const
{
	iferr_scope;

	ValueType s = ValueType(1.0) - w*w;
	if (s < ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Quaternion not normalized."_s);

	s = Sqrt(s);
	if (s == ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Singularity at 0/180 degree. Direction of axis not defined."_s);

	axis.x = v.x / s;
	axis.y = v.y / s;
	axis.z = v.z / s;

	angle = ValueType(2.0) * ACos(w);

	return OK;
}

#define LENGTH_ERROR "Length of quaternion is zero."_s
#define BLEND_ERROR  "Blend parameter outside [0.0, 1.0] range."_s

template <typename ValueType> ValueType Quaternion<ValueType>::GetSquaredLength() const
{
	return w * w + v.GetSquaredLength();
}

template <typename ValueType> ValueType Quaternion<ValueType>::GetLength() const
{
	return Sqrt(w * w + v.GetSquaredLength());
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetNormalized() const
{
	ValueType len = GetLength();
	if (len == ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, LENGTH_ERROR);

	return QuaternionType(v / len, w / len);
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetInverse() const
{
	QuaternionType ret = GetConjugate();

	ValueType len = GetSquaredLength();
	if (len == ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, LENGTH_ERROR);

	ret.v = v / len;
	ret.w = w / len;

	return ret;
}

template <typename ValueType> Quaternion<ValueType> Quaternion<ValueType>::GetConjugate() const
{
	return QuaternionType(-v, w);
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetLog() const
{
	iferr_scope;

	ValueType len = v.GetLength();
	if (len == ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, LENGTH_ERROR);

	QuaternionType ret;
	ret.w = ValueType(0.0);
	ret.v = v * ACos(w) / len;

	return ret;
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetExp() const
{
	QuaternionType ret;

	ValueType len = GetLength();
	if (len == ValueType(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, LENGTH_ERROR);

	ret.w = Cos(len);
	ret.v = v * Sin(len) / len;

	return ret;
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetPow(const ValueType& t) const
{
	iferr_scope;
	
	const QuaternionType logValue = GetLog() iferr_return;
	
	const QuaternionType ret = (logValue * t).GetExp() iferr_return;
	
	return ret;
}

template <typename ValueType> ValueType Quaternion<ValueType>::GetDot(const QuaternionType& q1, const QuaternionType& q2)
{
	return q1.v.x * q2.v.x + q1.v.y * q2.v.y + q1.v.z * q2.v.z + q1.w * q2.w;
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetLerp(const QuaternionType& q1, const QuaternionType& q2, const ValueType t)
{
	iferr_scope;

	if (t < ValueType(0.0) || t > ValueType(1.0))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, BLEND_ERROR);

	return (q1*(ValueType(1.0)-t) + q2*t).GetNormalized();
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetSlerp(const QuaternionType& q1, const QuaternionType& q2, const ValueType t)
{
	iferr_scope;

	if (t < ValueType(0.0) || t > ValueType(1.0))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, BLEND_ERROR);

	QuaternionType qd = q2;

	ValueType sum = Quaternion::GetDot(q1, q2);

	if (sum < ValueType(0.0))
	{
		// 	First, if the quaternion dot-product results in a negative value, then the resulting interpolation will travel the long-way around the 4D sphere which is not
		//	 necessarily what we want. To solve this problem, we can test the result of the dot product and if it is negative, then we can negate one of the orientations.
		//	 Negating the scalar and the vector part of the quaternion does not change the orientation that it represents but by doing this we guarantee that the rotation will be applied in the shortest path.

		sum = -sum;
		qd.v  = -qd.v;
	}

	ValueType beta1 = ValueType(1.0) - t;
	ValueType beta2 = t;

	ValueType theta = ACos(sum);
	ValueType sn    = Sin(theta);
	if (sn > 0.0)
	{
		beta1 = Sin((ValueType(1.0) - t) * theta) / sn;
		beta2 = Sin(t                    * theta) / sn;
	}
	else
	{
		// The other problem arises when the angular difference between q1 and q2 is very small then Sin(theta) becomes 0.
		// If this happens, then we will get an undefined result when we divide by Sin(theta).
		// In this case, we can fall-back to using linear interpolation between q1 and q2.

		beta1 = ValueType(1.0) - t;
		beta2 = t;
	}

	return beta1 * q1 + beta2 * qd;
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetSquad(const QuaternionType& qi, const QuaternionType& qi_p1, const QuaternionType& si, const QuaternionType& si_p1, const ValueType t)
{
	iferr_scope;

	if (t < ValueType(0.0) || t > ValueType(1.0))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, BLEND_ERROR);

	QuaternionType c = Quaternion::GetSlerp(qi, qi_p1, t) iferr_return;
	QuaternionType d = Quaternion::GetSlerp(si, si_p1, t) iferr_return;

	return Quaternion::GetSlerp(c, d, ValueType(2.0) * (ValueType(1.0) - t) * t);
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetInnerQuaternion(const QuaternionType& qi_m1, const QuaternionType& qi, const QuaternionType& qi_p1)
{
	iferr_scope;

	QuaternionType ti = qi.GetInverse() iferr_return;
	QuaternionType t1 = qi_p1 * ti;
	QuaternionType t2 = qi_m1 * ti;

	const QuaternionType t1Log = t1.GetLog() iferr_return;
	const QuaternionType t2Log = t2.GetLog() iferr_return;
	
	t1 = ValueType(-0.25) * (t1Log + t2Log);
	
	const QuaternionType t1Exp = t1.GetExp() iferr_return;
	
	return qi * t1Exp;
}

template <typename ValueType> Result<Quaternion<ValueType>> Quaternion<ValueType>::GetSpline(const QuaternionType& qi_m1, const QuaternionType& qi, const QuaternionType& qi_p1, const QuaternionType& qi_p2, const ValueType t)
{
	iferr_scope;

	if (t < ValueType(0.0) || t > ValueType(1.0))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, BLEND_ERROR);

	QuaternionType si    = Quaternion::GetInnerQuaternion(qi_m1, qi   , qi_p1) iferr_return;
	QuaternionType si_p1 = Quaternion::GetInnerQuaternion(qi   , qi_p1, qi_p2) iferr_return;

	return Quaternion::GetSquad(qi, si, si_p1, qi_p1, t);
}

template <typename ValueType> String Quaternion<ValueType>::ToString(const FormatStatement* formatStatement) const
{
	return "("_s + maxon::ToString(w, formatStatement) + ","_s + maxon::ToString(v, formatStatement) + ")"_s;
}

template <typename ValueType> Result<void> Quaternion<ValueType>::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, Quaternion);

	Describe("v", v, VectorType, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("w", w, ValueType , DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}



// ------------------------------  registration  -----------------------------------

/// Single-precision quaternion.
using Quaternion32 = Quaternion<Float32>;

/// Double-precision quaternion.
using Quaternion64 = Quaternion<Float64>;


MAXON_DATATYPE(Quaternion32, "net.maxon.datatype.quaternion32");
MAXON_DATATYPE(Quaternion64, "net.maxon.datatype.quaternion64");

} // namespace maxon

#endif // QUATERNION_H__
