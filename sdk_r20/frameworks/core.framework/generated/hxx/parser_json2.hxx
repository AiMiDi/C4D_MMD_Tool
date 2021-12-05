
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct NetworkProtocolJSONInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_NetworkProtocolJSONInterface_Free) (const NetworkProtocolJSONInterface* object);
	Interface* (*_NetworkProtocolJSONInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_NetworkProtocolJSONInterface_ConvertToJSON) (NetworkProtocolJSONInterface* this_, const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting);
	Result<void> (*_NetworkProtocolJSONInterface_ConvertFromJSON) (NetworkProtocolJSONInterface* this_, const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject);
	Result<void> (*_NetworkProtocolJSONInterface_ConvertFromJSON_1) (NetworkProtocolJSONInterface* this_, const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_NetworkProtocolJSONInterface_Free = &IMPL::_NetworkProtocolJSONInterface_Free;
		tbl->_NetworkProtocolJSONInterface_Alloc = &IMPL::_NetworkProtocolJSONInterface_Alloc;
		tbl->_NetworkProtocolJSONInterface_ConvertToJSON = &IMPL::_NetworkProtocolJSONInterface_ConvertToJSON;
		tbl->_NetworkProtocolJSONInterface_ConvertFromJSON = &IMPL::_NetworkProtocolJSONInterface_ConvertFromJSON;
		tbl->_NetworkProtocolJSONInterface_ConvertFromJSON_1 = &IMPL::_NetworkProtocolJSONInterface_ConvertFromJSON_1;
	}
};

template <typename C> class NetworkProtocolJSONInterface::Wrapper
{
public:
	static void _NetworkProtocolJSONInterface_Free(const NetworkProtocolJSONInterface* object) { return C::Free(object); }
	static Interface* _NetworkProtocolJSONInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _NetworkProtocolJSONInterface_ConvertToJSON(NetworkProtocolJSONInterface* this_, const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) { return ((C*) this_)->ConvertToJSON(jsonObject, jsonString, niceFormatting); }
	static Result<void> _NetworkProtocolJSONInterface_ConvertFromJSON(NetworkProtocolJSONInterface* this_, const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject) { return ((C*) this_)->ConvertFromJSON(stream, flags, stringDecoding, jsonObject); }
	static Result<void> _NetworkProtocolJSONInterface_ConvertFromJSON_1(NetworkProtocolJSONInterface* this_, const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject) { return ((C*) this_)->ConvertFromJSON(jsonString, flags, jsonObject); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::Free(const NetworkProtocolJSONInterface* object) -> void
{
	return MTable::_instance._NetworkProtocolJSONInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Interface*
{
	return MTable::_instance._NetworkProtocolJSONInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) -> Result<void>
{
	return MTable::_instance._NetworkProtocolJSONInterface_ConvertToJSON(this, jsonObject, jsonString, niceFormatting);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject) -> Result<void>
{
	return MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON(this, stream, flags, stringDecoding, jsonObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject) -> Result<void>
{
	return MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON_1(this, jsonString, flags, jsonObject);
}

auto NetworkProtocolJSONInterface::Reference::Create() -> maxon::ResultMemT<NetworkProtocolJSONRef>
{
	Interface* res_ = NetworkProtocolJSONInterface::Alloc(MAXON_SOURCE_LOCATION);
	return NetworkProtocolJSONRef(maxon::ForwardResultPtr<Interface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ReferenceFunctionsImpl<S>::ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NetworkProtocolJSONInterface* o_ = (NetworkProtocolJSONInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._NetworkProtocolJSONInterface_ConvertToJSON(o_, jsonObject, jsonString, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ReferenceFunctionsImpl<S>::ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NetworkProtocolJSONInterface* o_ = (NetworkProtocolJSONInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON(o_, stream, flags, stringDecoding, jsonObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NetworkProtocolJSONInterface::ReferenceFunctionsImpl<S>::ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NetworkProtocolJSONInterface* o_ = (NetworkProtocolJSONInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON_1(o_, jsonString, flags, jsonObject));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_NetworkProtocolJSONInterface(NetworkProtocolJSONInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser_json.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

