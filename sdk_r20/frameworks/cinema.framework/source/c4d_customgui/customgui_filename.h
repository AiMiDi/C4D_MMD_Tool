/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_FILENAME_H__
#define CUSTOMGUI_FILENAME_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// Filename custom GUI ID.
#define CUSTOMGUI_FILENAME			1000478

/// @addtogroup FILENAME_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define FILENAME_DIRECTORY			10000			///< ::Bool Directory chooser mode.
#define FILENAME_TEXTURE				10001			///< ::Bool Texture mode.
#define FILENAME_SAVE						10002			///< ::Bool Save mode for chooser.
#define FILENAME_READONLY				10003			///< ::Bool Read-only mode for the edit text field.
#define FILENAME_NOSELECT				10004			///< ::Bool Hides the file selection button.
#define FILENAME_TOKENPOPUP			10005			///< ::Bool Displays the token popup. @since R17.048
/// @}

//----------------------------------------------------------------------------------------
/// Filename custom GUI (@ref CUSTOMGUI_FILENAME).\n
/// Here are the settings: @enumerateEnum{FILENAME_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class FilenameCustomGui : public BaseCustomGui<CUSTOMGUI_FILENAME>
{
		FilenameCustomGui();
		~FilenameCustomGui();

	public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iFilenameCustomGui : public iBaseCustomGui
	{
		iFilenameCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iFilenameCustomGui;
#endif

struct CustomGuiFilenameLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_FILENAME_H__
