/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_QUATERNION_H__
#define C4D_QUATERNION_H__

#include "ge_math.h"

//----------------------------------------------------------------------------------------
/// Represents a quaternion.\n
/// Has methods for conversion to and from a rotation matrix: @ref GetMatrix/@ref SetMatrix/@ref SetMatrixNorm.
/// @see group_c4d_quaternion
//----------------------------------------------------------------------------------------
class Quaternion
{
public:

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Quaternion() : w(0.0), v(1.0, 0.0, 0.0) { }

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
	explicit Quaternion(_DONTCONSTRUCT vv) : v(DC) { }

	/// @}

	Float64	 w;	///< The rotation angle.
	Vector64 v;	///< The direction vector.

	/// @name Get/Set Matrix
	/// @{

	//----------------------------------------------------------------------------------------
	/// Derives a rotation matrix from the quaternion.
	/// @return												The rotation matrix.
	//----------------------------------------------------------------------------------------
	Matrix64 GetMatrix(void) const
	{
		Matrix64 m(DONT_INITIALIZE);
		m.off	= Vector64(0, 0, 0);
		m.sqmat.v1	= Vector64(1.0 - 2.0 * (v.y * v.y + v.z * v.z), 2.0 * (v.x * v.y - w * v.z), 2.0 * (v.x * v.z + w * v.y));
		m.sqmat.v2	= Vector64(2.0 * (v.x * v.y + w * v.z), 1.0 - 2.0 * (v.x * v.x + v.z * v.z), 2.0 * (v.y * v.z - w * v.x));
		m.sqmat.v3	= Vector64(2.0 * (v.x * v.z - w * v.y), 2.0 * (v.y * v.z + w * v.x), 1.0 - 2.0 * (v.x * v.x + v.y * v.y));
		return m;
	}

	//----------------------------------------------------------------------------------------
	/// Derives quaternion values from a rotation matrix.
	/// @param[in] _m									The rotation matrix.
	//----------------------------------------------------------------------------------------
	void SetMatrix(const Matrix64& _m)
	{
		Matrix64 m(Vector(0.0), _m.sqmat.v1, _m.sqmat.v2, _m.sqmat.v3);

		m.sqmat.Normalize();

		SetMatrixNorm(m);
	}

	//----------------------------------------------------------------------------------------
	/// Derives quaternion values from a normalized rotation matrix.
	/// @param[in] m									The normalized rotation matrix.
	//----------------------------------------------------------------------------------------
	void SetMatrixNorm(const Matrix64& m)
	{
		Float64 trace = m.sqmat.v1.x + m.sqmat.v2.y + m.sqmat.v3.z;

		if (trace > 0.0)
		{
			Float64 s = 0.5 / Sqrt(trace + 1.0);
			w = 0.25 / s;
			v.x = m.sqmat.v2.z - m.sqmat.v3.y;
			v.y = m.sqmat.v3.x - m.sqmat.v1.z;
			v.z = m.sqmat.v1.y - m.sqmat.v2.x;

			v *= s;
			v	 = -v;
		}
		else
		{
			if ((m.sqmat.v1.x > m.sqmat.v2.y) && (m.sqmat.v1.x > m.sqmat.v3.z))
			{
				Float64 s = 2.0 * Sqrt(1.0 + m.sqmat.v1.x - m.sqmat.v2.y - m.sqmat.v3.z);
				v.x = 0.25 * s;
				Float64 s1 = 1.0 / s;
				v.y = (m.sqmat.v2.x + m.sqmat.v1.y) * s1;
				v.z = (m.sqmat.v3.x + m.sqmat.v1.z) * s1;
				w = (m.sqmat.v3.y - m.sqmat.v2.z) * s1;
			}
			else if (m.sqmat.v2.y > m.sqmat.v3.z)
			{
				Float64 s = 2.0 * Sqrt(1.0 + m.sqmat.v2.y - m.sqmat.v1.x - m.sqmat.v3.z);
				Float64 s1 = 1.0 / s;
				v.x = (m.sqmat.v2.x + m.sqmat.v1.y) * s1;
				v.y = 0.25 * s;
				v.z = (m.sqmat.v3.y + m.sqmat.v2.z) * s1;
				w = -(m.sqmat.v3.x - m.sqmat.v1.z) * s1;
			}
			else
			{
				Float64 s = 2.0 * Sqrt(1.0 + m.sqmat.v3.z - m.sqmat.v1.x - m.sqmat.v2.y);
				Float64 s1 = 1.0 / s;
				v.x = (m.sqmat.v3.x + m.sqmat.v1.z) * s1;
				v.y = (m.sqmat.v3.y + m.sqmat.v2.z) * s1;
				v.z = 0.25 * s;
				w = (m.sqmat.v2.x - m.sqmat.v1.y) * s1;
			}
		}
	}

