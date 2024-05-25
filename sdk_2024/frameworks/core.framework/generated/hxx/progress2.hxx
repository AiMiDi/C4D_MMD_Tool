
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ProgressInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddProgressJob);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CancelJob);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDetailsText);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTotalWeight);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsCancelled);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableProgressNotification);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCancelJobDelegate);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetDetailsText);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetProgressAndCheckBreak);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportsCancelJob);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_InitProgress, InitProgress, true, maxon::GenericComponent,, (Result<void>), const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);
	maxon::Int ProgressInterface_InitProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_AddProgressJob, AddProgressJob, true, maxon::GenericComponent,, (Result<Int>), Float jobWeight, const String& jobName);
	maxon::Int ProgressInterface_AddProgressJob_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_SetProgressAndCheckBreak, SetProgressAndCheckBreak, true, maxon::GenericComponent,, (Result<void>), Int jobIndex, Float percent);
	maxon::Int ProgressInterface_SetProgressAndCheckBreak_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_GetProgress, GetProgress, true, maxon::GenericComponent,, (Result<Float>), Int jobIndex);
	maxon::Int ProgressInterface_GetProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_GetTotalWeight, GetTotalWeight, true, maxon::GenericComponent, const, (Float));
	maxon::Int ProgressInterface_GetTotalWeight_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_ObservableProgressNotification, ObservableProgressNotification, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableProgressNotificationDelegate>), Bool create);
	maxon::Int ProgressInterface_ObservableProgressNotification_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_GetTime, GetTime, true, maxon::GenericComponent, const, (Result<Tuple<TimeValue, TimeValue>>));
	maxon::Int ProgressInterface_GetTime_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_GetDetailsText, GetDetailsText, true, maxon::GenericComponent, const, (String));
	maxon::Int ProgressInterface_GetDetailsText_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_SetDetailsText, SetDetailsText, true, maxon::GenericComponent,, (void), const String& details);
	maxon::Int ProgressInterface_SetDetailsText_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_SupportsCancelJob, SupportsCancelJob, true, maxon::GenericComponent, const, (Bool));
	maxon::Int ProgressInterface_SupportsCancelJob_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_SetCancelJobDelegate, SetCancelJobDelegate, true, maxon::GenericComponent,, (Result<void>), JobCancelDelegate&& cancelJobDelegate);
	maxon::Int ProgressInterface_SetCancelJobDelegate_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_CancelJob, CancelJob, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int ProgressInterface_CancelJob_Offset;
	PRIVATE_MAXON_MF_POINTER(ProgressInterface_IsCancelled, IsCancelled, true, maxon::GenericComponent,, (Bool));
	maxon::Int ProgressInterface_IsCancelled_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, InitProgress))
	{
		maxon::Tie(ProgressInterface_InitProgress, ProgressInterface_InitProgress_Offset) = ProgressInterface_InitProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, AddProgressJob))
	{
		maxon::Tie(ProgressInterface_AddProgressJob, ProgressInterface_AddProgressJob_Offset) = ProgressInterface_AddProgressJob_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetProgressAndCheckBreak))
	{
		maxon::Tie(ProgressInterface_SetProgressAndCheckBreak, ProgressInterface_SetProgressAndCheckBreak_Offset) = ProgressInterface_SetProgressAndCheckBreak_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetProgress))
	{
		maxon::Tie(ProgressInterface_GetProgress, ProgressInterface_GetProgress_Offset) = ProgressInterface_GetProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetTotalWeight))
	{
		maxon::Tie(ProgressInterface_GetTotalWeight, ProgressInterface_GetTotalWeight_Offset) = ProgressInterface_GetTotalWeight_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, ObservableProgressNotification))
	{
		maxon::Tie(ProgressInterface_ObservableProgressNotification, ProgressInterface_ObservableProgressNotification_Offset) = ProgressInterface_ObservableProgressNotification_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetTime))
	{
		maxon::Tie(ProgressInterface_GetTime, ProgressInterface_GetTime_Offset) = ProgressInterface_GetTime_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetDetailsText))
	{
		maxon::Tie(ProgressInterface_GetDetailsText, ProgressInterface_GetDetailsText_Offset) = ProgressInterface_GetDetailsText_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetDetailsText))
	{
		maxon::Tie(ProgressInterface_SetDetailsText, ProgressInterface_SetDetailsText_Offset) = ProgressInterface_SetDetailsText_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SupportsCancelJob))
	{
		maxon::Tie(ProgressInterface_SupportsCancelJob, ProgressInterface_SupportsCancelJob_Offset) = ProgressInterface_SupportsCancelJob_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetCancelJobDelegate))
	{
		maxon::Tie(ProgressInterface_SetCancelJobDelegate, ProgressInterface_SetCancelJobDelegate_Offset) = ProgressInterface_SetCancelJobDelegate_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, CancelJob))
	{
		maxon::Tie(ProgressInterface_CancelJob, ProgressInterface_CancelJob_Offset) = ProgressInterface_CancelJob_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, IsCancelled))
	{
		maxon::Tie(ProgressInterface_IsCancelled, ProgressInterface_IsCancelled_Offset) = ProgressInterface_IsCancelled_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ProgressInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ProgressInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ProgressInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddProgressJob);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CancelJob);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDetailsText);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTotalWeight);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsCancelled);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableProgressNotification);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCancelJobDelegate);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetDetailsText);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetProgressAndCheckBreak);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportsCancelJob);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ProgressInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ProgressInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_InitProgress, maxon::GenericComponent,, (Result<void>), const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitProgress(delayFirstProgress, minProgressUpdate); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_AddProgressJob, maxon::GenericComponent,, (Result<Int>), Float jobWeight, const String& jobName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddProgressJob(jobWeight, jobName); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_SetProgressAndCheckBreak, maxon::GenericComponent,, (Result<void>), Int jobIndex, Float percent) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetProgressAndCheckBreak(jobIndex, percent); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_GetProgress, maxon::GenericComponent,, (Result<Float>), Int jobIndex) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetProgress(jobIndex); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_GetTotalWeight, maxon::GenericComponent, const, (Float)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTotalWeight(); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_ObservableProgressNotification, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableProgressNotificationDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableProgressNotification(create); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_GetTime, maxon::GenericComponent, const, (Result<Tuple<TimeValue, TimeValue>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTime(); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_GetDetailsText, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDetailsText(); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_SetDetailsText, maxon::GenericComponent,, (void), const String& details) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetDetailsText(details); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_SupportsCancelJob, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SupportsCancelJob(); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_SetCancelJobDelegate, maxon::GenericComponent,, (Result<void>), JobCancelDelegate&& cancelJobDelegate) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCancelJobDelegate(std::forward<JobCancelDelegate>(cancelJobDelegate)); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_CancelJob, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CancelJob(); }
		PRIVATE_MAXON_MF_WRAPPER(ProgressInterface_IsCancelled, maxon::GenericComponent,, (Bool)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IsCancelled(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_InitProgress_Offset), mt_.ProgressInterface_InitProgress, delayFirstProgress, minProgressUpdate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::AddProgressJob(Float jobWeight, const String& jobName) -> Result<Int>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_AddProgressJob_Offset), mt_.ProgressInterface_AddProgressJob, jobWeight, jobName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset), mt_.ProgressInterface_SetProgressAndCheckBreak, jobIndex, percent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetProgress(Int jobIndex) -> Result<Float>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_GetProgress_Offset), mt_.ProgressInterface_GetProgress, jobIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetTotalWeight() const -> Float
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetTotalWeight_Offset), mt_.ProgressInterface_GetTotalWeight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::ObservableProgressNotification(Bool create) const -> maxon::ObservableRef<ObservableProgressNotificationDelegate>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ProgressInterface_ObservableProgressNotification_Offset), mt_.ProgressInterface_ObservableProgressNotification, create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetTime() const -> Result<Tuple<TimeValue, TimeValue>>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetTime_Offset), mt_.ProgressInterface_GetTime);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetDetailsText() const -> String
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetDetailsText_Offset), mt_.ProgressInterface_GetDetailsText);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetDetailsText(const String& details) -> void
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_SetDetailsText_Offset), mt_.ProgressInterface_SetDetailsText, details);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SupportsCancelJob() const -> Bool
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ProgressInterface_SupportsCancelJob_Offset), mt_.ProgressInterface_SupportsCancelJob);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_SetCancelJobDelegate_Offset), mt_.ProgressInterface_SetCancelJobDelegate, std::forward<JobCancelDelegate>(cancelJobDelegate));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::CancelJob() -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_CancelJob_Offset), mt_.ProgressInterface_CancelJob);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::IsCancelled() -> Bool
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ProgressInterface_IsCancelled_Offset), mt_.ProgressInterface_IsCancelled);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_InitProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_InitProgress_Offset), mt_.ProgressInterface_InitProgress, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_InitProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_InitProgress_Offset), mt_.ProgressInterface_InitProgress, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::AddProgressJob(Float jobWeight, const String& jobName) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_AddProgressJob); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_AddProgressJob_Offset), mt_.ProgressInterface_AddProgressJob, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::AddProgressJob(Float jobWeight, const String& jobName) -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_AddProgressJob); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_AddProgressJob_Offset), mt_.ProgressInterface_AddProgressJob, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_SetProgressAndCheckBreak); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset), mt_.ProgressInterface_SetProgressAndCheckBreak, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_SetProgressAndCheckBreak); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset), mt_.ProgressInterface_SetProgressAndCheckBreak, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::GetProgress(Int jobIndex) const -> Result<Float>
{
	HXXRETURN0(Result<Float>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_GetProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetProgress_Offset), mt_.ProgressInterface_GetProgress, jobIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::GetProgress(Int jobIndex) -> Result<Float>
{
	HXXRETURN0(Result<Float>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_GetProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetProgress_Offset), mt_.ProgressInterface_GetProgress, jobIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetTotalWeight() const -> HXXADDRET2(Float)
{
	HXXRETURN0(HXXADDRET2(Float)); HXXRES; HXXCONST(0) HXXTABLE(ProgressInterface_GetTotalWeight); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTotalWeight_Offset), mt_.ProgressInterface_GetTotalWeight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::ObservableProgressNotification(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableProgressNotificationDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableProgressNotificationDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableProgressNotificationDelegate>::DefaultValue()) HXXTABLE(ProgressInterface_ObservableProgressNotification); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_ObservableProgressNotification_Offset), mt_.ProgressInterface_ObservableProgressNotification, create));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetTime() const -> Result<Tuple<TimeValue, TimeValue>>
{
	HXXRETURN0(Result<Tuple<TimeValue, TimeValue>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_GetTime); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTime_Offset), mt_.ProgressInterface_GetTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetDetailsText() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(ProgressInterface_GetDetailsText); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetDetailsText_Offset), mt_.ProgressInterface_GetDetailsText));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetDetailsText(const String& details) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ProgressInterface_SetDetailsText); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetDetailsText_Offset), mt_.ProgressInterface_SetDetailsText, details);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetDetailsText(const String& details) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_SetDetailsText); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetDetailsText_Offset), mt_.ProgressInterface_SetDetailsText, details);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::SupportsCancelJob() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(ProgressInterface_SupportsCancelJob); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SupportsCancelJob_Offset), mt_.ProgressInterface_SupportsCancelJob));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_SetCancelJobDelegate); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetCancelJobDelegate_Offset), mt_.ProgressInterface_SetCancelJobDelegate, std::forward<JobCancelDelegate>(cancelJobDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_SetCancelJobDelegate); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetCancelJobDelegate_Offset), mt_.ProgressInterface_SetCancelJobDelegate, std::forward<JobCancelDelegate>(cancelJobDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::CancelJob() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ProgressInterface_CancelJob); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_CancelJob_Offset), mt_.ProgressInterface_CancelJob));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::CancelJob() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_CancelJob); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_CancelJob_Offset), mt_.ProgressInterface_CancelJob));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::IsCancelled() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXNONCONST(, , false, maxon::PrivateLogNullptrError(false)) HXXTABLE(ProgressInterface_IsCancelled); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_IsCancelled_Offset), mt_.ProgressInterface_IsCancelled));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::IsCancelled() -> HXXADDRET1(Bool)
{
	HXXRETURN0(HXXADDRET1(Bool)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ProgressInterface_IsCancelled); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_IsCancelled_Offset), mt_.ProgressInterface_IsCancelled));
}
auto ProgressInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ProgressInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_progress)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ProgressInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ProgressInterface() { new (s_ui_maxon_ProgressInterface) maxon::EntityUse(ProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/progress.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ProgressInterface(ProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/progress.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

