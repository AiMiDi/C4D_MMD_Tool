#ifndef FILTER_INTERFACE_H__
#define FILTER_INTERFACE_H__

#include "filter_image.h"
#include "filter_parameter.h"
#include "maxon/optional.h"

namespace maxon
{
using FilterProgressMonitorFunction = Bool (*)(void* userPtr, Float progress);

//----------------------------------------------------------------------------------------
/// FilterInterface allows interfacing with the render filter
//----------------------------------------------------------------------------------------
class FilterInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FilterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.renderfilter.filter.interface");
public:	
	//----------------------------------------------------------------------------------------
	/// Sets Filter parameter
	/// @param[in] parameter	Parameter to set
	/// @param[in] data				Data for parameter
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const InternedId& parameter, const Data& data);
	
	//----------------------------------------------------------------------------------------
	/// Executes the filter standalone.
	/// @param[in] input	The input Filter Image
	/// @param[in] output	The target Filter Image
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute(const FilterImageRef& input, FilterImageRef output);

	//----------------------------------------------------------------------------------------
	/// Sets a progress monitor function pointer that gets invoked during the filter execution. 
	/// Only a single callback function can be registered, the next call to SetProgressMonitor overwrites the old one.
	/// The monitor function pointer gets called with provided userPtr and a progress in the range [0, 1].
	/// Returning false within the monitor will cancel the filter execution.
	/// @param[in] progressMonitor	The progress monitor function
	/// @param[in] userPtr					A custom user ptr that gets passed to the function pointer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetProgressMonitor(const FilterProgressMonitorFunction progressMonitor, void* userPtr);
};

#include "filter1.hxx"
MAXON_REGISTRY(Class<FilterRef>, FilterClasses, "net.maxon.renderfilter.registry.filterclasses");

namespace FilterClasses
{
	// Intel Denoiser type: Raytracing
	MAXON_DECLARATION(FilterClasses::EntryType, OIDNFILTERRT, "net.maxon.renderfilter.filterclass.oidn.rt");
}
#include "filter2.hxx"
}

MAXON_DEPENDENCY_WEAK("maxon/filter.h"); // This is an optional component

#endif // FILTER_INTERFACE_H__
