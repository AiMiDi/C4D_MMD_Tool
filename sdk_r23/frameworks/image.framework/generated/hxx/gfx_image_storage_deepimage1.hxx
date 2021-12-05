#if 1
class ImagePixelDeepImageStorage;

struct ImagePixelDeepImageStorageInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImagePixelDeepImageStorageInterface>::value || ImagePixelStorageInterface::HasBase::template Check<I>::value; static I* Cast(ImagePixelDeepImageStorageInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImagePixelDeepImageStorageInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ImagePixelDeepImageStorage;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImagePixelStorageInterface>;
	/// Intermediate helper class for ImagePixelDeepImageStorageInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImagePixelDeepImageStorageInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImagePixelDeepImageStorageInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ImagePixelDeepImageStorage, false>::type&() const { return reinterpret_cast<const ImagePixelDeepImageStorage&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ImagePixelDeepImageStorage, false>::type&() { return reinterpret_cast<const ImagePixelDeepImageStorage&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ImagePixelStorageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ImagePixelStorageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ImagePixelStorageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImagePixelDeepImageStorageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ImagePixelDeepImageStorage>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImagePixelDeepImageStorageInterface, maxon::StrongCOWRefHandler, ImagePixelDeepImageStorage>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImagePixelDeepImageStorageInterface, maxon::StrongCOWRefHandler, ImagePixelDeepImageStorage>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ImagePixelDeepImageStorageInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImagePixelDeepImageStorageInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImagePixelDeepImageStorageInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ImagePixelDeepImageStorage is the reference class of ImagePixelDeepImageStorageInterface.
///
/// Object that can store pixel data in a special layout (e.g. compact, plain, or tiles).
class ImagePixelDeepImageStorage : public ImagePixelDeepImageStorageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImagePixelDeepImageStorage, typename ImagePixelDeepImageStorageInterface::Hxx1::Reference);
};

#endif
