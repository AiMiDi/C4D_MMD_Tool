#ifndef CORENODES_INSTANCES_H__
#define CORENODES_INSTANCES_H__

#include "maxon/url.h"
#include "maxon/corenodes_helpers.h"

namespace maxon
{

namespace corenodes
{

class MicroNodeInterface;

class PortsDescription;
using PortsDescriptionCallback = void(*)(PortsDescription*);

template <typename T> inline const DataType& GetPortType()
{
	static_assert(!std::is_reference<T>::value, "Wrong template argument.");
	return GetDataType<T, Or<GET_DATATYPE_POLICY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY, GET_DATATYPE_POLICY::NO_DECAY>::value>();
}

using LlvmGlobalsReceiver = Delegate<Result<void>(const CString& name, const CString& decl, void* address)>;

//----------------------------------------------------------------------------------------
/// MicroNode is the base class of all micro node implementation classes such as BasicMicroNode
/// or BatchMicroNode. To implement a new custom micro node, you usually write a subclass of BasicMicroNode.
///
/// There is a 1:1 correspondence between a MicroNodeInterface instance
/// and a MicroNode instance: Each MicroNodeInterface instance holds its own MicroNode
/// instance, see MicroNodeInterface::GetImplementation() and MicroNode::GetNode().
///
/// Although MicroNode itself has no data members, it is ensured by its subclasses that the
/// data layout always starts with MicroNode::Base. MicroNode::ToBase() does the corresponding cast.
//----------------------------------------------------------------------------------------
class MicroNode
{
public:
	//----------------------------------------------------------------------------------------
	/// This enum lists the defined micro node types.
	//----------------------------------------------------------------------------------------
	enum class TYPE
	{
		INVALID,

		/// Enum value for BasicMicroNode.
		BASIC,

		BATCH,
		SPLIT_MERGE,
		ITERATION,

		SEQUENCING,

		RECURSION_STEP,

		LIST_INPUT_GROUP,
		PREVIOUS_ITERATION_VALUE,
		COPY,

		VARIABLE_MASK = 0x10,

		VALUE_PORT_MASK = 0x20,

		INPUT_PORT_MASK = 0x40,
		EXPORTED_PORT = INPUT_PORT_MASK | VALUE_PORT_MASK,
		VIRTUAL_INPUT_PORT,

		OUTPUT_PORT_MASK = 0x80,
		VARIABLE = OUTPUT_PORT_MASK | VALUE_PORT_MASK | VARIABLE_MASK,

		PORT_MASK = INPUT_PORT_MASK | OUTPUT_PORT_MASK,

		FACTOR_MASK = 0x100,
		ROOT,
		SWITCH,
		CASE,
		WHILE_CONDITION,
		INDEFINITE_LOOP,

		TOP_LEVEL_FACTOR_MASK = 0x200,
		FRAME_MASK = 0x400,

		TOP_LEVEL_FRAME = FACTOR_MASK | TOP_LEVEL_FACTOR_MASK | FRAME_MASK,

		FRAME = FACTOR_MASK | FRAME_MASK,

		PARAMETER_MASK = 0x800,

		PARAMETERS = PARAMETER_MASK + 1,

		EVENT_MASK = 0x1000,
		EVENT = FACTOR_MASK | TOP_LEVEL_FACTOR_MASK | EVENT_MASK,

		DIMENSIONAL_HEAD_MASK = 0x2000,

		INDEFINITE_LOOP_HEAD,
		RECURSION_HEAD,

		DEFINITE_FACTOR_HEAD_MASK = 0x4000,

		DEFINITE_LOOP_HEAD = DEFINITE_FACTOR_HEAD_MASK | DIMENSIONAL_HEAD_MASK,

		CONTAINER_OUTPUT_HEAD_MASK = 0x8000,

		CONTAINER_OUTPUT_HEAD = CONTAINER_OUTPUT_HEAD_MASK | DIMENSIONAL_HEAD_MASK | OUTPUT_PORT_MASK | VARIABLE_MASK,
		ARRAY_OUTPUT_HEAD = CONTAINER_OUTPUT_HEAD | DEFINITE_FACTOR_HEAD_MASK,

//		PASSTHROUGH = 0x8000 | SINGLE_VALUE_INPUT_MASK,

		CONTAINER_LOOP_MASK = 0x10000,
		CONTAINER_LOOP,
		ARRAY_LOOP,

		CONTAINER_LOOP_HEAD_MASK = 0x20000,
		CONTAINER_LOOP_HEAD,
		ARRAY_LOOP_HEAD,

