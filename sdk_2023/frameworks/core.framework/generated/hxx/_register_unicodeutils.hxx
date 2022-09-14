#if 1
namespace maxon
{
	namespace enum22
	{
		enum class NORMALIZATION
		{
			NFC = 1,          // Standard composition form
			NFD = 2,          // Standard decomposition form
			NKDC = 3,         // Not imeplemented yet
			NFKD = 4,         // Not imeplemented yet
			NFD_HFS = 5       // special for HFS+
		} ;
		static const maxon::UInt64 NORMALIZATION_values[] = {maxon::UInt64(enum22::NORMALIZATION::NFC), maxon::UInt64(enum22::NORMALIZATION::NFD), maxon::UInt64(enum22::NORMALIZATION::NKDC), maxon::UInt64(enum22::NORMALIZATION::NFKD), maxon::UInt64(enum22::NORMALIZATION::NFD_HFS)};
		static const maxon::EnumInfo NORMALIZATION_info{"NORMALIZATION", SIZEOF(NORMALIZATION), false, "NFC\0NFD\0NKDC\0NFKD\0NFD_HFS\0", NORMALIZATION_values, std::extent<decltype(NORMALIZATION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NORMALIZATION22(){ return enum22::NORMALIZATION_info; }
	namespace enum57
	{
		enum class CHARACTERTYPE : UChar
		{
			UNKNOWN = 0,
			LU, // Letter, Uppercase
			LL, // Letter, Lowercase
			LT, // Letter, Titlecase
			LM, // Letter, Modifier
			LO, // Letter, Other
			MN, // Mark, Nonspacing
			MC, // Mark, Spacing Combining
			ME, // Mark, Enclosing
			ND, // Number, Decimal Digit
			NL, // Number, Letter
			NO, // Number, Other
			PC, // Punctuation, Connector
			PD, // Punctuation, Dash
			PS, // Punctuation, Open
			PE, // Punctuation, Close
			PI, // Punctuation, Initial quote(may behave like Ps or Pe depending on usage)
			PF, // Punctuation, Final quote(may behave like Ps or Pe depending on usage)
			PO, // Punctuation, Other
			SM, // Symbol, Math
			SC, // Symbol, Currency
			SK, // Symbol, Modifier
			SO, // Symbol, Other
			ZS, // Separator, Space
			ZL, // Separator, Line
			ZP, // Separator, Paragraph
			CC, // Other, Control
			CF, // Other, Format
			CS, // Other, Surrogate
			CO, // Other, Private Use
			CN, // Other, Not Assigned(no characters in the file have this property)
		} ;
		static const maxon::UInt64 CHARACTERTYPE_values[] = {maxon::UInt64(enum57::CHARACTERTYPE::UNKNOWN), maxon::UInt64(enum57::CHARACTERTYPE::LU), maxon::UInt64(enum57::CHARACTERTYPE::LL), maxon::UInt64(enum57::CHARACTERTYPE::LT), maxon::UInt64(enum57::CHARACTERTYPE::LM), maxon::UInt64(enum57::CHARACTERTYPE::LO), maxon::UInt64(enum57::CHARACTERTYPE::MN), maxon::UInt64(enum57::CHARACTERTYPE::MC), maxon::UInt64(enum57::CHARACTERTYPE::ME), maxon::UInt64(enum57::CHARACTERTYPE::ND), maxon::UInt64(enum57::CHARACTERTYPE::NL), maxon::UInt64(enum57::CHARACTERTYPE::NO), maxon::UInt64(enum57::CHARACTERTYPE::PC), maxon::UInt64(enum57::CHARACTERTYPE::PD), maxon::UInt64(enum57::CHARACTERTYPE::PS), maxon::UInt64(enum57::CHARACTERTYPE::PE), maxon::UInt64(enum57::CHARACTERTYPE::PI), maxon::UInt64(enum57::CHARACTERTYPE::PF), maxon::UInt64(enum57::CHARACTERTYPE::PO), maxon::UInt64(enum57::CHARACTERTYPE::SM), maxon::UInt64(enum57::CHARACTERTYPE::SC), maxon::UInt64(enum57::CHARACTERTYPE::SK), maxon::UInt64(enum57::CHARACTERTYPE::SO), maxon::UInt64(enum57::CHARACTERTYPE::ZS), maxon::UInt64(enum57::CHARACTERTYPE::ZL), maxon::UInt64(enum57::CHARACTERTYPE::ZP), maxon::UInt64(enum57::CHARACTERTYPE::CC), maxon::UInt64(enum57::CHARACTERTYPE::CF), maxon::UInt64(enum57::CHARACTERTYPE::CS), maxon::UInt64(enum57::CHARACTERTYPE::CO), maxon::UInt64(enum57::CHARACTERTYPE::CN)};
		static const maxon::EnumInfo CHARACTERTYPE_info{"CHARACTERTYPE", SIZEOF(CHARACTERTYPE), false, "UNKNOWN\0LU\0LL\0LT\0LM\0LO\0MN\0MC\0ME\0ND\0NL\0NO\0PC\0PD\0PS\0PE\0PI\0PF\0PO\0SM\0SC\0SK\0SO\0ZS\0ZL\0ZP\0CC\0CF\0CS\0CO\0CN\0", CHARACTERTYPE_values, std::extent<decltype(CHARACTERTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CHARACTERTYPE57(){ return enum57::CHARACTERTYPE_info; }
	const maxon::Char* const UnicodeUtils::MTable::_ids = 
		"DecomposeStringHfs@71fd13a6a4e58539\0" // Result<String> DecomposeStringHfs(const String& str)
		"DecomposeString@71fd13a6a4e58539\0" // Result<String> DecomposeString(const String& str)
		"GetUnicodeVersion@b8f12df9fd0527a6\0" // String GetUnicodeVersion()
		"NormalizeString@da5dea0a24595cf2\0" // Result<String> NormalizeString(NORMALIZATION form, const String& str)
		"UniCharDecomposition@4ece237960dcb729\0" // Bool UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp)
		"UniCharHfsDecomposition@c2257b345c6f2260\0" // Bool UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp)
		"UniCodeCompare@45836c0cf38b9edb\0" // COMPARERESULT UniCodeCompare(Utf32Char a, Utf32Char b)
		"GetCharacterType@f8cb6749bb19c090\0" // CHARACTERTYPE GetCharacterType(Utf32Char chr)
		"UpperCase@59893fa258d96051\0" // Utf32Char UpperCase(Utf32Char chr)
		"TitleCase@59893fa258d96051\0" // Utf32Char TitleCase(Utf32Char chr)
		"LowerCase@59893fa258d96051\0" // Utf32Char LowerCase(Utf32Char chr)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UnicodeUtils::Hxx2::Unresolved : public UnicodeUtils
	{
	public:
		static const Unresolved* Get(const UnicodeUtils* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UnicodeUtils* o) { return (Unresolved*) o; }
		static Result<String> DecomposeStringHfs(const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UnicodeUtils::DecomposeStringHfs(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<String> DecomposeString(const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UnicodeUtils::DecomposeString(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static String GetUnicodeVersion() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::GetUnicodeVersion(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<String> NormalizeString(NORMALIZATION form, const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UnicodeUtils::NormalizeString(form, str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::UniCharDecomposition(chr, res_decomp); return maxon::PrivateLogNullptrError(false);}
		static Bool UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::UniCharHfsDecomposition(chr, res_decomp); return maxon::PrivateLogNullptrError(false);}
		static COMPARERESULT UniCodeCompare(Utf32Char a, Utf32Char b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::UniCodeCompare(a, b); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static CHARACTERTYPE GetCharacterType(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::GetCharacterType(chr); return maxon::PrivateIncompleteNullReturnValue<CHARACTERTYPE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Utf32Char UpperCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::UpperCase(chr); return 0;}
		static Utf32Char TitleCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::TitleCase(chr); return 0;}
		static Utf32Char LowerCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::LowerCase(chr); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UnicodeUtils::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<CHARACTERTYPE>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UnicodeUtils::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_DecomposeStringHfs = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_DecomposeStringHfs), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_DecomposeStringHfs);
		#else
		tbl->UnicodeUtils_DecomposeStringHfs = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_DecomposeStringHfs), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_DecomposeStringHfs);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_DecomposeString = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_DecomposeString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_DecomposeString);
		#else
		tbl->UnicodeUtils_DecomposeString = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_DecomposeString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_DecomposeString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_GetUnicodeVersion = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_GetUnicodeVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_GetUnicodeVersion);
		#else
		tbl->UnicodeUtils_GetUnicodeVersion = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_GetUnicodeVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_GetUnicodeVersion);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_NormalizeString = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_NormalizeString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_NormalizeString);
		#else
		tbl->UnicodeUtils_NormalizeString = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_NormalizeString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_NormalizeString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnicodeUtils_UniCharDecomposition = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_UniCharDecomposition), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_UniCharDecomposition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnicodeUtils_UniCharHfsDecomposition = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_UniCharHfsDecomposition), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_UniCharHfsDecomposition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_UniCodeCompare = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_UniCodeCompare), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_UniCodeCompare);
		#else
		tbl->UnicodeUtils_UniCodeCompare = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_UniCodeCompare), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_UniCodeCompare);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<CHARACTERTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnicodeUtils_GetCharacterType = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_GetCharacterType), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_GetCharacterType);
		#else
		tbl->UnicodeUtils_GetCharacterType = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_GetCharacterType), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_GetCharacterType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnicodeUtils_UpperCase = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_UpperCase), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_UpperCase);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnicodeUtils_TitleCase = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_TitleCase), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_TitleCase);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnicodeUtils_LowerCase = PRIVATE_MAXON_MF_CAST(decltype(UnicodeUtils_LowerCase), &Hxx2::Wrapper<Hxx2::Unresolved>::UnicodeUtils_LowerCase);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UnicodeUtils, "net.maxon.interface.unicodeutils", nullptr);
	template <typename DUMMY> maxon::Int UnicodeUtils::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<CHARACTERTYPE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_unicodeutils(0
	| maxon::UnicodeUtils::PrivateInstantiateNullValueHelper<maxon::Int>()
);
