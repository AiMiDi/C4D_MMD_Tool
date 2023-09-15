#ifndef DATABASE_ASSET_H__
#define DATABASE_ASSET_H__

#include "maxon/assets.h"



namespace maxon
{

class DatabaseAsset;
class LanguageRef;


//----------------------------------------------------------------------------------------
/// Implementation of DatabaseAsset.
//----------------------------------------------------------------------------------------
class DatabaseAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(DatabaseAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.databaseasset");

public:
	//----------------------------------------------------------------------------------------
	/// Create creates a new database asset.
	/// @return                       DatabaseAsset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DatabaseAsset> Create();
	
	//----------------------------------------------------------------------------------------
	/// GetRepositoryName returns the database name.
	/// @param[in] repository					Asset repository to use.
	/// @param[in] language						Optional Language. Default is the program language.
	/// @param[in] fallbackName				Fall back string of no name was found.
	/// @param[in] addDetails					Add additional details (like database name/url) to the name.
	/// @return                       String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetRepositoryName(const AssetRepositoryRef& repository, const LanguageRef& language, const String& fallbackName, Bool addDetails);

	//----------------------------------------------------------------------------------------
	/// SetRepositoryName stores a asset database name.
	/// @param[in] repository					Asset repository to modify.
	/// @param[in] name								Name to store.
	/// @param[in] language						Optional Language. Default is the program language.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
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
