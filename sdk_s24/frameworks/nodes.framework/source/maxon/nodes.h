#ifndef NODES_H__
#define NODES_H__

#include "maxon/arraymap.h"
#include "maxon/assets.h"
#include "maxon/datadescription_data.h"
#include "maxon/decorator.h"
#include "maxon/descriptionprocessor.h"
#include "maxon/errortypes.h"
#include "maxon/graph.h"
#include "maxon/nodepath.h"
#include "maxon/portattributes.h"
#include "maxon/taggedbaseref.h"
#include "maxon/treemap.h"
#include "maxon/url.h"

namespace maxon
{

namespace AssetTypes
{
	//----------------------------------------------------------------------------------------
	/// This is the asset type for NodeTemplate.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(AssetType, NodeTemplate, "net.maxon.node.assettype.nodetemplate");
};

//----------------------------------------------------------------------------------------
/// This namespace contains the API of the nodes framework.
//----------------------------------------------------------------------------------------
namespace nodes
{

class GNodeBase;
class GNode;
class GNodeData;
class GNodeIteratorBase;
class Node;
class MutableGNode;
class MutableNode;
class MutableRoot;
class PortList;
class MutablePortList;
class Port;
class MutablePort;
class NodeSystemImpl;
class NodeSystem;
class NodeSystemData;
class NodeSystemDerivationHandler;
class NodeTemplateInterface;
class NodeTemplate;
class InstantiationTrace;



//----------------------------------------------------------------------------------------
/// The type alias GNodeSelector selects between MutableGNode (mutable case) and GNode (read-only case).
/// @tparam MUTABLE								true for MutableGNode, false for GNode
//----------------------------------------------------------------------------------------
template <Bool MUTABLE> using GNodeSelector = typename std::conditional<MUTABLE, MutableGNode, GNode>::type;


//----------------------------------------------------------------------------------------
/// The type alias @CLASS contains the connected port in its first member and the Wires
/// of the connection in its second member. So it's rather a half-connection since the
/// starting port isn't contained. Connections are reported by PortFunctions::GetConnections.
//----------------------------------------------------------------------------------------
using Connection = Tuple<Port, Wires>;


//----------------------------------------------------------------------------------------
/// @copydoc Connection
//----------------------------------------------------------------------------------------
using MutableConnection = Tuple<MutablePort, Wires>;

//----------------------------------------------------------------------------------------
/// The type alias ConnectionSelector selects between MutableConnection (mutable case) and Connection (read-only case).
/// @tparam MUTABLE								true for MutableConnection, false for Connection
//----------------------------------------------------------------------------------------
template <Bool MUTABLE> using ConnectionSelector = typename std::conditional<MUTABLE, MutableConnection, Connection>::type;



//----------------------------------------------------------------------------------------
/// This class is used internally to store the data for a node.
/// Basically it is a pointer to GNodeData, but it also stores the node system through which the pointer is reached.
/// This is needed at some places, and the node system pointer can't be stored at the GNodeData itself because
/// the latter can be shared among several node systems.
/// @private
//----------------------------------------------------------------------------------------
struct GNodeDataPtr
{
	// Pointer to the node data. This may be shared among several node systems (it stems from a copy-on-write hashmap reference).
	const GNodeData* ptr = nullptr;

	// The node system for which the node data is used.
	const NodeSystemImpl* system = nullptr;

	GNodeDataPtr() = default;

	GNodeDataPtr(const GNodeData* p, const NodeSystemImpl* s) : ptr(p), system(s)
	{
	}

	void Reset()
	{
		ptr = nullptr;
		system = nullptr;
	}

	explicit operator Bool() const
	{
		return ptr != nullptr;
	}

	const GNodeData* operator ->() const
	{
		return ptr;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(GNodeDataPtr, ptr);
};

//----------------------------------------------------------------------------------------
/// A GNodeHandle references a g-node within a node system by a path.
/// It also caches the current GNodeData pointer for the path to speed up data access.
/// @private
//----------------------------------------------------------------------------------------
class GNodeHandle
{
public:
	GNodeHandle() = default;

	MAXON_OPERATOR_EQUALITY_HASHCODE(GNodeHandle, _path);

	explicit operator Bool() const
	{
		return _data.ptr != nullptr;
	}

	NODE_KIND GetKind() const
	{
		return (_path.GetPointer() != nullptr) ? _path.GetPointer()->PrivateGetKind(_data.ptr != nullptr)
			: (_data.ptr != nullptr) ? NODE_KIND::NODE
			: NODE_KIND::NONE;
	}

	const NodePath& GetPath() const
	{
		return _path;
	}

	void Reset()
	{
		_path = nullptr;
		_data.Reset();
	}

	String ToString(const FormatStatement* fs = nullptr) const
	{
		return _path.IsPopulated() ? _path.ToString(fs) : _data.ptr ? "Root"_s : "nullptr"_s;
	}

	static const GNodeHandle& NullValue()
	{
		return GetZeroRef<GNodeHandle>();
	}

protected:
	GNodeHandle(const NodePath& path, const GNodeDataPtr& data, UInt stamp) : _path(path), _data(data), _stamp(stamp)
	{
	}

	// Path of the g-node.
	NodePath _path;

	// The GNodeData of the g-node. This is a cached value and gets updated when needed (the dirtyness is checked with _stamp).
	mutable GNodeDataPtr _data;

	// _dataStamp of the node system for inherited data, or _dataValidationStamp for own data of node system.
	mutable UInt _stamp = 0;

	friend class NodeSystemImpl;
	friend class CompiledNodeImpl;
};



//----------------------------------------------------------------------------------------
/// This enum class contains a set of flags which can be queried for g-nodes. The flags can't be set directly,
/// they are either set at creation of a port (see MutablePortListFunctions::AddPort)
/// or derived automatically during node system validation.
//----------------------------------------------------------------------------------------
enum class GNODE_FLAGS : UInt64
{
	//----------------------------------------------------------------------------------------
	/// No flag set.
	//----------------------------------------------------------------------------------------
	NONE = 0,

	// the lower 7 bits are reserved for internal use

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which has been created directly by user code, as opposed
	/// to derived ports (DERIVED_PORT_INHERITED, DERIVED_PORT_SYNTHESIZED) which are created
	/// based on port bundles of connected ports.
	//----------------------------------------------------------------------------------------
	DIRECT_PORT = 1 << 7,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which has been created (or would have been created)
	/// during the derivation of inherited ports, namely when a port derives an inner port
	/// from an incoming connection from a port bundle.
	/// @see DIRECT_PORT
	/// @see DERIVED_PORT_SYNTHESIZED
	//----------------------------------------------------------------------------------------
	DERIVED_PORT_INHERITED = 1 << 8,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which has been created (or would have been created)
	/// during the derivation of synthesized ports, namely when a port derives an inner port
	/// from an outgoing connection to a port bundle.
	/// @see DIRECT_PORT
	/// @see DERIVED_PORT_INHERITED
	//----------------------------------------------------------------------------------------
	DERIVED_PORT_SYNTHESIZED = 1 << 9,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which is a source port of a CONTEXT wire (or which has an enclosing port with that property).
	//----------------------------------------------------------------------------------------
	CONTEXT_SOURCE = 1 << 10,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which is a target port of a CONTEXT wire (or which has an enclosing port with that property).
	//----------------------------------------------------------------------------------------
	CONTEXT_TARGET = 1 << 11,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port which has the FunctionParameters attribute set (or which has an enclosing port with that property).
	/// Such a port provides a context containing the function parameters, and it instantiates its predecessor subgraph
	/// for a compilation into a function.
	//----------------------------------------------------------------------------------------
	FUNCTION_INSTANTIATION = 1 << 12,

	//----------------------------------------------------------------------------------------
	/// This flag is set for the context port of a built-in NODE::CONTEXT::GET node.
	//----------------------------------------------------------------------------------------
	CONTEXT_PARAMETER_PORT = 1 << 13,

	//----------------------------------------------------------------------------------------
	/// This flag is set for a port for which the TappingPort attribute is true (or which has an enclosing port with that property).
	//----------------------------------------------------------------------------------------
	TAPPING_PORT = 1 << 14,

	//----------------------------------------------------------------------------------------
	/// This flag can be set for a port to enable shortcut filtering: A shortcut from a port
	/// marked in such a way to a port which has the FILTER_SHORTCUT_TARGET flag set has to pass
	/// the filter function NodeSystemDerivationHandlerInterface::FilterShortcut, otherwise it isn't reported by
	/// PortFunctions::GetConnections.
	//----------------------------------------------------------------------------------------
	FILTER_SHORTCUT_SOURCE = 1 << 15,

	//----------------------------------------------------------------------------------------
	/// See FILTER_SHORTCUT_SOURCE.
	//----------------------------------------------------------------------------------------
	FILTER_SHORTCUT_TARGET = 1 << 16,

	//----------------------------------------------------------------------------------------
	/// Combination of all flags of this enum.
	//----------------------------------------------------------------------------------------
	ALL_MASK = DIRECT_PORT | DERIVED_PORT_INHERITED | DERIVED_PORT_SYNTHESIZED | CONTEXT_SOURCE | CONTEXT_TARGET | FUNCTION_INSTANTIATION | CONTEXT_PARAMETER_PORT | TAPPING_PORT | FILTER_SHORTCUT_SOURCE | FILTER_SHORTCUT_TARGET
} MAXON_ENUM_FLAGS(GNODE_FLAGS);



//----------------------------------------------------------------------------------------
/// A node system class defines a set of methods to customize the behavior of node systems
/// and node templates. Whenever a NodeTemplate is instantiated to a NodeSystem, this process
/// goes through a NodeSystemClass. Also only NodeSystems which use the same class can be used together.
//----------------------------------------------------------------------------------------
class NodeSystemClassInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemClassInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.nodesystemclass");
public:
	//----------------------------------------------------------------------------------------
	/// Returns a unique identifier for this node system class (namely the identifier
	/// of the object class, @c{GetClass().GetId()}).
	/// @return												Unique identifier for node system class.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const Id& GetId() const { return GetClass().GetId(); }

	//----------------------------------------------------------------------------------------
	/// Checks if this class is a subclass of #other. This is implemented by the corresponding
	/// function of the underlying object class.
	/// @param[in] other							Another node system class.
	/// @return												True if this class is a subclass of #other, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsSubclassOf(const NodeSystemClass& other) const;

	//----------------------------------------------------------------------------------------
	/// Creates a new compound node system. Compound node systems allow to set up
	/// a node system consisting of several other nodes.
	/// @return												The MutableRoot of a new empty compound node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MutableRoot> CreateNodeSystem() const;

	//----------------------------------------------------------------------------------------
	/// MutableRoot::EndModification() passes FINALIZE_FLAGS to FinalizeModification, this is used
	/// to control which finalizations shall be done during MutableRoot::EndModification().
	//----------------------------------------------------------------------------------------
	enum class FINALIZE_FLAGS
	{
		NONE = 0,				///< Don't do any finalizations at all.
		CLEANUP = 1,		///< Run clean-up finalizations.
		FOR_GROUP = 2		///< Deprecated.
	} MAXON_ENUM_FLAGS_CLASS(FINALIZE_FLAGS);

	//----------------------------------------------------------------------------------------
	/// Runs finalization steps at the end of a modification. This method must not be called directly,
	/// instead it is called implicitly during MutableRoot::EndModification(). When overriding
	/// the method make sure to call the super implementation.
	/// @param[in] stampOnBegin				The time stamp of the node system at the time BeginModification() was called.
	/// @param[in] finalize						Flags to control the finalization.
	/// @param[in] changelist					Change list to log changes made during finalization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinalizeModification(MutableRoot& root, TimeStamp stampOnBegin, FINALIZE_FLAGS finalize, ChangeList* changelist) const;

	//----------------------------------------------------------------------------------------
	/// Returns the GraphAttribute which node systems of this class use for the attribute identified by attr.
	/// The method may return a null reference if the class doesn't provide a GraphAttribute for attr.
	/// This doesn't mean that the attribute is unsupported, it just means that
	/// there is no need for special handling of the attribute (which would require a GraphAttribute).
	/// The default implementation asks the Attributes registry.
	/// @param[in] attr								The identifier of the attribute.
	/// @return												The corresponding GraphAttribute, or a null reference
	///																if the node system class has no GraphAttribute for attr.
	/// @see GetGraphAttributeFlags
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const GraphAttribute& GetGraphAttribute(const InternedId& attr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the GraphAttribute::FLAGS to use for the attribute identified by attr.
	/// This allows the node system class to override the default flags of the attribute,
	/// for example to mark an attribute as meta attribute.
	/// @param[in] attr								The identifier of the attribute.
	/// @return												The flags which this node system class uses for the attribute.
	/// @see GetGraphAttribute
	/// @MAXON_ANNOTATION{default=GraphAttributeInterface::FLAGS::DIRECT}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphAttribute::FLAGS GetGraphAttributeFlags(const InternedId& attr) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the node system class needs the derivation of #attr. Each attribute registered
	/// at Attributes for which this method returns true will be used to derive attribute values.
	/// The default implementation of DefaultNodeSystemClass forwards the call to DerivedAttribute::IsNeededFor.
	/// @param[in] attr								The identifier of the attribute.
	/// @return												True if #attr shall be derived for node systems of this class, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool NeedsAttribute(const DerivedAttribute& attr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the conversion flags of a conversion from #src to #dest as implemented by Convert.
	/// If there is no such conversion, CONVERSION_FLAGS::INCONVERTIBLE is returned.
	/// @param[in] dest								The destination type.
	/// @param[in] src								The source type.
	/// @return												The conversion flags for the conversion from #src to #dest.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CONVERSION_FLAGS> GetConversionFlags(const DataType& dest, const DataType& src) const;

	//----------------------------------------------------------------------------------------
	/// Converts value to type dest. This is used e.g. by the validation mechanism of the ConstantValue
	/// attribute whenever this needs to convert incoming data to a different expected type.
	/// The default implementation of DefaultNodeSystemClass uses DataType::Convert, but this may be
	/// overridden if the implementation provides additional means for conversion.
	/// @param[in] dest								The type to convert to.
	/// @param[in] value							The value to convert.
	/// @return												The converted value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> Convert(const DataType& dest, const ConstDataPtr& value) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this node system class supports the instantiation of the given node template.
	/// If true is returned, this does not necessarily mean that all possible instantiations of
	/// the template are supported, but at least some are supported.
	/// Usually this call is just forwarded to NodeTemplateInterface::SupportsImpl, but the
	/// node system class may override this default behaviour.
	///
	/// @param[in] templ							The node template to check.
	/// @return												True if the node template can be instantiated for this class, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SupportsImpl(const NodeTemplate& templ) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this node system class supports the given #variant for a node template #templ
	/// created by NodesLib::CreateVariantTemplate(). #variant is a path into the TreeMap which
	/// was given as argument to NodesLib::CreateVariantTemplate(). The default implementation
	/// of DefaultNodeSystemClass returns true.
	///
	/// @param[in] templ							The variant node template to check.
	/// @param[in] variant						The path into the TreeMap of variants.
	/// @return												True if this node system supports the given variant, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SupportsVariant(const NodeTemplate& templ, const Block<const Id>& variant) const;

	//----------------------------------------------------------------------------------------
	/// Subtitutes an unsupported variant of a node template #templ created by
	/// NodesLib::CreateVariantTemplate() by a supported one. #variant is a path into the TreeMap which
	/// was given as argument to NodesLib::CreateVariantTemplate(). The path points to the variant
	/// of the template which was chosen by the template arguments, but which is not supported
	/// as reported by SupportsVariant(). If a supported alternative shall be used as a substitution,
	/// the method returns its identifier. If no substution is possible, the method returns an empty identifier.
	///
	/// @param[in] templ							The variant node template to check.
	/// @param[in] variant						The (unsupported) path into the TreeMap of variants.
	/// @param[in] options						The supported alternatives for the last path element of #variant.
	///																This is not a path, but a list of the supported siblings of the
	///																unsupported variant in the TreeMap of the variant node template.
	/// @return												An alternative to use for the unsupported #variant, or an empty identifier
	///																if there is no viable alternative.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Id> SubstituteVariant(const NodeTemplate& templ, const Block<const Id>& variant, const Block<const Id>& options) const;

	//----------------------------------------------------------------------------------------
	/// Instantiates the template #templ using the given arguments for this node system class.
	/// Usually this call is just forwarded to NodeTemplateInterface::InstantiateImpl, but the
	/// node system class may override this behaviour to return a specialization of the node template.
	///
	/// If this node system class supports the instantiation of #templ in general but not for the
	/// given arguments, a NodeSystem will be returned nevertheless but with error attributes indicating the
	/// instantiation error. If #templ isn't supported at all, error attributes can be set too,
	/// or an error can be returned.
	///
	/// @param[in] parent							The parent instantiation context.
	///																You can reach all enclosing instantiation contexts through #parent, this helps to prevent infinite recursions.
	/// @param[in] templ							The node template to instantiate.
	/// @param[in] args								Arguments to parametrize the instantiation.
	/// @return												A new node sytem which is the instantiation of this template for the given arguments.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> InstantiateImpl(const InstantiationTrace& parent, const NodeTemplate& templ, const TemplateArguments& args) const;

	//----------------------------------------------------------------------------------------
	/// Returns the set of special graph modification stamps which shall be set for the change from oldValue to newValue.
	/// @param[in] port								The port where the attribute value has changed.
	/// @param[in] attr								The attribute whose value has changed.
	/// @param[in] attrFlags					The flags of the attribute.
	/// @param[in] newValue						The newly derived attribute value for port.
	/// @param[in] oldValue						The previously derived attribute value for port.
	/// @return												Combination of special flags, these determine the graph modification stamps which shall be updated.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphModelInterface::MODIFIED> GetSpecialFlags(const Port& port, const InternedId& attr, GraphAttribute::FLAGS attrFlags, const ConstDataPtr& newValue, const ConstDataPtr& oldValue) const;
};


//----------------------------------------------------------------------------------------
/// This enum defines what kind of value a port has.
//----------------------------------------------------------------------------------------
enum class VALUEMODE : Char
{
	NONE,				///< The port doesn't have a value at all.
	DYNAMIC,		///< The port's value is dynamic, so it can't be computed during validation because it depends on values not known at that time.
	CONSTANT		///< The port's value is a known constant, so the ConstantValue attribute yields a valid value.
} MAXON_ENUM_LIST(VALUEMODE);


//----------------------------------------------------------------------------------------
/// A node system derivation handler defines a set of methods to customize the attribute derivation
/// behavior of node systems. Usually you don't have to bother about this because the default
/// handler is sufficient. However some node templates have to specialize the default behavior
/// for the node systems which they instantiate, for example to define a custom
/// constant value computation.
///
/// To change the handler of a node system a node template has to call MutableRoot::SetDerivationHandler().
//----------------------------------------------------------------------------------------
class NodeSystemDerivationHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemDerivationHandlerInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.nodesystemderivationhandler");
public:
	//----------------------------------------------------------------------------------------
	/// Computes the value of the derived attribute attr at the port specified by nesting.
	/// This method is called during validation of derived attributes. The default implementation
	/// just calls attr.DeriveAttributeValue(), but implementations may override this default
	/// behavior.
	/// @param[in] nesting						The last element of nesting if the port for which the attribute value
	///																shall be computed, the previous elements are its enclosing ports
	///																up to the top-level port.
	/// @param[in] attr								The derived attribute whose value shall be computed.
	/// @return												The derived attribute value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<Data>> DeriveAttributeValue(const Block<const Port>& nesting, const DerivedAttribute& attr) const;

