#ifndef BASE_PRESET_ASSET_H__
#define BASE_PRESET_ASSET_H__

#include "maxon/assets.h"

// forward declaration for old conversion stuff
class BaseContainer;

namespace maxon
{

class ProgressRef;

using AddAssetMetaData = HashMap<InternedId, Tuple<Data, AssetMetaDataInterface::KIND>>;

//----------------------------------------------------------------------------------------
/// Allows to pass several arguments into asset creation functions.
//----------------------------------------------------------------------------------------
class StoreAssetStruct
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor of StoreAssetStruct.
	//----------------------------------------------------------------------------------------
	StoreAssetStruct()
	{
	}

	//----------------------------------------------------------------------------------------
	/// StoreAssetStruct description.
	/// @param[in] parentCategory			Parent category to set.
	/// @param[in] saveRepository			Repository to save into.
	/// @param[in] lookupRepository		Repository to look for dependencies.
	//----------------------------------------------------------------------------------------
	StoreAssetStruct(const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository)
		: _parentCategory(parentCategory),
			_saveRepository(saveRepository),
			_lookupRepository(lookupRepository)
	{
	}

public:
	Id								 _parentCategory;		///< Parent category to set.
	AssetRepositoryRef _saveRepository;		///< Repository to save into.
	AssetRepositoryRef _lookupRepository;	///< Repository to look for dependencies.
};

MAXON_DATATYPE(StoreAssetStruct, "net.maxon.datatype.storeassetstruct");

//----------------------------------------------------------------------------------------
/// Helper structure to store resolved asset dependencies.
//----------------------------------------------------------------------------------------
class ResolveAssetDependenciesStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ResolveAssetDependenciesStruct)

	// we need to use a case insensitive url hash, otherwise the conversion of old libs breaks
	// ITEM#376365 [ORC25] Textures aren't imported / paths converted for some legacy lib4d libraries
	struct ResolveUrlHash
	{
		static HashInt IsEqual(const Url& a, const Url& b)
		{
			return a.GetUrl().ToLower() == b.GetUrl().ToLower();
		}

		static HashInt GetHashCode(const Url& loc)
		{
			return MAXON_HASHCODE(loc.GetUrl().ToLower());
		}
	};

public:
	ResolveAssetDependenciesStruct() {};
	ResolveAssetDependenciesStruct(ResolveAssetDependenciesStruct&& src) = default;
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ResolveAssetDependenciesStruct);

	maxon::Result<void> CopyFrom(const ResolveAssetDependenciesStruct & src)
	{
		iferr_scope;
		_resolveAssetDelegate.CopyFrom(src._resolveAssetDelegate) iferr_return;
		_resolvedMap.CopyFrom(src._resolvedMap) iferr_return;

		return maxon::OK;
	}

	using Map = HashMap<Url, Id, ResolveUrlHash>;

	using ResolveDelegate = Delegate<Result<Id>(const Url& depUrl, const StoreAssetStruct& storeAssetStruct, ResolveAssetDependenciesStruct& resolveAssetStruct, Bool addMessage)>;

public:
	ResolveDelegate _resolveAssetDelegate;
	Map							_resolvedMap;
};

