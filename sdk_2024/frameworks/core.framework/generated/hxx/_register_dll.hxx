#if 1
namespace maxon
{
	const maxon::Char* const DllInterface::MTable::_ids = 
		"Free@4d2ec1030bd9fba1\0" // void Free(const DllInterface* object)
		"LoadDll@fd61abad4e342b54\0" // Result<DllRef> LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags)
		"GetModule@c7a273d6b16e980\0" // Result<DllRef> GetModule(const void* handle, UInt processId)
		"AddDllPath@683e18fe1711316e\0" // Result<void> AddDllPath(const Url& dllDirectory)
		"RemoveDllPath@683e18fe1711316e\0" // Result<void> RemoveDllPath(const Url& dllDirectory)
		"GetLoadedDlls@5a77b521b3ce6f53\0" // Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls)
		"Unload@3008090429c5a175\0" // Result<void> Unload()
		"Release@3008090429c5a175\0" // Result<void> Release()
		"FindSymbolPointer@26dbb2de74b22346\0" // Result<void*> FindSymbolPointer(const CString& symbol) const
		"GetBinary@2b7fd8d51b1e5084\0" // Result<Binary*> GetBinary() const
		"UpdateSymbolData@3008090429c5a175\0" // Result<void> UpdateSymbolData()
		"GetPath@d2fb7b7fcfe4e778\0" // Result<Url> GetPath() const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DllInterface::Hxx2::Unresolved : public DllInterface
	{
	public:
		static const Unresolved* Get(const DllInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DllInterface* o) { return (Unresolved*) o; }
		static void Free(const DllInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DllInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<DllRef> LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags); return HXXRET1(UNRESOLVED);}
		static Result<DllRef> GetModule(const void* handle, UInt processId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::GetModule(handle, processId); return HXXRET1(UNRESOLVED);}
		static Result<void> AddDllPath(const Url& dllDirectory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::AddDllPath(dllDirectory); return HXXRET1(UNRESOLVED);}
		static Result<void> RemoveDllPath(const Url& dllDirectory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::RemoveDllPath(dllDirectory); return HXXRET1(UNRESOLVED);}
		static Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::GetLoadedDlls(dlls); return HXXRET1(UNRESOLVED);}
		Result<void> Unload() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->Unload(); return HXXRET1(UNRESOLVED);}
		Result<void> Release() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->Release(); return OK;}
		Result<void*> FindSymbolPointer(const CString& symbol) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->FindSymbolPointer(symbol); return HXXRET1(UNRESOLVED);}
		Result<Binary*> GetBinary() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->GetBinary(); return HXXRET1(UNRESOLVED);}
		Result<void> UpdateSymbolData() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->UpdateSymbolData(); return HXXRET1(UNRESOLVED);}
		Result<Url> GetPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->GetPath(); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE DllInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<Result<DllRef>>::value,
		maxon::details::UnresolvedReturnType<Result<DllRef>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void*>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Binary*>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Url>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DllInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DllInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DllRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_LoadDll = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_LoadDll), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_LoadDll);
		#else
		tbl->DllInterface_LoadDll = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_LoadDll), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_LoadDll);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DllRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_GetModule = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetModule), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetModule);
		#else
		tbl->DllInterface_GetModule = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetModule), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetModule);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_AddDllPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_AddDllPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_AddDllPath);
		#else
		tbl->DllInterface_AddDllPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_AddDllPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_AddDllPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_RemoveDllPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_RemoveDllPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_RemoveDllPath);
		#else
		tbl->DllInterface_RemoveDllPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_RemoveDllPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_RemoveDllPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_GetLoadedDlls = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetLoadedDlls), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetLoadedDlls);
		#else
		tbl->DllInterface_GetLoadedDlls = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetLoadedDlls), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetLoadedDlls);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_Unload = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_Unload), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_Unload);
		#else
		tbl->DllInterface_Unload = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_Unload), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_Unload);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_Release = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_Release), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_Release);
		#else
		tbl->DllInterface_Release = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_Release), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_Release);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_FindSymbolPointer = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_FindSymbolPointer), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_FindSymbolPointer);
		#else
		tbl->DllInterface_FindSymbolPointer = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_FindSymbolPointer), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_FindSymbolPointer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Binary*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_GetBinary = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetBinary), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetBinary);
		#else
		tbl->DllInterface_GetBinary = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetBinary), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetBinary);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_UpdateSymbolData = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_UpdateSymbolData), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_UpdateSymbolData);
		#else
		tbl->DllInterface_UpdateSymbolData = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_UpdateSymbolData), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_UpdateSymbolData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Url>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DllInterface_GetPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetPath);
		#else
		tbl->DllInterface_GetPath = PRIVATE_MAXON_MF_CAST(decltype(DllInterface_GetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::DllInterface_GetPath);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DllInterface, "net.maxon.interface.dll", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
