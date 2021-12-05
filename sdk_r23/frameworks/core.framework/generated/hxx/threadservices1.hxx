#if 1
class ThreadCancelledError;

struct ThreadCancelledErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ThreadCancelledErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(ThreadCancelledErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ThreadCancelledErrorObjectPrivateHelper;
struct ThreadCancelledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ThreadCancelledErrorObjectPrivateHelper;
	using ReferenceClass = ThreadCancelledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ThreadCancelledErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() const { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ThreadCancelledError, false>::type&() { return reinterpret_cast<const ThreadCancelledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ThreadCancelledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ThreadCancelledError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ThreadCancelledErrorInterface, maxon::StrongCOWRefHandler, ThreadCancelledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ThreadCancelledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ThreadCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ThreadCancelledError is the reference class of ThreadCancelledErrorInterface.
///
/// A ThreadCancelledError is returned if a function terminated because the thread has been stopped from outside.
class ThreadCancelledError : public ThreadCancelledErrorInterface::Hxx1::Reference
{
public:
	friend class ThreadCancelledErrorObject;
	friend class maxon::ResultBase<ThreadCancelledError>;
	ThreadCancelledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ThreadCancelledError, typename ThreadCancelledErrorInterface::Hxx1::Reference);
	template <typename D> ThreadCancelledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ThreadCancelledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ThreadCancelledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ThreadCancelledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ThreadCancelledError() = default;
};

MAXON_DECLARATION(ThreadCancelledError, ThreadCancelledErrorObject, "net.maxon.error.threadcancelled");
class JobError;

struct JobErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, JobErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(JobErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct JobErrorObjectPrivateHelper;
struct JobErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = JobErrorObjectPrivateHelper;
	using ReferenceClass = JobError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for JobErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for JobErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for JobErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() const { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, JobError, false>::type&() { return reinterpret_cast<const JobError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class JobErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<JobError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const JobErrorInterface, maxon::StrongCOWRefHandler, JobError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class JobErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JobErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JobErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
