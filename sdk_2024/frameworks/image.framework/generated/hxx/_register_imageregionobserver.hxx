#if 1
namespace maxon
{
	const maxon::Char* const ImageRegionObserverInterface::MTable::_ids = 
		"OnConnect@658d129dd5e12bfe\0" // Result<void> OnConnect(const IntVector2d& dimensions)
		"OnResize@1fe0e39ccb514b0f\0" // void OnResize(const IntVector2d& dimensions)
		"OnRegionDirty@3c67a64c26917eaa\0" // void OnRegionDirty(const Range<IntVector2d>& dirtyRegion)
		"OnDisconnect@780cdac8f1a33934\0" // void OnDisconnect()
	"";
	const maxon::METHOD_FLAGS ImageRegionObserverInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageRegionObserverInterface, , "net.maxon.nodes.interface.imageregionobserver", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ImageRegionObservableInterface::MTable::_ids = 
		"Free@770e839bbcacca05\0" // void Free(const ImageRegionObservableInterface* object)
		"RegisterObserver@3a42bda268d35a6d\0" // Result<GenericData> RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageRegionObservableInterface::Hxx2::Unresolved : public ImageRegionObservableInterface
	{
	public:
		static const Unresolved* Get(const ImageRegionObservableInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ImageRegionObservableInterface* o) { return (Unresolved*) o; }
		static void Free(const ImageRegionObservableInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ImageRegionObservableInterface::Free(object); return maxon::PrivateLogNullptrError();}
		Result<GenericData> RegisterObserver(const Id& observerId, const ImageRegionObserverRef& observer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ImageRegionObservableInterface*) this)->RegisterObserver(observerId, observer); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ImageRegionObservableInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<Result<GenericData>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageRegionObservableInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ImageRegionObservableInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<GenericData>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageRegionObservableInterface_RegisterObserver = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableInterface_RegisterObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableInterface_RegisterObserver);
		#else
		tbl->ImageRegionObservableInterface_RegisterObserver = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableInterface_RegisterObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableInterface_RegisterObserver);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ImageRegionObservableInterface, "net.maxon.interface.imageregionobservable", nullptr, maxon::EntityBase::FLAGS::NONE);
	const maxon::Char* const ImageRegionObservableHandlerInterface::MTable::_ids = 
		"Create@dbb8e085a8e4d2e5\0" // Result<ImageRegionObservableHandlerRef> Create(const IntVector2d& dimensions)
		"ResizeImage@c6d1bdbadbe59183\0" // Result<void> ResizeImage(const IntVector2d& dimensions)
		"MarkDirty@abaa6a904f16c22e\0" // Result<void> MarkDirty(const Range<IntVector2d>& dirtyRegion)
		"GetObservable@bdd33a4e6b2eefdb\0" // Result<ImageRegionObservableRef> GetObservable()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageRegionObservableHandlerInterface::Hxx2::Unresolved : public ImageRegionObservableInterface::Hxx2::Unresolved
	{
	public:
		operator const ImageRegionObservableHandlerInterface&() const { return *static_cast<const ImageRegionObservableHandlerInterface*>(static_cast<const BaseInterface*>(this)); }
		operator ImageRegionObservableHandlerInterface&() { return *static_cast<ImageRegionObservableHandlerInterface*>(static_cast<BaseInterface*>(this)); }
		static const Unresolved* Get(const ImageRegionObservableHandlerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ImageRegionObservableHandlerInterface* o) { return (Unresolved*) o; }
		static Result<ImageRegionObservableHandlerRef> Create(const IntVector2d& dimensions) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ImageRegionObservableHandlerInterface::Create(dimensions); return HXXRET1(UNRESOLVED);}
		Result<void> ResizeImage(const IntVector2d& dimensions) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ImageRegionObservableHandlerInterface*) this)->ResizeImage(dimensions); return HXXRET1(UNRESOLVED);}
		Result<void> MarkDirty(const Range<IntVector2d>& dirtyRegion) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ImageRegionObservableHandlerInterface*) this)->MarkDirty(dirtyRegion); return HXXRET1(UNRESOLVED);}
		Result<ImageRegionObservableRef> GetObservable() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ImageRegionObservableHandlerInterface*) this)->GetObservable(); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ImageRegionObservableHandlerInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<ImageRegionObservableHandlerRef>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<ImageRegionObservableRef>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageRegionObservableHandlerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ImageRegionObservableHandlerRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageRegionObservableHandlerInterface_Create = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_Create);
		#else
		tbl->ImageRegionObservableHandlerInterface_Create = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_Create);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageRegionObservableHandlerInterface_ResizeImage = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_ResizeImage), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_ResizeImage);
		#else
		tbl->ImageRegionObservableHandlerInterface_ResizeImage = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_ResizeImage), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_ResizeImage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageRegionObservableHandlerInterface_MarkDirty = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_MarkDirty), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_MarkDirty);
		#else
		tbl->ImageRegionObservableHandlerInterface_MarkDirty = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_MarkDirty), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_MarkDirty);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ImageRegionObservableRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageRegionObservableHandlerInterface_GetObservable = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_GetObservable), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_GetObservable);
		#else
		tbl->ImageRegionObservableHandlerInterface_GetObservable = PRIVATE_MAXON_MF_CAST(decltype(ImageRegionObservableHandlerInterface_GetObservable), &Hxx2::Wrapper<Hxx2::Unresolved>::ImageRegionObservableHandlerInterface_GetObservable);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ImageRegionObservableHandlerInterface, "net.maxon.interface.imageregionobservablehandler", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
