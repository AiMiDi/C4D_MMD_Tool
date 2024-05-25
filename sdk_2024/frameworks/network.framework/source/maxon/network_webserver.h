#ifndef NETWORK_WEBSERVER_H__
#define NETWORK_WEBSERVER_H__

#include "maxon/datadictionary.h"
#include "maxon/datetime.h"
#include "maxon/network_httperror.h"
#include "maxon/network_ip.h"
#include "maxon/network_url.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/range.h"
#include "maxon/stringencoding.h"
#include "maxon/thread.h"
#include "maxon/url.h"



namespace maxon
{

class NetworkWebServerRef;
class NetworkHttpHandlerRef;

using HandleRequestDelegate = Delegate<Result<void>(const NetworkWebServerRef& server, const NetworkHttpHandlerRef& remoteConnection, const String& file, const DataDictionary& request)>;

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// The result is combined by an OR operation.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, CombinerHttpCodeComponents, "net.maxon.component.combinerhttpcodecomponents");


//----------------------------------------------------------------------------------------
/// Easy interface to create and start a web server and handling http requests.
/// The web server starts several threads that handles the requests.
/// So make sure that you keep the handle as long as the server is running.
//----------------------------------------------------------------------------------------
class NetworkWebServerInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(NetworkWebServerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkwebserver");

public:
	//----------------------------------------------------------------------------------------
	/// Init initializes the web server object and tells which port should be used.
	/// @param[in] useSSL							Should the server use SSL/TLS?
	/// @param[in] serverIpAndPort		Server ip and port. If addr is 0.0.0.0 the server will be bound to all interfaces. If serverPort is 0,
	///																the system chooses an port. Otherwise the port needs to be in the range 0 < port < 10000.
	/// @param[in] serverName					Name of the server (only 'a..z''A..Z' are valid).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Bool useSSL, const NetworkIpAddrPort& serverIpAndPort, const String& serverName);

	//----------------------------------------------------------------------------------------
	/// Returns the server port. If 0 was given at Init() the serverport is only available after starting the server.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetServerPort() const;

	//----------------------------------------------------------------------------------------
	/// Returns the server name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetServerName() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the server uses the SSL/TLS protocol.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsUsingSSL() const;

	//----------------------------------------------------------------------------------------
	/// Starts the web server.
	/// @param[in] waitForListener		If true the functions waits until the listener is open. Otherwise it returns immediately.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StartServer(Bool waitForListener);

	//----------------------------------------------------------------------------------------
	/// Stops the web server.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StopServer();

	//----------------------------------------------------------------------------------------
	/// RegisterRequest allows to add callback delegates to handle urls.
	/// If the handler returns "HttpCodeError(MAXON_SOURCE_LOCATION, HTTPCODE::CALL_NEXT_HANDLER)" the next handler is called.
	/// @param[in] file								Url to catch. if the string ends with a "*" the pattern will be matched.
	/// @param[in] requestDelegate		Delegate to call.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RegisterRequest(const String& file, HandleRequestDelegate&& requestDelegate);

	//----------------------------------------------------------------------------------------
	/// ObservableHandleRequest is fired as soon as a client connects to the server. For each connection a new thread is spawned.
	/// @param[in] server							Reference to the server object.
	/// @param[in] remoteConnection		Reference to the remote connection. This handle allows to read and write from the ip stream.
	/// @param[in] request						The pre-translated http request from the server. See HTTPREQUEST for details.
	///																Predefined values can be found under it's id. All unknown header informations can be found under
	///																a string as the key of the dictionary. Try DiagnosticOutput("@", request); to see all members of the dictionary.
	/// @return												Return HTTPCODE::FINISHED if the request has been successfully replied.
	///																Return HTTPCODE::CALL_NEXT_HANDLER to call the next handler in the queue. Return a error code to respond with the error code.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableHandleRequest, (const NetworkWebServerRef& server, const NetworkHttpHandlerRef& remoteConnection, const DataDictionary& request), CombinerHttpCodeComponents);
};



//----------------------------------------------------------------------------------------
/// Interface to access more high level functions to read/send from NetworkConnectionRef.
/// This functions are used by the web server to read and send data.
//----------------------------------------------------------------------------------------
class NetworkIpHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NetworkIpHandlerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkiphandler");

public:

