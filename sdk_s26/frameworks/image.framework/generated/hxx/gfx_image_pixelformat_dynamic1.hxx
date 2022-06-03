#if 1
class PixelFormatDynamic;

struct PixelFormatDynamicInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatDynamicInterface>::value || PixelFormatInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PixelFormatDynamicInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct PixelFormatDynamicInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatDynamic;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<PixelFormatInterface>;
	/// Intermediate helper class for PixelFormatDynamicInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(PixelFormatDynamicInterface**);
/// AddChannel description.
/// @param[in] channel						Channel to add (ImageCRed, Green ...)
/// @return												Returns the channel number.
		inline Result<Int> AddChannel(const ImageChannel& channel) const;
	};
	/// Intermediate helper class for PixelFormatDynamicInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(PixelFormatDynamicInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatDynamic, false>::type&() const { return reinterpret_cast<const PixelFormatDynamic&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatDynamic, false>::type&() { return reinterpret_cast<const PixelFormatDynamic&>(this->GetBaseRef()); }
/// AddChannel description.
/// @param[in] channel						Channel to add (ImageCRed, Green ...)
/// @return												Returns the channel number.
		inline Result<Int> AddChannel(const ImageChannel& channel);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type, Fn<typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class PixelFormatDynamicInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<PixelFormatDynamic>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatDynamicInterface, maxon::StrongCOWRefHandler, PixelFormatDynamic>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatDynamicInterface, maxon::StrongCOWRefHandler, PixelFormatDynamic>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatDynamicInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatDynamicInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatDynamicInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatDynamic is the reference class of PixelFormatDynamicInterface.
class PixelFormatDynamic : public PixelFormatDynamicInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatDynamic, typename PixelFormatDynamicInterface::Hxx1::Reference);
};

#endif