		CONTAINER_FACTOR_MASK = 0x40000,
		DEFINITE_FACTOR_MASK = 0x80000,
		DEFINITE_LOOP = FACTOR_MASK | DEFINITE_FACTOR_MASK,

		OTHER_FACTOR_MASK = 0x100000,
		RECURSION = FACTOR_MASK | OTHER_FACTOR_MASK,

		DIMENSIONAL_FACTOR_MASK = DEFINITE_FACTOR_MASK | OTHER_FACTOR_MASK,

		INPUT_ELEMENT_MASK = 0x200000,
		ARRAY_INPUT_ELEMENT = INPUT_ELEMENT_MASK, // | LVALUE_INPUT_MASK,
		LIST_INPUT_ELEMENT,

		INPUT_MASK = INPUT_PORT_MASK | INPUT_ELEMENT_MASK,

		FACTOR_REFERENCE_MASK = 0x400000,
		FACTOR_REFERENCE,

		CONTAINER_OUTPUT_ELEMENT = FACTOR_MASK | CONTAINER_FACTOR_MASK,
		ARRAY_OUTPUT_ELEMENT = CONTAINER_OUTPUT_ELEMENT | DEFINITE_FACTOR_MASK,

		LIST_PARAMETER = CONTAINER_OUTPUT_ELEMENT | PARAMETER_MASK,
		ARRAY_PARAMETER = ARRAY_OUTPUT_ELEMENT | PARAMETER_MASK,

		OUTPUT_MASK = OUTPUT_PORT_MASK,

		LIST_MASK = 0x800000,
		LIST = LIST_MASK | OUTPUT_PORT_MASK | VALUE_PORT_MASK | VARIABLE_MASK,
		ARRAY,

		CONTAINER_OUTPUT_MASK = 0x1000000,
		CONTAINER_OUTPUT = CONTAINER_OUTPUT_MASK | OUTPUT_PORT_MASK,


		ALL = 0x7fffffff

	} MAXON_ENUM_ORDERED_FLAGS_CLASS(TYPE);


	//----------------------------------------------------------------------------------------
	/// This enum lists the flags for micro nodes as returned by GetFlags().
	//----------------------------------------------------------------------------------------
	enum class FLAGS
	{
		/// No flag set.
		NONE = 0,
		STATE = 1,
		STATE_MODIFIER = 2,
		LOCAL = 4,
		PERMANENT = 8,
		CACHED = 16,
		HIDDEN = 32,
		PREVIOUS_ITV = 64,
		CURRENT_ITV = 128,
		PORT_MODIFIERS = PERMANENT | CACHED | HIDDEN | PREVIOUS_ITV | CURRENT_ITV,
		CONTAINER_MEMBER = 256,
		COMMUTATIVE = 512,
		STATE_MAPPER = 1024,
		BOUND_TO_THREAD = 2048,
		PARAMETER = 4096,
		INPUT_WITHOUT_VALUE = 8192,
		MODIFIERS = PORT_MODIFIERS | COMMUTATIVE | STATE_MAPPER | STATE_MODIFIER | BOUND_TO_THREAD,
		ALL = 0xffffff
	} MAXON_ENUM_FLAGS_CLASS(FLAGS);


	//----------------------------------------------------------------------------------------
	/// All MicroNode subclasses have a Base member as their first member. It stores data which
	/// is needed by all micro nodes.
	///
	/// The casts from and to MicroNode are handled by MicroNode::ToBase() and Base::ToNode().
	//----------------------------------------------------------------------------------------
	class Base
	{
	public:
		/// The MicroNodeInterface instance which owns this MicroNode.
		MicroNodeInterface* _node;

		/// The type of this micro node.
		TYPE _type;

		/// The flags of this micro node.
		FLAGS _flags;

		/// The free function is used to free this MicroNode instance.
		void (*_free) (const MicroNode*);

		/// This callback is used during the automatic setup of the ports created by MAXON_PORT macros.
		PortsDescriptionCallback _portsDesc = nullptr;

		/// Keeps track of the next unused access index during port setup.
		ACCESS_INDEX _nextFreeAccessIndex = ACCESS_INDEX::INDEX_0;

		//----------------------------------------------------------------------------------------
		/// Casts this Base object to MicroNode. Each MicroNode has a Base as its first data member.
		/// @return												This object, casted to MicroNode.
		//----------------------------------------------------------------------------------------
		MicroNode& ToMicroNode()
		{
			return *reinterpret_cast<MicroNode*>(this);
		}

