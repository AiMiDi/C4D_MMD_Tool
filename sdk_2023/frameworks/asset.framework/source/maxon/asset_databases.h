#ifndef ASSET_DATABASES_H__
#define ASSET_DATABASES_H__

#include "maxon/delegate.h"
#include "maxon/forwardref.h"
#include "maxon/objectbase.h"
#include "maxon/observable.h"
#include "maxon/optional.h"
#include "maxon/url.h"



namespace maxon
{

class AssetRepositoryRef;

struct AssetDatabaseStruct
{
	Url	 _dbUrl; // URLFLAGS::ASSETREPOSITORYTYPE contains the type of the db
	Bool _active = true;
	Bool _exportOnSaveProject = true;

	// temporary, do not save
	Bool _isBuiltin = false;

	HashInt GetHashCode() const;
};

namespace URLFLAGS
{
	MAXON_ATTRIBUTE(Id, ASSETREPOSITORYTYPE, "net.maxon.url.assetdatabasetype"); ///< Forces the repository to treat this url as watch folder repository

	MAXON_ATTRIBUTE(InternedId, ASSETREPOSITORYCATEGORY, "net.maxon.url.repositorycategory"); ///< category of the repository in the database listview, see ASSETREPOSITORYCATEGORY_ENUM
	/// flags for URLFLAGS::ASSETREPOSITORYCATEGORY
	namespace ASSETREPOSITORYCATEGORY_ENUM
	{
		MAXON_ATTRIBUTE(void, OTHER, "databases.other");								///< URLFLAGS::ASSETREPOSITORYCATEGORY - fallback if everything goes wrong, usually not used
		MAXON_ATTRIBUTE(void, USER, "database.user");										///< URLFLAGS::ASSETREPOSITORYCATEGORY - watch folders and user databases category
		MAXON_ATTRIBUTE(void, INTERNAL, "database.internal");						///< URLFLAGS::ASSETREPOSITORYCATEGORY - internal databases
		MAXON_ATTRIBUTE(void, PROJECTFOLDER, "database.projectfolder"); ///< URLFLAGS::ASSETREPOSITORYCATEGORY - project related folders
		MAXON_ATTRIBUTE(void, SEARCHPATH, "database.searchpaths");			///< URLFLAGS::ASSETREPOSITORYCATEGORY - search paths added in the prefs
	}
}

//----------------------------------------------------------------------------------------
/// This namespace contains all attributes to be used with SettingsInterface to set and get preferences
//----------------------------------------------------------------------------------------
namespace APPSETTINGS
{
	namespace ASSETS
	{
		/// defines the path of the asset cache. this is the place where c4d stores all downloaded assets
		MAXON_ATTRIBUTE(Url, CACHEPATH, "net.maxon.appsettings.assets.cachepath");

		/// this settings contain an array with all additional database paths. it's internally used by AssetDataBasesInterface::GetAssetDatabaseCachePath()/SetAssetDatabaseCachePath()
		/// do not use this values directly! always go through AssetDataBasesInterface::GetAssetDatabaseCachePath()/SetAssetDatabaseCachePath()
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
	static MAXON_METHOD ForwardRef<AssetRepositoryRef> FindRepository(const Url& url);

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
	/// WaitForDatabaseLoading waits for the execution of the database loading. Since this is async now during the startup and modification of database lists it gives the developer a chance to wait for that end.
	/// @return                      True if loading is finished. False if canceled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool WaitForDatabaseLoading();

	//----------------------------------------------------------------------------------------
	/// ReloadDatabases reloads the asset repositories from disk.
	/// @param[in] forceReload				True if databases should be forces to be reloaded. False to only load new databases and remove unused.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ReloadAssetRepositories(Bool forceReload);

	//----------------------------------------------------------------------------------------
	/// Observable to receive additional databases to add to the application.
	/// the receiver needs to receive a url with the URLFLAGS::ASSETREPOSITORYTYPE set correctly
	/// e.g. url.Set(URLFLAGS::ASSETREPOSITORYTYPE, AssetRepositoryTypes::AssetDatabase().GetId()) iferr_return;
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableQueryDatabases, (const ValueReceiver<const Url&>& databaseUrl), ObservableCombinerRunAllComponent);
};

MAXON_DATATYPE(AssetDatabaseStruct, "net.maxon.datatype.assetdatabasestruct");

#include "asset_databases1.hxx"
#include "asset_databases2.hxx"

}

#endif // ASSET_DATABASES_H__
