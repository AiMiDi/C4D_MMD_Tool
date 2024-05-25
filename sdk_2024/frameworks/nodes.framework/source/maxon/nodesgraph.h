#ifndef NODESGRAPH_H__
#define NODESGRAPH_H__

#include "maxon/forwardref.h"
#include "maxon/nodesystem.h"
#include "maxon/graph.h"

namespace maxon
{

class UserStateDerivationRef;

namespace nodes
{

class NodesGraphModelRef;
class NodeSystemManagerRef;
class NodesGraphModelImpl;
class NodeTemplate MAXON_FORWARD("maxon/nodetemplate.h");

MAXON_ATTRIBUTE(void, Messages, "messages");


//----------------------------------------------------------------------------------------
/// Type of the PortConnectionState attribute.
//----------------------------------------------------------------------------------------
enum class PORT_CONNECTION_STATE
{
	NONE = 0,																					///< No flag set.
	SAME_LEVEL = 1,																		///< There is a normal (non-propagation) connection to a port of a node at the same level.
	OUTER_LEVEL = 2,																	///< There is a normal (non-propagation) connection to a port of an enclosing node.
	PROPAGATED = 4,																		///< There is a propagation connection to an enclosing node.
	AUTO_PROPAGATED = 8,															///< There is an auto-propagation connection to an enclosing node.

