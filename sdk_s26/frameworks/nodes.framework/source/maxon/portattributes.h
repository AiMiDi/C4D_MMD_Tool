#ifndef PORTATTRIBUTES_H__
#define PORTATTRIBUTES_H__

#include "maxon/optional.h"
#include "maxon/graphattribs.h"
#include "maxon/arraymap.h"

namespace maxon
{

namespace nodes
{

class NodeSystemClass;
class Port;
class GNode;

using NodePathArraySet = ArraySet<NodePath, true, FastNodePathHash>;
using NodePathArraySetRef = StrongCOWRef<NodePathArraySet>;

//----------------------------------------------------------------------------------------
/// This attribute controls whether nested ports shall be @ref usernode_derivation_ports "derived"
/// for a port or not. The derivation is based on the nested ports of connected source ports,
/// i.e., it goes from left to right. By default the value of this attribute is true.
/// @see SynthesizeNestedPorts
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, InheritNestedPorts, "inheritnestedports");

//----------------------------------------------------------------------------------------
/// This attribute controls whether nested ports shall be @ref usernode_derivation_ports "derived"
/// for a port or not. The derivation is based on the nested ports of connected target ports,
/// i.e., it goes from right to left. By default the value of this attribute is true.
/// @see InheritNestedPorts
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, SynthesizeNestedPorts, "synthesizenestedports");

//----------------------------------------------------------------------------------------
/// This attribute controls whether the port is used as source for the @ref usernode_derivation_ports "derivation"
/// of nested ports. Only if the value is true connected downstream ports will inherit nested ports of this port.
/// By default the value of this attribute is true.
/// @see InheritPortSource
/// @see InheritNestedPorts
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, InheritNestedPortsSource, "inheritnestedportssource");

//----------------------------------------------------------------------------------------
/// This attribute controls whether the port is used as source for the @ref usernode_derivation_ports "derivation"
/// of nested ports. Only if the value is true connected upstream ports will inherit nested ports of this port.
/// By default the value of this attribute is true.
/// @see SynthesizeNestedPorts
/// @see SynthesizePortSource
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, SynthesizeNestedPortsSource, "synthesizenestedportssource");

//----------------------------------------------------------------------------------------
/// This attribute controls whether the port is used as source for the @ref usernode_derivation_ports "derivation"
/// of nested ports. Only if the value is true this port will be inherited to a connected downstream port of its parent port.
/// By default the value of this attribute is true.
/// @see InheritNestedPortsSource
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, InheritPortSource, "inheritportsource");

//----------------------------------------------------------------------------------------
/// This attribute controls whether the port is used as source for the @ref usernode_derivation_ports "derivation"
/// of nested ports. Only if the value is true this port will be inherited to a connected upstream port of its parent port.
/// By default the value of this attribute is true.
/// @see SynthesizeNestedPortsSource
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, SynthesizePortSource, "synthesizeportsource");

//----------------------------------------------------------------------------------------
/// This attribute controls whether the port is used as source for the derivation of the data type.
/// Only if the value is true connected upstream ports will use the data type in the derivation.
/// By default the value of this attribute is true.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, SynthesizeTypeSource, "synthesizetypesource");

//----------------------------------------------------------------------------------------
/// This attribute has to be set to true for a port which is the source of a loop-carried dependency.
/// Corresponding targets have to be marked with LoopDependencyTarget and reachable through
/// dependency wires, where the first wire (starting at the source) needs to have a parallel slink wire
/// and the last wire (reaching the target) needs to have a parallel tlink wire.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, LoopDependencySource, "loopdependencysource");

//----------------------------------------------------------------------------------------
/// This attribute has to be set to true for a port which is the target of a loop-carried dependency,
/// see LoopDependencySource.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, LoopDependencyTarget, "loopdependencytarget");

