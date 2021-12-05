#if 1
class ColorSpace;

struct ColorSpaceInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ColorSpaceInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ColorSpaceInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ColorSpaceInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ColorSpace;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ColorSpaceInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ColorSpace, false>::type&() const { return reinterpret_cast<const ColorSpace&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ColorSpace, false>::type&() { return reinterpret_cast<const ColorSpace&>(this->GetBaseRef()); }
/// Returns the default non-linear color profile (gamma != 1.0) for this color space for 8/16 bit integer formats.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type GetDefaultNonlinearColorProfile() const;
/// Returns the default color profile for this color space for floating point data.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type GetDefaultLinearColorProfile() const;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	false, void,
	ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>
	> { };
};
class ColorSpaceInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ColorSpace>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ColorSpaceInterface, maxon::StrongRefHandler, ColorSpace>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ColorSpaceInterface, maxon::StrongRefHandler, ColorSpace>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ColorSpaceInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ColorSpaceInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ColorSpaceInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ColorSpace is the reference class of ColorSpaceInterface.
///
/// Interface class for color spaces.
/// At the moment this class has no elements and is more or less only used as enum.
/// See ColorSpaces registry to iterate through all available color spaces or
/// call a registered color space directly:
/// @code
/// ColorSpace rgbSpace = ColorSpaces::RGBspace;
/// @endcode
class ColorSpace : public ColorSpaceInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ColorSpace, typename ColorSpaceInterface::Hxx1::Reference);
};

#endif
