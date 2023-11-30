
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct SystemProcessKilledErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<SystemProcessKilledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<SystemProcessKilledErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct SystemProcessKilledErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (SystemProcessKilledErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SystemProcessKilledErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto SystemProcessKilledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SystemProcessKilledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_system_process)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SystemProcessKilledErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SystemProcessKilledErrorInterface() { new (s_ui_maxon_SystemProcessKilledErrorInterface) maxon::EntityUse(SystemProcessKilledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SystemProcessKilledErrorInterface(SystemProcessKilledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct SystemProcessOperationErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<SystemProcessOperationErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<SystemProcessOperationErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct SystemProcessOperationErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (SystemProcessOperationErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SystemProcessOperationErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto SystemProcessOperationErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SystemProcessOperationErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_system_process)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SystemProcessOperationErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SystemProcessOperationErrorInterface() { new (s_ui_maxon_SystemProcessOperationErrorInterface) maxon::EntityUse(SystemProcessOperationErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SystemProcessOperationErrorInterface(SystemProcessOperationErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct SystemProcessObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExitCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLoadedDlls);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLogFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProcessHandle);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProcessId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProcessUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUserData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsRunning);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(KillProcess);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableProcessFinished);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(StartProcess);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_StartProcess, StartProcess, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int SystemProcessObjectInterface_StartProcess_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_KillProcess, KillProcess, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int SystemProcessObjectInterface_KillProcess_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetExitCode, GetExitCode, true, maxon::GenericComponent, const, (Int));
	maxon::Int SystemProcessObjectInterface_GetExitCode_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_IsRunning, IsRunning, true, maxon::GenericComponent, const, (Bool));
	maxon::Int SystemProcessObjectInterface_IsRunning_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetProcessId, GetProcessId, true, maxon::GenericComponent, const, (UInt));
	maxon::Int SystemProcessObjectInterface_GetProcessId_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetProcessHandle, GetProcessHandle, true, maxon::GenericComponent, const, (void*));
	maxon::Int SystemProcessObjectInterface_GetProcessHandle_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetProcessUrl, GetProcessUrl, true, maxon::GenericComponent, const, (Url));
	maxon::Int SystemProcessObjectInterface_GetProcessUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetLogFile, GetLogFile, true, maxon::GenericComponent, const, (Url));
	maxon::Int SystemProcessObjectInterface_GetLogFile_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetUserData, GetUserData, true, maxon::GenericComponent, const, (void*));
	maxon::Int SystemProcessObjectInterface_GetUserData_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_GetLoadedDlls, GetLoadedDlls, true, maxon::GenericComponent, const, (Result<void>), const ValueReceiver<const DllRef&>& dlls);
	maxon::Int SystemProcessObjectInterface_GetLoadedDlls_Offset;
	PRIVATE_MAXON_MF_POINTER(SystemProcessObjectInterface_ObservableProcessFinished, ObservableProcessFinished, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableProcessFinishedDelegate>), Bool create);
	maxon::Int SystemProcessObjectInterface_ObservableProcessFinished_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, StartProcess))
	{
		maxon::Tie(SystemProcessObjectInterface_StartProcess, SystemProcessObjectInterface_StartProcess_Offset) = SystemProcessObjectInterface_StartProcess_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, KillProcess))
	{
		maxon::Tie(SystemProcessObjectInterface_KillProcess, SystemProcessObjectInterface_KillProcess_Offset) = SystemProcessObjectInterface_KillProcess_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetExitCode))
	{
		maxon::Tie(SystemProcessObjectInterface_GetExitCode, SystemProcessObjectInterface_GetExitCode_Offset) = SystemProcessObjectInterface_GetExitCode_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, IsRunning))
	{
		maxon::Tie(SystemProcessObjectInterface_IsRunning, SystemProcessObjectInterface_IsRunning_Offset) = SystemProcessObjectInterface_IsRunning_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessId))
	{
		maxon::Tie(SystemProcessObjectInterface_GetProcessId, SystemProcessObjectInterface_GetProcessId_Offset) = SystemProcessObjectInterface_GetProcessId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessHandle))
	{
		maxon::Tie(SystemProcessObjectInterface_GetProcessHandle, SystemProcessObjectInterface_GetProcessHandle_Offset) = SystemProcessObjectInterface_GetProcessHandle_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessUrl))
	{
		maxon::Tie(SystemProcessObjectInterface_GetProcessUrl, SystemProcessObjectInterface_GetProcessUrl_Offset) = SystemProcessObjectInterface_GetProcessUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetLogFile))
	{
		maxon::Tie(SystemProcessObjectInterface_GetLogFile, SystemProcessObjectInterface_GetLogFile_Offset) = SystemProcessObjectInterface_GetLogFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetUserData))
	{
		maxon::Tie(SystemProcessObjectInterface_GetUserData, SystemProcessObjectInterface_GetUserData_Offset) = SystemProcessObjectInterface_GetUserData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetLoadedDlls))
	{
		maxon::Tie(SystemProcessObjectInterface_GetLoadedDlls, SystemProcessObjectInterface_GetLoadedDlls_Offset) = SystemProcessObjectInterface_GetLoadedDlls_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, ObservableProcessFinished))
	{
		maxon::Tie(SystemProcessObjectInterface_ObservableProcessFinished, SystemProcessObjectInterface_ObservableProcessFinished_Offset) = SystemProcessObjectInterface_ObservableProcessFinished_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<SystemProcessObjectInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<SystemProcessObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct SystemProcessObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExitCode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLoadedDlls);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLogFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProcessHandle);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProcessId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProcessUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUserData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsRunning);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(KillProcess);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableProcessFinished);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(StartProcess);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (SystemProcessObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SystemProcessObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_StartProcess, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->StartProcess(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_KillProcess, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->KillProcess(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetExitCode, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetExitCode(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_IsRunning, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsRunning(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetProcessId, maxon::GenericComponent, const, (UInt)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProcessId(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetProcessHandle, maxon::GenericComponent, const, (void*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProcessHandle(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetProcessUrl, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProcessUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetLogFile, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLogFile(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetUserData, maxon::GenericComponent, const, (void*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUserData(); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_GetLoadedDlls, maxon::GenericComponent, const, (Result<void>), const ValueReceiver<const DllRef&>& dlls) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLoadedDlls(dlls); }
		PRIVATE_MAXON_MF_WRAPPER(SystemProcessObjectInterface_ObservableProcessFinished, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableProcessFinishedDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableProcessFinished(create); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::StartProcess() -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_StartProcess_Offset), mt_.SystemProcessObjectInterface_StartProcess);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::KillProcess() -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_KillProcess_Offset), mt_.SystemProcessObjectInterface_KillProcess);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetExitCode() const -> Int
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetExitCode_Offset), mt_.SystemProcessObjectInterface_GetExitCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::IsRunning() const -> Bool
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_IsRunning_Offset), mt_.SystemProcessObjectInterface_IsRunning);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessId() const -> UInt
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessId_Offset), mt_.SystemProcessObjectInterface_GetProcessId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessHandle() const -> void*
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessHandle_Offset), mt_.SystemProcessObjectInterface_GetProcessHandle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessUrl() const -> Url
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessUrl_Offset), mt_.SystemProcessObjectInterface_GetProcessUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetLogFile() const -> Url
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetLogFile_Offset), mt_.SystemProcessObjectInterface_GetLogFile);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetUserData() const -> void*
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetUserData_Offset), mt_.SystemProcessObjectInterface_GetUserData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetLoadedDlls_Offset), mt_.SystemProcessObjectInterface_GetLoadedDlls, dlls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::ObservableProcessFinished(Bool create) const -> maxon::ObservableRef<ObservableProcessFinishedDelegate>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_ObservableProcessFinished_Offset), mt_.SystemProcessObjectInterface_ObservableProcessFinished, create);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::Fn<S>::StartProcess() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(SystemProcessObjectInterface_StartProcess); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_StartProcess_Offset), mt_.SystemProcessObjectInterface_StartProcess));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::COWFn<S>::StartProcess() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(SystemProcessObjectInterface_StartProcess); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_StartProcess_Offset), mt_.SystemProcessObjectInterface_StartProcess));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::Fn<S>::KillProcess() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(SystemProcessObjectInterface_KillProcess); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_KillProcess_Offset), mt_.SystemProcessObjectInterface_KillProcess));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::COWFn<S>::KillProcess() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(SystemProcessObjectInterface_KillProcess); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_KillProcess_Offset), mt_.SystemProcessObjectInterface_KillProcess));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetExitCode() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(SystemProcessObjectInterface_GetExitCode); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetExitCode_Offset), mt_.SystemProcessObjectInterface_GetExitCode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::IsRunning() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(SystemProcessObjectInterface_IsRunning); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_IsRunning_Offset), mt_.SystemProcessObjectInterface_IsRunning));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessId() const -> HXXADDRET2(UInt)
{
	HXXRETURN0(HXXADDRET2(UInt)); HXXRES; HXXCONST(0) HXXTABLE(SystemProcessObjectInterface_GetProcessId); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessId_Offset), mt_.SystemProcessObjectInterface_GetProcessId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessHandle() const -> HXXADDRET2(void*)
{
	HXXRETURN0(HXXADDRET2(void*)); HXXRES; HXXCONST(nullptr) HXXTABLE(SystemProcessObjectInterface_GetProcessHandle); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessHandle_Offset), mt_.SystemProcessObjectInterface_GetProcessHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessUrl() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) HXXTABLE(SystemProcessObjectInterface_GetProcessUrl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessUrl_Offset), mt_.SystemProcessObjectInterface_GetProcessUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetLogFile() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) HXXTABLE(SystemProcessObjectInterface_GetLogFile); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetLogFile_Offset), mt_.SystemProcessObjectInterface_GetLogFile));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetUserData() const -> HXXADDRET2(void*)
{
	HXXRETURN0(HXXADDRET2(void*)); HXXRES; HXXCONST(nullptr) HXXTABLE(SystemProcessObjectInterface_GetUserData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetUserData_Offset), mt_.SystemProcessObjectInterface_GetUserData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(SystemProcessObjectInterface_GetLoadedDlls); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetLoadedDlls_Offset), mt_.SystemProcessObjectInterface_GetLoadedDlls, dlls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::ObservableProcessFinished(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableProcessFinishedDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableProcessFinishedDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableProcessFinishedDelegate>::DefaultValue()) HXXTABLE(SystemProcessObjectInterface_ObservableProcessFinished); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_ObservableProcessFinished_Offset), mt_.SystemProcessObjectInterface_ObservableProcessFinished, create));
}
auto SystemProcessObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SystemProcessObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_system_process)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SystemProcessObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SystemProcessObjectInterface() { new (s_ui_maxon_SystemProcessObjectInterface) maxon::EntityUse(SystemProcessObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SystemProcessObjectInterface(SystemProcessObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* SystemProcessInterface::PrivateGetCppName() { return nullptr; }

struct SystemProcessInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_CreateProcess, CreateProcess, MAXON_EXPAND_VA_ARGS, (Result<SystemProcessObjectRef>), const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe);
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_StartProcessAndWait, StartProcessAndWait, MAXON_EXPAND_VA_ARGS, (Result<SystemProcessObjectRef>), const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData);
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_GetSystemProcesses, GetSystemProcesses, MAXON_EXPAND_VA_ARGS, (Result<void>), const ValueReceiver<const SystemProcessObjectRef&>& processes);
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_GetCurrentProcessId, GetCurrentProcessId, MAXON_EXPAND_VA_ARGS, (UInt));
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_GetProcess, GetProcess, MAXON_EXPAND_VA_ARGS, (Result<SystemProcessObjectRef>), UInt id);
	PRIVATE_MAXON_SF_POINTER(SystemProcessInterface_WaitForProcess, WaitForProcess, MAXON_EXPAND_VA_ARGS, (Result<WAIT_PROCESS_RESULT>), const SystemProcessObjectRef& processRef, const TimeValue& timeout);
	template <typename IMPL> void Init()
	{
		SystemProcessInterface_CreateProcess = SystemProcessInterface_CreateProcess_GetPtr<IMPL>(true);
		SystemProcessInterface_StartProcessAndWait = SystemProcessInterface_StartProcessAndWait_GetPtr<IMPL>(true);
		SystemProcessInterface_GetSystemProcesses = SystemProcessInterface_GetSystemProcesses_GetPtr<IMPL>(true);
		SystemProcessInterface_GetCurrentProcessId = SystemProcessInterface_GetCurrentProcessId_GetPtr<IMPL>(true);
		SystemProcessInterface_GetProcess = SystemProcessInterface_GetProcess_GetPtr<IMPL>(true);
		SystemProcessInterface_WaitForProcess = SystemProcessInterface_WaitForProcess_GetPtr<IMPL>(true);
	}
};

