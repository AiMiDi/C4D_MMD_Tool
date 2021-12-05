
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
	static const maxon::Bool HAS_NONSTATIC = false;
	const Id& (*_DimensionInterface_GetId) (const maxon::GenericComponent* this_);
	maxon::Int _DimensionInterface_GetId_Offset;
	Result<Dimension> (*_DimensionInterface_operatorMul) (const maxon::GenericComponent* this_, const Result<Dimension>& q);
	maxon::Int _DimensionInterface_operatorMul_Offset;
	Result<Dimension> (*_DimensionInterface_operatorDiv) (const maxon::GenericComponent* this_, const Result<Dimension>& q);
	maxon::Int _DimensionInterface_operatorDiv_Offset;
	Result<Dimension> (*_DimensionInterface_operatorXor) (const maxon::GenericComponent* this_, Int exponent);
	maxon::Int _DimensionInterface_operatorXor_Offset;
	Result<Dimension> (*_DimensionInterface_Copy) (const maxon::GenericComponent* this_, const Id& qid);
	maxon::Int _DimensionInterface_Copy_Offset;
	Int (*_DimensionInterface_GetExponent) (const maxon::GenericComponent* this_, BASE_DIMENSION q);
	maxon::Int _DimensionInterface_GetExponent_Offset;
	Result<Unit> (*_DimensionInterface_AddUnit) (const maxon::GenericComponent* this_, const Id& unitId, Float siConversionFactor);
	maxon::Int _DimensionInterface_AddUnit_Offset;
	UnitsArray (*_DimensionInterface_GetUnits) (const maxon::GenericComponent* this_);
	maxon::Int _DimensionInterface_GetUnits_Offset;
	Bool (*_DimensionInterface_IsEquivalent) (const maxon::GenericComponent* this_, const Dimension& other);
	maxon::Int _DimensionInterface_IsEquivalent_Offset;
	String (*_DimensionInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* fs);
	maxon::Int _DimensionInterface_ToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetId), W, MTable>::type::_DimensionInterface_GetId;
			_DimensionInterface_GetId = reinterpret_cast<const decltype(_DimensionInterface_GetId)&>(ptr);
			_DimensionInterface_GetId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorMul))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorMul), W, MTable>::type::_DimensionInterface_operatorMul;
			_DimensionInterface_operatorMul = reinterpret_cast<const decltype(_DimensionInterface_operatorMul)&>(ptr);
			_DimensionInterface_operatorMul_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorDiv))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorDiv), W, MTable>::type::_DimensionInterface_operatorDiv;
			_DimensionInterface_operatorDiv = reinterpret_cast<const decltype(_DimensionInterface_operatorDiv)&>(ptr);
			_DimensionInterface_operatorDiv_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorXor))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, operatorXor), W, MTable>::type::_DimensionInterface_operatorXor;
			_DimensionInterface_operatorXor = reinterpret_cast<const decltype(_DimensionInterface_operatorXor)&>(ptr);
			_DimensionInterface_operatorXor_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, Copy))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, Copy), W, MTable>::type::_DimensionInterface_Copy;
			_DimensionInterface_Copy = reinterpret_cast<const decltype(_DimensionInterface_Copy)&>(ptr);
			_DimensionInterface_Copy_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetExponent))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetExponent), W, MTable>::type::_DimensionInterface_GetExponent;
			_DimensionInterface_GetExponent = reinterpret_cast<const decltype(_DimensionInterface_GetExponent)&>(ptr);
			_DimensionInterface_GetExponent_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, AddUnit))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, AddUnit), W, MTable>::type::_DimensionInterface_AddUnit;
			_DimensionInterface_AddUnit = reinterpret_cast<const decltype(_DimensionInterface_AddUnit)&>(ptr);
			_DimensionInterface_AddUnit_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetUnits))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, GetUnits), W, MTable>::type::_DimensionInterface_GetUnits;
			_DimensionInterface_GetUnits = reinterpret_cast<const decltype(_DimensionInterface_GetUnits)&>(ptr);
			_DimensionInterface_GetUnits_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, IsEquivalent))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, IsEquivalent), W, MTable>::type::_DimensionInterface_IsEquivalent;
			_DimensionInterface_IsEquivalent = reinterpret_cast<const decltype(_DimensionInterface_IsEquivalent)&>(ptr);
			_DimensionInterface_IsEquivalent_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, ToString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DimensionInterface, ToString), W, MTable>::type::_DimensionInterface_ToString;
			_DimensionInterface_ToString = reinterpret_cast<const decltype(_DimensionInterface_ToString)&>(ptr);
			_DimensionInterface_ToString_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DimensionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DimensionInterface);
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
	const Dimension& (*_DimensionInterface_Get) (BASE_DIMENSION q);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_DimensionInterface_Get = &IMPL::_DimensionInterface_Get;
		}
	};
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
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
	static const Dimension& _DimensionInterface_Get(BASE_DIMENSION q) { return S::Implementation::Get(q); }
	static const Id& _DimensionInterface_GetId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetId(); }
	static Result<Dimension> _DimensionInterface_operatorMul(const maxon::GenericComponent* this_, const Result<Dimension>& q) { return ((const typename S::Implementation*) this_)->operatorMul(q); }
	static Result<Dimension> _DimensionInterface_operatorDiv(const maxon::GenericComponent* this_, const Result<Dimension>& q) { return ((const typename S::Implementation*) this_)->operatorDiv(q); }
	static Result<Dimension> _DimensionInterface_operatorXor(const maxon::GenericComponent* this_, Int exponent) { return ((const typename S::Implementation*) this_)->operatorXor(exponent); }
	static Result<Dimension> _DimensionInterface_Copy(const maxon::GenericComponent* this_, const Id& qid) { return ((const typename S::Implementation*) this_)->Copy(qid); }
	static Int _DimensionInterface_GetExponent(const maxon::GenericComponent* this_, BASE_DIMENSION q) { return ((const typename S::Implementation*) this_)->GetExponent(q); }
	static Result<Unit> _DimensionInterface_AddUnit(const maxon::GenericComponent* this_, const Id& unitId, Float siConversionFactor) { return ((const typename S::Implementation*) this_)->AddUnit(unitId, siConversionFactor); }
	static UnitsArray _DimensionInterface_GetUnits(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUnits(); }
	static Bool _DimensionInterface_IsEquivalent(const maxon::GenericComponent* this_, const Dimension& other) { return ((const typename S::Implementation*) this_)->IsEquivalent(other); }
	static String _DimensionInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* fs) { return ((const typename S::Implementation*) this_)->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Get(BASE_DIMENSION q) -> const Dimension&
{
	return Hxx2::StaticMTable::_instance._DimensionInterface_Get(q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetId() const -> const Id&
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_GetId((const maxon::GenericComponent*) this + mt_._DimensionInterface_GetId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_operatorMul((const maxon::GenericComponent*) this + mt_._DimensionInterface_operatorMul_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_operatorDiv((const maxon::GenericComponent*) this + mt_._DimensionInterface_operatorDiv_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::operator ^(Int exponent) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_operatorXor((const maxon::GenericComponent*) this + mt_._DimensionInterface_operatorXor_Offset, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Copy(const Id& qid) const -> Result<Dimension>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_Copy((const maxon::GenericComponent*) this + mt_._DimensionInterface_Copy_Offset, qid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetExponent(BASE_DIMENSION q) const -> Int
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_GetExponent((const maxon::GenericComponent*) this + mt_._DimensionInterface_GetExponent_Offset, q);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_AddUnit((const maxon::GenericComponent*) this + mt_._DimensionInterface_AddUnit_Offset, unitId, siConversionFactor);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::GetUnits() const -> UnitsArray
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_GetUnits((const maxon::GenericComponent*) this + mt_._DimensionInterface_GetUnits_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::IsEquivalent(const Dimension& other) const -> Bool
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_IsEquivalent((const maxon::GenericComponent*) this + mt_._DimensionInterface_IsEquivalent_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::ToString(const FormatStatement* fs) const -> String
{
	const DimensionInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._DimensionInterface_ToString((const maxon::GenericComponent*) this + mt_._DimensionInterface_ToString_Offset, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(BASE_DIMENSION q) -> const Dimension& { return (Hxx2::StaticMTable::_instance._DimensionInterface_Get(q)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_GetId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_GetId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator *(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorMul) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_operatorMul(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_operatorMul_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator /(const Result<Dimension>& q) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorDiv) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_operatorDiv(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_operatorDiv_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator ^(Int exponent) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_operatorXor) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_operatorXor(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_operatorXor_Offset, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Copy(const Id& qid) const -> Result<Dimension>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Dimension>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_Copy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_Copy(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_Copy_Offset, qid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetExponent(BASE_DIMENSION q) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetExponent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_GetExponent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_GetExponent_Offset, q));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AddUnit(const Id& unitId, Float siConversionFactor) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_AddUnit) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_AddUnit(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_AddUnit_Offset, unitId, siConversionFactor));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUnits() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<UnitsArray>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_GetUnits) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_GetUnits(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_GetUnits_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEquivalent(const Dimension& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_IsEquivalent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_IsEquivalent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_IsEquivalent_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DimensionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DimensionInterface* o_ = (const DimensionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DimensionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DimensionInterface, o_, DimensionInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DimensionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DimensionInterface>() : PRIVATE_MAXON_VTABLE(DimensionInterface, o_); 
	return (mt_._DimensionInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DimensionInterface_ToString_Offset, fs));
}
auto DimensionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DimensionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DimensionInterface() { new (s_ui_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DimensionInterface(DimensionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui1_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui1_maxon_DimensionInterface() { new (s_ui1_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui1_maxon_DimensionInterface(DimensionInterface::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DimensionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DimensionInterface() { new (s_usi_maxon_DimensionInterface) maxon::EntityUse(DimensionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DimensionInterface(DimensionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/units.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnitInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_UnitInterface_Free) (const UnitInterface* object);
	const Id& (*_UnitInterface_GetId) (const UnitInterface* this_);
	const Dimension& (*_UnitInterface_GetDimension) (const UnitInterface* this_);
	Float (*_UnitInterface_GetSIConversionFactor) (const UnitInterface* this_);
	Result<Unit> (*_UnitInterface_operatorMul) (const UnitInterface* this_, const Result<Unit>& u);
	Result<Unit> (*_UnitInterface_operatorDiv) (const UnitInterface* this_, const Result<Unit>& u);
	Result<Unit> (*_UnitInterface_operatorXor) (const UnitInterface* this_, Int exponent);
	Result<Unit> (*_UnitInterface_Copy) (const UnitInterface* this_, const Id& uid);
	Result<Unit> (*_UnitInterface_Copy_1) (const UnitInterface* this_, const Dimension& quantity);
	Result<void> (*_UnitInterface_AddToDimension) (const UnitInterface* this_);
	Result<Unit> (*_UnitInterface_Reduce) (const UnitInterface* this_);
	String (*_UnitInterface_ToString) (const UnitInterface* this_, const FormatStatement* fs);
	template <typename IMPL> void Init()
	{
		_UnitInterface_Free = &IMPL::_UnitInterface_Free;
		_UnitInterface_GetId = &IMPL::_UnitInterface_GetId;
		_UnitInterface_GetDimension = &IMPL::_UnitInterface_GetDimension;
		_UnitInterface_GetSIConversionFactor = &IMPL::_UnitInterface_GetSIConversionFactor;
		_UnitInterface_operatorMul = &IMPL::_UnitInterface_operatorMul;
		_UnitInterface_operatorDiv = &IMPL::_UnitInterface_operatorDiv;
		_UnitInterface_operatorXor = &IMPL::_UnitInterface_operatorXor;
		_UnitInterface_Copy = &IMPL::_UnitInterface_Copy;
		_UnitInterface_Copy_1 = &IMPL::_UnitInterface_Copy_1;
		_UnitInterface_AddToDimension = &IMPL::_UnitInterface_AddToDimension;
		_UnitInterface_Reduce = &IMPL::_UnitInterface_Reduce;
		_UnitInterface_ToString = &IMPL::_UnitInterface_ToString;
	}
};

struct UnitInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _UnitInterface_Free(const UnitInterface* object) { return C::Free(object); }
	static const Id& _UnitInterface_GetId(const UnitInterface* this_) { return ((const C*) this_)->GetId(); }
	static const Dimension& _UnitInterface_GetDimension(const UnitInterface* this_) { return ((const C*) this_)->GetDimension(); }
	static Float _UnitInterface_GetSIConversionFactor(const UnitInterface* this_) { return ((const C*) this_)->GetSIConversionFactor(); }
	static Result<Unit> _UnitInterface_operatorMul(const UnitInterface* this_, const Result<Unit>& u) { return ((const C*) this_)->operator *(u); }
	static Result<Unit> _UnitInterface_operatorDiv(const UnitInterface* this_, const Result<Unit>& u) { return ((const C*) this_)->operator /(u); }
	static Result<Unit> _UnitInterface_operatorXor(const UnitInterface* this_, Int exponent) { return ((const C*) this_)->operator ^(exponent); }
	static Result<Unit> _UnitInterface_Copy(const UnitInterface* this_, const Id& uid) { return ((const C*) this_)->Copy(uid); }
	static Result<Unit> _UnitInterface_Copy_1(const UnitInterface* this_, const Dimension& quantity) { return ((const C*) this_)->Copy(quantity); }
	static Result<void> _UnitInterface_AddToDimension(const UnitInterface* this_) { return ((const C*) this_)->AddToDimension(); }
	static Result<Unit> _UnitInterface_Reduce(const UnitInterface* this_) { return ((const C*) this_)->Reduce(); }
	static String _UnitInterface_ToString(const UnitInterface* this_, const FormatStatement* fs) { return ((const C*) this_)->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Free(const UnitInterface* object) -> void
{
	return MTable::_instance._UnitInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetId() const -> const Id&
{
	return MTable::_instance._UnitInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetDimension() const -> const Dimension&
{
	return MTable::_instance._UnitInterface_GetDimension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::GetSIConversionFactor() const -> Float
{
	return MTable::_instance._UnitInterface_GetSIConversionFactor(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_operatorMul(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_operatorDiv(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::operator ^(Int exponent) const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_operatorXor(this, exponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Id& uid) const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_Copy(this, uid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Copy(const Dimension& quantity) const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_Copy_1(this, quantity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::AddToDimension() const -> Result<void>
{
	return MTable::_instance._UnitInterface_AddToDimension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Reduce() const -> Result<Unit>
{
	return MTable::_instance._UnitInterface_Reduce(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::ToString(const FormatStatement* fs) const -> String
{
	return MTable::_instance._UnitInterface_ToString(this, fs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UnitInterface_GetId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDimension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Dimension&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UnitInterface_GetDimension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSIConversionFactor() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._UnitInterface_GetSIConversionFactor(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator *(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_operatorMul(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator /(const Result<Unit>& u) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_operatorDiv(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator ^(Int exponent) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_operatorXor(o_, exponent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Copy(const Id& uid) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_Copy(o_, uid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Copy(const Dimension& quantity) const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_Copy_1(o_, quantity));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AddToDimension() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_AddToDimension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Reduce() const -> Result<Unit>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Unit>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UnitInterface_Reduce(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UnitInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UnitInterface* o_ = (const UnitInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UnitInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UnitInterface_ToString(o_, fs));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