		//----------------------------------------------------------------------------------------
		/// Casts this Base object to a subclass T of MicroNode. Each subclass of MicroNode has a Base as its first data member.
		/// @tparam T											A subclass of MicroNode.
		/// @return												This object, casted to T.
		//----------------------------------------------------------------------------------------
		template <typename T> const T& To() const
		{
			DebugAssert(_type == T::MICRONODE_TYPE);
			return *reinterpret_cast<const T*>(this);
		}
	};

	//----------------------------------------------------------------------------------------
	/// Casts this MicroNode to its Base object. Each MicroNode has a Base as its first data member.
	/// @return												This object, casted to Base.
	//----------------------------------------------------------------------------------------
	const Base& ToBase() const
	{
		return *reinterpret_cast<const Base*>(this);
	}

	/// @copydoc ToBase
	Base& ToBase()
	{
		return *reinterpret_cast<Base*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this micro node has the same implementation class as #other.
	/// @param[in] other							Another micro node.
	/// @return												This object, casted to MicroNode.
	//----------------------------------------------------------------------------------------
	Bool HasSameClass(const MicroNode& other) const
	{
		return ToBase()._free == other.ToBase()._free;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the MicroNodeInterface instance which owns this MicroNode.
	/// @return												The owning MicroNodeInterface.
	//----------------------------------------------------------------------------------------
	const MicroNodeInterface* GetNode() const
	{
		return ToBase()._node;
	}

	/// @copydoc GetNode
	MicroNodeInterface* GetNode()
	{
		return ToBase()._node;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type of this micro node.
	/// @return												Type of this micro node.
	//----------------------------------------------------------------------------------------
	TYPE GetType() const
	{
		return ToBase()._type;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the flags of this micro node.
	/// @return												Flags of this micro node.
	//----------------------------------------------------------------------------------------
	FLAGS GetFlags() const
	{
		return ToBase()._flags;
	}

	template <typename T> class AllowsChild : public std::true_type { };
	template <typename T> class AllowsParent : public std::true_type { };

	template <WIRETYPE WT> struct Source
	{
		MAXON_IMPLICIT Source(MicroNodeInterface* s) : src(s) { }
		MicroNodeInterface* src;
	};

	template <WIRETYPE WT, typename T> struct Child : public Result<T>
	{
		MAXON_IMPLICIT Child(Result<T>&& c) : Result<T>(std::move(c)) { }
	};

	template <typename PORT> using Input = typename PORT::PrivateInput;
	template <typename PORT> class Lazy;

	static const TYPE INPUT_TYPE_MASK = TYPE::INPUT_MASK;
	static const TYPE OUTPUT_TYPE_MASK = TYPE::OUTPUT_MASK;

	static const FLAGS MICRONODE_FLAGS = FLAGS::NONE;


	enum class PORTSACCESS_FLAGS
	{
		NONE = 0,
		ITERATION = 1,
		CONTAINER_MASK = 2,
		CONST_MASK = 4,
		BATCH = 8,
		BATCH_ACCESS = 16,
		CONTAINER = CONTAINER_MASK,
		CONST_CONTAINER = CONTAINER_MASK | CONST_MASK,
		DIRECT_ACCESS_TEST = CONTAINER_MASK | BATCH_ACCESS
	} MAXON_ENUM_FLAGS_CLASS(PORTSACCESS_FLAGS);

	template <PORTSACCESS_FLAGS ACCESS_FLAGS, typename... PORTS> class PortsAccess;


	//----------------------------------------------------------------------------------------
	/// You have to use @c{const Ports<...>&} as the parameter type of the Process method of a BasicMicroNode.
	/// @tparam PORTS									The ports which shall be accessed within the Process method.
	//----------------------------------------------------------------------------------------
	template <typename... PORTS> using Ports = typename PortsAccess<PORTSACCESS_FLAGS::NONE, PORTS...>::Members;


	static void InitUserData()
	{
	}

	static void GetLlvmAssembly(const LlvmGlobalsReceiver&)
	{
	}
};



//----------------------------------------------------------------------------------------
/// A NodeHandle identifies core/micro nodes and their instances in arbitrarily nested groups.
///
/// Consider the case of a group G which contains two core node instances m and n, and a
/// group H which contains two instances p, q of the same group G:
/// - H
///   - p: G
///     - m: M
///     - n: N
///   - q: G
///     - m: M
///     - n: N
///
/// So e.g. the instance m exists twice in H, but there is only one CoreNodeInstance object,
/// namely the one which is created when an instance of M is added to G, resulting in m.
/// When G is added as instance p to H, only a CoreNodeInstance object for p is created,
/// but not for its nested nodes m, n.
///
/// In order to differentiate between the occurrences of m, node handles are used:
/// Whenever an instance of a node is added to a group, node handles are automatically created
/// recursively for all instances nested in that node. For example when G is added as instance
/// q to H, node handles are created not only for q, but also for m and n. So node handles can
/// identify each node in the fully expanded instantiation hierarchy of a group.
///
/// To obtain a node handle for a node instance, use one of the CoreNodeInstanceBaseInterface::GetHandle()
/// methods. For example the call @c{p.GetHandle(m)} in the above situation returns the node
/// handle for the occurrence of m within p.
//----------------------------------------------------------------------------------------
class NodeHandle;


class CoreNodeBaseInterface;

//----------------------------------------------------------------------------------------
/// This is the base interface of MicroNodeInterface and CoreNodeInstanceInterface. It stands
/// for instances of nodes in a group: Micro nodes are children of a MicroNodeGroupInterface,
/// core node instances represent core nodes which are used as children of a CoreNodeGroupInterface.
//----------------------------------------------------------------------------------------
class CoreNodeInstanceBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CoreNodeInstanceBaseInterface, MAXON_REFERENCE_POINTER, "net.maxon.corenode.interface.corenodeinstancebase");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the name of this instance.
	/// @return												Name of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetName() const;

	//----------------------------------------------------------------------------------------
	/// Sets the name to use for this instance. Names have to be unique within the group
	/// to which this instance belongs.
	/// @param[in] name								The name to use for the node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetName(const Id& name);

	//----------------------------------------------------------------------------------------
	/// Returns the group node to which this node instance belongs.
	/// @return												The parent group of this node instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const CoreNodeBaseInterface* GetParentGroup() const;

	/// @copydoc GetParentGroup
	MAXON_FUNCTION CoreNodeBaseInterface* GetParentGroup()
	{
		return MAXON_NONCONST_COUNTERPART(GetParentGroup());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the NodeHandle of this node instance. This is the handle which is used to identify
	/// this instance within its enclosing group as root. If the enclosing group G is used as an
	/// instance in another group H and you want to identify this instance as a (nested) instance
	/// of H, you have to use GetHandle(INSTANCEPATH).
	/// @return												NodeHandle of this instance within its enclosing group.
	/// @see NodeHandle
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeHandle* GetHandle() const;

	//----------------------------------------------------------------------------------------
	/// Returns the NodeHandle of the nested node instance identified by path.
	/// For example consider the case of nested groups H, G, M, N, X (see also NodeHandle):
	/// - H
	///   - p: G
	///     - m: M
	///       - x: X
	///     - n: N
	///   - q: G
	///     - m: M
	///       - x: X
	///     - n: N
	///
	/// To obtain a node handle for the nested node instance p/m/x, we start with p (the node
	/// instance within the outmost group H) and have m/x as nested path. So the call
	/// @c{p.GetHandle(m, x)} returns the NodeHandle for the occurrence of m/x within p.
	///
	/// Five types of path elements are supported to identify the instance to use:
	/// 1. You can use a core node instance pointer (CoreNodeInstanceBaseInterface*, CoreNodeInstanceBasePtr and its derived classes).
	/// 2. You can use the index of the instance (an Int).
	/// 3. You can use the name of the instance (an Id).
	/// 4. The last path element can be an output port given by an OutPortId (optionally followed by a MicroNode::TYPE as a filter).
	///   Then the return value is the node handle of the micro node which represents the values of the given port.
	///   When the optional filter is used, the method only looks for connected micro nodes whose type matches the filter.
	/// 5. Finally you can use a Block of one of the previous four path elements.
	///
	/// GetInstancePath() implements the reverse of this method: For a node handle it returns the path its instances.
	///
	/// @param[in] path								A %path of nested node instances, see above for the allowed arguments.
	/// @return												The NodeHandle for the node instance identified by path.
	//----------------------------------------------------------------------------------------
	template <typename... INSTANCEPATH> MAXON_FUNCTION Result<const NodeHandle*> GetHandle(const INSTANCEPATH&... path) const
	{
		return GetHandleImpl(GetHandle(), path...);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the path of instances of a NodeHandle. For the following structure of nested groups
	/// - H
	///   - p: G
	///     - m: M
	///       - x: X
	///     - n: N
	///   - q: G
	///     - m: M
	///       - x: X
	///     - n: N
	///
	/// the node handle for x within m within p has the instance path p/m/x. The reverse operation
	/// (from an instance path to the node handle) is implemented by GetHandle(INSTANCEPATH).
	/// @param[in] handle							A node handle.
	/// @return												The path of node instances which leads to the instance of the handle.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<const CoreNodeInstanceBaseInterface*>> GetInstancePath(const NodeHandle* handle);

	/// @copydoc DefaultDoc::ToString
	MAXON_FUNCTION String ToString(const FormatStatement* fmt) const
	{
		return GetName().ToString(fmt);
	}

private:
	static MAXON_METHOD Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const CoreNodeInstanceBaseInterface* instance);

	template <typename... INSTANCEPATH> static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const CoreNodeInstanceBaseInterface* instance, const INSTANCEPATH&... rest)
	{
		return GetHandleImpl(GetHandleImpl(std::move(parent), instance), rest...);
	}

	static MAXON_METHOD Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, Int index);

	template <typename... INSTANCEPATH> static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, Int index, const INSTANCEPATH&... rest)
	{
		return GetHandleImpl(GetHandleImpl(std::move(parent), index), rest...);
	}

