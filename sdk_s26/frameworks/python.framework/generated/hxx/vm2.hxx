
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
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
	Bool (*LibraryInterface_ConsoleIsAvailable) ();
#ifdef MAXON_TARGET_WINDOWS
	Result<Int32> (*LibraryInterface_GetVsVersion) (Int32 compilerVersion);
	Result<Url> (*LibraryInterface_GetVsRuntimeLibrary) (Int32 version, Bool release);
#endif
	Result<String> (*LibraryInterface_GetFileContent) (const Url& filepath);
	Result<void> (*LibraryInterface_SetFileContent) (const Url& filepath, const String& str, Bool append);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->LibraryInterface_ConsoleIsAvailable = &IMPL::LibraryInterface_ConsoleIsAvailable;
#ifdef MAXON_TARGET_WINDOWS
		tbl->LibraryInterface_GetVsVersion = &IMPL::LibraryInterface_GetVsVersion;
		tbl->LibraryInterface_GetVsRuntimeLibrary = &IMPL::LibraryInterface_GetVsRuntimeLibrary;
#endif
		tbl->LibraryInterface_GetFileContent = &IMPL::LibraryInterface_GetFileContent;
		tbl->LibraryInterface_SetFileContent = &IMPL::LibraryInterface_SetFileContent;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (LibraryInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, LibraryInterface::_interface); if (!vt) return false;
			return true;
		}
		static Bool LibraryInterface_ConsoleIsAvailable() { return S::Implementation::ConsoleIsAvailable(); }
#ifdef MAXON_TARGET_WINDOWS
		static Result<Int32> LibraryInterface_GetVsVersion(Int32 compilerVersion) { return S::Implementation::GetVsVersion(compilerVersion); }
		static Result<Url> LibraryInterface_GetVsRuntimeLibrary(Int32 version, Bool release) { return S::Implementation::GetVsRuntimeLibrary(version, release); }