	//----------------------------------------------------------------------------------------
	/// Initializes the object with a NetworkConnectionRef. This might be an incoming or outgoing connection.
	/// @param[in] connection					NetworkConnectionRef for low level ip access.
	/// @param[in] webServer					Optional parameter to a NetworkWebServerRef.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitConnection(const NetworkConnectionRef& connection, const NetworkWebServerRef& webServer);

	//----------------------------------------------------------------------------------------
	/// Returns the NetworkConnectionRef connected to this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkConnectionRef GetConnection() const;

	//----------------------------------------------------------------------------------------
	/// Returns the NetworkWebServerRef connected to this object. It may return nullptr if no server is set in this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkWebServerRef GetWebServer() const;

	//----------------------------------------------------------------------------------------
	/// Reads the requested number of bytes from the connection.
	/// The function will not return before the number of requested bytes has been read or an error occurred.
	/// @param[in] data								Block for the data to be received.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RecvBytes(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Reads the requested number of bytes from the connection to the end of the stream.
	/// The function will not return before the number of requested bytes has been read, an error occurred or the stream has been closed.
	/// @param[in] data								Block for the data to be received.
	/// @return												Returns the number of bytes read or the error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RecvBytesEOS(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Reads data up to the next return character in the stream.
	/// @param[out] str								Reference to a string which receives the data.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReadLine(String& str);

	//----------------------------------------------------------------------------------------
	/// Sends data to the connection. Please note that you need to call FlushWriteBuffer() before the data goes out.
	/// The functions tries to cache as much as possible before sending each bit separately.
	/// @param[in] buffer							Block with the data to send.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendBytes(const Block<const Byte>& buffer);

	//----------------------------------------------------------------------------------------
	/// Sends a String.
	/// Please note that you need to call FlushWriteBuffer() before the data goes out.
	/// The functions tries to cache as much as possible before sending each bit separately.
	/// @param[in] str								Data string to be send.
	/// @param[in] encoding						String encoding that should be used to convert into 8-bit chars.
	/// @param[in] size								-1 for the complete string. Otherwise the string is sent only with a shortened length.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> SendString(const String& str, const StringEncodingRef& encoding = StringEncodings::Utf8(), Int size = -1)
	{
		iferr (BaseArray<Char> buf = str.GetCString(encoding))
			return err;
		return SendBytes(ToBlock(buf.GetFirst(), size == -1 ? buf.GetCount() : Min(size, buf.GetCount())));
	}

	//----------------------------------------------------------------------------------------
	/// Sends a CString.
	/// Please note that you need to call FlushWriteBuffer() before the data goes out.
	/// The functions tries to cache as much as possible before sending each bit separately.
	/// @param[in] str								Data string to be send.
	/// @param[in] size								-1 for the complete string. Otherwise the string is sent only with a shortened length.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> SendString(const CString& str, Int size = -1)
	{
		const Char* buf = (const Char*)str;
		return SendBytes(ToBlock(buf, size == -1 ? str.GetLength() : Min(size, str.GetLength())));
	}

	//----------------------------------------------------------------------------------------
	/// Flushes the write cache and forces the data to be send out.
	/// @return												True if the functions was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FlushWriteBuffer();
};



