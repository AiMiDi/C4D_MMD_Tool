#ifndef GRAPHATTRIBS_H__
#define GRAPHATTRIBS_H__

#include "maxon/datadescription.h"
#include "maxon/datadescriptiondefinition.h"
#include "maxon/datadictionary.h"
#include "maxon/hashmap.h"
#include "maxon/nodepath.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// A GraphAttributeMap collects the current values of attributes of a node or port, see GraphModelInterface::GetValues.
//----------------------------------------------------------------------------------------
using GraphAttributeMap = HashMap<InternedId, ConstDataPtr>;

class GraphNode;

//----------------------------------------------------------------------------------------
/// The OrderIndex attribute is used to define the order of ports within the same parent.
/// The values needn't be contiguous, just their relative order matters.
///
/// For a NodeSystem-based graph this is a derived attribute which can't be set directly,
/// you have to set NODE::ATTRIBUTE::ORDERINDEX instead.
/// This will be used to derive the value for OrderIndex.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Int, OrderIndex, "orderindex");

//----------------------------------------------------------------------------------------
/// The InsertIndex attribute tells about the temporal order in which sibling ports have been added to the graph.
/// This is not to be confused with OrderIndex which defines the actual order to use.
///
/// For a NodeSystem-based graph this is a derived attribute which can't be set directly,
/// you have to set NODE::ATTRIBUTE::INSERTINDEX instead.
/// This will be used to derive the value for InsertIndex.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Int, InsertIndex, "insertindex");

//----------------------------------------------------------------------------------------
/// The DefaultValue attribute is a derived attribute to query the default value of a port.
/// The attribute value has to be derived by the graph implementation, typically this takes into
/// account the value of the attribute DESCRIPTION::DATA::BASE::DEFAULTVALUE and, if that
/// value isn't set, the default values of connected ports.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Data, DefaultValue, "default");

//----------------------------------------------------------------------------------------
/// The ConstantValue attribute is a derived attribute to query the constant value of a port.
/// The attribute value has to be derived by the graph implementation, typically this takes into
/// account the DefaultValue, port connections and also functional nodes which can be
/// evaluated during validation of the graph when their inputs are known constants too.
///
/// If no constant value can be derived for the port, the value is an empty Data.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Data, ConstantValue, "constant");

//----------------------------------------------------------------------------------------
/// The EffectiveName attribute is a derived attribute which contains the user-visible
/// name of a node or port.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(String, EffectiveName, "effectivename");


class GraphMessage;

