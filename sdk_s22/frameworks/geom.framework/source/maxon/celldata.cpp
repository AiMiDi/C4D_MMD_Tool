#include "celldata.h"
#include "maxon/vector2d.h"
#include "maxon/hashmap.h"

namespace maxon
{
void CellData::Reset()
{
	_faces.Reset();
	_vertices.Reset();
	_verticesPreIndex.Reset();
	_edges.Reset();
	_adjacentCell.Reset();
}

void CellData::Flush()
{
	_faces.Flush();
	_vertices.Flush();
	_verticesPreIndex.Flush();
	_edges.Flush();
	_adjacentCell.Flush();
}

Result<void> CellData::RemoveFace(Int removeFaceIndex, BaseArray<Int>& affectedPoints)
{
	iferr_scope;
	BaseArray<Int32> removeEdge;
	removeEdge.Resize(_edges.GetCount()) iferr_return;

	BaseArray<Int32> removeEdgeShift;
	removeEdgeShift.Resize(_edges.GetCount()) iferr_return;

	Int curEdgeIndex = _faces[removeFaceIndex];
	Int startEdgeIndex = curEdgeIndex;
	Int edgesRemoved = 0;

	do
	{
		CellEdge& curEdge = _edges[curEdgeIndex];
		edgesRemoved++;
		removeEdge[curEdgeIndex] = 1;

		curEdgeIndex = curEdge._nextEdgeOfFace;
	} while (curEdgeIndex != startEdgeIndex);

	Int32 edgeShift = 0;
	for (Int edgeIndex = 0; edgeIndex < removeEdge.GetCount(); edgeIndex++)
	{
		edgeShift += removeEdge[edgeIndex];
		removeEdgeShift[edgeIndex] = edgeShift;
	}
	BaseArray<CellEdge> newEdges;
	newEdges.Resize(_edges.GetCount() - edgesRemoved) iferr_return;
	BaseArray<Int> newFaces;
	BaseArray<Int32> newAdjacentCells;
	Int newEdgeIndex = 0;
	Int newFaceIndex = 0;
	for (Int faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
	{
		newFaceIndex = newEdgeIndex;
		Int edgeIndex = _faces[faceIndex];
		Int startIndex = edgeIndex;

		if (faceIndex != removeFaceIndex)
		{
			do
			{
				CellEdge& curEdge = _edges[edgeIndex];
				CellEdge& targetEdge = newEdges[newEdgeIndex];
				targetEdge = curEdge;
				// shift all indices into new list
				targetEdge._prevEdgeOfFace -= removeEdgeShift[targetEdge._prevEdgeOfFace];
				targetEdge._nextEdgeOfFace -= removeEdgeShift[targetEdge._nextEdgeOfFace];
				if (targetEdge._reverseEdge != NOTOK)
				{
					if (removeEdge[targetEdge._reverseEdge] == 1)
						targetEdge._reverseEdge = NOTOK;
					else
						targetEdge._reverseEdge -= removeEdgeShift[targetEdge._reverseEdge];
				}
				newEdgeIndex++;

				edgeIndex = curEdge._nextEdgeOfFace;
			} while (edgeIndex != startIndex);

			if (newFaces.GetCount() == 0 || newFaceIndex != newFaces[newFaces.GetCount() - 1])
			{
				newFaces.Append(newFaceIndex) iferr_return;
				newAdjacentCells.Append(_adjacentCell[faceIndex]) iferr_return;
			}
		}
		else
		{
			do
			{
				CellEdge& curEdge = _edges[edgeIndex];
				affectedPoints.Append(curEdge._start) iferr_return;
				edgeIndex = curEdge._nextEdgeOfFace;
			} while (edgeIndex != startIndex);
		}
	}

	_adjacentCell = std::move(newAdjacentCells);
	_edges = std::move(newEdges);
	_faces = std::move(newFaces);
	return OK;
}

Result<void> CellData::FusePoints(BaseArray<Int>& affectedPoints)
{
	iferr_scope;

	BaseArray<Int> pointTranslate;
	pointTranslate.Resize(_vertices.GetCount()) iferr_return;

	for (Int& pointTarg : pointTranslate)
		pointTarg = NOTOK;

	// find all vertices that are too close to each other and mark the found point as useless
	for (Int32 vertAffIndex = 0; vertAffIndex < affectedPoints.GetCount(); vertAffIndex++)
	{
		Int& vertIndex = affectedPoints[vertAffIndex];
		if (pointTranslate[vertIndex] == NOTOK)
		{
			for (Int32 vertSearchAffIndex = vertAffIndex + 1; vertSearchAffIndex < affectedPoints.GetCount(); vertSearchAffIndex++)
			{
				Int& vertSearchIndex = affectedPoints[vertSearchAffIndex];
				if (pointTranslate[vertSearchIndex] == NOTOK)
				{
					Float edgeLength = (_vertices[vertSearchIndex] - _vertices[vertIndex]).GetLength();
					if (edgeLength < POINT_FUSE_EPS)
					{
						pointTranslate[vertSearchIndex] = vertIndex;
					}
				}
			}
		}
	}
	for (CellEdge& curEdge : _edges)
	{
		if (pointTranslate[curEdge._start] != NOTOK)
		{
			curEdge._start = pointTranslate[curEdge._start];
		}
		if (pointTranslate[curEdge._end] != NOTOK)
		{
			curEdge._end = pointTranslate[curEdge._end];
		}
	}

	return OK;
}

Result<void> CellData::AddCellData(const CellData& otherCell)
{
	iferr_scope;

	// remember old sizes for data shifts
	Int oldEdgeCount = _edges.GetCount();
	Int oldFaceCount = _faces.GetCount();
	Int oldVertexCount = _verticesPreIndex.GetCount();

	_edges.AppendAll(otherCell._edges) iferr_return;
	_faces.AppendAll(otherCell._faces) iferr_return;
	_verticesPreIndex.AppendAll(otherCell._verticesPreIndex) iferr_return;
	_adjacentCell.AppendAll(otherCell._adjacentCell) iferr_return;
	// translate old edg indices
	for (Int startEdgeIndex = oldEdgeCount; startEdgeIndex < _edges.GetCount(); startEdgeIndex++)
	{
		CellEdge& curEdge = _edges[startEdgeIndex];
		curEdge._nextEdgeOfFace = curEdge._nextEdgeOfFace + oldEdgeCount;
		curEdge._prevEdgeOfFace = curEdge._prevEdgeOfFace + oldEdgeCount;
		curEdge._reverseEdge = curEdge._reverseEdge + oldEdgeCount;
		curEdge._start = curEdge._start + oldVertexCount;
		curEdge._end = curEdge._end + oldVertexCount;
	}

	// translate old face indices
	for (Int startFaceIndex = oldFaceCount; startFaceIndex < _faces.GetCount(); startFaceIndex++)
	{
		_faces[startFaceIndex] = _faces[startFaceIndex] + oldEdgeCount;
	}
	return OK;
}

Result<void> CellData::CleanupUnusedPoints()
{
	iferr_scope;
	BaseArray<Int32> unusedPoints;
	unusedPoints.Resize(_vertices.GetCount()) iferr_return;

	for (Int32& curPos : unusedPoints)
		curPos = 1;

	for (Int faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
	{
		Int edgeIndex = _faces[faceIndex];
		Int startIndex = edgeIndex;
		do
		{
			CellEdge& curEdge = _edges[edgeIndex];
			unusedPoints[curEdge._end] = 0;

			edgeIndex = curEdge._nextEdgeOfFace;
		} while (edgeIndex != startIndex);
	}

	Int removedPoints = 0;
	for (Int pointIndex = 0; pointIndex < _vertices.GetCount(); pointIndex++)
	{
		if (unusedPoints[pointIndex] == 1)
			removedPoints++;
	}

	BaseArray<Vector> newVertices;
	newVertices.Resize(_vertices.GetCount() - removedPoints) iferr_return;

	Int copyPosition = 0;

	for (Int pointIndex = 0; pointIndex < _vertices.GetCount(); pointIndex++)
	{
		if (unusedPoints[pointIndex] == 1)
			continue;

		newVertices[copyPosition] = _vertices[pointIndex];
		copyPosition++;
	}


	Int32 pointShift = 0;
	for (Int pointIndex = 0; pointIndex < unusedPoints.GetCount(); pointIndex++)
	{
		pointShift += unusedPoints[pointIndex];
		unusedPoints[pointIndex] = pointShift;
	}

	for (Int edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		CellEdge& curEdge = _edges[edgeIndex];
		curEdge._start -= unusedPoints[curEdge._start];
		curEdge._end -= unusedPoints[curEdge._end];
	}
	

	_vertices = std::move(newVertices);
	return OK;
}
Result<void> CellData::FuseCells(Int thisCellIndex, CellData& neighbourCell, Int otherCellIndex)
{
	iferr_scope;
	// prepare datastructures for the clipped cell
	BaseArray<Int> pointTranslateMap;

	BaseArray<Int> affectedPoints;

	for (Int faceIndex = _faces.GetCount() - 1; faceIndex >= 0; faceIndex--)
	{
		const Int otherCell = _adjacentCell[faceIndex];
		if (otherCell == otherCellIndex)
		{
			RemoveFace(faceIndex, affectedPoints) iferr_return;
		}
	}

	for (Int faceIndex = neighbourCell._faces.GetCount() - 1; faceIndex >= 0; faceIndex--)
	{
		Int affectedPointsCountPrev = affectedPoints.GetCount();
		const Int& otherCell = neighbourCell.GetAdjacentCells()[faceIndex];
		if (otherCell == thisCellIndex)
		{
			neighbourCell.RemoveFace(faceIndex, affectedPoints) iferr_return;
		}

		for (Int pointIndex = affectedPointsCountPrev; pointIndex < affectedPoints.GetCount(); pointIndex++)
		{
			affectedPoints[pointIndex] += _vertices.GetCount();
		}
	}
	// append all new points to the cell
	Int cellOnePointCount = _vertices.GetCount();
	Int cellOneEdgeCount = _edges.GetCount();

	_vertices.AppendAll(neighbourCell._vertices) iferr_return;
	_verticesPreIndex.AppendAll(neighbourCell._verticesPreIndex) iferr_return;
	_edges.EnsureCapacity(_edges.GetCount() + neighbourCell._edges.GetCount()) iferr_return;
	_faces.EnsureCapacity(_faces.GetCount() + neighbourCell._faces.GetCount()) iferr_return;

	for (Int faceIndex = 0; faceIndex < neighbourCell._faces.GetCount(); faceIndex++)
	{
		if (neighbourCell._adjacentCell[faceIndex] == thisCellIndex)
		{
			Int edgeIndex = neighbourCell._faces[faceIndex];
			Int startIndex = edgeIndex;
			do
			{
				const CellEdge& curEdgeRef = neighbourCell._edges[edgeIndex];

				affectedPoints.Append(curEdgeRef._end + cellOnePointCount) iferr_return;
				edgeIndex = curEdgeRef._nextEdgeOfFace;
			} while (edgeIndex != startIndex);

			continue;
		}

		Int newFaceIndex = _edges.GetCount();

		Int edgeIndex = neighbourCell._faces[faceIndex];
		Int startIndex = edgeIndex;
		do
		{
			const CellEdge& curEdgeRef = neighbourCell._edges[edgeIndex];
			CellEdge curEdge = curEdgeRef;

			// shift all indices into new list
			curEdge._start += cellOnePointCount;
			curEdge._end += cellOnePointCount;
			curEdge._reverseEdge += cellOneEdgeCount;
			curEdge._nextEdgeOfFace += cellOneEdgeCount;
			curEdge._prevEdgeOfFace += cellOneEdgeCount;
			// add all edges of this face to the new Cell
			_edges.Append(std::move(curEdge)) iferr_return;

			edgeIndex = curEdgeRef._nextEdgeOfFace;
		} while (edgeIndex != startIndex);

		if (newFaceIndex != _faces.GetCount())
		{
			_faces.Append(newFaceIndex) iferr_return;
			_adjacentCell.Append(neighbourCell._adjacentCell[faceIndex]) iferr_return;
		}
	}

	FusePoints(affectedPoints) iferr_return;
	CleanupUnusedPoints() iferr_return;
	neighbourCell.Reset();

	if (!SetupReverseEdges())
		return IllegalStateError(MAXON_SOURCE_LOCATION);

	return OK;
}

Result<void> CellData::MergeCells(const BaseArray<Int>& thisCellFaces, const CellData& neighbourCell, const BaseArray<Int>& otherCellFaces)
{
	iferr_scope;
	// prepare datastructures for the clipped cell
	BaseArray<Int> pointTranslateMap;

	// append all new points to the cell
	Int cellOnePointCount = _vertices.GetCount();
	Int cellOneEdgeCount = _edges.GetCount();
	Int cellOneFaceCount = _faces.GetCount();
	_vertices.AppendAll(neighbourCell._vertices) iferr_return;
	_verticesPreIndex.AppendAll(neighbourCell._verticesPreIndex) iferr_return;
	_edges.EnsureCapacity(_edges.GetCount() + neighbourCell._edges.GetCount()) iferr_return;
	_faces.EnsureCapacity(_faces.GetCount() + neighbourCell._faces.GetCount()) iferr_return;

	for (Int faceIndex = 0; faceIndex < neighbourCell._faces.GetCount(); faceIndex++)
	{
		Int newFaceIndex = _edges.GetCount();

		Int edgeIndex = neighbourCell._faces[faceIndex];
		Int startIndex = edgeIndex;
		do
		{
			const CellEdge& curEdgeRef = neighbourCell._edges[edgeIndex];
			CellEdge curEdge = curEdgeRef;

			// shift all indices into new list
			curEdge._start += cellOnePointCount;
			curEdge._end += cellOnePointCount;
			curEdge._reverseEdge += cellOneEdgeCount;
			curEdge._nextEdgeOfFace += cellOneEdgeCount;

			// add all edges of this face to the new Cell
			_edges.Append(std::move(curEdge)) iferr_return;

			edgeIndex = curEdgeRef._nextEdgeOfFace;
		} while (edgeIndex != startIndex);

		if (newFaceIndex != _faces.GetCount())
		{
			_faces.Append(newFaceIndex) iferr_return;
			_adjacentCell.Append(neighbourCell._adjacentCell[faceIndex]) iferr_return;
		}
	}

	BaseArray<Int> affectedPoints;

	for (Int faceTwoIndex = otherCellFaces.GetCount() - 1; faceTwoIndex >= 0; faceTwoIndex--)
	{
		const Int& cellTwoFace = otherCellFaces[faceTwoIndex];
		RemoveFace(cellOneFaceCount + cellTwoFace, affectedPoints) iferr_return;
	}
	for (Int faceOneIndex = thisCellFaces.GetCount() - 1; faceOneIndex >= 0; faceOneIndex--)
	{
		const Int& cellOneFace = thisCellFaces[faceOneIndex];
		RemoveFace(cellOneFace, affectedPoints) iferr_return;
	}

	FusePoints(affectedPoints) iferr_return;
	return OK;
}

// marks every used point in an array with NOTOK or the given mark int
void CellData::MarkAllUsedPoints(BaseArray<Int>& pointUseless, Int mark)
{
	for (Int edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		CellEdge& curEdge = _edges[edgeIndex];
		pointUseless[curEdge._start] = mark;
		pointUseless[curEdge._end] = mark;
	}
}

Result<void> CellData::RemoveIsolatedPoints()
{
	iferr_scope;

	BaseArray<Int> pointUseless;
	pointUseless.Resize(_vertices.GetCount()) iferr_return;

	for (Int& pointTarg : pointUseless)
		pointTarg = -3;

	MarkAllUsedPoints(pointUseless);

	BaseArray<Vector> newPoints;
	newPoints.Resize(_vertices.GetCount()) iferr_return;
	Int pointShift = 0;
	Int pointIndex = 0;
	Int usefulCount = 0;
	for (Int& curShift : pointUseless)
	{
		if (curShift == -3)
		{
			pointShift++;
		}
		else
		{
			curShift = pointShift;
			newPoints[usefulCount] = _vertices[pointIndex];
			usefulCount++;
		}

		pointIndex++;
	}
	newPoints.Resize(usefulCount, COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE) iferr_return;

	_vertices = std::move(newPoints);

	for (Int edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		CellEdge& curEdge = _edges[edgeIndex];
		curEdge._start -= pointUseless[curEdge._start];
		curEdge._end -= pointUseless[curEdge._end];
	}

	return OK;
}

Result<void> CellData::CopyFrom(const CellData& src, COLLECTION_RESIZE_FLAGS resizeFlags)
{
	iferr_scope;

	_vertices.CopyFrom(src._vertices, resizeFlags) iferr_return;
	_verticesPreIndex.CopyFrom(src._verticesPreIndex, resizeFlags) iferr_return;
	_edges.CopyFrom(src._edges, resizeFlags) iferr_return;
	_faces.CopyFrom(src._faces, resizeFlags) iferr_return;
	_adjacentCell.CopyFrom(src._adjacentCell, resizeFlags) iferr_return;
	_isComplex = src._isComplex;
	return OK;
}

Bool CellData::TestCurrentDataStructure(BaseArray<Char>& faceRemoved)
{
	for (Int faceIndexTest = 0; faceIndexTest < _faces.GetCount(); faceIndexTest++)
	{
		if (faceRemoved[faceIndexTest])
			continue;

		Int curEdgeIndex = _faces[faceIndexTest];
		Int lastEdge = NOTOK;
		Int startIndex = curEdgeIndex;
		Bool error = false;
		Int cellEdgeCounter = 0;
		CellEdge* curEdge = nullptr;
		do
		{
			curEdge = &_edges[curEdgeIndex];

			if (curEdge->_reverseEdge == -1)
			{
				error = true;
				break;
			}
			CellEdge& nextEdge = _edges[curEdge->_nextEdgeOfFace];
			CellEdge& reverseEdge = _edges[curEdge->_reverseEdge];
			CellEdge& prevEdge = _edges[curEdge->_prevEdgeOfFace];

			if (prevEdge._reverseEdge == curEdgeIndex || nextEdge._reverseEdge == curEdgeIndex)
				error = true;

			cellEdgeCounter++;
			if (curEdge->_end != nextEdge._start)
				error = true;


			if (reverseEdge._reverseEdge != curEdgeIndex)
				error = true;

			if (cellEdgeCounter == 1000)
				error = true;

			if (lastEdge != NOTOK && curEdge->_prevEdgeOfFace != lastEdge)
				error = true;

			lastEdge = curEdgeIndex;
			curEdgeIndex = curEdge->_nextEdgeOfFace;
		} while (curEdgeIndex != startIndex && !error);

		if (error)
		{
			return false;
		}
	}
	return true;
}
Result<Bool> CellData::ProcessInsideFaceAndAddToEdges(const BaseArray<CellEdge>& newFaceEdges, Int pointCount, BaseArray<CellEdge>& newEdges)
{
	iferr_scope;

	Int curEdgeIndex = 0;
	Int startIndex = 0;

	Int possibleFirstEdge = newEdges.GetCount();
	BaseArray<Int> outgoingEdge;
	outgoingEdge.Resize(pointCount, COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;
	for (Int& curEdge : outgoingEdge)
	{
		curEdge = NOTOK;
	}

	for (Int edgeIndex = 0; edgeIndex < newFaceEdges.GetCount(); edgeIndex++)
	{
		if (newFaceEdges[edgeIndex]._start != newFaceEdges[edgeIndex]._end)
			outgoingEdge[newFaceEdges[edgeIndex]._start] = edgeIndex;
	}

	Int addCounter = 0;
	do
	{
		CellEdge curEdge = newFaceEdges[curEdgeIndex];
		if (addCounter == 0)
			startIndex = curEdgeIndex;

		if (outgoingEdge[curEdge._end] == NOTOK)
			return false;

		curEdgeIndex = outgoingEdge[curEdge._end];

		if (curEdge._start != curEdge._end)
		{
			curEdge._nextEdgeOfFace = newEdges.GetCount() + 1;
			curEdge._prevEdgeOfFace = newEdges.GetCount() - 1;
			newEdges.Append(std::move(curEdge)) iferr_return;

			addCounter++;
		}


		if (addCounter > newFaceEdges.GetCount())
			return false;

	} while (curEdgeIndex != startIndex);


	if (possibleFirstEdge != newEdges.GetCount())
	{
		newEdges[newEdges.GetCount() - 1]._nextEdgeOfFace = possibleFirstEdge;
		newEdges[possibleFirstEdge]._prevEdgeOfFace = newEdges.GetCount() - 1;
	}

	return true;
}

Result<Bool> CellData::CutFaceOnPlane(const Int faceIndex, const Pair<Vector, Vector>& plane, const BaseArray<Float>& pointToCutPlaneDistance, const BaseArray<Int>& edgeIntesection, const BaseArray<Int>& pointTranslateMap, BaseArray<CellEdge>& newEdges, BaseArray<CellEdge>& newFaceEdges)
{
	iferr_scope;

	Int startIndex = _faces[faceIndex];
	Int curEdgeIndex = startIndex;

	Int startEdgeIndex = newEdges.GetCount();
	Int curStartPoint = NOTOK;
	Bool currentlyOutside = false;
	do
	{
		const CellEdge& curEdge = _edges[curEdgeIndex];
		const Float& startDist = pointToCutPlaneDistance[curEdge._start];
		const Float& endDist = pointToCutPlaneDistance[curEdge._end];

		if (curStartPoint == NOTOK && startDist < 0.0)
		{
			curStartPoint = pointTranslateMap[curEdge._start];
			startIndex = curEdgeIndex;
		}

		if (curStartPoint != NOTOK && (endDist <= 0.0 || edgeIntesection[curEdgeIndex] != NOTOK))
		{


			CellEdge newEdge;
			newEdge._start = curStartPoint;
			newEdge._end = edgeIntesection[curEdgeIndex] != NOTOK ? edgeIntesection[curEdgeIndex] : pointTranslateMap[curEdge._end];
			newEdge._prevEdgeOfFace = newEdges.GetCount() - 1;
			newEdge._nextEdgeOfFace = newEdges.GetCount() + 1;
			curStartPoint = newEdge._end;

			if (currentlyOutside)
			{
				CellEdge newEdgeInside;
				newEdgeInside._start = newEdge._end;
				newEdgeInside._end = newEdge._start;
				newFaceEdges.Append(std::move(newEdgeInside)) iferr_return;
			}

			newEdges.Append(std::move(newEdge)) iferr_return;

			if (edgeIntesection[curEdgeIndex] != NOTOK && endDist < 0)
			{


				CellEdge newEdgeTwo;
				newEdgeTwo._start = edgeIntesection[curEdgeIndex];
				newEdgeTwo._end = pointTranslateMap[curEdge._end];
				newEdgeTwo._prevEdgeOfFace = newEdges.GetCount() - 1;
				newEdgeTwo._nextEdgeOfFace = newEdges.GetCount() + 1;

				curStartPoint = newEdgeTwo._end;

				newEdges.Append(std::move(newEdgeTwo)) iferr_return;
			}



			if ((startDist < 0 && endDist >= 0.0) || (startDist >= 0 && endDist < 0) || edgeIntesection[curEdgeIndex] != NOTOK)
				currentlyOutside = !currentlyOutside;
		}

		curEdgeIndex = curEdge._nextEdgeOfFace;
	} while (curEdgeIndex != startIndex);

	if (startEdgeIndex != newEdges.GetCount())
	{
		newEdges[newEdges.GetCount() - 1]._nextEdgeOfFace = startEdgeIndex;
		newEdges[startEdgeIndex]._prevEdgeOfFace = newEdges.GetCount() - 1;
	}

	return true;
}

inline Bool IntersectRayPlane(const Vector& origin, const Vector& direction, const Vector& center, const Vector& normal, Float& lambda)
{
	Float denom = Dot(normal, direction);

	// epsilon test in case of parallel Ray and Plane
	if (Abs(denom) > 1e-14)
	{
		lambda = Dot((center - origin), normal) / denom;
		return true;
	}
	return false;
}


inline Bool IntersectLineSegments2D(const Vector2d& startOne, const  Vector2d& endOne, const Vector2d& startTwo, const Vector2d& endTwo, Float& lambda1, Float& lambda2)
{

	Vector2d dirOne = endOne - startOne;
	Vector2d dirTwo = endTwo - startTwo;


	Float denom = -dirTwo[0] * dirOne[1] + dirOne[0] * dirTwo[1];
	if (Abs(denom) == 0)
		return false;

	Bool denomPositive = denom > 0;

	Float numerOne = -dirOne[1] * (startOne[0] - startTwo[0]) + dirOne[0] * (startOne[1] - startTwo[1]);
	if ((numerOne < 0) == denomPositive)
		return false; // No collision


	Float numerTwo = dirTwo[0] * (startOne[1] - startTwo[1]) - dirTwo[1] * (startOne[0] - startTwo[0]);
	if ((numerTwo < 0) == denomPositive)
		return false; // No collision


	if (((numerOne > denom) == denomPositive) || ((numerTwo > denom) == denomPositive))
		return false; // No collision

	lambda1 = numerOne / denom;
	lambda2 = numerTwo / denom;

	// Collision detected
	return true;
}

Result<Int> CellData::IntersectEdgeOnPlane(const Pair<Vector, Vector>& plane, const Int edgeIndex, BaseArray<Vector>& newPoints)
{
	iferr_scope;
	const CellEdge& curEdge = _edges[edgeIndex];

	const Vector& startPoint = _vertices[curEdge._start];
	const Vector& endPoint = _vertices[curEdge._end];

	const Vector& curPlaneNormal = plane.GetSecond();
	const Vector& onMovePlanePoint = plane.GetFirst();

	Float lambda = NOTOK;
	Vector edgeDir = endPoint - startPoint;

	if (IntersectRayPlane(startPoint, edgeDir, onMovePlanePoint, curPlaneNormal, lambda))
	{
		// add the new point and add the point to hashmap for current edgekey
		Int newPointIndex = newPoints.GetCount();
		newPoints.Append(startPoint + lambda * edgeDir) iferr_return;
		return newPointIndex;
	}
	return NOTOK;
}

Result<void> CellData::MergePointsInCutData(BaseArray<Vector>& newPoints, BaseArray<CellEdge>& newEdges, BaseArray<Int>& newFaces, BaseArray<CellEdge>& newFaceEdges)
{
	iferr_scope;

	BaseArray<Int> pointUseless;
	pointUseless.Resize(newPoints.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;
	for (Int& curIndex : pointUseless)
		curIndex = NOTOK;

	Bool pointRemoved = false;
	Int32 removedCount = 0;
	Float usedEpsilon = POINT_FUSE_EPS;
	// find all vertices that are too close to each other and mark the found point as useless
	for (Int32 vertIndex = 0; vertIndex < newPoints.GetCount(); vertIndex++)
	{
		if (pointUseless[vertIndex] == NOTOK)
		{
			for (Int32 vertSearchIndex = vertIndex + 1; vertSearchIndex < newPoints.GetCount(); vertSearchIndex++)
			{
				if (pointUseless[vertSearchIndex] == NOTOK)
				{
					Float edgeLength = (newPoints[vertSearchIndex] - newPoints[vertIndex]).GetLength();
					if (edgeLength < usedEpsilon)
					{
						pointRemoved = true;
						removedCount++;
						pointUseless[vertSearchIndex] = vertIndex;
					}
				}
			}
		}
	}

	if (pointRemoved)
	{
		maxon::BaseArray<Vector> reducedPointArray;

		reducedPointArray.Resize(newPoints.GetCount() - removedCount, COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

		maxon::BaseArray<Int> oldToNewTranslation;
		oldToNewTranslation.Resize(newPoints.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;
		Int32 addedPoints = 0;
		for (Int32 curPointIndex = 0; curPointIndex < newPoints.GetCount(); curPointIndex++)
		{
			if (pointUseless[curPointIndex] == NOTOK)
			{
				reducedPointArray[addedPoints] = newPoints[curPointIndex];
				oldToNewTranslation[curPointIndex] = addedPoints;
				addedPoints++;
			}
			else
			{
				oldToNewTranslation[curPointIndex] = NOTOK;
			}


		}
		newPoints = std::move(reducedPointArray);

		for (Int edgeIndex = 0; edgeIndex < newEdges.GetCount(); edgeIndex++)
		{
			if (pointUseless[newEdges[edgeIndex]._start] != NOTOK)
			{
				newEdges[edgeIndex]._start = oldToNewTranslation[pointUseless[newEdges[edgeIndex]._start]];
			}
			else
			{
				newEdges[edgeIndex]._start = oldToNewTranslation[newEdges[edgeIndex]._start];
			}

			if (pointUseless[newEdges[edgeIndex]._end] != NOTOK)
			{
				newEdges[edgeIndex]._end = oldToNewTranslation[pointUseless[newEdges[edgeIndex]._end]];
			}
			else
			{
				newEdges[edgeIndex]._end = oldToNewTranslation[newEdges[edgeIndex]._end];
			}

			if (newEdges[edgeIndex]._start == newEdges[edgeIndex]._end)
			{
				for (Int edgeIndexCorrect = 0; edgeIndexCorrect < newEdges.GetCount(); edgeIndexCorrect++)
				{
					if (edgeIndexCorrect == edgeIndex)
						continue;

					CellEdge& curEdge = newEdges[edgeIndexCorrect];

					if (curEdge._nextEdgeOfFace == edgeIndex)
						curEdge._nextEdgeOfFace = newEdges[edgeIndex]._nextEdgeOfFace;

					if (curEdge._nextEdgeOfFace > edgeIndex)
						curEdge._nextEdgeOfFace--;

					if (curEdge._prevEdgeOfFace == edgeIndex)
						curEdge._prevEdgeOfFace = newEdges[edgeIndex]._prevEdgeOfFace;

					if (curEdge._prevEdgeOfFace > edgeIndex)
						curEdge._prevEdgeOfFace--;
				}

				for (Int faceIndexCorrect = 0; faceIndexCorrect < newFaces.GetCount(); faceIndexCorrect++)
				{
					if (newFaces[faceIndexCorrect] > edgeIndex)
						newFaces[faceIndexCorrect]--;
				}
				newEdges.Erase(edgeIndex, 1) iferr_cannot_fail("The algorithm has been broken.");
				edgeIndex--;
			}
		}

		for (Int edgeIndex = 0; edgeIndex < newFaceEdges.GetCount(); edgeIndex++)
		{
			if (pointUseless[newFaceEdges[edgeIndex]._start] != NOTOK)
			{
				newFaceEdges[edgeIndex]._start = oldToNewTranslation[pointUseless[newFaceEdges[edgeIndex]._start]];
			}
			else
			{
				newFaceEdges[edgeIndex]._start = oldToNewTranslation[newFaceEdges[edgeIndex]._start];
			}

			if (pointUseless[newFaceEdges[edgeIndex]._end] != NOTOK)
			{
				newFaceEdges[edgeIndex]._end = oldToNewTranslation[pointUseless[newFaceEdges[edgeIndex]._end]];
			}
			else
			{
				newFaceEdges[edgeIndex]._end = oldToNewTranslation[newFaceEdges[edgeIndex]._end];
			}

		}
	}
	return OK;
}


Result<Bool> CellData::CutCellOnPlane(const Pair<Vector, Vector>& plane, Int32 planeNeighborIndex)
{
	iferr_scope;

	// prepare datastructures for the clipped cell
	BaseArray<CellEdge> newEdges;
	BaseArray<Int> newFaces;
	BaseArray<Int32> newAdjacentCells;
	BaseArray<Vector> newPoints;
	BaseArray<Int> pointTranslateMap;
	pointTranslateMap.Resize(_vertices.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;
	for (Int& mapIndex : pointTranslateMap)
		mapIndex = NOTOK;

	const Vector& curPlaneNormal = plane.GetSecond();
	const Vector& onMovePlanePoint = plane.GetFirst();

	BaseArray<Float> pointToCutPlaneDistance;
	pointToCutPlaneDistance.Resize(_vertices.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

	Float offsetEpsilon = 1e-9;

	// for each of the current vertices, check the distance to the cutplane.
	// if it is too close to the cutplane, the point will be moved inside the plane
	// the distance (also moved distance) will be saved in an array and used for cutdecisions
	for (Int32 vertexIndex = 0; vertexIndex < pointToCutPlaneDistance.GetCount(); vertexIndex++)
	{
		Vector& curPoint = _vertices[vertexIndex];

		Float dotPoint = Dot(curPoint - onMovePlanePoint, curPlaneNormal);

		// if point to close to plane
		if (Abs(dotPoint) < offsetEpsilon)
		{
			dotPoint = 0.0;
		}

		if (dotPoint <= 0.0)
		{
			pointTranslateMap[vertexIndex] = newPoints.GetCount();
			newPoints.Append(curPoint) iferr_return;
		}

		// save distance
		pointToCutPlaneDistance[vertexIndex] = dotPoint;
	}
	// in case the cell is fully cut away by the plane
	if (newPoints.GetCount() == 0)
		return false;

	// calculate intersection points of each edge, that has points on different sides of the plane
	// the intersection point is added to the new Points and its index is saved for every edge.
	// a hashmap is used to prevent 2 points to be added for the doubleedged datastructure
	BaseArray<Int> edgeIntesection;
	edgeIntesection.Resize(_edges.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

	for (Int& edgeIntersectIndex : edgeIntesection)
		edgeIntersectIndex = NOTOK;

	// in this hashmap all intersections will be saved, so they are not created multiple times
	HashMap<Int64, Int> edgeIntersections;

	for (Int32 edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		const CellEdge& curEdge = _edges[edgeIndex];
		if (Sign(pointToCutPlaneDistance[curEdge._start]) != Sign(pointToCutPlaneDistance[curEdge._end]))
		{

			// calculate the edge hashkey to save the point
			Int64 edgeKey;
			if (curEdge._start > curEdge._end)
			{
				edgeKey = Int64(curEdge._start) << 32 | Int32(curEdge._end);
			}
			else
			{
				edgeKey = Int64(curEdge._end) << 32 | Int32(curEdge._start);
			}

			HashMap<Int64, Int>::Entry* e = edgeIntersections.Find(edgeKey);

			// if the point has not yet been added
			// else use the point from hashmap
			if (!e)
			{
				edgeIntesection[edgeIndex] = IntersectEdgeOnPlane(plane, edgeIndex, newPoints) iferr_return;
				edgeIntersections.Insert(edgeKey, edgeIntesection[edgeIndex]) iferr_return;
			}
			else
			{
				edgeIntesection[edgeIndex] = e->GetValue();
			}

		}
	}


	// container to collect all edges of the new face
	BaseArray<CellEdge> newFaceEdges;

	// cut the faces on the plane with the collected data
	Int edgesBeforeCut = NOTOK;
	for (Int32 faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
	{
		// remember the possible facestart
		edgesBeforeCut = newEdges.GetCount();

		// cut the current face on the plane
		Result<Bool> cutRes = CutFaceOnPlane(faceIndex, plane, pointToCutPlaneDistance, edgeIntesection, pointTranslateMap, newEdges, newFaceEdges) iferr_return;

		if (!cutRes.GetValue())
			return false;

		// if the cut added new edges, add the facestart to faces
		if (newEdges.GetCount() > edgesBeforeCut)
		{
			newAdjacentCells.Append(_adjacentCell[faceIndex]) iferr_return;
			newFaces.Append(edgesBeforeCut) iferr_return;
		}
	}

	MergePointsInCutData(newPoints, newEdges, newFaces, newFaceEdges) iferr_return;

	if (newFaceEdges.GetCount() > 0)
	{
		Int prevEdgeCount = newEdges.GetCount();
		Result<Bool> cutRes2 = ProcessInsideFaceAndAddToEdges(newFaceEdges, newPoints.GetCount(), newEdges) iferr_return;

		if (!cutRes2.GetValue())
			return false;

		newAdjacentCells.Append(planeNeighborIndex) iferr_return;
		newFaces.Append(prevEdgeCount) iferr_return;
	}



	// replace the old cell with the new data
	_adjacentCell = std::move(newAdjacentCells);
	_vertices = std::move(newPoints);
	_edges = std::move(newEdges);
	_faces = std::move(newFaces);

	if (!SetupReverseEdges())
		return false;

	return true;
}


Result<Bool> CellData::ShrinkCellByValue(const BaseArray<Vector>& planeNormals, Float offset)
{
	iferr_scope;

	Int originalFaceCount = _faces.GetCount();

	BaseArray<Pair<Vector, Vector>> cutPlanes;
	for (Int faceIndex = 0; faceIndex < originalFaceCount; faceIndex++)
	{
		CellEdge& planeStartEdge = _edges[_faces[faceIndex]];
		Vector& startPoint = _vertices[planeStartEdge._start];
		const Vector& curPlaneNormal = planeNormals[faceIndex];
		Vector onMovePlanePoint = startPoint + offset * curPlaneNormal;

		cutPlanes.Append(Pair<Vector, Vector>(onMovePlanePoint, curPlaneNormal)) iferr_return;
	}

	BaseArray<Int32> originalPlaneNeighbor;
	originalPlaneNeighbor.CopyFrom(_adjacentCell) iferr_return;

	// iterate through all faces to clip the complete cell on the offsetted plane of that face
	for (Int planeIndex = 0; planeIndex < cutPlanes.GetCount(); planeIndex++)
	{
		Vector& planeNormal = cutPlanes[planeIndex].GetSecond();

		if (planeNormal.x != 0.0 || planeNormal.y != 0.0 || planeNormal.z != 0.0)
		{
			Result<Bool> cutRes = CutCellOnPlane(cutPlanes[planeIndex], originalPlaneNeighbor[planeIndex]) iferr_return;

			if (!cutRes.GetValue())
				return false;
		}
	}

	return true;
}


Result<void> CellData::ExpandCellByValue(const  BaseArray<Vector>& planeNormals, const BaseArray<Int32>& edgeToFaceBelonging, Float offset, BaseArray<Vector>& pointDisplacements)
{
	iferr_scope;

	BaseArray<Char> vertexProcessed;
	vertexProcessed.Resize(_vertices.GetCount()) iferr_return;

	// traverse through all faces to make sure every vertex has been touched with an adjecent edge
	for (Int32 faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
	{
		Int startEdgeIndex = _faces[faceIndex];
		Int curEdgeIndex = startEdgeIndex;

		CellEdge* startEdge = &_edges[startEdgeIndex];
		CellEdge* curEdge = startEdge;
		do
		{
			// if the endvertex of this edge has not yet been processed calculate the correct move out of the adjecent planes
			if (!vertexProcessed[curEdge->_end])
			{
				vertexProcessed[curEdge->_end] = 1;

				CellEdge& nextEdge = _edges[curEdge->_nextEdgeOfFace];


				Int neighborStartEdgeIndex = curEdge->_reverseEdge;
				Int neighborCurEdgeIndex = neighborStartEdgeIndex;
				CellEdge* neighborStartEdge = &_edges[neighborStartEdgeIndex];
				CellEdge* neighborCurEdge = neighborStartEdge;
				CellEdge* prevNeighborEdge = nullptr;
				do
				{
					if (neighborCurEdge->_nextEdgeOfFace == neighborStartEdgeIndex)
					{
						prevNeighborEdge = neighborCurEdge;
						break;
					}
					neighborCurEdgeIndex = neighborCurEdge->_nextEdgeOfFace;
					neighborCurEdge = &_edges[neighborCurEdgeIndex];
				} while (neighborCurEdgeIndex != neighborStartEdgeIndex);

				// ExactFloat

				const Vector& midPoint = _vertices[curEdge->_end];
				const Vector& edge1Start = _vertices[prevNeighborEdge->_start];
				const Vector& edge2Start = _vertices[nextEdge._end];
				const Vector& edge3Start = _vertices[curEdge->_start];
				//const Vector& edge4Start = _vertices[nextReverseNextEdge.end];

				const Vector& plane1Normal = planeNormals[faceIndex];
				const Vector& plane2Normal = planeNormals[edgeToFaceBelonging[curEdge->_reverseEdge]];
				const Vector& plane3Normal = planeNormals[edgeToFaceBelonging[nextEdge._reverseEdge]];


				Vector offsettetPlanePoint1 = midPoint + offset * plane1Normal;
				Vector offsettetPlanePoint2 = midPoint + offset * plane2Normal;
				Vector offsettetPlanePoint3 = midPoint + offset * plane3Normal;

				Vector edgeDir1 = midPoint - edge1Start;
				Vector edgeDir2 = midPoint - edge2Start;
				Vector edgeDir3 = midPoint - edge3Start;
				edgeDir3.Normalize();
				//Vector edgeDir4 = midPoint - edge4Start;


				Float lambdaEdge1;
				IntersectRayPlane(edge1Start, edgeDir1, offsettetPlanePoint1, plane1Normal, lambdaEdge1);
				Vector edgeMove1 = edgeDir1 * (lambdaEdge1 - 1);



				Float lambdaEdge2;
				IntersectRayPlane(edge2Start, edgeDir2, offsettetPlanePoint2, plane2Normal, lambdaEdge2);
				Vector edgeMove2 = edgeDir2 * (lambdaEdge2 - 1);


				Float lambdaEdge3;
				IntersectRayPlane(midPoint + edgeMove1 + edgeMove2, edgeDir3, offsettetPlanePoint3, plane3Normal, lambdaEdge3);

				Vector displace = edgeMove1 + edgeMove2 + lambdaEdge3* edgeDir3;

				pointDisplacements[curEdge->_end] = displace;

			}
			curEdgeIndex = curEdge->_nextEdgeOfFace;
			curEdge = &_edges[curEdgeIndex];
		} while (curEdgeIndex != startEdgeIndex);

	}

	return OK;
}

Result<void> CellData::CalcAllFaceNormals(BaseArray<Vector>& faceNormals)
{
	for (Int32 faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
	{
		Vector normal = Vector(0, 0, 0);

		Int startEdgeIndex = _faces[faceIndex];
		Int curEdgeIndex = startEdgeIndex;
		do
		{
			CellEdge& curEdge = _edges[curEdgeIndex];

			const Vector& point1 = _vertices[curEdge._start];
			const Vector& point2 = _vertices[curEdge._end];

			normal.x = normal.x + ((point1.y - point2.y) * (point1.z + point2.z));
			normal.y = normal.y + ((point1.z - point2.z) * (point1.x + point2.x));
			normal.z = normal.z + ((point1.x - point2.x) * (point1.y + point2.y));

			curEdgeIndex = curEdge._nextEdgeOfFace;
		} while (curEdgeIndex != startEdgeIndex);

		Float length = normal.GetLength();
		if (length > 1e-10)
		{
			normal /= length;
			faceNormals[faceIndex] = normal;
		}
		else
		{
			faceNormals[faceIndex] = Vector(0.0);
		}
	}
	return OK;
}

Result<Bool> CellData::ScaleCell(Float scaleValue)
{
	iferr_scope;

	if (Abs(scaleValue) < 1e-4)
		return true;

	BaseArray<Vector> faceNormals;
	faceNormals.Resize(_faces.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

	CalcAllFaceNormals(faceNormals) iferr_return;

	if (scaleValue < 0)
	{
		Result<Bool> shrinkRes = ShrinkCellByValue(faceNormals, scaleValue) iferr_return;
		if (!shrinkRes.GetValue())
		{
			_adjacentCell.Flush();
			_vertices.Flush();
			_edges.Flush();
			_faces.Flush();

			return false;
		}
	}

	return true;
}

Bool CellData::SetupReverseEdges()
{
	for (Int32 edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		CellEdge& curEdge = _edges[edgeIndex];
		curEdge._reverseEdge = NOTOK;
	}

	// iterate through all created edges to find the reverse edge
	for (Int32 edgeIndex = 0; edgeIndex < _edges.GetCount(); edgeIndex++)
	{
		CellEdge& curEdge = _edges[edgeIndex];

		// this edge does not know its reverse yet
		if (curEdge._reverseEdge == NOTOK)
		{
			Bool foundEdge = false;
			for (Int32 searchEdgeIndex = edgeIndex + 1; searchEdgeIndex < _edges.GetCount(); searchEdgeIndex++)
			{
				CellEdge& curSearchEdge = _edges[searchEdgeIndex];

				// if end and start is reversed in this edge, then this seachedge is the reverse edge
				if (curSearchEdge._reverseEdge == NOTOK && curEdge._end == curSearchEdge._start && curEdge._start == curSearchEdge._end)
				{
					foundEdge = true;

					curEdge._reverseEdge = searchEdgeIndex;
					curSearchEdge._reverseEdge = edgeIndex;
					break;
				}
			}

			if (!foundEdge)
				return false;
		}
	}

	return true;
}


// this calculates a unnormalized PointLoop normal using the Newell's method
Vector CellData::CreateCellFaceNormal(const Int faceIndex) const
{
	Vector normal = Vector(0, 0, 0);

	Int edgeStart = _faces[faceIndex];
	Int curEdgeIndex = edgeStart;

	Int failCounter = 0;
	do
	{
		const CellEdge& curEdge = _edges[curEdgeIndex];

		const Vector& point1 = _vertices[curEdge._start];
		const Vector& point2 = _vertices[curEdge._end];

		normal.x = normal.x + ((point1.y - point2.y) * (point1.z + point2.z));
		normal.y = normal.y + ((point1.z - point2.z) * (point1.x + point2.x));
		normal.z = normal.z + ((point1.x - point2.x) * (point1.y + point2.y));

		curEdgeIndex = curEdge._nextEdgeOfFace;

		failCounter++;
		if (failCounter == 5000)
			return Vector(0, 0, 0);

	} while (edgeStart != curEdgeIndex);

	normal.Normalize();
	return normal;
}

Bool CellData::TestPointWithCell(const Vector& point) const
{
	if (!_isComplex)
	{

		for (Int faceIndex = 0; faceIndex < _faces.GetCount(); faceIndex++)
		{
			Int faceStart = _faces[faceIndex];
			const CellEdge& startEdge = _edges[faceStart];


			const Vector& point1 = _vertices[startEdge._start];

			Vector normal = CreateCellFaceNormal(faceIndex); // normal to plane
			Float dotProd = Dot(normal, point - point1);
			if (dotProd > 0)
				return false;
		}
		if (_faces.GetCount() > 0)
			return true;
		else
			return false;
	}
	else
	{
		return true;
	}
}

void CellData::MarkAllDoublePoints(BaseArray<Int>& pointUseless, Bool& pointRemoved, Float epsilonOverride)
{
	iferr_scope;

	if (_vertices.GetCount() == 0 && _verticesPreIndex.GetCount() > 0)
	{
		for (Int32 vertIndex = 0; vertIndex < _verticesPreIndex.GetCount(); vertIndex++)
		{
			if (pointUseless[vertIndex] == NOTOK)
			{
				for (Int32 vertSearchIndex = vertIndex + 1; vertSearchIndex < _verticesPreIndex.GetCount(); vertSearchIndex++)
				{
					if (pointUseless[vertSearchIndex] == NOTOK)
					{
						if (_verticesPreIndex[vertSearchIndex] == _verticesPreIndex[vertIndex])
						{
							pointRemoved = true;
							pointUseless[vertSearchIndex] = vertIndex;
						}
					}
				}
			}
		}
	}
	else
	{
		Float usedEpsilon = epsilonOverride != 0.0 ? epsilonOverride : POINT_FUSE_EPS;
		// find all vertices that are too close to each other and mark the found point as useless
		for (Int32 vertIndex = 0; vertIndex < _vertices.GetCount(); vertIndex++)
		{
			if (pointUseless[vertIndex] == NOTOK)
			{
				for (Int32 vertSearchIndex = vertIndex + 1; vertSearchIndex < _vertices.GetCount(); vertSearchIndex++)
				{
					if (pointUseless[vertSearchIndex] == NOTOK)
					{
						Float edgeLength = (_vertices[vertSearchIndex] - _vertices[vertIndex]).GetLength();
						if (edgeLength < usedEpsilon)
						{
							pointRemoved = true;
							pointUseless[vertSearchIndex] = vertIndex;
						}
					}
				}
			}
		}
	}
}

Result<Bool> CellData::MarkAllColinearPoints(BaseArray<Int>& pointUseless, Bool& pointRemoved, Float epsilonOverride)
{
	iferr_scope;

	Float usedEpsilon = epsilonOverride != 0.0 ? epsilonOverride : POINT_FUSE_EPS;

	for (const Int& faceStart : _faces)
	{
		Int startEdgeIndex = faceStart;
		Int curEdgeIndex = startEdgeIndex;
		Int lastPoint = NOTOK;
		Int currentPoint = NOTOK;
		Int nextPoint = NOTOK;
		Vector lastEdge;
		Vector nextEdge;

		const CellEdge& curEdgestart = _edges[curEdgeIndex];


		lastPoint = curEdgestart._start;
		currentPoint = curEdgestart._end;
		lastEdge = _vertices[lastPoint] - _vertices[currentPoint];
		startEdgeIndex = curEdgestart._nextEdgeOfFace;
		curEdgeIndex = startEdgeIndex;


		do
		{

			const CellEdge& curEdge = _edges[curEdgeIndex];

			nextPoint = curEdge._end;
			nextEdge = _vertices[nextPoint] - _vertices[currentPoint];

			if (pointUseless[currentPoint] != -2)
			{
				Vector parallelogram = Cross(lastEdge, nextEdge);
				Float trianglesize = parallelogram.GetSquaredLength();

				if (trianglesize < usedEpsilon)
				{
					if (Sign(lastEdge[0]) != Sign(nextEdge[0]) && Sign(lastEdge[1]) != Sign(nextEdge[1]) && Sign(lastEdge[2]) != Sign(nextEdge[2]))
					{
						pointRemoved = true;
						pointUseless[currentPoint] = nextPoint;
					}
				}
			}
			currentPoint = nextPoint;
			lastEdge = -nextEdge;


			curEdgeIndex = curEdge._nextEdgeOfFace;
		} while (curEdgeIndex != startEdgeIndex);
	}

	return true;
}

Result<Bool> CellData::MarkAllUselessPoints(BaseArray<Int>& pointUseless, Bool& pointRemoved)
{
	iferr_scope;

	for (const Int& faceStart : _faces)
	{
		Int startEdgeIndex = faceStart;
		Int curEdgeIndex = startEdgeIndex;
		do
		{
			const CellEdge& curEdge = _edges[curEdgeIndex];
			if (pointUseless[curEdge._end] != -1)
			{
				const CellEdge& nextEdge = _edges[curEdge._nextEdgeOfFace];
				const CellEdge& nextEdgeReverse = _edges[nextEdge._reverseEdge];

				if (nextEdgeReverse._nextEdgeOfFace == curEdge._reverseEdge)
				{
					pointRemoved = true;
					pointUseless[curEdge._end] = -2;
				}
				else
				{
					pointUseless[curEdge._end] = -1;
				}
			}
			curEdgeIndex = curEdge._nextEdgeOfFace;
		} while (curEdgeIndex != startEdgeIndex);
	}

	return true;
}


inline Int ReturnCorrectNewVertexIndex(maxon::BaseArray<Int>& shiftArray, const Int& startIndex)
{
	Int returnIndex = startIndex;
	Int failCounter = 0;
	while (shiftArray[returnIndex] != NOTOK && shiftArray[returnIndex] != -2)
	{
		if (shiftArray[shiftArray[returnIndex]] == returnIndex || failCounter > 200)
		{
			shiftArray[returnIndex] = NOTOK;
			returnIndex = shiftArray[returnIndex];
			break;
		}
		failCounter++;
		returnIndex = shiftArray[returnIndex];
	}

	return returnIndex;
}

Result<Bool> CellData::ReCreateCellWithOnlyUsefulPoints(BaseArray<Int>& pointUseless)
{
	iferr_scope;

	BaseArray<Int> pointTranslateMap;
	pointTranslateMap.Resize(_verticesPreIndex.GetCount() > 0 ? _verticesPreIndex.GetCount() : _vertices.GetCount()) iferr_return;

	for (Int& curTrans : pointTranslateMap)
		curTrans = NOTOK;

	BaseArray<Vector> newPoints;
	BaseArray<Int> newPointsPreIndex;
	if (_vertices.GetCount() == 0 && _verticesPreIndex.GetCount() > 0)
	{
		for (Int oldPointIndex = 0; oldPointIndex < pointUseless.GetCount(); oldPointIndex++)
		{
			if (pointUseless[oldPointIndex] == NOTOK)
			{
				pointTranslateMap[oldPointIndex] = newPointsPreIndex.GetCount();
				newPointsPreIndex.Append(_verticesPreIndex[oldPointIndex]) iferr_return;
			}
		}
	}
	else
	{
		for (Int oldPointIndex = 0; oldPointIndex < pointUseless.GetCount(); oldPointIndex++)
		{
			if (pointUseless[oldPointIndex] == NOTOK)
			{
				pointTranslateMap[oldPointIndex] = newPoints.GetCount();
				newPoints.Append(_vertices[oldPointIndex]) iferr_return;
			}
		}
	}

	BaseArray<CellEdge> newEdges;
	BaseArray<Int> newFaces;
	BaseArray<Int32> newAdjacentCell;

	Int faceCount = _faces.GetCount();

	for (Int faceIndex = 0; faceIndex < faceCount; faceIndex++)
	{
		const Int& faceStart = _faces[faceIndex];
		Int startEdgeIndex = faceStart;
		Int curEdgeIndex = startEdgeIndex;
		Int newFaceStart = newEdges.GetCount();
		Int realStartIndex = NOTOK;
		Int startIndex = NOTOK;
		Int endIndex = NOTOK;
		Int lastAddedEdge = NOTOK;
		Int firstAddedEdge = NOTOK;
		do
		{
			const CellEdge& curEdge = _edges[curEdgeIndex];

			if (pointUseless[curEdge._end] == -2)
			{
				endIndex = NOTOK;
			}
			else
			{
				endIndex = pointTranslateMap[ReturnCorrectNewVertexIndex(pointUseless, curEdge._end)];
			}

			realStartIndex = ReturnCorrectNewVertexIndex(pointUseless, curEdge._start);

			if (startIndex == NOTOK && pointTranslateMap[realStartIndex] != NOTOK)
			{
				if (startEdgeIndex == faceStart)
					startEdgeIndex = curEdgeIndex;

				startIndex = pointTranslateMap[realStartIndex];
			}

			if (startIndex != NOTOK && endIndex != NOTOK && endIndex != startIndex)
			{

				CellEdge newEdge;
				newEdge._start = startIndex;
				newEdge._end = endIndex;

				if (lastAddedEdge == NOTOK)
				{
					firstAddedEdge = newEdges.GetCount();
				}
				else
				{
					newEdge._prevEdgeOfFace = lastAddedEdge;
					newEdges[lastAddedEdge]._nextEdgeOfFace = newEdges.GetCount();
				}
				lastAddedEdge = newEdges.GetCount();

				startIndex = newEdge._end;
				newEdges.Append(newEdge) iferr_return;

			}

			curEdgeIndex = _edges[curEdgeIndex]._nextEdgeOfFace;
		} while (curEdgeIndex != startEdgeIndex);


		// the face had edges left so a new face was created
		if (newEdges.GetCount() > newFaceStart + 2)
		{
			newEdges[firstAddedEdge]._prevEdgeOfFace = lastAddedEdge;
			newEdges[lastAddedEdge]._nextEdgeOfFace = firstAddedEdge;

			newFaces.Append(newFaceStart) iferr_return;
			newAdjacentCell.Append(_adjacentCell[faceIndex]) iferr_return;
		}
		else if (newEdges.GetCount() > newFaceStart)
		{
			newEdges.Erase(newFaceStart, newEdges.GetCount() - newFaceStart) iferr_return;
		}
	}
	_adjacentCell = std::move(newAdjacentCell);
	_vertices = std::move(newPoints);
	_verticesPreIndex = std::move(newPointsPreIndex);
	_edges = std::move(newEdges);
	_faces = std::move(newFaces);

	if (!SetupReverseEdges())
		return false;

	return true;
}

Result<Bool> CellData::FixGeometry()
{
	iferr_scope;
	BaseArray<Int> pointUseless;
	pointUseless.Resize(_vertices.GetCount()) iferr_return;
	Result<Bool> res;

	for (Int32& curFaceAdj : _adjacentCell)
	{
		curFaceAdj = curFaceAdj < 4 ? NOTOK : curFaceAdj - 4;
	}

	for (Int& pointTarg : pointUseless)
		pointTarg = NOTOK;

	Bool pointsChanged = false;

#if 0 // code might be necessary at some point to have better fusing. There are still some problems that need to be addressed at some point
	MarkAllDoublePoints(pointUseless, pointsChanged);

	if (pointsChanged)
	{
		res = ReCreateCellWithOnlyUsefulPoints(pointUseless) iferr_return;
		if (!res.GetValue())
			return false;
	}
#endif


	pointUseless.Resize(_vertices.GetCount()) iferr_return;
	for (Int& pointTarg : pointUseless)
		pointTarg = NOTOK;
#if 0 // code solves some problems, but created more problems somewhere else. Taken out for the moment until a proper solution can be found.
	pointsChanged = false;
	res = MarkAllColinearPoints(pointUseless, pointsChanged) iferr_return;
	if (!res.GetValue())
		return false;

	if (pointsChanged)
	{
		res = ReCreateCellWithOnlyUsefulPoints(pointUseless) iferr_return;
		if (!res.GetValue())
			return false;
	}
#endif
	pointUseless.Resize(_vertices.GetCount()) iferr_return;
	for (Int& pointTarg : pointUseless)
		pointTarg = -3;
	pointsChanged = false;
	res = MarkAllUselessPoints(pointUseless, pointsChanged) iferr_return;
	if (!res.GetValue())
		return false;

	if (pointsChanged)
	{
		res = ReCreateCellWithOnlyUsefulPoints(pointUseless) iferr_return;
		if (!res.GetValue())
			return false;

		// in very unrobust cases, this cleanup leaves some degenerated faces
		// try again to remove points and perform cleanup when useless points were found.
		pointUseless.Resize(_vertices.GetCount()) iferr_return;
		for (Int& pointTarg : pointUseless)
			pointTarg = -3;

		pointsChanged = false;
		res = MarkAllUselessPoints(pointUseless, pointsChanged) iferr_return;
		if (!res.GetValue())
			return false;

		if (pointsChanged)
		{
			res = ReCreateCellWithOnlyUsefulPoints(pointUseless) iferr_return;
			if (!res.GetValue())
				return false;
		}
	}

	return true;
}

BaseArray<Vector>& CellData::GetVertices()
{
	return _vertices;
}
BaseArray<CellEdge>& CellData::GetEdges()
{
	return _edges;
}
BaseArray<Int>& CellData::GetFaces()
{
	return _faces;
}

BaseArray<Int32>& CellData::GetAdjacentCells()
{
	return _adjacentCell;
}

const BaseArray<Vector>& CellData::GetVertices() const
{
	return _vertices;
}
const BaseArray<CellEdge>& CellData::GetEdges() const
{
	return _edges;
}
const BaseArray<Int>& CellData::GetFaces() const
{
	return _faces;
}

const BaseArray<Int32>& CellData::GetAdjacentCells() const
{
	return _adjacentCell;
}

Bool CellData::IsComplex() const
{
	return _isComplex;
}

Range<Vector> CellData::GetBoundingBox() const
{
	Range<Vector> newRange;
	for (const Vector& curPoint : _vertices)
	{
		newRange.Add(curPoint);
	}
	return newRange;
}
} // namespace maxon
