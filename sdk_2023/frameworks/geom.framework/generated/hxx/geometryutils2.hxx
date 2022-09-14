
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DegeneratedInputErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DegeneratedInputErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DegeneratedInputErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DegeneratedInputErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DegeneratedInputErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto DegeneratedInputErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DegeneratedInputErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_geometryutils)
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
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_LinearRemapToRange, LinearRemapToRange, MAXON_EXPAND_VA_ARGS, (Float), Float value, Float from1, Float to1, Float from2, Float to2);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetAngle2D, GetAngle2D, MAXON_EXPAND_VA_ARGS, (Float), const Vector2d& direction1, const Vector2d& direction2);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InterpolatePointOnSegment, InterpolatePointOnSegment, MAXON_EXPAND_VA_ARGS, (Float), const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InterpolatePointOnSegment2D, InterpolatePointOnSegment2D, MAXON_EXPAND_VA_ARGS, (Float), const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateBestFitPlane, CalculateBestFitPlane, MAXON_EXPAND_VA_ARGS, (Bool), const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_Points3Dto2D, Points3Dto2D, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_Points3Dto2D_1, Points3Dto2D, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_Point2Dto3D, Point2Dto3D, MAXON_EXPAND_VA_ARGS, (Vector), const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_Points2Dto3D, Points2Dto3D, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateTriangleArea, CalculateTriangleArea, MAXON_EXPAND_VA_ARGS, (Float), const Vector& a, const Vector& b, const Vector& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateSignedTriangleArea, CalculateSignedTriangleArea, MAXON_EXPAND_VA_ARGS, (Float), const Vector& a, const Vector& b, const Vector& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateQuadrangleArea, CalculateQuadrangleArea, MAXON_EXPAND_VA_ARGS, (Float), const Vector& a, const Vector& b, const Vector& c, const Vector& d);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateOutlineArea, CalculateOutlineArea, MAXON_EXPAND_VA_ARGS, (Float), const Block<const Vector>& outlinePoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateOutlineNormal, CalculateOutlineNormal, MAXON_EXPAND_VA_ARGS, (Vector), const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateOutlineNormal_1, CalculateOutlineNormal, MAXON_EXPAND_VA_ARGS, (Vector), const Block<const Vector>& points, Bool normalize);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IsVertexConvex, IsVertexConvex, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IsVertexConvexExact, IsVertexConvexExact, MAXON_EXPAND_VA_ARGS, (GEOMETRY_TEST_EXACT), const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights, CalculateMeanValueCoordinatesWeights, MAXON_EXPAND_VA_ARGS, (Result<void>), const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1, CalculateMeanValueCoordinatesWeights, MAXON_EXPAND_VA_ARGS, (Result<void>), const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IsVertexConvex2D, IsVertexConvex2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& vertex, const Vector2d& next, const Vector2d& pred);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IsVertexConvexExact2D, IsVertexConvexExact2D, MAXON_EXPAND_VA_ARGS, (GEOMETRY_TEST_EXACT), const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateBarycentricCoordinate, CalculateBarycentricCoordinate, MAXON_EXPAND_VA_ARGS, (Vector2d), const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateBarycentricCoordinate3D, CalculateBarycentricCoordinate3D, MAXON_EXPAND_VA_ARGS, (Vector), const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInTriangle, PointInTriangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Vector& a, const Vector& b, const Vector& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInTriangle2D, PointInTriangle2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetPointInPolygonWindingNumber2D, GetPointInPolygonWindingNumber2D, MAXON_EXPAND_VA_ARGS, (Int), Vector2d point, const Block<const Vector2d>& outline);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact, GetPointInPolygonWindingNumber2DExact, MAXON_EXPAND_VA_ARGS, (Int), Vector2d point, const Block<const Vector2d>& outline);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1, GetPointInPolygonWindingNumber2D, MAXON_EXPAND_VA_ARGS, (Int), Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetPointInPolygonWindingNumber, GetPointInPolygonWindingNumber, MAXON_EXPAND_VA_ARGS, (Int), Vector point, const Block<const Vector>& outline);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetPointInPolygonWindingNumber_1, GetPointInPolygonWindingNumber, MAXON_EXPAND_VA_ARGS, (Int), Vector point, const Block<const Vector>& outline, Int& edgeHit);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInOutline2D, PointInOutline2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Block<const Vector2d>& outline);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInOutlineRobust2D, PointInOutlineRobust2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Block<const Vector2d>& outline);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateBisector, CalculateBisector, MAXON_EXPAND_VA_ARGS, (Vector), const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateCircumcenter2D, CalculateCircumcenter2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateCircumcenter, CalculateCircumcenter, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_SegmentsIntersectionTest2D, SegmentsIntersectionTest2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_SegmentRayIntersectionTest2D, SegmentRayIntersectionTest2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectSegments2D, IntersectSegments2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_LineLineDistance, LineLineDistance, MAXON_EXPAND_VA_ARGS, (Vector), const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInSegment2D, PointInSegment2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInSegment, PointInSegment, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_PointInHalfLine, PointInHalfLine, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLines, IntersectLines, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLineSegment, IntersectLineSegment, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectSegments, IntersectSegments, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectHalfLines, IntersectHalfLines, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLineHalfLine, IntersectLineHalfLine, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectHalfLineSegment, IntersectHalfLineSegment, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectPlanes, IntersectPlanes, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLinePlane, IntersectLinePlane, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLinePlane_1, IntersectLinePlane, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectSegmentPlane, IntersectSegmentPlane, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectHalfLinePlane, IntersectHalfLinePlane, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLineTriangle, IntersectLineTriangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectHalfLineTriangle, IntersectHalfLineTriangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectLineQuadrangle, IntersectLineQuadrangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectHalfLineQuadrangle, IntersectHalfLineQuadrangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectSegmentTriangle, IntersectSegmentTriangle, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_TrianglesIntersectionTest, TrianglesIntersectionTest, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculatePolygonPointST, CalculatePolygonPointST, MAXON_EXPAND_VA_ARGS, (Bool), const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InverseBilinarInterpolate, InverseBilinarInterpolate, MAXON_EXPAND_VA_ARGS, (void), const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InverseBilinarInterpolateNewton, InverseBilinarInterpolateNewton, MAXON_EXPAND_VA_ARGS, (void), const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InverseBilinarInterpolate2D, InverseBilinarInterpolate2D, MAXON_EXPAND_VA_ARGS, (void), const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_InverseBilinarInterpolate2DNewton, InverseBilinarInterpolate2DNewton, MAXON_EXPAND_VA_ARGS, (void), const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_BilinearInterpolate, BilinearInterpolate, MAXON_EXPAND_VA_ARGS, (Vector), const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateSignedTriangleArea_1, CalculateSignedTriangleArea, MAXON_EXPAND_VA_ARGS, (Float), const Vector& a, const Vector& b, const Vector& c, const Vector& normal);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2, CalculateMeanValueCoordinatesWeights, MAXON_EXPAND_VA_ARGS, (Result<void>), const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculatePerimeterLength2D, CalculatePerimeterLength2D, MAXON_EXPAND_VA_ARGS, (Float), const Block<const Vector2d>& outlinePoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IsWoundClockwise2D, IsWoundClockwise2D, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const Block<const Vector2d>& outlinePoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D, CalculateOutlineCentroidAndArea2D, MAXON_EXPAND_VA_ARGS, (Vector2d), const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D, CalculateMultiOutlineCentroidAndAreas2D, MAXON_EXPAND_VA_ARGS, (Result<Vector2d>), const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateConvexHull2D, CalculateConvexHull2D, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Int>>), const Block<const Vector2d>& outlinePoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateConvexDecomposition2D, CalculateConvexDecomposition2D, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<BaseArray<Int>>>), const Block<const Vector2d>& outlinePoints);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CleanLoop2DInPlace, CleanLoop2DInPlace, MAXON_EXPAND_VA_ARGS, (Result<Bool>), BaseArray<Vector2d>& outlinePoints, Bool maintainStart);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateNoFitPolygonForConvex, CalculateNoFitPolygonForConvex, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Vector2d>>), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding, CalculateNoFitPolygonUsingSliding, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Vector2d>>), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding, CalculateInnerFitPolygonUsingSliding, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Vector2d>>), const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1, CalculateNoFitPolygonForConvex, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Vector2d>>), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1, CalculateNoFitPolygonUsingSliding, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Vector2d>>), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateUnionOfPolygons, CalculateUnionOfPolygons, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<BaseArray<Vector2d>>>), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_IntersectsSegmentsExact2D, IntersectsSegmentsExact2D, MAXON_EXPAND_VA_ARGS, (Bool), const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops, GetContainmentStateForNonIntersectingLoops, MAXON_EXPAND_VA_ARGS, (LOOP_OVERLAP_STATE), const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_AreLoopsEqualToWithinTolerance, AreLoopsEqualToWithinTolerance, MAXON_EXPAND_VA_ARGS, (Bool), const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_CalculateBoundingBoxIndices, CalculateBoundingBoxIndices, MAXON_EXPAND_VA_ARGS, (void), const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise);
	PRIVATE_MAXON_SF_POINTER(GeometryUtilsInterface_ArePointsCoLinearWithinTolerance, ArePointsCoLinearWithinTolerance, MAXON_EXPAND_VA_ARGS, (Bool), const Block<const Vector>& points, maxon::Float tol);
	template <typename IMPL> void Init()
	{
		GeometryUtilsInterface_LinearRemapToRange = GeometryUtilsInterface_LinearRemapToRange_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetAngle2D = GeometryUtilsInterface_GetAngle2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InterpolatePointOnSegment = GeometryUtilsInterface_InterpolatePointOnSegment_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InterpolatePointOnSegment2D = GeometryUtilsInterface_InterpolatePointOnSegment2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateBestFitPlane = GeometryUtilsInterface_CalculateBestFitPlane_GetPtr<IMPL>(true);
		GeometryUtilsInterface_Points3Dto2D = GeometryUtilsInterface_Points3Dto2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_Points3Dto2D_1 = GeometryUtilsInterface_Points3Dto2D_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_Point2Dto3D = GeometryUtilsInterface_Point2Dto3D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_Points2Dto3D = GeometryUtilsInterface_Points2Dto3D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateTriangleArea = GeometryUtilsInterface_CalculateTriangleArea_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateSignedTriangleArea = GeometryUtilsInterface_CalculateSignedTriangleArea_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateQuadrangleArea = GeometryUtilsInterface_CalculateQuadrangleArea_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateOutlineArea = GeometryUtilsInterface_CalculateOutlineArea_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateOutlineNormal = GeometryUtilsInterface_CalculateOutlineNormal_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateOutlineNormal_1 = GeometryUtilsInterface_CalculateOutlineNormal_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IsVertexConvex = GeometryUtilsInterface_IsVertexConvex_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IsVertexConvexExact = GeometryUtilsInterface_IsVertexConvexExact_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights = GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1 = GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IsVertexConvex2D = GeometryUtilsInterface_IsVertexConvex2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IsVertexConvexExact2D = GeometryUtilsInterface_IsVertexConvexExact2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateBarycentricCoordinate = GeometryUtilsInterface_CalculateBarycentricCoordinate_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateBarycentricCoordinate3D = GeometryUtilsInterface_CalculateBarycentricCoordinate3D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInTriangle = GeometryUtilsInterface_PointInTriangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInTriangle2D = GeometryUtilsInterface_PointInTriangle2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetPointInPolygonWindingNumber2D = GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact = GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1 = GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetPointInPolygonWindingNumber = GeometryUtilsInterface_GetPointInPolygonWindingNumber_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetPointInPolygonWindingNumber_1 = GeometryUtilsInterface_GetPointInPolygonWindingNumber_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInOutline2D = GeometryUtilsInterface_PointInOutline2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInOutlineRobust2D = GeometryUtilsInterface_PointInOutlineRobust2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateBisector = GeometryUtilsInterface_CalculateBisector_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateCircumcenter2D = GeometryUtilsInterface_CalculateCircumcenter2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateCircumcenter = GeometryUtilsInterface_CalculateCircumcenter_GetPtr<IMPL>(true);
		GeometryUtilsInterface_SegmentsIntersectionTest2D = GeometryUtilsInterface_SegmentsIntersectionTest2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_SegmentRayIntersectionTest2D = GeometryUtilsInterface_SegmentRayIntersectionTest2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectSegments2D = GeometryUtilsInterface_IntersectSegments2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_LineLineDistance = GeometryUtilsInterface_LineLineDistance_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInSegment2D = GeometryUtilsInterface_PointInSegment2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInSegment = GeometryUtilsInterface_PointInSegment_GetPtr<IMPL>(true);
		GeometryUtilsInterface_PointInHalfLine = GeometryUtilsInterface_PointInHalfLine_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLines = GeometryUtilsInterface_IntersectLines_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLineSegment = GeometryUtilsInterface_IntersectLineSegment_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectSegments = GeometryUtilsInterface_IntersectSegments_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectHalfLines = GeometryUtilsInterface_IntersectHalfLines_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLineHalfLine = GeometryUtilsInterface_IntersectLineHalfLine_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectHalfLineSegment = GeometryUtilsInterface_IntersectHalfLineSegment_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectPlanes = GeometryUtilsInterface_IntersectPlanes_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLinePlane = GeometryUtilsInterface_IntersectLinePlane_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLinePlane_1 = GeometryUtilsInterface_IntersectLinePlane_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectSegmentPlane = GeometryUtilsInterface_IntersectSegmentPlane_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectHalfLinePlane = GeometryUtilsInterface_IntersectHalfLinePlane_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLineTriangle = GeometryUtilsInterface_IntersectLineTriangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectHalfLineTriangle = GeometryUtilsInterface_IntersectHalfLineTriangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectLineQuadrangle = GeometryUtilsInterface_IntersectLineQuadrangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectHalfLineQuadrangle = GeometryUtilsInterface_IntersectHalfLineQuadrangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectSegmentTriangle = GeometryUtilsInterface_IntersectSegmentTriangle_GetPtr<IMPL>(true);
		GeometryUtilsInterface_TrianglesIntersectionTest = GeometryUtilsInterface_TrianglesIntersectionTest_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculatePolygonPointST = GeometryUtilsInterface_CalculatePolygonPointST_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InverseBilinarInterpolate = GeometryUtilsInterface_InverseBilinarInterpolate_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InverseBilinarInterpolateNewton = GeometryUtilsInterface_InverseBilinarInterpolateNewton_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InverseBilinarInterpolate2D = GeometryUtilsInterface_InverseBilinarInterpolate2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_InverseBilinarInterpolate2DNewton = GeometryUtilsInterface_InverseBilinarInterpolate2DNewton_GetPtr<IMPL>(true);
		GeometryUtilsInterface_BilinearInterpolate = GeometryUtilsInterface_BilinearInterpolate_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateSignedTriangleArea_1 = GeometryUtilsInterface_CalculateSignedTriangleArea_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2 = GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculatePerimeterLength2D = GeometryUtilsInterface_CalculatePerimeterLength2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IsWoundClockwise2D = GeometryUtilsInterface_IsWoundClockwise2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D = GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D = GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateConvexHull2D = GeometryUtilsInterface_CalculateConvexHull2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateConvexDecomposition2D = GeometryUtilsInterface_CalculateConvexDecomposition2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CleanLoop2DInPlace = GeometryUtilsInterface_CleanLoop2DInPlace_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateNoFitPolygonForConvex = GeometryUtilsInterface_CalculateNoFitPolygonForConvex_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding = GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding = GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1 = GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1 = GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateUnionOfPolygons = GeometryUtilsInterface_CalculateUnionOfPolygons_GetPtr<IMPL>(true);
		GeometryUtilsInterface_IntersectsSegmentsExact2D = GeometryUtilsInterface_IntersectsSegmentsExact2D_GetPtr<IMPL>(true);
		GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops = GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops_GetPtr<IMPL>(true);
		GeometryUtilsInterface_AreLoopsEqualToWithinTolerance = GeometryUtilsInterface_AreLoopsEqualToWithinTolerance_GetPtr<IMPL>(true);
		GeometryUtilsInterface_CalculateBoundingBoxIndices = GeometryUtilsInterface_CalculateBoundingBoxIndices_GetPtr<IMPL>(true);
		GeometryUtilsInterface_ArePointsCoLinearWithinTolerance = GeometryUtilsInterface_ArePointsCoLinearWithinTolerance_GetPtr<IMPL>(true);
	}
};