#endif
		static Result<String> LibraryInterface_GetFileContent(const Url& filepath) { return S::Implementation::GetFileContent(filepath); }
		static Result<void> LibraryInterface_SetFileContent(const Url& filepath, const String& str, Bool append) { return S::Implementation::SetFileContent(filepath, str, append); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::ConsoleIsAvailable() -> Bool
{
	return Hxx2::StaticMTable::_instance.LibraryInterface_ConsoleIsAvailable();
}
#ifdef MAXON_TARGET_WINDOWS
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetVsVersion(Int32 compilerVersion) -> Result<Int32>
{
	return Hxx2::StaticMTable::_instance.LibraryInterface_GetVsVersion(compilerVersion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetVsRuntimeLibrary(Int32 version, Bool release) -> Result<Url>
{
	return Hxx2::StaticMTable::_instance.LibraryInterface_GetVsRuntimeLibrary(version, release);
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::GetFileContent(const Url& filepath) -> Result<String>
{
	return Hxx2::StaticMTable::_instance.LibraryInterface_GetFileContent(filepath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::SetFileContent(const Url& filepath, const String& str, Bool append) -> Result<void>
{
	return Hxx2::StaticMTable::_instance.LibraryInterface_SetFileContent(filepath, str, append);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstFn<S>::ConsoleIsAvailable() -> Bool
{
	return (Hxx2::StaticMTable::_instance.LibraryInterface_ConsoleIsAvailable());
}
#ifdef MAXON_TARGET_WINDOWS
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstFn<S>::GetVsVersion(Int32 compilerVersion) -> Result<Int32>
{
	return (Hxx2::StaticMTable::_instance.LibraryInterface_GetVsVersion(compilerVersion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstFn<S>::GetVsRuntimeLibrary(Int32 version, Bool release) -> Result<Url>
{
	return (Hxx2::StaticMTable::_instance.LibraryInterface_GetVsRuntimeLibrary(version, release));
}
#endif
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstFn<S>::GetFileContent(const Url& filepath) -> Result<String>
{
	return (Hxx2::StaticMTable::_instance.LibraryInterface_GetFileContent(filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LibraryInterface::Hxx1::ConstFn<S>::SetFileContent(const Url& filepath, const String& str, Bool append) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.LibraryInterface_SetFileContent(filepath, str, append));
}
auto LibraryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LibraryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_vm)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LibraryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LibraryInterface() { new (s_ui_maxon_LibraryInterface) maxon::EntityUse(LibraryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LibraryInterface(LibraryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/vm.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_vm)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*VmDebuggerConnectionInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int VmDebuggerConnectionInterface_GetName_Offset;
	Url (*VmDebuggerConnectionInterface_GetPath) (const maxon::GenericComponent* this_);
	maxon::Int VmDebuggerConnectionInterface_GetPath_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	String (*VmDebuggerConnectionInterface_GetStartupScript) (const maxon::GenericComponent* this_);
	maxon::Int VmDebuggerConnectionInterface_GetStartupScript_Offset;
	String (*VmDebuggerConnectionInterface_GetShutdownScript) (const maxon::GenericComponent* this_);
	maxon::Int VmDebuggerConnectionInterface_GetShutdownScript_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetName))
	{
		VmDebuggerConnectionInterface_GetName = &W::VmDebuggerConnectionInterface_GetName;
		VmDebuggerConnectionInterface_GetName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetPath))
	{
		VmDebuggerConnectionInterface_GetPath = &W::VmDebuggerConnectionInterface_GetPath;
		VmDebuggerConnectionInterface_GetPath_Offset = offset;
	}
#ifdef MAXON_COMPILER_GCC
#endif
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetStartupScript))
	{
		VmDebuggerConnectionInterface_GetStartupScript = &W::VmDebuggerConnectionInterface_GetStartupScript;
		VmDebuggerConnectionInterface_GetStartupScript_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetShutdownScript))
	{
		VmDebuggerConnectionInterface_GetShutdownScript = &W::VmDebuggerConnectionInterface_GetShutdownScript;
		VmDebuggerConnectionInterface_GetShutdownScript_Offset = offset;
	}
#ifdef MAXON_COMPILER_GCC
#endif
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (VmDebuggerConnectionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VmDebuggerConnectionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static String VmDebuggerConnectionInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
		static Url VmDebuggerConnectionInterface_GetPath(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPath(); }
#ifdef MAXON_COMPILER_GCC
#endif
		static String VmDebuggerConnectionInterface_GetStartupScript(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStartupScript(); }
		static String VmDebuggerConnectionInterface_GetShutdownScript(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetShutdownScript(); }
#ifdef MAXON_COMPILER_GCC
#endif
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetName() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_.VmDebuggerConnectionInterface_GetName((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetPath() const -> Url
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_.VmDebuggerConnectionInterface_GetPath((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetPath_Offset);
}
#ifdef MAXON_COMPILER_GCC
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetStartupScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_.VmDebuggerConnectionInterface_GetStartupScript((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetStartupScript_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetShutdownScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return mt_.VmDebuggerConnectionInterface_GetShutdownScript((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetShutdownScript_Offset);
}
#ifdef MAXON_COMPILER_GCC
#endif

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_.VmDebuggerConnectionInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_.VmDebuggerConnectionInterface_GetPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetPath_Offset));
}
#ifdef MAXON_COMPILER_GCC
#endif
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetStartupScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetStartupScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_.VmDebuggerConnectionInterface_GetStartupScript(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetStartupScript_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetShutdownScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetShutdownScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (mt_.VmDebuggerConnectionInterface_GetShutdownScript(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetShutdownScript_Offset));
}
#ifdef MAXON_COMPILER_GCC
#endif
auto VmDebuggerConnectionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VmDebuggerConnectionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_vm)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*VirtualMachineScopeInterface_Init) (maxon::GenericComponent* this_, const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug);
	maxon::Int VirtualMachineScopeInterface_Init_Offset;
	Result<void> (*VirtualMachineScopeInterface_Add) (maxon::GenericComponent* this_, const String& name, const Data& data);
	maxon::Int VirtualMachineScopeInterface_Add_Offset;
	Result<Data> (*VirtualMachineScopeInterface_Get) (maxon::GenericComponent* this_, const String& name);
	maxon::Int VirtualMachineScopeInterface_Get_Offset;
	Result<void> (*VirtualMachineScopeInterface_Execute) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineScopeInterface_Execute_Offset;
	Result<Data*> (*VirtualMachineScopeInterface_PrivateInvoke) (maxon::GenericComponent* this_, const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments);
	maxon::Int VirtualMachineScopeInterface_PrivateInvoke_Offset;
	Result<void> (*VirtualMachineScopeInterface_ErrorHandling) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineScopeInterface_ErrorHandling_Offset;
	Result<void> (*VirtualMachineScopeInterface__PrivateInit) (maxon::GenericComponent* this_, const LibraryRef& lib);
	maxon::Int VirtualMachineScopeInterface__PrivateInit_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Init))
	{
		VirtualMachineScopeInterface_Init = &W::VirtualMachineScopeInterface_Init;
		VirtualMachineScopeInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Add))
	{
		VirtualMachineScopeInterface_Add = &W::VirtualMachineScopeInterface_Add;
		VirtualMachineScopeInterface_Add_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Get))
	{
		VirtualMachineScopeInterface_Get = &W::VirtualMachineScopeInterface_Get;
		VirtualMachineScopeInterface_Get_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Execute))
	{
		VirtualMachineScopeInterface_Execute = &W::VirtualMachineScopeInterface_Execute;
		VirtualMachineScopeInterface_Execute_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, PrivateInvoke))
	{
		VirtualMachineScopeInterface_PrivateInvoke = &W::VirtualMachineScopeInterface_PrivateInvoke;
		VirtualMachineScopeInterface_PrivateInvoke_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, ErrorHandling))
	{
		VirtualMachineScopeInterface_ErrorHandling = &W::VirtualMachineScopeInterface_ErrorHandling;
		VirtualMachineScopeInterface_ErrorHandling_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, _PrivateInit))
	{
		VirtualMachineScopeInterface__PrivateInit = &W::VirtualMachineScopeInterface__PrivateInit;
		VirtualMachineScopeInterface__PrivateInit_Offset = offset;
	}
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (VirtualMachineScopeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VirtualMachineScopeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> VirtualMachineScopeInterface_Init(maxon::GenericComponent* this_, const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) { return ((typename S::Implementation*) this_)->Init(identifier, code, errorHandling, debug); }
		static Result<void> VirtualMachineScopeInterface_Add(maxon::GenericComponent* this_, const String& name, const Data& data) { return ((typename S::Implementation*) this_)->Add(name, data); }
		static Result<Data> VirtualMachineScopeInterface_Get(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->Get(name); }
		static Result<void> VirtualMachineScopeInterface_Execute(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Execute(); }
		static Result<Data*> VirtualMachineScopeInterface_PrivateInvoke(maxon::GenericComponent* this_, const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) { return ((typename S::Implementation*) this_)->PrivateInvoke(name, helperStack, expected, arguments); }
		static Result<void> VirtualMachineScopeInterface_ErrorHandling(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->ErrorHandling(); }
		static Result<void> VirtualMachineScopeInterface__PrivateInit(maxon::GenericComponent* this_, const LibraryRef& lib) { return ((typename S::Implementation*) this_)->_PrivateInit(lib); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_Init((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Add(const String& name, const Data& data) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_Add((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Add_Offset, name, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Get(const String& name) -> Result<Data>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_Get((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Get_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Execute() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_Execute((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Execute_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_PrivateInvoke((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::ErrorHandling() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface_ErrorHandling((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return mt_.VirtualMachineScopeInterface__PrivateInit((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface__PrivateInit_Offset, lib);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Init_Offset, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Add(const String& name, const Data& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Add(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Add_Offset, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Add(const String& name, const Data& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Add(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Add_Offset, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Get(const String& name) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Get(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Get_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Get(const String& name) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Get(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Get_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Execute() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Execute_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Execute() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Execute_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) const -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_PrivateInvoke(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_PrivateInvoke(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::ErrorHandling() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_ErrorHandling(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::ErrorHandling() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface_ErrorHandling(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::_PrivateInit(const LibraryRef& lib) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface__PrivateInit(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface__PrivateInit_Offset, lib));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (mt_.VirtualMachineScopeInterface__PrivateInit(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface__PrivateInit_Offset, lib));
}
auto VirtualMachineScopeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VirtualMachineScopeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_vm)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*VirtualMachineInterface_Init) (maxon::GenericComponent* this_, const LoadRuntime& runtimeInfo, const DataDictionary& settings);
	maxon::Int VirtualMachineInterface_Init_Offset;
	void (*VirtualMachineInterface_Free) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_Free_Offset;
	Result<VirtualMachineScopeRef> (*VirtualMachineInterface_CreateScope) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_CreateScope_Offset;
	String (*VirtualMachineInterface_GetName) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetName_Offset;
	String (*VirtualMachineInterface_GetVersion) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetVersion_Offset;
	String (*VirtualMachineInterface_GetCopyright) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetCopyright_Offset;
	String (*VirtualMachineInterface_GetCompiler) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetCompiler_Offset;
	String (*VirtualMachineInterface_GetBuildInfo) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetBuildInfo_Offset;
	Result<void> (*VirtualMachineInterface_EnterInteractiveMode) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_EnterInteractiveMode_Offset;
	Result<void> (*VirtualMachineInterface_Execute) (maxon::GenericComponent* this_, const String& code);
	maxon::Int VirtualMachineInterface_Execute_Offset;
	Result<void> (*VirtualMachineInterface_Execute_1) (maxon::GenericComponent* this_, const Url& filepath);
	maxon::Int VirtualMachineInterface_Execute_1_Offset;
	Result<void> (*VirtualMachineInterface_ExecuteModule) (maxon::GenericComponent* this_, const String& name);
	maxon::Int VirtualMachineInterface_ExecuteModule_Offset;
	Result<void> (*VirtualMachineInterface_GetDocumentString) (maxon::GenericComponent* this_, const String& code, DocStringMeta& meta);
	maxon::Int VirtualMachineInterface_GetDocumentString_Offset;
	LibraryRef (*VirtualMachineInterface_GetLibraryRef) (maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetLibraryRef_Offset;
	Result<BaseArray<Runtime>> (*VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries) (const maxon::GenericComponent* this_);
	maxon::Int VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Init))
	{
		VirtualMachineInterface_Init = &W::VirtualMachineInterface_Init;
		VirtualMachineInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Free))
	{
		VirtualMachineInterface_Free = &W::VirtualMachineInterface_Free;
		VirtualMachineInterface_Free_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, CreateScope))
	{
		VirtualMachineInterface_CreateScope = &W::VirtualMachineInterface_CreateScope;
		VirtualMachineInterface_CreateScope_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetName))
	{
		VirtualMachineInterface_GetName = &W::VirtualMachineInterface_GetName;
		VirtualMachineInterface_GetName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetVersion))
	{
		VirtualMachineInterface_GetVersion = &W::VirtualMachineInterface_GetVersion;
		VirtualMachineInterface_GetVersion_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCopyright))
	{
		VirtualMachineInterface_GetCopyright = &W::VirtualMachineInterface_GetCopyright;
		VirtualMachineInterface_GetCopyright_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCompiler))
	{
		VirtualMachineInterface_GetCompiler = &W::VirtualMachineInterface_GetCompiler;
		VirtualMachineInterface_GetCompiler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetBuildInfo))
	{
		VirtualMachineInterface_GetBuildInfo = &W::VirtualMachineInterface_GetBuildInfo;
		VirtualMachineInterface_GetBuildInfo_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, EnterInteractiveMode))
	{
		VirtualMachineInterface_EnterInteractiveMode = &W::VirtualMachineInterface_EnterInteractiveMode;
		VirtualMachineInterface_EnterInteractiveMode_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
	{
		VirtualMachineInterface_Execute = &W::VirtualMachineInterface_Execute;
		VirtualMachineInterface_Execute_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
	{
		VirtualMachineInterface_Execute_1 = &W::VirtualMachineInterface_Execute_1;
		VirtualMachineInterface_Execute_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, ExecuteModule))
	{
		VirtualMachineInterface_ExecuteModule = &W::VirtualMachineInterface_ExecuteModule;
		VirtualMachineInterface_ExecuteModule_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetDocumentString))
	{
		VirtualMachineInterface_GetDocumentString = &W::VirtualMachineInterface_GetDocumentString;
		VirtualMachineInterface_GetDocumentString_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetLibraryRef))
	{
		VirtualMachineInterface_GetLibraryRef = &W::VirtualMachineInterface_GetLibraryRef;
		VirtualMachineInterface_GetLibraryRef_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetAllAvailableVirtualMachineLibraries))
	{
		VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries = &W::VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries;
		VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset = offset;
	}
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (VirtualMachineInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VirtualMachineInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> VirtualMachineInterface_Init(maxon::GenericComponent* this_, const LoadRuntime& runtimeInfo, const DataDictionary& settings) { return ((typename S::Implementation*) this_)->Init(runtimeInfo, settings); }
		static void VirtualMachineInterface_Free(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Free(); }
		static Result<VirtualMachineScopeRef> VirtualMachineInterface_CreateScope(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CreateScope(); }
		static String VirtualMachineInterface_GetName(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetName(); }
		static String VirtualMachineInterface_GetVersion(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetVersion(); }
		static String VirtualMachineInterface_GetCopyright(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCopyright(); }
		static String VirtualMachineInterface_GetCompiler(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetCompiler(); }
		static String VirtualMachineInterface_GetBuildInfo(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetBuildInfo(); }
		static Result<void> VirtualMachineInterface_EnterInteractiveMode(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->EnterInteractiveMode(); }
		static Result<void> VirtualMachineInterface_Execute(maxon::GenericComponent* this_, const String& code) { return ((typename S::Implementation*) this_)->Execute(code); }
		static Result<void> VirtualMachineInterface_Execute_1(maxon::GenericComponent* this_, const Url& filepath) { return ((typename S::Implementation*) this_)->Execute(filepath); }
		static Result<void> VirtualMachineInterface_ExecuteModule(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->ExecuteModule(name); }
		static Result<void> VirtualMachineInterface_GetDocumentString(maxon::GenericComponent* this_, const String& code, DocStringMeta& meta) { return ((typename S::Implementation*) this_)->GetDocumentString(code, meta); }
		static LibraryRef VirtualMachineInterface_GetLibraryRef(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetLibraryRef(); }
		static Result<BaseArray<Runtime>> VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAllAvailableVirtualMachineLibraries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_Init((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Init_Offset, runtimeInfo, settings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Free() -> void
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_Free((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Free_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::CreateScope() -> Result<VirtualMachineScopeRef>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_CreateScope((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_CreateScope_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetName() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetName((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetVersion() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetVersion((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetVersion_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCopyright() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetCopyright((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetCopyright_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCompiler() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetCompiler((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetCompiler_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetBuildInfo() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetBuildInfo((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetBuildInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::EnterInteractiveMode() -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_EnterInteractiveMode((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const String& code) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_Execute((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Execute_Offset, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const Url& filepath) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_Execute_1((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Execute_1_Offset, filepath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::ExecuteModule(const String& name) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_ExecuteModule((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_ExecuteModule_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetDocumentString((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetDocumentString_Offset, code, meta);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetLibraryRef() -> LibraryRef
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetLibraryRef((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetLibraryRef_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries((const maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Init_Offset, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Init_Offset, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Free() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	mt_.VirtualMachineInterface_Free(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Free_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Free() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	mt_.VirtualMachineInterface_Free(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Free_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::CreateScope() const -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_CreateScope(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_CreateScope_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::CreateScope() -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_CreateScope(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_CreateScope_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetName() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetVersion() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetVersion(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetVersion_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetVersion() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetVersion(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetVersion_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetCopyright() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetCopyright(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCopyright_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetCopyright() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetCopyright(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCopyright_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetCompiler() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetCompiler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCompiler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetCompiler() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetCompiler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCompiler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetBuildInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetBuildInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetBuildInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetBuildInfo() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetBuildInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetBuildInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::EnterInteractiveMode() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_EnterInteractiveMode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::EnterInteractiveMode() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_EnterInteractiveMode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Execute(const String& code) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_Offset, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Execute(const String& code) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_Offset, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Execute(const Url& filepath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Execute_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_1_Offset, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Execute(const Url& filepath) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_Execute_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_1_Offset, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::ExecuteModule(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_ExecuteModule(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_ExecuteModule_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::ExecuteModule(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_ExecuteModule(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_ExecuteModule_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetDocumentString(const String& code, DocStringMeta& meta) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetDocumentString(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetDocumentString_Offset, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetDocumentString(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetDocumentString_Offset, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetLibraryRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<LibraryRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetLibraryRef(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetLibraryRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetLibraryRef() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetLibraryRef(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetLibraryRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ConstFn<S>::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Runtime>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VirtualMachineInterface* o_ = (const VirtualMachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VirtualMachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset));
}
auto VirtualMachineInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VirtualMachineInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_vm)
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

