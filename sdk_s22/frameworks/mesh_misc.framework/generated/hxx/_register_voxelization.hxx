#if 1
namespace maxon
{
	const maxon::Char* const VoxelizationInterface::MTable::_ids = 
		"Init@6c14f567312d41f1\0" // Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise)
		"Init@38c5768c59c9d7bb\0" // Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride)
		"Init@18d0adae972d90a9\0" // Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
		"Init@0d5dfea35b55f785\0" // Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
		"GetClosestPolys@5ab8d001307ef717\0" // Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const
		"GetIntersectingIndices@fc43c2771e5baf85\0" // Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const
		"GetIntersectingIndicesPrecise@f913b4b8333419de\0" // Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const
		"GetIntersectingIndices@1b6120f8492eb04c\0" // Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const
		"GetBoundingBox@20f752d745e4b91e\0" // const Range<Vector>& GetBoundingBox() const
		"GetVoxelRangesFromBoundingBox@4cd15218ab5b843c\0" // Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const
		"IsInitialized@76f01901\0" // Bool IsInitialized() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VoxelizationInterface, , "net.maxon.geom.interface.voxelization", "maxon.VoxelizationInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int VoxelizationInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Range<IntVector32>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Range<Vector>&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PolyVoxelization, , "net.maxon.geom.interface.voxelization.polyvoxelization");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_voxelization(0
	| maxon::VoxelizationInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
