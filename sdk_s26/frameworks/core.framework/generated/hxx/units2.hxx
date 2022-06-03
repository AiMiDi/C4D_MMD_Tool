
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DimensionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddUnit);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Copy);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExponent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUnits);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsEquivalent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(operatorMul);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(operatorDiv);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(operatorXor);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const Id& (*DimensionInterface_GetId) (const maxon::GenericComponent* this_);
	maxon::Int DimensionInterface_GetId_Offset;
	Result<Dimension> (*DimensionInterface_operatorMul) (const maxon::GenericComponent* this_, const Result<Dimension>& q);
	maxon::Int DimensionInterface_operatorMul_Offset;
	Result<Dimension> (*DimensionInterface_operatorDiv) (const maxon::GenericComponent* this_, const Result<Dimension>& q);
	maxon::Int DimensionInterface_operatorDiv_Offset;
	Result<Dimension> (*DimensionInterface_operatorXor) (const maxon::GenericComponent* this_, Int exponent);
	maxon::Int DimensionInterface_operatorXor_Offset;
	Result<Dimension> (*DimensionInterface_Copy) (const maxon::GenericComponent* this_, const Id& qid);
	maxon::Int DimensionInterface_Copy_Offset;
	Int (*DimensionInterface_GetExponent) (const maxon::GenericComponent* this_, BASE_DIMENSION q);
	maxon::Int DimensionInterface_GetExponent_Offset;
	Result<Unit> (*DimensionInterface_AddUnit) (const maxon::GenericComponent* this_, const Id& unitId, Float siConversionFactor);
	maxon::Int DimensionInterface_AddUnit_Offset;
	UnitsArray (*DimensionInterface_GetUnits) (const maxon::GenericComponent* this_);
	maxon::Int DimensionInterface_GetUnits_Offset;
	Bool (*DimensionInterface_IsEquivalent) (const maxon::GenericComponent* this_, const Dimension& other);
	maxon::Int DimensionInterface_IsEquivalent_Offset;
	String (*DimensionInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* fs);
	maxon::Int DimensionInterface_ToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetId))
	{
		DimensionInterface_GetId = &W::DimensionInterface_GetId;
		DimensionInterface_GetId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorMul))
	{
		DimensionInterface_operatorMul = &W::DimensionInterface_operatorMul;
		DimensionInterface_operatorMul_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorDiv))
	{
		DimensionInterface_operatorDiv = &W::DimensionInterface_operatorDiv;
		DimensionInterface_operatorDiv_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorXor))
	{
		DimensionInterface_operatorXor = &W::DimensionInterface_operatorXor;
		DimensionInterface_operatorXor_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, Copy))
	{
		DimensionInterface_Copy = &W::DimensionInterface_Copy;
		DimensionInterface_Copy_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetExponent))
	{
		DimensionInterface_GetExponent = &W::DimensionInterface_GetExponent;
		DimensionInterface_GetExponent_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, AddUnit))
	{
		DimensionInterface_AddUnit = &W::DimensionInterface_AddUnit;
		DimensionInterface_AddUnit_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetUnits))
	{
		DimensionInterface_GetUnits = &W::DimensionInterface_GetUnits;
		DimensionInterface_GetUnits_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, IsEquivalent))
	{
		DimensionInterface_IsEquivalent = &W::DimensionInterface_IsEquivalent;
		DimensionInterface_IsEquivalent_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, ToString))
	{
		DimensionInterface_ToString = &W::DimensionInterface_ToString;
		DimensionInterface_ToString_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DimensionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DimensionInterface, SUPER>;
	struct NVMTable;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::SFINAEHelper<NVMTable, I>::type::_instance.template GetMTable<I>(); }
};

struct DimensionInterface::MTable::NVMTable : public MTable::template CombinedMTable<maxon::CombinedMTableRoot> { static NVMTable _instance; };

