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

class RamDiskRef;
class AssetRepositoryRef;

struct AssetDatabaseStruct
{
	Url	 _dbUrl; // URLFLAGS::ASSETREPOSITORYFACTORY contains the factory to create the db, ASSETREPOSITORYWRITABLE may be set to override the writability
	Bool _active = true;
	Bool _exportOnSaveProject = true;

	// temporary, do not save
	Bool _isBuiltin = false;

	HashInt GetHashCode() const;

	Bool operator ==(const AssetDatabaseStruct& other) const;

	Bool operator !=(const AssetDatabaseStruct& other) const
	{
		return !(this->operator ==(other));
	}
};

namespace URLFLAGS
{
	MAXON_ATTRIBUTE(Id, ASSETREPOSITORYFACTORY, "net.maxon.url.assetrepositoryfactory"); ///< Factory identifier to create the repository from the Url.
	MAXON_ATTRIBUTE(Bool, ASSETREPOSITORYWRITABLE, "net.maxon.url.assetrepositorywritable"); ///< Set to define the writability of the repository.

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
		/// defines the path of the asset cache. this is the place where the application stores all downloaded assets
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
	MAXON_INTERFACE(AssetDataBasesInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.assetdatabases", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// Returns the url of a asset repository.
	/// @param[in] repository					Repository to find.
	/// @return												Url of the repository on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> FindRepository(const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository for a Url.
	/// @param[in] url								Url of the repository to find.
	/// @return												Found repository (if any).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ForwardRef<AssetRepositoryRef> FindRepository(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns the message of an error (if any) which happened when trying to mount the given Url as an asset repository.
	/// @param[in] url								Url of the repository.
	/// @return												Error message on mount (empty if no error happened or the repository is inactive).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetErrorMessage(const Url& url);

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
	/// @MAXON_ANNOTATION{methodId="SetDatabases@bace6d46fa8fbc7f"->"SetDatabases@4659e754aa6f4b1e"}
	static MAXON_METHOD Result<void> SetDatabases(const Block<const AssetDatabaseStruct>& newDataBases);

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
	/// SetAssetDatabaseCachePath sets a new cache path to store temporary downloaded objects.
	/// @param[in] cachePath					Path to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetAssetDatabaseCachePath(const Url& cachePath);

	//----------------------------------------------------------------------------------------
	/// GetAssetDatabaseCacheSize returns the size of the cached files.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int64> GetAssetDatabaseCacheSize();

	//----------------------------------------------------------------------------------------
	/// ClearAssetDatabaseCache deletes the cache.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ClearAssetDatabaseCache();

	//----------------------------------------------------------------------------------------
	/// WaitForDatabaseLoading waits for the execution of the database loading. Since this is async now during the startup and modification of database lists it gives the developer a chance to wait for that end.
	/// @return												True if loading is finished. False if canceled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool WaitForDatabaseLoading();

	//----------------------------------------------------------------------------------------
	/// ReloadDatabases reloads the asset repositories from disk.
	/// @param[in] forceReload				True if databases should be forces to be reloaded. False to only load new databases and remove unused.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ReloadAssetRepositories(Bool forceReload);

	//----------------------------------------------------------------------------------------
	/// Creates a RAM disk which caches the files of the given remote asset repository in memory and also in the application's asset cache (APPSETTINGS::ASSETS::CACHEPATH).
	/// The root of the returned RAM disk can be used as parameter for AssetInterface::CreateRepositoryFromUrl to create the actual repository.
	/// After creating the repository, you can call SetupRamDiskCacheCallbacks.
	/// @param[in] repositoryUrl			The Url of a remote asset repository.
	/// @return												RAM disk as a cache for the remote repository.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ForwardRef<RamDiskRef>> CreateRamDiskCache(const Url& repositoryUrl);

	//----------------------------------------------------------------------------------------
	/// Creates a RAM disk which caches the files of the given remote asset repository in memory and also in the application's asset cache (APPSETTINGS::ASSETS::CACHEPATH).
	/// The root of the returned RAM disk can be used as parameter for AssetInterface::CreateRepositoryFromUrl to create the actual repository.
	/// After creating the repository, you can call SetupRamDiskCacheCallbacks.
	/// @param[in] repositoryUrl			The Url of a remote asset repository.
	/// @param[in] sync								True if changes of the remote repository shall be detected, false otherwise.
	/// 															With false, there will be no remote access unless a file which hasn't been cached needs to be accessed.
	/// @return												RAM disk as a cache for the remote repository.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ForwardRef<RamDiskRef>> CreateRamDiskCache(const Url& repositoryUrl, Bool sync);

	//----------------------------------------------------------------------------------------
	/// Sets callbacks for permission checking and download state notifications on ramDisk and repository.
	/// ramDisk has to be created by CreateRamDiskCache, and repository by a subsequent call of AssetInterface::CreateRepositoryFromUrl
	/// with the ramDisk's root Url.
	/// @param[in] ramDisk						A RAM disk created by CreateRamDiskCache.
	/// @param[in] repository					The repository created for the ramDisk's root Url.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetupRamDiskCacheCallbacks(const RamDiskRef& ramDisk, const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Returns a stamp which is incremented with each modification of the set of repositories.
	/// This includes adding, removing or reloading repositories, but not changes to the repositories themselves
	/// (such as storing a new asset or meta data).
	/// @return												A stamp to check for changes of the set of available repositories, starting with 1.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD UInt GetModificationStamp();

	//----------------------------------------------------------------------------------------
	/// Observable to receive additional databases to add to the application.
	/// the receiver needs to receive a url with the URLFLAGS::ASSETREPOSITORYFACTORY set correctly
	/// e.g. url.Set(URLFLAGS::ASSETREPOSITORYFACTORY, UrlAssetRepositoryFactories::Standard.GetId()) iferr_return;
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableQueryDatabases, (const ValueReceiver<const Url&>& databaseUrl), ObservableCombinerRunAllComponent);
};

MAXON_DATATYPE(AssetDatabaseStruct, "net.maxon.datatype.assetdatabasestruct");

#include "asset_databases1.hxx"
#include "asset_databases2.hxx"

}

#endif // ASSET_DATABASES_H__
