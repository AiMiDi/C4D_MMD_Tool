#if 1
namespace maxon
{
	const maxon::Char* const StringConversion::MTable::_ids = 
		"FloatToString@caaec0d78626fcdf\0" // String FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement)
		"FloatToString@404736f9f8590ea0\0" // String FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement)
		"AppendInt@ddf175b513a7badd\0" // void AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendUInt@1f4199735848b73e\0" // void AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendInt@dc8bc391effdafa2\0" // void AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendUInt@f3f1073206b15b19\0" // void AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"MemorySizeToString@ae0cea5f3a7cf568\0" // String MemorySizeToString(Int64 mem, Bool mebibytes)
		"HexToString@5e8b8bb71f2b63f3\0" // String HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement)
		"HexToString@dedaf18e499a8c92\0" // String HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement)
		"ToFloat32@76e5b984e915688a\0" // Result<Float32> ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToFloat64@e83930d3970a0e0b\0" // Result<Float64> ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToInt64@209f01567e89c158\0" // Result<Int64> ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToInt32@af4b8a07d0951bd7\0" // Result<Int32> ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToUInt64@3328be084489cf0f\0" // Result<UInt64> ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToUInt32@c1d546b99695298e\0" // Result<UInt32> ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"StringToFloat@ac3097ce13f5103b\0" // Result<Float64> StringToFloat(const Block<const Utf32Char>& str, Int& processedChars)
		"StringToInteger@cbcfde8686e250e2\0" // Result<UInt64> StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars)
		"GetLineEnd@27f2c2db0d16c8b8\0" // const String& GetLineEnd()
		"GetLineEndC@d663fe3cd82b5d2f\0" // const CString& GetLineEndC()
		"FormatXArgs@ee1650e6235338bb\0" // StringProxy* FormatXArgs(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs)
		"ScanStringXArgs@c1a427dd3430c875\0" // Bool ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs)
		"ScanParameterBasic@7c3148c018ea6e55\0" // Int64 ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class StringConversion::Hxx2::Unresolved : public StringConversion
	{
	public:
		static const Unresolved* Get(const StringConversion* o) { return (const Unresolved*) o; }
		static Unresolved* Get(StringConversion* o) { return (Unresolved*) o; }
		static String FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static String FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendUInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendUInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static String MemorySizeToString(Int64 mem, Bool mebibytes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::MemorySizeToString(mem, mebibytes); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static String HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::HexToString(value, prefix0x, leadingZeros, formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static String HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::HexToString(value, prefix0x, leadingZeros, formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<Float32> ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToFloat32(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Float64> ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToFloat64(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Int64> ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToInt64(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Int32> ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToInt32(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<UInt64> ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToUInt64(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<UInt32> ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToUInt32(str, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Float64> StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::StringToFloat(str, processedChars); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<UInt64> StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::StringToInteger(str, base, autodetect0x, signedMode, processedChars); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const String& GetLineEnd() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::GetLineEnd(); return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const CString& GetLineEndC() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::GetLineEndC(); return maxon::PrivateIncompleteNullReturnValue<const CString&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static StringProxy* FormatXArgs(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FormatXArgs(formatString, argsCnt, args, argFuncs); return nullptr;}
		static Bool ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs); return maxon::PrivateLogNullptrError(false);}
		static Int64 ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::ScanParameterBasic(str, signedMode, processed, formatStatement, error); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE StringConversion::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<Float32>>::value,
		maxon::details::NullReturnType<Result<Float64>>::value,
		maxon::details::NullReturnType<Result<Int64>>::value,
		maxon::details::NullReturnType<Result<Int32>>::value,
		maxon::details::NullReturnType<Result<UInt64>>::value,
		maxon::details::NullReturnType<Result<UInt32>>::value,
		maxon::details::NullReturnType<Result<Float64>>::value,
		maxon::details::NullReturnType<Result<UInt64>>::value,
		maxon::details::NullReturnType<const String&>::value,
		maxon::details::NullReturnType<const CString&>::value,
		maxon::details::NullReturnType<StringProxy*>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Int64>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool StringConversion::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_FloatToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_FloatToString;
		#else
		tbl->_StringConversion_FloatToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_FloatToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_FloatToString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_FloatToString_1;
		#else
		tbl->_StringConversion_FloatToString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_FloatToString_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_AppendInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_AppendInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_AppendUInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_AppendUInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_AppendInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_AppendInt_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_AppendUInt_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_AppendUInt_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_MemorySizeToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_MemorySizeToString;
		#else
		tbl->_StringConversion_MemorySizeToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_MemorySizeToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_HexToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_HexToString;
		#else
		tbl->_StringConversion_HexToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_HexToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_HexToString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_HexToString_1;
		#else
		tbl->_StringConversion_HexToString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_HexToString_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToFloat32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToFloat32;
		#else
		tbl->_StringConversion_ToFloat32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToFloat32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToFloat64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToFloat64;
		#else
		tbl->_StringConversion_ToFloat64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToFloat64;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToInt64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToInt64;
		#else
		tbl->_StringConversion_ToInt64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToInt64;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToInt32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToInt32;
		#else
		tbl->_StringConversion_ToInt32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToInt32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<UInt64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToUInt64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToUInt64;
		#else
		tbl->_StringConversion_ToUInt64 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToUInt64;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<UInt32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_ToUInt32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToUInt32;
		#else
		tbl->_StringConversion_ToUInt32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ToUInt32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_StringToFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_StringToFloat;
		#else
		tbl->_StringConversion_StringToFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_StringToFloat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<UInt64>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_StringToInteger = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_StringToInteger;
		#else
		tbl->_StringConversion_StringToInteger = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_StringToInteger;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const String&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_GetLineEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_GetLineEnd;
		#else
		tbl->_StringConversion_GetLineEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_GetLineEnd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const CString&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringConversion_GetLineEndC = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_GetLineEndC;
		#else
		tbl->_StringConversion_GetLineEndC = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_GetLineEndC;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_FormatXArgs = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_FormatXArgs;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_ScanStringXArgs = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ScanStringXArgs;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringConversion_ScanParameterBasic = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringConversion_ScanParameterBasic;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(StringConversion, "net.maxon.interface.stringconversion", nullptr);
	template <typename DUMMY> maxon::Int StringConversion::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const CString&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const String&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stringconversion(0
	| maxon::StringConversion::PrivateInstantiateNullValueHelper<maxon::Int>()
);
