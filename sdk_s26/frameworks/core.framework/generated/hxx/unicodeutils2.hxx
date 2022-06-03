
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* UnicodeUtils::PrivateGetCppName() { return nullptr; }

struct UnicodeUtils::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<String> (*UnicodeUtils_DecomposeStringHfs) (const String& str);
	Result<String> (*UnicodeUtils_DecomposeString) (const String& str);
	String (*UnicodeUtils_GetUnicodeVersion) ();
	Result<String> (*UnicodeUtils_NormalizeString) (NORMALIZATION form, const String& str);
	Bool (*UnicodeUtils_UniCharDecomposition) (Utf32Char chr, DecompositionArray& res_decomp);
	Bool (*UnicodeUtils_UniCharHfsDecomposition) (Utf16Char chr, DecompositionHfsArray& res_decomp);
	COMPARERESULT (*UnicodeUtils_UniCodeCompare) (Utf32Char a, Utf32Char b);
	CHARACTERTYPE (*UnicodeUtils_GetCharacterType) (Utf32Char chr);
	Utf32Char (*UnicodeUtils_UpperCase) (Utf32Char chr);
	Utf32Char (*UnicodeUtils_TitleCase) (Utf32Char chr);
	Utf32Char (*UnicodeUtils_LowerCase) (Utf32Char chr);
	template <typename IMPL> void Init()
	{
		UnicodeUtils_DecomposeStringHfs = &IMPL::UnicodeUtils_DecomposeStringHfs;
		UnicodeUtils_DecomposeString = &IMPL::UnicodeUtils_DecomposeString;
		UnicodeUtils_GetUnicodeVersion = &IMPL::UnicodeUtils_GetUnicodeVersion;
		UnicodeUtils_NormalizeString = &IMPL::UnicodeUtils_NormalizeString;
		UnicodeUtils_UniCharDecomposition = &IMPL::UnicodeUtils_UniCharDecomposition;
		UnicodeUtils_UniCharHfsDecomposition = &IMPL::UnicodeUtils_UniCharHfsDecomposition;
		UnicodeUtils_UniCodeCompare = &IMPL::UnicodeUtils_UniCodeCompare;
		UnicodeUtils_GetCharacterType = &IMPL::UnicodeUtils_GetCharacterType;
		UnicodeUtils_UpperCase = &IMPL::UnicodeUtils_UpperCase;
		UnicodeUtils_TitleCase = &IMPL::UnicodeUtils_TitleCase;
		UnicodeUtils_LowerCase = &IMPL::UnicodeUtils_LowerCase;
	}
};

struct UnicodeUtils::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<String> UnicodeUtils_DecomposeStringHfs(const String& str) { return C::DecomposeStringHfs(str); }
		static Result<String> UnicodeUtils_DecomposeString(const String& str) { return C::DecomposeString(str); }
		static String UnicodeUtils_GetUnicodeVersion() { return C::GetUnicodeVersion(); }
		static Result<String> UnicodeUtils_NormalizeString(NORMALIZATION form, const String& str) { return C::NormalizeString(form, str); }
		static Bool UnicodeUtils_UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) { return C::UniCharDecomposition(chr, res_decomp); }
		static Bool UnicodeUtils_UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) { return C::UniCharHfsDecomposition(chr, res_decomp); }
		static COMPARERESULT UnicodeUtils_UniCodeCompare(Utf32Char a, Utf32Char b) { return C::UniCodeCompare(a, b); }
		static CHARACTERTYPE UnicodeUtils_GetCharacterType(Utf32Char chr) { return C::GetCharacterType(chr); }
		static Utf32Char UnicodeUtils_UpperCase(Utf32Char chr) { return C::UpperCase(chr); }
		static Utf32Char UnicodeUtils_TitleCase(Utf32Char chr) { return C::TitleCase(chr); }
		static Utf32Char UnicodeUtils_LowerCase(Utf32Char chr) { return C::LowerCase(chr); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::DecomposeStringHfs(const String& str) -> Result<String>
{
	return MTable::_instance.UnicodeUtils_DecomposeStringHfs(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::DecomposeString(const String& str) -> Result<String>
{
	return MTable::_instance.UnicodeUtils_DecomposeString(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::GetUnicodeVersion() -> String
{
	return MTable::_instance.UnicodeUtils_GetUnicodeVersion();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::NormalizeString(NORMALIZATION form, const String& str) -> Result<String>
{
	return MTable::_instance.UnicodeUtils_NormalizeString(form, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) -> Bool
{
	return MTable::_instance.UnicodeUtils_UniCharDecomposition(chr, res_decomp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) -> Bool
{
	return MTable::_instance.UnicodeUtils_UniCharHfsDecomposition(chr, res_decomp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UniCodeCompare(Utf32Char a, Utf32Char b) -> COMPARERESULT
{
	return MTable::_instance.UnicodeUtils_UniCodeCompare(a, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::GetCharacterType(Utf32Char chr) -> CHARACTERTYPE
{
	return MTable::_instance.UnicodeUtils_GetCharacterType(chr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::UpperCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance.UnicodeUtils_UpperCase(chr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::TitleCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance.UnicodeUtils_TitleCase(chr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnicodeUtils::LowerCase(Utf32Char chr) -> Utf32Char
{
	return MTable::_instance.UnicodeUtils_LowerCase(chr);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_unicodeutils)
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

