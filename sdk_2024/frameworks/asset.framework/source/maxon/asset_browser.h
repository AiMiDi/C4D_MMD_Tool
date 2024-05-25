#ifndef ASSET_BROWSER_H__
#define ASSET_BROWSER_H__

#include "maxon/assets.h"
#include "maxon/lib_math.h"
#include "maxon/valuereceiver.h"

namespace maxon
{
enum class ASSETBROWSERMODE
{
	UNDEFINED = 0,		 // Undefined
	CATEGORIES,				 // Only categories are shown.
	ASSETS,						 // Only assets are shown. Tree should be provided with the categories of the nodes to be shown.
	KEYWORDSAVAILABLE, // Only tags are shown
	KEYWORDSASSIGNED,	 // assigned keywords of the selection
	VERSIONS,					 // Asset version only
	DEPENDENCIES,			 // Dependencies
	DEPENDANTS,				 // Dependents
	DATABASES,				 // Databases
} MAXON_ENUM_LIST(ASSETBROWSERMODE);

enum class ASSETGROUPBY
{
	UNDEFINED,
	CATEGORY,
	CREATIONDATE,
	USEDATE,
	USECOUNT,
	TYPE,
	DATABASE,
	NOTHING, // Special case: all asset appear in a single group. Group title will not be displayed. Only Sort by might apply and By Name by default.
	_MAX,
} MAXON_ENUM_LIST(ASSETGROUPBY);

enum class ASSETSORTBY
{
	UNDEFINED,
	NAME,
	MODIFICATION_DATE,
	CREATION_DATE,
	USEDATE,
	USE_COUNT,
	SIZE,
	RELEVANCE,
} MAXON_ENUM_LIST(ASSETSORTBY);

enum class ASSETSORTFIRST
{
	UNDEFINED,
	NONE,
	FAVORITES,					// Favorite items are shown as first items
	RELEVANT,						// Relevant items (e.g. materials when Material Manager is selected, etc.) are shown as first items
} MAXON_ENUM_LIST(ASSETSORTFIRST);

enum class ASSETSORTORDER
{
	NONE,
	ASCENDING,
	DESCENDING,
} MAXON_ENUM_LIST(ASSETSORTORDER);

enum class ASSETRELEVANCECONTEXT
{
	UNDEFINED, // Not defined.
	OBJECT_OM, // Focus is on Object Manager.
	OBJECT_VP, // Focus is on Viewport + Object selected + Model mode.
	MESH,			 // Focus is on Viewport + Editable mesh selected + Poly/Edge/Point mode.
	SPLINE,		 // Focus is on Viewport + Editable Spline selected + Point mode.
	MATERIAL,	 // Focus is on Material Manager.
	UV_EDITOR, // Focus is on Texture UV Editor.
	UV_VP,		 // Focus is on Viewport + Object selected + UV mode.
	NODE,			 // Focus is on Node editor.
	OTHER			 // Remaining focus.
} MAXON_ENUM_LIST(ASSETRELEVANCECONTEXT);

enum class REPOSITORYSTATE
{
	NONE				= 0,
	INTERNAL		= 1 << 0,
	MOUNTED			= 1 << 1,
	READONLY		= 1 << 2,
	DATABASE    = 1 << 3,
	WATCHFOLDER	= 1 << 4,
	ONLINE			= 1 << 5,
	COMPACTABLE = 1 << 6,
	ACTIVE			= 1 << 7,
	ERROR				= 1 << 8,
} MAXON_ENUM_FLAGS(REPOSITORYSTATE);

enum class FILTERASSETRESULT
{
	SKIP,
	ADD,
	ADDCATEGORYONLY,
} MAXON_ENUM_LIST(FILTERASSETRESULT);

enum class MASTERFILTER
{
	ALL,				 		///< Filter for all types
	OBJECTS,		 		///< Filter for object assets only
	MATERIALS,	 		///< Filter for material assets only
	MEDIA,			 		///< Filter for media assets only
	NODES,			 		///< Filter for node assets only
	SCENE_NODES, 		///< Filter for scene nodes only
	SCENES,			 		///< Filter for scene files only
	PRESETS,		 		///< Filter for presets only
	TOOLCOMMANDS,		///< Filter for tool commands only
	OBJECTCOMMANDS, ///< Filter for object commands only
	OTHERCOMMANDS,	///< FIlter for other commands only
	SPECIAL,				///< Filter for special mode
} MAXON_ENUM_LIST(MASTERFILTER);

enum class LENGTHUNITSYSTEM
{
	METRIC,
	IMPERIAL
} MAXON_ENUM_LIST(LENGTHUNITSYSTEM);

struct AssetSortData
{
	ASSETSORTBY						sortBy						= ASSETSORTBY::UNDEFINED;
	ASSETSORTORDER				order							= ASSETSORTORDER::NONE;
	ASSETSORTFIRST 				sortFirst					= ASSETSORTFIRST::FAVORITES;
	MASTERFILTER					relevantItems	  	= MASTERFILTER::ALL;
	ASSETRELEVANCECONTEXT relevanceContext	= ASSETRELEVANCECONTEXT::OTHER; // Used with ASSETSORTBY::RELEVANCE
};

enum class BUILDBROWSERENTRYCOMMAND
{
	START,	///< returned value is passed as data into all callbacks
	END,		///< 'data' contains the data returned in START, 'parent' data contains a boolean if the job was canceled
	RESET,	///< 'data' contains the data returned in START, called before the first element is added
	ADD,		///< 'data' contains the data returned in START, 'parent' contains the parent returned in the parent ADD operation
	SELECT, ///< 'data' contains the data returned in START, 'parent' contains the Id of the element that should be selected
} MAXON_ENUM_LIST(BUILDBROWSERENTRYCOMMAND);

struct BuildBrowserEntryData
{
	AssetDescription		 assetRef;
	AssetRepositoryRef	 repoRef;
	Id							 		 identifier;
	String					 		 name, searchName, additionalInformation, leftInfo, rightInfo, bubbleHelp;
	Bool						 		 isFolder = false, isLocked = false, noRepoCacheIndex = false;
	REPOSITORYSTATE			 repoState = REPOSITORYSTATE::NONE;
	REPOSITORYINDEXSTATE repoIndexState = REPOSITORYINDEXSTATE::NONE; // For databases
};


class AssetBrowserRef;

using BuildBrowserEntryDelegate = Delegate<Result<Data>(const AssetBrowserRef& assetBrowser, BUILDBROWSERENTRYCOMMAND cmd, const Data& data, const Data& parent, const BuildBrowserEntryData& add)>;

using AssetTypeNameMapKey = Tuple<AssetRepositoryRef, Id, Id, Id, Bool>;

using AssetTypeNameMap = HashMap<AssetTypeNameMapKey, Tuple<String, String>>;

class GraphNode;
namespace nodes
{
class NodesGraphModelRef;
class NodeSystemClass;
}

class AssetBrowserInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetBrowserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.assetbrowser");
public:
	using InitDataDelegate = Delegate<Result<void>()>;
	using GetAssetDataDelegate = Delegate<Result<Int32>(const AssetDescription& asset)>;

