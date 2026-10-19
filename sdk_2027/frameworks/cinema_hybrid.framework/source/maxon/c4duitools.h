#ifndef C4DUITOOLS_H__
#define C4DUITOOLS_H__

#include "maxon/hashmap.h"
#include "maxon/observable.h"
#include "maxon/vector2d.h"

namespace cinema
{

class BaseBitmap;
class BaseContainer;
class GeDialog;
class GeUserArea;
}

namespace maxon
{
class CommandLocationRef;
class OSWindowInterface;
class OSWindowDrawHandlerInterface;

template <typename T> struct DrawRect;
using DrawRectInt = DrawRect<Int>;
using DrawRectFloat = DrawRect<Float>;

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
} MAXON_ENUM_LIST(COMMAND_SOURCE);

enum class PALETTE_ORIENTATION
{
	HORIZONTAL,
	VERTICAL
} MAXON_ENUM_LIST(PALETTE_ORIENTATION);

enum class PALETTE_OUTOFBOUNDS
{
	NONE,	// Command is visible.
	HEAD, // Command is hidden at left for horizontal palettes, top for vertical palettes.
	TAIL	// Command is hidden at right for horizontal palettes, bottom for vertical palettes.
} MAXON_ENUM_LIST(PALETTE_OUTOFBOUNDS);

enum class POPUP_CLOSE_MODE
{
	NONE								= 0,			// Closing must be done manually by calling the respective close function.
	ON_FOCUS_LOST				= 1 << 0, // Popup is closed when its focus is lost, e.g. when clicked somewhere else.
	ON_LEFT_MOUSE_CLICK = 1 << 1	// Popup is closed when left mouse clicked inside of it.
} MAXON_ENUM_FLAGS(POPUP_CLOSE_MODE);

