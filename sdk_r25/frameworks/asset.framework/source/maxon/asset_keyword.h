#ifndef ASSET_KEYWORD_H__
#define ASSET_KEYWORD_H__



#include "maxon/assets.h"



namespace maxon
{

class KeywordAsset;

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
	/// IsFavouriteAsset returns true if the given asset is a favourite.
	/// @param[in] ad									Asset to inspect.
	/// @return                       True if favourite.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsFavouriteAsset(const AssetDescription& ad);

	static MAXON_METHOD Result<Tuple<Bool, Bool>> GetDefaultAssetState(const AssetDescription& ad);

	static MAXON_METHOD Result<AssetDescription> GetDefaultAsset(const Id& type, const AssetRepositoryRef& lookupRepository);

	static MAXON_METHOD Result<void> SetDefaultAsset(const AssetDescription& ad, Bool on);
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Array<Id>, Keywords, "net.maxon.asset.keywords");
	MAXON_ATTRIBUTE(Array<Id>, UserKeywords, "net.maxon.asset.userkeywords");

	/// defines the id of the favorite keyword
	static const LiteralId ID_FAVOURITEKEYWORD = LiteralId("net.maxon.keyword.favourite");
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
		MAXON_ATTRIBUTE(DataDictionary, DEFAULTS, "net.maxon.appsettings.assets.defaults");
	}
}

#include "asset_keyword1.hxx"
#include "asset_keyword2.hxx"

}



#endif // ASSET_KEYWORD_H__
