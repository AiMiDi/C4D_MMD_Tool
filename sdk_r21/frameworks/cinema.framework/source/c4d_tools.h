/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_TOOLS_H__
#define C4D_TOOLS_H__

#include "ge_math.h"
#include "operatingsystem.h"

#ifndef __API_INTERN__
	#include "c4d_string.h"
	#include "c4d_raytrace.h"
	#include "c4d_shader.h"
	#include "c4d_videopostplugin.h"
	#include "c4d_baseobject.h"
#endif

static const Float COLORTOINT_MULTIPLIER = 255.99;		///< Constant to convert from vectors color components to integers. @since R18
static const Float PERCENT = 100.0;										///< Constant to convert from <i>0</i>-<i>1</i> range to percentage.
static const Float THIRD = 0.333333333333333333;			///< Constant to calculate the third of a value.
static const Float SIXTH = 0.166666666666666666;			///< Constant to calculate the sixth of a value.

#define MAXRANGE		1.0e20				///< Maximum value for metric data.
#define MAXELEMENTS 100000000			///< Maximum number of points.
#define MIN_EPSILON 0.001					///< Minimum epsilon value.

class Filename;

/// @addtogroup c4d_tools_math Math
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Returns @em 1.0 if @formatParam{x} is greater than or equal to @formatParam{a}, else @em 0.0.
/// @param[in] a									A double-precision floating point value.
/// @param[in] x									A double-precision floating point value.
/// @return												The step value (@em 0.0 or @em 1.0).
//----------------------------------------------------------------------------------------
inline Float64 StepEx(Float64 a, Float64 x)
{
	if (x >= a)
		return 1.0;
	else
		return 0.0;
}

//----------------------------------------------------------------------------------------
/// Returns @em 0.0 if @formatParam{x} is less than @formatParam{a} and @em 1.0 if @formatParam{x} is greater than @formatParam{b}, else returns @formatParam{x} mapped on the range [@formatParam{a},@formatParam{b}].
/// @param[in] a									A single-precision floating point value.
/// @param[in] b									A single-precision floating point value.
/// @param[in] x									A single-precision floating point value.
/// @return												The box stepped value between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float32 Boxstep(Float32 a, Float32 b, Float32 x)
{
	if (b == a)
	{
		if (x < a)
			return (Float32) 0.0;
		else
			return (Float32) 1.0;
	}
	x = (x - a) / (b - a);
	return x < (Float32) 0.0 ? (Float32) 0.0 : (x > (Float32) 1.0 ? (Float32) 1.0 : x);
}

//----------------------------------------------------------------------------------------
/// Returns @em 0.0 if @formatParam{x} is less than @formatParam{a} and @em 1.0 if @formatParam{x} is greater than @formatParam{b}, else returns @formatParam{x} mapped on the range [@formatParam{a},@formatParam{b}].
/// @param[in] a									A double-precision floating point value.
/// @param[in] b									A double-precision floating point value.
/// @param[in] x									A double-precision floating point value.
/// @return												The box stepped value between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float64 Boxstep(Float64 a, Float64 b, Float64 x)
{
	if (b == a)
	{
		if (x < a)
			return 0.0;
		else
			return 1.0;
	}
	x = (x - a) / (b - a);
	return x < 0.0 ? 0.0 : (x > 1.0 ? 1.0 : x);
}

//----------------------------------------------------------------------------------------
/// Returns @em 0.0 if @formatParam{x} is less than @formatParam{a} and @em 1.0 if @formatParam{x} is greater than @formatParam{b}, else returns @formatParam{x} mapped on the range [@formatParam{a},@formatParam{b}].
/// @note The mapping is smoothed using an ease-in/ease-out curve.
/// @param[in] a									A single-precision floating point value.
/// @param[in] b									A single-precision floating point value.
/// @param[in] x									A single-precision floating point value.
/// @return												The smoothed stepped value between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float32 Smoothstep(Float32 a, Float32 b, Float32 x)
{
	if (x < a)
		return (Float32) 0.0;
	if (x >= b)
		return (Float32) 1.0;

	x = (x - a) / (b - a);	// normalize to [0,1]

	return x * x * ((Float32) 3.0 - (Float32) 2.0 * x);
}

//----------------------------------------------------------------------------------------
/// Returns @em 0.0 if @formatParam{x} is less than @formatParam{a} and @em 1.0 if @formatParam{x} is greater than @formatParam{b}, else returns @formatParam{x} mapped on the range [@formatParam{a},@formatParam{b}].
/// @note The mapping is smoothed using an ease-in/ease-out curve.
/// @param[in] a									A double-precision floating point value.
/// @param[in] b									A double-precision floating point value.
/// @param[in] x									A double-precision floating point value.
/// @return												The smoothed stepped value between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float64 Smoothstep(Float64 a, Float64 b, Float64 x)
{
	if (x < a)
		return 0.0;
	if (x >= b)
		return 1.0;

	x = (x - a) / (b - a);	// normalize to [0,1]

	return x * x * (3.0 - 2.0 * x);
}

//----------------------------------------------------------------------------------------
/// Returns @formatParam{a} modulo @formatParam{b}.
/// @param[in] a									A single-precision floating point value.
/// @param[in] b									A single-precision floating point value.
/// @return												The modulo value.
//----------------------------------------------------------------------------------------
inline Float32 Modulo(Float32 a, Float32 b)
{
	if (b == 0.0)
		return 0.0;
	Int32 n = (Int32) (a / b);

	a -= n * b;
	if (a < 0.0)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Returns @formatParam{a} modulo @formatParam{b}.
/// @param[in] a									A double-precision floating point value.
/// @param[in] b									A double-precision floating point value.
/// @return												The modulo value.
//----------------------------------------------------------------------------------------
inline Float64 Modulo(Float64 a, Float64 b)
{
	if (b == 0.0)
		return 0.0;
	Int32 n = (Int32) (a / b);

	a -= n * b;
	if (a < 0.0)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Returns @formatParam{a} modulo @formatParam{b} (integer modulo).
/// @param[in] a									A 32-bit integer value.
/// @param[in] b									A 32-bit integer value.
/// @return												The modulo value.
//----------------------------------------------------------------------------------------
inline Int32 LModulo(Int32 a, Int32 b)
{
	if (!b)
		return 0;
	if (a >= 0)
		return a % b;

	a -= (a / b) * b;
	if (a < 0)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Returns @formatParam{a} modulo @formatParam{b} (integer modulo).
/// @param[in] a									A 64-bit integer value.
/// @param[in] b									A 64-bit integer value.
/// @return												The modulo value.
//----------------------------------------------------------------------------------------
inline Int64 LModulo(Int64 a, Int64 b)
{
	if (!b)
		return 0;
	if (a >= 0)
		return a % b;

	a -= (a / b) * b;
	if (a < 0)
		a += b;

	return a;
}

//----------------------------------------------------------------------------------------
/// Returns the bias as the defined in the book @em "Texturing and Modeling" by Ebert.
/// @param[in] b									The bias value.
/// @param[in] x									A single-precision floating point value.
/// @return												The bias value.
//----------------------------------------------------------------------------------------
inline Float32 Bias(Float32 b, Float32 x)
{
	return Pow(x, Float32(-Ln(b) / (Float32) 0.693147180559945309));
}

//----------------------------------------------------------------------------------------
/// Returns the bias as the defined in the book @em "Texturing and Modeling" by Ebert.
/// @param[in] b									The bias value.
/// @param[in] x									A double-precision floating point value.
/// @return												The bias value.
//----------------------------------------------------------------------------------------
inline Float64 Bias(Float64 b, Float64 x)
{
	return Pow(x, Float64(-Ln(b) / 0.693147180559945309));
}

//----------------------------------------------------------------------------------------
/// Returns the next integer value towards zero.
/// @param[in] x									The 32-bit floating point value to truncate.
/// @return												The truncated value.
//----------------------------------------------------------------------------------------
inline Float32 Truncate(Float32 x)
{
	if (x >= (Float32) 0.0)
		return Floor(x);
	else
		return Ceil(x);
}

//----------------------------------------------------------------------------------------
/// Returns the next integer value towards zero.
/// @param[in] x									The 64-bit floating point value to truncate.
/// @return												The truncated value.
//----------------------------------------------------------------------------------------
inline Float64 Truncate(Float64 x)
{
	if (x >= 0.0)
		return Floor(x);
	else
		return Ceil(x);
}

/// @}

/// @addtogroup c4d_tools_matrix Matrix
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Creates a translation matrix.
/// @param[in] t									The translation vector.
/// @return												The translation matrix.
//----------------------------------------------------------------------------------------
Matrix MatrixMove(const Vector& t);

//----------------------------------------------------------------------------------------
/// Creates a scaling matrix.
/// @param[in] s									The scaling vector for the axes.
/// @return												The scaling matrix.
//----------------------------------------------------------------------------------------
Matrix MatrixScale(const Vector& s);

//----------------------------------------------------------------------------------------
/// Creates a rotation matrix on the X axis.
/// @param[in] w									The angle around X.
/// @return												The rotation matrix.
//----------------------------------------------------------------------------------------
Matrix MatrixRotX(Float w);

//----------------------------------------------------------------------------------------
/// Creates a rotation matrix on the Y axis.
/// @param[in] w									The angle around Y.
/// @return												The rotation matrix.
//----------------------------------------------------------------------------------------
Matrix MatrixRotY(Float w);

//----------------------------------------------------------------------------------------
/// Creates a rotation matrix on the Z axis.
/// @param[in] w									The angle around Z.
/// @return												The rotation matrix.
//----------------------------------------------------------------------------------------
Matrix MatrixRotZ(Float w);

//----------------------------------------------------------------------------------------
/// Calculates Euler angles from a matrix.
/// @param[in] m									The rotation matrix.
/// @param[in] rot_order					The rotation order.
/// @return												The rotation HPB.
//----------------------------------------------------------------------------------------
Vector MatrixToHPB(const Matrix& m, ROTATIONORDER rot_order);

//----------------------------------------------------------------------------------------
/// Calculates Euler angles from a vector.
/// @note The bank is always set to @em 0.0.
/// @param[in] p									The vector to find the HPB for.
/// @return												The rotation HPB.
//----------------------------------------------------------------------------------------
Vector VectorToHPB(const Vector& p);

//----------------------------------------------------------------------------------------
/// Constructs a matrix from Euler angles.
/// @param[in] hpb								The input HPB.
/// @param[in] rot_order					The rotation order.
/// @return												The rotation matrix.
//----------------------------------------------------------------------------------------
Matrix HPBToMatrix(const Vector& hpb, ROTATIONORDER rot_order);

//----------------------------------------------------------------------------------------
/// Calculates rotation axis and angle from a matrix.
/// @param[in] m									The rotation matrix.
/// @param[out] v									Assigned the rotation axis.
/// @param[out] w									Assigned the rotation angle.
//----------------------------------------------------------------------------------------
void MatrixToRotAxis(const Matrix& m, Vector* v, Float* w);

//----------------------------------------------------------------------------------------
/// Calculates matrix from rotation axis and angle.
/// @param[in] v									The rotation axis.
/// @param[in] w									The rotation angle.
/// @return												The rotation matrix.
//----------------------------------------------------------------------------------------
Matrix RotAxisToMatrix(const Vector& v, Float w);

//----------------------------------------------------------------------------------------
/// Recalculates a matrix making it orthogonal if one or more of its vectors is collapsed (scale @em 0.0).
/// @param[in] m									The matrix to rebuild.
/// @return												The recalculated matrix with the collapsed components fixed and unit length.
//----------------------------------------------------------------------------------------
Matrix RebuildMatrix(const Matrix& m);

/// @}

//----------------------------------------------------------------------------------------
/// Modifies @formatParam{hpb_new} so that the "distance" to the last angle @formatParam{hpb_old} is at minimum.
/// @note Helps to avoid HPB singularity effects.
/// @param[in] hpb_old						The old HPB.
/// @param[in] hpb_new						The new HPB.
/// @param[in] order							The rotation order.
/// @return												The optimal angle.
//----------------------------------------------------------------------------------------
Vector GetOptimalAngle(const Vector& hpb_old, const Vector& hpb_new, ROTATIONORDER order);

//----------------------------------------------------------------------------------------
/// Calculates the distance from a point to a line.
/// @param[in] p0									The starting point of the line.
/// @param[in] v									The line vector.
/// @param[in] p									The point.
/// @return												The point-line vector.
//----------------------------------------------------------------------------------------
Vector PointLineDistance(const Vector& p0, const Vector& v, const Vector& p);

//----------------------------------------------------------------------------------------
/// Calculates the distance from a point to a line segment between two points.
/// @since R17.032
/// @param[in] segmentPoint1			The line segments first point.
/// @param[in] segmentPoint2			The line segments second point.
/// @param[in] pos								The point to test against the line segment.
/// @param[out] intersectionPoint	Optional, if non-null the intersection point on the segment.
/// @param[out] lineOffset				Optional, if non-null, the offset along the segment of the intersection point.
/// @return												A distance between the point and the line segment.
//----------------------------------------------------------------------------------------
Float PointLineSegmentDistance(const Vector &segmentPoint1, const Vector &segmentPoint2, const Vector &pos, Vector *intersectionPoint = nullptr, Float *lineOffset = nullptr);

//----------------------------------------------------------------------------------------
/// Calculates the distance from a point to a line segment between two points in 2D ignoring the Z value.
/// @since R17.032
/// @param[in] segmentPoint1			The line segments first point.
/// @param[in] segmentPoint2			The line segments second point.
/// @param[in] pos								The point to test against the line segment.
/// @param[out] intersectionPoint	Optional, if non-null the intersection point on the segment.
/// @param[out] lineOffset				Optional, if non-null, the offset along the segment of the intersection point.
/// @return												A distance between the point and the line segment.
//----------------------------------------------------------------------------------------
Float PointLineSegmentDistance2D(const Vector &segmentPoint1, const Vector &segmentPoint2, const Vector &pos, Vector *intersectionPoint = nullptr, Float *lineOffset = nullptr);

//----------------------------------------------------------------------------------------
/// Finds the ray vector after a reflection on a surface normal.
/// @param[in] v									The incoming ray.
/// @param[in] n									The surface normal.
/// @return												The reflected ray.
//----------------------------------------------------------------------------------------
Vector64 ReflectRay(const Vector64& v, const Vector64& n);

//----------------------------------------------------------------------------------------
/// Calculates where the intersection points are between a line and a sphere in 3D space.
/// since @em R16
/// @param[in] linePoint1					The first point of the line.
/// @param[in] linePoint2					The second point of the line.
/// @param[in] sphereCenter				The center of the sphere.
/// @param[in] sphereRadius				The radius of the sphere.
/// @param[out] intersection1			(optional) Assigned the first intersection point (lowest) as an offset between linePoint1 and linePoint2
/// @param[out] intersection2			(optional) Assigned the second intersection point (highest) as an offset between linePoint1 and linePoint2
/// @param[out] hitPoint1					(optional) Assigned the actual 3D point where the line first intersects (enters) the sphere.
/// @param[out] hitPoint2					(optional) Assigned the actual 3D point where the line subsequently intersects (exits) the sphere.
/// @return												Whether the line segment passed intersected the sphere or not.
//----------------------------------------------------------------------------------------
Bool SphereLineIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &sphereCenter, Float sphereRadius, Float *intersection1 = nullptr, Float *intersection2 = nullptr, Vector *hitPoint1 = nullptr, Vector *hitPoint2 = nullptr);

//----------------------------------------------------------------------------------------
/// Calculates where the intersection points are between a line and a circle in 2D space (although Z will also be calculated on the resulting hit points)
/// since @em R16
/// @param[in] linePoint1					The first point of the line.
/// @param[in] linePoint2					The second point of the line.
/// @param[in] circleCenter				The center of the circle.
/// @param[in] circleRadius				The radius of the circle.
/// @param[out] intersection1			(optional) Assigned the first intersection point (lowest) as an offset between linePoint1 and linePoint2
/// @param[out] intersection2			(optional) Assigned the second intersection point (highest) as an offset between linePoint1 and linePoint2
/// @param[out] hitPoint1					(optional) Assigned the actual point where the line first intersects (enters) the circle, Z may also be calculated.
/// @param[out] hitPoint2					(optional) Assigned the actual point where the line subsequently intersects (exits) the circle, Z may also be calculated.
/// @return												Whether the line segment passed intersected the circle or not.
//----------------------------------------------------------------------------------------
Bool CircleLineIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &circleCenter, Float circleRadius, Float *intersection1 = nullptr, Float *intersection2 = nullptr, Vector *hitPoint1 = nullptr, Vector *hitPoint2 = nullptr);

//----------------------------------------------------------------------------------------
/// Structure for passing SegmentSphereIntersection and SegmentCircleIntersection intersection hits from the aforementioned functions.
/// since @em R16
//----------------------------------------------------------------------------------------
struct SegmentSphereIntersectionData
{
	SegmentSphereIntersectionData() { offset = 0.0; }
	SegmentSphereIntersectionData(Float o, Vector h) : offset(o), hitPoint(h) {}

	Float offset;					///< The offset along the segment that the hit occurs at
	Vector hitPoint;			///< The position that the hit occurs at
};

//----------------------------------------------------------------------------------------
/// Calculates where the intersection points are between a segment (a portion of a line) and a sphere in 3D space.
/// since @em R16
/// @param[in] linePoint1					The first point (start) of the segment.
/// @param[in] linePoint2					The second point (end) of the segment.
/// @param[in] sphereCenter				The center of the sphere.
/// @param[in] sphereRadius				The radius of the sphere.
/// @param[out] intersections			Assigned the SegmentSphereIntersectionData hit-points.
/// @return												Whether the line segment passed intersected the sphere or not.
//----------------------------------------------------------------------------------------
Bool SphereSegmentIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &sphereCenter, Float sphereRadius, maxon::BaseArray<SegmentSphereIntersectionData> &intersections);

//----------------------------------------------------------------------------------------
/// Calculates where the intersection points are between a segment (a portion of a line) and a circle in 2D space (although Z will be calculated for any resulting hit points)
/// since @em R16
/// @param[in] linePoint1					The first point (start) of the segment.
/// @param[in] linePoint2					The second point (end) of the segment.
/// @param[in] circleCenter				The center of the circle.
/// @param[in] circleRadius				The radius of the circle.
/// @param[out] intersections			Assigned the SegmentSphereIntersectionData hit-points.
/// @return												Whether the line segment passed intersected the circle or not.
//----------------------------------------------------------------------------------------
Bool CircleSegmentIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &circleCenter, Float circleRadius, maxon::BaseArray<SegmentSphereIntersectionData> &intersections);


