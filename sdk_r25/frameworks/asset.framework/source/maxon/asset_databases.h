#ifndef ASSET_DATABASES_H__
#define ASSET_DATABASES_H__

#include "maxon/objectbase.h"
#include "maxon/url.h"
#include "maxon/tuple.h"
#include "maxon/optional.h"



namespace maxon
{

class AssetRepositoryRef;

struct AssetDatabaseStruct
{
	Url	 _dbUrl;
	Bool _active = true;
	Bool _exportOnSaveProject = true;

	// temporary, do not save
	Bool _isBuiltin = false;
};

namespace APPSETTINGS
{
	namespace ASSETS
	{
		MAXON_ATTRIBUTE(Url, CACHEPATH, "net.maxon.appsettings.assets.cachepath");
		MAXON_ATTRIBUTE(BaseArray<AssetDatabaseStruct>, USERPATHS, "net.maxon.appsettings.assets.userpaths");
	}
}

//----------------------------------------------------------------------------------------
/// This interface provides helper functions to register asset repositories.
//----------------------------------------------------------------------------------------
class AssetDataBasesInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetDataBasesInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.assetdatabases");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the url of a asset repository.
	/// @param[in] repository					Repository to find.
	/// @return												Url of the repository on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> FindRepository(const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository for a Url
	/// @param[in] url								Url of the repository to find.
	/// @return												Found repository (if any).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Opt<const AssetRepositoryRef&> FindRepository(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns all repositories added by the user.
	/// @param[in] entry							ValueReceiver to receive the entries.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetDatabases(const ValueReceiver<const AssetDatabaseStruct&>& entry);

	//----------------------------------------------------------------------------------------
	/// Set the new user repositories.
	/// @param[in] newDataBases				Block with tuples of the new urls and activation states.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetDatabases(const Block<AssetDatabaseStruct>& newDataBases);

	//----------------------------------------------------------------------------------------
	/// Writes the gml file with the dependencies of the given asset repository.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteGmlDependencies();

	//----------------------------------------------------------------------------------------
	/// GetAssetDatabaseCachePath returns the path to the cache folder
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Url GetAssetDatabaseCachePath();

	//----------------------------------------------------------------------------------------
	/// SetAssetDatabaseCachePath sets a new cache path to store temporary downloaded objects
	/// @param[in] cachePath					Path to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetAssetDatabaseCachePath(const Url& cachePath);

	//----------------------------------------------------------------------------------------
	/// GetAssetDatabaseCacheSize returns the size of the cached files.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int64> GetAssetDatabaseCacheSize();

	//----------------------------------------------------------------------------------------
	/// ClearAssetDatabaseCache deletes the cache.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ClearAssetDatabaseCache();

	//----------------------------------------------------------------------------------------
	/// WaitForDatabaseLoading description.
	/// @return                      True if loading is finished.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool WaitForDatabaseLoading();

	//----------------------------------------------------------------------------------------
	/// ReloadDatabases reloads the asset repositories from disk.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ReloadAssetRepositories();
};

MAXON_DATATYPE(AssetDatabaseStruct, "net.maxon.datatype.assetdatabasestruct");

#include "asset_databases1.hxx"
#include "asset_databases2.hxx"

}

#endif // ASSET_DATABASES_H__
