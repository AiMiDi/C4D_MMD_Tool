#ifndef CORENODES_LIB_H__
#define CORENODES_LIB_H__

#include "maxon/optional.h"
#include "maxon/corenodes.h"

namespace maxon
{

namespace reflection
{
class Function;
};

namespace corenodes
{

//----------------------------------------------------------------------------------------
/// An Optimizer returns an OptimizationInfo when some optimization can be applied to a core node.
/// Node compilers can take advantage of this information.
//----------------------------------------------------------------------------------------
struct OptimizationInfo
{
	/// The node to use instead of the original node (e.g. a Neg node for a Sub node which subtracts from 0).
	/// May be null if there is no need at all for a node because all outputs can be computed at compile-time or by pass-throughs (see #outputValues).
	CoreNode node;

	/// If #node is set, this is the port mapping from the port of the new node to the ports of the original node.
	/// portMap[Int(PORT_DIR::INPUT)] must have one entry for each input port of #node,
	/// portMap[Int(PORT_DIR::OUTPUT)] must have one entry for each output port of #node.
	/// E.g. if input port 0 of the new node shall be used as a substitute for input port 1 of the original node,
	/// you have to set portMap[Int(PORT_DIR::INPUT)][0] to 1.
	BaseArray<Int> portMap[2];

	//----------------------------------------------------------------------------------------
	/// An Output contains optimization info for an output port of the original node:
	/// - If #passthrough is set (non-negative), then this is the index of an input port of the
	///   original node whose value shall be taken over directly for the output port. For example
	///   this can be used for an Add node where one operand is known to be zero.
	/// - Otherwise if #value is non-null this is the compile-time constant value for the port.
	/// - Otherwise there is no optimization info for the port, so the #node substitution has to be used.
	//----------------------------------------------------------------------------------------
	struct Output
	{
		Int passthrough = -1;
		Data value;

		MAXON_OPERATOR_STRUCT(Output, passthrough, value);
	};

	/// For each output port of the original node there must be one Output entry in #outputValues
	/// which contains optimization info for that port.
	BaseArray<Output> outputValues;

	MAXON_OPERATOR_STRUCT(OptimizationInfo, node, portMap[0], portMap[1], outputValues);
};

MAXON_DATATYPE(OptimizationInfo, "net.maxon.corenode.datatype.optimizationinfo");


//----------------------------------------------------------------------------------------
/// A set of short circuit rules is used for CoreNodesLib::CreateOptimizer to easily create an
/// Optimizer for common cases. For example to optimize binary multiplication there are four rules:
/// 1. If input 0 is 0, the result is 0.
/// 2. If input 1 is 0, the result is 0.
/// 3. If input 0 is 1, the result is input 1.
/// 4. If input 1 is 1, the result is input 0.
///
/// These can be represented as short circuit rules:
/// @code{corenodes_shortcircuit}
//! static const ShortCircuitRule g_mulRules[] = {{0, 0, -1, 0},		// if input 0 is 0, return 0
//! 																			 				{1, 0, -1, 0},		// if input 1 is 0, return 0
//! 																			 				{0, 1, 1, -1},		// if input 0 is 1, return input 1
//! 																			 				{1, 1, 0, -1}};		// if input 1 is 1, return input 0
/// @endcode
///
/// You can only use short circuit rules for nodes with exactly one output port.
/// For other nodes you have to implement the Optimizer yourself.
//----------------------------------------------------------------------------------------
struct ShortCircuitRule
{
	/// The index of the input port to test.
	Int testInput;

	/// If the value of the input port given by #testInput matches #testValue,
	/// the rule applies. A conversion to the input port type is done before, so e.g. a 0
	/// for #testValue matches any zero-valued number or vector.
	Int testValue;

	/// If this is non-negative, a pass-through is create from the input port given by #resultInput to the output port.
	/// Otherwise #resultValue is used.
	Int resultInput;

