#if 1
constexpr inline const maxon::Char* DT_GradientKnot_CppName() { return "maxon::GradientKnot"; }
class Gradient;

struct GradientInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Gradient;
	/// Intermediate helper class for GradientInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = GradientInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(GradientInterface**);
/// Gets the number of knots.
/// @return												The knot count.
		inline HXXADDRET2(Int) GetKnotCount() const;
/// Gets the knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												The knot.
		inline HXXADDRET2(GradientKnot) GetKnot(Int index) const;
/// Checks if this is an alpha gradient.
/// @return												True, if this is an alpha gradient.
		inline HXXADDRET2(Bool) IsAlphaGradient() const;
/// Compares this with another gradient.
/// @param[in] arg2								The other gradient to compare with.
/// @return												The comparison result.
		inline HXXADDRET2(COMPARERESULT) Compare(const GradientInterface* arg2) const;
/// Initializes the gradient for rendering.
/// @param[in] transformColorDelegate	A delegate to transform the color of a gradient knot.
/// @return												The render data.
		inline Result<GradientRenderData> InitRender(const TransformColorDelegate& transformColorDelegate) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for GradientInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = GradientInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(GradientInterface**);
/// Allocates an alpha gradient.
/// @return												The alpha gradient.
		inline Result<Gradient*> AllocAlphaGradient() const;
/// Returns the internal alpha gradient.
/// @return												The alpha gradient.
		inline HXXADDRET2(Gradient*) GetAlphaGradient() const;
/// Inserts a knot.
/// @param[in] knot								The knot to insert.
/// @param[in] keepId							Specifies if the knot ID should be taken from knot or if a new one should be generated.
/// @return												The index of the inserted knot, GetKnotCount() - @em 1
		inline Result<Int> InsertKnot(const GradientKnot& knot, Bool keepId = false) const;
/// Removes a knot.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												OK on success.
		inline Result<void> RemoveKnot(Int index) const;
/// Sets knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @param[in] k									The knot.
		inline Result<void> SetKnot(Int index, const GradientKnot& k) const;
/// Converts the current gradient to an alpha gradient.
		inline HXXADDRET2(void) ConvertToAlphaGradient() const;
/// Sorts the knots according to their position.
		inline HXXADDRET2(void) SortKnots() const;
/// Inverts the knots.
/// @return												True if any knot inverted, otherwise false.
		inline Result<Bool> InvertKnots() const;
/// Doubles the knots.
/// @return												True if any knot doubled, otherwise false.
		inline Result<Bool> DoubleKnots() const;
/// Distributes the knots evenly.
/// @return												True if any knot distributed, otherwise false.
		inline HXXADDRET2(Bool) DistributeKnots() const;
/// Flushes all the knots.
		inline HXXADDRET2(void) Flush() const;
/// Sets the alpha mode.
/// @param[in] alphaGradient			The gradient alpha type.
		inline HXXADDRET2(void) SetIsAlphaGradient(Bool alphaGradient) const;
	};
	/// Intermediate helper class for GradientInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = GradientInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(GradientInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Gradient, false>::type&() const { return reinterpret_cast<const Gradient&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Gradient, false>::type&() { return reinterpret_cast<const Gradient&>(this->GetBaseRef()); }
/// Allocates an alpha gradient.
/// @return												The alpha gradient.
		inline Result<Gradient*> AllocAlphaGradient();
/// Returns the internal alpha gradient.
/// @return												The alpha gradient.
		inline HXXADDRET1(Gradient*) GetAlphaGradient();
/// Inserts a knot.
/// @param[in] knot								The knot to insert.
/// @param[in] keepId							Specifies if the knot ID should be taken from knot or if a new one should be generated.
/// @return												The index of the inserted knot, GetKnotCount() - @em 1
		inline Result<Int> InsertKnot(const GradientKnot& knot, Bool keepId = false);
/// Removes a knot.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												OK on success.
		inline Result<void> RemoveKnot(Int index);
/// Sets knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @param[in] k									The knot.
		inline Result<void> SetKnot(Int index, const GradientKnot& k);
/// Converts the current gradient to an alpha gradient.
		inline HXXADDRET1(void) ConvertToAlphaGradient();
/// Sorts the knots according to their position.
		inline HXXADDRET1(void) SortKnots();
/// Inverts the knots.
/// @return												True if any knot inverted, otherwise false.
		inline Result<Bool> InvertKnots();
/// Doubles the knots.
/// @return												True if any knot doubled, otherwise false.
		inline Result<Bool> DoubleKnots();
/// Distributes the knots evenly.
/// @return												True if any knot distributed, otherwise false.
		inline HXXADDRET1(Bool) DistributeKnots();
/// Flushes all the knots.
		inline HXXADDRET1(void) Flush();
/// Sets the alpha mode.
/// @param[in] alphaGradient			The gradient alpha type.
		inline HXXADDRET1(void) SetIsAlphaGradient(Bool alphaGradient);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class GradientInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<Gradient>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const GradientInterface, maxon::StrongCOWRefHandler, Gradient>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const GradientInterface, maxon::StrongCOWRefHandler, Gradient>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Gradient> Create();
};

class GradientInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<GradientInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<GradientInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Gradient is the reference class of GradientInterface.
///
/// This is the interface for the Gradient data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
/// Alpha Gradients ONLY set Brightness, Color is always 1.0
/// Regular Gradients can set Brightness & Color
class Gradient : public GradientInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Gradient, typename GradientInterface::Hxx1::Reference);
};

class GradientRenderData;

struct GradientRenderDataInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = GradientRenderData;
	/// Intermediate helper class for GradientRenderDataInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = GradientRenderDataInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(GradientRenderDataInterface**);
/// Calculates a gradient pixel.
/// @param[in] pos								The X position.
/// @return												The calculated gradient pixel.
		inline HXXADDRET2(Color) CalcGradientPixel(Float pos) const;
/// Gets the number of knots for GetRenderKnot().
/// @return												The render knot count.
		inline HXXADDRET2(Int) GetKnotCount() const;
/// Gets a pointer to the knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												The render knot at @formatParam{index}. @theOwnsPointed{gradient data,knot}
		inline HXXADDRET2(const GradientKnot*) GetKnot(Int index) const;
/// Gets a read only reference to internal knot list for fast access.
/// @return												The knot list.
		inline HXXADDRET2(const BaseArray<GradientKnot>&) GetKnots() const;
/// Compares this with another GradientRenderData value.
/// @param[in] arg2								The other GradientRenderData value to compare with.
/// @return												The comparison result.
		inline HXXADDRET2(COMPARERESULT) Compare(const GradientRenderDataInterface* arg2) const;
	};
	/// Intermediate helper class for GradientRenderDataInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = GradientRenderDataInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(GradientRenderDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, GradientRenderData, false>::type&() const { return reinterpret_cast<const GradientRenderData&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, GradientRenderData, false>::type&() { return reinterpret_cast<const GradientRenderData&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	ConstFn<typename ST::type>
	> { };
};
class GradientRenderDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<GradientRenderData>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const GradientRenderDataInterface, maxon::StrongCOWRefHandler, GradientRenderData>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const GradientRenderDataInterface, maxon::StrongCOWRefHandler, GradientRenderData>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<GradientRenderData> Create();
};

class GradientRenderDataInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<GradientRenderDataInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<GradientRenderDataInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GradientRenderData is the reference class of GradientRenderDataInterface.
///
/// This is the interface for the render data of the Gradient data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
class GradientRenderData : public GradientRenderDataInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GradientRenderData, typename GradientRenderDataInterface::Hxx1::Reference);
};

#endif
