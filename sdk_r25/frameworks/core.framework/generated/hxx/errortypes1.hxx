#if 1
class UnsupportedArgumentError;

struct UnsupportedArgumentErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedArgumentErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnsupportedArgumentErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnsupportedArgumentErrorObjectPrivateHelper;
struct UnsupportedArgumentErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnsupportedArgumentErrorObjectPrivateHelper;
	using ReferenceClass = UnsupportedArgumentError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnsupportedArgumentErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() const { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedArgumentError, false>::type&() { return reinterpret_cast<const UnsupportedArgumentError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class UnsupportedArgumentErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedArgumentError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedArgumentErrorInterface, maxon::StrongCOWRefHandler, UnsupportedArgumentError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnsupportedArgumentErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnsupportedArgumentError is the reference class of UnsupportedArgumentErrorInterface.
///
/// An UnsupportedArgumentError indicates that a generally valid argument was passed to a function parameter,
/// but the function implementation doesn't support that argument. An example is the
/// conversion of a value to a destination type where the particular combination of value
/// and destination type is not supported by the converter.
class UnsupportedArgumentError : public UnsupportedArgumentErrorInterface::Hxx1::Reference
{
public:
	friend class UnsupportedArgumentErrorObject;
	friend class maxon::ResultBase<UnsupportedArgumentError>;
	UnsupportedArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedArgumentError, typename UnsupportedArgumentErrorInterface::Hxx1::Reference);
	template <typename D> UnsupportedArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedArgumentError() = default;
};

MAXON_DECLARATION(UnsupportedArgumentError, UnsupportedArgumentErrorObject, "net.maxon.error.unsupportedargument");
class UnresolvedError;

struct UnresolvedErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnresolvedErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnresolvedErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnresolvedErrorObjectPrivateHelper;
struct UnresolvedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnresolvedErrorObjectPrivateHelper;
	using ReferenceClass = UnresolvedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnresolvedErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() const { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnresolvedError, false>::type&() { return reinterpret_cast<const UnresolvedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class UnresolvedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnresolvedError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnresolvedErrorInterface, maxon::StrongCOWRefHandler, UnresolvedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnresolvedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnresolvedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnresolvedError is the reference class of UnresolvedErrorInterface.
///
/// An UnresolvedError indicates that an interface or declaration was accessed for which
/// there is no definition.
class UnresolvedError : public UnresolvedErrorInterface::Hxx1::Reference
{
public:
	friend class UnresolvedErrorObject;
	friend class maxon::ResultBase<UnresolvedError>;
	UnresolvedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnresolvedError, typename UnresolvedErrorInterface::Hxx1::Reference);
	template <typename D> UnresolvedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnresolvedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnresolvedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnresolvedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnresolvedError() = default;
};

MAXON_DECLARATION(UnresolvedError, UnresolvedErrorObject, "net.maxon.error.unresolved");
class UnknownError;

struct UnknownErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnknownErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnknownErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnknownErrorObjectPrivateHelper;
struct UnknownErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnknownErrorObjectPrivateHelper;
	using ReferenceClass = UnknownError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnknownErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() const { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnknownError, false>::type&() { return reinterpret_cast<const UnknownError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class UnknownErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnknownError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnknownErrorInterface, maxon::StrongCOWRefHandler, UnknownError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnknownErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnknownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnknownError is the reference class of UnknownErrorInterface.
///
/// An UnknownError is returned in places where no specific error was defined.
class UnknownError : public UnknownErrorInterface::Hxx1::Reference
{
public:
	friend class UnknownErrorObject;
	friend class maxon::ResultBase<UnknownError>;
	UnknownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnknownError, typename UnknownErrorInterface::Hxx1::Reference);
	template <typename D> UnknownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnknownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnknownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnknownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnknownError() = default;
};

MAXON_DECLARATION(UnknownError, UnknownErrorObject, "net.maxon.error.unknown");
class UnsupportedOperationError;

struct UnsupportedOperationErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnsupportedOperationErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnsupportedOperationErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnsupportedOperationErrorObjectPrivateHelper;
struct UnsupportedOperationErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnsupportedOperationErrorObjectPrivateHelper;
	using ReferenceClass = UnsupportedOperationError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnsupportedOperationErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() const { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnsupportedOperationError, false>::type&() { return reinterpret_cast<const UnsupportedOperationError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class UnsupportedOperationErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<UnsupportedOperationError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnsupportedOperationErrorInterface, maxon::StrongCOWRefHandler, UnsupportedOperationError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnsupportedOperationErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnsupportedOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnsupportedOperationError is the reference class of UnsupportedOperationErrorInterface.
///
/// An UnsupportedOperationError indicates that the intended operation is
/// not supported by the implementation (for example, the attempt to modify a read-only dictionary).
class UnsupportedOperationError : public UnsupportedOperationErrorInterface::Hxx1::Reference
{
public:
	friend class UnsupportedOperationErrorObject;
	friend class maxon::ResultBase<UnsupportedOperationError>;
	UnsupportedOperationError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnsupportedOperationError, typename UnsupportedOperationErrorInterface::Hxx1::Reference);
	template <typename D> UnsupportedOperationError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnsupportedOperationError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnsupportedOperationError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnsupportedOperationError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnsupportedOperationError() = default;
};

MAXON_DECLARATION(UnsupportedOperationError, UnsupportedOperationErrorObject, "net.maxon.error.unsupportedoperation");
class ShutdownError;

struct ShutdownErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ShutdownErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ShutdownErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ShutdownErrorObjectPrivateHelper;
struct ShutdownErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ShutdownErrorObjectPrivateHelper;
	using ReferenceClass = ShutdownError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ShutdownErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() const { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ShutdownError, false>::type&() { return reinterpret_cast<const ShutdownError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class ShutdownErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ShutdownError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ShutdownErrorInterface, maxon::StrongCOWRefHandler, ShutdownError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ShutdownErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ShutdownErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ShutdownError is the reference class of ShutdownErrorInterface.
///
/// A ShutdownError is returned when errors are being used while the object system is being shut down.
class ShutdownError : public ShutdownErrorInterface::Hxx1::Reference
{
public:
	friend class ShutdownErrorObject;
	friend class maxon::ResultBase<ShutdownError>;
	ShutdownError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ShutdownError, typename ShutdownErrorInterface::Hxx1::Reference);
	template <typename D> ShutdownError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ShutdownError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ShutdownError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ShutdownError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ShutdownError() = default;
};

MAXON_DECLARATION(ShutdownError, ShutdownErrorObject, "net.maxon.error.shutdown");
class DisabledError;

struct DisabledErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DisabledErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DisabledErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DisabledErrorObjectPrivateHelper;
struct DisabledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = DisabledErrorObjectPrivateHelper;
	using ReferenceClass = DisabledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for DisabledErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DisabledError, false>::type&() const { return reinterpret_cast<const DisabledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DisabledError, false>::type&() { return reinterpret_cast<const DisabledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class DisabledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<DisabledError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DisabledErrorInterface, maxon::StrongCOWRefHandler, DisabledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DisabledErrorInterface, maxon::StrongCOWRefHandler, DisabledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DisabledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DisabledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DisabledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DisabledError is the reference class of DisabledErrorInterface.
///
/// A DisabledError is returned by a registration function to tell that the registration is disabled.
/// The system won't show a warning message for such an error.
class DisabledError : public DisabledErrorInterface::Hxx1::Reference
{
public:
	friend class DisabledErrorObject;
	friend class maxon::ResultBase<DisabledError>;
	DisabledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DisabledError, typename DisabledErrorInterface::Hxx1::Reference);
	template <typename D> DisabledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<DisabledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> DisabledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<DisabledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	DisabledError() = default;
};

MAXON_DECLARATION(DisabledError, DisabledErrorObject, "net.maxon.error.disabled");
class ErrnoError;

struct ErrnoErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ErrnoErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ErrnoErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ErrnoErrorObjectPrivateHelper;
struct ErrnoErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = ErrnoErrorObjectPrivateHelper;
	using ReferenceClass = ErrnoError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the errno error code stored in this error.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetErrorCode() const;
	};
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Sets the errno error code. This error must be returned from the errno system variable.
/// The error can output the human readable string of the errno error.
/// @param[in] errorCode					Error code of errno system variable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetErrorCode(Int errorCode) const;
	};
	/// Intermediate helper class for ErrnoErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ErrnoError, false>::type&() const { return reinterpret_cast<const ErrnoError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ErrnoError, false>::type&() { return reinterpret_cast<const ErrnoError&>(this->GetBaseRef()); }

protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, Int errorCode)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetErrorCode(errorCode);
	}
	
		public:
/// Sets the errno error code. This error must be returned from the errno system variable.
/// The error can output the human readable string of the errno error.
/// @param[in] errorCode					Error code of errno system variable.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetErrorCode(Int errorCode);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class ErrnoErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<ErrnoError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ErrnoErrorInterface, maxon::StrongCOWRefHandler, ErrnoError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ErrnoErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ErrnoErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ErrnoError is the reference class of ErrnoErrorInterface.
///
/// Error that contains a errno error state.
/// This error is returned if the error code contains the value of the 'errno' variable at the point when the error occurred.
/// The GetMessage functions retrieves the error text from the system using strerror().
class ErrnoError : public ErrnoErrorInterface::Hxx1::Reference
{
public:
	friend class ErrnoErrorObject;
	friend class maxon::ResultBase<ErrnoError>;
	ErrnoError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ErrnoError, typename ErrnoErrorInterface::Hxx1::Reference);
	template <typename D> ErrnoError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<ErrnoError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> ErrnoError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<ErrnoError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	ErrnoError() = default;
};

MAXON_DECLARATION(ErrnoError, ErrnoErrorObject, "net.maxon.error.errno");
#endif
