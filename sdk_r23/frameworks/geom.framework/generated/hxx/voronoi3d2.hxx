
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Voronoi3DInterface::PrivateGetCppName() { return "maxon::Voronoi3DRef"; }

struct Voronoi3DInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_Voronoi3DInterface_Free) (const Voronoi3DInterface* object);
	Voronoi3DInterface* (*_Voronoi3DInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_Voronoi3DInterface_Init) (Voronoi3DInterface* this_, const Range<Vector>& workSpace);
	Result<void> (*_Voronoi3DInterface_CopyFrom) (Voronoi3DInterface* this_, const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags);
	Bool (*_Voronoi3DInterface_IsReadyButPendingChanges) (Voronoi3DInterface* this_);
	Bool (*_Voronoi3DInterface_IsReady) (Voronoi3DInterface* this_);
	Result<void> (*_Voronoi3DInterface_SetPoints) (Voronoi3DInterface* this_, const BaseArray<Vector>& points);
	Result<void> (*_Voronoi3DInterface_AddPoint) (Voronoi3DInterface* this_, const Vector& pointIn);
	Result<void> (*_Voronoi3DInterface_AddPoints) (Voronoi3DInterface* this_, const BaseArray<Vector>& points);
	Result<void> (*_Voronoi3DInterface_CalcCells) (Voronoi3DInterface* this_);
	Result<void> (*_Voronoi3DInterface_CalcTetrahedralization) (Voronoi3DInterface* this_);
	void (*_Voronoi3DInterface_SetForClipping) (Voronoi3DInterface* this_, Bool clipping);
	Int (*_Voronoi3DInterface_GetCellCount) (Voronoi3DInterface* this_);
	const BaseArray<Vector>& (*_Voronoi3DInterface_GetVoronoiPointPositions) (const Voronoi3DInterface* this_);
	const BaseArray<Vector>& (*_Voronoi3DInterface_GetInputPoints) (const Voronoi3DInterface* this_);
	ResultRef<BaseArray<Bool>> (*_Voronoi3DInterface_GetBorderCellFlags) (Voronoi3DInterface* this_);
	ResultRef<BaseArray<CellData>> (*_Voronoi3DInterface_GetCellDataStructure) (Voronoi3DInterface* this_);
	ResultRef<BaseArray<Char>> (*_Voronoi3DInterface_GetCellHasVolume) (Voronoi3DInterface* this_);
	Result<void> (*_Voronoi3DInterface_ScaleCell) (Voronoi3DInterface* this_, Int cellIndex, Float scaleValue);
	Result<void> (*_Voronoi3DInterface_ScaleAllCells) (Voronoi3DInterface* this_, Float scaleValue);
	ResultRef<Delaunay3DRef> (*_Voronoi3DInterface_GetDelaunayTetrizer) (Voronoi3DInterface* this_);
	void (*_Voronoi3DInterface_Flush) (Voronoi3DInterface* this_);
	Result<void> (*_Voronoi3DInterface_SetCellFuseGroup) (Voronoi3DInterface* this_, BaseArray<Int>& fuseIndices);
	Result<void> (*_Voronoi3DInterface_FuseCells) (Voronoi3DInterface* this_, BaseArray<Pair<Int, Int>>& joinList);
	Result<void> (*_Voronoi3DInterface_CreateInvertedVoronoiCell) (Voronoi3DInterface* this_);
	template <typename IMPL> void Init()
	{
		_Voronoi3DInterface_Free = &IMPL::_Voronoi3DInterface_Free;
		_Voronoi3DInterface_Alloc = &IMPL::_Voronoi3DInterface_Alloc;
		_Voronoi3DInterface_Init = &IMPL::_Voronoi3DInterface_Init;
		_Voronoi3DInterface_CopyFrom = &IMPL::_Voronoi3DInterface_CopyFrom;
		_Voronoi3DInterface_IsReadyButPendingChanges = &IMPL::_Voronoi3DInterface_IsReadyButPendingChanges;
		_Voronoi3DInterface_IsReady = &IMPL::_Voronoi3DInterface_IsReady;
		_Voronoi3DInterface_SetPoints = &IMPL::_Voronoi3DInterface_SetPoints;
		_Voronoi3DInterface_AddPoint = &IMPL::_Voronoi3DInterface_AddPoint;
		_Voronoi3DInterface_AddPoints = &IMPL::_Voronoi3DInterface_AddPoints;
		_Voronoi3DInterface_CalcCells = &IMPL::_Voronoi3DInterface_CalcCells;
		_Voronoi3DInterface_CalcTetrahedralization = &IMPL::_Voronoi3DInterface_CalcTetrahedralization;
		_Voronoi3DInterface_SetForClipping = &IMPL::_Voronoi3DInterface_SetForClipping;
		_Voronoi3DInterface_GetCellCount = &IMPL::_Voronoi3DInterface_GetCellCount;
		_Voronoi3DInterface_GetVoronoiPointPositions = &IMPL::_Voronoi3DInterface_GetVoronoiPointPositions;
		_Voronoi3DInterface_GetInputPoints = &IMPL::_Voronoi3DInterface_GetInputPoints;
		_Voronoi3DInterface_GetBorderCellFlags = &IMPL::_Voronoi3DInterface_GetBorderCellFlags;
		_Voronoi3DInterface_GetCellDataStructure = &IMPL::_Voronoi3DInterface_GetCellDataStructure;
		_Voronoi3DInterface_GetCellHasVolume = &IMPL::_Voronoi3DInterface_GetCellHasVolume;
		_Voronoi3DInterface_ScaleCell = &IMPL::_Voronoi3DInterface_ScaleCell;
		_Voronoi3DInterface_ScaleAllCells = &IMPL::_Voronoi3DInterface_ScaleAllCells;
		_Voronoi3DInterface_GetDelaunayTetrizer = &IMPL::_Voronoi3DInterface_GetDelaunayTetrizer;
		_Voronoi3DInterface_Flush = &IMPL::_Voronoi3DInterface_Flush;
		_Voronoi3DInterface_SetCellFuseGroup = &IMPL::_Voronoi3DInterface_SetCellFuseGroup;
		_Voronoi3DInterface_FuseCells = &IMPL::_Voronoi3DInterface_FuseCells;
		_Voronoi3DInterface_CreateInvertedVoronoiCell = &IMPL::_Voronoi3DInterface_CreateInvertedVoronoiCell;
	}
};

