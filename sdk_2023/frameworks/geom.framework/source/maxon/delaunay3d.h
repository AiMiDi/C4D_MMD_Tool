#ifndef DELAUNAY3D_H__
#define DELAUNAY3D_H__

#include "maxon/interface.h"
#include "maxon/vector.h"
#include "maxon/matrix.h"
#include "maxon/matrix4d.h"
#include "maxon/range.h"
#include "maxon/tetrahedron.h"

namespace maxon
{

class Delaunay3DInterface
{
	MAXON_INTERFACE_NONVIRTUAL(Delaunay3DInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.delaunay3d");

public:

	static MAXON_METHOD Delaunay3DInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Copies the content of another Delaunay3D Object into this one (copy and assign is not allowed)
	/// @param[in] src								The Delaunay3D Object to copy from.
	/// @param[in] resizeFlags				Resize flag for internal list copies. recommended is default.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE);

	//----------------------------------------------------------------------------------------
	/// The Initialization function for Delaunay3D.
	/// Needs to be called before points can be added into the tetrahedralization.
	/// @param[in] workSpace					The space in which the input points will be in. Should not be too big for numeric reasons.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Range<Vector>& workSpace);

	//----------------------------------------------------------------------------------------
	/// Updates the Tetrahedralization if new points have been added.
	/// This triggers the final calculation or update of the tetrahedralization.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalculateDelaunayTetrahedralization();

	//----------------------------------------------------------------------------------------
	/// Checks if Init() has been called.
	/// THREADSAFE.
	/// @return												true if Init() has beed called, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsInitialized();

	//----------------------------------------------------------------------------------------
	/// Adds a BaseArray of points into the tetrahedralization.
	/// CalculateDelaunayTetrahedralization() needs to be called
	/// afterwards to calculate the insertion.
	/// @param[in] newPointsIn				The list of points, that will be added into the tetrahedralization.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn);

	//----------------------------------------------------------------------------------------
	/// Adds a single point into the tetrahedralization.
	/// CalculateDelaunayTetrahedralization() needs to be called afterwards to calculate the insertion.
	/// @param[in] newPointIn					The point that will be added into the tetrahedralization.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddPointIntoTetrahedralization(const Vector& newPointIn);

	//----------------------------------------------------------------------------------------
	/// Gets a constant reference to the tetrahedrons list.
	/// THREADSAFE.
	/// @param[out] arrayCount				Will be filled with the amount of tetrahedrons in the array reference.
	/// @param[out] pointCount				Will be filled with the amount of points inserted into the teterahedralization.
	/// @return												A constant reference to a BaseArray<Tetrahedron> with the tetrahedrons, that make up the tetrahedralization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Tetrahedron>& GetTetrahedrons(Int& arrayCount, Int& pointCount) const;

	//----------------------------------------------------------------------------------------
	/// Gets a constant reference to the tetrahedrons list.
	/// THREADSAFE.
	/// @return												A constant reference to a BaseArray<Tetrahedron> with the tetrahedrons, that make up the tetrahedralization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Tetrahedron>& GetTetrahedrons() const;

	//----------------------------------------------------------------------------------------
	/// Gets a constant reference to the connection of one of the points to an arbitrary adjacent tetrahedron.
	/// This can be used to greatly increase the calculation speed of a Voronoi conversion.
	/// THREADSAFE.
	/// @return												A constant reference to a BaseArray<Int32> with the tetrahedron index to the point at the same array position as added.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Int32>& GetPointsToTetConnections() const;

	//----------------------------------------------------------------------------------------
	/// Gets a constant reference to the list of points, that are set for the Delaunay tetrahedralization.
	/// THREADSAFE.
	/// @return												A constant reference to a BaseArray<Vector> with the points of the tetrahedralization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Vector>& GetPoints() const;

	//----------------------------------------------------------------------------------------
	/// Gets a reference to the list of points, that are set for the Delaunay tetrahedralization (writable).
	/// THREADSAFE.
	/// @return												A reference to a BaseArray<Vector> with the points of the tetrahedralization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<BaseArray<Vector>> GetPointsWrite();

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the tetrahedrons making up the tetrahedralization.
	/// THREADSAFE.
	/// @param[out] arrayIn						Will be filled with the tetrahedron information.
	/// @param[out] tetCount					Will be filled with the amount of tetrahedrons.
	/// @param[out] pointCount				Will be filled with the amount of points.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetTetrahedronCopy(BaseArray<Tetrahedron>& arrayIn, Int& tetCount, Int& pointCount) const;

	//----------------------------------------------------------------------------------------
	/// Gets the current amount of tetrahedrons.
	/// THREADSAFE.
	/// @return												Amount of tetrahedrons.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetTetrahedronCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets the current amount of points
	/// THREADSAFE.
	/// @return												Amount of points that were added.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetPointCount() const;

	//----------------------------------------------------------------------------------------
	/// Resets the Delaunay object for a reuse with the same initialization.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Reset();

	//----------------------------------------------------------------------------------------
	/// Static helper method to calculate the precise orientation of a point, in reference to a plane.
	/// the plane is spanned by planePointA, planePointB and planePointC.
	/// the tested point is testPoint.
	/// THREADSAFE.
	/// @param[in] planePointA				Point one of plane.
	/// @param[in] planePointB				Point two of plane.
	/// @param[in] planePointC				Point three of plane.
	/// @param[in] testPoint					Point to test for.
	/// @return												The determinant of the calculation. The sign of the result gives information about the side the point was is on.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint);

	//----------------------------------------------------------------------------------------
	/// Resets all data structures for a new calculation. Needs to be reinitialized before its reused.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	//----------------------------------------------------------------------------------------
	/// Returns the index of the tetrahedron the input point is in.
	/// THREADSAFE.
	/// @param[in] point							The point position to search the tetrahedron index for.
	/// @param[out] foundTetIndex			The index of the tetrahedron that the point was in.
	/// @param[out] onFace1						Is set if the point is on one of the tetrahedrons faces.
	/// @param[out] onFace2						Is set if the point is on one of the tetrahedron edges (there for on two faces).
	/// @return												True if the point was inside a tetrahedron, false otherwise or on error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const;

	//----------------------------------------------------------------------------------------
	/// Returns the index of the tetrahedron the input point is in.
	/// THREADSAFE.
	/// @param[in] point							The point position to search the tetrahedron index for.
	/// @param[out] foundTetIndex			The index of the tetrahedron that the point was in.
	/// @return												True if the point was inside a tetrahedron, false otherwise or on error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const;
};

#include "delaunay3d1.hxx"
#include "delaunay3d2.hxx"

} // namespace maxon


#endif // DELAUNAY3D_H__
