#ifndef ASSETMANAGERINTERFACE_H__
#define ASSETMANAGERINTERFACE_H__

#include "maxon/object.h"
#include "maxon/assets.h"


namespace maxon
{

enum class ASSETPOPUPOPTIONS
{
	NONE = 0,
	POPUPMODE = (1 << 0),
	MODAL = (1 << 1),
	ALLOWDRAGANDDROP = (1 << 2),
	SHOWCATEGORIESONLY = (1 << 3),
	SHOWKEYWORDSONLY = (1 << 4),
} MAXON_ENUM_FLAGS(ASSETPOPUPOPTIONS);

enum class MASTERFILTER
{
	ALL,
	OBJECTS,
	MATERIALS,
	MEDIA,
	NODES,
	SCENE_NODES,
	SCENES,
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
	/// @param[in] presenter					Optional parameter to pass a NodeGraph presenter.
	/// @param[in] model							Optional parameter to pass a NodeGraph.
	/// @param[out] selection					Returns the selected elements.
	/// @return                       True on success. False if the user cancelled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> OpenPopup(ASSETPOPUPOPTIONS flags, MASTERFILTER masterFilter, const GraphModelPresenterRef& presenter = GetZeroRef<GraphModelPresenterRef>(), const nodes::NodesGraphModelRef& model = GetZeroRef<nodes::NodesGraphModelRef>(), const ValueReceiver<const Id&>& selection = {});

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

	//----------------------------------------------------------------------------------------
	/// GetAssetFilenameFromDragData extracts the filename/url from the legacy d&d message
	/// @param[in] dragData           DragData containing the asset filename.
	/// @return                       Bool: false if cancelled by user, Id: Asset ID, Url: asset url, AssetDescription: asset description
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<Bool, Id, Url, AssetDescription> GetAssetFilenameFromDragData(const void* dragData, Bool updateUsage, Bool showDownloadDialog);
};


#include "assetmanagerinterface1.hxx"
#include "assetmanagerinterface2.hxx"


} // namespace maxon



#endif // ASSETMANAGERINTERFACE_H__
