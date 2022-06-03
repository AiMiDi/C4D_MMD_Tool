
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImageRegionObserverInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OnConnect);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OnDisconnect);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OnRegionDirty);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OnResize);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ImageRegionObserverInterface_OnConnect) (maxon::GenericComponent* this_, const IntVector2d& dimensions);
	maxon::Int ImageRegionObserverInterface_OnConnect_Offset;
	void (*ImageRegionObserverInterface_OnResize) (maxon::GenericComponent* this_, const IntVector2d& dimensions);
	maxon::Int ImageRegionObserverInterface_OnResize_Offset;
	void (*ImageRegionObserverInterface_OnRegionDirty) (maxon::GenericComponent* this_, const Range<IntVector2d>& dirtyRegion);
	maxon::Int ImageRegionObserverInterface_OnRegionDirty_Offset;
	void (*ImageRegionObserverInterface_OnDisconnect) (maxon::GenericComponent* this_);
	maxon::Int ImageRegionObserverInterface_OnDisconnect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnConnect))
	{
		ImageRegionObserverInterface_OnConnect = &W::ImageRegionObserverInterface_OnConnect;
		ImageRegionObserverInterface_OnConnect_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnResize))
	{
		ImageRegionObserverInterface_OnResize = &W::ImageRegionObserverInterface_OnResize;
		ImageRegionObserverInterface_OnResize_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnRegionDirty))
	{
		ImageRegionObserverInterface_OnRegionDirty = &W::ImageRegionObserverInterface_OnRegionDirty;
		ImageRegionObserverInterface_OnRegionDirty_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnDisconnect))
	{
		ImageRegionObserverInterface_OnDisconnect = &W::ImageRegionObserverInterface_OnDisconnect;
		ImageRegionObserverInterface_OnDisconnect_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageRegionObserverInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageRegionObserverInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageRegionObserverInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OnConnect);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OnDisconnect);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OnRegionDirty);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OnResize);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImageRegionObserverInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageRegionObserverInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ImageRegionObserverInterface_OnConnect(maxon::GenericComponent* this_, const IntVector2d& dimensions) { return ((typename S::Implementation*) this_)->OnConnect(dimensions); }
		static void ImageRegionObserverInterface_OnResize(maxon::GenericComponent* this_, const IntVector2d& dimensions) { return ((typename S::Implementation*) this_)->OnResize(dimensions); }
		static void ImageRegionObserverInterface_OnRegionDirty(maxon::GenericComponent* this_, const Range<IntVector2d>& dirtyRegion) { return ((typename S::Implementation*) this_)->OnRegionDirty(dirtyRegion); }
		static void ImageRegionObserverInterface_OnDisconnect(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->OnDisconnect(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_.ImageRegionObserverInterface_OnConnect((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnConnect_Offset, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnResize(const IntVector2d& dimensions) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_.ImageRegionObserverInterface_OnResize((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnResize_Offset, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_.ImageRegionObserverInterface_OnRegionDirty((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnDisconnect() -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_.ImageRegionObserverInterface_OnDisconnect((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnDisconnect_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnConnect(const IntVector2d& dimensions) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnConnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	return (mt_.ImageRegionObserverInterface_OnConnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnConnect_Offset, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnConnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	return (mt_.ImageRegionObserverInterface_OnConnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnConnect_Offset, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnResize(const IntVector2d& dimensions) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnResize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnResize(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnResize_Offset, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnResize(const IntVector2d& dimensions) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnResize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnResize(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnResize_Offset, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnRegionDirty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnRegionDirty(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnRegionDirty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnRegionDirty(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnDisconnect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnDisconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnDisconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnDisconnect_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnDisconnect() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnDisconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_.ImageRegionObserverInterface_OnDisconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnDisconnect_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ImageRegionObserverInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageRegionObserverInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageregionobserver)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageRegionObserverInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageRegionObserverInterface() { new (s_ui_maxon_ImageRegionObserverInterface) maxon::EntityUse(ImageRegionObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageRegionObserverInterface(ImageRegionObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ImageRegionObservableInterface::PrivateGetCppName() { return "maxon::ImageRegionObservableRef"; }

struct ImageRegionObservableInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*ImageRegionObservableInterface_Free) (const ImageRegionObservableInterface* object);
	Result<GenericData> (*ImageRegionObservableInterface_RegisterObserver) (ImageRegionObservableInterface* this_, const Id& observerId, const ImageRegionObserverRef& observer);
	template <typename IMPL> void Init()
	{
		ImageRegionObservableInterface_Free = &IMPL::ImageRegionObservableInterface_Free;
		ImageRegionObservableInterface_RegisterObserver = &IMPL::ImageRegionObservableInterface_RegisterObserver;
	}
};

struct ImageRegionObservableInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ImageRegionObservableInterface_Free(const ImageRegionObservableInterface* object) { return C::Free(object); }
		static Result<GenericData> ImageRegionObservableInterface_RegisterObserver(ImageRegionObservableInterface* this_, const Id& observerId, const ImageRegionObserverRef& observer) { return C::Get(this_)->RegisterObserver(observerId, observer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Free(const ImageRegionObservableInterface* object) -> void
{
	return MTable::_instance.ImageRegionObservableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) -> Result<GenericData>
{
	return MTable::_instance.ImageRegionObservableInterface_RegisterObserver(this, observerId, observer);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Hxx1::Fn<S>::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) const -> Result<GenericData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableInterface* o_ = (ImageRegionObservableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ImageRegionObservableInterface_RegisterObserver(o_, observerId, observer));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageregionobserver)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageRegionObservableInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageRegionObservableInterface() { new (s_ui_maxon_ImageRegionObservableInterface) maxon::EntityUse(ImageRegionObservableInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageRegionObservableInterface(ImageRegionObservableInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ImageRegionObservableHandlerInterface::PrivateGetCppName() { return "maxon::ImageRegionObservableHandlerRef"; }

struct ImageRegionObservableHandlerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	Result<ImageRegionObservableHandlerRef> (*ImageRegionObservableHandlerInterface_Create) (const IntVector2d& dimensions);
	Result<void> (*ImageRegionObservableHandlerInterface_ResizeImage) (ImageRegionObservableHandlerInterface* this_, const IntVector2d& dimensions);
	Result<void> (*ImageRegionObservableHandlerInterface_MarkDirty) (ImageRegionObservableHandlerInterface* this_, const Range<IntVector2d>& dirtyRegion);
	Result<ImageRegionObservableRef> (*ImageRegionObservableHandlerInterface_GetObservable) (ImageRegionObservableHandlerInterface* this_);
	template <typename IMPL> void Init()
	{
		ImageRegionObservableHandlerInterface_Create = &IMPL::ImageRegionObservableHandlerInterface_Create;
		ImageRegionObservableHandlerInterface_ResizeImage = &IMPL::ImageRegionObservableHandlerInterface_ResizeImage;
		ImageRegionObservableHandlerInterface_MarkDirty = &IMPL::ImageRegionObservableHandlerInterface_MarkDirty;
		ImageRegionObservableHandlerInterface_GetObservable = &IMPL::ImageRegionObservableHandlerInterface_GetObservable;
	}
};

struct ImageRegionObservableHandlerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public ImageRegionObservableInterface::Hxx2::Wrapper<C>
	{
	public:
		static Result<ImageRegionObservableHandlerRef> ImageRegionObservableHandlerInterface_Create(const IntVector2d& dimensions) { return C::Create(dimensions); }
		static Result<void> ImageRegionObservableHandlerInterface_ResizeImage(ImageRegionObservableHandlerInterface* this_, const IntVector2d& dimensions) { return C::Get(this_)->ResizeImage(dimensions); }
		static Result<void> ImageRegionObservableHandlerInterface_MarkDirty(ImageRegionObservableHandlerInterface* this_, const Range<IntVector2d>& dirtyRegion) { return C::Get(this_)->MarkDirty(dirtyRegion); }
		static Result<ImageRegionObservableRef> ImageRegionObservableHandlerInterface_GetObservable(ImageRegionObservableHandlerInterface* this_) { return C::Get(this_)->GetObservable(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Free(const ImageRegionObservableHandlerInterface* object) -> void
{
	return BaseInterface::MTable::_instance.ImageRegionObservableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef>
{
	return MTable::_instance.ImageRegionObservableHandlerInterface_Create(dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::ResizeImage(const IntVector2d& dimensions) -> Result<void>
{
	return MTable::_instance.ImageRegionObservableHandlerInterface_ResizeImage(this, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::MarkDirty(const Range<IntVector2d>& dirtyRegion) -> Result<void>
{
	return MTable::_instance.ImageRegionObservableHandlerInterface_MarkDirty(this, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::GetObservable() -> Result<ImageRegionObservableRef>
{
	return MTable::_instance.ImageRegionObservableHandlerInterface_GetObservable(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ConstFn<S>::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef>
{
	return (MTable::_instance.ImageRegionObservableHandlerInterface_Create(dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::ResizeImage(const IntVector2d& dimensions) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ImageRegionObservableHandlerInterface_ResizeImage(o_, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::MarkDirty(const Range<IntVector2d>& dirtyRegion) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ImageRegionObservableHandlerInterface_MarkDirty(o_, dirtyRegion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::GetObservable() const -> Result<ImageRegionObservableRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ImageRegionObservableRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ImageRegionObservableHandlerInterface_GetObservable(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageregionobserver)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageRegionObservableHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageRegionObservableHandlerInterface() { new (s_ui_maxon_ImageRegionObservableHandlerInterface) maxon::EntityUse(ImageRegionObservableHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageRegionObservableHandlerInterface(ImageRegionObservableHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageregionobserver.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

