
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* UrlFileCacheEntryInterface::PrivateGetCppName() { return "maxon::UrlFileCacheEntry"; }

struct UrlFileCacheEntryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(UrlFileCacheEntryInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const UrlFileCacheEntryInterface* object);
	PRIVATE_MAXON_MF_POINTER(UrlFileCacheEntryInterface_GetSourceUrl, GetSourceUrl, false, UrlFileCacheEntryInterface, const, (Url));
	PRIVATE_MAXON_MF_POINTER(UrlFileCacheEntryInterface_GetCacheUrl, GetCacheUrl, false, UrlFileCacheEntryInterface, const, (Url));
	template <typename IMPL> void Init()
	{
		UrlFileCacheEntryInterface_Free = UrlFileCacheEntryInterface_Free_GetPtr<IMPL>(true);
		UrlFileCacheEntryInterface_GetSourceUrl = UrlFileCacheEntryInterface_GetSourceUrl_GetPtr<IMPL>(0, true).first;
		UrlFileCacheEntryInterface_GetCacheUrl = UrlFileCacheEntryInterface_GetCacheUrl_GetPtr<IMPL>(0, true).first;
	}
};

struct UrlFileCacheEntryInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void UrlFileCacheEntryInterface_Free(const UrlFileCacheEntryInterface* object) { return S::Free(object); }
		PRIVATE_MAXON_MF_WRAPPER(UrlFileCacheEntryInterface_GetSourceUrl, UrlFileCacheEntryInterface, const, (Url)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlFileCacheEntryInterface))->GetSourceUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlFileCacheEntryInterface_GetCacheUrl, UrlFileCacheEntryInterface, const, (Url)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlFileCacheEntryInterface))->GetCacheUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Free(const UrlFileCacheEntryInterface* object) -> void
{
	return MTable::_instance.UrlFileCacheEntryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetSourceUrl() const -> Url
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlFileCacheEntryInterface_GetSourceUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetCacheUrl() const -> Url
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlFileCacheEntryInterface_GetCacheUrl);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstFn<S>::GetSourceUrl() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlFileCacheEntryInterface_GetSourceUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstFn<S>::GetCacheUrl() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlFileCacheEntryInterface_GetCacheUrl));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_urlfile_cache)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UrlFileCacheEntryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UrlFileCacheEntryInterface() { new (s_ui_maxon_UrlFileCacheEntryInterface) maxon::EntityUse(UrlFileCacheEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UrlFileCacheEntryInterface(UrlFileCacheEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* UrlFileCacheInterface::PrivateGetCppName() { return nullptr; }

struct UrlFileCacheInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(UrlFileCacheInterface_IsAccessible, IsAccessible, MAXON_EXPAND_VA_ARGS, (Bool), const maxon::Url& url);
	PRIVATE_MAXON_SF_POINTER(UrlFileCacheInterface_FindOrCreateUrl, FindOrCreateUrl, MAXON_EXPAND_VA_ARGS, (Result<UrlFileCacheEntry>), const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags);
	PRIVATE_MAXON_SF_POINTER(UrlFileCacheInterface_FlushCache, FlushCache, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& url);
	template <typename IMPL> void Init()
	{
		UrlFileCacheInterface_IsAccessible = UrlFileCacheInterface_IsAccessible_GetPtr<IMPL>(true);
		UrlFileCacheInterface_FindOrCreateUrl = UrlFileCacheInterface_FindOrCreateUrl_GetPtr<IMPL>(true);
		UrlFileCacheInterface_FlushCache = UrlFileCacheInterface_FlushCache_GetPtr<IMPL>(true);
	}
};

struct UrlFileCacheInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Bool UrlFileCacheInterface_IsAccessible(const maxon::Url& url) { return S::IsAccessible(url); }
		static Result<UrlFileCacheEntry> UrlFileCacheInterface_FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) { return S::FindOrCreateUrl(sourceUrl, maxCacheTime, flags); }
		static Result<void> UrlFileCacheInterface_FlushCache(const Url& url) { return S::FlushCache(url); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::IsAccessible(const maxon::Url& url) -> Bool
{
	return MTable::_instance.UrlFileCacheInterface_IsAccessible(url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) -> Result<UrlFileCacheEntry>
{
	return MTable::_instance.UrlFileCacheInterface_FindOrCreateUrl(sourceUrl, maxCacheTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::FlushCache(const Url& url) -> Result<void>
{
	return MTable::_instance.UrlFileCacheInterface_FlushCache(url);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_urlfile_cache)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UrlFileCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UrlFileCacheInterface() { new (s_ui_maxon_UrlFileCacheInterface) maxon::EntityUse(UrlFileCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UrlFileCacheInterface(UrlFileCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

