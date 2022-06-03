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

class ProgressRef;
class AddAssetDepencendyStruct;

//----------------------------------------------------------------------------------------
/// used as parameter in AssetCreationInterface::CreateObjectsOnDrag()
//----------------------------------------------------------------------------------------
enum class ASSETINSERTOBJECTMODE
{
	ASOBJECT,					///< create new assets as an individual object
	ASINSTANCE,				///< if one object of the same object was already dragged into the scene create a instance
	ASRENDERINSTANCE, ///< if one object of the same object was already dragged into the scene create a render instance
	ASXREF,						///< if one object of the same object was already dragged into the scene create a legacy xref
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
	ISORIGINALDOCUMENT = (1 << 0),			///< if set the document will be cloned for rendering, otherwise the document will be used and modified directly.
	FRAMESCENE = (1 << 1),							///< frames the scene before rendering
	PREVIEWRENDER = (1 << 2),						///< use the preview renderer instead of the selected render engine
	GEOMETRYONLY = (1 << 3),						///< apply geometry only rendering to the scene (in case of PREVIEWRENDER)
	AUTODETECT_RENDERENGINE = (1 << 4),	///< detect render engine from document
} MAXON_ENUM_FLAGS(GENERATESCENEPREVIEWIMAGEFLAGS);

enum class OPENSAVEASSETDIALOGFLAGS
{
	NONE = 0,
	ALLOW_EDIT_ID = (1 << 0),				 ///< enabled the editfield of the assset id to allow the user editing of the id.
	ALLOW_EDIT_NAME = (1 << 1),			 ///< allows to edit the name of the asset
	SHOW_VERSION = (1 << 2),				 ///< shows the version edit field to let the user enter a version name
	ALLOW_EMPTY_CATEGORY = (1 << 3), ///< set to allow to clear the category (make it blank). otherwise the user needs to choose a category.
	SHOW_MAKE_DEFAULT = (1 << 4),		 ///< enabled the "make as default" checkbox for presets.
} MAXON_ENUM_FLAGS(OPENSAVEASSETDIALOGFLAGS);

using DescCompareEntry = Tuple<Bool, BaseContainer, DescID, maxon::String>;

//----------------------------------------------------------------------------------------
/// Helper interface for asset creation and drag&drop
//----------------------------------------------------------------------------------------
class AssetCreationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetCreationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.mvp.assetcreationinterface");

