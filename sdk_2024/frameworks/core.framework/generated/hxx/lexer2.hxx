
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* LexerInterface::PrivateGetCppName() { return "maxon::LexerRef"; }

struct LexerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(LexerInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const LexerInterface* object);
	PRIVATE_MAXON_SF_POINTER(LexerInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (LexerInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_Init, Init, false, LexerInterface,, (Result<void>), UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_AddOperator, AddOperator, false, LexerInterface,, (Result<void>), const String& chars);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_Close, Close, false, LexerInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_ReadNextChar, ReadNextChar, false, LexerInterface,, (Result<Utf32Char>));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_SkipSpaces, SkipSpaces, false, LexerInterface,, (Result<Bool>));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_SkipLineToEnd, SkipLineToEnd, false, LexerInterface,, (Result<Bool>), Bool collectSkipped);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_ReadNextSymbol, ReadNextSymbol, false, LexerInterface,, (Result<LEXERSYMBOL>), LEXERSYMBOLFLAGS flags);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_ReadNextSymbolExpected, ReadNextSymbolExpected, false, LexerInterface,, (Result<void>), LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_RewindSymbol, RewindSymbol, false, LexerInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetSymbol, GetSymbol, false, LexerInterface, const, (LEXERSYMBOL));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetLeadingSpace, GetLeadingSpace, false, LexerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetIdent, GetIdent, false, LexerInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetFloat, GetFloat, false, LexerInterface, const, (Result<void>), Float32& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetFloat_1, GetFloat, false, LexerInterface, const, (Result<void>), Float64& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetInt, GetInt, false, LexerInterface, const, (Result<void>), Int32& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetInt_1, GetInt, false, LexerInterface, const, (Result<void>), Int64& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetUInt, GetUInt, false, LexerInterface, const, (Result<void>), UInt32& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetUInt_1, GetUInt, false, LexerInterface, const, (Result<void>), UInt64& val);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetCurrentReadPosition, GetCurrentReadPosition, false, LexerInterface, const, (Result<Int64>));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetSymbolPosition, GetSymbolPosition, false, LexerInterface, const, (Result<Int64>));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_CheckIdent, CheckIdent, false, LexerInterface, const, (Bool), const Char* cmp);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_CheckIdent_1, CheckIdent, false, LexerInterface, const, (Bool), const String& cmp);
	PRIVATE_MAXON_MF_POINTER(LexerInterface_GetLine, GetLine, false, LexerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(LexerInterface_SetStringQuoteCharacters, SetStringQuoteCharacters, false, LexerInterface,, (void), const String& quoteChar);
	template <typename IMPL> void Init()
	{
		LexerInterface_Free = LexerInterface_Free_GetPtr<IMPL>(true);
		LexerInterface_Alloc = LexerInterface_Alloc_GetPtr<IMPL>(true);
		LexerInterface_Init = LexerInterface_Init_GetPtr<IMPL>(0, true).first;
		LexerInterface_AddOperator = LexerInterface_AddOperator_GetPtr<IMPL>(0, true).first;
		LexerInterface_Close = LexerInterface_Close_GetPtr<IMPL>(0, true).first;
		LexerInterface_ReadNextChar = LexerInterface_ReadNextChar_GetPtr<IMPL>(0, true).first;
		LexerInterface_SkipSpaces = LexerInterface_SkipSpaces_GetPtr<IMPL>(0, true).first;
		LexerInterface_SkipLineToEnd = LexerInterface_SkipLineToEnd_GetPtr<IMPL>(0, true).first;
		LexerInterface_ReadNextSymbol = LexerInterface_ReadNextSymbol_GetPtr<IMPL>(0, true).first;
		LexerInterface_ReadNextSymbolExpected = LexerInterface_ReadNextSymbolExpected_GetPtr<IMPL>(0, true).first;
		LexerInterface_RewindSymbol = LexerInterface_RewindSymbol_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetSymbol = LexerInterface_GetSymbol_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetLeadingSpace = LexerInterface_GetLeadingSpace_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetIdent = LexerInterface_GetIdent_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetFloat = LexerInterface_GetFloat_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetFloat_1 = LexerInterface_GetFloat_1_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetInt = LexerInterface_GetInt_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetInt_1 = LexerInterface_GetInt_1_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetUInt = LexerInterface_GetUInt_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetUInt_1 = LexerInterface_GetUInt_1_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetCurrentReadPosition = LexerInterface_GetCurrentReadPosition_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetSymbolPosition = LexerInterface_GetSymbolPosition_GetPtr<IMPL>(0, true).first;
		LexerInterface_CheckIdent = LexerInterface_CheckIdent_GetPtr<IMPL>(0, true).first;
		LexerInterface_CheckIdent_1 = LexerInterface_CheckIdent_1_GetPtr<IMPL>(0, true).first;
		LexerInterface_GetLine = LexerInterface_GetLine_GetPtr<IMPL>(0, true).first;
		LexerInterface_SetStringQuoteCharacters = LexerInterface_SetStringQuoteCharacters_GetPtr<IMPL>(0, true).first;
	}
};

