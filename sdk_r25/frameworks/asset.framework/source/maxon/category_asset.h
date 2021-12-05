#ifndef CATEGORY_ASSET_H__
#define CATEGORY_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class CategoryAsset;



class CategoryAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(CategoryAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.categoryasset");

public:
	static MAXON_METHOD Result<CategoryAsset> Create();

	static MAXON_METHOD Id GetParentCategory(const AssetDescription& asset);

	static MAXON_METHOD Result<void> SetAssetCategory(const AssetDescription& asset, const Id& category);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, Category, "net.maxon.node.category");
}

MAXON_ATTRIBUTE(void, AssetCategoryUncategorized, "net.maxon.assetcategory.uncategorized");

namespace AssetTypes
{
	/// AssetTypes::Category allows to store categories within in a repository
	MAXON_DECLARATION(AssetType, Category, "net.maxon.assettype.category");
};

#include "category_asset1.hxx"
#include "category_asset2.hxx"

}

#endif // CATEGORY_ASSET_H__
