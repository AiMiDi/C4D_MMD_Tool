#ifndef PARSER_H__
#define PARSER_H__

#include "maxon/string.h"
#include "maxon/datadictionary.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/url.h"




namespace maxon
{

enum class PARSERFLAGS
{
	NONE						= 0,
	HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the  object.
} MAXON_ENUM_FLAGS(PARSERFLAGS);

namespace PARSERPARAMETERS
{
	class RESTRICT;

	namespace JWT
	{
		MAXON_ATTRIBUTE(StringEncodingRef, STRINGENCODING, "net.maxon.parser.args.stringencoding");
		/// public key for jwt writer to encrypt the token
		MAXON_ATTRIBUTE(BaseArray<Char>, PRIVATEKEY, "net.maxon.parser.args.privatekey");
		/// public key for jwt reader to verify the token
		MAXON_ATTRIBUTE(BaseArray<Char>, PUBLICKEY, "net.maxon.parser.args.publickey");
	}

	namespace CSV
	{
		MAXON_ATTRIBUTE(Bool, AUTODETECTDELIMITER, "net.maxon.parserparameters.csv.autodetectdelimiter", RESOURCE_DEFAULT(false));
		MAXON_ATTRIBUTE(String, DELIMITER, "net.maxon.parserparameters.csv.delimiter"); // if auto-detection is turned on delimiter is ignored.

		MAXON_ATTRIBUTE(Bool, DETECTDATATYPES, "net.maxon.parserparameters.csv.detectdatatypes", RESOURCE_DEFAULT(false));	
		MAXON_ATTRIBUTE(Bool, FORCESAMECOLUMNDATATYPE, "net.maxon.parserparameters.csv.forcecolumnsamedatatype", RESOURCE_DEFAULT(false)); // detect data types needs to be true for this to have an effect

		MAXON_ATTRIBUTE(Bool, HASHEADER, "net.maxon.parserparameters.csv.hasheader", RESOURCE_DEFAULT(true));
		MAXON_ATTRIBUTE(String, QUOTECHAR, "net.maxon.parserparameters.csv.quotechar");
		MAXON_ATTRIBUTE(Bool, HASHTAGCOMMENTS, "net.maxon.parserparameters.csv.hashtagcomments", RESOURCE_DEFAULT(true));
		MAXON_ATTRIBUTE(Bool, DOUBLEQUOTE, "net.maxon.parserparameters.csv.doublequote", RESOURCE_DEFAULT(true));
		MAXON_ATTRIBUTE(Bool, TRIMSPACES, "net.maxon.parserparameters.csv.trimspaces", RESOURCE_DEFAULT(false));
		MAXON_ATTRIBUTE(Int, ROWLIMIT, "net.maxon.parserparameters.csv.rowlimit", RESOURCE_DEFAULT(LIMIT<Int>::MAX));
	}
}

class ParserInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(ParserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.parser");
public:
	using RESTRICT_DICTIONARY_PROPS = PARSERPARAMETERS::RESTRICT;

	//----------------------------------------------------------------------------------------
	/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
	/// @param[in] nameOrStream				JSON formated input stream or file url.
	/// @param[in] flags							See JWTPARSERFLAGS.
	/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
	/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
	/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken = nullptr);

	//----------------------------------------------------------------------------------------
	/// ConvertFromJSON parses a json string into DataDictionary representation.
	/// @param[in] parserData					JSON formated string to precess.
	/// @param[in] flags							See JSONPARSERFLAGS.
	/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
	/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
	/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects);
	MAXON_FUNCTION Result<void> ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects);

	//----------------------------------------------------------------------------------------
	/// ConvertToJSON converts a data dictionary into a JSON string.
	/// @param[in] object							DataDictionary to convert.
	/// @param[out] string						Result string.
	/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting);

	//----------------------------------------------------------------------------------------
	/// WriteFile writes a object into a file or url.
	/// @param[in] out								Url or stream to write.
	/// @param[in] stringEncoding			String encoding to use.
	/// @param[in] dict								Data to write.
	/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting);
	
	//----------------------------------------------------------------------------------------
	/// GetFileExtension gives the file extension of the parser.
	/// @return the file extension as a string.
	MAXON_METHOD String GetFileExtension() const;
};

#include "parser1.hxx"
MAXON_REGISTRY(Class<ParserRef>, ParserClasses, "net.maxon.interface.registry.parserclasses");

namespace ParserClasses
{
	MAXON_DECLARATION(ParserClasses::EntryType, JsonParser, "net.maxon.interface.parserclass.json");
	MAXON_DECLARATION(ParserClasses::EntryType, JwtParser, "net.maxon.interface.parserclass.jwt");
	MAXON_DECLARATION(ParserClasses::EntryType, CsvParser, "net.maxon.interface.parserclass.csv");
}
MAXON_DECLARATION(Class<ParserRef>, ParserBaseClass, "net.maxon.interface.parserclass.base");

#include "parser2.hxx"

}



#endif // PARSER_H__

