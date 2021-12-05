
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct LexerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_LexerInterface_Free) (const LexerInterface* object);
	LexerInterface* (*_LexerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_LexerInterface_Init) (LexerInterface* this_, UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding);
	Result<void> (*_LexerInterface_AddOperator) (LexerInterface* this_, const String& chars);
	Result<void> (*_LexerInterface_Close) (LexerInterface* this_);
	Result<Utf32Char> (*_LexerInterface_ReadNextChar) (LexerInterface* this_);
	Result<Bool> (*_LexerInterface_SkipSpaces) (LexerInterface* this_);
	Result<Bool> (*_LexerInterface_SkipLineToEnd) (LexerInterface* this_, Bool collectSkipped);
	Result<LEXERSYMBOL> (*_LexerInterface_ReadNextSymbol) (LexerInterface* this_, LEXERSYMBOLFLAGS flags);
	Result<void> (*_LexerInterface_ReadNextSymbolExpected) (LexerInterface* this_, LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags);
	void (*_LexerInterface_RewindSymbol) (LexerInterface* this_);
	LEXERSYMBOL (*_LexerInterface_GetSymbol) (const LexerInterface* this_);
	Int (*_LexerInterface_GetLeadingSpace) (const LexerInterface* this_);
	String (*_LexerInterface_GetIdent) (const LexerInterface* this_);
	Result<void> (*_LexerInterface_GetFloat) (const LexerInterface* this_, Float32& val);
	Result<void> (*_LexerInterface_GetFloat_1) (const LexerInterface* this_, Float64& val);
	Result<void> (*_LexerInterface_GetInt) (const LexerInterface* this_, Int32& val);
	Result<void> (*_LexerInterface_GetInt_1) (const LexerInterface* this_, Int64& val);
	Result<void> (*_LexerInterface_GetUInt) (const LexerInterface* this_, UInt32& val);
	Result<void> (*_LexerInterface_GetUInt_1) (const LexerInterface* this_, UInt64& val);
	Result<Int64> (*_LexerInterface_GetCurrentReadPosition) (const LexerInterface* this_);
	Result<Int64> (*_LexerInterface_GetSymbolPosition) (const LexerInterface* this_);
	Bool (*_LexerInterface_CheckIdent) (const LexerInterface* this_, const Char* cmp);
	Bool (*_LexerInterface_CheckIdent_1) (const LexerInterface* this_, const String& cmp);
	Int (*_LexerInterface_GetLine) (const LexerInterface* this_);
	template <typename IMPL> void Init()
	{
		_LexerInterface_Free = &IMPL::_LexerInterface_Free;
		_LexerInterface_Alloc = &IMPL::_LexerInterface_Alloc;
		_LexerInterface_Init = &IMPL::_LexerInterface_Init;
		_LexerInterface_AddOperator = &IMPL::_LexerInterface_AddOperator;
		_LexerInterface_Close = &IMPL::_LexerInterface_Close;
		_LexerInterface_ReadNextChar = &IMPL::_LexerInterface_ReadNextChar;
		_LexerInterface_SkipSpaces = &IMPL::_LexerInterface_SkipSpaces;
		_LexerInterface_SkipLineToEnd = &IMPL::_LexerInterface_SkipLineToEnd;
		_LexerInterface_ReadNextSymbol = &IMPL::_LexerInterface_ReadNextSymbol;
		_LexerInterface_ReadNextSymbolExpected = &IMPL::_LexerInterface_ReadNextSymbolExpected;
		_LexerInterface_RewindSymbol = &IMPL::_LexerInterface_RewindSymbol;
		_LexerInterface_GetSymbol = &IMPL::_LexerInterface_GetSymbol;
		_LexerInterface_GetLeadingSpace = &IMPL::_LexerInterface_GetLeadingSpace;
		_LexerInterface_GetIdent = &IMPL::_LexerInterface_GetIdent;
		_LexerInterface_GetFloat = &IMPL::_LexerInterface_GetFloat;
		_LexerInterface_GetFloat_1 = &IMPL::_LexerInterface_GetFloat_1;
		_LexerInterface_GetInt = &IMPL::_LexerInterface_GetInt;
		_LexerInterface_GetInt_1 = &IMPL::_LexerInterface_GetInt_1;
		_LexerInterface_GetUInt = &IMPL::_LexerInterface_GetUInt;
		_LexerInterface_GetUInt_1 = &IMPL::_LexerInterface_GetUInt_1;
		_LexerInterface_GetCurrentReadPosition = &IMPL::_LexerInterface_GetCurrentReadPosition;
		_LexerInterface_GetSymbolPosition = &IMPL::_LexerInterface_GetSymbolPosition;
		_LexerInterface_CheckIdent = &IMPL::_LexerInterface_CheckIdent;
		_LexerInterface_CheckIdent_1 = &IMPL::_LexerInterface_CheckIdent_1;
		_LexerInterface_GetLine = &IMPL::_LexerInterface_GetLine;
	}
};