	NORMAL_MASK = SAME_LEVEL | OUTER_LEVEL,						///< Use this mask to test for SAME_LEVEL or OUTER_LEVEL.
	PROPAGATED_MASK = PROPAGATED | AUTO_PROPAGATED		///< Use this mask to test for PROPAGATED or AUTO_PROPAGATED.
} MAXON_ENUM_FLAGS(PORT_CONNECTION_STATE);

//----------------------------------------------------------------------------------------
/// The PortConnectionState attribute is a derived attribute which can be queried at a port to get
/// some information about the port connection state (see also PORT_CONNECTION_STATE).
/// For input ports the information is about incoming connections, for output ports
/// about outgoing connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(PORT_CONNECTION_STATE, PortConnectionState, "portconnectionstate");


//----------------------------------------------------------------------------------------
/// A node system manager manages a NodeSystem and several views on that NodeSystem,
/// where each view is a NodesGraphModelRef. A node system manager is created by methods
/// of NodesGraphModelInterface.
///
/// The task of the manager is to coordinate accesses to a shared node system from
/// different views: It stores a single NodeSystem reference which is used by all views,
/// a ChangeList to track changes made by any of the views, and also transaction observers which
/// get informed about transactions made by any of the views.
///
/// NodeSystemManagerClass is the base implementation of this interface. It has to be
/// used as base class for custom implementations.
///
/// @note This class as well as the views are not thread-safe. This class coordinates
/// different views, but everything has to happen within the same thread
/// (or be properly synchronized by the callers).
//----------------------------------------------------------------------------------------
class NodeSystemManagerInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(NodeSystemManagerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.node.interface.nodesystemmanager");

public:
	//----------------------------------------------------------------------------------------
	/// Filter flags for views, see CreateView.
	//----------------------------------------------------------------------------------------
	enum class FILTER
	{
		NONE = 0,																			///< No flags set.
		INCLUDE_INNER = 1 << 0,												///< Includes inner nodes in the view.
		INCLUDE_HIDDEN = 1 << 1,											///< Includes hidden nodes in the view.
		INCLUDE_ALL = INCLUDE_INNER | INCLUDE_HIDDEN,	///< Combination of all include flags.
		READ_ONLY = 1 << 2,														///< Creates a read-only view.
		NO_COMPONENT_ACCESS = 1 << 3,									///< All the unused component access ports will not be part of the graph.
	} MAXON_ENUM_FLAGS_CLASS(FILTER);

	MAXON_ADD_TO_REFERENCE_CLASS
	(
	using FILTER = typename NodeSystemManagerInterface::FILTER;
	);

	//----------------------------------------------------------------------------------------
	/// Creates a view of the node system of this manager using the given settings.
	/// @param[in] filter							The filter to use for the view.
	/// @param[in] rootPath						The path to the root node of the view. Use this if the view shall not
	///																represent the whole graph, but only a node and its inner parts.
	/// @return												A new view.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodesGraphModelRef> CreateView(FILTER filter, const NodePath& rootPath);

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository to use for lookups within graph models created by this manager.
	/// This repository is used whenever an asset is looked up.
	/// @return												The asset repository for lookup.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const AssetRepositoryRef& GetLookupRepository() const;

	//----------------------------------------------------------------------------------------
	/// Returns the node system reference of this manager. The node system itself may change over time
	/// due to its copy-on-write nature.
	/// @return												The managed node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeSystem& GetNodeSystem() const;

	//----------------------------------------------------------------------------------------
	/// This method gets called when the outmost transaction has started
	/// (observers will be informed afterwards). You can override this method in subclasses
	/// of to trigger special actions. It is guaranteed that a matching call to TransactionEnded will happen.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void TransactionStarted();

	//----------------------------------------------------------------------------------------
	/// This method gets called during a commit, immediately before observers and TransactionEnded().
	/// You can override this method in subclasses to do some clean-up.
	/// @param[in] userData						The user data passed to GraphTransaction::Commit.
	/// @param[in] changeList					The optional change list to track changes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinalizeTransaction(const DataDictionary& userData, ChangeList* changeList);

	//----------------------------------------------------------------------------------------
	/// This method gets called during a commit, immediately before observers and TransactionEnded(),
	/// but after FinalizeTransaction().
	/// You can override this method in subclasses to do some validation. The persistent
	/// state of the graph must not be modified, this has to be done in FinalizeTransaction().
	/// @param[in] userData						The user data passed to GraphTransaction::Commit.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ValidateTransaction(const DataDictionary& userData);

	//----------------------------------------------------------------------------------------
	/// This method gets called when the outmost transaction has ended by a commit or rollback
	/// (observers have been informed before). You can override this method in subclasses
	/// to trigger special actions. It is guaranteed that a matching call to TransactionStarted has happened before.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void TransactionEnded();

	//----------------------------------------------------------------------------------------
	/// Returns a time stamp of this manager which can be used to test for modifications,
	/// see GraphModelInterface::GetModificationStamp. All views use this time stamp too.
	///
	/// The time stamp doesn't coincide with the time stamp of the node system, because the manager
	/// also manages user state attributes which aren't stored at the node system.
	///
	/// @return												Modification time stamp of the manager.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeStamp GetModificationStamp() const;

	//----------------------------------------------------------------------------------------
	/// Returns the main view of this manager. This is the initial view which has been created
	/// in conjunction with this manager by NodesGraphModelInterface::Create (unless that
	/// view has been freed in the mean time, then the returned view is one of the other views
	/// or a null reference if there is no view left).
	/// @return												Main view of this manager.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodesGraphModelRef& GetMainView() const;

	//----------------------------------------------------------------------------------------
	/// Returns the change list to which this manager currently logs modifications.
	/// A newly created manager doesn't automatically create a change list, so to start
	/// logging you need to call StartNewChangeList() once. The change list can be used
	/// to undo or redo the changes or even to apply them to a different node system, see Apply().
	/// @return												Current change list, may be a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ChangeList& GetChangeList();

	//----------------------------------------------------------------------------------------
	/// Starts a new change list and returns the previous one. Afterwards this manager will log
	/// all modifications to the newly created change list. The new change list can be obtained with
	/// GetChangeList() or as the result of the next call to StartNewChangeList().
	/// The returned change list contains all modifications which have been made since the previous
	/// call to StartNewChangeList(). You can pass it to Apply() to undo or redo the changes.
	/// @return												Change list which contains the modifications since the previous call to StartNewChangeList().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ChangeList> StartNewChangeList();

	//----------------------------------------------------------------------------------------
	/// Applies the given change list to the node system of this manager.
	/// @param[in] list								Change list to apply.
	/// @param[in] inverse						Use true if the inverse of the change list shall be applied (for an undo), false otherwise.
	/// @return												A new change list which contains those changes of list which couldn't be applied,
	///																for example the change of an attribute value at a node which doesn't exist in the node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ChangeList> Apply(const ChangeList& list, Bool inverse);

	//----------------------------------------------------------------------------------------
	/// Informs about the start of a transaction. This is called during BeginTransaction(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] manager						The manager at which the observer was registered.
	/// @param[in] userData						The user data given to GraphModelRef::BeginTransaction(). In case of nested transactions,
	///																this is the user data of the outmost (i.e. first) invocation.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionStarted, (const NodeSystemManagerRef& manager, const DataDictionary& userData), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the commit of a transaction. This is called during GraphTransaction::Commit(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] manager						The manager at which the observer was registered.
	/// @param[in] userData						The user data given to GraphTransaction::Commit(). In case of nested transactions,
	///																this is the merger of the user datas given to all commits.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionCommitted, (const NodeSystemManagerRef& manager, const DataDictionary& transactionUserData), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the rollback of a transaction. This is called during GraphTransaction::Rollback(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] manager						The manager at which the observer was registered.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionRolledBack, (const NodeSystemManagerRef& manager), ObservableCombinerRunAllComponent);

	/// @private
	MAXON_METHOD Result<void> Update(const Block<const Tuple<AssetReference, AssetBase>>& updates);

	MAXON_METHOD Result<void> SetNodeSystem(const NodeSystem& sys);

	//----------------------------------------------------------------------------------------
	/// Forces the manager to increment it's TimeStamp. This will force the GraphModel to validate
	/// all the outdated GNodeHandle.
	/// @see GraphModelInterface::GetModificationStamp.
	/// @return												The incremented stamp value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeStamp IncSystemStamp();

protected:
	//----------------------------------------------------------------------------------------
	/// Creates a new graph model instance of an implementation class which is suitable for this manager.
	/// Initialization methods will be called later.
	/// @return												New graph model instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodesGraphModelRef> CreateGraphModel() const;

};


//----------------------------------------------------------------------------------------
/// A NodesGraphModelRef is an implementation of GraphModelInterface which wraps a NodeSystem.
/// There may be more than one model working on the same NodeSystem reference, this is
/// handled by a shared NodeSystemManagerRef: Each NodesGraphModelRef is a certain
/// @ref CreateView "view" on the NodeSystem with individual filter settings and root paths,
/// and the manager coordinates the accesses of the views.
///
/// NodesGraphModelClass is the base implementation of this interface. It has to be
/// used as base class for custom implementations.
//----------------------------------------------------------------------------------------
class NodesGraphModelInterface : MAXON_INTERFACE_BASES(GraphModelInterface)
{
	MAXON_INTERFACE(NodesGraphModelInterface, MAXON_REFERENCE_NORMAL, "net.maxon.node.interface.nodesgraphmodel");

public:
	//----------------------------------------------------------------------------------------
	/// Creates a new manager to be used for this graph model. This method should not be invoked
	/// by user code, however you can override the default implementation to create a
	/// customized manager.
	/// @return												A new manager to manage this graph model.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystemManagerRef> CreateManager() const;

