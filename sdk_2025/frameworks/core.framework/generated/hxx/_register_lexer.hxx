#if 1
namespace maxon
{
	namespace enum54
	{
		enum class LEXERSYMBOL : UChar
		{
			NONE,
		
			ILLEGAL,
		
			ENDOFFILE,						///< The end of file or stream was reached.
		
			IDENTIFIER,						///< An arbitrary symbol that is neither a string, nor a value. It may contain unicode characters.
		
			STRING,								///< A double-quoted string.
			STRINGCHR,						///< A single-quoted string.
		
			NUMBER,								///< A numerical value.
		
			NEWLINE,							///< '\\r', '\\n' or a combination of both.
			CURLYBRACKET_OPEN,		///< '{' symbol.
			CURLYBRACKET_CLOSE,		///< '}' symbol.
			PARENTHESE_OPEN,			///< '(' symbol.
			PARENTHESE_CLOSE,			///< ')' symbol.
			SQUAREBRACKET_OPEN,		///< '[' symbol.
			SQUAREBRACKET_CLOSE,	///< ']' symbol.
			SLASH,								///< '/' symbol.
			EQUAL,								///< '=' symbol.
			COMMA,								///< ',' symbol.
			SEMICOLON,						///< ';' symbol.
			COLON,								///< ':' symbol.
			PLUS,									///< '+' symbol.
			TILDE,								///< '~' symbol.
			PREPROCESSOR,					///< '#' symbol.
			MULTIPLY,							///< '*' symbol.
			PIPE,									///< '|' symbol.
			AMPERSAND,						///< '&' symbol.
		