	//----------------------------------------------------------------------------------------
	/// Computes the value of the ConstantValue attribute at the given port.
	/// This method is called during validation of derived attributes. The default implementation
	/// returns VALUEMODE::DYNAMIC to indicate that no constant value can be computed.
	/// Implementations may override this default behavior.
	/// @param[in] port								The port for which the constant value shall be computed.
	/// @return												The value of the ConstantValue attribute of the port.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<VALUEMODE, Data>> ComputeConstantValue(const Port& port) const;

	//----------------------------------------------------------------------------------------
	/// Checks if shortcut connections from src do dst shall be reported by
	/// PortFunctions::GetConnections. This method is called by PortFunctions::GetConnections
	/// whenever the source port of a shortcut connection has GNODE_FLAGS::FILTER_SHORTCUT_SOURCE set,
	/// the target port has GNODE_FLAGS::FILTER_SHORTCUT_TARGET set and both ports belong to
	/// instantiations of the same template. Only if this method returns true the shortcut
	/// will be reported by PortFunctions::GetConnections. This allows to hide shortcuts
	/// which aren't needed, for example because they transport constant values.
	/// @param[in] src								The source port of a shortcut connection.
	/// @param[in] dst								The target port of a shortcut connection.
	/// @return												True if the shortcut connection shall be reported by PortFunctions::GetConnections, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FilterShortcut(const Port& src, const Port& dst) const;
};


//----------------------------------------------------------------------------------------
/// A NodeSystem owns and manages a complete hierarchy of nodes and ports. NodeSystem is a
/// copy-on-write reference, therefore each non-const method may create a copy of the
/// original node system at first. However the copy is done by sharing the internal data, so it is a
/// lightweight operation.
///
/// Traversal of a node system starts with GetRoot().
/// For @ref usernodes_modifications "modifications", you have to call
/// BeginModification() to obtain write access to the hierarchy through a MutableRoot. As long as you make
/// modifications, you have to ensure that no other thread uses the reference to the node system,
/// or synchronize the threads in an appropriate way. As last step of a sequence of modifications
/// you have to call MutableRoot::EndModification().
///
/// The implementation class of this interface is a final class, so you can't override it.
/// However some behavior is delegated to NodeSystemClass and NodeSystemDerivationHandler
/// to allow for customization of certain aspects.
///
/// @see @$ref usernodes_nodesystem
/// @see NodesLib
//----------------------------------------------------------------------------------------
class NodeSystemInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.nodesystem");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
public:
	using GET_CONNECTIONS_MODE = GraphModelInterface::GET_CONNECTIONS_MODE;

	static constexpr WIRE_MODE VALUE_CHAIN = WIRE_MODE(UnderlyingType<WIRE_MODE>(WIRE_MODE::NORMAL) + 1);
	static constexpr WIRE_MODE VALUE_SECONDARY = WIRE_MODE(UnderlyingType<WIRE_MODE>(WIRE_MODE::NORMAL) - 2);
	static constexpr WIRE_MODE VALUE_DEFAULT = WIRE_MODE(UnderlyingType<WIRE_MODE>(WIRE_MODE::MIN) + 1);
	static constexpr WIRE_MODE VALUE_COUNTERCHAIN = WIRE_MODE(UnderlyingType<WIRE_MODE>(WIRE_MODE::MIN) + 2);

	static constexpr WIRE_MODE DEPENDENCY_TYPE = WIRE_MODE::FLAG0;
	static constexpr WIRE_MODE DEPENDENCY_SYNTHESIZE_VALUE = WIRE_MODE::FLAG1;

	//----------------------------------------------------------------------------------------
	/// Returns the node system class which created this node system. Only node systems of the
	/// same node system class can be used together.
	/// @return												The node system class of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeSystemClass& GetNodeSystemClass() const;

	//----------------------------------------------------------------------------------------
	/// Returns the derivation handler of this node system. Node templates can override the default
	/// derivation handler when they instantiate a node system using MutableRoot::SetDerivarionHandler().
	/// @return												The derivation handler of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeSystemDerivationHandler& GetDerivationHandler() const;

	//----------------------------------------------------------------------------------------
	/// Returns the base node system of which this node system is an instance. If this node system
	/// is not an instance of a base, the method returns a null reference.
	/// @return												The base of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeSystem& GetBase() const;

	//----------------------------------------------------------------------------------------
	/// Returns the base node systems of which this node system is an instance.
	/// The entry at index 0 refers to the node system of which this node system has been
	/// created as instance by CreateInstance(), this will be a null reference if the node
	/// systems hasn't been created this way. It's the same as the node system returned by
	/// GetBase(). The remaining entries list the bases which have been added by AddBase().
	/// @return												The bases of this node system, this will have at least one entry.
	///																The first entry may be a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Block<const NodeSystem>& GetBases() const;

	//----------------------------------------------------------------------------------------
	/// Returns the node template which instantiated this node system. If this node system is no instantiation
	/// of a node template, the method returns a null reference.
	/// @see GetArguments
	/// @see NodeTemplate::Instantiate
	/// @return												The node template which instantiated this node system, or a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodeTemplate& GetTemplate() const;

	//----------------------------------------------------------------------------------------
	/// Returns the template arguments which have been used for this instantiation of a node template
	/// (if this node system is an instantiation of a node template at all).
	/// @see GetTemplate
	/// @return												The arguments of this node template instantiation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const TemplateArguments& GetArguments() const;

	//----------------------------------------------------------------------------------------
	/// Returns the root node of this node system as an immutable Node. You can traverse the node system
	/// starting at the root, but you can't get write access to the node system via Node. For
	/// write-access use the function BeginModification() instead.
	/// @see @$ref usernodes_nodes
	/// @return												The root node of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Node GetRoot() const;

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Indicates the beginning of a sequence of modifications and returns the root node of
	/// this node system as a MutableRoot. This is the only way to obtain write access to the node system.
	///
	/// If #keepCurrent is true, the current state of the node system is kept in the NodeSystem reference
	/// on which BeginModification was called, and the returned MutableRoot references a new copy of the node system.
	/// If #keepCurrent is false, the reference is moved from the original NodeSystem reference to the returned
	/// MutableRoot, so the original reference is cleared. A copy is only made if there is more than one reference
	/// to the node system (keep in mind that NodeSystem is a copy-on-write reference).
	///
	/// In both cases the returned MutableRoot has the only reference to the mutable node system.
	/// When you are done with all modifications, you have to write the reference to the modified node system
	/// back to the original NodeSystem (or some other place), otherwise the modifications will get lost
	/// when the MutableRoot goes out of scope. You should do this by calling MutableRoot::EndModification(),
	/// this will clear the node system reference within MutableRoot. The typical usage is
	///	@code
	///	MutableRoot root = system.BeginModification(false) iferr_return;
	///	... // apply some changes to root
	///	system = root.EndModification() iferr_return;
	///	@endcode
	///
	/// @see @$ref usernodes_nodes
	/// @see @$ref usernodes_modifications
	/// @return												The root node of the mutable node system.
	//----------------------------------------------------------------------------------------
	Result<MutableRoot> BeginModification(Bool keepCurrent);

	Result<MutableRoot> BeginInstantiationModification(const NodeTemplate& templ);

	Result<MutableRoot> BeginSubstitutionModification(const AssetRepositoryRef& lookup, const NodeTemplate& original, const TemplateArguments& args);

	Result<MutableRoot> BeginSubstitutionModification(const NodeSystem& original);
	);

	//----------------------------------------------------------------------------------------
	/// Checks if this node system is in finalized state. A node system is in finalized state
	/// after MutableRoot::EndModification() has been called as long as no further modification
	/// is being made.
	/// @return												True if this node system is finalized (and therefore ready to use), false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsFinalized() const;

	//----------------------------------------------------------------------------------------
	/// Creates an @ref usernodes_instancing "instance" of this node system. Initially
	/// the returned instance will behave exactly like this node system, but you can apply changes to the instance.
	/// No data needs to be copied to the instance, so creating an instance is a lightweight process.
	/// @return												An instance which uses this node system as its base.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MutableRoot> CreateInstance() const;

	//----------------------------------------------------------------------------------------
	/// Returns a new node system which is a copy of the subgraph induced by all nodes
	/// given by basePath and selection. All nodes with a node path consisting of the basePath
	/// plus one of the identifiers of selection are copied, including their attributes and connections.
	/// Connections which don't end in one of the selected nodes are ignored.
	/// @param[in] basePath						The base path, this has to point to a true node. selection selects direct children of the node given by basePath.
	/// @param[in] selection					A selection of nodes, namely children of the node given by basePath. Identifiers for which no child exists are ignored.
	/// @return												A copy of the subgraph given by the selection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> CreateCopyOfSelection(const NodePath& basePath, const Block<const InternedId>& selection) const;

	//----------------------------------------------------------------------------------------
	/// Returns the time stamp of this node system, it can be used to test for modifications.
	/// Each call to BeginModification() increments the stamp. The time stamp is also
	/// needed for GetModificationsSince and GNodeFunctions::GetAttributeModificationsSince
	/// to get all modifications which have happened since then.
	/// @return												Modification time stamp of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeStamp GetModificationStamp() const;

