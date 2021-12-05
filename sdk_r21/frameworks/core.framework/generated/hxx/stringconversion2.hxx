
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct StringConversion::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*_StringConversion_FloatToString) (Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);
	String (*_StringConversion_FloatToString_1) (Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);
	void (*_StringConversion_AppendInt) (StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);
	void (*_StringConversion_AppendUInt) (StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);
	void (*_StringConversion_AppendInt_1) (CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);
	void (*_StringConversion_AppendUInt_1) (CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);
	String (*_StringConversion_MemorySizeToString) (Int64 mem, Bool mebibytes);
	String (*_StringConversion_HexToString) (UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);
	String (*_StringConversion_HexToString_1) (UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);
	Result<Float32> (*_StringConversion_ToFloat32) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<Float64> (*_StringConversion_ToFloat64) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<Int64> (*_StringConversion_ToInt64) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<Int32> (*_StringConversion_ToInt32) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<UInt64> (*_StringConversion_ToUInt64) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<UInt32> (*_StringConversion_ToUInt32) (const Block<const Utf32Char>& str, STRINGCONVERSION flags);
	Result<Float64> (*_StringConversion_StringToFloat) (const Block<const Utf32Char>& str, Int& processedChars);
	Result<UInt64> (*_StringConversion_StringToInteger) (const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars);
	const String& (*_StringConversion_GetLineEnd) ();
	const CString& (*_StringConversion_GetLineEndC) ();
	StringProxy* (*_StringConversion_FormatXArgs) (const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs);
	Bool (*_StringConversion_ScanStringXArgs) (const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs);
	Int64 (*_StringConversion_ScanParameterBasic) (const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error);
	template <typename IMPL> void Init()
	{
		_StringConversion_FloatToString = &IMPL::_StringConversion_FloatToString;
		_StringConversion_FloatToString_1 = &IMPL::_StringConversion_FloatToString_1;
		_StringConversion_AppendInt = &IMPL::_StringConversion_AppendInt;
		_StringConversion_AppendUInt = &IMPL::_StringConversion_AppendUInt;
		_StringConversion_AppendInt_1 = &IMPL::_StringConversion_AppendInt_1;
		_StringConversion_AppendUInt_1 = &IMPL::_StringConversion_AppendUInt_1;
		_StringConversion_MemorySizeToString = &IMPL::_StringConversion_MemorySizeToString;
		_StringConversion_HexToString = &IMPL::_StringConversion_HexToString;
		_StringConversion_HexToString_1 = &IMPL::_StringConversion_HexToString_1;
		_StringConversion_ToFloat32 = &IMPL::_StringConversion_ToFloat32;
		_StringConversion_ToFloat64 = &IMPL::_StringConversion_ToFloat64;
		_StringConversion_ToInt64 = &IMPL::_StringConversion_ToInt64;
		_StringConversion_ToInt32 = &IMPL::_StringConversion_ToInt32;
		_StringConversion_ToUInt64 = &IMPL::_StringConversion_ToUInt64;
		_StringConversion_ToUInt32 = &IMPL::_StringConversion_ToUInt32;
		_StringConversion_StringToFloat = &IMPL::_StringConversion_StringToFloat;
		_StringConversion_StringToInteger = &IMPL::_StringConversion_StringToInteger;
		_StringConversion_GetLineEnd = &IMPL::_StringConversion_GetLineEnd;
		_StringConversion_GetLineEndC = &IMPL::_StringConversion_GetLineEndC;
		_StringConversion_FormatXArgs = &IMPL::_StringConversion_FormatXArgs;
		_StringConversion_ScanStringXArgs = &IMPL::_StringConversion_ScanStringXArgs;
		_StringConversion_ScanParameterBasic = &IMPL::_StringConversion_ScanParameterBasic;
	}
};

