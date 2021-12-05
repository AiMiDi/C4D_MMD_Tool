
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaSessionProgressInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddProgressJob);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableProgressNotification);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetProgressAndCheckBreak);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_MediaSessionProgressInterface_InitProgress) (maxon::GenericComponent* this_, const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);
	maxon::Int _MediaSessionProgressInterface_InitProgress_Offset;
	Result<Int> (*_MediaSessionProgressInterface_AddProgressJob) (maxon::GenericComponent* this_, const Float jobWeight, const String& jobName);
	maxon::Int _MediaSessionProgressInterface_AddProgressJob_Offset;
	Result<void> (*_MediaSessionProgressInterface_SetProgressAndCheckBreak) (maxon::GenericComponent* this_, Int jobIndex, Float percent);
	maxon::Int _MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset;
	maxon::ObservableRef<ObservableProgressNotificationDelegate> (*_MediaSessionProgressInterface_ObservableProgressNotification) (const maxon::GenericComponent* this_);
	maxon::Int _MediaSessionProgressInterface_ObservableProgressNotification_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, InitProgress))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, InitProgress), W, MTable>::type::_MediaSessionProgressInterface_InitProgress;
			_MediaSessionProgressInterface_InitProgress = reinterpret_cast<const decltype(_MediaSessionProgressInterface_InitProgress)&>(ptr);
			_MediaSessionProgressInterface_InitProgress_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, AddProgressJob))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, AddProgressJob), W, MTable>::type::_MediaSessionProgressInterface_AddProgressJob;
			_MediaSessionProgressInterface_AddProgressJob = reinterpret_cast<const decltype(_MediaSessionProgressInterface_AddProgressJob)&>(ptr);
			_MediaSessionProgressInterface_AddProgressJob_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, SetProgressAndCheckBreak))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, SetProgressAndCheckBreak), W, MTable>::type::_MediaSessionProgressInterface_SetProgressAndCheckBreak;
			_MediaSessionProgressInterface_SetProgressAndCheckBreak = reinterpret_cast<const decltype(_MediaSessionProgressInterface_SetProgressAndCheckBreak)&>(ptr);
			_MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, ObservableProgressNotification))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionProgressInterface, ObservableProgressNotification), W, MTable>::type::_MediaSessionProgressInterface_ObservableProgressNotification;
			_MediaSessionProgressInterface_ObservableProgressNotification = reinterpret_cast<const decltype(_MediaSessionProgressInterface_ObservableProgressNotification)&>(ptr);
			_MediaSessionProgressInterface_ObservableProgressNotification_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaSessionProgressInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MediaSessionProgressInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionProgressInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddProgressJob);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableProgressNotification);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetProgressAndCheckBreak);
	static Result<void> _MediaSessionProgressInterface_InitProgress(maxon::GenericComponent* this_, const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) { return ((typename S::Implementation*) this_)->InitProgress(delayFirstProgress, minProgressUpdate); }
	static Result<Int> _MediaSessionProgressInterface_AddProgressJob(maxon::GenericComponent* this_, const Float jobWeight, const String& jobName) { return ((typename S::Implementation*) this_)->AddProgressJob(jobWeight, jobName); }
	static Result<void> _MediaSessionProgressInterface_SetProgressAndCheckBreak(maxon::GenericComponent* this_, Int jobIndex, Float percent) { return ((typename S::Implementation*) this_)->SetProgressAndCheckBreak(jobIndex, percent); }
	static maxon::ObservableRef<ObservableProgressNotificationDelegate> _MediaSessionProgressInterface_ObservableProgressNotification(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableProgressNotification(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	const MediaSessionProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, this); return mt_._MediaSessionProgressInterface_InitProgress((maxon::GenericComponent*) this + mt_._MediaSessionProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::AddProgressJob(const Float jobWeight, const String& jobName) -> Result<Int>
{
	const MediaSessionProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, this); return mt_._MediaSessionProgressInterface_AddProgressJob((maxon::GenericComponent*) this + mt_._MediaSessionProgressInterface_AddProgressJob_Offset, jobWeight, jobName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	const MediaSessionProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, this); return mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak((maxon::GenericComponent*) this + mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::ObservableProgressNotification() const -> maxon::ObservableRef<ObservableProgressNotificationDelegate>
{
	const MediaSessionProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, this); return mt_._MediaSessionProgressInterface_ObservableProgressNotification((const maxon::GenericComponent*) this + mt_._MediaSessionProgressInterface_ObservableProgressNotification_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::ReferenceFunctionsImpl<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_InitProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_InitProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_InitProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_InitProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_InitProgress_Offset, delayFirstProgress, minProgressUpdate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::ReferenceFunctionsImpl<S>::AddProgressJob(const Float jobWeight, const String& jobName) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_AddProgressJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_AddProgressJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_AddProgressJob_Offset, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddProgressJob(const Float jobWeight, const String& jobName) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_AddProgressJob) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_AddProgressJob(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_AddProgressJob_Offset, jobWeight, jobName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::ReferenceFunctionsImpl<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_SetProgressAndCheckBreak) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetProgressAndCheckBreak(Int jobIndex, Float percent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionProgressInterface* o_ = (MediaSessionProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_SetProgressAndCheckBreak) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_SetProgressAndCheckBreak_Offset, jobIndex, percent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionProgressInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableProgressNotification() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProgressNotificationDelegate>>, maxon::ObservableRef<ObservableProgressNotificationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProgressNotificationDelegate>>, maxon::ObservableRef<ObservableProgressNotificationDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaSessionProgressInterface* o_ = (const MediaSessionProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaSessionProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableProgressNotificationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionProgressInterface, o_, MediaSessionProgressInterface_ObservableProgressNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionProgressInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionProgressInterface, o_); 
	return (mt_._MediaSessionProgressInterface_ObservableProgressNotification(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaSessionProgressInterface_ObservableProgressNotification_Offset));
}
auto MediaSessionProgressInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionProgressInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaSessionProgressInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaSessionProgressInterface() { new (s_ui_maxon_MediaSessionProgressInterface) maxon::EntityUse(MediaSessionProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_progress.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaSessionProgressInterface(MediaSessionProgressInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_progress.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

