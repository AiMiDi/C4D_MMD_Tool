
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
	String (*BackgroundEntryInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundEntryInterface_GetName_Offset;
	UniversalDateTime (*BackgroundEntryInterface_GetStartTime) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundEntryInterface_GetStartTime_Offset;
	TimeValue (*BackgroundEntryInterface_GetDuration) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundEntryInterface_GetDuration_Offset;
	STATE (*BackgroundEntryInterface_GetState) (maxon::GenericComponent* this_);
	maxon::Int BackgroundEntryInterface_GetState_Offset;
	Result<Bool> (*BackgroundEntryInterface_GetStates) (const maxon::GenericComponent* this_, const ValueReceiver<STATE, const String&>& state);
	maxon::Int BackgroundEntryInterface_GetStates_Offset;
	Int (*BackgroundEntryInterface_GetStateCount) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundEntryInterface_GetStateCount_Offset;
	Result<void> (*BackgroundEntryInterface_AddState) (maxon::GenericComponent* this_, STATE state, const String& message);
	maxon::Int BackgroundEntryInterface_AddState_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetName))
	{
		BackgroundEntryInterface_GetName = &W::BackgroundEntryInterface_GetName;
		BackgroundEntryInterface_GetName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStartTime))
	{
		BackgroundEntryInterface_GetStartTime = &W::BackgroundEntryInterface_GetStartTime;
		BackgroundEntryInterface_GetStartTime_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetDuration))
	{
		BackgroundEntryInterface_GetDuration = &W::BackgroundEntryInterface_GetDuration;
		BackgroundEntryInterface_GetDuration_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetState))
	{
		BackgroundEntryInterface_GetState = &W::BackgroundEntryInterface_GetState;
		BackgroundEntryInterface_GetState_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStates))
	{
		BackgroundEntryInterface_GetStates = &W::BackgroundEntryInterface_GetStates;
		BackgroundEntryInterface_GetStates_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, GetStateCount))
	{
		BackgroundEntryInterface_GetStateCount = &W::BackgroundEntryInterface_GetStateCount;
		BackgroundEntryInterface_GetStateCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundEntryInterface, AddState))
	{
		BackgroundEntryInterface_AddState = &W::BackgroundEntryInterface_AddState;
		BackgroundEntryInterface_AddState_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BackgroundEntryInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (BackgroundEntryInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BackgroundEntryInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static String BackgroundEntryInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
		static UniversalDateTime BackgroundEntryInterface_GetStartTime(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStartTime(); }
		static TimeValue BackgroundEntryInterface_GetDuration(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDuration(); }
		static STATE BackgroundEntryInterface_GetState(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetState(); }
		static Result<Bool> BackgroundEntryInterface_GetStates(const maxon::GenericComponent* this_, const ValueReceiver<STATE, const String&>& state) { return ((const typename S::Implementation*) this_)->GetStates(state); }
		static Int BackgroundEntryInterface_GetStateCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStateCount(); }
		static Result<void> BackgroundEntryInterface_AddState(maxon::GenericComponent* this_, STATE state, const String& message) { return ((typename S::Implementation*) this_)->AddState(state, message); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetName() const -> String
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetName((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStartTime() const -> UniversalDateTime
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetStartTime((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStartTime_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetDuration() const -> TimeValue
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetDuration((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetDuration_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetState() -> STATE
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetState((maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetState_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStates(const ValueReceiver<STATE, const String&>& state) const -> Result<Bool>
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetStates((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStates_Offset, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::GetStateCount() const -> Int
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_GetStateCount((const maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_GetStateCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::AddState(STATE state, const String& message) -> Result<void>
{
	const BackgroundEntryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, this); return mt_.BackgroundEntryInterface_AddState((maxon::GenericComponent*) this + mt_.BackgroundEntryInterface_AddState_Offset, state, message);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStartTime() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UniversalDateTime>, UniversalDateTime>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UniversalDateTime>, UniversalDateTime>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<UniversalDateTime>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStartTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetStartTime(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStartTime_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetDuration() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetDuration) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetDuration(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetDuration_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<STATE>, STATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<STATE>, STATE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<STATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::GetState() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), STATE, maxon::Result<STATE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), STATE, maxon::Result<STATE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStates(const ValueReceiver<STATE, const String&>& state) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStates) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetStates(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStates_Offset, state));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStateCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStateCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_GetStateCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStateCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::AddState(STATE state, const String& message) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_AddState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_AddState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset, state, message));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::AddState(STATE state, const String& message) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_AddState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (mt_.BackgroundEntryInterface_AddState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset, state, message));
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
	Result<BackgroundProgressRef> (*BackgroundProgressInterface_AddActiveEntry) (maxon::GenericComponent* this_, const String& title, Bool sendToHistory);
	maxon::Int BackgroundProgressInterface_AddActiveEntry_Offset;
	Result<void> (*BackgroundProgressInterface_RemoveActiveEntry) (maxon::GenericComponent* this_, const BackgroundProgressRef& entry);
	maxon::Int BackgroundProgressInterface_RemoveActiveEntry_Offset;
	Result<Bool> (*BackgroundProgressInterface_GetActiveEntries) (const maxon::GenericComponent* this_, const ValueReceiver<const BackgroundProgressRef&>& entry);
	maxon::Int BackgroundProgressInterface_GetActiveEntries_Offset;
	Int (*BackgroundProgressInterface_GetActiveCount) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundProgressInterface_GetActiveCount_Offset;
	Result<Bool> (*BackgroundProgressInterface_GetHistoryEntries) (const maxon::GenericComponent* this_, const ValueReceiver<const BackgroundEntryRef&>& entry);
	maxon::Int BackgroundProgressInterface_GetHistoryEntries_Offset;
	Int (*BackgroundProgressInterface_GetHistoryCount) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundProgressInterface_GetHistoryCount_Offset;
	Result<void> (*BackgroundProgressInterface_RemoveHistoryEntry) (maxon::GenericComponent* this_, const BackgroundEntryRef& entry);
	maxon::Int BackgroundProgressInterface_RemoveHistoryEntry_Offset;
	Result<void> (*BackgroundProgressInterface_ClearHistory) (maxon::GenericComponent* this_);
	maxon::Int BackgroundProgressInterface_ClearHistory_Offset;
	maxon::ObservableRef<ObservableStateChangedDelegate> (*BackgroundProgressInterface_ObservableStateChanged) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundProgressInterface_ObservableStateChanged_Offset;
	maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> (*BackgroundProgressInterface_ObservableTotalProgressNotification) (const maxon::GenericComponent* this_);
	maxon::Int BackgroundProgressInterface_ObservableTotalProgressNotification_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, AddActiveEntry))
	{
		BackgroundProgressInterface_AddActiveEntry = &W::BackgroundProgressInterface_AddActiveEntry;
		BackgroundProgressInterface_AddActiveEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, RemoveActiveEntry))
	{
		BackgroundProgressInterface_RemoveActiveEntry = &W::BackgroundProgressInterface_RemoveActiveEntry;
		BackgroundProgressInterface_RemoveActiveEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetActiveEntries))
	{
		BackgroundProgressInterface_GetActiveEntries = &W::BackgroundProgressInterface_GetActiveEntries;
		BackgroundProgressInterface_GetActiveEntries_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetActiveCount))
	{
		BackgroundProgressInterface_GetActiveCount = &W::BackgroundProgressInterface_GetActiveCount;
		BackgroundProgressInterface_GetActiveCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetHistoryEntries))
	{
		BackgroundProgressInterface_GetHistoryEntries = &W::BackgroundProgressInterface_GetHistoryEntries;
		BackgroundProgressInterface_GetHistoryEntries_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, GetHistoryCount))
	{
		BackgroundProgressInterface_GetHistoryCount = &W::BackgroundProgressInterface_GetHistoryCount;
		BackgroundProgressInterface_GetHistoryCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, RemoveHistoryEntry))
	{
		BackgroundProgressInterface_RemoveHistoryEntry = &W::BackgroundProgressInterface_RemoveHistoryEntry;
		BackgroundProgressInterface_RemoveHistoryEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ClearHistory))
	{
		BackgroundProgressInterface_ClearHistory = &W::BackgroundProgressInterface_ClearHistory;
		BackgroundProgressInterface_ClearHistory_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ObservableStateChanged))
	{
		BackgroundProgressInterface_ObservableStateChanged = &W::BackgroundProgressInterface_ObservableStateChanged;
		BackgroundProgressInterface_ObservableStateChanged_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BackgroundProgressInterface, ObservableTotalProgressNotification))
	{
		BackgroundProgressInterface_ObservableTotalProgressNotification = &W::BackgroundProgressInterface_ObservableTotalProgressNotification;
		BackgroundProgressInterface_ObservableTotalProgressNotification_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BackgroundProgressInterface, typename BackgroundEntryInterface::MTable::template CombinedMTable<typename ProgressInterface::MTable::template CombinedMTable<S>>>;
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
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	BackgroundProgressRef (*BackgroundProgressInterface_GetMaster) ();
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->BackgroundProgressInterface_GetMaster = &IMPL::BackgroundProgressInterface_GetMaster;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (BackgroundProgressInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BackgroundProgressInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static BackgroundProgressRef BackgroundProgressInterface_GetMaster() { return S::Implementation::GetMaster(); }
		static Result<BackgroundProgressRef> BackgroundProgressInterface_AddActiveEntry(maxon::GenericComponent* this_, const String& title, Bool sendToHistory) { return ((typename S::Implementation*) this_)->AddActiveEntry(title, sendToHistory); }
		static Result<void> BackgroundProgressInterface_RemoveActiveEntry(maxon::GenericComponent* this_, const BackgroundProgressRef& entry) { return ((typename S::Implementation*) this_)->RemoveActiveEntry(entry); }
		static Result<Bool> BackgroundProgressInterface_GetActiveEntries(const maxon::GenericComponent* this_, const ValueReceiver<const BackgroundProgressRef&>& entry) { return ((const typename S::Implementation*) this_)->GetActiveEntries(entry); }
		static Int BackgroundProgressInterface_GetActiveCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetActiveCount(); }
		static Result<Bool> BackgroundProgressInterface_GetHistoryEntries(const maxon::GenericComponent* this_, const ValueReceiver<const BackgroundEntryRef&>& entry) { return ((const typename S::Implementation*) this_)->GetHistoryEntries(entry); }
		static Int BackgroundProgressInterface_GetHistoryCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHistoryCount(); }
		static Result<void> BackgroundProgressInterface_RemoveHistoryEntry(maxon::GenericComponent* this_, const BackgroundEntryRef& entry) { return ((typename S::Implementation*) this_)->RemoveHistoryEntry(entry); }
		static Result<void> BackgroundProgressInterface_ClearHistory(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->ClearHistory(); }
		static maxon::ObservableRef<ObservableStateChangedDelegate> BackgroundProgressInterface_ObservableStateChanged(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableStateChanged(); }
		static maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> BackgroundProgressInterface_ObservableTotalProgressNotification(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableTotalProgressNotification(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetMaster() -> BackgroundProgressRef
{
	return Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::AddActiveEntry(const String& title, Bool sendToHistory) -> Result<BackgroundProgressRef>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_AddActiveEntry((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_AddActiveEntry_Offset, title, sendToHistory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::RemoveActiveEntry(const BackgroundProgressRef& entry) -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_RemoveActiveEntry((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const -> Result<Bool>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_GetActiveEntries((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetActiveEntries_Offset, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetActiveCount() const -> Int
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_GetActiveCount((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetActiveCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const -> Result<Bool>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_GetHistoryEntries((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::GetHistoryCount() const -> Int
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_GetHistoryCount((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_GetHistoryCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::RemoveHistoryEntry(const BackgroundEntryRef& entry) -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_RemoveHistoryEntry((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ClearHistory() -> Result<void>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_ClearHistory((maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ClearHistory_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableStateChanged() const -> maxon::ObservableRef<ObservableStateChangedDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_ObservableStateChanged((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableTotalProgressNotification() const -> maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return mt_.BackgroundProgressInterface_ObservableTotalProgressNotification((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetMaster() -> BackgroundProgressRef
{
	return (Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::AddActiveEntry(const String& title, Bool sendToHistory) const -> Result<BackgroundProgressRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BackgroundProgressRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_AddActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_AddActiveEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::AddActiveEntry(const String& title, Bool sendToHistory) -> Result<BackgroundProgressRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BackgroundProgressRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_AddActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_AddActiveEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_RemoveActiveEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_RemoveActiveEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetActiveEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_GetActiveEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveEntries_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetActiveCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_GetActiveCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetHistoryEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_GetHistoryEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetHistoryCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_GetHistoryCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveHistoryEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_RemoveHistoryEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveHistoryEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_RemoveHistoryEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::ClearHistory() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ClearHistory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_ClearHistory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::ClearHistory() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ClearHistory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_ClearHistory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableStateChanged() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableStateChangedDelegate>>, maxon::ObservableRef<ObservableStateChangedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableStateChangedDelegate>>, maxon::ObservableRef<ObservableStateChangedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableStateChangedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ObservableStateChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_ObservableStateChanged(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableTotalProgressNotification() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>, maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>, maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ObservableTotalProgressNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (mt_.BackgroundProgressInterface_ObservableTotalProgressNotification(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset));
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

