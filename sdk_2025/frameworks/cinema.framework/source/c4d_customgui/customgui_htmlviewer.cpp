#include "customgui_htmlviewer.h"

namespace cinema
{

static CustomGuiHtmlViewerLib *lib_HtmlViewer = nullptr;


static CustomGuiHtmlViewerLib *CheckCustomGuiHtmlViewerLib(Int32 offset)
{
	return CheckLib<CustomGuiHtmlViewerLib>(CUSTOMGUI_HTMLVIEWER, offset, lib_HtmlViewer);
}

#define HtmlViewerCall(b) 			cinema::CustomGuiHtmlViewerLib *lib = cinema::CheckCustomGuiHtmlViewerLib(LIBOFFSET(cinema::CustomGuiHtmlViewerLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iHtmlViewerCustomGui*>(this)->*lib->b)

#define HtmlViewerCallR(a, b) 		cinema::CustomGuiHtmlViewerLib *lib = cinema::CheckCustomGuiHtmlViewerLib(LIBOFFSET(cinema::CustomGuiHtmlViewerLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iHtmlViewerCustomGui*>(this)->*lib->b)

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

void HtmlViewerCustomGui::SetURLCallback(HtmlViewerCustomGuiURLCallback *callback, void *user_data)
{
	HtmlViewerCall(SetURLCallback)(callback, user_data);
}


//----------------------------------------------------------------------------------------
// Convert a local filename to a proper URL for a web browser
// Function result:		url string
// f:									name of local html file
// encoding:					used to return the encoding (URL_ENCODING_ESCAPED or URL_ENCODING_UTF16)
//----------------------------------------------------------------------------------------
String HtmlViewerCustomGui::FilenameToURL(const Filename& f, Int32* encoding)
{
	CustomGuiHtmlViewerLib* lib = CheckCustomGuiHtmlViewerLib(LIBOFFSET(CustomGuiHtmlViewerLib, FilenameToURL));
	if (!lib || !lib->FilenameToURL)
		return String();

	return lib->FilenameToURL(f, encoding);
}


void HtmlViewerCustomGui::SetResourceRequestInterceptCallback(HtmlViewerCustomGuiResourceRequestInterceptCallback* callback, void* user_data)
{
	HtmlViewerCall(SetResourceRequestInterceptCallback)(callback, user_data);
}

} // namespace cinema
