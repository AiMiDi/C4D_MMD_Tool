
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FunctionBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObserver);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObserverPointer);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOwner);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Set);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*FunctionBaseInterface_Init) (maxon::GenericComponent* this_, const ObservableForwardFunction forwardFunction, DelegateBase&& function);
	maxon::Int FunctionBaseInterface_Init_Offset;
	Result<void> (*FunctionBaseInterface_Init_1) (maxon::GenericComponent* this_, const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue);
	maxon::Int FunctionBaseInterface_Init_1_Offset;
	void (*FunctionBaseInterface_Set) (maxon::GenericComponent* this_, ObserverObjectInterface* owner, ObserverObjectInterface* observer);
	maxon::Int FunctionBaseInterface_Set_Offset;
	void (*FunctionBaseInterface_GetOwner) (const maxon::GenericComponent* this_, ObserverObjectRef& res);
	maxon::Int FunctionBaseInterface_GetOwner_Offset;
	void (*FunctionBaseInterface_GetObserver) (const maxon::GenericComponent* this_, ObserverObjectRef& res);
	maxon::Int FunctionBaseInterface_GetObserver_Offset;
	const void* (*FunctionBaseInterface_GetObserverPointer) (const maxon::GenericComponent* this_);
	maxon::Int FunctionBaseInterface_GetObserverPointer_Offset;
	Result<Data> (*FunctionBaseInterface_Execute) (maxon::GenericComponent* this_, const Block<const ConstDataPtr>& args);
	maxon::Int FunctionBaseInterface_Execute_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Init))
	{
		FunctionBaseInterface_Init = &W::FunctionBaseInterface_Init;
		FunctionBaseInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Init))
	{
		FunctionBaseInterface_Init_1 = &W::FunctionBaseInterface_Init_1;
		FunctionBaseInterface_Init_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Set))
	{
		FunctionBaseInterface_Set = &W::FunctionBaseInterface_Set;
		FunctionBaseInterface_Set_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetOwner))
	{
		FunctionBaseInterface_GetOwner = &W::FunctionBaseInterface_GetOwner;
		FunctionBaseInterface_GetOwner_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetObserver))
	{
		FunctionBaseInterface_GetObserver = &W::FunctionBaseInterface_GetObserver;
		FunctionBaseInterface_GetObserver_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetObserverPointer))
	{
		FunctionBaseInterface_GetObserverPointer = &W::FunctionBaseInterface_GetObserverPointer;
		FunctionBaseInterface_GetObserverPointer_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Execute))
	{
		FunctionBaseInterface_Execute = &W::FunctionBaseInterface_Execute;
		FunctionBaseInterface_Execute_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FunctionBaseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FunctionBaseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FunctionBaseInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObserver);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObserverPointer);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOwner);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Set);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (FunctionBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FunctionBaseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> FunctionBaseInterface_Init(maxon::GenericComponent* this_, const ObservableForwardFunction forwardFunction, DelegateBase&& function) { return ((typename S::Implementation*) this_)->Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)); }
		static Result<void> FunctionBaseInterface_Init_1(maxon::GenericComponent* this_, const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) { return ((typename S::Implementation*) this_)->Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue); }
		static void FunctionBaseInterface_Set(maxon::GenericComponent* this_, ObserverObjectInterface* owner, ObserverObjectInterface* observer) { return ((typename S::Implementation*) this_)->Set(owner, observer); }
		static void FunctionBaseInterface_GetOwner(const maxon::GenericComponent* this_, ObserverObjectRef& res) { return ((const typename S::Implementation*) this_)->GetOwner(res); }
		static void FunctionBaseInterface_GetObserver(const maxon::GenericComponent* this_, ObserverObjectRef& res) { return ((const typename S::Implementation*) this_)->GetObserver(res); }
		static const void* FunctionBaseInterface_GetObserverPointer(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetObserverPointer(); }
		static Result<Data> FunctionBaseInterface_Execute(maxon::GenericComponent* this_, const Block<const ConstDataPtr>& args) { return ((typename S::Implementation*) this_)->Execute(args); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) -> Result<void>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_Init((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Init_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) -> Result<void>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_Init_1((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Init_1_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_Set((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Set_Offset, owner, observer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetOwner(ObserverObjectRef& res) const -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_GetOwner((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetOwner_Offset, res);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetObserver(ObserverObjectRef& res) const -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_GetObserver((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetObserver_Offset, res);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetObserverPointer() const -> const void*
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_GetObserverPointer((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetObserverPointer_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Execute(const Block<const ConstDataPtr>& args) -> Result<Data>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return mt_.FunctionBaseInterface_Execute((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Execute_Offset, args);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	mt_.FunctionBaseInterface_Set(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	mt_.FunctionBaseInterface_Set(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetOwner(ObserverObjectRef& res) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetOwner) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	mt_.FunctionBaseInterface_GetOwner(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetOwner_Offset, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserver(ObserverObjectRef& res) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	mt_.FunctionBaseInterface_GetObserver(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserver_Offset, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserverPointer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetObserverPointer) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_GetObserverPointer(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserverPointer_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Execute(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Execute(const Block<const ConstDataPtr>& args) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (mt_.FunctionBaseInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset, args));
}
auto FunctionBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FunctionBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_observable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FunctionBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FunctionBaseInterface() { new (s_ui_maxon_FunctionBaseInterface) maxon::EntityUse(FunctionBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FunctionBaseInterface(FunctionBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CombinerInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CombineResult);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitCombine);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*CombinerInterface_InitCombine) (const maxon::GenericComponent* this_, Result<Data>& combinedRes);
	maxon::Int CombinerInterface_InitCombine_Offset;
	Result<Bool> (*CombinerInterface_CombineResult) (const maxon::GenericComponent* this_, Result<Data>& combinedRes, Result<Data>&& newRes);
	maxon::Int CombinerInterface_CombineResult_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CombinerInterface, InitCombine))
	{
		CombinerInterface_InitCombine = &W::CombinerInterface_InitCombine;
		CombinerInterface_InitCombine_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CombinerInterface, CombineResult))
	{
		CombinerInterface_CombineResult = &W::CombinerInterface_CombineResult;
		CombinerInterface_CombineResult_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CombinerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CombinerInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CombinerInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CombineResult);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitCombine);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (CombinerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CombinerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> CombinerInterface_InitCombine(const maxon::GenericComponent* this_, Result<Data>& combinedRes) { return ((const typename S::Implementation*) this_)->InitCombine(combinedRes); }
		static Result<Bool> CombinerInterface_CombineResult(const maxon::GenericComponent* this_, Result<Data>& combinedRes, Result<Data>&& newRes) { return ((const typename S::Implementation*) this_)->CombineResult(combinedRes, std::forward<Result<Data>>(newRes)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::InitCombine(Result<Data>& combinedRes) const -> Result<void>
{
	const CombinerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CombinerInterface, this); return mt_.CombinerInterface_InitCombine((const maxon::GenericComponent*) this + mt_.CombinerInterface_InitCombine_Offset, combinedRes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const -> Result<Bool>
{
	const CombinerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CombinerInterface, this); return mt_.CombinerInterface_CombineResult((const maxon::GenericComponent*) this + mt_.CombinerInterface_CombineResult_Offset, combinedRes, std::forward<Result<Data>>(newRes));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::Hxx1::ConstFn<S>::InitCombine(Result<Data>& combinedRes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CombinerInterface* o_ = (const CombinerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CombinerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CombinerInterface, o_, CombinerInterface_InitCombine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CombinerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CombinerInterface>() : PRIVATE_MAXON_VTABLE(CombinerInterface, o_); 
	return (mt_.CombinerInterface_InitCombine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CombinerInterface_InitCombine_Offset, combinedRes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::Hxx1::ConstFn<S>::CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CombinerInterface* o_ = (const CombinerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CombinerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CombinerInterface, o_, CombinerInterface_CombineResult) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CombinerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CombinerInterface>() : PRIVATE_MAXON_VTABLE(CombinerInterface, o_); 
	return (mt_.CombinerInterface_CombineResult(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CombinerInterface_CombineResult_Offset, combinedRes, std::forward<Result<Data>>(newRes)));
}
auto CombinerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CombinerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_observable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CombinerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CombinerInterface() { new (s_ui_maxon_CombinerInterface) maxon::EntityUse(CombinerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CombinerInterface(CombinerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ObservableBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddObserver);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObservableId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObserverCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOwner);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Notify);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveObserver);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetInverseNotification);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(_intDisconnectAll);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ObservableBaseInterface_Init) (maxon::GenericComponent* this_, ObserverObjectInterface* owner, const Id& observableName);
	maxon::Int ObservableBaseInterface_Init_Offset;
	Id (*ObservableBaseInterface_GetObservableId) (const maxon::GenericComponent* this_);
	maxon::Int ObservableBaseInterface_GetObservableId_Offset;
	void (*ObservableBaseInterface__intDisconnectAll) (maxon::GenericComponent* this_, ObserverObjectInterface* observer, Int pass);
	maxon::Int ObservableBaseInterface__intDisconnectAll_Offset;
	Result<void> (*ObservableBaseInterface_AddObserver) (maxon::GenericComponent* this_, ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority);
	maxon::Int ObservableBaseInterface_AddObserver_Offset;
	Result<Data> (*ObservableBaseInterface_Notify) (const maxon::GenericComponent* this_, const Block<const ConstDataPtr>& args);
	maxon::Int ObservableBaseInterface_Notify_Offset;
	Result<void> (*ObservableBaseInterface_RemoveObserver) (maxon::GenericComponent* this_, const FunctionBaseRef& observerEntry);
	maxon::Int ObservableBaseInterface_RemoveObserver_Offset;
	void (*ObservableBaseInterface_SetInverseNotification) (maxon::GenericComponent* this_, Bool inverse);
	maxon::Int ObservableBaseInterface_SetInverseNotification_Offset;
	Int (*ObservableBaseInterface_GetObserverCount) (maxon::GenericComponent* this_);
	maxon::Int ObservableBaseInterface_GetObserverCount_Offset;
	ObserverObjectInterface* (*ObservableBaseInterface_GetOwner) (const maxon::GenericComponent* this_);
	maxon::Int ObservableBaseInterface_GetOwner_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, Init))
	{
		ObservableBaseInterface_Init = &W::ObservableBaseInterface_Init;
		ObservableBaseInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetObservableId))
	{
		ObservableBaseInterface_GetObservableId = &W::ObservableBaseInterface_GetObservableId;
		ObservableBaseInterface_GetObservableId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, _intDisconnectAll))
	{
		ObservableBaseInterface__intDisconnectAll = &W::ObservableBaseInterface__intDisconnectAll;
		ObservableBaseInterface__intDisconnectAll_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, AddObserver))
	{
		ObservableBaseInterface_AddObserver = &W::ObservableBaseInterface_AddObserver;
		ObservableBaseInterface_AddObserver_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, Notify))
	{
		ObservableBaseInterface_Notify = &W::ObservableBaseInterface_Notify;
		ObservableBaseInterface_Notify_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, RemoveObserver))
	{
		ObservableBaseInterface_RemoveObserver = &W::ObservableBaseInterface_RemoveObserver;
		ObservableBaseInterface_RemoveObserver_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, SetInverseNotification))
	{
		ObservableBaseInterface_SetInverseNotification = &W::ObservableBaseInterface_SetInverseNotification;
		ObservableBaseInterface_SetInverseNotification_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetObserverCount))
	{
		ObservableBaseInterface_GetObserverCount = &W::ObservableBaseInterface_GetObserverCount;
		ObservableBaseInterface_GetObserverCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetOwner))
	{
		ObservableBaseInterface_GetOwner = &W::ObservableBaseInterface_GetOwner;
		ObservableBaseInterface_GetOwner_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ObservableBaseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ObservableBaseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ObservableBaseInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddObserver);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObservableId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObserverCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOwner);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Notify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveObserver);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetInverseNotification);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(_intDisconnectAll);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ObservableBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ObservableBaseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ObservableBaseInterface_Init(maxon::GenericComponent* this_, ObserverObjectInterface* owner, const Id& observableName) { return ((typename S::Implementation*) this_)->Init(owner, observableName); }
		static Id ObservableBaseInterface_GetObservableId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetObservableId(); }
		static void ObservableBaseInterface__intDisconnectAll(maxon::GenericComponent* this_, ObserverObjectInterface* observer, Int pass) { return ((typename S::Implementation*) this_)->_intDisconnectAll(observer, pass); }
		static Result<void> ObservableBaseInterface_AddObserver(maxon::GenericComponent* this_, ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) { return ((typename S::Implementation*) this_)->AddObserver(observer, observerFunction, priority); }
		static Result<Data> ObservableBaseInterface_Notify(const maxon::GenericComponent* this_, const Block<const ConstDataPtr>& args) { return ((const typename S::Implementation*) this_)->Notify(args); }
		static Result<void> ObservableBaseInterface_RemoveObserver(maxon::GenericComponent* this_, const FunctionBaseRef& observerEntry) { return ((typename S::Implementation*) this_)->RemoveObserver(observerEntry); }
		static void ObservableBaseInterface_SetInverseNotification(maxon::GenericComponent* this_, Bool inverse) { return ((typename S::Implementation*) this_)->SetInverseNotification(inverse); }
		static Int ObservableBaseInterface_GetObserverCount(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetObserverCount(); }
		static ObserverObjectInterface* ObservableBaseInterface_GetOwner(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetOwner(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Init(ObserverObjectInterface* owner, const Id& observableName) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_Init((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_Init_Offset, owner, observableName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetObservableId() const -> Id
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_GetObservableId((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetObservableId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) -> void
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface__intDisconnectAll((maxon::GenericComponent*) this + mt_.ObservableBaseInterface__intDisconnectAll_Offset, observer, pass);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_AddObserver((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_AddObserver_Offset, observer, observerFunction, priority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_Notify((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_Notify_Offset, args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::RemoveObserver(const FunctionBaseRef& observerEntry) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_RemoveObserver((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_RemoveObserver_Offset, observerEntry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::SetInverseNotification(Bool inverse) -> void
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_SetInverseNotification((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_SetInverseNotification_Offset, inverse);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetObserverCount() -> Int
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_GetObserverCount((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetObserverCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetOwner() const -> ObserverObjectInterface*
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return mt_.ObservableBaseInterface_GetOwner((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetOwner_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Init(ObserverObjectInterface* owner, const Id& observableName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Init(ObserverObjectInterface* owner, const Id& observableName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetObservableId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObservableId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_GetObservableId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObservableId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface__intDisconnectAll) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	mt_.ObservableBaseInterface__intDisconnectAll(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface__intDisconnectAll_Offset, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface__intDisconnectAll) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	mt_.ObservableBaseInterface__intDisconnectAll(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface__intDisconnectAll_Offset, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Disconnect(ObserverObjectInterface* observer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Disconnect(ObserverObjectInterface* observer) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObservableBaseInterface::Disconnect on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Free() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Free() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObservableBaseInterface::Free on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_AddObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_AddObserver(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_AddObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_AddObserver(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Notify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_Notify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Notify_Offset, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_RemoveObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_RemoveObserver(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_RemoveObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_RemoveObserver(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::SetInverseNotification(Bool inverse) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_SetInverseNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	mt_.ObservableBaseInterface_SetInverseNotification(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::SetInverseNotification(Bool inverse) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_SetInverseNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	mt_.ObservableBaseInterface_SetInverseNotification(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::GetObserverCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObserverCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_GetObserverCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::GetObserverCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObserverCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_GetObserverCount(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetOwner() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObserverObjectInterface*>, ObserverObjectInterface*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObserverObjectInterface*>, ObserverObjectInterface*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetOwner) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (mt_.ObservableBaseInterface_GetOwner(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetOwner_Offset));
}
auto ObservableBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ObservableBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_observable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ObservableBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ObservableBaseInterface() { new (s_ui_maxon_ObservableBaseInterface) maxon::EntityUse(ObservableBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ObservableBaseInterface(ObservableBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ObservableStaticInterface::PrivateGetCppName() { return nullptr; }

struct ObservableStaticInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const ClassInterface* (*ObservableStaticInterface_GetOrAllocClass) (const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2);
	template <typename IMPL> void Init()
	{
		ObservableStaticInterface_GetOrAllocClass = &IMPL::ObservableStaticInterface_GetOrAllocClass;
	}
};

struct ObservableStaticInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static const ClassInterface* ObservableStaticInterface_GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2) { return C::GetOrAllocClass(id, id1, id2); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableStaticInterface::GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2) -> const ClassInterface*
{
	return MTable::_instance.ObservableStaticInterface_GetOrAllocClass(id, id1, id2);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_observable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ObservableStaticInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ObservableStaticInterface() { new (s_ui_maxon_ObservableStaticInterface) maxon::EntityUse(ObservableStaticInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ObservableStaticInterface(ObservableStaticInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifndef DOXYGEN
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

