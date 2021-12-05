
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Data> (*_BlendTweenInterface_GetMappedValue) (maxon::GenericComponent* this_, Float xValue);
	maxon::Int _BlendTweenInterface_GetMappedValue_Offset;
	Result<void> (*_BlendTweenInterface_SetNewTarget) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& endValue);
	maxon::Int _BlendTweenInterface_SetNewTarget_Offset;
	Result<void> (*_BlendTweenInterface_SetFunction) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction);
	maxon::Int _BlendTweenInterface_SetFunction_Offset;
	BlendFunctionRef (*_BlendTweenInterface_GetFunction) (const maxon::GenericComponent* this_);
	maxon::Int _BlendTweenInterface_GetFunction_Offset;
	Result<void> (*_BlendTweenInterface_SetStart) (maxon::GenericComponent* this_, const Data& value);
	maxon::Int _BlendTweenInterface_SetStart_Offset;
	Result<Data> (*_BlendTweenInterface_GetStart) (const maxon::GenericComponent* this_);
	maxon::Int _BlendTweenInterface_GetStart_Offset;
	Result<void> (*_BlendTweenInterface_SetEnd) (maxon::GenericComponent* this_, const Data& value);
	maxon::Int _BlendTweenInterface_SetEnd_Offset;
	Result<Data> (*_BlendTweenInterface_GetEnd) (const maxon::GenericComponent* this_);
	maxon::Int _BlendTweenInterface_GetEnd_Offset;
	maxon::ObservableRef<ObservableAnimationDelegate> (*_BlendTweenInterface_ObservableAnimation) (const maxon::GenericComponent* this_);
	maxon::Int _BlendTweenInterface_ObservableAnimation_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetMappedValue))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetMappedValue), W, MTable>::type::_BlendTweenInterface_GetMappedValue;
			_BlendTweenInterface_GetMappedValue = reinterpret_cast<const decltype(_BlendTweenInterface_GetMappedValue)&>(ptr);
			_BlendTweenInterface_GetMappedValue_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetNewTarget))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetNewTarget), W, MTable>::type::_BlendTweenInterface_SetNewTarget;
			_BlendTweenInterface_SetNewTarget = reinterpret_cast<const decltype(_BlendTweenInterface_SetNewTarget)&>(ptr);
			_BlendTweenInterface_SetNewTarget_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetFunction))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetFunction), W, MTable>::type::_BlendTweenInterface_SetFunction;
			_BlendTweenInterface_SetFunction = reinterpret_cast<const decltype(_BlendTweenInterface_SetFunction)&>(ptr);
			_BlendTweenInterface_SetFunction_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetFunction))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetFunction), W, MTable>::type::_BlendTweenInterface_GetFunction;
			_BlendTweenInterface_GetFunction = reinterpret_cast<const decltype(_BlendTweenInterface_GetFunction)&>(ptr);
			_BlendTweenInterface_GetFunction_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetStart))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetStart), W, MTable>::type::_BlendTweenInterface_SetStart;
			_BlendTweenInterface_SetStart = reinterpret_cast<const decltype(_BlendTweenInterface_SetStart)&>(ptr);
			_BlendTweenInterface_SetStart_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetStart))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetStart), W, MTable>::type::_BlendTweenInterface_GetStart;
			_BlendTweenInterface_GetStart = reinterpret_cast<const decltype(_BlendTweenInterface_GetStart)&>(ptr);
			_BlendTweenInterface_GetStart_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetEnd))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, SetEnd), W, MTable>::type::_BlendTweenInterface_SetEnd;
			_BlendTweenInterface_SetEnd = reinterpret_cast<const decltype(_BlendTweenInterface_SetEnd)&>(ptr);
			_BlendTweenInterface_SetEnd_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetEnd))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, GetEnd), W, MTable>::type::_BlendTweenInterface_GetEnd;
			_BlendTweenInterface_GetEnd = reinterpret_cast<const decltype(_BlendTweenInterface_GetEnd)&>(ptr);
			_BlendTweenInterface_GetEnd_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, ObservableAnimation))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendTweenInterface, ObservableAnimation), W, MTable>::type::_BlendTweenInterface_ObservableAnimation;
			_BlendTweenInterface_ObservableAnimation = reinterpret_cast<const decltype(_BlendTweenInterface_ObservableAnimation)&>(ptr);
			_BlendTweenInterface_ObservableAnimation_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BlendTweenInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(BlendTweenInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BlendTweenInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
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
	static Result<Data> _BlendTweenInterface_GetMappedValue(maxon::GenericComponent* this_, Float xValue) { return ((typename S::Implementation*) this_)->GetMappedValue(xValue); }
	static Result<void> _BlendTweenInterface_SetNewTarget(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& endValue) { return ((typename S::Implementation*) this_)->SetNewTarget(blendFunction, endValue); }
	static Result<void> _BlendTweenInterface_SetFunction(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction) { return ((typename S::Implementation*) this_)->SetFunction(blendFunction); }
	static BlendFunctionRef _BlendTweenInterface_GetFunction(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFunction(); }
	static Result<void> _BlendTweenInterface_SetStart(maxon::GenericComponent* this_, const Data& value) { return ((typename S::Implementation*) this_)->SetStart(value); }
	static Result<Data> _BlendTweenInterface_GetStart(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStart(); }
	static Result<void> _BlendTweenInterface_SetEnd(maxon::GenericComponent* this_, const Data& value) { return ((typename S::Implementation*) this_)->SetEnd(value); }
	static Result<Data> _BlendTweenInterface_GetEnd(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEnd(); }
	static maxon::ObservableRef<ObservableAnimationDelegate> _BlendTweenInterface_ObservableAnimation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableAnimation(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetMappedValue(Float xValue) -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_GetMappedValue((maxon::GenericComponent*) this + mt_._BlendTweenInterface_GetMappedValue_Offset, xValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_SetNewTarget((maxon::GenericComponent*) this + mt_._BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_SetFunction((maxon::GenericComponent*) this + mt_._BlendTweenInterface_SetFunction_Offset, blendFunction);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetFunction() const -> BlendFunctionRef
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_GetFunction((const maxon::GenericComponent*) this + mt_._BlendTweenInterface_GetFunction_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetStart(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_SetStart((maxon::GenericComponent*) this + mt_._BlendTweenInterface_SetStart_Offset, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetStart() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_GetStart((const maxon::GenericComponent*) this + mt_._BlendTweenInterface_GetStart_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::SetEnd(const Data& value) -> Result<void>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_SetEnd((maxon::GenericComponent*) this + mt_._BlendTweenInterface_SetEnd_Offset, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::GetEnd() const -> Result<Data>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_GetEnd((const maxon::GenericComponent*) this + mt_._BlendTweenInterface_GetEnd_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::ObservableAnimation() const -> maxon::ObservableRef<ObservableAnimationDelegate>
{
	const BlendTweenInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendTweenInterface, this); return mt_._BlendTweenInterface_ObservableAnimation((const maxon::GenericComponent*) this + mt_._BlendTweenInterface_ObservableAnimation_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ReferenceFunctionsImpl<S>::GetMappedValue(Float xValue) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetMappedValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_GetMappedValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetMappedValue_Offset, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetMappedValue(Float xValue) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetMappedValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_GetMappedValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetMappedValue_Offset, xValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ReferenceFunctionsImpl<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetNewTarget) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetNewTarget(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetNewTarget) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetNewTarget(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetNewTarget_Offset, blendFunction, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ReferenceFunctionsImpl<S>::SetFunction(const BlendFunctionRef& blendFunction) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetFunction_Offset, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetFunction(const BlendFunctionRef& blendFunction) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetFunction(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetFunction_Offset, blendFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BlendFunctionRef>, BlendFunctionRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BlendFunctionRef>, BlendFunctionRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BlendFunctionRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetFunction) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_GetFunction(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetFunction_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ReferenceFunctionsImpl<S>::SetStart(const Data& value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetStart(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetStart_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetStart(const Data& value) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetStart(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetStart_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetStart() const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetStart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_GetStart(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetStart_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ReferenceFunctionsImpl<S>::SetEnd(const Data& value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetEnd(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetEnd_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetEnd(const Data& value) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendTweenInterface* o_ = (BlendTweenInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_SetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_SetEnd(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_SetEnd_Offset, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEnd() const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_GetEnd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_GetEnd(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_GetEnd_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendTweenInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableAnimation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableAnimationDelegate>>, maxon::ObservableRef<ObservableAnimationDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableAnimationDelegate>>, maxon::ObservableRef<ObservableAnimationDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendTweenInterface* o_ = (const BlendTweenInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendTweenInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableAnimationDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendTweenInterface, o_, BlendTweenInterface_ObservableAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendTweenInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendTweenInterface>() : PRIVATE_MAXON_VTABLE(BlendTweenInterface, o_); 
	return (mt_._BlendTweenInterface_ObservableAnimation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendTweenInterface_ObservableAnimation_Offset));
}
auto BlendTweenInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BlendTweenInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(StartAnimation);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<BlendTweenRef> (*_BlendAnimationInterface_AddTween) (maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue);
	maxon::Int _BlendAnimationInterface_AddTween_Offset;
	Result<void> (*_BlendAnimationInterface_RemoveTween) (maxon::GenericComponent* this_, const BlendTweenRef& tween);
	maxon::Int _BlendAnimationInterface_RemoveTween_Offset;
	Result<BaseArray<BlendTweenRef>> (*_BlendAnimationInterface_GetTweens) (const maxon::GenericComponent* this_);
	maxon::Int _BlendAnimationInterface_GetTweens_Offset;
	Result<void> (*_BlendAnimationInterface_StartAnimation) (maxon::GenericComponent* this_, const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration);
	maxon::Int _BlendAnimationInterface_StartAnimation_Offset;
	Float (*_BlendAnimationInterface_GetProgress) (const maxon::GenericComponent* this_);
	maxon::Int _BlendAnimationInterface_GetProgress_Offset;
	ANIMBLENDSTATE (*_BlendAnimationInterface_GetState) (const maxon::GenericComponent* this_);
	maxon::Int _BlendAnimationInterface_GetState_Offset;
	void (*_BlendAnimationInterface_CancelAndWait) (maxon::GenericComponent* this_);
	maxon::Int _BlendAnimationInterface_CancelAndWait_Offset;
	Result<TimerRef> (*_BlendAnimationInterface_GetTimerRef) (const maxon::GenericComponent* this_);
	maxon::Int _BlendAnimationInterface_GetTimerRef_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, AddTween))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, AddTween), W, MTable>::type::_BlendAnimationInterface_AddTween;
			_BlendAnimationInterface_AddTween = reinterpret_cast<const decltype(_BlendAnimationInterface_AddTween)&>(ptr);
			_BlendAnimationInterface_AddTween_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, RemoveTween))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, RemoveTween), W, MTable>::type::_BlendAnimationInterface_RemoveTween;
			_BlendAnimationInterface_RemoveTween = reinterpret_cast<const decltype(_BlendAnimationInterface_RemoveTween)&>(ptr);
			_BlendAnimationInterface_RemoveTween_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTweens))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTweens), W, MTable>::type::_BlendAnimationInterface_GetTweens;
			_BlendAnimationInterface_GetTweens = reinterpret_cast<const decltype(_BlendAnimationInterface_GetTweens)&>(ptr);
			_BlendAnimationInterface_GetTweens_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, StartAnimation))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, StartAnimation), W, MTable>::type::_BlendAnimationInterface_StartAnimation;
			_BlendAnimationInterface_StartAnimation = reinterpret_cast<const decltype(_BlendAnimationInterface_StartAnimation)&>(ptr);
			_BlendAnimationInterface_StartAnimation_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetProgress))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetProgress), W, MTable>::type::_BlendAnimationInterface_GetProgress;
			_BlendAnimationInterface_GetProgress = reinterpret_cast<const decltype(_BlendAnimationInterface_GetProgress)&>(ptr);
			_BlendAnimationInterface_GetProgress_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetState))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetState), W, MTable>::type::_BlendAnimationInterface_GetState;
			_BlendAnimationInterface_GetState = reinterpret_cast<const decltype(_BlendAnimationInterface_GetState)&>(ptr);
			_BlendAnimationInterface_GetState_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, CancelAndWait))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, CancelAndWait), W, MTable>::type::_BlendAnimationInterface_CancelAndWait;
			_BlendAnimationInterface_CancelAndWait = reinterpret_cast<const decltype(_BlendAnimationInterface_CancelAndWait)&>(ptr);
			_BlendAnimationInterface_CancelAndWait_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTimerRef))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendAnimationInterface, GetTimerRef), W, MTable>::type::_BlendAnimationInterface_GetTimerRef;
			_BlendAnimationInterface_GetTimerRef = reinterpret_cast<const decltype(_BlendAnimationInterface_GetTimerRef)&>(ptr);
			_BlendAnimationInterface_GetTimerRef_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BlendAnimationInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(BlendAnimationInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BlendAnimationInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddTween);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CancelAndWait);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTimerRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTweens);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveTween);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(StartAnimation);
	static Result<BlendTweenRef> _BlendAnimationInterface_AddTween(maxon::GenericComponent* this_, const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) { return ((typename S::Implementation*) this_)->AddTween(blendFunction, startValue, endValue); }
	static Result<void> _BlendAnimationInterface_RemoveTween(maxon::GenericComponent* this_, const BlendTweenRef& tween) { return ((typename S::Implementation*) this_)->RemoveTween(tween); }
	static Result<BaseArray<BlendTweenRef>> _BlendAnimationInterface_GetTweens(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTweens(); }
	static Result<void> _BlendAnimationInterface_StartAnimation(maxon::GenericComponent* this_, const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) { return ((typename S::Implementation*) this_)->StartAnimation(timerInterval, startDelay, duration); }
	static Float _BlendAnimationInterface_GetProgress(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProgress(); }
	static ANIMBLENDSTATE _BlendAnimationInterface_GetState(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetState(); }
	static void _BlendAnimationInterface_CancelAndWait(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CancelAndWait(); }
	static Result<TimerRef> _BlendAnimationInterface_GetTimerRef(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTimerRef(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_AddTween((maxon::GenericComponent*) this + mt_._BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_RemoveTween((maxon::GenericComponent*) this + mt_._BlendAnimationInterface_RemoveTween_Offset, tween);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_GetTweens((const maxon::GenericComponent*) this + mt_._BlendAnimationInterface_GetTweens_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_StartAnimation((maxon::GenericComponent*) this + mt_._BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetProgress() const -> Float
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_GetProgress((const maxon::GenericComponent*) this + mt_._BlendAnimationInterface_GetProgress_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetState() const -> ANIMBLENDSTATE
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_GetState((const maxon::GenericComponent*) this + mt_._BlendAnimationInterface_GetState_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::CancelAndWait() -> void
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_CancelAndWait((maxon::GenericComponent*) this + mt_._BlendAnimationInterface_CancelAndWait_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::GetTimerRef() const -> Result<TimerRef>
{
	const BlendAnimationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendAnimationInterface, this); return mt_._BlendAnimationInterface_GetTimerRef((const maxon::GenericComponent*) this + mt_._BlendAnimationInterface_GetTimerRef_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ReferenceFunctionsImpl<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) const -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_AddTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_AddTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_AddTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_AddTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_AddTween_Offset, blendFunction, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ReferenceFunctionsImpl<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) const -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) -> Result<BlendTweenRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BlendTweenRef>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION BlendAnimationInterface::AddTween on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->AddTween(blendFunction, startValue, endValue, std::forward<AnimBlendTweenCallback>(callback), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveTween(const BlendTweenRef& tween) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_RemoveTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_RemoveTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_RemoveTween_Offset, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveTween(const BlendTweenRef& tween) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_RemoveTween) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_RemoveTween(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_RemoveTween_Offset, tween));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTweens() const -> Result<BaseArray<BlendTweenRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<BlendTweenRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetTweens) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_GetTweens(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetTweens_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ReferenceFunctionsImpl<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_StartAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_StartAnimation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWReferenceFunctionsImpl<S>::StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_StartAnimation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_StartAnimation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_StartAnimation_Offset, timerInterval, startDelay, duration));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetProgress() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_GetProgress(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetProgress_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ANIMBLENDSTATE>, ANIMBLENDSTATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ANIMBLENDSTATE>, ANIMBLENDSTATE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ANIMBLENDSTATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_GetState(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ReferenceFunctionsImpl<S>::CancelAndWait() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_CancelAndWait) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_._BlendAnimationInterface_CancelAndWait(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_CancelAndWait_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::COWReferenceFunctionsImpl<S>::CancelAndWait() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BlendAnimationInterface* o_ = (BlendAnimationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_CancelAndWait) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	mt_._BlendAnimationInterface_CancelAndWait(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_CancelAndWait_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendAnimationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTimerRef() const -> Result<TimerRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<TimerRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BlendAnimationInterface* o_ = (const BlendAnimationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BlendAnimationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendAnimationInterface, o_, BlendAnimationInterface_GetTimerRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BlendAnimationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendAnimationInterface>() : PRIVATE_MAXON_VTABLE(BlendAnimationInterface, o_); 
	return (mt_._BlendAnimationInterface_GetTimerRef(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BlendAnimationInterface_GetTimerRef_Offset));
}
auto BlendAnimationInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BlendAnimationInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

