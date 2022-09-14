#ifndef _GRAPH_HELPER_H__
#define _GRAPH_HELPER_H__


#include "maxon/graph.h"
namespace maxon
{
//----------------------------------------------------------------------------------------
// Regroups functions to simplify the usage of the node API. 
// Those functions help developers retrieving and manipulate information about a node system.
// Those functions mainly use internal function from the GraphModelInterface and do not offer 
// more functionalities than what can be already done.
//----------------------------------------------------------------------------------------
class GraphModelHelper
{
	MAXON_INTERFACE_NONVIRTUAL(GraphModelHelper, MAXON_REFERENCE_STATIC, "net.maxon.graph.interface.graphmodelhelper");
	
public:

	//----------------------------------------------------------------------------------------
	/// Retrieves the first level of nodes or ports connected to the passed port or node. This will only retrieve nodes or ports that are connected to the inputs.
	/// @param[in] node									The starting point to retrieve the direct predecessors. A node or a port can be used. If a port is used, an input port must be used.
	/// @param[in] filter								The NODE_KIND that will be included. The function search for all possible nodes or ports and will include them or not based on this filter.
	/// @param[out] callback							The callback that will receive all connected nodes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetDirectPredecessors(const GraphNode& node, NODE_KIND filter, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes or ports connected to the passed port or node. This will only retrieve nodes or ports that are connected to the inputs.
	/// @param[in] node									The starting point to retrieve all the predecessor. A node or a port can be used. If a port is used, an input port must be used.
	/// @param[in] filter								The NODE_KIND that will be included. The function search for all possible nodes or ports and will include them or not based on this filter.
	/// @param[out] callback							The callback that will receive all connected nodes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetAllPredecessors(const GraphNode& node, NODE_KIND filter, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Retrieves the first level of nodes or ports connected to the passed port or node. This will only retrieve nodes or ports that are connected to the outputs.
	/// @param[in] node									The starting point to retrieve the direct successors. A node or a port can be used. If a port is used, an output port must be used.
	/// @param[in] filter								The NODE_KIND that will be included. The function search for all possible nodes or ports and will include them or not based on this filter.
	/// @param[out] callback							The callback that will receive all connected nodes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetDirectSuccessors(const GraphNode& node, NODE_KIND filter, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes or ports connected to the passed port or node. This will only retrieve nodes or ports that are connected to the outputs.
	/// @param[in] node									The starting point to retrieve all the successors. A node or a port can be used. If a port is used, an output port must be used.
	/// @param[in] filter								The NODE_KIND that will be included. The function search for all possible nodes or ports and will include them or not based on this filter.
	/// @param[out] callback							The callback that will receive all connected nodes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetAllSuccessors(const GraphNode& node, NODE_KIND filter, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Mutes the connection between a node or port and another port.
	/// If a true node is passed, and the port is connected to one or several input port, all the connections will be muted between the port and the node.
	/// For example, a constant port is connected to several input port of another node.
	/// @param[in] srcNode									The node to mute the connection with.  
	/// @param[in] dstPort									The other port the connection must be muted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MuteConnection(const GraphNode& srcNode, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Mutes all incoming or outgoing connections of a node depending on the specified direction
	/// @param[in] node									The true node to mute all the connections. 
	/// @param[in] direction						The direction where all connection will be muted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MuteAllConnections(const GraphNode& node, PORT_DIR direction);

	//----------------------------------------------------------------------------------------
	/// Unmutes the connection between a node or port and another port.
	/// If a true node is passed, depending of the port passed direction, every output or every input will be unmuted.
	/// @param[in] srcNode							The node to unmute the connection with. 
	/// @param[in] dstPort							The other port that the connection must be Unmuted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> UnmuteConnection(const GraphNode& srcNode, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Unmutes all the connections in one direction.
	/// @param[in] node									The node to unmute the connection. 
	/// @param[in] direction						The direction where all connection will be Unmuted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> UnmuteAllConnections(const GraphNode& node, PORT_DIR direction);

