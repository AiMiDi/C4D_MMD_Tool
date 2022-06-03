
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*UrlFileCacheEntryInterface_Free) (const UrlFileCacheEntryInterface* object);
	Url (*UrlFileCacheEntryInterface_GetSourceUrl) (const UrlFileCacheEntryInterface* this_);
	Url (*UrlFileCacheEntryInterface_GetCacheUrl) (const UrlFileCacheEntryInterface* this_);
	template <typename IMPL> void Init()
	{
		UrlFileCacheEntryInterface_Free = &IMPL::UrlFileCacheEntryInterface_Free;
		UrlFileCacheEntryInterface_GetSourceUrl = &IMPL::UrlFileCacheEntryInterface_GetSourceUrl;
		UrlFileCacheEntryInterface_GetCacheUrl = &IMPL::UrlFileCacheEntryInterface_GetCacheUrl;
	}
};

struct UrlFileCacheEntryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void UrlFileCacheEntryInterface_Free(const UrlFileCacheEntryInterface* object) { return C::Free(object); }
		static Url UrlFileCacheEntryInterface_GetSourceUrl(const UrlFileCacheEntryInterface* this_) { return C::Get(this_)->GetSourceUrl(); }
		static Url UrlFileCacheEntryInterface_GetCacheUrl(const UrlFileCacheEntryInterface* this_) { return C::Get(this_)->GetCacheUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Free(const UrlFileCacheEntryInterface* object) -> void
{
	return MTable::_instance.UrlFileCacheEntryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetSourceUrl() const -> Url
{
	return MTable::_instance.UrlFileCacheEntryInterface_GetSourceUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetCacheUrl() const -> Url
{
	return MTable::_instance.UrlFileCacheEntryInterface_GetCacheUrl(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstFn<S>::GetSourceUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlFileCacheEntryInterface* o_ = (const UrlFileCacheEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlFileCacheEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlFileCacheEntryInterface_GetSourceUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstFn<S>::GetCacheUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlFileCacheEntryInterface* o_ = (const UrlFileCacheEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlFileCacheEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlFileCacheEntryInterface_GetCacheUrl(o_));
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*UrlFileCacheInterface_IsAccessible) (const maxon::Url& url);
	Result<UrlFileCacheEntry> (*UrlFileCacheInterface_FindOrCreateUrl) (const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags);
	Result<void> (*UrlFileCacheInterface_FlushCache) (const Url& url);
	template <typename IMPL> void Init()
	{
		UrlFileCacheInterface_IsAccessible = &IMPL::UrlFileCacheInterface_IsAccessible;
		UrlFileCacheInterface_FindOrCreateUrl = &IMPL::UrlFileCacheInterface_FindOrCreateUrl;
		UrlFileCacheInterface_FlushCache = &IMPL::UrlFileCacheInterface_FlushCache;
	}
};

struct UrlFileCacheInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Bool UrlFileCacheInterface_IsAccessible(const maxon::Url& url) { return C::IsAccessible(url); }
		static Result<UrlFileCacheEntry> UrlFileCacheInterface_FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) { return C::FindOrCreateUrl(sourceUrl, maxCacheTime, flags); }
		static Result<void> UrlFileCacheInterface_FlushCache(const Url& url) { return C::FlushCache(url); }
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

