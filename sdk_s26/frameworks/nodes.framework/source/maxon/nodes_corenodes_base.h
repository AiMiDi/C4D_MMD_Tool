#ifndef NODES_CORENODES_BASE_H__
#define NODES_CORENODES_BASE_H__

#include "maxon/nodesystem_class.h"

namespace maxon::nodes
{

//----------------------------------------------------------------------------------------
/// This is the base class of node systems which are aware of core nodes. You can inherit
/// from this class to implement your own node space which shall use core nodes
/// to do constant evaluation during validation.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, BaseCoreNodesNodeSystemClass, "net.maxon.corenode.basenodesystemclass");

//----------------------------------------------------------------------------------------
/// This is the base class of true core-node-based node systems. While BaseCoreNodesNodeSystemClass
/// uses core nodes only to do constant evaluation, a node system based on CoreNodesNodeSystemClass
/// can be compiled into a core node system.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, CoreNodesNodeSystemClass, "net.maxon.corenode.nodesystemclass");

//----------------------------------------------------------------------------------------
/// This factory can be used to create a DescriptionProcessor which builds core-node-based
/// nodes from descriptions. The method NodeTemplateInterface::SupportsImpl of the built
/// node template is implemented by the delegate passed to the factory, so you can easily
/// set up a filter which enables the node only for a specific node system class:
/// @code{nodes_corenodesdescriptionprocessor}
//! MAXON_DECLARATION_REGISTER(maxon::DescriptionProcessors, "net.maxonsdk.nodespace.corenodedescriptionprocessor")
//! {
//! 	return maxon::nodes::CoreNodesDescriptionProcessor().Create(
//! 		[] (const maxon::nodes::NodeSystemClass& cls) -> maxon::Result<maxon::Bool>
//! 		{
//! 			return cls.GetClass() == NodeSystemClassExample::GetClass();
//! 		});
//! }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Factory<DescriptionProcessor(Delegate<Result<Bool>(const NodeSystemClass& cls)>&& support)>, CoreNodesDescriptionProcessor, "net.maxon.corenode.factory.descriptionprocessor");

using ConstantOptimizer = Delegate<Result<Data>(const ConstDataPtr& value)>;

MAXON_REGISTRY(ConstantOptimizer, ConstantOptimizers, "net.maxon.nodes.registry.constantoptimizers");

MAXON_ATTRIBUTE(Bool, FunctionResult, "functionresult");


//----------------------------------------------------------------------------------------
/// This attribute can be set at a root node to skip the cleanup during NodeSystemClassFinalizeModification.
/// The usual cleanup made by BaseCoreNodesNodeSystemClass and its subclasses contains
/// the removal of unconnected propagated ports and of description entries which belong to
/// no longer existing ports.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, NoCleanupOnFinalize, "skipfinalizemodification");

}

#endif // NODES_CORENODES_BASE_H__
