
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Bool> (*_VoxelizationInterface_Init) (maxon::GenericComponent* this_, PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise);
	maxon::Int _VoxelizationInterface_Init_Offset;
	Result<Bool> (*_VoxelizationInterface_Init_1) (maxon::GenericComponent* this_, PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride);
	maxon::Int _VoxelizationInterface_Init_1_Offset;
	Result<Bool> (*_VoxelizationInterface_Init_2) (maxon::GenericComponent* this_, const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);
	maxon::Int _VoxelizationInterface_Init_2_Offset;
	Result<Bool> (*_VoxelizationInterface_Init_3) (maxon::GenericComponent* this_, const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges);
	maxon::Int _VoxelizationInterface_Init_3_Offset;
	Result<void> (*_VoxelizationInterface_GetClosestPolys) (const maxon::GenericComponent* this_, const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter);
	maxon::Int _VoxelizationInterface_GetClosestPolys_Offset;
	Result<void> (*_VoxelizationInterface_GetIntersectingIndices) (const maxon::GenericComponent* this_, const Range<Vector>& toTestBox, BaseArray<Int32>& indexList);
	maxon::Int _VoxelizationInterface_GetIntersectingIndices_Offset;
	Result<void> (*_VoxelizationInterface_GetIntersectingIndicesPrecise) (const maxon::GenericComponent* this_, const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList);
	maxon::Int _VoxelizationInterface_GetIntersectingIndicesPrecise_Offset;
	Result<Bool> (*_VoxelizationInterface_GetIntersectingIndices_1) (const maxon::GenericComponent* this_, const Vector& point, BaseArray<Int32>& indexList);
	maxon::Int _VoxelizationInterface_GetIntersectingIndices_1_Offset;
	const Range<Vector>& (*_VoxelizationInterface_GetBoundingBox) (const maxon::GenericComponent* this_);
	maxon::Int _VoxelizationInterface_GetBoundingBox_Offset;
	Range<IntVector32> (*_VoxelizationInterface_GetVoxelRangesFromBoundingBox) (const maxon::GenericComponent* this_, const Range<Vector>& boundingBox);
	maxon::Int _VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset;
	Bool (*_VoxelizationInterface_IsInitialized) (const maxon::GenericComponent* this_);
	maxon::Int _VoxelizationInterface_IsInitialized_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init), W, MTable>::type::_VoxelizationInterface_Init;
			_VoxelizationInterface_Init = reinterpret_cast<const decltype(_VoxelizationInterface_Init)&>(ptr);
			_VoxelizationInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init), W, MTable>::type::_VoxelizationInterface_Init_1;
			_VoxelizationInterface_Init_1 = reinterpret_cast<const decltype(_VoxelizationInterface_Init_1)&>(ptr);
			_VoxelizationInterface_Init_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init), W, MTable>::type::_VoxelizationInterface_Init_2;
			_VoxelizationInterface_Init_2 = reinterpret_cast<const decltype(_VoxelizationInterface_Init_2)&>(ptr);
			_VoxelizationInterface_Init_2_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, Init), W, MTable>::type::_VoxelizationInterface_Init_3;
			_VoxelizationInterface_Init_3 = reinterpret_cast<const decltype(_VoxelizationInterface_Init_3)&>(ptr);
			_VoxelizationInterface_Init_3_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetClosestPolys))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetClosestPolys), W, MTable>::type::_VoxelizationInterface_GetClosestPolys;
			_VoxelizationInterface_GetClosestPolys = reinterpret_cast<const decltype(_VoxelizationInterface_GetClosestPolys)&>(ptr);
			_VoxelizationInterface_GetClosestPolys_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices), W, MTable>::type::_VoxelizationInterface_GetIntersectingIndices;
			_VoxelizationInterface_GetIntersectingIndices = reinterpret_cast<const decltype(_VoxelizationInterface_GetIntersectingIndices)&>(ptr);
			_VoxelizationInterface_GetIntersectingIndices_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndicesPrecise))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndicesPrecise), W, MTable>::type::_VoxelizationInterface_GetIntersectingIndicesPrecise;
			_VoxelizationInterface_GetIntersectingIndicesPrecise = reinterpret_cast<const decltype(_VoxelizationInterface_GetIntersectingIndicesPrecise)&>(ptr);
			_VoxelizationInterface_GetIntersectingIndicesPrecise_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetIntersectingIndices), W, MTable>::type::_VoxelizationInterface_GetIntersectingIndices_1;
			_VoxelizationInterface_GetIntersectingIndices_1 = reinterpret_cast<const decltype(_VoxelizationInterface_GetIntersectingIndices_1)&>(ptr);
			_VoxelizationInterface_GetIntersectingIndices_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetBoundingBox))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetBoundingBox), W, MTable>::type::_VoxelizationInterface_GetBoundingBox;
			_VoxelizationInterface_GetBoundingBox = reinterpret_cast<const decltype(_VoxelizationInterface_GetBoundingBox)&>(ptr);
			_VoxelizationInterface_GetBoundingBox_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetVoxelRangesFromBoundingBox))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, GetVoxelRangesFromBoundingBox), W, MTable>::type::_VoxelizationInterface_GetVoxelRangesFromBoundingBox;
			_VoxelizationInterface_GetVoxelRangesFromBoundingBox = reinterpret_cast<const decltype(_VoxelizationInterface_GetVoxelRangesFromBoundingBox)&>(ptr);
			_VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, IsInitialized))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VoxelizationInterface, IsInitialized), W, MTable>::type::_VoxelizationInterface_IsInitialized;
			_VoxelizationInterface_IsInitialized = reinterpret_cast<const decltype(_VoxelizationInterface_IsInitialized)&>(ptr);
			_VoxelizationInterface_IsInitialized_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<VoxelizationInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(VoxelizationInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VoxelizationInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBoundingBox);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetClosestPolys);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIntersectingIndices);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIntersectingIndicesPrecise);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetVoxelRangesFromBoundingBox);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsInitialized);
	static Result<Bool> _VoxelizationInterface_Init(maxon::GenericComponent* this_, PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) { return ((typename S::Implementation*) this_)->Init(polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise); }
	static Result<Bool> _VoxelizationInterface_Init_1(maxon::GenericComponent* this_, PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) { return ((typename S::Implementation*) this_)->Init(polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride); }
	static Result<Bool> _VoxelizationInterface_Init_2(maxon::GenericComponent* this_, const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) { return ((typename S::Implementation*) this_)->Init(hull, voxelResolution, minResolution, polyRanges); }
	static Result<Bool> _VoxelizationInterface_Init_3(maxon::GenericComponent* this_, const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) { return ((typename S::Implementation*) this_)->Init(facePoints, points, voxelResolution, minResolution, polyRanges); }
	static Result<void> _VoxelizationInterface_GetClosestPolys(const maxon::GenericComponent* this_, const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) { return ((const typename S::Implementation*) this_)->GetClosestPolys(std::forward<const Vector>(pos), voxelPolys, polyFilter); }
	static Result<void> _VoxelizationInterface_GetIntersectingIndices(const maxon::GenericComponent* this_, const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) this_)->GetIntersectingIndices(toTestBox, indexList); }
	static Result<void> _VoxelizationInterface_GetIntersectingIndicesPrecise(const maxon::GenericComponent* this_, const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) this_)->GetIntersectingIndicesPrecise(toTestBox, polyRanges, indexList); }
	static Result<Bool> _VoxelizationInterface_GetIntersectingIndices_1(const maxon::GenericComponent* this_, const Vector& point, BaseArray<Int32>& indexList) { return ((const typename S::Implementation*) this_)->GetIntersectingIndices(point, indexList); }
	static const Range<Vector>& _VoxelizationInterface_GetBoundingBox(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBoundingBox(); }
	static Range<IntVector32> _VoxelizationInterface_GetVoxelRangesFromBoundingBox(const maxon::GenericComponent* this_, const Range<Vector>& boundingBox) { return ((const typename S::Implementation*) this_)->GetVoxelRangesFromBoundingBox(boundingBox); }
	static Bool _VoxelizationInterface_IsInitialized(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsInitialized(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_Init((maxon::GenericComponent*) this + mt_._VoxelizationInterface_Init_Offset, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_Init_1((maxon::GenericComponent*) this + mt_._VoxelizationInterface_Init_1_Offset, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_Init_2((maxon::GenericComponent*) this + mt_._VoxelizationInterface_Init_2_Offset, hull, voxelResolution, minResolution, polyRanges);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_Init_3((maxon::GenericComponent*) this + mt_._VoxelizationInterface_Init_3_Offset, facePoints, points, voxelResolution, minResolution, polyRanges);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetClosestPolys((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetClosestPolys_Offset, std::forward<const Vector>(pos), voxelPolys, polyFilter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetIntersectingIndices((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetIntersectingIndices_Offset, toTestBox, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const -> Result<void>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetIntersectingIndicesPrecise((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetIntersectingIndicesPrecise_Offset, toTestBox, polyRanges, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const -> Result<Bool>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetIntersectingIndices_1((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetIntersectingIndices_1_Offset, point, indexList);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetBoundingBox() const -> const Range<Vector>&
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetBoundingBox((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetBoundingBox_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const -> Range<IntVector32>
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset, boundingBox);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::IsInitialized() const -> Bool
{
	const VoxelizationInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VoxelizationInterface, this); return mt_._VoxelizationInterface_IsInitialized((const maxon::GenericComponent*) this + mt_._VoxelizationInterface_IsInitialized_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_Offset, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_Offset, polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_1_Offset, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_1_Offset, polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_2_Offset, hull, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_2_Offset, hull, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_3) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_3(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_3_Offset, facePoints, points, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VoxelizationInterface* o_ = (VoxelizationInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_Init_3) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_Init_3(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_Init_3_Offset, facePoints, points, voxelResolution, minResolution, polyRanges));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetClosestPolys) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetClosestPolys(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetClosestPolys_Offset, std::forward<const Vector>(pos), voxelPolys, polyFilter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetIntersectingIndices) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetIntersectingIndices(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndices_Offset, toTestBox, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetIntersectingIndicesPrecise) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetIntersectingIndicesPrecise(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndicesPrecise_Offset, toTestBox, polyRanges, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetIntersectingIndices_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetIntersectingIndices_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetIntersectingIndices_1_Offset, point, indexList));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBoundingBox() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Range<Vector>&>, const Range<Vector>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Range<Vector>&>, const Range<Vector>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Range<Vector>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetBoundingBox) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetBoundingBox(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetBoundingBox_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Range<IntVector32>>, Range<IntVector32>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Range<IntVector32>>, Range<IntVector32>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Range<IntVector32>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_GetVoxelRangesFromBoundingBox) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_GetVoxelRangesFromBoundingBox_Offset, boundingBox));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VoxelizationInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsInitialized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VoxelizationInterface* o_ = (const VoxelizationInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VoxelizationInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VoxelizationInterface, o_, VoxelizationInterface_IsInitialized) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<VoxelizationInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VoxelizationInterface>() : PRIVATE_MAXON_VTABLE(VoxelizationInterface, o_); 
	return (mt_._VoxelizationInterface_IsInitialized(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VoxelizationInterface_IsInitialized_Offset));
}
auto VoxelizationInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VoxelizationInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

