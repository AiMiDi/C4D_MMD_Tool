/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_HTMLVIEWER_H__
#define CUSTOMGUI_HTMLVIEWER_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// HTML viewer custom GUI ID.
#define CUSTOMGUI_HTMLVIEWER	200000114

/// @addtogroup WEBPAGE
/// @ingroup group_enumeration
/// @{
#define WEBPAGE_GOBACK		0			///< Go back.
#define WEBPAGE_GOFORWARD	1			///< Go forward.
#define WEBPAGE_GOHOME		2			///< Go home.
#define WEBPAGE_SEARCH		3			///< Search.
#define WEBPAGE_REFRESH		4			///< Refresh.
#define WEBPAGE_STOP			5			///< Stop.
/// @}

/// @addtogroup URL_ENCODING
/// @ingroup group_enumeration
/// @{
#define URL_ENCODING_UTF16		0			///< String contains umlauts and spaces. The last # following the last slash is regarded as start of the anchor. (The anchor following the hash mark must be escaped!)
#define URL_ENCODING_ESCAPED	1			///< String contains an escaped url (all umlauts, spaces and other stuff that does not belong there is % according to RFC 2396.)
/// @}

//----------------------------------------------------------------------------------------
/// HTML viewer GUI URL callback. Has to be registered/unregistered with HtmlViewerCustomGui::SetURLCallback().
/// @param[in] user_data					The user data.
/// @param[in] url								The URL.
/// @param[in] encoding						The URL encoding: @enumerateEnum{URL_ENCODING}
/// @param[in,out] reserved				Reserved.
//----------------------------------------------------------------------------------------
typedef void HtmlViewerCustomGuiURLCallback(void *user_data, const maxon::String &url, Bool hasError, Int32 encoding, void *reserved);

//----------------------------------------------------------------------------------------
/// HTML viewer custom GUI (@ref CUSTOMGUI_HTMLVIEWER). Can view both local and internet HTML files using the @em http protocol.
/// @warning HTML viewer custom GUI cannot be used in modal dialogs.
//----------------------------------------------------------------------------------------
class HtmlViewerCustomGui : public BaseCustomGui<CUSTOMGUI_HTMLVIEWER>
{
	HtmlViewerCustomGui();
	~HtmlViewerCustomGui();

public:
	//----------------------------------------------------------------------------------------
	/// Sets the HTML viewer URL.
	/// @param[in] url								The new URL.
	/// @param[in] encoding						The URL encoding: @enumerateEnum{URL_ENCODING}
	//----------------------------------------------------------------------------------------
	void SetUrl(const maxon::String &url, Int32 encoding);

	//----------------------------------------------------------------------------------------
	/// Sets the HTML viewer text.
	/// @param[in] url								The new text.
	//----------------------------------------------------------------------------------------
	void SetText(const maxon::String &url);

	//----------------------------------------------------------------------------------------
	/// Do an action in the HTML viewer.
	/// @param[in] action							The action: @enumerateEnum{WEBPAGE}
	//----------------------------------------------------------------------------------------
	void DoAction(Int32 action);

	//----------------------------------------------------------------------------------------
	/// Registers the URL callback.
	/// @param[in] callback						The callback, or @formatConstant{nullptr} to disable it.
	/// @param[in] user_data					The user data. @callerOwnsPointed{data}
	//----------------------------------------------------------------------------------------
	void SetURLCallback(HtmlViewerCustomGuiURLCallback *callback, void *user_data);

	//----------------------------------------------------------------------------------------
	/// @markDeprecated Always return an empty string.
	//----------------------------------------------------------------------------------------
	String GetTextArea(const maxon::String &id);

	//----------------------------------------------------------------------------------------
	/// Converts a filename into an URL string.
	/// @param[in] f									The filename.
	/// @param[out] encoding					Assigned the URL encoding: @enumerateEnum{URL_ENCODING}
	/// @return												The URL of the filename.
	//----------------------------------------------------------------------------------------
	static String FilenameToURL(const Filename &f, Int32 *encoding);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iHtmlViewerCustomGui : public iBaseCustomGui
	{
		iHtmlViewerCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iHtmlViewerCustomGui;
#endif

struct CustomGuiHtmlViewerLib : public BaseCustomGuiLib
{
	void		(iHtmlViewerCustomGui::*SetUrl)(const maxon::String &url, Int32 encoding);
	void		(iHtmlViewerCustomGui::*DoAction)(Int32 action);
	void		(iHtmlViewerCustomGui::*SetURLCallback)(HtmlViewerCustomGuiURLCallback *callback, void *user_data);
	void		(iHtmlViewerCustomGui::*SetText)(const maxon::String &url);
	String	(*FilenameToURL)(const Filename &f, Int32 *encoding);
	String	(iHtmlViewerCustomGui::*GetTextArea)(const maxon::String &id);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_HTMLVIEWER_H__
