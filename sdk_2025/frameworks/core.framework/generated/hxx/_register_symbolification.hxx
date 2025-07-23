#if 1
namespace maxon
{
	const maxon::Char* const SymbolificationInterface::MTable::_ids = 
		"Free@addc34927cf1404d\0" // void Free(const SymbolificationInterface* object)
		"Alloc@b9c7690074995f1e\0" // SymbolificationInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@97e00d0cf19ccaab\0" // Result<void> Init(const Url& symbolFile, const String& architecture)
		"FindSymbol@2f99579632b1fc36\0" // Result<void> FindSymbol(UInt64 addr, String& file, Int& line, String& function)
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
		Result<void> Init(const Url& symbolFile, const String& architecture) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SymbolificationInterface*) this)->Init(symbolFile, architecture); return HXXRET1(UNRESOLVED);}
		Result<void> FindSymbol(UInt64 addr, String& file, Int& line, String& function) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SymbolificationInterface*) this)->FindSymbol(addr, file, line, function); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE SymbolificationInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<SymbolificationInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SymbolificationInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SymbolificationInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SymbolificationInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SymbolificationInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_Init);
		#else
		tbl->SymbolificationInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SymbolificationInterface_FindSymbol = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_FindSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_FindSymbol);
		#else
		tbl->SymbolificationInterface_FindSymbol = PRIVATE_MAXON_MF_CAST(decltype(SymbolificationInterface_FindSymbol), &Hxx2::Wrapper<Hxx2::Unresolved>::SymbolificationInterface_FindSymbol);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SymbolificationInterface, "net.maxon.interface.symbolification", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
