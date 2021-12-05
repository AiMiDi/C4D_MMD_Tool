#if 1
constexpr inline const maxon::Char* DT_SplineMapperKnot_CppName() { return "maxon::SplineMapperKnot"; }
class SplineMapper;

struct SplineMapperInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = SplineMapper;
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets a point from its X coordinate. If out of range, the first or last spline knots will be returned.
/// @note Make sure knots are sorted before calling this (@see SortKnots)
/// @param[in] positionX					The X coordinate.
/// @return												The retrieved position.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type GetPoint(Float positionX) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetRange(Vector2d& min, Vector2d& max) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetTension() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetKnotCount() const;
/// Compares this SplineMapper with another if both are identical.
/// @param[in] other							The other SplineMapper to compare this object with.
/// @return												True if the object is identical.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const SplineMapperInterface* other, EQUALITY equality) const;
/// Gets the internal array for read-only operations.
/// @return 		Reference to internal array.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<SplineMapperKnot>&>, const BaseArray<SplineMapperKnot>&>::type GetKnots() const;
/// Clamps a position to the defined range (@see GetRange(), SetRange()).
/// @param[in] position 							The position.
/// @return														The clamped position.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Vector2d>, Vector2d>::type ClampPosition(const Vector2d& position) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetRange(const Vector2d& min, const Vector2d& max) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AdaptRange(const Vector2d& min, const Vector2d& max) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetTension(Float tension) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<SplineMapperKnot*>, SplineMapperKnot*>::type GetKnot(Int knotIndex) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SetKnot(Int knotIndex, const SplineMapperKnot& knot) const;
/// Inserts a new knot at index position (0 <= position <= GetCount()).
/// @param[in] knotIndex							Insert index (the internal array size will increase and if (0 <= position < GetCount()), the existing elements are moved, but if (position == GetCount()), then element is appended to the end).
/// @param[in] knot										The knot to insert
		inline Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot) const;
		inline Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) const;
		inline Result<void> DeleteKnot(Int knotIndex) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type DeleteAllKnots() const;
/// Gets the internal array for read/write operations.
/// @return Pointer to internal array. It's guaranteed to be valid.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<SplineMapperKnot>*>, BaseArray<SplineMapperKnot>*>::type GetKnotsRW() const;
/// Sorts the knots by its position X. Call this when an new knot is added or if a knot postion X has been modified.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SortKnots() const;
	};
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SplineMapper, false>::type&() const { return reinterpret_cast<const SplineMapper&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SplineMapper, false>::type&() { return reinterpret_cast<const SplineMapper&>(this->GetBaseRef()); }
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetRange(const Vector2d& min, const Vector2d& max);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type AdaptRange(const Vector2d& min, const Vector2d& max);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetTension(Float tension);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), SplineMapperKnot*, maxon::Result<SplineMapperKnot*>>::type GetKnot(Int knotIndex);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type SetKnot(Int knotIndex, const SplineMapperKnot& knot);
/// Inserts a new knot at index position (0 <= position <= GetCount()).
/// @param[in] knotIndex							Insert index (the internal array size will increase and if (0 <= position < GetCount()), the existing elements are moved, but if (position == GetCount()), then element is appended to the end).
/// @param[in] knot										The knot to insert
		inline Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot);
		inline Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents);
		inline Result<void> DeleteKnot(Int knotIndex);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type DeleteAllKnots();
/// Gets the internal array for read/write operations.
/// @return Pointer to internal array. It's guaranteed to be valid.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), BaseArray<SplineMapperKnot>*, maxon::Result<BaseArray<SplineMapperKnot>*>>::type GetKnotsRW();
/// Sorts the knots by its position X. Call this when an new knot is added or if a knot postion X has been modified.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SortKnots();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type
	> { };
};
class SplineMapperInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<SplineMapper>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SplineMapperInterface, maxon::StrongCOWRefHandler, SplineMapper>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SplineMapperInterface, maxon::StrongCOWRefHandler, SplineMapper>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<SplineMapper> Create();
};

class SplineMapperInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SplineMapperInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SplineMapperInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// SplineMapper is the reference class of SplineMapperInterface.
///
/// This is the interface for the SplineMapper data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
class SplineMapper : public SplineMapperInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SplineMapper, typename SplineMapperInterface::Hxx1::Reference);
};

#endif
