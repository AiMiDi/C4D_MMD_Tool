#if 1
class Voronoi3DRef;

struct Voronoi3DInterface::Hxx1
{
	class Reference;
	using ReferenceClass = Voronoi3DRef;
	/// Intermediate helper class for Voronoi3DInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = Voronoi3DInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(Voronoi3DInterface**);
/// Gets the point positions
/// @return												Reference to the list holding the site positions.
		inline HXXADDRET2(const BaseArray<Vector>&) GetVoronoiPointPositions() const;
/// Gets the point positions
/// @return												Reference to the list holding the site positions.
		inline HXXADDRET2(const BaseArray<Vector>&) GetInputPoints() const;
	};
	/// Intermediate helper class for Voronoi3DInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = Voronoi3DInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(Voronoi3DInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Voronoi3DRef, true>::type&() const { return reinterpret_cast<const Voronoi3DRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Voronoi3DRef, false>::type&() { return reinterpret_cast<const Voronoi3DRef&>(this->GetBaseRef()); }
		inline Result<void> Init(const Range<Vector>& workSpace) const;
/// Copies the contents of src into this object.
/// @param[in] src								The object to copy from.
/// @param[in] resizeFlags				Resize flag for collections.
/// @return												OK on success.
		inline Result<void> CopyFrom(const Voronoi3DInterface* src, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) const;
/// Checks if the Voronoi data structure is ready, even through the data might need recalculation.
/// @return												True if a Voronoi data structure is ready.
		inline HXXADDRET2(Bool) IsReadyButPendingChanges() const;
/// Checks if the current object state is the finished data with no pending changes.
/// @return												True if all calculations were performed and no pending changes.
		inline HXXADDRET2(Bool) IsReady() const;
/// Sets a list of points as Voronoi sites. Only these will be used, and old points will be reset
/// @param[in] points							Points to set for this Voronoi object.
/// @return												OK on success.
		inline Result<void> SetPoints(const BaseArray<Vector>& points) const;
/// Add a single point to the current set of points.
/// @param[in] pointIn						Point to add for this Voronoi object.
/// @return												OK on success.
		inline Result<void> AddPoint(const Vector& pointIn) const;
/// Adds a list of points as Voronoi sites to the current set of points.
/// @param[in] points							Points to add for this Voronoi object.
/// @return												OK on success.
		inline Result<void> AddPoints(const BaseArray<Vector>& points) const;
/// Performs a Voronoi calculation on the current set of points.
/// @return												OK on success.
		inline Result<void> CalcCells() const;
/// Performs the pre-step of calculating a Delaunay tetrahedralization.
/// if CalcCells() is called after this, the calcualted tetrahedralization will be reused.
/// If CalcCells() is called without this being called, it will perform it automatically.
/// @return												OK on success.
		inline Result<void> CalcTetrahedralization() const;
/// Set a flag that will trigger some extra calculations in die Voronoi algorithm.
		inline HXXADDRET2(void) SetForClipping(Bool clipping) const;
/// Gets the amount of cells.
/// @return												The amount of cells.
		inline HXXADDRET2(Int) GetCellCount() const;
/// Gets the flag list of that defines if a cell is a border cell.
/// This is only set if the algorithm was set for clipping.
/// @return												Reference to the list holding the border flags.
		inline HXXADDRET2(ResultRef<BaseArray<Bool>>) GetBorderCellFlags() const;
/// Gets the final data structure of the Voronoi 3D diagram.
/// @return												Reference to the list holding the full cell data.
		inline HXXADDRET2(ResultRef<BaseArray<CellData>>) GetCellDataStructure() const;
/// Gets a list of flags, that defines for every cell, if it still has a volume.
/// This will be true for every start cell and can only be false if a cell got scaled.
/// @return												Reference to the list holding the flag if a cell still has volume.
		inline HXXADDRET2(ResultRef<BaseArray<Char>>) GetCellHasVolume() const;
/// Scales one cell (cellIndex) in the Voronoi data structure
/// @param[in] cellIndex					The index of the cell to scale
/// @param[in] scaleValue					Scale amount
/// @return												OK on success.
		inline Result<void> ScaleCell(Int cellIndex, Float scaleValue) const;
/// Scales all cells in the Voronoi data structure.
/// @param[in] scaleValue					Scale amount.
/// @return												OK on success.
		inline Result<void> ScaleAllCells(Float scaleValue) const;
/// Gets the internal Delaunay3D tetrahedralization class.
/// @return												Reference to the internal Delaunay3D.
		inline HXXADDRET2(ResultRef<Delaunay3DRef>) GetDelaunayTetrizer() const;
/// Resets the object for a fresh calculation.
		inline HXXADDRET2(void) Flush() const;
/// Sets a list of indices to be one group. These points will be fused to one cell in generation.
/// If an index is set to fuse in an earlier call, it will be ignored.
/// This needs to be called after points are set or it will not have any effect.
/// @param[in] fuseIndices				The list of indices to be fused.
/// @return												OK on success.
		inline Result<void> SetCellFuseGroup(BaseArray<Int>& fuseIndices) const;
/// Fuses the cells declared in a list of neighbor pairs into each other.
/// @param[in] joinList						The neighbor pairs of cells that should be fused.
/// @return												OK on success.
		inline Result<void> FuseCells(BaseArray<Pair<Int, Int>>& joinList) const;
/// Inverts the whole Voronoi data structure.
/// this is done by inverting all faces of the cells and fusing all into one cell.
/// @return												OK on success.
		inline Result<void> CreateInvertedVoronoiCell() const;
	};
	/// Intermediate helper class for Voronoi3DInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = Voronoi3DInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(Voronoi3DInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, Voronoi3DRef, false>::type&() { return reinterpret_cast<const Voronoi3DRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class Voronoi3DInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<Voronoi3DRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<Voronoi3DInterface, maxon::StrongRefHandler, Voronoi3DRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<Voronoi3DInterface, maxon::StrongRefHandler, Voronoi3DRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Voronoi3DRef> Create();
};

/// Voronoi3DRef is the reference class of Voronoi3DInterface.
///
/// Voronoi3D provides functions for creating a 3D Voronoi representation of points.
class Voronoi3DRef : public Voronoi3DInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Voronoi3DRef, typename Voronoi3DInterface::Hxx1::Reference);
	using ConstPtr = typename Voronoi3DInterface::ConstPtr;
};

#endif