	static MAXON_METHOD Result<AssetBrowserRef> Create(ASSETBROWSERMODE mode = ASSETBROWSERMODE::ASSETS);

	MAXON_METHOD void SkipWatchfolders(Bool skip);

	MAXON_METHOD void SkipCommandAssets(Bool skip);

	MAXON_METHOD void ShowHiddenFlaggedCommandAssets(Bool show);

	MAXON_METHOD Bool GetShowHiddenFlaggedCommandAssets() const;

	MAXON_METHOD void SetLengthUnitSystem(LENGTHUNITSYSTEM system);

	MAXON_METHOD void EnableUpdates(Bool enableUpdates);

	MAXON_METHOD AssetRepositoryRef GetLookupRepository() const;

	MAXON_METHOD Result<void> SetGraphModel(const nodes::NodesGraphModelRef& nodesGraphRef);

	MAXON_METHOD Result<void> SetBuildEntryDelegate(BuildBrowserEntryDelegate&& builderDelegate);

	MAXON_METHOD Result<void> SetAssetTypesFilter(const HashSet<Id>& assetTypes);

	MAXON_METHOD Result<void> GetAssetTypesFilter(const ValueReceiver<const Id&>& assetTypes) const;

	MAXON_METHOD Result<void> SetParentSelection(const HashSet<Id>& parentSelection, const HashSet<Id>& selectOnNextUpdate);