			OPERATOR							///< One of the operator symbols added by LexerInterface::AddOperator.
		} ;
		static const maxon::UInt64 LEXERSYMBOL_values[] = {maxon::UInt64(enum54::LEXERSYMBOL::NONE), maxon::UInt64(enum54::LEXERSYMBOL::ILLEGAL), maxon::UInt64(enum54::LEXERSYMBOL::ENDOFFILE), maxon::UInt64(enum54::LEXERSYMBOL::IDENTIFIER), maxon::UInt64(enum54::LEXERSYMBOL::STRING), maxon::UInt64(enum54::LEXERSYMBOL::STRINGCHR), maxon::UInt64(enum54::LEXERSYMBOL::NUMBER), maxon::UInt64(enum54::LEXERSYMBOL::NEWLINE), maxon::UInt64(enum54::LEXERSYMBOL::CURLYBRACKET_OPEN), maxon::UInt64(enum54::LEXERSYMBOL::CURLYBRACKET_CLOSE), maxon::UInt64(enum54::LEXERSYMBOL::PARENTHESE_OPEN), maxon::UInt64(enum54::LEXERSYMBOL::PARENTHESE_CLOSE), maxon::UInt64(enum54::LEXERSYMBOL::SQUAREBRACKET_OPEN), maxon::UInt64(enum54::LEXERSYMBOL::SQUAREBRACKET_CLOSE), maxon::UInt64(enum54::LEXERSYMBOL::SLASH), maxon::UInt64(enum54::LEXERSYMBOL::EQUAL), maxon::UInt64(enum54::LEXERSYMBOL::COMMA), maxon::UInt64(enum54::LEXERSYMBOL::SEMICOLON), maxon::UInt64(enum54::LEXERSYMBOL::COLON), maxon::UInt64(enum54::LEXERSYMBOL::PLUS), maxon::UInt64(enum54::LEXERSYMBOL::TILDE), maxon::UInt64(enum54::LEXERSYMBOL::PREPROCESSOR), maxon::UInt64(enum54::LEXERSYMBOL::MULTIPLY), maxon::UInt64(enum54::LEXERSYMBOL::PIPE), maxon::UInt64(enum54::LEXERSYMBOL::AMPERSAND), maxon::UInt64(enum54::LEXERSYMBOL::OPERATOR)};
		static const maxon::EnumInfo LEXERSYMBOL_info{"LEXERSYMBOL", SIZEOF(LEXERSYMBOL), false, "NONE\0ILLEGAL\0ENDOFFILE\0IDENTIFIER\0STRING\0STRINGCHR\0NUMBER\0NEWLINE\0CURLYBRACKET_OPEN\0CURLYBRACKET_CLOSE\0PARENTHESE_OPEN\0PARENTHESE_CLOSE\0SQUAREBRACKET_OPEN\0SQUAREBRACKET_CLOSE\0SLASH\0EQUAL\0COMMA\0SEMICOLON\0COLON\0PLUS\0TILDE\0PREPROCESSOR\0MULTIPLY\0PIPE\0AMPERSAND\0OPERATOR\0", LEXERSYMBOL_values, std::extent<decltype(LEXERSYMBOL_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LEXERSYMBOL54(){ return enum54::LEXERSYMBOL_info; }
	namespace enum65
	{
		enum class LEXERSYMBOLFLAGS
		{
			NONE						= 0,
			NO_NUMBER				= 1 << 0,	///< If set, numbers (and characters as '.' or '-') are not recognized as numbers. Instead either an LEXERSYMBOL::IDENTIFIER or LEXERSYMBOL::ILLEGAL will be generated (and GetIdent() returns the symbol).
			ALLOWSTRINGS		= 1 << 1,	///< If set, strings starting with \" or ' will be detected and LEXERSYMBOL::STRING is returned. GetIdent() returns the content of the string.
			MINUS_OPERATOR	= 1 << 2,	///< If set, the minus symbol in front of a number will be reported as own token.
		} ;
		static const maxon::UInt64 LEXERSYMBOLFLAGS_values[] = {maxon::UInt64(enum65::LEXERSYMBOLFLAGS::NONE), maxon::UInt64(enum65::LEXERSYMBOLFLAGS::NO_NUMBER), maxon::UInt64(enum65::LEXERSYMBOLFLAGS::ALLOWSTRINGS), maxon::UInt64(enum65::LEXERSYMBOLFLAGS::MINUS_OPERATOR)};
		static const maxon::EnumInfo LEXERSYMBOLFLAGS_info{"LEXERSYMBOLFLAGS", SIZEOF(LEXERSYMBOLFLAGS), true, "NONE\0NO_NUMBER\0ALLOWSTRINGS\0MINUS_OPERATOR\0", LEXERSYMBOLFLAGS_values, std::extent<decltype(LEXERSYMBOLFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LEXERSYMBOLFLAGS65(){ return enum65::LEXERSYMBOLFLAGS_info; }
	namespace enum84
	{
		enum class LEXERINITFLAGS
		{
			NONE										= 0,
			NEED_EOL								= 1 << 0,		///< The lexer stops at each end of line and returns LEXERSYMBOL::OPERATOR_NEWLINE whenever a newline appears.
			REWIND_WHEN_DONE				= 1 << 1,		///< The lexer will rewind the stream to the last interpreted character when it is done. Only set this if you want to continue scanning the open stream. It will only work if the stream supports seeking. Also a string decoding that has an exact counterpart (e.g. StringEncodings::Utf8) needs to be passed to the lexer.
			ALLOW_DOLLAR_IDENT			= 1 << 2,		///< Allow $ as part of identifiers.
			ALLOW_AT_IDENT					= 1 << 3,		///< Allow @ as part of identifiers (but not as start).
			NON_ASCII_IS_IDENT			= 1 << 4,		///< If set, non-ASCII characters (code > 127) are considered to be part of identifiers.
			HASH_COMMENTS						= 1 << 5,		///< If set, comments are introduced by the hash character (instead of C++-like comments).
			ESCAPE_IN_SINGLE_QUOTED = 1 << 6,		///< If set, escape characters are also considered in single-quoted-strings.
			C_ESCAPE_SEQUENCES			= 1 << 7,		///< If set, a subset of C escape sequences is recognized in strings (\\n, \\t and \\r).
			DOUBLEQUOTEESCAPE				= 1 << 8,		///< If set, double quotes will escape the quote char.
			SPACESCOMPATIBILITY			= 1 << 29,	///< If set, a newline character will be included in the result of LexerInterface::GetLeadingSpaces.
			C4DSTRCOMPATIBILITY			= 1 << 30,	///< If set, the lexer will handle the escape character in a special manner. Then the escape character works only for the following character if it matches \".
		} ;
		static const maxon::UInt64 LEXERINITFLAGS_values[] = {maxon::UInt64(enum84::LEXERINITFLAGS::NONE), maxon::UInt64(enum84::LEXERINITFLAGS::NEED_EOL), maxon::UInt64(enum84::LEXERINITFLAGS::REWIND_WHEN_DONE), maxon::UInt64(enum84::LEXERINITFLAGS::ALLOW_DOLLAR_IDENT), maxon::UInt64(enum84::LEXERINITFLAGS::ALLOW_AT_IDENT), maxon::UInt64(enum84::LEXERINITFLAGS::NON_ASCII_IS_IDENT), maxon::UInt64(enum84::LEXERINITFLAGS::HASH_COMMENTS), maxon::UInt64(enum84::LEXERINITFLAGS::ESCAPE_IN_SINGLE_QUOTED), maxon::UInt64(enum84::LEXERINITFLAGS::C_ESCAPE_SEQUENCES), maxon::UInt64(enum84::LEXERINITFLAGS::DOUBLEQUOTEESCAPE), maxon::UInt64(enum84::LEXERINITFLAGS::SPACESCOMPATIBILITY), maxon::UInt64(enum84::LEXERINITFLAGS::C4DSTRCOMPATIBILITY)};
		static const maxon::EnumInfo LEXERINITFLAGS_info{"LEXERINITFLAGS", SIZEOF(LEXERINITFLAGS), true, "NONE\0NEED_EOL\0REWIND_WHEN_DONE\0ALLOW_DOLLAR_IDENT\0ALLOW_AT_IDENT\0NON_ASCII_IS_IDENT\0HASH_COMMENTS\0ESCAPE_IN_SINGLE_QUOTED\0C_ESCAPE_SEQUENCES\0DOUBLEQUOTEESCAPE\0SPACESCOMPATIBILITY\0C4DSTRCOMPATIBILITY\0", LEXERINITFLAGS_values, std::extent<decltype(LEXERINITFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LEXERINITFLAGS84(){ return enum84::LEXERINITFLAGS_info; }
	const maxon::Char* const LexerInterface::MTable::_ids = 
		"Free@2b3af705cea3c4c3\0" // void Free(const LexerInterface* object)
		"Alloc@f74ce17227141568\0" // LexerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@c1e3abb9b224146b\0" // Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag)
		"AddOperator@d85d74e087a2f051\0" // Result<void> AddOperator(const String& chars)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"ReadNextChar@5f540e9851d5a567\0" // Result<Utf32Char> ReadNextChar()
		"SkipSpaces@5ddc8a7d04582063\0" // Result<Bool> SkipSpaces()
		"SkipLineToEnd@ad330f37e606d837\0" // Result<Bool> SkipLineToEnd(Bool collectSkipped)
		"ReadNextSymbol@e4e7fcdb040423fc\0" // Result<LEXERSYMBOL> ReadNextSymbol(LEXERSYMBOLFLAGS flags)
		"ReadNextSymbolExpected@605270d2cf91d8e\0" // Result<void> ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags)
		"RewindSymbol@780cdac8f1a33934\0" // void RewindSymbol()
		"GetSymbol@fed745294e152ce8\0" // LEXERSYMBOL GetSymbol() const
		"GetLeadingSpace@7d0e6f3d29c239e7\0" // Int GetLeadingSpace() const
		"GetIdent@b8f12dfa16054f01\0" // String GetIdent() const
		"GetFloat@4927f596ea5efa58\0" // Result<void> GetFloat(Float32& val) const
		"GetFloat@ca21525c4bc3809b\0" // Result<void> GetFloat(Float64& val) const
		"GetInt@d912da82119dcb63\0" // Result<void> GetInt(Int32& val) const
		"GetInt@cad2dc0fbb40ccc4\0" // Result<void> GetInt(Int64& val) const
		"GetUInt@5b5a0ee31529501c\0" // Result<void> GetUInt(UInt32& val) const
		"GetUInt@7c462a61a695a49f\0" // Result<void> GetUInt(UInt64& val) const
		"GetCurrentReadPosition@bb48d07a52041bca\0" // Result<Int64> GetCurrentReadPosition() const
		"GetSymbolPosition@bb48d07a52041bca\0" // Result<Int64> GetSymbolPosition() const
		"CheckIdent@29926876897a780b\0" // Bool CheckIdent(const Char* cmp) const
		"CheckIdent@1d577fae915a8f2e\0" // Bool CheckIdent(const String& cmp) const
		"GetLine@7d0e6f3d29c239e7\0" // Int GetLine() const
		"SetStringQuoteCharacters@cc63eccfe460c07a\0" // void SetStringQuoteCharacters(const String& quoteChar)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LexerInterface::Hxx2::Unresolved : public LexerInterface
	{
	public:
		static const Unresolved* Get(const LexerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LexerInterface* o) { return (Unresolved*) o; }
		static void Free(const LexerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LexerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LexerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LexerInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag); return HXXRET1(UNRESOLVED);}
		Result<void> AddOperator(const String& chars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->AddOperator(chars); return HXXRET1(UNRESOLVED);}
		Result<void> Close() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->Close(); return HXXRET1(UNRESOLVED);}
		Result<Utf32Char> ReadNextChar() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextChar(); return HXXRET1(UNRESOLVED);}
		Result<Bool> SkipSpaces() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->SkipSpaces(); return HXXRET1(UNRESOLVED);}
		Result<Bool> SkipLineToEnd(Bool collectSkipped) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->SkipLineToEnd(collectSkipped); return HXXRET1(UNRESOLVED);}
		Result<LEXERSYMBOL> ReadNextSymbol(LEXERSYMBOLFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextSymbol(flags); return HXXRET1(UNRESOLVED);}
		Result<void> ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextSymbolExpected(expectedSymbols, flags); return HXXRET1(UNRESOLVED);}
		void RewindSymbol() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LexerInterface*) this)->RewindSymbol(); return maxon::PrivateLogNullptrError();}
		LEXERSYMBOL GetSymbol() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetSymbol(); return HXXRET3(UNRESOLVED, LEXERSYMBOL);}
		Int GetLeadingSpace() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetLeadingSpace(); return 0;}
		String GetIdent() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetIdent(); return HXXRET3(UNRESOLVED, String);}
		Result<void> GetFloat(Float32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetFloat(val); return HXXRET1(UNRESOLVED);}
		Result<void> GetFloat(Float64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetFloat(val); return HXXRET1(UNRESOLVED);}
		Result<void> GetInt(Int32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetInt(val); return HXXRET1(UNRESOLVED);}
		Result<void> GetInt(Int64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetInt(val); return HXXRET1(UNRESOLVED);}
		Result<void> GetUInt(UInt32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetUInt(val); return HXXRET1(UNRESOLVED);}
		Result<void> GetUInt(UInt64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetUInt(val); return HXXRET1(UNRESOLVED);}
		Result<Int64> GetCurrentReadPosition() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetCurrentReadPosition(); return HXXRET1(UNRESOLVED);}
		Result<Int64> GetSymbolPosition() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetSymbolPosition(); return HXXRET1(UNRESOLVED);}
		Bool CheckIdent(const Char* cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Bool CheckIdent(const String& cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Int GetLine() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetLine(); return 0;}
		void SetStringQuoteCharacters(const String& quoteChar) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LexerInterface*) this)->SetStringQuoteCharacters(quoteChar); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE LexerInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<LexerInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Utf32Char>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Bool>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Bool>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<LEXERSYMBOL>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<LEXERSYMBOL>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int64>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int64>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LexerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Init);
		#else
		tbl->LexerInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_AddOperator = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_AddOperator), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_AddOperator);
		#else
		tbl->LexerInterface_AddOperator = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_AddOperator), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_AddOperator);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_Close = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Close), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Close);
		#else
		tbl->LexerInterface_Close = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_Close), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_Close);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Utf32Char>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_ReadNextChar = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextChar), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextChar);
		#else
		tbl->LexerInterface_ReadNextChar = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextChar), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextChar);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_SkipSpaces = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_SkipSpaces), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_SkipSpaces);
		#else
		tbl->LexerInterface_SkipSpaces = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_SkipSpaces), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_SkipSpaces);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_SkipLineToEnd = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_SkipLineToEnd), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_SkipLineToEnd);
		#else
		tbl->LexerInterface_SkipLineToEnd = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_SkipLineToEnd), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_SkipLineToEnd);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<LEXERSYMBOL>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_ReadNextSymbol = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextSymbol);
		#else
		tbl->LexerInterface_ReadNextSymbol = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextSymbol);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_ReadNextSymbolExpected = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextSymbolExpected), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextSymbolExpected);
		#else
		tbl->LexerInterface_ReadNextSymbolExpected = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_ReadNextSymbolExpected), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_ReadNextSymbolExpected);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_RewindSymbol = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_RewindSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_RewindSymbol);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LEXERSYMBOL>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetSymbol = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetSymbol);
		#else
		tbl->LexerInterface_GetSymbol = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetSymbol);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_GetLeadingSpace = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetLeadingSpace), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetLeadingSpace);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetIdent = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetIdent), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetIdent);
		#else
		tbl->LexerInterface_GetIdent = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetIdent), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetIdent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetFloat = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetFloat), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetFloat);
		#else
		tbl->LexerInterface_GetFloat = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetFloat), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetFloat);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetFloat_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetFloat_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetFloat_1);
		#else
		tbl->LexerInterface_GetFloat_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetFloat_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetFloat_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetInt = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetInt), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetInt);
		#else
		tbl->LexerInterface_GetInt = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetInt), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetInt);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetInt_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetInt_1);
		#else
		tbl->LexerInterface_GetInt_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetInt_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetUInt = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetUInt), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetUInt);
		#else
		tbl->LexerInterface_GetUInt = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetUInt), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetUInt);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetUInt_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetUInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetUInt_1);
		#else
		tbl->LexerInterface_GetUInt_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetUInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetUInt_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetCurrentReadPosition = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetCurrentReadPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetCurrentReadPosition);
		#else
		tbl->LexerInterface_GetCurrentReadPosition = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetCurrentReadPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetCurrentReadPosition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LexerInterface_GetSymbolPosition = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetSymbolPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetSymbolPosition);
		#else
		tbl->LexerInterface_GetSymbolPosition = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetSymbolPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetSymbolPosition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_CheckIdent = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_CheckIdent), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_CheckIdent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_CheckIdent_1 = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_CheckIdent_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_CheckIdent_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_GetLine = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_GetLine), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_GetLine);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LexerInterface_SetStringQuoteCharacters = PRIVATE_MAXON_MF_CAST(decltype(LexerInterface_SetStringQuoteCharacters), &Hxx2::Wrapper<Hxx2::Unresolved>::LexerInterface_SetStringQuoteCharacters);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LexerInterface, "net.maxon.interface.lexer", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int LexerInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<LEXERSYMBOL>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_lexer(0
	| maxon::LexerInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
