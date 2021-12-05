#ifndef STRINGENCODING_H__
#define STRINGENCODING_H__

#include "maxon/streamconversion.h"

namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringEncodingRef is able to convert Utf32Char to UChar data.
//----------------------------------------------------------------------------------------
class StringEncodingInterface : MAXON_INTERFACE_BASES(StreamConversionInterface)
{
	MAXON_INTERFACE(StringEncodingInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.stringencoding");
public:
};

//----------------------------------------------------------------------------------------
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringDecodingRef is able to convert UChar to Utf32Char data.
//----------------------------------------------------------------------------------------
class StringDecodingInterface : MAXON_INTERFACE_BASES(StreamConversionInterface)
{
	MAXON_INTERFACE(StringDecodingInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.stringdecoding");
public:
};

#include "stringencoding1.hxx"

MAXON_REGISTRY(StringEncodingRef, StringEncodings, "net.maxon.registry.stringencodings");
MAXON_REGISTRY(StringDecodingRef, StringDecodings, "net.maxon.registry.stringdecodings");


//----------------------------------------------------------------------------------------
/// This Macro can be used to register an implementation of a stream en-/decoder.
/// @param[in] EXTENSION					Registry to extend. (e.g. StringEncodings or StringDecodings).
/// @param[in] CATEGORY						Encoder or Decoder.
/// @param[in] IDSTR							Lowercase string with the id to be registered. e.g. "utf8".
/// @param[in] IDSYM							Mixed case id with the id to be registered. e.g. Utf8.
/// @param[in] IMPLCLASS					Implementation class name.
//----------------------------------------------------------------------------------------
#define REGISTER_STRINGENCODING(EXTENSION, CATEGORY, IDSYM, IMPLCLASS) \
	MAXON_COMPONENT_OBJECT_REGISTER(IMPLCLASS, EXTENSION::IDSYM); \
	MAXON_DECLARATION_REGISTER(maxon::StreamConversions::String##IDSYM##CATEGORY) \
	{ \
		iferr (auto r = maxon::StreamConversionFactory::CreateObjectFactory(&IMPLCLASS::FactoryInit)) \
			return err; \
		return maxon::ConvertStreamConversionRef<maxon::StreamConversionRef>(r); \
	}

//----------------------------------------------------------------------------------------
/// This Macro can be used to register an implementation of a stream en-/decoder with a impl template class.
/// @param[in] EXTENSION					Registry to extend. (e.g. StringEncodings or StringDecodings).
/// @param[in] CATEGORY						Encoder or Decoder.
/// @param[in] IDSTR							Lowercase string with the id to be registered. e.g. "utf8".
/// @param[in] IDSYM							Mixed case id with the id to be registered. e.g. Utf8.
/// @param[in] IMPLCLASS					Implementation class name.
//----------------------------------------------------------------------------------------
#define REGISTER_STRINGENCODING_TEMPLATE(EXTENSION, CATEGORY, IDSYM, IMPLCLASS) \
	MAXON_COMPONENT_OBJECT_REGISTER_TEMPLATE(IMPLCLASS, EXTENSION::IDSYM); \
	MAXON_DECLARATION_REGISTER(maxon::StreamConversions::String##IDSYM##CATEGORY) \
	{ \
		iferr (auto r = maxon::StreamConversionFactory::CreateObjectFactory(&IMPLCLASS::FactoryInit)) \
			return err; \
		return maxon::ConvertStreamConversionRef<maxon::StreamConversionRef>(r); \
	}

//----------------------------------------------------------------------------------------
/// This Macro adds a given string encoding to the 3 registries: StringEncodings, StringDecodings and StreamConversions.
/// @param[in] IDSTR							Lowercase string with the id to be registered. e.g. "utf8".
/// @param[in] IDSYM							Mixed case id with the id to be registered. e.g. Utf8.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARATION_STRINGENCODING(IDSTR, IDSYM) \
	namespace StringEncodings \
	{ \
		MAXON_DECLARATION(maxon::StringEncodingRef, IDSYM, "net.maxon.stringencoding." IDSTR); \
	} \
	namespace StringDecodings \
	{ \
		MAXON_DECLARATION(maxon::StringDecodingRef, IDSYM, "net.maxon.stringdecoding." IDSTR); \
	} \
	namespace StreamConversions \
	{ \
		MAXON_DECLARATION(maxon::StreamConversionFactory, String##IDSYM##Encoder, "net.maxon.streamconversion." IDSTR "enc"); \
		MAXON_DECLARATION(maxon::StreamConversionFactory, String##IDSYM##Decoder, "net.maxon.streamconversion." IDSTR "dec"); \
	}


//----------------------------------------------------------------------------------------
/// <H1>SystemCodePage</H1>
/// - SystemCodePage encodes characters from Utf32Char to the active system code page (UChar).
/// - SystemCodePage decodes characters from the active systemcodepage (UChar) to Utf32Char
///
/// <B>Details:</B><BR>
/// - this encoder/decoder uses system functions for the encoding. Under windows
/// [ http://msdn.microsoft.com/en-us/library/windows/desktop/dd319072(v=vs.85).aspx ]MultiByteToWideChar and
/// [ http://msdn.microsoft.com/en-us/library/windows/desktop/dd374130(v=vs.85).aspx ]WideCharToMultiByte are used.
///
/// <B>Errors:</B><BR>
/// Returns an error if the system functions return errors.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("systemcodepage", SystemCodePage)

//----------------------------------------------------------------------------------------
/// <HR>
/// <H1>Bit8</H1>
/// - encodes characters from Utf32Char to UChar
/// - decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// - characters in the range 0..255 are encoded as single byte values
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("bit8", Bit8)

//----------------------------------------------------------------------------------------
/// <HR>
/// <H1>Bit7Hex</H1>
/// - encodes characters from UniChar to UChar
/// - decodes characters from UChar to UniChar
///
/// <B>Details:</B><BR>
/// - characters in the range 0..127 are encoded as single byte values
/// - characters above 127 are encoded into a sequence of bytes with the format @\uhhhh
/// where each hhhh is the hex value representing the character in Unicode space.
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("hex7", Bit7Hex)


//----------------------------------------------------------------------------------------
/// <HR>
/// <H1>UTF-8</H1>
/// - encodes characters from Utf32Char to UChar
/// - decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// UTF-8 (UCS Transformation Format-8-bit) is a variable-width encoding that can represent every character in the Unicode character set.
/// Depending on the number range a UniCode character is encoded in either a single byte or multiple bytes where the byte sequence starts with a leading byte followed by one or more continuation bytes.
/// Currently the 32bit UniCode range below 0x10000 is supported (resulting in up to 4 byte sequences)
///
/// <B>Errors:</B><BR>
/// Returns an error if byte code sequences (unicode >=0x10000) with more then 4 bytes are used for decoding.
///
/// @note UTF-8 was designed for backward compatibility with ASCII and to avoid the complications of endianness and byte order marks in UTF-16 and UTF-32.
/// UTF-8 has become the dominant character encoding for the World Wide Web, accounting for more than half of all Web pages.
/// The Internet Mail Consortium (IMC) recommends that all e-mail programs be able to display and create mail using UTF-8.
/// UTF-8 is also increasingly being used as the default character encoding in operating systems, programming languages, APIs, and software applications.
/// More details can be found here: http://en.wikipedia.org/wiki/UTF-8
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("utf8", Utf8)

//----------------------------------------------------------------------------------------
/// <HR>
/// <H1>UTF-16</H1>
/// - encodes characters from Utf32Char to UTF-16
/// - decodes characters from UTF-16 to Utf32Char
///
/// <B>Details:</B><BR>
/// UTF-16 is a variable-width encoding that can represent every character in the Unicode character set.
/// Depending on the number range a UniCode character is encoded in either a single or two 16-bit values.
///
/// <B>Errors:</B><BR>
/// Returns an error if an illegal code sequence is detected during decoding.
///
/// More details can be found here: http://en.wikipedia.org/wiki/UTF-16
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("utf16", Utf16)

//----------------------------------------------------------------------------------------
/// <H1>Url</H1>
/// - Url encodes characters from Utf32Char to UChar
/// - Url decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// - only characters in the range 0..255 are accepted
/// - all characters which are not Unreserved Characters are encoded using percent encoding-
/// for example the space character " " is encoded as "%20"
/// More details can be found here: http://www.ietf.org/rfc/rfc3986.txt
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("url", Url)
MAXON_DECLARATION_STRINGENCODING("url32", Url32)

//----------------------------------------------------------------------------------------
/// <H1>Url</H1>
/// - Url encodes characters from Utf32Char to UChar
/// - Url decodes characters from UChar to Utf32Char
///

/// <B>Details:</B><BR>
/// - only characters in the range 0..255 are accepted
/// - all characters which are not Unreserved Characters are encoded using percent encoding-
/// for example the space character " " is encoded as "%20"
/// More details can be found here: http://www.ietf.org/rfc/rfc3986.txt
/// - additionally the backslash '\' is a reserved character and hence ignored for encoding
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("urlpath", UrlPath)

//----------------------------------------------------------------------------------------
/// <H1>Url</H1>
/// - Url encodes characters from Utf32Char to UChar
/// - Url decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// - only characters in the range 0..255 are accepted
/// - all characters which are not Unreserved Characters are encoded using percent encoding-
/// for example the space character " " is encoded as "%20"
/// More details can be found here: http://www.ietf.org/rfc/rfc3986.txt
/// - additionally the characters '&', '=', '$', '+', ',', ':', ';' and '@' are reserved characters and hence ignored for encoding
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("urlquery", UrlQuery)

//----------------------------------------------------------------------------------------
/// <HR>
/// <H1>CodePage437</H1>
/// - encodes characters from Utf32Char to UChar
/// - decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// - characters in the range 0..255 are encoded using the codepage 437.
/// more details see: http://en.wikipedia.org/wiki/Codepage_437
///
/// <B>Errors:</B><BR>
/// Returns an error if character codes outside the valid range are used.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("codepage437", CodePage437)


#include "stringencoding2.hxx"

/// @}

} // namespace maxon



#endif // STRINGENCODING_H__
