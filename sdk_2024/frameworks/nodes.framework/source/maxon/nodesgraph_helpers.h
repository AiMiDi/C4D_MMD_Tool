#ifndef NODESGRAPH_HELPERS_H__
#define NODESGRAPH_HELPERS_H__

#include "maxon/interfacebase.h"
#include "maxon/objectbase.h"

#include "maxon/nodesgraph.h"
#include "maxon/graph.h"

namespace maxon
{
namespace nodes
{

// The graph of the original nimbus object and the time stamp of the original graph at the time is was copied.
using OriginalGraph = Tuple<nodes::NodesGraphModelRef, TimeStamp>;

MAXON_ATTRIBUTE(OriginalGraph, OriginalGraphAttr, "net.maxon.nimbus.originalgraph");

class NodesGraphHelpersInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NodesGraphHelpersInterface, MAXON_REFERENCE_STATIC, "net.maxon.interface.nodesgraphhelpers");
public:

	//----------------------------------------------------------------------------------------
	/// Sets the original graph of a graph clone. This method has to be called for clones for previews or renderings
	/// so that compiler messages can be passed to the original (which is the one the user edits).
	/// @param[in] graph							Clone of orig.
	/// @param[in] orig								Original user-accessible graph.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetOriginal(const nodes::NodesGraphModelRef& graph, const nodes::NodesGraphModelRef& orig);

	//----------------------------------------------------------------------------------------
	/// Sets the original graph of a graph clone. This method has to be called for clones for previews or renderings
	/// so that compiler messages can be passed to the original (which is the one the user edits).
	/// @param[in] graph							The mutable clone of orig.
	/// @param[in] orig								Original user-accessible graph.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetOriginal(MutableRoot& graph, const NodesGraphModelRef& orig);

	//----------------------------------------------------------------------------------------
	/// Returns the original graph of a graph clone.
	/// @param[in] graph							Clone of orig.
	/// @return												Original user-accessible graph.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<nodes::NodesGraphModelRef> GetOriginal(const nodes::NodesGraphModelRef& graph);

	//----------------------------------------------------------------------------------------
	/// Returns the modification stamp of the graph when it was cloned.
	/// @param[in] graph							Clone of orig.
	/// @return												The original TimeStamp.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<TimeStamp> GetOriginalModificationStamp(const NodesGraphModelRef& graph);
};

#include "nodesgraph_helpers1.hxx"
#include "nodesgraph_helpers2.hxx"

} // namespace nodes
} // namespace maxon


#endif // NODESGRAPH_HELPERS_H__
