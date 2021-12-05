#if 1
class Delaunay3DRef;

struct Delaunay3DInterface::Hxx1
{
	class Reference;
	using ReferenceClass = Delaunay3DRef;
	/// Intermediate helper class for Delaunay3DInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets a constant reference to the tetrahedrons list.
/// THREADSAFE.
/// @param[out] arrayCount				Will be filled with the amount of tetrahedrons in the array reference.
/// @param[out] pointCount				Will be filled with the amount of points inserted into the teterahedralization.
/// @return												A constant reference to a BaseArray<Tetrahedron> with the tetrahedrons, that make up the tetrahedralization.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type GetTetrahedrons(Int& arrayCount, Int& pointCount) const;
/// Gets a constant reference to the tetrahedrons list.
/// THREADSAFE.
/// @return												A constant reference to a BaseArray<Tetrahedron> with the tetrahedrons, that make up the tetrahedralization.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Tetrahedron>&>, const BaseArray<Tetrahedron>&>::type GetTetrahedrons() const;
/// Gets a constant reference to the connection of one of the points to an arbitrary adjacent tetrahedron.
/// This can be used to greatly increase the calculation speed of a Voronoi conversion.
/// THREADSAFE.
/// @return												A constant reference to a BaseArray<Int32> with the tetrahedron index to the point at the same array position as added.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Int32>&>, const BaseArray<Int32>&>::type GetPointsToTetConnections() const;
/// Gets a constant reference to the list of points, that are set for the Delaunay tetrahedralization.
/// THREADSAFE.
/// @return												A constant reference to a BaseArray<Vector> with the points of the tetrahedralization.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector>&>, const BaseArray<Vector>&>::type GetPoints() const;
/// Gets the current amount of tetrahedrons.
/// THREADSAFE.
/// @return												Amount of tetrahedrons.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetTetrahedronCount() const;
/// Gets the current amount of points
/// THREADSAFE.
/// @return												Amount of points that were added.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetPointCount() const;
/// Static helper method to calculate the precise orientation of a point, in reference to a plane.
/// the plane is spanned by planePointA, planePointB and planePointC.
/// the tested point is testPoint.
/// THREADSAFE.
/// @param[in] planePointA				Point one of plane.
/// @param[in] planePointB				Point two of plane.
/// @param[in] planePointC				Point three of plane.
/// @param[in] testPoint					Point to test for.
/// @return												The determinant of the calculation. The sign of the result gives information about the side the point was is on.
		static inline Float OrientDet(const Vector& planePointA, const Vector& planePointB, const Vector& planePointC, const Vector& testPoint);
/// Returns the index of the tetrahedron the input point is in.
/// THREADSAFE.
/// @param[in] point							The point position to search the tetrahedron index for.
/// @param[out] foundTetIndex			The index of the tetrahedron that the point was in.
/// @param[out] onFace1						Is set if the point is on one of the tetrahedrons faces.
/// @param[out] onFace2						Is set if the point is on one of the tetrahedron edges (there for on two faces).
/// @return												True if the point was inside a tetrahedron, false otherwise or on error.
		inline Result<Bool> FindTetIndexContainingPoint(const Vector& point, Int32& foundTetIndex, Int32& onFace1, Int32& onFace2) const;
/// Returns the index of the tetrahedron the input point is in.
/// THREADSAFE.
/// @param[in] point							The point position to search the tetrahedron index for.
/// @param[out] foundTetIndex			The index of the tetrahedron that the point was in.
/// @return												True if the point was inside a tetrahedron, false otherwise or on error.
		inline Result<Bool> FindTetContainingPoint(const Vector& point, Int32& foundTetIndex) const;
	};
	/// Intermediate helper class for Delaunay3DInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Delaunay3DRef, true>::type&() const { return reinterpret_cast<const Delaunay3DRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Delaunay3DRef, false>::type&() { return reinterpret_cast<const Delaunay3DRef&>(this->GetBaseRef()); }
/// Copies the content of another Delaunay3D Object into this one (copy and assign is not allowed)
/// @param[in] src								The Delaunay3D Object to copy from.
/// @param[in] resizeFlags				Resize flag for internal list copies. recommended is default.
/// @return												OK on success.
		inline Result<void> CopyFrom(const Delaunay3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) const;
/// The Initialization function for Delaunay3D.
/// Needs to be called before points can be added into the tetrahedralization.
/// @param[in] workSpace					The space in which the input points will be in. Should not be too big for numeric reasons.
/// @return												OK on success.
		inline Result<void> Init(const Range<Vector>& workSpace) const;
/// Updates the Tetrahedralization if new points have been added.
/// This triggers the final calculation or update of the tetrahedralization.
/// @return												OK on success.
		inline Result<void> CalculateDelaunayTetrahedralization() const;
/// Checks if Init() has been called.
/// THREADSAFE.
/// @return												true if Init() has beed called, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsInitialized() const;
/// Adds a BaseArray of points into the tetrahedralization.
/// CalculateDelaunayTetrahedralization() needs to be called
/// afterwards to calculate the insertion.
/// @param[in] newPointsIn				The list of points, that will be added into the tetrahedralization.
/// @return												OK on success.
		inline Result<void> AddPointsIntoTetrahedralization(const BaseArray<Vector>& newPointsIn) const;
/// Adds a single point into the tetrahedralization.
/// CalculateDelaunayTetrahedralization() needs to be called afterwards to calculate the insertion.
/// @param[in] newPointIn					The point that will be added into the tetrahedralization.
/// @return												OK on success.
		inline Result<void> AddPointIntoTetrahedralization(const Vector& newPointIn) const;
/// Gets a reference to the list of points, that are set for the Delaunay tetrahedralization (writable).
/// THREADSAFE.
/// @return												A reference to a BaseArray<Vector> with the points of the tetrahedralization.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Vector>&>, ResultRef<BaseArray<Vector>>>::type GetPointsWrite() const;
/// Resets the Delaunay object for a reuse with the same initialization.
/// @return												OK on success.
		inline Result<void> Reset() const;
/// Resets all data structures for a new calculation. Needs to be reinitialized before its reused.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Flush() const;
	};
	/// Intermediate helper class for Delaunay3DInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, Delaunay3DRef, false>::type&() { return reinterpret_cast<const Delaunay3DRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class Delaunay3DInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<Delaunay3DRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<Delaunay3DInterface, maxon::StrongRefHandler, Delaunay3DRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<Delaunay3DInterface, maxon::StrongRefHandler, Delaunay3DRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Delaunay3DRef> Create();
};

/// Delaunay3DRef is the reference class of Delaunay3DInterface.
class Delaunay3DRef : public Delaunay3DInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Delaunay3DRef, typename Delaunay3DInterface::Hxx1::Reference);
	using ConstPtr = typename Delaunay3DInterface::ConstPtr;
};

#endif