	/// If #resultInput is negative, #resultValue is the compile-time constant value to use for the output port.
	/// It will be converted to the correct port type.
	Int resultValue;
};


class ConversionSequence;

//----------------------------------------------------------------------------------------
/// CoreNodesLib provides a set of static methods around core nodes.
//----------------------------------------------------------------------------------------
class CoreNodesLib
{
	MAXON_INTERFACE_NONVIRTUAL(CoreNodesLib, MAXON_REFERENCE_NONE, "net.maxon.corenode.interface.corenodeslib");
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a ConversionSequence from type #from to type #to. The sequence consists of
	/// zero to two ConversionNodes. If no suitable sequence can be found, nullptr is returned.
	/// @param[in] to									The destination type.
	/// @param[in] from								The source type.
	/// @return												A ConversionSequence #from &rarr; #to, or nullptr if no such sequence exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const ConversionSequence*> GetConversion(const DataType& to, const DataType& from);

	//----------------------------------------------------------------------------------------
	/// Checks if two conversion sequences are equal (consist of equal conversion nodes).
	/// You don't have to call this method explicitly, just use ConversionSequence::operator==.
	/// @param[in] a									A conversion sequence.
	/// @param[in] b									Another conversion sequence.
	/// @return												True if both conversion sequences are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsEqualConversionSequence(const ConversionSequence& a, const ConversionSequence& b);

	//----------------------------------------------------------------------------------------
	/// Checks if a conversion sequence is better than another one.
	/// You don't have to call this method explicitly, just use ConversionSequence::operator>.
	/// @param[in] a									A conversion sequence.
	/// @param[in] b									Another conversion sequence.
	/// @return												True if #a is better then #b, false otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsBetterConversionSequence(const ConversionSequence& a, const ConversionSequence& b);

	//----------------------------------------------------------------------------------------
	/// Converts a given #value using conversion sequence #cs to the destination type
	/// of the conversion sequence.
	/// @param[in] cs									A conversion sequence.
	/// @param[in] value							A value to convert. This has to match the source type of #cs, otherwise an error is returned.
	/// @return												The converted value, or an error if #value can't be converted by #cs.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Data> Convert(const ConversionSequence& cs, const ConstDataPtr& value);

	//----------------------------------------------------------------------------------------
	/// Converts a given #value to a destination type #to using registered ConversionNodes.
	/// This method obtains a ConversionSequence using Convert() and then calls that sequence
	/// to convert the #value. If no ConversionSequence can be found a conversion with
	/// DataType::Convert() is tried.
	/// @param[in] to									The destination type.
	/// @param[in] value							A value to convert.
	/// @return												The converted value, or an error the conversion isn't possible.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Data> Convert(const DataType& to, const ConstDataPtr& value);

	//----------------------------------------------------------------------------------------
	/// Constructs a CoreNode which implements a direct pass-through of its single input port
	/// to its single output port. Such nodes can be used by Optimizers to set up special cases,
	/// for example a multiplication by one can be optimized to a pass-through.
	/// @param[in] type								The type of the values for the pass-through.
	/// @return												A CoreNode implementing a pass-through of values of the given #type.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<CoreNode> GetPassThroughNode(const DataType& type);

	//----------------------------------------------------------------------------------------
	/// Constructs a CoreNode which calls the given #function on execution. The returned CoreNode
	/// has input ports for function parameters and a single output port for the function result.
	/// @param[in] function						The function to be wrapped by a CoreNode.
	/// @return												A CoreNode which calls #function on execution.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<CoreNode> WrapFunction(const reflection::Function& function);

	//----------------------------------------------------------------------------------------
	/// Creates an Optimizer for a set of ShortCircuitRules, see there for the meaning of the rules.
	/// The returned Optimizer will test the rules in the given order and apply the first matching one.
	/// @param[in] rules							A set of rules. The Optimizer doesn't make a copy, to you have to ensure
	///																that the rules remain valid during the lifetime of the Optimizer.
	///																For example just put the rules in a global static variable
	///																as in the example given at ShortCircuitRule.
	/// @return												An Optimizer using the given #rules.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Optimizer CreateOptimizer(const Block<const ShortCircuitRule>& rules);
};


#include "corenodes_lib1.hxx"

#include "corenodes_lib2.hxx"

}

} // namespace maxon

#endif // CORENODES_LIB_H__
