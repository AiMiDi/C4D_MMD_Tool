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

/// @addtogroup FONTCHOOSER_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
enum
{
	FONTCHOOSER_ENABLE_SIZE = 'size'								///< ::Bool @formatConstant{true} if the size popup should be displayed.
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
/// Custom data (@ref FONTCHOOSER_DATA) for the font chooser GUI (FontchooserCustomGui).\n
/// All items in the font container are private except for these: @enumerateEnum{FONTCHOOSER_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class FontData : public CustomDataType
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
	void SetFont(BaseContainer *bc);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _FONTCHOOSER_INTERNAL_DEF_
	class iFontChooserGUI : public iBaseCustomGui
	{
		iFontChooserGUI(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iFontData
	{
	};
#else
	class iFontChooserGUI;
	class iFontData;
#endif

struct FontchooserLib : public BaseCustomGuiLib
{
	BaseContainer	(iFontChooserGUI::*GetFont)() const;
	void					(iFontChooserGUI::*SetFont)(BaseContainer* bc);
	BaseContainer	(iFontData::*GetFontData)() const;
	void					(iFontData::*SetFontData)(BaseContainer* bc);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_FONTCHOOSER_H__
