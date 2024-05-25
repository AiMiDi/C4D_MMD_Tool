
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct BackgroundEntryInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDuration);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStartTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStateCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStates);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetName, GetName, true, maxon::GenericComponent, const, (String));
	maxon::Int BackgroundEntryInterface_GetName_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetStartTime, GetStartTime, true, maxon::GenericComponent, const, (UniversalDateTime));
	maxon::Int BackgroundEntryInterface_GetStartTime_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetDuration, GetDuration, true, maxon::GenericComponent, const, (TimeValue));
	maxon::Int BackgroundEntryInterface_GetDuration_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetState, GetState, true, maxon::GenericComponent,, (STATE));
	maxon::Int BackgroundEntryInterface_GetState_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetStates, GetStates, true, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<STATE, const String&>& state);
	maxon::Int BackgroundEntryInterface_GetStates_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_GetStateCount, GetStateCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int BackgroundEntryInterface_GetStateCount_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundEntryInterface_AddState, AddState, true, maxon::GenericComponent,, (Result<void>), STATE state, const String& message);
	maxon::Int BackgroundEntryInterface_AddState_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetName))
	{
		maxon::Tie(BackgroundEntryInterface_GetName, BackgroundEntryInterface_GetName_Offset) = BackgroundEntryInterface_GetName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStartTime))
	{
		maxon::Tie(BackgroundEntryInterface_GetStartTime, BackgroundEntryInterface_GetStartTime_Offset) = BackgroundEntryInterface_GetStartTime_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetDuration))
	{
		maxon::Tie(BackgroundEntryInterface_GetDuration, BackgroundEntryInterface_GetDuration_Offset) = BackgroundEntryInterface_GetDuration_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetState))
	{
		maxon::Tie(BackgroundEntryInterface_GetState, BackgroundEntryInterface_GetState_Offset) = BackgroundEntryInterface_GetState_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStates))
	{
		maxon::Tie(BackgroundEntryInterface_GetStates, BackgroundEntryInterface_GetStates_Offset) = BackgroundEntryInterface_GetStates_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStateCount))
	{
		maxon::Tie(BackgroundEntryInterface_GetStateCount, BackgroundEntryInterface_GetStateCount_Offset) = BackgroundEntryInterface_GetStateCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, AddState))
	{
		maxon::Tie(BackgroundEntryInterface_AddState, BackgroundEntryInterface_AddState_Offset) = BackgroundEntryInterface_AddState_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<BackgroundEntryInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BackgroundEntryInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BackgroundEntryInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDuration);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStartTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStateCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStates);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BackgroundEntryInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BackgroundEntryInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetName, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetStartTime, maxon::GenericComponent, const, (UniversalDateTime)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStartTime(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetDuration, maxon::GenericComponent, const, (TimeValue)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDuration(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetState, maxon::GenericComponent,, (STATE)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetState(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetStates, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<STATE, const String&>& state) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStates(state); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_GetStateCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStateCount(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundEntryInterface_AddState, maxon::GenericComponent,, (Result<void>), STATE state, const String& message) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddState(state, message); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetName() const -> String
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetName_Offset), mt_.BackgroundEntryInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStartTime() const -> UniversalDateTime
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStartTime_Offset), mt_.BackgroundEntryInterface_GetStartTime);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetDuration() const -> TimeValue
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetDuration_Offset), mt_.BackgroundEntryInterface_GetDuration);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetState() -> STATE
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetState_Offset), mt_.BackgroundEntryInterface_GetState);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStates(const ValueReceiver<STATE, const String&>& state) const -> Result<Bool>
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStates_Offset), mt_.BackgroundEntryInterface_GetStates, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStateCount() const -> Int
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStateCount_Offset), mt_.BackgroundEntryInterface_GetStateCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::AddState(STATE state, const String& message) -> Result<void>
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_AddState_Offset), mt_.BackgroundEntryInterface_AddState, state, message);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetName() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(BackgroundEntryInterface_GetName); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetName_Offset), mt_.BackgroundEntryInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStartTime() const -> HXXADDRET2(UniversalDateTime)
{
	HXXRETURN0(HXXADDRET2(UniversalDateTime)); HXXRES; HXXCONST(HXXRET3(NULLPTR, UniversalDateTime)) HXXTABLE(BackgroundEntryInterface_GetStartTime); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStartTime_Offset), mt_.BackgroundEntryInterface_GetStartTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetDuration() const -> HXXADDRET2(TimeValue)
{
	HXXRETURN0(HXXADDRET2(TimeValue)); HXXRES; HXXCONST(HXXRET3(NULLPTR, TimeValue)) HXXTABLE(BackgroundEntryInterface_GetDuration); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetDuration_Offset), mt_.BackgroundEntryInterface_GetDuration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::GetState() const -> HXXADDRET2(STATE)
{
	HXXRETURN0(HXXADDRET2(STATE)); HXXRES; HXXNONCONST(, , false, HXXRET3(NULLPTR, STATE)) HXXTABLE(BackgroundEntryInterface_GetState); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset), mt_.BackgroundEntryInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::GetState() -> HXXADDRET1(STATE)
{
	HXXRETURN0(HXXADDRET1(STATE)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundEntryInterface_GetState); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset), mt_.BackgroundEntryInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStates(const ValueReceiver<STATE, const String&>& state) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BackgroundEntryInterface_GetStates); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStates_Offset), mt_.BackgroundEntryInterface_GetStates, state));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStateCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(BackgroundEntryInterface_GetStateCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStateCount_Offset), mt_.BackgroundEntryInterface_GetStateCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::AddState(STATE state, const String& message) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BackgroundEntryInterface_AddState); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset), mt_.BackgroundEntryInterface_AddState, state, message));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::AddState(STATE state, const String& message) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundEntryInterface_AddState); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset), mt_.BackgroundEntryInterface_AddState, state, message));
}
auto BackgroundEntryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BackgroundEntryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_backgroundentry)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BackgroundEntryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BackgroundEntryInterface() { new (s_ui_maxon_BackgroundEntryInterface) maxon::EntityUse(BackgroundEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BackgroundEntryInterface(BackgroundEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct BackgroundProgressInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddActiveEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ClearHistory);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetActiveCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetActiveEntries);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHistoryCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHistoryEntries);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableStateChanged);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableTotalProgressNotification);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveActiveEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveHistoryEntry);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_AddActiveEntry, AddActiveEntry, true, maxon::GenericComponent,, (Result<BackgroundProgressRef>), const String& title, Bool sendToHistory);
	maxon::Int BackgroundProgressInterface_AddActiveEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_RemoveActiveEntry, RemoveActiveEntry, true, maxon::GenericComponent,, (Result<void>), const BackgroundProgressRef& entry);
	maxon::Int BackgroundProgressInterface_RemoveActiveEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_GetActiveEntries, GetActiveEntries, true, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<const BackgroundProgressRef&>& entry);
	maxon::Int BackgroundProgressInterface_GetActiveEntries_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_GetActiveCount, GetActiveCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int BackgroundProgressInterface_GetActiveCount_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_GetHistoryEntries, GetHistoryEntries, true, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<const BackgroundEntryRef&>& entry);
	maxon::Int BackgroundProgressInterface_GetHistoryEntries_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_GetHistoryCount, GetHistoryCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int BackgroundProgressInterface_GetHistoryCount_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_RemoveHistoryEntry, RemoveHistoryEntry, true, maxon::GenericComponent,, (Result<void>), const BackgroundEntryRef& entry);
	maxon::Int BackgroundProgressInterface_RemoveHistoryEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_ClearHistory, ClearHistory, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int BackgroundProgressInterface_ClearHistory_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_ObservableStateChanged, ObservableStateChanged, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableStateChangedDelegate>), Bool create);
	maxon::Int BackgroundProgressInterface_ObservableStateChanged_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_ObservableTotalProgressNotification, ObservableTotalProgressNotification, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>), Bool create);
	maxon::Int BackgroundProgressInterface_ObservableTotalProgressNotification_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, AddActiveEntry))
	{
		maxon::Tie(BackgroundProgressInterface_AddActiveEntry, BackgroundProgressInterface_AddActiveEntry_Offset) = BackgroundProgressInterface_AddActiveEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, RemoveActiveEntry))
	{
		maxon::Tie(BackgroundProgressInterface_RemoveActiveEntry, BackgroundProgressInterface_RemoveActiveEntry_Offset) = BackgroundProgressInterface_RemoveActiveEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetActiveEntries))
	{
		maxon::Tie(BackgroundProgressInterface_GetActiveEntries, BackgroundProgressInterface_GetActiveEntries_Offset) = BackgroundProgressInterface_GetActiveEntries_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetActiveCount))
	{
		maxon::Tie(BackgroundProgressInterface_GetActiveCount, BackgroundProgressInterface_GetActiveCount_Offset) = BackgroundProgressInterface_GetActiveCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetHistoryEntries))
	{
		maxon::Tie(BackgroundProgressInterface_GetHistoryEntries, BackgroundProgressInterface_GetHistoryEntries_Offset) = BackgroundProgressInterface_GetHistoryEntries_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetHistoryCount))
	{
		maxon::Tie(BackgroundProgressInterface_GetHistoryCount, BackgroundProgressInterface_GetHistoryCount_Offset) = BackgroundProgressInterface_GetHistoryCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, RemoveHistoryEntry))
	{
		maxon::Tie(BackgroundProgressInterface_RemoveHistoryEntry, BackgroundProgressInterface_RemoveHistoryEntry_Offset) = BackgroundProgressInterface_RemoveHistoryEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ClearHistory))
	{
		maxon::Tie(BackgroundProgressInterface_ClearHistory, BackgroundProgressInterface_ClearHistory_Offset) = BackgroundProgressInterface_ClearHistory_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ObservableStateChanged))
	{
		maxon::Tie(BackgroundProgressInterface_ObservableStateChanged, BackgroundProgressInterface_ObservableStateChanged_Offset) = BackgroundProgressInterface_ObservableStateChanged_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ObservableTotalProgressNotification))
	{
		maxon::Tie(BackgroundProgressInterface_ObservableTotalProgressNotification, BackgroundProgressInterface_ObservableTotalProgressNotification_Offset) = BackgroundProgressInterface_ObservableTotalProgressNotification_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<BackgroundProgressInterface, typename BackgroundEntryInterface::MTable::template CombinedMTable<typename ProgressInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BackgroundProgressInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BackgroundProgressInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(BackgroundProgressInterface_GetMaster, GetMaster, MAXON_EXPAND_VA_ARGS, (BackgroundProgressRef));
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->BackgroundProgressInterface_GetMaster = BackgroundProgressInterface_GetMaster_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public BackgroundEntryInterface::Hxx2::template CWrapper<typename ProgressInterface::Hxx2::template CWrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddActiveEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ClearHistory);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetActiveCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetActiveEntries);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHistoryCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHistoryEntries);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableStateChanged);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableTotalProgressNotification);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveActiveEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveHistoryEntry);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ProgressInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename BackgroundEntryInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BackgroundProgressInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BackgroundProgressInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static BackgroundProgressRef BackgroundProgressInterface_GetMaster() { return S::Implementation::GetMaster(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_AddActiveEntry, maxon::GenericComponent,, (Result<BackgroundProgressRef>), const String& title, Bool sendToHistory) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddActiveEntry(title, sendToHistory); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_RemoveActiveEntry, maxon::GenericComponent,, (Result<void>), const BackgroundProgressRef& entry) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveActiveEntry(entry); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_GetActiveEntries, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<const BackgroundProgressRef&>& entry) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetActiveEntries(entry); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_GetActiveCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetActiveCount(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_GetHistoryEntries, maxon::GenericComponent, const, (Result<Bool>), const ValueReceiver<const BackgroundEntryRef&>& entry) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHistoryEntries(entry); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_GetHistoryCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHistoryCount(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_RemoveHistoryEntry, maxon::GenericComponent,, (Result<void>), const BackgroundEntryRef& entry) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveHistoryEntry(entry); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_ClearHistory, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ClearHistory(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_ObservableStateChanged, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableStateChangedDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableStateChanged(create); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_ObservableTotalProgressNotification, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableTotalProgressNotification(create); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetMaster() -> BackgroundProgressRef
{
	return Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::AddActiveEntry(const String& title, Bool sendToHistory) -> Result<BackgroundProgressRef>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), mt_.BackgroundProgressInterface_AddActiveEntry, title, sendToHistory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::RemoveActiveEntry(const BackgroundProgressRef& entry) -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), mt_.BackgroundProgressInterface_RemoveActiveEntry, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const -> Result<Bool>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetActiveEntries_Offset), mt_.BackgroundProgressInterface_GetActiveEntries, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetActiveCount() const -> Int
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetActiveCount_Offset), mt_.BackgroundProgressInterface_GetActiveCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const -> Result<Bool>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset), mt_.BackgroundProgressInterface_GetHistoryEntries, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetHistoryCount() const -> Int
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetHistoryCount_Offset), mt_.BackgroundProgressInterface_GetHistoryCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::RemoveHistoryEntry(const BackgroundEntryRef& entry) -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), mt_.BackgroundProgressInterface_RemoveHistoryEntry, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ClearHistory() -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ClearHistory_Offset), mt_.BackgroundProgressInterface_ClearHistory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableStateChanged(Bool create) const -> maxon::ObservableRef<ObservableStateChangedDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset), mt_.BackgroundProgressInterface_ObservableStateChanged, create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableTotalProgressNotification(Bool create) const -> maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset), mt_.BackgroundProgressInterface_ObservableTotalProgressNotification, create);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetMaster() -> BackgroundProgressRef
{
	return (Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::AddActiveEntry(const String& title, Bool sendToHistory) const -> Result<BackgroundProgressRef>
{
	HXXRETURN0(Result<BackgroundProgressRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_AddActiveEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), mt_.BackgroundProgressInterface_AddActiveEntry, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::AddActiveEntry(const String& title, Bool sendToHistory) -> Result<BackgroundProgressRef>
{
	HXXRETURN0(Result<BackgroundProgressRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundProgressInterface_AddActiveEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), mt_.BackgroundProgressInterface_AddActiveEntry, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_RemoveActiveEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), mt_.BackgroundProgressInterface_RemoveActiveEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundProgressInterface_RemoveActiveEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), mt_.BackgroundProgressInterface_RemoveActiveEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_GetActiveEntries); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveEntries_Offset), mt_.BackgroundProgressInterface_GetActiveEntries, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(BackgroundProgressInterface_GetActiveCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveCount_Offset), mt_.BackgroundProgressInterface_GetActiveCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_GetHistoryEntries); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset), mt_.BackgroundProgressInterface_GetHistoryEntries, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(BackgroundProgressInterface_GetHistoryCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryCount_Offset), mt_.BackgroundProgressInterface_GetHistoryCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_RemoveHistoryEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), mt_.BackgroundProgressInterface_RemoveHistoryEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundProgressInterface_RemoveHistoryEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), mt_.BackgroundProgressInterface_RemoveHistoryEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::ClearHistory() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BackgroundProgressInterface_ClearHistory); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset), mt_.BackgroundProgressInterface_ClearHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::ClearHistory() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BackgroundProgressInterface_ClearHistory); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset), mt_.BackgroundProgressInterface_ClearHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableStateChanged(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableStateChangedDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableStateChangedDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableStateChangedDelegate>::DefaultValue()) HXXTABLE(BackgroundProgressInterface_ObservableStateChanged); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset), mt_.BackgroundProgressInterface_ObservableStateChanged, create));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableTotalProgressNotification(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>::DefaultValue()) HXXTABLE(BackgroundProgressInterface_ObservableTotalProgressNotification); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset), mt_.BackgroundProgressInterface_ObservableTotalProgressNotification, create));
}
auto BackgroundProgressInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BackgroundProgressInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_backgroundentry)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BackgroundProgressInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BackgroundProgressInterface() { new (s_ui_maxon_BackgroundProgressInterface) maxon::EntityUse(BackgroundProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BackgroundProgressInterface(BackgroundProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_backgroundentry)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_BackgroundProgressInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_BackgroundProgressInterface() { new (s_usi_maxon_BackgroundProgressInterface) maxon::EntityUse(BackgroundProgressInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_BackgroundProgressInterface(BackgroundProgressInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/backgroundentry.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

