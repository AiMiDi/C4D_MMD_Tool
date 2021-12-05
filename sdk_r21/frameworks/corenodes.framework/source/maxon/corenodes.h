#ifndef CORENODES_H__
#define CORENODES_H__

#include "maxon/corenodes_instances.h"

namespace maxon
{

namespace corenodes
{

class CoreNode;
class CoreNodeGroupRef;

//----------------------------------------------------------------------------------------
/// A CoreNodeFactory creates a CoreNode given a set of arguments in a DataDictionary.
/// The supported arguments are specific for the core node, some common arguments
/// are defined in CoreNodeBaseInterface such as CoreNodeBaseInterface::Type.
//----------------------------------------------------------------------------------------
using CoreNodeFactory = Factory<CoreNode(const DataDictionary&)>;

struct OptimizationInfo;

//----------------------------------------------------------------------------------------
/// A CoreNode may have an optimizer to provide an optimized handling of the core node
/// given a set of values of its input ports which are known at compile-time.
///
/// At compile-time the optimizer is called with the node to optimize and the values
/// of all input ports as arguments, where an empty ConstDataPtr indicates an unknown
/// (dynamic) value. If an optimization is possible the necessary information is returned
/// in an OptimizationInfo.
///
/// To set an optimizer for a core node you have to set the CoreNodeInterface::Optimizer
/// attribute either directly on the core node (CoreNodeBaseInterface::SetValue)
/// or as meta data of the CoreNodeFactory. The latter can be done with the help of
/// MAXON_CORENODE_REGISTER_WITH_METADATA. Also if you use one of the MAXON_CORENODE_REGISTER
/// macros and the core node implementation class has a static Optimize function
/// @code
/// static Result<Opt<OptimizationInfo>> Optimize(const CoreNode& node, const Block<const Tuple<ConstDataPtr, PORT_FLAGS>>& args);
/// @endcode
/// this will be used automatically as optimizer.
///
/// There is the method CoreNodesLib::CreateOptimizer which returns an optimizer given
/// a number of ShortCircuitRules.
//----------------------------------------------------------------------------------------
using Optimizer = Delegate<Result<Opt<OptimizationInfo>>(const CoreNode& node, const Block<const Tuple<ConstDataPtr, PORT_FLAGS>>& args)>;


namespace details
{
struct SourceCodePortId;
}


//----------------------------------------------------------------------------------------
/// PortInfo stores information about a port, it is returned by CoreNodeBaseInterface::GetPortInfo().
//----------------------------------------------------------------------------------------
struct PortInfo
{
	/// The name of the port. Port names have to be unique per direction for a core node.
	Id name;

	/// The type of the port. This is usually a const type, only for state ports it is non-const.
	DataType type;

	mutable DataType accessType;

	/// The union of the wire types of all inner connections of the port.
	WIRETYPE wtypes = WIRETYPE::NONE;

	/// Additional flags for the port.
	MicroNode::FLAGS flags = MicroNode::FLAGS::NONE;

	//----------------------------------------------------------------------------------------
	/// Returns the access type of the port. For non-state ports, this is the decayed #type,
	/// otherwise it's the l-value-reference type of #type.
	/// @return												Access type of this port.
	//----------------------------------------------------------------------------------------
	const DataType& GetAccessType() const
	{
		if (!accessType && type)
		{
			accessType = (wtypes & WIRETYPE::STATE) ? ParametricTypes::LVReference().Instantiate(type) iferr_ignore("TODO") : type.GetDecayedType();
		}
		return accessType;
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* format) const
	{
		return name.ToString(format);
	}
};



//----------------------------------------------------------------------------------------
/// CoreNodeBaseInterface is the common base interface of @ref MicroNodeGroupRef "micro node groups",
/// @ref CoreNodeGroupRef "core node groups" and their finalized version CoreNode.
/// Each core node is either a group of other core nodes, or a group of micro nodes.
/// Thus at the lowest level we always have micro nodes.
///
/// This class diagram shows the relationships:
/// @graph
///                                                        +--CoreNodeBaseInterface-------------------+
///                                                        |------------------------------------------|
///                                                        |------------------------------------------|
///                                                        |+GetId(): Id                              |
///                        ,-----------------------------|>|+GetPortInfo(kind, index): PortInfo       |<|--------------------.
///                        |                               |+GetChild(index): CoreNodeInstanceBasePtr |                      |
///                        |                               +------------------------------------------+                      |
///                        |                                                     ^                 ^ "1"                     |
///                        |                                                     -                 *                         |
///                        |                                                     |                 v                         |
/// +--CoreNodeGroupInterface-------------------------------+    +-CoreNodeInterface------------+  |  +--MicroNodeGroupInterface----------------+
/// |-------------------------------------------------------|    |------------------------------|  |  |-----------------------------------------|
/// |-------------------------------------------------------|    |------------------------------|  |  |-----------------------------------------|
/// |+AddChild(name:Id, node:CoreNode): CoreNodeInstancePtr |    |                              |  |  |+AddChild<MN>(name:Id): MicroNodePtr<MN> |
/// |+Finalize(): CoreNode                                  |    +------------------------------+  |  |+Finalize(): CoreNode                    |
/// +-------------------------------------------------------+                                      |  +-----------------------------------------+
///       ^ "1"           ^ "1"                                                                    |                         ^ "1"
///       *               |                                                                        | "1..*                   *
///       v               | "base"                       +--CoreNodeInstanceBaseInterface----------------+                   v
///       |               |         .------------------|>|-----------------------------------------------|<|-----------.     |
///       |               |         |                    |-----------------------------------------------|             |     |
///       |               |         |                    |+GetName(): Id                                 |             |     |
///       |               |         |                    +-----------------------------------------------+             |     |
///       |               |         |                                                                                  |     |
///       | "1..*"        |         |                                                                                  |     | "1..*"
/// +--CoreNodeInstanceInterface------------------+                                                       +--MicroNodeInterface-----------------+
/// |---------------------------------------------|                                                       |-------------------------------------|
/// |---------------------------------------------|                                                       |-------------------------------------|
/// |+GetParentGroup(): CoreNodeGroupRef          |                                                       |+GetParentGroup(): MicroNodeGroupRef |
/// |+GetBase(): CoreNode                         |                                                       |+GetImplementation(): MicroNode      |
/// +---------------------------------------------+                                                       +-------------------------------------+
///                                                                                                                         | "1"
///                                                                                                                         |
///                                                                                                                         | "1"
///                                                                                                       +--MicroNode--------------------------+
///                                                                                                       |-------------------------------------|
///                                                                                                       |-------------------------------------|
///                                                                                                       |+GetNode(): MicroNodeInterface*      |
///                                                                                                       +-------------------------------------+
/// @endgraph
//----------------------------------------------------------------------------------------
class CoreNodeBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CoreNodeBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.corenode.interface.corenodebase");

