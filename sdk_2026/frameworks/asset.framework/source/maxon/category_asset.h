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
	/// @return												CategoryAsset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<CategoryAsset> Create();

	//----------------------------------------------------------------------------------------
	/// GetParentCategory returns the category id of the given asset.
	/// @param[in] asset							Asset to investigate.
	/// @return												Category id on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Id GetParentCategory(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// SetAssetCategory allows to move an asset into a category.
	/// @param[in] asset							Asset to move.
	/// @param[in] category						Category to use.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetAssetCategory(const AssetDescription& asset, const Id& category);

	//----------------------------------------------------------------------------------------
	/// GetAssetBreadcrumbString returns the asset parent categories as string.
	/// @param[in] asset							Asset to investigate.
	/// @param[in] repository					Repository to use.
	/// @return												Breadcrumb as string array. Example: "Category3, Category2, Category1". You can use this to create the final string: String x = JoinElements(array, " > "_s)
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


/// Categories for the basic asset types and top level categories.
MAXON_ATTRIBUTE(void, AssetCategoryMaterials         , "category_a1ba084a9eeedb9b");
MAXON_ATTRIBUTE(void, AssetCategoryModels            , "category@3d2621c1bc48485aa2b7ceead989e421");
MAXON_ATTRIBUTE(void, AssetCategoryHDRIS             , "category@b9c32d04a12d449ca1c758ddb3c695b0");
MAXON_ATTRIBUTE(void, AssetCategoryExampleScenes     , "category@4e785a69ef3749738bfd9d2b191535d5");
MAXON_ATTRIBUTE(void, AssetCategoryDefaultScenes     , "category@710902c4d01a4e7d9778e620ec05ee5b");
MAXON_ATTRIBUTE(void, AssetCategoryNodes             , "category@52d8f01357834200aa0dc28f0e61bbb3");
MAXON_ATTRIBUTE(void, AssetCategoryTextures          , "category@8c76a408c56f4b5ca9f585dbe0ece9b7");
MAXON_ATTRIBUTE(void, AssetCategoryMotionCapture     , "category_910670e9c361d913");
MAXON_ATTRIBUTE(void, AssetCategoryTemplateAndPresets, "category_6a5cdc939b8ce9ed");
MAXON_ATTRIBUTE(void, AssetCategoryPresets           , "category@2468666d866a481886c91c7155440264");
MAXON_ATTRIBUTE(void, AssetCategoryPlants            , "category_e024f65cd280795e");
MAXON_ATTRIBUTE(void, AssetCategoryFurniture         , "category@ce7a0860d80442c39fae50859132b880");
MAXON_ATTRIBUTE(void, AssetCategoryAccessories       , "category@4087cd4b3c1f43b28f564e189b4328bd");
MAXON_ATTRIBUTE(void, AssetCategoryLighting          , "category@9c7d5c38ab4c43539344ab8add5c3f06");
MAXON_ATTRIBUTE(void, AssetCategoryCharacters        , "category@a0ffc595b4cd438585421bdc47f95aa");
MAXON_ATTRIBUTE(void, AssetCategoryOutdoor           , "category@9101008117534c8f8c88a7c8664df1ee");
MAXON_ATTRIBUTE(void, AssetCategoryVehicles          , "category@3b0bf93f27364ae8bdc59bbfc7e37f56");


namespace AssetTypes
{
	/// AssetTypes::Category allows to store categories within in a repository
	MAXON_DECLARATION(AssetType, Category, "net.maxon.assettype.category");
};

#include "category_asset1.hxx"
#include "category_asset2.hxx"

}

#endif // CATEGORY_ASSET_H__
