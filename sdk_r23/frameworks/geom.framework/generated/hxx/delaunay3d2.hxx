
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Delaunay3DInterface::PrivateGetCppName() { return "maxon::Delaunay3DRef"; }

struct Delaunay3DInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_Delaunay3DInterface_Free) (const Delaunay3DInterface* object);
	Delaunay3DInterface* (*_Delaunay3DInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_Delaunay3DInterface_CopyFrom) (Delaunay3DInterface* this_, const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags);
	Result<void> (*_Delaunay3DInterface_Init) (Delaunay3DInterface* this_, const Range<Vector>& workSpace);
	Result<void> (*_Delaunay3DInterface_CalculateDelaunayTetrahedralization) (Delaunay3DInterface* this_);
	Bool (*_Delaunay3DInterface_IsInitialized) (Delaunay3DInterface* this_);
	Result<void> (*_Delaunay3DInterface_AddPointsIntoTetrahedralization) (Delaunay3DInterface* this_, const BaseArray<Vector>& newPointsIn);
	Result<void> (*_Delaunay3DInterface_AddPointIntoTetrahedralization) (Delaunay3DInterface* this_, const Vector& newPointIn);
	const BaseArray<Tetrahedron>& (*_Delaunay3DInterface_GetTetrahedrons) (const Delaunay3DInterface* this_, Int& arrayCount, Int& pointCount);
	const BaseArray<Tetrahedron>& (*_Delaunay3DInterface_GetTetrahedrons_1) (const Delaunay3DInterface* this_);
	const BaseArray<Int32>& (*_Delaunay3DInterface_GetPointsToTetConnections) (const Delaunay3DInterface* this_);
	const BaseArray<Vector>& (*_Delaunay3DInterface_GetPoints) (const Delaunay3DInterface* this_);
	ResultRef<BaseArray<Vector>> (*_Delaunay3DInterface_GetPointsWrite) (Delaunay3DInterface* this_);
	Int (*_Delaunay3DInterface_GetTetrahedronCount) (const Delaunay3DInterface* this_);
	Int (*_Delaunay3DInterface_GetPointCount) (const Delaunay3DInterface* this_);
	Result<void> (*_Delaunay3DInterface_Reset) (Delaunay3DInterface* this_);
	Float (*_Delaunay3DInterface_OrientDet) (const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint);
	void (*_Delaunay3DInterface_Flush) (Delaunay3DInterface* this_);
	Result<Bool> (*_Delaunay3DInterface_FindTetIndexContainingPoint) (const Delaunay3DInterface* this_, const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2);
	Result<Bool> (*_Delaunay3DInterface_FindTetContainingPoint) (const Delaunay3DInterface* this_, const Vector& point, Int32& foundTetIndex);
	template <typename IMPL> void Init()
	{
		_Delaunay3DInterface_Free = &IMPL::_Delaunay3DInterface_Free;
		_Delaunay3DInterface_Alloc = &IMPL::_Delaunay3DInterface_Alloc;
		_Delaunay3DInterface_CopyFrom = &IMPL::_Delaunay3DInterface_CopyFrom;
		_Delaunay3DInterface_Init = &IMPL::_Delaunay3DInterface_Init;
		_Delaunay3DInterface_CalculateDelaunayTetrahedralization = &IMPL::_Delaunay3DInterface_CalculateDelaunayTetrahedralization;
		_Delaunay3DInterface_IsInitialized = &IMPL::_Delaunay3DInterface_IsInitialized;
		_Delaunay3DInterface_AddPointsIntoTetrahedralization = &IMPL::_Delaunay3DInterface_AddPointsIntoTetrahedralization;
		_Delaunay3DInterface_AddPointIntoTetrahedralization = &IMPL::_Delaunay3DInterface_AddPointIntoTetrahedralization;
		_Delaunay3DInterface_GetTetrahedrons = &IMPL::_Delaunay3DInterface_GetTetrahedrons;
		_Delaunay3DInterface_GetTetrahedrons_1 = &IMPL::_Delaunay3DInterface_GetTetrahedrons_1;
		_Delaunay3DInterface_GetPointsToTetConnections = &IMPL::_Delaunay3DInterface_GetPointsToTetConnections;
		_Delaunay3DInterface_GetPoints = &IMPL::_Delaunay3DInterface_GetPoints;
		_Delaunay3DInterface_GetPointsWrite = &IMPL::_Delaunay3DInterface_GetPointsWrite;
		_Delaunay3DInterface_GetTetrahedronCount = &IMPL::_Delaunay3DInterface_GetTetrahedronCount;
		_Delaunay3DInterface_GetPointCount = &IMPL::_Delaunay3DInterface_GetPointCount;
		_Delaunay3DInterface_Reset = &IMPL::_Delaunay3DInterface_Reset;
		_Delaunay3DInterface_OrientDet = &IMPL::_Delaunay3DInterface_OrientDet;
		_Delaunay3DInterface_Flush = &IMPL::_Delaunay3DInterface_Flush;
		_Delaunay3DInterface_FindTetIndexContainingPoint = &IMPL::_Delaunay3DInterface_FindTetIndexContainingPoint;
		_Delaunay3DInterface_FindTetContainingPoint = &IMPL::_Delaunay3DInterface_FindTetContainingPoint;
	}
};

