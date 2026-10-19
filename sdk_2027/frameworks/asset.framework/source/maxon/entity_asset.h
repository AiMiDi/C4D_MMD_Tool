#ifndef ENTITY_ASSET_H__
#define ENTITY_ASSET_H__

#include "maxon/dataless_asset.h"

namespace maxon
{

namespace AssetTypes
{
	//----------------------------------------------------------------------------------------
	/// The Entity asset type is used for the meta data attributes ASSETMETADATA::Vendor and ASSETMETADATA::Artist
	/// to represent vendors or artists. These can be persons, companies or other legal entities.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(DatalessAssetType, Entity, "net.maxon.assettype.entity");
};

namespace ASSETMETADATA
{
	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute indicates the vendor of an asset.
	/// The Id refers to an Entity asset with information about the vendor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Id, Vendor, "net.maxon.asset.vendor");

	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute indicates the creator of an asset.
	/// The Id refers to an Entity asset with information about the creator.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Id, Creator, "net.maxon.asset.creator");

	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute points to internet resources of an entity.
	/// These can include the entity's own website, social media links, email addresses (with mailto scheme) etc.
	///
	/// The attribute is stored at an entity asset, not at the asset created by an entity.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Url>, InternetResources, "net.maxon.asset.internetresources");

	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute contains licensing and copyright information associated with an entity.
	/// The attribute is localized.
	///
	/// The attribute is stored at an entity asset, not at the asset created by an entity.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(String, License, "net.maxon.asset.license");

	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute points to a webpage with more information about the license associated with an entity.
	///
	/// The attribute is stored at an entity asset, not at the asset created by an entity.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Url, LicenseUrl, "net.maxon.asset.licenseurl");

	// other meta data typically used for entities are OBJECT::BASE::NAME for the name, OBJECT::BASE::ANNOTATIONS for a description,
	// and ASSETMETADATA::ASSET_PREVIEWIMAGEURL for a logo
}

#include "entity_asset1.hxx"
#include "entity_asset2.hxx"

}

#endif // ENTITY_ASSET_H__
