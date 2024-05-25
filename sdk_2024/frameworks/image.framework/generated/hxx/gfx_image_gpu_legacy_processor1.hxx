#if 1
class ColorProfileLegacyProcessor;

struct ColorProfileLegacyProcessorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ColorProfileLegacyProcessor;
	/// Intermediate helper class for ColorProfileLegacyProcessorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ColorProfileLegacyProcessorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ColorProfileLegacyProcessorInterface**);
		static inline Result<ForwardRef<ColorProfileGpuHandlerRef>> CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
	};
	/// Intermediate helper class for ColorProfileLegacyProcessorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ColorProfileLegacyProcessorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ColorProfileLegacyProcessorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongACOWRefHandler, ColorProfileLegacyProcessor, false>::type&() const { return reinterpret_cast<const ColorProfileLegacyProcessor&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongACOWRefHandler, ColorProfileLegacyProcessor, false>::type&() { return reinterpret_cast<const ColorProfileLegacyProcessor&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	ConstFn<typename ST::type>
	> { };
};
class ColorProfileLegacyProcessorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<ColorProfileLegacyProcessor>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileLegacyProcessorInterface, maxon::StrongACOWRefHandler, ColorProfileLegacyProcessor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileLegacyProcessorInterface, maxon::StrongACOWRefHandler, ColorProfileLegacyProcessor>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<ColorProfileLegacyProcessor> Create();
};

class ColorProfileLegacyProcessorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public COWFnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileLegacyProcessorInterface, maxon::StrongACOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileLegacyProcessorInterface, maxon::StrongACOWRefHandler, NonConstRef>>>>);
};

/// ColorProfileLegacyProcessor is the reference class of ColorProfileLegacyProcessorInterface.
class ColorProfileLegacyProcessor : public ColorProfileLegacyProcessorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ColorProfileLegacyProcessor, typename ColorProfileLegacyProcessorInterface::Hxx1::Reference);
};

#endif