enum class CORNERS
{
	NONE				 = 0,
	TOP_LEFT		 = (1 << 0),
	TOP_RIGHT		 = (1 << 1),
	BOTTOM_LEFT	 = (1 << 2),
	BOTTOM_RIGHT = (1 << 3),
	LEFT				 = TOP_LEFT | BOTTOM_LEFT,
	RIGHT				 = TOP_RIGHT | BOTTOM_RIGHT,
	TOP					 = TOP_LEFT | TOP_RIGHT,
	BOTTOM			 = BOTTOM_LEFT | BOTTOM_RIGHT,
	ALL					= LEFT | RIGHT
} MAXON_ENUM_FLAGS(CORNERS);

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class C4dUiTools
{
	MAXON_INTERFACE_NONVIRTUAL(C4dUiTools, MAXON_REFERENCE_STATIC, "net.maxon.interface.c4duitools");

public:

	// NOTE: (Ferdinand) Left over from a merge issue in main fixed by Maxime. This likely is an orphaned 
	// constant as I do not see any usage in the modules. But due to the broken merge, it has become 
	// impossible to find the original author.
	static constexpr Float IMMEDIATE_UPDATE_MODE_OFFSET = 1000.0;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD OSWindowInterface* GetMainWindow();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> HighlightManager(Int32 managerId, POPUP_CLOSE_MODE closeMode);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void CloseManagerHighlighting();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetManagerIdFromString(const String& str);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	// commandId can be either a numeric symbol: (e.g. "13563"), or a text symbol (e.g. "HOTKEY_CAMERA_MOVE") as defined in file: c4d_command_strings.str
	// Returns 0 on failure (e.g. command not found)
	static MAXON_METHOD Int32 GetCommandIdFromString(const String& commandIdAsString);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ShowCommandLocationAndHighlightManagerPopups(Int32 commandId, Int32 managerId, POPUP_CLOSE_MODE closeMode);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void CloseCommandLocationAndHighlightManagerPopups();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsR2L();

	//----------------------------------------------------------------------------------------
	/// Returns the most recent active window. Can be used in OSGuiRef::ChooseUrls as parent window to return to.
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD OSWindowInterface* GetMostRecentActiveWindow();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetGadgetMinHeight();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetGadgetSpace();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<OSWindowDrawHandlerInterface*, IntVector2d32/*offset*/> GetUserAreaDrawHandler(cinema::GeUserArea* userArea);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD IntVector2d32 GetStoredDialogSize(Int32 pluginId, Int32 subId, const IntVector2d32& defaultSize);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void GetDialogFrame(cinema::GeDialog* dlg, DrawRectFloat& dlgFrame);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetDialogFrame(cinema::GeDialog* dlg, const DrawRectFloat& dlgFrame);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD FunctionBaseRef	AddPositionChangedObserver(cinema::GeDialog* dlg, Int32 commandId);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool RemovePositionChangedObserver(cinema::GeDialog* dlg, const FunctionBaseRef& func);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD FunctionBaseRef	AddMainWindowPositionChangedObserver(cinema::GeDialog* dlg, Int32 commandId);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool RemoveMainWindowPositionChangedObserver(const FunctionBaseRef& func);

	//----------------------------------------------------------------------------------------
	/// @markInternal Deprecated. Use maxon::FontScaling::ScaleDimension instead.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetFontAdjustedHeight(Int32 height);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void ConstrainFramePositionToMonitor(DrawRectInt& frame, const DrawRectInt& monitorFrame);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void GetMonitorFrameFromDialog(cinema::GeDialog* dlg, DrawRectInt& monitorFrame);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float GetGadgetCornerRadius();

	//----------------------------------------------------------------------------------------
	/// Extracts from the input text, the string delimited with a preffix and a suffix, and the input string cleaned.
	/// Example: using as input text: "My Tab Title&i12345&", delimiterPreffix: "&i", delimiterSuffix "&",
	/// will result in extractedString: "12345", cleanedString: "My Tab Title"
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Tuple<String/*extractedString*/, String/*cleanedInputString*/> ExtractAndRemoveDelimitedSubstring(const String& text, const String& delimiterPreffix, const String& delimiterSuffix);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DrawOverlayedRoundedCorners(cinema::GeUserArea& ua, Int32 x1, Int32 y1, Int32 x2, Int32 y2, const Vector2d& radius, CORNERS corners = CORNERS::ALL);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetButtonString(const String& name, const String& bubbleHelp, Int32 iconId = 0);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetApplicationName();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void RevealManager(Int32 managerId);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ShowOverlayMessage(const String& title, const String& message);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> CloseOverlayMessage();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetOverlayProgress(Float percent, const String& detailText);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ShowWelcomeScreen();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> CloseWelcomeScreen();

	/// @MAXON_ANNOTATION{methodId="DeprecatedCloseWelcomeScreen@a0cff72f181cfa62"->"CloseWelcomeScreen@a0cff72f181cfa62"}
	static MAXON_METHOD Result<void> DeprecatedCloseWelcomeScreen();

	//----------------------------------------------------------------------------------------
	/// fontType: FONT_STANDARD, FONT_BOLD, FONT_MONOSPACED, etc. @see gui.h
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetFontHeight(Int32 fontType);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetUIFontName();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> LoadSVGIntoBitmap(const Url& svgUrl, cinema::BaseBitmap& bmp);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ColorizeWrappedSVG(cinema::BaseBitmap& bmp, const Color& color);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Vector2d ComputeAspectFitSize(const Vector2d& size, Float maxTargetSize);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD IntVector2d32 ComputeAspectFitSize(const IntVector2d32& size, Int32 maxTargetSize);

	//----------------------------------------------------------------------------------------
	/// Rasterizes a wrapped SVG from sourceBitmap into targetBitmap. Returns false when no wrapped SVG is present.
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool TryRasterizeWrappedSVG(const cinema::BaseBitmap& sourceBitmap, cinema::BaseBitmap& targetBitmap);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD IntVector2d32 ComputeCappedCursorIconSize(Int32 sourceWidth, Int32 sourceHeight, Float scale, Int32 maxCursorIconSize);

	//----------------------------------------------------------------------------------------
	/// Colorizes SVG elements whose CSS class attribute matches a key in @formatParam{classColors}.
	/// Applies per-class fill and stroke overrides to the wrapped SVG in @formatParam{bmp}.
	/// Creates a new VectorImageRef to avoid mutating the shared original SVG.
	/// Returns false when @formatParam{bmp} does not wrap an SVG or on error.
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ColorizeIconClasses(cinema::BaseBitmap& bmp, const HashMap<String, Color32>& classColors);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> LoadSVGIntoBitmap(const Url& svgUrl, cinema::BaseBitmap& bmp, Bool doubleSize);
};

using MessageDelegate = Delegate<void(const cinema::BaseContainer* message)>;
//-------------------------------------------------------------
// Searches for commands in the UI.
/// @markInternal
//-------------------------------------------------------------
class CommandLocationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CommandLocationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.c4duitools.interfaces.commandlocation");

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ShowCommandLocation(Int32 commandId, POPUP_CLOSE_MODE closeMode);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<CommandLocationRef>> LocateCommand(Int32 commandId, COMMAND_SEARCH_RESULT searchResult);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void CloseCommandLocation();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetCommandId() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMMAND_SOURCE GetCommandSource() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetGadgetFrame(Int& x, Int& y, Int& w, Int& h) const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetPaletteFrame(Int& x, Int& y, Int& w, Int& h) const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PALETTE_ORIENTATION GetPaletteOrientation() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PALETTE_OUTOFBOUNDS GetPaletteOutOfBounds() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsFoldedPaletteIcon() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<String>& GetParentSubmenus() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ShowPopup(const String& text, POPUP_CLOSE_MODE closeMode) const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMessageDelegate(MessageDelegate&& delegate);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ResetMessageDelegate();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IntVector2d32 GetPopupScreenPosition(const IntVector2d32& popupSize, Int32 offsetY);
};

#include "c4duitools1.hxx"
MAXON_DECLARATION(Class<CommandLocationRef>, CommandLocationClass, "net.maxon.c4duitools.commandlocation");
#include "c4duitools2.hxx"

} // namespace maxon

#endif // C4DUITOOLS_H__
