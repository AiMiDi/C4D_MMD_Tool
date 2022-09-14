#ifndef GEOMETRYUTILS_H__
#define GEOMETRYUTILS_H__

#include "maxon/errorbase.h"
#include "maxon/vector2d.h"
#include "maxon/matrix2d.h"
#include "maxon/array.h"
#include "maxon/geomconstants.h"

namespace maxon
{
/// Return type for geometric tests when degenerate cases need to be reported
enum class GEOMETRY_TEST_EXACT
{
	GEOM_FALSE = 0,				///< Test result is false
	GEOM_TRUE,						///< Test result is true
	GEOM_PARALLEL,				///< Degenerate colinear, ordered in same direction
	GEOM_ANTIPARALLEL,		///< Degenerate colinear, ordered in opposite direction
	GEOM_COINCIDENT_PREV,	///< Degenerate coincident points
	GEOM_COINCIDENT_NEXT,	///< Degenerate coincident points
	GEOM_COINCIDENT_ALL,	///< Degenerate coincident points
	GEOM_DEGENERATE,			///< Other degeneracy
	GEOM_INVALID_INPUT		///< Input is non-valid in some way making it impossible to proceed
} MAXON_ENUM_LIST(GEOMETRY_TEST_EXACT);


/// Return type for loop overlap state queries.
enum class LOOP_OVERLAP_STATE
{
	INTERSECTING,	///< Loops intersect each other. Contact points do not count as intersections, only actual crossings of the loops.
	DISJOINT,			///< Loops are completely disjoint from each other
	A_INSIDE_B,		///< A is entirely within B
	B_INSIDE_A,		///< B is entirely within A
	COINCIDENT,		///< Loops are coincident - they lie on each other's perimeter, e.g. A and B are the same.
	DEGENERATE		///< At least one of A and B has insufficient vertices (need at least 3)
} MAXON_ENUM_LIST(LOOP_OVERLAP_STATE);




//----------------------------------------------------------------------------------------
/// An Degenerated input error indicates that a function was unable to compute a result because of degenerate cases (i.e. polygons with size 0).
//----------------------------------------------------------------------------------------
class DegeneratedInputErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(DegeneratedInputErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.degeneratedinputerror");
};


//----------------------------------------------------------------------------------------
/// 2D and 3D geometrical utility functions.
//----------------------------------------------------------------------------------------
class GeometryUtilsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GeometryUtilsInterface, MAXON_REFERENCE_NONE, "net.maxon.geom.geometryutils");