struct DimensionInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	const Dimension& (*DimensionInterface_Get) (BASE_DIMENSION q);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DimensionInterface_Get = &IMPL::DimensionInterface_Get;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddUnit);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Copy);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExponent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUnits);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsEquivalent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ToString);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(operatorMul);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(operatorDiv);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(operatorXor);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DimensionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DimensionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const Dimension& DimensionInterface_Get(BASE_DIMENSION q) { return S::Implementation::Get(q); }
		static const Id& DimensionInterface_GetId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetId(); }
		static Result<Dimension> DimensionInterface_operatorMul(const maxon::GenericComponent* this_, const Result<Dimension>& q) { return ((const typename S::Implementation*) this_)->operatorMul(q); }
		static Result<Dimension> DimensionInterface_operatorDiv(const maxon::GenericComponent* this_, const Result<Dimension>& q) { return ((const typename S::Implementation*) this_)->operatorDiv(q); }
		static Result<Dimension> DimensionInterface_operatorXor(const maxon::GenericComponent* this_, Int exponent) { return ((const typename S::Implementation*) this_)->operatorXor(exponent); }
		static Result<Dimension> DimensionInterface_Copy(const maxon::GenericComponent* this_, const Id& qid) { return ((const typename S::Implementation*) this_)->Copy(qid); }
		static Int DimensionInterface_GetExponent(const maxon::GenericComponent* this_, BASE_DIMENSION q) { return ((const typename S::Implementation*) this_)->GetExponent(q); }
		static Result<Unit> DimensionInterface_AddUnit(const maxon::GenericComponent* this_, const Id& unitId, Float siConversionFactor) { return ((const typename S::Implementation*) this_)->AddUnit(unitId, siConversionFactor); }
		static UnitsArray DimensionInterface_GetUnits(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUnits(); }
		static Bool DimensionInterface_IsEquivalent(const maxon::GenericComponent* this_, const Dimension& other) { return ((const typename S::Implementation*) this_)->IsEquivalent(other); }
		static String DimensionInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* fs) { return ((const typename S::Implementation*) this_)->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Get(BASE_DIMENSION q) -> const Dimension&
{
	return Hxx2::StaticMTable::_instance.DimensionInterface_Get(q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetId() const -> const Id&
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_GetId((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_operatorMul((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorMul_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_operatorDiv((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorDiv_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator ^(Int exponent) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_operatorXor((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorXor_Offset, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Copy(const Id& qid) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_Copy((const maxon::GenericComponent*) this + mt_.DimensionInterface_Copy_Offset, qid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetExponent(BASE_DIMENSION q) const -> Int
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_GetExponent((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetExponent_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_AddUnit((const maxon::GenericComponent*) this + mt_.DimensionInterface_AddUnit_Offset, unitId, siConversionFactor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetUnits() const -> UnitsArray
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_GetUnits((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetUnits_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::IsEquivalent(const Dimension& other) const -> Bool
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_IsEquivalent((const maxon::GenericComponent*) this + mt_.DimensionInterface_IsEquivalent_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::ToString(const FormatStatement* fs) const -> String
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_.DimensionInterface_ToString((const maxon::GenericComponent*) this + mt_.DimensionInterface_ToString_Offset, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::Get(BASE_DIMENSION q) -> const Dimension&
{
	return (Hxx2::StaticMTable::_instance.DimensionInterface_Get(q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_GetId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorMul) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_operatorMul(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorMul_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorDiv) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_operatorDiv(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorDiv_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator ^(Int exponent) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorXor) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_operatorXor(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorXor_Offset, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::Copy(const Id& qid) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_Copy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_Copy(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_Copy_Offset, qid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetExponent(BASE_DIMENSION q) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetExponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_GetExponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetExponent_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_AddUnit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_AddUnit(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_AddUnit_Offset, unitId, siConversionFactor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetUnits() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<UnitsArray>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetUnits) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_GetUnits(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetUnits_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::IsEquivalent(const Dimension& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_IsEquivalent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_IsEquivalent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_IsEquivalent_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_.DimensionInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_ToString_Offset, fs));
}
auto DimensionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DimensionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_units)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DimensionInterface() { new (s_ui_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DimensionInterface(DimensionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_units)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui1_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui1_maxon_DimensionInterface() { new (s_ui1_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui1_maxon_DimensionInterface(DimensionInterface::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_units)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DimensionInterface() { new (s_usi_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DimensionInterface(DimensionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* UnitInterface::PrivateGetCppName() { return "maxon::Unit"; }

struct UnitInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*UnitInterface_Free) (const UnitInterface* object);
	const Id& (*UnitInterface_GetId) (const UnitInterface* this_);
	const Dimension& (*UnitInterface_GetDimension) (const UnitInterface* this_);
	Float (*UnitInterface_GetSIConversionFactor) (const UnitInterface* this_);
	Result<Unit> (*UnitInterface_operatorMul) (const UnitInterface* this_, const Result<Unit>& u);
	Result<Unit> (*UnitInterface_operatorDiv) (const UnitInterface* this_, const Result<Unit>& u);
	Result<Unit> (*UnitInterface_operatorXor) (const UnitInterface* this_, Int exponent);
	Result<Unit> (*UnitInterface_Copy) (const UnitInterface* this_, const Id& uid);
	Result<Unit> (*UnitInterface_Copy_1) (const UnitInterface* this_, const Dimension& quantity);
	Result<void> (*UnitInterface_AddToDimension) (const UnitInterface* this_);
	Result<Unit> (*UnitInterface_Reduce) (const UnitInterface* this_);
	String (*UnitInterface_ToString) (const UnitInterface* this_, const FormatStatement* fs);
	template <typename IMPL> void Init()
	{
		UnitInterface_Free = &IMPL::UnitInterface_Free;
		UnitInterface_GetId = &IMPL::UnitInterface_GetId;
		UnitInterface_GetDimension = &IMPL::UnitInterface_GetDimension;
		UnitInterface_GetSIConversionFactor = &IMPL::UnitInterface_GetSIConversionFactor;
		UnitInterface_operatorMul = &IMPL::UnitInterface_operatorMul;
		UnitInterface_operatorDiv = &IMPL::UnitInterface_operatorDiv;
		UnitInterface_operatorXor = &IMPL::UnitInterface_operatorXor;
		UnitInterface_Copy = &IMPL::UnitInterface_Copy;
		UnitInterface_Copy_1 = &IMPL::UnitInterface_Copy_1;
		UnitInterface_AddToDimension = &IMPL::UnitInterface_AddToDimension;
		UnitInterface_Reduce = &IMPL::UnitInterface_Reduce;
		UnitInterface_ToString = &IMPL::UnitInterface_ToString;
	}
};

struct UnitInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void UnitInterface_Free(const UnitInterface* object) { return C::Free(object); }
		static const Id& UnitInterface_GetId(const UnitInterface* this_) { return C::Get(this_)->GetId(); }
		static const Dimension& UnitInterface_GetDimension(const UnitInterface* this_) { return C::Get(this_)->GetDimension(); }
		static Float UnitInterface_GetSIConversionFactor(const UnitInterface* this_) { return C::Get(this_)->GetSIConversionFactor(); }
		static Result<Unit> UnitInterface_operatorMul(const UnitInterface* this_, const Result<Unit>& u) { return C::Get(this_)->operator *(u); }
		static Result<Unit> UnitInterface_operatorDiv(const UnitInterface* this_, const Result<Unit>& u) { return C::Get(this_)->operator /(u); }
		static Result<Unit> UnitInterface_operatorXor(const UnitInterface* this_, Int exponent) { return C::Get(this_)->operator ^(exponent); }
		static Result<Unit> UnitInterface_Copy(const UnitInterface* this_, const Id& uid) { return C::Get(this_)->Copy(uid); }
		static Result<Unit> UnitInterface_Copy_1(const UnitInterface* this_, const Dimension& quantity) { return C::Get(this_)->Copy(quantity); }
		static Result<void> UnitInterface_AddToDimension(const UnitInterface* this_) { return C::Get(this_)->AddToDimension(); }
		static Result<Unit> UnitInterface_Reduce(const UnitInterface* this_) { return C::Get(this_)->Reduce(); }
		static String UnitInterface_ToString(const UnitInterface* this_, const FormatStatement* fs) { return C::Get(this_)->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Free(const UnitInterface* object) -> void
{
	return MTable::_instance.UnitInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetId() const -> const Id&
{
	return MTable::_instance.UnitInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetDimension() const -> const Dimension&
{
	return MTable::_instance.UnitInterface_GetDimension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetSIConversionFactor() const -> Float
{
	return MTable::_instance.UnitInterface_GetSIConversionFactor(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_operatorMul(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_operatorDiv(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator ^(Int exponent) const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_operatorXor(this, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Id& uid) const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_Copy(this, uid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Dimension& quantity) const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_Copy_1(this, quantity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::AddToDimension() const -> Result<void>
{
	return MTable::_instance.UnitInterface_AddToDimension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Reduce() const -> Result<Unit>
{
	return MTable::_instance.UnitInterface_Reduce(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::ToString(const FormatStatement* fs) const -> String
{
	return MTable::_instance.UnitInterface_ToString(this, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UnitInterface_GetId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetDimension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Dimension&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UnitInterface_GetDimension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetSIConversionFactor() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.UnitInterface_GetSIConversionFactor(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_operatorMul(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_operatorDiv(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator ^(Int exponent) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_operatorXor(o_, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Copy(const Id& uid) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_Copy(o_, uid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Copy(const Dimension& quantity) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_Copy_1(o_, quantity));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::AddToDimension() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_AddToDimension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Reduce() const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UnitInterface_Reduce(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UnitInterface_ToString(o_, fs));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_units)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnitInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnitInterface() { new (s_ui_maxon_UnitInterface) maxon::EntityUse(UnitInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnitInterface(UnitInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

