#ifndef NODEMATERIALEXCHANGE_H__
#define NODEMATERIALEXCHANGE_H__

#include "maxon/nodesgraph.h"
#include "maxon/datatypebase.h"

// TODO: (Maik) for R23 move most the contents of this file into exchange framework.
// The reason for this is the requirement to maintain compatibility between 21.1 and 22, resulting
// in potential function duplicates. In this case, the newly introduced functionality to the
// exchange framework overlaps with parts of the nodespace framework.

class BaseDocument;
namespace maxon
{

namespace material
{
struct MaterialExchangeData;
} // namespace material

namespace nodes
{

//----------------------------------------------------------------------------------------
/// Defines a type-agnostic material parameter that is used to opaquely pass data along the MaterialExchangeInterface with DataDictionary objects.
/// This class only holds a single value and no texture, but it may indicate the need for a texture representation.
//----------------------------------------------------------------------------------------
struct PackedMaterialParameter
{
	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty parameter.
	//----------------------------------------------------------------------------------------
	PackedMaterialParameter() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor a parameter with the opaque provided data. 
	//----------------------------------------------------------------------------------------
	explicit PackedMaterialParameter(Data&& value, Bool isConstant, UInt dynamicTimestamp) :
		_value(std::move(value)), _isConstant(isConstant), _dynamicTimestamp(dynamicTimestamp)
	{

	}

	Result<void> CopyFrom(const PackedMaterialParameter& src)
	{
		iferr_scope;
		_value.CopyFrom(src._value) iferr_return;
		_isConstant = src._isConstant;
		_dynamicTimestamp = src._dynamicTimestamp;
		return OK;
	}

	Data _value;								 // The opaque default / constant value.
	Bool _isConstant = true;		 // Defines whether the parameter is constant and only requires a single value for representation.
	UInt _dynamicTimestamp = 0;	 // The timestamp of the dynamic texture-driven parameter.
};
MAXON_DATATYPE(PackedMaterialParameter, "net.maxon.nodes.datatype.packedmaterialparameter");

//----------------------------------------------------------------------------------------
/// Defines a material parameter that is used to communicated via the MaterialExchangeInterface.
/// This class only holds a single value and no texture, but it may indicate the need for a texture representation.
//----------------------------------------------------------------------------------------
template <typename TYPE>
struct TypedMaterialParameter
{
	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty parameter.
	//----------------------------------------------------------------------------------------
	TypedMaterialParameter() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor a parameter with the provided typed data. 
	//----------------------------------------------------------------------------------------
	TypedMaterialParameter(TYPE&& value, Bool isConstant, UInt dynamicTimestamp, const InternedId& id) :
		_value(std::move(value)), _isConstant(isConstant), _dynamicTimestamp(dynamicTimestamp), _id(id)
	{

	}

