#if 1
class DistanceQueryRef;

struct DistanceQueryInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DistanceQueryInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DistanceQueryInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DistanceQueryInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DistanceQueryRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Retrieves the closest primitive of the initialized mesh.
/// @param[in] pos								The point in space the closest primitive should be found for.
/// @param[out] primInfo					The information for the primitive closest to the passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @return												The minimum distance to the closest primitive.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter = nullptr) const;
/// Retrieves the closest primitive of the initialized mesh.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[out] distInfo					The calculated distance information for passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
/// Retrieves the closest primitive of the initialized mesh. Same as GetDistanceToMesh
/// This will filter out all polygons that have primitive normals with a higher angle from the passed direction.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[in] direction					The direction for which the found polygons are not allowed to deviate more than the passed angle.
/// @param[in] angle							The angle for which the found polygons normals are not allowed to deviate relative to the passed direction.
/// @param[out] distInfo					The calculated distance information for the passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
/// Retrieves the closest primitive of the initialized Spline or Line.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[out] distInfo					The calculated distance information for passed point.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const;
/// Retrieves if the class was initialized with a polygon object, a spline or a line.
/// @return												True if the class was initialized, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsInitialized() const;
	};
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DistanceQueryRef, true>::type&() const { return reinterpret_cast<const DistanceQueryRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DistanceQueryRef, false>::type&() { return reinterpret_cast<const DistanceQueryRef&>(this->GetBaseRef()); }
/// Initializes the distance query with a polygon object.
/// @param[in] mesh								Reference to the polygon object that the distance query is initialized to.
/// @param[in] initVoxelization		Initializes a voxelization for the distance query. This Is useful for massive tests on high poly polygon objects.
/// @return												OK on success.
		inline Result<void> Init(PolygonObject* mesh, Bool initVoxelization = false) const;
/// Initializes the distance query with a spline object.
/// @param[in] spline							Reference to the spline object that the distance query is initialized to.
/// @return												OK on success.
		inline Result<void> Init(SplineObject* spline) const;
/// Initializes the distance query with a line object.
/// @param[in] line								Reference to the line object that the distance query is initialized to.
/// @return												OK on success.
		inline Result<void> Init(LineObject* line) const;
/// Resets the Initialized data.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
/// Set the thread count for the calculations.
/// @param[in] threads						The amount of threads to be used.		
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetThreading(Int32 threads) const;
	};
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DistanceQueryRef, false>::type&() { return reinterpret_cast<const DistanceQueryRef&>(this->GetBaseRef()); }
/// Initializes the distance query with a polygon object.
/// @param[in] mesh								Reference to the polygon object that the distance query is initialized to.
/// @param[in] initVoxelization		Initializes a voxelization for the distance query. This Is useful for massive tests on high poly polygon objects.
/// @return												OK on success.
		inline Result<void> Init(PolygonObject* mesh, Bool initVoxelization = false);
/// Initializes the distance query with a spline object.
/// @param[in] spline							Reference to the spline object that the distance query is initialized to.
/// @return												OK on success.
		inline Result<void> Init(SplineObject* spline);
/// Initializes the distance query with a line object.
/// @param[in] line								Reference to the line object that the distance query is initialized to.
/// @return												OK on success.
		inline Result<void> Init(LineObject* line);
/// Resets the Initialized data.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
/// Set the thread count for the calculations.
/// @param[in] threads						The amount of threads to be used.		
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetThreading(Int32 threads);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DistanceQueryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DistanceQueryRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DistanceQueryInterface, maxon::StrongRefHandler, DistanceQueryRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DistanceQueryInterface, maxon::StrongRefHandler, DistanceQueryRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DistanceQueryRef is the reference class of DistanceQueryInterface.
///
/// DistanceQueryInterface provides functions for calculating the distance to a mesh, a spline or a line.
class DistanceQueryRef : public DistanceQueryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DistanceQueryRef, typename DistanceQueryInterface::Hxx1::Reference);
};

#endif
