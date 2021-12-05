#if 1
class DescriptionProcessor;

struct DescriptionProcessorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DescriptionProcessorInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DescriptionProcessorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DescriptionProcessorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DescriptionProcessor;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DescriptionProcessorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionProcessor, false>::type&() const { return reinterpret_cast<const DescriptionProcessor&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionProcessor, false>::type&() { return reinterpret_cast<const DescriptionProcessor&>(this->GetBaseRef()); }
/// Processes a description for which this processor is set.
/// @param[in] descriptionId			The description identifier.
/// @param[in] dataDescription		The description.
/// @return												Some object whose destructor will be called when the description database is unregistered.
		inline Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const;
	};
	/// Intermediate helper class for DescriptionProcessorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DescriptionProcessorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DescriptionProcessorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<DescriptionProcessor>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DescriptionProcessorInterface, maxon::StrongRefHandler, DescriptionProcessor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DescriptionProcessorInterface, maxon::StrongRefHandler, DescriptionProcessor>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DescriptionProcessorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DescriptionProcessorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DescriptionProcessorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
