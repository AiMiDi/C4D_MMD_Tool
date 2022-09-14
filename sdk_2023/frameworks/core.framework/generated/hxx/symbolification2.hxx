
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* SymbolificationInterface::PrivateGetCppName() { return "maxon::SymbolificationRef"; }

struct SymbolificationInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(SymbolificationInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const SymbolificationInterface* object);
	PRIVATE_MAXON_SF_POINTER(SymbolificationInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (SymbolificationInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(SymbolificationInterface_Init, Init, false, SymbolificationInterface,, (Result<void>), const Url& symbolFile, const String& architecture);
	PRIVATE_MAXON_MF_POINTER(SymbolificationInterface_FindSymbol, FindSymbol, false, SymbolificationInterface,, (Result<void>), UInt64 addr, String& file, Int& line, String& function);
	template <typename IMPL> void Init()
	{
		SymbolificationInterface_Free = SymbolificationInterface_Free_GetPtr<IMPL>(true);
		SymbolificationInterface_Alloc = SymbolificationInterface_Alloc_GetPtr<IMPL>(true);
		SymbolificationInterface_Init = SymbolificationInterface_Init_GetPtr<IMPL>(0, true).first;
		SymbolificationInterface_FindSymbol = SymbolificationInterface_FindSymbol_GetPtr<IMPL>(0, true).first;
	}
};

struct SymbolificationInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void SymbolificationInterface_Free(const SymbolificationInterface* object) { return C::Free(object); }
		static SymbolificationInterface* SymbolificationInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(SymbolificationInterface_Init, SymbolificationInterface,, (Result<void>), const Url& symbolFile, const String& architecture) { return C::Get(PRIVATE_MAXON_MF_THIS(SymbolificationInterface))->Init(symbolFile, architecture); }
		PRIVATE_MAXON_MF_WRAPPER(SymbolificationInterface_FindSymbol, SymbolificationInterface,, (Result<void>), UInt64 addr, String& file, Int& line, String& function) { return C::Get(PRIVATE_MAXON_MF_THIS(SymbolificationInterface))->FindSymbol(addr, file, line, function); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Free(const SymbolificationInterface* object) -> void
{
	return MTable::_instance.SymbolificationInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Alloc(const maxon::SourceLocation& allocLocation) -> SymbolificationInterface*
{
	return MTable::_instance.SymbolificationInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Init(const Url& symbolFile, const String& architecture) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SymbolificationInterface_Init, symbolFile, architecture);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::FindSymbol(UInt64 addr, String& file, Int& line, String& function) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SymbolificationInterface_FindSymbol, addr, file, line, function);
}

auto SymbolificationInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<SymbolificationRef>
{
	SymbolificationInterface* res_ = SymbolificationInterface::Alloc(MAXON_SOURCE_LOCATION);
	return SymbolificationRef(maxon::ForwardResultPtr<SymbolificationInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Hxx1::Fn<S>::Init(const Url& symbolFile, const String& architecture) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SymbolificationInterface_Init, symbolFile, architecture));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Hxx1::Fn<S>::FindSymbol(UInt64 addr, String& file, Int& line, String& function) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SymbolificationInterface_FindSymbol, addr, file, line, function));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_symbolification)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SymbolificationInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SymbolificationInterface() { new (s_ui_maxon_SymbolificationInterface) maxon::EntityUse(SymbolificationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/symbolification.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SymbolificationInterface(SymbolificationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/symbolification.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

