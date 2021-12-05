#if 1
namespace maxon
{
	const maxon::Char* const SymbolificationInterface::MTable::_ids = 
		"Free@5c2f04fb2fde8898\0" // void Free(const SymbolificationInterface* object)
		"Alloc@a2cfc23a47e755a7\0" // SymbolificationInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@43bb3f719247d698\0" // Result<void> Init(const Url& symbolFile, const String& architecture)
		"FindSymbol@8319a74d946d13d3\0" // Result<void> FindSymbol(UInt64 addr, String& file, Int& line, String& function)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SymbolificationInterface::Hxx2::Unresolved : public SymbolificationInterface
	{
	public:
		static const Unresolved* Get(const SymbolificationInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SymbolificationInterface* o) { return (Unresolved*) o; }
		static void Free(const SymbolificationInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SymbolificationInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static SymbolificationInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SymbolificationInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Init(const Url& symbolFile, const String& architecture) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SymbolificationInterface*) this)->Init(symbolFile, architecture); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> FindSymbol(UInt64 addr, String& file, Int& line, String& function) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SymbolificationInterface*) this)->FindSymbol(addr, file, line, function); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE SymbolificationInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<SymbolificationInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SymbolificationInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SymbolificationInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SymbolificationInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SymbolificationInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_Init;
		#else
		tbl->_SymbolificationInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SymbolificationInterface_FindSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_FindSymbol;
		#else
		tbl->_SymbolificationInterface_FindSymbol = &Hxx2::Wrapper<Hxx2::Unresolved>::_SymbolificationInterface_FindSymbol;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SymbolificationInterface, "net.maxon.interface.symbolification", nullptr);
}
#endif
