
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
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const ObservableForwardFunction forwardFunction, DelegateBase&& function);
	maxon::Int FunctionBaseInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue);
	maxon::Int FunctionBaseInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_Set, Set, true, maxon::GenericComponent,, (void), ObserverObjectInterface* owner, ObserverObjectInterface* observer);
	maxon::Int FunctionBaseInterface_Set_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_GetOwner, GetOwner, true, maxon::GenericComponent, const, (void), ObserverObjectRef& res);
	maxon::Int FunctionBaseInterface_GetOwner_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_GetObserver, GetObserver, true, maxon::GenericComponent, const, (void), ObserverObjectRef& res);
	maxon::Int FunctionBaseInterface_GetObserver_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_GetObserverPointer, GetObserverPointer, true, maxon::GenericComponent, const, (const void*));
	maxon::Int FunctionBaseInterface_GetObserverPointer_Offset;
	PRIVATE_MAXON_MF_POINTER(FunctionBaseInterface_Execute, Execute, true, maxon::GenericComponent,, (Result<Data>), const Block<const ConstDataPtr>& args);
	maxon::Int FunctionBaseInterface_Execute_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Init))
	{
		maxon::Tie(FunctionBaseInterface_Init, FunctionBaseInterface_Init_Offset) = FunctionBaseInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Init))
	{
		maxon::Tie(FunctionBaseInterface_Init_1, FunctionBaseInterface_Init_1_Offset) = FunctionBaseInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Set))
	{
		maxon::Tie(FunctionBaseInterface_Set, FunctionBaseInterface_Set_Offset) = FunctionBaseInterface_Set_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetOwner))
	{
		maxon::Tie(FunctionBaseInterface_GetOwner, FunctionBaseInterface_GetOwner_Offset) = FunctionBaseInterface_GetOwner_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetObserver))
	{
		maxon::Tie(FunctionBaseInterface_GetObserver, FunctionBaseInterface_GetObserver_Offset) = FunctionBaseInterface_GetObserver_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, GetObserverPointer))
	{
		maxon::Tie(FunctionBaseInterface_GetObserverPointer, FunctionBaseInterface_GetObserverPointer_Offset) = FunctionBaseInterface_GetObserverPointer_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FunctionBaseInterface, Execute))
	{
		maxon::Tie(FunctionBaseInterface_Execute, FunctionBaseInterface_Execute_Offset) = FunctionBaseInterface_Execute_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FunctionBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FunctionBaseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_Init, maxon::GenericComponent,, (Result<void>), const ObservableForwardFunction forwardFunction, DelegateBase&& function) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_Init_1, maxon::GenericComponent,, (Result<void>), const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_Set, maxon::GenericComponent,, (void), ObserverObjectInterface* owner, ObserverObjectInterface* observer) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Set(owner, observer); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_GetOwner, maxon::GenericComponent, const, (void), ObserverObjectRef& res) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetOwner(res); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_GetObserver, maxon::GenericComponent, const, (void), ObserverObjectRef& res) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetObserver(res); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_GetObserverPointer, maxon::GenericComponent, const, (const void*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetObserverPointer(); }
		PRIVATE_MAXON_MF_WRAPPER(FunctionBaseInterface_Execute, maxon::GenericComponent,, (Result<Data>), const Block<const ConstDataPtr>& args) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Execute(args); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) -> Result<void>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Init_Offset), mt_.FunctionBaseInterface_Init, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) -> Result<void>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Init_1_Offset), mt_.FunctionBaseInterface_Init_1, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Set_Offset), mt_.FunctionBaseInterface_Set, owner, observer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetOwner(ObserverObjectRef& res) const -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetOwner_Offset), mt_.FunctionBaseInterface_GetOwner, res);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetObserver(ObserverObjectRef& res) const -> void
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetObserver_Offset), mt_.FunctionBaseInterface_GetObserver, res);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::GetObserverPointer() const -> const void*
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FunctionBaseInterface_GetObserverPointer_Offset), mt_.FunctionBaseInterface_GetObserverPointer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Execute(const Block<const ConstDataPtr>& args) -> Result<Data>
{
	const FunctionBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.FunctionBaseInterface_Execute_Offset), mt_.FunctionBaseInterface_Execute, args);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset), mt_.FunctionBaseInterface_Init, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset), mt_.FunctionBaseInterface_Init, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset), mt_.FunctionBaseInterface_Init_1, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset), mt_.FunctionBaseInterface_Init_1, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset), mt_.FunctionBaseInterface_Set, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset), mt_.FunctionBaseInterface_Set, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetOwner(ObserverObjectRef& res) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetOwner) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetOwner_Offset), mt_.FunctionBaseInterface_GetOwner, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserver(ObserverObjectRef& res) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserver_Offset), mt_.FunctionBaseInterface_GetObserver, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserverPointer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FunctionBaseInterface* o_ = (const FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FunctionBaseInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_GetObserverPointer) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserverPointer_Offset), mt_.FunctionBaseInterface_GetObserverPointer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Execute(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset), mt_.FunctionBaseInterface_Execute, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Execute(const Block<const ConstDataPtr>& args) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); FunctionBaseInterface* o_ = (FunctionBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionBaseInterface, o_, FunctionBaseInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FunctionBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionBaseInterface>() : PRIVATE_MAXON_VTABLE(FunctionBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset), mt_.FunctionBaseInterface_Execute, args));
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
	PRIVATE_MAXON_MF_POINTER(CombinerInterface_InitCombine, InitCombine, true, maxon::GenericComponent, const, (Result<void>), Result<Data>& combinedRes);
	maxon::Int CombinerInterface_InitCombine_Offset;
	PRIVATE_MAXON_MF_POINTER(CombinerInterface_CombineResult, CombineResult, true, maxon::GenericComponent, const, (Result<Bool>), Result<Data>& combinedRes, Result<Data>&& newRes);
	maxon::Int CombinerInterface_CombineResult_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CombinerInterface, InitCombine))
	{
		maxon::Tie(CombinerInterface_InitCombine, CombinerInterface_InitCombine_Offset) = CombinerInterface_InitCombine_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CombinerInterface, CombineResult))
	{
		maxon::Tie(CombinerInterface_CombineResult, CombinerInterface_CombineResult_Offset) = CombinerInterface_CombineResult_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CombinerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CombinerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CombinerInterface_InitCombine, maxon::GenericComponent, const, (Result<void>), Result<Data>& combinedRes) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InitCombine(combinedRes); }
		PRIVATE_MAXON_MF_WRAPPER(CombinerInterface_CombineResult, maxon::GenericComponent, const, (Result<Bool>), Result<Data>& combinedRes, Result<Data>&& newRes) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CombineResult(combinedRes, std::forward<Result<Data>>(newRes)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::InitCombine(Result<Data>& combinedRes) const -> Result<void>
{
	const CombinerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CombinerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CombinerInterface_InitCombine_Offset), mt_.CombinerInterface_InitCombine, combinedRes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const -> Result<Bool>
{
	const CombinerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CombinerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CombinerInterface_CombineResult_Offset), mt_.CombinerInterface_CombineResult, combinedRes, std::forward<Result<Data>>(newRes));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::Hxx1::ConstFn<S>::InitCombine(Result<Data>& combinedRes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CombinerInterface* o_ = (const CombinerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CombinerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CombinerInterface, o_, CombinerInterface_InitCombine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CombinerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CombinerInterface>() : PRIVATE_MAXON_VTABLE(CombinerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CombinerInterface_InitCombine_Offset), mt_.CombinerInterface_InitCombine, combinedRes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::Hxx1::ConstFn<S>::CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CombinerInterface* o_ = (const CombinerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CombinerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CombinerInterface, o_, CombinerInterface_CombineResult) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CombinerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CombinerInterface>() : PRIVATE_MAXON_VTABLE(CombinerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CombinerInterface_CombineResult_Offset), mt_.CombinerInterface_CombineResult, combinedRes, std::forward<Result<Data>>(newRes)));
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
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* owner, const Id& observableName);
	maxon::Int ObservableBaseInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_GetObservableId, GetObservableId, true, maxon::GenericComponent, const, (Id));
	maxon::Int ObservableBaseInterface_GetObservableId_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface__intDisconnectAll, _intDisconnectAll, true, maxon::GenericComponent,, (void), ObserverObjectInterface* observer, Int pass);
	maxon::Int ObservableBaseInterface__intDisconnectAll_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_AddObserver, AddObserver, true, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority);
	maxon::Int ObservableBaseInterface_AddObserver_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_Notify, Notify, true, maxon::GenericComponent, const, (Result<Data>), const Block<const ConstDataPtr>& args);
	maxon::Int ObservableBaseInterface_Notify_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_RemoveObserver, RemoveObserver, true, maxon::GenericComponent,, (Result<void>), const FunctionBaseRef& observerEntry);
	maxon::Int ObservableBaseInterface_RemoveObserver_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_SetInverseNotification, SetInverseNotification, true, maxon::GenericComponent,, (void), Bool inverse);
	maxon::Int ObservableBaseInterface_SetInverseNotification_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_GetObserverCount, GetObserverCount, true, maxon::GenericComponent,, (Int));
	maxon::Int ObservableBaseInterface_GetObserverCount_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_GetOwner, GetOwner, true, maxon::GenericComponent, const, (ObserverObjectInterface*));
	maxon::Int ObservableBaseInterface_GetOwner_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, Init))
	{
		maxon::Tie(ObservableBaseInterface_Init, ObservableBaseInterface_Init_Offset) = ObservableBaseInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetObservableId))
	{
		maxon::Tie(ObservableBaseInterface_GetObservableId, ObservableBaseInterface_GetObservableId_Offset) = ObservableBaseInterface_GetObservableId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, _intDisconnectAll))
	{
		maxon::Tie(ObservableBaseInterface__intDisconnectAll, ObservableBaseInterface__intDisconnectAll_Offset) = ObservableBaseInterface__intDisconnectAll_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, AddObserver))
	{
		maxon::Tie(ObservableBaseInterface_AddObserver, ObservableBaseInterface_AddObserver_Offset) = ObservableBaseInterface_AddObserver_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, Notify))
	{
		maxon::Tie(ObservableBaseInterface_Notify, ObservableBaseInterface_Notify_Offset) = ObservableBaseInterface_Notify_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, RemoveObserver))
	{
		maxon::Tie(ObservableBaseInterface_RemoveObserver, ObservableBaseInterface_RemoveObserver_Offset) = ObservableBaseInterface_RemoveObserver_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, SetInverseNotification))
	{
		maxon::Tie(ObservableBaseInterface_SetInverseNotification, ObservableBaseInterface_SetInverseNotification_Offset) = ObservableBaseInterface_SetInverseNotification_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetObserverCount))
	{
		maxon::Tie(ObservableBaseInterface_GetObserverCount, ObservableBaseInterface_GetObserverCount_Offset) = ObservableBaseInterface_GetObserverCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, GetOwner))
	{
		maxon::Tie(ObservableBaseInterface_GetOwner, ObservableBaseInterface_GetOwner_Offset) = ObservableBaseInterface_GetOwner_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ObservableBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ObservableBaseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_Init, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* owner, const Id& observableName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(owner, observableName); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_GetObservableId, maxon::GenericComponent, const, (Id)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetObservableId(); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface__intDisconnectAll, maxon::GenericComponent,, (void), ObserverObjectInterface* observer, Int pass) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->_intDisconnectAll(observer, pass); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_AddObserver, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddObserver(observer, observerFunction, priority); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_Notify, maxon::GenericComponent, const, (Result<Data>), const Block<const ConstDataPtr>& args) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Notify(args); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_RemoveObserver, maxon::GenericComponent,, (Result<void>), const FunctionBaseRef& observerEntry) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveObserver(observerEntry); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_SetInverseNotification, maxon::GenericComponent,, (void), Bool inverse) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetInverseNotification(inverse); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_GetObserverCount, maxon::GenericComponent,, (Int)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetObserverCount(); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_GetOwner, maxon::GenericComponent, const, (ObserverObjectInterface*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetOwner(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Init(ObserverObjectInterface* owner, const Id& observableName) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_Init_Offset), mt_.ObservableBaseInterface_Init, owner, observableName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetObservableId() const -> Id
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetObservableId_Offset), mt_.ObservableBaseInterface_GetObservableId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) -> void
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface__intDisconnectAll_Offset), mt_.ObservableBaseInterface__intDisconnectAll, observer, pass);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_Notify_Offset), mt_.ObservableBaseInterface_Notify, args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::RemoveObserver(const FunctionBaseRef& observerEntry) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_RemoveObserver_Offset), mt_.ObservableBaseInterface_RemoveObserver, observerEntry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::SetInverseNotification(Bool inverse) -> void
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_SetInverseNotification_Offset), mt_.ObservableBaseInterface_SetInverseNotification, inverse);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetObserverCount() -> Int
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetObserverCount_Offset), mt_.ObservableBaseInterface_GetObserverCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::GetOwner() const -> ObserverObjectInterface*
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_GetOwner_Offset), mt_.ObservableBaseInterface_GetOwner);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Init(ObserverObjectInterface* owner, const Id& observableName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset), mt_.ObservableBaseInterface_Init, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Init(ObserverObjectInterface* owner, const Id& observableName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset), mt_.ObservableBaseInterface_Init, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetObservableId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObservableId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObservableId_Offset), mt_.ObservableBaseInterface_GetObservableId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface__intDisconnectAll) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface__intDisconnectAll_Offset), mt_.ObservableBaseInterface__intDisconnectAll, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::_intDisconnectAll(ObserverObjectInterface* observer, Int pass) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface__intDisconnectAll) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface__intDisconnectAll_Offset), mt_.ObservableBaseInterface__intDisconnectAll, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Disconnect(ObserverObjectInterface* observer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Disconnect(ObserverObjectInterface* observer) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObservableBaseInterface::Disconnect on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Free() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Free() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObservableBaseInterface::Free on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_AddObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_AddObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_Notify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Notify_Offset), mt_.ObservableBaseInterface_Notify, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_RemoveObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset), mt_.ObservableBaseInterface_RemoveObserver, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_RemoveObserver) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset), mt_.ObservableBaseInterface_RemoveObserver, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::SetInverseNotification(Bool inverse) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_SetInverseNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset), mt_.ObservableBaseInterface_SetInverseNotification, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::SetInverseNotification(Bool inverse) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_SetInverseNotification) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset), mt_.ObservableBaseInterface_SetInverseNotification, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::GetObserverCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObserverCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset), mt_.ObservableBaseInterface_GetObserverCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::GetObserverCount() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObservableBaseInterface* o_ = (ObservableBaseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetObserverCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset), mt_.ObservableBaseInterface_GetObserverCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetOwner() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObserverObjectInterface*>, ObserverObjectInterface*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObserverObjectInterface*>, ObserverObjectInterface*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObservableBaseInterface* o_ = (const ObservableBaseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObservableBaseInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObservableBaseInterface, o_, ObservableBaseInterface_GetOwner) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObservableBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObservableBaseInterface>() : PRIVATE_MAXON_VTABLE(ObservableBaseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetOwner_Offset), mt_.ObservableBaseInterface_GetOwner));
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
	PRIVATE_MAXON_SF_POINTER(ObservableStaticInterface_GetOrAllocClass, GetOrAllocClass, MAXON_EXPAND_VA_ARGS, (const ClassInterface*), const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2);
	template <typename IMPL> void Init()
	{
		ObservableStaticInterface_GetOrAllocClass = ObservableStaticInterface_GetOrAllocClass_GetPtr<IMPL>(true);
	}
};

struct ObservableStaticInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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

