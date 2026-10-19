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

namespace cinema
{

/// HTML viewer custom GUI ID.
#define CUSTOMGUI_HTMLVIEWER	200000114

/// @addtogroup HTMLVIEWER_CUSTOMGUISETTINGS HTML Viewer Custom GUI Settings
/// @ingroup CUSTOMGUISETTINGS
/// @{
/// ::Bool Enables the "Inspect Element" developer tools for this HTML viewer. Default is @formatConstant{false}.
#define HTMLVIEWER_ENABLE_INSPECT_ELEMENT 1000
/// @markPrivate
#define HTMLVIEWER_PRIVATE_1 1001
/// @markPrivate
#define HTMLVIEWER_PRIVATE_2 1002
/// @}

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
/// HTML viewer GUI resource request interception callback. Has to be registered/unregistered with HtmlViewerCustomGui::SetResourceRequestInterceptCallback().
/// @param[in] user_data					The user data.
/// @param[in] url								The URL.
/// @param[in] encoding						The URL encoding: @enumerateEnum{URL_ENCODING}
/// @param[in,out] reserved				Reserved.
//----------------------------------------------------------------------------------------
typedef maxon::Opt<maxon::BaseArray<Char>> HtmlViewerCustomGuiResourceRequestInterceptCallback(void* user_data, const maxon::String& url, Int32 encoding, void* reserved);

//----------------------------------------------------------------------------------------
/// Callback for web messages sent from the HTML viewer's JavaScript context.
/// @param[in] message						The message sent from JavaScript.
/// @param[in] user_data					The user data pointer provided during callback registration.
/// @param[in] hasError						True if the message indicates an error, false otherwise.
//----------------------------------------------------------------------------------------
typedef void HtmlViewerCustomGuiWebMessageCallback(maxon::String message, void* user_data, Bool hasError);

//----------------------------------------------------------------------------------------
/// @brief Provides a custom GUI for displaying HTML content within Cinema 4D and interacting with it via JavaScript.
/// @note See the `py-cmd_gui_html_2027` example in the Cinema 4D Python SDK for a practical demonstration of how 
/// to use this custom GUI.
/// @warning HTML viewer custom GUI cannot be used in modal dialogs.
//----------------------------------------------------------------------------------------
class HtmlViewerCustomGui : public BaseCustomGui<CUSTOMGUI_HTMLVIEWER>
{
	HtmlViewerCustomGui();
	~HtmlViewerCustomGui();

public:
	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @param[in] script							@markPrivate
	//----------------------------------------------------------------------------------------
	void ExecuteJavaScript(const maxon::String& script);

	//----------------------------------------------------------------------------------------
	/// @brief Posts a web message to the HTML viewer's JavaScript context.
	/// @details The message is delivered to @c window.maxon.messageListener, the cross-platform receive hook
	/// that behaves identically on Windows and MacOS. The page assigns a function to it; the host invokes that
	/// function with the message.
	///
	/// @warning We strongly recommend to only send JSON-encoded strings as messages to ensure proper
	/// parsing and handling. On MacOS, plain text messages containing double quotes, control characters,
	/// or other special characters may not be parsed correctly, leading to unexpected behavior. Sending
	/// pure alphanumeric strings will work on all platforms, for complex data structures, you must use JSON.
	/// @note Sending the empty string as a message is not supported and will be ignored.
	///
	/// ```javascript
	/// // Receiving the message in the web page (same code on Windows and MacOS).
	///	window.maxon.messageListener = (message) => {
  /// 	if (!message || typeof message !== 'string')
  ///			return;
	///
  ///		try {
  ///			var data = JSON.parse(message);
  ///		}
  ///		catch (error) {
  ///			return;
  ///		}
	///		// Do something with the data ...
	///	};
	/// ```
	/// @param[in] message						The message to send to JavaScript. Cannot be the empty string. We strongly recommend to send JSON-encoded strings to ensure proper parsing and handling.
	//----------------------------------------------------------------------------------------
	void PostWebMessage(const maxon::String& message);

