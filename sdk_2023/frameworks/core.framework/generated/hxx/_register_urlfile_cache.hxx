#if 1
namespace maxon
{
	namespace enum21
	{
		enum class URLFILECACHEFLAGS
		{
			NONE				 = 0,
			FORCE_RELOAD = 1 << 0 ///< Reloads the file from the sourceUrl, a new cache file will be created. The previous cache file will stay until
														///  older UrlFileCacheEntries disappear.
		} ;
		static const maxon::UInt64 URLFILECACHEFLAGS_values[] = {maxon::UInt64(enum21::URLFILECACHEFLAGS::NONE), maxon::UInt64(enum21::URLFILECACHEFLAGS::FORCE_RELOAD)};
		static const maxon::EnumInfo URLFILECACHEFLAGS_info{"URLFILECACHEFLAGS", SIZEOF(URLFILECACHEFLAGS), true, "NONE\0FORCE_RELOAD\0", URLFILECACHEFLAGS_values, std::extent<decltype(URLFILECACHEFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_URLFILECACHEFLAGS21(){ return enum21::URLFILECACHEFLAGS_info; }
	const maxon::Char* const UrlFileCacheEntryInterface::MTable::_ids = 
		"Free@a427a0b56c64c3f6\0" // void Free(const UrlFileCacheEntryInterface* object)
		"GetSourceUrl@f0cc56ca89511da7\0" // Url GetSourceUrl() const
		"GetCacheUrl@f0cc56ca89511da7\0" // Url GetCacheUrl() const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UrlFileCacheEntryInterface::Hxx2::Unresolved : public UrlFileCacheEntryInterface
	{
	public:
		static const Unresolved* Get(const UrlFileCacheEntryInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UrlFileCacheEntryInterface* o) { return (Unresolved*) o; }
		static void Free(const UrlFileCacheEntryInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UrlFileCacheEntryInterface::Free(object); return maxon::PrivateLogNullptrError();}
		Url GetSourceUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlFileCacheEntryInterface*) this)->GetSourceUrl(); return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Url GetCacheUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlFileCacheEntryInterface*) this)->GetCacheUrl(); return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UrlFileCacheEntryInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Url>::value,
		maxon::details::NullReturnType<Url>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UrlFileCacheEntryInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlFileCacheEntryInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheEntryInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheEntryInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UrlFileCacheEntryInterface_GetSourceUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheEntryInterface_GetSourceUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheEntryInterface_GetSourceUrl);
		#else
		tbl->UrlFileCacheEntryInterface_GetSourceUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheEntryInterface_GetSourceUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheEntryInterface_GetSourceUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UrlFileCacheEntryInterface_GetCacheUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheEntryInterface_GetCacheUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheEntryInterface_GetCacheUrl);
		#else
		tbl->UrlFileCacheEntryInterface_GetCacheUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheEntryInterface_GetCacheUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheEntryInterface_GetCacheUrl);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UrlFileCacheEntryInterface, "net.maxon.interface.urlfilecacheentry", nullptr);
	template <typename DUMMY> maxon::Int UrlFileCacheEntryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const UrlFileCacheInterface::MTable::_ids = 
		"IsAccessible@d58731fc475afca4\0" // Bool IsAccessible(const maxon::Url& url)
		"FindOrCreateUrl@32dc392ba6338b2e\0" // Result<UrlFileCacheEntry> FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags)
		"FlushCache@683e18fe1711316e\0" // Result<void> FlushCache(const Url& url)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UrlFileCacheInterface::Hxx2::Unresolved : public UrlFileCacheInterface
	{
	public:
		static const Unresolved* Get(const UrlFileCacheInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UrlFileCacheInterface* o) { return (Unresolved*) o; }
		static Bool IsAccessible(const maxon::Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UrlFileCacheInterface::IsAccessible(url); return maxon::PrivateLogNullptrError(false);}
		static Result<UrlFileCacheEntry> FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UrlFileCacheInterface::FindOrCreateUrl(sourceUrl, maxCacheTime, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> FlushCache(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UrlFileCacheInterface::FlushCache(url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UrlFileCacheInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<UrlFileCacheEntry>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UrlFileCacheInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlFileCacheInterface_IsAccessible = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheInterface_IsAccessible), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheInterface_IsAccessible);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<UrlFileCacheEntry>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UrlFileCacheInterface_FindOrCreateUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheInterface_FindOrCreateUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheInterface_FindOrCreateUrl);
		#else
		tbl->UrlFileCacheInterface_FindOrCreateUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheInterface_FindOrCreateUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheInterface_FindOrCreateUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UrlFileCacheInterface_FlushCache = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheInterface_FlushCache), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheInterface_FlushCache);
		#else
		tbl->UrlFileCacheInterface_FlushCache = PRIVATE_MAXON_MF_CAST(decltype(UrlFileCacheInterface_FlushCache), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlFileCacheInterface_FlushCache);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UrlFileCacheInterface, "net.maxon.interface.urlfilecache", nullptr);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_urlfile_cache(0
	| maxon::UrlFileCacheEntryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
