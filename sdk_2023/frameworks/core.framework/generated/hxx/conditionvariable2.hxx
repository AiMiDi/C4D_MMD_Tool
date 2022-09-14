
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ConditionVariableInterface::PrivateGetCppName() { return "maxon::ConditionVariableRef"; }

struct ConditionVariableInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(ConditionVariableInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ConditionVariableInterface* object);
	PRIVATE_MAXON_SF_POINTER(ConditionVariableInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (ConditionVariableInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(ConditionVariableInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (ConditionVariableInterface*), const maxon::SourceLocation& allocLocation, Bool isAutoClear);
	PRIVATE_MAXON_MF_POINTER(ConditionVariableInterface_Clear, Clear, false, ConditionVariableInterface,, (void), Int32 dependencyCnt);
	PRIVATE_MAXON_MF_POINTER(ConditionVariableInterface_AddDependency, AddDependency, false, ConditionVariableInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(ConditionVariableInterface_Set, Set, false, ConditionVariableInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(ConditionVariableInterface_Wait, Wait, false, ConditionVariableInterface, const, (Bool), const TimeValue& timeout, WAITMODE mode);
	PRIVATE_MAXON_MF_POINTER(ConditionVariableInterface_PrivateAddFinishedObserver, PrivateAddFinishedObserver, false, ConditionVariableInterface,, (Result<void>), const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	template <typename IMPL> void Init()
	{
		ConditionVariableInterface_Free = ConditionVariableInterface_Free_GetPtr<IMPL>(true);
		ConditionVariableInterface_Alloc = ConditionVariableInterface_Alloc_GetPtr<IMPL>(true);
		ConditionVariableInterface_Alloc_1 = ConditionVariableInterface_Alloc_1_GetPtr<IMPL>(true);
		ConditionVariableInterface_Clear = ConditionVariableInterface_Clear_GetPtr<IMPL>(0, true).first;
		ConditionVariableInterface_AddDependency = ConditionVariableInterface_AddDependency_GetPtr<IMPL>(0, true).first;
		ConditionVariableInterface_Set = ConditionVariableInterface_Set_GetPtr<IMPL>(0, true).first;
		ConditionVariableInterface_Wait = ConditionVariableInterface_Wait_GetPtr<IMPL>(0, true).first;
		ConditionVariableInterface_PrivateAddFinishedObserver = ConditionVariableInterface_PrivateAddFinishedObserver_GetPtr<IMPL>(0, true).first;
	}
};

struct ConditionVariableInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void ConditionVariableInterface_Free(const ConditionVariableInterface* object) { return C::Free(object); }
		static ConditionVariableInterface* ConditionVariableInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static ConditionVariableInterface* ConditionVariableInterface_Alloc_1(const maxon::SourceLocation& allocLocation, Bool isAutoClear) { return C::Alloc(allocLocation, isAutoClear); }
		PRIVATE_MAXON_MF_WRAPPER(ConditionVariableInterface_Clear, ConditionVariableInterface,, (void), Int32 dependencyCnt) { return C::Get(PRIVATE_MAXON_MF_THIS(ConditionVariableInterface))->Clear(dependencyCnt); }
		PRIVATE_MAXON_MF_WRAPPER(ConditionVariableInterface_AddDependency, ConditionVariableInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(ConditionVariableInterface))->AddDependency(); }
		PRIVATE_MAXON_MF_WRAPPER(ConditionVariableInterface_Set, ConditionVariableInterface,, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(ConditionVariableInterface))->Set(); }
		PRIVATE_MAXON_MF_WRAPPER(ConditionVariableInterface_Wait, ConditionVariableInterface, const, (Bool), const TimeValue& timeout, WAITMODE mode) { return C::Get(PRIVATE_MAXON_MF_THIS(const ConditionVariableInterface))->Wait(timeout, mode); }
		PRIVATE_MAXON_MF_WRAPPER(ConditionVariableInterface_PrivateAddFinishedObserver, ConditionVariableInterface,, (Result<void>), const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::Get(PRIVATE_MAXON_MF_THIS(ConditionVariableInterface))->PrivateAddFinishedObserver(observerPod, observerQueue); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Free(const ConditionVariableInterface* object) -> void
{
	return MTable::_instance.ConditionVariableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ConditionVariableInterface*
{
	return MTable::_instance.ConditionVariableInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Alloc(const maxon::SourceLocation& allocLocation, Bool isAutoClear) -> ConditionVariableInterface*
{
	return MTable::_instance.ConditionVariableInterface_Alloc_1(allocLocation, isAutoClear);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Clear(Int32 dependencyCnt) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConditionVariableInterface_Clear, dependencyCnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::AddDependency() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConditionVariableInterface_AddDependency);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Set() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConditionVariableInterface_Set);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Wait(const TimeValue& timeout, WAITMODE mode) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConditionVariableInterface_Wait, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConditionVariableInterface_PrivateAddFinishedObserver, observerPod, observerQueue);
}

auto ConditionVariableInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ConditionVariableRef>
{
	ConditionVariableInterface* res_ = ConditionVariableInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ConditionVariableRef(maxon::ForwardResultPtr<ConditionVariableInterface>(res_));
}
auto ConditionVariableInterface::Hxx1::Reference::Create(Bool isAutoClear) -> maxon::ResultMemT<ConditionVariableRef>
{
	ConditionVariableInterface* res_ = ConditionVariableInterface::Alloc(MAXON_SOURCE_LOCATION, isAutoClear);
	return ConditionVariableRef(maxon::ForwardResultPtr<ConditionVariableInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::Clear(Int32 dependencyCnt) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConditionVariableInterface_Clear, dependencyCnt);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::AddDependency() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConditionVariableInterface_AddDependency);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::Set() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConditionVariableInterface_Set));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ConstFn<S>::Wait(const TimeValue& timeout, WAITMODE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ConditionVariableInterface* o_ = (const ConditionVariableInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ConditionVariableInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConditionVariableInterface_Wait, timeout, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::ObservableFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ObservableFinishedBase<ConditionVariableInterface>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->ObservableFinished());
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_conditionvariable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ConditionVariableInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ConditionVariableInterface() { new (s_ui_maxon_ConditionVariableInterface) maxon::EntityUse(ConditionVariableInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/conditionvariable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ConditionVariableInterface(ConditionVariableInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/conditionvariable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

