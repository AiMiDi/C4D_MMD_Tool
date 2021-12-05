#if 1
class GenericFactory;

struct FactoryInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FactoryInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(FactoryInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct FactoryInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = GenericFactory;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for FactoryInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFactory, false>::type&() const { return reinterpret_cast<const GenericFactory&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFactory, false>::type&() { return reinterpret_cast<const GenericFactory&>(this->GetBaseRef()); }
/// Returns the delegate which implements the factory function.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DelegateBase*>, const DelegateBase*>::type PrivateGetDelegate() const;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	false, void,
	ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>
	> { };
};
class FactoryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<GenericFactory>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FactoryInterface, maxon::StrongRefHandler, GenericFactory>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FactoryInterface, maxon::StrongRefHandler, GenericFactory>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FactoryInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FactoryInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FactoryInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GenericFactory is the reference class of FactoryInterface.
///
/// Interface for factories. Factories create new objects based on parameters.
/// @see Factory
class GenericFactory : public FactoryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericFactory, typename FactoryInterface::Hxx1::Reference);
};

#endif
