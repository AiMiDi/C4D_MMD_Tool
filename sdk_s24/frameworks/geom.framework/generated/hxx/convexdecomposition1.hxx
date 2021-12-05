#if 1
class ConvexDecompositionRef;

struct ConvexDecompositionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ConvexDecompositionInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ConvexDecompositionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ConvexDecompositionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ConvexDecompositionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ConvexDecompositionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline Result<DataDictionary> GetSettings() const;
/// Get the current status of the decomposition job.
/// @return true if the decomposition is complete
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsReady() const;
/// Get the current progress of the decomposition job.
/// @return percentage completed
		inline Result<UInt16> GetProgress() const;
	};
	/// Intermediate helper class for ConvexDecompositionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexDecompositionRef, true>::type&() const { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexDecompositionRef, false>::type&() { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
/// Initialize the convex decomposition library.
/// @param levelOfDetail	desired level of detail to retail in the decomposition.
///												Allowed values are between 0 and 1. Recommended 0.5.
/// @param maxVoxelCount	Maximum number of voxels used to decompose the bounding box
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(Float levelOfDetail = 0.5, UInt32 maxVoxelCount = 16000000) const;
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
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ConvexDecompositionRef, false>::type&() { return reinterpret_cast<const ConvexDecompositionRef&>(this->GetBaseRef()); }
/// Initialize the convex decomposition library.
/// @param levelOfDetail	desired level of detail to retail in the decomposition.
///												Allowed values are between 0 and 1. Recommended 0.5.
/// @param maxVoxelCount	Maximum number of voxels used to decompose the bounding box
/// @return												This @CLASS (to allow method chaining).
		inline Result<void> Init(Float levelOfDetail = 0.5, UInt32 maxVoxelCount = 16000000);
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class ConvexDecompositionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ConvexDecompositionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConvexDecompositionInterface, maxon::StrongRefHandler, ConvexDecompositionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConvexDecompositionInterface, maxon::StrongRefHandler, ConvexDecompositionRef>>>>);
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