MAXON_DATATYPE(ResolveAssetDependenciesStruct, "net.maxon.datatype.resolveassetdependenciesstruct");
/// Helper class to pass additional data into asset creation functions.
//----------------------------------------------------------------------------------------
class AddAssetDepencendyStruct : public StoreAssetStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(AddAssetDepencendyStruct)
public:
	AddAssetDepencendyStruct() {};

	AddAssetDepencendyStruct(const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository)
		: StoreAssetStruct(parentCategory, saveRepository, lookupRepository)
	{
	}
	AddAssetDepencendyStruct(AddAssetDepencendyStruct&& src) = default;
	MAXON_OPERATOR_MOVE_ASSIGNMENT(AddAssetDepencendyStruct);

	maxon::Result<void> CopyFrom(const AddAssetDepencendyStruct& src)
	{
		iferr_scope;
		_dependencies.CopyFrom(src.GetDependencies()) iferr_return;
		return maxon::OK;
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
MAXON_DATATYPE(AddAssetDepencendyStruct, "net.maxon.datatype.addassetdepencendystruct");
//----------------------------------------------------------------------------------------
/// Helper class to pass arguments for loading presets into asset/preset implementations. The values are implementation specific.
//----------------------------------------------------------------------------------------
class PresetLoadArgs : public DataDictionary
{
public:
	//----------------------------------------------------------------------------------------
	/// PresetLoadArgs default constructor.
	//----------------------------------------------------------------------------------------
	PresetLoadArgs();

	//----------------------------------------------------------------------------------------
	/// PresetLoadArgs copy constructor.
	/// @param[in] src							data to copy.
	//----------------------------------------------------------------------------------------
	PresetLoadArgs(const PresetLoadArgs& src);

	//----------------------------------------------------------------------------------------
	/// SetPointer sets a pointer.
	/// @param[in] pointer						pointer to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetPointer(void* pointer);

	//----------------------------------------------------------------------------------------
	/// GetPointer returns the stored pointer.
	//----------------------------------------------------------------------------------------
	void* GetPointer() const;

	//----------------------------------------------------------------------------------------
	/// SetType sets the pointer type.
	/// @param[in] type								Type to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetType(Int type);

	//----------------------------------------------------------------------------------------
	/// GetType returns the type.
	//----------------------------------------------------------------------------------------
	Int GetType() const;
};

//----------------------------------------------------------------------------------------
/// Helper class to pass arguments for saving presets into asset/preset implementations. The values are implementation specific.
//----------------------------------------------------------------------------------------
class PresetSaveArgs : public DataDictionary
{
public:
	//----------------------------------------------------------------------------------------
	/// PresetSaveArgs default constructor.
	//----------------------------------------------------------------------------------------
	PresetSaveArgs() { }

	//----------------------------------------------------------------------------------------
	/// PresetSaveArgs copy constructor.
	/// @param[in] src								data to copy.
	//----------------------------------------------------------------------------------------
	PresetSaveArgs(const PresetSaveArgs& src);

	//----------------------------------------------------------------------------------------
	/// PresetSaveArgs sets the pointer and type.
	/// @param[in] rawptr							Pointer to set.
	/// @param[in] type								Type to set.
	//----------------------------------------------------------------------------------------
	explicit PresetSaveArgs(void* rawptr, Int type = 0);

	//----------------------------------------------------------------------------------------
	/// GetPointer returns the pointer.
	//----------------------------------------------------------------------------------------
	void* GetPointer() const;

	//----------------------------------------------------------------------------------------
	/// GetType returns the type.
	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	/// GetName returns the preset type name.
	/// @return                       Name of the preset type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// LoadPreset loads the preset into memory.
	/// @param[in] preset							Preset to load
	/// @param[in] target							Arguments to use when loading the preset.
	/// @return                       True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool LoadPreset(const BasePresetAsset& preset, const PresetLoadArgs& target) const;

	//----------------------------------------------------------------------------------------
	/// CreateNewPresetSettings creates the new preset of this type.
	/// @param[in] args								see CreatePresetAssetStruct.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateNewPresetSettings(CreatePresetAssetStruct& args) const;

	//----------------------------------------------------------------------------------------
	/// GetFilterString returns the default filter string to search for this asset type in the asset browser.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetFilterString() const;
};

//----------------------------------------------------------------------------------------
/// BasePresetAssetInterface allows to implement details for preset assets.
//----------------------------------------------------------------------------------------
class BasePresetAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(BasePresetAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.asset.preset.base");

public:
	//----------------------------------------------------------------------------------------
	/// Apply loads the asset/preset.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Apply() const;

	//----------------------------------------------------------------------------------------
	/// GeneratePreview implements the preview calculation of this preset type.
	/// @param[in] previewSize				Desired preview size.
	/// @param[in] progressRef				Progress object to use.
	/// @param[in] progressIndex			Progress Index to use.
	/// @return                       Image wrapped into a url on success.
	/// @MAXON_ANNOTATION{methodId="GeneratePreview@30e43d469de278b3"->"GeneratePreview@d62409d191fcc693"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GeneratePreview(Int previewSize, const ProgressRef& progressRef, Int progressIndex) const;

	//----------------------------------------------------------------------------------------
	/// ConvertFromLegacyBrowser implements the conversion from the old c4d content browser.
	/// @param[in] pluginId						Old c4d plugin id.
	/// @param[in] memBlock						Original browser data.
	/// @param[in] settings						Original browser settings.
	/// @param[in] name								Preset/Asset name.
	/// @param[in] metaProperties			Additional meta properties.
	/// @param[in] additionalMetaData	Additional meta data.
	/// @param[in] addDependencyStruct	Asset dependencies.
	/// @param[in] resolveAssets			Resolve asset helper struct.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConvertFromLegacyBrowser(Int32 pluginId, const Block<const Char>& memBlock, const BaseContainer& settings, const String& name, DataDictionary& metaProperties, AddAssetMetaData& additionalMetaData, AddAssetDepencendyStruct& addDependencyStruct, ResolveAssetDependenciesStruct& resolveAssets);

	//----------------------------------------------------------------------------------------
	/// Serialize implements the serialization of the data to disk.
	/// @param[in] outputStream				Stream to store the data.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------
/// Helper class to create a new preset asset.
//----------------------------------------------------------------------------------------
class CreatePresetAssetStruct : public AddAssetDepencendyStruct
{
public:
	//----------------------------------------------------------------------------------------
	/// CreatePresetAssetStruct description.
	/// @param[in] name								Name of the asset/preset.
	/// @param[in] sourceData					Source data to copy into the asset.
	/// @param[in] resolveDependenciesDelegate helper delegate to resolve dependencies.
	/// @param[in] parentCategory			Parent category to set.
	/// @param[in] saveRepository			Repository to save the asset in.
	/// @param[in] lookupRepository		Repository to search for dependencies.
	//----------------------------------------------------------------------------------------
	CreatePresetAssetStruct(const String& name, const PresetSaveArgs& sourceData, ResolveAssetDependenciesStruct::ResolveDelegate&& resolveDependenciesDelegate, const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository);

	//----------------------------------------------------------------------------------------
	/// StoreMetaData stores additional metadata for this preset.
	/// @param[in] attr								Attribute Id.
	/// @param[in] data								Data to store.
	/// @param[in] kind								Asset Kind.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
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
