#ifndef COLORCATEGORY_ASSET_H__
#define COLORCATEGORY_ASSET_H__

#include "maxon/assets.h"
#include "maxon/vector.h"



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

//----------------------------------------------------------------------------------------
/// Implementation of a color category asset.
//----------------------------------------------------------------------------------------
class ColorCategoryAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(ColorCategoryAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.colorcategoryasset");

public:
	//----------------------------------------------------------------------------------------
	/// Create returns a new color category asset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ColorCategoryAsset> Create();

	//----------------------------------------------------------------------------------------
	/// GetColorCategory returns the color category of an asset.
	/// @param[in] asset							Asset to use.
	/// @param[in] lookupRepository		Repository to look up for dependencies.
	/// @return                       Tuple<Id, Color>.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Id, Color> GetColorCategory(const AssetDescription& asset, const AssetRepositoryRef& lookupRepository);

	//----------------------------------------------------------------------------------------
	/// SetColorCategory stores a color category for an asset.
	/// @param[in] asset							Asset to modify
	/// @param[in] category						Category to use.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
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
