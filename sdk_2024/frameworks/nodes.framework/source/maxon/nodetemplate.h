#ifndef NODETEMPLATE_H__
#define NODETEMPLATE_H__

#include "maxon/forwardref.h"
#include "maxon/nodesystem_data.h"

namespace maxon
{

namespace AssetTypes
{
	//----------------------------------------------------------------------------------------
	/// This is the asset type for NodeTemplate.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(AssetType, NodeTemplate, "net.maxon.node.assettype.nodetemplate");
};

namespace nodes
{

class NodeSystemClass MAXON_FORWARD("maxon/nodesystem_class.h");


//----------------------------------------------------------------------------------------
/// The TemplateArguments class implements a dictionary which stores template arguments
/// for instantiations of NodeTemplates. It implements a two-level dictionary:
///	- The first level stores /default arguments/.
///		This level is set by user code when a node template instantiation is initially added to a node system.
///		The default arguments are never changed implicitly.
///	- The second level stores /deduced/ or /explicit/ values, these have higher priority than default arguments.
///		Deduced values get implicitly set during node system validation:
///		Whenever a template parameter is available as a port and a EffectivePortValue
///		can be deduced for that port, that value is used as argument for the template parameter
///		by making a corresponding override in the TemplateArguments.
///
/// Template arguments are usually identified by their relative port path within the node template
/// and the kind of template argument. For a given port there may be several arguments if the
/// port represents several template parameters (for example a TypeTemplateParameter as well as a TemplateParameter).
//----------------------------------------------------------------------------------------
class TemplateArguments
{
public:
	//----------------------------------------------------------------------------------------
	/// This enum lists the different kinds of template arguments. Exactly one of VALUE, TYPE, BUNDLE
	/// has to be set.
	//----------------------------------------------------------------------------------------
	enum class KIND : UChar
	{
		NONE = 0,				///< No flag set.
		
		// FLAGS
		DEDUCED = 1,		///< This flag can be used in combination with the other flags if the value has been deduced from the node graph.
		EXPLICIT = 16,	///< This flag can be used in combination with the other flags if the value has been explicitly set.
		
		// KIND TYPES
		VALUE = 2,			///< The template argument is for a port which is marked as TemplateParameter.
		TYPE = 4,				///< The template argument is for a port which is marked as TypeTemplateParameter.
		BUNDLE = 8,			///< The template argument is for a port which is marked as BundleTemplateParameter.

		// MASKS
		MASK = 14,			///< Anything but DEDUCED or EXPLICIT.
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	using KeyType = Tuple<NodePath, KIND>;										/// {NodePath to port with template argument, argument kind}.

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
	/// @return												OK on success.
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
	/// @return												OK on success.
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
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetDefaultRemoveDeduced(const NodePath& path, KIND kind, T&& value)
	{
		iferr_scope;
		_args.EraseData(ConstDataPtr(ToTuple(path, kind | KIND::DEDUCED))) iferr_return;
		_args.SetData(ConstDataPtr(ToTuple(path, kind)), ForwardingDataPtr(std::forward<T>(value))) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Sets a template parameter with no KIND value. This can be useful when passing TemplateArguments to lower level node implementation.
	/// @param[in] id									The identifier of the template parameter (use as key to read this parameter).
	/// @param[in] value							The value for the template parameter.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> SetNoKindArgument(const InternedId& id, T&& value)
	{
		return _args.SetData(ConstDataPtr(id), ForwardingDataPtr(std::forward<T>(value)));
	}

	//----------------------------------------------------------------------------------------
	/// Removes any value (default or overridden) for the template parameter path.
	/// If there is no such value, nothing happens.
	/// #kind should not contain any of KIND::MASK or it will not be able to remove all
	/// arguments of the given kind (KIND::VALUE, KIND::TYPE or KIND::BUNDLE).
	/// @param[in] path								The path of the template parameter.
	/// @param[in] kind								The kind of the template parameter.
	//----------------------------------------------------------------------------------------
	Result<void> Remove(const NodePath& path, KIND kind)
	{
		iferr_scope;
		DebugAssert((kind & ~KIND::MASK) == KIND::NONE);
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
	/// @b{You must not override it.}
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
	/// @b{You must not override it.}
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
	/// @return												A new node system which is the instantiation of this template for the given arguments.
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
	/// @param[in] additionalContext	Supplementary instantiation context parameters.
	/// @return												A new node system which is the instantiation of this template for the given arguments.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<NodeSystem> Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const DataDictionary& additionalContext, const TemplateArguments& args = GetZeroRef<TemplateArguments>()) const;
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
	/// @param[in] repo								The repository to use for asset lookup.
	/// @return												The underlying node system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> GetNodeSystem(const NodeSystemClass& cls, const AssetRepositoryRef& repo) const;

	/// @MAXON_ANNOTATION{methodId="DeprecatedGetNodeSystemData@2f3e4e8fca5f2d60"->"GetNodeSystemData@2f3e4e8fca5f2d60"}
	MAXON_METHOD const NodeSystemData& DeprecatedGetNodeSystemData() const;

	//----------------------------------------------------------------------------------------
	/// Returns the node system data which is used for the template.
	/// @return												The underlying node system data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystemData> GetNodeSystemData() const;
};

//----------------------------------------------------------------------------------------
/// PRIVATE
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Url, InstantiateContextBasePath, "net.maxon.nodes.nodesystem.instantiatecontext.basepath");

//----------------------------------------------------------------------------------------
/// PRIVATE
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(AssetMetaData, InstantiateContextMeta, "net.maxon.node.nodesystem.instantiatecontext.metadata");

#include "nodetemplate1.hxx"


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
	InstantiationTrace(const InstantiationTrace& parent, const NodeTemplate& nt, const TemplateArguments& args, const void* extra) : _class(parent._class), _repository(parent._repository), _context(parent._context), _parent(&parent), _template(nt), _arguments(args), _extra(extra)
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
		return _class.Get();
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