struct SystemProcessInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<SystemProcessObjectRef> SystemProcessInterface_CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe) { return S::CreateProcess(programPath, arguments, flags, userData, stdinPipe, stdoutPipe, stderrPipe); }
		static Result<SystemProcessObjectRef> SystemProcessInterface_StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData) { return S::StartProcessAndWait(programPath, arguments, flags, std::forward<ExecuteProgramCallback>(callback), userData); }
		static Result<void> SystemProcessInterface_GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes) { return S::GetSystemProcesses(processes); }
		static UInt SystemProcessInterface_GetCurrentProcessId() { return S::GetCurrentProcessId(); }
		static Result<SystemProcessObjectRef> SystemProcessInterface_GetProcess(UInt id) { return S::GetProcess(id); }
		static Result<WAIT_PROCESS_RESULT> SystemProcessInterface_WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout) { return S::WaitForProcess(processRef, timeout); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe) -> Result<SystemProcessObjectRef>
{
	return MTable::_instance.SystemProcessInterface_CreateProcess(programPath, arguments, flags, userData, stdinPipe, stdoutPipe, stderrPipe);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData) -> Result<SystemProcessObjectRef>
{
	return MTable::_instance.SystemProcessInterface_StartProcessAndWait(programPath, arguments, flags, std::forward<ExecuteProgramCallback>(callback), userData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes) -> Result<void>
{
	return MTable::_instance.SystemProcessInterface_GetSystemProcesses(processes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::GetCurrentProcessId() -> UInt
{
	return MTable::_instance.SystemProcessInterface_GetCurrentProcessId();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::GetProcess(UInt id) -> Result<SystemProcessObjectRef>
{
	return MTable::_instance.SystemProcessInterface_GetProcess(id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessInterface::WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout) -> Result<WAIT_PROCESS_RESULT>
{
	return MTable::_instance.SystemProcessInterface_WaitForProcess(processRef, timeout);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_system_process)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SystemProcessInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SystemProcessInterface() { new (s_ui_maxon_SystemProcessInterface) maxon::EntityUse(SystemProcessInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SystemProcessInterface(SystemProcessInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system_process.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

