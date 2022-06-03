
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* SplineMapperInterface::PrivateGetCppName() { return "maxon::SplineMapper"; }

struct SplineMapperInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*SplineMapperInterface_Free) (const SplineMapperInterface* object);
	SplineMapperInterface* (*SplineMapperInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	SplineMapperInterface* (*SplineMapperInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object);
	Vector2d (*SplineMapperInterface_GetPoint) (const SplineMapperInterface* this_, Float positionX);
	void (*SplineMapperInterface_GetRange) (const SplineMapperInterface* this_, Vector2d& min, Vector2d& max);
	void (*SplineMapperInterface_SetRange) (SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max);
	void (*SplineMapperInterface_AdaptRange) (SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max);
	Float (*SplineMapperInterface_GetTension) (const SplineMapperInterface* this_);
	void (*SplineMapperInterface_SetTension) (SplineMapperInterface* this_, Float tension);
	Int (*SplineMapperInterface_GetKnotCount) (const SplineMapperInterface* this_);
	SplineMapperKnot* (*SplineMapperInterface_GetKnot) (SplineMapperInterface* this_, Int knotIndex);
	Bool (*SplineMapperInterface_SetKnot) (SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot);
	Bool (*SplineMapperInterface_IsEqual) (const SplineMapperInterface* this_, const SplineMapperInterface* other, EQUALITY equality);
	HashInt (*SplineMapperInterface_GetHashCode) (const SplineMapperInterface* this_);
	Result<void> (*SplineMapperInterface_InsertKnot) (SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot);
	Result<Int> (*SplineMapperInterface_InsertKnot_1) (SplineMapperInterface* this_, Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents);
	Result<void> (*SplineMapperInterface_DeleteKnot) (SplineMapperInterface* this_, Int knotIndex);
	void (*SplineMapperInterface_DeleteAllKnots) (SplineMapperInterface* this_);
	const BaseArray<SplineMapperKnot>& (*SplineMapperInterface_GetKnots) (const SplineMapperInterface* this_);
	BaseArray<SplineMapperKnot>* (*SplineMapperInterface_GetKnotsRW) (SplineMapperInterface* this_);
	void (*SplineMapperInterface_SortKnots) (SplineMapperInterface* this_);
	Vector2d (*SplineMapperInterface_ClampPosition) (const SplineMapperInterface* this_, const Vector2d& position);
	Result<void> (*SplineMapperInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		SplineMapperInterface_Free = &IMPL::SplineMapperInterface_Free;
		SplineMapperInterface_Alloc = &IMPL::SplineMapperInterface_Alloc;
		SplineMapperInterface_Alloc_1 = &IMPL::SplineMapperInterface_Alloc_1;
		SplineMapperInterface_GetPoint = &IMPL::SplineMapperInterface_GetPoint;
		SplineMapperInterface_GetRange = &IMPL::SplineMapperInterface_GetRange;
		SplineMapperInterface_SetRange = &IMPL::SplineMapperInterface_SetRange;
		SplineMapperInterface_AdaptRange = &IMPL::SplineMapperInterface_AdaptRange;
		SplineMapperInterface_GetTension = &IMPL::SplineMapperInterface_GetTension;
		SplineMapperInterface_SetTension = &IMPL::SplineMapperInterface_SetTension;
		SplineMapperInterface_GetKnotCount = &IMPL::SplineMapperInterface_GetKnotCount;
		SplineMapperInterface_GetKnot = &IMPL::SplineMapperInterface_GetKnot;
		SplineMapperInterface_SetKnot = &IMPL::SplineMapperInterface_SetKnot;
		SplineMapperInterface_IsEqual = &IMPL::SplineMapperInterface_IsEqual;
		SplineMapperInterface_GetHashCode = &IMPL::SplineMapperInterface_GetHashCode;
		SplineMapperInterface_InsertKnot = &IMPL::SplineMapperInterface_InsertKnot;
		SplineMapperInterface_InsertKnot_1 = &IMPL::SplineMapperInterface_InsertKnot_1;
		SplineMapperInterface_DeleteKnot = &IMPL::SplineMapperInterface_DeleteKnot;
		SplineMapperInterface_DeleteAllKnots = &IMPL::SplineMapperInterface_DeleteAllKnots;
		SplineMapperInterface_GetKnots = &IMPL::SplineMapperInterface_GetKnots;
		SplineMapperInterface_GetKnotsRW = &IMPL::SplineMapperInterface_GetKnotsRW;
		SplineMapperInterface_SortKnots = &IMPL::SplineMapperInterface_SortKnots;
		SplineMapperInterface_ClampPosition = &IMPL::SplineMapperInterface_ClampPosition;
		SplineMapperInterface_DescribeIO = &IMPL::SplineMapperInterface_DescribeIO;
	}
};

