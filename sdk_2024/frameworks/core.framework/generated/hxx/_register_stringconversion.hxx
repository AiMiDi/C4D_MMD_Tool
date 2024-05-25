#if 1
namespace maxon
{
	const maxon::Char* const StringConversion::MTable::_ids = 
		"FloatToString@a9bf1f3fd28b72d4\0" // String FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement)
		"FloatToString@dbbdbc9eda788ded\0" // String FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement)
		"AppendInt@5c241b7c01ad9ebc\0" // void AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendUInt@a272b533665cf609\0" // void AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendInt@5c2ec67e2642af35\0" // void AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"AppendUInt@f8e07eb0b0c5a112\0" // void AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement)
		"MemorySizeToString@45b03af4615d0005\0" // String MemorySizeToString(Int64 mem, Bool mebibytes)
		"HexToString@74b59a994ae76f30\0" // String HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement)
		"HexToString@fb2ba6b37138ecc3\0" // String HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement)
		"ToFloat32@f0dd2a6503f4376f\0" // Result<Float32> ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToFloat64@bb9f0fe95728c7ba\0" // Result<Float64> ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToInt64@b03108b5308a16b7\0" // Result<Int64> ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToInt32@8b67ff4e945f7fe6\0" // Result<Int32> ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToUInt64@ac7cc23ece218a0\0" // Result<UInt64> ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"ToUInt32@781a667629ecdd81\0" // Result<UInt32> ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags)
		"StringToFloat@5496ab4e40c764be\0" // Result<Float64> StringToFloat(const Block<const Utf32Char>& str, Int& processedChars)
		"StringToInteger@148b4fea24d611a5\0" // Result<UInt64> StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars)
		"GetLineEnd@8fd391aed037fedf\0" // const String& GetLineEnd()
		"GetLineEndC@d001d7a32e0d3520\0" // const CString& GetLineEndC()
		"FormatXArgs@8845f7e79fb4d709\0" // StringProxy* FormatXArgs(const String& formatString, Int argsCnt, const void** args, const TOSTR* argFuncs)
		"ScanStringXArgs@f2df7c590741b654\0" // Bool ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs)
		"ScanParameterBasic@496525ff0e9463dc\0" // Int64 ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class StringConversion::Hxx2::Unresolved : public StringConversion
	{
	public:
		static const Unresolved* Get(const StringConversion* o) { return (const Unresolved*) o; }
		static Unresolved* Get(StringConversion* o) { return (Unresolved*) o; }
		static String FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); return HXXRET3(UNRESOLVED, String);}
		static String FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); return HXXRET3(UNRESOLVED, String);}
		static void AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendUInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static void AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::AppendUInt(str, value, datatypeSize, formatStatement); return maxon::PrivateLogNullptrError();}
		static String MemorySizeToString(Int64 mem, Bool mebibytes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::MemorySizeToString(mem, mebibytes); return HXXRET3(UNRESOLVED, String);}
		static String HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::HexToString(value, prefix0x, leadingZeros, formatStatement); return HXXRET3(UNRESOLVED, String);}
		static String HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::HexToString(value, prefix0x, leadingZeros, formatStatement); return HXXRET3(UNRESOLVED, String);}
		static Result<Float32> ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToFloat32(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<Float64> ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToFloat64(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<Int64> ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToInt64(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<Int32> ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToInt32(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<UInt64> ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToUInt64(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<UInt32> ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::ToUInt32(str, flags); return HXXRET1(UNRESOLVED);}
		static Result<Float64> StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::StringToFloat(str, processedChars); return HXXRET1(UNRESOLVED);}
		static Result<UInt64> StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return StringConversion::StringToInteger(str, base, autodetect0x, signedMode, processedChars); return HXXRET1(UNRESOLVED);}
		static const String& GetLineEnd() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::GetLineEnd(); return HXXRET3(UNRESOLVED, const String&);}
		static const CString& GetLineEndC() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::GetLineEndC(); return HXXRET3(UNRESOLVED, const CString&);}
		static StringProxy* FormatXArgs(const String& formatString, Int argsCnt, const void** args, const TOSTR* argFuncs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::FormatXArgs(formatString, argsCnt, args, argFuncs); return nullptr;}
		static Bool ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs); return maxon::PrivateLogNullptrError(false);}
		static Int64 ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringConversion::ScanParameterBasic(str, signedMode, processed, formatStatement, error); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE StringConversion::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<Result<Float32>>::value,
		maxon::details::UnresolvedReturnType<Result<Float64>>::value,
		maxon::details::UnresolvedReturnType<Result<Int64>>::value,
		maxon::details::UnresolvedReturnType<Result<Int32>>::value,
		maxon::details::UnresolvedReturnType<Result<UInt64>>::value,
		maxon::details::UnresolvedReturnType<Result<UInt32>>::value,
		maxon::details::UnresolvedReturnType<Result<Float64>>::value,
		maxon::details::UnresolvedReturnType<Result<UInt64>>::value,
		maxon::details::UnresolvedReturnType<const String&>::value,
		maxon::details::UnresolvedReturnType<const CString&>::value,
		maxon::details::UnresolvedReturnType<StringProxy*>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Int64>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool StringConversion::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_FloatToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_FloatToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_FloatToString);
		#else
		tbl->StringConversion_FloatToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_FloatToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_FloatToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_FloatToString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_FloatToString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_FloatToString_1);
		#else
		tbl->StringConversion_FloatToString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_FloatToString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_FloatToString_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_AppendInt = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_AppendInt), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_AppendInt);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_AppendUInt = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_AppendUInt), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_AppendUInt);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_AppendInt_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_AppendInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_AppendInt_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_AppendUInt_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_AppendUInt_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_AppendUInt_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_MemorySizeToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_MemorySizeToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_MemorySizeToString);
		#else
		tbl->StringConversion_MemorySizeToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_MemorySizeToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_MemorySizeToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_HexToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_HexToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_HexToString);
		#else
		tbl->StringConversion_HexToString = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_HexToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_HexToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_HexToString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_HexToString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_HexToString_1);
		#else
		tbl->StringConversion_HexToString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_HexToString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_HexToString_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Float32>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToFloat32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToFloat32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToFloat32);
		#else
		tbl->StringConversion_ToFloat32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToFloat32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToFloat32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Float64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToFloat64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToFloat64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToFloat64);
		#else
		tbl->StringConversion_ToFloat64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToFloat64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToFloat64);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToInt64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToInt64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToInt64);
		#else
		tbl->StringConversion_ToInt64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToInt64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToInt64);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int32>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToInt32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToInt32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToInt32);
		#else
		tbl->StringConversion_ToInt32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToInt32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToInt32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<UInt64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToUInt64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToUInt64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToUInt64);
		#else
		tbl->StringConversion_ToUInt64 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToUInt64), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToUInt64);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<UInt32>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_ToUInt32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToUInt32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToUInt32);
		#else
		tbl->StringConversion_ToUInt32 = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ToUInt32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ToUInt32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Float64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_StringToFloat = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_StringToFloat), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_StringToFloat);
		#else
		tbl->StringConversion_StringToFloat = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_StringToFloat), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_StringToFloat);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<UInt64>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_StringToInteger = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_StringToInteger), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_StringToInteger);
		#else
		tbl->StringConversion_StringToInteger = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_StringToInteger), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_StringToInteger);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const String&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_GetLineEnd = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_GetLineEnd), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_GetLineEnd);
		#else
		tbl->StringConversion_GetLineEnd = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_GetLineEnd), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_GetLineEnd);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const CString&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringConversion_GetLineEndC = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_GetLineEndC), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_GetLineEndC);
		#else
		tbl->StringConversion_GetLineEndC = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_GetLineEndC), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_GetLineEndC);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_FormatXArgs = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_FormatXArgs), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_FormatXArgs);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_ScanStringXArgs = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ScanStringXArgs), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ScanStringXArgs);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringConversion_ScanParameterBasic = PRIVATE_MAXON_MF_CAST(decltype(StringConversion_ScanParameterBasic), &Hxx2::Wrapper<Hxx2::Unresolved>::StringConversion_ScanParameterBasic);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(StringConversion, "net.maxon.interface.stringconversion", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int StringConversion::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const CString&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const String&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stringconversion(0
	| maxon::StringConversion::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
