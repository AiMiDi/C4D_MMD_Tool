#if 1
namespace maxon
{
	namespace enum23 { enum class PRIMITIVETYPE
	{
		NONE = 0,
		POINT = 1,
		EDGE = 2,
		POLYGON = 3
	} ; }
	maxon::String PrivateToString_PRIMITIVETYPE23(std::underlying_type<enum23::PRIMITIVETYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum23::PRIMITIVETYPE::NONE, (maxon::UInt64) enum23::PRIMITIVETYPE::POINT, (maxon::UInt64) enum23::PRIMITIVETYPE::EDGE, (maxon::UInt64) enum23::PRIMITIVETYPE::POLYGON};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PRIMITIVETYPE", SIZEOF(x), false, values, "NONE\0POINT\0EDGE\0POLYGON\0", fmt);
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DistanceQueryInterface, "net.maxon.geom.interface.distancequery", "maxon.DistanceQueryInterface", , &Object::_interface);
	const maxon::Char* const DistanceQueryInterface::MTable::_ids = 
		"Init@ebe29c72202ac9ed\0" // Init(PolygonObject* mesh, Bool initVoxelization)
		"Init@d635c588e0f19a02\0" // Init(SplineObject* spline)
		"Init@5afabcd52479467f\0" // Init(LineObject* line)
		"Reset@6b2e10f\0" // Reset()
		"GetClosestMeshPrimitive@64c36cce4ad2c26d\0" // GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const
		"GetDistanceToMesh@c1156ece050777e2\0" // GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
		"GetDistanceToMeshMaxAngleToDirection@6c6bacf921d1a4ef\0" // GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
		"GetDistanceToSpline@b5a6f89a881c9079\0" // GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const
		"IsInitialized@76f01901\0" // IsInitialized() const
		"SetThreading@b6e5268c2debf\0" // SetThreading(Int32 threads)
	"";
	template <typename DUMMY> maxon::Int DistanceQueryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DistanceCalculator, , "net.maxon.geom.interface.distancequery.distancecalculator");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_distancequery(0
	| maxon::DistanceQueryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