struct SplineMapperInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void SplineMapperInterface_Free(const SplineMapperInterface* object) { return C::Free(object); }
		static SplineMapperInterface* SplineMapperInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static SplineMapperInterface* SplineMapperInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Vector2d SplineMapperInterface_GetPoint(const SplineMapperInterface* this_, Float positionX) { return C::Get(this_)->GetPoint(positionX); }
		static void SplineMapperInterface_GetRange(const SplineMapperInterface* this_, Vector2d& min, Vector2d& max) { return C::Get(this_)->GetRange(min, max); }
		static void SplineMapperInterface_SetRange(SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max) { return C::Get(this_)->SetRange(min, max); }
		static void SplineMapperInterface_AdaptRange(SplineMapperInterface* this_, const Vector2d& min, const Vector2d& max) { return C::Get(this_)->AdaptRange(min, max); }
		static Float SplineMapperInterface_GetTension(const SplineMapperInterface* this_) { return C::Get(this_)->GetTension(); }
		static void SplineMapperInterface_SetTension(SplineMapperInterface* this_, Float tension) { return C::Get(this_)->SetTension(tension); }
		static Int SplineMapperInterface_GetKnotCount(const SplineMapperInterface* this_) { return C::Get(this_)->GetKnotCount(); }
		static SplineMapperKnot* SplineMapperInterface_GetKnot(SplineMapperInterface* this_, Int knotIndex) { return C::Get(this_)->GetKnot(knotIndex); }
		static Bool SplineMapperInterface_SetKnot(SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot) { return C::Get(this_)->SetKnot(knotIndex, knot); }
		static Bool SplineMapperInterface_IsEqual(const SplineMapperInterface* this_, const SplineMapperInterface* other, EQUALITY equality) { return C::Get(this_)->IsEqual(other, equality); }
		static HashInt SplineMapperInterface_GetHashCode(const SplineMapperInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static Result<void> SplineMapperInterface_InsertKnot(SplineMapperInterface* this_, Int knotIndex, const SplineMapperKnot& knot) { return C::Get(this_)->InsertKnot(knotIndex, knot); }
		static Result<Int> SplineMapperInterface_InsertKnot_1(SplineMapperInterface* this_, Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) { return C::Get(this_)->InsertKnot(x, y, flags, adaptTangents); }
		static Result<void> SplineMapperInterface_DeleteKnot(SplineMapperInterface* this_, Int knotIndex) { return C::Get(this_)->DeleteKnot(knotIndex); }
		static void SplineMapperInterface_DeleteAllKnots(SplineMapperInterface* this_) { return C::Get(this_)->DeleteAllKnots(); }
		static const BaseArray<SplineMapperKnot>& SplineMapperInterface_GetKnots(const SplineMapperInterface* this_) { return C::Get(this_)->GetKnots(); }
		static BaseArray<SplineMapperKnot>* SplineMapperInterface_GetKnotsRW(SplineMapperInterface* this_) { return C::Get(this_)->GetKnotsRW(); }
		static void SplineMapperInterface_SortKnots(SplineMapperInterface* this_) { return C::Get(this_)->SortKnots(); }
		static Vector2d SplineMapperInterface_ClampPosition(const SplineMapperInterface* this_, const Vector2d& position) { return C::Get(this_)->ClampPosition(position); }
		static Result<void> SplineMapperInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Free(const SplineMapperInterface* object) -> void
{
	return MTable::_instance.SplineMapperInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Alloc(const maxon::SourceLocation& allocLocation) -> SplineMapperInterface*
{
	return MTable::_instance.SplineMapperInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Alloc(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) -> SplineMapperInterface*
{
	return MTable::_instance.SplineMapperInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetPoint(Float positionX) const -> Vector2d
{
	return MTable::_instance.SplineMapperInterface_GetPoint(this, positionX);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetRange(Vector2d& min, Vector2d& max) const -> void
{
	return MTable::_instance.SplineMapperInterface_GetRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetRange(const Vector2d& min, const Vector2d& max) -> void
{
	return MTable::_instance.SplineMapperInterface_SetRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::AdaptRange(const Vector2d& min, const Vector2d& max) -> void
{
	return MTable::_instance.SplineMapperInterface_AdaptRange(this, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetTension() const -> Float
{
	return MTable::_instance.SplineMapperInterface_GetTension(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetTension(Float tension) -> void
{
	return MTable::_instance.SplineMapperInterface_SetTension(this, tension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotCount() const -> Int
{
	return MTable::_instance.SplineMapperInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnot(Int knotIndex) -> SplineMapperKnot*
{
	return MTable::_instance.SplineMapperInterface_GetKnot(this, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> Bool
{
	return MTable::_instance.SplineMapperInterface_SetKnot(this, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::IsEqual(const SplineMapperInterface* other, EQUALITY equality) const -> Bool
{
	return MTable::_instance.SplineMapperInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.SplineMapperInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	return MTable::_instance.SplineMapperInterface_InsertKnot(this, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) -> Result<Int>
{
	return MTable::_instance.SplineMapperInterface_InsertKnot_1(this, x, y, flags, adaptTangents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteKnot(Int knotIndex) -> Result<void>
{
	return MTable::_instance.SplineMapperInterface_DeleteKnot(this, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteAllKnots() -> void
{
	return MTable::_instance.SplineMapperInterface_DeleteAllKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnots() const -> const BaseArray<SplineMapperKnot>&
{
	return MTable::_instance.SplineMapperInterface_GetKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotsRW() -> BaseArray<SplineMapperKnot>*
{
	return MTable::_instance.SplineMapperInterface_GetKnotsRW(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SortKnots() -> void
{
	return MTable::_instance.SplineMapperInterface_SortKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::ClampPosition(const Vector2d& position) const -> Vector2d
{
	return MTable::_instance.SplineMapperInterface_ClampPosition(this, position);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.SplineMapperInterface_DescribeIO(stream);
}

auto SplineMapperInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<SplineMapper>
{
	SplineMapperInterface* res_ = SplineMapperInterface::Alloc(MAXON_SOURCE_LOCATION);
	return SplineMapper(maxon::ForwardResultPtr<SplineMapperInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetPoint(Float positionX) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.SplineMapperInterface_GetPoint(o_, positionX));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetRange(Vector2d& min, Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_GetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_SetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.SplineMapperInterface_SetRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::AdaptRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_AdaptRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::AdaptRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.SplineMapperInterface_AdaptRange(o_, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetTension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.SplineMapperInterface_GetTension(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetTension(Float tension) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_SetTension(o_, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetTension(Float tension) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.SplineMapperInterface_SetTension(o_, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.SplineMapperInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::GetKnot(Int knotIndex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance.SplineMapperInterface_GetKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::GetKnot(Int knotIndex) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_GetKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.SplineMapperInterface_SetKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_SetKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::IsEqual(const SplineMapperInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.SplineMapperInterface_IsEqual(o_, other, equality));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.SplineMapperInterface_InsertKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_InsertKnot(o_, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.SplineMapperInterface_InsertKnot_1(o_, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_InsertKnot_1(o_, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::DeleteKnot(Int knotIndex) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.SplineMapperInterface_DeleteKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::DeleteKnot(Int knotIndex) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_DeleteKnot(o_, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::DeleteAllKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_DeleteAllKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::DeleteAllKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.SplineMapperInterface_DeleteAllKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<SplineMapperKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.SplineMapperInterface_GetKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::GetKnotsRW() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance.SplineMapperInterface_GetKnotsRW(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::GetKnotsRW() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.SplineMapperInterface_GetKnotsRW(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.SplineMapperInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.SplineMapperInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::ClampPosition(const Vector2d& position) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.SplineMapperInterface_ClampPosition(o_, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.SplineMapperInterface_DescribeIO(stream));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_splinemapper)
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

