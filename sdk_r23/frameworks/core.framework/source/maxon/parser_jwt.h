#ifndef PARSER_JWT_H__
#define PARSER_JWT_H__

#include "maxon/string.h"
#include "maxon/datadictionary.h"
#include "maxon/url.h"



namespace maxon
{

class InputStreamRef;


enum class JWTPARSERFLAGS
{
	NONE						= 0,
} MAXON_ENUM_FLAGS(JWTPARSERFLAGS);



class JwtParserInterface
{
	MAXON_INTERFACE_NONVIRTUAL(JwtParserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.jwtparser");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Interface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
	/// @param[in] nameOrStream				JSON formated input stream or file url.
	/// @param[in] flags							See JWTPARSERFLAGS.
	/// @param[in] publicKey					RSA256 public key to verify the JWT token.
	/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
	/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.	
	/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding,
		const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken);

	MAXON_METHOD Result<void> Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding,
		const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects);

	MAXON_METHOD Result<CString> Write(
		const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey);
};



#include "parser_jwt1.hxx"

#include "parser_jwt2.hxx"



}


#endif // PARSER_JWT_H__
