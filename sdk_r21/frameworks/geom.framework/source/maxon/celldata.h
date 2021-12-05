#ifndef CELLDATA_H__
#define CELLDATA_H__

#include "maxon/apibase.h"
#include "maxon/string.h"
#include "maxon/vector.h"
#include "maxon/range.h"

namespace maxon
{
//----------------------------------------------------------------------------------------
/// CellEdge struct respresents an edge in the Voronoi Cell data. It saves indices to the start and endpoint of the edge
/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
//----------------------------------------------------------------------------------------
struct CellEdge
{
	CellEdge() = default;
	CellEdge(Int start, Int end, Int nextEdgeOfFace, Int prevEdgeOfFace, Int reverseEdge) :
		_start(start), _end(end), _nextEdgeOfFace(nextEdgeOfFace), _prevEdgeOfFace(prevEdgeOfFace), _reverseEdge(reverseEdge) {}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return "(start: "_s + String::IntToString(_start) + ", end:"_s + String::IntToString(_end) + ", next:"_s + String::IntToString(_nextEdgeOfFace) + ", prev:"_s + String::IntToString(_prevEdgeOfFace) + ", reverse:"_s + String::IntToString(_reverseEdge) + ")"_s;
	}

	Int _start = NOTOK;
	Int _end = NOTOK;
	Int _nextEdgeOfFace = NOTOK;
	Int _prevEdgeOfFace = NOTOK;
	Int _reverseEdge = NOTOK;
};

static const Float POINT_FUSE_EPS = 1.0e-5;

//----------------------------------------------------------------------------------------
/// CellData struct is a datacontainer that represents a single Voronoi Cell
//----------------------------------------------------------------------------------------
class CellData
{
	friend class Voronoi3DImpl;
public:
	MAXON_DISALLOW_COPY_AND_ASSIGN(CellData);
	CellData() = default;
	CellData(CellData&& src) = default;
	MAXON_OPERATOR_MOVE_ASSIGNMENT(CellData);

	~CellData() = default;

	//----------------------------------------------------------------------------------------
	/// Copies the contents of src into this object.
	/// @param[in] src								The object to copy from.
	/// @param[in] resizeFlags				Resize flag for collections.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const CellData& src, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE);

	//----------------------------------------------------------------------------------------
	/// Resets this cell to an empty cell.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Resets this cell to an empty cell (keeps memory).
	//----------------------------------------------------------------------------------------
	void Flush();

	//----------------------------------------------------------------------------------------
	/// Scales the current cell by a specific value.
	/// @param[in] scaleValue					the amout the cell will be scaled by.
	/// @return												if the scaling succeded.
	//----------------------------------------------------------------------------------------
	Result<Bool> ScaleCell(Float scaleValue);

	//----------------------------------------------------------------------------------------
	/// This cell checks the current cell data structure and optimizes it.
	/// @return												true if everything worked out, otherwise false.
	//----------------------------------------------------------------------------------------
	Result<Bool> FixGeometry();

	//----------------------------------------------------------------------------------------
	/// Gets the vertex list of this cell (writable).
	/// @return												Reference to vertex array.
	//----------------------------------------------------------------------------------------
	BaseArray<Vector>& GetVertices();

	//----------------------------------------------------------------------------------------
	/// Gets the edge list of this cell (writable).
	/// @return												Reference to edge array.
	//----------------------------------------------------------------------------------------
	BaseArray<CellEdge>& GetEdges();

	//----------------------------------------------------------------------------------------
	/// Gets the face list of this cell (writable).
	/// @return												Reference to face array.
	//----------------------------------------------------------------------------------------
	BaseArray<Int>& GetFaces();

	//----------------------------------------------------------------------------------------
	/// Gets the adjacent cell list of this cell (writable).
	/// @return												Reference to the adjacent cell array.
	//----------------------------------------------------------------------------------------
	BaseArray<Int32>& GetAdjacentCells();

	//----------------------------------------------------------------------------------------
	/// Gets the vertex list of this cell (not writable).
	/// @return												Constant reference to vertex array.
	//----------------------------------------------------------------------------------------
	const BaseArray<Vector>& GetVertices() const;

	//----------------------------------------------------------------------------------------
	/// Gets the edge list of this cell (not writable).
	/// @return												Constant reference to edge array.
	//----------------------------------------------------------------------------------------
	const BaseArray<CellEdge>& GetEdges() const;

	//----------------------------------------------------------------------------------------
	/// Gets the face list of this cell (not writable).
	/// @return												Constant reference to face array.
	//----------------------------------------------------------------------------------------
	const BaseArray<Int>& GetFaces() const;

	//----------------------------------------------------------------------------------------
	/// Gets the adjacent cell list of this cell (not writable).
	/// @return												Constant reference to adjacent cell array.
	//----------------------------------------------------------------------------------------
	const BaseArray<Int32>& GetAdjacentCells() const;

