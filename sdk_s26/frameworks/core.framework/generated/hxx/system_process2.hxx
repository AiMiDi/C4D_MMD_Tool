
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SystemProcessKilledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SystemProcessOperationErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	Result<void> (*SystemProcessObjectInterface_StartProcess) (maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_StartProcess_Offset;
	Result<void> (*SystemProcessObjectInterface_KillProcess) (maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_KillProcess_Offset;
	Int (*SystemProcessObjectInterface_GetExitCode) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetExitCode_Offset;
	Bool (*SystemProcessObjectInterface_IsRunning) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_IsRunning_Offset;
	UInt (*SystemProcessObjectInterface_GetProcessId) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetProcessId_Offset;
	void* (*SystemProcessObjectInterface_GetProcessHandle) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetProcessHandle_Offset;
	Url (*SystemProcessObjectInterface_GetProcessUrl) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetProcessUrl_Offset;
	Url (*SystemProcessObjectInterface_GetLogFile) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetLogFile_Offset;
	void* (*SystemProcessObjectInterface_GetUserData) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_GetUserData_Offset;
	Result<void> (*SystemProcessObjectInterface_GetLoadedDlls) (const maxon::GenericComponent* this_, const ValueReceiver<const DllRef&>& dlls);
	maxon::Int SystemProcessObjectInterface_GetLoadedDlls_Offset;
	maxon::ObservableRef<ObservableProcessFinishedDelegate> (*SystemProcessObjectInterface_ObservableProcessFinished) (const maxon::GenericComponent* this_);
	maxon::Int SystemProcessObjectInterface_ObservableProcessFinished_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, StartProcess))
	{
		SystemProcessObjectInterface_StartProcess = &W::SystemProcessObjectInterface_StartProcess;
		SystemProcessObjectInterface_StartProcess_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, KillProcess))
	{
		SystemProcessObjectInterface_KillProcess = &W::SystemProcessObjectInterface_KillProcess;
		SystemProcessObjectInterface_KillProcess_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetExitCode))
	{
		SystemProcessObjectInterface_GetExitCode = &W::SystemProcessObjectInterface_GetExitCode;
		SystemProcessObjectInterface_GetExitCode_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, IsRunning))
	{
		SystemProcessObjectInterface_IsRunning = &W::SystemProcessObjectInterface_IsRunning;
		SystemProcessObjectInterface_IsRunning_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessId))
	{
		SystemProcessObjectInterface_GetProcessId = &W::SystemProcessObjectInterface_GetProcessId;
		SystemProcessObjectInterface_GetProcessId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessHandle))
	{
		SystemProcessObjectInterface_GetProcessHandle = &W::SystemProcessObjectInterface_GetProcessHandle;
		SystemProcessObjectInterface_GetProcessHandle_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetProcessUrl))
	{
		SystemProcessObjectInterface_GetProcessUrl = &W::SystemProcessObjectInterface_GetProcessUrl;
		SystemProcessObjectInterface_GetProcessUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetLogFile))
	{
		SystemProcessObjectInterface_GetLogFile = &W::SystemProcessObjectInterface_GetLogFile;
		SystemProcessObjectInterface_GetLogFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetUserData))
	{
		SystemProcessObjectInterface_GetUserData = &W::SystemProcessObjectInterface_GetUserData;
		SystemProcessObjectInterface_GetUserData_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, GetLoadedDlls))
	{
		SystemProcessObjectInterface_GetLoadedDlls = &W::SystemProcessObjectInterface_GetLoadedDlls;
		SystemProcessObjectInterface_GetLoadedDlls_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SystemProcessObjectInterface, ObservableProcessFinished))
	{
		SystemProcessObjectInterface_ObservableProcessFinished = &W::SystemProcessObjectInterface_ObservableProcessFinished;
		SystemProcessObjectInterface_ObservableProcessFinished_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SystemProcessObjectInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (SystemProcessObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SystemProcessObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> SystemProcessObjectInterface_StartProcess(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->StartProcess(); }
		static Result<void> SystemProcessObjectInterface_KillProcess(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->KillProcess(); }
		static Int SystemProcessObjectInterface_GetExitCode(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetExitCode(); }
		static Bool SystemProcessObjectInterface_IsRunning(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsRunning(); }
		static UInt SystemProcessObjectInterface_GetProcessId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProcessId(); }
		static void* SystemProcessObjectInterface_GetProcessHandle(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProcessHandle(); }
		static Url SystemProcessObjectInterface_GetProcessUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProcessUrl(); }
		static Url SystemProcessObjectInterface_GetLogFile(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLogFile(); }
		static void* SystemProcessObjectInterface_GetUserData(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUserData(); }
		static Result<void> SystemProcessObjectInterface_GetLoadedDlls(const maxon::GenericComponent* this_, const ValueReceiver<const DllRef&>& dlls) { return ((const typename S::Implementation*) this_)->GetLoadedDlls(dlls); }
		static maxon::ObservableRef<ObservableProcessFinishedDelegate> SystemProcessObjectInterface_ObservableProcessFinished(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableProcessFinished(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::StartProcess() -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_StartProcess((maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_StartProcess_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::KillProcess() -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_KillProcess((maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_KillProcess_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetExitCode() const -> Int
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetExitCode((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetExitCode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::IsRunning() const -> Bool
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_IsRunning((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_IsRunning_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessId() const -> UInt
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetProcessId((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessHandle() const -> void*
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetProcessHandle((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessHandle_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetProcessUrl() const -> Url
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetProcessUrl((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetProcessUrl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetLogFile() const -> Url
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetLogFile((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetLogFile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetUserData() const -> void*
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetUserData((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetUserData_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const -> Result<void>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_GetLoadedDlls((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_GetLoadedDlls_Offset, dlls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::ObservableProcessFinished() const -> maxon::ObservableRef<ObservableProcessFinishedDelegate>
{
	const SystemProcessObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, this); return mt_.SystemProcessObjectInterface_ObservableProcessFinished((const maxon::GenericComponent*) this + mt_.SystemProcessObjectInterface_ObservableProcessFinished_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::Fn<S>::StartProcess() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemProcessObjectInterface* o_ = (SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_StartProcess) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_StartProcess(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_StartProcess_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::COWFn<S>::StartProcess() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemProcessObjectInterface* o_ = (SystemProcessObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_StartProcess) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_StartProcess(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_StartProcess_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::Fn<S>::KillProcess() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemProcessObjectInterface* o_ = (SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_KillProcess) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_KillProcess(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_KillProcess_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::COWFn<S>::KillProcess() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemProcessObjectInterface* o_ = (SystemProcessObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_KillProcess) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_KillProcess(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_KillProcess_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetExitCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetExitCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetExitCode(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetExitCode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::IsRunning() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_IsRunning) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_IsRunning(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_IsRunning_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetProcessId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetProcessId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessHandle() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetProcessHandle) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetProcessHandle(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessHandle_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetProcessUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetProcessUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetProcessUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetProcessUrl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetLogFile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetLogFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetLogFile(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetLogFile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetUserData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetUserData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetUserData(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetUserData_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_GetLoadedDlls) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_GetLoadedDlls(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_GetLoadedDlls_Offset, dlls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemProcessObjectInterface::Hxx1::ConstFn<S>::ObservableProcessFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProcessFinishedDelegate>>, maxon::ObservableRef<ObservableProcessFinishedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProcessFinishedDelegate>>, maxon::ObservableRef<ObservableProcessFinishedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemProcessObjectInterface* o_ = (const SystemProcessObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemProcessObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableProcessFinishedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SystemProcessObjectInterface, o_, SystemProcessObjectInterface_ObservableProcessFinished) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SystemProcessObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SystemProcessObjectInterface>() : PRIVATE_MAXON_VTABLE(SystemProcessObjectInterface, o_); 
	return (mt_.SystemProcessObjectInterface_ObservableProcessFinished(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SystemProcessObjectInterface_ObservableProcessFinished_Offset));
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<SystemProcessObjectRef> (*SystemProcessInterface_CreateProcess) (const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe);
	Result<SystemProcessObjectRef> (*SystemProcessInterface_StartProcessAndWait) (const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData);
	Result<void> (*SystemProcessInterface_GetSystemProcesses) (const ValueReceiver<const SystemProcessObjectRef&>& processes);
	UInt (*SystemProcessInterface_GetCurrentProcessId) ();
	Result<SystemProcessObjectRef> (*SystemProcessInterface_GetProcess) (UInt id);
	Result<WAIT_PROCESS_RESULT> (*SystemProcessInterface_WaitForProcess) (const SystemProcessObjectRef& processRef, const TimeValue& timeout);
	template <typename IMPL> void Init()
	{
		SystemProcessInterface_CreateProcess = &IMPL::SystemProcessInterface_CreateProcess;
		SystemProcessInterface_StartProcessAndWait = &IMPL::SystemProcessInterface_StartProcessAndWait;
		SystemProcessInterface_GetSystemProcesses = &IMPL::SystemProcessInterface_GetSystemProcesses;
		SystemProcessInterface_GetCurrentProcessId = &IMPL::SystemProcessInterface_GetCurrentProcessId;
		SystemProcessInterface_GetProcess = &IMPL::SystemProcessInterface_GetProcess;
		SystemProcessInterface_WaitForProcess = &IMPL::SystemProcessInterface_WaitForProcess;
	}
};

struct SystemProcessInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<SystemProcessObjectRef> SystemProcessInterface_CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe) { return C::CreateProcess(programPath, arguments, flags, userData, stdinPipe, stdoutPipe, stderrPipe); }
		static Result<SystemProcessObjectRef> SystemProcessInterface_StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData) { return C::StartProcessAndWait(programPath, arguments, flags, std::forward<ExecuteProgramCallback>(callback), userData); }
		static Result<void> SystemProcessInterface_GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes) { return C::GetSystemProcesses(processes); }
		static UInt SystemProcessInterface_GetCurrentProcessId() { return C::GetCurrentProcessId(); }
		static Result<SystemProcessObjectRef> SystemProcessInterface_GetProcess(UInt id) { return C::GetProcess(id); }
		static Result<WAIT_PROCESS_RESULT> SystemProcessInterface_WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout) { return C::WaitForProcess(processRef, timeout); }
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

