
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
	PRIVATE_MAXON_SF_POINTER(SplineMapperInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const SplineMapperInterface* object);
	PRIVATE_MAXON_SF_POINTER(SplineMapperInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (SplineMapperInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(SplineMapperInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (SplineMapperInterface*), const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetPoint, GetPoint, false, SplineMapperInterface, const, (Vector2d), Float positionX);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetRange, GetRange, false, SplineMapperInterface, const, (void), Vector2d& min, Vector2d& max);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_SetRange, SetRange, false, SplineMapperInterface,, (void), const Vector2d& min, const Vector2d& max);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_AdaptRange, AdaptRange, false, SplineMapperInterface,, (void), const Vector2d& min, const Vector2d& max);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetTension, GetTension, false, SplineMapperInterface, const, (Float));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_SetTension, SetTension, false, SplineMapperInterface,, (void), Float tension);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetKnotCount, GetKnotCount, false, SplineMapperInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetKnot, GetKnot, false, SplineMapperInterface,, (SplineMapperKnot*), Int knotIndex);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_SetKnot, SetKnot, false, SplineMapperInterface,, (Bool), Int knotIndex, const SplineMapperKnot& knot);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_IsEqual, IsEqual, false, SplineMapperInterface, const, (Bool), const SplineMapperInterface* other, EQUALITY equality);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetHashCode, GetHashCode, false, SplineMapperInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_InsertKnot, InsertKnot, false, SplineMapperInterface,, (Result<void>), Int knotIndex, const SplineMapperKnot& knot);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_InsertKnot_1, InsertKnot, false, SplineMapperInterface,, (Result<Int>), Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_DeleteKnot, DeleteKnot, false, SplineMapperInterface,, (Result<void>), Int knotIndex);
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_DeleteAllKnots, DeleteAllKnots, false, SplineMapperInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetKnots, GetKnots, false, SplineMapperInterface, const, (const BaseArray<SplineMapperKnot>&));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_GetKnotsRW, GetKnotsRW, false, SplineMapperInterface,, (BaseArray<SplineMapperKnot>*));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_SortKnots, SortKnots, false, SplineMapperInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(SplineMapperInterface_ClampPosition, ClampPosition, false, SplineMapperInterface, const, (Vector2d), const Vector2d& position);
	PRIVATE_MAXON_SF_POINTER(SplineMapperInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		SplineMapperInterface_Free = SplineMapperInterface_Free_GetPtr<IMPL>(true);
		SplineMapperInterface_Alloc = SplineMapperInterface_Alloc_GetPtr<IMPL>(true);
		SplineMapperInterface_Alloc_1 = SplineMapperInterface_Alloc_1_GetPtr<IMPL>(true);
		SplineMapperInterface_GetPoint = SplineMapperInterface_GetPoint_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetRange = SplineMapperInterface_GetRange_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_SetRange = SplineMapperInterface_SetRange_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_AdaptRange = SplineMapperInterface_AdaptRange_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetTension = SplineMapperInterface_GetTension_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_SetTension = SplineMapperInterface_SetTension_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetKnotCount = SplineMapperInterface_GetKnotCount_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetKnot = SplineMapperInterface_GetKnot_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_SetKnot = SplineMapperInterface_SetKnot_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_IsEqual = SplineMapperInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetHashCode = SplineMapperInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_InsertKnot = SplineMapperInterface_InsertKnot_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_InsertKnot_1 = SplineMapperInterface_InsertKnot_1_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_DeleteKnot = SplineMapperInterface_DeleteKnot_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_DeleteAllKnots = SplineMapperInterface_DeleteAllKnots_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetKnots = SplineMapperInterface_GetKnots_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_GetKnotsRW = SplineMapperInterface_GetKnotsRW_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_SortKnots = SplineMapperInterface_SortKnots_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_ClampPosition = SplineMapperInterface_ClampPosition_GetPtr<IMPL>(0, true).first;
		SplineMapperInterface_DescribeIO = SplineMapperInterface_DescribeIO_GetPtr<IMPL>(true);
	}
};

