
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
	Result<Data> (*BlendTweenInterface_GetMappedValue) (maxon::GenericComponent* this_, Float xValue);
	maxon::Int BlendTweenInterface_GetMappedValue_Offset;
	Result<void> (*BlendTweenInterface_SetNewTarget) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& endValue);
	maxon::Int BlendTweenInterface_SetNewTarget_Offset;
	Result<void> (*BlendTweenInterface_SetFunction) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction);
	maxon::Int BlendTweenInterface_SetFunction_Offset;
	BlendFunctionRef (*BlendTweenInterface_GetFunction) (const maxon::GenericComponent* this_);
	maxon::Int BlendTweenInterface_GetFunction_Offset;
	Result<void> (*BlendTweenInterface_SetStart) (maxon::GenericComponent* this_, const Data& value);
	maxon::Int BlendTweenInterface_SetStart_Offset;
	Result<Data> (*BlendTweenInterface_GetStart) (const maxon::GenericComponent* this_);
	maxon::Int BlendTweenInterface_GetStart_Offset;
	Result<void> (*BlendTweenInterface_SetEnd) (maxon::GenericComponent* this_, const Data& value);
	maxon::Int BlendTweenInterface_SetEnd_Offset;
	Result<Data> (*BlendTweenInterface_GetEnd) (const maxon::GenericComponent* this_);
	maxon::Int BlendTweenInterface_GetEnd_Offset;
	maxon::ObservableRef<ObservableAnimationDelegate> (*BlendTweenInterface_ObservableAnimation) (const maxon::GenericComponent* this_);
	maxon::Int BlendTweenInterface_ObservableAnimation_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetMappedValue))
	{
		BlendTweenInterface_GetMappedValue = &W::BlendTweenInterface_GetMappedValue;
		BlendTweenInterface_GetMappedValue_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetNewTarget))
	{
		BlendTweenInterface_SetNewTarget = &W::BlendTweenInterface_SetNewTarget;
		BlendTweenInterface_SetNewTarget_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetFunction))
	{
		BlendTweenInterface_SetFunction = &W::BlendTweenInterface_SetFunction;
		BlendTweenInterface_SetFunction_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetFunction))
	{
		BlendTweenInterface_GetFunction = &W::BlendTweenInterface_GetFunction;
		BlendTweenInterface_GetFunction_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetStart))
	{
		BlendTweenInterface_SetStart = &W::BlendTweenInterface_SetStart;
		BlendTweenInterface_SetStart_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetStart))
	{
		BlendTweenInterface_GetStart = &W::BlendTweenInterface_GetStart;
		BlendTweenInterface_GetStart_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetEnd))
	{
		BlendTweenInterface_SetEnd = &W::BlendTweenInterface_SetEnd;
		BlendTweenInterface_SetEnd_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetEnd))
	{
		BlendTweenInterface_GetEnd = &W::BlendTweenInterface_GetEnd;
		BlendTweenInterface_GetEnd_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, ObservableAnimation))
	{
		BlendTweenInterface_ObservableAnimation = &W::BlendTweenInterface_ObservableAnimation;
		BlendTweenInterface_ObservableAnimation_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BlendTweenInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (BlendTweenInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BlendTweenInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<Data> BlendTweenInterface_GetMappedValue(maxon::GenericComponent* this_, Float xValue) { return ((typename S::Implementation*) this_)->GetMappedValue(xValue); }
		static Result<void> BlendTweenInterface_SetNewTarget(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& endValue) { return ((typename S::Implementation*) this_)->SetNewTarget(blendFunction, endValue); }
		static Result<void> BlendTweenInterface_SetFunction(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction) { return ((typename S::Implementation*) this_)->SetFunction(blendFunction); }
		static BlendFunctionRef BlendTweenInterface_GetFunction(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFunction(); }
		static Result<void> BlendTweenInterface_SetStart(maxon::GenericComponent* this_, const Data& value) { return ((typename S::Implementation*) this_)->SetStart(value); }
		static Result<Data> BlendTweenInterface_GetStart(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStart(); }
		static Result<void> BlendTweenInterface_SetEnd(maxon::GenericComponent* this_, const Data& value) { return ((typename S::Implementation*) this_)->SetEnd(value); }
		static Result<Data> BlendTweenInterface_GetEnd(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEnd(); }
		static maxon::ObservableRef<ObservableAnimationDelegate> BlendTweenInterface_ObservableAnimation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableAnimation(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetMappedValue(Float xValue) -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_GetMappedValue((maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetMappedValue_Offset, xValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_SetNewTarget((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_SetFunction((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetFunction_Offset, blendFunction);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetFunction() const -> BlendFunctionRef
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_GetFunction((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetFunction_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetStart(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_SetStart((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetStart_Offset, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetStart() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_GetStart((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetStart_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetEnd(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_SetEnd((maxon::GenericComponent*) this + mt_.BlendTweenInterface_SetEnd_Offset, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetEnd() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_GetEnd((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_GetEnd_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::ObservableAnimation() const -> maxon::ObservableRef<ObservableAnimationDelegate>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_.BlendTweenInterface_ObservableAnimation((const maxon::GenericComponent*) this + mt_.BlendTweenInterface_ObservableAnimation_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::GetMappedValue(Float xValue) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetMappedValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_GetMappedValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetMappedValue_Offset, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::GetMappedValue(Float xValue) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetMappedValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_GetMappedValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetMappedValue_Offset, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetNewTarget) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetNewTarget(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetNewTarget) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetNewTarget(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetFunction(const BlendFunctionRef& blendFunction) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetFunction_Offset, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetFunction_Offset, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BlendFunctionRef>, BlendFunctionRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BlendFunctionRef>, BlendFunctionRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BlendFunctionRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_GetFunction(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetFunction_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetStart(const Data& value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetStart(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetStart_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetStart(const Data& value) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetStart(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetStart_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetStart() const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_GetStart(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetStart_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::Fn<S>::SetEnd(const Data& value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetEnd(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetEnd_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWFn<S>::SetEnd(const Data& value) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_SetEnd(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_SetEnd_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::GetEnd() const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_GetEnd(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_GetEnd_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstFn<S>::ObservableAnimation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableAnimationDelegate>>, maxon::ObservableRef<ObservableAnimationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableAnimationDelegate>>, maxon::ObservableRef<ObservableAnimationDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableAnimationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_ObservableAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_.BlendTweenInterface_ObservableAnimation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendTweenInterface_ObservableAnimation_Offset));
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
	Result<BlendTweenRef> (*BlendAnimationInterface_AddTween) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue);
	maxon::Int BlendAnimationInterface_AddTween_Offset;
	Result<void> (*BlendAnimationInterface_RemoveTween) (maxon::GenericComponent* this_, const BlendTweenRef& tween);
	maxon::Int BlendAnimationInterface_RemoveTween_Offset;
	Result<BaseArray<BlendTweenRef>> (*BlendAnimationInterface_GetTweens) (const maxon::GenericComponent* this_);
	maxon::Int BlendAnimationInterface_GetTweens_Offset;
	Result<void> (*BlendAnimationInterface_StartAnimation) (maxon::GenericComponent* this_, const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration);
	maxon::Int BlendAnimationInterface_StartAnimation_Offset;
	Float (*BlendAnimationInterface_GetProgress) (const maxon::GenericComponent* this_);
	maxon::Int BlendAnimationInterface_GetProgress_Offset;
	ANIMBLENDSTATE (*BlendAnimationInterface_GetState) (const maxon::GenericComponent* this_);
	maxon::Int BlendAnimationInterface_GetState_Offset;
	void (*BlendAnimationInterface_CancelAndWait) (maxon::GenericComponent* this_);
	maxon::Int BlendAnimationInterface_CancelAndWait_Offset;
	Result<TimerRef> (*BlendAnimationInterface_GetTimerRef) (const maxon::GenericComponent* this_);
	maxon::Int BlendAnimationInterface_GetTimerRef_Offset;
	void (*BlendAnimationInterface_SetStartProgress) (maxon::GenericComponent* this_, Float startProgress);
	maxon::Int BlendAnimationInterface_SetStartProgress_Offset;
	void (*BlendAnimationInterface_SetDirection) (maxon::GenericComponent* this_, Bool reverse);
	maxon::Int BlendAnimationInterface_SetDirection_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, AddTween))
	{
		BlendAnimationInterface_AddTween = &W::BlendAnimationInterface_AddTween;
		BlendAnimationInterface_AddTween_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, RemoveTween))
	{
		BlendAnimationInterface_RemoveTween = &W::BlendAnimationInterface_RemoveTween;
		BlendAnimationInterface_RemoveTween_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTweens))
	{
		BlendAnimationInterface_GetTweens = &W::BlendAnimationInterface_GetTweens;
		BlendAnimationInterface_GetTweens_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, StartAnimation))
	{
		BlendAnimationInterface_StartAnimation = &W::BlendAnimationInterface_StartAnimation;
		BlendAnimationInterface_StartAnimation_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetProgress))
	{
		BlendAnimationInterface_GetProgress = &W::BlendAnimationInterface_GetProgress;
		BlendAnimationInterface_GetProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetState))
	{
		BlendAnimationInterface_GetState = &W::BlendAnimationInterface_GetState;
		BlendAnimationInterface_GetState_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, CancelAndWait))
	{
		BlendAnimationInterface_CancelAndWait = &W::BlendAnimationInterface_CancelAndWait;
		BlendAnimationInterface_CancelAndWait_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTimerRef))
	{
		BlendAnimationInterface_GetTimerRef = &W::BlendAnimationInterface_GetTimerRef;
		BlendAnimationInterface_GetTimerRef_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, SetStartProgress))
	{
		BlendAnimationInterface_SetStartProgress = &W::BlendAnimationInterface_SetStartProgress;
		BlendAnimationInterface_SetStartProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, SetDirection))
	{
		BlendAnimationInterface_SetDirection = &W::BlendAnimationInterface_SetDirection;
		BlendAnimationInterface_SetDirection_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BlendAnimationInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (BlendAnimationInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BlendAnimationInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<BlendTweenRef> BlendAnimationInterface_AddTween(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) { return ((typename S::Implementation*) this_)->AddTween(blendFunction, startValue, endValue); }
		static Result<void> BlendAnimationInterface_RemoveTween(maxon::GenericComponent* this_, const BlendTweenRef& tween) { return ((typename S::Implementation*) this_)->RemoveTween(tween); }
		static Result<BaseArray<BlendTweenRef>> BlendAnimationInterface_GetTweens(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTweens(); }
		static Result<void> BlendAnimationInterface_StartAnimation(maxon::GenericComponent* this_, const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) { return ((typename S::Implementation*) this_)->StartAnimation(timerInterval, startDelay, duration); }
		static Float BlendAnimationInterface_GetProgress(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProgress(); }
		static ANIMBLENDSTATE BlendAnimationInterface_GetState(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetState(); }
		static void BlendAnimationInterface_CancelAndWait(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CancelAndWait(); }
		static Result<TimerRef> BlendAnimationInterface_GetTimerRef(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTimerRef(); }
		static void BlendAnimationInterface_SetStartProgress(maxon::GenericComponent* this_, Float startProgress) { return ((typename S::Implementation*) this_)->SetStartProgress(startProgress); }
		static void BlendAnimationInterface_SetDirection(maxon::GenericComponent* this_, Bool reverse) { return ((typename S::Implementation*) this_)->SetDirection(reverse); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_AddTween((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_RemoveTween((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_RemoveTween_Offset, tween);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_GetTweens((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetTweens_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_StartAnimation((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetProgress() const -> Float
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_GetProgress((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetProgress_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetState() const -> ANIMBLENDSTATE
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_GetState((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetState_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::CancelAndWait() -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_CancelAndWait((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_CancelAndWait_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTimerRef() const -> Result<TimerRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_GetTimerRef((const maxon::GenericComponent*) this + mt_.BlendAnimationInterface_GetTimerRef_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::SetStartProgress(Float startProgress) -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_SetStartProgress((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_SetStartProgress_Offset, startProgress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::SetDirection(Bool reverse) -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_.BlendAnimationInterface_SetDirection((maxon::GenericComponent*) this + mt_.BlendAnimationInterface_SetDirection_Offset, reverse);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) const -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_AddTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_AddTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_AddTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_AddTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) const -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION BlendAnimationInterface::AddTween on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::RemoveTween(const BlendTweenRef& tween) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_RemoveTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_RemoveTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_RemoveTween_Offset, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_RemoveTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_RemoveTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_RemoveTween_Offset, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<BlendTweenRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetTweens) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_GetTweens(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetTweens_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_StartAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_StartAnimation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_StartAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_StartAnimation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetProgress() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_GetProgress(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetProgress_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ANIMBLENDSTATE>, ANIMBLENDSTATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ANIMBLENDSTATE>, ANIMBLENDSTATE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ANIMBLENDSTATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_GetState(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::CancelAndWait() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_CancelAndWait) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_CancelAndWait(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_CancelAndWait_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::CancelAndWait() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_CancelAndWait) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_CancelAndWait(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_CancelAndWait_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstFn<S>::GetTimerRef() const -> Result<TimerRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<TimerRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetTimerRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_.BlendAnimationInterface_GetTimerRef(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_GetTimerRef_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::SetStartProgress(Float startProgress) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_SetStartProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_SetStartProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetStartProgress_Offset, startProgress);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::SetStartProgress(Float startProgress) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_SetStartProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_SetStartProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetStartProgress_Offset, startProgress);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::Fn<S>::SetDirection(Bool reverse) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_SetDirection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_SetDirection(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetDirection_Offset, reverse);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWFn<S>::SetDirection(Bool reverse) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_SetDirection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_.BlendAnimationInterface_SetDirection(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendAnimationInterface_SetDirection_Offset, reverse);
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

