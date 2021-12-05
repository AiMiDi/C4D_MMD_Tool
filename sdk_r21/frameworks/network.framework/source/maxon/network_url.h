#ifndef NETWORK_URL_H__
#define NETWORK_URL_H__


#include "maxon/datadictionary.h"
#include "maxon/fid.h"
#include "maxon/stringencoding.h"


namespace maxon
{

enum class HTTPMETHOD
{
	GET,
	POST,
	PUT,
	DELETE,
} MAXON_ENUM_LIST(HTTPMETHOD);

//----------------------------------------------------------------------------------------
/// Parameters for UrlInterface::SetData(), UrlInterface::GetData().
//----------------------------------------------------------------------------------------
namespace URLFLAGS
{
	/// Each entry in the dictionary will be added to the http request in the form "key: value\r\n".
	MAXON_ATTRIBUTE(DataDictionary, HTTP_ADDITIONAL_REQUEST_HEADER, "net.maxon.url.http_additional_request_header");
	/// Writes the response header into the datadictionary.
	MAXON_ATTRIBUTE(DataDictionary*, HTTP_RESPONSE_HEADER, "net.maxon.url.http_response_header");
	/// Set to true if a http connection should follow "301 permanently moved file" and open the moved file instead.
	MAXON_ATTRIBUTE(Bool, HTTP_FOLLOWMOVEDFILES, "net.maxon.url.http_followmovedfiles");
	/// Set to true if a you want to send a POST request, otherwise GET will be assumed.
	MAXON_ATTRIBUTE(HTTPMETHOD, HTTP_POSTMETHOD, "net.maxon.url.http_postmethod");
	/// If HTTPPOST is true, add additional data. The data needs to be url encoded. Zhe CString needs to be in the format: "<<parameter>>=<<data>>&..."
	MAXON_ATTRIBUTE(CString, HTTP_POSTDATA, "net.maxon.url.http_postdata");
	/// If a proxy Server is used set the "Cache-Control: no-cache"
	MAXON_ATTRIBUTE(Bool, HTTP_NO_PROXY_CACHING, "net.maxon.url.http_no_proxy_caching");
	/// Set to true, if gzip compression is not allowed.
	MAXON_ATTRIBUTE(Bool, HTTP_DISALLOW_GZIP, "net.maxon.url.http_disallow_gzip");
}

#include "network_url1.hxx"
#include "network_url2.hxx"

inline CString ConvertFromUnicodeToUtf8Url(const StringEncodingRef& urlEncoding, const String& src)
{
	return CString(String(CString(src, StringEncodings::Utf8()), StringDecodings::Bit8()), urlEncoding);
}


}

#endif // NETWORK_URL_H__
