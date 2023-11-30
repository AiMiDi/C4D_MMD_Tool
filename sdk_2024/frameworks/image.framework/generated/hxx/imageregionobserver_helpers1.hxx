#if 1
class ImageRegionTilesObserverRef;

struct ImageRegionTilesObserverInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageRegionTilesObserverInterface>::value || ImageRegionObserverInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ImageRegionTilesObserverInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImageRegionTilesObserverInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageRegionTilesObserverRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageRegionObserverInterface>;
	/// Intermediate helper class for ImageRegionTilesObserverInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ImageRegionTilesObserverInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ImageRegionTilesObserverInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageRegionTilesObserverRef, true>::type&() const { return reinterpret_cast<const ImageRegionTilesObserverRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageRegionTilesObserverRef, false>::type&() { return reinterpret_cast<const ImageRegionTilesObserverRef&>(this->GetBaseRef()); }
/// Initializes the tile-based change tracking data structure. Each tile contains an AABB. The number of tiles is determined
/// as numTiles = ceil(imageWidth / tileSize) * ceil(imageHeight / tileSize).
/// We recommend reasonable power-of-two values such as 64, 128, 256, 512 or 1024.
/// @param[in] tileSize						The size of a tile in pixels.
/// @return												OK on success.
		inline Result<void> Init(Int tileSize) const;
/// Returns and resets the accumulated region changes in form of a set of non-overlapping tiles.
/// @param[out] dirtyState				The state to overwrite.
/// @return												OK on success.
		inline Result<void> GetAndResetDirtyState(DirtyState& dirtyState) const;
	};
	/// Intermediate helper class for ImageRegionTilesObserverInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ImageRegionTilesObserverInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ImageRegionTilesObserverInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageRegionTilesObserverRef, false>::type&() { return reinterpret_cast<const ImageRegionTilesObserverRef&>(this->GetBaseRef()); }
/// Initializes the tile-based change tracking data structure. Each tile contains an AABB. The number of tiles is determined
/// as numTiles = ceil(imageWidth / tileSize) * ceil(imageHeight / tileSize).
/// We recommend reasonable power-of-two values such as 64, 128, 256, 512 or 1024.
/// @param[in] tileSize						The size of a tile in pixels.
/// @return												OK on success.
		inline Result<void> Init(Int tileSize);
/// Returns and resets the accumulated region changes in form of a set of non-overlapping tiles.
/// @param[out] dirtyState				The state to overwrite.
/// @return												OK on success.
		inline Result<void> GetAndResetDirtyState(DirtyState& dirtyState);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ImageRegionObserverInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ImageRegionObserverInterface::Hxx1::template FnHelper<ST>::type, Fn<typename ImageRegionObserverInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ImageRegionTilesObserverInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ImageRegionTilesObserverRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImageRegionTilesObserverInterface, maxon::StrongRefHandler, ImageRegionTilesObserverRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImageRegionTilesObserverInterface, maxon::StrongRefHandler, ImageRegionTilesObserverRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageRegionTilesObserverRef is the reference class of ImageRegionTilesObserverInterface.
///
/// This interface extends the notifiers about regional image changes with accessors to the tile-based tracking data structure.
class ImageRegionTilesObserverRef : public ImageRegionTilesObserverInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageRegionTilesObserverRef, typename ImageRegionTilesObserverInterface::Hxx1::Reference);
	using ConstPtr = typename ImageRegionTilesObserverInterface::ConstPtr;
};

#endif
