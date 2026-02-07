#ifndef SMARTSEARCH_ASSET_H__
#define SMARTSEARCH_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class SmartSearchAsset;
class LanguageRef;


//----------------------------------------------------------------------------------------
/// Implements the smartsearch asset type.
//----------------------------------------------------------------------------------------
class SmartSearchAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(SmartSearchAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.SmartSearchAsset");

public:
	//----------------------------------------------------------------------------------------
	/// GetFilterString returns the filter string stored in the smart search asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetFilterString() const;

	//----------------------------------------------------------------------------------------
	/// Create creates an ew SmartSearchAsset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SmartSearchAsset> Create();

	//----------------------------------------------------------------------------------------
	/// SetFilterString stores a new smartsearch in a SmartSearchAsset.
	/// @param[in] asset							SmartSearchAsset to modify.
	/// @param[in] filter							Fitler string to store.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetFilterString(const AssetDescription& asset, const String& filter);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(String, SmartSearch, "net.maxon.node.smartsearch");
}

MAXON_ATTRIBUTE(void, AssetCategorySmartSearch, "net.maxon.asset.category.smartsearches");

/// Basic smart searches.
MAXON_INTERNED_ID("smartsearch@c69ec87146e342f49930d8c3fa473ec2", AssetSmartSearchBodypaintBrushes);
MAXON_INTERNED_ID("smartsearch@cacfe8f628d848d4990d72e299d52461", AssetSmartSearchBodypaintSwatches);
MAXON_INTERNED_ID("smartsearch@32791c126a7340848eb75940e0c5abf4", AssetSmartSearchIncompleteAssets);
MAXON_INTERNED_ID("smartsearch@14a7e42d83524011a368c266e7b2f382", AssetSmartSearchKeywords);
MAXON_INTERNED_ID("smartsearch@3bb80ad988104cfa9c251e43988e96b6", AssetSmartSearchNewContent);
MAXON_INTERNED_ID("smartsearch@5485368ab6b54a7b95aa919f8aa6e403", AssetSmartSearchRecentlyCreated);
MAXON_INTERNED_ID("smartsearch@b23042157dba43ffa0f47f541bb87b63", AssetSmartSearchRecentlyUsed);

namespace AssetTypes
{
	/// AssetTypes::SmartSearch allows to store smartsearchs within in a repository
	MAXON_DECLARATION(AssetType, SmartSearch, "net.maxon.assettype.smartsearch");
};

#include "smartsearch_asset1.hxx"
#include "smartsearch_asset2.hxx"

}



#endif // SMARTSEARCH_ASSET_H__
