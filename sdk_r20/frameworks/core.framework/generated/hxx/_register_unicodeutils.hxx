#if 1
namespace maxon
{
	namespace enum22 { enum class NORMALIZATION
	{
		NFC = 1,          // Standard composition form
		NFD = 2,          // Standard decomposition form
		NKDC = 3,         // Not imeplemented yet
		NFKD = 4,         // Not imeplemented yet
		NFD_HFS = 5       // special for HFS+
	} ; }
	maxon::String PrivateToString_NORMALIZATION22(std::underlying_type<enum22::NORMALIZATION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum22::NORMALIZATION::NFC, (maxon::UInt64) enum22::NORMALIZATION::NFD, (maxon::UInt64) enum22::NORMALIZATION::NKDC, (maxon::UInt64) enum22::NORMALIZATION::NFKD, (maxon::UInt64) enum22::NORMALIZATION::NFD_HFS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NORMALIZATION", SIZEOF(x), false, values, "NFC\0NFD\0NKDC\0NFKD\0NFD_HFS\0", fmt);
	}
	const maxon::Char* const UnicodeUtils::MTable::_ids = 
		"DecomposeStringHfs@fa6a9fe074ce2040\0" // DecomposeStringHfs(const String& str)
		"DecomposeString@fa6a9fe074ce2040\0" // DecomposeString(const String& str)
		"GetUnicodeVersion@22c6ed80851\0" // GetUnicodeVersion()
		"NormalizeString@64764e37f48b4b8f\0" // NormalizeString(NORMALIZATION form, const String& str)
		"UniCharDecomposition@7a1880ccc796ebd6\0" // UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp)
		"UniCharHfsDecomposition@a24e95fd960667a7\0" // UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp)
		"UniCodeCompare@e21cb774b450cad8\0" // UniCodeCompare(Utf32Char a, Utf32Char b)
		"UpperCase@9fd21dde8d1f254e\0" // UpperCase(Utf32Char chr)
		"TitleCase@9fd21dde8d1f254e\0" // TitleCase(Utf32Char chr)
		"LowerCase@9fd21dde8d1f254e\0" // LowerCase(Utf32Char chr)
	"";
	class UnicodeUtils::Unresolved : public UnicodeUtils
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
		static Utf32Char UpperCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::UpperCase(chr); return 0;}
		static Utf32Char TitleCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::TitleCase(chr); return 0;}
		static Utf32Char LowerCase(Utf32Char chr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnicodeUtils::LowerCase(chr); return 0;}
	};
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
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UnicodeUtils::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnicodeUtils_DecomposeStringHfs = &Wrapper<Unresolved>::_UnicodeUtils_DecomposeStringHfs;
	#else
		tbl->_UnicodeUtils_DecomposeStringHfs = &Wrapper<Unresolved>::_UnicodeUtils_DecomposeStringHfs;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnicodeUtils_DecomposeString = &Wrapper<Unresolved>::_UnicodeUtils_DecomposeString;
	#else
		tbl->_UnicodeUtils_DecomposeString = &Wrapper<Unresolved>::_UnicodeUtils_DecomposeString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnicodeUtils_GetUnicodeVersion = &Wrapper<Unresolved>::_UnicodeUtils_GetUnicodeVersion;
	#else
		tbl->_UnicodeUtils_GetUnicodeVersion = &Wrapper<Unresolved>::_UnicodeUtils_GetUnicodeVersion;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnicodeUtils_NormalizeString = &Wrapper<Unresolved>::_UnicodeUtils_NormalizeString;
	#else
		tbl->_UnicodeUtils_NormalizeString = &Wrapper<Unresolved>::_UnicodeUtils_NormalizeString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UnicodeUtils_UniCharDecomposition = &Wrapper<Unresolved>::_UnicodeUtils_UniCharDecomposition;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UnicodeUtils_UniCharHfsDecomposition = &Wrapper<Unresolved>::_UnicodeUtils_UniCharHfsDecomposition;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnicodeUtils_UniCodeCompare = &Wrapper<Unresolved>::_UnicodeUtils_UniCodeCompare;
	#else
		tbl->_UnicodeUtils_UniCodeCompare = &Wrapper<Unresolved>::_UnicodeUtils_UniCodeCompare;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UnicodeUtils_UpperCase = &Wrapper<Unresolved>::_UnicodeUtils_UpperCase;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UnicodeUtils_TitleCase = &Wrapper<Unresolved>::_UnicodeUtils_TitleCase;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UnicodeUtils_LowerCase = &Wrapper<Unresolved>::_UnicodeUtils_LowerCase;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UnicodeUtils, "net.maxon.interface.unicodeutils", nullptr);
	template <typename DUMMY> maxon::Int UnicodeUtils::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_unicodeutils(0
	| maxon::UnicodeUtils::PrivateInstantiateNullValueHelper<maxon::Int>()
);