struct Delaunay3DInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _Delaunay3DInterface_Free(const Delaunay3DInterface* object) { return C::Free(object); }
		static Delaunay3DInterface* _Delaunay3DInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> _Delaunay3DInterface_CopyFrom(Delaunay3DInterface* this_, const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->CopyFrom(src, resizeFlags); }
		static Result<void> _Delaunay3DInterface_Init(Delaunay3DInterface* this_, const Range<Vector>& workSpace) { return C::Get(this_)->Init(workSpace); }
		static Result<void> _Delaunay3DInterface_CalculateDelaunayTetrahedralization(Delaunay3DInterface* this_) { return C::Get(this_)->CalculateDelaunayTetrahedralization(); }
		static Bool _Delaunay3DInterface_IsInitialized(Delaunay3DInterface* this_) { return C::Get(this_)->IsInitialized(); }
		static Result<void> _Delaunay3DInterface_AddPointsIntoTetrahedralization(Delaunay3DInterface* this_, const BaseArray<Vector>& newPointsIn) { return C::Get(this_)->AddPointsIntoTetrahedralization(newPointsIn); }
		static Result<void> _Delaunay3DInterface_AddPointIntoTetrahedralization(Delaunay3DInterface* this_, const Vector& newPointIn) { return C::Get(this_)->AddPointIntoTetrahedralization(newPointIn); }
		static const BaseArray<Tetrahedron>& _Delaunay3DInterface_GetTetrahedrons(const Delaunay3DInterface* this_, Int& arrayCount, Int& pointCount) { return C::Get(this_)->GetTetrahedrons(arrayCount, pointCount); }
		static const BaseArray<Tetrahedron>& _Delaunay3DInterface_GetTetrahedrons_1(const Delaunay3DInterface* this_) { return C::Get(this_)->GetTetrahedrons(); }
		static const BaseArray<Int32>& _Delaunay3DInterface_GetPointsToTetConnections(const Delaunay3DInterface* this_) { return C::Get(this_)->GetPointsToTetConnections(); }
		static const BaseArray<Vector>& _Delaunay3DInterface_GetPoints(const Delaunay3DInterface* this_) { return C::Get(this_)->GetPoints(); }
		static ResultRef<BaseArray<Vector>> _Delaunay3DInterface_GetPointsWrite(Delaunay3DInterface* this_) { return C::Get(this_)->GetPointsWrite(); }
		static Int _Delaunay3DInterface_GetTetrahedronCount(const Delaunay3DInterface* this_) { return C::Get(this_)->GetTetrahedronCount(); }
		static Int _Delaunay3DInterface_GetPointCount(const Delaunay3DInterface* this_) { return C::Get(this_)->GetPointCount(); }
		static Result<void> _Delaunay3DInterface_Reset(Delaunay3DInterface* this_) { return C::Get(this_)->Reset(); }
		static Float _Delaunay3DInterface_OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) { return C::OrientDet(planePointA, planePointB, planePointC, testPoint); }
		static void _Delaunay3DInterface_Flush(Delaunay3DInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<Bool> _Delaunay3DInterface_FindTetIndexContainingPoint(const Delaunay3DInterface* this_, const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) { return C::Get(this_)->FindTetIndexContainingPoint(point, foundTetIndex, onFace1, onFace2); }
		static Result<Bool> _Delaunay3DInterface_FindTetContainingPoint(const Delaunay3DInterface* this_, const Vector& point, Int32& foundTetIndex) { return C::Get(this_)->FindTetContainingPoint(point, foundTetIndex); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Free(const Delaunay3DInterface* object) -> void
{
	return MTable::_instance._Delaunay3DInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Delaunay3DInterface*
{
	return MTable::_instance._Delaunay3DInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_CopyFrom(this, src, resizeFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Init(const Range<Vector>& workSpace) -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_Init(this, workSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::CalculateDelaunayTetrahedralization() -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_CalculateDelaunayTetrahedralization(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::IsInitialized() -> Bool
{
	return MTable::_instance._Delaunay3DInterface_IsInitialized(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_AddPointsIntoTetrahedralization(this, newPointsIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::AddPointIntoTetrahedralization(const Vector& newPointIn) -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_AddPointIntoTetrahedralization(this, newPointIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedrons(Int& arrayCount, Int& pointCount) const -> const BaseArray<Tetrahedron>&
{
	return MTable::_instance._Delaunay3DInterface_GetTetrahedrons(this, arrayCount, pointCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedrons() const -> const BaseArray<Tetrahedron>&
{
	return MTable::_instance._Delaunay3DInterface_GetTetrahedrons_1(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointsToTetConnections() const -> const BaseArray<Int32>&
{
	return MTable::_instance._Delaunay3DInterface_GetPointsToTetConnections(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPoints() const -> const BaseArray<Vector>&
{
	return MTable::_instance._Delaunay3DInterface_GetPoints(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointsWrite() -> ResultRef<BaseArray<Vector>>
{
	return MTable::_instance._Delaunay3DInterface_GetPointsWrite(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedronCount() const -> Int
{
	return MTable::_instance._Delaunay3DInterface_GetTetrahedronCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointCount() const -> Int
{
	return MTable::_instance._Delaunay3DInterface_GetPointCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Reset() -> Result<void>
{
	return MTable::_instance._Delaunay3DInterface_Reset(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) -> Float
{
	return MTable::_instance._Delaunay3DInterface_OrientDet(planePointA, planePointB, planePointC, testPoint);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Flush() -> void
{
	return MTable::_instance._Delaunay3DInterface_Flush(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const -> Result<Bool>
{
	return MTable::_instance._Delaunay3DInterface_FindTetIndexContainingPoint(this, point, foundTetIndex, onFace1, onFace2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const -> Result<Bool>
{
	return MTable::_instance._Delaunay3DInterface_FindTetContainingPoint(this, point, foundTetIndex);
}

auto Delaunay3DInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Delaunay3DRef>
{
	Delaunay3DInterface* res_ = Delaunay3DInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Delaunay3DRef(maxon::ForwardResultPtr<Delaunay3DInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_CopyFrom(o_, src, resizeFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const Range<Vector>& workSpace) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_Init(o_, workSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CalculateDelaunayTetrahedralization() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_CalculateDelaunayTetrahedralization(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::IsInitialized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._Delaunay3DInterface_IsInitialized(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_AddPointsIntoTetrahedralization(o_, newPointsIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::AddPointIntoTetrahedralization(const Vector& newPointIn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_AddPointIntoTetrahedralization(o_, newPointIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTetrahedrons(Int& arrayCount, Int& pointCount) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Tetrahedron>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Delaunay3DInterface_GetTetrahedrons(o_, arrayCount, pointCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTetrahedrons() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Tetrahedron>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Delaunay3DInterface_GetTetrahedrons_1(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPointsToTetConnections() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Int32>&>, const BaseArray<Int32>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Int32>&>, const BaseArray<Int32>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Int32>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Delaunay3DInterface_GetPointsToTetConnections(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPoints() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Delaunay3DInterface_GetPoints(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetPointsWrite() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Vector>&>, ResultRef<BaseArray<Vector>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Vector>&>, ResultRef<BaseArray<Vector>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Vector>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Delaunay3DInterface_GetPointsWrite(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTetrahedronCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._Delaunay3DInterface_GetTetrahedronCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPointCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._Delaunay3DInterface_GetPointCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_Reset(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) -> Float { return (MTable::_instance._Delaunay3DInterface_OrientDet(planePointA, planePointB, planePointC, testPoint)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Delaunay3DInterface* o_ = (Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._Delaunay3DInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_FindTetIndexContainingPoint(o_, point, foundTetIndex, onFace1, onFace2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Delaunay3DInterface* o_ = (const Delaunay3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Delaunay3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Delaunay3DInterface_FindTetContainingPoint(o_, point, foundTetIndex));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Delaunay3DInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Delaunay3DInterface() { new (s_ui_maxon_Delaunay3DInterface) maxon::EntityUse(Delaunay3DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/delaunay3d.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Delaunay3DInterface(Delaunay3DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/delaunay3d.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