//----------------------------------------------------------------------------------------
/// Interface to access more high level functions to read/send data with http connections.
/// This functions are used by the web server to read and send data.
//----------------------------------------------------------------------------------------
class NetworkHttpHandlerInterface : MAXON_INTERFACE_BASES(NetworkIpHandlerInterface)
{
	MAXON_INTERFACE(NetworkHttpHandlerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkhttphandler");
public:
	//----------------------------------------------------------------------------------------
	/// Opens an outgoing http connection.
	/// @param[in] address						Connection address e.g. "127.0.0.1:80" or "www.maxon.de:8080".
	/// @param[in] thread							Reference to the handling thread. this thread is checked for the is cancelled state.
	/// @param[in] connectionTimeOut	Timeout during the first connect.
	/// @param[in] sessiontimeOut			Timeout for the session in seconds. if SOCKETTIMEOUT_INDEFINITELY is used a thread is needed.
	/// @return												True if the connection could be opened.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> OpenConnection(const String& address, const ThreadRef& thread, TimeValue connectionTimeOut, TimeValue sessiontimeOut);

	//----------------------------------------------------------------------------------------
	/// Determines the mine type depending of the file.
	/// @param[in] file								File name of the file which type should be determined.
	/// @return												Mime type. E.g. "image/jpg".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetMimeType(const Url& file) const;

	//----------------------------------------------------------------------------------------
	/// Creates an http request header for a server.
	/// The default values for the header are:
	/// -"Host: <<hostName without port>>".
	/// -"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8".
	/// -"User-Agent: Maxon Computer GmbH".
	/// -"Accept-Encoding: gzip" if range is empty.
	/// -"Content-Type: application/x-www-form-urlencoded" if isPost is true.
	/// -"Content-Length: <<postData.GetCount()>>" if isPost is true.
	///
	/// @param[in] method							HTTP method.
	/// @param[in] proxyScheme				An empty Id if this is not a proxy request. Otherwise the scheme (e.g. "http") of the request. In that case the "<<scheme>>://<<hostName>>" and "Proxy-Connection: keep-alive" will be added to the request.
	/// @param[in] allowGzip					True if the request allows gzip compression.
	/// @param[in] hostName						Host name with the port. In case of a proxy this name will be added to the request  (e.g. "www.maxon.de:80").
	/// 															This name without the port will be added to the "Host:" field.
	/// @param[in] fileName						The path of the request. E.g. "/file/index.html". This name must start with a '/'.
	/// @param[in] queryParameter			Query parameter for the request. Usually they will be concatenated with a '?' to the fileName.
	/// @param[in] range							If range is not empty the request will add a "Range: bytes=@-" if maxRange is LIMIT<Int64>::MAX or "Range: bytes=@-@" otherwise.
	/// @param[in] optionalTags				Optional parameter, if given each entry in the dictionary will be added to the request in the form: "key: value\r\n".
	/// @param[in] postData						Optional parameter, if given this contains the block of data for the post request added to the post.
	/// @return												The string with a valid http request header.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CString> CreateRequestHeader(HTTPMETHOD method, const UrlScheme& proxyScheme, Bool allowGzip, const String& hostName,
		const String& fileName, const String& queryParameter, const Range<Int64>& range, const DataDictionary& optionalTags = DataDictionary(),
		const Block<const Char>& postData = Block<const Char>()) const;

	//----------------------------------------------------------------------------------------
	/// Creates an http answer header for a given mime type.
	/// @param[in] mime								Mime type of the data to be send. If not IsEmpty() the "content-type" field will be created.
	/// @param[in] size								Size of the data to be send. If not 0 the "content-length" field will be created.
	/// @param[in] code								Code the is used for the http header code. "HTTP/1.0 <<_code_>>" is generated.
	/// @param[in] refresh						If > 0 the "refresh" field will be created. This forces the browser to reload the site every refresh seconds.
	/// @param[in] expires						Defines the date when this object has to be reloaded. Use DateTime() to disable caching.
	/// @return												The string with a valid http header.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CString CreateAnswerHeader(const String& mime, Int64 size, HTTPCODE code = HTTPCODE::OK, Int refresh = -1, const UniversalDateTime& expires = UniversalDateTime()) const;