//-------------------------------------------------------------------------------------------------
/// A class to construct a bounding box around points.
//-------------------------------------------------------------------------------------------------
class LMinMax
{
private:
	Vector64 min, max;
	Bool used;

public:
	//-------------------------------------------------------------------------------------------------
	/// Default constructor.
	//-------------------------------------------------------------------------------------------------
	LMinMax() { min = Vector64(MAXVALUE_FLOAT64); max = Vector64(MINVALUE_FLOAT64); used = false; }

	//----------------------------------------------------------------------------------------
	/// Constructs with vector @formatParam{v} set for both the minimum and maximum.
	/// @param[in] v									The vector for minimum and maximum.
	//----------------------------------------------------------------------------------------
	explicit LMinMax(const Vector64& v) { min = max = v; used = true; }

	//-------------------------------------------------------------------------------------------------
	/// Resets the minimum and maximum to the largest values possible.
	//-------------------------------------------------------------------------------------------------
	inline void Init(void) { min = Vector64(MAXVALUE_FLOAT64); max = Vector64(MINVALUE_FLOAT64); used = false; }

	//----------------------------------------------------------------------------------------
	/// Initializes the minimum and maximum with vector @formatParam{v}.
	/// @param[in] v									The value to initialize minimum and maximum.
	//----------------------------------------------------------------------------------------
	inline void Init(const Vector64& v) { min = max = v; used = true; }

