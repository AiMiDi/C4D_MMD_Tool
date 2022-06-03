
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
	Result<Vector> (*NURBSCurveInterface_EvaluateAt) (const NURBSCurveInterface* this_, Float s);
	Result<Vector> (*NURBSCurveInterface_DeriveAt) (const NURBSCurveInterface* this_, Float s);
	Result<Int> (*NURBSCurveInterface_GetDegree) (const NURBSCurveInterface* this_);
	Result<Int> (*NURBSCurveInterface_GetMaxDegree) (const NURBSCurveInterface* this_);
	Int (*NURBSCurveInterface_GetPointCount) (const NURBSCurveInterface* this_);
	Result<Int> (*NURBSCurveInterface_GetWeightCount) (const NURBSCurveInterface* this_);
	Result<Vector> (*NURBSCurveInterface_GetPoint) (const NURBSCurveInterface* this_, Int i);
	Result<Vector4d> (*NURBSCurveInterface_GetPointWithWeight) (const NURBSCurveInterface* this_, Int i);
	const Block<const Vector4d> (*NURBSCurveInterface_GetPointsWithWeights) (const NURBSCurveInterface* this_);
	Result<Float> (*NURBSCurveInterface_GetWeight) (const NURBSCurveInterface* this_, Int i);
	Result<void> (*NURBSCurveInterface_SetPoint) (NURBSCurveInterface* this_, Int i, const Vector& point);
	Result<void> (*NURBSCurveInterface_SetPointWithWeight) (NURBSCurveInterface* this_, Int i, const Vector4d& point);
	Result<void> (*NURBSCurveInterface_ChangePoints) (NURBSCurveInterface* this_, const Block<Vector>& points);
	Result<void> (*NURBSCurveInterface_SetPointsWithWeights) (NURBSCurveInterface* this_, const Block<const Vector4d>& points);
	Result<void> (*NURBSCurveInterface_SetWeight) (NURBSCurveInterface* this_, Int i, Float weight);
	Result<void> (*NURBSCurveInterface_ChangeWeights) (NURBSCurveInterface* this_, const Block<const Float>& weights);
	Result<void> (*NURBSCurveInterface_ChangeWeights_1) (NURBSCurveInterface* this_, const Block<const Float32>& weights);
	Result<Pair<Block<Vector4d>, Int>> (*NURBSCurveInterface_AddControlPoint) (NURBSCurveInterface* this_, const Float t);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const NURBSCurveInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		NURBSCurveInterface_EvaluateAt = &IMPL::NURBSCurveInterface_EvaluateAt;
		NURBSCurveInterface_DeriveAt = &IMPL::NURBSCurveInterface_DeriveAt;
		NURBSCurveInterface_GetDegree = &IMPL::NURBSCurveInterface_GetDegree;
		NURBSCurveInterface_GetMaxDegree = &IMPL::NURBSCurveInterface_GetMaxDegree;
		NURBSCurveInterface_GetPointCount = &IMPL::NURBSCurveInterface_GetPointCount;
		NURBSCurveInterface_GetWeightCount = &IMPL::NURBSCurveInterface_GetWeightCount;
		NURBSCurveInterface_GetPoint = &IMPL::NURBSCurveInterface_GetPoint;
		NURBSCurveInterface_GetPointWithWeight = &IMPL::NURBSCurveInterface_GetPointWithWeight;
		NURBSCurveInterface_GetPointsWithWeights = &IMPL::NURBSCurveInterface_GetPointsWithWeights;
		NURBSCurveInterface_GetWeight = &IMPL::NURBSCurveInterface_GetWeight;
		NURBSCurveInterface_SetPoint = &IMPL::NURBSCurveInterface_SetPoint;
		NURBSCurveInterface_SetPointWithWeight = &IMPL::NURBSCurveInterface_SetPointWithWeight;
		NURBSCurveInterface_ChangePoints = &IMPL::NURBSCurveInterface_ChangePoints;
		NURBSCurveInterface_SetPointsWithWeights = &IMPL::NURBSCurveInterface_SetPointsWithWeights;
		NURBSCurveInterface_SetWeight = &IMPL::NURBSCurveInterface_SetWeight;
		NURBSCurveInterface_ChangeWeights = &IMPL::NURBSCurveInterface_ChangeWeights;
		NURBSCurveInterface_ChangeWeights_1 = &IMPL::NURBSCurveInterface_ChangeWeights_1;
		NURBSCurveInterface_AddControlPoint = &IMPL::NURBSCurveInterface_AddControlPoint;
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
		static Result<Vector> NURBSCurveInterface_EvaluateAt(const NURBSCurveInterface* this_, Float s) { return C::Get(this_)->EvaluateAt(s); }
		static Result<Vector> NURBSCurveInterface_DeriveAt(const NURBSCurveInterface* this_, Float s) { return C::Get(this_)->DeriveAt(s); }
		static Result<Int> NURBSCurveInterface_GetDegree(const NURBSCurveInterface* this_) { return C::Get(this_)->GetDegree(); }
		static Result<Int> NURBSCurveInterface_GetMaxDegree(const NURBSCurveInterface* this_) { return C::Get(this_)->GetMaxDegree(); }
		static Int NURBSCurveInterface_GetPointCount(const NURBSCurveInterface* this_) { return C::Get(this_)->GetPointCount(); }
		static Result<Int> NURBSCurveInterface_GetWeightCount(const NURBSCurveInterface* this_) { return C::Get(this_)->GetWeightCount(); }
		static Result<Vector> NURBSCurveInterface_GetPoint(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetPoint(i); }
		static Result<Vector4d> NURBSCurveInterface_GetPointWithWeight(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetPointWithWeight(i); }
		static const Block<const Vector4d> NURBSCurveInterface_GetPointsWithWeights(const NURBSCurveInterface* this_) { return C::Get(this_)->GetPointsWithWeights(); }
		static Result<Float> NURBSCurveInterface_GetWeight(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetWeight(i); }
		static Result<void> NURBSCurveInterface_SetPoint(NURBSCurveInterface* this_, Int i, const Vector& point) { return C::Get(this_)->SetPoint(i, point); }
		static Result<void> NURBSCurveInterface_SetPointWithWeight(NURBSCurveInterface* this_, Int i, const Vector4d& point) { return C::Get(this_)->SetPointWithWeight(i, point); }
		static Result<void> NURBSCurveInterface_ChangePoints(NURBSCurveInterface* this_, const Block<Vector>& points) { return C::Get(this_)->ChangePoints(points); }
		static Result<void> NURBSCurveInterface_SetPointsWithWeights(NURBSCurveInterface* this_, const Block<const Vector4d>& points) { return C::Get(this_)->SetPointsWithWeights(points); }
		static Result<void> NURBSCurveInterface_SetWeight(NURBSCurveInterface* this_, Int i, Float weight) { return C::Get(this_)->SetWeight(i, weight); }
		static Result<void> NURBSCurveInterface_ChangeWeights(NURBSCurveInterface* this_, const Block<const Float>& weights) { return C::Get(this_)->ChangeWeights(weights); }
		static Result<void> NURBSCurveInterface_ChangeWeights_1(NURBSCurveInterface* this_, const Block<const Float32>& weights) { return C::Get(this_)->ChangeWeights(weights); }
		static Result<Pair<Block<Vector4d>, Int>> NURBSCurveInterface_AddControlPoint(NURBSCurveInterface* this_, const Float t) { return C::Get(this_)->AddControlPoint(t); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::EvaluateAt(Float s) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_EvaluateAt(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::DeriveAt(Float s) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_DeriveAt(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetDegree() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetDegree(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetMaxDegree() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetMaxDegree(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointCount() const -> Int
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeightCount() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeightCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPoint(Int i) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPoint(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointWithWeight(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointsWithWeights() const -> const Block<const Vector4d>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointsWithWeights(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeight(Int i) const -> Result<Float>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeight(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPoint(Int i, const Vector& point) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPoint(this, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointWithWeight(Int i, const Vector4d& point) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointWithWeight(this, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangePoints(const Block<Vector>& points) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangePoints(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointsWithWeights(const Block<const Vector4d>& points) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointsWithWeights(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetWeight(Int i, Float weight) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_SetWeight(this, i, weight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float>& weights) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights(this, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float32>& weights) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights_1(this, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::AddControlPoint(const Float t) -> Result<Pair<Block<Vector4d>, Int>>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1].NURBSCurveInterface_AddControlPoint(this, t);
}

NURBSCurveInterface::NURBSCurveInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::EvaluateAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_EvaluateAt(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::DeriveAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_DeriveAt(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetDegree(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetMaxDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetMaxDegree(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetWeightCount() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeightCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPoint(Int i) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPoint(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector4d>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointWithWeight(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetPointsWithWeights() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Block<const Vector4d>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetPointsWithWeights(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstFn<S>::GetWeight(Int i) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_GetWeight(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPoint(Int i, const Vector& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPoint(o_, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPointWithWeight(Int i, const Vector4d& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointWithWeight(o_, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangePoints(const Block<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangePoints(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetPointsWithWeights(const Block<const Vector4d>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetPointsWithWeights(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::SetWeight(Int i, Float weight) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_SetWeight(o_, i, weight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangeWeights(const Block<const Float>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights(o_, weights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::ChangeWeights(const Block<const Float32>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_ChangeWeights_1(o_, weights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::Fn<S>::AddControlPoint(const Float t) const -> Result<Pair<Block<Vector4d>, Int>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Pair<Block<Vector4d>, Int>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1].NURBSCurveInterface_AddControlPoint(o_, t));
}
#if 0
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

