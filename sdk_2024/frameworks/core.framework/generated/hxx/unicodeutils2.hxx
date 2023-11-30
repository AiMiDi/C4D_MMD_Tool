
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_DecomposeStringHfs, DecomposeStringHfs, MAXON_EXPAND_VA_ARGS, (Result<String>), const String& str);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_DecomposeString, DecomposeString, MAXON_EXPAND_VA_ARGS, (Result<String>), const String& str);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_GetUnicodeVersion, GetUnicodeVersion, MAXON_EXPAND_VA_ARGS, (String));
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_NormalizeString, NormalizeString, MAXON_EXPAND_VA_ARGS, (Result<String>), NORMALIZATION form, const String& str);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_UniCharDecomposition, UniCharDecomposition, MAXON_EXPAND_VA_ARGS, (Bool), Utf32Char chr, DecompositionArray& res_decomp);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_UniCharHfsDecomposition, UniCharHfsDecomposition, MAXON_EXPAND_VA_ARGS, (Bool), Utf16Char chr, DecompositionHfsArray& res_decomp);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_UniCodeCompare, UniCodeCompare, MAXON_EXPAND_VA_ARGS, (COMPARERESULT), Utf32Char a, Utf32Char b);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_GetCharacterType, GetCharacterType, MAXON_EXPAND_VA_ARGS, (CHARACTERTYPE), Utf32Char chr);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_UpperCase, UpperCase, MAXON_EXPAND_VA_ARGS, (Utf32Char), Utf32Char chr);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_TitleCase, TitleCase, MAXON_EXPAND_VA_ARGS, (Utf32Char), Utf32Char chr);
	PRIVATE_MAXON_SF_POINTER(UnicodeUtils_LowerCase, LowerCase, MAXON_EXPAND_VA_ARGS, (Utf32Char), Utf32Char chr);
	template <typename IMPL> void Init()
	{
		UnicodeUtils_DecomposeStringHfs = UnicodeUtils_DecomposeStringHfs_GetPtr<IMPL>(true);
		UnicodeUtils_DecomposeString = UnicodeUtils_DecomposeString_GetPtr<IMPL>(true);
		UnicodeUtils_GetUnicodeVersion = UnicodeUtils_GetUnicodeVersion_GetPtr<IMPL>(true);
		UnicodeUtils_NormalizeString = UnicodeUtils_NormalizeString_GetPtr<IMPL>(true);
		UnicodeUtils_UniCharDecomposition = UnicodeUtils_UniCharDecomposition_GetPtr<IMPL>(true);
		UnicodeUtils_UniCharHfsDecomposition = UnicodeUtils_UniCharHfsDecomposition_GetPtr<IMPL>(true);
		UnicodeUtils_UniCodeCompare = UnicodeUtils_UniCodeCompare_GetPtr<IMPL>(true);
		UnicodeUtils_GetCharacterType = UnicodeUtils_GetCharacterType_GetPtr<IMPL>(true);
		UnicodeUtils_UpperCase = UnicodeUtils_UpperCase_GetPtr<IMPL>(true);
		UnicodeUtils_TitleCase = UnicodeUtils_TitleCase_GetPtr<IMPL>(true);
		UnicodeUtils_LowerCase = UnicodeUtils_LowerCase_GetPtr<IMPL>(true);
	}
};

struct UnicodeUtils::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<String> UnicodeUtils_DecomposeStringHfs(const String& str) { return S::DecomposeStringHfs(str); }
		static Result<String> UnicodeUtils_DecomposeString(const String& str) { return S::DecomposeString(str); }
		static String UnicodeUtils_GetUnicodeVersion() { return S::GetUnicodeVersion(); }
		static Result<String> UnicodeUtils_NormalizeString(NORMALIZATION form, const String& str) { return S::NormalizeString(form, str); }
		static Bool UnicodeUtils_UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) { return S::UniCharDecomposition(chr, res_decomp); }
		static Bool UnicodeUtils_UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) { return S::UniCharHfsDecomposition(chr, res_decomp); }
		static COMPARERESULT UnicodeUtils_UniCodeCompare(Utf32Char a, Utf32Char b) { return S::UniCodeCompare(a, b); }
		static CHARACTERTYPE UnicodeUtils_GetCharacterType(Utf32Char chr) { return S::GetCharacterType(chr); }
		static Utf32Char UnicodeUtils_UpperCase(Utf32Char chr) { return S::UpperCase(chr); }
		static Utf32Char UnicodeUtils_TitleCase(Utf32Char chr) { return S::TitleCase(chr); }
		static Utf32Char UnicodeUtils_LowerCase(Utf32Char chr) { return S::LowerCase(chr); }
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

