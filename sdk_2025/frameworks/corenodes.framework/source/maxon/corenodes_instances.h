#ifndef CORENODES_INSTANCES_H__
#define CORENODES_INSTANCES_H__

#include "maxon/url.h"
#include "maxon/corenodes_helpers.h"

namespace maxon
{

namespace corenodes
{

class MicroNodeInterface;

class PortAccessDescription;
using PortAccessDescriptionCallback = void(*)(PortAccessDescription*);

using LlvmGlobalsReceiver = Delegate<Result<void>(const CString& name, const CString& decl, void* address)>;

enum class PORT_MODE : UInt32
{
	NONE = 0,

	INPUT_PORT_FLAG = 1 << 0,

	INPUT_FLAG = 1 << 1,
	OUTPUT_FLAG = 1 << 2,
	LCV_PREV_FLAG = 1 << 3,
	LCV_NEXT_FLAG = 1 << 4,
	REDUCTION_FLAG = 1 << 5,
	FINAL_FLAG = 1 << 6,

	UNINITIALIZED = 1 << 7,

	// IMPORTANT: Make sure the following enum values don't conflict with the previous ones!

	LAZY = (maxon::UInt32) WIRETYPE::LAZY,
	CONSUMABLE_REQUEST = (maxon::UInt32) WIRETYPE::CONSUMABLE_REQUEST,

	// Modifers can be combined freely with the other flags.
	MODIFIERS = UNINITIALIZED | LAZY | CONSUMABLE_REQUEST,

	INPUT = INPUT_FLAG | INPUT_PORT_FLAG,
	OUTPUT = OUTPUT_FLAG,
	LCV_PREV = INPUT_FLAG | LCV_PREV_FLAG,
	LCV_NEXT = OUTPUT_FLAG | LCV_NEXT_FLAG,
	REDUCTION = OUTPUT_FLAG | REDUCTION_FLAG,
	FINAL = INPUT_FLAG | FINAL_FLAG | CONSUMABLE_REQUEST

} MAXON_ENUM_FLAGS(PORT_MODE);


// Used internally as template parameter of MicroNode::PortsAccess.
// It configures in which way the PortsAccess (which is related to the Ports<> parameter of a Process method) accesses port values.
enum class PORTS_MODE
{
	// Default mode (non-batch, the Process method handles a single set of input/output values).
	NONE = 0,
	// Iteration mode, used for IterationMicroNode.
	ITERATION = 1,
	// Batch mode, the Process method handles a batch of input/output values.
	BATCH = 2,
	// The DIRECT mode is used within the batch loop: The loop sets up a local DirectVarAccess object which directly contains
	// the ViewIteratorMembers to iterate over the batch.
	DIRECT = 4,
	// This flag has to be set when the Process method needs to access variadic ports.
	VARIADIC = 8,
	// Mask of all modifiers (which can be set in addition to the real mode flags like BATCH).
	MODIFIERS = VARIADIC
} MAXON_ENUM_FLAGS(PORTS_MODE);

//----------------------------------------------------------------------------------------
/// MicroNode is the base class of all micro node implementation classes such as BasicMicroNode.
/// To implement a new custom micro node, you usually write a subclass of BasicMicroNode.
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

		ITERATION,

		SEQUENCING,

		NOP,
		SUBTRACTIVE_DOMAIN,

		JOIN,
		CONTROL_TRANSFER,

		MAX_WITHOUT_FLAG,

		VARIABLE_MASK = 0x20,
		MIN_FLAG = VARIABLE_MASK,

		VALUE_PORT_MASK = 0x40,

		INPUT_PORT_MASK = 0x80,
		EXPORTED_PORT = INPUT_PORT_MASK | VALUE_PORT_MASK,
		VIRTUAL_INPUT_PORT,

		OUTPUT_PORT_MASK = 0x100,
		VARIABLE = OUTPUT_PORT_MASK | VALUE_PORT_MASK | VARIABLE_MASK,

		PORT_MASK = INPUT_PORT_MASK | OUTPUT_PORT_MASK,

		VARIABLE_FRONT_MASK = 0x10000000,
		VARIABLE_BACK_MASK = 0x20000000,

		VARIABLE_FRONT = VARIABLE | VARIABLE_FRONT_MASK,
		VARIABLE_BACK = OUTPUT_PORT_MASK | VARIABLE_BACK_MASK,

