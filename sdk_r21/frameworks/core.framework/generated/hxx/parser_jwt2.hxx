
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct JwtParserInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_JwtParserInterface_Free) (const JwtParserInterface* object);
	Interface* (*_JwtParserInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_JwtParserInterface_Read) (JwtParserInterface* this_, UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken);
	Result<void> (*_JwtParserInterface_Read_1) (JwtParserInterface* this_, const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects);
	Result<CString> (*_JwtParserInterface_Write) (JwtParserInterface* this_, const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey);
	template <typename IMPL> void Init()
	{
		_JwtParserInterface_Free = &IMPL::_JwtParserInterface_Free;
		_JwtParserInterface_Alloc = &IMPL::_JwtParserInterface_Alloc;
		_JwtParserInterface_Read = &IMPL::_JwtParserInterface_Read;
		_JwtParserInterface_Read_1 = &IMPL::_JwtParserInterface_Read_1;
		_JwtParserInterface_Write = &IMPL::_JwtParserInterface_Write;
	}
};

struct JwtParserInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _JwtParserInterface_Free(const JwtParserInterface* object) { return C::Free(object); }
	static Interface* _JwtParserInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _JwtParserInterface_Read(JwtParserInterface* this_, UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken) { return ((C*) this_)->Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, publicKey, jsonObjects, originalToken); }
	static Result<void> _JwtParserInterface_Read_1(JwtParserInterface* this_, const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects) { return ((C*) this_)->Read(jwtString, flags, stringDecoding, publicKey, jsonObjects); }
	static Result<CString> _JwtParserInterface_Write(JwtParserInterface* this_, const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey) { return ((C*) this_)->Write(jsonObject, stringEncoding, privateKey); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Free(const JwtParserInterface* object) -> void
{
	return MTable::_instance._JwtParserInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Interface*
{
	return MTable::_instance._JwtParserInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken) -> Result<void>
{
	return MTable::_instance._JwtParserInterface_Read(this, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, publicKey, jsonObjects, originalToken);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects) -> Result<void>
{
	return MTable::_instance._JwtParserInterface_Read_1(this, jwtString, flags, stringDecoding, publicKey, jsonObjects);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Write(const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey) -> Result<CString>
{
	return MTable::_instance._JwtParserInterface_Write(this, jsonObject, stringEncoding, privateKey);
}

auto JwtParserInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<JwtParserRef>
{
	Interface* res_ = JwtParserInterface::Alloc(MAXON_SOURCE_LOCATION);
	return JwtParserRef(maxon::ForwardResultPtr<Interface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JwtParserInterface* o_ = (JwtParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JwtParserInterface_Read(o_, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, publicKey, jsonObjects, originalToken));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JwtParserInterface* o_ = (JwtParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JwtParserInterface_Read_1(o_, jwtString, flags, stringDecoding, publicKey, jsonObjects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JwtParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey) const -> Result<CString>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CString>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JwtParserInterface* o_ = (JwtParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JwtParserInterface_Write(o_, jsonObject, stringEncoding, privateKey));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_JwtParserInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_JwtParserInterface() { new (s_ui_maxon_JwtParserInterface) maxon::EntityUse(JwtParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser_jwt.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_JwtParserInterface(JwtParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser_jwt.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