//----------------------------------------------------------------------------------------
/// This attribute tells whether the port's value is usually set or computed at run-time of the compiled
/// node system. You have to mark all run-time inputs of a node system with this flag,
/// also a node with an underlying computation method for the values of its output ports
/// (for example, a core node wrapper) has to set this value for all of its outputs.
/// Note that the value of the port may still be computed at compile-time as a constant value
/// during validation if all required inputs have constant values.
///
/// The value of this attribute must not be modified after first validation.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, Dynamic, "dynamic");

//----------------------------------------------------------------------------------------
/// This attribute is similar to Dynamic, but it may be modified after first validation
/// and won't be serialized. It's used for ports which are dynamic due to node-system-external
/// circumstances, for example when a port's value is animated from the outside.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, TransientDynamic, "transientdynamic");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for input ports which define a template parameter of a NodeTemplate.
/// It enables a special handling of those ports during validation: Whenever the
/// @ref ConstantValue "constant value" of such a port doesn't match the value used for the
/// template instantiation the template is re-instantiated with the derived constant value as argument for the
/// template parameter, and the new instantiation replaces the previous one in the node system.
///
/// It is an error if no constant value can be derived for such a port
/// unless the AllowDynamicArgument flag is set.
///
/// A variadic port which is a template parameter of a NodeTemplate has to be marked with
/// DESCRIPTION::DATA::BASE::ISVARIADIC instead, this also activates the special handling.
///
/// @see AllowDynamicArgument
/// @see TypeTemplateParameter
/// @see BundleTemplateParameter
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, TemplateParameter, "templateparameter");

//----------------------------------------------------------------------------------------
/// This attribute can be set in addition to TemplateParameter to allow dynamic values as
/// arguments for the template parameter. Usually a dynamic (non-constant) value is an error,
/// but when this flag is enabled an empty Data is used as template argument instead.
/// This can be used by templates which allow for optimized instantiations for certain
/// constant values (such as 0 or 1) and otherwise use a generic instantiation.
///
/// @see TemplateParameter
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, AllowDynamicArgument, "allowdynamicargument");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for input ports whose PortType defines a template parameter of a NodeTemplate.
/// Similar to TemplateParameter it enables a special handling of those ports during validation: Whenever the
/// @ref PortType "port type" of such a port doesn't match the value used for the
/// template instantiation (which can be found in the TemplateArgument attribute
/// of the port) the template is re-instantiated with the port type as argument for the
/// template parameter, and the new instantiation replaces the previous one in the node system.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, TypeTemplateParameter, "porttypetemplateparameter");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for ports whose set of nested ports defines a template parameter of a NodeTemplate.
/// Similar to TemplateParameter it enables a special handling of those ports during validation: Whenever the
/// set of nested ports of such a port doesn't match the value used for the
/// template instantiation the template is re-instantiated with the set as argument for the
/// template parameter, and the new instantiation replaces the previous one in the node system.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, BundleTemplateParameter, "bundletemplateparameter");

//----------------------------------------------------------------------------------------
/// This attribute is a computed attribute which can be queried for template parameter ports
/// and returns the actually used template argument for that parameter. Usually this is the
/// same as the ConstantValue, but there are cases where both differ,
/// for example if ConstantValue has an illegal template argument which the node template
/// substitutes by a legal one.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Data, TemplateArgument, "templateargument");

//----------------------------------------------------------------------------------------
/// This attribute is useful only when combined with TypeTemplateParameter attribute (true).
/// Otherwise, the attribute just has no effect. It allows the template argument to stick to the
/// port even if the type template source port is disconnect. In other words, the port will
/// remember the the last data type that was connected to it even if disconnected.
/// Usually, this allows to have templated node maintain their outputs after a templated input is disconnected,
/// otherwise outgoing connections could be lost.
/// By default the value of this attribute is true. There are cases, namely when TypeTemplateParameter value can change dynamically
/// depending current connections, where we don't want the type to be sticky.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, StickyTypeTemplateParameter, "stickyporttypetemplateparameter");

