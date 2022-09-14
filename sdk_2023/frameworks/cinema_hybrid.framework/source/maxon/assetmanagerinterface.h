#ifndef ASSETMANAGERINTERFACE_H__
#define ASSETMANAGERINTERFACE_H__

#include "maxon/object.h"
#include "maxon/assets.h"


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

	SHOWCATEGORIESONLY	= (1 << 10),	///< special mode to select only categories
	SHOWKEYWORDSONLY		= (1 << 11),	///< special mode to select only keywords
	SHOWCATEGORYLIST		= (1 << 12),	///< enables the category list for selections
	SHOWQUICKTABS				= (1 << 13),	///< enables the visibility of the quicktabs
	DISPLAYASLIST				= (1 << 14),	///< displays the popup as list instead of gridview
	HIDEWATCHFOLDERS		= (1 << 15),	///< Hides Watchfolder categories
} MAXON_ENUM_FLAGS(ASSETPOPUPOPTIONS);

enum class MASTERFILTER
{
	ALL,				 ///< Filter for all types
	OBJECTS,		 ///< Filter for object assets only
	MATERIALS,	 ///< Filter for material assets only
	MEDIA,			 ///< Filter for media assets only
	NODES,			 ///< Filter for node assets only
	SCENE_NODES, ///< Filter for scene nodes only
	SCENES,			 ///< Filter for scene files only
	PRESETS,		 ///< Filter for presets only
	SPECIAL,		 ///< Filter for special mode
} MAXON_ENUM_LIST(MASTERFILTER);

class GraphModelPresenterRef;

namespace nodes
{
	class NodesGraphModelRef;
}

//----------------------------------------------------------------------------------------
/// Helper class to control the Asset Manager.
//----------------------------------------------------------------------------------------
class AssetManagerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(AssetManagerInterface, MAXON_REFERENCE_NONE, "net.maxon.mvp.assetmanager.interface");

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

	using Filter = Delegate<Bool(const AssetDescription& desc)>;

	//----------------------------------------------------------------------------------------
	/// GetAssetFilenameFromDragData extracts the filename/url from the legacy d&d message. If filter is null,
	/// this will only return assets of type AssetTypes::File, otherwise only assets which pass the given filter.
	/// @param[in] dragData           DragData containing the asset filename.
	/// @return                       Bool: false if cancelled by user, Id: Asset ID, Url: asset url, AssetDescription: asset description, String: filter string from asset browser
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Bool, Id, Url, AssetDescription, String> GetAssetFilenameFromDragData(const void* dragData, Bool updateUsage, Bool showDownloadDialog, const Filter& filter = GetZeroRef<Filter>());

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
};


#include "assetmanagerinterface1.hxx"
#include "assetmanagerinterface2.hxx"


} // namespace maxon



#endif // ASSETMANAGERINTERFACE_H__
