#ifndef CORENODES_IMPLEMENTER_H__
#define CORENODES_IMPLEMENTER_H__

#include "maxon/micronodes.h"

namespace maxon
{

namespace corenodes
{

struct OperatorNodeLlvmBase
{
	static void GetLlvmAssembly(const LlvmGlobalsReceiver&)
	{
	}
};

template <typename T> struct OperatorNodeLlvm : public OperatorNodeLlvmBase
{
};

namespace details
{

template <typename TYPES, size_t... I> class OperatorNodeBase
{
public:
	using Inputs = TYPES;

	MAXON_PORT_INPUT_INDEXED(Generic, in, sizeof...(I));

	template <typename PORT> static MAXON_ATTRIBUTE_FORCE_INLINE const Generic& GetPortValue(const PORT& port, size_t index)
	{
		return port[index]();
	}

	static void SetupPorts(const MicroNodeGroupRef& group)
	{
		ForEach{group.SetDataType(in(I), GetPortType<const typename TYPES::template At<I>::type>())...};
	}
};

template <typename IN> class OperatorNodeBase<ParameterPack<IN>, 0>
{
public:
	using Inputs = ParameterPack<IN>;

	MAXON_PORT_INPUT(IN, in);

	template <typename PORT> static MAXON_ATTRIBUTE_FORCE_INLINE const IN& GetPortValue(const PORT& port, size_t)
	{
		return port();
	}

	static void SetupPorts(const MicroNodeGroupRef& group)
	{
	}
};


template <typename OP, size_t... I> class OperatorMicroNode : public BatchMicroNode
{
public:
	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Process(Batch<typename OP::in, typename OP::out>& batch) const
	{
		iferr_scope;
		typename std::decay<typename OP::out::PortAccessType>::type result;
		for (auto& ports : batch)
		{
			OP::Process(result, reinterpret_cast<const typename OP::Inputs::template At<I>::type&>(OP::GetPortValue(ports.in, I))...) iferr_return;
			ports.out.Update(std::move(result));
		}
		return OK;
	}

	decltype(OperatorNodeLlvm<OP>::GetLlvmAssembly(GetZeroRef<LlvmGlobalsReceiver>())) GetLlvmAssembly(const LlvmGlobalsReceiver& receiver) const
	{
		return OperatorNodeLlvm<OP>::GetLlvmAssembly(receiver);
	}
};


template <typename OP, typename RESULT, typename TYPES, typename INDEX_SEQUENCE> class OperatorNodeHelper;

template <typename OP, typename RESULT, typename TYPES, size_t... I> class OperatorNodeHelper<OP, RESULT, TYPES, std::index_sequence<I...>> : public OperatorNodeBase<TYPES, I...>
{
public:
	using ValueType = RESULT;

	MAXON_PORT_OUTPUT(RESULT, out);

	static Result<void> Init(const MicroNodeGroupRef& group)
	{
		OperatorNodeHelper::SetupPorts(group);
		return group.template AddChild<OperatorMicroNode<OP, I...>>();
	}
};

}

//----------------------------------------------------------------------------------------
/// OperatorNode is a helper class to simplify the implementation of core nodes. It implements
/// a core node for the function OP::Process which you have to provide. OP::Process receives a
/// reference to the value of the single output port in its first parameter and the function
/// arguments from the input ports in the remaining parameters, for example:
/// @code{corenodes_operatornode}
//! template <typename T> class ReflectNode : public OperatorNode<ReflectNode<T>, T(T, T)>
//! {
//! public:
//! 	static ResultOk<void> Process(T& out, const T& incoming, const T& normal)
//! 	{
//! 		out = incoming - normal * (T(2) * Dot(normal, incoming));
//! 		return OK;
//! 	}
//! };
/// @endcode
/// The implemented core node consists of a single BatchMicroNode. The output port has the
/// name "out", the input ports are named "in.1", "in.2", ... (or just "in" for a function
/// with a single parameter).
///
/// The MAXON_CORENODE_FUNCTION, MAXON_CORENODE_OPERATOR_UNARY and MAXON_CORENODE_OPERATOR_BINARY
/// macros further simplify the core node implementation if the function is already available
/// as a C++ function or operator.
///
/// @tparam OP										A class with a Process function which implements the operator.
/// @tparam SIGNATURE							The signature of the node as a function type RESULT(IN...).
///																RESULT is used for the type of the output port, IN... for the
///																types of the input ports.
//----------------------------------------------------------------------------------------
template <typename OP, typename SIGNATURE> class OperatorNode;

template <typename OP, typename RESULT, typename... IN> class OperatorNode<OP, RESULT(IN...)> : public corenodes::details::OperatorNodeHelper<OP, RESULT, ParameterPack<IN...>, std::make_index_sequence<sizeof...(IN)>>
{
};



#define PRIVATE_MAXON_CORENODE_OPERATOR_INDEX(x, i, a) i
#define PRIVATE_MAXON_CORENODE_OPERATOR_PARAM(x, i, a) const x& in##i
#define PRIVATE_MAXON_CORENODE_OPERATOR_NAME(x, i, a) in##i
#define PRIVATE_MAXON_CORENODE_OPERATOR_DECLVAL(x, i, a) std::declval<x>()

#define PRIVATE_MAXON_CORENODE_OPERATOR(op, N, R, ...) \
	class N : public maxon::corenodes::details::OperatorNodeBase<maxon::ParameterPack<__VA_ARGS__>, MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_CORENODE_OPERATOR_INDEX,,, __VA_ARGS__)> \
	{ \
	public: \
		using ValueType = typename std::decay<R>::type; \
		MAXON_PORT_OUTPUT(ValueType, out); \
		static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultOk<void> Process(ValueType& out, MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_CORENODE_OPERATOR_PARAM,,, __VA_ARGS__)) { op; return maxon::OK; } \
		static maxon::Result<void> Init(const maxon::corenodes::MicroNodeGroupRef& group) \
		{ \
			N::SetupPorts(group); \
			return group.template AddChild<maxon::corenodes::details::OperatorMicroNode<N, MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_CORENODE_OPERATOR_INDEX,,, __VA_ARGS__)>>(); \
		} \
	}

