#ifndef NODESGRAPH_HELPERS_H__
#define NODESGRAPH_HELPERS_H__

#include "maxon/interfacebase.h"
#include "maxon/nodesgraph.h"

namespace maxon
{

namespace nodes
{

// The graph of the original nimbus object and the time stamp of the original graph at the time is was copied.
using OriginalGraph = Tuple<nodes::NodesGraphModelRef, TimeStamp>;

MAXON_ATTRIBUTE(OriginalGraph, OriginalGraphAttr, "net.maxon.nimbus.originalgraph");

/// @brief Tuple like struct to hold a node and its asset identifier.
/// A node can have multiple nested base NodeSystem, each having a specific identifier.
/// @see NodesGraphHelpers::FindNodesBasedOnAssetId.
struct NodeWithAssetId
{
	GraphNode _node;						///< The node.
	IdAndVersion _assetAid;			///< On one the node's base asset.
	MAXON_STRUCT_TUPLE(NodeWithAssetId, _node, _assetAid);
};

class NodesGraphHelpers
{
	MAXON_INTERFACE_NONVIRTUAL(NodesGraphHelpers, MAXON_REFERENCE_STATIC, "net.maxon.interface.nodesgraphhelpers", MAXON_IMPLEMENTATION_MODULE("net.maxon.nodes"));
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

	//----------------------------------------------------------------------------------------
	/// @brief Finds all nodes child of #startNode which are based on a specific node asset.
	/// Goal is the same as GraphModelHelper::FindNodesByAssetId, but accounting for multiple or nested base assets.
	/// @see GraphModelHelper::FindNodesByAssetId.
	/// 
	/// @param[in] startNode					The search starting point in the graph. Can be the root node to search a whole graph.
	/// @param[in] assetId						The asset identifier to search for.
	/// @param[in] recv								The callback to process matches.
	/// @return												Result from #recv.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> FindNodesBasedOnAssetId(const GraphNode& startNode, const Id& assetId, const ValueReceiver<const NodeWithAssetId&>& recv);

};

#include "nodesgraph_helpers1.hxx"
#include "nodesgraph_helpers2.hxx"

} // namespace nodes
} // namespace maxon


#endif // NODESGRAPH_HELPERS_H__
