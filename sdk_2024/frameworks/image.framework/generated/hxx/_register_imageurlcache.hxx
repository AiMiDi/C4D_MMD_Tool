#if 1
namespace maxon
{
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ImageUrlCacheInterface::Hxx2::Unresolved : public ImageUrlCacheInterface
	{
	public:
		static Result<void> InvalidateCache(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImageUrlCacheInterface::InvalidateCache(url); return HXXRET1(UNRESOLVED);}
		static Result<ImageUrlCacheRef> FindOrCreate(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ImageUrlCacheInterface::FindOrCreate(url); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ImageUrlCacheInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<ImageUrlCacheRef>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ImageUrlCacheInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageUrlCacheInterface_InvalidateCache = PRIVATE_MAXON_MF_CAST(decltype(ImageUrlCacheInterface_InvalidateCache), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_InvalidateCache);
		#else
		tbl->ImageUrlCacheInterface_InvalidateCache = PRIVATE_MAXON_MF_CAST(decltype(ImageUrlCacheInterface_InvalidateCache), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_InvalidateCache);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ImageUrlCacheRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ImageUrlCacheInterface_FindOrCreate = PRIVATE_MAXON_MF_CAST(decltype(ImageUrlCacheInterface_FindOrCreate), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_FindOrCreate);
		#else
		tbl->ImageUrlCacheInterface_FindOrCreate = PRIVATE_MAXON_MF_CAST(decltype(ImageUrlCacheInterface_FindOrCreate), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ImageUrlCacheInterface_FindOrCreate);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (const void**) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ImageUrlCacheInterface::MTable::_ids = 
		"ObservableFreeCache@d88a55ad733be5e5\0" // maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache(Bool create) const
		"GetImage@3282da2cd20f6087\0" // Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const
		"GetImage@a6a43b44bcdc42d1\0" // Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const
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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageUrlCacheInterface, , "net.maxon.image.interface.imageurlcache", (ObserverObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ImageUrlCacheInterface::Hxx2::StaticMTable::_ids = 
		"InvalidateCache@683e18fe1711316e\0" // Result<void> InvalidateCache(const Url& url)
		"FindOrCreate@1f307e16168c488f\0" // Result<ImageUrlCacheRef> FindOrCreate(const Url& url)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ImageUrlCacheInterface, , "net.maxon.image.interface.imageurlcache");
}
#endif