//----------------------------------------------------------------------------------------
/// This macro defines a core node implementation class N for the given unary operator #op.
/// The implemented core node consists of a single BatchMicroNode. The output port has the
/// name "out", the input port is named "in".
/// @code{corenodes_unaryoperator}
//! template <typename T> MAXON_CORENODE_OPERATOR_UNARY(NegNode, -, T);
/// @endcode
/// @param[in] N									Name of the class to define.
/// @param[in] op									A unary operator such as -.
/// @param[in] T									Type of the operand.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_OPERATOR_UNARY(N, op, T) PRIVATE_MAXON_CORENODE_OPERATOR(out = op in0, N, decltype(op std::declval<T>()), T)

//----------------------------------------------------------------------------------------
/// This macro defines a core node implementation class N for the given binary operator #op.
/// The implemented core node consists of a single BatchMicroNode. The output port has the
/// name "out", the input ports are named "in.1", "in.2".
/// @code{corenodes_binaryoperator1}
//! MAXON_CORENODE_OPERATOR_BINARY(BooleanOperatorANDNode, &, Bool, Bool);
/// @endcode
/// @code{corenodes_binaryoperator2}
//! template <typename T> MAXON_CORENODE_OPERATOR_BINARY(AddNode, +, T, T);
/// @endcode
/// @param[in] N									Name of the class to define.
/// @param[in] op									A binary operator such as +.
/// @param[in] T1									Type of the left operand.
/// @param[in] T2									Type of the right operand.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_OPERATOR_BINARY(N, op, T1, T2) PRIVATE_MAXON_CORENODE_OPERATOR(out = in0 op in1, N, decltype(std::declval<T1>() op std::declval<T2>()), T1, T2)

//----------------------------------------------------------------------------------------
/// This macro defines a core node implementation class N for the given function #func.
/// The implemented core node consists of a single BatchMicroNode. The output port has the
/// name "out", the input ports are named "in.1", "in.2", ... (or just "in" for a function
/// with a single parameter).
/// @code{corenodes_unaryfunction}
//! template <typename T> MAXON_CORENODE_FUNCTION(AbsNode, Abs, T);
/// @endcode
/// @code{corenodes_function}
//! template <typename T> MAXON_CORENODE_FUNCTION(BoxStepNode, BoxStep, T, T, T);
/// @endcode
/// @param[in] N									Name of the class to define.
/// @param[in] func								A function such as Abs or BoxStep.
/// @param[in] ...								Port types of the core node. The port values are passed
/// 															as arguments to #func.
//----------------------------------------------------------------------------------------
#define MAXON_CORENODE_FUNCTION(N, func, ...) PRIVATE_MAXON_CORENODE_OPERATOR(out = func(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_CORENODE_OPERATOR_NAME,,, __VA_ARGS__)), N, decltype(func(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_CORENODE_OPERATOR_DECLVAL,,, __VA_ARGS__))), __VA_ARGS__)


#define MAXON_CORENODE_OPERATOR_UNARY_LLVM(OP, LLVM, LLVMTYPE) \
	template <> struct OperatorNodeLlvm<OP> \
	{ \
		static Result<CString> GetLlvmAssembly(const LlvmGlobalsReceiver&) { return "%1 = " LLVM " " LLVMTYPE " %0"_cs; } \
	}

#define MAXON_CORENODE_OPERATOR_BINARY_LLVM(OP, LLVM, LLVMTYPE) \
	template <> struct OperatorNodeLlvm<OP> \
	{ \
		static Result<CString> GetLlvmAssembly(const LlvmGlobalsReceiver&) { return "%2 = " LLVM " " LLVMTYPE " %0, %1"_cs; } \
	}

}

} // namespace maxon

#endif // CORENODES_IMPLEMENTER_H__
