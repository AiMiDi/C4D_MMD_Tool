#ifndef PORTATTRIBUTES_H__
#define PORTATTRIBUTES_H__

#include "maxon/optional.h"
#include "maxon/graphattribs.h"
#include "maxon/arraymap.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// The TemplateArguments class implements a dictionary which stores template arguments
/// for instantiations of NodeTemplates. It implements a two-level dictionary:
/// - The first level stores /default arguments/. This level is set by user code when a
///		node template instantiation is initially added to a node system. The default arguments
///		are never changed implicitly.
/// - The second level stores /deduced/ or /explicit/ values, these have higher priority than default arguments.
/// 	Deduced values get implicitly set during node system validation:
/// 	Whenever a template parameter is available as a port and a ConstantValue
///   can be deduced for that port, that value is used as argument for the template parameter
///   by making a corresponding override in the TemplateArguments.
///
/// Template arguments are usually identified by their relative port path within the node template
/// and the kind of template argument. For a given port there may be several arguments if the
/// port represents several template parameters (for example a TypeTemplateParameter as well as a TemplateParameter).
//----------------------------------------------------------------------------------------
class TemplateArguments
{
public:
	//----------------------------------------------------------------------------------------
	/// This enum lists the different kinds of template arguments. Exacly one of VALUE, TYPE, BUNDLE
	/// has to be set.
	//----------------------------------------------------------------------------------------
	enum class KIND : UChar
	{
		NONE = 0,				///< No flag set.
		DEDUCED = 1,		///< This flag can be used in combination with the other flags if the value has been deduced from the node graph.
		EXPLICIT = 16,	///< This flag can be used in combination with the other flags if the value has been explicitly set.
		VALUE = 2,			///< The template argument is for a port which is marked as TemplateParameter.
		TYPE = 4,				///< The template argument is for a port which is marked as TypeTemplateParameter.
		BUNDLE = 8,			///< The template argument is for a port which is marked as BundleTemplateParameter.
		MASK = 14				///< Anything but DEDUCED or EXPLICIT.
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	using KeyType = Tuple<NodePath, KIND>;

	/// @copydoc DefaultDoc::DefaultDoc
	TemplateArguments() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a TemplateArguments object with the given default arguments.
	/// @param[in] defaultArgs				The default arguments.
	//----------------------------------------------------------------------------------------
	explicit TemplateArguments(const DataDictionary& defaultArgs) : _args(defaultArgs)
	{
	}

