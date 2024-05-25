
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DllInterface::PrivateGetCppName() { return "maxon::DllRef"; }

struct DllInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(DllInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const DllInterface* object);
	PRIVATE_MAXON_SF_POINTER(DllInterface_LoadDll, LoadDll, MAXON_EXPAND_VA_ARGS, (Result<DllRef>), const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags);
	PRIVATE_MAXON_SF_POINTER(DllInterface_GetModule, GetModule, MAXON_EXPAND_VA_ARGS, (Result<DllRef>), const void* handle, UInt processId);
	PRIVATE_MAXON_SF_POINTER(DllInterface_AddDllPath, AddDllPath, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& dllDirectory);
	PRIVATE_MAXON_SF_POINTER(DllInterface_RemoveDllPath, RemoveDllPath, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& dllDirectory);
	PRIVATE_MAXON_SF_POINTER(DllInterface_GetLoadedDlls, GetLoadedDlls, MAXON_EXPAND_VA_ARGS, (Result<void>), const ValueReceiver<const DllRef&>& dlls);
	PRIVATE_MAXON_MF_POINTER(DllInterface_Unload, Unload, false, DllInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(DllInterface_Release, Release, false, DllInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(DllInterface_FindSymbolPointer, FindSymbolPointer, false, DllInterface, const, (Result<void*>), const CString& symbol);
	PRIVATE_MAXON_MF_POINTER(DllInterface_GetBinary, GetBinary, false, DllInterface, const, (Result<Binary*>));
	PRIVATE_MAXON_MF_POINTER(DllInterface_UpdateSymbolData, UpdateSymbolData, false, DllInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(DllInterface_GetPath, GetPath, false, DllInterface, const, (Result<Url>));
	template <typename IMPL> void Init()
	{
		DllInterface_Free = DllInterface_Free_GetPtr<IMPL>(true);
		DllInterface_LoadDll = DllInterface_LoadDll_GetPtr<IMPL>(true);
		DllInterface_GetModule = DllInterface_GetModule_GetPtr<IMPL>(true);
		DllInterface_AddDllPath = DllInterface_AddDllPath_GetPtr<IMPL>(true);
		DllInterface_RemoveDllPath = DllInterface_RemoveDllPath_GetPtr<IMPL>(true);
		DllInterface_GetLoadedDlls = DllInterface_GetLoadedDlls_GetPtr<IMPL>(true);
		DllInterface_Unload = DllInterface_Unload_GetPtr<IMPL>(0, true).first;
		DllInterface_Release = DllInterface_Release_GetPtr<IMPL>(0, true).first;
		DllInterface_FindSymbolPointer = DllInterface_FindSymbolPointer_GetPtr<IMPL>(0, true).first;
		DllInterface_GetBinary = DllInterface_GetBinary_GetPtr<IMPL>(0, true).first;
		DllInterface_UpdateSymbolData = DllInterface_UpdateSymbolData_GetPtr<IMPL>(0, true).first;
		DllInterface_GetPath = DllInterface_GetPath_GetPtr<IMPL>(0, true).first;
	}
};

struct DllInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void DllInterface_Free(const DllInterface* object) { return S::Free(object); }
		static Result<DllRef> DllInterface_LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) { return S::LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags); }
		static Result<DllRef> DllInterface_GetModule(const void* handle, UInt processId) { return S::GetModule(handle, processId); }
		static Result<void> DllInterface_AddDllPath(const Url& dllDirectory) { return S::AddDllPath(dllDirectory); }
		static Result<void> DllInterface_RemoveDllPath(const Url& dllDirectory) { return S::RemoveDllPath(dllDirectory); }
		static Result<void> DllInterface_GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) { return S::GetLoadedDlls(dlls); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_Unload, DllInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(DllInterface))->Unload(); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_Release, DllInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(DllInterface))->Release(); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_FindSymbolPointer, DllInterface, const, (Result<void*>), const CString& symbol) { return S::Get(PRIVATE_MAXON_MF_THIS(const DllInterface))->FindSymbolPointer(symbol); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_GetBinary, DllInterface, const, (Result<Binary*>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const DllInterface))->GetBinary(); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_UpdateSymbolData, DllInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(DllInterface))->UpdateSymbolData(); }
		PRIVATE_MAXON_MF_WRAPPER(DllInterface_GetPath, DllInterface, const, (Result<Url>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const DllInterface))->GetPath(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Free(const DllInterface* object) -> void
{
	return MTable::_instance.DllInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) -> Result<DllRef>
{
	return MTable::_instance.DllInterface_LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetModule(const void* handle, UInt processId) -> Result<DllRef>
{
	return MTable::_instance.DllInterface_GetModule(handle, processId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::AddDllPath(const Url& dllDirectory) -> Result<void>
{
	return MTable::_instance.DllInterface_AddDllPath(dllDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::RemoveDllPath(const Url& dllDirectory) -> Result<void>
{
	return MTable::_instance.DllInterface_RemoveDllPath(dllDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) -> Result<void>
{
	return MTable::_instance.DllInterface_GetLoadedDlls(dlls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Unload() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_Unload);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Release() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_Release);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::FindSymbolPointer(const CString& symbol) const -> Result<void*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_FindSymbolPointer, symbol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetBinary() const -> Result<Binary*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_GetBinary);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::UpdateSymbolData() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_UpdateSymbolData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetPath() const -> Result<Url>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DllInterface_GetPath);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) -> Result<DllRef>
{
	return (MTable::_instance.DllInterface_LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::GetModule(const void* handle, UInt processId) -> Result<DllRef>
{
	return (MTable::_instance.DllInterface_GetModule(handle, processId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::AddDllPath(const Url& dllDirectory) -> Result<void>
{
	return (MTable::_instance.DllInterface_AddDllPath(dllDirectory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::RemoveDllPath(const Url& dllDirectory) -> Result<void>
{
	return (MTable::_instance.DllInterface_RemoveDllPath(dllDirectory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) -> Result<void>
{
	return (MTable::_instance.DllInterface_GetLoadedDlls(dlls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::Fn<S>::Unload() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_Unload));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::Fn<S>::Release() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, OK) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_Release));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::FindSymbolPointer(const CString& symbol) const -> Result<void*>
{
	HXXRETURN0(Result<void*>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_FindSymbolPointer, symbol));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::FindSymbol(const CString& symbol) const -> Result<T>
{
	HXXRETURN0(Result<T>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->FindSymbol<T>(symbol));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::GetBinary() const -> Result<Binary*>
{
	HXXRETURN0(Result<Binary*>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_GetBinary));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::Fn<S>::UpdateSymbolData() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_UpdateSymbolData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Hxx1::ConstFn<S>::GetPath() const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DllInterface_GetPath));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dll)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DllInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DllInterface() { new (s_ui_maxon_DllInterface) maxon::EntityUse(DllInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dll.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DllInterface(DllInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dll.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

