
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*LexerInterface_Free) (const LexerInterface* object);
	LexerInterface* (*LexerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*LexerInterface_Init) (LexerInterface* this_, UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag);
	Result<void> (*LexerInterface_AddOperator) (LexerInterface* this_, const String& chars);
	Result<void> (*LexerInterface_Close) (LexerInterface* this_);
	Result<Utf32Char> (*LexerInterface_ReadNextChar) (LexerInterface* this_);
	Result<Bool> (*LexerInterface_SkipSpaces) (LexerInterface* this_);
	Result<Bool> (*LexerInterface_SkipLineToEnd) (LexerInterface* this_, Bool collectSkipped);
	Result<LEXERSYMBOL> (*LexerInterface_ReadNextSymbol) (LexerInterface* this_, LEXERSYMBOLFLAGS flags);
	Result<void> (*LexerInterface_ReadNextSymbolExpected) (LexerInterface* this_, LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags);
	void (*LexerInterface_RewindSymbol) (LexerInterface* this_);
	LEXERSYMBOL (*LexerInterface_GetSymbol) (const LexerInterface* this_);
	Int (*LexerInterface_GetLeadingSpace) (const LexerInterface* this_);
	String (*LexerInterface_GetIdent) (const LexerInterface* this_);
	Result<void> (*LexerInterface_GetFloat) (const LexerInterface* this_, Float32& val);
	Result<void> (*LexerInterface_GetFloat_1) (const LexerInterface* this_, Float64& val);
	Result<void> (*LexerInterface_GetInt) (const LexerInterface* this_, Int32& val);
	Result<void> (*LexerInterface_GetInt_1) (const LexerInterface* this_, Int64& val);
	Result<void> (*LexerInterface_GetUInt) (const LexerInterface* this_, UInt32& val);
	Result<void> (*LexerInterface_GetUInt_1) (const LexerInterface* this_, UInt64& val);
	Result<Int64> (*LexerInterface_GetCurrentReadPosition) (const LexerInterface* this_);
	Result<Int64> (*LexerInterface_GetSymbolPosition) (const LexerInterface* this_);
	Bool (*LexerInterface_CheckIdent) (const LexerInterface* this_, const Char* cmp);
	Bool (*LexerInterface_CheckIdent_1) (const LexerInterface* this_, const String& cmp);
	Int (*LexerInterface_GetLine) (const LexerInterface* this_);
	void (*LexerInterface_SetStringQuoteCharacters) (LexerInterface* this_, const String& quoteChar);
	template <typename IMPL> void Init()
	{
		LexerInterface_Free = &IMPL::LexerInterface_Free;
		LexerInterface_Alloc = &IMPL::LexerInterface_Alloc;
		LexerInterface_Init = &IMPL::LexerInterface_Init;
		LexerInterface_AddOperator = &IMPL::LexerInterface_AddOperator;
		LexerInterface_Close = &IMPL::LexerInterface_Close;
		LexerInterface_ReadNextChar = &IMPL::LexerInterface_ReadNextChar;
		LexerInterface_SkipSpaces = &IMPL::LexerInterface_SkipSpaces;
		LexerInterface_SkipLineToEnd = &IMPL::LexerInterface_SkipLineToEnd;
		LexerInterface_ReadNextSymbol = &IMPL::LexerInterface_ReadNextSymbol;
		LexerInterface_ReadNextSymbolExpected = &IMPL::LexerInterface_ReadNextSymbolExpected;
		LexerInterface_RewindSymbol = &IMPL::LexerInterface_RewindSymbol;
		LexerInterface_GetSymbol = &IMPL::LexerInterface_GetSymbol;
		LexerInterface_GetLeadingSpace = &IMPL::LexerInterface_GetLeadingSpace;
		LexerInterface_GetIdent = &IMPL::LexerInterface_GetIdent;
		LexerInterface_GetFloat = &IMPL::LexerInterface_GetFloat;
		LexerInterface_GetFloat_1 = &IMPL::LexerInterface_GetFloat_1;
		LexerInterface_GetInt = &IMPL::LexerInterface_GetInt;
		LexerInterface_GetInt_1 = &IMPL::LexerInterface_GetInt_1;
		LexerInterface_GetUInt = &IMPL::LexerInterface_GetUInt;
		LexerInterface_GetUInt_1 = &IMPL::LexerInterface_GetUInt_1;
		LexerInterface_GetCurrentReadPosition = &IMPL::LexerInterface_GetCurrentReadPosition;
		LexerInterface_GetSymbolPosition = &IMPL::LexerInterface_GetSymbolPosition;
		LexerInterface_CheckIdent = &IMPL::LexerInterface_CheckIdent;
		LexerInterface_CheckIdent_1 = &IMPL::LexerInterface_CheckIdent_1;
		LexerInterface_GetLine = &IMPL::LexerInterface_GetLine;
		LexerInterface_SetStringQuoteCharacters = &IMPL::LexerInterface_SetStringQuoteCharacters;
	}
};

