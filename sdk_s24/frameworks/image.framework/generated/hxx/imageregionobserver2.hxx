
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
	Result<void> (*_ImageRegionObserverInterface_OnConnect) (maxon::GenericComponent* this_, const IntVector2d& dimensions);
	maxon::Int _ImageRegionObserverInterface_OnConnect_Offset;
	void (*_ImageRegionObserverInterface_OnResize) (maxon::GenericComponent* this_, const IntVector2d& dimensions);
	maxon::Int _ImageRegionObserverInterface_OnResize_Offset;
	void (*_ImageRegionObserverInterface_OnRegionDirty) (maxon::GenericComponent* this_, const Range<IntVector2d>& dirtyRegion);
	maxon::Int _ImageRegionObserverInterface_OnRegionDirty_Offset;
	void (*_ImageRegionObserverInterface_OnDisconnect) (maxon::GenericComponent* this_);
	maxon::Int _ImageRegionObserverInterface_OnDisconnect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnConnect))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnConnect), W, MTable>::type::_ImageRegionObserverInterface_OnConnect;
		_ImageRegionObserverInterface_OnConnect = reinterpret_cast<const decltype(_ImageRegionObserverInterface_OnConnect)&>(ptr);
		_ImageRegionObserverInterface_OnConnect_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnResize))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnResize), W, MTable>::type::_ImageRegionObserverInterface_OnResize;
		_ImageRegionObserverInterface_OnResize = reinterpret_cast<const decltype(_ImageRegionObserverInterface_OnResize)&>(ptr);
		_ImageRegionObserverInterface_OnResize_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnRegionDirty))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnRegionDirty), W, MTable>::type::_ImageRegionObserverInterface_OnRegionDirty;
		_ImageRegionObserverInterface_OnRegionDirty = reinterpret_cast<const decltype(_ImageRegionObserverInterface_OnRegionDirty)&>(ptr);
		_ImageRegionObserverInterface_OnRegionDirty_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnDisconnect))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnDisconnect), W, MTable>::type::_ImageRegionObserverInterface_OnDisconnect;
		_ImageRegionObserverInterface_OnDisconnect = reinterpret_cast<const decltype(_ImageRegionObserverInterface_OnDisconnect)&>(ptr);
		_ImageRegionObserverInterface_OnDisconnect_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
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
		static Result<void> _ImageRegionObserverInterface_OnConnect(maxon::GenericComponent* this_, const IntVector2d& dimensions) { return ((typename S::Implementation*) this_)->OnConnect(dimensions); }
		static void _ImageRegionObserverInterface_OnResize(maxon::GenericComponent* this_, const IntVector2d& dimensions) { return ((typename S::Implementation*) this_)->OnResize(dimensions); }
		static void _ImageRegionObserverInterface_OnRegionDirty(maxon::GenericComponent* this_, const Range<IntVector2d>& dirtyRegion) { return ((typename S::Implementation*) this_)->OnRegionDirty(dirtyRegion); }
		static void _ImageRegionObserverInterface_OnDisconnect(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->OnDisconnect(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_._ImageRegionObserverInterface_OnConnect((maxon::GenericComponent*) this + mt_._ImageRegionObserverInterface_OnConnect_Offset, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnResize(const IntVector2d& dimensions) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_._ImageRegionObserverInterface_OnResize((maxon::GenericComponent*) this + mt_._ImageRegionObserverInterface_OnResize_Offset, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_._ImageRegionObserverInterface_OnRegionDirty((maxon::GenericComponent*) this + mt_._ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnDisconnect() -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return mt_._ImageRegionObserverInterface_OnDisconnect((maxon::GenericComponent*) this + mt_._ImageRegionObserverInterface_OnDisconnect_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::ReferenceFunctionsImpl<S>::OnConnect(const IntVector2d& dimensions) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnConnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	return (mt_._ImageRegionObserverInterface_OnConnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnConnect_Offset, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWReferenceFunctionsImpl<S>::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnConnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	return (mt_._ImageRegionObserverInterface_OnConnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnConnect_Offset, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::ReferenceFunctionsImpl<S>::OnResize(const IntVector2d& dimensions) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnResize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnResize(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnResize_Offset, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWReferenceFunctionsImpl<S>::OnResize(const IntVector2d& dimensions) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnResize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnResize(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnResize_Offset, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::ReferenceFunctionsImpl<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnRegionDirty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnRegionDirty(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWReferenceFunctionsImpl<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnRegionDirty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnRegionDirty(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnRegionDirty_Offset, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::ReferenceFunctionsImpl<S>::OnDisconnect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnDisconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnDisconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnDisconnect_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWReferenceFunctionsImpl<S>::OnDisconnect() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObserverInterface* o_ = (ImageRegionObserverInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageRegionObserverInterface, o_, ImageRegionObserverInterface_OnDisconnect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageRegionObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageRegionObserverInterface>() : PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, o_); 
	mt_._ImageRegionObserverInterface_OnDisconnect(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ImageRegionObserverInterface_OnDisconnect_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ImageRegionObserverInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageRegionObserverInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	void (*_ImageRegionObservableInterface_Free) (const ImageRegionObservableInterface* object);
	Result<GenericData> (*_ImageRegionObservableInterface_RegisterObserver) (ImageRegionObservableInterface* this_, const Id& observerId, const ImageRegionObserverRef& observer);
	template <typename IMPL> void Init()
	{
		_ImageRegionObservableInterface_Free = &IMPL::_ImageRegionObservableInterface_Free;
		_ImageRegionObservableInterface_RegisterObserver = &IMPL::_ImageRegionObservableInterface_RegisterObserver;
	}
};

struct ImageRegionObservableInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _ImageRegionObservableInterface_Free(const ImageRegionObservableInterface* object) { return C::Free(object); }
		static Result<GenericData> _ImageRegionObservableInterface_RegisterObserver(ImageRegionObservableInterface* this_, const Id& observerId, const ImageRegionObserverRef& observer) { return C::Get(this_)->RegisterObserver(observerId, observer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Free(const ImageRegionObservableInterface* object) -> void
{
	return MTable::_instance._ImageRegionObservableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) -> Result<GenericData>
{
	return MTable::_instance._ImageRegionObservableInterface_RegisterObserver(this, observerId, observer);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Hxx1::ReferenceFunctionsImpl<S>::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) const -> Result<GenericData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableInterface* o_ = (ImageRegionObservableInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ImageRegionObservableInterface_RegisterObserver(o_, observerId, observer));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	Result<ImageRegionObservableHandlerRef> (*_ImageRegionObservableHandlerInterface_Create) (const IntVector2d& dimensions);
	Result<void> (*_ImageRegionObservableHandlerInterface_ResizeImage) (ImageRegionObservableHandlerInterface* this_, const IntVector2d& dimensions);
	Result<void> (*_ImageRegionObservableHandlerInterface_MarkDirty) (ImageRegionObservableHandlerInterface* this_, const Range<IntVector2d>& dirtyRegion);
	Result<ImageRegionObservableRef> (*_ImageRegionObservableHandlerInterface_GetObservable) (ImageRegionObservableHandlerInterface* this_);
	template <typename IMPL> void Init()
	{
		_ImageRegionObservableHandlerInterface_Create = &IMPL::_ImageRegionObservableHandlerInterface_Create;
		_ImageRegionObservableHandlerInterface_ResizeImage = &IMPL::_ImageRegionObservableHandlerInterface_ResizeImage;
		_ImageRegionObservableHandlerInterface_MarkDirty = &IMPL::_ImageRegionObservableHandlerInterface_MarkDirty;
		_ImageRegionObservableHandlerInterface_GetObservable = &IMPL::_ImageRegionObservableHandlerInterface_GetObservable;
	}
};

struct ImageRegionObservableHandlerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public ImageRegionObservableInterface::Hxx2::Wrapper<C>
	{
	public:
		static Result<ImageRegionObservableHandlerRef> _ImageRegionObservableHandlerInterface_Create(const IntVector2d& dimensions) { return C::Create(dimensions); }
		static Result<void> _ImageRegionObservableHandlerInterface_ResizeImage(ImageRegionObservableHandlerInterface* this_, const IntVector2d& dimensions) { return C::Get(this_)->ResizeImage(dimensions); }
		static Result<void> _ImageRegionObservableHandlerInterface_MarkDirty(ImageRegionObservableHandlerInterface* this_, const Range<IntVector2d>& dirtyRegion) { return C::Get(this_)->MarkDirty(dirtyRegion); }
		static Result<ImageRegionObservableRef> _ImageRegionObservableHandlerInterface_GetObservable(ImageRegionObservableHandlerInterface* this_) { return C::Get(this_)->GetObservable(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Free(const ImageRegionObservableHandlerInterface* object) -> void
{
	return BaseInterface::MTable::_instance._ImageRegionObservableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef>
{
	return MTable::_instance._ImageRegionObservableHandlerInterface_Create(dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::ResizeImage(const IntVector2d& dimensions) -> Result<void>
{
	return MTable::_instance._ImageRegionObservableHandlerInterface_ResizeImage(this, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::MarkDirty(const Range<IntVector2d>& dirtyRegion) -> Result<void>
{
	return MTable::_instance._ImageRegionObservableHandlerInterface_MarkDirty(this, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::GetObservable() -> Result<ImageRegionObservableRef>
{
	return MTable::_instance._ImageRegionObservableHandlerInterface_GetObservable(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef> { return (MTable::_instance._ImageRegionObservableHandlerInterface_Create(dimensions)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ReferenceFunctionsImpl<S>::ResizeImage(const IntVector2d& dimensions) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ImageRegionObservableHandlerInterface_ResizeImage(o_, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ReferenceFunctionsImpl<S>::MarkDirty(const Range<IntVector2d>& dirtyRegion) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ImageRegionObservableHandlerInterface_MarkDirty(o_, dirtyRegion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ReferenceFunctionsImpl<S>::GetObservable() const -> Result<ImageRegionObservableRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ImageRegionObservableRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ImageRegionObservableHandlerInterface* o_ = (ImageRegionObservableHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ImageRegionObservableHandlerInterface_GetObservable(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