	//----------------------------------------------------------------------------------------
	/// Returns if this cell is complex (most likely not convex)
	/// @return												Reference to face array.
	//----------------------------------------------------------------------------------------
	Bool IsComplex() const;

	//----------------------------------------------------------------------------------------
	/// Tests if a passed point is inside of the cell.
	/// @param[in] point							Point to test if it is inside.
	/// @return												True if point is inside cell, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool TestPointWithCell(const Vector& point) const;

	//----------------------------------------------------------------------------------------
	/// Merges another cell into this one.
	/// @param[in] thisCellFaces			The faces of this cell that should be removed.
	/// @param[in] neighbourCell			The other cell to fuse into this one.
	/// @param[in] otherCellFaces			The faces of the other cell to remove.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeCells(const BaseArray<Int>& thisCellFaces, const CellData& neighbourCell, const BaseArray<Int>& otherCellFaces);

	//----------------------------------------------------------------------------------------
	/// Fuses another cell into this one. The wall between the cells is removed if they are neighbors.
	/// @param[in] thisCellIndex			The external index of this cell.
	/// @param[in] neighbourCell			The neighbor cell that should be fused.
	/// @param[in] otherCellIndex			The external index of the neighbor cell.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> FuseCells(Int thisCellIndex, CellData& neighbourCell, Int otherCellIndex);


	//----------------------------------------------------------------------------------------
	/// Calculates the Normal of a pointloop face of the cell.
	/// @param[in] faceIndex					The index of the cell to calculate the normal for.
	/// @return												The normal of the face.
	//----------------------------------------------------------------------------------------
	Vector CreateCellFaceNormal(Int faceIndex) const;

	//----------------------------------------------------------------------------------------
	/// Adds the data of a different cell to this one. Indices are translated.
	/// @param[in] otherCell					The other cell whose data should be added
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AddCellData(const CellData& otherCell);

	//----------------------------------------------------------------------------------------
	/// Calculates and returns the Axis Aligned Bounding Box of the cell.
	/// @return												The Bounding Box of the cell
	//----------------------------------------------------------------------------------------
	Range<Vector> GetBoundingBox() const;

private:
	void MarkAllUsedPoints(BaseArray<Int>& pointUseless, Int mark = NOTOK);
	void MarkAllDoublePoints(BaseArray<Int>& pointUseless, Bool& pointRemoved, Float epsilonOverride = 0.0);
	Result<Bool> MarkAllColinearPoints(BaseArray<Int>& pointUseless, Bool& pointRemoved, Float epsilonOverride = 0.0);
	Result<Bool> MarkAllUselessPoints(BaseArray<Int>& pointUseless, Bool& pointRemoved);
	Result<Bool> ReCreateCellWithOnlyUsefulPoints(BaseArray<Int>& pointUseless);
	Result<void> CalcAllFaceNormals(BaseArray<Vector>& faceNormals);
	Bool SetupReverseEdges();
	Result<void> CleanupUnusedPoints();

	Bool TestCurrentDataStructure(BaseArray<Char>& faceRemoved);
	Result<void> ExpandCellByValue(const  BaseArray<Vector>& planeNormals, const BaseArray<Int32>& edgeToFaceBelonging, Float offset, BaseArray<Vector>& pointDisplacements);
	Result<Bool> ShrinkCellByValue(const  BaseArray<Vector>& planeNormals, Float offset);
	Result<Bool> CutCellOnPlane(const Pair<Vector, Vector>& plane, Int32 planeNeighborIndex = NOTOK);
	Result<Bool> CutFaceOnPlane(Int faceIndex, const Pair<Vector, Vector>& plane, const BaseArray<Float>& pointToCutPlaneDistance, const BaseArray<Int>& edgeIntesection, const BaseArray<Int>& pointTranslateMap, BaseArray<CellEdge>& newEdges, BaseArray<CellEdge>& newFaceEdges);
	Result<Bool> ProcessInsideFaceAndAddToEdges(const BaseArray<CellEdge>& newFaceEdges, Int pointCount, BaseArray<CellEdge>& newEdges);
	Result<Int> IntersectEdgeOnPlane(const Pair<Vector, Vector>& planeBaseArray, Int edgeIndex, BaseArray<Vector>& newPoints);
	Result<void> MergePointsInCutData(BaseArray<Vector>& newPoints, BaseArray<CellEdge>& newEdges, BaseArray<Int>& newFaces, BaseArray<CellEdge>& newFaceEdges);
	Result<void> RemoveIsolatedPoints();
	Result<void> FusePoints(BaseArray<Int>& affectedPoints);
	Result<void> RemoveFace(Int faceIndex, BaseArray<Int>& affectedPoints);

	BaseArray<Int>		_verticesPreIndex;

	BaseArray<Vector>		_vertices;
	BaseArray<CellEdge> _edges;
	BaseArray<Int>			_faces;
	BaseArray<Int32>		_adjacentCell;

	Bool _isComplex = false;
};
}
#endif // CELLDATA_H__
