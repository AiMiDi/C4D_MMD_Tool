#ifndef ASSET_CREATION_H__
#define ASSET_CREATION_H__

#include "maxon/assets.h"
#include "maxon/base_preset_asset.h"
#include "maxon/matrix.h"

#ifdef __CINEMA_HYBRID_REFLECTION_INCLUDE__
#include "lib_description.h"
#include "maxon/desctranslation.h"
#endif

class BaseBitmap;
class BaseDocument;
class BaseList2D;
class BaseMaterial;
class BaseObject;
class C4DAtomGoal;
class Description;
class DescID;
class Filename;
class GeListNode;

namespace maxon
{

class MediaSessionProgressRef;
class AddAssetDepencendyStruct;

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
		MAXON_ATTRIBUTE(Id, LASTSAVEREPOSITORY, "net.maxon.appsettings.assets.lastsaverepository");
	}
}

enum class GENERATESCENEPREVIEWIMAGEFLAGS
{
	NONE = 0,
	ISORIGINALDOCUMENT = (1 << 0),
	FRAMESCENE = (1 << 1),		///< frames the scene before rendering
	PREVIEWRENDER = (1 << 2), ///< use the preview renderer instead of the selected render engine
	GEOMETRYONLY = (1 << 3),	///< apply geometry only rendering to the scene (in case of PREVIEWRENDER)
} MAXON_ENUM_FLAGS(GENERATESCENEPREVIEWIMAGEFLAGS);

enum class OPENSAVEASSETDIALOGFLAGS
{
	NONE = 0,
	ALLOW_EDIT_ID = (1 << 0),
	ALLOW_EDIT_NAME = (1 << 1),
	SHOW_VERSION = (1 << 2),
	ALLOW_EMPTY_CATEGORY = (1 << 3),
	SHOW_MAKE_DEFAULT = (1 << 4),
} MAXON_ENUM_FLAGS(OPENSAVEASSETDIALOGFLAGS);

using DescCompareEntry = Tuple<Bool, BaseContainer, DescID, maxon::String>;


class AssetCreationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetCreationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.mvp.assetcreationinterface");