struct Voronoi3DInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _Voronoi3DInterface_Free(const Voronoi3DInterface* object) { return C::Free(object); }
		static Voronoi3DInterface* _Voronoi3DInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> _Voronoi3DInterface_Init(Voronoi3DInterface* this_, const Range<Vector>& workSpace) { return C::Get(this_)->Init(workSpace); }
		static Result<void> _Voronoi3DInterface_CopyFrom(Voronoi3DInterface* this_, const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->CopyFrom(src, resizeFlags); }
		static Bool _Voronoi3DInterface_IsReadyButPendingChanges(Voronoi3DInterface* this_) { return C::Get(this_)->IsReadyButPendingChanges(); }
		static Bool _Voronoi3DInterface_IsReady(Voronoi3DInterface* this_) { return C::Get(this_)->IsReady(); }
		static Result<void> _Voronoi3DInterface_SetPoints(Voronoi3DInterface* this_, const BaseArray<Vector>& points) { return C::Get(this_)->SetPoints(points); }
		static Result<void> _Voronoi3DInterface_AddPoint(Voronoi3DInterface* this_, const Vector& pointIn) { return C::Get(this_)->AddPoint(pointIn); }
		static Result<void> _Voronoi3DInterface_AddPoints(Voronoi3DInterface* this_, const BaseArray<Vector>& points) { return C::Get(this_)->AddPoints(points); }
		static Result<void> _Voronoi3DInterface_CalcCells(Voronoi3DInterface* this_) { return C::Get(this_)->CalcCells(); }
		static Result<void> _Voronoi3DInterface_CalcTetrahedralization(Voronoi3DInterface* this_) { return C::Get(this_)->CalcTetrahedralization(); }
		static void _Voronoi3DInterface_SetForClipping(Voronoi3DInterface* this_, Bool clipping) { return C::Get(this_)->SetForClipping(clipping); }
		static Int _Voronoi3DInterface_GetCellCount(Voronoi3DInterface* this_) { return C::Get(this_)->GetCellCount(); }
		static const BaseArray<Vector>& _Voronoi3DInterface_GetVoronoiPointPositions(const Voronoi3DInterface* this_) { return C::Get(this_)->GetVoronoiPointPositions(); }
		static const BaseArray<Vector>& _Voronoi3DInterface_GetInputPoints(const Voronoi3DInterface* this_) { return C::Get(this_)->GetInputPoints(); }
		static ResultRef<BaseArray<Bool>> _Voronoi3DInterface_GetBorderCellFlags(Voronoi3DInterface* this_) { return C::Get(this_)->GetBorderCellFlags(); }
		static ResultRef<BaseArray<CellData>> _Voronoi3DInterface_GetCellDataStructure(Voronoi3DInterface* this_) { return C::Get(this_)->GetCellDataStructure(); }
		static ResultRef<BaseArray<Char>> _Voronoi3DInterface_GetCellHasVolume(Voronoi3DInterface* this_) { return C::Get(this_)->GetCellHasVolume(); }
		static Result<void> _Voronoi3DInterface_ScaleCell(Voronoi3DInterface* this_, Int cellIndex, Float scaleValue) { return C::Get(this_)->ScaleCell(cellIndex, scaleValue); }
		static Result<void> _Voronoi3DInterface_ScaleAllCells(Voronoi3DInterface* this_, Float scaleValue) { return C::Get(this_)->ScaleAllCells(scaleValue); }
		static ResultRef<Delaunay3DRef> _Voronoi3DInterface_GetDelaunayTetrizer(Voronoi3DInterface* this_) { return C::Get(this_)->GetDelaunayTetrizer(); }
		static void _Voronoi3DInterface_Flush(Voronoi3DInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<void> _Voronoi3DInterface_SetCellFuseGroup(Voronoi3DInterface* this_, BaseArray<Int>& fuseIndices) { return C::Get(this_)->SetCellFuseGroup(fuseIndices); }
		static Result<void> _Voronoi3DInterface_FuseCells(Voronoi3DInterface* this_, BaseArray<Pair<Int, Int>>& joinList) { return C::Get(this_)->FuseCells(joinList); }
		static Result<void> _Voronoi3DInterface_CreateInvertedVoronoiCell(Voronoi3DInterface* this_) { return C::Get(this_)->CreateInvertedVoronoiCell(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Free(const Voronoi3DInterface* object) -> void
{
	return MTable::_instance._Voronoi3DInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Voronoi3DInterface*
{
	return MTable::_instance._Voronoi3DInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Init(const Range<Vector>& workSpace) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_Init(this, workSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_CopyFrom(this, src, resizeFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::IsReadyButPendingChanges() -> Bool
{
	return MTable::_instance._Voronoi3DInterface_IsReadyButPendingChanges(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::IsReady() -> Bool
{
	return MTable::_instance._Voronoi3DInterface_IsReady(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetPoints(const BaseArray<Vector>& points) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_SetPoints(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::AddPoint(const Vector& pointIn) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_AddPoint(this, pointIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::AddPoints(const BaseArray<Vector>& points) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_AddPoints(this, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CalcCells() -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_CalcCells(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CalcTetrahedralization() -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_CalcTetrahedralization(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetForClipping(Bool clipping) -> void
{
	return MTable::_instance._Voronoi3DInterface_SetForClipping(this, clipping);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellCount() -> Int
{
	return MTable::_instance._Voronoi3DInterface_GetCellCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetVoronoiPointPositions() const -> const BaseArray<Vector>&
{
	return MTable::_instance._Voronoi3DInterface_GetVoronoiPointPositions(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetInputPoints() const -> const BaseArray<Vector>&
{
	return MTable::_instance._Voronoi3DInterface_GetInputPoints(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetBorderCellFlags() -> ResultRef<BaseArray<Bool>>
{
	return MTable::_instance._Voronoi3DInterface_GetBorderCellFlags(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellDataStructure() -> ResultRef<BaseArray<CellData>>
{
	return MTable::_instance._Voronoi3DInterface_GetCellDataStructure(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellHasVolume() -> ResultRef<BaseArray<Char>>
{
	return MTable::_instance._Voronoi3DInterface_GetCellHasVolume(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::ScaleCell(Int cellIndex, Float scaleValue) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_ScaleCell(this, cellIndex, scaleValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::ScaleAllCells(Float scaleValue) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_ScaleAllCells(this, scaleValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetDelaunayTetrizer() -> ResultRef<Delaunay3DRef>
{
	return MTable::_instance._Voronoi3DInterface_GetDelaunayTetrizer(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Flush() -> void
{
	return MTable::_instance._Voronoi3DInterface_Flush(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetCellFuseGroup(BaseArray<Int>& fuseIndices) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_SetCellFuseGroup(this, fuseIndices);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::FuseCells(BaseArray<Pair<Int, Int>>& joinList) -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_FuseCells(this, joinList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CreateInvertedVoronoiCell() -> Result<void>
{
	return MTable::_instance._Voronoi3DInterface_CreateInvertedVoronoiCell(this);
}

auto Voronoi3DInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Voronoi3DRef>
{
	Voronoi3DInterface* res_ = Voronoi3DInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Voronoi3DRef(maxon::ForwardResultPtr<Voronoi3DInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const Range<Vector>& workSpace) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_Init(o_, workSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_CopyFrom(o_, src, resizeFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::IsReadyButPendingChanges() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._Voronoi3DInterface_IsReadyButPendingChanges(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::IsReady() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._Voronoi3DInterface_IsReady(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPoints(const BaseArray<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_SetPoints(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::AddPoint(const Vector& pointIn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_AddPoint(o_, pointIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::AddPoints(const BaseArray<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_AddPoints(o_, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CalcCells() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_CalcCells(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CalcTetrahedralization() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_CalcTetrahedralization(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::SetForClipping(Bool clipping) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._Voronoi3DInterface_SetForClipping(o_, clipping);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCellCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return 0; } 
	return (MTable::_instance._Voronoi3DInterface_GetCellCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetVoronoiPointPositions() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Voronoi3DInterface* o_ = (const Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Voronoi3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetVoronoiPointPositions(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInputPoints() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Voronoi3DInterface* o_ = (const Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Voronoi3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetInputPoints(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetBorderCellFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Bool>&>, ResultRef<BaseArray<Bool>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Bool>&>, ResultRef<BaseArray<Bool>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Bool>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetBorderCellFlags(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCellDataStructure() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<CellData>&>, ResultRef<BaseArray<CellData>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<CellData>&>, ResultRef<BaseArray<CellData>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<CellData>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetCellDataStructure(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetCellHasVolume() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Char>&>, ResultRef<BaseArray<Char>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Char>&>, ResultRef<BaseArray<Char>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Char>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetCellHasVolume(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::ScaleCell(Int cellIndex, Float scaleValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_ScaleCell(o_, cellIndex, scaleValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::ScaleAllCells(Float scaleValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_ScaleAllCells(o_, scaleValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::GetDelaunayTetrizer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Delaunay3DRef&>, ResultRef<Delaunay3DRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Delaunay3DRef&>, ResultRef<Delaunay3DRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<Delaunay3DRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._Voronoi3DInterface_GetDelaunayTetrizer(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._Voronoi3DInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::SetCellFuseGroup(BaseArray<Int>& fuseIndices) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_SetCellFuseGroup(o_, fuseIndices));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::FuseCells(BaseArray<Pair<Int, Int>>& joinList) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_FuseCells(o_, joinList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ReferenceFunctionsImpl<S>::CreateInvertedVoronoiCell() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._Voronoi3DInterface_CreateInvertedVoronoiCell(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Voronoi3DInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Voronoi3DInterface() { new (s_ui_maxon_Voronoi3DInterface) maxon::EntityUse(Voronoi3DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/voronoi3d.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Voronoi3DInterface(Voronoi3DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/voronoi3d.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

