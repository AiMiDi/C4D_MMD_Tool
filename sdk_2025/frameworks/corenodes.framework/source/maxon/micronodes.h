#ifndef MICRONODES_H__
#define MICRONODES_H__

#include "maxon/micronodes_ports.h"
#include "maxon/stackalloc.h"

#ifdef MAXON_TARGET_WINDOWS
// Required for alloca()
#include <malloc.h>
#endif

namespace maxon
{

namespace corenodes
{

namespace details
{

using ProcessFunction = Result<void>(*)(const MicroNode*, VarAccess&);

template <typename MT, typename MODE> struct ProcessWrapper
{
	static ProcessFunction Get(MicroNode::Base& node)
	{
		static_assert(AlwaysFalse<MT>::value, "Wrong signature of Process method.");
		return nullptr;
	}
};

// MODE is either void (MN has a non-template Process method)
// or PortsMode<M> (MN has a Process method template which shall be instantiated in mode M).
template <typename MN, typename MODE, typename PORTS> struct ProcessWrapper<Result<void> (MN::*) (PORTS&) const, MODE>
{
	using Param = PORTS;
	using ImplParam = typename MN::template ProcessParamType<PORTS>;

	static MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Invoke(const MicroNode* node, PORTS& arg)
	{
		if constexpr (std::is_void_v<MODE>)
		{
			return static_cast<const MN*>(node)->Process(arg);
		}
		else
		{
			// Verify that Process method respects the MODE given as template parameter.
			static_assert(!((MODE::MODE ^ PORTS::Ports::MODE) & ~PORTS_MODE::MODIFIERS), "You forgot the MODE template parameter as first template argument of Ports<MODE, ...>.");
			return static_cast<const MN*>(node)->template Process<MODE>(arg);
		}
	}

	static Result<void> Impl(const MicroNode* node, VarAccess& access)
	{
		if constexpr (ImplParam::ADD_BATCH_LOOP)
		{
			iferr_scope;
			if constexpr (ImplParam::type::Ports::MODE & PORTS_MODE::VARIADIC)
			{
				// With variadic ports we don't know the number of ports at compile-time,
				// so we have to dynamically allocate memory for them and can't use the range-based for loop.
				void* mem = alloca(DirectVarAccess<>::GetSize(access.GetMemberCount()));
				DirectVarAccess<>* a = new (mem) DirectVarAccess<>(access);
				auto it = ImplParam::type::PrivateFromVarAccess(access).Begin(a);
				while (it)
				{
					Invoke(node, *it) iferr_return;
					++it;
				}
			}
			else
			{
				for (const PORTS& p : ImplParam::type::PrivateFromVarAccess(access))
				{
					Invoke(node, p) iferr_return;
				}
			}
			return OK;
		}
		else
		{
			return Invoke(node, ImplParam::type::PrivateFromVarAccess(access));
		}
	}

	static ProcessFunction Get(MicroNode::Base& node)
	{
		node._portAccessDesc = &ImplParam::type::Ports::Members::DescribePortAccess;
		node._nextFreeAccessIndex = ACCESS_INDEX(ImplParam::type::Ports::Members::PORTCOUNT);
		return &Impl;
	}
};


template <typename MN, typename = void> struct HasProcessMethodTemplate
{
	static constexpr Bool value = false;
};

template <typename MN> struct HasProcessMethodTemplate<MN, typename SFINAEHelper<void, decltype(&MN::template Process<PortsMode<PORTS_MODE::NONE>>)>::type>
{
	static constexpr Bool value = true;
};


using InitUserDataFn = Result<void>(*)(const MicroNode::Base*, GenericData& data, const Block<const DataType>&);

template <typename MN, typename MT, MT METHOD, typename T> static Result<void> InvokeInitUserData(const MicroNode::Base* node, GenericData& data, const Block<const DataType>& types)
{
	iferr_scope;
	T userData = (node->To<MN>().*METHOD)(types) iferr_return;
	data.Set(std::move(userData)) iferr_return;
	return OK;
}

template <typename MN, typename MT, MT METHOD, typename T> static InitUserDataFn GetInitUserData(Result<T> (MN::*) (const Block<const DataType>&) const, MicroNode::Base& node)
{
	return &InvokeInitUserData<MN, MT, METHOD, T>;
}

template <typename MN, typename MT, MT METHOD> static InitUserDataFn GetInitUserData(void (*) (), MicroNode::Base&)
{
	return nullptr;
}


using GetLlvmAssemblyFn = Result<CString>(*)(const MicroNode::Base*, const LlvmGlobalsReceiver& globals);

template <typename MN, typename MT, MT METHOD> static Result<CString> InvokeGetLlvmAssembly(const MicroNode::Base* node, const LlvmGlobalsReceiver& globals)
{
	return (node->To<MN>().*METHOD)(globals);
}

template <typename MN, typename MT, MT METHOD> static GetLlvmAssemblyFn GetGetLlvmAssembly(Result<CString> (MN::*) (const LlvmGlobalsReceiver&) const, MicroNode::Base& node)
{
	return &InvokeGetLlvmAssembly<MN, MT, METHOD>;
}

template <typename MN, typename MT, MT METHOD> static GetLlvmAssemblyFn GetGetLlvmAssembly(void (*) (const LlvmGlobalsReceiver&), MicroNode::Base&)
{
	return nullptr;
}

template <typename MN, typename MT, MT METHOD> static GetLlvmAssemblyFn GetGetLlvmAssembly(void (MN::*) (const LlvmGlobalsReceiver&) const, MicroNode::Base&)
{
	return nullptr;
}

}

#define PRIVATE_MAXON_MICRONODE(C, MNTYPE) \
	public: \
		using MicroNodeClass = C; \
		static constexpr TYPE MICRONODE_TYPE = TYPE::MNTYPE; \
		Base _base

#define PRIVATE_MAXON_BUILTIN_MICRONODE(C, MNTYPE) \
	PRIVATE_MAXON_MICRONODE(C, MNTYPE); \
	template <typename MN> void PrivateInit() \
	{ \
		PRIVATE_MAXON_MICRONODE_INIT; \
	}


#define PRIVATE_MAXON_MICRONODE_INIT \
	MAXON_CHECK_CLASS(MicroNodeClass); \
	MAXON_ASSERT_STANDARD_LAYOUT(MicroNodeClass); \
	_base._node = nullptr; \
	_base._type = MICRONODE_TYPE; \
	_base._flags = MN::MICRONODE_FLAGS; \
	_base._free = reinterpret_cast<void(*)(const MicroNode*)>(&DeleteConstPtrObj<MN>); \
	static_assert(offsetof(MicroNodeClass, _base) == 0, "Wrong layout of micro node implementation class.")


#define PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA corenodes::details::InitUserDataFn _fInitUserData
#define PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA_INIT _fInitUserData = corenodes::details::GetInitUserData<MN, decltype(&MN::InitUserData), &MN::InitUserData>(&MN::InitUserData, _base)

#define PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE corenodes::details::GetLlvmAssemblyFn _fGetLlvmAssembly
#define PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE_INIT _fGetLlvmAssembly = corenodes::details::GetGetLlvmAssembly<MN, decltype(&MN::GetLlvmAssembly), &MN::GetLlvmAssembly>(&MN::GetLlvmAssembly, _base)



class VirtualInputPort
{
public:
	static constexpr MicroNode::TYPE MICRONODE_TYPE = MicroNode::TYPE::VIRTUAL_INPUT_PORT;
	static constexpr MicroNode::FLAGS MICRONODE_FLAGS = MicroNode::FLAGS::NONE;
};


class VariableMicroNode final : public MicroNode
{
	PRIVATE_MAXON_BUILTIN_MICRONODE(VariableMicroNode, VARIABLE);
};



//----------------------------------------------------------------------------------------
/// BasicMicroNode is the base class for custom micro nodes. A BasicMicroNode receives
/// input values in its Process method and computes the corresponding output values.
///
/// To implement a BasicMicroNode, you have to derive a new class from BasicMicroNode and add
/// a Process method. There are three possible flavors of the Process method:
/// 1. The simplest one is best when the Process method is complex enough
///    that the overhead of calling the Process method is negligible. The Process method
///    has a single @c{const Ports<...>&} parameter with a list of those ports between the angular brackets
///    which shall be accessed by the node. The ports have to be defined by MAXON_PORT macros in a micro node group class.
///    Usually the BasicMicroNode class is a member of that micro node group class as in this example:
///    @code{corenodes_micronodegroup_basic}
///    @endcode
/// 2. When the Process method consists of just a few simple operations, the calling overhead of nodes is significant.
///    By turning the Process method into a template with a MODE template parameter, the compiler can instantiate
///    variants of the Process method which are optimized for different cases (e.g., for the case of just a single
///    set of values, or for the case of a batch of values). The parameter of the Process method
///    has to be of type @c{const Ports<MODE, ...>&}.
///    @code{corenodes_micronodegroup_template}
///    @endcode
/// 3. The previous flavor makes an implicit loop over the Process method to deal with batches. But you can also
///    do this yourself, just use @c{Batch<...>&)} as parameter and do a for loop within the method. This allows to
///    have some code before the loop.
///    @code{corenodes_micronodegroup_batch}
///    @endcode
///
/// There is the helper class OperatorNode to simplify the implementation of a core node class
/// consisting of a single BasicMicroNode. And if you want to implement a core node for an existing C++ function or operator
/// (as in the example with the + operator) you can also use one of the macros
/// MAXON_CORENODE_FUNCTION, MAXON_CORENODE_OPERATOR_UNARY and MAXON_CORENODE_OPERATOR_BINARY.
//----------------------------------------------------------------------------------------
class BasicMicroNode : public MicroNode
{
	PRIVATE_MAXON_MICRONODE(BasicMicroNode, BASIC);

public:
	template <typename... PORTS> using Ports = typename corenodes::details::PortsAccessHelper<PORTS_MODE::NONE, PORTS...>::type::Members;

