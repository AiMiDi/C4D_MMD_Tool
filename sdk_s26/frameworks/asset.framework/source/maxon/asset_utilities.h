#ifndef ASSET_UTILITIES_H__
#define ASSET_UTILITIES_H__

#include "maxon/assets.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// Helper Interface for Asset functions.
//----------------------------------------------------------------------------------------
class AssetUtilitiesInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetUtilitiesInterface, MAXON_REFERENCE_NORMAL, "net.maxon.asset.helperinterface");

public:
	//----------------------------------------------------------------------------------------
	/// IncreaseAssetVersion description.
	/// @param[in] currentVersion			Increases the version string by one. e.g. "1.0" -> "1.1" or "1.0.99" -> "1.1.00"
	/// @return                       New Version String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> IncreaseAssetVersion(const String& currentVersion);

	//----------------------------------------------------------------------------------------
	/// AssetSetMetaData sets the asset meta data for the given asset.
	/// @param[in] asset							Asset to modify
	/// @param[in] assetName					Human readable asset name.
	/// @param[in] assetVersion				Asset version to set.
	/// @param[in] assetCategory			Asset category to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssetSetMetaData(const AssetDescription& asset, const String& assetName, const String& assetVersion, const Id& assetCategory);

	//----------------------------------------------------------------------------------------
	/// GetAssetIcon returns the asset icon. It returns the preview stored under ASSETMETADATA::ASSET_PREVIEWIMAGEURL
	/// @param[in] asset							Asset to use.
	/// @return                       Url to the preview icon on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> GetAssetIcon(const AssetDescription& asset);
};

#include "asset_utilities1.hxx"
#include "asset_utilities2.hxx"

} // namespace maxon



#endif // ASSET_UTILITIES_H__
