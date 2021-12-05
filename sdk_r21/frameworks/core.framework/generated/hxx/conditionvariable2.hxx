
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ConditionVariableInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_ConditionVariableInterface_Free) (const ConditionVariableInterface* object);
	ConditionVariableInterface* (*_ConditionVariableInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	ConditionVariableInterface* (*_ConditionVariableInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, Bool isAutoClear);
	void (*_ConditionVariableInterface_Clear) (ConditionVariableInterface* this_, Int32 dependencyCnt);
	void (*_ConditionVariableInterface_AddDependency) (ConditionVariableInterface* this_);
	Bool (*_ConditionVariableInterface_Set) (ConditionVariableInterface* this_);
	Bool (*_ConditionVariableInterface_Wait) (const ConditionVariableInterface* this_, const TimeValue& timeout, WAITMODE mode);
	Result<void> (*_ConditionVariableInterface_PrivateAddFinishedObserver) (ConditionVariableInterface* this_, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	template <typename IMPL> void Init()
	{
		_ConditionVariableInterface_Free = &IMPL::_ConditionVariableInterface_Free;
		_ConditionVariableInterface_Alloc = &IMPL::_ConditionVariableInterface_Alloc;
		_ConditionVariableInterface_Alloc_1 = &IMPL::_ConditionVariableInterface_Alloc_1;
		_ConditionVariableInterface_Clear = &IMPL::_ConditionVariableInterface_Clear;
		_ConditionVariableInterface_AddDependency = &IMPL::_ConditionVariableInterface_AddDependency;
		_ConditionVariableInterface_Set = &IMPL::_ConditionVariableInterface_Set;
		_ConditionVariableInterface_Wait = &IMPL::_ConditionVariableInterface_Wait;
		_ConditionVariableInterface_PrivateAddFinishedObserver = &IMPL::_ConditionVariableInterface_PrivateAddFinishedObserver;
	}
};

struct ConditionVariableInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _ConditionVariableInterface_Free(const ConditionVariableInterface* object) { return C::Free(object); }
	static ConditionVariableInterface* _ConditionVariableInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static ConditionVariableInterface* _ConditionVariableInterface_Alloc_1(const maxon::SourceLocation& allocLocation, Bool isAutoClear) { return C::Alloc(allocLocation, isAutoClear); }
	static void _ConditionVariableInterface_Clear(ConditionVariableInterface* this_, Int32 dependencyCnt) { return ((C*) this_)->Clear(dependencyCnt); }
	static void _ConditionVariableInterface_AddDependency(ConditionVariableInterface* this_) { return ((C*) this_)->AddDependency(); }
	static Bool _ConditionVariableInterface_Set(ConditionVariableInterface* this_) { return ((C*) this_)->Set(); }
	static Bool _ConditionVariableInterface_Wait(const ConditionVariableInterface* this_, const TimeValue& timeout, WAITMODE mode) { return ((const C*) this_)->Wait(timeout, mode); }
	static Result<void> _ConditionVariableInterface_PrivateAddFinishedObserver(ConditionVariableInterface* this_, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return ((C*) this_)->PrivateAddFinishedObserver(observerPod, observerQueue); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Free(const ConditionVariableInterface* object) -> void
{
	return MTable::_instance._ConditionVariableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ConditionVariableInterface*
{
	return MTable::_instance._ConditionVariableInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Alloc(const maxon::SourceLocation& allocLocation, Bool isAutoClear) -> ConditionVariableInterface*
{
	return MTable::_instance._ConditionVariableInterface_Alloc_1(allocLocation, isAutoClear);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Clear(Int32 dependencyCnt) -> void
{
	return MTable::_instance._ConditionVariableInterface_Clear(this, dependencyCnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::AddDependency() -> void
{
	return MTable::_instance._ConditionVariableInterface_AddDependency(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Set() -> Bool
{
	return MTable::_instance._ConditionVariableInterface_Set(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Wait(const TimeValue& timeout, WAITMODE mode) const -> Bool
{
	return MTable::_instance._ConditionVariableInterface_Wait(this, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance._ConditionVariableInterface_PrivateAddFinishedObserver(this, observerPod, observerQueue);
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
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ReferenceFunctionsImpl<S>::Clear(Int32 dependencyCnt) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._ConditionVariableInterface_Clear(o_, dependencyCnt);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ReferenceFunctionsImpl<S>::AddDependency() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._ConditionVariableInterface_AddDependency(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ReferenceFunctionsImpl<S>::Set() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (MTable::_instance._ConditionVariableInterface_Set(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Wait(const TimeValue& timeout, WAITMODE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ConditionVariableInterface* o_ = (const ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ConditionVariableInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ConditionVariableInterface_Wait(o_, timeout, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConditionVariableInterface::Hxx1::ReferenceFunctionsImpl<S>::ObservableFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConditionVariableInterface* o_ = (ConditionVariableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateIncompleteNullReturnValue<ObservableFinishedBase<ConditionVariableInterface>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->ObservableFinished());
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

