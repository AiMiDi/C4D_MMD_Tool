#ifndef ASSET_DRAGANDDROP_H__
#define ASSET_DRAGANDDROP_H__

#include "maxon/assets.h"
#include "maxon/subtype_asset.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Message data for DRAGTYPE_ASSET
//----------------------------------------------------------------------------------------
class DragAndDropDataAssetArray
{
public:
	Result<void> SetAssetDescriptions(const BaseArray<DndAsset>& assetDescriptions)
	{
		return _assetDescriptions.CopyFrom(assetDescriptions);
	}
	void SetAssetDescriptions(BaseArray<DndAsset>&& assetDescriptions)
	{
		_assetDescriptions = std::move(assetDescriptions);
	}
	const BaseArray<DndAsset>& GetAssetDescriptions() const
	{
		return _assetDescriptions;
	}
	BaseArray<DndAsset>& GetAssetDescriptions()
	{
		return _assetDescriptions;
	}

	void SetLookupRepository(const AssetRepositoryRef& lookupRepository)
	{
		_lookupRepository = lookupRepository;
	}
	const AssetRepositoryRef& GetLookupRepository() const
	{
		return _lookupRepository;
	}

	void SetFilterMatch(const String& filterMatch)
	{
		_filterMatch = filterMatch;
	}
	String GetFilterMatch() const
	{
		return _filterMatch;
	}

private:
	BaseArray<DndAsset> _assetDescriptions;
	AssetRepositoryRef	_lookupRepository;
	String							_filterMatch;

public:
	MAXON_OPERATOR_STRUCT(DragAndDropDataAssetArray, _assetDescriptions, _lookupRepository, _filterMatch);
};

MAXON_DATATYPE(DragAndDropDataAssetArray, "net.maxon.datatype.draganddropdataassetarray");

//----------------------------------------------------------------------------------------
/// Message ID for Asset browser assets, the message data contains (const DragAndDropDataAssetArray*)
//----------------------------------------------------------------------------------------
#define DRAGTYPE_ASSET 200001016

#include "asset_draganddrop1.hxx"
#include "asset_draganddrop2.hxx"

}


#endif // ASSET_DRAGANDDROP_H__
