#ifndef DATABASE_ASSET_H__
#define DATABASE_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class DatabaseAsset;
class LanguageRef;



class DatabaseAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(DatabaseAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.databaseasset");

public:
	static MAXON_METHOD Result<DatabaseAsset> Create();
	
	static MAXON_METHOD Result<String> GetRepositoryName(const AssetRepositoryRef& repository, const LanguageRef& language, const String& fallbackName);

	static MAXON_METHOD Result<void> SetRepositoryName(const AssetRepositoryRef& repository, const String& name, const LanguageRef& language);
};

namespace AssetTypes
{
	/// AssetTypes::Database stores informations about the repository
	MAXON_DECLARATION(AssetType, Database, "net.maxon.assettype.database");
};

#include "database_asset1.hxx"
#include "database_asset2.hxx"

/// id of the asset which contains the database informations.
#define DATABASEASSETID_PREFIX "databaseinfo_"_cs

}

#endif // DATABASE_ASSET_H__
