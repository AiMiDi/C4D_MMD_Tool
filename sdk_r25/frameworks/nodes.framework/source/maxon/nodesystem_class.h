#ifndef NODESYSTEM_CLASS_H__
#define NODESYSTEM_CLASS_H__

#include "maxon/nodesystem.h"

namespace maxon
{

namespace nodes
{

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
	/// Runs finalization steps at the end of a modification. This method must not be called directly,
	/// instead it is called implicitly during MutableRoot::EndModification(). When overriding
	/// the method make sure to call the super implementation.
	/// @param[in] stampOnBegin				The time stamp of the node system at the time BeginModification() was called.
	/// @param[in] finalize						Flags to control the finalization.
	/// @param[in] changelist					Change list to log changes made during finalization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinalizeModification(MutableRoot& root, TimeStamp stampOnBegin, NodeSystem::FINALIZE_FLAGS finalize, ChangeList* changelist) const;

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


#include "nodesystem_class1.hxx"


//----------------------------------------------------------------------------------------
/// The base implementation class of NodeSystemClass. You have to use this class as
/// base class whenever you implement NodeSystemClassInterface. It implements all methods.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, DefaultNodeSystemClass, "net.maxon.node.nodesystemclass");


#include "nodesystem_class2.hxx"

inline Bool NodeSystemClassInterface::IsSubclassOf(const NodeSystemClass& other) const { return GetClass().IsSubclassOf(other.GetClass()); }


}

} // namespace maxon

#endif // NODESYSTEM_CLASS_H__
