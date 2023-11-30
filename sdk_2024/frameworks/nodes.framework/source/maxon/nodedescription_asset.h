#ifndef NODEDESCRIPTION_ASSET_H__
#define NODEDESCRIPTION_ASSET_H__

#include "maxon/assets.h"

namespace maxon
{

namespace AssetTypes
{
	//----------------------------------------------------------------------------------------
	/// @brief This is the asset type for node description definitions.
	/// @see NodeDescriptionAssetInterface.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(AssetType, NodeDescription, "net.maxon.node.assettype.nodedescription");
};

class DataDictionary;
class DataDescriptionDefinition MAXON_FORWARD("maxon/datadescriptiondefinition.h");
class GraphNode;

using LanguageStringDataDescriptionDefinition = HashMap<Id /* Language Id */, DataDescriptionDefinition /* Description */> MAXON_FORWARD("maxon/datadescriptiondefinition.h");
using DataDescriptionDefinitionWithUIAndLanguageStrings = Tuple<DataDescriptionDefinition /* Data description */, DataDescriptionDefinition /* Ui description*/, LanguageStringDataDescriptionDefinition /* String description */> MAXON_FORWARD("maxon/datadescriptiondefinition.h");

namespace nodes
{

class NodeDescriptionAsset;


//----------------------------------------------------------------------------------------
/// @brief A description asset allows easy reuse of partial or complete descriptions.
/// Asset can be used to create new nodes or to add some component to existing nodes and groups.
//----------------------------------------------------------------------------------------
class NodeDescriptionAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(NodeDescriptionAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.asset.nodedescription");
public:

	/// @brief Allows to overwrite node description attributes instead of creating unique port entries.
	/// Set to true to overwrite all attributes, i.e. the same asset dropped multiple times on a node will create ports on first drop, subsequent drops
	/// would update the description so it matches the dropped description.
	/// Set to false to allow same asset dropped multiple times on a node to create new unique ports each time. Port identifiers will be appended
	/// with an increasing number (1, 2, 3, ....). This only applies to ports. Include commands, groups and separators will only get updated, not created
	/// with unique identifiers.
	/// False by default.
	MAXON_ATTRIBUTE_CLASS(Bool, OverwriteAllAttributes, "net.maxon.node.assettype.context.overwriteall", RESOURCE_DEFAULT(false));

	/// @brief Defines the default classification to assign to an attribute which has DESCRIPTION::DATA::BASE::CLASSIFICATION not set.
	/// Providing this allow to use a basic NodeDescriptionAsset both as input or output.
	/// @see DESCRIPTION::DATA::BASE::CLASSIFICATION.
	MAXON_ATTRIBUTE_CLASS(Id, DefaultPortClassification, "net.maxon.node.assettype.context.defaultportclass");

	//----------------------------------------------------------------------------------------
	/// Creates a new NodeDescriptionAsset. Asset will be empty and should be stored in a repository
	/// with AssetRepositoryInterface::StoreAsset to save it's content.
	/// @return												The new empty NodeDescriptionAsset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeDescriptionAsset> Create();

	//----------------------------------------------------------------------------------------
	/// Uses the NodeDescriptionAsset's definition to update the the target node with any additional entries
	/// or changes it contains.
	/// @param[in] node								The group node where to apply the description changes.
	/// @param[in] context						Additional arguments for the node definition update.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Apply(const GraphNode& node, const DataDictionary& context);

	//----------------------------------------------------------------------------------------
	/// Merges the given DataDescriptionDefinition #desc with the current asset's content.
	/// @param[in] desc								The descriptions to add or merge to the current asset.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> MergeDescriptions(const DataDescriptionDefinitionWithUIAndLanguageStrings& desc);

	//----------------------------------------------------------------------------------------
	/// Reads the description from the requested category.
	/// @param[in] category						Either DATADESCRIPTION_CATEGORY_DATA, DATADESCRIPTION_CATEGORY_UI or a language identifier.
	/// @return												The description on success, will be empty if the category was empty or missing.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionDefinition> GetDataDescriptionDefinition(const Id& category) const;

	//----------------------------------------------------------------------------------------
	/// Writes the description for the requested category. Asset should be stored to repository for changes to be permanent.
	/// @param[in] category						Either DATADESCRIPTION_CATEGORY_DATA, DATADESCRIPTION_CATEGORY_UI or a language identifier.
	/// @param[in] desc								The new description (no merge will occur).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetDataDescriptionDefinition(const Id& category, const DataDescriptionDefinition& desc);

	//----------------------------------------------------------------------------------------
	/// Reads all description categories.
	/// @return												The description on success, can be empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<const DataDescriptionDefinitionWithUIAndLanguageStrings&> GetCompleteDescription() const;

	//----------------------------------------------------------------------------------------
	/// Writes the all description categories. Asset should be stored to repository for changes to be permanent.
	/// @param[in] desc								The new description (no merge will occur).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCompleteDescription(const DataDescriptionDefinitionWithUIAndLanguageStrings& desc);

	//----------------------------------------------------------------------------------------
	/// Uses the NodeDescriptionAsset's definition to create a new one ready to be used in the given context.
	/// Attributes could be skipped, removed or receive a new identifier based on the content of #context.
	/// I.e. #compareDefinition will be compared with the asset's definition and a final adjusted result will be returned.
	/// @param[in] compareDefinition	The definition categories to which add the NodeDescriptionAsset's content.
	/// @param[in] context						Additional arguments for the definition comparison.
	/// @return												A full definition ready to be used as per the requested context.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionDefinitionWithUIAndLanguageStrings> CreateFinalDefinition(const DataDescriptionDefinitionWithUIAndLanguageStrings& compareDefinition, const DataDictionary& context);

};

//----------------------------------------------------------------------------------------
/// @brief Type interface for NodeDescriptionAsset. Allows to create new assets from a description and
/// load descriptions from existing assets.
//----------------------------------------------------------------------------------------
class NodeDescriptionAssetTypeInterface : MAXON_INTERFACE_BASES(AssetTypeInterface)
{
	MAXON_INTERFACE(NodeDescriptionAssetTypeInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.asset.nodedescriptiontype");

public:

	//----------------------------------------------------------------------------------------
	/// Reads the default category identifier as suggested by the asset type.
	/// @return												The category identifier. Empty if no default suggestion.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Id GetSuggestedCategory() const;

	//----------------------------------------------------------------------------------------
	/// Creates and stores a complete description in a new NodeDescriptionAsset with identifier #assetId.
	/// AssetUtilitiesInterface::AssetSetMetaData can be called afterwards to setup name, version, ...
	/// @param[in] desc								The description to store. Categories are all optional.
	/// @param[in] repo								The destination repository.
	/// @param[in] assetId						The final NodeDescriptionAsset's identifier.
	/// @return												The new AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> StoreAsset(const DataDescriptionDefinitionWithUIAndLanguageStrings& desc, const AssetRepositoryRef& repo, const Id& assetId);

	//----------------------------------------------------------------------------------------
	/// Loads the asset with all categories (including string languages).
	/// @param[in] desc								The asset to load.
	/// @return												The asset with all categories reading to be used.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodeDescriptionAsset> LoadAsset(const AssetDescription& desc);

};

/// @see NodesDescriptionAssetApplyFinalizers.
using NodesDescriptionAssetApplyFinalizer = Delegate<Result<void>(const NodeDescriptionAsset& asset /* Asset applied on node */, const GraphNode&/* Apply node */, const DataDictionary&/* Context */)>;

/// @brief Register delegates to be called after a NodeDescriptionAsset was applied on a node. Transaction will still be opened
MAXON_REGISTRY(NodesDescriptionAssetApplyFinalizer, NodesDescriptionAssetApplyFinalizers, "net.maxon.node.registry.asset.nodedescriptionfinalizers");

#include "nodedescription_asset1.hxx"
#include "nodedescription_asset2.hxx"

} // namespace nodes

} // namespace maxon

#endif // NODEDESCRIPTION_ASSET_H__
