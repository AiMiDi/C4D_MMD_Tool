#ifndef CONVEXDECOMPOSITION_H__
#define CONVEXDECOMPOSITION_H__

#include "maxon/array.h"
#include "maxon/datadictionary.h"
#include "./convexdecomposition_attributes.h"

namespace maxon
{

class GeometryObject;

class ConvexDecompositionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ConvexDecompositionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.convexdecomposition");

public:
	//----------------------------------------------------------------------------------------
	/// Initialize the convex decomposition library.
	/// @param levelOfDetail	desired level of detail to retail in the decomposition.
	///												Allowed values are between 0 and 1. Recommended 0.5.
	/// @param maxVoxelCount	Maximum number of voxels used to decompose the bounding box
	/// @return												This @CLASS (to allow method chaining).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Float levelOfDetail = 0.5, UInt32 maxVoxelCount = 16000000);

	//----------------------------------------------------------------------------------------
	/// Initialize the convex decomposition library with the given settings.
	/// @return												This @CLASS (to allow method chaining).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const DataDictionary & settings);

	MAXON_METHOD Result<DataDictionary> GetSettings() const;
	//----------------------------------------------------------------------------------------
	/// Get the current status of the decomposition job.
	/// @return true if the decomposition is complete
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsReady() const;
	//----------------------------------------------------------------------------------------
	/// Get the current progress of the decomposition job.
	/// @return percentage completed
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<UInt16> GetProgress() const;

	//----------------------------------------------------------------------------------------
	/// Compute convex decomposition. By default this is done asynchronously. To be called after Init().
	/// @param geometryObject	geometry object to decompose
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Compute(const GeometryObject& geometryObject);
	//----------------------------------------------------------------------------------------
	/// Fetch results of the decomposition. In case the decomposition job is not done, wait for the results to be available.
	/// To be called after Compute().
	/// @return		An array of geometry objects where each entry represents one of the convex
	///						hulls the original object was decomposed into.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Array<GeometryObject>> FetchResults();
	//----------------------------------------------------------------------------------------
	/// Cancel the decomposition job
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Cancel();

	MAXON_METHOD Result<void> Clear();
};

#include "convexdecomposition1.hxx"

MAXON_REGISTRY(Class<ConvexDecompositionRef>, ConvexDecompositionClasses, "net.maxon.registry.convexdecompositionclasses");

namespace ConvexDecompositionClasses
{
	MAXON_DECLARATION(maxon::Class<ConvexDecompositionRef>, ConvexDecompositionVHACD, "net.maxon.convexdecompositionvhacd");
}

#include "convexdecomposition2.hxx"

} // namespace maxon

#endif // CONVEXDECOMPOSITION_H__