	/// @copydoc DefaultDoc::Reset
	void Reset()
	{
		_args = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the default value for the template parameter path to value. Deduced or explicit values aren't removed.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @param[in] value							The default value for the template parameter.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetDefault(const NodePath& path, KIND kind, T&& value)
	{
		return _args.SetData(ConstDataPtr(ToTuple(path, kind)), ForwardingDataPtr(std::forward<T>(value)));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the explicit value for the template parameter path to value.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @param[in] value							The explicit value for the template parameter.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetExplicit(const NodePath& path, KIND kind, T&& value)
	{
		return _args.SetData(ConstDataPtr(ToTuple(path, kind | KIND::EXPLICIT)), ForwardingDataPtr(std::forward<T>(value)));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the default value for the template parameter path to value, and removes
	/// a deduced value if there is one.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @param[in] value							The default value for the template parameter.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetDefaultRemoveDeduced(const NodePath& path, KIND kind, T&& value)
	{
		iferr_scope;
		_args.EraseData(ConstDataPtr(ToTuple(path, kind | KIND::DEDUCED))) iferr_return;
		_args.SetData(ConstDataPtr(ToTuple(path, kind)), ForwardingDataPtr(std::forward<T>(value))) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Removes any value (default or overridden) for the template parameter path.
	/// If there is no such value, nothing happens.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	//----------------------------------------------------------------------------------------
	Result<void> Remove(const NodePath& path, KIND kind)
	{
		iferr_scope;
		_args.EraseData(ConstDataPtr(ToTuple(path, kind | KIND::DEDUCED))) iferr_return;
		_args.EraseData(ConstDataPtr(ToTuple(path, kind | KIND::EXPLICIT))) iferr_return;
		_args.EraseData(ConstDataPtr(ToTuple(path, kind))) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all entries of args on top of this object. So if both TemplateArguments have
	/// entries for the same template parameter, the value stored in this object will
	/// be overwritten with that of args.
	/// @param[in] args								Another TemplateArguments object to add to this object.
	//----------------------------------------------------------------------------------------
	Result<void> Add(const TemplateArguments& args);

	//----------------------------------------------------------------------------------------
	/// Returns the value for the template parameter identified by the given path.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												The argument for the parameter.
	//----------------------------------------------------------------------------------------
	Opt<const Data&> Get(const NodePath& path, KIND kind) const
	{
		return GetImpl(path, kind);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value for the template parameter identified by the given path.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												The argument for the parameter.
	//----------------------------------------------------------------------------------------
	template <typename T> Opt<const T&> Get(const NodePath& path, KIND kind) const
	{
		const Data* d = GetImpl(path, kind);
		return d ? d->GetPtr<T>() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value for the value template parameter identified by the given path.
	/// @param[in] path								The path of the template parameter.
	/// @return												The argument for the parameter.
	//----------------------------------------------------------------------------------------
	template <typename T> Opt<const T&> GetValueArgument(const NodePath& path) const
	{
		const Data* d = GetImpl(path, KIND::VALUE);
		return d ? d->GetPtr<T>() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value for the bundle template parameter identified by the given path.
	/// @param[in] path								The path of the template parameter.
	/// @return												The argument for the parameter.
	//----------------------------------------------------------------------------------------
	Opt<const Array<InternedId>&> GetBundleArgument(const NodePath& path) const
	{
		const Data* d = GetImpl(path, KIND::BUNDLE);
		return d ? d->GetPtr<Array<InternedId>>() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value for the type template parameter identified by the given path.
	/// @param[in] path								The path of the template parameter.
	/// @return												The argument for the parameter.
	//----------------------------------------------------------------------------------------
	Opt<const DataType&> GetTypeArgument(const NodePath& path) const
	{
		const Data* d = GetImpl(path, KIND::TYPE);
		return d ? d->GetPtr<DataType>() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the template parameter identified by path has a default value.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												True if template parameter path has a default value, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasDefault(const NodePath& path, KIND kind) const
	{
		return _args.Contains(ToTuple(path, kind));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the template parameter identified by path has a deduced value.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												True if template parameter path has a deduced value, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasDeduced(const NodePath& path, KIND kind) const
	{
		return _args.Contains(ToTuple(path, kind | KIND::DEDUCED));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the template parameter identified by path has an explicit value.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												True if template parameter path has an explicit value, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasExplicit(const NodePath& path, KIND kind) const
	{
		return _args.Contains(ToTuple(path, kind | KIND::EXPLICIT));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if there is a value for the template parameter identified by path.
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	/// @return												True if there is a value for template parameter path, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool Contains(const NodePath& path, KIND kind) const
	{
		return _args.Contains(ToTuple(path, kind)) || _args.Contains(ToTuple(path, kind | KIND::DEDUCED)) || _args.Contains(ToTuple(path, kind | KIND::EXPLICIT));
	}

	//----------------------------------------------------------------------------------------
	/// Yields all arguments for NodePath-identified parameters to receiver. receiver has to accept
	/// (const NodePath&, TemplateArguments::KIND, const Data&) as arguments and return a Result<Bool>, where false as result
	/// value stops yielding of further arguments. For parameters which have both a default and a
	/// deduced/explicit value only the deduced/explicit value is reported.
	/// @param[in] receiver						A callback which receives the arguments.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	template <typename OP> Result<Bool> GetPathArguments(OP&& receiver) const
	{
		yield_scope;
		for (const auto& a : _args)
		{
			const DataType& t = a.GetKey().GetType();
			if (t.Is<KeyType>())
			{
				const KeyType& key = a.GetKey().Get(KeyType());
				// Process argument if the type is DEDUCED or EXPLICIT
				// OR
				// if the TemplateArguments dictionary doesn't contain the same key with DEDUCED or EXPLICIT.
				// I.e. if the DEDUCED key is anywhere in the arguments and current #key is VALUE type only, we don't process it.
				// Has keys can be duplicated with various KIND values in the dictionary.
				if (key.second & (KIND::DEDUCED | KIND::EXPLICIT) ||
						!(HasDeduced(key.first, key.second) || _args.Contains(ToTuple(key.first, key.second | KIND::EXPLICIT)))
				)
				{
					receiver(key.first, key.second, a.GetValue()) yield_return;
				}
			}
		}
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying DataDictionary used by this TemplateArguments object.
	/// The dictionary stores default values as well as overridden values. The keys
	/// are usually of type Tuple<NodePath, KIND>, but there may be additional arguments
	/// which aren't related to node ports.
	/// @return												The underlying DataDictionary containing the arguments.
	//----------------------------------------------------------------------------------------
	const DataDictionary& GetArgs() const
	{
		return _args;
	}

	/// @copydoc GetArgs
	DataDictionary& GetArgs()
	{
		return _args;
	}

	template <typename... ARGS> static Result<TemplateArguments> Create(ARGS&&... args)
	{
		iferr_scope;
		TemplateArguments result;
		result.CreateImpl(std::forward<ARGS>(args)...) iferr_return;
		return result;
	}

	Bool IsEmpty() const
	{
		return _args.IsEmpty();
	}

	Bool IsPopulated() const
	{
		return _args.IsPopulated();
	}

private:
	const Data* GetImpl(const NodePath& path, KIND kind) const;

	static Result<void> CreateImpl()
	{
		return OK;
	}

	template <typename PATH, typename T, typename... REST> Result<void> CreateImpl(const PATH& path, T&& value, REST&&... rest)
	{
		iferr_scope;
		SetImpl(path, std::forward<T>(value)) iferr_return;
		return CreateImpl(std::forward<REST>(rest)...);
	}

	static KIND GetKindFor(const void*, OverloadRank0)
	{
		return KIND::VALUE;
	}

	static KIND GetKindFor(const DataType*, OverloadRank1)
	{
		return KIND::TYPE;
	}

	static KIND GetKindFor(const Array<InternedId>*, OverloadRank1)
	{
		return KIND::BUNDLE;
	}

	template <typename T> Result<void> SetImpl(const NodePath& path, T&& value)
	{
		return SetExplicit(path, GetKindFor(&value, OVERLOAD_MAX_RANK), std::forward<T>(value));
	}

	template <typename T> Result<void> SetImpl(const Char* path, T&& value)
	{
		iferr_scope;
		NodePath p = NodePath::FromCString(CharToBlock(path)) iferr_return;
		return SetExplicit(p, GetKindFor(&value, OVERLOAD_MAX_RANK), std::forward<T>(value));
	}

	DataDictionary _args;

public:
	MAXON_OPERATOR_STRUCT(TemplateArguments, _args);
};

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(TemplateArguments**, OverloadRank0)
{
	return GetDataType<DataDictionary>();
}


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
/// This attribute can be set for ports which shall be forced to be shortcut stops.
/// There are several additional criteria which turn a port into a shortcut stop, see IsShortcutStop.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, ShortcutStop, "shortcutstop");

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
/// This read-only attribute is true for ports which are shortcut stops. Shortcut stops are ports which
/// - are ports of the root node
/// - or are input ports and have the DEFAULTVALUE attribute set
/// - or have the ShortcutStop, Dynamic, TappingPort or ExternalContext attribute set to true
/// - or are source or target of a Wires::CONTEXT wire
/// - or have a ContextReference or FunctionParameters attribute
/// - or have a direct child which has the ExternalContext attribute set to true
/// - or have an enclosing port with one of the above properties.
///
/// Short cut stops are used to derive shortcut wires: These represent paths along normal
/// wires with shortcut stops only at their ends. This is useful to skip irrelevant intermediate ports
/// when walking along wires.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IsShortcutStop, "isshortcutstop");

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
/// Type of the PortFlags attribute.
//----------------------------------------------------------------------------------------
enum class PORT_FLAGS
{
	NONE = 0,																				///< No flag set.
	HIDDEN = 1,																			///< The port shall be hidden.
	USED_FOR_TEMPLATE_ARGUMENT = 2,									///< The port is used for an argument for a TemplateParameter of a node template.
	USED_FOR_INPUTPORTTYPE_TEMPLATE_ARGUMENT = 4,		///< The port is used for an argument for a TypeTemplateParameter of an input port of a node template.
	CONSTANT = 8,																		///< It is required that the port has a constant value.
	VARIADIC = 16,																	///< The port is a variadic port (don't confuse with a variadic port instance).
	INHERITS_NESTED_PORTS = 32,											///< The port inherits nested ports from upstream ports, see InheritNestedPorts.
	SYNTHESIZES_NESTED_PORTS = 64,									///< The port synthesizes nested ports from downstream ports, see SynthesizeNestedPorts.
	HAS_CHILDREN = 128,															///< The port has children (so it's a port bundle or a variadic port).
	USED_FOR_INPUTBUNDLE_TEMPLATE_ARGUMENT = 256,		///< The port is used for an argument for an BundleTemplateParameter of an input port of a node template.
	CHAIN = 512																			///< The port belongs to a chain.
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
			&& counterPort.IsEqual(port.ToBlock().Slice(0, otherNesting), other.counterPort, true);
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


class NodeSystemClass;
class Port;
class GNode;

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
		SHORTCUT = 8,														///< This flag has to be set for inherited or synthesized attributes which are defined based on shortcut wires instead of normal wires.
		INDUCED_DEPENDENCIES = 16,							///< This flag has to be set for inherited or synthesized attributes when the derivation needs induced dependencies as well (see GraphModelInterface::GET_CONNECTIONS_MODE::INDUCED_DEPENDENCIES).
		POST_ORDER = 32,												///< This flag has to be set for inherited or synthesized attributes when the derivation for a port shall be done after the derivation for its nested ports.
		DERIVED_MASK = INHERITED | SYNTHESIZED	///< Use this to test for derived attributes (INHERITED or SYNTHESIZED).
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	//----------------------------------------------------------------------------------------
	/// Returns the kind of this attribute, i.e., whether it is an inherited, synthesized or computed attribute.
	/// @return												Kind of this attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD KIND GetKind() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the derivation of this attribute is needed for the given node system class.
	/// @see NodeSystemClassInterface::NeedsAttribute
	/// @return												True to enable derivation of this attribute within validation of node systems.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsNeededFor(const NodeSystemClass& cls) const;

	//----------------------------------------------------------------------------------------
	/// Returns the dependencies of this derived attribute. This has to include all other
	/// attributes which are needed for the derivation of this attribute.
	/// @return												Block of all dependencies which this attribute has.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const InternedId> GetDependencies() const;

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

using NodePathArraySetRef = StrongCOWRef<ArraySet<NodePath>>;


//----------------------------------------------------------------------------------------
/// This attribute can be set to true for port bundles if the resources of member ports
/// shall be obtained from attribute resources.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, UseAttributeResources, "useattributeresources");

MAXON_ATTRIBUTE(Bool, IgnoreBase, "ignorebase");


#include "portattributes1.hxx"
#include "portattributes2.hxx"

}

} // namespace maxon

#endif // PORTATTRIBUTES_H__
