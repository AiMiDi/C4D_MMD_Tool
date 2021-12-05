#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(StreamConversionInterface, "net.maxon.interface.streamconversion", "maxon.StreamConversionInterface", , &DataDictionaryObjectInterface::_interface);
	const maxon::Char* const StreamConversionInterface::MTable::_ids = 
		"GetBatchSize@4386c86\0" // GetBatchSize() const
		"GetBlockSize@4386c86\0" // GetBlockSize() const
		"GetCounterpart@22aaf2\0" // GetCounterpart() const
		"GetSourceType@f6200306f4b33440\0" // GetSourceType() const
		"GetDestinationType@f6200306f4b33440\0" // GetDestinationType() const
		"SupportInplaceConversion@76f01901\0" // SupportInplaceConversion() const
		"ConvertImpl@615569063d80daf5\0" // ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
		"ConvertToStream@d570f48df17b78d3\0" // ConvertToStream(const InputStreamRef& in)
		"ConvertToStream@f1653426b90b6692\0" // ConvertToStream(const DataFormatBaseReaderRef& in)
		"ConvertToReader@f687f0e51f5bc91c\0" // ConvertToReader(const InputStreamRef& in)
		"ConvertToReader@25506a94c3765869\0" // ConvertToReader(const DataFormatBaseReaderRef& in)
		"ConvertToStream@063b5f364b4b14e9\0" // ConvertToStream(const OutputStreamRef& out)
		"ConvertToStream@2752ab9885de0fcd\0" // ConvertToStream(const DataFormatBaseWriterRef& out)
		"ConvertToWriter@5fbeeda6666b4385\0" // ConvertToWriter(const OutputStreamRef& out)
		"ConvertToWriter@2bf2b1f226a3e269\0" // ConvertToWriter(const DataFormatBaseWriterRef& out)
	"";
	template <typename DUMMY> maxon::Int StreamConversionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(StreamConversions);
	namespace STREAMCONVERSIONFACTORYFLAGS
	{
		ISENCODER_PrivateAttribute ISENCODER;
		ISHASHALGORITHM_PrivateAttribute ISHASHALGORITHM;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ConversionTestSet,, "net.maxon.datatype.conversiontestset");
	namespace STREAMCONVERSIONTEST
	{
		SOURCELOCATION_PrivateAttribute SOURCELOCATION;
		CONVERSIONTESTSET_PrivateAttribute CONVERSIONTESTSET;
		SRCDATA_PrivateAttribute SRCDATA;
		COMPAREDATA_PrivateAttribute COMPAREDATA;
		FORBIDSOURCEDUPLICATION_PrivateAttribute FORBIDSOURCEDUPLICATION;
	}
	MAXON_REGISTRY_REGISTER(StreamConversionTests);
	namespace BASE64_OPTIONS
	{
		MAXMIMELINELENGTH_PrivateAttribute MAXMIMELINELENGTH;
		ADD_NEWLINE_PrivateAttribute ADD_NEWLINE;
	}
	namespace StreamConversions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64Encoder, , "net.maxon.streamconversion.base64.encoder");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Base64Decoder, , "net.maxon.streamconversion.base64.decoder");
	}
	namespace UTFTEXT_OPTIONS
	{
		namespace enum346 { enum class TEXTENCODING
			{
				NONE									= 0, ///< No encoding takes place. The values are just extended or truncated.
				UTF8									= 1, ///< UTF-8 encoding.
				UTF16_BIGENDIAN				= 2, ///< UTF-16 encoding, Big Endian format.
				UTF16_LITTLEENDIAN		= 3, ///< UTF-16 encoding, Little Endian format.
				UTF32_BIGENDIAN				= 4, ///< UTF-32 encoding, Big Endian format.
				UTF32_LITTLEENDIAN		= 5  ///< UTF-32 encoding, Little Endian format.
			} ; }
		maxon::String PrivateToString_TEXTENCODING346(std::underlying_type<enum346::TEXTENCODING>::type x, const maxon::FormatStatement* fmt)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum346::TEXTENCODING::NONE, (maxon::UInt64) enum346::TEXTENCODING::UTF8, (maxon::UInt64) enum346::TEXTENCODING::UTF16_BIGENDIAN, (maxon::UInt64) enum346::TEXTENCODING::UTF16_LITTLEENDIAN, (maxon::UInt64) enum346::TEXTENCODING::UTF32_BIGENDIAN, (maxon::UInt64) enum346::TEXTENCODING::UTF32_LITTLEENDIAN};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TEXTENCODING", SIZEOF(x), false, values, "NONE\0UTF8\0UTF16_BIGENDIAN\0UTF16_LITTLEENDIAN\0UTF32_BIGENDIAN\0UTF32_LITTLEENDIAN\0", fmt);
		}
		ENCODING_PrivateAttribute ENCODING;
		DEFAULT_DECODING_PrivateAttribute DEFAULT_DECODING;
		DONTWRITEHEADER_PrivateAttribute DONTWRITEHEADER;
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
	| maxon::StreamConversionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
