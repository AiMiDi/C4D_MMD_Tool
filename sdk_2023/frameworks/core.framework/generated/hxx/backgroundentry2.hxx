
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

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetName_Offset), mt_.BackgroundEntryInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStartTime() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UniversalDateTime>, UniversalDateTime>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UniversalDateTime>, UniversalDateTime>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<UniversalDateTime>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStartTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStartTime_Offset), mt_.BackgroundEntryInterface_GetStartTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetDuration() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetDuration) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetDuration_Offset), mt_.BackgroundEntryInterface_GetDuration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<STATE>, STATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<STATE>, STATE>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<STATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset), mt_.BackgroundEntryInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::GetState() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), STATE, maxon::Result<STATE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), STATE, maxon::Result<STATE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetState_Offset), mt_.BackgroundEntryInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStates(const ValueReceiver<STATE, const String&>& state) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStates) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStates_Offset), mt_.BackgroundEntryInterface_GetStates, state));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::ConstFn<S>::GetStateCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundEntryInterface* o_ = (const BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundEntryInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_GetStateCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_GetStateCount_Offset), mt_.BackgroundEntryInterface_GetStateCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::Fn<S>::AddState(STATE state, const String& message) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_AddState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundEntryInterface_AddState_Offset), mt_.BackgroundEntryInterface_AddState, state, message));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundEntryInterface::Hxx1::COWFn<S>::AddState(STATE state, const String& message) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundEntryInterface* o_ = (BackgroundEntryInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundEntryInterface, o_, BackgroundEntryInterface_AddState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundEntryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundEntryInterface>() : PRIVATE_MAXON_VTABLE(BackgroundEntryInterface, o_); 
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
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_ObservableStateChanged, ObservableStateChanged, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableStateChangedDelegate>));
	maxon::Int BackgroundProgressInterface_ObservableStateChanged_Offset;
	PRIVATE_MAXON_MF_POINTER(BackgroundProgressInterface_ObservableTotalProgressNotification, ObservableTotalProgressNotification, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>));
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
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_ObservableStateChanged, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableStateChangedDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableStateChanged(); }
		PRIVATE_MAXON_MF_WRAPPER(BackgroundProgressInterface_ObservableTotalProgressNotification, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableTotalProgressNotification(); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableStateChanged() const -> maxon::ObservableRef<ObservableStateChangedDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset), mt_.BackgroundProgressInterface_ObservableStateChanged);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::ObservableTotalProgressNotification() const -> maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>
{
	const BackgroundProgressInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset), mt_.BackgroundProgressInterface_ObservableTotalProgressNotification);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetMaster() -> BackgroundProgressRef
{
	return (Hxx2::StaticMTable::_instance.BackgroundProgressInterface_GetMaster());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::AddActiveEntry(const String& title, Bool sendToHistory) const -> Result<BackgroundProgressRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BackgroundProgressRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_AddActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), mt_.BackgroundProgressInterface_AddActiveEntry, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::AddActiveEntry(const String& title, Bool sendToHistory) -> Result<BackgroundProgressRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BackgroundProgressRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_AddActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_AddActiveEntry_Offset), mt_.BackgroundProgressInterface_AddActiveEntry, title, sendToHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), mt_.BackgroundProgressInterface_RemoveActiveEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveActiveEntry(const BackgroundProgressRef& entry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveActiveEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveActiveEntry_Offset), mt_.BackgroundProgressInterface_RemoveActiveEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetActiveEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveEntries_Offset), mt_.BackgroundProgressInterface_GetActiveEntries, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetActiveCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetActiveCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetActiveCount_Offset), mt_.BackgroundProgressInterface_GetActiveCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetHistoryEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryEntries_Offset), mt_.BackgroundProgressInterface_GetHistoryEntries, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::GetHistoryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_GetHistoryCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_GetHistoryCount_Offset), mt_.BackgroundProgressInterface_GetHistoryCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveHistoryEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), mt_.BackgroundProgressInterface_RemoveHistoryEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::RemoveHistoryEntry(const BackgroundEntryRef& entry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_RemoveHistoryEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_RemoveHistoryEntry_Offset), mt_.BackgroundProgressInterface_RemoveHistoryEntry, entry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::Fn<S>::ClearHistory() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ClearHistory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset), mt_.BackgroundProgressInterface_ClearHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::COWFn<S>::ClearHistory() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BackgroundProgressInterface* o_ = (BackgroundProgressInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ClearHistory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ClearHistory_Offset), mt_.BackgroundProgressInterface_ClearHistory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableStateChanged() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableStateChangedDelegate>>, maxon::ObservableRef<ObservableStateChangedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableStateChangedDelegate>>, maxon::ObservableRef<ObservableStateChangedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableStateChangedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ObservableStateChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableStateChanged_Offset), mt_.BackgroundProgressInterface_ObservableStateChanged));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BackgroundProgressInterface::Hxx1::ConstFn<S>::ObservableTotalProgressNotification() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>, maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>, maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BackgroundProgressInterface* o_ = (const BackgroundProgressInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BackgroundProgressInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BackgroundProgressInterface, o_, BackgroundProgressInterface_ObservableTotalProgressNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BackgroundProgressInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BackgroundProgressInterface>() : PRIVATE_MAXON_VTABLE(BackgroundProgressInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BackgroundProgressInterface_ObservableTotalProgressNotification_Offset), mt_.BackgroundProgressInterface_ObservableTotalProgressNotification));
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

