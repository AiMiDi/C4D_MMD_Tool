
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
	PRIVATE_MAXON_SF_POINTER(Voronoi3DInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const Voronoi3DInterface* object);
	PRIVATE_MAXON_SF_POINTER(Voronoi3DInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (Voronoi3DInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_Init, Init, false, Voronoi3DInterface,, (Result<void>), const Range<Vector>& workSpace);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_CopyFrom, CopyFrom, false, Voronoi3DInterface,, (Result<void>), const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_IsReadyButPendingChanges, IsReadyButPendingChanges, false, Voronoi3DInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_IsReady, IsReady, false, Voronoi3DInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_SetPoints, SetPoints, false, Voronoi3DInterface,, (Result<void>), const BaseArray<Vector>& points);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_AddPoint, AddPoint, false, Voronoi3DInterface,, (Result<void>), const Vector& pointIn);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_AddPoints, AddPoints, false, Voronoi3DInterface,, (Result<void>), const BaseArray<Vector>& points);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_CalcCells, CalcCells, false, Voronoi3DInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_CalcTetrahedralization, CalcTetrahedralization, false, Voronoi3DInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_SetForClipping, SetForClipping, false, Voronoi3DInterface,, (void), Bool clipping);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetCellCount, GetCellCount, false, Voronoi3DInterface,, (Int));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetVoronoiPointPositions, GetVoronoiPointPositions, false, Voronoi3DInterface, const, (const BaseArray<Vector>&));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetInputPoints, GetInputPoints, false, Voronoi3DInterface, const, (const BaseArray<Vector>&));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetBorderCellFlags, GetBorderCellFlags, false, Voronoi3DInterface,, (ResultRef<BaseArray<Bool>>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetCellDataStructure, GetCellDataStructure, false, Voronoi3DInterface,, (ResultRef<BaseArray<CellData>>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetCellHasVolume, GetCellHasVolume, false, Voronoi3DInterface,, (ResultRef<BaseArray<Char>>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_ScaleCell, ScaleCell, false, Voronoi3DInterface,, (Result<void>), Int cellIndex, Float scaleValue);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_ScaleAllCells, ScaleAllCells, false, Voronoi3DInterface,, (Result<void>), Float scaleValue);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_GetDelaunayTetrizer, GetDelaunayTetrizer, false, Voronoi3DInterface,, (ResultRef<Delaunay3DRef>));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_Flush, Flush, false, Voronoi3DInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_SetCellFuseGroup, SetCellFuseGroup, false, Voronoi3DInterface,, (Result<void>), BaseArray<Int>& fuseIndices);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_FuseCells, FuseCells, false, Voronoi3DInterface,, (Result<void>), BaseArray<Pair<Int, Int>>& joinList);
	PRIVATE_MAXON_MF_POINTER(Voronoi3DInterface_CreateInvertedVoronoiCell, CreateInvertedVoronoiCell, false, Voronoi3DInterface,, (Result<void>));
	template <typename IMPL> void Init()
	{
		Voronoi3DInterface_Free = Voronoi3DInterface_Free_GetPtr<IMPL>(true);
		Voronoi3DInterface_Alloc = Voronoi3DInterface_Alloc_GetPtr<IMPL>(true);
		Voronoi3DInterface_Init = Voronoi3DInterface_Init_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_CopyFrom = Voronoi3DInterface_CopyFrom_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_IsReadyButPendingChanges = Voronoi3DInterface_IsReadyButPendingChanges_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_IsReady = Voronoi3DInterface_IsReady_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_SetPoints = Voronoi3DInterface_SetPoints_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_AddPoint = Voronoi3DInterface_AddPoint_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_AddPoints = Voronoi3DInterface_AddPoints_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_CalcCells = Voronoi3DInterface_CalcCells_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_CalcTetrahedralization = Voronoi3DInterface_CalcTetrahedralization_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_SetForClipping = Voronoi3DInterface_SetForClipping_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetCellCount = Voronoi3DInterface_GetCellCount_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetVoronoiPointPositions = Voronoi3DInterface_GetVoronoiPointPositions_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetInputPoints = Voronoi3DInterface_GetInputPoints_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetBorderCellFlags = Voronoi3DInterface_GetBorderCellFlags_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetCellDataStructure = Voronoi3DInterface_GetCellDataStructure_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetCellHasVolume = Voronoi3DInterface_GetCellHasVolume_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_ScaleCell = Voronoi3DInterface_ScaleCell_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_ScaleAllCells = Voronoi3DInterface_ScaleAllCells_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_GetDelaunayTetrizer = Voronoi3DInterface_GetDelaunayTetrizer_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_Flush = Voronoi3DInterface_Flush_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_SetCellFuseGroup = Voronoi3DInterface_SetCellFuseGroup_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_FuseCells = Voronoi3DInterface_FuseCells_GetPtr<IMPL>(0, true).first;
		Voronoi3DInterface_CreateInvertedVoronoiCell = Voronoi3DInterface_CreateInvertedVoronoiCell_GetPtr<IMPL>(0, true).first;
	}
};