	MAXON_METHOD Result<void> SetSelectionOnNextUpdate(const HashSet<Id>& selectOnNextUpdate);

	MAXON_METHOD Result<void> GetParentSelection(const ValueReceiver<const Id&>& parentSelection) const;

	MAXON_METHOD Result<void> GetParentSelection(const ValueReceiver<const IdAndVersion&>& parentSelection) const;

	MAXON_METHOD HashSet<Id> GetAndClearSelectionOnNextUpdate();

	MAXON_METHOD Result<void> SetDatabaseMasterfilter(const HashSet<Id>& masterFilterDatabaseIds);

	MAXON_METHOD Result<void> GetDatabaseMasterfilter(const ValueReceiver<const Id&>& filteredDatabases) const;

	MAXON_METHOD Result<void> SetSmartSearch(const Block<AssetDescription>& smartSearch);

	MAXON_METHOD Result<String> GetSmartSearchString() const;

	MAXON_METHOD Bool GetAndResetClearState();

	MAXON_METHOD void JobRefReset(Bool wait);

	MAXON_METHOD void DoFiltering(const String& masterFilter, const String& groupFilter, const String& sortFilter, const String& filterString, Bool localFilterMode, Bool showUnavailable);

	MAXON_METHOD void GetFilterStrings(String& masterFilter, String& groupFilter, String& sortFilter, String& filterString, Bool& localFilterMode) const;

	MAXON_METHOD Block<const String> GetSearchStrings() const;

	MAXON_METHOD const String& GetFilterString() const;

	MAXON_METHOD void RequestAssetBrowserUpdate();

	MAXON_METHOD ASSETBROWSERMODE GetBrowseMode() const;

	MAXON_METHOD Result<void> CopySettingsFrom(const AssetBrowserRef& source);

	MAXON_METHOD void SetInitDataDelegate(InitDataDelegate&& delegate);

	MAXON_METHOD void SetRelevantMasterFilter(MASTERFILTER filter);

	MAXON_METHOD void SetActiveManager(Int32 managerId);

	MAXON_METHOD void SetGetCommandRestrictionManagerDelegate(GetAssetDataDelegate&& delegate);

	MAXON_METHOD void SetGetAssetDefaultPresetPluginTypeDelegate(GetAssetDataDelegate&& delegate);

	static MAXON_METHOD ASSETSORTBY GetDefaultSortByFromGroupBy(ASSETGROUPBY groupBy);

	static MAXON_METHOD Result<Bool> HasMissingDependencies(const AssetRepositoryRef& lookupRepository, const AssetDescription& asset, HashSet<IdAndVersion>& checked);

	static MAXON_METHOD Result<Bool> HasRedshiftDependencies(const AssetDescription& ad);

	static MAXON_METHOD Tuple<String, String> GetAssetTypeName(const Id& id);

	static MAXON_METHOD Result<Tuple<String, String>> GetAssetTypeName(const AssetRepositoryRef& repository, const Id& assetType, const Id& assetId, const Id& versionId, Bool addParentCategories, AssetTypeNameMap* cacheMap);

	static MAXON_METHOD Result<Tuple<String, String>> GetAssetTypeName(const AssetRepositoryRef& repository, const AssetType& assetType, const Id& assetId, const Id& versionId, Bool addParentCategories, AssetTypeNameMap* cacheMap);

	static MAXON_METHOD Tuple<Bool, Color> GetAssetColorBar(const AssetDescription& asset, const AssetRepositoryRef& lookupRepository);

	static MAXON_METHOD Result<String> GetTagStrings(const AssetDescription& asset, const nodes::NodeSystemClass& nodeSystemClass, HashMap<Id, GraphNode>& filterCache);

	static MAXON_METHOD Result<FILTERASSETRESULT> IsNodeHidden(const AssetDescription& asset, const nodes::NodeSystemClass& cls);
};

#include "asset_browser1.hxx"
#include "asset_browser2.hxx"

}

#endif // ASSET_BROWSER_H__
