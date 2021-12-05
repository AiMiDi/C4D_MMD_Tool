#ifndef ASSET_CREATION_H__
#define ASSET_CREATION_H__

#include "maxon/assets.h"

class BaseBitmap;
class BaseDocument;
class BaseList2D;
class BaseMaterial;
class BaseObject;
class Filename;

namespace maxon
{

using AssetMap = HashMap<Url, Id>;

using AddDependenciesDelegate = Delegate<Result<Id>(const Url& depUrl, const Id& parentCategory, const AssetRepositoryRef& repository, AssetMap& assetIdMap)>;

enum class ASSETINSERTOBJECTMODE
{
	ASOBJECT,
	ASINSTANCE,
	ASRENDERINSTANCE,
	ASXREF,
} MAXON_ENUM_LIST(ASSETINSERTOBJECTMODE);

namespace APPSETTINGS
{
	namespace ASSETS
	{
		MAXON_ATTRIBUTE(ASSETINSERTOBJECTMODE, INSERTOBJECTAS, "net.maxon.appsettings.assets.insertobjectas");
	}
}

class AssetCreationInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(AssetCreationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.mvp.assetcreationinterface");

public:
	static MAXON_METHOD Result<Id> GetNewAssetIdFromIdAndVersion(const IdAndVersion& idAndVersion);

	static MAXON_METHOD Result<void> UpdateMetaData(const AssetDescription& asset);

	static MAXON_METHOD Result<void> UpdateMetaData(BaseDocument* doc, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	static MAXON_METHOD Result<Bool> SaveBaseDocumentAsAsset(BaseDocument* doc, const Filename& c4dRootPath, Filename& saveFileName, const AssetRepositoryRef& repository, const ValueReceiver<const AssetDependencyStruct&>& dependencies, AssetMap& assetIdMap, const AddDependenciesDelegate& addDependenciesDelegate, const Id& parentCategory, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAsset(const Url& saveFileName, const Id& parentCategory, const InternedId& subType,
		Bool calculateMetaData, const DataDictionary& metaProperties, const HashSet<AssetDependencyStruct>& dependencies,
		const BaseArray<Url>& previews, Float animFps, const String& nodeFilename, const HashMap<Id, String>& localizedNames,
		const HashMap<Id, String>& localizedAnnotations, const AssetMetaData& copyMetaData);

	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAssetAlone(const Url& saveFileName, const AssetMetaData& copyMetaData);

	static MAXON_METHOD Result<AssetDescription> SaveDocumentAsset(BaseDocument* assetDoc, InternedId subType, Id newAssetId, const AssetRepositoryRef& assetRepository, const Id& assetCategory, const String& assetName, const String& versionString, const Delegate<Result<BaseBitmap*>()>& createPreviewBitmapDelegate, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<Tuple<AssetDescription, Bool>> SaveTextureAsset(const Url& imageUrl, const String& assetName, const Id& parentCategory, const AssetRepositoryRef& assetRepository, HashSet<AssetDependencyStruct>& dependencies, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<void> GenerateImagePreview(const Url& imageUrl, const ValueReceiver<const Url&>& previews, Int32 previewW, Int32 previewH);

	static MAXON_METHOD Result<void> GenerateScenePreviewImage(BaseDocument* doc, BaseBitmap* preview, Bool frameScene, Bool isOriginal, Int32 previewW, Int32 previewH);

	static MAXON_METHOD Result<AssetDescription> CreateMaterialAsset(BaseDocument* activeDoc, BaseMaterial* mat, const AssetRepositoryRef& assetRepository, 
		const Id& assetId, const Id& assetCategory, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> CreateObjectAsset(BaseObject* op, BaseDocument* activeDoc, const AssetRepositoryRef& assetRepository, 
		const Id& assetId, const Id& assetCategory, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> CreateSceneAsset(BaseDocument* activeDoc, const AssetRepositoryRef& assetRepository, 
		const Id& assetId, const Id& assetCategory, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> SaveActiveDocumentAsNewVersion(BaseDocument* activeDoc, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<void> CreateObjectsOnDrag(BaseDocument* doc, const Url& url, const AssetDescription& asset, Bool allowPreviewCube, Bool overwriteMatrix, const Matrix& overwriteMatrixMg, Float placementScale);

	static MAXON_METHOD Result<void> CheckObjectsOnDrop(BaseDocument* doc, const Url& url, const AssetDescription& asset, Float placementScale);

	static MAXON_METHOD Result<Bool> CreateMaterialsOnDrag(BaseDocument* doc, BaseList2D* objectOrTag, const Url& url, const AssetDescription& asset);
};

#include "asset_creation1.hxx"
#include "asset_creation2.hxx"

} // namespace maxon


#endif // ASSET_CREATION_H__
