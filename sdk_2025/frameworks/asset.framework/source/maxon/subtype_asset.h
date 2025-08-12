#ifndef SUBTYPE_ASSET_H__
#define SUBTYPE_ASSET_H__



#include "maxon/assets.h"



namespace maxon
{

class SubTypeAsset;

//----------------------------------------------------------------------------------------
/// Implements the SubTypeAsset. This subtype specializes for example FileAssets.
//----------------------------------------------------------------------------------------
class SubTypeAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(SubTypeAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.subtypeasset");

public:
	//----------------------------------------------------------------------------------------
	/// Create creates a new SubtypeAsset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SubTypeAsset> Create();

	//----------------------------------------------------------------------------------------
	/// SetSubType stores the subtype of an asset.
	/// @param[in] target							Asset to modify.
	/// @param[in] subtype						Subtype to store.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetSubType(const AssetDescription& target, const Id& subtype);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, SubType, "net.maxon.asset.subtype");
	// predefined assets
	MAXON_ATTRIBUTE(void, SubType_ENUM_MediaImage, "net.maxon.asset.subtype.mediaimage");
	MAXON_ATTRIBUTE(void, SubType_ENUM_MediaMovie, "net.maxon.asset.subtype.mediamovie");
	MAXON_ATTRIBUTE(void, SubType_ENUM_Object,		 "net.maxon.asset.subtype.object");
	MAXON_ATTRIBUTE(void, SubType_ENUM_Material,	 "net.maxon.asset.subtype.material");
	MAXON_ATTRIBUTE(void, SubType_ENUM_Scene,			 "net.maxon.asset.subtype.scene");
}

namespace AssetTypes
{
	/// AssetTypes::SubType allows to store subtypes within in a repository
	MAXON_DECLARATION(AssetType, SubType, "net.maxon.assettype.subtype");
};

#include "subtype_asset1.hxx"
#include "subtype_asset2.hxx"

}



#endif // SUBTYPE_ASSET_H__