	//----------------------------------------------------------------------------------------
	/// Removes all the connection a true node have. The node should be a true node. To remove connection for a port, use maxon::GraphNodeFunctions::RemoveConnections()
	/// @param[in] node									The node to remove all the connections to.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RemoveAllConnections(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Removes the connections between two ports.
	/// @param[in] srcPort							The source's port.
	/// @param[in] dstPort							The destination's port.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RemoveConnection(const GraphNode &srcPort, const GraphNode &dstPort);

	//----------------------------------------------------------------------------------------
	/// Selects the connection between two ports.
	/// @param[in] srcPort							The connection's source port.
	/// @param[in] dstPort							The connection's destination port.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SelectConnection(const GraphNode& srcPort, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Deselects the connection between two ports. A connection hold a Wire object.
	/// There is at most one connection between two port, but this connection is composed by 8 wires.
	/// @param[in] srcPort							The connection's source port.
	/// @param[in] dstPort							The connection's destination port.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DeselectConnection(const GraphNode& srcPort, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Retrieves all the selected connections on the graph. A connection hold a Wire object.
	/// There is none or only one connection between two ports, and this connection is composed by multiple wires.
	/// @param[in] graphModel						The GraphModelRef to retrieve the GraphNode from the path.
	/// @param[out] callback						This callback will receive the source and destination ports and the wires itself.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetSelectedConnections(const GraphModelRef& graphModel, const ValueReceiver<const GraphNode&, const GraphNode&, const Wires&>& callback);