struct Voronoi3DInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void Voronoi3DInterface_Free(const Voronoi3DInterface* object) { return C::Free(object); }
		static Voronoi3DInterface* Voronoi3DInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_Init, Voronoi3DInterface,, (Result<void>), const Range<Vector>& workSpace) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->Init(workSpace); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_CopyFrom, Voronoi3DInterface,, (Result<void>), const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->CopyFrom(src, resizeFlags); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_IsReadyButPendingChanges, Voronoi3DInterface,, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->IsReadyButPendingChanges(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_IsReady, Voronoi3DInterface,, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->IsReady(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_SetPoints, Voronoi3DInterface,, (Result<void>), const BaseArray<Vector>& points) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->SetPoints(points); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_AddPoint, Voronoi3DInterface,, (Result<void>), const Vector& pointIn) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->AddPoint(pointIn); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_AddPoints, Voronoi3DInterface,, (Result<void>), const BaseArray<Vector>& points) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->AddPoints(points); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_CalcCells, Voronoi3DInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->CalcCells(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_CalcTetrahedralization, Voronoi3DInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->CalcTetrahedralization(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_SetForClipping, Voronoi3DInterface,, (void), Bool clipping) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->SetForClipping(clipping); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetCellCount, Voronoi3DInterface,, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->GetCellCount(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetVoronoiPointPositions, Voronoi3DInterface, const, (const BaseArray<Vector>&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Voronoi3DInterface))->GetVoronoiPointPositions(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetInputPoints, Voronoi3DInterface, const, (const BaseArray<Vector>&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Voronoi3DInterface))->GetInputPoints(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetBorderCellFlags, Voronoi3DInterface,, (ResultRef<BaseArray<Bool>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->GetBorderCellFlags(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetCellDataStructure, Voronoi3DInterface,, (ResultRef<BaseArray<CellData>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->GetCellDataStructure(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetCellHasVolume, Voronoi3DInterface,, (ResultRef<BaseArray<Char>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->GetCellHasVolume(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_ScaleCell, Voronoi3DInterface,, (Result<void>), Int cellIndex, Float scaleValue) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->ScaleCell(cellIndex, scaleValue); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_ScaleAllCells, Voronoi3DInterface,, (Result<void>), Float scaleValue) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->ScaleAllCells(scaleValue); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_GetDelaunayTetrizer, Voronoi3DInterface,, (ResultRef<Delaunay3DRef>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->GetDelaunayTetrizer(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_Flush, Voronoi3DInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_SetCellFuseGroup, Voronoi3DInterface,, (Result<void>), BaseArray<Int>& fuseIndices) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->SetCellFuseGroup(fuseIndices); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_FuseCells, Voronoi3DInterface,, (Result<void>), BaseArray<Pair<Int, Int>>& joinList) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->FuseCells(joinList); }
		PRIVATE_MAXON_MF_WRAPPER(Voronoi3DInterface_CreateInvertedVoronoiCell, Voronoi3DInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(Voronoi3DInterface))->CreateInvertedVoronoiCell(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Free(const Voronoi3DInterface* object) -> void
{
	return MTable::_instance.Voronoi3DInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Voronoi3DInterface*
{
	return MTable::_instance.Voronoi3DInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Init(const Range<Vector>& workSpace) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_Init, workSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_CopyFrom, src, resizeFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::IsReadyButPendingChanges() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_IsReadyButPendingChanges);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::IsReady() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_IsReady);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetPoints(const BaseArray<Vector>& points) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_SetPoints, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::AddPoint(const Vector& pointIn) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_AddPoint, pointIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::AddPoints(const BaseArray<Vector>& points) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_AddPoints, points);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CalcCells() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_CalcCells);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CalcTetrahedralization() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_CalcTetrahedralization);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetForClipping(Bool clipping) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_SetForClipping, clipping);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellCount() -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetCellCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetVoronoiPointPositions() const -> const BaseArray<Vector>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetVoronoiPointPositions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetInputPoints() const -> const BaseArray<Vector>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetInputPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetBorderCellFlags() -> ResultRef<BaseArray<Bool>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetBorderCellFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellDataStructure() -> ResultRef<BaseArray<CellData>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetCellDataStructure);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetCellHasVolume() -> ResultRef<BaseArray<Char>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetCellHasVolume);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::ScaleCell(Int cellIndex, Float scaleValue) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_ScaleCell, cellIndex, scaleValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::ScaleAllCells(Float scaleValue) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_ScaleAllCells, scaleValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::GetDelaunayTetrizer() -> ResultRef<Delaunay3DRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_GetDelaunayTetrizer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_Flush);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::SetCellFuseGroup(BaseArray<Int>& fuseIndices) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_SetCellFuseGroup, fuseIndices);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::FuseCells(BaseArray<Pair<Int, Int>>& joinList) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_FuseCells, joinList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::CreateInvertedVoronoiCell() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Voronoi3DInterface_CreateInvertedVoronoiCell);
}

