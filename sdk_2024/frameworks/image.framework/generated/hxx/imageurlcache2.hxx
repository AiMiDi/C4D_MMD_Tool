
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImageUrlCacheInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetImage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableFreeCache);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ImageUrlCacheInterface_ObservableFreeCache, ObservableFreeCache, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableFreeCacheDelegate>), Bool create);
	maxon::Int ImageUrlCacheInterface_ObservableFreeCache_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageUrlCacheInterface_GetImage, GetImage, true, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate);
	maxon::Int ImageUrlCacheInterface_GetImage_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageUrlCacheInterface_GetImage_1, GetImage, true, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate, Bool async);
	maxon::Int ImageUrlCacheInterface_GetImage_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, ObservableFreeCache))
	{
		maxon::Tie(ImageUrlCacheInterface_ObservableFreeCache, ImageUrlCacheInterface_ObservableFreeCache_Offset) = ImageUrlCacheInterface_ObservableFreeCache_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, GetImage))
	{
		maxon::Tie(ImageUrlCacheInterface_GetImage, ImageUrlCacheInterface_GetImage_Offset) = ImageUrlCacheInterface_GetImage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, GetImage))
	{
		maxon::Tie(ImageUrlCacheInterface_GetImage_1, ImageUrlCacheInterface_GetImage_1_Offset) = ImageUrlCacheInterface_GetImage_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImageUrlCacheInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImageUrlCacheInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImageUrlCacheInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(ImageUrlCacheInterface_InvalidateCache, InvalidateCache, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& url);
	PRIVATE_MAXON_SF_POINTER(ImageUrlCacheInterface_FindOrCreate, FindOrCreate, MAXON_EXPAND_VA_ARGS, (Result<ImageUrlCacheRef>), const Url& url);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->ImageUrlCacheInterface_InvalidateCache = ImageUrlCacheInterface_InvalidateCache_GetPtr<IMPL>(true);
		tbl->ImageUrlCacheInterface_FindOrCreate = ImageUrlCacheInterface_FindOrCreate_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetImage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableFreeCache);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImageUrlCacheInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageUrlCacheInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ImageUrlCacheInterface_InvalidateCache(const Url& url) { return S::Implementation::InvalidateCache(url); }
		static Result<ImageUrlCacheRef> ImageUrlCacheInterface_FindOrCreate(const Url& url) { return S::Implementation::FindOrCreate(url); }
		PRIVATE_MAXON_MF_WRAPPER(ImageUrlCacheInterface_ObservableFreeCache, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableFreeCacheDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableFreeCache(create); }
		PRIVATE_MAXON_MF_WRAPPER(ImageUrlCacheInterface_GetImage, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetImage(std::forward<UpdateCacheDelegate>(updateDelegate)); }
		PRIVATE_MAXON_MF_WRAPPER(ImageUrlCacheInterface_GetImage_1, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate, Bool async) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetImage(std::forward<UpdateCacheDelegate>(updateDelegate), async); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::InvalidateCache(const Url& url) -> Result<void>
{
	return Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_InvalidateCache(url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::FindOrCreate(const Url& url) -> Result<ImageUrlCacheRef>
{
	return Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_FindOrCreate(url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::ObservableFreeCache(Bool create) const -> maxon::ObservableRef<ObservableFreeCacheDelegate>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset), mt_.ImageUrlCacheInterface_ObservableFreeCache, create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_GetImage_Offset), mt_.ImageUrlCacheInterface_GetImage, std::forward<UpdateCacheDelegate>(updateDelegate));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const -> Result<Opt<ImageBaseRef>>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_GetImage_1_Offset), mt_.ImageUrlCacheInterface_GetImage_1, std::forward<UpdateCacheDelegate>(updateDelegate), async);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::InvalidateCache(const Url& url) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_InvalidateCache(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::FindOrCreate(const Url& url) -> Result<ImageUrlCacheRef>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_FindOrCreate(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::ObservableFreeCache(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableFreeCacheDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableFreeCacheDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableFreeCacheDelegate>::DefaultValue()) HXXTABLE(ImageUrlCacheInterface_ObservableFreeCache); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset), mt_.ImageUrlCacheInterface_ObservableFreeCache, create));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	HXXRETURN0(Result<Opt<ImageBaseRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageUrlCacheInterface_GetImage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_Offset), mt_.ImageUrlCacheInterface_GetImage, std::forward<UpdateCacheDelegate>(updateDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const -> Result<Opt<ImageBaseRef>>
{
	HXXRETURN0(Result<Opt<ImageBaseRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ImageUrlCacheInterface_GetImage_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_1_Offset), mt_.ImageUrlCacheInterface_GetImage_1, std::forward<UpdateCacheDelegate>(updateDelegate), async));
}
auto ImageUrlCacheInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImageUrlCacheInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageurlcache)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImageUrlCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImageUrlCacheInterface() { new (s_ui_maxon_ImageUrlCacheInterface) maxon::EntityUse(ImageUrlCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageurlcache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImageUrlCacheInterface(ImageUrlCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/imageurlcache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_imageurlcache)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_ImageUrlCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_ImageUrlCacheInterface() { new (s_usi_maxon_ImageUrlCacheInterface) maxon::EntityUse(ImageUrlCacheInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/imageurlcache.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_ImageUrlCacheInterface(ImageUrlCacheInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/imageurlcache.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

