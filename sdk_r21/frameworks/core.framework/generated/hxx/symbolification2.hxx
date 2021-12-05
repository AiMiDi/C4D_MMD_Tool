
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct SymbolificationInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_SymbolificationInterface_Free) (const SymbolificationInterface* object);
	SymbolificationInterface* (*_SymbolificationInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_SymbolificationInterface_Init) (SymbolificationInterface* this_, const Url& symbolFile, const String& architecture);
	Result<void> (*_SymbolificationInterface_FindSymbol) (SymbolificationInterface* this_, UInt64 addr, String& file, Int& line, String& function);
	template <typename IMPL> void Init()
	{
		_SymbolificationInterface_Free = &IMPL::_SymbolificationInterface_Free;
		_SymbolificationInterface_Alloc = &IMPL::_SymbolificationInterface_Alloc;
		_SymbolificationInterface_Init = &IMPL::_SymbolificationInterface_Init;
		_SymbolificationInterface_FindSymbol = &IMPL::_SymbolificationInterface_FindSymbol;
	}
};

struct SymbolificationInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _SymbolificationInterface_Free(const SymbolificationInterface* object) { return C::Free(object); }
	static SymbolificationInterface* _SymbolificationInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _SymbolificationInterface_Init(SymbolificationInterface* this_, const Url& symbolFile, const String& architecture) { return ((C*) this_)->Init(symbolFile, architecture); }
	static Result<void> _SymbolificationInterface_FindSymbol(SymbolificationInterface* this_, UInt64 addr, String& file, Int& line, String& function) { return ((C*) this_)->FindSymbol(addr, file, line, function); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Free(const SymbolificationInterface* object) -> void
{
	return MTable::_instance._SymbolificationInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Alloc(const maxon::SourceLocation& allocLocation) -> SymbolificationInterface*
{
	return MTable::_instance._SymbolificationInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Init(const Url& symbolFile, const String& architecture) -> Result<void>
{
	return MTable::_instance._SymbolificationInterface_Init(this, symbolFile, architecture);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::FindSymbol(UInt64 addr, String& file, Int& line, String& function) -> Result<void>
{
	return MTable::_instance._SymbolificationInterface_FindSymbol(this, addr, file, line, function);
}

auto SymbolificationInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<SymbolificationRef>
{
	SymbolificationInterface* res_ = SymbolificationInterface::Alloc(MAXON_SOURCE_LOCATION);
	return SymbolificationRef(maxon::ForwardResultPtr<SymbolificationInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const Url& symbolFile, const String& architecture) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._SymbolificationInterface_Init(o_, symbolFile, architecture));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::Hxx1::ReferenceFunctionsImpl<S>::FindSymbol(UInt64 addr, String& file, Int& line, String& function) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._SymbolificationInterface_FindSymbol(o_, addr, file, line, function));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