		FACTOR_MASK = 0x200,
		ROOT,
		WHILE_CONDITION,
		INDEFINITE_LOOP,
		BLOCK,

		TOP_LEVEL_FACTOR_MASK = 0x400,
		FRAME_MASK = 0x800,

		TOP_LEVEL_FRAME = FACTOR_MASK | TOP_LEVEL_FACTOR_MASK | FRAME_MASK,

		FRAME = FACTOR_MASK | FRAME_MASK,

		FACTOR_HEADER_MASK = 0x2000,

		BLOCK_HEADER = FACTOR_HEADER_MASK + 1,
		CONDITIONAL_HEADER,

		DEFINITE_FACTOR_HEADER_MASK = 0x4000,
		CONTAINER_LOOP_HEADER_MASK = 0x8000,
		CONTAINER_OUTPUT_FRONT_MASK = 0x10000,

		DEFINITE_FACTOR_MASK = 0x20000,
		CONTAINER_OUTPUT_ELEMENT_MASK = 0x40000,
		INDEXABLE_FACTOR_MASK = 0x80000,

		DIMENSIONAL_FACTOR_TEST = DEFINITE_FACTOR_MASK | CONTAINER_OUTPUT_ELEMENT_MASK,

		CONTAINER_LOOP_MASK = 0x100000,


		DEFINITE_LOOP_HEADER = FACTOR_HEADER_MASK | DEFINITE_FACTOR_HEADER_MASK,

		CONTAINER_LOOP_HEADER = FACTOR_HEADER_MASK | CONTAINER_LOOP_HEADER_MASK,
		ARRAY_LOOP_HEADER = CONTAINER_LOOP_HEADER | DEFINITE_FACTOR_HEADER_MASK,

		CONTAINER_LOOP = FACTOR_MASK | CONTAINER_LOOP_MASK | DEFINITE_FACTOR_MASK,
		ARRAY_LOOP = CONTAINER_LOOP | INDEXABLE_FACTOR_MASK,

		CONTAINER_OUTPUT_FRONT = FACTOR_HEADER_MASK | CONTAINER_OUTPUT_FRONT_MASK | OUTPUT_PORT_MASK | VARIABLE_MASK | VARIABLE_FRONT_MASK,

		CONTAINER_OUTPUT_ELEMENT = FACTOR_MASK | CONTAINER_OUTPUT_ELEMENT_MASK | DEFINITE_FACTOR_MASK,
		ARRAY_OUTPUT_ELEMENT = CONTAINER_OUTPUT_ELEMENT | INDEXABLE_FACTOR_MASK,

		DEFINITE_LOOP = FACTOR_MASK | DEFINITE_FACTOR_MASK | INDEXABLE_FACTOR_MASK,
		GENERIC_DEFINITE_LOOP,

		INPUT_ELEMENT_MASK = 0x200000,
		ARRAY_INPUT_ELEMENT,
		CONTAINER_INPUT_ELEMENT,

		INPUT_MASK = INPUT_PORT_MASK | INPUT_ELEMENT_MASK,

		OUTPUT_MASK = OUTPUT_PORT_MASK,

		CONDITIONAL_MASK = 0x400000,

		IF = FACTOR_MASK | CONDITIONAL_MASK,

		CONTAINER_MASK = 0x800000,
		CONTAINER = CONTAINER_MASK + 1,
		ARRAY_CONTAINER,
		ARRAY,

		CONTAINER_OUTPUT_BACK_MASK = 0x1000000,
		CONTAINER_OUTPUT_BACK = CONTAINER_OUTPUT_BACK_MASK | OUTPUT_PORT_MASK | VARIABLE_BACK_MASK,

		CONTAINER_INPUT_GROUP_MASK = 0x2000000,
		CONTAINER_INPUT_GROUP,

		FACTOR_WITH_FACTOR_VARIABLE = DEFINITE_FACTOR_MASK | CONTAINER_OUTPUT_ELEMENT_MASK | CONTAINER_LOOP_MASK | CONDITIONAL_MASK,

//		ARRAY_OUTPUT_HEAD = CONTAINER_OUTPUT_FRONT | DEFINITE_FACTOR_HEADER_MASK,

		ALL = 0x7fffffff

	} MAXON_ENUM_ORDERED_FLAGS_CLASS(TYPE);

	static_assert(TYPE::MAX_WITHOUT_FLAG <= TYPE::MIN_FLAG);

