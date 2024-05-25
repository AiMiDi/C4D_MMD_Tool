#include "maxon/matrix.h"
#include "maxon/branch.h" // remove once feature switch is gone. 

#include "tangentspacenormalhelper.h"

namespace maxon
{

namespace TangentSpaceNormalHelper
{

	Vector ComputeNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint)
	{
		return !(Cross(nextPoint - currPoint, prevPoint - currPoint));
	}

	Vector ComputeTangent(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint)
	{
		return !((prevPoint + nextPoint) - 2.0_f * currPoint);
	}

	Vector ConvertToTangentSpaceNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint, const Vector& objectSpaceNormal)
	{
		// compute the tangent, normal and bitangent vectors, that are required to construct a local space matrix around this polygon corner
		// that local space matrix is then used to convert the given custom normal in object space, to it's representation in tangent space (space around the corner of a polygon)
		Vector normal = ComputeNormal(prevPoint, currPoint, nextPoint);
		Vector tangent = ComputeTangent(prevPoint, currPoint, nextPoint);
		Vector biTangent = ComputeBiTangent(normal, tangent);

		// Create the appropriate matrix.
		Matrix trn;
		trn.sqmat.v1 = tangent;
		trn.sqmat.v2 = normal;
		trn.sqmat.v3 = biTangent;

		// Invert the matrix, as we are transforming from object space to tangent space
		trn = ~trn;

		return trn.sqmat * objectSpaceNormal;
	}

	Vector ConvertToObjectSpaceNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint, const Vector& tangentSpaceNormal)
	{
		// compute the tangent, normal and bitangent vectors, that are required to construct a local space matrix around this polygon corner
		// that local space matrix is then used to convert the given custom normal in object space, to it's representation in tangent space (space around the corner of a polygon)
		Vector normal = ComputeNormal(prevPoint, currPoint, nextPoint);
		Vector tangent = ComputeTangent(prevPoint, currPoint, nextPoint);
		Vector biTangent = ComputeBiTangent(normal, tangent);

		// Create the appropriate matrix.
		Matrix trn;
		trn.sqmat.v1 = tangent;
		trn.sqmat.v2 = normal;
		trn.sqmat.v3 = biTangent;

		return trn.sqmat * tangentSpaceNormal;
	}

	Vector ComputeNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index)
	{
		Int32 prevIndex = index > 0 ? index - 1 : (Int32)polygonPoints.GetCount() - 1;
		Int32 nextIndex = index < polygonPoints.GetCount() - 1 ? index + 1 : 0;

		return !(Cross(points[polygonPoints[nextIndex]] - points[polygonPoints[index]], points[polygonPoints[prevIndex]] - points[polygonPoints[index]]));
	}

	Vector ComputeTangent(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index)
	{
		Int32 prevIndex = index > 0 ? index - 1 : (Int32)polygonPoints.GetCount() - 1;
		Int32 nextIndex = index < polygonPoints.GetCount() - 1 ? index + 1 : 0;

		return !((points[polygonPoints[prevIndex]] + points[polygonPoints[nextIndex]]) - 2.0_f * points[polygonPoints[index]]);
	}

	Vector ComputeBiTangent(const Vector& normal, const Vector& tangent)
	{
		return !(Cross(normal, tangent));
	}

	Vector ConvertToTangentSpaceNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index, const Vector& objectSpaceNormal)
	{
		// compute the tangent, normal and bitangent vectors, that are required to construct a local space matrix around this polygon corner
		// that local space matrix is then used to convert the given custom normal in object space, to it's representation in tangent space (space around the corner of a polygon)
		Vector normal = ComputeNormal(points, polygonPoints, index);
		Vector tangent = ComputeTangent(points, polygonPoints, index);
		Vector biTangent = ComputeBiTangent(normal, tangent);

		// Create the appropriate matrix.
		Matrix trn;
		trn.sqmat.v1 = tangent;
		trn.sqmat.v2 = normal;
		trn.sqmat.v3 = biTangent;

		// Invert the matrix, as we are transforming from object space to tangent space
		trn = ~trn;

		return trn.sqmat * objectSpaceNormal;
	}

	Vector ConvertToObjectSpaceNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index, const Vector& tangentSpaceNormal)
	{
		// compute the tangent, normal and bitangent vectors, that are required to construct a local space matrix around this polygon corner
		// that local space matrix is then used to convert the given custom normal in object space, to it's representation in tangent space (space around the corner of a polygon)
		Vector normal = ComputeNormal(points, polygonPoints, index);
		Vector tangent = ComputeTangent(points, polygonPoints, index);
		Vector biTangent = ComputeBiTangent(normal, tangent);

		// Create the appropriate matrix.
		Matrix trn;
		trn.sqmat.v1 = tangent;
		trn.sqmat.v2 = normal;
		trn.sqmat.v3 = biTangent;

		return trn.sqmat * tangentSpaceNormal;
	}
	
	Result<void> NormalVertexCycle::CopyFrom(const NormalVertexCycle& src)
	{
		iferr_scope;

		_polygons.CopyFrom(src._polygons) iferr_return;
		_vertexIdxInPolygon.CopyFrom(src._vertexIdxInPolygon) iferr_return;

		return OK;
	}

	Result<void> NormalVertexCycles::CopyFrom(const NormalVertexCycles& src)
	{
		iferr_scope;

		_cycles.CopyFrom(src._cycles) iferr_return;
		_vertex = src._vertex;

		return OK;
	}

	Result<void> NormalVertexCycles::Init(Int32 vertex, const Block<const Int32>& pointPolys, const Block<const Vector>& normals, const Block<const Int32>& vertexIdxInPolygon)
	{
		iferr_scope;

		if (pointPolys.GetCount() == 0 || vertexIdxInPolygon.GetCount() != pointPolys.GetCount())
		{
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		}

		// initialize the vertex cycles. 
		// if the two polygons have the normal aligned, they are added to the same cycle. 
		// after this is executed, the cycles will have still the normals in object space. 
		for (Int32 polyIdx = 0; polyIdx < pointPolys.GetCount(); ++polyIdx)
		{
			Bool found = false;
			for (Int32 cycleIdx = 0; cycleIdx < _cycles.GetCount(); ++cycleIdx)
			{
				const Vector& existingCycleNormal = normals[4 * _cycles[cycleIdx]._polygons[0] + _cycles[cycleIdx]._vertexIdxInPolygon[0]];
				const Vector& currentNormal = normals[4 * pointPolys[polyIdx] + vertexIdxInPolygon[polyIdx]];
				// check if the cycle normal is aligned with the current polygon normal...
				if (Dot(existingCycleNormal, currentNormal) > 0.99_f)
				{
					// normal is aligned. append polygon to cycle and break the loop.
					_cycles[cycleIdx]._polygons.Append(pointPolys[polyIdx]) iferr_return;
					_cycles[cycleIdx]._vertexIdxInPolygon.Append(vertexIdxInPolygon[polyIdx]) iferr_return;
					found = true;
					break;
				}
			}

			if (!found)
			{
				// we failed to find a vertex cycle that has the same normal as the current polygon
				// therefore, we append a new vertex cycle and append the polygon to that cycle. 
				// this will happen at least once, for the first polygon. 
				NormalVertexCycle& cycle = _cycles.Append() iferr_return;
				cycle._polygons.Append(pointPolys[polyIdx]) iferr_return;
				cycle._vertexIdxInPolygon.Append(vertexIdxInPolygon[polyIdx]) iferr_return;
			}
		}

		_vertex = vertex;

		return OK;
	}

  Result<void> NormalVertexCycles::ConvertDataToTangentSpace(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const
	{
		iferr_scope;

		for (const NormalVertexCycle& cycle : _cycles)
		{
			for (Int32 idx = 0; idx < cycle._polygons.GetCount(); ++idx)
			{
				const Vector& normal = inNormals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]];
				Bool isTriangle = polygons[cycle._polygons[idx]].c == polygons[cycle._polygons[idx]].d;
        outNormals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]] = ConvertToTangentSpaceNormal(points, Block<const Int32>(&(polygons[cycle._polygons[idx]].a), isTriangle ? 3 : 4), cycle._vertexIdxInPolygon[idx], normal);
			}
		}

		return OK;
	}

	Result<void> NormalVertexCycles::ConvertDataToObjectSpace(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const
	{
		iferr_scope;

		for (const NormalVertexCycle& cycle : _cycles)
		{
			for (Int32 idx = 0; idx < cycle._polygons.GetCount(); ++idx)
			{
				const Vector& normal = inNormals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]];
				Bool isTriangle = polygons[cycle._polygons[idx]].c == polygons[cycle._polygons[idx]].d;
        outNormals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]] = ConvertToObjectSpaceNormal(points, Block<const Int32>(&(polygons[cycle._polygons[idx]].a), isTriangle ? 3 : 4), cycle._vertexIdxInPolygon[idx], normal);
			}
		}

		return OK;
	}

	Result<void> NormalVertexCycles::AverageOutVertexCycleNormals(Block<Vector>& normals) const
	{
		for (const NormalVertexCycle& cycle : _cycles)
		{
			for (Int32 idx = 1; idx < cycle._polygons.GetCount(); ++idx)
			{
				normals[4 * cycle._polygons[0] + cycle._vertexIdxInPolygon[0]] += normals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]];
			}
			normals[4 * cycle._polygons[0] + cycle._vertexIdxInPolygon[0]].Normalize();
			for (Int32 idx = 1; idx < cycle._polygons.GetCount(); ++idx)
			{
				normals[4 * cycle._polygons[idx] + cycle._vertexIdxInPolygon[idx]] = normals[4 * cycle._polygons[0] + cycle._vertexIdxInPolygon[0]];
			}
		}

		return OK;
	}

	Result<void> TangentSpaceNormalData::CopyFrom(const TangentSpaceNormalData& src)
	{
		iferr_scope;

		_normalVertexCycles.CopyFrom(src._normalVertexCycles) iferr_return;
		_pointCount = src._pointCount;
		_polygonCount = src._polygonCount;

		return OK;
	}

	Result<void> TangentSpaceNormalData::ComputeUpdatedNormals(const Block<const Vector>& updatedPointPoisitions, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const
	{
		iferr_scope;

		if (outNormals.GetCount() != 4 * polygons.GetCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		ParallelFor::Dynamic<>(0, _normalVertexCycles.GetCount(),
			[&normalVertexCycles = _normalVertexCycles, &outNormals, &updatedPointPoisitions, &polygons, &inNormals](Int index) -> Result<void>
			{
				iferr_scope;

				const NormalVertexCycles& cycles = normalVertexCycles[index];
				cycles.ConvertDataToObjectSpace(updatedPointPoisitions, polygons, inNormals, outNormals) iferr_return;
				cycles.AverageOutVertexCycleNormals(outNormals) iferr_return;

				return OK;
			}, ParallelFor::Granularity(128, _normalVertexCycles.GetCount() > 1023)) iferr_return;

		return OK;
	}

	void TangentSpaceNormalData::Flush()
	{
		_normalVertexCycles.Flush();
		return;
	}

	Bool TangentSpaceNormalData::IsInitialized() const
	{
		return _pointCount != NOTOK && _polygonCount != NOTOK && _normalVertexCycles.GetCount() > 0;
	}

	Bool TangentSpaceNormalData::IsTopologyValid(Int32 pointCount, Int32 polygonCount) const
	{
		return _pointCount == pointCount && polygonCount == _polygonCount;
	}

} // namespace TangentSpaceNormalHelper

} // namespace maxon