	//----------------------------------------------------------------------------------------
	/// Reports all modifications which have been made since the given stamp to the receiver. A typical usage is
	/// @code
	/// TimeStamp stamp = system.GetModificationStamp(); // get the reference time stamp
	/// ... // do some modifications
	/// system.GetModificationsSince(stamp,
	///   [] (const GNode& node, GraphModelRef::MODIFIED mod) -> Result<Bool>
	///		{
	///			...
	///		}) iferr_return;
	/// @endcode
	/// The node system on which GetModificationStamp() is called needn't be the same as the one
	/// on which GetModificationsSince() is called, it suffices that the latter has been created
	/// by a number of CopyFrom operations from the first (which includes the implicit copy operation due to
	/// copy-on-write).
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @param[in] receiver						Modifications are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetModificationsSince(TimeStamp stamp, const ValueReceiver<const GNode&, GraphModelRef::MODIFIED>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Returns flags which tell which kinds of changes have happened since the given time stamp.
	/// From the returned value you can't tell exactly which nodes or ports are affected, but you can
	/// tell for example if only attributes have changed or also the structure.
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @return												Combination of flags to indicate the kinds of changes that have happened.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GraphModelRef::MODIFIED GetModificationsSince(TimeStamp stamp) const;

	//----------------------------------------------------------------------------------------
	/// Returns an Int value which corresponds to the index of the given port in the topological ordering
	/// of the node system. The connections within a node system build a directed acyclic graph,
	/// and the node system sets up a corresponding topological ordering of all ports within MutableRoot::ValidateTopology().
	/// For this step only top-level ports are considered, connections between nested ports are treated as if
	/// they were between their enclosing top-level ports. Therefore the index of a nested
	/// port is the same as the index of its enclosing port.
	/// @param[in] port								A path to a port of this node system. This may be a port
	///																of the root node, but also of any other arbitrarily nested node.
	/// @return												The index of the (enclosing top-level-) port in the topological ordering,
	///																or a negative number if port doesn't point to a port.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetTopologicalOrder(const NodePath& port) const;

	//----------------------------------------------------------------------------------------
	/// Yields all top-level ports of this node system to receiver in topological order.
	/// This comprises really all top-level ports, so not only
	/// ports of the root node, but also of its children and any other arbitrarily nested node.
	/// @see GetTopologicalOrder
	/// @param[in] reverseOrder				True if the ports shall be reported in reverse topological order, false otherwise.
	/// @param[in] receiver						A callback which receives the top-level ports.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetTopLevelPorts(Bool reverseOrder, const ValueReceiver<const Port&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for #node. This will override any value
	/// which would otherwise be inherited for the attribute from a base.
	/// @param[in] node								The handle for the g-node.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The new value for the attribute.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @param[in] checkAndInvalidate	Usually true. Use false if no check, invalidation and update of time stamp shall be done,
	///																this may only be used for attributes which aren't needed during validation.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SetValue(const GNodeHandle& node, const InternedId& attr, ForwardingDataPtr&& value, ChangeList* list, Bool checkAndInvalidate = true);

	//----------------------------------------------------------------------------------------
	/// Extracts the NodeSystemData for serialization. A NodeSystem itself can't be serialized.
	/// @return												NodeSystemData of this node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystemData> GetNodeSystemData() const;

	MAXON_METHOD AssetRepositoryRef GetLookupRepository() const;

	//----------------------------------------------------------------------------------------
	/// This enum contains options for the GML output written by WriteGml.
	//----------------------------------------------------------------------------------------
	enum class GML_OPTIONS
	{
		NONE = 0,											///< No flags.
		DIRECT_ATTRIBUTES = 1,				///< Writes direct attributes (those which are set directly at the node system).
		BASE_ATTRIBUTES = 2,					///< Writes base attributes (those which are inherited from a base node system).
		DERIVED_ATTRIBUTES = 4,				///< Writes derived attributes.
		BASES = 8,										///< Also writes the node systems which are used as bases for the node system.
		ALL_BASES = 16,								///< Like BASES, but also writes bases of bases etc.
		SHORTCUTS = 32,								///< Also writes shortcut connections.
		NO_CONNECTIONS = 64,					///< No connections will be written.
		ATTRIBUTES = DIRECT_ATTRIBUTES | BASE_ATTRIBUTES | DERIVED_ATTRIBUTES		///< Combination of all attribute flags, used to write all attributes.
	} MAXON_ENUM_FLAGS_CLASS(GML_OPTIONS);

	//----------------------------------------------------------------------------------------
	/// Writes this node system to a GML file (Graph Modeling Language).
	/// @param[in] output							The output stream to write to.
	/// @param[in] opts								Options for the output.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteGml(UrlOrOutputStream&& output, GML_OPTIONS opts) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Int PrivateGetChildEntryCount(const GNodeHandle& node) const;

	MAXON_METHOD GNodeHandle PrivateGetRoot() const;

private:
	// For documentation of the following methods see below in the corresponding functions of GNodeBase and its subclasses
	MAXON_METHOD Result<void> SetDerivationHandler(const NodeSystemDerivationHandler& handler);

	MAXON_METHOD Result<void> SetTemplate(const AssetRepositoryRef& lookup, const NodeTemplate& templ, const TemplateArguments& args);

	MAXON_METHOD Result<Bool> GetInnerNodes(const GNodeHandle& node, NODE_KIND mask, Bool includeNode, const ValueReceiver<const MutableGNode&>& receiver);

	MAXON_METHOD Result<GNodeHandle> GetParent(const GNodeHandle& node) const;

	MAXON_METHOD Result<GNodeHandle> GetAncestor(const GNodeHandle& node, NODE_KIND kind) const;

	MAXON_METHOD Result<GNodeHandle> GetPortList(const GNodeHandle& node, PORT_DIR dir) const;

	MAXON_METHOD Result<GNodeHandle> FindChild(const GNodeHandle& node, const InternedId& name, NODE_KIND kind) const;

	MAXON_METHOD Result<GNodeHandle> FindInnerNode(const GNodeHandle& node, const PathBlock& innerPath) const;

	MAXON_METHOD const NodeSystem& GetBase(const GNodeHandle& node) const;

	MAXON_METHOD Result<void> AddBase(const NodeSystem& other);

	MAXON_METHOD const NodeTemplate& GetTemplate(const GNodeHandle& node) const;

	MAXON_METHOD const NodeSystemDerivationHandler& GetDerivationHandler(const GNodeHandle& node) const;

	MAXON_METHOD Result<GNodeHandle> FindHandle(const PathBlock& path) const;

	MAXON_METHOD GNodeHandle FindHandle(const NodePath& path) const;

	MAXON_METHOD Bool PrivateValidate(const GNodeHandle& handle) const;

	MAXON_METHOD GNODE_FLAGS GetFlags(const GNodeHandle& port) const;

	MAXON_METHOD Result<void> InitIterator(const GNodeHandle& node, GNodeIteratorBase& iterator) const;

	MAXON_METHOD Result<void> MoveToNext(GNodeIteratorBase& iterator) const;

	MAXON_METHOD Result<void> Validate(ChangeList* change);

	MAXON_METHOD Result<void> ValidateTopology();

	MAXON_METHOD Result<void> ValidatePorts(ChangeList* change);

	MAXON_METHOD Result<void> BeginModificationImpl();

	MAXON_METHOD Result<void> EndModificationImpl(ChangeList* change, NodeSystemClassInterface::FINALIZE_FLAGS finalize);

	MAXON_METHOD Result<void> Compact();

	MAXON_METHOD Result<ChangeList> Apply(const ChangeList& toApply, Bool inverse, ChangeList* list);

	MAXON_METHOD Result<void> Update(const Block<const Tuple<AssetReference, AssetBase>>& updates, const AssetRepositoryRef& lookup, ChangeList* list);

	MAXON_METHOD Result<GNodeHandle> AddChild(const Id& child, const NodeSystem& base, ChangeList* list);

	MAXON_METHOD Result<ChangeList> ReplaceBase(const NodeSystem& base, ChangeList* list);

	MAXON_METHOD Result<ChangeList> ReplaceChildren(const Block<const Tuple<InternedId, NodeSystem>>& newChildren, ChangeList* list);

	MAXON_METHOD Result<GNodeHandle> MoveToGroup(MutableRoot& groupRoot, const Id& groupId, const Block<const InternedId>& selection, ChangeList* list);

	MAXON_METHOD Result<NodeSystem> MoveToNodeSystem(const GNodeHandle& node, ChangeList* list);

	MAXON_METHOD Result<HashMap<InternedId, InternedId>> Ungroup(const GNodeHandle& node, ChangeList* list);

	MAXON_METHOD Result<HomogenousTupleType<3, HashMap<InternedId, InternedId>>> Merge(const NodeSystem& other, ChangeList* list);

	MAXON_METHOD Result<GNodeHandle> AddChild(const GNodeHandle& node, const Id& port, GNODE_FLAGS flags, ChangeList* list);

	MAXON_METHOD Result<void> InheritChild(const GNodeHandle& parent, const InternedId& childId, ChangeList* list);

	MAXON_METHOD Result<void> Remove(const GNodeHandle& child, ChangeList* list);

	MAXON_METHOD Result<void> Connect(const GNodeHandle& source, const GNodeHandle& target, Wires modes, ChangeList* list);

	MAXON_METHOD Result<Bool> GetConnections(const GNodeHandle& source, PORT_DIR dir, const ValueReceiver<const MutableConnection&>& conns, Wires mask, GET_CONNECTIONS_MODE mode);

	MAXON_METHOD Result<Wires> GetWires(const GNodeHandle& source, const GNodeHandle& target) const;

	MAXON_METHOD Result<Bool> GetConnectionValues(const GNodeHandle& source, const GNodeHandle& target, const ValueReceiver<CONNECTION_POSITION, InternedId, const ConstDataPtr&>& receiver) const;

	MAXON_METHOD Result<ConstDataPtr> GetConnectionValue(const GNodeHandle& source, const GNodeHandle& target, CONNECTION_POSITION position, const InternedId& attr, const DataType& expectedType) const;

	MAXON_METHOD Result<Bool> SetConnectionValue(const GNodeHandle& source, const GNodeHandle& target, CONNECTION_POSITION position, const InternedId& attr, ForwardingDataPtr&& value, ChangeList* list);

	MAXON_METHOD Result<void> GetValues(const GNodeHandle& port, GraphAttribute::FLAGS mask, GraphAttributeMap& attribs, Bool includeInherited, Bool includeRemoved) const;

	MAXON_METHOD Result<ConstDataPtr> GetValue(const GNodeHandle& port, const InternedId& attr, const DataType& expectedType) const;

	MAXON_METHOD Result<ConstDataPtr> GetValue(const GNodeHandle& port, const InternedId& attr, const DataType& expectedType, Int* nesting, Bool negativeRootNesting) const;

	MAXON_METHOD Result<Bool> GetBaseValues(const GNodeHandle& port, const InternedId& attr, const DataType& expectedType, const ValueReceiver<const ConstDataPtr&, Int>& values) const;

	MAXON_METHOD Result<void> TouchValue(const GNodeHandle& port, const InternedId& attr, ChangeList* list);

	MAXON_METHOD Result<void> ChangeValue(const GNodeHandle& port, const InternedId& attr, const SubDataOperation& op, const SubDataPathBlock& path, ForwardingDataPtr&& subvalue,
																				ChangeList* change);

	MAXON_METHOD Result<Bool> InheritValue(const GNodeHandle& port, const InternedId& attr, ChangeList* list);

	MAXON_METHOD Result<Bool> RemoveValue(const GNodeHandle& port, const InternedId& attr, ChangeList* list);

	MAXON_METHOD Result<Bool> GetAttributeModificationsSince(const GNodeHandle& node, TimeStamp stamp, const ValueReceiver<InternedId, ConstDataPtr>& receiver) const;

	MAXON_METHOD TimeStamp GetAttributeStamp(const GNodeHandle& node, const InternedId& attr) const;

	MAXON_METHOD TimeStamp GetConnectionStamp(const GNodeHandle& node, PORT_DIR direction) const;

public:
	MAXON_METHOD Bool HasBase(const IdAndVersion& baseId) const;

private:
	friend class GNodeIteratorBase;
	template <typename NODE> friend class GNodeIterator;

	template <typename BASE> friend class GNodeFunctions;
	template <typename BASE> friend class MutableGNodeFunctions;
	template <typename BASE> friend class NodeFunctions;
	template <typename BASE> friend class PortListFunctions;
	template <typename BASE> friend class MutablePortListFunctions;
	template <typename BASE> friend class PortFunctions;
	template <typename BASE> friend class MutablePortFunctions;

	friend class GNode;
	friend class GNodeBase;
	friend class MutableGNode;
	friend class MutableNode;
	friend class MutableRoot;
	friend class MutablePortList;
	friend class Port;
	friend class MutablePort;

	friend class NodeSystemImpl;
	friend class NodesLibImpl;
	friend class CompiledNodeImpl;
	friend class NodesGraphModelImpl;
	friend class NodeSystemManagerImpl;
	friend class NodeSystemBasedTemplateImpl;
	friend class CoreNodeWrapperImpl;
};


//----------------------------------------------------------------------------------------
/// A node template allows to create node system instantiations based on a set of template parameters.
//----------------------------------------------------------------------------------------
class NodeTemplateInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(NodeTemplateInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.nodetemplate");
public:
	//----------------------------------------------------------------------------------------
	/// Checks if this node template can be instantiated for the node system class #cls.
	/// If true is returned, this does not necessarily mean that all possible instantiations of
	/// the template are supported, but at least some.
	///
	/// The default implementation of this method just forwards to NodeSystemClass::SupportsImpl.
	/// You must not override it.
	///
	/// @param[in] cls								The node sytem class to check.
	/// @return												True if this node template can be instantiated for #cls, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Supports(const NodeSystemClass& cls) const;

	//----------------------------------------------------------------------------------------
	/// Instantiates this template using the given template arguments in the context of #parent.
	///
	/// If this template or the node system class support the instantiation in general
	/// but not for the given arguments, a NodeSystem will be returned nevertheless but with error attributes
	/// indicating the instantiation error.
	/// If the instantiation isn't supported at all, error attributes can be set too,
	/// or an error can be returned.
	///
	/// The implementation of this method just forwards to NodeSystemClass::InstantiateImpl.
	/// You must not override it.
	///
	/// @param[in] parent							The parent instantiation context, this defines the node system class to use
	///																as well as the asset repository for asset resolution.
	/// @param[in] args								Arguments to parametrize the instantiation.
	/// @return												A new node sytem which is the instantiation of this template for the given arguments.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> Instantiate(const InstantiationTrace& parent, const TemplateArguments& args = GetZeroRef<TemplateArguments>()) const;

	/// @copydoc Instantiate
	MAXON_FUNCTION Result<NodeSystem> Instantiate(const InstantiationTrace& parent, Result<TemplateArguments>&& args) const;

	//----------------------------------------------------------------------------------------
	/// Instantiates this template using the given template arguments for the node system class #cls.
	/// Asset references are resolved in the scope of the asset repository #repo.
	///
	/// If this template or the node system class support the instantiation in general
	/// but not for the given arguments, a NodeSystem will be returned nevertheless but with error attributes
	/// indicating the instantiation error.
	/// If the instantiation isn't supported at all, error attributes can be set too,
	/// or an error can be returned.
	///
	/// The implementation of this function just forwards to NodeSystemClass::InstantiateImpl.
	///
	/// @param[in] cls								The node system class to use for the instantiation.
	/// @param[in] repo								The asset repository to use for asset resolution.
	/// @param[in] args								Arguments to parametrize the instantiation.
	/// @return												A new node sytem which is the instantiation of this template for the given arguments.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<NodeSystem> Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const TemplateArguments& args = GetZeroRef<TemplateArguments>()) const;

	//----------------------------------------------------------------------------------------
	/// Yields all possible template parameter configurations for this template. Templates can implement
	/// this method if they have a finite number of instantiations.
	/// @param[in] receiver						A callback which receives the configurations.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> PrivateGetConfigurations(const ValueReceiver<const TemplateArguments&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this node template can be instantiated for the node system class #cls.
	/// If true is returned, this does not necessarily mean that all possible instantiations of
	/// the template are supported, but at least some.
	///
	/// This method shouldn't be invoked directly, use Supports instead. You have to implement
	/// this method to define a template-specific check, it will be called
	/// by NodeSystemClass::SupportsImpl.
	///
	/// @param[in] cls								The node sytem class to check.
	/// @return												True if this node template can be instantiated for cls, false otherwise.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SupportsImpl(const NodeSystemClass& cls) const;

	//----------------------------------------------------------------------------------------
	/// Instantiates this template using the given arguments.
	///
	/// This method shouldn't be invoked directly, use Instantiate instead. You have to implement
	/// this method to define the template instantiation, it will be called
	/// by NodeSystemClass::InstantiateImpl.
	///
	/// @param[in] parent							The parent instantiation context.
	///																You can reach all enclosing instantiation contexts through parent, this helps to prevent infinite recursions.
	/// @param[in] args								Arguments to parametrize the instantiation.
	/// @return												A new node sytem which is the instantiation of this template for the given arguments.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> InstantiateImpl(const InstantiationTrace& parent, const TemplateArguments& args) const;

	//----------------------------------------------------------------------------------------
	/// Tells if this node template is a group template. Group templates may have some ports
	/// but are otherwise empty. When a group template is added in the node editor it isn't added
	/// as asset but as editable group.
	///
	/// @return												True if this node template is a group, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsGroup() const;

	MAXON_ATTRIBUTE_CLASS(Array<IdAndVersion>, Bases, "net.maxon.node.bases");
};


//----------------------------------------------------------------------------------------
/// NodeSystemBasedNodeTemplate is a NodeTemplate which is defined by a NodeSystem.
/// NodesLib::CreateTemplateFromNodeSystem creates such a NodeTemplate. It uses the node system
/// as a template which is modified according to the template arguments, for example
/// it duplicates parts of the node system which belong to variadic port instances.
//----------------------------------------------------------------------------------------
class NodeSystemBasedNodeTemplateInterface : MAXON_INTERFACE_BASES(NodeTemplateInterface)
{
	MAXON_INTERFACE(NodeSystemBasedNodeTemplateInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.nodesystembasednodetemplate");
public:
	//----------------------------------------------------------------------------------------
	/// Checks if this template is a protected asset (so that the user can't see its inner setup).
	/// @return												True if the template is protected, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsProtected() const;

	//----------------------------------------------------------------------------------------
	/// Returns the node system which is used as a template.
	/// @param[in] cls								The node system class to use.
	/// @return												The underlying node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> GetNodeSystem(const NodeSystemClass& cls) const;
};


//----------------------------------------------------------------------------------------
/// NodeSystemData represents the serializable data of a NodeSystem. Node systems themselves
/// can't be serialized, however you can call NodeSystem::GetNodeSystemData() to extract
/// their persistent, serializable data and serialize that. After deserialization you have
/// to call Instantiate to obtain a node system from the pure data.
//----------------------------------------------------------------------------------------
class NodeSystemDataInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemDataInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.nodesystemdata");
public:
	//----------------------------------------------------------------------------------------
	/// Instantiates the node system described by this NodeSystemData for the given node system
	/// class. To resolve asset references #repo will be used.
	/// @param[in] cls								The node system class to use for the instantiation.
	/// @param[in] repo								The asset repository to use for asset resolution.
	/// @param[out] updateReferences	If nullptr, asset references won't be updated to the latest version. Otherwise
	///																they will (where the ASSET_UPDATE_POLICY allows), and the Bool will be set to
	///																true if at least one asset reference was updated.
	/// @return												The node system which is described by this NodeSystemData.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, Bool* updateReferences) const;
};


#include "nodes1.hxx"


//----------------------------------------------------------------------------------------
/// An InstantiationTrace is used as argument for NodeTemplate::Instantiate to track the
/// nesting of calls to that method and prevent infinite recursions. Whenever an
/// implementation of NodeTemplateInterface::InstantiateImpl calls that method itself, it has to check
/// before that the current instantiation hasn't already been made in an enclosing call
/// (because then we'd run into an infinite recursion), and it has to add the current
/// instantiation to the trace:
/// @code
///	MAXON_METHOD Result<NodeSystem> InstantiateImpl(const InstantiationTrace& parent, const TemplateArguments& args) const
///	{
///		iferr_scope;
///
///		if (parent.Contains(self, args, nullptr))
///		{
///			// This would lead to infinite recursion, handle error case.
///			...
///		}
///		else
///		{
///			// The current instantiation isn't part of the parent trace, we can instantiate another template.
///			// We have to add the current instantiation to the trace when calling Instantiate.
///			NodeSystem other = someTemplate.Instantiate(InstantiationTrace(parent, self, args, nullptr), someArguments) iferr_return;
///			...
///		}
///		...
///	}
//----------------------------------------------------------------------------------------
class InstantiationTrace
{
public:
	//----------------------------------------------------------------------------------------
	/// Extends an instantiation trace by a further element. This can be used within
	/// NodeTemplateInterface::InstantiateImpl when another instantiation is made, see InstantiationTrace.
	/// @param[in] parent							The parent InstantiationTrace.
	/// @param[in] nt									The current NodeTemplate (which wants to make an instantiation itself).
	/// @param[in] args								The arguments for the current NodeTemplate nt.
	/// @param[in] extra							Some extra value to mark this element of the trace, will be used for Contains.
	//----------------------------------------------------------------------------------------
	InstantiationTrace(const InstantiationTrace& parent, const NodeTemplate& nt, const TemplateArguments& args, const void* extra) : _class(parent._class), _repository(parent._repository), _parent(&parent), _template(nt), _arguments(args), _extra(extra)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the instantiation (t, args, extra) is already contained in this instantiation trace.
	/// This is to prevent infinite recursions when a NodeTemplate instantiates another NodeTemplate, see InstantiationTrace.
	/// @param[in] t									A node template.
	/// @param[in] args								Template arguments for t.
	/// @param[in] extra							This pointer has to match the extra value given for the InstantiationTrace constructor.
	/// @return												true if (t, args, extra) is already contained in this trace, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool Contains(const NodeTemplate& t, const TemplateArguments& args, const void* extra) const
	{
		return ContainsImpl(t, &args, extra);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the instantiation (t, extra) is already contained in this instantiation trace (template arguments are ignored for the comparison).
	/// This is to prevent infinite recursions when a NodeTemplate instantiates another NodeTemplate, see InstantiationTrace.
	/// @param[in] t									A node template.
	/// @param[in] extra							This pointer has to match the extra value given for the InstantiationTrace constructor.
	/// @return												true if (t, extra) is already contained in this trace (ignoring template arguments), false otherwise.
	//----------------------------------------------------------------------------------------
	Bool Contains(const NodeTemplate& t, const void* extra) const
	{
		return ContainsImpl(t, nullptr, extra);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the instantiation (t, args, extra) is already contained in this instantiation trace.
	/// This is to prevent infinite recursions when a NodeTemplate instantiates another NodeTemplate, see InstantiationTrace.
	/// @param[in] t									The identifier of a node template.
	/// @param[in] args								Template arguments for t.
	/// @param[in] extra							This pointer has to match the extra value given for the InstantiationTrace constructor.
	/// @return												true if (t, args, extra) is already contained in this trace, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool Contains(const Id& t, const TemplateArguments& args, const void* extra) const
	{
		return ContainsImpl(t, &args, extra);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the node system class to use for instantiations. This has been set by the constructor
	/// of the outmost trace element.
	/// @return												The node system class to use.
	//----------------------------------------------------------------------------------------
	const NodeSystemClass& GetNodeSystemClass() const
	{
		return _class;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository to use for asset lookup. This has been set by the constructor
	/// of the outmost trace element.
	/// @return												The asset repository to use.
	//----------------------------------------------------------------------------------------
	const AssetRepositoryRef& GetLookupRepository() const
	{
		return _repository;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the beginning of an instantiation trace.
	/// @param[in] cls								The node system class to use.
	/// @param[in] repo								The asset repository to use for lookup of assets.
	//----------------------------------------------------------------------------------------
	InstantiationTrace(const NodeSystemClass& cls, const AssetRepositoryRef& repo) : _class(cls), _repository(repo)
	{
	}

private:
	Bool ContainsImpl(const NodeTemplate& t, const TemplateArguments* args, const void* extra) const;
	Bool ContainsImpl(const Id& t, const TemplateArguments* args, const void* extra) const;

	NodeSystemClass _class;
	AssetRepositoryRef _repository;
	const InstantiationTrace* const _parent = nullptr;
	const NodeTemplate _template = {};
	const TemplateArguments _arguments = {};
	const void* const _extra = nullptr;

	friend class NodeTemplateInterface;
	friend class NodeSystemImpl;
};


//----------------------------------------------------------------------------------------
/// NodesLib provides a set of static methods for the creation and management of node systems.
//----------------------------------------------------------------------------------------
class NodesLib
{
	MAXON_INTERFACE_NONVIRTUAL(NodesLib, MAXON_REFERENCE_NONE, "net.maxon.node.interface.nodeslib");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a NodeSystemBasedNodeTemplate from a template node system.
	/// @param[in] templ							A node system to be used as template.
	/// @param[in] lookup							The asset repository to use for lookup of assets within #templ.
	/// @return												A NodeSystemBasedNodeTemplate based on #templ.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeSystemBasedNodeTemplate> CreateTemplateFromNodeSystem(const NodeSystem& templ, const AssetRepositoryRef& lookup);

	//----------------------------------------------------------------------------------------
	/// Loads a NodeTemplate asset from a repository. This is a convenience method around
	/// AssetRepositoryRef::FindAssets, it returns the latest version for assetId after
	/// a check that the asset is really a NodeTemplate.
	/// @param[in] repo								A repository.
	/// @param[in] assetId						The id of the asset to load.
	/// @return												The loaded NodeTemplate asset, or an IllegalArgumentError if no such asset exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> LoadTemplate(const AssetRepositoryRef& repo, const Id& assetId);

	//----------------------------------------------------------------------------------------
	/// Loads a NodeTemplate asset from the builtin asset repository. This is the same as LoadTemplate,
	/// but restricted to the builtin asset repository.
	/// @param[in] assetId						The id of the asset to load.
	/// @return												The loaded NodeTemplate asset, or an IllegalArgumentError if no such asset exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> LoadBuiltinTemplate(const Id& assetId);

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate which wraps the given template and caches instantiations.
	/// I.e., whenever the template is instantiated with equal arguments,
	/// the returned instantiation will be the same NodeSystem.
	/// @param[in] templ							The node template to wrap.
	/// @return												A wrapper template around templ which caches instantiations.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> CreateTemplateWithInstantiationCache(const NodeTemplate& templ);

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate which wraps a lazily created NodeTemplate. Only when needed the
	/// creator is called once to obtain the NodeTemplate to be wrapped, this is then cached.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] creator						The callback for lazy creation of the wrapped NodeTemplate.
	/// @param[in] support						The callback to implement NodeTemplateInterface::SupportsImpl.
	///																Pass a null value (the default) to use the wrapped implementation.
	/// @return												The lazy NodeTemplate wrapper for #creator.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> CreateLazyTemplate(const Id& nodeId, Delegate<Result<NodeTemplate>()>&& creator, Delegate<Result<Bool>(const NodeSystemClass& cls)>&& support = {});

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate which wraps a lazily created NodeTemplate. Only when needed the
	/// creator is called once to obtain the NodeTemplate to be wrapped, this is then cached.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] creator						The callback for lazy creation of the wrapped NodeTemplate.
	/// @param[in] support						The returned NodeTemplate implements the SupportsImpl method
	///																such that it returns true if and only if the NodeSystemClass argument
	///																has the component given by #support.
	/// @return												The lazy NodeTemplate wrapper for creator.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<NodeTemplate> CreateLazyTemplate(const Id& nodeId, Delegate<Result<NodeTemplate>()>&& creator, const ComponentDescriptor& support)
	{
		return CreateLazyTemplate(nodeId, std::move(creator), [&support] (const NodeSystemClass& cls) -> Result<Bool> { return cls.GetPointer()->GetClassInfo()->GetComponentInfo(support) != nullptr; });
	}

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate which wraps a lazily created NodeTemplate. Only when needed the
	/// creator is called once to obtain the NodeTemplate to be wrapped, this is then cached.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] creator						The callback for lazy creation of the wrapped NodeTemplate.
	/// @param[in] support						The returned NodeTemplate implements the SupportsImpl method
	///																such that it returns true if and only if the NodeSystemClass argument
	///																is the same as the class given by #support or a subclass thereof.
	/// @return												The lazy NodeTemplate wrapper for creator.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<NodeTemplate> CreateLazyTemplate(const Id& nodeId, Delegate<Result<NodeTemplate>()>&& creator, const NodeSystemClass& support)
	{
		return CreateLazyTemplate(nodeId, std::move(creator), [support] (const NodeSystemClass& cls) -> Result<Bool> { return cls.IsSubclassOf(support); });
	}

	using InstantiateDelegate = Delegate<Result<MutableRoot>(const InstantiationTrace& parent, const TemplateArguments& args)>;

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate where the Instantiate method is implemented by the given delegate.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] cache							If true, instantiations will be cached.
	///																I.e., for a given set of template arguments, the delegate will be called only once and the result will be cached.
	/// @param[in] instantiate				The delegate to implement NodeTemplateInterface::InstantiateImpl.
	/// @param[in] support						The callback to implement NodeTemplateInterface::SupportsImpl.
	///																Pass a null value (the default) to use the wrapped implementation.
	/// @return												The NodeTemplate wrapper for #instantiate.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> CreateTemplateFromDelegate(const Id& nodeId, Bool cache, InstantiateDelegate&& instantiate, Delegate<Result<Bool>(const NodeSystemClass& cls)>&& support = {});

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate where the Instantiate method is implemented by the given delegate.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] cache							If true, instantiations will be cached.
	///																I.e., for a given set of template arguments, the delegate will be called only once and the result will be cached.
	/// @param[in] instantiate				The delegate to implement NodeTemplateInterface::InstantiateImpl.
	/// @param[in] support						The returned NodeTemplate implements the SupportsImpl method
	///																such that it returns true if and only if the NodeSystemClass argument
	///																has the component given by #support.
	/// @return												The NodeTemplate wrapper for #instantiate.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<NodeTemplate> CreateTemplateFromDelegate(const Id& nodeId, Bool cache, InstantiateDelegate&& instantiate, const ComponentDescriptor& support)
	{
		return CreateTemplateFromDelegate(nodeId, cache, std::move(instantiate), [&support] (const NodeSystemClass& cls) -> Result<Bool> { return cls.GetPointer()->GetClassInfo()->GetComponentInfo(support) != nullptr; });
	}

	//----------------------------------------------------------------------------------------
	/// Creates a NodeTemplate where the Instantiate method is implemented by the given delegate.
	/// @param[in] nodeId							The asset id to use for the NodeTemplate. The asset repository
	///																will be set to the built-in repository.
	/// @param[in] cache							If true, instantiations will be cached.
	///																I.e., for a given set of template arguments, the delegate will be called only once and the result will be cached.
	/// @param[in] instantiate				The delegate to implement NodeTemplateInterface::InstantiateImpl.
	/// @param[in] support						The returned NodeTemplate implements the SupportsImpl method
	///																such that it returns true if and only if the NodeSystemClass argument
	///																is the same as the class given by #support or a subclass thereof.
	/// @return												The NodeTemplate wrapper for #instantiate.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<NodeTemplate> CreateTemplateFromDelegate(const Id& nodeId, Bool cache, InstantiateDelegate&& instantiate, const NodeSystemClass& support)
	{
		return CreateTemplateFromDelegate(nodeId, cache, std::move(instantiate), [support] (const NodeSystemClass& cls) -> Result<Bool> { return cls.IsSubclassOf(support); });
	}


	//----------------------------------------------------------------------------------------
	/// A Variant describes one of the possibilities among which a user can choose for a
	/// @ref CreateVariantTemplate "variant node template".
	//----------------------------------------------------------------------------------------
	struct Variant
	{
		/// The name of the variant. If empty the key of the VariantTreeMap is used as name.
		/// This is used for leaf nodes as well as for inner nodes of the VariantTreeMap.
		Id name;

		/// The actual node template to use. This is only needed for a leaf node of the VariantTreeMap.
		NodeTemplate templ;

		/// The name of the template parameter port to create for the selection of children.
		/// This is only needed for inner nodes of the VariantTreeMap.
		InternedId childSelector;

		/// The default child to choose.
		/// This is only needed for inner nodes of the VariantTreeMap.
		Id childDefault;
		
		String ToString(const FormatStatement* fs = nullptr) const
		{
			return FormatString("(@,@,@,@)", name, templ, childSelector, childDefault);
		}
	};

	//----------------------------------------------------------------------------------------
	/// A VariantTreeMap is used as argument for CreateVariantTemplate to define the variants
	/// of the variant template.
	//----------------------------------------------------------------------------------------
	using VariantTreeMap = TreeMap<Id, Variant, ArrayMapSelector<false>>;

	//----------------------------------------------------------------------------------------
	/// Creates a variant template for the VariantTreeMap #variants. A variant template allows
	/// the user to choose between different other templates, for example the arithmetic node
	/// allows to select the operation (add, subtract, multiply, divide) at first level
	/// and the datatype at second level. The selection of the variant is controlled by
	/// template parameter ports (see Variant::childSelector) of the returned node template.
	/// @param[in] variants						The variants as a tree of alternatives.
	/// @return												A node template which allows to choose among the #variants using template parameter ports.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeTemplate> CreateVariantTemplate(VariantTreeMap&& variants);


	//----------------------------------------------------------------------------------------
	/// Builds a node template from a resource description.
	/// @param[in] id									The identifier of the description.
	/// @param[in] nodeClass					The node system class to use for the construction.
	/// @param[in] addDependencies		If true (the default) dependency wires are added crosswise between input and output ports.
	/// @param[in] finalizer					An optional finalizer which will be called at the end to allow for customization.
	/// @return												A node template built from the information in a resource description.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeSystemBasedNodeTemplate> BuildNodeFromDescription(const Id& id, const NodeSystemClass& nodeClass, Bool addDependencies = true, const Delegate<Result<void>(const MutableRoot& root)>& finalizer = {});

	//----------------------------------------------------------------------------------------
	/// Creates a DescriptionProcessor which processes a resource description to build a node template.
	/// The actual processing is done by #delegate, the returned DescriptionProcessor just adds
	/// the automatic insertion of the node template into the BuiltinNodes registry.
	/// @param[in] delegate						A delegate to process the dataDescription for descriptionId into a NodeTemplate.
	/// @return												A DescriptionProcessor which wraps #delegate.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DescriptionProcessor> CreateNodeDescriptionProcessor(Delegate<Result<NodeTemplate>(const Id& descriptionId, const DataDescription& dataDescription)>&& delegate);


	//----------------------------------------------------------------------------------------
	/// Checks if a node template asset is @ref NodeTemplate::Supports "supported" by
	/// a node system class using a cache.
	/// The method caches this information in the asset meta data, so that the asset only
	/// needs to be loaded and the NodeTemplate::Supports only needs to be called once.
	/// @param[in] nodeAsset					The node asset to check.
	/// @param[in] cls								The node system class to check.
	/// @return												True if #nodeAsset can be instantiated for #cls, false otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> AssetSupports(const AssetDescription& nodeAsset, const NodeSystemClass& cls);


	//----------------------------------------------------------------------------------------
	/// Creates a ChangeList which can be used to track NodeSystem changes. Most of the methods which
	/// modify a NodeSystem have an optional ChangeList parameter, when a ChangeList is passed
	/// there the changes will be tracked.
	/// @return												A new ChangeList which is compatible with NodeSystem.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ChangeList> CreateChangeList();


	static MAXON_METHOD String PrivateGNodeToString(const GNodeBase& node, const FormatStatement* fs);

	static MAXON_METHOD Result<void> PrivateInitFromPath(GNode& node, const NodeSystem& system, const NodePath& path, NODE_KIND check);

	static MAXON_METHOD Result<void> PrivateInitFromPath(MutableGNode& node, NodeSystemInterface* system, const NodePath& path, NODE_KIND check);
};


//----------------------------------------------------------------------------------------
/// GNodeBase is the base class of node references. The whole hierarchy is
/// - GNodeBase
///   - GNode
///     - Node
///     - PortList
///       - Port
///   - MutableGNode
///     - MutableNode
///       - MutableRoot
///     - MutablePortList
///       - MutablePort
///
/// See also @ref usernodes_nodes for a class diagram and more details. It is important
/// to understand that GNodeBase and its subclasses are not nodes themselves, but references
/// to nodes. Such a reference consists of a reference to the node system and the node path
/// to the g-node within the node system.
//----------------------------------------------------------------------------------------
class GNodeBase
{
public:
	//----------------------------------------------------------------------------------------
	/// Checks if this is a non-null reference to a g-node in some node system.
	/// @return												True for a non-null reference, false otherwise.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return _system != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this g-node is empty and contains no reference.
	/// @return												True if no node is referenced, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _system == nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this is a non-null reference to a g-node in some node system.
	/// @return												True for a non-null reference, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _system != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the node system of this node reference. For a null node a null reference is returned.
	/// @return												The node system of this g-node, or a null reference.
	//----------------------------------------------------------------------------------------
	const NodeSystemInterface::ConstPtr& GetNodeSystem() const
	{
		return reinterpret_cast<const NodeSystemInterface::ConstPtr&>(_system);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the path of this node reference. A g-node is identified by its owning node system
	/// and the path within that node system.
	/// @return												The path of the referenced g-node.
	//----------------------------------------------------------------------------------------
	const NodePath& GetPath() const
	{
		return _node.GetPath();
	}

	/// @copydoc GetPath
	operator const NodePath&() const
	{
		return _node.GetPath();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this node reference. The identifier is the last element of the path,
	/// so it is only guaranteed to be unique among siblings of the referenced node, but not
	/// within the whole node system. For the root node (which has an empty path) the identifier is also empty.
	/// @return												Identifier of this g-node (last path element).
	//----------------------------------------------------------------------------------------
	const InternedId& GetId() const
	{
		return _node.GetPath().GetLastId();
	}

	/// @private
	const GNodeHandle& GetHandle() const
	{
		return _node;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the node kind of this g-node (whether it's a true node, a port list or a port).
	/// @return												The node kind of this g-node.
	//----------------------------------------------------------------------------------------
	NODE_KIND GetKind() const
	{
		return _node.GetKind();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the GNODE_FLAGS of this g-node.
	/// @return												GNODE_FLAGS of this g-node.
	//----------------------------------------------------------------------------------------
	GNODE_FLAGS GetFlags() const
	{
		return _system ? _system->GetFlags(_node) : GNODE_FLAGS::NONE;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this g-node is the same as other.
	/// @param[in] other							Another g-node.
	/// @return												True if this and other are the same g-node, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const GNodeBase& other) const
	{
		return (_system == other._system) && (_node == other._node);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this g-node and other denote different nodes.
	/// @param[in] other							Another g-node.
	/// @return												True if this and other are different nodes, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const GNodeBase& other) const
	{
		return !this->operator ==(other);
	}

	/// @copydoc DefaultDoc::GetHashCode
	HashInt GetHashCode() const
	{
		return _node.GetHashCode();
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs = nullptr) const
	{
		return NodesLib::PrivateGNodeToString(*this, fs);
	}

	/// @private
	static const Bool MUTABLE = false;

	/// @private
	static const NODE_KIND KIND_MASK = NODE_KIND::ALL_MASK;

	/// @private
	static const Bool HAS_ERROR = false;

	/// @private
	const ThreadReferencedError& GetErrorStorage() const
	{
		return GetZeroRef<ThreadReferencedError>();
	}

	/// @private
	using NodeSystemCtorParam = NodeSystemInterface*;

protected:
	GNodeBase() = default;

	GNodeBase(NodeSystemInterface* system, const GNodeHandle& node) : _system(system), _node(node)
	{
	}

	GNodeBase(NodeSystemInterface* system, GNodeHandle&& node) : _system(system), _node(std::move(node))
	{
	}

	void SetNodeSystem(NodeSystemInterface* sys)
	{
		_system = sys;
	}

	// The node system within which _node is to be used. The subclass GNode as well as MutableRoot reinterprets this as a NodeSystem reference so that it participates in reference counting.
	NodeSystemInterface* _system = nullptr;

	// The node handle of a g-node within _system.
	GNodeHandle _node;

	friend class NodeSystemImpl;
	friend class NodesLibImpl;
};

#define PRIVATE_MAXON_NODE_CTOR(name, super) \
	using Super = super; \
	using Super::Super

#define PRIVATE_MAXON_NODEFN_PROLOGUE \
	iferr_scope; \
	if (BASE::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return this->GetErrorStorage(); \
	CheckStateDebugStop(this->GetNodeSystem())

#define PRIVATE_MAXON_NODEFN_MEMBERS(name, super) \
	template <typename SUPER> using ResultFunctions = name<maxon::nodes::details::GNodeResultBase<SUPER>>; \
	PRIVATE_MAXON_NODE_CTOR(name, super)

#define PRIVATE_MAXON_NODE_MEMBERS(name, super) \
	static const name& NullValue() { return GetZeroRef<name>(); } \
	PRIVATE_MAXON_NODE_CTOR(name, super)


//----------------------------------------------------------------------------------------
/// Base class for mutable g-nodes.
//----------------------------------------------------------------------------------------
class MutableGNodeBase : public GNodeBase
{
public:
	/// @private
	static const Bool MUTABLE = true;

	/// @copydoc GNodeBase::GetNodeSystem
	const NodeSystemInterface::Ptr& GetNodeSystem() const
	{
		return reinterpret_cast<const NodeSystemInterface::Ptr&>(_system);
	}

protected:
	PRIVATE_MAXON_NODE_CTOR(MutableGNodeBase, GNodeBase);
};


namespace details
{

template <typename SUPER> class GNodeResultBase : public SUPER
{
public:
	using NodeSystemCtorParam = DummyParamType*;
	static const Bool MUTABLE = std::decay<typename SUPER::ValueType>::type::MUTABLE;

	decltype(std::declval<SUPER>().GetValue().GetNodeSystem()) GetNodeSystem() const
	{
		return this->GetValue().GetNodeSystem();
	}

	const GNodeHandle& GetHandle() const
	{
		return this->GetValue().GetHandle();
	}

	GNodeResultBase() = default;

	GNodeResultBase(DummyParamType*, const GNodeHandle&)
	{
	}

	using SUPER::SUPER;
};

template <typename T> inline Result<T> ConstructGNodeResult(typename ConstIf<NodeSystemInterface, !T::MUTABLE>::type* system, Result<GNodeHandle>&& handle)
{
	if (handle == FAILED)
		return handle.GetErrorStorage();
	return T(system, std::move(handle.GetValue()));
}

}


//----------------------------------------------------------------------------------------
/// The type alias NodeSelector selects between MutableNode (mutable case) and Node (read-only case).
/// @tparam MUTABLE								true for MutableNode, false for Node
//----------------------------------------------------------------------------------------
template <Bool MUTABLE> using NodeSelector = typename std::conditional<MUTABLE, MutableNode, Node>::type;



//----------------------------------------------------------------------------------------
/// This class template contains the functions of a general g-node which shall also be available on Result<NODE>.
//----------------------------------------------------------------------------------------
template <typename BASE> class GNodeFunctions : public BASE
{
public:
	//----------------------------------------------------------------------------------------
	/// Collects all attribute values which are defined for this g-node in #attribs. This includes
	/// values which are set at the node itself, but also values which are inherited from a
	/// base node unless they have been marked as removed by MutableGNode::RemoveValue().
	/// @param[in] mask								A mask to filter the attributes which shall be added to attribs.
	/// 															The mask filter is split into two parts: You have to set at least one of the flags from GraphAttribute::FLAGS::TYPE_MASK
	///																to determine which attribute types shall be taken into account at all.
	///																Optionally you can add further flags, then these have to be matched too.
	/// @param[in] attribs						The map to write the values to.
	/// @param[in] includeInherited		Use true if attributes inherited from base node systems shall be added (the default).
	/// @param[in] includeRemoved			Use true if removed attributes shall be added, too (false by default,
	///																the corresponding attribute value to signal a removed attribute is empty).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetValues(GraphAttribute::FLAGS mask, GraphAttributeMap& attribs, Bool includeInherited = true, Bool includeRemoved = false) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetValues(this->GetHandle(), mask, attribs, includeInherited, includeRemoved);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the value of #attr at this g-node. The value may be
	/// defined at this node itself or at one of its bases. If no value is found or the found value doesn't match
	/// the expectedType, nullptr is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the value. May be nullptr, then no type-check is done.
	/// @return												Pointer to the value of #attr (to be cast to the type of #attr),
	/// 															or nullptr if this g-node has no value for the attribute.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetValue(const InternedId& attr, const DataType& expectedType) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetValue(this->GetHandle(), attr, expectedType);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the value of #attr at this g-node. The value may be
	/// defined at this node itself or at one of its bases. If no value is found or the found value doesn't match
	/// the expectedType, nullptr is returned.
	///
	/// Compared to the basic GetValue function this function has an additional output parameter nesting.
	/// If a value is found, the %nesting of the node system which contained the value
	///	is written to nesting. For example if the attribute value is defined at a node system
	/// which is a child of the root node system, the nesting is 1. If it's a child of a child
	/// the nesting is 2. However if the root node system overrides an attribute value
	/// for a g-node of a child, then the nesting is 0, or -1 when negativeRootNesting is true.
	///
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the value. May be nullptr, then no type-check is done.
	/// @param[out] nesting						If a value is found, the %nesting of the node system which contained the value
	///																is written to nesting.
	/// @param[in] negativeRootNesting	If this is true #nesting will be set to -1 if the value is defined at the root
	/// 															node system. This allows to distinguish between values which are set at the root
	/// 															and those which are inherited from a base (they will report a nesting of 0).
	/// @return												Pointer to the value of #attr (to be cast to the type of #attr),
	/// 															or nullptr if this g-node has no value for the attribute.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetValue(const InternedId& attr, const DataType& expectedType, Int& nesting, Bool negativeRootNesting = false) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetValue(this->GetHandle(), attr, expectedType, &nesting, negativeRootNesting);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the value of #attr at this g-node. The value may be
	/// defined at this node itself or at one of its bases. If no value is found or the found value doesn't match
	/// the expected type T, nullptr is returned.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @tparam T											The expected type of the value.
	/// @return												The value of attr for this g-node, or an empty Opt if this g-node has no value for the attribute.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<Opt<const T&>> GetValue(const InternedId& attr) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(attr, maxon::GetDataType<T>()) iferr_return;
		return Opt<const T&>(reinterpret_cast<const T*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer the value of #ATTR at this g-node. The value may be
	/// defined at this node itself or at one of its bases. If no value is found, nullptr is returned.
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @return												The value of ATTR for this g-node, or an empty Opt if this g-node has no value for the attribute.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetValue() const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(ATTR::GetInstance(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer the value of #ATTR at this g-node. The value may be
	/// defined at this node itself or at one of its bases. If no value is found, nullptr is returned.
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @param[out] nesting						If a value is found, the %nesting of the node system which contained the value
	///																is written to nesting, see GetValue(InternedId, DataType, Int).
	/// @return												The value of ATTR for this g-node, or an empty Opt if this g-node has no value for the attribute.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetValue(Int& nesting) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(ATTR::GetInstance(), maxon::GetDataType<typename ATTR::ValueType>(), nesting) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Yields all values which are stored for attr at this g-node and its bases. While the
	/// normal getter functions only return the outmost value (which overrides the inner ones)
	/// this function allows to obtain also the hidden values.
	///
	/// The found values are reported together with their nesting in ascending order of the nesting.
	/// The nesting is defined as for GetValue(InternedId, DataType, Int) with one exception:
	/// A value which is stored at the root node system itself has a nesting of -1 instead of 0.
	/// This allows to distinguish between such values and values stored at a base of the root node system
	/// (which have a nesting of 0).
	///
	/// @param[in] attr								The attribute whose values shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute. May be nullptr, then no type-check is done.
	/// @param[in] receiver						A callback which receives the attribute values and their nestings.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetBaseValues(const InternedId& attr, const DataType& expectedType, const ValueReceiver<const ConstDataPtr&, Int>& receiver) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetBaseValues(this->GetHandle(), attr, expectedType, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of the DefaultValue attribute at this g-node.
	/// @tparam T											The expected type of the value.
	/// @param[in] def								The default value to use when there is no value for DefaultValue (or the type didn't match).
	/// @return												Value of the DefaultValue attribute (or def).
	//----------------------------------------------------------------------------------------
	template <typename T> Result<const T&> GetDefaultValue(const T& def = maxon::NullValue<const T&>()) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetValue(DefaultValue, GetDataType<T>()) iferr_return;
		return ptr.IsPopulated() ? *(const T*) ptr.PrivateGetPtr() : def;
	}

	//----------------------------------------------------------------------------------------
	/// Reports all attribute modifications which have been made for this g-node since the given stamp to the receiver.
	/// Only stored attributes will be reported, so to also check for new values of computed
	/// attributes you should use GraphAttributeInterface::IsComputedFrom().
	/// @see NodeSystemInterface::GetModificationsSince
	/// @param[in] stamp							A reference time stamp. Only modifications newer than this stamp are reported.
	/// @param[in] receiver						Modifications are reported to this receiver as a pair of the attribute identifier and the current value.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetAttributeModificationsSince(TimeStamp stamp, const ValueReceiver<InternedId, ConstDataPtr>& receiver) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetAttributeModificationsSince(this->GetHandle(), stamp, receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the modification stamp of the given attribute for this g-node. This is the value of
	/// the node system's time stamp (see NodeSystemInterface::GetModificationStamp) at the time when
	/// the attribute value has been set last for this g-node, or a null value if it hasn't been set
	/// at all.
	/// @param[in] attr								An attribute.
	/// @return												The modification stamp of the last change of the attribute value.
	//----------------------------------------------------------------------------------------
	TimeStamp GetAttributeStamp(const InternedId& attr) const
	{
		static_assert(!BASE::HAS_ERROR, "Can't invoke GetAttributeStamp on a Result.");
		const NodeSystemInterface* sys = this->GetNodeSystem();
		return sys ? sys->GetAttributeStamp(this->GetHandle(), attr) : TimeStamp();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the enclosing (true) node to which this g-node belongs.
	/// If this g-node is already a node, then it is returned itself.
	/// @return												The enclosing node if this g-node is a port list or port,
	///																otherwise this node itself.
	//----------------------------------------------------------------------------------------
	Result<NodeSelector<BASE::MUTABLE>> GetNode() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		GNodeHandle n = this->GetHandle();
		while (true)
		{
			if (n.GetKind() == NODE_KIND::NODE)
				return NodeSelector<BASE::MUTABLE>(this->GetNodeSystem(), n);
			CheckAssert(!n.GetPath().IsEmpty());
			n = this->GetNodeSystem().GetPointer()->GetParent(n) iferr_return;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parent node of this node. If this node is null or a root node, a null reference is returned.
	/// @return												Parent node.
	//----------------------------------------------------------------------------------------
	Result<GNodeSelector<BASE::MUTABLE>> GetParent() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		if (this->GetHandle().GetPath().IsEmpty())
			return GNodeSelector<BASE::MUTABLE>();
		else
			return maxon::nodes::details::ConstructGNodeResult<GNodeSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetParent(this->GetHandle()));
	}

	//----------------------------------------------------------------------------------------
	/// Finds a child with the given name or kind. If name is given, this returns the
	/// first direct child of this node which has the identifier #name and whose kind matches
	/// the mask. If name is empty, the function returns the first direct child with matching kind
	/// (in this case children whose identifiers start with a dot are ignored).
	/// @param[in] name								The identifier to look for.
	/// @param[in] mask								A mask for the node kind.
	/// @return												The first direct child which matches name and mask, or a null node.
	//----------------------------------------------------------------------------------------
	Result<GNodeSelector<BASE::MUTABLE>> FindChild(const InternedId& name, NODE_KIND mask) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<GNodeSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), name, mask));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the inner child of this g-node with the given relative path.
	/// If no such child can be found, a null node is returned.
	/// @tparam NODE									The expected node type (such as Node or MutablePort).
	/// @param[in] relativePath				The relative path of the child to find, starting at this node.
	/// @return												The inner child of this node with the given relativePath, or a null node if no such child exists.
	//----------------------------------------------------------------------------------------
	template <typename NODE> Result<typename NODE::template Selector<BASE::MUTABLE>> FindInnerNode(const PathBlock& relativePath) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<typename NODE::template Selector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindInnerNode(this->GetHandle(), relativePath));
	}

	//----------------------------------------------------------------------------------------
	/// Yields all inner nodes of this g-node matching #mask in pre-order. The recursive traversal
	/// stops at nodes which don't match #mask.
	/// @param[in] mask								Mask to filter the tree traversal. Only nodes matching this mask are considered.
	///																The node on which GetInnerNodes is called isn't checked for mask.
	/// @param[in] includeThis				If true, the node on which GetInnerNodes is called is yielded to #receiver too.
	/// @param[in] receiver						Inner nodes are reported to this value receiver.
	/// @return												false if #receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetInnerNodes(NODE_KIND mask, Bool includeThis, const ValueReceiver<const GNodeSelector<BASE::MUTABLE>&>& receiver) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return const_cast<NodeSystemInterface*>(this->GetNodeSystem().GetPointer())->GetInnerNodes(this->GetHandle(), mask, includeThis, reinterpret_cast<const ValueReceiver<const MutableGNode&>&>(receiver));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the base node system of this node
	/// (or in other words, the node system of which this node is an instance).
	/// - For a root node, this is the @ref NodeSystem::GetBase "base" of the root's node system (which may be null).
	///   In the instancing graph below the base of `B` is `A` and the base of `E` is `D`.
	///		`A`, `C` and `D` have no bases.
	/// - Otherwise we have a nested node, then we follow the chain of bases until we reach a root node.
	///		In the instancing graph the base node system of the nodes `n` of `C`, `m/n` of `D`
	///		as well as `m/n` of `E` is `B`. The base node system of the node `m` of `D` and of `E` is `C`.
	///
	/// @graph
	///                                                     +-D--------------+      +-E--------------+
	///                                 +-C----------+      | +-m----------+ |      | +-m----------+ |
	/// +-A------+      +-B------+      | +-n------+ |      | | +-n------+ | |      | | +-n------+ | |
	/// |        |<- - -|        |<- - - -|        | |<- - - -| |        | | |<- - -| | |        | | |
	/// +--------+      +--------+      | +--------+ |      | | +--------+ | |      | | +--------+ | |
	///                                 +------------+      | +------------+ |      | +------------+ |
	///                                                     +----------------+      +----------------+
	/// @endgraph
	/// If this node is not a true node but a port or port list, the base of the enclosing true node
	/// is returned.
	/// @return												The base node system of this node, may be a null reference.
	//----------------------------------------------------------------------------------------
	const NodeSystem& GetBase() const
	{
		static_assert(!BASE::HAS_ERROR, "This function can't be invoked on Result<Node>.");
		return this->GetNodeSystem() ? this->GetNodeSystem().GetPointer()->GetBase(this->GetHandle()) : GetZeroRef<NodeSystem>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the NodeTemplate which instantiated this node. For a root node, this is the
	/// @ref NodeSystem::GetTemplate "template" of the root's node system. Otherwise it is the
	/// template of the @ref GetBase "base" of this node.
	/// @return												The NodeTemplate which instantiated this node, may be a null reference.
	//----------------------------------------------------------------------------------------
	const NodeTemplate& GetTemplate() const
	{
		static_assert(!BASE::HAS_ERROR, "This function can't be invoked on Result<Node>.");
		return this->GetNodeSystem() ? this->GetNodeSystem().GetPointer()->GetTemplate(this->GetHandle()) : GetZeroRef<NodeTemplate>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the derivation handler of this node.
	/// @return												The NodeSystemDerivationHandler of this node.
	//----------------------------------------------------------------------------------------
	const NodeSystemDerivationHandler& GetDerivationHandler() const
	{
		static_assert(!BASE::HAS_ERROR, "This function can't be invoked on Result<Node>.");
		return this->GetNodeSystem() ? this->GetNodeSystem().GetPointer()->GetDerivationHandler(this->GetHandle()) : GetZeroRef<NodeSystemDerivationHandler>();
	}

protected:
	PRIVATE_MAXON_NODE_CTOR(GNodeFunctions, BASE);
};


//----------------------------------------------------------------------------------------
/// GNode is the base class of immutable node references. The class hierarchy is
/// - GNodeBase
///   - GNode
///     - Node
///     - PortList
///       - Port
///
/// See also @ref usernodes_nodes for a class diagram and more details. The method
/// NodeSystem::GetRoot() returns a reference to the root node of a node system, from this
/// all other nodes and ports can be found. However it is not possible to get mutable node
/// references starting with an immutable reference, for mutable references see MutableRoot.
//----------------------------------------------------------------------------------------
class GNode : public GNodeFunctions<GNodeBase>
{
public:
	/// @copydoc DefaultDoc::Reset
	void Reset()
	{
		reinterpret_cast<NodeSystem&>(_system) = nullptr;
		_node.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Resets this reference to a null reference.
	//----------------------------------------------------------------------------------------
	GNode& operator =(std::nullptr_t)
	{
		Reset();
		return *this;
	}

	/// @copydoc GNodeBase::GetNodeSystem
	const NodeSystem& GetNodeSystem() const
	{
		return reinterpret_cast<const NodeSystem&>(_system);
	}

	/// @private
	using NodeSystemCtorParam = const NodeSystem&;

	//----------------------------------------------------------------------------------------
	/// Constructs a null node reference.
	//----------------------------------------------------------------------------------------
	GNode() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a g-node reference from a node system and a node handle.
	/// @param[in] system							The node system to use.
	/// @param[in] handle							A handle for a node within the given node system.
	/// @private
	//----------------------------------------------------------------------------------------
	GNode(const NodeSystem& system, const GNodeHandle& handle) : GNodeFunctions<GNodeBase>(nullptr, handle)
	{
		if (_node)
		{
			reinterpret_cast<NodeSystem&>(_system) = system;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a g-node reference from a node system and a node handle.
	/// @param[in] system							The node system to use.
	/// @param[in] handle							A handle for a node within the given node system.
	/// @private
	//----------------------------------------------------------------------------------------
	GNode(const NodeSystem& system, GNodeHandle&& handle) : GNodeFunctions<GNodeBase>(nullptr, std::move(handle))
	{
		if (_node)
		{
			reinterpret_cast<NodeSystem&>(_system) = system;
		}
	}

	~GNode()
	{
		reinterpret_cast<NodeSystem&>(_system) = nullptr;
	}

	GNode(const GNode& other) : GNodeFunctions<GNodeBase>(nullptr, other._node)
	{
		reinterpret_cast<NodeSystem&>(_system) = other._system;
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(GNode);

	GNode(GNode&& other) : GNodeFunctions<GNodeBase>(nullptr, std::move(other._node))
	{
		reinterpret_cast<NodeSystem&>(_system) = std::move(reinterpret_cast<NodeSystem&>(other._system));
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GNode);

	//----------------------------------------------------------------------------------------
	/// Initializes a g-node reference from a node system and a path. If there's no node
	/// in the node system for the given path, this reference is set to a null reference.
	/// If a node exists but its kind doesn't match the check mask, an IllegalArgumentError
	/// is returned.
	/// @param[in] system							The node system to use.
	/// @param[in] path								A path which points to a g-node in the given node system.
	/// @param[in] check							A mask of the expected node kind(s).
	///	@return												Usually OK (even when path doesn't exist),
	///																but an IllegalArgumentError if path exists but doesn't match check.
	//----------------------------------------------------------------------------------------
	Result<void> InitFromPath(const NodeSystem& system, const NodePath& path, NODE_KIND check = NODE_KIND::ALL_MASK)
	{
		return NodesLib::PrivateInitFromPath(*this, system, path, check);
	}

protected:
	void SetNodeSystem(const NodeSystem& sys)
	{
		reinterpret_cast<NodeSystem&>(_system) = sys;
	}

	friend class NodesLibImpl;
};


//----------------------------------------------------------------------------------------
/// This class template contains the functions of a general mutable g-node which shall also be available on Result<NODE>.
//----------------------------------------------------------------------------------------
template <typename BASE> class MutableGNodeFunctions : public GNodeFunctions<BASE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Removes the referenced g-node from this node system. Internally how the removal is done
	/// depends on the situation:
	/// 1. If the node is not defined by this node system, but inherited from a base, it is
	///    marked as removed in this node system, so effectively the inherited node is hidden.
	/// 2. If the node is defined by this node system, the node definition is removed. If this
	///    makes an inherited node visible, the latter is marked as removed as in the first case.
	///
	/// Not all g-nodes can be removed:
	/// - Input or output port lists can never be removed.
	/// - Top-level ports can only be removed if they belong to the root node. There are no
	///   restrictions on nested ports.
	/// - True nodes can only be removed if they are direct children of the root node.
	/// @param[in] list								An optional ChangeList to track the changes.
	//----------------------------------------------------------------------------------------
	Result<void> Remove(Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->Remove(this->GetHandle(), list);
	}

	//----------------------------------------------------------------------------------------
	/// Removes any data for the child node #childId of the referenced node from the node system
	/// so that the state of the child node is restored to an unmodified instance of its base node.
	/// If there is no base, the node ceases to exist in the current node system.
	/// This function only has an effect if modifications to the child node have been made at the
	/// level of the node system of this reference.
	/// @param[in] childId						The identifier of the child of this node which shall be restored to its inherited state.
	/// @param[in] list								An optional ChangeList to track the changes.
	//----------------------------------------------------------------------------------------
	Result<void> InheritChild(const InternedId& childId, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->InheritChild(this->GetHandle(), childId, list);
	}

	//----------------------------------------------------------------------------------------
	/// Restores the inherited state of the value for #attr. This removes any value which has
	/// been set in this node system. It will also annul the effect of a previous invocation of RemoveValue().
	/// @param[in] attr								The attribute whose value at this g-node shall be restored to the inherited state.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	/// @see RemoveValue
	//----------------------------------------------------------------------------------------
	Result<Bool> InheritValue(const InternedId& attr, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->InheritValue(this->GetHandle(), attr, list);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an attribute value from this g-node. The node won't have
	/// a value for #attr afterwards, i.e., even if one of its bases has a value for #attr,
	/// this node doesn't inherit the value. The removal can be undone by calling InheritValue().
	/// @param[in] attr								The attribute whose value shall be removed from this g-node.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												True if modified.
	/// @see InheritValue
	//----------------------------------------------------------------------------------------
	Result<Bool> RemoveValue(const InternedId& attr, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->RemoveValue(this->GetHandle(), attr, list);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an attribute value from this g-node. The node won't have
	/// a value for ATTR afterwards, i.e., even if one of its bases has a value for ATTR,
	/// this node doesn't inherit the value. The removal can be undone by calling InheritValue().
	/// @tparam ATTR									The attribute whose value shall be removed from this g-node.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	/// @see InheritValue
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> RemoveValue(Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->RemoveValue(this->GetHandle(), ATTR::GetInstance(), list);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for this g-node. This will override any value
	/// which would otherwise be inherited for the attribute from a base.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The new value for the attribute.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<Bool> SetValue(const InternedId& attr, ForwardingDataPtr&& value, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->SetValue(this->GetHandle(), attr, std::move(value), list);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of ATTR to #value for this g-node. This will override any value
	/// which would otherwise be inherited for the attribute from a base. Example:
	/// @code
	/// MutablePort port;
	/// port.SetValue<decltype(InheritNestedPorts)>(false) iferr_return;
	/// @endcode
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The new value for the attribute.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(const typename ATTR::ValueType& value, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->SetValue(this->GetHandle(), ATTR::GetInstance(), ConstDataPtr(value), list);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of ATTR to #value for this g-node. This will override any value
	/// which would otherwise be inherited for the attribute from a base. Example:
	/// @code
	/// MutablePort port;
	/// TypeAccess ta;
	/// port.SetValue<decltype(FixedPortType)>(std::move(ta)) iferr_return;
	/// @endcode
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] value							The new value for the attribute, this will be moved into the g-node.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetValue(typename ATTR::ValueType&& value, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->SetValue(this->GetHandle(), ATTR::GetInstance(), MoveDataPtr(std::move(value)), list);
	}

	//----------------------------------------------------------------------------------------
	/// Sets a part of the value of #attr to #value for this g-node.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] op									The SubDataOperation to use.
	/// @param[in] path								The path to the part of the attribute value which shall be changed.
	/// @param[in] value							The new value for the part.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ChangeValue(const InternedId& attr, const SubDataOperation& op, const SubDataPathBlock& path, ForwardingDataPtr&& value, Opt<ChangeList&> list = {}) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->ChangeValue(this->GetHandle(), attr, op, path, std::move(value), list);
	}

protected:
	PRIVATE_MAXON_NODE_CTOR(MutableGNodeFunctions, GNodeFunctions<BASE>);
};


//----------------------------------------------------------------------------------------
/// MutableGNode is the base class of mutable node references. The class hierarchy is
/// - GNodeBase
///   - MutableGNode
///     - MutableNode
///       - MutableRoot
///     - MutablePortList
///       - MutablePort
///
/// See also @ref usernodes_nodes for a class diagram and more details. The function
/// NodeSystem::BeginModification() returns a reference to the root node of a node system with write access,
/// from this all other nodes and ports can be found and modified.
//----------------------------------------------------------------------------------------
class MutableGNode : public MutableGNodeFunctions<MutableGNodeBase>
{
public:
	/// @copydoc DefaultDoc::Reset
	void Reset()
	{
		_system = nullptr;
		_node.Reset();
	}

	/// @copydoc GNode::operator=
	MutableGNode& operator =(std::nullptr_t)
	{
		Reset();
		return *this;
	}

	/// @copydoc GNode::GNode
	MutableGNode() = default;

	/// @copydoc GNode::GNode(NodeSystem,GNodeHandle)
	/// @private
	MutableGNode(NodeSystemInterface* system, const GNodeHandle& node) : MutableGNodeFunctions<MutableGNodeBase>(node ? system : nullptr, node)
	{
	}

	/// @copydoc GNode::GNode(NodeSystem,GNodeHandle)
	/// @private
	MutableGNode(NodeSystemInterface* system, GNodeHandle&& node) : MutableGNodeFunctions<MutableGNodeBase>(node ? system : nullptr, std::move(node))
	{
	}

	/// @copydoc GNode::InitFromPath
	Result<void> InitFromPath(NodeSystemInterface* system, const NodePath& path, NODE_KIND check = NODE_KIND::ALL_MASK)
	{
		return NodesLib::PrivateInitFromPath(*this, system, path, check);
	}
};



//----------------------------------------------------------------------------------------
/// Internal base class for GNodeIterator.
/// @private
//----------------------------------------------------------------------------------------
class GNodeIteratorBase
{
public:
	Result<void> Init(const NodeSystemInterface* nodeSystem, const GNodeHandle& node)
	{
		iferr_scope;
		_baseData = nullptr;
		CheckArgument(nodeSystem);
		return nodeSystem->InitIterator(node, *this);
	}

	Result<void> Init(const NodeSystemInterface* nodeSystem, Result<GNodeHandle>&& node)
	{
		iferr_scope;
		if (node == FAILED)
			return node.GetErrorStorage();
		_baseData = nullptr;
		CheckArgument(nodeSystem);
		return nodeSystem->InitIterator(node.GetValue(), *this);
	}

	Result<void> Init(const NodeSystemInterface* nodeSystem, Result<const GNodeHandle&>&& node)
	{
		iferr_scope;
		if (node == FAILED)
			return node.GetErrorStorage();
		_baseData = nullptr;
		CheckArgument(nodeSystem);
		return nodeSystem->InitIterator(node.GetValue(), *this);
	}

	Result<void> MoveToNext()
	{
		return _nodeSystem->MoveToNext(*this);
	}

	Bool HasEntry() const
	{
		return _baseData != nullptr;
	}

	explicit operator Bool() const
	{
		return _baseData != nullptr;
	}

	const GNodeHandle& GetHandle() const
	{
		return _child.GetHandle();
	}

	const MutableGNode& GetNode() const
	{
		return _child;
	}

protected:
	// node system, path and data of the node over whose children shall be iterated
	const NodeSystemInterface* _nodeSystem;
	NodePath _nodePath;
	const GNodeData* _nodeData;

	// current base of node
	const GNodeData* _baseData;

	// current index in the children list of _baseData
	Int _childIndex;

	// current child
	MutableGNode _child;

	friend class NodeSystemImpl;
};


//----------------------------------------------------------------------------------------
/// A GNodeIterator iterates over all children of a g-node. It is returned by
/// NodeFunctions::GetChildren and PortListFunctions::GetPorts. Because both creation and
/// iterator advance can return errors, the iteration doesn't provide the node of
/// the current iteration directly, but wrapped in a Result. Therefore you have to
/// write the loop as follows:
/// @code
///	for (auto p : portlist.GetPorts())
///	{
///		Port port = p iferr_return;
///		...
///	}
/// @endcode
/// @tparam NODE									The node class over which the iterator loops (e.g. Node or MutablePort).
//----------------------------------------------------------------------------------------
template <typename NODE> class GNodeIterator : public GNodeIteratorBase
{
public:
	/// @copydoc DefaultDoc::DefaultDoc
	GNodeIterator() = default;

	//----------------------------------------------------------------------------------------
	/// Advances this iterator to the next child node.
	/// @return												OK on success, or an error. Advancing to the position
	///																one behind the last child is no error.
	//----------------------------------------------------------------------------------------
	Result<void> operator ++()
	{
		iferr_scope;
		GNodeIteratorBase::MoveToNext() iferr_return;
		return Filter();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current child node. This function must not be called when this iterator
	/// doesn't point to a valid child node.
	/// @return												The current child node.
	//----------------------------------------------------------------------------------------
	const NODE& operator *() const
	{
		return reinterpret_cast<const NODE&>(this->_child);
	}

	/// @copydoc operator*
	const NODE* operator ->() const
	{
		return &reinterpret_cast<const NODE&>(this->_child);
	}

	/// @private
	Result<void> Init(const NodeSystemInterface* nodeSystem, const GNodeHandle& node)
	{
		iferr_scope;
		GNodeIteratorBase::Init(nodeSystem, node) iferr_return;
		return Filter();
	}

	/// @private
	template <typename SUPER> using ResultFunctions = ResultIteratorFunctions<SUPER>;

private:
	Result<void> Filter()
	{
		iferr_scope;
		while ((NODE::KIND_MASK & NODE_KIND::NODE) && this->_baseData && (this->_child.GetHandle().GetKind() != NODE_KIND::NODE))
		{
			GNodeIteratorBase::MoveToNext() iferr_return;
		}
		return OK;
	}
};


//----------------------------------------------------------------------------------------
/// The type alias PortListSelector selects between MutablePortList (mutable case) and PortList (read-only case).
/// @tparam MUTABLE								true for MutablePortList, false for PortList
//----------------------------------------------------------------------------------------
template <Bool MUTABLE> using PortListSelector = typename std::conditional<MUTABLE, MutablePortList, PortList>::type;


//----------------------------------------------------------------------------------------
/// The type alias PortSelector selects between MutablePort (mutable case) and Port (read-only case).
/// @tparam MUTABLE								true for MutablePort, false for Port
//----------------------------------------------------------------------------------------
template <Bool MUTABLE> using PortSelector = typename std::conditional<MUTABLE, MutablePort, Port>::type;


namespace details
{
template <typename BASE> using NodeFunctionsSuper = typename std::conditional<BASE::HAS_ERROR, typename std::conditional<BASE::MUTABLE, MutableGNodeFunctions<BASE>, GNodeFunctions<BASE>>::type, GNodeSelector<BASE::MUTABLE>>::type;
}


//----------------------------------------------------------------------------------------
/// This class template contains the functions of Node which shall also be available on Result<Node> (and likewise for MutableNode).
//----------------------------------------------------------------------------------------
template <typename BASE> class NodeFunctions : public maxon::nodes::details::NodeFunctionsSuper<BASE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the parent node of this node. If this node is null or a root node, a null reference is returned.
	/// @return												Parent node.
	//----------------------------------------------------------------------------------------
	Result<NodeSelector<BASE::MUTABLE>> GetParent() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		if (this->GetHandle().GetPath().IsEmpty())
			return NodeSelector<BASE::MUTABLE>();
		else
			return maxon::nodes::details::ConstructGNodeResult<NodeSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetParent(this->GetHandle()));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the direct child node with the given identifier. If this node is null or if there is not exactly
	/// one such child, a null reference. This function only searches for true nodes, but not for
	/// port lists.
	/// @param[in] name								Identifier of the child node to find.
	/// @return												Found node or a null reference.
	//----------------------------------------------------------------------------------------
	Result<NodeSelector<BASE::MUTABLE>> FindChild(const InternedId& name) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<NodeSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), name, NODE_KIND::NODE));
	}

	/// @copydoc FindChild
	Result<NodeSelector<BASE::MUTABLE>> FindChild(const Id& name) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		InternedId iid;
		iid.Init(name) iferr_return;
		return maxon::nodes::details::ConstructGNodeResult<NodeSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), iid, NODE_KIND::NODE));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the nested g-node which corresponds to the given nested g-node
	/// of a base of this node. #baseInner has to refer to a node which is nested
	/// within a base of this node. For example consider the following graph:
	/// @graph
	///                                         +-C----------------+
	///                   +-B------------+      | +-m------------+ |
	/// +-A--------+      | +-n--------+ |      | | +-n--------+ | |
	/// o port     |      | o port     | |      | | o port     | | |
	/// |          |<- - - -|          | |<- - - -| |          | | |
	/// +----------+      | +----------+ |      | | +----------+ | |
	///                   +--------------+      | +--------------+ |
	///                                         +------------------+
	/// @endgraph
	/// The nested node `m/n` of node system `C` has the root node of node system `A` as its base
	/// (via the intermediate base `n` of `B`). The root node of `A` has `port` as a nested g-node,
	/// and the corresponding nested g-node of `m/n` is the `port` nested within `m/n`:
	/// @code
	/// Port port = ...; // port of A
	/// Node n = ...; // node m/n of C
	/// Port portInN = n.FindInnerNode(port) iferr_return; // returns reference to port within m/n
	/// @endcode
	/// @param[in] baseInner					Inner node of the base of this node.
	/// @return												Found node or a null reference.
	//----------------------------------------------------------------------------------------
	template <typename NODE> Result<typename NODE::template Selector<BASE::MUTABLE>> FindInnerNode(const NODE& baseInner) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<typename NODE::template Selector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindInnerNode(this->GetHandle(), baseInner.GetPath().ToBlock()));
	}

#ifdef MAXON_COMPILER_MSVC
	using MSVCWorkAround = maxon::nodes::details::NodeFunctionsSuper<BASE>;
	using MSVCWorkAround::FindInnerNode;
#else
	using maxon::nodes::details::NodeFunctionsSuper<BASE>::FindInnerNode;
#endif

	//----------------------------------------------------------------------------------------
	/// Returns the input or output port list of this node, depending on dir.
	/// @see @$ref usernodes_nodes
	/// @param[in] dir								PORT_DIR::INPUT to return the input port list, PORT_DIR::OUTPUT to return the output port list.
	/// @return												Port list of this node.
	//----------------------------------------------------------------------------------------
	Result<PortListSelector<BASE::MUTABLE>> GetPortList(PORT_DIR dir) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortListSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetPortList(this->GetHandle(), dir));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the input port list of this node. All top-level input ports of a node
	/// can be found as children of its input port list.
	/// @see @$ref usernodes_nodes
	/// @return												Input port list of this node.
	//----------------------------------------------------------------------------------------
	Result<PortListSelector<BASE::MUTABLE>> GetInputs() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortListSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetPortList(this->GetHandle(), PORT_DIR::INPUT));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the output port list of this node. All top-level output ports of a node
	/// can be found as children of its output port list.
	/// @see @$ref usernodes_nodes
	/// @return												Output port list of this node.
	//----------------------------------------------------------------------------------------
	Result<PortListSelector<BASE::MUTABLE>> GetOutputs() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortListSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetPortList(this->GetHandle(), PORT_DIR::OUTPUT));
	}

	/// @copydoc GNodeIterator
	using Iterator = GNodeIterator<NodeSelector<BASE::MUTABLE>>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator over the child nodes of this node. This does only include true nodes,
	/// but not the input/output port lists.
	/// @code
	///	for (auto c : node.GetChildren())
	///	{
	///		Node child = c iferr_return;
	///		...
	///	}
	/// @endcode
	/// @see @$ref usernodes_nodes
	/// @return												Iterator over the children of this node.
	//----------------------------------------------------------------------------------------
	Result<Iterator> GetChildren() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		Result<Iterator> res;
		res.GetValue().Init(this->GetNodeSystem(), this->GetHandle()) % res.GetErrorStorage();
		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Initializes a node reference from a node system and a path. If there's no node
	/// in the node system for the given path, this reference is set to a null reference.
	/// @param[in] system							The node system to use.
	/// @param[in] path								A path which points to a node in the given node system.
	///	@return												Usually OK (even when path doesn't exist),
	///																but an IllegalArgumentError if path exists but doesn't point to a true node.
	//----------------------------------------------------------------------------------------
	Result<void> InitFromPath(typename maxon::nodes::details::NodeFunctionsSuper<BASE>::NodeSystemCtorParam system, const NodePath& path)
	{
		return NodesLib::PrivateInitFromPath(*this, system, path, NODE_KIND::NODE);
	}

	/// @private
	template <Bool MUT> using Selector = NodeSelector<MUT>;

	/// @private
	static const NODE_KIND KIND_MASK = NODE_KIND::NODE;

	PRIVATE_MAXON_NODEFN_MEMBERS(NodeFunctions, maxon::nodes::details::NodeFunctionsSuper<BASE>);
};


//----------------------------------------------------------------------------------------
/// Node represents a node within a NodeSystem. A node may be either
/// the /root node/ of a node system or a /nested/ node (i.e., a child of another node). A direct child
/// of a root node is called a /root child node/.
///
/// A node may be an /instance/ of another node, in which case it inherits the ports and nested nodes from that base node,
/// but it is still possible to remove inherited ports and children, or add additional ones.
///
/// Node allows for read-only access to the node of the NodeSystem. If you want to make
/// modifications, you have to use MutableNode instead.
//----------------------------------------------------------------------------------------
class Node : public NodeFunctions<GNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(Node, NodeFunctions<GNodeBase>);
};


//----------------------------------------------------------------------------------------
/// This class template contains the functions of MutableNode which shall also be available on Result<MutableNode>.
//----------------------------------------------------------------------------------------
template <typename BASE> class MutableNodeFunctions : public NodeFunctions<BASE>
{
public:
	PRIVATE_MAXON_NODEFN_MEMBERS(MutableNodeFunctions, NodeFunctions<BASE>);
};


//----------------------------------------------------------------------------------------
/// MutableNode represents a node within a NodeSystem with write access. A node may be either
/// the /root node/ of a node system or a /nested/ node (i.e., a child of another node). A direct child
/// of a root node is called a /root child node/.
///
/// A node may be an /instance/ of another node, in which case it inherits the ports and nested nodes from that base node,
/// but it is still possible to remove inherited ports and children, or add additional ones.
/// @see @$ref usernodes_modifications
//----------------------------------------------------------------------------------------
class MutableNode : public MutableNodeFunctions<MutableGNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(MutableNode, MutableNodeFunctions<MutableGNodeBase>);