//----------------------------------------------------------------------------------------
/// Set a detailed node template error in this attribute to indicate graph validation failure
/// using a red colored node or group. The message will be visible to users, so it shall be readable.
/// This error is quite useful to avoid cases of incompatible scenes after type changes or type removal.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Error, TemplateError, "templateerror");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for input ports which require a constant value. Whenever the user
/// connects the port in a way such that a constant value for the port can't be computed,
/// this is an error in the node setup.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, ConstantParameter, "constantparameter");

//----------------------------------------------------------------------------------------
/// This attribute can be set by a NodeTemplate at a port to prevent the derivation
/// of a DefaultValue for that port. By default the value of this attribute is true.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, SynthesizeDefaultValue, "synthesizevalue");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for ports whose values shall be accessible at evaluation time.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, TappingPort, "tappingport");

//----------------------------------------------------------------------------------------
/// When this attribute is true for a root node of a node system then that node system
/// can be converted to a user-editable group.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IsGroup, "isgroup");

//----------------------------------------------------------------------------------------
/// When this attribute is true for a group node this means that the group can't be dissolved
/// into its components (e.g. because it has some extra semantics like ports which receive
/// context or hidden nodes inherited from a base).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IndissolubleGroup, "indissolublegroup");

//----------------------------------------------------------------------------------------
/// This attribute has to be set to true for ports which mustn't be deleted.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, Permanent, "permanent");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for ports which shall be hidden when seen from the inside
/// (so when they belong to the group which is currently shown in the node editor).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, HiddenFromInside, "hiddeninside");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for ports which shall be hidden when seen from the outside
/// (so when they belong to a child node of the group which is currently shown in the node editor).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, HiddenFromOutside, "hiddenoutside");

//----------------------------------------------------------------------------------------
/// This attribute has to be set for input or output ports which have a known fixed type
/// (as opposed to a port with a dynamic type which is derived from e.g. its connections).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, FixedPortType, "fixedtype");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for a port which has a valid FixedPortType to enforce
/// that values flowing through that port are converted to the port type. It is only needed
/// for ports which just forward the value. For example the ports of a wrapped core node
/// dont't have to set this attribute because value forwarding ends at those ports
/// anyway, but the value node needs to set it because it just forwards values from
/// its input port to its output port. Without this attribute the port types of intermediate
/// ports are ignored.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, EnforceType, "enforcetype");

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the effective type of an input or output port.
/// It is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, PortType, "type");

//----------------------------------------------------------------------------------------
/// You have to set this attribute at the final port of a subgraph which shall be compiled
/// into a function. The members of the given TupleDataType are the function parameters, and
/// the port (and its nested ports) define the function results. The function parameters
/// become context members of the subgraph, so they can be queried anywhere in that subgraph
/// by using ports with a matching ContextReference attribute.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(TupleDataType, FunctionParameters, "functionparams");

//----------------------------------------------------------------------------------------
/// You have to set this attribute at a port which, when it doesn't receive a value through
/// a connection or a default value, shall receive the value from the context member
/// identified by the given InternedId.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(InternedId, ContextReference, "ctxref");

//----------------------------------------------------------------------------------------
/// You have to set this attribute at a port which is used to provide values for context members
/// if the port's name doesn't match the desired name of the context members.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(InternedId, ContextDefinition, "ctxdef");

//----------------------------------------------------------------------------------------
/// You have to set this attribute if a port shall define context members for its immediately enclosing port.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, ExternalContext, "externalcontext");

//----------------------------------------------------------------------------------------
/// A port can be marked with this flag if it has been created by propagation of a port of an
/// inner node to its enclosing node. Then it will automatically be removed by
/// NodeSystemClassInterface::FinalizeModification when the inner propagation connection is removed.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, CreatedByPropagation, "net.maxon.node.createdbypropagation");

