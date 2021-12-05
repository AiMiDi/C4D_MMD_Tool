#if 1
class UnregisteredDataTypeError;

struct UnregisteredDataTypeErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnregisteredDataTypeErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(UnregisteredDataTypeErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UnregisteredDataTypeErrorObjectPrivateHelper;
struct UnregisteredDataTypeErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnregisteredDataTypeErrorObjectPrivateHelper;
	using ReferenceClass = UnregisteredDataTypeError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() const { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UnregisteredDataTypeErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnregisteredDataTypeError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnregisteredDataTypeErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnregisteredDataTypeError is the reference class of UnregisteredDataTypeErrorInterface.
///
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
class UnregisteredDataTypeError : public UnregisteredDataTypeErrorInterface::Hxx1::Reference
{
public:
	friend class UnregisteredDataTypeErrorObject;
	friend class maxon::ResultBase<UnregisteredDataTypeError>;
	UnregisteredDataTypeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnregisteredDataTypeError, typename UnregisteredDataTypeErrorInterface::Hxx1::Reference);
	template <typename D> UnregisteredDataTypeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnregisteredDataTypeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnregisteredDataTypeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnregisteredDataTypeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnregisteredDataTypeError() = default;
};

MAXON_DECLARATION(UnregisteredDataTypeError, UnregisteredDataTypeErrorObject, "net.maxon.error.unregistereddatatype");
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#endif
