
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
	void (*ConditionVariableInterface_Free) (const ConditionVariableInterface* object);
	ConditionVariableInterface* (*ConditionVariableInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	ConditionVariableInterface* (*ConditionVariableInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, Bool isAutoClear);
	void (*ConditionVariableInterface_Clear) (ConditionVariableInterface* this_, Int32 dependencyCnt);
	void (*ConditionVariableInterface_AddDependency) (ConditionVariableInterface* this_);
	Bool (*ConditionVariableInterface_Set) (ConditionVariableInterface* this_);
	Bool (*ConditionVariableInterface_Wait) (const ConditionVariableInterface* this_, const TimeValue& timeout, WAITMODE mode);
	Result<void> (*ConditionVariableInterface_PrivateAddFinishedObserver) (ConditionVariableInterface* this_, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	template <typename IMPL> void Init()
	{
		ConditionVariableInterface_Free = &IMPL::ConditionVariableInterface_Free;
		ConditionVariableInterface_Alloc = &IMPL::ConditionVariableInterface_Alloc;
		ConditionVariableInterface_Alloc_1 = &IMPL::ConditionVariableInterface_Alloc_1;
		ConditionVariableInterface_Clear = &IMPL::ConditionVariableInterface_Clear;
		ConditionVariableInterface_AddDependency = &IMPL::ConditionVariableInterface_AddDependency;
		ConditionVariableInterface_Set = &IMPL::ConditionVariableInterface_Set;
		ConditionVariableInterface_Wait = &IMPL::ConditionVariableInterface_Wait;
		ConditionVariableInterface_PrivateAddFinishedObserver = &IMPL::ConditionVariableInterface_PrivateAddFinishedObserver;
	}
};

struct ConditionVariableInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ConditionVariableInterface_Free(const ConditionVariableInterface* object) { return C::Free(object); }
		static ConditionVariableInterface* ConditionVariableInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static ConditionVariableInterface* ConditionVariableInterface_Alloc_1(const maxon::SourceLocation& allocLocation, Bool isAutoClear) { return C::Alloc(allocLocation, isAutoClear); }
		static void ConditionVariableInterface_Clear(ConditionVariableInterface* this_, Int32 dependencyCnt) { return C::Get(this_)->Clear(dependencyCnt); }
		static void ConditionVariableInterface_AddDependency(ConditionVariableInterface* this_) { return C::Get(this_)->AddDependency(); }
		static Bool ConditionVariableInterface_Set(ConditionVariableInterface* this_) { return C::Get(this_)->Set(); }
		static Bool ConditionVariableInterface_Wait(const ConditionVariableInterface* this_, const TimeValue& timeout, WAITMODE mode) { return C::Get(this_)->Wait(timeout, mode); }
		static Result<void> ConditionVariableInterface_PrivateAddFinishedObserver(ConditionVariableInterface* this_, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::Get(this_)->PrivateAddFinishedObserver(observerPod, observerQueue); }
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
	return MTable::_instance.ConditionVariableInterface_Clear(this, dependencyCnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::AddDependency() -> void
{
	return MTable::_instance.ConditionVariableInterface_AddDependency(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Set() -> Bool
{
	return MTable::_instance.ConditionVariableInterface_Set(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Wait(const TimeValue& timeout, WAITMODE mode) const -> Bool
{
	return MTable::_instance.ConditionVariableInterface_Wait(this, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance.ConditionVariableInterface_PrivateAddFinishedObserver(this, observerPod, observerQueue);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.ConditionVariableInterface_Clear(o_, dependencyCnt);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::AddDependency() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.ConditionVariableInterface_AddDependency(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::Set() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ConditionVariableInterface_Set(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ConstFn<S>::Wait(const TimeValue& timeout, WAITMODE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ConditionVariableInterface* o_ = (const ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ConditionVariableInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ConditionVariableInterface_Wait(o_, timeout, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::Fn<S>::ObservableFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ObservableFinishedBase<ConditionVariableInterface>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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