	TYPE _value = TYPE();					// The default / constant value.
	Bool _isConstant = true;			// Defines whether the parameter is constant and only requires a single value for representation.
	UInt _dynamicTimestamp = 0;		// The timestamp of the dynamic texture-driven parameter.
	InternedId _id;								// The id of the parameter.
};

namespace MATERIALEXCHANGE
{	
	//----------------------------------------------------------------------------------------
	/// INTENT gives and indication of the intention for material exchange query of a particular subject to allow you to react differently.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(maxon::InternedId, INTENT, "net.maxon.nodes.materialexchange.intent");
	MAXON_ATTRIBUTE(void, INTENT_VIEWPORT, "net.maxon.nodes.materialexchange.intent_viewport");	///< Used for material preview in viewport.
	MAXON_ATTRIBUTE(void, INTENT_EXPORT, "net.maxon.nodes.materialexchange.intent_export");			///< Used for material export.

} // namespace MATERIALEXCHANGE

//----------------------------------------------------------------------------------------
/// MaterialExchangeInterface defines the external representation of a node material.
/// If not specifically defined for a node space, all node materials are assumed to be gray dielectric materials
/// for viewport and export purposes.
///
/// You may derive from this interface and indicate support for particular material types in your node space the following:
/// @code
/// maxon::BaseArray<maxon::Id> materialExchangeBundleIds;
/// materialExchangeBundleIds.Append(maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::GetId()) iferr_return;
/// spaceData.Set(maxon::nodes::NODESPACE::MATERIALEXCHANGEBUNDLEIDS, std::move(materialExchangeBundleIds)) iferr_return;
/// spaceData.Set(maxon::nodes::NODESPACE::MATERIALEXCHANGECLASS, NodeSpaceViewportMaterialExample::GetClass()) iferr_return;
/// @endcode
///
/// Currently, the material types are declared in the file "datadescription_node_spaces.h" as port bundles
/// As of R21.1, only the "maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL" is used, solely for viewport representation.
/// However, this may change in the future, we may export the delivered parameters into various output formats such as OBJ or FBX
/// without any further requirements from the component.
/// In addition, we may consider supporting differing bundle types that will enhance the visual quality by the viewport, for example
/// Disney Principled BRDF, Standard Surface, or USD Preview Surface.
/// Furthermore, we may offer the ability the extend this material collection dynamically to offer a quality-optimized export to
/// a particular output format, e.g. GLTF.
///
/// The lifetime of MaterialExchangeRef instances is managed by C4D. Generally, a space-specific instance is constructed
/// for each node material. However, it may be rather short-living.
///
/// The instance is released if a space is switched from, or created respectively when toggling the active space in the GUI.
///
/// It is also released and recreated if the topology of the material changes, for example
/// enabling the solo mode on a node flushes all cached textures and results in a new MaterialExchangeRef instantiation.
/// 
/// The MaterialExchangeRef is kept alive over parameter changes. Effectively, such a change is assumed to be a gradual / continuous
/// change from the previously displayed state of the material.
//----------------------------------------------------------------------------------------
class MaterialExchangeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(MaterialExchangeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.materialexchangeinterface");

public:

	//----------------------------------------------------------------------------------------
	/// Extracts / gets an typed parameter from a DataDictionaryInterface object with type check between the requested value type and the attribute's type.
	/// @tparam TYPE									The value type of the parameter.
	/// @tparam KEY										The type of the key attribute.
	/// @param[in] parameters					The DataDictionary holding the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @return												The typed parameter on success.
	//----------------------------------------------------------------------------------------
	template <typename TYPE, typename KEY>
	static Result<TypedMaterialParameter<TYPE>> Extract(const DataDictionaryInterface& parameters, KEY&& id)
	{
		iferr_scope;

		using TT = typename std::conditional<IsFidClass<KEY>::value && !STD_IS_REPLACEMENT(same, typename IsFidClass<KEY>::type, Data), typename maxon::Substitute<TYPE, typename IsFidClass<KEY>::type>::type, TYPE>::type;

		const Data* parameterDataPtr = parameters.PrivateGetData(ConstDataPtr(InternedId(id)));
		CheckState(parameterDataPtr != nullptr);

		if (parameterDataPtr->GetType() == GetDataType<PackedMaterialParameter>())
		{
			const PackedMaterialParameter& packedParameter = parameterDataPtr->Get<PackedMaterialParameter>() iferr_return;
			TT value = packedParameter._value.Get<TT>() iferr_return;
			const Bool isConstant = packedParameter._isConstant;
			const UInt dynamicTimestamp = packedParameter._dynamicTimestamp;
			TypedMaterialParameter<TT> parameter = TypedMaterialParameter<TT>(std::move(value), isConstant, dynamicTimestamp, id);
			return parameter;
		}

		return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid TypedMaterialParameter"_s);
	}

	//----------------------------------------------------------------------------------------
	/// Extracts / gets an typed parameter from a DataDictionary with type check between the requested value type and the attribute's type.
	/// @tparam TYPE									The value type of the parameter.
	/// @tparam KEY										The type of the key attribute.
	/// @param[in] parameters					The DataDictionary holding the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @return												The typed parameter on success.
	/// For example, a base color can be extracted the following:
	/// @code
	/// maxon::nodes::TypedMaterialParameter<Color> baseColor = maxon::nodes::MaterialExchangeInterface::Extract<Color>(parameters, maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::BASE_COLOR) iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename TYPE, typename KEY>
	static Result<TypedMaterialParameter<TYPE>> Extract(const DataDictionary& parameters, KEY&& id)
	{
		iferr_scope;
		const DataDictionaryInterface* parametersPtr = parameters.GetPointer();
		CheckState(parametersPtr != nullptr);
		return Extract<TYPE>(*parametersPtr, id);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a typed parameter into the provided DataDictionary with type check between the provided value and the attribute's type.
	/// @tparam KEY										The type of the key attribute.
	/// @param[out] parameters				The DataDictionary to hold on the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @param[in] value							The typed constant / default value of the parameter.
	/// @param[in] isConstant					True if the parameter is constant (and requires no texture-driven representation).
	/// @param[in] dynamicTimestamp		The timestamp of the texture-driven representation.
	/// @return												OK on success.
	/// For example, a red base color can be inserted the following:
	/// @code
	/// maxon::nodes::MaterialExchangeInterface::Insert(parameters, maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL::BASE_COLOR, Color(1, 0, 0), true, 0) iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY>
	static Result<void> Insert(DataDictionary& parameters, KEY&& id, T&& value, Bool isConstant, UInt dynamicTimestamp)
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value && !STD_IS_REPLACEMENT(same, typename IsFidClass<KEY>::type, Data), typename maxon::Substitute<T, typename IsFidClass<KEY>::type>::type, T>::type;
		Data dataValue;
		iferr (dataValue.Set(std::forward<TT>(value)))
			return err;
		Data packedParameter;
		iferr (packedParameter.Set(PackedMaterialParameter(std::move(dataValue), isConstant, dynamicTimestamp)))
			return err;
		return parameters.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(id)), std::move(packedParameter));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts an opaque parameter into the provided DataDictionary.
	/// @tparam KEY										The type of the key attribute.
	/// @param[out] parameters				The DataDictionary to hold on the parameter.
	/// @param[in] id									The parameter's attribute id.
	/// @param[in] dataValue					The opaque constant / default value of the parameter.
	/// @param[in] isConstant					True if the parameter is constant (and requires no texture-driven representation).
	/// @param[in] dynamicTimestamp		The timestamp of the texture-driven representation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename KEY>
	static Result<void> InsertData(DataDictionary& parameters, KEY&& id, Data&& dataValue, Bool isConstant, UInt dynamicTimestamp)
	{
		Data packedParameter;
		iferr (packedParameter.Set(PackedMaterialParameter(std::move(dataValue), isConstant, dynamicTimestamp)))
			return err;
		return parameters.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(id)), std::move(packedParameter));
	}

	//----------------------------------------------------------------------------------------
	/// Loads and parses the data description of material and inserts the defined default values into a DataDictionary.
	/// This method caches once-loaded description for performance.
	/// @param[in] materialType			The (bundle) type of the material representation.
	/// @return											The parameter set on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> LoadMaterialDefaults(const Id& materialType);

	//----------------------------------------------------------------------------------------
	/// Initializes the exchange representation for a node material. 
	/// This method is called immediately after a change to the node graph by the viewport.
	/// In this method it is safe to access the original node graph.
	/// @param[in] intent						The intention behind the material exchange request.
	/// @param[in] materialType			The (bundle) type of the external material representation.
	/// @param[in] graph						The node graph of the node material.
	/// @param[in] endNodePath			The path to the end node as it is known to C4D.
	/// @param[in] soloNodePath			The path to the solo node as it is known to C4D.
	/// @return											OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Initialize(const Id& intent, const Id& materialType, const NodesGraphModelRef& graph, const NodePath& endNodePath, const NodePath& soloNodePath);

	//----------------------------------------------------------------------------------------
	/// Fetches the parameters for the external material representation.
	/// The returned container is expected to be populated with the appropriate configuration for all bundle members.
	/// Parameters that are marked as non-constant may result in a texture baking request through
	/// ConfigureTextureProviderRequest() later on if demanded by the viewport, or by the export functionality.
	/// In this method it is safe to access the original node graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> GetMaterialParameters();

	//----------------------------------------------------------------------------------------
	/// Offers configuration of the preview request. The call to this function is made
	/// during viewport redraw if any non-constant texture-driven value is demanded.
	/// 
	/// In this method it is *not* safe to access the original node graph.
	/// 
	/// It expected that the attribute maxon::nodes::PREVIEWIMAGEREQUEST::PROVIDER is defined, e.g.
	/// @code
	/// request.Set(maxon::nodes::PREVIEWIMAGEREQUEST::PROVIDER, ViewportTextureProviderExample::GetClass()) iferr_return;
	/// @endcode
	///
	/// @param[in,out] request			The data container of the preview request that is handed over to the PreviewImageProviderInterface::Initialize() method.
	/// @return											OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConfigureTextureProviderRequest(DataDictionaryObjectRef request);
};