	/// @}

	/// @name Set HPB/Axis
	/// @{

	//----------------------------------------------------------------------------------------
	/// Derives quaternion values from a HPB rotation.
	/// @param[in] hpb								The HPB rotation.
	//----------------------------------------------------------------------------------------
	void SetHPB(const Vector64& hpb);

	//----------------------------------------------------------------------------------------
	/// Sets the quaternion values directly.
	/// @param[in] ax									The direction vector.
	/// @param[in] ww									The rotation angle.
	//----------------------------------------------------------------------------------------
	void SetAxis(const Vector64& ax, const Float64 ww)
	{
		v = (!ax) * Sin(0.5 * ww);
		w = Cos(0.5 * ww);
	}

	/// @}
};


/// @addtogroup group_c4d_quaternion Quaternion
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Linear interpolates the quaternions @formatParam{q1} and @formatParam{q2} with the parameter @formatParam{alpha}.
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @param[in] alfa								The interpolation parameter. Between @em 0.0 (@formatParam{q1}) and @em 1.0 (@formatParam{q2}).
/// @return												The interpolated quaternion.
//----------------------------------------------------------------------------------------
Quaternion QSlerp(const Quaternion& q1, const Quaternion& q2, Float64 alfa);

//----------------------------------------------------------------------------------------
/// Cubic interpolates the quaternions @formatParam{q1} and @formatParam{q2} with parameter @formatParam{alpha} using spherical quadrangle interpolation.
/// @formatParam{q0} and @formatParam{q3} are used to provide C1-continuity at the borders (tangents):
/// @formatParam{q0} = i-1, @formatParam{q1} = i, @formatParam{q2} = i+1, @formatParam{q3} = i+2
/// @param[in] q0									The first quaternion to provide continuity.
/// @param[in] q1									The first quaternion to interpolate from.
/// @param[in] q2									The second quaternion to interpolate from.
/// @param[in] q3									The second quaternion to provide continuity.
/// @param[in] alfa								The interpolation parameter. Between @em 0.0 (@formatParam{q1}) and @em 1.0 (@formatParam{q2}).
/// @return												The interpolated quaternion.
//----------------------------------------------------------------------------------------
Quaternion QSquad (const Quaternion& q0, const Quaternion& q1, const Quaternion& q2, const Quaternion& q3, Float64 alfa);

//----------------------------------------------------------------------------------------
/// Smooth interpolates the quaternions @formatParam{q1} and @formatParam{q2} with parameter @formatParam{r}.
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @param[in] r									The blending parameter. Between @em 0.0 (@formatParam{q1}) and @em 1.0 (@formatParam{q2}).
/// @return												The interpolated quaternion.
//----------------------------------------------------------------------------------------
Quaternion QBlend(const Quaternion& q1, const Quaternion& q2, const Float64 r);

//----------------------------------------------------------------------------------------
/// Smooth blends the quaternions @formatParam{qn} and @formatParam{qn_p1} using spherical spline interpolation with parameter @formatParam{t}.\n
/// qn_m1 (@em -1) and qn_p2 (@em -1+2) are used to provide C1-continuity at the borders (tangents).
/// @param[in] qn_m1							The first quaternion (@em -1) to provide continuity.
/// @param[in] qn									The first quaternion to interpolate from.
/// @param[in] qn_p1							The second quaternion to interpolate from.
/// @param[in] qn_p2							The second quaternion (@em +2) to provide continuity.
/// @param[in] t									The blending parameter. Between @em 0.0 (@formatParam{qn}) and @em 1.0 (@formatParam{qn_p1}).
/// @return												The interpolated quaternion.
//----------------------------------------------------------------------------------------
Quaternion QSpline(const Quaternion& qn_m1, const Quaternion& qn, const Quaternion& qn_p1, const Quaternion& qn_p2, Float64 t);

//----------------------------------------------------------------------------------------
/// Smooth blends the quaternions @formatParam{qn} and @formatParam{qn_p1} using Cubic interpolation with parameter @formatParam{t}.\n
/// qn_m1 (@em -1) and qn_p2 (@em -1+2) are used to provide C1-continuity at the borders (tangents).
/// @since R18
/// @param[in] qn_m1							The first quaternion (@em -1) to provide continuity.
/// @param[in] qn									The first quaternion to interpolate from.
/// @param[in] qn_p1							The second quaternion to interpolate from.
/// @param[in] t									The blending parameter. Between @em 0.0 (@formatParam{qn}) and @em 1.0 (@formatParam{qn_p1}).
/// @return												The interpolated quaternion.
//----------------------------------------------------------------------------------------
Quaternion QSmoothCubic(const Quaternion& qn_m1, const Quaternion& qn, const Quaternion& qn_p1, Float64 t);

