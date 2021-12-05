#if 1
namespace maxon
{
	namespace enum19 { enum class NETWORKPROTOCOLJSONFLAGS
	{
		NONE						= 0,
		HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the json object.
	} ; }
	maxon::String PrivateToString_NETWORKPROTOCOLJSONFLAGS19(std::underlying_type<enum19::NETWORKPROTOCOLJSONFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::NETWORKPROTOCOLJSONFLAGS::NONE, (maxon::UInt64) enum19::NETWORKPROTOCOLJSONFLAGS::HAS_NO_EOF};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NETWORKPROTOCOLJSONFLAGS", SIZEOF(x), true, values, "NONE\0HAS_NO_EOF\0", fmt);
	}
	const maxon::Char* const NetworkProtocolJSONInterface::MTable::_ids = 
		"Free@91115c1f84187890\0" // Free(const NetworkProtocolJSONInterface* object)
		"Alloc@f92856a34cadb001\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"ConvertToJSON@25363bc62e81223c\0" // ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting)
		"ConvertFromJSON@0b0b000df0076e75\0" // ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject)
		"ConvertFromJSON@d5a8ec6284f30a7f\0" // ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject)
	"";
	class NetworkProtocolJSONInterface::Unresolved : public NetworkProtocolJSONInterface
	{
	public:
		static const Unresolved* Get(const NetworkProtocolJSONInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(NetworkProtocolJSONInterface* o) { return (Unresolved*) o; }
		static void Free(const NetworkProtocolJSONInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return NetworkProtocolJSONInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Interface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return NetworkProtocolJSONInterface::Alloc(allocLocation); return nullptr;}
		Result<void> ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((NetworkProtocolJSONInterface*) this)->ConvertToJSON(jsonObject, jsonString, niceFormatting); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((NetworkProtocolJSONInterface*) this)->ConvertFromJSON(stream, flags, stringDecoding, jsonObject); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((NetworkProtocolJSONInterface*) this)->ConvertFromJSON(jsonString, flags, jsonObject); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE NetworkProtocolJSONInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Interface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool NetworkProtocolJSONInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_NetworkProtocolJSONInterface_Free = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_NetworkProtocolJSONInterface_Alloc = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NetworkProtocolJSONInterface_ConvertToJSON = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertToJSON;
	#else
		tbl->_NetworkProtocolJSONInterface_ConvertToJSON = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertToJSON;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NetworkProtocolJSONInterface_ConvertFromJSON = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertFromJSON;
	#else
		tbl->_NetworkProtocolJSONInterface_ConvertFromJSON = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertFromJSON;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NetworkProtocolJSONInterface_ConvertFromJSON_1 = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertFromJSON_1;
	#else
		tbl->_NetworkProtocolJSONInterface_ConvertFromJSON_1 = &Wrapper<Unresolved>::_NetworkProtocolJSONInterface_ConvertFromJSON_1;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(NetworkProtocolJSONInterface, "net.maxon.interface.networkprotocoljson", nullptr);
	template <typename DUMMY> maxon::Int NetworkProtocolJSONInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_parser_json(0
	| maxon::NetworkProtocolJSONInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