	template <typename... PORTS> using Batch = typename corenodes::details::PortsAccessHelper<PORTS_MODE::BATCH, PORTS...>::type::ReductionMembers;

	template <typename PORTS> struct ProcessParamType
	{
		static constexpr Bool ADD_BATCH_LOOP = Bool(PORTS::Ports::MODE & PORTS_MODE::DIRECT);
		using type = std::conditional_t<ADD_BATCH_LOOP, typename PORTS::Ports::AsBatch::ReductionMembers, PORTS>;

		static_assert(!(PORTS::Ports::MODE & PORTS_MODE::BATCH) || !std::is_const<PORTS>::value, "The parameter of the Process method needs to be non-const.");
		static_assert((PORTS::Ports::MODE & PORTS_MODE::BATCH) || std::is_const<PORTS>::value, "The parameter of the Process method needs to be const.");
	};

	corenodes::details::ProcessFunction _fProcessSingle;
	corenodes::details::ProcessFunction _fProcessBatch;

	PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA;
	PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE;

	template <typename MN> void PrivateInit()
	{
		if constexpr (corenodes::details::HasProcessMethodTemplate<MN>::value)
		{
			using WrapperSingle = corenodes::details::ProcessWrapper<decltype(&MN::template Process<corenodes::details::PortsMode<PORTS_MODE::NONE>>), corenodes::details::PortsMode<PORTS_MODE::NONE>>;
			static_assert(!(WrapperSingle::Param::Ports::MODE & (PORTS_MODE::DIRECT | PORTS_MODE::ITERATION)));
			_fProcessSingle = WrapperSingle::Get(_base);

			using WrapperBatch = corenodes::details::ProcessWrapper<decltype(&MN::template Process<corenodes::details::PortsMode<PORTS_MODE::DIRECT>>), corenodes::details::PortsMode<PORTS_MODE::DIRECT>>;
			static_assert(!(WrapperSingle::Param::Ports::MODE & (PORTS_MODE::BATCH | PORTS_MODE::ITERATION)));
			_fProcessBatch = WrapperBatch::Get(_base);
		}
		else
		{
			using Wrapper = corenodes::details::ProcessWrapper<decltype(&MN::Process), void>;
			static_assert(!(Wrapper::Param::Ports::MODE & (PORTS_MODE::DIRECT | PORTS_MODE::ITERATION)));
			_fProcessSingle = Wrapper::Get(_base);
			if constexpr (Wrapper::Param::Ports::MODE & PORTS_MODE::BATCH)
			{
				_fProcessBatch = _fProcessSingle;
			}
			else
			{
				_fProcessBatch = nullptr;
			}
		}
		PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA_INIT;
		PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE_INIT;
		PRIVATE_MAXON_MICRONODE_INIT;
	}
};


class VariadicBasicMicroNode : public BasicMicroNode
{
public:
	template <typename... PORTS> using Ports = typename corenodes::details::PortsAccessHelper<PORTS_MODE::NONE | PORTS_MODE::VARIADIC, PORTS...>::type::Members;

	template <typename... PORTS> using Batch = typename corenodes::details::PortsAccessHelper<PORTS_MODE::BATCH | PORTS_MODE::VARIADIC, PORTS...>::type::ReductionMembers;
};


template <typename MICRONODE> class Uninitialized : public MICRONODE
{
public:
	static constexpr MicroNode::FLAGS MICRONODE_FLAGS = MICRONODE::MICRONODE_FLAGS | MicroNode::FLAGS::UNINITIALIZED;
};

}

} // namespace maxon

#endif // MICRONODES_H__
