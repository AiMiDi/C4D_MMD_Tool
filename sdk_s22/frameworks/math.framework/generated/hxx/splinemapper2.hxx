
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct SplineMapperInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_SplineMapperInterface_Free) (const SplineMapperInterface* object);
	SplineMapperInterface* (*_SplineMapperInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	SplineMapperInterface* (*_SplineMapperInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object);
	Vector2d (*_SplineMapperInterface_GetPoint) (const SplineMapperInterface* this_, Float positionX);
	void (*_SplineMapperInterface_GetRange) (const SplineMapperInterface* this_, Vector2d& min, Vector2d& max);
	void (*_SplineMapperInterface_SetRange) (SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max);
	void (*_SplineMapperInterface_AdaptRange) (SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max);
	Float (*_SplineMapperInterface_GetTension) (const SplineMapperInterface* this_);
	void (*_SplineMapperInterface_SetTension) (SplineMapperInterface* this_, Float tension);
	Int (*_SplineMapperInterface_GetKnotCount) (const SplineMapperInterface* this_);
	SplineMapperKnot* (*_SplineMapperInterface_GetKnot) (SplineMapperInterface* this_, Int knotIndex);
	Bool (*_SplineMapperInterface_SetKnot) (SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot);
	Result<void> (*_SplineMapperInterface_InsertKnot) (SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot);
	Result<Int> (*_SplineMapperInterface_InsertKnot_1) (SplineMapperInterface* this_, Float x, Float y, Int flags, Bool adaptTangents);
	Result<void> (*_SplineMapperInterface_DeleteKnot) (SplineMapperInterface* this_, Int knotIndex);
	void (*_SplineMapperInterface_DeleteAllKnots) (SplineMapperInterface* this_);
	const BaseArray<SplineMapperKnot>& (*_SplineMapperInterface_GetKnots) (const SplineMapperInterface* this_);
	BaseArray<SplineMapperKnot>* (*_SplineMapperInterface_GetKnotsRW) (SplineMapperInterface* this_);
	void (*_SplineMapperInterface_SortKnots) (SplineMapperInterface* this_);
	Vector2d (*_SplineMapperInterface_ClampPosition) (const SplineMapperInterface* this_, const Vector2d& position);
	template <typename IMPL> void Init()
	{
		_SplineMapperInterface_Free = &IMPL::_SplineMapperInterface_Free;
		_SplineMapperInterface_Alloc = &IMPL::_SplineMapperInterface_Alloc;
		_SplineMapperInterface_Alloc_1 = &IMPL::_SplineMapperInterface_Alloc_1;
		_SplineMapperInterface_GetPoint = &IMPL::_SplineMapperInterface_GetPoint;
		_SplineMapperInterface_GetRange = &IMPL::_SplineMapperInterface_GetRange;
		_SplineMapperInterface_SetRange = &IMPL::_SplineMapperInterface_SetRange;
		_SplineMapperInterface_AdaptRange = &IMPL::_SplineMapperInterface_AdaptRange;
		_SplineMapperInterface_GetTension = &IMPL::_SplineMapperInterface_GetTension;
		_SplineMapperInterface_SetTension = &IMPL::_SplineMapperInterface_SetTension;
		_SplineMapperInterface_GetKnotCount = &IMPL::_SplineMapperInterface_GetKnotCount;
		_SplineMapperInterface_GetKnot = &IMPL::_SplineMapperInterface_GetKnot;
		_SplineMapperInterface_SetKnot = &IMPL::_SplineMapperInterface_SetKnot;
		_SplineMapperInterface_InsertKnot = &IMPL::_SplineMapperInterface_InsertKnot;
		_SplineMapperInterface_InsertKnot_1 = &IMPL::_SplineMapperInterface_InsertKnot_1;
		_SplineMapperInterface_DeleteKnot = &IMPL::_SplineMapperInterface_DeleteKnot;
		_SplineMapperInterface_DeleteAllKnots = &IMPL::_SplineMapperInterface_DeleteAllKnots;
		_SplineMapperInterface_GetKnots = &IMPL::_SplineMapperInterface_GetKnots;
		_SplineMapperInterface_GetKnotsRW = &IMPL::_SplineMapperInterface_GetKnotsRW;
		_SplineMapperInterface_SortKnots = &IMPL::_SplineMapperInterface_SortKnots;
		_SplineMapperInterface_ClampPosition = &IMPL::_SplineMapperInterface_ClampPosition;
	}
};

