#ifndef ASSET_CREATION_HELPER_H__
#define ASSET_CREATION_HELPER_H__

#include "maxon/assets.h"

namespace maxon
{

class BasePresetAssetType;

//----------------------------------------------------------------------------------------
/// Helper interface for asset creation and drag&drop.
/// All maxon API based asset creation code should be here. Any asset creation with C4D legacy API ties
/// should be in AssetCreationInterface.
//----------------------------------------------------------------------------------------
class AssetCreationHelper
{
	MAXON_INTERFACE_NONVIRTUAL(AssetCreationHelper, MAXON_REFERENCE_STATIC, "net.maxon.assets.assetcreationhelper");

public:

	/// List of identifiers that define a defaults preset type (will become the asset's ASSETMETADATA::SubType).
	using DefaultsPresetSubType = Array<Id>;			// Should be decltype(presetargs::AssetSubType)::ValueType, dependency to fix.

	//----------------------------------------------------------------------------------------
	/// GetDefaultSettings loads the settings for all maxon API defaults asset types.
	/// All XnodeEmulation and capsule type objects are supported here.
	/// @param[in] asset							Defaults preset asset to load.
	/// @param[out] outSubType				Identifier of the defaults preset asset type.
	/// @param[out] outDefaultValues	Setting dictionary. One entry for each attribute to receive a default value. Key: AMEmulationDefaultsKey (i.e. ~ PathBlock), Value: Data (contains DESCRIPTION::DATA::BASE::DEFAULTVALUE).
	/// @return												True means a partial preset was loaded. False for a full preset. Error on failure.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> GetDefaultSettings(const AssetDescription& asset, DefaultsPresetSubType& outSubType, DataDictionary& outDefaultValues);

	//----------------------------------------------------------------------------------------
	/// Merges all identifiers in a single formatted Id. Format will be C4DSUBTYPEPREFIX + ("_" + Id) ...
	/// where each identifier will be appended to the prefix with a "_" separator.
	/// @param[in] ids								The identifiers to merge.
	/// @return												The merged identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> JoinDefaultsPresetSubType(const DefaultsPresetSubType& ids);

	//----------------------------------------------------------------------------------------
	/// Merges all identifiers in a single formatted Id. Format will be C4DSUBTYPEPREFIX + ("_" + Id) ...
	/// Where each identifier will be appended to the prefix with a "_" separator.
	/// @param[in] ids								The identifiers to merge.
	/// @return												The merged identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> JoinDefaultsPresetSubType(const Block<const DefaultsPresetSubType::ValueType>& ids);

	//----------------------------------------------------------------------------------------
	/// Merges all identifiers in a single formatted Id. Format will be C4DSUBTYPEPREFIX + ("_" + assetTypePrefix) + ("_" + ids[0])...
	/// @see JoinDefaultsPresetSubType.
	/// @param[in] ids								The identifiers to merge.
	/// @return												The merged identifier. An IllegalArgumentError if the #assetType is not handled by function.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> GetJoinedDefaultsPresetSubType(const BasePresetAssetType& assetType, const Block<const DefaultsPresetSubType::ValueType>& ids);

	//----------------------------------------------------------------------------------------
	/// Finds the NodeTemplate asset id that was used to create the AssetTypes::NodeDefaultsPreset #asset.
	/// @param[in] asset							An asset of type AssetTypes::NodeDefaultsPreset.
	/// @return												The NodeTemplate identifier to use for creating a node or capsule. Error if no identifier found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> GetNodeTemplateIdFromDefaultsPreset(const AssetDescription& asset);
};

#include "asset_creation_helper1.hxx"
#include "asset_creation_helper2.hxx"

} // namespace maxon


#endif // #ifndef ASSET_CREATION_HELPER_H__
