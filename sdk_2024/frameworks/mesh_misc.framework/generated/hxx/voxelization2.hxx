
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct VoxelizationInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBoundingBox);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetClosestPolys);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetIntersectingIndices);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetIntersectingIndicesPrecise);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetVoxelRangesFromBoundingBox);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsInitialized);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_Init, Init, true, maxon::GenericComponent,, (Result<Bool>), PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise);
	maxon::Int VoxelizationInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<Bool>), PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride);
	maxon::Int VoxelizationInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_Init_2, Init, true, maxon::GenericComponent,, (Result<Bool>), const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);
	maxon::Int VoxelizationInterface_Init_2_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_Init_3, Init, true, maxon::GenericComponent,, (Result<Bool>), const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);
	maxon::Int VoxelizationInterface_Init_3_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetClosestPolys, GetClosestPolys, true, maxon::GenericComponent, const, (Result<void>), const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter);
	maxon::Int VoxelizationInterface_GetClosestPolys_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetIntersectingIndices, GetIntersectingIndices, true, maxon::GenericComponent, const, (Result<void>), const Range<Vector>& toTestBox, BaseArray<Int32>& indexList);
	maxon::Int VoxelizationInterface_GetIntersectingIndices_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetIntersectingIndicesPrecise, GetIntersectingIndicesPrecise, true, maxon::GenericComponent, const, (Result<void>), const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList);
	maxon::Int VoxelizationInterface_GetIntersectingIndicesPrecise_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetIntersectingIndices_1, GetIntersectingIndices, true, maxon::GenericComponent, const, (Result<Bool>), const Vector& point, BaseArray<Int32>& indexList);
	maxon::Int VoxelizationInterface_GetIntersectingIndices_1_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetBoundingBox, GetBoundingBox, true, maxon::GenericComponent, const, (const Range<Vector>&));
	maxon::Int VoxelizationInterface_GetBoundingBox_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_GetVoxelRangesFromBoundingBox, GetVoxelRangesFromBoundingBox, true, maxon::GenericComponent, const, (Range<IntVector32>), const Range<Vector>& boundingBox);
	maxon::Int VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset;
	PRIVATE_MAXON_MF_POINTER(VoxelizationInterface_IsInitialized, IsInitialized, true, maxon::GenericComponent, const, (Bool));
	maxon::Int VoxelizationInterface_IsInitialized_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
	{
		maxon::Tie(VoxelizationInterface_Init, VoxelizationInterface_Init_Offset) = VoxelizationInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
	{
		maxon::Tie(VoxelizationInterface_Init_1, VoxelizationInterface_Init_1_Offset) = VoxelizationInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
	{
		maxon::Tie(VoxelizationInterface_Init_2, VoxelizationInterface_Init_2_Offset) = VoxelizationInterface_Init_2_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
	{
		maxon::Tie(VoxelizationInterface_Init_3, VoxelizationInterface_Init_3_Offset) = VoxelizationInterface_Init_3_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetClosestPolys))
	{
		maxon::Tie(VoxelizationInterface_GetClosestPolys, VoxelizationInterface_GetClosestPolys_Offset) = VoxelizationInterface_GetClosestPolys_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices))
	{
		maxon::Tie(VoxelizationInterface_GetIntersectingIndices, VoxelizationInterface_GetIntersectingIndices_Offset) = VoxelizationInterface_GetIntersectingIndices_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndicesPrecise))
	{
		maxon::Tie(VoxelizationInterface_GetIntersectingIndicesPrecise, VoxelizationInterface_GetIntersectingIndicesPrecise_Offset) = VoxelizationInterface_GetIntersectingIndicesPrecise_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices))
	{
		maxon::Tie(VoxelizationInterface_GetIntersectingIndices_1, VoxelizationInterface_GetIntersectingIndices_1_Offset) = VoxelizationInterface_GetIntersectingIndices_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetBoundingBox))
	{
		maxon::Tie(VoxelizationInterface_GetBoundingBox, VoxelizationInterface_GetBoundingBox_Offset) = VoxelizationInterface_GetBoundingBox_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetVoxelRangesFromBoundingBox))
	{
		maxon::Tie(VoxelizationInterface_GetVoxelRangesFromBoundingBox, VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset) = VoxelizationInterface_GetVoxelRangesFromBoundingBox_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, IsInitialized))
	{
		maxon::Tie(VoxelizationInterface_IsInitialized, VoxelizationInterface_IsInitialized_Offset) = VoxelizationInterface_IsInitialized_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<VoxelizationInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<VoxelizationInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VoxelizationInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBoundingBox);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetClosestPolys);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIntersectingIndices);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIntersectingIndicesPrecise);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetVoxelRangesFromBoundingBox);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsInitialized);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (VoxelizationInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VoxelizationInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_Init, maxon::GenericComponent,, (Result<Bool>), PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_Init_1, maxon::GenericComponent,, (Result<Bool>), PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_Init_2, maxon::GenericComponent,, (Result<Bool>), const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(hull, voxelResolution, minResolution, polyRanges); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_Init_3, maxon::GenericComponent,, (Result<Bool>), const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(facePoints, points, voxelResolution, minResolution, polyRanges); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetClosestPolys, maxon::GenericComponent, const, (Result<void>), const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetClosestPolys(std::forward<const Vector>(pos), voxelPolys, polyFilter); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetIntersectingIndices, maxon::GenericComponent, const, (Result<void>), const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetIntersectingIndices(toTestBox, indexList); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetIntersectingIndicesPrecise, maxon::GenericComponent, const, (Result<void>), const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetIntersectingIndicesPrecise(toTestBox, polyRanges, indexList); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetIntersectingIndices_1, maxon::GenericComponent, const, (Result<Bool>), const Vector& point, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetIntersectingIndices(point, indexList); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetBoundingBox, maxon::GenericComponent, const, (const Range<Vector>&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBoundingBox(); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_GetVoxelRangesFromBoundingBox, maxon::GenericComponent, const, (Range<IntVector32>), const Range<Vector>& boundingBox) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetVoxelRangesFromBoundingBox(boundingBox); }
		PRIVATE_MAXON_MF_WRAPPER(VoxelizationInterface_IsInitialized, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsInitialized(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VoxelizationInterface_Init_Offset), mt_.VoxelizationInterface_Init, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VoxelizationInterface_Init_1_Offset), mt_.VoxelizationInterface_Init_1, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VoxelizationInterface_Init_2_Offset), mt_.VoxelizationInterface_Init_2, hull, voxelResolution, minResolution, polyRanges);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VoxelizationInterface_Init_3_Offset), mt_.VoxelizationInterface_Init_3, facePoints, points, voxelResolution, minResolution, polyRanges);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetClosestPolys_Offset), mt_.VoxelizationInterface_GetClosestPolys, std::forward<const Vector>(pos), voxelPolys, polyFilter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetIntersectingIndices_Offset), mt_.VoxelizationInterface_GetIntersectingIndices, toTestBox, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetIntersectingIndicesPrecise_Offset), mt_.VoxelizationInterface_GetIntersectingIndicesPrecise, toTestBox, polyRanges, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetIntersectingIndices_1_Offset), mt_.VoxelizationInterface_GetIntersectingIndices_1, point, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetBoundingBox() const -> const Range<Vector>&
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetBoundingBox_Offset), mt_.VoxelizationInterface_GetBoundingBox);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const -> Range<IntVector32>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset), mt_.VoxelizationInterface_GetVoxelRangesFromBoundingBox, boundingBox);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::IsInitialized() const -> Bool
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VoxelizationInterface_IsInitialized_Offset), mt_.VoxelizationInterface_IsInitialized);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::Fn<S>::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_Offset), mt_.VoxelizationInterface_Init, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWFn<S>::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(VoxelizationInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_Offset), mt_.VoxelizationInterface_Init, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::Fn<S>::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_1_Offset), mt_.VoxelizationInterface_Init_1, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWFn<S>::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(VoxelizationInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_1_Offset), mt_.VoxelizationInterface_Init_1, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::Fn<S>::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_Init_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_2_Offset), mt_.VoxelizationInterface_Init_2, hull, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWFn<S>::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(VoxelizationInterface_Init_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_2_Offset), mt_.VoxelizationInterface_Init_2, hull, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::Fn<S>::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_Init_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_3_Offset), mt_.VoxelizationInterface_Init_3, facePoints, points, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWFn<S>::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(VoxelizationInterface_Init_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_Init_3_Offset), mt_.VoxelizationInterface_Init_3, facePoints, points, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_GetClosestPolys); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetClosestPolys_Offset), mt_.VoxelizationInterface_GetClosestPolys, std::forward<const Vector>(pos), voxelPolys, polyFilter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_GetIntersectingIndices); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetIntersectingIndices_Offset), mt_.VoxelizationInterface_GetIntersectingIndices, toTestBox, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_GetIntersectingIndicesPrecise); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetIntersectingIndicesPrecise_Offset), mt_.VoxelizationInterface_GetIntersectingIndicesPrecise, toTestBox, polyRanges, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(VoxelizationInterface_GetIntersectingIndices_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetIntersectingIndices_1_Offset), mt_.VoxelizationInterface_GetIntersectingIndices_1, point, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetBoundingBox() const -> HXXADDRET2(const Range<Vector>&)
{
	HXXRETURN0(HXXADDRET2(const Range<Vector>&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Range<Vector>&)) HXXTABLE(VoxelizationInterface_GetBoundingBox); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetBoundingBox_Offset), mt_.VoxelizationInterface_GetBoundingBox));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const -> HXXADDRET2(Range<IntVector32>)
{
	HXXRETURN0(HXXADDRET2(Range<IntVector32>)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Range<IntVector32>)) HXXTABLE(VoxelizationInterface_GetVoxelRangesFromBoundingBox); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset), mt_.VoxelizationInterface_GetVoxelRangesFromBoundingBox, boundingBox));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstFn<S>::IsInitialized() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(VoxelizationInterface_IsInitialized); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VoxelizationInterface_IsInitialized_Offset), mt_.VoxelizationInterface_IsInitialized));
}
auto VoxelizationInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VoxelizationInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_voxelization)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_VoxelizationInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_VoxelizationInterface() { new (s_ui_maxon_VoxelizationInterface) maxon::EntityUse(VoxelizationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/voxelization.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_VoxelizationInterface(VoxelizationInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/voxelization.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

