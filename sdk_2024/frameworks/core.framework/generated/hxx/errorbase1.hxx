#if 1
class OutOfMemoryError;

struct OutOfMemoryErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, OutOfMemoryErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(OutOfMemoryErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct OutOfMemoryErrorObject_PrivateHelper;
struct OutOfMemoryErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = OutOfMemoryErrorObject_PrivateHelper;
	using ReferenceClass = OutOfMemoryError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for OutOfMemoryErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = OutOfMemoryErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(OutOfMemoryErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() const { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OutOfMemoryError, false>::type&() { return reinterpret_cast<const OutOfMemoryError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class OutOfMemoryErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<OutOfMemoryError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const OutOfMemoryErrorInterface, maxon::StrongCOWRefHandler, OutOfMemoryError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class OutOfMemoryErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<OutOfMemoryErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// OutOfMemoryError is the reference class of OutOfMemoryErrorInterface.
///
/// An OutOfMemoryError indicates that a memory allocation failed.
class OutOfMemoryError : public OutOfMemoryErrorInterface::Hxx1::Reference
{
public:
	friend class OutOfMemoryErrorObject;
	friend class maxon::ResultBase<OutOfMemoryError>;
	OutOfMemoryError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(OutOfMemoryError, typename OutOfMemoryErrorInterface::Hxx1::Reference);
	template <typename D> OutOfMemoryError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<OutOfMemoryError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> OutOfMemoryError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<OutOfMemoryError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	OutOfMemoryError() = default;
};

MAXON_DECLARATION(OutOfMemoryError, OutOfMemoryErrorObject, "net.maxon.error.outofmemory");
class FunctionNotImplementedError;

struct FunctionNotImplementedErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionNotImplementedErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(FunctionNotImplementedErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct FunctionNotImplementedErrorObject_PrivateHelper;
struct FunctionNotImplementedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = FunctionNotImplementedErrorObject_PrivateHelper;
	using ReferenceClass = FunctionNotImplementedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for FunctionNotImplementedErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = FunctionNotImplementedErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(FunctionNotImplementedErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() const { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, FunctionNotImplementedError, false>::type&() { return reinterpret_cast<const FunctionNotImplementedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class FunctionNotImplementedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<FunctionNotImplementedError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const FunctionNotImplementedErrorInterface, maxon::StrongCOWRefHandler, FunctionNotImplementedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FunctionNotImplementedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FunctionNotImplementedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FunctionNotImplementedError is the reference class of FunctionNotImplementedErrorInterface.
///
/// A FunctionNotImplementedError indicates that a function has been invoked
/// which did not contain a suitable implementation.
/// This error type creates the full call stack so that you can see where the call came from.
class FunctionNotImplementedError : public FunctionNotImplementedErrorInterface::Hxx1::Reference
{
public:
	friend class FunctionNotImplementedErrorObject;
	friend class maxon::ResultBase<FunctionNotImplementedError>;
	FunctionNotImplementedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FunctionNotImplementedError, typename FunctionNotImplementedErrorInterface::Hxx1::Reference);
	template <typename D> FunctionNotImplementedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<FunctionNotImplementedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> FunctionNotImplementedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<FunctionNotImplementedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	FunctionNotImplementedError() = default;
};

MAXON_DECLARATION(FunctionNotImplementedError, FunctionNotImplementedErrorObject, "net.maxon.error.functionnotimplemented");
class IllegalArgumentError;

struct IllegalArgumentErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalArgumentErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IllegalArgumentErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IllegalArgumentErrorObject_PrivateHelper;
struct IllegalArgumentErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = IllegalArgumentErrorObject_PrivateHelper;
	using ReferenceClass = IllegalArgumentError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for IllegalArgumentErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IllegalArgumentErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IllegalArgumentErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() const { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalArgumentError, false>::type&() { return reinterpret_cast<const IllegalArgumentError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class IllegalArgumentErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<IllegalArgumentError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IllegalArgumentErrorInterface, maxon::StrongCOWRefHandler, IllegalArgumentError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IllegalArgumentErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IllegalArgumentErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IllegalArgumentError is the reference class of IllegalArgumentErrorInterface.
///
/// An IllegalArgumentError is returned if an illegal argument was passed to a function parameter.
class IllegalArgumentError : public IllegalArgumentErrorInterface::Hxx1::Reference
{
public:
	friend class IllegalArgumentErrorObject;
	friend class maxon::ResultBase<IllegalArgumentError>;
	IllegalArgumentError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalArgumentError, typename IllegalArgumentErrorInterface::Hxx1::Reference);
	template <typename D> IllegalArgumentError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalArgumentError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalArgumentError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalArgumentError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalArgumentError() = default;
};

MAXON_DECLARATION(IllegalArgumentError, IllegalArgumentErrorObject, "net.maxon.error.illegalargument");
class NullptrError;

struct NullptrErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NullptrErrorInterface>::value || IllegalArgumentErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(NullptrErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct NullptrErrorObject_PrivateHelper;
struct NullptrErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = NullptrErrorObject_PrivateHelper;
	using ReferenceClass = NullptrError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<IllegalArgumentErrorInterface>;
	/// Intermediate helper class for NullptrErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NullptrErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(NullptrErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() const { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, NullptrError, false>::type&() { return reinterpret_cast<const NullptrError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename IllegalArgumentErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename IllegalArgumentErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class NullptrErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<NullptrError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const NullptrErrorInterface, maxon::StrongCOWRefHandler, NullptrError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class NullptrErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NullptrErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NullptrErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// NullptrError is the reference class of NullptrErrorInterface.
///
/// A NullptrError is returned if an (illegal) nullptr was passed to a function.
class NullptrError : public NullptrErrorInterface::Hxx1::Reference
{
public:
	friend class NullptrErrorObject;
	friend class maxon::ResultBase<NullptrError>;
	NullptrError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NullptrError, typename NullptrErrorInterface::Hxx1::Reference);
	template <typename D> NullptrError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<NullptrError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> NullptrError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<NullptrError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	NullptrError() = default;
};

MAXON_DECLARATION(NullptrError, NullptrErrorObject, "net.maxon.error.nullptr");
class IllegalStateError;

struct IllegalStateErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IllegalStateErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IllegalStateErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IllegalStateErrorObject_PrivateHelper;
struct IllegalStateErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = IllegalStateErrorObject_PrivateHelper;
	using ReferenceClass = IllegalStateError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for IllegalStateErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IllegalStateErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IllegalStateErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() const { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, IllegalStateError, false>::type&() { return reinterpret_cast<const IllegalStateError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class IllegalStateErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<IllegalStateError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IllegalStateErrorInterface, maxon::StrongCOWRefHandler, IllegalStateError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IllegalStateErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IllegalStateErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IllegalStateError is the reference class of IllegalStateErrorInterface.
///
/// An IllegalStateError indicates that a function has been invoked on an object and the object
/// hasn't been in a state which allows the proper execution of the function.
class IllegalStateError : public IllegalStateErrorInterface::Hxx1::Reference
{
public:
	friend class IllegalStateErrorObject;
	friend class maxon::ResultBase<IllegalStateError>;
	IllegalStateError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IllegalStateError, typename IllegalStateErrorInterface::Hxx1::Reference);
	template <typename D> IllegalStateError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<IllegalStateError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> IllegalStateError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<IllegalStateError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	IllegalStateError() = default;
};

MAXON_DECLARATION(IllegalStateError, IllegalStateErrorObject, "net.maxon.error.illegalstate");
class UnexpectedError;

struct UnexpectedErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnexpectedErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnexpectedErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnexpectedErrorObject_PrivateHelper;
struct UnexpectedErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnexpectedErrorObject_PrivateHelper;
	using ReferenceClass = UnexpectedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnexpectedErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = UnexpectedErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(UnexpectedErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() const { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnexpectedError, false>::type&() { return reinterpret_cast<const UnexpectedError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class UnexpectedErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<UnexpectedError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnexpectedErrorInterface, maxon::StrongCOWRefHandler, UnexpectedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnexpectedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnexpectedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnexpectedError is the reference class of UnexpectedErrorInterface.
///
/// An UnexpectedError is returned when something unexpected happens within a function.
/// This typically indicates a bug in the function (or in one of the other functions which
/// are invoked by the function).
class UnexpectedError : public UnexpectedErrorInterface::Hxx1::Reference
{
public:
	friend class UnexpectedErrorObject;
	friend class maxon::ResultBase<UnexpectedError>;
	UnexpectedError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnexpectedError, typename UnexpectedErrorInterface::Hxx1::Reference);
	template <typename D> UnexpectedError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnexpectedError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnexpectedError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnexpectedError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnexpectedError() = default;
};

MAXON_DECLARATION(UnexpectedError, UnexpectedErrorObject, "net.maxon.error.unexpected");
class OperationCancelledError;

struct OperationCancelledErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, OperationCancelledErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(OperationCancelledErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct OperationCancelledErrorObject_PrivateHelper;
struct OperationCancelledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = OperationCancelledErrorObject_PrivateHelper;
	using ReferenceClass = OperationCancelledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for OperationCancelledErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = OperationCancelledErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(OperationCancelledErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OperationCancelledError, false>::type&() const { return reinterpret_cast<const OperationCancelledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, OperationCancelledError, false>::type&() { return reinterpret_cast<const OperationCancelledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class OperationCancelledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<OperationCancelledError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const OperationCancelledErrorInterface, maxon::StrongCOWRefHandler, OperationCancelledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const OperationCancelledErrorInterface, maxon::StrongCOWRefHandler, OperationCancelledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class OperationCancelledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<OperationCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<OperationCancelledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// OperationCancelledError is the reference class of OperationCancelledErrorInterface.
///
/// A OperationCancelledError is returned if a function terminated because a job or thread has been cancelled (from outside).
class OperationCancelledError : public OperationCancelledErrorInterface::Hxx1::Reference
{
public:
	friend class OperationCancelledErrorObject;
	friend class maxon::ResultBase<OperationCancelledError>;
	OperationCancelledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(OperationCancelledError, typename OperationCancelledErrorInterface::Hxx1::Reference);
	template <typename D> OperationCancelledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<OperationCancelledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> OperationCancelledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<OperationCancelledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	OperationCancelledError() = default;
};

MAXON_DECLARATION(OperationCancelledError, OperationCancelledErrorObject, "net.maxon.error.OperationCancelledError");
class AggregatedError;

struct AggregatedErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, AggregatedErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(AggregatedErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct AggregatedErrorObject_PrivateHelper;
struct AggregatedErrorInterface::Hxx1
{
	class NonConstRef;
	using ErrObj = AggregatedErrorObject_PrivateHelper;
	using ReferenceClass = AggregatedError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = AggregatedErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(AggregatedErrorInterface**);
/// Returns the number of errors in this AggregatedError.
		inline HXXADDRET2(Int) GetCount() const;
/// Returns the error at the given index.
/// @param[in] index							Index of the error. Index must be >= 0 and < GetCount().
/// @return												Error stored at this index.
		inline HXXADDRET2(const Error&) GetError(Int index) const;
	};
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = AggregatedErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(AggregatedErrorInterface**);
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline HXXADDRET2(Bool) AddError(const Error& error) const;
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline HXXADDRET2(Bool) AddError(Error&& error) const;
	};
	/// Intermediate helper class for AggregatedErrorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = AggregatedErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(AggregatedErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, AggregatedError, false>::type&() const { return reinterpret_cast<const AggregatedError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, AggregatedError, false>::type&() { return reinterpret_cast<const AggregatedError&>(this->GetBaseRef()); }
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline HXXADDRET1(Bool) AddError(const Error& error);
/// Adds an error to this AggregatedError.
/// @param[in] error							AggregatedError to add.
		inline HXXADDRET1(Bool) AddError(Error&& error);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class AggregatedErrorInterface::Reference :
#ifdef DOXYGEN
public COWFnDoxy<AggregatedError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const AggregatedErrorInterface, maxon::StrongCOWRefHandler, AggregatedError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class AggregatedErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<AggregatedErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#endif