//----------------------------------------------------------------------------------------
/// A port can be put into a port group by this attribute. The port group is only used for
/// visual purposes, it has no functional meaning. The NodePath is used as a group path,
/// so if a port shall be part of a top-level group then use a NodePath of one element,
/// for a nested group you have to use more path elements.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(NodePath, PortGroup, "net.maxon.node.portgroup");

// stylecheck.naming=false
[[deprecated("Use the PortDescriptionUi for group assignments.")]] extern PortGroup_PrivateAttribute PortGroup;
// stylecheck.naming=true

//----------------------------------------------------------------------------------------
/// This attribute can be set on ports for which a NodeTemplate wants to keep control over the
/// ordering of some or all of it's ports. If set to true, the NODE::ATTRIBUTE::ORDERINDEX set
/// on the port by the NodeTemplate will be kept when resources are applied on the node.
/// By default the value of this attribute is false.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, OverrideOrderIndex, "overrideorderindex");

//----------------------------------------------------------------------------------------
/// This attribute is set to enforce the name derivation mechanism for variadic ports.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, ForceVariadicPortNameDerivation, "forcevariadicportnamederivation");

//----------------------------------------------------------------------------------------
/// This attribute can be set on a node to restrict description derivation to the node itself.
/// Any connected nodes aren't considered for description derivation.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, InternalDescriptionDerivation, "internaldescriptionderivation");

//----------------------------------------------------------------------------------------
/// This attribute is set internally within groups to pass the port type of the enclosing node system
/// to the group's input, this helps to ensure correct template instantiations within groups if the template
/// arguments stem from an enclosing node system.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, DefaultInheritedType, "net.maxon.node.defaultinheritedtype");

//----------------------------------------------------------------------------------------
/// This attribute is set internally within groups to pass the port type of the enclosing node system
/// to the group's output, this helps to ensure correct template instantiations within groups if the template
/// arguments stem from an enclosing node system.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, DefaultSynthesizedType, "net.maxon.node.defaultsynthesizedtype");

//----------------------------------------------------------------------------------------
/// Type of the PortFlags attribute.
//----------------------------------------------------------------------------------------
enum class PORT_FLAGS
{
	NONE = 0,																				///< No flag set.
	HIDDEN = 1,																			///< The port shall be hidden.
	USED_FOR_TEMPLATE_ARGUMENT = 2,									///< The port is used for an argument for a TemplateParameter of a node template.
	USED_FOR_INPUTPORTTYPE_TEMPLATE_ARGUMENT = 4,		///< The port is used for an argument for a TypeTemplateParameter of an input port of a node template.
	CONSTANT = 8,																		///< It is required that the port has a constant value.
	VARIADIC = 16,																	///< The port is a variadic port, possibly with a fixed count (don't confuse with a variadic port instance).
	VARIADIC_TEMPLATE = 32,													///< The port is a true variadic port (don't confuse with a variadic port instance). Set in addition to VARIADIC.
	INHERITS_NESTED_PORTS = 64,											///< The port inherits nested ports from upstream ports, see InheritNestedPorts.
	SYNTHESIZES_NESTED_PORTS = 128,									///< The port synthesizes nested ports from downstream ports, see SynthesizeNestedPorts.
	HAS_CHILDREN = 256,															///< The port has children (so it's a port bundle or a variadic port).
	USED_FOR_INPUTBUNDLE_TEMPLATE_ARGUMENT = 512,		///< The port is used for an argument for an BundleTemplateParameter of an input port of a node template.
	CHAIN = 1024,																		///< The port belongs to a chain.
	DYNAMIC = 2048,																	///< The port is marked with the Dynamic or TransientDynamic attribute.
} MAXON_ENUM_FLAGS(PORT_FLAGS);

//----------------------------------------------------------------------------------------
/// The PortFlags attribute is a derived attribute which can be queried at a port to get
/// some information about the port, see PORT_FLAGS.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(PORT_FLAGS, PortFlags, "portflags");