struct LexerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void LexerInterface_Free(const LexerInterface* object) { return C::Free(object); }
		static LexerInterface* LexerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> LexerInterface_Init(LexerInterface* this_, UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) { return C::Get(this_)->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag); }
		static Result<void> LexerInterface_AddOperator(LexerInterface* this_, const String& chars) { return C::Get(this_)->AddOperator(chars); }
		static Result<void> LexerInterface_Close(LexerInterface* this_) { return C::Get(this_)->Close(); }
		static Result<Utf32Char> LexerInterface_ReadNextChar(LexerInterface* this_) { return C::Get(this_)->ReadNextChar(); }
		static Result<Bool> LexerInterface_SkipSpaces(LexerInterface* this_) { return C::Get(this_)->SkipSpaces(); }
		static Result<Bool> LexerInterface_SkipLineToEnd(LexerInterface* this_, Bool collectSkipped) { return C::Get(this_)->SkipLineToEnd(collectSkipped); }
		static Result<LEXERSYMBOL> LexerInterface_ReadNextSymbol(LexerInterface* this_, LEXERSYMBOLFLAGS flags) { return C::Get(this_)->ReadNextSymbol(flags); }
		static Result<void> LexerInterface_ReadNextSymbolExpected(LexerInterface* this_, LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) { return C::Get(this_)->ReadNextSymbolExpected(expectedSymbols, flags); }
		static void LexerInterface_RewindSymbol(LexerInterface* this_) { return C::Get(this_)->RewindSymbol(); }
		static LEXERSYMBOL LexerInterface_GetSymbol(const LexerInterface* this_) { return C::Get(this_)->GetSymbol(); }
		static Int LexerInterface_GetLeadingSpace(const LexerInterface* this_) { return C::Get(this_)->GetLeadingSpace(); }
		static String LexerInterface_GetIdent(const LexerInterface* this_) { return C::Get(this_)->GetIdent(); }
		static Result<void> LexerInterface_GetFloat(const LexerInterface* this_, Float32& val) { return C::Get(this_)->GetFloat(val); }
		static Result<void> LexerInterface_GetFloat_1(const LexerInterface* this_, Float64& val) { return C::Get(this_)->GetFloat(val); }
		static Result<void> LexerInterface_GetInt(const LexerInterface* this_, Int32& val) { return C::Get(this_)->GetInt(val); }
		static Result<void> LexerInterface_GetInt_1(const LexerInterface* this_, Int64& val) { return C::Get(this_)->GetInt(val); }
		static Result<void> LexerInterface_GetUInt(const LexerInterface* this_, UInt32& val) { return C::Get(this_)->GetUInt(val); }
		static Result<void> LexerInterface_GetUInt_1(const LexerInterface* this_, UInt64& val) { return C::Get(this_)->GetUInt(val); }
		static Result<Int64> LexerInterface_GetCurrentReadPosition(const LexerInterface* this_) { return C::Get(this_)->GetCurrentReadPosition(); }
		static Result<Int64> LexerInterface_GetSymbolPosition(const LexerInterface* this_) { return C::Get(this_)->GetSymbolPosition(); }
		static Bool LexerInterface_CheckIdent(const LexerInterface* this_, const Char* cmp) { return C::Get(this_)->CheckIdent(cmp); }
		static Bool LexerInterface_CheckIdent_1(const LexerInterface* this_, const String& cmp) { return C::Get(this_)->CheckIdent(cmp); }
		static Int LexerInterface_GetLine(const LexerInterface* this_) { return C::Get(this_)->GetLine(); }
		static void LexerInterface_SetStringQuoteCharacters(LexerInterface* this_, const String& quoteChar) { return C::Get(this_)->SetStringQuoteCharacters(quoteChar); }
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
	return MTable::_instance.LexerInterface_Init(this, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::AddOperator(const String& chars) -> Result<void>
{
	return MTable::_instance.LexerInterface_AddOperator(this, chars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Close() -> Result<void>
{
	return MTable::_instance.LexerInterface_Close(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextChar() -> Result<Utf32Char>
{
	return MTable::_instance.LexerInterface_ReadNextChar(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipSpaces() -> Result<Bool>
{
	return MTable::_instance.LexerInterface_SkipSpaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipLineToEnd(Bool collectSkipped) -> Result<Bool>
{
	return MTable::_instance.LexerInterface_SkipLineToEnd(this, collectSkipped);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbol(LEXERSYMBOLFLAGS flags) -> Result<LEXERSYMBOL>
{
	return MTable::_instance.LexerInterface_ReadNextSymbol(this, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) -> Result<void>
{
	return MTable::_instance.LexerInterface_ReadNextSymbolExpected(this, expectedSymbols, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::RewindSymbol() -> void
{
	return MTable::_instance.LexerInterface_RewindSymbol(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbol() const -> LEXERSYMBOL
{
	return MTable::_instance.LexerInterface_GetSymbol(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLeadingSpace() const -> Int
{
	return MTable::_instance.LexerInterface_GetLeadingSpace(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetIdent() const -> String
{
	return MTable::_instance.LexerInterface_GetIdent(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float32& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetFloat(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float64& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetFloat_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int32& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetInt(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int64& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetInt_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt32& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetUInt(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt64& val) const -> Result<void>
{
	return MTable::_instance.LexerInterface_GetUInt_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetCurrentReadPosition() const -> Result<Int64>
{
	return MTable::_instance.LexerInterface_GetCurrentReadPosition(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbolPosition() const -> Result<Int64>
{
	return MTable::_instance.LexerInterface_GetSymbolPosition(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const Char* cmp) const -> Bool
{
	return MTable::_instance.LexerInterface_CheckIdent(this, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const String& cmp) const -> Bool
{
	return MTable::_instance.LexerInterface_CheckIdent_1(this, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLine() const -> Int
{
	return MTable::_instance.LexerInterface_GetLine(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SetStringQuoteCharacters(const String& quoteChar) -> void
{
	return MTable::_instance.LexerInterface_SetStringQuoteCharacters(this, quoteChar);
}

auto LexerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LexerRef>
{
	LexerInterface* res_ = LexerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LexerRef(maxon::ForwardResultPtr<LexerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_Init(o_, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding, firstParseFlag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::AddOperator(const String& chars) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_AddOperator(o_, chars));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_Close(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextChar() const -> Result<Utf32Char>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Utf32Char>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_ReadNextChar(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SkipSpaces() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_SkipSpaces(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SkipLineToEnd(Bool collectSkipped) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_SkipLineToEnd(o_, collectSkipped));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextSymbol(LEXERSYMBOLFLAGS flags) const -> Result<LEXERSYMBOL>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEXERSYMBOL>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_ReadNextSymbol(o_, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_ReadNextSymbolExpected(o_, expectedSymbols, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::RewindSymbol() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.LexerInterface_RewindSymbol(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetSymbol() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LEXERSYMBOL>, LEXERSYMBOL>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LEXERSYMBOL>, LEXERSYMBOL>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LEXERSYMBOL>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LexerInterface_GetSymbol(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetLeadingSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.LexerInterface_GetLeadingSpace(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetIdent() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LexerInterface_GetIdent(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetFloat(Float32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetFloat(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetFloat(Float64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetFloat_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetInt(Int32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetInt(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetInt(Int64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetInt_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetUInt(UInt32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetUInt(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetUInt(UInt64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetUInt_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetCurrentReadPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetCurrentReadPosition(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetSymbolPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.LexerInterface_GetSymbolPosition(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::CheckIdent(const Char* cmp) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.LexerInterface_CheckIdent(o_, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::CheckIdent(const String& cmp) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.LexerInterface_CheckIdent_1(o_, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstFn<S>::GetLine() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.LexerInterface_GetLine(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::Fn<S>::SetStringQuoteCharacters(const String& quoteChar) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.LexerInterface_SetStringQuoteCharacters(o_, quoteChar);
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