	static MAXON_METHOD Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const Id& name);

	template <typename... INSTANCEPATH> static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const Id& name, const INSTANCEPATH&... rest)
	{
		return GetHandleImpl(GetHandleImpl(std::move(parent), name), rest...);
	}

	static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent)
	{
		return std::move(parent);
	}

	template <typename ELEMENT, typename... INSTANCEPATH> static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const Block<ELEMENT>& path, const INSTANCEPATH&... rest)
	{
		Result<const NodeHandle*> h = std::move(parent);
		for (const ELEMENT& e : path)
		{
			h = GetHandleImpl(std::move(h), e);
		}
		return GetHandleImpl(std::move(h), rest...);
	}

	static MAXON_METHOD Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const OutPortId& port, MicroNode::TYPE filter = MicroNode::TYPE::VARIABLE_MASK);
};


class MicroNodeGroupInterface;

template <typename MN = MicroNode> class MicroNodePtr;
template <typename T, Bool OUTPUT = false> class VariadicPort;

//----------------------------------------------------------------------------------------
/// A MicroNodeInterface instance wraps a MicroNode so that it can be part of a
/// @ref MicroNodeGroupRef "micro node group".
///
/// MicroNodeInterface instances aren't created directly,
/// instead you create them by one of the MicroNodeGroupRef::Add functions which get
/// a MicroNode as parameter and impliclity create the required MicroNodeInterface wrapper.
/// For example in the following code
/// @code{corenodes_micronode_example}
//! class MyNode
//! {
//! public:
//! 	... port declarations ...
//! 
//! 	class Impl : public BasicMicroNode
//! 	{
//! 	public:
//! 		Result<void> Process(const Ports<...>& ports) const;
//!  	};
//! 
//! 	static Result<void> Init(const MicroNodeGroupRef& group)
//! 	{
//! 		iferr_scope;
//! 		MicroNodePtr<Impl> n = group.AddChild<Impl>() iferr_return;
//! 		... optionally do something with n, usually not needed ...
//! 		return OK;
//! 	}
//! };
/// @endcode
/// the call to Add adds an instance of the BasicMicroNode implementation class Impl
/// to #group and returns a pointer to the MicroNodeInterface instance which wraps
/// the Impl object.
///
/// MicroNodeInterface instances are always owned by the enclosing micro node group,
/// therefore there is no reference class.
//----------------------------------------------------------------------------------------
class MicroNodeInterface : public CoreNodeInstanceBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(MicroNodeInterface, MAXON_REFERENCE_POINTER, "net.maxon.corenode.interface.micronode");

	/// The type of the micro node implementation class of this micro node.
	MAXON_GENERIC((std::is_base_of) typename MN = MicroNode);

