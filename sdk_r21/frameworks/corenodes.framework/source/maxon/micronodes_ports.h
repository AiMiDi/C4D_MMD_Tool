#ifndef MICRONODES_PORTS_H__
#define MICRONODES_PORTS_H__

#include "maxon/micronodes_runtime.h"
#include "maxon/corenodes.h"

namespace maxon
{

namespace corenodes
{

//----------------------------------------------------------------------------------------
/// Defines an input port of a micro node group with the given type and name. The macro
/// has to be used within a micro node group implementation class, see MicroNodeGroupInterface
/// for a complete example.
///
/// To be accessible within the Process method of a micro node, you have to add the port
/// to the port list of the MicroNode::Ports or BatchMicroNode::Batch template for the
/// Process methods's parameter. Within the method you can use two operations on the port:
/// - @c{ports.name()} returns the value of the input port.
/// - @c{ports.name.HasValue()} returns true if the port has some explicitly given value
///   (such as a default value or a value coming from a connected upstream port), false otherwise.
///
/// The following code shows the usage of MAXON_INPUT_PORT:
/// @code{corenodes_inputport}
//! class MySquareRoot
//! {
//! public:
//! 	// Declaration of the input and output ports of the micro node group.
//! 	MAXON_PORT_INPUT(Float, input);
//! 	MAXON_PORT_OUTPUT(Float, result);
//! 
//! 	class Impl : public BasicMicroNode
//! 	{
//! 	public:
//! 		// The Process method needs to specify which ports of the group the micro node accesses, in this case all ports.
//! 		// If the group contains more than one micro node, each micro node usually needs only a subset of the ports.
//! 		Result<void> Process(const Ports<input, result>& ports) const
//! 		{
//! 			// Read value from input port.
//! 			Float x = ports.input();
//! 
//! 			// Check if the input port has a user-defined value.
//! 			Bool hasValue = ports.input.HasValue();
//! 			...
//! 			return OK;
//! 		}
//!  	};
//! 
//! 	...
//! };
/// @endcode
///
/// @param[in] T									The type of the port.
/// @param[in] name								The name of the port.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_INPUT(T, name) PRIVATE_MAXON_INPUT_PORT(T, name, false, false, -1)


//----------------------------------------------------------------------------------------
/// Defines an indexed input port of a micro node group with the given type and name.
/// An indexed port is an indexable collection of N ports with same name and type.
/// The number N has to be a compile-time constant, for a dynamic number of ports see
/// VariadicPort.
///
/// The macro has to be used within a micro node group implementation class,
/// afterwards you can use the indexed port for micro nodes as in this example:
/// @code{corenodes_indexedport}
//! // This class template defines a micro node group which adds N values.
//! template <Int N> class MyIndexedAddNode
//! {
//! public:
//! 	// Declaration of the input and output ports of the micro node group.
//! 	MAXON_PORT_INPUT_INDEXED(Int, in, N);
//! 	MAXON_PORT_OUTPUT(Int, out);
//! 
//! 	// Implementation of the single custom micro node.
//! 	class Impl : public BasicMicroNode
//! 	{
//! 	public:
//! 		// The Process method needs to specify which ports of the group the micro node accesses, in this case all ports.
//! 		// If the group contains more than one micro node, each micro node usually needs only a subset of the ports.
//! 		Result<void> Process(const Ports<in, out>& ports) const
//! 		{
//! 			Int sum = 0;
//! 			for (Int i = 0; i < N; ++i)
//! 			{
//! 				sum += ports.in[i]();
//! 			}
//! 			ports.out.Update(sum);
//! 			return OK;
//! 		}
//!  	};
//! 
//! 	// The Init function will be called to set up the micro node group
//! 	// when you call CreateNode<MyIndexedAddNode<N>>() or as part of the MAXON_CORENODE_REGISTER macro.
//! 	static Result<void> Init(const MicroNodeGroupRef& group)
//! 	{
//! 		iferr_scope;
//! 		group.AddChild<Impl>() iferr_return;
//! 		for (Int i = 0; i < N; ++i)
//! 		{
//! 			// GetPort() needs the index of the port for which you want to get the PortId,
//! 			// you have to specify the index within the parentheses.
//! 			InPortId p = group.GetPort(in(i)) iferr_return;
//! 			DiagnosticOutput("Name of port @ is @.", i, group.GetPortInfo(p).name);
//! 		}
//! 		return OK;
//! 	}
//! };
/// @endcode
///
/// @note name is the name by which the port is accessed in source code. The name which
/// is used by the API (such as in PortInfo::name) is name followed by a dot and the index
/// plus one (so the names are 1-based).
///
/// @param[in] T									The type of the indexed port.
/// @param[in] name								The name of the indexed port.
/// @param[in] N									The number of ports.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_INPUT_INDEXED(T, name, N) PRIVATE_MAXON_INPUT_PORT(T, name, false, true, N)


//----------------------------------------------------------------------------------------
/// Defines an output port of a micro node group with the given type and name. The macro
/// has to be used within a micro node group implementation class, see MicroNodeGroupInterface
/// for a complete example.
///
/// To be accessible within the Process method of a micro node, you have to add the port
/// to the port list of the MicroNode::Ports or BatchMicroNode::Batch template for the
/// Process methods's parameter. Within the method you can use several operations on the port:
/// - @c{ports.name.Update(v)} updates the output value with #v. Update checks if the value differs
///   from the previous value, and also updates the modification stamp in that case.
/// - @c{ports.name.GetWritable()} returns an l-value-reference to the value of the output port.
///   You can modify the value through that reference. The modification stamp of the port's value
///   is automatically updated by the call to GetWritable(), whether there will be a
///   subsequent modification of the value or not.
/// - @c{ports.name.GetWritableTouchLater()} returns an l-value-reference to the value of the output port.
///   You can modify the value through that reference. If you have made some modification,
///   you have to make sure to update the modification stamp of the port's value by a call to Touch(),
///   otherwise downstream parts of the core node graph might not get re-evaluated.
/// - @c{ports.name.Touch()} updates the modification stamp of the port value. You have to call this
///   after GetWritableTouchLater() if you've made an actual modification.
/// - @c{ports.name.IsNeeded()} returns true if the port's value is needed at all, false otherwise.
///   This is useful for micro nodes with multiple output ports where only some of them are
///   needed by downstream parts of the core node graph to avoid unnecessary, time-consuming
///   computations. If the micro node has just a single output port this isn't needed because
///   the micro node won't be evaluated if the output port's value isn't used.
/// - @c{ports.name.IsTimeStamped()} returns true if the port's value is time-stamped, false otherwise.
///
/// The following code shows the usage of MAXON_OUTPUT_PORT:
/// @code{corenodes_outputport}
//! class MySquareRoot
//! {
//! public:
//! 	// Declaration of the input and output ports of the micro node group.
//! 	MAXON_PORT_INPUT(Float, input);
//! 	MAXON_PORT_OUTPUT(Float, result);
//! 
//! 	class Impl : public BasicMicroNode
//! 	{
//! 	public:
//! 		// The Process method needs to specify which ports of the group the micro node accesses, in this case all ports.
//! 		// If the group contains more than one micro node, each micro node usually needs only a subset of the ports.
//! 		Result<void> Process(const Ports<input, result>& ports) const
//! 		{
//! 			Float x = ports.input();
//! 
//! 			// Update the port's value, this will only update the time stamp if the new value differs from the previous one.
//! 			ports.result.Update(Sqrt(x));
//! 
//! 			// Directly set the port's value, this will always update the time stamp.
//! 			ports.result.GetWritable() = Sqrt(x);
//! 
//! 			// Same as above.
//! 			Float& r = ports.result.GetWritable();
//! 			r = Sqrt(x);
//! 
//! 			// GetWritableTouchLater() returns a writable reference for the port value. When you modify the referenced value
//! 			// you have to make sure to call Touch() on the port to update the time stamp.
//! 			Float& s = ports.result.GetWritableTouchLater();
//! 			if (s * s != x)
//! 			{
//! 				// Current value of output port isn't the square root of x, recompute and update time stamp.
//! 				// (In practice one wouldn't use this optimization for something as simple as Sqrt.)
//! 				s = Sqrt(x);
//! 				ports.result.Touch();
//! 			}
//! 
//! 			// Check if the value of the output port is actually needed.
//! 			Bool needed = ports.result.IsNeeded();
//! 		
//! 			// Check if the output port is time-stamped.
//! 			Bool timeStamped = ports.result.IsTimeStamped();
//! 
//! 			
//! 			return OK;
//! 		}
//!  	};
//! 
//! 	...
//! };
/// @endcode
///
/// @param[in] T									The type of the port.
/// @param[in] name								The name of the port.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_OUTPUT(T, name) PRIVATE_MAXON_OUTPUT_PORT(T, name, VariableMicroNode, false, false, -1)


//----------------------------------------------------------------------------------------
/// Defines an indexed output port of a micro node group with the given type and name,
/// see MAXON_PORT_INPUT_INDEXED for more details.
///
/// @param[in] T									The type of the indexed port.
/// @param[in] name								The name of the indexed port.
/// @param[in] N									The number of ports.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_OUTPUT_INDEXED(T, name, N) PRIVATE_MAXON_OUTPUT_PORT(T, name, VariableMicroNode, false, true, N)


namespace details
{

template <typename PORT, typename OWNER> class DirectPortAccess
{
public:
	using Owner = OWNER;

	static ACCESS_INDEX PrivateGetMemberIndex()
	{
		return PORT::PrivateGetIndex();
	}

	const Generic* PrivateGet(Int portIndex) const
	{
		return _it.value;
	}

	Bool IsNeeded(Int portIndex = 0) const
	{
		return !(PORT_FLAGS(_it.simd.GetFlags()) & PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue(Int portIndex = 0) const
	{
		return !(PORT_FLAGS(_it.simd.GetFlags()) & PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	const OWNER& GetOwner(Int portIndex) const
	{
		return ((typename OWNER::Members*) (this - Int(PORT::PrivateGetIndex()) - portIndex))->PrivateGetPortsAccess();
	}

	void Init()
	{
	}

protected:
	DirectPortAccess() = default;

	DirectPortAccess(const DirectPortAccess& src)
	{
		MAXON_ASSERT_STANDARD_LAYOUT(DirectPortAccess);
		static_assert(SIZEOF(DirectPortAccess) == SIZEOF(ViewIteratorMember), "Wrong layout.");
		static_assert(SIZEOF(DirectPortAccess) == OWNER::MEMBER_SIZE, "Wrong layout.");
		static_assert(SIZEOF(PORT) == SIZEOF(ViewIteratorMember) * PORT::COUNT, "Wrong layout.");
		OWNER::CheckAssertions();
		MicroNodeGroupInterface::PrivateDescribePortAccess(src._description, PORT::PrivateGetIndex(), PORT::PortClass::GetSourceCodePortHash(), std::is_reference<typename PORT::Type>::value);
	}

	DirectPortAccess& operator =(const DirectPortAccess&) = delete;

	union
	{
		ViewIteratorMember _it;
		PortsDescription* _description;
	};
};

template <typename PORT, typename OWNER> class MappedPortAccess
{
public:
	using Owner = OWNER;

	static ACCESS_INDEX PrivateGetMemberIndex()
	{
		return PORT::PrivateGetIndex();
	}

	const Generic* PrivateGet(Int portIndex) const
	{
		return GetOwner(portIndex).GetBaseData().GetMember(ACCESS_INDEX(Int(PORT::PrivateGetIndex()) + portIndex)).value;
	}

	Bool IsNeeded(Int portIndex = 0) const
	{
		return !(PORT_FLAGS(GetOwner(portIndex).GetBaseData().GetMember(ACCESS_INDEX(Int(PORT::PrivateGetIndex()) + portIndex)).simd.GetFlags()) & PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue(Int portIndex = 0) const
	{
		return !(PORT_FLAGS(GetOwner(portIndex).GetBaseData().GetMember(ACCESS_INDEX(Int(PORT::PrivateGetIndex()) + portIndex)).simd.GetFlags()) & PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	const OWNER& GetOwner(Int portIndex) const
	{
		return ((typename OWNER::Members*) (this - Int(PORT::PrivateGetIndex()) - portIndex))->PrivateGetPortsAccess();
	}

	void Init()
	{
	}

protected:
	MappedPortAccess() = default;

	MappedPortAccess(const MappedPortAccess& src)
	{
		MAXON_ASSERT_STANDARD_LAYOUT(MappedPortAccess);
		static_assert(SIZEOF(MappedPortAccess) == SIZEOF(void*), "Wrong layout.");
		static_assert(SIZEOF(MappedPortAccess) == OWNER::MEMBER_SIZE, "Wrong layout.");
		static_assert(SIZEOF(PORT) == SIZEOF(void*) * PORT::COUNT, "Wrong layout.");
		OWNER::CheckAssertions();
		MicroNodeGroupInterface::PrivateDescribePortAccess(src._description, PORT::PrivateGetIndex(), PORT::PortClass::GetSourceCodePortHash(), std::is_reference<typename PORT::Type>::value);
	}

	MappedPortAccess& operator =(const MappedPortAccess&) = delete;

	PortsDescription* _description;
};

template <typename ELEMENT> class ArrayElementAccess;

template <typename T, typename ACCESS, typename CHECK> class PortOps;

template <typename T, typename ACCESS> class PortOpsBase : public ACCESS
{
public:
	template <typename ACC> using Rebind = PortOps<T, ACC, void>;

	const T& operator ()() const
	{
		return *reinterpret_cast<const T*>(this->PrivateGet(0));
	}
};

template <typename T, typename ACCESS> class PortOpsBase<T&, ACCESS> : public ACCESS
{
public:
	template <typename ACC> using Rebind = PortOps<T&, ACC, void>;

	template <typename T2> T2& GetImpl() const
	{
		// static_assert(std::is_same<T, Generic>::value, "The function template Get may only be used when the declared port type is Generic.");
		return *reinterpret_cast<T2*>(const_cast<Generic*>(this->PrivateGet(0)));
	}

	T& operator ()() const
	{
		return GetImpl<T>();
	}

	T& GetWritable() const
	{
		return GetImpl<T>();
	}

	void Update(const T& value) const
	{
		GetImpl<T>() = value;
	}

	void Update(T&& value) const
	{
		GetImpl<T>() = std::move(value);
	}
};

template <typename T, typename ACCESS, typename CHECK> class PortOps : public PortOpsBase<T, ACCESS>
{
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit PortOps(ARGS&&... args)
	{
		this->Init(std::forward<ARGS>(args)...);
	}
};


template <typename ACCESS> class IndexedPortAccess
{
public:
	using Owner = typename ACCESS::Owner;

	void Init(const ACCESS* access, Int index)
	{
		_access = access;
		_index = index;
	}

	ACCESS_INDEX PrivateGetMemberIndex() const
	{
		return ACCESS_INDEX(Int(ACCESS::PrivateGetMemberIndex()) + _index);
	}

	decltype(std::declval<const ACCESS*>()->PrivateGet(Int())) PrivateGet(Int portIndex) const
	{
		return _access->PrivateGet(_index);
	}

	const Owner& GetOwner(Int portIndex) const
	{
		return _access->GetOwner(_index);
	}

private:
	const ACCESS* _access;
	Int _index;
};

template <typename OP, Int N> class IndexedPort
{
public:
	using Element = typename OP::template Rebind<IndexedPortAccess<OP>>;

	Element operator [](Int index) const
	{
		DebugAssert((UInt) index < (UInt) N);
		return Element(std::is_empty<OP>::value ? _access : _access + index, index);
	}

private:
	OP _access[std::is_empty<OP>::value ? 1 : N];
};

//----------------------------------------------------------------------------------------
/// SourceCodePortId is used internally to identify the ports created with the MAXON_PORT macros.
//----------------------------------------------------------------------------------------
struct SourceCodePortId
{
	explicit SourceCodePortId(Int h = -1, Int i = -1) : hash(h), linearIndex(i)
	{
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(SourceCodePortId, hash, linearIndex);

	explicit operator Bool() const
	{
		return Bool(linearIndex >= 0);
	}

	Int hash;					///< A hash code based on the port name. Negative for input ports, non-negative for output or state ports.
	Int linearIndex;	///< The linear index for indexed ports. E.g. for a port array p[3][4] the port at [1][2] has linear index 1*4+2 = 6.
};


template <typename C, typename MICRO, Int HASH, Bool LOCAL, Bool IS_STATE, Int INDEXCOUNT> class PortDefBase
{
public:
	using PortClass = C;
	using MicroNodeClass = MICRO;

	PortDefBase() = default;

	PortDefBase(const PortDefBase& src)
	{
		src._info->CreatePort(GetSourceCodePortHash(), C::GetId(), MICRO::MICRONODE_TYPE, MICRONODE_FLAGS, GetPortType<typename C::PortDeclarationType>(), INDEXCOUNT);
	}

	static const Bool STATE = IS_STATE;
	static const MicroNode::FLAGS MICRONODE_FLAGS = ConditionalFlag(IS_STATE, MicroNode::FLAGS::STATE) | ConditionalFlag(LOCAL, MicroNode::FLAGS::LOCAL);

	static Int GetSourceCodePortHash() { return HASH; }
	SourceCodePortId GetSourceCodePortId() const { return SourceCodePortId(HASH, _linearIndex); }

protected:
	MicroNodeGroupInterface::PrivateAutoCreatePortInfo* _info;
	Int _linearIndex;
};

template <typename DIMENSION> inline Int ComputeLinearIndex(const Int* index)
{
	Int i = index[std::rank<DIMENSION>::value - 1];
	DebugAssert((UInt) i < (UInt) std::extent<DIMENSION>::value);
	return ComputeLinearIndex<typename std::remove_extent<DIMENSION>::type>(index) * std::extent<DIMENSION>::value + i;
}

template <> inline Int ComputeLinearIndex<Char>(const Int* index)
{
	return 0;
}

template <typename DIMENSION> inline Int ComputeLinearIndex(Int index)
{
	static_assert(std::rank<DIMENSION>::value == 1, "Wrong overload used.");
	DebugAssert((UInt) index < (UInt) std::extent<DIMENSION>::value);
	return index;
}

template <typename C, typename MICRO, Int HASH, Bool LOCAL, Bool STATE, Int MEMBERS, typename DIMENSION, Int INDEXCOUNT> class PortDefBaseCtor : public PortDefBase<C, MICRO, HASH, LOCAL, STATE, INDEXCOUNT>
{
public:
	using Super = PortDefBaseCtor;
//	static_assert(std::is_reference<T>::value || std::is_const<typename maxon::GetReferencedType<T, const maxon::Int>::type>::value, "The type of a port must not be a non-const reference.");
//	static_assert((MEMBERS == 0) || IsPossiblyContainer<T>::value, "Only arrays or lists allow nested ports.");

	static_assert(INDEXCOUNT != 0, "An index count of 0 is not allowed.");
	using PrivateMaxonCorenodesParentDimension = DIMENSION;

	PortDefBaseCtor(const PortDefBaseCtor&) = default;

	using IndexType = typename std::conditional<std::rank<DIMENSION>::value == 1, Int, Int[std::rank<DIMENSION>::value]>::type;

	explicit PortDefBaseCtor(const IndexType& index)
	{
		this->_linearIndex = ComputeLinearIndex<DIMENSION>(index);
	}

	explicit PortDefBaseCtor(ENUM_DONT_INITIALIZE)
	{
	}
};

template <typename C, typename MICRO, Int HASH, Bool LOCAL, Bool STATE, Int MEMBERS> class PortDefBaseCtor<C, MICRO, HASH, LOCAL, STATE, MEMBERS, void, -1> : public PortDefBase<C, MICRO, HASH, LOCAL, STATE, -1>
{
public:
	using Super = PortDefBaseCtor;
//	static_assert(std::is_reference<T>::value || std::is_const<typename maxon::GetReferencedType<T, const maxon::Int>::type>::value, "The type of a port must not be a non-const reference.");
//	static_assert((MEMBERS == 0) || IsPossiblyContainer<T>::value, "Only arrays or lists allow nested ports.");

	PortDefBaseCtor(const PortDefBaseCtor&) = default;

	PortDefBaseCtor()
	{
		this->_linearIndex = 0;
	}

	explicit PortDefBaseCtor(ENUM_DONT_INITIALIZE)
	{
	}
};

template <typename T, Int N> struct AddDimension
{
	using type = T[N];
};

template <Int N> struct AddDimension<void, N>
{
	using type = Char[N];
};

#define PRIVATE_MAXON_PORT_WRAP_false(CNT, ...) __VA_ARGS__
#define PRIVATE_MAXON_PORT_WRAP_true(CNT, ...) maxon::corenodes::details::IndexedPort<__VA_ARGS__, CNT>
#define PRIVATE_MAXON_PORT_DIMENSION_false(CNT) PrivateMaxonCorenodesParentDimension
#define PRIVATE_MAXON_PORT_DIMENSION_true(CNT) typename maxon::corenodes::details::AddDimension<PrivateMaxonCorenodesParentDimension, CNT>::type


#define PRIVATE_MAXON_PORT_MEMBER(name, ARRAY, CNT) \
	template <typename OWNER> struct Port \
	{ \
		using Type = PortAccessType; \
		using PortClass = PrivatePortClass; /* we have to use PrivatePortClass instead of just 'name', otherwise the declaration of the 'name' member below would change the meaning of the name 'name' which is an error */ \
		static const maxon::Int COUNT = ARRAY ? CNT : 1; \
		MAXON_MACROARG_TYPE(PRIVATE_MAXON_PORT_WRAP_##ARRAY(CNT, maxon::corenodes::details::PortOps<PortAccessType, typename OWNER::template MemberAccess<Port>, void>)) name; \
		static maxon::corenodes::ACCESS_INDEX PrivateGetIndex() { return maxon::corenodes::ACCESS_INDEX(MAXON_OFFSETOF_NON_STANDARD_LAYOUT(typename OWNER::Members, name) / OWNER::MEMBER_SIZE); } \
	}

template <typename T> using MyBegin = typename T::Begin;

#define PRIVATE_MAXON_PORT(name, ARRAY, CNT, ...) \
	static maxon::Id GetId() { return maxon::Id(#name); } \
	template <typename... ARGS> name(ARGS&&... args) : name::Super(std::forward<ARGS>(args)...) { } \
	using PrivatePortClass = name; /* see above in PRIVATE_MAXON_PORT_MEMBER */ \
	PRIVATE_MAXON_PORT_MEMBER(name, ARRAY, CNT); \
	template <typename SUPER> struct Element : public SUPER \
	{ \
		MAXON_MACROARG_TYPE(PRIVATE_MAXON_PORT_WRAP_##ARRAY(CNT, maxon::corenodes::details::PortOps<PortAccessType, maxon::corenodes::details::ArrayElementAccess<Element>, void>)) name; \
		static maxon::Int PrivateGetOffset() { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(Element, array) - MAXON_OFFSETOF_NON_STANDARD_LAYOUT(Element, name); } \
		static maxon::corenodes::ACCESS_INDEX PrivateGetIndex() { return maxon::corenodes::ACCESS_INDEX(MAXON_OFFSETOF_NON_STANDARD_LAYOUT(typename SUPER::ArrayOps::Values::Members, name) / SIZEOF(maxon::ViewIteratorMember)); } \
	};

// To avoid commas in PRIVATE_MAXON_INPUT_PORT (they would lead to wrong macro expansion), we define a type alias here.
template <typename T> using PortValueTypeHelper = typename std::conditional<std::is_reference<T>::value, typename std::decay<T>::type, typename std::add_const<T>::type>::type;

#define PRIVATE_MAXON_PORT_GET_NAME_HASHCODE(name) (maxon::Int(maxon::PrivateGetHashCode(MAXON_STRINGIFY(name), SIZEOF(MAXON_STRINGIFY(name))-1)) & maxon::LIMIT<maxon::Int>::MAX)

#define PRIVATE_MAXON_INPUT_PORT(T, name, LOCAL, ARRAY, CNT, ...) \
	struct name : public MAXON_MACROARG_TYPE(maxon::corenodes::details::PortDefBaseCtor<name, maxon::corenodes::VirtualInputPort, ~(PRIVATE_MAXON_PORT_GET_NAME_HASHCODE(name)), LOCAL, std::is_reference<T>::value, MAXON_EXPAND(MAXON_VA_NARGS(__VA_ARGS__)), PRIVATE_MAXON_PORT_DIMENSION_##ARRAY(CNT), CNT>) \
	{ \
		using PortDeclarationType = maxon::corenodes::details::PortValueTypeHelper<T>; \
		using PortAccessType = typename maxon::corenodes::UnannotatedType<T>::type; \
		using PortIdType = maxon::corenodes::InPortId; \
		PRIVATE_MAXON_PORT(name, ARRAY, CNT, __VA_ARGS__) \
	}; name PrivateRegister_##name = name(maxon::DONT_INITIALIZE)

#define PRIVATE_MAXON_STATE_PORT(T, name, LOCAL, ARRAY, CNT, ...) \
	struct name : public MAXON_MACROARG_TYPE(maxon::corenodes::details::PortDefBaseCtor<name, maxon::corenodes::VariableMicroNode, PRIVATE_MAXON_PORT_GET_NAME_HASHCODE(name), LOCAL, true, MAXON_EXPAND(MAXON_VA_NARGS(__VA_ARGS__)), PRIVATE_MAXON_PORT_DIMENSION_##ARRAY(CNT), CNT>) \
	{ \
		using PortDeclarationType = T; \
		using UnannotatedPortType = typename maxon::corenodes::UnannotatedType<T>::type; \
		using PortAccessType = typename std::add_lvalue_reference<UnannotatedPortType>::type; \
		using PortIdType = maxon::corenodes::OutPortId; \
		PRIVATE_MAXON_PORT(name, ARRAY, CNT, __VA_ARGS__) \
		struct PrivateInput \
		{ \
			using MicroNodeClass = maxon::corenodes::VariableMicroNode; \
			using PortDeclarationType = const T; \
			using PortAccessType = UnannotatedPortType; \
			PRIVATE_MAXON_PORT_MEMBER(name, ARRAY, CNT); \
		}; \
	}; name PrivateRegister_##name = name(maxon::DONT_INITIALIZE)

#define PRIVATE_MAXON_OUTPUT_PORT(T, name, mtype, LOCAL, ARRAY, CNT, ...) \
	struct name : public MAXON_MACROARG_TYPE(maxon::corenodes::details::PortDefBaseCtor<name, maxon::corenodes::mtype, PRIVATE_MAXON_PORT_GET_NAME_HASHCODE(name), LOCAL, false, MAXON_EXPAND(MAXON_VA_NARGS(__VA_ARGS__)), PRIVATE_MAXON_PORT_DIMENSION_##ARRAY(CNT), CNT>) \
	{ \
		using PortDeclarationType = const T; \
		using UnannotatedPortType = typename maxon::corenodes::UnannotatedType<T>::type; \
		using PortAccessType = typename std::add_lvalue_reference<UnannotatedPortType>::type; \
		using PortIdType = maxon::corenodes::OutPortId; \
		PRIVATE_MAXON_PORT(name, ARRAY, CNT, __VA_ARGS__) \
		struct PrivateInput \
		{ \
			using MicroNodeClass = maxon::corenodes::mtype; \
			using PortDeclarationType = const T; \
			using PortAccessType = UnannotatedPortType; \
			PRIVATE_MAXON_PORT_MEMBER(name, ARRAY, CNT); \
		}; \
	}; name PrivateRegister_##name = name(maxon::DONT_INITIALIZE)


template <typename ACCESS> class PortArrayAccess
{
public:
	const Generic* PrivateGet(Int portIndex) const
	{
		return _access->GetMember(_index).value;
	}

	Bool IsNeeded() const
	{
		return !(PORT_FLAGS(_access->GetMember(_index).simd.GetFlags()) & PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue() const
	{
		return !(PORT_FLAGS(_access->GetMember(_index).simd.GetFlags()) & PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	void Init(const ACCESS& a, ACCESS_INDEX i)
	{
		_access = &a;
		_index = i;
	}

	ACCESS_INDEX PrivateGetMemberIndex() const
	{
		return _index;
	}

private:
	const ACCESS* _access;
	ACCESS_INDEX _index;
};

template <typename PORT, Int MASK, typename OWNER> struct Select
{
	using type = typename std::conditional<(Int(PORT::MicroNodeClass::MICRONODE_TYPE) & MASK) != 0, typename PORT::template Port<OWNER>, Select>::type;
	static constexpr Int COUNT = 0;
};

template <typename... PORTS> class PortMembers : public NonEmptyBases<PORTS...>
{
public:
	static constexpr Int PORTCOUNT = Sum<SFINAEHelper<PORTS, void>::type::COUNT...>::value; // SFINAEHelper needed here as workaround for MSVC bug
};

}


template <typename T> struct UnannotatedType;

namespace details
{
template <typename T> using UnannotatedTypeHelper = typename SubstituteType<T, UnannotatedType>::type;
}

template <typename T> struct UnannotatedType
{
	// We use the helper to avoid that UnannotatedType is used within itself to denote the class template UnannotatedType
	// (as argument for SubstituteType) instead of the instantiation UnannotatedType<T>. MSVC has a problem with this.
	using type = details::UnannotatedTypeHelper<T>;
};

template <typename PORT> class MicroNode::Lazy : public PORT
{
public:
	template <typename OWNER> class Port : public PORT::template Port<OWNER>
	{
	public:
#ifdef MAXON_COMPILER_MSVC
		Port(); // prevent warning C4510
#endif

		Port(const Port& src) : PORT::template Port<OWNER>(src.BeginLazy())
		{
			MicroNodeGroupInterface::PrivateEndLazy(*(PortsDescription**) &src);
		}

	private:
		const Port& BeginLazy() const
		{
			MicroNodeGroupInterface::PrivateBeginLazy(*(PortsDescription**) this);
			return *this;
		}
	};
};


/// @private
template <MicroNode::PORTSACCESS_FLAGS ACCESS_FLAGS, typename... PORTS> class MicroNode::PortsAccess
{
public:
	template <typename PORT> using MemberAccess = typename std::conditional<(Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::DIRECT_ACCESS_TEST)) != 0, corenodes::details::DirectPortAccess<PORT, PortsAccess>, corenodes::details::MappedPortAccess<PORT, PortsAccess>>::type;
	static const Int MEMBER_SIZE = (Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::DIRECT_ACCESS_TEST)) ? SIZEOF(ViewIteratorMember) : SIZEOF(void*);

	using Batch = PortsAccess<Or<PORTSACCESS_FLAGS, PORTSACCESS_FLAGS((Int) ACCESS_FLAGS & ~(Int) PORTSACCESS_FLAGS::BATCH), PORTSACCESS_FLAGS::BATCH_ACCESS>::value, PORTS...>;

	class InputMembers : public corenodes::details::PortMembers<typename corenodes::details::Select<PORTS, Int(TYPE::INPUT_MASK), PortsAccess>::type...>
	{
	public:
		using Ports = PortsAccess;

		Int GetIndex() const
		{
			return const_cast<InputMembers*>(this)->PrivateGetPortsAccess().GetIndex();
		}

		const PortsAccess& PrivateGetPortsAccess() const
		{
			return *reinterpret_cast<const PortsAccess*>(reinterpret_cast<const Char*>(static_cast<const Members*>(this)) - Access::PrivateGetMemberArrayOffset());
		}

		PortsAccess& PrivateGetPortsAccess()
		{
			return MAXON_NONCONST_COUNTERPART(PrivateGetPortsAccess());
		}

		static Int PrivateGetOffsetInMembers()
		{
			InputMembers* x = (InputMembers*) 0x5678;
			return reinterpret_cast<Char*>(x) - reinterpret_cast<Char*>(static_cast<Members*>(x));
		}
	};

	class BatchIterator;

	class NonEmptyInputMembersIteration : public InputMembers
	{
	public:
		BatchIterator begin()
		{
			return BatchIterator(this->PrivateGetPortsAccess().GetBaseData());
		}

		PRIVATE_MAXON_RBF_SENTINEL(BatchIterator) end()
		{
			return {};
		}
	};

	class OutputMembers : public corenodes::details::PortMembers<typename corenodes::details::Select<PORTS, Int(TYPE::OUTPUT_MASK), PortsAccess>::type...>
	{
	};

	class Members : public NonEmptyBases<typename std::conditional<Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::ITERATION), NonEmptyInputMembersIteration, InputMembers>::type, OutputMembers>
	{
	public:
		using Ports = PortsAccess;

		static const Int PORTCOUNT = InputMembers::PORTCOUNT + OutputMembers::PORTCOUNT;

		Int GetIndex() const
		{
			return PrivateGetPortsAccess().GetIndex();
		}

		template <typename T> const T& GetUserData() const
		{
			return PrivateGetPortsAccess().template GetUserData<T>();
		}

		const PortsAccess& PrivateGetPortsAccess() const
		{
			return *reinterpret_cast<const PortsAccess*>(reinterpret_cast<const Char*>(this) - Access::PrivateGetMemberArrayOffset());
		}

		PortsAccess& PrivateGetPortsAccess()
		{
			return MAXON_NONCONST_COUNTERPART(PrivateGetPortsAccess());
		}

		static void DescribePortAccess(PortsDescription* desc)
		{
			PortsDescription* descArray[SIZEOF(Members) / SIZEOF(PortsDescription*)];
			for (PortsDescription*& d : descArray)
			{
				d = desc;
			}
			// it's undefined behavior if we use descArray for the placement-new address too (and GCC code crashes), so use a second temporary memory
			void* tmp[SIZEOF(Members) / SIZEOF(void*)];
			new (tmp) Members(*reinterpret_cast<const Members*>(descArray));
			*reinterpret_cast<Int*>(desc) = InputMembersIteration::PrivateGetOffsetInMembers();
		}

		template <typename... LAZY> Result<void> Validate(const LAZY&... lazyPorts) const
		{
			ACCESS_INDEX portIndices[] = {lazyPorts.PrivateGetMemberIndex()...};
			return PrivateGetPortsAccess().GetBaseData().Validate(portIndices);
		}
	};

	class EmptyInputMembersIteration : private Members
	{
	public:
		using Ports = PortsAccess;

		BatchIterator begin()
		{
			return BatchIterator(this->PrivateGetPortsAccess().GetBaseData());
		}

		PRIVATE_MAXON_RBF_SENTINEL(BatchIterator) end()
		{
			return {};
		}

		static Int PrivateGetOffsetInMembers()
		{
			return 0;
		}

		using Members::GetIndex;
	};

	using InputMembersIteration = typename std::conditional<std::is_empty<NonEmptyInputMembersIteration>::value, EmptyInputMembersIteration, NonEmptyInputMembersIteration>::type;


	using Access = typename std::conditional<(Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::BATCH_ACCESS)) != 0, BatchVarAccess<Members::PORTCOUNT>,
																					 typename std::conditional<(Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::CONTAINER_MASK)) != 0, ContainerVarAccess<Members::PORTCOUNT>, VarAccess>::type>::type;

	class Iterator
	{
	public:
		template <typename ACCESS> explicit Iterator(ACCESS& access) : _access(access)
		{
		}

		Iterator() : _access(*(Access*) g_writableMemory)
		{
			static_assert(std::is_reference<decltype(_access)>::value, "Wrong constructor call.");
		}

		explicit Iterator(ENUM_DONT_INITIALIZE) : _access(DONT_INITIALIZE)
		{
		}

		Bool operator !=(const PRIVATE_MAXON_RBF_SENTINEL(Iterator)&) const
		{
			return _access.HasValues();
		}

		void operator ++()
		{
			if (ACCESS_FLAGS & PORTSACCESS_FLAGS::ITERATION)
			{
				if (!std::is_empty<OutputMembers>::value)
				{
					const Int start = reinterpret_cast<ViewIteratorMember*>(static_cast<typename std::conditional<std::is_empty<OutputMembers>::value, Members, OutputMembers>::type*>((Members*) nullptr)) - (ViewIteratorMember*) nullptr;
					_access.template Advance<false>(start, start + SIZEOF(OutputMembers) / SIZEOF(ViewIteratorMember)) iferr_cannot_fail("Caller must check bounds");
				}
			}
			else
			{
				_access.template Advance<false>() iferr_cannot_fail("Caller must check bounds");
			}
		}

		const Members& operator *() const
		{
			return *reinterpret_cast<const Members*>(_access.GetMemberArrayPointer());
		}

	private:
		typename std::conditional<(Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::BATCH_ACCESS)) != 0, Access, Access&>::type _access;
	};

	class BatchIterator : public Batch::Iterator
	{
	public:
		explicit BatchIterator(Access& access) : Batch::Iterator(access)
		{
		}

		BatchIterator() : Batch::Iterator(DONT_INITIALIZE)
		{
		}
	};

	using BeginEndIterator = typename std::conditional<(Int(ACCESS_FLAGS) & Int(PORTSACCESS_FLAGS::BATCH)) != 0, BatchIterator, Iterator>::type;

	BeginEndIterator begin()
	{
		static_assert((Int(ACCESS_FLAGS) & Int(Or<PORTSACCESS_FLAGS, PORTSACCESS_FLAGS::CONTAINER_MASK, PORTSACCESS_FLAGS::BATCH>::value)) != 0, "Range-based for loop not supported here.");
		return BeginEndIterator(_data);
	}

	PRIVATE_MAXON_RBF_SENTINEL(BeginEndIterator) end()
	{
		return {};
	}

	Int GetIndex() const
	{
		return _data.GetIndex();
	}

	Context& GetContext() const
	{
		return _data.GetContext();
	}

	template <typename T> const T& GetUserData() const
	{
		return *reinterpret_cast<const T*>(_data.GetUserData());
	}

	void PrivateTouch(ACCESS_INDEX member) const
	{
		DebugAssert((UInt) member < (UInt) Members::PORTCOUNT);
		_data.GetModified(member).Append(_data.GetIndex(), _data.GetContext());
	}

	Bool IsTimeStamped(ACCESS_INDEX member) const
	{
		DebugAssert((UInt) member < (UInt) Members::PORTCOUNT);
		return _data.IsTimeStamped(member);
	}

	PortsAccess(Context& context, const GenericContainerInterface* value) : _data(context)
	{
		Result<void> res = _data.Init(value, DataTypeLib::GetIdentityMemberMap(Members::PORTCOUNT) iferr_cannot_fail("member maps for low numbers are pre-allocated"));
		if (MAXON_UNLIKELY(res == FAILED))
			MicroNodeRuntime::AddError(res.GetError(), context);
	}

	explicit PortsAccess(const VarAccess& access) : _data(access)
	{
	}

	using Ports = PortsAccess;

	const Access& GetBaseData() const
	{
		return _data;
	}

	Access& GetBaseData()
	{
		return _data;
	}

	static void CheckAssertions()
	{
		MAXON_ASSERT_STANDARD_LAYOUT(PortsAccess);
		static_assert(SIZEOF(NonEmptyInputMembersIteration) == SIZEOF(InputMembers), "Size mismatch.");
		static_assert((std::is_empty<InputMembers>::value ? 0 : SIZEOF(InputMembers)) + (std::is_empty<OutputMembers>::value ? 0 : SIZEOF(OutputMembers)) == SIZEOF(Members), "Size mismatch.");
		static_assert(SIZEOF(EmptyInputMembersIteration) == SIZEOF(Members), "Size mismatch.");
		static_assert(MEMBER_SIZE * Members::PORTCOUNT == SIZEOF(Members), "Size mismatch.");
	}

private:
	Access _data;
};

}

} // namespace maxon

using PrivateMaxonCorenodesParentDimension = void; // has to be in global namespace so that it can always be found by the port macros

#endif // MICRONODES_PORTS_H__