	/// This defines the covariant return type of GetChild
	/// @private
	using Instance = CoreNodeInstanceBaseInterface;

public:
	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the core node.
	/// @return												Identifier of the core node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Sets the identifier of this core node. The identifier is used to derive names of
	/// instances of this node when they have no explicit name (such as "mynode.1" if the
	/// node has identifier "mynode").
	/// @param[in] name								The identifier of the core node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetId(const Id& name);

	//----------------------------------------------------------------------------------------
	/// Returns the factory which created this core node. When a core node has been created by
	/// a factory, an equivalent core node can be created by calling the factory again with
	/// the same @ref GetArguments "arguments".
	/// @return												Factory which created this core node, or nullptr if it hasn't been created by a factory.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CoreNodeFactory GetFactory() const;

	//----------------------------------------------------------------------------------------
	/// Returns the factory arguments which have been used to create this core node, see GetFactory().
	/// @return												Factory arguments for the creation of this core node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataDictionary& GetArguments() const;

	//----------------------------------------------------------------------------------------
	/// Sets the factory and factory arguments for this core node, see GetFactory().
	/// @param[in] factory						The core node factory which created this core node.
	/// @param[in] args								The factory arguments used for creation of this core node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InitFactory(const CoreNodeFactory& factory, const DataDictionary& args);

	//----------------------------------------------------------------------------------------
	/// Checks if this CoreNodeBaseInterface is a core node group or a micro node group.
	/// In the first case you can cast #this to a CoreNodeGroupInterface, otherwise to a
	/// MicroNodeGroupInterface.
	/// @return												True if #this is a core node group, false if it is a micro node group.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsCoreNodeGroup() const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of children of this group.
	/// @return												Number of children of this group.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChildCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the child of this group at the given index.
	/// @param[in] index							The child index between 0 and GetChildCount()-1.
	/// @return												Child node instance at the given index.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const typename Interface::Instance* GetChild(Int index) const;

