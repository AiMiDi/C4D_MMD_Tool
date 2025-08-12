#ifndef WBSOCK_JSON_CE_H__
#define WBSOCK_JSON_CE_H__

#include "maxon/interface.h"
#include "maxon/objectbase.h"
#include "maxon/fid.h"
#include "maxon/basearray.h"
#include "maxon/weakref.h"
#include "maxon/code_exchanger.h"

namespace maxon
{

class NetworkWebSocketConnectionRef;


namespace JSON_WEBSOCK
{
	// Keys used in the JSON dictionary JSON communication with VsCode Extension
	namespace KEY
	{
		static constexpr LiteralId ACTION{ "action" };
		static constexpr LiteralId VALUE{ "value" };
		static constexpr LiteralId DEBUG{ "debug" };
		static constexpr LiteralId SCRIPT_PATH{ "script_path" };
	}

	// ACTION ID for message received from the IDE
	namespace IDE2C4D
	{
		static constexpr LiteralId GET_SCRIPT_CONTENT				{ "idea2c4d.get_script_content" };
		static constexpr LiteralId SET_SCRIPT_CONTENT				{ "idea2c4d.set_script_content" };
		static constexpr LiteralId LOAD_IN_SCRIPT_MANAGER		{ "idea2c4d.load_in_script_manager" };
		static constexpr LiteralId EXECUTE_SCRIPT						{ "idea2c4d.execute" };
		static constexpr LiteralId GET_PID									{ "idea2c4d.get_pid" };
		static constexpr LiteralId GET_PATH									{ "idea2c4d.get_path" };
	}

	// ACTION ID for message send from Cinema 4D
	namespace C4D2IDE
	{
		static constexpr LiteralId SET_SCRIPT_CONTENT		{ "c4d2ide.set_script_content" };
		static constexpr LiteralId GET_PID							{ "c4d2ide.get_pid" };
		static constexpr LiteralId GET_PATH							{ "c4d2ide.get_path" };
		static constexpr LiteralId CONSOLE							{ "c4d2ide.console" };
	}
}

//----------------------------------------------------------------------------------------
/// WebSocket and JSON Python code communication for Cinema 4D and IDE(s).
///
/// Only 1 implementation of this interface is allowed and it should be singleton.
//----------------------------------------------------------------------------------------
class WebSocketJsonCodeExchangerInterface : MAXON_INTERFACE_BASES(CodeExchangerInterface)
{
	MAXON_INTERFACE(WebSocketJsonCodeExchangerInterface, MAXON_REFERENCE_NORMAL, "net.maxonsdk.interfaces.codeexchanger.websocket_json");

public:

	//----------------------------------------------------------------------------------------
	/// Retrieves a list of ongoing connections.
	///
	/// @return	Connection list with Cinema 4D and IDE.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BaseArray<WeakRef<const NetworkWebSocketConnectionRef>>* GetWebSockets();
};


#include "websocket_json_codeexchanger1.hxx"

MAXON_DECLARATION(maxon::Class<WebSocketJsonCodeExchangerRef>, WebSocketJsonCodeExchanger, "net.maxonsdk.class.codeexchanger.websocket_json");

#include "websocket_json_codeexchanger2.hxx"

}

#endif // WBSOCK_JSON_CE_H__