	//----------------------------------------------------------------------------------------
	/// Initializes a new NodesGraphModelRef view for the node system. Also a NodeSystemManagerRef is created
	/// which manages the NodesGraphModelRef and possible further views.
	/// @param[in] system							The initial state of the node system.
	/// @param[in] lookup							The asset search scope to use for the graph model.
	/// @param[in] filter							The filter to use for the view.
	/// @param[in] supportRollback		Use true if GraphTransaction::Rollback shall be supported by the graph model.
	///																This keeps a copy of the original state of the node system before a transaction is started.
	/// @return												A new NodesGraphModelRef view for system.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const NodeSystem& system, const AssetRepositoryRef& lookup, NodeSystemManagerInterface::FILTER filter = NodeSystemManagerInterface::FILTER::NONE, Bool supportRollback = true);

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository to use for lookups for the node graph.
	/// This repository is used whenever an asset is looked up.
	/// @return												The asset repository for lookup.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const AssetRepositoryRef& GetLookupRepository() const;

	//----------------------------------------------------------------------------------------
	/// Returns the manager which manages this graph model. The manager may manage more than
	/// one graph model, each model represents a specific view on the underlying node system.
	/// @return												The manager of this graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeSystemManagerRef& GetManager() const;

	//----------------------------------------------------------------------------------------
	/// Creates a new view for the node system of this view. The returned view will be managed
	/// by the same NodeSystemManagerRef as this view.
	/// @note CreateView does not call Init (just PrivateInit).
	/// @param[in] filter							The filter to use for the view. If this view is read-only,
	///																the FILTER::READ_ONLY flag will be set implicitly.
	/// @param[in] rootPath						The absolute path to the root node of the new view. Use this if the new view shall not
	///																represent the whole graph, but only a node and its inner parts.
	///																Note that this is an absolute path, so the path of the current
	///																view is always ignored.
	/// @return												A new NodesGraphModelRef view for the same node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodesGraphModelRef> CreateView(NodeSystemManagerInterface::FILTER filter, const NodePath& rootPath);

