
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DegeneratedInputErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DegeneratedInputErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DegeneratedInputErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DegeneratedInputErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
	};

};

auto DegeneratedInputErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DegeneratedInputErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DegeneratedInputErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DegeneratedInputErrorInterface() { new (s_ui_maxon_DegeneratedInputErrorInterface) maxon::EntityUse(DegeneratedInputErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/geometryutils.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DegeneratedInputErrorInterface(DegeneratedInputErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/geometryutils.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* GeometryUtilsInterface::PrivateGetCppName() { return nullptr; }

struct GeometryUtilsInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Float (*_GeometryUtilsInterface_LinearRemapToRange) (Float value, Float from1, Float to1, Float from2, Float to2);
	Float (*_GeometryUtilsInterface_GetAngle2D) (const Vector2d& direction1, const Vector2d& direction2);
	Float (*_GeometryUtilsInterface_InterpolatePointOnSegment) (const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp);
	Float (*_GeometryUtilsInterface_InterpolatePointOnSegment2D) (const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp);
	Bool (*_GeometryUtilsInterface_CalculateBestFitPlane) (const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax);
	Result<void> (*_GeometryUtilsInterface_Points3Dto2D) (const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis);
	Result<void> (*_GeometryUtilsInterface_Points3Dto2D_1) (const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints);
	Vector (*_GeometryUtilsInterface_Point2Dto3D) (const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate);
	Result<void> (*_GeometryUtilsInterface_Points2Dto3D) (const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints);
	Float (*_GeometryUtilsInterface_CalculateTriangleArea) (const Vector& a, const Vector& b, const Vector& c);
	Float (*_GeometryUtilsInterface_CalculateSignedTriangleArea) (const Vector& a, const Vector& b, const Vector& c);
	Float (*_GeometryUtilsInterface_CalculateQuadrangleArea) (const Vector& a, const Vector& b, const Vector& c, const Vector& d);
	Float (*_GeometryUtilsInterface_CalculateOutlineArea) (const Block<const Vector>& outlinePoints);
	Vector (*_GeometryUtilsInterface_CalculateOutlineNormal) (const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized);
	Vector (*_GeometryUtilsInterface_CalculateOutlineNormal_1) (const Block<const Vector>& points, Bool normalize);
	Bool (*_GeometryUtilsInterface_IsVertexConvex) (const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up);
	GEOMETRY_TEST_EXACT (*_GeometryUtilsInterface_IsVertexConvexExact) (const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon);
	Result<void> (*_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights) (const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights);
	Result<void> (*_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1) (const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights);
	Bool (*_GeometryUtilsInterface_IsVertexConvex2D) (const Vector2d& vertex, const Vector2d& next, const Vector2d& pred);
	GEOMETRY_TEST_EXACT (*_GeometryUtilsInterface_IsVertexConvexExact2D) (const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon);
	Vector2d (*_GeometryUtilsInterface_CalculateBarycentricCoordinate) (const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	Vector (*_GeometryUtilsInterface_CalculateBarycentricCoordinate3D) (const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	Bool (*_GeometryUtilsInterface_PointInTriangle) (const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	Bool (*_GeometryUtilsInterface_PointInTriangle2D) (const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c);
	Int (*_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D) (Vector2d point, const Block<const Vector2d>& outline);
	Int (*_GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact) (Vector2d point, const Block<const Vector2d>& outline);
	Int (*_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1) (Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit);
	Int (*_GeometryUtilsInterface_GetPointInPolygonWindingNumber) (Vector point, const Block<const Vector>& outline);
	Int (*_GeometryUtilsInterface_GetPointInPolygonWindingNumber_1) (Vector point, const Block<const Vector>& outline, Int& edgeHit);
	Bool (*_GeometryUtilsInterface_PointInOutline2D) (const Vector& point, const Block<const Vector2d>& outline);
	Bool (*_GeometryUtilsInterface_PointInOutlineRobust2D) (const Vector& point, const Block<const Vector2d>& outline);
	Vector (*_GeometryUtilsInterface_CalculateBisector) (const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2);
	Bool (*_GeometryUtilsInterface_CalculateCircumcenter2D) (const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance);
	Bool (*_GeometryUtilsInterface_CalculateCircumcenter) (const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance);
	Bool (*_GeometryUtilsInterface_SegmentsIntersectionTest2D) (const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2);
	Bool (*_GeometryUtilsInterface_SegmentRayIntersectionTest2D) (const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection);
	Bool (*_GeometryUtilsInterface_IntersectSegments2D) (const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance);
	Vector (*_GeometryUtilsInterface_LineLineDistance) (const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance);
	Bool (*_GeometryUtilsInterface_PointInSegment2D) (const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance);
	Bool (*_GeometryUtilsInterface_PointInSegment) (const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance);
	Bool (*_GeometryUtilsInterface_PointInHalfLine) (const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLines) (const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLineSegment) (const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectSegments) (const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectHalfLines) (const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLineHalfLine) (const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectHalfLineSegment) (const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectPlanes) (const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLinePlane) (const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLinePlane_1) (const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectSegmentPlane) (const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectHalfLinePlane) (const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLineTriangle) (const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectHalfLineTriangle) (const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectLineQuadrangle) (const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectHalfLineQuadrangle) (const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance);
	Bool (*_GeometryUtilsInterface_IntersectSegmentTriangle) (const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance);
	Bool (*_GeometryUtilsInterface_TrianglesIntersectionTest) (const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance);
	Bool (*_GeometryUtilsInterface_CalculatePolygonPointST) (const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance);
	void (*_GeometryUtilsInterface_InverseBilinarInterpolate) (const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables);
	void (*_GeometryUtilsInterface_InverseBilinarInterpolateNewton) (const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables);
	void (*_GeometryUtilsInterface_InverseBilinarInterpolate2D) (const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables);
	void (*_GeometryUtilsInterface_InverseBilinarInterpolate2DNewton) (const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables);
	Vector (*_GeometryUtilsInterface_BilinearInterpolate) (const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t);
	Float (*_GeometryUtilsInterface_CalculateSignedTriangleArea_1) (const Vector& a, const Vector& b, const Vector& c, const Vector& normal);
	Result<void> (*_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2) (const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights);
	Float (*_GeometryUtilsInterface_CalculatePerimeterLength2D) (const Block<const Vector2d>& outlinePoints);
	Result<Bool> (*_GeometryUtilsInterface_IsWoundClockwise2D) (const Block<const Vector2d>& outlinePoints);
	Vector2d (*_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D) (const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity);
	Result<Vector2d> (*_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D) (const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity);
	Result<BaseArray<Int>> (*_GeometryUtilsInterface_CalculateConvexHull2D) (const Block<const Vector2d>& outlinePoints);
	Result<BaseArray<BaseArray<Int>>> (*_GeometryUtilsInterface_CalculateConvexDecomposition2D) (const Block<const Vector2d>& outlinePoints);
	Result<Bool> (*_GeometryUtilsInterface_CleanLoop2DInPlace) (BaseArray<Vector2d>& outlinePoints, Bool maintainStart);
	Result<BaseArray<Vector2d>> (*_GeometryUtilsInterface_CalculateNoFitPolygonForConvex) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA);
	Result<BaseArray<Vector2d>> (*_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA);
	Result<BaseArray<Vector2d>> (*_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding) (const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB);
	Result<BaseArray<Vector2d>> (*_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA);
	Result<BaseArray<Vector2d>> (*_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA);
	Result<BaseArray<BaseArray<Vector2d>>> (*_GeometryUtilsInterface_CalculateUnionOfPolygons) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop);
	Bool (*_GeometryUtilsInterface_IntersectsSegmentsExact2D) (const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance);
	LOOP_OVERLAP_STATE (*_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops) (const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB);
	Bool (*_GeometryUtilsInterface_AreLoopsEqualToWithinTolerance) (const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol);
	void (*_GeometryUtilsInterface_CalculateBoundingBoxIndices) (const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise);
	template <typename IMPL> void Init()
	{
		_GeometryUtilsInterface_LinearRemapToRange = &IMPL::_GeometryUtilsInterface_LinearRemapToRange;
		_GeometryUtilsInterface_GetAngle2D = &IMPL::_GeometryUtilsInterface_GetAngle2D;
		_GeometryUtilsInterface_InterpolatePointOnSegment = &IMPL::_GeometryUtilsInterface_InterpolatePointOnSegment;
		_GeometryUtilsInterface_InterpolatePointOnSegment2D = &IMPL::_GeometryUtilsInterface_InterpolatePointOnSegment2D;
		_GeometryUtilsInterface_CalculateBestFitPlane = &IMPL::_GeometryUtilsInterface_CalculateBestFitPlane;
		_GeometryUtilsInterface_Points3Dto2D = &IMPL::_GeometryUtilsInterface_Points3Dto2D;
		_GeometryUtilsInterface_Points3Dto2D_1 = &IMPL::_GeometryUtilsInterface_Points3Dto2D_1;
		_GeometryUtilsInterface_Point2Dto3D = &IMPL::_GeometryUtilsInterface_Point2Dto3D;
		_GeometryUtilsInterface_Points2Dto3D = &IMPL::_GeometryUtilsInterface_Points2Dto3D;
		_GeometryUtilsInterface_CalculateTriangleArea = &IMPL::_GeometryUtilsInterface_CalculateTriangleArea;
		_GeometryUtilsInterface_CalculateSignedTriangleArea = &IMPL::_GeometryUtilsInterface_CalculateSignedTriangleArea;
		_GeometryUtilsInterface_CalculateQuadrangleArea = &IMPL::_GeometryUtilsInterface_CalculateQuadrangleArea;
		_GeometryUtilsInterface_CalculateOutlineArea = &IMPL::_GeometryUtilsInterface_CalculateOutlineArea;
		_GeometryUtilsInterface_CalculateOutlineNormal = &IMPL::_GeometryUtilsInterface_CalculateOutlineNormal;
		_GeometryUtilsInterface_CalculateOutlineNormal_1 = &IMPL::_GeometryUtilsInterface_CalculateOutlineNormal_1;
		_GeometryUtilsInterface_IsVertexConvex = &IMPL::_GeometryUtilsInterface_IsVertexConvex;
		_GeometryUtilsInterface_IsVertexConvexExact = &IMPL::_GeometryUtilsInterface_IsVertexConvexExact;
		_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights = &IMPL::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights;
		_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1 = &IMPL::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1;
		_GeometryUtilsInterface_IsVertexConvex2D = &IMPL::_GeometryUtilsInterface_IsVertexConvex2D;
		_GeometryUtilsInterface_IsVertexConvexExact2D = &IMPL::_GeometryUtilsInterface_IsVertexConvexExact2D;
		_GeometryUtilsInterface_CalculateBarycentricCoordinate = &IMPL::_GeometryUtilsInterface_CalculateBarycentricCoordinate;
		_GeometryUtilsInterface_CalculateBarycentricCoordinate3D = &IMPL::_GeometryUtilsInterface_CalculateBarycentricCoordinate3D;
		_GeometryUtilsInterface_PointInTriangle = &IMPL::_GeometryUtilsInterface_PointInTriangle;
		_GeometryUtilsInterface_PointInTriangle2D = &IMPL::_GeometryUtilsInterface_PointInTriangle2D;
		_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D = &IMPL::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D;
		_GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact = &IMPL::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact;
		_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1 = &IMPL::_GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1;
		_GeometryUtilsInterface_GetPointInPolygonWindingNumber = &IMPL::_GeometryUtilsInterface_GetPointInPolygonWindingNumber;
		_GeometryUtilsInterface_GetPointInPolygonWindingNumber_1 = &IMPL::_GeometryUtilsInterface_GetPointInPolygonWindingNumber_1;
		_GeometryUtilsInterface_PointInOutline2D = &IMPL::_GeometryUtilsInterface_PointInOutline2D;
		_GeometryUtilsInterface_PointInOutlineRobust2D = &IMPL::_GeometryUtilsInterface_PointInOutlineRobust2D;
		_GeometryUtilsInterface_CalculateBisector = &IMPL::_GeometryUtilsInterface_CalculateBisector;
		_GeometryUtilsInterface_CalculateCircumcenter2D = &IMPL::_GeometryUtilsInterface_CalculateCircumcenter2D;
		_GeometryUtilsInterface_CalculateCircumcenter = &IMPL::_GeometryUtilsInterface_CalculateCircumcenter;
		_GeometryUtilsInterface_SegmentsIntersectionTest2D = &IMPL::_GeometryUtilsInterface_SegmentsIntersectionTest2D;
		_GeometryUtilsInterface_SegmentRayIntersectionTest2D = &IMPL::_GeometryUtilsInterface_SegmentRayIntersectionTest2D;
		_GeometryUtilsInterface_IntersectSegments2D = &IMPL::_GeometryUtilsInterface_IntersectSegments2D;
		_GeometryUtilsInterface_LineLineDistance = &IMPL::_GeometryUtilsInterface_LineLineDistance;
		_GeometryUtilsInterface_PointInSegment2D = &IMPL::_GeometryUtilsInterface_PointInSegment2D;
		_GeometryUtilsInterface_PointInSegment = &IMPL::_GeometryUtilsInterface_PointInSegment;
		_GeometryUtilsInterface_PointInHalfLine = &IMPL::_GeometryUtilsInterface_PointInHalfLine;
		_GeometryUtilsInterface_IntersectLines = &IMPL::_GeometryUtilsInterface_IntersectLines;
		_GeometryUtilsInterface_IntersectLineSegment = &IMPL::_GeometryUtilsInterface_IntersectLineSegment;
		_GeometryUtilsInterface_IntersectSegments = &IMPL::_GeometryUtilsInterface_IntersectSegments;
		_GeometryUtilsInterface_IntersectHalfLines = &IMPL::_GeometryUtilsInterface_IntersectHalfLines;
		_GeometryUtilsInterface_IntersectLineHalfLine = &IMPL::_GeometryUtilsInterface_IntersectLineHalfLine;
		_GeometryUtilsInterface_IntersectHalfLineSegment = &IMPL::_GeometryUtilsInterface_IntersectHalfLineSegment;
		_GeometryUtilsInterface_IntersectPlanes = &IMPL::_GeometryUtilsInterface_IntersectPlanes;
		_GeometryUtilsInterface_IntersectLinePlane = &IMPL::_GeometryUtilsInterface_IntersectLinePlane;
		_GeometryUtilsInterface_IntersectLinePlane_1 = &IMPL::_GeometryUtilsInterface_IntersectLinePlane_1;
		_GeometryUtilsInterface_IntersectSegmentPlane = &IMPL::_GeometryUtilsInterface_IntersectSegmentPlane;
		_GeometryUtilsInterface_IntersectHalfLinePlane = &IMPL::_GeometryUtilsInterface_IntersectHalfLinePlane;
		_GeometryUtilsInterface_IntersectLineTriangle = &IMPL::_GeometryUtilsInterface_IntersectLineTriangle;
		_GeometryUtilsInterface_IntersectHalfLineTriangle = &IMPL::_GeometryUtilsInterface_IntersectHalfLineTriangle;
		_GeometryUtilsInterface_IntersectLineQuadrangle = &IMPL::_GeometryUtilsInterface_IntersectLineQuadrangle;
		_GeometryUtilsInterface_IntersectHalfLineQuadrangle = &IMPL::_GeometryUtilsInterface_IntersectHalfLineQuadrangle;
		_GeometryUtilsInterface_IntersectSegmentTriangle = &IMPL::_GeometryUtilsInterface_IntersectSegmentTriangle;
		_GeometryUtilsInterface_TrianglesIntersectionTest = &IMPL::_GeometryUtilsInterface_TrianglesIntersectionTest;
		_GeometryUtilsInterface_CalculatePolygonPointST = &IMPL::_GeometryUtilsInterface_CalculatePolygonPointST;
		_GeometryUtilsInterface_InverseBilinarInterpolate = &IMPL::_GeometryUtilsInterface_InverseBilinarInterpolate;
		_GeometryUtilsInterface_InverseBilinarInterpolateNewton = &IMPL::_GeometryUtilsInterface_InverseBilinarInterpolateNewton;
		_GeometryUtilsInterface_InverseBilinarInterpolate2D = &IMPL::_GeometryUtilsInterface_InverseBilinarInterpolate2D;
		_GeometryUtilsInterface_InverseBilinarInterpolate2DNewton = &IMPL::_GeometryUtilsInterface_InverseBilinarInterpolate2DNewton;
		_GeometryUtilsInterface_BilinearInterpolate = &IMPL::_GeometryUtilsInterface_BilinearInterpolate;
		_GeometryUtilsInterface_CalculateSignedTriangleArea_1 = &IMPL::_GeometryUtilsInterface_CalculateSignedTriangleArea_1;
		_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2 = &IMPL::_GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2;
		_GeometryUtilsInterface_CalculatePerimeterLength2D = &IMPL::_GeometryUtilsInterface_CalculatePerimeterLength2D;
		_GeometryUtilsInterface_IsWoundClockwise2D = &IMPL::_GeometryUtilsInterface_IsWoundClockwise2D;
		_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D = &IMPL::_GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D;
		_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D = &IMPL::_GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D;
		_GeometryUtilsInterface_CalculateConvexHull2D = &IMPL::_GeometryUtilsInterface_CalculateConvexHull2D;
		_GeometryUtilsInterface_CalculateConvexDecomposition2D = &IMPL::_GeometryUtilsInterface_CalculateConvexDecomposition2D;
		_GeometryUtilsInterface_CleanLoop2DInPlace = &IMPL::_GeometryUtilsInterface_CleanLoop2DInPlace;
		_GeometryUtilsInterface_CalculateNoFitPolygonForConvex = &IMPL::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex;
		_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding = &IMPL::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding;
		_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding = &IMPL::_GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding;
		_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1 = &IMPL::_GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1;
		_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1 = &IMPL::_GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1;
		_GeometryUtilsInterface_CalculateUnionOfPolygons = &IMPL::_GeometryUtilsInterface_CalculateUnionOfPolygons;
		_GeometryUtilsInterface_IntersectsSegmentsExact2D = &IMPL::_GeometryUtilsInterface_IntersectsSegmentsExact2D;
		_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops = &IMPL::_GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops;
		_GeometryUtilsInterface_AreLoopsEqualToWithinTolerance = &IMPL::_GeometryUtilsInterface_AreLoopsEqualToWithinTolerance;
		_GeometryUtilsInterface_CalculateBoundingBoxIndices = &IMPL::_GeometryUtilsInterface_CalculateBoundingBoxIndices;
	}
};

struct GeometryUtilsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Float _GeometryUtilsInterface_LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2) { return C::LinearRemapToRange(value, from1, to1, from2, to2); }
		static Float _GeometryUtilsInterface_GetAngle2D(const Vector2d& direction1, const Vector2d& direction2) { return C::GetAngle2D(direction1, direction2); }
		static Float _GeometryUtilsInterface_InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp) { return C::InterpolatePointOnSegment(segmentPoint1, segmentPoint2, point, clamp); }
		static Float _GeometryUtilsInterface_InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp) { return C::InterpolatePointOnSegment2D(segmentPoint1, segmentPoint2, point, clamp); }
		static Bool _GeometryUtilsInterface_CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax) { return C::CalculateBestFitPlane(pointCloud, centroid, normal, iterMax); }
		static Result<void> _GeometryUtilsInterface_Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis) { return C::Points3Dto2D(points, normal, basisVector0, basisVector1, translate, checkDegenerated, outPoints, computeBasis); }
		static Result<void> _GeometryUtilsInterface_Points3Dto2D_1(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints) { return C::Points3Dto2D(points, normal, checkDegenerated, outPoints); }
		static Vector _GeometryUtilsInterface_Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate) { return C::Point2Dto3D(point, basisVector0, basisVector1, translate); }
		static Result<void> _GeometryUtilsInterface_Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints) { return C::Points2Dto3D(points, basisVector0, basisVector1, translate, outPoints); }
		static Float _GeometryUtilsInterface_CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c) { return C::CalculateTriangleArea(a, b, c); }
		static Float _GeometryUtilsInterface_CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c) { return C::CalculateSignedTriangleArea(a, b, c); }
		static Float _GeometryUtilsInterface_CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d) { return C::CalculateQuadrangleArea(a, b, c, d); }
		static Float _GeometryUtilsInterface_CalculateOutlineArea(const Block<const Vector>& outlinePoints) { return C::CalculateOutlineArea(outlinePoints); }
		static Vector _GeometryUtilsInterface_CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized) { return C::CalculateOutlineNormal(points, indices, normalized); }
		static Vector _GeometryUtilsInterface_CalculateOutlineNormal_1(const Block<const Vector>& points, Bool normalize) { return C::CalculateOutlineNormal(points, normalize); }
		static Bool _GeometryUtilsInterface_IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up) { return C::IsVertexConvex(vertex, next, pred, up); }
		static GEOMETRY_TEST_EXACT _GeometryUtilsInterface_IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon) { return C::IsVertexConvexExact(vertex, next, pred, up, epsilon); }
		static Result<void> _GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, outline, weights); }
		static Result<void> _GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, points, outlineIndices, normal, weights); }
		static Bool _GeometryUtilsInterface_IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred) { return C::IsVertexConvex2D(vertex, next, pred); }
		static GEOMETRY_TEST_EXACT _GeometryUtilsInterface_IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon) { return C::IsVertexConvexExact2D(vertex, next, pred, epsilon); }
		static Vector2d _GeometryUtilsInterface_CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::CalculateBarycentricCoordinate(point, a, b, c); }
		static Vector _GeometryUtilsInterface_CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::CalculateBarycentricCoordinate3D(point, a, b, c); }
		static Bool _GeometryUtilsInterface_PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::PointInTriangle(point, a, b, c); }
		static Bool _GeometryUtilsInterface_PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c) { return C::PointInTriangle2D(point, a, b, c); }
		static Int _GeometryUtilsInterface_GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline) { return C::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline); }
		static Int _GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline) { return C::GetPointInPolygonWindingNumber2DExact(std::forward<Vector2d>(point), outline); }
		static Int _GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit) { return C::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline, edgeHit); }
		static Int _GeometryUtilsInterface_GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline) { return C::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline); }
		static Int _GeometryUtilsInterface_GetPointInPolygonWindingNumber_1(Vector point, const Block<const Vector>& outline, Int& edgeHit) { return C::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline, edgeHit); }
		static Bool _GeometryUtilsInterface_PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline) { return C::PointInOutline2D(point, outline); }
		static Bool _GeometryUtilsInterface_PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline) { return C::PointInOutlineRobust2D(point, outline); }
		static Vector _GeometryUtilsInterface_CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2) { return C::CalculateBisector(v1, v2, up, w1, w2); }
		static Bool _GeometryUtilsInterface_CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance) { return C::CalculateCircumcenter2D(a, b, c, center, sqrRad, tolerance); }
		static Bool _GeometryUtilsInterface_CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance) { return C::CalculateCircumcenter(a, b, c, center, rad, tolerance); }
		static Bool _GeometryUtilsInterface_SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2) { return C::SegmentsIntersectionTest2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2); }
		static Bool _GeometryUtilsInterface_SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection) { return C::SegmentRayIntersectionTest2D(segmentPoint1, segmentPoint2, rayStartPoint, rayDirection); }
		static Bool _GeometryUtilsInterface_IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance) { return C::IntersectSegments2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); }
		static Vector _GeometryUtilsInterface_LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance) { return C::LineLineDistance(line1Point, line1Dir, line2Point, line2Dir, parallel, param1, param2, tolerance); }
		static Bool _GeometryUtilsInterface_PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance) { return C::PointInSegment2D(point, segmentPoint1, segmentPoint2, tolerance); }
		static Bool _GeometryUtilsInterface_PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance) { return C::PointInSegment(point, segmentPoint1, segmentPoint2, tolerance); }
		static Bool _GeometryUtilsInterface_PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance) { return C::PointInHalfLine(point, halfLineOrigin, halfLineDir, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance) { return C::IntersectLines(line1Point, line1Dir, line2Point, line2Dir, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineSegment(linePoint, lineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance) { return C::IntersectSegments(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineHalfLine(linePoint, lineDir, halfLineOrigin, halfLineDir, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance) { return C::IntersectPlanes(plane1Point, plane1Normal, plane2Point, plane2Normal, resLinePoint, resLineDirection, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLinePlane_1(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance) { return C::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectSegmentPlane(segmentPoint1, segmentPoint2, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { return C::IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { return C::IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineQuadrangle(linePoint, lineDir, a, b, c, d, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLineQuadrangle(halfLineOrigin, halfLineDir, a, b, c, d, intersectionPoint, tolerance); }
		static Bool _GeometryUtilsInterface_IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance) { return C::IntersectSegmentTriangle(segmentPoint1, segmentPoint2, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool _GeometryUtilsInterface_TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance) { return C::TrianglesIntersectionTest(t1a, t1b, t1c, t2a, t2b, t2c, tolerance); }
		static Bool _GeometryUtilsInterface_CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance) { return C::CalculatePolygonPointST(point, pa, pb, pc, pd, isQuad, s, t, tolerance); }
		static void _GeometryUtilsInterface_InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate(pa, pb, pc, pd, point, bilinarVariables); }
		static void _GeometryUtilsInterface_InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolateNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); }
		static void _GeometryUtilsInterface_InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate2D(pa, pb, pc, pd, point, bilinarVariables); }
		static void _GeometryUtilsInterface_InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate2DNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); }
		static Vector _GeometryUtilsInterface_BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t) { return C::BilinearInterpolate(pa, pb, pc, pd, s, t); }
		static Float _GeometryUtilsInterface_CalculateSignedTriangleArea_1(const Vector& a, const Vector& b, const Vector& c, const Vector& normal) { return C::CalculateSignedTriangleArea(a, b, c, normal); }
		static Result<void> _GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, outline, normal, weights); }
		static Float _GeometryUtilsInterface_CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints) { return C::CalculatePerimeterLength2D(outlinePoints); }
		static Result<Bool> _GeometryUtilsInterface_IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints) { return C::IsWoundClockwise2D(outlinePoints); }
		static Vector2d _GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity) { return C::CalculateOutlineCentroidAndArea2D(outlinePoints, area, windingPolarity); }
		static Result<Vector2d> _GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity) { return C::CalculateMultiOutlineCentroidAndAreas2D(loopVertices, loopVertexCounts, includeHolesInCogCalcs, overallArea, loopSoloAreas, windingPolarity); }
		static Result<BaseArray<Int>> _GeometryUtilsInterface_CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints) { return C::CalculateConvexHull2D(outlinePoints); }
		static Result<BaseArray<BaseArray<Int>>> _GeometryUtilsInterface_CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints) { return C::CalculateConvexDecomposition2D(outlinePoints); }
		static Result<Bool> _GeometryUtilsInterface_CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart) { return C::CleanLoop2DInPlace(outlinePoints, maintainStart); }
		static Result<BaseArray<Vector2d>> _GeometryUtilsInterface_CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { return C::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, relativeBToA); }
		static Result<BaseArray<Vector2d>> _GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { return C::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, relativeBToA); }
		static Result<BaseArray<Vector2d>> _GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB) { return C::CalculateInnerFitPolygonUsingSliding(outlinePointsCcwA, outlinePointsB); }
		static Result<BaseArray<Vector2d>> _GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { return C::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); }
		static Result<BaseArray<Vector2d>> _GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { return C::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); }
		static Result<BaseArray<BaseArray<Vector2d>>> _GeometryUtilsInterface_CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop) { return C::CalculateUnionOfPolygons(outlinePointsA, outlinePointsB, includeHolesInResult, createOuterLoop); }
		static Bool _GeometryUtilsInterface_IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance) { return C::IntersectsSegmentsExact2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, areParallel, intersectionPoint2, tolerance); }
		static LOOP_OVERLAP_STATE _GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB) { return C::GetContainmentStateForNonIntersectingLoops(outlinePointsA, outlinePointsB); }
		static Bool _GeometryUtilsInterface_AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol) { return C::AreLoopsEqualToWithinTolerance(loopA, loopB, allowCyclicRotation, ignoreTranslationOffset, tol); }
		static void _GeometryUtilsInterface_CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise) { return C::CalculateBoundingBoxIndices(verts, minIdxX, maxIdxX, minIdxY, maxIdxY, findMostCounterClockwise); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_LinearRemapToRange(value, from1, to1, from2, to2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetAngle2D(const Vector2d& direction1, const Vector2d& direction2) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_GetAngle2D(direction1, direction2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_InterpolatePointOnSegment(segmentPoint1, segmentPoint2, point, clamp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_InterpolatePointOnSegment2D(segmentPoint1, segmentPoint2, point, clamp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_CalculateBestFitPlane(pointCloud, centroid, normal, iterMax);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_Points3Dto2D(points, normal, basisVector0, basisVector1, translate, checkDegenerated, outPoints, computeBasis);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_Points3Dto2D_1(points, normal, checkDegenerated, outPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_Point2Dto3D(point, basisVector0, basisVector1, translate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_Points2Dto3D(points, basisVector0, basisVector1, translate, outPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculateTriangleArea(a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculateSignedTriangleArea(a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculateQuadrangleArea(a, b, c, d);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineArea(const Block<const Vector>& outlinePoints) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculateOutlineArea(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_CalculateOutlineNormal(points, indices, normalized);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineNormal(const Block<const Vector>& points, Bool normalize) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_CalculateOutlineNormal_1(points, normalize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IsVertexConvex(vertex, next, pred, up);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon) -> GEOMETRY_TEST_EXACT
{
	return MTable::_instance._GeometryUtilsInterface_IsVertexConvexExact(vertex, next, pred, up, epsilon);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights(point, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1(point, points, outlineIndices, normal, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IsVertexConvex2D(vertex, next, pred);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon) -> GEOMETRY_TEST_EXACT
{
	return MTable::_instance._GeometryUtilsInterface_IsVertexConvexExact2D(vertex, next, pred, epsilon);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Vector2d
{
	return MTable::_instance._GeometryUtilsInterface_CalculateBarycentricCoordinate(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_CalculateBarycentricCoordinate3D(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInTriangle(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInTriangle2D(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline) -> Int
{
	return MTable::_instance._GeometryUtilsInterface_GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline) -> Int
{
	return MTable::_instance._GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact(std::forward<Vector2d>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit) -> Int
{
	return MTable::_instance._GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1(std::forward<Vector2d>(point), outline, edgeHit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline) -> Int
{
	return MTable::_instance._GeometryUtilsInterface_GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline, Int& edgeHit) -> Int
{
	return MTable::_instance._GeometryUtilsInterface_GetPointInPolygonWindingNumber_1(std::forward<Vector>(point), outline, edgeHit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInOutline2D(point, outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInOutlineRobust2D(point, outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_CalculateBisector(v1, v2, up, w1, w2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_CalculateCircumcenter2D(a, b, c, center, sqrRad, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_CalculateCircumcenter(a, b, c, center, rad, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_SegmentsIntersectionTest2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_SegmentRayIntersectionTest2D(segmentPoint1, segmentPoint2, rayStartPoint, rayDirection);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectSegments2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_LineLineDistance(line1Point, line1Dir, line2Point, line2Dir, parallel, param1, param2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInSegment2D(point, segmentPoint1, segmentPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInSegment(point, segmentPoint1, segmentPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_PointInHalfLine(point, halfLineOrigin, halfLineDir, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLines(line1Point, line1Dir, line2Point, line2Dir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLineSegment(linePoint, lineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectSegments(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectHalfLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLineHalfLine(linePoint, lineDir, halfLineOrigin, halfLineDir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectHalfLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectPlanes(plane1Point, plane1Normal, plane2Point, plane2Normal, resLinePoint, resLineDirection, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLinePlane_1(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectSegmentPlane(segmentPoint1, segmentPoint2, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectHalfLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectLineQuadrangle(linePoint, lineDir, a, b, c, d, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectHalfLineQuadrangle(halfLineOrigin, halfLineDir, a, b, c, d, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectSegmentTriangle(segmentPoint1, segmentPoint2, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_TrianglesIntersectionTest(t1a, t1b, t1c, t2a, t2b, t2c, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_CalculatePolygonPointST(point, pa, pb, pc, pd, isQuad, s, t, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance._GeometryUtilsInterface_InverseBilinarInterpolate(pa, pb, pc, pd, point, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance._GeometryUtilsInterface_InverseBilinarInterpolateNewton(pa, pb, pc, pd, point, iterations, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance._GeometryUtilsInterface_InverseBilinarInterpolate2D(pa, pb, pc, pd, point, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance._GeometryUtilsInterface_InverseBilinarInterpolate2DNewton(pa, pb, pc, pd, point, iterations, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t) -> Vector
{
	return MTable::_instance._GeometryUtilsInterface_BilinearInterpolate(pa, pb, pc, pd, s, t);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& normal) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculateSignedTriangleArea_1(a, b, c, normal);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2(point, outline, normal, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints) -> Float
{
	return MTable::_instance._GeometryUtilsInterface_CalculatePerimeterLength2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints) -> Result<Bool>
{
	return MTable::_instance._GeometryUtilsInterface_IsWoundClockwise2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity) -> Vector2d
{
	return MTable::_instance._GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D(outlinePoints, area, windingPolarity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity) -> Result<Vector2d>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D(loopVertices, loopVertexCounts, includeHolesInCogCalcs, overallArea, loopSoloAreas, windingPolarity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints) -> Result<BaseArray<Int>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateConvexHull2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints) -> Result<BaseArray<BaseArray<Int>>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateConvexDecomposition2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart) -> Result<Bool>
{
	return MTable::_instance._GeometryUtilsInterface_CleanLoop2DInPlace(outlinePoints, maintainStart);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding(outlinePointsCcwA, outlinePointsB);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop) -> Result<BaseArray<BaseArray<Vector2d>>>
{
	return MTable::_instance._GeometryUtilsInterface_CalculateUnionOfPolygons(outlinePointsA, outlinePointsB, includeHolesInResult, createOuterLoop);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_IntersectsSegmentsExact2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, areParallel, intersectionPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB) -> LOOP_OVERLAP_STATE
{
	return MTable::_instance._GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops(outlinePointsA, outlinePointsB);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol) -> Bool
{
	return MTable::_instance._GeometryUtilsInterface_AreLoopsEqualToWithinTolerance(loopA, loopB, allowCyclicRotation, ignoreTranslationOffset, tol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise) -> void
{
	return MTable::_instance._GeometryUtilsInterface_CalculateBoundingBoxIndices(verts, minIdxX, maxIdxX, minIdxY, maxIdxY, findMostCounterClockwise);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_GeometryUtilsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_GeometryUtilsInterface() { new (s_ui_maxon_GeometryUtilsInterface) maxon::EntityUse(GeometryUtilsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/geometryutils.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_GeometryUtilsInterface(GeometryUtilsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/geometryutils.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

