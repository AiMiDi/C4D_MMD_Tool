#ifndef TETRAHEDRON_H__
#define TETRAHEDRON_H__

#include "maxon/vector.h"
#include "maxon/vector4d.h"

namespace maxon
{

//  class for a Tetrahedron consisting of 4 Triangles and the Adjacent Tetrahedron
//
// 		  0            Triangles are 0, 1, 2
// 	   /*\                         0, 3, 1
// 	  / | \                        0, 2, 3
// 	 / 3*  \                       1, 3, 2
// 1*-------* 2

struct Tetrahedron
{
	Tetrahedron(){};
	Tetrahedron(const Tetrahedron&) = default;
	Tetrahedron(Int32 point1, Int32 point2, Int32 point3, Int32 point4, Int32 neighbor1, Int32 neighbor2, Int32 neighbor3, Int32 neighbor4);

	~Tetrahedron(){};
	IntVector4d32 points;
	IntVector4d32 neighbors;

	//----------------------------------------------------------------------------------------
	/// Gets the internal tetrahedron point indices between 0 and 3 of the two input points.
	/// This is meant to be a helper to get the indices of an edge.
	/// If the index cannot be found it will not be written.
	/// @param[in] startPoint					First point index to get the index of.
	/// @param[in] endPoint						Second point index to get the index of.
	/// @param[out] startPointIndex		Tetrahedron index of the first point.
	/// @param[out] endPointIndex			Tetrahedron index of the second point.
	//----------------------------------------------------------------------------------------
	void	GetPointIndexOfTwoPoints(Int32 startPoint, Int32 endPoint, Int32& startPointIndex, Int32& endPointIndex) const;

	//----------------------------------------------------------------------------------------
	/// Gets the point indices between 0 and 3 of one input point.
	/// If the index cannot be found it will not be written.
	/// @param[in] pointIn						Point index to get the index of.
	/// @return												The points Tetrahedron index.
	//----------------------------------------------------------------------------------------
	Int32 GetPointIndexOfPoint(Int32 pointIn) const;

	//----------------------------------------------------------------------------------------
	/// Gets the internal tetrahedron face index of the face with the 3 indices.
	/// only correct if the three points are part of this tetrahedron.
	/// @param[in] point1							Point index one of the triangle.
	/// @param[in] point2							Point index two of the triangle.
	/// @param[in] point3							Point index three of the triangle.
	/// @return												The tetrahedron face index of the the point indices
	//----------------------------------------------------------------------------------------
	Int32 GetFaceWithPoints(Int32 point1, Int32 point2, Int32 point3) const;

	//----------------------------------------------------------------------------------------
	/// Gets the point in this tetrahedron that is opposite of the face with the input neighbor index.
	/// @param[in] neighbourIndex			The neighbor index of which the point should be opposite of.
	/// @return												The point index of the point opposite of the neighbor face.
	//----------------------------------------------------------------------------------------
	Int32 GetPointOppositeNeighbour(Int32 neighbourIndex) const;

	//----------------------------------------------------------------------------------------
	/// Gets the three point indices of a face.
	/// @param[in] face								The internal tetrahedron face index.
	/// @param[out] pointList					A list of the point indices that are building the face.
	//----------------------------------------------------------------------------------------
	void	GetFacePoints(Int32 face, IntVector32& pointList) const;

	//----------------------------------------------------------------------------------------
	/// Gets the three point indices of a face.
	/// @param[in] face								The internal tetrahedron face index.
	/// @param[out] point1						Point index one of the face.
	/// @param[out] point2						Point index two of the face.
	/// @param[out] point3						Point index three of the face.
	//----------------------------------------------------------------------------------------
	void	GetFacePoints(Int32 face, Int32& point1, Int32& point2, Int32& point3) const;


	//----------------------------------------------------------------------------------------
	/// Gets the face index of a face that shares the two edge points but is not the passed face index.
	/// Helper method to traverse to the neighbor face over an edge.
	/// @param[in] notFace						The excluded face index that shares the edge.
	/// @param[in] edgePoint1					Point index one of the edge between two faces.
	/// @param[in] edgePoint2					Point index two of the edge between two faces.
	/// @return												The internal face index of the neighbor face.
	//----------------------------------------------------------------------------------------
	Int32 GetFaceIndexSharingTwoPointsButNotInputFace(Int32 notFace, Int32 edgePoint1, Int32 edgePoint2) const;


	//----------------------------------------------------------------------------------------
	/// Gets the point index of a point opposite of the input face index.
	/// @param[in] faceIndex					The face index the returned point should be opposite of.
	/// @return												The point index opposite of the face index.
	//----------------------------------------------------------------------------------------
	Int32 GetPointOppositeFace(Int32 faceIndex) const;


	//----------------------------------------------------------------------------------------
	/// Gets the internal tetrahedron face index of the face with the input neighbor index
	/// @param[in] neighbor						The neighbor index.
	/// @return												The face index of the face with the neighbor index as neighbor.
	//----------------------------------------------------------------------------------------
	Int32 GetFaceWithNeighbor(Int32 neighbor) const;


	//----------------------------------------------------------------------------------------
	/// Gets the face index of the face opposite the input point.
	/// @param[in] pointIndex					The input point.
	/// @return												The face index of the face opposite the input point.
	//----------------------------------------------------------------------------------------
	Int32 GetFaceOppositePoint(Int32 pointIndex) const;


	//----------------------------------------------------------------------------------------
	/// Gets a list of points that build up the face with the input neighbor.
	/// @param[in] neighbor						The neighbor index of the face that the points should be returned.
	/// @param[in] pointList					The list of points building up the face.
	//----------------------------------------------------------------------------------------
	void	GetFacePointsWithNeighbor(Int32 neighbor, IntVector32& pointList) const;


	//----------------------------------------------------------------------------------------
	/// Changes the point index for one point.
	/// @param[in] oldPoint						The old index of the point.
	/// @param[in] newPoint						The new index of the point.
	/// @return												True if something was changed. False if oldPoint was not in this tetrahedron.
	//----------------------------------------------------------------------------------------
	Bool	ChangePointToOtherPoint(Int32 oldPoint, Int32 newPoint);


	//----------------------------------------------------------------------------------------
	/// Calculates the barycentric coordinates for a point in relation to this tetrahedron.
	/// @param[in] pointList					The list of point positions the tetrahedron references with its point indices.
	/// @param[in] testPoint					The point the barycentric coordinates should be calculated for.
	/// @return												The barycentric coordinates of testPoint in relation to this tetrahedron.
	//----------------------------------------------------------------------------------------
	Vector4d CalcBarycentricOfPoint(const BaseArray<Vector>& pointList, const Vector& testPoint) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the barycentric coordinates for a point in relation to this tetrahedron.
	/// @param[in] pointList					The list of point positions the tetrahedron references with its point indices.
	/// @param[in] testPoint					The point the barycentric coordinates should be calculated for.
	/// @return												The barycentric coordinates of testPoint in relation to this tetrahedron.
	//----------------------------------------------------------------------------------------
	Vector4d CalcBarycentricOfPoint2(const BaseArray<Vector>& pointList, const Vector& testPoint) const;

};

} // namespace maxon

#endif // TETRAHEDRON_H__
