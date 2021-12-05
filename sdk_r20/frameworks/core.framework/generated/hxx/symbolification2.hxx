
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_SymbolificationInterface_Free = &IMPL::_SymbolificationInterface_Free;
		tbl->_SymbolificationInterface_Alloc = &IMPL::_SymbolificationInterface_Alloc;
		tbl->_SymbolificationInterface_Init = &IMPL::_SymbolificationInterface_Init;
		tbl->_SymbolificationInterface_FindSymbol = &IMPL::_SymbolificationInterface_FindSymbol;
	}
};

template <typename C> class SymbolificationInterface::Wrapper
{
public:
	static void _SymbolificationInterface_Free(const SymbolificationInterface* object) { return C::Free(object); }
	static SymbolificationInterface* _SymbolificationInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static Result<void> _SymbolificationInterface_Init(SymbolificationInterface* this_, const Url& symbolFile, const String& architecture) { return ((C*) this_)->Init(symbolFile, architecture); }
	static Result<void> _SymbolificationInterface_FindSymbol(SymbolificationInterface* this_, UInt64 addr, String& file, Int& line, String& function) { return ((C*) this_)->FindSymbol(addr, file, line, function); }
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

auto SymbolificationInterface::Reference::Create() -> maxon::ResultMemT<SymbolificationRef>
{
	SymbolificationInterface* res_ = SymbolificationInterface::Alloc(MAXON_SOURCE_LOCATION);
	return SymbolificationRef(maxon::ForwardResultPtr<SymbolificationInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::ReferenceFunctionsImpl<S>::Init(const Url& symbolFile, const String& architecture) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._SymbolificationInterface_Init(o_, symbolFile, architecture));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SymbolificationInterface::ReferenceFunctionsImpl<S>::FindSymbol(UInt64 addr, String& file, Int& line, String& function) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SymbolificationInterface* o_ = (SymbolificationInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._SymbolificationInterface_FindSymbol(o_, addr, file, line, function));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_SymbolificationInterface(SymbolificationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/symbolification.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

