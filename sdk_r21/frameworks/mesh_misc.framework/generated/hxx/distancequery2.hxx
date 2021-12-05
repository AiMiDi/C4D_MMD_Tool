
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DistanceQueryInterface_Init) (maxon::GenericComponent* this_, PolygonObject* mesh, Bool initVoxelization);
	maxon::Int _DistanceQueryInterface_Init_Offset;
	Result<void> (*_DistanceQueryInterface_Init_1) (maxon::GenericComponent* this_, SplineObject* spline);
	maxon::Int _DistanceQueryInterface_Init_1_Offset;
	Result<void> (*_DistanceQueryInterface_Init_2) (maxon::GenericComponent* this_, LineObject* line);
	maxon::Int _DistanceQueryInterface_Init_2_Offset;
	void (*_DistanceQueryInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _DistanceQueryInterface_Reset_Offset;
	Float (*_DistanceQueryInterface_GetClosestMeshPrimitive) (const maxon::GenericComponent* this_, const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter);
	maxon::Int _DistanceQueryInterface_GetClosestMeshPrimitive_Offset;
	void (*_DistanceQueryInterface_GetDistanceToMesh) (const maxon::GenericComponent* this_, const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives);
	maxon::Int _DistanceQueryInterface_GetDistanceToMesh_Offset;
	void (*_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection) (const maxon::GenericComponent* this_, const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives);
	maxon::Int _DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset;
	void (*_DistanceQueryInterface_GetDistanceToSpline) (const maxon::GenericComponent* this_, const Vector& pos, SplineDistanceData& distInfo);
	maxon::Int _DistanceQueryInterface_GetDistanceToSpline_Offset;
	Bool (*_DistanceQueryInterface_IsInitialized) (const maxon::GenericComponent* this_);
	maxon::Int _DistanceQueryInterface_IsInitialized_Offset;
	void (*_DistanceQueryInterface_SetThreading) (maxon::GenericComponent* this_, Int32 threads);
	maxon::Int _DistanceQueryInterface_SetThreading_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init), W, MTable>::type::_DistanceQueryInterface_Init;
			_DistanceQueryInterface_Init = reinterpret_cast<const decltype(_DistanceQueryInterface_Init)&>(ptr);
			_DistanceQueryInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init), W, MTable>::type::_DistanceQueryInterface_Init_1;
			_DistanceQueryInterface_Init_1 = reinterpret_cast<const decltype(_DistanceQueryInterface_Init_1)&>(ptr);
			_DistanceQueryInterface_Init_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Init), W, MTable>::type::_DistanceQueryInterface_Init_2;
			_DistanceQueryInterface_Init_2 = reinterpret_cast<const decltype(_DistanceQueryInterface_Init_2)&>(ptr);
			_DistanceQueryInterface_Init_2_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, Reset), W, MTable>::type::_DistanceQueryInterface_Reset;
			_DistanceQueryInterface_Reset = reinterpret_cast<const decltype(_DistanceQueryInterface_Reset)&>(ptr);
			_DistanceQueryInterface_Reset_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetClosestMeshPrimitive))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetClosestMeshPrimitive), W, MTable>::type::_DistanceQueryInterface_GetClosestMeshPrimitive;
			_DistanceQueryInterface_GetClosestMeshPrimitive = reinterpret_cast<const decltype(_DistanceQueryInterface_GetClosestMeshPrimitive)&>(ptr);
			_DistanceQueryInterface_GetClosestMeshPrimitive_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMesh))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMesh), W, MTable>::type::_DistanceQueryInterface_GetDistanceToMesh;
			_DistanceQueryInterface_GetDistanceToMesh = reinterpret_cast<const decltype(_DistanceQueryInterface_GetDistanceToMesh)&>(ptr);
			_DistanceQueryInterface_GetDistanceToMesh_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMeshMaxAngleToDirection))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToMeshMaxAngleToDirection), W, MTable>::type::_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection;
			_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection = reinterpret_cast<const decltype(_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection)&>(ptr);
			_DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToSpline))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, GetDistanceToSpline), W, MTable>::type::_DistanceQueryInterface_GetDistanceToSpline;
			_DistanceQueryInterface_GetDistanceToSpline = reinterpret_cast<const decltype(_DistanceQueryInterface_GetDistanceToSpline)&>(ptr);
			_DistanceQueryInterface_GetDistanceToSpline_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, IsInitialized))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, IsInitialized), W, MTable>::type::_DistanceQueryInterface_IsInitialized;
			_DistanceQueryInterface_IsInitialized = reinterpret_cast<const decltype(_DistanceQueryInterface_IsInitialized)&>(ptr);
			_DistanceQueryInterface_IsInitialized_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, SetThreading))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DistanceQueryInterface, SetThreading), W, MTable>::type::_DistanceQueryInterface_SetThreading;
			_DistanceQueryInterface_SetThreading = reinterpret_cast<const decltype(_DistanceQueryInterface_SetThreading)&>(ptr);
			_DistanceQueryInterface_SetThreading_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DistanceQueryInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DistanceQueryInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DistanceQueryInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
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
	static Result<void> _DistanceQueryInterface_Init(maxon::GenericComponent* this_, PolygonObject* mesh, Bool initVoxelization) { return ((typename S::Implementation*) this_)->Init(mesh, initVoxelization); }
	static Result<void> _DistanceQueryInterface_Init_1(maxon::GenericComponent* this_, SplineObject* spline) { return ((typename S::Implementation*) this_)->Init(spline); }
	static Result<void> _DistanceQueryInterface_Init_2(maxon::GenericComponent* this_, LineObject* line) { return ((typename S::Implementation*) this_)->Init(line); }
	static void _DistanceQueryInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	static Float _DistanceQueryInterface_GetClosestMeshPrimitive(const maxon::GenericComponent* this_, const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) { return ((const typename S::Implementation*) this_)->GetClosestMeshPrimitive(pos, primInfo, polyFilter); }
	static void _DistanceQueryInterface_GetDistanceToMesh(const maxon::GenericComponent* this_, const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) { return ((const typename S::Implementation*) this_)->GetDistanceToMesh(pos, distInfo, polyFilter, onlyPolyPrimitives); }
	static void _DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection(const maxon::GenericComponent* this_, const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) { return ((const typename S::Implementation*) this_)->GetDistanceToMeshMaxAngleToDirection(pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives); }
	static void _DistanceQueryInterface_GetDistanceToSpline(const maxon::GenericComponent* this_, const Vector& pos, SplineDistanceData& distInfo) { return ((const typename S::Implementation*) this_)->GetDistanceToSpline(pos, distInfo); }
	static Bool _DistanceQueryInterface_IsInitialized(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsInitialized(); }
	static void _DistanceQueryInterface_SetThreading(maxon::GenericComponent* this_, Int32 threads) { return ((typename S::Implementation*) this_)->SetThreading(threads); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(PolygonObject* mesh, Bool initVoxelization) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_Init((maxon::GenericComponent*) this + mt_._DistanceQueryInterface_Init_Offset, mesh, initVoxelization);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(SplineObject* spline) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_Init_1((maxon::GenericComponent*) this + mt_._DistanceQueryInterface_Init_1_Offset, spline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Init(LineObject* line) -> Result<void>
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_Init_2((maxon::GenericComponent*) this + mt_._DistanceQueryInterface_Init_2_Offset, line);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Reset() -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_Reset((maxon::GenericComponent*) this + mt_._DistanceQueryInterface_Reset_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const -> Float
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_GetClosestMeshPrimitive((const maxon::GenericComponent*) this + mt_._DistanceQueryInterface_GetClosestMeshPrimitive_Offset, pos, primInfo, polyFilter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_GetDistanceToMesh((const maxon::GenericComponent*) this + mt_._DistanceQueryInterface_GetDistanceToMesh_Offset, pos, distInfo, polyFilter, onlyPolyPrimitives);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection((const maxon::GenericComponent*) this + mt_._DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset, pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_GetDistanceToSpline((const maxon::GenericComponent*) this + mt_._DistanceQueryInterface_GetDistanceToSpline_Offset, pos, distInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::IsInitialized() const -> Bool
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_IsInitialized((const maxon::GenericComponent*) this + mt_._DistanceQueryInterface_IsInitialized_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::SetThreading(Int32 threads) -> void
{
	const DistanceQueryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DistanceQueryInterface, this); return mt_._DistanceQueryInterface_SetThreading((maxon::GenericComponent*) this + mt_._DistanceQueryInterface_SetThreading_Offset, threads);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(PolygonObject* mesh, Bool initVoxelization) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_Offset, mesh, initVoxelization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(PolygonObject* mesh, Bool initVoxelization) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_Offset, mesh, initVoxelization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(SplineObject* spline) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_1_Offset, spline));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(SplineObject* spline) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_1_Offset, spline));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(LineObject* line) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_2_Offset, line));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(LineObject* line) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Init_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_Init_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Init_2_Offset, line));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DistanceQueryInterface* o_ = (const DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DistanceQueryInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_GetClosestMeshPrimitive) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_GetClosestMeshPrimitive(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_GetClosestMeshPrimitive_Offset, pos, primInfo, polyFilter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DistanceQueryInterface* o_ = (const DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DistanceQueryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_GetDistanceToMesh) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_GetDistanceToMesh(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_GetDistanceToMesh_Offset, pos, distInfo, polyFilter, onlyPolyPrimitives);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DistanceQueryInterface* o_ = (const DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DistanceQueryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_GetDistanceToMeshMaxAngleToDirection_Offset, pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DistanceQueryInterface* o_ = (const DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DistanceQueryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_GetDistanceToSpline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_GetDistanceToSpline(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_GetDistanceToSpline_Offset, pos, distInfo);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsInitialized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DistanceQueryInterface* o_ = (const DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DistanceQueryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_IsInitialized) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	return (mt_._DistanceQueryInterface_IsInitialized(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_IsInitialized_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::ReferenceFunctionsImpl<S>::SetThreading(Int32 threads) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_SetThreading) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_SetThreading(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_SetThreading_Offset, threads);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DistanceQueryInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetThreading(Int32 threads) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DistanceQueryInterface* o_ = (DistanceQueryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DistanceQueryInterface, o_, DistanceQueryInterface_SetThreading) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DistanceQueryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DistanceQueryInterface>() : PRIVATE_MAXON_VTABLE(DistanceQueryInterface, o_); 
	mt_._DistanceQueryInterface_SetThreading(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DistanceQueryInterface_SetThreading_Offset, threads);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto DistanceQueryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DistanceQueryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

