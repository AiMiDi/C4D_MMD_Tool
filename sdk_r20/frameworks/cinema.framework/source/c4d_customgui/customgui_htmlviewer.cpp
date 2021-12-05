#include "customgui_htmlviewer.h"

static CustomGuiHtmlViewerLib *lib_HtmlViewer = nullptr;


static CustomGuiHtmlViewerLib *CheckCustomGuiHtmlViewerLib(Int32 offset)
{
	return (CustomGuiHtmlViewerLib*)CheckLib(CUSTOMGUI_HTMLVIEWER, offset, (C4DLibrary**)&lib_HtmlViewer);
}

#define HtmlViewerCall(b) 			CustomGuiHtmlViewerLib *lib = CheckCustomGuiHtmlViewerLib(LIBOFFSET(CustomGuiHtmlViewerLib, b)); \
															if (!lib || !lib->b) return; \
															(((iHtmlViewerCustomGui*)this)->*lib->b)

#define HtmlViewerCallR(a, b) 		CustomGuiHtmlViewerLib *lib = CheckCustomGuiHtmlViewerLib(LIBOFFSET(CustomGuiHtmlViewerLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iHtmlViewerCustomGui*)this)->*lib->b)

void HtmlViewerCustomGui::SetUrl(const maxon::String &str, Int32 encoding)
{
	HtmlViewerCall(SetUrl)(str, encoding);
}

String HtmlViewerCustomGui::GetTextArea(const maxon::String &id)
{
	HtmlViewerCallR(String(), GetTextArea)(id);
}

void HtmlViewerCustomGui::SetText(const maxon::String &str)
{
	HtmlViewerCall(SetText)(str);
}

void HtmlViewerCustomGui::DoAction(Int32 action)
{
	HtmlViewerCall(DoAction)(action);
}

void	HtmlViewerCustomGui::SetURLCallback(HtmlViewerCustomGuiURLCallback *callback, void *user_data)
{
	HtmlViewerCall(SetURLCallback)(callback, user_data);
}

//----------------------------------------------------------------------------------------
// Convert a local filename to a proper URL for a web browser
// Function result:		url string
// f:									name of local html file
// encoding:					used to return the encoding (URL_ENCODING_ESCAPED or URL_ENCODING_UTF16)
//----------------------------------------------------------------------------------------
String	HtmlViewerCustomGui::FilenameToURL(const Filename &f, Int32 *encoding)
{
	CustomGuiHtmlViewerLib *lib = CheckCustomGuiHtmlViewerLib(LIBOFFSET(CustomGuiHtmlViewerLib, FilenameToURL));
	if (!lib || !lib->FilenameToURL) return String();

	return lib->FilenameToURL(f, encoding);
}