	MAXON_METHOD Result<DataDictionary> ReadRequest();
	MAXON_METHOD Result<DataDictionary> ReadAnswer();

	MAXON_METHOD Result<void> SendHtmlFile(const Url& path, Bool usemime, Bool del = false, const UniversalDateTime& expires = UniversalDateTime());
	MAXON_METHOD Result<void> SendRedirect(const String& location);

	MAXON_METHOD Result<void> HandleGet(const Url& basePath, const DataDictionary& request);
	MAXON_METHOD Result<DataDictionary> HandlePost(const DataDictionary& request, const Url& upload);

	MAXON_METHOD Result<void> LoadHtmlFile(const Url& file, String& html);
	MAXON_METHOD Result<void> SubstInHtml(String& html, const DataDictionary& data);
	MAXON_METHOD Result<void> LssHtmlFile(const Url& file, const DataDictionary& data, HTTPCODE code = HTTPCODE::OK, Int refresh = -1);

	MAXON_METHOD String KillPercentChar(const String& name);

	MAXON_METHOD Result<void> DoIt();
};

enum class HTTPREQUESTTYPE
{
	UNKNOWN,
	GET,
	POST
} MAXON_ENUM_LIST(HTTPREQUESTTYPE);

template <> inline void Data::InitSet(HTTPREQUESTTYPE&& d)
{
	InitSet((Int32)d);
}

namespace HTTPREQUEST
{
	MAXON_ATTRIBUTE(HTTPREQUESTTYPE, TYPE, "net.maxon.http.type");	///< type of the request.
	MAXON_ATTRIBUTE(String, FILE, "net.maxon.http.file");						///< path and file requested by the client
	MAXON_ATTRIBUTE(String, PARAMETER, "net.maxon.http.parameter");						///< parameter list of the request behind the "?"
	MAXON_ATTRIBUTE(String, USERNAME, "net.maxon.http.username");						///< authorization: basic: username
	MAXON_ATTRIBUTE(String, PASSWORD, "net.maxon.http.password");						///< authorization: basic: password
	MAXON_ATTRIBUTE(String, BOUNDARY, "net.maxon.http.boundary");						///< boundary=
	MAXON_ATTRIBUTE(String, CONTENTTYPE, "net.maxon.http.contenttype");						///< Type of the data
	MAXON_ATTRIBUTE(Int64, CONTENTLENGTH, "net.maxon.http.contentlength");						///< Length of the data in bytes
	MAXON_ATTRIBUTE(String, CONNECTION, "net.maxon.http.connection");						///< Type of the connection. E.g. "keep-alive" or "upgrade"
}


namespace HTTPANSWER
{
	// HTTP/1.1 101 Switching Protocols
	MAXON_ATTRIBUTE(Int, MAJORVERSION, "net.maxon.http.majorversion");							///< major version of the http protocol
	MAXON_ATTRIBUTE(Int, MINORVERSION, "net.maxon.http.minorversion");							///< minor version of the http protocol
	MAXON_ATTRIBUTE(Int, HTTPCODE, "net.maxon.http.httpcode");							///< http code, e.g. 101
	MAXON_ATTRIBUTE(String, HTTPMESSAGE, "net.maxon.http.httpmessage");						///< http message e.g. "Switching Protocols"
}




#include "network_webserver1.hxx"

//----------------------------------------------------------------------------------------
/// object definitions
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NetworkIpHandlerRef>, NetworkIpHandlerClass, "net.maxon.class.networkiphandler");
MAXON_DECLARATION(Class<NetworkHttpHandlerRef>, NetworkHttpHandlerClass, "net.maxon.class.networkhttphandler");
MAXON_DECLARATION(Class<NetworkWebServerRef>, NetworkWebServerClass, "net.maxon.class.networkwebserver");

#include "network_webserver2.hxx"

}



#endif // NETWORK_WEBSERVER_H__
