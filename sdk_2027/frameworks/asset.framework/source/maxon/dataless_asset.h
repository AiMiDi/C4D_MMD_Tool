#ifndef DATALESS_ASSET_H__
#define DATALESS_ASSET_H__

#include "maxon/assets.h"

namespace maxon
{

class DatalessAssetType;

//----------------------------------------------------------------------------------------
/// DatalessAssetType is a convenience class to simplify the implementation of dataless assets
/// (i.e., assets which consist of just their id and meta data). Unless you want to override
/// or add methods to the AssetTypeInterface or AssetInterface implementations, you can simply
/// write code like
/// @code
/// MAXON_DECLARATION_REGISTER(AssetTypes::Entity)
/// {
///   return DatalessAssetType::Create(Class<Asset>::DefaultValue(), objectId, false, Url::DefaultValue());
/// }
/// @endcode
/// to register a dataless asset type.
//----------------------------------------------------------------------------------------
class DatalessAssetTypeInterface : MAXON_INTERFACE_BASES(AssetTypeInterface)
{
	MAXON_INTERFACE(DatalessAssetTypeInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.datalessassettype");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the asset type. Usually, you don't call this method directly but through Create.
	/// @param[in] cls                The asset class to use for asset creation. You can pass a null reference to use a default implementation.
	/// @param[in] typeId             The asset type identifier.
	/// @param[in] versioned          True if the asset shall be versioned, false otherwise.
	/// @param[in] defaultIcon        A Url pointing to the default icon for assets of this type. Can be left empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Class<Asset>& cls, const Id& typeId, Bool versioned, const Url& defaultIcon);

	//----------------------------------------------------------------------------------------
	/// Creates a new asset type for dataless assets.
	/// @param[in] cls                The asset class to use for asset creation. You can pass a null reference to use a default implementation.
	/// @param[in] typeId             The asset type identifier.
	/// @param[in] versioned          True if the asset shall be versioned, false otherwise.
	/// @param[in] defaultIcon        A Url pointing to the default icon for assets of this type. Can be left empty.
	/// @return                       A new asset type.
	//----------------------------------------------------------------------------------------
	static inline MAXON_FUNCTION Result<DatalessAssetType> Create(const Class<Asset>& cls, const Id& typeId, Bool versioned, const Url& defaultIcon);

	//----------------------------------------------------------------------------------------
	/// Creates a new asset of this asset type. This uses the asset class which was given to Create,
	/// or a default implementation if no class was specified.
	/// @return                       A new asset of this asset type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Asset> CreateAsset() const;
};

#include "dataless_asset1.hxx"

MAXON_DECLARATION(Class<DatalessAssetType>, DatalessAssetTypeBase, "net.maxon.class.datalessassettype");

#include "dataless_asset2.hxx"

Result<DatalessAssetType> DatalessAssetTypeInterface::Create(const Class<Asset>& cls, const Id& typeId, Bool versioned, const Url& defaultIcon)
{
	iferr_scope;
	DatalessAssetType::NonConst t = DatalessAssetTypeBase().Create() iferr_return;
	t.Init(cls, typeId, versioned, defaultIcon) iferr_return;
	return t;
}

}

#endif // DATALESS_ASSET_H__
