#ifndef ASSETMANAGERINTERFACE_H__
#define ASSETMANAGERINTERFACE_H__

#include "maxon/object.h"
#include "maxon/asset_browser.h"

class SubDialog;

namespace maxon
{

class DragAndDropDataAssetArray;

enum class ASSETPOPUPOPTIONS
{
	NONE = 0,

	POPUPMODE						= (1 << 0),		///< opens the manager in popup mode
	MODAL								= (1 << 1),		///< opens a modal dialog
	EXECUTELOAD					= (1 << 2),		///< in POPUPMODE mode do not call the resultCallback, but execute the load on doubleclick directly
	ALLOWDRAGANDDROP		= (1 << 3),		///< enables d&d out of the manager
	ALLOWPINPOPUP				= (1 << 4),		///< show pin button to make dialog sticky
	SUBDIALOG						= (1 << 5),		///< @internal dialog is running in a subdialog

	SHOWCATEGORIESONLY	= (1 << 10),	///< special mode to select only categories
	SHOWKEYWORDSONLY		= (1 << 11),	///< special mode to select only keywords
	SHOWCATEGORYLIST		= (1 << 12),	///< enables the category list for selections
	SHOWQUICKTABS				= (1 << 13),	///< enables the visibility of the quicktabs
	DISPLAYASLIST				= (1 << 14),	///< displays the popup as list instead of gridview
	HIDEWATCHFOLDERS		= (1 << 15),	///< Hides Watchfolder categories
	COMMANDER						= (1 << 16),	///< @markprivate
} MAXON_ENUM_FLAGS(ASSETPOPUPOPTIONS);

class GraphModelPresenterRef;
class GraphNode;

namespace nodes
{
	class NodesGraphModelRef;
}

class AssetManagerSubDialogRef;

enum class VIEW_MODE
{
	LIST,
	GRID
} MAXON_ENUM_LIST(VIEW_MODE);

//----------------------------------------------------------------------------------------
/// Parameters for @ref AssetManagerSubDialogInterface::Configure()
//----------------------------------------------------------------------------------------
namespace ASSET_MANAGER_SETTINGS
{
MAXON_ATTRIBUTE(VIEW_MODE, VIEW_MODE, "net.maxon.assetmanager.settings.viewmode"); ///< View mode.
MAXON_ATTRIBUTE(Bool, HIDE_GROUPING_SORTING_ICONS, "net.maxon.assetmanager.settings.hidegroupingsoringticons"); ///< Hides the "Group by", "Sort by" and "Show Content of Subcategories" icons.
MAXON_ATTRIBUTE(Float, LIST_VIEW_ICON_SIZE, "net.maxon.assetmanager.settings.listviewiconsize"); ///< Icon size in range [0, 1] for list view mode.
MAXON_ATTRIBUTE(Float, GRID_VIEW_ICON_SIZE, "net.maxon.assetmanager.settings.gridviewiconsize"); ///< Icon size in range [0, 1] for grid view mode.
};

//----------------------------------------------------------------------------------------
// Interface to allow the asset manager in sub dialogs
//----------------------------------------------------------------------------------------
class AssetManagerSubDialogInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetManagerSubDialogInterface, MAXON_REFERENCE_NORMAL, "net.maxon.mvp.assetmanager.subdialog.interface");

public:
	//----------------------------------------------------------------------------------------
	/// Allows to define several settings with the ASSET_MANAGER_SETTINGS parameters.
	/// @param[in] settings						Dictionary with settings.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Configure(const DataDictionary& settings);

	//----------------------------------------------------------------------------------------
	/// Get() returns the subdialog to embed into your own dialog.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SubDialog* Get();

	//----------------------------------------------------------------------------------------
	/// SetNewGraphNode sets the current selected presenter, model and node. Depending on this values the asset browser switches to the right context.
	/// @param[in] presenter					Presenter to set.
	/// @param[in] model							Model to set.
	/// @param[in] node								Node to set.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetNewGraphNode(const GraphModelPresenterRef& presenter, const nodes::NodesGraphModelRef& model, const GraphNode& node);

	//----------------------------------------------------------------------------------------
	/// SetMasterFilter allows to set the filter for the asset browser.
	/// @param[in] filter							See MASTERFILTER.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetMasterFilter(MASTERFILTER filter);
	
	//----------------------------------------------------------------------------------------
	/// ForceHideFilterTab allows to control the visibility of filter tab.
	/// @param[in] hide								True to disable filter tab.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ForceHideFilterTab(Bool hide);
};

//----------------------------------------------------------------------------------------
/// Helper class to control the Asset Manager.
//----------------------------------------------------------------------------------------
class AssetManagerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AssetManagerInterface, MAXON_REFERENCE_STATIC, "net.maxon.mvp.assetmanager.interface");

