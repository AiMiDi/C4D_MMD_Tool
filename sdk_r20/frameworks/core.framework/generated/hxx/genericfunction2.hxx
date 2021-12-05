
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct FunctionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetConstantValue);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFunctionType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Invoke);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const FunctionDataType* (*_FunctionInterface_GetFunctionType) (const maxon::GenericComponent* this_);
	maxon::Int _FunctionInterface_GetFunctionType_Offset;
	Result<void> (*_FunctionInterface_Invoke) (const maxon::GenericComponent* this_, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs);
	maxon::Int _FunctionInterface_Invoke_Offset;
	Result<void> (*_FunctionInterface_Invoke_1) (const maxon::GenericComponent* this_, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData);
	maxon::Int _FunctionInterface_Invoke_1_Offset;
	ConstDataPtr (*_FunctionInterface_GetConstantValue) (const maxon::GenericComponent* this_, const Member& output);
	maxon::Int _FunctionInterface_GetConstantValue_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, GetFunctionType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, GetFunctionType), W, MTable>::type::_FunctionInterface_GetFunctionType;
			_FunctionInterface_GetFunctionType = reinterpret_cast<const decltype(_FunctionInterface_GetFunctionType)&>(ptr);
			_FunctionInterface_GetFunctionType_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, Invoke))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, Invoke), W, MTable>::type::_FunctionInterface_Invoke;
			_FunctionInterface_Invoke = reinterpret_cast<const decltype(_FunctionInterface_Invoke)&>(ptr);
			_FunctionInterface_Invoke_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, Invoke))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, Invoke), W, MTable>::type::_FunctionInterface_Invoke_1;
			_FunctionInterface_Invoke_1 = reinterpret_cast<const decltype(_FunctionInterface_Invoke_1)&>(ptr);
			_FunctionInterface_Invoke_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, GetConstantValue))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FunctionInterface, GetConstantValue), W, MTable>::type::_FunctionInterface_GetConstantValue;
			_FunctionInterface_GetConstantValue = reinterpret_cast<const decltype(_FunctionInterface_GetConstantValue)&>(ptr);
			_FunctionInterface_GetConstantValue_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FunctionInterface, Object::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FunctionInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class FunctionInterface::Wrapper : public Object::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetConstantValue);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFunctionType);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Invoke);
	static const FunctionDataType* _FunctionInterface_GetFunctionType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFunctionType(); }
	static Result<void> _FunctionInterface_Invoke(const maxon::GenericComponent* this_, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) { return ((const typename S::Implementation*) this_)->Invoke(outputs, inputs); }
	static Result<void> _FunctionInterface_Invoke_1(const maxon::GenericComponent* this_, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) { return ((const typename S::Implementation*) this_)->Invoke(outputs, inputs, cacheData); }
	static ConstDataPtr _FunctionInterface_GetConstantValue(const maxon::GenericComponent* this_, const Member& output) { return ((const typename S::Implementation*) this_)->GetConstantValue(output); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::GetFunctionType() const -> const FunctionDataType*
{
	const FunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionInterface, this); return mt_._FunctionInterface_GetFunctionType((const maxon::GenericComponent*) this + mt_._FunctionInterface_GetFunctionType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const -> Result<void>
{
	const FunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionInterface, this); return mt_._FunctionInterface_Invoke((const maxon::GenericComponent*) this + mt_._FunctionInterface_Invoke_Offset, outputs, inputs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const -> Result<void>
{
	const FunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionInterface, this); return mt_._FunctionInterface_Invoke_1((const maxon::GenericComponent*) this + mt_._FunctionInterface_Invoke_1_Offset, outputs, inputs, cacheData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::GetConstantValue(const Member& output) const -> ConstDataPtr
{
	const FunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FunctionInterface, this); return mt_._FunctionInterface_GetConstantValue((const maxon::GenericComponent*) this + mt_._FunctionInterface_GetConstantValue_Offset, output);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::ConstReferenceFunctionsImpl<S>::GetFunctionType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const FunctionDataType*>, const FunctionDataType*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const FunctionDataType*>, const FunctionDataType*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionInterface* o_ = (const FunctionInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FunctionInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionInterface, o_, FunctionInterface_GetFunctionType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionInterface>() : PRIVATE_MAXON_VTABLE(FunctionInterface, o_); 
	return (mt_._FunctionInterface_GetFunctionType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FunctionInterface_GetFunctionType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::ConstReferenceFunctionsImpl<S>::Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionInterface* o_ = (const FunctionInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FunctionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionInterface, o_, FunctionInterface_Invoke) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionInterface>() : PRIVATE_MAXON_VTABLE(FunctionInterface, o_); 
	return (mt_._FunctionInterface_Invoke(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FunctionInterface_Invoke_Offset, outputs, inputs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::ConstReferenceFunctionsImpl<S>::Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionInterface* o_ = (const FunctionInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FunctionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionInterface, o_, FunctionInterface_Invoke_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionInterface>() : PRIVATE_MAXON_VTABLE(FunctionInterface, o_); 
	return (mt_._FunctionInterface_Invoke_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FunctionInterface_Invoke_1_Offset, outputs, inputs, cacheData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionInterface::ConstReferenceFunctionsImpl<S>::GetConstantValue(const Member& output) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FunctionInterface* o_ = (const FunctionInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FunctionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FunctionInterface, o_, FunctionInterface_GetConstantValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FunctionInterface>() : PRIVATE_MAXON_VTABLE(FunctionInterface, o_); 
	return (mt_._FunctionInterface_GetConstantValue(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FunctionInterface_GetConstantValue_Offset, output));
}
auto FunctionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FunctionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_FunctionInterface(FunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/genericfunction.h", false);
#endif

struct FunctionLib::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Class<GenericFunction> (*_FunctionLib_GetConstantFunctionClass) ();
	Result<GenericFunction> (*_FunctionLib_CreateConstantFunction) (InternedId outputId, const DataType* resultType, const ConstDataPtr& value);
	Result<GenericFunction> (*_FunctionLib_PrivateCreateWrapper) (void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_FunctionLib_GetConstantFunctionClass = &IMPL::_FunctionLib_GetConstantFunctionClass;
		tbl->_FunctionLib_CreateConstantFunction = &IMPL::_FunctionLib_CreateConstantFunction;
		tbl->_FunctionLib_PrivateCreateWrapper = &IMPL::_FunctionLib_PrivateCreateWrapper;
	}
};

template <typename C> class FunctionLib::Wrapper
{
public:
	static Class<GenericFunction> _FunctionLib_GetConstantFunctionClass() { return C::GetConstantFunctionClass(); }
	static Result<GenericFunction> _FunctionLib_CreateConstantFunction(InternedId outputId, const DataType* resultType, const ConstDataPtr& value) { return C::CreateConstantFunction(std::forward<InternedId>(outputId), resultType, value); }
	static Result<GenericFunction> _FunctionLib_PrivateCreateWrapper(void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke) { return C::PrivateCreateWrapper(function, type, std::forward<DestructWrapper>(destruct), std::forward<InvokeWrapper>(invoke)); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionLib::GetConstantFunctionClass() -> Class<GenericFunction>
{
	return MTable::_instance._FunctionLib_GetConstantFunctionClass();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionLib::CreateConstantFunction(InternedId outputId, const DataType* resultType, const ConstDataPtr& value) -> Result<GenericFunction>
{
	return MTable::_instance._FunctionLib_CreateConstantFunction(std::forward<InternedId>(outputId), resultType, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FunctionLib::PrivateCreateWrapper(void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke) -> Result<GenericFunction>
{
	return MTable::_instance._FunctionLib_PrivateCreateWrapper(function, type, std::forward<DestructWrapper>(destruct), std::forward<InvokeWrapper>(invoke));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_FunctionLib(FunctionLib::_interface.GetReference(), &maxon::g_translationUnit, "maxon/genericfunction.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

