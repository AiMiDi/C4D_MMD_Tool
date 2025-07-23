#ifndef MICRONODES_PORTS_H__
#define MICRONODES_PORTS_H__

#include "maxon/corenodes.h"
#include "maxon/corenodes_errors.h"
#include "maxon/micronodes_runtime.h"

namespace maxon
{

class GenericContainerInterface;

namespace corenodes
{

//----------------------------------------------------------------------------------------
/// Defines an input port of a micro node group with the given type and name. The macro
/// has to be used within a micro node group implementation class, see MicroNodeGroupInterface
/// for a complete example.
///
/// To be accessible within the Process method of a micro node, you have to add the port
/// to the port list of the BasicMicroNode::Ports or BasicMicroNode::Batch template for the
/// Process methods's parameter. Within the method you can use two operations on the port:
/// - @c{ports.name()} returns the value of the input port.
/// - @c{ports.name.HasValue()} returns true if the port has some explicitly given value
///   (such as a default value or a value coming from a connected upstream port), false otherwise.
///
/// The following code shows the usage of MAXON_PORT_INPUT:
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
//! 		MAXON_ATTRIBUTE_FORCE_RELEASE_INLINE Result<void> Process(const Ports<input, result>& ports) const
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
/// @param[in] T									The type of the port or a MAXON_ATTRIBUTE.
/// 															In the latter case type and port id are taken from the attribute.
/// @param[in] name								The name of the port.
/// @param[in] ...								Optional MicroNode::FLAGS for the port.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_INPUT(T, name, ...) PRIVATE_MAXON_PORT_INPUT(decltype(maxon::corenodes::details::GetPortTypeWrapper<T>()), name, MAXON_STRINGIFY(name), maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))

#define MAXON_PORT_INPUT_LAMBDA(T, name) MAXON_PORT_INPUT(T, name, maxon::corenodes::MicroNode::FLAGS::WRAPPER_LAMBDA)


//----------------------------------------------------------------------------------------
/// Defines a named input port with an id that can differ from the name.
/// @see MAXON_PORT_INPUT, split name parameter into name + portId.
/// portId supports any constexpr type, hardcoded strings, attribute, LiteralId.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_INPUT_NAMED(T, name, portId, ...) PRIVATE_MAXON_PORT_INPUT(maxon::corenodes::details::PortTypeWrapper<T>, name, portId, maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))


//----------------------------------------------------------------------------------------
/// Defines an output port of a micro node group with the given type and name. The macro
/// has to be used within a micro node group implementation class, see MicroNodeGroupInterface
/// for a complete example.
///
/// To be accessible within the Process method of a micro node, you have to add the port
/// to the port list of the BasicMicroNode::Ports or BasicMicroNode::Batch template for the
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
/// The following code shows the usage of MAXON_PORT_OUTPUT:
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
//! 		MAXON_ATTRIBUTE_FORCE_RELEASE_INLINE Result<void> Process(const Ports<input, result>& ports) const
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
/// @param[in] T									The type of the port or a MAXON_ATTRIBUTE.
/// 															In the latter case type and port id are taken from the attribute.
/// @param[in] name								The name of the port.
/// @param[in] ...								Optional MicroNode::FLAGS for the port.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_OUTPUT(T, name, ...) PRIVATE_MAXON_PORT_OUTPUT(decltype(maxon::corenodes::details::GetPortTypeWrapper<T>()), name, MAXON_STRINGIFY(name), maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))


//----------------------------------------------------------------------------------------
/// Defines a named output port with an id that can differ from the name.
/// @see MAXON_PORT_INPUT, split name parameter into name + portId.
/// portId supports any constexpr type, hardcoded strings, attribute, LiteralId.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_OUTPUT_NAMED(T, name, portId, ...) PRIVATE_MAXON_PORT_OUTPUT(maxon::corenodes::details::PortTypeWrapper<T>, name, portId, maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))


//----------------------------------------------------------------------------------------
/// Defines a local output port of a micro node group with the given type and name.
/// A local port isn't exported automatically as a port of the group, instead it can only
/// be used to connect micro nodes within a group.
///
/// @param[in] T									The type of the port or a MAXON_ATTRIBUTE.
/// 															In the latter case type and port id are taken from the attribute.
/// @param[in] name								The name of the port.
/// @param[in] ...								Optional MicroNode::FLAGS for the port.
//----------------------------------------------------------------------------------------
#define MAXON_PORT_OUTPUT_LOCAL(T, name, ...) MAXON_PORT_OUTPUT(T, name, maxon::corenodes::MicroNode::FLAGS::LOCAL | maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))


namespace details
{

// Helper class for GetPortTypeWrapper.
template <typename T> struct PortTypeWrapper
{
	using ValueType = T;
	// Hacky trick to allow a simple check if a type is a PortTypeWrapper (READONLY < 0) or an attribute type (READONLY true or false).
	static constexpr Int READONLY = -1;
	// Just needed to make the compiler happy.
	static Id GetId();
};

// GetPortTypeWrapper<X>() can be called with a type T or an attribute A as X.
// This is used by MAXON_PORT_INPUT/OUTPUT to support both types and attributes for the first parameter.
template <typename T> PortTypeWrapper<T> GetPortTypeWrapper();
template <const auto& A> std::decay_t<decltype(A)> GetPortTypeWrapper();

template <typename PORT, typename OWNER> class DirectPortAccess
{
public:
	using PrivatePortAccessType = typename PORT::PortClass::PortAccessType;

	static ACCESS_INDEX PrivateGetMemberIndex()
	{
		return PORT::PrivateGetIndex();
	}

	const Generic* PrivateGet() const
	{
		MAXON_ASSERT_STANDARD_LAYOUT(DirectPortAccess);
		static_assert(SIZEOF(DirectPortAccess) == SIZEOF(ViewIteratorMember), "Wrong layout.");
		static_assert(SIZEOF(DirectPortAccess) == OWNER::MEMBER_SIZE, "Wrong layout.");
		static_assert(SIZEOF(PORT) == SIZEOF(ViewIteratorMember), "Wrong layout.");
		OWNER::CheckAssertions();
		return _it.value;
	}

	Bool IsNeeded() const
	{
		return !(CORENODE_PORT_FLAGS(_it.simd.GetFlags()) & CORENODE_PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue() const
	{
		return !(CORENODE_PORT_FLAGS(_it.simd.GetFlags()) & CORENODE_PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	Bool IsConsumable() const
	{
		return Bool(GetOwner().GetBaseData().GetFlags(PORT::PrivateGetIndex()) & PORTACCESS_FLAGS::CONSUMABLE);
	}

	const OWNER& GetOwner() const
	{
		return ((typename OWNER::Members*) (this - Int(PORT::PrivateGetIndex())))->PrivateGetPortsAccess();
	}

protected:
	DirectPortAccess() = default;

	DirectPortAccess(const DirectPortAccess& src) = delete;
	DirectPortAccess& operator =(const DirectPortAccess&) = delete;

	ViewIteratorMember _it;
};

template <typename PORT, typename OWNER> class MappedPortAccess
{
public:
	using PrivatePortAccessType = typename PORT::PortClass::PortAccessType;

	static ACCESS_INDEX PrivateGetMemberIndex()
	{
		return PORT::PrivateGetIndex();
	}

	const Generic* PrivateGet() const
	{
		return GetOwner().GetBaseData().GetMember(PORT::PrivateGetIndex()).value;
	}

	Bool IsNeeded() const
	{
		return !(CORENODE_PORT_FLAGS(GetOwner().GetBaseData().GetMember(PORT::PrivateGetIndex()).simd.GetFlags()) & CORENODE_PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue() const
	{
		return !(CORENODE_PORT_FLAGS(GetOwner().GetBaseData().GetMember(PORT::PrivateGetIndex()).simd.GetFlags()) & CORENODE_PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	Bool IsConsumable() const
	{
		return Bool(GetOwner().GetBaseData().GetFlags(PORT::PrivateGetIndex()) & PORTACCESS_FLAGS::CONSUMABLE);
	}

protected:
	const OWNER& GetOwner() const
	{
		return reinterpret_cast<const typename OWNER::Members*>(this - Int(PORT::PrivateGetIndex()))->PrivateGetPortsAccess();
	}

	MappedPortAccess() = default;

	MappedPortAccess(const MappedPortAccess& src)
	{
		MAXON_ASSERT_STANDARD_LAYOUT(MappedPortAccess);
		static_assert(SIZEOF(MappedPortAccess) == SIZEOF(void*), "Wrong layout.");
		static_assert(SIZEOF(MappedPortAccess) == OWNER::MEMBER_SIZE, "Wrong layout.");
		static_assert(SIZEOF(PORT) == SIZEOF(void*), "Wrong layout.");
		OWNER::CheckAssertions();
		MicroNodeGroupInterface::PrivateDescribePortAccess(src._description, PORT::PortClass::GetId(), PORT::PrivateGetIndex(), PORT::MODE);
	}

	MappedPortAccess& operator =(const MappedPortAccess&) = delete;

	PortAccessDescription* _description;
};

template <typename ACCESS, Bool WRITE = false> class PortOps : public ACCESS
{
public:
	using ACCESS::ACCESS;
	using Type = typename ACCESS::PrivatePortAccessType;
	static_assert(!std::is_const_v<Type> && !std::is_reference_v<Type>);

	const Type& operator ()() const
	{
		return *reinterpret_cast<const Type*>(this->PrivateGet());
	}

	template <typename T = Type> T TryMove() const
	{
		const T& x = *reinterpret_cast<const T*>(this->PrivateGet());
		if (this->IsConsumable())
		{
			return std::move(const_cast<T&>(x));
		}
		else
		{
			return x;
		}
	}
};

template <typename ACCESS> class PortOps<ACCESS, true> : public ACCESS
{
public:
	using ACCESS::ACCESS;
	using Type = typename ACCESS::PrivatePortAccessType;
	static_assert(!std::is_const_v<Type> && !std::is_reference_v<Type>);

	template <typename T2> T2& GetImpl() const
	{
		// static_assert(STD_IS_REPLACEMENT(same, T, Generic), "The function template Get may only be used when the declared port type is Generic.");
		return *reinterpret_cast<T2*>(const_cast<Generic*>(this->PrivateGet()));
	}

	Type& operator ()() const
	{
		return GetImpl<Type>();
	}

	Type& GetWritable() const
	{
		return GetImpl<Type>();
	}

	void Update(const Type& value) const
	{
		GetImpl<Type>() = value;
	}

	void Update(Type&& value) const
	{
		GetImpl<Type>() = std::move(value);
	}
};


template <typename C> class PortDef
{
public:
	using PortClass = C;

	PortDef()
	{
	}

	PortDef(const PortDef& src)
	{
		src._info->CreatePort(C::GetId(), C::MicroNodeClass::MICRONODE_TYPE, C::MICRONODE_FLAGS, GetDataType<typename C::PortDeclarationType>());
	}

protected:
	MicroNodeGroupInterface::PrivateAutoCreatePortInfo* _info;
};

template <typename T> using MyBegin = typename T::Begin;

#define PRIVATE_MAXON_PORT(W, name, portId, idtype, mtype, flags, mode, allowed) \
	using Super = maxon::corenodes::details::PortDef<name>; \
	using Super::Super; \
	using MicroNodeClass = maxon::corenodes::mtype; \
	using PortIdType = maxon::corenodes::idtype; \
	using PrivatePortTypeWrapper = W; \
	using PortDeclarationType = typename PrivatePortTypeWrapper::ValueType; \
	using PortAccessType = typename maxon::corenodes::UnannotatedType<PortDeclarationType>::type; \
	using PrivatePortClass = name; \
	static maxon::Id GetId() { if constexpr (maxon::Int(PrivatePortTypeWrapper::READONLY) < 0) return maxon::Id(portId); else return PrivatePortTypeWrapper::GetId(); } \
	static constexpr maxon::corenodes::MicroNode::FLAGS MICRONODE_FLAGS = flags; \
	static constexpr maxon::corenodes::PORT_MODE MODE = mode; \
	static constexpr maxon::corenodes::PORT_MODE ALLOWED_MODES = allowed; \
	template <typename OWNER, maxon::corenodes::PORT_MODE PM = mode> struct Port \
	{ \
		static_assert((PM & ~maxon::corenodes::PORT_MODE::MODIFIERS) != maxon::corenodes::PORT_MODE::NONE, "You can't use the port directly, it has to be qualified (e.g., with Init, Previous, Next, Reduction or Final)."); \
		static constexpr maxon::corenodes::PORT_MODE MODE = PM; \
		using PortClass = PrivatePortClass; /* we have to use PrivatePortClass instead of just 'name', otherwise the declaration of the 'name' member below would change the meaning of the name 'name' which is an error */ \
		maxon::corenodes::details::PortOps<typename OWNER::template MemberAccess<Port>, maxon::Bool(PM & maxon::corenodes::PORT_MODE::OUTPUT_FLAG)> name; \
		static maxon::corenodes::ACCESS_INDEX PrivateGetIndex() { return maxon::corenodes::ACCESS_INDEX(MAXON_OFFSETOF_NON_STANDARD_LAYOUT(typename OWNER::Members, name) / OWNER::MEMBER_SIZE); } \
	};

#define PRIVATE_MAXON_PORT_INPUT(W, name, portId, MICROFLAGS) \
	struct name : public maxon::corenodes::details::PortDef<name> \
	{ \
		PRIVATE_MAXON_PORT(W, name, portId, InPortId, VirtualInputPort, MICROFLAGS, maxon::corenodes::PORT_MODE::INPUT, \
											 maxon::corenodes::PORT_MODE::LCV_NEXT_FLAG) \
	}; name PrivateRegister_##name

#define PRIVATE_MAXON_PORT_OUTPUT(W, name, portId, MICROFLAGS) \
	struct name : public maxon::corenodes::details::PortDef<name> \
	{ \
		PRIVATE_MAXON_PORT(W, name, portId, OutPortId, VariableMicroNode, MICROFLAGS, maxon::corenodes::PORT_MODE::OUTPUT, \
											 maxon::corenodes::PORT_MODE::INPUT_FLAG) \
	}; name PrivateRegister_##name


#define PRIVATE_MAXON_PORT_LCV(W, name, portId, MICROFLAGS) \
	struct name : public maxon::corenodes::details::PortDef<name> \
	{ \
		PRIVATE_MAXON_PORT(W, name, portId, OutPortId, VariableMicroNode, maxon::corenodes::MicroNode::FLAGS::LCV | MICROFLAGS, maxon::corenodes::PORT_MODE::NONE, \
											 maxon::corenodes::PORT_MODE::OUTPUT_FLAG | maxon::corenodes::PORT_MODE::LCV_PREV_FLAG | maxon::corenodes::PORT_MODE::LCV_NEXT_FLAG | maxon::corenodes::PORT_MODE::FINAL_FLAG) \
	}; name PrivateRegister_##name

#define MAXON_PORT_LCV(T, name, ...) PRIVATE_MAXON_PORT_LCV(decltype(maxon::corenodes::details::GetPortTypeWrapper<T>()), name, MAXON_STRINGIFY(name), maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))
#define MAXON_PORT_LCV_NAMED(T, name, portId, ...) PRIVATE_MAXON_PORT_LCV(maxon::corenodes::details::PortTypeWrapper<T>, name, portId, maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))
#define MAXON_PORT_LCV_LOCAL(T, name, ...) MAXON_PORT_LCV(T, name, maxon::corenodes::MicroNode::FLAGS::LOCAL | maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))


#define PRIVATE_MAXON_PORT_REDUCTION(W, name, portId, MICROFLAGS) \
	struct name : public maxon::corenodes::details::PortDef<name> \
	{ \
		PRIVATE_MAXON_PORT(W, name, portId, OutPortId, VariableMicroNode, maxon::corenodes::MicroNode::FLAGS::REDUCTION | MICROFLAGS, maxon::corenodes::PORT_MODE::NONE, \
											 maxon::corenodes::PORT_MODE::OUTPUT_FLAG | maxon::corenodes::PORT_MODE::REDUCTION_FLAG | maxon::corenodes::PORT_MODE::FINAL_FLAG) \
	}; name PrivateRegister_##name

#define PRIVATE_MAXON_REDUCTION_PORT(T, name, mtype, MICROFLAGS) PRIVATE_MAXON_PORT_REDUCTION_NAMED(T, name, MAXON_STRINGIFY(name), mtype, MICROFLAGS)

#define MAXON_PORT_REDUCTION(T, name, ...) PRIVATE_MAXON_PORT_REDUCTION(decltype(maxon::corenodes::details::GetPortTypeWrapper<T>()), name, MAXON_STRINGIFY(name), maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))
#define MAXON_PORT_REDUCTION_NAMED(T, name, portId, ...) PRIVATE_MAXON_PORT_REDUCTION(maxon::corenodes::details::PortTypeWrapper<T>, name, portId, maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))
#define MAXON_PORT_REDUCTION_LOCAL(T, name, ...) MAXON_PORT_REDUCTION(T, name, maxon::corenodes::MicroNode::FLAGS::LOCAL | maxon::corenodes::MicroNode::FLAGS(__VA_ARGS__))

template <typename T, typename ACCESS> class PortArrayAccess
{
public:
	using PrivatePortAccessType = T;

	PortArrayAccess(const ACCESS& a, ACCESS_INDEX i) : _access(a), _index(i)
	{
	}

	const Generic* PrivateGet() const
	{
		return _access.GetMember(_index).value;
	}

	Bool IsNeeded() const
	{
		return !(CORENODE_PORT_FLAGS(_access.GetMember(_index).simd.GetFlags()) & CORENODE_PORT_FLAGS::OUTPUT_UNUSED);
	}

	Bool HasValue() const
	{
		return !(CORENODE_PORT_FLAGS(_access.GetMember(_index).simd.GetFlags()) & CORENODE_PORT_FLAGS::INPUT_WITHOUT_VALUE);
	}

	Bool IsConsumable() const
	{
		return Bool(_access.GetFlags(_index) & PORTACCESS_FLAGS::CONSUMABLE);
	}

	ACCESS_INDEX PrivateGetMemberIndex() const
	{
		return _index;
	}

private:
	const ACCESS& _access;
	const ACCESS_INDEX _index;
};

template <typename PORT, PORT_MODE MODE, typename OWNER> struct Select
{
	using type = std::conditional_t<(PORT::MODE & (PORT_MODE::INPUT_FLAG | PORT_MODE::REDUCTION_FLAG)) == MODE,
																	typename PORT::template Port<OWNER>,
																	EmptyClass>;
};


template <typename... PORTS> class PortMembers : public NonEmptyBases<PORTS...>
{
public:
	static constexpr Int PORTCOUNT = Sum<!std::is_empty_v<PORTS>...>::value;
};


template <PORTS_MODE M> struct PortsMode
{
	static constexpr PORTS_MODE MODE = M;
};

template <PORTS_MODE MODE, typename... PORTS> struct PortsAccessHelper
{
	using type = MicroNode::PortsAccess<MODE, PORTS...>;
};

template <PORTS_MODE MODE, PORTS_MODE MODE2, typename... PORTS> struct PortsAccessHelper<MODE, PortsMode<MODE2>, PORTS...>
{
	using type = MicroNode::PortsAccess<MODE2 | (MODE & PORTS_MODE::VARIADIC), PORTS...>;
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
			MicroNodeGroupInterface::PrivateEndLazy(*(PortAccessDescription**) &src);
		}

	private:
		const Port& BeginLazy() const
		{
			MicroNodeGroupInterface::PrivateBeginLazy(*(PortAccessDescription**) this);
			return *this;
		}
	};
};

/// @private
template <PORTS_MODE PMODE, typename... PORTS> class MicroNode::PortsAccess
{
public:
	template <typename PORT> using MemberAccess = typename std::conditional<Bool(PMODE & PORTS_MODE::DIRECT), corenodes::details::DirectPortAccess<PORT, PortsAccess>, corenodes::details::MappedPortAccess<PORT, PortsAccess>>::type;
	static constexpr Int MEMBER_SIZE = (PMODE & PORTS_MODE::DIRECT) ? SIZEOF(ViewIteratorMember) : SIZEOF(void*);

	static constexpr PORTS_MODE MODE = PMODE;
	using AsBatch = PortsAccess<(PMODE & ~PORTS_MODE::DIRECT) | PORTS_MODE::BATCH, PORTS...>;
	using AsDirect = PortsAccess<(PMODE & ~PORTS_MODE::BATCH) | PORTS_MODE::DIRECT, PORTS...>;

	template <Bool REF> class Iterator;

	class InputMembers : public corenodes::details::PortMembers<typename corenodes::details::Select<PORTS, PORT_MODE::INPUT_FLAG, PortsAccess>::type...>
	{
	public:
		using Ports = PortsAccess;

		MAXON_ATTRIBUTE_FORCE_INLINE Int GetIndex() const
		{
			return PrivateGetPortsNonConstAccess().GetIndex();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE const PortsAccess& PrivateGetPortsAccess() const
		{
			if constexpr (InputMembers::PORTCOUNT == 0)
			{
				return *reinterpret_cast<const PortsAccess*>(this);
			}
			else
			{
				return *reinterpret_cast<const PortsAccess*>(reinterpret_cast<const Char*>(static_cast<const Members*>(this)) - Access::PrivateGetMemberArrayOffset());
			}
		}

		MAXON_ATTRIBUTE_FORCE_INLINE PortsAccess& PrivateGetPortsAccess()
		{
			return MAXON_NONCONST_COUNTERPART(PrivateGetPortsAccess());
		}

		/// For non-const PortAccess read, useful for manual access to output port value pointers when not used named ports.
		/// I.e. when not using the port name from MAXON_PORT_OUTPUT macro to access values.
		/// @code
		/// // Normal port access for writing:
		/// ports.portname() = newPortValue;
		/// // Manual non-const access:
		/// auto& genericPortValue = *ports.PrivateGetPortsNonConstAccess().GetBaseData().GetMemberValue(corenodes::ACCESS_INDEX(0));
		/// @endcode
		MAXON_ATTRIBUTE_FORCE_INLINE PortsAccess& PrivateGetPortsNonConstAccess() const
		{
			return const_cast<InputMembers*>(this)->PrivateGetPortsAccess();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE const Context& GetContext() const
		{
			return PrivateGetPortsAccess().GetContext();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE static InputMembers& PrivateFromVarAccess(VarAccess& access)
		{
			if constexpr (InputMembers::PORTCOUNT == 0)
			{
				return reinterpret_cast<InputMembers&>(access);
			}
			else
			{
				return reinterpret_cast<Members&>(access);
			}
		}

		using BatchIterator = typename AsDirect::template Iterator<false>;

		BatchIterator Begin()
		{
			static_assert(Bool(PMODE & PORTS_MODE::ITERATION), "Range-based for loop not supported here.");
			return BatchIterator(PrivateGetPortsAccess().GetBaseData());
		}

		PRIVATE_MAXON_RBF_SENTINEL(BatchIterator) End()
		{
			return {};
		}
	};

	class OutputMembers : public corenodes::details::PortMembers<typename corenodes::details::Select<PORTS, PORT_MODE::NONE, PortsAccess>::type...>
	{
	};

	class ReductionMembers : public corenodes::details::PortMembers<typename corenodes::details::Select<PORTS, PORT_MODE::REDUCTION_FLAG, PortsAccess>::type...>
	{
	public:
		using Ports = PortsAccess;

		MAXON_ATTRIBUTE_FORCE_INLINE Int GetIndex() const
		{
			return PrivateGetPortsNonConstAccess().GetIndex();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE const PortsAccess& PrivateGetPortsAccess() const
		{
			if constexpr (ReductionMembers::PORTCOUNT == 0)
			{
				return *reinterpret_cast<const PortsAccess*>(this);
			}
			else
			{
				return *reinterpret_cast<const PortsAccess*>(reinterpret_cast<const Char*>(static_cast<const Members*>(this)) - Access::PrivateGetMemberArrayOffset());
			}
		}

		MAXON_ATTRIBUTE_FORCE_INLINE PortsAccess& PrivateGetPortsAccess()
		{
			return MAXON_NONCONST_COUNTERPART(PrivateGetPortsAccess());
		}

		/// For non-const PortAccess read, useful for manual access to output port value pointers when not used named ports.
		/// I.e. when not using the port name from MAXON_PORT_OUTPUT macro to access values.
		/// @code
		/// // Normal port access for writing:
		/// ports.portname() = newPortValue;
		/// // Manual non-const access:
		/// auto& genericPortValue = *ports.PrivateGetPortsNonConstAccess().GetBaseData().GetMemberValue(corenodes::ACCESS_INDEX(0));
		/// @endcode
		MAXON_ATTRIBUTE_FORCE_INLINE PortsAccess& PrivateGetPortsNonConstAccess() const
		{
			return const_cast<ReductionMembers*>(this)->PrivateGetPortsAccess();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE const Context& GetContext() const
		{
			return PrivateGetPortsAccess().GetContext();
		}

		Result<Bool> AddMessage(const Error& msg, const Id& portId = GetZeroRef<Id>()) const
		{
			return PrivateGetPortsAccess().AddMessage(msg, portId);
		}

		MAXON_ATTRIBUTE_FORCE_INLINE static ReductionMembers& PrivateFromVarAccess(VarAccess& access)
		{
			if constexpr (ReductionMembers::PORTCOUNT == 0)
			{
				return reinterpret_cast<ReductionMembers&>(access);
			}
			else
			{
				return reinterpret_cast<Members&>(access);
			}
		}

		using BatchIterator = typename AsDirect::template Iterator<false>;

		BatchIterator Begin()
		{
			static_assert(Bool(PMODE & PORTS_MODE::BATCH), "Range-based for loop not supported here.");
			return BatchIterator(PrivateGetPortsAccess().GetBaseData());
		}

		PRIVATE_MAXON_RBF_SENTINEL(BatchIterator) End()
		{
			return {};
		}

		typename AsDirect::template Iterator<true> Begin(DirectVarAccess<>* access)
		{
			static_assert(Bool(PMODE & PORTS_MODE::BATCH), "Range-based for loop not supported here.");
			return typename AsDirect::template Iterator<true>(*access);
		}
	};

	class Members : public NonEmptyBases<InputMembers, OutputMembers, ReductionMembers>
	{
	public:
		using Ports = PortsAccess;

		static constexpr Int PORTCOUNT = InputMembers::PORTCOUNT + OutputMembers::PORTCOUNT + ReductionMembers::PORTCOUNT;

		Int GetIndex() const
		{
			return PrivateGetPortsAccess().GetIndex();
		}

		Int GetCount() const
		{
			return PrivateGetPortsAccess().GetCount();
		}

		const Context& GetContext() const
		{
			return PrivateGetPortsAccess().GetContext();
		}

		Result<Bool> AddMessage(const Error& msg, const Id& portId = GetZeroRef<Id>()) const
		{
			return PrivateGetPortsAccess().AddMessage(msg, portId);
		}

		Result<void> AddRuntimeMessage(MAXON_SOURCE_LOCATION_DECLARATION, ErrorInterface::MessageDelegate&& msgDel, const Id& portId = GetZeroRef<Id>()) const
		{
			RuntimeMessage msg{MAXON_SOURCE_LOCATION_FORWARD};
			msg.SetMessageDelegate(std::move(msgDel));
			return AddMessage(msg, portId);
		}

		const PortsAccess& PrivateGetPortsAccess() const
		{
			return *reinterpret_cast<const PortsAccess*>(reinterpret_cast<const Char*>(this) - Access::PrivateGetMemberArrayOffset());
		}

		PortsAccess& PrivateGetPortsAccess()
		{
			return MAXON_NONCONST_COUNTERPART(PrivateGetPortsAccess());
		}

		MAXON_ATTRIBUTE_FORCE_INLINE static const Members& PrivateFromVarAccess(VarAccess& access)
		{
			return reinterpret_cast<Members&>(access);
		}

		static void DescribePortAccess(PortAccessDescription* desc)
		{
			constexpr Int PTRSIZE = (SIZEOF(Members) + SIZEOF(void*) - 1) / SIZEOF(void*);
			PortAccessDescription* descArray[PTRSIZE];
			for (PortAccessDescription*& d : descArray)
			{
				d = desc;
			}
			// it's undefined behavior if we use descArray for the placement-new address too (and GCC code crashes), so use a second temporary memory
			void* tmp[PTRSIZE];
			new (tmp) Members(*reinterpret_cast<const Members*>(descArray));
		}

		template <typename... LAZY> Result<void> Validate(const LAZY&... lazyPorts) const
		{
			ACCESS_INDEX portIndices[] = {lazyPorts.PrivateGetMemberIndex()...};
			return PrivateGetPortsAccess().GetBaseData().Validate(portIndices);
		}
	};

	using Access = std::conditional_t<Bool(PMODE & PORTS_MODE::DIRECT),
																		DirectVarAccess<(PMODE & PORTS_MODE::VARIADIC) ? -1 : Members::PORTCOUNT>,
																		VarAccess>;

	template <Bool REF> class Iterator
	{
	public:
		static_assert(PMODE & PORTS_MODE::DIRECT);

		explicit Iterator(const VarAccess& access) : _access(access)
		{
			static_assert(!(PMODE & PORTS_MODE::VARIADIC));
		}

		explicit Iterator(Access& access) : _access(access)
		{
		}

#ifndef _HAS_RANGE_BASED_FOR_DIFFERING_TYPES
		Iterator() : _access(GetZeroRef<VarAccess>())
		{
		}
#endif

		explicit operator Bool() const
		{
			return _access.HasValues();
		}

		Bool operator !=(const PRIVATE_MAXON_RBF_SENTINEL(Iterator)&) const
		{
			return _access.HasValues();
		}

		void operator ++()
		{
			if constexpr (PMODE & PORTS_MODE::ITERATION)
			{
				if constexpr ((PMODE & PORTS_MODE::VARIADIC) || (Members::PORTCOUNT > InputMembers::PORTCOUNT))
				{
					// In the Iteration case InputMembers don't change in a batch.
					_access.template Advance<false>(InputMembers::PORTCOUNT, GetMemberCount()) iferr_cannot_fail("Caller must check bounds");
				}
			}
			else
			{
				// ReductionMembers have to be advanced as well for the rare case of a reduction of a single non-looped value within a loop.
				_access.template Advance<false>(0, GetMemberCount()) iferr_cannot_fail("Caller must check bounds");
			}
		}

		const Members& operator *() const
		{
			return *reinterpret_cast<const Members*>(_access.GetMemberArrayPointer());
		}

		Int GetMemberCount() const
		{
			if constexpr (PMODE & PORTS_MODE::VARIADIC)
				return _access.GetMemberCount();
			else
				return Members::PORTCOUNT;
		}

	private:
		std::conditional_t<REF, Access&, Access> _access;
	};

	Int GetIndex() const
	{
		return _data.GetIndex();
	}

	Int GetCount() const
	{
		return _data.GetCount();
	}

	const Context& GetContext() const
	{
		return _data.GetContext();
	}

	Result<Bool> AddMessage(const Error& msg, const Id& portId = GetZeroRef<Id>()) const
	{
		return MicroNodeRuntime::AddMessage(msg, portId, GetContext(), _data.GetMicroNodeContext());
	}

	Result<void> AddRuntimeMessage(MAXON_SOURCE_LOCATION_DECLARATION, ErrorInterface::MessageDelegate&& msgDel, const Id& portId = GetZeroRef<Id>()) const
	{
		RuntimeMessage msg{MAXON_SOURCE_LOCATION_FORWARD};
		msg.SetMessageDelegate(std::move(msgDel));
		return AddMessage(msg, portId);
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
		static_assert(!((PMODE & PORTS_MODE::BATCH)
										&& ((PORT_MODE::NONE | ... | PORTS::MODE) & (PORT_MODE::LCV_PREV_FLAG | PORT_MODE::LCV_NEXT_FLAG))),
									"LCV previous/next access can't be used in a Batch.");
		MAXON_ASSERT_STANDARD_LAYOUT(PortsAccess);
		static_assert((STD_IS_REPLACEMENT(empty, InputMembers) ? 0 : SIZEOF(InputMembers))
									+ (STD_IS_REPLACEMENT(empty, OutputMembers) ? 0 : SIZEOF(OutputMembers))
									+ (STD_IS_REPLACEMENT(empty, ReductionMembers) ? 0 : SIZEOF(ReductionMembers)) == SIZEOF(Members), "Size mismatch.");
		static_assert(MEMBER_SIZE * Members::PORTCOUNT == SIZEOF(Members), "Size mismatch.");
	}

private:
	Access _data;
};

using maxon::begin;
using maxon::end;


/// Id prefix for internal ports which shall not be visible.
/// @markPrivate
static constexpr Char g_internalPortPrefix = '.';

/// Separator for identifiers of variadic port instances, separates between port id and instance id.
/// @markPrivate
static constexpr Char g_variadicPortIdSeparator = '#';

}

} // namespace maxon

#endif // MICRONODES_PORTS_H__