public:
	//----------------------------------------------------------------------------------------
	/// GetNewAssetIdFromIdAndVersion generates a standarized id from the given prefix and IdAndVersion for a new asset.
	/// @param[in] prefix							Prefix can be used for the type of the asset. e.g. "file" for file assets. preset for "presets".
	/// @param[in] idAndVersion				IdAndVersion of the asset to be created.
	/// @return                       Id on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> GetNewAssetIdFromIdAndVersion(const String& prefix, const IdAndVersion& idAndVersion);

	//----------------------------------------------------------------------------------------
	/// UpdateMetaData recalculates the asset metadata. For scene files this might be the number of points, polygons. etc. for images the size, bitdepth etc.
	/// @param[in] asset							Asset to be evaluated.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> UpdateMetaData(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// UpdateMetaData recalculates the asset metadata. For scene files this might be the number of points, polygons. etc. for images the size, bitdepth etc.
	/// @param[in] doc								BaseDocument to evaluate.
	/// @param[out] metaProperties		DataDictionary to store the data.
	/// @param[in] calcBoundingBox		True to calculate the bounding box of the scene.
	/// @param[in] objectMatrix				Optional matrix to add to the object.
	/// @param[in] subType						SubType of the asset, e.g. ASSETMETADATA::SubType_ENUM_Object.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> UpdateMetaData(BaseDocument* doc, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	//----------------------------------------------------------------------------------------
	/// SaveBaseDocumentAsAsset stores the given BaseDocument as a new scene to be saved as an asset. Dependencies will be calculated as well.
	/// @param[in] doc								BaseDocument to store.
	/// @param[in] c4dRootPath				Root of the document. This path is used to search textures/dependencies.
	/// @param[in,out] saveFileName		Destination path where the BaseDocument will be stored (this can be a memory file).
	/// @param[in,out] addDependencyStruct	AddAssetDepencendyStruct which is triggered on any dependency found.
	/// @param[in,out] resolveAssets	ResolveAssetDependenciesStruct keeps temporary data to resolve dependencies.
	/// @param[out] metaProperties		DataDictionary to store the data.
	/// @param[in] calcBoundingBox		True to calculate the bounding box of the scene.
	/// @param[in] objectMatrix				Optional matrix to add to the object.
	/// @param[in] subType						SubType of the asset, e.g. ASSETMETADATA::SubType_ENUM_Object.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> SaveBaseDocumentAsAsset(BaseDocument* doc, const Filename& c4dRootPath, Filename& saveFileName, AddAssetDepencendyStruct& addDependencyStruct, ResolveAssetDependenciesStruct& resolveAssets, DataDictionary& metaProperties, Bool calcBoundingBox, const Matrix& objectMatrix, const Id& subType);

	//----------------------------------------------------------------------------------------
	/// SaveMemFileAsAssetWithCopyAsset stores the given url as a asset.
	/// @param[in] depResultUrl				Url of the asset to store.
	/// @param[in] storeAssetStruct		see StoreAssetStruct.
	/// @param[in] subType						SubType of the asset, e.g. ASSETMETADATA::SubType_ENUM_Object.
	/// @param[in] dependencies				Dependencies to store with the assets.
	/// @param[in] assetName					User readable name of the asset.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       Tuple<AssetDescription, Bool> on success. AssetDescription contains the new asset description, Bool is true if the asset is a new asset. False if the asset already existed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<AssetDescription, Bool>> SaveMemFileAsAssetWithCopyAsset(const Url& depResultUrl, const StoreAssetStruct& storeAssetStruct, const InternedId& subType, const HashSet<AssetDependencyStruct>& dependencies, const String& assetName, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// SaveMemFileAsAsset stores the given url as a asset into a temporary repository. 
	/// @param[in] saveFileName				Url of the asset to be stored.
	/// @param[in] parentCategory			Parent category in which the asset should be saved.
	/// @param[in] subType						SubType of the asset, e.g. ASSETMETADATA::SubType_ENUM_Object.
	/// @param[in] calculateMetaData	True to automatically calculate meta data when saving.
	/// @param[in] metaProperties			Additional metadata to store.
	/// @param[in] dependencies				Dependencies to store with the asset.
	/// @param[in] previews						Array images of Previews. If you pass more then one image it will be stored as animated mp4 with the given animFps frame rate.
	/// @param[in] animFps						If more than one image was given the preview will be stored as mp4 wih this frame rate.
	/// @param[in] assetName					User readable name of the asset.
	/// @param[in] localizedNames			Optional translated names of the asset in other languages. Id is the languageid from LanguageInterface.
	/// @param[in] localizedAnnotations Optional translated descriptions of the asset in other languages. Id is the languageid from LanguageInterface.
	/// @param[in] copyMetaData				Metadata to copy.
	/// @return                       Tuple<AssetDescription, UpdatableAssetRepositoryRef> on success. AssetDescription of the new asset. UpdatableAssetRepositoryRef is a new temporary repository from which the asset can be moved into the target repository.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAsset(const Url& saveFileName, const Id& parentCategory, const InternedId& subType,
		Bool calculateMetaData, const DataDictionary& metaProperties, const HashSet<AssetDependencyStruct>& dependencies,
		const BaseArray<Url>& previews, Float animFps, const String& assetName, const HashMap<Id, String>& localizedNames,
		const HashMap<Id, String>& localizedAnnotations, const AssetMetaData& copyMetaData);

	//----------------------------------------------------------------------------------------
	/// SaveMemFileAsAssetAlone stores the plain file into a temporary repository.
	/// @param[in] saveFileName				Url of the asset to be stored.
	/// @param[in] copyMetaData				Optional meta data to copy.
	/// @return                       Tuple<AssetDescription, UpdatableAssetRepositoryRef> on success. AssetDescription of the new asset. UpdatableAssetRepositoryRef is a new temporary repository from which the asset can be moved into the target repository.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<AssetDescription, UpdatableAssetRepositoryRef>> SaveMemFileAsAssetAlone(const Url& saveFileName, const AssetMetaData& copyMetaData);

	//----------------------------------------------------------------------------------------
	/// SaveMetaDataForAsset stores he given values into the asset description.
	/// @param[in] asset							Asset to be modified.
	/// @param[in] parentCategory			Optional value to set the category of the asset.
	/// @param[in] subType						Optional value to set the subType of the asset.
	/// @param[in] calculateMetaData	True to automatically calculate the meta data for known sybTypes.
	/// @param[in] metaProperties			Additional metaData to store.
	/// @param[in] dependencies				Dependencies to store along with the asset.
	/// @param[in] previews						Array images of Previews. If you pass more then one image it will be stored as animated mp4 with the given animFps frame rate.
	/// @param[in] animFps						If more than one image was given the preview will be stored as mp4 wih this frame rate.
	/// @param[in] assetName					User readable name of the asset.
	/// @param[in] localizedNames			Optional translated names of the asset in other languages. Id is the languageid from LanguageInterface.
	/// @param[in] localizedAnnotations Optional translated descriptions of the asset in other languages. Id is the languageid from LanguageInterface.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SaveMetaDataForAsset(const AssetDescription& asset, const Id& parentCategory, const InternedId& subType, Bool calculateMetaData, const DataDictionary& metaProperties, const HashSet<AssetDependencyStruct>& dependencies, const BaseArray<Url>& previews, Float animFps, const String& assetName, const HashMap<Id, String>& localizedNames, const HashMap<Id, String>& localizedAnnotations);

	//----------------------------------------------------------------------------------------
	/// SaveDocumentAsset stores the given BaseDocument into the given repository.
	/// @param[in] assetDoc						BaseDocument to store.
	/// @param[in] subType						Optional value to set the subType of the asset.
	/// @param[in] newAssetId					Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetName					User readable name of the asset.
	/// @param[in] versionString			User readable version string.
	/// @param[in] createPreviewBitmapDelegate	Optional delegate to generate a preview preview bitmap when saving the asset.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       AssetDescription of the new asset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> SaveDocumentAsset(BaseDocument* assetDoc, InternedId subType, Id newAssetId, const StoreAssetStruct& storeAssetStruct, const String& assetName, const String& versionString, const Delegate<Result<BaseBitmap*>()>& createPreviewBitmapDelegate, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// SaveTextureAsset stores the given image as media asset.
	/// @param[in] imageUrl						Url of the texture to store.
	/// @param[in] assetName					Human readable asset name.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] dependencies				Optional dependencies to store along with the asset.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       Tuple<AssetDescription, Bool> on success. AssetDescription of the new asset. Bool is true if the asset was saved. False if it was already in the repository. In that case the AssetDescription is the one of the existing asset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<AssetDescription, Bool>> SaveTextureAsset(const Url& imageUrl, const String& assetName, const StoreAssetStruct& storeAssetStruct, const HashSet<AssetDependencyStruct>& dependencies, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// GenerateImagePreview generates a preview image for a given texture.
	/// @param[in] imageUrl						Url of the texture.
	/// @param[out] previews					ValueReceiver which receives the preview.
	/// @param[in] previewW						Preview width.
	/// @param[in] previewH						Preview height.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GenerateImagePreview(const Url& imageUrl, const ValueReceiver<const Url&>& previews, Int32 previewW, Int32 previewH);

	//----------------------------------------------------------------------------------------
	/// GenerateScenePreviewImage generates the preview image of the given BaseDocument
	/// @param[in] doc								BaseDocument to preview.
	/// @param[out] preview						BaseBitmap into which the preview should be rendered.
	/// @param[in] flags							see GENERATESCENEPREVIEWIMAGEFLAGS.
	/// @param[in] previewW						Preview width.
	/// @param[in] previewH						Preview height.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GenerateScenePreviewImage(BaseDocument* doc, BaseBitmap* preview, GENERATESCENEPREVIEWIMAGEFLAGS flags, Int32 previewW, Int32 previewH);

	//----------------------------------------------------------------------------------------
	/// CreateMaterialAsset creates a material asset from the given BaseMaterial.
	/// @param[in] activeDoc					BaseDocument of the material to store. This document will be used to find dependencies.
	/// @param[in] mat								BaseMaterial to store.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetId						Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] assetName					Human readable name of the asset.
	/// @param[in] assetVersion				Human readable version string.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> CreateMaterialAsset(BaseDocument* activeDoc, BaseMaterial* mat, const StoreAssetStruct& storeAssetStruct,
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// CreateObjectAsset description.
	/// @param[in] op									BaseObject to store.
	/// @param[in] activeDoc					BaseDocument of the material to store. This document will be used to find dependencies.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetId						Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] assetName					Human readable name of the asset.
	/// @param[in] assetVersion				Human readable version string.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> CreateObjectAsset(BaseObject* op, BaseDocument* activeDoc, const StoreAssetStruct& storeAssetStruct,
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// CreateSceneAsset description.
	/// @param[in] activeDoc					BaseDocument to store. This document will be used to find dependencies.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetId						Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] assetName					Human readable name of the asset.
	/// @param[in] assetVersion				Human readable version string.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> CreateSceneAsset(BaseDocument* activeDoc, const StoreAssetStruct& storeAssetStruct,
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// SaveActiveDocumentAsNewVersion writes the current BaseDocument as new version with asset dialog.
	/// @param[in] activeDoc					Basedocument to store.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> SaveActiveDocumentAsNewVersion(BaseDocument* activeDoc, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// CreateObjectsOnDrag helper function to create assets when d&d into a scene/viewport.
	/// @param[in] doc								BaseDocument to insert the asset.
	/// @param[in] url								Url of the d&d operation. This is typically an asset url "asset:///..."
	/// @param[in] asset							AssetDescription of the asset.
	/// @param[in] allowPreviewCube		True to indicate that a preview cube should be inserted instead of the real geometry.
	/// @param[in] overwriteMatrix		True to overwrite the overwriteMatrixMg.
	/// @param[in] overwriteMatrixMg	Overwrite the matrix with this value.
	/// @param[in] placementScale			Additional scale factor.
	/// @param[in] parent							Parent object to insert.
	/// @param[in] prev								Previous object to insert.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	// #LEGACYCOMPATIBILITY remove overload
	static MAXON_METHOD Result<void> CreateObjectsOnDrag(BaseDocument* doc, const Url& url, const AssetDescription& asset, Bool allowPreviewCube, Bool overwriteMatrix, const Matrix& overwriteMatrixMg, Float placementScale, BaseObject* parent = nullptr, BaseObject* prev = nullptr);

	//----------------------------------------------------------------------------------------
	/// CreateObjectsOnDrag helper function to create assets when d&d into a scene/viewport.
	/// @param[in] doc								BaseDocument to insert the asset.
	/// @param[in] url								Url of the d&d operation. This is typically an asset url "asset:///..."
	/// @param[in] asset							AssetDescription of the asset.
	/// @param[in] filterString				Filter string of the d&d operation. This allows to switch the search term e.g. sphere / cube on a modeling node.
	/// @param[in] allowPreviewCube		True to indicate that a preview cube should be inserted instead of the real geometry.
	/// @param[in] overwriteMatrix		True to overwrite the overwriteMatrixMg.
	/// @param[in] overwriteMatrixMg	Overwrite the matrix with this value.
	/// @param[in] placementScale			Additional scale factor.
	/// @param[in] parent							Parent object to insert.
	/// @param[in] prev								Previous object to insert.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CreateObjectsOnDrag(BaseDocument* doc, const Url& url, const AssetDescription& asset, const String& filterString, Bool allowPreviewCube, Bool overwriteMatrix, const Matrix& overwriteMatrixMg, Float placementScale, BaseObject* parent = nullptr, BaseObject* prev = nullptr);

	//----------------------------------------------------------------------------------------
	/// CheckObjectsOnDrop helper function to add objects into the scene from the asset browser. This functions keeps a list of assets and remembers if they were added already.
	/// @param[in] doc								BaseDocument to insert the asset.
	/// @param[in] url								Url of the d&d operation. This is typically an asset url "asset:///..."
	/// @param[in] asset							AssetDescription of the asset.
	/// @param[in] placementScale			Additional scale factor.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CheckObjectsOnDrop(BaseDocument* doc, const Url& url, const AssetDescription& asset, Float placementScale);

	//----------------------------------------------------------------------------------------
	/// CreateMaterialsOnDrag description.
	/// @param[in] doc								BaseDocument to insert the asset.
	/// @param[in] objectOrTag				Drop destination.
	/// @param[in] url								Url of the d&d operation. This is typically an asset url "asset:///..."
	/// @param[in] allowMultiple			True to insert multiple materials at the same time.
	/// @param[in] subType						Subtype of the asset.
	/// @param[in] noManagerUpdate		True to prevent attribute manager updates when activating the new objects.
	/// @param[in] startUndo					True to call doc->StartUndo() and EndUndo().
	/// @return                       Array with the newly created BaseMaterials on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<BaseMaterial*>> CreateMaterialsOnDrag(BaseDocument* doc, BaseList2D* objectOrTag, const Url& url, Bool allowMultiple, const Id& subType, Bool noManagerUpdate, Bool startUndo);

	//----------------------------------------------------------------------------------------
	/// AddPreviewRenderAsset adds the given assets to the background render queue.
	/// @param[in] assetsToPreviewRender	Assets to add to the render queue.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddPreviewRenderAsset(const Block<AssetDescription>& assetsToPreviewRender);

	//----------------------------------------------------------------------------------------
	/// OpenSaveAssetDialog opens the save asset dialog.
	/// @param[in] flags							see OPENSAVEASSETDIALOGFLAGS.
	/// @param[in] presetTypeName			Asset Type name to create the dialog title.
	/// @param[in,out] id							Id of the asset.
	/// @param[in,out] name						Asset name.
	/// @param[in,out] version				Version string.
	/// @param[in] lookupRepository		Repository to search for assets.
	/// @param[in,out] category				Category in which the asset should be stored.
	/// @param[in,out] selectedRepository	Selected repository where the asset should be stored.
	/// @param[in,out] setAsDefault		True to set the preset as default.
	/// @return                       True on success and dialog okay. False if user canceled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OpenSaveAssetDialog(OPENSAVEASSETDIALOGFLAGS flags, const String& presetTypeName, Id& id, String& name, String& version, const AssetRepositoryRef& lookupRepository, Id& category, AssetRepositoryRef& selectedRepository, Bool &setAsDefault);

	//----------------------------------------------------------------------------------------
	/// RenderDocumentAsset helper function to render a BaseDocument for preview rendering.
	/// @param[in] renderDoc				BaseDocument to render.
	/// @param[in] progressRef			progress class.
	/// @param[in] progressIndex		progress index to use.
	/// @param[in] polygonCount			Number of polygons in the scene. If -1 the count will be calculated. If the count == 0 and the scene has one first object the icon of the object is used as preview.
	/// @param[in] previewW						Preview width.
	/// @param[in] previewH						Preview height.
	/// @param[in] flags							see GENERATESCENEPREVIEWIMAGEFLAGS.
	/// @return                       OK on success.
	/// @MAXON_ANNOTATION{methodId="RenderDocumentAsset@8c5ff3cae2739fbf"->"RenderDocumentAsset@68aa959347a27cc7"}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> RenderDocumentAsset(BaseDocument* renderDoc, const ProgressRef& progressRef, Int progressIndex, Int polygonCount, Int32 previewW, Int32 previewH, GENERATESCENEPREVIEWIMAGEFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// GetAddDependencyDelegate helepr function to generate the ResolveAssetDependenciesStruct::ResolveDelegate.
	/// @param[in] documentPath				Root Path of the document.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @return                       ResolveAssetDependenciesStruct::ResolveDelegate on success to be used in functions where it is required.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ResolveAssetDependenciesStruct::ResolveDelegate> GetAddDependencyDelegate(const Filename& documentPath, Bool addAssetsIfNotInThisRepository);

	//----------------------------------------------------------------------------------------
	/// GetDefaultSettings loads the settings for a preset
	/// @param[in] asset							Asset to load.
	/// @param[out] resId							BaseList Ids of the preset.
	/// @param[out] resData						Settings Container.
	/// @return                       True means a partial preset was loaded.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool GetDefaultSettings(const AssetDescription& asset, Block<const Int32>& resId, BaseContainer& resData);

	//----------------------------------------------------------------------------------------
	/// GetDefaultObject returns a new default object for the given preset type.
	/// @param[in] id									Ids of the BaseObject. e.g. Ocube
	/// @param[in] doc								BaseDocument to look for the scene repository.
	/// @return                       New BaseList2D on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BaseList2D* GetDefaultObject(const Block<const Int32>& id, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// GetDefaultObject returns a new default object for the given preset.
	/// @param[in] asset							Asset to load.
	/// @return                       New BaseList2D on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BaseList2D* GetDefaultObject(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// SetDefaultObject description.
	/// @param[in] defaultsType				Ids of the BaseObject. e.g. Ocube
	/// @param[in] partial						True to signal that this preset contains only partial settings.
	/// @param[in] bc									BaseContainer with the settings.
	/// @param[in] setAsDefault				True to make this preset the default when creating new objects.
	/// @param[in] allowMakeDefault		True to enable the "Make as default" checkbox in the dialog.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SetDefaultObject(const Block<const Int32>& defaultsType, Bool partial, const BaseContainer& bc, Bool setAsDefault, Bool allowMakeDefault);

	//----------------------------------------------------------------------------------------
	/// BrowseDescriptionForDefaults is a helper function to browse through Descriptions to collect all attributes to be stored in a preset.
	/// @param[in] desc								Description to browse.
	/// @param[in] add								delegate which is triggered for each attribute.
	/// @param[in] isPartial					True if this should be a partial preset. In that case DESC_UNIMPORTANTFORDEFAULTS will be ignored.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BrowseDescriptionForDefaults(Description& desc, const Delegate<Result<void>(const DescID& key, DescCompareEntry&& value)>& add, Bool isPartial);

	//----------------------------------------------------------------------------------------
	/// SaveDefaultPresetFromObject stores the default from the given object into the asset browser.
	/// @param[in] l									Object to store.
	/// @param[in] makeDefault				True to make it the default.
	/// @param[in] allowMakeDefault		True to enable the "Make as default" checkbox in the dialog.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SaveDefaultPresetFromObject(GeListNode* l, Bool makeDefault, Bool allowMakeDefault = true);

	//----------------------------------------------------------------------------------------
	/// SaveBrowserPreset stores the given data as preset asset.
	/// @param[in] assetType					PresetType.
	/// @param[in] sourceData					Data to store.
	/// @param[in] presetTypeName			Present Type name to generate the dialog title for.
	/// @param[in] presetNameA				Name of the Preset.
	/// @param[in] showMakeDefault		True to enable the "Make as default" checkbox in the dialog.
	/// @param[in] setAsDefault				True to make it the default.
	/// @param[in] allowSceneRepository True to allow to stor the preset into the scene repository.
	/// @return                       AssetDescription of the newly created asset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> SaveBrowserPreset(const BasePresetAssetType& assetType, const PresetSaveArgs& sourceData, const String& presetTypeName, const String& presetNameA, Bool showMakeDefault, Bool setAsDefault, Bool allowSceneRepository);

	//----------------------------------------------------------------------------------------
	/// SupportDefaultPresets helper function to find if the given type supports the preset system.
	/// @param[in] l									Object to check
	/// @return                       Tuple<Bool, Bool>: first - support presets, second - support set as default 
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Bool, Bool> SupportDefaultPresets(C4DAtomGoal* l);

	//- R26 ----------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	/// SaveDocumentAsset stores the given BaseDocument into the given repository.
	/// @param[in] assetDoc						BaseDocument to store.
	/// @param[in] subType						Optional value to set the subType of the asset.
	/// @param[in] newAssetId					Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetName					User readable name of the asset.
	/// @param[in] versionString			User readable version string.
	/// @param[in] createPreviewBitmapDelegate	Optional delegate to generate a preview preview bitmap when saving the asset.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @param[in,out] resolveAssets	ResolveAssetDependenciesStruct keeps temporary data to resolve dependencies.
	/// @return                       AssetDescription of the new asset on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> SaveDocumentAsset(BaseDocument* assetDoc, InternedId subType, Id newAssetId, const StoreAssetStruct& storeAssetStruct, const String& assetName, const String& versionString, const Delegate<Result<BaseBitmap*>()>& createPreviewBitmapDelegate, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository, ResolveAssetDependenciesStruct& resolveAssets);

	//----------------------------------------------------------------------------------------
	/// CreateObjectAsset description.
	/// @param[in] op									BaseObject to store.
	/// @param[in] activeDoc					BaseDocument of the material to store. This document will be used to find dependencies.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetId						Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] assetName					Human readable name of the asset.
	/// @param[in] assetVersion				Human readable version string.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @param[in,out] resolveAssets	ResolveAssetDependenciesStruct keeps temporary data to resolve dependencies.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> CreateObjectAsset(BaseObject* op, BaseDocument* activeDoc, const StoreAssetStruct& storeAssetStruct,
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository, ResolveAssetDependenciesStruct& resolveAssets);

	//----------------------------------------------------------------------------------------
	/// CreateMaterialAsset creates a material asset from the given BaseMaterial.
	/// @param[in] activeDoc					BaseDocument of the material to store. This document will be used to find dependencies.
	/// @param[in] mat								BaseMaterial to store.
	/// @param[in] storeAssetStruct		Settings where to store the asset.
	/// @param[in] assetId						Optional asset Id. If empty the system calculates a new asset id.
	/// @param[in] assetName					Human readable name of the asset.
	/// @param[in] assetVersion				Human readable version string.
	/// @param[in] copyMetaData				Optional meta data to copy from another version.
	/// @param[in] addAssetsIfNotInThisRepository True to store the asset in the given saveRepository even if it's already in any other repository. False would skip the writing.
	/// @param[in,out] resolveAssets	ResolveAssetDependenciesStruct keeps temporary data to resolve dependencies.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> CreateMaterialAsset(BaseDocument* activeDoc, BaseMaterial* mat, const StoreAssetStruct& storeAssetStruct,
		const Id& assetId, const String& assetName, const String& assetVersion, const AssetMetaData& copyMetaData, Bool addAssetsIfNotInThisRepository, ResolveAssetDependenciesStruct& resolveAssets);
};

#include "asset_creation1.hxx"
#include "asset_creation2.hxx"

} // namespace maxon


#endif // ASSET_CREATION_H__
