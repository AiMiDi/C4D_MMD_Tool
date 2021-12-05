#ifndef PARSER_JSON_H__
#define PARSER_JSON_H__

#include "maxon/string.h"
#include "maxon/datadictionary.h"
#include "maxon/url.h"



namespace maxon
{

class InputStreamRef;


enum class JSONPARSERFLAGS
{
	NONE						= 0,
	HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the json object.
} MAXON_ENUM_FLAGS(JSONPARSERFLAGS);



class JsonParserInterface
{
	MAXON_INTERFACE_NONVIRTUAL(JsonParserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.jsonparser");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Interface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// ConvertToJSON converts a data dictionary into a JSON string.
	/// @param[in] jsonObject					DataDictionary to convert.
	/// @param[out] jsonString				Result string.
	/// @param[in] niceFormatting			True to have nict formatting with idents and new lines. False to get compact format (smaller filesize).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting);

	//----------------------------------------------------------------------------------------
	/// ConvertFromJSON parses a json string into DataDictionary representation.
	/// @param[in] jsonString					JSON formated string to precess.
	/// @param[in] flags							See JSONPARSERFLAGS.
	/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
	/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects);

	//----------------------------------------------------------------------------------------
	/// ConvertFromJSON parses a json stream or url into DataDictionary representation.
	/// @param[in] nameOrStream				JSON formated input stream or file url.
	/// @param[in] flags							See JSONPARSERFLAGS.
	/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
	/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding,
		const ValueReceiver<const DataDictionary&>& jsonObjects);
};



#include "parser_json1.hxx"

#include "parser_json2.hxx"



}


#endif // PARSER_JSON_H__
