
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImageRegionTilesObserverInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetAndResetDirtyState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ImageRegionTilesObserverInterface_Init) (maxon::GenericComponent* this_, Int tileSize);
	maxon::Int ImageRegionTilesObserverInterface_Init_Offset;
	Result<void> (*ImageRegionTilesObserverInterface_GetAndResetDirtyState) (maxon::GenericComponent* this_, DirtyState& dirtyState);
	maxon::Int ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionTilesObserverInterface, Init))
	{
		ImageRegionTilesObserverInterface_Init = &W::ImageRegionTilesObserverInterface_Init;
		ImageRegionTilesObserverInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionTilesObserverInterface, GetAndResetDirtyState))
	{
		ImageRegionTilesObserverInterface_GetAndResetDirtyState = &W::ImageRegionTilesObserverInterface_GetAndResetDirtyState;
		ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageRegionTilesObserverInterface, typename ImageRegionObserverInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageRegionTilesObserverInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageRegionTilesObserverInterface::Hxx2
{
	template <typename S> class CWrapper : public ImageRegionObserverInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAndResetDirtyState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImageRegionObserverInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImageRegionTilesObserverInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageRegionTilesObserverInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ImageRegionTilesObserverInterface_Init(maxon::GenericComponent* this_, Int tileSize) { return ((typename S::Implementation*) this_)->Init(tileSize); }
		static Result<void> ImageRegionTilesObserverInterface_GetAndResetDirtyState(maxon::GenericComponent* this_, DirtyState& dirtyState) { return ((typename S::Implementation*) this_)->GetAndResetDirtyState(dirtyState); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::Init(Int tileSize) -> Result<void>
{
	const ImageRegionTilesObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, this); return mt_.ImageRegionTilesObserverInterface_Init((maxon::GenericComponent*) this + mt_.ImageRegionTilesObserverInterface_Init_Offset, tileSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::GetAndResetDirtyState(DirtyState& dirtyState) -> Result<void>
{
	const ImageRegionTilesObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, this); return mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState((maxon::GenericComponent*) this + mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset, dirtyState);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::Hxx1::Fn<S>::Init(Int tileSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionTilesObserverInterface* o_ = (ImageRegionTilesObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionTilesObserverInterface, o_, ImageRegionTilesObserverInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionTilesObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionTilesObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, o_); 
	return (mt_.ImageRegionTilesObserverInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_Init_Offset, tileSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::Hxx1::COWFn<S>::Init(Int tileSize) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionTilesObserverInterface* o_ = (ImageRegionTilesObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionTilesObserverInterface, o_, ImageRegionTilesObserverInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionTilesObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionTilesObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, o_); 
	return (mt_.ImageRegionTilesObserverInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_Init_Offset, tileSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::Hxx1::Fn<S>::GetAndResetDirtyState(DirtyState& dirtyState) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionTilesObserverInterface* o_ = (ImageRegionTilesObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionTilesObserverInterface, o_, ImageRegionTilesObserverInterface_GetAndResetDirtyState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionTilesObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionTilesObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, o_); 
	return (mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset, dirtyState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionTilesObserverInterface::Hxx1::COWFn<S>::GetAndResetDirtyState(DirtyState& dirtyState) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionTilesObserverInterface* o_ = (ImageRegionTilesObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionTilesObserverInterface, o_, ImageRegionTilesObserverInterface_GetAndResetDirtyState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionTilesObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionTilesObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionTilesObserverInterface, o_); 
	return (mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionTilesObserverInterface_GetAndResetDirtyState_Offset, dirtyState));
}
auto ImageRegionTilesObserverInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageRegionTilesObserverInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageregionobserver_helpers)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageRegionTilesObserverInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageRegionTilesObserverInterface() { new (s_ui_maxon_ImageRegionTilesObserverInterface) maxon::EntityUse(ImageRegionTilesObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver_helpers.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageRegionTilesObserverInterface(ImageRegionTilesObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver_helpers.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

