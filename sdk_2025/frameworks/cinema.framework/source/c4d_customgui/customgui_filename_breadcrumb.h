/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_FILENAME_BREADCRUMB_H__
#define CUSTOMGUI_FILENAME_BREADCRUMB_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

namespace cinema
{

/// Filename breadcrumb custom GUI ID.
#define CUSTOMGUI_FILENAME_BREADCRUMB			200000297

/// @addtogroup FILENAME_BREADCRUMB_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define BREADCRUMB_DIRECTORY								10000			///< ::Bool Directory chooser mode.
#define BREADCRUMB_TEXTURE									10001			///< ::Bool Texture mode.
#define BREADCRUMB_SAVE											10002			///< ::Bool Save mode for chooser.
#define BREADCRUMB_READONLY									10003			///< ::Bool Read-only mode for the field.
#define BREADCRUMB_NOSELECT									10004			///< ::Bool Hide file select button.
#define BREADCRUMB_NOEDITFIELD							10005			///< ::Bool do not enter editfield mode
#define BREADCRUMB_BORDERLESS								10006			///< ::Bool Deprecated.
#define BREADCRUMB_SLASH_CODE								10007			///< ::Bool The string "_&s&_" and "_&bs&_" are replaced respectively with character "/" and "\\"
#define BREADCRUMB_HISTORY									10008			///< ::Bool History mode, keep the deepest url displayed.
/// @}

//----------------------------------------------------------------------------------------
/// Filename breadcrumb custom GUI (@ref CUSTOMGUI_FILENAME_BREADCRUMB).\n
/// Here are the settings: @enumerateEnum{FILENAME_BREADCRUMB_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class FilenameBreadCrumbCustomGui : public BaseCustomGui<CUSTOMGUI_FILENAME_BREADCRUMB>
{
		FilenameBreadCrumbCustomGui();
		~FilenameBreadCrumbCustomGui();

	public:

		static constexpr const Char* SPECIAL_FORWARDSLASH = "_&s&_"; ///< Forward slash special character
		static constexpr const Char* SPECIAL_BACKSLASH = "_&bs&_";   ///< Back slash special character

		//----------------------------------------------------------------------------------------
		/// This function can be used together with @ref BREADCRUMB_SLASH_CODE set to true, to replace slash characters
		/// with special characters @see SPECIAL_FORWARDSLASH, @see  SPECIAL_BACKSLASH so that a string with slash characters
		/// can be added to the breadcrumb url.
		/// Then before displaying, the breadcrumb will convert back those special characters to the expected slashes.
		/// @param[in,out] outString			The string from which slash characters will be replaced.
		/// @return												OK on success.
		//----------------------------------------------------------------------------------------
		static maxon::Result<void> ReplaceSlashCharacters(maxon::String& outString)
		{
			iferr_scope;
			outString.Replace('/', maxon::String(SPECIAL_FORWARDSLASH)) iferr_return;
			outString.Replace('\\', maxon::String(SPECIAL_BACKSLASH)) iferr_return;
			return maxon::OK;
		}
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
#ifndef _INTERNAL_DEF_
	class iFilenameBreadCrumbCustomGui : public iBaseCustomGui
	{
		iFilenameBreadCrumbCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iFilenameBreadCrumbCustomGui;
#endif

struct CustomGuiFilenameBreadCrumbLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_FILENAME_BREADCRUMB_H__
