#if 1
namespace maxon
{
	namespace enum20 { enum class JSONPARSERFLAGS
	{
		NONE						= 0,
		HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the json object.
	} ; }
	maxon::String PrivateToString_JSONPARSERFLAGS20(std::underlying_type<enum20::JSONPARSERFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum20::JSONPARSERFLAGS::NONE, (maxon::UInt64) enum20::JSONPARSERFLAGS::HAS_NO_EOF};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JSONPARSERFLAGS", SIZEOF(x), true, values, "NONE\0HAS_NO_EOF\0", fmt);
	}
	const maxon::Char* const JsonParserInterface::MTable::_ids = 
		"Free@75f19c93cf770994\0" // void Free(const JsonParserInterface* object)
		"Alloc@3bfeb7474b2a796c\0" // Interface* Alloc(const maxon::SourceLocation& allocLocation)
		"Write@1e7cd5fc234db431\0" // Result<void> Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting)
		"Read@81a0c64d99369e73\0" // Result<void> Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects)
		"Read@81d4d1b5a72c0061\0" // Result<void> Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class JsonParserInterface::Hxx2::Unresolved : public JsonParserInterface
	{
	public:
		static const Unresolved* Get(const JsonParserInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(JsonParserInterface* o) { return (Unresolved*) o; }
		static void Free(const JsonParserInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JsonParserInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Interface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JsonParserInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JsonParserInterface*) this)->Write(jsonObject, jsonString, niceFormatting); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JsonParserInterface*) this)->Read(jsonString, flags, jsonObjects); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JsonParserInterface*) this)->Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, jsonObjects); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE JsonParserInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Interface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool JsonParserInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JsonParserInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JsonParserInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JsonParserInterface_Write = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Write;
		#else
		tbl->_JsonParserInterface_Write = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Write;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JsonParserInterface_Read = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Read;
		#else
		tbl->_JsonParserInterface_Read = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Read;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JsonParserInterface_Read_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Read_1;
		#else
		tbl->_JsonParserInterface_Read_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_JsonParserInterface_Read_1;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(JsonParserInterface, "net.maxon.interface.jsonparser", nullptr);
}
#endif
