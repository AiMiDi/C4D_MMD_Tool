
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DistanceQueryInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetClosestMeshPrimitive);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDistanceToMesh);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDistanceToMeshMaxAngleToDirection);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDistanceToSpline);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsInitialized);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetThreading);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), PolygonObject* mesh, Bool initVoxelization);
	maxon::Int DistanceQueryInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), SplineObject* spline);
	maxon::Int DistanceQueryInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_Init_2, Init, true, maxon::GenericComponent,, (Result<void>), LineObject* line);
	maxon::Int DistanceQueryInterface_Init_2_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_Init_3, Init, true, maxon::GenericComponent,, (Result<void>), const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition);
	maxon::Int DistanceQueryInterface_Init_3_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int DistanceQueryInterface_Reset_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_GetClosestMeshPrimitive, GetClosestMeshPrimitive, true, maxon::GenericComponent, const, (Float), const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter);
	maxon::Int DistanceQueryInterface_GetClosestMeshPrimitive_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_GetDistanceToMesh, GetDistanceToMesh, true, maxon::GenericComponent, const, (void), const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives);
	maxon::Int DistanceQueryInterface_GetDistanceToMesh_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, GetDistanceToMeshMaxAngleToDirection, true, maxon::GenericComponent, const, (void), const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives);
	maxon::Int DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_GetDistanceToSpline, GetDistanceToSpline, true, maxon::GenericComponent, const, (void), const Vector& pos, SplineDistanceData& distInfo);
	maxon::Int DistanceQueryInterface_GetDistanceToSpline_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_IsInitialized, IsInitialized, true, maxon::GenericComponent, const, (Bool));
	maxon::Int DistanceQueryInterface_IsInitialized_Offset;
	PRIVATE_MAXON_MF_POINTER(DistanceQueryInterface_SetThreading, SetThreading, true, maxon::GenericComponent,, (void), Int32 threads);
	maxon::Int DistanceQueryInterface_SetThreading_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
	{
		maxon::Tie(DistanceQueryInterface_Init, DistanceQueryInterface_Init_Offset) = DistanceQueryInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
	{
		maxon::Tie(DistanceQueryInterface_Init_1, DistanceQueryInterface_Init_1_Offset) = DistanceQueryInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
	{
		maxon::Tie(DistanceQueryInterface_Init_2, DistanceQueryInterface_Init_2_Offset) = DistanceQueryInterface_Init_2_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
	{
		maxon::Tie(DistanceQueryInterface_Init_3, DistanceQueryInterface_Init_3_Offset) = DistanceQueryInterface_Init_3_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Reset))
	{
		maxon::Tie(DistanceQueryInterface_Reset, DistanceQueryInterface_Reset_Offset) = DistanceQueryInterface_Reset_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetClosestMeshPrimitive))
	{
		maxon::Tie(DistanceQueryInterface_GetClosestMeshPrimitive, DistanceQueryInterface_GetClosestMeshPrimitive_Offset) = DistanceQueryInterface_GetClosestMeshPrimitive_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMesh))
	{
		maxon::Tie(DistanceQueryInterface_GetDistanceToMesh, DistanceQueryInterface_GetDistanceToMesh_Offset) = DistanceQueryInterface_GetDistanceToMesh_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMeshMaxAngleToDirection))
	{
		maxon::Tie(DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset) = DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToSpline))
	{
		maxon::Tie(DistanceQueryInterface_GetDistanceToSpline, DistanceQueryInterface_GetDistanceToSpline_Offset) = DistanceQueryInterface_GetDistanceToSpline_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, IsInitialized))
	{
		maxon::Tie(DistanceQueryInterface_IsInitialized, DistanceQueryInterface_IsInitialized_Offset) = DistanceQueryInterface_IsInitialized_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, SetThreading))
	{
		maxon::Tie(DistanceQueryInterface_SetThreading, DistanceQueryInterface_SetThreading_Offset) = DistanceQueryInterface_SetThreading_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DistanceQueryInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DistanceQueryInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DistanceQueryInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetClosestMeshPrimitive);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDistanceToMesh);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDistanceToMeshMaxAngleToDirection);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDistanceToSpline);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsInitialized);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetThreading);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DistanceQueryInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DistanceQueryInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_Init, maxon::GenericComponent,, (Result<void>), PolygonObject* mesh, Bool initVoxelization) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(mesh, initVoxelization); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_Init_1, maxon::GenericComponent,, (Result<void>), SplineObject* spline) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(spline); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_Init_2, maxon::GenericComponent,, (Result<void>), LineObject* line) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(line); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_Init_3, maxon::GenericComponent,, (Result<void>), const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(std::forward<const Block<const Vector>>(points), std::forward<const Block<const SimplePolygon>>(polygons), objectPosition); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_GetClosestMeshPrimitive, maxon::GenericComponent, const, (Float), const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetClosestMeshPrimitive(pos, primInfo, polyFilter); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_GetDistanceToMesh, maxon::GenericComponent, const, (void), const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDistanceToMesh(pos, distInfo, polyFilter, onlyPolyPrimitives); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, maxon::GenericComponent, const, (void), const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDistanceToMeshMaxAngleToDirection(pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_GetDistanceToSpline, maxon::GenericComponent, const, (void), const Vector& pos, SplineDistanceData& distInfo) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDistanceToSpline(pos, distInfo); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_IsInitialized, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsInitialized(); }
		PRIVATE_MAXON_MF_WRAPPER(DistanceQueryInterface_SetThreading, maxon::GenericComponent,, (void), Int32 threads) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetThreading(threads); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(PolygonObject* mesh, Bool initVoxelization) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_Init_Offset), mt_.DistanceQueryInterface_Init, mesh, initVoxelization);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(SplineObject* spline) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_Init_1_Offset), mt_.DistanceQueryInterface_Init_1, spline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(LineObject* line) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_Init_2_Offset), mt_.DistanceQueryInterface_Init_2, line);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_Init_3_Offset), mt_.DistanceQueryInterface_Init_3, std::forward<const Block<const Vector>>(points), std::forward<const Block<const SimplePolygon>>(polygons), objectPosition);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Reset() -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_Reset_Offset), mt_.DistanceQueryInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const -> Float
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DistanceQueryInterface_GetClosestMeshPrimitive_Offset), mt_.DistanceQueryInterface_GetClosestMeshPrimitive, pos, primInfo, polyFilter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DistanceQueryInterface_GetDistanceToMesh_Offset), mt_.DistanceQueryInterface_GetDistanceToMesh, pos, distInfo, polyFilter, onlyPolyPrimitives);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset), mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DistanceQueryInterface_GetDistanceToSpline_Offset), mt_.DistanceQueryInterface_GetDistanceToSpline, pos, distInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::IsInitialized() const -> Bool
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DistanceQueryInterface_IsInitialized_Offset), mt_.DistanceQueryInterface_IsInitialized);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::SetThreading(Int32 threads) -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DistanceQueryInterface_SetThreading_Offset), mt_.DistanceQueryInterface_SetThreading, threads);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::Init(PolygonObject* mesh, Bool initVoxelization) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DistanceQueryInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_Offset), mt_.DistanceQueryInterface_Init, mesh, initVoxelization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::Init(PolygonObject* mesh, Bool initVoxelization) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_Offset), mt_.DistanceQueryInterface_Init, mesh, initVoxelization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::Init(SplineObject* spline) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DistanceQueryInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_1_Offset), mt_.DistanceQueryInterface_Init_1, spline));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::Init(SplineObject* spline) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_1_Offset), mt_.DistanceQueryInterface_Init_1, spline));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::Init(LineObject* line) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DistanceQueryInterface_Init_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_2_Offset), mt_.DistanceQueryInterface_Init_2, line));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::Init(LineObject* line) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_Init_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_2_Offset), mt_.DistanceQueryInterface_Init_2, line));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DistanceQueryInterface_Init_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_3_Offset), mt_.DistanceQueryInterface_Init_3, std::forward<const Block<const Vector>>(points), std::forward<const Block<const SimplePolygon>>(polygons), objectPosition));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_Init_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Init_3_Offset), mt_.DistanceQueryInterface_Init_3, std::forward<const Block<const Vector>>(points), std::forward<const Block<const SimplePolygon>>(polygons), objectPosition));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::Reset() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(DistanceQueryInterface_Reset); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Reset_Offset), mt_.DistanceQueryInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::Reset() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_Reset); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_Reset_Offset), mt_.DistanceQueryInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstFn<S>::GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const -> HXXADDRET2(Float)
{
	HXXRETURN0(HXXADDRET2(Float)); HXXRES; HXXCONST(0) HXXTABLE(DistanceQueryInterface_GetClosestMeshPrimitive); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetClosestMeshPrimitive_Offset), mt_.DistanceQueryInterface_GetClosestMeshPrimitive, pos, primInfo, polyFilter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstFn<S>::GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(DistanceQueryInterface_GetDistanceToMesh); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToMesh_Offset), mt_.DistanceQueryInterface_GetDistanceToMesh, pos, distInfo, polyFilter, onlyPolyPrimitives);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstFn<S>::GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset), mt_.DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection, pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstFn<S>::GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(DistanceQueryInterface_GetDistanceToSpline); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_GetDistanceToSpline_Offset), mt_.DistanceQueryInterface_GetDistanceToSpline, pos, distInfo);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstFn<S>::IsInitialized() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(DistanceQueryInterface_IsInitialized); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_IsInitialized_Offset), mt_.DistanceQueryInterface_IsInitialized));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::Fn<S>::SetThreading(Int32 threads) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(DistanceQueryInterface_SetThreading); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_SetThreading_Offset), mt_.DistanceQueryInterface_SetThreading, threads);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWFn<S>::SetThreading(Int32 threads) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DistanceQueryInterface_SetThreading); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DistanceQueryInterface_SetThreading_Offset), mt_.DistanceQueryInterface_SetThreading, threads);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto DistanceQueryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DistanceQueryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_distancequery)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DistanceQueryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DistanceQueryInterface() { new (s_ui_maxon_DistanceQueryInterface) maxon::EntityUse(DistanceQueryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/distancequery.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DistanceQueryInterface(DistanceQueryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/distancequery.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

