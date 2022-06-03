#ifndef GRAPH_H__
#define GRAPH_H__

#include "maxon/subdata.h"
#include "maxon/changelist.h"
#include "maxon/datadescription_data.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/graphattribs.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/optional.h"
#include "maxon/url.h"

namespace maxon
{

using TimeStamp = UInt64;

//----------------------------------------------------------------------------------------
/// WIRE_MODE is used for the wires in a Wires object to control whether a wire is set,
/// inherited or hidden.
///
/// This is an ordered enumeration with NONE < MIN < NORMAL < MAX. Other values
/// shouldn't be used for ordered comparisons.
/// @see Wires
//----------------------------------------------------------------------------------------
enum class WIRE_MODE : UChar
{
	NONE = 0,											///< No wire.
	MIN = 8,											///< A wire with minimum priority.
	NORMAL = 16,									///< A wire with normal priority.
	PROPAGATION = 32,							///< A wire with propagation priority.
	AUTO_PROPAGATION = 40,				///< A wire with auto-propagation priority.
	MAX = 48,											///< A wire with maximum priority.
	REMOVE = 62,									///< Only used for MutablePort::Connect to tell that the an existing wire shall be removed.
	ALL = 63,											///< A mask for all explicit modes.
	FLAG0 = 1,										///< A wire flag which can be used for wires which don't interpret the wire mode as priority, but as a bit set. Different from NORMAL and any other flag in WIRE_MODE.
	FLAG1 = 2,										///< A wire flag which can be used for wires which don't interpret the wire mode as priority, but as a bit set. Different from NORMAL and any other flag in WIRE_MODE.
	IMPLICIT = 64,								///< Used as mask for implicit wires in MutablePort::GetConnections.
	ALL_INCLUDING_IMPLICIT = 127,	///< A mask for all modes
	INHERIT = 128,								///< Used for MutablePort::Connect to tell that the wire mode shall be inherited. (Also used internally.)
	FLAGS_MASK = 3,								///< Mask for FLAG0 | FLAG1.
	FULL_MASK = 255,							///< Complete mask for all bits of WIRE_MODE.
	CONNECT_DEFAULT = NORMAL,			///< Default mode for Connect methods.
	GETCONNECTIONS_DEFAULT = ALL	///< Default mode for GetConnections methods.
} MAXON_ENUM_ORDERED_FLAGS(WIRE_MODE);

#if defined(MAXON_TARGET_CPU_INTEL) && defined(MAXON_ASSEMBLY_GCC) && !defined(MAXON_TARGET_LINUX)
	#if (MAXON_COMPILER_CLANG == 1001) && defined(MAXON_TARGET_MACOS)
		// Workaround for Xcode 10.2: Do not use inline assembly. It crashes the backend rdar://49470921
	#else
		#define MAXON_WIRES_ASSEMBLY_GCC_INTEL
	#endif
#endif

//----------------------------------------------------------------------------------------
/// A port connection consists of up to eight independent wires:
/// 1. The /value/ wire is used to pass data values along the connection.
/// 2. The /event/ wire is used when events shall flow along the connection.
/// 3. The /dependency/ wire is only needed for internal connections within evaluation nodes such as core node wrappers.
///    A computed output port needs to have a dependency wire from each input port which is required for its computation.
/// 4. The /context/ wire connects a port which shall define a context to an input port which introduces that context.
/// 5. The /hidden/ wire is used mark a connection as hidden. What this means exactly is model-specific, for example
///    NodesGraphModelInterface doesn't show those connections.
/// 6. The /inhibit/ wire is used to temporarily disable the other wires. When this wire is present, the other wires
///    should be considered as non-existing.
///	7. The /slink/ wire is a marker which is used for node-specific purposes, where the source port of the connection
///	   determines the meaning. For example it connects the output port of a context parameter node
///	   to the input port which introduces the context.
///	8. The /tlink/ wire is a marker which is used for node-specific purposes, where the target port of the connection
///	   determines the meaning.
///
/// In most cases you only need a combination of a value, event and dependency wire.
///
///	The Wires class has the members #value, #event, #dependency, #context, #hidden, #inhibit, #slink, #tlink to store information about these wires for a connection.
/// Each of them has the enumeration type WIRE_MODE with the following possible values:
/// - WIRE_MODE::NONE means that there is no such wire in the connection. This does not necessarily mean that there is
///   no such wire at all because a wire might be @ref usernodes_derivation "inherited" from a base node system,
///   or there may be an @ref usernodes_wires_implicit "implicit wire" due to an enclosing connection.
/// - WIRE_MODE::MIN, WIRE_MODE::NORMAL and WIRE_MODE::MAX indicate that a wire exists. The values are priorities,
///   so whenever an ambiguity between multiple wires has to be resolved, the wires with highest priority are taken.
///
/// The wires of a connection can also be accessed by index, see VALUE, EVENT, DEPENDENCY, CONTEXT, HIDDEN, INHIBIT, SLINK, TLINK and #operator[]. For a loop over the wires
/// you have to use COUNT as upper bound:
/// @code
/// Wires w;
/// for (Int i = 0; i < Wires::COUNT; ++i)
/// {
///   // do something with w[i]
/// }
/// w.value = WIRE_MODE::NONE;
/// w[Wires::VALUE] = WIRE_MODE::NONE; // same as line above
/// @endcode
///
/// A Wires object can also be used as a mask to test another Wires object. Wires masks use the mask values of
/// WIRE_MODE (WIRE_MODE::NONE, WIRE_MODE::ALL, WIRE_MODE::IMPLICIT, WIRE_MODE::ALL_INCLUDING_IMPLICIT, WIRE_MODE::INHERIT, WIRE_MODE::FULL_MASK).
/// Testing against a mask is done by the bitwise operators & and |.
///
/// @see @$ref usernodes_wires
/// @see MutablePort::Connect
/// @see WIRE_MODE
//----------------------------------------------------------------------------------------
struct Wires
{
	//----------------------------------------------------------------------------------------
	/// Constructs an empty Wires object. All wire modes are set to WIRE_MODE::NONE.
	//----------------------------------------------------------------------------------------
	constexpr Wires() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a normal wire for values, events and dependencies. The #value, #event
	/// and #dependency members will be set to the given #mode, all other members to WIRE_MODE::NONE.
	/// @param[in] mode								The mode to use for the value and event wires.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT constexpr Wires(WIRE_MODE mode) : value(mode), event(mode), dependency(mode) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a single wire. The wire indexed by the given #index
	/// will be set to the given #mode, all other members to WIRE_MODE::NONE.
	/// @param[in] index							The index of the wire, one of VALUE, EVENT, DEPENDENCY, CONTEXT, HIDDEN, INHIBIT, SLINK.
	/// @param[in] mode								The mode to use for the wire.
	//----------------------------------------------------------------------------------------
	explicit Wires(Int index, WIRE_MODE mode = WIRE_MODE::NORMAL) { (&value)[index] = mode; }

	//----------------------------------------------------------------------------------------
	/// Constructs the wires using the given modes.
	/// @param[in] val								The mode for the value wire.
	/// @param[in] ev									The mode for the event wire.
	/// @param[in] dep								The mode for the dependency wire.
	//----------------------------------------------------------------------------------------
	constexpr Wires(WIRE_MODE val, WIRE_MODE ev, WIRE_MODE dep) : value(val), event(ev), dependency(dep) { }

	//----------------------------------------------------------------------------------------
	/// Constructs the wires using the given modes.
	/// @param[in] val								The mode for the value wire.
	/// @param[in] ev									The mode for the event wire.
	/// @param[in] dep								The mode for the dependency wire.
	/// @param[in] ctx								The mode for the context wire.
	/// @param[in] hid								The mode for the hidden wire.
	/// @param[in] inh								The mode for the inherit wire.
	/// @param[in] sln								The mode for the slink wire.
	/// @param[in] tln								The mode for the tlink wire.
	//----------------------------------------------------------------------------------------
	constexpr Wires(WIRE_MODE val, WIRE_MODE ev, WIRE_MODE dep, WIRE_MODE ctx, WIRE_MODE hid, WIRE_MODE inh, WIRE_MODE sln, WIRE_MODE tln) : value(val), event(ev), dependency(dep), context(ctx), hidden(hid), inhibit(inh), slink(sln), tlink(tln) { }

	WIRE_MODE value = WIRE_MODE::NONE;				///< The mode for the value part of the connection.
	WIRE_MODE event = WIRE_MODE::NONE;				///< The mode for the event part of the connection.
	WIRE_MODE dependency = WIRE_MODE::NONE;		///< The mode for the dependency part of the connection.
	WIRE_MODE context = WIRE_MODE::NONE;			///< The mode for the context part of the connection.
	WIRE_MODE hidden = WIRE_MODE::NONE;				///< The mode for the hidden part of the connection.
	WIRE_MODE inhibit = WIRE_MODE::NONE;			///< The mode for the inhibit part of the connection.
	WIRE_MODE slink = WIRE_MODE::NONE;				///< The mode for the slink part of the connection.
	WIRE_MODE tlink = WIRE_MODE::NONE;				///< The mode for the tlink part of the connection.

	static const Int VALUE = 0;					///< The index to address the value part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int EVENT = 1;					///< The index to address the event part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int DEPENDENCY = 2;		///< The index to address the dependency part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int CONTEXT = 3;				///< The index to address the context part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int HIDDEN = 4;				///< The index to address the hidden part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int INHIBIT = 5;				///< The index to address the inhibit part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int SLINK = 6;					///< The index to address the slink part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int TLINK = 7;					///< The index to address the tlink part, used in #operator[] and Wires(Int,WIRE_MODE).
	static const Int COUNT = 8;					///< The number of wires (currently 8). Use this for a loop over all possible wire indices.

	/// Constant indicating no wires at all.
	static const WIRE_MODE NONE = WIRE_MODE::NONE;

	//----------------------------------------------------------------------------------------
	/// Returns the mode for the wire indexed by #index.
	/// @param[in] index							The index of the wire, one of VALUE, EVENT, DEPENDENCY, CONTEXT, HIDDEN, INHIBIT, SLINK, TLINK.
	/// @return												Mode for the wire.
	//----------------------------------------------------------------------------------------
	WIRE_MODE operator [](Int index) const { return (&value)[index]; }

	/// @copydoc operator[]
	WIRE_MODE& operator [](Int index) { return (&value)[index]; }

	//----------------------------------------------------------------------------------------
	/// Returns a Wires value where all wire modes are set to the given #mode. With the default
	/// WIRE_MODE::ALL this can be used as a mask which represents all wires, this is useful
	/// as argument to PortTemplate::GetConnections to get all connections.
	/// @param[in] mode								The mode to use for all wires, WIRE_MODE::ALL by default.
	/// @return												Wires value having all wire modes set to #mode.
	//----------------------------------------------------------------------------------------
	static constexpr Wires All(WIRE_MODE mode = WIRE_MODE::ALL)
	{
		return {mode, mode, mode, mode, mode, mode, mode, mode};
	}

