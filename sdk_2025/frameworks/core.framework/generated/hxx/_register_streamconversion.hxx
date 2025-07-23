#if 1
namespace maxon
{
	const maxon::Char* const StreamConversionInterface::MTable::_ids = 
		"GetBatchSize@7d0e6f3d29c239e7\0" // Int GetBatchSize() const
		"GetBlockSize@7d0e6f3d29c239e7\0" // Int GetBlockSize() const
		"GetCounterpart@33636d531bf4ad19\0" // Id GetCounterpart() const
		"GetSourceType@a6c0b400f1ac4207\0" // const DataType& GetSourceType() const
		"GetDestinationType@a6c0b400f1ac4207\0" // const DataType& GetDestinationType() const
		"SupportInplaceConversion@12e73654e6d65520\0" // Bool SupportInplaceConversion() const
		"ConvertImpl@743538e641f348ac\0" // Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
		"ConvertToStream@f9be2765d6e93090\0" // Result<InputStreamRef> ConvertToStream(const InputStreamRef& in)
		"ConvertToStream@24f507ab8f782807\0" // Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in)
		"ConvertToReader@f6e9d9461303efe5\0" // Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in)
		"ConvertToReader@424b66f0fafa8518\0" // Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in)
		"ConvertToStream@6d09a2ff6b41ad8\0" // Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out)
		"ConvertToStream@4319f7193db97c0c\0" // Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out)
		"ConvertToWriter@806b30e58d7f9ed4\0" // Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out)
		"ConvertToWriter@4e20f05a634f90a8\0" // Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out)
	"";
	const maxon::METHOD_FLAGS StreamConversionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(StreamConversionInterface, , "net.maxon.interface.streamconversion", (DataDictionaryObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int StreamConversionInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Id>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(StreamConversions);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ConversionTestSet,, "net.maxon.datatype.conversiontestset");
	MAXON_REGISTRY_REGISTER(StreamConversionTests);
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64Encoder, , "net.maxon.streamconversion.base64.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64Decoder, , "net.maxon.streamconversion.base64.decoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64UrlEncoder, , "net.maxon.streamconversion.base64url.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64UrlDecoder, , "net.maxon.streamconversion.base64url.decoder");
	}
	namespace UTFTEXT_OPTIONS
	{
		namespace enum403
		{
			enum class TEXTENCODING
				{
					NONE									= 0, ///< No encoding takes place. The values are just extended or truncated.
					UTF8									= 1, ///< UTF-8 encoding.
					UTF16_BIGENDIAN				= 2, ///< UTF-16 encoding, Big Endian format.
					UTF16_LITTLEENDIAN		= 3, ///< UTF-16 encoding, Little Endian format.
					UTF32_BIGENDIAN				= 4, ///< UTF-32 encoding, Big Endian format.
					UTF32_LITTLEENDIAN		= 5  ///< UTF-32 encoding, Little Endian format.
				} ;
			static const maxon::UInt64 TEXTENCODING_values[] = {maxon::UInt64(enum403::TEXTENCODING::NONE), maxon::UInt64(enum403::TEXTENCODING::UTF8), maxon::UInt64(enum403::TEXTENCODING::UTF16_BIGENDIAN), maxon::UInt64(enum403::TEXTENCODING::UTF16_LITTLEENDIAN), maxon::UInt64(enum403::TEXTENCODING::UTF32_BIGENDIAN), maxon::UInt64(enum403::TEXTENCODING::UTF32_LITTLEENDIAN)};
			static const maxon::EnumInfo TEXTENCODING_info{"TEXTENCODING", SIZEOF(TEXTENCODING), false, "NONE\0UTF8\0UTF16_BIGENDIAN\0UTF16_LITTLEENDIAN\0UTF32_BIGENDIAN\0UTF32_LITTLEENDIAN\0", TEXTENCODING_values, std::extent<decltype(TEXTENCODING_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_TEXTENCODING403(){ return enum403::TEXTENCODING_info; }
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UtfTextEncoder, , "net.maxon.streamconversion.utftext.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UtfTextDecoder, , "net.maxon.streamconversion.utftext.decoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HexEncoder, , "net.maxon.streamconversion.hex.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HexDecoder, , "net.maxon.streamconversion.hex.decoder");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StreamConversionBaseClass, , "net.maxon.class.streamconversionbase");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_streamconversion(0
	| maxon::StreamConversionInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
