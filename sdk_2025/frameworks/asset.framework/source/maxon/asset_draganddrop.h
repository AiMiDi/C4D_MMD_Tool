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
	//----------------------------------------------------------------------------------------
	/// SetAssetDescriptions setter for DndAsset data.
	/// @param[in] assetDescriptions	Array with assets to drag around.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetAssetDescriptions(const BaseArray<DndAsset>& assetDescriptions)
	{
		return _assetDescriptions.CopyFrom(assetDescriptions);
	}

	//----------------------------------------------------------------------------------------
	/// SetAssetDescriptions setter for DndAsset data.
	/// @param[in] assetDescriptions	Array with assets to drag around.
	//----------------------------------------------------------------------------------------
	void SetAssetDescriptions(BaseArray<DndAsset>&& assetDescriptions)
	{
		_assetDescriptions = std::move(assetDescriptions);
	}

	//----------------------------------------------------------------------------------------
	/// GetAssetDescriptions getter to access the BaseArray<DndAsset>.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	const BaseArray<DndAsset>& GetAssetDescriptions() const
	{
		return _assetDescriptions;
	}

	//----------------------------------------------------------------------------------------
	/// GetAssetDescriptions getter to access the BaseArray<DndAsset>.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	BaseArray<DndAsset>& GetAssetDescriptions()
	{
		return _assetDescriptions;
	}

	//----------------------------------------------------------------------------------------
	/// SetLookupRepository setter to set the lookup repository.
	/// @param[in] lookupRepository		Repository to search in.
	//----------------------------------------------------------------------------------------
	void SetLookupRepository(const AssetRepositoryRef& lookupRepository)
	{
		_lookupRepository = lookupRepository;
	}
	
	//----------------------------------------------------------------------------------------
	/// GetLookupRepository getter function.
	/// @return                       AssetRepositoryRef where to search for assets.
	//----------------------------------------------------------------------------------------
	const AssetRepositoryRef& GetLookupRepository() const
	{
		return _lookupRepository;
	}

private:
	BaseArray<DndAsset> _assetDescriptions;
	AssetRepositoryRef	_lookupRepository;

public:
	MAXON_OPERATOR_STRUCT(DragAndDropDataAssetArray, _assetDescriptions, _lookupRepository);
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
