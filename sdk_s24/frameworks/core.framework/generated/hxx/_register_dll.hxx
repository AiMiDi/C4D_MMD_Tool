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
		static Result<DllRef> LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DllRef> GetModule(const void* handle, UInt processId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::GetModule(handle, processId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddDllPath(const Url& dllDirectory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::AddDllPath(dllDirectory); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> RemoveDllPath(const Url& dllDirectory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::RemoveDllPath(dllDirectory); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DllInterface::GetLoadedDlls(dlls); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Unload() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->Unload(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Release() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->Release(); return OK;}
		Result<void*> FindSymbolPointer(const CString& symbol) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->FindSymbolPointer(symbol); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Binary*> GetBinary() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->GetBinary(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> UpdateSymbolData() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DllInterface*) this)->UpdateSymbolData(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Url> GetPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DllInterface*) this)->GetPath(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DllInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<DllRef>>::value,
		maxon::details::NullReturnType<Result<DllRef>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void*>>::value,
		maxon::details::NullReturnType<Result<Binary*>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DllInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DllInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DllRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_LoadDll = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_LoadDll;
		#else
		tbl->_DllInterface_LoadDll = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_LoadDll;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DllRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_GetModule = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetModule;
		#else
		tbl->_DllInterface_GetModule = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetModule;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_AddDllPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_AddDllPath;
		#else
		tbl->_DllInterface_AddDllPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_AddDllPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_RemoveDllPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_RemoveDllPath;
		#else
		tbl->_DllInterface_RemoveDllPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_RemoveDllPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_GetLoadedDlls = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetLoadedDlls;
		#else
		tbl->_DllInterface_GetLoadedDlls = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetLoadedDlls;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_Unload = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_Unload;
		#else
		tbl->_DllInterface_Unload = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_Unload;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_Release = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_Release;
		#else
		tbl->_DllInterface_Release = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_Release;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_FindSymbolPointer = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_FindSymbolPointer;
		#else
		tbl->_DllInterface_FindSymbolPointer = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_FindSymbolPointer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Binary*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_GetBinary = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetBinary;
		#else
		tbl->_DllInterface_GetBinary = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetBinary;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_UpdateSymbolData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_UpdateSymbolData;
		#else
		tbl->_DllInterface_UpdateSymbolData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_UpdateSymbolData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DllInterface_GetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetPath;
		#else
		tbl->_DllInterface_GetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_DllInterface_GetPath;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DllInterface, "net.maxon.interface.dll", nullptr);
}
#endif