	//----------------------------------------------------------------------------------------
	/// Checks if there is any wire.
	/// @return												True if at least one of the wire modes differs from WIRE_MODE::NONE, false otherwise.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return ToInt() != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Applies a mask to this Wires object. This is implemented by a bitwise and of the underlying
	/// integral values.
	/// @param[in] other							A mask. The wire modes of #other should only be mask values of WIRE_MODE.
	/// @return												Reference to this.
	//----------------------------------------------------------------------------------------
	Wires& operator &=(Wires other)
	{
		*reinterpret_cast<UInt64*>(this) &= other.ToInt();
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the bitwise and of the underlying integral values. This makes sense only if one
	/// of the two Wires objects is a mask where the wire modes are mask values of WIRE_MODE.
	/// @param[in] other							Another Wires object.
	/// @return												The bitwise and of both Wires object.
	//----------------------------------------------------------------------------------------
	Wires operator &(Wires other) const
	{
		return {ToInt() & other.ToInt(), false};
	}

	//----------------------------------------------------------------------------------------
	/// Adds the wires of other to this Wires object. This is implemented by a bitwise or of the underlying
	/// integral values, and it makes sense only if both
	/// Wires objects only use mask values of WIRE_MODE, or if they don't have overlapping wires.
	/// For a parallel combination of two general Wires see Combine().
	/// @param[in] other							Another Wires object.
	/// @return												Reference to this.
	//----------------------------------------------------------------------------------------
	Wires& operator |=(Wires other)
	{
		*reinterpret_cast<UInt64*>(this) |= other.ToInt();
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the bitwise or of the underlying integral values. This makes sense only if both
	/// Wires objects only use mask values of WIRE_MODE, or if they don't have overlapping wires.
	/// For a parallel combination of two general Wires see Combine().
	/// @param[in] other							Another Wires object.
	/// @return												The bitwise or of both Wires object.
	//----------------------------------------------------------------------------------------
	Wires operator |(Wires other) const
	{
		return {ToInt() | other.ToInt(), false};
	}

	//----------------------------------------------------------------------------------------
	/// Returns the bitwise inverse of the underlying integral values. This makes sense only if this
	/// Wires object is a mask where the wire modes are mask values of WIRE_MODE. Then the
	/// returned object is the inverse of this mask.
	/// @return												The inverse of this mask.
	//----------------------------------------------------------------------------------------
	Wires operator ~() const
	{
		return {~ToInt(), false};
	}

	/// @copydoc DefaultDoc::operator==
	Bool operator ==(Wires other) const
	{
		return *reinterpret_cast<const UInt64*>(this) == reinterpret_cast<const UInt64&>(other);
	}

	/// @copydoc DefaultDoc::operator!=
	Bool operator !=(Wires other) const
	{
		return *reinterpret_cast<const UInt64*>(this) != reinterpret_cast<const UInt64&>(other);
	}

	/// @copydoc DefaultDoc::GetHashCode
	HashInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(*reinterpret_cast<const UInt64*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the concatenation of this Wires object and other. This takes the minimum of
	/// each wire value.
	/// @param[in] other							Another Wires object.
	/// @return												The concatenation (minimum) of the wires.
	//----------------------------------------------------------------------------------------
	Wires Concat(const Wires& other) const
	{
#ifdef MAXON_WIRES_ASSEMBLY_GCC_INTEL
		UInt64 a, b;
		__asm__ ("movq %2, %0\n" "movq %3, %1\n" "pminub %1, %0" : "=x" (a), "=x" (b) : "r" (ToInt()), "r" (other.ToInt()));
		return Wires{a, false};
#else
		return { Min(value, other.value), Min(event, other.event), Min(dependency, other.dependency), Min(context, other.context), Min(hidden, other.hidden), Min(inhibit, other.inhibit), Min(slink, other.slink), Min(tlink, other.tlink) };
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parallel combination of this Wires object and other. This takes the maximum of
	/// each wire value.
	/// @param[in] other							Another Wires object.
	/// @return												The parallel combination (maximum) of the wires.
	//----------------------------------------------------------------------------------------
	Wires Combine(const Wires& other) const
	{
#ifdef MAXON_WIRES_ASSEMBLY_GCC_INTEL
		UInt64 a, b;
		__asm__ ("movq %2, %0\n" "movq %3, %1\n" "pmaxub %1, %0" : "=x" (a), "=x" (b) : "r" (ToInt()), "r" (other.ToInt()));
		return Wires{a, false};
#else
		return { Max(value, other.value), Max(event, other.event), Max(dependency, other.dependency), Max(context, other.context), Max(hidden, other.hidden), Max(inhibit, other.inhibit), Max(slink, other.slink), Max(tlink, other.tlink) };
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Returns a Wires object which contains only those wires of this Wires object which aren't
	/// below the priority values given in #priorityMask.
	/// @param[in] priorityMask				Another Wires object.
	/// @return												Those wires which aren't below the values of #priorityMask.
	//----------------------------------------------------------------------------------------
	Wires MaskByPriority(const Wires& priorityMask) const
	{
#ifdef MAXON_WIRES_ASSEMBLY_GCC_INTEL
		UInt64 a, b;
		// This uses signed comparison, but the priority values have the sign-bit cleared, so this is not a problem.
		__asm__ ("movq %2, %1\n" "movq %3, %0\n" "pcmpgtb %1, %0\n" "pandn %1, %0" : "=x" (a), "=x" (b) : "r" (ToInt()), "r" (priorityMask.ToInt()));
		return Wires{a, false};
#else
		Wires result;
		for (Int m = 0; m < Wires::COUNT; ++m)
		{
			if ((*this)[m] >= priorityMask[m])
				result[m] = (*this)[m];
		}
		return result;
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Converts this Wires object into a mask which uses WIRE_MODE::FULL_MASK for wires which
	/// are set in this Wires object, otherwise WIRE_MODE::NONE.
	/// @return												Mask object to mask those wires which are present in this Wires object.
	//----------------------------------------------------------------------------------------
	Wires ToMask() const
	{
#ifdef MAXON_WIRES_ASSEMBLY_GCC_INTEL
		UInt64 a;
		__asm__ ("movq %1, %0\n" "pcmpeqb %2, %0\n" : "=&x" (a) : "r" (ToInt()), "x" (0));
		return Wires{~a, false};
#else
		Wires result;
		for (Int m = 0; m < Wires::COUNT; ++m)
		{
			if ((*this)[m] != WIRE_MODE::NONE)
				result[m] = WIRE_MODE::FULL_MASK;
		}
		return result;
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Returns the wire-wise comparison of this and other. This uses WIRE_MODE::FULL_MASK
	/// for a wire with the same value in this and other, of WIRE_MODE::NONE if the values differ.
	/// @param[in] other							Another Wires object.
	/// @return												Wire-wise comparison of this and other.
	//----------------------------------------------------------------------------------------
	Wires EqualWires(const Wires& other) const
	{
#ifdef MAXON_WIRES_ASSEMBLY_GCC_INTEL
		UInt64 a, b;
		__asm__ ("movq %2, %1\n" "movq %3, %0\n" "pcmpeqb %1, %0\n" : "=x" (a), "=x" (b) : "r" (ToInt()), "r" (other.ToInt()));
		return Wires{a & Wires::All(WIRE_MODE::FULL_MASK).ToInt(), false};
#else
		Wires result;
		for (Int m = 0; m < Wires::COUNT; ++m)
		{
			if ((*this)[m] == other[m])
				result[m] = WIRE_MODE::FULL_MASK;
		}
		return result;
#endif
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs = nullptr) const
	{
		return FormatString("(@,@,@,@,@,@,@,@)", value, event, dependency, context, hidden, inhibit, slink, tlink);
	}

	/// Only for internal use.
	/// @private
	UInt64 ToInt() const
	{
		static_assert(SIZEOF(Wires) == SIZEOF(UInt64), "Wrong size of Wires.");
		return *reinterpret_cast<const UInt64*>(this);
	}

	MAXON_IMPLICIT Wires(UInt64) = delete;

	/// Only for internal use, dummy Bool parameter to disambiguate constructor calls.
	/// @private
	Wires(UInt64 i, Bool)
	{
		*reinterpret_cast<UInt64*>(this) = i;
	}
};

MAXON_DATATYPE(Wires, "net.maxon.graph.wires");

//----------------------------------------------------------------------------------------
/// GraphConnection represents a connection between two ports of a graph. For a pair of connected
/// ports, one GraphConnection is stored at the source port and another one at the target port.
/// The first tuple value represents the other end of the connection, the second tuple value
/// the wires modes of the connection.
//----------------------------------------------------------------------------------------
using GraphConnection = Tuple<GraphNode, Wires>;

//----------------------------------------------------------------------------------------
/// IoNodePath represents a path to a node and port (port is optional).
/// Tuple<node absolute path, port relative path (single id if port is top-level)>.
//----------------------------------------------------------------------------------------
using IoNodePath = Tuple<NodePath, InternedId>;

//----------------------------------------------------------------------------------------
/// IoNodeConnection represents the start and end points of a connection.
/// Tuple<source node and port path, node and port path>.
//----------------------------------------------------------------------------------------
using IoNodeConnection = Tuple<IoNodePath, IoNodePath>;

//----------------------------------------------------------------------------------------
/// 
//----------------------------------------------------------------------------------------
using IoGraphNode = Tuple<GraphNode, InternedId>;

//----------------------------------------------------------------------------------------
/// Graph connections can @ref GraphNode::GetConnectionValue "store attribute values"
/// at three different positions: At their source, at their center and at their target.
//----------------------------------------------------------------------------------------
enum class CONNECTION_POSITION
{
	SOURCE,		///< The source position of a connection.
	CENTER,		///< The center position of a connection.
	TARGET		///< The target position of a connection.
} MAXON_ENUM_ORDERED_LIST(CONNECTION_POSITION);


//----------------------------------------------------------------------------------------
/// Reverses the given connection position. CONNECTION_POSITION::SOURCE becomes CONNECTION_POSITION::TARGET
/// and vice versa, CONNECTION_POSITION::CENTER remains the same.
/// @param[in] pos								A connection position.
/// @return												The reverse connection position.
//----------------------------------------------------------------------------------------
inline CONNECTION_POSITION Reverse(CONNECTION_POSITION pos)
{
	return CONNECTION_POSITION(2 - UnderlyingType<CONNECTION_POSITION>(pos));
}

class GraphTransaction;
class GraphModelRef;

//----------------------------------------------------------------------------------------
/// GraphModelInterface is an abstraction of a hierarchical graph. A GraphModelInterface has
/// a single root node (see GetRoot()). The root node and any other node may have an arbitrary
/// number of child nodes. Also each node may have a number of input ports and output ports,
/// and those ports may have nested ports, too. So nodes and ports of a graph can be arranged in a single tree,
/// for example:
/// - Root (NODE_KIND::NODE)
///  - N1 (NODE_KIND::NODE)
///    - N2 (NODE_KIND::NODE)
///      - Inputs (NODE_KIND::INPUTS)
///        - PortA (NODE_KIND::INPORT)
///          - PortB (NODE_KIND::INPORT)
///        - PortC (NODE_KIND::INPORT)
///      - Outputs (NODE_KIND::OUTPUTS)
///        - PortD (NODE_KIND::OUTPORT)
///    - Inputs (NODE_KIND::INPUTS)
///      - PortE (NODE_KIND::INPORT)
///    - Outputs (NODE_KIND::OUTPUTS)
///      - PortF (NODE_KIND::OUTPORT)
///        - PortG (NODE_KIND::OUTPORT)
///  - N3 (NODE_KIND::NODE)
///    - Inputs (NODE_KIND::INPUTS)
///      - PortH (NODE_KIND::INPORT)
///    - Outputs (NODE_KIND::OUTPUTS)
///      - PortI (NODE_KIND::OUTPORT)
///
/// In fact, GraphModelInterface represents nodes and ports by the same class GraphNode.
/// To distinguish between the different kinds of a GraphNode, a value of type NODE_KIND is returned
/// by GraphNode::GetKind(). The example tree shows the possible kinds in parentheses:
/// - NODE_KIND::NODE stands for true nodes.
/// - NODE_KIND::INPUTS/NODE_KIND::OUTPUTS represent the lists of top-level input/output ports of a node.
/// - NODE_KIND::INPORT/NODE_KIND::OUTPORT represent input/output ports.
///
/// It is not required for an implementation of GraphModelInterface to support arbitrary nestings.
/// For example, the implementation for nodes supports arbitrarily nested ports, but depending
/// on its filter settings it doesn't support nodes nested within other nodes.
///
/// In addition to the tree of nodes and ports, a hierarchical graph also has a number of connections
/// between ports. They are represented by GraphConnection. Typically a connection goes from
/// an output port to an input port, but this is not always the case. The following connections are allowed:
/// - An output port of a node may have a connection to an input port of a sibling node (so both nodes
///   must have the same direct parent).
/// - An input port of a child node may have a connection from an input port of its direct parent node.
/// - An output port of a child node may have a connection to an output port of its direct parent node.
/// - An input port of a node may have a connection to an output port of that same node (so the connections
///   just tunnels the value through the node).
///
/// In all cases it doesn't matter if the ports are top-level ports or nested ports. This is an example graph
/// which shows all four cases:
/// @graph
/// +-Root----------------------------------------+
/// |                        ,----------------> p o
/// |       +-N---------+   /                     |
/// |       |         p o -*                      |
/// o x --> o x ---> x o    \     +-M-----+       |
/// o y --> o y ---> y o     `--> o p   q o --> q o
/// |       +-----------+         +-------+       |
/// +---------------------------------------------+
/// @endgraph
///
/// Each node may have attributes. An attribute is identified by an InternedId, typically this id
/// is defined together with the type of the attribute value by MAXON_ATTRIBUTE.
//----------------------------------------------------------------------------------------
class GraphModelInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(GraphModelInterface, MAXON_REFERENCE_NORMAL, "net.maxon.graph.interface.graphmodel");

public:
	//----------------------------------------------------------------------------------------
	/// This enum is needed for GraphNode::GetConnections to control which connections shall be reported.
	/// At least one of CONNECTIONS or INDUCED_DEPENDENCIES has to be set.
	//----------------------------------------------------------------------------------------
	enum class GET_CONNECTIONS_MODE
	{
		NONE = 0,										///< No flags.
		CONNECTIONS = 1,						///< Report normal connections, the default.
		INDUCED_DEPENDENCIES = 2,		///< Report induced dependencies (due to loop dependencies or sequencing).
		DERIVATION_FILTER = 4,			///< Apply the derivation filter.
		EXTERNAL_CONNECTIONS = 8,		///< Only report connections which leave the node to which the port belongs (so they are external to the node).
		WITHOUT_INHIBITED = 16,			///< Don't report inhibited connections (those where Wires::inhibit is present).
		WITH_IMPLICIT_FLAG = 32,		///< Report the WIRE_MODE::IMPLICIT flag for imlicit connections.
		INCLUDE_HIDDEN = 64,				///< Report connections where the hidden flag is set or which go to hidden ports.
		INTERNAL_CONNECTIONS = 128,	///< Only report connections which don't leave the node to which the port belongs (so they are internal to the node).
	} MAXON_ENUM_FLAGS_CLASS(GET_CONNECTIONS_MODE);

	//----------------------------------------------------------------------------------------
	/// Returns the path of the root node of this graph. Usually this is an empty path, but
	/// a graph model may be a view of a nested part of an enclosing graph. In the latter case
	/// the path points to the root node of the nested part.
	/// @return												The path of the root node of this graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodePath& GetRootPath();

	//----------------------------------------------------------------------------------------
	/// Returns the root node of this graph. The whole graph can be traversed starting from the root node.
	/// @return												The root node of this graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphNode GetRoot();

	//----------------------------------------------------------------------------------------
	/// Checks if this graph is read-only. You can't modify read-only graphs.
	/// @return												@trueIfOtherwiseFalse{this graph is read-only}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsReadOnly();

	//----------------------------------------------------------------------------------------
	/// Returns the GraphNode corresponding to path. If no such node exists in the graph,
	/// an empty node is returned.
	/// @param[in] path								A node path. This has to be an absolute path, so if the current graph
	///																is view of a nested part of an enclosing graph, the path has to be the full path
	///																starting at the root of the enclosing graph.
	/// @param[in] filtered						With the default value of true the filter settings (if any) of this graph will be used.
	///																When false this is disabled, then you'll get a valid GraphNode even for paths
	///																which don't belong to this graph, but e.g. to nested graphs which are hidden
	///																by the filter settings.
	/// @return												The GraphNode corresponding to the path. This is empty when there is no such node in the graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphNode GetNode(const NodePath& path, Bool filtered = true);

	//----------------------------------------------------------------------------------------
	/// Validates the graph. This is an implementation-specific operation and should be invoked
	/// when a batch of changes has been applied to the graph and the graph should be brought
	/// into a valid state again. For example, the implementation of GraphModelInterface for
	/// nodes may update the type of an output port of a polymorphic node based on the
	/// types of the input ports.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Validate();

	//----------------------------------------------------------------------------------------
	/// Removes all values for the given user state attribute attr from this graph (so from all of its nodes).
	/// @param[in] attr								A user state attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ResetUserState(const InternedId& attr);


	//----------------------------------------------------------------------------------------
	/// Returns the GraphAttribute which this graph model uses for the attribute identified by attr.
	/// The model may return a null reference if it doesn't provide a GraphAttribute for attr.
	/// This doesn't mean that the attribute is unsupported, it just means that
	/// there is no need for special handling of the attribute (which would require a GraphAttribute).
	/// @param[in] attr								The identifier of the attribute.
	/// @return												The corresponding GraphAttribute, or a null reference if the graph model has
	///																no GraphAttribute for attr.
	/// @see GetGraphAttributeFlags
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const GraphAttribute& GetGraphAttribute(const InternedId& attr);

	//----------------------------------------------------------------------------------------
	/// Returns the GraphAttribute::FLAGS to use for the attribute identified by attr.
	/// This allows the graph model to override the default flags of the attribute,
	/// for example to mark an attribute as meta attribute.
	/// @param[in] attr								The identifier of the attribute.
	/// @return												The flags which this graph model uses for the attribute.
	/// @see GetGraphAttribute
	/// @MAXON_ANNOTATION{default=GraphAttributeInterface::FLAGS::DIRECT}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphAttribute::FLAGS GetGraphAttributeFlags(const InternedId& attr);

	//----------------------------------------------------------------------------------------
	/// Begins a new transaction within which modifications can be made. You have to do this
	/// in order to modify the graph, modifications outside of transactions are not allowed
	/// (with the exception of changing user state attributes).
	///
	/// If there already is an active transaction, this will create a nested transaction.
	/// Otherwise a non-nested transaction starts, only then the observable
	/// GraphModelInterface::ObservableTransactionStarted informs its observers about the
	/// start of a transaction.
	///
	/// @param[in] userData						User data to pass to the observers of GraphModelInterface::ObservableTransactionStarted.
	///																Because nested transactions don't trigger the observable, the user data of them is ignored.
	/// @return												A GraphTransaction object to commit or rollback the transaction at a later point of time.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<GraphTransaction> BeginTransaction(const DataDictionary& userData = GetPtrSizedZeroRef<DataDictionary>());

	//----------------------------------------------------------------------------------------
	/// Informs about the start of a transaction. This is called during BeginTransaction(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] graph							The graph at which the observer was registered.
	/// @param[in] userData						The user data given to GraphModelRef::BeginTransaction(). In case of nested transactions,
	///																this is the user data of the outmost (i.e. first) invocation.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionStarted, (const GraphModelRef& graph, const DataDictionary& userData), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the commit of a transaction. This is called during GraphTransaction::Commit(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] graph							The graph at which the observer was registered.
	/// @param[in] userData						The user data given to GraphTransaction::Commit(). In case of nested transactions,
	///																this is the merger of the user datas given to all commits.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionCommitted, (const GraphModelRef& graph, const DataDictionary& userData), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the rollback of a transaction. This is called during GraphTransaction::Rollback(),
	/// but only for outmost transactions (which aren't nested within other transactions).
	/// @param[in] graph							The graph at which the observer was registered.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTransactionRolledBack, (const GraphModelRef& graph), ObservableCombinerRunAllComponent);


	//----------------------------------------------------------------------------------------
	/// Returns a time stamp of this graph which can be used to test for modifications.
	/// Each transaction or change of user state increments the stamp. The time stamp is also
	/// needed for GetModificationsSince and GraphNodeFunctions::GetAttributeModificationsSince
	/// to get all modifications which have happened since then.
	/// @return												Modification time stamp of the graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeStamp GetModificationStamp();

	//----------------------------------------------------------------------------------------
	/// These flags are reported by GetModificationsSince() to tell which properties of the node have changed.
	//----------------------------------------------------------------------------------------
	enum class MODIFIED
	{
		/// No flag.
		NONE = 0,

		/// The graph has changed completely. This is only reported for the root node.
		COMPLETE = 1,

		/// Direct non-meta attributes of the node have changed.
		DIRECT_ATTRIBUTE = 2,

		/// Direct meta attributes of the node have changed (see GraphAttributeInterface::FLAGS::META).
		DIRECT_META_ATTRIBUTE = 4,

		/// Inherited attributes (derived from left to right) of the node have changed.
		INHERITED_ATTRIBUTE = 8,

		/// Synthesized attributes (derived from right to left) of the node have changed.
		SYNTHESIZED_ATTRIBUTE = 16,

		/// User state attributes of the node have changed (see GraphAttributeInterface::FLAGS::USER_STATE).
		USER_STATE_ATTRIBUTE = 32,

		/// The node has been added.
		NODE_ADDED = 64,

		/// Children of the node have been removed.
		CHILD_REMOVED = 128,

		/// Input connections of the port have changed.
		INPUT_CONNECTION = 256,

		/// Output connections of the port have changed.
		OUTPUT_CONNECTION = 512,

		/// This is set to indicate a special change, the exact meaning is graph-specific.
		SPECIAL0 = 1024,

		/// This is set to indicate a special change, the exact meaning is graph-specific.
		SPECIAL1 = 2048,

		/// This is set to indicate a change which affects names of nodes or ports.
		SPECIAL_NAME = 4096,

		/// A mask containing all possible MODIFIED bits.
		ALL_MASK = 0x7fffffff,

		/// Derived attributes of the node have changed.
		DERIVED_ATTRIBUTE_MASK = INHERITED_ATTRIBUTE | SYNTHESIZED_ATTRIBUTE,

		/// Mask to test for changes to direct attributes (whether meta or non-meta).
		DIRECT_ATTRIBUTE_MASK = DIRECT_ATTRIBUTE | DIRECT_META_ATTRIBUTE,

		/// Mask to test for changes to attributes belonging to the data model of the graph (non-meta, non-user-state attributes).
		DATA_ATTRIBUTE_MASK = DIRECT_ATTRIBUTE | DERIVED_ATTRIBUTE_MASK,

		/// Mask to test for attribute changes.
		ATTRIBUTE_MASK = DATA_ATTRIBUTE_MASK | DIRECT_META_ATTRIBUTE | USER_STATE_ATTRIBUTE,

		/// Mask to test for connection changes of ports.
		CONNECTION_MASK = INPUT_CONNECTION | OUTPUT_CONNECTION,

		/// Mask to test for added or removed nodes.
		NODE_MASK = NODE_ADDED | CHILD_REMOVED,

		/// Mask to test for any structural change (changed connections, added or removed nodes).
		STRUCTURE_MASK = CONNECTION_MASK | NODE_MASK
	} MAXON_ENUM_FLAGS_CLASS(MODIFIED);

	//----------------------------------------------------------------------------------------
	/// Reports all modifications which have been made since the given stamp to the receiver. A typical usage is
	/// @code
	/// TimeStamp stamp = graph.GetModificationStamp(); // get the reference time stamp
	/// ... // do some modifications
	/// graph.GetModificationsSince(stamp,
	///   [] (const GraphNode& node, GraphModelRef::MODIFIED mod) -> Result<Bool>
	///		{
	///			...
	///		}) iferr_return;
	/// @endcode
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @param[in] receiver						Modifications are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetModificationsSince(TimeStamp stamp, const ValueReceiver<const GraphNode&, MODIFIED>& receiver);

	//----------------------------------------------------------------------------------------
	/// Returns flags which tell which kinds of changes have happened since the given time stamp.
	/// From the returned value you can't tell exactly which nodes or ports are affected, but you can
	/// tell for example if only attributes have changed or also the structure.
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @return												Combination of flags to indicate the kinds of changes that have happened.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MODIFIED GetModificationsSince(TimeStamp stamp);


	//----------------------------------------------------------------------------------------
	/// Returns the change list to which this graph model currently logs its modifications.
	/// A newly created graph model doesn't automatically create a change list, so to start
	/// logging you need to call StartNewChangeList() once. The change list can be used
	/// to undo or redo the changes or even to apply them to a different graph, see Apply().
	/// @return												Current change list, may be a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ChangeList& GetChangeList();

	//----------------------------------------------------------------------------------------
	/// Starts a new change list and returns the previous one. Afterwards the graph will log
	/// all modifications to the newly created change list. The new change list can be obtained with
	/// GetChangeList() or as the result of the next call to StartNewChangeList().
	/// The returned change list contains all modifications which have been made since the previous
	/// call to StartNewChangeList(). You can pass it to Apply() to undo or redo the changes
	/// or apply them to a different graph.
	/// @return												Change list which contains the modifications since the previous call to StartNewChangeList().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ChangeList> StartNewChangeList();

	//----------------------------------------------------------------------------------------
	/// Applies the given change list to this graph. For an undo set inverse to true, for a
	/// redo or if you want to apply the change list to a different graph use false.
	/// @param[in] list								Change list to apply.
	/// @param[in] inverse						Use true if the inverse of the change list shall be applied (for an undo), false otherwise.
	/// @return												A new change list which contains those changes of list which couldn't be applied,
	///																for example the change of an attribute value at a node which doesn't exist in this graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ChangeList> Apply(const ChangeList& list, Bool inverse);


	//----------------------------------------------------------------------------------------
	/// Returns a new graph model which is a copy of the subgraph given by the selection.
	/// @param[in] selection					A selection of nodes. Nodes which aren't direct children of this graph are ignored.
	/// @return												A copy of the subgraph given by the selection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphModelRef> CreateCopyOfSelection(const Block<const GraphNode>& selection);

	//----------------------------------------------------------------------------------------
	/// Merges the other graph into this graph. Top-level nodes and ports are added into this graph
	/// using new unique identifiers to prevent naming conflicts. The mapping from the original identifiers
	/// of other to the new ones is returned.
	/// @param[in] other							Another graph to merge into this graph.
	/// @return												The mapping from original identifiers of #other to the identifiers used for the merge:
	///																- first contains the mapping of top-level nodes.
	///																- second contains the mapping of top-level input ports.
	///																- third contains the mapping of top-level output ports.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HomogenousTupleType<3, HashMap<InternedId, InternedId>>> Merge(const GraphModelRef& other);

protected:
	// The following methods are protected here, they are needed by GraphNode and GraphTransaction and documented there.

	MAXON_METHOD NODE_KIND GetKind(const GraphNode& node);

	MAXON_METHOD const NodePath& GetPath(const GraphNode& node);

	MAXON_METHOD Result<Bool> GetChildren(const GraphNode& node, const ValueReceiver<const GraphNode&>& callback, NODE_KIND filter = NODE_KIND::ALL_MASK);

	MAXON_METHOD Result<GraphNode> GetParent(const GraphNode& node);

	MAXON_METHOD Result<GraphNode> GetAncestor(const GraphNode& node, NODE_KIND kind);

	MAXON_METHOD Result<GraphNode> FindChild(const GraphNode& node, const InternedId& name, NODE_KIND kind = NODE_KIND::ALL_MASK);

	MAXON_METHOD Result<GraphNode> FindInnerNode(const GraphNode& node, const PathBlock& innerPath);

	MAXON_METHOD Result<Bool> GetInnerNodes(const GraphNode& node, NODE_KIND mask, Bool includeNode, const ValueReceiver<const GraphNode&>& receiver);

	MAXON_METHOD Result<void> Remove(const GraphNode& node);

	MAXON_METHOD Result<GraphNode> AddPort(const GraphNode& parent, const Id& name);

	MAXON_METHOD Result<Bool> GetConnections(const GraphNode& node, PORT_DIR dir, const ValueReceiver<const GraphConnection&>& callback, Wires mask = Wires::All(), GraphModelInterface::GET_CONNECTIONS_MODE mode = GraphModelInterface::GET_CONNECTIONS_MODE::CONNECTIONS);

	MAXON_METHOD Result<Wires> GetWires(const GraphNode& source, const GraphNode& target);

	MAXON_METHOD Result<void> Connect(const GraphNode& source, const GraphNode& target, Wires wires = WIRE_MODE::CONNECT_DEFAULT);

	MAXON_METHOD Result<void> RemoveConnections(const GraphNode& port, PORT_DIR dir, Wires mask);

	MAXON_METHOD Result<void> CopyConnectionsFrom(const GraphNode& dest, const GraphNode& source, PORT_DIR direction, Bool includeInner);

	MAXON_METHOD Result<Bool> GetConnectionValues(const GraphNode& source, const GraphNode& target, const ValueReceiver<CONNECTION_POSITION, InternedId, const ConstDataPtr&>& receiver);

	MAXON_METHOD Result<ConstDataPtr> GetConnectionValue(const GraphNode& source, const GraphNode& target, CONNECTION_POSITION position, const InternedId& attr, const DataType& expectedType);

	MAXON_METHOD Result<Bool> SetConnectionValue(const GraphNode& source, const GraphNode& target, CONNECTION_POSITION position, const InternedId& attr, ForwardingDataPtr&& value);

	MAXON_METHOD Result<void> GetValues(const GraphNode& node, GraphAttributeInterface::FLAGS mask, GraphAttributeMap& map);

	MAXON_METHOD Result<ConstDataPtr> GetValue(const GraphNode& node, const InternedId& attr, const DataType& expectedType);

	MAXON_METHOD Result<ConstDataPtr> GetStoredValue(const GraphNode& node, const InternedId& attr, const DataType& expectedType);

	MAXON_METHOD Result<Bool> GetBaseValues(const GraphNode& node, const InternedId& attr, const DataType& expectedType, const ValueReceiver<const ConstDataPtr&, Int>& valueReceiver);

	MAXON_METHOD Result<Bool> SetValue(const GraphNode& node, const InternedId& attr, ForwardingDataPtr&& value, Bool checkAndInvalidate);

	MAXON_METHOD Result<void> TouchValue(const GraphNode& node, const InternedId& attr);

	MAXON_METHOD Result<void> ChangeValue(const GraphNode& node, const InternedId& attr, const SubDataOperation& op, const SubDataPathBlock& path, ForwardingDataPtr&& subvalue);

	MAXON_METHOD Result<Bool> RemoveValue(const GraphNode& node, const InternedId& attr);

	MAXON_METHOD Result<Bool> InheritValue(const GraphNode& node, const InternedId& attr);

	MAXON_METHOD Result<void> CopyValuesFrom(const GraphNode& dest, const GraphNode& source, Bool includeInner);

	MAXON_METHOD Result<GraphAttribute::FLAGS> GetMessageFlags(const GraphNode& node, const InternedId& attr);

	MAXON_METHOD Result<Bool> GetMessages(const GraphNode& node, const InternedId& attr, const ValueReceiver<const GraphMessage&>& receiver);

	MAXON_METHOD Result<Bool> GetAttributeModificationsSince(const GraphNode& node, TimeStamp stamp, const ValueReceiver<InternedId, ConstDataPtr>& receiver);

	MAXON_METHOD Result<TimeStamp> GetAttributeStamp(const GraphNode& node, const InternedId& attr);

	MAXON_METHOD Result<TimeStamp> GetConnectionStamp(const GraphNode& node, PORT_DIR direction);

	MAXON_METHOD Result<Int> BeginTransactionImpl(const DataDictionary& userData);

	[[deprecated]] MAXON_METHOD Result<void> CommitImpl(const DataDictionary& userData, Int nesting);

	MAXON_METHOD void RollbackImpl(Int nesting);

	MAXON_METHOD void CopyConstruct(GraphNode& node, const GraphNode& src);

	MAXON_METHOD void Destruct(GraphNode& node);

	MAXON_METHOD Bool IsValid(const GraphNode& node);

	MAXON_METHOD Bool IsSame(const GraphNode& a, const GraphNode& b);

	MAXON_METHOD UInt GetNodeHashCode(const GraphNode& node);

	MAXON_METHOD String NodeToString(const GraphNode& node, const FormatStatement* fs);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> IsSelected(const GraphNode& node);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<GraphNode> CreateOutputPort(const GraphNode& node, const CString& id, const String& name = String("Output"));

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<GraphNode> CreateInputPort(const GraphNode& node, const CString& id, const String& name = String("Input"));

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetDirectPredecessors(const GraphNode& node, const ValueReceiver<const GraphNode&>& callback, const NODE_KIND& filter);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetAllPredecessors(const GraphNode& node, const ValueReceiver<const GraphNode&>& callback, const NODE_KIND& filter);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetDirectSuccessors(const GraphNode& node, const ValueReceiver<const GraphNode&>& callback, const NODE_KIND& filter);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetAllSuccessors(const GraphNode& node, const ValueReceiver<const GraphNode&>& callback, const NODE_KIND& filter);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> IsConnectedTo(const GraphNode& node, const GraphNode& port);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> MuteConnectionWith(const GraphNode& node, const GraphNode& port);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> MuteAllConnections(const GraphNode& node, const PORT_DIR& direction);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> UnmuteConnectionWith(const GraphNode& node, const GraphNode& port);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> UnmuteAllConnections(const GraphNode& node, const PORT_DIR& direction);

	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> RemoveAllConnections(const GraphNode& node);

public:
	//----------------------------------------------------------------------------------------
	/// Adds an instance of the node given by the identifier nodeId as child of the root node to this graph.
	/// If #childId is empty, a UUID will be chosen as identifier of the child, otherwise #childId.
	/// In the latter case it is an error if this root node already has a child with that identifier.
	/// @param[in] childId						Identifier for the child node (if empty, a UUID is chosen).
	/// @param[in] nodeId							Identifier for the type of the node to add. How this is resolved to an actual node type is model-specific.
	/// @param[in] args								Arguments to use for the node creation. The exact meaning is model-specific.
	/// @return												A GraphNode referencing the added child.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphNode> AddChild(const Id& childId, const Id& nodeId, const DataDictionary& args = DataDictionary::NullValue());

	//----------------------------------------------------------------------------------------
	/// Selects the Wire between two Ports.
	/// @param[in] src								The first GraphNode's path
	/// @param[in] dst								The second GraphNode's path
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> SelectWire(const NodePath& src, const NodePath& dst);

	//----------------------------------------------------------------------------------------
	/// Deselects the Wire between two Ports.
	/// @param[in] src								The first GraphNode
	/// @param[in] dst								The second GraphNode
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> DeselectWire(const GraphNode& src, const GraphNode& dst);

	//----------------------------------------------------------------------------------------
	/// Retrieves all selected Wires on the graph.
	/// @param[in] callback						This callback will receive the source and destination ports and the wire itself
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetSelectedWires(const ValueReceiver<const GraphNode&, const GraphNode&, const Wires&>& callback);
	
	//----------------------------------------------------------------------------------------
	/// Deselects the True Node passed as an argument.
	/// @param[in] node								The True Node to Deselect
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> DeselectTrueNode(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Deselects the Port passed as an argument.
	/// @param[in] port								The Port to Deselect
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> DeselectPort(const GraphNode& port);

	//----------------------------------------------------------------------------------------
	/// Selects a node or a port.
	/// @param[in] node 						the node or the port that have to be selected.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> SelectNode(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Deselects a node or a port.
	/// @param[in] node 						the node or the port that have to be Deselected.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> DeselectNode(const GraphNode& node);
	
	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes having their stored data equals the ones in the passed DataDictionary.
	/// @param[in] callback						This callback will receive all node.
	/// @param[in] matchingData				The Dictionary filled with the data we want to compare the GraphNode with
	/// @return												All node founded that have the same data values than those passed within the Dictionary.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> ListAllNodes(const ValueReceiver<const GraphNode&>& callback, const DataDictionary& matchingData);

	//----------------------------------------------------------------------------------------
	/// Checks if the passed True Node is selected.
	/// @param[in] node								The True Node to check
	/// @return												@trueIfOtherwiseFalse{this GraphNode is a True Node and is selected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> IsTrueNodeSelected(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Checks if the passed Port is selected.
	/// @param[in] port								The port to check
	/// @return												@trueIfOtherwiseFalse{this GraphNode is a port and is selected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> IsPortSelected(const GraphNode& port);

	//----------------------------------------------------------------------------------------
	/// Checks if a Wires between two port is selected. (GraphNode will be converted to nodePath)
	/// @param[in] src								The wire's source port's path 
	/// @param[in] dst								The wire's destination port's path
	/// @return												@trueIfOtherwiseFalse{the wire is selected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<Bool> IsWireSelected(const NodePath& src, const NodePath& dst);

	//----------------------------------------------------------------------------------------
	/// Selects the Wires between two Ports.
	/// @param[in] src								The wire's source port
	/// @param[in] dst								The wire's destination port
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> SelectWire(const GraphNode& src, const GraphNode& dst);
	
	//----------------------------------------------------------------------------------------
	/// Selects the True Node passed as an argument.
	/// @param[in] node								The True Node to select
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> SelectTrueNode(const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// Retrieves all the selected True Node on the graph.
	/// @param[in] callback						This callback will receive all selected True Node
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetSelectedTrueNodes(const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Selects the Port passed as an argument.
	/// @param[in] port								The Port to select
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> SelectPort(const GraphNode& port);

	//----------------------------------------------------------------------------------------
  /// Retrieves all selected Ports on the graph.
  /// @param[in] callback						This callback will receive all selected Ports
  //----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetSelectedPorts(const ValueReceiver<const GraphNode&>& callback);

	//----------------------------------------------------------------------------------------
	/// Retrieves all selected Ports and/or True Node on the graph depending on the NODE_KIND passed as argument
	/// @param[in] callback						This callback will receive all selected ports and/or True Node
	/// @param[in] kind								The GraphNode kind to check
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> GetSelectedNodes(const ValueReceiver<const GraphNode&>& callback, const NODE_KIND &kind);

	//----------------------------------------------------------------------------------------
	/// Deselect all True Nodes and ports based on the NODE_KIND passed as parameter.
	/// @param[in] kind								The GraphNode's kind that will be deselected.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> DeselectAll(const NODE_KIND &kind);

	//----------------------------------------------------------------------------------------
	/// Removes the Wires between two True Nodes or Ports.
	/// @param[in] src								The source's GraphNode
	/// @param[in] dst								The destination's GraphNode
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> RemoveAllConnections(const GraphNode &src, const GraphNode &dst);

	MAXON_METHOD const Data* GetUserState(const NodePath& path, const InternedId& attr);

	MAXON_METHOD Int GetTransactionCount();

protected:
	// #LEGACYCOMPATIBILITY: (Ole) reorder methods
	MAXON_METHOD Result<void> CommitImpl(const DataDictionary& userData, Int nesting, Bool validate);

	MAXON_METHOD Result<BaseArray<GraphNode>> AddPorts(const GraphNode& parent, Int index, Int count);

	MAXON_METHOD Result<void> RemovePorts(const GraphNode& parent, const Block<const InternedId>& ports);

	MAXON_METHOD Result<Bool> IsConnectable(const GraphNode& src, const GraphNode& trg);

	MAXON_METHOD Result<Bool> PrivateGetConnections(const GraphNode& node, PORT_DIR dir, const ValueReceiver<const GraphConnection&>& callback, Wires inputMask, Wires outputMask, GraphModelInterface::GET_CONNECTIONS_MODE mode);
public:
	/// @copydoc GetNode
	MAXON_METHOD Result<GraphNode> GetNode(const PathBlock& path, Bool filtered = true);

public:
	MAXON_METHOD Result<Bool> GetModificationsSince(TimeStamp stamp, const ValueReceiver<const GraphNode&, MODIFIED>& receiver, Bool filtered);

	friend class GraphNode;
	friend class GraphTransaction;
	template <typename BASE> friend class GraphNodeFunctions;

	//-------------------------------------------------------------------------------------------------
	/// Find all GraphNode (true nodes or ports) that have the same name as the passed argument. 
	/// This function will return several nodes/port if they share the same name.
	/// @param[in] nodeName 						The name of the true node or the port
	/// @param[in] callback 						This callback will receive all ports and/or True Node that have the same name.
	/// @param[in] kind 								Filter that will be applied to the kind of GraphNode we are looking for. By default, All type (true node/ports)
	/// @param[in] direction 						Filter the GraphNode by direction. Input or Output.
	//-------------------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] MAXON_METHOD Result<void> FindAllGraphNodeByName(const String& nodeName, const ValueReceiver<const GraphNode&>& callback, const NODE_KIND &kind = NODE_KIND::ALL_MASK, const PORT_DIR direction = PORT_DIR::INPUT);
};


#include "graph1.hxx"

//----------------------------------------------------------------------------------------
/// Modifications to a GraphModelInterface may only be done when there is an active GraphTransaction.
/// You start a transaction by calling GraphModelInterface::BeginTransaction() on the graph
/// to modify. When all modifications are done, you call Commit() to make them permanent,
/// or Rollback() to return to the state of the graph when BeginTransaction() has been called.
///
/// Transactions can be nested. A commit or rollback ends the current (innermost) transaction,
/// but not enclosing transactions. However only the outmost transaction triggers the observables
/// GraphModelInterface::ObservableTransactionStarted, GraphModelInterface::ObservableTransactionCommitted,
/// GraphModelInterface::ObservableTransactionRolledBack.
///
/// If a GraphTransaction goes out of scope but is still active (Commit() or Rollback()
/// hasn't been called), a rollback is triggered implicitly by the destructor. This is
/// important for error handling, as it implies that in case of an unhandled error
/// an implicit rollback is made. This prevents inconsistent states of the graph.
//----------------------------------------------------------------------------------------
class GraphTransaction
{
public:
	GraphTransaction() = default;

	GraphTransaction(GraphTransaction&& src) = default;

	GraphTransaction& operator =(GraphTransaction&& src)
	{
		Rollback();
		_graph = std::move(src._graph);
		_nesting = src._nesting;
		return *this;
	}

	maxon::Result<void> CopyFrom(const GraphTransaction& src)
	{
		return maxon::FunctionNotImplementedError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// Does a rollback when this transaction is still active. This enables an automatic
	/// rollback to the previous consistent state of the graph in case of an error.
	//----------------------------------------------------------------------------------------
	~GraphTransaction()
	{
		if (_graph)
		{
			_graph.GetPointer()->RollbackImpl(_nesting);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Rolls back the graph to its state at the time this transaction has been started,
	/// and ends this transaction. If this transaction isn't nested within an enclosing
	/// transaction, the observable GraphModelInterface::ObservableTransactionRolledBack
	/// informs its observers about the rollback.
	//----------------------------------------------------------------------------------------
	void Rollback()
	{
		if (_graph)
		{
			_graph.GetPointer()->RollbackImpl(_nesting);
			_graph = nullptr;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Commits (ends) this transaction. The changes made within this transaction become
	/// permanent in the graph (unless this is a nested transaction and an enclosing transaction
	/// is rolled back later). If this transaction isn't nested within an enclosing
	/// transaction, the observable GraphModelInterface::ObservableTransactionCommitted
	/// informs its observers about the commit.
	///
	/// If this transaction isn't active, nothing happens.
	/// @param[in] userData						User data to pass to the observers of GraphModelInterface::ObservableTransactionCommitted.
	///																This will be merged with all given user data of nested commits.
	/// @param[in] validate						If false, no validation of the graph is made when this transaction is a nested one.
	///																This can be used to avoid unnecessary validations for nested transactions.
	//----------------------------------------------------------------------------------------
	Result<void> Commit(const DataDictionary& userData = GetPtrSizedZeroRef<DataDictionary>(), Bool validate = true);

	//----------------------------------------------------------------------------------------
	/// Returns the graph of this transaction, or a null reference when this transaction is inactive.
	/// @return												Graph of transaction, or null reference.
	//----------------------------------------------------------------------------------------
	const GraphModelRef& GetGraph() const
	{
		return _graph;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this transaction is active. A transaction is active between the initial call
	/// to GraphModelInterface::BeginTransaction() and the corresponding call to Commit() or Rollback().
	/// @return												@trueIfOtherwiseFalse{this transaction is active}
	//----------------------------------------------------------------------------------------
	Bool IsActive() const
	{
		return _graph.GetPointer() != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the nesting level of the transaction. The nesting level of an outmost transaction is 0.
	/// @return												Nesting level of the transaction.
	//----------------------------------------------------------------------------------------
	Int GetNesting() const
	{
		return _nesting;
	}	

private:
	GraphTransaction(const GraphModelRef& graph, Int nesting) : _graph(graph), _nesting(nesting)
	{
	}

	friend class GraphModelInterface;

	GraphModelRef _graph;
	Int _nesting = 0;
};


MAXON_DATATYPE(GraphTransaction, "net.maxon.graph.graphtransaction");

//----------------------------------------------------------------------------------------
/// GraphNodeBase is the protected base class of GraphNode. GraphNode adds no further data members,
/// therefore both have the same memory layout. You only have to work with
/// GraphNodeBase when you implement GraphModelInterface and need access to its data members.
//----------------------------------------------------------------------------------------
class GraphNodeBase
{
public:
	GraphModelRef _graph;							///< The graph model of this graph node.
	static const Int MEMCOUNT = 5;		///< Number of Int elements in _mem, currently 5.
	mutable Int _mem[MEMCOUNT];				///< Some storage space for free use by the GraphModelInterface implementation. Typically this holds information to identify the graph node such as a path.

	/// @private
	static const Bool HAS_ERROR = false;

	//----------------------------------------------------------------------------------------
	/// Returns this GraphNode, downcasted to its protected base class GraphNodeBase.
	/// This function is needed by implementations of GraphModelInterface to access the
	/// protected data members of GraphNodeBase.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	const GraphNodeBase& GetBase() const
	{
		return *this;
	}

	/// @copydoc GetBase
	GraphNodeBase& GetBase()
	{
		return *this;
	}

protected:
	const GraphNode& GetGraphNode() const;

	GraphModelInterface* PrivateGetGraph() const
	{
		return _graph.GetPointer();
	}

	const ThreadReferencedError& GetErrorStorage() const
	{
		return GetZeroRef<ThreadReferencedError>();
	}
};

#define PRIVATE_MAXON_GRAPHFN_PROLOGUE \
	iferr_scope; \
	if (BASE::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return this->GetErrorStorage(); \
	CheckStateDebugStop(this->PrivateGetGraph())

//----------------------------------------------------------------------------------------
/// Base class of GraphNode and Result<GraphNode> which implements most GraphNode functions.
//----------------------------------------------------------------------------------------
template <typename BASE> class GraphNodeFunctions : public BASE
{
public:
	GraphNodeFunctions() = default;
	template <typename ARG> explicit GraphNodeFunctions(ARG&& arg) : BASE(std::forward<ARG>(arg)) { }

	//----------------------------------------------------------------------------------------
	/// Removes this node from the graph. This will also remove all nested nodes as well
	/// as connections of this node and its nested ports.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Remove() const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->Remove(this->GetGraphNode());
	}

	//----------------------------------------------------------------------------------------
	/// Gets all children of this node. For a true node this will be its child nodes as well
	/// as a single input port list and a single output port list. Otherwise, the children are
	/// ports.
	/// @param[in] callback						This callback will receive all children.
	/// @return												false if #callback cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetChildren(const ValueReceiver<const GraphNode&>& callback, NODE_KIND mask = NODE_KIND::ALL_MASK) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetChildren(this->GetGraphNode(), callback, mask);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parent of this node.
	/// @return												Parent node of this node, or a null node if this node is the root node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> GetParent() const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetParent(this->GetGraphNode());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the closest ancestor node of this node (possibly this node itself) whose kind matches the given #mask.
	/// I.e., the function goes upwards in the hierarchy until it finds a matching node.
	/// @param[in] mask								Mask for the kind of node to look for.
	/// @return												Closest ancestor of this node matching the given #mask, may be this node itself or a null node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> GetAncestor(NODE_KIND mask) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetAncestor(this->GetGraphNode(), mask);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the input port list of this node. All top-level input ports of a node
	/// can be found as children of its input port list.
	/// @return												Input port list of this node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> GetInputs() const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), NodePathInterface::INPUTS, NODE_KIND::INPUTS);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the output port list of this node. All top-level output ports of a node
	/// can be found as children of its output port list.
	/// @return												Output port list of this node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> GetOutputs() const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), NodePathInterface::OUTPUTS, NODE_KIND::OUTPUTS);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the input or output port list of this node, depending on dir.
	/// @param[in] dir								PORT_DIR::INPUT to return the input port list, PORT_DIR::OUTPUT to return the output port list.
	/// @return												Port list of this node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> GetPortList(PORT_DIR dir) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), (dir == PORT_DIR::INPUT) ? NodePathInterface::INPUTS : NodePathInterface::OUTPUTS, (dir == PORT_DIR::INPUT) ? NODE_KIND::INPUTS : NODE_KIND::OUTPUTS);
	}

	//----------------------------------------------------------------------------------------
	/// Finds a child with the given id. This searches all direct children of this node for a child
	/// which has the identifier #name. The first found child is returned.
	/// @param[in] name								The identifier to look for.
	/// @return												The first direct child whose id is #name, or a null node.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> FindChild(const InternedId& name) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), name, NODE_KIND::ALL_MASK);
	}

	/// @copydoc FindChild
	Result<typename SFINAEHelper<GraphNode, BASE>::type> FindChild(const Id& name) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		InternedId iid;
		iid.Init(name) iferr_return;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), iid, NODE_KIND::ALL_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the child of this node whose kind matches the given #mask. If no such child can be found,
	/// a null node is returned. If there is more than one matching child, an error is returned.
	/// @param[in] mask								Kind mask to look for.
	/// @return												A direct child of this node which matches the given #mask, or a null node if no such child exists.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> FindChild(NODE_KIND mask) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindChild(this->GetGraphNode(), InternedId(), mask);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the inner child of this node with the given relative path.
	/// If no such child can be found, a null node is returned.
	/// @param[in] relativePath				The relative path of the child to find, starting at this node.
	/// @return												The inner child of this node with the given relativePath, or a null node if no such child exists.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> FindInnerNode(const PathBlock& relativePath) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->FindInnerNode(this->GetGraphNode(), relativePath);
	}

	//----------------------------------------------------------------------------------------
	/// Yields all inner nodes of this node matching #mask in pre-order. The recursive traversal
	/// stops at nodes which don't match #mask.
	/// @param[in] mask								Mask to filter the tree traversal. Only nodes matching this mask are considered.
	///																The node on which GetInnerNodes is called isn't checked for mask.
	/// @param[in] includeThis				If true, the node on which GetInnerNodes is called is yielded to #receiver too.
	/// @param[in] receiver						Inner nodes are reported to this value receiver.
	/// @return												false if #receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetInnerNodes(NODE_KIND mask, Bool includeThis, const ValueReceiver<const GraphNode&>& receiver) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetInnerNodes(this->GetGraphNode(), mask, includeThis, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a port to this node with the given id. This node has to be a port list or a port itself.
	/// @param[in] name								The identifier for the new port.
	/// @return												The added port.
	//----------------------------------------------------------------------------------------
	Result<typename SFINAEHelper<GraphNode, BASE>::type> AddPort(const Id& name) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->AddPort(this->GetGraphNode(), name);
	}
	
	//----------------------------------------------------------------------------------------
	/// Adds a number of variadic port instances to this variadic port. This is more efficient
	/// than a repeated call to AddPort().
	/// It is an error if this GraphNode is no variadic port.
	/// @param[in] index							The index within the current list of variadic port instances where the new instances shall be added.
	/// @param[in] count							The number of instances to add.
	/// @return												The newly added port instances as an array.
	//----------------------------------------------------------------------------------------
	Result<BaseArray<typename SFINAEHelper<GraphNode, BASE>::type>> AddPorts(Int index, Int count) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->AddPorts(this->GetGraphNode(), index, count);
	}

	//----------------------------------------------------------------------------------------
	/// Removes a number of variadic port instances from this variadic port. This is more efficient
	/// than a repeated call to Remove() on each of the instances.
	/// It is an error if this GraphNode is no variadic port.
	/// @param[in] ports							The identifiers of the port instances which shall be removed.
	//----------------------------------------------------------------------------------------
	Result<void> RemovePorts(const Block<const InternedId>& ports) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->RemovePorts(this->GetGraphNode(), ports);
	}

	//----------------------------------------------------------------------------------------
	/// Yields all connections of this port for the given direction #dir. Depending on the graph model implementation,
	/// this may include implicit wires due to connections between enclosing ports. The latter
	/// are marked with WIRE_MODE::IMPLICIT.
	/// @param[in] dir								Whether to yield incoming or outgoing connections.
	/// @param[in] conns							The receiver for the found connections.
	/// @param[in] mask								Only yield connections whose wires match this mask.
	/// @param[in] mode								Mode for GetConnections.
	/// @return												false if #conns cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetConnections(PORT_DIR dir, const ValueReceiver<const GraphConnection&>& conns, Wires mask = Wires::All(), GraphModelInterface::GET_CONNECTIONS_MODE mode = GraphModelInterface::GET_CONNECTIONS_MODE::CONNECTIONS) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetConnections(this->GetGraphNode(), dir, conns, mask, mode);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the Wires from this node to #target. Depending on the graph model implementation,
	/// this may include implicit wires due to connections between enclosing nodes. The latter
	/// are marked with WIRE_MODE::IMPLICIT.
	/// @param[in] target							Another graph node.
	/// @return												Wires between from this node to #target.
	//----------------------------------------------------------------------------------------
	Result<Wires> GetWires(const GraphNode& target) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetWires(this->GetGraphNode(), target);
	}

	//----------------------------------------------------------------------------------------
	/// Gets all attribute values of the connection from this port to target.
	/// @param[in] target							The other end of the connection.
	/// @param[out] receiver					All attribute values of the connection will be reported to the receiver.
	/// @return												false if #receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetConnectionValues(const GraphNode& target, const ValueReceiver<CONNECTION_POSITION, InternedId, const ConstDataPtr&>& receiver) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetConnectionValues(this->GetGraphNode(), target, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// a null ConstDataPtr is returned.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute value, may be nullptr if no check shall be done.
	/// @param[in] reverse						True if the connection shall be from target to this port (also #position is reversed in this case), false otherwise (the default).
	/// @return												The attribute value of the connection, or a null ConstDataPtr.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const InternedId& attr, const DataType& expectedType, Bool reverse = false) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return reverse ? this->PrivateGetGraph()->GetConnectionValue(target, this->GetGraphNode(), Reverse(position), attr, expectedType) : this->PrivateGetGraph()->GetConnectionValue(this->GetGraphNode(), target, position, attr, expectedType);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// an empty Opt is returned.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] reverse						True if the connection shall be from target to this port (also #position is reversed in this case), false otherwise (the default).
	/// @return												The attribute value of the connection, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<Opt<const T&>> GetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const InternedId& attr, Bool reverse = false) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetConnectionValue(target, position, attr, maxon::GetDataType<T>(), reverse) iferr_return;
		return Opt<const T&>(reinterpret_cast<const T*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute #attr for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// an empty Opt is returned.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @param[in] reverse						True if the connection shall be from target to this port (also #position is reversed in this case), false otherwise (the default).
	/// @return												The attribute value of the connection, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const ATTR& attr, Bool reverse = false) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetConnectionValue(target, position, attr.Get(), maxon::GetDataType<typename ATTR::ValueType>(), reverse) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for the connection from this port to #target. This will override any previously existing value.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	Result<Bool> SetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const InternedId& attr, ForwardingDataPtr&& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetConnectionValue(this->GetGraphNode(), target, position, attr, std::move(value));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const ATTR& attr, const typename ATTR::ValueType& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetConnectionValue(this->GetGraphNode(), target, position, attr.Get(), ConstDataPtr(value));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetConnectionValue(const GraphNode& target, CONNECTION_POSITION position, const ATTR& attr, typename ATTR::ValueType&& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetConnectionValue(this->GetGraphNode(), target, position, attr.Get(), MoveDataPtr(std::move(value)));
	}

	//----------------------------------------------------------------------------------------
	/// Connects this port to the other port #target using the given wire #modes.
	/// Usually you use one of the values WIRE_MODE::MIN, WIRE_MODE::NORMAL, WIRE_MODE::MAX for #modes,
	/// then a connection with a @ref Wires "value wire" of the given priority is created from this
	/// port to the #target port. But you can also add dependency and event wires by using an
	/// appropriate Wires value for #modes. And for each wire you can specify one of the special wire modes:
	/// - WIRE_MODE::NONE doesn't change the current wire mode.
	/// - WIRE_MODE::REMOVE removes the wire. If necessary, this hides inherited wires.
	/// - WIRE_MODE::INHERIT inherits the wire from a base node system.
	///
	/// Typically, you connect an output port of a root child node to an input port of another root child node.
	/// But you can also connect
	/// - an output port of a root child node to an output port of the root node
	///   (to forward the output of the child node to the root node)
	/// - an input port of the root node to an input port of a root child node,
	///   (to forward the input of the root node to the child node)
	/// - an input port of the root node to an output port of the same root node
	///   (to forward the input directly to the output without changing anything).
	///
	/// It is not possible to connect ports which don't belong to the root node or its direct children.
	///
	/// @param[in] target							The target port to connect to.
	/// @param[in] modes							The type to use for the connection.
	/// @param[in] reverse						If true the direction is reversed (from target to this port).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Connect(const GraphNode& target, Wires modes = WIRE_MODE::CONNECT_DEFAULT, Bool reverse = false) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->Connect(reverse ? target : this->GetGraphNode(), reverse ? this->GetGraphNode() : target, modes);
	}

	/// @copydoc Connect
	Result<void> Connect(const Result<typename SFINAEHelper<GraphNode, BASE>::type>& target, Wires modes = WIRE_MODE::CONNECT_DEFAULT, Bool reverse = false) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		if (target == FAILED)
			return target;
		return this->PrivateGetGraph()->Connect(reverse ? target.GetValue() : this->GetGraphNode(), reverse ? this->GetGraphNode() : target.GetValue(), modes);
	}

	//----------------------------------------------------------------------------------------
	/// Removes all connections of this port in the given direction which match the given mask.
	/// @param[in] dir								Connection direction.
	/// @param[in] mask								Mask for the connections to remove.
	//----------------------------------------------------------------------------------------
	Result<void> RemoveConnections(PORT_DIR dir, Wires mask = Wires::All(WIRE_MODE::FULL_MASK)) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->RemoveConnections(this->GetGraphNode(), dir, mask);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a connection from this port to target can be made.
	/// @param[in] target							Target port of the (hypothetical) connection.
	/// @return												True if a connection is allowed, false otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> IsConnectable(const GraphNode& target) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->IsConnectable(this->GetGraphNode(), target);
	}

	//----------------------------------------------------------------------------------------
	/// Gets all attribute values of this node.
	/// @param[out] map								All attribute values of this node will be added to #map.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetValues(GraphAttributeInterface::FLAGS mask, GraphAttributeMap& map) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetValues(this->GetGraphNode(), mask, map);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an attribute value from this node. Nothing happens if this node doesn't have
	/// a value for the given attribute.
	/// @param[in] attr								The attribute whose value shall be removed from this node.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	Result<Bool> RemoveValue(const InternedId& attr) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->RemoveValue(this->GetGraphNode(), attr);
	}

	//----------------------------------------------------------------------------------------
	/// Restores the inherited state of the value for #attr. This removes any value which has
	/// been set directly in this graph.
	/// @param[in] attr								The attribute whose value shall be inherited from the base graph.
	//----------------------------------------------------------------------------------------
	Result<Bool> InheritValue(const InternedId& attr) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->InheritValue(this->GetGraphNode(), attr);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for this node. If this node doesn't have a value
	/// for the attribute or the value doesn't have the expected type, a null ConstDataPtr is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute value, may be nullptr if no check shall be done.
	/// @return												The attribute value of this node, or a null ConstDataPtr.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetValue(const InternedId& attr, const DataType& expectedType) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetValue(this->GetGraphNode(), attr, expectedType);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the current value of the given attribute for this node, REGARDLESS of whether it is
	/// valid or not. If using lazy updates then this may be out of date.
	/// If NOT using lazy updates then this should always match GetValue().
	/// If this node doesn't have a value for the attribute or the value doesn't have the expected type,
	/// a null ConstDataPtr is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute value, may be nullptr if no check shall be done.
	/// @return												The attribute value of this node, or a null ConstDataPtr.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetStoredValue(const InternedId& attr, const DataType& expectedType) const // 200310
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetStoredValue(this->GetGraphNode(), attr, expectedType);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the values of the given attribute for this node and its inherited parents. If this node doesn't have a value
	/// for the attribute or the value doesn't have the expected type, GetBaseValues will keep iterating the inherited
	/// nodes and call #valueReceiver each time the attribute is found on an a base.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute value, may be nullptr if no check shall be done.
	/// @param[in] valueReceiver			A callback which receives the attribute values and their nestings.
	/// @return												The attribute values.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetBaseValues(const InternedId& attr, const DataType& expectedType, const ValueReceiver<const ConstDataPtr&, Int>& valueReceiver) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetBaseValues(this->GetGraphNode(), attr, expectedType, valueReceiver);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for this node. If this node doesn't have a value
	/// for the attribute or the value doesn't have type T, an empty Opt is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @tparam T											The expected type of the attribute value.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<Opt<const T&>> GetValue(const InternedId& attr) const
	{
		iferr_scope;
		ConstDataPtr value = GetValue(attr, maxon::GetDataType<T>()) iferr_return;
		return Opt<const T&>(reinterpret_cast<const T*>(value.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute #ATTR for this node. If this node doesn't have a value
	/// for the attribute of the correct type, an empty Opt is returned.
	/// @code
	/// String name = port.GetValue<decltype(Name)>().GetValueOrNull() iferr_return;
	/// @endcode
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetValue() const
	{
		iferr_scope;
		ConstDataPtr value = GetValue(ATTR::GetInstance(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(value.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute #attr for this node. If this node doesn't have a value
	/// for the attribute of the correct type, an empty Opt is returned.
	/// @code
	/// String name = port.GetValue(Name).GetValueOrNull() iferr_return;
	/// @endcode
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetValue(const ATTR& attr) const
	{
		iferr_scope;
		ConstDataPtr value = GetValue(attr.Get(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(value.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the current value of the given attribute for this node, REGARDLESS of whether it is
	/// valid or not. If using lazy updates then this may be out of date.
	/// If NOT using lazy updates then this should always match GetValue().
	/// If this node doesn't have a value
	/// for the attribute of the correct type, an empty Opt is returned.
	/// @code
	/// String name = port.GetStoredValue<decltype(Name)>().GetValueOrNull() iferr_return;
	/// @endcode
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetStoredValue() const
	{
		iferr_scope;
		ConstDataPtr value = GetStoredValue(ATTR::GetInstance(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(value.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the current value of the given attribute for this node, REGARDLESS of whether it is
	/// valid or not. If using lazy updates then this may be out of date.
	/// If NOT using lazy updates then this should always match GetValue().
	/// If this node doesn't have a value
	/// for the attribute of the correct type, an empty Opt is returned.
	/// @code
	/// String name = port.GetStoredValue(Name).GetValueOrNull() iferr_return;
	/// @endcode
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @return												The attribute value of this node, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetStoredValue(const ATTR& attr) const
	{
		iferr_scope;
		ConstDataPtr value = GetStoredValue(attr.Get(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(value.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for this node. This will override any previously existing value.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @param[in] checkAndInvalidate	True by default. Use false to suppress check, invalidation and update of time stamp.
	///																False may only be used for attributes which aren't needed during @ref GraphModelInterface::Validate "validation".
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	Result<Bool> SetValue(const InternedId& attr, ForwardingDataPtr&& value, Bool checkAndInvalidate = true) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetValue(this->GetGraphNode(), attr, std::move(value), checkAndInvalidate);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for this node. This will override any previously existing value.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(const ATTR& attr, const typename ATTR::ValueType& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetValue(this->GetGraphNode(), attr.Get(), ConstDataPtr(value), true);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for this node. This will override any previously existing value.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(const ATTR& attr, typename ATTR::ValueType&& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetValue(this->GetGraphNode(), attr.Get(), MoveDataPtr(std::move(value)), true);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(const typename ATTR::ValueType& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetValue(this->GetGraphNode(), ATTR::GetInstance(), ConstDataPtr(value), true);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(typename ATTR::ValueType&& value) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->SetValue(this->GetGraphNode(), ATTR::GetInstance(), MoveDataPtr(std::move(value)), true);
	}

	//----------------------------------------------------------------------------------------
	/// Marks the value of #attr as modified without actually modifying it. Use this if the value points to some external
	/// data which has changed without knowledge of the graph (for example a Url for a file which has been modified).
	/// If there is no value yet for attr, an IllegalStateError is returned.
	/// @param[in] attr								The attribute which shall be marked as modified.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> TouchValue(const InternedId& attr) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->TouchValue(this->GetGraphNode(), attr);
	}

	//----------------------------------------------------------------------------------------
	/// Sets a part of the value of #attr to #value for this node.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] op									The SubDataOperation to use.
	/// @param[in] path								The path to the part of the attribute value which shall be changed.
	/// @param[in] value							The new value for the part.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ChangeValue(const InternedId& attr, const SubDataOperation& op, const SubDataPathBlock& path, ForwardingDataPtr&& value)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->ChangeValue(this->GetGraphNode(), attr, op, path, std::move(value));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of the attribute DESCRIPTION::DATA::BASE::DEFAULTVALUE to #value for this port.
	/// This will override any values which would otherwise be inherited from a base port.
	/// @param[in] value							The value for the DefaultValue attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<Bool> SetDefaultValue(T&& value) const
	{
		iferr_scope;
		Data d;
		d.Set(std::forward<T>(value)) iferr_return;
		return SetValue<decltype(DESCRIPTION::DATA::BASE::DEFAULTVALUE)>(std::move(d));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the default value of this port. This is the value of the DefaultValue attribute,
	/// which in turn is synthesized from DESCRIPTION::DATA::BASE::DEFAULTVALUE: Default values are
	/// derived from right to left along connections.
	/// @tparam T											The type to return.
	/// @param[in] def								The value to return when there is no default value of matching type.
	/// @return												The default value of this port.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<const T&> GetDefaultValue(const T& def = maxon::NullValue<const T&>()) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(DefaultValue, GetDataType<T>()) iferr_return;
		return ptr.IsPopulated() ? *(const T*) ptr.PrivateGetPtr() : def;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the constant value of this port. The constant value is set whenever the graph
	/// implementation is able to determine a constant value for the port, either because the
	/// default value has been set directly at the port, or because it is possible to compute
	///	the value from connected ports and nodes.
	/// @tparam T											The type to return.
	/// @param[in] def								The value to return when there is no constant value of matching type.
	/// @return												The constant value of this port.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<const T&> GetConstantValue(const T& def = maxon::NullValue<const T&>()) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(ConstantValue, GetDataType<T>()) iferr_return;
		return ptr.IsPopulated() ? *(const T*) ptr.PrivateGetPtr() : def;
	}

	//----------------------------------------------------------------------------------------
	/// Reports all attribute modifications which have been made for this node since the given stamp to the receiver.
	/// Only stored attributes will be reported, so to also check for new values of computed
	/// attributes you should use GraphAttributeInterface::IsComputedFrom().
	/// @see GraphModelInterface::GetModificationsSince
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @param[in] receiver						Modifications are reported to this receiver as a pair of the attribute identifier and the current value.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetAttributeModificationsSince(TimeStamp stamp, const ValueReceiver<InternedId, ConstDataPtr>& receiver) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetAttributeModificationsSince(this->GetGraphNode(), stamp, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the modification stamp of the given attribute for this node. This is the value of
	/// the graph's time stamp (see GraphModelInterface::GetModificationStamp) at the time when
	/// the attribute value has been set last for this node, or a null value if it hasn't been set
	/// at all.
	/// @param[in] attr								An attribute.
	/// @return												The modification stamp of the last change of the attribute value.
	//----------------------------------------------------------------------------------------
	Result<TimeStamp> GetAttributeStamp(const InternedId& attr) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetAttributeStamp(this->GetGraphNode(), attr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the modification stamp of incoming/outgoing connections for this port. This is the value of
	/// the graph's time stamp (see GraphModelInterface::GetModificationStamp) at the time when
	/// connections in the given direction have been modified last for this port.
	/// @param[in] direction					The connection direction.
	/// @return												The modification stamp of the last connection change of the port.
	//----------------------------------------------------------------------------------------
	Result<TimeStamp> GetConnectionStamp(PORT_DIR direction) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetConnectionStamp(this->GetGraphNode(), direction);
	}

	//----------------------------------------------------------------------------------------
	/// Copies all directly set attribute values of #source to this node. This excludes
	/// derived attribute values as well as attribute values which are inherited from a base.
	/// @param[in] source							Another GraphNode, may stem from a different graph.
	/// @param[in] includeInner				If true, copies attribute values for all inner nodes, too.
	//----------------------------------------------------------------------------------------
	Result<void> CopyValuesFrom(const GraphNode& source, Bool includeInner) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->CopyValuesFrom(this->GetGraphNode(), source, includeInner);
	}

	//----------------------------------------------------------------------------------------
	/// Copies all connections of #source to the port given by this GraphNode. For each connection of #source
	/// to a port in the given #direction, a corresponding port in this graph is searched (based on the
	/// relative path) and, if it exists, a connection to that port is created.
	/// @param[in] source							Another GraphNode port, may stem from a different graph.
	/// @param[in] direction					The direction of connections to copy.
	/// @param[in] includeInner				If true, copies connections for all inner nodes, too.
	//----------------------------------------------------------------------------------------
	Result<void> CopyConnectionsFrom(const GraphNode& source, PORT_DIR direction, Bool includeInner) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->CopyConnectionsFrom(this->GetGraphNode(), source, direction, includeInner);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the message flags of the given attribute at this node. You have to call this method
	/// if you want to check if an attribute has a message (an error or a warning) for this node.
	///
	/// @param[in] attr								The attribute which shall be asked.
	/// @return												Message flags (GraphAttribute::FLAGS::WARNING, GraphAttribute::FLAGS::ERROR) of #attr at this node.
	///
	/// @see GraphAttributeInterface::GetMessageFlags
	//----------------------------------------------------------------------------------------
	Result<GraphAttribute::FLAGS> GetMessageFlags(const InternedId& attr) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetMessageFlags(this->GetGraphNode(), attr);
	}

	//----------------------------------------------------------------------------------------
	/// Yields the error or warning messages (if any) of the given attribute at this node to #receiver.
	///
	/// @param[in] attr								The attribute which shall be asked.
	/// @param[in] receiver						All messages are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetMessages(const InternedId& attr, const ValueReceiver<const GraphMessage&>& receiver) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetMessages(this->GetGraphNode(), attr, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the node is selected or not
	/// @return												@trueIfOtherwiseFalse{the node is selected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<Bool> IsSelected() const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->IsSelected(this->GetGraphNode());
	}

	//----------------------------------------------------------------------------------------
	/// Creates and returns a new OutputPort that correspond to the name passed as argument
	/// @param[in] id									The id of the port that need to be created.
	/// @param[in] name								The name of the port that need to be created.
	/// @return												The created port.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<typename SFINAEHelper<GraphNode, BASE>::type> CreateOutputPort(const CString& id, const String& name = String("Output"))
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->CreateOutputPort(this->GetGraphNode(), id, name);
	}
	
	//----------------------------------------------------------------------------------------
	/// Creates and returns a new InputPort that correspond to the name passed as argument
	/// @param[in] id									The id of the port that need to be created.
	/// @param[in] name								The name of the port that need to be created.
	/// @return												The created port.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<typename SFINAEHelper<GraphNode, BASE>::type> CreateInputPort(const CString& id, const String& name = String("Input"))
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->CreateInputPort(this->GetGraphNode(), id, name);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the first level of nodes connected to the input port of this node.
	/// @param[in] callback								The callback that will receive all connected nodes.
	/// @param[in] filter										The NODE_KIND that will be included
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> GetDirectPredecessors(const ValueReceiver<const GraphNode&>& callback, NODE_KIND filter = NODE_KIND::NODE) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetDirectPredecessors(this->GetGraphNode(), callback, filter);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes connected to the input port of this node.
	/// @param[in] callback								The callback that will receive all connected nodes.
	/// @param[in] filter										The NODE_KIND that will be included
		//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> GetAllPredecessors(const ValueReceiver<const GraphNode&>& callback, NODE_KIND filter = NODE_KIND::NODE) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetAllPredecessors(this->GetGraphNode(), callback, filter);
	}


	//----------------------------------------------------------------------------------------
	/// Retrieves the first level of nodes connected to the output port of this node.
	/// @param[in] callback								The callback that will receive all connected nodes.
	/// @param[in] filter										The NODE_KIND that will be included.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> GetDirectSuccessors(const ValueReceiver<const GraphNode&>& callback, NODE_KIND filter = NODE_KIND::NODE) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetDirectSuccessors(this->GetGraphNode(), callback, filter);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves all nodes connected to the output port of this node.
	/// @param[in] callback								The callback that will receive all connected nodes.
	/// @param[in] filter										The NODE_KIND that will be included.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> GetAllSuccessors(const ValueReceiver<const GraphNode&>& callback, NODE_KIND filter = NODE_KIND::NODE) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->GetAllSuccessors(this->GetGraphNode(), callback, filter);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this port is connected to another port.
	/// @paramn[in] port									The other port to check the connection with.
	/// @return														@trueIfOtherwiseFalse{ports are connected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<Bool> IsConnectedTo(const GraphNode& port) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->IsConnectedTo(this->GetGraphNode(), port);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this port is connected to another port.
	/// @paramn[in] portName							The other port's name to check the connection with.
	/// @return														@trueIfOtherwiseFalse{ports are connected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<Bool> IsConnectedTo(const String& portName) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->IsConnectedTo(this->GetGraphNode(), portName);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this port is connected to another port.
	/// @paramn[in] portId								The other port's ID to check the connection with.
	/// @return														@trueIfOtherwiseFalse{ports are connected}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<Bool> IsConnectedTo(const Id& portId) const
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->IsConnectedTo(this->GetGraphNode(), portId);
	}

	//----------------------------------------------------------------------------------------
	/// Connect this node with another node to a port found by its name.
	/// @param[in] dst 						the node that have the port we want to connect to
	/// @param[in] portName 			the port's name we need to found						
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> Connect(const GraphNode& dst, const String &portName )
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->Connect(this->GetGraphNode(), dst, portName);
	}

	//----------------------------------------------------------------------------------------
	/// Connect this node with another node to a port found by its Id.
	/// @param[in] dst 						the node that have the port with want to connect to
	/// @param[in] portId 				the port's id we need to found						
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> Connect(const GraphNode& dst, const Id& portId)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->Connect(this->GetGraphNode(), dst, portId);
	}

	//----------------------------------------------------------------------------------------
	/// Mutes the connection from the current port to the passed port.
	/// @paramn[in] port									The other port the connection must be muted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> MuteConnectionWith(const GraphNode& port)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->MuteConnectionWith(this->GetGraphNode(), port);
	}


	//----------------------------------------------------------------------------------------
	/// Mutes the connection from the current port to the passed port's name.
	/// @paramn[in] portName							The other port's name the connection must be muted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> MuteConnectionWith(const String& portName)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->MuteConnectionWith(this->GetGraphNode(), portName);
	}


	//----------------------------------------------------------------------------------------
	/// Mutes the connection from the current port to the passed port.
	/// @paramn[in] portId								The other port's id the connection must be muted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> MuteConnectionWith(const Id& portId)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->MuteConnectionWith(this->GetGraphNode(), portId);
	}

	//----------------------------------------------------------------------------------------
	/// Mutes the connection from the current port to the passed port.
	/// @paramn[in] direction							The direction where all connection will be muted
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> MuteAllConnections(PORT_DIR direction)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->MuteAllConnections(this->GetGraphNode(), direction);
	}

	//----------------------------------------------------------------------------------------
	/// Unmutes the connection from the current port to the passed port.
	/// @paramn[in] port									The other port that the connection must be Unmuted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> UnmuteConnectionWith(const GraphNode& port)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->UnmuteConnectionWith(this->GetGraphNode(), port);
	}

	//----------------------------------------------------------------------------------------
	/// Unmutes the connection from the current port to the passed port.
	/// @paramn[in] portName							The other port's name that the connection must be Unmuted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> UnmuteConnectionWith(const String& portName)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->UnmuteConnectionWith(this->GetGraphNode(), portName);
	}

	//----------------------------------------------------------------------------------------
	/// Unmutes the connection from the current port to the passed port.
	/// @paramn[in] portId									The other port's Id that the connection must be Unmuted.
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> UnmuteConnectionWith(const Id& portId)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->UnmuteConnectionWith(this->GetGraphNode(), portId);
	}

	//----------------------------------------------------------------------------------------
	/// Unmutes all the connection in one direction
	/// @paramn[in] direction							The direction where all connection will be Unmuted
	/// @return														if error
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<void> UnmuteAllConnections(PORT_DIR direction)
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->UnmuteAllConnections(this->GetGraphNode(), direction);
	}

	//----------------------------------------------------------------------------------------
	/// Removes all connection this node have.
	/// @return														@trueIfOtherwiseFalse{the connection were removed}.
	//----------------------------------------------------------------------------------------
	[[deprecated("Use GraphModelHelper static functions")]] Result<Bool> RemoveAllConnections()
	{
		PRIVATE_MAXON_GRAPHFN_PROLOGUE;
		return this->PrivateGetGraph()->RemoveAllConnections(this->GetGraphNode());
	}
};


template <typename SUPER> class GraphNodeResultBase;

//----------------------------------------------------------------------------------------
/// A GraphNode represents a general node (g-node for short) in the hierarchy of a GraphModelInterface.
/// There are five different kinds of such a node: It may be a true node,
/// an input or output port or an input port list or output port list. A node may have
/// attributes, and if it is a port, it may be connected to other ports. For a general
/// overview, see GraphModelInterface.
///
/// Most functions of GraphNode can be used for all node kinds, some functions are specific
/// for certain kinds (such as Connect which is only supported for ports).
///
/// GraphNode holds a strong GraphModelRef reference on the graph, see GetGraph(). The node within the graph
/// is referenced symbolically by a NodePath, see GetPath(). Therefore it is guaranteed for the referenced
/// graph that it exists as long as the GraphNode, but not for the referenced node.
/// Namely, a GraphNode can be in one of three states:
/// 1. It may be a null value, then it doesn't represent any node. IsNull() returns true in this state.
/// 2. It may be a valid node in a graph (IsValid() returns true). GetGraph() returns the graph, GetPath() the path of the node,
///    and all supported functions can be called.
/// 3. It represents a node which doesn't exist any longer. IsValid() returns false, but IsPopulated()
///    still returns true. Also GetGraph() and GetPath() return valid values, but you can't call any functions
///    which would require access to the node. Such a state can be used to identify deleted nodes.
/// A transition between the cases 2 and 3 can happen without this GraphNode being directly involved,
/// namely when the graph is modified through another GraphNode and a node with the path
/// of this GraphNode is added or removed.
//----------------------------------------------------------------------------------------
class GraphNode : public GraphNodeFunctions<Protected<GraphNodeBase>>
{
public:
	using GraphNodeBase::GetBase;

	//----------------------------------------------------------------------------------------
	/// Checks whether this GraphNode points to a valid node. This is not the same as IsPopulated():
	/// - IsValid() return true if the node is a valid, existing node in the graph.
	/// - IsPopulated() also returns true for graph nodes which point to non-existing (deleted) nodes.
	///   They have a valid graph and path to identify the node, but you can't call any function
	///   which would require access to the node.
	/// @return												True if this GraphNode points to a valid node,
	///																false if it is a null node or a reference to a deleted node.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _graph && _graph.GetPointer()->IsValid(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Checks whether this GraphNode has graph and path references. This is not the same as IsValid(),
	/// because IsPopulated() just checks if graph and path are set, but not if the graph really
	/// contains a node with the path, see IsValid().
	/// Therefore we also don't have an IsEmpty() counterpart, because it would hide
	/// that there are two different functions to check the content of a GraphNode.
	/// @return												True if this GraphNode has graph and path set, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _graph.GetPointer() != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this GraphNode belongs to an inner node of the graph. The root node and
	/// its port lists and ports aren't inner nodes, all other nodes are.
	/// @return												True if this GraphNode is an inner node of the graph.
	//----------------------------------------------------------------------------------------
	Bool IsInner() const;

	//----------------------------------------------------------------------------------------
	/// Returns the graph to which this node belongs.
	/// @return												Owning graph of this node.
	//----------------------------------------------------------------------------------------
	const GraphModelRef& GetGraph() const
	{
		return _graph;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the path of this node. It is not guaranteed that a node with that path still exists
	/// in the graph, to check this use IsValid().
	/// @return												Path of this node.
	//----------------------------------------------------------------------------------------
	const NodePath& GetPath() const
	{
		return _graph ? _graph.GetPointer()->GetPath(*this) : NodePath::NullValue();
	}

	/// @copydoc GetPath
	operator const NodePath&() const
	{
		return GetPath();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this node. This is the last part of the @ref GetPath "path",
	/// so it's unique within the siblings of this node, but not within the whole graph.
	/// @return												Identifier of this node.
	//----------------------------------------------------------------------------------------
	const InternedId& GetId() const
	{
		return _graph ? _graph.GetPointer()->GetPath(*this).GetLastId() : GetPtrSizedZeroRef<InternedId>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the kind of this node. This can be used to check whether this node is a true node,
	/// a port or a port list, see NODE_KIND and GraphModelInterface.
	/// @return												Kind of this node.
	//----------------------------------------------------------------------------------------
	NODE_KIND GetKind() const
	{
		return _graph ? _graph.GetPointer()->GetKind(*this) : NODE_KIND::NONE;
	}

	GraphNode() = default;

	~GraphNode()
	{
		if (_graph)
			_graph.GetPointer()->Destruct(*this);
	}

	GraphNode(GraphNode&& src)
	{
		_graph = std::move(src._graph);
		for (Int i = 0; i < MEMCOUNT; ++i)
		{
			_mem[i] = src._mem[i];
		}
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GraphNode);

	GraphNode(const GraphNode& src)
	{
		_graph = src._graph;
		if (_graph)
			_graph.GetPointer()->CopyConstruct(*this, src);
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(GraphNode);

	/// @copydoc DefaultDoc::Reset
	void Reset()
	{
		if (_graph)
		{
			_graph.GetPointer()->Destruct(*this);
			_graph = nullptr;
		}
	}

	/// @copydoc DefaultDoc::operator==
	Bool operator ==(const GraphNode& other) const
	{
		return (_graph == other._graph) && (!_graph || _graph.GetPointer()->IsSame(*this, other));
	}

	/// @copydoc DefaultDoc::operator!=
	Bool operator !=(const GraphNode& other) const
	{
		return !this->operator ==(other);
	}

	/// @copydoc DefaultDoc::GetHashCode
	HashInt GetHashCode() const
	{
		return _graph ? _graph.GetPointer()->GetNodeHashCode(*this) : 0;
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs = nullptr) const
	{
		return _graph ? _graph.GetPointer()->NodeToString(*this, fs) : "null"_s;
	}

	/// @private
	template <typename SUPER> using ResultFunctions = GraphNodeFunctions<GraphNodeResultBase<SUPER>>;

	friend class GraphNodeBase;
	friend class GraphModelInterface;
	friend class GraphNodeFunctions<Protected<GraphNodeBase>>;
	friend class GraphNodeFunctions<GraphNodeResultBase<ResultBase<GraphNode>>>;
};

template <> struct IsZeroInitialized<GraphNode> : public std::true_type { };

template <typename SUPER> class GraphNodeResultBase : public SUPER
{
public:
	GraphNodeResultBase() = default;
	template <typename ARG> explicit GraphNodeResultBase(ARG&& arg) : SUPER(std::forward<ARG>(arg)) { }

	GraphModelInterface* PrivateGetGraph() const
	{
		return this->GetValue().GetGraph().GetPointer();
	}

	const GraphNode& GetGraphNode() const
	{
		return this->GetValue();
	}
};

inline const GraphNode& GraphNodeBase::GetGraphNode() const
{
	return static_cast<const GraphNode&>(*this);
}

MAXON_DATATYPE(GraphNode, "net.maxon.graph.graphnode");


//----------------------------------------------------------------------------------------
/// Returns the direction for connections of the given port in the context of the graph model.
/// For an input port this function usually returns PORT_DIR::INPORT,
/// however if the input port is at the root level of the graph model (as defined by
/// GraphModelInterface::GetRootPath(), this is not necessarily the absolute top level because
/// the graph model may be a nested one) then the returned direction is PORT_DIR::OUTPUT because
/// connections will start at the port. Same for output ports.
/// @param[in] port								A port.
/// @return												The direction of connections of the port in the context of its graph model.
//----------------------------------------------------------------------------------------
inline PORT_DIR GetConnectionDirection(const GraphNode& port)
{
	return port.IsInner() ? GetPortDirection(port.GetKind()) : Reverse(GetPortDirection(port.GetKind()));
}


//----------------------------------------------------------------------------------------
/// GraphLib contains some static functions for graphs.
//----------------------------------------------------------------------------------------
class GraphLib
{
	MAXON_INTERFACE_NONVIRTUAL(GraphLib, MAXON_REFERENCE_NONE, "net.maxon.graph.interface.graphlib");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a GraphAttribute with the given name and flags
	/// @param[in] attr								The name of the attribute.
	/// @param[in] flags							The flags of the attribute.
	/// @return												A new GraphAttribute with the given name and flags.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphAttribute> CreateAttribute(const InternedId& attr, GraphAttributeInterface::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Creates a GraphMessage.
	/// @param[in] flags							The flags of the message.
	/// @param[in] origin							The origin of the message.
	/// @param[in] value							The ToString function of #value will be called to implement GraphMessageInterface::Format.
	/// @return												A new GraphMessage for the given parameters.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphMessage> CreateMessage(GraphAttributeInterface::FLAGS flags, const NodePath& origin, const ConstDataPtr& value);

	//----------------------------------------------------------------------------------------
	/// Creates a new instance of a simple implementation of GraphModelInterface. The simple graph model
	/// only manages plain nodes, ports and connections, but it doesn't support advanced features like
	/// inheritance from base graphs, derived attributes, implicit connections, rollback of transactions
	/// or change lists.
	/// @return												A new GraphModelRef which uses a simple implementation of GraphModelInterface.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphModelRef> CreateSimpleGraphModel();

	//----------------------------------------------------------------------------------------
	/// Writes a graph to a GML file (Graph Modeling Language).
	/// @param[in] graph							The graph to write.
	/// @param[in] output							The output stream to write to.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteGml(const GraphModelRef& graph, UrlOrOutputStream&& output);

	//----------------------------------------------------------------------------------------
	/// Returns a PartFormatter which formats NodePath and GraphNode parts using their effective names.
	/// Also DataType parts are formatted with the help of DataTypeBuilderInterface::GetDataTypeName.
	/// @param[in] graph							The graph to use for name lookup.
	/// @return												A PartFormatter which can be used to format node-related error messages.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ErrorInterface::PartFormatter CreatePathFormatter(const GraphModelRef& graph);

	//----------------------------------------------------------------------------------------
	/// Extracts a node path from the given message. If the message was formatted by the formatter
	/// created by CreatePathFormatter, this function will find the first occurrence of a formatted
	/// node path and return its original NodePath. Otherwise it will return an empty node path
	/// (unless the message happens to contain a substring which matches a formatted node path).
	/// @param[in] message						An error message created by CreatePathFormatter.
	/// @return												The NodePath of the first path contained in the message, or an empty path if no path can be found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> ExtractNodePath(const String& message);
};

#include "graph2.hxx"

}

#endif // GRAPH_H__
