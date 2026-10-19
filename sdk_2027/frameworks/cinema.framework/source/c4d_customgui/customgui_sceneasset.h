/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_SCENEASSET_H__
#define CUSTOMGUI_SCENEASSET_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

namespace cinema
{

/// Scene asset custom GUI ID.
#define CUSTOMGUI_SCENEASSET 1068177

/// Scene asset custom data type ID.
#define CUSTOMDATATYPE_SCENEASSET 1068176

/// @addtogroup SCENEASSET_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{

// Feature flags (Bool) — each enables an optional button in the widget.
#define SCENEASSET_BUTTON_SAVE          1000 ///< ::Bool Enable "Save" button. Requires @ref SCENEASSET_CATEGORY_ID.
#define SCENEASSET_BUTTON_RESET         1001 ///< ::Bool Enable "Reset" button (re-apply current asset).
#define SCENEASSET_BUTTON_OPEN_BROWSER  1002 ///< ::Bool Enable "Open Browser" button (Asset Browser Popup Window).

// Configuration values — control filtering, search, and display.
#define SCENEASSET_ASSET_TYPE_ID        1010 ///< ::String Registered asset-type ID for filtering popup/save.
#define SCENEASSET_CATEGORY_ID          1011 ///< ::String Default category ID in browser popup.
#define SCENEASSET_SEARCH_STRING        1012 ///< ::String Smart search filter string.
#define SCENEASSET_TITLE                1013 ///< ::String Title shown in the browser popup header.
#define SCENEASSET_MASTERFILTER         1014 ///< ::Int32 MASTERFILTER value (default: ALL).
#define SCENEASSET_TYPE                 1015 ///< ::String Human-readable type label shown in the widget. Falls back to the asset type ID string when not set.

// Action sub-command IDs — sent alongside BFM_ACTION when no callbacks are set (backward compat).
#define SCENEASSET_MSG_SUBCOMMAND       1020 ///< ::Int32 Key in BFM_ACTION identifying the sub-command type.
#define SCENEASSET_MSG_SELECTED         0    ///< Sub-command: user selected an asset. BFM_ACTION_VALUE contains new asset-ID Filename.
#define SCENEASSET_MSG_SAVE             1    ///< Sub-command: user pressed Save. Parent should perform the save.
#define SCENEASSET_MSG_RESET            2    ///< Sub-command: user pressed Reset. BFM_ACTION_VALUE contains current asset-ID Filename.
#define SCENEASSET_MSG_BROWSER_OPENING  3    ///< Sub-command: before browser popup is opening.
#define SCENEASSET_MSG_BROWSER_CLOSED   4    ///< Sub-command: when browser popup is closing.
/// @}

/// Asset metadata key for an optional wide-format (3:2) preview image stored alongside the
/// standard 1:1 ASSET_PREVIEWIMAGEURL. Preset asset types that generate a dedicated widescreen
/// preview should store it under this key via StoreUrlMetaData. customgui_sceneasset will
/// prefer this key over ASSETMETADATA::ASSET_PREVIEWIMAGEURL when the entry is present.
#define ASSETMETADATA_WIDE_PREVIEWIMAGEURL_KEY "net.maxon.asset.widepreviewimageurl"

//----------------------------------------------------------------------------------------
/// Scene asset custom GUI (@ref CUSTOMGUI_SCENEASSET).\n
/// A reusable widget that displays an asset preview thumbnail and name, with optional
/// Save, Reset and Open Browser buttons. The widget stores a plain asset ID filename.\n
/// Sends ::BFM_ACTION with @ref SCENEASSET_MSG_SUBCOMMAND on user interaction; handle it via
/// GeDialog::Command() or NodeData::SetDParameter() / NodeData::Message().\n
/// Here are the settings: @enumerateEnum{SCENEASSET_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class SceneAssetCustomGui : public BaseCustomGui<CUSTOMGUI_SCENEASSET>
{
	SceneAssetCustomGui();
	~SceneAssetCustomGui();

public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
class iSceneAssetCustomGui : public iBaseCustomGui
{
	iSceneAssetCustomGui(const BaseContainer& settings, CUSTOMGUIPLUGIN* plugin) : iBaseCustomGui(settings, plugin) { }
};
#else
class iSceneAssetCustomGui;
#endif

struct CustomGuiSceneAssetLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_SCENEASSET_H__
