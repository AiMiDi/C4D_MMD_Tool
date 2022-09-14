#if 1
namespace maxon
{
	const maxon::Char* const Delaunay3DInterface::MTable::_ids = 
		"Free@d948c28b42c59b21\0" // void Free(const Delaunay3DInterface* object)
		"Alloc@b619499dbda94252\0" // Delaunay3DInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"CopyFrom@6ebeec628295cc54\0" // Result<void> CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags)
		"Init@d5ab15d4fd51c9b8\0" // Result<void> Init(const Range<Vector>& workSpace)
		"CalculateDelaunayTetrahedralization@3008090429c5a175\0" // Result<void> CalculateDelaunayTetrahedralization()
		"IsInitialized@d7a8c99431e20a5a\0" // Bool IsInitialized()
		"AddPointsIntoTetrahedralization@af2c4064cd0711a1\0" // Result<void> AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn)
		"AddPointIntoTetrahedralization@ab248dd1767f3b07\0" // Result<void> AddPointIntoTetrahedralization(const Vector& newPointIn)
		"GetTetrahedrons@d19253319f43864b\0" // const BaseArray<Tetrahedron>& GetTetrahedrons(Int& arrayCount, Int& pointCount) const
		"GetTetrahedrons@ec24e2c8a23b86b\0" // const BaseArray<Tetrahedron>& GetTetrahedrons() const
		"GetPointsToTetConnections@106cbd3e2fa5cf53\0" // const BaseArray<Int32>& GetPointsToTetConnections() const
		"GetPoints@4ba72e30410c4924\0" // const BaseArray<Vector>& GetPoints() const
		"GetPointsWrite@7b873f330bc11c8f\0" // ResultRef<BaseArray<Vector>> GetPointsWrite()
		"GetTetrahedronCount@7d0e6f3d29c239e7\0" // Int GetTetrahedronCount() const
		"GetPointCount@7d0e6f3d29c239e7\0" // Int GetPointCount() const
		"Reset@3008090429c5a175\0" // Result<void> Reset()
		"OrientDet@6df9291b9dc382b\0" // Float OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint)
		"Flush@780cdac8f1a33934\0" // void Flush()
		"FindTetIndexContainingPoint@4b53588fad6eec99\0" // Result<Bool> FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const
		"FindTetContainingPoint@abdb50583e3ca2b9\0" // Result<Bool> FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Delaunay3DInterface::Hxx2::Unresolved : public Delaunay3DInterface
	{
	public:
		static const Unresolved* Get(const Delaunay3DInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Delaunay3DInterface* o) { return (Unresolved*) o; }
		static void Free(const Delaunay3DInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Delaunay3DInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Delaunay3DInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Delaunay3DInterface::Alloc(allocLocation); return nullptr;}
		Result<void> CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->CopyFrom(src, resizeFlags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Init(const Range<Vector>& workSpace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->Init(workSpace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> CalculateDelaunayTetrahedralization() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->CalculateDelaunayTetrahedralization(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsInitialized() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Delaunay3DInterface*) this)->IsInitialized(); return maxon::PrivateLogNullptrError(false);}
		Result<void> AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->AddPointsIntoTetrahedralization(newPointsIn); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> AddPointIntoTetrahedralization(const Vector& newPointIn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->AddPointIntoTetrahedralization(newPointIn); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const BaseArray<Tetrahedron>& GetTetrahedrons(Int& arrayCount, Int& pointCount) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetTetrahedrons(arrayCount, pointCount); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Tetrahedron>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const BaseArray<Tetrahedron>& GetTetrahedrons() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetTetrahedrons(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Tetrahedron>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const BaseArray<Int32>& GetPointsToTetConnections() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetPointsToTetConnections(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Int32>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const BaseArray<Vector>& GetPoints() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetPoints(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<Vector>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ResultRef<BaseArray<Vector>> GetPointsWrite() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Delaunay3DInterface*) this)->GetPointsWrite(); return maxon::PrivateIncompleteNullReturnValue<ResultRef<BaseArray<Vector>>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetTetrahedronCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetTetrahedronCount(); return 0;}
		Int GetPointCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Delaunay3DInterface*) this)->GetPointCount(); return 0;}
		Result<void> Reset() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((Delaunay3DInterface*) this)->Reset(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Float OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Delaunay3DInterface::OrientDet(planePointA, planePointB, planePointC, testPoint); return 0;}
		void Flush() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((Delaunay3DInterface*) this)->Flush(); return maxon::PrivateLogNullptrError();}
		Result<Bool> FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Delaunay3DInterface*) this)->FindTetIndexContainingPoint(point, foundTetIndex, onFace1, onFace2); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Delaunay3DInterface*) this)->FindTetContainingPoint(point, foundTetIndex); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Delaunay3DInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Delaunay3DInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const BaseArray<Tetrahedron>&>::value,
		maxon::details::NullReturnType<const BaseArray<Tetrahedron>&>::value,
		maxon::details::NullReturnType<const BaseArray<Int32>&>::value,
		maxon::details::NullReturnType<const BaseArray<Vector>&>::value,
		maxon::details::NullReturnType<ResultRef<BaseArray<Vector>>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Delaunay3DInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_CopyFrom = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_CopyFrom), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_CopyFrom);
		#else
		tbl->Delaunay3DInterface_CopyFrom = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_CopyFrom), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_CopyFrom);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Init);
		#else
		tbl->Delaunay3DInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_CalculateDelaunayTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_CalculateDelaunayTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_CalculateDelaunayTetrahedralization);
		#else
		tbl->Delaunay3DInterface_CalculateDelaunayTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_CalculateDelaunayTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_CalculateDelaunayTetrahedralization);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_IsInitialized = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_IsInitialized), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_IsInitialized);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_AddPointsIntoTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_AddPointsIntoTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_AddPointsIntoTetrahedralization);
		#else
		tbl->Delaunay3DInterface_AddPointsIntoTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_AddPointsIntoTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_AddPointsIntoTetrahedralization);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_AddPointIntoTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_AddPointIntoTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_AddPointIntoTetrahedralization);
		#else
		tbl->Delaunay3DInterface_AddPointIntoTetrahedralization = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_AddPointIntoTetrahedralization), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_AddPointIntoTetrahedralization);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Tetrahedron>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_GetTetrahedrons = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetTetrahedrons), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetTetrahedrons);
		#else
		tbl->Delaunay3DInterface_GetTetrahedrons = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetTetrahedrons), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetTetrahedrons);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Tetrahedron>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_GetTetrahedrons_1 = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetTetrahedrons_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetTetrahedrons_1);
		#else
		tbl->Delaunay3DInterface_GetTetrahedrons_1 = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetTetrahedrons_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetTetrahedrons_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Int32>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_GetPointsToTetConnections = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPointsToTetConnections), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPointsToTetConnections);
		#else
		tbl->Delaunay3DInterface_GetPointsToTetConnections = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPointsToTetConnections), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPointsToTetConnections);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<Vector>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_GetPoints = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPoints), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPoints);
		#else
		tbl->Delaunay3DInterface_GetPoints = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPoints), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPoints);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultRef<BaseArray<Vector>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_GetPointsWrite = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPointsWrite), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPointsWrite);
		#else
		tbl->Delaunay3DInterface_GetPointsWrite = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPointsWrite), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPointsWrite);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_GetTetrahedronCount = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetTetrahedronCount), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetTetrahedronCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_GetPointCount = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_GetPointCount), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_GetPointCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Reset);
		#else
		tbl->Delaunay3DInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Reset);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_OrientDet = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_OrientDet), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_OrientDet);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Delaunay3DInterface_Flush = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_Flush), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_Flush);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_FindTetIndexContainingPoint = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_FindTetIndexContainingPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_FindTetIndexContainingPoint);
		#else
		tbl->Delaunay3DInterface_FindTetIndexContainingPoint = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_FindTetIndexContainingPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_FindTetIndexContainingPoint);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Delaunay3DInterface_FindTetContainingPoint = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_FindTetContainingPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_FindTetContainingPoint);
		#else
		tbl->Delaunay3DInterface_FindTetContainingPoint = PRIVATE_MAXON_MF_CAST(decltype(Delaunay3DInterface_FindTetContainingPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::Delaunay3DInterface_FindTetContainingPoint);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Delaunay3DInterface, "net.maxon.interface.delaunay3d", nullptr);
	template <typename DUMMY> maxon::Int Delaunay3DInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ResultRef<BaseArray<Vector>>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<Int32>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<Tetrahedron>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<Vector>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_delaunay3d(0
	| maxon::Delaunay3DInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