	//----------------------------------------------------------------------------------------
	/// @brief Sets an HTTP request header that is injected on requests to @p hostname.
	/// @details Any HTTP request header can be set this way, be it a standard one (e.g. "Accept-Language") or an application-specific one.
	/// Set it before navigating with SetUrl().
	/// Call the function repeatedly to register several headers. Calling it again for the same @p name (case-insensitive)
	/// and @p hostname replaces the previously registered value; there is no way to unregister a header.
	///
	/// @note The header is applied to @b main-frame navigations only, i.e. to top-level document loads, and @b not to the sub-resource or API requests the loaded page issues (images, scripts, fetch/XHR, ...).
	/// A page that needs a header on its own API requests has to set it in JavaScript.
	/// @note On macOS the header is applied to plain page loads only, and @b not to form submissions, reloads, or back/forward navigation. Windows has no such restriction.
	/// @note Registered headers are discarded when the viewer's window is destroyed (e.g. a layout switch), so set them again from the dialog's InitValues().
	/// @note This function is not implemented on Linux (no-op).
	/// @param[in] name The header name, e.g. "Accept-Language".
	/// @param[in] value The header value, e.g. "de-DE".
	/// @param[in] hostname The host the header applies to, e.g. "example.com". Required; bare host only, no scheme, port or path.
	/// Matched exactly and case-insensitively, so a subdomain like "api.example.com" needs its own registration.
	/// @param[in] httpsOnly Send the header only over HTTPS. Default is @formatConstant{true}; pass @formatConstant{false} for a host served over plain HTTP, e.g. a local development server.
	/// @warning The header is sent on every navigation to @p hostname, including those the page triggers itself.
	//----------------------------------------------------------------------------------------
	void SetRequestHeader(const maxon::String& name, const maxon::String& value, const maxon::String& hostname, Bool httpsOnly = true);

	//----------------------------------------------------------------------------------------
	/// @brief Sets a callback for web messages sent from the HTML viewer's JavaScript context.
	/// @details The callback is triggered when JavaScript calls @c window.maxon.postMessage(msg):
	/// ```javascript
	/// function postMessage(payload) {
	/// 	window.maxon.postMessage(payload);
	/// };
	/// ```
	/// @param[in] callback						The callback function to handle web messages.
	/// @param[in] urlPartial					A partial URL to filter which messages trigger the callback.
	/// @param[in] user_data					User data pointer passed to the callback.
	//----------------------------------------------------------------------------------------
	void SetWebMessageCallback(HtmlViewerCustomGuiWebMessageCallback* callback, const maxon::String& urlPartial, void* user_data);
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


	//----------------------------------------------------------------------------------------
	/// Registers the resource request interception callback.
	/// @param[in] callback						The callback, or @formatConstant{nullptr} to disable it.
	/// @param[in] user_data					The user data. @callerOwnsPointed{data}
	//----------------------------------------------------------------------------------------
	void SetResourceRequestInterceptCallback(HtmlViewerCustomGuiResourceRequestInterceptCallback* callback, void* user_data);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class CINEWARE_SINGLEINHERITANCE iHtmlViewerCustomGui : public iBaseCustomGui
	{
		iHtmlViewerCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iHtmlViewerCustomGui;
#endif

struct CustomGuiHtmlViewerLib : public BaseCustomGuiLib
{
	void (iHtmlViewerCustomGui::*SetUrl)(const maxon::String &url, Int32 encoding);
	void (iHtmlViewerCustomGui::*DoAction)(Int32 action);
	void (iHtmlViewerCustomGui::*SetURLCallback)(HtmlViewerCustomGuiURLCallback *callback, void *user_data);
	void (iHtmlViewerCustomGui::*SetText)(const maxon::String &url);
	String (iHtmlViewerCustomGui::*GetTextArea)(const maxon::String& id);
	String (*FilenameToURL)(const Filename& f, Int32* encoding);
	void (iHtmlViewerCustomGui::*SetResourceRequestInterceptCallback)(HtmlViewerCustomGuiResourceRequestInterceptCallback* callback, void* user_data);
	void (iHtmlViewerCustomGui::*ExecuteJavaScript)(const maxon::String& script);
	void (iHtmlViewerCustomGui::*PostWebMessage)(const maxon::String& message);
	void (iHtmlViewerCustomGui::*SetWebMessageCallback)(HtmlViewerCustomGuiWebMessageCallback* callback, const maxon::String& urlPartial, void* user_data);
	void (iHtmlViewerCustomGui::*SetRequestHeader)(const maxon::String& name, const maxon::String& value, const maxon::String& hostname, Bool httpsOnly);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_HTMLVIEWER_H__
