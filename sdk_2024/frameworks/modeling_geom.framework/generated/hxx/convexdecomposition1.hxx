#if 1
class ConvexDecompositionRef;

struct ConvexDecompositionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ConvexDecompositionInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ConvexDecompositionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ConvexDecompositionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ConvexDecompositionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ConvexDecompositionInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ConvexDecompositionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ConvexDecompositionInterface**);
		inline Result<DataDictionary> GetSettings() const;
/// Get the current status of the decomposition job.
/// @return true if the decomposition is complete
		inline HXXADDRET2(Bool) IsReady() const;
/// Get the current progress of the decomposition job.
/// @return percentage completed
		inline Result<UInt16> GetProgress() const;
	};
	/// Intermediate helper class for ConvexDecompositionInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ConvexDecompositionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ConvexDecompositionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexDecompositionRef, true>::type&() const { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexDecompositionRef, false>::type&() { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
/// Initialize the convex decomposition library.
/// @param levelOfDetail	desired level of detail to retail in the decomposition.
///												Allowed values are between 0 and 1. Recommended 0.5.
/// @param maxVoxelCount	Maximum number of voxels used to decompose the bounding box
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(Float levelOfDetail = 0.5, UInt32 maxVoxelCount = 16000000) const;
/// Initialize the convex decomposition library with the given settings.
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(const DataDictionary& settings) const;
/// Compute convex decomposition. By default this is done asynchronously. To be called after Init().
/// @param geometryObject	geometry object to decompose
		inline Result<void> Compute(const GeometryObject& geometryObject) const;
/// Fetch results of the decomposition. In case the decomposition job is not done, wait for the results to be available.
/// To be called after Compute().
/// @return		An array of geometry objects where each entry represents one of the convex
///						hulls the original object was decomposed into.
		inline Result<Array<GeometryObject>> FetchResults() const;
/// Cancel the decomposition job
		inline Result<void> Cancel() const;
		inline Result<void> Clear() const;
	};
	/// Intermediate helper class for ConvexDecompositionInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ConvexDecompositionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ConvexDecompositionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ConvexDecompositionRef, false>::type&() { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
/// Initialize the convex decomposition library.
/// @param levelOfDetail	desired level of detail to retail in the decomposition.
///												Allowed values are between 0 and 1. Recommended 0.5.
/// @param maxVoxelCount	Maximum number of voxels used to decompose the bounding box
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(Float levelOfDetail = 0.5, UInt32 maxVoxelCount = 16000000);
/// Initialize the convex decomposition library with the given settings.
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(const DataDictionary& settings);
/// Compute convex decomposition. By default this is done asynchronously. To be called after Init().
/// @param geometryObject	geometry object to decompose
		inline Result<void> Compute(const GeometryObject& geometryObject);
/// Fetch results of the decomposition. In case the decomposition job is not done, wait for the results to be available.
/// To be called after Compute().
/// @return		An array of geometry objects where each entry represents one of the convex
///						hulls the original object was decomposed into.
		inline Result<Array<GeometryObject>> FetchResults();
/// Cancel the decomposition job
		inline Result<void> Cancel();
		inline Result<void> Clear();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ConvexDecompositionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ConvexDecompositionRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ConvexDecompositionInterface, maxon::StrongRefHandler, ConvexDecompositionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ConvexDecompositionInterface, maxon::StrongRefHandler, ConvexDecompositionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ConvexDecompositionRef is the reference class of ConvexDecompositionInterface.
class ConvexDecompositionRef : public ConvexDecompositionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ConvexDecompositionRef, typename ConvexDecompositionInterface::Hxx1::Reference);
	using ConstPtr = typename ConvexDecompositionInterface::ConstPtr;
};

#endif
