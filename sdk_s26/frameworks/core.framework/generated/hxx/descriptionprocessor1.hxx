#if 1
class DescriptionProcessor;

struct DescriptionProcessorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DescriptionProcessorInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DescriptionProcessorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DescriptionProcessorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DescriptionProcessor;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DescriptionProcessorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DescriptionProcessorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionProcessor, false>::type&() const { return reinterpret_cast<const DescriptionProcessor&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionProcessor, false>::type&() { return reinterpret_cast<const DescriptionProcessor&>(this->GetBaseRef()); }
/// Processes a description for which this processor is set.
/// @param[in] descriptionId			The description identifier.
/// @param[in] dataDescription		The description.
/// @return												Some object whose destructor will be called when the description database is unregistered.
		inline Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class DescriptionProcessorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<DescriptionProcessor>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DescriptionProcessorInterface, maxon::StrongRefHandler, DescriptionProcessor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DescriptionProcessorInterface, maxon::StrongRefHandler, DescriptionProcessor>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DescriptionProcessorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DescriptionProcessorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DescriptionProcessorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DescriptionProcessor is the reference class of DescriptionProcessorInterface.
///
/// A DescriptionProcessor processes a resource description, usually in order to derive
/// some object from that description and register it at a registry. The processor to use
/// for a description is directly set in the description (DESCRIPTION::DATA::INFO::PROCESSOR).
class DescriptionProcessor : public DescriptionProcessorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DescriptionProcessor, typename DescriptionProcessorInterface::Hxx1::Reference);
};

#endif
