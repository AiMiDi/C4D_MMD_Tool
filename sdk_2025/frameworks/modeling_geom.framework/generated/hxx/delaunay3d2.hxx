
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(Delaunay3DInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const Delaunay3DInterface* object);
	PRIVATE_MAXON_SF_POINTER(Delaunay3DInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (Delaunay3DInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_CopyFrom, CopyFrom, false, Delaunay3DInterface,, (Result<void>), const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_Init, Init, false, Delaunay3DInterface,, (Result<void>), const Range<Vector>& workSpace);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_CalculateDelaunayTetrahedralization, CalculateDelaunayTetrahedralization, false, Delaunay3DInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_IsInitialized, IsInitialized, false, Delaunay3DInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_AddPointsIntoTetrahedralization, AddPointsIntoTetrahedralization, false, Delaunay3DInterface,, (Result<void>), const BaseArray<Vector>& newPointsIn);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_AddPointIntoTetrahedralization, AddPointIntoTetrahedralization, false, Delaunay3DInterface,, (Result<void>), const Vector& newPointIn);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetTetrahedrons, GetTetrahedrons, false, Delaunay3DInterface, const, (const BaseArray<Tetrahedron>&), Int& arrayCount, Int& pointCount);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetTetrahedrons_1, GetTetrahedrons, false, Delaunay3DInterface, const, (const BaseArray<Tetrahedron>&));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetPointsToTetConnections, GetPointsToTetConnections, false, Delaunay3DInterface, const, (const BaseArray<Int32>&));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetPoints, GetPoints, false, Delaunay3DInterface, const, (const BaseArray<Vector>&));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetPointsWrite, GetPointsWrite, false, Delaunay3DInterface,, (ResultRef<BaseArray<Vector>>));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetTetrahedronCount, GetTetrahedronCount, false, Delaunay3DInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_GetPointCount, GetPointCount, false, Delaunay3DInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_Reset, Reset, false, Delaunay3DInterface,, (Result<void>));
	PRIVATE_MAXON_SF_POINTER(Delaunay3DInterface_OrientDet, OrientDet, MAXON_EXPAND_VA_ARGS, (Float), const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_Flush, Flush, false, Delaunay3DInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_FindTetIndexContainingPoint, FindTetIndexContainingPoint, false, Delaunay3DInterface, const, (Result<Bool>), const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2);
	PRIVATE_MAXON_MF_POINTER(Delaunay3DInterface_FindTetContainingPoint, FindTetContainingPoint, false, Delaunay3DInterface, const, (Result<Bool>), const Vector& point, Int32& foundTetIndex);
	template <typename IMPL> void Init()
	{
		Delaunay3DInterface_Free = Delaunay3DInterface_Free_GetPtr<IMPL>(true);
		Delaunay3DInterface_Alloc = Delaunay3DInterface_Alloc_GetPtr<IMPL>(true);
		Delaunay3DInterface_CopyFrom = Delaunay3DInterface_CopyFrom_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_Init = Delaunay3DInterface_Init_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_CalculateDelaunayTetrahedralization = Delaunay3DInterface_CalculateDelaunayTetrahedralization_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_IsInitialized = Delaunay3DInterface_IsInitialized_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_AddPointsIntoTetrahedralization = Delaunay3DInterface_AddPointsIntoTetrahedralization_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_AddPointIntoTetrahedralization = Delaunay3DInterface_AddPointIntoTetrahedralization_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetTetrahedrons = Delaunay3DInterface_GetTetrahedrons_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetTetrahedrons_1 = Delaunay3DInterface_GetTetrahedrons_1_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetPointsToTetConnections = Delaunay3DInterface_GetPointsToTetConnections_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetPoints = Delaunay3DInterface_GetPoints_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetPointsWrite = Delaunay3DInterface_GetPointsWrite_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetTetrahedronCount = Delaunay3DInterface_GetTetrahedronCount_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_GetPointCount = Delaunay3DInterface_GetPointCount_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_Reset = Delaunay3DInterface_Reset_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_OrientDet = Delaunay3DInterface_OrientDet_GetPtr<IMPL>(true);
		Delaunay3DInterface_Flush = Delaunay3DInterface_Flush_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_FindTetIndexContainingPoint = Delaunay3DInterface_FindTetIndexContainingPoint_GetPtr<IMPL>(0, true).first;
		Delaunay3DInterface_FindTetContainingPoint = Delaunay3DInterface_FindTetContainingPoint_GetPtr<IMPL>(0, true).first;
	}
};

