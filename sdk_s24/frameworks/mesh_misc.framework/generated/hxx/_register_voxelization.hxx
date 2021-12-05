#if 1
namespace maxon
{
	const maxon::Char* const VoxelizationInterface::MTable::_ids = 
		"Init@ae8bd7e0976b868a\0" // Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise)
		"Init@7eaed2bf261252b8\0" // Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride)
		"Init@2749a14bfa531180\0" // Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
		"Init@585fb78aad898c78\0" // Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
		"GetClosestPolys@97c5d1d94363cf42\0" // Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const
		"GetIntersectingIndices@389c754be3fe59c0\0" // Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const
		"GetIntersectingIndicesPrecise@6c64e7449d594851\0" // Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const
		"GetIntersectingIndices@5a9b5b8dfd6f0b83\0" // Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const
		"GetBoundingBox@4ab7145ac5f3f851\0" // const Range<Vector>& GetBoundingBox() const
		"GetVoxelRangesFromBoundingBox@a673abd46d4ec8d3\0" // Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const
		"IsInitialized@12e73654e6d65520\0" // Bool IsInitialized() const
	"";
	const maxon::METHOD_FLAGS VoxelizationInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VoxelizationInterface, , "net.maxon.geom.interface.voxelization", "maxon.VoxelizationInterface", (ObjectInterface::PrivateGetInterface()));
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