public:
	//----------------------------------------------------------------------------------------
	/// Returns the micro node group to which this micro node belongs.
	/// @return												The parent group of this micro node.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const MicroNodeGroupInterface* GetParentGroup() const
	{
		return reinterpret_cast<const MicroNodeGroupInterface*>(CoreNodeInstanceBaseInterface::GetParentGroup());
	}

	/// @copydoc GetParentGroup
	MAXON_FUNCTION MicroNodeGroupInterface* GetParentGroup()
	{
		return MAXON_NONCONST_COUNTERPART(GetParentGroup());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type of this micro node. This is the type of the @ref GetImplementation
	/// "MicroNode implementation" wrapped by this node.
	/// @return												The type of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MicroNode::TYPE GetType() const;

	//----------------------------------------------------------------------------------------
	/// Returns the MicroNode implementation which is wrapped by this MicroNodeInterface instance.
	/// @return												The implementation type of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const MN& GetImplementation() const;

	/// @copydoc GetImplementation
	MicroNode& GetImplementation()
	{
		return MAXON_NONCONST_COUNTERPART(GetImplementation());
	}

	//----------------------------------------------------------------------------------------
	/// Adds additional flags to the micro node.
	/// @param[in] flags							The flags to add. Only modifier flags (MicroNode::FLAGS::MODIFIERS) can be added.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void AddFlags(MicroNode::FLAGS flags)
	{
		DebugAssert(!(flags & ~(MicroNode::FLAGS::MODIFIERS | MicroNode::FLAGS::STATE)));
		GetImplementation().ToBase()._flags |= flags;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the data type of this micro node. This is only supported for a subset of micro nodes.
	/// @param[in] type								The data type of this micro node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetDataType(const DataType& type);

	//----------------------------------------------------------------------------------------
	/// Adds a variadic port to this micro node. The number and names of the variadic port instances
	/// are determined from arg:
	/// - If arg wraps an Array<VariadicInstance>, then it defines number and names. If prefix is
	///   given, it is used as a %prefix with a # as an additional separation character.
	/// - If arg wraps a non-negative Int, then it defines the number of port instances.
	///   The names are given by the prefix, followed by a # and a 0-based index.
	/// - Otherwise a single instance is added whose name is just the prefix followed by a #.
	///   This special case is only needed for CoreNodeWrapper: It has to create node templates
	///   for core nodes, and this special case allows to instantiate a core node with a placeholder
	///   port which stands for an arbitrary number of port instances.
	///
	/// The typical use looks as follows:
	/// @code{corenodes_variadicport_example}
	//! template <typename T> class SumNode
	//! {
	//! public:
	//! 	MAXON_PORT_OUTPUT(T, out);
	//! 
	//!  	class Impl : public BasicMicroNode
	//! 	{
	//! 	public:
	//! 		Result<void> Process(const Ports<out>& ports) const
	//! 		{
	//! 			T sum = T();
	//! 			for (auto input : _inputs(ports))
	//! 				sum += input();
	//! 			ports.out.Update(sum);
	//! 			return OK;
	//! 		}
	//! 
	//! 		typename VariadicPort<const T>::Access _inputs;
	//! 	};
	//! 
	//!  	static Result<void> Init(const MicroNodeGroupRef& group, const DataDictionary& args)
	//!  	{
	//! 		iferr_scope;
	//! 		MicroNodePtr<Impl> base = group.AddChild<Impl>() iferr_return;
	//! 		base.AddVariadicPort(&Impl::_inputs, "in"_cs, args.Get(Id("in"), Data())) iferr_return;
	//! 		return OK;
	//! 	}
	//! };
	/// @endcode
	/// @param[in] acc								Pointer-to-member for a member of the micro node implementation MN of type VariadicPort<const T>::Access.
	/// 															This member can be used in the micro node implementation to loop over the port instances.
	/// @param[in] prefix							A name %prefix.
	/// @param[in] arg								This controls the number and names of the port instances, see above.
	/// @param[in] wires							The wires to use for the connection to the port instances.
	/// @return												Array of identifiers for the variadic port instances.
	//----------------------------------------------------------------------------------------
	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortId>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const CString& prefix, const Data& arg, WIRETYPE wires = WIRETYPE::ALL)
	{
		iferr_scope;
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), prefix, arg) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	//----------------------------------------------------------------------------------------
	/// Adds a variadic port to this micro node. See the other AddVariadicPort function for a
	/// description. This functions differs from the other one in how the variadic ports are given:
	/// count is the number of variadic ports, and the names are given by the prefix, then a #
	/// and finally an index which starts with #base. If #base is negative, count has to be 1,
	/// then the name of the single port is just the prefix plus #.
	///
	/// @param[in] acc								Pointer-to-member for a member of the micro node implementation MN of type VariadicPort<const T>::Access.
	/// 															This member can be used in the micro node implementation to loop over the port instances.
	/// @param[in] prefix							A name %prefix.
	/// @param[in] count							The number of port instances to create.
	/// @param[in] base								The %base to use for name counting.
	/// @param[in] wires							The wire types to use for the connection to the port instances.
	/// @return												Array of identifiers for the variadic port instances.
	//----------------------------------------------------------------------------------------
	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortId>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const CString& prefix, Int count, Int base = 0, WIRETYPE wires = WIRETYPE::ALL)
	{
		iferr_scope;
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), prefix, count, base) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortId>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const Block<const Member>& members, WIRETYPE wires = WIRETYPE::ALL)
	{
		iferr_scope;
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), members) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	//----------------------------------------------------------------------------------------
	/// Adds a connection from this micro node to the target micro node. thisIndex and targetIndex
	/// control at which index the Process methods of #this and target produce/receive the value
	/// transported by the connection.
	///
	/// To connect a micro node with a port of its enclosing group, use Export().
	///
	/// @param[in] thisIndex					The index of the parameter of this micro node which shall be transported along the connection.
	/// 															Use ACCESS_INDEX::UNUSED when this is not needed.
	/// @param[in] target							Another micro node.
	/// @param[in] targetIndex				The index of the parameter of the target micro node which shall receive the transported value of the connection.
	/// 															Use ACCESS_INDEX::UNUSED when this is not needed.
	/// @param[in] wires							The wires to use for the connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by both ends are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Connect(ACCESS_INDEX thisIndex, MicroNodeInterface* target, ACCESS_INDEX targetIndex, WIRETYPE wires);

	//----------------------------------------------------------------------------------------
	/// Adds a connection from this micro node to the target micro node. If it is necessary to specify
	/// at least one ACCESS_INDEX for the connection, use the other Connect() method.
	///
	/// To connect a micro node with a port of its enclosing group, use Export().
	///
	/// @param[in] target							Another micro node.
	/// @param[in] wires							The wires to use for the connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by both ends are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> Connect(MicroNodeInterface* target, WIRETYPE wires)
	{
		return Connect(ACCESS_INDEX::UNUSED, target, ACCESS_INDEX::UNUSED, wires);
	}

	//----------------------------------------------------------------------------------------
	/// Exports an input parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by a name for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty name,
	/// the name of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the input parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	/// @param[in] type								An optional type for the exported port. This is combined with the current type of the exported port,
	/// 															which may result in an error if the types can't be combined.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InPortId> Export(const InPortId& parentPort, WIRETYPE wires = WIRETYPE::ALL, ACCESS_INDEX index = ACCESS_INDEX::UNUSED, const DataType& type = DataType::NullValue())
	{
		return ExportImpl(parentPort, wires, index, type);
	}

	//----------------------------------------------------------------------------------------
	/// Exports an output parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by a name for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty name,
	/// the name of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the output parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	/// @param[in] type								An optional type for the exported port. This is combined with the current type of the exported port,
	/// 															which may result in an error if the types can't be combined.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutPortId> Export(const OutPortId& parentPort, WIRETYPE wires = WIRETYPE::ALL, ACCESS_INDEX index = ACCESS_INDEX::UNUSED, const DataType& type = DataType::NullValue())
	{
		return ExportImpl(parentPort, wires, index, type);
	}

	//----------------------------------------------------------------------------------------
	/// Exports a parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// This function can be used instead of the other Export functions when a port from a
	/// MAXON_PORT macro shall be used as argument instead of an index or name. The name of the port,
	/// followed by a pair of parentheses, has to be used as argument for parentPort:
	/// @code{corenodes_export_example}
	//! class WhileNode
	//! {
	//! public:
	//! 	MAXON_PORT_INPUT(Bool, condition);
	//! 
	//! 	static Result<void> Init(const MicroNodeGroupRef& group, const DataDictionary&)
	//! 	{
	//! 		...
	//! 		MicroNodePtr<WhileConditionMicroNode> it = group.AddChild<WhileConditionMicroNode>() iferr_return;
	//! 		it.Export(condition(), WIRETYPE::ALL, ACCESS_INDEX::INDEX_0) iferr_return;
	//! 		...
	//! 	}
	//! };
	/// @endcode
	/// For indexed ports you have to specify the indices within the parentheses,
	/// MicroNodeGroupInterface::GetPort.
	///
	/// @param[in] parentPort					One of the ports declared by a MAXON_PORT macro within the enclosing group.
	///																A parentheses pair, possibly including indices, is needed after the name, see example.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	//----------------------------------------------------------------------------------------
	template <typename PORT> MAXON_FUNCTION Result<typename PORT::PortIdType> Export(const PORT& parentPort, WIRETYPE wires = WIRETYPE::ALL, ACCESS_INDEX index = ACCESS_INDEX::UNUSED)
	{
		iferr_scope;
		auto portId = MakeDependentExpr<PORT>(this)->GetParentGroup()->GetPort(parentPort) iferr_return;
		ExportImpl(portId, wires, index, GetPortType<typename PORT::PortDeclarationType>()) iferr_return;
		return std::move(portId);
	}

	/// @MAXON_ANNOTATION{returnsThis}
	template <typename MN, typename A, typename... ARGS> MAXON_FUNCTION Result<void> operator ()(Result<A>&& arg, ARGS&&... args)
	{
		if (arg == FAILED)
			return arg.GetErrorStorage();
		Result<void> res = AddChild<MN>(arg.GetValue());
		if (res == FAILED)
			return res.GetErrorStorage();
		return this->operator ()<MN>(std::forward<ARGS>(args)...);
	}

	/// @MAXON_ANNOTATION{returnsThis}
	template <typename MN, typename A, typename... ARGS> MAXON_FUNCTION Result<void> operator ()(A&& arg, ARGS&&... args)
	{
		Result<void> res = AddChild<MN>(arg);
		if (res == FAILED)
			return res.GetErrorStorage();
		return this->operator ()<MN>(std::forward<ARGS>(args)...);
	}

