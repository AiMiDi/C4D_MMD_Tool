
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DllInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_DllInterface_Free) (const DllInterface* object);
	Result<DllRef> (*_DllInterface_LoadDll) (const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags);
	Result<DllRef> (*_DllInterface_GetModule) (const void* handle, UInt processId);
	Result<void> (*_DllInterface_AddDllPath) (const Url& dllDirectory);
	Result<void> (*_DllInterface_RemoveDllPath) (const Url& dllDirectory);
	Result<void> (*_DllInterface_GetLoadedDlls) (const ValueReceiver<const DllRef&>& dlls);
	Result<void> (*_DllInterface_Unload) (DllInterface* this_);
	Result<void> (*_DllInterface_Release) (DllInterface* this_);
	Result<void*> (*_DllInterface_FindSymbolPointer) (const DllInterface* this_, const CString& symbol);
	Result<void> (*_DllInterface_UpdateSymbolData) (DllInterface* this_);
	Result<Url> (*_DllInterface_GetPath) (const DllInterface* this_);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DllInterface_Free = &IMPL::_DllInterface_Free;
		tbl->_DllInterface_LoadDll = &IMPL::_DllInterface_LoadDll;
		tbl->_DllInterface_GetModule = &IMPL::_DllInterface_GetModule;
		tbl->_DllInterface_AddDllPath = &IMPL::_DllInterface_AddDllPath;
		tbl->_DllInterface_RemoveDllPath = &IMPL::_DllInterface_RemoveDllPath;
		tbl->_DllInterface_GetLoadedDlls = &IMPL::_DllInterface_GetLoadedDlls;
		tbl->_DllInterface_Unload = &IMPL::_DllInterface_Unload;
		tbl->_DllInterface_Release = &IMPL::_DllInterface_Release;
		tbl->_DllInterface_FindSymbolPointer = &IMPL::_DllInterface_FindSymbolPointer;
		tbl->_DllInterface_UpdateSymbolData = &IMPL::_DllInterface_UpdateSymbolData;
		tbl->_DllInterface_GetPath = &IMPL::_DllInterface_GetPath;
	}
};

template <typename C> class DllInterface::Wrapper
{
public:
	static void _DllInterface_Free(const DllInterface* object) { return C::Free(object); }
	static Result<DllRef> _DllInterface_LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) { return C::LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags); }
	static Result<DllRef> _DllInterface_GetModule(const void* handle, UInt processId) { return C::GetModule(handle, processId); }
	static Result<void> _DllInterface_AddDllPath(const Url& dllDirectory) { return C::AddDllPath(dllDirectory); }
	static Result<void> _DllInterface_RemoveDllPath(const Url& dllDirectory) { return C::RemoveDllPath(dllDirectory); }
	static Result<void> _DllInterface_GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) { return C::GetLoadedDlls(dlls); }
	static Result<void> _DllInterface_Unload(DllInterface* this_) { return ((C*) this_)->Unload(); }
	static Result<void> _DllInterface_Release(DllInterface* this_) { return ((C*) this_)->Release(); }
	static Result<void*> _DllInterface_FindSymbolPointer(const DllInterface* this_, const CString& symbol) { return ((const C*) this_)->FindSymbolPointer(symbol); }
	static Result<void> _DllInterface_UpdateSymbolData(DllInterface* this_) { return ((C*) this_)->UpdateSymbolData(); }
	static Result<Url> _DllInterface_GetPath(const DllInterface* this_) { return ((const C*) this_)->GetPath(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Free(const DllInterface* object) -> void
{
	return MTable::_instance._DllInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) -> Result<DllRef>
{
	return MTable::_instance._DllInterface_LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetModule(const void* handle, UInt processId) -> Result<DllRef>
{
	return MTable::_instance._DllInterface_GetModule(handle, processId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::AddDllPath(const Url& dllDirectory) -> Result<void>
{
	return MTable::_instance._DllInterface_AddDllPath(dllDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::RemoveDllPath(const Url& dllDirectory) -> Result<void>
{
	return MTable::_instance._DllInterface_RemoveDllPath(dllDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) -> Result<void>
{
	return MTable::_instance._DllInterface_GetLoadedDlls(dlls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Unload() -> Result<void>
{
	return MTable::_instance._DllInterface_Unload(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::Release() -> Result<void>
{
	return MTable::_instance._DllInterface_Release(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::FindSymbolPointer(const CString& symbol) const -> Result<void*>
{
	return MTable::_instance._DllInterface_FindSymbolPointer(this, symbol);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::UpdateSymbolData() -> Result<void>
{
	return MTable::_instance._DllInterface_UpdateSymbolData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::GetPath() const -> Result<Url>
{
	return MTable::_instance._DllInterface_GetPath(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags) -> Result<DllRef> { return (MTable::_instance._DllInterface_LoadDll(fileName, registerDll, requireCoreModule, systemDependentFlags)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::GetModule(const void* handle, UInt processId) -> Result<DllRef> { return (MTable::_instance._DllInterface_GetModule(handle, processId)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::AddDllPath(const Url& dllDirectory) -> Result<void> { return (MTable::_instance._DllInterface_AddDllPath(dllDirectory)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::RemoveDllPath(const Url& dllDirectory) -> Result<void> { return (MTable::_instance._DllInterface_RemoveDllPath(dllDirectory)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) -> Result<void> { return (MTable::_instance._DllInterface_GetLoadedDlls(dlls)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ReferenceFunctionsImpl<S>::Unload() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DllInterface* o_ = (DllInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DllInterface_Unload(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ReferenceFunctionsImpl<S>::Release() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DllInterface* o_ = (DllInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return OK; 
	return (MTable::_instance._DllInterface_Release(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::FindSymbolPointer(const CString& symbol) const -> Result<void*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DllInterface* o_ = (const DllInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DllInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._DllInterface_FindSymbolPointer(o_, symbol));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::FindSymbol(const CString& symbol) const -> Result<T>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<T>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DllInterface* o_ = (const DllInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DllInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Result<T>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->FindSymbol<T>(symbol));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ReferenceFunctionsImpl<S>::GetBinary() const -> Result<Binary*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Binary*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DllInterface* o_ = (DllInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->GetBinary());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ReferenceFunctionsImpl<S>::UpdateSymbolData() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DllInterface* o_ = (DllInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DllInterface_UpdateSymbolData(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DllInterface::ConstReferenceFunctionsImpl<S>::GetPath() const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DllInterface* o_ = (const DllInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DllInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._DllInterface_GetPath(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DllInterface(DllInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dll.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

