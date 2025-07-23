/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_FONTCHOOSER_H__
#define CUSTOMGUI_FONTCHOOSER_H__

/// Font chooser custom GUI ID.
#define CUSTOMGUI_FONTCHOOSER		1009371

/// Font chooser custom data ID.
#define FONTCHOOSER_DATA				1009372

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

namespace cinema
{

/// @addtogroup FONTCHOOSER_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
enum
{
	FONTCHOOSER_ENABLE_SIZE = 'size',								///< ::Bool @formatConstant{true} if the size popup should be displayed.
	FONTCHOOSER_USE_REDUCED_FONT_LIST = 'redu',			///< ::Bool @formatConstant{true} If true, restrict the available fonts to 'core' families only. Cannot be set from resource file. Used by UiConversionFontChooserImpl to restrict options exposed.
	FONTCHOOSER_ENABLE_FILTER = 'filt',							///< ::Bool @formatConstant{true} Whether font filter field should be displayed.
};
/// @}

//----------------------------------------------------------------------------------------
/// Font chooser custom GUI (::CUSTOMGUI_FONTCHOOSER) for FontData.\n
/// All items in the font container are private except for these: @enumerateEnum{FONTCHOOSER_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class FontchooserCustomGui : public BaseCustomGui<CUSTOMGUI_FONTCHOOSER>
{
private:
	FontchooserCustomGui();
	~FontchooserCustomGui();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the font container.
	/// @return												The font container.
	//----------------------------------------------------------------------------------------
	BaseContainer GetFont();

	//----------------------------------------------------------------------------------------
	/// Sets the font container.
	/// @param[in] bc									The font container.
	//----------------------------------------------------------------------------------------
	void SetFont(BaseContainer* bc);
};

//----------------------------------------------------------------------------------------
// Font chooser popup user action result. @see OpenFontChooserPopup()
//----------------------------------------------------------------------------------------
enum class FONTCHOOSER_POPUP_RESULT
{
	OK, 		///< User has selected a font.
	CANCEL 	///< User has cancelled popup, either by pressing ESC key or by clicking outside.
} MAXON_ENUM_LIST(FONTCHOOSER_POPUP_RESULT);

//----------------------------------------------------------------------------------------
/// Opens a font chooser popup at the specified position that can be closed by clicking outside or with ESC.
/// @note	If @formatParam{screenPositionX}=@em -1 and @formatParam{screenPositionY}=@em -1 the popup will be opened at the current mouse position.\n
/// 			If @formatParam{screenPositionX}=@em -2 and @formatParam{screenPositionY}=@em -2 the popup will be opened at the center of the screen.
/// @param[in] font								The initial font container.
/// @param[out] callback					Function called on user action with the result and the choosen font data. If FONTCHOOSER_POPUP_RESULT is OK, then choosen font is stored in the BaseContainer. If FONTCHOOSER_POPUP_RESULT is CANCEL, BaseContainer received is empty.
/// @param[in] useReducedFontList	If true, restrict the available fonts to 'core' families only
/// @param[in] screenPositionX		The Y position of the popup. See note above.
/// @param[in] screenPositionY		The Y position of the popup. See note above.
/// @return												@trueIfOtherwiseFalse{the popup opened successfully}
//----------------------------------------------------------------------------------------
Bool OpenFontChooserPopup(const BaseContainer& font, maxon::Delegate<void(FONTCHOOSER_POPUP_RESULT, const BaseContainer&)> callback, Bool useReducedFontList = false, Int32 screenPositionX = -1, Int32 screenPositionY = -1);

//----------------------------------------------------------------------------------------
/// Custom data (@ref FONTCHOOSER_DATA) for the font chooser GUI (FontchooserCustomGui).\n
/// All items in the font container are private except for these: @enumerateEnum{FONTCHOOSER_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class FontData : public CustomDataTypeT<FONTCHOOSER_DATA>
{
private:
	FontData();
	~FontData();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the font container.
	/// @return												The font container.
	//----------------------------------------------------------------------------------------
	BaseContainer GetFont() const;

	//----------------------------------------------------------------------------------------
	/// Sets the font container.
	/// @param[in] bc									The font container.
	//----------------------------------------------------------------------------------------
	void SetFont(const BaseContainer *bc);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _FONTCHOOSER_INTERNAL_DEF_
	class CINEWARE_SINGLEINHERITANCE iFontChooserGUI : public iBaseCustomGui
	{
		iFontChooserGUI(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class CINEWARE_SINGLEINHERITANCE iFontData
	{
	};
#else
	class iFontChooserGUI;
	class iFontData;
#endif

struct FontchooserLib : public BaseCustomGuiLib
{
	BaseContainer	(iFontChooserGUI::*GetFont)() const;
	void					(iFontChooserGUI::*SetFont)(const BaseContainer* bc);
	BaseContainer	(iFontData::*GetFontData)() const;
	void					(iFontData::*SetFontData)(const BaseContainer* bc);
	Bool					(*OpenFontChooserPopup)(const BaseContainer& font, maxon::Delegate<void(FONTCHOOSER_POPUP_RESULT, const BaseContainer&)> callback, Bool useReducedFontList, Int32 screenPositionX, Int32 screenPositionY);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema
#endif // CUSTOMGUI_FONTCHOOSER_H__