//----------------------------------------------------------------------------------------
/// Please see maxon::material::MaterialImport in "maxon/material/materialimport.h" for related information.
/// NodeMaterialImport defines how a node material is created for import operations.
/// If no importer is defined, a fallback is performed and creates a group node with image nodes, ignoring
/// any texture buffers or substance references.
//----------------------------------------------------------------------------------------
class NodeMaterialImportInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeMaterialImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.nodematerialimportinterface");

public:

	//----------------------------------------------------------------------------------------
	/// Populates a node graph based on the provided material data. The destination BaseDocument is provided for context.
	/// @param[out] graph					The node graph to fill with nodes, connections and values.
	/// @param[in] materialData		The material data to import from.
	/// @param[in] baseDocument		The scene into which the material is imported.
	/// @return										OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Import(NodesGraphModelRef& graph, const material::MaterialExchangeData& materialData, BaseDocument& baseDocument);
};


//----------------------------------------------------------------------------------------
/// Please see maxon::material::MaterialExport in "maxon/material/materialexport.h" for related information.
/// A MaterialExport defines the data provider of node space for material export operations.
/// If no exporter is defined, a fallback is performed that the MaterialExchangeInterface to create a
/// textured material of type maxon::NODESPACE::EXCHANGE::BUNDLE::VIEWPORTMATERIAL.
/// Then, a material mapping to the requested target type is performed.
//----------------------------------------------------------------------------------------
class NodeMaterialExportInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeMaterialExportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.nodematerialexport");

public:

	//----------------------------------------------------------------------------------------
	/// Initialized the export operation by providing the node graph that should be exported and the BaseDocument and export configuration for context.
	/// @param[in] graph							The node graph to be exported.
	/// @param[in] baseDocument				The document in which the node graph lives.
	/// @param[in] config							The export configuration.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Initialize(NodesGraphModelRef& graph, BaseDocument& baseDocument, const DataDictionary& config);

	//----------------------------------------------------------------------------------------
	/// Returns the constant-values parameters along with markings of whether they require texture representation
	/// in order to request texture baking in the GetTextures() stage.
	/// Returned parameters are expected to be of type maxon::material::PackedConstantParameter().
	/// @return												The material parameters on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Id, DataDictionary>> GetParameters();

	//----------------------------------------------------------------------------------------
	/// Creates textures for the provided parameters.
	/// The textures may be texture buffers, image references or substance references.
	/// @param[in] texturedChannels		The parameters for which textures are requested.
	/// @return												The textures on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashMap<Id, Data>> GetTextures(const HashSet<Id>& texturedChannels);
};

#include "nodematerialexchange1.hxx"
#include "nodematerialexchange2.hxx"
} // namespace nodes
} // namespace maxon

#endif // NODEMATERIALEXCHANGE_H__