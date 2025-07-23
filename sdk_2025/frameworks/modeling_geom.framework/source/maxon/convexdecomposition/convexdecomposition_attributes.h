#ifndef CONVEXDECOMPOSITION_ATTRIBUTES_H__
#define CONVEXDECOMPOSITION_ATTRIBUTES_H__

#include "maxon/fid.h"
#include "maxon/apibase.h"

namespace maxon
{

namespace CONVEXDECOMPOSITIONATTRIBUTES
{
	MAXON_ATTRIBUTE(Bool, ASYNCH, "net.maxon.convexdecomposition.convexdecompositionattributes.asynch", RESOURCE_DEFAULT(true));
	/// Desired level of detail to retail in the decomposition. Allowed values are between 0 and 1. Recommended 0.5.
	MAXON_ATTRIBUTE(Float, LEVELOFDETAIL, "net.maxon.convexdecomposition.convexdecompositionattributes.levelofdetail", RESOURCE_DEFAULT(0.5));
	/// Maximum number of voxels used to decompose the bounding box, if the implementation uses voxelization.
	MAXON_ATTRIBUTE(UInt32, MAXVOXELCOUNT, "net.maxon.convexdecomposition.convexdecompositionattributes.maxvoxelcount", RESOURCE_DEFAULT(16000000));
	/// Maximum number of vertices for each output convex hull. For use with physx on the gpu: set lower or equal to 64
	MAXON_ATTRIBUTE(UInt32, MAXVERTICESPERCONVEXHULL, "net.maxon.convexdecomposition.convexdecompositionattributes.maxverticesperconvexhull", RESOURCE_DEFAULT(64));
	/// Maximum number of output convex hulls.
	MAXON_ATTRIBUTE(UInt32, MAXCONVEXHULLS, "net.maxon.convexdecomposition.convexdecompositionattributes.maxconvexhulls", RESOURCE_DEFAULT(1024));
	MAXON_ATTRIBUTE(Int, THREADCOUNT, "net.maxon.convexdecomposition.convexdecompositionattributes.threadcount", RESOURCE_DEFAULT(0));
}

#include "convexdecomposition_attributes1.hxx"
#include "convexdecomposition_attributes2.hxx"

} // namespace maxon


#endif // CONVEXDECOMPOSITION_ATTRIBUTES_H__