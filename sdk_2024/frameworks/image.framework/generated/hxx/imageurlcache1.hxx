#if 1
class ImageUrlCacheRef;

struct ImageUrlCacheInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageUrlCacheInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ImageUrlCacheInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImageUrlCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageUrlCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ImageUrlCacheInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ImageUrlCacheInterface**);
		using UpdateCacheDelegate = ImageUrlCacheInterface::UpdateCacheDelegate;
/// InvalidateCache invalidates and removed the image from the cache. The next request will reload the image.
/// @param[in] url								Image to discard from the cache.
/// @return                       OK on success.
		static inline Result<void> InvalidateCache(const Url& url);
/// FindOrCreate returns the cache for the requested image resource.
/// @param[in] url								Url of the image to load.
/// @return                       Cache on success.
		static inline Result<ImageUrlCacheRef> FindOrCreate(const Url& url);
		inline HXXADDRET2(maxon::ObservableRef<ObservableFreeCacheDelegate>) ObservableFreeCache(Bool create) const;
/// GetImage returns the image from the cache, if there is one. If nullptr then the image is 
/// still loading. In that case the delegate is triggered once the image is loaded.
/// @param[in] updateDelegate			Delegate which is called once the image is loaded.
/// @return                       Image or nullptr on success.
		inline Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const;
/// GetImage returns the image from the cache, if there is one. If nullptr then the image is
/// still loading. In that case the delegate is triggered once the image is loaded.
/// @param[in] updateDelegate			Delegate which is called once the image is loaded.
/// @param[in] async							Use false to force synchronous loading, by default loading is asynchronous.
/// @return                       Image or nullptr on success.
		inline Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const;
	};
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ImageUrlCacheInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ImageUrlCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageUrlCacheRef, true>::type&() const { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageUrlCacheRef, false>::type&() { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ImageUrlCacheInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ImageUrlCacheInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ImageUrlCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageUrlCacheRef, false>::type&() { return reinterpret_cast<const ImageUrlCacheRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ImageUrlCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ImageUrlCacheRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImageUrlCacheInterface, maxon::StrongRefHandler, ImageUrlCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImageUrlCacheInterface, maxon::StrongRefHandler, ImageUrlCacheRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageUrlCacheRef is the reference class of ImageUrlCacheInterface.
///
/// Cache class to allow delayed load of images with notification when it's ready to display.
/// Multiple requests are combined (the first request loads the image and notifies all others)
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
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

#endif
