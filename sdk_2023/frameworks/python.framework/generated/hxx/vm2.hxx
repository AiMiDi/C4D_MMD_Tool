
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
	PRIVATE_MAXON_SF_POINTER(LibraryInterface_ConsoleIsAvailable, ConsoleIsAvailable, MAXON_EXPAND_VA_ARGS, (Bool));
#ifdef MAXON_TARGET_WINDOWS
	PRIVATE_MAXON_SF_POINTER(LibraryInterface_GetVsVersion, GetVsVersion, MAXON_EXPAND_VA_ARGS, (Result<Int32>), Int32 compilerVersion);
	PRIVATE_MAXON_SF_POINTER(LibraryInterface_GetVsRuntimeLibrary, GetVsRuntimeLibrary, MAXON_EXPAND_VA_ARGS, (Result<Url>), Int32 version, Bool release);
#endif
	PRIVATE_MAXON_SF_POINTER(LibraryInterface_GetFileContent, GetFileContent, MAXON_EXPAND_VA_ARGS, (Result<String>), const Url& filepath);
	PRIVATE_MAXON_SF_POINTER(LibraryInterface_SetFileContent, SetFileContent, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& filepath, const String& str, Bool append);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->LibraryInterface_ConsoleIsAvailable = LibraryInterface_ConsoleIsAvailable_GetPtr<IMPL>(true);
#ifdef MAXON_TARGET_WINDOWS
		tbl->LibraryInterface_GetVsVersion = LibraryInterface_GetVsVersion_GetPtr<IMPL>(true);
		tbl->LibraryInterface_GetVsRuntimeLibrary = LibraryInterface_GetVsRuntimeLibrary_GetPtr<IMPL>(true);
#endif
		tbl->LibraryInterface_GetFileContent = LibraryInterface_GetFileContent_GetPtr<IMPL>(true);
		tbl->LibraryInterface_SetFileContent = LibraryInterface_SetFileContent_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
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
	PRIVATE_MAXON_MF_POINTER(VmDebuggerConnectionInterface_GetName, GetName, true, maxon::GenericComponent, const, (String));
	maxon::Int VmDebuggerConnectionInterface_GetName_Offset;
	PRIVATE_MAXON_MF_POINTER(VmDebuggerConnectionInterface_GetPath, GetPath, true, maxon::GenericComponent, const, (Url));
	maxon::Int VmDebuggerConnectionInterface_GetPath_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	PRIVATE_MAXON_MF_POINTER(VmDebuggerConnectionInterface_GetStartupScript, GetStartupScript, true, maxon::GenericComponent, const, (String));
	maxon::Int VmDebuggerConnectionInterface_GetStartupScript_Offset;
	PRIVATE_MAXON_MF_POINTER(VmDebuggerConnectionInterface_GetShutdownScript, GetShutdownScript, true, maxon::GenericComponent, const, (String));
	maxon::Int VmDebuggerConnectionInterface_GetShutdownScript_Offset;
#ifdef MAXON_COMPILER_GCC
#endif
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetName))
	{
		maxon::Tie(VmDebuggerConnectionInterface_GetName, VmDebuggerConnectionInterface_GetName_Offset) = VmDebuggerConnectionInterface_GetName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetPath))
	{
		maxon::Tie(VmDebuggerConnectionInterface_GetPath, VmDebuggerConnectionInterface_GetPath_Offset) = VmDebuggerConnectionInterface_GetPath_GetPtr<W>(offset, true);
	}