struct Chain
{
	NodePath counterPort;
	InternedId inId;
	InternedId outId;

	Bool IsEqual(const NodePath& port, const Chain& other, Int otherNesting) const
	{
		return inId == other.inId && outId == other.outId
			&& counterPort.IsEqual(port.Slice(0, otherNesting), other.counterPort, true);
	}

	String ToString(const FormatStatement* fs = nullptr) const
	{
		return FormatString("(chain @,@,@)", counterPort, inId, outId);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(Chain, counterPort, inId, outId);
};

MAXON_DATATYPE(Chain, "net.maxon.node.datatype.chain");
MAXON_ATTRIBUTE(StrongCOWRef<Chain>, ChainCounterPort, "chaincounterport");


//----------------------------------------------------------------------------------------
/// This attribute can be set for ports which shall receive a global context value.
/// Such a global context value can't be overridden in the node system. The value of this
/// attribute identifies which global context value shall be set for the port.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(InternedId, GlobalContext, "globalcontext");


//----------------------------------------------------------------------------------------
/// The ScenePortMode attribute is a derived attribute which can be queried at a port to get
/// the NODE::ATTRIBUTE::SCENEPORTMODE attribute with the exception that for a variadic port
/// the value of ScenePortMode is always SCENEPORTMODE_ENUM_NONE. This is useful because a
/// variadic scene port has a scene port mode, but is no scene port itself (only its instances are).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(InternedId, ScenePortMode, "sceneportmode");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for port bundles if the resources of member ports
/// shall be obtained from attribute resources.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, UseAttributeResources, "useattributeresources");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for nodes that will ignore their first base
/// in HasBase and GetAllBases calls.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IgnoreBase, "ignorebase");

//----------------------------------------------------------------------------------------
/// This attribute has to be set to true for ports which shall allow the creation
/// of multiple incoming connections via the node editor.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, AllowMultipleConnections, "allowmultipleconnections");

//----------------------------------------------------------------------------------------
/// This registry contains GraphAttributes which implement a special handling of the attribute
/// for node systems, see NodeSystemClassInterface::GetGraphAttribute. You can use this to
/// register your own attributes, for example to register an attribute which shall be transient
/// (not saved during serialization):
/// @code{nodes_registerattribute}
//! MAXON_ATTRIBUTE(Bool, CheckUniqueNumber, "checkuniquenumber");
//! ...
//! MAXON_DECLARATION_REGISTER(Attributes, )
//! {
//! 	objectId = CheckUniqueNumber;
//! 	return GraphLib::CreateAttribute(CheckUniqueNumber, GraphAttribute::FLAGS::DIRECT | GraphAttribute::FLAGS::TRANSIENT | GraphAttribute::FLAGS::META);
//! }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(GraphAttribute, Attributes, "net.maxon.node.registry.attributes");

//----------------------------------------------------------------------------------------
/// DerivedAttributeInterface stands for derived attributes of ports.
///
/// The public declaration as well as the access to values of derived attributes is the same
/// as for non-derived attributes, namely with MAXON_ATTRIBUTE. However,
/// the values of derived attributes can't be set directly, instead they are derived based on
/// other values of a NodeSystem.
//----------------------------------------------------------------------------------------
class DerivedAttributeInterface : MAXON_INTERFACE_BASES(GraphAttributeInterface)
{
	MAXON_INTERFACE(DerivedAttributeInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.derivedattribute");
public:
	//----------------------------------------------------------------------------------------
	/// There are three kinds of derived attributes:
	/// 1. INHERITED: These are inherited attributes in the sense of attribute grammars, i.e., for a port
	///   their value is derived based on values at the port and its direct predecessors in the graph.
	///   The NodeTemplate which created the node of the port decides how exactly the derivation is carried out
	///		(via NodeTemplateInterface::DeriveAttributeValue).
	/// 2. SYNTHESIZED: The opposite of inherited attributes, i.e., for a port
	///   their value is derived based on values at the port and its direct successors in the graph.
	///   The NodeTemplate which created the node of the port decides how exactly the derivation is carried out
	///		(via NodeTemplateInterface::DeriveAttributeValue).
	/// 3. COMPUTED: These attributes are computed on the fly using ComputeAttributeValue when a value is requested.
	//----------------------------------------------------------------------------------------
	enum class KIND
	{
		NONE = 0,
		INHERITED = 1,													///< The attribute is an inherited attribute whose value is derived from values at direct predecessor ports.
		SYNTHESIZED = 2,												///< The attribute is a synthesized attribute whose value is derived from the values at direct successor ports.
		COMPUTED = 4,														///< The attribute is computed on-the-fly whenever its value is requested.
		FILTERED = 8,														///< This flag has to be set for inherited or synthesized attributes which shall use the derivation filter for connections
		INDUCED_DEPENDENCIES = 16,							///< This flag has to be set for inherited or synthesized attributes when the derivation needs induced dependencies as well (see GraphModelInterface::GET_CONNECTIONS_MODE::INDUCED_DEPENDENCIES).
		NODE_PRE = 32,													///< The attribute is a derived attribute for true nodes which has to be derived before ports.
		NODE_POST = 64,													///< The attribute is a derived attribute for true nodes which has to be derived after ports.
		DERIVED_MASK = INHERITED | SYNTHESIZED	///< Use this to test for derived port attributes (INHERITED or SYNTHESIZED).
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	//----------------------------------------------------------------------------------------
	/// The flags of this enum tell on which ports (relative to the current port) a derived attribute depends.
	//----------------------------------------------------------------------------------------
	enum class DEPENDENCY
	{
		NONE = 0,											///< No flags.

		SELF = 1 << 0,								///< The attribute depends on another attribute value of the same port. Can be used for node or port attributes.
		CHILDREN = 1 << 1,						///< The attribute depends on attribute values of children ports. Can be used for node attributes only.
		PARENT = 1 << 2,							///< The attribute depends on attribute values of parent ports.
		HAS_CHILDREN = 1 << 3,				///< The attribute depends on the port's property of having children.

		VALUE_SOURCES = 1 << 8,				///< The attribute depends on attribute values of ports of incoming value connections. Can be used for port attributes only.
		VALUE_TARGETS = 1 << 9,				///< The attribute depends on attribute values of ports of outgoing value connections. Can be used for port attributes only.
		DEP_SOURCES = 1 << 10,				///< The attribute depends on attribute values of ports of incoming dependency connections. Can be used for port attributes only.
		DEP_TARGETS = 1 << 11,				///< The attribute depends on attribute values of ports of outgoing dependency connections. Can be used for port attributes only.

		VALUE_DEP_SOURCES = VALUE_SOURCES | DEP_SOURCES,
		VALUE_DEP_TARGETS = VALUE_TARGETS | DEP_TARGETS,

		SOURCES_MASK = VALUE_DEP_SOURCES,
		TARGETS_MASK = VALUE_DEP_TARGETS,

		SHORTCUT_SOURCES = 1 << 12,		///< The attribute depends on attribute values of ports of incoming connections. Can be used for port attributes only.
		SHORTCUT_TARGETS = 1 << 13,		///< The attribute depends on attribute values of ports of outgoing connections. Can be used for port attributes only.

		INDUCED_SOURCES = 1 << 14,		///< The attribute depends on attribute values of ports of incoming connections. Can be used for port attributes only.
		INDUCED_TARGETS = 1 << 15,		///< The attribute depends on attribute values of ports of outgoing connections. Can be used for port attributes only.

		CTX_SOURCES_DEEP = 1 << 16,		///< The attribute depends on attribute values of ports of incoming context connections. Can be used for port attributes only.
		CTX_TARGETS_DEEP = 1 << 17,		///< The attribute depends on attribute values of ports of outgoing context connections. Can be used for port attributes only.

		SHORTCUT_SOURCES_MASK = SHORTCUT_SOURCES | INDUCED_SOURCES | CTX_SOURCES_DEEP,
		SHORTCUT_TARGETS_MASK = SHORTCUT_TARGETS | INDUCED_TARGETS | CTX_TARGETS_DEEP,

		SOURCES_ALL = SOURCES_MASK | SHORTCUT_SOURCES_MASK,
		TARGETS_ALL = TARGETS_MASK | SHORTCUT_TARGETS_MASK
	} MAXON_ENUM_FLAGS_CLASS(DEPENDENCY);

	//----------------------------------------------------------------------------------------
	/// Returns the kind of this attribute, i.e., whether it is an inherited, synthesized or computed attribute.
	/// @return												Kind of this attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD KIND GetKind() const;

	[[deprecated]] MAXON_METHOD Bool IsNeededFor(const NodeSystemClass& cls) const;

	//----------------------------------------------------------------------------------------
	/// Returns the dependencies of this derived attribute as attribute/DEPENDENCY pairs.
	/// This has to include all other attributes which are needed for the derivation of this attribute.
	/// @return												Dependencies of this attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Tuple<InternedId, DEPENDENCY>> GetDependencies() const;

	//----------------------------------------------------------------------------------------
	/// Compares two derived attribute values for equality. Usually this is the same as
	/// @c{newValue == oldValue}, but there are derived attributes whose values have to be interpreted
	/// in the context of the enclosing nodes.
	/// @param[in] newValue						The newly derived attribute value for port.
	/// @param[in] port								The port for which newValue has been derived.
	/// @param[in] oldValue						The previously derived attribute value for port.
	/// @param[in] oldNesting					The nesting depth of the port's node which derived oldValue in the current node system.
	/// @return												True if both values are equal, taking into account the nesting.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool ValuesEqual(const ConstDataPtr& newValue, const NodePath& port, const ConstDataPtr& oldValue, Int oldNesting) const;

	//----------------------------------------------------------------------------------------
	/// Derives the value of this attribute (either a synthesized or an inherited attribute)
	/// for the port given by the last element of nesting. The derivation may use attribute values of
	/// - the port itself
	/// - its enclosing ports (which are also found in nesting) as well as its nested ports,
	///   but if the value of this attribute itself is queried, then only enclosing ports are allowed
	///   if KIND::POST_ORDER isn't set, otherwise only nested ports
	/// - direct predecessor ports in case of an inherited attribute
	/// - direct successor ports in case of a synthesized attribute.
	///
	/// But the dependency of this attribute on the accessed attributes has to be properly reflected
	/// by GetDependencies.
	/// @param[in] nesting						The port for which the attribute value shall be derived (last element) and its enclosing ports.
	/// @return												The derived attribute value, or an empty Opt if there shall be no derived value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<Data>> DeriveAttributeValue(const Block<const Port>& nesting) const;

	//----------------------------------------------------------------------------------------
	/// Computes the value of this computed attribute for the given node.
	/// @param[in] node								The g-node for which the attribute value shall be computed.
	/// @param[in] expectedType				The expected type of the value. If this is non-null, the returned value has to be castable to that type.
	/// @return												The computed attribute value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ConstDataPtr> ComputeAttributeValue(const GNode& node, const DataType& expectedType) const;
};

/// Id prefix used for filling the NODE::ATTRIBUTE::ASSETID attribute on wrapped CoreNodes.
/// The rest of the Id will be the CoreNode's real registered Id.
constexpr Char g_corePrefix[] = "net.maxon.corenode:";

#include "portattributes1.hxx"
#include "portattributes2.hxx"

}

} // namespace maxon

#endif // PORTATTRIBUTES_H__
