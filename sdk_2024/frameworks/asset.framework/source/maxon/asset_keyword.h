#ifndef ASSET_KEYWORD_H__
#define ASSET_KEYWORD_H__



#include "maxon/assets.h"



namespace maxon
{

class KeywordAsset;

//----------------------------------------------------------------------------------------
/// KeywordAssetInterface extends the AssetInterface to deal with keyword assets.
//----------------------------------------------------------------------------------------
class KeywordAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(KeywordAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.keywordasset");

public:
	static MAXON_METHOD Result<KeywordAsset> Create();

	//----------------------------------------------------------------------------------------
	/// AddKeyword adds a keyword to an asset.
	/// @param[in] target							Asset to add keywords.
	/// @param[in] keywordId					Keyword Id to add.
	/// @param[in] userScope					True to use ASSETMETADATA::UserKeywords other wise ASSETMETADATA::Keywords.
	/// @param[in] updateUsageRepository True to update the last used time and use count.
	/// @return                       True if a keyword was added. False if the keyword was not added - that means it already exists. 
	///																Error if it was not possible to add the keyword.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> AddKeyword(const AssetDescription& target, const Id& keywordId, Bool userScope, const AssetRepositoryRef& updateUsageRepository);
	
	//----------------------------------------------------------------------------------------
	/// RemoveKeyword removes a keyword from an asset. 
	/// @param[in] target							Asset to remove keywords.
	/// @param[in] keywordId					Keyword Id to remove.
	/// @param[in] userScope					True to use ASSETMETADATA::UserKeywords other wise ASSETMETADATA::Keywords.
	/// @return                       True if a keyword was found and removed. False if the keyword was not found on the asset. Error if it was not possible to remove the keyword.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> RemoveKeyword(const AssetDescription& target, const Id& keywordId, Bool userScope);

	//----------------------------------------------------------------------------------------
	/// HasKeyword returns if the asset has a given keyword assigned
	/// @param[in] target							Asset to search.
	/// @param[in] keywordId					Keyword Id to search.
	/// @return                       userScope type on success ASSETMETADATA::UserKeywords or ASSETMETADATA::Keywords. Id() if not found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<LiteralId> HasKeyword(const AssetDescription& target, const Id& keywordId);

	//----------------------------------------------------------------------------------------
	/// IsFavouriteAsset returns true if the given asset is a favourite.
	/// @param[in] ad									Asset to inspect.
	/// @return                       True if favourite.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsFavouriteAsset(const AssetDescription& ad);

	//----------------------------------------------------------------------------------------
	/// GetDefaultAssetState checks if the given asset is a preset.
	/// @param[in] ad									Asset to look at.
	/// @return                       Tuple<Bool, Bool> on success. First: true if it is an preset, Second: True if the asset is the default asset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<Bool, Bool>> GetDefaultAssetState(const AssetDescription& ad);

	//----------------------------------------------------------------------------------------
	/// GetDefaultAsset returns the default preset for the given type.
	/// @param[in] type								Preset type.
	/// @param[in] lookupRepository		Repository to search for.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> GetDefaultAsset(const Id& type, const AssetRepositoryRef& lookupRepository);

	//----------------------------------------------------------------------------------------
	/// SetDefaultAsset sets the default state of the given preset asset. Every type can only have one preset as default.
	/// @param[in] ad									Asset to modify.
	/// @param[in] on									True to make this preset the default. False to make it no longer the default.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetDefaultAsset(const AssetDescription& ad, Bool on);
};

namespace ASSETMETADATA
{
	/// Array with ids of keywords assets, attached to the asset
	MAXON_ATTRIBUTE(Array<Id>, Keywords, "net.maxon.asset.keywords");

	/// Array with ids of user keywords assets, attached to the asset. 
	MAXON_ATTRIBUTE(Array<Id>, UserKeywords, "net.maxon.asset.userkeywords");

	/// defines the id of the favorite keyword
	static constexpr LiteralId ID_FAVOURITEKEYWORD = LiteralId("net.maxon.keyword.favourite");
}

namespace AssetTypes
{
	/// AssetTypes::Keyword allows to store keywords within in a repository
	MAXON_DECLARATION(AssetType, Keyword, "net.maxon.assettype.keyword");
};

namespace APPSETTINGS
{
	namespace ASSETS
	{
		/// Used by KeywordAssetInterface::GetDefaultAsset()/SetDefaultAsset() 
		/// to store the Application Settings with ids of all the user defaults (those with the star) in a DataDictionary.
		/// The key is the asset's ASSETMETADATA::SubType, while the value is the associated DefaultsPreset asset Id for
		/// older defaults. All 2023.2 and newer defaults have a value of type Tuple<Id,Id> (asset identifier, asset type identifier).
		MAXON_ATTRIBUTE(DataDictionary, DEFAULTS, "net.maxon.appsettings.assets.defaults");
	}
}

#include "asset_keyword1.hxx"
#include "asset_keyword2.hxx"

}



#endif // ASSET_KEYWORD_H__
