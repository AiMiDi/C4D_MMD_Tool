#ifndef SMARTSEARCH_ASSET_H__
#define SMARTSEARCH_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class SmartSearchAsset;
class LanguageRef;



class SmartSearchAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(SmartSearchAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.SmartSearchAsset");

public:
	MAXON_METHOD String GetFilterString() const;

	static MAXON_METHOD Result<SmartSearchAsset> Create();

	static MAXON_METHOD Result<void> SetFilterString(const AssetDescription& asset, const String& filter);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(String, SmartSearch, "net.maxon.node.smartsearch");
}

MAXON_ATTRIBUTE(void, AssetCategorySmartSearch, "net.maxon.asset.category.smartsearches");

namespace AssetTypes
{
	/// AssetTypes::SmartSearch allows to store smartsearchs within in a repository
	MAXON_DECLARATION(AssetType, SmartSearch, "net.maxon.assettype.smartsearch");
};

#include "smartsearch_asset1.hxx"
#include "smartsearch_asset2.hxx"

}



#endif // SMARTSEARCH_ASSET_H__
