
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef MAXON_TARGET_WINDOWS
#endif

struct LibraryInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
#ifdef MAXON_TARGET_WINDOWS
#endif
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LibraryInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<LibraryInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LibraryInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Bool (*_LibraryInterface_ConsoleIsAvailable) ();
#ifdef MAXON_TARGET_WINDOWS
	Result<Int32> (*_LibraryInterface_GetVsVersion) (Int32 compilerVersion);
	Result<Url> (*_LibraryInterface_GetVsRuntimeLibrary) (Int32 version, Bool release);
#endif
	Result<String> (*_LibraryInterface_GetFileContent) (const Url& filepath);
	Result<void> (*_LibraryInterface_SetFileContent) (const Url& filepath, const String& str, Bool append);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_LibraryInterface_ConsoleIsAvailable = &IMPL::_LibraryInterface_ConsoleIsAvailable;
#ifdef MAXON_TARGET_WINDOWS
		tbl->_LibraryInterface_GetVsVersion = &IMPL::_LibraryInterface_GetVsVersion;
		tbl->_LibraryInterface_GetVsRuntimeLibrary = &IMPL::_LibraryInterface_GetVsRuntimeLibrary;
#endif
		tbl->_LibraryInterface_GetFileContent = &IMPL::_LibraryInterface_GetFileContent;
		tbl->_LibraryInterface_SetFileContent = &IMPL::_LibraryInterface_SetFileContent;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static Bool _LibraryInterface_ConsoleIsAvailable() { return S::Implementation::ConsoleIsAvailable(); }
#ifdef MAXON_TARGET_WINDOWS
		static Result<Int32> _LibraryInterface_GetVsVersion(Int32 compilerVersion) { return S::Implementation::GetVsVersion(compilerVersion); }
		static Result<Url> _LibraryInterface_GetVsRuntimeLibrary(Int32 version, Bool release) { return S::Implementation::GetVsRuntimeLibrary(version, release); }