private:
	MAXON_METHOD Result<Int> ExportImpl(const PortId& parentPort, WIRETYPE wires, ACCESS_INDEX index, const DataType& type);

	template <typename MN> ResultOk<void> operator ()()
	{
		return OK;
	}

	template <typename MN, typename T, typename = typename std::enable_if<MN::template AllowsChild<T>::value && T::template AllowsParent<MN>::value>::type> Result<void> AddChild(MicroNodePtr<T> mn, WIRETYPE wt = WIRETYPE::DOMAIN_FLOW | WIRETYPE::HIERARCHY)
	{
		return Connect(mn, wt);
	}
};

class CoreNodeGroupInterface;
class CoreNode;
class CoreNodeInstancePtr;

//----------------------------------------------------------------------------------------
/// CoreNodeInstanceInterface is an instance of a core node within a core node group. Such an
/// instance is created whenever you add a core node as a child to a group:
/// @code
/// CoreNodeInstancePtr instance = group.AddChild(Id(), node) iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------
class CoreNodeInstanceInterface : public CoreNodeInstanceBaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(CoreNodeInstanceInterface, MAXON_REFERENCE_POINTER, "net.maxon.corenode.interface.corenodeinstance");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the core node group to which this core node instance belongs.
	/// @return												The parent group of this core node.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const CoreNodeGroupInterface* GetParentGroup() const
	{
		return reinterpret_cast<const CoreNodeGroupInterface*>(CoreNodeInstanceBaseInterface::GetParentGroup());
	}

	/// @copydoc GetParentGroup
	MAXON_FUNCTION CoreNodeGroupInterface* GetParentGroup()
	{
		return MAXON_NONCONST_COUNTERPART(GetParentGroup());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the core node of which this object is an instance.
	/// @return												The instanced core node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const CoreNode& GetBase() const;

	//----------------------------------------------------------------------------------------
	/// Connects the outport of this instance to the inport of dest.
	/// To connect a port of this instance with a port of its enclosing group, use Export().
	/// @param[in] outport						An output port of this core node instance.
	/// @param[in] dest								Another core node instance within the same core node group.
	/// @param[in] inport							An input port of dest.
	/// @param[in] wires							The wires to use for the connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by both ports are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Connect(const OutPortId& outport, CoreNodeInstanceInterface* dest, const InPortId& inport, WIRETYPE wires = WIRETYPE::DOMAIN_FLOW_VALUE | WIRETYPE::SEQUENCED | WIRETYPE::STATE);

	//----------------------------------------------------------------------------------------
	/// Exports the given input port of this instance to a port of the enclosing group.
	/// If parentPort is given by a name for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty name,
	/// the name of inport is used instead of parentPort.
	/// @param[in] inport							An input port of this core node instance.
	/// @param[in] parentPort					A port of the enclosing group. If empty, the name of inport is used instead.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by inport are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InPortId> Export(const InPortId& inport, const InPortId& parentPort = InPortId::NullValue(), WIRETYPE wires = WIRETYPE::ALL)
	{
		return ExportImpl(inport, parentPort, wires);
	}

	//----------------------------------------------------------------------------------------
	/// Exports the given output port of this instance to a port of the enclosing group.
	/// If parentPort is given by a name for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty name,
	/// the name of outport is used instead of parentPort.
	/// @param[in] outport						An output port of this core node instance.
	/// @param[in] parentPort					A port of the enclosing group. If empty, the name of outport is used instead.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by outport are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutPortId> Export(const OutPortId& outport, const OutPortId& parentPort = OutPortId::NullValue(), WIRETYPE wires = WIRETYPE::ALL)
	{
		return ExportImpl(outport, parentPort, wires);
	}

private:
	MAXON_METHOD Result<Int> ExportImpl(const PortId& port, const PortId& parentPort, WIRETYPE wires);
};


#include "corenodes_instances1.hxx"

#include "corenodes_instances2.hxx"

}

} // namespace maxon

#endif // CORENODES_INSTANCES_H__
