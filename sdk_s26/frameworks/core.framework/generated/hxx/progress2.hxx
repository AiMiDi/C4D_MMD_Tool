
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
	Result<void> (*ProgressInterface_InitProgress) (maxon::GenericComponent* this_, const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);
	maxon::Int ProgressInterface_InitProgress_Offset;
	Result<Int> (*ProgressInterface_AddProgressJob) (maxon::GenericComponent* this_, const Float jobWeight, const String& jobName);
	maxon::Int ProgressInterface_AddProgressJob_Offset;
	Result<void> (*ProgressInterface_SetProgressAndCheckBreak) (maxon::GenericComponent* this_, Int jobIndex, Float percent);
	maxon::Int ProgressInterface_SetProgressAndCheckBreak_Offset;
	Result<Float> (*ProgressInterface_GetProgress) (maxon::GenericComponent* this_, Int jobIndex);
	maxon::Int ProgressInterface_GetProgress_Offset;
	Float (*ProgressInterface_GetTotalWeight) (const maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_GetTotalWeight_Offset;
	maxon::ObservableRef<ObservableProgressNotificationDelegate> (*ProgressInterface_ObservableProgressNotification) (const maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_ObservableProgressNotification_Offset;
	Result<Tuple<TimeValue, TimeValue>> (*ProgressInterface_GetTime) (const maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_GetTime_Offset;
	String (*ProgressInterface_GetDetailsText) (const maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_GetDetailsText_Offset;
	void (*ProgressInterface_SetDetailsText) (maxon::GenericComponent* this_, const String& details);
	maxon::Int ProgressInterface_SetDetailsText_Offset;
	Bool (*ProgressInterface_SupportsCancelJob) (const maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_SupportsCancelJob_Offset;
	Result<void> (*ProgressInterface_SetCancelJobDelegate) (maxon::GenericComponent* this_, JobCancelDelegate&& cancelJobDelegate);
	maxon::Int ProgressInterface_SetCancelJobDelegate_Offset;
	Result<void> (*ProgressInterface_CancelJob) (maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_CancelJob_Offset;
	Bool (*ProgressInterface_IsCancelled) (maxon::GenericComponent* this_);
	maxon::Int ProgressInterface_IsCancelled_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, InitProgress))
	{
		ProgressInterface_InitProgress = &W::ProgressInterface_InitProgress;
		ProgressInterface_InitProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, AddProgressJob))
	{
		ProgressInterface_AddProgressJob = &W::ProgressInterface_AddProgressJob;
		ProgressInterface_AddProgressJob_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetProgressAndCheckBreak))
	{
		ProgressInterface_SetProgressAndCheckBreak = &W::ProgressInterface_SetProgressAndCheckBreak;
		ProgressInterface_SetProgressAndCheckBreak_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetProgress))
	{
		ProgressInterface_GetProgress = &W::ProgressInterface_GetProgress;
		ProgressInterface_GetProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetTotalWeight))
	{
		ProgressInterface_GetTotalWeight = &W::ProgressInterface_GetTotalWeight;
		ProgressInterface_GetTotalWeight_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, ObservableProgressNotification))
	{
		ProgressInterface_ObservableProgressNotification = &W::ProgressInterface_ObservableProgressNotification;
		ProgressInterface_ObservableProgressNotification_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetTime))
	{
		ProgressInterface_GetTime = &W::ProgressInterface_GetTime;
		ProgressInterface_GetTime_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, GetDetailsText))
	{
		ProgressInterface_GetDetailsText = &W::ProgressInterface_GetDetailsText;
		ProgressInterface_GetDetailsText_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetDetailsText))
	{
		ProgressInterface_SetDetailsText = &W::ProgressInterface_SetDetailsText;
		ProgressInterface_SetDetailsText_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SupportsCancelJob))
	{
		ProgressInterface_SupportsCancelJob = &W::ProgressInterface_SupportsCancelJob;
		ProgressInterface_SupportsCancelJob_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, SetCancelJobDelegate))
	{
		ProgressInterface_SetCancelJobDelegate = &W::ProgressInterface_SetCancelJobDelegate;
		ProgressInterface_SetCancelJobDelegate_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, CancelJob))
	{
		ProgressInterface_CancelJob = &W::ProgressInterface_CancelJob;
		ProgressInterface_CancelJob_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ProgressInterface, IsCancelled))
	{
		ProgressInterface_IsCancelled = &W::ProgressInterface_IsCancelled;
		ProgressInterface_IsCancelled_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ProgressInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ProgressInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ProgressInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ProgressInterface_InitProgress(maxon::GenericComponent* this_, const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) { return ((typename S::Implementation*) this_)->InitProgress(delayFirstProgress, minProgressUpdate); }
		static Result<Int> ProgressInterface_AddProgressJob(maxon::GenericComponent* this_, const Float jobWeight, const String& jobName) { return ((typename S::Implementation*) this_)->AddProgressJob(jobWeight, jobName); }
		static Result<void> ProgressInterface_SetProgressAndCheckBreak(maxon::GenericComponent* this_, Int jobIndex, Float percent) { return ((typename S::Implementation*) this_)->SetProgressAndCheckBreak(jobIndex, percent); }
		static Result<Float> ProgressInterface_GetProgress(maxon::GenericComponent* this_, Int jobIndex) { return ((typename S::Implementation*) this_)->GetProgress(jobIndex); }
		static Float ProgressInterface_GetTotalWeight(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTotalWeight(); }
		static maxon::ObservableRef<ObservableProgressNotificationDelegate> ProgressInterface_ObservableProgressNotification(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableProgressNotification(); }
		static Result<Tuple<TimeValue, TimeValue>> ProgressInterface_GetTime(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTime(); }
		static String ProgressInterface_GetDetailsText(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDetailsText(); }
		static void ProgressInterface_SetDetailsText(maxon::GenericComponent* this_, const String& details) { return ((typename S::Implementation*) this_)->SetDetailsText(details); }
		static Bool ProgressInterface_SupportsCancelJob(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SupportsCancelJob(); }
		static Result<void> ProgressInterface_SetCancelJobDelegate(maxon::GenericComponent* this_, JobCancelDelegate&& cancelJobDelegate) { return ((typename S::Implementation*) this_)->SetCancelJobDelegate(std::forward<JobCancelDelegate>(cancelJobDelegate)); }
		static Result<void> ProgressInterface_CancelJob(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CancelJob(); }
		static Bool ProgressInterface_IsCancelled(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->IsCancelled(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_InitProgress((maxon::GenericComponent*) this + mt_.ProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::AddProgressJob(const Float jobWeight, const String& jobName) -> Result<Int>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_AddProgressJob((maxon::GenericComponent*) this + mt_.ProgressInterface_AddProgressJob_Offset, jobWeight, jobName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_SetProgressAndCheckBreak((maxon::GenericComponent*) this + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetProgress(Int jobIndex) -> Result<Float>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_GetProgress((maxon::GenericComponent*) this + mt_.ProgressInterface_GetProgress_Offset, jobIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetTotalWeight() const -> Float
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_GetTotalWeight((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetTotalWeight_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::ObservableProgressNotification() const -> maxon::ObservableRef<ObservableProgressNotificationDelegate>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_ObservableProgressNotification((const maxon::GenericComponent*) this + mt_.ProgressInterface_ObservableProgressNotification_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetTime() const -> Result<Tuple<TimeValue, TimeValue>>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_GetTime((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetTime_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::GetDetailsText() const -> String
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_GetDetailsText((const maxon::GenericComponent*) this + mt_.ProgressInterface_GetDetailsText_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetDetailsText(const String& details) -> void
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_SetDetailsText((maxon::GenericComponent*) this + mt_.ProgressInterface_SetDetailsText_Offset, details);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SupportsCancelJob() const -> Bool
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_SupportsCancelJob((const maxon::GenericComponent*) this + mt_.ProgressInterface_SupportsCancelJob_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_SetCancelJobDelegate((maxon::GenericComponent*) this + mt_.ProgressInterface_SetCancelJobDelegate_Offset, std::forward<JobCancelDelegate>(cancelJobDelegate));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::CancelJob() -> Result<void>
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_CancelJob((maxon::GenericComponent*) this + mt_.ProgressInterface_CancelJob_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::IsCancelled() -> Bool
{
	const ProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ProgressInterface, this); return mt_.ProgressInterface_IsCancelled((maxon::GenericComponent*) this + mt_.ProgressInterface_IsCancelled_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_InitProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_InitProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_InitProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_InitProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::AddProgressJob(const Float jobWeight, const String& jobName) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_AddProgressJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_AddProgressJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_AddProgressJob_Offset, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::AddProgressJob(const Float jobWeight, const String& jobName) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_AddProgressJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_AddProgressJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_AddProgressJob_Offset, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetProgressAndCheckBreak) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_SetProgressAndCheckBreak(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetProgressAndCheckBreak) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_SetProgressAndCheckBreak(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::GetProgress(Int jobIndex) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_GetProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetProgress_Offset, jobIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::GetProgress(Int jobIndex) -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_GetProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetProgress_Offset, jobIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetTotalWeight() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ProgressInterface* o_ = (const ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ProgressInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_GetTotalWeight) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_GetTotalWeight(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTotalWeight_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::ObservableProgressNotification() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProgressNotificationDelegate>>, maxon::ObservableRef<ObservableProgressNotificationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProgressNotificationDelegate>>, maxon::ObservableRef<ObservableProgressNotificationDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ProgressInterface* o_ = (const ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableProgressNotificationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_ObservableProgressNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_ObservableProgressNotification(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_ObservableProgressNotification_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetTime() const -> Result<Tuple<TimeValue, TimeValue>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<TimeValue, TimeValue>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ProgressInterface* o_ = (const ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_GetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_GetTime(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetTime_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::GetDetailsText() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ProgressInterface* o_ = (const ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_GetDetailsText) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_GetDetailsText(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_GetDetailsText_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetDetailsText(const String& details) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetDetailsText) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	mt_.ProgressInterface_SetDetailsText(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetDetailsText_Offset, details);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetDetailsText(const String& details) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetDetailsText) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	mt_.ProgressInterface_SetDetailsText(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetDetailsText_Offset, details);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::ConstFn<S>::SupportsCancelJob() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ProgressInterface* o_ = (const ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SupportsCancelJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_SupportsCancelJob(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SupportsCancelJob_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetCancelJobDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_SetCancelJobDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetCancelJobDelegate_Offset, std::forward<JobCancelDelegate>(cancelJobDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_SetCancelJobDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_SetCancelJobDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_SetCancelJobDelegate_Offset, std::forward<JobCancelDelegate>(cancelJobDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::CancelJob() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_CancelJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_CancelJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_CancelJob_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::CancelJob() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_CancelJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_CancelJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_CancelJob_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::Fn<S>::IsCancelled() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_IsCancelled) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_IsCancelled(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_IsCancelled_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ProgressInterface::Hxx1::COWFn<S>::IsCancelled() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ProgressInterface* o_ = (ProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ProgressInterface, o_, ProgressInterface_IsCancelled) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ProgressInterface>() : PRIVATE_MAXON_VTABLE(ProgressInterface, o_); 
	return (mt_.ProgressInterface_IsCancelled(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ProgressInterface_IsCancelled_Offset));
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

