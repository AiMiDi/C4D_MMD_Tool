#ifndef BASE_PRESET_ASSET_H__
#define BASE_PRESET_ASSET_H__

#include "maxon/assets.h"

// forward declaration for old conversion stuff
class BaseContainer;

namespace maxon
{

class MediaSessionProgressRef;

using AddAssetMetaData = HashMap<InternedId, Tuple<Data, AssetMetaDataInterface::KIND>>;

class StoreAssetStruct
{
public:
	StoreAssetStruct(const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository)
		: _parentCategory(parentCategory),
			_saveRepository(saveRepository),
			_lookupRepository(lookupRepository)
	{
	}
	StoreAssetStruct(){}

public:
	Id								 _parentCategory;
	AssetRepositoryRef _saveRepository;
	AssetRepositoryRef _lookupRepository;
};

MAXON_DATATYPE(StoreAssetStruct, "net.maxon.datatype.storeassetstruct");

class ResolveAssetDependenciesStruct
{
public:
	using Map = HashMap<Url, Id>;

	using ResolveDelegate = Delegate<Result<Id>(const Url& depUrl, const StoreAssetStruct& storeAssetStruct, ResolveAssetDependenciesStruct& resolveAssetStruct)>;

public:
	ResolveDelegate _resolveAssetDelegate;
	Map			 _resolvedMap;
};


class AddAssetDepencendyStruct : public StoreAssetStruct
{
public:
	AddAssetDepencendyStruct(const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository)
		: StoreAssetStruct(parentCategory, saveRepository, lookupRepository)
	{
	}
	
	//----------------------------------------------------------------------------------------
	/// AddDependency adds a dependency using the AssetDependencyStruct.
	/// @param[in] assetDependency		Dependencies to add.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AddDependency(AssetDependencyStruct&& assetDependency);

	//----------------------------------------------------------------------------------------
	/// AddDependency adds the given asset as dependency.
	/// @param[in] depAsset						Asset to add.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AddDependency(const AssetDescription& depAsset);

	//----------------------------------------------------------------------------------------
	/// AddDependency description.
	/// @param[in] depAssetId					?
	/// @return                       AssetDescription if asset could be found in the lookuprepository. nullptr if asset was not found. otherwise error.
	//----------------------------------------------------------------------------------------
	Result<AssetDescription> AddDependency(const Id& depAssetId);

	//----------------------------------------------------------------------------------------
	/// GetDependencies returns the collected dependencies.
	//----------------------------------------------------------------------------------------
	const HashSet<AssetDependencyStruct>& GetDependencies() const;

private:
	HashSet<AssetDependencyStruct> _dependencies;
};

class PresetLoadArgs : public DataDictionary
{
public:
	PresetLoadArgs();

	PresetLoadArgs(const PresetLoadArgs& src);

	Result<void> SetPointer(void* pointer);
	void* GetPointer() const;

	Result<void> SetType(Int type);
	Int GetType() const;
};


class PresetSaveArgs : public DataDictionary
{
public:
	PresetSaveArgs() { }

	PresetSaveArgs(const PresetSaveArgs& src);

	explicit PresetSaveArgs(void* rawptr, Int type = 0);

	void* GetPointer() const;