	//----------------------------------------------------------------------------------------
	/// Returns flags applied to GetNode and other GraphModelInterface methods.
	/// @return												The node filtering flags of the view.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NodeSystemManagerInterface::FILTER GetNodeFilter();

	//----------------------------------------------------------------------------------------
	/// Returns flags applied to GetConnections other GraphModelInterface methods.
	/// @return												The node filtering flags of the view.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Wires GetWireFilter();

	//----------------------------------------------------------------------------------------
	/// Returns the node system reference wrapped by this graph. The node system itself may change over time
	/// due to its copy-on-write nature.
	/// @return												The underlying node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NodeSystem GetNodeSystem();

	MAXON_METHOD const NodeSystem& GetBase(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Recursively finds all the bases of a node or port. This is useful for ports which are made from 
	/// an asset and resource different then their ancestor node.
	/// @param[in] node								The node for which we want all base NodeSystem.
	/// @param[in] receiver						ValueReceiver or Array that will receive all the base NodeSystem found.
	/// @return												False if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetAllBases(const GraphNode& node, const ValueReceiver<const NodeSystem&>& receiver);

	//----------------------------------------------------------------------------------------
	/// Returns the NodeTemplate which instantiated #node.
	/// @param[in] node								The node for which we want the template.
	/// @return												The NodeTemplate which instantiated the NodeSystem of #node, or a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeTemplate& GetTemplate(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Recursively finds all the templates of a node or port. This is useful for ports which are made from 
	/// an asset and resource different then their ancestor node.
	/// @param[in] node								The node for which we want all templates.
	/// @param[in] receiver						ValueReceiver or Array that will receive all the NodeTemplate found.
	/// @return												False if ValueReceiver was canceled. True otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetAllTemplates(const GraphNode& node, const ValueReceiver<const NodeTemplate&>& receiver);

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the node system in mutable state. When outsideOfTransaction is false
	/// (the default) a GraphTransaction has to be active, otherwise an IllegalStateError is returned.
	/// When outsideOfTransaction is true the NodeSystem is made writable like a usual copy-on-write
	/// reference, you should use this only to @ref NodeSystemInterface::SetValue "set values"
	/// of attributes which don't need validation or notification.
	/// @param[in] outsideOfTransaction	Usually false (the default), use true for a modification which
	/// 															shall bypass the normal validation and notification mechanism.
	/// @return												Pointer to the underlying node system with write access.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystemInterface*> GetMutableNodeSystem(Bool outsideOfTransaction = false);

	MAXON_USING(GraphModelInterface::AddChild);

	//----------------------------------------------------------------------------------------
	/// Adds an instance of a node system as child of the root node to this graph. If #childId is empty, a
	/// UUID will be chosen as identifier of the child, otherwise #childId. In the latter
	/// case it is an error if this root node already has a child with that identifier.
	/// @param[in] childId						Identifier for the child node (if empty, a UUID is chosen).
	/// @param[in] base								Node system to add as an instance.
	/// @return												A GraphNode referencing the added child.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphNode> AddChild(const Id& childId, const NodeSystem& base);

	//----------------------------------------------------------------------------------------
	/// Adds an instance of a node system as child of the root node to this graph. If #childId is empty, a
	/// UUID will be chosen as identifier of the child, otherwise #childId. In the latter
	/// case it is an error if this root node already has a child with that identifier.
	/// @param[in] childId						Identifier for the child node (if empty, a UUID is chosen).
	/// @param[in] templ							NodeTemplate of which an instantiation shall be added as an instance to the root node.
	/// @param[in] args								Template arguments for templ.
	/// @return												A GraphNode referencing the added child.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<GraphNode> AddChild(const Id& childId, const NodeTemplate& templ, const TemplateArguments& args = maxon::DefaultValue<const TemplateArguments&>());

	//----------------------------------------------------------------------------------------
	/// Replaces the given child node with an instance of a node system. This removes the original
	/// child, adds an instance of base as new child (with the same identifier), and finally
	/// tries to re-establish connections and attribute values of the original node at the new node.
	/// @param[in] childNode					The child node which shall be replaced.
	/// @param[in] base								Node system to use for the replacement.
	/// @param[in] portMap						An optional port mapping from old port paths to new port paths, see MutableRoot::ReplaceChild.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReplaceChild(const GraphNode& childNode, const NodeSystem& base, const HashMap<NodePath, NodePath>& portMap = GetZeroRef<HashMap<NodePath, NodePath>>());

	//----------------------------------------------------------------------------------------
	/// Groups the selection of nodes of this graph into a new group node.
	/// The new group node will be set up as an instance of base.
	///
	/// All selected nodes are moved to the group using their original
	/// identifiers, including inner connections. Afterwards the group is @ref MutableRoot::EndModification "finalized"
	/// and an instance of the group is added to this graph using the given groupId.
	/// Connections which leave the group are kept by adding ports to the group node
	/// as needed, and connecting them correspondingly. If the used group node already has ports,
	/// these will be used where identifiers match.
	/// @param[in] base								The base NodeSystem for the group. If null, an instantiation of the NODE::GROUP template is used.
	/// @param[in] groupId						Identifier for the new group within this node system (if empty, a UUID is chosen).
	/// @param[in] selection					A selection of nodes. Only nodes which are direct children of the root node of this view are considered.
	/// @return												A GraphNode referencing the added child.
	/// @see MutableRoot::MoveToGroup
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphNode> MoveToGroup(const NodeSystem& base, const Id& groupId, const Block<const GraphNode>& selection);

	//----------------------------------------------------------------------------------------
	/// Dissolves the given group into its children. This moves all children of group including their
	/// inner connections to the parent of group. External connections (from the group to other nodes)
	/// are moved to the inner nodes as well.
	/// @param[in] group							The group node to dissolve.
	/// @return												The mapping from original identifiers within the group to the new identifiers used at parent level.
	/// @see MutableNode::Ungroup
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashMap<InternedId, InternedId>> Ungroup(const GraphNode& group);

	//----------------------------------------------------------------------------------------
	/// Makes an asset for the given node and replaces the node by a reference to that asset.
	/// @param[in] node								The node which shall be made an asset.
	/// @param[in] repository					The asset repository where the node asset shall be stored.
	/// @param[in] assetId						The asset identifier to use. This must not be empty.
	/// @param[in] finalizer					This Delegate is called right before the asset is stored.
	/// 															This allows to do some finalization on the node system.
	/// @return												The AssetDescription for the new asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> MoveToAsset(const GraphNode& node, const AssetRepositoryRef& repository, const Id& assetId, const Delegate<Result<void>(const MutableRoot& rootNode)>& finalizer);

	//----------------------------------------------------------------------------------------
	/// Replaces the base node system of the given node with another one.
	/// @param[in] node								The node whose base shall be replaced,
	/// 															either the root node or a group node.
	/// @param[in] newBase						The new base node system to use for node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReplaceBase(const GraphNode& node, const NodeSystem& newBase);

	//----------------------------------------------------------------------------------------
	/// Yields the descriptions of all node template assets which are supported by this graph to receiver.
	/// @param[in] receiver						All supported assets are reported to this receiver.
	/// @return												False if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetSupportedAssets(const ValueReceiver<const AssetDescription&>& receiver);

	/// @private
	MAXON_METHOD Result<ForwardRef<UserStateDerivationRef>> CreateUserStateDerivation(const Block<const Id>& categories, Bool lazy);

	MAXON_METHOD const GNodeHandle& PrivateGetHandle(const GraphNode& node);

	MAXON_METHOD Result<GNode> PrivateToGNode(const GraphNode& node, NODE_KIND mask);

	MAXON_METHOD Result<MutableGNode> PrivateToMutableGNode(const GraphNode& node, NODE_KIND mask);

	//----------------------------------------------------------------------------------------
	/// Recursively finds all the node asset identifier and version of a node. The top level assets will be reported first.
	/// @param[in] node								The node for which we want all templates (NODE_KIND::NODE is mandatory).
	/// @param[in] receiver						ValueReceiver or Array that will collect all asset identifiers found.
	/// @return												False if ValueReceiver was by the #receiver before last asset was reached. True otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetAllAssetIds(const GraphNode& node, const ValueReceiver<const IdAndVersion&>& receiver);

protected:
	MAXON_METHOD Result<void> CopyToImpl(NodesGraphModelImpl& dst) const;

	//----------------------------------------------------------------------------------------
	/// Common init code used by Init method and CreateView method can be placed here.
	/// @note CreateView does not call Init.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrivateInit();

	//----------------------------------------------------------------------------------------
	/// Creates a view of the node system using the given class.
	/// @param[in] filter							The filter to use for the view.
	/// @param[in] rootPath						The path to the root node of the view. Use this if the view shall not
	///																represent the whole graph, but only a node and its inner parts.
	/// @param[in] graphModelClass		The class to use. Usually "self.GetClass()" is used internally to keep the same model implementation.
	/// @return												A GraphModelInterface reference, could be "this" if arguments yield no change.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodesGraphModelRef> CreateView(NodeSystemManagerInterface::FILTER filter, const NodePath& rootPath, const Class<>& graphModelClass);
};

#include "nodesgraph1.hxx"

//----------------------------------------------------------------------------------------
/// The default implementation of NodeSystemManagerInterface. This class has to be used as
/// base class for custom implementations.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeSystemManagerRef>, NodeSystemManagerClass, "net.maxon.node.class.nodesystemmanager");

//----------------------------------------------------------------------------------------
/// The default implementation of NodesGraphModelInterface. This class has to be used as
/// base class for custom implementations.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodesGraphModelRef>, NodesGraphModelClass, "net.maxon.node.class.nodesgraphmodel");

#include "nodesgraph2.hxx"


//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a Node. If node doesn't point to a valid true node, an IllegalArgumentError is returned.
/// @return												The node as a Node.
//----------------------------------------------------------------------------------------
inline Result<Node> ToNode(const GraphNode& node)
{
	Result<GNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToGNode(node, NODE_KIND::NODE);
	return std::move(reinterpret_cast<Result<Node>&>(res));
}

//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a PortList. If node doesn't point to a valid port list, an IllegalArgumentError is returned.
/// @return												The node as a PortList.
//----------------------------------------------------------------------------------------
inline Result<PortList> ToPortList(const GraphNode& node)
{
	Result<GNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToGNode(node, NODE_KIND::PORTLIST_MASK | NODE_KIND::PORT_MASK);
	return std::move(reinterpret_cast<Result<PortList>&>(res));
}

//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a Port. If node doesn't point to a valid port, an IllegalArgumentError is returned.
/// @return												The node as a Port.
//----------------------------------------------------------------------------------------
inline Result<Port> ToPort(const GraphNode& node)
{
	Result<GNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToGNode(node, NODE_KIND::PORT_MASK);
	return std::move(reinterpret_cast<Result<Port>&>(res));
}

//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a MutableNode. If node doesn't point to a valid true %node, an IllegalArgumentError is returned.
/// If there is no active graph transaction, an IllegalStateError is returned.
/// @return												The node as a MutableNode.
//----------------------------------------------------------------------------------------
inline Result<MutableNode> ToMutableNode(const GraphNode& node)
{
	Result<MutableGNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToMutableGNode(node, NODE_KIND::NODE);
	return std::move(reinterpret_cast<Result<MutableNode>&>(res));
}

//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a MutablePortList. If node doesn't point to a valid port list, an IllegalArgumentError is returned.
/// If there is no active graph transaction, an IllegalStateError is returned.
/// @return												The node as a MutablePortList.
//----------------------------------------------------------------------------------------
inline Result<MutablePortList> ToMutablePortList(const GraphNode& node)
{
	Result<MutableGNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToMutableGNode(node, NODE_KIND::PORTLIST_MASK | NODE_KIND::PORT_MASK);
	return std::move(reinterpret_cast<Result<MutablePortList>&>(res));
}

//----------------------------------------------------------------------------------------
/// Converts a GraphNode to a MutablePort. If node doesn't point to a valid port, an IllegalArgumentError is returned.
/// If there is no active graph transaction, an IllegalStateError is returned.
/// @return												The node as a MutablePort.
//----------------------------------------------------------------------------------------
inline Result<MutablePort> ToMutablePort(const GraphNode& node)
{
	Result<MutableGNode> res = Cast<NodesGraphModelRef>(node.GetGraph()).PrivateToMutableGNode(node, NODE_KIND::PORT_MASK);
	return std::move(reinterpret_cast<Result<MutablePort>&>(res));
}

//----------------------------------------------------------------------------------------
/// Checks if the given node has the node template asset as a base.
/// See NodeSystemInterface::HasBase().
/// @param[in] asset							The asset identifier of a node template.
/// @return												True if the node has an instantiation of the template given by asset
/// 															as a direct or indirect base, false otherwise.
//----------------------------------------------------------------------------------------
inline Bool HasBase(const GraphNode& node, const Id& asset)
{
	const NodeSystem& base = Cast<NodesGraphModelRef>(node.GetGraph()).GetBase(node);
	return base.HasBase(IdAndVersion(asset, Id()));
}

}

} // namespace maxon

#endif // NODESGRAPH_H__
