#ifndef NETWORK_WEBSOCKET_H__
#define NETWORK_WEBSOCKET_H__

#include "maxon/interfacebase.h"
#include "maxon/observerobject.h"
#include "maxon/basearray.h"
#include "maxon/network_webserver.h"
#include "maxon/datadictionaryobject.h"



namespace maxon
{


class DataDictionary;
class NetworkHttpHandlerRef;
class NetworkWebSocketConnectionRef;
class NetworkWebSocketServerRef;


enum class WEBSOCKETSTATE
{
	NOT_CONNECTED,	///< connection is not established yet.
	CONNECTED,			///< connection is established.
	CLOSED,					///< connection is closed. Sending data is not allowed anymore.
	ERROR,					///< connection is in error state, so it's going to be closed.
} MAXON_ENUM_LIST(WEBSOCKETSTATE);

//----------------------------------------------------------------------------------------
/// Used by NetworkWebSocketConnectionInterface::Send().
//----------------------------------------------------------------------------------------
enum class WEBSOCKETTYPE
{
	TEXT,			///< text WebSocket frame.
	BINARY,		///< binary WebSocket frame.
	CLOSE,		///< @cond INTERNAL used internally for the closing handshake. @endcond
} MAXON_ENUM_LIST(WEBSOCKETTYPE);


namespace NETWORKWEBSOCKETCONNECTIONPROPERTIES
{
	class RESTRICT;
}

//----------------------------------------------------------------------------------------
/// WebSockets opcodes. See https://tools.ietf.org/html/rfc6455 for details.
//----------------------------------------------------------------------------------------
enum class WEBSOCKET_OPCODE : UChar
{
	CONTINUE = 0x0, ///< continuation frame, no data follows
	TEXT = 0x1,			///< text frame
	DATA = 0x2,			///< binary frame
	CLOSE = 0x8,		///< closing frame
	PING = 0x9,			///< ping frame
	PONG = 0xA,			///< pong frame
	ILLEGAL = 0xFF, ///< invalid state
} MAXON_ENUM_LIST(WEBSOCKET_OPCODE);

//----------------------------------------------------------------------------------------
/// Class that handles the WebSocket Protocol and an easy interface to use WebSockets.
//----------------------------------------------------------------------------------------
class NetworkWebSocketConnectionInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(NetworkWebSocketConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkwebsocketconnection");

public:
	using RESTRICT_DICTIONARY_PROPS = NETWORKWEBSOCKETCONNECTIONPROPERTIES::RESTRICT;

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// Init the object with a NetworkHttpHandlerInterface.
	/// @param[in] handler						Handler to the NetworkHandler to read/write from the http stream.
	/// @return												OK on success.
	/// @endcond
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const NetworkHttpHandlerRef& handler);

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// returns the NetworkHttpHandlerInterface connected to this object.
	/// @return												NetworkHttpHandlerRef object.
	/// @endcond
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NetworkHttpHandlerRef& GetHandler() const;

	//----------------------------------------------------------------------------------------
	/// Closes the WebSocket connection.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	//----------------------------------------------------------------------------------------
	/// Send bytes as WebProtocol message.
	/// @param[in] buffer							Buffer data to send.
	/// @param[in] type								Defines the type of the WebSocket frame to be send.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Send(const Block<const Char>& buffer, WEBSOCKETTYPE type);

	//----------------------------------------------------------------------------------------
	/// Send String as WebProtocol message.
	/// @param[in] data								Data to be send.
	/// @param[in] type								Type of the data to be send (see WEBSOCKETTYPE).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Send(const String& data, WEBSOCKETTYPE type = WEBSOCKETTYPE::TEXT);

	//----------------------------------------------------------------------------------------
	/// Returns the state of the connection.
	/// @return												Returns the state of the connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD WEBSOCKETSTATE GetState() const;
};



class NetworkWebSocketSignalInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(NetworkWebSocketSignalInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkwebsocketsignal");

public:
	//----------------------------------------------------------------------------------------
	/// Signal fired when the handshake is received and before sending back the handshake.
	/// @return												Returns optional additional header entries. they needs to be terminated by "\r\n".
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<String>, ObservableHandshake, (const NetworkWebSocketConnectionRef& webSocket, const DataDictionary& request), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Signal fired when the connection has been established.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableConnected, (const NetworkWebSocketConnectionRef& webSocket, const DataDictionary& request), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Signal fired when the connection has been closed.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableDisconnected, (const NetworkWebSocketConnectionRef& webSocket), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Signal fired when the connection throws an error.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableError, (const NetworkWebSocketConnectionRef& webSocket, const Error& err), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Signal fired when the connection receives a message.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableMessage, (const NetworkWebSocketConnectionRef& webSocket, WEBSOCKET_OPCODE opCode, const BaseArray<Char>& data), ObservableCombinerRunAllComponent);
};



class NetworkWebSocketClientConnectionInterface : MAXON_INTERFACE_BASES(NetworkWebSocketConnectionInterface, NetworkWebSocketSignalInterface)
{
	MAXON_INTERFACE(NetworkWebSocketClientConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkwebsocketclientconnection");

public:
	//----------------------------------------------------------------------------------------
	/// Start a client WebSocket connection to the given address e.g. "127.0.0.1:1234".
	/// @param[in] address						Address of the server to connect.
	/// @param[in] protocols					Comma separated list of needed protocols e.g. "chat, superchat". The server picks on of the protocols for the communication.
	/// @param[in] extraHeaderData		Add extra data to the handshake header. A entry needs to be terminated by "\r\n". e.g. "id: data\r\nid2: data2\r\n"
	/// @param[in] thread							Thread reference that is checked for IsCancelled().
	/// @return												Returns the http answer of the handshake.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> OpenConnection(
		const String& address, const String& protocols, const CString& extraHeaderData, const ThreadRef& thread);
};




class NetworkWebSocketServerInterface : MAXON_INTERFACE_BASES(NetworkWebSocketSignalInterface)
{
	MAXON_INTERFACE(NetworkWebSocketServerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkwebsocketserver");

public:
	//----------------------------------------------------------------------------------------
	/// Start a new web server using given port.
	/// @param[in] addressAndPort			Address and port which should be listened on.
	/// @param[in] waitForListener		If true the functions waits until the listener is open. Otherwise it returns immediately.
	/// @param[in] requestedProtocol	Given protocol to check within the handshake. The requestedProtocol will be compared to the
	/// 															"sec-websocket-protocol" property of the http incoming header.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StartWebServer(const NetworkIpAddrPort& addressAndPort, Bool waitForListener, const String& requestedProtocol);

	//----------------------------------------------------------------------------------------
	/// Stops the web server and closes all connections.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StopWebServer();

	//----------------------------------------------------------------------------------------
	/// Attaches the WebSocket to a running web server.
	/// @param[in] webServer					Reference to a WebServerRef object.
	/// @param[in] requestedProtocol	Given protocol to check within the handshake. The requestedProtocol will be compared to the
	/// 															"sec-websocket-protocol" property of the http incoming header.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachToWebServer(const NetworkWebServerRef& webServer, const String& requestedProtocol);

	//----------------------------------------------------------------------------------------
	/// Returns the web server connected to this object.
	/// @return												Returns the web server connected to this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NetworkWebServerRef& GetWebServer();

	//----------------------------------------------------------------------------------------
	/// Handles the client handshake.
	/// @param[in] webSocket					Socket connection to use for the handshake.
	/// @param[in] request						The web server request.
	/// @param[in] requestedProtocol	Optional parameter to check if a protocol is supported by the server. If the protocol is not found in the header the function fails.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> HandleHandShake(const NetworkWebSocketConnectionRef& webSocket, const DataDictionary& request, const String& requestedProtocol);
};




#include "network_websocket1.hxx"

MAXON_DECLARATION(Class<NetworkWebSocketConnectionRef>, NetworkWebSocketConnectionClass, "net.maxon.class.networkwebsocketconnection");
MAXON_DECLARATION(Class<NetworkWebSocketSignalRef>, NetworkWebSocketSignalClass, "net.maxon.class.networkwebsocketsignal");
MAXON_DECLARATION(Class<NetworkWebSocketServerRef>, NetworkWebSocketServerClass, "net.maxon.class.networkwebsocketserver");
MAXON_DECLARATION(Class<NetworkWebSocketClientConnectionRef>, NetworkWebSocketClientConnectionClass, "net.maxon.class.networkwebsocketclientconnection");


#include "network_websocket2.hxx"

}


#endif // NETWORK_WEBSOCKET_H__