struct SplineMapperInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _SplineMapperInterface_Free(const SplineMapperInterface* object) { return C::Free(object); }
	static SplineMapperInterface* _SplineMapperInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static SplineMapperInterface* _SplineMapperInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Vector2d _SplineMapperInterface_GetPoint(const SplineMapperInterface* this_, Float positionX) { return ((const C*) this_)->GetPoint(positionX); }
	static void _SplineMapperInterface_GetRange(const SplineMapperInterface* this_, Vector2d& min, Vector2d& max) { return ((const C*) this_)->GetRange(min, max); }
	static void _SplineMapperInterface_SetRange(SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max) { return ((C*) this_)->SetRange(min, max); }
	static void _SplineMapperInterface_AdaptRange(SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max) { return ((C*) this_)->AdaptRange(min, max); }
	static Float _SplineMapperInterface_GetTension(const SplineMapperInterface* this_) { return ((const C*) this_)->GetTension(); }
	static void _SplineMapperInterface_SetTension(SplineMapperInterface* this_, Float tension) { return ((C*) this_)->SetTension(tension); }
	static Int _SplineMapperInterface_GetKnotCount(const SplineMapperInterface* this_) { return ((const C*) this_)->GetKnotCount(); }
	static SplineMapperKnot* _SplineMapperInterface_GetKnot(SplineMapperInterface* this_, Int knotIndex) { return ((C*) this_)->GetKnot(knotIndex); }
	static Bool _SplineMapperInterface_SetKnot(SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot) { return ((C*) this_)->SetKnot(knotIndex, knot); }
	static Result<void> _SplineMapperInterface_InsertKnot(SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot) { return ((C*) this_)->InsertKnot(knotIndex, knot); }
	static Result<Int> _SplineMapperInterface_InsertKnot_1(SplineMapperInterface* this_, Float x, Float y, Int flags, Bool adaptTangents) { return ((C*) this_)->InsertKnot(x, y, flags, adaptTangents); }
	static Result<void> _SplineMapperInterface_DeleteKnot(SplineMapperInterface* this_, Int knotIndex) { return ((C*) this_)->DeleteKnot(knotIndex); }
	static void _SplineMapperInterface_DeleteAllKnots(SplineMapperInterface* this_) { return ((C*) this_)->DeleteAllKnots(); }
	static const BaseArray<SplineMapperKnot>& _SplineMapperInterface_GetKnots(const SplineMapperInterface* this_) { return ((const C*) this_)->GetKnots(); }
	static BaseArray<SplineMapperKnot>* _SplineMapperInterface_GetKnotsRW(SplineMapperInterface* this_) { return ((C*) this_)->GetKnotsRW(); }
	static void _SplineMapperInterface_SortKnots(SplineMapperInterface* this_) { return ((C*) this_)->SortKnots(); }
	static Vector2d _SplineMapperInterface_ClampPosition(const SplineMapperInterface* this_, const Vector2d& position) { return ((const C*) this_)->ClampPosition(position); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Free(const SplineMapperInterface* object) -> void
{
	return MTable::_instance._SplineMapperInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Alloc(const maxon::SourceLocation& allocLocation) -> SplineMapperInterface*
{
	return MTable::_instance._SplineMapperInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Alloc(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) -> SplineMapperInterface*
{
	return MTable::_instance._SplineMapperInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetPoint(Float positionX) const -> Vector2d
{
	return MTable::_instance._SplineMapperInterface_GetPoint(this, positionX);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetRange(Vector2d& min, Vector2d& max) const -> void
{
	return MTable::_instance._SplineMapperInterface_GetRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetRange(const Vector2d& min, const Vector2d& max) -> void
{
	return MTable::_instance._SplineMapperInterface_SetRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::AdaptRange(const Vector2d& min, const Vector2d& max) -> void
{
	return MTable::_instance._SplineMapperInterface_AdaptRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetTension() const -> Float
{
	return MTable::_instance._SplineMapperInterface_GetTension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetTension(Float tension) -> void
{
	return MTable::_instance._SplineMapperInterface_SetTension(this, tension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotCount() const -> Int
{
	return MTable::_instance._SplineMapperInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnot(Int knotIndex) -> SplineMapperKnot*
{
	return MTable::_instance._SplineMapperInterface_GetKnot(this, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> Bool
{
	return MTable::_instance._SplineMapperInterface_SetKnot(this, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	return MTable::_instance._SplineMapperInterface_InsertKnot(this, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Float x, Float y, Int flags, Bool adaptTangents) -> Result<Int>
{
	return MTable::_instance._SplineMapperInterface_InsertKnot_1(this, x, y, flags, adaptTangents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteKnot(Int knotIndex) -> Result<void>
{
	return MTable::_instance._SplineMapperInterface_DeleteKnot(this, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteAllKnots() -> void
{
	return MTable::_instance._SplineMapperInterface_DeleteAllKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnots() const -> const BaseArray<SplineMapperKnot>&
{
	return MTable::_instance._SplineMapperInterface_GetKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotsRW() -> BaseArray<SplineMapperKnot>*
{
	return MTable::_instance._SplineMapperInterface_GetKnotsRW(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SortKnots() -> void
{
	return MTable::_instance._SplineMapperInterface_SortKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::ClampPosition(const Vector2d& position) const -> Vector2d
{
	return MTable::_instance._SplineMapperInterface_ClampPosition(this, position);
}

auto SplineMapperInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<SplineMapper>
{
	SplineMapperInterface* res_ = SplineMapperInterface::Alloc(MAXON_SOURCE_LOCATION);
	return SplineMapper(maxon::ForwardResultPtr<SplineMapperInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPoint(Float positionX) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._SplineMapperInterface_GetPoint(o_, positionX));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetRange(Vector2d& min, Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_GetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::SetRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_SetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._SplineMapperInterface_SetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::AdaptRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_AdaptRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::AdaptRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._SplineMapperInterface_AdaptRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._SplineMapperInterface_GetTension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::SetTension(Float tension) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_SetTension(o_, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetTension(Float tension) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._SplineMapperInterface_SetTension(o_, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._SplineMapperInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::GetKnot(Int knotIndex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance._SplineMapperInterface_GetKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetKnot(Int knotIndex) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_GetKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._SplineMapperInterface_SetKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_SetKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._SplineMapperInterface_InsertKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_InsertKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::InsertKnot(Float x, Float y, Int flags, Bool adaptTangents) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._SplineMapperInterface_InsertKnot_1(o_, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::InsertKnot(Float x, Float y, Int flags, Bool adaptTangents) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_InsertKnot_1(o_, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::DeleteKnot(Int knotIndex) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._SplineMapperInterface_DeleteKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::DeleteKnot(Int knotIndex) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_DeleteKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::DeleteAllKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_DeleteAllKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::DeleteAllKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._SplineMapperInterface_DeleteAllKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<SplineMapperKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._SplineMapperInterface_GetKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::GetKnotsRW() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance._SplineMapperInterface_GetKnotsRW(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetKnotsRW() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._SplineMapperInterface_GetKnotsRW(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ReferenceFunctionsImpl<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._SplineMapperInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWReferenceFunctionsImpl<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._SplineMapperInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ClampPosition(const Vector2d& position) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._SplineMapperInterface_ClampPosition(o_, position));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SplineMapperInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SplineMapperInterface() { new (s_ui_maxon_SplineMapperInterface) maxon::EntityUse(SplineMapperInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/splinemapper.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SplineMapperInterface(SplineMapperInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/splinemapper.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

