#ifndef MICRONODES_H__
#define MICRONODES_H__

#include "maxon/micronodes_ports.h"

namespace maxon
{

namespace corenodes
{

namespace details
{

template <typename MN, typename PORTS, typename... ARGS> class MethodWrapper
{
public:
	template <Result<void> (MN::* METHOD) (PORTS&, ARGS...) const> static Result<void> Invoke(const MicroNode* self, const void* ports, ARGS... args)
	{
		return (static_cast<const MN*>(self)->*METHOD)(*(PORTS*) ports, args...);
	}
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
		static const TYPE MICRONODE_TYPE = TYPE::MNTYPE; \
		Base _base

#define PRIVATE_MAXON_BUILTIN_MICRONODE(C, MNTYPE) \
	PRIVATE_MAXON_MICRONODE(C, MNTYPE); \
public: \
	template <typename MN> void PrivateInit() \
	{ \
		PRIVATE_MAXON_MICRONODE_INIT; \
	}

#define PRIVATE_MAXON_MICRONODE_METHOD_1 ,

#define PRIVATE_MAXON_MICRONODE_METHOD(name, N, ...) \
		using name##Fn = Result<void>(*)(const MicroNode*, const void*, ##__VA_ARGS__); \
	private: \
		template <typename MN, typename MT, MT METHOD, typename PORTS> static name##Fn Get##name##Fn(Result<void> (MN::*) (PORTS&, ##__VA_ARGS__) const, MicroNode::Base& node) \
		{ \
			node._portsDesc = &PORTS::Ports::Members::DescribePortAccess; \
			node._nextFreeAccessIndex = ACCESS_INDEX(PORTS::Ports::Members::PORTCOUNT); \
			return &corenodes::details::MethodWrapper<MN, PORTS, ##__VA_ARGS__>::template Invoke<METHOD>; \
		} \
		template <typename MN, typename MT, MT METHOD> static name##Fn Get##name## Fn(void (*) (), MicroNode::Base&) \
		{ \
			return nullptr; \
		} \
	public: \
		MAXON_SECONDARG(PRIVATE_MAXON_MICRONODE_METHOD_##N, template <typename PORTMODE>) static void name() { } \
		name##Fn _f##name[N]

#define PRIVATE_MAXON_MICRONODE_METHOD_INIT_HELPER(i, name, tname) \
	_f##name[i] = Get##name##Fn<MN, decltype(&MN::tname), &MN::tname>(&MN::tname, _base)

#define PRIVATE_MAXON_MICRONODE_METHOD_INIT_A(PORTMODE, i, name) PRIVATE_MAXON_MICRONODE_METHOD_INIT_HELPER(i, name, template name<PORTMODE>)

#define PRIVATE_MAXON_MICRONODE_METHOD_INIT(name, ...) \
	MAXON_MAKE_LIST(PRIVATE_MAXON_MICRONODE_METHOD_INIT_A, name, ;, (PRIVATE_MAXON_MICRONODE_METHOD_INIT_HELPER(0, name, name)), __VA_ARGS__)

#define PRIVATE_MAXON_MICRONODE_INIT \
	MAXON_CHECK_CLASS(MicroNodeClass); \
	MAXON_ASSERT_STANDARD_LAYOUT(MicroNodeClass); \
	_base._node = nullptr; \
	_base._type = MICRONODE_TYPE; \
	_base._flags = MN::MICRONODE_FLAGS; \
	_base._free = reinterpret_cast<void(*)(const MicroNode*)>(&DeleteConstPtrObj<MN>);


#define PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA corenodes::details::InitUserDataFn _fInitUserData
#define PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA_INIT _fInitUserData = corenodes::details::GetInitUserData<MN, decltype(&MN::InitUserData), &MN::InitUserData>(&MN::InitUserData, _base)

#define PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE corenodes::details::GetLlvmAssemblyFn _fGetLlvmAssembly
#define PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE_INIT _fGetLlvmAssembly = corenodes::details::GetGetLlvmAssembly<MN, decltype(&MN::GetLlvmAssembly), &MN::GetLlvmAssembly>(&MN::GetLlvmAssembly, _base)



class VariableBase : public MicroNode
{
public:
	template <typename T> class AllowsParent : public std::false_type { };
	template <typename T> using AllowsChild = std::false_type;
};


class VirtualInputPort
{
public:
	static const MicroNode::TYPE MICRONODE_TYPE = MicroNode::TYPE::VIRTUAL_INPUT_PORT;
	static const MicroNode::FLAGS MICRONODE_FLAGS = MicroNode::FLAGS::NONE;
};


class VariableMicroNode final : public VariableBase
{
	PRIVATE_MAXON_MICRONODE(VariableMicroNode, VARIABLE);
public:
	static const WIRETYPE IS_TARGET_OF = WIRETYPE::DOMAIN_FLOW_VALUE_SEQUENCED;
	static const WIRETYPE IS_SOURCE_OF = WIRETYPE::DOMAIN_FLOW_PURE_VALUE_SEQUENCED_LIFETIME | WIRETYPE::ALIAS | WIRETYPE::MARK;

	template <typename MN> void PrivateInit()
	{
		PRIVATE_MAXON_MICRONODE_INIT;
	}
};



//----------------------------------------------------------------------------------------
/// BasicMicroNode is the base class for simple custom micro nodes. A BasicMicroNode receives
/// a single set of input values in its Process method and computes the corresponding output values.
/// If the Process method consists of just a few simple operations, you should consider to
/// implement a BatchMicroNode instead: It computes the output values for a whole batch
/// of input values with a single call, so this reduces the calling overhead of nodes.
///
/// To implement a BasicMicroNode, you have to derive a new class from BasicMicroNode and add
/// a Process method to that class which has a @c{const Ports<...>&} parameter with a list
/// of those ports between the angular brackets which shall be accessed by the node.
/// The ports have to be defined by MAXON_PORT macros in a micro node group class.
/// Usually the BasicMicroNode class is a member of that micro node group class as in this example:
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
//----------------------------------------------------------------------------------------
class BasicMicroNode : public MicroNode
{
	PRIVATE_MAXON_MICRONODE(BasicMicroNode, BASIC);

public:
	static const WIRETYPE IS_TARGET_OF = WIRETYPE::DOMAIN_FLOW_SEQUENCED | WIRETYPE::PORT;
	static const WIRETYPE IS_SOURCE_OF = WIRETYPE::DOMAIN_FLOW_SEQUENCED | WIRETYPE::PORT;

	PRIVATE_MAXON_MICRONODE_METHOD(Process, 1);
	PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA;
	PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE;

	template <typename MN> void PrivateInit()
	{
		PRIVATE_MAXON_MICRONODE_METHOD_INIT(Process);
		PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA_INIT;
		PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE_INIT;
		PRIVATE_MAXON_MICRONODE_INIT;
	}
};


//----------------------------------------------------------------------------------------
/// BatchMicroNode is the base class for custom micro nodes which shall receive
/// a batch of input values in their Process method and compute the corresponding output values.
/// You should prefer this over a BasicMicroNode when the Process method consists of just
/// a few simple operations: Then the calling overhead of nodes is significant, and it can be
/// reduced when a single call to Process handles a whole batch of values. Of course this only
/// holds when there is a proper batch of values, for example in the context of shading there's
/// usually just one set of values.
///
/// To implement a BatchMicroNode, you have to derive a new class from BatchMicroNode and add
/// a function template @c{Result<void> Process(Batch<...>&)}
/// (no const in front of Batch) to that class with a list of those ports between the angular brackets which shall
/// be accessed by the node. Within the Process method you have to write a for loop over the batch
/// as in the example shown below. The ports have to be defined by MAXON_PORT macros in a micro node group class.
/// Usually the BatchMicroNode class is a member of that micro node group class:
/// @code{corenodes_micronodegroup_batch}
//! // This class defines a micro node group which adds batches of two Int values by a BatchMicroNode.
//! class MyBatchAddNode
//! {
//! public:
//! 	// Declaration of the input and output ports of the micro node group.
//! 	MAXON_PORT_INPUT(Int, in1);
//! 	MAXON_PORT_INPUT(Int, in2);
//! 	MAXON_PORT_OUTPUT(Int, out);
//! 
//! 	// Implementation of the single custom micro node.
//! 	class Impl : public BatchMicroNode
//! 	{
//! 	public:
//! 		// The Process method needs to specify which ports of the group the micro node accesses, in this case all ports.
//! 		// If the group contains more than one micro node, each micro node usually needs only a subset of the ports.
//! 		//
//! 		// The PORTMODE template parameter allows to instantiate the Process method with different port modes, see PortMode.
//! 		//
//! 		// Note that there's no const in front of Batch!
//! 		Result<void> Process(Batch<in1, in2, out>& batch) const
//! 		{
//! 			// Iterate over the batch. Again there's no const in front of auto.
//! 			for (auto& ports : batch)
//! 			{
//! 				// Do the computation for a single set of values.
//! 				ports.out.Update(ports.in1() + ports.in2());
//! 			}
//! 			return OK;
//! 		}
//!  	};
//! 
//! 	// The Init function will be called to set up the micro node group
//! 	// when you call CreateNode<MyBatchAddNode>() or as part of the MAXON_CORENODE_REGISTER macro.
//! 	static Result<void> Init(const MicroNodeGroupRef& group)
//! 	{
//! 		iferr_scope;
//! 		group.AddChild<Impl>() iferr_return;
//! 		return OK;
//! 	}
//! };
/// @endcode
/// There is the helper class OperatorNode to simplify the implementation of a core node class
/// consisting of a single BatchMicroNode. If you want to implement a core node class consisting
/// of a single BatchMicroNode which just invokes an existing C++ function or operator
/// (as in the example with the + operator) you can also use one of the macros
/// MAXON_CORENODE_FUNCTION, MAXON_CORENODE_OPERATOR_UNARY and MAXON_CORENODE_OPERATOR_BINARY.
//----------------------------------------------------------------------------------------
class BatchMicroNode : public MicroNode
{
	PRIVATE_MAXON_MICRONODE(BatchMicroNode, BATCH);

public:
	//----------------------------------------------------------------------------------------
	/// You have to use @c{Batch<...>&} as the parameter type of the Process method of a BatchMicroNode.
	/// @tparam PORTS									The ports which shall be accessed within the Process method.
	//----------------------------------------------------------------------------------------
	template <typename... PORTS> using Batch = PortsAccess<PORTSACCESS_FLAGS::BATCH, PORTS...>;

	/// This is only to hide the Ports class template inherited from MicroNode.
	/// @private
	class Ports;

	static const WIRETYPE IS_TARGET_OF = WIRETYPE::DOMAIN_FLOW_SEQUENCED | WIRETYPE::PORT;
	static const WIRETYPE IS_SOURCE_OF = WIRETYPE::DOMAIN_FLOW_SEQUENCED | WIRETYPE::PORT;

	template <typename T> using AllowsChild = std::false_type;

	PRIVATE_MAXON_MICRONODE_METHOD(Process, 1);
	PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA;
	PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE;

	template <typename MN> void PrivateInit()
	{
		PRIVATE_MAXON_MICRONODE_METHOD_INIT(Process);
		PRIVATE_MAXON_MICRONODE_METHOD_INITUSERDATA_INIT;
		PRIVATE_MAXON_MICRONODE_METHOD_GETLLVMCODE_INIT;
		PRIVATE_MAXON_MICRONODE_INIT;
	}
};

}

} // namespace maxon

#endif // MICRONODES_H__
