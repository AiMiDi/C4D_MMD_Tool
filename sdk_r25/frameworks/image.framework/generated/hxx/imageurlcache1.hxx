#if 1
class ImageUrlCacheRef;

struct ImageUrlCacheInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageUrlCacheInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ImageUrlCacheInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImageUrlCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageUrlCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using UpdateCacheDelegate = ImageUrlCacheInterface::UpdateCacheDelegate;
		static inline Result<void> InvalidateCache(const Url& url);
		static inline Result<ImageUrlCacheRef> FindOrCreate(const Url& url);
		inline Result<ImageBaseRef> GetImageRef(UpdateCacheDelegate&& updateDelegate) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableFreeCacheDelegate>>, maxon::ObservableRef<ObservableFreeCacheDelegate>>::type ObservableFreeCache() const;
	};
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageUrlCacheRef, true>::type&() const { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageUrlCacheRef, false>::type&() { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageUrlCacheRef, false>::type&() { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class ImageUrlCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ImageUrlCacheRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageUrlCacheInterface, maxon::StrongRefHandler, ImageUrlCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageUrlCacheInterface, maxon::StrongRefHandler, ImageUrlCacheRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageUrlCacheRef is the reference class of ImageUrlCacheInterface.
class ImageUrlCacheRef : public ImageUrlCacheInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageUrlCacheRef, typename ImageUrlCacheInterface::Hxx1::Reference);
	using ConstPtr = typename ImageUrlCacheInterface::ConstPtr;
};

class ImageUrlCacheInterface::ObservableFreeCacheDelegate : public maxon::Delegate<void(const Url&)>
{
public:
	using Super = maxon::Delegate<void(const Url&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleFreeCache);
	ObservableFreeCacheDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleFreeCache<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleFreeCache); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleFreeCache<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