	//----------------------------------------------------------------------------------------
	/// Casts this MutableNode to an immutable Node. If you call this function during
	/// an active modification you have to make sure that the returned Node (and all further
	/// immutable references which are obtained through this Node) is only stored temporarily
	/// and goes out of scope before the next modification is made,
	/// see @ref usernodes_modifications.
	///	@return												This node as a Node.
	//----------------------------------------------------------------------------------------
	const Node& ToImmutable() const
	{
		// Final validation when converting to an immutable reference.
		// Otherwise there would be a race condition for concurrent validations (concurrency can only happen for immutable references in correct code).
		if (this->GetNodeSystem())
			this->GetNodeSystem().GetPointer()->PrivateValidate(_node);
		return *static_cast<const Node*>(static_cast<const GNodeBase*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Dissolves this node into its children. This can only be called for a direct child node
	/// of the root node which is a group. It moves all children of that node including their
	/// inner connections to the root node. External connections (from the group to other nodes)
	/// are moved to the inner nodes as well.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												The mapping from original identifiers within the group to the new identifiers used at root level.
	/// @see MutableRoot::MoveToGroup
	//----------------------------------------------------------------------------------------
	Result<HashMap<InternedId, InternedId>> Ungroup(Opt<ChangeList&> list = {})
	{
		iferr_scope;
		CheckState(_system);
		return _system->Ungroup(_node, list);
	}

	Result<NodeSystem> MoveToNodeSystem(Opt<ChangeList&> list = {})
	{
		iferr_scope;
		CheckState(_system);
		return _system->MoveToNodeSystem(_node, list);
	}
};


//----------------------------------------------------------------------------------------
/// MutableRoot is a subclass of MutableNode and used for root nodes of node systems with write access.
/// Such a node is returned by NodeSystem::BeginModifications(). The difference to MutableNode
/// is that MutableRoot allows to add children, because this is only possible at the root level,
/// and that MutableRoot holds a strong reference on the node system. You have to ensure that this
/// reference is the only reference during the modification.
/// @see @$ref usernodes_modifications
//----------------------------------------------------------------------------------------
class MutableRoot : private MutableNode
{
	// Note: We use private inheritance for safety reasons, otherwise we could assign a MutableRoot to a non-const MutableNode&.
	// Because MutableRoot holds a strong reference, but MutableNode just a pointer, changing the MutableRoot through the
	// MutableNode& would break the reference counting.
public:
	/// @copydoc DefaultDoc::Reset
	void Reset()
	{
		reinterpret_cast<NodeSystem&>(_system) = nullptr;
		_node.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Resets this reference to a null reference.
	//----------------------------------------------------------------------------------------
	MutableRoot& operator =(std::nullptr_t)
	{
		Reset();
		return *this;
	}

	/// @copydoc GNode::GNode
	MutableRoot() = default;

	~MutableRoot();

	MutableRoot(MutableRoot&& src) : MutableNode(std::move(src))
	{
		src._system = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(MutableRoot);

	MAXON_DISALLOW_COPY_AND_ASSIGN(MutableRoot);

	Result<void> CopyFrom(const MutableRoot& src)
	{
		return UnsupportedOperationError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// Adds an instance of a node system as child to this root node. If #childId is empty, a
	/// UUID will be chosen as identifier of the child, otherwise #childId. In the latter
	/// case it is an error if this root node already has a child with that identifier.
	/// @param[in] childId						Identifier for the child node (if empty, a UUID is chosen).
	/// @param[in] base								Node system to add as an instance.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												Reference to the added child.
	//----------------------------------------------------------------------------------------
	Result<MutableNode> AddChild(const Id& childId, const Result<NodeSystem>& base, Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Adds an instance of a node system as child to this root node. If #childId is empty, a
	/// UUID will be chosen as identifier of the child, otherwise #childId. In the latter
	/// case it is an error if this root node already has a child with that identifier.
	/// @param[in] childId						Identifier for the child node (if empty, a UUID is chosen).
	/// @param[in] templ							NodeTemplate of which an instantiation shall be added as an instance to this root node.
	/// @param[in] args								Template arguments for templ.
	/// @param[in] lookup							The asset repository to use for lookup of assets within the instantiation of templ.
	///																If this is a null reference (the default), then the repository of templ will be used.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												Reference to the added child.
	//----------------------------------------------------------------------------------------
	Result<MutableNode> AddChild(const Id& childId, const Result<NodeTemplate>& templ, const TemplateArguments& args = maxon::NullValue<const TemplateArguments&>(), const AssetRepositoryRef& lookup = maxon::NullValue<const AssetRepositoryRef&>(), Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Replaces the base of the current node system.
	/// @param[in] base								The new base node system.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												A new change list which contains those parts of the original node system.
	///																which couldn't be restored for the new base.
	//----------------------------------------------------------------------------------------
	Result<ChangeList> ReplaceBase(const NodeSystem& base, Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Replaces the base of an existing child of this root node.
	/// @param[in] childId						Identifier for the child node.
	/// @param[in] base								The new base node system for the child node.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												A new change list which contains those parts of the original node system.
	///																which couldn't be restored for the new base.
	//----------------------------------------------------------------------------------------
	Result<ChangeList> ReplaceChild(const InternedId& childId, const NodeSystem& base, Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Groups the selection of direct child nodes of this node system into a new group node.
	/// groupRoot is used to set up the new group node, usually you provide an empty new node
	/// system for groupRoot. All selected nodes are moved to the group using their original
	/// identifiers, including inner connections. Afterwards the group is @ref EndModification "finalized"
	/// and an instance of the group is added to this node system using the given groupId.
	/// Connections which leave the group are kept by adding ports to the group node
	/// as needed, and connecting them correspondingly. If the used group node already has ports,
	/// these will be used where identifiers mach.
	/// @param[in] groupRoot					The MutableRoot of another (usually empty) node system which will become the group.
	///																The function will clear this reference after successful creation of the group.
	/// @param[in] groupId						Identifier for the new group within this node system (if empty, a UUID is chosen).
	/// @param[in] selection					A selection of nodes, namely children of the root node. Identifiers for which no root child node exists are ignored.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												Reference to the added group node.
	/// @see MutableNode::Ungroup
	//----------------------------------------------------------------------------------------
	Result<MutableNode> MoveToGroup(MutableRoot& groupRoot, const Id& groupId, const Block<const InternedId>& selection, Opt<ChangeList&> list = {}) const
	{
		iferr_scope;
		CheckState(_system);
		return maxon::nodes::details::ConstructGNodeResult<MutableNode>(_system, _system->MoveToGroup(groupRoot, groupId, selection, list));
	}

	//----------------------------------------------------------------------------------------
	/// Merges the other node system into this node system. Top-level nodes and ports are added into this node system
	/// using new unique identifiers to prevent naming conflicts. The mapping from the original identifiers
	/// of other to the new ones is returned.
	/// @param[in] other							Another node system to merge into this node system.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												The mapping from original identifiers of #other to the identifiers used for the merge:
	///																- first contains the mapping of top-level nodes.
	///																- second contains the mapping of top-level input ports.
	///																- third contains the mapping of top-level output ports.
	//----------------------------------------------------------------------------------------
	Result<HomogenousTupleType<3, HashMap<InternedId, InternedId>>> Merge(const NodeSystem& other, Opt<ChangeList&> list = {}) const
	{
		iferr_scope;
		CheckState(_system);
		return _system->Merge(other, list);
	}

	//----------------------------------------------------------------------------------------
	/// Adds the other node system as an additional @ref NodeSystemInterface::GetBases "base"
	/// of this node system. This merges the other node system into this node system,
	/// port identifiers are kept (unlike for Merge).
	/// @param[in] other							Another node system to add as base and merge into this node system.
	//----------------------------------------------------------------------------------------
	Result<void> AddBase(const NodeSystem& other) const
	{
		iferr_scope;
		CheckState(_system);
		return _system->AddBase(other);
	}

	//----------------------------------------------------------------------------------------
	/// Validates the topology of the node system. This checks for cycles in the node graph
	/// and sets up the @ref NodeSystemInterface::GetTopologicalOrder "topological ordering".
	/// Usually you don't have to call this as it gets called implicitly by ValidatePorts,
	/// Validate or EndModification.
	/// @return												OK on success. If there is a cycle, an IllegalStateError is returned.
	//----------------------------------------------------------------------------------------
	Result<void> ValidateTopology() const
	{
		iferr_scope;
		CheckState(_system);
		return _system->ValidateTopology();
	}

	//----------------------------------------------------------------------------------------
	/// Validates the ports of the node system after a sequence of modifications. You should
	/// invoke this function whenever you have applied several modifications to the node system
	/// which affect @ref usernodes_derivation "derived ports" and want them to
	/// be up-to-date. For example a new connection between two ports #a, #b might induce derived nested
	/// ports at #b if #a has nested ports.
	///
	/// ValidatePorts() does the following steps:
	/// 1. The topology of the node system is checked (see ValidateTopology). If cycles are detected, an IllegalStateError is returned.
	/// 2. Nested ports are derived:
	///    1. Nested ports are derived from sources to targets of connections.
	///    2. After this has been done for the complete node system, nested ports are derived
	///       from targets to sources of connections.
	///
	/// @see @$ref usernodes_modifications
	/// @see @$ref usernodes_derivation
	/// @see Validate() which validates ports and derived attributes.
	/// @param[in] list								An optional ChangeList to track the changes.
	//----------------------------------------------------------------------------------------
	Result<void> ValidatePorts(Opt<ChangeList&> list = {}) const
	{
		iferr_scope;
		CheckState(_system);
		return _system->ValidatePorts(list);
	}

	//----------------------------------------------------------------------------------------
	/// Completely validates the node system after a sequence of modifications. This includes
	/// the validation which happens as part of ValidatePorts(), but afterwards
	/// @ref usernodes_attributes_derived are validated, too. So you should invoke this function
	/// whenever you have applied several modifications to the node system
	/// which affect derived attributes and want the values of derived attributes to be up-to-date.
	/// @see @$ref usernodes_modifications
	/// @see @$ref usernodes_derivation
	/// @param[in] list								An optional ChangeList to track the changes.
	//----------------------------------------------------------------------------------------
	Result<void> Validate(Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Ends a sequence of modifications of this MutableRoot. You have to call this at the end
	/// of a sequence of modifications which has been started with NodeSystem::BeginModification,
	/// see there for an example. This MutableRoot reference is cleared by this function.
	///
	/// This function executes several steps:
	/// 1. The node system is @ref Validate "validated".
	/// 2. The node system is @ref NodeSystemClass::FinalizeModification "finalized" according to the given flags.
	/// 3. The (exclusive) strong reference to the node system is moved from this MutableRoot to the returned NodeSystem.
	///
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @param[in] finalize						The flags to pass to NodeSystemClass::FinalizeModification.
	/// @return												Strong reference to the node system, this is moved from the MutableRoot to the return value.
	//----------------------------------------------------------------------------------------
	Result<NodeSystem> EndModification(Opt<ChangeList&> list = {}, NodeSystemClass::FINALIZE_FLAGS finalize = NodeSystemClass::FINALIZE_FLAGS::CLEANUP);

	//----------------------------------------------------------------------------------------
	/// Sets template and arguments for the current node system if it is an instantiation of a NodeTemplate.
	/// This method has to be called within NodeTemplate::Instantiate to have a back reference
	/// to the arguments of the instantiation.
	/// @param[in] trace							The instantiation trace.
	/// @param[in] templ							The NodeTemplate which instantiated the current node system.
	/// @param[in] args								The template arguments used for the instantiation.
	//----------------------------------------------------------------------------------------
	Result<void> SetTemplate(const InstantiationTrace& trace, const NodeTemplate& templ, const TemplateArguments& args) const;

	//----------------------------------------------------------------------------------------
	/// Sets the derivation handler for the current node system. Only NodeTemplates are allowed
	/// to change the derivation handler within their InstantiateImpl method, and they have to
	/// do so immediately after the creation of the new node system.
	/// @param[in] handler						The derivation handler to use for the current node system.
	//----------------------------------------------------------------------------------------
	Result<void> SetDerivationHandler(const NodeSystemDerivationHandler& handler) const;

	//----------------------------------------------------------------------------------------
	/// Applies the given change list to this node system. For an undo set inverse to true, for a
	/// redo or if you want to apply the change list to a different graph use false.
	/// @param[in] toApply						Change list to apply.
	/// @param[in] inverse						Use true if the inverse of the change list shall be applied (for an undo), false otherwise.
	/// @param[in] track							An optional ChangeList to track the changes.
	/// @return												A new change list which contains those changes of toApply which couldn't be applied,
	///																for example the change of an attribute value at a node which doesn't exist in the node system.
	//----------------------------------------------------------------------------------------
	Result<ChangeList> Apply(const ChangeList& toApply, Bool inverse, Opt<ChangeList&> track = {}) const
	{
		iferr_scope;
		CheckState(_system);
		return _system->Apply(toApply, inverse, track);
	}

	static const MutableRoot& NullValue()
	{
		return GetZeroRef<MutableRoot>();
	}

	//----------------------------------------------------------------------------------------
	/// Upcasts this MutableRoot to a MutableNode.
	/// @return												This MutableRoot as a MutableNode.
	//----------------------------------------------------------------------------------------
	const MutableNode& ToNode() const
	{
		return *this;
	}

	/// @copydoc DefaultDoc::ToString
	const String& ToString(const FormatStatement* fs = nullptr) const
	{
		return "Root"_s;
	}

	using MutableNode::ResultFunctions;
	using MutableNode::MUTABLE;
	using MutableNode::GetNodeSystem;
	using MutableNode::operator Bool;
	using MutableNode::IsEmpty;
	using MutableNode::IsPopulated;

	using MutableNode::GetInputs;
	using MutableNode::GetOutputs;
	using MutableNode::GetPortList;
	using MutableNode::FindInnerNode;
	using MutableNode::FindChild;
	using MutableNode::InheritChild;
	using MutableNode::GetInnerNodes;
	using MutableNode::GetChildren;

	using MutableNode::GetValues;
	using MutableNode::GetValue;
	using MutableNode::SetValue;
	using MutableNode::ChangeValue;
	using MutableNode::InheritValue;
	using MutableNode::RemoveValue;

	//----------------------------------------------------------------------------------------
	/// Checks if this MutableRoot is the same object as #other. Note that a MutableRoot has to
	/// be the exclusive owner of its NodeSystem, so two different MutableRoots will
	/// always point to different node systems.
	/// @param[in] other							Another MutableRoot.
	/// @return												True if this is the same as #other, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const MutableRoot& other) const
	{
		DebugAssert((this == &other) == (_system == other._system));
		return this == &other;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this MutableRoot is a different object as #other.
	/// @param[in] other							Another MutableRoot.
	/// @return												True if this and other are different MutableRoots, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const MutableRoot& other) const
	{
		return !this->operator ==(other);
	}

	using MutableNode::GetHashCode;

private:
	explicit MutableRoot(NodeSystem&& system) : MutableNode(const_cast<NodeSystemInterface*>(system.GetPointer()), system.GetPointer()->PrivateGetRoot())
	{
		DebugAssert(System::GetReferenceCounter(system.GetPointer()) == 1);
		reinterpret_cast<void*&>(system) = nullptr;
	}

	friend class NodeSystemImpl;
	friend class NodeSystemInterface;
};

MAXON_DATATYPE(MutableRoot, "net.maxon.node.datatype.mutableroot");


//----------------------------------------------------------------------------------------
/// This class template contains the functions of PortList which shall also be available on Result<PortList> (and likewise for MutablePortList).
//----------------------------------------------------------------------------------------
template <typename BASE> class PortListFunctions : public maxon::nodes::details::NodeFunctionsSuper<BASE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the direction of this port or port list (either PORT_DIR::INPUT or PORT_DIR::OUTPUT).
	/// @return												Direction of this port or port list.
	//----------------------------------------------------------------------------------------
	PORT_DIR GetPortDirection() const
	{
		static_assert(!BASE::HAS_ERROR, "Function not supported on Result<GNode>.");
		return maxon::GetPortDirection(this->GetHandle().GetKind());
	}

	//----------------------------------------------------------------------------------------
	/// Checks whether this reference addresses a port or a port list. PortList is a base
	/// class of Port, so a PortList reference may actually refer to a port.
	/// @return												True if this reference points to a port, false if it points to a port list.
	//----------------------------------------------------------------------------------------
	Bool IsPort() const
	{
		static_assert(!BASE::HAS_ERROR, "Function not supported on Result<GNode>.");
		return Bool(this->GetHandle().GetKind() & NODE_KIND::PORT_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Downcasts this reference to a port reference. This function may only be invoked if this
	/// reference really points to a port and not just to a port list (see IsPort()), otherwise
	/// the behaviour is undefined.
	/// @return												This reference, cast to a port reference.
	//----------------------------------------------------------------------------------------
	const PortSelector<BASE::MUTABLE>& ToPort() const
	{
		static_assert(!BASE::HAS_ERROR, "Function not supported on Result<GNode>.");
		DebugAssert(IsPort());
		return *reinterpret_cast<const PortSelector<BASE::MUTABLE>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the enclosing (true) node to which this port list or port belongs.
	/// @return												The enclosing node of this port list or port.
	//----------------------------------------------------------------------------------------
	Result<NodeSelector<BASE::MUTABLE>> GetNode() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		GNodeHandle n = this->GetHandle();
		while (true)
		{
			CheckAssert(!n.GetPath().IsEmpty());
			n = this->GetNodeSystem().GetPointer()->GetParent(n) iferr_return;
			if (n.GetKind() == NODE_KIND::NODE)
				return NodeSelector<BASE::MUTABLE>(this->GetNodeSystem(), n);
		}
	}

	/// @copydoc GNodeIterator
	using Iterator = GNodeIterator<PortSelector<BASE::MUTABLE>>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator over the ports of this port list. This does only include direct
	/// children, but not nested ports.
	/// @code
	///	for (auto p : portlist.GetPorts())
	///	{
	///		Port port = p iferr_return;
	///		...
	///	}
	/// @endcode
	/// @see @$ref usernodes_nodes
	/// @return												Iterator over the ports of this port list.
	//----------------------------------------------------------------------------------------
	Result<Iterator> GetPorts() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		Result<Iterator> res;
		std::move(res.GetValue()).Init(this->GetNodeSystem(), this->GetHandle()) % res.GetErrorStorage();
		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the single port of this port list. If this port list does not have exactly one
	/// port, an error is returned.
	/// @return												Single port of this port list.
	//----------------------------------------------------------------------------------------
	Result<PortSelector<BASE::MUTABLE>> GetSinglePort() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), InternedId(), NODE_KIND::PORT_MASK));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the port with the given identifier. Returns a null reference if no such port exists.
	/// @param[in] port								The identifier to search for.
	/// @return												Reference to the found port, or a null reference when there is no matching port.
	//----------------------------------------------------------------------------------------
	Result<PortSelector<BASE::MUTABLE>> FindPort(const InternedId& port) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), port, NODE_KIND::PORT_MASK));
	}

	/// @copydoc FindPort
	Result<PortSelector<BASE::MUTABLE>> FindPort(const Id& port) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		InternedId iid;
		iid.Init(port) iferr_return;
		return maxon::nodes::details::ConstructGNodeResult<PortSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->FindChild(this->GetHandle(), iid, NODE_KIND::PORT_MASK));
	}

	/// @private
	template <Bool MUT> using Selector = PortListSelector<MUT>;

	/// @private
	static const NODE_KIND KIND_MASK = NODE_KIND::PORTLIST_MASK;

	PRIVATE_MAXON_NODEFN_MEMBERS(PortListFunctions, maxon::nodes::details::NodeFunctionsSuper<BASE>);

	/// @copydoc GNode::InitFromPath
	Result<void> InitFromPath(typename maxon::nodes::details::NodeFunctionsSuper<BASE>::NodeSystemCtorParam system, const NodePath& path, NODE_KIND check = NODE_KIND::PORTLIST_MASK | NODE_KIND::PORT_MASK)
	{
		return Super::InitFromPath(system, path, check);
	}
};


//----------------------------------------------------------------------------------------
/// PortList represents a port list within a NodeSystem. Each Node has exactly two port lists,
/// one for its top-level input ports and one for its top-level output ports.
/// Also each Port may have nested ports, therefore Port has PortList as base class.
///
/// PortList allows for read-only access to the port list of the NodeSystem. If you want to make
/// modifications, you have to use MutablePortList instead.
//----------------------------------------------------------------------------------------
class PortList : public PortListFunctions<GNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(PortList, PortListFunctions<GNodeBase>);
};


//----------------------------------------------------------------------------------------
/// This class template contains the functions of MutablePortList which shall also be available on Result<MutablePortList>.
//----------------------------------------------------------------------------------------
template <typename BASE> class MutablePortListFunctions : public PortListFunctions<BASE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Adds a new port to this port list or port. The port will have #portId as its identifier.
	/// @param[in] portId							The identifier for the new port. An error is returned if the identifier is empty, or if there already exists a port for the identifier.
	/// @return												A reference to the added port.
	//----------------------------------------------------------------------------------------
	Result<MutablePort> AddPort(const Id& portId, GNODE_FLAGS flags = GNODE_FLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Adds a new port to this port list or port. The port will have #portId as its identifier.
	/// @param[in] portId							The identifier for the new port. An error is returned if the identifier is empty, or if there already exists a port for the identifier.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												A reference to the added port.
	//----------------------------------------------------------------------------------------
	Result<MutablePort> AddPort(const Id& portId, Opt<ChangeList&> list) const;

	//----------------------------------------------------------------------------------------
	/// Adds a new port to this port list or port. The port uses identifier and type from ATTR.
	/// @tparam ATTR									An attribute declared by MAXON_ATTRIBUTE.
	/// @return												A reference to the added port.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<typename SFINAEHelper<MutablePort, ATTR>::type> AddPort() const
	{
		iferr_scope;
		auto port = AddPort(ATTR::GetInstance()) iferr_return;
		if (!std::is_void<typename ATTR::ValueType>::value)
		{
			port.template SetType<typename ATTR::ValueType>() iferr_return;
		}
		return std::move(port);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new port to this port list or port if it doesn't exist already. otherwise returns the existing port.
	/// The port will have #portId as its identifier.
	/// @param[in] portId							The identifier for the port. An error is returned if the identifier is empty.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												A reference to the found or added port.
	//----------------------------------------------------------------------------------------
	Result<MutablePort> FindOrAddPort(const Id& portId, Opt<ChangeList&> list = {}) const;

	PRIVATE_MAXON_NODEFN_MEMBERS(MutablePortListFunctions, PortListFunctions<BASE>);
};


//----------------------------------------------------------------------------------------
/// MutablePortList represents a PortList within a NodeSystem with write access.
/// @see @$ref usernodes_modifications
//----------------------------------------------------------------------------------------
class MutablePortList : public MutablePortListFunctions<MutableGNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(MutablePortList, MutablePortListFunctions<MutableGNodeBase>);

	//----------------------------------------------------------------------------------------
	/// Casts this MutablePortList to an immutable PortList. If you call this function during
	/// an active modification you have to make sure that the returned PortList (and all further
	/// immutable references which are obtained through this PortList) is only stored temporarily
	/// and goes out of scope before the next modification is made,
	/// see @ref usernodes_modifications.
	///	@return												This port list as a PortList.
	//----------------------------------------------------------------------------------------
	const PortList& ToImmutable() const
	{
		// Final validation when converting to an immutable reference.
		// Otherwise there would be a race condition for concurrent validations (concurrency can only happen for immutable references in correct code).
		if (this->GetNodeSystem())
			this->GetNodeSystem().GetPointer()->PrivateValidate(_node);
		return *static_cast<const PortList*>(static_cast<const GNodeBase*>(this));
	}
};



template <typename BASE> using PortFunctionsSuper = typename std::conditional<BASE::HAS_ERROR, typename std::conditional<BASE::MUTABLE, MutablePortListFunctions<BASE>, PortListFunctions<BASE>>::type, PortListSelector<BASE::MUTABLE>>::type;

//----------------------------------------------------------------------------------------
/// This class template contains the functions of Port which shall also be available on Result<Port> (and also for MutablePort).
//----------------------------------------------------------------------------------------
template <typename BASE> class PortFunctions : public PortFunctionsSuper<BASE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the parent node of this port. The parent node of a top-level port is a port list,
	/// the parent node of a nested port is a port, too. Therefore this function's return type is PortList
	/// which is a base class of Port.
	/// @return												Reference to parent port list or port.
	//----------------------------------------------------------------------------------------
	Result<PortListSelector<BASE::MUTABLE>> GetParent() const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return maxon::nodes::details::ConstructGNodeResult<PortListSelector<BASE::MUTABLE>>(this->GetNodeSystem(), this->GetNodeSystem().GetPointer()->GetParent(this->GetHandle()));
	}

