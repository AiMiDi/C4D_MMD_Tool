/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LONGICONS_H__
#define CUSTOMGUI_LONGICONS_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "lib_description.h"

namespace cinema
{

/// Long Icons custom GUI ID.
#define CUSTOMGUI_LONGICONS 440000323

/// @brief Expresses settings for a Long Icons custom GUI.
enum class LONGICONS : Int32
{
	VERTICAL = 1100, ///< ::Bool Use a vertical layout.
	ROWS = 1101, ///< ::Int32 Number of rows, or zero for automatic layout.
	HEIGHT = 1102, ///< ::Int32 Icon and button height in pixels.
	SHOW_TITLES = 1103, ///< ::Bool Show group titles.
	SHOW_NAMES = 1104, ///< ::Bool Show button names.
	NAMES_BELOW = 1105, ///< ::Bool Draw button names below the icons.
	WIDTH = 1106, ///< ::Int32 Target button width in pixels.
	MAX_WIDTH = 1107, ///< ::Int32 Maximum button width in pixels.
	MENU_MODE = 1108, ///< ::Bool Use menu styling and behavior.
	RADIO = 1109, ///< ::Bool Use radio-button selection behavior.
	TOGGLE = 1110, ///< ::Bool Use toggle-button selection behavior.
	BUTTON_LOCK = 1111, ///< ::Bool Keep popup menus open while dragging.
	FIX_WIDTH = 1112, ///< ::Bool Use a fixed width for menu buttons.
	MENU_SETTINGS = 1113, ///< BaseContainer with settings for popup menus.
	FIX_MAXIMIZE = 1114, ///< ::Bool Include submenu content when maximizing fixed width.
	BIG_TITLES = 1115 ///< ::Bool Use the large font for group titles.
} MAXON_ENUM_FLAGS(LONGICONS);

/// @brief Expresses the data for a single top-level button in a Long Icons custom GUI.
enum class LONGICONS_ITEM : Int32
{
	NAME = 0, ///< String button label in an item data container.
	ICON = 1, ///< Int32 icon ID in an item data container.
	HELP = 2 ///< String bubble help in an item data container.
} MAXON_ENUM_LIST(LONGICONS_ITEM);

class GeDialog;

//----------------------------------------------------------------------------------------
/// @brief Realizes the @ref CUSTOMGUI_LONGICONS custom GUI to display a grid of buttons with
/// optional icons, names, and titles on a `LONG` parameter.
/// @see The `plugins/example.main/source/object/objectdata_objecttree.cpp` demonstrates how to use
/// this custom GUI.
//----------------------------------------------------------------------------------------
class LongIconsCustomGui : public BaseCustomGui<CUSTOMGUI_LONGICONS>
{
	LongIconsCustomGui();
	~LongIconsCustomGui();

public:
	/// @brief Adds a menu item to the settings container of a Long Icons custom GUI.
	///
	/// @details Also ensures the basic shape of the settings container by setting `DESC_CUSTOMGUI`
	/// to `CUSTOMGUI_LONGICONS`. This is a convenience function for adding menu items to a Long Icons
	/// custom GUI, and it is not required to use this function to add menu items. You can also manually
	/// construct the settings container with the appropriate sub-containers for names, icons, and help
	/// text.
	///
	/// @warning This helper function has a slight overhead compared to manually constructing menu items
	/// as it has to access the name, icon, and help sub-container for each call.
	///
	/// @param[in] settings The custom GUI settings container to modify.
	/// @param[in] id The ID returned when the item is selected.
	/// @param[in] name The item label.
	/// @param[in] iconId The optional icon ID, or ::NOTOK to omit the icon.
	/// @param[in] help The optional bubble help text.
	/// @param[in] hasSubmenu Whether the item opens a submenu.
	/// ```
	static void AddMenuItem(BaseContainer& settings, Int32 id, const String& name, Int32 iconId = NOTOK, const String& help = String(), Bool hasSubmenu = false);

	/// @brief Adds an item to a popup menu container for a Long Icons custom GUI.
	///
	/// @details This is a convenience function for adding items to a popup menu container for a Long
	/// Icons custom GUI, and it is not required to use this function to add popup menu items. You can
	/// also manually construct the popup menu container for each item.
	///
	/// @param[in] popup The popup menu container to modify.
	/// @param[in] id The ID returned when the item is selected. The ID `0` is reserved for the popup
	/// title. The title must be the first entry in the popup menu.
	/// @param[in] name The item label.
	/// @param[in] iconId The optional icon ID, or ::NOTOK to omit the icon.
	/// @note For a title, pass ID `0` and leave `iconId` at its default value.
	static void AddPopupMenuItem(BaseContainer& popup, Int32 id, const String& name, Int32 iconId = NOTOK);

	/// @brief Supplies a dynamically built popup menu to a Long Icons custom GUI.
	///
	/// @details The host must build `menu` in response to the popup notification and then
	/// call this function. For a dialog, `dialog` must be set and the menu is passed to
	/// `GeDialog::SetPopup`. For a description, `popup` must be set and the menu is written
	/// to `DescriptionPopup::_popup` for the Attribute Manager.
	///
	/// For a dialog, `actionID` is the gadget ID from `BFM_ACTION_ID`.
	/// It is not inspected for the description case.
	///
	/// @param[in] menu The popup menu container to supply.
	/// @param[in] popup The optional description popup receiving the menu.
	/// @param[in] dialog The optional dialog receiving the menu.
	/// @param[in] actionID The dialog gadget ID from `BFM_ACTION_ID`.
	static Bool HandlePopup(const BaseContainer& menu, DescriptionPopup* popup = nullptr, GeDialog* dialog = nullptr, Int32 actionID = 0);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iLongIconsCustomGui;

struct LongIconsLib : public BaseCustomGuiLib
{
	void (*AddMenuItem)(BaseContainer& settings, Int32 id, const String& name, Int32 iconId, const String& help, Bool hasSubmenu);
	void (*AddPopupMenuItem)(BaseContainer& popup, Int32 id, const String& name, Int32 iconId);
	Bool (*HandlePopup)(const BaseContainer& menu, DescriptionPopup* popup, GeDialog* dialog, Int32 actionID);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_LONGICONS_H__