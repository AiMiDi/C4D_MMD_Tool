#ifndef VORONOI3D_H__
#define VORONOI3D_H__

#include "maxon/apibase.h"
#include "maxon/delaunay3d.h"
#include "maxon/celldata.h"

namespace maxon
{
class Delaunay3DRef;

//----------------------------------------------------------------------------------------
/// Voronoi3D provides functions for creating a 3D Voronoi representation of points.
//----------------------------------------------------------------------------------------
class Voronoi3DInterface
{
	MAXON_INTERFACE_NONVIRTUAL(Voronoi3DInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.voronoi3d");

public:

	static MAXON_METHOD Voronoi3DInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	MAXON_METHOD Result<void> Init(const Range<Vector>& workSpace);

	//----------------------------------------------------------------------------------------
	/// Copies the contents of src into this object.
	/// @param[in] src								The object to copy from.
	/// @param[in] resizeFlags				Resize flag for collections.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE);

	//----------------------------------------------------------------------------------------
	/// Checks if the Voronoi data structure is ready, even through the data might need recalculation.
	/// @return												True if a Voronoi data structure is ready.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsReadyButPendingChanges();

	//----------------------------------------------------------------------------------------
	/// Checks if the current object state is the finished data with no pending changes.
	/// @return												True if all calculations were performed and no pending changes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsReady();

	//----------------------------------------------------------------------------------------
	/// Sets a list of points as Voronoi sites. Only these will be used, and old points will be reset
	/// @param[in] points							Points to set for this Voronoi object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetPoints(const BaseArray<Vector>& points);

	//----------------------------------------------------------------------------------------
	/// Add a single point to the current set of points.
	/// @param[in] pointIn						Point to add for this Voronoi object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddPoint(const Vector& pointIn);

	//----------------------------------------------------------------------------------------
	/// Adds a list of points as Voronoi sites to the current set of points.
	/// @param[in] points							Points to add for this Voronoi object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddPoints(const BaseArray<Vector>& points);

	//----------------------------------------------------------------------------------------
	/// Performs a Voronoi calculation on the current set of points.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalcCells();

	//----------------------------------------------------------------------------------------
	/// Performs the pre-step of calculating a Delaunay tetrahedralization.
	/// if CalcCells() is called after this, the calcualted tetrahedralization will be reused.
	/// If CalcCells() is called without this being called, it will perform it automatically.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalcTetrahedralization();

	//----------------------------------------------------------------------------------------
	/// Set a flag that will trigger some extra calculations in die Voronoi algorithm.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetForClipping(Bool clipping);

	//----------------------------------------------------------------------------------------
	/// Gets the amount of cells.
	/// @return												The amount of cells.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCellCount();

	//----------------------------------------------------------------------------------------
	/// Gets the point positions
	/// @return												Reference to the list holding the site positions.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Vector>& GetVoronoiPointPositions() const;

	//----------------------------------------------------------------------------------------
	/// Gets the point positions
	/// @return												Reference to the list holding the site positions.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Vector>& GetInputPoints() const;

	//----------------------------------------------------------------------------------------
	/// Gets the flag list of that defines if a cell is a border cell.
	/// This is only set if the algorithm was set for clipping.
	/// @return												Reference to the list holding the border flags.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<BaseArray<Bool>> GetBorderCellFlags();

	//----------------------------------------------------------------------------------------
	/// Gets the final data structure of the Voronoi 3D diagram.
	/// @return												Reference to the list holding the full cell data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<BaseArray<CellData>> GetCellDataStructure();

	//----------------------------------------------------------------------------------------
	/// Gets a list of flags, that defines for every cell, if it still has a volume.
	/// This will be true for every start cell and can only be false if a cell got scaled.
	/// @return												Reference to the list holding the flag if a cell still has volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<BaseArray<Char>> GetCellHasVolume();

	//----------------------------------------------------------------------------------------
	/// Scales one cell (cellIndex) in the Voronoi data structure
	/// @param[in] cellIndex					The index of the cell to scale
	/// @param[in] scaleValue					Scale amount
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ScaleCell(Int cellIndex, Float scaleValue);

	//----------------------------------------------------------------------------------------
	/// Scales all cells in the Voronoi data structure.
	/// @param[in] scaleValue					Scale amount.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ScaleAllCells(Float scaleValue);

	//----------------------------------------------------------------------------------------
	/// Gets the internal Delaunay3D tetrahedralization class.
	/// @return												Reference to the internal Delaunay3D.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<Delaunay3DRef> GetDelaunayTetrizer();

	//----------------------------------------------------------------------------------------
	/// Resets the object for a fresh calculation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	//----------------------------------------------------------------------------------------
	/// Sets a list of indices to be one group. These points will be fused to one cell in generation.
	/// If an index is set to fuse in an earlier call, it will be ignored.
	/// This needs to be called after points are set or it will not have any effect.
	/// @param[in] fuseIndices				The list of indices to be fused.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCellFuseGroup(BaseArray<Int>& fuseIndices);

	//----------------------------------------------------------------------------------------
	/// Fuses the cells declared in a list of neighbor pairs into each other.
	/// @param[in] joinList						The neighbor pairs of cells that should be fused.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FuseCells(BaseArray<Pair<Int, Int>>& joinList);

	//----------------------------------------------------------------------------------------
	/// Inverts the whole Voronoi data structure.
	/// this is done by inverting all faces of the cells and fusing all into one cell.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateInvertedVoronoiCell();
};

#include "voronoi3d1.hxx"
#include "voronoi3d2.hxx"

}	// namespace maxon



#endif // VORONOI3D_H__
