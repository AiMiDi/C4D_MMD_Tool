#ifndef FILTER_COMMAND_QUEUE_H__
#define FILTER_COMMAND_QUEUE_H__

#include "filter.h"

namespace maxon
{
//----------------------------------------------------------------------------------------
/// A Filter Command queue allows queuing of multiple filter's of the same context.
//----------------------------------------------------------------------------------------
class FilterCommandQueueInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FilterCommandQueueInterface, MAXON_REFERENCE_NORMAL, "net.maxon.renderfilter.filtercommandqueue.interface");
public:
	//----------------------------------------------------------------------------------------
	/// Enqueues a filter to the filter queue
	/// @param[in] filter			Filter to enqueue
	/// @param[in] input			Input Image to the filter
	/// @param[in] output			Output Image of the filter
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachFilter(FilterRef filter, FilterImageRef input, FilterImageRef output);
	
	//----------------------------------------------------------------------------------------
	/// Enqueues a filter to the filter queue which will operate on a specific region of the image
	/// @param[in] filter			Filter to enqueue
	/// @param[in] input			Input Image to the filter
	/// @param[in] output			Output Image of the filter
	/// @param[in] x					Starting point x
	/// @param[in] y					Starting point y
	/// @param[in] w					Width of region
	/// @param[in] h					Height of region
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachFilterRect(FilterRef filter, FilterImageRef input, FilterImageRef output, UInt32 x, UInt32 y, UInt32 w, UInt32 h);
	
	//----------------------------------------------------------------------------------------
	/// Dequeues a filter from the filter queue
	/// @param[in] filter 		Filter to dequeue
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DetachFilter(FilterRef filter);
};

#include "filter_command_queue1.hxx"
MAXON_REGISTRY(Class<FilterCommandQueueRef>, FilterCommandQueueClasses, "net.maxon.renderfilter.registry.filtercommandqueueclasses");
namespace FilterCommandQueueClasses
{
	MAXON_DECLARATION(FilterCommandQueueClasses::EntryType, OIDNFILTERCOMMANDQUEUE, "net.maxon.renderfilter.filtercommandqueueclass.oidnfiltercommandqueue");
}
#include "filter_command_queue2.hxx"
}

MAXON_DEPENDENCY_WEAK("maxon/filter_command_queue.h"); // This is an optional component

#endif // FILTER_COMMAND_QUEUE_H__
