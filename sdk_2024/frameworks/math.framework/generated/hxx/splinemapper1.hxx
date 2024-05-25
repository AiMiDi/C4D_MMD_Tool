#if 1
constexpr inline const maxon::Char* DT_SplineMapperKnot_CppName() { return "maxon::SplineMapperKnot"; }
class SplineMapper;

struct SplineMapperInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = SplineMapper;
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SplineMapperInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(SplineMapperInterface**);
/// Gets a point from its X coordinate. If out of range, the first or last spline knots will be returned.
/// @note Make sure knots are sorted before calling this (@see SortKnots)
/// @param[in] positionX					The X coordinate.
/// @return												The retrieved position.
		inline HXXADDRET2(Vector2d) GetPoint(Float positionX) const;
		inline HXXADDRET2(void) GetRange(Vector2d& min, Vector2d& max) const;
		inline HXXADDRET2(Float) GetTension() const;
		inline HXXADDRET2(Int) GetKnotCount() const;
/// Compares this SplineMapper with another if both are identical.
/// @param[in] other							The other SplineMapper to compare this object with.
/// @return												True if the object is identical.
		inline HXXADDRET2(Bool) IsEqual(const SplineMapperInterface* other, EQUALITY equality) const;
/// Gets the internal array for read-only operations.
/// @return 		Reference to internal array.
		inline HXXADDRET2(const BaseArray<SplineMapperKnot>&) GetKnots() const;
/// Clamps a position to the defined range (@see GetRange(), SetRange()).
/// @param[in] position 							The position.
/// @return														The clamped position.
		inline HXXADDRET2(Vector2d) ClampPosition(const Vector2d& position) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SplineMapperInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(SplineMapperInterface**);
		inline HXXADDRET2(void) SetRange(const Vector2d& min, const Vector2d& max) const;
		inline HXXADDRET2(void) AdaptRange(const Vector2d& min, const Vector2d& max) const;
		inline HXXADDRET2(void) SetTension(Float tension) const;
		inline HXXADDRET2(SplineMapperKnot*) GetKnot(Int knotIndex) const;
		inline HXXADDRET2(Bool) SetKnot(Int knotIndex, const SplineMapperKnot& knot) const;
/// Inserts a new knot at index position (0 <= position <= GetCount()).
/// @param[in] knotIndex							Insert index (the internal array size will increase and if (0 <= position < GetCount()), the existing elements are moved, but if (position == GetCount()), then element is appended to the end).
/// @param[in] knot										The knot to insert
		inline Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot) const;
		inline Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) const;
		inline Result<void> DeleteKnot(Int knotIndex) const;
		inline HXXADDRET2(void) DeleteAllKnots() const;
/// Gets the internal array for read/write operations.
/// @return Pointer to internal array. It's guaranteed to be valid.
		inline HXXADDRET2(BaseArray<SplineMapperKnot>*) GetKnotsRW() const;
/// Sorts the knots by its position X. Call this when an new knot is added or if a knot postion X has been modified.
		inline HXXADDRET2(void) SortKnots() const;
	};
	/// Intermediate helper class for SplineMapperInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = SplineMapperInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(SplineMapperInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SplineMapper, false>::type&() const { return reinterpret_cast<const SplineMapper&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SplineMapper, false>::type&() { return reinterpret_cast<const SplineMapper&>(this->GetBaseRef()); }
		inline HXXADDRET1(void) SetRange(const Vector2d& min, const Vector2d& max);
		inline HXXADDRET1(void) AdaptRange(const Vector2d& min, const Vector2d& max);
		inline HXXADDRET1(void) SetTension(Float tension);
		inline HXXADDRET1(SplineMapperKnot*) GetKnot(Int knotIndex);
		inline HXXADDRET1(Bool) SetKnot(Int knotIndex, const SplineMapperKnot& knot);
/// Inserts a new knot at index position (0 <= position <= GetCount()).
/// @param[in] knotIndex							Insert index (the internal array size will increase and if (0 <= position < GetCount()), the existing elements are moved, but if (position == GetCount()), then element is appended to the end).
/// @param[in] knot										The knot to insert
		inline Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot);
		inline Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents);
		inline Result<void> DeleteKnot(Int knotIndex);
		inline HXXADDRET1(void) DeleteAllKnots();
/// Gets the internal array for read/write operations.
/// @return Pointer to internal array. It's guaranteed to be valid.
		inline HXXADDRET1(BaseArray<SplineMapperKnot>*) GetKnotsRW();
/// Sorts the knots by its position X. Call this when an new knot is added or if a knot postion X has been modified.
		inline HXXADDRET1(void) SortKnots();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class SplineMapperInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<SplineMapper>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const SplineMapperInterface, maxon::StrongCOWRefHandler, SplineMapper>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const SplineMapperInterface, maxon::StrongCOWRefHandler, SplineMapper>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<SplineMapper> Create();
};

class SplineMapperInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SplineMapperInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SplineMapperInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
