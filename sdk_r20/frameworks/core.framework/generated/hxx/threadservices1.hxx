#if 1
struct JobErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, JobErrorInterface>::value || ErrorInterface::HasBase::Check<I>::value; static I* Cast(JobErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class JobError;

struct JobErrorObjectPrivateHelper;
struct JobErrorInterface::ReferenceClassHelper { using type = JobError; using object = JobErrorObjectPrivateHelper; };

/// Intermediate helper class for JobErrorInterface.
template <typename S> class JobErrorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class JobErrorInterface::ConstReferenceFunctionsImplDoxy : public JobErrorInterface::ConstReferenceFunctionsImpl<REF>, public ErrorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for JobErrorInterface.
template <typename S> class JobErrorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class JobErrorInterface::ReferenceFunctionsImplDoxy : public JobErrorInterface::ReferenceFunctionsImpl<REF>, public ErrorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for JobErrorInterface.
template <typename S> class JobErrorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() const { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class JobErrorInterface::COWReferenceFunctionsImplDoxy : public JobErrorInterface::COWReferenceFunctionsImpl<REF>, public ErrorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct JobErrorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class JobErrorInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<JobError>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>);
	using NonConst = NonConstRef;
};

class JobErrorInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<JobErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<JobErrorInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

/// JobError is the reference class of JobErrorInterface.
///
/// Error of the category jobs, groups and threads.
class JobError : public JobErrorInterface::Reference
{
public:
	friend class JobErrorObject;
	friend class maxon::ResultBase<JobError>;
	JobError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JobError, Reference);
	template <typename D> JobError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<JobError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> JobError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<JobError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	JobError() = default;
};

MAXON_DECLARATION(JobError, JobErrorObject, "net.maxon.error.job");
/// @cond INTERNAL

/// @endcond

#endif