struct LexerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _LexerInterface_Free(const LexerInterface* object) { return C::Free(object); }
	static LexerInterface* _LexerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _LexerInterface_Init(LexerInterface* this_, UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) { return ((C*) this_)->Init(std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding); }
	static Result<void> _LexerInterface_AddOperator(LexerInterface* this_, const String& chars) { return ((C*) this_)->AddOperator(chars); }
	static Result<void> _LexerInterface_Close(LexerInterface* this_) { return ((C*) this_)->Close(); }
	static Result<Utf32Char> _LexerInterface_ReadNextChar(LexerInterface* this_) { return ((C*) this_)->ReadNextChar(); }
	static Result<Bool> _LexerInterface_SkipSpaces(LexerInterface* this_) { return ((C*) this_)->SkipSpaces(); }
	static Result<Bool> _LexerInterface_SkipLineToEnd(LexerInterface* this_, Bool collectSkipped) { return ((C*) this_)->SkipLineToEnd(collectSkipped); }
	static Result<LEXERSYMBOL> _LexerInterface_ReadNextSymbol(LexerInterface* this_, LEXERSYMBOLFLAGS flags) { return ((C*) this_)->ReadNextSymbol(flags); }
	static Result<void> _LexerInterface_ReadNextSymbolExpected(LexerInterface* this_, LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) { return ((C*) this_)->ReadNextSymbolExpected(expectedSymbols, flags); }
	static void _LexerInterface_RewindSymbol(LexerInterface* this_) { return ((C*) this_)->RewindSymbol(); }
	static LEXERSYMBOL _LexerInterface_GetSymbol(const LexerInterface* this_) { return ((const C*) this_)->GetSymbol(); }
	static Int _LexerInterface_GetLeadingSpace(const LexerInterface* this_) { return ((const C*) this_)->GetLeadingSpace(); }
	static String _LexerInterface_GetIdent(const LexerInterface* this_) { return ((const C*) this_)->GetIdent(); }
	static Result<void> _LexerInterface_GetFloat(const LexerInterface* this_, Float32& val) { return ((const C*) this_)->GetFloat(val); }
	static Result<void> _LexerInterface_GetFloat_1(const LexerInterface* this_, Float64& val) { return ((const C*) this_)->GetFloat(val); }
	static Result<void> _LexerInterface_GetInt(const LexerInterface* this_, Int32& val) { return ((const C*) this_)->GetInt(val); }
	static Result<void> _LexerInterface_GetInt_1(const LexerInterface* this_, Int64& val) { return ((const C*) this_)->GetInt(val); }
	static Result<void> _LexerInterface_GetUInt(const LexerInterface* this_, UInt32& val) { return ((const C*) this_)->GetUInt(val); }
	static Result<void> _LexerInterface_GetUInt_1(const LexerInterface* this_, UInt64& val) { return ((const C*) this_)->GetUInt(val); }
	static Result<Int64> _LexerInterface_GetCurrentReadPosition(const LexerInterface* this_) { return ((const C*) this_)->GetCurrentReadPosition(); }
	static Result<Int64> _LexerInterface_GetSymbolPosition(const LexerInterface* this_) { return ((const C*) this_)->GetSymbolPosition(); }
	static Bool _LexerInterface_CheckIdent(const LexerInterface* this_, const Char* cmp) { return ((const C*) this_)->CheckIdent(cmp); }
	static Bool _LexerInterface_CheckIdent_1(const LexerInterface* this_, const String& cmp) { return ((const C*) this_)->CheckIdent(cmp); }
	static Int _LexerInterface_GetLine(const LexerInterface* this_) { return ((const C*) this_)->GetLine(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Free(const LexerInterface* object) -> void
{
	return MTable::_instance._LexerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LexerInterface*
{
	return MTable::_instance._LexerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) -> Result<void>
{
	return MTable::_instance._LexerInterface_Init(this, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::AddOperator(const String& chars) -> Result<void>
{
	return MTable::_instance._LexerInterface_AddOperator(this, chars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Close() -> Result<void>
{
	return MTable::_instance._LexerInterface_Close(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextChar() -> Result<Utf32Char>
{
	return MTable::_instance._LexerInterface_ReadNextChar(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipSpaces() -> Result<Bool>
{
	return MTable::_instance._LexerInterface_SkipSpaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::SkipLineToEnd(Bool collectSkipped) -> Result<Bool>
{
	return MTable::_instance._LexerInterface_SkipLineToEnd(this, collectSkipped);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbol(LEXERSYMBOLFLAGS flags) -> Result<LEXERSYMBOL>
{
	return MTable::_instance._LexerInterface_ReadNextSymbol(this, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) -> Result<void>
{
	return MTable::_instance._LexerInterface_ReadNextSymbolExpected(this, expectedSymbols, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::RewindSymbol() -> void
{
	return MTable::_instance._LexerInterface_RewindSymbol(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbol() const -> LEXERSYMBOL
{
	return MTable::_instance._LexerInterface_GetSymbol(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLeadingSpace() const -> Int
{
	return MTable::_instance._LexerInterface_GetLeadingSpace(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetIdent() const -> String
{
	return MTable::_instance._LexerInterface_GetIdent(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float32& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetFloat(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetFloat(Float64& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetFloat_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int32& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetInt(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetInt(Int64& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetInt_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt32& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetUInt(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetUInt(UInt64& val) const -> Result<void>
{
	return MTable::_instance._LexerInterface_GetUInt_1(this, val);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetCurrentReadPosition() const -> Result<Int64>
{
	return MTable::_instance._LexerInterface_GetCurrentReadPosition(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetSymbolPosition() const -> Result<Int64>
{
	return MTable::_instance._LexerInterface_GetSymbolPosition(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const Char* cmp) const -> Bool
{
	return MTable::_instance._LexerInterface_CheckIdent(this, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::CheckIdent(const String& cmp) const -> Bool
{
	return MTable::_instance._LexerInterface_CheckIdent_1(this, cmp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::GetLine() const -> Int
{
	return MTable::_instance._LexerInterface_GetLine(this);
}

auto LexerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LexerRef>
{
	LexerInterface* res_ = LexerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LexerRef(maxon::ForwardResultPtr<LexerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_Init(o_, std::forward<UrlOrInputStream>(fileName), flags, stringEscapeCharacters, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::AddOperator(const String& chars) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_AddOperator(o_, chars));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_Close(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadNextChar() const -> Result<Utf32Char>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Utf32Char>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_ReadNextChar(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::SkipSpaces() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_SkipSpaces(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::SkipLineToEnd(Bool collectSkipped) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_SkipLineToEnd(o_, collectSkipped));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadNextSymbol(LEXERSYMBOLFLAGS flags) const -> Result<LEXERSYMBOL>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEXERSYMBOL>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_ReadNextSymbol(o_, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._LexerInterface_ReadNextSymbolExpected(o_, expectedSymbols, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ReferenceFunctionsImpl<S>::RewindSymbol() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LexerInterface* o_ = (LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._LexerInterface_RewindSymbol(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSymbol() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LEXERSYMBOL>, LEXERSYMBOL>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LEXERSYMBOL>, LEXERSYMBOL>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LEXERSYMBOL>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LexerInterface_GetSymbol(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLeadingSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._LexerInterface_GetLeadingSpace(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIdent() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LexerInterface_GetIdent(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFloat(Float32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetFloat(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFloat(Float64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetFloat_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInt(Int32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetInt(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInt(Int64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetInt_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUInt(UInt32& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetUInt(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUInt(UInt64& val) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetUInt_1(o_, val));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCurrentReadPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetCurrentReadPosition(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSymbolPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LexerInterface_GetSymbolPosition(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CheckIdent(const Char* cmp) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._LexerInterface_CheckIdent(o_, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CheckIdent(const String& cmp) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._LexerInterface_CheckIdent_1(o_, cmp));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LexerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLine() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LexerInterface* o_ = (const LexerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LexerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._LexerInterface_GetLine(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

