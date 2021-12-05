
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct UnicodeUtils::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<String> (*_UnicodeUtils_DecomposeStringHfs) (const String& str);
	Result<String> (*_UnicodeUtils_DecomposeString) (const String& str);
	String (*_UnicodeUtils_GetUnicodeVersion) ();
	Result<String> (*_UnicodeUtils_NormalizeString) (NORMALIZATION form, const String& str);
	Bool (*_UnicodeUtils_UniCharDecomposition) (Utf32Char chr, DecompositionArray& res_decomp);
	Bool (*_UnicodeUtils_UniCharHfsDecomposition) (Utf16Char chr, DecompositionHfsArray& res_decomp);
	COMPARERESULT (*_UnicodeUtils_UniCodeCompare) (Utf32Char a, Utf32Char b);
	Utf32Char (*_UnicodeUtils_UpperCase) (Utf32Char chr);
	Utf32Char (*_UnicodeUtils_TitleCase) (Utf32Char chr);
	Utf32Char (*_UnicodeUtils_LowerCase) (Utf32Char chr);
	template <typename IMPL> void Init()
	{
		_UnicodeUtils_DecomposeStringHfs = &IMPL::_UnicodeUtils_DecomposeStringHfs;
		_UnicodeUtils_DecomposeString = &IMPL::_UnicodeUtils_DecomposeString;
		_UnicodeUtils_GetUnicodeVersion = &IMPL::_UnicodeUtils_GetUnicodeVersion;
		_UnicodeUtils_NormalizeString = &IMPL::_UnicodeUtils_NormalizeString;
		_UnicodeUtils_UniCharDecomposition = &IMPL::_UnicodeUtils_UniCharDecomposition;
		_UnicodeUtils_UniCharHfsDecomposition = &IMPL::_UnicodeUtils_UniCharHfsDecomposition;
		_UnicodeUtils_UniCodeCompare = &IMPL::_UnicodeUtils_UniCodeCompare;
		_UnicodeUtils_UpperCase = &IMPL::_UnicodeUtils_UpperCase;
		_UnicodeUtils_TitleCase = &IMPL::_UnicodeUtils_TitleCase;
		_UnicodeUtils_LowerCase = &IMPL::_UnicodeUtils_LowerCase;
	}
};

struct UnicodeUtils::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<String> _UnicodeUtils_DecomposeStringHfs(const String& str) { return C::DecomposeStringHfs(str); }
	static Result<String> _UnicodeUtils_DecomposeString(const String& str) { return C::DecomposeString(str); }
	static String _UnicodeUtils_GetUnicodeVersion() { return C::GetUnicodeVersion(); }
	static Result<String> _UnicodeUtils_NormalizeString(NORMALIZATION form, const String& str) { return C::NormalizeString(form, str); }
	static Bool _UnicodeUtils_UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) { return C::UniCharDecomposition(chr, res_decomp); }
	static Bool _UnicodeUtils_UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) { return C::UniCharHfsDecomposition(chr, res_decomp); }
	static COMPARERESULT _UnicodeUtils_UniCodeCompare(Utf32Char a, Utf32Char b) { return C::UniCodeCompare(a, b); }
	static Utf32Char _UnicodeUtils_UpperCase(Utf32Char chr) { return C::UpperCase(chr); }
	static Utf32Char _UnicodeUtils_TitleCase(Utf32Char chr) { return C::TitleCase(chr); }
	static Utf32Char _UnicodeUtils_LowerCase(Utf32Char chr) { return C::LowerCase(chr); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::DecomposeStringHfs(const String& str) -> Result<String>
{
	return MTable::_instance._UnicodeUtils_DecomposeStringHfs(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::DecomposeString(const String& str) -> Result<String>
{
	return MTable::_instance._UnicodeUtils_DecomposeString(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::GetUnicodeVersion() -> String
{
	return MTable::_instance._UnicodeUtils_GetUnicodeVersion();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::NormalizeString(NORMALIZATION form, const String& str) -> Result<String>
{
	return MTable::_instance._UnicodeUtils_NormalizeString(form, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) -> Bool
{
	return MTable::_instance._UnicodeUtils_UniCharDecomposition(chr, res_decomp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) -> Bool
{
	return MTable::_instance._UnicodeUtils_UniCharHfsDecomposition(chr, res_decomp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCodeCompare(Utf32Char a, Utf32Char b) -> COMPARERESULT
{
	return MTable::_instance._UnicodeUtils_UniCodeCompare(a, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UpperCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance._UnicodeUtils_UpperCase(chr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::TitleCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance._UnicodeUtils_TitleCase(chr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::LowerCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance._UnicodeUtils_LowerCase(chr);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnicodeUtils); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnicodeUtils() { new (s_ui_maxon_UnicodeUtils) maxon::EntityUse(UnicodeUtils::_interface.GetReference(), &maxon::g_translationUnit, "maxon/unicodeutils.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnicodeUtils(UnicodeUtils::_interface.GetReference(), &maxon::g_translationUnit, "maxon/unicodeutils.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