	Int GetType() const;
};


class BasePresetAsset;
class CreatePresetAssetStruct;

//----------------------------------------------------------------------------------------
/// BasePresetAssetTypeInterface defines a new preset type and is the connector to BasePresetAssetInterface
//----------------------------------------------------------------------------------------
class BasePresetAssetTypeInterface : MAXON_INTERFACE_BASES(AssetTypeInterface)
{
	MAXON_INTERFACE(BasePresetAssetTypeInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.basepresetassettype");

public:
	MAXON_METHOD String GetName() const;

	MAXON_METHOD Bool LoadPreset(const BasePresetAsset& preset, const PresetLoadArgs& target) const;

	MAXON_METHOD Result<void> CreateNewPresetSettings(CreatePresetAssetStruct& args) const;

	MAXON_METHOD String GetFilterString() const;
};

//----------------------------------------------------------------------------------------
/// BasePresetAssetInterface allows to implement details for preset assets.
//----------------------------------------------------------------------------------------
class BasePresetAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(BasePresetAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.asset.preset.base");

public:
	MAXON_METHOD Result<void> Apply() const;

	MAXON_METHOD Result<Url> GeneratePreview(Int previewSize, const MediaSessionProgressRef& progressRef, Int progressIndex) const;

	MAXON_METHOD Result<void> ConvertFromLegacyBrowser(Int32 pluginId, const Block<const Char>& memBlock, const BaseContainer& settings, const String& name, DataDictionary& metaProperties, AddAssetMetaData& additionalMetaData, AddAssetDepencendyStruct& addDependencyStruct, ResolveAssetDependenciesStruct& resolveAssets);

	MAXON_METHOD Result<void> Serialize(const OutputStreamRef& outputStream) const;
};

static constexpr LiteralId PRESET_DEFAULT_CATEGORY = LiteralId("category@2468666d866a481886c91c7155440264");

#define C4DSUBTYPEPREFIX "net.maxon.subtype.preset.~."_cs
#define C4DSUBTYPEEXCHANGE "net.maxon.subtype.preset.exchange."_cs

#include "base_preset_asset1.hxx"

//----------------------------------------------------------------------------------------
/// This base component can be used by implementations of AssetType.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<BasePresetAssetType>, AssetTypeBasePresetClass, "net.maxon.class.assettypepresetbase");

namespace AssetTypes
{
	MAXON_DECLARATION(BasePresetAssetType, ColorSwatchPreset, "net.maxon.assettype.preset.colorswatch");
	MAXON_DECLARATION(BasePresetAssetType, DisplayFilterPreset, "net.maxon.assettype.preset.displayfilter");
	MAXON_DECLARATION(BasePresetAssetType, DocumentPreset, "net.maxon.assettype.preset.document");
	MAXON_DECLARATION(BasePresetAssetType, CapsAndBevelPreset, "net.maxon.assettype.preset.capsandbevel");
	MAXON_DECLARATION(BasePresetAssetType, GradientPreset, "net.maxon.assettype.preset.gradient");
	MAXON_DECLARATION(BasePresetAssetType, RenderSettingsPreset, "net.maxon.assettype.preset.rendersettings");
	MAXON_DECLARATION(BasePresetAssetType, VideoPostPreset, "net.maxon.assettype.preset.videopost");
	MAXON_DECLARATION(BasePresetAssetType, SplinePreset, "net.maxon.assettype.preset.spline");
	MAXON_DECLARATION(BasePresetAssetType, UserDataPreset, "net.maxon.assettype.preset.userdata");
	MAXON_DECLARATION(BasePresetAssetType, TimelineDefinitionPreset, "net.maxon.assettype.preset.timelinedefinition");
	MAXON_DECLARATION(BasePresetAssetType, TakePreset, "net.maxon.assettype.preset.take");
	MAXON_DECLARATION(BasePresetAssetType, IconChooserPreset, "net.maxon.assettype.preset.iconchooser");
	MAXON_DECLARATION(BasePresetAssetType, SketchPreset, "net.maxon.assettype.preset.sketch");
	MAXON_DECLARATION(BasePresetAssetType, CharacterDefinitionPreset, "net.maxon.assettype.preset.characterdefinition");
	MAXON_DECLARATION(BasePresetAssetType, ExchangeSettingsPreset, "net.maxon.assettype.preset.exchangesettings");
	MAXON_DECLARATION(BasePresetAssetType, SkyPreset, "net.maxon.assettype.preset.skypreset");
	MAXON_DECLARATION(BasePresetAssetType, SkyWeatherPreset, "net.maxon.assettype.preset.skyweather");
	MAXON_DECLARATION(BasePresetAssetType, SkyLayerPreset, "net.maxon.assettype.preset.skylayer");
	MAXON_DECLARATION(BasePresetAssetType, RenderQueuePreset, "net.maxon.assettype.preset.renderqueue");
	MAXON_DECLARATION(BasePresetAssetType, MotionSequencePreset, "net.maxon.assettype.preset.motionsequence");
	MAXON_DECLARATION(BasePresetAssetType, PictureViewerPreset, "net.maxon.assettype.preset.pictureviewer");
	MAXON_DECLARATION(BasePresetAssetType, SculptBrushPreset, "net.maxon.assettype.preset.sculptbrush");
	MAXON_DECLARATION(BasePresetAssetType, SculptStencilPreset, "net.maxon.assettype.preset.sculptstencil");
	MAXON_DECLARATION(BasePresetAssetType, SculptStampPreset, "net.maxon.assettype.preset.sculptstamp");
	MAXON_DECLARATION(BasePresetAssetType, SculptSplinePreset, "net.maxon.assettype.preset.sculptspline");
	MAXON_DECLARATION(BasePresetAssetType, BPBrushPreset, "net.maxon.assettype.preset.bpbrush");
	MAXON_DECLARATION(BasePresetAssetType, BPColorPreset, "net.maxon.assettype.preset.bpcolor");
	MAXON_DECLARATION(BasePresetAssetType, BPGradientPreset, "net.maxon.assettype.preset.bpgradient");
	MAXON_DECLARATION(BasePresetAssetType, DefaultsPreset, "net.maxon.assettype.preset.defaults");
};

namespace PresetAssetImplementations
{
	MAXON_DECLARATION(Class<BasePresetAsset>, DocumentPresetClass, "net.maxon.class.asset.preset.document");
	MAXON_DECLARATION(Class<BasePresetAsset>, GradientPresetClass, "net.maxon.class.asset.preset.gradient");
	MAXON_DECLARATION(Class<BasePresetAsset>, ColorSwatchPresetClass, "net.maxon.class.asset.preset.colorswatch");
	MAXON_DECLARATION(Class<BasePresetAsset>, RenderSettingsPresetClass, "net.maxon.class.asset.preset.rendersettings");
	MAXON_DECLARATION(Class<BasePresetAsset>, VideoPostPresetClass, "net.maxon.class.asset.preset.videopost");
	MAXON_DECLARATION(Class<BasePresetAsset>, CapsAndBevelPresetClass, "net.maxon.class.asset.preset.capsandbevel");
	MAXON_DECLARATION(Class<BasePresetAsset>, DisplayFilterPresetClass, "net.maxon.class.asset.preset.displayfilter");
	MAXON_DECLARATION(Class<BasePresetAsset>, SplinePresetClass, "net.maxon.class.asset.preset.spline");
	MAXON_DECLARATION(Class<BasePresetAsset>, UserDataPresetClass, "net.maxon.class.asset.preset.userdata");
	MAXON_DECLARATION(Class<BasePresetAsset>, TimelineDefinitionPresetClass, "net.maxon.class.asset.preset.timelinedefinition");	
	MAXON_DECLARATION(Class<BasePresetAsset>, TakePresetClass, "net.maxon.class.asset.preset.take");
	MAXON_DECLARATION(Class<BasePresetAsset>, IconChooserPresetClass, "net.maxon.class.asset.preset.iconchooser");
	MAXON_DECLARATION(Class<BasePresetAsset>, SketchPresetClass, "net.maxon.class.asset.preset.sketch");
	MAXON_DECLARATION(Class<BasePresetAsset>, CharacterDefinitionPresetClass, "net.maxon.class.asset.preset.characterdefinition");
	MAXON_DECLARATION(Class<BasePresetAsset>, ExchangeSettingsPresetClass, "net.maxon.class.asset.preset.exchangesettings");
	MAXON_DECLARATION(Class<BasePresetAsset>, SkyPresetClass, "net.maxon.class.asset.preset.skypreset");
	MAXON_DECLARATION(Class<BasePresetAsset>, SkyWeatherPresetClass, "net.maxon.class.asset.preset.skyweather");
	MAXON_DECLARATION(Class<BasePresetAsset>, SkyLayerPresetClass, "net.maxon.class.asset.preset.skylayer");
	MAXON_DECLARATION(Class<BasePresetAsset>, RenderQueuePresetClass, "net.maxon.class.asset.preset.renderqueue");
	MAXON_DECLARATION(Class<BasePresetAsset>, MotionSequencePresetClass, "net.maxon.class.asset.preset.motionsequence");
	MAXON_DECLARATION(Class<BasePresetAsset>, PictureViewerPresetClass, "net.maxon.class.asset.preset.pictureviewer");
	MAXON_DECLARATION(Class<BasePresetAsset>, SculptBrushPresetClass, "net.maxon.class.asset.preset.sculptbrush");
	MAXON_DECLARATION(Class<BasePresetAsset>, SculptStencilPresetClass, "net.maxon.class.asset.preset.sculptstencil");
	MAXON_DECLARATION(Class<BasePresetAsset>, SculptStampPresetClass, "net.maxon.class.asset.preset.sculptstamp");
	MAXON_DECLARATION(Class<BasePresetAsset>, SculptSplinePresetClass, "net.maxon.class.asset.preset.sculptspline");
	MAXON_DECLARATION(Class<BasePresetAsset>, BPBrushPresetClass, "net.maxon.class.asset.preset.bpbrush");
	MAXON_DECLARATION(Class<BasePresetAsset>, BPColorPresetClass, "net.maxon.class.asset.preset.bpcolor");	
	MAXON_DECLARATION(Class<BasePresetAsset>, BPGradientPresetClass, "net.maxon.class.asset.preset.bpgradient");	
	MAXON_DECLARATION(Class<BasePresetAsset>, DefaultsPresetClass, "net.maxon.class.asset.preset.defaults");
}

#include "base_preset_asset2.hxx"

class CreatePresetAssetStruct : public AddAssetDepencendyStruct
{
public:
	CreatePresetAssetStruct(const String& name, const PresetSaveArgs& sourceData, ResolveAssetDependenciesStruct::ResolveDelegate&& resolveDependenciesDelegate, const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository);

	Result<void> StoreMetaData(const InternedId& attr, ForwardingDataPtr&& data, AssetMetaDataInterface::KIND kind);

	/// @copydoc StoreMetaData
	template <typename ATTR> MAXON_FUNCTION Result<void> StoreMetaData(const ATTR& attr, typename ATTR::ValueType&& data, AssetMetaDataInterface::KIND kind)
	{
		return StoreMetaData(attr.Get(), MoveDataPtr(std::move(data)), kind);
	}

	/// @copydoc StoreMetaData
	template <typename ATTR> MAXON_FUNCTION Result<void> StoreMetaData(const ATTR& attr, const typename ATTR::ValueType& data, AssetMetaDataInterface::KIND kind)
	{
		return StoreMetaData(attr.Get(), ConstDataPtr(data), kind);
	}

public:
	// input arguments
	String											_name;
	PresetSaveArgs							_sourceData;

	// temp variables
	ResolveAssetDependenciesStruct _resolveAssets;

	// return values
	BasePresetAsset	 _resAsset;
	Url							 _resPreviewUrl;
	AddAssetMetaData _resMetaData;
};

}

#endif // BASE_PRESET_ASSET_H__
