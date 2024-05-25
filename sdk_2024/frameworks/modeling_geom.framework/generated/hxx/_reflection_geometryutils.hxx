#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DegeneratedInputErrorInterface(DegeneratedInputErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DegeneratedInputError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DegeneratedInputErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, DegeneratedInputErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DegeneratedInputErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(DegeneratedInputErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DegeneratedInputErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DegeneratedInputErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DegeneratedInputErrorInterface(nullptr, &DegeneratedInputErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_DegeneratedInputErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_GeometryUtilsInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_LinearRemapToRange)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0from1\0to1\0from2\0to2\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetAngle2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "direction1\0direction2\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InterpolatePointOnSegment)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segmentPoint1\0segmentPoint2\0point\0clamp\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InterpolatePointOnSegment2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segmentPoint1\0segmentPoint2\0point\0clamp\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateBestFitPlane)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pointCloud\0centroid\0normal\0iterMax\0", 105LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_Points3Dto2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0normal\0basisVector0\0basisVector1\0translate\0checkDegenerated\0outPoints\0computeBasis\0", 42741LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_Points3Dto2D_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0normal\0checkDegenerated\0outPoints\0", 149LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_Point2Dto3D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0basisVector0\0basisVector1\0translate\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_Points2Dto3D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0basisVector0\0basisVector1\0translate\0outPoints\0", 597LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateTriangleArea)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateSignedTriangleArea)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateQuadrangleArea)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0d\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateOutlineArea)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateOutlineNormal)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0indices\0normalized\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateOutlineNormal_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0normalize\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IsVertexConvex)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vertex\0next\0pred\0up\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IsVertexConvexExact)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vertex\0next\0pred\0up\0epsilon\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0weights\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0points\0outlineIndices\0normal\0weights\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IsVertexConvex2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vertex\0next\0pred\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IsVertexConvexExact2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vertex\0next\0pred\0epsilon\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateBarycentricCoordinate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0a\0b\0c\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateBarycentricCoordinate3D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0a\0b\0c\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInTriangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0a\0b\0c\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInTriangle2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0a\0b\0c\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2DExact)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber2D_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0edgeHit\0", 37LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetPointInPolygonWindingNumber_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0edgeHit\0", 37LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInOutline2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInOutlineRobust2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateBisector)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "v1\0v2\0up\0w1\0w2\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateCircumcenter2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0center\0sqrRad\0tolerance\0", 1685LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateCircumcenter)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0center\0rad\0tolerance\0", 1685LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_SegmentsIntersectionTest2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segment1Point1\0segment1Point2\0segment2Point1\0segment2Point2\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_SegmentRayIntersectionTest2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segmentPoint1\0segmentPoint2\0rayStartPoint\0rayDirection\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectSegments2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segment1Point1\0segment1Point2\0segment2Point1\0segment2Point2\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_LineLineDistance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "line1Point\0line1Dir\0line2Point\0line2Dir\0parallel\0param1\0param2\0tolerance\0", 27221LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInSegment2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0segmentPoint1\0segmentPoint2\0tolerance\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInSegment)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0segmentPoint1\0segmentPoint2\0tolerance\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_PointInHalfLine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0halfLineOrigin\0halfLineDir\0tolerance\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLines)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "line1Point\0line1Dir\0line2Point\0line2Dir\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLineSegment)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0segmentPoint1\0segmentPoint2\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectSegments)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segment1Point1\0segment1Point2\0segment2Point1\0segment2Point2\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectHalfLines)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "halfLine1Origin\0halfLine1Dir\0halfLine2Origin\0halfLine2Dir\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLineHalfLine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0halfLineOrigin\0halfLineDir\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectHalfLineSegment)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "halfLineOrigin\0halfLineDir\0segmentPoint1\0segmentPoint2\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectPlanes)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "plane1Point\0plane1Normal\0plane2Point\0plane2Normal\0resLinePoint\0resLineDirection\0tolerance\0", 6741LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLinePlane)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0planePoint\0planeNormal\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLinePlane_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0planePoint\0planeNormal\0intersectionPoint\0param\0samePlane\0tolerance\0", 16981LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectSegmentPlane)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segmentPoint1\0segmentPoint2\0planePoint\0planeNormal\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectHalfLinePlane)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "halfLinePoint\0halfLineDir\0planePoint\0planeNormal\0intersectionPoint\0tolerance\0", 1621LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLineTriangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0a\0b\0c\0intersectionPoint\0barycCoords\0tolerance\0", 26965LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectHalfLineTriangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "halfLineOrigin\0halfLineDir\0a\0b\0c\0intersectionPoint\0barycCoords\0tolerance\0", 26965LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectLineQuadrangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "linePoint\0lineDir\0a\0b\0c\0d\0intersectionPoint\0tolerance\0", 25941LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectHalfLineQuadrangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "halfLineOrigin\0halfLineDir\0a\0b\0c\0d\0intersectionPoint\0tolerance\0", 25941LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectSegmentTriangle)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segmentPoint1\0segmentPoint2\0a\0b\0c\0intersectionPoint\0barycCoords\0tolerance\0", 26965LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_TrianglesIntersectionTest)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "t1a\0t1b\0t1c\0t2a\0t2b\0t2c\0tolerance\0", 5461LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculatePolygonPointST)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0pa\0pb\0pc\0pd\0isQuad\0s\0t\0tolerance\0", 107861LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pa\0pb\0pc\0pd\0point\0bilinarVariables\0", 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolateNewton)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pa\0pb\0pc\0pd\0point\0iterations\0bilinarVariables\0", 9557LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pa\0pb\0pc\0pd\0point\0bilinarVariables\0", 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_InverseBilinarInterpolate2DNewton)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pa\0pb\0pc\0pd\0point\0iterations\0bilinarVariables\0", 9557LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_BilinearInterpolate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pa\0pb\0pc\0pd\0s\0t\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateSignedTriangleArea_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0c\0normal\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateMeanValueCoordinatesWeights_2)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "point\0outline\0normal\0weights\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculatePerimeterLength2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IsWoundClockwise2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateOutlineCentroidAndArea2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0area\0windingPolarity\0", 41LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateMultiOutlineCentroidAndAreas2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "loopVertices\0loopVertexCounts\0includeHolesInCogCalcs\0overallArea\0loopSoloAreas\0windingPolarity\0", 2709LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateConvexHull2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateConvexDecomposition2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CleanLoop2DInPlace)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePoints\0maintainStart\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonForConvex)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0relativeBToA\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0relativeBToA\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateInnerFitPolygonUsingSliding)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsCcwA\0outlinePointsB\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonForConvex_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0transformA\0transformB\0relativeBToA\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateNoFitPolygonUsingSliding_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0transformA\0transformB\0relativeBToA\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateUnionOfPolygons)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0includeHolesInResult\0createOuterLoop\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_IntersectsSegmentsExact2D)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "segment1Point1\0segment1Point2\0segment2Point1\0segment2Point2\0intersectionPoint\0areParallel\0intersectionPoint2\0tolerance\0", 27221LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_GetContainmentStateForNonIntersectingLoops)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlinePointsA\0outlinePointsB\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_AreLoopsEqualToWithinTolerance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "loopA\0loopB\0allowCyclicRotation\0ignoreTranslationOffset\0tol\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_CalculateBoundingBoxIndices)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "verts\0minIdxX\0maxIdxX\0minIdxY\0maxIdxY\0findMostCounterClockwise\0", 1705LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GeometryUtilsInterface::MTable::_instance.GeometryUtilsInterface_ArePointsCoLinearWithinTolerance)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0tol\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&GeometryUtilsInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_GeometryUtilsInterface("net.maxon.geom.geometryutils", nullptr, &RegisterReflection_GeometryUtilsInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