//----------------------------------------------------------------------------------------
/// A graph attribute provides extra information about an attribute of nodes and ports.
/// Attributes are identified and accessed only by an InternedId which carries no extra
/// information about the attribute. If a GraphModelInterface wants to provide additional
/// information for an attribute, its GraphModelInterface::GetGraphAttribute returns
/// a graph attribute to get that information (such as the attribute FLAGS).
//----------------------------------------------------------------------------------------
class GraphAttributeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GraphAttributeInterface, MAXON_REFERENCE_CONST, "net.maxon.graph.interface.attribute");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the id of this attribute.
	/// @return												Id of this attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const InternedId& GetId() const;

	//----------------------------------------------------------------------------------------
	/// FLAGS provide information about the nature of the attribute.
	/// Exactly one of DIRECT, DERIVED, USER_STATE or DERIVED|USER_STATE has to be set
	/// in the flags returned by GetFlags().
	//----------------------------------------------------------------------------------------
	enum class FLAGS
	{
		/// No flag set.
		NONE = 0,

		/// The attribute is an attribute which can be set directly by program code.
		DIRECT = 1,

		/// The attribute is a derived attribute which can't be set by program code.
		/// The graph model implementation will derive its value from the graph.
		DERIVED = 2,

		/// The attribute is a user-state attribute which can be set by program code and doesn't belong to the persistent state of the graph.
		/// User-state attributes can be set outside of a GraphTransaction, and there is the method GraphModelInterface::ResetUserState.
		/// A user-state attribute also has to set the TRANSIENT flag. The flag DERIVED can be set in addition for a derived user-state attribute.
		USER_STATE = 4,

		/// The attribute is transient (non-persistent, i.e., not stored by serialization).
		TRANSIENT = 8,

		/// The attribute value can only be set once on creation of the node or port.
		IMMUTABLE = 16,

		/// The attribute is a meta attribute whose value is irrelevant for the data model and runtime behaviour of the graph.
		/// What exactly this means is graph-model-specific.
		META = 32,

		/// The attribute is a graph-global attribute which is stored at the root. When the value of such an attribute is read,
		/// it is always read at the root node even if the GetValue method was called on another node. Inner graphs will use
		/// the root node of their outmost enclosing graph.
		ROOT = 64,

		/// The attribute represents a warning message. Typically this is a user-state attribute set during the analysis of the graph
		/// to inform about questionable findings.
		WARNING = 0x10000,

		/// The attribute represents an error message. Typically this is a user-state attribute set during the analysis of the graph
		/// to inform about found errors.
		ERROR = 0x20000,

		/// Use this mask to test for the type (one of DIRECT, DERIVED, USER_STATE or DERIVED|USER_STATE).
		TYPE_MASK = DIRECT | DERIVED | USER_STATE,

		/// Use this mask to test for WARNING or ERROR.
		MESSAGE_MASK = WARNING | ERROR

	} MAXON_ENUM_FLAGS_CLASS(FLAGS);

	//----------------------------------------------------------------------------------------
	/// Checks for a @ref FLAGS::DERIVED "derived" attribute if its value is computed
	/// on-the-fly and needs the value of #other for that computation. A derived attribute
	/// may store its value in the graph, or it may compute it on-the-fly. In the latter
	/// case you can check the required attributes with this method. This is important e.g.
	/// when you check for attribute modifications using GraphNodeFunctions::GetAttributeModificationsSince:
	/// You only get notified about changes of stored attribute values, so for a computed value
	/// you have to use this method:
	/// @code{nodes_iscomputedfrom}
	//! GraphNode node;
	//! const GraphAttribute& def = node.GetGraph().GetGraphAttribute(DefaultValue);
	//! return node.GetAttributeModificationsSince(stamp,
	//! 	[&def] (const InternedId& attr, ConstDataPtr value) -> Result<Bool>
	//! 	{
	//! 		if (def.IsComputedFrom(attr))
	//! 		{
	//! 			// default value has changed
	//! 		}
	//! 		else
	//! 		{
	//! 			// test for other attributes
	//! 		}
	//! 		return true;
	//! 	});
	/// @endcode
	/// You can use this method even for non-computed attributes, then it returns true if
	/// #other is the same as #this.
	///
	/// @param[in] other							Another attribute.
	/// @return												True if #other is the same as #this, or if #this is a computed
	/// 															attribute which needs #other to compute its value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsComputedFrom(const InternedId& other) const;

	//----------------------------------------------------------------------------------------
	/// Returns the flags of this attribute. If FLAGS::ERROR or FLAGS::WARNING is set, this means
	/// that the attribute can contain an error or warning, however a check for a concrete node
	/// using GetMessageFlags has to be done to test if the value of the attribute at that node
	/// really contains an error or warning.
	///
	/// Usually you shouldn't call this method directly, but use GraphModelInterface::GetGraphAttributeFlags.
	///
	/// @return												Flags of this attribute.
	/// @MAXON_ANNOTATION{default=GraphAttributeInterface::FLAGS::DIRECT}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD FLAGS GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Returns the message flags of the attribute value at #node. An attribute which may contain
	/// an error or warning according to GetFlags() doesn't necessarily have to do so, you have
	/// to test for a concrete node if the value of the attribute at that node really contains an error or warning.
	///
	/// Usually you shouldn't call this method directly, but use GraphNode::GetMessageFlags.
	///
	/// @param[in] node								A node or port where the message flags of this attribute shall be checked.
	/// @return												Message flags (FLAGS::WARNING, FLAGS::ERROR) of this attribute at #node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<FLAGS> GetMessageFlags(const GraphNode& node) const;

	//----------------------------------------------------------------------------------------
	/// Yields the messages of this attribute at #node to #receiver.
	///
	/// Usually you shouldn't call this method directly, but use GraphNode::GetMessages.
	///
	/// @param[in] node								A node or port at which the messages shall be obtained.
	/// @param[in] receiver						All messages are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetMessages(const GraphNode& node, const ValueReceiver<const GraphMessage&>& receiver) const;
};


//----------------------------------------------------------------------------------------
/// A graph message is an error or warning message to tell the user about issues found in the graph.
/// A graph attribute which has one of GraphAttributeInterface::FLAGS::ERROR, GraphAttributeInterface::FLAGS::WARNING
/// set can produce such messages via the method GraphAttributeInterface::GetMessages.
/// To query for messages use GraphNode::GetMessages.
//----------------------------------------------------------------------------------------
class GraphMessageInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GraphMessageInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.graph.interface.message");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the flags of this message, either GraphAttributeInterface::FLAGS::ERROR,
	/// GraphAttributeInterface::FLAGS::WARNING or both.
	/// @return												Message flags.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphAttributeInterface::FLAGS GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Returns the origin of the message. The graph model implementation may propagate a message
	/// along connections, for example to make a message for a nested node visible at the outside of a group.
	/// In such cases the origin tells where the message originates.
	/// @return												The origin of the message.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodePath& GetOrigin() const;

	//----------------------------------------------------------------------------------------
	/// Formats this message in a user-friendly way.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction.
	/// @return												A human-readable message.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> Format(const FormatStatement* formatStatement) const;
};


#include "graphattribs1.hxx"

#include "graphattribs2.hxx"

} // namespace maxon

#endif // GRAPHATTRIBS_H__
