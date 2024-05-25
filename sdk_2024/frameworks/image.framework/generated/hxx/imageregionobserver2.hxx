
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
	PRIVATE_MAXON_MF_POINTER(ImageRegionObserverInterface_OnConnect, OnConnect, true, maxon::GenericComponent,, (Result<void>), const IntVector2d& dimensions);
	maxon::Int ImageRegionObserverInterface_OnConnect_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageRegionObserverInterface_OnResize, OnResize, true, maxon::GenericComponent,, (void), const IntVector2d& dimensions);
	maxon::Int ImageRegionObserverInterface_OnResize_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageRegionObserverInterface_OnRegionDirty, OnRegionDirty, true, maxon::GenericComponent,, (void), const Range<IntVector2d>& dirtyRegion);
	maxon::Int ImageRegionObserverInterface_OnRegionDirty_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageRegionObserverInterface_OnDisconnect, OnDisconnect, true, maxon::GenericComponent,, (void));
	maxon::Int ImageRegionObserverInterface_OnDisconnect_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnConnect))
	{
		maxon::Tie(ImageRegionObserverInterface_OnConnect, ImageRegionObserverInterface_OnConnect_Offset) = ImageRegionObserverInterface_OnConnect_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnResize))
	{
		maxon::Tie(ImageRegionObserverInterface_OnResize, ImageRegionObserverInterface_OnResize_Offset) = ImageRegionObserverInterface_OnResize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnRegionDirty))
	{
		maxon::Tie(ImageRegionObserverInterface_OnRegionDirty, ImageRegionObserverInterface_OnRegionDirty_Offset) = ImageRegionObserverInterface_OnRegionDirty_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageRegionObserverInterface, OnDisconnect))
	{
		maxon::Tie(ImageRegionObserverInterface_OnDisconnect, ImageRegionObserverInterface_OnDisconnect_Offset) = ImageRegionObserverInterface_OnDisconnect_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageRegionObserverInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageRegionObserverInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageRegionObserverInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObserverInterface_OnConnect, maxon::GenericComponent,, (Result<void>), const IntVector2d& dimensions) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OnConnect(dimensions); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObserverInterface_OnResize, maxon::GenericComponent,, (void), const IntVector2d& dimensions) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OnResize(dimensions); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObserverInterface_OnRegionDirty, maxon::GenericComponent,, (void), const Range<IntVector2d>& dirtyRegion) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OnRegionDirty(dirtyRegion); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObserverInterface_OnDisconnect, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OnDisconnect(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnConnect_Offset), mt_.ImageRegionObserverInterface_OnConnect, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnResize(const IntVector2d& dimensions) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnResize_Offset), mt_.ImageRegionObserverInterface_OnResize, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset), mt_.ImageRegionObserverInterface_OnRegionDirty, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::OnDisconnect() -> void
{
	const ImageRegionObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageRegionObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ImageRegionObserverInterface_OnDisconnect_Offset), mt_.ImageRegionObserverInterface_OnDisconnect);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnConnect(const IntVector2d& dimensions) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ImageRegionObserverInterface_OnConnect); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnConnect_Offset), mt_.ImageRegionObserverInterface_OnConnect, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnConnect(const IntVector2d& dimensions) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageRegionObserverInterface_OnConnect); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnConnect_Offset), mt_.ImageRegionObserverInterface_OnConnect, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnResize(const IntVector2d& dimensions) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ImageRegionObserverInterface_OnResize); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnResize_Offset), mt_.ImageRegionObserverInterface_OnResize, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnResize(const IntVector2d& dimensions) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageRegionObserverInterface_OnResize); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnResize_Offset), mt_.ImageRegionObserverInterface_OnResize, dimensions);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ImageRegionObserverInterface_OnRegionDirty); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset), mt_.ImageRegionObserverInterface_OnRegionDirty, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnRegionDirty(const Range<IntVector2d>& dirtyRegion) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageRegionObserverInterface_OnRegionDirty); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnRegionDirty_Offset), mt_.ImageRegionObserverInterface_OnRegionDirty, dirtyRegion);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::Fn<S>::OnDisconnect() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ImageRegionObserverInterface_OnDisconnect); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnDisconnect_Offset), mt_.ImageRegionObserverInterface_OnDisconnect);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObserverInterface::Hxx1::COWFn<S>::OnDisconnect() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ImageRegionObserverInterface_OnDisconnect); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ImageRegionObserverInterface_OnDisconnect_Offset), mt_.ImageRegionObserverInterface_OnDisconnect);
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(ImageRegionObservableInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ImageRegionObservableInterface* object);
	PRIVATE_MAXON_MF_POINTER(ImageRegionObservableInterface_RegisterObserver, RegisterObserver, false, ImageRegionObservableInterface,, (Result<GenericData>), const Id& observerId, const ImageRegionObserverRef& observer);
	template <typename IMPL> void Init()
	{
		ImageRegionObservableInterface_Free = ImageRegionObservableInterface_Free_GetPtr<IMPL>(true);
		ImageRegionObservableInterface_RegisterObserver = ImageRegionObservableInterface_RegisterObserver_GetPtr<IMPL>(0, true).first;
	}
};

