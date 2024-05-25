#ifndef CATEGORY_ASSET_H__
#define CATEGORY_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class CategoryAsset;


//----------------------------------------------------------------------------------------
/// Implementation of category assets
//----------------------------------------------------------------------------------------
class CategoryAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(CategoryAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.categoryasset");

public:
	//----------------------------------------------------------------------------------------
	/// Create creates a new category asset.
	/// @return                       CategoryAsset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<CategoryAsset> Create();

	//----------------------------------------------------------------------------------------
	/// GetParentCategory returns the category id of the given asset.
	/// @param[in] asset							Asset to investigate.
	/// @return                       Category id on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Id GetParentCategory(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// SetAssetCategory allows to move an asset into a category.
	/// @param[in] asset							asset to move.
	/// @param[in] category						Category to use.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetAssetCategory(const AssetDescription& asset, const Id& category);

	//----------------------------------------------------------------------------------------
	/// GetAssetBreadcrumbString returns the asset parent categories as string.
	/// @param[in] asset							Asset to investigate.
	/// @param[in] repository					Repository to use.
	/// @return                       Breadcrumb as string array. Example: "Category3, Category2, Category1". You can use this to create the final string: String x = JoinElements(array, " > "_s)
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<String>> GetAssetBreadcrumbString(const AssetDescription& asset, const AssetRepositoryRef& repository);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, Category, "net.maxon.node.category");
}

//----------------------------------------------------------------------------------------
/// Uncategorized Category. This is a default category where all assets with no category ends up.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(void, AssetCategoryUncategorized, "net.maxon.assetcategory.uncategorized");

//----------------------------------------------------------------------------------------
/// Special Category to collect all watch folders (R26)
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(void, AssetCategoryWatchFolders, "category@5846c0689c0248cfa54bffed866571ce");

namespace AssetTypes
{
	/// AssetTypes::Category allows to store categories within in a repository
	MAXON_DECLARATION(AssetType, Category, "net.maxon.assettype.category");
};

#include "category_asset1.hxx"
#include "category_asset2.hxx"

}

#endif // CATEGORY_ASSET_H__
