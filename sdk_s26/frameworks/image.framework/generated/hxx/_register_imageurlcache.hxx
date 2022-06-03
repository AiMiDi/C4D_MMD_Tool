#if 1
namespace maxon
{
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageUrlCacheInterface::Hxx2::Unresolved : public ImageUrlCacheInterface
	{
	public:
		static Result<void> InvalidateCache(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImageUrlCacheInterface::InvalidateCache(url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<ImageUrlCacheRef> FindOrCreate(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImageUrlCacheInterface::FindOrCreate(url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ImageUrlCacheInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<ImageUrlCacheRef>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageUrlCacheInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ImageUrlCacheInterface_InvalidateCache = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_InvalidateCache;
		#else
		tbl->ImageUrlCacheInterface_InvalidateCache = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_InvalidateCache;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ImageUrlCacheRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ImageUrlCacheInterface_FindOrCreate = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_FindOrCreate;
		#else
		tbl->ImageUrlCacheInterface_FindOrCreate = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_FindOrCreate;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ImageUrlCacheInterface::MTable::_ids = 
		"GetImageRef@8b987e1d0039cde\0" // Result<ImageBaseRef> GetImageRef(UpdateCacheDelegate&& updateDelegate) const
		"ObservableFreeCache@12d4e0d094da122d\0" // maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache() const
		"GetImage@3282da2cd20f6087\0" // Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const
	"";
	const maxon::METHOD_FLAGS ImageUrlCacheInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageUrlCacheInterface, , "net.maxon.image.interface.imageurlcache", "maxon.ImageUrlCacheInterface", (ObserverObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ImageUrlCacheInterface::Hxx2::StaticMTable::_ids = 
		"InvalidateCache@683e18fe1711316e\0" // Result<void> InvalidateCache(const Url& url)
		"FindOrCreate@1f307e16168c488f\0" // Result<ImageUrlCacheRef> FindOrCreate(const Url& url)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ImageUrlCacheInterface, , "net.maxon.image.interface.imageurlcache");
}
#endif
