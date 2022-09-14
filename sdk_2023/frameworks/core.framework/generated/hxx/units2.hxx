
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
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_GetId, GetId, true, maxon::GenericComponent, const, (const Id&));
	maxon::Int DimensionInterface_GetId_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_operatorMul, operatorMul, true, maxon::GenericComponent, const, (Result<Dimension>), const Result<Dimension>& q);
	maxon::Int DimensionInterface_operatorMul_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_operatorDiv, operatorDiv, true, maxon::GenericComponent, const, (Result<Dimension>), const Result<Dimension>& q);
	maxon::Int DimensionInterface_operatorDiv_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_operatorXor, operatorXor, true, maxon::GenericComponent, const, (Result<Dimension>), Int exponent);
	maxon::Int DimensionInterface_operatorXor_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_Copy, Copy, true, maxon::GenericComponent, const, (Result<Dimension>), const Id& qid);
	maxon::Int DimensionInterface_Copy_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_GetExponent, GetExponent, true, maxon::GenericComponent, const, (Int), BASE_DIMENSION q);
	maxon::Int DimensionInterface_GetExponent_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_AddUnit, AddUnit, true, maxon::GenericComponent, const, (Result<Unit>), const Id& unitId, Float siConversionFactor);
	maxon::Int DimensionInterface_AddUnit_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_GetUnits, GetUnits, true, maxon::GenericComponent, const, (UnitsArray));
	maxon::Int DimensionInterface_GetUnits_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_IsEquivalent, IsEquivalent, true, maxon::GenericComponent, const, (Bool), const Dimension& other);
	maxon::Int DimensionInterface_IsEquivalent_Offset;
	PRIVATE_MAXON_MF_POINTER(DimensionInterface_ToString, ToString, true, maxon::GenericComponent, const, (String), const FormatStatement* fs);
	maxon::Int DimensionInterface_ToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetId))
	{
		maxon::Tie(DimensionInterface_GetId, DimensionInterface_GetId_Offset) = DimensionInterface_GetId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorMul))
	{
		maxon::Tie(DimensionInterface_operatorMul, DimensionInterface_operatorMul_Offset) = DimensionInterface_operatorMul_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorDiv))
	{
		maxon::Tie(DimensionInterface_operatorDiv, DimensionInterface_operatorDiv_Offset) = DimensionInterface_operatorDiv_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorXor))
	{
		maxon::Tie(DimensionInterface_operatorXor, DimensionInterface_operatorXor_Offset) = DimensionInterface_operatorXor_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, Copy))
	{
		maxon::Tie(DimensionInterface_Copy, DimensionInterface_Copy_Offset) = DimensionInterface_Copy_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetExponent))
	{
		maxon::Tie(DimensionInterface_GetExponent, DimensionInterface_GetExponent_Offset) = DimensionInterface_GetExponent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, AddUnit))
	{
		maxon::Tie(DimensionInterface_AddUnit, DimensionInterface_AddUnit_Offset) = DimensionInterface_AddUnit_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetUnits))
	{
		maxon::Tie(DimensionInterface_GetUnits, DimensionInterface_GetUnits_Offset) = DimensionInterface_GetUnits_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, IsEquivalent))
	{
		maxon::Tie(DimensionInterface_IsEquivalent, DimensionInterface_IsEquivalent_Offset) = DimensionInterface_IsEquivalent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, ToString))
	{
		maxon::Tie(DimensionInterface_ToString, DimensionInterface_ToString_Offset) = DimensionInterface_ToString_GetPtr<W>(offset, true);
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
	PRIVATE_MAXON_SF_POINTER(DimensionInterface_Get, Get, MAXON_EXPAND_VA_ARGS, (const Dimension&), BASE_DIMENSION q);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DimensionInterface_Get = DimensionInterface_Get_GetPtr<IMPL>(true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DimensionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DimensionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const Dimension& DimensionInterface_Get(BASE_DIMENSION q) { return S::Implementation::Get(q); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_GetId, maxon::GenericComponent, const, (const Id&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_operatorMul, maxon::GenericComponent, const, (Result<Dimension>), const Result<Dimension>& q) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->operatorMul(q); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_operatorDiv, maxon::GenericComponent, const, (Result<Dimension>), const Result<Dimension>& q) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->operatorDiv(q); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_operatorXor, maxon::GenericComponent, const, (Result<Dimension>), Int exponent) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->operatorXor(exponent); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_Copy, maxon::GenericComponent, const, (Result<Dimension>), const Id& qid) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Copy(qid); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_GetExponent, maxon::GenericComponent, const, (Int), BASE_DIMENSION q) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetExponent(q); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_AddUnit, maxon::GenericComponent, const, (Result<Unit>), const Id& unitId, Float siConversionFactor) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AddUnit(unitId, siConversionFactor); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_GetUnits, maxon::GenericComponent, const, (UnitsArray)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUnits(); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_IsEquivalent, maxon::GenericComponent, const, (Bool), const Dimension& other) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsEquivalent(other); }
		PRIVATE_MAXON_MF_WRAPPER(DimensionInterface_ToString, maxon::GenericComponent, const, (String), const FormatStatement* fs) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Get(BASE_DIMENSION q) -> const Dimension&
{
	return Hxx2::StaticMTable::_instance.DimensionInterface_Get(q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetId() const -> const Id&
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetId_Offset), mt_.DimensionInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorMul_Offset), mt_.DimensionInterface_operatorMul, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorDiv_Offset), mt_.DimensionInterface_operatorDiv, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator ^(Int exponent) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_operatorXor_Offset), mt_.DimensionInterface_operatorXor, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Copy(const Id& qid) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_Copy_Offset), mt_.DimensionInterface_Copy, qid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetExponent(BASE_DIMENSION q) const -> Int
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetExponent_Offset), mt_.DimensionInterface_GetExponent, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_AddUnit_Offset), mt_.DimensionInterface_AddUnit, unitId, siConversionFactor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetUnits() const -> UnitsArray
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_GetUnits_Offset), mt_.DimensionInterface_GetUnits);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::IsEquivalent(const Dimension& other) const -> Bool
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_IsEquivalent_Offset), mt_.DimensionInterface_IsEquivalent, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::ToString(const FormatStatement* fs) const -> String
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DimensionInterface_ToString_Offset), mt_.DimensionInterface_ToString, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::Get(BASE_DIMENSION q) -> const Dimension&
{
	return (Hxx2::StaticMTable::_instance.DimensionInterface_Get(q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetId_Offset), mt_.DimensionInterface_GetId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorMul) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorMul_Offset), mt_.DimensionInterface_operatorMul, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorDiv) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorDiv_Offset), mt_.DimensionInterface_operatorDiv, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::operator ^(Int exponent) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorXor) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_operatorXor_Offset), mt_.DimensionInterface_operatorXor, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::Copy(const Id& qid) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_Copy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_Copy_Offset), mt_.DimensionInterface_Copy, qid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetExponent(BASE_DIMENSION q) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetExponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetExponent_Offset), mt_.DimensionInterface_GetExponent, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_AddUnit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_AddUnit_Offset), mt_.DimensionInterface_AddUnit, unitId, siConversionFactor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::GetUnits() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<UnitsArray>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetUnits) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_GetUnits_Offset), mt_.DimensionInterface_GetUnits));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::IsEquivalent(const Dimension& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_IsEquivalent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_IsEquivalent_Offset), mt_.DimensionInterface_IsEquivalent, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DimensionInterface_ToString_Offset), mt_.DimensionInterface_ToString, fs));
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
	PRIVATE_MAXON_SF_POINTER(UnitInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const UnitInterface* object);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_GetId, GetId, false, UnitInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(UnitInterface_GetDimension, GetDimension, false, UnitInterface, const, (const Dimension&));
	PRIVATE_MAXON_MF_POINTER(UnitInterface_GetSIConversionFactor, GetSIConversionFactor, false, UnitInterface, const, (Float));
	PRIVATE_MAXON_MF_POINTER(UnitInterface_operatorMul, operatorMul, false, UnitInterface, const, (Result<Unit>), const Result<Unit>& u);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_operatorDiv, operatorDiv, false, UnitInterface, const, (Result<Unit>), const Result<Unit>& u);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_operatorXor, operatorXor, false, UnitInterface, const, (Result<Unit>), Int exponent);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_Copy, Copy, false, UnitInterface, const, (Result<Unit>), const Id& uid);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_Copy_1, Copy, false, UnitInterface, const, (Result<Unit>), const Dimension& quantity);
	PRIVATE_MAXON_MF_POINTER(UnitInterface_AddToDimension, AddToDimension, false, UnitInterface, const, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(UnitInterface_Reduce, Reduce, false, UnitInterface, const, (Result<Unit>));
	PRIVATE_MAXON_MF_POINTER(UnitInterface_ToString, ToString, false, UnitInterface, const, (String), const FormatStatement* fs);
	template <typename IMPL> void Init()
	{
		UnitInterface_Free = UnitInterface_Free_GetPtr<IMPL>(true);
		UnitInterface_GetId = UnitInterface_GetId_GetPtr<IMPL>(0, true).first;
		UnitInterface_GetDimension = UnitInterface_GetDimension_GetPtr<IMPL>(0, true).first;
		UnitInterface_GetSIConversionFactor = UnitInterface_GetSIConversionFactor_GetPtr<IMPL>(0, true).first;
		UnitInterface_operatorMul = UnitInterface_operatorMul_GetPtr<IMPL>(0, true).first;
		UnitInterface_operatorDiv = UnitInterface_operatorDiv_GetPtr<IMPL>(0, true).first;
		UnitInterface_operatorXor = UnitInterface_operatorXor_GetPtr<IMPL>(0, true).first;
		UnitInterface_Copy = UnitInterface_Copy_GetPtr<IMPL>(0, true).first;
		UnitInterface_Copy_1 = UnitInterface_Copy_1_GetPtr<IMPL>(0, true).first;
		UnitInterface_AddToDimension = UnitInterface_AddToDimension_GetPtr<IMPL>(0, true).first;
		UnitInterface_Reduce = UnitInterface_Reduce_GetPtr<IMPL>(0, true).first;
		UnitInterface_ToString = UnitInterface_ToString_GetPtr<IMPL>(0, true).first;
	}
};

