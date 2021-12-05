#ifndef GEOMETRYUTILS_H__
#define GEOMETRYUTILS_H__

#include "maxon/errorbase.h"
#include "maxon/vector2d.h"
#include "maxon/array.h"
#include "maxon/geomconstants.h"

namespace maxon
{
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
	/// Calculates the mean value coordinates weights for a point inside an outline.
	/// @param[in] point							The point for which to calculate weights.
	/// @param[in] outline						The outline.
	/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights);

	//----------------------------------------------------------------------------------------
	/// A convexity test for vertex in between two other vertices in 2D.
	/// @param[in] vertex							The vertex to check.
	/// @param[in] next								The next point.
	/// @param[in] pred								The prev point.
	/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred);

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
	/// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
	/// @param[in] segment1Point1			First segment point.
	/// @param[in] segment1Point2			First segment point.
	/// @param[in] segment2Point1			Second segment point.
	/// @param[in] segment2Point2			Second segment point.
	/// @param[out] intersectionPoint	Calculated intersection point in xy plane.
	/// @param[in] tolerance					Geometric linear tolerance for the operation by default = 0.0.
	/// @return												True if the segments intersect in 2D.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IntersectsSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance = 0.0);

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
};

#include "geometryutils1.hxx"
#include "geometryutils2.hxx"

} // namespace maxon

#endif // GEOMETRYUTILS_H__