struct ImageRegionObservableInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void ImageRegionObservableInterface_Free(const ImageRegionObservableInterface* object) { return S::Free(object); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObservableInterface_RegisterObserver, ImageRegionObservableInterface,, (Result<GenericData>), const Id& observerId, const ImageRegionObserverRef& observer) { return S::Get(PRIVATE_MAXON_MF_THIS(ImageRegionObservableInterface))->RegisterObserver(observerId, observer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Free(const ImageRegionObservableInterface* object) -> void
{
	return MTable::_instance.ImageRegionObservableInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) -> Result<GenericData>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ImageRegionObservableInterface_RegisterObserver, observerId, observer);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableInterface::Hxx1::Fn<S>::RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) const -> Result<GenericData>
{
	HXXRETURN0(Result<GenericData>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ImageRegionObservableInterface_RegisterObserver, observerId, observer));
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(ImageRegionObservableHandlerInterface_Create, Create, MAXON_EXPAND_VA_ARGS, (Result<ImageRegionObservableHandlerRef>), const IntVector2d& dimensions);
	PRIVATE_MAXON_MF_POINTER(ImageRegionObservableHandlerInterface_ResizeImage, ResizeImage, false, ImageRegionObservableHandlerInterface,, (Result<void>), const IntVector2d& dimensions);
	PRIVATE_MAXON_MF_POINTER(ImageRegionObservableHandlerInterface_MarkDirty, MarkDirty, false, ImageRegionObservableHandlerInterface,, (Result<void>), const Range<IntVector2d>& dirtyRegion);
	PRIVATE_MAXON_MF_POINTER(ImageRegionObservableHandlerInterface_GetObservable, GetObservable, false, ImageRegionObservableHandlerInterface,, (Result<ImageRegionObservableRef>));
	template <typename IMPL> void Init()
	{
		ImageRegionObservableHandlerInterface_Create = ImageRegionObservableHandlerInterface_Create_GetPtr<IMPL>(true);
		ImageRegionObservableHandlerInterface_ResizeImage = ImageRegionObservableHandlerInterface_ResizeImage_GetPtr<IMPL>(0, true).first;
		ImageRegionObservableHandlerInterface_MarkDirty = ImageRegionObservableHandlerInterface_MarkDirty_GetPtr<IMPL>(0, true).first;
		ImageRegionObservableHandlerInterface_GetObservable = ImageRegionObservableHandlerInterface_GetObservable_GetPtr<IMPL>(0, true).first;
	}
};

struct ImageRegionObservableHandlerInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper : public ImageRegionObservableInterface::Hxx2::Wrapper<S>
	{
	public:
		static Result<ImageRegionObservableHandlerRef> ImageRegionObservableHandlerInterface_Create(const IntVector2d& dimensions) { return S::Create(dimensions); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObservableHandlerInterface_ResizeImage, ImageRegionObservableHandlerInterface,, (Result<void>), const IntVector2d& dimensions) { return S::Get(PRIVATE_MAXON_MF_THIS(ImageRegionObservableHandlerInterface))->ResizeImage(dimensions); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObservableHandlerInterface_MarkDirty, ImageRegionObservableHandlerInterface,, (Result<void>), const Range<IntVector2d>& dirtyRegion) { return S::Get(PRIVATE_MAXON_MF_THIS(ImageRegionObservableHandlerInterface))->MarkDirty(dirtyRegion); }
		PRIVATE_MAXON_MF_WRAPPER(ImageRegionObservableHandlerInterface_GetObservable, ImageRegionObservableHandlerInterface,, (Result<ImageRegionObservableRef>)) { return S::Get(PRIVATE_MAXON_MF_THIS(ImageRegionObservableHandlerInterface))->GetObservable(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef>
{
	return MTable::_instance.ImageRegionObservableHandlerInterface_Create(dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::ResizeImage(const IntVector2d& dimensions) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ImageRegionObservableHandlerInterface_ResizeImage, dimensions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::MarkDirty(const Range<IntVector2d>& dirtyRegion) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ImageRegionObservableHandlerInterface_MarkDirty, dirtyRegion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::GetObservable() -> Result<ImageRegionObservableRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ImageRegionObservableHandlerInterface_GetObservable);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::ConstFn<S>::Create(const IntVector2d& dimensions) -> Result<ImageRegionObservableHandlerRef>
{
	return (MTable::_instance.ImageRegionObservableHandlerInterface_Create(dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::ResizeImage(const IntVector2d& dimensions) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ImageRegionObservableHandlerInterface_ResizeImage, dimensions));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::MarkDirty(const Range<IntVector2d>& dirtyRegion) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ImageRegionObservableHandlerInterface_MarkDirty, dirtyRegion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageRegionObservableHandlerInterface::Hxx1::Fn<S>::GetObservable() const -> Result<ImageRegionObservableRef>
{
	HXXRETURN0(Result<ImageRegionObservableRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ImageRegionObservableHandlerInterface_GetObservable));
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

