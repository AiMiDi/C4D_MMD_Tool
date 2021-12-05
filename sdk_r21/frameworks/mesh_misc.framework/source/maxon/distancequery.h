#ifndef DISTANCEQUERY_H__
#define DISTANCEQUERY_H__

#include "maxon/range.h"
#include "maxon/vector.h"
#include "maxon/basebitset.h"
#include "maxon/matrix.h"

#define DISTANCEQUERY_SPEEDTEST 0

class PolygonObject;
class LineObject;
class SplineObject;

namespace maxon
{
enum class PRIMITIVETYPE
{
	NONE = 0,
	POINT = 1,
	EDGE = 2,
	POLYGON = 3
} MAXON_ENUM_LIST(PRIMITIVETYPE);

//----------------------------------------------------------------------------------------
/// PrimitiveInformation stores information about a primitive relative to a mesh and a position on that primitive.
//----------------------------------------------------------------------------------------
struct PrimitiveInformation
{

	//----------------------------------------------------------------------------------------
	/// Retrieve if the primitive information is on the quad or the triangle part of a quad.
	/// @return												True if the point is on the quadpart of a polygon (a-c-d triangle), false if it is on the triangle part (a-b-c triangle).
	//----------------------------------------------------------------------------------------
	Bool GetTriangleQuadInfo() const
	{
		return index < 0;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieve the original polygon index if the primitive type is PRIMITIVETYPE::POLYGON.
	/// @note this does the same as GetRealIndex() if the primitive is a polygon, but is a bit faster. Only use this if you are certain it is a polygon primitive.
	/// @return												Returns the polygon index relative to the initialized mesh.
	//----------------------------------------------------------------------------------------
	Int GetRealPolyIndex() const
	{
		return GetTriangleQuadInfo() ? -(index + 1) : index - 1;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieve the index of the primitive.
	/// @return												Returns the index relative to the initialized mesh.
	//----------------------------------------------------------------------------------------
	Int GetRealIndex() const
	{
		switch (type)
		{
			case PRIMITIVETYPE::POINT:
			{
				return index;
				break;
			}
			case PRIMITIVETYPE::EDGE:
			{
				return GetTriangleQuadInfo() ? -(index + 1) : index - 1;
				break;
			}
			case PRIMITIVETYPE::POLYGON:
			{
				return GetTriangleQuadInfo() ? -(index + 1) : index - 1;
				break;
			}
		}
		return NOTOK;
	}

	PRIMITIVETYPE type = PRIMITIVETYPE::POLYGON;
	Int index = 0;
	Int secondaryIndex = 0;
	Vector uvw;
};

//----------------------------------------------------------------------------------------
/// MeshDistanceData is a struct that stores distance information to a mesh for a point in space.
//----------------------------------------------------------------------------------------
struct MeshDistanceData
{
	Vector minPosition;
	Float minDistance = 0.0;
	PrimitiveInformation primitiveInfo;
	Float featureDistanceWeight = 0.0;
	Float edgeDistanceWeight = 1.0;
};

//----------------------------------------------------------------------------------------
/// SplineDistanceData is a struct that stores distance information to a spline or line for a point in space.
//----------------------------------------------------------------------------------------
struct SplineDistanceData
{
	Vector minPosition;
	Float minDistance = 0.0;
	Int segmentIndex = 0;
	Float segmentLength = 0.0;
};

//----------------------------------------------------------------------------------------
/// DistanceQueryInterface provides functions for calculating the distance to a mesh, a spline or a line.
//----------------------------------------------------------------------------------------
class DistanceQueryInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DistanceQueryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.geom.interface.distancequery");

public:

	//----------------------------------------------------------------------------------------
	/// Initializes the distance query with a polygon object.
	/// @param[in] mesh								Reference to the polygon object that the distance query is initialized to.
	/// @param[in] initVoxelization		Initializes a voxelization for the distance query. This Is useful for massive tests on high poly polygon objects.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(PolygonObject* mesh, Bool initVoxelization = false);

	//----------------------------------------------------------------------------------------
	/// Initializes the distance query with a spline object.
	/// @param[in] spline							Reference to the spline object that the distance query is initialized to.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(SplineObject* spline);

	//----------------------------------------------------------------------------------------
	/// Initializes the distance query with a line object.
	/// @param[in] line								Reference to the line object that the distance query is initialized to.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(LineObject* line);

	//----------------------------------------------------------------------------------------
	/// Resets the Initialized data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Retrieves the closest primitive of the initialized mesh.
	/// @param[in] pos								The point in space the closest primitive should be found for.
	/// @param[out] primInfo					The information for the primitive closest to the passed point.
	/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
	/// @return												The minimum distance to the closest primitive.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the closest primitive of the initialized mesh.
	/// @param[in] pos								The point in space the distance information should be calculated for.
	/// @param[out] distInfo					The calculated distance information for passed point.
	/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
	/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
	
	//----------------------------------------------------------------------------------------
	/// Retrieves the closest primitive of the initialized mesh. Same as GetDistanceToMesh
	/// This will filter out all polygons that have primitive normals with a higher angle from the passed direction.
	/// @param[in] pos								The point in space the distance information should be calculated for.
	/// @param[in] direction					The direction for which the found polygons are not allowed to deviate more than the passed angle.
	/// @param[in] angle							The angle for which the found polygons normals are not allowed to deviate relative to the passed direction.
	/// @param[out] distInfo					The calculated distance information for the passed point.
	/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
	/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
	
	//----------------------------------------------------------------------------------------
	/// Retrieves the closest primitive of the initialized Spline or Line.
	/// @param[in] pos								The point in space the distance information should be calculated for.
	/// @param[out] distInfo					The calculated distance information for passed point.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves if the class was initialized with a polygon object, a spline or a line.
	/// @return												True if the class was initialized, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsInitialized() const;

	//----------------------------------------------------------------------------------------
	/// Set the thread count for the calculations.
	/// @param[in] threads						The amount of threads to be used.		
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetThreading(Int32 threads);
};


#include "distancequery1.hxx"

MAXON_DECLARATION(Class<DistanceQueryRef>, DistanceCalculator, "net.maxon.geom.interface.distancequery.distancecalculator");

#include "distancequery2.hxx"

}
#endif // DISTANCEQUERY_H__
