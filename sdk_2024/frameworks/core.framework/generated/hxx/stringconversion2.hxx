
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* StringConversion::PrivateGetCppName() { return nullptr; }

struct StringConversion::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(StringConversion_FloatToString, FloatToString, MAXON_EXPAND_VA_ARGS, (String), Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_FloatToString_1, FloatToString, MAXON_EXPAND_VA_ARGS, (String), Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_AppendInt, AppendInt, MAXON_EXPAND_VA_ARGS, (void), StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_AppendUInt, AppendUInt, MAXON_EXPAND_VA_ARGS, (void), StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_AppendInt_1, AppendInt, MAXON_EXPAND_VA_ARGS, (void), CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_AppendUInt_1, AppendUInt, MAXON_EXPAND_VA_ARGS, (void), CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_MemorySizeToString, MemorySizeToString, MAXON_EXPAND_VA_ARGS, (String), Int64 mem, Bool mebibytes);
	PRIVATE_MAXON_SF_POINTER(StringConversion_HexToString, HexToString, MAXON_EXPAND_VA_ARGS, (String), UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_HexToString_1, HexToString, MAXON_EXPAND_VA_ARGS, (String), UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToFloat32, ToFloat32, MAXON_EXPAND_VA_ARGS, (Result<Float32>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToFloat64, ToFloat64, MAXON_EXPAND_VA_ARGS, (Result<Float64>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToInt64, ToInt64, MAXON_EXPAND_VA_ARGS, (Result<Int64>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToInt32, ToInt32, MAXON_EXPAND_VA_ARGS, (Result<Int32>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToUInt64, ToUInt64, MAXON_EXPAND_VA_ARGS, (Result<UInt64>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ToUInt32, ToUInt32, MAXON_EXPAND_VA_ARGS, (Result<UInt32>), const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	PRIVATE_MAXON_SF_POINTER(StringConversion_StringToFloat, StringToFloat, MAXON_EXPAND_VA_ARGS, (Result<Float64>), const Block<const Utf32Char>& str, Int& processedChars);
	PRIVATE_MAXON_SF_POINTER(StringConversion_StringToInteger, StringToInteger, MAXON_EXPAND_VA_ARGS, (Result<UInt64>), const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars);
	PRIVATE_MAXON_SF_POINTER(StringConversion_GetLineEnd, GetLineEnd, MAXON_EXPAND_VA_ARGS, (const String&));
	PRIVATE_MAXON_SF_POINTER(StringConversion_GetLineEndC, GetLineEndC, MAXON_EXPAND_VA_ARGS, (const CString&));
	PRIVATE_MAXON_SF_POINTER(StringConversion_FormatXArgs, FormatXArgs, MAXON_EXPAND_VA_ARGS, (StringProxy*), const String& formatString, Int argsCnt, const void** args, const TOSTR* argFuncs);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ScanStringXArgs, ScanStringXArgs, MAXON_EXPAND_VA_ARGS, (Bool), const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs);
	PRIVATE_MAXON_SF_POINTER(StringConversion_ScanParameterBasic, ScanParameterBasic, MAXON_EXPAND_VA_ARGS, (Int64), const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error);
	template <typename IMPL> void Init()
	{
		StringConversion_FloatToString = StringConversion_FloatToString_GetPtr<IMPL>(true);
		StringConversion_FloatToString_1 = StringConversion_FloatToString_1_GetPtr<IMPL>(true);
		StringConversion_AppendInt = StringConversion_AppendInt_GetPtr<IMPL>(true);
		StringConversion_AppendUInt = StringConversion_AppendUInt_GetPtr<IMPL>(true);
		StringConversion_AppendInt_1 = StringConversion_AppendInt_1_GetPtr<IMPL>(true);
		StringConversion_AppendUInt_1 = StringConversion_AppendUInt_1_GetPtr<IMPL>(true);
		StringConversion_MemorySizeToString = StringConversion_MemorySizeToString_GetPtr<IMPL>(true);
		StringConversion_HexToString = StringConversion_HexToString_GetPtr<IMPL>(true);
		StringConversion_HexToString_1 = StringConversion_HexToString_1_GetPtr<IMPL>(true);
		StringConversion_ToFloat32 = StringConversion_ToFloat32_GetPtr<IMPL>(true);
		StringConversion_ToFloat64 = StringConversion_ToFloat64_GetPtr<IMPL>(true);
		StringConversion_ToInt64 = StringConversion_ToInt64_GetPtr<IMPL>(true);
		StringConversion_ToInt32 = StringConversion_ToInt32_GetPtr<IMPL>(true);
		StringConversion_ToUInt64 = StringConversion_ToUInt64_GetPtr<IMPL>(true);
		StringConversion_ToUInt32 = StringConversion_ToUInt32_GetPtr<IMPL>(true);
		StringConversion_StringToFloat = StringConversion_StringToFloat_GetPtr<IMPL>(true);
		StringConversion_StringToInteger = StringConversion_StringToInteger_GetPtr<IMPL>(true);
		StringConversion_GetLineEnd = StringConversion_GetLineEnd_GetPtr<IMPL>(true);
		StringConversion_GetLineEndC = StringConversion_GetLineEndC_GetPtr<IMPL>(true);
		StringConversion_FormatXArgs = StringConversion_FormatXArgs_GetPtr<IMPL>(true);
		StringConversion_ScanStringXArgs = StringConversion_ScanStringXArgs_GetPtr<IMPL>(true);
		StringConversion_ScanParameterBasic = StringConversion_ScanParameterBasic_GetPtr<IMPL>(true);
	}
};

struct StringConversion::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static String StringConversion_FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { return S::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); }
		static String StringConversion_FloatToString_1(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { return S::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); }
		static void StringConversion_AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { return S::AppendInt(str, value, datatypeSize, formatStatement); }
		static void StringConversion_AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { return S::AppendUInt(str, value, datatypeSize, formatStatement); }
		static void StringConversion_AppendInt_1(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { return S::AppendInt(str, value, datatypeSize, formatStatement); }
		static void StringConversion_AppendUInt_1(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { return S::AppendUInt(str, value, datatypeSize, formatStatement); }
		static String StringConversion_MemorySizeToString(Int64 mem, Bool mebibytes) { return S::MemorySizeToString(mem, mebibytes); }
		static String StringConversion_HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { return S::HexToString(value, prefix0x, leadingZeros, formatStatement); }
		static String StringConversion_HexToString_1(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { return S::HexToString(value, prefix0x, leadingZeros, formatStatement); }
		static Result<Float32> StringConversion_ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToFloat32(str, flags); }
		static Result<Float64> StringConversion_ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToFloat64(str, flags); }
		static Result<Int64> StringConversion_ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToInt64(str, flags); }
		static Result<Int32> StringConversion_ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToInt32(str, flags); }
		static Result<UInt64> StringConversion_ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToUInt64(str, flags); }
		static Result<UInt32> StringConversion_ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return S::ToUInt32(str, flags); }
		static Result<Float64> StringConversion_StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) { return S::StringToFloat(str, processedChars); }
		static Result<UInt64> StringConversion_StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) { return S::StringToInteger(str, base, autodetect0x, signedMode, processedChars); }
		static const String& StringConversion_GetLineEnd() { return S::GetLineEnd(); }
		static const CString& StringConversion_GetLineEndC() { return S::GetLineEndC(); }
		static StringProxy* StringConversion_FormatXArgs(const String& formatString, Int argsCnt, const void** args, const TOSTR* argFuncs) { return S::FormatXArgs(formatString, argsCnt, args, argFuncs); }
		static Bool StringConversion_ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) { return S::ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs); }
		static Int64 StringConversion_ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) { return S::ScanParameterBasic(str, signedMode, processed, formatStatement, error); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance.StringConversion_FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance.StringConversion_FloatToString_1(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance.StringConversion_AppendInt(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance.StringConversion_AppendUInt(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance.StringConversion_AppendInt_1(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance.StringConversion_AppendUInt_1(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::MemorySizeToString(Int64 mem, Bool mebibytes) -> String
{
	return MTable::_instance.StringConversion_MemorySizeToString(mem, mebibytes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance.StringConversion_HexToString(value, prefix0x, leadingZeros, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance.StringConversion_HexToString_1(value, prefix0x, leadingZeros, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Float32>
{
	return MTable::_instance.StringConversion_ToFloat32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Float64>
{
	return MTable::_instance.StringConversion_ToFloat64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Int64>
{
	return MTable::_instance.StringConversion_ToInt64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Int32>
{
	return MTable::_instance.StringConversion_ToInt32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<UInt64>
{
	return MTable::_instance.StringConversion_ToUInt64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<UInt32>
{
	return MTable::_instance.StringConversion_ToUInt32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) -> Result<Float64>
{
	return MTable::_instance.StringConversion_StringToFloat(str, processedChars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) -> Result<UInt64>
{
	return MTable::_instance.StringConversion_StringToInteger(str, base, autodetect0x, signedMode, processedChars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::GetLineEnd() -> const String&
{
	return MTable::_instance.StringConversion_GetLineEnd();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::GetLineEndC() -> const CString&
{
	return MTable::_instance.StringConversion_GetLineEndC();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FormatXArgs(const String& formatString, Int argsCnt, const void** args, const TOSTR* argFuncs) -> StringProxy*
{
	return MTable::_instance.StringConversion_FormatXArgs(formatString, argsCnt, args, argFuncs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) -> Bool
{
	return MTable::_instance.StringConversion_ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) -> Int64
{
	return MTable::_instance.StringConversion_ScanParameterBasic(str, signedMode, processed, formatStatement, error);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_stringconversion)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StringConversion); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StringConversion() { new (s_ui_maxon_StringConversion) maxon::EntityUse(StringConversion::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringconversion.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StringConversion(StringConversion::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringconversion.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

