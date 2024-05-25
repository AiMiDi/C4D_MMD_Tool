#if 1
class VectorImageRef;

struct VectorImageInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, VectorImageInterface>::value || ImageBaseInterface::HasBaseDetector::template Check<I>::value; static I* Cast(VectorImageInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct VectorImageInterface::Hxx1
{
	class Reference;
	using ReferenceClass = VectorImageRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageBaseInterface>;
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = VectorImageInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(VectorImageInterface**);
/// GetUrl returns the url of the image.
		inline HXXADDRET2(const Url&) GetUrl() const;
/// GetSVGDocument returns the SVGDocument connected to this image.
		inline Result<ForwardRef<SVGDocument>> GetSVGDocument() const;
	};
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = VectorImageInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(VectorImageInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VectorImageRef, true>::type&() const { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VectorImageRef, false>::type&() { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
/// Initialized the Vector image with the given url of an svg image.
/// @param[in] url								Url of a svg file to load.
/// @return                       OK on success.
		inline Result<void> Init(const Url& url) const;
/// Initializes the image with a SVGDocument.
/// @param[in] svgDocument				The image.
/// @return                       OK on success.
		inline Result<void> Init(const SVGDocument& svgDocument) const;
	};
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = VectorImageInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(VectorImageInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, VectorImageRef, false>::type&() { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
/// Initialized the Vector image with the given url of an svg image.
/// @param[in] url								Url of a svg file to load.
/// @return                       OK on success.
		inline Result<void> Init(const Url& url);
/// Initializes the image with a SVGDocument.
/// @param[in] svgDocument				The image.
/// @return                       OK on success.
		inline Result<void> Init(const SVGDocument& svgDocument);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ImageBaseInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ImageBaseInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ImageBaseInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class VectorImageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<VectorImageRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<VectorImageInterface, maxon::StrongRefHandler, VectorImageRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<VectorImageInterface, maxon::StrongRefHandler, VectorImageRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// VectorImageRef is the reference class of VectorImageInterface.
///
/// The VectorImageInterface represents a vector image (internally SVG).
/// This class wraps the vector image into a ImageBaseRef. The draw functions then extract 
/// that and draw the image as vector image.
class VectorImageRef : public VectorImageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(VectorImageRef, typename VectorImageInterface::Hxx1::Reference);
	using ConstPtr = typename VectorImageInterface::ConstPtr;
};

#endif
