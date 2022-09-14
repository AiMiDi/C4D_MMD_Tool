#ifndef ASSETS_WATCHFOLDER_H__
#define ASSETS_WATCHFOLDER_H__

#include "maxon/assets.h"
#include "maxon/urlassetrepository.h"

namespace maxon
{

namespace URLFLAGS
{
	MAXON_ATTRIBUTE(String, WATCHFOLDERNAME, "net.maxon.url.watchfolderstring"); ///< Forces the repository name
}

class WatchFolderAssetRepositoryRef;

class WatchFolderAssetRepositoryInterface : MAXON_INTERFACE_BASES(UrlAssetRepositoryInterface)
{
	MAXON_INTERFACE(WatchFolderAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.watchfolderassetrepository");

public:
	static MAXON_METHOD Result<void> AddWatchFolder(const Url& url, Bool active);
	static MAXON_METHOD Result<void> RemoveWatchFolder(const WatchFolderAssetRepositoryRef& repo);
};

#include "asset_watchfolder1.hxx"

namespace AssetRepositoryTypes
{
	MAXON_DECLARATION(Class<AssetRepositoryRef>, WatchFolder, "net.maxon.assets.repositorytype.watchfolder");
}

#include "asset_watchfolder2.hxx"

}


#endif // ASSETS_WATCHFOLDER_H__
