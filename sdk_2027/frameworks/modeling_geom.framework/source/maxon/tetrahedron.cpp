#include "tetrahedron.h"

namespace maxon
{

Tetrahedron::Tetrahedron(Int32 point1, Int32 point2, Int32 point3, Int32 point4, Int32 neighbor1, Int32 neighbor2, Int32 neighbor3, Int32 neighbor4)
	: points(IntVector4d32(point1, point2, point3, point4)), neighbors(IntVector4d32(neighbor1, neighbor2, neighbor3, neighbor4))
{}

void Tetrahedron::GetFacePoints(Int32 face, IntVector32& pointList) const
{
	switch (face)
	{
		case 0:
		{
			pointList.x = points[0];
			pointList.y = points[1];
			pointList.z = points[2];
			break;
		}
		case 1:
		{
			pointList.x = points[0];
			pointList.y = points[3];
			pointList.z = points[1];
			break;
		}
		case 2:
		{
			pointList.x = points[0];
			pointList.y = points[2];
			pointList.z = points[3];
			break;
		}
		case 3:
		{
			pointList.x = points[1];
			pointList.y = points[3];
			pointList.z = points[2];
			break;
		}
		}
}

Bool Tetrahedron::ChangePointToOtherPoint(Int32 oldPoint, Int32 newPoint)
{
	for (Int32 pointIndex = 0; pointIndex < 4; pointIndex++)
	{
		if (points[pointIndex] == oldPoint)
		{
			points[pointIndex] = newPoint;
			return true;
		}
	}
	return false;
}

// Returns Face on the inner right of the edge in edgedirection
void Tetrahedron::GetPointIndexOfTwoPoints(Int32 startPoint, Int32 endPoint, Int32& startPointIndex, Int32& endPointIndex) const
{

	for (Int32 pointIndex = 0; pointIndex < 4; pointIndex++)
	{
		if (points[pointIndex] == startPoint)
		{
			startPointIndex = pointIndex;
		}
		else if (points[pointIndex] == endPoint)
		{
			endPointIndex = pointIndex;
		}
	}
}

Int32 Tetrahedron::GetPointIndexOfPoint(Int32 pointIn) const
{
	for (Int32 pointIndex = 0; pointIndex < 4; pointIndex++)
	{
		if (points[pointIndex] == pointIn)
		{
			return pointIndex;
		}
	}
	return NOTOK;
}

void Tetrahedron::GetFacePointsWithNeighbor(Int32 neighbor, IntVector32& pointList) const
{
	Int32 faceIndexFound = -1;
	for (Int32 faceIndex = 0; faceIndex < 4; faceIndex++)
	{
		if (neighbors[faceIndex] == neighbor)
		{
			faceIndexFound = faceIndex;
		}
	}

	switch (faceIndexFound)
	{
		default:
			break;
		case -1:
		{
			pointList.x = -1;
			pointList.y = -1;
			pointList.z = -1;
			break;
		}
		case 0:
		{
			pointList.x = points[0];
			pointList.y = points[1];
			pointList.z = points[2];
			break;
		}
		case 1:
		{
			pointList.x = points[0];
			pointList.y = points[3];
			pointList.z = points[1];
			break;
		}
		case 2:
		{
			pointList.x = points[0];
			pointList.y = points[2];
			pointList.z = points[3];
			break;
		}
		case 3:
		{
			pointList.x = points[1];
			pointList.y = points[3];
			pointList.z = points[2];
			break;
		}
	}
}
void Tetrahedron::GetFacePoints(Int32 face, Int32& point1, Int32& point2, Int32& point3) const
{
	switch (face)
	{
		case 0:
		{
			point1 = points[0];
			point2 = points[1];
			point3 = points[2];
			break;
		}
		case 1:
		{
			point1 = points[0];
			point2 = points[3];
			point3 = points[1];
			break;
		}
		case 2:
		{
			point1 = points[0];
			point2 = points[2];
			point3 = points[3];
			break;
		}
		case 3:
		{
			point1 = points[1];
			point2 = points[3];
			point3 = points[2];
			break;
		}
	}
}

Int32 Tetrahedron::GetFaceWithPoints(Int32 point1, Int32 point2, Int32 point3) const
{
	Int32 faceIndex = 3;
	if (points[0] == point1 || points[0] == point2 || points[0] == point3)
	{
		faceIndex--;
		if (points[1] == point1 || points[1] == point2 || points[1] == point3)
		{
			faceIndex--;
			if (points[2] == point1 || points[2] == point2 || points[2] == point3)
			{
				faceIndex--;
			}
		}
	}

	return faceIndex;
}
Int32 Tetrahedron::GetFaceWithNeighbor(Int32 neighborIn) const
{
	for (Int32 faceIndex = 0; faceIndex < 4; faceIndex++)
	{
		if (neighbors[faceIndex] == neighborIn)
			return faceIndex;
	}

	return -1;
}

Int32 Tetrahedron::GetFaceOppositePoint(Int32 pointIndex) const
{
	if (points[0] == pointIndex)
		return 3;
	if (points[1] == pointIndex)
		return 2;
	if (points[2] == pointIndex)
		return 1;
	if (points[3] == pointIndex)
		return 0;

	return -1;
}
Int32 Tetrahedron::GetPointOppositeFace(Int32 faceIndex) const
{
	if (faceIndex == 0)
		return points[3];
	if (faceIndex == 1)
		return points[2];
	if (faceIndex == 2)
		return points[1];
	if (faceIndex == 3)
		return points[0];

	return -1;
}

Int32 Tetrahedron::GetPointOppositeNeighbour(Int32 neighbourIndex) const
{
	if (neighbors[0] == neighbourIndex)
		return points[3];
	if (neighbors[1] == neighbourIndex)
		return points[2];
	if (neighbors[2] == neighbourIndex)
		return points[1];
	if (neighbors[3] == neighbourIndex)
		return points[0];

	return -1;
}

Int32 Tetrahedron::GetFaceIndexSharingTwoPointsButNotInputFace(Int32 notFace, Int32 edgePoint1, Int32 edgePoint2) const
{
	Int32 count = 0;

	for (Int32 faceIndex = 0; faceIndex < 4; faceIndex++)
	{
		if (faceIndex != notFace)
		{
			switch (faceIndex)
			{
				case 0:
				{
					if (points[0] == edgePoint1 || points[0] == edgePoint2)
						count++;
					if (points[1] == edgePoint1 || points[1] == edgePoint2)
						count++;
					if (points[2] == edgePoint1 || points[2] == edgePoint2)
						count++;
					break;
				}
				case 1:
				{
					if (points[0] == edgePoint1 || points[0] == edgePoint2)
						count++;
					if (points[3] == edgePoint1 || points[3] == edgePoint2)
						count++;
					if (points[1] == edgePoint1 || points[1] == edgePoint2)
						count++;
					break;
				}
				case 2:
				{
					if (points[0] == edgePoint1 || points[0] == edgePoint2)
						count++;
					if (points[2] == edgePoint1 || points[2] == edgePoint2)
						count++;
					if (points[3] == edgePoint1 || points[3] == edgePoint2)
						count++;
					break;
				}
				case 3:
				{
					if (points[1] == edgePoint1 || points[1] == edgePoint2)
						count++;
					if (points[2] == edgePoint1 || points[2] == edgePoint2)
						count++;
					if (points[3] == edgePoint1 || points[3] == edgePoint2)
						count++;
					break;
				}
			}
		}

		if (count == 2)
			return faceIndex;

		count = 0;
	}

	return -1;
}

inline Float SignedDistanceToPlane(const Vector& point1, const Vector& point2, const Vector& point3, const Vector& point)
{
	Vector e1 = point2 - point1;
	Vector e2 = point3 - point1;
	Vector normal = Cross(e1, e2);
	normal.Normalize();
	return Dot(point - point1, normal);
}

inline Float SignedDistanceToPlaneRatio(const Vector& point1, const Vector& point2, const Vector& point3, const Vector& testPoint1, const Vector& testPoint2)
{
	Vector e1 = point2 - point1;
	Vector e2 = point3 - point1;
	Vector normal = Cross(e1, e2);

	return Dot(testPoint1 - point1, normal) / Dot(testPoint2 - point1, normal);
}

Vector4d Tetrahedron::CalcBarycentricOfPoint(const BaseArray<Vector>& pointList, const Vector& testPoint) const
{
	maxon::Vec4<Float> result;

	const Vector& point1 = pointList[points[0]];
	const Vector& point2 = pointList[points[1]];
	const Vector& point3 = pointList[points[2]];
	const Vector& point4 = pointList[points[3]];

	result.x = SignedDistanceToPlaneRatio(point2, point3, point4, testPoint, point1);
	result.y = SignedDistanceToPlaneRatio(point1, point4, point3, testPoint, point2);
	result.z = SignedDistanceToPlaneRatio(point1, point2, point4, testPoint, point3);
	result.w = SignedDistanceToPlaneRatio(point1, point3, point2, testPoint, point4);

	return result;
}

inline Float BaryOnePoint(const Vector& point1, const Vector& point2, const Vector& point3, const Vector& testPoint, const Float sixTetVolume)
{
	Vector e1 = point2 - point1;
	Vector e2 = point3 - point1;
	Vector normal = Cross(e1, e2);

	return Dot(testPoint - point1, normal) * sixTetVolume;
}

Vector4d Tetrahedron::CalcBarycentricOfPoint2(const BaseArray<Vector>& pointList, const Vector& testPoint) const
{

	const Vector& point1 = pointList[points[0]];
	const Vector& point2 = pointList[points[1]];
	const Vector& point3 = pointList[points[2]];
	const Vector& point4 = pointList[points[3]];

	maxon::Vec4<Float> result;
	Vector edge1 = point2 - point1;
	Vector edge2 = point3 - point1;
	Vector edge3 = point4 - point1;
	Float sixTetVolume = 1.0 / Dot(edge1, Cross(edge2, edge3));
	result.x = BaryOnePoint(point2, point4, point3, testPoint, sixTetVolume);
	result.y = BaryOnePoint(point1, point3, point4, testPoint, sixTetVolume);
	result.z = BaryOnePoint(point1, point4, point2, testPoint, sixTetVolume);
	result.w = 1.0 - result.x - result.y - result.z;

	return result;
}

} // namespace maxon
