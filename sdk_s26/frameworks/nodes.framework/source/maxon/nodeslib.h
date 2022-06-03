#ifndef NODESLIB_H__
#define NODESLIB_H__

#include "maxon/nodetemplate.h"
#include "maxon/nodesystem_class.h"

namespace maxon
{

namespace nodes
{


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

	using InstantiateDelegateDeprecated = Delegate<Result<MutableRoot>(const InstantiationTrace& parent, const TemplateArguments& args)>;

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
	/// @MAXON_ANNOTATION{methodId="CreateTemplateFromDelegate@e2b16554ed011d8f"->"CreateTemplateFromDelegate@3bd5932a0d2404b8"}
	//----------------------------------------------------------------------------------------
	[[deprecated]] static MAXON_METHOD Result<NodeTemplate> CreateTemplateFromDelegate(const Id& nodeId, Bool cache, InstantiateDelegateDeprecated&& instantiate, Delegate<Result<Bool>(const NodeSystemClass& cls)>&& support = {});

	//----------------------------------------------------------------------------------------
	/// The Delegate type to use for CreateTemplateFromDelegate. This is used to implement NodeTemplateInterface::InstantiateImpl.
	/// @param[in] parent							The parent instantiation context, this defines the node system class to use
	///																as well as the asset repository for asset resolution.
	/// @param[in] args								Arguments to parametrize the instantiation.
	/// @param[in] self								The NodeTemplate created by CreateTemplateFromDelegate is passed here.
	/// @return												The MutableRoot of the node system to use for the instantiation.
	//----------------------------------------------------------------------------------------
	using InstantiateDelegate = Delegate<Result<MutableRoot>(const InstantiationTrace& parent, const TemplateArguments& args, const NodeTemplate& self)>;

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
	/// @MAXON_ANNOTATION{methodId="CreateTemplateFromDelegate@3bd5932a0d2404b8"->"CreateTemplateFromDelegate@5e5417c777a8f0c6"}
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
	// #LEGACYCOMPATIBILITY: add additional const TemplateArguments& parameter to finalizer

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

	static MAXON_METHOD Result<AssetDescription> StoreAsset(const AssetRepositoryRef& repository, const Id& assetId, const NodeSystemData& data);

	static MAXON_METHOD String PrivateGNodeToString(const GNodeBase& node, const FormatStatement* fs);

	[[deprecated]] static MAXON_METHOD Result<void> PrivateInitFromPath(GNode& node, const NodeSystem& system, const NodePath& path, NODE_KIND check);

	[[deprecated]] static MAXON_METHOD Result<void> PrivateInitFromPath(MutableGNode& node, NodeSystemInterface* system, const NodePath& path, NODE_KIND check);
};


#include "nodeslib1.hxx"

#include "nodeslib2.hxx"


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




#define PRIVATE_MAXON_DECLARATION_REGISTER_BUILTINNODE_DELEGATE(id, enable, CNT, ...) \
	static maxon::Result<maxon::nodes::MutableRoot> MAXON_CONCAT(PrivateDelegateNode, CNT)(const maxon::nodes::InstantiationTrace& parent, const maxon::nodes::TemplateArguments& args, const maxon::nodes::NodeTemplate& self); \
	MAXON_DECLARATION_REGISTER(maxon::nodes::BuiltinNodes, id) \
	{ \
		if (enable) \
			return maxon::nodes::NodesLib::CreateTemplateFromDelegate(objectId, true, &MAXON_CONCAT(PrivateDelegateNode, CNT), ##__VA_ARGS__); \
		return DisabledError(MAXON_SOURCE_LOCATION); \
	} \
	static maxon::Result<maxon::nodes::MutableRoot> MAXON_CONCAT(PrivateDelegateNode, CNT)(const maxon::nodes::InstantiationTrace& parent, const maxon::nodes::TemplateArguments& args, const maxon::nodes::NodeTemplate& self)


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


}

} // namespace maxon

#endif // NODESLIB_H__
