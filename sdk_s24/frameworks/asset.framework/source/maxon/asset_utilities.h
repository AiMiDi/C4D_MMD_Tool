#ifndef ASSET_UTILITIES_H__
#define ASSET_UTILITIES_H__

#include "maxon/assets.h"



namespace maxon
{

class AssetUtilitiesInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(AssetUtilitiesInterface, MAXON_REFERENCE_NORMAL, "net.maxon.asset.helperinterface");

public:
	static MAXON_METHOD Result<String> IncreaseAssetVersion(const String& currentVersion);

	static MAXON_METHOD Result<void> AssetSetMetaData(const AssetDescription& asset, const String& assetName, const String& assetVersion, const Id& assetCategory);
};

#include "asset_utilities1.hxx"
#include "asset_utilities2.hxx"

} // namespace maxon



#endif // ASSET_UTILITIES_H__