public:
	//----------------------------------------------------------------------------------------
	/// Remaps a value from one range to another.
	/// @param[in] value 					The value to remap.
	/// @param[in] from1 					First bound of source range.
	/// @param[in] to1 						Second bound of source range.
	/// @param[in] from2 					First bound of destination range.
	/// @param[in] to2 						Second bound of destination range.
	/// @return 									The remapped value.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2);

	//----------------------------------------------------------------------------------------
	/// Gets the 2D angle between two direction vectors.
	/// @param[in] direction1					First direction vector.
	/// @param[in] direction2					Second direction vector.
	/// @return												The angle value in between 0 and 2PI in radians.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float GetAngle2D(const Vector2d& direction1, const Vector2d& direction2);

	//----------------------------------------------------------------------------------------
	/// Calculates the normalized position of a point along a directed segment.
	/// @param[in] segmentPoint1			First segment point.
	/// @param[in] segmentPoint2			Second segment point.
	/// @param[in] point							The point position along the segment line.
	/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
	/// @return												The normalized position of the point on the segment.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp = true);

	//----------------------------------------------------------------------------------------
	/// Calculates the normalized position of a 2D point along a directed segment.
	/// @param[in] segmentPoint1			First segment point.
	/// @param[in] segmentPoint2			Second segment point.
	/// @param[in] point							The point position along the segment line.
	/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
	/// @return												The normalized position of the point on the segment.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp = true);

	//----------------------------------------------------------------------------------------
	/// Calculates the the best fit plane centroid and normal from a point cloud.
	/// @param[in] pointCloud					A block filled with point coordinates.
	/// @param[out] centroid					The resulting point cloud centroid.
	/// @param[out] normal						The resulting plane normal.
	/// @param[in] iterMax						Max iteration for computation.
	/// @return												True if successful otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax = 500);

	//----------------------------------------------------------------------------------------
	/// Projects 3D points as 2D points on a plane which is parallel to the points best fit
	/// plane and which passes through the origin of the world coordinate system.
	/// @param[in] points							Points 3D positions to project.
	/// @param[in] normal							The normal vector of the plane onto which to project the points.
	/// @param[in, out] basisVector0	First basis vector of the 2D plane coordinate system.
	/// @param[in, out] basisVector1	Second basis vector of the 2D plane coordinate system.
	/// @param[out] translate					Translation vector between the projection plane origin (which is
	///																the world CS origin) and the best fit plane origin (which is
	///																the orthogonal projection of the world CS origin to the fit plane).
	///																In other words, translation vector is the distance vector between
	///																the projection plane an the best fit planes.
	/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
	/// @param[out] outPoints					Array containing 2D projected points positions.
	/// @param[out] computeBasis			Compute basis vectors from the normal and the input points if enabled.
	/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis = true);

	//----------------------------------------------------------------------------------------
	/// Projects 3D points as 2D points on a plane. Overloaded function.
	/// @param[in] points							Points 3D positions to project.
	/// @param[in] normal							The normal vector of the plane onto which to project the points.
	/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
	/// @param[out] outPoints					Array containing 2D projected points positions.
	/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints);

	//----------------------------------------------------------------------------------------
	/// Calculates 3D world point coordinates from its 2D local coordinates.
	/// @param[in] point							Point 2D local coordinates.
	/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
	/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
	/// @param[in] translate					Translation vector.
	/// @return												Point 3D world coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate);

	//----------------------------------------------------------------------------------------
	/// Calculates 3D world points coordinates from its 2D local coordinates.
	/// @param[in] points							Points 2D local coordinates.
	/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
	/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
	/// @param[in] translate					Translation vector.
	/// @param[out] outPoints					Points 3D world coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints);

	//----------------------------------------------------------------------------------------
	/// Calculates the area of a triangle.
	/// @param[in] a									Triangle point A.
	/// @param[in] b									Triangle point B.
	/// @param[in] c									Triangle point C.
	/// @return												Unsigned triangle area.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c);

	//----------------------------------------------------------------------------------------
	/// Calculates the signed area of an oriented triangle.
	/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
	/// @param[in] a									Triangle point A.
	/// @param[in] b									Triangle point B.
	/// @param[in] c									Triangle point C.
	/// @return												Unsigned triangle area.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c);

	//----------------------------------------------------------------------------------------
	/// Calculates the area of a quadrangle.
	/// @param[in] a									Quadrangle point A.
	/// @param[in] b									Quadrangle Point B.
	/// @param[in] c									Quadrangle Point C.
	/// @param[in] d									Quadrangle Point D.
	/// @return												Unsigned area of Quadrangle.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d);

	//----------------------------------------------------------------------------------------
	/// Calculates the unsigned area of an outline defined by points in outlinePoints.
	/// If the points are not co-planar, they will be flattened on a "best fit" plane.
	/// @param[in] outlinePoints			An array with a point sequence.
	/// @return												The outline area.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculateOutlineArea(const Block<const Vector>& outlinePoints);

	//----------------------------------------------------------------------------------------
	/// Calculates the normal of an ngon outline.
	/// @param[in] points							A list of points that includes the outline points.
	/// @param[in] indices						The indices in the points list for the outline points to use. The order is important.
	/// @param[in] normalized					If true, the output normal will be normalized.
	/// @return												The normal of the point outline.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized = true);

	//----------------------------------------------------------------------------------------
	/// Calculates the normal of an ngon outline.
	/// @param[in] points							The correctly ordered points that include the points for the outline.
	/// @param[in] normalize					If true, the output normal will be normalized.
	/// @return												The normal of the point outline.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector CalculateOutlineNormal(const Block<const Vector>& points, Bool normalize = true);

	//----------------------------------------------------------------------------------------
	/// A convexity test for vertex in between 2 other vertices in 3D space.
	/// @param[in] vertex							The vertex to check.
	/// @param[in] next								The next point.
	/// @param[in] pred								The prev point.
	/// @param[in] up									Up vector or the normal of the polygon.
	/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up = Vector(0, 1, 0));

	//----------------------------------------------------------------------------------------
	/// A convexity test for vertex in between 2 other vertices in 3D space.
	/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
	/// @param[in] vertex							The vertex to check.
	/// @param[in] next								The next point.
	/// @param[in] pred								The prev point.
	/// @param[in] up									Up vector or the normal of the polygon.
	/// @return												The detectected state
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD GEOMETRY_TEST_EXACT IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up = Vector(0, 1, 0), Float epsilon = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Calculates the mean value coordinates weights for a point inside an outline.
	/// @param[in] point							The point for which to calculate weights.
	/// @param[in] outline						The outline.
	/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights);

	//----------------------------------------------------------------------------------------
	/// Calculates the mean value coordinates weights for a point inside an outline.
	/// @param[in] point							The point for which to calculate weights.
	/// @param[in] points							A list of points that the outlineIndices reference to.
	/// @param[in] outlineIndices			The indices of the outline.
	/// @param[in] normal							The normal direction of the outline.
	/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights);

	//----------------------------------------------------------------------------------------
	/// A convexity test for vertex in between two other vertices in 2D.
	/// @param[in] vertex							The vertex to check.
	/// @param[in] next								The next point.
	/// @param[in] pred								The prev point.
	/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred);

	//----------------------------------------------------------------------------------------
	/// A convexity test for vertex in between 2 other vertices in 2D
	/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
	/// @param[in] vertex							The vertex to check.
	/// @param[in] next								The next point.
	/// @param[in] pred								The prev point.
	/// @return												The detectected state
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD GEOMETRY_TEST_EXACT IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Calculates the barycentric UV coordinate of a point within a triangle.
	/// @param[in] point							The point.
	/// @param[in] a									Triangle vertex A.
	/// @param[in] b									Triangle vertex B.
	/// @param[in] c									Triangle vertex C.
	/// @return												The barycentric point coordinate.
	///																'x' component of the vector is the coordinate of the point @p c,
	///																'y' component of the vector is the coordinate of the point @p b.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector2d CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c);

	//----------------------------------------------------------------------------------------
	/// Calculates the barycentric UVW coordinate of a point within a triangle.
	/// @param[in] point							The point.
	/// @param[in] a									Triangle vertex A.
	/// @param[in] b									Triangle vertex B.
	/// @param[in] c									Triangle vertex C.
	/// @return												The barycentric point coordinate.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside a triangle.
	/// @param[in] point							The point to test.
	/// @param[in] a									Triangle vertex A.
	/// @param[in] b									Triangle vertex B.
	/// @param[in] c									Triangle vertex C.
	/// @return												True if point is inside the triangle.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside triangle in 2D.
	/// @param[in] point							The point to test.
	/// @param[in] a									Triangle vertex A.
	/// @param[in] b									Triangle vertex B.
	/// @param[in] c									Triangle vertex C.
	/// @return												True if point is inside the triangle.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline.
	/// @param[in] point							The point ot test.
	/// @param[in] outline						The array with outline points.
	/// @return												The resulting winding number, 0 means point is outside.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline. Exact yet slower version.
	/// @param[in] point							The point ot test.
	/// @param[in] outline						The array with outline points.
	/// @return												The resulting winding number, 0 means point is outside.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline.
	/// @param[in] point							The point ot test.
	/// @param[in] outline						The array with outline points.
	/// @param[out] edgeHit						In case point lies on an outline edge this will be filled with the edge index, otherwise maxon::InvalidArrayIndex.
	/// @return												The resulting winding number, 0 means point is outside.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
	/// @param[in] point							The point to test.
	/// @param[in] outline						The array with outline points.
	/// @return												The resulting winding number. 0 means point is outside.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
	/// @param[in] point							The point to test.
	/// @param[in] outline						The array with outline points.
	/// @param[out] edgeHit						In case point lies on an outline edge, this will be filled with the edge index. Otherwise the value maxon::InvalidArrayIndex is set.
	/// @return												The resulting winding number. 0 means point is outside.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline, Int& edgeHit);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline.
	/// @param[in] point							The point ot test.
	/// @param[in] outline						The array with outline points.
	/// @return												True if the point is inside the outline.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is inside an outline.
	/// @param[in] point							The point ot test.
	/// @param[in] outline						The array with outline points.
	/// @return												True if the point is inside the outline.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline);

	//----------------------------------------------------------------------------------------
	/// Calculates the 3D bisector angle using an up vector to identify the sliding surface.
	/// A custom weight for each side can optionally be specified.
	/// @param[in] v1									First vector.
	/// @param[in] v2									Second vector.
	/// @param[in] up									The up vector.
	/// @param[in] w1									Optional weight value for v1.
	/// @param[in] w2									Optional weight value for v2.
	/// @return												The bisector angle vector.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up = Vector(0, 1, 0), Float w1 = 1.0, Float w2 = 1.0);

	//----------------------------------------------------------------------------------------
	/// Calculates the circumcenter and radius of a planar triangle.
	/// @param[in] a									Triangle point A.
	/// @param[in] b									Triangle point B.
	/// @param[in] c									Triangle point C.
	/// @param[out] center						Triangle circumcenter.
	/// @param[out] sqrRad						Squared radius of the circle defined by the triangle points.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Calculates the circumcenter and radius of a triangle.
	/// @param[in] a									Triangle point A.
	/// @param[in] b									Triangle point B.
	/// @param[in] c									Triangle point C.
	/// @param[out] center						Triangle circumcenter.
	/// @param[out] rad								Radius of the circle defined by the triangle points.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks if two segments intersect in 2D space.
	/// @param[in] segment1Point1			First segment point 1.
	/// @param[in] segment1Point2			First segment point 2.
	/// @param[in] segment2Point1			Second segment point 1.
	/// @param[in] segment2Point2			Second segment point 2.
	/// @return												True if the segments intersect in 2D.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2);

	//----------------------------------------------------------------------------------------
	/// Checks if a segment is intersected by a ray in 2D space.
	/// @param[in] segmentPoint1			Segment point 1.
	/// @param[in] segmentPoint2			Segment point 2.
	/// @param[in] rayStartPoint			Line start point.
	/// @param[in] rayDirection				Line Direction.
	/// @return												True if the segments intersect in 2D.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection);

	//----------------------------------------------------------------------------------------
	/// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
	/// @param[in] segment1Point1			First segment point.
	/// @param[in] segment1Point2			First segment point.
	/// @param[in] segment2Point1			Second segment point.
	/// @param[in] segment2Point2			Second segment point.
	/// @param[out] intersectionPoint	Calculated intersection point in xy plane.
	/// @param[in] tolerance					Geometric linear tolerance for the operation by default = 0.0.
	/// @return												True if the segments intersect in 2D.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance = 0.0_f);

	//----------------------------------------------------------------------------------------
	/// Calculates min distance for given lines, fill param1/param2 with parametrized distance form first point.
	/// @param[in] line1Point					A point on first line.
	/// @param[in] line1Dir						First line direction vector.
	/// @param[in] line2Point					A point on second line.
	/// @param[in] line2Dir						Second line direction vector.
	/// @param[out] parallel					The function set it true if the tow line are parallel.
	/// @param[out] param1						Parametrized distance from fist line first point where the distance is calculated (p = line1Point + !line1Dir * param1)
	/// @param[out] param2						Parametrized distance from second line first point where the distance is calculated (p = line2Point + !line2Dir * param2)
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												Distance Vector.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector LineLineDistance(const Vector& line1Point, const Vector& line1Dir , const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is on a line segment in 2D. The tolerance value is used for the colinearity test only, not for the boundary test.
	/// @param[in] point							The point to check.
	/// @param[in] segmentPoint1			1st Segment point.
	/// @param[in] segmentPoint2			2nd Segment point.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if point is on segment, otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is on a line segment in 3D. The tolerance value is used for the colinearity test only, not for the boundary test.
	/// @param[in] point							The point to check.
	/// @param[in] segmentPoint1			1st Segment point.
	/// @param[in] segmentPoint2			2nd Segment point.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if point is on segment, otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is on a half line .
	/// @param[in] point							The point to check.
	/// @param[in] halfLineOrigin			Half line origin.
	/// @param[in] halfLineDir				Half line direction.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if point is on half line, otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for intersection between two lines and fills intersectionPoint with the intersection position.
	/// @param[in] line1Point					A point on 1st line.
	/// @param[in] line1Dir						1st line direction vector.
	/// @param[in] line2Point					A point on 2nd line.
	/// @param[in] line2Dir						2nd line direction vector.
	/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for line vs. segment intersection and fills intersection with the intersection position.
	/// @param[in] linePoint					A point on the line.
	/// @param[in] lineDir						Line direction vector.
	/// @param[in] segmentPoint1			First segment point.
	/// @param[in] segmentPoint2			Second segment point.
	/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for segment vs. segment intersection and fills intersection with the intersection position.
	/// @param[in] segment1Point1			First Segment first point.
	/// @param[in] segment1Point2			First Segment second point.
	/// @param[in] segment2Point1			Second Segment first point.
	/// @param[in] segment2Point2			Second Segment second point.
	/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for halfline/halfline intersection and fills intersectionPoint with the intersection position.
	/// @param[in] halfLine1Origin		Start point 1st half line.
	/// @param[in] halfLine1Dir				1st half line direction vector.
	/// @param[in] halfLine2Origin		Start point 2nd half line.
	/// @param[in] halfLine2Dir				2nd half line direction vector.
	/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for line/halfline intersection and fills intersectionPoint with the intersection position.
	/// @param[in] linePoint					A point on the line.
	/// @param[in] lineDir						Line direction vector.
	/// @param[in] halfLineOrigin			Start point of Half line.
	/// @param[in] halfLineDir				Half line direction vector.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for halfLine/segment Intersection and fills intersectionPoint with the intersection position.
	/// @param[in] halfLineOrigin			Start point of Half line.
	/// @param[in] halfLineDir				Half line direction vector.
	/// @param[in] segmentPoint1			First Segment point.
	/// @param[in] segmentPoint2			Second Segment point.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for plane/plane intersection and fills the intersection line.
	/// @param[in] plane1Point				Plane 1 point.
	/// @param[in] plane1Normal				Plane 1 normal.
	/// @param[in] plane2Point				Plane 2 point.
	/// @param[in] plane2Normal				Plane 2 normal.
	/// @param[out] resLinePoint			A point on the intersection line.
	/// @param[out] resLineDirection	Intersection line direction.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for plane/Line intersection and fills intersectionPoint with the intersection position.
	/// @param[in] linePoint					A point on line.
	/// @param[in] lineDir						Line direction vector.
	/// @param[in] planePoint					Plane point.
	/// @param[in] planeNormal				Plane normal.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for plane/line intersection and fills intersectionPoint with the intersection position.
	/// @param[in] linePoint					A point on line.
	/// @param[in] lineDir						Line direction vector.
	/// @param[in] planePoint					Plane point.
	/// @param[in] planeNormal				Plane normal.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for plane/segment intersection and fills intersectionPoint with the intersection position.
	/// @param[in] segmentPoint1			Segment point 1.
	/// @param[in] segmentPoint2			Segment point 2.
	/// @param[in] planePoint					Plane point.
	/// @param[in] planeNormal				Plane normal.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for plane/halfline intersection and fills intersectionPoint with the intersection position.
	/// @param[in] halfLinePoint			Half line Origin.
	/// @param[in] halfLineDir				Half line direction vector.
	/// @param[in] planePoint					Plane point.
	/// @param[in] planeNormal				Plane normal.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for line/triangle intersection and fills intersectionPoint with the intersection position.
	/// @param[in] linePoint					A point on the line.
	/// @param[in] lineDir						The line direction vector.
	/// @param[in] a									Triangle vertex.
	/// @param[in] b									Triangle vertex.
	/// @param[in] c									Triangle vertex.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords = nullptr, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for halfline/triangle intersection and fills intersectionPoint with the intersection position.
	/// @param[in] halfLineOrigin			Half line origin point.
	/// @param[in] halfLineDir				The half line direction vector.
	/// @param[in] a									Triangle vertex.
	/// @param[in] b									Triangle vertex.
	/// @param[in] c									Triangle vertex.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords = nullptr, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for line/quadrangle intersection and fills intersectionPoint with the intersection position.
	/// @param[in] linePoint					A point on the line.
	/// @param[in] lineDir						The line direction vector.
	/// @param[in] a									Quadrangle vertex.
	/// @param[in] b									Quadrangle vertex.
	/// @param[in] c									Quadrangle vertex.
	/// @param[in] d									Quadrangle vertex.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for halfline/quadrangle intersection and fills intersectionPoint with the intersection position.
	/// @param[in] halfLineOrigin			Half line origin point.
	/// @param[in] halfLineDir				The half line direction vector.
	/// @param[in] a									Quadrangle vertex.
	/// @param[in] b									Quadrangle vertex.
	/// @param[in] c									Quadrangle vertex.
	/// @param[in] d									Quadrangle vertex.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks for linesegment/triangle intersection and fills intersectionPoint with the intersection position.
	/// @param[in] segmentPoint1			Segment point.
	/// @param[in] segmentPoint2			Segment point.
	/// @param[in] a									Triangle vertex.
	/// @param[in] b									Triangle vertex.
	/// @param[in] c									Triangle vertex.
	/// @param[out] intersectionPoint	Intersection position if intersection happens.
	/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords = nullptr, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Checks if 2 triangles intersect.
	/// @param[in] t1a								Triangle 1 vertex.
	/// @param[in] t1b								Triangle 1 vertex.
	/// @param[in] t1c								Triangle 1 vertex.
	/// @param[in] t2a								Triangle 2 vertex.
	/// @param[in] t2b								Triangle 2 vertex.
	/// @param[in] t2c								Triangle 2 vertex.
	/// @param[in] tolerance					Geometric linear tolerance for the operation.
	/// @return												True if an intersection happens  otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance = GeomConstants::EPSILON4);

	//----------------------------------------------------------------------------------------
	/// Calculates a S/T coordinate for a given 3D point and polygon in the polygon plane. The 3D point needs to be on
	/// the plane that is defined by the polygon.
	/// The function is just a 2d evaluation so not coplanar polygons need to be evaluated by projecting vertex on best fit plane.
	/// @param[in] point							The point to find s and t.
	/// @param[in] pa									Polygon point.
	/// @param[in] pb									Polygon point.
	/// @param[in] pc									Polygon point.
	/// @param[in] pd									Polygon point.
	/// @param[in] isQuad							If true evaluate using a quadrangle, otherwise ignore pd and use a triangle.
	/// @param[out] s									The resulting s coordinate, or MINVLAUE_FLOAT if the functions fail.
	/// @param[out] t									The resulting t coordinate, or MINVLAUE_FLOAT if the functions fail.
	/// @param[in] tolerance					Geometric linear tolerance for the operation, used to define if the point is inside of polygon or not.
	/// @return												True if the point is in the polygon boundary otherwise false (negative s or t values).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance = GeomConstants::EPSILON4);


	//----------------------------------------------------------------------------------------
	/// Calculates the bilinear coordinates of a point in a quad.
	/// The quad is defined by the points pa, pb, pc and pd.
	/// @param[in] pa									Polygon point.
	/// @param[in] pb									Polygon point.
	/// @param[in] pc									Polygon point.
	/// @param[in] pd									Polygon point.
	/// @param[in] point							The point to find the bilinear interpolation values for.
	/// @param[out] bilinarVariables	The resulting coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables);

	//----------------------------------------------------------------------------------------
	/// Calculates the bilinear coordinates of a point in a quad with a Newton iteration method.
	/// The quad is defined by the points pa, pb, pc and pd.
	/// @param[in] pa									Polygon point.
	/// @param[in] pb									Polygon point.
	/// @param[in] pc									Polygon point.
	/// @param[in] pd									Polygon point.
	/// @param[in] point							The point to find the bilinear interpolation values for.
	/// @param[in] iterations					The iteration count of the Newton iteration.
	/// @param[out] bilinarVariables	The resulting coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables);

	//----------------------------------------------------------------------------------------
	/// Calculates the bilinear coordinates of a 2d point in a 2d quad.
	/// The quad is defined by the points pa, pb, pc and pd.
	/// @param[in] pa									Polygon 2d point.
	/// @param[in] pb									Polygon 2d point.
	/// @param[in] pc									Polygon 2d point.
	/// @param[in] pd									Polygon 2d point.
	/// @param[in] point							The 2d point to find the bilinear interpolation values for.
	/// @param[out] bilinarVariables	The resulting coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables);

	//----------------------------------------------------------------------------------------
	/// Calculates the bilinear coordinates of a 2d point in a 2d quad with a Newton iteration method.
	/// The quad is defined by the points pa, pb, pc and pd.
	/// @param[in] pa									Polygon 2d point.
	/// @param[in] pb									Polygon 2d point.
	/// @param[in] pc									Polygon 2d point.
	/// @param[in] pd									Polygon 2d point.
	/// @param[in] point							The 2d point to find the bilinear interpolation values for.
	/// @param[in] iterations					The iteration count of the Newton iteration.
	/// @param[out] bilinarVariables	The resulting coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables);

	//----------------------------------------------------------------------------------------
	/// Calculates the bilinear interpolation within a quad.
	/// The quad is defined by the points pa, pb, pc and pd.
	/// @param[in] pa									Polygon point.
	/// @param[in] pb									Polygon point.
	/// @param[in] pc									Polygon point.
	/// @param[in] pd									Polygon point.
	/// @param[in] s									The first bilinar coordinate.
	/// @param[in] t									The second bilinear coordinate.
	/// @return												The point in space with these bilinear coordinates relative to the quad pa, pb, pc and pd.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t);

	//----------------------------------------------------------------------------------------
	/// Calculates the signed area of an oriented triangle.
	/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
	/// @param[in] a									Triangle point A.
	/// @param[in] b									Triangle point B.
	/// @param[in] c									Triangle point C.
	/// @param[in] normal             The reference normal to calculate the sign.
	/// @return												Unsigned triangle area.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& normal);

	//----------------------------------------------------------------------------------------
	/// Calculates the mean value coordinates weights for a point inside an outline.
	/// @param[in] point							The point for which to calculate weights.
	/// @param[in] outline						The outline.
	/// @param[in] normal							The normal direction of the outline.
	/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights);

	//----------------------------------------------------------------------------------------
	/// Calculates the perimeter length for an outline defined by a loop of points in outlinePoints.
	/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
	/// @return												The perimeter
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints);

	//----------------------------------------------------------------------------------------
	/// Determines whether outline defined by a loop of points is would clockwise or not
	/// This is only meaningful if the loop has no self crossings.
	/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
	/// @return												Whether loop is wound clockwise
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints);

	//----------------------------------------------------------------------------------------
	/// Calculates the centroid coordinates for an outline defined by a loop of points in outlinePoints.
	/// @param[in] outlinePoints			An array with a point sequence.
	/// @param[out] area							If non-null, then pointed value is set to the enclosed area.
	/// @param[out] windingPolarity 	If non-null, then pointed value contains the winding direction of the loop.
	/// @return												The centroid coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector2d CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area = nullptr, Bool* windingPolarity = nullptr);

	//----------------------------------------------------------------------------------------
	/// Calculates the centroid coordinates for an outline with optional holes, defined by loop(s) of vertices.
	/// @param[in] loopVertices				An array with one or more point sequences which define perimeter loop followed by any hole loops. All loops are ASSUMED to neither overlap nor intersect, and first loop must enclose all others.
	/// @param[in] loopVertexCounts		An array containing the number of vertices in each loop. If no holes, then this will be a single value equal to the number of entries in loopVertices.
	/// @param[in] includeHolesInCogCalcs If true, the holes are considered in calculation of the centroid position. If false, only the first loop (outer perimeter) is considered.
	/// @param[out] overallArea				If non-null, then pointed value is set to the enclosed area. Holes are ALWAYS considered in this calculation.
	/// @param[out] loopSoloAreas 		If non-null, then pointed array contains the areas enclosed by each loop in isolation. Overall area is then the first value minus the sum of the rest.
	/// @param[out] windingPolarity	 	If non-null, then pointed array contains the winding direction of each loop.
	/// @return												The centroid coordinates.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Vector2d> CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea = nullptr, BaseArray<Float>* loopSoloAreas = nullptr, BaseArray<Bool>* windingPolarity = nullptr);

	//----------------------------------------------------------------------------------------
	/// Calculates the convex hull for an outline, defined by a loop of vertices
	/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
	/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
	/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
	/// @return												BaseArray containing the indices of the input array corresponding to the vertices of the convex hull of the polygon.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Int>> CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints);

	//----------------------------------------------------------------------------------------
	/// Decomposes an outline defined by a loop of vertices into a set of convex parts
	/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
	/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
	/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
	/// @return												BaseArray containing BaseArray of indices of the input array corresponding to the vertices of each of the convex parts of.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<BaseArray<Int>>> CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints);

	//----------------------------------------------------------------------------------------
	/// Given a loop of vertices, this performs in-place cleaning operations.
	/// - Duplicated consecutive vertices are removed.
	/// - Colinear and anti-colinear vertices are removed.
	/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
	/// @param[in] maintainStart			If false, then vertex order is rotated such that the first vertex lies on the convex hull. (If it is true, then starting vertex remains unchanged, unless that vertex was removed during cleaning. In this case the new start vertex is the first vertex after that which survived.)
	/// @return												Whether any changes were made.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
	/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
	/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
	/// @return												The resulting NoFit polygon
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA = true);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
	/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
	/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
	/// @return												The resulting NoFit polygon
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA = true);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two polygons, this calculates the corresponding Inner-Fit Polygon using the sliding method.
	/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
	/// @param[in] outlinePointsCcwA	An array with a point sequence representing the perimeter of the first polygon. This must be counterclockwise wound.
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon. This must be clockwise wound.
	/// @return												The resulting Inner-Fit polygon
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Vector2d>> CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
	/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
	/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
	/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
	/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
	/// @return												The resulting NoFit polygon
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA = true);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
	/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
	/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
	/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
	/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
	/// @return												The resulting NoFit polygon
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA = true);

	//----------------------------------------------------------------------------------------
	/// Given two loops of vertices which represent two polygon outlines, this calculates the union.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
	/// @param[in] includeHolesInResult		If true, then if union shape contains holes, then these are also calculated and returned. If false then only the outer perimeter is returned.
	/// @param[in] createOuterLoop		If true, then attempt to generate an outer loop before looking for holes. Otherwise just generate holes.
	/// @return												The resulting union. If this contains multiple loops the first is the outer perimeter and all others represent internal loops (holes).
	///																If this is empty, then the outlines do not overlap.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<BaseArray<Vector2d>>> CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop = true);

	//----------------------------------------------------------------------------------------
	/// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
	/// If the lines are parallel and intersect:
	///   If intersectionPoint2 is nullptr then the midpoint of the intersection range will be returned via 'intersectionPoint'
	///		If intersectionPoint2 is non-null, then the start of the intersection range will be returned via 'intersectionPoint', and the end via '*intersectionPoint2'
	/// 
	/// @param[in]	segment1Point1			First segment point.
	/// @param[in]	segment1Point2			First segment point.
	/// @param[in]	segment2Point1			Second segment point.
	/// @param[in]	segment2Point2			Second segment point.
	/// @param[out] intersectionPoint		Calculated intersection point in xy plane. For parallel intersection segments this is the start or mid-point of the overlapping region - see above.
	/// @param[out] areParallel					If non null, routine sets to true or false to indicate whether the line segments were detected to be parallel.
	/// @param[out] intersectionPoint2	If non null, and segments are colinear and overlapping,  then is the end of the overlapping region.
	/// @param[in]	tolerance						Geometric tolerance for the operation.
	/// @return													True if the segments intersect in 2D.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2 = nullptr, Float tolerance = 0.0_f);


	//----------------------------------------------------------------------------------------
	/// Given two boundary loops of vertices WHICH ARE KNOWN TO CONTAIN NO INTERSECTIONS, this determines the relative
	/// containment state of the two loops.
	/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
	/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
	/// @return												The containment state
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LOOP_OVERLAP_STATE GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB);

	//----------------------------------------------------------------------------------------
	/// Given two boundary loops of vertices, this determines whether the two loops are the same shape.
	/// They are deemed to be the same if there are the same number of vertices, and the pairwise vertices
	/// have the same coordinates to within the tolerance distance.
	/// @param[in] loopA			An array with a point sequence representing the first loop
	/// @param[in] loopB			An array with a point sequence representing the second loop
	/// @param[in] allowCyclicRotation			If true, then cyclically rotated loops are considered equivalent, i.e. the loops don't have to start on the same vertices 
	///																			for a match to be found. Loops which match, but have opposing winding directions are also considered to be a match when this is true.
	///																			If false then vertices with the same indices must have the same coordinates to declare a match.
	/// @param[in] ignoreTranslationOffset	If true then any translational offset between the loops is ignored. I.e. the same shapes at different offsets will be considered to match.
	/// @param[in] tol				The position tolerance. If vertices differ by more than this in either x or y then they are considered to be different and non-matching.
	/// @return								Whether the loops represent the same shape.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation = true, Bool ignoreTranslationOffset = true, maxon::Float tol = maxon::GeomConstants::EPSILON5);

	
	//----------------------------------------------------------------------------------------
	/// Given a set of vertices, returns indices of vertices which lie on each of the maximal extents.
	/// @param[in] verts			The set of vertices
	/// @param[out] minIdxX		The index of a vertex with minimum X extent
	/// @param[out] maxIdxX		The index of a vertex with maximum X extent
	/// @param[out] minIdxY		The index of a vertex with minimum Y extent
	/// @param[out] maxIdxY		The index of a vertex with minimum Y extent
	/// @param[in]	findMostCounterClockwise	If true then when multiple vertices lie on the same extent, the most counterclockwise one will be the one whose index is returned.
	static MAXON_METHOD void CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise);

	//----------------------------------------------------------------------------------------
	/// Given a set of vertices, this determines whether the vertices are co-linear (lie in the same line)
	/// They are deemed not to be co-linear if there exists a triangle whose area is greater than the given tolerance. 
	/// @param[in] points			The set of vertices.
	/// @param[in] tol				The triangle area tolerance. If area of the triangle formed by three vertices is greater than the tolerance, the vertices are not co-linear.
	/// @return								Whether the loops are co-linear.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ArePointsCoLinearWithinTolerance(const Block<const Vector>& points, maxon::Float tol = maxon::GeomConstants::EPSILON5);
};

#include "geometryutils1.hxx"
#include "geometryutils2.hxx"

} // namespace maxon

#endif // GEOMETRYUTILS_H__