//----------------------------------------------------------------------------------------
/// Gets a normalized copy of quaternion @formatParam{q}.
/// @param[in] q									The quaternion to normalize.
/// @return												A normalized copy of @formatParam{q}.
//----------------------------------------------------------------------------------------
Quaternion QNorm(const Quaternion& q);

//----------------------------------------------------------------------------------------
/// Calculates the quaternion product of quaternions @formatParam{q1} and @formatParam{q2}.
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @return												The quaternion product of @formatParam{q1} and @formatParam{q2}.
//----------------------------------------------------------------------------------------
Quaternion QMul(const Quaternion& q1, const Quaternion& q2);

//----------------------------------------------------------------------------------------
/// Calculates the product of quaternion @formatParam{q} with scalar @formatParam{s}.
/// @param[in] q									The quaternion.
/// @param[in] s									The scalar.
/// @return												The product of @formatParam{q} with @formatParam{s}.
//----------------------------------------------------------------------------------------
Quaternion QMul(const Quaternion& q, Float64 s);

//----------------------------------------------------------------------------------------
/// Calculates the quaternion addition of quaternions @formatParam{q1} and @formatParam{q2}.
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @return												The quaternion addition of @formatParam{q1} and @formatParam{q2}.
//----------------------------------------------------------------------------------------
Quaternion QAdd(const Quaternion& q1, const Quaternion& q2);

//----------------------------------------------------------------------------------------
/// Calculates the quaternion subtraction of quaternions @formatParam{q1} and @formatParam{q2}.
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @return												The quaternion subtraction of @formatParam{q1} and @formatParam{q2}.
//----------------------------------------------------------------------------------------
Quaternion QSub(const Quaternion& q1, const Quaternion& q2);


//----------------------------------------------------------------------------------------
/// Calculates the inverse of quaternion @formatParam{q}.
/// @param[in] q									The quaternion.
/// @return												The quaternion inverse of @formatParam{q}.
//----------------------------------------------------------------------------------------
Quaternion QInvert(const Quaternion& q);

//----------------------------------------------------------------------------------------
/// Calculates the Dot Product between @formatParam{q1} and @formatParam{q2}.
/// @since R18
/// @param[in] q1									The first quaternion.
/// @param[in] q2									The second quaternion.
/// @return												The Dot Product of @formatParam{q1} and @formatParam{q2}.
//----------------------------------------------------------------------------------------
Float64 QDot(const Quaternion& q1, const Quaternion& q2);

//----------------------------------------------------------------------------------------
/// Calculates the derivative of quaternion @formatParam{q} by vector @formatParam{w}.
/// @param[in] q									The quaternion.
/// @param[in] w									The vector.
/// @return												The quaternion derivative of @formatParam{q} by @formatParam{w}.
//----------------------------------------------------------------------------------------
Quaternion QDeriv(const Quaternion& q, const Vector64& w);

//----------------------------------------------------------------------------------------
/// Calculates the natural logarithm of quaternion @formatParam{q}.
/// @param[in] q									The quaternion.
/// @return												The natural logarithm of @formatParam{q}.
//----------------------------------------------------------------------------------------
Quaternion QLogN(const Quaternion& q);

//----------------------------------------------------------------------------------------
/// Calculates the exponential of quaternion @formatParam{q}.
/// @param[in] q									The quaternion.
/// @return												The exponential of @formatParam{q}.
//----------------------------------------------------------------------------------------
Quaternion QExpQ(const Quaternion& q);

/// @}


//----------------------------------------------------------------------------------------
/// Calculates Euler angles from matrix @formatParam{m}.
/// @param[in] m									The rotation matrix.
/// @return												The HPB.
//----------------------------------------------------------------------------------------
Vector64 Matrix64ToHPB(const Matrix64& m);

//----------------------------------------------------------------------------------------
/// A double precision version of HPBToMatrix().
/// @param[in] w									The HPB.
/// @return												The matrix calculated from the HPB rotations in @formatParam{w}.
//----------------------------------------------------------------------------------------
Matrix64 LHPBToMatrix(const Vector64& w);


#endif // C4D_QUATERNION_H__