#endif
		static Result<String> _LibraryInterface_GetFileContent(const Url& filepath) { return S::Implementation::GetFileContent(filepath); }
		static Result<void> _LibraryInterface_SetFileContent(const Url& filepath, const String& str, Bool append) { return S::Implementation::SetFileContent(filepath, str, append); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::ConsoleIsAvailable() -> Bool
{
	return Hxx2::StaticMTable::_instance._LibraryInterface_ConsoleIsAvailable();
}
#ifdef MAXON_TARGET_WINDOWS
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetVsVersion(Int32 compilerVersion) -> Result<Int32>
{
	return Hxx2::StaticMTable::_instance._LibraryInterface_GetVsVersion(compilerVersion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetVsRuntimeLibrary(Int32 version, Bool release) -> Result<Url>
{
	return Hxx2::StaticMTable::_instance._LibraryInterface_GetVsRuntimeLibrary(version, release);
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetFileContent(const Url& filepath) -> Result<String>
{
	return Hxx2::StaticMTable::_instance._LibraryInterface_GetFileContent(filepath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::SetFileContent(const Url& filepath, const String& str, Bool append) -> Result<void>
{
	return Hxx2::StaticMTable::_instance._LibraryInterface_SetFileContent(filepath, str, append);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ConsoleIsAvailable() -> Bool { return (Hxx2::StaticMTable::_instance._LibraryInterface_ConsoleIsAvailable()); }
#ifdef MAXON_TARGET_WINDOWS
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetVsVersion(Int32 compilerVersion) -> Result<Int32> { return (Hxx2::StaticMTable::_instance._LibraryInterface_GetVsVersion(compilerVersion)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetVsRuntimeLibrary(Int32 version, Bool release) -> Result<Url> { return (Hxx2::StaticMTable::_instance._LibraryInterface_GetVsRuntimeLibrary(version, release)); }
#endif
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFileContent(const Url& filepath) -> Result<String> { return (Hxx2::StaticMTable::_instance._LibraryInterface_GetFileContent(filepath)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SetFileContent(const Url& filepath, const String& str, Bool append) -> Result<void> { return (Hxx2::StaticMTable::_instance._LibraryInterface_SetFileContent(filepath, str, append)); }
auto LibraryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LibraryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LibraryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LibraryInterface() { new (s_ui_maxon_LibraryInterface) maxon::EntityUse(LibraryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LibraryInterface(LibraryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_LibraryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_LibraryInterface() { new (s_usi_maxon_LibraryInterface) maxon::EntityUse(LibraryInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_LibraryInterface(LibraryInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif

struct VmDebuggerConnectionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetShutdownScript);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStartupScript);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*_VmDebuggerConnectionInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int _VmDebuggerConnectionInterface_GetName_Offset;
	Url (*_VmDebuggerConnectionInterface_GetPath) (const maxon::GenericComponent* this_);
	maxon::Int _VmDebuggerConnectionInterface_GetPath_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	String (*_VmDebuggerConnectionInterface_GetStartupScript) (const maxon::GenericComponent* this_);
	maxon::Int _VmDebuggerConnectionInterface_GetStartupScript_Offset;
	String (*_VmDebuggerConnectionInterface_GetShutdownScript) (const maxon::GenericComponent* this_);
	maxon::Int _VmDebuggerConnectionInterface_GetShutdownScript_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetName), W, MTable>::type::_VmDebuggerConnectionInterface_GetName;
			_VmDebuggerConnectionInterface_GetName = reinterpret_cast<const decltype(_VmDebuggerConnectionInterface_GetName)&>(ptr);
			_VmDebuggerConnectionInterface_GetName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetPath))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetPath), W, MTable>::type::_VmDebuggerConnectionInterface_GetPath;
			_VmDebuggerConnectionInterface_GetPath = reinterpret_cast<const decltype(_VmDebuggerConnectionInterface_GetPath)&>(ptr);
			_VmDebuggerConnectionInterface_GetPath_Offset = offset;
		}
#ifdef MAXON_COMPILER_GCC
#endif
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetStartupScript))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetStartupScript), W, MTable>::type::_VmDebuggerConnectionInterface_GetStartupScript;
			_VmDebuggerConnectionInterface_GetStartupScript = reinterpret_cast<const decltype(_VmDebuggerConnectionInterface_GetStartupScript)&>(ptr);
			_VmDebuggerConnectionInterface_GetStartupScript_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetShutdownScript))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetShutdownScript), W, MTable>::type::_VmDebuggerConnectionInterface_GetShutdownScript;
			_VmDebuggerConnectionInterface_GetShutdownScript = reinterpret_cast<const decltype(_VmDebuggerConnectionInterface_GetShutdownScript)&>(ptr);
			_VmDebuggerConnectionInterface_GetShutdownScript_Offset = offset;
		}
#ifdef MAXON_COMPILER_GCC
#endif
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<VmDebuggerConnectionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<VmDebuggerConnectionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VmDebuggerConnectionInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetShutdownScript);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStartupScript);
		static String _VmDebuggerConnectionInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
		static Url _VmDebuggerConnectionInterface_GetPath(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPath(); }
#ifdef MAXON_COMPILER_GCC
#endif
		static String _VmDebuggerConnectionInterface_GetStartupScript(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStartupScript(); }
		static String _VmDebuggerConnectionInterface_GetShutdownScript(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetShutdownScript(); }
#ifdef MAXON_COMPILER_GCC
#endif
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetName() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_._VmDebuggerConnectionInterface_GetName((const maxon::GenericComponent*) this + mt_._VmDebuggerConnectionInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetPath() const -> Url
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_._VmDebuggerConnectionInterface_GetPath((const maxon::GenericComponent*) this + mt_._VmDebuggerConnectionInterface_GetPath_Offset);
}
#ifdef MAXON_COMPILER_GCC
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetStartupScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_._VmDebuggerConnectionInterface_GetStartupScript((const maxon::GenericComponent*) this + mt_._VmDebuggerConnectionInterface_GetStartupScript_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetShutdownScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_._VmDebuggerConnectionInterface_GetShutdownScript((const maxon::GenericComponent*) this + mt_._VmDebuggerConnectionInterface_GetShutdownScript_Offset);
}
#ifdef MAXON_COMPILER_GCC
#endif

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_._VmDebuggerConnectionInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_._VmDebuggerConnectionInterface_GetPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetPath_Offset));
}
#ifdef MAXON_COMPILER_GCC
#endif
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetStartupScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetStartupScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_._VmDebuggerConnectionInterface_GetStartupScript(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetStartupScript_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetShutdownScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetShutdownScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_._VmDebuggerConnectionInterface_GetShutdownScript(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetShutdownScript_Offset));
}
#ifdef MAXON_COMPILER_GCC
#endif
auto VmDebuggerConnectionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VmDebuggerConnectionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_VmDebuggerConnectionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_VmDebuggerConnectionInterface() { new (s_ui_maxon_VmDebuggerConnectionInterface) maxon::EntityUse(VmDebuggerConnectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_VmDebuggerConnectionInterface(VmDebuggerConnectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct VirtualMachineScopeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Add);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ErrorHandling);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Get);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateInvoke);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(_PrivateInit);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_VirtualMachineScopeInterface_Init) (maxon::GenericComponent* this_, const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug);
	maxon::Int _VirtualMachineScopeInterface_Init_Offset;
	Result<void> (*_VirtualMachineScopeInterface_Add) (maxon::GenericComponent* this_, const String& name, const Data& data);
	maxon::Int _VirtualMachineScopeInterface_Add_Offset;
	Result<Data> (*_VirtualMachineScopeInterface_Get) (maxon::GenericComponent* this_, const String& name);
	maxon::Int _VirtualMachineScopeInterface_Get_Offset;
	Result<void> (*_VirtualMachineScopeInterface_Execute) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineScopeInterface_Execute_Offset;
	Result<Data*> (*_VirtualMachineScopeInterface_PrivateInvoke) (maxon::GenericComponent* this_, const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments);
	maxon::Int _VirtualMachineScopeInterface_PrivateInvoke_Offset;
	Result<void> (*_VirtualMachineScopeInterface_ErrorHandling) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineScopeInterface_ErrorHandling_Offset;
	Result<void> (*_VirtualMachineScopeInterface__PrivateInit) (maxon::GenericComponent* this_, const LibraryRef& lib);
	maxon::Int _VirtualMachineScopeInterface__PrivateInit_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Init), W, MTable>::type::_VirtualMachineScopeInterface_Init;
			_VirtualMachineScopeInterface_Init = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_Init)&>(ptr);
			_VirtualMachineScopeInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Add))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Add), W, MTable>::type::_VirtualMachineScopeInterface_Add;
			_VirtualMachineScopeInterface_Add = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_Add)&>(ptr);
			_VirtualMachineScopeInterface_Add_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Get))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Get), W, MTable>::type::_VirtualMachineScopeInterface_Get;
			_VirtualMachineScopeInterface_Get = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_Get)&>(ptr);
			_VirtualMachineScopeInterface_Get_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Execute))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Execute), W, MTable>::type::_VirtualMachineScopeInterface_Execute;
			_VirtualMachineScopeInterface_Execute = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_Execute)&>(ptr);
			_VirtualMachineScopeInterface_Execute_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, PrivateInvoke))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, PrivateInvoke), W, MTable>::type::_VirtualMachineScopeInterface_PrivateInvoke;
			_VirtualMachineScopeInterface_PrivateInvoke = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_PrivateInvoke)&>(ptr);
			_VirtualMachineScopeInterface_PrivateInvoke_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, ErrorHandling))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, ErrorHandling), W, MTable>::type::_VirtualMachineScopeInterface_ErrorHandling;
			_VirtualMachineScopeInterface_ErrorHandling = reinterpret_cast<const decltype(_VirtualMachineScopeInterface_ErrorHandling)&>(ptr);
			_VirtualMachineScopeInterface_ErrorHandling_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, _PrivateInit))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, _PrivateInit), W, MTable>::type::_VirtualMachineScopeInterface__PrivateInit;
			_VirtualMachineScopeInterface__PrivateInit = reinterpret_cast<const decltype(_VirtualMachineScopeInterface__PrivateInit)&>(ptr);
			_VirtualMachineScopeInterface__PrivateInit_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<VirtualMachineScopeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<VirtualMachineScopeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VirtualMachineScopeInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Add);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ErrorHandling);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Get);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateInvoke);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(_PrivateInit);
		static Result<void> _VirtualMachineScopeInterface_Init(maxon::GenericComponent* this_, const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) { return ((typename S::Implementation*) this_)->Init(identifier, code, errorHandling, debug); }
		static Result<void> _VirtualMachineScopeInterface_Add(maxon::GenericComponent* this_, const String& name, const Data& data) { return ((typename S::Implementation*) this_)->Add(name, data); }
		static Result<Data> _VirtualMachineScopeInterface_Get(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->Get(name); }
		static Result<void> _VirtualMachineScopeInterface_Execute(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Execute(); }
		static Result<Data*> _VirtualMachineScopeInterface_PrivateInvoke(maxon::GenericComponent* this_, const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) { return ((typename S::Implementation*) this_)->PrivateInvoke(name, helperStack, expected, arguments); }
		static Result<void> _VirtualMachineScopeInterface_ErrorHandling(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->ErrorHandling(); }
		static Result<void> _VirtualMachineScopeInterface__PrivateInit(maxon::GenericComponent* this_, const LibraryRef& lib) { return ((typename S::Implementation*) this_)->_PrivateInit(lib); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_Init((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Add(const String& name, const Data& data) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_Add((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_Add_Offset, name, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Get(const String& name) -> Result<Data>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_Get((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_Get_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Execute() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_Execute((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_Execute_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_PrivateInvoke((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::ErrorHandling() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface_ErrorHandling((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface_ErrorHandling_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_._VirtualMachineScopeInterface__PrivateInit((maxon::GenericComponent*) this + mt_._VirtualMachineScopeInterface__PrivateInit_Offset, lib);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::Add(const String& name, const Data& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Add(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Add_Offset, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Add(const String& name, const Data& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Add(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Add_Offset, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::Get(const String& name) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Get(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Get_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Get(const String& name) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Get(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Get_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::Execute() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Execute_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::Execute() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Execute_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) const -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_PrivateInvoke(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_PrivateInvoke(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::ErrorHandling() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_ErrorHandling(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_ErrorHandling_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::ErrorHandling() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface_ErrorHandling(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_ErrorHandling_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::ReferenceFunctionsImpl<S>::_PrivateInit(const LibraryRef& lib) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface__PrivateInit(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface__PrivateInit_Offset, lib));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWReferenceFunctionsImpl<S>::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_._VirtualMachineScopeInterface__PrivateInit(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface__PrivateInit_Offset, lib));
}
auto VirtualMachineScopeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VirtualMachineScopeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_VirtualMachineScopeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_VirtualMachineScopeInterface() { new (s_ui_maxon_VirtualMachineScopeInterface) maxon::EntityUse(VirtualMachineScopeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_VirtualMachineScopeInterface(VirtualMachineScopeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct VirtualMachineInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreateScope);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(EnterInteractiveMode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ExecuteModule);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Free);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetAllAvailableVirtualMachineLibraries);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBuildInfo);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCompiler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCopyright);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDocumentString);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLibraryRef);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetVersion);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_VirtualMachineInterface_Init) (maxon::GenericComponent* this_, const LoadRuntime& runtimeInfo, const DataDictionary& settings);
	maxon::Int _VirtualMachineInterface_Init_Offset;
	void (*_VirtualMachineInterface_Free) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_Free_Offset;
	Result<VirtualMachineScopeRef> (*_VirtualMachineInterface_CreateScope) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_CreateScope_Offset;
	String (*_VirtualMachineInterface_GetName) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetName_Offset;
	String (*_VirtualMachineInterface_GetVersion) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetVersion_Offset;
	String (*_VirtualMachineInterface_GetCopyright) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetCopyright_Offset;
	String (*_VirtualMachineInterface_GetCompiler) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetCompiler_Offset;
	String (*_VirtualMachineInterface_GetBuildInfo) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetBuildInfo_Offset;
	Result<void> (*_VirtualMachineInterface_EnterInteractiveMode) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_EnterInteractiveMode_Offset;
	Result<void> (*_VirtualMachineInterface_Execute) (maxon::GenericComponent* this_, const String& code);
	maxon::Int _VirtualMachineInterface_Execute_Offset;
	Result<void> (*_VirtualMachineInterface_Execute_1) (maxon::GenericComponent* this_, const Url& filepath);
	maxon::Int _VirtualMachineInterface_Execute_1_Offset;
	Result<void> (*_VirtualMachineInterface_ExecuteModule) (maxon::GenericComponent* this_, const String& name);
	maxon::Int _VirtualMachineInterface_ExecuteModule_Offset;
	Result<void> (*_VirtualMachineInterface_GetDocumentString) (maxon::GenericComponent* this_, const String& code, DocStringMeta& meta);
	maxon::Int _VirtualMachineInterface_GetDocumentString_Offset;
	LibraryRef (*_VirtualMachineInterface_GetLibraryRef) (maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetLibraryRef_Offset;
	Result<BaseArray<Runtime>> (*_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries) (const maxon::GenericComponent* this_);
	maxon::Int _VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Init), W, MTable>::type::_VirtualMachineInterface_Init;
			_VirtualMachineInterface_Init = reinterpret_cast<const decltype(_VirtualMachineInterface_Init)&>(ptr);
			_VirtualMachineInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Free))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Free), W, MTable>::type::_VirtualMachineInterface_Free;
			_VirtualMachineInterface_Free = reinterpret_cast<const decltype(_VirtualMachineInterface_Free)&>(ptr);
			_VirtualMachineInterface_Free_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, CreateScope))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, CreateScope), W, MTable>::type::_VirtualMachineInterface_CreateScope;
			_VirtualMachineInterface_CreateScope = reinterpret_cast<const decltype(_VirtualMachineInterface_CreateScope)&>(ptr);
			_VirtualMachineInterface_CreateScope_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetName), W, MTable>::type::_VirtualMachineInterface_GetName;
			_VirtualMachineInterface_GetName = reinterpret_cast<const decltype(_VirtualMachineInterface_GetName)&>(ptr);
			_VirtualMachineInterface_GetName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetVersion))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetVersion), W, MTable>::type::_VirtualMachineInterface_GetVersion;
			_VirtualMachineInterface_GetVersion = reinterpret_cast<const decltype(_VirtualMachineInterface_GetVersion)&>(ptr);
			_VirtualMachineInterface_GetVersion_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCopyright))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCopyright), W, MTable>::type::_VirtualMachineInterface_GetCopyright;
			_VirtualMachineInterface_GetCopyright = reinterpret_cast<const decltype(_VirtualMachineInterface_GetCopyright)&>(ptr);
			_VirtualMachineInterface_GetCopyright_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCompiler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCompiler), W, MTable>::type::_VirtualMachineInterface_GetCompiler;
			_VirtualMachineInterface_GetCompiler = reinterpret_cast<const decltype(_VirtualMachineInterface_GetCompiler)&>(ptr);
			_VirtualMachineInterface_GetCompiler_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetBuildInfo))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetBuildInfo), W, MTable>::type::_VirtualMachineInterface_GetBuildInfo;
			_VirtualMachineInterface_GetBuildInfo = reinterpret_cast<const decltype(_VirtualMachineInterface_GetBuildInfo)&>(ptr);
			_VirtualMachineInterface_GetBuildInfo_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, EnterInteractiveMode))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, EnterInteractiveMode), W, MTable>::type::_VirtualMachineInterface_EnterInteractiveMode;
			_VirtualMachineInterface_EnterInteractiveMode = reinterpret_cast<const decltype(_VirtualMachineInterface_EnterInteractiveMode)&>(ptr);
			_VirtualMachineInterface_EnterInteractiveMode_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute), W, MTable>::type::_VirtualMachineInterface_Execute;
			_VirtualMachineInterface_Execute = reinterpret_cast<const decltype(_VirtualMachineInterface_Execute)&>(ptr);
			_VirtualMachineInterface_Execute_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute), W, MTable>::type::_VirtualMachineInterface_Execute_1;
			_VirtualMachineInterface_Execute_1 = reinterpret_cast<const decltype(_VirtualMachineInterface_Execute_1)&>(ptr);
			_VirtualMachineInterface_Execute_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, ExecuteModule))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, ExecuteModule), W, MTable>::type::_VirtualMachineInterface_ExecuteModule;
			_VirtualMachineInterface_ExecuteModule = reinterpret_cast<const decltype(_VirtualMachineInterface_ExecuteModule)&>(ptr);
			_VirtualMachineInterface_ExecuteModule_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetDocumentString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetDocumentString), W, MTable>::type::_VirtualMachineInterface_GetDocumentString;
			_VirtualMachineInterface_GetDocumentString = reinterpret_cast<const decltype(_VirtualMachineInterface_GetDocumentString)&>(ptr);
			_VirtualMachineInterface_GetDocumentString_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetLibraryRef))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetLibraryRef), W, MTable>::type::_VirtualMachineInterface_GetLibraryRef;
			_VirtualMachineInterface_GetLibraryRef = reinterpret_cast<const decltype(_VirtualMachineInterface_GetLibraryRef)&>(ptr);
			_VirtualMachineInterface_GetLibraryRef_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetAllAvailableVirtualMachineLibraries))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetAllAvailableVirtualMachineLibraries), W, MTable>::type::_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries;
			_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries = reinterpret_cast<const decltype(_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries)&>(ptr);
			_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<VirtualMachineInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<VirtualMachineInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VirtualMachineInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateScope);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(EnterInteractiveMode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ExecuteModule);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Free);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAllAvailableVirtualMachineLibraries);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBuildInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCompiler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCopyright);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDocumentString);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLibraryRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetVersion);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static Result<void> _VirtualMachineInterface_Init(maxon::GenericComponent* this_, const LoadRuntime& runtimeInfo, const DataDictionary& settings) { return ((typename S::Implementation*) this_)->Init(runtimeInfo, settings); }
		static void _VirtualMachineInterface_Free(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Free(); }
		static Result<VirtualMachineScopeRef> _VirtualMachineInterface_CreateScope(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CreateScope(); }
		static String _VirtualMachineInterface_GetName(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetName(); }
		static String _VirtualMachineInterface_GetVersion(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetVersion(); }
		static String _VirtualMachineInterface_GetCopyright(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCopyright(); }
		static String _VirtualMachineInterface_GetCompiler(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCompiler(); }
		static String _VirtualMachineInterface_GetBuildInfo(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetBuildInfo(); }
		static Result<void> _VirtualMachineInterface_EnterInteractiveMode(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->EnterInteractiveMode(); }
		static Result<void> _VirtualMachineInterface_Execute(maxon::GenericComponent* this_, const String& code) { return ((typename S::Implementation*) this_)->Execute(code); }
		static Result<void> _VirtualMachineInterface_Execute_1(maxon::GenericComponent* this_, const Url& filepath) { return ((typename S::Implementation*) this_)->Execute(filepath); }
		static Result<void> _VirtualMachineInterface_ExecuteModule(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->ExecuteModule(name); }
		static Result<void> _VirtualMachineInterface_GetDocumentString(maxon::GenericComponent* this_, const String& code, DocStringMeta& meta) { return ((typename S::Implementation*) this_)->GetDocumentString(code, meta); }
		static LibraryRef _VirtualMachineInterface_GetLibraryRef(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetLibraryRef(); }
		static Result<BaseArray<Runtime>> _VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAllAvailableVirtualMachineLibraries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_Init((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_Init_Offset, runtimeInfo, settings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Free() -> void
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_Free((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_Free_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::CreateScope() -> Result<VirtualMachineScopeRef>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_CreateScope((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_CreateScope_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetName() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetName((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetVersion() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetVersion((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetVersion_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCopyright() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetCopyright((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetCopyright_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCompiler() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetCompiler((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetCompiler_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetBuildInfo() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetBuildInfo((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetBuildInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::EnterInteractiveMode() -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_EnterInteractiveMode((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_EnterInteractiveMode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const String& code) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_Execute((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_Execute_Offset, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const Url& filepath) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_Execute_1((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_Execute_1_Offset, filepath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::ExecuteModule(const String& name) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_ExecuteModule((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_ExecuteModule_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetDocumentString((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetDocumentString_Offset, code, meta);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetLibraryRef() -> LibraryRef
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetLibraryRef((maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetLibraryRef_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries((const maxon::GenericComponent*) this + mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Init_Offset, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Init_Offset, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::Free() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	mt_._VirtualMachineInterface_Free(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Free_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::Free() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	mt_._VirtualMachineInterface_Free(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Free_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::CreateScope() const -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_CreateScope(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_CreateScope_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::CreateScope() -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_CreateScope(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_CreateScope_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetName() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetVersion() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetVersion(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetVersion_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetVersion() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetVersion(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetVersion_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCopyright() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetCopyright(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCopyright_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetCopyright() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetCopyright(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCopyright_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCompiler() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetCompiler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCompiler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetCompiler() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetCompiler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCompiler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetBuildInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetBuildInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetBuildInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetBuildInfo() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetBuildInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetBuildInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::EnterInteractiveMode() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_EnterInteractiveMode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_EnterInteractiveMode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::EnterInteractiveMode() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_EnterInteractiveMode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_EnterInteractiveMode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::Execute(const String& code) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_Offset, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::Execute(const String& code) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_Offset, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::Execute(const Url& filepath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Execute_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_1_Offset, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::Execute(const Url& filepath) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_Execute_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_1_Offset, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::ExecuteModule(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_ExecuteModule(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_ExecuteModule_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::ExecuteModule(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_ExecuteModule(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_ExecuteModule_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetDocumentString(const String& code, DocStringMeta& meta) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetDocumentString(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetDocumentString_Offset, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetDocumentString(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetDocumentString_Offset, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetLibraryRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<LibraryRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetLibraryRef(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetLibraryRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetLibraryRef() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetLibraryRef(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetLibraryRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Runtime>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VirtualMachineInterface* o_ = (const VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VirtualMachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset));
}
auto VirtualMachineInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VirtualMachineInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_VirtualMachineInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_VirtualMachineInterface() { new (s_ui_maxon_VirtualMachineInterface) maxon::EntityUse(VirtualMachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_VirtualMachineInterface(VirtualMachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

