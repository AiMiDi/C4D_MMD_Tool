#if 1
namespace maxon
{
	namespace enum19
	{
		enum class JWTPARSERFLAGS
		{
			NONE						= 0,
		} ;
		static const maxon::UInt64 JWTPARSERFLAGS_values[] = {maxon::UInt64(enum19::JWTPARSERFLAGS::NONE)};
		static const maxon::EnumInfo JWTPARSERFLAGS_info{"JWTPARSERFLAGS", SIZEOF(JWTPARSERFLAGS), true, "NONE\0", JWTPARSERFLAGS_values, std::extent<decltype(JWTPARSERFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JWTPARSERFLAGS19(){ return enum19::JWTPARSERFLAGS_info; }
	const maxon::Char* const JwtParserInterface::MTable::_ids = 
		"Free@57668832c514f1cb\0" // void Free(const JwtParserInterface* object)
		"Alloc@3bfeb7474b2a796c\0" // Interface* Alloc(const maxon::SourceLocation& allocLocation)
		"Read@d5b1ef95f664fd87\0" // Result<void> Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken)
		"Read@824028fce9075082\0" // Result<void> Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects)
		"Write@431ab7a6e906c33b\0" // Result<CString> Write(const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class JwtParserInterface::Hxx2::Unresolved : public JwtParserInterface
	{
	public:
		static const Unresolved* Get(const JwtParserInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(JwtParserInterface* o) { return (Unresolved*) o; }
		static void Free(const JwtParserInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JwtParserInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Interface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JwtParserInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JwtParserInterface*) this)->Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, publicKey, jsonObjects, originalToken); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JwtParserInterface*) this)->Read(jwtString, flags, stringDecoding, publicKey, jsonObjects); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<CString> Write(const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((JwtParserInterface*) this)->Write(jsonObject, stringEncoding, privateKey); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE JwtParserInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Interface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<CString>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool JwtParserInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JwtParserInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JwtParserInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JwtParserInterface_Read = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Read;
		#else
		tbl->_JwtParserInterface_Read = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Read;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JwtParserInterface_Read_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Read_1;
		#else
		tbl->_JwtParserInterface_Read_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Read_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<CString>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JwtParserInterface_Write = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Write;
		#else
		tbl->_JwtParserInterface_Write = &Hxx2::Wrapper<Hxx2::Unresolved>::_JwtParserInterface_Write;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(JwtParserInterface, "net.maxon.interface.jwtparser", nullptr);
}
#endif