struct SplineMapperInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void SplineMapperInterface_Free(const SplineMapperInterface* object) { return C::Free(object); }
		static SplineMapperInterface* SplineMapperInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static SplineMapperInterface* SplineMapperInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetPoint, SplineMapperInterface, const, (Vector2d), Float positionX) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetPoint(positionX); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetRange, SplineMapperInterface, const, (void), Vector2d& min, Vector2d& max) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetRange(min, max); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_SetRange, SplineMapperInterface,, (void), const Vector2d& min, const Vector2d& max) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->SetRange(min, max); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_AdaptRange, SplineMapperInterface,, (void), const Vector2d& min, const Vector2d& max) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->AdaptRange(min, max); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetTension, SplineMapperInterface, const, (Float)) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetTension(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_SetTension, SplineMapperInterface,, (void), Float tension) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->SetTension(tension); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetKnotCount, SplineMapperInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetKnotCount(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetKnot, SplineMapperInterface,, (SplineMapperKnot*), Int knotIndex) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->GetKnot(knotIndex); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_SetKnot, SplineMapperInterface,, (Bool), Int knotIndex, const SplineMapperKnot& knot) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->SetKnot(knotIndex, knot); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_IsEqual, SplineMapperInterface, const, (Bool), const SplineMapperInterface* other, EQUALITY equality) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->IsEqual(other, equality); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetHashCode, SplineMapperInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_InsertKnot, SplineMapperInterface,, (Result<void>), Int knotIndex, const SplineMapperKnot& knot) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->InsertKnot(knotIndex, knot); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_InsertKnot_1, SplineMapperInterface,, (Result<Int>), Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->InsertKnot(x, y, flags, adaptTangents); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_DeleteKnot, SplineMapperInterface,, (Result<void>), Int knotIndex) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->DeleteKnot(knotIndex); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_DeleteAllKnots, SplineMapperInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->DeleteAllKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetKnots, SplineMapperInterface, const, (const BaseArray<SplineMapperKnot>&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->GetKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_GetKnotsRW, SplineMapperInterface,, (BaseArray<SplineMapperKnot>*)) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->GetKnotsRW(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_SortKnots, SplineMapperInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(SplineMapperInterface))->SortKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(SplineMapperInterface_ClampPosition, SplineMapperInterface, const, (Vector2d), const Vector2d& position) { return C::Get(PRIVATE_MAXON_MF_THIS(const SplineMapperInterface))->ClampPosition(position); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetPoint, positionX);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetRange(Vector2d& min, Vector2d& max) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetRange, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetRange(const Vector2d& min, const Vector2d& max) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_SetRange, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::AdaptRange(const Vector2d& min, const Vector2d& max) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_AdaptRange, min, max);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetTension() const -> Float
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetTension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetTension(Float tension) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_SetTension, tension);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetKnotCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnot(Int knotIndex) -> SplineMapperKnot*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetKnot, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_SetKnot, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::IsEqual(const SplineMapperInterface* other, EQUALITY equality) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_IsEqual, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_InsertKnot, knotIndex, knot);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_InsertKnot_1, x, y, flags, adaptTangents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteKnot(Int knotIndex) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_DeleteKnot, knotIndex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::DeleteAllKnots() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_DeleteAllKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnots() const -> const BaseArray<SplineMapperKnot>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::GetKnotsRW() -> BaseArray<SplineMapperKnot>*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_GetKnotsRW);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::SortKnots() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_SortKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::ClampPosition(const Vector2d& position) const -> Vector2d
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.SplineMapperInterface_ClampPosition, position);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetPoint, positionX));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetRange(Vector2d& min, Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetRange, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetRange, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetRange, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::AdaptRange(const Vector2d& min, const Vector2d& max) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_AdaptRange, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::AdaptRange(const Vector2d& min, const Vector2d& max) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_AdaptRange, min, max);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetTension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetTension));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetTension(Float tension) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetTension, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetTension(Float tension) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetTension, tension);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnotCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::GetKnot(Int knotIndex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnot, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::GetKnot(Int knotIndex) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnot, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetKnot, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SetKnot(Int knotIndex, const SplineMapperKnot& knot) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SetKnot, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::IsEqual(const SplineMapperInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_IsEqual, other, equality));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_InsertKnot, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::InsertKnot(Int knotIndex, const SplineMapperKnot& knot) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_InsertKnot, knotIndex, knot));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_InsertKnot_1, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_InsertKnot_1, x, y, flags, adaptTangents));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::DeleteKnot(Int knotIndex) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_DeleteKnot, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::DeleteKnot(Int knotIndex) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_DeleteKnot, knotIndex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::DeleteAllKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_DeleteAllKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::DeleteAllKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_DeleteAllKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<SplineMapperKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::GetKnotsRW() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnotsRW));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::GetKnotsRW() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_GetKnotsRW));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::Fn<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SortKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::COWFn<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); SplineMapperInterface* o_ = (SplineMapperInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_SortKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SplineMapperInterface::Hxx1::ConstFn<S>::ClampPosition(const Vector2d& position) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SplineMapperInterface* o_ = (const SplineMapperInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SplineMapperInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.SplineMapperInterface_ClampPosition, position));
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

