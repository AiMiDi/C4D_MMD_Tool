#ifndef VOXELIZATION_H__
#define VOXELIZATION_H__

#include "maxon/interface.h"
#include "maxon/baselist.h"
#include "maxon/vector.h"
#include "maxon/lib_math.h"
#include "maxon/range.h"
#include "maxon/parallelfor.h"
#include "maxon/hashmap.h"
#include "maxon/basebitset.h"


class PolygonObject;

namespace maxon
{
struct ConvexHullData;
//----------------------------------------------------------------------------------------
/// VoxelizationInterface provides a class for building up a voxelization of different kinds of index based mesh data structures.
//----------------------------------------------------------------------------------------
class VoxelizationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(VoxelizationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.geom.interface.voxelization");

public:

	//----------------------------------------------------------------------------------------
	/// Initializes the voxelization with a polygon object.
	/// @param[in] polyObject					Pointer to the polygon object to be added to the voxelization.
	/// @param[in] voxelResolution		The voxel resolution of the largest dimension.
	/// @param[in] minResolution			The minimal resolution of either dimension.
	/// @param[out] polyRanges				Calculated bounding boxes for every polygon.
	/// @param[in] pointOverride			Override option for the polygon points. If not nullptr, these points will be used for the polygon vertices.
	/// @param[in] precise						If true, only the voxels touching a polygon will hold the specific polygon index. If false, all voxels touching the polygon AABB will hold the polygon index.
	/// @return												True if the voxelization was properly initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride = nullptr, Bool precise = false);
	
	
	//----------------------------------------------------------------------------------------
	/// Initializes the voxelization with a polygon object.
	/// @param[in] polyObject					Pointer to the polygon object to be added to the voxelization.
	/// @param[in] polyIslands				A list of polygon indices. Only those polygons will be added to the voxelization.
	/// @param[in] voxelResolution		The voxel resolution of the largest dimension.
	/// @param[in] minResolution			The minimal resolution of either dimension.
	/// @param[out] polyRanges				Calculated bounding boxes for every polygon.
	/// @param[in] pointOverride			Override option for the polygon points. If not nullptr, these points will be used for the polygon vertices.
	/// @return												True if the voxelization was properly initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Initializes the voxelization with a convex hull data struct.
	/// @param[in] hull								The convex hull data to be added to the voxelization.
	/// @param[in] voxelResolution		The voxel resolution of the largest dimension.
	/// @param[in] minResolution			The minimal resolution of either dimension.
	/// @param[out] polyRanges				Calculated bounding boxes for every polygon.
	/// @return												True if the voxelization was properly initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);

	//----------------------------------------------------------------------------------------
	/// Initializes the voxelization with a list of polygon indices and points.
	/// @param[in] facePoints					A list of list holding the point indices for each polygon.
	/// @param[in] points							The vertex positions.
	/// @param[in] voxelResolution		The voxel resolution of the largest dimension.
	/// @param[in] minResolution			The minimal resolution of either dimension.
	/// @param[out] polyRanges				Calculated bounding boxes for every polygon.
	/// @return												True if the voxelization was properly initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);
	
	//----------------------------------------------------------------------------------------
	/// Retrieve the polygon indices of the closest polygons to a point in space.
	/// @param[in] pos								The position in space to test for.
	/// @param[out] voxelPolys				A bitset with the closest polygon indices set.
	/// @param[in] polyFilter					An optional bitset with polygon indices set that should be respected. if nullptr all initialized polygons can be found.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the polygon indices of all polygons stored in voxels overlappint a axis-aligned bounding box.
	/// @param[in] toTestBox					The bounding box to find the polygon indices for.
	/// @param[out] indexList					A list of polygon indices that are stored in voxels overlapping the passed bounding box.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the polygon indices of all polygons stored in voxels overlapping a axis-aligned bounding box.
	/// @param[in] toTestBox					The bounding box to find the polygon indices for.
	/// @param[in] polyRanges					The bounding box for each polygon. This list can be retrieved from the initialization of the voxelization.
	/// @param[out] indexList					A list of polygon indices that are stored in voxels overlapping the passed bounding box.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the polygon indices of all polygons stored in the voxel that contains the passed point.
	/// @param[in] point							The point to find the polygon indices for.
	/// @param[out] indexList					A list of polygon indices that are stored in voxel containing the passed point.
	/// @return												True if the point was inside of a voxel, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the bounding box of the voxelization.
	/// @return												The bounding box as range of all voxels of this voxelization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Range<Vector>& GetBoundingBox() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the voxel ranges for a passed bounding box.
	/// @return												A voxel range bounding box with minimum and maximum indices in each dimension.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the initialization state of the voxelization.
	/// @return												True if the voxelization is initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsInitialized() const;
};

#include "voxelization1.hxx"

MAXON_DECLARATION(Class<VoxelizationRef>, PolyVoxelization, "net.maxon.geom.interface.voxelization.polyvoxelization");

#include "voxelization2.hxx"

}
#endif // VOXELIZATION_H__
