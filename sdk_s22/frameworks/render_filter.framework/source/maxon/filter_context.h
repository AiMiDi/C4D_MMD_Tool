#ifndef FILTER_CONTEXT_INTERFACE_H__
#define FILTER_CONTEXT_INTERFACE_H__

#include "filter_command_queue.h"
#include "maxon/optional.h"

namespace maxon
{
class FilterContextInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FilterContextInterface, MAXON_REFERENCE_NORMAL, "net.maxon.renderfilter.filtercontext.interface");
public:
	//----------------------------------------------------------------------------------------
	/// Initializes the context
	/// @param[in] dict 					(Optional) input parameters
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<void>									Init(Opt<const DataDictionary&> dict = {});
	
	//----------------------------------------------------------------------------------------
	/// Creates Image according to the description given
	/// @param[in] imageDesc			The image description
	/// @return										The created Image
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<FilterImageRef>				CreateImage(const DataDictionary& imageDesc);
	
	//----------------------------------------------------------------------------------------
	/// Creates a filter, for example:
	/// @code
	/// maxon::FilterRef filter = filterContext.CreateFilter(maxon::FilterClasses::OIDNFILTERRT.GetId()) iferr_return;
	/// @endcode
	/// @param[in] filterType			The type of the filter
	/// @return										The created Filter
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<FilterRef>							CreateFilter(const LiteralId& filterType);
	
	//----------------------------------------------------------------------------------------
	/// Creates a command queue
	/// @return 									The created Command Queue
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<FilterCommandQueueRef>	CreateCommandQueue();
	
	//----------------------------------------------------------------------------------------
	/// Executes all the filters inside the command queue
	/// @param[in] commandQueue		The command queue to execute
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<void>									ExecuteCommandQueue(FilterCommandQueueRef commandQueue);
};

#include "filter_context1.hxx"
MAXON_REGISTRY(Class<FilterContextRef>, FilterContextClasses, "net.maxon.renderfilter.registry.filtercontextclasses");
namespace FilterContextClasses
{
	// Open Image Denoiser Context
	MAXON_DECLARATION(FilterContextClasses::EntryType, OIDNCONTEXT, "net.maxon.renderfilter.filterclass.oidncontext");
}
#include "filter_context2.hxx"
}

MAXON_DEPENDENCY_WEAK("maxon/filter_context.h"); // This is an optional component

#endif // FILTER_CONTEXT_INTERFACE_H__