	//----------------------------------------------------------------------------------------
	/// Selects a node or a port.
	/// @param[in] node 								The node or the port that have to be selected.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SelectNode(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Deselects a node or a port.
	/// @param[in] node 								The node or the port that have to be Deselected.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DeselectNode(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes having their stored data equals the ones in the passed DataDictionary.
	/// The passed DataDictionary can have one or multiple data defined. 
	/// The function will compare all the value inside the DataDictionary, if they all match, the node will be returned.
	/// @code
	/// // Retrieve all nodes with a defined name
	/// DataDictionary nodeProperties;
	/// nodeProperties.Set(NODE::BASE::NAME, groupName) iferr_return;
	/// GraphModelHelper::ListAllNodes(nodeGraph, nodeProperties, [](const GraphNode& child)
	///	{
	///		ApplicationOuput("node that have this name @", child);
	///		return true;
	///	}) iferr_return;
	/// @endcode
	/// @param[in] graphModel						The GraphModelRef to list the node.
	/// @param[in] matchingData					The Dictionary filled with the data we want to compare the GraphNode with.
	/// @param[out] callback						This callback will receive all nodes founded that have the same data values than those passed within the Dictionary
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ListAllNodes(const GraphModelRef& graphModel, const DataDictionary& matchingData, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Checks if a connection between two port is selected. A connection hold a Wire object.
	/// There is at most one connection between two port, but this connection is composed by 8 wires.
	/// If a GraphNode is passed instead a NodePath, the GraphNode will be converted to NodePath.
	/// @param[in] srcPort							The connection's source port.
	/// @param[in] dstPort							The connection's destination port.
	/// @return													@trueIfOtherwiseFalse{the connection is selected}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsConnectionSelected(const GraphNode& srcPort, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Retrieves all selected ports and/or true node on the graph depending on the NODE_KIND passed as argument.
	/// @param[in] graphModel						The GraphModelRef to retrieve the selected elements.
	/// @param[in] kind									The GraphNode kind to check.
	/// @param[out] callback						This callback will receive all selected ports and/or true node.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetSelectedNodes(const GraphModelRef& graphModel, NODE_KIND kind, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Deselect all true nodes and ports based on the NODE_KIND passed as parameter.
	/// @param[in] graphModel						The GraphModelRef to deselect elements.
	/// @param[in] kind									The GraphNode's kind that will be deselected.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DeselectAll(const GraphModelRef& graphModel, NODE_KIND kind);

	//----------------------------------------------------------------------------------------
	/// Checks if this node or port is connected to another port. If a true node is passed, every port on the node will be tested. If a port is passed, only the passed port will be tested.
	/// @param[in] srcNode							The node to check the connection with.
	/// @param[in] dstPort							The port to check the connection with.
	/// @return													@trueIfOtherwiseFalse{ports are connected}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsConnected(const GraphNode& srcNode, const GraphNode& dstPort);

	//----------------------------------------------------------------------------------------
	/// Returns if the node or the port is selected or not.
	/// @param[in] node									The Node or the Port to check.
	/// @return													@trueIfOtherwiseFalse{the node or the port is selected}.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsNodeSelected(const GraphNode& node);

	//-------------------------------------------------------------------------------------------------
	/// Find all GraphNode (true nodes or ports) that have the same name as the passed argument. 
	/// This function will return several nodes/port if they share the same name.
	/// @warning	Name of true nodes or port can change depending on the language of Cinema4D.
	///						Search based on name should be avoided as mush as possible, unless you are sure the name will not be different on any setup.
	/// @param[in] graphModel						The GraphModelRef to search for the nodes.
	/// @param[in] nodeName 						The name of the true node or the port to look for.
	/// @param[in] kind 								Filter that will be applied to the kind of GraphNode we are looking for. By default, All type (true node/ports)
	/// @param[in] direction 						Filter the GraphNode by direction. Input or Output. By default INPUT.
	/// @param[in] exactName 						Set true if the exact name should be search. If this is set to false, check if the passed name is contained in the GraphNode's name.
	/// @param[out] callback 						This callback will receive all ports and/or true node that have the same name.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FindNodesByName(const GraphModelRef& graphModel, const String& nodeName, NODE_KIND kind, PORT_DIR direction, Bool exactName, const ValueReceiver<const GraphNode&>& callback);

	/// Find all GraphNode (true nodes or ports) that have the same id as the passed argument.
	/// This function will return several nodes/port if they share the same id.
	/// @param[in] graphModel						The GraphModelRef to search for the nodes.
	/// @param[in] nodeId 							The id of the true node or the port to look for.
	/// @param[in] kind 								Filter that will be applied to the kind of GraphNode we are looking for. By default, All type (true node/ports)
	/// @param[in] direction 						Filter the GraphNode by direction. Input or Output. By default INPUT.
	/// @param[in] exactId 							Set true if the exact id should be search. If this is set to false, check if the passed id is contained in the GraphNode's id.
	/// @param[out] callback 						This callback will receive all ports and/or true node that have the same name.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FindNodesById(const GraphModelRef& graphModel, const Id& nodeId, NODE_KIND kind, PORT_DIR direction, Bool exactId, const ValueReceiver<const GraphNode&>& callback);
	
	/// Find all true nodes that have the same AssetId as the passed argument. Only nodes have assetId.
	/// This function will return several nodes if they share the same assetId.
	/// @param[in] graphModel						The GraphModelRef to search for the nodes.
	/// @param[in] assetId 							The AssetId of the true node or the port to look for. This have the form of a reversed domain string. e.g "net.maxon.asset.utility.color"
	/// @param[in] exactId 							Set true if the exact id should be search. If this is set to false, check if the passed id is contained in the node assetID.
	/// @param[out] callback 						This callback will receive all ports and/or true node that have the same name.
	//-------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FindNodesByAssetId(const GraphModelRef& graphModel, const Id& assetId, Bool exactId, const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Creates and returns a new OutputPort. The port will be identify by the passed id and will be rename with the passed string. 
	/// This new port can only be created on the root or any group node.
	/// @param[in] dstNode							The node where to create the output port.
	/// @param[in] portId								The id of the port that need to be created.
	/// @param[in] portName							The name of the port that need to be created.
	/// @return													The created port.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphNode> CreateOutputPort(const GraphNode& dstNode, const CString& portId, const String& portName = String("Output"));

	//----------------------------------------------------------------------------------------
	/// Creates and returns a new InputPort. The port will be identify by the passed id and will be rename with the passed string. 
	/// This new port can only be created on the root or any group node.
	/// @param[in] dstNode							The node where to create the input port.
	/// @param[in] portId								The id of the port that need to be created.
	/// @param[in] portName							The name of the port that need to be created.
	/// @return													The created port.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphNode> CreateInputPort(const GraphNode& dstNode, const CString& portId, const String& portName = String("Input"));

};

} // end of namespace maxon

#include "graph_helper1.hxx"
#include "graph_helper2.hxx"


#endif
