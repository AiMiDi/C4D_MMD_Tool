#if 1
namespace maxon
{
	namespace enum19
	{
		enum class PARSERFLAGS
		{
			NONE						= 0,
			HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the  object.
		} ;
		static const maxon::UInt64 PARSERFLAGS_values[] = {maxon::UInt64(enum19::PARSERFLAGS::NONE), maxon::UInt64(enum19::PARSERFLAGS::HAS_NO_EOF)};
		static const maxon::EnumInfo PARSERFLAGS_info{"PARSERFLAGS", SIZEOF(PARSERFLAGS), true, "NONE\0HAS_NO_EOF\0", PARSERFLAGS_values, std::extent<decltype(PARSERFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_PARSERFLAGS19(){ return enum19::PARSERFLAGS_info; }
	const maxon::Char* const ParserInterface::MTable::_ids = 
		"Read@1269d46fd3e8a77b\0" // Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken)
		"Write@1e7cd5fc234db431\0" // Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting)
		"WriteFile@57d449910585bca9\0" // Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting)
		"GetFileExtension@b8f12dfa16054f01\0" // String GetFileExtension() const
	"";
	const maxon::METHOD_FLAGS ParserInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ParserInterface, , "net.maxon.interface.parser", (DataDictionaryObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ParserInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(ParserClasses);
	namespace ParserClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(JsonParser, , "net.maxon.interface.parserclass.json");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(JwtParser, , "net.maxon.interface.parserclass.jwt");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CsvParser, , "net.maxon.interface.parserclass.csv");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ParserBaseClass, , "net.maxon.interface.parserclass.base");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_parser(0
	| maxon::ParserInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