struct Delaunay3DInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void Delaunay3DInterface_Free(const Delaunay3DInterface* object) { return S::Free(object); }
		static Delaunay3DInterface* Delaunay3DInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_CopyFrom, Delaunay3DInterface,, (Result<void>), const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->CopyFrom(src, resizeFlags); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_Init, Delaunay3DInterface,, (Result<void>), const Range<Vector>& workSpace) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->Init(workSpace); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_CalculateDelaunayTetrahedralization, Delaunay3DInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->CalculateDelaunayTetrahedralization(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_IsInitialized, Delaunay3DInterface,, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->IsInitialized(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_AddPointsIntoTetrahedralization, Delaunay3DInterface,, (Result<void>), const BaseArray<Vector>& newPointsIn) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->AddPointsIntoTetrahedralization(newPointsIn); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_AddPointIntoTetrahedralization, Delaunay3DInterface,, (Result<void>), const Vector& newPointIn) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->AddPointIntoTetrahedralization(newPointIn); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetTetrahedrons, Delaunay3DInterface, const, (const BaseArray<Tetrahedron>&), Int& arrayCount, Int& pointCount) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetTetrahedrons(arrayCount, pointCount); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetTetrahedrons_1, Delaunay3DInterface, const, (const BaseArray<Tetrahedron>&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetTetrahedrons(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetPointsToTetConnections, Delaunay3DInterface, const, (const BaseArray<Int32>&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetPointsToTetConnections(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetPoints, Delaunay3DInterface, const, (const BaseArray<Vector>&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetPoints(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetPointsWrite, Delaunay3DInterface,, (ResultRef<BaseArray<Vector>>)) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->GetPointsWrite(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetTetrahedronCount, Delaunay3DInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetTetrahedronCount(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_GetPointCount, Delaunay3DInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->GetPointCount(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_Reset, Delaunay3DInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->Reset(); }
		static Float Delaunay3DInterface_OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) { return S::OrientDet(planePointA, planePointB, planePointC, testPoint); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_Flush, Delaunay3DInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(Delaunay3DInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_FindTetIndexContainingPoint, Delaunay3DInterface, const, (Result<Bool>), const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->FindTetIndexContainingPoint(point, foundTetIndex, onFace1, onFace2); }
		PRIVATE_MAXON_MF_WRAPPER(Delaunay3DInterface_FindTetContainingPoint, Delaunay3DInterface, const, (Result<Bool>), const Vector& point, Int32& foundTetIndex) { return S::Get(PRIVATE_MAXON_MF_THIS(const Delaunay3DInterface))->FindTetContainingPoint(point, foundTetIndex); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Free(const Delaunay3DInterface* object) -> void
{
	return MTable::_instance.Delaunay3DInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Alloc(const maxon::SourceLocation& allocLocation) -> Delaunay3DInterface*
{
	return MTable::_instance.Delaunay3DInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_CopyFrom, src, resizeFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Init(const Range<Vector>& workSpace) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_Init, workSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::CalculateDelaunayTetrahedralization() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_CalculateDelaunayTetrahedralization);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::IsInitialized() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_IsInitialized);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_AddPointsIntoTetrahedralization, newPointsIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::AddPointIntoTetrahedralization(const Vector& newPointIn) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_AddPointIntoTetrahedralization, newPointIn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedrons(Int& arrayCount, Int& pointCount) const -> const BaseArray<Tetrahedron>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetTetrahedrons, arrayCount, pointCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedrons() const -> const BaseArray<Tetrahedron>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetTetrahedrons_1);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointsToTetConnections() const -> const BaseArray<Int32>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetPointsToTetConnections);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPoints() const -> const BaseArray<Vector>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetPoints);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointsWrite() -> ResultRef<BaseArray<Vector>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetPointsWrite);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetTetrahedronCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetTetrahedronCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::GetPointCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_GetPointCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Reset() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) -> Float
{
	return MTable::_instance.Delaunay3DInterface_OrientDet(planePointA, planePointB, planePointC, testPoint);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_Flush);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_FindTetIndexContainingPoint, point, foundTetIndex, onFace1, onFace2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Delaunay3DInterface_FindTetContainingPoint, point, foundTetIndex);
}

auto Delaunay3DInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Delaunay3DRef>
{
	Delaunay3DInterface* res_ = Delaunay3DInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Delaunay3DRef(maxon::ForwardResultPtr<Delaunay3DInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_CopyFrom, src, resizeFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::Init(const Range<Vector>& workSpace) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_Init, workSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::CalculateDelaunayTetrahedralization() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_CalculateDelaunayTetrahedralization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::IsInitialized() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXNONCONST(, , false, maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_IsInitialized));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_AddPointsIntoTetrahedralization, newPointsIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::AddPointIntoTetrahedralization(const Vector& newPointIn) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_AddPointIntoTetrahedralization, newPointIn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetTetrahedrons(Int& arrayCount, Int& pointCount) const -> HXXADDRET2(const BaseArray<Tetrahedron>&)
{
	HXXRETURN0(HXXADDRET2(const BaseArray<Tetrahedron>&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const BaseArray<Tetrahedron>&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetTetrahedrons, arrayCount, pointCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetTetrahedrons() const -> HXXADDRET2(const BaseArray<Tetrahedron>&)
{
	HXXRETURN0(HXXADDRET2(const BaseArray<Tetrahedron>&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const BaseArray<Tetrahedron>&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetTetrahedrons_1));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetPointsToTetConnections() const -> HXXADDRET2(const BaseArray<Int32>&)
{
	HXXRETURN0(HXXADDRET2(const BaseArray<Int32>&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const BaseArray<Int32>&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetPointsToTetConnections));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetPoints() const -> HXXADDRET2(const BaseArray<Vector>&)
{
	HXXRETURN0(HXXADDRET2(const BaseArray<Vector>&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const BaseArray<Vector>&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetPoints));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::GetPointsWrite() const -> HXXADDRET2(ResultRef<BaseArray<Vector>>)
{
	HXXRETURN0(HXXADDRET2(ResultRef<BaseArray<Vector>>)); HXXRES; HXXNONCONST(, , false, HXXRET3(NULLPTR, ResultRef<BaseArray<Vector>>)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetPointsWrite));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetTetrahedronCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetTetrahedronCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::GetPointCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_GetPointCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::Reset() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_Reset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint) -> Float
{
	return (MTable::_instance.Delaunay3DInterface_OrientDet(planePointA, planePointB, planePointC, testPoint));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::Fn<S>::Flush() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_FindTetIndexContainingPoint, point, foundTetIndex, onFace1, onFace2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Delaunay3DInterface::Hxx1::ConstFn<S>::FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.Delaunay3DInterface_FindTetContainingPoint, point, foundTetIndex));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_delaunay3d)
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

