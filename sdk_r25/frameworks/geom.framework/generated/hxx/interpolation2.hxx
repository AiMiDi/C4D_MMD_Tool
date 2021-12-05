
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct InterpolateTypeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Average);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInterpolateDataType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateInOutline);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateLinear);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType& (*_InterpolateTypeInterface_GetInterpolateDataType) (const maxon::GenericComponent* this_);
	maxon::Int _InterpolateTypeInterface_GetInterpolateDataType_Offset;
	void (*_InterpolateTypeInterface_InterpolateLinear) (const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend);
	maxon::Int _InterpolateTypeInterface_InterpolateLinear_Offset;
	void (*_InterpolateTypeInterface_InterpolateInOutline) (const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights);
	maxon::Int _InterpolateTypeInterface_InterpolateInOutline_Offset;
	void (*_InterpolateTypeInterface_Average) (const maxon::GenericComponent* this_, void* data, const Block<const void*>& dataSet);
	maxon::Int _InterpolateTypeInterface_Average_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, GetInterpolateDataType))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, GetInterpolateDataType), W, MTable>::type::_InterpolateTypeInterface_GetInterpolateDataType;
		_InterpolateTypeInterface_GetInterpolateDataType = reinterpret_cast<const decltype(_InterpolateTypeInterface_GetInterpolateDataType)&>(ptr);
		_InterpolateTypeInterface_GetInterpolateDataType_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateLinear))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateLinear), W, MTable>::type::_InterpolateTypeInterface_InterpolateLinear;
		_InterpolateTypeInterface_InterpolateLinear = reinterpret_cast<const decltype(_InterpolateTypeInterface_InterpolateLinear)&>(ptr);
		_InterpolateTypeInterface_InterpolateLinear_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateInOutline))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateInOutline), W, MTable>::type::_InterpolateTypeInterface_InterpolateInOutline;
		_InterpolateTypeInterface_InterpolateInOutline = reinterpret_cast<const decltype(_InterpolateTypeInterface_InterpolateInOutline)&>(ptr);
		_InterpolateTypeInterface_InterpolateInOutline_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, Average))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, Average), W, MTable>::type::_InterpolateTypeInterface_Average;
		_InterpolateTypeInterface_Average = reinterpret_cast<const decltype(_InterpolateTypeInterface_Average)&>(ptr);
		_InterpolateTypeInterface_Average_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<InterpolateTypeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<InterpolateTypeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct InterpolateTypeInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	InterpolateType (*_InterpolateTypeInterface_GetInterpolationClass) (const DataType& datatype);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_InterpolateTypeInterface_GetInterpolationClass = &IMPL::_InterpolateTypeInterface_GetInterpolationClass;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Average);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInterpolateDataType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateInOutline);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateLinear);
		static const DataType& _InterpolateTypeInterface_GetInterpolateDataType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetInterpolateDataType(); }
		static void _InterpolateTypeInterface_InterpolateLinear(const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend) { return ((const typename S::Implementation*) this_)->InterpolateLinear(data1, data2, blend); }
		static void _InterpolateTypeInterface_InterpolateInOutline(const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights) { return ((const typename S::Implementation*) this_)->InterpolateInOutline(data, outline, weights); }
		static void _InterpolateTypeInterface_Average(const maxon::GenericComponent* this_, void* data, const Block<const void*>& dataSet) { return ((const typename S::Implementation*) this_)->Average(data, dataSet); }
		static InterpolateType _InterpolateTypeInterface_GetInterpolationClass(const DataType& datatype) { return S::Implementation::GetInterpolationClass(datatype); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::GetInterpolateDataType() const -> const DataType&
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return mt_._InterpolateTypeInterface_GetInterpolateDataType((const maxon::GenericComponent*) this + mt_._InterpolateTypeInterface_GetInterpolateDataType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::InterpolateLinear(void* data1, const void* data2, Float blend) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return mt_._InterpolateTypeInterface_InterpolateLinear((const maxon::GenericComponent*) this + mt_._InterpolateTypeInterface_InterpolateLinear_Offset, data1, data2, blend);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return mt_._InterpolateTypeInterface_InterpolateInOutline((const maxon::GenericComponent*) this + mt_._InterpolateTypeInterface_InterpolateInOutline_Offset, data, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Average(void* data, const Block<const void*>& dataSet) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return mt_._InterpolateTypeInterface_Average((const maxon::GenericComponent*) this + mt_._InterpolateTypeInterface_Average_Offset, data, dataSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::GetInterpolationClass(const DataType& datatype) -> InterpolateType
{
	return Hxx2::StaticMTable::_instance._InterpolateTypeInterface_GetInterpolationClass(datatype);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInterpolateDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_GetInterpolateDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	return (mt_._InterpolateTypeInterface_GetInterpolateDataType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._InterpolateTypeInterface_GetInterpolateDataType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InterpolateLinear(void* data1, const void* data2, Float blend) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_InterpolateLinear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	mt_._InterpolateTypeInterface_InterpolateLinear(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._InterpolateTypeInterface_InterpolateLinear_Offset, data1, data2, blend);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_InterpolateInOutline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	mt_._InterpolateTypeInterface_InterpolateInOutline(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._InterpolateTypeInterface_InterpolateInOutline_Offset, data, outline, weights);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Average(void* data, const Block<const void*>& dataSet) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_Average) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	mt_._InterpolateTypeInterface_Average(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._InterpolateTypeInterface_Average_Offset, data, dataSet);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InterpolateBilinear(const DataTypePtr dataType, void* data1, const void* data2, const void* data3, const void* data4, Float blendS, Float blendT) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION InterpolateTypeInterface::InterpolateBilinear on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->InterpolateBilinear(std::forward<const DataTypePtr>(dataType), data1, data2, data3, data4, blendS, blendT);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInterpolationClass(const DataType& datatype) -> InterpolateType
{
	return (Hxx2::StaticMTable::_instance._InterpolateTypeInterface_GetInterpolationClass(datatype));
}
auto InterpolateTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InterpolateTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InterpolateTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InterpolateTypeInterface() { new (s_ui_maxon_InterpolateTypeInterface) maxon::EntityUse(InterpolateTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InterpolateTypeInterface(InterpolateTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_InterpolateTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_InterpolateTypeInterface() { new (s_usi_maxon_InterpolateTypeInterface) maxon::EntityUse(InterpolateTypeInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_InterpolateTypeInterface(InterpolateTypeInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

