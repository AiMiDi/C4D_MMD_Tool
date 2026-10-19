#ifndef ASSET_FILE_STORAGE_H__
#define ASSET_FILE_STORAGE_H__

#include "maxon/urlassetrepository.h"
#include "maxon/observable.h"

namespace maxon
{

class FileStorageAssetRepositoryInterface : MAXON_INTERFACE_BASES(UrlAssetRepositoryInterface)
{
	MAXON_INTERFACE(FileStorageAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.filestorageassetrepository");

public:
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableProcessRenamedAsset, (const BaseArray<AssetDescription>& assets, const DataDictionary& assetFileMapping), ObservableCombinerRunAllComponent);

	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableProcessMetaData, (const BaseArray<AssetDescription>& assets), ObservableCombinerRunAllComponent);

	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableCopyFile, (const AssetDescription& asset, const Url& from, const Url& to), ObservableCombinerRunAllComponent);
};

#include "asset_file_storage1.hxx"

namespace UrlAssetRepositoryFactories
{
	MAXON_DECLARATION(UrlAssetRepositoryFactory, FileStorage, "net.maxon.asset.registry.repositoryfactories.filestorage");
}

#include "asset_file_storage2.hxx"

} // namespace maxon


#endif // ASSET_FILE_STORAGE_H__
