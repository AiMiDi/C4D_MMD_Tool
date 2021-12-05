#if 1
class Gradient;

struct GradientInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Gradient;
	/// Intermediate helper class for GradientInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets the number of knots.
/// @return												The knot count.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetKnotCount() const;
/// Gets the knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												The knot.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type GetKnot(Int index) const;
/// Checks if this is an alpha gradient.
/// @return												True, if this is an alpha gradient.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsAlphaGradient() const;
/// Compares this with another gradient.
/// @param[in] arg2								The other gradient to compare with.
/// @return												The comparison result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const GradientInterface* arg2) const;
/// Initializes the gradient for rendering.
/// @param[in] transformColorDelegate	A delegate to transform the color of a gradient knot.
/// @return												The render data.
		inline Result<GradientRenderData> InitRender(const TransformColorDelegate& transformColorDelegate) const;
	};
	/// Intermediate helper class for GradientInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Allocates an alpha gradient.
/// @return												The alpha gradient.
		inline Result<Gradient*> AllocAlphaGradient() const;
/// Returns the internal alpha gradient.
/// @return												The alpha gradient.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type GetAlphaGradient() const;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type ConvertToAlphaGradient() const;
/// Sorts the knots according to their position.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SortKnots() const;
/// Inverts the knots.
/// @return												True if any knot inverted, otherwise false.
		inline Result<Bool> InvertKnots() const;
/// Doubles the knots.
/// @return												True if any knot doubled, otherwise false.
		inline Result<Bool> DoubleKnots() const;
/// Distributes the knots evenly.
/// @return												True if any knot distributed, otherwise false.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type DistributeKnots() const;
/// Flushes all the knots.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Flush() const;
/// Sets the alpha mode.
/// @param[in] alphaGradient			The gradient alpha type.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetIsAlphaGradient(Bool alphaGradient) const;
	};
	/// Intermediate helper class for GradientInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Gradient, false>::type&() const { return reinterpret_cast<const Gradient&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Gradient, false>::type&() { return reinterpret_cast<const Gradient&>(this->GetBaseRef()); }
/// Allocates an alpha gradient.
/// @return												The alpha gradient.
		inline Result<Gradient*> AllocAlphaGradient();
/// Returns the internal alpha gradient.
/// @return												The alpha gradient.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type GetAlphaGradient();
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
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type ConvertToAlphaGradient();
/// Sorts the knots according to their position.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SortKnots();
/// Inverts the knots.
/// @return												True if any knot inverted, otherwise false.
		inline Result<Bool> InvertKnots();
/// Doubles the knots.
/// @return												True if any knot doubled, otherwise false.
		inline Result<Bool> DoubleKnots();
/// Distributes the knots evenly.
/// @return												True if any knot distributed, otherwise false.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type DistributeKnots();
/// Flushes all the knots.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Flush();
/// Sets the alpha mode.
/// @param[in] alphaGradient			The gradient alpha type.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetIsAlphaGradient(Bool alphaGradient);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class GradientInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Gradient>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const GradientInterface, maxon::StrongCOWRefHandler, Gradient>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const GradientInterface, maxon::StrongCOWRefHandler, Gradient>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Gradient> Create();
};

class GradientInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GradientInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GradientInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Calculates a gradient pixel.
/// @param[in] pos								The X position.
/// @return												The calculated gradient pixel.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type CalcGradientPixel(Float pos) const;
/// Gets the number of knots for GetRenderKnot().
/// @return												The render knot count.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetKnotCount() const;
/// Gets a pointer to the knot at @formatParam{index}.
/// @param[in] index							The knot index. @em 0 <= @formatParam{index} < GetKnotCount()
/// @return												The render knot at @formatParam{index}. @theOwnsPointed{gradient data,knot}
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type GetKnot(Int index) const;
/// Gets a read only reference to internal knot list for fast access.
/// @return												The knot list.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type GetKnots() const;
/// Compares this with another GradientRenderData value.
/// @param[in] arg2								The other GradientRenderData value to compare with.
/// @return												The comparison result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const GradientRenderDataInterface* arg2) const;
	};
	/// Intermediate helper class for GradientRenderDataInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for GradientRenderDataInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, GradientRenderData, false>::type&() const { return reinterpret_cast<const GradientRenderData&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, GradientRenderData, false>::type&() { return reinterpret_cast<const GradientRenderData&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class GradientRenderDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<GradientRenderData>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const GradientRenderDataInterface, maxon::StrongCOWRefHandler, GradientRenderData>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const GradientRenderDataInterface, maxon::StrongCOWRefHandler, GradientRenderData>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<GradientRenderData> Create();
};

class GradientRenderDataInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GradientRenderDataInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GradientRenderDataInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