struct GeometryUtilsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Float GeometryUtilsInterface_LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2) { return C::LinearRemapToRange(value, from1, to1, from2, to2); }
		static Float GeometryUtilsInterface_GetAngle2D(const Vector2d& direction1, const Vector2d& direction2) { return C::GetAngle2D(direction1, direction2); }
		static Float GeometryUtilsInterface_InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp) { return C::InterpolatePointOnSegment(segmentPoint1, segmentPoint2, point, clamp); }
		static Float GeometryUtilsInterface_InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp) { return C::InterpolatePointOnSegment2D(segmentPoint1, segmentPoint2, point, clamp); }
		static Bool GeometryUtilsInterface_CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax) { return C::CalculateBestFitPlane(pointCloud, centroid, normal, iterMax); }
		static Result<void> GeometryUtilsInterface_Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis) { return C::Points3Dto2D(points, normal, basisVector0, basisVector1, translate, checkDegenerated, outPoints, computeBasis); }
		static Result<void> GeometryUtilsInterface_Points3Dto2D_1(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints) { return C::Points3Dto2D(points, normal, checkDegenerated, outPoints); }
		static Vector GeometryUtilsInterface_Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate) { return C::Point2Dto3D(point, basisVector0, basisVector1, translate); }
		static Result<void> GeometryUtilsInterface_Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints) { return C::Points2Dto3D(points, basisVector0, basisVector1, translate, outPoints); }
		static Float GeometryUtilsInterface_CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c) { return C::CalculateTriangleArea(a, b, c); }
		static Float GeometryUtilsInterface_CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c) { return C::CalculateSignedTriangleArea(a, b, c); }
		static Float GeometryUtilsInterface_CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d) { return C::CalculateQuadrangleArea(a, b, c, d); }
		static Float GeometryUtilsInterface_CalculateOutlineArea(const Block<const Vector>& outlinePoints) { return C::CalculateOutlineArea(outlinePoints); }
		static Vector GeometryUtilsInterface_CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized) { return C::CalculateOutlineNormal(points, indices, normalized); }
		static Vector GeometryUtilsInterface_CalculateOutlineNormal_1(const Block<const Vector>& points, Bool normalize) { return C::CalculateOutlineNormal(points, normalize); }
		static Bool GeometryUtilsInterface_IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up) { return C::IsVertexConvex(vertex, next, pred, up); }
		static GEOMETRY_TEST_EXACT GeometryUtilsInterface_IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon) { return C::IsVertexConvexExact(vertex, next, pred, up, epsilon); }
		static Result<void> GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, outline, weights); }
		static Result<void> GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, points, outlineIndices, normal, weights); }
		static Bool GeometryUtilsInterface_IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred) { return C::IsVertexConvex2D(vertex, next, pred); }
		static GEOMETRY_TEST_EXACT GeometryUtilsInterface_IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon) { return C::IsVertexConvexExact2D(vertex, next, pred, epsilon); }
		static Vector2d GeometryUtilsInterface_CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::CalculateBarycentricCoordinate(point, a, b, c); }
		static Vector GeometryUtilsInterface_CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::CalculateBarycentricCoordinate3D(point, a, b, c); }
		static Bool GeometryUtilsInterface_PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c) { return C::PointInTriangle(point, a, b, c); }
		static Bool GeometryUtilsInterface_PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c) { return C::PointInTriangle2D(point, a, b, c); }
		static Int GeometryUtilsInterface_GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline) { return C::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline); }
		static Int GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline) { return C::GetPointInPolygonWindingNumber2DExact(std::forward<Vector2d>(point), outline); }
		static Int GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit) { return C::GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline, edgeHit); }
		static Int GeometryUtilsInterface_GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline) { return C::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline); }
		static Int GeometryUtilsInterface_GetPointInPolygonWindingNumber_1(Vector point, const Block<const Vector>& outline, Int& edgeHit) { return C::GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline, edgeHit); }
		static Bool GeometryUtilsInterface_PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline) { return C::PointInOutline2D(point, outline); }
		static Bool GeometryUtilsInterface_PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline) { return C::PointInOutlineRobust2D(point, outline); }
		static Vector GeometryUtilsInterface_CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2) { return C::CalculateBisector(v1, v2, up, w1, w2); }
		static Bool GeometryUtilsInterface_CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance) { return C::CalculateCircumcenter2D(a, b, c, center, sqrRad, tolerance); }
		static Bool GeometryUtilsInterface_CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance) { return C::CalculateCircumcenter(a, b, c, center, rad, tolerance); }
		static Bool GeometryUtilsInterface_SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2) { return C::SegmentsIntersectionTest2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2); }
		static Bool GeometryUtilsInterface_SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection) { return C::SegmentRayIntersectionTest2D(segmentPoint1, segmentPoint2, rayStartPoint, rayDirection); }
		static Bool GeometryUtilsInterface_IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance) { return C::IntersectSegments2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); }
		static Vector GeometryUtilsInterface_LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance) { return C::LineLineDistance(line1Point, line1Dir, line2Point, line2Dir, parallel, param1, param2, tolerance); }
		static Bool GeometryUtilsInterface_PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance) { return C::PointInSegment2D(point, segmentPoint1, segmentPoint2, tolerance); }
		static Bool GeometryUtilsInterface_PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance) { return C::PointInSegment(point, segmentPoint1, segmentPoint2, tolerance); }
		static Bool GeometryUtilsInterface_PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance) { return C::PointInHalfLine(point, halfLineOrigin, halfLineDir, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance) { return C::IntersectLines(line1Point, line1Dir, line2Point, line2Dir, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineSegment(linePoint, lineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance) { return C::IntersectSegments(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineHalfLine(linePoint, lineDir, halfLineOrigin, halfLineDir, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance) { return C::IntersectPlanes(plane1Point, plane1Normal, plane2Point, plane2Normal, resLinePoint, resLineDirection, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLinePlane_1(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance) { return C::IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance); }
		static Bool GeometryUtilsInterface_IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectSegmentPlane(segmentPoint1, segmentPoint2, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { return C::IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool GeometryUtilsInterface_IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) { return C::IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool GeometryUtilsInterface_IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { return C::IntersectLineQuadrangle(linePoint, lineDir, a, b, c, d, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) { return C::IntersectHalfLineQuadrangle(halfLineOrigin, halfLineDir, a, b, c, d, intersectionPoint, tolerance); }
		static Bool GeometryUtilsInterface_IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance) { return C::IntersectSegmentTriangle(segmentPoint1, segmentPoint2, a, b, c, intersectionPoint, barycCoords, tolerance); }
		static Bool GeometryUtilsInterface_TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance) { return C::TrianglesIntersectionTest(t1a, t1b, t1c, t2a, t2b, t2c, tolerance); }
		static Bool GeometryUtilsInterface_CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance) { return C::CalculatePolygonPointST(point, pa, pb, pc, pd, isQuad, s, t, tolerance); }
		static void GeometryUtilsInterface_InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate(pa, pb, pc, pd, point, bilinarVariables); }
		static void GeometryUtilsInterface_InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolateNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); }
		static void GeometryUtilsInterface_InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate2D(pa, pb, pc, pd, point, bilinarVariables); }
		static void GeometryUtilsInterface_InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables) { return C::InverseBilinarInterpolate2DNewton(pa, pb, pc, pd, point, iterations, bilinarVariables); }
		static Vector GeometryUtilsInterface_BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t) { return C::BilinearInterpolate(pa, pb, pc, pd, s, t); }
		static Float GeometryUtilsInterface_CalculateSignedTriangleArea_1(const Vector& a, const Vector& b, const Vector& c, const Vector& normal) { return C::CalculateSignedTriangleArea(a, b, c, normal); }
		static Result<void> GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights) { return C::CalculateMeanValueCoordinatesWeights(point, outline, normal, weights); }
		static Float GeometryUtilsInterface_CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints) { return C::CalculatePerimeterLength2D(outlinePoints); }
		static Result<Bool> GeometryUtilsInterface_IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints) { return C::IsWoundClockwise2D(outlinePoints); }
		static Vector2d GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity) { return C::CalculateOutlineCentroidAndArea2D(outlinePoints, area, windingPolarity); }
		static Result<Vector2d> GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity) { return C::CalculateMultiOutlineCentroidAndAreas2D(loopVertices, loopVertexCounts, includeHolesInCogCalcs, overallArea, loopSoloAreas, windingPolarity); }
		static Result<BaseArray<Int>> GeometryUtilsInterface_CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints) { return C::CalculateConvexHull2D(outlinePoints); }
		static Result<BaseArray<BaseArray<Int>>> GeometryUtilsInterface_CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints) { return C::CalculateConvexDecomposition2D(outlinePoints); }
		static Result<Bool> GeometryUtilsInterface_CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart) { return C::CleanLoop2DInPlace(outlinePoints, maintainStart); }
		static Result<BaseArray<Vector2d>> GeometryUtilsInterface_CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { return C::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, relativeBToA); }
		static Result<BaseArray<Vector2d>> GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) { return C::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, relativeBToA); }
		static Result<BaseArray<Vector2d>> GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB) { return C::CalculateInnerFitPolygonUsingSliding(outlinePointsCcwA, outlinePointsB); }
		static Result<BaseArray<Vector2d>> GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { return C::CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); }
		static Result<BaseArray<Vector2d>> GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) { return C::CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA); }
		static Result<BaseArray<BaseArray<Vector2d>>> GeometryUtilsInterface_CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop) { return C::CalculateUnionOfPolygons(outlinePointsA, outlinePointsB, includeHolesInResult, createOuterLoop); }
		static Bool GeometryUtilsInterface_IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance) { return C::IntersectsSegmentsExact2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, areParallel, intersectionPoint2, tolerance); }
		static LOOP_OVERLAP_STATE GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB) { return C::GetContainmentStateForNonIntersectingLoops(outlinePointsA, outlinePointsB); }
		static Bool GeometryUtilsInterface_AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol) { return C::AreLoopsEqualToWithinTolerance(loopA, loopB, allowCyclicRotation, ignoreTranslationOffset, tol); }
		static void GeometryUtilsInterface_CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise) { return C::CalculateBoundingBoxIndices(verts, minIdxX, maxIdxX, minIdxY, maxIdxY, findMostCounterClockwise); }
		static Bool GeometryUtilsInterface_ArePointsCoLinearWithinTolerance(const Block<const Vector>& points, maxon::Float tol) { return C::ArePointsCoLinearWithinTolerance(points, tol); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::LinearRemapToRange(Float value, Float from1, Float to1, Float from2, Float to2) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_LinearRemapToRange(value, from1, to1, from2, to2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetAngle2D(const Vector2d& direction1, const Vector2d& direction2) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_GetAngle2D(direction1, direction2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InterpolatePointOnSegment(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& point, Bool clamp) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_InterpolatePointOnSegment(segmentPoint1, segmentPoint2, point, clamp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InterpolatePointOnSegment2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& point, Bool clamp) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_InterpolatePointOnSegment2D(segmentPoint1, segmentPoint2, point, clamp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBestFitPlane(const Block<const Vector>& pointCloud, Vector& centroid, Vector& normal, Int iterMax) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_CalculateBestFitPlane(pointCloud, centroid, normal, iterMax);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Vector& basisVector0, Vector& basisVector1, Vector& translate, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints, Bool computeBasis) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_Points3Dto2D(points, normal, basisVector0, basisVector1, translate, checkDegenerated, outPoints, computeBasis);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points3Dto2D(const Block<const Vector>& points, const Vector& normal, Bool checkDegenerated, WritableArrayInterface<Vector2d>& outPoints) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_Points3Dto2D_1(points, normal, checkDegenerated, outPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Point2Dto3D(const Vector2d& point, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_Point2Dto3D(point, basisVector0, basisVector1, translate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::Points2Dto3D(const Block<const Vector2d>& points, const Vector& basisVector0, const Vector& basisVector1, const Vector& translate, WritableArrayInterface<Vector>& outPoints) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_Points2Dto3D(points, basisVector0, basisVector1, translate, outPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateTriangleArea(const Vector& a, const Vector& b, const Vector& c) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculateTriangleArea(a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculateSignedTriangleArea(a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateQuadrangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& d) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculateQuadrangleArea(a, b, c, d);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineArea(const Block<const Vector>& outlinePoints) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculateOutlineArea(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineNormal(const Block<const Vector>& points, const Block<const Int32>& indices, Bool normalized) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_CalculateOutlineNormal(points, indices, normalized);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineNormal(const Block<const Vector>& points, Bool normalize) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_CalculateOutlineNormal_1(points, normalize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvex(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IsVertexConvex(vertex, next, pred, up);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvexExact(const Vector& vertex, const Vector& next, const Vector& pred, const Vector& up, Float epsilon) -> GEOMETRY_TEST_EXACT
{
	return MTable::_instance.GeometryUtilsInterface_IsVertexConvexExact(vertex, next, pred, up, epsilon);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights(point, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& points, const Block<const UInt32>& outlineIndices, const Vector& normal, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1(point, points, outlineIndices, normal, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvex2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IsVertexConvex2D(vertex, next, pred);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsVertexConvexExact2D(const Vector2d& vertex, const Vector2d& next, const Vector2d& pred, Float epsilon) -> GEOMETRY_TEST_EXACT
{
	return MTable::_instance.GeometryUtilsInterface_IsVertexConvexExact2D(vertex, next, pred, epsilon);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBarycentricCoordinate(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Vector2d
{
	return MTable::_instance.GeometryUtilsInterface_CalculateBarycentricCoordinate(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBarycentricCoordinate3D(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_CalculateBarycentricCoordinate3D(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInTriangle(const Vector& point, const Vector& a, const Vector& b, const Vector& c) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInTriangle(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInTriangle2D(const Vector2d& point, const Vector2d& a, const Vector2d& b, const Vector2d& c) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInTriangle2D(point, a, b, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline) -> Int
{
	return MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2D(std::forward<Vector2d>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2DExact(Vector2d point, const Block<const Vector2d>& outline) -> Int
{
	return MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact(std::forward<Vector2d>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber2D(Vector2d point, const Block<const Vector2d>& outline, Int& edgeHit) -> Int
{
	return MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1(std::forward<Vector2d>(point), outline, edgeHit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline) -> Int
{
	return MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber(std::forward<Vector>(point), outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetPointInPolygonWindingNumber(Vector point, const Block<const Vector>& outline, Int& edgeHit) -> Int
{
	return MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber_1(std::forward<Vector>(point), outline, edgeHit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInOutline2D(const Vector& point, const Block<const Vector2d>& outline) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInOutline2D(point, outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInOutlineRobust2D(const Vector& point, const Block<const Vector2d>& outline) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInOutlineRobust2D(point, outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBisector(const Vector& v1, const Vector& v2, const Vector& up, Float w1, Float w2) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_CalculateBisector(v1, v2, up, w1, w2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateCircumcenter2D(const Vector2d& a, const Vector2d& b, const Vector2d& c, Vector2d& center, Float& sqrRad, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_CalculateCircumcenter2D(a, b, c, center, sqrRad, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateCircumcenter(const Vector& a, const Vector& b, const Vector& c, Vector& center, Float& rad, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_CalculateCircumcenter(a, b, c, center, rad, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::SegmentsIntersectionTest2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_SegmentsIntersectionTest2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::SegmentRayIntersectionTest2D(const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, const Vector2d& rayStartPoint, const Vector2d& rayDirection) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_SegmentRayIntersectionTest2D(segmentPoint1, segmentPoint2, rayStartPoint, rayDirection);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegments2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectSegments2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::LineLineDistance(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Bool& parallel, Float& param1, Float& param2, Float tolerance) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_LineLineDistance(line1Point, line1Dir, line2Point, line2Dir, parallel, param1, param2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInSegment2D(const Vector2d& point, const Vector2d& segmentPoint1, const Vector2d& segmentPoint2, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInSegment2D(point, segmentPoint1, segmentPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInSegment(const Vector& point, const Vector& segmentPoint1, const Vector& segmentPoint2, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInSegment(point, segmentPoint1, segmentPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::PointInHalfLine(const Vector& point, const Vector& halfLineOrigin, const Vector& halfLineDir, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_PointInHalfLine(point, halfLineOrigin, halfLineDir, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLines(const Vector& line1Point, const Vector& line1Dir, const Vector& line2Point, const Vector& line2Dir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLines(line1Point, line1Dir, line2Point, line2Dir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineSegment(const Vector& linePoint, const Vector& lineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLineSegment(linePoint, lineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegments(const Vector& segment1Point1, const Vector& segment1Point2, const Vector& segment2Point1, const Vector& segment2Point2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectSegments(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLines(const Vector& halfLine1Origin, const Vector& halfLine1Dir, const Vector& halfLine2Origin, const Vector& halfLine2Dir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectHalfLines(halfLine1Origin, halfLine1Dir, halfLine2Origin, halfLine2Dir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineHalfLine(const Vector& linePoint, const Vector& lineDir, const Vector& halfLineOrigin, const Vector& halfLineDir, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLineHalfLine(linePoint, lineDir, halfLineOrigin, halfLineDir, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineSegment(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& segmentPoint1, const Vector& segmentPoint2, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectHalfLineSegment(halfLineOrigin, halfLineDir, segmentPoint1, segmentPoint2, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectPlanes(const Vector& plane1Point, const Vector& plane1Normal, const Vector& plane2Point, const Vector& plane2Normal, Vector& resLinePoint, Vector& resLineDirection, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectPlanes(plane1Point, plane1Normal, plane2Point, plane2Normal, resLinePoint, resLineDirection, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLinePlane(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLinePlane(const Vector& linePoint, const Vector& lineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float& param, Bool& samePlane, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLinePlane_1(linePoint, lineDir, planePoint, planeNormal, intersectionPoint, param, samePlane, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegmentPlane(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectSegmentPlane(segmentPoint1, segmentPoint2, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLinePlane(const Vector& halfLinePoint, const Vector& halfLineDir, const Vector& planePoint, const Vector& planeNormal, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectHalfLinePlane(halfLinePoint, halfLineDir, planePoint, planeNormal, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineTriangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLineTriangle(linePoint, lineDir, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineTriangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector2d* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectHalfLineTriangle(halfLineOrigin, halfLineDir, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectLineQuadrangle(const Vector& linePoint, const Vector& lineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectLineQuadrangle(linePoint, lineDir, a, b, c, d, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectHalfLineQuadrangle(const Vector& halfLineOrigin, const Vector& halfLineDir, const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& intersectionPoint, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectHalfLineQuadrangle(halfLineOrigin, halfLineDir, a, b, c, d, intersectionPoint, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectSegmentTriangle(const Vector& segmentPoint1, const Vector& segmentPoint2, const Vector& a, const Vector& b, const Vector& c, Vector& intersectionPoint, Vector* barycCoords, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectSegmentTriangle(segmentPoint1, segmentPoint2, a, b, c, intersectionPoint, barycCoords, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::TrianglesIntersectionTest(const Vector& t1a, const Vector& t1b, const Vector& t1c, const Vector& t2a, const Vector& t2b, const Vector& t2c, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_TrianglesIntersectionTest(t1a, t1b, t1c, t2a, t2b, t2c, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculatePolygonPointST(const Vector& point, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool isQuad, Float& s, Float& t, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_CalculatePolygonPointST(point, pa, pb, pc, pd, isQuad, s, t, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate(pa, pb, pc, pd, point, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolateNewton(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Vector& point, Int32 iterations, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolateNewton(pa, pb, pc, pd, point, iterations, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate2D(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate2D(pa, pb, pc, pd, point, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::InverseBilinarInterpolate2DNewton(const Vector2d& pa, const Vector2d& pb, const Vector2d& pc, const Vector2d& pd, const Vector2d& point, Int32 iterations, Vector2d& bilinarVariables) -> void
{
	return MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate2DNewton(pa, pb, pc, pd, point, iterations, bilinarVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::BilinearInterpolate(const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, const Float s, const Float t) -> Vector
{
	return MTable::_instance.GeometryUtilsInterface_BilinearInterpolate(pa, pb, pc, pd, s, t);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateSignedTriangleArea(const Vector& a, const Vector& b, const Vector& c, const Vector& normal) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculateSignedTriangleArea_1(a, b, c, normal);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMeanValueCoordinatesWeights(const Vector& point, const Block<const Vector>& outline, const Vector& normal, WritableArrayInterface<Float>& weights) -> Result<void>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2(point, outline, normal, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculatePerimeterLength2D(const Block<const Vector2d>& outlinePoints) -> Float
{
	return MTable::_instance.GeometryUtilsInterface_CalculatePerimeterLength2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IsWoundClockwise2D(const Block<const Vector2d>& outlinePoints) -> Result<Bool>
{
	return MTable::_instance.GeometryUtilsInterface_IsWoundClockwise2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateOutlineCentroidAndArea2D(const Block<const Vector2d>& outlinePoints, Float* area, Bool* windingPolarity) -> Vector2d
{
	return MTable::_instance.GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D(outlinePoints, area, windingPolarity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateMultiOutlineCentroidAndAreas2D(const Block<const Vector2d>& loopVertices, const Block<const Int>& loopVertexCounts, Bool includeHolesInCogCalcs, Float* overallArea, BaseArray<Float>* loopSoloAreas, BaseArray<Bool>* windingPolarity) -> Result<Vector2d>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D(loopVertices, loopVertexCounts, includeHolesInCogCalcs, overallArea, loopSoloAreas, windingPolarity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateConvexHull2D(const Block<const Vector2d>& outlinePoints) -> Result<BaseArray<Int>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateConvexHull2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateConvexDecomposition2D(const Block<const Vector2d>& outlinePoints) -> Result<BaseArray<BaseArray<Int>>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateConvexDecomposition2D(outlinePoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CleanLoop2DInPlace(BaseArray<Vector2d>& outlinePoints, Bool maintainStart) -> Result<Bool>
{
	return MTable::_instance.GeometryUtilsInterface_CleanLoop2DInPlace(outlinePoints, maintainStart);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonForConvex(outlinePointsA, outlinePointsB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding(outlinePointsA, outlinePointsB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateInnerFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsCcwA, const Block<const Vector2d>& outlinePointsB) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding(outlinePointsCcwA, outlinePointsB);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonForConvex(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateNoFitPolygonUsingSliding(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, const Matrix2d& transformA, const Matrix2d& transformB, Bool relativeBToA) -> Result<BaseArray<Vector2d>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1(outlinePointsA, outlinePointsB, transformA, transformB, relativeBToA);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateUnionOfPolygons(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB, Bool includeHolesInResult, Bool createOuterLoop) -> Result<BaseArray<BaseArray<Vector2d>>>
{
	return MTable::_instance.GeometryUtilsInterface_CalculateUnionOfPolygons(outlinePointsA, outlinePointsB, includeHolesInResult, createOuterLoop);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::IntersectsSegmentsExact2D(const Vector2d& segment1Point1, const Vector2d& segment1Point2, const Vector2d& segment2Point1, const Vector2d& segment2Point2, Vector2d& intersectionPoint, Bool& areParallel, Vector2d* intersectionPoint2, Float tolerance) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_IntersectsSegmentsExact2D(segment1Point1, segment1Point2, segment2Point1, segment2Point2, intersectionPoint, areParallel, intersectionPoint2, tolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::GetContainmentStateForNonIntersectingLoops(const Block<const Vector2d>& outlinePointsA, const Block<const Vector2d>& outlinePointsB) -> LOOP_OVERLAP_STATE
{
	return MTable::_instance.GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops(outlinePointsA, outlinePointsB);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::AreLoopsEqualToWithinTolerance(const Block<const Vector2d>& loopA, const Block<const Vector2d>& loopB, Bool allowCyclicRotation, Bool ignoreTranslationOffset, maxon::Float tol) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_AreLoopsEqualToWithinTolerance(loopA, loopB, allowCyclicRotation, ignoreTranslationOffset, tol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::CalculateBoundingBoxIndices(const Block<const Vector2d>& verts, Int& minIdxX, Int& maxIdxX, Int& minIdxY, Int& maxIdxY, Bool findMostCounterClockwise) -> void
{
	return MTable::_instance.GeometryUtilsInterface_CalculateBoundingBoxIndices(verts, minIdxX, maxIdxX, minIdxY, maxIdxY, findMostCounterClockwise);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GeometryUtilsInterface::ArePointsCoLinearWithinTolerance(const Block<const Vector>& points, maxon::Float tol) -> Bool
{
	return MTable::_instance.GeometryUtilsInterface_ArePointsCoLinearWithinTolerance(points, tol);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_geometryutils)
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

