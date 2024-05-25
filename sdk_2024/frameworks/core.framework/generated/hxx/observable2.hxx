
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
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<FunctionBaseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(FunctionBaseInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset), mt_.FunctionBaseInterface_Init, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(FunctionBaseInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_Offset), mt_.FunctionBaseInterface_Init, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(FunctionBaseInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset), mt_.FunctionBaseInterface_Init_1, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(FunctionBaseInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Init_1_Offset), mt_.FunctionBaseInterface_Init_1, std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(FunctionBaseInterface_Set); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset), mt_.FunctionBaseInterface_Set, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(FunctionBaseInterface_Set); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Set_Offset), mt_.FunctionBaseInterface_Set, owner, observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetOwner(ObserverObjectRef& res) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(FunctionBaseInterface_GetOwner); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetOwner_Offset), mt_.FunctionBaseInterface_GetOwner, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserver(ObserverObjectRef& res) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(FunctionBaseInterface_GetObserver); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserver_Offset), mt_.FunctionBaseInterface_GetObserver, res);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::ConstFn<S>::GetObserverPointer() const -> HXXADDRET2(const void*)
{
	HXXRETURN0(HXXADDRET2(const void*)); HXXRES; HXXCONST(nullptr) HXXTABLE(FunctionBaseInterface_GetObserverPointer); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_GetObserverPointer_Offset), mt_.FunctionBaseInterface_GetObserverPointer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::Fn<S>::Execute(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(FunctionBaseInterface_Execute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FunctionBaseInterface_Execute_Offset), mt_.FunctionBaseInterface_Execute, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionBaseInterface::Hxx1::COWFn<S>::Execute(const Block<const ConstDataPtr>& args) -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(FunctionBaseInterface_Execute); 
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
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<CombinerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(CombinerInterface_InitCombine); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CombinerInterface_InitCombine_Offset), mt_.CombinerInterface_InitCombine, combinedRes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CombinerInterface::Hxx1::ConstFn<S>::CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(CombinerInterface_CombineResult); 
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateDisconnectAll);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveObserver);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetInverseNotification);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* owner, const Id& observableName);
	maxon::Int ObservableBaseInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_GetObservableId, GetObservableId, true, maxon::GenericComponent, const, (Id));
	maxon::Int ObservableBaseInterface_GetObservableId_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_PrivateDisconnectAll, PrivateDisconnectAll, true, maxon::GenericComponent,, (void), ObserverObjectInterface* observer, Int pass);
	maxon::Int ObservableBaseInterface_PrivateDisconnectAll_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_AddObserver, AddObserver, true, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority);
	maxon::Int ObservableBaseInterface_AddObserver_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_Notify, Notify, true, maxon::GenericComponent, const, (Result<Data>), const Block<const ConstDataPtr>& args);
	maxon::Int ObservableBaseInterface_Notify_Offset;
	PRIVATE_MAXON_MF_POINTER(ObservableBaseInterface_RemoveObserver, RemoveObserver, true, maxon::GenericComponent,, (Bool), const FunctionBaseRef& observerEntry);
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
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObservableBaseInterface, PrivateDisconnectAll))
	{
		maxon::Tie(ObservableBaseInterface_PrivateDisconnectAll, ObservableBaseInterface_PrivateDisconnectAll_Offset) = ObservableBaseInterface_PrivateDisconnectAll_GetPtr<W>(offset, true);
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
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ObservableBaseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateDisconnectAll);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveObserver);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetInverseNotification);
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
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_PrivateDisconnectAll, maxon::GenericComponent,, (void), ObserverObjectInterface* observer, Int pass) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateDisconnectAll(observer, pass); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_AddObserver, maxon::GenericComponent,, (Result<void>), ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddObserver(observer, observerFunction, priority); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_Notify, maxon::GenericComponent, const, (Result<Data>), const Block<const ConstDataPtr>& args) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Notify(args); }
		PRIVATE_MAXON_MF_WRAPPER(ObservableBaseInterface_RemoveObserver, maxon::GenericComponent,, (Bool), const FunctionBaseRef& observerEntry) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveObserver(observerEntry); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass) -> void
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_PrivateDisconnectAll_Offset), mt_.ObservableBaseInterface_PrivateDisconnectAll, observer, pass);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	const ObservableBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObservableBaseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObservableBaseInterface_Notify_Offset), mt_.ObservableBaseInterface_Notify, args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::RemoveObserver(const FunctionBaseRef& observerEntry) -> Bool
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
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ObservableBaseInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset), mt_.ObservableBaseInterface_Init, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Init(ObserverObjectInterface* owner, const Id& observableName) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Init_Offset), mt_.ObservableBaseInterface_Init, owner, observableName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetObservableId() const -> HXXADDRET2(Id)
{
	HXXRETURN0(HXXADDRET2(Id)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Id)) HXXTABLE(ObservableBaseInterface_GetObservableId); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObservableId_Offset), mt_.ObservableBaseInterface_GetObservableId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ObservableBaseInterface_PrivateDisconnectAll); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_PrivateDisconnectAll_Offset), mt_.ObservableBaseInterface_PrivateDisconnectAll, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_PrivateDisconnectAll); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_PrivateDisconnectAll_Offset), mt_.ObservableBaseInterface_PrivateDisconnectAll, observer, pass);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Disconnect(ObserverObjectInterface* observer) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Disconnect(ObserverObjectInterface* observer) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXSUPER("ObservableBaseInterface::Disconnect"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	o_->Disconnect(observer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::Free() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::Free() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXSUPER("ObservableBaseInterface::Free"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	o_->Free();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ObservableBaseInterface_AddObserver); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_AddObserver); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_AddObserver_Offset), mt_.ObservableBaseInterface_AddObserver, observer, observerFunction, priority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::Notify(const Block<const ConstDataPtr>& args) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ObservableBaseInterface_Notify); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_Notify_Offset), mt_.ObservableBaseInterface_Notify, args));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXNONCONST(, , false, maxon::PrivateLogNullptrError(false)) HXXTABLE(ObservableBaseInterface_RemoveObserver); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset), mt_.ObservableBaseInterface_RemoveObserver, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::RemoveObserver(const FunctionBaseRef& observerEntry) -> HXXADDRET1(Bool)
{
	HXXRETURN0(HXXADDRET1(Bool)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_RemoveObserver); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_RemoveObserver_Offset), mt_.ObservableBaseInterface_RemoveObserver, observerEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::SetInverseNotification(Bool inverse) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ObservableBaseInterface_SetInverseNotification); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset), mt_.ObservableBaseInterface_SetInverseNotification, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::SetInverseNotification(Bool inverse) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_SetInverseNotification); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_SetInverseNotification_Offset), mt_.ObservableBaseInterface_SetInverseNotification, inverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::Fn<S>::GetObserverCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXNONCONST(, , false, 0) HXXTABLE(ObservableBaseInterface_GetObserverCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset), mt_.ObservableBaseInterface_GetObserverCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::COWFn<S>::GetObserverCount() -> HXXADDRET1(Int)
{
	HXXRETURN0(HXXADDRET1(Int)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObservableBaseInterface_GetObserverCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObservableBaseInterface_GetObserverCount_Offset), mt_.ObservableBaseInterface_GetObserverCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObservableBaseInterface::Hxx1::ConstFn<S>::GetOwner() const -> HXXADDRET2(ObserverObjectInterface*)
{
	HXXRETURN0(HXXADDRET2(ObserverObjectInterface*)); HXXRES; HXXCONST(nullptr) HXXTABLE(ObservableBaseInterface_GetOwner); 
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
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
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static const ClassInterface* ObservableStaticInterface_GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2) { return S::GetOrAllocClass(id, id1, id2); }
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

