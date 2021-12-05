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
	namespace enum83
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
			SPACESCOMPATIBILITY			= 1 << 29,	///< If set, a newline character will be included in the result of LexerInterface::GetLeadingSpaces.
			C4DSTRCOMPATIBILITY			= 1 << 30,	///< If set, the lexer will handle the escape character in a special manner. Then the escape character works only for the following character if it matches \".
		} ;
		static const maxon::UInt64 LEXERINITFLAGS_values[] = {maxon::UInt64(enum83::LEXERINITFLAGS::NONE), maxon::UInt64(enum83::LEXERINITFLAGS::NEED_EOL), maxon::UInt64(enum83::LEXERINITFLAGS::REWIND_WHEN_DONE), maxon::UInt64(enum83::LEXERINITFLAGS::ALLOW_DOLLAR_IDENT), maxon::UInt64(enum83::LEXERINITFLAGS::ALLOW_AT_IDENT), maxon::UInt64(enum83::LEXERINITFLAGS::NON_ASCII_IS_IDENT), maxon::UInt64(enum83::LEXERINITFLAGS::HASH_COMMENTS), maxon::UInt64(enum83::LEXERINITFLAGS::ESCAPE_IN_SINGLE_QUOTED), maxon::UInt64(enum83::LEXERINITFLAGS::C_ESCAPE_SEQUENCES), maxon::UInt64(enum83::LEXERINITFLAGS::SPACESCOMPATIBILITY), maxon::UInt64(enum83::LEXERINITFLAGS::C4DSTRCOMPATIBILITY)};
		static const maxon::EnumInfo LEXERINITFLAGS_info{"LEXERINITFLAGS", SIZEOF(LEXERINITFLAGS), true, "NONE\0NEED_EOL\0REWIND_WHEN_DONE\0ALLOW_DOLLAR_IDENT\0ALLOW_AT_IDENT\0NON_ASCII_IS_IDENT\0HASH_COMMENTS\0ESCAPE_IN_SINGLE_QUOTED\0C_ESCAPE_SEQUENCES\0SPACESCOMPATIBILITY\0C4DSTRCOMPATIBILITY\0", LEXERINITFLAGS_values, std::extent<decltype(LEXERINITFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LEXERINITFLAGS83(){ return enum83::LEXERINITFLAGS_info; }
	const maxon::Char* const LexerInterface::MTable::_ids = 
		"Free@2b3af705cea3c4c3\0" // void Free(const LexerInterface* object)
		"Alloc@f74ce17227141568\0" // LexerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@9bbc55ee299728f2\0" // Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding)
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
		Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> AddOperator(const String& chars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->AddOperator(chars); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Close() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->Close(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Utf32Char> ReadNextChar() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextChar(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> SkipSpaces() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->SkipSpaces(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> SkipLineToEnd(Bool collectSkipped) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->SkipLineToEnd(collectSkipped); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<LEXERSYMBOL> ReadNextSymbol(LEXERSYMBOLFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextSymbol(flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->ReadNextSymbolExpected(expectedSymbols, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void RewindSymbol() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LexerInterface*) this)->RewindSymbol(); return maxon::PrivateLogNullptrError();}
		LEXERSYMBOL GetSymbol() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetSymbol(); return maxon::PrivateIncompleteNullReturnValue<LEXERSYMBOL>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetLeadingSpace() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetLeadingSpace(); return 0;}
		String GetIdent() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetIdent(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> GetFloat(Float32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetFloat(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetFloat(Float64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetFloat(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetInt(Int32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetInt(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetInt(Int64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetInt(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetUInt(UInt32& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetUInt(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetUInt(UInt64& val) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetUInt(val); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int64> GetCurrentReadPosition() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetCurrentReadPosition(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int64> GetSymbolPosition() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const LexerInterface*) this)->GetSymbolPosition(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool CheckIdent(const Char* cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Bool CheckIdent(const String& cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Int GetLine() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetLine(); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LexerInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<LexerInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Utf32Char>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<LEXERSYMBOL>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<LEXERSYMBOL>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int64>>::value,
		maxon::details::NullReturnType<Result<Int64>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LexerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Init;
		#else
		tbl->_LexerInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_AddOperator = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_AddOperator;
		#else
		tbl->_LexerInterface_AddOperator = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_AddOperator;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_Close = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Close;
		#else
		tbl->_LexerInterface_Close = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_Close;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Utf32Char>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextChar;
		#else
		tbl->_LexerInterface_ReadNextChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextChar;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_SkipSpaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_SkipSpaces;
		#else
		tbl->_LexerInterface_SkipSpaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_SkipSpaces;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_SkipLineToEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_SkipLineToEnd;
		#else
		tbl->_LexerInterface_SkipLineToEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_SkipLineToEnd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<LEXERSYMBOL>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextSymbol;
		#else
		tbl->_LexerInterface_ReadNextSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextSymbol;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextSymbolExpected = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextSymbolExpected;
		#else
		tbl->_LexerInterface_ReadNextSymbolExpected = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_ReadNextSymbolExpected;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_RewindSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_RewindSymbol;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LEXERSYMBOL>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetSymbol;
		#else
		tbl->_LexerInterface_GetSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetSymbol;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_GetLeadingSpace = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetLeadingSpace;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetIdent = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetIdent;
		#else
		tbl->_LexerInterface_GetIdent = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetIdent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetFloat;
		#else
		tbl->_LexerInterface_GetFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetFloat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetFloat_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetFloat_1;
		#else
		tbl->_LexerInterface_GetFloat_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetFloat_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetInt;
		#else
		tbl->_LexerInterface_GetInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetInt_1;
		#else
		tbl->_LexerInterface_GetInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetInt_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetUInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetUInt;
		#else
		tbl->_LexerInterface_GetUInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetUInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetUInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetUInt_1;
		#else
		tbl->_LexerInterface_GetUInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetUInt_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetCurrentReadPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetCurrentReadPosition;
		#else
		tbl->_LexerInterface_GetCurrentReadPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetCurrentReadPosition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetSymbolPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetSymbolPosition;
		#else
		tbl->_LexerInterface_GetSymbolPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetSymbolPosition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_CheckIdent = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_CheckIdent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_CheckIdent_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_CheckIdent_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LexerInterface_GetLine = &Hxx2::Wrapper<Hxx2::Unresolved>::_LexerInterface_GetLine;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LexerInterface, "net.maxon.interface.lexer", nullptr);
	template <typename DUMMY> maxon::Int LexerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<LEXERSYMBOL>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_lexer(0
	| maxon::LexerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