struct LexerInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void LexerInterface_Free(const LexerInterface* object) { return S::Free(object); }
		static LexerInterface* LexerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_Init, LexerInterface,, (Result<void>), UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_AddOperator, LexerInterface,, (Result<void>), const String& chars) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->AddOperator(chars); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_Close, LexerInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->Close(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_ReadNextChar, LexerInterface,, (Result<Utf32Char>)) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->ReadNextChar(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_SkipSpaces, LexerInterface,, (Result<Bool>)) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->SkipSpaces(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_SkipLineToEnd, LexerInterface,, (Result<Bool>), Bool collectSkipped) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->SkipLineToEnd(collectSkipped); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_ReadNextSymbol, LexerInterface,, (Result<LEXERSYMBOL>), LEXERSYMBOLFLAGS flags) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->ReadNextSymbol(flags); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_ReadNextSymbolExpected, LexerInterface,, (Result<void>), LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->ReadNextSymbolExpected(expectedSymbols, flags); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_RewindSymbol, LexerInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->RewindSymbol(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetSymbol, LexerInterface, const, (LEXERSYMBOL)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetSymbol(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetLeadingSpace, LexerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetLeadingSpace(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetIdent, LexerInterface, const, (String)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetIdent(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetFloat, LexerInterface, const, (Result<void>), Float32& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetFloat(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetFloat_1, LexerInterface, const, (Result<void>), Float64& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetFloat(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetInt, LexerInterface, const, (Result<void>), Int32& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetInt(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetInt_1, LexerInterface, const, (Result<void>), Int64& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetInt(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetUInt, LexerInterface, const, (Result<void>), UInt32& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetUInt(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetUInt_1, LexerInterface, const, (Result<void>), UInt64& val) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetUInt(val); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetCurrentReadPosition, LexerInterface, const, (Result<Int64>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetCurrentReadPosition(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetSymbolPosition, LexerInterface, const, (Result<Int64>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetSymbolPosition(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_CheckIdent, LexerInterface, const, (Bool), const Char* cmp) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->CheckIdent(cmp); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_CheckIdent_1, LexerInterface, const, (Bool), const String& cmp) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->CheckIdent(cmp); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_GetLine, LexerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const LexerInterface))->GetLine(); }
		PRIVATE_MAXON_MF_WRAPPER(LexerInterface_SetStringQuoteCharacters, LexerInterface,, (void), const String& quoteChar) { return S::Get(PRIVATE_MAXON_MF_THIS(LexerInterface))->SetStringQuoteCharacters(quoteChar); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Free(const LexerInterface* object) -> void
{
	return MTable::_instance.LexerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LexerInterface*
{
	return MTable::_instance.LexerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_Init, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::AddOperator(const String& chars) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_AddOperator, chars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Close() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_Close);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextChar() -> Result<Utf32Char>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_ReadNextChar);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipSpaces() -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_SkipSpaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipLineToEnd(Bool collectSkipped) -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_SkipLineToEnd, collectSkipped);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbol(LEXERSYMBOLFLAGS flags) -> Result<LEXERSYMBOL>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_ReadNextSymbol, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_ReadNextSymbolExpected, expectedSymbols, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::RewindSymbol() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_RewindSymbol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbol() const -> LEXERSYMBOL
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetSymbol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLeadingSpace() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetLeadingSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetIdent() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetIdent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float32& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetFloat, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float64& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetFloat_1, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int32& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetInt, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int64& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetInt_1, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt32& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetUInt, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt64& val) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetUInt_1, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetCurrentReadPosition() const -> Result<Int64>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetCurrentReadPosition);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbolPosition() const -> Result<Int64>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetSymbolPosition);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const Char* cmp) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_CheckIdent, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const String& cmp) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_CheckIdent_1, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLine() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_GetLine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SetStringQuoteCharacters(const String& quoteChar) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LexerInterface_SetStringQuoteCharacters, quoteChar);
}

auto LexerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LexerRef>
{
	LexerInterface* res_ = LexerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LexerRef(maxon::ForwardResultPtr<LexerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_Init, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::AddOperator(const String& chars) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_AddOperator, chars));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextChar() const -> Result<Utf32Char>
{
	HXXRETURN0(Result<Utf32Char>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_ReadNextChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SkipSpaces() const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_SkipSpaces));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SkipLineToEnd(Bool collectSkipped) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_SkipLineToEnd, collectSkipped));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextSymbol(LEXERSYMBOLFLAGS flags) const -> Result<LEXERSYMBOL>
{
	HXXRETURN0(Result<LEXERSYMBOL>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_ReadNextSymbol, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_ReadNextSymbolExpected, expectedSymbols, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::RewindSymbol() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_RewindSymbol);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetSymbol() const -> HXXADDRET2(LEXERSYMBOL)
{
	HXXRETURN0(HXXADDRET2(LEXERSYMBOL)); HXXRES; HXXCONST(HXXRET3(NULLPTR, LEXERSYMBOL)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetSymbol));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetLeadingSpace() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetLeadingSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetIdent() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetIdent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetFloat(Float32& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetFloat, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetFloat(Float64& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetFloat_1, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetInt(Int32& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetInt, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetInt(Int64& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetInt_1, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetUInt(UInt32& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetUInt, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetUInt(UInt64& val) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetUInt_1, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetCurrentReadPosition() const -> Result<Int64>
{
	HXXRETURN0(Result<Int64>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetCurrentReadPosition));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetSymbolPosition() const -> Result<Int64>
{
	HXXRETURN0(Result<Int64>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetSymbolPosition));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::CheckIdent(const Char* cmp) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_CheckIdent, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::CheckIdent(const String& cmp) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_CheckIdent_1, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetLine() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_GetLine));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SetStringQuoteCharacters(const String& quoteChar) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LexerInterface_SetStringQuoteCharacters, quoteChar);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_lexer)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LexerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LexerInterface() { new (s_ui_maxon_LexerInterface) maxon::EntityUse(LexerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/lexer.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LexerInterface(LexerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/lexer.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

