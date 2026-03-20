#ifndef C4DUITOOLS_H__
#define C4DUITOOLS_H__

#include "maxon/registrybase.h"

namespace maxon
{

class CommandLocationRef;
class OSWindowInterface;

enum class COMMAND_SEARCH_RESULT
{
	SINGLE, // Return the single most relevant result, prioritizing palettes over menus.
	ALL 		// Return all results.
} MAXON_ENUM_LIST(COMMAND_SEARCH_RESULT);

enum class COMMAND_SOURCE
{
	NONE,
	PALETTE,
	MENU,
	MENU_ICON
}
MAXON_ENUM_LIST(COMMAND_SOURCE);

enum class PALETTE_ORIENTATION
{
	HORIZONTAL,
	VERTICAL
}
MAXON_ENUM_LIST(PALETTE_ORIENTATION);

enum class PALETTE_OUTOFBOUNDS
{
	NONE,	// Command is visible.
	HEAD, // Command is hidden at left for horizontal palettes, top for vertical palettes.
	TAIL	// Command is hidden at right for horizontal palettes, bottom for vertical palettes.
}
MAXON_ENUM_LIST(PALETTE_OUTOFBOUNDS);

enum class POPUP_CLOSE_MODE
{
	NONE								= 0,			// Closing must be done manually by calling the respective close function.
	ON_FOCUS_LOST				= 1 << 0, // Popup is closed when its focus is lost, e.g. when clicked somewhere else.
	ON_LEFT_MOUSE_CLICK = 1 << 1	// Popup is closed when left mouse clicked inside of it.
} MAXON_ENUM_FLAGS(POPUP_CLOSE_MODE);

class C4dUiTools
{
	MAXON_INTERFACE_NONVIRTUAL(C4dUiTools, MAXON_REFERENCE_STATIC, "net.maxon.interface.c4duitools");

public:
	static MAXON_METHOD OSWindowInterface* GetMainWindow();
	
	static MAXON_METHOD Result<Bool> HighlightManager(Int32 managerId, POPUP_CLOSE_MODE closeMode);
	static MAXON_METHOD void CloseManagerHighlighting();

	static MAXON_METHOD Int32 GetManagerIdFromString(const String& str);

	// commandId can be either a numeric symbol: (e.g. "13563"), or a text symbol (e.g. "HOTKEY_CAMERA_MOVE") as defined in file: c4d_command_strings.str
	// Returns 0 on failure (e.g. command not found)
	static MAXON_METHOD Int32 GetCommandIdFromString(const String& commandIdAsString);

	static MAXON_METHOD Result<void> ShowCommandLocationAndHighlightManagerPopups(Int32 commandId, Int32 managerId, POPUP_CLOSE_MODE closeMode);
	static MAXON_METHOD void CloseCommandLocationAndHighlightManagerPopups();

	static MAXON_METHOD Bool IsR2L();

//	static MAXON_METHOD String GetShortcutStringFromCommandId(Int32 commandId);
};

//-------------------------------------------------------------
// Searches for commands in the UI.
//-------------------------------------------------------------
class CommandLocationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CommandLocationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.c4duitools.interfaces.commandlocation");

public:
	static MAXON_METHOD Result<void> ShowCommandLocation(Int32 commandId, POPUP_CLOSE_MODE closeMode);
	static MAXON_METHOD Result<BaseArray<CommandLocationRef>> LocateCommand(Int32 commandId, COMMAND_SEARCH_RESULT searchResult);
	static MAXON_METHOD void CloseCommandLocation();

	MAXON_METHOD Int32 GetCommandId() const;
	MAXON_METHOD COMMAND_SOURCE GetCommandSource() const;

	MAXON_METHOD void GetGadgetFrame(Int& x, Int& y, Int& w, Int& h) const;

	MAXON_METHOD void GetPaletteFrame(Int& x, Int& y, Int& w, Int& h) const;

	MAXON_METHOD PALETTE_ORIENTATION GetPaletteOrientation() const;
	MAXON_METHOD PALETTE_OUTOFBOUNDS GetPaletteOutOfBounds() const;
	MAXON_METHOD Bool IsFoldedPaletteIcon() const;

	MAXON_METHOD const BaseArray<String>& GetParentSubmenus() const;

	MAXON_METHOD Result<void> ShowPopup(const String& text, POPUP_CLOSE_MODE closeMode) const;
};

#include "c4duitools1.hxx"
MAXON_DECLARATION(Class<CommandLocationRef>, CommandLocationClass, "net.maxon.c4duitools.commandlocation");
#include "c4duitools2.hxx"

} // namespace maxon

#endif // C4DUITOOLS_H__
