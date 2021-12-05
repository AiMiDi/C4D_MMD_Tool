#if 1
namespace maxon
{
	namespace enum21 { enum class URLFILECACHEFLAGS
	{
		NONE				 = 0,
		FORCE_RELOAD = 1 << 0 ///< Reloads the file from the sourceUrl, a new cache file will be created. The previous cache file will stay until
													///  older UrlFileCacheEntries disappear.
	} ; }
	maxon::String PrivateToString_URLFILECACHEFLAGS21(std::underlying_type<enum21::URLFILECACHEFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::URLFILECACHEFLAGS::NONE, (maxon::UInt64) enum21::URLFILECACHEFLAGS::FORCE_RELOAD};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "URLFILECACHEFLAGS", SIZEOF(x), true, values, "NONE\0FORCE_RELOAD\0", fmt);
	}
	const maxon::Char* const UrlFileCacheEntryInterface::MTable::_ids = 
		"Free@ce3c1a22d7282a43\0" // void Free(const UrlFileCacheEntryInterface* object)
		"GetSourceUrl@4e33a06\0" // Url GetSourceUrl() const
		"GetCacheUrl@4e33a06\0" // Url GetCacheUrl() const
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
		tbl->_UrlFileCacheEntryInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheEntryInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlFileCacheEntryInterface_GetSourceUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheEntryInterface_GetSourceUrl;
		#else
		tbl->_UrlFileCacheEntryInterface_GetSourceUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheEntryInterface_GetSourceUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlFileCacheEntryInterface_GetCacheUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheEntryInterface_GetCacheUrl;
		#else
		tbl->_UrlFileCacheEntryInterface_GetCacheUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheEntryInterface_GetCacheUrl;
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
		"IsAccessible@1aeaf711b704ef1f\0" // Bool IsAccessible(const maxon::Url& url)
		"FindOrCreateUrl@b336bfba983c7ac9\0" // Result<UrlFileCacheEntry> FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags)
		"FlushCache@5b3e46c920933bb7\0" // Result<void> FlushCache(const Url& url)
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
		tbl->_UrlFileCacheInterface_IsAccessible = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheInterface_IsAccessible;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<UrlFileCacheEntry>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlFileCacheInterface_FindOrCreateUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheInterface_FindOrCreateUrl;
		#else
		tbl->_UrlFileCacheInterface_FindOrCreateUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheInterface_FindOrCreateUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlFileCacheInterface_FlushCache = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheInterface_FlushCache;
		#else
		tbl->_UrlFileCacheInterface_FlushCache = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlFileCacheInterface_FlushCache;
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
