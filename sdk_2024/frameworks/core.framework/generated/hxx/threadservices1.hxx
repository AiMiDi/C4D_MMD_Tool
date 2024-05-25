#if 1
class JobError;

struct JobErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, JobErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(JobErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct JobErrorObject_PrivateHelper;
struct JobErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = JobErrorObject_PrivateHelper;
	using ReferenceClass = JobError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for JobErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = JobErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(JobErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() const { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class JobErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<JobError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class JobErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<JobErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<JobErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// JobError is the reference class of JobErrorInterface.
///
/// Error of the category jobs, groups and threads.
class JobError : public JobErrorInterface::Hxx1::Reference
{
public:
	friend class JobErrorObject;
	friend class maxon::ResultBase<JobError>;
	JobError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JobError, typename JobErrorInterface::Hxx1::Reference);
	template <typename D> JobError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<JobError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> JobError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<JobError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	JobError() = default;
};

MAXON_DECLARATION(JobError, JobErrorObject, "net.maxon.error.job");
/// @cond INTERNAL

/// @endcond

#endif
