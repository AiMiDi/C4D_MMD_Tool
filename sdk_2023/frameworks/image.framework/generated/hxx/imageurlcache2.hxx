
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
	PRIVATE_MAXON_MF_POINTER(ImageUrlCacheInterface_ObservableFreeCache, ObservableFreeCache, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableFreeCacheDelegate>));
	maxon::Int ImageUrlCacheInterface_ObservableFreeCache_Offset;
	PRIVATE_MAXON_MF_POINTER(ImageUrlCacheInterface_GetImage, GetImage, true, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate);
	maxon::Int ImageUrlCacheInterface_GetImage_Offset;
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
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ImageUrlCacheInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
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
		PRIVATE_MAXON_MF_WRAPPER(ImageUrlCacheInterface_ObservableFreeCache, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableFreeCacheDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableFreeCache(); }
		PRIVATE_MAXON_MF_WRAPPER(ImageUrlCacheInterface_GetImage, maxon::GenericComponent, const, (Result<Opt<ImageBaseRef>>), UpdateCacheDelegate&& updateDelegate) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetImage(std::forward<UpdateCacheDelegate>(updateDelegate)); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::ObservableFreeCache() const -> maxon::ObservableRef<ObservableFreeCacheDelegate>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset), mt_.ImageUrlCacheInterface_ObservableFreeCache);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_GetImage_Offset), mt_.ImageUrlCacheInterface_GetImage, std::forward<UpdateCacheDelegate>(updateDelegate));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::InvalidateCache(const Url& url) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_InvalidateCache(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::FindOrCreate(const Url& url) -> Result<ImageUrlCacheRef>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_FindOrCreate(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::ObservableFreeCache() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableFreeCacheDelegate>>, maxon::ObservableRef<ObservableFreeCacheDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableFreeCacheDelegate>>, maxon::ObservableRef<ObservableFreeCacheDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageUrlCacheInterface* o_ = (const ImageUrlCacheInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageUrlCacheInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableFreeCacheDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageUrlCacheInterface, o_, ImageUrlCacheInterface_ObservableFreeCache) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageUrlCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageUrlCacheInterface>() : PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset), mt_.ImageUrlCacheInterface_ObservableFreeCache));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Opt<ImageBaseRef>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ImageUrlCacheInterface* o_ = (const ImageUrlCacheInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ImageUrlCacheInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageUrlCacheInterface, o_, ImageUrlCacheInterface_GetImage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageUrlCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageUrlCacheInterface>() : PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_Offset), mt_.ImageUrlCacheInterface_GetImage, std::forward<UpdateCacheDelegate>(updateDelegate)));
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

