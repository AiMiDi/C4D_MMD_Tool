#ifndef GUI_RADIOBUTTON_UTILS_H__
#define GUI_RADIOBUTTON_UTILS_H__

#include "maxon/object.h"
#include "maxon/optional.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @brief Utility interface for radio button gadget metrics and icon state mapping.
/// @details Provides helpers to compute font-scaled radio button sizes and to resolve radio
/// button icon resource IDs from hover, focus, disabled, and radio button states.
/// @note Radio button visuals are vector-based, so they scale cleanly with UI/font scaling.
/// @note Radio buttons have no tristate: only UNCHECKED and CHECKED are valid states.
/// @note The checked state has no hover icon; hover only applies to the unchecked state.
//----------------------------------------------------------------------------------------
class GuiRadioButtonUtils
{
	MAXON_INTERFACE_NONVIRTUAL(GuiRadioButtonUtils, MAXON_REFERENCE_STATIC, "net.maxon.interface.guiradiobuttonutils");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the unscaled base size used for the radio button gadget.
	/// @note GetFontScaledSize is the preferred way to retrieve radio button size for UI usage because it applies font scaling.
	/// @return                   The base radio button size in pixels (currently 14).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetBaseSize();

	//----------------------------------------------------------------------------------------
	/// Returns the size of a radio button gadget, scaled according to the optional font size.
	/// @param fontSize           Optional font size override; if omitted, uses the font size defined in preferences.
	/// @return                   The font scaled size of a radio button gadget in pixels.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetFontScaledSize(Opt<Float> fontSize = {});

	//----------------------------------------------------------------------------------------
	/// Logical check state represented by a radio button.
	//----------------------------------------------------------------------------------------
	enum class STATE : UChar
	{
		UNCHECKED = 0, ///< The radio button is unchecked.
		CHECKED = 1,   ///< The radio button is checked.
		TRISTATE = 2   ///< The radio button is in an indeterminate state (e.g., partially checked).
	} MAXON_ENUM_LIST_CLASS(STATE);

	//----------------------------------------------------------------------------------------
	/// Returns the icon resource identifier for a radio button with the specified interaction and radio button states.
	/// @param isHovered          True if the mouse cursor is hovering over the gadget.
	/// @param isFocused          True if the gadget has keyboard focus.
	/// @param isDisabled         True if the gadget is disabled. Takes priority over hover and focus.
	/// @param radioButtonState   The current radio button state.
	/// @return                   The corresponding icon resource identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int32 GetIconId(Bool isHovered, Bool isFocused, Bool isDisabled, STATE radioButtonState);
};

#include "gui_radio_button_utils1.hxx"
#include "gui_radio_button_utils2.hxx"

} // namespace maxon

#endif // GUI_RADIOBUTTON_UTILS_H__