	/// @copydoc GetChild
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	MAXON_FUNCTION typename Interface::Instance* GetChild(Int index)
	{
		return MAXON_NONCONST_COUNTERPART(GetChild(index));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the child of this group with the given name.
	/// @param[in] name								A name.
	/// @return												Child node instance having the given name, or a nullptr if no such child exists.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const typename Interface::Instance* FindChild(const Id& name) const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of ports of this group for the given direction.
	/// @param[in] direction					A port direction (PORT_DIR::INPUT for input ports, PORT_DIR::OUTPUT for output ports).
	/// @return												Number of ports for direction.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetPortCount(PORT_DIR direction) const;

	//----------------------------------------------------------------------------------------
	/// Finds the index of the port of this group which is identified by the given PortId port.
	/// @param[in] port								Identifier of the port.
	/// @return												Index of the identified port, or a negative number if no such port exists.
	/// @MAXON_ANNOTATION{default=-1}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindPortIndex(const PortId& port) const;

	//----------------------------------------------------------------------------------------
	/// Finds the index of the port of this group which is identified by the given PortId port.
	/// @param[in] port								Identifier of the port.
	/// @return												Index of the identified port, or an error if no such port exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> FindValidPortIndex(const PortId& port) const;

	//----------------------------------------------------------------------------------------
	/// Returns the PortInfo of the port of this group which is identified by the given PortId port.
	/// @param[in] port								Identifier of the port.
	/// @return												PortInfo of the identified port, or a null value if no such port exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const PortInfo& GetPortInfo(const PortId& port) const;

	//----------------------------------------------------------------------------------------
	/// Returns the PortInfo of the port of this group which is identified by the given PortId port.
	/// @param[in] port								Identifier of the port.
	/// @return												PortInfo of the identified port, or an error if no such port exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<const PortInfo&> GetValidPortInfo(const PortId& port) const;

	//----------------------------------------------------------------------------------------
	/// Adds a port to this group.
	/// @param[in] direction					The direction of the port (PORT_DIR::INPUT for inputs ports, PORT_DIR::OUTPUT for output ports).
	/// @param[in] name								Name of the port, this has to be unique among all ports of the same direction.
	/// @param[in] type								Type of the port. Usually this is a const type, only state ports have a non-const type.
	/// @return												PortInfo of the identified port, or an error if no such port exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> AddPort(PORT_DIR direction, const Id& name, const DataType& type);

	//----------------------------------------------------------------------------------------
	/// Adds a pass-through connection from an input port of this group to an output port of this group.
	/// Pass-through connections just pass their values on without changing or using them.
	/// @param[in] input							The input port for the pass-through.
	/// @param[in] output							The output port for the pass-through.
	/// @param[in] wires							The wires to use for the pass-through.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddPassThrough(const InPortId& input, const OutPortId& output, WIRETYPE wires);

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for this node. Values can be set on the node
	/// using SetValue, and they are also inherited from the @ref GetArguments "factory arguments"
	/// and from the @ref GetFactory "factory".
	/// If this node doesn't have a value for the attribute, an empty Data is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, or an empty Data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetValue(const InternedId& attr) const;

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute #ATTR for this node. Values can be set on the node
	/// using SetValue, and they are also inherited from the @ref GetArguments "factory arguments".
	/// If this node doesn't have a value for the attribute
	/// or the value doesn't have the expected type, an empty Opt is returned.
	/// @code
	/// Bool pure = node.GetValue<decltype(corenodes::CoreNodeInterface::Pure)>().GetValueOrNull() iferr_return;
	/// @endcode
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<Opt<typename ATTR::ValueType>> GetValue() const
	{
		iferr_scope;
		Data v = GetValue(ATTR::GetInstance()) iferr_return;
		const typename ATTR::ValueType* ptr = v.GetPtr<typename ATTR::ValueType>();
		if (!ptr)
			return {};
		typename ATTR::ValueType result = NewCopy(*ptr) iferr_return;
		return Opt<typename ATTR::ValueType>(std::move(result));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for this node.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetValue(const InternedId& attr, ForwardingDataPtr&& value);

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<void> SetValue(const typename ATTR::ValueType& value)
	{
		return SetValue(ATTR::GetInstance(), ConstDataPtr(value));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<void> SetValue(typename ATTR::ValueType&& value)
	{
		return SetValue(ATTR::GetInstance(), MoveDataPtr(std::move(value)));
	}

	//----------------------------------------------------------------------------------------
	/// This attribute should be set to true for a core node which implements a pure function.
	/// A pure function is a function where the return value is always the same for the same arguments
	/// and the evaluation has no side effects. Node compilers can take advantage
	/// of this by evaluating pure functions at compile-time.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_CLASS(Bool, Pure, "net.maxon.corenode.pure");

	//----------------------------------------------------------------------------------------
	/// This attribute provides an optimizer for a core node, see corenodes::Optimizer.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_CLASS(maxon::corenodes::Optimizer, Optimizer, "net.maxon.corenode.optimizer");

	MAXON_ATTRIBUTE_CLASS(Id, NodeId, "net.maxon.corenode.nodeid");

	MAXON_ATTRIBUTE_CLASS(Data, Value, "net.maxon.corenode.value");

	MAXON_ATTRIBUTE_CLASS(DataType, Type, "net.maxon.corenode.type");

	MAXON_ATTRIBUTE_CLASS(DataType, SourceType, "net.maxon.corenode.sourcetype");

	MAXON_ATTRIBUTE_CLASS(BaseArray<Member>, Members, "net.maxon.corenode.members");

	MAXON_ATTRIBUTE_CLASS(Int, Count, "net.maxon.corenode.count");

	MAXON_ATTRIBUTE_CLASS(CONVERSION_FLAGS, ConversionFlags, "net.maxon.corenode.conversionflags");

	MAXON_ATTRIBUTE_CLASS(String, Message, "net.maxon.corenode.message");

	/// @copydoc DefaultDoc::ToString
	MAXON_FUNCTION String ToString(const FormatStatement* fmt) const { return GetId().ToString(fmt); }
};


//----------------------------------------------------------------------------------------
/// CoreNodeInterface represents a micro node group or core node group in a finalized state.
/// You have to set those groups into finalized state by calling
/// MicroNodeGroupRef::Finalize() or CoreNodeGroupRef::Finalize() after you
/// have finished the setup of those groups. These methods return the group as a CoreNode.
/// A CoreNode can't be modified, therefore it uses a const reference class.
//----------------------------------------------------------------------------------------
class CoreNodeInterface : public CoreNodeBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(CoreNodeInterface, MAXON_REFERENCE_CONST, "net.maxon.corenode.interface.corenode");
public:
	//----------------------------------------------------------------------------------------
	/// Invokes the core node directly (as opposed to the invocation from within a compiled
	/// core node graph). This is only supported for a limited set of core nodes.
	/// The main purpose is to assist the nodes compiler in constant propagation at compile-time.
	/// @param[in] args								The arguments: At first the values for input ports,
	/// 															afterwards storage locations where output ports write their results.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Invoke(const Block<const Tuple<ConstDataPtr, PORT_FLAGS>>& args) const;

	//----------------------------------------------------------------------------------------
	/// This enum contains options for the GML output written by WriteGml.
	//----------------------------------------------------------------------------------------
	enum class GML_OPTIONS
	{
		NONE = 0,							///< No flags.
		DEEP = 1,							///< Write groups deeply, so the complete graph is written up to the micro node level.
		PORTS = 2,						///< Include ports.
		NANO_EMBEDDED = 4,		///< Write nano nodes embedded in their micro nodes.
		NANO = 8,							///< Write the nano graph instead of the core node graph.
		BLOCK = 16,						///< Write the compiled block graph instead of the core node graph.
		HIDDEN_PORTS = 32,		///< Include hidden ports.
		VERBOSE = 64					///< Verbose output with a lot of information.
	} MAXON_ENUM_FLAGS_CLASS(GML_OPTIONS);

	//----------------------------------------------------------------------------------------
	/// Writes this core node to a GML file (graph modelling language). This can be used to
	/// visualize the core node with a graph viewer application such as yEd.
	/// @param[in] output							The location to write to.
	/// @param[in] options						Options for the GML output.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteGml(UrlOrOutputStream&& output, GML_OPTIONS options) const;
};


//----------------------------------------------------------------------------------------
/// MicroNodeGroupInterface is a group of micro nodes. A micro node group is the most fundamental
/// core node. In the usual case a group consists of just one micro node, then you set up
/// a micro node group with the following pattern:
/// @code{corenodes_micronodegroup_basic}
//! // This class defines a micro node group which adds two Int values.
//! class MyAddNode
//! {
//! public:
//! 	// Declaration of the input and output ports of the micro node group.
//! 	MAXON_PORT_INPUT(Int, in1);
//! 	MAXON_PORT_INPUT(Int, in2);
//! 	MAXON_PORT_OUTPUT(Int, out);
//! 
//! 	// Implementation of the single custom micro node.
//! 	class Impl : public BasicMicroNode
//! 	{
//! 	public:
//! 		// The Process method needs to specify which ports of the group the micro node accesses, in this case all ports.
//! 		// If the group contains more than one micro node, each micro node usually needs only a subset of the ports.
//! 		Result<void> Process(const Ports<in1, in2, out>& ports) const
//! 		{
//! 			ports.out.Update(ports.in1() + ports.in2());
//! 			return OK;
//! 		}
//!  	};
//! 
//! 	// The Init function will be called to set up the micro node group
//! 	// when you call CreateNode<MyAddNode>() or as part of the MAXON_CORENODE_REGISTER macro.
//! 	static Result<void> Init(const MicroNodeGroupRef& group)
//! 	{
//! 		iferr_scope;
//! 		group.AddChild<Impl>() iferr_return;
//! 		return OK;
//! 	}
//! };
/// @endcode
/// The Init function can have additional parameters:
/// - When called from one of the MAXON_CORENODE_REGISTER macros there may be one additional
///   parameter of type @c{const DataDictionary&}. It receives the factory arguments which are passed
///   to the Create method of the CoreNodeFactory registered by the macro. These arguments
///   contain information such as the number of variadic ports to create,
///		see MicroNodeInterface::AddVariadicPort.
/// - When called from CreateNode an arbitrary number of extra arguments can be passed from
///   the call to CreateNode to the call to Init.
//----------------------------------------------------------------------------------------
class MicroNodeGroupInterface : public CoreNodeBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(MicroNodeGroupInterface, MAXON_REFERENCE_NORMAL, "net.maxon.corenode.interface.micronodegroup");

public:
	/// This defines the covariant return type of GetChild
	/// @private
	using Instance = MicroNodeInterface;

	//----------------------------------------------------------------------------------------
	/// Creates a new, empty micro node group.
	/// @return												A new micro node group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD MicroNodeGroupInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Adds a micro node of class MN to this group using the given name. The created micro node
	/// is owned by this group.
	/// @tparam MN										The micro node class to instantiate.
	/// @param[in] name								The name for the child. Names have to be unique within a group.
	/// 															If an empty name is passed a unique name will be chosen.
	/// @param[in] args								Additional arguments, these are forwarded to the constructor of MN.
	/// @return												A pointer to the micro node instance. The instance is owned
	/// 															by this group.
	//----------------------------------------------------------------------------------------
	template <typename MN, typename... ARGS> MAXON_FUNCTION Result<MicroNodePtr<MN>> AddChild(const Id& name, ARGS&&... args)
	{
		iferr_scope;
		MN* microNode = NewObj(MN, std::forward<ARGS>(args)...) iferr_return;
		microNode->template PrivateInit<MN>();
		return GenericReinterpretCast<Result<MicroNodePtr<MN>>>(AddMicroNode(name, microNode));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a micro node of class MN to this group. The created micro node
	/// is owned by this group. A unique name is chosen automatically.
	/// @tparam MN										The micro node class to instantiate.
	/// @return												A pointer to the micro node instance. The instance is owned
	/// 															by this group.
	//----------------------------------------------------------------------------------------
	template <typename MN> MAXON_FUNCTION Result<MicroNodePtr<MN>> AddChild()
	{
		iferr_scope;
		MN* microNode = NewObj(MN) iferr_return;
		microNode->template PrivateInit<MN>();
		return GenericReinterpretCast<Result<MicroNodePtr<MN>>>(AddMicroNode(Id::NullValue(), microNode));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the port id (either InPortId or OutPortId) of the given port. port has to be
	/// one of the ports defined by a MAXON_PORT macro, followed by a pair of parentheses
	/// as in @c{group.GetPort(in())}.
	/// For indexed ports you have to specify the index within the parentheses:
	/// @code{corenodes_getport}
	//! class MyNode
	//! {
	//! public:
	//! 	MAXON_PORT_INPUT(Int, index);
	//! 	MAXON_PORT_INPUT_INDEXED(Float, numbers, 5);
	//! 	MAXON_PORT_OUTPUT(Float, result);
	//! 
	//!  	static Result<void> Init(const MicroNodeGroupRef& group)
	//!  	{
	//! 		iferr_scope;
	//! 		InPortId indexPort = group.GetPort(index()) iferr_return;
	//! 		for (Int i = 0; i < 5; ++i)
	//! 		{
	//! 			// Indexed port numbers needs port index within parentheses.
	//! 			InPortId numberPort = group.GetPort(numbers(i)) iferr_return;
	//! 		}
	//! 		OutPortId resultPort = group.GetPort(result()) iferr_return;
	//! 		return OK;
	//! 	}
	//! };
	/// @endcode
	/// @param[in] port								One of the ports declared by a MAXON_PORT macro (a parentheses pair,
	/// 															possibly including indices, is needed after the name, see example).
	/// @return												The InPortId or OutPortId of the port.
	//----------------------------------------------------------------------------------------
	template <typename PORT> MAXON_FUNCTION Result<typename PORT::PortIdType> GetPort(const PORT& port)
	{
		return PrivateGetPort<typename PORT::PortIdType>(port.GetSourceCodePortId(), PORT::GetId(), GetPortType<typename PORT::PortDeclarationType>(), WIRETYPE::NONE);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the micro node which represents the given output port of this group.
	/// port has to be one of the ports defined by a MAXON_PORT_OUTPUT macro followed by a pair of parentheses,
	/// see GetPort() for more details.
	///
	/// This function can only be used for output ports because input ports aren't represented by micro nodes.
	///
	/// @param[in] port								One of the output ports of this group declared by a MAXON_PORT_OUTPUT macro.
	/// 															A parentheses pair, possibly including indices, is needed after the name, see GetPort().
	/// @return												The micro node of the output port.
	//----------------------------------------------------------------------------------------
	template <typename OUTPORT> MAXON_FUNCTION Result<MicroNodePtr<typename OUTPORT::PortClass::MicroNodeClass>> GetPortMicroNode(const OUTPORT& port)
	{
		return GenericReinterpretCast<Result<MicroNodePtr<typename OUTPORT::PortClass::MicroNodeClass>>>(PrivateGetMicroNode(port.GetSourceCodePortId(), OUTPORT::GetId(), GetPortType<const Generic>(), OUTPORT::MicroNodeClass::MICRONODE_TYPE, OUTPORT::MICRONODE_FLAGS));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the data type of the given port of this group. 
	/// port has to be one of the ports defined by a MAXON_PORT macro followed by a pair of parentheses,
	/// see GetPort() for more details.
	///
	/// @param[in] port								One of the ports of this group declared by a MAXON_PORT macro.
	/// 															A parentheses pair, possibly including indices, is needed after the name, see GetPort().
	/// @param[in] type								The data type to set for port.
	//----------------------------------------------------------------------------------------
	template <typename PORT> MAXON_FUNCTION Result<void> SetDataType(const PORT& port, const DataType& type)
	{
		return PrivateGetPort<typename PORT::PortIdType>(port.GetSourceCodePortId(), PORT::GetId(), type, WIRETYPE::NONE);
	}

	template <typename PORT> MAXON_FUNCTION Result<void> AddWires(const PORT& port, WIRETYPE wires)
	{
		return PrivateGetPort<typename PORT::PortIdType>(port.GetSourceCodePortId(), PORT::GetId(), GetPortType<const Generic>(), wires);
	}

	MAXON_ADD_TO_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Finalizes this group and returns the group as a finalized CoreNode. Afterwards the
	/// group can't be modified any longer. You have to call this on a group before the group
	/// shall be added to another group, because only finalized groups can be added.
	///
	/// @return												This group as a finalized CoreNode.
	//----------------------------------------------------------------------------------------
	Result<CoreNode> Finalize()
	{
		if (!this->GetPointer())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		Result<CoreNode> result = this->GetPointer()->PrivateFinalize();
		if (result == OK)
			this->ResetPointer();
		return result;
	}
	);

	MAXON_METHOD Result<CoreNode> PrivateFinalize();

	template <typename PORTID> Result<PORTID> PrivateGetPort(const corenodes::details::SourceCodePortId& pid, const Id& name, const DataType& vtype, WIRETYPE wtypes)
	{
		iferr_scope;
		Int i = PrivateGetPort(pid, PORTID(name), vtype, wtypes) iferr_return;
		return PORTID(i);
	}

	struct PrivateAutoCreatePortInfo
	{
		MicroNodeGroupInterface* group;
		Result<void> result;

		void CreatePort(Int pid, const Id& name, MicroNode::TYPE type, MicroNode::FLAGS flags, const DataType& vtype, Int count)
		{
			if (result == FAILED)
				return;
			result = group->PrivateCreatePort(pid, name, type, flags, vtype, count);
		}
	};

	template <typename NODECLASS> Result<void> PrivateAutoCreatePorts()
	{
		const Bool EMPTY = std::is_empty<NODECLASS>::value;
		if (EMPTY)
		{
			return OK;
		}
		else
		{
			typename std::aligned_union1<0, NODECLASS>::type mem;
			static_assert(EMPTY || ((SIZEOF(mem) % SIZEOF(void*)) == 0), "Size of node class not a multiple of pointer size.");
			PrivateAutoCreatePortInfo result;
			result.group = this;
			for (Int i = 0; i < SIZEOF(mem) / SIZEOF(void*); ++i)
			{
				((PrivateAutoCreatePortInfo**) &mem)[i] = &result;
			}
			using NODECLASSNonEmpty = typename std::conditional<EMPTY, Pointer<Char>, NODECLASS>::type; // just to prevent "unused variable" warning in the EMPTY case
			NODECLASSNonEmpty cls(reinterpret_cast<const NODECLASSNonEmpty&>(mem));
			return std::move(result.result);
		}
	}

	MAXON_METHOD Result<MicroNodePtr<>> PrivateCreatePort(Int pid, const Id& name, MicroNode::TYPE type, MicroNode::FLAGS flags, const DataType& vtype, Int count);

	MAXON_METHOD Result<Int> PrivateGetPort(const corenodes::details::SourceCodePortId& declId, const PortId& pid, const DataType& vtype, WIRETYPE wtypes);

	MAXON_METHOD Result<OutPortId> PrivateAddParameter(MicroNodeInterface* paramRoot, Int pid, const DataType& type, const Id& name, MicroNode::TYPE portType, MicroNode::FLAGS flags, const ConstDataPtr& constant, MicroNodeInterface*& portOut);

	static MAXON_METHOD void PrivateDescribePortAccess(PortsDescription* desc, ACCESS_INDEX index, Int counter, Bool ref);

	static MAXON_METHOD void PrivateBeginLazy(PortsDescription* desc);

	static MAXON_METHOD void PrivateEndLazy(PortsDescription* desc);

private:
	MAXON_METHOD Result<MicroNodePtr<>> AddMicroNode(const Id& name, MicroNode* child);

	MAXON_METHOD Result<MicroNodePtr<>> PrivateGetMicroNode(const corenodes::details::SourceCodePortId& pid, const Id& name, const DataType& vtype, MicroNode::TYPE ptype, MicroNode::FLAGS flags);
};



//----------------------------------------------------------------------------------------
/// CoreNodeGroupInterface is a group of core nodes.
//----------------------------------------------------------------------------------------
class CoreNodeGroupInterface : public CoreNodeBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(CoreNodeGroupInterface, MAXON_REFERENCE_NORMAL, "net.maxon.corenode.interface.corenodegroup");

public:
	/// This defines the covariant return type of GetChild
	/// @private
	using Instance = CoreNodeInstanceInterface;

	//----------------------------------------------------------------------------------------
	/// Creates a new, empty core node group.
	/// @return												A new core node group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CoreNodeGroupInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Adds a core node as an instance to this group using the given name.
	///
	/// The created instance is owned by this group.
	///
	/// @param[in] name								The name for the child. Names have to be unique within a group.
	/// 															If an empty name is passed a unique name will be chosen.
	/// @param[in] node								The core node to add.
	/// @return												A pointer to the core node instance. The instance is owned
	/// 															by this group.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CoreNodeInstancePtr> AddChild(const Id& name, const CoreNode& node);

	/// @copydoc AddChild
	MAXON_FUNCTION Result<CoreNodeInstancePtr> AddChild(const Id& name, Result<CoreNode>&& node);

	//----------------------------------------------------------------------------------------
	/// Adds a core node as an instance to this group using the given name. nodeId specifies
	/// a CoreNodeFactory in the CoreNodes registry, this factory is used, together with the
	/// given factory arguments, to create the core node to add.
	///
	/// The created instance is owned by this group.
	///
	/// @param[in] name								The name for the child. Names have to be unique within a group.
	/// 															If an empty name is passed a unique name will be chosen.
	/// @param[in] nodeId							The identifier of the core node factory to use.
	/// @param[in] args								The factory arguments.
	/// @return												A pointer to the core node instance. The instance is owned
	/// 															by this group.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<CoreNodeInstancePtr> AddChild(const Id& name, IdOrBuilder&& nodeId, const DataDictionary& args = GetZeroRef<DataDictionary>());

	/// @copydoc AddChild(Id, IdOrBuilder, DataDictionary)
	MAXON_FUNCTION Result<CoreNodeInstancePtr> AddChild(const Id& name, IdOrBuilder&& nodeId, Result<DataDictionary>&& args);

	//----------------------------------------------------------------------------------------
	/// Adds a core node as an instance to this group using the given name. nodeId specifies
	/// a CoreNodeFactory in the CoreNodes registry. This factory is used, together with the
	/// factory arguments, to create the core node to add. The factory arguments are made up
	/// of the given args and an additional mapping of CoreNodeBaseInterface::Type to TYPE.
	///
	/// The created instance is owned by this group.
	///
	/// @tparam TYPE									The data type to use for the CoreNodeBaseInterface::Type parameter
	/// 															in the factory arguments.
	/// @param[in] name								The name for the child. Names have to be unique within a group.
	/// 															If an empty name is passed a unique name will be chosen.
	/// @param[in] nodeId							The identifier of the core node factory to use.
	/// @param[in] args								The factory arguments.
	/// @return												A pointer to the core node instance. The instance is owned
	/// 															by this group.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> MAXON_FUNCTION Result<CoreNodeInstancePtr> AddChild(const Id& name, IdOrBuilder&& nodeId, DataDictionary args = DataDictionary())
	{
		return AddChild(name, std::move(nodeId), args.Set(CoreNodeBaseInterface::Type, GetPortType<TYPE>()));
	}

	MAXON_ADD_TO_REFERENCE_CLASS(
	/// @copydoc MicroNodeGroupRef::Finalize
	Result<CoreNode> Finalize()
	{
		if (!this->GetPointer())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		Result<CoreNode> result = this->GetPointer()->PrivateFinalize();
		if (result == OK)
			this->ResetPointer();
		return result;
	}
	);

	MAXON_METHOD Result<CoreNode> PrivateFinalize();

	template <typename NODECLASS> ResultOk<void> PrivateAutoCreatePorts()
	{
		return OK;
	}
};


#include "corenodes1.hxx"

#include "corenodes2.hxx"

namespace details
{

template <typename N, typename... ARGS> inline Result<typename std::decay<typename GetSignature<decltype(&N::Init)>::Parameters::template At<0>::type>::type> CreateNode(const Id& nodeId, ARGS&&... args)
{
	iferr_scope;
	using Ref = typename std::decay<typename GetSignature<decltype(&N::Init)>::Parameters::template At<0>::type>::type;
	Ref n = NewObj(typename Ref::ReferencedType) iferr_return;
	if (nodeId.IsPopulated())
		n.SetId(nodeId);
	n.GetPointer()->template PrivateAutoCreatePorts<N>() iferr_return;
	N::Init(n, std::forward<ARGS>(args)...) iferr_return;
	return std::move(n);
}

}


//----------------------------------------------------------------------------------------
/// Creates a core node from class N. The class N has to contain an Init function where the first
/// parameter is either a MicroNodeGroupRef or a CoreNodeGroupRef and the remaining parameters
/// (if any) have to match the given args. For an example of such a class have a look at MicroNodeGroupInterface.
///
/// @tparam N											The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as first parameter.
/// @param[in] nodeId							The identifier to use for the node. This may be left empty.
/// @param[in] args								Optional arguments for the Init function.
/// @return												The created, finalized node.
//----------------------------------------------------------------------------------------
template <typename N, typename... ARGS> inline Result<CoreNode> CreateNode(const Id& nodeId, ARGS&&... args)
{
	iferr_scope;
	auto n = maxon::corenodes::details::CreateNode<N>(nodeId, std::forward<ARGS>(args)...) iferr_return;
	return n.Finalize();
}

//----------------------------------------------------------------------------------------
/// Creates a core node from class N. The class N has to contain an Init function which takes
/// a single parameter of type MicroNodeGroupRef or CoreNodeGroupRef. For an example of such a class
/// have a look at MicroNodeGroupInterface.
/// To create a node with additional arguments see the other CreateNode function.
///
/// @tparam N											The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as parameter.
/// @return												The created, finalized node.
//----------------------------------------------------------------------------------------
template <typename N> inline Result<CoreNode> CreateNode()
{
	return CreateNode<N>(Id::NullValue());
}



namespace details
{

template <Bool SINGLE_PARAM> struct CoreNodeFactoryFunctionHelper
{
	template <typename N> static Result<CoreNode> Create(FactoryInterface::ConstPtr factory, const DataDictionary& args)
	{
		iferr_scope;
		Id name = factory.Get(CoreNodeInterface::NodeId, Id());
		auto n = maxon::corenodes::details::CreateNode<N>(name, args) iferr_return;
		n.InitFactory(factory, args);
		return n.Finalize();
	}
};

template <> struct CoreNodeFactoryFunctionHelper<true>
{
	template <typename N> static Result<CoreNode> Create(FactoryInterface::ConstPtr factory, const DataDictionary&)
	{
		iferr_scope;
		Id name = factory.Get(CoreNodeInterface::NodeId, Id());
		auto n = maxon::corenodes::details::CreateNode<N>(name) iferr_return;
		n.InitFactory(factory, GetZeroRef<DataDictionary>());
		return n.Finalize();
	}
};

MAXON_MEMBERFUNCTION_DETECTOR(Optimize);

template <typename NODE, typename = typename std::enable_if<maxon::corenodes::details::HasOptimize<NODE>::value>::type> inline Result<void> AddOptimizer(DataDictionary& meta, Bool dummy = false)
{
	return meta.Set(CoreNodeInterface::Optimizer, &NODE::Optimize);
}

template <typename NODE, typename = typename std::enable_if<!maxon::corenodes::details::HasOptimize<NODE>::value>::type> inline ResultOk<void> AddOptimizer(DataDictionary& meta)
{
	return OK;
}

template <typename CORENODE, typename = void> struct SetParameters
{
	static ResultOk<void> Set(DataDictionary& dict)
	{
		return OK;
	}
};

template <typename CORENODE> struct SetParameters<CORENODE, typename SFINAEHelper<void, typename CORENODE::Parameters>::type>
{
	static Result<void> Set(DataDictionary& dict)
	{
		return SetImpl(dict, (typename CORENODE::Parameters*) nullptr);
	}

	template <typename... P> static Result<void> SetImpl(DataDictionary& dict, ParameterPack<P...>*)
	{
		DataDictionary params;
		ThreadReferencedError err{};
		ForEach{(MAXON_LIKELY(err.GetReferencedError() == nullptr) && (params.Set(P::GetInstance().Get(), GetDataType<typename P::ValueType>()) % err, false))...};
		if (err.GetReferencedError())
			return err;
		return dict.Set(FactoryInterface::Parameters, std::move(params));
	}
};

}


//----------------------------------------------------------------------------------------
/// The registry for @ref CoreNodeFactory "core node factories". You can use one of the
/// MAXON_CORENODE_REGISTER macros to register a core node factory.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(CoreNodeFactory, CoreNodes, "net.maxon.corenode.registry.corenodes");


#define PRIVATE_MAXON_REGISTER_CORE_NODE_A(name, cls, initMetadata, line, ...) \
	MAXON_DECLARATION_REGISTER(maxon::corenodes::CoreNodes, ) \
	{ \
		iferr_scope; \
		if (MAXON_VA_NARGS(__VA_ARGS__) > 1) \
		{ \
			maxon::corenodes::IdBuilder mangledName = maxon::corenodes::IdBuilder(name).Append MAXON_EXPAND(MAXON_ARG16(, ##__VA_ARGS__, <, <, <, <, <, <, <, <, <, <, <, <, <, )) MAXON_EXPAND(MAXON_ALLBUTFIRST(__VA_ARGS__)) MAXON_EXPAND(MAXON_ARG16(, ##__VA_ARGS__, >, >, >, >, >, >, >, >, >, >, >, >, >, )) (); \
			iferr (objectId = mangledName.ToId()) return err; \
		} \
		else \
		{ \
			objectId = maxon::Id(name); \
		} \
		using NodeCls = cls MAXON_EXPAND(MAXON_ARG16(, ##__VA_ARGS__, <, <, <, <, <, <, <, <, <, <, <, <, <, )) MAXON_EXPAND(MAXON_ALLBUTFIRST(__VA_ARGS__)) MAXON_EXPAND(MAXON_ARG16(, ##__VA_ARGS__, >, >, >, >, >, >, >, >, >, >, >, >, >, )); \
		maxon::DataDictionary meta; \
		maxon::corenodes::details::SetParameters<NodeCls>::Set(meta) iferr_return; \
		using ValueType = typename maxon::GetValueType<NodeCls>::type; \
		if (!std::is_same<ValueType, void>::value) \
		{ \
			meta.Set(maxon::corenodes::CoreNodeInterface::Type, maxon::corenodes::GetPortType<ValueType>()) iferr_return; \
		} \
		meta.Set(maxon::corenodes::CoreNodeInterface::NodeId, objectId) iferr_return; \
		initMetadata \
		maxon::corenodes::details::AddOptimizer<NodeCls>(meta) iferr_return; \
		return maxon::FactoryFactory::CreateCached<maxon::corenodes::CoreNode>(&maxon::corenodes::details::CoreNodeFactoryFunctionHelper<maxon::GetSignature<decltype(&NodeCls::Init)>::Parameters::COUNT == 1>::Create<NodeCls>, 100, meta); \
	}

#define PRIVATE_MAXON_REGISTER_CORE_NODE(name, cls, meta, line, ...) PRIVATE_MAXON_REGISTER_CORE_NODE_A(name, cls, meta, line, 0, ##__VA_ARGS__)


//----------------------------------------------------------------------------------------
/// Registers the given core node implementation class #CLS at the CoreNodes registry.
/// The class has to contain an Init function with one or two parameters where the first
/// parameter is either a MicroNodeGroupRef or a CoreNodeGroupRef and the optional second one
/// is a DataDictionary which receives the parameters given to the factory's Create method.
/// For an example of such a class have a look at MicroNodeGroupInterface.
///
/// @param[in] CLS								The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as first parameter.
///																If CLS is a class template, you have to specify the template arguments in ...
/// @param[in] id									The identifier to use for the registry entry.
/// @param[in] ...								Optional template arguments if CLS is a class template. The identifier
///																will be extended by the arguments, see IdBuilder.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_REGISTER(CLS, id, ...) PRIVATE_MAXON_REGISTER_CORE_NODE(id, CLS, , __LINE__, ##__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Registers the given core node implementation class #CLS at the CoreNodes registry.
/// The class has to contain an Init function with one or two parameters where the first
/// parameter is either a MicroNodeGroupRef or a CoreNodeGroupRef and the optional second one
/// is a DataDictionary which receives the parameters given to the factory's Create method.
/// For an example of such a class have a look at MicroNodeGroupInterface.
///
/// @param[in] CLS								The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as first parameter.
///																If CLS is a class template, you have to specify the template arguments in ...
/// @param[in] id									The identifier to use for the registry entry.
/// @param[in] META								Additional code to set up meta data for the core node. Within the code
///																you have access to the variable #meta of type DataDictionary which
///																is used to setup the factory's meta data. The meta data can be accessed later
///																through the factory's base interface DataDictionaryObjectInterface.
/// @param[in] ...								Optional template arguments if CLS is a class template. The identifier
///																will be extended by the arguments, see IdBuilder.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_REGISTER_WITH_METADATA(CLS, id, META, ...) PRIVATE_MAXON_REGISTER_CORE_NODE(id, CLS, META, __LINE__, ##__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Registers the given core node implementation class #CLS at the CoreNodes registry,
/// see MAXON_CORENODE_REGISTER. This macro should be used for core nodes which implement
/// a pure function, it sets the CoreNodeInterface::Pure attribute of the factory to true.
///
/// @param[in] CLS								The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as first parameter.
///																If CLS is a class template, you have to specify the template arguments in ...
/// @param[in] id									The identifier to use for the registry entry.
/// @param[in] ...								Optional template arguments if CLS is a class template. The identifier
///																will be extended by the arguments, see IdBuilder.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_REGISTER_PURE(CLS, id, ...) MAXON_CORENODE_REGISTER_PURE_WITH_METADATA(CLS, id, , ##__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Registers the given core node implementation class #CLS at the CoreNodes registry,
/// see MAXON_CORENODE_REGISTER_WITH_METADATA. This macro should be used for core nodes which implement
/// a pure function, it sets the CoreNodeInterface::Pure attribute of the factory to true.
///
/// @param[in] CLS								The class which implements the node. It has to contain an Init function
/// 															with either a MicroNodeGroupRef or a CoreNodeGroupRef as first parameter.
///																If CLS is a class template, you have to specify the template arguments in ...
/// @param[in] id									The identifier to use for the registry entry.
/// @param[in] META								Additional code to set up meta data for the core node. Within the code
///																you have access to the variable #meta of type DataDictionary which
///																is used to setup the factory's meta data. The meta data can be accessed later
///																through the factory's base interface DataDictionaryObjectInterface.
/// @param[in] ...								Optional template arguments if CLS is a class template. The identifier
///																will be extended by the arguments, see IdBuilder.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_REGISTER_PURE_WITH_METADATA(CLS, id, META, ...) MAXON_CORENODE_REGISTER_WITH_METADATA(CLS, id, meta.Set(CoreNodeInterface::Pure, true) iferr_return; META, ##__VA_ARGS__)

}

} // namespace maxon

#endif // CORENODES_H__