#ifdef MAXON_COMPILER_GCC
#endif
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetStartupScript))
	{
		maxon::Tie(VmDebuggerConnectionInterface_GetStartupScript, VmDebuggerConnectionInterface_GetStartupScript_Offset) = VmDebuggerConnectionInterface_GetStartupScript_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VmDebuggerConnectionInterface, GetShutdownScript))
	{
		maxon::Tie(VmDebuggerConnectionInterface_GetShutdownScript, VmDebuggerConnectionInterface_GetShutdownScript_Offset) = VmDebuggerConnectionInterface_GetShutdownScript_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (VmDebuggerConnectionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VmDebuggerConnectionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(VmDebuggerConnectionInterface_GetName, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(VmDebuggerConnectionInterface_GetPath, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPath(); }
#ifdef MAXON_COMPILER_GCC
#endif
		PRIVATE_MAXON_MF_WRAPPER(VmDebuggerConnectionInterface_GetStartupScript, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStartupScript(); }
		PRIVATE_MAXON_MF_WRAPPER(VmDebuggerConnectionInterface_GetShutdownScript, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetShutdownScript(); }
#ifdef MAXON_COMPILER_GCC
#endif
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetName() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetName_Offset), mt_.VmDebuggerConnectionInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetPath() const -> Url
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetPath_Offset), mt_.VmDebuggerConnectionInterface_GetPath);
}
#ifdef MAXON_COMPILER_GCC
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetStartupScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetStartupScript_Offset), mt_.VmDebuggerConnectionInterface_GetStartupScript);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::GetShutdownScript() const -> String
{
	const VmDebuggerConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VmDebuggerConnectionInterface_GetShutdownScript_Offset), mt_.VmDebuggerConnectionInterface_GetShutdownScript);
}
#ifdef MAXON_COMPILER_GCC
#endif

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetName_Offset), mt_.VmDebuggerConnectionInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetPath_Offset), mt_.VmDebuggerConnectionInterface_GetPath));
}
#ifdef MAXON_COMPILER_GCC
#endif
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetStartupScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetStartupScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetStartupScript_Offset), mt_.VmDebuggerConnectionInterface_GetStartupScript));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VmDebuggerConnectionInterface::Hxx1::ConstFn<S>::GetShutdownScript() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VmDebuggerConnectionInterface* o_ = (const VmDebuggerConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VmDebuggerConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VmDebuggerConnectionInterface, o_, VmDebuggerConnectionInterface_GetShutdownScript) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VmDebuggerConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VmDebuggerConnectionInterface>() : PRIVATE_MAXON_VTABLE(VmDebuggerConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VmDebuggerConnectionInterface_GetShutdownScript_Offset), mt_.VmDebuggerConnectionInterface_GetShutdownScript));
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
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug);
	maxon::Int VirtualMachineScopeInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_Add, Add, true, maxon::GenericComponent,, (Result<void>), const String& name, const Data& data);
	maxon::Int VirtualMachineScopeInterface_Add_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_Get, Get, true, maxon::GenericComponent,, (Result<Data>), const String& name);
	maxon::Int VirtualMachineScopeInterface_Get_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_Execute, Execute, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int VirtualMachineScopeInterface_Execute_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_PrivateInvoke, PrivateInvoke, true, maxon::GenericComponent,, (Result<Data*>), const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments);
	maxon::Int VirtualMachineScopeInterface_PrivateInvoke_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface_ErrorHandling, ErrorHandling, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int VirtualMachineScopeInterface_ErrorHandling_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineScopeInterface__PrivateInit, _PrivateInit, true, maxon::GenericComponent,, (Result<void>), const LibraryRef& lib);
	maxon::Int VirtualMachineScopeInterface__PrivateInit_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Init))
	{
		maxon::Tie(VirtualMachineScopeInterface_Init, VirtualMachineScopeInterface_Init_Offset) = VirtualMachineScopeInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Add))
	{
		maxon::Tie(VirtualMachineScopeInterface_Add, VirtualMachineScopeInterface_Add_Offset) = VirtualMachineScopeInterface_Add_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Get))
	{
		maxon::Tie(VirtualMachineScopeInterface_Get, VirtualMachineScopeInterface_Get_Offset) = VirtualMachineScopeInterface_Get_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, Execute))
	{
		maxon::Tie(VirtualMachineScopeInterface_Execute, VirtualMachineScopeInterface_Execute_Offset) = VirtualMachineScopeInterface_Execute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, PrivateInvoke))
	{
		maxon::Tie(VirtualMachineScopeInterface_PrivateInvoke, VirtualMachineScopeInterface_PrivateInvoke_Offset) = VirtualMachineScopeInterface_PrivateInvoke_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, ErrorHandling))
	{
		maxon::Tie(VirtualMachineScopeInterface_ErrorHandling, VirtualMachineScopeInterface_ErrorHandling_Offset) = VirtualMachineScopeInterface_ErrorHandling_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineScopeInterface, _PrivateInit))
	{
		maxon::Tie(VirtualMachineScopeInterface__PrivateInit, VirtualMachineScopeInterface__PrivateInit_Offset) = VirtualMachineScopeInterface__PrivateInit_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (VirtualMachineScopeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VirtualMachineScopeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_Init, maxon::GenericComponent,, (Result<void>), const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(identifier, code, errorHandling, debug); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_Add, maxon::GenericComponent,, (Result<void>), const String& name, const Data& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Add(name, data); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_Get, maxon::GenericComponent,, (Result<Data>), const String& name) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Get(name); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_Execute, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Execute(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_PrivateInvoke, maxon::GenericComponent,, (Result<Data*>), const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateInvoke(name, helperStack, expected, arguments); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface_ErrorHandling, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ErrorHandling(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineScopeInterface__PrivateInit, maxon::GenericComponent,, (Result<void>), const LibraryRef& lib) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->_PrivateInit(lib); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Init_Offset), mt_.VirtualMachineScopeInterface_Init, identifier, code, errorHandling, debug);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Add(const String& name, const Data& data) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Add_Offset), mt_.VirtualMachineScopeInterface_Add, name, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Get(const String& name) -> Result<Data>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Get_Offset), mt_.VirtualMachineScopeInterface_Get, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Execute() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_Execute_Offset), mt_.VirtualMachineScopeInterface_Execute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset), mt_.VirtualMachineScopeInterface_PrivateInvoke, name, helperStack, expected, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::ErrorHandling() -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset), mt_.VirtualMachineScopeInterface_ErrorHandling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	const VirtualMachineScopeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineScopeInterface__PrivateInit_Offset), mt_.VirtualMachineScopeInterface__PrivateInit, lib);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Init_Offset), mt_.VirtualMachineScopeInterface_Init, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Init_Offset), mt_.VirtualMachineScopeInterface_Init, identifier, code, errorHandling, debug));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Add(const String& name, const Data& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Add_Offset), mt_.VirtualMachineScopeInterface_Add, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Add(const String& name, const Data& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Add) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Add_Offset), mt_.VirtualMachineScopeInterface_Add, name, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Get(const String& name) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Get_Offset), mt_.VirtualMachineScopeInterface_Get, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Get(const String& name) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Get) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Get_Offset), mt_.VirtualMachineScopeInterface_Get, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::Execute() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Execute_Offset), mt_.VirtualMachineScopeInterface_Execute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::Execute() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_Execute_Offset), mt_.VirtualMachineScopeInterface_Execute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) const -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset), mt_.VirtualMachineScopeInterface_PrivateInvoke, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) -> Result<Data*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_PrivateInvoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_PrivateInvoke_Offset), mt_.VirtualMachineScopeInterface_PrivateInvoke, name, helperStack, expected, arguments));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::ErrorHandling() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset), mt_.VirtualMachineScopeInterface_ErrorHandling));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::ErrorHandling() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface_ErrorHandling) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface_ErrorHandling_Offset), mt_.VirtualMachineScopeInterface_ErrorHandling));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::Fn<S>::_PrivateInit(const LibraryRef& lib) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface__PrivateInit_Offset), mt_.VirtualMachineScopeInterface__PrivateInit, lib));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineScopeInterface::Hxx1::COWFn<S>::_PrivateInit(const LibraryRef& lib) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineScopeInterface* o_ = (VirtualMachineScopeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineScopeInterface, o_, VirtualMachineScopeInterface__PrivateInit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineScopeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineScopeInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineScopeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineScopeInterface__PrivateInit_Offset), mt_.VirtualMachineScopeInterface__PrivateInit, lib));
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
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const LoadRuntime& runtimeInfo, const DataDictionary& settings);
	maxon::Int VirtualMachineInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_Free, Free, true, maxon::GenericComponent,, (void));
	maxon::Int VirtualMachineInterface_Free_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_CreateScope, CreateScope, true, maxon::GenericComponent,, (Result<VirtualMachineScopeRef>));
	maxon::Int VirtualMachineInterface_CreateScope_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetName, GetName, true, maxon::GenericComponent,, (String));
	maxon::Int VirtualMachineInterface_GetName_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetVersion, GetVersion, true, maxon::GenericComponent,, (String));
	maxon::Int VirtualMachineInterface_GetVersion_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetCopyright, GetCopyright, true, maxon::GenericComponent,, (String));
	maxon::Int VirtualMachineInterface_GetCopyright_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetCompiler, GetCompiler, true, maxon::GenericComponent,, (String));
	maxon::Int VirtualMachineInterface_GetCompiler_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetBuildInfo, GetBuildInfo, true, maxon::GenericComponent,, (String));
	maxon::Int VirtualMachineInterface_GetBuildInfo_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_EnterInteractiveMode, EnterInteractiveMode, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int VirtualMachineInterface_EnterInteractiveMode_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_Execute, Execute, true, maxon::GenericComponent,, (Result<void>), const String& code);
	maxon::Int VirtualMachineInterface_Execute_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_Execute_1, Execute, true, maxon::GenericComponent,, (Result<void>), const Url& filepath);
	maxon::Int VirtualMachineInterface_Execute_1_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_ExecuteModule, ExecuteModule, true, maxon::GenericComponent,, (Result<void>), const String& name);
	maxon::Int VirtualMachineInterface_ExecuteModule_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetDocumentString, GetDocumentString, true, maxon::GenericComponent,, (Result<void>), const String& code, DocStringMeta& meta);
	maxon::Int VirtualMachineInterface_GetDocumentString_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetLibraryRef, GetLibraryRef, true, maxon::GenericComponent,, (LibraryRef));
	maxon::Int VirtualMachineInterface_GetLibraryRef_Offset;
	PRIVATE_MAXON_MF_POINTER(VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries, GetAllAvailableVirtualMachineLibraries, true, maxon::GenericComponent, const, (Result<BaseArray<Runtime>>));
	maxon::Int VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Init))
	{
		maxon::Tie(VirtualMachineInterface_Init, VirtualMachineInterface_Init_Offset) = VirtualMachineInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Free))
	{
		maxon::Tie(VirtualMachineInterface_Free, VirtualMachineInterface_Free_Offset) = VirtualMachineInterface_Free_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, CreateScope))
	{
		maxon::Tie(VirtualMachineInterface_CreateScope, VirtualMachineInterface_CreateScope_Offset) = VirtualMachineInterface_CreateScope_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetName))
	{
		maxon::Tie(VirtualMachineInterface_GetName, VirtualMachineInterface_GetName_Offset) = VirtualMachineInterface_GetName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetVersion))
	{
		maxon::Tie(VirtualMachineInterface_GetVersion, VirtualMachineInterface_GetVersion_Offset) = VirtualMachineInterface_GetVersion_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCopyright))
	{
		maxon::Tie(VirtualMachineInterface_GetCopyright, VirtualMachineInterface_GetCopyright_Offset) = VirtualMachineInterface_GetCopyright_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetCompiler))
	{
		maxon::Tie(VirtualMachineInterface_GetCompiler, VirtualMachineInterface_GetCompiler_Offset) = VirtualMachineInterface_GetCompiler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetBuildInfo))
	{
		maxon::Tie(VirtualMachineInterface_GetBuildInfo, VirtualMachineInterface_GetBuildInfo_Offset) = VirtualMachineInterface_GetBuildInfo_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, EnterInteractiveMode))
	{
		maxon::Tie(VirtualMachineInterface_EnterInteractiveMode, VirtualMachineInterface_EnterInteractiveMode_Offset) = VirtualMachineInterface_EnterInteractiveMode_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
	{
		maxon::Tie(VirtualMachineInterface_Execute, VirtualMachineInterface_Execute_Offset) = VirtualMachineInterface_Execute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, Execute))
	{
		maxon::Tie(VirtualMachineInterface_Execute_1, VirtualMachineInterface_Execute_1_Offset) = VirtualMachineInterface_Execute_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, ExecuteModule))
	{
		maxon::Tie(VirtualMachineInterface_ExecuteModule, VirtualMachineInterface_ExecuteModule_Offset) = VirtualMachineInterface_ExecuteModule_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetDocumentString))
	{
		maxon::Tie(VirtualMachineInterface_GetDocumentString, VirtualMachineInterface_GetDocumentString_Offset) = VirtualMachineInterface_GetDocumentString_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetLibraryRef))
	{
		maxon::Tie(VirtualMachineInterface_GetLibraryRef, VirtualMachineInterface_GetLibraryRef_Offset) = VirtualMachineInterface_GetLibraryRef_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VirtualMachineInterface, GetAllAvailableVirtualMachineLibraries))
	{
		maxon::Tie(VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries, VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset) = VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (VirtualMachineInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VirtualMachineInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_Init, maxon::GenericComponent,, (Result<void>), const LoadRuntime& runtimeInfo, const DataDictionary& settings) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(runtimeInfo, settings); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_Free, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Free(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_CreateScope, maxon::GenericComponent,, (Result<VirtualMachineScopeRef>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CreateScope(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetName, maxon::GenericComponent,, (String)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetVersion, maxon::GenericComponent,, (String)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetVersion(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetCopyright, maxon::GenericComponent,, (String)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetCopyright(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetCompiler, maxon::GenericComponent,, (String)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetCompiler(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetBuildInfo, maxon::GenericComponent,, (String)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetBuildInfo(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_EnterInteractiveMode, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->EnterInteractiveMode(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_Execute, maxon::GenericComponent,, (Result<void>), const String& code) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Execute(code); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_Execute_1, maxon::GenericComponent,, (Result<void>), const Url& filepath) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Execute(filepath); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_ExecuteModule, maxon::GenericComponent,, (Result<void>), const String& name) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ExecuteModule(name); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetDocumentString, maxon::GenericComponent,, (Result<void>), const String& code, DocStringMeta& meta) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetDocumentString(code, meta); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetLibraryRef, maxon::GenericComponent,, (LibraryRef)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetLibraryRef(); }
		PRIVATE_MAXON_MF_WRAPPER(VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries, maxon::GenericComponent, const, (Result<BaseArray<Runtime>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetAllAvailableVirtualMachineLibraries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Init_Offset), mt_.VirtualMachineInterface_Init, runtimeInfo, settings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Free() -> void
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Free_Offset), mt_.VirtualMachineInterface_Free);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::CreateScope() -> Result<VirtualMachineScopeRef>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_CreateScope_Offset), mt_.VirtualMachineInterface_CreateScope);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetName() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetName_Offset), mt_.VirtualMachineInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetVersion() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetVersion_Offset), mt_.VirtualMachineInterface_GetVersion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCopyright() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetCopyright_Offset), mt_.VirtualMachineInterface_GetCopyright);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetCompiler() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetCompiler_Offset), mt_.VirtualMachineInterface_GetCompiler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetBuildInfo() -> String
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetBuildInfo_Offset), mt_.VirtualMachineInterface_GetBuildInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::EnterInteractiveMode() -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset), mt_.VirtualMachineInterface_EnterInteractiveMode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const String& code) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Execute_Offset), mt_.VirtualMachineInterface_Execute, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Execute(const Url& filepath) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_Execute_1_Offset), mt_.VirtualMachineInterface_Execute_1, filepath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::ExecuteModule(const String& name) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_ExecuteModule_Offset), mt_.VirtualMachineInterface_ExecuteModule, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetDocumentString_Offset), mt_.VirtualMachineInterface_GetDocumentString, code, meta);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetLibraryRef() -> LibraryRef
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetLibraryRef_Offset), mt_.VirtualMachineInterface_GetLibraryRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	const VirtualMachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VirtualMachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset), mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Init_Offset), mt_.VirtualMachineInterface_Init, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Init_Offset), mt_.VirtualMachineInterface_Init, runtimeInfo, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Free() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Free_Offset), mt_.VirtualMachineInterface_Free);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Free() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Free) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Free_Offset), mt_.VirtualMachineInterface_Free);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::CreateScope() const -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_CreateScope_Offset), mt_.VirtualMachineInterface_CreateScope));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::CreateScope() -> Result<VirtualMachineScopeRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VirtualMachineScopeRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_CreateScope) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_CreateScope_Offset), mt_.VirtualMachineInterface_CreateScope));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetName_Offset), mt_.VirtualMachineInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetName() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetName_Offset), mt_.VirtualMachineInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetVersion() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetVersion_Offset), mt_.VirtualMachineInterface_GetVersion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetVersion() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetVersion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetVersion_Offset), mt_.VirtualMachineInterface_GetVersion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetCopyright() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCopyright_Offset), mt_.VirtualMachineInterface_GetCopyright));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetCopyright() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCopyright) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCopyright_Offset), mt_.VirtualMachineInterface_GetCopyright));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetCompiler() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCompiler_Offset), mt_.VirtualMachineInterface_GetCompiler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetCompiler() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetCompiler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetCompiler_Offset), mt_.VirtualMachineInterface_GetCompiler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetBuildInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetBuildInfo_Offset), mt_.VirtualMachineInterface_GetBuildInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetBuildInfo() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetBuildInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetBuildInfo_Offset), mt_.VirtualMachineInterface_GetBuildInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::EnterInteractiveMode() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset), mt_.VirtualMachineInterface_EnterInteractiveMode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::EnterInteractiveMode() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_EnterInteractiveMode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_EnterInteractiveMode_Offset), mt_.VirtualMachineInterface_EnterInteractiveMode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Execute(const String& code) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_Offset), mt_.VirtualMachineInterface_Execute, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Execute(const String& code) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_Offset), mt_.VirtualMachineInterface_Execute, code));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::Execute(const Url& filepath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_1_Offset), mt_.VirtualMachineInterface_Execute_1, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::Execute(const Url& filepath) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_Execute_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_Execute_1_Offset), mt_.VirtualMachineInterface_Execute_1, filepath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::ExecuteModule(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_ExecuteModule_Offset), mt_.VirtualMachineInterface_ExecuteModule, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::ExecuteModule(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_ExecuteModule) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_ExecuteModule_Offset), mt_.VirtualMachineInterface_ExecuteModule, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetDocumentString(const String& code, DocStringMeta& meta) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetDocumentString_Offset), mt_.VirtualMachineInterface_GetDocumentString, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetDocumentString(const String& code, DocStringMeta& meta) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetDocumentString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetDocumentString_Offset), mt_.VirtualMachineInterface_GetDocumentString, code, meta));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::Fn<S>::GetLibraryRef() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<LibraryRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetLibraryRef_Offset), mt_.VirtualMachineInterface_GetLibraryRef));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::COWFn<S>::GetLibraryRef() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VirtualMachineInterface* o_ = (VirtualMachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetLibraryRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetLibraryRef_Offset), mt_.VirtualMachineInterface_GetLibraryRef));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VirtualMachineInterface::Hxx1::ConstFn<S>::GetAllAvailableVirtualMachineLibraries() const -> Result<BaseArray<Runtime>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Runtime>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VirtualMachineInterface* o_ = (const VirtualMachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VirtualMachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VirtualMachineInterface, o_, VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VirtualMachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VirtualMachineInterface>() : PRIVATE_MAXON_VTABLE(VirtualMachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset), mt_.VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries));
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

