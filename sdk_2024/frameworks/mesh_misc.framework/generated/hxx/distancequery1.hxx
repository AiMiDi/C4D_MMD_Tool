#if 1
class DistanceQueryRef;

struct DistanceQueryInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DistanceQueryInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DistanceQueryInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DistanceQueryInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DistanceQueryRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DistanceQueryInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DistanceQueryInterface**);
/// Retrieves the closest primitive of the initialized mesh.
/// @param[in] pos								The point in space the closest primitive should be found for.
/// @param[out] primInfo					The information for the primitive closest to the passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @return												The minimum distance to the closest primitive.
		inline HXXADDRET2(Float) GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter = nullptr) const;
/// Retrieves the closest primitive of the initialized mesh.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[out] distInfo					The calculated distance information for passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
		inline HXXADDRET2(void) GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
/// Retrieves the closest primitive of the initialized mesh. Same as GetDistanceToMesh
/// This will filter out all polygons that have primitive normals with a higher angle from the passed direction.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[in] direction					The direction for which the found polygons are not allowed to deviate more than the passed angle.
/// @param[in] angle							The angle for which the found polygons normals are not allowed to deviate relative to the passed direction.
/// @param[out] distInfo					The calculated distance information for the passed point.
/// @param[in] polyFilter					An optional bitset with the polygon indices that should be tested set, if nullptr all polygons will be tested.
/// @param[in] onlyPolyPrimitives	If true the primitive information in the calculated distInfo will always be relative to polygons, false will return primitive information for points and edges as well.
		inline HXXADDRET2(void) GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter = nullptr, Bool onlyPolyPrimitives = false) const;
/// Retrieves the closest primitive of the initialized Spline or Line.
/// @param[in] pos								The point in space the distance information should be calculated for.
/// @param[out] distInfo					The calculated distance information for passed point.
		inline HXXADDRET2(void) GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const;
/// Retrieves if the class was initialized with a polygon object, a spline or a line.
/// @return												True if the class was initialized, false otherwise.
		inline HXXADDRET2(Bool) IsInitialized() const;
	};
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DistanceQueryInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DistanceQueryInterface**);
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
/// Initializes the distance query with a list of points and polygons.
/// @param[in] points							Block of Vectors that represent the points of the mesh.
/// @param[in] polygons						Block to Simple polygons that represent the topology.
/// @param[in] objectPosition			The matrix of the geometry.
/// @return												OK on success.
		inline Result<void> Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition) const;
/// Resets the Initialized data.
		inline HXXADDRET2(void) Reset() const;
/// Set the thread count for the calculations.
/// @param[in] threads						The amount of threads to be used.		
		inline HXXADDRET2(void) SetThreading(Int32 threads) const;
	};
	/// Intermediate helper class for DistanceQueryInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DistanceQueryInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DistanceQueryInterface**);
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
/// Initializes the distance query with a list of points and polygons.
/// @param[in] points							Block of Vectors that represent the points of the mesh.
/// @param[in] polygons						Block to Simple polygons that represent the topology.
/// @param[in] objectPosition			The matrix of the geometry.
/// @return												OK on success.
		inline Result<void> Init(const Block<const Vector> points, const Block<const SimplePolygon> polygons, const Matrix& objectPosition);
/// Resets the Initialized data.
		inline HXXADDRET1(void) Reset();
/// Set the thread count for the calculations.
/// @param[in] threads						The amount of threads to be used.		
		inline HXXADDRET1(void) SetThreading(Int32 threads);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DistanceQueryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DistanceQueryRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DistanceQueryInterface, maxon::StrongRefHandler, DistanceQueryRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DistanceQueryInterface, maxon::StrongRefHandler, DistanceQueryRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DistanceQueryRef is the reference class of DistanceQueryInterface.
///
/// DistanceQueryInterface provides functions for calculating the distance to a mesh, a spline or a line.
class DistanceQueryRef : public DistanceQueryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DistanceQueryRef, typename DistanceQueryInterface::Hxx1::Reference);
	using ConstPtr = typename DistanceQueryInterface::ConstPtr;
};

#endif
