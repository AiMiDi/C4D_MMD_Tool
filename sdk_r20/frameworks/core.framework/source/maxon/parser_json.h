#ifndef PARSER_JSON_H__
#define PARSER_JSON_H__

#include "maxon/string.h"
#include "maxon/datadictionary.h"



namespace maxon
{

class InputStreamRef;


enum class NETWORKPROTOCOLJSONFLAGS
{
	NONE						= 0,
	HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the json object.
} MAXON_ENUM_FLAGS(NETWORKPROTOCOLJSONFLAGS);



class NetworkProtocolJSONInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkProtocolJSONInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkprotocoljson");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Interface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	MAXON_METHOD Result<void> ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting);
	MAXON_METHOD Result<void> ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject);
	MAXON_METHOD Result<void> ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject);
};



#include "parser_json1.hxx"

#include "parser_json2.hxx"



}


#endif // PARSER_JSON_H__