auto Voronoi3DInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Voronoi3DRef>
{
	Voronoi3DInterface* res_ = Voronoi3DInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Voronoi3DRef(maxon::ForwardResultPtr<Voronoi3DInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::Init(const Range<Vector>& workSpace) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_Init, workSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_CopyFrom, src, resizeFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::IsReadyButPendingChanges() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_IsReadyButPendingChanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::IsReady() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_IsReady));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::SetPoints(const BaseArray<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_SetPoints, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::AddPoint(const Vector& pointIn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_AddPoint, pointIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::AddPoints(const BaseArray<Vector>& points) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_AddPoints, points));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::CalcCells() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_CalcCells));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::CalcTetrahedralization() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_CalcTetrahedralization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::SetForClipping(Bool clipping) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_SetForClipping, clipping);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::GetCellCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetCellCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ConstFn<S>::GetVoronoiPointPositions() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const Voronoi3DInterface* o_ = (const Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = Voronoi3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetVoronoiPointPositions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::ConstFn<S>::GetInputPoints() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const Voronoi3DInterface* o_ = (const Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = Voronoi3DInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetInputPoints));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::GetBorderCellFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Bool>&>, ResultRef<BaseArray<Bool>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Bool>&>, ResultRef<BaseArray<Bool>>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Bool>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetBorderCellFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::GetCellDataStructure() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<CellData>&>, ResultRef<BaseArray<CellData>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<CellData>&>, ResultRef<BaseArray<CellData>>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<CellData>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetCellDataStructure));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::GetCellHasVolume() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Char>&>, ResultRef<BaseArray<Char>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Char>&>, ResultRef<BaseArray<Char>>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Char>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetCellHasVolume));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::ScaleCell(Int cellIndex, Float scaleValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_ScaleCell, cellIndex, scaleValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::ScaleAllCells(Float scaleValue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_ScaleAllCells, scaleValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::GetDelaunayTetrizer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Delaunay3DRef&>, ResultRef<Delaunay3DRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Delaunay3DRef&>, ResultRef<Delaunay3DRef>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<ResultRef<Delaunay3DRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_GetDelaunayTetrizer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::SetCellFuseGroup(BaseArray<Int>& fuseIndices) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_SetCellFuseGroup, fuseIndices));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::FuseCells(BaseArray<Pair<Int, Int>>& joinList) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_FuseCells, joinList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Voronoi3DInterface::Hxx1::Fn<S>::CreateInvertedVoronoiCell() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); Voronoi3DInterface* o_ = (Voronoi3DInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Voronoi3DInterface_CreateInvertedVoronoiCell));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_voronoi3d)
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

