#ifndef CONVEXDECOMPOSITION_ATTRIBUTES_H__
#define CONVEXDECOMPOSITION_ATTRIBUTES_H__

#include "maxon/fid.h"
#include "maxon/apibase.h"

namespace maxon
{

namespace CONVEXDECOMPOSITIONATTRIBUTES
{
	enum class DECOMPOSITION_MODE
	{
		COARSE = 0,
		MEDIUM = 1,
		FINE = 2
	} MAXON_ENUM_LIST(DECOMPOSITION_MODE);

	MAXON_ATTRIBUTE(Bool, ASYNCH, "net.maxon.convexdecomposition.convexdecompositionattributes.asynch", RESOURCE_DEFAULT(true));
	MAXON_ATTRIBUTE(DECOMPOSITION_MODE, MODE, "net.maxon.convexdecomposition.convexdecompositionattributes.mode", RESOURCE_DEFAULT(DECOMPOSITION_MODE::MEDIUM));
	MAXON_ATTRIBUTE(Int, THREADCOUNT, "net.maxon.convexdecomposition.convexdecompositionattributes.threadcount", RESOURCE_DEFAULT(1));
}

#include "convexdecomposition_attributes1.hxx"
#include "convexdecomposition_attributes2.hxx"

} // namespace maxon


#endif // CONVEXDECOMPOSITION_ATTRIBUTES_H__