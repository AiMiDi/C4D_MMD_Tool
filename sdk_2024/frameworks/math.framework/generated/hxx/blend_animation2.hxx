
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct BlendTweenInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEnd);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFunction);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMappedValue);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStart);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableAnimation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetEnd);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetFunction);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetNewTarget);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetStart);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_GetMappedValue, GetMappedValue, true, maxon::GenericComponent,, (Result<Data>), Float xValue);
	maxon::Int BlendTweenInterface_GetMappedValue_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_SetNewTarget, SetNewTarget, true, maxon::GenericComponent,, (Result<void>), const BlendFunctionRef& blendFunction, const Data& endValue);
	maxon::Int BlendTweenInterface_SetNewTarget_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_SetFunction, SetFunction, true, maxon::GenericComponent,, (Result<void>), const BlendFunctionRef& blendFunction);
	maxon::Int BlendTweenInterface_SetFunction_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_GetFunction, GetFunction, true, maxon::GenericComponent, const, (BlendFunctionRef));
	maxon::Int BlendTweenInterface_GetFunction_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_SetStart, SetStart, true, maxon::GenericComponent,, (Result<void>), const Data& value);
	maxon::Int BlendTweenInterface_SetStart_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_GetStart, GetStart, true, maxon::GenericComponent, const, (Result<Data>));
	maxon::Int BlendTweenInterface_GetStart_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_SetEnd, SetEnd, true, maxon::GenericComponent,, (Result<void>), const Data& value);
	maxon::Int BlendTweenInterface_SetEnd_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_GetEnd, GetEnd, true, maxon::GenericComponent, const, (Result<Data>));
	maxon::Int BlendTweenInterface_GetEnd_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendTweenInterface_ObservableAnimation, ObservableAnimation, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableAnimationDelegate>), Bool create);
	maxon::Int BlendTweenInterface_ObservableAnimation_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetMappedValue))
	{
		maxon::Tie(BlendTweenInterface_GetMappedValue, BlendTweenInterface_GetMappedValue_Offset) = BlendTweenInterface_GetMappedValue_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetNewTarget))
	{
		maxon::Tie(BlendTweenInterface_SetNewTarget, BlendTweenInterface_SetNewTarget_Offset) = BlendTweenInterface_SetNewTarget_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetFunction))
	{
		maxon::Tie(BlendTweenInterface_SetFunction, BlendTweenInterface_SetFunction_Offset) = BlendTweenInterface_SetFunction_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetFunction))
	{
		maxon::Tie(BlendTweenInterface_GetFunction, BlendTweenInterface_GetFunction_Offset) = BlendTweenInterface_GetFunction_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetStart))
	{
		maxon::Tie(BlendTweenInterface_SetStart, BlendTweenInterface_SetStart_Offset) = BlendTweenInterface_SetStart_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetStart))
	{
		maxon::Tie(BlendTweenInterface_GetStart, BlendTweenInterface_GetStart_Offset) = BlendTweenInterface_GetStart_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetEnd))
	{
		maxon::Tie(BlendTweenInterface_SetEnd, BlendTweenInterface_SetEnd_Offset) = BlendTweenInterface_SetEnd_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetEnd))
	{
		maxon::Tie(BlendTweenInterface_GetEnd, BlendTweenInterface_GetEnd_Offset) = BlendTweenInterface_GetEnd_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, ObservableAnimation))
	{
		maxon::Tie(BlendTweenInterface_ObservableAnimation, BlendTweenInterface_ObservableAnimation_Offset) = BlendTweenInterface_ObservableAnimation_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<BlendTweenInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BlendTweenInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BlendTweenInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEnd);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFunction);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMappedValue);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStart);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableAnimation);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetEnd);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetFunction);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetNewTarget);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetStart);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BlendTweenInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BlendTweenInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_GetMappedValue, maxon::GenericComponent,, (Result<Data>), Float xValue) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetMappedValue(xValue); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_SetNewTarget, maxon::GenericComponent,, (Result<void>), const BlendFunctionRef& blendFunction, const Data& endValue) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetNewTarget(blendFunction, endValue); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_SetFunction, maxon::GenericComponent,, (Result<void>), const BlendFunctionRef& blendFunction) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetFunction(blendFunction); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_GetFunction, maxon::GenericComponent, const, (BlendFunctionRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFunction(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_SetStart, maxon::GenericComponent,, (Result<void>), const Data& value) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetStart(value); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_GetStart, maxon::GenericComponent, const, (Result<Data>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStart(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_SetEnd, maxon::GenericComponent,, (Result<void>), const Data& value) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetEnd(value); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_GetEnd, maxon::GenericComponent, const, (Result<Data>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetEnd(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendTweenInterface_ObservableAnimation, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableAnimationDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableAnimation(create); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetMappedValue(Float xValue) -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetMappedValue_Offset), mt_.BlendTweenInterface_GetMappedValue, xValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetNewTarget_Offset), mt_.BlendTweenInterface_SetNewTarget, blendFunction, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetFunction_Offset), mt_.BlendTweenInterface_SetFunction, blendFunction);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetFunction() const -> BlendFunctionRef
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetFunction_Offset), mt_.BlendTweenInterface_GetFunction);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetStart(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetStart_Offset), mt_.BlendTweenInterface_SetStart, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetStart() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetStart_Offset), mt_.BlendTweenInterface_GetStart);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetEnd(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetEnd_Offset), mt_.BlendTweenInterface_SetEnd, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetEnd() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetEnd_Offset), mt_.BlendTweenInterface_GetEnd);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::ObservableAnimation(Bool create) const -> maxon::ObservableRef<ObservableAnimationDelegate>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_ObservableAnimation_Offset), mt_.BlendTweenInterface_ObservableAnimation, create);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::GetMappedValue(Float xValue) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_GetMappedValue); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetMappedValue_Offset), mt_.BlendTweenInterface_GetMappedValue, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::GetMappedValue(Float xValue) -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendTweenInterface_GetMappedValue); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetMappedValue_Offset), mt_.BlendTweenInterface_GetMappedValue, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_SetNewTarget); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetNewTarget_Offset), mt_.BlendTweenInterface_SetNewTarget, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendTweenInterface_SetNewTarget); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetNewTarget_Offset), mt_.BlendTweenInterface_SetNewTarget, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetFunction(const BlendFunctionRef& blendFunction) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_SetFunction); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetFunction_Offset), mt_.BlendTweenInterface_SetFunction, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendTweenInterface_SetFunction); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetFunction_Offset), mt_.BlendTweenInterface_SetFunction, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetFunction() const -> HXXADDRET2(BlendFunctionRef)
{
	HXXRETURN0(HXXADDRET2(BlendFunctionRef)); HXXRES; HXXCONST(HXXRET3(NULLPTR, BlendFunctionRef)) HXXTABLE(BlendTweenInterface_GetFunction); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetFunction_Offset), mt_.BlendTweenInterface_GetFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetStart(const Data& value) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_SetStart); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetStart_Offset), mt_.BlendTweenInterface_SetStart, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetStart(const Data& value) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendTweenInterface_SetStart); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetStart_Offset), mt_.BlendTweenInterface_SetStart, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetStart() const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_GetStart); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetStart_Offset), mt_.BlendTweenInterface_GetStart));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetEnd(const Data& value) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_SetEnd); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetEnd_Offset), mt_.BlendTweenInterface_SetEnd, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetEnd(const Data& value) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendTweenInterface_SetEnd); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetEnd_Offset), mt_.BlendTweenInterface_SetEnd, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetEnd() const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BlendTweenInterface_GetEnd); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetEnd_Offset), mt_.BlendTweenInterface_GetEnd));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::ObservableAnimation(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableAnimationDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableAnimationDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableAnimationDelegate>::DefaultValue()) HXXTABLE(BlendTweenInterface_ObservableAnimation); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_ObservableAnimation_Offset), mt_.BlendTweenInterface_ObservableAnimation, create));
}
auto BlendTweenInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BlendTweenInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_blend_animation)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BlendTweenInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BlendTweenInterface() { new (s_ui_maxon_BlendTweenInterface) maxon::EntityUse(BlendTweenInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_animation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BlendTweenInterface(BlendTweenInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_animation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct BlendAnimationInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddTween);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CancelAndWait);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTimerRef);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTweens);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveTween);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetDirection);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetStartProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(StartAnimation);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_AddTween, AddTween, true, maxon::GenericComponent,, (Result<BlendTweenRef>), const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue);
	maxon::Int BlendAnimationInterface_AddTween_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_RemoveTween, RemoveTween, true, maxon::GenericComponent,, (Result<void>), const BlendTweenRef& tween);
	maxon::Int BlendAnimationInterface_RemoveTween_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_GetTweens, GetTweens, true, maxon::GenericComponent, const, (Result<BaseArray<BlendTweenRef>>));
	maxon::Int BlendAnimationInterface_GetTweens_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_StartAnimation, StartAnimation, true, maxon::GenericComponent,, (Result<void>), const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration);
	maxon::Int BlendAnimationInterface_StartAnimation_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_GetProgress, GetProgress, true, maxon::GenericComponent, const, (Float));
	maxon::Int BlendAnimationInterface_GetProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_GetState, GetState, true, maxon::GenericComponent, const, (ANIMBLENDSTATE));
	maxon::Int BlendAnimationInterface_GetState_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_CancelAndWait, CancelAndWait, true, maxon::GenericComponent,, (void));
	maxon::Int BlendAnimationInterface_CancelAndWait_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_GetTimerRef, GetTimerRef, true, maxon::GenericComponent, const, (Result<TimerRef>));
	maxon::Int BlendAnimationInterface_GetTimerRef_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_SetStartProgress, SetStartProgress, true, maxon::GenericComponent,, (void), Float startProgress);
	maxon::Int BlendAnimationInterface_SetStartProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(BlendAnimationInterface_SetDirection, SetDirection, true, maxon::GenericComponent,, (void), Bool reverse);
	maxon::Int BlendAnimationInterface_SetDirection_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, AddTween))
	{
		maxon::Tie(BlendAnimationInterface_AddTween, BlendAnimationInterface_AddTween_Offset) = BlendAnimationInterface_AddTween_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, RemoveTween))
	{
		maxon::Tie(BlendAnimationInterface_RemoveTween, BlendAnimationInterface_RemoveTween_Offset) = BlendAnimationInterface_RemoveTween_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTweens))
	{
		maxon::Tie(BlendAnimationInterface_GetTweens, BlendAnimationInterface_GetTweens_Offset) = BlendAnimationInterface_GetTweens_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, StartAnimation))
	{
		maxon::Tie(BlendAnimationInterface_StartAnimation, BlendAnimationInterface_StartAnimation_Offset) = BlendAnimationInterface_StartAnimation_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetProgress))
	{
		maxon::Tie(BlendAnimationInterface_GetProgress, BlendAnimationInterface_GetProgress_Offset) = BlendAnimationInterface_GetProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetState))
	{
		maxon::Tie(BlendAnimationInterface_GetState, BlendAnimationInterface_GetState_Offset) = BlendAnimationInterface_GetState_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, CancelAndWait))
	{
		maxon::Tie(BlendAnimationInterface_CancelAndWait, BlendAnimationInterface_CancelAndWait_Offset) = BlendAnimationInterface_CancelAndWait_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTimerRef))
	{
		maxon::Tie(BlendAnimationInterface_GetTimerRef, BlendAnimationInterface_GetTimerRef_Offset) = BlendAnimationInterface_GetTimerRef_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, SetStartProgress))
	{
		maxon::Tie(BlendAnimationInterface_SetStartProgress, BlendAnimationInterface_SetStartProgress_Offset) = BlendAnimationInterface_SetStartProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, SetDirection))
	{
		maxon::Tie(BlendAnimationInterface_SetDirection, BlendAnimationInterface_SetDirection_Offset) = BlendAnimationInterface_SetDirection_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<BlendAnimationInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BlendAnimationInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BlendAnimationInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddTween);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CancelAndWait);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTimerRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTweens);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveTween);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetDirection);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetStartProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(StartAnimation);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BlendAnimationInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BlendAnimationInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_AddTween, maxon::GenericComponent,, (Result<BlendTweenRef>), const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddTween(blendFunction, startValue, endValue); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_RemoveTween, maxon::GenericComponent,, (Result<void>), const BlendTweenRef& tween) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveTween(tween); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_GetTweens, maxon::GenericComponent, const, (Result<BaseArray<BlendTweenRef>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTweens(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_StartAnimation, maxon::GenericComponent,, (Result<void>), const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->StartAnimation(timerInterval, startDelay, duration); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_GetProgress, maxon::GenericComponent, const, (Float)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProgress(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_GetState, maxon::GenericComponent, const, (ANIMBLENDSTATE)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetState(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_CancelAndWait, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CancelAndWait(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_GetTimerRef, maxon::GenericComponent, const, (Result<TimerRef>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTimerRef(); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_SetStartProgress, maxon::GenericComponent,, (void), Float startProgress) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetStartProgress(startProgress); }
		PRIVATE_MAXON_MF_WRAPPER(BlendAnimationInterface_SetDirection, maxon::GenericComponent,, (void), Bool reverse) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetDirection(reverse); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_AddTween_Offset), mt_.BlendAnimationInterface_AddTween, blendFunction, startValue, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_RemoveTween_Offset), mt_.BlendAnimationInterface_RemoveTween, tween);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetTweens_Offset), mt_.BlendAnimationInterface_GetTweens);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_StartAnimation_Offset), mt_.BlendAnimationInterface_StartAnimation, timerInterval, startDelay, duration);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetProgress() const -> Float
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetProgress_Offset), mt_.BlendAnimationInterface_GetProgress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetState() const -> ANIMBLENDSTATE
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetState_Offset), mt_.BlendAnimationInterface_GetState);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::CancelAndWait() -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_CancelAndWait_Offset), mt_.BlendAnimationInterface_CancelAndWait);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTimerRef() const -> Result<TimerRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetTimerRef_Offset), mt_.BlendAnimationInterface_GetTimerRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::SetStartProgress(Float startProgress) -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_SetStartProgress_Offset), mt_.BlendAnimationInterface_SetStartProgress, startProgress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::SetDirection(Bool reverse) -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_SetDirection_Offset), mt_.BlendAnimationInterface_SetDirection, reverse);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) const -> Result<BlendTweenRef>
{
	HXXRETURN0(Result<BlendTweenRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendAnimationInterface_AddTween); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_AddTween_Offset), mt_.BlendAnimationInterface_AddTween, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	HXXRETURN0(Result<BlendTweenRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_AddTween); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_AddTween_Offset), mt_.BlendAnimationInterface_AddTween, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) const -> Result<BlendTweenRef>
{
	HXXRETURN0(Result<BlendTweenRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) -> Result<BlendTweenRef>
{
	HXXRETURN0(Result<BlendTweenRef>); HXXSUPER("BlendAnimationInterface::AddTween"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::RemoveTween(const BlendTweenRef& tween) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendAnimationInterface_RemoveTween); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_RemoveTween_Offset), mt_.BlendAnimationInterface_RemoveTween, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_RemoveTween); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_RemoveTween_Offset), mt_.BlendAnimationInterface_RemoveTween, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	HXXRETURN0(Result<BaseArray<BlendTweenRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BlendAnimationInterface_GetTweens); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetTweens_Offset), mt_.BlendAnimationInterface_GetTweens));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(BlendAnimationInterface_StartAnimation); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_StartAnimation_Offset), mt_.BlendAnimationInterface_StartAnimation, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_StartAnimation); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_StartAnimation_Offset), mt_.BlendAnimationInterface_StartAnimation, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetProgress() const -> HXXADDRET2(Float)
{
	HXXRETURN0(HXXADDRET2(Float)); HXXRES; HXXCONST(0) HXXTABLE(BlendAnimationInterface_GetProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetProgress_Offset), mt_.BlendAnimationInterface_GetProgress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetState() const -> HXXADDRET2(ANIMBLENDSTATE)
{
	HXXRETURN0(HXXADDRET2(ANIMBLENDSTATE)); HXXRES; HXXCONST(HXXRET3(NULLPTR, ANIMBLENDSTATE)) HXXTABLE(BlendAnimationInterface_GetState); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetState_Offset), mt_.BlendAnimationInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::CancelAndWait() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(BlendAnimationInterface_CancelAndWait); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_CancelAndWait_Offset), mt_.BlendAnimationInterface_CancelAndWait);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::CancelAndWait() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_CancelAndWait); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_CancelAndWait_Offset), mt_.BlendAnimationInterface_CancelAndWait);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetTimerRef() const -> Result<TimerRef>
{
	HXXRETURN0(Result<TimerRef>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(BlendAnimationInterface_GetTimerRef); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetTimerRef_Offset), mt_.BlendAnimationInterface_GetTimerRef));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::SetStartProgress(Float startProgress) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(BlendAnimationInterface_SetStartProgress); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetStartProgress_Offset), mt_.BlendAnimationInterface_SetStartProgress, startProgress);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::SetStartProgress(Float startProgress) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_SetStartProgress); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetStartProgress_Offset), mt_.BlendAnimationInterface_SetStartProgress, startProgress);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::SetDirection(Bool reverse) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(BlendAnimationInterface_SetDirection); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetDirection_Offset), mt_.BlendAnimationInterface_SetDirection, reverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::SetDirection(Bool reverse) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(BlendAnimationInterface_SetDirection); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetDirection_Offset), mt_.BlendAnimationInterface_SetDirection, reverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto BlendAnimationInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BlendAnimationInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_blend_animation)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BlendAnimationInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BlendAnimationInterface() { new (s_ui_maxon_BlendAnimationInterface) maxon::EntityUse(BlendAnimationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_animation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BlendAnimationInterface(BlendAnimationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_animation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