public:
	//----------------------------------------------------------------------------------------
	/// SetActiveManager sets the active asset manager mode.
	/// @param[in] masterFilter				see MASTERFILTER.
	/// @param[in] presenter					Optional parameter to pass a NodeGraph presenter.
	/// @param[in] model							Optional parameter to pass a NodeGraph.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetActiveManager(MASTERFILTER masterFilter, const GraphModelPresenterRef& presenter = GetZeroRef<GraphModelPresenterRef>(), const nodes::NodesGraphModelRef& model = GetZeroRef<nodes::NodesGraphModelRef>());

	//----------------------------------------------------------------------------------------
	/// OpenPopup opens an asset selection popup.
	/// @param[in] flags							see ASSETPOPUPOPTIONS.
	/// @param[in] masterFilter				see MASTERFILTER.
	/// @param[in] filterString				see FilterString.
	/// @param[in] smartFilter				SmartFilter to select.
	/// @param[in] presenter					Optional parameter to pass a NodeGraph presenter.
	/// @param[in] model							Optional parameter to pass a NodeGraph.
	/// @param[in] title							Optional Window Title.
	/// @param[out] inSelection				Returns the selected elements.
	/// @param[out]	outSelection			Delegate.
	/// @return                       True on success. False if the user cancelled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OpenPopup(ASSETPOPUPOPTIONS flags, MASTERFILTER masterFilter, const String& filterString, const AssetDescription& smartFilter = GetZeroRef<AssetDescription>(), const GraphModelPresenterRef& presenter = GetZeroRef<GraphModelPresenterRef>(), const nodes::NodesGraphModelRef& model = GetZeroRef<nodes::NodesGraphModelRef>(), const String& title = String(), const HashSet<Id>& inSelection = HashSet<Id>(), Delegate<void(const DragAndDropDataAssetArray&)>&& outSelection = {});

	//----------------------------------------------------------------------------------------
	/// CheckDownloadAssetWithModalProgressDialog checks if an asset is already cached and if 
	/// not it will download the asset with a modal progress dialog which can be canceled.
	/// Canceling the dialog will continue the download but returns false.
	/// Dependencies will be added to the download queue as well.
	/// @param[in] asset							Asset to inspect/download.
	/// @param[in] lookupRepository		Repository to check dependencies for.
	/// @return                       True if done. False if cancelled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> CheckDownloadAssetWithModalProgressDialog(const AssetDescription& asset, const AssetRepositoryRef& lookupRepository);

	static MAXON_METHOD Result<Bool> CheckDownloadAssetsWithModalProgressDialog(const BaseArray<AssetDescription>& assets, const AssetRepositoryRef& lookupRepository);


	using Filter = Delegate<Bool(const AssetDescription& desc)>;

	//----------------------------------------------------------------------------------------
	/// GetAssetFilenameFromDragData extracts the filename/url from the legacy d&d message. If filter is null,
	/// this will only return assets of type AssetTypes::File, otherwise only assets which pass the given filter.
	/// @param[in] dragData           DragData containing the asset filename.
	/// @return                       Bool: false if cancelled by user, Id: Asset ID, Url: asset url, AssetDescription: asset description, String: filter string from asset browser
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Bool, Id, Url, AssetDescription, String> GetAssetFilenameFromDragData(const void* dragData, Bool updateUsage, Bool showDownloadDialog, const Filter& filter = GetZeroRef<Filter>());

	using AssetDragTuple = Tuple<Url, AssetDescription, String>;
	using AssetDragArray = BaseArray<AssetDragTuple>;
	using AssetDragSubtypeArray = BaseArray<Id>;
	using AssetDragArrayTuple = Tuple<AssetDragArray, AssetDragSubtypeArray>;
	static MAXON_METHOD Result<AssetDragArrayTuple> GetAssetFilenameFromMultiDragData(const void* dragData, Bool updateUsage, Bool showDownloadDialog, const Filter& filter = GetZeroRef<Filter>());

	//----------------------------------------------------------------------------------------
	/// RevealAsset opens the asset browser to show the given assets in the browser.
	/// @param[in] assets							Assets to show.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RevealAsset(const Block<AssetDescription>& assets);

	//----------------------------------------------------------------------------------------
	/// LoadAssets executes the load asset command from the asset browser (e.g. double click or open).
	/// @param[in] searchRepository		Search repository.
	/// @param[in] selectionAndFilterString HashMap which contains the search terms to switch modes in the newly created node/object.
	/// @param[in] presenter					Optional presenter to use when creating nodes.
	/// @param[in] graphModelRef			Optional parameter to pass the node graph where to insert nodes.
	/// @return                       Bool on success. True if loaded. False indicates another error state.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> LoadAssets(const AssetRepositoryRef& searchRepository, const HashMap<Id, String>& selectionAndFilterString, const GraphModelPresenterRef& presenter = GetZeroRef<GraphModelPresenterRef>(), const nodes::NodesGraphModelRef& graphModelRef = GetZeroRef<nodes::NodesGraphModelRef>());

	static MAXON_METHOD Result<AssetManagerSubDialogRef> GetAssetManagerSubDialogRef();
};


#include "assetmanagerinterface1.hxx"
#include "assetmanagerinterface2.hxx"


} // namespace maxon



#endif // ASSETMANAGERINTERFACE_H__
