#ifndef COLORCATEGORY_ASSET_H__
#define COLORCATEGORY_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

#define COLOR_CATEGORY_PREFIX "net.maxon.asset.colorcategory."

namespace ASSETMETADATA
{
	namespace COLORCATEGORY
	{
		MAXON_ATTRIBUTE(Color, COLOR, "net.maxon.assetmetadata.colorcategory.color");
	}
}

class ColorCategoryAsset;

class ColorCategoryAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(ColorCategoryAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.colorcategoryasset");

public:
	static MAXON_METHOD Result<ColorCategoryAsset> Create();

	static MAXON_METHOD Tuple<Id, Color> GetColorCategory(const AssetDescription& asset, const AssetRepositoryRef& lookupRepository);

	static MAXON_METHOD Result<void> SetColorCategory(const AssetDescription& asset, const Id& category);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, ColorCategory, "net.maxon.asset.colorcategory");
}

namespace AssetTypes
{
	/// AssetTypes::ColorCategory allows to store color categories within in a repository
	MAXON_DECLARATION(AssetType, ColorCategory, "net.maxon.assettype.colorcategory");
};

#include "colorcategory_asset1.hxx"
#include "colorcategory_asset2.hxx"

}


#endif // COLORCATEGORY_ASSET_H__