struct UnitInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void UnitInterface_Free(const UnitInterface* object) { return C::Free(object); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_GetId, UnitInterface, const, (const Id&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_GetDimension, UnitInterface, const, (const Dimension&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->GetDimension(); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_GetSIConversionFactor, UnitInterface, const, (Float)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->GetSIConversionFactor(); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_operatorMul, UnitInterface, const, (Result<Unit>), const Result<Unit>& u) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->operator *(u); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_operatorDiv, UnitInterface, const, (Result<Unit>), const Result<Unit>& u) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->operator /(u); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_operatorXor, UnitInterface, const, (Result<Unit>), Int exponent) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->operator ^(exponent); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_Copy, UnitInterface, const, (Result<Unit>), const Id& uid) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->Copy(uid); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_Copy_1, UnitInterface, const, (Result<Unit>), const Dimension& quantity) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->Copy(quantity); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_AddToDimension, UnitInterface, const, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->AddToDimension(); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_Reduce, UnitInterface, const, (Result<Unit>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->Reduce(); }
		PRIVATE_MAXON_MF_WRAPPER(UnitInterface_ToString, UnitInterface, const, (String), const FormatStatement* fs) { return C::Get(PRIVATE_MAXON_MF_THIS(const UnitInterface))->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Free(const UnitInterface* object) -> void
{
	return MTable::_instance.UnitInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetDimension() const -> const Dimension&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_GetDimension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetSIConversionFactor() const -> Float
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_GetSIConversionFactor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_operatorMul, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_operatorDiv, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator ^(Int exponent) const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_operatorXor, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Id& uid) const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_Copy, uid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Dimension& quantity) const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_Copy_1, quantity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::AddToDimension() const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_AddToDimension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Reduce() const -> Result<Unit>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_Reduce);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::ToString(const FormatStatement* fs) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UnitInterface_ToString, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_GetId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetDimension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Dimension&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_GetDimension));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::GetSIConversionFactor() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_GetSIConversionFactor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_operatorMul, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_operatorDiv, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::operator ^(Int exponent) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_operatorXor, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Copy(const Id& uid) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_Copy, uid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Copy(const Dimension& quantity) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_Copy_1, quantity));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::AddToDimension() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_AddToDimension));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::Reduce() const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_Reduce));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UnitInterface_ToString, fs));
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

