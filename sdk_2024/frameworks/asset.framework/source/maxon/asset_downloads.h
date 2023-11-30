#ifndef ASSET_DOWNLOADS_H__
#define ASSET_DOWNLOADS_H__

#include "maxon/assets.h"

namespace maxon
{

enum class DOWNLOADSTATE
{
	NO,
	YES,
	INPROGRESS,
	ERROR,
	UNAVAILABLE,
} MAXON_ENUM_LIST(DOWNLOADSTATE);

//----------------------------------------------------------------------------------------
/// Helper Interface for Asset downloads functions.
//----------------------------------------------------------------------------------------
class AssetDownloadsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AssetDownloadsInterface, MAXON_REFERENCE_STATIC, "net.maxon.asset.downloadsinterface");

public:
	static MAXON_METHOD Bool IsAssetCached(const AssetDescription& ad);

	static MAXON_METHOD Result<Int64> GetAssetFileSize(const AssetDescription& ad);

	static MAXON_METHOD Result<DOWNLOADSTATE> GetDownloadState(const AssetDescription& ad, const HashSet<AssetDescription>& toDownloadTemp);

	static MAXON_METHOD Result<void> AddAssetWithDependencies(const AssetDescription& ad, const AssetRepositoryRef& searchRepository, BaseArray<AssetDescription>& assetsToExport, HashSet<IdAndVersion>& assetsProcessed);

	static MAXON_METHOD Result<void> DownloadAsset(const BaseArray<AssetDescription>& assetsToDownload, const AssetRepositoryRef& searchRepository);
	static MAXON_METHOD Result<Tuple<ProgressRef, Int>> DownloadAsset(const AssetDescription& asset, const AssetRepositoryRef& searchRepository);
	static MAXON_METHOD Result<Tuple<ProgressRef, Int>> DownloadMultipleAssets(const BaseArray<AssetDescription>& assetsToDownload, const AssetRepositoryRef& searchRepository);

	static MAXON_METHOD void DownloadManagerCancelAll();
	static MAXON_METHOD Bool DownloadManagerIsDownloading();

	static MAXON_METHOD void FreeAssetDownloads();
};

#include "asset_downloads1.hxx"
#include "asset_downloads2.hxx"

}



#endif	// ASSET_DOWNLOADS_H__
