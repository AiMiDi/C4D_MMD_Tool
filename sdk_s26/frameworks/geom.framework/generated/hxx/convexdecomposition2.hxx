
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ConvexDecompositionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Cancel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Clear);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Compute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FetchResults);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSettings);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsReady);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ConvexDecompositionInterface_Init) (maxon::GenericComponent* this_, Float levelOfDetail, UInt32 maxVoxelCount);
	maxon::Int ConvexDecompositionInterface_Init_Offset;
	Result<DataDictionary> (*ConvexDecompositionInterface_GetSettings) (const maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_GetSettings_Offset;
	Bool (*ConvexDecompositionInterface_IsReady) (const maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_IsReady_Offset;
	Result<UInt16> (*ConvexDecompositionInterface_GetProgress) (const maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_GetProgress_Offset;
	Result<void> (*ConvexDecompositionInterface_Compute) (maxon::GenericComponent* this_, const GeometryObject& geometryObject);
	maxon::Int ConvexDecompositionInterface_Compute_Offset;
	Result<Array<GeometryObject>> (*ConvexDecompositionInterface_FetchResults) (maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_FetchResults_Offset;
	Result<void> (*ConvexDecompositionInterface_Cancel) (maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_Cancel_Offset;
	Result<void> (*ConvexDecompositionInterface_Clear) (maxon::GenericComponent* this_);
	maxon::Int ConvexDecompositionInterface_Clear_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Init))
	{
		ConvexDecompositionInterface_Init = &W::ConvexDecompositionInterface_Init;
		ConvexDecompositionInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, GetSettings))
	{
		ConvexDecompositionInterface_GetSettings = &W::ConvexDecompositionInterface_GetSettings;
		ConvexDecompositionInterface_GetSettings_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, IsReady))
	{
		ConvexDecompositionInterface_IsReady = &W::ConvexDecompositionInterface_IsReady;
		ConvexDecompositionInterface_IsReady_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, GetProgress))
	{
		ConvexDecompositionInterface_GetProgress = &W::ConvexDecompositionInterface_GetProgress;
		ConvexDecompositionInterface_GetProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Compute))
	{
		ConvexDecompositionInterface_Compute = &W::ConvexDecompositionInterface_Compute;
		ConvexDecompositionInterface_Compute_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, FetchResults))
	{
		ConvexDecompositionInterface_FetchResults = &W::ConvexDecompositionInterface_FetchResults;
		ConvexDecompositionInterface_FetchResults_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Cancel))
	{
		ConvexDecompositionInterface_Cancel = &W::ConvexDecompositionInterface_Cancel;
		ConvexDecompositionInterface_Cancel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Clear))
	{
		ConvexDecompositionInterface_Clear = &W::ConvexDecompositionInterface_Clear;
		ConvexDecompositionInterface_Clear_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ConvexDecompositionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ConvexDecompositionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ConvexDecompositionInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Cancel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Clear);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Compute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FetchResults);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSettings);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsReady);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ConvexDecompositionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ConvexDecompositionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ConvexDecompositionInterface_Init(maxon::GenericComponent* this_, Float levelOfDetail, UInt32 maxVoxelCount) { return ((typename S::Implementation*) this_)->Init(levelOfDetail, maxVoxelCount); }
		static Result<DataDictionary> ConvexDecompositionInterface_GetSettings(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSettings(); }
		static Bool ConvexDecompositionInterface_IsReady(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsReady(); }
		static Result<UInt16> ConvexDecompositionInterface_GetProgress(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProgress(); }
		static Result<void> ConvexDecompositionInterface_Compute(maxon::GenericComponent* this_, const GeometryObject& geometryObject) { return ((typename S::Implementation*) this_)->Compute(geometryObject); }
		static Result<Array<GeometryObject>> ConvexDecompositionInterface_FetchResults(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->FetchResults(); }
		static Result<void> ConvexDecompositionInterface_Cancel(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Cancel(); }
		static Result<void> ConvexDecompositionInterface_Clear(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Clear(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Init(Float levelOfDetail, UInt32 maxVoxelCount) -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_Init((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Init_Offset, levelOfDetail, maxVoxelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::GetSettings() const -> Result<DataDictionary>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_GetSettings((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_GetSettings_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::IsReady() const -> Bool
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_IsReady((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_IsReady_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::GetProgress() const -> Result<UInt16>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_GetProgress((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_GetProgress_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Compute(const GeometryObject& geometryObject) -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_Compute((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Compute_Offset, geometryObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::FetchResults() -> Result<Array<GeometryObject>>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_FetchResults((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_FetchResults_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Cancel() -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_Cancel((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Cancel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Clear() -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return mt_.ConvexDecompositionInterface_Clear((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Clear_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Init(Float levelOfDetail, UInt32 maxVoxelCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_Offset, levelOfDetail, maxVoxelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Init(Float levelOfDetail, UInt32 maxVoxelCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_Offset, levelOfDetail, maxVoxelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::GetSettings() const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ConvexDecompositionInterface* o_ = (const ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ConvexDecompositionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_GetSettings) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_GetSettings(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_GetSettings_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::IsReady() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ConvexDecompositionInterface* o_ = (const ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ConvexDecompositionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_IsReady) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_IsReady(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_IsReady_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::GetProgress() const -> Result<UInt16>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt16>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ConvexDecompositionInterface* o_ = (const ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ConvexDecompositionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_GetProgress(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_GetProgress_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Compute(const GeometryObject& geometryObject) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Compute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Compute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Compute_Offset, geometryObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Compute(const GeometryObject& geometryObject) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Compute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Compute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Compute_Offset, geometryObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::FetchResults() const -> Result<Array<GeometryObject>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Array<GeometryObject>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_FetchResults) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_FetchResults(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_FetchResults_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::FetchResults() -> Result<Array<GeometryObject>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Array<GeometryObject>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_FetchResults) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_FetchResults(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_FetchResults_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Cancel() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Cancel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Cancel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Cancel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Cancel() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Cancel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Cancel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Cancel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Clear() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Clear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Clear(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Clear_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Clear() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexDecompositionInterface* o_ = (ConvexDecompositionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ConvexDecompositionInterface, o_, ConvexDecompositionInterface_Clear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ConvexDecompositionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ConvexDecompositionInterface>() : PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, o_); 
	return (mt_.ConvexDecompositionInterface_Clear(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Clear_Offset));
}
auto ConvexDecompositionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ConvexDecompositionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_convexdecomposition)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ConvexDecompositionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ConvexDecompositionInterface() { new (s_ui_maxon_ConvexDecompositionInterface) maxon::EntityUse(ConvexDecompositionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexdecomposition/convexdecomposition.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ConvexDecompositionInterface(ConvexDecompositionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexdecomposition/convexdecomposition.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

