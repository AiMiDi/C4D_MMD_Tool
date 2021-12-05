#ifndef CONVEXHULL_H__
#define CONVEXHULL_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/vector.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// ConvEdge struct respresents an edge in the convex hull data. It saves indices to the start and endpoint of the edge
/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
//----------------------------------------------------------------------------------------
struct ConvEdge
{
	ConvEdge() = default;
	ConvEdge(Int start, Int end, Int nextEdgeOfFace, Int nextEdgeOfVert, Int reverseEdge) :
		_start(start), _end(end), _nextEdgeOfFace(nextEdgeOfFace), _nextEdgeOfVert(nextEdgeOfVert), _reverseEdge(reverseEdge){}
	Int _start = NOTOK;
	Int _end = NOTOK;
	Int _nextEdgeOfFace = NOTOK;
	Int _nextEdgeOfVert = NOTOK;
	Int _reverseEdge = NOTOK;
};

//----------------------------------------------------------------------------------------
/// ConvexHullData struct is a datacontainer that represents a convex hull
//----------------------------------------------------------------------------------------
struct ConvexHullData
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ConvexHullData);
	ConvexHullData(){}
	ConvexHullData(ConvexHullData&& src) = default;
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ConvexHullData);
	BaseArray<Vector> vertices;
	BaseArray<ConvEdge> edges;
	BaseArray<Int> faces;
};

//----------------------------------------------------------------------------------------
/// ConvexHullInterface provides functions for creating a convex hull of a set of points
//----------------------------------------------------------------------------------------
class ConvexHullInterface
{

	MAXON_INTERFACE_NONVIRTUAL(ConvexHullInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.convexhull");
public:

	static MAXON_METHOD ConvexHullInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Creates a Convex hull out of the input points.
	/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
	/// @param[in] shrink							Value the resulting convex hull is shrunk by.
	/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
	/// @param[out] resultVertices		The array is filled with the vertices of the calculated convex hull.
	/// @param[out] resultEdges				The array is filled with the edges of the calculated convex hull.
	/// @param[out] resultFaces				The array is filled with the face of the calculated convex hull.
	/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces);

	//----------------------------------------------------------------------------------------
	/// Creates a Convex hull out of the input points.
	/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
	/// @param[in] shrink							Value the resulting convex hull is shrunk by.
	/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
	/// @param[out] hull							The struct is filled with all data that makes up the convex hull (vertices, edges, faces).
	/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull);
};

#include "convexhull1.hxx"
#include "convexhull2.hxx"
} // namespace maxon
#endif // CONVEXHULL_H__