	//----------------------------------------------------------------------------------------
	/// This enum lists the flags for micro nodes as returned by GetFlags().
	//----------------------------------------------------------------------------------------
	enum class FLAGS : Int64
	{
		/// No flag set.
		NONE = 0,
		STATE_ACCESS = 1 << 0,
		LOCAL = 1 << 1,
		PERMANENT = 1 << 2,
		CACHED = 1 << 3,
		CONTAINER_MEMBER = 1 << 4,
		COMMUTATIVE = 1 << 5,
		PARAMETER = 1 << 6,													///< Set for ports added by ParameterBuilder::AddParameter, ports that don't have input/default values given by the graph (like component access ports).
		INPUT_WITHOUT_VALUE = 1 << 7,
		OUTER_DOMAIN = 1 << 8,
		SUSPEND = 1 << 9,
		INDEPENDENT = 1 << 10,
		FIX_DOMAIN = 1 << 11,
		FACTOR_REFERENCE = 1 << 12,
		OPTIONAL_INPUT = 1 << 13,
		KEEP_VALUES = 1 << 14,
		NEW_UNIQUE_NAME = 1 << 15,
		TIMESTEP = 1 << 16,													///< Set for a micro node which shall be executed as part of the state transition from one time step to the next, see also EXECUTION_MODE.
		UNDERSCORE_NUMBER_PREFIX = 1 << 17,
		WRAPPER_HIDDEN = 1 << 18,
		WRAPPER_KEEP_LETTER_CASE = 1 << 19,
		WRAPPER_LAMBDA = 1 << 20,
		WRAPPER_USE_ATTRIBUTE_RESOURCES = 1 << 21,
		WRAPPER_FIXED_VARIADIC = 1 << 22,
		WRAPPER_COPIED_VARIADIC = 1 << 23,
		WRAPPER_INNER_DOMAIN = 1 << 24,							///< Marker flag for inner-domain ports, used by the core node wrapper.
		WRAPPER_OUTER_DOMAIN = 1 << 25,							///< Marker flag for outer-domain ports, used by the core node wrapper.
		WRAPPER_ENCLOSING_DOMAIN = 1 << 26,					///< Marker flag for enclosing-domain ports, used by the core node wrapper.
		WRAPPER_STREAM = 1 << 27,										///< Marker flag for stream ports, used by the core node wrapper.
		WRAPPER_CONTEXT = 1 << 28,									///< Marker flag for context ports, used by the core node wrapper.
		NO_FACTOR_NODES = 1 << 29,
		// #LEGACYCOMPATIBILITY: replace RUNTIME_COST_100 by a function which can be defined at a BasicMicroNode
		RUNTIME_COST_100 = 1LL << 30,								///< Execution of node takes about 100x the time of a usual node.

		LCV = 1LL << 31,
		REDUCTION = 1LL << 32,
		STATE_MASK = LCV | REDUCTION,

		EXPORT_LCV = 1LL << 33,

		UNINITIALIZED = 1LL << 34,									///< Set for a BasicMicroNode if all of its output ports shall not be initialized prior to execution of Process method.

		WRAPPER_FLAGS = WRAPPER_HIDDEN | WRAPPER_KEEP_LETTER_CASE | WRAPPER_LAMBDA | WRAPPER_USE_ATTRIBUTE_RESOURCES | WRAPPER_FIXED_VARIADIC | WRAPPER_COPIED_VARIADIC | WRAPPER_INNER_DOMAIN | WRAPPER_OUTER_DOMAIN | WRAPPER_ENCLOSING_DOMAIN | WRAPPER_STREAM | WRAPPER_CONTEXT,
		PORT_MODIFIERS = PERMANENT | CACHED | OPTIONAL_INPUT | WRAPPER_FLAGS | NO_FACTOR_NODES,
		MODIFIERS = PORT_MODIFIERS | COMMUTATIVE | FIX_DOMAIN | STATE_ACCESS | OUTER_DOMAIN | SUSPEND | INDEPENDENT | FACTOR_REFERENCE | TIMESTEP,
		PORTINFO_FLAGS = WRAPPER_FLAGS,
		ALL = -1
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

		/// This callback is used during the automatic setup of the port access made by a micro node's Process method.
		PortAccessDescriptionCallback _portAccessDesc = nullptr;

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