public:
	static MAXON_METHOD Result<Id> GetNewAssetIdFromIdAndVersion(const String& prefix, const IdAndVersion& idAndVersion);

	static MAXON_METHOD Result<void> UpdateMetaData(const AssetDescription& asset);

	static MAXON_METHOD Result<void> UpdateMetaData(BaseDocument* doc, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	static MAXON_METHOD Result<Bool> SaveBaseDocumentAsAsset(BaseDocument* doc, const Filename& c4dRootPath, Filename& saveFileName, AddAssetDepencendyStruct& addDependencyStruct, ResolveAssetDependenciesStruct& resolveAssets, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	static MAXON_METHOD Result<Tuple<AssetDescription, Bool>> SaveMemFileAsAssetWithCopyAsset(const Url& depResultUrl, const StoreAssetStruct& storeAssetStruct, const InternedId& subType, const HashSet<AssetDependencyStruct>& dependencies, const String& assetName, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAsset(const Url& saveFileName, const Id& parentCategory, const InternedId& subType,
		Bool calculateMetaData, const DataDictionary& metaProperties, const HashSet<AssetDependencyStruct>& dependencies,
		const BaseArray<Url>& previews, Float animFps, const String& assetName, const HashMap<Id, String>& localizedNames,
		const HashMap<Id, String>& localizedAnnotations, const AssetMetaData& copyMetaData);

	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAssetAlone(const Url& saveFileName, const AssetMetaData& copyMetaData);

	static MAXON_METHOD Result<void> SaveMetaDataForAsset(const AssetDescription& asset, const Id& parentCategory, const InternedId& subType, Bool calculateMetaData, const DataDictionary& metaProperties, const HashSet<AssetDependencyStruct>& dependencies, const BaseArray<Url>& previews, Float animFps, const String& assetName, const HashMap<Id, String>& localizedNames, const HashMap<Id, String>& localizedAnnotations);

	static MAXON_METHOD Result<AssetDescription> SaveDocumentAsset(BaseDocument* assetDoc, InternedId subType, Id newAssetId, const StoreAssetStruct& storeAssetStruct, const String& assetName, const String& versionString, const Delegate<Result<BaseBitmap*>()>& createPreviewBitmapDelegate, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<Tuple<AssetDescription, Bool>> SaveTextureAsset(const Url& imageUrl, const String& assetName, const StoreAssetStruct& storeAssetStruct, const HashSet<AssetDependencyStruct>& dependencies, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<void> GenerateImagePreview(const Url& imageUrl, const ValueReceiver<const Url&>& previews, Int32 previewW, Int32 previewH);

	static MAXON_METHOD Result<void> GenerateScenePreviewImage(BaseDocument* doc, BaseBitmap* preview, GENERATESCENEPREVIEWIMAGEFLAGS flags, Int32 previewW, Int32 previewH);

	static MAXON_METHOD Result<AssetDescription> CreateMaterialAsset(BaseDocument* activeDoc, BaseMaterial* mat, const StoreAssetStruct& storeAssetStruct, 
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> CreateObjectAsset(BaseObject* op, BaseDocument* activeDoc, const StoreAssetStruct& storeAssetStruct, 
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> CreateSceneAsset(BaseDocument* activeDoc, const StoreAssetStruct& storeAssetStruct, 
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<AssetDescription> SaveActiveDocumentAsNewVersion(BaseDocument* activeDoc, Bool addAssetsIfNotInThisRepository);

	static MAXON_METHOD Result<void> CreateObjectsOnDrag(BaseDocument* doc, const Url& url, const AssetDescription& asset, Bool allowPreviewCube, Bool overwriteMatrix, const Matrix& overwriteMatrixMg, Float placementScale,
																											 BaseObject* parent = nullptr, BaseObject* prev = nullptr);

	static MAXON_METHOD Result<void> CheckObjectsOnDrop(BaseDocument* doc, const Url& url, const AssetDescription& asset, Float placementScale);

	static MAXON_METHOD Result<BaseArray<BaseMaterial*>> CreateMaterialsOnDrag(BaseDocument* doc, BaseList2D* objectOrTag, const Url& url, Bool allowMultiple, const Id& subType, Bool noManagerUpdate, Bool startUndo);

	static MAXON_METHOD Result<void> AddPreviewRenderAsset(const Block<AssetDescription>& assetsToPreviewRender);

	static MAXON_METHOD Result<Bool> OpenSaveAssetDialog(OPENSAVEASSETDIALOGFLAGS flags, const String& presetTypeName, Id& id, String& name, String& version, const AssetRepositoryRef& lookupRepository, Id& category, AssetRepositoryRef& selectedRepository, Bool &setAsDefault);

	static MAXON_METHOD Result<Url> RenderDocumentAsset(BaseDocument* renderDoc, const MediaSessionProgressRef& progressRef, Int progressIndex, Int polygonCount, Int32 previewW, Int32 previewH, GENERATESCENEPREVIEWIMAGEFLAGS flags);

	static MAXON_METHOD Result<ResolveAssetDependenciesStruct::ResolveDelegate> GetAddDependencyDelegate(const Filename& documentPath, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// GetDefaultSettings loads the settings for a preset
	/// @param[in] asset							Asset to load.
	/// @param[out] resId							BaseList Ids of the preset.
	/// @param[out] resData						Settings Container.
	/// @return                       True means a partial preset was loaded.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool GetDefaultSettings(const AssetDescription& asset, Block<const Int32>& resId, BaseContainer& resData);

	static MAXON_METHOD BaseList2D* GetDefaultObject(const Block<const Int32>& id, BaseDocument* doc);

	static MAXON_METHOD BaseList2D* GetDefaultObject(const AssetDescription& asset);

	static MAXON_METHOD Bool SetDefaultObject(const Block<const Int32>& defaultsType, Bool partial, const BaseContainer& bc, Bool setAsDefault, Bool allowMakeDefault);

	static MAXON_METHOD Result<void> BrowseDescriptionForDefaults(Description& desc, const Delegate<Result<void>(const DescID& key, DescCompareEntry&& value)>& add, Bool isPartial);

	static MAXON_METHOD Result<void> SaveDefaultPresetFromObject(GeListNode* l, Bool makeDefault, Bool allowMakeDefault = true);

	static MAXON_METHOD Result<AssetDescription> SaveBrowserPreset(const BasePresetAssetType& assetType, const PresetSaveArgs& sourceData, const String& presetTypeName, const String& presetNameA, Bool showMakeDefault, Bool setAsDefault, Bool allowSceneRepository);

	//----------------------------------------------------------------------------------------
	/// SupportDefaultPresets description.
	/// @param[in] l									Object to check
	/// @return                       Tuple<Bool, Bool>: first - support presets, second - support set as default 
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Bool, Bool> SupportDefaultPresets(C4DAtomGoal* l);
};

#include "asset_creation1.hxx"
#include "asset_creation2.hxx"

} // namespace maxon


#endif // ASSET_CREATION_H__
