#ifndef ASSET_UTILITIES_H__
#define ASSET_UTILITIES_H__

#include "maxon/assets.h"

namespace maxon
{

class LanguageRef;

/// @brief Basic meta data container for AssetUtilitiesInterface::AssetSetMetaData.
struct BaseAssetMetaData
{
	MAXON_OPERATOR_EQUALITY(BaseAssetMetaData, _assetName, _assetVersion, _assetCategory);

	String _assetName;								///< Human readable asset name to set. Can start with #$XXAssetName where XX are numbers indicating the asset's sorting value (ASSETMETADATA::ASSET_SORT).
	String _assetVersion;							///< Asset version to set (ASSETMETADATA::ASSET_VERSIONTAG).
	Id _assetCategory;								///< Asset category identifier to set.
};

/// @brief Creation meta data container for AssetUtilitiesInterface::AssetSetCreationData.
struct CreationAssetMetaData
{
	MAXON_OPERATOR_EQUALITY(CreationAssetMetaData, _c4dVersion, _releaseType, _c4dBuildId);

	Int _c4dVersion = 0;							///< Current Cinema 4D version (Application::GetVersion).
	Int _releaseType = 0;							///< Usually BRANCH_RELEASE_TYPE_VALUE.
	String _c4dBuildId;								///< Current Cinema 4D build (Application::GetVersion).
};

//----------------------------------------------------------------------------------------
/// Helper Interface for Asset functions.
//----------------------------------------------------------------------------------------
class AssetUtilitiesInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AssetUtilitiesInterface, MAXON_REFERENCE_STATIC, "net.maxon.asset.helperinterface", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// IncreaseAssetVersion description.
	/// @param[in] currentVersion			Increases the version string by one. e.g. "1.0" -> "1.1" or "1.0.99" -> "1.1.00"
	/// @return                       New Version String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> IncreaseAssetVersion(const String& currentVersion);

	//----------------------------------------------------------------------------------------
	/// Sets the asset's meta data.
	/// @markDeprecated	Use BaseAssetMetaData version.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetMetaData(const AssetDescription& asset, const String& userAssetName, const String& assetVersion, const Id& assetCategory);

	//----------------------------------------------------------------------------------------
	/// Sets the asset's meta data.
	/// @param[in] asset							Asset which will receive the meta data.
	/// @param[in] data								Meta data to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetMetaData(const AssetDescription& asset, const BaseAssetMetaData& data);

	//----------------------------------------------------------------------------------------
	/// Returns the asset icon. It returns the preview stored under ASSETMETADATA::ASSET_PREVIEWIMAGEURL
	/// @param[in] asset							Asset to use.
	/// @return                       Url to the preview icon on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> GetAssetIcon(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Returns an EnumDataType which contains all versions of the asset, plus an additional "latest" entry.
	/// @param[in] repo								The asset repository for the lookup.
	/// @param[in] type								The asset type of the asset.
	/// @param[in] assetId						The asset id to look for.
	/// @return                       An enum type which has "latest" as first entry and all found versions of the asset as following entries.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<EnumDataType> GetEnumTypeForVersions(const AssetRepositoryRef& repo, const AssetType& type, const Id& assetId);

	//----------------------------------------------------------------------------------------
	/// @brief Sets the asset's creation meta data.
	/// @see ASSETMETADATA::CreationProperties
	/// @markDeprecated	Use CreationAssetMetaData version.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetCreationData(const AssetDescription& asset, Int c4dVersion, const String& c4dBuildId, Int releaseType);

	//----------------------------------------------------------------------------------------
	/// @brief Sets the asset's creation meta data.
	/// @see ASSETMETADATA::CreationProperties
	/// @param[in] asset							Asset which will receive the meta data.
	/// @param[in] data								Meta data to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetCreationData(const AssetDescription& asset, const CreationAssetMetaData& data);

	//----------------------------------------------------------------------------------------
	/// @brief Sets the asset's creation meta data with current version's values.
	/// @see ASSETMETADATA::CreationProperties
	/// @param[in] asset							Asset which will receive the meta data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetCreationData(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// @brief Creates an updated version of the AssetLink's origin data, filled with missing informations from the asset's meta data.
	/// Result will be a merge #link origin data and a new origin data built from #nodeAsset.
	/// @param[in] nodeAsset					The asset.
	/// @param[in] link								The link containing the origin data to update or fill.
	/// @param[in] lang								Language to use for filling origin data.
	/// @return												The updated origin data.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> GetMergedAssetOriginData(const AssetDescription& nodeAsset, const AssetLink& link, const LanguageRef& lang);

	//----------------------------------------------------------------------------------------
	/// @brief Iterates through the given string to search for characters that would disrupt a Url URLFLAGS::QUERY.
	/// Like '=', '&'.
	/// 
	/// @param[in] query							The query string to validate.
	/// @return												True if the query contains unwanted characters.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool HasUrlQueryCharacters(const String& query);

	//----------------------------------------------------------------------------------------
	/// @brief Iterates through the given string to replace characters that would disrupt a Url URLFLAGS::QUERY.
	/// @see HasUrlQueryCharacters
	/// 
	/// @param[in] query							The query string to fix.
	/// @return												The fixed query string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> ReplaceUrlQueryCharacters(const String& query);

	//----------------------------------------------------------------------------------------
	/// @brief Appends a variable and value pair to the query string.
	/// Name and value will be cleansed of any unwanted characters. Appended result will be
	/// "name=value" with a '&' prefix if there was already some other variables in the query.
	/// @see URLFLAGS::QUERY
	/// 
	/// @param[in,out] query					The query string to append to.
	/// @param[in] variableName				The variable's identifier to append.
	/// @param[in] variableValue			The variable's value to append.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AppendUrlQueryVariable(String& query, const String& variableName, const String& variableValue);
};

// AssetUtilitiesInterface is legacy name, static helpers don't have interface suffix.
using AssetUtilities = AssetUtilitiesInterface;

#include "asset_utilities1.hxx"
#include "asset_utilities2.hxx"

} // namespace maxon



#endif // ASSET_UTILITIES_H__
