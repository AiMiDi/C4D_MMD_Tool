#ifndef GUI_CHECKBOX_UTILS_H__
#define GUI_CHECKBOX_UTILS_H__

#include "maxon/object.h"
#include "maxon/optional.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @brief Utility interface for checkbox gadget metrics and icon state mapping.
/// @details Provides helpers to compute font-scaled checkbox sizes and to resolve checkbox
/// icon resource IDs from hover, focus, disabled, and checkbox states.
/// @note Checkbox visuals are vector-based, so they scale cleanly with UI/font scaling.
//----------------------------------------------------------------------------------------
class GuiCheckboxUtils
{
	MAXON_INTERFACE_NONVIRTUAL(GuiCheckboxUtils, MAXON_REFERENCE_STATIC, "net.maxon.interface.guicheckboxutils");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the unscaled base size used for the checkbox gadget.
	/// @note GetFontScaledSize is the preferred way to retrieve checkbox size for UI usage because it applies font scaling.
	/// @return                   The base checkbox size in pixels (currently 12).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetBaseSize();

	//----------------------------------------------------------------------------------------
	/// Returns the size of a checkbox gadget, scaled according to the optional font size.
	/// @param fontSize           Optional font size override; if omitted, uses the font size defined in preferences.
	/// @return                   The font scaled size of a checkbox gadget in pixels.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetFontScaledSize(Opt<Float> fontSize = {});

	//----------------------------------------------------------------------------------------
	/// Logical check state represented by a checkbox.
	//----------------------------------------------------------------------------------------
	enum class STATE : UChar
	{
		UNCHECKED = 0, ///< The checkbox is unchecked.
		CHECKED = 1,   ///< The checkbox is checked.
		TRISTATE = 2   ///< The checkbox is in an indeterminate state (e.g., partially checked).
	} MAXON_ENUM_LIST_CLASS(STATE);

	//----------------------------------------------------------------------------------------
	/// Returns the icon resource identifier for a checkbox with the specified interaction and checkbox states.
	/// @param isHovered          True if the mouse cursor is hovering over the gadget.
	/// @param isFocused          True if the gadget has keyboard focus.
	/// @param isDisabled         True if the gadget is disabled. Takes priority over hover and focus.
	/// @param checkboxState      The current checkbox state.
	/// @return                   The corresponding icon resource identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetIconId(Bool isHovered, Bool isFocused, Bool isDisabled, STATE checkboxState);
};

#include "gui_checkbox_utils1.hxx"
#include "gui_checkbox_utils2.hxx"

} // namespace maxon

#endif // GUI_CHECKBOX_UTILS_H__
