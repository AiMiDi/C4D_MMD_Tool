#if 1
namespace maxon
{
	const maxon::Char* const Voronoi3DInterface::MTable::_ids = 
		"Free@3ed52f761d822a62\0" // void Free(const Voronoi3DInterface* object)
		"Alloc@2c75823f574c7c5b\0" // Voronoi3DInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@d5ab15d4fd51c9b8\0" // Result<void> Init(const Range<Vector>& workSpace)
		"CopyFrom@bf6f7e870bd54943\0" // Result<void> CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags)
		"IsReadyButPendingChanges@d7a8c99431e20a5a\0" // Bool IsReadyButPendingChanges()
		"IsReady@d7a8c99431e20a5a\0" // Bool IsReady()
		"SetPoints@af2c4064cd0711a1\0" // Result<void> SetPoints(const BaseArray<Vector>& points)
		"AddPoint@ab248dd1767f3b07\0" // Result<void> AddPoint(const Vector& pointIn)
		"AddPoints@af2c4064cd0711a1\0" // Result<void> AddPoints(const BaseArray<Vector>& points)
		"CalcCells@3008090429c5a175\0" // Result<void> CalcCells()
		"CalcTetrahedralization@3008090429c5a175\0" // Result<void> CalcTetrahedralization()
		"SetForClipping@add9409250097f0c\0" // void SetForClipping(Bool clipping)
		"GetCellCount@6286b762fbbe6ae7\0" // Int GetCellCount()
		"GetVoronoiPointPositions@4ba72e30410c4924\0" // const BaseArray<Vector>& GetVoronoiPointPositions() const
		"GetInputPoints@4ba72e30410c4924\0" // const BaseArray<Vector>& GetInputPoints() const
		"GetBorderCellFlags@ad541f63a476bc9a\0" // ResultRef<BaseArray<Bool>> GetBorderCellFlags()
		"GetCellDataStructure@955c023b97a15932\0" // ResultRef<BaseArray<CellData>> GetCellDataStructure()
		"GetCellHasVolume@e268974e155b2ba\0" // ResultRef<BaseArray<Char>> GetCellHasVolume()
		"ScaleCell@b1e4a8f684988fec\0" // Result<void> ScaleCell(Int cellIndex, Float scaleValue)
		"ScaleAllCells@208bad147bb17895\0" // Result<void> ScaleAllCells(Float scaleValue)
		"GetDelaunayTetrizer@895751cb87955f75\0" // ResultRef<Delaunay3DRef> GetDelaunayTetrizer()
		"Flush@780cdac8f1a33934\0" // void Flush()
		"SetCellFuseGroup@be46b83b86ac7428\0" // Result<void> SetCellFuseGroup(BaseArray<Int>& fuseIndices)
		"FuseCells@2eb852a19873b33f\0" // Result<void> FuseCells(BaseArray<Pair<Int, Int>>& joinList)
		"CreateInvertedVoronoiCell@3008090429c5a175\0" // Result<void> CreateInvertedVoronoiCell()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Voronoi3DInterface::Hxx2::Unresolved : public Voronoi3DInterface
	{
	public:
		static const Unresolved* Get(const Voronoi3DInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Voronoi3DInterface* o) { return (Unresolved*) o; }
		static void Free(const Voronoi3DInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Voronoi3DInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Voronoi3DInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Voronoi3DInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Init(const Range<Vector>& workSpace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->Init(workSpace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->CopyFrom(src, resizeFlags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsReadyButPendingChanges() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->IsReadyButPendingChanges(); return maxon::PrivateLogNullptrError(false);}
		Bool IsReady() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->IsReady(); return maxon::PrivateLogNullptrError(false);}
		Result<void> SetPoints(const BaseArray<Vector>& points) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->SetPoints(points); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> AddPoint(const Vector& pointIn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->AddPoint(pointIn); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> AddPoints(const BaseArray<Vector>& points) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->AddPoints(points); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> CalcCells() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->CalcCells(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> CalcTetrahedralization() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->CalcTetrahedralization(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void SetForClipping(Bool clipping) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->SetForClipping(clipping); return maxon::PrivateLogNullptrError();}
		Int GetCellCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->GetCellCount(); return 0;}
		const BaseArray<Vector>& GetVoronoiPointPositions() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Voronoi3DInterface*) this)->GetVoronoiPointPositions(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const BaseArray<Vector>& GetInputPoints() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Voronoi3DInterface*) this)->GetInputPoints(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ResultRef<BaseArray<Bool>> GetBorderCellFlags() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->GetBorderCellFlags(); return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Bool>>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ResultRef<BaseArray<CellData>> GetCellDataStructure() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->GetCellDataStructure(); return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<CellData>>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ResultRef<BaseArray<Char>> GetCellHasVolume() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->GetCellHasVolume(); return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Char>>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> ScaleCell(Int cellIndex, Float scaleValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->ScaleCell(cellIndex, scaleValue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ScaleAllCells(Float scaleValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->ScaleAllCells(scaleValue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		ResultRef<Delaunay3DRef> GetDelaunayTetrizer() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->GetDelaunayTetrizer(); return maxon::PrivateIncompleteNullReturnValue<ResultRef<Delaunay3DRef>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void Flush() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Voronoi3DInterface*) this)->Flush(); return maxon::PrivateLogNullptrError();}
		Result<void> SetCellFuseGroup(BaseArray<Int>& fuseIndices) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->SetCellFuseGroup(fuseIndices); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> FuseCells(BaseArray<Pair<Int, Int>>& joinList) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->FuseCells(joinList); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> CreateInvertedVoronoiCell() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Voronoi3DInterface*) this)->CreateInvertedVoronoiCell(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Voronoi3DInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Voronoi3DInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<const BaseArray<Vector>&>::value,
		maxon::details::NullReturnType<const BaseArray<Vector>&>::value,
		maxon::details::NullReturnType<ResultRef<BaseArray<Bool>>>::value,
		maxon::details::NullReturnType<ResultRef<BaseArray<CellData>>>::value,
		maxon::details::NullReturnType<ResultRef<BaseArray<Char>>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<ResultRef<Delaunay3DRef>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Voronoi3DInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_Init;
		#else
		tbl->_Voronoi3DInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_CopyFrom = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CopyFrom;
		#else
		tbl->_Voronoi3DInterface_CopyFrom = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CopyFrom;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_IsReadyButPendingChanges = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_IsReadyButPendingChanges;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_IsReady = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_IsReady;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_SetPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_SetPoints;
		#else
		tbl->_Voronoi3DInterface_SetPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_SetPoints;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_AddPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_AddPoint;
		#else
		tbl->_Voronoi3DInterface_AddPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_AddPoint;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_AddPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_AddPoints;
		#else
		tbl->_Voronoi3DInterface_AddPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_AddPoints;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_CalcCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CalcCells;
		#else
		tbl->_Voronoi3DInterface_CalcCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CalcCells;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_CalcTetrahedralization = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CalcTetrahedralization;
		#else
		tbl->_Voronoi3DInterface_CalcTetrahedralization = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CalcTetrahedralization;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_SetForClipping = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_SetForClipping;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_GetCellCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetCellCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Vector>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetVoronoiPointPositions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetVoronoiPointPositions;
		#else
		tbl->_Voronoi3DInterface_GetVoronoiPointPositions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetVoronoiPointPositions;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Vector>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetInputPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetInputPoints;
		#else
		tbl->_Voronoi3DInterface_GetInputPoints = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetInputPoints;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultRef<BaseArray<Bool>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetBorderCellFlags = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetBorderCellFlags;
		#else
		tbl->_Voronoi3DInterface_GetBorderCellFlags = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetBorderCellFlags;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultRef<BaseArray<CellData>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetCellDataStructure = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetCellDataStructure;
		#else
		tbl->_Voronoi3DInterface_GetCellDataStructure = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetCellDataStructure;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultRef<BaseArray<Char>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetCellHasVolume = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetCellHasVolume;
		#else
		tbl->_Voronoi3DInterface_GetCellHasVolume = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetCellHasVolume;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_ScaleCell = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_ScaleCell;
		#else
		tbl->_Voronoi3DInterface_ScaleCell = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_ScaleCell;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_ScaleAllCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_ScaleAllCells;
		#else
		tbl->_Voronoi3DInterface_ScaleAllCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_ScaleAllCells;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultRef<Delaunay3DRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_GetDelaunayTetrizer = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetDelaunayTetrizer;
		#else
		tbl->_Voronoi3DInterface_GetDelaunayTetrizer = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_GetDelaunayTetrizer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Voronoi3DInterface_Flush = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_Flush;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_SetCellFuseGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_SetCellFuseGroup;
		#else
		tbl->_Voronoi3DInterface_SetCellFuseGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_SetCellFuseGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_FuseCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_FuseCells;
		#else
		tbl->_Voronoi3DInterface_FuseCells = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_FuseCells;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Voronoi3DInterface_CreateInvertedVoronoiCell = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CreateInvertedVoronoiCell;
		#else
		tbl->_Voronoi3DInterface_CreateInvertedVoronoiCell = &Hxx2::Wrapper<Hxx2::Unresolved>::_Voronoi3DInterface_CreateInvertedVoronoiCell;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Voronoi3DInterface, "net.maxon.interface.voronoi3d", nullptr);
	template <typename DUMMY> maxon::Int Voronoi3DInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ResultRef<BaseArray<Bool>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultRef<BaseArray<CellData>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultRef<BaseArray<Char>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultRef<Delaunay3DRef>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<Vector>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_voronoi3d(0
	| maxon::Voronoi3DInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