	const DataDictionary& GetAdditionalContext() const
	{
		return _context;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the beginning of an instantiation trace.
	/// @param[in] cls								The node system class to use.
	/// @param[in] repo								The asset repository to use for lookup of assets.
	//----------------------------------------------------------------------------------------
	InstantiationTrace(const NodeSystemClass& cls, const AssetRepositoryRef& repo) : _class(reinterpret_cast<const ForwardRef<NodeSystemClass>&>(cls)), _repository(repo), _context()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the beginning of an instantiation trace.
	/// @param[in] cls								The node system class to use.
	/// @param[in] repo								The asset repository to use for lookup of assets.
	/// @param[in] additionalContext	Supplementary instantiation context parameters.
	//----------------------------------------------------------------------------------------
	InstantiationTrace(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const DataDictionary& additionalContext) : _class(reinterpret_cast<const ForwardRef<NodeSystemClass>&>(cls)), _repository(repo), _context(additionalContext)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new node system using the node system class and lookup repository of this InstantiationTrace.
	/// This is the same as @c{trace.GetNodeSystemClass().CreateNodeSystem(trace.GetLookupRepository())}.
	/// @return												The MutableRoot of a new empty compound node system.
	//----------------------------------------------------------------------------------------
	Result<MutableRoot> CreateNodeSystem() const;

	//----------------------------------------------------------------------------------------
	/// Creates an @ref usernodes_instancing "instance" of the given node system,
	/// see NodeSystem::CreateInstance().
	/// This is the same as @c{system.CreateInstance(trace.GetLookupRepository())}.
	///
	/// Whenever the node system needs to do an asset lookup during the following modifications,
	/// the lookup repository of this InstantiationTrace is used.
	///
	/// @param[in] system							The node system of which an instance shall be created.
	/// @return												A MutableRoot of a new node system which uses the given system as its base.
	//----------------------------------------------------------------------------------------
	Result<MutableRoot> CreateInstance(const NodeSystem& system) const;

private:
	Bool ContainsImpl(const NodeTemplate& t, const TemplateArguments* args, const void* extra) const;
	Bool ContainsImpl(const Id& t, const TemplateArguments* args, const void* extra) const;

	ForwardRef<NodeSystemClass> _class;
	AssetRepositoryRef _repository;
	DataDictionary _context;
	const InstantiationTrace* const _parent = nullptr;
	const NodeTemplate _template = {};
	const TemplateArguments _arguments = {};
	const void* const _extra = nullptr;

	friend class NodeTemplateInterface;
	friend class NodeSystemImpl;
};


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
/// This registry contains all built-in nodes (those which are defined by code or by resource descriptions).
/// They are also accessible via the built-in asset repository, however the built-in
/// repository returns a decorated version which has resource descriptions and meta data
/// from BuiltinNodesMetaData applied on top and also caches instantiations of the node template.
/// In general you should work with the decorated version, there's the convenience method
/// @c{NodesLib::LoadBuiltinTemplate} for that purpose.
///
/// The macro MAXON_DECLARATION_REGISTER_BUILTINNODE helps to register a built-in node.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(NodeTemplate, BuiltinNodes, "net.maxon.node.registry.builtinnodes");

//----------------------------------------------------------------------------------------
/// This registry contains meta data for built-in nodes when they are accessed via the
/// built-in asset repository.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(DataDictionary, BuiltinNodesMetaData, "net.maxon.node.registry.builtinnodesmetadata");


//----------------------------------------------------------------------------------------
/// This registry collects delegates which are called after descriptions have been applied
/// on top of nodes registered at BuiltinNodes. You have to register a delegate using
/// the exact id of the node whose description shall be finalized. For example to override
/// values of the first knot of the gradient node (so that it differs from the second knot,
/// per-knot-values can't be defined in the resource description at the moment) the following code is used:
/// @code{nodes_descriptionfinalizer}
//! MAXON_DECLARATION_REGISTER(nodes::DescriptionFinalizers, PATTERN::NODE::GENERATOR::GRADIENT::GetId())
//! {
//! 	return nodes::DescriptionFinalizers::EntryType([] (const nodes::MutableRoot& root)-> Result<void>
//! 	{
//! 		iferr_scope;
//! 		nodes::MutablePort knot0 = root.GetInputs().FindPort(PATTERN::NODE::GENERATOR::GRADIENT::GRADIENT).FindPort(Id("_0")) iferr_return;
//! 		if (knot0)
//! 		{
//! 			knot0.FindPort(RENDER::PORTBUNDLE::GRADIENT::COLOR).SetPortValue(ColorA()) iferr_return;
//! 			knot0.FindPort(RENDER::PORTBUNDLE::GRADIENT::POSITION).SetPortValue(Float(0.0)) iferr_return;
//! 		}
//! 		return OK;
//! 	});
//! }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Delegate<Result<void>(const MutableRoot&)>, DescriptionFinalizers, "net.maxon.node.registry.descriptionfinalizers");


#include "nodetemplate2.hxx"


}

} // namespace maxon

#endif // NODETEMPLATE_H__
