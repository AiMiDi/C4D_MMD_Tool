#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(StringEncodingInterface, "net.maxon.interface.stringencoding", "maxon.StringEncodingInterface", , &StreamConversionInterface::_interface);
	const maxon::Char* const StringEncodingInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int StringEncodingInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(StringDecodingInterface, "net.maxon.interface.stringdecoding", "maxon.StringDecodingInterface", , &StreamConversionInterface::_interface);
	const maxon::Char* const StringDecodingInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int StringDecodingInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_REGISTRY_REGISTER(StringEncodings);
	MAXON_REGISTRY_REGISTER(StringDecodings);
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemCodePage, , "net.maxon.stringencoding.systemcodepage");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemCodePage, , "net.maxon.stringdecoding.systemcodepage");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringSystemCodePageEncoder, , "net.maxon.streamconversion.systemcodepageenc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringSystemCodePageDecoder, , "net.maxon.streamconversion.systemcodepagedec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Bit8, , "net.maxon.stringencoding.bit8");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Bit8, , "net.maxon.stringdecoding.bit8");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringBit8Encoder, , "net.maxon.streamconversion.bit8enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringBit8Decoder, , "net.maxon.streamconversion.bit8dec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Bit7Hex, , "net.maxon.stringencoding.hex7");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Bit7Hex, , "net.maxon.stringdecoding.hex7");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringBit7HexEncoder, , "net.maxon.streamconversion.hex7enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringBit7HexDecoder, , "net.maxon.streamconversion.hex7dec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Utf8, , "net.maxon.stringencoding.utf8");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Utf8, , "net.maxon.stringdecoding.utf8");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUtf8Encoder, , "net.maxon.streamconversion.utf8enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUtf8Decoder, , "net.maxon.streamconversion.utf8dec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Utf16, , "net.maxon.stringencoding.utf16");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Utf16, , "net.maxon.stringdecoding.utf16");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUtf16Encoder, , "net.maxon.streamconversion.utf16enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUtf16Decoder, , "net.maxon.streamconversion.utf16dec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Url, , "net.maxon.stringencoding.url");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Url, , "net.maxon.stringdecoding.url");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlEncoder, , "net.maxon.streamconversion.urlenc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlDecoder, , "net.maxon.streamconversion.urldec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Url32, , "net.maxon.stringencoding.url32");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Url32, , "net.maxon.stringdecoding.url32");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrl32Encoder, , "net.maxon.streamconversion.url32enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrl32Decoder, , "net.maxon.streamconversion.url32dec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UrlPath, , "net.maxon.stringencoding.urlpath");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UrlPath, , "net.maxon.stringdecoding.urlpath");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlPathEncoder, , "net.maxon.streamconversion.urlpathenc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlPathDecoder, , "net.maxon.streamconversion.urlpathdec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UrlQuery, , "net.maxon.stringencoding.urlquery");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UrlQuery, , "net.maxon.stringdecoding.urlquery");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlQueryEncoder, , "net.maxon.streamconversion.urlqueryenc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringUrlQueryDecoder, , "net.maxon.streamconversion.urlquerydec");
	}
	namespace StringEncodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CodePage437, , "net.maxon.stringencoding.codepage437");
	}
	namespace StringDecodings
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CodePage437, , "net.maxon.stringdecoding.codepage437");
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringCodePage437Encoder, , "net.maxon.streamconversion.codepage437enc");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StringCodePage437Decoder, , "net.maxon.streamconversion.codepage437dec");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stringencoding(0
	| maxon::StringEncodingInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::StringDecodingInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
