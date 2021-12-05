#if 1
namespace maxon
{
	namespace enum52 { enum class LEXERSYMBOL : UChar
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
		AMPERSAND							///< '&' symbol.
	
	} ; }
	maxon::String PrivateToString_LEXERSYMBOL52(std::underlying_type<enum52::LEXERSYMBOL>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum52::LEXERSYMBOL::NONE, (maxon::UInt64) enum52::LEXERSYMBOL::ILLEGAL, (maxon::UInt64) enum52::LEXERSYMBOL::ENDOFFILE, (maxon::UInt64) enum52::LEXERSYMBOL::IDENTIFIER, (maxon::UInt64) enum52::LEXERSYMBOL::STRING, (maxon::UInt64) enum52::LEXERSYMBOL::STRINGCHR, (maxon::UInt64) enum52::LEXERSYMBOL::NUMBER, (maxon::UInt64) enum52::LEXERSYMBOL::NEWLINE, (maxon::UInt64) enum52::LEXERSYMBOL::CURLYBRACKET_OPEN, (maxon::UInt64) enum52::LEXERSYMBOL::CURLYBRACKET_CLOSE, (maxon::UInt64) enum52::LEXERSYMBOL::PARENTHESE_OPEN, (maxon::UInt64) enum52::LEXERSYMBOL::PARENTHESE_CLOSE, (maxon::UInt64) enum52::LEXERSYMBOL::SQUAREBRACKET_OPEN, (maxon::UInt64) enum52::LEXERSYMBOL::SQUAREBRACKET_CLOSE, (maxon::UInt64) enum52::LEXERSYMBOL::SLASH, (maxon::UInt64) enum52::LEXERSYMBOL::EQUAL, (maxon::UInt64) enum52::LEXERSYMBOL::COMMA, (maxon::UInt64) enum52::LEXERSYMBOL::SEMICOLON, (maxon::UInt64) enum52::LEXERSYMBOL::COLON, (maxon::UInt64) enum52::LEXERSYMBOL::PLUS, (maxon::UInt64) enum52::LEXERSYMBOL::TILDE, (maxon::UInt64) enum52::LEXERSYMBOL::PREPROCESSOR, (maxon::UInt64) enum52::LEXERSYMBOL::MULTIPLY, (maxon::UInt64) enum52::LEXERSYMBOL::PIPE, (maxon::UInt64) enum52::LEXERSYMBOL::AMPERSAND};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LEXERSYMBOL", SIZEOF(x), false, values, "NONE\0ILLEGAL\0ENDOFFILE\0IDENTIFIER\0STRING\0STRINGCHR\0NUMBER\0NEWLINE\0CURLYBRACKET_OPEN\0CURLYBRACKET_CLOSE\0PARENTHESE_OPEN\0PARENTHESE_CLOSE\0SQUAREBRACKET_OPEN\0SQUAREBRACKET_CLOSE\0SLASH\0EQUAL\0COMMA\0SEMICOLON\0COLON\0PLUS\0TILDE\0PREPROCESSOR\0MULTIPLY\0PIPE\0AMPERSAND\0", fmt);
	}
	namespace enum62 { enum class LEXERSYMBOLFLAGS
	{
		NONE					= 0,
		NO_NUMBER			= 1 << 0,	///< If set, numbers (and characters as '.' or '-') are not recognized as numbers. Instead either an LEXERSYMBOL::IDENTIFIER or LEXERSYMBOL::ILLEGAL will be generated (and GetIdent() returns the symbol).
		ALLOWSTRINGS	= 1 << 1,	///< If set, strings starting with \" or ' will be detected and LEXERSYMBOL::STRING is returned. GetIdent() returns the content of the string.
	} ; }
	maxon::String PrivateToString_LEXERSYMBOLFLAGS62(std::underlying_type<enum62::LEXERSYMBOLFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum62::LEXERSYMBOLFLAGS::NONE, (maxon::UInt64) enum62::LEXERSYMBOLFLAGS::NO_NUMBER, (maxon::UInt64) enum62::LEXERSYMBOLFLAGS::ALLOWSTRINGS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LEXERSYMBOLFLAGS", SIZEOF(x), true, values, "NONE\0NO_NUMBER\0ALLOWSTRINGS\0", fmt);
	}
	namespace enum73 { enum class LEXERINITFLAGS
	{
		NONE								= 0,
		NEED_EOL						= 1 << 0,		///< The lexer stops at each end of line and returns LEXERSYMBOL::OPERATOR_NEWLINE whenever a newline appears.
		REWIND_WHEN_DONE		= 1 << 1,		///< The lexer will rewind the stream to the last interpreted character when it is done. Only set this if you want to continue scanning the open stream. It will only work if the stream supports seeking. Also a string decoding that has an exact counterpart (e.g. StringEncodings::Utf8) needs to be passed to the lexer.
		C4DSTRCOMPATIBILITY	= 1 << 30,	///< If set, the lexer will handle the escape character in a special manner. Then the escape character works only for the following character if it matches \".
	} ; }
	maxon::String PrivateToString_LEXERINITFLAGS73(std::underlying_type<enum73::LEXERINITFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum73::LEXERINITFLAGS::NONE, (maxon::UInt64) enum73::LEXERINITFLAGS::NEED_EOL, (maxon::UInt64) enum73::LEXERINITFLAGS::REWIND_WHEN_DONE, (maxon::UInt64) enum73::LEXERINITFLAGS::C4DSTRCOMPATIBILITY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LEXERINITFLAGS", SIZEOF(x), true, values, "NONE\0NEED_EOL\0REWIND_WHEN_DONE\0C4DSTRCOMPATIBILITY\0", fmt);
	}
	const maxon::Char* const LexerInterface::MTable::_ids = 
		"Free@387afaf93f9b2892\0" // Free(const LexerInterface* object)
		"Alloc@a17a54f81c9a06ed\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"Init@9d1ff7382024abc5\0" // Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding)
		"Close@a54f4799cbe1a498\0" // Close()
		"ReadNextChar@8236d5bf0daa6642\0" // ReadNextChar()
		"SkipSpaces@a54f479973287c8e\0" // SkipSpaces()
		"SkipLineToEnd@56c629e27a7b3498\0" // SkipLineToEnd(Bool collectSkipped)
		"ReadNextSymbol@c5b31b9df856f24d\0" // ReadNextSymbol(LEXERSYMBOLFLAGS flags)
		"ReadNextSymbolExpected@e5a1378dc8a99323\0" // ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags)
		"RewindSymbol@6b2e10f\0" // RewindSymbol()
		"GetSymbol@581d6a86ff5466fb\0" // GetSymbol() const
		"GetLeadingSpace@4386c86\0" // GetLeadingSpace() const
		"GetIdent@22c6ed80868\0" // GetIdent() const
		"GetFloat@ee834e7712dbaa17\0" // GetFloat(Float32& val) const
		"GetFloat@ee834e7712dd0eb6\0" // GetFloat(Float64& val) const
		"GetInt@36dba42e0b47102a\0" // GetInt(Int32& val) const
		"GetInt@36dba42e0b4874c9\0" // GetInt(Int64& val) const
		"GetUInt@a498e1d8903a0265\0" // GetUInt(UInt32& val) const
		"GetUInt@a498e1d8903b6704\0" // GetUInt(UInt64& val) const
		"GetCurrentReadPosition@8e9bc735f2c8b3e7\0" // GetCurrentReadPosition() const
		"CheckIdent@b66a303ab7dd277c\0" // CheckIdent(const Char* cmp) const
		"CheckIdent@c49f0cd54ab1f37b\0" // CheckIdent(const String& cmp) const
		"GetLine@4386c86\0" // GetLine() const
	"";
	class LexerInterface::Unresolved : public LexerInterface
	{
	public:
		static const Unresolved* Get(const LexerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LexerInterface* o) { return (Unresolved*) o; }
		static void Free(const LexerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LexerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LexerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LexerInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LexerInterface*) this)->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
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
		Bool CheckIdent(const Char* cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Bool CheckIdent(const String& cmp) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->CheckIdent(cmp); return maxon::PrivateLogNullptrError(false);}
		Int GetLine() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LexerInterface*) this)->GetLine(); return 0;}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LexerInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<LexerInterface*>::value,
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
		tbl->_LexerInterface_Free = &Wrapper<Unresolved>::_LexerInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_Alloc = &Wrapper<Unresolved>::_LexerInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_Init = &Wrapper<Unresolved>::_LexerInterface_Init;
	#else
		tbl->_LexerInterface_Init = &Wrapper<Unresolved>::_LexerInterface_Init;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_Close = &Wrapper<Unresolved>::_LexerInterface_Close;
	#else
		tbl->_LexerInterface_Close = &Wrapper<Unresolved>::_LexerInterface_Close;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Utf32Char>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextChar = &Wrapper<Unresolved>::_LexerInterface_ReadNextChar;
	#else
		tbl->_LexerInterface_ReadNextChar = &Wrapper<Unresolved>::_LexerInterface_ReadNextChar;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_SkipSpaces = &Wrapper<Unresolved>::_LexerInterface_SkipSpaces;
	#else
		tbl->_LexerInterface_SkipSpaces = &Wrapper<Unresolved>::_LexerInterface_SkipSpaces;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_SkipLineToEnd = &Wrapper<Unresolved>::_LexerInterface_SkipLineToEnd;
	#else
		tbl->_LexerInterface_SkipLineToEnd = &Wrapper<Unresolved>::_LexerInterface_SkipLineToEnd;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<LEXERSYMBOL>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextSymbol = &Wrapper<Unresolved>::_LexerInterface_ReadNextSymbol;
	#else
		tbl->_LexerInterface_ReadNextSymbol = &Wrapper<Unresolved>::_LexerInterface_ReadNextSymbol;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_ReadNextSymbolExpected = &Wrapper<Unresolved>::_LexerInterface_ReadNextSymbolExpected;
	#else
		tbl->_LexerInterface_ReadNextSymbolExpected = &Wrapper<Unresolved>::_LexerInterface_ReadNextSymbolExpected;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_RewindSymbol = &Wrapper<Unresolved>::_LexerInterface_RewindSymbol;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LEXERSYMBOL>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetSymbol = &Wrapper<Unresolved>::_LexerInterface_GetSymbol;
	#else
		tbl->_LexerInterface_GetSymbol = &Wrapper<Unresolved>::_LexerInterface_GetSymbol;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_GetLeadingSpace = &Wrapper<Unresolved>::_LexerInterface_GetLeadingSpace;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetIdent = &Wrapper<Unresolved>::_LexerInterface_GetIdent;
	#else
		tbl->_LexerInterface_GetIdent = &Wrapper<Unresolved>::_LexerInterface_GetIdent;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetFloat = &Wrapper<Unresolved>::_LexerInterface_GetFloat;
	#else
		tbl->_LexerInterface_GetFloat = &Wrapper<Unresolved>::_LexerInterface_GetFloat;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetFloat_1 = &Wrapper<Unresolved>::_LexerInterface_GetFloat_1;
	#else
		tbl->_LexerInterface_GetFloat_1 = &Wrapper<Unresolved>::_LexerInterface_GetFloat_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetInt = &Wrapper<Unresolved>::_LexerInterface_GetInt;
	#else
		tbl->_LexerInterface_GetInt = &Wrapper<Unresolved>::_LexerInterface_GetInt;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetInt_1 = &Wrapper<Unresolved>::_LexerInterface_GetInt_1;
	#else
		tbl->_LexerInterface_GetInt_1 = &Wrapper<Unresolved>::_LexerInterface_GetInt_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetUInt = &Wrapper<Unresolved>::_LexerInterface_GetUInt;
	#else
		tbl->_LexerInterface_GetUInt = &Wrapper<Unresolved>::_LexerInterface_GetUInt;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetUInt_1 = &Wrapper<Unresolved>::_LexerInterface_GetUInt_1;
	#else
		tbl->_LexerInterface_GetUInt_1 = &Wrapper<Unresolved>::_LexerInterface_GetUInt_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LexerInterface_GetCurrentReadPosition = &Wrapper<Unresolved>::_LexerInterface_GetCurrentReadPosition;
	#else
		tbl->_LexerInterface_GetCurrentReadPosition = &Wrapper<Unresolved>::_LexerInterface_GetCurrentReadPosition;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_CheckIdent = &Wrapper<Unresolved>::_LexerInterface_CheckIdent;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_CheckIdent_1 = &Wrapper<Unresolved>::_LexerInterface_CheckIdent_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LexerInterface_GetLine = &Wrapper<Unresolved>::_LexerInterface_GetLine;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
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
