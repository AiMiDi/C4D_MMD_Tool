#if 1
namespace maxon
{
	namespace enum24 { enum class GEOMETRY_TEST_EXACT
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
	} ; }
	maxon::String PrivateToString_GEOMETRY_TEST_EXACT24(std::underlying_type<enum24::GEOMETRY_TEST_EXACT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_FALSE, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_TRUE, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_PARALLEL, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_ANTIPARALLEL, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_COINCIDENT_PREV, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_COINCIDENT_NEXT, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_COINCIDENT_ALL, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_DEGENERATE, (maxon::UInt64) enum24::GEOMETRY_TEST_EXACT::GEOM_INVALID_INPUT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GEOMETRY_TEST_EXACT", SIZEOF(x), false, values, "GEOM_FALSE\0GEOM_TRUE\0GEOM_PARALLEL\0GEOM_ANTIPARALLEL\0GEOM_COINCIDENT_PREV\0GEOM_COINCIDENT_NEXT\0GEOM_COINCIDENT_ALL\0GEOM_DEGENERATE\0GEOM_INVALID_INPUT\0", fmt);
	}
	namespace enum36 { enum class LOOP_OVERLAP_STATE
	{
		INTERSECTING,	///< Loops intersect each other. Contact points do not count as intersections, only actual crossings of the loops.
		DISJOINT,			///< Loops are completely disjoint from each other
		A_INSIDE_B,		///< A is entirely within B
		B_INSIDE_A,		///< B is entirely within A
		COINCIDENT,		///< Loops are coincident - they lie on each other's perimeter, e.g. A and B are the same.
		DEGENERATE		///< At least one of A and B has insufficient vertices (need at least 3)
	} ; }
	maxon::String PrivateToString_LOOP_OVERLAP_STATE36(std::underlying_type<enum36::LOOP_OVERLAP_STATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum36::LOOP_OVERLAP_STATE::INTERSECTING, (maxon::UInt64) enum36::LOOP_OVERLAP_STATE::DISJOINT, (maxon::UInt64) enum36::LOOP_OVERLAP_STATE::A_INSIDE_B, (maxon::UInt64) enum36::LOOP_OVERLAP_STATE::B_INSIDE_A, (maxon::UInt64) enum36::LOOP_OVERLAP_STATE::COINCIDENT, (maxon::UInt64) enum36::LOOP_OVERLAP_STATE::DEGENERATE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LOOP_OVERLAP_STATE", SIZEOF(x), false, values, "INTERSECTING\0DISJOINT\0A_INSIDE_B\0B_INSIDE_A\0COINCIDENT\0DEGENERATE\0", fmt);
	}
	const maxon::Char* const DegeneratedInputErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DegeneratedInputErrorInterface, , "net.maxon.interface.degeneratedinputerror", "maxon.DegeneratedInputErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DegeneratedInputErrorObject, , "net.maxon.error.degeneratedinput");
	const maxon::Char* const GeometryUtilsInterface::MTable::_ids = 
		"LinearRemapToRange@9a69efda73cd1131\0" // Float LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2)
		"GetAngle2D@b7cd04937484a59f\0" // Float GetAngle2D(const Vector2d& direction1, const Vector2d& direction2)
		"InterpolatePointOnSegment@c17b02dcaeded3c7\0" // Float InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp)
		"InterpolatePointOnSegment2D@c024aa88f99af01\0" // Float InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp)
		"CalculateBestFitPlane@94c8d437a7b95d20\0" // Bool CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax)
		"Points3Dto2D@115fd1c3719bce9a\0" // Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis)
		"Points3Dto2D@165572535a54960f\0" // Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints)
		"Point2Dto3D@c3f1f93da76f08a4\0" // Vector Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate)
		"Points2Dto3D@78c9f93bc039dbe9\0" // Result<void> Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints)
		"CalculateTriangleArea@716847940b2d41cb\0" // Float CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c)
		"CalculateSignedTriangleArea@716847940b2d41cb\0" // Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c)
		"CalculateQuadrangleArea@6df9291b9dc382b\0" // Float CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d)
		"CalculateOutlineArea@15c8b802bcb27f63\0" // Float CalculateOutlineArea(const Block<const Vector>& outlinePoints)
		"CalculateOutlineNormal@b6c39610c515246b\0" // Vector CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized)
		"CalculateOutlineNormal@5e464640e4459cf6\0" // Vector CalculateOutlineNormal(const Block<const Vector>& points, Bool normalize)
		"IsVertexConvex@dcccc447955dede3\0" // Bool IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up)
		"IsVertexConvexExact@574c04c9e353120\0" // GEOMETRY_TEST_EXACT IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon)
		"CalculateMeanValueCoordinatesWeights@cdb141fa600a9232\0" // Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights)
		"CalculateMeanValueCoordinatesWeights@2a57a527f0bdc4c6\0" // Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights)
		"IsVertexConvex2D@f822e5da60d6f2ed\0" // Bool IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred)
		"IsVertexConvexExact2D@a23c28027e693dda\0" // GEOMETRY_TEST_EXACT IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon)
		"CalculateBarycentricCoordinate@d9b9a8eeae2eb0d0\0" // Vector2d CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
		"CalculateBarycentricCoordinate3D@c79a1a4f080ef36a\0" // Vector CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
		"PointInTriangle@dcccc447955dede3\0" // Bool PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c)
		"PointInTriangle2D@233874b0ef0bda8b\0" // Bool PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c)
		"GetPointInPolygonWindingNumber2D@ceb7101e2756de3d\0" // Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline)
		"GetPointInPolygonWindingNumber2DExact@ceb7101e2756de3d\0" // Int GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline)
		"GetPointInPolygonWindingNumber2D@154ea452e4e08d02\0" // Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit)
		"GetPointInPolygonWindingNumber@ae22e7d545be2379\0" // Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline)
		"GetPointInPolygonWindingNumber@fe7b0b4d973a6ae6\0" // Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline, Int& edgeHit)
		"PointInOutline2D@eb590f93eb6e4eed\0" // Bool PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline)
		"PointInOutlineRobust2D@eb590f93eb6e4eed\0" // Bool PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline)
		"CalculateBisector@630e23c8b56285f6\0" // Vector CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2)
		"CalculateCircumcenter2D@1753fca9680a1bfa\0" // Bool CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance)
		"CalculateCircumcenter@6e2baeb24651e572\0" // Bool CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance)
		"SegmentsIntersectionTest2D@233874b0ef0bda8b\0" // Bool SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2)
		"SegmentRayIntersectionTest2D@233874b0ef0bda8b\0" // Bool SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection)
		"IntersectSegments2D@30ce06f6f9ff6dd2\0" // Bool IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance)
		"LineLineDistance@e928ef3088da6406\0" // Vector LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance)
		"PointInSegment2D@420f41ae8feacd0b\0" // Bool PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance)
		"PointInSegment@fd86eee204942371\0" // Bool PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance)
		"PointInHalfLine@fd86eee204942371\0" // Bool PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance)
		"IntersectLines@3a69e71de0262724\0" // Bool IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance)
		"IntersectLineSegment@3a69e71de0262724\0" // Bool IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance)
		"IntersectSegments@3a69e71de0262724\0" // Bool IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance)
		"IntersectHalfLines@3a69e71de0262724\0" // Bool IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance)
		"IntersectLineHalfLine@3a69e71de0262724\0" // Bool IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance)
		"IntersectHalfLineSegment@3a69e71de0262724\0" // Bool IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance)
		"IntersectPlanes@b807868f350e6ec9\0" // Bool IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance)
		"IntersectLinePlane@3a69e71de0262724\0" // Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
		"IntersectLinePlane@6057ccc70664b790\0" // Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance)
		"IntersectSegmentPlane@3a69e71de0262724\0" // Bool IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
		"IntersectHalfLinePlane@3a69e71de0262724\0" // Bool IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance)
		"IntersectLineTriangle@e5d054e5e153b92b\0" // Bool IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance)
		"IntersectHalfLineTriangle@e5d054e5e153b92b\0" // Bool IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance)
		"IntersectLineQuadrangle@fa645beeaf052324\0" // Bool IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance)
		"IntersectHalfLineQuadrangle@fa645beeaf052324\0" // Bool IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance)
		"IntersectSegmentTriangle@c0bb5570ef02aad5\0" // Bool IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance)
		"TrianglesIntersectionTest@311b7152c1914571\0" // Bool TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance)
		"CalculatePolygonPointST@4fcc788dc2f39e65\0" // Bool CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance)
		"InverseBilinarInterpolate@b039df704292ddea\0" // void InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables)
		"InverseBilinarInterpolateNewton@3ae826743467f3da\0" // void InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables)
		"InverseBilinarInterpolate2D@cc8b4462cb1a3cc4\0" // void InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables)
		"InverseBilinarInterpolate2DNewton@2544b4de94fd6970\0" // void InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables)
		"BilinearInterpolate@cb91d98abfa1d7ca\0" // Vector BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t)
		"CalculateSignedTriangleArea@6df9291b9dc382b\0" // Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& normal)
		"CalculateMeanValueCoordinatesWeights@9dcf4be1f81a5f5a\0" // Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights)
		"CalculatePerimeterLength2D@3eae8148cbf295f5\0" // Float CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints)
		"IsWoundClockwise2D@877e936705fc1636\0" // Result<Bool> IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints)
		"CalculateOutlineCentroidAndArea2D@891c346814b6ef90\0" // Vector2d CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity)
		"CalculateMultiOutlineCentroidAndAreas2D@c9fafaa5b55f7613\0" // Result<Vector2d> CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity)
		"CalculateConvexHull2D@33918425ec9860ab\0" // Result<BaseArray<Int>> CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints)
		"CalculateConvexDecomposition2D@9d29db68ddafc051\0" // Result<BaseArray<BaseArray<Int>>> CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints)
		"CleanLoop2DInPlace@7083c5a00dca3171\0" // Result<Bool> CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart)
		"CalculateNoFitPolygonForConvex@2cf5d3784e26397d\0" // Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA)
		"CalculateNoFitPolygonUsingSliding@2cf5d3784e26397d\0" // Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA)
		"CalculateInnerFitPolygonUsingSliding@f600b22834667689\0" // Result<BaseArray<Vector2d>> CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB)
		"CalculateNoFitPolygonForConvex@ef35efc40ecc0955\0" // Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA)
		"CalculateNoFitPolygonUsingSliding@ef35efc40ecc0955\0" // Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA)
		"CalculateUnionOfPolygons@5e7daf7506a3dfb\0" // Result<BaseArray<BaseArray<Vector2d>>> CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop)
		"IntersectsSegmentsExact2D@b0ab6be3e003cff7\0" // Bool IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance)
		"GetContainmentStateForNonIntersectingLoops@25bd0a8f4309a767\0" // LOOP_OVERLAP_STATE GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB)
		"AreLoopsEqualToWithinTolerance@9157d5af79857f6\0" // Bool AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol)
		"CalculateBoundingBoxIndices@b1fe9a52a8b1d5e3\0" // void CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class GeometryUtilsInterface::Hxx2::Unresolved : public GeometryUtilsInterface
	{
	public:
		static const Unresolved* Get(const GeometryUtilsInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(GeometryUtilsInterface* o) { return (Unresolved*) o; }
		static Float LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::LinearRemapToRange(value, from1, to1, from2, to2); return 0;}
		static Float GetAngle2D(const Vector2d& direction1, const Vector2d& direction2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetAngle2D(direction1, direction2); return 0;}
		static Float InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InterpolatePointOnSegment(segmentPoint1, segmentPoint2, point, clamp); return 0;}
		static Float InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InterpolatePointOnSegment2D(segmentPoint1, segmentPoint2, point, clamp); return 0;}
		static Bool CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateBestFitPlane(pointCloud, centroid, normal, iterMax); return maxon::PrivateLogNullptrError(false);}
		static Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::Points3Dto2D(points, normal, basisVector0, basisVector1, translate, checkDegenerated, outPoints, computeBasis); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::Points3Dto2D(points, normal, checkDegenerated, outPoints); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Vector Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::Point2Dto3D(point, basisVector0, basisVector1, translate); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::Points2Dto3D(points, basisVector0, basisVector1, translate, outPoints); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Float CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateTriangleArea(a, b, c); return 0;}
		static Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateSignedTriangleArea(a, b, c); return 0;}
		static Float CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateQuadrangleArea(a, b, c, d); return 0;}
		static Float CalculateOutlineArea(const Block<const Vector>& outlinePoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateOutlineArea(outlinePoints); return 0;}
		static Vector CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateOutlineNormal(points, indices, normalized); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Vector CalculateOutlineNormal(const Block<const Vector>& points, Bool normalize) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateOutlineNormal(points, normalize); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IsVertexConvex(vertex, next, pred, up); return maxon::PrivateLogNullptrError(false);}
		static GEOMETRY_TEST_EXACT IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IsVertexConvexExact(vertex, next, pred, up, epsilon); return maxon::PrivateIncompleteNullReturnValue<GEOMETRY_TEST_EXACT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(point, outline, weights); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(point, points, outlineIndices, normal, weights); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IsVertexConvex2D(vertex, next, pred); return maxon::PrivateLogNullptrError(false);}
		static GEOMETRY_TEST_EXACT IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IsVertexConvexExact2D(vertex, next, pred, epsilon); return maxon::PrivateIncompleteNullReturnValue<GEOMETRY_TEST_EXACT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Vector2d CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateBarycentricCoordinate(point, a, b, c); return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Vector CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateBarycentricCoordinate3D(point, a, b, c); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInTriangle(point, a, b, c); return maxon::PrivateLogNullptrError(false);}
		static Bool PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInTriangle2D(point, a, b, c); return maxon::PrivateLogNullptrError(false);}
		static Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline); return 0;}
		static Int GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetPointInPolygonWindingNumber2DExact(std::forward<Vector2d>(point), outline); return 0;}
		static Int GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline, edgeHit); return 0;}
		static Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline); return 0;}
		static Int GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline, Int& edgeHit) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline, edgeHit); return 0;}
		static Bool PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInOutline2D(point, outline); return maxon::PrivateLogNullptrError(false);}
		static Bool PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInOutlineRobust2D(point, outline); return maxon::PrivateLogNullptrError(false);}
		static Vector CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateBisector(v1, v2, up, w1, w2); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateCircumcenter2D(a, b, c, center, sqrRad, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateCircumcenter(a, b, c, center, rad, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::SegmentsIntersectionTest2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2); return maxon::PrivateLogNullptrError(false);}
		static Bool SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::SegmentRayIntersectionTest2D(segmentPoint1, segmentPoint2, rayStartPoint, rayDirection); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectSegments2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Vector LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::LineLineDistance(line1Point, line1Dir, line2Point, line2Dir, parallel, param1, param2, tolerance); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInSegment2D(point, segmentPoint1, segmentPoint2, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInSegment(point, segmentPoint1, segmentPoint2, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::PointInHalfLine(point, halfLineOrigin, halfLineDir, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLines(line1Point, line1Dir, line2Point, line2Dir, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLineSegment(linePoint, lineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectSegments(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectHalfLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLineHalfLine(linePoint, lineDir, halfLineOrigin, halfLineDir, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectHalfLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectPlanes(plane1Point, plane1Normal, plane2Point, plane2Normal, resLinePoint, resLineDirection, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectSegmentPlane(segmentPoint1, segmentPoint2, planePoint, planeNormal, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectHalfLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, barycCoords, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, barycCoords, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectLineQuadrangle(linePoint, lineDir, a, b, c, d, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectHalfLineQuadrangle(halfLineOrigin, halfLineDir, a, b, c, d, intersectionPoint, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectSegmentTriangle(segmentPoint1, segmentPoint2, a, b, c, intersectionPoint, barycCoords, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::TrianglesIntersectionTest(t1a, t1b, t1c, t2a, t2b, t2c, tolerance); return maxon::PrivateLogNullptrError(false);}
		static Bool CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculatePolygonPointST(point, pa, pb, pc, pd, isQuad, s, t, tolerance); return maxon::PrivateLogNullptrError(false);}
		static void InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InverseBilinarInterpolate(pa, pb, pc, pd, point, bilinarVariables); return maxon::PrivateLogNullptrError();}
		static void InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InverseBilinarInterpolateNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); return maxon::PrivateLogNullptrError();}
		static void InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InverseBilinarInterpolate2D(pa, pb, pc, pd, point, bilinarVariables); return maxon::PrivateLogNullptrError();}
		static void InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::InverseBilinarInterpolate2DNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); return maxon::PrivateLogNullptrError();}
		static Vector BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::BilinearInterpolate(pa, pb, pc, pd, s, t); return maxon::PrivateIncompleteNullReturnValue<Vector>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Float CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& normal) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateSignedTriangleArea(a, b, c, normal); return 0;}
		static Result<void> CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(point, outline, normal, weights); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Float CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculatePerimeterLength2D(outlinePoints); return 0;}
		static Result<Bool> IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::IsWoundClockwise2D(outlinePoints); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Vector2d CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateOutlineCentroidAndArea2D(outlinePoints, area, windingPolarity); return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<Vector2d> CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateMultiOutlineCentroidAndAreas2D(loopVertices, loopVertexCounts, includeHolesInCogCalcs, overallArea, loopSoloAreas, windingPolarity); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Int>> CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateConvexHull2D(outlinePoints); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<BaseArray<Int>>> CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateConvexDecomposition2D(outlinePoints); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CleanLoop2DInPlace(outlinePoints, maintainStart); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, relativeBToA); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, relativeBToA); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Vector2d>> CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateInnerFitPolygonUsingSliding(outlinePointsCcwA, outlinePointsB); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Vector2d>> CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Vector2d>> CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<BaseArray<Vector2d>>> CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return GeometryUtilsInterface::CalculateUnionOfPolygons(outlinePointsA, outlinePointsB, includeHolesInResult, createOuterLoop); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::IntersectsSegmentsExact2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, areParallel, intersectionPoint2, tolerance); return maxon::PrivateLogNullptrError(false);}
		static LOOP_OVERLAP_STATE GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::GetContainmentStateForNonIntersectingLoops(outlinePointsA, outlinePointsB); return maxon::PrivateIncompleteNullReturnValue<LOOP_OVERLAP_STATE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::AreLoopsEqualToWithinTolerance(loopA, loopB, allowCyclicRotation, ignoreTranslationOffset, tol); return maxon::PrivateLogNullptrError(false);}
		static void CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return GeometryUtilsInterface::CalculateBoundingBoxIndices(verts, minIdxX, maxIdxX, minIdxY, maxIdxY, findMostCounterClockwise); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE GeometryUtilsInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<GEOMETRY_TEST_EXACT>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<GEOMETRY_TEST_EXACT>::value,
		maxon::details::NullReturnType<Vector2d>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Vector>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Vector2d>::value,
		maxon::details::NullReturnType<Result<Vector2d>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Int>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<BaseArray<Int>>>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value,
		maxon::details::NullReturnType<Result<BaseArray<BaseArray<Vector2d>>>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<LOOP_OVERLAP_STATE>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool GeometryUtilsInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_LinearRemapToRange = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_LinearRemapToRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetAngle2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetAngle2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InterpolatePointOnSegment = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InterpolatePointOnSegment;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InterpolatePointOnSegment2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InterpolatePointOnSegment2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateBestFitPlane = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBestFitPlane;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_Points3Dto2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points3Dto2D;
		#else
		tbl->_GeometryUtilsInterface_Points3Dto2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points3Dto2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_Points3Dto2D_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points3Dto2D_1;
		#else
		tbl->_GeometryUtilsInterface_Points3Dto2D_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points3Dto2D_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_Point2Dto3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Point2Dto3D;
		#else
		tbl->_GeometryUtilsInterface_Point2Dto3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Point2Dto3D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_Points2Dto3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points2Dto3D;
		#else
		tbl->_GeometryUtilsInterface_Points2Dto3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_Points2Dto3D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateTriangleArea = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateTriangleArea;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateSignedTriangleArea = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateSignedTriangleArea;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateQuadrangleArea = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateQuadrangleArea;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateOutlineArea = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineArea;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateOutlineNormal = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineNormal;
		#else
		tbl->_GeometryUtilsInterface_CalculateOutlineNormal = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineNormal;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateOutlineNormal_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineNormal_1;
		#else
		tbl->_GeometryUtilsInterface_CalculateOutlineNormal_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineNormal_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IsVertexConvex = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<GEOMETRY_TEST_EXACT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_IsVertexConvexExact = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvexExact;
		#else
		tbl->_GeometryUtilsInterface_IsVertexConvexExact = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvexExact;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights;
		#else
		tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1;
		#else
		tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IsVertexConvex2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvex2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<GEOMETRY_TEST_EXACT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_IsVertexConvexExact2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvexExact2D;
		#else
		tbl->_GeometryUtilsInterface_IsVertexConvexExact2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsVertexConvexExact2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateBarycentricCoordinate = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBarycentricCoordinate;
		#else
		tbl->_GeometryUtilsInterface_CalculateBarycentricCoordinate = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBarycentricCoordinate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateBarycentricCoordinate3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBarycentricCoordinate3D;
		#else
		tbl->_GeometryUtilsInterface_CalculateBarycentricCoordinate3D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBarycentricCoordinate3D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInTriangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInTriangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInTriangle2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInTriangle2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetPointInPolygonWindingNumber = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetPointInPolygonWindingNumber;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_GetPointInPolygonWindingNumber_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetPointInPolygonWindingNumber_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInOutline2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInOutline2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInOutlineRobust2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInOutlineRobust2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateBisector = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBisector;
		#else
		tbl->_GeometryUtilsInterface_CalculateBisector = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBisector;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateCircumcenter2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateCircumcenter2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateCircumcenter = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateCircumcenter;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_SegmentsIntersectionTest2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_SegmentsIntersectionTest2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_SegmentRayIntersectionTest2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_SegmentRayIntersectionTest2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectSegments2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectSegments2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_LineLineDistance = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_LineLineDistance;
		#else
		tbl->_GeometryUtilsInterface_LineLineDistance = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_LineLineDistance;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInSegment2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInSegment2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInSegment = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInSegment;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_PointInHalfLine = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_PointInHalfLine;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLines = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLines;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLineSegment = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLineSegment;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectSegments = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectSegments;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectHalfLines = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectHalfLines;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLineHalfLine = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLineHalfLine;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectHalfLineSegment = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectHalfLineSegment;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectPlanes = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectPlanes;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLinePlane = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLinePlane;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLinePlane_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLinePlane_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectSegmentPlane = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectSegmentPlane;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectHalfLinePlane = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectHalfLinePlane;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLineTriangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLineTriangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectHalfLineTriangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectHalfLineTriangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectLineQuadrangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectLineQuadrangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectHalfLineQuadrangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectHalfLineQuadrangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectSegmentTriangle = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectSegmentTriangle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_TrianglesIntersectionTest = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_TrianglesIntersectionTest;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculatePolygonPointST = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculatePolygonPointST;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InverseBilinarInterpolate = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InverseBilinarInterpolate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InverseBilinarInterpolateNewton = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InverseBilinarInterpolateNewton;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InverseBilinarInterpolate2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InverseBilinarInterpolate2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_InverseBilinarInterpolate2DNewton = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_InverseBilinarInterpolate2DNewton;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_BilinearInterpolate = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_BilinearInterpolate;
		#else
		tbl->_GeometryUtilsInterface_BilinearInterpolate = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_BilinearInterpolate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateSignedTriangleArea_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateSignedTriangleArea_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2;
		#else
		tbl->_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculatePerimeterLength2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculatePerimeterLength2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_IsWoundClockwise2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsWoundClockwise2D;
		#else
		tbl->_GeometryUtilsInterface_IsWoundClockwise2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IsWoundClockwise2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D;
		#else
		tbl->_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Vector2d>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D;
		#else
		tbl->_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Int>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateConvexHull2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateConvexHull2D;
		#else
		tbl->_GeometryUtilsInterface_CalculateConvexHull2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateConvexHull2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<BaseArray<Int>>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateConvexDecomposition2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateConvexDecomposition2D;
		#else
		tbl->_GeometryUtilsInterface_CalculateConvexDecomposition2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateConvexDecomposition2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CleanLoop2DInPlace = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CleanLoop2DInPlace;
		#else
		tbl->_GeometryUtilsInterface_CleanLoop2DInPlace = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CleanLoop2DInPlace;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateNoFitPolygonForConvex = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex;
		#else
		tbl->_GeometryUtilsInterface_CalculateNoFitPolygonForConvex = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding;
		#else
		tbl->_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding;
		#else
		tbl->_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1;
		#else
		tbl->_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Vector2d>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1;
		#else
		tbl->_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<BaseArray<Vector2d>>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_CalculateUnionOfPolygons = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateUnionOfPolygons;
		#else
		tbl->_GeometryUtilsInterface_CalculateUnionOfPolygons = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateUnionOfPolygons;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_IntersectsSegmentsExact2D = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_IntersectsSegmentsExact2D;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LOOP_OVERLAP_STATE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops;
		#else
		tbl->_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_AreLoopsEqualToWithinTolerance = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_AreLoopsEqualToWithinTolerance;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_GeometryUtilsInterface_CalculateBoundingBoxIndices = &Hxx2::Wrapper<Hxx2::Unresolved>::_GeometryUtilsInterface_CalculateBoundingBoxIndices;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(GeometryUtilsInterface, "net.maxon.geom.geometryutils", nullptr);
	template <typename DUMMY> maxon::Int GeometryUtilsInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<GEOMETRY_TEST_EXACT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<LOOP_OVERLAP_STATE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Vector>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Vector2d>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_geometryutils(0
	| maxon::GeometryUtilsInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
