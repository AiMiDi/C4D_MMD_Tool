#if 1
class PixelFormatDynamic;

struct PixelFormatDynamicInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatDynamicInterface>::value || PixelFormatInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatDynamicInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct PixelFormatDynamicInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatDynamic;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<PixelFormatInterface>;
	/// Intermediate helper class for PixelFormatDynamicInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for PixelFormatDynamicInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// AddChannel description.
/// @param[in] channel						Channel to add (ImageCRed, Green ...)
/// @return												Returns the channel number.
		inline Result<Int> AddChannel(const ImageChannel& channel) const;
	};
	/// Intermediate helper class for PixelFormatDynamicInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatDynamic, false>::type&() const { return reinterpret_cast<const PixelFormatDynamic&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatDynamic, false>::type&() { return reinterpret_cast<const PixelFormatDynamic&>(this->GetBaseRef()); }
/// AddChannel description.
/// @param[in] channel						Channel to add (ImageCRed, Green ...)
/// @return												Returns the channel number.
		inline Result<Int> AddChannel(const ImageChannel& channel);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatDynamicInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<PixelFormatDynamic>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatDynamicInterface, maxon::StrongCOWRefHandler, PixelFormatDynamic>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatDynamicInterface, maxon::StrongCOWRefHandler, PixelFormatDynamic>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatDynamicInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatDynamicInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatDynamicInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatDynamic is the reference class of PixelFormatDynamicInterface.
class PixelFormatDynamic : public PixelFormatDynamicInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatDynamic, typename PixelFormatDynamicInterface::Hxx1::Reference);
};

#endif
