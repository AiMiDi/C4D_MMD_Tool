
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
	PRIVATE_MAXON_MF_POINTER(InterpolateTypeInterface_GetInterpolateDataType, GetInterpolateDataType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int InterpolateTypeInterface_GetInterpolateDataType_Offset;
	PRIVATE_MAXON_MF_POINTER(InterpolateTypeInterface_InterpolateLinear, InterpolateLinear, true, maxon::GenericComponent, const, (void), void* data1, const void* data2, Float blend);
	maxon::Int InterpolateTypeInterface_InterpolateLinear_Offset;
	PRIVATE_MAXON_MF_POINTER(InterpolateTypeInterface_InterpolateInOutline, InterpolateInOutline, true, maxon::GenericComponent, const, (void), void* data, const Block<void*>& outline, const Block<Float>& weights);
	maxon::Int InterpolateTypeInterface_InterpolateInOutline_Offset;
	PRIVATE_MAXON_MF_POINTER(InterpolateTypeInterface_Average, Average, true, maxon::GenericComponent, const, (void), void* data, const Block<const void*>& dataSet);
	maxon::Int InterpolateTypeInterface_Average_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, GetInterpolateDataType))
	{
		maxon::Tie(InterpolateTypeInterface_GetInterpolateDataType, InterpolateTypeInterface_GetInterpolateDataType_Offset) = InterpolateTypeInterface_GetInterpolateDataType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateLinear))
	{
		maxon::Tie(InterpolateTypeInterface_InterpolateLinear, InterpolateTypeInterface_InterpolateLinear_Offset) = InterpolateTypeInterface_InterpolateLinear_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, InterpolateInOutline))
	{
		maxon::Tie(InterpolateTypeInterface_InterpolateInOutline, InterpolateTypeInterface_InterpolateInOutline_Offset) = InterpolateTypeInterface_InterpolateInOutline_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InterpolateTypeInterface, Average))
	{
		maxon::Tie(InterpolateTypeInterface_Average, InterpolateTypeInterface_Average_Offset) = InterpolateTypeInterface_Average_GetPtr<W>(offset, true);
	}
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
	PRIVATE_MAXON_SF_POINTER(InterpolateTypeInterface_GetInterpolationClass, GetInterpolationClass, MAXON_EXPAND_VA_ARGS, (InterpolateType), const DataType& datatype);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->InterpolateTypeInterface_GetInterpolationClass = InterpolateTypeInterface_GetInterpolationClass_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Average);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInterpolateDataType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateInOutline);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateLinear);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (InterpolateTypeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, InterpolateTypeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(InterpolateTypeInterface_GetInterpolateDataType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetInterpolateDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(InterpolateTypeInterface_InterpolateLinear, maxon::GenericComponent, const, (void), void* data1, const void* data2, Float blend) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InterpolateLinear(data1, data2, blend); }
		PRIVATE_MAXON_MF_WRAPPER(InterpolateTypeInterface_InterpolateInOutline, maxon::GenericComponent, const, (void), void* data, const Block<void*>& outline, const Block<Float>& weights) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InterpolateInOutline(data, outline, weights); }
		PRIVATE_MAXON_MF_WRAPPER(InterpolateTypeInterface_Average, maxon::GenericComponent, const, (void), void* data, const Block<const void*>& dataSet) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Average(data, dataSet); }
		static InterpolateType InterpolateTypeInterface_GetInterpolationClass(const DataType& datatype) { return S::Implementation::GetInterpolationClass(datatype); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::GetInterpolateDataType() const -> const DataType&
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.InterpolateTypeInterface_GetInterpolateDataType_Offset), mt_.InterpolateTypeInterface_GetInterpolateDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::InterpolateLinear(void* data1, const void* data2, Float blend) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.InterpolateTypeInterface_InterpolateLinear_Offset), mt_.InterpolateTypeInterface_InterpolateLinear, data1, data2, blend);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.InterpolateTypeInterface_InterpolateInOutline_Offset), mt_.InterpolateTypeInterface_InterpolateInOutline, data, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Average(void* data, const Block<const void*>& dataSet) const -> void
{
	const InterpolateTypeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.InterpolateTypeInterface_Average_Offset), mt_.InterpolateTypeInterface_Average, data, dataSet);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::GetInterpolationClass(const DataType& datatype) -> InterpolateType
{
	return Hxx2::StaticMTable::_instance.InterpolateTypeInterface_GetInterpolationClass(datatype);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::GetInterpolateDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_GetInterpolateDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_GetInterpolateDataType_Offset), mt_.InterpolateTypeInterface_GetInterpolateDataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::InterpolateLinear(void* data1, const void* data2, Float blend) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_InterpolateLinear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_InterpolateLinear_Offset), mt_.InterpolateTypeInterface_InterpolateLinear, data1, data2, blend);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_InterpolateInOutline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_InterpolateInOutline_Offset), mt_.InterpolateTypeInterface_InterpolateInOutline, data, outline, weights);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::Average(void* data, const Block<const void*>& dataSet) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InterpolateTypeInterface, o_, InterpolateTypeInterface_Average) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InterpolateTypeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InterpolateTypeInterface>() : PRIVATE_MAXON_VTABLE(InterpolateTypeInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InterpolateTypeInterface_Average_Offset), mt_.InterpolateTypeInterface_Average, data, dataSet);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::InterpolateBilinear(const DataTypePtr dataType, void* data1, const void* data2, const void* data3, const void* data4, Float blendS, Float blendT) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION InterpolateTypeInterface::InterpolateBilinear on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InterpolateTypeInterface* o_ = (const InterpolateTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InterpolateTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->InterpolateBilinear(std::forward<const DataTypePtr>(dataType), data1, data2, data3, data4, blendS, blendT);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InterpolateTypeInterface::Hxx1::ConstFn<S>::GetInterpolationClass(const DataType& datatype) -> InterpolateType
{
	return (Hxx2::StaticMTable::_instance.InterpolateTypeInterface_GetInterpolationClass(datatype));
}
auto InterpolateTypeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InterpolateTypeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_interpolation)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InterpolateTypeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InterpolateTypeInterface() { new (s_ui_maxon_InterpolateTypeInterface) maxon::EntityUse(InterpolateTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InterpolateTypeInterface(InterpolateTypeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interpolation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_interpolation)
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