	//----------------------------------------------------------------------------------------
	/// Yields all connections of this port for the given direction. This includes not only
	/// connections which have been added at the level of the node system of this reference,
	/// but also inherited connections from base node systems and @ref usernodes_wires_implicit "implicit connections"
	/// from enclosing ports. It does not include connections which have
	/// been marked as removed (see WIRE_MODE::REMOVE).
	/// @param[in] dir								Whether to yield incoming or outgoing connections.
	/// @param[out] conns							The receiver for the found connections.
	/// @param[in] mask								Only yield connections whose wires match this mask.
	/// @param[in] mode								Mode for GetConnections.
	/// @return												false if #conns cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetConnections(PORT_DIR dir, const ValueReceiver<const ConnectionSelector<BASE::MUTABLE>&>& conns, Wires mask = Wires::All(), NodeSystemInterface::GET_CONNECTIONS_MODE mode = NodeSystemInterface::GET_CONNECTIONS_MODE::CONNECTIONS) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return const_cast<NodeSystemInterface*>(this->GetNodeSystem().GetPointer())->GetConnections(this->GetHandle(), dir, reinterpret_cast<const ValueReceiver<const MutableConnection&>&>(conns), mask, mode);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the Wires which are present between this port (source) and target.
	/// Like GetConnections this includes connections which are inherited from a base node system
	/// and @ref usernodes_wires_implicit "implicit connections" from enclosing ports.
	/// It does not include connections which have been marked as removed (see WIRE_MODE::REMOVE).
	/// @param[in] target							The target port.
	/// @return												The complete set of Wires from this port to target.
	//----------------------------------------------------------------------------------------
	Result<Wires> GetWires(const PortSelector<BASE::MUTABLE>& target) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetWires(this->GetHandle(), target.GetHandle());
	}

	//----------------------------------------------------------------------------------------
	/// Gets all attribute values of the connection from this port to target.
	/// @param[in] target							The other end of the connection.
	/// @param[out] receiver					All attribute values of the connection will be reported to the receiver.
	/// @return												false if #receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	Result<Bool> GetConnectionValues(const PortSelector<BASE::MUTABLE>& target, const ValueReceiver<CONNECTION_POSITION, InternedId, const ConstDataPtr&>& receiver) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetConnectionValues(this->GetHandle(), target.GetHandle(), receiver);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// a null ConstDataPtr is returned.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @param[in] expectedType				The expected type of the attribute value, may be nullptr if no check shall be done.
	/// @return												The attribute value of the connection, or a null ConstDataPtr.
	//----------------------------------------------------------------------------------------
	Result<ConstDataPtr> GetConnectionValue(const PortSelector<BASE::MUTABLE>& target, CONNECTION_POSITION position, const InternedId& attr, const DataType& expectedType) const
	{
		PRIVATE_MAXON_NODEFN_PROLOGUE;
		return this->GetNodeSystem().GetPointer()->GetConnectionValue(this->GetHandle(), target.GetHandle(), position, attr, expectedType);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// an empty Opt is returned.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @param[in] attr								The attribute whose value shall be obtained.
	/// @return												The attribute value of the connection, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<Opt<const T&>> GetConnectionValue(const PortSelector<BASE::MUTABLE>& target, CONNECTION_POSITION position, const InternedId& attr) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetConnectionValue(target, position, attr, maxon::GetDataType<T>()) iferr_return;
		return Opt<const T&>(reinterpret_cast<const T*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Gets the value of the given attribute #ATTR for the connection from this port to target. If there is no such
	/// connection, the connection has no value for the attribute or the value doesn't have the expected type,
	/// an empty Opt is returned.
	/// @tparam ATTR									The attribute whose value shall be obtained.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be obtained.
	/// @return												The attribute value of the connection, may be an empty Opt.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Opt<const typename ATTR::ValueType&>> GetConnectionValue(const PortSelector<BASE::MUTABLE>& target, CONNECTION_POSITION position) const
	{
		iferr_scope;
		ConstDataPtr ptr = GetConnectionValue(target, position, ATTR::GetInstance(), maxon::GetDataType<typename ATTR::ValueType>()) iferr_return;
		return Opt<const typename ATTR::ValueType&>(reinterpret_cast<const typename ATTR::ValueType*>(ptr.PrivateGetPtr()));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the modification stamp of incoming/outgoing connections for this port. This is the value of
	/// the graph's time stamp (see GraphModelInterface::GetModificationStamp) at the time when
	/// connections in the given direction have been modified last for this port.
	/// @param[in] direction					The connection direction.
	/// @return												The modification stamp of the last connection change of the port.
	//----------------------------------------------------------------------------------------
	TimeStamp GetConnectionStamp(PORT_DIR direction) const
	{
		static_assert(!BASE::HAS_ERROR, "Can't invoke GetConnectionStamp on a Result.");
		const NodeSystemInterface* sys = this->GetNodeSystem();
		return sys ? sys->GetConnectionStamp(this->GetHandle(), direction) : TimeStamp();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this port is a port of the root node of a node system.
	/// This includes not only top-level ports, but also nested ports.
	/// @return												True if this port is a port of the root node, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPortOfRoot() const
	{
		return this->GetPath().IsPortOfRoot();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this port is a @ref Port "top-level port". A top-level port is a port
	/// which is not nested within another port, but a direct child of the input or output port list of a node.
	/// @return												True if this port is a top-level port, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsTopLevelPort() const
	{
		return this->GetPath().IsTopLevelPort();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an Int value which corresponds to the index of this port in the topological ordering
	/// of its node system. The connections within a node system build a directed acyclic graph,
	/// and the node system sets up a corresponding topological ordering of all ports within MutableRoot::ValidateTopology().
	/// For this step only top-level ports are considered, connections between nested ports are treated as if
	/// they were between their enclosing top-level ports. Therefore the index of a nested
	/// port is the same as the index of its enclosing port.
	/// @return												The index of this port (or its enclosing top-level port) in the topological ordering,
	///																or a negative number if this port reference doesn't point to a valid port.
	//----------------------------------------------------------------------------------------
	Int GetTopologicalOrder() const
	{
		DebugAssert(IsTopLevelPort());
		return this->GetNodeSystem() ? this->GetNodeSystem().GetPointer()->GetTopologicalOrder(this->GetHandle().GetPath()) : LIMIT<Int>::MIN;
	}

	/// @private
	template <Bool MUT> using Selector = PortSelector<MUT>;

	/// @private
	static const NODE_KIND KIND = NODE_KIND::PORT_MASK;

	PRIVATE_MAXON_NODEFN_MEMBERS(PortFunctions, PortFunctionsSuper<BASE>);

	/// @copydoc GNode::InitFromPath
	Result<void> InitFromPath(typename PortFunctionsSuper<BASE>::NodeSystemCtorParam system, const NodePath& path, NODE_KIND check = NODE_KIND::PORT_MASK)
	{
		return Super::InitFromPath(system, path, check);
	}
};


//----------------------------------------------------------------------------------------
/// Port represents a port within a NodeSystem. Each port belongs to a port list:
/// - The port may be a direct child of the list of input or output ports of a node.
///   Then the port is a /top-level/ port.
/// - Otherwise the port is a /nested/ port, contained within another port.
///
/// Example: In the following node system a, c, e, f are top-level ports
/// and b, d are nested ports.
/// @graph
/// +---------------------------+
/// |       +-----------+       |
/// o a --> o c         |       |
///  o b     o d ---> e o --> f o
/// |       +-----------+       |
/// +---------------------------+
/// @endgraph
/// Port allows for read-only access to the port of the NodeSystem. If you want to make
/// modifications, you have to use MutablePort instead.
//----------------------------------------------------------------------------------------
class Port : public PortFunctions<GNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(Port, PortFunctions<GNodeBase>);
};


//----------------------------------------------------------------------------------------
/// This class template contains the functions of MutablePortList which shall also be available on Result<MutablePortList>.
//----------------------------------------------------------------------------------------
template <typename BASE> class MutablePortFunctions : public PortFunctions<BASE>
{
public:
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
	/// It is not allowed to create a cycle in the graph. However the Connect function
	/// itself doesn't check this, it is done later during e.g. MutableRoot::Validate
	/// or MutableRoot::EndModification. Therefore it is possible to temporarily introduce
	/// a cycle and resolve this immediately afterwards by removing another connection.
	///
	/// @param[in] target							The target port to connect to. Result<MutablePort> is accepted and the error, if any, is forwarded.
	/// @param[in] modes							The Wires to use for the connection.
	/// @param[in] list								An optional ChangeList to track the changes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Connect(Result<MutablePort>&& target, Wires modes = WIRE_MODE::NORMAL, Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Sets the value of the DefaultValue attribute to #value for this port.
	/// This will override any values which would otherwise be inherited from a base port.
	/// @param[in] value							The value for the DefaultValue attribute.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetDefaultValue(T&& value) const
	{
		iferr_scope;
		Data d;
		d.Set(std::forward<T>(value)) iferr_return;
		return PortFunctions<BASE>::template SetValue<decltype(DESCRIPTION::DATA::BASE::DEFAULTVALUE)>(std::move(d));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the given #dataType as the value of the FixedPortType attribute.
	/// @param[in] dataType						The data type for this port.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetType(const DataType& dataType) const
	{
		return PortFunctions<BASE>::template SetValue<decltype(FixedPortType)>(dataType);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the type T as the value of the FixedPortType attribute.
	/// @tparam T											The data type for this port.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetType() const
	{
		return SetType(maxon::GetDataType<T, GET_DATATYPE_POLICY::NO_DECAY>());
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #attr to #value for the connection from this port to #target. This will override any previously existing value.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] attr								The attribute whose value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	Result<Bool> SetConnectionValue(const MutablePort& target, CONNECTION_POSITION position, const InternedId& attr, ForwardingDataPtr&& value, Opt<ChangeList&> list = {}) const;

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetConnectionValue(const MutablePort& target, CONNECTION_POSITION position, const typename ATTR::ValueType& value, Opt<ChangeList&> list = {}) const
	{
		return SetConnectionValue(target, position, ATTR::GetInstance(), ConstDataPtr(value), list);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of #ATTR to #value for this node. This will override any previously existing value.
	/// @tparam ATTR									The attribute whose value shall be set.
	/// @param[in] target							The other end of the connection.
	/// @param[in] position						The connection position at which the attribute's value shall be set.
	/// @param[in] value							The value for the attribute.
	/// @return												True if the value has been changed.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> Result<Bool> SetConnectionValue(const MutablePort& target, CONNECTION_POSITION position, typename ATTR::ValueType&& value, Opt<ChangeList&> list = {}) const
	{
		return SetConnectionValue(target, position, ATTR::GetInstance(), MoveDataPtr(std::move(value)), list);
	}

	PRIVATE_MAXON_NODEFN_MEMBERS(MutablePortFunctions, PortFunctions<BASE>);
};


//----------------------------------------------------------------------------------------
/// MutablePort represents a Port within a NodeSystem with write access.
/// @see @$ref usernodes_modifications
//----------------------------------------------------------------------------------------
class MutablePort : public MutablePortFunctions<MutableGNodeBase>
{
public:
	PRIVATE_MAXON_NODE_MEMBERS(MutablePort, MutablePortFunctions<MutableGNodeBase>);

	//----------------------------------------------------------------------------------------
	/// Casts this MutablePort to an immutable Port. If you call this function during
	/// an active modification you have to make sure that the returned Port (and all further
	/// immutable references which are obtained through this Port) is only stored temporarily
	/// and goes out of scope before the next modification is made,
	/// see @ref usernodes_modifications.
	///	@return												This port list as a Port.
	//----------------------------------------------------------------------------------------
	const Port& ToImmutable() const
	{
		// Final validation when converting to an immutable reference.
		// Otherwise there would be a race condition for concurrent validations (concurrency can only happen for immutable references in correct code).
		if (this->GetNodeSystem())
			this->GetNodeSystem().GetPointer()->PrivateValidate(_node);
		return *static_cast<const Port*>(static_cast<const GNodeBase*>(this));
	}
};


//----------------------------------------------------------------------------------------
/// The base implementation class of NodeSystemClass. You have to use this class as
/// base class whenever you implement NodeSystemClassInterface. It implements all methods.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, DefaultNodeSystemClass, "net.maxon.node.nodesystemclass");


//----------------------------------------------------------------------------------------
/// The base implementation class of NodeSystemDerivationHandler. You can use this class as
/// base class whenever you implement a derivation handler.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeSystemDerivationHandler>, NodeSystemDerivationHandlerBaseClass, "net.maxon.node.class.nodesystemderivationhandlerbase");


//----------------------------------------------------------------------------------------
/// A base implementation class of NodeTemplate. You can use this class as
/// base class whenever you implement NodeTemplateInterface. It provides default
/// implementations for all methods except NodeTemplateInterface::Instantiate.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeTemplate>, NodeTemplateBaseClass, "net.maxon.node.class.nodetemplatebase");


//----------------------------------------------------------------------------------------
/// A base implementation class for a decorator of NodeTemplate. You can use this class as
/// base class whenever you implement such a decorator. The class forwards calls
/// of all methods of NodeTemplateInterface to the decorated object.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeTemplate>, NodeTemplateDecoratorBaseClass, "net.maxon.node.class.nodetemplatedecoratorbase");



//----------------------------------------------------------------------------------------
/// This registry contains all built-in nodes (those are defined by code or by resource descriptions).
/// They are also accessible via the built-in asset repository, however the built-in
/// repository returns a decorated version which has resource descriptions applied on top.
/// The macro MAXON_DECLARATION_REGISTER_BUILTINNODE helps to register a built-in node.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(NodeTemplate, BuiltinNodes, "net.maxon.node.registry.builtinnodes");

//----------------------------------------------------------------------------------------
/// Registers a built-in node at the BuiltinNodes registry. After the macro you have to add
/// a code block which returns the NodeTemplate to register. The code block will be executed
/// lazily as it will be wrapped by NodesLib::CreateLazyTemplate.
/// @param[in] id									The identifier to use.
/// @param[in] ...								This optional argument is passed as second argument to NodesLib::CreateLazyTemplate.
///																It allows to control for which node system classes the node shall be supported.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_REGISTER_BUILTINNODE(id, ...) MAXON_EXPAND(PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE(id, true, __COUNTER__, ##__VA_ARGS__))

//----------------------------------------------------------------------------------------
/// Registers a built-in node at the BuiltinNodes registry. Node enabled state will be tied to the #enable parameter.
/// One can link node to a MAXON_FEATURE_CONFIGURATION_BRANCHES value.
/// After the macro you have to add a code block which returns the NodeTemplate to register.
/// The code block will be executed lazily as it will be wrapped by NodesLib::CreateLazyTemplate.
/// Note that using an enable check in the supplied code block will make the node not instantiate but it would still
/// be registered and visible in node list.
/// @param[in] id									The identifier to use.
/// @param[in] enable							Configuration flag to control if node is to be registered or not.
/// @param[in] ...								This optional argument is passed as second argument to NodesLib::CreateLazyTemplate.
///																It allows to control for which node system classes the node shall be supported.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_REGISTER_FEATURE_BUILTINNODE(id, enable, ...) MAXON_EXPAND(PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE(id, enable, __COUNTER__, ##__VA_ARGS__))

#define PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE(id, enable, CNT, ...) \
	static maxon::Result<maxon::nodes::NodeTemplate> MAXON_CONCAT(PrivateLazyNode, CNT)(); \
	MAXON_DECLARATION_REGISTER(maxon::nodes::BuiltinNodes, id) \
	{ \
		if (enable) \
			return maxon::nodes::NodesLib::CreateLazyTemplate(objectId, &MAXON_CONCAT(PrivateLazyNode, CNT), ##__VA_ARGS__); \
		return DisabledError(MAXON_SOURCE_LOCATION); \
	} \
	static maxon::Result<maxon::nodes::NodeTemplate> MAXON_CONCAT(PrivateLazyNode, CNT)()


//----------------------------------------------------------------------------------------
/// Registers a built-in node at the BuiltinNodes registry. Node enabled state will be tied to the #enable parameter.
/// One can link node to a MAXON_FEATURE_CONFIGURATION_BRANCHES value.
/// After the macro you have to add a code block for a function with the parameter list
/// (const InstantiationTrace& parent, const TemplateArguments& args) and return type Result<MutableRoot>,
/// this function will be used to implement the InstantiateImpl method of the registered node template
/// (via NodesLib::CreateTemplateFromDelegate).
/// Note that using an enable check in the supplied code block will make the node not instantiate but it would still
/// be registered and visible in node list.
/// @param[in] id									The identifier to use.
/// @param[in] enable							Configuration flag to control if node is to be registered or not.
/// @param[in] ...								This optional argument is passed as argument to NodesLib::CreateTemplateFromDelegate.
///																It allows to control for which node system classes the node shall be supported.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_REGISTER_FEATURE_BUILTINNODE_DELEGATE(id, enable, ...) MAXON_EXPAND(PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE_DELEGATE(id, enable, __COUNTER__, ##__VA_ARGS__))

#define PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE_DELEGATE(id, enable, CNT, ...) \
	static maxon::Result<maxon::nodes::MutableRoot> MAXON_CONCAT(PrivateDelegateNode, CNT)(const maxon::nodes::InstantiationTrace& parent, const maxon::nodes::TemplateArguments& args); \
	MAXON_DECLARATION_REGISTER(maxon::nodes::BuiltinNodes, id) \
	{ \
		if (enable) \
			return maxon::nodes::NodesLib::CreateTemplateFromDelegate(objectId, true, &MAXON_CONCAT(PrivateDelegateNode, CNT), ##__VA_ARGS__); \
		return DisabledError(MAXON_SOURCE_LOCATION); \
	} \
	static maxon::Result<maxon::nodes::MutableRoot> MAXON_CONCAT(PrivateDelegateNode, CNT)(const maxon::nodes::InstantiationTrace& parent, const maxon::nodes::TemplateArguments& args)


//----------------------------------------------------------------------------------------
/// This registry collects delegates which are called after descriptions have been applied
/// on top of nodes registered at BuiltinNodes. You have to register a delegate using
/// the exact id of the node whose description shall be finalized. For example to override
/// values of the first color of the checkerboard node (so that it differs from the second
/// which can't be defined in the resource description at the moment) the following code is used:
/// @code{nodes_descriptionfinalizer}
//! MAXON_DECLARATION_REGISTER(nodes::DescriptionFinalizers, PATTERN::NODE::GENERATOR::GRADIENT::GetId())
//! {
//! 	return nodes::DescriptionFinalizers::EntryType([] (const nodes::MutableRoot& root)-> Result<void>
//! 	{
//! 		iferr_scope;
//! 		nodes::MutablePort knot0 = root.GetInputs().FindPort(PATTERN::NODE::GENERATOR::GRADIENT::GRADIENT).FindPort(Id("_0")) iferr_return;
//! 		if (knot0)
//! 		{
//! 			knot0.FindPort(RENDER::PORTBUNDLE::GRADIENT::COLOR).SetDefaultValue(ColorA()) iferr_return;
//! 			knot0.FindPort(RENDER::PORTBUNDLE::GRADIENT::POSITION).SetDefaultValue(Float(0.0)) iferr_return;
//! 		}
//! 		return OK;
//! 	});
//! }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Delegate<Result<void>(const MutableRoot&)>, DescriptionFinalizers, "net.maxon.node.registry.descriptionfinalizers");

}

#include "nodes2.hxx"

namespace nodes
{

inline Node NodeSystemInterface::GetRoot() const { return Node(this, PrivateGetRoot()); }

inline Bool NodeSystemClassInterface::IsSubclassOf(const NodeSystemClass& other) const { return GetClass().IsSubclassOf(other.GetClass()); }

template <typename S> inline Result<MutableRoot> NodeSystemInterface::Hxx1::COWReferenceFunctionsImpl<S>::BeginSubstitutionModification(const NodeSystem& original)
{
	if (MAXON_UNLIKELY(!original))
		return PrivateGetNullReturnError(NULL_RETURN_REASON::NULLPTR);
	return BeginSubstitutionModification(original.GetPointer()->GetLookupRepository(), original.GetPointer()->GetTemplate(), original.GetPointer()->GetArguments());
}

}

} // namespace maxon

#endif // NODES_H__
