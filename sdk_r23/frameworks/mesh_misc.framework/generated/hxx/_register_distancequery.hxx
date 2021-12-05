#if 1
namespace maxon
{
	namespace enum24 { enum class PRIMITIVETYPE
	{
		NONE = 0,
		POINT = 1,
		EDGE = 2,
		POLYGON = 3
	} ; }
	maxon::String PrivateToString_PRIMITIVETYPE24(std::underlying_type<enum24::PRIMITIVETYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::PRIMITIVETYPE::NONE, (maxon::UInt64) enum24::PRIMITIVETYPE::POINT, (maxon::UInt64) enum24::PRIMITIVETYPE::EDGE, (maxon::UInt64) enum24::PRIMITIVETYPE::POLYGON};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PRIMITIVETYPE", SIZEOF(x), false, values, "NONE\0POINT\0EDGE\0POLYGON\0", fmt);
	}
	const maxon::Char* const DistanceQueryInterface::MTable::_ids = 
		"Init@bc2dbad9749ca758\0" // Result<void> Init(PolygonObject* mesh, Bool initVoxelization)
		"Init@e521e765642f54c3\0" // Result<void> Init(SplineObject* spline)
		"Init@c41ce8ae2a6813da\0" // Result<void> Init(LineObject* line)
		"Init@931f0603da97c33c\0" // Result<void> Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition)
		"Reset@780cdac8f1a33934\0" // void Reset()
		"GetClosestMeshPrimitive@d618aca5b687d81a\0" // Float GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const
		"GetDistanceToMesh@145036e14a976e29\0" // void GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
		"GetDistanceToMeshMaxAngleToDirection@1fbc6d407ae53bf0\0" // void GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
		"GetDistanceToSpline@15fd6ac2021a8406\0" // void GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const
		"IsInitialized@12e73654e6d65520\0" // Bool IsInitialized() const
		"SetThreading@26d30ab205d458\0" // void SetThreading(Int32 threads)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DistanceQueryInterface, , "net.maxon.geom.interface.distancequery", "maxon.DistanceQueryInterface", (ObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DistanceCalculator, , "net.maxon.geom.interface.distancequery.distancecalculator");
}
#endif
