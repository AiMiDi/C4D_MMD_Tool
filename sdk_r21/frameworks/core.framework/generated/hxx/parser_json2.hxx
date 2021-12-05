
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct JsonParserInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_JsonParserInterface_Free) (const JsonParserInterface* object);
	Interface* (*_JsonParserInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_JsonParserInterface_Write) (JsonParserInterface* this_, const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting);
	Result<void> (*_JsonParserInterface_Read) (JsonParserInterface* this_, const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects);
	Result<void> (*_JsonParserInterface_Read_1) (JsonParserInterface* this_, UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects);
	template <typename IMPL> void Init()
	{
		_JsonParserInterface_Free = &IMPL::_JsonParserInterface_Free;
		_JsonParserInterface_Alloc = &IMPL::_JsonParserInterface_Alloc;
		_JsonParserInterface_Write = &IMPL::_JsonParserInterface_Write;
		_JsonParserInterface_Read = &IMPL::_JsonParserInterface_Read;
		_JsonParserInterface_Read_1 = &IMPL::_JsonParserInterface_Read_1;
	}
};

struct JsonParserInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _JsonParserInterface_Free(const JsonParserInterface* object) { return C::Free(object); }
	static Interface* _JsonParserInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _JsonParserInterface_Write(JsonParserInterface* this_, const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) { return ((C*) this_)->Write(jsonObject, jsonString, niceFormatting); }
	static Result<void> _JsonParserInterface_Read(JsonParserInterface* this_, const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects) { return ((C*) this_)->Read(jsonString, flags, jsonObjects); }
	static Result<void> _JsonParserInterface_Read_1(JsonParserInterface* this_, UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects) { return ((C*) this_)->Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, jsonObjects); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Free(const JsonParserInterface* object) -> void
{
	return MTable::_instance._JsonParserInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Interface*
{
	return MTable::_instance._JsonParserInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) -> Result<void>
{
	return MTable::_instance._JsonParserInterface_Write(this, jsonObject, jsonString, niceFormatting);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects) -> Result<void>
{
	return MTable::_instance._JsonParserInterface_Read(this, jsonString, flags, jsonObjects);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects) -> Result<void>
{
	return MTable::_instance._JsonParserInterface_Read_1(this, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, jsonObjects);
}

auto JsonParserInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<JsonParserRef>
{
	Interface* res_ = JsonParserInterface::Alloc(MAXON_SOURCE_LOCATION);
	return JsonParserRef(maxon::ForwardResultPtr<Interface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JsonParserInterface* o_ = (JsonParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JsonParserInterface_Write(o_, jsonObject, jsonString, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JsonParserInterface* o_ = (JsonParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JsonParserInterface_Read(o_, jsonString, flags, jsonObjects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JsonParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JsonParserInterface* o_ = (JsonParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._JsonParserInterface_Read_1(o_, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, jsonObjects));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_JsonParserInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_JsonParserInterface() { new (s_ui_maxon_JsonParserInterface) maxon::EntityUse(JsonParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser_json.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_JsonParserInterface(JsonParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser_json.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

