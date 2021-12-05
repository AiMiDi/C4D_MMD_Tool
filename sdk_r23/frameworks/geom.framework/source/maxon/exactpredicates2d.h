#ifndef EXACTPREDICATES2D_H__
#define EXACTPREDICATES2D_H__

#include "maxon/errorbase.h"
#include "maxon/vector2d.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// 2D exact geometrical predicates. Based on Shewchuk's adaptive exact predicates.
//----------------------------------------------------------------------------------------
class ExactPredicates2DInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ExactPredicates2DInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.exactpredicates2d");

public:
	//----------------------------------------------------------------------------------------
	/// Gets orientation of three points.
	/// @param[in] pointA							First point.
	/// @param[in] pointB							Second point.
	/// @param[in] pointC							Third point.
	/// @return												Positive (negative) value if orientation is counter-clockwise
	///																(clockwise), zero otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float Orient(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC);

	//----------------------------------------------------------------------------------------
	/// Tests if a point is inside the circumscribed circle of a triangle defined by three points.
	/// @param[in] pointA							First point.
	/// @param[in] pointB							Second point.
	/// @param[in] pointC							Third point.
	/// @param[in] testPoint					Test point.
	/// @return												Positive (negative) value if the point is inside (outside)
	///																the circle, zero if it is on the circle.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float InCircle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint);

	//----------------------------------------------------------------------------------------
	/// Tests if a point is inside a triangle defined by three points.
	/// @param[in] pointA							First point.
	/// @param[in] pointB							Second point.
	/// @param[in] pointC							Third point.
	/// @param[in] testPoint					Test point.
	/// @pre													Three triangle points shall differ.
	/// @return												Positive (negative) value if the point is inside (outside)
	///																the triangle, zero if it is on the triangle boundary.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float> InTriangle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint);

	//----------------------------------------------------------------------------------------
	/// Checks if the test point lies inside a space sector.
	/// @details											Check if the test point lies inside the space sector defined by
	///																a center point and two rays (ccw order).
	/// @param[in] center							Sector center.
	/// @param[in] rayA								Sector first ray.
	/// @param[in] rayB								Sector second ray (ccw w.r.t the above parameters).
	/// @param[in] testPoint					Test Point.
	/// @pre													Center and ray points shall differ.
	/// @pre													Sector angle shall be less than 180 degree (not reflex).
	/// @return												Positive/zero/negative if the test point @testPoint is
	///																in/on/outside the sector respectively.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float> InSector(const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint);

	//----------------------------------------------------------------------------------------
	/// Tests if a closed outline is self-intersected or have duplicated points.
	/// @param[in] outline						Input outline.
	/// @return												Outlines is self-intersected.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OutlineSelfIntersectionTest(const Block<const Vector2d>& outline);

	//----------------------------------------------------------------------------------------
	/// Tests if two closed outlines intersect or either polyline is self-intersected.
	/// @details											Tests if two closed outlines intersect in at least one point or at
	///																least one of them is self-intersected or have duplicated points.
	/// @pre													Each outline has at least 3 points.
	/// @param[in] outline1						First outline.
	/// @param[in] outline2						Second outline.
	/// @return												Outlines intersect.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OutlinesIntersectionTest(const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2);

	//----------------------------------------------------------------------------------------
	/// Tests if a set of closed outlines intersect or if either polyline is self-intersected.
	/// @details											Tests if a set of closed outlines intersect in at least one point or at
	///																least one of them is self-intersected or has duplicated points.
	/// @pre													Each outline has at least 3 points.
	/// @param[in] outlines						Input outlines.
	/// @return												Outlines intersect.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OutlinesIntersectionTest(const Block<const Block<const Vector2d>>& outlines);
};

#include "exactpredicates2d1.hxx"
#include "exactpredicates2d2.hxx"

} // namespace maxon

#endif // EXACTPREDICATES2D_H__