	//----------------------------------------------------------------------------------------
	/// Adds point @formatParam{p} and recalculates the minimum and maximum.
	/// @param[in] p									The point to add into the bounds.
	//----------------------------------------------------------------------------------------
	inline void AddPoint(const Vector64& p)
	{
		if (used)
		{
			if (p.x < min.x)
				min.x = p.x;
			if (p.y < min.y)
				min.y = p.y;
			if (p.z < min.z)
				min.z = p.z;
			if (p.x > max.x)
				max.x = p.x;
			if (p.y > max.y)
				max.y = p.y;
			if (p.z > max.z)
				max.z = p.z;
		}
		else
		{
			min	 = max = p;
			used = true;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Adds points @formatParam{a} and @formatParam{b} and recalculates the minimum and maximum.
	/// @param[in] a									The minimum point to add into the bounds.
	/// @param[in] b									The maximum point to add into the bounds.
	//----------------------------------------------------------------------------------------
	inline void AddPoints(const Vector64& a, const Vector64& b)
	{
		used = true;
		if (a.x < min.x)
			min.x = a.x;
		if (a.y < min.y)
			min.y = a.y;
		if (a.z < min.z)
			min.z = a.z;
		if (b.x > max.x)
			max.x = b.x;
		if (b.y > max.y)
			max.y = b.y;
		if (b.z > max.z)
			max.z = b.z;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the minimum and maximum of the bounding box.
	/// @param[in] a									The minimum.
	/// @param[in] b									The maximum.
	//----------------------------------------------------------------------------------------
	inline void Set(const Vector64& a, const Vector64& b)
	{
		used = true;
		min	 = a;
		max	 = b;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if any points were added.
	/// @return												@trueIfOtherwiseFalse{if any points were added to the bounds}
	//----------------------------------------------------------------------------------------
	inline Bool IsPopulated(void) const { return used; }

	//----------------------------------------------------------------------------------------
	/// Gets the minimum of the bounding box.
	/// @return												The minimum position of the bounds.
	//----------------------------------------------------------------------------------------
	inline const Vector64& GetMin(void) const
	{
		extern Vector64 l_empty;
		if (used)
			return min;
		else
			return l_empty;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the maximum of the bounding box.
	/// @return												The maximum position of the bounds.
	//----------------------------------------------------------------------------------------
	inline const Vector64& GetMax(void) const
	{
		extern Vector64 l_empty;
		if (used)
			return max;
		else
			return l_empty;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the middle between the minimum and maximum (the center).
	/// @return												The center of the bounds.
	//----------------------------------------------------------------------------------------
	inline Vector64 GetMp(void) const
	{
		if (used)
			return (min + max) * 0.5;
		else
			return Vector64(0.0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets half the distance between the minimum and the maximum (the size).
	/// @return												The size of the bounds.
	//----------------------------------------------------------------------------------------
	inline Vector64 GetRad(void) const
	{
		if (used)
			return (max - min) * 0.5;
		else
			return Vector64(0.0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets both the center and size of the bounding box.
	/// @param[out] mp								Assigned the center of the bounds.
	/// @param[out] rad								Assigned the size of the bounds.
	//----------------------------------------------------------------------------------------
	inline void GetMpRad(Vector64* mp, Vector64* rad) const
	{
		if (used)
		{
			*mp = (min + max) * 0.5; *rad = max - *mp;
		}
		else
		{
			*mp = *rad = Vector64(0.0);
		}
	}
};

//-------------------------------------------------------------------------------------------------
/// A class to construct a bounding box around points.
//-------------------------------------------------------------------------------------------------
class SMinMax
{
private:
	Vector32 min, max;
	Bool used;

public:
	//-------------------------------------------------------------------------------------------------
	/// Default constructor.
	//-------------------------------------------------------------------------------------------------
	SMinMax() { min = Vector32(MAXVALUE_FLOAT32); max = Vector32(MINVALUE_FLOAT32); used = false; }

	//----------------------------------------------------------------------------------------
	/// Constructs with vector @formatParam{v} set for both the minimum and maximum.
	/// @param[in] v									The vector for minimum and maximum.
	//----------------------------------------------------------------------------------------
	explicit SMinMax(const Vector32& v) { min = max = v; used = true; }

	//-------------------------------------------------------------------------------------------------
	/// Resets the minimum and maximum to the largest values possible.
	//-------------------------------------------------------------------------------------------------
	inline void Init(void) { min = Vector32(MAXVALUE_FLOAT32); max = Vector32(MINVALUE_FLOAT32); used = false; }

	//----------------------------------------------------------------------------------------
	/// Initializes the minimum and maximum with vector @formatParam{v}.
	/// @param[in] v									The value to initialize minimum and maximum.
	//----------------------------------------------------------------------------------------
	inline void Init(const Vector32& v) { min = max = v; used = true; }

	//----------------------------------------------------------------------------------------
	/// Adds point @formatParam{p} and recalculates the minimum and maximum.
	/// @param[in] p									The point to add into the bounds.
	//----------------------------------------------------------------------------------------
	inline void AddPoint(const Vector32& p)
	{
		if (used)
		{
			if (p.x < min.x)
				min.x = p.x;
			if (p.y < min.y)
				min.y = p.y;
			if (p.z < min.z)
				min.z = p.z;
			if (p.x > max.x)
				max.x = p.x;
			if (p.y > max.y)
				max.y = p.y;
			if (p.z > max.z)
				max.z = p.z;
		}
		else
		{
			min	 = max = p;
			used = true;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Adds points @formatParam{a} and @formatParam{b} and recalculates the minimum and maximum.
	/// @param[in] a									The minimum point to add into the bounds.
	/// @param[in] b									The maximum point to add into the bounds.
	//----------------------------------------------------------------------------------------
	inline void AddPoints(const Vector32& a, const Vector32& b)
	{
		used = true;
		if (a.x < min.x)
			min.x = a.x;
		if (a.y < min.y)
			min.y = a.y;
		if (a.z < min.z)
			min.z = a.z;
		if (b.x > max.x)
			max.x = b.x;
		if (b.y > max.y)
			max.y = b.y;
		if (b.z > max.z)
			max.z = b.z;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the minimum and maximum of the bounding box.
	/// @param[in] a									The minimum.
	/// @param[in] b									The maximum.
	//----------------------------------------------------------------------------------------
	inline void Set(const Vector32& a, const Vector32& b)
	{
		used = true;
		min	 = a;
		max	 = b;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if any points were added.
	/// @return												@trueIfOtherwiseFalse{if any points were added to the bounds}
	//----------------------------------------------------------------------------------------
	inline Bool IsPopulated(void) const { return used; }

	//----------------------------------------------------------------------------------------
	/// Gets the minimum of the bounding box.
	/// @return												The minimum position of the bounds.
	//----------------------------------------------------------------------------------------
	inline const Vector32& GetMin(void) const
	{
		extern Vector32 s_empty;
		if (used)
			return min;
		else
			return s_empty;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the maximum of the bounding box.
	/// @return												The maximum position of the bounds.
	//----------------------------------------------------------------------------------------
	inline const Vector32& GetMax(void) const
	{
		extern Vector32 s_empty;
		if (used)
			return max;
		else
			return s_empty;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the middle between the minimum and maximum (the center).
	/// @return												The center of the bounds.
	//----------------------------------------------------------------------------------------
	inline Vector32 GetMp(void) const
	{
		if (used)
			return (min + max) * (Float32) 0.5;
		else
			return Vector32(0.0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets half the distance between the minimum and the maximum (the size).
	/// @return												The size of the bounds.
	//----------------------------------------------------------------------------------------
	inline Vector32 GetRad(void) const
	{
		if (used)
			return (max - min) * (Float32) 0.5;
		else
			return Vector32(0.0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets both the center and size of the bounding box.
	/// @param[out] mp								Assigned the center of the bounds.
	/// @param[out] rad								Assigned the size of the bounds.
	//----------------------------------------------------------------------------------------
	inline void GetMpRad(Vector32* mp, Vector32* rad) const
	{
		if (used)
		{
			*mp = (min + max) * (Float32) 0.5; *rad = max - *mp;
		}
		else
		{
			*mp = *rad = Vector32(0.0);
		}
	}
};

typedef LMinMax MinMax;

//-------------------------------------------------------------------------------------------------
/// A class to generate random number sequences.\n
/// Uniform and Gaussian deviates can be generated.
//-------------------------------------------------------------------------------------------------
class Random
{
private:
	UInt32 seed;
	Int32 iset;
	Float gset;

public:
	//-------------------------------------------------------------------------------------------------
	/// Default constructor.
	//-------------------------------------------------------------------------------------------------
	Random();

	//----------------------------------------------------------------------------------------
	/// Initializes the random number sequence from a starting seed. Each seed will give a different sequence of random numbers.
	/// @param[in] s									The initial seed to start the random number sequence.
	//----------------------------------------------------------------------------------------
	void Init(UInt32 s);

	//----------------------------------------------------------------------------------------
	/// Gets a random value between @em 0 and @em 1.
	/// @return												A random value in the range [@em 0, @em 1].
	//----------------------------------------------------------------------------------------
	Float Get01(void);

	//----------------------------------------------------------------------------------------
	/// Gets a random value between @em -1 and @em +1.
	/// @return												A random value in the range [@em -1, @em +1].
	//----------------------------------------------------------------------------------------
	Float Get11(void);

	//----------------------------------------------------------------------------------------
	/// Gets a random value between @em 0 and @em 1 with Gaussian distribution.
	/// @return												A random value in the range [@em 0, @em 1] with Gaussian distribution.
	//----------------------------------------------------------------------------------------
	Float GetG01(void);

	//----------------------------------------------------------------------------------------
	/// Gets a random value between @em -1 and @em +1 with Gaussian distribution.
	/// @return												A random value in the range [@em -1, @em +1] with Gaussian distribution.
	//----------------------------------------------------------------------------------------
	Float GetG11(void);

	//----------------------------------------------------------------------------------------
	/// Gets the seed representing the current state of the random number generator.
	/// @return												The current seed.
	//----------------------------------------------------------------------------------------
	Int32 GetSeed(void) const { return seed; }
};

//----------------------------------------------------------------------------------------
/// Converts RGB into the HSV color space.
/// @param[in] col								The RGB color to convert.
/// @return												The converted HSV color.
//----------------------------------------------------------------------------------------
Vector RGBToHSV(const Vector& col);

//----------------------------------------------------------------------------------------
/// Converts HSV into the RGB color space.
/// @param[in] col								The HSV color to convert.
/// @return												The converted RGB color.
//----------------------------------------------------------------------------------------
Vector HSVToRGB(const Vector& col);

//----------------------------------------------------------------------------------------
/// Converts RGB into the HSL color space.
/// @param[in] col								The RGB color to convert.
/// @return												The converted HSL color.
//----------------------------------------------------------------------------------------
Vector RGBToHSL(const Vector& col);

//----------------------------------------------------------------------------------------
/// Converts HSL into the RGB color space.
/// @param[in] col								The HSL color to convert.
/// @return												The converted RGB color.
//----------------------------------------------------------------------------------------
Vector HSLtoRGB(const Vector& col);

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct RayShaderStackElement
{
	const TexList*	texture;
	const void*			texture_link;
	Float32					visibility;
};

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct MsgGICSExData
{
	Int32	action;	// 0: load; 1: save; 2:flush
	const Filename*	fn;
	Bool	success;
};

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct MsgGINewData
{
	Int32							action;	// 0: Animation Prepass, 1 - Net Cache File Notify, 2 - NET Cache File, 3 - Cache Reload, 10 - Baker State
	const VideoPostStruct*	vps;
	const Filename*					fn;
	Bool							success;
	Int32							state;
	Float							scale;
};

#ifndef __API_INTERN__

//----------------------------------------------------------------------------------------
/// Calculates a point along a spline curve from a set of points in 3D space.
/// @since R17.032
/// @param[in] offset							The offset along the spline from @em 0.0 to @em 1.0.
/// @param[in] type								The type of spline, i.e. AKIMA, BSPLINE etc.
/// @param[in] closed							Whether the spline is closed or not.
/// @param[in] pcnt								The number of points in the spline.
/// @param[in] padr								The points array.
/// @param[in] tadr								The tangents array, required for Bezier, Cubic and Akima spline types (otherwise will default to b-spline).
/// @return												The resulting point calculated from the offset.
//----------------------------------------------------------------------------------------
Vector	CalcSplinePoint(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr = nullptr);

//----------------------------------------------------------------------------------------
/// Calculates the tangent of a point along a spline curve from a given set of points and optional tangents.
/// @since R17.032
/// @param[in] offset							The offset along the spline from @em 0.0 to @em 1.0.
/// @param[in] type								The type of spline, i.e. AKIMA, BSPLINE etc.
/// @param[in] closed							Whether the spline is closed or not.
/// @param[in] pcnt								The number of points in the spline.
/// @param[in] padr								The points array.
/// @param[in] tadr								The tangents array, required for Bezier, Cubic and Akima spline types (otherwise will default to b-spline).
/// @return												The resulting tangent (normalized) for the given offset.
//----------------------------------------------------------------------------------------
Vector	CalcSplineTangent(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr = nullptr);

//----------------------------------------------------------------------------------------
/// Calculates data about a point would if it were inserted into the spline at the passed offset.
/// @since R17.032
/// @param[in] offset							The offset to calculate the point for.
/// @param[in] type								The spline type.
/// @param[in] closed							The closed state of the spline points.
/// @param[in] pcnt								The number of points in the spline.
/// @param[in] padr								The address of the points array.
/// @param[in] tadr								The (optional) address of the tangents array.
/// @param[out] pointIndex				The index that the resulting point would be if it were inserted into the spline.
/// @param[out] resultPoint				The position of the resulting point.
/// @param[out] resultTangent			The spline tangent information of the resulting point.
/// @param[out] leftTangent				The correct new left tangent (tadr[pointIndex - 1].vr).
/// @param[out] rightTangent			The correct new right tangent (tadr[pointIndex].vl).
//----------------------------------------------------------------------------------------
void CalcSplineInsert(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr, Int32 &pointIndex, Vector &resultPoint, Tangent &resultTangent, Vector &leftTangent, Vector &rightTangent);

//----------------------------------------------------------------------------------------
/// Creates a transformed tangent around a point and plane, allowing to directly set the position of one of the tangent handles and automatically rotating the rest of the tangent to match.
/// @since R17.032
/// @param[in] newPos							The new position for the tangent handle.
/// @param[in] planeNormal				The normal of the plane for rotation of the handles.
/// @param[in] position						The position of the center of the tangent being modified.
/// @param[in] tangent						The tangent to modify/derive the resulting tangent from.
/// @param[in] tangentSide				The handle to modify of the tangent, left, right, or none.
/// @param[in] flags							The flags for controlling tangent breaking, rotation and scale locking etc.
/// @return												The resulting transformed tangent.
//----------------------------------------------------------------------------------------
Tangent TransformTangent(const Vector& newPos, const Vector& planeNormal, const Vector& position, const Tangent& tangent, TANGENTSIDE tangentSide, TANGENTTRANSFORMFLAG flags = TANGENTTRANSFORMFLAG::BREAK_SCALE);

//----------------------------------------------------------------------------------------
/// Moves a point on a spline curve to a user specified new position.
/// @since R17.032
/// @param[in] newPos							The new position for the point of the curve at offset.
/// @param[in] offset							The offset to move to the position @formatParam{newPos}.
/// @param[in] type								The type of spline to move.
/// @param[in] splineMg						The matrix of the spline.
/// @param[in] bd									The (optional) basedraw.
/// @param[in] planeNormal				The normal for tangent rotation, typically @c Vector(0,0,1).
/// @param[in] closed							The closed state of the spline.
/// @param[in] lockTangentAngle		@formatConstant{true} if tangents angle may not be changed by this routine.
/// @param[in] lockTangentLength	@formatConstant{true} if the tangents length may not be changed by this routine.
/// @param[in] breakTangents			Set to break the tangents while manipulating the curve if tangents exist.
/// @param[in] pcnt								The number of points in the spline.
/// @param[out] padr							The address of the points that describe the spline.
/// @param[out] tadr							The (optional) address of the tangents that are used by the spline.
//----------------------------------------------------------------------------------------
void CalcSplineMovement(const Vector& newPos, Float offset, SPLINETYPE type, const Matrix& splineMg, BaseDraw* bd, const Vector& planeNormal, Bool closed, Bool lockTangentAngle, Bool lockTangentLength, BREAKTANGENTS breakTangents, Int32 pcnt, Vector* padr, Tangent* tadr);

//----------------------------------------------------------------------------------------
/// Calculates the default tangents for the passed points (spline segment) based on the spline type.
/// @since R17.032
/// @param[in] type								The spline type to calculate the tangents for.
/// @param[in] closed							Whether the spline segment is closed.
/// @param[in] pcnt								The number of points to calculate.
/// @param[in] padr								The address of the points.
/// @param[out] tadr							The resulting tangents (caller owns the array, must be pre-allocated).
/// @return												@formatConstant{true} on success, @formatConstant{false} on failure to generate the tangents.
//----------------------------------------------------------------------------------------
Bool CalcSplineDefaultTangents(SPLINETYPE type, Bool closed, Int32 pcnt, const Vector* padr, Tangent* tadr);

//----------------------------------------------------------------------------------------
/// Booleans an initial SplineObject with an array of other SplineObjects along a passed projection axis (in 2D).
/// @since R17.032
/// @param[in] initialSpline			The original SplineObject that will have the operations applied to it.
/// @param[in] booleanObjects			The array of SplineObjects to boolean with the initialSpline.
/// @param[in] doc								The active document that the objects belong to.
/// @param[in] bd									The active BaseDraw.
/// @param[in] projectionAxis			The projection axis to use, XY, ZY, screen space etc.
/// @param[in] booleanMode				The type of boolean to apply (Union, Subtract etc).
/// @return												The result of the Boolean operation (a new SplineObject, called owns), @formatConstant{nullptr} if there was an error.
//----------------------------------------------------------------------------------------
SplineObject* BooleanSplines(SplineObject* initialSpline, AtomArray* booleanObjects, BaseDocument *doc, BaseDraw* bd, SPLINEBOOL_AXIS projectionAxis, SPLINEBOOL_MODE booleanMode);

//----------------------------------------------------------------------------------------
/// A class to generate stratified 2D random numbers.
//----------------------------------------------------------------------------------------
class Stratified2DRandom
{
private:
	Stratified2DRandom();
	~Stratified2DRandom();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{generator}
	/// @return												@allocReturn{generator}
	//----------------------------------------------------------------------------------------
	static Stratified2DRandom* Alloc(void) { return C4DOS.Sh->SNAlloc(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{generators}
	/// @param[in,out] rnd						@theToDestruct{generator}
	//----------------------------------------------------------------------------------------
	static void Free(Stratified2DRandom*& rnd) { C4DOS.Sh->SNFree(rnd); rnd = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Initializes the generator.
	/// @param[in] initial_value			Initial value.
	/// @param[in] reset							@trueIfOtherwiseFalse{the generator should be reset}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(Int32 initial_value, Bool reset) { return (this->*C4DOS.Sh->SNInit)(initial_value, reset); }

	//----------------------------------------------------------------------------------------
	/// Gets the next random value pair.
	/// @param[in] xx									Assigned the first random value.
	/// @param[in] yy									Assigned the second random value.
	//----------------------------------------------------------------------------------------
	void GetNext(Float* xx, Float* yy) { (this->*C4DOS.Sh->SNGetNext)(xx, yy); }
};

/// @addtogroup c4d_tools_noiseturbulence Noise/Turbulence
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Generates a signed noise value.
/// @param[in] p									The noise coordinate.
/// @return												The signed noise value, between @em -1.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float SNoise(const Vector& p) { return C4DOS.Sh->SNoise(p); }

//----------------------------------------------------------------------------------------
/// Generates a signed noise value.
/// @param[in] p									The noise coordinate.
/// @param[in] t									The time.
/// @return												The signed noise value, between @em -1.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float SNoise(const Vector& p, Float t) { return C4DOS.Sh->SNoiseT(p, t); }

//----------------------------------------------------------------------------------------
/// Generates a noise value.
/// @param[in] p									The noise coordinate.
/// @return												The noise value, between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float Noise(const Vector& p) { return C4DOS.Sh->Noise(p); }

//----------------------------------------------------------------------------------------
/// Generates a noise value.
/// @param[in] p									The noise coordinate.
/// @param[in] t									The time.
/// @return												The noise value, between @em 0.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float Noise(const Vector& p, Float t) { return C4DOS.Sh->NoiseT(p, t); }

//----------------------------------------------------------------------------------------
/// Generates a periodical noise value.\n
/// PNoise is based on SNoise():
/// @code
/// #define NOISERES 1024
/// pnoise = SNoise(Vector(p.x*NOISERES/d.x, p.y*NOISERES/d.y, p.z*NOISERES/d.z));
/// @endcode
/// @param[in] p									The noise coordinate.
/// @param[in] d									The period.
/// @return												The periodical noise value.
//----------------------------------------------------------------------------------------
inline Float PNoise(const Vector& p, const Vector& d) { return C4DOS.Sh->PNoise(p, d); }

//----------------------------------------------------------------------------------------
/// Generates a periodical noise value.\n
/// PNoise is based on SNoise():
/// @code
/// #define NOISERES 1024
/// pnoise = SNoise(Vector(p.x*NOISERES/d.x, p.y*NOISERES/d.y, p.z*NOISERES/d.z));
/// @endcode
/// @param[in] p									The noise coordinate.
/// @param[in] t									The time.
/// @param[in] d									The period.
/// @param[in] dt									The time period.
/// @return												The periodical noise value.
//----------------------------------------------------------------------------------------
inline Float PNoise(const Vector& p, Float t, const Vector& d, Float dt) { return C4DOS.Sh->PNoiseT(p, t, d, dt); }

//----------------------------------------------------------------------------------------
/// Generates a turbulence value, this is a sum of multiple noises with different frequency.
/// @param[in] p									The turbulence coordinate.
/// @param[in] oct								The number of octaves.
/// @param[in] abs								@formatConstant{true} for the absolute value.
/// @return												The turbulence value, between @em -1.0 and @em 1.0 unless @formatParam{abs} is @formatConstant{true}, in which case it will be between @em 0.0 to @em 1.0.
//----------------------------------------------------------------------------------------
inline Float Turbulence(const Vector& p, Float oct, Bool abs) { return C4DOS.Sh->Turbulence(p, oct, abs); }

//----------------------------------------------------------------------------------------
/// Generates a turbulence value, this is a sum of multiple noises with different frequency.
/// @param[in] p									The turbulence coordinate.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves.
/// @param[in] abs								@formatConstant{true} for the absolute value.
/// @return												The turbulence value, between @em -1.0 and @em 1.0 unless @formatParam{abs} is @formatConstant{true}, in which case it will be between @em 0.0 to @em 1.0.
//----------------------------------------------------------------------------------------
inline Float Turbulence(const Vector& p, Float t, Float oct, Bool abs) { return C4DOS.Sh->TurbulenceT(p, t, oct, abs); }

//----------------------------------------------------------------------------------------
/// Generates a wavy turbulence value, this is a sum of multiple noises with different frequency.
/// @param[in] p									The turbulence coordinate.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves.
/// @param[in] start							The start value.
/// @return												The turbulence value, between @em -1.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float WavyTurbulence(const Vector& p, Float t, Float oct, Float start) { return C4DOS.Sh->WavyTurbulence(p, t, oct, start); }

/// @}

/// @addtogroup c4d_tools_fbm Fbm
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Initializes the tables needed for the Fractional Brownian Motion.\n
/// @b Example:
/// @code
/// Float arr[20];
/// InitFbm(arr, 10, 2.0, 0.5); // max_octaves must not exceed 18 (as the array can contain 20 values maximum)
/// @endcode
/// @param[in] table							A preallocated array of size @formatParam{max_octaves}+@em 2. @callerOwnsPointed{array}
/// @param[in] max_octaves				The number of octaves for the table.
/// @param[in] lacunarity					The gap between successive frequencies.
/// @param[in] h									The fractal increment parameter.
//----------------------------------------------------------------------------------------
inline void InitFbm(Float* table, Int32 max_octaves, Float lacunarity, Float h) { C4DOS.Sh->InitFbm(table, max_octaves, lacunarity, h); }

//----------------------------------------------------------------------------------------
/// Generates a Fractional Brownian Motion value.
/// @note InitFbm() must be called before this function.
/// @param[in] table							The preallocated and initialized table by InitFbm(). @callerOwnsPointed{array}
/// @param[in] p									The evaluation point.
/// @param[in] oct								The number of octaves. Must not exceed the @c max_octaves value passed to InitFbm(), but can be lower.
/// @return												The fBm value.
//----------------------------------------------------------------------------------------
inline Float Fbm(Float* table, const Vector& p, Float oct) { return C4DOS.Sh->Fbm(table, p, oct); }

//----------------------------------------------------------------------------------------
/// Generates a Fractional Brownian Motion value.
/// @note InitFbm() must be called before this function.
/// @param[in] table							The preallocated and initialized table by InitFbm(). @callerOwnsPointed{array}
/// @param[in] p									The evaluation point.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves. Must not exceed the @c max_octaves value passed to InitFbm(), but can be lower.
/// @return												The fBm value.
//----------------------------------------------------------------------------------------
inline Float Fbm(Float* table, const Vector& p, Float t, Float oct) { return C4DOS.Sh->FbmT(table, p, t, oct); }

//----------------------------------------------------------------------------------------
/// Generates a fractal function used for such things as landscapes or mountain ranges.
/// @note InitFbm() must be called before this function.
/// @param[in] table							The preallocated and initialized table by InitFbm(). @callerOwnsPointed{array}
/// @param[in] p									The evaluation point.
/// @param[in] oct								The number of octaves. Must not exceed the @c max_octaves value passed to InitFbm(), but can be lower.
/// @param[in] offset							The zero offset, this controls the multi-fractal.
/// @param[in] gain								The amplification of the fractal value.
/// @return												The fractal value.
//----------------------------------------------------------------------------------------
inline Float RidgedMultifractal(Float* table, const Vector& p, Float oct, Float offset, Float gain) { return C4DOS.Sh->RidgedMultifractal(table, p, oct, offset, gain); }

/// @}

//----------------------------------------------------------------------------------------
/// Calculates the value of a spline at a point.
/// @param[in] x									The position on the spline.
/// @param[in] knot								The spline knots array. @callerOwnsPointed{array}
/// @param[in] nknots							The number of knots.
/// @return												The spline value.
//----------------------------------------------------------------------------------------
inline Float CalcSpline(Float x, Float* knot, Int32 nknots) { return C4DOS.Sh->CalcSpline(x, knot, nknots); }

//----------------------------------------------------------------------------------------
/// Calculates the value of a spline at a point.
/// @param[in] x									The position on the spline.
/// @param[in] knot								The spline knots array. @callerOwnsPointed{array}
/// @param[in] nknots							The number of knots.
/// @return												The spline point.
//----------------------------------------------------------------------------------------
inline Vector CalcSpline(Float x, Vector* knot, Int32 nknots) { return C4DOS.Sh->CalcSplineV(x, knot, nknots); }

/// @addtogroup c4d_tools_periodical Periodical Noise/Turbulence/Fbm
/// @ingroup group_function
/// @{

/// Noise resolution.
static const Int32 NOISE_RESOLUTION = 1024;

//----------------------------------------------------------------------------------------
/// Generates a periodic signed noise value.
/// @param[in] p									The noise coordinate.
/// @param[in] t									The time.
/// @param[in] t_repeat						The time repeat. Must be @em 2^@c x - @em 1, where @c x = [@em 1..@em 10], i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
/// 															A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{t_repeat} the noise will repeat at an earlier time.
/// @return												The signed noise value, between @em -1.0 and @em 1.0.
//----------------------------------------------------------------------------------------
inline Float SNoiseP(Vector p, Float t, Int32 t_repeat) { return C4DOS.Sh->SNoiseP(p, t, t_repeat); }

//----------------------------------------------------------------------------------------
/// Generates a periodic turbulence value, this is a sum of multiple noises with different frequency.
/// @param[in] p									The noise coordinate.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves.
/// @param[in] abs								@formatConstant{true} for the absolute value.
/// @param[in] t_repeat						The time repeat. Must be @em 2^@c x - @em 1, where @c x = [@em 1..@em 10], i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
/// 															A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{t_repeat} the noise will repeat at an earlier time.
/// @return												The turbulence value, between @em -1.0 and @em 1.0 unless @formatParam{abs} is @formatConstant{true}, in which case it will be between @em 0.0 to @em 1.0.
//----------------------------------------------------------------------------------------
inline Float TurbulenceP(Vector p, Float t, Float oct, Bool abs, Int32 t_repeat) { return C4DOS.Sh->TurbulenceP(p, t, oct, abs, t_repeat); }

//----------------------------------------------------------------------------------------
/// Generates a periodic Fractional Brownian Motion value.
/// @note InitFbm() must be called before this function.
/// @param[in] table							The preallocated and initialized table by InitFbm(). @callerOwnsPointed{array}
/// @param[in] p									The evaluation point.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves. Must not exceed the @c max_octaves value passed to InitFbm(), but can be lower.
/// @param[in] t_repeat						The time repeat. Must be @em 2^@c x - @em 1, where @c x = [@em 1..@em 10], i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
/// 															A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{t_repeat} the noise will repeat at an earlier time.
/// @return												The fBm value.
//----------------------------------------------------------------------------------------
inline Float FbmP(Float* table, Vector p, Float t, Float oct, Int32 t_repeat) { return C4DOS.Sh->FbmP(table, p, t, oct, t_repeat); }

//----------------------------------------------------------------------------------------
/// Generates a periodic fractal function used for such things as landscapes or mountain ranges.
/// @note InitFbm() must be called before this function.
/// @param[in] table							The preallocated and initialized table by InitFbm(). @callerOwnsPointed{array}
/// @param[in] p									The evaluation point.
/// @param[in] t									The time.
/// @param[in] oct								The number of octaves. Must not exceed the @c max_octaves value passed to InitFbm(), but can be lower.
/// @param[in] offset							The zero offset, this controls the multi-fractal.
/// @param[in] gain								The amplification of the fractal value.
/// @param[in] t_repeat						The time repeat. Must be @em 2^@c x - @em 1, where @c x = [@em 1..@em 10], i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
/// 															A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{t_repeat} the noise will repeat at an earlier time.
/// @return												The fractal value.
//----------------------------------------------------------------------------------------
inline Float RidgedMultifractalP(Float* table, Vector p, Float t, Float oct, Float offset, Float gain, Int32 t_repeat) { return C4DOS.Sh->RidgedMultifractalP(table, p, t, oct, offset, gain, t_repeat); }

/// @}

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct DisplaceInfo
{
	DisplaceInfo()
	{
		dispn = nullptr;
		displacenum = nullptr;
	};
	Vector* dispn;
	Int32*	displacenum;
};

struct VolumeData : public BaseVolumeData
{
private:
	VolumeData();
	~VolumeData();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{volume data}
	/// @warning Should normally not be used.
	/// @return												@allocReturn{volume data}
	//----------------------------------------------------------------------------------------
	static VolumeData* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{volume data}
	/// @param[in,out] vd							@theToDestruct{volume data}
	//----------------------------------------------------------------------------------------
	static void Free(VolumeData*& vd);

	/// @}

	//----------------------------------------------------------------------------------------
	/// If you code custom illumination models (e.g. different specular function) you can do this for standard light sources easily.\n
	/// For area lights you will usually want to fall back to the default illumination model though, as otherwise you would have to rebuild the sample code of area lights!\n
	/// Here is an example how to sample area lights using this method:
	/// @code
	/// for (i=sd->GetLightCount()-1; i>=0; i--)
	/// {
	/// 		lp = sd->GetLight(i);
	/// 		if (!sd->IlluminateSurfacePoint(lp,&col,&lv,sd->p,sd->bumpn,sd->n,sd->orign,SV(sd->ray->v),sd->calc_shadow,sd->lhit,sd->raybits,true))
	/// 			continue;
	/// 		if (lp->ambient)
	/// 		{
	/// 			*diffuse += col;
	/// 			continue;
	/// 		}
	///
	/// 		nodif = nospec = false;
	/// 		if (lp->lr.object)
	/// 			CalcRestrictionInc(&lp->lr,sd->op,nodif,nospec);
	///
	/// 		if (lp->type==RT_LT_AREA)
	/// 		{
	/// 			Vector dif,spc;
	/// 			sd->CalcArea(lp,nodif,nospec,exponent,SV(sd->ray->v),sd->p,sd->bumpn,sd->orign,sd->raybits,&dif,&spc);
	///
	/// 			*diffuse  += dif^col;
	/// 			*specular += spc^col;
	/// 		}
	/// 		else
	/// 		{
	/// 			cosa=lv*sd->bumpn;
	/// 			if (!(lp->nodiffuse || nodif) && sd->cosc*cosa>=0.0)
	/// 			{
	/// 				if (lp->contrast!=0.0)
	/// 					*diffuse += Pow(Abs(cosa),Exp(-lp->contrast))*col;
	/// 				else
	/// 					*diffuse += Abs(cosa)*col;
	/// 		}
	///
	/// 		if (calc_specular && !(lp->nospecular || nospec))
	/// 		{
	/// 			cosb=SV(sd->ray->v) * (lv - sd->bumpn*(2.0 * cosa));
	/// 			if (cosb<=0.0) continue;
	///
	/// 			*specular += Pow(cosb,exponent)*col;
	/// 		}
	/// 		}
	/// 	}
	///
	/// 	diffuse.ClampMin(); // there can be subtractive light sources
	/// 	specular.ClampMin();
	/// }
	/// @endcode
	/// @param[in] light							The area light to calculate.
	/// @param[in] nodiffuse					@trueIfOtherwiseFalse{the diffuse value should not be calculated}
	/// @param[in] nospecular					@trueIfOtherwiseFalse{the specular value should not be calculated}
	/// @param[in] specular_exponent	The specular exponent to use.
	/// @param[in] ray_vector					The ray vector.
	/// @param[in] p									The surface point.
	/// @param[in] bumpn							The bump normal.
	/// @param[in] orign							The original normal.
	/// @param[in] raybits						The ray bits: @enumerateEnum{RAYBIT}
	/// @param[in] ignoreLightColor		Whether to factor the light color into the result
	/// @param[out] diffuse						Assigned the diffuse component.
	/// @param[out] specular					Assigned the specular component.
	//----------------------------------------------------------------------------------------
	void CalcArea(const RayLight* light, Bool nodiffuse, Bool nospecular, Float specular_exponent, const Vector64& ray_vector, const Vector64& p, const Vector64& bumpn, const Vector64& orign, RAYBIT raybits, Bool ignoreLightColor, Vector* diffuse, Vector* specular) { C4DOS.Sh->CalcArea(this, light, nodiffuse, nospecular, specular_exponent, ray_vector, p, bumpn, orign, raybits, ignoreLightColor, diffuse, specular); }

	//----------------------------------------------------------------------------------------
	/// Computes a shadow.
	/// @param[in] l									The illuminating light source. @callerOwnsPointed{light}
	/// @param[in] p									The point in global coordinates.
	/// @param[in] bumpn							The bump normal.
	/// @param[in] phongn							The phong normal.
	/// @param[in] orign							The original normal.
	/// @param[in] rayv								The ray vector.
	/// @param[in] transparency				@formatConstant{true} if transparencies/alphas for in between objects should be evaluated.
	/// @param[in] hitid							The global RayHitID structure for the surface intersection (to avoid self shadowing).\n
	/// 															Pass RayHitID() if not on a surface or to not use of this avoidance.
	/// @param[in] raybits						The ray bits: @enumerateEnum{RAYBIT}
	/// @return												The shadow value. If there is no shadow, @em 0.0 will be returned. @em 1.0 is the maximum shadow value for each component.
	//----------------------------------------------------------------------------------------
	Vector CalcShadow(const RayLight* l, const Vector64& p, const Vector64& bumpn, const Vector64& phongn, const Vector64& orign, const Vector64& rayv, Bool transparency, const RayHitID& hitid, RAYBIT raybits) { return C4DOS.Sh->CalcShadow(this, l, p, bumpn, phongn, orign, rayv, transparency, hitid, raybits); }

	//----------------------------------------------------------------------------------------
	/// Calculates the intensity of incoming light for a given light and surface point. Used for custom illumination models.
	/// @param[in] rl									The illuminating light. @callerOwnsPointed{light}
	/// @param[out] col								Assigned the result of the calculation.
	/// @param[out] light_vector			Assigned the light to point vector. For area and tube lights the vector will use the center of the light source.
	/// @param[in] p									The surface point.
	/// @param[in] bumpn							The bump normal.
	/// @param[in] phongn							The phong normal.
	/// @param[in] orign							The original normal.
	/// @param[in] ray_vector					The ray vector.
	/// @param[in] flags							The illuminate flags: @enumerateEnum{ILLUMINATEFLAGS}
	/// @param[in] hitid							The global RayHitID structure for the surface intersection (to avoid self shadowing). Can be set to RayHitID() if you do not have the current RayHitID.
	/// @param[in] raybits						The ray bits: @enumerateEnum{RAYBIT}
	/// @param[in] cosine_cutoff			@trueIfOtherwiseFalse{cosine cut-off should be used}
	/// @return												@trueIfOtherwiseFalse{the light illuminates the objects surface point}
	//----------------------------------------------------------------------------------------
	Bool IlluminateSurfacePoint(const RayLight* rl, Vector* col, Vector64* light_vector, const Vector64& p, const Vector64& bumpn, const Vector64& phongn, const Vector64& orign, const Vector64& ray_vector, ILLUMINATEFLAGS flags, const RayHitID& hitid, RAYBIT raybits, Bool cosine_cutoff) { return C4DOS.Sh->Illuminate(this, rl, col, light_vector, p, bumpn, phongn, orign, ray_vector, flags, hitid, raybits, cosine_cutoff, nullptr); }

	//----------------------------------------------------------------------------------------
	/// Calculates the intensity of incoming light for a given light and arbitrary point. Used for custom illumination models.
	/// @param[in] rl									The illuminating light. @callerOwnsPointed{light}
	/// @param[out] col								Assigned the result of the calculation.
	/// @param[out] light_vector			Assigned the light to point vector. For area and tube lights the vector will use the center of the light source.
	/// @param[in] p									The surface point.
	/// @param[in] flags							The illuminate flags: @enumerateEnum{ILLUMINATEFLAGS}
	/// @param[in] raybits						The ray bits: @enumerateEnum{RAYBIT}
	/// @return												@trueIfOtherwiseFalse{the light illuminates the point}
	//----------------------------------------------------------------------------------------
	Bool IlluminateAnyPoint(const RayLight* rl, Vector* col, Vector64* light_vector, const Vector64& p, ILLUMINATEFLAGS flags, RAYBIT raybits) { return C4DOS.Sh->Illuminate(this, rl, col, light_vector, p, Vector64(0.0), Vector64(0.0), Vector64(0.0), Vector64(0.0), flags, RayHitID(), raybits, false, nullptr); }

	//----------------------------------------------------------------------------------------
	/// Calculates the diffuse and specular components for a given point.\n
	/// This function can calculate the illumination for any point in space and is widely used for volumetric shaders that display a surface structure (e.g. @C4D's terrain shader).
	/// @param[in] f									The surface point data used for the call. @callerOwnsPointed{data}
	/// @param[in] diffuse						Assigned the diffuse component.
	/// @param[in] specular						Assigned the specular component.
	//----------------------------------------------------------------------------------------
	void IlluminanceSurfacePoint(IlluminanceSurfacePointData* f, Vector* diffuse, Vector* specular) { C4DOS.Sh->IlluminanceSurfacePoint(this, f, diffuse, specular); }

	//----------------------------------------------------------------------------------------
	/// Calculates the light intensity for a given point @formatParam{p}.\n
	/// This function can calculate the illumination for any point in space and is widely used for transparent volumetric shaders (gases, clouds etc.).
	/// @param[in] p									The global coordinate point to calculate the illumination for.
	/// @param[in] flags							The illuminate flags: @enumerateEnum{ILLUMINATEFLAGS}
	/// @param[in] raybits						The ray bits: @enumerateEnum{RAYBIT}
	/// @return												The calculated color. Note its components can exceed values of @em 1.0!
	//----------------------------------------------------------------------------------------
	Vector IlluminanceAnyPoint(const Vector64& p, ILLUMINATEFLAGS flags, RAYBIT raybits) { return C4DOS.Sh->IlluminanceAnyPoint(this, p, flags, raybits); }

	//----------------------------------------------------------------------------------------
	/// Calculates the diffuse and specular components according to the current VolumeData and a given specular @formatParam{exponent}, or optionally using a custom illumination @formatParam{model}.
	/// @param[out] diffuse						Assigned the diffuse component.
	/// @param[out] specular					Assigned the specular component.
	/// @param[in] exponent						The exponent to calculate the specular component.\n
	/// 															If @formatParam{exponent}==@em 0.0 then no specular is calculated, otherwise a specular is calculated with @formatParam{exponent} as exponent value for the phong formula.
	/// @param[in] model							A custom illumination model, or @formatConstant{nullptr} to use the default illumination model. @callerOwnsPointed{illumination model}
	/// @param[in] data								The private data passed to the custom illumination function. @callerOwnsPointed{data}
	//----------------------------------------------------------------------------------------
	void IlluminanceSimple(Vector* diffuse, Vector* specular, Float exponent, IlluminationModel* model, void* data)
	{
		if (data)
			C4DOS.Sh->Illuminance(this, diffuse, specular, model, data);
		else
			C4DOS.Sh->Illuminance1(this, diffuse, specular, exponent);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the current thread index on which the shader is executed.
	/// @return												The running thread index, which is guaranteed to be <tt>>= 0</tt> and smaller than GetCPUCount().
	//----------------------------------------------------------------------------------------
	Int32 GetCurrentCPU() const { return C4DOS.Sh->GetCurrentCPU(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the thread count the renderer is utilizing.
	/// The value returned here can differ from or exceed the global GeGetCurrentThreadCount() as the renderer can utilize any different number of threads.
	/// @return												The number of utilized threads (>=1).
	//----------------------------------------------------------------------------------------
	Int32 GetCPUCount() const { return C4DOS.Sh->GetCPUCount(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves an object's number. Opposite of GetObj().
	/// @param[in] obj								The object to get the number for. @callerOwnsPointed{object}
	/// @return												The object's number.
	//----------------------------------------------------------------------------------------
	Int32 Obj_to_Num(const RayObject* obj) const { return C4DOS.Sh->Obj_to_Num(this, obj); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the object at @formatParam{index}.
	/// @param[in] index							The object index: @em 0<= index < GetObjCount()
	/// @return												The object. @theOwnsPointed{volume data,object}
	//----------------------------------------------------------------------------------------
	const RayObject* GetObj(Int32 index) const { return C4DOS.Sh->GetObj(this, index); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the overall number of objects.
	/// @return												The total number of objects.
	//----------------------------------------------------------------------------------------
	Int32 GetObjCount() const { return C4DOS.Sh->GetObjCount(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the UVW coordinates information for a polygon.
	/// @note If the polygon consists of three points (triangle) the fourth UVW coordinate 'd' may be uninitialized.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] uvwind							The UVW number (there may be several UVW coordinate sets): @em 1 <= @formatParam{uvwind} < @formatParam{op}->@link RayObject::uvwcnt uvwcnt@endlink
	/// @param[in] local_id						The local polygon ID: @em 0 <= @formatParam{local_id} < @formatParam{op}->@link RayObject::vcnt vcnt@endlink
	/// @param[out] uvw								Assigned the UVW coordinates. @callerOwnsPointed{coordinates}
	//----------------------------------------------------------------------------------------
	void GetUVW(const RayObject* op, Int32 uvwind, Int32 local_id, PolyVector* uvw) const { C4DOS.Sh->GetUVW(this, op, uvwind, local_id, uvw); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the phong normals for a polygon.
	/// @note If the polygon consists of three points (triangle) the fourth normal @link PolyVector::d d@endlink may be uninitialized.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] local_id						The local polygon ID: @em 0 <= @formatParam{local_id} < @formatParam{op}->@link RayObject::vcnt vcnt@endlink
	/// @param[out] norm							Assigned the phong normals. @callerOwnsPointed{coordinates}
	//----------------------------------------------------------------------------------------
	void GetNormals(const RayObject* op, Int32 local_id, PolyVector* norm) const { C4DOS.Sh->GetNormals(this, op, local_id, norm); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the texture at index of an object.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the texture: @em 0 <= @formatParam{index} < @formatParam{op}->@link RayObject::texcnt texcnt@endlink
	/// @return												The texture. @theOwnsPointed{volume data,texture}
	//----------------------------------------------------------------------------------------
	TexData* GetTexData(const RayObject* op, Int32 index) const { return C4DOS.Sh->GetTexData(this, op, index); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the face normal for a polygon.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] polygon						The local polygon ID: @em 0 <= @formatParam{local_id} < @formatParam{op}->@link RayObject::vcnt vcnt@endlink
	/// @param[in] second							@trueIfOtherwiseFalse{this is the second part of a quadrangle (A-C-D)}
	/// @return												The face normal.
	//----------------------------------------------------------------------------------------
	Vector64 GetNormal(const RayObject* op, Int32 polygon, Bool second) const { return C4DOS.Sh->GetNormal(this, op, polygon, second); }

	//----------------------------------------------------------------------------------------
	/// Gets the polygon state of the polygon with ID @formatParam{local_id} of object @formatParam{op}.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] local_id						The local polygon ID: @em 0 <= @formatParam{local_id} < @formatParam{op}->@link RayObject::vcnt vcnt@endlink
	/// @return												The polygon state: @enumerateEnum{RayTracePolystate}
	//----------------------------------------------------------------------------------------
	Int32 GetRayPolyState(const RayObject* op, Int32 local_id) const { return C4DOS.Sh->GetRayPolyState(this, op, local_id); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the unique object IP address.
	/// @note The ID is somewhat constant across frames so it is handy to identify objects in animation.
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @param[in] length							Assigned the length.
	/// @return												The pointer to the address of the unique ID. @cinemaOwnsPointed{ID}
	//----------------------------------------------------------------------------------------
	Int32* GetUniqueID(const RayObject* op, Int32& length) const { return C4DOS.Sh->GetUniqueID(this, op, length); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the phong normal for a point.
	/// @param[in] hitid							The global RayHitID.
	/// @param[in] p									The point for the phong normal. Must be within the surface boundaries of the polygon.
	/// @return												The phong normal.
	//----------------------------------------------------------------------------------------
	Vector64 GetSmoothedNormal(const RayHitID& hitid, const Vector64& p) const { return C4DOS.Sh->GetSmoothedNormal(this, hitid, p); }

	//----------------------------------------------------------------------------------------
	/// Calculates the R/S parameters for a point.\n
	/// To calculate the weighted data (e.g. based upon a color for each polygon point) do it the following way:
	/// @code
	/// Float r,s;
	/// Bool snd = sd->GetRS(hitid,p,&r,&s);
	///
	/// if (snd)
	/// 	result = [color a] * (1.0-r-s) + [color d]*r + [color c]*s
	/// else
	/// 	result = [color a] * (1.0-r-s) + [color b]*r + [color c]*s
	/// @endcode
	/// @param[in] hitid							The global RayHitID.
	/// @param[in] p									The point.
	/// @param[out] r									Assigned the R parameter.
	/// @param[out] s									Assigned the S parameter.
	/// @return												@formatConstant{true} if the polygon is a quadrangle for the second part (a-c-d) of the quadrangle or @formatConstant{false} for the first part (a-b-c).\n
	/// 															If the polygon is a triangle then this is the same as the first part of a quadrangle (a-b-c).
	//----------------------------------------------------------------------------------------
	Bool GetRS(const RayHitID& hitid, const Vector64& p, Float* r, Float* s) const { return C4DOS.Sh->GetRS(this, hitid, p, r, s); }

	//----------------------------------------------------------------------------------------
	/// Calculates the barycentric coordinates for a point on the surface of a polygon.\n
	/// @C4D uses enhanced interpolation routines for quadrangles, so you will get a higher quality using it instead of considering a quadrangle as two triangles.\n
	/// The routine works for any type of polygon, including triangles and non-coplanar quadrangles.
	///
	/// The function fills the @formatParam{wgt} structure with the weight factors for the global polygon with ID @formatParam{hitid} at point @formatParam{p} on polygon.\n
	/// Works similar to GetRS(), but has a higher quality. Here is an example:
	/// @code
	/// cd->vd->GetWeights(cd->vd->lhit, vSurfIntersect, &weight);
	/// Float rWeightA, rWeightB, rWeightC, rWeightD;
	/// Int32 lIndexA = pRayObject->vadr[lPolygonIndex].a;
	/// Int32 lIndexB = pRayObject->vadr[lPolygonIndex].b;
	/// Int32 lIndexC = pRayObject->vadr[lPolygonIndex].c;
	/// Int32 lIndexD = pRayObject->vadr[lPolygonIndex].d;
	/// rWeightA = prVertexMapData[lIndexA];
	/// rWeightB = prVertexMapData[lIndexB];
	/// rWeightC = prVertexMapData[lIndexC];
	/// rWeightD = prVertexMapData[lIndexD];
	/// rFunctionSample = weight.wa * rWeightA + weight.wb * rWeightB + weight.wc * rWeightC + weight.wd * rWeightD;
	/// @endcode
	/// @param[in] hitid							The global RayHitID.
	/// @param[in] p									The point on polygon.
	/// @param[out] wgt								Filled with the weight factors. @callerOwnsPointed{weights}
	//----------------------------------------------------------------------------------------
	void GetWeights(const RayHitID& hitid, const Vector64& p, RayPolyWeight* wgt) const { C4DOS.Sh->GetWeights(this, hitid, p, wgt); }

	//----------------------------------------------------------------------------------------
	/// Get the light source at @formatParam{index}.
	/// @param[in] index							The index of the light source to return: @em 0 <= @formatParam{index} < GetLightCount()
	/// @return												The light source. @theOwnsPointed{volume data,light}
	//----------------------------------------------------------------------------------------
	const RayLight* GetLight(Int32 index) const { return C4DOS.Sh->GetLight(this, index); }

	//----------------------------------------------------------------------------------------
	/// Gets the overall number of lights.
	/// @return												The number of lights.
	//----------------------------------------------------------------------------------------
	Int32 GetLightCount() const { return C4DOS.Sh->GetLightCount(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the number for a light. Opposite of GetLight().
	/// @param[in] light							The light to get the number for. @callerOwnsPointed{light}
	/// @return												The light's number.
	//----------------------------------------------------------------------------------------
	Int32 Light_to_Num(const RayLight* light) const { return C4DOS.Sh->Light_to_Num(this, light); }

	//----------------------------------------------------------------------------------------
	/// Retrieves one of the raytracer structures, these are also available as direct called, for example GetRaySky().
	/// @param[in] i									The requested structure type: @enumerateEnum{RAY}
	/// @return												The requested raytracer structure. @theOwnsPointed{volume data,structure}
	//----------------------------------------------------------------------------------------
	const void* GetRayData(Int32 i) const { return C4DOS.Sh->GetRayData(this, i); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the raytracer camera.
	/// @return												The camera. @theOwnsPointed{volume data,camera}
	//----------------------------------------------------------------------------------------
	const RayCamera* GetRayCamera() const { return (RayCamera*)C4DOS.Sh->GetRayData(this, RAY_CAMERA); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the raytracer parameters (settings).
	/// @note The raytracer uses a completely different representation than the normal scene (BaseDocument).\n
	///				It has new, efficient data structures where you do not need to check a lot of things.
	///				As you do not have a BaseDocument (it is still there for special purposes, but normally you will not have to deal with it in the raytracer) all relevant data structures can be obtained through VolumeData.
	/// @return												The raytracer parameters. Guaranteed to be valid (not @formatConstant{nullptr}). @theOwnsPointed{volume data,parameters}
	//----------------------------------------------------------------------------------------
	const RayParameter* GetRayParameter() const { return (RayParameter*)C4DOS.Sh->GetRayData(this, RAY_PARAMETER); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the raytracer environment parameters.
	/// @return												The raytracer environment. Guaranteed to be valid (not @formatConstant{nullptr}). @theOwnsPointed{volume data,parameters}
	//----------------------------------------------------------------------------------------
	const RayEnvironment* GetRayEnvironment() const { return (RayEnvironment*)C4DOS.Sh->GetRayData(this, RAY_ENVIRONMENT); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the sky object.
	/// @return												The sky object, or @formatConstant{nullptr} if none is there. @theOwnsPointed{volume data,sky object}
	//----------------------------------------------------------------------------------------
	const RayObject* GetRaySky() const { return (RayObject*)C4DOS.Sh->GetRayData(this, RAY_SKY); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the foreground object.
	/// @return												The foreground object, or @formatConstant{nullptr} if none is there. @theOwnsPointed{volume data,foreground object}
	//----------------------------------------------------------------------------------------
	const RayObject* GetRayForeground() const { return (RayObject*)C4DOS.Sh->GetRayData(this, RAY_FOREGROUND); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the background object.
	/// @return												The background object, or @formatConstant{nullptr} if none is there. @theOwnsPointed{volume data,background object}
	//----------------------------------------------------------------------------------------
	const RayObject* GetRayBackground() const { return (RayObject*)C4DOS.Sh->GetRayData(this, RAY_BACKGROUND); }

	//----------------------------------------------------------------------------------------
	/// Generates the view ray for a position.\n
	/// Does not set Ray::pp[@em 0..@em 2], Ray::vv[@em 0..@em 2], Ray::transport and Ray::ior. Those have to be filled in if used subsequently by TraceColor(), TraceColorDirect() or GetSurfaceData().\n
	/// It is not necessary for TraceGeometry() though (as there are no MIP mapping calculations).
	/// @code
	/// ray.ior=1.0;
	/// ray.transport=1.0;
	/// ray.pp[0]=ray.pp[1]=ray.pp[2]=SV(ray.p);
	/// ray.vv[0]=ray.vv[1]=ray.vv[2]=SV(ray.v);
	/// @endcode
	/// @param[in] x									The X position for the view ray in screen space coordinates.
	/// @param[in] y									The Y position for the view ray in screen space coordinates.
	/// @param[out] ray								Assigned the generated view ray. @callerOwnsPointed{ray}
	//----------------------------------------------------------------------------------------
	void GetRay(Float x, Float y, Ray* ray) const { C4DOS.Sh->GetRay(this, x, y, ray); }

	//----------------------------------------------------------------------------------------
	/// Transforms screen to camera coordinates.
	/// @note During QTVR rendering same point is returned.
	/// @param[in] p									The screen coordinate.
	/// @return												The camera coordinate.
	//----------------------------------------------------------------------------------------
	Vector64 ScreenToCamera(const Vector64& p) const { return C4DOS.Sh->ScreenToCamera(this, p); }

	//----------------------------------------------------------------------------------------
	/// Transforms camera to screen coordinates.
	/// @note During QTVR rendering same point is returned.
	/// @param[in] p									The camera coordinate.
	/// @return												The screen coordinate.
	//----------------------------------------------------------------------------------------
	Vector64 CameraToScreen(const Vector64& p) const { return C4DOS.Sh->CameraToScreen(this, p); }

	//----------------------------------------------------------------------------------------
	/// Calculates a hard shadow from point @formatParam{p1} to @formatParam{p2}.
	/// @note Set the @ref CALCHARDSHADOW::TRANSPARENCY flag if transparencies/alphas for in between objects shall be evaluated.\n
	///				An additional @formatParam{last_hit} can be passed to avoid self-shadowing (if starting on a surface). To not make use of it just pass @em 0.
	/// @param[in] p1									The start point for the hard shadow.
	/// @param[in] p2									The end point for the hard shadow.
	/// @param[in] flags							The flags: @enumerateEnum{CALCHARDSHADOW}
	/// @param[in] last_hit						The last intersection. Pass RayHitID() to include all polygons.
	/// @param[in] recursion_id				A plugin ID for data passed through recursion.
	/// @param[in] recursion_data			The data that can be passed through recursion.
	/// @return												The shadow value. @em 0.0 if there is no shadow. @em 1.0 is the maximum shadow value for each component.
	//----------------------------------------------------------------------------------------
	Vector CalcHardShadow(const Vector64& p1, const Vector64& p2, CALCHARDSHADOW flags, const RayHitID& last_hit, Int32 recursion_id = 0, void* recursion_data = nullptr) { return C4DOS.Sh->CalcHardShadow(this, p1, p2, flags, last_hit, recursion_id, recursion_data); }

	//----------------------------------------------------------------------------------------
	/// Computes the UVW coordinates for a texture.
	/// @param[in] tdp								The texture for the coordinate. @callerOwnsPointed{texture}
	/// @param[in] hit								The global RayHitID.
	/// @param[in] p									The point for the UVW coordinate.
	/// @return												The UVW coordinate.
	//----------------------------------------------------------------------------------------
	Vector GetPointUVW(const TexData* tdp, const RayHitID& hit, const Vector64& p) const { return C4DOS.Sh->GetPointUVW(this, tdp, hit, p); }

	//----------------------------------------------------------------------------------------
	/// Computes the UVW coordinates for a texture.
	/// @param[in] tdp								The texture for the coordinates. @callerOwnsPointed{texture}
	/// @param[in] hit								The global RayHitID.
	/// @param[in] p									The point for the UVW coordinate.
	/// @param[in] n									The normal for the UVW coordinate.
	/// @param[out] uv								Assigned the UVW coordinate.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ProjectPoint(const TexData* tdp, const RayHitID& hit, const Vector64& p, const Vector64& n, Vector* uv) const { return C4DOS.Sh->ProjectPoint(this, tdp, hit, p, n, uv); }

	//----------------------------------------------------------------------------------------
	/// Set the status bar text during initialization of a shader or videopost effect. If String() is passed the status bar will be cleared.
	/// @param[in] str								The status text to display.
	//----------------------------------------------------------------------------------------
	void StatusSetText(const maxon::String& str) const { C4DOS.Sh->StatusSetText(this, str); }

	//----------------------------------------------------------------------------------------
	/// Sets the status bar progress during initialization a your shader or videopost effect.
	/// @param[in] percentage					The percentage for the bar.
	//----------------------------------------------------------------------------------------
	void StatusSetBar(Float percentage) const { C4DOS.Sh->StatusSetBar(this, percentage); }

	//----------------------------------------------------------------------------------------
	/// Sets the render progress bar spinning. Use this to indicate that a plugin is still processing even if the progress bar is not increasing.
	/// @param[in] on									@formatConstant{true} to set the progress bar spinning, @formatConstant{false} to stop it.
	//----------------------------------------------------------------------------------------
	void StatusSetSpinMode(Bool on) const { C4DOS.Sh->StatusSetSpinMode(this, on); }

	//----------------------------------------------------------------------------------------
	/// Calculates the mixed color of all visible lights on a given @formatParam{ray} span.
	/// @param[in] ray								The ray span. @callerOwnsPointed{ray}
	/// @param[in] maxdist						The maximum distance for the lights.
	/// @param[out] trans							Assigned a value @c !=0 if some light sources have a dust effect.
	/// @return												The mixed color of the lights.
	//----------------------------------------------------------------------------------------
	Vector CalcVisibleLight(const Ray* ray, Float maxdist, Vector* trans) const { return C4DOS.Sh->CalcVisibleLight(this, ray, maxdist, trans); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the current X/Y pixel position in render resolution. %Render resolution is the screen resolution multiplied by @formatParam{scale}.
	/// @note @c Float(x)/Float(scale) and @c Float(y)/Float(scale) is the screen position.
	/// @param[out] x									Assigned the X pixel position.
	/// @param[out] y									Assigned the Y pixel position.
	/// @param[out] scale							Assigned the render scale.
	//----------------------------------------------------------------------------------------
	void GetXY(Int32* x, Int32* y, Int32* scale) const { C4DOS.Sh->GetXY(this, x, y, scale); }

	//----------------------------------------------------------------------------------------
	/// Sets the current X/Y pixel position in render resolution. %Render resolution is the screen resolution multiplied by @formatParam{scale}.
	/// @note @c Float(x)/Float(scale) and @c Float(y)/Float(scale) is the screen position.\n
	///				Certain Shaders use the screen pixel position. Plugins (like the Baker for instance) can change this position without having to render an image.
	/// @param[in] x									The X pixel position to set.
	/// @param[in] y									The Y pixel position to set.
	//----------------------------------------------------------------------------------------
	void SetXY(Float x, Float y) { C4DOS.Sh->SetXY(this, x, y); }

	//----------------------------------------------------------------------------------------
	/// Goes through all objects and calculates the scene boundaries. It does not take into account infinite sky/floor objects.
	/// @return												The boundary for all objects within the scene.
	//----------------------------------------------------------------------------------------
	MinMax GetSceneBoundaries() const { Vector64 min, max; MinMax MM; C4DOS.Sh->GetSceneBoundaries(this, min, max); MM.Set(min, max); return MM; }

	//----------------------------------------------------------------------------------------
	/// Copies the volume data to another VolumeData.
	/// @param[out] dst								The destination VolumeData. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	void CopyTo(VolumeData* dst) const { C4DOS.Sh->CopyVolumeData(this, dst); }

	//----------------------------------------------------------------------------------------
	/// Initializes the VolumeData with the data of the from object.\n
	/// Only the most essential parts are copied over, including the render instance.\n
	/// Such a VolumeData can be used for TraceColorDirect(), TraceGeometry(), TraceColor() etc.
	/// @note Init() is faster than CopyTo(), but does not allow subsequent access of functions like BaseMaterial::CalcSurface() (only possible if all members are initialized by hand).
	/// @param[in] from								The source volume data. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	void Init(VolumeData* from) { C4DOS.Sh->InitVolumeData(from, this); }

	//----------------------------------------------------------------------------------------
	/// Notify @C4D that a (severe) out-of-memory condition occurred.\n
	/// @C4D will stop as soon as possible, but there is no guarantee when exactly. It is possible that the shader could still be called several times, so it has to be programmed to handle this and to be crash-proof.
	//----------------------------------------------------------------------------------------
	void OutOfMemory() { C4DOS.Sh->OutOfMemory(this); }

	//----------------------------------------------------------------------------------------
	/// Calculates the foreground or background color and alpha at (@formatParam{x},@formatParam{y}).
	/// @param[in] foreground					@formatConstant{true} to calculate the foreground color, otherwise the background color.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] subx								The sub-pixel X position: @em 0 <= @formatParam{subx} <= @em 15
	/// @param[in] suby								The sub-pixel Y position: @em 0 <= @formatParam{suby} <= @em 15
	/// @param[out] color							Assigned the background/foreground color.
	/// @param[out] alpha							Assigned the background/foreground alpha.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CalcFgBg(Bool foreground, Int32 x, Int32 y, Int32 subx, Int32 suby, Vector* color, Float* alpha) const { return C4DOS.Sh->CalcFgBg(this, foreground, x, y, subx, suby, color, alpha); }

	//----------------------------------------------------------------------------------------
	/// Calculates the light falloff function (light intensity for a distance).
	/// @param[in] falloff						The light falloff type: @enumerateEnum{RaytraceLightFalloff}
	/// @param[in] inner							The inner falloff value.
	/// @param[in] outer							The outer falloff value.
	/// @param[in] dist								The distance for the intensity to be calculated at.
	/// @return												The light falloff.
	//----------------------------------------------------------------------------------------
	Float GetLightFalloff(Int32 falloff, Float inner, Float outer, Float dist) const { return C4DOS.Sh->GetLightFalloff(falloff, inner, outer, dist); }

	//----------------------------------------------------------------------------------------
	/// Tests for termination.
	/// If time intensive operations are performed (such as sending out several rays into the scene) call this routine to check for a renderer break.\n
	/// In normal situations @C4D breaks after a pixel has been calculated.
	/// @return												@trueIfOtherwiseFalse{the operation has been terminated}
	//----------------------------------------------------------------------------------------
	Bool TestBreak() { return C4DOS.Sh->TestBreak(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a videopost effect for the current render process by index.
	/// @param[in] nth								The index of the videopost effect.
	/// @return												The video post, or @formatConstant{nullptr} if the index is too large.
	//----------------------------------------------------------------------------------------
	BaseVideoPost* GetVideoPost(Int32 nth) const { return C4DOS.Sh->FindVideoPost(this, nth, true); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a video post effect for the current render process by ID.
	/// @param[in] id									The video post effect ID.
	/// @return												The video post, or @formatConstant{nullptr} if the index is too large.
	//----------------------------------------------------------------------------------------
	BaseVideoPost* FindVideoPost(Int32 id) const { return C4DOS.Sh->FindVideoPost(this, id, false); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the videopost fragments for a point.
	/// @note Not all fragments are stored during rendering, just the ones closest to the camera. So this cannot be used to for example draw inside a transparent object.
	/// @warning The array needs to be freed with DeleteMem() afterwards. The fragments must not be freed!
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] cnt								The X pixel count.
	/// @param[in] flags							The flags: @enumerateEnum{VPGETFRAGMENTS}
	/// @return												An array of pointers to the videopost fragments. @callerOwnsPointed{array} @theOwnsPointed{volume data, fragments}
	//----------------------------------------------------------------------------------------
	const VPFragment** GetFragments(Int32 x, Int32 y, Int32 cnt, VPGETFRAGMENTS flags) const { return C4DOS.Sh->VPGetFragments(this, x, y, cnt, flags); }

	//----------------------------------------------------------------------------------------
	/// Adds a number of lens glows to the image.\n
	/// In earlier versions the SampleLensFX() call was done automatically. Now this has to be called manually at the end to provide @C4D with the information where to sample.
	/// @param[in] lgs								An array of @formatParam{lgs_cnt} lens glow structs to draw. @callerOwnsPointed{array}
	/// @param[in] lgs_pos						An array of @formatParam{lgs_cnt} vectors with the corresponding positions of each lens glow in @formatParam{lgs}. @callerOwnsPointed{array}
	/// @param[in] lgs_cnt						The number of elements in the @formatParam{lgs} and @formatParam{lgs_pos} arrays.
	/// @param[in] intensity					The intensity of the lens glows.
	/// @param[in] linear_workflow		@trueIfOtherwiseFalse{linear workflow is used}
	/// @return												@trueIfOtherwiseFalse{the lens glow was added}
	//----------------------------------------------------------------------------------------
	Bool AddLensGlow(const LensGlowStruct* lgs, Vector* lgs_pos, Int32 lgs_cnt, Float intensity, Bool linear_workflow) const { return C4DOS.Sh->AddLensGlow(this, lgs, lgs_pos, lgs_cnt, intensity, linear_workflow); }

	//----------------------------------------------------------------------------------------
	/// Samples all lens effects previously created by calling AddLensGlow().
	/// @param[in] rgba								The image buffer. @callerOwnsPointed{buffer}
	/// @param[in] fx									An FX buffer for the new post effect multipass feature, or @formatConstant{nullptr}. @callerOwnsPointed{buffer}
	/// @param[in] bt									The current thread, or @formatConstant{nullptr} for the main @C4D thread.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SampleLensFX(const VPBuffer* rgba, const VPBuffer* fx, BaseThread* bt) const { return C4DOS.Sh->SampleLensFX(this, rgba, fx, bt); }

	//----------------------------------------------------------------------------------------
	/// Translates a current RayObject number to the one used in the last frame's rendering or vice versa.\n
	/// For instance if object @em 5 was object @em 10 in the last frame. Then @c TranslateObjIndex(5, false) = @em 10 and @c TranslateObjIndex(10, true) = @em 5.
	/// @note If plugin generator objects are involved it is necessary that they support the BaseObject::SetUniqueIP() feature.
	/// @param[in] index							The object index to convert.
	/// @param[in] old_to_new					If @formatConstant{true} then @formatParam{index} is an index from the last frame and the return value is an index in the current frame. Otherwise it is the other way around.
	/// @return												The converted object index, or @ref NOTOK if the object does not exist anymore (or did not exist before).
	//----------------------------------------------------------------------------------------
	Int32 TranslateObjIndex(Int32 index, Bool old_to_new) const { return C4DOS.Sh->TranslateObjIndex(this, index, old_to_new); }

	//----------------------------------------------------------------------------------------
	/// For a given RayObject @formatParam{op} and a local polygon ID @formatParam{local_index} retrieves the array of points from the last frame.\n
	/// @note To enable this functionality @ref VIDEOPOSTINFO::REQUEST_MOTIONGEOMETRY must be set in the video post.\n
	///				This function only makes sense to activate in a videopost plugin, as it goes beyond a single frame.
	/// @param[in] op									A ray object from the current frame. @callerOwnsPointed{object}
	/// @param[in] local_index				A local polygon ID from the current frame.
	/// @param[in,out] previous_points	Should point to an array of @em 4 Vector elements. @callerOwnsPointed{array}\n
	/// 															Assigned the points of the specified polygon from the last frame, if it existed.
	/// 															For a triangle only the @em 3 first fields of the array are filled.
	/// @return												@trueOtherwiseFalse{the data was available and stored in @formatParam{previous_points}}
	//----------------------------------------------------------------------------------------
	Bool TranslatePolygon(const RayObject* op, Int32 local_index, Vector* previous_points) const { return C4DOS.Sh->TranslatePolygon(this, op, local_index, previous_points); }

	//----------------------------------------------------------------------------------------
	/// Works like TraceGeometry(), but calculates the color for a given ray and evaluates all shaders for the intersection point.\n
	/// @note To avoid self-intersection, pass the current hit as @formatParam{last_hit}. To include all polygons, set @formatParam{last_hit} to RayHitID().
	/// @warning Always use a limit for the recursion (typically a value from @em 6 to @em 20) to avoid the danger of a stack overflow.
	/// @param[in] ray								The ray to find the intersection for. @callerOwnsPointed{ray}
	/// @param[in] maxdist						The maximum distance to check for intersections.
	/// @param[in] last_hit						The last intersection, or RayHitID() to include all polygons.
	/// @param[out] si								The surface intersection structure to take the calculated hit data. @callerOwnsPointed{surface intersection}
	/// @return												The color.\n
	/// 															A color can be returned even if there was no intersection (@c si.gid==0); in this case the ray intersected the sky.
	//----------------------------------------------------------------------------------------
	Vector TraceColor(Ray* ray, Float maxdist, const RayHitID& last_hit, SurfaceIntersection* si) { return C4DOS.Sh->TraceColor(this, ray, maxdist, last_hit, si); }

	//----------------------------------------------------------------------------------------
	/// Works like TraceColor(), but always samples the full color including all effects.
	/// @note To avoid self-intersection, pass the current hit as @formatParam{last_hit}. To include all polygons, set @formatParam{last_hit} to RayHitID().
	/// @warning A shader must not call this function if @ref RAYBIT::GI is set in @formatParam{raybits}.
	/// @param[in] ray								The ray to find the intersection for. @callerOwnsPointed{ray}
	/// @param[in] maxdist						The maximum distance to check for intersections.
	/// @param[in] raydepth						The ray depth.
	/// @param[in] raybits						The ray flags: @enumerateEnum{RAYBIT}
	/// @param[in] last_hit						The last intersection. Pass RayHitID() to include all polygons.
	/// @param[in] oldray							Should be set to @formatConstant{nullptr}.
	/// @param[out] si								The surface intersection structure to take the calculated hit data. @callerOwnsPointed{surface intersection}
	/// @return												The color.
	//----------------------------------------------------------------------------------------
	Vector TraceColorDirect(Ray* ray, Float maxdist, Int32 raydepth, RAYBIT raybits, const RayHitID& last_hit, Vector64* oldray, SurfaceIntersection* si) { return C4DOS.Sh->TraceColorDirect(this, ray, maxdist, raydepth, raybits, last_hit, oldray, si); }

	//----------------------------------------------------------------------------------------
	/// Calculates an intersection for @formatParam{ray}.
	/// @note To avoid self-intersection, pass the current hit as @formatParam{last_hit}. To include all polygons, set @formatParam{last_hit} to RayHitID().
	/// @param[in] ray								The ray to find the intersection for. @callerOwnsPointed{ray}
	/// @param[in] maxdist						The maximum distance to check for intersections.
	/// @param[in] last_hit						The last intersection. Pass RayHitID() to include all polygons.
	/// @param[out] si								The surface intersection structure to take the calculated hit data. @callerOwnsPointed{surface intersection}
	/// @return												@trueIfOtherwiseFalse{an intersection was found}
	//----------------------------------------------------------------------------------------
	Bool TraceGeometry(const Ray* ray, Float maxdist, const RayHitID& last_hit, SurfaceIntersection* si) const { return C4DOS.Sh->TraceGeometry(this, ray, maxdist, last_hit, si); }

	//----------------------------------------------------------------------------------------
	/// Calculates an intersection for ray at a certain ray depth.
	/// @note To avoid self-intersection, pass the current hit as @formatParam{last_hit}. To include all polygons, set @formatParam{last_hit} to RayHitID().
	/// @param[in] ray								The ray to find the intersection for. @callerOwnsPointed{ray}
	/// @param[in] maxdist						The maximum distance to check for intersections.
	/// @param[in] last_hit						The last intersection. Pass RayHitID() to include all polygons.
	/// @param[in] raydepth						The ray depth.
	/// @param[in] raybits						The rays flags: @enumerateEnum{RAYBIT}
	/// @param[in] oldray							Should be set to @formatConstant{nullptr}.
	/// @param[out] si								The surface intersection structure to take the calculated hit data. @callerOwnsPointed{surface intersection}
	/// @return												@trueIfOtherwiseFalse{an intersection was found}
	//----------------------------------------------------------------------------------------
	Bool TraceGeometryEnhanced(const Ray* ray, Float maxdist, const RayHitID& last_hit, Int32 raydepth, RAYBIT raybits, Vector64* oldray, SurfaceIntersection* si) const { return C4DOS.Sh->TraceGeometryEnhanced(this, ray, maxdist, last_hit, raydepth, raybits, oldray, si); }

	//----------------------------------------------------------------------------------------
	/// Retrieves information for a point on a surface.
	/// @param[out] cd								The retrieved surface information. @callerOwnsPointed{surface information}
	/// @param[in] calc_illum					@formatConstant{true} if the point shall be shaded (e.g. the sky is not shaded so is @formatConstant{false}).
	/// @param[in] calc_shadow				@formatConstant{true} if a shadow shall be calculated.
	/// @param[in] calc_refl					@formatConstant{true} if a reflection shall be calculated.
	/// @param[in] calc_trans					@formatConstant{true} if a transparency shall be calculated.
	/// @param[in] ray								The ray. @callerOwnsPointed{ray}
	/// @param[in] si									The surface intersection data.
	//----------------------------------------------------------------------------------------
	void GetSurfaceData(SurfaceData* cd, Bool calc_illum, Bool calc_shadow, Bool calc_refl, Bool calc_trans, Ray* ray, const SurfaceIntersection& si) { C4DOS.Sh->GetSurfaceData(this, cd, calc_illum, calc_shadow, calc_refl, calc_trans, ray, si); }

	//----------------------------------------------------------------------------------------
	/// Calculates the subpolygon displacement for a polygon @formatParam{local_id} of object @formatParam{op}.\n
	/// SPD has to be enabled for the object. The indices @formatParam{uu} and @formatParam{vv} are >=@em 0 and @formatParam{uu} + @formatParam{vv} <= @formatParam{op}->@link RayObject::spd_displacement spd_displacement@endlink.\n
	/// See CalcDisplacementNormals() for an example.
	/// @note @C4D automatically converts quads to triangles only if an objects has SPD enabled.
	/// @param[in] op									The ray object. @callerOwnsPointed{object}
	/// @param[in] local_id						The local polygon ID.
	/// @param[in] uu									The R coordinate.
	/// @param[in] vv									The S coordinate.
	/// @return												The displacement vector.
	//----------------------------------------------------------------------------------------
	Vector CentralDisplacePointUV(const RayObject* op, Int32 local_id, Int32 uu, Int32 vv) const { return C4DOS.Sh->CentralDisplacePointUV(this, op, local_id, uu, vv); }

	//----------------------------------------------------------------------------------------
	/// Calculates the subpolygon displacement of a point @formatParam{uv} in polygon @formatParam{local_id} of object @formatParam{op}.\n
	/// SPD has to be enabled for the object. The @formatParam{uv} point is expected to be within the triangle @formatParam{local_id}.
	/// The parameters @formatParam{l1} and @formatParam{l2} are expected to be the triangular barycentric coordinates of point @formatParam{uv}
	/// within a the triangle. If @formatParam{local_id} corresponds to a triangle within a quad, @formatParam{bFirst} indicates which of the
	/// sub triangles @formatParam{local_id} is.
	///
	/// @note @C4D automatically converts quads to triangles only if an objects has SPD enabled.
	/// @since R18
	///
	/// @param[in] op									The ray object. @callerOwnsPointed{object}
	/// @param[in] local_id						The abc or acd triangle id of a quad polygon.
	/// @param[in] bFirst							Whether local_id corresponds to the abc or acd triangle of the quad polygon.
	/// @param[in] l1									First barycentric coordinate.
	/// @param[in] l2									Second barycentric coordinate.
	/// @param[in] uv									UV coordinates of the point to displace.
	/// @param[in] uvw								UVW polygon enclosing the 'uv' point.
	/// @return												The displacement vector.
	//----------------------------------------------------------------------------------------
	Vector CentralDisplacePointFromUVPoint(const RayObject *op, Int32 local_id, Bool bFirst, Float l1, Float l2, const Vector& uv, const UVWStruct& uvw) const { return C4DOS.Sh->CentralDisplacePointFromUVPoint(this, op, local_id, bFirst, l1, l2, uv, uvw); }

	//----------------------------------------------------------------------------------------
	/// Calculates the normal at a point on polygon @formatParam{polynum} of object @formatParam{op}.\n
	/// SPD has to be enabled for the object. The indices @formatParam{a}/@formatParam{b}/@formatParam{c} are the corner points of the subpolygon and @formatParam{u0}/@formatParam{v0}/@formatParam{u1}/@formatParam{v1}/@formatParam{u2}/@formatParam{v2} are the r/s coordinates for it.\n
	/// These are passed here since one usually has to calculate them before, so for speed reasons they do not have to be calculated again.\n
	/// @b Example:
	/// @code
	/// Int32 num = lSubID & ~(1<<31), u0, u1, u2, v0, v1, v2;
	///
	/// u0 = u1 = u2 = num / m_pRayObject->spd_displacement;
	/// v0 = v1 = v2 = num % m_pRayObject->spd_displacement;
	/// if (lSubID & (1<<31))
	/// 	{ u1--; v2--; }
	/// else
	/// 	{ u1++; v2++; }
	///
	/// tri0 = m_pVolumeData->CentralDisplacePointUV(m_pRayObject, lLocalID, u0, v0);
	/// tri1 = m_pVolumeData->CentralDisplacePointUV(m_pRayObject, lLocalID, u1, v1);
	/// tri2 = m_pVolumeData->CentralDisplacePointUV(m_pRayObject, lLocalID, u2, v2);
	///
	/// n = m_pVolumeData->CalcDisplacementNormals(rParU, rParV, u0, v0, u1, v1, u2, v2, tri0, tri1, tri2, m_pRayObject, lLocalID));
	/// @endcode
	/// The sub-ID and par_u/par_v e.g. are retrieved with VolumeData::TraceGeometry().
	/// @param[in] par_u							The U parameter.
	/// @param[in] par_v							The V parameter.
	/// @param[in] u0									The R coordinate for @formatParam{a}.
	/// @param[in] v0									The S coordinate for @formatParam{a}.
	/// @param[in] u1									The R coordinate for @formatParam{b}.
	/// @param[in] v1									The S coordinate for @formatParam{b}.
	/// @param[in] u2									The R coordinate for @formatParam{c}.
	/// @param[in] v2									The S coordinate for @formatParam{c}.
	/// @param[in] a									The first corner point of the sub-polygon.
	/// @param[in] b									The second corner point of the sub-polygon.
	/// @param[in] c									The third corner point of the sub-polygon.
	/// @param[in] op									The ray object. @callerOwnsPointed{object}
	/// @param[in] polynum						The polygon index.
	/// @return												The displacement normal.
	//----------------------------------------------------------------------------------------
	Vector CalcDisplacementNormals(Float par_u, Float par_v, Int32 u0, Int32 v0, Int32 u1, Int32 v1, Int32 u2, Int32 v2, const Vector& a, const Vector& b, const Vector& c, const RayObject* op, Int32 polynum) const { return C4DOS.Sh->CalcDisplacementNormals(this, par_u, par_v, u0, v0, u1, v1, u2, v2, a, b, c, op, polynum); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Vector CentralDisplaceUVGetNormal(const RayObject* op, Int32 local_id, Int32 uu, Int32 vv) const { return C4DOS.Sh->CentralDisplaceUVGetNormal(this, op, local_id, uu, vv); }

	//----------------------------------------------------------------------------------------
	/// Computes the surface normal at the world point corresponding to the UV point at
	/// @formatParam{uv}.
	/// Takes into account whether surface subdivision is active and if true, whether surface
	/// rounding is applied.
	/// @since R18
	///
	/// @param[in] op									RayObject containing the UV point and polygon in question.
	/// @param[in] local_id						Id of the triangle containing the point @formatParam{uv}.
	/// @param[in] bFirst							If @formatParam{local_id} is within a quad, whether @formatParam{local_id}
	/// 															is the 'abc' or 'acd' triangle.
	/// @param[in] par_u							'u' barycentric coordinate of @formatParam{uv} within the triangle.
	/// @param[in] par_v							'v' barycentric coordinate of @formatParam{uv} within the triangle.
	/// @param[in] uv									UV point to evaluate.
	/// @param[in] uvw								UVW polygon enclosing the 'uv' point.
	/// @return												The surface normal at the world point corresponding to the
	/// 															UV point at @formatParam{uv}.
	//----------------------------------------------------------------------------------------
	Vector CentralDisplaceGetSurfaceNormalFromUVPoint(const RayObject *op, Int32 local_id, Bool bFirst, Float par_u, Float par_v, const Vector& uv, const UVWStruct& uvw) const { return C4DOS.Sh->CentralDisplaceGetSurfaceNormalFromUVPoint(this, op, local_id, bFirst, par_u, par_v, uv, uvw); }

	//----------------------------------------------------------------------------------------
	/// Computes the shading normal at the world point corresponding to the UV point at @formatParam{uv}.
	/// Takes into account whether surface subdivision is active and if true, whether surface rounding is applied.
	/// @since R18
	///
	/// @param[in] op									RayObject containing the UV point and polygon in question.
	/// @param[in] local_id						Id of the triangle containing the point @formatParam{uv}.
	/// @param[in] bFirst							If @formatParam{local_id} is within a quad, whether @formatParam{local_id} is the
	/// 															'abc' or 'acd' triangle.
	/// @param[in] par_u							'u' barycentric coordinate of @formatParam{uv}' within the triangle.
	/// @param[in] par_v							'v' barycentric coordinate of @formatParam{uv} within the triangle.
	/// @param[in] uv									Point to evaluate.
	/// @param[in] uvw								UVW polygon enclosing the 'uv' point.
	/// @return												The shading normal at the world point corresponding to the
	/// 															UV point at @formatParam{uv}.
	//----------------------------------------------------------------------------------------
	Vector CentralDisplaceGetShadingNormalFromUVPoint(const RayObject *op, Int32 local_id, Bool bFirst, Float par_u, Float par_v, const Vector& uv, const UVWStruct& uvw) const { return C4DOS.Sh->CentralDisplaceGetShadingNormalFromUVPoint(this, op, local_id, bFirst, par_u, par_v, uv, uvw); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool CentralDisplacePointUVGetBarycentric(const RayObject *op, Int32& local_id, Int32& uu, Int32& vv, RayPolyWeight& bary, Bool& displaceQuad) const { return C4DOS.Sh->CentralDisplacePointUVGetBarycentric(this, op, local_id, uu, vv, bary, displaceQuad); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool GetDisplaceInfo(const RayObject* op, DisplaceInfo& info) const { return C4DOS.Sh->GetDisplaceInfo(this, op, info); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Int32 GetDisplaceNeighbor(const RayObject* op, Int32 local_id, Int32 side) const { return C4DOS.Sh->GetDisplaceNeighbor(this, op, local_id, side); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void CorrectLocalID(const RayObject* op, Int32& local_id) const { C4DOS.Sh->CorrectLocalID(this, op, local_id); }

	//----------------------------------------------------------------------------------------
	/// Calculates the back transform point.
	/// @note Every time the texture matrix multiplies the back point this method should be used:
	///				Call CalcBackTransformPoint():
	/// @code
	/// p = cd->vd->CalcBackTransformPoint();
	/// @endcode
	/// Instead of writing:
	/// @code
	/// p = cd->vd->tex->im * cd->vd->back_p;
	/// @endcode
	/// @return												The back transform point.
	//----------------------------------------------------------------------------------------
	Vector CalcBackTransformPoint() const { return C4DOS.Sh->CalcBackTransformPoint(this); }

	//----------------------------------------------------------------------------------------
	/// Calculates the inverse matrix of the object when in motion blur.
	/// @since R16
	/// @param[in] op									The object. @callerOwnsPointed{object}
	/// @return												The inverse matrix of the object for motion blur.
	//----------------------------------------------------------------------------------------
	Matrix64 CalcMotionObjectMatrixInv(const RayObject *op) const { return C4DOS.Sh->CalcMotionObjectMatrixInv(this, op); }

	//----------------------------------------------------------------------------------------
	/// Skips the render process.
	/// @note Useful for custom renderers.
	//----------------------------------------------------------------------------------------
	void SkipRenderProcess() { C4DOS.Sh->SkipRenderProcess(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the current Render* instance.
	/// @return												The render instance.
	//----------------------------------------------------------------------------------------
	const Render* GetRenderInstance() const { return C4DOS.Sh->GetRenderInstance(this); }

	//----------------------------------------------------------------------------------------
	/// Calculates the DU/DV components for a texture and a given point/normal.\n
	/// Only necessary for channel shaders that normally cannot access this information.\n
	/// @note Traditionally we would estimate the DU/DV for UV mapping from surrounding points.\n
	///				But it can be inaccurate at the edges for smooth surfaces. Just like we precompute phong normals to compute smooth normals, we added an option (usetangents) to use UV tangents to compute correct DU/DV at any point.\n
	///				It is a more accurate method that avoid many of the previous problems.
	/// @param[in] tex								The texture to initialize. @callerOwnsPointed{texture data}
	/// @param[in] p									The surface point.
	/// @param[in] phongn							The shading normal.
	/// @param[in] orign							The original normal.
	/// @param[in] hit								The global RayHitID to get the UV coordinate in.
	/// @param[in] forceuvw						@formatConstant{true} to force UVW calculation.
	/// @param[out] ddu								Assigned the calculated DU component.
	/// @param[out] ddv								Assigned the calculated DV component.
	/// @param[in] usetangents				@formatConstant{true} to use UV tangents to compute DU/DV components.
	/// @param[in] weight							Optional weight for the polygon.
	//----------------------------------------------------------------------------------------
	void GetDUDV(const TexData* tex, const Vector64& p, const Vector64& phongn, const Vector64& orign, const RayHitID& hit, Bool forceuvw, Vector* ddu, Vector* ddv, Bool usetangents, const RayPolyWeight* weight) const { C4DOS.Sh->GetDUDV(this, tex, p, phongn, orign, hit, forceuvw, ddu, ddv, usetangents, weight); }

	//----------------------------------------------------------------------------------------
	/// Calculates the DU/DV components for a texture and a given point/normal.  Takes into
	/// account geometry rounding.  \n
	/// @since R18
	/// @param[in] op									Ray object on which the tangents are being evaluated.
	/// @param[in] tex								The texture to initialize. @callerOwnsPointed{texture data}
	/// @param[in] par_u							'u' triangle barycentric coordinate for uv point
	/// @param[in] par_v							'v' triangle barycentric coordinate for uv point
	/// @param[in] uv									The UV point for which to evaluate the tangents.
	/// @param[in] p									The surface point.
	/// @param[in] phongn							The shading normal. See CentralDisplaceGetShadingNormalFromUVPoint
	/// @param[in] orign							The surface normal. See CentralDisplaceGetSurfaceNormalFromUVPoint
	/// @param[in] uvw								UVW polygon enclosing the 'uv' point.
	/// @param[in] hit								The RayHitID containing the triangle info for the 'uv' point.
	/// @param[in] forceuvw						@formatConstant{true} to force UVW calculation.
	/// @param[out] ddu								The calculated DU tangent vector.
	/// @param[out] ddv								The calculated DV co-tangent vector.
	/// @param[in] usetangents				@formatConstant{true} to use UV tangents to compute DU/DV components.
	//----------------------------------------------------------------------------------------
	void GetDUDVFromUVPoint(const RayObject* op, const TexData* tex, Float par_u, Float par_v, const Vector64& uv, const Vector64& p, const Vector64& phongn, const Vector64& orign, const UVWStruct& uvw, RayHitID& hit, Bool forceuvw, Vector* ddu, Vector* ddv, Bool usetangents) { C4DOS.Sh->GetDUDVFromUVPoint(this, op, tex, par_u, par_v, uv, p, phongn, orign, uvw, hit, forceuvw, ddu, ddv, usetangents); }

	//----------------------------------------------------------------------------------------
	/// Initializes the surface point properties in the texture data @formatParam{td}.
	/// @param[in] td									The texture data to initialize. @callerOwnsPointed{texture data}
	//----------------------------------------------------------------------------------------
	void InitSurfacePointProperties(TexData* td) { C4DOS.Sh->InitSurfacePointProperties(this, td); }

	//----------------------------------------------------------------------------------------
	/// Attaches camera data to the VolumeData structure that is not available otherwise (like camera information, renderdata and screen pixel position).\n
	/// Enables the following render functions to work: SetXY(), GetXY(), ProjectPoint() (frontal projection), GetRay(), ScreenToCamera(), CameraToScreen(), GetParameter(), GetRayCamera().\n
	/// To delete it either free the VolumeData or call AttachVolumeData(nullptr, empty_container).\n
	/// Here is an example of how to use this method:
	/// @code
	/// VolumeData *vd = VolumeData::Alloc();
	/// BaseDraw *bd = doc->GetRenderBaseDraw();
	/// BaseObject *camera = bd?bd->GetSceneCamera(doc):nullptr;
	/// RenderData *rdata = doc->GetActiveRenderData();
	/// if (vd && camera && rdata && vd->AttachVolumeDataFake(camera,*rdata->GetDataInstance()))
	/// {
	/// 	Int32 x,y;
	/// 	Ray ray;
	/// 	for (y=0; y<10; y++)
	/// 	{
	/// 		for (x=0; x<rdata->GetDataInstance()->GetInt32(RDATA_XRES); x++)
	/// 		{
	/// 			vd->GetRay(x,y,&ray);
	/// 			GePrint(String::FloatToString(ray.v.x)+String(" ")+String::FloatToString(ray.v.y)+String(" ")+String::FloatToString(ray.v.z));
	/// 		}
	/// 	}
	/// }
	/// VolumeData::Free(vd);
	/// @endcode
	/// @param[in] camera							The camera to attach. @callerOwnsPointed{camera}
	/// @param[in] renderdata					The render data container.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AttachVolumeDataFake(BaseObject* camera, const BaseContainer& renderdata) { return C4DOS.Sh->AttachVolumeDataFake(this, camera, renderdata, nullptr); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool SaveShaderStack(RayShaderStackElement*& stack, Int32& stack_cnt) { return C4DOS.Sh->SaveShaderStack(this, stack, stack_cnt); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool RestoreShaderStack(RayShaderStackElement* stack, Int32 stack_cnt) { return C4DOS.Sh->RestoreShaderStack(this, stack, stack_cnt); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the @formatParam{index}-th sky object (index ranging from @em 0 to GetRaySkyCount()-@em 1). The object is of type @ref O_SKY.
	/// @param[in] index							The sky object index.
	/// @return												The sky object, or @formatConstant{nullptr}. @theOwnsPointed{volume data,sky object}
	//----------------------------------------------------------------------------------------
	const RayObject* GetRaySky(Int32 index) const { return C4DOS.Sh->GetSky(this, index); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of sky objects.
	/// @return												The number of sky objects.
	//----------------------------------------------------------------------------------------
	Int32 GetRaySkyCount() const { return C4DOS.Sh->GetSkyCount(this); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	RaySampler* GetRaySampler(void* guid, Int32 depth) { return C4DOS.Sh->GetSampler(this, guid, depth); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Float GetRayWeight() const { return C4DOS.Sh->GetRayWeight(this); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Float CalcAmbientOcclusion(SurfaceIntersection* si, RaySampler* sampler, Float minlength, Float maxlength, Float index, Bool self, Bool trans, Float weight, Bool reverse) { return C4DOS.Sh->CalcAmbientOcclusion(this, si, sampler, minlength, maxlength, index, self, trans, weight, reverse); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Vector CalcSubsurfaceScattering(Vector scattering, Vector absorption, Vector diffuse, Float ior) { return C4DOS.Sh->CalcSubsurfaceScattering(this, scattering, absorption, diffuse, ior); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of stereoscopic streams that are rendered.
	/// @return												The number of stereoscopic streams.
	//----------------------------------------------------------------------------------------
	Int32 GetStreamCount() const { return C4DOS.Sh->GetStreamCount(this); }

	//----------------------------------------------------------------------------------------
	/// The same as GetRay() but just for stereoscopic streams.
	/// @param[in] stream							The stereoscopic stream: @em 0 <= @formatParam{stream} < GetStreamCount()
	/// @param[in] x									The X position for the view ray in screen space coordinates.
	/// @param[in] y									The Y position for the view ray in screen space coordinates.
	/// @param[in] ray								Assigned the generated view ray. @callerOwnsPointed{ray}
	//----------------------------------------------------------------------------------------
	void GetStreamRay(Int32 stream, Float x, Float y, Ray* ray) const { C4DOS.Sh->GetStreamRay(this, stream, x, y, ray); }

	//----------------------------------------------------------------------------------------
	/// Entry point into @C4D GI calculation. Performs the full @em 3 phase MIS sampling for indirect illumination.\n
	/// CalcIndirectIllumination() can also be used to compute AO. It is handy as it computes also gradients allowing very fast AO with interpolation.
	/// @param[in] hs									Controls the GI and if gradient information needs to be computed or not for the caches.
	/// @param[in] weight							The weight.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CalcIndirectIllumination(RayHemisphere* hs, Float weight) { return C4DOS.Sh->CalcIndirectIllumination(this, hs, weight); }

	//----------------------------------------------------------------------------------------
	/// Calculates the PDF (Probability Distribution) for the given intersection and 2 ray directions.
	/// @param[in] point							The point.
	/// @param[in] normal							The normal.
	/// @param[in] ray_in							The ray in direction.
	/// @param[in] ray_out						The ray out direction.
	/// @param[out] pdf_qmc						Assigned the PDF QMC.
	/// @param[out] pdf_area					Assigned the PDF area.
	/// @param[out] pdf_portal				Assigned the PDF portal.
	/// @param[out] pdf_sky						Assigned the PDF sky.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CalcIndirectPDF(const Vector& point, const Vector& normal, const Vector& ray_in, const Vector& ray_out, Float& pdf_qmc, Float& pdf_area, Float& pdf_portal, Float& pdf_sky) { return C4DOS.Sh->CalcIndirectPDF(this, point, normal, ray_in, ray_out, pdf_qmc, pdf_area, pdf_portal, pdf_sky); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool CalcIndirectPath(VolumeData* sd, const Vector& dir, void* source, void* target) { return C4DOS.Sh->CalcIndirectPath(this, dir, source, target); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	RayRadianceObject* CreateRadianceMaps() { return C4DOS.Sh->CreateRadianceMaps(this); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	RayRadianceObject* GetRadianceMaps() { return C4DOS.Sh->GetRadianceMaps(this); }

	//----------------------------------------------------------------------------------------
	/// Calculates the values for radiance maps.
	/// @param[in] ray								The ray. @callerOwnsPointed{ray}
	/// @param[in] si									The surface intersection structure. @callerOwnsPointed{surface intersection}
	/// @return												The radiance value.
	//----------------------------------------------------------------------------------------
	Vector CalcRadianceValue(Ray* ray, const SurfaceIntersection& si) { return C4DOS.Sh->CalcRadianceValue(this, ray, si); }

	//----------------------------------------------------------------------------------------
	/// Computes the radiance for the given object and polygon index. Used by the Radiosity Maps when computing the color for each "texel" on the poly.
	/// @param[in] obj								The radiance object.
	/// @param[in] si									The surface intersection structure. @callerOwnsPointed{surface intersection}
	/// @param[in] poly								The polygon index.
	/// @param[in] u									The U texel position for the radiosity map.
	/// @param[in] v									The V texel position for the radiosity map.
	/// @param[in] back								Set to @formatConstant{true} to computes the illumination for the back side.
	/// @return												The radiance value.
	//----------------------------------------------------------------------------------------
	Vector CalcRadiancePoly(RayRadianceObject* obj, SurfaceIntersection* si, Int32 poly, Int32 u, Int32 v, Bool back) { return C4DOS.Sh->CalcRadiancePoly(this, obj, si, poly, u, v, back); }

	//----------------------------------------------------------------------------------------
	/// Checks if the Physical %Render is being used to render the volume data.
	/// @return												@trueIfOtherwiseFalse{the Physical %Render is used to render}
	//----------------------------------------------------------------------------------------
	Bool IsPhysicalRender() const { return C4DOS.Sh->IsPhysicalRender(this); }

	//----------------------------------------------------------------------------------------
	/// Used in Physical %Render (always returns @em 1.0 in Standard).
	/// @note This method is handy if the plugin does any custom drawing into the buffer. e.g. it can be used in the GI/AO prepass to make sure the prepass intensity matches the render.
	/// @return												The relative intensity of the camera when exposure is used.
	//----------------------------------------------------------------------------------------
	Float GetPhysicalCameraIntensity() const { return C4DOS.Sh->GetPhysicalCameraIntensity(this); }

	//----------------------------------------------------------------------------------------
	/// Used in Physical %Render. Sets the time state inside the renderer.\n
	/// The value range is from @em 0.0 to @em 1.0, and corresponds to the frame exposure range as specified by the camera.
	/// @note This method is useful to customize the time when rays are traced before the rendering starts, for example in various prepass tasks to make sure Motion Blur is properly handled.
	/// @param[in] time								The time.
	//----------------------------------------------------------------------------------------
	void SetPhysicalRayTime(Float time) { return C4DOS.Sh->SetPhysicalRayTime(this, time); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the motion blur information for an object.
	/// @since R17.032
	/// @param[in] op									The object. @callerOwnsPointed{op}
	/// @return												The motion data.
	//----------------------------------------------------------------------------------------
	const RayMotionObject* GetMotionObject(RayObject *op) { return C4DOS.Sh->GetMotionObject(this, op); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the motion blur information for a light.
	/// @since R17.032
	/// @param[in] light							The light. @callerOwnsPointed{light}
	/// @return												The motion data.
	//----------------------------------------------------------------------------------------
	const RayMotionLight* GetMotionLight(RayLight *light) { return C4DOS.Sh->GetMotionLight(this, light); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the motion blur information for a camera.
	/// @since R17.032
	/// @param[in] stream							The camera stream.
	/// @return												The motion data.
	//----------------------------------------------------------------------------------------
	const RayMotionCamera* GetMotionCamera(Int32 stream) { return C4DOS.Sh->GetMotionCamera(this, stream); }

	//----------------------------------------------------------------------------------------
	/// Queries information about the currently rendered RayTile.
	/// @since R16.038
	/// @warning Not valid during Videopost execution, with the exception of @ref VIDEOPOSTCALL::TILE.
	/// @param[out] xMin							Assigned the upper left of the rendered tile.
	/// @param[out] yMin							Assigned the lower left of the rendered tile.
	/// @param[out] xMax							Assigned the upper right of the rendered tile.
	/// @param[out] yMax							Assigned the lower right of the rendered tile.
	/// @param[out] renderThreadIndex	Assigned the index of the render thread that invoked @ref VIDEOPOSTCALL::TILE and 'owns' the tile.\n
	/// 															Note that pixel calculation can be distributed on multiple render threads.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetTile(Int32& xMin, Int32& yMin, Int32& xMax, Int32& yMax, Int32& renderThreadIndex) const { return C4DOS.Sh->GetTile(this, xMin, yMin, xMax, yMax, renderThreadIndex); }
};

/// @addtogroup c4d_tools_allocfreerayobject Alloc/Free Ray Object
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Allocates a ray object. Destroy the allocated ray object with FreeRayObject().
/// @param[in] tex_cnt						The texture count.
/// @return												@allocReturn{ray object}
//----------------------------------------------------------------------------------------
RayObject* AllocRayObject(Int32 tex_cnt);

//----------------------------------------------------------------------------------------
/// Destructs ray objects allocated with AllocRayObject().
/// @param[in,out] op							@theToDestruct{ray object}
//----------------------------------------------------------------------------------------
void FreeRayObject(RayObject*& op);

/// @}

/// @addtogroup c4d_tools_raylight Ray Light
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Allocates a ray light for @formatParam{op}. Destroy the allocated ray light with FreeRayLight().
/// @param[in] doc								The document containing the object @formatParam{op}. @callerOwnsPointed{document}
/// @param[in] op									The object to allocate the ray light for. @callerOwnsPointed{object}
/// @return												@allocReturn{ray light}
//----------------------------------------------------------------------------------------
RayLight* AllocRayLight(BaseDocument* doc, BaseObject* op);

//----------------------------------------------------------------------------------------
/// Destructs ray lights allocated with AllocRayLight().
/// @param[in,out] lgt						@theToDestruct{ray light}
//----------------------------------------------------------------------------------------
void FreeRayLight(RayLight*& lgt);

//----------------------------------------------------------------------------------------
/// Calculates the illumination for a ray light.
/// @param[in] rl									The ray light to use for the calculation. @callerOwnsPointed{ray light}
/// @param[out] color							Assigned the calculated color.
/// @param[out] light_vector			Assigned the calculated light color.
/// @param[in] p									The point for the illumination.
/// @param[in] n									The normal for the illumination.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool IlluminateRayLight(RayLight* rl, Vector* color, Vector64* light_vector, const Vector64& p, const Vector64& n);

/// @}

//----------------------------------------------------------------------------------------
/// A rendering bitmap buffer. Represents internally the same class as MultipassBitmap, so a VPBuffer can be cast to a MultipassBitmap and vice versa.
//----------------------------------------------------------------------------------------
class VPBuffer
{
private:
	VPBuffer();
	~VPBuffer();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves information about the videopost buffer.
	/// @param[in] type								The information type to get: @enumerateEnum{VPGETINFO}
	/// @return												The information.
	//----------------------------------------------------------------------------------------
	Int32 GetInfo(VPGETINFO type) const;

	//----------------------------------------------------------------------------------------
	/// Gets a line from the videopost buffer.
	/// @param[in] x									The starting horizontal position.
	/// @param[in] y									The vertical position of the line.
	/// @param[in] cnt								The width of the line to get.
	/// @param[in] data								The buffer to fill with the data from the line. @callerOwnsPointed{buffer}
	/// @param[in] bitdepth						The bit depth to use to fill the @formatParam{data} buffer:
	/// 															- 8 (::UChar)
	/// 															- 16 (::UInt16)
	/// 															- 32 (::Float)
	/// @param[in] dithering					@formatConstant{true} if the line should be dithered.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetLine(Int32 x, Int32 y, Int32 cnt, void* data, Int32 bitdepth, Bool dithering) const;

	//----------------------------------------------------------------------------------------
	/// Sets a line in the videopost buffer.
	/// @param[in] x									The starting horizontal position.
	/// @param[in] y									The vertical position of the line.
	/// @param[in] cnt								The width of the line to set.
	/// @param[in] data								The buffer with the data to set the line. @callerOwnsPointed{buffer}
	/// @param[in] bitdepth						The bit depth of @formatParam{data} buffer:
	/// 															- 8 (::UChar)
	/// 															- 16 (::UInt16)
	/// 															- 32 (::Float)
	/// @param[in] dithering					@formatConstant{true} if the line should be dithered.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetLine(Int32 x, Int32 y, Int32 cnt, void* data, Int32 bitdepth, Bool dithering) const;

	//----------------------------------------------------------------------------------------
	/// Gets the width of the videopost buffer.
	/// @return												The width.
	//----------------------------------------------------------------------------------------
	Int32 GetBw() const { return C4DOS.Sh->VPGetInfo(this, VPGETINFO::XRESOLUTION); }

	//----------------------------------------------------------------------------------------
	/// Gets the height of the videopost buffer.
	/// @return												The height.
	//----------------------------------------------------------------------------------------
	Int32 GetBh() const { return C4DOS.Sh->VPGetInfo(this, VPGETINFO::YRESOLUTION); }

	//----------------------------------------------------------------------------------------
	/// Gets the bit depth of the videopost buffer.
	/// @return												The bit depth:
	/// 															- 8 (::UChar)
	/// 															- 16 (::UInt16)
	/// 															- 32 (::Float)
	//----------------------------------------------------------------------------------------
	Int32 GetBt() const { return C4DOS.Sh->VPGetInfo(this, VPGETINFO::BITDEPTH); }

	//----------------------------------------------------------------------------------------
	/// Gets the bytes per pixel for the videopost buffer.
	/// @return												The number of bytes per pixel.
	//----------------------------------------------------------------------------------------
	Int32 GetCpp() const { return C4DOS.Sh->VPGetInfo(this, VPGETINFO::CPP); }

	//----------------------------------------------------------------------------------------
	/// Determines whether the videopost buffer is visible.\n
/// @note Buffers that were requested by plugins can be existent, but invisible (not listed in the Picture Viewer %Multipass menu).
	/// @return												@trueIfOtherwiseFalse{the buffer is visible}
	//----------------------------------------------------------------------------------------
	Bool GetVisibleBit() const { return C4DOS.Sh->VPGetInfo(this, VPGETINFO::VISIBLE) != 0; }
};

struct VideoPostStruct : public BaseVideoPostStruct
{
private:
	VideoPostStruct();
	~VideoPostStruct();
};

class Render
{
private:
	Render();
	~Render();

public:
	//----------------------------------------------------------------------------------------
	/// Allocates a videopost buffer.
	/// @warning Must be called only within VideoPostData::AllocateBuffers()
	/// @param[in] id									The type of buffer: @enumerateEnum{VPBUFFER}
	/// @param[in] subid							The sub-ID for the buffer type, such as the @ref VPBUFFER_OBJECTBUFFER Group ID. (See Rendering in the @C4D manual.)
	/// @param[in] bitdepth						The bit depth:
	/// 															- 8 (::UChar)
	/// 															- 16 (::UInt16)
	/// 															- 32 (::Float)
	/// @param[in] visible						@formatConstant{true} if the buffer shall be visible to the user in the Picture Viewer.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AllocateBuffer(Int32 id, Int32 subid, Int32 bitdepth, Bool visible);

	//----------------------------------------------------------------------------------------
	/// Allocates a special effect buffer of type @formatParam{id}.\n
	/// For example, PyroCluster does the following:
	/// @code
	/// pfx_mulid = render->AllocateBufferFX(VPBUFFER_POSTEFFECT_MUL, GeLoadString(IDS_GLOW_NAME2), 8, true); // mul requested before normal buffer
	/// pfx_id = render->AllocateBufferFX(VPBUFFER_POSTEFFECT, GeLoadString(IDS_GLOW_NAME), 8, true);
	/// @endcode
	/// @warning Must be called only within VideoPostData::AllocateBuffers()
	/// @param[in] id									The type of effect buffer: @ref VPBUFFER_POSTEFFECT or @ref VPBUFFER_POSTEFFECT_MUL.
	/// @param[in] name								The buffer name.
	/// @param[in] bitdepth						The buffer bit depth.
	/// @param[in] visible						@formatConstant{true} if the buffer shall be visible to the user in the Picture Viewer.
	/// @return												The special effect buffer ID.\n
	/// 															The ID returned needs to be passed later on to Render::GetBuffer(), which can return @formatConstant{nullptr} either if the buffer could not be allocated or if the user did not add the Post-effect %Multipass.
	//----------------------------------------------------------------------------------------
	Int32 AllocateBufferFX(Int32 id, const maxon::String& name, Int32 bitdepth, Bool visible);

	//----------------------------------------------------------------------------------------
	/// Gets a videopost buffer.
	/// @param[in] id									The type of buffer: @enumerateEnum{VPBUFFER}
	/// @param[in] subid							The sub-ID for the buffer.\n
	/// 															Some buffers share the same ID (Object buffers for instance. Sub-IDs are used to discern between buffers then).
	/// @return												The videopost buffer. @cinemaOwnsPointed{videopost buffer}
	//----------------------------------------------------------------------------------------
	VPBuffer* GetBuffer(Int32 id, Int32 subid) const;

	//----------------------------------------------------------------------------------------
	/// Gets the render data. This is a container with the same values as used in the RenderData class.
	/// @note Some flags are only set in this container, for example when rendering using the "Render Only Active Object" button.
	/// @return												The render settings.
	//----------------------------------------------------------------------------------------
	BaseContainer GetRenderData() const;

	//----------------------------------------------------------------------------------------
	/// Gets the BaseDraw associated with this rendering.
	/// @return												The class or nullptr in case of an error.
	//----------------------------------------------------------------------------------------
	BaseDraw* GetBaseDraw() const;

	//----------------------------------------------------------------------------------------
	/// Sets the render data.
	/// @param[in] bc									The render settings.
	//----------------------------------------------------------------------------------------
	void SetRenderData(const BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Retrieves a VolumeData structure for every CPU processor. Needed when multiprocessing in a videopost plugin.\n
	/// @warning The returned volume data is only valid in @ref VIDEOPOSTCALL::INNER.
	/// @param[in] cpu								The CPU index.
	/// @return												The volume data for processor @formatParam{cpu}. @cinemaOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	VolumeData* GetInitialVolumeData(Int32 cpu) const;

	//----------------------------------------------------------------------------------------
	/// Sets render properties.
	/// @param[in] id									The property to set: @enumerateEnum{RENDERPROPERTY}
	/// @param[in] dat								The render property value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetRenderProperty(Int32 id, const GeData& dat);

	//----------------------------------------------------------------------------------------
	/// Converts a number of pixels from render color space to output color space or the other way around.
	/// @param[out] data							The pixel buffer. @callerOwnsPointed{buffer}
	/// @param[in] xcnt								The number of pixels.
	/// @param[in] components					The number of pixel components (@em 3 for RGB, @em 4 for RGBA, etc.)
	/// @param[in] inverse						@formatConstant{true} for conversion from render to output color space, or @formatConstant{false} to convert from output to render color space.
	//----------------------------------------------------------------------------------------
	void IccConvert(void* data, Int32 xcnt, Int32 components, Bool inverse);
};

//----------------------------------------------------------------------------------------
/// Calculates the include-/exclude situation for a given object @formatParam{op} and a @c light source (@c &light->lr is passed).
/// @param[in] lr									The light restriction to evaluate. @callerOwnsPointed{light restriction}
/// @param[in] op									The object to evaluate. @callerOwnsPointed{object}
/// @param[in,out] nodif					Must be initialized with @formatConstant{false} before the call. Assigned @formatConstant{true} if @formatParam{lr} specifies that @formatParam{op} should not receive any diffuse light.
/// @param[in,out] nospec					Must be initialized with @formatConstant{false} before the call. Assigned @formatConstant{true} if @formatParam{lr} specifies that @formatParam{op} should not receive any specular light.
//----------------------------------------------------------------------------------------
void CalcRestrictionInc(const ObjectRestriction* lr, const RayObject* op, Bool& nodif, Bool& nospec);

/// @addtogroup c4d_tools_bake Bake
/// @ingroup group_function
/// @{

/// @addtogroup BakeTexEnums
/// @ingroup group_containerid
/// @{
enum BakeTexEnums
{
	BAKE_TEX_USE_CAMERA_VECTOR											= 1006,			///< ::Bool Use camera vector.
	BAKE_TEX_USE_POLYSELECTION											= 1007,			///< ::Bool Use polygon selection.
	BAKE_TEX_AMBIENT_OCCLUSION											= 1009,			///< ::Bool Bake ambient occlusion.
	BAKE_TEX_NORMAL																	= 1010,			///< ::Bool Bake normal channel.
	BAKE_TEX_SURFACECOLOR														= 1011,			///< ::Bool Bake surface color.
	BAKE_TEX_COLOR																	= 1012,			///< ::Bool Bake color.
	BAKE_TEX_DIFFUSION															= 1013,			///< ::Bool Bake diffusion channel.
	BAKE_TEX_LUMINANCE															= 1014,			///< ::Bool Bake luminance.
	BAKE_TEX_ALPHA																	= 1015,			///< ::Bool Bake alpha channel.
	BAKE_TEX_ILLUMINATION														= 1016,			///< ::Bool Bake illumination.
	BAKE_TEX_SHADOWS																= 1017,			///< ::Bool Bake shadows.
	BAKE_TEX_BUMP																		= 1018,			///< ::Bool Bake bump.
	BAKE_TEX_TRANSPARENCY														= 1019,			///< ::Bool Bake transparency.
	BAKE_TEX_UVMAP																	= 1040,			///< ::Bool Bake UV map.
	BAKE_TEX_REFLECTION															= 1041,			///< ::Bool Bake reflection.
	BAKE_TEX_DISPLACEMENT														= 1042,			///< ::Bool Bake displacement.

	BAKE_TEX_WIDTH																	= 1020,			///< ::Int32 Width.
	BAKE_TEX_HEIGHT																	= 1021,			///< ::Int32 Height.
	BAKE_TEX_PIXELBORDER														= 1022,			///< ::Int32 Pixel border.
	BAKE_TEX_FILL_COLOR															= 1023,			///< ::Vector Fill color.
	BAKE_TEX_UV_LEFT																= 1024,			///< ::Float Left UV coordinate.
	BAKE_TEX_UV_RIGHT																= 1025,			///< ::Float Right UV coordinate.
	BAKE_TEX_UV_TOP																	= 1026,			///< ::Float Top UV coordinate.
	BAKE_TEX_UV_BOTTOM															= 1027,			///< ::Float Bottom UV coordinate.
	BAKE_TEX_SUPERSAMPLING													= 1030,			///< ::Int32 Supersampling.
	BAKE_TEX_USE_BUMP																= 1031,			///< ::Bool Use bump.
	BAKE_TEX_NO_GI																	= 1032,			///< ::Bool No GI.
	BAKE_TEX_CONTINUE_UV														= 1033,			///< ::Bool Continue UV.
	BAKE_TEX_USE_PHONG_TAG													= 1034,			///< ::Bool The pixel will be clamped to the current polygon if set to @formatConstant{true} and if the angle between polygons is bigger than their phong angle.\n
																															///< Only needed if @ref BAKE_TEX_CONTINUE_UV is set to @formatConstant{true}.
	BAKE_TEX_COLORPROFILE														= 1035,			///< ColorProfile Color profile of the baked texture.
	// 1400 to 1500 is reserved
	BAKE_TEX_SHOW_STATUS														= 2000,			///< ::Bool Show status.
	BAKE_TEX_PROGRESS_BITMAP												= 2001,			///< ::Bool Show the bitmap in a preview during baking.
	BAKE_TEX_GENERATE_UNDO													= 2002,			///< ::Bool Generate undo for UVW tags and Vertex tags created by the baker.
	BAKE_TEX_PREVIEW																= 2003,			///< ::Bool Bake texture preview.

	BAKE_TEX_COLOR_ILLUM														= 2100,			///< ::Bool Illumination in color.
	BAKE_TEX_COLOR_SHADOWS													= 2101,			///< ::Bool Shadows in color.
	BAKE_TEX_COLOR_LUMINANCE												= 2102,			///< ::Bool Luminance in color.
	BAKE_TEX_COLOR_DIFFUSION												= 2103,			///< ::Bool Diffusion in color.

	BAKE_TEX_LUMINANCE_DIFFUSION										= 2110,			///< ::Bool Diffusion in luminance.

	BAKE_TEX_ILLUMINATION_SHADOWS										= 2120,			///< ::Bool Shadows in luminance.

	BAKE_TEX_NORMAL_METHOD													= 2130,			///< ::Int32 Normal method:
	BAKE_TEX_NORMAL_METHOD_OBJECT										= 1,			///< Object.
	BAKE_TEX_NORMAL_METHOD_TANGENT									= 2,			///< %Tangent.
	BAKE_TEX_NORMAL_METHOD_WORLD										= 3,			///< World.
	BAKE_TEX_NORMAL_FLIP_X													= 2131,			///< ::Bool Flip X.
	BAKE_TEX_NORMAL_FLIP_Y													= 2132,			///< ::Bool Flip Y.
	BAKE_TEX_NORMAL_FLIP_Z													= 2133,			///< ::Bool Flip Z.
	BAKE_TEX_NORMAL_SWAP_YZ													= 2134,			///< ::Bool Swap Y/Z.
	BAKE_TEX_NORMAL_SOURCE													= 2135,			///< BaseLink Normal source.
	BAKE_TEX_NORMAL_USE_RAYCAST                     = 2136,     ///< Whether the normal map will be generated using ray casting. True when baking the normal map only. @since R18

	BAKE_TEX_SURFACE_ILLUMINATION										= 2140,			///< ::Bool Surface illumination.

	BAKE_TEX_AO_VERTEX_MAP													= 2150,			///< ::Bool Ambient occlusion in vertex map.
	BAKE_TEX_AO_SELFINTERSECTION										= 2151,			///< ::Bool Ambient occlusion self-intersection.
	BAKE_TEX_AO_VERTEXMAPS													= 2152,			///< @c void* Pointer to a BaseContainer that stores all new generated vertex maps.

	BAKE_TEX_DISPLACEMENT_SOURCE										= 2160,			///< BaseLink The high-res source object.
	BAKE_TEX_DISPLACEMENT_HEIGHT										= 2161,			///< @c void* A pointer to a Float that will receive the displacement height.
	BAKE_TEX_DISPLACEMENT_METHOD										= 2163,			///< ::Int32 Displacement method:
	BAKE_TEX_DISPLACEMENT_METHOD_OBJECT							= 0,			///< Object.
	BAKE_TEX_DISPLACEMENT_METHOD_WORLD							= 1,			///< World.
	BAKE_TEX_DISPLACEMENT_METHOD_TANGENT						= 2,			///< %Tangent.
	BAKE_TEX_DISPLACEMENT_METHOD_INTENSITY					= 3,			///< Intensity.
	BAKE_TEX_DISPLACEMENT_METHOD_CENTEREDINTENSITY	= 4,			///< Centered intensity.
	BAKE_TEX_DISPLACEMENT_METHOD_REDGREEN						= 5,			///< Red <-> Green.

	BAKE_TEX_DISPLACEMENT_SUBPOLY										= 2435,			///< ::Bool Displacement subpoly.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_SUBDIVISION				= 2436,			///< ::Int32 Displacement subpoly subdivision.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_ROUND							= 2437,			///< ::Bool Displacement subpoly round.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_ROUNDCONTOUR			= 2438,			///< ::Bool Displacement subpoly round contour.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_HQREMAPPING				= 2439,			///< ::Bool Displacement subpoly HQ remapping.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_MAPRESULT					= 2440,			///< ::Bool Displacement subpoly map result.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_KEEPEDGES					= 2441,			///< ::Bool Displacement subpoly keep edges.
	BAKE_TEX_DISPLACEMENT_SUBPOLY_DISTRIBUTION			= 2442,			///< ::Bool Displacement subpoly distribution.

	BAKE_TEX_RAYCAST_USE_MAX_DISTANCE									= 2443,   ///< ::Bool Use maximum ray casting distance. @since R18
	BAKE_TEX_RAYCAST_CUSTOM_MAX_DISTANCE							= 2444,   ///< ::Float Custom maximum ray casting distance. @since R18
	BAKE_TEX_RAYCAST_USE_AUTO_SPIKE_FILTER_THRESHOLD	=	2445,   ///< ::Bool Use automatic spike filter threshold. @since R18
	BAKE_TEX_RAYCAST_CUSTOM_SPIKE_FILTER_THRESHOLD		= 2446,		///< ::Float Custom spike filter threshold. @since R18

	BAKE_TEX_OPTIMAL_MAPPING												= 2200,			///< ::Int32 Optimal mapping:
	BAKE_TEX_OPTIMAL_MAPPING_OFF										= 0,			///< Off.
	BAKE_TEX_OPTIMAL_MAPPING_CUBIC									= 1,			///< Cubic.
	BAKE_TEX_OPTIMAL_MAPPING_ANGLE									= 2,			///< Angle.
	BAKE_TEX_OPTIMAL_MAPPING_RELAXCOUNT							= 2207,			///< ::Int32 Optimal mapping relax count.
	BAKE_TEX_OPTIMAL_MAPPING_PREVIEW								= 2201,			///< ::Int32 Optimal mapping preview.

	BAKE_TEX_NO_INIT_BITMAP													= 5000,			///< ::Bool Set to @formatConstant{true} if the MultipassBitmap is already initialized.
	BAKE_TEX_AUTO_SIZE															= 5001,			///< ::Bool Auto size.
	BAKE_TEX_AUTO_SIZE_MIN													= 5002,			///< ::Int32 Minimum auto size.
	BAKE_TEX_AUTO_SIZE_MAX													= 5003,			///< ::Int32 Maximum auto size.
	BAKE_TEX_AUTO_PIXEL_SIZE												= 5004,			///< ::Float Automatic pixel size.

	BAKE_TEX_STATUSBAR															= 5005,			///< String Status bar text.

	BAKE_TEX_DUMMY
};
/// @}

/// @addtogroup BAKE_STATE
/// @ingroup group_enumeration
/// @{
enum class BAKE_STATE
{
	NONE					= 0,					///< None.
	PREPARE				= 10000,			///< Prepare.
	GI_PREPASS		= 10001,			///< GI prepass.
	FILL_IMAGE		= 10002,			///< Fill image.
	COMPLETE			= 10003,			///< Complete.
	INITIALIZE		= 10004,			///< Initialize.

	RESIZENOTIFY = 19999				///< Resize notify. See BakeTextureResizeNotify.
} MAXON_ENUM_LIST(BAKE_STATE);
/// @}

struct BakeProgressInfo
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	BakeProgressInfo() { private_data = nullptr; state = BAKE_STATE::NONE; data = nullptr; timedelta = 0; r = 0.0; starttime = 0; version = 2; }

	Int32				version;					///< Bake version.
	void*				private_data;			///< @markPrivate
	BAKE_STATE	state;						///< Bake state: @enumerateEnum{BAKE_STATE}
	void*				data;							///< Only used in case of a @ref BAKE_STATE::RESIZENOTIFY message, cast to @ref BakeTextureResizeNotify*.
	Int32				timedelta;				///< Time.
	Float				r;								///< Progress, between @em 0 and @em 1.
	Int32				starttime;				///< Start time in milliseconds.
};

struct BakeTextureResizeNotify
{
	Int32					w,					///< Width.
								h;					///< Height.
	BaseBitmap**	cake;				///< Pointer to pointer to cake bitmap.
	Bool					result;			///< Result.
};

/// @}

//----------------------------------------------------------------------------------------
/// Bakes the texture(s) specified by the last InitBakeTexture() call into @formatParam{bmp}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] data								The bake settings: @enumerateEnum{BakeTexEnums}
/// @param[out] bmp								The bitmap to bake to. If this points to a MultipassBitmap, it must be initialized with the correct width and height before BakeTexture() is called. @callerOwnsPointed{bitmap}\n
/// 															If this points to a MultipassBitmap, it must be initialized with the correct width and height before BakeTexture() is called.\n
/// 															Multipass bitmaps must be used if @ref BAKE_TEX_AMBIENT_OCCLUSION is set. The only allowed modes for multipass bitmaps are @ref COLORMODE::RGB, @ref COLORMODE::ARGB, @ref COLORMODE::RGBw, @ref COLORMODE::ARGBw, @ref COLORMODE::RGBf, @ref COLORMODE::ARGBf.
/// @param[in] th									The current thread. @callerOwnsPointed{document}
/// @param[in] hook								The bake progress hook callback function pointer.
/// @param[in] info								The bake progress information passed to the @formatParam{hook} callback.
/// @return												::BAKE_TEX_ERR::NONE if successful, otherwise one of these errors: @enumerateEnum{BAKE_TEX_ERR}
//----------------------------------------------------------------------------------------
BAKE_TEX_ERR BakeTexture(BaseDocument* doc, const BaseContainer& data, BaseBitmap* bmp, BaseThread* th, BakeProgressHook* hook, BakeProgressInfo* info);

//----------------------------------------------------------------------------------------
/// Initializes a bake operation of a single tag for BakeTexture().
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] textag							The texture tag to bake. Must be assigned to an object. @callerOwnsPointed{tag}
/// @param[in] texuvw							The UVW tag to bake. Must be valid if UVW projection is selected in the tag, ignored otherwise. @callerOwnsPointed{tag}
/// @param[out] destuvw						The destination UVW tag for the bake. If not @formatConstant{nullptr}, the current projection is transformed into the uvw tag. @callerOwnsPointed{tag}
/// @param[in] bc									The bake settings: @enumerateEnum{BakeTexEnums}
/// @param[out] err								Assigned the error result, if not @formatConstant{nullptr}: @enumerateEnum{BAKE_TEX_ERR}
/// @param[in] th									The current thread. @callerOwnsPointed{document}
/// @return												The document for the bake to use for the call to BakeTexture(). @callerOwnsPointed{document}
//----------------------------------------------------------------------------------------
BaseDocument* InitBakeTexture(BaseDocument* doc, TextureTag* textag, UVWTag* texuvw, UVWTag* destuvw, const BaseContainer& bc, BAKE_TEX_ERR* err = nullptr, BaseThread* th = nullptr);

//----------------------------------------------------------------------------------------
/// Initializes a bake operation of multiple tags for BakeTexture().
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] textags						The texture tags to bake. Must be assigned to objects. @callerOwnsPointed{array}
/// @param[in] texuvws						The UVW tags to bake. @callerOwnsPointed{array}
/// @param[out] destuvws					The destination UVW tags for the bake. If not @formatConstant{nullptr}, the current projection is transformed into the uvw tags. @callerOwnsPointed{array}
/// @param[in] cnt								The number of tags in @formatParam{textags}, @formatParam{texuvws} and @formatParam{destuvws} arrays.
/// @param[in] bc									The bake settings: @enumerateEnum{BakeTexEnums}
/// @param[out] err								Assigned the error result, if not @formatConstant{nullptr}: @enumerateEnum{BAKE_TEX_ERR}
/// @param[in] th									The current thread. @callerOwnsPointed{document}
/// @return												The document for the bake to use for the call to BakeTexture(). @callerOwnsPointed{document}
//----------------------------------------------------------------------------------------
BaseDocument* InitBakeTexture(BaseDocument* doc, TextureTag** textags, UVWTag** texuvws, UVWTag** destuvws, Int32 cnt, const BaseContainer& bc, BAKE_TEX_ERR* err = nullptr, BaseThread* th = nullptr);

/// @}

//----------------------------------------------------------------------------------------
/// A class that encrypts data using an insecure scrambling.
//----------------------------------------------------------------------------------------
class GeCipher256
{
private:
	void* hnd;

public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GeCipher256();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~GeCipher256();

	//----------------------------------------------------------------------------------------
	/// Initializes the cipher engine with the specified @formatParam{key}.
	/// @param[in] key								Key array.
	/// @param[in] klength						Key length. Must be >@em 1.
	/// @param[in] stream							If @formatConstant{true} the encryption/decryption sequence has to take place in the exact same order, otherwise it will not work.\n
	/// 															If @formatConstant{false} all bytes are encrypted/decrypted independently.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Open(const void* key, Int32 klength, Bool stream);

	//----------------------------------------------------------------------------------------
	/// Closes the cipher engine.
	//----------------------------------------------------------------------------------------
	void Close();

	//----------------------------------------------------------------------------------------
	/// Encrypts an array.
	/// @param[in] mem								The array to encrypt.
	/// @param[in] size								The size of the array.
	//----------------------------------------------------------------------------------------
	void Encrypt(void* mem, Int32 size);

	//----------------------------------------------------------------------------------------
	/// Decrypts an array.
	/// @param[in] mem								The array to decrypt.
	/// @param[in] size								The size of the array.
	//----------------------------------------------------------------------------------------
	void Decrypt(void* mem, Int32 size);
};

#endif

#endif // C4D_TOOLS_H__