struct StringConversion::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static String _StringConversion_FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { return C::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); }
	static String _StringConversion_FloatToString_1(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) { return C::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement); }
	static void _StringConversion_AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { return C::AppendInt(str, value, datatypeSize, formatStatement); }
	static void _StringConversion_AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { return C::AppendUInt(str, value, datatypeSize, formatStatement); }
	static void _StringConversion_AppendInt_1(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) { return C::AppendInt(str, value, datatypeSize, formatStatement); }
	static void _StringConversion_AppendUInt_1(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) { return C::AppendUInt(str, value, datatypeSize, formatStatement); }
	static String _StringConversion_MemorySizeToString(Int64 mem, Bool mebibytes) { return C::MemorySizeToString(mem, mebibytes); }
	static String _StringConversion_HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { return C::HexToString(value, prefix0x, leadingZeros, formatStatement); }
	static String _StringConversion_HexToString_1(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) { return C::HexToString(value, prefix0x, leadingZeros, formatStatement); }
	static Result<Float32> _StringConversion_ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToFloat32(str, flags); }
	static Result<Float64> _StringConversion_ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToFloat64(str, flags); }
	static Result<Int64> _StringConversion_ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToInt64(str, flags); }
	static Result<Int32> _StringConversion_ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToInt32(str, flags); }
	static Result<UInt64> _StringConversion_ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToUInt64(str, flags); }
	static Result<UInt32> _StringConversion_ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) { return C::ToUInt32(str, flags); }
	static Result<Float64> _StringConversion_StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) { return C::StringToFloat(str, processedChars); }
	static Result<UInt64> _StringConversion_StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) { return C::StringToInteger(str, base, autodetect0x, signedMode, processedChars); }
	static const String& _StringConversion_GetLineEnd() { return C::GetLineEnd(); }
	static const CString& _StringConversion_GetLineEndC() { return C::GetLineEndC(); }
	static StringProxy* _StringConversion_FormatXArgs(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs) { return C::FormatXArgs(formatString, argsCnt, args, argFuncs); }
	static Bool _StringConversion_ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) { return C::ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs); }
	static Int64 _StringConversion_ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) { return C::ScanParameterBasic(str, signedMode, processed, formatStatement, error); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance._StringConversion_FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance._StringConversion_FloatToString_1(value, charsBeforeComma, digitsAfterComma, exponent, fillChar, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance._StringConversion_AppendInt(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance._StringConversion_AppendUInt(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance._StringConversion_AppendInt_1(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement) -> void
{
	return MTable::_instance._StringConversion_AppendUInt_1(str, value, datatypeSize, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::MemorySizeToString(Int64 mem, Bool mebibytes) -> String
{
	return MTable::_instance._StringConversion_MemorySizeToString(mem, mebibytes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance._StringConversion_HexToString(value, prefix0x, leadingZeros, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance._StringConversion_HexToString_1(value, prefix0x, leadingZeros, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Float32>
{
	return MTable::_instance._StringConversion_ToFloat32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Float64>
{
	return MTable::_instance._StringConversion_ToFloat64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Int64>
{
	return MTable::_instance._StringConversion_ToInt64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<Int32>
{
	return MTable::_instance._StringConversion_ToInt32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<UInt64>
{
	return MTable::_instance._StringConversion_ToUInt64(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags) -> Result<UInt32>
{
	return MTable::_instance._StringConversion_ToUInt32(str, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::StringToFloat(const Block<const Utf32Char>& str, Int& processedChars) -> Result<Float64>
{
	return MTable::_instance._StringConversion_StringToFloat(str, processedChars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars) -> Result<UInt64>
{
	return MTable::_instance._StringConversion_StringToInteger(str, base, autodetect0x, signedMode, processedChars);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::GetLineEnd() -> const String&
{
	return MTable::_instance._StringConversion_GetLineEnd();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::GetLineEndC() -> const CString&
{
	return MTable::_instance._StringConversion_GetLineEndC();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::FormatXArgs(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs) -> StringProxy*
{
	return MTable::_instance._StringConversion_FormatXArgs(formatString, argsCnt, args, argFuncs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs) -> Bool
{
	return MTable::_instance._StringConversion_ScanStringXArgs(str, format, parsedCharacters, argsCnt, args, argFuncs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringConversion::ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error) -> Int64
{
	return MTable::_instance._StringConversion_ScanParameterBasic(str, signedMode, processed, formatStatement, error);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

