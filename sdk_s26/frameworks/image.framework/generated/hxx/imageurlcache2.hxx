
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetImageRef);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableFreeCache);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<ImageBaseRef> (*ImageUrlCacheInterface_GetImageRef) (const maxon::GenericComponent* this_, UpdateCacheDelegate&& updateDelegate);
	maxon::Int ImageUrlCacheInterface_GetImageRef_Offset;
	maxon::ObservableRef<ObservableFreeCacheDelegate> (*ImageUrlCacheInterface_ObservableFreeCache) (const maxon::GenericComponent* this_);
	maxon::Int ImageUrlCacheInterface_ObservableFreeCache_Offset;
	Result<Opt<ImageBaseRef>> (*ImageUrlCacheInterface_GetImage) (const maxon::GenericComponent* this_, UpdateCacheDelegate&& updateDelegate);
	maxon::Int ImageUrlCacheInterface_GetImage_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, GetImageRef))
	{
		ImageUrlCacheInterface_GetImageRef = &W::ImageUrlCacheInterface_GetImageRef;
		ImageUrlCacheInterface_GetImageRef_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, ObservableFreeCache))
	{
		ImageUrlCacheInterface_ObservableFreeCache = &W::ImageUrlCacheInterface_ObservableFreeCache;
		ImageUrlCacheInterface_ObservableFreeCache_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ImageUrlCacheInterface, GetImage))
	{
		ImageUrlCacheInterface_GetImage = &W::ImageUrlCacheInterface_GetImage;
		ImageUrlCacheInterface_GetImage_Offset = offset;
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
	Result<void> (*ImageUrlCacheInterface_InvalidateCache) (const Url& url);
	Result<ImageUrlCacheRef> (*ImageUrlCacheInterface_FindOrCreate) (const Url& url);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->ImageUrlCacheInterface_InvalidateCache = &IMPL::ImageUrlCacheInterface_InvalidateCache;
		tbl->ImageUrlCacheInterface_FindOrCreate = &IMPL::ImageUrlCacheInterface_FindOrCreate;
		}
	};
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetImage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetImageRef);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableFreeCache);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ImageUrlCacheInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImageUrlCacheInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ImageUrlCacheInterface_InvalidateCache(const Url& url) { return S::Implementation::InvalidateCache(url); }
		static Result<ImageUrlCacheRef> ImageUrlCacheInterface_FindOrCreate(const Url& url) { return S::Implementation::FindOrCreate(url); }
		static Result<ImageBaseRef> ImageUrlCacheInterface_GetImageRef(const maxon::GenericComponent* this_, UpdateCacheDelegate&& updateDelegate) { return ((const typename S::Implementation*) this_)->GetImageRef(std::forward<UpdateCacheDelegate>(updateDelegate)); }
		static maxon::ObservableRef<ObservableFreeCacheDelegate> ImageUrlCacheInterface_ObservableFreeCache(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableFreeCache(); }
		static Result<Opt<ImageBaseRef>> ImageUrlCacheInterface_GetImage(const maxon::GenericComponent* this_, UpdateCacheDelegate&& updateDelegate) { return ((const typename S::Implementation*) this_)->GetImage(std::forward<UpdateCacheDelegate>(updateDelegate)); }
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
[[deprecated]] MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::GetImageRef(UpdateCacheDelegate&& updateDelegate) const -> Result<ImageBaseRef>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return mt_.ImageUrlCacheInterface_GetImageRef((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_GetImageRef_Offset, std::forward<UpdateCacheDelegate>(updateDelegate));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::ObservableFreeCache() const -> maxon::ObservableRef<ObservableFreeCacheDelegate>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return mt_.ImageUrlCacheInterface_ObservableFreeCache((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	const ImageUrlCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, this); return mt_.ImageUrlCacheInterface_GetImage((const maxon::GenericComponent*) this + mt_.ImageUrlCacheInterface_GetImage_Offset, std::forward<UpdateCacheDelegate>(updateDelegate));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::InvalidateCache(const Url& url) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_InvalidateCache(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::FindOrCreate(const Url& url) -> Result<ImageUrlCacheRef>
{
	return (Hxx2::StaticMTable::_instance.ImageUrlCacheInterface_FindOrCreate(url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::GetImageRef(UpdateCacheDelegate&& updateDelegate) const -> Result<ImageBaseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ImageBaseRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageUrlCacheInterface* o_ = (const ImageUrlCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageUrlCacheInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageUrlCacheInterface, o_, ImageUrlCacheInterface_GetImageRef) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageUrlCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageUrlCacheInterface>() : PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, o_); 
	return (mt_.ImageUrlCacheInterface_GetImageRef(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImageRef_Offset, std::forward<UpdateCacheDelegate>(updateDelegate)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::ObservableFreeCache() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableFreeCacheDelegate>>, maxon::ObservableRef<ObservableFreeCacheDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableFreeCacheDelegate>>, maxon::ObservableRef<ObservableFreeCacheDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageUrlCacheInterface* o_ = (const ImageUrlCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageUrlCacheInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableFreeCacheDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageUrlCacheInterface, o_, ImageUrlCacheInterface_ObservableFreeCache) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageUrlCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageUrlCacheInterface>() : PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, o_); 
	return (mt_.ImageUrlCacheInterface_ObservableFreeCache(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_ObservableFreeCache_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ImageUrlCacheInterface::Hxx1::ConstFn<S>::GetImage(UpdateCacheDelegate&& updateDelegate) const -> Result<Opt<ImageBaseRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Opt<ImageBaseRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ImageUrlCacheInterface* o_ = (const ImageUrlCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ImageUrlCacheInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ImageUrlCacheInterface, o_, ImageUrlCacheInterface_GetImage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ImageUrlCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ImageUrlCacheInterface>() : PRIVATE_MAXON_VTABLE(ImageUrlCacheInterface, o_); 
	return (mt_.ImageUrlCacheInterface_GetImage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ImageUrlCacheInterface_GetImage_Offset, std::forward<UpdateCacheDelegate>(updateDelegate)));
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

