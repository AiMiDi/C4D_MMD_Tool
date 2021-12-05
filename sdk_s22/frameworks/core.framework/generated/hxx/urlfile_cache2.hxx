
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct UrlFileCacheEntryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_UrlFileCacheEntryInterface_Free) (const UrlFileCacheEntryInterface* object);
	Url (*_UrlFileCacheEntryInterface_GetSourceUrl) (const UrlFileCacheEntryInterface* this_);
	Url (*_UrlFileCacheEntryInterface_GetCacheUrl) (const UrlFileCacheEntryInterface* this_);
	template <typename IMPL> void Init()
	{
		_UrlFileCacheEntryInterface_Free = &IMPL::_UrlFileCacheEntryInterface_Free;
		_UrlFileCacheEntryInterface_GetSourceUrl = &IMPL::_UrlFileCacheEntryInterface_GetSourceUrl;
		_UrlFileCacheEntryInterface_GetCacheUrl = &IMPL::_UrlFileCacheEntryInterface_GetCacheUrl;
	}
};

struct UrlFileCacheEntryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _UrlFileCacheEntryInterface_Free(const UrlFileCacheEntryInterface* object) { return C::Free(object); }
	static Url _UrlFileCacheEntryInterface_GetSourceUrl(const UrlFileCacheEntryInterface* this_) { return ((const C*) this_)->GetSourceUrl(); }
	static Url _UrlFileCacheEntryInterface_GetCacheUrl(const UrlFileCacheEntryInterface* this_) { return ((const C*) this_)->GetCacheUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Free(const UrlFileCacheEntryInterface* object) -> void
{
	return MTable::_instance._UrlFileCacheEntryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetSourceUrl() const -> Url
{
	return MTable::_instance._UrlFileCacheEntryInterface_GetSourceUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::GetCacheUrl() const -> Url
{
	return MTable::_instance._UrlFileCacheEntryInterface_GetCacheUrl(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSourceUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlFileCacheEntryInterface* o_ = (const UrlFileCacheEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlFileCacheEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlFileCacheEntryInterface_GetSourceUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheEntryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCacheUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlFileCacheEntryInterface* o_ = (const UrlFileCacheEntryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlFileCacheEntryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlFileCacheEntryInterface_GetCacheUrl(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UrlFileCacheEntryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UrlFileCacheEntryInterface() { new (s_ui_maxon_UrlFileCacheEntryInterface) maxon::EntityUse(UrlFileCacheEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UrlFileCacheEntryInterface(UrlFileCacheEntryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/urlfile_cache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UrlFileCacheInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_UrlFileCacheInterface_IsAccessible) (const maxon::Url& url);
	Result<UrlFileCacheEntry> (*_UrlFileCacheInterface_FindOrCreateUrl) (const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags);
	Result<void> (*_UrlFileCacheInterface_FlushCache) (const Url& url);
	template <typename IMPL> void Init()
	{
		_UrlFileCacheInterface_IsAccessible = &IMPL::_UrlFileCacheInterface_IsAccessible;
		_UrlFileCacheInterface_FindOrCreateUrl = &IMPL::_UrlFileCacheInterface_FindOrCreateUrl;
		_UrlFileCacheInterface_FlushCache = &IMPL::_UrlFileCacheInterface_FlushCache;
	}
};

struct UrlFileCacheInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Bool _UrlFileCacheInterface_IsAccessible(const maxon::Url& url) { return C::IsAccessible(url); }
	static Result<UrlFileCacheEntry> _UrlFileCacheInterface_FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) { return C::FindOrCreateUrl(sourceUrl, maxCacheTime, flags); }
	static Result<void> _UrlFileCacheInterface_FlushCache(const Url& url) { return C::FlushCache(url); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::IsAccessible(const maxon::Url& url) -> Bool
{
	return MTable::_instance._UrlFileCacheInterface_IsAccessible(url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::FindOrCreateUrl(const Url& sourceUrl, const TimeValue& maxCacheTime, URLFILECACHEFLAGS flags) -> Result<UrlFileCacheEntry>
{
	return MTable::_instance._UrlFileCacheInterface_FindOrCreateUrl(sourceUrl, maxCacheTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlFileCacheInterface::FlushCache(const Url& url) -> Result<void>
{
	return MTable::_instance._UrlFileCacheInterface_FlushCache(url);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

