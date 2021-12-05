
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
	Result<Vector> (*_NURBSCurveInterface_EvaluateAt) (const NURBSCurveInterface* this_, Float s);
	Result<Vector> (*_NURBSCurveInterface_DeriveAt) (const NURBSCurveInterface* this_, Float s);
	Result<Int> (*_NURBSCurveInterface_GetDegree) (const NURBSCurveInterface* this_);
	Result<Int> (*_NURBSCurveInterface_GetMaxDegree) (const NURBSCurveInterface* this_);
	Int (*_NURBSCurveInterface_GetPointCount) (const NURBSCurveInterface* this_);
	Result<Int> (*_NURBSCurveInterface_GetWeightCount) (const NURBSCurveInterface* this_);
	Result<Vector> (*_NURBSCurveInterface_GetPoint) (const NURBSCurveInterface* this_, Int i);
	Result<Vector4d> (*_NURBSCurveInterface_GetPointWithWeight) (const NURBSCurveInterface* this_, Int i);
	const Block<const Vector4d> (*_NURBSCurveInterface_GetPointsWithWeights) (const NURBSCurveInterface* this_);
	Result<Float> (*_NURBSCurveInterface_GetWeight) (const NURBSCurveInterface* this_, Int i);
	Result<void> (*_NURBSCurveInterface_SetPoint) (NURBSCurveInterface* this_, Int i, const Vector& point);
	Result<void> (*_NURBSCurveInterface_SetPointWithWeight) (NURBSCurveInterface* this_, Int i, const Vector4d& point);
	Result<void> (*_NURBSCurveInterface_ChangePoints) (NURBSCurveInterface* this_, const Block<Vector>& points);
	Result<void> (*_NURBSCurveInterface_SetPointsWithWeights) (NURBSCurveInterface* this_, const Block<const Vector4d>& points);
	Result<void> (*_NURBSCurveInterface_SetWeight) (NURBSCurveInterface* this_, Int i, Float weight);
	Result<void> (*_NURBSCurveInterface_ChangeWeights) (NURBSCurveInterface* this_, const Block<const Float>& weights);
	Result<void> (*_NURBSCurveInterface_ChangeWeights_1) (NURBSCurveInterface* this_, const Block<const Float32>& weights);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const NURBSCurveInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_NURBSCurveInterface_EvaluateAt = &IMPL::_NURBSCurveInterface_EvaluateAt;
		_NURBSCurveInterface_DeriveAt = &IMPL::_NURBSCurveInterface_DeriveAt;
		_NURBSCurveInterface_GetDegree = &IMPL::_NURBSCurveInterface_GetDegree;
		_NURBSCurveInterface_GetMaxDegree = &IMPL::_NURBSCurveInterface_GetMaxDegree;
		_NURBSCurveInterface_GetPointCount = &IMPL::_NURBSCurveInterface_GetPointCount;
		_NURBSCurveInterface_GetWeightCount = &IMPL::_NURBSCurveInterface_GetWeightCount;
		_NURBSCurveInterface_GetPoint = &IMPL::_NURBSCurveInterface_GetPoint;
		_NURBSCurveInterface_GetPointWithWeight = &IMPL::_NURBSCurveInterface_GetPointWithWeight;
		_NURBSCurveInterface_GetPointsWithWeights = &IMPL::_NURBSCurveInterface_GetPointsWithWeights;
		_NURBSCurveInterface_GetWeight = &IMPL::_NURBSCurveInterface_GetWeight;
		_NURBSCurveInterface_SetPoint = &IMPL::_NURBSCurveInterface_SetPoint;
		_NURBSCurveInterface_SetPointWithWeight = &IMPL::_NURBSCurveInterface_SetPointWithWeight;
		_NURBSCurveInterface_ChangePoints = &IMPL::_NURBSCurveInterface_ChangePoints;
		_NURBSCurveInterface_SetPointsWithWeights = &IMPL::_NURBSCurveInterface_SetPointsWithWeights;
		_NURBSCurveInterface_SetWeight = &IMPL::_NURBSCurveInterface_SetWeight;
		_NURBSCurveInterface_ChangeWeights = &IMPL::_NURBSCurveInterface_ChangeWeights;
		_NURBSCurveInterface_ChangeWeights_1 = &IMPL::_NURBSCurveInterface_ChangeWeights_1;
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
		static Result<Vector> _NURBSCurveInterface_EvaluateAt(const NURBSCurveInterface* this_, Float s) { return C::Get(this_)->EvaluateAt(s); }
		static Result<Vector> _NURBSCurveInterface_DeriveAt(const NURBSCurveInterface* this_, Float s) { return C::Get(this_)->DeriveAt(s); }
		static Result<Int> _NURBSCurveInterface_GetDegree(const NURBSCurveInterface* this_) { return C::Get(this_)->GetDegree(); }
		static Result<Int> _NURBSCurveInterface_GetMaxDegree(const NURBSCurveInterface* this_) { return C::Get(this_)->GetMaxDegree(); }
		static Int _NURBSCurveInterface_GetPointCount(const NURBSCurveInterface* this_) { return C::Get(this_)->GetPointCount(); }
		static Result<Int> _NURBSCurveInterface_GetWeightCount(const NURBSCurveInterface* this_) { return C::Get(this_)->GetWeightCount(); }
		static Result<Vector> _NURBSCurveInterface_GetPoint(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetPoint(i); }
		static Result<Vector4d> _NURBSCurveInterface_GetPointWithWeight(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetPointWithWeight(i); }
		static const Block<const Vector4d> _NURBSCurveInterface_GetPointsWithWeights(const NURBSCurveInterface* this_) { return C::Get(this_)->GetPointsWithWeights(); }
		static Result<Float> _NURBSCurveInterface_GetWeight(const NURBSCurveInterface* this_, Int i) { return C::Get(this_)->GetWeight(i); }
		static Result<void> _NURBSCurveInterface_SetPoint(NURBSCurveInterface* this_, Int i, const Vector& point) { return C::Get(this_)->SetPoint(i, point); }
		static Result<void> _NURBSCurveInterface_SetPointWithWeight(NURBSCurveInterface* this_, Int i, const Vector4d& point) { return C::Get(this_)->SetPointWithWeight(i, point); }
		static Result<void> _NURBSCurveInterface_ChangePoints(NURBSCurveInterface* this_, const Block<Vector>& points) { return C::Get(this_)->ChangePoints(points); }
		static Result<void> _NURBSCurveInterface_SetPointsWithWeights(NURBSCurveInterface* this_, const Block<const Vector4d>& points) { return C::Get(this_)->SetPointsWithWeights(points); }
		static Result<void> _NURBSCurveInterface_SetWeight(NURBSCurveInterface* this_, Int i, Float weight) { return C::Get(this_)->SetWeight(i, weight); }
		static Result<void> _NURBSCurveInterface_ChangeWeights(NURBSCurveInterface* this_, const Block<const Float>& weights) { return C::Get(this_)->ChangeWeights(weights); }
		static Result<void> _NURBSCurveInterface_ChangeWeights_1(NURBSCurveInterface* this_, const Block<const Float32>& weights) { return C::Get(this_)->ChangeWeights(weights); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::EvaluateAt(Float s) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_EvaluateAt(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::DeriveAt(Float s) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_DeriveAt(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetDegree() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetDegree(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetMaxDegree() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetMaxDegree(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointCount() const -> Int
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeightCount() const -> Result<Int>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetWeightCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPoint(Int i) const -> Result<Vector>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPoint(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointWithWeight(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetPointsWithWeights() const -> const Block<const Vector4d>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointsWithWeights(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::GetWeight(Int i) const -> Result<Float>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_GetWeight(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPoint(Int i, const Vector& point) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPoint(this, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointWithWeight(Int i, const Vector4d& point) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPointWithWeight(this, i, point);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangePoints(const Block<Vector>& points) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangePoints(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetPointsWithWeights(const Block<const Vector4d>& points) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPointsWithWeights(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::SetWeight(Int i, Float weight) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_SetWeight(this, i, weight);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float>& weights) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangeWeights(this, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::ChangeWeights(const Block<const Float32>& weights) -> Result<void>
{
	return ((NURBSCurveInterface::MTable*) (this->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangeWeights_1(this, weights);
}

NURBSCurveInterface::NURBSCurveInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::EvaluateAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_EvaluateAt(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DeriveAt(Float s) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_DeriveAt(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetDegree(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMaxDegree() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetMaxDegree(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPointCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetWeightCount() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetWeightCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPoint(Int i) const -> Result<Vector>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPoint(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPointWithWeight(Int i) const -> Result<Vector4d>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Vector4d>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointWithWeight(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPointsWithWeights() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Block<const Vector4d>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetPointsWithWeights(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetWeight(Int i) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NURBSCurveInterface* o_ = (const NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NURBSCurveInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_GetWeight(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPoint(Int i, const Vector& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPoint(o_, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPointWithWeight(Int i, const Vector4d& point) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPointWithWeight(o_, i, point));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::ChangePoints(const Block<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangePoints(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPointsWithWeights(const Block<const Vector4d>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_SetPointsWithWeights(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::SetWeight(Int i, Float weight) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_SetWeight(o_, i, weight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::ChangeWeights(const Block<const Float>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangeWeights(o_, weights));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NURBSCurveInterface::Hxx1::ReferenceFunctionsImpl<S>::ChangeWeights(const Block<const Float32>& weights) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NURBSCurveInterface* o_ = (NURBSCurveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((NURBSCurveInterface::MTable*) (o_->_vtableCls + 1))[-1]._NURBSCurveInterface_ChangeWeights_1(o_, weights));
}
#if 0
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

