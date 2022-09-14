
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct NURBSCurveInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_EvaluateAt, EvaluateAt, false, NURBSCurveInterface, const, (Result<Vector>), Float s);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_DeriveAt, DeriveAt, false, NURBSCurveInterface, const, (Result<Vector>), Float s);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetDegree, GetDegree, false, NURBSCurveInterface, const, (Result<Int>));
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetMaxDegree, GetMaxDegree, false, NURBSCurveInterface, const, (Result<Int>));
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetPointCount, GetPointCount, false, NURBSCurveInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetWeightCount, GetWeightCount, false, NURBSCurveInterface, const, (Result<Int>));
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetPoint, GetPoint, false, NURBSCurveInterface, const, (Result<Vector>), Int i);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetPointWithWeight, GetPointWithWeight, false, NURBSCurveInterface, const, (Result<Vector4d>), Int i);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetPointsWithWeights, GetPointsWithWeights, false, NURBSCurveInterface, const, (const Block<const Vector4d>));
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_GetWeight, GetWeight, false, NURBSCurveInterface, const, (Result<Float>), Int i);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_SetPoint, SetPoint, false, NURBSCurveInterface,, (Result<void>), Int i, const Vector& point);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_SetPointWithWeight, SetPointWithWeight, false, NURBSCurveInterface,, (Result<void>), Int i, const Vector4d& point);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_ChangePoints, ChangePoints, false, NURBSCurveInterface,, (Result<void>), const Block<Vector>& points);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_SetPointsWithWeights, SetPointsWithWeights, false, NURBSCurveInterface,, (Result<void>), const Block<const Vector4d>& points);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_SetWeight, SetWeight, false, NURBSCurveInterface,, (Result<void>), Int i, Float weight);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_ChangeWeights, ChangeWeights, false, NURBSCurveInterface,, (Result<void>), const Block<const Float>& weights);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_ChangeWeights_1, ChangeWeights, false, NURBSCurveInterface,, (Result<void>), const Block<const Float32>& weights);
	PRIVATE_MAXON_MF_POINTER(NURBSCurveInterface_AddControlPoint, AddControlPoint, false, NURBSCurveInterface,, (Result<Pair<Block<Vector4d>, Int>>), const Float t);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const NURBSCurveInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		NURBSCurveInterface_EvaluateAt = NURBSCurveInterface_EvaluateAt_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_DeriveAt = NURBSCurveInterface_DeriveAt_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetDegree = NURBSCurveInterface_GetDegree_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetMaxDegree = NURBSCurveInterface_GetMaxDegree_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetPointCount = NURBSCurveInterface_GetPointCount_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetWeightCount = NURBSCurveInterface_GetWeightCount_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetPoint = NURBSCurveInterface_GetPoint_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetPointWithWeight = NURBSCurveInterface_GetPointWithWeight_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetPointsWithWeights = NURBSCurveInterface_GetPointsWithWeights_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_GetWeight = NURBSCurveInterface_GetWeight_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_SetPoint = NURBSCurveInterface_SetPoint_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_SetPointWithWeight = NURBSCurveInterface_SetPointWithWeight_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_ChangePoints = NURBSCurveInterface_ChangePoints_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_SetPointsWithWeights = NURBSCurveInterface_SetPointsWithWeights_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_SetWeight = NURBSCurveInterface_SetWeight_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_ChangeWeights = NURBSCurveInterface_ChangeWeights_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_ChangeWeights_1 = NURBSCurveInterface_ChangeWeights_1_GetPtr<IMPL>(0, true).first;
		NURBSCurveInterface_AddControlPoint = NURBSCurveInterface_AddControlPoint_GetPtr<IMPL>(0, true).first;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct NURBSCurveInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_EvaluateAt, NURBSCurveInterface, const, (Result<Vector>), Float s) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->EvaluateAt(s); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_DeriveAt, NURBSCurveInterface, const, (Result<Vector>), Float s) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->DeriveAt(s); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetDegree, NURBSCurveInterface, const, (Result<Int>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetDegree(); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetMaxDegree, NURBSCurveInterface, const, (Result<Int>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetMaxDegree(); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetPointCount, NURBSCurveInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetPointCount(); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetWeightCount, NURBSCurveInterface, const, (Result<Int>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetWeightCount(); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetPoint, NURBSCurveInterface, const, (Result<Vector>), Int i) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetPoint(i); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetPointWithWeight, NURBSCurveInterface, const, (Result<Vector4d>), Int i) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetPointWithWeight(i); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetPointsWithWeights, NURBSCurveInterface, const, (const Block<const Vector4d>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetPointsWithWeights(); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_GetWeight, NURBSCurveInterface, const, (Result<Float>), Int i) { return C::Get(PRIVATE_MAXON_MF_THIS(const NURBSCurveInterface))->GetWeight(i); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_SetPoint, NURBSCurveInterface,, (Result<void>), Int i, const Vector& point) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->SetPoint(i, point); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_SetPointWithWeight, NURBSCurveInterface,, (Result<void>), Int i, const Vector4d& point) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->SetPointWithWeight(i, point); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_ChangePoints, NURBSCurveInterface,, (Result<void>), const Block<Vector>& points) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->ChangePoints(points); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_SetPointsWithWeights, NURBSCurveInterface,, (Result<void>), const Block<const Vector4d>& points) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->SetPointsWithWeights(points); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_SetWeight, NURBSCurveInterface,, (Result<void>), Int i, Float weight) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->SetWeight(i, weight); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_ChangeWeights, NURBSCurveInterface,, (Result<void>), const Block<const Float>& weights) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->ChangeWeights(weights); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_ChangeWeights_1, NURBSCurveInterface,, (Result<void>), const Block<const Float32>& weights) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->ChangeWeights(weights); }
		PRIVATE_MAXON_MF_WRAPPER(NURBSCurveInterface_AddControlPoint, NURBSCurveInterface,, (Result<Pair<Block<Vector4d>, Int>>), const Float t) { return C::Get(PRIVATE_MAXON_MF_THIS(NURBSCurveInterface))->AddControlPoint(t); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::EvaluateAt(Float s) const -> Result<Vector>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_EvaluateAt, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::DeriveAt(Float s) const -> Result<Vector>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_DeriveAt, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetDegree() const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetDegree);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetMaxDegree() const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetMaxDegree);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeightCount() const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeightCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPoint(Int i) const -> Result<Vector>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPoint, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointWithWeight, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointsWithWeights() const -> const Block<const Vector4d>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointsWithWeights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeight(Int i) const -> Result<Float>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeight, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPoint(Int i, const Vector& point) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPoint, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointWithWeight(Int i, const Vector4d& point) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointWithWeight, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangePoints(const Block<Vector>& points) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangePoints, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointsWithWeights(const Block<const Vector4d>& points) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointsWithWeights, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetWeight(Int i, Float weight) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetWeight, i, weight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float>& weights) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float32>& weights) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights_1, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::AddControlPoint(const Float t) -> Result<Pair<Block<Vector4d>, Int>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_AddControlPoint, t);
}

NURBSCurveInterface::NURBSCurveInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::EvaluateAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_EvaluateAt, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::DeriveAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_DeriveAt, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetDegree));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetMaxDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetMaxDegree));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetWeightCount() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeightCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPoint(Int i) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPoint, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector4d>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointWithWeight, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointsWithWeights() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Block<const Vector4d>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointsWithWeights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetWeight(Int i) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeight, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPoint(Int i, const Vector& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPoint, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPointWithWeight(Int i, const Vector4d& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointWithWeight, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangePoints(const Block<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangePoints, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPointsWithWeights(const Block<const Vector4d>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointsWithWeights, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetWeight(Int i, Float weight) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetWeight, i, weight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangeWeights(const Block<const Float>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights, weights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangeWeights(const Block<const Float32>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights_1, weights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::AddControlPoint(const Float t) const -> Result<Pair<Block<Vector4d>, Int>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Pair<Block<Vector4d>, Int>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_AddControlPoint, t));
}
#if 0
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

