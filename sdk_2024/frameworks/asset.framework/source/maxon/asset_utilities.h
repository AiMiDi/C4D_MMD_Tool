#ifndef ASSET_UTILITIES_H__
#define ASSET_UTILITIES_H__

#include "maxon/assets.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// Helper Interface for Asset functions.
//----------------------------------------------------------------------------------------
class AssetUtilitiesInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AssetUtilitiesInterface, MAXON_REFERENCE_STATIC, "net.maxon.asset.helperinterface");

public:
	//----------------------------------------------------------------------------------------
	/// IncreaseAssetVersion description.
	/// @param[in] currentVersion			Increases the version string by one. e.g. "1.0" -> "1.1" or "1.0.99" -> "1.1.00"
	/// @return                       New Version String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> IncreaseAssetVersion(const String& currentVersion);

	//----------------------------------------------------------------------------------------
	/// Sets the asset meta data for the given asset.
	/// @param[in] asset							Asset to modify
	/// @param[in] assetName					Human readable asset name.
	/// @param[in] assetVersion				Asset version to set.
	/// @param[in] assetCategory			Asset category to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetMetaData(const AssetDescription& asset, const String& assetName, const String& assetVersion, const Id& assetCategory);

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
};

#include "asset_utilities1.hxx"
#include "asset_utilities2.hxx"

} // namespace maxon



#endif // ASSET_UTILITIES_H__