	template <WIRETYPE WT> struct Source
	{
		MAXON_IMPLICIT Source(MicroNodeInterface* s) : src(s) { }
		MicroNodeInterface* src;
	};

	template <WIRETYPE WT, typename T> struct Child : public Result<T>
	{
		MAXON_IMPLICIT Child(Result<T>&& c) : Result<T>(std::move(c)) { }
	};

	#define PRIVATE_MAXON_PORT_QUALIFIER(name, mode, test) \
		static_assert(test, "The port can't be used as " #name " port."); \
		static constexpr PORT_MODE MODE = mode; \
		static constexpr PORT_MODE ALLOWED_MODES = PORT_MODE::NONE; \
		template <typename OWNER, PORT_MODE PM = MODE> using Port = typename PORT::template Port<OWNER, PM>

	template <typename PORT> struct Input : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Input, PORT_MODE::INPUT_FLAG, PORT::ALLOWED_MODES & PORT_MODE::INPUT_FLAG);
	};

	template <typename PORT> struct Init : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Init, PORT_MODE::OUTPUT, PORT::ALLOWED_MODES & PORT_MODE::OUTPUT_FLAG);
	};

	template <typename PORT> struct Previous : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Previous, PORT_MODE::LCV_PREV, PORT::ALLOWED_MODES & PORT_MODE::LCV_PREV_FLAG);
	};

	template <typename PORT> struct Next : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Next, PORT_MODE::LCV_NEXT | (PORT::MODE & PORT_MODE::INPUT_PORT_FLAG), PORT::ALLOWED_MODES & PORT_MODE::LCV_NEXT_FLAG);
	};

	template <typename PORT> struct Reduction : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Reduction, PORT_MODE::REDUCTION, PORT::ALLOWED_MODES & PORT_MODE::REDUCTION_FLAG);
	};

	template <typename PORT> struct Final : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Final, PORT_MODE::FINAL, PORT::ALLOWED_MODES & PORT_MODE::FINAL_FLAG);
	};

	template <typename PORT> struct Uninitialized : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Uninitialized, PORT::MODE | PORT_MODE::UNINITIALIZED, PORT::MODE & PORT_MODE::OUTPUT_FLAG);
	};

	template <typename PORT> struct Consumable : public PORT
	{
		PRIVATE_MAXON_PORT_QUALIFIER(Consumable, PORT::MODE | PORT_MODE::CONSUMABLE_REQUEST, PORT::MODE & PORT_MODE::INPUT_FLAG);
	};

	template <typename PORT> class Lazy;

	static constexpr TYPE INPUT_TYPE_MASK = TYPE::INPUT_MASK;
	static constexpr TYPE OUTPUT_TYPE_MASK = TYPE::OUTPUT_MASK;

	static constexpr FLAGS MICRONODE_FLAGS = FLAGS::NONE;

	template <PORTS_MODE MODE, typename... PORTS> class PortsAccess;

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
	/// Returns the identifier of this instance.
	/// @return												Identifier of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Sets the identifier to use for this instance. Identifiers have to be unique within the group
	/// to which this instance belongs.
	/// @param[in] identifier					The identifier to use for the node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetId(const Id& identifier);

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
	/// 3. You can use the identifier of the instance (an Id).
	/// 4. The last path element can be an output port given by an OutPortId (optionally followed by a MicroNode::TYPE as a filter).
	///   Then the return value is the node handle of the micro node which represents the values of the given port.
	///   When the optional filter is used, the method only looks for connected micro nodes whose type matches the filter.
	/// 5. Finally you can use a Block of one of the previous four path elements.
	///
	/// GetInstancePath() implements the reverse of this method: For a node handle it returns the path of its instances.
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

	static MAXON_METHOD String PrivateNodeHandleToString(const NodeHandle* handle, const FormatStatement* fs);

	/// @copydoc DefaultDoc::ToString
	MAXON_FUNCTION String ToString(const FormatStatement* fmt = nullptr) const
	{
		return GetId().ToString(fmt);
	}

	//----------------------------------------------------------------------------------------
	/// Reads the compiled node's additional attributes. Those attributes are the result of graph compilation.
	/// Use instead of GetUserData.
	/// @return												The additional attribute dictionary. Can be empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataDictionary& GetCompilationData() const;

	//----------------------------------------------------------------------------------------
	/// Sets the compiler additional attributes. Usually set by CompilerInterface::Compile.
	/// @param[in] data								The compiler additional attributes for this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetCompilationData(DataDictionary&& data);


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

	static MAXON_METHOD Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const Id& id);

	template <typename... INSTANCEPATH> static Result<const NodeHandle*> GetHandleImpl(Result<const NodeHandle*>&& parent, const Id& id, const INSTANCEPATH&... rest)
	{
		return GetHandleImpl(GetHandleImpl(std::move(parent), id), rest...);
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

inline String ToString(const NodeHandle* h, const FormatStatement* fs, Bool checkDataType = true)
{
	return CoreNodeInstanceBaseInterface::PrivateNodeHandleToString(h, fs);
}

class MicroNodeGroupInterface;

template <typename MN = MicroNode> class MicroNodePtr;
template <typename T, Bool OUTPUT_PORT = false, Bool WRITE = OUTPUT_PORT> class VariadicPort;

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
//! 		MAXON_ATTRIBUTE_FORCE_RELEASE_INLINE Result<void> Process(const Ports<...>& ports) const;
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
	/// @MAXON_ANNOTATION{refclass=true}
	MAXON_FUNCTION MN& GetImplementation()
	{
		return MAXON_NONCONST_COUNTERPART(GetImplementation());
	}

	//----------------------------------------------------------------------------------------
	/// Adds additional flags to the micro node.
	/// @param[in] flags							The flags to add. Only modifier flags (MicroNode::FLAGS::MODIFIERS) can be added.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddFlags(MicroNode::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Sets the data type of this micro node. This is only supported for a subset of micro nodes.
	/// @param[in] type								The data type of this micro node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetDataType(const DataType& type);

	//----------------------------------------------------------------------------------------
	/// Adds a variadic port to this micro node. The number and identifiers of the variadic port instances
	/// are determined from arg:
	/// - If arg wraps an Array<VariadicInstance>, then it defines number and identifiers. If prefix is
	///   given, it is used as a %prefix with a # as an additional separation character.
	/// - If arg wraps a non-negative Int, then it defines the number of port instances.
	///   The identifiers are given by the prefix, followed by a # and a 0-based index.
	/// - Otherwise a single instance is added whose identifier is just the prefix followed by a #.
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
	//! 		MAXON_ATTRIBUTE_FORCE_RELEASE_INLINE Result<void> Process(const Ports<out>& ports) const
	//! 		{
	//! 			T sum = T();
	//! 			for (auto input : _inputs(ports))
	//! 				sum += input();
	//! 			ports.out.Update(sum);
	//! 			return OK;
	//! 		}
	//! 
	//! 		typename VariadicPort<T>::Access _inputs;
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
	/// @param[in] acc								Pointer-to-member for a member of the micro node implementation MN of type VariadicPort<T>::Access.
	/// 															This member can be used in the micro node implementation to loop over the port instances.
	/// @param[in] prefix							An identifier %prefix.
	/// @param[in] arg								This controls the number and identifiers of the port instances, see above.
	/// @param[in] type								The type to use for the variadic ports. By default this is the type of #acc.
	/// @param[in] flags							Additional flags for the created ports.
	/// @param[in] mode								The port mode. By default this will be OUTPUT or INPUT, depending on the variadic port.
	/// @param[in] wires							The wires to use for the connection to the port instances.
	/// @return												Array of identifiers for the variadic port instances.
	//----------------------------------------------------------------------------------------
	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortIdType>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const CString& prefix, const Data& arg, const DataType& type = GetZeroRef<DataType>(), MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, PORT_MODE mode = PORT_MODE::NONE, WIRETYPE wires = WIRETYPE::DEFAULT)
	{
		iferr_scope;
		// MSVC workaround: MSVC crashes if GetDataType<typename VARIADIC_ACCESS::ValueType>() is used as default argument for type, therefore use an empty type as default and replace it by the correct type here.
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), prefix, arg, type ? type : GetDataType<typename VARIADIC_ACCESS::ValueType>(), flags) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, mode, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	//----------------------------------------------------------------------------------------
	/// Adds a variadic port to this micro node. See the other AddVariadicPort function for a
	/// description. This functions differs from the other one in how the variadic ports are given:
	/// count is the number of variadic ports, and the identifiers are given by the prefix, then a #
	/// and finally an index which starts with #base. If #base is negative, count has to be 1,
	/// then the identifier of the single port is just the prefix plus #.
	///
	/// @param[in] acc								Pointer-to-member for a member of the micro node implementation MN of type VariadicPort<T>::Access.
	/// 															This member can be used in the micro node implementation to loop over the port instances.
	/// @param[in] prefix							An identifier %prefix.
	/// @param[in] count							The number of port instances to create.
	/// @param[in] base								The %base to use for identifier counting.
	/// @param[in] flags							Additional flags for the created ports.
	/// @param[in] mode								The port mode. By default this will be OUTPUT or INPUT, depending on the variadic port.
	/// @param[in] wires							The wires to use for the connection to the port instances.
	/// @return												Array of identifiers for the variadic port instances.
	//----------------------------------------------------------------------------------------
	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortIdType>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const CString& prefix, Int count, Int base = 0, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, PORT_MODE mode = PORT_MODE::NONE, WIRETYPE wires = WIRETYPE::DEFAULT)
	{
		iferr_scope;
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), prefix, count, base, flags) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, mode, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortIdType>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const CString& prefix, const Block<const Member>& members, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, PORT_MODE mode = PORT_MODE::NONE, WIRETYPE wires = WIRETYPE::DEFAULT)
	{
		iferr_scope;
		typename VARIADIC_ACCESS::VPort ports = VARIADIC_ACCESS::VPort::Create(GetParentGroup(), prefix, members, flags) iferr_return;
		ports.ConnectMicroNode(MicroNodePtr<MN>(this), acc, mode, wires) iferr_return;
		return std::move(ports.GetPorts());
	}

	template <typename VARIADIC_ACCESS, typename MN> MAXON_FUNCTION Result<BaseArray<typename VARIADIC_ACCESS::VPort::PortIdType>> AddVariadicPort(VARIADIC_ACCESS MN::* acc, const Block<const Member>& members, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE, PORT_MODE mode = PORT_MODE::NONE, WIRETYPE wires = WIRETYPE::DEFAULT)
	{
		return AddVariadicPort<VARIADIC_ACCESS, MN>(acc, CString::DefaultValue(), members, flags, mode, wires);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a connection from this micro node to the target micro node.
	/// The optional index controls at which index the Process method of #this or target produces/receives the value
	/// transported by the connection. (Both ends of the connection use the same index,
	/// but that's no problem because at most one of the ends is associated with a Process method.)
	///
	/// To connect a micro node with a port of its enclosing group, use Export().
	///
	/// @param[in] target							Another micro node.
	/// @param[in] wires							The wires to use for the connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by both ends are ignored.
	/// @param[in] index							The index of the Process method's parameter of the micro node (at one end of the connection)
	/// 															which shall produce/receive the transported value of the connection.
	/// 															Use ACCESS_INDEX::UNUSED when this is not needed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Connect(MicroNodeInterface* target, WIRETYPE wires, ACCESS_INDEX index = ACCESS_INDEX::UNUSED);

	//----------------------------------------------------------------------------------------
	/// Exports an input parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the input parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	/// @param[in] type								An optional type for the exported port. This is combined with the current type of the exported port,
	/// 															which may result in an error if the types can't be combined.
	/// @param[in] flags							Optional flags for the input port.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InPortId> Export(const InPortId& parentPort, WIRETYPE wires, ACCESS_INDEX index, const DataType& type = DataType::DefaultValue(), MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		return ExportImpl(parentPort, wires, index, type, flags);
	}

	//----------------------------------------------------------------------------------------
	/// Exports an input parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// @param[in] flags							Optional flags for the input port.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InPortId> Export(const InPortId& parentPort, WIRETYPE wires, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		return ExportImpl(parentPort, wires, ACCESS_INDEX::UNUSED, DataType::DefaultValue(), flags);
	}

	//----------------------------------------------------------------------------------------
	/// Exports an output parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the output parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	/// @param[in] type								An optional type for the exported port. This is combined with the current type of the exported port,
	/// 															which may result in an error if the types can't be combined.
	/// @param[in] flags							Optional flags for the input port.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutPortId> Export(const OutPortId& parentPort, WIRETYPE wires, ACCESS_INDEX index, const DataType& type = DataType::DefaultValue(), MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		return ExportImpl(parentPort, wires, index, type, flags);
	}

	//----------------------------------------------------------------------------------------
	/// Exports an output parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of this micro node is used instead of parentPort.
	///
	/// @param[in] parentPort					A port of the enclosing group.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// @param[in] flags							Optional flags for the input port.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutPortId> Export(const OutPortId& parentPort, WIRETYPE wires, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		return ExportImpl(parentPort, wires, ACCESS_INDEX::UNUSED, DataType::DefaultValue(), flags);
	}

	//----------------------------------------------------------------------------------------
	/// Exports a parameter of this micro node to a port of the enclosing group.
	/// This is only needed for built-in micro nodes, custom micro nodes automatically export
	/// their ports according to the parameters of the Process method.
	///
	/// This function can be used instead of the other Export functions when a port from a
	/// MAXON_PORT macro shall be used as argument instead of an index or identifier. The identifier of the port,
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
	//! 		it.Export(condition(), WIRETYPE::DEFAULT, ACCESS_INDEX::INDEX_0) iferr_return;
	//! 		...
	//! 	}
	//! };
	/// @endcode
	/// For indexed ports you have to specify the indices within the parentheses,
	/// MicroNodeGroupInterface::GetPort.
	///
	/// @param[in] parentPort					One of the ports declared by a MAXON_PORT macro within the enclosing group.
	/// 															A parentheses pair, possibly including indices, is needed after the identifier, see example.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by this micro node are ignored.
	/// @param[in] index							The index of the parameter of this micro node which shall be exported.
	/// 															Use ACCESS_INDEX::UNUSED (the default) when this is not needed.
	/// @param[in] flags							Optional flags for the input port.
	//----------------------------------------------------------------------------------------
	template <typename PORT> MAXON_FUNCTION Result<typename PORT::PortIdType> Export(const PORT& parentPort, WIRETYPE wires = WIRETYPE::DEFAULT, ACCESS_INDEX index = ACCESS_INDEX::UNUSED, MicroNode::FLAGS flags = MicroNode::FLAGS::NONE)
	{
		iferr_scope;
		auto portId = MakeDependentExpr<PORT>(this)->GetParentGroup()->GetPort(parentPort) iferr_return;
		ExportImpl(portId, wires, index, GetDataType<typename PORT::PortDeclarationType>(), flags) iferr_return;
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

	MAXON_METHOD Result<void> PrivateConnectPort(MicroNodeInterface* outputPort, ACCESS_INDEX index, PORT_MODE mode);

private:
	MAXON_METHOD Result<Int> ExportImpl(const PortId& parentPort, WIRETYPE wires, ACCESS_INDEX index, const DataType& type, MicroNode::FLAGS flags);

	template <typename MN> ResultOk<void> operator ()()
	{
		return OK;
	}

	template <typename MN, typename T> Result<void> AddChild(MicroNodePtr<T> mn, WIRETYPE wt = WIRETYPE::DOMAIN_FLOW | WIRETYPE::HIERARCHY)
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
	MAXON_METHOD Result<void> Connect(const OutPortId& outport, CoreNodeInstanceInterface* dest, const InPortId& inport, WIRETYPE wires = WIRETYPE::ALL);

	//----------------------------------------------------------------------------------------
	/// Exports the given input port of this instance to a port of the enclosing group.
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of inport is used instead of parentPort.
	/// @param[in] inport							An input port of this core node instance.
	/// @param[in] parentPort					A port of the enclosing group. If empty, the identifier of inport is used instead.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by inport are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<InPortId> Export(const InPortId& inport, const InPortId& parentPort = InPortId::DefaultValue(), WIRETYPE wires = WIRETYPE::ALL)
	{
		return ExportImpl(inport, parentPort, wires);
	}

	//----------------------------------------------------------------------------------------
	/// Exports the given output port of this instance to a port of the enclosing group.
	/// If parentPort is given by an identifier for which there is no port yet, a corresponding port
	/// is created at the enclosing group. If parentPort is empty or has an empty identifier,
	/// the identifier of outport is used instead of parentPort.
	/// @param[in] outport						An output port of this core node instance.
	/// @param[in] parentPort					A port of the enclosing group. If empty, the identifier of outport is used instead.
	/// @param[in] wires							The wires to use for the export connection. Already existing wires aren't changed.
	/// 															Wires which aren't supported by outport are ignored.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<OutPortId> Export(const OutPortId& outport, const OutPortId& parentPort = OutPortId::DefaultValue(), WIRETYPE wires = WIRETYPE::ALL)
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
