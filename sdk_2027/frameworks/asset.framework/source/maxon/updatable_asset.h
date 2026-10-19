#ifndef UPDATABLE_ASSET_H__
#define UPDATABLE_ASSET_H__

#include "maxon/assets.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// An UpdatableAsset is an Asset which supports the update of its updatable references
/// to other assets to newer versions. Such an update doesn't create a new repository version
/// of the asset because the asset definition itself isn't changed, only the references
/// (represented by AssetLink) point to newer assets.
//----------------------------------------------------------------------------------------
class UpdatableAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(UpdatableAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.updatableasset", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// Updates the given references of this asset to point to the corresponding assets.
	/// The references have to use updatable AssetLink objects (their update policy must not
	/// be ASSET_UPDATE_POLICY::NEVER). Afterwards the @ref GetUpdate "update counter"
	/// is incremented.
	/// @param[in] updates						The updates to apply as a block of the references and their new targets.
	/// @param[in] repository					The repository to which this asset belongs. @c{asset.GetRepository()}
	/// 															will be nullptr during the update because the asset is in mutable state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Update(const Block<const Tuple<AssetReference, AssetBase>>& updates, const AssetRepositoryRef& repository);
};


//----------------------------------------------------------------------------------------
/// A tuple where the asset description represents an asset in a repository and the array
/// lists other assets to which the asset's references can be updated. For example if
/// asset A has links to assets B1, C1 but there are newer versions B2, C2,
/// then this is represented by the tuple (A, [B2, C2]).
//----------------------------------------------------------------------------------------
using AssetRepositoryUpdate = Tuple<AssetDescription, BaseArray<AssetBase>>;

//----------------------------------------------------------------------------------------
/// Asset repository which allows to update assets.
//----------------------------------------------------------------------------------------
class UpdatableAssetRepositoryInterface : MAXON_INTERFACE_BASES(AssetRepositoryInterface)
{
	MAXON_INTERFACE(UpdatableAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.updatableassetrepository", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// GetPendingUpdates returns an array with a list of unsaved changes.
	/// @param[in] reset							True to reset the changes.
	/// @return												Array on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<AssetRepositoryUpdate>> GetPendingUpdates(Bool reset) const;

	//----------------------------------------------------------------------------------------
	/// Update applies the updates to the repository.
	/// @param[in] updates						Updates to process.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Update(const Block<const AssetRepositoryUpdate>& updates);
};

#include "updatable_asset1.hxx"

#include "updatable_asset2.hxx"

}

#endif // UPDATABLE_ASSET_H__
